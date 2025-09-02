# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
This sample demonstrates creating group hole by selecting outer and inner boundary. (Used:SendCommand, SendDataPointForLocate, SendDataPoint)
1. Invoke "Group Hole" Command.
2. Select outer and inner boundary element.
'''

# Help method: Create a shape by points and add it to the active model
def AddShape (points):
    """
    Adds a shape element to the active DGN model.

    :param points: A list of points defining the shape.
    :type points: list
    :return: An EditElementHandle object if the shape is successfully added to the model, otherwise None.
    :rtype: EditElementHandle or None
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    eeh = EditElementHandle()
    ShapeHandler.CreateShapeElement (eeh, None, points, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
    if eeh.AddToModel() != 0:
        return None
    return eeh

# Create outer boundary shape.
points = DPoint3dArray()
points.append (DPoint3d (0.0, 0.0, 0.0))
points.append (DPoint3d (5.0, 0.0, 0.0))
points.append (DPoint3d (5.0, 5.0, 0.0))
points.append (DPoint3d (0.0, 5.0, 0.0))
points.append (DPoint3d (0.0, 0.0, 0.0))

outer = AddShape (points)

# Create inner boundary shape
points.clear()
points.append (DPoint3d (1.0, 1.0, 0.0))
points.append (DPoint3d (4.0, 1.0, 0.0))
points.append (DPoint3d (4.0, 4.0, 0.0))
points.append (DPoint3d (1.0, 4.0, 0.0))
points.append (DPoint3d (1.0, 1.0, 0.0))

inner = AddShape (points)

if inner != None and outer != None:
    # Invoke "Group Hole" Command and select the outer and inner boundary.
    PyCadInputQueue.SendCommand ("GROUP HOLES")
    PyCadInputQueue.SendDataPointForLocate (outer.GetElementRef(), DPoint3d (0.0,0.0,0.0))
    PyCadInputQueue.SendDataPointForLocate (inner.GetElementRef(), DPoint3d (1.0,1.0,0.0))
    PyCadInputQueue.SendDataPoint (DPoint3d (1.0,1.0,0.0), 1)




