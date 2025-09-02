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
Sample demonstrating how to create a curve element.
'''

def drawCurve():
    """
    Draws a curve in the active DGN model.
    This function selects the active DGN model, creates a set of points through which the curve will pass,
    scales these points, and then creates and adds the curve element to the model.
    The points are then scaled by a factor of 10000.0.
    If the curve is successfully added to the model, an informational message is displayed.
    Otherwise, an error message is shown.
    Raises:
        Exception: If the active DGN model is not selected or if the curve cannot be added to the model.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)

    # Points the curve passes through.
    curvePoints = DPoint3dArray()
    curvePoints.append(DPoint3d(0.0, 1.0, 0.0))
    curvePoints.append(DPoint3d(0.0, 0.0, 0.0))
    curvePoints.append(DPoint3d(0.0, -5.0, 0.0))
    curvePoints.append(DPoint3d(5.0, -5.0, 0.0))
    curvePoints.append(DPoint3d(5.0, 0.0, 0.0))
    curvePoints.append(DPoint3d(5.0, 1.0, 0.0))

    # Amplify the size of the curve.
    SCALE = 10000.0  
    for i in range(0, len(curvePoints)):
        curvePoints[i].x *= SCALE
        curvePoints[i].y *= SCALE
        curvePoints[i].z *= SCALE

    curveElementHandle = EditElementHandle()
    result = CurveHandler.CreateCurveElement(curveElementHandle, None, curvePoints, dgnModel.Is3d(), dgnModel)
    if result == BentleyStatus.eSUCCESS:
        curveElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("Curve added successfully in the DGN Model.", "", False)
    else:
        MessageCenter.ShowErrorMessage("Curve not added in the DGN Model.", "", False)

#main
if __name__ == "__main__":
    drawCurve()