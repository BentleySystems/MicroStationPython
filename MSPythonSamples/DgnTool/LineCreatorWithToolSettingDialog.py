# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $


import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

from tkinter import *
import tkinter
import win32gui

'''
This sample demonstrates how to create a DgnPrimitiveTool with a tool setting dialog implemented using tkinter.
'''

class MsTk(Tk):
    allMstkWindows = []

    def __init__(self):
        Tk.__init__(self)

        self.update()
        hFrame = win32gui.GetParent(self.winfo_id())
        if  hFrame != 0:
            PyCadInputQueue.AttachTkinterToolSetting(hFrame)

        MsTk.allMstkWindows.append(self)

    @staticmethod
    def msmainloop():
        """
        Main loop for the MsTk class.

        This method runs a loop that continuously updates the Tkinter GUI
        and checks for certain conditions to break the loop. It also attaches
        the Tkinter tool setting to a parent window if not already attached.

        The loop performs the following actions:
        - Updates the Tkinter GUI.
        - Breaks the loop if the default Tkinter root is None.
        - Breaks the loop if the window ID is not valid.
        - Attaches the Tkinter tool setting to the parent window if not already attached.
        - Calls the Python main loop of PyCadInputQueue.
        """

        while MsTk.allMstkWindows :
            for thisMstkwindow in MsTk.allMstkWindows:
                thisMstkwindow.update()
  
            PyCadInputQueue.PythonMainLoop() 

class LineToolSetting:
    def __init__(self):
        """
        Initializes the LineToolSetting class.

        This constructor initializes the following attributes:
        
        - use_length (BooleanVar): A Tkinter variable indicating whether to use length.
        - length (float): The length value, initialized to 0.0.
        - use_angle (BooleanVar): A Tkinter variable indicating whether to use angle.
        - angle (float): The angle value, initialized to 0.0.
        """
        self.use_length = BooleanVar()
        self.length = 0.0
        self.use_angle = BooleanVar()
        self.angle = 0.0

class LineToolSettingDlg(MsTk): # must derive from MsTk which is reuseable module for interacting with Microstation UI system
    def __init__(self):
        """
        Initializes the LineToolSettingDlg class.

        This constructor performs the following actions:
        
        - Calls the constructor of the parent MsTk class.
        - Initializes the tool_setting attribute with an instance of LineToolSetting.
        - Calls the populate_tool_setting method to populate the tool settings.
        """
        super(LineToolSettingDlg, self).__init__()
        self.tool_setting = LineToolSetting ()
        self.populate_tool_setting()

    def populate_tool_setting(self): # all are Tikinter codes without Microstation logic involved
        """
        Populates the tool settings for the LineToolSettingDlg class.

        This method creates and arranges the Tkinter widgets for the tool settings,
        including checkbuttons, labels, and entry fields for length and angle.

        The following widgets are created and arranged:
        
        - A checkbutton for the use_length attribute.
        - A label for the "Length" text.
        - An entry field for the length value.
        - A checkbutton for the use_angle attribute.
        - A label for the "Angle" text.
        - An entry field for the angle value.
        """
        Checkbutton(self, text="", variable=self.tool_setting.use_length).grid(row=0, column=0, sticky=W, padx=(10, 0))
        Label(self, text="Length").grid(row=0, column=1, sticky=E, padx=(50, 0))
        self.lengthVar = StringVar()
        self.lengthVar.set("0")
        self.lengthEntry = Entry(self, width=15, textvariable=self.lengthVar)
        self.lengthEntry.grid(row=0, column=2, sticky=W, padx=(10, 10))
        Checkbutton(self, text="", variable=self.tool_setting.use_angle).grid(row=1, column=0, sticky=W, padx=(10,0))
        Label(self, text="Angle").grid(row= 1, column=1, sticky=E, padx=(50, 0))
        self.angleVar = StringVar()
        self.angleVar.set("0")
        self.angleEntry = Entry(self, width=15, textvariable=self.angleVar)
        self.angleEntry.grid(row=1, column=2, sticky=W, padx=(10, 10))



'''
/*=================================================================================**//**
* Example showing how to use DgnPrimitiveTool to write a place line tool.
*
* Demonstrates using the RedrawElems class for element dynamics.
* 
+===============+===============+===============+===============+===============+======*/
'''
class LineCreator(DgnPrimitiveTool):
    def __init__(self, toolName, toolPrompt):
        """
        Initializes the LineCreator class.

        This constructor performs the following actions:

        - Calls the constructor of the parent DgnPrimitiveTool class with the provided toolName and toolPrompt.
        - Initializes the m_points attribute with an instance of DPoint3dArray.
        - Keeps a self reference in the m_self attribute.

        :param toolName: The name of the tool.
        :param toolPrompt: The prompt message for the tool.
        """
        DgnPrimitiveTool.__init__(self, toolName, toolPrompt) # C++ base's __init__ must be called.
        self.m_points = DPoint3dArray()
        self.m_self = self # Keep self reference
    
    def _OnPostInstall(self):
        """
        Post-installation setup for the LineCreator tool.

        This method performs the following actions:

        - Enables snapping for create tools using AccuSnap.
        - Calls the _OnPostInstall method of the parent DgnPrimitiveTool class.
        """

        AccuSnap.GetInstance().EnableSnap(True) # Enable snapping for create tools.
    
        DgnPrimitiveTool._OnPostInstall(self)
       
    def _OnRestartTool(self):
        """
        Restarts the LineCreator tool.

        This method performs the following actions:

        - Installs a new instance of the LineCreator tool with the current tool ID and prompt.
        """
        LineCreator.InstallNewInstance(self.GetToolId(), self.GetToolPrompt())
        
    def _OnDataButton(self, ev):
        """
        Handles the data button event for the LineCreator tool.

        This method performs the following actions:

        - Starts dynamics on the first point, enabling AccuDraw and triggering _OnDynamicFrame.
        - Saves the current data point location.
        - Sets up and prompts for the next action.
        - If two points are collected, updates the tool setting and gets the end point.
        - Creates a new line element and adds it to the active model.
        - Clears the points and starts the next line from the end of the current line.
        - Checks if the tool should exit after creating a single line in single-shot mode.

        :param ev: The event containing the data point information.
        :type ev: Event
        :return: False if less than two points are collected, otherwise the result of _CheckSingleShot.
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
       

    def _OnResetButton(self, ev):
        """
        Handles the reset button event for the LineCreator tool.

        This method performs the following actions:

        - Restarts the LineCreator tool by calling the _OnRestartTool method.

        :param ev: The event containing the reset button information.
        :type ev: Event
        :return: Always returns True.
        :rtype: bool
        """
        self._OnRestartTool()
        return True
        
    def __UpdateToolSettingAndGetEndPoint(self, ev):
        """
        Updates the tool settings and calculates the end point based on the current event.

        This method performs the following actions:

        - Calculates the dynamic normal direction and length from the start point to the current event point.
        - Updates the length in the tool settings if the use_length attribute is not set.
        - Updates the angle in the tool settings if the use_angle attribute is not set.
        - Converts the angle to degrees and updates the angle display.
        - Calculates the end point based on the updated length and angle.

        :param ev: The event containing the data point information.
        :type ev: Event
        :return: The calculated end point.
        :rtype: DPoint3d
        """
        startPt = self.m_points[0]
        dynamicEndPt = ev.GetPoint()

        dynamicNormalDir = dynamicEndPt - startPt
        dynamicNormalDir.Normalize()

        dynamicLength = dynamicEndPt.Distance(startPt)

        if not self.toolSettingDlg.tool_setting.use_length.get():
            self.toolSettingDlg.tool_setting.length = dynamicLength
            wstr = WString()
            StringUtility.FromUors(wstr, self.toolSettingDlg.tool_setting.length)
            displayStr = str(wstr)           
            self.toolSettingDlg.lengthVar.set(displayStr)    
        else:
            wstr = WString(self.toolSettingDlg.lengthVar.get())
            length = StringUtility.ToUors(wstr)
            self.toolSettingDlg.tool_setting.length = length

        PI = 3.1415926

        if not self.toolSettingDlg.tool_setting.use_angle.get():
            xAxis = DVec3d.UnitX()            
            self.toolSettingDlg.tool_setting.angle = dynamicNormalDir.AngleTo(xAxis)
            if (dynamicNormalDir.y < 0):
                self.toolSettingDlg.tool_setting.angle = 2*PI -self.toolSettingDlg.tool_setting.angle 

            degrees = self.toolSettingDlg.tool_setting.angle * 180.0 / PI
            wstr = WString()
            StringUtility.FromDirection(wstr, degrees, AngleFormatVals.eActive, False, True, -1, -1, True, False, ISessionMgr.ActiveDgnModelRef)
            displayStr = str(wstr)
            self.toolSettingDlg.angleVar.set(displayStr)
        else:
            degree = StringUtility.ToDirection(WString(self.toolSettingDlg.angleVar.get())) #float(self.toolSettingDlg.angleVar.get())
            self.toolSettingDlg.tool_setting.angle = degree * PI / 180.0

        dir = DVec3d.UnitX()
        dir.RotateXY(self.toolSettingDlg.tool_setting.angle)
        endPt = startPt + dir * self.toolSettingDlg.tool_setting.length
        return endPt             

    def _OnDynamicFrame(self, ev):

        """
        Handles the dynamic frame event for the LineCreator tool.

        This method performs the following actions:

        - Creates a temporary array of points including the current points and the updated end point.
        - Updates the tool settings and calculates the end point based on the current event.
        - Creates a new element with the temporary points.
        - Sets up the redraw elements for dynamic display.
        - Redraws the element in the active view set.

        :param ev: The event containing the dynamic frame information.
        :type ev: Event
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
        Retrieves the name of the LineCreator tool.

        This method performs the following actions:

        - Creates a WString with the tool name "LineCreator".
        - Returns the created WString.

        :param name: The name parameter (not used in this method).
        :type name: str
        :return: The name of the tool as a WString.
        :rtype: WString
        """
        s = WString ("LineCreator")
        return s
    
    def _OnCleanup (self):
        """
        Cleans up the LineCreator tool.

        This method performs the following actions:

        - Destroys the tool setting dialog.
        """
        MsTk.allMstkWindows.remove(self.toolSettingDlg)
        self.toolSettingDlg.destroy()

    def CreateElement(self, eeh, points):
        """
        Creates a line element based on the provided points.

        This method performs the following actions:

        - Checks if the number of points is exactly 2.
        - Converts the points into a line element using the DraftingElementSchema.
        - Applies active settings to the created element.

        :param eeh: The EditElementHandle to store the created element.
        :type eeh: EditElementHandle
        :param points: A list of points to define the line.
        :type points: list of DPoint3d
        :return: True if the element is successfully created, False otherwise.
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
        Sets up and prompts the user for the next action in the LineCreator tool.

        This method performs the following actions:

        - Displays a prompt message based on the number of collected points.
        - If one point is collected, prompts the user to enter the next point.
        - If more than one point is collected, prompts the user to enter the next point or reset to complete.
        - If exactly two points are collected, orients AccuDraw to the last segment.

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
        Creates and installs a new instance of the LineCreator tool.

        This method performs the following actions:

        - Creates a new instance of the LineCreator tool with the provided tool ID and prompt.
        - Installs the new tool instance.
        - Creates and initializes the tool setting dialog.
        - Sets the title of the tool setting dialog to "Place Line".
        - Runs the main loop of the tool setting dialog.

        :param toolId: The ID of the tool.
        :type toolId: str
        :param toolPrompt: The prompt message for the tool.
        :type toolPrompt: str
        """

        LineCreator.tool = LineCreator(toolId, toolPrompt)        
        LineCreator.tool.InstallTool()
        LineCreator.tool.toolSettingDlg = LineToolSettingDlg()
        LineCreator.tool.toolSettingDlg.title("Place Line")

if __name__ == "__main__":
    LineCreator.InstallNewInstance(0, 0)
    MsTk.msmainloop()
