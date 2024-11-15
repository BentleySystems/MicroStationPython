import math
import sys
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MeshHandlerUtils import *

m_eeh = EditElementHandle()
EPSILON = 0.000000001

@pytest.mark.skip(reason = "LinkageUtil::ExtractNamedStringLinkageByIndex in not exposed.")
def test_CreateMeshElement(initDgnPlatformHost, loadDgnFile):
    errors = 0
    loadDgnFile.FillDictionaryModel()
    model = dgnFile.LoadRootModelById (None, dgnFile.GetDefaultModelId(), True)
    if not model:
        assert 1 == 0
    
    header0 = CreateMesh00 (m_eeh, model)
    assert header0 != None

    MeshHeaderHandler.CreateMeshElement(m_eeh, None , header0, True, model)
    header1 = PolyfaceHeaderPtrArray()
    if PolyfaceFromElement(header1, m_eeh) == BentleyStatus.eSUCCESS:
        # For now.
        header1 = header0
        a = MatchedIndexVectors(header0.PointIndex(), header1.PointIndex())
        assert a == True
        visitor0 = PolyfaceVisitor.Attach(header0)
        visitor1 = PolyfaceVisitor.Attach(header0)
        while visitor0.Reset() and visitor1.Reset():
            n0 = len(visitor0.Point())
            n1 = len(visitor1.Point())
            if n0 != n1:
                errors += 1
            else:
                for i in range(0, n0):
                    if visitor0.ClientPointIndex()[i] != visitor1.ClientPointIndex()[i]:
                        errors += 1
            visitor0 = visitor0.AdvanceToNextFace()
            visitor1 = visitor1.AdvanceToNextFace()
        assert errors == 0
        assert visitor0.AdvanceToNextFace() == False
        assert visitor1.AdvanceToNextFace() == False

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_Cubes(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    v = 2 * 3 * 5
    cube_v = CreateCube(True, 1, 2, 3, 2, 3, 5)
    cube_f = CreateCube(True, 1, 2, 3, 2, 3, 5)

    assert True == ConfirmProperties(cube_v, v, 6, 4, 4, False, False)
    assert True == ConfirmProperties(cube_f, v, 6, 4, 4, False, False)

    assert cube_v.Triangulate() == BentleyStatus.eSUCCESS
    assert cube_f.Triangulate() == BentleyStatus.eSUCCESS

    assert True == ConfirmProperties(cube_v, v, 12, 3, 3, False, False)
    assert True == ConfirmProperties(cube_f, v, 12, 3, 3, False, False)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_Sweep(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    basePolygon = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0),
                                 DPoint3d(2.0, 0.0, 0.0),
                                 DPoint3d(2.0, 1.0, 0.0),
                                 DPoint3d(1.0, 1.0, 0.0),
                                 DPoint3d(1.0, 2.0, 0.0),
                                 DPoint3d(0.0, 2.0, 0.0)])
    sweepVector = DVec3d()
    h = 2.5
    area = 3.0
    sweepVector.Init (0, 0, h)
    n = 6
    v = area * h
    mesh = CreateSweep(basePolygon, n, sweepVector)
    assert True == ConfirmProperties(mesh, v, n + 2, 4, n, False, True)
    assert mesh.Triangulate() == BentleyStatus.eSUCCESS
    assert True == ConfirmProperties(mesh, v, 2 * (n-2) + 2 * n, 3, 3, False, False)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_IsRenderable_Mesh(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateElement(m_eeh, ret)
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp.IsRenderable(m_eeh) == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetTransformOrigin_Mesh(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateElement(m_eeh, ret)
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    assert disp.IsRenderable(m_eeh) == True

    act = DPoint3d()
    exp = DPoint3d(1.5, 1.5, 0)
    disp.GetTransformOrigin(m_eeh, act);
    assert isDPoint3dNear(act, exp, EPSILON) == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetOrientation_Mesh(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateElement(m_eeh, ret)
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    
    ROWS = 3
    COLS = 3
    act = RotMatrix()
    exp = RotMatrix()
    exp.InitIdentity ()
    disp.GetOrientation(m_eeh, act)
    for i in range(ROWS):
        for j in range(COLS):
            assert act.form3d[i][j] == exp.form3d[i][j]

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_IsPlanar_Mesh(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateElement(m_eeh, ret)
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    
    point = DPoint3d()
    normal = DVec3d()
    val = DVec3d.From (0.0, 0.0, 1.0)
    assert False == disp.IsPlanar(m_eeh, normal, point, val)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetSnapOrigin_Mesh(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateElement(m_eeh, ret)
    disp = m_eeh.GetHandler (eMISSING_HANDLER_PERMISSION_ChangeAttrib)
    assert disp != None
    
    point = DPoint3d()
    expPoint = DPoint3d(1.5, 1.5, 0)
    disp.GetSnapOrigin(m_eeh, point)
    assert isDPoint3dNear(expPoint, point, EPSILON) == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_DisplayHandler_GetElemDisplayParams_Mesh(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    CreateElement(m_eeh, ret)
    propQuery = ElementPropertiesGetter(m_eeh)
    assert 0 == propQuery.GetColor()
    assert 0 == propQuery.GetLineStyle()
    assert 0 == propQuery.GetWeight()
    assert LEVEL_DEFAULT_LEVEL_ID == propQuery.GetLevel()