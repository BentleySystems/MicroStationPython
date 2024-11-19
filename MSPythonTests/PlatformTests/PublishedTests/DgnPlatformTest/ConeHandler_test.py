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

EPSILON = 0.000000001
eMISSING_HANDLER_PERMISSION_ChangeAttrib = 512
m_eeh = EditElementHandle()
LEVEL_DEFAULT_LEVEL_ID = 64

def ConeElementSetUp(model):
    rMatrix = RotMatrix()
    top = DPoint3d (0,10,0)
    bottom = DPoint3d (0,0,0)
    rMatrix.InitIdentity ()
    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(m_eeh, None, 5.0, 8.0, top, bottom, rMatrix, True, model)

def CreateElement (type,eeh, model, is3d):
    top = DPoint3d (0,10,0)
    bottom = DPoint3d (0,0,0)

    TOP_RADIUS = 5.0
    BOTTOM_RADIUS = 8.0

    rMatrix = RotMatrix()
    rMatrix.InitIdentity ()

    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(eeh, None, TOP_RADIUS, BOTTOM_RADIUS, top, bottom, rMatrix, is3d, model)


def isDPoint3dNear(left, right , Epsilon):

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


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateConeElement (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    top = DPoint3d (0,10,0)
    bottom = DPoint3d (0,0,0)
    type = 6.0
    quat = DoubleArray()
    actual = RotMatrix()
    ConeElementSetUp(ret[0])
    actual.InitIdentity ()
    actual.GetQuaternion (quat, 1)

    elm = m_eeh.GetElement()

    assert True == isDPoint3dNear (top, elm.cone_3d.center_1, EPSILON)
    assert True == isDPoint3dNear (bottom, elm.cone_3d.center_2, EPSILON)
    assert 5.0 == elm.cone_3d.radius_1
    assert 8.0 == elm.cone_3d.radius_2

    assert True == isQuaternionNear (elm.cone_3d.quat, quat, EPSILON)

    assert elm.cone_3d.b.type == type
   
    assert 104 == elm.ehdr.elementSize
    assert 104 == elm.ehdr.attrOffset


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateConeElement_Type2 (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    rMatrix = RotMatrix()
    top = DPoint3d (0,10,0)
    bottom = DPoint3d (0,0,0)
    quat = DoubleArray()
    actual = RotMatrix()
    rMatrix.InitIdentity ()
    type = 2
    topRadius = 1.000000000001
    bottomRadius = 1

    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(m_eeh, None, topRadius, bottomRadius, top, bottom, rMatrix, True, ret[0])

    actual.InitIdentity ()
    actual.GetQuaternion (quat, 1)

    elm = m_eeh.GetElement()

    assert True == isDPoint3dNear (top, elm.cone_3d.center_1, EPSILON)
    assert True == isDPoint3dNear (bottom, elm.cone_3d.center_2, EPSILON)
    assert topRadius == elm.cone_3d.radius_1
    assert bottomRadius == elm.cone_3d.radius_2

    assert True == isQuaternionNear (elm.cone_3d.quat, quat, EPSILON)

    assert elm.cone_3d.b.type == type
    assert 104 == elm.ehdr.elementSize
    assert 104 == elm.ehdr.attrOffset



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateConeElement_Type6 (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    rMatrix = RotMatrix()
    top = DPoint3d (0,10,0)
    bottom = DPoint3d (0,0,0)
    quat = DoubleArray()
    actual = RotMatrix()
    rMatrix.InitIdentity ()
    type = 4
    topRadius = 1.000000000001
    bottomRadius = 0
    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(m_eeh, None, topRadius, bottomRadius, top, bottom, rMatrix, True, ret[0])

    actual.InitIdentity ()
    actual.GetQuaternion (quat, 1)

    elm = m_eeh.GetElement()

    assert True == isDPoint3dNear (top, elm.cone_3d.center_1, EPSILON)
    assert True == isDPoint3dNear (bottom, elm.cone_3d.center_2, EPSILON)
    assert topRadius == elm.cone_3d.radius_1
    assert bottomRadius == elm.cone_3d.radius_2

    assert True == isQuaternionNear (elm.cone_3d.quat, quat, EPSILON)

    assert elm.cone_3d.b.type == type  
    assert 104 == elm.ehdr.elementSize
    assert 104 == elm.ehdr.attrOffset


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_IsRenderable_Cone (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    CreateElement ("Cone" , m_eeh , ret[0] , ret[0].Is3d())
    disp = m_eeh.GetHandler ()
    assert None != disp
    assert True == disp.IsRenderable(m_eeh)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetTransformOrigin_Cone (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    CreateElement ("Cone" , m_eeh , ret[0] , ret[0].Is3d())
    disp = m_eeh.GetHandler ()

    act = DPoint3d ()
    exp = DPoint3d (0,5,0)
    disp.GetTransformOrigin(m_eeh, act)
    assert True == isDPoint3dNear (act, exp, EPSILON)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetOrientation_Cone (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    CreateElement ("Cone" , m_eeh , ret[0] , ret[0].Is3d())
    disp = m_eeh.GetHandler ()
    ROWS = 3
    COLS = 3
    act = RotMatrix ()
    exp = RotMatrix ()
    exp.InitIdentity ()
    xvec = DVec3d()
    yvec = DVec3d()

    assert None != disp

    disp.GetOrientation(m_eeh, act)  
    act.GetRow(xvec,0)
    exp.GetRow(yvec,0)
    act.GetRow(xvec,1)

    for i in range(0,ROWS):
        act.GetRow(xvec,i)
        exp.GetRow(yvec,i)
        
        assert abs (xvec.x- yvec.x) <= EPSILON
        assert abs (xvec.y- yvec.y) <= EPSILON
        assert abs (xvec.z- yvec.z) <= EPSILON


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_IsPlanar_Cone (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    CreateElement ("Cone" , m_eeh , ret[0] , ret[0].Is3d())
    disp = m_eeh.GetHandler ()
    assert disp != None

    point = DPoint3d ()
    normal = DVec3d()
    def1 = DVec3d(DVec3d.From (0.0, 0.0, 1.0))
    res = disp.GetDisplayHandler()
    assert False == res.IsPlanar(m_eeh, normal, point, def1)



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetSnapOrigin_Cone (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    CreateElement ("Cone" , m_eeh , ret[0] , ret[0].Is3d())
    disp = m_eeh.GetHandler ()
    assert disp != None

    point = DPoint3d ()
    expPoint = DPoint3d (0, 5, 0)
    disp.GetSnapOrigin(m_eeh, point)
    assert True == isDPoint3dNear(expPoint, point, EPSILON)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetElemDisplayParams_Cone (initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    CreateElement ("Cone" , m_eeh , ret[0] , ret[0].Is3d())
    propQuery = ElementPropertiesGetter (m_eeh)

    assert 0 == propQuery.GetColor ()
    assert 0 == propQuery.GetLineStyle ()
    assert 0 == propQuery.GetWeight ()
    assert LEVEL_DEFAULT_LEVEL_ID == propQuery.GetLevel ()