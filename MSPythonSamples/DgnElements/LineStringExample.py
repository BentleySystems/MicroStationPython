# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to create an element by calling its handler's 'create' method.
'''

def createLineString(basePoint, length=50, count=5, step=10):
    """
    Creates multiple line strings in the active DGN model.

    :param basePoint: The starting point for the first line string.
    :type basePoint: DPoint3d
    :param length: The length of each segment in the line string.
    :type length: float
    :param count: The number of line strings to create.
    :type count: int
    :param step: The distance between the starting points of consecutive line strings.
    :type step: float

    :returns: True if all line strings are successfully created and added to the model, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()
    xDir = DVec3d(1, 0, 0)
    yDir = DVec3d(0, 1, 0)
    xyDir1 = DVec3d(1, 1, 0)
    xyDir2 = DVec3d(1, -1, 0)
    
    # Create line strings into current model
    for i in range(count):
        point1 = basePoint + i*step*yDir
        point2 = point1 + length*xDir
        point3 = point2 + length*xyDir1
        point4 = point3 + length*xDir
        point5 = point4 + length*xyDir2
        
        vertices = []
        vertices.append(point1)
        vertices.append(point2)
        vertices.append(point3)
        vertices.append(point4)
        vertices.append(point5)

        # Create line string element
        status = LineStringHandler.CreateLineStringElement(eeh, None, vertices,
                                                           ACTIVEMODEL.Is3d(), 
                                                           ACTIVEMODEL)
        
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the line string element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True


if __name__ == "__main__":
    if True != createLineString(DPoint3d(0, 0, 0)):
        print("Return false when call createLineString!")