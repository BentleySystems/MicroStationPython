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
* Example showing how to use DgnElementSetTool to write a MODIFY ELEMENT tool.
*
* This tool will move the closest vertex on a line or linestring.
* 
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
class ElementModifier(DgnElementSetTool):
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def __init__(self, toolId):
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_isDynamics = False
        self.m_ev = None
        self.m_self = self # Keep self referenced
    
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _DoGroups(self):
        return False # Pick single element, don't include graphic and named group members...
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _AllowSelection(self):
        return DgnElementSetTool.eUSES_SS_None # Don't support selection sets...
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def GetCloseVertex(self, location):
        nSegments = 1 # If it's not a linestring (ex. line) there's only a single segment.

        if ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString == location.curve.GetCurvePrimitiveType():
            points = location.curve.GetLineString()
            
            if len(points) < 3:
                nSegments = 1
            else:
                nSegments = len(points) - 1
        
        uSegRange = float(1.0 / nSegments)
        closeVertex = int((location.fraction + uSegRange*0.5) / uSegRange)
        
        return closeVertex
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _SetupForModify(self, ev, isDynamics):
        self.m_isDynamics = isDynamics
        self.m_ev = ev
        
        return True
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnElementModify(self, eeh):
        # NOTE: Since we've already validated the element in OnPostLocate and don't support groups/selection sets we don't have to check it again here.
        locatePoint = DPoint3d()
        curve = ICurvePathQuery.ElementToCurveVector(eeh)
        location = CurveLocationDetail()

        self._GetAnchorPoint(locatePoint)

        # Get curve location detail from accept point.
        if not curve.ClosestPointBounded(locatePoint, location):
            return BentleyStatus.eERROR

        # Get the closest vertex from the curve location detail.
        closeVertex = self.GetCloseVertex(location)
        primitive = curve[0]
        
        # Update closest vertex on line/line string with current button location.
        if primitive.GetCurvePrimitiveType() == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line:
            segment = primitive.GetLine()
            
            segment.SetPoint(self.m_ev.GetPoint(), closeVertex)
            primitive = ICurvePrimitive.CreateLine(segment) # Replace line primitive with a new primitive with modified point.
        elif primitive.GetCurvePrimitiveType() == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString:
            points = primitive.GetLineString()

            points[closeVertex] = self.m_ev.GetPoint()
            primitive = ICurvePrimitive.CreateLineString(points) # Replace linestring primitive with a new primitive with modified point.
            
        # Give the element's handler a chance to update itself from the modified curve vector.
        pathEdit = eeh.GetHandler()
        
        if pathEdit != None and pathEdit.SetCurveVector(eeh, curve) == BentleyStatus.eSUCCESS:
            return BentleyStatus.eSUCCESS
            
        # Handler didn't choose to update itself, create a new element to represent the modified curve vector.
        return DraftingElementSchema.ToElement(eeh, curve, eeh, eeh.GetModelRef().Is3d(), eeh.GetModelRef())
        
    '''
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def _OnPostLocate(self, path, cantAcceptReason):
        if not DgnElementSetTool._OnPostLocate(self, path, cantAcceptReason):
            return False

        eh = ElementHandle(path.GetHeadElem(), path.GetRoot())
        curve = ICurvePathQuery.ElementToCurveVector(eh)

        # Accept elements that are open paths with one or more linear segments (ex. line or linestring).
        if curve==None or (not curve.IsOpenPath()):
            return False

        primitiveType = curve.HasSingleCurvePrimitive()
        if primitiveType == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line or primitiveType == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString:
            return True
        
        return False
     
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
        ElementModifier.InstallNewInstance(self.GetToolId())
     
    '''
    /*---------------------------------------------------------------------------------**//**
    * Method to create and install a new instance of the tool. If InstallTool returns ERROR,
    * the new tool instance will be freed/invalid. Never call delete on RefCounted classes.
    *
    * @bsimethod                                                              Bentley Systems
    +---------------+---------------+---------------+---------------+---------------+------*/
    '''
    def InstallNewInstance(toolId):
        tool = ElementModifier(toolId)
        tool.InstallTool()

'''
/*=================================================================================**//**
* Default entrypoint for current module unit.
*
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
if __name__ == "__main__":
    ElementModifier.InstallNewInstance(1)
