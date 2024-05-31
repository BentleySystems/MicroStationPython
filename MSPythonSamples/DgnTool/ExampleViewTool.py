# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
import pydoc
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
/*=================================================================================**//**
* Example showing how to use DgnViewTool to write a viewing tool.
* 
* A simple viewing tool example that zooms the view and centers the accept.
* Demonstrates using IndexedViewSet and IViewManager to update the view.
* By default a DgnViewTool will exit on a reset button event.
* 
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
class ExampleViewTool(DgnViewTool):
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def __init__(self, toolName, toolPrompt):
        DgnViewTool.__init__(self, toolName, toolPrompt) # C++ base's __init__ must be called.        
        self.m_self = self # Keep self reference
    
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnDataButton(self, ev):
        vp = ev.GetViewport()

        if vp==None:
            return False # Sub-classes may ascribe special meaning to this status, it's not checked by DgnViewTool.

        centerPt = ev.GetPoint() # The DgnButtonEvent point is always ACTIVE coords.

        vp.ActiveToRoot(centerPt, centerPt) # Need point in ROOT coords for new zoom center (ACTIVE != ROOT when a reference is activated).
        vp.Zoom(centerPt, 0.5, True) # Change the frustum for this viewport by tje supplied scale factor, does not update the view.
        vp.SynchWithViewInfo(True, True) # Add entry to view undo stack so that view previous can nr used to get back to the current view.

        info = IndexedViewSet.FullUpdateInfo()

        info.SetStartEndMsg(True) # View tools should output progress/display complete messages...
        IViewManager.GetActiveViewSet().UpdateView(vp, DgnDrawMode.eDRAW_MODE_Normal, DrawPurpose.eUpdate, info) # Update the display by doing a full update.

        return True
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * Method to create and install a new instance of the tool. If InstallTool returns ERROR,
    * the new tool instance will be freed/invalid. Never call delete on RefCounted classes.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def InstallNewInstance(toolId, toolPrompt):
        tool = ExampleViewTool(toolId, toolPrompt)
        tool.InstallTool()        

'''
/*=================================================================================**//**
* Default entrypoint for current module unit.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
if __name__ == "__main__":
    ExampleViewTool.InstallNewInstance(0, 0)

