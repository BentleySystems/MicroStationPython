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

'''
/*=================================================================================**//**
* Example showing how to use DgnElementSetTool to write a basic MOVE ELEMENT tool.
* 
* The base class populates an ElementAgenda from a pick or selection set on the 1st
* data button and starts element dynamics. The 2nd data button accepts the modification.
*
* The base class provides generic user prompts such as Identify Element and
* Accept/Reject Selection. Override _SetupAndPromptForNextAction to supply more detailed
* direction to the user.
* 
* This sub-class is responsible for applying the desired modification to the element(s). 
* The _OnElementModify method is called for each entry in the ElementAgenda both during
* element dynamics as well as for the final accept.
* 
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
class ElementMover(DgnElementSetTool):
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def __init__(self, toolId):
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_transform = Transform()
        self.m_self = self # Keep self reference
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * Tools that modify elements relative to the current cursor location in dynamics, or
    * the data button location to accept, should pre-compute the necessary information needed
    * for their _OnElementModify method in _SetupForModify. Unless this method returns
    * true, _OnElementModify won't be called.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _SetupForModify(self, ev, isDynamics):
        anchorPt = DPoint3d()

        # Base class saves the location that was used to accept the element, selection set, or fence.
        if not self._GetAnchorPoint(anchorPt):
            return False

        vec = DVec3d()
        
        # Setup translation from accept point to this button event point.
        vec.DifferenceOf(ev.Point, anchorPt)
        self.m_transform.InitFrom(vec)

        return True

    '''
    /*---------------------------------------------------------------------------------**//**
    * Apply the transform previously computed in _SetupForModify to the supplied element.
    * Will be called both for element dynamics and on the data button to accept the modification.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnElementModify(self, eeh):
        tInfo = TransformInfo(self.m_transform)
        return eeh.GetHandler(eMISSING_HANDLER_PERMISSION_Transform).ApplyTransform(eeh, tInfo)

    '''
    /*---------------------------------------------------------------------------------**//**
    * Install a new instance of the tool. Will be called in response to external events
    * such as undo or by the base class from _OnReinitialize when the tool needs to be
    * reset to it's initial state.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnRestartTool(self):
        ElementMover.InstallNewInstance(self.ToolId)

    '''
    /*---------------------------------------------------------------------------------**//**
    * Method to create and install a new instance of the tool. If InstallTool returns ERROR,
    * the new tool instance will be freed/invalid. Never call delete on RefCounted classes.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def InstallNewInstance(toolId):
        tool = ElementMover(toolId)
        tool.InstallTool()

'''
/*=================================================================================**//**
* Default entrypoint for current module unit.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
if __name__ == "__main__":
    ElementMover.InstallNewInstance(1)

