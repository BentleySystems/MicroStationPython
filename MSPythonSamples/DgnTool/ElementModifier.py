# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to use DgnElementSetTool to write a MODIFY ELEMENT tool.
This tool will move the closest vertex on a line or linestring.
'''

class ElementModifier(DgnElementSetTool):
    def __init__(self, toolId):
        """
        Initialize the ElementModifier.

        :param toolId: The ID of the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_isDynamics = False
        self.m_ev = None
        self.m_self = self # Keep self referenced
    
    def _DoGroups(self):
        """
        Determine if groups should be processed.

        :returns: False, indicating single element selection without including graphic and named group members.
        :rtype: bool
        """
        return False # Pick single element, don't include graphic and named group members...
        
    def _AllowSelection(self):
        """
        Determine if selection sets are allowed.

        :returns: The selection set usage type.
        :rtype: DgnElementSetTool.eUSES_SS_None
        """
        return DgnElementSetTool.eUSES_SS_None # Don't support selection sets...
        
    def GetCloseVertex(self, location):
        """
        Get the closest vertex to the given location.

        :param location: The location to find the closest vertex to.
        :type location: LocationType
        :returns: The index of the closest vertex.
        :rtype: int
        """
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
        

    def _SetupForModify(self, ev, isDynamics):
        """
        Set up the modifier for modification.

        :param ev: The event to be modified.
        :type ev: EventType
        :param isDynamics: Flag indicating if dynamics are enabled.
        :type isDynamics: bool
        :returns: True if setup is successful.
        :rtype: bool
        """
        self.m_isDynamics = isDynamics
        self.m_ev = ev
        
        return True
        

    def _OnElementModify(self, eeh):
        """
        Modify the given element.

        :param eeh: The element to be modified.
        :type eeh: EditElementHandle
        :returns: The status of the modification.
        :rtype: BentleyStatus
        """
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
        
    def _OnPostLocate(self, path, cantAcceptReason):
        """
        Handle post-locate event to determine if the element can be accepted for modification.

        :param path: The path of the located element.
        :type path: ElementPath
        :param cantAcceptReason: The reason why the element cannot be accepted.
        :type cantAcceptReason: str
        :returns: True if the element can be accepted, False otherwise.
        :rtype: bool
        """
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
     
    def _OnRestartTool(self):
        """
        Install a new instance of the tool. Will be called in response to external events
        such as undo or by the base class from _OnReinitialize when the tool needs to be
        reset to its initial state.

        :returns: None
        """
        ElementModifier.InstallNewInstance(self.GetToolId())
     
    def InstallNewInstance(toolId):
        """
        Create and install a new instance of the tool. If InstallTool returns ERROR,
        the new tool instance will be freed/invalid. Never call delete on RefCounted classes.

        :param toolId: The ID of the tool.
        :type toolId: int
        :returns: None
        """
        tool = ElementModifier(toolId)
        tool.InstallTool()


if __name__ == "__main__":
    ElementModifier.InstallNewInstance(1)
