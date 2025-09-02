# ---------------------------------------------------------------------------
# Script Description:
# ---------------------------------------------------------------------------
# This script provides a PyQt5-based GUI tool for MicroStation (using the MicroStation Python API)
# that allows users to select one or more BSpline surface elements in the active DGN model and 
# place a grid of points, shapes (quads), and optionally extruded solids on those surfaces.
# The user can specify the number of U/V divisions, whether to place points, shapes, or solids,
# the extrusion thickness, and whether to delete the original surface after processing.
# The script handles selection, geometry creation, and error reporting, and is designed to be
# robust and user-friendly for interactive use within MicroStation.
# ---------------------------------------------------------------------------

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QSpinBox, QCheckBox, QPushButton, QGridLayout, QMessageBox, QDoubleSpinBox, QHBoxLayout
)
from PyQt5.QtCore import Qt, QTimer
import sys
import traceback

# Try to import sip for widget validity checks (optional)
try:
    import sip
    HAVE_SIP = True
except ImportError:
    HAVE_SIP = False

# Utility function to show error messages in both MicroStation and Qt
def show_error_dialog(msg, detail=""):
    MessageCenter.ShowErrorMessage(msg, detail, False)
    try:
        QMessageBox.critical(None, "Error", f"{msg}\n\n{detail}")
    except Exception:
        pass

# Get the element IDs of all selected BSpline surface elements in the active model
def get_selected_surface_ids():
    try:
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        sel_mgr = SelectionSetManager.GetManager()
        agenda = ElementAgenda()
        sel_mgr.BuildAgenda(agenda)
        ids = []
        for idx in range(agenda.GetCount()):
            eeh = agenda.GetEntry(idx)
            if eeh.GetElementType() == MSElementTypes.eBSPLINE_SURFACE_ELM:
                ids.append(eeh.ElementId)
        return ids
    except Exception as ex:
        show_error_dialog("Failed to get selected surfaces.", str(ex))
        return []

# Fit a best-fit plane to a set of 3D points using least squares (for extrusion direction)
def best_fit_plane(points):
    """
    Fit a plane to a set of 3D points using least squares.
    Returns (origin, normal) as DPoint3d and DVec3d.
    """
    import numpy as np
    pts = np.array([[p.x, p.y, p.z] for p in points if p is not None])
    if pts.shape[0] < 3:
        return None, None
    centroid = pts.mean(axis=0)
    uu, dd, vv = np.linalg.svd(pts - centroid)
    normal = vv[2, :]
    return DPoint3d(*centroid), DVec3d(*normal)

# Ensure the normal vector points in the same general direction as a reference normal
def ensure_consistent_normal(normal, reference_normal):
    """
    Ensures the normal points in the same general direction as the reference_normal.
    If not, flips the normal.
    """
    dot = normal.DotProduct(reference_normal)
    if dot < 0:
        normal.Negate()
    return normal

# Main function to place points, shapes, and/or solids on selected BSpline surfaces
def place_points_and_quads_on_selected_surface(
    num_u=10, num_v=10, place_points=True, place_shape=True, make_solid=False, thickness=1.0, surface_ids=None, delete_surface=False
):
    try:
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        if dgnModel is None:
            show_error_dialog("No active DGN model.")
            return

        # Get UOR (Units of Resolution) per master unit for scaling
        modelInfo = dgnModel.GetModelInfo()
        __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)
        thickness_uor = thickness * uorPerMast

        # Use provided surface IDs or get from selection
        ids = surface_ids if surface_ids else []
        if not ids:
            show_error_dialog("No BSpline surface element selected.")
            return

        total_points = 0
        total_quads = 0
        total_solids = 0
        for elem_id in ids:
            try:
                eeh = EditElementHandle(elem_id, dgnModel)
                if eeh.GetElementType() != MSElementTypes.eBSPLINE_SURFACE_ELM:
                    continue
                surf_query = eeh.GetIBsplineSurfaceQuery()
                if surf_query is None:
                    continue
                ret = surf_query.GetBsplineSurface(eeh)
                if ret[0] != BentleyStatus.eSUCCESS:
                    continue
                surface = ret[1]

                # Compute a reference normal at the center of the surface for consistent extrusion direction
                ref_u = 0.5
                ref_v = 0.5
                ref_normal = DVec3d()
                try:
                    # Evaluate normal at center
                    surface.EvaluateNormal(ref_normal, ref_u, ref_v)
                    if ref_normal.Magnitude() == 0:
                        ref_normal = DVec3d(0, 0, 1)
                    else:
                        ref_normal.Normalize()
                except Exception:
                    ref_normal = DVec3d(0, 0, 1)

                # Prepare grid for storing evaluated points
                grid_points = [[None for _ in range(num_v)] for _ in range(num_u)]
                num_points_placed = 0
                for i in range(num_u):
                    u = i / (num_u - 1) if num_u > 1 else 0.0
                    for j in range(num_v):
                        v = j / (num_v - 1) if num_v > 1 else 0.0
                        pt = DPoint3d()
                        try:
                            eval_success = surface.EvaluatePoint(pt, u, v)
                        except Exception as ex:
                            eval_success = -1
                        # If evaluation is successful, store and optionally place a point element
                        if eval_success is None:
                            pt_scaled = DPoint3d(pt.x, pt.y, pt.z)
                            grid_points[i][j] = pt_scaled
                            if place_points:
                                try:
                                    eeh_pt = EditElementHandle()
                                    status = DraftingElementSchema.ToElement(
                                        eeh_pt,
                                        ICurvePrimitive.CreateLine(DSegment3d(pt_scaled, pt_scaled)),
                                        None,
                                        dgnModel.Is3d(),
                                        dgnModel
                                    )
                                    if BentleyStatus.eSUCCESS == status:
                                        ElementPropertyUtils.ApplyActiveSettings(eeh_pt)
                                        eeh_pt.AddToModel()
                                        num_points_placed += 1
                                except Exception as ex:
                                    show_error_dialog("Failed to place point.", str(ex))
                        else:
                            grid_points[i][j] = None

                num_quads_placed = 0
                num_solids_placed = 0
                # For each quad in the grid, optionally place a shape and/or extruded solid
                if place_shape or make_solid:
                    for i in range(num_u - 1):
                        for j in range(num_v - 1):
                            p00 = grid_points[i][j]
                            p10 = grid_points[i+1][j]
                            p11 = grid_points[i+1][j+1]
                            p01 = grid_points[i][j+1]
                            if None in (p00, p10, p11, p01):
                                continue
                            quad = DPoint3dArray()
                            quad.append(p00)
                            quad.append(p10)
                            quad.append(p11)
                            quad.append(p01)
                            if place_shape:
                                try:
                                    eeh_quad = EditElementHandle()
                                    status = ShapeHandler.CreateShapeElement(
                                        eeh_quad, None, quad, dgnModel.Is3d(), dgnModel
                                    )
                                    if BentleyStatus.eSUCCESS == status:
                                        ElementPropertyUtils.ApplyActiveSettings(eeh_quad)
                                        eeh_quad.AddToModel()
                                        num_quads_placed += 1
                                except Exception as ex:
                                    show_error_dialog("Failed to place shape.", str(ex))
                            if make_solid:
                                try:
                                    quad_pts = [p00, p10, p11, p01]
                                    origin, normal = best_fit_plane(quad_pts)
                                    if normal is None or normal.Magnitude() == 0:
                                        normal = DVec3d(ref_normal.x, ref_normal.y, ref_normal.z)
                                    else:
                                        normal.Normalize()
                                        normal = ensure_consistent_normal(normal, ref_normal)
                                    cv = CurveVector(CurveVector.eBOUNDARY_TYPE_Outer)
                                    segs = []
                                    for k in range(4):
                                        segs.append(ICurvePrimitive.CreateLine(DSegment3d(quad[k], quad[(k+1)%4])))
                                    for seg in segs:
                                        cv.Add(seg)
                                    extrude_vec = DVec3d(normal.x * thickness_uor, normal.y * thickness_uor, normal.z * thickness_uor)
                                    extrude_detail = DgnExtrusionDetail(cv, extrude_vec, True)
                                    solid_prim = ISolidPrimitive.CreateDgnExtrusion(extrude_detail)
                                    eeh_solid = EditElementHandle()
                                    status = DraftingElementSchema.ToElement(
                                        eeh_solid, solid_prim, None, dgnModel
                                    )
                                    if BentleyStatus.eSUCCESS == status:
                                        ElementPropertyUtils.ApplyActiveSettings(eeh_solid)
                                        eeh_solid.AddToModel()
                                        num_solids_placed += 1
                                except Exception as ex:
                                    show_error_dialog("Failed to place solid.", str(ex))

                total_points += num_points_placed
                total_quads += num_quads_placed
                total_solids += num_solids_placed

                # Optionally delete the original surface after processing
                if delete_surface:
                    try:
                        eeh.DeleteFromModel()
                    except Exception as ex:
                        show_error_dialog("Failed to delete surface.", str(ex))

            except Exception as ex:
                show_error_dialog("Error processing surface element.", traceback.format_exc())

        # Show summary message in MessageCenter
        MessageCenter.ShowInfoMessage(
            f"Placed {total_points if place_points else 0} points, "
            f"{total_quads if place_shape else 0} shapes, "
            f"{total_solids if make_solid else 0} solids on surface(s).", "", False
        )
    except Exception as ex:
        show_error_dialog("Unexpected error in placing geometry.", traceback.format_exc())

# PyQt5 dialog for user input and launching the geometry placement
class SurfaceGridDialog(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Place Points and Shapes on Surface")
        self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
        self.setWindowModality(Qt.NonModal)

        # Build the dialog layout with controls for U/V divisions, options, etc.
        grid = QGridLayout()
        grid.setContentsMargins(24, 24, 120, 24)
        grid.setHorizontalSpacing(16)
        grid.setVerticalSpacing(8)

        # U divisions spinner and "Place Points" checkbox
        grid.addWidget(QLabel("U divisions:"), 0, 0, Qt.AlignRight)
        self.u_spin = QSpinBox()
        self.u_spin.setMinimum(2)
        self.u_spin.setMaximum(999)
        self.u_spin.setValue(15)
        grid.addWidget(self.u_spin, 0, 1)
        self.points_chk = QCheckBox("Place Points")
        self.points_chk.setChecked(True)
        grid.addWidget(self.points_chk, 0, 2)

        # V divisions spinner and "Place Shape" checkbox
        grid.addWidget(QLabel("V divisions:"), 1, 0, Qt.AlignRight)
        self.v_spin = QSpinBox()
        self.v_spin.setMinimum(2)
        self.v_spin.setMaximum(999)
        self.v_spin.setValue(15)
        grid.addWidget(self.v_spin, 1, 1)
        self.shapes_chk = QCheckBox("Place Shape")
        self.shapes_chk.setChecked(True)
        grid.addWidget(self.shapes_chk, 1, 2)

        # Thickness spinner and "Place Solid" checkbox
        grid.addWidget(QLabel("Thickness:"), 2, 0, Qt.AlignRight)
        self.thickness_spin = QDoubleSpinBox()
        self.thickness_spin.setMinimum(0.01)
        self.thickness_spin.setMaximum(1e6)
        self.thickness_spin.setDecimals(3)
        self.thickness_spin.setValue(1.0)
        self.thickness_spin.setSingleStep(1.0)
        self.thickness_spin.setEnabled(False)
        grid.addWidget(self.thickness_spin, 2, 1)

        self.solid_chk = QCheckBox("Place Solid")
        self.solid_chk.setChecked(False)
        grid.addWidget(self.solid_chk, 2, 2)
        self.solid_chk.stateChanged.connect(self.thickness_spin.setEnabled)

        # "Delete Surface" checkbox
        self.delete_surface_chk = QCheckBox("Delete Surface")
        self.delete_surface_chk.setChecked(False)
        grid.addWidget(self.delete_surface_chk, 3, 2)

        # Label showing how many surfaces are selected
        surf_label_container = QWidget()
        surf_label_layout = QHBoxLayout()
        surf_label_layout.setContentsMargins(0, 0, 0, 0)
        surf_label_layout.setSpacing(0)
        self.surf_label = QLabel("No surfaces selected.")
        surf_label_layout.addWidget(self.surf_label)
        surf_label_container.setLayout(surf_label_layout)
        grid.addWidget(surf_label_container, 4, 0, 2, 4, Qt.AlignLeft)

        # Place button
        self.place_btn = QPushButton("Place")
        grid.addWidget(self.place_btn, 4, 0, 1, 3)
        self.place_btn.clicked.connect(self.on_place)

        self.setLayout(grid)
        self.resize(400, 280)

        # Timer to update the surface selection count every 500ms
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_surface_count)
        self.timer.start(500)
        self.update_surface_count()

    # Update the label showing the number of selected surfaces
    def update_surface_count(self):
        try:
            ids = get_selected_surface_ids()
            if ids:
                self.surf_label.setText(f"{len(ids)} surface(s) selected.")
            else:
                self.surf_label.setText("No surfaces selected.")
        except Exception as ex:
            show_error_dialog("Failed to update surface count.", str(ex))

    # Handler for the "Place" button
    def on_place(self):
        try:
            u = self.u_spin.value()
            v = self.v_spin.value()
            ids = get_selected_surface_ids()
            if not ids:
                QMessageBox.critical(self, "No Surfaces Selected", "Please select at least one BSpline surface using the selection tool, then click Place.")
                return
            place_points_and_quads_on_selected_surface(
                num_u=u,
                num_v=v,
                place_points=self.points_chk.isChecked(),
                place_shape=self.shapes_chk.isChecked(),
                make_solid=self.solid_chk.isChecked(),
                thickness=self.thickness_spin.value(),
                surface_ids=ids,
                delete_surface=self.delete_surface_chk.isChecked()
            )
            self.close()
        except Exception as ex:
            show_error_dialog("Error in Place operation.", traceback.format_exc())

    # Ensure dialog reference is cleared on close
    def closeEvent(self, event):
        if hasattr(sys, "_surface_grid_dialog"):
            sys._surface_grid_dialog = None
        super().closeEvent(event)

# Utility to check if a dialog is still valid (not deleted)
def is_dialog_valid(dlg):
    if dlg is None:
        return False
    if HAVE_SIP:
        try:
            if sip.isdeleted(dlg):
                return False
        except Exception:
            return False
    try:
        _ = dlg.isVisible()
    except RuntimeError:
        return False
    return True

# Show the main dialog, ensuring only one instance is active and keeping the event loop alive
def show_surface_grid_dialog():
    try:
        if not hasattr(sys, "_surface_grid_app"):
            sys._surface_grid_app = None
        if not hasattr(sys, "_surface_grid_dialog"):
            sys._surface_grid_dialog = None
        if sys._surface_grid_app is None:
            sys._surface_grid_app = QApplication.instance()
            if sys._surface_grid_app is None:
                sys._surface_grid_app = QApplication(sys.argv)
        dlg = getattr(sys, "_surface_grid_dialog", None)
        if not is_dialog_valid(dlg):
            dlg = SurfaceGridDialog()
            sys._surface_grid_dialog = dlg
        dlg.show()
        dlg.raise_()
        dlg.activateWindow()
        # Keep the dialog and event loop alive as long as the dialog is visible
        def keep_alive():
            try:
                if is_dialog_valid(sys._surface_grid_dialog) and sys._surface_grid_dialog.isVisible():
                    QApplication.processEvents()
                    QTimer.singleShot(100, keep_alive)
            except Exception:
                pass
        QTimer.singleShot(100, keep_alive)
    except Exception as ex:
        show_error_dialog("Failed to show dialog.", traceback.format_exc())

# Usage: call show_surface_grid_dialog() to launch the tool
show_surface_grid_dialog()