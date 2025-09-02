# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

def drawLines(basePoint = DPoint3d(0,0,0), step = 10.0, length = 200.0, nLines = 20, rotAngle = 0.0):
    """
    Draws multiple lines in the active DGN model.

    :param basePoint: The starting point for the first line.
    :type basePoint: DPoint3d
    :param step: The distance between the starting points of consecutive lines.
    :type step: float
    :param length: The length of each line.
    :type length: float
    :param nLines: The number of lines to draw.
    :type nLines: int
    :param rotAngle: The rotation angle of the lines in degrees.
    :type rotAngle: float

    :returns: None
    """
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

def drawCircles(centerPoint = DPoint3d(0,0,0), startRadius = 5.0, step = 2.0, nCircles = 20):
    """
    Draws multiple concentric circles in the active DGN model.

    :param centerPoint: The center point for all the circles.
    :type centerPoint: DPoint3d
    :param startRadius: The radius of the first circle.
    :type startRadius: float
    :param step: The incremental increase in radius for each subsequent circle.
    :type step: float
    :param nCircles: The number of circles to draw.
    :type nCircles: int

    :returns: None
    """
    if startRadius <=0.0 or step <= 0.0 or nCircles < 1:
        return
        
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    eeh = EditElementHandle()
    for i in range(nCircles):
        radius = startRadius + i * step
        ell = DEllipse3d.FromCenterRadiusXY(centerPoint, radius)
        ArcHandler.CreateArcElement(eeh, None, ell, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
        eeh.AddToModel()
        

def drawRoundRectangles(centerPoint = DPoint3d(0,0,0), startSizeX = 30.0, startSizeY = 10.0, step = 5.0, baseRadius = 2.0, nRects = 20, rotAngle = 0.0):
    """
    Draws multiple rounded rectangles in the active DGN model.

    :param centerPoint: The center point for all the rectangles.
    :type centerPoint: DPoint3d
    :param startSizeX: The width of the first rectangle.
    :type startSizeX: float
    :param startSizeY: The height of the first rectangle.
    :type startSizeY: float
    :param step: The incremental increase in size for each subsequent rectangle.
    :type step: float
    :param baseRadius: The radius of the corners of the rectangles.
    :type baseRadius: float
    :param nRects: The number of rectangles to draw.
    :type nRects: int
    :param rotAngle: The rotation angle of the rectangles in degrees.
    :type rotAngle: float

    :returns: None
    """
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

