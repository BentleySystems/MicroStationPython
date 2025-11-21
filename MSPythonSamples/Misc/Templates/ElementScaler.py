from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import tkinter as tk

class ElementScaleTool(DgnElementSetTool):
    def __init__(self, toolId):
        """
        Initialize the ElementScale tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        DgnElementSetTool.__init__(self, toolId)  # C++ base's __init__ must be called.
        self.m_transform = Transform()
        self.m_point = DPoint3d()
        self.m_scale = 1.0

    def _SetupForModify(self, ev, isDynamics):
        """
        Pre-compute the necessary information needed for the _OnElementModify method.

        :param ev: The event containing the point information.
        :type ev: DgnButtonEvent
        :param isDynamics: Flag indicating if the modification is in dynamics mode.
        :type isDynamics: bool
        :return: True if the setup is successful, False otherwise.
        :rtype: bool
        """
        anchorPt = DPoint3d()

        # Base class saves the location that was used to accept the element, selection set, or fence.
        if not self._GetAnchorPoint(anchorPt):
            return False

        self.m_point = anchorPt
        self.m_scale = float(self.scale_factor.get())  # Get scale factor from user input

        return True

    def _OnElementModify(self, eeh):
        """
        Apply the transform to the supplied element to scale.

        :param eeh: The element handle to be modified.
        :type eeh: ElementHandle
        :return: Result of the transform application.
        :rtype: StatusInt
        """
        tInfo = TransformInfo(self.m_transform)
        tInfo.Transform.form3d[0][0] = self.m_scale
        tInfo.Transform.form3d[1][1] = self.m_scale
        tInfo.Transform.form3d[2][2] = self.m_scale
        tInfo.Transform.form3d[0][3] = self.m_point.x * (1 - self.m_scale)
        tInfo.Transform.form3d[1][3] = self.m_point.y * (1 - self.m_scale)
        tInfo.Transform.form3d[2][3] = self.m_point.z * (1 - self.m_scale)
        return eeh.GetHandler(eMISSING_HANDLER_PERMISSION_Transform).ApplyTransform(eeh, tInfo)

    def _OnRestartTool(self):
        """
        Install a new instance of the tool.
        """
        ElementScaleTool.InstallNewInstance(self.ToolId)

    def _OnCleanup(self):
        """
        Called when current command is being terminated.
        """
        ElementScaleTool.s_instance = None  # Clear instance reference
        super()._OnCleanup()

    def _GetToolName(self, name):
        """
        Customize the tool name prompt at bottom left.

        :return: Tool name.
        :rtype: WString
        """
        s = WString("Scale Element")
        return s

    def InstallNewInstance(toolId):
        """
        Create and install a new instance of the tool.

        :param toolId: Identifier for the tool.
        :type toolId: int
        """
        tool = ElementScaleTool(toolId)
        tool.InstallTool()
        ElementScaleTool.s_instance = tool

    def show_scale_input_dialog(self):
        """
        Show a dialog to input the scale factor.
        """
        root = tk.Tk()
        root.title("Scale Factor Input")

        tk.Label(root, text="Enter Scale Factor:").pack()
        self.scale_factor = tk.StringVar()
        tk.Entry(root, textvariable=self.scale_factor).pack()
        tk.Button(root, text="OK", command=root.destroy).pack()

        root.mainloop()

    def _OnPostInstall(self):
        """
        Perform post-installation steps for the tool.
        """
        self.show_scale_input_dialog()
        super()._OnPostInstall()

# Install the tool
ElementScaleTool.InstallNewInstance(1)