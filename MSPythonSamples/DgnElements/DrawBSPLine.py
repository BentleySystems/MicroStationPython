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
Sample demonstrating how to create a B-spline curve element.
'''

def drawBSPLine():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)

    # Points the curve passes through.
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, 0.0, 0.0))
    points.append(DPoint3d(0.0, 1.0, 0.0))
    points.append(DPoint3d(1.0, 2.0, 0.0))
    points.append(DPoint3d(2.0, 2.0, 0.0))
    points.append(DPoint3d(3.0, 1.0, 0.0))
    points.append(DPoint3d(3.0, 0.0, 0.0))
    # Amplify the size of the curve.
    SCALE = 10000.0
    for i in range(0, len(points)):
        points[i].x *= SCALE
        points[i].y *= SCALE
        points[i].z *= SCALE
    
    # Set the points to draw curve.
    curve = MSBsplineCurve.CreateFromPolesAndOrder(points, None, None, 3, False, False)
    # Draw the curve based of the points.
    ICurvePrimitive.CreateBsplineCurve(curve)
    bspLineEditElementHandle = EditElementHandle()
    result = BSplineCurveHandler.CreateBSplineCurveElement(bspLineEditElementHandle, None, curve, dgnModel.Is3d(), dgnModel)
        
    if result == BSplineStatus.eBSPLINE_STATUS_Success:
        bspLineEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("BSP Line curve added successfully in the DGN Model.", "", False)
    else:
        MessageCenter.ShowErrorMessage("BSP Line curve not added in the DGN Model.", "", False)

#main
if __name__ == "__main__":
    drawBSPLine()