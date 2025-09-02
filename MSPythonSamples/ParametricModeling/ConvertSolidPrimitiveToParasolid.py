# $Copyright:(c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

class ConvertPrimitiveToPara(DgnElementSetTool):

    def __init__(self, toolId=1):
        """
        Initializes the instance of the class.

        :param toolId: An identifier for the tool, default is 1.
        :type toolId: int

        This constructor calls the base class `DgnElementSetTool`'s initializer
        to ensure proper initialization of the C++ base class. It also maintains
        a self-reference for internal use.
        """
        DgnElementSetTool.__init__(self, toolId) # C++ base's __init__ must be called.
        self.m_self = self # Keep self reference

    def _OnElementModify(self, elementHandle):
        """
        Handles the modification of an element in the DGN model.
        This method checks if the active DGN model is available and processes the 
        given element if it is of type surface or solid. The element is converted 
        to a body, then back to an element, and added to the model. The original 
        element is deleted from the model.
        
        :param elementHandle: The handle to the element being modified.
        :type elementHandle: ElementHandle
        
        :returns: A status indicating success or failure of the operation.
        :rtype: BentleyStatus
        """
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        dgnModel = ACTIVEMODEL.GetDgnModel()
        if dgnModel != None:
            MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
        else:
            MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        
        if eSURFACE_ELM == elementHandle.GetElementType() or eSOLID_ELM == elementHandle.GetElementType():
            SurfaceOrSolidEditElementHandle = EditElementHandle(elementHandle.ElementId, dgnModel)
            solid = SolidUtil.Convert.ElementToBody(SurfaceOrSolidEditElementHandle, True, True, True)
            smartSolidEditElementHandle = EditElementHandle()
            SolidUtil.Convert.BodyToElement(smartSolidEditElementHandle, solid[1], SurfaceOrSolidEditElementHandle, dgnModel)
            smartSolidEditElementHandle.AddToModel()
            SurfaceOrSolidEditElementHandle.DeleteFromModel()
            return BentleyStatus.eSUCCESS
        return BentleyStatus.eERROR
    
    def _OnRestartTool(self):
        """
        Restarts the tool by installing a new instance of the 
        `ConvertPrimitiveToPara` class with the current tool ID.

        :return: None
        """
        ConvertPrimitiveToPara().InstallInstance(self.GetToolId())

    def InstallInstance(self, toolId):
        """
        Installs an instance of the tool for converting a solid primitive to a Parasolid.

        :param toolId: The identifier of the tool to be installed.
        :type toolId: Any
        
        :raises Exception: If the tool installation fails.
        """
        tool = ConvertPrimitiveToPara(toolId)
        tool.InstallTool()

if __name__ == "__main__":
    ConvertPrimitiveToPara().InstallInstance(1)