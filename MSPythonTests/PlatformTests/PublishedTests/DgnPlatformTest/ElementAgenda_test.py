import os
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

EPSILON = 0.000000001
def isDPoint3dNear(left , right ,Epsilon):

    assert abs(left.x - right.x) <= Epsilon
    assert abs(left.y - right.y) <= Epsilon
    assert abs(left.z - right.z) <= Epsilon

    return abs(left.x - right.x) < Epsilon and abs(left.y - right.y) < Epsilon and abs(left.z - right.z) < Epsilon

def GeneratePoints(points , sz):
    SCALE = 1000.0

    for i in range(0,sz):
        x = SCALE * i
        y = SCALE * i
        z = SCALE * i
        points.append(DPoint3d(x,y,z))
def InitPoints(points,size):
    SCALE = 100.0
    for i in range(0,size):
        points[i].x = i*SCALE
        points[i].y = i*SCALE
        points[i].z = i*SCALE

    

def CreateElement(type, eeh , model , is3d):
    if(type == "LineString"):
        
        NV = 5
        points = DPoint3dArray()
        GeneratePoints(points, NV)

        assert BentleyStatus.eSUCCESS == LineStringHandler.CreateLineStringElement(eeh, None, points, is3d, model)
        return
    
    if(type == "Line"):
        NV = 2
        segment = DSegment3d()
        InitPoints(segment.point,NV)
        assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement (eeh, None, segment, is3d, model)


m_eeh = EditElementHandle()

def test_GetSource(initDgnPlatformHost):
    
    agenda = ElementAgenda ()
    source = ModifyElementSource.eSelected
    #actual = ModifyElementSource()

    agenda.SetSource(source)
    actual  = agenda.GetSource()

    assert source == actual

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_InsertElemRef(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    agenda = ElementAgenda ()
    CreateElement("LineString", m_eeh, ret[0], ret[0].Is3d())
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()

    elm  = m_eeh.GetElementRef ()
    agenda.Insert (elm, ret[0], False)

    curr  = agenda.GetFirst ()
    actual  = curr.GetElement ()

    line = EditElementHandle()

    CreateElement("LineString", line, ret[0], ret[0].Is3d())
    expected  = line.GetElement ()
    for i in range(0,5):
        assert True == isDPoint3dNear(expected.line_string_3d.vertice[i], actual.line_string_3d.vertice[i], EPSILON)

 
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])     
def test_InsertElemRef_NullRef(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    agenda = ElementAgenda ()
    elm  = None
    actual = EditElementHandle()
    actual  = agenda.Insert (elm, ret[0], False)
    assert None == actual

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Find(initDgnPlatformHost, loadDgnFile): 
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    agenda = ElementAgenda ()
    CreateElement("LineString", m_eeh, ret[0], ret[0].Is3d())
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()

    elm  = m_eeh.GetElementRef ()
    agenda.Insert (elm, ret[0], False)

    res  = agenda.Find(elm, ret[0], 0 , 1)
    actual  = res.GetElement ()

    line = EditElementHandle()

    CreateElement("LineString", line, ret[0], ret[0].Is3d())
    expected  = line.GetElement ()
    for i in range(0,5):
        assert True == isDPoint3dNear(expected.line_string_3d.vertice[i], actual.line_string_3d.vertice[i], EPSILON)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])     
def test_Find_InvalidIndex(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    agenda = ElementAgenda ()
    CreateElement("LineString", m_eeh, ret[0], False)
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()
    elm  = m_eeh.GetElementRef ()
    agenda.Insert (elm, ret[0], False)

    assert None == agenda.Find(elm, ret[0], 1 , 0)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])     
def test_Find_WrongElement(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    agenda = ElementAgenda ()
    CreateElement("LineString", m_eeh, ret[0], False)
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()
    elm  = m_eeh.GetElementRef ()
    agenda.Insert (elm, ret[0], False)

    line = EditElementHandle()
    CreateElement("LineString", line, ret[0], False)
    assert None == agenda.Find(elm, ret[0], 1 , 0)
    assert BentleyStatus.eSUCCESS == line.AddToModel()

    wrong  = line.GetElementRef ()
    assert None == agenda.Find(wrong, ret[0], 0, 1)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_Find_EmptyAgenda(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    agenda = ElementAgenda ()
    line = EditElementHandle()
    CreateElement("Line", m_eeh, ret[0], False) 
    assert BentleyStatus.eSUCCESS == m_eeh.AddToModel()


    wrong  = line.GetElementRef ()
    assert None == agenda.Find(wrong, ret[0], 0, 1)