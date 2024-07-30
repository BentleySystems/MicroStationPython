#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import sys
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

MAX_POLES = 5000
EPSILON = 0.000000001
m_eeh = EditElementHandle()

def isDPoint3dNear (left , right , Epsilon):

    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon

    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)


def FillSurfacePoints (points , pointnum, perrow):

    yStep = 200.0
    for i in range(0,pointnum):
    
        j = (int)(i / perrow)
        points.append(DPoint3d(1000*(i/perrow),yStep * j,0))
    return points


def getMPoints ():
    points = DPoint3dArray()
    m_points = DPoint3dArray ()
    res = FillSurfacePoints(points,9, 3)
    for i in range(0,9):
        m_points.append(res[i])
    
    return m_points


def isDoubleArrayNear (left,  right,  arraySize,  Epsilon):
    
    keepTestingFabs = True
    for i in range(0,arraySize):
        
        res = abs (left[i]- right[i])
        assert res <= Epsilon
        if (keepTestingFabs and abs (left[i] - right[i]) < Epsilon):
            
            keepTestingFabs = False

    return keepTestingFabs

def isDPoint3dArrayNear(left , right , epsilon , numPoints):
    result = True
    for i in range(0,numPoints):
        
        if (isDPoint3dNear (left[i], right[i], epsilon) == False):
            result = False
        
    return result


def GetInterface ():

    m_interface = m_eeh.GetHandler()
    return m_interface


def test_IsValidSurface():
    
    m_points = getMPoints ()
    surface = MSBsplineSurface()
    surface.Populate (m_points, None, None, 3, 3, False, None, 3, 3, False, False)

    assert BSplineStatus.eBSPLINE_STATUS_Success == BSplineSurfaceHandler.IsValidSurface (surface)
    surface.ReleaseMem ()

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ElementFromSurface(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    m_points = getMPoints ()

    surface = MSBsplineSurface()
    surface.Populate (m_points, None, None, 3, 3, False, None, 3, 3, False, False)

    if(BentleyStatus.eSUCCESS != BSplineSurfaceHandler.CreateBSplineSurfaceElement (m_eeh, None, surface, ret[0])):
         surface.ReleaseMem ()
         assert False
    
    elm = m_eeh.GetElement ()

    assert elm.bspline_surface.flags.order == surface.uParams.order - 2
    assert elm.bspline_surface.flags.curve_display == surface.display.curveDisplay
    assert elm.bspline_surface.flags.poly_display == surface.display.polygonDisplay
    assert elm.bspline_surface.flags.rational == surface.rational
    assert elm.bspline_surface.flags.closed == surface.uParams.closed

    assert elm.bspline_surface.flags.curve_type == surface.type
    assert elm.bspline_surface.bsurf_flags.v_order == surface.vParams.order - 2
    assert elm.bspline_surface.bsurf_flags.arcSpacing == surface.display.rulesByLength
    assert elm.bspline_surface.bsurf_flags.v_closed == surface.vParams.closed

    assert elm.bspline_surface.num_poles_u == surface.uParams.numPoles 
    assert elm.bspline_surface.num_knots_u == surface.uParams.numKnots 
    assert elm.bspline_surface.rule_lines_u == surface.uParams.numRules

    assert elm.bspline_surface.num_poles_v == surface.vParams.numPoles
    assert elm.bspline_surface.num_knots_v == surface.vParams.numKnots
    assert elm.bspline_surface.rule_lines_v, surface.vParams.numRules

    assert elm.bspline_surface.num_bounds == surface.numBounds 
    assert elm.bspline_surface.dhdr.props.b.h == surface.holeOrigin
    surface.ReleaseMem ()  

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_ElementFromSurface_CellElement(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    points_large = DPoint3dArray ()
    unumpoints = MAX_POLES+1
    vnumpoints = (MAX_POLES*4)//unumpoints
    large_polenum = unumpoints*vnumpoints
    points = DPoint3dArray ()

    res = FillSurfacePoints (points, MAX_POLES*4, unumpoints)
    for i in range(0,int(large_polenum)):
        points_large.append(res[i])

    surface = MSBsplineSurface()
    surface.Populate (points_large, None, None, 3, unumpoints, False, None, 3, int(vnumpoints), False, False)

    if(BentleyStatus.eSUCCESS != BSplineSurfaceHandler.CreateBSplineSurfaceElement (m_eeh, None, surface, ret[0])):
        surface.ReleaseMem ()
        assert False
    descr = m_eeh.GetElementDescr ()
    print(descr)
    assert None != descr.h.firstElem
    assert 1 == descr.h.firstElem.h.isValid
    assert None != descr.h.firstElem.h.next
    assert 1 == descr.h.firstElem.h.next.h.isValid
    surface.ReleaseMem ()

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_Handler_GetTypeName(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    m_points = getMPoints ()

    surface = MSBsplineSurface()
    name= WString()

    surface.Populate (m_points, None, None, 3, 3, False, None, 3, 3, False, False)

    if(BentleyStatus.eSUCCESS != BSplineSurfaceHandler.CreateBSplineSurfaceElement (m_eeh, None, surface, ret[0])):
         surface.ReleaseMem ()
         assert False
    
    res= GetInterface()

    res.GetTypeName(name,20)
    assert repr(name) == "Bspline Surface"

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DisplayHandler_GetOrientation(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    m_points = getMPoints ()
    surface = MSBsplineSurface()
    orientation = RotMatrix()
    get_orientation = RotMatrix()
    xvec = DVec3d()
    yvec = DVec3d()
    orientation_row=DVec3d()
    get_orientation_row=DVec3d()

    surface.Populate (m_points, None, None, 3, 3, False, None, 3, 3, False, False)

    if(BentleyStatus.eSUCCESS != BSplineSurfaceHandler.CreateBSplineSurfaceElement (m_eeh, None, surface, ret[0])):
         surface.ReleaseMem ()
         assert False
    
    res= GetInterface()
    res.GetOrientation (m_eeh, get_orientation)
    print(surface)
    xvec.DifferenceOf (surface.GetPole(1), surface.GetPole(0))
    yvec.DifferenceOf (surface.GetPole(surface.GetNumUPoles()), surface.GetPole(0))

    orientation.InitFrom2Vector (xvec, yvec)
    orientation.SquareAndNormalizeColumns (orientation, 0, 1)
    orientation.GetRow(orientation_row,0)
   
    list1=list()
    list1.append(orientation_row.x)
    list1.append(orientation_row.y)
    list1.append(orientation_row.z)

    get_orientation.GetRow(get_orientation_row,0)
    list2=list()
    list2.append(get_orientation_row.x)
    list2.append(get_orientation_row.y)
    list2.append(get_orientation_row.z)

    isDoubleArrayNear (list1,list2, 3, EPSILON)
    list1=[]
    list2=[]

    orientation.GetRow(orientation_row,1)
    list1.append(orientation_row.x)
    list1.append(orientation_row.y)
    list1.append(orientation_row.z)

    get_orientation.GetRow(get_orientation_row,1)
    list2.append(get_orientation_row.x)
    list2.append(get_orientation_row.y)
    list2.append(get_orientation_row.z)

    isDoubleArrayNear (list1,list2, 3, EPSILON)
    list1=[]
    list2=[]

    orientation.GetRow(orientation_row,2)
    list1.append(orientation_row.x)
    list1.append(orientation_row.y)
    list1.append(orientation_row.z)

    get_orientation.GetRow(get_orientation_row,2)
    list2.append(get_orientation_row.x)
    list2.append(get_orientation_row.y)
    list2.append(get_orientation_row.z)

    isDoubleArrayNear (list1,list2, 3, EPSILON)

@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_DisplayHandler_GetBsplineSurface(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    m_points = getMPoints ()
    xvec = DPoint3dArray()
    yvec = DPoint3dArray()
    surface = MSBsplineSurface()
    surface.Populate (m_points, None, None, 3, 3, False, None, 3, 3, False, False)

    if(BentleyStatus.eSUCCESS != BSplineSurfaceHandler.CreateBSplineSurfaceElement (m_eeh, None, surface, ret[0])):
         surface.ReleaseMem ()
         assert False

    surfaceFromElement = MSBsplineSurface()
    res= GetInterface()
    result = res.GetBsplineSurface(m_eeh)
    assert BentleyStatus.eSUCCESS == result[0]

    arr1= DoubleArray()
    arr2= DoubleArray()
    arr3= DoubleArray()
    surface.GetUKnots(arr1)
    
    result[1].GetUKnots(arr2)
    
    print(result[1])
    isDoubleArrayNear (arr1, arr2, surface.GetUOrder() * 2, EPSILON)
    
    result[1].GetWeights(arr3)
    assert 0 == len(arr3)
    assert surface.GetNumBounds() == result[1].GetNumBounds()
    assert surface.holeOrigin == surfaceFromElement.holeOrigin

    surface.GetPoles(xvec)
    result[1].GetPoles(yvec)

    isDPoint3dArrayNear (xvec, yvec, EPSILON, 9)
    surface.ReleaseMem ()




