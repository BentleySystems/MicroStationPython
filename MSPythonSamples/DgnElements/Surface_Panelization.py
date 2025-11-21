"""
DESCRIPTION:
-------------
This script provides a graphical user interface (GUI) for panelizing (tiling) a selected surface in MicroStation using a custom motif (tile) defined by the user.
It allows the user to:
- Select a surface or solid in the active DGN model.
- Define a motif polygon by sketching on a grid.
- Specify grid divisions, motif shifts, spacings, and output options (points, shapes, solids).
- Extrude motifs normal to their best-fit plane, ensuring consistent extrusion direction.
- Optionally keep motifs planar, include/exclude start/end pieces, and flip extrusion direction.
- Save/load motif and grid settings as named designs.
- Place the resulting geometry (points, shapes, solids) onto the selected surface(s) in the active model.

The script uses PyQt5 for the GUI and the MicroStation Python API for geometry creation and manipulation.
Helper functions are provided throughout for geometry, validation, and UI logic.

REQUIREMENTS:
-------------
- MicroStation CONNECT Edition with Python API enabled.
- PyQt5 installed in the Python environment used by MicroStation.

"""


from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

from PyQt5.QtWidgets import (
    QApplication, QWidget, QLabel, QDoubleSpinBox, QSpinBox, QCheckBox, QPushButton, QGridLayout, QMessageBox, QHBoxLayout, QFrame,
    QVBoxLayout, QListWidget, QListWidgetItem, QLineEdit, QInputDialog, QGroupBox, QFormLayout, QSizePolicy
)
from PyQt5.QtCore import Qt, QTimer, QPoint, pyqtSignal
from PyQt5.QtGui import QPainter, QPen, QColor, QPolygonF
import sys
import traceback
import json
import os
import numpy as np

#Rules

#Each motif tile should extrude normal to its own best-fit plane (i.e., the local orientation of the tile).
#The extrusion direction should be consistent with the "positive" side of the underlying surface (i.e., all extrusions go to the same side of the surface, not flipping randomly). Make this occur on surfaces with tight folds
#Shapes with an area of 0 must not be extrude

def polygon_area_2d(pts):
    """Shoelace formula for area in UV space."""
    area = 0.0
    n = len(pts)
    for i in range(n):
        x1, y1 = pts[i][0], pts[i][1]
        x2, y2 = pts[(i+1)%n][0], pts[(i+1)%n][1]
        area += (x1 * y2 - x2 * y1)
    return area * 0.5

def ensure_ccw_uv_order(uv_pts, xyz_pts):
    """Reverse order if polygon is clockwise in UV."""
    if polygon_area_2d(uv_pts) < 0:
        return list(reversed(uv_pts)), list(reversed(xyz_pts))
    return uv_pts, xyz_pts
    
def is_valid_polygon(poly_pts, area_tol=1e-8):
    if len(poly_pts) < 3:
        return False
    # Remove consecutive duplicate points
    unique_pts = []
    for pt in poly_pts:
        if not unique_pts or pt.Distance(unique_pts[-1]) > 1e-8:
            unique_pts.append(pt)
    if len(unique_pts) < 3:
        return False
    # Compute area using best-fit plane normal magnitude
    origin, normal = best_fit_plane(unique_pts)
    if normal is None or normal.Magnitude() < area_tol:
        return False
    return True

def centroid(polygon):
    x = sum(p[0] for p in polygon) / len(polygon)
    y = sum(p[1] for p in polygon) / len(polygon)
    return (x, y)

def point_in_polygon(pt, polygon):
    """Ray casting algorithm for point-in-polygon in 2D."""
    x, y = pt
    inside = False
    n = len(polygon)
    px1, py1 = polygon[0]
    for i in range(n+1):
        px2, py2 = polygon[i % n]
        if min(py1, py2) < y <= max(py1, py2) and x < (px2 - px1) * (y - py1) / (py2 - py1 + 1e-12) + px1:
            inside = not inside
        px1, py1 = px2, py2
    return inside

def get_trim_boundaries_uv(surface):
    """Extract trimming boundaries as lists of (u,v) tuples."""
    trims = []
    try:
        nLoops = surface.GetNumTrimLoops()
        for i in range(nLoops):
            loop = surface.GetTrimLoop(i)
            nCurves = loop.GetNumCurves()
            for j in range(nCurves):
                curve = loop.GetCurve(j)
                pts = DPoint2dArray()
                curve.GetSampledPoints(pts, 100)  # Sample curve into points
                trims.append([(pt.x, pt.y) for pt in pts])
    except Exception:
        pass
    return trims

def polygon_inside_trims(polygon, trim_loops):
    """Return True if all points of polygon are inside the outer trim and not inside any holes."""
    if not trim_loops:
        return True  # No trims: treat as untrimmed
    outer = trim_loops[0]
    holes = trim_loops[1:]
    for pt in polygon:
        if not point_in_polygon(pt, outer):
            return False
        for hole in holes:
            if point_in_polygon(pt, hole):
                return False
    return True

def sutherland_hodgman_clip(polygon, clip_rect):
    """
    Clip a polygon (list of (u,v) tuples) to a rectangular region [u_min,u_max] x [v_min,v_max]
    using the Sutherland-Hodgman algorithm.
    """
    def inside(p, edge):
        u, v = p
        if edge == 0: return u >= clip_rect[0]  # left
        if edge == 1: return u <= clip_rect[1]  # right
        if edge == 2: return v >= clip_rect[2]  # bottom
        if edge == 3: return v <= clip_rect[3]  # top

    def intersect(p1, p2, edge):
        u1, v1 = p1
        u2, v2 = p2
        if edge == 0:  # left
            u = clip_rect[0]
            v = v1 + (v2 - v1) * (clip_rect[0] - u1) / (u2 - u1) if u2 != u1 else v1
            return (u, v)
        if edge == 1:  # right
            u = clip_rect[1]
            v = v1 + (v2 - v1) * (clip_rect[1] - u1) / (u2 - u1) if u2 != u1 else v1
            return (u, v)
        if edge == 2:  # bottom
            v = clip_rect[2]
            u = u1 + (u2 - u1) * (clip_rect[2] - v1) / (v2 - v1) if v2 != v1 else u1
            return (u, v)
        if edge == 3:  # top
            v = clip_rect[3]
            u = u1 + (u2 - u1) * (clip_rect[3] - v1) / (v2 - v1) if v2 != v1 else u1
            return (u, v)

    output = polygon
    for edge in range(4):
        input_list = output
        output = []
        if not input_list:
            break
        s = input_list[-1]
        for e in input_list:
            if inside(e, edge):
                if not inside(s, edge):
                    output.append(intersect(s, e, edge))
                output.append(e)
            elif inside(s, edge):
                output.append(intersect(s, e, edge))
            s = e
    return output

def show_error_dialog(msg, detail=""):
    MessageCenter.ShowErrorMessage(msg, detail, False)
    try:
        from PyQt5.QtWidgets import QMessageBox
        QMessageBox.critical(None, "Error", f"{msg}\n\n{detail}")
    except Exception:
        pass

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
            elem_type = eeh.GetElementType()
            # Accept BSpline Surface directly
            if elem_type == MSElementTypes.eBSPLINE_SURFACE_ELM:
                ids.append(eeh.ElementId)
            else:
                # Try to convert any other element to a Body (Parametric, SmartSolid, SmartSurface, etc.)
                body_result = SolidUtil.Convert.ElementToBody(eeh, True, True, False)
                if body_result[0] == BentleyStatus.eSUCCESS and body_result[1] is not None:
                    ids.append(eeh.ElementId)
        return ids
    except Exception as ex:
        show_error_dialog("Failed to get selected surfaces.", str(ex))
        return []

def best_fit_plane(points):
    import numpy as np
    pts = np.array([[p.x, p.y, p.z] for p in points if p is not None])
    if pts.shape[0] < 3:
        return None, None
    centroid = pts.mean(axis=0)
    uu, dd, vv = np.linalg.svd(pts - centroid)
    normal = vv[2, :]
    return DPoint3d(*centroid), DVec3d(*normal)

def ensure_consistent_normal(normal, reference_normal):
    # Align normal direction to reference_normal
    if normal.DotProduct(reference_normal) < 0:
        normal.Negate()
    return normal

class PolygonSketchWidget(QFrame):
    def __init__(self, parent=None, grid_size_u=11, grid_size_v=11, boundary_size=220):
        super().__init__(parent)
        self.grid_size_u = grid_size_u
        self.grid_size_v = grid_size_v
        self.boundary_size = boundary_size
        self.setMinimumSize(boundary_size, boundary_size)
        self.setMaximumSize(boundary_size, boundary_size)
        self.setFrameStyle(QFrame.Box | QFrame.Plain)
        self.setLineWidth(1)
        self.dots = []
        self.shapes = []
        self.current_shape = []
        self.setMouseTracking(True)
        self._build_grid()
        self._hover_point = None

    def set_grid_size(self, grid_size_u, grid_size_v):
        self.grid_size_u = grid_size_u
        self.grid_size_v = grid_size_v
        self._build_grid()
        self.shapes.clear()
        self.current_shape = []
        self.update()

    def set_boundary_size(self, boundary_size):
        self.boundary_size = boundary_size
        self.setMinimumSize(boundary_size, boundary_size)
        self.setMaximumSize(boundary_size, boundary_size)
        self._build_grid()
        self.update()

    def set_spacing(self, row_spacing, col_spacing):
        self._build_grid()
        self.update()

    def _build_grid(self):
        self.dots.clear()
        margin = 10
        width = self.boundary_size - 2 * margin
        height = self.boundary_size - 2 * margin
        n_u = self.grid_size_u
        n_v = self.grid_size_v
        for i in range(n_u):
            x = margin + (width * i) / (n_u - 1) if n_u > 1 else margin + width / 2
            for j in range(n_v):
                y = margin + (height * j) / (n_v - 1) if n_v > 1 else margin + height / 2
                self.dots.append(QPoint(int(x), int(y)))

    def resizeEvent(self, event):
        self._build_grid()
        super().resizeEvent(event)

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)
        pen = QPen(QColor(180, 180, 180))
        painter.setPen(pen)
        for pt in self.dots:
            painter.drawEllipse(pt, 2, 2)
        for shape in self.shapes:
            if shape:
                poly = QPolygonF([self.dots[idx] for idx in shape])
                painter.setPen(QPen(QColor(0, 120, 255), 2))
                painter.drawPolyline(poly)
                if len(shape) > 2:
                    painter.setBrush(QColor(0, 120, 255, 40))
                    painter.drawPolygon(poly)
        if self.current_shape:
            poly = QPolygonF([self.dots[idx] for idx in self.current_shape])
            painter.setPen(QPen(QColor(255, 120, 0), 2, Qt.DashLine))
            painter.drawPolyline(poly)
            if len(self.current_shape) > 2:
                painter.setBrush(QColor(255, 120, 0, 40))
                painter.drawPolygon(poly)
        if self._hover_point is not None:
            painter.setPen(QPen(QColor(255, 0, 0), 2))
            painter.setBrush(QColor(255, 0, 0, 80))
            painter.drawEllipse(self.dots[self._hover_point], 6, 6)

    def mouseMoveEvent(self, event):
        idx = self._find_nearest_dot(event.pos())
        if idx != self._hover_point:
            self._hover_point = idx
            self.update()

    def mousePressEvent(self, event):
        idx = self._find_nearest_dot(event.pos())
        if idx is not None:
            if event.button() == Qt.RightButton:
                self.finish_current_shape()
                return
            if self.current_shape and idx == self.current_shape[0] and len(self.current_shape) > 2:
                self.current_shape.append(idx)
                self.finish_current_shape()
            elif idx not in self.current_shape:
                self.current_shape.append(idx)
            self.update()

    def mouseDoubleClickEvent(self, event):
        if self.current_shape and len(self.current_shape) > 2:
            self.finish_current_shape()

    def finish_current_shape(self):
        if self.current_shape:
            if len(self.current_shape) > 2:
                if self.current_shape[-1] != self.current_shape[0]:
                    self.current_shape.append(self.current_shape[0])
                self.shapes.append(self.current_shape[:-1])
            self.current_shape = []
            self.update()

    def finish_shape_button(self):
        self.finish_current_shape()

    def _find_nearest_dot(self, pos):
        for i, pt in enumerate(self.dots):
            if (pt - pos).manhattanLength() < 10:
                return i
        return None

    def clear_all(self):
        self.shapes.clear()
        self.current_shape = []
        self.update()

    def get_all_shapes(self):
        all_shapes = []
        for shape in self.shapes:
            if len(shape) >= 3:
                all_shapes.append(shape)
        if self.current_shape and len(self.current_shape) >= 3:
            all_shapes.append(self.current_shape)
        return all_shapes

class ShiftPreviewWidget(QFrame):
    def __init__(self, parent=None, boundary_size=220):
        super().__init__(parent)
        self.boundary_size = boundary_size
        self.setMinimumSize(boundary_size, boundary_size)
        self.setMaximumSize(boundary_size, boundary_size)
        self.shift_u = 0.0
        self.shift_v = 0.0
        self.row_spacing = 1.0
        self.col_spacing = 1.0
        self.setFrameStyle(QFrame.Box | QFrame.Plain)
        self.setLineWidth(1)
        self.motif_shapes = []
        self.grid_size_u = 11
        self.grid_size_v = 11
        self.show_end_pieces = False
        
    def set_show_end_pieces(self, value: bool):
        self.show_end_pieces = value
        self.update()

    def set_boundary_size(self, boundary_size):
        self.boundary_size = boundary_size
        self.setMinimumSize(boundary_size, boundary_size)
        self.setMaximumSize(boundary_size, boundary_size)
        self.update()

    def set_shifts(self, shift_u, shift_v, row_spacing=1.0, col_spacing=1.0, motif_shapes=None, grid_size_u=11, grid_size_v=11):
        self.shift_u = float(shift_u)
        self.shift_v = float(shift_v)
        self.row_spacing = float(col_spacing)
        self.col_spacing = float(row_spacing)
        self.grid_size_u = int(grid_size_u)
        self.grid_size_v = int(grid_size_v)
        if motif_shapes is not None and isinstance(motif_shapes, list) and len(motif_shapes) > 0 and isinstance(motif_shapes[0], list):
            self.motif_shapes = [list(map(int, shape)) for shape in motif_shapes if len(shape) >= 3]
        else:
            self.motif_shapes = []
        self.update()

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHint(QPainter.Antialiasing)
        painter.fillRect(self.rect(), QColor(255,255,255))
        pen = QPen(QColor(80, 80, 80), 1)
        painter.setPen(pen)
        margin = 10
        size = self.boundary_size - 2 * margin
        n_cells = 4
        cell_w = size / n_cells
        cell_h = size / n_cells

        motif_shapes = self.motif_shapes if self.motif_shapes else [[0, self.grid_size_v-1, (self.grid_size_u-1)*self.grid_size_v + self.grid_size_v-1, (self.grid_size_u-1)*self.grid_size_v + 0]]

        def normalize_shape(shape, grid_size_u, grid_size_v):
            points = []
            for idx in shape:
                try:
                    i = idx // grid_size_v
                    j = idx % grid_size_v
                    u = i / (grid_size_u-1) if grid_size_u > 1 else 0
                    v = j / (grid_size_v-1) if grid_size_v > 1 else 0
                    points.append((u, v))
                except Exception:
                    continue
            return points

        motif_w = cell_w
        motif_h = cell_h
        motif_offx = 0
        motif_offy = 0

        step_x = cell_w * self.col_spacing
        step_y = cell_h * self.row_spacing

        n_tiles_x = int((size - cell_w + 1e-8) / step_x) + 2
        n_tiles_y = int((size - cell_h + 1e-8) / step_y) + 2

        for j in range(-1, n_tiles_y+2):
            for i in range(-1, n_tiles_x+2):
                tile_x = margin + i * step_x
                tile_y = margin + j * step_y
                shift_u_px = self.shift_u * cell_w if (j % 2 == 1) else 0.0
                shift_v_px = self.shift_v * cell_h if (i % 2 == 1) else 0.0
                base_x = tile_x + shift_u_px
                base_y = tile_y + shift_v_px
                for shape in motif_shapes:
                    if len(shape) < 3:
                        continue
                    norm_pts = normalize_shape(shape, self.grid_size_u, self.grid_size_v)
                    if len(norm_pts) < 3:
                        continue
                    poly = QPolygonF()
                    screen_poly = []
                    for u, v in norm_pts:
                        x = base_x + motif_offx + u * motif_w
                        y = base_y + motif_offy + v * motif_h
                        poly.append(QPoint(int(x), int(y)))
                        screen_poly.append((x, y))
                    # Clip to preview area
                    clip_rect = (margin, margin + size, margin, margin + size)
                    clipped_poly = sutherland_hodgman_clip(screen_poly, clip_rect)
                    # Determine if this tile is a "main" tile (fully inside) or an "end piece" (crosses boundary)
                    fully_inside = all(
                        margin <= x <= margin + size and margin <= y <= margin + size
                        for x, y in screen_poly
                    )
                    # Only draw:
                    # - main tiles (fully inside) always
                    # - end pieces only if self.show_end_pieces is True
                    if (fully_inside or self.show_end_pieces) and len(clipped_poly) >= 3:
                        qpoly = QPolygonF([QPoint(int(x), int(y)) for x, y in clipped_poly])
                        painter.setPen(QPen(QColor(0, 120, 255), 2))
                        painter.setBrush(QColor(0, 120, 255, 40))
                        painter.drawPolygon(qpoly)

class DesignManagerWidget(QWidget):
    design_selected = pyqtSignal(dict)

    def __init__(self, main_dialog=None, storage_path="surface_grid_designs.json"):
        super().__init__()
        self.main_dialog = main_dialog
        self.storage_path = storage_path
        self.designs = []
        self.list_widget = QListWidget()
        self.save_btn = QPushButton("Save Design")
        self.delete_btn = QPushButton("Delete")
        self.load_designs()
        self.init_ui()
        # self.setFixedHeight(162) # Removed to allow natural height

    def init_ui(self):
        layout = QVBoxLayout(self)
        layout.addWidget(self.list_widget)
        btn_layout = QHBoxLayout()
        btn_layout.addWidget(self.save_btn)
        btn_layout.addWidget(self.delete_btn)
        layout.addLayout(btn_layout)
        
        self.save_btn.clicked.connect(self.save_current_design)
        self.delete_btn.clicked.connect(self.delete_selected_design)
        self.list_widget.itemClicked.connect(self.on_item_clicked)
        self.list_widget.itemDoubleClicked.connect(self.on_item_double_clicked)
        self.refresh_list()

    def save_current_design(self):
        name, ok = QInputDialog.getText(self, "Save Design", "Design name:", QLineEdit.Normal, "Design {}".format(len(self.designs)+1))
        if not ok or not name.strip():
            return
        if self.main_dialog is None:
            QMessageBox.critical(self, "Error", "Main dialog reference missing.")
            return
        design = self.main_dialog.get_current_design()
        design['name'] = name.strip()
        for i, d in enumerate(self.designs):
            if d['name'] == design['name']:
                self.designs[i] = design
                break
        else:
            self.designs.append(design)
        self.save_designs()
        self.refresh_list()

    def delete_selected_design(self):
        items = self.list_widget.selectedItems()
        if not items:
            QMessageBox.information(self, "Delete", "Please select a design to delete.")
            return
        item = items[0]
        idx = self.list_widget.row(item)
        if 0 <= idx < len(self.designs):
            del self.designs[idx]
            self.save_designs()
            self.refresh_list()

    def on_item_clicked(self, item):
        idx = self.list_widget.row(item)
        if 0 <= idx < len(self.designs):
            self.design_selected.emit(self.designs[idx])

    def on_item_double_clicked(self, item):
        idx = self.list_widget.row(item)
        if 0 <= idx < len(self.designs):
            old_name = self.designs[idx]['name']
            new_name, ok = QInputDialog.getText(self, "Rename Design", "New name:", QLineEdit.Normal, old_name)
            if ok and new_name.strip():
                for i, d in enumerate(self.designs):
                    if i != idx and d['name'] == new_name.strip():
                        QMessageBox.warning(self, "Duplicate Name", "A design with this name already exists.")
                        return
                self.designs[idx]['name'] = new_name.strip()
                self.save_designs()
                self.refresh_list()
                for i in range(self.list_widget.count()):
                    if self.list_widget.item(i).text() == new_name.strip():
                        self.list_widget.setCurrentRow(i)
                        break

    def refresh_list(self):
        self.list_widget.blockSignals(True)
        self.list_widget.clear()
        for d in self.designs:
            item = QListWidgetItem(d['name'])
            item.setFlags(item.flags() & ~Qt.ItemIsEditable)
            self.list_widget.addItem(item)
        self.list_widget.blockSignals(False)

    def load_designs(self):
        if os.path.exists(self.storage_path):
            try:
                with open(self.storage_path, "r") as f:
                    self.designs = json.load(f)
            except Exception:
                self.designs = []
        else:
            self.designs = []

    def save_designs(self):
        try:
            with open(self.storage_path, "w") as f:
                json.dump(self.designs, f, indent=2)
        except Exception as ex:
            QMessageBox.warning(self, "Save Error", str(ex))

class SurfaceGridDialog(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Panelize Surface")
        self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
        self.setWindowModality(Qt.NonModal)
        self.boundary_size = 220

        # --- WIDGET CREATION & CONFIGURATION ---

        # Grid Spacing Widgets
        self.u_spin = QSpinBox(); self.u_spin.setRange(2, 999); self.u_spin.setValue(15)
        self.v_spin = QSpinBox(); self.v_spin.setRange(2, 999); self.v_spin.setValue(15)
        self.sketch_grid_u_spin = QSpinBox(); self.sketch_grid_u_spin.setRange(3, 20); self.sketch_grid_u_spin.setValue(11)
        self.sketch_grid_v_spin = QSpinBox(); self.sketch_grid_v_spin.setRange(3, 20); self.sketch_grid_v_spin.setValue(11)

        # Output Option Widgets
        self.points_chk = QCheckBox("Place Points"); self.points_chk.setChecked(True)
        self.shapes_chk = QCheckBox("Place Shape"); self.shapes_chk.setChecked(True)
        self.solid_chk = QCheckBox("Place Solid"); self.solid_chk.setChecked(False)
        self.thickness_spin = QDoubleSpinBox()
        self.thickness_spin.setRange(0.01, 100000); self.thickness_spin.setDecimals(2); self.thickness_spin.setValue(5.00)
        self.keep_planar_chk = QCheckBox("Keep Planar"); self.keep_planar_chk.setChecked(False)
        self.start_end_chk = QCheckBox("Start/End Pieces"); self.start_end_chk.setChecked(True)
        self.flip_dir_chk = QCheckBox("Flip Direction")
        self.flip_dir_chk.setChecked(False)
        
        # Motif Sketch and Preview Widgets
        self.sketch_widget = PolygonSketchWidget(
            grid_size_u=self.sketch_grid_u_spin.value(), grid_size_v=self.sketch_grid_v_spin.value(), boundary_size=self.boundary_size
        )
        self.preview_widget = ShiftPreviewWidget(boundary_size=self.boundary_size)

        # Motif Control Widgets
        self.clear_sketch_btn = QPushButton("Clear All")
        self.finish_shape_btn = QPushButton("Finish Shape")
        self.element_label = QLabel("No elements selected.")
        self.shift_u_spin = QDoubleSpinBox(); self.shift_u_spin.setRange(-1.0, 1.0); self.shift_u_spin.setDecimals(2); self.shift_u_spin.setValue(0.50)
        self.shift_v_spin = QDoubleSpinBox(); self.shift_v_spin.setRange(-1.0, 1.0); self.shift_v_spin.setDecimals(2); self.shift_v_spin.setValue(0.00)
        self.row_spacing_spin = QDoubleSpinBox(); self.row_spacing_spin.setRange(0.05, 5.0); self.row_spacing_spin.setDecimals(2); self.row_spacing_spin.setValue(1.00)
        self.col_spacing_spin = QDoubleSpinBox(); self.col_spacing_spin.setRange(0.05, 5.0); self.col_spacing_spin.setDecimals(2); self.col_spacing_spin.setValue(1.00)
        self.delete_surface_chk = QCheckBox("Delete Surface"); self.delete_surface_chk.setChecked(True)

        # Main Action Button
        self.place_btn = QPushButton("Place")

        # Design Manager
        self.design_manager = DesignManagerWidget(main_dialog=self)

        # --- LAYOUT ---
        main_layout = QVBoxLayout(self)

        # --- Top Section ---
        top_layout = QHBoxLayout()

        # Top-Left Area (Grid and Output)
        top_left_layout = QVBoxLayout()

        grid_group = QGroupBox("Grid Spacing")
        grid_form = QFormLayout(grid_group)
        grid_form.addRow("Row Divisions (U):", self.u_spin)
        grid_form.addRow("Column Divisions (V):", self.v_spin)  # Renamed here
        grid_form.addRow("Sketch Grid Rows (U):", self.sketch_grid_u_spin)
        grid_form.addRow("Sketch Grid Columns (V):", self.sketch_grid_v_spin)  # Renamed here
        top_left_layout.addWidget(grid_group)

        output_group = QGroupBox("Output Options")
        output_layout = QGridLayout(output_group)
        output_layout.addWidget(self.points_chk, 0, 0)
        output_layout.addWidget(self.shapes_chk, 0, 1)
        output_layout.addWidget(self.solid_chk, 0, 2)
        output_layout.addWidget(self.start_end_chk, 1, 0)
        output_layout.addWidget(self.keep_planar_chk, 1, 1)
        thickness_layout = QHBoxLayout()
        thickness_layout.setContentsMargins(0,0,0,0)
        thickness_layout.addWidget(QLabel("Thickness:"))
        thickness_layout.addWidget(self.thickness_spin)
        output_layout.addLayout(thickness_layout, 1, 2)
        top_left_layout.addWidget(output_group)
        top_left_layout.addStretch()

        # Top-Right Area (Saved Designs)
        design_group = QGroupBox("Saved Designs")
        design_layout = QVBoxLayout(design_group)
        design_layout.addWidget(self.design_manager)

        top_layout.addLayout(top_left_layout)
        top_layout.addWidget(design_group)

        main_layout.addLayout(top_layout)

        # --- Middle Section (Preview) ---
        motif_preview_group = QGroupBox("Motif Sketch Preview")
        motif_preview_layout = QHBoxLayout(motif_preview_group)
        motif_preview_layout.addWidget(self.sketch_widget)
        motif_preview_layout.addWidget(self.preview_widget)
        main_layout.addWidget(motif_preview_group)
     
        # PATCH: Add flip_dir_chk to motif_controls_group
        motif_controls_group = QGroupBox("Motif Controls")
        mc_layout = QGridLayout(motif_controls_group)
        mc_layout.addWidget(self.clear_sketch_btn, 0, 0)
        mc_layout.addWidget(self.finish_shape_btn, 1, 0)
        mc_layout.addWidget(QLabel("Shift Row (U):"), 0, 1)
        mc_layout.addWidget(self.shift_u_spin, 0, 2)
        mc_layout.addWidget(QLabel("Shift Column (V):"), 1, 1)
        mc_layout.addWidget(self.shift_v_spin, 1, 2)
        mc_layout.addWidget(QLabel("Row Spacing (U):"), 0, 3)
        mc_layout.addWidget(self.row_spacing_spin, 0, 4)
        mc_layout.addWidget(QLabel("Col Spacing (V):"), 1, 3)
        mc_layout.addWidget(self.col_spacing_spin, 1, 4)
        mc_layout.addWidget(QLabel("Element Selection"), 2, 0)
        mc_layout.addWidget(self.element_label, 2, 1, 1, 3)
        mc_layout.addWidget(self.delete_surface_chk, 2, 4, Qt.AlignRight)
        mc_layout.addWidget(self.flip_dir_chk, 2, 5)  # PATCH: Add to layout
        mc_layout.setColumnStretch(5, 1)
        main_layout = self.layout() if self.layout() else QVBoxLayout(self)
        main_layout.addWidget(motif_controls_group)
        
        # --- Place Button at the very bottom ---
        main_layout.addWidget(self.place_btn)

        # --- CONNECTIONS ---
        self.u_spin.valueChanged.connect(self.update_preview)
        self.v_spin.valueChanged.connect(self.update_preview)
        self.sketch_grid_u_spin.valueChanged.connect(self.on_sketch_grid_changed)
        self.sketch_grid_v_spin.valueChanged.connect(self.on_sketch_grid_changed)
        self.row_spacing_spin.valueChanged.connect(self.update_preview)
        self.col_spacing_spin.valueChanged.connect(self.update_preview)
        self.shift_u_spin.valueChanged.connect(self.update_preview)
        self.shift_v_spin.valueChanged.connect(self.update_preview)
        self.points_chk.stateChanged.connect(self.update_preview)
        self.shapes_chk.stateChanged.connect(self.update_preview)
        self.solid_chk.stateChanged.connect(self.thickness_spin.setEnabled)
        self.solid_chk.stateChanged.connect(self.update_preview)
        self.keep_planar_chk.stateChanged.connect(self.update_preview)
        self.start_end_chk.stateChanged.connect(self.on_start_end_pieces_changed)
        self.place_btn.clicked.connect(self.on_place)
        self.clear_sketch_btn.clicked.connect(self.clear_sketch)
        self.finish_shape_btn.clicked.connect(self.finish_shape)
        self.design_manager.design_selected.connect(self.load_design)

        # --- Timer for element selection info ---
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_surface_count)
        self.timer.start(500)
        self.update_surface_count()
        self.update_preview()

    def on_start_end_pieces_changed(self, state):
        self.preview_widget.set_show_end_pieces(self.start_end_chk.isChecked())
        self.update_preview()

    def get_current_design(self):
        return {
            'u': self.u_spin.value(),
            'v': self.v_spin.value(),
            'sketch_grid_u': self.sketch_grid_u_spin.value(),
            'sketch_grid_v': self.sketch_grid_v_spin.value(),
            'row_spacing': self.row_spacing_spin.value(),
            'col_spacing': self.col_spacing_spin.value(),
            'shift_u': self.shift_u_spin.value(),
            'shift_v': self.shift_v_spin.value(),
            'keep_planar': self.keep_planar_chk.isChecked(),
            'thickness': self.thickness_spin.value(),
            'place_points': self.points_chk.isChecked(),
            'place_shape': self.shapes_chk.isChecked(),
            'place_solid': self.solid_chk.isChecked(),
            'delete_surface': self.delete_surface_chk.isChecked(),
            'motif_shapes': self.sketch_widget.get_all_shapes(),
            'start_end_pieces': self.start_end_chk.isChecked(),
            'flip_direction': self.flip_dir_chk.isChecked(),  # PATCH: Save flip direction
        }

    def load_design(self, design):
        self.u_spin.setValue(design.get('u', 15))
        self.v_spin.setValue(design.get('v', 15))
        self.sketch_grid_u_spin.setValue(design.get('sketch_grid_u', 11))
        self.sketch_grid_v_spin.setValue(design.get('sketch_grid_v', 11))
        self.row_spacing_spin.setValue(design.get('row_spacing', 1.0))
        self.col_spacing_spin.setValue(design.get('col_spacing', 1.0))
        self.shift_u_spin.setValue(design.get('shift_u', 0.0))
        self.shift_v_spin.setValue(design.get('shift_v', 0.0))
        self.keep_planar_chk.setChecked(design.get('keep_planar', False))
        self.thickness_spin.setValue(design.get('thickness', 1))
        self.points_chk.setChecked(design.get('place_points', False))
        self.shapes_chk.setChecked(design.get('place_shape', True))
        self.solid_chk.setChecked(design.get('place_solid', False))
        self.delete_surface_chk.setChecked(design.get('delete_surface', False))
        self.start_end_chk.setChecked(design.get('start_end_pieces', False))
        self.flip_dir_chk.setChecked(design.get('flip_direction', False))  # PATCH: Load flip direction
        motif_shapes = design.get('motif_shapes', [])
        self.sketch_widget.shapes = [list(shape) for shape in motif_shapes]
        self.sketch_widget.current_shape = []
        self.sketch_widget.update()
        self.update_preview()

    def on_sketch_grid_changed(self, value):
        u = self.sketch_grid_u_spin.value()
        v = self.sketch_grid_v_spin.value()
        self.sketch_widget.set_grid_size(u, v)
        self.sketch_widget.set_boundary_size(self.boundary_size)
        self.preview_widget.set_boundary_size(self.boundary_size)
        self.update_preview()

    def update_preview(self):
        shift_u = self.shift_u_spin.value()
        shift_v = self.shift_v_spin.value()
        row_spacing = self.row_spacing_spin.value()
        col_spacing = self.col_spacing_spin.value()
        motif_shapes = self.sketch_widget.get_all_shapes()
        grid_size_u = self.sketch_widget.grid_size_u
        grid_size_v = self.sketch_widget.grid_size_v
        self.preview_widget.set_shifts(
            shift_u, shift_v, row_spacing, col_spacing,
            motif_shapes=motif_shapes,
            grid_size_u=grid_size_u,
            grid_size_v=grid_size_v
        )

    def clear_sketch(self):
        self.sketch_widget.clear_all()
        self.update_preview()

    def finish_shape(self):
        self.sketch_widget.finish_shape_button()
        self.update_preview()

    def get_selected_element_ids(self):
        """
        Return a list of currently selected element IDs from the MicroStation selection set.
        """
        try:
            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
            dgnModel = ACTIVEMODEL.GetDgnModel()
            sel_mgr = SelectionSetManager.GetManager()
            agenda = ElementAgenda()
            sel_mgr.BuildAgenda(agenda)
            ids = []
            for idx in range(agenda.GetCount()):
                eeh = agenda.GetEntry(idx)
                # Only accept graphical elements (optional: filter by type)
                msElement = eeh.GetElement()
                if msElement.ehdr.isGraphics and not msElement.hdr.dhdr.props.b.invisible:
                    ids.append(eeh.ElementId)
            return ids
        except Exception as ex:
            show_error_dialog("Failed to get selected elements.", str(ex))
            return []

    def update_surface_count(self):
        try:
            ids = self.get_selected_element_ids()
            if ids:
                self.element_label.setText(f"{len(ids)} element(s) selected.")
            else:
                self.element_label.setText("No elements selected.")
        except Exception as ex:
            show_error_dialog("Failed to update surface count.", str(ex))

    def on_place(self):
        """
        Slot for the Place button. Collects user input, validates, and places geometry on selected surfaces.
        """
        try:
            # Get user settings from the dialog
            u = self.u_spin.value()
            v = self.v_spin.value()
            ids = self.get_selected_element_ids()
            if not ids:
                from PyQt5.QtWidgets import QMessageBox
                QMessageBox.critical(self, "No Elements Selected", "Please select at least one element using the selection tool, then click Place.")
                return

            all_shapes = self.sketch_widget.get_all_shapes()
            if not all_shapes or all(len(shape) < 3 for shape in all_shapes):
                from PyQt5.QtWidgets import QMessageBox
                QMessageBox.critical(self, "Sketch Error", "Please sketch at least one polygon with at least 3 points.")
                return

            grid_size_u = self.sketch_widget.grid_size_u
            grid_size_v = self.sketch_widget.grid_size_v
            all_polygon_uv = []
            for shape in all_shapes:
                shape_uv = []
                for idx in shape:
                    i = idx // grid_size_v
                    j = idx % grid_size_v
                    shape_uv.append((i, j))
                all_polygon_uv.append(shape_uv)

            keep_planar = self.keep_planar_chk.isChecked()
            shift_u_val = self.shift_u_spin.value()
            shift_v_val = self.shift_v_spin.value()
            row_spacing = self.row_spacing_spin.value()
            col_spacing = self.col_spacing_spin.value()
            start_end_pieces = self.start_end_chk.isChecked()

            # Call the placement function
            flip_direction = self.flip_dir_chk.isChecked()  # PATCH: Get flip direction
            place_points_and_polygons_cellmotif_on_surface(
                num_u=u,
                num_v=v,
                place_points=self.points_chk.isChecked(),
                place_shape=self.shapes_chk.isChecked(),
                make_solid=self.solid_chk.isChecked(),
                thickness=self.thickness_spin.value(),
                surface_ids=ids,
                delete_surface=self.delete_surface_chk.isChecked(),
                all_polygon_uv=all_polygon_uv,
                keep_planar=keep_planar,
                shift_u_val=shift_u_val,
                shift_v_val=shift_v_val,
                sketch_grid_size_u=grid_size_u,
                sketch_grid_size_v=grid_size_v,
                row_spacing=row_spacing,
                col_spacing=col_spacing,
                start_end_pieces=start_end_pieces,
                flip_direction=flip_direction,  # PATCH: Pass to function
            )
            # Dialog remains open after placing
        except Exception as ex:
            show_error_dialog("Error in Place operation.", traceback.format_exc())

    def closeEvent(self, event):
        if hasattr(sys, "_surface_grid_dialog"):
            sys._surface_grid_dialog = None
        super().closeEvent(event)

def is_dialog_valid(dlg):
    try:
        if dlg is None:
            return False
        _ = dlg.isVisible()
    except Exception:
        return False
    return True

def place_points_and_polygons_cellmotif_on_surface(
    num_u=10, num_v=10, place_points=False, place_shape=True, make_solid=False, thickness=1.0, surface_ids=None, delete_surface=False,
    all_polygon_uv=None, keep_planar=False, shift_u_val=0.0, shift_v_val=0.0, sketch_grid_size_u=11, sketch_grid_size_v=11,
    row_spacing=1.0, col_spacing=1.0, start_end_pieces=False, flip_direction=False
):
    def sutherland_hodgman_clip(polygon, clip_rect):
        def inside(p, edge):
            u, v = p
            if edge == 0: return u >= clip_rect[0]  # left
            if edge == 1: return u <= clip_rect[1]  # right
            if edge == 2: return v >= clip_rect[2]  # bottom
            if edge == 3: return v <= clip_rect[3]  # top

        def intersect(p1, p2, edge):
            u1, v1 = p1
            u2, v2 = p2
            if edge == 0:  # left
                u = clip_rect[0]
                v = v1 + (v2 - v1) * (clip_rect[0] - u1) / (u2 - u1) if u2 != u1 else v1
                return (u, v)
            if edge == 1:  # right
                u = clip_rect[1]
                v = v1 + (v2 - v1) * (clip_rect[1] - u1) / (u2 - u1) if u2 != u1 else v1
                return (u, v)
            if edge == 2:  # bottom
                v = clip_rect[2]
                u = u1 + (u2 - u1) * (clip_rect[2] - v1) / (v2 - v1) if v2 != v1 else u1
                return (u, v)
            if edge == 3:  # top
                v = clip_rect[3]
                u = u1 + (u2 - u1) * (clip_rect[3] - v1) / (v2 - v1) if v2 != v1 else u1
                return (u, v)

        output = polygon
        for edge in range(4):
            input_list = output
            output = []
            if not input_list:
                break
            s = input_list[-1]
            for e in input_list:
                if inside(e, edge):
                    if not inside(s, edge):
                        output.append(intersect(s, e, edge))
                    output.append(e)
                elif inside(s, edge):
                    output.append(intersect(s, e, edge))
                s = e
        return output

    def best_fit_plane(points):
        import numpy as np
        pts = np.array([[p.x, p.y, p.z] for p in points if p is not None])
        if pts.shape[0] < 3:
            return None, None
        centroid = pts.mean(axis=0)
        uu, dd, vv = np.linalg.svd(pts - centroid)
        normal = vv[2, :]
        return DPoint3d(*centroid), DVec3d(*normal)

    def ensure_consistent_normal(normal, reference_normal):
        if normal.DotProduct(reference_normal) < 0:
            normal.Negate()
        return normal

    try:
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        if dgnModel is None:
            MessageCenter.ShowErrorMessage("No active DGN model.", "", False)
            return

        modelInfo = dgnModel.GetModelInfo()
        __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)
        thickness_uor = thickness * uorPerMast

        ids = surface_ids if surface_ids else []
        if not ids:
            MessageCenter.ShowErrorMessage("No surface element selected.", "", False)
            return

        total_points = 0
        total_polys = 0
        total_solids = 0
        for elem_id in ids:
            reference_normal = None  # <-- START: Set reference_normal to None ONCE per surface
            try:
                eeh = EditElementHandle(elem_id, dgnModel)
                elem_type = eeh.GetElementType()

                # --- BSpline Surface ---
                if elem_type == MSElementTypes.eBSPLINE_SURFACE_ELM:
                    surf_query = eeh.GetIBsplineSurfaceQuery()
                    if surf_query is None:
                        continue
                    ret = surf_query.GetBsplineSurface(eeh)
                    if ret[0] != BentleyStatus.eSUCCESS:
                        continue
                    surface = ret[1]

                    trim_loops = get_trim_boundaries_uv(surface)
                    if trim_loops and len(trim_loops[0]) > 0:
                        umin = min(u for u, v in trim_loops[0])
                        umax = max(u for u, v in trim_loops[0])
                        vmin = min(v for u, v in trim_loops[0])
                        vmax = max(v for u, v in trim_loops[0])
                    else:
                        umin, umax, vmin, vmax = 0.0, 1.0, 0.0, 1.0
                        
                    tile_size_u = (umax - umin) / num_u
                    tile_size_v = (vmax - vmin) / num_v
                    step_u = tile_size_u * row_spacing
                    step_v = tile_size_v * col_spacing
                    n_tiles_u = int(((umax - umin) - 1e-8 - tile_size_u) / step_u) + 2
                    n_tiles_v = int(((vmax - vmin) - 1e-8 - tile_size_v) / step_v) + 2

                    ref_u = 0.5
                    ref_v = 0.5
                    ref_normal = DVec3d()
                    try:
                        surface.EvaluateNormal(ref_normal, ref_u, ref_v)
                        if ref_normal.Magnitude() == 0:
                            ref_normal = DVec3d(0, 0, 1)
                        else:
                            ref_normal.Normalize()
                    except Exception:
                        ref_normal = DVec3d(0, 0, 1)

                    tile_size_u = (umax - umin) / num_u
                    tile_size_v = (vmax - vmin) / num_v
                    step_u = tile_size_u * row_spacing
                    step_v = tile_size_v * col_spacing
                    n_tiles_u = int(((umax - umin) - 1e-8 - tile_size_u) / step_u) + 2
                    n_tiles_v = int(((vmax - vmin) - 1e-8 - tile_size_v) / step_v) + 2

                    filled_tiles = set()
                    num_points_placed = 0
                    num_polys_placed = 0
                    num_solids_placed = 0

                    # Place points
                    if place_points:
                        for i in range(-1, n_tiles_u+2):
                            u = umin + (i + 0.5) * tile_size_u
                            for j in range(-1, n_tiles_v+2):
                                v = vmin + (j + 0.5) * tile_size_v
                                # Only place if inside trim
                                if trim_loops:
                                    if not point_in_polygon((u, v), trim_loops[0]):
                                        print("SKIP: point outside trim", u, v)
                                        skip = True
                                        continue
                                    skip = False
                                    if trim_loops:
                                        if not point_in_polygon((u, v), trim_loops[0]):
                                            print("SKIP: point outside trim", u, v)
                                            skip = True
                                            continue
                                        for hole in trim_loops[1:]:
                                            if point_in_polygon((u, v), hole):
                                                print("SKIP: point in hole", u, v)
                                                skip = True
                                                break
                                    if skip:
                                        continue
                                pt = DPoint3d()
                                try:
                                    eval_success = surface.EvaluatePoint(pt, u, v)
                                except Exception as ex:
                                    eval_success = -1
                                if eval_success is None:
                                    try:
                                        eeh_pt = EditElementHandle()
                                        status = DraftingElementSchema.ToElement(
                                            eeh_pt,
                                            ICurvePrimitive.CreateLine(DSegment3d(pt, pt)),
                                            None,
                                            dgnModel.Is3d(),
                                            dgnModel
                                        )
                                        if BentleyStatus.eSUCCESS == status:
                                            ElementPropertyUtils.ApplyActiveSettings(eeh_pt)
                                            eeh_pt.AddToModel()
                                            num_points_placed += 1
                                    except Exception as ex:
                                        MessageCenter.ShowErrorMessage("Failed to place point.", str(ex), False)

                    # Place polygons/solids using motif logic (including start/end pieces)
                    if all_polygon_uv and len(all_polygon_uv) > 0:
                        for polygon_uv in all_polygon_uv:
                            if len(polygon_uv) < 3:
                                continue
                            motif_pts_uv = []
                            for ui, vi in polygon_uv:
                                motif_u = ui / float(sketch_grid_size_u - 1) if sketch_grid_size_u > 1 else 0.0
                                motif_v = vi / float(sketch_grid_size_v - 1) if sketch_grid_size_v > 1 else 0.0
                                motif_pts_uv.append((motif_u, motif_v))

                            for i in range(-1, n_tiles_u+2):
                                tile_origin_u = umin + i * step_u
                                for j in range(-1, n_tiles_v+2):
                                    tile_origin_v = vmin + j * step_v
                                    shift_u = shift_u_val * tile_size_u if (j % 2 == 1) else 0.0
                                    shift_v = shift_v_val * tile_size_v if (i % 2 == 1) else 0.0
                                    tile_u = tile_origin_u + shift_u
                                    tile_v = tile_origin_v + shift_v

                                    motif_poly = []
                                    for motif_u, motif_v in motif_pts_uv:
                                        u = tile_u + motif_u * tile_size_u
                                        v = tile_v + motif_v * tile_size_v
                                        motif_poly.append((u, v))
                                    # Always clip, so we get both main and start/end pieces
                                    clipped_uvs = sutherland_hodgman_clip(motif_poly, (umin, umax, vmin, vmax))
                                    if len(clipped_uvs) >= 3:
                                        if trim_loops:
                                             if not polygon_inside_trims(clipped_uvs, trim_loops):
                                                 print("SKIP: motif outside trim", clipped_uvs)
                                                 continue
                                        poly_pts = []
                                        for u, v in clipped_uvs:
                                            pt = DPoint3d()
                                            try:
                                                eval_success = surface.EvaluatePoint(pt, u, v)
                                            except Exception as ex:
                                                eval_success = -1
                                            if eval_success is None:
                                                poly_pts.append(DPoint3d(pt.x, pt.y, pt.z))
                                                
                                        if not is_valid_polygon(poly_pts):
                                            continue  # Skip degenerate/slither polygons
                                                
                                        if keep_planar:
                                                origin, normal = best_fit_plane(poly_pts)
                                                if normal is None or normal.Magnitude() == 0:
                                                    normal = DVec3d(0, 0, 1)
                                                else:
                                                    normal.Normalize()
                                                for idx, pt in enumerate(poly_pts):
                                                    vec = DVec3d(pt.x - origin.x, pt.y - origin.y, pt.z - origin.z)
                                                    dist = vec.DotProduct(normal)
                                                    poly_pts[idx] = DPoint3d(pt.x - dist * normal.x, pt.y - dist * normal.y, pt.z - dist * normal.z)
                                        dptarr = DPoint3dArray()
                                        for pt in poly_pts:
                                            dptarr.append(pt)
                                        if place_shape:
                                            try:
                                                eeh_poly = EditElementHandle()
                                                status = ShapeHandler.CreateShapeElement(
                                                    eeh_poly, None, dptarr, dgnModel.Is3d(), dgnModel
                                                )
                                                if BentleyStatus.eSUCCESS == status:
                                                    ElementPropertyUtils.ApplyActiveSettings(eeh_poly)
                                                    eeh_poly.AddToModel()
                                                    num_polys_placed += 1
                                            except Exception as ex:
                                                MessageCenter.ShowErrorMessage("Failed to place polygon.", str(ex), False)

                                        if make_solid:
                                            try:
                                                # Ensure motif polygon winding is consistent (CCW in UV)
                                                clipped_uvs, poly_pts = ensure_ccw_uv_order(clipped_uvs, poly_pts)

                                                # Compute best-fit plane for the motif polygon
                                                plane_origin, plane_normal = best_fit_plane(poly_pts)
                                                if plane_normal is None or plane_normal.Magnitude() == 0:
                                                    continue  # Skip degenerate polygons (area 0 or collinear)
                                                plane_normal.Normalize()

                                                # Project all points onto the best-fit plane (keeps the motif planar)
                                                projected_pts = []
                                                for pt in poly_pts:
                                                    vec = DVec3d(pt.x - plane_origin.x, pt.y - plane_origin.y, pt.z - plane_origin.z)
                                                    dist = vec.DotProduct(plane_normal)
                                                    projected_pt = DPoint3d(
                                                        pt.x - dist * plane_normal.x,
                                                        pt.y - dist * plane_normal.y,
                                                        pt.z - dist * plane_normal.z
                                                    )
                                                    projected_pts.append(projected_pt)

                                                # --- Area check: skip if area is zero (using robust 2D projection) ---
                                                # Find two orthogonal axes in the plane
                                                import numpy as np
                                                nvec = np.array([plane_normal.x, plane_normal.y, plane_normal.z])
                                                nvec = nvec / np.linalg.norm(nvec)
                                                ref = np.array([1.0, 0.0, 0.0]) if abs(nvec[0]) < 0.9 else np.array([0.0, 1.0, 0.0])
                                                u_axis = np.cross(nvec, ref)
                                                u_axis = u_axis / np.linalg.norm(u_axis)
                                                v_axis = np.cross(nvec, u_axis)
                                                v_axis = v_axis / np.linalg.norm(v_axis)
                                                pts2d = []
                                                for p in projected_pts:
                                                    vec = np.array([p.x - plane_origin.x, p.y - plane_origin.y, p.z - plane_origin.z])
                                                    u = np.dot(vec, u_axis)
                                                    v = np.dot(vec, v_axis)
                                                    pts2d.append((u, v))
                                                # Shoelace formula
                                                area = 0.0
                                                for i in range(len(pts2d)):
                                                    x0, y0 = pts2d[i]
                                                    x1, y1 = pts2d[(i + 1) % len(pts2d)]
                                                    area += (x0 * y1 - x1 * y0)
                                                area = abs(area) * 0.5
                                                if area < 1e-8:
                                                    continue  # Skip zero-area or sliver shapes

                                                # Build the curve vector from the projected motif polygon
                                                cv = CurveVector(CurveVector.eBOUNDARY_TYPE_Outer)
                                                n = len(projected_pts)
                                                for k in range(n):
                                                    cv.Add(ICurvePrimitive.CreateLine(DSegment3d(projected_pts[k], projected_pts[(k + 1) % n])))

                                                # Compute the "positive" surface normal at the motif tile center
                                                tile_center_u = sum(u for u, v in clipped_uvs) / len(clipped_uvs)
                                                tile_center_v = sum(v for u, v in clipped_uvs) / len(clipped_uvs)
                                                surf_normal = DVec3d()
                                                try:
                                                    if elem_type == MSElementTypes.eBSPLINE_SURFACE_ELM:
                                                        surface.EvaluateNormal(surf_normal, tile_center_u, tile_center_v)
                                                    else:
                                                        uvParam = DPoint2d(tile_center_u, tile_center_v)
                                                        SolidUtil.EvaluateFace(face, DPoint3d(), surf_normal, DVec3d(), DVec3d(), uvParam)
                                                except Exception:
                                                    surf_normal = DVec3d(0, 0, 1)
                                                if surf_normal.Magnitude() == 0:
                                                    surf_normal = DVec3d(0, 0, 1)
                                                else:
                                                    surf_normal.Normalize()
                                                if flip_direction:
                                                    surf_normal.Negate()

                                                # Ensure the extrusion direction is consistent with the surface's positive side
                                                dot = surf_normal.DotProduct(plane_normal)
                                                if dot < 0:
                                                    plane_normal.Negate()

                                                # Extrude in the direction of the (possibly flipped) best-fit plane normal
                                                extrude_vec = DVec3d(
                                                    plane_normal.x * thickness_uor,
                                                    plane_normal.y * thickness_uor,
                                                    plane_normal.z * thickness_uor
                                                )

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
                                                else:
                                                    MessageCenter.ShowErrorMessage("Failed to create solid element.", f"Status: {status}", False)
                                            except Exception as ex:
                                                MessageCenter.ShowErrorMessage("Failed to place solid.", str(ex), False)
            
                    total_points += num_points_placed
                    total_polys += num_polys_placed
                    total_solids += num_solids_placed

                # --- All other surface/solid types ---
                else:
                    body_result = SolidUtil.Convert.ElementToBody(eeh, True, True, False)
                    if body_result[0] == BentleyStatus.eSUCCESS and body_result[1] is not None:
                        body = body_result[1]
                        sub_face_array = ISubEntityPtrArray()
                        num_faces = SolidUtil.GetBodyFaces(sub_face_array, body)
                        for face_idx in range(num_faces):
                            face = sub_face_array[face_idx]
                            uRange = DRange1d()
                            vRange = DRange1d()
                            status = SolidUtil.GetFaceParameterRange(face, uRange, vRange)
                            if status != BentleyStatus.eSUCCESS:
                                continue

                            u_min, u_max = uRange.Low(), uRange.High()
                            v_min, v_max = vRange.Low(), vRange.High()

                            tile_size_u = (u_max - u_min) / num_u
                            tile_size_v = (v_max - v_min) / num_v
                            step_u = tile_size_u * row_spacing
                            step_v = tile_size_v * col_spacing
                            n_tiles_u = int(((u_max - u_min) - 1e-8 - tile_size_u) / step_u) + 2
                            n_tiles_v = int(((v_max - v_min) - 1e-8 - tile_size_v) / step_v) + 2

                            for polygon_uv in (all_polygon_uv or []):
                                if len(polygon_uv) < 3:
                                    continue
                                motif_pts_uv = []
                                for ui, vi in polygon_uv:
                                    motif_u = ui / float(sketch_grid_size_u - 1) if sketch_grid_size_u > 1 else 0.0
                                    motif_v = vi / float(sketch_grid_size_v - 1) if sketch_grid_size_v > 1 else 0.0
                                    motif_pts_uv.append((motif_u, motif_v))

                                for i in range(-1, n_tiles_u+2):
                                    tile_origin_u = u_min + i * step_u
                                    for j in range(-1, n_tiles_v+2):
                                        tile_origin_v = v_min + j * step_v
                                        shift_u = shift_u_val * tile_size_u if (j % 2 == 1) else 0.0
                                        shift_v = shift_v_val * tile_size_v if (i % 2 == 1) else 0.0
                                        tile_u = tile_origin_u + shift_u
                                        tile_v = tile_origin_v + shift_v

                                        motif_poly = []
                                        for motif_u, motif_v in motif_pts_uv:
                                            u = tile_u + motif_u * tile_size_u
                                            v = tile_v + motif_v * tile_size_v
                                            motif_poly.append((u, v))
                                        # Always clip to face UV range
                                        clipped_uvs = sutherland_hodgman_clip(motif_poly, (u_min, u_max, v_min, v_max))
                                        if len(clipped_uvs) < 3:
                                            continue

                                        poly_pts = []
                                        for u, v in clipped_uvs:
                                            pt = DPoint3d()
                                            normal = DVec3d()
                                            uDir = DVec3d()
                                            vDir = DVec3d()
                                            uvParam = DPoint2d(u, v)
                                            status_eval = SolidUtil.EvaluateFace(face, pt, normal, uDir, vDir, uvParam)
                                            if status_eval == BentleyStatus.eSUCCESS:
                                                poly_pts.append(DPoint3d(pt.x, pt.y, pt.z))

                                        if not is_valid_polygon(poly_pts):
                                            continue  # Skip degenerate/slither polygons

                                        # Planarize if needed
                                        if keep_planar:
                                            origin, normal = best_fit_plane(poly_pts)
                                            if normal is None or normal.Magnitude() == 0:
                                                normal = DVec3d(0, 0, 1)
                                            else:
                                                normal.Normalize()
                                            for idx, pt in enumerate(poly_pts):
                                                vec = DVec3d(pt.x - origin.x, pt.y - origin.y, pt.z - origin.z)
                                                dist = vec.DotProduct(normal)
                                                poly_pts[idx] = DPoint3d(pt.x - dist * normal.x, pt.y - dist * normal.y, pt.z - dist * normal.z)

                                        dptarr = DPoint3dArray()
                                        for pt in poly_pts:
                                            dptarr.append(pt)

                                        if place_shape:
                                            try:
                                                eeh_poly = EditElementHandle()
                                                status = ShapeHandler.CreateShapeElement(
                                                    eeh_poly, None, dptarr, dgnModel.Is3d(), dgnModel
                                                )
                                                if BentleyStatus.eSUCCESS == status:
                                                    ElementPropertyUtils.ApplyActiveSettings(eeh_poly)
                                                    eeh_poly.AddToModel()
                                            except Exception as ex:
                                                MessageCenter.ShowErrorMessage("Failed to place polygon.", str(ex), False)

                                        if make_solid:
                                            try:
                                                # Ensure motif polygon winding is consistent (CCW in UV)
                                                clipped_uvs, poly_pts = ensure_ccw_uv_order(clipped_uvs, poly_pts)
                                                # Compute best-fit plane for the motif polygon
                                                plane_origin, plane_normal = best_fit_plane(poly_pts)
                                                if plane_normal is None or plane_normal.Magnitude() == 0:
                                                    continue  # Skip degenerate polygons (area 0 or collinear)
                                                plane_normal.Normalize()
                                                # Project all points onto the best-fit plane (keeps the motif planar)
                                                projected_pts = []
                                                for pt in poly_pts:
                                                    vec = DVec3d(pt.x - plane_origin.x, pt.y - plane_origin.y, pt.z - plane_origin.z)
                                                    dist = vec.DotProduct(plane_normal)
                                                    projected_pt = DPoint3d(
                                                        pt.x - dist * plane_normal.x,
                                                        pt.y - dist * plane_normal.y,
                                                        pt.z - dist * plane_normal.z
                                                    )
                                                    projected_pts.append(projected_pt)
                                                # Area check (robust 2D projection)
                                                import numpy as np
                                                nvec = np.array([plane_normal.x, plane_normal.y, plane_normal.z])
                                                nvec = nvec / np.linalg.norm(nvec)
                                                ref = np.array([1.0, 0.0, 0.0]) if abs(nvec[0]) < 0.9 else np.array([0.0, 1.0, 0.0])
                                                u_axis = np.cross(nvec, ref)
                                                u_axis = u_axis / np.linalg.norm(u_axis)
                                                v_axis = np.cross(nvec, u_axis)
                                                v_axis = v_axis / np.linalg.norm(v_axis)
                                                pts2d = []
                                                for p in projected_pts:
                                                    vec = np.array([p.x - plane_origin.x, p.y - plane_origin.y, p.z - plane_origin.z])
                                                    u = np.dot(vec, u_axis)
                                                    v = np.dot(vec, v_axis)
                                                    pts2d.append((u, v))
                                                area = 0.0
                                                for i in range(len(pts2d)):
                                                    x0, y0 = pts2d[i]
                                                    x1, y1 = pts2d[(i + 1) % len(pts2d)]
                                                    area += (x0 * y1 - x1 * y0)
                                                area = abs(area) * 0.5
                                                if area < 1e-8:
                                                    continue  # Skip zero-area or sliver shapes

                                                # Build the curve vector from the projected motif polygon
                                                cv = CurveVector(CurveVector.eBOUNDARY_TYPE_Outer)
                                                n = len(projected_pts)
                                                for k in range(n):
                                                    cv.Add(ICurvePrimitive.CreateLine(DSegment3d(projected_pts[k], projected_pts[(k + 1) % n])))

                                                # Compute the "positive" surface normal at the motif tile center
                                                tile_center_u = sum(u for u, v in clipped_uvs) / len(clipped_uvs)
                                                tile_center_v = sum(v for u, v in clipped_uvs) / len(clipped_uvs)
                                                surf_normal = DVec3d()
                                                uvParam = DPoint2d(tile_center_u, tile_center_v)
                                                SolidUtil.EvaluateFace(face, DPoint3d(), surf_normal, DVec3d(), DVec3d(), uvParam)
                                                if surf_normal.Magnitude() == 0:
                                                    surf_normal = DVec3d(0, 0, 1)
                                                else:
                                                    surf_normal.Normalize()
                                                if flip_direction:
                                                    surf_normal.Negate()
                                                dot = surf_normal.DotProduct(plane_normal)
                                                if dot < 0:
                                                    plane_normal.Negate()

                                                # Extrude in the direction of the (possibly flipped) best-fit plane normal
                                                extrude_vec = DVec3d(
                                                    plane_normal.x * thickness_uor,
                                                    plane_normal.y * thickness_uor,
                                                    plane_normal.z * thickness_uor
                                                )

                                                extrude_detail = DgnExtrusionDetail(cv, extrude_vec, True)
                                                solid_prim = ISolidPrimitive.CreateDgnExtrusion(extrude_detail)
                                                eeh_solid = EditElementHandle()
                                                status = DraftingElementSchema.ToElement(
                                                    eeh_solid, solid_prim, None, dgnModel
                                                )
                                                if BentleyStatus.eSUCCESS == status:
                                                    ElementPropertyUtils.ApplyActiveSettings(eeh_solid)
                                                    eeh_solid.AddToModel()
                                                else:
                                                    MessageCenter.ShowErrorMessage("Failed to create solid element.", f"Status: {status}", False)
                                            except Exception as ex:
                                                MessageCenter.ShowErrorMessage("Failed to place solid.", str(ex), False)


                            total_points += num_points_placed
                            total_polys += num_polys_placed
                            total_solids += num_solids_placed

                    else:
                        continue

                if delete_surface:
                    try:
                        eeh.DeleteFromModel()
                    except Exception as ex:
                        MessageCenter.ShowErrorMessage("Failed to delete surface.", str(ex), False)

            except Exception as ex:
                MessageCenter.ShowErrorMessage("Error processing surface element.", str(ex), False)

        MessageCenter.ShowInfoMessage(
            f"Placed {total_points if place_points else 0} points, "
            f"{total_polys if place_shape else 0} polygons, "
            f"{total_solids if make_solid else 0} solids on surface(s).", "", False
        )
    except Exception as ex:
        MessageCenter.ShowErrorMessage("Unexpected error in placing geometry.", str(ex), False)

def show_surface_grid_dialog():
    import sip
    if not hasattr(sys, "_surface_grid_app"):
        sys._surface_grid_app = None
    if not hasattr(sys, "_surface_grid_dialog"):
        sys._surface_grid_dialog = None
    if sys._surface_grid_app is None:
        sys._surface_grid_app = QApplication.instance()
        if sys._surface_grid_app is None:
            sys._surface_grid_app = QApplication(sys.argv)
    dlg = getattr(sys, "_surface_grid_dialog", None)
    try:
        if dlg is not None and sip.isdeleted(dlg):
            dlg = None
    except Exception:
        dlg = None
    if dlg is None:
        dlg = SurfaceGridDialog()
        sys._surface_grid_dialog = dlg
    dlg.show()
    dlg.raise_()
    dlg.activateWindow()
    def keep_alive():
        try:
            if is_dialog_valid(sys._surface_grid_dialog) and sys._surface_grid_dialog.isVisible():
                QApplication.processEvents()
                QTimer.singleShot(100, keep_alive)
        except Exception:
            pass
    QTimer.singleShot(100, keep_alive)

show_surface_grid_dialog()




