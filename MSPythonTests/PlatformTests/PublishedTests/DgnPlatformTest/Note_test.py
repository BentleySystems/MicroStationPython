import os
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

noteStyleName = "NoteStyle"

def Setup(File):
    dimStyle = DimensionStyle(noteStyleName, File)
    dimStyle.Add()

    textstyle = DgnTextStyle(noteStyleName, File)
    textstyle.Add()

def GetText(text, File, model):
    textStyle = DgnTextStyle.GetByName(noteStyleName, File)
    textBlock = TextBlock(textStyle, model)
    textBlock.AppendText(text)
    return textBlock

def CreateNote(leader, noteElem, File, model): 
    dimStyle = DimensionStyle.GetByName(noteStyleName, File)
    text = GetText("69", File, model)

    points= DPoint3dArray()
    points.append(DPoint3d(10000, 0, 0))
    points.append(DPoint3d(50000, 0, 0))
    return NoteCellHeaderHandler.CreateNote(noteElem, leader, text, dimStyle, False, model, points)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateNote(removeTempCreatedFile, initDgnPlatformHost, loadDgnFile):
    filenamesave = str(os.environ['MSPYTESTDATA']+"DgnFile_DoSaveToTest.dgn")
    loadDgnFile.DoSaveAs(DgnDocument.CreateForLocalFile(filenamesave))
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    Setup(loadDgnFile)
    noteElem = EditElementHandle()
    leader = EditElementHandle()
    status = CreateNote(leader, noteElem, loadDgnFile, ret[0])
    assert 0 == status

    status = NoteCellHeaderHandler.AddToModel(noteElem, leader, ret[0])
    assert 0 == status
    status = loadDgnFile.ProcessChanges(DgnSaveReason.eFileClose)
    assert 0 == status
    removeTempCreatedFile('test_DoSaveTo', filenamesave)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ApplyDimensionStyle(removeTempCreatedFile, initDgnPlatformHost, loadDgnFile):
    filenamesave = str(os.environ['MSPYTESTDATA']+"DgnFile_DoSaveToTest.dgn")
    loadDgnFile.DoSaveAs(DgnDocument.CreateForLocalFile(filenamesave))
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    Setup(loadDgnFile)
    noteElem = EditElementHandle()
    leader = EditElementHandle()

    status = CreateNote(leader, noteElem, loadDgnFile, ret[0])
    assert BentleyStatus.eSUCCESS == status

    status = NoteCellHeaderHandler.AddToModel(noteElem, leader, ret[0])
    assert BentleyStatus.eSUCCESS == status

    elemRef = noteElem.GetElementRef()
    leaderRef = leader.GetElementRef()

    hdlr = NoteCellHeaderHandler.GetInstance()

    dimStyle = hdlr.GetNoteDimensionStyle(noteElem)
    assert None != dimStyle

    assert BentleyStatus.eSUCCESS == dimStyle.SetIntegerProp(eDIMSTYLE_VALUE_MLNote_FrameType_Hexagon, eDIMSTYLE_PROP_MLNote_FrameType_INTEGER)
    assert BentleyStatus.eSUCCESS == hdlr.SetNoteDimensionStyle(noteElem, leader, dimStyle)
    assert BentleyStatus.eSUCCESS == noteElem.ReplaceInModel(elemRef)
    assert BentleyStatus.eSUCCESS == leader.ReplaceInModel(leaderRef)

    loadDgnFile.ProcessChanges(DgnSaveReason.eApplInitiated)
    removeTempCreatedFile('test_DoSaveTo', filenamesave)