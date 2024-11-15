#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

def GeneratePoints(points , sz):
    SCALE = 1000.0

    for i in range(0,sz):
        x = SCALE * i
        y = SCALE * i
        z = SCALE * i
        points.append(DPoint3d(x,y,z))

def InitPoints(points , size):
    SCALE = 100.0

    for i in range(0,size):
        x = SCALE * i
        y = SCALE * i
        z = SCALE * i
        points.append(DPoint3d(x,y,z))


def InitPoints_Complex(points , size):
    SCALE = 100.0

    for i in range(0,size):
        points[i].x = SCALE * i
        points[i].y = SCALE * i
        points[i].z = SCALE * i

def CreateElement(type, eeh , model , is3d):
    if(type == "LineString"):
        
        NV = 5
        points = DPoint3dArray()
        GeneratePoints(points, NV)

        assert BentleyStatus.eSUCCESS == LineStringHandler.CreateLineStringElement(eeh, None, points, is3d, model)
        return
         
    if(type == "nShape"):
        NUM_POINTS = 20
        points = DPoint3dArray()
        InitPoints(points, NUM_POINTS)

        assert BentleyStatus.eSUCCESS == ShapeHandler.CreateShapeElement (eeh, None, points, is3d, model)
        return
    
    if(type == "nEllipse"):
        NUM_POINTS = 20
        point = DPoint3d(0, 0, 0)
        axis1 = math.pi/4
        axis2 = math.pi/6
        rotAngle = math.pi/8
    

        assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement (eeh, None, point,axis1, axis2, rotAngle, is3d, model)
        return

    if(type == "Complex"):    #DSegment3d.point() method is not exposed. 
        ChainHeaderHandler.CreateChainHeaderElement (eeh, None, True, is3d, model)
        NV = 2
        line = EditElementHandle()
        segment = DSegment3d()
    
        InitPoints_Complex (segment.point, NV)

        assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement (line, None, segment, is3d, model)
        ChainHeaderHandler.AddComponentElement (eeh, line)
        ChainHeaderHandler.AddComponentComplete(eeh)
        line.Invalidate()
        return

    if(type == "BSpline"):
        spline = MSBsplineCurve.Create()
        NUM_POINTS = 4
        poles = DPoint3dArray()
        InitPoints(poles, NUM_POINTS)
        spline.InitFromPoints (poles)

        assert BentleyStatus.eSUCCESS ==  BSplineCurveHandler.CreateBSplineCurveElement (eeh, None, spline, is3d, model)
        spline.ReleaseMem()
        return


m_eeh = EditElementHandle ()
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateGroupeHoleElement_NoHoles(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    solid = EditElementHandle ()
    shapeEeh = EditElementHandle ()
    holeEeh = EditElementHandle ()
    holes = ElementAgenda ()

    point2 = DPoint3d (5.0, 5.0, 5.0)
    assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement (holeEeh, None, point2, math.pi/6, math.pi/7, 0.0 , False, ret[0])
    assert BentleyStatus.eSUCCESS == holeEeh.AddToModel()

    point = DPoint3d (0.0, 0.0, 0.0)
    assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement (shapeEeh, None, point, math.pi/4, math.pi/5, 0.0 , False, ret[0])

    holeElm = holeEeh.GetElement ()
    assert None != holeElm
    shapeElm = shapeEeh.GetElement ()
    assert None != shapeElm
    elm = holeEeh.GetElementRef ()
    assert None != elm

    assert BentleyStatus.eERROR == GroupedHoleHandler.CreateGroupedHoleElement (m_eeh, shapeEeh, holes)

    solid.Invalidate ()
    shapeEeh.Invalidate ()
    holeEeh.Invalidate ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateGroupeHoleElement_InValidSolid(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    solid = EditElementHandle ()
    shapeEeh = EditElementHandle ()
    holeEeh = EditElementHandle ()
    holes = ElementAgenda ()

    point2 = DPoint3d (5.0, 5.0, 5.0)
    assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement (holeEeh, None, point2, math.pi/6, math.pi/7, 0.0 , False, ret[0])
    assert BentleyStatus.eSUCCESS == holeEeh.AddToModel()

    CreateElement("LineString", shapeEeh, ret[0], False)

    holeElm = holeEeh.GetElement ()
    assert None != holeElm
    shapeElm = shapeEeh.GetElement ()
    assert None != shapeElm
    elm = holeEeh.GetElementRef ()
    assert None != elm

    holes.Insert (elm,  ret[0], False)
    assert BentleyStatus.eERROR == GroupedHoleHandler.CreateGroupedHoleElement (m_eeh, shapeEeh, holes)

    solid.Invalidate ()
    shapeEeh.Invalidate ()
    holeEeh.Invalidate ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsGroupedHole_true(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    solid = EditElementHandle ()
    shapeEeh = EditElementHandle ()
    holeEeh = EditElementHandle ()
    holes = ElementAgenda ()

    point2 = DPoint3d (5.0, 5.0, 5.0)
    assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement (holeEeh, None, point2, math.pi/6, math.pi/7, 0.0 , False, ret[0])
    assert BentleyStatus.eSUCCESS == holeEeh.AddToModel()

    point = DPoint3d (0.0, 0.0, 0.0)
    assert BentleyStatus.eSUCCESS == EllipseHandler.CreateEllipseElement (shapeEeh, None, point, math.pi/4, math.pi/5, 0.0 , False, ret[0])

    elm = holeEeh.GetElementRef ()
    holes.Insert (elm,  ret[0], False)

    assert BentleyStatus.eSUCCESS == GroupedHoleHandler.CreateGroupedHoleElement (m_eeh, shapeEeh, holes)
    assert True == GroupedHoleHandler.IsGroupedHole (m_eeh)

    solid.Invalidate ()
    shapeEeh.Invalidate ()
    holeEeh.Invalidate ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsGroupedHole_false(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    shapeEeh = EditElementHandle ()

    NUM_POINTS = 20

    points = DPoint3dArray()
    GeneratePoints(points, NUM_POINTS)
    
    
    assert BentleyStatus.eSUCCESS == ShapeHandler.CreateShapeElement (shapeEeh, None, points, False, ret[0])
    assert False == GroupedHoleHandler.IsGroupedHole (shapeEeh)
    shapeEeh.Invalidate()
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsValidGroupedHoleComponentType_Shape(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement("nShape", m_eeh, ret[0], False)
    assert True == GroupedHoleHandler.IsValidGroupedHoleComponentType (m_eeh)
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsValidGroupedHoleComponentType_Ellipse(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement("nEllipse", m_eeh, ret[0], False)
    assert True == GroupedHoleHandler.IsValidGroupedHoleComponentType (m_eeh)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsValidGroupedHoleComponentType_ComplexShape(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement("Complex", m_eeh, ret[0], False)
    assert True == GroupedHoleHandler.IsValidGroupedHoleComponentType (m_eeh)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsValidGroupedHoleComponentType_BSpline(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement("BSpline", m_eeh, ret[0], False)
    assert False == GroupedHoleHandler.IsValidGroupedHoleComponentType (m_eeh)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsValidGroupedHoleComponentType_false(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    line = EditElementHandle()
    NUM_POINTS = 20
    points = DPoint3dArray()
    InitPoints(points, NUM_POINTS)

    assert BentleyStatus.eSUCCESS == LineStringHandler.CreateLineStringElement (line, None, points,False, ret[0])

    assert False == GroupedHoleHandler.IsValidGroupedHoleComponentType (line)
    line.Invalidate ()
