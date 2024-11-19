#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_eeh = EditElementHandle()
EPSILON = 0.000000001
NUM_LINES = 3
NUM_POINTS = 2

def isDPoint3dNear (left , right , Epsilon):

    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)


def SharedCellSetUp (definitionName, ret):
    origin = DPoint3d(0.0, 0.0, 0.0)
    scale = DPoint3d(1.0, 1.0, 1.0)
    m_rMatrix = RotMatrix()
    SharedCellHandler.CreateSharedCellElement (m_eeh, None, definitionName, origin, m_rMatrix, scale, ret[0].Is3d(), ret[0])
    SharedCellHandler.CreateSharedCellComplete (m_eeh)

def GeneratePoints(points, sz):
    
    SCALE = 1000.0
    
    
    for i in range(0,sz):
        # x = SCALE * i
        # y = SCALE * i
        # z = SCALE * i
        # points.append(DPoint3d(x,y,z))
        points[i].x= SCALE * i 
        points[i].y= SCALE * i 
        points[i].z= SCALE * i

def SharedCellSetUp1 (m_eeh, model, is3d):
    origin = DPoint3d(0.0, 0.0, 0.0)
    scale = DPoint3d(1.0, 1.0, 1.0)
    m_rMatrix = RotMatrix()
    SharedCellHandler.CreateSharedCellElement (m_eeh, None, "test", origin, m_rMatrix, scale, is3d, model)
    SharedCellHandler.CreateSharedCellComplete (m_eeh)


def CreateDef (model, is3d):
    defHandle = EditElementHandle()
    m_points = [[DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)], [DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)],[DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)]]
    Lines = [EditElementHandle() for _ in range(NUM_LINES)]
    for i in range(NUM_LINES):
        GeneratePoints (m_points[i], NUM_POINTS)
        for j in range(NUM_POINTS):
            m_points[i][j].x *= i+7
            m_points[i][j].y *= i+5
            m_points[i][j].z *= i+6

    SharedCellDefHandler.CreateSharedCellDefElement (defHandle, "test", is3d, model)
    for j in range(NUM_LINES):
        if j+1 < NUM_LINES :
            pt1 = DPoint3d(m_points[j][0].x, m_points[j][0].y, m_points[j][0].z)
            pt2 = DPoint3d(m_points[j][1].x, m_points[j][1].y, m_points[j][1].z)
            seg = DSegment3d(pt1, pt2)
        else:
            pt1 = DPoint3d(m_points[j][0].x, m_points[j][0].y, m_points[j][0].z)
            seg = DSegment3d(pt1, pt1)
                
        LineHandler.CreateLineElement (Lines[j], None, seg, is3d, model)
        assert SharedCellDefHandler.AddChildElement (defHandle, Lines[j]) == BentleyStatus.eSUCCESS
    SharedCellDefHandler.AddChildComplete (defHandle)
    defHandle.AddToModel ()


def CreateElement(type, eeh , model , is3d):
    if (type == 9):
        CreateDef(model, is3d)
        SharedCellSetUp1(eeh, model, is3d)
        return


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateSharedCellElement(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    SharedCellSetUp ("definition", ret)
    m_points = [[DPoint3d() for i in range(NUM_POINTS)] for j in range(NUM_LINES)]
    numChildren = 0
    for child in range(3):
        elm = m_eeh.GetElement()
        assert True == isDPoint3dNear (m_points[numChildren][0], elm.line_3d.start, 0.000000001)
        assert True == isDPoint3dNear (m_points[numChildren][1], elm.line_3d.end, 0.000000001)
        numChildren += 1
    assert 3 == numChildren


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SharedCellDef_FindDefinitionByName_Valid(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    m_eehDef = EditElementHandle()
    de = m_eehDef.GetDgnFile ()
    assert m_eehDef.GetElementRef () == SharedCellDefHandler.FindDefinitionByName ("test", dgnFile)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SharedCellDef_FindDefinitionByName_InValid(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    m_eehDef = EditElementHandle()
    de = m_eehDef.GetDgnFile ()
    assert None == SharedCellDefHandler.FindDefinitionByName ("fail", dgnFile)



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SharedCellDef_NonUniqueDefs(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = [[DPoint3d() for i in range(NUM_POINTS)] for j in range(NUM_LINES)]
    m_eehDef = EditElementHandle()
    m_eehLines = [EditElementHandle() for _ in range(3)]
    for i in range (3):
        GeneratePoints (points[i], 2)
        for j in range (2):
            points[i][j].x *= i + 200
            points[i][j].y *= i + 125
            points[i][j].z *= i + 654
    SharedCellDefHandler.CreateSharedCellDefElement (m_eeh, "test", ret[0].Is3d(), ret[0])
    for j in range (3):
        pt1 = DPoint3d(points[j][0].x, points[j][0].y, points[j][0].z)
        pt2 = DPoint3d(points[j][1].x, points[j][1].y, points[j][1].z)
        seg = DSegment3d(pt1, pt2)
        LineHandler.CreateLineElement (m_eehLines[j], None, seg, ret[0].Is3d(), ret[0])
        assert SharedCellDefHandler.AddChildElement (m_eeh, m_eehLines[j]) == BentleyStatus.eSUCCESS

    SharedCellDefHandler.AddChildComplete (m_eeh)
    addFailed = False
    try:
        addFailed = BentleyStatus.eSUCCESS != m_eehDef.AddToModel ()
    except Exception as e:
        addFailed = True
    assert addFailed == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsRenderable_SharedCell(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement(9, m_eeh, ret[0], ret[0].Is3d())
    disp = m_eeh.GetHandler ()
    assert disp != None
    assert disp.IsRenderable(m_eeh) == False


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_GetTransformOrigin_SharedCell(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement(9, m_eeh, ret[0], ret[0].Is3d())
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    act = DPoint3d()
    exp = DPoint3d(0, 0, 0)
    disp.GetTransformOrigin(m_eeh, act)
    assert isDPoint3dNear (act, exp, EPSILON) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_GetOrientation_SharedCell(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement(9, m_eeh, ret[0], ret[0].Is3d())
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    ROWS = 3
    COLS = 3
    act = RotMatrix()
    exp = RotMatrix()
    exp.InitIdentity ()
    assert disp != None
    disp.GetOrientation (m_eeh, act)
    # for i in range(ROWS):
    #     for j in range(COLS):
            # assert act.form3d[i][j] == exp.form3d[i][j]


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_SharedCell(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement(9, m_eeh, ret[0], ret[0].Is3d())
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    de = DVec3d.From (0.0, 0.0, 1.0)
    assert disp.IsPlanar(m_eeh, normal, point, de) == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_GetSnapOrigin_SharedCell(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement(9, m_eeh, ret[0], ret[0].Is3d())
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    expPoint = DPoint3d(0, 0, 0)
    disp.GetSnapOrigin(m_eeh, point)
    assert isDPoint3dNear(expPoint, point, EPSILON) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_GetElemDisplayParams_SharedCell(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement(9, m_eeh, ret[0], ret[0].Is3d())
    propQuery = ElementPropertiesGetter(m_eeh)
    assert propQuery.GetColor () == 0
    assert propQuery.GetLineStyle () == 0
    assert propQuery.GetWeight () == 0
    assert propQuery.GetLevel () == LEVEL_DEFAULT_LEVEL_ID