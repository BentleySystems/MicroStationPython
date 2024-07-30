#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import sys
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
import shutil
import tempfile

MAX_MODEL_NAME_LENGTH = 512
INVALID_MODELID = -2

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_createModel (initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    if (ret[1] != DgnModelStatus.eDGNMODEL_STATUS_Success):
        assert False
    model = ret[0]
    assert ret[0] != None
    assert model.GetDgnFile() == loadDgnFile
    assert model.GetModelName() == "Test"

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_LoadDgnFileWriteAccess(initDgnPlatformHost, loadDgnFile):
    assert loadDgnFile.IsOpen() == True
    assert loadDgnFile.IsLoaded() == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_LoadDgnFileReadOnly(initDgnPlatformHost, loadDgnFileReadOnly):
    assert loadDgnFileReadOnly.IsOpen() == False
    assert loadDgnFileReadOnly.IsLoaded() == True

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FillDictionaryModel(initDgnPlatformHost, loadDgnFile):

    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    name= "Model-1"

    assert ret != None
    assert loadDgnFile.FillDictionaryModel() == BentleyStatus.eSUCCESS

    temp_dir = tempfile.TemporaryDirectory()

    fileName = loadDgnFile.GetFileName()
    original = r'%s' %fileName

    target =  temp_dir.name+'/DgnFile_GetLoadedModelsCollectionTest1.dgn'

    shutil.copyfile(original, target)
    
    ret1 = DgnDocument.CreateFromFileName (target, None, -101, DgnDocument.FetchMode.eWrite)
    if (ret1[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False
    dgnFile = DgnFile (ret1[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()

    assert dgnFile.FillDictionaryModel() == BentleyStatus.eSUCCESS

    dgnFile = None
    temp_dir.cleanup()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FillSectionsInModel(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    #Creates a model named "Model-1"
    name = "Model-1"
    ret = srcDgnFile.CreateNewModel ( 'Model-1', DgnModelType.eNormal, True)

    #when newly created, models are supposed to be "full"
    assert BentleyStatus.eSUCCESS == srcDgnFile.FillSectionsInModel(ret[0])

    #creates a cone
    eeh = EditElementHandle()
    rMatrix = RotMatrix()
    rMatrix.InitIdentity ()

    top = DPoint3d(0,10,0)
    bottom = DPoint3d(0,0,0)

    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(eeh, None, 2, 1, top, bottom, rMatrix, True, ret[0])

    #checking to see if the method still works correctly when elements are present
    assert BentleyStatus.eSUCCESS == srcDgnFile.FillSectionsInModel(ret[0])

    eeh.DeleteFromModel()

    #should still work on a model without elements that was not just created
    assert BentleyStatus.eSUCCESS == srcDgnFile.FillSectionsInModel(ret[0])

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) # Problem in GetLoadedModelsCollection
def test_GetLoadedModelsCollection(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name= "Model-1"
    model1 = srcDgnFile.CreateNewModel (name, DgnModelType.eNormal, False)
    assert None != model1[0] 

    name2= "Model-2"
    model2 = srcDgnFile.CreateNewModel (name2, DgnModelType.eNormal, False)
    assert None != model2[0]

    name3= "Model-3"
    model3 = srcDgnFile.CreateNewModel (name3, DgnModelType.eNormal, False)
    assert None != model3[0]

    loaded = 0; #counter to track the number of loaded models in the file
    modelCol = srcDgnFile.GetLoadedModelsCollection()
 
    for cache in srcDgnFile.GetLoadedModelsCollection():
         loaded += 1

    #should be 4 because there is a default model as well as the created caches
    assert 4 == loaded

    fileTarget = os.environ['MSPYTEMPDATA'] + os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    BeFileName.BeDeleteFile (fileTarget)
    srcDgnFile.DoSaveTo(fileTarget)

    #Create a new DgnFile instance
    doc = DgnDocument.CreateForLocalFile(fileTarget)
    assert doc != None
    targetDgnFile = DgnFile(doc, DgnFileOpenMode.eReadWrite)
    targetDgnFile.LoadDgnFile ()

    loaded = 0; #resets loaded for another test

    #no models should be loaded since we have just opened the file and have not accessed any of them
    for cache in targetDgnFile.GetLoadedModelsCollection():
         loaded += 1

    assert 0 == loaded

    #locates this files copy of cache1; finding it loads it
    mid1 = targetDgnFile.FindModelIdByName(name)
    found1 = targetDgnFile.LoadRootModelById (mid1)
    assert None != found1[0]

    #tests to make sure only one cache has been loaded
    for cache in targetDgnFile.GetLoadedModelsCollection():
         loaded += 1

    assert 1 == loaded

    loaded = 0 #resets loaded

    #loads the other two caches by finding them
    mid2 = targetDgnFile.FindModelIdByName(name2)
    found2 = targetDgnFile.LoadRootModelById (mid2)
    assert None != found2[0]

    mid3 = targetDgnFile.FindModelIdByName(name3)
    found3 = targetDgnFile.LoadRootModelById (mid3)
    assert None != found3[0]

    #now we should have three loaded caches
    for cache in targetDgnFile.GetLoadedModelsCollection():
         loaded += 1

    assert 3 == loaded #I have not loaded the default model in this file, so should be 3

 
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DeleteModel(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile) 
    name= "Test Model"
    model1 = srcDgnFile.CreateNewModel (name, DgnModelType.eNormal, False)
    assert None != model1
    srcDgnFile.DeleteModel(model1[0])
    assert srcDgnFile.FindModelIdByName(name) == INVALID_MODELID


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CannotDeleteDefaultModel(initDgnPlatformHost, loadDgnFile): 
    defaultModel = loadDgnFile.LoadRootModelById(loadDgnFile.GetDefaultModelId())  

    assert 0!= loadDgnFile.DeleteModel(defaultModel[0])

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateNewRootModel(initDgnPlatformHost, loadDgnFile): 
    name= "Test Model"
    model1 = loadDgnFile.CreateNewModel (name, DgnModelType.eNormal, False)
    assert None != model1

    mid = loadDgnFile.FindModelIdByName(name)
    assert loadDgnFile.LoadRootModelById(mid,True) == model1

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) #BackDoor is not defined
def test_CreateNewDrawingModel(initDgnPlatformHost, loadDgnFile): 
    name= "New Drawing Model"
    model1 = loadDgnFile.CreateNewModel (name, DgnModelType.eDrawing, False)
    assert None != model1
    #assert loadDgnFile.GetModelType (model1[0]) == DgnModelType.eDrawing

    mid = loadDgnFile.FindModelIdByName(name)
    assert loadDgnFile.LoadRootModelById(mid,True) == model1


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindModelIdByName(initDgnPlatformHost, loadDgnFile): 
    name= "New Model"
    model1 = loadDgnFile.CreateNewModel (name, DgnModelType.eNormal, False)
    assert None != model1

    nonexistant = "I don't exist"
    
    assert INVALID_MODELID != loadDgnFile.FindModelIdByName(name)
    assert INVALID_MODELID == loadDgnFile.FindModelIdByName(nonexistant)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_LoadModelById(initDgnPlatformHost, loadDgnFile): 
    name= "New Model 1"
    model1 = loadDgnFile.CreateNewModel (name, DgnModelType.eNormal, False)
    assert None != model1
    mid = loadDgnFile.FindModelIdByName(name)

    assert loadDgnFile.LoadRootModelById(mid) == model1

@pytest.mark.skip(reason = "PlatformTest Fail. Writing into the source tree")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DoSaveAs(removeTempCreatedFile, initDgnPlatformHost, loadDgnFile): 
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")       
    filenamesave = WString((str(emptyDir))+"DgnFile_DoSaveAsTest.dgn")
    BeFileName.BeDeleteFile (repr(filenamesave))
    doc = DgnDocument.CreateForLocalFile(repr(filenamesave))
    assert doc != None
    loadDgnFile.DoSaveAs(doc)

    assert repr(filenamesave) == repr(loadDgnFile.GetFileName())

    removeTempCreatedFile('test_DoSaveAs', filenamesave)

@pytest.mark.skip(reason = "PlatformTest Fail. Writing into the source tree")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DoSaveTo(removeTempCreatedFile, initDgnPlatformHost, loadDgnFile): 
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")   
    filenamesave = WString(str(emptyDir)+"DgnFile_DoSaveToTest.dgn")
    loadDgnFile.DoSaveTo(repr(filenamesave))

    assert repr(filenamesave) != repr(loadDgnFile.GetFileName())
    dataDir = os.environ['MSPYTESTDATA']
    ret = DgnDocument.CreateFromFileName ("DgnFile_DoSaveToTest.dgn", dataDir, -101, DgnDocument.FetchMode.eWrite)
    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False
    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()

    assert loadDgnFile != dgnFile

    removeTempCreatedFile('test_DoSaveTo', filenamesave)


@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn'])
def test_IsReadOnlyReadWrite(initDgnPlatformHost,loadDgnFile):
    if(loadDgnFile == None):
        assert False
        
    assert False == loadDgnFile.IsReadOnly()


@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn'])
def test_IsReadOnlyReadOnly(initDgnPlatformHost,loadDgnFileReadOnly):
    if(loadDgnFileReadOnly == None):
        assert False
        
    assert True == loadDgnFileReadOnly.IsReadOnly()

@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn'])
def test_CannotCreateNewModelWithBadName(initDgnPlatformHost,loadDgnFile):
    assert True == (None == loadDgnFile.CreateNewModel("",DgnModelType.eNormal,True)[0])
    assert True == (None == loadDgnFile.CreateNewModel("???",DgnModelType.eNormal,True)[0])
    
    tooLong = "x" * ( MAX_MODEL_NAME_LENGTH + 2 )

    assert True == ( len(tooLong) > MAX_MODEL_NAME_LENGTH )
    assert True == (None == loadDgnFile.CreateNewModel(tooLong,DgnModelType.eNormal,True)[0])
    assert True != (None == loadDgnFile.CreateNewModel("NormalName",DgnModelType.eNormal,True)[0])
    assert True != (None == loadDgnFile.CreateNewModel("Normal Name With Spaces",DgnModelType.eNormal,True)[0])

@pytest.mark.skip(reason = "PlatformTest Fail. Writing into the source tree")
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn'])
def test_LoadFileTwice(initDgnPlatformHost,loadDgnFile):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    BeFileName.BeDeleteFile (fileSrc)
    loadDgnFile.DoSaveTo(fileSrc)

    doc = DgnDocument.CreateForLocalFile(fileSrc)
    assert doc != None

    srcDgnFile =  DgnFile(doc, DgnFileOpenMode.eReadOnly)
    assert DgnFileStatus.eDGNFILE_STATUS_Success == srcDgnFile.LoadDgnFile()[0]
    assert DgnFileStatus.eDGNFILE_STATUS_Success == srcDgnFile.LoadDgnFile()[0]
    assert DgnFileStatus.eDGNFILE_STATUS_Success == srcDgnFile.LoadDgnFile()[0]

@pytest.mark.parametrize('fileName',['3dMetricGeneral.dgn'])
def test_SetModelBackgroundColor_Design(initDgnPlatformHost,loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    original = RgbColorDef()
    srcDgnFile.GetModelBackgroundColor(original, DgnModelType.eNormal)

    colorMap = DgnColorMap.GetForFile (srcDgnFile)
    def0 = IntColorDef()
    def0.m_int = colorMap.GetTbgrColors ()[DgnColorMap.eINDEX_Background]

    assert original.red == def0.m_rgb.red and original.blue == def0.m_rgb.blue and original.green == def0.m_rgb.green
    print(original.red, original.blue, original.green)

    newColor = RgbColorDef()
    newColor.red   = 80
    newColor.blue  = 75
    newColor.green = 120

    srcDgnFile.SetModelBackgroundColor (newColor, DgnModelType.eNormal)
    colorMap = DgnColorMap.GetForFile (srcDgnFile)
    def0.m_int = colorMap.GetTbgrColors ()[DgnColorMap.eINDEX_Background]

    assert newColor.red == def0.m_rgb.red and newColor.blue == def0.m_rgb.blue and newColor.green == def0.m_rgb.green
    print(newColor.red, newColor.blue, newColor.green)
 
    
