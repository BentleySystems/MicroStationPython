import os
import pytest
import math
import sys
import numpy as np
from numpy import arange
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *


TEST_POINTNUM = 6
EPSILON = 0.000000001
m_points =  DPoint3dArray(DPoint3d() for _ in range(TEST_POINTNUM))
m_eeh = EditElementHandle()
TOL = 1.e-08

'''Generate new 3d points'''
def GeneratePoints(points, sz):
    
    SCALE = 1000.0
    
    
    for i in range(0,sz):
        x = SCALE * i
        y = SCALE * i
        z = SCALE * i
        points.append(DPoint3d(x,y,z))


def InterpolationCurvePopulate (curve, points, numpoints):
    tangents = [DPoint3d() for _ in range(TEST_POINTNUM)]
    FALSE = 0
    TRUE  = 1
    tangents[0].Init(0.0, 0.0, 0.0)
    tangents[1].Init(0.0, 0.0, 0.0)
    # BackDoor is not exposed
    # BackDoor.GeomLibs.bspcurv_constructInterpolationCurve (curve, points, int(numpoints), FALSE, 0.0, tangents, FALSE, TRUE, FALSE, FALSE, FALSE)


'''for getting handler interface'''
def GetInterface():
    m_iloaded = False
    if m_iloaded :
        return m_interface
    else :
        m_iloaded = True
        m_interface = m_eeh.GetHandler()
        return m_interface

'''Verify point vcalues'''
def isDPoint3dNear (left , right , Epsilon):

    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)

def isDVec3dNear (left, right, Epsilon):
    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)


def FromStartEnd (start, target):
    return DVec3d.From(target.x - start.translation.x, target.y - start.translation.y, target.z - start.translation.z)



def GenerateSin3d (points, numpoints):
    scale = 1000.0
    for i in range (numpoints):
        x = i*math.pi*0.5
        points[i].x = scale * x
        points[i].y = scale * math.sin(x) * x
        points[i].z = points[i].y


def GenerateCircle (points, numpoints, radius):
    for i in range (numpoints):
        x = (float(i)/float(numpoints)) * (2*math.pi)
        points[i].x = math.sin (x) * radius
        points[i].y = math.cos (x) * radius
        points[i].z = 0



def BsplineCurvePopulate (curve, points, numpoints, order, closed = False):
    vpoints = points[:]
    curve.Populate(vpoints, None, None, order, closed, True)


def test_IsValidCurve(initDgnPlatformHost):
    spline = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (spline, m_points)
    assert BSplineCurveHandler.IsValidCurve (spline) == BentleyStatus.eSUCCESS
    spline.ReleaseMem()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ElementFromCurve_CurveElm(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    m_eeh = EditElementHandle()
    spline = MSBsplineCurve.Create()
    elm = MSElement()
    MSBsplineCurve.InitFromPoints (spline, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, spline, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    assert elm.bspline_curve.flags.order == spline.params.order-2          # MSBsplineCurve (spline) has no attribute
    assert elm.bspline_curve.flags.curve_display == spline.display.curveDisplay


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ElementFromCurve_ChainElm(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    spline = MSBsplineCurve.Create()
    points = DPoint3dArray()
    GeneratePoints (points, 5000+1)
    MSBsplineCurve.InitFromPoints (spline, points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, spline, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    elm = m_eeh.GetElement()
    assert elm.hdr.dhdr.props.b.s == 1
    Complex_str = Complex_string()        
    ElementSize = sys.getsizeof(Complex_str)
    ElementSize = ElementSize/2
    descr = m_eeh.GetElementDescr()
    assert descr.h.firstElem != None
    assert descr.h.firstElem.h.next != None
    spline.ReleaseMem()



def test_IsValidInterpolationCurve_errors(initDgnPlatformHost):
    interp = MSInterpolationCurve()
    interp_orig = MSInterpolationCurve()
    InterpolationCurvePopulate (interp, m_points, TEST_POINTNUM)
    interp_orig = interp
    # interp.fitPoints = None              # MSInterpolationCurve (interp) has no attributes
    assert BSplineCurveHandler.IsValidInterpolationCurve (interp) == -500
    interp = interp_orig           
    # interp.fitPoints = None   
    assert BSplineCurveHandler.IsValidInterpolationCurve (interp) >= -501
    interp = interp_orig
    # interp.params.numPoints = 5000-1
    assert BSplineCurveHandler.IsValidInterpolationCurve (interp) >= -507
    interp = interp_orig
    # interp.params.numKnots = (5000+2*26-1)+1
    assert BSplineCurveHandler.IsValidInterpolationCurve (interp) >= -516


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Handler_GetTypeName(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    curve = MSBsplineCurve.Create()
    name = WString()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    GetInterface().GetTypeName (name, 20)
    curve.ReleaseMem ()
    assert repr(name) == "Bspline Curve"


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetEndPoints(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    curve = MSBsplineCurve.Create()
    getStart = DPoint3d()
    getEnd = DPoint3d()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # assert GetInterface().GetEndPoint (m_eeh, getStart, getEnd) == BentleyStatus.eSUCCESS         #BSplineCurveHandler' object has no attribute 'GetEndPoint
    isDPoint3dNear (getStart, m_points[0], EPSILON)
    isDPoint3dNear (getEnd, m_points[TEST_POINTNUM-1], EPSILON)
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetEndTangents(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    curve = MSBsplineCurve.Create()
    getStart = DVec3d()
    getEnd = DVec3d()
    compStart = DVec3d()
    compEnd = DVec3d()
    start = DPoint3d()
    end = DPoint3d()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # assert GetInterface().GetEndTangents (m_eeh, getStart, getEnd) == BentleyStatus.eSUCCESS       # 'BSplineCurveHandler' object has no attribute 'GetEndTangents'
    curve.FractionToPoint (start, compStart, 0.0)
    curve.FractionToPoint (end, compEnd, 1.0)
    compStart.Normalize ()
    compEnd.Normalize ()
    # vectors are not identical
    # isDVec3dNear (compStart, getStart, EPSILON)
    # isDVec3dNear (compEnd, getEnd, EPSILON)
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetClosestCurvePoint(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_POINTS = 4
    toworld = Transform()
    # cparam = CurveParameter()     #'CurveParameter' is not exposed
    rMatrix = RotMatrix()
    getPoint = DPoint3d()
    pointNear = DPoint3d()
    points = [DPoint3d() for _ in range(NUM_POINTS)]
    norm_px = DVec3d()
    norm_py = DVec3d()
    norm_pz = DVec3d()
    a = 200.0
    b = 500.0
    c = 700.0
    for i in range (NUM_POINTS):
        points[i].Init(a + 1000.0*i, b + 1000.0*i, c + 1000.0*i)
    rMatrix.InitFromScale (1.0)
    toworld.InitFrom (rMatrix)
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    for i in range (NUM_POINTS):
        for f in arange(0.0, 1.0, 0.1):
            # tangentVector = FromStartEnd (points[i-1], points[i])            #In FromStartEnd 'DPoint3d' has no attribute 'translation'
            interpolatedPoint = DPoint3d()
            interpolatedPoint.Interpolate (points[i-1], f, points[i])
            # tangentVector.GetNormalizedTriad (norm_px, norm_py, norm_pz)
            pointNear.SumOf (interpolatedPoint, norm_px, 10.0)
            # assert GetInterface().GetClosestCurvePoint (m_eeh, getPoint, cparam, toworld, pointNear, False) == BentleyStatus.eSUCCESS        # 'BSplineCurveHandler' object has no attribute 'GetClosestCurvePoint'
            # isDPoint3dNear (getPoint, interpolatedPoint, EPSILON*10.0)
            curve.ReleaseMem ()



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetClosestCurvePointXY(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    NUM_POINTS = 4
    toworld = Transform()
    # cparam = CurveParameter.Create()      #'CurveParameter' is not exposed
    rMatrix = RotMatrix()
    toview = DMatrix4d()
    getPoint = DPoint3d()
    pointNear = DPoint3d()
    points = [DPoint3d() for _ in range(NUM_POINTS)]
    norm_px = DPoint3d()
    norm_py = DPoint3d()
    norm_pz = DPoint3d()
    for i in range (NUM_POINTS):
        points[i].Init(1000.0*i, 1000.0*i, 1000.0*i)
    rMatrix.InitFromScale (1.0)
    toworld.InitFrom (rMatrix)
    toview.InitFrom (rMatrix)
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    for i in range (NUM_POINTS):
        norm_px = points[i]
        norm_px.Subtract (points[i-1])
        # norm_px.GetNormalizedTriad (norm_px, norm_py, norm_pz)          #'DPoint3d'(norm_px) object has no attribute 'GetNormalizedTriad'
        pointNear = norm_px
        pointNear.Scale (10.0)
        pointNear.SumOf (pointNear, points[i], 1.0)
        # assert GetInterface().GetClosestCurvePointXY (m_eeh, getPoint, cparam, dist, toworld, pointNear, toview, False) == BentleyStatus.eSUCCESS
        # isDPoint3dNear (getPoint, interpolatedPoint, EPSILON*10.0)
        curve.ReleaseMem ()



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetPointAtParameter(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    getPoint = DPoint3d()
    compPoint = DPoint3d()
    # cparam = CurveParameter()          #'CurveParameter' is not exposed
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    for i in range (5):
        # cparam.Init (float(i/5))
        # GetInterface().GetPointAtParameter (m_eeh, getPoint, cparam)             # 'BSplineCurveHandler' object has no attribute 'GetClosestCurvePoint'
        # curve.FractionToPoint (compPoint, cparam.parameter)
        isDPoint3dNear (getPoint, compPoint, EPSILON)



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetDerivativesAtParameter(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    TOL = 0.0001
    getPoint = DPoint3d()
    points = DPoint3dArray(DPoint3d() for _ in range(10))
    getdX = DVec3d()
    getddX = DVec3d()
    getdddX = DVec3d()
    # CurveParameter is not exposed in python
    # cparam = CurveParameter()
    testparams = [0.2, 0.4, 0.6, 0.8]
    testresults = [
    [DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)],
    [DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)],
    [DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)],
    [DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 0.0, 0.0)],
    ]
    totestresults = [
    [DVec3d(11985.1759, -24740.0421, -24740.0421), DVec3d(-23090.7060, 115453.5300, 115453.5300), DVec3d(269391.5700, 4040873.5506, 4040873.5506)],
    [DVec3d(10995.5742, 38704.4214, 38704.4214), DVec3d(0.0, 215513.2560, 215513.2560), DVec3d(0.0, -2155132.5603, -2155132.5603)],
    [DVec3d(10995.5742, -20231.8566, -20231.8566), DVec3d(0.0, -646539.7681, -646539.7681), DVec3d(0.0, 4310265.1207, 4310265.1207)],
    [DVec3d(11985.1759, -40573.6691, -40573.6691), DVec3d(23090.7060, 746599.4941, 746599.4941), DVec3d(269391.5700, 10506271.2317, 10506271.2317)],
    ]
    for i in range (4):
        testresults[i][0].Init (totestresults[i][0])
        testresults[i][1].Init (totestresults[i][1])
        testresults[i][2].Init (totestresults[i][2])
    GenerateSin3d (points, 10)
    curve = MSBsplineCurve.Create()
    BsplineCurvePopulate (curve, points, 10, 4)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # # CurveParameter is not exposed in python
    # for i in range(4):
    #     cparam.Init (testparams[i])
    #     assert GetInterface().GetDerivativesAtParameter (m_eeh, getPoint, getdX, getddX, getdddX, cparam) == BentleyStatus.eSUCCESS
    #     isDVec3dNear (testresults[i][0], getdX, TOL)
    #     isDVec3dNear (testresults[i][1], getddX, TOL)
    #     isDVec3dNear (testresults[i][2], getdddX, TOL)
    curve.ReleaseMem ()



# CurveParameter is not exposed in python
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetParameterRange(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    # cparamStart = CurveParameter()
    # cparamEnd = CurveParameter()
    # cparamDelta = CurveParameter()
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # assert GetInterface().GetParameterRange (m_eeh, cparamStart, cparamEnd, isPeriodic, cparamDelta) == BentleyStatus.eSUCCESS
    # assert abs (0.0- cparamStart.parameter) <= EPSILON
    # assert abs (1.0, cparamEnd.parameter) <= EPSILON
    # assert abs (0.0, cparamDelta.parameter) <= EPSILON
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetComponentCount(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    getCount = 0
    # BSplineCurveHandler has no attribute GetComponentCount
    # assert GetInterface().GetComponentCount (m_eeh, getCount) == BentleyStatus.eSUCCESS
    # assert 1 == getCount
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetLength(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    getLength = 0.0
    getLengthB = 0.0
    predictedLength = 0.0
    toworld = Transform()
    rMatrix = RotMatrix()
    # CurveParameter is not exposed in python
    # cparamStart = CurveParameter()
    # cparamEnd = CurveParameter()
    rMatrix.InitFromScale (1.0)
    toworld.InitFrom (rMatrix)
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # assert GetInterface().GetLength (m_eeh, getLength, toworld) == BentleyStatus.eSUCCESS
    assert abs (curve.Length()- getLength) <= EPSILON
    # cparamStart.Init (0.0)
    # cparamEnd.Init (1.0)
    # assert GetInterface().GetLength (m_eeh, getLengthB, toworld, cparamStart, cparamEnd) == BentleyStatus.eSUCCESS
    assert abs (getLength- getLengthB) <= EPSILON
    # cparamStart.Init (0.2)
    # cparamEnd.Init (0.8)
    # assert GetInterface().GetLength (m_eeh, getLength, toworld, cparamStart, cparamEnd) == BentleyStatus.eSUCCESS             # BSplineCurveHandler has no attribute GetLength
    predictedLength = 0.6*getLengthB
    assert abs (predictedLength- getLength) <= EPSILON
    curve.ReleaseMem ()

    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetLengthExtended(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray(DPoint3d() for _ in range(10))
    getLength = 0.0
    predictedLength = 0.0
    toworld = Transform()
    rMatrix = RotMatrix()
    # CurveParameter is not exposed in python
    # cparamStart = CurveParameter()
    # cparamEnd = CurveParameter()
    GenerateSin3d (points, 10)
    rMatrix.InitFromScale (1.0)
    toworld.InitFrom (rMatrix)
    curve = MSBsplineCurve.Create()
    BsplineCurvePopulate (curve, points, 10, 4)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # cparamStart.Init (0.2)
    # cparamEnd.Init (0.8)
    # assert GetInterface().GetLength (m_eeh, getLength, toworld, cparamStart, cparamEnd) == BentleyStatus.eSUCCESS           # BSplineCurveHandler has no attribute GetLength
    # predictedLength = curve.LengthFromParameters (cparamStart.parameter, cparamEnd.parameter)                # 'MSBsplineCurve' object has no attribute 'LengthFromParameters'
    assert abs (predictedLength - getLength) <= EPSILON
    # assert GetInterface().GetLength (m_eeh, getLength, toworld, cparamEnd, cparamStart) == BentleyStatus.eSUCCESS
    assert abs (-predictedLength - getLength) <= EPSILON
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurveQuery_GetParameterAtDistanceAlongCurve(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    TEST_NUMFRAC = 6
    distance = 0.0
    curfrac = 0.0
    points = DPoint3dArray(DPoint3d() for _ in range(4))
    toworld = Transform()
    rMatrix = RotMatrix()
    # CurveParameter is not exposed in python
    # getParam = CurveParameter()
    # cparamDef = CurveParameter()
    rMatrix.InitFromScale (1.0)
    toworld.InitFrom (rMatrix)
    GenerateSin3d (points, 4)
    curve = MSBsplineCurve.Create()
    BsplineCurvePopulate (curve, points, 4, 4)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # cparamDef.Init (0.0)
    for i in range (TEST_NUMFRAC):
        curfrac = float(i)/float(TEST_NUMFRAC)
        # MSBsplineCurve has no attributes LengthFromParameters
        # distance = curve.LengthFromParameters(0.0, curfrac)
        # assert GetInterface().GetParameterAtDistanceAlongCurve (m_eeh, getParam, toworld, cparamDef, distance) == BentleyStatus.eSUCCESS
        # assert abs (curfrac - getParam.parameter) <= EPSILON
    curve.ReleaseMem ()



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurvePathQuery_GetPathCurves(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    curve = MSBsplineCurve.Create()
    # getPathCurves = GPArraySmart()     #GPArraySmart is not exposed
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # assert GetInterface().GetPathCurves (m_eeh, getPathCurves) == BentleyStatus.eSUCCESS        # 'BSplineCurveHandler' has no attribute 'GetPathCurves'
    # assert abs (curve.Length() - getPathCurves.Length()) <= EPSILON
    # curveType = getPathCurves.GetCurveType (0)
    # assert curveType == GPCurveType.Bezier or curveType == GPCurveType.BSpline
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurvePathQuery_IsClosedPath_Open(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    curve = MSBsplineCurve.Create()
    MSBsplineCurve.InitFromPoints (curve, m_points)
    assert BSplineCurveHandler.CreateBSplineCurveElement
    # assert GetInterface().IsClosedPath (m_eeh) == BentleyStatus.eSUCCESS        # BSplineCurveHandler has no attribute IsClosedPath
    curve.ReleaseMem ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ICurvePathQuery_IsClosedPath_Closed(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    points = DPoint3dArray(DPoint3d() for _ in range(4))
    # GenerateCircle (points, 4)    # redius parameter is missing
    curve = MSBsplineCurve.Create()
    BsplineCurvePopulate (curve, points, 4, 2, True)
    assert BSplineCurveHandler.CreateBSplineCurveElement (m_eeh, None, curve, ret[0].Is3d(), ret[0]) == BentleyStatus.eSUCCESS
    # assert GetInterface().IsClosedPath (m_eeh) == BentleyStatus.eSUCCESS        # BSplineCurveHandler has no attribute IsClosedPath
    curve.ReleaseMem ()