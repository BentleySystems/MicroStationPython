# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

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

'''
This sample demonstrates how to create a DgnPrimitiveTool with a tool setting dialog implemented using PyQt5.
'''

class MsQtApplication(QApplication):
    @staticmethod
    def updateMstn ():
        PyCadInputQueue.PythonMainLoop()

    timerForMsMessagePump = None  

    @staticmethod
    def exec():
        MsQtApplication.timerForMsMessagePump = QTimer()
        MsQtApplication.timerForMsMessagePump.timeout.connect(MsQtApplication.updateMstn)
        MsQtApplication.timerForMsMessagePump.start()
        QApplication.exec()
        MsQtApplication.timerForMsMessagePump.stop()      

class MsQtWidgiet(QWidget):
    def __init__(self) :
        """
        Initialize the MsQtWidgiet.
        """
        super().__init__()
        PyCadInputQueue.AttachQtToolSetting(int(self.winId()))


class LineToolSetting:
    def __init__(self) -> None:
        self.length = 0.0
        self.angle = 0.0

def bind(objectName, propertyName, type):
    """
    Bind a property of a child widget to a specified type.

    :param objectName: The name of the child widget.
    :type objectName: str
    :param propertyName: The name of the property to bind.
    :type propertyName: str
    :param type: The type to which the property value should be converted.
    :type type: type
    :return: A property object with getter and setter functions.
    :rtype: property
    """
    # Define a function that takes an object name, property name, and type as arguments
    
    def getter(self):
        """
        Retrieve the property value from the child widget and convert it to the specified type.

        :return: The converted property value.
        :rtype: type
        """
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
        """
        Set the property value on the child widget.

        :param value: The value to set on the property.
        :type value: Any
        """      
        # Find the child widget with the given object name
        self.findChild(QObject, objectName)
        # Set the property value on the child widget
        self.findChild(QObject, objectName).setProperty(propertyName, QVariant(value))
      
      # Define a setter function that sets the property value
    
    return property(getter, setter)
  # Return a property object with the getter and setter functions

class LineToolSettingDlg(MsQtWidgiet):
    def __init__(self):
        """
        Initialize the LineToolSettingDlg.

        This initializes the dialog with the superclass constructor call,
        creates an instance of LineToolSetting, and populates the tool setting.
        """
        # Initialize the dialog with the superclass constructor call
        super().__init__()
        self.tool_setting = LineToolSetting()  # Create an instance of LineToolSetting
        self.populate_tool_setting()  # Populate the tool setting

    def populate_tool_setting(self):  # all are Qt codes without Microstation logic involved
        """
        Populate the tool setting dialog with widgets.

        This method creates and arranges the widgets in a grid layout, including checkboxes,
        labels, and edit boxes for length and angle settings. It also sets the fixed size
        of the dialog and initializes the tool setting properties.

        :ivar checkBoxUseL: Checkbox to enable or disable length setting.
        :vartype checkBoxUseL: QCheckBox
        :ivar editBoxLength: Edit box to input the length value.
        :vartype editBoxLength: QLineEdit
        :ivar checkBoxUseA: Checkbox to enable or disable angle setting.
        :vartype checkBoxUseA: QCheckBox
        :ivar editBoxAngle: Edit box to input the angle value.
        :vartype editBoxAngle: QLineEdit
        :ivar length: The length property from the tool setting.
        :vartype length: float
        :ivar angle: The angle property from the tool setting.
        :vartype angle: float
        :ivar use_length: Flag to indicate if length setting is used.
        :vartype use_length: bool
        :ivar use_angle: Flag to indicate if angle setting is used.
        :vartype use_angle: bool
        """
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


class LineCreator(DgnPrimitiveTool):
    """
    Example showing how to use DgnPrimitiveTool to write a place line tool.

    Demonstrates using the RedrawElems class for element dynamics.

    """
    
    def __init__(self, toolName, toolPrompt):
        """
        Initialize the LineCreator tool.

        :param toolName: The name of the tool.
        :type toolName: str
        :param toolPrompt: The prompt for the tool.
        :type toolPrompt: str
        """
        DgnPrimitiveTool.__init__(self, toolName, toolPrompt) # C++ base's __init__ must be called.
        self.m_points = DPoint3dArray()
        self.m_self = self # Keep self reference
    
    def _OnPostInstall(self):
        """
        Perform post-installation steps for the LineCreator tool.

        This method enables snapping for create tools and calls the superclass's
        _OnPostInstall method.
        """
        AccuSnap.GetInstance().EnableSnap(True) # Enable snapping for create tools.
    
        DgnPrimitiveTool._OnPostInstall(self)
       
    def _OnRestartTool(self):
        """
        Restart the LineCreator tool.

        This method installs a new instance of the tool with the current tool ID and prompt.
        """
        LineCreator.InstallNewInstance(self.GetToolId(), self.GetToolPrompt())
        

    def _OnDataButton(self, ev):
        """
        Handle the data button event.

        This method processes the data button event, updates the tool settings, and creates
        a line element in the active model.

        :param ev: The event object containing information about the button event.
        :type ev: DgnButtonEvent
        :return: True if the event was handled successfully, False otherwise.
        :rtype: bool
        """
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
        """
        Handle the reset button event.

        This method restarts the tool when the reset button is pressed.

        :param ev: The event object containing information about the button event.
        :type ev: DgnButtonEvent
        :return: True if the event was handled successfully, False otherwise.
        :rtype: bool
        """       
        self._OnRestartTool()
        return True
        
    def __UpdateToolSettingAndGetEndPoint(self, ev):
        """
        Update the tool settings and get the end point based on the event.

        This method calculates the end point of the line based on the current tool settings
        and the event data. It updates the length and angle settings of the tool.

        :param ev: The event object containing information about the button event.
        :type ev: DgnButtonEvent
        :return: The calculated end point.
        :rtype: DPoint3d
        """
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


    def _OnDynamicFrame(self, ev):
        """
        Handle the dynamic frame event.

        This method updates the tool settings, creates a temporary line element,
        and redraws it dynamically in the active view.

        :param ev: The event object containing information about the dynamic frame event.
        :type ev: DgnButtonEvent
        """
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
        """
        Get the name of the tool.

        :param name: The name of the tool.
        :type name: str
        :return: The name of the tool as a WString.
        :rtype: WString
        """
        s = WString ("LineCreator")
        return s
    
    def _OnCleanup (self):
        """
        Perform cleanup operations for the LineCreator tool.

        This method destroys the tool setting dialog if its window is still valid.
        """
        self.toolSettingDlg.close()
 
    def CreateElement(self, eeh, points):
        """
        Create a line element from the given points.

        This method creates a line element using the provided points and applies active settings to it.

        :param eeh: The edit element handle to store the created element.
        :type eeh: EditElementHandle
        :param points: The points to create the line element from.
        :type points: list[DPoint3d]
        :return: True if the element was created successfully, False otherwise.
        :rtype: bool
        """
        if len(points) != 2:
            return False

        # NOTE: Easier to always work with CurveVector/CurvePrimitive and not worry about element specific create methods, ex. LineHandler::CreateLineElement.
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(eeh, ICurvePrimitive.CreateLine(DSegment3d(points[0], points[-1])), None, ACTIVEMODEL.Is3d(), ACTIVEMODEL):
            return False

        ElementPropertyUtils.ApplyActiveSettings(eeh)

        return True
        
    def SetupAndPromptForNextAction(self):
        """
        Set up the tool and prompt the user for the next action.

        This method displays a prompt message based on the number of points collected
        and sets the AccuDraw context for the next point.

        :ivar m_points: The list of points collected by the tool.
        :vartype m_points: list[DPoint3d]
        """
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
        

    tool = None

    def InstallNewInstance(toolId, toolPrompt):   
        """
        Create and install a new instance of the LineCreator tool.

        This method creates a new instance of the LineCreator tool, installs it, and
        initializes the tool setting dialog.

        :param toolId: The ID of the tool.
        :type toolId: str
        :param toolPrompt: The prompt for the tool.
        :type toolPrompt: str
        """
        LineCreator.tool = LineCreator(toolId, toolPrompt) 
        LineCreator.tool.InstallTool()
        LineCreator.tool.toolSettingDlg = LineToolSettingDlg()
        LineCreator.tool.toolSettingDlg.setWindowTitle("Place Line")
        LineCreator.tool.toolSettingDlg.show()

if __name__ == "__main__":
    app = QApplication.instance()
    if app is None:
        app = MsQtApplication(sys.argv) 

    LineCreator.InstallNewInstance(0, 0)

    app.exec()
