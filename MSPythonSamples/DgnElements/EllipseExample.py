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


'''Create a set of ellipse in Microstation'''
def createEllipseOverride1(basePoint, radius=100,
                           rotation=RotMatrix.FromRowValues(1,0,0,0,1,0,0,0,1),
                           count=10, step=5):
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


'''Create a set of ellipse in Microstation'''
def createEllipseOverride2(basePoint, radius=100, rotation=0,
                           count=10, step=5):
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


'''Create a set of ellipses in Microstation'''
def createEllipseOverride3(basePoint, firstRadius=50,
                           count=10, step=5):
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