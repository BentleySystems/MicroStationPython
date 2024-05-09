import os
import copy
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

DGNMODEL_STATUS_InvalidModelTypeSwitch = 69668
BentleyStatus.eERROR = 32768
BentleyStatus.eSUCCESS = 0

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetModelInfo_NoChanges(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo1 = ModelInfo.MakeCopy(model)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo1)

@pytest.mark.skip(reason="NEEDS WORK: Fix Me")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) #doubt
def test_SetModelInfo_AttemptToChangePropertiesOfReadOnlyModel(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    # model1=ModelInfo()
    model = DgnModel.GetModelInfo(ret[0])
    model1 = DgnModel.GetModelInfo(ret[0])
    newName = "NewName"
    #Backdoor is not defined


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetModelInfo_Undo(initDgnPlatformHost, loadDgnFile):
    ITxnManager.GetManager().Activate ()
    loadDgnFile.SetTransactable(True)
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    newName = "NewName"
    oldName = original.GetName()
    assert BentleyStatus.eSUCCESS == modelInfo.SetName(newName)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert model == modelInfo
    ITxnManager.GetManager().ReverseTxns (1, False)
    assert model == original
    assert oldName == DgnModel.GetModelInfo(ret[0]).GetName()
    ITxnManager.GetManager().ReinstateTxn ()
    assert newName == DgnModel.GetModelInfo(ret[0]).GetName()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetModelInfo_UndoShouldNotUndoSettingChanges(initDgnPlatformHost, loadDgnFile):
    ITxnManager.GetManager().Activate ()
    loadDgnFile.SetTransactable(True)
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    newName = "NewName"
    oldName = original.GetName()
    oldExtent = original.GetSolidExtent()
    newExtent = 234343.3

    assert BentleyStatus.eSUCCESS == modelInfo.SetName(newName)
    assert BentleyStatus.eSUCCESS == modelInfo.SetSolidExtent(newExtent)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    ITxnManager.GetManager().CloseCurrentTxn (True)
    assert model == modelInfo
    assert model.GetSolidExtent() == newExtent
    ITxnManager.GetManager().ReverseTxns (1, False)
    assert oldName == model.GetName()

    assert model.GetSolidExtent() == newExtent
    ITxnManager.GetManager().ReinstateTxn ()
    assert newName == DgnModel.GetModelInfo(ret[0]).GetName()
    assert model.GetSolidExtent() == newExtent


@pytest.mark.skip(reason="NEEDS WORK: Fix Me")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) #doubt
def test_SetModelInfo_AttemptToChangeSettingOfReadOnlyModel(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    newValue = 234343.3
    #BackDoor is not defined


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetModelInfo_FixAzimuth(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])

    assert -1000.0 != model.GetAzimuth ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetName_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    newName = "SomeNewModelName"
    
    assert BentleyStatus.eSUCCESS == modelInfo.SetName(newName)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newName == DgnModel.GetModelInfo(ret[0]).GetName()
    assert newName == DgnModel.GetModelName(ret[0])
    assert True != ModelInfo.__eq__(model,original)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetName_Invalid(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])

    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)

    assert 32768 == modelInfo.SetName(None)
    assert 32768 == modelInfo.SetName("     ")
    assert 32768 == modelInfo.SetName("Invalid:Name\"\t/")
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert model == original


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetAnnotationScaleFactor_NewValueValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    newValue = 0.234
    assert BentleyStatus.eSUCCESS == modelInfo.SetAnnotationScaleFactor(newValue)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newValue == model.GetAnnotationScaleFactor()
    

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetAnnotationScaleFactor_InvalidValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    newValue = -0.234
    assert BentleyStatus.eERROR == modelInfo.SetAnnotationScaleFactor(newValue)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert model == original


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetDefaultRefLogical_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    newDesc = "NewRefLogical"
    modelInfo.SetDefaultRefLogical(repr(newDesc))
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert repr(newDesc) == model.GetDefaultRefLogical()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetDefaultRefLogical_NULL(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    modelInfo.SetDefaultRefLogical("SomethingDifferent")
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    modelInfo.SetDefaultRefLogical(None)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert "" == model.GetDefaultRefLogical()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetDescription_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    newDesc = "NewDescription"
    assert BentleyStatus.eSUCCESS == modelInfo.SetDescription(repr(newDesc))
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert repr(newDesc) == model.GetDescription()
   

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetDescription_NULL(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    assert BentleyStatus.eSUCCESS == modelInfo.SetDescription(None)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert "" == model.GetDescription()
   

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetModelType_CannotChangeExistingModelToExtractionModel(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    type = DgnModelType.eExtraction_Deprecated

    assert BentleyStatus.eSUCCESS == modelInfo.SetModelType(type)
    assert BentleyStatus.eSUCCESS != DgnModel.SetModelInfo(ret[0],modelInfo)
    assert model == original

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetModelType_CannotChangeExistingExtractionModelsType(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("ExtractionModel", DgnModelType.eExtraction_Deprecated, True)
    info = ret[0].GetModelInfo().MakeCopy()
    info.SetModelType(DgnModelType.eNormal)

    assert BentleyStatus.eSUCCESS != ret[0].SetModelInfo(info)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetModelType_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    type = DgnModelType.eSheet

    assert BentleyStatus.eSUCCESS == modelInfo.SetModelType(type)
    assert DgnModelType.eDrawing != model.GetModelType()
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert DgnModelType.eSheet == model.GetModelType()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetModelType_CannotChangeTo_Extraction(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    assert BentleyStatus.eSUCCESS == modelInfo.SetModelType(DgnModelType.eExtraction_Deprecated)
    assert DGNMODEL_STATUS_InvalidModelTypeSwitch == DgnModel.SetModelInfo(ret[0],modelInfo)


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetModelType_InvalidDrawingOn3d(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    type = DgnModelType.eDrawing

    assert BentleyStatus.eSUCCESS == modelInfo.SetModelType(type)
    assert BentleyStatus.eSUCCESS != DgnModel.SetModelInfo(ret[0],modelInfo)
    assert model == original


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetStorageUnit_InvalidArgs(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    validStorageUnit = modelInfo.GetStorageUnit ()
    invalidStorageUnit = UnitDefinition (validStorageUnit.GetBase(), validStorageUnit.GetSystem(), -1, validStorageUnit.GetDenominator(), "NewStorageUnit")

    assert invalidStorageUnit != DgnModel.GetModelInfo(ret[0]).GetStorageUnit()
    
    VALID_UOR_PER_STORAGE = 1.0
    INVALID_UOR_PER_STORAGE = 0.0

    assert BentleyStatus.eERROR == modelInfo.SetStorageUnit (invalidStorageUnit, VALID_UOR_PER_STORAGE )
    assert BentleyStatus.eERROR == modelInfo.SetStorageUnit (validStorageUnit, INVALID_UOR_PER_STORAGE )

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0], modelInfo)

    assert DgnModel.GetModelInfo(ret[0]) == original



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetStorageUnit_NewUorPerStorage(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    originalStorageUnit = modelInfo.GetStorageUnit()
    newUorPerStorage = modelInfo.GetUorPerStorage () + 1.0
    type = DgnModelType.eDrawing

    assert BentleyStatus.eSUCCESS == modelInfo.SetStorageUnit(originalStorageUnit,newUorPerStorage )
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert originalStorageUnit == model.GetStorageUnit()
    assert newUorPerStorage == model.GetUorPerStorage()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetStorageUnit_NewStorageUnitWithDifferentBase(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    originalStorageUnit = modelInfo.GetStorageUnit()
    originalMasterUnit  = modelInfo.GetMasterUnit ()
    originalSubUnit     = modelInfo.GetSubUnit ()

    newStorageUnit = UnitDefinition (UnitBase.eDegree, UnitSystem.eMetric, 1.0, 1.0, "NewStorageUnit")
    originalUorPerStorage = modelInfo.GetUorPerStorage ()

    assert newStorageUnit != model.GetStorageUnit()
    assert BentleyStatus.eSUCCESS == modelInfo.SetStorageUnit (newStorageUnit, originalUorPerStorage )
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newStorageUnit == model.GetStorageUnit()
    assert newStorageUnit == model.GetMasterUnit()
    assert newStorageUnit == model.GetSubUnit()
    assert originalUorPerStorage == model.GetUorPerStorage()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetWorkingUnits_NullSubUnit(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    master = modelInfo.GetMasterUnit()
    master.SetLabel ("NewMasterLabel")

    assert master != model.GetMasterUnit()
    assert BentleyStatus.eSUCCESS == modelInfo.SetWorkingUnits(master,master)  #doubt
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert master == model.GetMasterUnit()
    assert master == model.GetSubUnit()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetWorkingUnits_OnlyMasterUnitNew(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    master = modelInfo.GetMasterUnit()
    sub = modelInfo.GetSubUnit()

    master.SetLabel ("NewMasterUnit")

    assert master != modelInfo.GetMasterUnit()
    assert sub == modelInfo.GetSubUnit()
    assert BentleyStatus.eSUCCESS == modelInfo.SetWorkingUnits(master,sub)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert master == model.GetMasterUnit()
    assert sub == model.GetSubUnit()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetWorkingUnits_OnlySubUnitNew(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    master = modelInfo.GetMasterUnit()
    sub = modelInfo.GetSubUnit()
    sub.SetLabel ("NewSubLabel")

    assert master == modelInfo.GetMasterUnit()
    assert sub != modelInfo.GetSubUnit()
    assert BentleyStatus.eSUCCESS == modelInfo.SetWorkingUnits(master,sub)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert master == model.GetMasterUnit()
    assert sub == model.GetSubUnit()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetWorkingUnits_BothMasterUnitAndSubUnitNew(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    master = modelInfo.GetMasterUnit()
    sub = modelInfo.GetSubUnit()
    master.SetLabel ("NewMasterLabel")
    sub.SetLabel ("NewSubLabel")

    assert master != modelInfo.GetMasterUnit()
    assert sub != modelInfo.GetSubUnit()
    assert BentleyStatus.eSUCCESS == modelInfo.SetWorkingUnits(master,sub)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert master == model.GetMasterUnit()
    assert sub == model.GetSubUnit()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetWorkingUnits_NeitherMasterUnitOrSubUnitNew(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    masterThatIsTheSame = modelInfo.GetMasterUnit()
    subThatIsTheSame = modelInfo.GetSubUnit()

    assert masterThatIsTheSame == modelInfo.GetMasterUnit()
    assert subThatIsTheSame == modelInfo.GetSubUnit()
    assert BentleyStatus.eSUCCESS == modelInfo.SetWorkingUnits(masterThatIsTheSame,subThatIsTheSame)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert masterThatIsTheSame == model.GetMasterUnit()
    assert subThatIsTheSame == model.GetSubUnit()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetGridParams_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    uorPerGrid = modelInfo.GetUorPerGrid () + 1.0
    gridPerRef = modelInfo.GetGridPerReference () + 1
    gridRatio = modelInfo.GetGridRatio () + 1.0
    gridBase = modelInfo.GetGridBase ()
    gridBase.x += 1.0
    gridAngle = modelInfo.GetGridAngle () + 1.0
    modelInfo.SetGridParams (uorPerGrid, gridPerRef, gridRatio, gridBase, gridAngle)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert uorPerGrid == model.GetUorPerGrid ()
    assert gridPerRef == model.GetGridPerReference ()
    assert gridRatio == model.GetGridRatio ()
    assert gridBase.x == model.GetGridBase ().x
    assert gridBase.y == model.GetGridBase ().y
    assert gridAngle == model.GetGridAngle ()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetGridParams_NULL(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    uorPerGrid = modelInfo.GetUorPerGrid () + 1.0
    gridPerRef = modelInfo.GetGridPerReference () + 1
    gridRatio = modelInfo.GetGridRatio () + 1.0
    gridBase = modelInfo.GetGridBase ()
    gridBase.x += 1.0
    gridAngle = modelInfo.GetGridAngle () + 1.0

    for i in range(0,6):   
        if(i==1): pPerGrid = uorPerGrid           
        elif(i==2): pPerRef  = gridPerRef
        elif(i==3): pRatio   = gridRatio
        elif(i==4): pBase    = gridBase
        elif(i==5): pAngle   = gridAngle        

    modelInfo.SetGridParams (pPerGrid, pPerRef, pRatio, pBase, pAngle)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert uorPerGrid == model.GetUorPerGrid ()
    assert gridPerRef == model.GetGridPerReference ()
    assert gridRatio == model.GetGridRatio ()
    assert gridBase.x == model.GetGridBase ().x
    assert gridBase.y == model.GetGridBase ().y
    assert gridAngle == model.GetGridAngle ()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetCellType_InvalidArg(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = ModelInfo.MakeCopy(model)
    
    cellType = modelInfo.GetCellType ()

    assert 32768 == modelInfo.SetCellType (CellLibraryType.eCBMenu)
    assert 32768 == modelInfo.SetCellType (CellLibraryType.eMatrixMenu)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert original == model

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetCellType_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)   
    cellType = modelInfo.GetCellType ()
    newVal = CellLibraryType.eGraphic

    if (CellLibraryType.eGraphic == cellType):
        newVal = CellLibraryType.ePoint

    assert BentleyStatus.eSUCCESS == modelInfo.SetCellType (newVal)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newVal == model.GetCellType ()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetRoundoffUnit_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)    
    unit =  modelInfo.GetRoundoffUnit ()
    ratio = modelInfo.GetRoundoffRatio ()
    unit += 1.0
    ratio += 1.0

    modelInfo.SetRoundoffUnit (unit, ratio)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert unit == model.GetRoundoffUnit()
    assert ratio == model.GetRoundoffRatio()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetRoundoffUnit_NewValue_Unit(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)   
    unit =  modelInfo.GetRoundoffUnit ()
    ratio = modelInfo.GetRoundoffRatio ()
    unit += 1.0
    modelInfo.SetRoundoffUnit (unit, ratio)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert unit == model.GetRoundoffUnit()
    assert ratio == model.GetRoundoffRatio()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetRoundoffUnit_NULL(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    modelInfo.SetRoundoffUnit (0.0, 0.0)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetLineStyleScaleMode_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    oldMode = modelInfo.GetLineStyleScaleMode()
    newMode = ModelInfo.eLSSCALEMODE_CompoundScale
    if (newMode == oldMode):
        newMode = ModelInfo.LSSCALEMODE_AnnotationScale

    modelInfo.SetLineStyleScaleMode (newMode)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newMode == model.GetLineStyleScaleMode()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetLineStyleScale_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    original = modelInfo.GetLineStyleScale ()
    newValue = 2.343

    if (newValue == original):
        newValue *= 2.0

    assert BentleyStatus.eSUCCESS == modelInfo.SetLineStyleScale (newValue)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newValue == model.GetLineStyleScale()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetLineStyleScale_InvalidValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    assert BentleyStatus.eSUCCESS == modelInfo.SetLineStyleScale (1.0)
    assert BentleyStatus.eERROR == modelInfo.SetLineStyleScale(0.0)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetLineStyleScale_InvalidValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    assert BentleyStatus.eSUCCESS == modelInfo.SetLineStyleScale (1.0)
    assert BentleyStatus.eERROR == modelInfo.SetLineStyleScale(0.0)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetSolidExtent_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    original = modelInfo.GetSolidExtent ()
    newValue = 2.343

    if (newValue == original):
        newValue *= 2.0

    assert BentleyStatus.eSUCCESS == modelInfo.SetSolidExtent (newValue)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)  
    assert newValue == model.GetSolidExtent()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetSolidExtent_InvalidValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    original = modelInfo.GetSolidExtent ()
    newValue = -1.0

    assert BentleyStatus.eERROR == modelInfo.SetSolidExtent (newValue)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)   
    assert original == model.GetSolidExtent()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetGlobalOrigin_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    newOrigin = copy.copy(modelInfo.GetGlobalOrigin())
    newOrigin.x += 1.0
    newOrigin.y += 1.0
    newOrigin.z += 1.0

    assert not newOrigin.IsEqual(modelInfo.GetGlobalOrigin ())
    modelInfo.SetGlobalOrigin (newOrigin)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newOrigin.IsEqual(model.GetGlobalOrigin())

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetAzimuth_Invalid(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    originalAzimuth = modelInfo.GetAzimuth ()
    invalidAzimuth = -181.0
    
    assert BentleyStatus.eERROR == modelInfo.SetAzimuth (invalidAzimuth)
    invalidAzimuth = 181.0

    assert BentleyStatus.eERROR == modelInfo.SetAzimuth (invalidAzimuth)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)

    assert originalAzimuth == model.GetAzimuth()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetAzimuth_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    
    originalAzimuth = modelInfo.GetAzimuth ()
    newAzimuth = 60.0
    if (originalAzimuth == newAzimuth):
        newAzimuth *= -1.0

    assert BentleyStatus.eSUCCESS == modelInfo.SetAzimuth (newAzimuth)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)

    assert newAzimuth == model.GetAzimuth()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetPropertiesIsoPlane(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    assert IsoPlaneValues.eIsoPlaneAll != modelInfo.GetIsoPlane()
    modelInfo.SetIsoPlane(IsoPlaneValues.eIsoPlaneAll)

    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0], modelInfo)

    assert IsoPlaneValues.eIsoPlaneAll == DgnModel.GetModelInfo(ret[0]).GetIsoPlane()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_SetDirectionClockwise_NewValue(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)

    original = modelInfo.GetDirectionClockwise ()
    newValue = original

    modelInfo.SetDirectionClockwise (newValue)
    assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)
    assert newValue == model.GetDirectionClockwise()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetLinearPrecision_NewValue(initDgnPlatformHost, loadDgnFile):
    
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    arr= [PrecisionFormat.eDecimalWhole,PrecisionFormat.eDecimalWhole,PrecisionFormat.eDecimal2Places,PrecisionFormat.eDecimal8Places,PrecisionFormat.eFractional1_Over_256,PrecisionFormat.eFractional1_Over_32 , PrecisionFormat.eFractionalWhole,PrecisionFormat.eScientificWhole,PrecisionFormat.eScientific8Places,PrecisionFormat.eScientific6Places,PrecisionFormat.eDecimal4Places]
    for i in arr:
        modelInfo.SetLinearPrecision (i)
        assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)

        assert i == model.GetLinearPrecision()
    

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetLinearPrecision_NewValue(initDgnPlatformHost, loadDgnFile):
    
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    arr= [PrecisionFormat.eDecimalWhole,PrecisionFormat.eDecimalWhole,PrecisionFormat.eDecimal2Places,PrecisionFormat.eDecimal8Places,PrecisionFormat.eFractional1_Over_256,PrecisionFormat.eFractional1_Over_32 , PrecisionFormat.eFractionalWhole,PrecisionFormat.eScientificWhole,PrecisionFormat.eScientific8Places,PrecisionFormat.eScientific6Places,PrecisionFormat.eDecimal4Places]
    for i in arr:
        modelInfo.SetLinearPrecision (i)
        assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)

        assert i == model.GetLinearPrecision()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) 
def test_SetBaseDirection_NewValue(initDgnPlatformHost, loadDgnFile):
    
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    arr= [45.0,0.0,700.0]
    for i in arr:
        modelInfo.SetDirectionBaseDir (i)
        assert BentleyStatus.eSUCCESS == DgnModel.SetModelInfo(ret[0],modelInfo)

        assert i == model.GetDirectionBaseDir()

@pytest.mark.skip(reason="NEEDS WORK: Fix Me")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn']) #BackDoor is not defined
def test_SetPropertiesAll(initDgnPlatformHost, loadDgnFile):
    
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    model = DgnModel.GetModelInfo(ret[0])
    modelInfo = ModelInfo.MakeCopy(model)
    listener = BackDoor.CreateModelInfoListener()