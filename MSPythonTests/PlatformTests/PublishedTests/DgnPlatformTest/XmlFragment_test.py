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

APPID_GasCompany = 2000
APPTYPE_FeatureData = 10
APPTYPE_StateData = 11
APPTYPE_ProjectData = 12

featureDataSchema = (WString)("www.bentley.com/piping")
featureData = (WString)("<FeatureData Name=\"Pipe\"></FeatureData>")

stateDataSchema = (WString)("www.bentley.com/state")
stateData = (WString)("<StateData><State>Existing</State></StateData>")

projectDataSchema = (WString)("www.bentley.com/project-data")
projectData = (WString)("<Project><Title>East Side Shopping Center</Title><ID>P_0001></ID><Bid_Date>01/01/2009</Bid_Date></Project>")

def AddElementToModel(eeh, model):
  
    numberBeforeAdded = model.GetElementCount(DgnModelSections.eAll)

    id = eeh.GetElementId()

    if 0 != id:
        return BSIERROR
    
    result = eeh.AddToModel()
    if(BentleyStatus.eSUCCESS != result):
        return result
    
    id = eeh.GetElementId()
    if 0 == id:
        return BSIERROR
    
    numberAfterAdded = model.GetElementCount(DgnModelSections.eAll)
    if numberAfterAdded <= numberBeforeAdded:
        return BSIERROR

    return BentleyStatus.eSUCCESS

def test_MiscTest():
    compressedFragment = XmlFragment(0, 0)
    compressedFragment.SetAppID(APPID_GasCompany)
    compressedFragment.SetAppType(APPTYPE_ProjectData)
    compressedFragment.SetIsCompressed (True)
    compressedFragment.SetSchemaURN(projectDataSchema)
    compressedFragment.SetText(projectData)

    assert APPID_GasCompany == compressedFragment.GetAppID ()
    assert APPTYPE_ProjectData == compressedFragment.GetAppType ()
    assert compressedFragment.GetSchemaURN() == projectDataSchema
    assert compressedFragment.GetText() == projectData

    ulBufferSize = compressedFragment.GetStreamData()
    assert 166 == ulBufferSize[2]

    uncompressedFragment = XmlFragment(0, 0)
    uncompressedFragment.SetAppID (APPID_GasCompany)
    uncompressedFragment.SetAppType (APPTYPE_ProjectData)
    uncompressedFragment.SetSchemaURN (projectDataSchema)
    uncompressedFragment.SetText (projectData)

    assert APPID_GasCompany, uncompressedFragment.GetAppID()
    assert APPTYPE_ProjectData, uncompressedFragment.GetAppType()
    assert uncompressedFragment.GetSchemaURN() == projectDataSchema
    assert uncompressedFragment.GetText() == projectData

    ulBufferSize = uncompressedFragment.GetStreamData()
    assert 292 == ulBufferSize[2]

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateSingleLinkage(initDgnPlatformHost, loadDgnFile):
    modelId = loadDgnFile.GetDefaultModelId()
    ret = loadDgnFile.LoadRootModelById(modelId)
    cache = loadDgnFile.FillSectionsInModel(ret[0])   
    eeh = EditElementHandle()
    segment = DSegment3d(0,0,0,0,100,0)
    assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement(eeh, None, segment, False, ret[0])
    pXmlFragment = XmlFragment(APPID_GasCompany, APPTYPE_FeatureData, False, featureDataSchema, featureData)
    assert BentleyStatus.eSUCCESS == pXmlFragment.AttachToElement(eeh)
    assert BentleyStatus.eSUCCESS == AddElementToModel(eeh, ret[0])
    linkageFragments = XmlFragmentList.ExtractFromElement(eeh, APPID_GasCompany, APPTYPE_FeatureData)
    if linkageFragments != None:
        assert 1 == linkageFragments.GetCount()
        if 1 == linkageFragments.GetCount():
            fragment = linkageFragments.GetFragmentAtIndex(0)
            assert None != fragment
            assert APPTYPE_FeatureData == fragment.GetAppType()
    
#-------------------------------------------------------------------
#   This test doens't work due to issues with ExtractFromElement
#-------------------------------------------------------------------
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateMultipleLinkages(initDgnPlatformHost, loadDgnFile):
    modelId = loadDgnFile.GetDefaultModelId()
    ret = loadDgnFile.LoadRootModelById(modelId)
    cache = loadDgnFile.FillSectionsInModel(ret[0])
    eeh = EditElementHandle()
    
    segment = DSegment3d(100,0,0,100,100,0)

    assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement(eeh, None, segment, False, ret[0])

    pXmlFragment = XmlFragment(APPID_GasCompany, APPTYPE_StateData, True, stateDataSchema, stateData)
    assert pXmlFragment != None

    pXmlFragmentList = XmlFragmentList(pXmlFragment)

    pXmlFragment = XmlFragment(APPID_GasCompany, APPTYPE_FeatureData, False, featureDataSchema, featureData)

    pXmlFragmentList.Prepend(pXmlFragment)

    assert BentleyStatus.eSUCCESS == pXmlFragmentList.AttachToElement(eeh)

    assert BentleyStatus.eSUCCESS == AddElementToModel(eeh, ret[0])
    for v in pXmlFragmentList:
        print(type(v))
    
    print("-----------------------")

    linkageFragments = XmlFragmentList.ExtractFromElement(eeh)

    for v in linkageFragments:
        print(type(v))
    
    print("-----------------------")
    assert None != linkageFragments
    if None != linkageFragments:
        assert 2 == linkageFragments.GetCount()
        if 2 == linkageFragments.GetCount():
            fragment1 = linkageFragments.GetFragmentAtIndex (0)
            assert None != fragment1
            assert APPTYPE_FeatureData == fragment1.GetAppType()
            assert fragment1.GetSchemaURN() == featureDataSchema
            assert fragment1.GetText() == featureData
            
            fragment2 = linkageFragments.GetFragmentAtIndex (1)
            assert None != fragment2
            assert APPTYPE_StateData == fragment2.GetAppType()
            assert fragment2.GetSchemaURN() == stateDataSchema
            assert fragment2.GetText() == stateData
    
    appID = APPID_GasCompany
    appType = APPTYPE_FeatureData

    XmlFragment.StripFromElementByAppIDAndType (eeh, appID, appType)
    reducedlinkageFragments = XmlFragmentList.ExtractFromElement (eeh)
    assert None != reducedlinkageFragments
    if None != reducedlinkageFragments:
        assert 1 == reducedlinkageFragments.GetCount()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Create(initDgnPlatformHost, loadDgnFile):
    modelId = loadDgnFile.GetDefaultModelId()
    ret = loadDgnFile.LoadRootModelById(modelId)
    cache = loadDgnFile.FillSectionsInModel(ret[0])
    eeh = EditElementHandle()
    pXmlFragment = XmlFragment(APPID_GasCompany, APPTYPE_ProjectData, False, projectDataSchema, projectData)
    assert pXmlFragment != None
    assert BentleyStatus.eSUCCESS == pXmlFragment.CreateXmlElement(eeh, loadDgnFile.GetDictionaryModel(), True)
    assert BentleyStatus.eSUCCESS == AddElementToModel(eeh, ret[0])
    readFragment = XmlFragment(eeh)
    assert None != readFragment
    assert APPTYPE_ProjectData == readFragment.GetAppType ()
    assert readFragment.GetSchemaURN() == projectDataSchema
    assert readFragment.GetText() == projectData
