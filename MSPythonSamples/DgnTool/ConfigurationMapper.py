"""
MicroStation Configuration Variable Search and Visualization Tool

This script provides a PyQt5-based GUI for searching, viewing, and visualizing MicroStation configuration variables.
Key features:
- Search and filter configuration variables.
- View variable values, source CFG file, and order.
- Visualize relationships between variables and their references as a mind map.
- Load configuration variable data from a MicroStation debug file or launch MicroStation with the -debug flag to generate one.
- Synchronize selection between the variable list and the mind map visualization.

Helpers are provided throughout the code for:
- Printing to the terminal.
- Finding the MicroStation executable.
- Parsing debug files.
- Collecting configuration variables.
- Managing dialog state.
- GUI event handling and deferred actions.
- Mind map construction and navigation.

No functional code has been changed; only helpers and this description have been added.
"""

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import sys
import os
import re
import subprocess
import getpass
from PyQt5.QtWidgets import (
    QApplication, QDialog, QVBoxLayout, QHBoxLayout, QLabel, QLineEdit,
    QListWidget, QPushButton, QProgressBar, QGraphicsView, QGraphicsScene,
    QGraphicsItem, QSizePolicy, QWidget, QFileDialog, QListWidgetItem, QSplitter
)
from PyQt5.QtCore import Qt, QTimer, QPointF, QRectF
from PyQt5.QtGui import QPen, QColor, QFont, QPainter, QPainterPath, QFontMetrics

# --- Helper: Manage dialog instance state ---
_dialog_instance = None
_app_instance = None

def is_dialog_active():
    # Helper: Check if the dialog is currently active and visible.
    global _dialog_instance
    return _dialog_instance is not None and _dialog_instance.isVisible()

def cleanup_dialog():
    # Helper: Clean up and delete the dialog instance.
    global _dialog_instance
    if _dialog_instance is not None:
        _dialog_instance.deleteLater()
        _dialog_instance = None

def print_terminal(msg):
    # Helper: Print a message to the terminal.
    print(msg)

def find_microstation_exe():
    # Helper: Attempt to locate the MicroStation executable on the system.
    # Returns the path to microstation.exe if found, else an empty string.
    from MSPyBentley import WString
    cfg_value = WString()
    status = ConfigurationManager.GetVariable(cfg_value, "MSDIR")
    if status == BentleyStatus.eSUCCESS:
        msdir = str(cfg_value)
        possible_path = os.path.join(msdir, "MicroStation", "microstation.exe")
        if os.path.isfile(possible_path):
            return possible_path

    msdir_env = os.environ.get("MSDIR")
    if msdir_env:
        possible_path = os.path.join(msdir_env, "MicroStation", "microstation.exe")
        if os.path.isfile(possible_path):
            return possible_path

    possible_dirs = [
        r"C:\Program Files\Bentley\MicroStation",
        r"C:\Program Files\Bentley\MicroStation CONNECT Edition\MicroStation",
        r"C:\Program Files\Bentley\MicroStation 2025\MicroStation",
        r"C:\Program Files\Bentley\OpenBuildingsDesigner\MicroStation",
    ]
    for base in possible_dirs:
        exe = os.path.join(base, "microstation.exe")
        if os.path.isfile(exe):
            return exe

    try:
        import winreg
        for root in (winreg.HKEY_LOCAL_MACHINE, winreg.HKEY_CURRENT_USER):
            try:
                key = winreg.OpenKey(root, r"SOFTWARE\Bentley\MicroStation\Install")
                value, _ = winreg.QueryValueEx(key, "Path")
                exe = os.path.join(value, "microstation.exe")
                if os.path.isfile(exe):
                    return exe
            except Exception:
                continue
    except ImportError:
        pass

    return ""

class SafeVarCollector(IConfigVariableIterator):
    # Helper: Collects configuration variable names and values using the MicroStation API iterator.
    def __init__(self, var_list, var_value_map):
        super().__init__()
        self.var_list = var_list
        self.var_value_map = var_value_map

    def EachConfigVariable(self, name, value, level, locked):
        self.var_list.append(name)
        self.var_value_map[name] = value

def parse_msconfig_debug_file(debug_file_path):
    # Helper: Parse a MicroStation debug file to extract variable values, source CFG files, and order.
    # Returns a dictionary of variable information.
    variables = {}
    current_cfg_file = ""
    order = 0
    macro_file_re = re.compile(r'Processing macro file \[(.+?)\]')
    var_re = re.compile(r'^\s*\([^)]+\):\s*([A-Za-z0-9_]+)=(.*?)\s*\[(.*?)\]')
    with open(debug_file_path, 'r', encoding='utf-8') as f:
        for line in f:
            macro_match = macro_file_re.search(line)
            if macro_match:
                current_file = macro_match.group(1)
                current_cfg_file = os.path.basename(current_file)
            var_match = var_re.match(line)
            if var_match:
                name = var_match.group(1)
                value = var_match.group(2)
                variables[name] = {'value': value, 'cfg_file': current_cfg_file, 'order': order}
                order += 1
    return variables

# --- Mind Map Visualization Classes ---

class MindMapWidget(QWidget):
    # Helper: Widget containing the mind map graphics view and zoom controls.
    def __init__(self, parent=None):
        super().__init__(parent)
        self.view = MindMapGraphicsView(self)
        layout = QVBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(0)
        btn_layout = QHBoxLayout()
        btn_layout.addStretch(1)
        self.zoom_extents_btn = QPushButton("Zoom Extents")
        self.zoom_extents_btn.clicked.connect(self.zoom_extents)
        btn_layout.addWidget(self.zoom_extents_btn)
        layout.addLayout(btn_layout)
        layout.addWidget(self.view)
        self.setLayout(layout)

    def build_map(self, var_value_map, var_info_map, dialog_ref):
        self.view.build_map(var_value_map, var_info_map, dialog_ref)

    def fit_to_screen(self):
        self.view.fit_to_screen()

    def zoom_extents(self):
        self.fit_to_screen()

class MindMapGraphicsView(QGraphicsView):
    # Helper: Graphics view for displaying the mind map scene.
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setScene(MindMapScene(self))
        self.setRenderHint(QPainter.Antialiasing)
        self.setMinimumWidth(500)
        self.setSizePolicy(QSizePolicy.Expanding, QSizePolicy.Expanding)
        self.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.setMouseTracking(True)
        self.setDragMode(QGraphicsView.NoDrag)
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        self.setBackgroundBrush(QColor(42, 42, 42))
        self._pan = False
        self._pan_start = None
        self._pan_start_center = None
        self._zoom = 1.0

    def build_map(self, var_value_map, var_info_map, dialog_ref):
        self.scene().build_map(var_value_map, var_info_map, dialog_ref)
        self.fit_to_screen()

    def fit_to_screen(self):
        if self.scene().items():
            self.setTransformationAnchor(QGraphicsView.AnchorViewCenter)
            self.setTransform(QPainter().transform())
            self._zoom = 1.0
            self.fitInView(self.scene().itemsBoundingRect(), Qt.KeepAspectRatio)
            self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)

    def wheelEvent(self, event):
        self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        zoomInFactor = 1.15
        zoomOutFactor = 1 / zoomInFactor
        if event.angleDelta().y() > 0:
            zoomFactor = zoomInFactor
        else:
            zoomFactor = zoomOutFactor
        self._zoom *= zoomFactor
        self.scale(zoomFactor, zoomFactor)

    def mousePressEvent(self, event):
        if event.button() == Qt.MiddleButton:
            self._pan = True
            self.setCursor(Qt.ClosedHandCursor)
            self._pan_start = event.pos()
            self._pan_start_center = self.mapToScene(self.viewport().rect().center())
        else:
            super().mousePressEvent(event)

    def mouseMoveEvent(self, event):
        if self._pan:
            delta = self.mapToScene(event.pos()) - self.mapToScene(self._pan_start)
            new_center = self._pan_start_center - delta
            self.centerOn(new_center)
        else:
            super().mouseMoveEvent(event)

    def mouseReleaseEvent(self, event):
        if event.button() == Qt.MiddleButton:
            self._pan = False
            self.setCursor(Qt.ArrowCursor)
        else:
            super().mouseReleaseEvent(event)

    def center_on_node(self, node):
        if node is not None:
            center = node.scenePos() + node._box_rect.center()
            self.centerOn(center)

class MindMapScene(QGraphicsScene):
    # Helper: Scene for managing mind map nodes and edges.
    def __init__(self, parent=None):
        super().__init__(parent)
        self.var_value_map = {}
        self.var_info_map = {}
        self.nodes = {}
        self.edges = []
        self.node_positions = {}
        self.root_node = None
        self.padding = 24
        self.dialog_ref = None
        self._cluster_names = set()
        self.expanded_cfg_file = None
        self.deferred_expand_node = None
        self.selected_var_name = None

    def build_map(self, var_value_map, var_info_map, dialog_ref):
        self.clear()
        self.var_value_map = dict(var_value_map)
        self.var_info_map = dict(var_info_map)
        self.nodes = {}
        self.edges = []
        self.node_positions = {}
        self.dialog_ref = dialog_ref
        self._cluster_names = set()
        self.expanded_cfg_file = None
        self.deferred_expand_node = None
        self.selected_var_name = None

        clusters = {}
        for var, info in self.var_info_map.items():
            cfg_file = info.get('cfg_file', 'Unknown')
            clusters.setdefault(cfg_file, []).append((var, info['order']))
        sorted_clusters = sorted(clusters.items(), key=lambda item: min(order for _, order in item[1]))

        self.root_node = MindMapNode("Current Configuration", self, is_root=True, is_cluster=False)
        self.root_node.setPos(0, 0)
        self.addItem(self.root_node)
        self.nodes["Current Configuration"] = self.root_node
        self.node_positions["Current Configuration"] = QPointF(0, 0)
        self.root_node.update_expand_btn()

        cluster_nodes = []
        cluster_spacing_y = 90
        cluster_x = 300
        cluster_y0 = 0
        for i, (cfg_file, var_list) in enumerate(sorted_clusters):
            y = cluster_y0 + i * cluster_spacing_y
            cluster_node = MindMapNode(cfg_file, self, is_root=False, is_cluster=True)
            cluster_node.setPos(cluster_x, y)
            self.addItem(cluster_node)
            self.nodes[cfg_file] = cluster_node
            self.node_positions[cfg_file] = cluster_node.pos()
            edge = MindMapEdge(self.root_node, cluster_node)
            self.addItem(edge)
            self.edges.append(edge)
            var_list_sorted = [v for v, _ in sorted(var_list, key=lambda t: t[1])]
            cluster_node._cluster_vars = var_list_sorted
            cluster_node.update_expand_btn()
            cluster_nodes.append(cluster_node)

    def extract_references(self, value):
        # Helper: Extract variable references from a value string.
        # Returns a set of referenced variable names.
        refs = set()
        if not value:
            return refs
        refs.update(re.findall(r"\$\((\w+)\)", value))
        refs.update(re.findall(r"%(\w+)%", value))
        refs.update(re.findall(r"\$\{(\w+)\}", value))
        return refs

    def contract_cfg_file_nodes(self, except_node=None):
        # Helper: Contract all expanded cluster nodes except the specified one.
        for node in list(self.nodes.values()):
            if node.is_cluster and node._expanded and node is not except_node:
                node.contract()
        self.update()

    def expand_node(self, var_name, parent_node):
        # Helper: Defer expansion of a node for GUI thread safety.
        self.deferred_expand_node = (var_name, parent_node)
        if self.dialog_ref:
            self.dialog_ref.defer_expand_node()

    def _do_expand_node(self, var_name, parent_node):
        # Helper: Actually expand a node, adding child nodes and edges.
        if getattr(parent_node, "_expanded", False):
            return
        if parent_node.is_cluster:
            self.contract_cfg_file_nodes(except_node=parent_node)
        parent_node._expanded = True

        for node in list(self.nodes.values()):
            if getattr(node, "_parent", None) is parent_node:
                self.removeItem(node)
                del self.nodes[node.var_name]
        for edge in list(self.edges):
            if edge.node_from is parent_node:
                self.removeItem(edge)
                self.edges.remove(edge)

        if hasattr(parent_node, "_cluster_vars"):
            var_list = parent_node._cluster_vars
            child_nodes = []
            spacing_y = 60
            x = parent_node.pos().x() + 300
            y0 = parent_node.pos().y() - (len(var_list) - 1) * spacing_y / 2
            for i, var in enumerate(var_list):
                y = y0 + i * spacing_y
                node = MindMapNode(var, self, is_root=False, is_cluster=False)
                node._parent = parent_node
                node.setPos(x, y)
                self.addItem(node)
                self.nodes[var] = node
                edge = MindMapEdge(parent_node, node)
                self.addItem(edge)
                self.edges.append(edge)
                node.update_expand_btn()
                child_nodes.append(node)
            parent_node._child_nodes = child_nodes
        else:
            child_vars = []
            for child_var, child_val in self.var_value_map.items():
                refs = self.extract_references(child_val)
                if var_name in refs:
                    child_vars.append(child_var)
            if not child_vars:
                return
            spacing_y = 60
            x = parent_node.pos().x() + 300
            y0 = parent_node.pos().y() - (len(child_vars) - 1) * spacing_y / 2
            child_nodes = []
            for i, child_var in enumerate(child_vars):
                y = y0 + i * spacing_y
                if child_var in self.nodes:
                    child_node = self.nodes[child_var]
                else:
                    child_node = MindMapNode(child_var, self, is_root=False, is_cluster=False)
                    self.nodes[child_var] = child_node
                    self.addItem(child_node)
                child_node._parent = parent_node
                child_node.setPos(x, y)
                edge = MindMapEdge(parent_node, child_node)
                self.addItem(edge)
                self.edges.append(edge)
                child_node.update_expand_btn()
                child_nodes.append(child_node)
            parent_node._child_nodes = child_nodes
        self.update()

    def node_clicked(self, node):
        # Helper: Handle node click events, updating selection and expanding clusters as needed.
        if not node.is_cluster:
            info = self.var_info_map.get(node.var_name, None)
            self.selected_var_name = node.var_name
            if self.dialog_ref is not None:
                self.dialog_ref.update_fields_from_node(node.var_name, info, from_mindmap=True)
        elif node.is_cluster:
            self.expand_node(node.var_name, node)
        self.update()

    def highlight_node(self, var_name):
        # Helper: Highlight a node by variable name.
        node = None
        for n in list(self.items()):
            if isinstance(n, MindMapNode):
                n.setSelected(n.var_name == var_name)
                if n.var_name == var_name:
                    node = n
        self.selected_var_name = var_name
        self.update()
        return node

    def expand_to_variable(self, var_name):
        # Helper: Expand the mind map to reveal a variable node.
        for node in list(self.nodes.values()):
            if node.is_cluster and hasattr(node, "_cluster_vars") and var_name in node._cluster_vars:
                if not node._expanded:
                    self.expand_node(node.var_name, node)
                    self._do_expand_node(node.var_name, node)
        return self.highlight_node(var_name)

class MindMapNode(QGraphicsItem):
    # Helper: Node item for the mind map, representing a variable or cluster.
    def __init__(self, name, scene, is_root=False, is_cluster=False):
        super().__init__()
        self.var_name = name
        self.scene_ref = scene
        self._expanded = False
        self._child_nodes = []
        self._parent = None
        self.is_root = is_root
        self.is_cluster = is_cluster
        self.setFlag(QGraphicsItem.ItemIsSelectable)
        self.setToolTip(name)
        self.font = QFont("Segoe UI", 10)
        self._padding = 18
        self._box_rect = QRectF(0, 0, 140, 40)
        self._update_box_size()
        self.expand_btn = MindMapExpandButton(self)
        self.expand_btn.setParentItem(self)
        self.expand_btn.setPos(self._box_rect.width() + 10, self._box_rect.height() / 2 - 10)
        self.expand_btn.setVisible(False)

    def _update_box_size(self):
        metrics = QFontMetrics(self.font)
        name_width = metrics.horizontalAdvance(self.var_name)
        name_height = metrics.height()
        box_width = name_width + 2 * self._padding
        box_height = name_height + 2 * self._padding
        self._box_rect = QRectF(0, 0, box_width, box_height)
        if hasattr(self, 'expand_btn'):
            self.expand_btn.setPos(self._box_rect.width() + 10, self._box_rect.height() / 2 - 10)

    def boundingRect(self):
        rect = QRectF(self._box_rect)
        rect.setRight(rect.right() + 30)
        rect.setBottom(rect.bottom() + 2)
        return rect

    def paint(self, painter, option, widget):
        shadow_path = QPainterPath()
        shadow_path.addRoundedRect(self._box_rect.translated(6, 8), 12, 12)
        painter.setBrush(QColor(0, 0, 0, 110))
        painter.setPen(Qt.NoPen)
        painter.drawPath(shadow_path)
        path = QPainterPath()
        path.addRoundedRect(self._box_rect, 12, 12)
        if self.isSelected():
            painter.setBrush(QColor(255, 220, 120))
            painter.setPen(QPen(QColor(255, 180, 50), 3))
        elif self.is_cluster:
            painter.setBrush(QColor(40, 80, 40))
            painter.setPen(QPen(QColor(90, 120, 180), 2))
        else:
            painter.setBrush(QColor(48, 54, 72))
            painter.setPen(QPen(QColor(90, 120, 180), 2))
        painter.drawPath(path)
        painter.setPen(QColor(0, 0, 0) if self.isSelected() else QColor(255, 255, 255))
        painter.setFont(self.font)
        metrics = QFontMetrics(self.font)
        name_height = metrics.height()
        painter.drawText(
            QPointF(self._box_rect.left() + self._padding,
                    self._box_rect.top() + self._padding + name_height - metrics.descent()),
            str(self.var_name)
        )

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.scene_ref.node_clicked(self)
        super().mousePressEvent(event)

    def has_children(self):
        # Helper: Determine if this node has children (references or cluster members).
        if self.is_cluster and hasattr(self, "_cluster_vars"):
            return bool(self._cluster_vars)
        for child_var, child_val in self.scene_ref.var_value_map.items():
            refs = self.scene_ref.extract_references(child_val)
            if self.var_name in refs:
                return True
        return False

    def update_expand_btn(self):
        # Helper: Show or hide the expand button depending on whether the node has children.
        if self.has_children():
            self.expand_btn.setVisible(True)
        else:
            self.expand_btn.setVisible(False)

    def expand(self):
        # Helper: Expand this node to show its children.
        self.expand_btn.setVisible(False)
        self.scene_ref.expand_node(self.var_name, self)

    def contract(self):
        # Helper: Contract this node, hiding its children.
        for node in list(getattr(self, "_child_nodes", [])):
            if hasattr(node, "contract"):
                node.contract()
            if node.var_name in self.scene_ref.nodes:
                self.scene_ref.removeItem(node)
                del self.scene_ref.nodes[node.var_name]
        for edge in list(self.scene_ref.edges):
            if edge.node_from is self:
                self.scene_ref.removeItem(edge)
                self.scene_ref.edges.remove(edge)
        self._expanded = False
        self._child_nodes = []
        self.update_expand_btn()

class MindMapExpandButton(QGraphicsItem):
    # Helper: Expand button for mind map nodes.
    def __init__(self, parent_node):
        super().__init__()
        self.parent_node = parent_node
        self.setZValue(2)
        self.setAcceptHoverEvents(True)
        self.setCursor(Qt.PointingHandCursor)
        self._rect = QRectF(-10, -10, 20, 20)

    def boundingRect(self):
        return self._rect

    def paint(self, painter, option, widget):
        path = QPainterPath()
        path.addEllipse(self._rect)
        painter.setBrush(QColor(180, 255, 180))
        painter.setPen(QPen(QColor(50, 150, 50), 2))
        painter.drawPath(path)
        painter.setPen(QPen(QColor(50, 150, 50), 3))
        painter.drawLine(0, -5, 0, 5)
        painter.drawLine(-5, 0, 5, 0)

    def mousePressEvent(self, event):
        if event.button() == Qt.LeftButton:
            self.parent_node.expand()
            event.accept()
        else:
            super().mousePressEvent(event)

class MindMapEdge(QGraphicsItem):
    # Helper: Edge connecting two mind map nodes.
    def __init__(self, node_from, node_to):
        super().__init__()
        self.node_from = node_from
        self.node_to = node_to
        self.setZValue(-1)

    def boundingRect(self):
        p1 = self.node_from.scenePos() + self.node_from._box_rect.center()
        p2 = self.node_to.scenePos() + self.node_to._box_rect.center()
        return QRectF(p1, p2).normalized().adjusted(-12, -12, 12, 12)

    def paint(self, painter, option, widget):
        p1 = self.node_from.scenePos() + self.node_from._box_rect.center()
        p2 = self.node_to.scenePos() + self.node_to._box_rect.center()
        dx = (p2.x() - p1.x()) * 0.5
        dy = (p2.y() - p1.y()) * 0.1
        path = QPainterPath(p1)
        path.cubicTo(p1.x() + dx, p1.y() + dy, p2.x() - dx, p2.y() - dy, p2.x(), p2.y())
        painter.setRenderHint(QPainter.Antialiasing)
        painter.setPen(QPen(QColor(100, 200, 255, 180), 4, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))
        painter.drawPath(path)
        shadow_path = QPainterPath(p1 + QPointF(2, 4))
        shadow_path.cubicTo(p1.x() + dx + 2, p1.y() + dy + 4, p2.x() - dx + 2, p2.y() - dy + 4, p2.x() + 2, p2.y() + 4)
        painter.setPen(QPen(QColor(0, 0, 0, 70), 8, Qt.SolidLine, Qt.RoundCap, Qt.RoundJoin))
        painter.drawPath(shadow_path)

# --- Main Dialog and Application Logic ---

class ConfigVarSearchDialog(QDialog):
    # Main dialog for configuration variable search and visualization.
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("MicroStation Configuration Variable Search")
        self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
        self.setMinimumWidth(1100)
        self.setMinimumHeight(600)

        self.layout = QHBoxLayout(self)
        self.layout.setContentsMargins(8, 8, 8, 8)
        self.layout.setSpacing(8)

        self._block_selection = False

        self.splitter = QSplitter(Qt.Horizontal)
        self.splitter.setChildrenCollapsible(False)

        left_panel = QVBoxLayout()
        left_panel.setContentsMargins(8, 8, 8, 8)
        left_panel.setSpacing(8)

        search_layout = QHBoxLayout()
        search_layout.setContentsMargins(2, 2, 2, 2)
        search_layout.setSpacing(6)
        search_label = QLabel("Search:")
        self.search_edit = QLineEdit()
        self.search_edit.textChanged.connect(self.defer_update_var_list)
        search_layout.addWidget(search_label)
        search_layout.addWidget(self.search_edit)
        left_panel.addLayout(search_layout)

        self.var_cfg_splitter = QSplitter(Qt.Horizontal)
        self.var_cfg_splitter.setChildrenCollapsible(False)
        self.var_list = QListWidget()
        self.var_list.setSelectionMode(QListWidget.SingleSelection)
        self.var_list.itemSelectionChanged.connect(self.defer_on_var_selected)
        self.var_list.setStyleSheet(
            "border-right: 1px solid #cccccc; font-family: monospace; padding: 2px;"
        )
        self.cfg_file_list = QListWidget()
        self.cfg_file_list.setSelectionMode(QListWidget.SingleSelection)
        self.cfg_file_list.setStyleSheet(
            "border: none; font-family: monospace; padding: 2px;"
        )
        self.var_cfg_splitter.addWidget(self.var_list)
        self.var_cfg_splitter.addWidget(self.cfg_file_list)
        self.var_cfg_splitter.setSizes([220, 180])
        left_panel.addWidget(self.var_cfg_splitter, stretch=10)

        self.var_list.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOff)
        self.cfg_file_list.setVerticalScrollBarPolicy(Qt.ScrollBarAlwaysOn)
        self.cfg_file_list.setHorizontalScrollBarPolicy(Qt.ScrollBarAlwaysOff)

        self.cfg_file_list.verticalScrollBar().valueChanged.connect(
            lambda value: self.var_list.verticalScrollBar().setValue(value)
        )
        self.var_list.verticalScrollBar().valueChanged.connect(
            lambda value: self.cfg_file_list.verticalScrollBar().setValue(value)
        )

        value_layout = QHBoxLayout()
        value_layout.setContentsMargins(2, 2, 2, 2)
        value_layout.setSpacing(6)
        value_label = QLabel("Value:")
        self.value_display = QLineEdit()
        self.value_display.setReadOnly(True)
        self.value_display.setMinimumHeight(24)
        self.value_display.setStyleSheet("QLineEdit { font-family: monospace; }")
        value_layout.addWidget(value_label)
        value_layout.addWidget(self.value_display)
        left_panel.addLayout(value_layout)

        file_layout = QHBoxLayout()
        file_layout.setContentsMargins(2, 2, 2, 2)
        file_layout.setSpacing(6)
        file_label = QLabel("CFG File:")
        self.file_display = QLineEdit()
        self.file_display.setReadOnly(True)
        file_layout.addWidget(file_label)
        file_layout.addWidget(self.file_display)
        left_panel.addLayout(file_layout)

        order_layout = QHBoxLayout()
        order_layout.setContentsMargins(2, 2, 2, 2)
        order_layout.setSpacing(6)
        order_label = QLabel("Order:")
        self.order_display = QLineEdit()
        self.order_display.setReadOnly(True)
        order_layout.addWidget(order_label)
        order_layout.addWidget(self.order_display)
        left_panel.addLayout(order_layout)

        self.progress_bar = QProgressBar()
        self.progress_bar.setMinimum(0)
        self.progress_bar.setMaximum(0)
        self.progress_bar.setVisible(False)
        left_panel.addWidget(self.progress_bar)

        self.load_debug_btn = QPushButton("Load Debug File")
        self.load_debug_btn.clicked.connect(self._load_debug_file)
        left_panel.addWidget(self.load_debug_btn)

        self.launch_debug_btn = QPushButton("Launch MicroStation with -debug")
        self.launch_debug_btn.clicked.connect(self.launch_microstation_debug)
        left_panel.addWidget(self.launch_debug_btn)

        left_panel.addStretch(1)

        left_widget = QWidget()
        left_widget.setLayout(left_panel)
        self.splitter.addWidget(left_widget)

        self.mind_map = MindMapWidget()
        self.splitter.addWidget(self.mind_map)
        self.splitter.setSizes([400, 700])

        self.layout.addWidget(self.splitter)

        self.timer = QTimer(self)
        self.timer.setInterval(250)
        self.timer.timeout.connect(self.process_deferred_actions)
        self.deferred_action = None
        self.deferred_arg = None

        self.all_vars = []
        self.filtered_vars = []
        self.var_value_map = {}
        self.var_info_map = {}

        self._collect_names = []
        self._collect_done = False

        self.debug_var_map = None

        # Only change: dynamic path
        self.ms_exe_path = find_microstation_exe()

        self.deferred_expand_node_flag = False

        self.defer_refresh_vars()
        self.timer.start()

    # --- Helpers for deferred GUI actions ---

    def defer_update_var_list(self):
        # Helper: Defer updating the variable list after search/filter change.
        self.deferred_action = "update_var_list"
        self.deferred_arg = None

    def defer_on_var_selected(self):
        # Helper: Defer handling variable selection.
        self.deferred_action = "on_var_selected"
        self.deferred_arg = None

    def defer_refresh_vars(self):
        # Helper: Defer refreshing the variable list from the configuration manager.
        self.deferred_action = "refresh_vars"
        self.deferred_arg = None

    def defer_expand_node(self):
        # Helper: Defer expanding a mind map node.
        self.deferred_expand_node_flag = True

    def process_deferred_actions(self):
        # Helper: Process any deferred GUI actions.
        try:
            if self.deferred_action == "refresh_vars":
                self.refresh_vars()
                self.deferred_action = None
            elif self.deferred_action == "update_var_list":
                self.update_var_list()
                self.deferred_action = None
            elif self.deferred_action == "on_var_selected":
                self.on_var_selected()
                self.deferred_action = None
            if self.deferred_expand_node_flag:
                self.deferred_expand_node_flag = False
                scene = self.mind_map.view.scene()
                if scene.deferred_expand_node:
                    var_name, parent_node = scene.deferred_expand_node
                    scene.deferred_expand_node = None
                    scene._do_expand_node(var_name, parent_node)
        except Exception as ex:
            print_terminal(f"Error in process_deferred_actions: {ex}")
            self.close()

    def refresh_vars(self):
        # Helper: Refresh the variable list from the configuration manager.
        try:
            self.progress_bar.setVisible(True)
            self.var_list.clear()
            self.cfg_file_list.clear()
            self.value_display.setText("")
            self.file_display.setText("")
            self.order_display.setText("")
            self._collect_names = []
            self._collect_done = False
            self.var_value_map = {}
            self.var_info_map = {}
            self.deferred_action = None
            collector = SafeVarCollector(self._collect_names, self.var_value_map)
            ConfigurationManager.IterateThroughVariables(collector)
            self._collect_done = True
            self.all_vars = list(self._collect_names)
            self.all_vars.sort()
            self.var_info_map = {}
            for idx, var in enumerate(self.all_vars):
                self.var_info_map[var] = {
                    'value': self.var_value_map[var],
                    'cfg_file': "",
                    'order': idx
                }
            self.update_var_list()
            self.progress_bar.setVisible(False)
            self.mind_map.build_map(self.var_value_map, self.var_info_map, self)
            self.mind_map.fit_to_screen()
        except Exception as ex:
            print_terminal(f"Error in refresh_vars: {ex}")
            self.progress_bar.setVisible(False)
            self.close()

    def update_var_list(self):
        # Helper: Update the variable list based on the current search filter.
        try:
            filter_text = self.search_edit.text().strip().upper()
            self.var_list.clear()
            self.cfg_file_list.clear()
            self.filtered_vars = []
            if self.debug_var_map is not None:
                all_vars = sorted(self.debug_var_map.items(), key=lambda kv: kv[1]['order'])
                for var, info in all_vars:
                    if filter_text in var.upper():
                        self.var_list.addItem(var)
                        self.cfg_file_list.addItem(info['cfg_file'])
                        self.filtered_vars.append(var)
            else:
                all_vars = self.all_vars
                for var in all_vars:
                    if filter_text in var.upper():
                        cfg_file = ""
                        if var in self.var_info_map and "cfg_file" in self.var_info_map[var]:
                            cfg_file = self.var_info_map[var]["cfg_file"]
                        self.var_list.addItem(var)
                        self.cfg_file_list.addItem(cfg_file)
                        self.filtered_vars.append(var)
            if not self.filtered_vars:
                self.value_display.setText("")
                self.file_display.setText("")
                self.order_display.setText("")
        except Exception as ex:
            print_terminal(f"Error in update_var_list: {ex}")
            self.close()

    def on_var_selected(self, var_name=None, info=None, from_mindmap=False):
        # Helper: Handle selection of a variable in the list or mind map.
        if self._block_selection:
            return
        self._block_selection = True
        try:
            if var_name is None:
                selected_items = self.var_list.selectedItems()
                if selected_items:
                    var_name = selected_items[0].text()
                    idx = self.var_list.currentRow()
                    self.cfg_file_list.setCurrentRow(idx)
                else:
                    self.value_display.setText("")
                    self.file_display.setText("")
                    self.order_display.setText("")
                    self._block_selection = False
                    return
            if info is None:
                if self.debug_var_map is not None and var_name in self.debug_var_map:
                    info = self.debug_var_map[var_name]
                else:
                    idx = self.all_vars.index(var_name) if var_name in self.all_vars else -1
                    info = {
                        'value': self.var_value_map.get(var_name, ""),
                        'cfg_file': "",
                        'order': idx
                    }
            self.value_display.setText(info['value'])
            self.file_display.setText(info['cfg_file'])
            self.order_display.setText(str(info['order']))
            if not from_mindmap:
                node = self.mind_map.view.scene().expand_to_variable(var_name)
                node = self.mind_map.view.scene().nodes.get(var_name, None)
                if node is not None:
                    self.mind_map.view.center_on_node(node)
        except Exception as ex:
            print_terminal(f"Error in on_var_selected: {ex}")
            self.value_display.setText("")
            self.file_display.setText("")
            self.order_display.setText("")
        self._block_selection = False

    def update_fields_from_node(self, var_name, info, from_mindmap=False):
        # Helper: Update the variable detail fields from a mind map node selection.
        self.on_var_selected(var_name, info, from_mindmap=from_mindmap)
        if from_mindmap:
            self.highlight_config_list(var_name)

    def highlight_config_list(self, var_name):
        # Helper: Highlight the variable in the list when selected from the mind map.
        if self._block_selection:
            return
        self._block_selection = True
        try:
            for i in range(self.var_list.count()):
                if self.var_list.item(i).text() == var_name:
                    self.var_list.setCurrentRow(i)
                    self.cfg_file_list.setCurrentRow(i)
                    self.var_list.scrollToItem(self.var_list.item(i), QListWidget.PositionAtCenter)
                    break
        finally:
            self._block_selection = False

    def _load_debug_file(self):
        # Helper: Load a MicroStation debug file and update the variable list and mind map.
        fname, _ = QFileDialog.getOpenFileName(self, "Select Debug File", "", "Text Files (*.txt);;All Files (*)")
        if fname:
            self.debug_var_map = parse_msconfig_debug_file(fname)
            self.all_vars = [k for k, v in sorted(self.debug_var_map.items(), key=lambda kv: kv[1]['order'])]
            self.var_info_map = {k: v for k, v in self.debug_var_map.items()}
            self.update_var_list()
            self.value_display.setText("")
            self.file_display.setText("")
            self.order_display.setText("")
            self.mind_map.build_map({k: v['value'] for k, v in self.debug_var_map.items()}, self.var_info_map, self)
            self.mind_map.fit_to_screen()

    def launch_microstation_debug(self):
        # Helper: Launch MicroStation with the -debug flag and attempt to load the resulting debug file.
        exe_path = self.ms_exe_path
        if not os.path.isfile(exe_path):
            exe_path, _ = QFileDialog.getOpenFileName(self, "Select MicroStation Executable", "", "Executables (*.exe);;All Files (*)")
            if not exe_path or not os.path.isfile(exe_path):
                print_terminal("MicroStation executable not found.")
                return
            self.ms_exe_path = exe_path
        try:
            subprocess.Popen([exe_path, "-debug"])
            print_terminal("MicroStation launched with -debug. Close that session after the debug file is created. The debug file will now be loaded automatically if found.")
            username = getpass.getuser()
            debug_path = os.path.join(
                "C:\\Users", username, "AppData", "Local", "Temp",
                "Bentley", "MicroStation", "25.0.0", "msdebug.txt"
            )
            if os.path.isfile(debug_path):
                self.debug_var_map = parse_msconfig_debug_file(debug_path)
                self.all_vars = [k for k, v in sorted(self.debug_var_map.items(), key=lambda kv: kv[1]['order'])]
                self.var_info_map = {k: v for k, v in self.debug_var_map.items()}
                self.update_var_list()
                self.value_display.setText("")
                self.file_display.setText("")
                self.order_display.setText("")
                self.mind_map.build_map({k: v['value'] for k, v in self.debug_var_map.items()}, self.var_info_map, self)
                self.mind_map.fit_to_screen()
                print_terminal(f"Loaded debug file: {debug_path}")
            else:
                print_terminal(f"Could not find debug file at: {debug_path} Please check that MicroStation has closed and try again.")
        except Exception as ex:
            print_terminal(f"Error launching MicroStation with -debug: {ex}")

    def closeEvent(self, event):
        # Helper: Clean up dialog on close.
        cleanup_dialog()
        event.accept()

def show_config_var_search_dialog():
    # Helper: Show the configuration variable search dialog, ensuring only one instance is active.
    global _dialog_instance, _app_instance
    try:
        app = QApplication.instance()
        if app is None:
            app = QApplication(sys.argv)
            _app_instance = app
        else:
            _app_instance = app
        if is_dialog_active():
            _dialog_instance.raise_()
            _dialog_instance.activateWindow()
            return
        _dialog_instance = ConfigVarSearchDialog()
        _dialog_instance.show()
        print_terminal("ConfigVarSearchDialog shown.")
    except Exception as ex:
        print_terminal(f"Error in show_config_var_search_dialog: {ex}")

# --- Entry Point ---

show_config_var_search_dialog()