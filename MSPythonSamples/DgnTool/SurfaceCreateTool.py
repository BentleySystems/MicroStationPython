# $Copyright: (c) 2025 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to implement a tool to create surface element.

Prerequisite: Open MSPythonSamples\\data\\CreateSurfaceBySweep.dgn

For this example, you need to:
1. Select a curve element as a path.
2. Select a profile element.
3. The tool will create a surface element by sweeping the profile along the path.
'''
class SurfaceCreator(DgnElementSetTool):

    def __init__(self, toolId):
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_eehList = list()
               
    def DrawSurface (self, ev, isDynamics):
        if len(self.m_eehList) < 2:
            return False
        
        try:
            viewNum = ev.GetViewport().GetViewNumber()
            retTuple = MstnView.getHomogeneousMaps(viewNum)

            if BentleyStatus.eSUCCESS != retTuple[0]:
                return False
            
            worldToViewMap = retTuple[3]

            path = ICurvePathQuery.ElementToCurveVector(self.m_eehList[0])
            profile = ICurvePathQuery.ElementToCurveVector(self.m_eehList[1])
        
            stPoint = DPoint3d()
            endPoint = DPoint3d()
            path.GetStartEnd (stPoint,endPoint)

            stLoc = CurveLocationDetail()
            path.ClosestPointBoundedXY (stPoint, worldToViewMap.M0, stLoc)

            dynLoc = CurveLocationDetail()
            path.ClosestPointBoundedXY (ev.GetPoint(), worldToViewMap.M0, dynLoc)
      
            dynPath = path.CloneBetweenDirectedFractions (stLoc, dynLoc)
            ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef

            retVal, outbody = SolidUtil.Create.BodyFromSweep(profile, dynPath, ACTIVEMODEL, False, True, False, None, None, None, None)
            if BentleyStatus.eSUCCESS != retVal:
                return False

            surfaceElement = EditElementHandle()
            dgnModel = ACTIVEMODEL.GetDgnModel()
            ret = SolidUtil.Convert.BodyToElement(surfaceElement, outbody, self.m_eehList[1], dgnModel)
            if BentleyStatus.eSUCCESS != ret:
                return False
            
            if not isDynamics:
                surfaceElement.AddToModel()
            else:   
                redrawElems = RedrawElems()
                redrawElems.SetDynamicsViews(IViewManager.GetActiveViewSet(), ev.GetViewport()) # Display in all views, draws to cursor view first...
                redrawElems.SetDrawMode(eDRAW_MODE_TempDraw)
                redrawElems.SetDrawPurpose(DrawPurpose.eDynamics)
                redrawElems.DoRedraw(surfaceElement)
            
        except Exception as e:
            print(f"An error occurred in drawing process \n exception : {e}")
            return False
        
        return True
    
    def _OnPostLocate (self, path, cantAcceptReason):
        if len(self.m_eehList) > 1:
            return False
        
        eeh = EditElementHandle (path.GetHeadElem (), path.GetRoot ())
        if len(self.m_eehList) > 0:
            if self.m_eehList[0].GetElementId() == eeh.GetElementId():
                return False
        
        curve = ICurvePathQuery.ElementToCurveVector(eeh)  # Convert the profile element to a curve vector
        if None == curve:
            return False
            
        return True  
    
    def _BuildLocateAgenda(self, path, ev):
        eeh = super()._BuildLocateAgenda (path, ev)
        self.m_eehList.append(eeh)  # Add the element handle to the list
        return eeh

    def _NeedAcceptPoint(self):
        return len(self.m_eehList) > 1
    
    def _WantAdditionalLocate (self, ev):
        return len(self.m_eehList) < 2
    
    def _WantDynamics (self):
        return True
 
    def _OnDynamicFrame(self, ev):
        self.DrawSurface(ev, True)
            
    def _OnElementModify(self, eeh):
        return BentleyStatus.eERROR

    def _AllowSelection(self):
        return DgnElementSetTool.UsesSelection.eUSES_SS_None
        
    def _OnModifyComplete(self, ev):
        return self.DrawSurface(ev, False)
     
    def _OnRestartTool(self):
        SelectionSetManager.GetManager().EmptyAll()
        SurfaceCreator.s_instance = None  # Clear instance reference
        SurfaceCreator.InstallNewInstance(self.ToolId)

    def _GetToolName (self, name):
        s = WString("Create Surface Element")
        return s

    def InstallNewInstance(toolId):
        tool = SurfaceCreator(toolId)
        tool.InstallTool()
        SurfaceCreator.s_instance = tool  # Keep instance reference
    
    def _SetupAndPromptForNextAction(self):
        elemCount = len(self.m_eehList)
        if elemCount == 0:
            prompt = 'Identify a path element'
        elif elemCount == 1:
            prompt = 'Accept/Reject Selection or identify a profile element'
        elif elemCount == 2:
            prompt = 'Accept - Complete Operation'

        NotificationManager.OutputPrompt(prompt)

if __name__ == "__main__":
    SelectionSetManager.GetManager().EmptyAll()
    SurfaceCreator.InstallNewInstance(1)

