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
Example demonstrating how to create multiple ellipses in the active DGN model.
'''

def createEllipseOverride1(basePoint, radius=100,
                           rotation=RotMatrix.FromRowValues(1,0,0,0,1,0,0,0,1),
                           count=10, step=5):
    """
    Creates multiple ellipses in the active DGN model.

    :param basePoint: The center point for the ellipses.
    :type basePoint: DPoint3d
    :param radius: The initial radius of the ellipses.
    :type radius: float
    :param rotation: The rotation matrix for the ellipses.
    :type rotation: RotMatrix
    :param count: The number of ellipses to create.
    :type count: int
    :param step: The decrement step for the radius of each subsequent ellipse.
    :type step: float

    :returns: True if all ellipses are successfully created and added to the model, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()
    centerPoint = basePoint

    # Create ellipses into current model
    for i in range(count):
        axis1 = radius - i*step
        axis2 = axis1 / 2

        # Create ellipse element
        status = EllipseHandler.CreateEllipseElement(eeh, None, 
                                                     centerPoint, 
                                                     axis1, axis2,
                                                     rotation, 
                                                     ACTIVEMODEL.Is3d(), 
                                                     ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the ellipse element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True


def createEllipseOverride2(basePoint, radius=100, rotation=0,
                           count=10, step=5):
    """
    Creates multiple ellipses in the active DGN model with a specified rotation.

    :param basePoint: The center point for the ellipses.
    :type basePoint: DPoint3d
    :param radius: The initial radius of the ellipses.
    :type radius: float
    :param rotation: The rotation angle for the ellipses.
    :type rotation: float
    :param count: The number of ellipses to create.
    :type count: int
    :param step: The decrement step for the radius of each subsequent ellipse.
    :type step: float

    :returns: True if all ellipses are successfully created and added to the model, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()
    centerPoint = basePoint

    # Create ellipses into current model
    for i in range(count):
        axis2 = radius - i*step
        axis1 = axis2 / 2

        # Create ellipse element
        status = EllipseHandler.CreateEllipseElement(eeh, None, 
                                                     centerPoint, 
                                                     axis1, axis2,
                                                     rotation, 
                                                     ACTIVEMODEL.Is3d(), 
                                                     ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the ellipse element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True



def createEllipseOverride3(basePoint, firstRadius=50,
                           count=10, step=5):
    """
    Creates multiple ellipses in the active DGN model with increasing radii.

    :param basePoint: The center point for the ellipses.
    :type basePoint: DPoint3d
    :param firstRadius: The radius of the first ellipse.
    :type firstRadius: float
    :param count: The number of ellipses to create.
    :type count: int
    :param step: The increment step for the radius of each subsequent ellipse.
    :type step: float

    :returns: True if all ellipses are successfully created and added to the model, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()

    # Create ellipses into current model
    for i in range(count):
        radius = firstRadius + i*step
        ell = DEllipse3d.FromCenterRadiusXY(basePoint, radius)

        # Create ellipse element
        status = EllipseHandler.CreateEllipseElement(eeh, None, ell, 
                                                     ACTIVEMODEL.Is3d(), 
                                                     ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the ellipse element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True


if __name__ == "__main__":
    if True != createEllipseOverride1(DPoint3d(0, 0, 0)):
        print("Return false when call createEllipseOverride1!")

    if True != createEllipseOverride2(DPoint3d(300, 0, 0)):
        print("Return false when call createEllipseOverride2!")

    if True != createEllipseOverride3(DPoint3d(600, 0, 0)):
        print("Return false when call createEllipseOverride3!")