# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import sys
import time
import random
import win32gui
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtCore import Qt
from PyQt5.QtCore import pyqtSignal as Signal
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''
Running this sample needs to open GlassColor.dgn.
This sample demonstrates how to change the glass panels with PyQt UI.
Drag the red box in middle to change color of the glasses.
Right click on the 3 red boxes on left, middle or right to pick different color with QColorDialog.
'''

def needToChangeColor(msElement):
    """
    Determines if the color of the given element needs to be changed.
    The function checks several conditions to decide if the color of the 
    provided element should be changed. The element must be graphic, visible, 
    not deleted, and not a construction element. Additionally, the element 
    must be on specific levels ("A-GLAZ" or "A-WALL-METL").
    
    :param msElement: The element to check.
    :type msElement: Element
    
    :return: True if the color needs to be changed, False otherwise.
    :rtype: bool
    """
    # Element should be graphic, visible, not deleted and not construction
    if ((not msElement.ehdr.isGraphics) or msElement.hdr.dhdr.props.b.invisible
        or msElement.ehdr.deleted or msElement.hdr.dhdr.props.b.elementClass != 0):
        return False
    
    # Element should be on level "A-GLAZ" or "A-WALL-METL"
    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "A-GLAZ")
    if(ret1[0] != BentleyStatus.eSUCCESS):
        return False
    ret2 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "A-WALL-METL")
    if(ret2[0] != BentleyStatus.eSUCCESS):
        return False

    levelID1 = ret1[1]
    levelID2 = ret2[1]
    if(msElement.ehdr.level != levelID1 and msElement.ehdr.level != levelID2):
        return False
    
    return True

def GetElementByXCoordinate():
    """
    Categorizes graphical elements by their x-coordinate.
    This function retrieves all graphical elements from the active DGN model,
    checks if they need to change color, and categorizes them based on their
    x-coordinate. The x-coordinate is rounded and divided by 10,000,000 to
    group elements into different walls.
    
    Returns:
        dict: A dictionary where the keys are the rounded x-coordinates divided
              by 10,000,000, and the values are lists of element references
              that fall into those categories.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()
    categorizedElementsByX = {}
    for elementRef in graphicalElements:
        eeh = EditElementHandle(elementRef, dgnModel)
        msElement = eeh.GetElement ()

        if(not needToChangeColor(msElement)):
            continue

        # Categorize elements in different walls by x-coordinate
        xCoordinate = msElement.hdr.dhdr.range.xlowlim
        if round(xCoordinate/10000000) not in categorizedElementsByX:
            categorizedElementsByX[round(xCoordinate/10000000)] = []
        categorizedElementsByX[round(xCoordinate/10000000)].append(elementRef)

    return categorizedElementsByX

def ChangeGlassWallColor(graphicalElements, gradient):
    """
    Change the color of glass wall elements based on their y-coordinate and a gradient.
    This function categorizes graphical elements by their y-coordinate and changes their color
    according to a specified gradient. The gradient is applied across the columns of elements.
    
    :param graphicalElements: List of graphical element references to be processed.
    :type graphicalElements: list
    :param gradient: A list of tuples where each tuple contains a stop value and a color value.
                     The stop value is a float between 0 and 1 indicating the position in the gradient.
                     The color value is a string representing the color in a format recognized by QtGui.QColor.
    :type gradient: list of tuple(float, str)
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    categorizedElements = {}
    for elementRef in graphicalElements:
        eeh = EditElementHandle(elementRef, dgnModel)
        msElement = eeh.GetElement ()

        if(not needToChangeColor(msElement)):
            continue

        # Categorize elements by y-coordinate to change the color of glass panels in each column
        yCoordinate = msElement.hdr.dhdr.range.ylowlim if msElement.hdr.dhdr.range.ylowlim > 506461000 else msElement.hdr.dhdr.range.yhighlim
        if round(yCoordinate/1000000) not in categorizedElements:
            categorizedElements[round(yCoordinate/1000000)] = []
        categorizedElements[round(yCoordinate/1000000)].append(elementRef)


    columnsCount = len(categorizedElements)
    leftRgbColor = QtGui.QColor(gradient[0][1])
    middleRgbColor = QtGui.QColor(gradient[1][1])
    rightRgbColor = QtGui.QColor(gradient[2][1])
    count = 0
    color = None
    stop, _ = gradient[1]
    # Change glass panels color for each column
    for yCoordinate in sorted(categorizedElements, reverse=True):
        if count <= round(columnsCount * stop) - 1:
            color = CalculateColor(leftRgbColor, middleRgbColor, round(columnsCount * stop) - 1, count)
        elif count <= columnsCount - 1:
            color = CalculateColor(middleRgbColor, rightRgbColor, columnsCount - round(columnsCount * stop),  count - round(columnsCount * stop) + 1)
        for elementRef in categorizedElements[yCoordinate]:
            eeh = EditElementHandle(elementRef, dgnModel)
            propertiesSetter = ElementPropertiesSetter()
            propertiesSetter.SetColor(round(color))
            propertiesSetter.SetTransparency(0)
            if True == propertiesSetter.Apply(eeh):
                eeh.ReplaceInModel(elementRef)

        count += 1

def ChangeGlassColor(gradient):
    """
    Change the color of glass walls based on a gradient.

    This function categorizes elements by their X coordinate and changes the color
    of glass walls in descending order of their X coordinates using the provided gradient.

    :param gradient: The gradient to be applied to the glass walls.
    :type gradient: Any
    """
    categorizedElementsByX = GetElementByXCoordinate()
    for xCoordinate in sorted(categorizedElementsByX, reverse=True):
        ChangeGlassWallColor(categorizedElementsByX[xCoordinate], gradient) 

def CalculateColor(startRgbColor, endRgbColor, totalCount, currentCount):
    """
    Calculate the intermediate color in a gradient transition between two colors.

    This function computes the RGB color at a specific point in a gradient transition
    from `startRgbColor` to `endRgbColor` over a total of `totalCount` steps, 
    returning the color at the `currentCount` step.

    :param startRgbColor: The starting color as a `QtGui.QColor` object.
    :param endRgbColor: The ending color as a `QtGui.QColor` object.
    :param totalCount: The total number of steps in the gradient transition.
    :param currentCount: The current step in the gradient transition.
    
    :return: The intermediate color as an integer.
    """
    currentRgbColor = QtGui.QColor(startRgbColor)
    if totalCount > 0:
        currentRgbColor.setRed(round(currentRgbColor.red() + (endRgbColor.red() - startRgbColor.red()) / totalCount * currentCount)) 
        currentRgbColor.setGreen(round(currentRgbColor.green() + (endRgbColor.green() - startRgbColor.green()) / totalCount * currentCount)) 
        currentRgbColor.setBlue(round(currentRgbColor.blue() + (endRgbColor.blue() - startRgbColor.blue()) / totalCount * currentCount)) 
    return GetIntColorFromRGB(currentRgbColor)

def GetIntColorFromRGB(rgbColor):
    """
    Converts an RGB color to an integer color representation.

    :param rgbColor: An object representing the RGB color. It should have `red()`, `green()`, and `blue()` methods.
    :type rgbColor: RGBColor
    
    :return: An integer color representation suitable for use with DgnColorMap.
    :rtype: int
    """
    intColorDef = IntColorDef(rgbColor.red(), rgbColor.green(), rgbColor.blue())
    return DgnColorMap.CreateElementColor(intColorDef, None, None, ISessionMgr.GetActiveDgnFile())

class Gradient(QtWidgets.QWidget):

    gradientChanged = Signal()

    def __init__(self, gradient=None, *args, **kwargs):
        """
        Initialize the GlassColorWithQtDialog.
        
        :param gradient: Optional; A list of tuples representing the gradient stops. 
                         Each tuple contains a float (position) and a string (color in hex format).
                         Defaults to [(0.0, '#000000'), (1.0, '#ffffff')].
        :type gradient: list of tuple, optional
        :param args: Additional positional arguments.
        :param kwargs: Additional keyword arguments.
        """
        super().__init__(*args, **kwargs)

        self.setSizePolicy(QtWidgets.QSizePolicy.MinimumExpanding, QtWidgets.QSizePolicy.MinimumExpanding)

        if gradient:
            self._gradient = gradient
        else:
            self._gradient = [(0.0, '#000000'), (1.0, '#ffffff'),]

        # Stop point handle sizes.
        self._handle_w = 10
        self._handle_h = 10

        self._drag_position = None

    def paintEvent(self, e):
        """
        Handles the paint event for the widget.
        This method is called whenever the widget needs to be repainted. It uses a QPainter to draw a linear horizontal gradient
        and stop handles on the widget.
        
        :param e: The paint event.
        :type e: QPaintEvent
        """
        painter = QtGui.QPainter(self)
        width = painter.device().width()
        height = painter.device().height()

        # Draw the linear horizontal gradient.
        gradient = QtGui.QLinearGradient(0, 0, width, 0)
        for stop, color in self._gradient:
            gradient.setColorAt(stop, QtGui.QColor(color))

        rect = QtCore.QRect(0, 0, width, height)
        painter.fillRect(rect, gradient)

        pen = QtGui.QPen()

        y = painter.device().height() / 2

        # Draw the stop handles.
        for stop, _ in self._gradient:
            pen.setColor(QtGui.QColor('white'))
            painter.setPen(pen)

            painter.drawLine(int(stop * width), int(y - self._handle_h), int(stop * width), int(y + self._handle_h))

            pen.setColor(QtGui.QColor('red'))
            painter.setPen(pen)

            rect = QtCore.QRect(int(stop * width - self._handle_w/2), int(y - self._handle_h/2), int(self._handle_w), int(self._handle_h))
            painter.drawRect(rect)

        painter.end()

    def sortGradient(self):
        """
        Sorts the gradient list in ascending order based on the first element of each tuple.

        The gradient list is expected to be a list of tuples, where each tuple's first element
        is used as the key for sorting.

        :return: None
        """
        self._gradient = sorted(self._gradient, key=lambda g:g[0])

    def constrainGradient(self):
        """
        Constrains the gradient stops to be within the valid range [0.0, 1.0].

        This method iterates over the gradient stops and ensures that each stop value
        is within the range of 0.0 to 1.0. If a stop value is less than 0.0, it is set
        to 0.0. If a stop value is greater than 1.0, it is set to 1.0. The color values
        associated with each stop remain unchanged.
        """
        self._gradient = [
            # Ensure values within valid range.
            (max(0.0, min(1.0, stop)), color)
            for stop, color in self._gradient
        ]

    def setGradient(self, gradient):
        """
        Set the gradient for the glass color and update the necessary properties.

        :param gradient: A list of tuples where each tuple contains a stop value 
                         (float between 0.0 and 1.0) and a corresponding color value.
        :type gradient: list of tuple(float, Any)

        :raises AssertionError: If any stop value in the gradient is not between 0.0 and 1.0.
        :return: None
        """
        assert all([0.0 <= stop <= 1.0 for stop, _ in gradient])
        self._gradient = gradient
        self.constrainGradient()
        self.sortGradient()
        self.gradientChanged.emit()
        ChangeGlassColor(self._gradient)

    @property
    def _end_stops(self):
        """
        Returns the indices of the first and last elements in the gradient list.

        :return: A list containing the indices of the first and last elements.
        :rtype: list[int]
        """
        return [0, len(self._gradient)-1]
    
    def setColorAtPosition(self, n, color):
        """
        Set the color at a specific position in the gradient.

        :param int n: The position in the gradient to set the color.
        :param QColor color: The color to set at the specified position.
        
        :raises IndexError: If the position `n` is out of the gradient's range.
        """
        if n < len(self._gradient):
            stop, _ = self._gradient[n]
            self._gradient[n] = stop, color
            self.gradientChanged.emit()
            self.update()

    def chooseColorAtPosition(self, n, current_color=None):
        """
        Opens a QColorDialog to choose a color and sets the chosen color at the specified position.
        
        :param int n: The position at which to set the chosen color.
        :param str current_color: The current color in hexadecimal format (e.g., '#RRGGBB') to be pre-selected in the dialog. Defaults to None.
        
        :return: None
        """
        dlg = QtWidgets.QColorDialog(self)
        if current_color:
            dlg.setCurrentColor(QtGui.QColor(current_color))

        if dlg.exec_():
            self.setColorAtPosition(n, dlg.currentColor().name())

    def findStopHandleForEvent(self, e, to_exclude=None):
        """
        Find the handle for a gradient stop based on the event coordinates.
        This method checks if the event coordinates (e.x(), e.y()) are within the bounds
        of any gradient stop handle, excluding any specified stops.
        
        :param e: The event object containing the x and y coordinates.
        :type e: QEvent
        :param to_exclude: A list of stop indices to exclude from the check, defaults to None.
        :type to_exclude: list, optional
        
        :return: The index of the gradient stop handle if found, otherwise None.
        :rtype: int or None
        """
        width = self.width()
        height = self.height()
        midpoint = height / 2

        # Are we inside a stop point? First check y.
        if ( e.y() >= midpoint - self._handle_h
            and  e.y() <= midpoint + self._handle_h ):
            for n, (stop, color) in enumerate(self._gradient):
                if to_exclude and n in to_exclude:
                    # Allow us to skip the extreme ends of the gradient.
                    continue
                if ( e.x() >= stop * width - self._handle_w
                    and  e.x() <= stop * width + self._handle_w ):
                    return n

    def mousePressEvent(self, e):
        """
        Handles mouse press events.
        This method is called when a mouse button is pressed. It distinguishes between
        right and left mouse button presses and performs different actions accordingly.
        
        :param e: The mouse event.
        :type e: QMouseEvent
        """
        # We're in this stop point.
        if e.button() == Qt.RightButton:
            n = self.findStopHandleForEvent(e)
            if n is not None:
                _, color = self._gradient[n]
                self.chooseColorAtPosition(n, color)
                ChangeGlassColor(self._gradient)

        elif e.button() == Qt.LeftButton:
            n = self.findStopHandleForEvent(e, to_exclude=self._end_stops)
            if n is not None:
                # Activate drag mode.
                self._drag_position = n

    def mouseReleaseEvent(self, e):
        """
        Handle the mouse release event.

        This method is called when the mouse button is released. It resets the 
        drag position, sorts the gradient, and changes the glass color based 
        on the current gradient.

        :param e: The mouse event.
        :type e: QMouseEvent
        """
        self._drag_position = None
        self.sortGradient()
        ChangeGlassColor(self._gradient)

    def mouseMoveEvent(self, e):
        """
        Handle the mouse move event to update the gradient stop position.

        This method is called when the mouse is moved within the widget. If a drag
        operation is active, it updates the position of the gradient stop being
        dragged based on the current mouse position.

        :param e: QMouseEvent object containing information about the mouse event.
        :type e: QMouseEvent
        """
        # If drag active, move the stop.
        if self._drag_position:
            stop = e.x() / self.width()
            _, color = self._gradient[self._drag_position]
            self._gradient[self._drag_position] = stop, color
            self.constrainGradient()
            self.update()


class Window(QtWidgets.QMainWindow):

    def __init__(self):
        """
        Initializes the main window and sets up the user interface.

        This constructor method calls the parent class's constructor and then
        initializes the user interface by calling the `initUI` method.
        """
        super().__init__()
        self.initUI()

    def initUI(self):
        """
        Initializes the user interface for the color setting dialog.
        This method sets the window title, geometry, and creates a central widget
        with a gradient. It also attaches the Qt tool setting to the window ID.
        
        :return: None
        """
        self.setWindowTitle('Color Setting')
        self.setGeometry(100, 200, 400, 100)

        # Create a central widget
        gradient = Gradient(self)
        gradient.setGradient([(0, 'black'), (0.5, 'red'), (1, 'green')])
        self.setCentralWidget(gradient)
        self.storedWinId = self.winId()
        self.loop = QtCore.QEventLoop()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

    def ms_mainLoop(self):
        """
        Main loop that processes events and handles input for the application.

        This function continuously checks if a specific window is still open and,
        while it is, processes events, handles input through the PyCadInputQueue,
        and sleeps for a short duration to prevent high CPU usage.

        :return: None
        """
        while win32gui.IsWindow(self.storedWinId):
            self.loop.processEvents()
            PyCadInputQueue.PythonMainLoop()
            time.sleep(0.001)

def Run():
    """
    Run the application.

    This function initializes a Qt application, creates a main window,
    displays it, and starts the main event loop.
    """
    app = QtWidgets.QApplication([])
    w = Window()
    w.show()
    w.ms_mainLoop()
    
if __name__ == '__main__':
    Run()
