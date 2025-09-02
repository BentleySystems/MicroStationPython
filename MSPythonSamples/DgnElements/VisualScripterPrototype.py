# -----------------------------------------------------------------------------
# Script Description:
#
# This script implements a node-based visual scripting tool using Tkinter for the
# user interface and the MicroStation Python API for geometry creation. Users can
# add, connect, and interact with various node types (such as numeric input,
# math operations, value display, series, circle creation, and sliders) on a canvas.
# Nodes can be connected via "wires" (lines), and data flows from output connectors
# to input connectors. The tool supports dynamic updates, node movement, and deletion
# (with all associated wires) via right-click. Circles are created in the active
# MicroStation model using the MicroStation Python API when triggered from the UI.
# Feel free to build upon this prototype
# -----------------------------------------------------------------------------

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
import tkinter as tk
from tkinter import ttk

# Base class for all node types
class Node:
    def __init__(self, canvas, x, y, text, app, color):
        self.canvas = canvas
        self.app = app
        # Draw the node rectangle and label
        self.id = canvas.create_rectangle(x, y, x+180, y+180, fill=color)
        self.text_id = canvas.create_text(x+90, y+10, text=text)  # Centered text

        # Create input and output connectors (ovals)
        self.input_connector = canvas.create_oval(x+5, y+70, x+15, y+80, fill="green")
        self.output_connector = canvas.create_oval(x+165, y+70, x+175, y+80, fill="red")

        # Bind mouse events for moving and connecting nodes
        for item in [self.id, self.text_id, self.input_connector, self.output_connector]:
            self.canvas.tag_bind(item, "<ButtonPress-1>", self.on_press)
            self.canvas.tag_bind(item, "<B1-Motion>", self.on_drag)

        self.canvas.tag_bind(self.input_connector, "<ButtonPress-1>", self.on_connector_click)
        self.canvas.tag_bind(self.output_connector, "<ButtonPress-1>", self.on_connector_click)

        self.x = x
        self.y = y
        # Store all canvas elements for this node
        self.elements = [self.id, self.text_id, self.input_connector, self.output_connector]

    # Store mouse position on press
    def on_press(self, event):
        self.x = event.x
        self.y = event.y

    # Move all node elements on drag
    def on_drag(self, event):
        dx = event.x - self.x
        dy = event.y - self.y
        for item in self.elements:
            self.canvas.move(item, dx, dy)
        self.x = event.x
        self.y = event.y
        self.app.update_connections()

    # Handle connector click for wiring nodes
    def on_connector_click(self, event):
        connector_id = self.canvas.find_closest(event.x, event.y)[0]
        self.app.handle_connector_click(connector_id)

# Node for generating a numeric series
class SeriesNode(Node):
    def __init__(self, canvas, x, y, app):
        super().__init__(canvas, x, y, "Series", app, "lightgoldenrod")

        # Create labels and entry fields for start, end, increment
        self.start_label = tk.Label(canvas, text="Start:")
        self.end_label = tk.Label(canvas, text="End:")
        self.increment_label = tk.Label(canvas, text="Increment:")

        self.start_entry = tk.Entry(canvas, width=10)
        self.end_entry = tk.Entry(canvas, width=10)
        self.increment_entry = tk.Entry(canvas, width=10)

        # Place widgets on the canvas
        self.start_label_window = canvas.create_window(x+60, y+40, window=self.start_label)
        self.start_window = canvas.create_window(x+120, y+40, window=self.start_entry)

        self.end_label_window = canvas.create_window(x+60, y+70, window=self.end_label)
        self.end_window = canvas.create_window(x+120, y+70, window=self.end_entry)

        self.increment_label_window = canvas.create_window(x+60, y+100, window=self.increment_label)
        self.increment_window = canvas.create_window(x+120, y+100, window=self.increment_entry)

        # Add input connectors for start, end, and increment
        self.start_connector = canvas.create_oval(x+5, y+40, x+15, y+50, fill="green")
        self.end_connector = canvas.create_oval(x+5, y+70, x+15, y+80, fill="green")
        self.increment_connector = canvas.create_oval(x+5, y+100, x+15, y+110, fill="green")

        # Add all elements to the node's element list
        self.elements.extend([
            self.start_label_window, self.start_window,
            self.end_label_window, self.end_window,
            self.increment_label_window, self.increment_window,
            self.start_connector, self.end_connector, self.increment_connector
        ])

        # Bind connector clicks for wiring
        for connector in [self.start_connector, self.end_connector, self.increment_connector]:
            self.canvas.tag_bind(connector, "<ButtonPress-1>", self.on_connector_click)

    # Generate a comma-separated series string from the entry fields
    def generate_series(self):
        try:
            start = float(self.start_entry.get())
            end = float(self.end_entry.get())
            increment = float(self.increment_entry.get())
            series = [str(value) for value in self._frange(start, end, increment)]
            return ','.join(series)
        except ValueError:
            return ""

    # Helper for floating-point range
    def _frange(self, start, end, step):
        while start <= end:
            yield start
            start += step

# Node for creating circles in MicroStation
class CircleNode(Node):
    def __init__(self, canvas, x, y, app):
        super().__init__(canvas, x, y, "Circle Node", app, "magenta")

        # Add input connectors for center x, center y, and radius
        self.center_x_connector = canvas.create_oval(x+5, y+40, x+15, y+50, fill="green")
        self.center_y_connector = canvas.create_oval(x+5, y+70, x+15, y+80, fill="green")
        self.radius_connector = canvas.create_oval(x+5, y+100, x+15, y+110, fill="green")

        # Create labels and entry fields for parameters
        self.center_x_label = tk.Label(canvas, text="Center X:")
        self.center_y_label = tk.Label(canvas, text="Center Y:")
        self.radius_label = tk.Label(canvas, text="Radius:")

        self.center_x_entry = tk.Entry(canvas, width=10)
        self.center_y_entry = tk.Entry(canvas, width=10)
        self.radius_entry = tk.Entry(canvas, width=10)

        # Place widgets on the canvas
        self.center_x_label_window = canvas.create_window(x+60, y+40, window=self.center_x_label)
        self.center_x_window = canvas.create_window(x+120, y+40, window=self.center_x_entry)

        self.center_y_label_window = canvas.create_window(x+60, y+70, window=self.center_y_label)
        self.center_y_window = canvas.create_window(x+120, y+70, window=self.center_y_entry)

        self.radius_label_window = canvas.create_window(x+60, y+100, window=self.radius_label)
        self.radius_window = canvas.create_window(x+120, y+100, window=self.radius_entry)

        # Create button to trigger circle creation
        self.create_button = tk.Button(canvas, text="Create Circle", command=self.create_circle)
        self.create_button_window = canvas.create_window(x+90, y+140, window=self.create_button)

        # Add all elements to the node's element list
        self.elements.extend([
            self.center_x_connector, self.center_y_connector, self.radius_connector,
            self.center_x_label_window, self.center_x_window,
            self.center_y_label_window, self.center_y_window,
            self.radius_label_window, self.radius_window,
            self.create_button_window
        ])

        self.created_elements = []  # Track created MicroStation elements

        # Bind connector clicks for wiring
        for connector in [self.center_x_connector, self.center_y_connector, self.radius_connector]:
            self.canvas.tag_bind(connector, "<ButtonPress-1>", self.on_connector_click)

    # Create circles in the active MicroStation model based on entry values
    def create_circle(self):
        try:
            # Remove previously created elements from the model
            for element in self.created_elements:
                element.DeleteFromModel()
            self.created_elements.clear()

            center_x_values = self.center_x_entry.get().split(',')
            center_y_values = self.center_y_entry.get().split(',')
            radius_values = self.radius_entry.get().split(',')

            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
            dgnModel = ACTIVEMODEL.GetDgnModel()
            modelInfo = dgnModel.GetModelInfo()
            __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)

            # Ensure all lists have the same length by repeating the last value if necessary
            max_length = max(len(center_x_values), len(center_y_values), len(radius_values))
            center_x_values = self._extend_list(center_x_values, max_length)
            center_y_values = self._extend_list(center_y_values, max_length)
            radius_values = self._extend_list(radius_values, max_length)

            for center_x, center_y, radius in zip(center_x_values, center_y_values, radius_values):
                centerPoint = DPoint3d(float(center_x), float(center_y), 0)
                centerPoint.Scale(uorPerMast)
                radius_scaled = float(radius) * uorPerMast

                ellipse = DEllipse3d.FromCenterRadiusXY(centerPoint, radius_scaled)
                eeh = EditElementHandle()
                status = EllipseHandler.CreateEllipseElement(eeh, None, ellipse, ACTIVEMODEL.Is3d(), ACTIVEMODEL)

                if BentleyStatus.eSUCCESS == status:
                    eeh.AddToModel()
                    self.created_elements.append(eeh)  # Track the created element
                    print(f"Circle created at ({center_x}, {center_y}) with radius {radius}.")
                else:
                    print("Failed to create circle.")

        except ValueError:
            print("Invalid input values.")

    # Helper to extend lists to the same length
    def _extend_list(self, lst, length):
        if len(lst) < length:
            lst.extend([lst[-1]] * (length - len(lst)))
        return lst

# Node for numeric input
class NumericInputNode(Node):
    def __init__(self, canvas, x, y, app):
        super().__init__(canvas, x, y, "Numeric Input", app, "lightyellow")
        # Entry for numeric value
        self.entry = tk.Entry(canvas, width=10)
        self.entry_window = canvas.create_window(x+90, y+90, window=self.entry)  # Centered
        self.elements.append(self.entry_window)

    # Move all elements on drag
    def on_drag(self, event):
        dx = event.x - self.x
        dy = event.y - self.y
        for item in self.elements:
            self.canvas.move(item, dx, dy)
        self.x = event.x
        self.y = event.y
        self.app.update_connections()

# Node for math operations (+, -, *, /)
class MathOperationNode(Node):
    def __init__(self, canvas, x, y, app):
        super().__init__(canvas, x, y, "Math Operation", app, "lightblue")
        # Second input connector for binary operations
        self.input_connector2 = canvas.create_oval(x+5, y+35, x+15, y+45, fill="green")
        # Display result
        self.result_text = canvas.create_text(x+90, y+120, text="Result: ")  # Centered
        # Dropdown for operation selection
        self.operation_var = tk.StringVar(value="+")
        self.operation_menu = ttk.Combobox(canvas, textvariable=self.operation_var, values=["+", "-", "*", "/"], width=3)
        self.operation_menu_window = canvas.create_window(x+90, y+60, window=self.operation_menu)  # Centered

        # Bind events for moving and connecting
        for item in [self.input_connector2, self.result_text]:
            self.canvas.tag_bind(item, "<ButtonPress-1>", self.on_press)
            self.canvas.tag_bind(item, "<B1-Motion>", self.on_drag)

        self.canvas.tag_bind(self.input_connector2, "<ButtonPress-1>", self.on_connector_click)

        # Add all elements to the node's element list
        self.elements.extend([self.input_connector2, self.result_text, self.operation_menu_window])

    # Move all elements on drag
    def on_drag(self, event):
        dx = event.x - self.x
        dy = event.y - self.y
        for item in self.elements:
            self.canvas.move(item, dx, dy)
        self.x = event.x
        self.y = event.y
        self.app.update_connections()

    # Calculate and display result based on inputs and selected operation
    def calculate_result(self, input1, input2):
        try:
            num1 = float(input1)
            num2 = float(input2)
            op = self.operation_var.get()
            result = {
                "+": num1 + num2,
                "-": num1 - num2,
                "*": num1 * num2,
                "/": num1 / num2 if num2 != 0 else "∞"
            }.get(op, "Err")
            self.canvas.itemconfig(self.result_text, text=f"Result: {result}")
        except:
            self.canvas.itemconfig(self.result_text, text="Result: Error")

# Node for displaying a value
class ValueDisplayNode(Node):
    def __init__(self, canvas, x, y, app):
        super().__init__(canvas, x, y, "Value Display", app, "lightgreen")
        # Display value text
        self.value_text = canvas.create_text(x+90, y+90, text="Value: ")  # Centered
        self.elements.append(self.value_text)

    # Move all elements on drag
    def on_drag(self, event):
        dx = event.x - self.x
        dy = event.y - self.y
        for item in self.elements:
            self.canvas.move(item, dx, dy)
        self.x = event.x
        self.y = event.y
        self.app.update_connections()

    # Update displayed value
    def display_value(self, value):
        self.canvas.itemconfig(self.value_text, text=f"Value: {value}")

# Node for slider input
class SliderNode(Node):
    def __init__(self, canvas, x, y, app):
        super().__init__(canvas, x, y, "Slider Node", app, "lightcoral")
        # Horizontal slider
        self.slider = tk.Scale(canvas, from_=0, to=100, orient=tk.HORIZONTAL, length=120)
        self.slider_window = canvas.create_window(x+90, y+90, window=self.slider)
        self.elements.append(self.slider_window)
    # Move all elements on drag
    def on_drag(self, event):
        dx = event.x - self.x
        dy = event.y - self.y
        for item in self.elements:
            self.canvas.move(item, dx, dy)
        self.x = event.x
        self.y = event.y
        self.app.update_connections()

# Main application class for the visual scripting tool
class VisualScriptingApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Visual Scripting Tool")
        # Main canvas for node layout
        self.canvas = tk.Canvas(root, width=800, height=600, bg="white")
        self.canvas.pack(fill=tk.BOTH, expand=True)

        # Toolbar for adding nodes and running the script
        self.button_frame = tk.Frame(root)
        self.button_frame.pack(side=tk.TOP, fill=tk.X, padx=5, pady=5)

        # Node creation buttons
        tk.Button(self.button_frame, text="Numeric Input", bg="lightyellow", command=lambda: self.add_node("Numeric Input")).pack(side=tk.LEFT, padx=5)
        tk.Button(self.button_frame, text="Math Operation", bg="lightblue", command=lambda: self.add_node("Math Operation")).pack(side=tk.LEFT, padx=5)
        tk.Button(self.button_frame, text="Value Display", bg="lightgreen", command=lambda: self.add_node("Value Display")).pack(side=tk.LEFT, padx=5)
        tk.Button(self.button_frame, text="Circle Node", bg="magenta", command=lambda: self.add_node("Circle Node")).pack(side=tk.LEFT, padx=5)
        tk.Button(self.button_frame, text="Slider Node", bg="lightcoral", command=lambda: self.add_node("Slider Node")).pack(side=tk.LEFT, padx=5)
        tk.Button(self.button_frame, text="Series Node", bg="lightgoldenrod", command=lambda: self.add_node("Series Node")).pack(side=tk.LEFT, padx=5)

        # Run button
        tk.Button(self.button_frame, text="Run", command=self.run).pack(side=tk.RIGHT, padx=5)

        self.nodes = []  # List of all nodes
        self.connections = []  # List of (start_connector_id, end_connector_id, line_id)
        self.start_connector = None  # For wiring nodes interactively

        # Bind right-click for node/connection deletion
        self.canvas.bind("<Button-3>", self.on_right_click)

    # Add a node of the specified type to the canvas
    def add_node(self, node_type=None):
        if node_type is None:
            node_type = "Numeric Input"  # Default node type if none specified
        if node_type == "Numeric Input":
            node = NumericInputNode(self.canvas, 50, 50, self)
        elif node_type == "Math Operation":
            node = MathOperationNode(self.canvas, 50, 50, self)
        elif node_type == "Value Display":
            node = ValueDisplayNode(self.canvas, 50, 50, self)
        elif node_type == "Circle Node":
            node = CircleNode(self.canvas, 50, 50, self)
        elif node_type == "Slider Node":
            node = SliderNode(self.canvas, 50, 50, self)
        elif node_type == "Series Node":
            node = SeriesNode(self.canvas, 50, 50, self)
        self.nodes.append(node)

    # Handle connector click for wiring nodes
    def handle_connector_click(self, connector_id):
        if self.start_connector is None:
            self.start_connector = connector_id
        else:
            self.create_connection(self.start_connector, connector_id)
            self.start_connector = None

    # Create a wire (line) between two connectors
    def create_connection(self, start_id, end_id):
        x1, y1 = self._center(self.canvas.coords(start_id))
        x2, y2 = self._center(self.canvas.coords(end_id))
        line = self.canvas.create_line(x1, y1, x2, y2, fill="black")
        self.connections.append((start_id, end_id, line))
        self.update_connections()

    # Update all wires and propagate values through the graph
    def update_connections(self):
        for start_id, end_id, line_id in self.connections:
            x1, y1 = self._center(self.canvas.coords(start_id))
            x2, y2 = self._center(self.canvas.coords(end_id))
            self.canvas.coords(line_id, x1, y1, x2, y2)
        self.update_math_operations()
        self.update_series_parameters()
        self.update_circle_parameters()
        self.update_value_display()

    # Update math operation nodes with new input values
    def update_math_operations(self):
        for node in self.nodes:
            if isinstance(node, MathOperationNode):
                input1 = self.get_connected_value(node.input_connector)
                input2 = self.get_connected_value(node.input_connector2)
                if input1 is not None and input2 is not None:
                    node.calculate_result(input1, input2)

    # Update series node parameters from connections
    def update_series_parameters(self):
        for node in self.nodes:
            if isinstance(node, SeriesNode):
                start_value = self.get_connected_value(node.start_connector)
                end_value = self.get_connected_value(node.end_connector)
                increment_value = self.get_connected_value(node.increment_connector)
                if start_value is not None:
                    node.start_entry.delete(0, tk.END)
                    node.start_entry.insert(0, start_value)
                if end_value is not None:
                    node.end_entry.delete(0, tk.END)
                    node.end_entry.insert(0, end_value)
                if increment_value is not None:
                    node.increment_entry.delete(0, tk.END)
                    node.increment_entry.insert(0, increment_value)

    # Update circle node parameters from connections
    def update_circle_parameters(self):
        for node in self.nodes:
            if isinstance(node, CircleNode):
                center_x_value = self.get_connected_value(node.center_x_connector)
                center_y_value = self.get_connected_value(node.center_y_connector)
                radius_value = self.get_connected_value(node.radius_connector)
                if center_x_value is not None:
                    node.center_x_entry.delete(0, tk.END)
                    node.center_x_entry.insert(0, center_x_value)
                if center_y_value is not None:
                    node.center_y_entry.delete(0, tk.END)
                    node.center_y_entry.insert(0, center_y_value)
                if radius_value is not None:
                    node.radius_entry.delete(0, tk.END)
                    node.radius_entry.insert(0, radius_value)

    # Update value display nodes from connections
    def update_value_display(self):
        for node in self.nodes:
            if isinstance(node, ValueDisplayNode):
                value = self.get_connected_value(node.input_connector)
                if value is not None:
                    node.display_value(value)

    # Get the value from the node connected to the given connector
    def get_connected_value(self, connector):
        for start_id, end_id, _ in self.connections:
            if end_id == connector:
                for node in self.nodes:
                    if isinstance(node, NumericInputNode) and node.output_connector == start_id:
                        return node.entry.get()
                    elif isinstance(node, MathOperationNode) and node.output_connector == start_id:
                        return node.canvas.itemcget(node.result_text, "text").split(": ")[1]
                    elif isinstance(node, ValueDisplayNode) and node.output_connector == start_id:
                        return node.canvas.itemcget(node.value_text, "text").split(": ")[1]
                    elif isinstance(node, SliderNode) and node.output_connector == start_id:
                        return str(node.slider.get())
                    elif isinstance(node, SeriesNode) and node.output_connector == start_id:
                        return node.generate_series()
        return None

    # Helper to get the center of a canvas item
    def _center(self, coords):
        return (coords[0] + coords[2]) / 2, (coords[1] + coords[3]) / 2

    # Handle right-click for deleting nodes or connections
    def on_right_click(self, event):
        clicked_item = self.canvas.find_closest(event.x, event.y)
        if clicked_item:
            item_type = self.canvas.type(clicked_item)
            if item_type == "rectangle":
                self.delete_node(clicked_item[0])
            elif item_type == "line":
                self.delete_connection(clicked_item[0])

    # Delete a node and all associated wires and elements
    def delete_node(self, node_id):
        node_to_delete = None
        for node in self.nodes:
            if node.id == node_id:
                node_to_delete = node
                break
        if node_to_delete:
            # Remove all connections (wires) attached to any of this node's connectors
            connectors = set()
            for attr in dir(node_to_delete):
                if attr.endswith("_connector") or attr.endswith("_connectors"):
                    val = getattr(node_to_delete, attr)
                    if isinstance(val, list) or isinstance(val, tuple):
                        connectors.update(val)
                    else:
                        connectors.add(val)
            # Also add the standard connectors
            connectors.add(node_to_delete.input_connector)
            connectors.add(node_to_delete.output_connector)
            # Remove connections
            new_connections = []
            for start, end, line in self.connections:
                if start in connectors or end in connectors:
                    self.canvas.delete(line)
                else:
                    new_connections.append((start, end, line))
            self.connections = new_connections
            # Remove all canvas elements for this node
            for element in node_to_delete.elements:
                self.canvas.delete(element)
            self.nodes.remove(node_to_delete)
            self.update_connections()

    # Delete a connection (wire) by line id
    def delete_connection(self, line_id):
        self.connections = [(start, end, line) for start, end, line in self.connections if line != line_id]
        self.canvas.delete(line_id)

    # Run the script: propagate all values and update all nodes
    def run(self):
        self.update_math_operations()
        self.update_series_parameters()
        self.update_circle_parameters()
        self.update_value_display()

# Entry point: start the Tkinter main loop and launch the app
if __name__ == "__main__":
    root = tk.Tk()
    app = VisualScriptingApp(root)
    root.mainloop()