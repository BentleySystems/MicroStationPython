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
* Example showing how to use DgnRegionElementTool to write a CREATE REGION by FLOOD tool.
* 
* The base class handles collecting the region boundary from the elements in the view
* or selection set. The sub-class is responsible for doing something with the new region
* and optionally processing the original elements that comprise the boundary.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
class ElementFlood(DgnRegionElementTool):
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def __init__(self):
        DgnRegionElementTool.__init__(self) # C++ base's __init__ must be called.
        self.m_regionParams = RegionParams()
        self.m_self = self # Keep self reference
    
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _WantFloodDynamicArea(self):
        return True # Show valid flood region under the cursor without waiting for accept point.
       
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _GetRegionCreateMode(self):
        return DgnRegionElementTool.eREGION_CREATE_ByParams # Create region using _GetRegionParams.
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    * Setup region params to create region by flood (or boolean).
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _GetRegionParams(self):
        self.m_regionParams.SetType(RegionType.eFlood) # Create region by flood using seed point.
        self.m_regionParams.SetFloodParams(RegionLoops.eOuter, 0.0) # Allow regions to be created with holes.

        return self.m_regionParams
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    * Process a region element created by this tool.
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnProcessRegionResult(self, eeh):
        ElementPropertyUtils.ApplyActiveSettings(eeh) # Apply active symbology to new region element.
        ElementPropertyUtils.ApplyActiveAreaSettings(eeh, -1) # Apply active area fill to new region element.
        eeh.AddToModel()

        return BentleyStatus.eSUCCESS
        
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
        ElementFlood.InstallNewInstance()
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * Method to create and install a new instance of the tool. If InstallTool returns ERROR,
    * the new tool instance will be freed/invalid. Never call delete on RefCounted classes.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def InstallNewInstance():
        tool = ElementFlood()
        tool.InstallTool()

'''
/*=================================================================================**//**
* Default entrypoint for current module unit.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
if __name__ == "__main__":
    ElementFlood.InstallNewInstance()

