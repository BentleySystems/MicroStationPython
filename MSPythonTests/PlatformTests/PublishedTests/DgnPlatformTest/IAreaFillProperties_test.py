import os
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

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

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetModelRefType_DgnCache(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    expected = DgnModelRefType.eRoot
    actual = ret[0].GetModelRefType()
    assert actual == expected

m_eeh = EditElementHandle()
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetModelRefType_DgnFile(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    expected = DgnModelRefType.eNonModel
    NUM_POINTS = 2
    points = DSegment3d()
    res=points.point
    GeneratePoints(res,NUM_POINTS)
    LineHandler.CreateLineElement (m_eeh, None, points,  ret[0].Is3d(), ret[0])
    model = loadDgnFile.GetDictionaryModel()
    actual =model.GetModelRefType()
    assert actual == expected

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Is3d_DgnCache(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)  
    expected = True
    actual = ret[0].Is3d()
    assert actual == expected

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetDgnFile_DgnCache(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    expected = loadDgnFile
    actual = ret[0].GetDgnFile()
    assert actual == expected


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetDgnModelPID_DgnCache(initDgnPlatformHost, loadDgnFile):
    expected = 0
    actual = loadDgnFile.FindModelIdByName ("Default")
    assert actual == expected


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetModelRefType_ReferenceFile(initDgnPlatformHost, loadDgnFile):
    externalizedDocMoniker = WString("<MSDocMoniker><FileName>c:\\frompw\\dms83539\\AT-70879.dgn</FileName><DmsMoniker>pw://Alpo.bentley.com:alpo-alpo/Documents/D{32c486af-2e94-4bb6-ba6c-9ca6da8c2a47}</DmsMoniker><FullPath>c:\\frompw\\dms83539\\AT-70879.dgn</FullPath></MSDocMoniker>").GetWCharCP()
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    expected = DgnModelRefType.ePrimaryRef
    ref = DgnModelRef.CreateDgnAttachment (ret[0], DgnDocumentMoniker.Create(externalizedDocMoniker), 'Test', False)
    actual = ref[1].GetModelRefType()
    assert actual == expected



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Is3d_ReferenceFile(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    externalizedDocMoniker = WString("<MSDocMoniker><FileName>c:\\frompw\\dms83539\\AT-70879.dgn</FileName><DmsMoniker>pw://Alpo.bentley.com:alpo-alpo/Documents/D{32c486af-2e94-4bb6-ba6c-9ca6da8c2a47}</DmsMoniker><FullPath>c:\\frompw\\dms83539\\AT-70879.dgn</FullPath></MSDocMoniker>").GetWCharCP()
    expected = True
    ref = DgnModelRef.CreateDgnAttachment (ret[0], DgnDocumentMoniker.Create(externalizedDocMoniker), 'Test', False)  
    actual = ref[1].Is3d()
    assert actual == expected


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetDgnCache_DgnCache(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    loadDgnFile.FillSectionsInModel (ret[0], DgnModelSections.eModel)
    expected = ret[0]
    modelId = ret[0].GetModelId()
    dgnModel = loadDgnFile.LoadRootModelById ( modelId, True, True)
    actual = dgnModel[0]
    assert actual == expected