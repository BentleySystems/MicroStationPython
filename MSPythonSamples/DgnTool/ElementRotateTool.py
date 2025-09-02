# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to use DgnElementSetTool to write a basic ROTATE ELEMENT tool.
'''
class ElementRotateTool(DgnElementSetTool):

    def __init__(self, toolId):
        """
        Initialize the ElementRotate tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_point = DPoint3d()
        self.m_rad = 0.0

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
        
        # Setup vector from accept point to this button event point.
        vec.DifferenceOf(ev.Point, anchorPt)

        self.m_rad = DVec2d(1, 0).AngleTo(DVec2d(vec.x, vec.y))
        self.m_point = anchorPt

        return True

    def _OnElementModify(self, eeh):
        """
        Apply the transform to the supplied element to rotate.
        Will be called both for element dynamics and on the data button to accept the modification.

        :param eeh: The element handle to be modified.
        :type eeh: ElementHandle
        :return: Result of the transform application.
        :rtype: StatusInt
        """
        tInfo = TransformInfo(Transform.FromLineAndRotationAngle(self.m_point, self.m_point + DVec3d(0, 0, 1), self.m_rad))
        return eeh.GetHandler(eMISSING_HANDLER_PERMISSION_Transform).ApplyTransform(eeh, tInfo)

    def _OnRestartTool(self):
        """
        Install a new instance of the tool. Will be called in response to external events
        such as undo or by the base class from _OnReinitialize when the tool needs to be
        reset to its initial state.
        """
        ElementRotateTool.s_instance = None # Clear instance reference
        ElementRotateTool.InstallNewInstance(self.ToolId)

    def _OnCleanup(self):
        """
        Called when current command is being terminated.
        """
        ElementRotateTool.s_instance = None # Clear instance reference
        super()._OnCleanup()

    def _GetToolName (self, name):
        """
        Customize the tool name prompt at bottom left.

        :return: Tool name.
        :rtype: WString
        """
        s = WString("Rotate Element")
        return s

    def InstallNewInstance(toolId):
        """
        Create and install a new instance of the tool. If InstallTool returns ERROR,
        the new tool instance will be freed/invalid. Never call delete on RefCounted classes.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        tool = ElementRotateTool(toolId)
        tool.InstallTool()
        ElementRotateTool.s_instance = tool # Keep instance reference

if __name__ == "__main__":
    SelectionSetManager.GetManager().EmptyAll() # Clear selection
    ElementRotateTool.InstallNewInstance(1)
