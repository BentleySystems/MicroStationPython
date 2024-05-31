# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''Create a set of arcs in Microstation'''
def createArcOverride1(basePoint, radius=100, rotation=math.pi/4,
                       startAngle=0, sweepAngle=math.pi/2,
                       count=10, step=5):
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


'''Create a set of arcs in Microstation'''
def createArcOverride3(basePoint, firstRadius=50, count=10, step=5):
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