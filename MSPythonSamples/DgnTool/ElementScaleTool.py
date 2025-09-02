# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to use DgnElementSetTool to write a basic SCALE ELEMENT tool.
'''

class ElementScaleTool(DgnElementSetTool):

    def __init__(self, toolId):
        """
        Initialize the ElementScale tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_transform = Transform()
        self.m_point = DPoint3d()
        self.m_scale = 1.0

    def _SetupForModify(self, ev, isDynamics):
        """
        Pre-compute the necessary information needed for the _OnElementModify method.

        Tools that modify elements relative to the current cursor location in dynamics, or
        the data button location to accept, should pre-compute the necessary information needed
        for their _OnElementModify method in _SetupForModify. Unless this method returns
        true, _OnElementModify won't be called.

        :param ev: The event containing the point information.
        :type ev: Event
        :param isDynamics: Flag indicating if the modification is in dynamics mode.
        :type isDynamics: bool
        :return: True if the setup is successful, False otherwise.
        :rtype: bool
        """
        anchorPt = DPoint3d()

        # Base class saves the location that was used to accept the element, selection set, or fence.
        if not self._GetAnchorPoint(anchorPt):
            print(False)

        vec = DVec3d()
        
        # Setup translation from accept point to this button event point.
        vec.DifferenceOf(ev.Point, anchorPt)
        self.m_transform.InitFrom(vec)

        self.m_scale = ev.Point.Distance(anchorPt)/anchorPt.Distance(DPoint3d())
        self.m_point = anchorPt

        return True

    def _OnElementModify(self, eeh):
        """
        Apply the transform to the supplied element to scale.
        Will be called both for element dynamics and on the data button to accept the modification.

        :param eeh: The element handle to be modified.
        :type eeh: ElementHandle
        :return: Result of the transform application.
        :rtype: StatusInt
        """
        tInfo = TransformInfo(self.m_transform)
        tInfo.Transform.form3d[0][0] = self.m_scale
        tInfo.Transform.form3d[0][1] = 0
        tInfo.Transform.form3d[0][2] = 0
        tInfo.Transform.form3d[0][3] = self.m_point.x/(self.m_scale + 1.0)
        tInfo.Transform.form3d[1][0] = 0
        tInfo.Transform.form3d[1][1] = self.m_scale
        tInfo.Transform.form3d[1][2] = 0
        tInfo.Transform.form3d[1][3] = self.m_point.y/(self.m_scale + 1.0)
        tInfo.Transform.form3d[2][0] = 0
        tInfo.Transform.form3d[2][1] = 0
        tInfo.Transform.form3d[2][2] = self.m_scale
        tInfo.Transform.form3d[2][3] = self.m_point.z/(self.m_scale + 1.0)
        return eeh.GetHandler(eMISSING_HANDLER_PERMISSION_Transform).ApplyTransform(eeh, tInfo)

    def _OnRestartTool(self):
        """
        Install a new instance of the tool. Will be called in response to external events
        such as undo or by the base class from _OnReinitialize when the tool needs to be
        reset to its initial state.
        """
        ElementScaleTool.s_instance = None  # Clear instance reference
        ElementScaleTool.InstallNewInstance(self.ToolId)

    def _OnCleanup(self):
        """
        Called when current command is being terminated.
        """
        ElementScaleTool.s_instance = None  # Clear instance reference
        super()._OnCleanup()

    def _GetToolName (self, name):
        """
        Customize the tool name prompt at bottom left.

        :return: Tool name.
        :rtype: WString
        """
        s = WString("Scale Element")
        return s

    def InstallNewInstance(toolId):
        """
        Create and install a new instance of the tool. If InstallTool returns ERROR,
        the new tool instance will be freed/invalid. Never call delete on RefCounted classes.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        tool = ElementScaleTool(toolId)
        tool.InstallTool()
        ElementScaleTool.s_instance = tool  # Keep instance reference

if __name__ == "__main__":
    SelectionSetManager.GetManager().EmptyAll() # Clear selection
    ElementScaleTool.InstallNewInstance(1)
