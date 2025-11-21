"""
MicroStation Sphere Gravity Player

This script provides an interactive PyQt5 dialog for simulating gravity-driven sphere animation within a MicroStation DGN model.
It allows users to control gravity, bounce, rolling, number of spheres, sphere sizes, drop height, and other simulation parameters.
Spheres are created as DgnSphere solids in the active model and animated with basic physics, including collision detection with
other spheres and static solids in the model. The script supports frame-by-frame stepping, real-time animation, and various
customization options.

"""


from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import sys
import random
from PyQt5.QtWidgets import (
    QApplication, QDialog, QVBoxLayout, QPushButton, QSlider, QLabel, QHBoxLayout, QGridLayout, QCheckBox
)
from PyQt5.QtCore import QTimer, Qt
import math

_sphere_anim_dialog = None

def get_solid_bodies_from_model(exclude_ids=None):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    solids = []
    for elemRef in dgnModel.GetGraphicElements():
        eeh = EditElementHandle(elemRef, dgnModel)
        if not eeh.IsValid():
            continue
        elem_id = eeh.GetElementId()
        if exclude_ids and elem_id in exclude_ids:
            continue
        status, body = SolidUtil.Convert.ElementToBody(eeh, True, True, False)
        if status == BentleyStatus.eSUCCESS and body is not None:
            primitive_query = eeh.GetISolidPrimitiveQuery()
            if primitive_query is not None:
                result = primitive_query.GetSolidPrimitive(eeh)
                if result and isinstance(result, tuple) and len(result) == 2 and result[0]:
                    solid_primitive = result[1]
                    solid_type = solid_primitive.GetSolidPrimitiveType()
                    if solid_type in [
                        SolidPrimitiveType.eSolidPrimitiveType_DgnBox,
                        SolidPrimitiveType.eSolidPrimitiveType_DgnSphere,
                        SolidPrimitiveType.eSolidPrimitiveType_DgnCone,
                        SolidPrimitiveType.eSolidPrimitiveType_DgnTorusPipe,
                        SolidPrimitiveType.eSolidPrimitiveType_DgnExtrusion,
                        SolidPrimitiveType.eSolidPrimitiveType_DgnRotationalSweep,
                        SolidPrimitiveType.eSolidPrimitiveType_DgnRuledSweep,
                    ]:
                        bbox = DRange3d()
                        if SolidUtil.GetEntityRange(bbox, body) == BentleyStatus.eSUCCESS:
                            solids.append((body, bbox.low, bbox.high, elem_id, True))
    return solids

def get_all_bspline_surfaces(model):
    surfaces = []
    for elemRef in model.GetGraphicElements():
        eeh = EditElementHandle(elemRef, model)
        elem = eeh.GetElement()
        if not hasattr(elem, "bspline_surface"):
            continue
        handler = eeh.GetHandler()
        if handler is None:
            continue
        if type(handler).__name__ != "BSplineSurfaceHandler":
            continue
        res = handler.GetBsplineSurface(eeh)
        if not (isinstance(res, tuple) and len(res) == 2):
            continue
        status, surface = res
        if status != BentleyStatus.eSUCCESS:
            continue
        bbox = DRange3d()
        try:
            surface.GetRange(bbox)
        except Exception:
            bbox = None
        surfaces.append((eeh, surface, bbox))
    return surfaces

def ensure_body(body_or_elem):
    if isinstance(body_or_elem, ISolidKernelEntity):
        return body_or_elem
    elif isinstance(body_or_elem, EditElementHandle):
        body = ISolidKernelEntity()
        status = SolidUtil.Create.BodyFromElement(body, body_or_elem)
        if status == BentleyStatus.eSUCCESS:
            return body
        else:
            return None
    else:
        return None

def ray_cast_sphere_collision(sphere_pos_uor, sphere_radius_uor, body):
    try:
        if hasattr(SolidUtil, "IntersectRay"):
            ray_origin = DPoint3d(sphere_pos_uor.x, sphere_pos_uor.y, sphere_pos_uor.z)
            ray_direction = DVec3d(0, 0, -1)
            ray = DRay3d(ray_origin, ray_direction)
            pickData = SolidLocationDetailArray()
            status = SolidUtil.IntersectRay(body, ray, pickData)
            if status == BentleyStatus.eSUCCESS and len(pickData) > 0:
                min_dist = None
                closest_detail = None
                for detail in pickData:
                    intersection_point = detail.GetXYZ()
                    dz = ray_origin.z - intersection_point.z
                    if dz >= 0 and dz <= sphere_radius_uor:
                        if min_dist is None or dz < min_dist:
                            min_dist = dz
                            closest_detail = detail
                if closest_detail is not None:
                    intersection_point = closest_detail.GetXYZ()
                    normal = closest_detail.GetNormal()
                    penetration = sphere_radius_uor - min_dist
                    return True, normal, penetration, intersection_point
    except Exception:
        pass
    return False, None, None, None

def robust_sphere_body_collision(sphere_pos, sphere_radius, body, bbox_min, bbox_max, uorPerMast, is_brep):
    sphere_pos_uor = DPoint3d(sphere_pos.x, sphere_pos.y, sphere_pos.z)
    sphere_pos_uor.Scale(uorPerMast)
    sphere_radius_uor = sphere_radius * uorPerMast

    body_for_closest = ensure_body(body)

    if is_brep and body_for_closest is not None:
        result = SolidUtil.ClosestPoint(body_for_closest, sphere_pos_uor)
        if (
            result is not None
            and isinstance(result, tuple)
            and len(result) == 4
            and result[0]
        ):
            cp = result[1]
            normal = result[2]
            dist = result[3]
            if dist < sphere_radius_uor:
                penetration = sphere_radius_uor - dist
                if hasattr(normal, "Normalize") and normal.Magnitude() > 1e-8:
                    normal.Normalize()
                else:
                    normal = DVec3d(0, 0, 1)
                return True, normal, penetration / uorPerMast, cp
        else:
            collided, normal, penetration, intersection_point = ray_cast_sphere_collision(sphere_pos_uor, sphere_radius_uor, body_for_closest)
            if collided:
                return True, normal, penetration / uorPerMast, intersection_point

    sx, sy, sz = sphere_pos_uor.x, sphere_pos_uor.y, sphere_pos_uor.z
    closest_x = min(max(sx, bbox_min.x), bbox_max.x)
    closest_y = min(max(sy, bbox_min.y), bbox_max.y)
    closest_z = min(max(sz, bbox_min.z), bbox_max.z)
    dx = sx - closest_x
    dy = sy - closest_y
    dz = sz - closest_z
    dist_sq = dx*dx + dy*dy + dz*dz
    if dist_sq < sphere_radius_uor * sphere_radius_uor:
        dist = math.sqrt(dist_sq) if dist_sq > 1e-8 else 1.0
        penetration = sphere_radius_uor - dist
        normal = DVec3d(dx / dist, dy / dist, dz / dist) if dist > 1e-8 else DVec3d(0, 0, 1)
        return True, normal, penetration / uorPerMast, DPoint3d(closest_x, closest_y, closest_z)
    return False, None, None, None

def vertical_project_point_onto_surface(pt, surface, u_steps=50, v_steps=50, xy_tol=1000):
    try:
        umin = surface.GetUMin()
        umax = surface.GetUMax()
        vmin = surface.GetVMin()
        vmax = surface.GetVMax()
    except AttributeError:
        umin, umax, vmin, vmax = 0.0, 1.0, 0.0, 1.0
    best_uv = None
    best_xyz = None
    best_dist = None
    for i in range(u_steps+1):
        u = umin + (umax-umin)*i/u_steps
        for j in range(v_steps+1):
            v = vmin + (vmax-vmin)*j/v_steps
            xyz = DPoint3d()
            surface.EvaluatePoint(xyz, u, v)
            dist = math.hypot(xyz.x - pt.x, xyz.y - pt.y)
            if dist < xy_tol:
                if best_dist is None or abs(xyz.z - pt.z) < abs(best_xyz.z - pt.z):
                    best_uv = DPoint2d(u, v)
                    best_xyz = DPoint3d(xyz.x, xyz.y, xyz.z)
                    best_dist = dist
    if best_xyz is not None:
        return best_xyz, best_uv
    else:
        return None, None

def robust_sphere_surface_collision(sphere_pos, sphere_radius, surface, bbox, uorPerMast):
    pt = DPoint3d(sphere_pos.x, sphere_pos.y, sphere_pos.z)
    proj_pt, uv = vertical_project_point_onto_surface(pt, surface, u_steps=50, v_steps=50, xy_tol=1000)
    if proj_pt is not None:
        dz = pt.z - proj_pt.z
        if abs(dz) < sphere_radius:
            penetration = sphere_radius - abs(dz)
            normal = DVec3d(0, 0, 1 if dz > 0 else -1)
            return True, normal, penetration, proj_pt
    return False, None, None, None

class SphereGravityDialog(QDialog):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("MicroStation Sphere Gravity Player")
        self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
        self.setFixedSize(520, 520)
        self.playing = False
        self.timer = QTimer(self)
        self.animation_speed = 30  # ms per frame
        self.timer.setInterval(self.animation_speed)
        self.timer.timeout.connect(self.on_timer_tick)

        self.gravity = -0.12
        self.bounce_damping = 0.85
        self.floor_z = 0.0
        self.num_spheres = 20
        self.spheres = []
        self.uorPerMast = self._get_uor_per_master()
        self.frames = 0
        self.max_frames = 2000
        self.roll_control = 80
        self.sphere_radius_min = 0.7
        self.sphere_radius_max = 5.0
        self.drop_height = 150

        self.substeps = 4

        self.animated_sphere_ids = set()
        self.ignore_static_collisions = True

        self.frame_by_frame_mode = False
        self.frame_slider = None
        self.max_manual_frames = 1000
        self.manual_frame = 0

        self.xy_spread = 16  # Default spread (matches 2..18 range)

        self._update_roll_params()
        self._init_spheres()
        self._setup_ui()
        self.solid_bodies = get_solid_bodies_from_model(self.animated_sphere_ids)
        self.bspline_surfaces = get_all_bspline_surfaces(ISessionMgr.ActiveDgnModelRef.GetDgnModel())

    def _setup_ui(self):
        layout = QVBoxLayout()
        btn_layout = QHBoxLayout()
        self.play_btn = QPushButton("Play")
        self.stop_btn = QPushButton("Stop")
        self.play_btn.clicked.connect(self.on_play)
        self.stop_btn.clicked.connect(self.on_stop)
        btn_layout.addWidget(self.play_btn)
        btn_layout.addWidget(self.stop_btn)
        layout.addLayout(btn_layout)

        grid = QGridLayout()
        self.gravity_slider = QSlider(Qt.Horizontal)
        self.gravity_slider.setMinimum(-200)
        self.gravity_slider.setMaximum(-1)
        self.gravity_slider.setValue(int(self.gravity * 1000))
        self.gravity_slider.setSingleStep(1)
        self.gravity_slider.valueChanged.connect(self.on_gravity_slider)
        grid.addWidget(QLabel("Gravity (m/s²):"), 0, 0)
        self.gravity_label = QLabel(f"{self.gravity:.3f}")
        grid.addWidget(self.gravity_label, 0, 1)
        grid.addWidget(self.gravity_slider, 0, 2)

        self.bounce_slider = QSlider(Qt.Horizontal)
        self.bounce_slider.setMinimum(10)
        self.bounce_slider.setMaximum(100)
        self.bounce_slider.setValue(int(self.bounce_damping * 100))
        self.bounce_slider.setSingleStep(1)
        self.bounce_slider.valueChanged.connect(self.on_bounce_slider)
        grid.addWidget(QLabel("Bounce Damping:"), 1, 0)
        self.bounce_label = QLabel(f"{self.bounce_damping:.2f}")
        grid.addWidget(self.bounce_label, 1, 1)
        grid.addWidget(self.bounce_slider, 1, 2)

        self.roll_control_slider = QSlider(Qt.Horizontal)
        self.roll_control_slider.setMinimum(0)
        self.roll_control_slider.setMaximum(100)
        self.roll_control_slider.setValue(self.roll_control)
        self.roll_control_slider.setSingleStep(1)
        self.roll_control_slider.valueChanged.connect(self.on_roll_control_slider)
        grid.addWidget(QLabel("Roll Amount:"), 2, 0)
        self.roll_control_label = QLabel(self._roll_control_label_text())
        grid.addWidget(self.roll_control_label, 2, 1)
        grid.addWidget(self.roll_control_slider, 2, 2)

        self.num_spheres_slider = QSlider(Qt.Horizontal)
        self.num_spheres_slider.setMinimum(1)
        self.num_spheres_slider.setMaximum(150)
        self.num_spheres_slider.setValue(self.num_spheres)
        self.num_spheres_slider.setSingleStep(1)
        self.num_spheres_slider.valueChanged.connect(self.on_num_spheres_slider)
        grid.addWidget(QLabel("Number of Spheres:"), 3, 0)
        self.num_spheres_label = QLabel(str(self.num_spheres))
        grid.addWidget(self.num_spheres_label, 3, 1)
        grid.addWidget(self.num_spheres_slider, 3, 2)

        self.sphere_min_slider = QSlider(Qt.Horizontal)
        self.sphere_min_slider.setMinimum(1)
        self.sphere_min_slider.setMaximum(100)
        self.sphere_min_slider.setValue(int(self.sphere_radius_min * 10))
        self.sphere_min_slider.setSingleStep(1)
        self.sphere_min_slider.valueChanged.connect(self.on_sphere_min_slider)
        grid.addWidget(QLabel("Sphere Min Size:"), 4, 0)
        self.sphere_min_label = QLabel(f"{self.sphere_radius_min:.2f}")
        grid.addWidget(self.sphere_min_label, 4, 1)
        grid.addWidget(self.sphere_min_slider, 4, 2)

        self.sphere_max_slider = QSlider(Qt.Horizontal)
        self.sphere_max_slider.setMinimum(1)
        self.sphere_max_slider.setMaximum(100)
        self.sphere_max_slider.setValue(int(self.sphere_radius_max * 10))
        self.sphere_max_slider.setSingleStep(1)
        self.sphere_max_slider.valueChanged.connect(self.on_sphere_max_slider)
        grid.addWidget(QLabel("Sphere Max Size:"), 5, 0)
        self.sphere_max_label = QLabel(f"{self.sphere_radius_max:.2f}")
        grid.addWidget(self.sphere_max_label, 5, 1)
        grid.addWidget(self.sphere_max_slider, 5, 2)

        self.drop_height_slider = QSlider(Qt.Horizontal)
        self.drop_height_slider.setMinimum(50)
        self.drop_height_slider.setMaximum(200)
        self.drop_height_slider.setValue(int(self.drop_height))
        self.drop_height_slider.setSingleStep(1)
        self.drop_height_slider.valueChanged.connect(self.on_drop_height_slider)
        grid.addWidget(QLabel("Drop Height:"), 6, 0)
        self.drop_height_label = QLabel(f"{self.drop_height:.2f}")
        grid.addWidget(self.drop_height_label, 6, 1)
        grid.addWidget(self.drop_height_slider, 6, 2)

        self.substeps_slider = QSlider(Qt.Horizontal)
        self.substeps_slider.setMinimum(1)
        self.substeps_slider.setMaximum(30)
        self.substeps_slider.setValue(self.substeps)
        self.substeps_slider.setSingleStep(1)
        self.substeps_slider.valueChanged.connect(self.on_substeps_slider)
        grid.addWidget(QLabel("Physics Substeps - Speed <--> Accuracy:"), 7, 0)
        self.substeps_label = QLabel(str(self.substeps))
        grid.addWidget(self.substeps_label, 7, 1)
        grid.addWidget(self.substeps_slider, 7, 2)

        self.ignore_static_checkbox = QCheckBox("Ignore Model Primitive Solids")
        self.ignore_static_checkbox.setChecked(self.ignore_static_collisions)
        self.ignore_static_checkbox.stateChanged.connect(self.on_ignore_static_checkbox)
        grid.addWidget(self.ignore_static_checkbox, 8, 0, 1, 3)

        self.frame_by_frame_checkbox = QCheckBox("Frame by Frame Mode")
        self.frame_by_frame_checkbox.setChecked(self.frame_by_frame_mode)
        self.frame_by_frame_checkbox.stateChanged.connect(self.on_frame_by_frame_checkbox)
        grid.addWidget(self.frame_by_frame_checkbox, 9, 0, 1, 3)

        self.frame_slider = QSlider(Qt.Horizontal)
        self.frame_slider.setMinimum(0)
        self.frame_slider.setMaximum(self.max_manual_frames)
        self.frame_slider.setValue(0)
        self.frame_slider.setSingleStep(1)
        self.frame_slider.valueChanged.connect(self.on_frame_slider)
        grid.addWidget(QLabel("Frame:"), 10, 0)
        self.frame_label = QLabel(str(self.manual_frame))
        grid.addWidget(self.frame_label, 10, 1)
        grid.addWidget(self.frame_slider, 10, 2)

        # XY Spread Slider
        self.xy_spread_slider = QSlider(Qt.Horizontal)
        self.xy_spread_slider.setMinimum(4)
        self.xy_spread_slider.setMaximum(100)
        self.xy_spread_slider.setValue(self.xy_spread)
        self.xy_spread_slider.setSingleStep(1)
        self.xy_spread_slider.valueChanged.connect(self.on_xy_spread_slider)
        grid.addWidget(QLabel("XY Spread:"), 11, 0)
        self.xy_spread_label = QLabel(str(self.xy_spread))
        grid.addWidget(self.xy_spread_label, 11, 1)
        grid.addWidget(self.xy_spread_slider, 11, 2)

        # Animation Speed Slider
        self.animation_speed_slider = QSlider(Qt.Horizontal)
        self.animation_speed_slider.setMinimum(5)
        self.animation_speed_slider.setMaximum(200)
        self.animation_speed_slider.setValue(self.animation_speed)
        self.animation_speed_slider.setSingleStep(1)
        self.animation_speed_slider.valueChanged.connect(self.on_animation_speed_slider)
        grid.addWidget(QLabel("Animation Speed (ms/frame):"), 12, 0)
        self.animation_speed_label = QLabel(str(self.animation_speed))
        grid.addWidget(self.animation_speed_label, 12, 1)
        grid.addWidget(self.animation_speed_slider, 12, 2)

        layout.addLayout(grid)
        self.setLayout(layout)
        self.setFocusPolicy(Qt.StrongFocus)
        self.update_frame_slider_state()

    def update_frame_slider_state(self):
        self.frame_slider.setEnabled(self.frame_by_frame_mode)
        self.frame_label.setEnabled(self.frame_by_frame_mode)

    def _roll_control_label_text(self):
        if self.roll_control <= 10:
            return "None"
        elif self.roll_control <= 30:
            return "Low"
        elif self.roll_control <= 70:
            return "Medium"
        elif self.roll_control <= 90:
            return "High"
        else:
            return "Max"

    def _update_roll_params(self):
        t = self.roll_control / 100.0
        if self.roll_control == 0:
            self.roll_friction = 0.0
            self.roll_stop_threshold = 1.0
        else:
            self.roll_friction = 0.5 + 0.495 * t
            self.roll_stop_threshold = 0.05 - 0.049 * t

    def keyPressEvent(self, event):
        if event.key() == Qt.Key_Up:
            self.gravity_slider.setValue(self.gravity_slider.value() + 1)
        elif event.key() == Qt.Key_Down:
            self.gravity_slider.setValue(self.gravity_slider.value() - 1)
        elif event.key() == Qt.Key_Left:
            self.roll_control_slider.setValue(self.roll_control_slider.value() - 1)
        elif event.key() == Qt.Key_Right:
            self.roll_control_slider.setValue(self.roll_control_slider.value() + 1)
        elif event.key() == Qt.Key_Plus or event.key() == Qt.Key_Equal:
            self.bounce_slider.setValue(self.bounce_slider.value() + 1)
        elif event.key() == Qt.Key_Minus:
            self.bounce_slider.setValue(self.bounce_slider.value() - 1)
        elif event.key() == Qt.Key_R:
            self.on_play()
        elif event.key() == Qt.Key_S:
            self.on_stop()
        elif event.key() == Qt.Key_N:
            self.num_spheres_slider.setFocus()
        elif event.key() == Qt.Key_PageUp and self.frame_by_frame_mode:
            self.frame_slider.setValue(min(self.frame_slider.value() + 1, self.max_manual_frames))
        elif event.key() == Qt.Key_PageDown and self.frame_by_frame_mode:
            self.frame_slider.setValue(max(self.frame_slider.value() - 1, 0))
        else:
            super().keyPressEvent(event)

    def on_gravity_slider(self, value):
        self.gravity = value / 1000.0
        self.gravity_label.setText(f"{self.gravity:.3f}")

    def on_bounce_slider(self, value):
        self.bounce_damping = value / 100.0
        self.bounce_label.setText(f"{self.bounce_damping:.2f}")

    def on_roll_control_slider(self, value):
        self.roll_control = value
        self._update_roll_params()
        self.roll_control_label.setText(self._roll_control_label_text())

    def on_num_spheres_slider(self, value):
        self.num_spheres = value
        self.num_spheres_label.setText(str(self.num_spheres))
        self._init_spheres()

    def on_sphere_min_slider(self, value):
        min_val = value / 10.0
        if min_val > self.sphere_radius_max:
            min_val = self.sphere_radius_max
            self.sphere_min_slider.setValue(int(min_val * 10))
        self.sphere_radius_min = min_val
        self.sphere_min_label.setText(f"{self.sphere_radius_min:.2f}")
        self._init_spheres()

    def on_sphere_max_slider(self, value):
        max_val = value / 10.0
        if max_val < self.sphere_radius_min:
            max_val = self.sphere_radius_min
            self.sphere_max_slider.setValue(int(max_val * 10))
        self.sphere_radius_max = max_val
        self.sphere_max_label.setText(f"{self.sphere_radius_max:.2f}")
        self._init_spheres()

    def on_drop_height_slider(self, value):
        self.drop_height = float(value)
        self.drop_height_label.setText(f"{self.drop_height:.2f}")
        self._init_spheres()

    def on_substeps_slider(self, value):
        self.substeps = value
        self.substeps_label.setText(str(self.substeps))

    def on_ignore_static_checkbox(self, state):
        self.ignore_static_collisions = (state == Qt.Checked)

    def on_frame_by_frame_checkbox(self, state):
        self.frame_by_frame_mode = (state == Qt.Checked)
        self.update_frame_slider_state()
        if self.frame_by_frame_mode:
            self.timer.stop()
        else:
            self.manual_frame = 0
            self.frame_slider.setValue(0)
            if self.playing:
                self.timer.start()

    def on_frame_slider(self, value):
        if not self.frame_by_frame_mode:
            return
        self.manual_frame = value
        self.frame_label.setText(str(self.manual_frame))
        self._init_spheres()
        self.animated_sphere_ids = set()
        for sphere in self.spheres:
            if sphere["eeh"] is not None and sphere["eeh"].IsValid():
                self.animated_sphere_ids.add(sphere["eeh"].GetElementId())
        self.solid_bodies = get_solid_bodies_from_model(self.animated_sphere_ids)
        self.bspline_surfaces = get_all_bspline_surfaces(ISessionMgr.ActiveDgnModelRef.GetDgnModel())
        for frame in range(self.manual_frame):
            self._advance_simulation_step()
        self._redraw_spheres()

    def on_xy_spread_slider(self, value):
        self.xy_spread = value
        self.xy_spread_label.setText(str(self.xy_spread))
        self._init_spheres()

    def on_animation_speed_slider(self, value):
        self.animation_speed = value
        self.animation_speed_label.setText(str(self.animation_speed))
        self.timer.setInterval(self.animation_speed)

    def _get_uor_per_master(self):
        dgnModel = ISessionMgr.ActiveDgnModelRef.GetDgnModel()
        modelInfo = dgnModel.GetModelInfo()
        __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)
        return uorPerMast

    def _init_spheres(self):
        self._delete_all_spheres()
        self.spheres = []
        self.animated_sphere_ids.clear()

        # Generate radii for all spheres
        radii = [random.uniform(self.sphere_radius_min, self.sphere_radius_max) for _ in range(self.num_spheres)]

        # Packing parameters
        max_attempts = 1000
        z_step = 0.2  # Z increment for stacking
        base_z = self.drop_height
        placed_centers = []

        for i in range(self.num_spheres):
            radius = radii[i]
            placed = False
            for attempt in range(max_attempts):
                x = random.uniform(2 + radius, 2 + self.xy_spread - radius)
                y = random.uniform(2 + radius, 2 + self.xy_spread - radius)
                z = base_z
                while True:
                    overlap = False
                    for (px, py, pz, pr) in placed_centers:
                        dist_xy = math.hypot(x - px, y - py)
                        dist_z = abs(z - pz)
                        # Check for overlap in 3D
                        if dist_xy < (radius + pr - 1e-8) and dist_z < (radius + pr - 1e-8):
                            overlap = True
                            break
                    if not overlap:
                        placed_centers.append((x, y, z, radius))
                        vx = random.uniform(-0.05, 0.05)
                        vy = random.uniform(-0.05, 0.05)
                        vz = random.uniform(-0.05, 0.05)
                        eeh = self._create_sphere(x, y, z, radius)
                        self.spheres.append({
                            "x": x, "y": y, "z": z,
                            "vx": vx, "vy": vy, "vz": vz,
                            "radius": radius,
                            "eeh": eeh,
                            "rolling": False
                        })
                        placed = True
                        break
                    else:
                        z += z_step  # Try next Z level
                if placed:
                    break
            else:
                print(f"Could not place sphere {i+1} after {max_attempts} attempts (try increasing XY spread or reducing sphere size range)")


    def _create_sphere(self, x, y, z, radius):
        try:
            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
            dgnModel = ACTIVEMODEL.GetDgnModel()
            center = DPoint3d(x, y, z)
            center.Scale(self.uorPerMast)
            rad = radius * self.uorPerMast
            upVector1 = DVec3d.From(1.0, 0.0, 0.0)
            upVector2 = DVec3d.From(0.0, 1.0, 0.0)
            sphere_detail = DgnSphereDetail(center, upVector1, upVector2, rad, rad, -Angle.PiOver2(), Angle.Pi(), True)
            solid = ISolidPrimitive.CreateDgnSphere(sphere_detail)
            eeh = EditElementHandle()
            status = DraftingElementSchema.ToElement(eeh, solid, None, dgnModel)
            if status == BentleyStatus.eSUCCESS:
                eeh.AddToModel()
                return eeh
            else:
                return None
        except Exception:
            return None

    def _delete_all_spheres(self):
        for sphere in self.spheres:
            try:
                if sphere.get("eeh") and sphere["eeh"].IsValid():
                    sphere["eeh"].DeleteFromModel()
            except Exception:
                pass
        self.spheres = []

    def on_play(self):
        if not self.playing:
            self._init_spheres()
            self.animated_sphere_ids = set()
            for sphere in self.spheres:
                if sphere["eeh"] is not None and sphere["eeh"].IsValid():
                    self.animated_sphere_ids.add(sphere["eeh"].GetElementId())
            self.solid_bodies = get_solid_bodies_from_model(self.animated_sphere_ids)
            self.bspline_surfaces = get_all_bspline_surfaces(ISessionMgr.ActiveDgnModelRef.GetDgnModel())
            self.playing = True
            self.timer.start()
            print("Gravity animation started")

    def on_stop(self):
        if self.playing:
            self.playing = False
            self.timer.stop()
            self._delete_all_spheres()
            print("Gravity animation stopped and spheres cleared")

    def on_timer_tick(self):
        if self.frame_by_frame_mode:
            return
        self._advance_simulation_step()

    def _advance_simulation_step(self):
        try:
            SUBSTEPS = max(1, self.substeps)
            for i, s1 in enumerate(self.spheres):
                for j in range(i + 1, len(self.spheres)):
                    s2 = self.spheres[j]
                    dx = s2["x"] - s1["x"]
                    dy = s2["y"] - s1["y"]
                    dz = s2["z"] - s1["z"]
                    dist = math.sqrt(dx*dx + dy*dy + dz*dz)
                    min_dist = s1["radius"] + s2["radius"]
                    if dist < min_dist and dist > 1e-8:
                        overlap = 0.5 * (min_dist - dist)
                        nx = dx / dist
                        ny = dy / dist
                        nz = dz / dist
                        s1["x"] -= overlap * nx
                        s1["y"] -= overlap * ny
                        s1["z"] -= overlap * nz
                        s2["x"] += overlap * nx
                        s2["y"] += overlap * ny
                        s2["z"] += overlap * nz

                        v1 = [s1["vx"], s1["vy"], s1["vz"]]
                        v2 = [s2["vx"], s2["vy"], s2["vz"]]
                        n = [nx, ny, nz]
                        v1n = v1[0]*n[0] + v1[1]*n[1] + v1[2]*n[2]
                        v2n = v2[0]*n[0] + v2[1]*n[1] + v2[2]*n[2]
                        if v1n - v2n > 0:
                            for k in range(3):
                                s1["vx"] = v1[0] + (v2n - v1n) * n[0]
                                s1["vy"] = v1[1] + (v2n - v1n) * n[1]
                                s1["vz"] = v1[2] + (v2n - v1n) * n[2]
                                s2["vx"] = v2[0] + (v1n - v2n) * n[0]
                                s2["vy"] = v2[1] + (v1n - v2n) * n[1]
                                s2["vz"] = v2[2] + (v1n - v2n) * n[2]

            for sphere in self.spheres:
                for _ in range(SUBSTEPS):
                    if not sphere["rolling"]:
                        sphere["vz"] += self.gravity / SUBSTEPS
                        sphere["z"] += sphere["vz"] / SUBSTEPS
                        sphere["x"] += sphere["vx"] / SUBSTEPS
                        sphere["y"] += sphere["vy"] / SUBSTEPS

                        if sphere["z"] - sphere["radius"] <= self.floor_z:
                            sphere["z"] = self.floor_z + sphere["radius"]
                            sphere["vz"] = -sphere["vz"] * self.bounce_damping
                            if abs(sphere["vz"]) < self.roll_stop_threshold:
                                sphere["vz"] = 0.0
                                sphere["rolling"] = True

                        if not self.ignore_static_collisions:
                            sphere_pos = DPoint3d(sphere["x"], sphere["y"], sphere["z"])
                            for body, bbox_min, bbox_max, elem_id, is_brep in self.solid_bodies:
                                max_correction = 2
                                for _ in range(max_correction):
                                    result = robust_sphere_body_collision(
                                        sphere_pos, sphere["radius"], body, bbox_min, bbox_max, self.uorPerMast, is_brep
                                    )
                                    if not result or not result[0]:
                                        break
                                    collided, normal, penetration, cp = result
                                    if collided:
                                        sphere["x"] += normal.x * penetration / SUBSTEPS
                                        sphere["y"] += normal.y * penetration / SUBSTEPS
                                        sphere["z"] += normal.z * penetration / SUBSTEPS
                                        sphere_pos = DPoint3d(sphere["x"], sphere["y"], sphere["z"])
                                        v_dot_n = sphere["vx"] * normal.x + sphere["vy"] * normal.y + sphere["vz"] * normal.z
                                        if v_dot_n < 0:
                                            sphere["vx"] -= (1 + self.bounce_damping) * v_dot_n * normal.x
                                            sphere["vy"] -= (1 + self.bounce_damping) * v_dot_n * normal.y
                                            sphere["vz"] -= (1 + self.bounce_damping) * v_dot_n * normal.z
                                        if abs(normal.z) > 0.7 and abs(sphere["vz"]) < self.roll_stop_threshold:
                                            sphere["vz"] = 0.0
                                            sphere["rolling"] = True
                                    else:
                                        break

                    else:
                        if self.roll_friction > 0.0:
                            sphere["x"] += sphere["vx"] / SUBSTEPS
                            sphere["y"] += sphere["vy"] / SUBSTEPS
                            sphere["vx"] *= self.roll_friction
                            sphere["vy"] *= self.roll_friction
                            if abs(sphere["vx"]) < self.roll_stop_threshold and abs(sphere["vy"]) < self.roll_stop_threshold:
                                sphere["vx"] = 0.0
                                sphere["vy"] = 0.0
                        else:
                            sphere["vx"] = 0.0
                            sphere["vy"] = 0.0
                        sphere["z"] = self.floor_z + sphere["radius"]

                try:
                    if sphere["eeh"] is not None and sphere["eeh"].IsValid():
                        sphere["eeh"].DeleteFromModel()
                except Exception:
                    pass
                sphere["eeh"] = self._create_sphere(
                    sphere["x"], sphere["y"], sphere["z"], sphere["radius"]
                )

            self.frames += 1
            if self.frames > self.max_frames:
                print("Max frames reached, stopping animation.")
                self.on_stop()
        except Exception as ex:
            print("Exception in _advance_simulation_step:", ex)

    def _redraw_spheres(self):
        for sphere in self.spheres:
            try:
                if sphere["eeh"] is not None and sphere["eeh"].IsValid():
                    sphere["eeh"].DeleteFromModel()
            except Exception:
                pass
            sphere["eeh"] = self._create_sphere(
                sphere["x"], sphere["y"], sphere["z"], sphere["radius"]
            )

    def closeEvent(self, event):
        print("SphereGravityDialog closed")
        self.timer.stop()
        self._delete_all_spheres()
        global _sphere_anim_dialog
        _sphere_anim_dialog = None
        event.accept()

def show_sphere_gravity_dialog():
    global _sphere_anim_dialog
    app = QApplication.instance()
    if app is None:
        app = QApplication(sys.argv)
    if _sphere_anim_dialog is not None:
        print("Sphere gravity dialog already open.")
        _sphere_anim_dialog.raise_()
        _sphere_anim_dialog.activateWindow()
        return
    _sphere_anim_dialog = SphereGravityDialog()
    _sphere_anim_dialog.show()
    print("Sphere gravity dialog shown")

    ms_timer = QTimer()
    ms_timer.setInterval(50)
    ms_timer.timeout.connect(PyCadInputQueue.PythonMainLoop)
    ms_timer.start()

    def cleanup():
        ms_timer.stop()
    _sphere_anim_dialog.destroyed.connect(cleanup)

    if not hasattr(app, "_mstn_event_loop_started"):
        app._mstn_event_loop_started = True
        app.exec_()

if __name__ == "__main__":
    show_sphere_gravity_dialog()