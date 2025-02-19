# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

'''
Running this sample needs to open GlassColor.dgn.
This sample shows how to change the glass panels with PyQt UI.
Drag the red box in middle to change color of the glasses.
Right click on the 3 red boxes on left, middle or right to pick different color with QColorDialog.
'''

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


''' Check whether the element color need to be changed. '''
def needToChangeColor(msElement):
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

''' Categorize the elements by x-coordinate '''
def GetElementByXCoordinate():
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

''' Change the glass panels color in each column '''
def ChangeGlassWallColor(graphicalElements, gradient):
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

''' Change glass color with gradient '''
def ChangeGlassColor(gradient):
    categorizedElementsByX = GetElementByXCoordinate()
    for xCoordinate in sorted(categorizedElementsByX, reverse=True):
        ChangeGlassWallColor(categorizedElementsByX[xCoordinate], gradient) 

''' Calculate the color between start and end color '''
def CalculateColor(startRgbColor, endRgbColor, totalCount, currentCount):
    currentRgbColor = QtGui.QColor(startRgbColor)
    if totalCount > 0:
        currentRgbColor.setRed(round(currentRgbColor.red() + (endRgbColor.red() - startRgbColor.red()) / totalCount * currentCount)) 
        currentRgbColor.setGreen(round(currentRgbColor.green() + (endRgbColor.green() - startRgbColor.green()) / totalCount * currentCount)) 
        currentRgbColor.setBlue(round(currentRgbColor.blue() + (endRgbColor.blue() - startRgbColor.blue()) / totalCount * currentCount)) 
    return GetIntColorFromRGB(currentRgbColor)

''' Get the int color from color table by RGB value '''
def GetIntColorFromRGB(rgbColor):
    intColorDef = IntColorDef(rgbColor.red(), rgbColor.green(), rgbColor.blue())
    return DgnColorMap.CreateElementColor(intColorDef, None, None, ISessionMgr.GetActiveDgnFile())

class Gradient(QtWidgets.QWidget):

    gradientChanged = Signal()

    def __init__(self, gradient=None, *args, **kwargs):
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
        self._gradient = sorted(self._gradient, key=lambda g:g[0])

    def constrainGradient(self):
        self._gradient = [
            # Ensure values within valid range.
            (max(0.0, min(1.0, stop)), color)
            for stop, color in self._gradient
        ]

    def setGradient(self, gradient):
        assert all([0.0 <= stop <= 1.0 for stop, _ in gradient])
        self._gradient = gradient
        self.constrainGradient()
        self.sortGradient()
        self.gradientChanged.emit()
        ChangeGlassColor(self._gradient)

    @property
    def _end_stops(self):
        return [0, len(self._gradient)-1]
    
    def setColorAtPosition(self, n, color):
        if n < len(self._gradient):
            stop, _ = self._gradient[n]
            self._gradient[n] = stop, color
            self.gradientChanged.emit()
            self.update()

    def chooseColorAtPosition(self, n, current_color=None):
        dlg = QtWidgets.QColorDialog(self)
        if current_color:
            dlg.setCurrentColor(QtGui.QColor(current_color))

        if dlg.exec_():
            self.setColorAtPosition(n, dlg.currentColor().name())

    def findStopHandleForEvent(self, e, to_exclude=None):
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
        self._drag_position = None
        self.sortGradient()
        ChangeGlassColor(self._gradient)

    def mouseMoveEvent(self, e):
        # If drag active, move the stop.
        if self._drag_position:
            stop = e.x() / self.width()
            _, color = self._gradient[self._drag_position]
            self._gradient[self._drag_position] = stop, color
            self.constrainGradient()
            self.update()


class Window(QtWidgets.QMainWindow):

    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
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
        while win32gui.IsWindow(self.storedWinId):
            self.loop.processEvents()
            PyCadInputQueue.PythonMainLoop()
            time.sleep(0.001)

def Run():
    app = QtWidgets.QApplication([])
    w = Window()
    w.show()
    w.ms_mainLoop()
    
if __name__ == '__main__':
    Run()
