# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright:(c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from math import pi
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''
Sample demonstrating how to create a Grouped Hole element.
'''

def drawGroupedHole():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)

    groupedHoleEditElementHandle = EditElementHandle()
    innerEllipseEditElementHandle = EditElementHandle()
    outerEllipseEditElementHandle = EditElementHandle()
    # Set the element agenda.
    groupedHoles = ElementAgenda()
    # Set the points for the outer and inner circle.
    outerEllipsePoint = DPoint3d(5.0, 5.0, 0.0)
    innerEllipsePoint = DPoint3d(0.0, 0.0, 0.0)
    # Set the scales to amplify the size of the circles.
    scale = 10000

    # Create a structure for it to have a hole.
    # Create the inner circle.
    EllipseHandler.CreateEllipseElement(outerEllipseEditElementHandle, None, outerEllipsePoint, pi/6*scale, pi/7*scale, 0.0 , False, dgnModel)
    outerEllipseEditElementHandle.AddToModel()
    # Create the outer circle.
    EllipseHandler.CreateEllipseElement(innerEllipseEditElementHandle, None, innerEllipsePoint, pi/4*scale, pi/5*scale, 0.0 , False, dgnModel)
    innerEllipseEditElementHandle.AddToModel()

    outerEllipseReference = outerEllipseEditElementHandle.GetElementRef()
    groupedHoles.Insert(outerEllipseReference, dgnModel, False)
    result = GroupedHoleHandler.CreateGroupedHoleElement(groupedHoleEditElementHandle, innerEllipseEditElementHandle, groupedHoles)
        
    if result == BentleyStatus.eSUCCESS:
        groupedHoleEditElementHandle.AddToModel()
        MessageCenter.ShowInfoMessage("Grouped hole created successfully in the DGN Model.", "", False)
    else:
        MessageCenter.ShowErrorMessage("Grouped hole not added in the DGN Model.", "", False)

#main
if __name__ == "__main__":
    drawGroupedHole()