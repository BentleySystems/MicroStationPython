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
Example demonstrating how to create a set of arcs
'''

def createArcOverride1(basePoint, radius=100, rotation=math.pi/4,
                       startAngle=0, sweepAngle=math.pi/2,
                       count=10, step=5):
    """
    Create multiple arc elements in the active model.

    :param basePoint: The center point of the arcs.
    :type basePoint: Point3d
    :param radius: The initial radius of the arcs. Default is 100.
    :type radius: float, optional
    :param rotation: The rotation angle of the arcs. Default is pi/4.
    :type rotation: float, optional
    :param startAngle: The starting angle of the arcs. Default is 0.
    :type startAngle: float, optional
    :param sweepAngle: The sweep angle of the arcs. Default is pi/2.
    :type sweepAngle: float, optional
    :param count: The number of arcs to create. Default is 10.
    :type count: int, optional
    :param step: The decrement step for the radius of each subsequent arc. Default is 5.
    :type step: float, optional
    :return: True if all arcs are created and added to the model successfully, False otherwise.
    :rtype: bool
    """    
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()
    centerPoint = basePoint

    # Create arcs into current model
    for i in range(count):
        axis1 = axis2 = radius - i*step
        # Create arc element
        status = ArcHandler.CreateArcElement(eeh, None, centerPoint, axis1, axis2,
                                             rotation, startAngle, sweepAngle, 
                                             ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the arc element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True


'''Create a set of arcs in Microstation'''
def createArcOverride2(basePoint, radius=100, 
                       rotation=RotMatrix.FromRowValues(1,0,0,0,1,0,0,0,1),
                       startAngle=0, sweepAngle=math.pi/2, count=10, step=5):
    """
    Create multiple arc elements in the active model.

    :param basePoint: The center point of the arcs.
    :type basePoint: Point3d
    :param radius: The initial radius of the arcs. Default is 100.
    :type radius: float, optional
    :param rotation: The rotation matrix of the arcs. Default is identity matrix.
    :type rotation: RotMatrix, optional
    :param startAngle: The starting angle of the arcs. Default is 0.
    :type startAngle: float, optional
    :param sweepAngle: The sweep angle of the arcs. Default is pi/2.
    :type sweepAngle: float, optional
    :param count: The number of arcs to create. Default is 10.
    :type count: int, optional
    :param step: The decrement step for the radius of each subsequent arc. Default is 5.
    :type step: float, optional
    :return: True if all arcs are created and added to the model successfully, False otherwise.
    :rtype: bool
    """    
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()
    centerPoint = basePoint
    
    # Create arcs into current model
    for i in range(count):
        axis1 = axis2 = radius - i*step
        # Create arc element
        status = ArcHandler.CreateArcElement(eeh, None, 
                                             centerPoint, 
                                             axis1, axis2, 
                                             rotation, 
                                             startAngle, sweepAngle, 
                                             ACTIVEMODEL.Is3d(), 
                                             ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the arc element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True


def createArcOverride3(basePoint, firstRadius=50, count=10, step=5):
    """
    Create multiple arc elements in the active DGN model.
    This function creates a series of arc elements in the active DGN model,
    starting from a specified base point. The radius of each arc increases
    incrementally based on the provided step value.
    
    :param basePoint: The center point for the arcs.
    :type basePoint: Point3d
    :param firstRadius: The radius of the first arc. Default is 50.
    :type firstRadius: float, optional
    :param count: The number of arcs to create. Default is 10.
    :type count: int, optional
    :param step: The incremental step to increase the radius for each subsequent arc. Default is 5.
    :type step: float, optional
    
    :return: True if all arcs are created and added to the model successfully, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()

    # Create arcs into current model
    for i in range(count):
        radius = firstRadius + i*step
        ell = DEllipse3d.FromCenterRadiusXY(basePoint, radius)

        # Create arc element
        status = ArcHandler.CreateArcElement(eeh, None, ell, 
                                             ACTIVEMODEL.Is3d(), 
                                             ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False

        # Add the arc element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
        
    return True


if __name__ == "__main__":
    if True != createArcOverride1(DPoint3d(0, 0, 0)):
        print("Return false when call createArcOverride1!")

    if True != createArcOverride2(DPoint3d(300, 0, 0)):
        print("Return false when call createArcOverride2!")

    if True != createArcOverride3(DPoint3d(600, 0, 0)):
        print("Return false when call createArcOverride3!")