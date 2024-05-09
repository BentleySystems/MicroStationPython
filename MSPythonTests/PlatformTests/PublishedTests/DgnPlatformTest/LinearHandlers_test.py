import os
import pytest
import math
import copy
import sys
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *


def IterateCacheAndSearchForDescriptor (handleList, cache, description):
    for ref in cache.GetElementsCollection ():
        eh = EditElementHandle(ref, cache)
        BUFFER_SZ = 1024
        desc = WString()
        eh.GetHandler().GetDescription (eh, desc, BUFFER_SZ)
        if desc == description :
           handleList.append (eh) 

def InitFilledCache (fileName, is3d, ret):
    m_is3d = is3d
    m_model = ret[0]
    if not m_model :
        return BentleyStatus.eERROR
    return BentleyStatus.eSUCCESS

def GeneratePoints(points, sz):    
    SCALE = 1000.0   
    for i in range(0,sz):
        x = SCALE * i
        y = SCALE * i
        z = SCALE * i
        points.append(DPoint3d(x,y,z))

def InitPoints():
    SCALE = 100.0
    for i in range(0, NV):
        m_points[i].x = i*SCALE
        m_points[i].y =0
        m_points[i].z = 0

def isDPoint3dNear (left , right , Epsilon):

    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)

def isQuaternionNear(left, right , Epsilon):

    assert abs (left[0]- right[0]) <= Epsilon
    assert abs (left[1] - right[1]) <= Epsilon
    assert abs (left[2]- right[2]) <= Epsilon
    assert abs (left[3]- right[3]) <= Epsilon

    return (abs (left[0] - right[0]) < Epsilon and
            abs (left[1] - right[1]) < Epsilon and
            abs (left[2] - right[2]) < Epsilon and
            abs (left[3] - right[3]) < Epsilon)


def nearRowValuesXY (dataA, other):
     s_tolerance = 1.0e-14
     for i in range (4):
        if abs (dataA[i] - dataA[i]) > s_tolerance :
            return False
        return True


def isPerp(a, b):
    assert (a.x*b.x)+(a.y*b.y)+(a.z*b.z) == 0



m_eeh = EditElementHandle()
OVER_MAX = 10000
EPSILON = 0.000001
NV = 2
m_points = [DPoint3d() for _ in range(NV)]


@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_CreateLineElement_Example(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    segment = DSegment3d(0.0, 0.0, 0.0, 1.0, 1.0, 1.0)
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    ehs = []    
    IterateCacheAndSearchForDescriptor (ehs, ret[0], WString("Line"))
    assert len(ehs) == 0
    m_eeh.AddToModel()
    IterateCacheAndSearchForDescriptor (ehs, ret[0], WString("Line"))
    assert len(ehs) == 1
    elm = m_eeh.GetElement()
    d = elm.line_3d    
    assert abs (segment.point[0].x - (elm.line_3d.start).x) <= 0.000001
    assert abs (segment.point[0].y - (elm.line_3d.start).y) <= 0.000001
    assert abs (segment.point[1].x - (elm.line_3d.end).x) <= 0.000001
    assert abs (segment.point[1].y - (elm.line_3d.end).y) <= 0.000001

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateLineString_MAX_VERTICES_1(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    m_eeh = EditElementHandle()
    tempoints = DPoint3dArray()
    GeneratePoints(tempoints, MAX_VERTICES - 1)
    assert LineStringHandler.CreateLineStringElement(m_eeh, None, tempoints, False, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    if elm != None:
        assert elm.line_string_2d.numverts == MAX_VERTICES-1


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateLineString_MAX_VERTICES_2(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    m_eeh = EditElementHandle()
    tempoints = DPoint3dArray()
    GeneratePoints(tempoints, MAX_VERTICES + 1)
    assert LineStringHandler.CreateLineStringElement(m_eeh, None, tempoints, False, ret[0]) == BentleyStatus.eERROR
    elm = m_eeh.GetElement()
    if elm != None:
        assert elm.line_string_2d.numverts == MAX_VERTICES+1



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateLineString_BadArg(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    points = DPoint3dArray()
    GeneratePoints(points, OVER_MAX)
    assert LineStringHandler.CreateLineStringElement(m_eeh, None, points, False, ret[0]) == BentleyStatus.eERROR



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateLineString_is3d(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    points = DPoint3dArray()
    GeneratePoints(points, MAX_VERTICES - 1)
    assert LineStringHandler.CreateLineStringElement(m_eeh, None, points, True, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    for i in range (0, MAX_VERTICES - 1):
        assert isDPoint3dNear(elm.line_string_3d.vertice[i], points[i], EPSILON) == True



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateLineString_Example(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, -1.0, 0.0))
    points.append(DPoint3d(0.0, -0.1, 0.0))
    points.append(DPoint3d(0.0, 0.0, 0.0))
    points.append(DPoint3d(1.0, 4.0, 0.0))
    points.append(DPoint3d(5.0 , 5.0, 0.0))
    points.append(DPoint3d(6.0, 5.0, 0.0))
    points.append(DPoint3d(7.0, 5.0, 0.0))
    SCALE = 100000.0
    for i in range (len(points)):
         points[i].x *= SCALE
         points[i].y *= SCALE
    assert LineStringHandler.CreateLineStringElement(m_eeh, None, points, False, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    assert elm.line_string_2d.numverts == len (points)
    for i in range (len(points)):
        assert abs (points[i].x - elm.line_string_2d.vertice[i].x) <= 0.000001
        assert abs (points[i].y - elm.line_string_2d.vertice[i].y) <= 0.000001



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatePointString_MAX_VERTICES(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, OVER_MAX)
    assert BentleyStatus.eSUCCESS != PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, False, False, ret[0])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatePointString_BadArgs(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, OVER_MAX)
    assert BentleyStatus.eERROR == PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, False, True, ret[0])


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatePointString_disjoint_false(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_VERTS=200
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, NUM_VERTS)
    assert BentleyStatus.eSUCCESS == PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, False, False, ret[0])
    elm = m_eeh.GetElement()
    assert elm.hdr.dhdr.props.b.h == 0


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatePointString_disjoint_true(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_VERTS=200
    assert InitFilledCache (WString("2dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, NUM_VERTS)
    assert BentleyStatus.eSUCCESS == PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, True, False, ret[0])
    elm = m_eeh.GetElement()
    assert elm.hdr.dhdr.props.b.h == 1



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatePointString_VerifyDefaultQuaterions3d(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_VERTS=2000
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, NUM_VERTS)
    assert BentleyStatus.eSUCCESS == PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, True, ret[0].Is3d(), ret[0])
    elm = m_eeh.GetElement()
    transtart = elm.line_string_3d.vertice[NUM_VERTS-1] if ret[0].Is3d() else elm.line_string_2d.vertice[NUM_VERTS-1]
    rMatrix = RotMatrix()
    rMatrix.InitIdentity ()
    quat = DPoint4d(0,0,0,0)
    rMatrix.GetQuaternion (quat, 1)
    # for i in range (NUM_VERTS):
    #     assert isQuaternionNear (quat, transtart, EPSILON) == True
    #     transtart = [transtart[j] for j in range(4)]


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatPointString_VerifyDefaultQuaterions2d(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_VERTS=6
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, NUM_VERTS)
    rMatrix = RotMatrix()
    rMatrix.InitIdentity ()
    packA = DoubleArray()
    rMatrix.GetRowValuesXY (packA)
    assert BentleyStatus.eSUCCESS == PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, True, ret[0].Is3d(), ret[0])
    elm = m_eeh.GetElement()
    transtart = elm.line_string_3d.vertice[NUM_VERTS-1] if ret[0].Is3d() else elm.line_string_2d.vertice[NUM_VERTS-1]
    for i in range (NUM_VERTS):
        assert nearRowValuesXY (packA, transtart) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreatPointString_VerifyDiffQuaterions3d(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_VERTS=2000
    rt = RotMatrixArray()
    points = DPoint3dArray()
    GeneratePoints(points, NUM_VERTS)
    rMatrix = [RotMatrix() for _ in range(NUM_VERTS)]
    vec = DVec3d()
    vec.x = 0.0
    vec.y = 0.0
    vec.z = 1.0
    increment = math.pi/6
    for i in range (NUM_VERTS):
        rMatrix[i].InitFromVectorAndRotationAngle (vec, increment*i)
    assert BentleyStatus.eSUCCESS == PointStringHandler.CreatePointStringElement(m_eeh, None, points, rt, True, ret[0].Is3d(), ret[0])
    elm = m_eeh.GetElement()
    quat = DoubleArray()
    transtart = elm.line_string_3d.vertice[NUM_VERTS-1] if ret[0].Is3d() else elm.line_string_2d.vertice[NUM_VERTS-1]
    for i in range (NUM_VERTS):
        rMatrix[i].GetQuaternion (quat, 1)
        # assert isQuaternionNear (quat, transtart, EPSILON) == True



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateShapeElement_WithSameEndPoints(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, 0.0, 0.0))
    points.append(DPoint3d(1.0, 1.0, 1.0))
    points.append(DPoint3d(0.0,0.0,0.0))
    assert ShapeHandler.CreateShapeElement(m_eeh, None, points, True, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    for i in range (len(points)):
         assert isDPoint3dNear (points[i], elm.line_string_3d.vertice[i], EPSILON) == True
    assert elm.line_string_3d.numverts == len (points)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateShapeElement_WithDifferentEndPoints(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, 0.0, 0.0))
    points.append(DPoint3d(1.0, 1.0, 1.0))
    points.append(DPoint3d(8.0,8.0,8.0))
    assert ShapeHandler.CreateShapeElement(m_eeh, None, points, True, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    for i in range (len(points)):
         assert isDPoint3dNear (points[i], elm.line_string_3d.vertice[i], EPSILON) == True
    newLastVert = elm.line_string_3d.numverts-1
    assert isDPoint3dNear (points[0], elm.line_string_3d.vertice[newLastVert], EPSILON) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateShapeElement_WithDifferentEndPoints_MAX_VERTS(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    GeneratePoints(points, MAX_VERTICES - 1)
    assert ShapeHandler.CreateShapeElement(m_eeh, None, points, True, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    for i in range (MAX_VERTICES - 1):
        assert isDPoint3dNear (points[i], elm.line_string_3d.vertice[i], EPSILON) == True
    newLastVert = elm.line_string_3d.numverts-1
    assert isDPoint3dNear (points[0], elm.line_string_3d.vertice[newLastVert], EPSILON) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateShapeElement_MAX_VERTICES(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    GeneratePoints(points, MAX_VERTICES - 1)
    assert ShapeHandler.CreateShapeElement(m_eeh, None, points, False, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    assert elm.line_string_2d.numverts == MAX_VERTICES


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateShapeElement_is3d(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    GeneratePoints(points, MAX_VERTICES - 1)
    assert ShapeHandler.CreateShapeElement(m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    for i in range (MAX_VERTICES - 1):
        assert isDPoint3dNear (elm.line_string_3d.vertice[i], points[i], EPSILON) == True
    assert isDPoint3dNear(elm.line_string_3d.vertice[MAX_VERTICES-1], points[0],EPSILON) == True



@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQueryLine_GetEndPoints_Line(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    InitPoints()
    segment = DSegment3d(m_points[0], m_points[1])
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    start = DPoint3d()
    end = DPoint3d()
    startTangent = DVec3d()
    endTangent = DVec3d()

    curveQuery_Line = ICurvePathQuery.ElementToCurveVector (m_eeh)
    assert curveQuery_Line != None
    assert curveQuery_Line.GetStartEnd (start, end, startTangent, endTangent) == True
    assert isDPoint3dNear (start, m_points[0], EPSILON) == True
    assert isDPoint3dNear (end, m_points[NV-1], EPSILON) == True


@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQueryLine_GetEndTangents_Line(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    InitPoints()
    segment = DSegment3d(m_points[0], m_points[1])
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    expectedStart = DVec3d()
    expectedEnd = DVec3d()
    expectedStart.NormalizedDifference (m_points[1], m_points[0])
    expectedEnd = copy.copy(expectedStart)

    curveQuery_Line = ICurvePathQuery.ElementToCurveVector (m_eeh)
    assert curveQuery_Line != None

    start = DPoint3d()
    end = DPoint3d()
    startTangent = DVec3d()
    endTangent = DVec3d()
    assert curveQuery_Line.GetStartEnd (start, end, startTangent, endTangent) == True
    startTangent.Normalize()
    endTangent.Normalize()
    assert isDPoint3dNear (expectedStart, startTangent, EPSILON) == True
    assert isDPoint3dNear (expectedEnd, endTangent, EPSILON) == True


@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQueryLine_GetClosestCurvePoint_Line(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    InitPoints()
    segment = DSegment3d(m_points[0], m_points[1])
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS

    curveQuery_Line = ICurvePathQuery.ElementToCurveVector (m_eeh)
    assert curveQuery_Line != None

    targetPoint = DPoint3d(50.0, 50.0, 0.0)
    tr = Transform()
    tr.InitIdentity()

    cvd = CurveLocationDetail()
    assert True == curveQuery_Line.ClosestPointBounded(targetPoint, cvd)

    expectedPoint = DPoint3d(50,0,0)
    expectedParametricResult = 0.5
    assert isDPoint3dNear (expectedPoint, cvd.point, EPSILON) == True
    assert abs (expectedParametricResult - cvd.componentFraction) <= EPSILON


@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQueryLineSring_GetEndPoints_Line(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    InitPoints()
    points = DPoint3dArray()
    points.append(m_points[0])
    points.append(m_points[1])
    assert LineStringHandler.CreateLineStringElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS

    curveQuery_Line = ICurvePathQuery.ElementToCurveVector (m_eeh)
    assert curveQuery_Line != None

    start = DPoint3d()
    end = DPoint3d()
    startTangent = DVec3d()
    endTangent = DVec3d()
    assert curveQuery_Line.GetStartEnd (start, end, startTangent, endTangent) == True

    assert isDPoint3dNear (start, m_points[0], EPSILON) == True
    assert isDPoint3dNear (end, m_points[NV-1], EPSILON) == True


@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQueryLineString_GetEndTangents_Line(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    InitPoints()
    points = DPoint3dArray()
    points.append(m_points[0])
    points.append(m_points[1])
    assert LineStringHandler.CreateLineStringElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS

    curveQuery_LineString = ICurvePathQuery.ElementToCurveVector (m_eeh)
    assert curveQuery_LineString != None

    start = DPoint3d()
    end = DPoint3d()
    startTangent = DVec3d()
    endTangent = DVec3d()
    assert curveQuery_LineString.GetStartEnd (start, end, startTangent, endTangent) == True
    startTangent.Normalize()
    endTangent.Normalize()

    expectedStart = DVec3d()
    expectedEnd = DVec3d()
    expectedStart.Normalize()
    expectedEnd.Normalize()
    assert isDPoint3dNear (expectedStart, startTangent, EPSILON) == True
    assert isDPoint3dNear (expectedEnd, endTangent, EPSILON) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_Line(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    segment = DSegment3d(0, 0, 0, 100, 0, 0)
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    expPoint = DPoint3d(50, 0, 0)
    df = DVec3d(DVec3d(0.0, 0.0, 0.0), DVec3d(10, 0.0, 0.0))
    assert disp.IsPlanar(m_eeh, normal, point, df) == True
    assert isDPoint3dNear(expPoint, point, EPSILON) == True
    elm = m_eeh.GetElement()
    line = DVec3d()
    line.x = elm.line_3d.end.x - elm.line_3d.start.x
    line.y = elm.line_3d.end.y - elm.line_3d.start.y
    line.z = elm.line_3d.end.z - elm.line_3d.start.z
    # isPerp(normal, line)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_LineDef2(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    segment = DSegment3d(0, 0, 0, 100, 0, 0)
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    expPoint = DPoint3d(50, 0, 0)
    df = DVec3d(DVec3d(0.0, 0.0, 0.0), DVec3d(0.0, 10.0, 0.0))
    assert disp.IsPlanar(m_eeh, normal, point, df) == True
    assert isDPoint3dNear(expPoint, point, EPSILON) == True
    elm = m_eeh.GetElement()
    line = DVec3d()
    line.x = elm.line_3d.end.x - elm.line_3d.start.x
    line.y = elm.line_3d.end.y - elm.line_3d.start.y
    line.z = elm.line_3d.end.z - elm.line_3d.start.z
    # isPerp(normal, line)
    

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_LineDef3(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    segment = DSegment3d(0, 0, 0, 100, 0, 0)
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    expPoint = DPoint3d(50, 0, 0)
    df = DVec3d(DVec3d(0.0, 0.0, 0.0), DVec3d(0.0, 0.0, 1.0))
    assert disp.IsPlanar(m_eeh, normal, point, df) == True
    assert isDPoint3dNear(expPoint, point, EPSILON) == True
    elm = m_eeh.GetElement()
    line = DVec3d()
    line.x = elm.line_3d.end.x - elm.line_3d.start.x
    line.y = elm.line_3d.end.y - elm.line_3d.start.y
    line.z = elm.line_3d.end.z - elm.line_3d.start.z
    # isPerp(normal, line)



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_Line2(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    segment = DSegment3d(2.0, 5.0, 8.0, 3.0, 15.0, 20.0)
    assert LineHandler.CreateLineElement (m_eeh, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    expPoint = DPoint3d(2.5, 10, 14)
    df = DVec3d(DVec3d(0.0, 0.0, 0.0), DVec3d(10, 0.0, 0.0))
    assert disp.IsPlanar(m_eeh, normal, point, df) == True
    # assert isDPoint3dNear(expPoint, point, EPSILON) == True
    elm = m_eeh.GetElement()
    line = DVec3d()
    line.x = elm.line_3d.end.x - elm.line_3d.start.x
    line.y = elm.line_3d.end.y - elm.line_3d.start.y
    line.z = elm.line_3d.end.z - elm.line_3d.start.z
    # isPerp(normal, line)