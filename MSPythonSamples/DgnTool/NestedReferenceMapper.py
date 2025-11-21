"""
ReferenceMap2.py

This script provides a PyQt5-based interactive visualization ("mind map") of the reference file structure
for the currently active MicroStation DGN model. It uses the MicroStation Python API to query reference
attachments and their properties, and displays them as interconnected nodes in a graphical scene. Each node
represents a reference file/model, and provides toggle buttons to control display, snap, and locate settings.
The UI supports searching for references by name, zooming to extents, and interactively expanding/collapsing
nodes. All changes made via the UI are deferred and safely applied to the MicroStation model.

Requirements:
- MicroStation Python API (MSPyBentley, MSPyECObjects, MSPyBentleyGeom, MSPyDgnPlatform, MSPyDgnView, MSPyMstnPlatform)
- PyQt5

Author: [Your Name]
Date: [Date]
"""

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import sys
import os
from PyQt5.QtWidgets import (
    QApplication, QDialog, QVBoxLayout, QHBoxLayout, QLabel, QPushButton,
    QGraphicsView, QGraphicsScene, QGraphicsItem, QSizePolicy, QWidget, QLineEdit, QStyle, QToolButton
)
from PyQt5.QtCore import Qt, QPointF, QRectF, QTimer
from PyQt5.QtGui import QPen, QColor, QFont, QPainter, QPainterPath, QFontMetrics, QPolygonF, QIcon

_dialog_instance = None
_app_instance = None

def print_terminal(msg):
    """
    Print a message to the terminal.
    """
    print(msg)

def is_dialog_active():
    """
    Check if the reference map dialog is currently active and visible.
    Returns:
        bool: True if dialog is active and visible, False otherwise.
    """
    global _dialog_instance
    return _dialog_instance is not None and _dialog_instance.isVisible()

def cleanup_dialog():
    """
    Clean up and delete the reference map dialog instance if it exists.
    """
    global _dialog_instance
    if _dialog_instance is not None:
        try:
            _dialog_instance.deleteLater()
        except Exception as ex:
            print_terminal(f"Error during dialog cleanup: {ex}")
        _dialog_instance = None

def exit_gracefully(msg=None):
    """
    Exit the script gracefully, optionally printing a message and cleaning up the dialog.
    Args:
        msg (str, optional): Message to print before exiting.
    """
    if msg:
        print_terminal(msg)
    cleanup_dialog()
    return

class DeferredActionQueue:
    """
    Helper class to queue up deferred actions (API calls) and process them safely.
    """
    def __init__(self):
        self.actions = []

    def add(self, func, *args, **kwargs):
        """
        Add a function and its arguments to the deferred action queue.
        """
        self.actions.append((func, args, kwargs))

    def process(self):
        """
        Process and execute all actions in the queue.
        """
        while self.actions:
            func, args, kwargs = self.actions.pop(0)
            try:
                func(*args, **kwargs)
            except Exception as ex:
                print_terminal(f"Error in deferred MicroStation API call: {ex}")

deferred_queue = DeferredActionQueue()

def synchronize_reference_dialog():
    """
    Synchronize and update the MicroStation Reference File Dialog.
    """
    try:
        PyCadInputQueue.SendKeyin("REFERENCE SYNCHRONIZEVIEW")
        PyCadInputQueue.SendKeyin("REFERENCE DIALOG UPDATE")
    except Exception as ex:
        print_terminal(f"Error synchronizing Reference File Dialog: {ex}")

def refresh_all_views():
    """
    Redraw all open views using the MicroStation keyin for 'Update All'.
    This preserves the zoom/pan state.
    """
    try:
        PyCadInputQueue.SendKeyin("UPDATE ALL")
    except Exception as ex:
        print_terminal(f"Error updating all views: {ex}")

class ToggleButton(QGraphicsItem):
    """
    Custom QGraphicsItem representing a toggle button for reference properties (Displayed, Snap, Locate).
    """
    def __init__(self, label, color_on, color_off, callback, initial_state=False, parent=None):
        super().__init__(parent)
        self.label = label
        self.color_on = color_on
        self.color_off = color_off
        self.callback = callback
        self.state = initial_state
        self.enabled = True
        self.setAcceptHoverEvents(True)
        self.setCursor(Qt.PointingHandCursor)
        self._rect = QRectF(0, 0, 80, 36)
        self.font = QFont("Segoe UI", 11, QFont.Bold)

    def setEnabled(self, enabled):
        """
        Enable or disable the toggle button.
        """
        self.enabled = enabled
        self.update()

    def boundingRect(self):
        """
        Return the bounding rectangle of the button.
        """
        return self._rect

    def paint(self, painter, option, widget):
        """
        Paint the toggle button.
        """
        try:
            painter.setRenderHint(QPainter.Antialiasing)
            if not self.enabled:
                color = QColor(60, 60, 60)
            else:
                color = self.color_on if self.state else self.color_off
            painter.setBrush(color)
            painter.setPen(QPen(QColor(70, 70, 70), 2))
            painter.drawRoundedRect(self._rect, 10, 10)
            painter.setFont(self.font)
            if not self.enabled:
                painter.setPen(QColor(120, 120, 120))
            else:
                painter.setPen(QColor(30, 30, 30) if self.state else QColor(120, 120, 120))
            metrics = QFontMetrics(self.font)
            text_width = metrics.horizontalAdvance(self.label)
            text_height = metrics.ascent()
            painter.drawText(
                QPointF(self._rect.left() + (self._rect.width() - text_width) / 2,
                        self._rect.top() + (self._rect.height() + text_height) / 2 - 2),
                self.label
            )
        except Exception as ex:
            print_terminal(f"Error in ToggleButton.paint: {ex}")

    def mousePressEvent(self, event):
        """
        Handle mouse press events to toggle the button state.
        """
        try:
            if not self.enabled:
                event.ignore()
                return
            if event.button() == Qt.LeftButton:
                self.state = not self.state
                self.update()
                if self.callback:
                    self.callback(self.state)
                event.accept()
            else:
                super().mousePressEvent(event)
        except Exception as ex:
            print_terminal(f"Error in ToggleButton.mousePressEvent: {ex}")

class DownArrowButton(QGraphicsItem):
    """
    QGraphicsItem representing a down arrow button for expanding/collapsing nodes.
    """
    def __init__(self, parent_node):
        super().__init__()
        self.parent_node = parent_node
        self.setZValue(2)
        self.setAcceptHoverEvents(True)
        self.setCursor(Qt.PointingHandCursor)
        self._rect = QRectF(-16, -16, 32, 32)

    def boundingRect(self):
        """
        Return the bounding rectangle of the arrow button.
        """
        return self._rect

    def paint(self, painter, option, widget):
        """
        Paint the down arrow button.
        """
        try:
            painter.setRenderHint(QPainter.Antialiasing)
            painter.setBrush(QColor(180, 255, 180))
            painter.setPen(QPen(QColor(50, 150, 50), 2))
            painter.drawEllipse(self._rect)
            arrow = QPolygonF([
                QPointF(0, 7),
                QPointF(-7, -3),
                QPointF(7, -3)
            ])
            painter.setBrush(QColor(50, 150, 50))
            painter.setPen(Qt.NoPen)
            painter.save()
            painter.translate(0, 0)
            painter.drawPolygon(arrow)
            painter.restore()
        except Exception as ex:
            print_terminal(f"Error in DownArrowButton.paint: {ex}")

    def mousePressEvent(self, event):
        """
        Handle mouse press events to expand/collapse the parent node.
        """
        try:
            if event.button() == Qt.LeftButton:
                self.parent_node.toggle_expand()
                event.accept()
            else:
                super().mousePressEvent(event)
        except Exception as ex:
            print_terminal(f"Error in DownArrowButton.mousePressEvent: {ex}")

class RefMindMapNode(QGraphicsItem):
    """
    QGraphicsItem representing a node in the reference mind map.
    Each node corresponds to a reference file/model.
    """
    def __init__(self, file_name, file_path, model_ref, scene, is_root=False):
        super().__init__()
        self.file_name = str(file_name)
        self.file_path = str(file_path)
        self.model_ref = model_ref
        self.scene_ref = scene
        self.is_root = is_root
        self.font = QFont("Segoe UI", 12)
        self._padding = 24
        self._box_rect = QRectF(0, 0, 400, 150)
        self._expanded = False
        self._expand_box_rect = QRectF(0, 0, 0, 0)
        self.expand_btn = DownArrowButton(self)
        self.expand_btn.setParentItem(self)
        self.toggle_buttons = []
        self.children = []
        self.parent_node = None
        self.highlighted = False  # <-- For search highlight
        self._create_toggle_buttons()
        self._update_box_size()
        self.expand_btn.setVisible(True)

    def _update_box_size(self):
        """
        Update the size of the node's bounding box based on content.
        """
        try:
            metrics = QFontMetrics(self.font)
            name_width = metrics.horizontalAdvance(self.file_name)
            box_width = max(name_width + 2 * self._padding, 400)
            box_height = 150
            self._box_rect = QRectF(0, 0, box_width, box_height)
            self.expand_btn.setPos(self._box_rect.left() + self._box_rect.width() / 2, self._box_rect.bottom() + 8)
            btn_y = self._box_rect.top() + 60
            btn_spacing = 20
            btn_total_width = len(self.toggle_buttons) * 80 + (len(self.toggle_buttons) - 1) * btn_spacing
            btn_x0 = self._box_rect.left() + (self._box_rect.width() - btn_total_width) / 2
            for i, btn in enumerate(self.toggle_buttons):
                btn.setPos(btn_x0 + i * (80 + btn_spacing), btn_y)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapNode._update_box_size: {ex}")

    def boundingRect(self):
        """
        Return the bounding rectangle of the node, including expanded area if needed.
        """
        try:
            self._update_box_size()
            rect = QRectF(self._box_rect)
            if self._expanded:
                rect = rect.united(self._expand_box_rect)
            rect = rect.united(QRectF(
                self.expand_btn.pos().x() - 16, self.expand_btn.pos().y() - 16, 32, 32
            ))
            rect.setRight(rect.right() + 40)
            rect.setBottom(rect.bottom() + 40)
            return rect
        except Exception as ex:
            print_terminal(f"Error in RefMindMapNode.boundingRect: {ex}")
            return QRectF(0, 0, 1, 1)

    def paint(self, painter, option, widget):
        """
        Paint the node, including highlight and expanded details.
        """
        try:
            self._update_box_size()
            painter.setRenderHint(QPainter.Antialiasing)
            shadow_path = QPainterPath()
            shadow_path.addRoundedRect(self._box_rect.translated(4, 6), 14, 14)
            painter.setBrush(QColor(0, 0, 0, 90))
            painter.setPen(Qt.NoPen)
            painter.drawPath(shadow_path)
            path = QPainterPath()
            path.addRoundedRect(self._box_rect, 14, 14)
            # Highlight if search matched
            if self.highlighted:
                painter.setBrush(QColor(255, 255, 180))  # light yellow
                painter.setPen(QPen(QColor(200, 180, 60), 4))
            elif self.is_root:
                painter.setBrush(QColor(120, 180, 255))
                painter.setPen(QPen(QColor(50, 90, 180), 3))
            else:
                painter.setBrush(QColor(48, 54, 72))
                painter.setPen(QPen(QColor(90, 120, 180), 2))
            painter.drawPath(path)
            painter.setPen(QColor(0, 0, 0) if self.is_root or self.highlighted else QColor(255, 255, 255))
            painter.setFont(self.font)
            metrics = QFontMetrics(self.font)
            text_width = metrics.horizontalAdvance(self.file_name)
            painter.drawText(
                QPointF(self._box_rect.left() + (self._box_rect.width() - text_width) / 2,
                        self._box_rect.top() + self._padding + metrics.ascent()),
                self.file_name
            )
            if self._expanded:
                painter.setFont(QFont("Segoe UI", 10))
                painter.setPen(QColor(180, 210, 255, 245))
                painter.drawText(
                    QPointF(self._box_rect.left() + self._padding,
                            self._box_rect.bottom() + 40),
                    self.file_path
                )
        except Exception as ex:
            print_terminal(f"Error in RefMindMapNode.paint: {ex}")

    def toggle_expand(self):
        """
        Toggle the expanded/collapsed state of the node.
        """
        try:
            self._expanded = not self._expanded
            self.update()
            if self.scene():
                self.scene().update()
        except Exception as ex:
            print_terminal(f"Error in RefMindMapNode.toggle_expand: {ex}")

    def _create_toggle_buttons(self):
        """
        Create toggle buttons for Displayed, Snap, and Locate properties.
        """
        try:
            self._remove_toggle_buttons()
            displayed_state = self.model_ref.IsDisplayed() if hasattr(self.model_ref, "IsDisplayed") else True
            snap_state = self.model_ref.IsSnapLocked() if hasattr(self.model_ref, "IsSnapLocked") else True
            locate_state = self.model_ref.IsLocateLocked() if hasattr(self.model_ref, "IsLocateLocked") else True
            color_on = QColor(120, 220, 120)
            color_off = QColor(200, 200, 200)
            snap_on = QColor(120, 180, 255)
            snap_off = QColor(200, 200, 200)
            locate_on = QColor(255, 220, 120)
            locate_off = QColor(200, 200, 200)
            self.toggle_buttons = [
                ToggleButton("Displayed", color_on, color_off, self._defer_displayed_toggle, displayed_state, self),
                ToggleButton("Snap", snap_on, snap_off, self._defer_snap_toggle, snap_state, self),
                ToggleButton("Locate", locate_on, locate_off, self._defer_locate_toggle, locate_state, self)
            ]
            for btn in self.toggle_buttons:
                btn.setParentItem(self)
            self._update_box_size()
        except Exception as ex:
            print_terminal(f"Error in RefMindMapNode._create_toggle_buttons: {ex}")

    def _remove_toggle_buttons(self):
        """
        Remove all toggle buttons from the node.
        """
        try:
            for btn in self.toggle_buttons:
                btn.setParentItem(None)
                if self.scene():
                    self.scene().removeItem(btn)
            self.toggle_buttons = []
        except Exception as ex:
            print_terminal(f"Error in RefMindMapNode._remove_toggle_buttons: {ex}")

    def _defer_displayed_toggle(self, state):
        """
        Defer the action of toggling the Displayed property.
        """
        deferred_queue.add(self._on_displayed_toggle, state)

    def _defer_snap_toggle(self, state):
        """
        Defer the action of toggling the Snap property.
        """
        deferred_queue.add(self._on_snap_toggle, state)

    def _defer_locate_toggle(self, state):
        """
        Defer the action of toggling the Locate property.
        """
        deferred_queue.add(self._on_locate_toggle, state)

    def _on_displayed_toggle(self, state):
        """
        Toggle the Displayed property and update downstream nodes.
        """
        try:
            if hasattr(self.model_ref, "SetIsDisplayed"):
                self.model_ref.SetIsDisplayed(state, True, True)
                self.model_ref.WriteToModel()
                print_terminal(f"Displayed set to {state} for {self.file_name}")
                self.set_downstream_display_enabled(state)
                refresh_all_views()
        except Exception as ex:
            print_terminal(f"Displayed toggle error: {ex}")

    def set_downstream_display_enabled(self, enabled):
        """
        Enable or disable the Displayed button for all downstream (child) nodes.
        """
        for child in self.children:
            display_btn = child.toggle_buttons[0]
            display_btn.setEnabled(enabled)
            if not enabled:
                child.set_downstream_display_enabled(False)
            else:
                parent_displayed = True
                if child.parent_node:
                    parent_displayed = child.parent_node.toggle_buttons[0].state
                if parent_displayed:
                    child.set_downstream_display_enabled(True)

    def _on_snap_toggle(self, state):
        """
        Toggle the Snap property for this reference.
        """
        try:
            if hasattr(self.model_ref, "SetSnapLock"):
                self.model_ref.SetSnapLock(state)
                self.model_ref.WriteToModel()
                print_terminal(f"Snap set to {state} for {self.file_name}")
                synchronize_reference_dialog()
        except Exception as ex:
            print_terminal(f"Snap toggle error: {ex}")

    def _on_locate_toggle(self, state):
        """
        Toggle the Locate property for this reference.
        """
        try:
            if hasattr(self.model_ref, "SetLocateLock"):
                self.model_ref.SetLocateLock(state)
                self.model_ref.WriteToModel()
                print_terminal(f"Locate set to {state} for {self.file_name}")
                synchronize_reference_dialog()
        except Exception as ex:
            print_terminal(f"Locate toggle error: {ex}")

    def set_highlight(self, highlight):
        """
        Set whether this node is highlighted (e.g., by search).
        """
        self.highlighted = highlight
        self.update()

class RefMindMapEdge(QGraphicsItem):
    """
    QGraphicsItem representing an edge (connection) between two nodes in the mind map.
    """
    def __init__(self, node_from, node_to):
        super().__init__()
        self.node_from = node_from
        self.node_to = node_to
        self.setZValue(-1)

    def boundingRect(self):
        """
        Return the bounding rectangle of the edge.
        """
        try:
            p1 = self.node_from.scenePos() + self.node_from._box_rect.center()
            p2 = self.node_to.scenePos() + self.node_to._box_rect.center()
            return QRectF(p1, p2).normalized().adjusted(-12, -12, 12, 12)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapEdge.boundingRect: {ex}")
            return QRectF(0, 0, 1, 1)

    def paint(self, painter, option, widget):
        """
        Paint the edge as a cubic Bezier curve with a shadow.
        """
        try:
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
        except Exception as ex:
            print_terminal(f"Error in RefMindMapEdge.paint: {ex}")

class RefMindMapScene(QGraphicsScene):
    """
    QGraphicsScene subclass for managing the mind map nodes and edges.
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        self.nodes = {}
        self.edges = []
        self.node_positions = {}
        self.padding = 24

    def build_map(self, root_model):
        """
        Build the mind map starting from the root model reference.
        """
        try:
            self.clear()
            self.nodes = {}
            self.edges = []
            self.node_positions = {}

            def add_node(model_ref, parent_node, depth, y_offset):
                file_name, file_path = self.get_file_info(model_ref)
                node = RefMindMapNode(file_name, file_path, model_ref, self, is_root=(parent_node is None))
                node.parent_node = parent_node
                if parent_node:
                    parent_node.children.append(node)
                x = depth * 420
                y = y_offset[0]
                node.setPos(x, y)
                self.addItem(node)
                self.nodes[model_ref] = node
                self.node_positions[model_ref] = node.pos()
                if parent_node:
                    edge = RefMindMapEdge(parent_node, node)
                    self.addItem(edge)
                    self.edges.append(edge)
                attachments = []
                try:
                    attachments = list(model_ref.GetDgnAttachments())
                except Exception:
                    pass
                spacing_y = 180
                for i, child_ref in enumerate(attachments):
                    y_offset[0] += spacing_y
                    add_node(child_ref, node, depth + 1, y_offset)

            y_offset = [0]
            add_node(root_model, None, 0, y_offset)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapScene.build_map: {ex}")

    def get_file_info(self, model_ref):
        """
        Get the file name and full path for a model reference.
        Returns:
            tuple: (base_name, file_path)
        """
        try:
            file_name = model_ref.GetDgnFile().GetFileName()
            if hasattr(file_name, 'GetWCharCP'):
                file_path = file_name.GetWCharCP()
            else:
                file_path = str(file_name)
            base_name = os.path.basename(file_path)
            return base_name, file_path
        except Exception as ex:
            print_terminal(f"Error in RefMindMapScene.get_file_info: {ex}")
            return "Unknown", "Unknown"

    def search_and_highlight(self, search_text):
        """
        Highlight nodes whose file name matches the search text.
        Returns:
            int: Number of matches found.
        """
        # Remove previous highlights
        for node in self.nodes.values():
            node.set_highlight(False)
        if not search_text:
            return 0
        count = 0
        search_text = search_text.lower()
        for node in self.nodes.values():
            if search_text in node.file_name.lower():
                node.set_highlight(True)
                count += 1
        self.update()
        return count

    def get_highlighted_nodes_bounding_rect(self):
        """
        Get the bounding rectangle of all highlighted nodes.
        Returns:
            QRectF or None: Bounding rect if any highlighted nodes, else None.
        """
        rect = None
        for node in self.nodes.values():
            if node.highlighted:
                node_rect = node.mapToScene(node.boundingRect()).boundingRect()
                if rect is None:
                    rect = node_rect
                else:
                    rect = rect.united(node_rect)
        return rect

class RefMindMapGraphicsView(QGraphicsView):
    """
    QGraphicsView subclass for displaying the mind map scene.
    Supports zooming, panning, and fitting to extents.
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setScene(RefMindMapScene(self))
        self.setRenderHint(QPainter.Antialiasing)
        self.setMinimumWidth(700)
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

    def build_map(self, root_model):
        """
        Build the mind map for the given root model.
        """
        try:
            self.scene().build_map(root_model)
            QTimer.singleShot(0, self.fit_to_screen)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.build_map: {ex}")

    def fit_to_screen(self):
        """
        Fit the view to show all items in the scene.
        """
        try:
            if self.scene().items():
                self.setTransformationAnchor(QGraphicsView.AnchorViewCenter)
                self.setTransform(QPainter().transform())
                self._zoom = 1.0
                self.fitInView(self.scene().itemsBoundingRect(), Qt.KeepAspectRatio)
                self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.fit_to_screen: {ex}")

    def fit_to_highlighted(self):
        """
        Fit the view to show only the highlighted nodes.
        """
        try:
            rect = self.scene().get_highlighted_nodes_bounding_rect()
            if rect and not rect.isNull():
                self.setTransformationAnchor(QGraphicsView.AnchorViewCenter)
                self.setTransform(QPainter().transform())
                self._zoom = 1.0
                self.fitInView(rect, Qt.KeepAspectRatio)
                self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.fit_to_highlighted: {ex}")

    def wheelEvent(self, event):
        """
        Zoom in/out with the mouse wheel.
        """
        try:
            self.setTransformationAnchor(QGraphicsView.AnchorUnderMouse)
            zoomInFactor = 1.15
            zoomOutFactor = 1 / zoomInFactor
            if event.angleDelta().y() > 0:
                zoomFactor = zoomInFactor
            else:
                zoomFactor = zoomOutFactor
            self._zoom *= zoomFactor
            self.scale(zoomFactor, zoomFactor)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.wheelEvent: {ex}")

    def mousePressEvent(self, event):
        """
        Start panning with middle mouse button.
        """
        try:
            if event.button() == Qt.MiddleButton:
                self._pan = True
                self.setCursor(Qt.ClosedHandCursor)
                self._pan_start = event.pos()
                self._pan_start_center = self.mapToScene(self.viewport().rect().center())
            else:
                super().mousePressEvent(event)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.mousePressEvent: {ex}")

    def mouseMoveEvent(self, event):
        """
        Pan the view if panning is active.
        """
        try:
            if self._pan:
                delta = self.mapToScene(event.pos()) - self.mapToScene(self._pan_start)
                new_center = self._pan_start_center - delta
                self.centerOn(new_center)
            else:
                super().mouseMoveEvent(event)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.mouseMoveEvent: {ex}")

    def mouseReleaseEvent(self, event):
        """
        Stop panning on mouse release.
        """
        try:
            if event.button() == Qt.MiddleButton:
                self._pan = False
                self.setCursor(Qt.ArrowCursor)
            else:
                super().mouseReleaseEvent(event)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapGraphicsView.mouseReleaseEvent: {ex}")

class RefMindMapWidget(QWidget):
    """
    QWidget containing the mind map view and search/zoom controls.
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        self.view = RefMindMapGraphicsView(self)
        layout = QVBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(0)
        btn_layout = QHBoxLayout()
        btn_layout.addStretch(1)
        self.zoom_extents_btn = QPushButton("Zoom Extents")
        self.zoom_extents_btn.clicked.connect(self.zoom_extents)
        btn_layout.addWidget(self.zoom_extents_btn)

        # --- Search UI ---
        self.search_edit = QLineEdit()
        self.search_edit.setPlaceholderText("Search reference file name...")
        self.search_edit.textChanged.connect(self.do_search_dynamic)
        self.search_edit.setClearButtonEnabled(True)  # Show X button to clear

        self.search_btn = QPushButton("Search")
        self.search_btn.clicked.connect(self.do_search)

        self.zoom_to_search_btn = QPushButton("Zoom to Search")
        self.zoom_to_search_btn.clicked.connect(self.zoom_to_search)

        btn_layout.addWidget(self.search_edit)
        btn_layout.addWidget(self.search_btn)
        btn_layout.addWidget(self.zoom_to_search_btn)
        layout.addLayout(btn_layout)
        layout.addWidget(self.view)
        self.setLayout(layout)

    def build_map(self, root_model):
        """
        Build the mind map for the given root model.
        """
        try:
            self.view.build_map(root_model)
        except Exception as ex:
            print_terminal(f"Error in RefMindMapWidget.build_map: {ex}")

    def fit_to_screen(self):
        """
        Fit the view to show all items.
        """
        try:
            self.view.fit_to_screen()
        except Exception as ex:
            print_terminal(f"Error in RefMindMapWidget.fit_to_screen: {ex}")

    def zoom_extents(self):
        """
        Zoom to show all nodes in the mind map.
        """
        self.fit_to_screen()

    def do_search(self):
        """
        Perform a search for reference file names and highlight matches.
        """
        search_text = self.search_edit.text()
        count = self.view.scene().search_and_highlight(search_text)
        if count == 0 and search_text:
            print_terminal(f"No references found matching '{search_text}'.")
        elif search_text:
            print_terminal(f"Found {count} reference(s) matching '{search_text}'.")

    def do_search_dynamic(self):
        """
        Dynamically highlight nodes as the user types in the search box.
        """
        search_text = self.search_edit.text()
        if len(search_text) > 0:
            self.view.scene().search_and_highlight(search_text)
        else:
            self.view.scene().search_and_highlight("")
        # No print_terminal output for dynamic search

    def zoom_to_search(self):
        """
        Zoom the view to fit highlighted (searched) nodes.
        """
        self.view.fit_to_highlighted()

class ReferenceMapDialog(QDialog):
    """
    Main dialog for the Reference File Mind Map application.
    """
    def __init__(self, parent=None):
        super().__init__(parent)
        try:
            self.setWindowTitle("Reference File Mind Map")
            self.setWindowFlags(self.windowFlags() | Qt.WindowStaysOnTopHint)
            self.setMinimumWidth(1400)
            self.setMinimumHeight(900)
            layout = QVBoxLayout(self)
            self.setLayout(layout)

            self.mind_map = RefMindMapWidget()
            layout.addWidget(self.mind_map)

            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
            if ACTIVEMODEL is None:
                label = QLabel("No active DGN model found.")
                layout.addWidget(label)
                return

            self.mind_map.build_map(ACTIVEMODEL)
            QTimer.singleShot(0, self.mind_map.fit_to_screen)

            self.timer = QTimer(self)
            self.timer.setInterval(100)
            self.timer.timeout.connect(self.process_deferred_actions)
            self.timer.start()
        except Exception as ex:
            print_terminal(f"Error in ReferenceMapDialog.__init__: {ex}")
            exit_gracefully("Script exited due to error in ReferenceMapDialog.__init__.")

    def process_deferred_actions(self):
        """
        Process any deferred MicroStation API actions.
        """
        try:
            deferred_queue.process()
        except Exception as ex:
            print_terminal(f"Error in ReferenceMapDialog.process_deferred_actions: {ex}")

    def closeEvent(self, event):
        """
        Handle dialog close event and clean up.
        """
        try:
            cleanup_dialog()
            event.accept()
        except Exception as ex:
            print_terminal(f"Error in ReferenceMapDialog.closeEvent: {ex}")

def show_reference_map_dialog():
    """
    Show the Reference File Mind Map dialog, creating it if necessary.
    """
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
        _dialog_instance = ReferenceMapDialog()
        _dialog_instance.show()
        print_terminal("ReferenceMapDialog shown.")
    except Exception as ex:
        print_terminal(f"Error in show_reference_map_dialog: {ex}")
        exit_gracefully("Script exited due to error in show_reference_map_dialog.")

show_reference_map_dialog()