from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to create a DgnElementSetTool in python and create a mesh element with the tool.
'''

class PolyfaceCreateTool(DgnElementSetTool):
    """Tool to create polyface elements using user-selected points."""

    def __init__(self, toolId):
        """Initialize the tool with the given tool ID."""
        super().__init__(toolId)
        self.m_self = self  # Keep self-reference.
        self.m_Points = DPoint3dArray()  # Stores user-selected points.
        self.activeModel = ISessionMgr.ActiveDgnModelRef

    def _OnRestartTool(self):
        """Restart the tool by installing a new instance."""
        PolyfaceCreateTool.InstallNewInstance(self.GetToolId())
    
    def _OnResetButton(self, ev):
        """Handle reset button to restart the tool."""
        self._OnRestartTool()
        return True
    
    def CreateDynamicElements(self, agenda: ElementAgenda, points: DPoint3dArray):
        """Create temporary dynamic elements based on user points."""
        if len(points) < 2:
            return False
        eeh = EditElementHandle()
        pt0 = points[0]

        # Create line segments between points.
        for i in range(1, len(points)):
            pt1 = points[i]
            if BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement(
                eeh, ICurvePrimitive.CreateLine(DSegment3d(pt0, pt1)), None, 
                self.activeModel.Is3d(), self.activeModel
            ):
                ElementPropertyUtils.ApplyActiveSettings(eeh)
                agenda.Insert(eeh)
            pt0 = pt1

        # Create final segment to close the shape.
        pt0, pt1 = points[0], points[-1]
        if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(
            eeh, ICurvePrimitive.CreateLine(DSegment3d(pt0, pt1)), None,
            self.activeModel.Is3d(), self.activeModel
        ):
            return False
        ElementPropertyUtils.ApplyActiveSettings(eeh)
        agenda.Insert(eeh)
        return True
    
    def CreateElement(self, eeh, points):
        """Create a polyface element with the given points."""
        if len(points) != 3:
            return False
        polyface = PolyfaceHeader.CreateVariableSizeIndexed()
        polyface.AddPolygon(points)

        if BentleyStatus.eSUCCESS != MeshHeaderHandler.CreateMeshElement(
            eeh, None, polyface, True, self.activeModel
        ):
            return False
        ElementPropertyUtils.ApplyActiveSettings(eeh)
        return True
    
    def SetupAndPromptForNextAction(self):
        """Set up prompts for user input."""
        msgStr = (
            "Enter first point:" if len(self.m_Points) == 0 else
            "Enter next point:" if len(self.m_Points) == 1 else
            "Enter next point or reset to complete:"
        )
        NotificationManager.OutputPrompt(msgStr)

        if len(self.m_Points) != 3:
            return

        xVec = DVec3d.FromStartEndNormalize(self.m_Points[0], self.m_Points[-1])
        AccuDraw.GetInstance().SetContext(AccuDrawFlags.eACCUDRAW_SetXAxis, None, xVec)

    def _OnDynamicFrame(self, ev):
        """Handle dynamic frame updates during point selection."""
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

    def _OnDataButton(self, ev: DgnButtonEvent):
        """Handle data button press to add points and create elements."""
        if len(self.m_Points) == 0:
            self._BeginDynamics()
        
        self.m_Points.append(ev.GetPoint())
        self.SetupAndPromptForNextAction()

        if len(self.m_Points) < 3:
            return False

        eeh = EditElementHandle()
        if self.CreateElement(eeh, self.m_Points):
            eeh.AddToModel()

        self.m_Points.clear()
        self.m_Points.append(ev.GetPoint())
        return False   
    
    def _OnPostInstall(self):
        """Enable snapping and set up the tool on installation."""
        AccuSnap.GetInstance().EnableSnap(True)
        super()._OnPostInstall()

    @staticmethod
    def InstallNewInstance(toolId):
        """Install a new tool instance with the given ID."""
        tool = PolyfaceCreateTool(toolId)
        tool.InstallTool()

def StartPolyfaceCreateTool():
    PolyfaceCreateTool.InstallNewInstance(1)

