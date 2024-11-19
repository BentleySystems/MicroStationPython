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

def isDPoint3dNear(left, right, Epsilon):
    return (abs(left.x - right.x) < Epsilon and
            abs(left.y - right.y) < Epsilon and
            abs(left.z - right.z) < Epsilon)    

def GeneratePoints(points, sz):
    SCALE = 1000.0
    for i in range(0, sz):
        points[i].x = SCALE * i
        points[i].y = SCALE * i
        points[i].z = SCALE * i
        
    return points

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_CreateChainHeader(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    NUM_LINES = 3
    lines0 = EditElementHandle()
    lines1 = EditElementHandle()
    lines2 = EditElementHandle()
    Lines = [lines0, lines1, lines2]
    
    m_points = [[DPoint3d() for i in range(2)] for j in range(NUM_LINES)]
    
    for i in range(0, NUM_LINES):
        m_points[i] = GeneratePoints(m_points[i], 2)
        for j in range(0, 2):
            m_points[i][j].x = m_points[i][j].x * (i+7)
            m_points[i][j].y = m_points[i][j].y * (i+5)
            m_points[i][j].z = m_points[i][j].z * (i+6)
            
    print(m_points)
    ChainHeaderHandler.CreateChainHeaderElement(m_eeh, None, True, ret[0].Is3d(), ret[0])
    
    for j in range(0, NUM_LINES):
        pt1 = DPoint3d(m_points[j][0].x, m_points[j][0].y, m_points[j][0].z)
        pt2 = DPoint3d(m_points[j][1].x, m_points[j][1].y, m_points[j][1].z)
        seg = DSegment3d(pt1, pt2)
        LineHandler.CreateLineElement(Lines[j], None, seg, ret[0].Is3d(), ret[0])
        assert BentleyStatus.eSUCCESS == ChainHeaderHandler.AddComponentElement (m_eeh, Lines[j])
        
    assert BentleyStatus.eSUCCESS == ChainHeaderHandler.AddComponentComplete(m_eeh)
    
    numChildren = 0
    
    childIter = ChildElemIter(m_eeh)
    while childIter.IsValid():
        elm = childIter.GetElement()
        assert True == isDPoint3dNear(m_points[numChildren][0], elm.line_3d.start, EPSILON)
        assert True == isDPoint3dNear(m_points[numChildren][1], elm.line_3d.end, EPSILON)
        childIter = childIter.ToNext()
        numChildren = numChildren + 1


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_IsValidChainComponent_true(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    segment = DSegment3d(0.0, 0.0, 0.0, 1.0, 1.0, 1.0)
    
    assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement(m_eeh, None, segment,ret[0].Is3d(), ret[0])
    
    assert True == ChainHeaderHandler.IsValidChainComponentType(m_eeh)


    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_IsValidChainComponent_false(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    top = DPoint3d(0, 10, 0)
    bottom = DPoint3d(0, 0, 0)
    
    rMatrix = RotMatrix()
    rMatrix.InitIdentity()
    
    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(m_eeh, None, 2, 3, top, bottom, rMatrix, True, ret[0])
    
    assert False == ChainHeaderHandler.IsValidChainComponentType(m_eeh)