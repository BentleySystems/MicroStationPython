"""
Guide Lines: Circle & Bspline for MicroStation

This script provides a PyQt5-based dialog for MicroStation that allows users to select a circle and a B-spline curve
from the active DGN model and generate guide lines and cylinders between the circle center and points along the B-spline.
The number of guide lines/cylinders is user-adjustable. The script monitors geometry for changes and updates the guides
automatically. It demonstrates element selection, geometry extraction, and dynamic element creation in MicroStation
using the Python API.

Helper functions are provided throughout the code to facilitate extension, debugging, and code clarity.
"""

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import sys
import traceback
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QWidget, QFormLayout, QHBoxLayout,
    QLabel, QPushButton, QComboBox, QSlider
)
from PyQt5.QtCore import Qt, QTimer

# -------------------- Helper Functions --------------------

def describe_script():
    """
    Print a high-level description of what this script does.
    """
    print(__doc__)

def debug_print(msg):
    """
    Print a debug message.
    Args:
        msg (str): The message to print.
    """
    print(f"[DEBUG] {msg}")

def print_element_list(elements, label="Elements"):
    """
    Print a list of element IDs and names for debugging.
    Args:
        elements (list): List of (id, name) tuples.
        label (str): Label for the printout.
    """
    print(f"{label}:")
    for eid, name in elements:
        print(f"  ID {eid}: {name}")

def print_point3d(pt, label="Point"):
    """
    Print a DPoint3d for debugging.
    Args:
        pt (DPoint3d): The point to print.
        label (str): Label for the printout.
    """
    print(f"{label}: ({pt.x:.3f}, {pt.y:.3f}, {pt.z:.3f})")

def print_point3d_list(pts, label="Points"):
    """
    Print a list of DPoint3d for debugging.
    Args:
        pts (list): List of DPoint3d.
        label (str): Label for the printout.
    """
    print(f"{label}:")
    for i, pt in enumerate(pts):
        print(f"  {i}: ({pt.x:.3f}, {pt.y:.3f}, {pt.z:.3f})")

def validate_element_handle(eeh):
    """
    Validate an EditElementHandle and print a warning if invalid.
    Args:
        eeh (EditElementHandle): The element handle to validate.
    Returns:
        bool: True if valid, False otherwise.
    """
    if not eeh or not eeh.IsValid():
        print("Warning: Invalid EditElementHandle.")
        return False
    return True

def validate_curve_vector(cv):
    """
    Validate a CurveVector and print a warning if invalid.
    Args:
        cv: The CurveVector to validate.
    Returns:
        bool: True if valid, False otherwise.
    """
    if cv is None or len(cv) == 0:
        print("Warning: Invalid or empty CurveVector.")
        return False
    return True

def print_exception_context(context, ex):
    """
    Print an exception with context string.
    Args:
        context (str): Context string.
        ex (Exception): The exception object.
    """
    print(f"Exception in {context}: {ex}")
    traceback.print_exc()

# -------------------- End of Helper Functions --------------------

_app_instance = None
_guide_line_dialog = None

def is_dialog_valid(dlg):
    try:
        return dlg is not None and dlg.isVisible()
    except Exception:
        return False

def get_circle_elements():
    try:
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        elements = []
        for elemRef in dgnModel.GetGraphicElements():
            eeh = EditElementHandle(elemRef, dgnModel)
            if not eeh.IsValid():
                continue
            elemType = eeh.GetElementType()
            if elemType == 15:  # Circle/Ellipse
                name = f"ID {eeh.GetElementId()} (Circle)"
                elements.append((eeh.GetElementId(), name))
        # Helper: print found circles
        print_element_list(elements, label="Found Circles")
        return elements
    except Exception as ex:
        print_exception_context("get_circle_elements", ex)
        return []

def get_bspline_curve_elements():
    try:
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        elements = []
        for elemRef in dgnModel.GetGraphicElements():
            eeh = EditElementHandle(elemRef, dgnModel)
            if not eeh.IsValid():
                continue
            elemType = eeh.GetElementType()
            if elemType == 27:  # B-spline curve
                name = f"ID {eeh.GetElementId()}"
                elements.append((eeh.GetElementId(), name))
        # Helper: print found bsplines
        print_element_list(elements, label="Found B-spline Curves")
        return elements
    except Exception as ex:
        print_exception_context("get_bspline_curve_elements", ex)
        return []

def get_circle_center_and_radius(eeh):
    try:
        msElem = eeh.GetElement()
        if hasattr(msElem, "ellipse_3d"):
            center = msElem.ellipse_3d.origin
            radius = msElem.ellipse_3d.primary
            # Helper: print extracted center/radius
            print_point3d(center, label="Circle Center (3D)")
            print(f"Circle Radius: {radius}")
            return center, radius
        elif hasattr(msElem, "ellipse_2d"):
            pt2d = msElem.ellipse_2d.origin
            center = DPoint3d(pt2d.x, pt2d.y, 0.0)
            radius = msElem.ellipse_2d.primary
            print_point3d(center, label="Circle Center (2D)")
            print(f"Circle Radius: {radius}")
            return center, radius
    except Exception as ex:
        print_exception_context("get_circle_center_and_radius", ex)
    return None, None

def get_bspline_fractions_by_arclength(curve, n_targets=20):
    length_result = curve.Length()
    if isinstance(length_result, tuple):
        total_length = length_result[1]
    else:
        total_length = length_result
    fractions = []
    for i in range(n_targets):
        target_length = (i / (n_targets - 1)) * total_length
        location = CurveLocationDetail()
        start_fraction = 0.0
        signed_distance = target_length
        allow_extension = False
        found = curve.PointAtSignedDistanceFromFraction(start_fraction, signed_distance, allow_extension, location)
        if found:
            fractions.append(location.fraction)
        else:
            fractions.append(i / (n_targets - 1))
    # Helper: print fractions
    debug_print(f"Fractions along curve: {fractions}")
    return fractions

def point3d_equal(a, b, tol=1e-6):
    return abs(a.x - b.x) < tol and abs(a.y - b.y) < tol and abs(a.z - b.z) < tol

def point3d_list_equal(list1, list2, tol=1e-6):
    if len(list1) != len(list2):
        return False
    for p1, p2 in zip(list1, list2):
        if not point3d_equal(p1, p2, tol):
            return False
    return True

class GuideLineDialog(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Guide Lines: Circle & Bspline")
        self.setFixedSize(340, 150)
        self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
        self.elements = []
        self._deferred_action = None
        self._pending_close = False
        self.circle_id = None
        self.bspline_id = None
        self._circle_list = []
        self._curve_list = []
        self.last_circle_center = None
        self.last_circle_radius = None
        self.last_bspline_points = None
        self.npts = 20

        self.initUI()

        self._timer = QTimer(self)
        self._timer.timeout.connect(self.process_deferred_actions)
        self._timer.start(200)

    # ---------- Dialog Helper Methods ----------

    def print_dialog_state(self):
        """
        Print the current state of the dialog and selected elements.
        """
        debug_print(f"Dialog State: circle_id={self.circle_id}, bspline_id={self.bspline_id}, npts={self.npts}")

    def print_last_geometry(self):
        """
        Print the last stored geometry for debugging.
        """
        if self.last_circle_center:
            print_point3d(self.last_circle_center, label="Last Circle Center")
        if self.last_bspline_points:
            print_point3d_list(self.last_bspline_points, label="Last B-spline Points")

    # ---------- End Dialog Helper Methods ----------

    def initUI(self):
        central = QWidget()
        self.setCentralWidget(central)
        form = QFormLayout(central)
        form.setContentsMargins(10, 8, 10, 8)
        form.setSpacing(6)

        self.circle_combo = QComboBox()
        self.bspline_combo = QComboBox()

        # Slider for count
        self.npts_slider = QSlider(Qt.Horizontal)
        self.npts_slider.setRange(3, 25)
        self.npts_slider.setValue(self.npts)
        self.npts_slider.setTickInterval(1)
        self.npts_slider.setSingleStep(1)
        self.npts_slider.setFixedWidth(120)
        self.npts_slider.setToolTip("Number of guide lines/cylinders")

        self.npts_label = QLabel(str(self.npts))
        self.npts_label.setFixedWidth(24)
        slider_row = QHBoxLayout()
        slider_row.addWidget(self.npts_slider)
        slider_row.addWidget(self.npts_label)
        slider_row.addStretch(1)

        form.addRow(QLabel("Circle:"), self.circle_combo)
        form.addRow(QLabel("Bspline:"), self.bspline_combo)
        form.addRow(QLabel("Count:"), slider_row)

        btn_row = QHBoxLayout()
        self.refresh_btn = QPushButton("Refresh")
        self.update_btn = QPushButton("Update")
        self.exit_btn = QPushButton("Exit")
        btn_row.addWidget(self.refresh_btn)
        btn_row.addWidget(self.update_btn)
        btn_row.addWidget(self.exit_btn)
        btn_row.setSpacing(8)
        btn_row.addStretch(1)
        form.addRow(btn_row)

        self.circle_combo.currentIndexChanged.connect(self.defer_refresh_ids)
        self.bspline_combo.currentIndexChanged.connect(self.defer_refresh_ids)
        self.npts_slider.valueChanged.connect(self.on_npts_changed)
        self.refresh_btn.clicked.connect(self.defer_refresh_lists)
        self.update_btn.clicked.connect(self.defer_update_geometry)
        self.exit_btn.clicked.connect(self.defer_close)

        self.defer_refresh_lists()

    def on_npts_changed(self, val):
        self.npts = val
        self.npts_label.setText(str(val))
        self.defer_update_geometry()

    def defer_refresh_lists(self):
        self._deferred_action = "refresh_lists"

    def defer_refresh_ids(self):
        self._deferred_action = "refresh_ids"

    def defer_update_geometry(self):
        self._deferred_action = "update_geometry"

    def defer_close(self):
        self._pending_close = True

    def process_deferred_actions(self):
        try:
            if self._pending_close:
                self._pending_close = False
                self.close()
                return

            if self._deferred_action == "refresh_lists":
                self._deferred_action = None
                self.refresh_element_lists()
            elif self._deferred_action == "refresh_ids":
                self._deferred_action = None
                self.refresh_ids()
            elif self._deferred_action == "update_geometry":
                self._deferred_action = None
                self.do_update_geometry()
            self.check_geometry_movement_and_update()
        except Exception as ex:
            print_exception_context("process_deferred_actions", ex)

    def refresh_element_lists(self):
        try:
            self._circle_list = get_circle_elements()
            self._curve_list = get_bspline_curve_elements()
            self.circle_combo.blockSignals(True)
            self.bspline_combo.blockSignals(True)
            self.circle_combo.clear()
            self.bspline_combo.clear()
            for eid, name in self._circle_list:
                self.circle_combo.addItem(name, eid)
            for eid, name in self._curve_list:
                self.bspline_combo.addItem(name, eid)
            self.circle_combo.blockSignals(False)
            self.bspline_combo.blockSignals(False)
            self.refresh_ids()
        except Exception as ex:
            print_exception_context("refresh_element_lists", ex)

    def refresh_ids(self):
        try:
            self.circle_id = self.circle_combo.currentData()
            self.bspline_id = self.bspline_combo.currentData()
            # Helper: print dialog state
            self.print_dialog_state()
        except Exception as ex:
            print_exception_context("refresh_ids", ex)

    def clear_previous_elements(self):
        try:
            for eeh in self.elements:
                try:
                    if eeh is not None:
                        eeh.DeleteFromModel()
                except Exception as inner_ex:
                    print_exception_context("clear_previous_elements (delete)", inner_ex)
            self.elements = []
        except Exception as ex:
            print_exception_context("clear_previous_elements", ex)

    def do_update_geometry(self):
        try:
            circle_id = self.circle_combo.currentData()
            curve_id = self.bspline_combo.currentData()
            if circle_id is None or curve_id is None:
                print("Please select both a Circle and a B-spline curve.")
                return
            if circle_id == curve_id:
                print("Please select two different elements.")
                return

            self.circle_id = circle_id
            self.bspline_id = curve_id

            self.clear_previous_elements()
            self.create_guide_lines_and_cylinders()
        except Exception as ex:
            print_exception_context("do_update_geometry", ex)

    def create_guide_lines_and_cylinders(self):
        try:
            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
            dgnModel = ACTIVEMODEL.GetDgnModel()

            eeh_circle = EditElementHandle(self.circle_id, dgnModel)
            eeh_curve = EditElementHandle(self.bspline_id, dgnModel)
            if not (eeh_circle.IsValid() and eeh_curve.IsValid()):
                print("Could not find both elements.")
                return

            center, radius = get_circle_center_and_radius(eeh_circle)
            if center is None or radius is None:
                print("Could not extract center/radius from Circle element.")
                return

            self.last_circle_center = DPoint3d(center.x, center.y, center.z)
            self.last_circle_radius = radius

            cv = ICurvePathQuery.ElementToCurveVector(eeh_curve)
            if not validate_curve_vector(cv):
                print("Could not extract CurveVector from B-spline element.")
                return
            curve = cv[0]

            npts = self.npts
            fractions = get_bspline_fractions_by_arclength(curve, n_targets=npts)
            pts = []
            for frac in fractions:
                pt = DPoint3d()
                curve.FractionToPoint(frac, pt)
                pts.append(DPoint3d(pt.x, pt.y, pt.z))
            self.last_bspline_points = pts

            # Helper: print geometry to be used
            self.print_last_geometry()

            for pt in pts:
                # Draw the line
                eeh_line = EditElementHandle()
                seg = DSegment3d(center, pt)
                status = LineHandler.CreateLineElement(eeh_line, None, seg, dgnModel.Is3d(), dgnModel)
                if status == BentleyStatus.eSUCCESS:
                    propSetter = ElementPropertiesSetter()
                    propSetter.SetWeight(0)
                    propSetter.SetLinestyle(1, None)
                    propSetter.Apply(eeh_line)
                    eeh_line.AddToModel()
                    self.elements.append(eeh_line)
                # Extrude the cylinder
                length = center.Distance(pt)
                base = pt
                top = DPoint3d(pt.x, pt.y, pt.z + length)
                cone_detail = DgnConeDetail(base, top, radius, radius, True)
                solid = ISolidPrimitive.CreateDgnCone(cone_detail)
                eeh_cyl = EditElementHandle()
                if BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement(eeh_cyl, solid, None, dgnModel):
                    eeh_cyl.AddToModel()
                    self.elements.append(eeh_cyl)
        except Exception as ex:
            print_exception_context("create_guide_lines_and_cylinders", ex)

    def check_geometry_movement_and_update(self):
        if self.circle_id is None or self.bspline_id is None or not self.elements:
            return
        try:
            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
            dgnModel = ACTIVEMODEL.GetDgnModel()
            eeh_circle = EditElementHandle(self.circle_id, dgnModel)
            eeh_curve = EditElementHandle(self.bspline_id, dgnModel)
            if not (eeh_circle.IsValid() and eeh_curve.IsValid()):
                return
            center, radius = get_circle_center_and_radius(eeh_circle)
            if center is None or radius is None:
                return
            circle_changed = (
                self.last_circle_center is None or not point3d_equal(center, self.last_circle_center) or
                self.last_circle_radius is None or abs(radius - self.last_circle_radius) > 1e-6
            )
            cv = ICurvePathQuery.ElementToCurveVector(eeh_curve)
            if not validate_curve_vector(cv):
                return
            curve = cv[0]
            npts = self.npts
            fractions = get_bspline_fractions_by_arclength(curve, n_targets=npts)
            pts = []
            for frac in fractions:
                pt = DPoint3d()
                curve.FractionToPoint(frac, pt)
                pts.append(DPoint3d(pt.x, pt.y, pt.z))
            bspline_changed = (
                self.last_bspline_points is None or not point3d_list_equal(pts, self.last_bspline_points, tol=1e-6)
            )
            if circle_changed or bspline_changed:
                debug_print("Detected geometry change, updating guides.")
                self.clear_previous_elements()
                self.create_guide_lines_and_cylinders()
        except Exception as ex:
            print_exception_context("check_geometry_movement_and_update", ex)

    def closeEvent(self, event):
        global _guide_line_dialog
        _guide_line_dialog = None
        super().closeEvent(event)

def show_guide_line_dialog():
    global _app_instance, _guide_line_dialog
    if QApplication.instance() is None:
        _app_instance = QApplication(sys.argv)
    else:
        _app_instance = QApplication.instance()
    if is_dialog_valid(_guide_line_dialog):
        _guide_line_dialog.raise_()
        _guide_line_dialog.activateWindow()
        return
    _guide_line_dialog = GuideLineDialog()
    _guide_line_dialog.show()
    _guide_line_dialog.raise_()
    _guide_line_dialog.activateWindow()

if __name__ == "__main__":
    describe_script()
    show_guide_line_dialog()