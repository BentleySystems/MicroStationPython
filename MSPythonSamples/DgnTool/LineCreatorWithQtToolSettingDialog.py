# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import sys
import PyQt5
from PyQt5.QtCore import  *
from PyQt5.QtWidgets import *
from PyQt5.QtWidgets import QMainWindow, QApplication, QCheckBox, QLabel, QTextEdit, QWidget
from PyQt5.QtWidgets import QGridLayout

from PyQt5.QtGui import QFont, QWindow

import win32gui

class MsQtWidgiet(QWidget):
    def __init__(self) :
        super().__init__()
        self.storedWinId = self.winId()
#        self.winIdCapsule = self.winId.ascapsule()
        self.loop = QEventLoop()
        PyCadInputQueue.AttachQtToolSetting(int(self.storedWinId))

    def ms_mainLoop(self):
        while win32gui.IsWindow(self.storedWinId):
            self.loop.processEvents()
            PyCadInputQueue.PythonMainLoop()

class LineToolSetting:
    def __init__(self) -> None:
        self.length = 0.0
        self.angle = 0.0

def bind(objectName, propertyName, type):
  # Define a function that takes an object name, property name, and type as arguments
    
    def getter(self):
      # Find the child widget with the given object name
        child = self.findChild(QObject, objectName)
        # Get the property value from the child widget
        p = child.property(propertyName)
        # Convert the property value to the specified type
        r = type(p)
        # Return the converted value
        return r 
      # Define a getter function that retrieves the property value
    
    def setter(self, value):
      # Find the child widget with the given object name
      self.findChild(QObject, objectName)
      # Set the property value on the child widget
      self.findChild(QObject, objectName).setProperty(propertyName, QVariant(value))
      
      # Define a setter function that sets the property value
    
    return property(getter, setter)
  # Return a property object with the getter and setter functions

class LineToolSettingDlg(MsQtWidgiet):
    def __init__(self):
        # Initialize the dialog with the superclass constructor call
        super().__init__()
        self.tool_setting = LineToolSetting()  # Create an instance of LineToolSetting
        self.populate_tool_setting()  # Populate the tool setting

    def populate_tool_setting(self):  # all are Qt codes without Microstation logic involved
        # Create a QGridLayout and set it as the layout for this dialog
        self.grid = QGridLayout()
        self.setLayout(self.grid)

        self.checkBoxUseL = QCheckBox("")  # Create a check box with no initial text
        self.checkBoxUseL.setObjectName("checkBoxUseL")  # Set the object name to "checkBoxUseL"
        self.grid.addWidget(self.checkBoxUseL, 0, 0)  # Add the checkbox to the grid at row 0, column 0

        self.grid.addWidget(QLabel("Length"), 0, 1)  # Add a label with text "Length" to the grid at row 0, column 1

        self.editBoxLength = QLineEdit()  # Create an edit box
        self.editBoxLength.setObjectName("editBoxLength")  # Set the object name to "editBoxLength"
        self.grid.addWidget(self.editBoxLength, 0, 2)  # Add the edit box to the grid at row 0, column 2

        self.checkBoxUseA = QCheckBox("")  # Create a checkbox with no initial text
        self.checkBoxUseA.setObjectName("checkBoxUseA")  # Set the object name to "checkBoxUseA"
        self.grid.addWidget(self.checkBoxUseA, 1, 0)  # Add the checkbox to the grid at row 1, column 0

        self.grid.addWidget(QLabel("Angle"), 1, 1)  # Add a label with text "Angle" to the grid at row 1, column 1

        self.editBoxAngle = QLineEdit()  # Create an edit box
        self.editBoxAngle.setObjectName("editBoxAngle")  # Set the object name to "editBoxAngle"
        self.grid.addWidget(self.editBoxAngle, 1, 2)  # Add the edit box to the grid at row 1, column 2

        self.grid.setSpacing(5)  # Set the spacing between widgets in the grid
        self.grid.setColumnStretch(0, 100)  # Stretch the first column of the grid to take up most of the space

        self.setFixedHeight(80)  # Set the fixed height of this dialog
        self.setFixedWidth(280)  # Set the fixed width of this dialog

        self.length = self.tool_setting.length  # Get the length property from the tool setting
        self.angle = self.tool_setting.angle  # Get the angle property from the tool setting
        self.use_length = False  # Initialize use_length to false
        self.use_angle = False  # Initialize use_angle to false

    length = bind("editBoxLength", "text", str)  # Bind the text property of editBoxLength to a string type
    angle = bind("editBoxAngle", "text", str)  # Bind the text property of editBoxAngle to a string type
    use_length = bind("checkBoxUseL", "checked", bool)  # Bind the checked state of checkBoxUseL to a boolean type
    use_angle = bind("checkBoxUseA", "checked", bool)  # Bind the checked state of checkBoxUseA to a boolean type


'''
/*=================================================================================**//**
* Example showing how to use DgnPrimitiveTool to write a place line tool.
*
* Demonstrates using the RedrawElems class for element dynamics.
* 
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
class LineCreator(DgnPrimitiveTool):
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def __init__(self, toolName, toolPrompt):
        DgnPrimitiveTool.__init__(self, toolName, toolPrompt) # C++ base's __init__ must be called.
        self.m_points = DPoint3dArray()
        self.m_self = self # Keep self reference
    
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnPostInstall(self):
        AccuSnap.GetInstance().EnableSnap(True) # Enable snapping for create tools.
    
        DgnPrimitiveTool._OnPostInstall(self)
       
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnRestartTool(self):
        LineCreator.InstallNewInstance(self.GetToolId(), self.GetToolPrompt())
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnDataButton(self, ev):
        if len(self.m_points) == 0:
            self._BeginDynamics() # Start dynamics on first point. Enables AccuDraw and triggers _OnDynamicFrame being called.

        self.m_points.append(ev.GetPoint()) # Save current data point location.
        self.SetupAndPromptForNextAction()

        if len(self.m_points) < 2:
            return False

        endPt = self.__UpdateToolSettingAndGetEndPoint(ev)
        self.m_points[1] = endPt;

        eeh = EditElementHandle()

        if self.CreateElement(eeh, self.m_points):
            eeh.AddToModel() # Add new line element to active model.

        self.m_points.clear()
        self.m_points.append(endPt) # Start of next line is end of current line.

        return self._CheckSingleShot() # Tool should exit after creating a single line if started in single-shot mode.
       
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnResetButton(self, ev):
        self._OnRestartTool()
        return True
        
    def __UpdateToolSettingAndGetEndPoint(self, ev):
        startPt = self.m_points[0]
        dynamicEndPt = ev.GetPoint()

        dynamicNormalDir = dynamicEndPt - startPt
        dynamicNormalDir.Normalize()

        dynamicLength = dynamicEndPt.Distance(startPt)

        if not self.toolSettingDlg.use_length:
            self.toolSettingDlg.tool_setting.length = dynamicLength
            wstr = WString()
            StringUtility.FromUors(wstr, self.toolSettingDlg.tool_setting.length)
            displayStr = str(wstr)           
            self.toolSettingDlg.length = displayStr
        else:
            wstr = WString(self.toolSettingDlg.length)
            length = StringUtility.ToUors(wstr)
            self.toolSettingDlg.tool_setting.length = length

        PI = 3.1415926

        if not self.toolSettingDlg.use_angle:
            xAxis = DVec3d.UnitX()            
            self.toolSettingDlg.tool_setting.angle = dynamicNormalDir.AngleTo(xAxis)
            if (dynamicNormalDir.y < 0):
                self.toolSettingDlg.tool_setting.angle = 2*PI -self.toolSettingDlg.tool_setting.angle 

            degrees = self.toolSettingDlg.tool_setting.angle * 180.0 / PI
            wstr = WString()
            StringUtility.FromDirection(wstr, degrees, AngleFormatVals.eActive, False, True, -1, -1, True, False, ISessionMgr.ActiveDgnModelRef)
            displayStr = str(wstr)
            self.toolSettingDlg.angle = displayStr
        else:
            degree = StringUtility.ToDirection(WString(self.toolSettingDlg.angle)) 
            self.toolSettingDlg.tool_setting.angle = degree * PI / 180.0

        dir = DVec3d.UnitX()
        dir.RotateXY(self.toolSettingDlg.tool_setting.angle)
        endPt = startPt + dir * self.toolSettingDlg.tool_setting.length
        return endPt             

    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnDynamicFrame(self, ev):
        tmpPts = DPoint3dArray(self.m_points)
        eeh = EditElementHandle()

        endPt = self.__UpdateToolSettingAndGetEndPoint(ev)

        tmpPts.append(endPt)

        if not self.CreateElement(eeh, tmpPts):
            return

        redrawElems = RedrawElems()
        redrawElems.SetDynamicsViews(IViewManager.GetActiveViewSet(), ev.GetViewport()) # Display in all views, draws to cursor view first...
        redrawElems.SetDrawMode(eDRAW_MODE_TempDraw)
        redrawElems.SetDrawPurpose(DrawPurpose.eDynamics)

        redrawElems.DoRedraw(eeh)

    def _GetToolName (self, name):
        s = WString ("LineCreator")
        return s
    
    def _OnCleanup (self):
        if win32gui.IsWindow(self.toolSettingDlg.storedWinId):
            self.toolSettingDlg.destroy()
 
    '''    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def CreateElement(self, eeh, points):
        if len(points) != 2:
            return False

        # NOTE: Easier to always work with CurveVector/CurvePrimitive and not worry about element specific create methods, ex. LineHandler::CreateLineElement.
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(eeh, ICurvePrimitive.CreateLine(DSegment3d(points[0], points[-1])), None, ACTIVEMODEL.Is3d(), ACTIVEMODEL):
            return False

        ElementPropertyUtils.ApplyActiveSettings(eeh)

        return True
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def SetupAndPromptForNextAction(self):
        msgStr = ''
        
        if (len(self.m_points)==1):
            msgStr = 'Enter next point:'
        else:
            msgStr = 'Enter next point or reset to complete :'

        NotificationManager.OutputPrompt(msgStr)

        if len(self.m_points) != 2:
            return

        xVec = DVec3d.FromStartEndNormalize(self.m_points[0], self.m_points[-1])

        AccuDraw.GetInstance().SetContext(AccuDrawFlags.eACCUDRAW_SetXAxis, None, xVec) # Orient AccuDraw to last segment.
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * Method to create and install a new instance of the tool. If InstallTool returns ERROR,
    * the new tool instance will be freed/invalid. Never call delete on RefCounted classes.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def InstallNewInstance(toolId, toolPrompt):   
        tool = LineCreator(toolId, toolPrompt) 
        tool.InstallTool()
        tool.app = QApplication(sys.argv)
        tool.toolSettingDlg = LineToolSettingDlg()
        tool.toolSettingDlg.setWindowTitle("Place Line")
        tool.toolSettingDlg.show()
        tool.toolSettingDlg.ms_mainLoop()

'''
/*=================================================================================**//**
* Default entrypoint for current module unit.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
if __name__ == "__main__":
#    app = QApplication(sys.argv)
    LineCreator.InstallNewInstance(0, 0)