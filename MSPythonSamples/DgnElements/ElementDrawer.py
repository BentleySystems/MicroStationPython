# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Function to create a set of parallel lines into current model
    basePoint : DPoint3d    base point of lines
    step : float            distance between lines
    length : float          length of each line
    nLines : int            number of lines to be created
    rotAngle : float        plane rotate angle of lines in degree.
'''
def drawLines(basePoint = DPoint3d(0,0,0), step = 10.0, length = 200.0, nLines = 20, rotAngle = 0.0):
    if step <= 0.0 or length <=0.0 or nLines < 1:
        return
        
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    xRot = math.radians(rotAngle)
    yRot = xRot + math.pi * 0.5
    xDir = DVec3d(math.cos(xRot), math.sin(xRot), 0)
    yDir = DVec3d(math.cos(yRot), math.sin(yRot), 0)
    eeh = EditElementHandle()
    for i in range(nLines):
        p1 = basePoint + i * step * xDir
        p2 = p1 + length * yDir
        seg = DSegment3d(p1, p2)
        LineHandler.CreateLineElement(eeh, None, seg, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        eeh.AddToModel()

'''
Function to create a set of concentric circles into current model
    centerPoint : DPoint3d  center point of circles
    startRadius : float     start radius of circles
    step : float            distance between each circles
    nCircles : int          number of circles to be created    
'''     
def drawCircles(centerPoint = DPoint3d(0,0,0), startRadius = 5.0, step = 2.0, nCircles = 20):
    if startRadius <=0.0 or step <= 0.0 or nCircles < 1:
        return
        
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    eeh = EditElementHandle()
    for i in range(nCircles):
        radius = startRadius + i * step
        ell = DEllipse3d.FromCenterRadiusXY(centerPoint, radius)
        ArcHandler.CreateArcElement(eeh, None, ell, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        eeh.AddToModel()
        
'''
Function to create a set of round rectangles into current model
    centerPoint : DPoint3d      center point of rectangles
    startSizeX : float          start dimension on x direction
    startSizeY : float          start dimension on y direction
    step : float                distance between rectangles
    baseRadius : float          base radius of round
    nRects : int                number of rectangles to be created
    rotAngle : 
'''
def drawRoundRectangles(centerPoint = DPoint3d(0,0,0), startSizeX = 30.0, startSizeY = 10.0, step = 5.0, baseRadius = 2.0, nRects = 20, rotAngle = 0.0):
    if startSizeX <= 0.0 or startSizeY <= 0.0 or step <= 0.0 or baseRadius <= 0.0 or nRects < 1:
        return
        
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    xRot = math.radians(rotAngle)
    rightX = startSizeX * 0.5
    leftX = -rightX
    topY = startSizeY * 0.5
    bottomY = -topY
    
    rotMat = RotMatrix.FromAxisAndRotationAngle(2, xRot)
    transform = Transform.From(rotMat, centerPoint)
    
    curve = CurveVector.CreateRectangle(leftX, topY, rightX, bottomY, centerPoint.z, CurveVector.eBOUNDARY_TYPE_Outer)
    curve = curve.CloneWithFillets(baseRadius)    
    curve.TransformInPlace(transform)
    
    eeh = EditElementHandle()
    offset = CurveOffsetOptions(step)
    for i in range(nRects):
        DraftingElementSchema.ToElement(eeh, curve, None, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        eeh.AddToModel()
        curve = curve.CloneOffsetCurvesXY(offset)
    
def PyMain():
    drawLines(DPoint3d(0,0,0), 50.0, 1000.0, 100, 30.0)

