
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to create a mesh element baseed on DgnElementSetTool.
'''

# Command IDs for mesh creation
COMMAND_PlaceMeshFunction = 0
COMMAND_PlaceMeshClass = 1

class MeshCreateTool(DgnElementSetTool):
    """
    Tool to create Mesh element using user-selected points. 
    """
    def __init__(self, toolId):
        """
        Initialize the tool with the given tool ID.
        
        :param toolId: Identifier for the tool (e.g., COMMAND_PlaceMeshFunction or COMMAND_PlaceMeshClass).
        """
        super().__init__(toolId)
        self.m_self = self  # Keep self-reference.
        self.m_Points = DPoint3dArray()  # Stores user-selected points.
        self.activeModel = ISessionMgr.ActiveDgnModelRef  # Reference to the active design model.

    def _OnRestartTool(self):
        """Restart the tool by installing a new instance."""
        MeshCreateTool.InstallNewInstance(self.GetToolId())

    def _OnResetButton(self, ev):
        """
        Handle reset button to restart the tool.
        This creates the final element, clears the points, and starts the tool again.
        
        :param ev: Event data for the reset button action.
        """
        self.CreateElement(self.m_Points)  # Finalize the element creation.
        self.m_Points.clear()  # Clear the points for a fresh start.
        self.m_Points.append(ev.GetPoint())  # Add the reset point.
        self._OnRestartTool()

    def CreateDynamicElements(self, agenda: ElementAgenda, points: DPoint3dArray):
        """
        Create temporary dynamic elements based on user points for visualization.
        
        :param agenda: The agenda for temporary elements to redraw.
        :param points: Array of user-selected points.
        :return: True if dynamic elements are created successfully, otherwise False.
        """
        if len(points) < 2:  # At least two points are required for a line.
            return False

        eeh = EditElementHandle()
        pt0 = points[0]

        # Create line segments between consecutive points.
        for i in range(1, len(points)):
            pt1 = points[i]
            if BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement(
                eeh, ICurvePrimitive.CreateLine(DSegment3d(pt0, pt1)), None,
                self.activeModel.Is3d(), self.activeModel
            ):
                ElementPropertyUtils.ApplyActiveSettings(eeh)
                agenda.Insert(eeh)
            pt0 = pt1

        # Create the final segment to close the shape if needed.
        pt0, pt1 = points[0], points[-1]
        if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(
            eeh, ICurvePrimitive.CreateLine(DSegment3d(pt0, pt1)), None,
            self.activeModel.Is3d(), self.activeModel
        ):
            return False

        ElementPropertyUtils.ApplyActiveSettings(eeh)
        agenda.Insert(eeh)
        return True

    def CreateElement(self, points: DPoint3dArray):
        """
        Create a mesh element based on the collected points.
        
        :param points: Array of user-selected points.
        :return: False if there are insufficient points, True otherwise.
        """
        if len(self.m_Points) < 3:  # At least three points are needed for a polyface.
            return False

        eeh = EditElementHandle()

        if self.ToolId == COMMAND_PlaceMeshClass:
            # Create a variable-size indexed mesh element.
            polyface = PolyfaceHeader.CreateVariableSizeIndexed()
            polyface.AddPolygon(self.m_Points)
            status = MeshHeaderHandler.CreateMeshElement(eeh, None, polyface, True, self.activeModel)
        
        elif self.ToolId == COMMAND_PlaceMeshFunction:
            # Create a fixed block-coordinate mesh element.
            polyface = PolyfaceHeader.CreateFixedBlockCoordinates(4)
            polyface.Point().CopyVectorFrom(self.m_Points)
            status = MeshHeaderHandler.CreateMeshElement(eeh, None, polyface, True, self.activeModel)

        if BentleyStatus.eSUCCESS == status:
            ElementPropertyUtils.ApplyActiveSettings(eeh)
            eeh.AddToModel()

    def SetupAndPromptForNextAction(self):
        """
        Set up the prompts for user input and manage AccuDraw context for point selection.
        """
        msgStr = (
            "Enter first point:" if len(self.m_Points) == 0 else
            "Enter next point:" if len(self.m_Points) < 3 else
            "Enter next point or reset to complete:"
        )
        NotificationManager.OutputPrompt(msgStr)

        if len(self.m_Points) >= 2:
            xVec = DVec3d.FromStartEndNormalize(self.m_Points[0], self.m_Points[-1])
            AccuDraw.GetInstance().SetContext(AccuDrawFlags.eACCUDRAW_SetXAxis, None, xVec)

    def _OnDynamicFrame(self, ev):
        """
        Handle dynamic frame updates during point selection.
        
        :param ev: Event data for the dynamic frame.
        """
        tmpPts = DPoint3dArray(self.m_Points)
        agenda = ElementAgenda()
        tmpPts.append(ev.GetPoint())

        if not self.CreateDynamicElements(agenda, tmpPts):
            return

        redrawElems = RedrawElems()
        redrawElems.SetDynamicsViews(IViewManager.GetActiveViewSet(), ev.GetViewport())
        redrawElems.SetDrawMode(eDRAW_MODE_TempDraw)
        redrawElems.SetDrawPurpose(DrawPurpose.eDynamics)

        for ag in agenda:
            redrawElems.DoRedraw(ag)

    def _OnDataButton(self, ev):
        """
        Handle the data button click to add points.
        
        :param ev: Event data for the button click.
        """
        if len(self.m_Points) == 0:
            self._BeginDynamics()
        if self.ToolId == COMMAND_PlaceMeshFunction:
            if len(self.m_Points)== 4:
                self.CreateElement(self.m_Points)
                self.m_Points.clear() 
        self.m_Points.append(ev.GetPoint())
        self.SetupAndPromptForNextAction()
        return False

    def _OnPostInstall(self):
        """
        Enable snapping and set up the tool upon installation.
        """
        AccuSnap.GetInstance().EnableSnap(True)
        self.SetupAndPromptForNextAction()
        super()._OnPostInstall()

    @staticmethod
    def InstallNewInstance(toolId):
        """
        Install a new instance of the tool with the given ID.
        
        :param toolId: Identifier for the tool.
        """
        tool = MeshCreateTool(toolId)
        tool.InstallTool()

