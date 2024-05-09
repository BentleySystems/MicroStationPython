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

from tkinter import *
import tkinter
import win32gui
 


class MsTk(Tk):
    def __init__(self):
        Tk.__init__(self)
    def msmainloop(self):
        self.attachedToMstn = False
        while tkinter._default_root != None :
            self.update ()
            if tkinter._default_root == None:
                break

            if not win32gui.IsWindow(self.winfo_id()):
                break
            
            if (not self.attachedToMstn):                
                hFrame = win32gui.GetParent(self.winfo_id())
                if  hFrame != 0:
                    PyCadInputQueue.AttachTkinterToolSetting(hFrame)
                    self.attachedToMstn = True

            PyCadInputQueue.PythonMainLoop() 


class LineToolSetting:
    def __init__(self):
        self.use_length = BooleanVar()
        self.length = 0.0
        self.use_angle = BooleanVar()
        self.angle = 0.0

class LineToolSettingDlg(MsTk): # must derive from MsTk which is reuseable module for interacting with Microstation UI system
    def __init__(self):
        super(LineToolSettingDlg, self).__init__()
        self.tool_setting = LineToolSetting ()
        self.populate_tool_setting()

    def populate_tool_setting(self): # all are Tikinter codes without Microstation logic involved
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
#        win32api.MessageBox(0, "to destroy window", "_OnCleanup")
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
        tool.toolSettingDlg = LineToolSettingDlg()
        tool.toolSettingDlg.title("Place Line")
        tool.toolSettingDlg.msmainloop()     

'''
/*=================================================================================**//**
* Default entrypoint for current module unit.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
if __name__ == "__main__":
    LineCreator.InstallNewInstance(0, 0)
