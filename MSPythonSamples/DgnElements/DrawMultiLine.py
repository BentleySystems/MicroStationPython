# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''
Sample demonstrating how to create a multi-line element.
'''

def drawMultiLine():
    """
    Draws a multi-line element in the active DGN model.
    This function retrieves the active DGN model and file, sets the style of the multi-line based on the DGN file settings,
    and creates a multi-line element passing through specified points. If successful, the multi-line element is added to the model.
    
    :raises Exception: If the active DGN model or DGN file is not found.
    :returns: None
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
    dgnFile = dgnModel.DgnFile
    if dgnFile != None:
        MessageCenter.ShowInfoMessage("The DGN File exists.", "", False)
    else:
        MessageCenter.ShowErrorMessage("The DGN File does not exists.", "", False)
    
    # Set the style of the mLine based of the DGN file setting.
    multiLineStyle = MultilineStyle.GetSettings(dgnFile)
    multiLineNormal = DVec3d.From(0.0, 0.0, 1.0)
    # Get the points the line passes through.
    multiLinePoints = DPoint3dArray([DPoint3d(00000, 0, 0), DPoint3d(100000, 0, 0), DPoint3d(100000, 150000, 0)])
    
    multiLineElementHandle = EditElementHandle()
    result = MultilineHandler.CreateMultilineElement(multiLineElementHandle, None, multiLineStyle, 1.0, multiLineNormal, multiLinePoints, False, dgnModel)
    if result == BentleyStatus.eSUCCESS:
        multiLineElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("Multi Line element added successfully in the DGN Model.", "", False)
    else:
        MessageCenter.ShowErrorMessage("Multi Line element not added in the DGN Model.", "", False)

#main
if __name__ == "__main__":
    drawMultiLine()
