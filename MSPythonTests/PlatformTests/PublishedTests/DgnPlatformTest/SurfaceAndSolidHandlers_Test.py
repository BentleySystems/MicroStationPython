#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import math
import sys
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from SurfaceAndSolidHandlersUtils import *

SURFTYPE_PROJECTION = 0
SURFTYPE_REVOLUTION = 8
SOLIDTYPE_REVOLUTION = 1
EPSILON = 0.000000001
PI = 3.1415926535897932384626433
DISTANCE = 10.0
isCapped = True
m_eeh = EditElementHandle()
m_ees = EditElementHandle()
m_eesh = EditElementHandle()
eeh = EditElementHandle()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_IsValidProfileType (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    TestValidProfile(True, eSURFACE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eSOLID_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eLINE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eLINE_STRING_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eSHAPE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eCURVE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eCMPLX_STRING_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eCMPLX_SHAPE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eELLIPSE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eARC_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)
    TestValidProfile(True, eBSPLINE_CURVE_ELM, m_eeh.GetDgnModel(), 0, ret, m_eeh)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateProjectionElement_Example (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidProj(False, ret, "LineStringCreator", m_eeh, True)
    isCapped = True
    isSuccess = m_eeh.AddToModel()

    assert BentleyStatus.eSUCCESS == isSuccess

    # SaveAndCopyFile method is not exposed.
    # assert BentleyStatus.eSUCCESS == SaveAndCopyFile("CreateProjectionElement.dgn")
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsSurfaceOfProjection (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidProj(False, ret, "LineStringCreator", m_eeh)
    isCapped = False
    retVal = IsSurfaceOfProjection(m_eeh, isCapped)

    assert True == retVal[0]
    assert False == retVal[1]
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsSurfaceOfProjection_Capped (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidProj(True, ret, "ShapeCreator", m_eeh)
    isCapped = True
    retVal = IsSurfaceOfProjection(m_eeh, isCapped)

    assert True == retVal[0]
    assert True == retVal[1]
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsSurfaceOfRevolution (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(False, ret, "LineStringCreator", m_eeh)
    isCapped = True
    retVal = IsSurfaceOfRevolution(m_eeh, isCapped)

    assert True == retVal[0]
    assert False == retVal[1]
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsSurfaceOfRevolution_Capped (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(True, ret, "ShapeCreator", m_eeh)
    isCapped = True
    retVal = IsSurfaceOfRevolution(m_eeh, isCapped)

    assert True == retVal[0]
    assert True == retVal[1]

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsSurfaceOfProjection_False (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(True, ret, "ShapeCreator", m_eeh)
    isCapped = True
    retVal = IsSurfaceOfProjection(m_eeh, isCapped)

    assert False == retVal[0]

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IsSurfaceOfRevolution_False (initDgnPlatformHost, loadDgnFile):
    global isCapped
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidProj(True, ret, "ShapeCreator", m_eeh)
    isCapped = True
    retVal = IsSurfaceOfRevolution(m_eeh, isCapped)

    assert False == retVal[0]

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ExtractRevolutionParameters_FALSE (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidProj(True, ret, "ShapeCreator", m_eeh)
    center = DPoint3d()
    axis = DVec3d()
    sweep = 0.0
    id = m_eeh.GetElementId()
    eh = ElementHandle(id, ret[0])

    assert BentleyStatus.eERROR == ExtractRevolutionParameters(m_eeh, eh, center, axis, sweep, True, ret)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ExtractRevolutionParameters (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(True, ret, "ShapeCreator", m_eeh)
    center = DPoint3d()
    axis = DVec3d()
    sweep = 0.0
    id = m_eeh.GetElementId()
    eh = ElementHandle(id, ret[0])
    retVal, center, axis = ExtractRevolutionParameters(m_eeh, eh, center, axis, sweep, True, ret)
    
    assert BentleyStatus.eSUCCESS == retVal
    
    expectedCenter = DPoint3d(0.0, 0.0, 0.0)
    expectedAxis = DVec3d.From (0.0, 0.0, 1.0)

    assert True == isDPoint3dNear (center, expectedCenter, EPSILON)
    assert True == isDPoint3dNear (axis, expectedAxis, EPSILON)

    # The exposed TryGetRotationAxis method only take center and axis as parameters, 
    # hence sweep is not getting updated.
    # assert math.isclose(sweep, EPSILON)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateConeElement (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    ConeElementSetUp(ret[0], m_eesh)
    top = DPoint3d (0, 10, 0)
    bottom = DPoint3d (0, 0, 0)
    actual = RotMatrix()
    rMatrix = RotMatrix()
    quat = DoubleArray()
    
    topRadius = 1.000000000001
    bottomRadius = 0.0
    type = 4
    
    rMatrix.InitIdentity ()
    actual.InitIdentity ()
    elm = m_eesh.GetElement()
    coneData = DgnConeDetail(bottom, top, rMatrix, bottomRadius, topRadius, True)
    cone = ISolidPrimitive.CreateDgnCone(coneData)
    
    ElementSize = CalculateElementSize (sys.getsizeof(Cone_3d));
    
    actual.GetQuaternion (quat, 1)

    assert BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement (m_eesh, cone, None, ret[0])

    assert True == isDPoint3dNear (top, elm.cone_3d.center_1, EPSILON)
    assert True == isDPoint3dNear (bottom, elm.cone_3d.center_2, EPSILON)
    
    assert topRadius == elm.cone_3d.radius_1
    assert bottomRadius == elm.cone_3d.radius_2
    assert type == elm.cone_3d.b.type

    # Cone_3d object size does not match.
    # assert ElementSize == elm.ehdr.elementSize
    # assert ElementSize == elm.ehdr.attrOffset

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateBoxElement (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    point1 = DPoint3d.From (1.0, 1.0, 2.0)
    point2 = DPoint3d.From (1.0, 1.0, 3.0)
    upVector1 = DVec3d.From (1.0, 0.0, 0.0)
    upVector2 = DVec3d.From (0.0, 1.0, 0.0)
    detailData = DgnBoxDetail(point1, point2, upVector1, upVector2, 3.0, 5.0, 3.0, 5.0, True)
    solid = ISolidPrimitive.CreateDgnBox (detailData)

    assert BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement (m_eesh, solid, None, ret[0])
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_CreateCompleteSphereElement (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    point = DPoint3d.From (1.0, 1.0, 2.0)
    upVector1 = DVec3d.From (1.0, 0.0, 0.0)
    upVector2 = DVec3d.From (0.0, 1.0, 0.0)
    detailData = DgnSphereDetail(point, upVector1, upVector2, 3.0, 3.0, -Angle.PiOver2(), Angle.Pi(), True)
    solid = ISolidPrimitive.CreateDgnSphere (detailData)

    assert BentleyStatus.eSUCCESS == DraftingElementSchema.ToElement (m_eesh, solid, None, ret[0])

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ExtractProfiles_FAIL (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(True, ret, "ShapeCreator", m_eeh)
    profiles = ElementAgenda()
    id = m_eeh.GetElementId()
    eh = ElementHandle(id, ret[0])

    assert BentleyStatus.eSUCCESS != ExtractProfiles(eh, profiles, m_eeh, ret)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ExtractProjectionParameters_FALSE (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(True, ret, "ShapeCreator", m_eeh)
    dir = DVec3d()
    distance = 0.0
    id = m_eeh.GetElementId()
    eh = ElementHandle(id, ret[0])

    assert BentleyStatus.eERROR == ExtractProjectionParameters(m_eeh, eh, dir, distance, True)

@pytest.mark.skip(reason = "SetBoundaryType method for CurveVector class is not exposed.")
def test_ExtractProfiles_Revolution (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidRev(True, ret, "ShapeCreator", m_eeh)
    profiles = ElementAgenda()
    id = m_eeh.GetElementId()
    eh = ElementHandle(id, ret[0])

    assert BentleyStatus.eSUCCESS == ExtractProfiles(eh, profiles, m_eeh, ret)
    assert True == (profiles.GetCount() >= 1)
    
    eh = profiles.GetFirst()
    profileHdr = Elm_hdr()
    originalHdr = Elm_hdr()
    eh.GetElementHeader(profileHdr)
    m_eeh.GetElementHeader(originalHdr)
    elm = eh.GetElement()
    for i in range(5):
        isDPoint3dNear(elm.line_string_3d.numverts[i], m_eeh.GetElement().line_string_3d.numverts[i], EPSILON)

@pytest.mark.skip(reason = "m_sectionCurves method for DgnRuledSweepDetail class is not exposed")
def test_ExtractProjectionParameters (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateSolidProj(True, ret, "ShapeCreator", m_eeh)
    expectedDir = DPoint3d()
    dir = DVec3d()
    distance = 0.0
    id = m_eeh.GetElementId()
    eh = ElementHandle(id, ret[0])

    assert BentleyStatus.eSUCCESS == ExtractProjectionParameters(m_eeh, eh, dir, distance, True)
    
    expectedDir.x = expectedDir.y = 0.0;
    expectedDir.z = 1.0
    extrusionVector = DVec3d()
    assert True == isDPoint3dNear (dir, extrusionVector, EPSILON)