import os
import sys
import pytest
import math
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

m_eeh = EditElementHandle()
EPSILON = 0.000001
MAX_VERTICES = 5000
NV = 11
m_points = [DPoint3d() for _ in range(NV)]

'''Generate new 3d points'''
def GeneratePoints(points, sz):
    
    SCALE = 1000.0
       
    for i in range(0,sz):
        x = SCALE * i
        y = SCALE * i
        z = SCALE * i
        points.append(DPoint3d(x,y,z))

def InitFilledCache (fileName, is3d, ret):
    m_is3d = is3d
    m_model = ret[0]
    if not m_model :
        return BentleyStatus.eERROR
    return BentleyStatus.eSUCCESS

def GenerateSpiralYAxis(points, sz):
    rads = 0.0
    incr = math.pi/180.0
    scale = 1000.0
    for i in range (sz):
        rads += incr
        x = scale * math.cos (rads)
        y = scale * rads
        z = scale * math.sin (rads)
        points.append(DPoint3d(x,y,z))

'''Initialize points'''
def InitPoints (pointlist):
    ptnum = len(pointlist)
    if ptnum != NV:
        return
    
    SCALE = 1.0
    for i in range(NV):
       pointlist[i].x = pointlist[i].y = pointlist[i].z = SCALE * i
       pointlist[i].y = SCALE * math.sin (i * math.pi / (NV-1))
    # make the first and last 3 points on the same line so the tangents match up
    pointlist[1].Interpolate (pointlist[0], 0.5, pointlist[2])
    pointlist[NV-2].Interpolate (pointlist[NV-1], 0.5, pointlist[NV-3])

def isPerp(a, b):
    assert (a.x*b.x)+(a.y*b.y)+(a.z*b.z) == 0

def isDPoint3dNear (left , right , Epsilon):

    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)

def ComputeDistancePrecision(p1, p2):
    r = DRange3d (p1, p2)
    return r.LargestCoordinate() * 1.0e-14

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateCurveElement_Example(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    assert InitFilledCache (WString("3dMetricGeneral.dgn"), False, ret) == BentleyStatus.eSUCCESS
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, -1.0, 0.0))
    points.append(DPoint3d(0.0, -0.1, 0.0))
    points.append(DPoint3d(0.0, 0.0, 0.0))
    points.append(DPoint3d(1.0, 4.0, 0.0))
    points.append(DPoint3d(5.0 , 5.0, 0.0))
    points.append(DPoint3d(6.0, 5.0, 0.0))
    points.append(DPoint3d(7.0, 5.0, 0.0))
    SCALE = 1000.0
    sz = len(points)
    for i in range(sz):
        points[i].x *= SCALE
        points[i].y *= SCALE
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    assert sz == elm.line_string_2d.numverts
    for i in range(2,sz-2):
        assert abs (points[i].x - elm.line_string_2d.vertice[i].x) <= EPSILON
        assert abs (points[i].y - elm.line_string_2d.vertice[i].y) <= EPSILON
    
@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_CreateCurveElement_BadArg(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    eeh = EditElementHandle()
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, 0.0, 0.0))
    assert CurveHandler.CreateCurveElement (eeh, None, points, False, ret[0]) == BentleyStatus.eERROR

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_CreateCurveElement_MAX_VERTICES(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    GenerateSpiralYAxis (points, MAX_VERTICES * 2)
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    assert MAX_VERTICES ==  elm.line_string_3d.numverts
    for i in range(0,MAX_VERTICES,500):
        assert abs (points[i].x - elm.line_string_3d.vertice[i].x) <= EPSILON
        assert abs (points[i].y - elm.line_string_3d.vertice[i].y) <= EPSILON
        assert abs (points[i].z - elm.line_string_3d.vertice[i].z) <= EPSILON

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_CreateCurveElement_is3d(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    OVER_MAX = MAX_VERTICES * 2
    points = DPoint3dArray()
    GeneratePoints (points, OVER_MAX)
    assert CurveHandler.CreateCurveElement(m_eeh, None, points, True, ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    for i in range(0,MAX_VERTICES,500):
        assert isDPoint3dNear(elm.line_string_3d.vertice[i], points[i],EPSILON) == True

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_CreateCurveElement_TemplateCopy(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    GenerateSpiralYAxis (points, MAX_VERTICES)
    COLOR = 50
    LINE_STYLE = 4
    
    levelIter = iter(ret[0].GetFileLevelCache())
    levelIter = next(levelIter)
    levelID   = levelIter.GetLevelId()
    
    tmpEl = EditElementHandle()
    segment = DSegment3d(0.0, 0.0, 0.0, 1.0, 1.0, 1.0)
    assert LineHandler.CreateLineElement (tmpEl, None, segment, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    pSetter = ElementPropertiesSetter()
    pSetter.SetLevel (levelID)
    pSetter.SetColor (COLOR)
    pSetter.SetLinestyle (LINE_STYLE, None)
    assert pSetter.Apply (tmpEl) == True
    assert CurveHandler.CreateCurveElement (m_eeh, tmpEl, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    query = ElementPropertiesGetter(tmpEl)
    query1 = IQueryProperties()
    PropertyContext.QueryElementProperties (m_eeh, query1)
    assert bool(query.GetLevel ()) == True
    assert bool(query.GetColor ()) == True
    assert query.GetLevel () == levelID
    assert COLOR ==  query.GetColor ()
    assert bool( query.GetLineStyle ()) == True
    assert LINE_STYLE == query.GetLineStyle ()

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQuery_GetEndPoints_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    
    ptList = [DPoint3d() for _ in range(NV)]
    InitPoints (ptList)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(ptList[i])
    
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
   
    curveQuery = CurveHandler.ElementToCurveVector (m_eeh)
    assert None != curveQuery
    
    start = DPoint3d()
    end   = DPoint3d()
       
    assert True == curveQuery.GetStartEnd (start, end)

    assert isDPoint3dNear (start, ptList[2], EPSILON) == True
    assert isDPoint3dNear (end, ptList[NV-3], EPSILON) == True

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQuery_GetComponentCount_ERROR_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    eeh = EditElementHandle()
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert LineStringHandler.CreateLineStringElement (eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS

    curveQuery = CurveHandler.ElementToCurveVector (eeh)
    assert None != curveQuery

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQuery_GetEndTangents_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    
    ptList = [DPoint3d() for _ in range(NV)]
    InitPoints (ptList)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(ptList[i])
        
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # Generate expected Tangents
    expectedStart = DVec3d()
    expectedEnd = DVec3d()
    offset = 2
    expectedStart.DifferenceOf (ptList[offset], ptList[offset-1])
    expectedEnd.DifferenceOf (ptList[NV-offset+1], ptList[NV-offset])
    expectedStart.Normalize()
    expectedEnd.Normalize()
    
    curveQuery = CurveHandler.ElementToCurveVector (m_eeh)
    assert None != curveQuery
    
    start = DPoint3d()
    end   = DPoint3d()
    startTangent = DVec3d()
    endTangent = DVec3d()
    
    assert True == curveQuery.GetStartEnd (start, end, startTangent, endTangent)
    assert isDPoint3dNear (expectedStart, startTangent, EPSILON) == True
    assert isDPoint3dNear (expectedEnd, endTangent, EPSILON) == True

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ICurveQuery_GetClosestCurvePoint_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    
    ptList = [DPoint3d() for _ in range(NV)]
    InitPoints (ptList)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(ptList[i])
    
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    
    curveQuery = CurveHandler.ElementToCurveVector (m_eeh)
    assert None != curveQuery
    
    targetPoint = DPoint3d(5.0, 5.0, 5.0)
    CENTER_INDEX = 5
    expectedPoint = ptList[CENTER_INDEX]
    expectedParametricResult = 0.5
    
    cvd = CurveLocationDetail()
    assert True == curveQuery.ClosestPointBounded(targetPoint, cvd)
    assert isDPoint3dNear (expectedPoint, cvd.point, EPSILON) == True
    assert abs (expectedParametricResult - cvd.componentFraction) <= EPSILON
        

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_CurveFail(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    points.append(DPoint3d(0.0, -1.0, 0.0))
    points.append(DPoint3d(0.0, -0.5, -2))
    points.append(DPoint3d(0.0, 0.0, 0.0))
    points.append(DPoint3d(1.0, 4.0, 5))
    points.append(DPoint3d(5.0 , 5.0, 0.0))
    points.append(DPoint3d(6.0, 5.0, 0.0))
    points.append(DPoint3d(7.0, 5.0, 0.0))
    
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    df = DVec3d(DVec3d(0.0, 0.0, 0.0), DVec3d(10, 0.0, 0.0))
 
    assert disp.IsPlanar(m_eeh, normal, point, df) == False

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DisplayHandler_GetOrientation_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    
    disp = m_eeh.GetHandler (MissingHandlerPermissions.eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    
    ROWS = 3
    COLS = 3
    act = RotMatrix()
    exp = RotMatrix()
    exp.InitIdentity ()
  
    disp.GetOrientation (m_eeh, act)

    for i in range(ROWS):
         for j in range(COLS):
             assert abs (act.form3d[i][j] - exp.form3d[i][j]) <= EPSILON
             print(act.form3d[i][j])

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DisplayHandler_GetTransformOrigin_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    act = DPoint3d()
    exp = DPoint3d(0.0, 0.0, 0.0)
    disp.GetTransformOrigin(m_eeh, act)
    assert isDPoint3dNear (act, exp, EPSILON) == True


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsRenderable_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    assert disp.IsRenderable(m_eeh) == False

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_GetElemDisplayParams_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    propQuery = ElementPropertiesGetter (m_eeh)
    assert propQuery.GetColor () == 0
    assert propQuery.GetLineStyle () == 0
    assert propQuery.GetWeight () == 0
    assert propQuery.GetLevel () == LEVEL_DEFAULT_LEVEL_ID

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DisplayHandler_GetSnapOrigin_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    expPoint = DPoint3d(0.0, 0.0, 0.0)
    disp.GetSnapOrigin(m_eeh, point)
    assert isDPoint3dNear(expPoint, point, EPSILON) == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DisplayHandler_IsPlanar_Curve(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)
    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray()
    for i in range(NV):
        points.append(m_points[i])
    assert CurveHandler.CreateCurveElement (m_eeh, None, points, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    point = DPoint3d()
    normal = DVec3d()
    df = DVec3d(DVec3d(0.0, 0.0, 0.0), DVec3d(10, 0.0, 0.0))
    elm = m_eeh.GetElement()
    line = DVec3d()
    line.x = elm.line_string_3d.vertice[3].x - elm.line_string_3d.vertice[2].x
    line.y = elm.line_string_3d.vertice[3].y - elm.line_string_3d.vertice[2].y
    line.z = elm.line_string_3d.vertice[3].z - elm.line_string_3d.vertice[2].z
    isPerp(normal, line)
    pln = DPlane3d()
    plane = pln.InitFromOriginAndNormal (point, normal)
    assert pln.Evaluate (elm.line_string_3d.vertice[3]) <= ComputeDistancePrecision (elm.line_string_3d.vertice[3], pln.origin)
    assert pln.Evaluate (elm.line_string_3d.vertice[2]) <= ComputeDistancePrecision (elm.line_string_3d.vertice[2], pln.origin)
    assert pln.Evaluate (elm.line_string_3d.vertice[1]) <= ComputeDistancePrecision (elm.line_string_3d.vertice[1], pln.origin)
    assert pln.Evaluate (elm.line_string_3d.vertice[0]) <= ComputeDistancePrecision (elm.line_string_3d.vertice[0], pln.origin)
    assert disp.IsPlanar(m_eeh, normal, point, df) == True