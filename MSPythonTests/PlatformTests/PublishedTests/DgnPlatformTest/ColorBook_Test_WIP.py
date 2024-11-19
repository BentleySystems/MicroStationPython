import copy
import numpy as np
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from ColorBookUtils import *

m_eeh = EditElementHandle()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_GetEntryCount(initDgnPlatformHost, loadDgnFile):
    expected = 4
    m_colors = {}
    AddEntry(m_colors, "a", 5, 8, 9)
    AddEntry(m_colors, "b", 5, 9, 9)
    AddEntry(m_colors, "c", 5, 12, 9)
    AddEntry(m_colors, "d", 5, 6, 9)

    actual= GetEntryCount(m_colors)
    assert actual == expected

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_GetEntry(initDgnPlatformHost, loadDgnFile):
    expectedDef = RgbColorDef()
    expectedDef.red = 5
    expectedDef.green = 12
    expectedDef.blue = 9

    m_colors = {}
    AddEntry(m_colors, "a", 5, 8, 9)
    AddEntry(m_colors, "b", 5, 9, 9)
    AddEntry(m_colors, "c", 5, 12, 9)
    AddEntry(m_colors, "d", 5, 6, 9)

    index = 2
    exp = "c"
    colorData = {"name": "", "color": RgbColorDef()}
    assert BentleyStatus.eSUCCESS == GetEntry(m_colors, index, colorData)

    if exp != colorData["name"]:
        return BentleyStatus.eERROR
    
    assert expectedDef.red == colorData["color"].red
    assert expectedDef.green == colorData["color"].green
    assert expectedDef.blue == colorData["color"].blue

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_GetEntry_InValidIndex(initDgnPlatformHost, loadDgnFile):
    m_colors = {}
    AddEntry(m_colors, "a", 5, 8, 9)
    AddEntry(m_colors, "b", 5, 9, 9)
    AddEntry(m_colors, "c", 5, 12, 9)
    AddEntry(m_colors, "d", 5, 6, 9)

    index = 6
    colorData = {"name": None, "color": RgbColorDef()}
    assert BentleyStatus.eERROR == GetEntry(m_colors, index, colorData)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_FindColorByName(initDgnPlatformHost, loadDgnFile):
    expectedDef = RgbColorDef()
    expectedDef.red = 5
    expectedDef.green = 12
    expectedDef.blue = 9

    m_colors = {}
    AddEntry(m_colors, "a", 5, 8, 9)
    AddEntry(m_colors, "b", 5, 9, 9)
    AddEntry(m_colors, "c", 5, 12, 9)
    AddEntry(m_colors, "d", 5, 6, 9)

    color = [RgbColorDef()]
    FindColorByName(m_colors, color, "c")

    assert expectedDef.red == color[0].red
    assert expectedDef.green == color[0].green
    assert expectedDef.blue == color[0].blue

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindColorByName_InValidName(initDgnPlatformHost, loadDgnFile):
    m_colors = {}
    AddEntry(m_colors, "a", 5, 8, 9)
    AddEntry(m_colors, "b", 5, 9, 9)
    AddEntry(m_colors, "c", 5, 12, 9)
    AddEntry(m_colors, "d", 5, 6, 9)

    color = [RgbColorDef()]
    assert BentleyStatus.eERROR == FindColorByName(m_colors, color, "s")

@pytest.mark.skip(reason = "Too many inbuild functions are not exposed")
def test_LoadFromDgn(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # actual = RgbColorDef()
    # act = ""
    exp = "a"
    index = 0
    expectedDef = RgbColorDef()
    expectedDef.red = 5
    expectedDef.green = 12
    expectedDef.blue = 9
    m_colors = {}
    AddEntry(m_colors, "a", 5, 8, 9)
    dgnFile = ret[0].GetDgnFile()
    assert BentleyStatus.eSUCCESS == SaveToDgn(dgnFile, "a", ret, loadDgnFile)
    assert BentleyStatus.eSUCCESS == SaveAndCopyFile(WString("colorbook.dgn"))

    referenceTdm = TestDgnManager()
    model = referenceTdm.GetAndFillDgnModel()
    m_ent = None
    def2 = model.GetDgnFile()
    assert BentleyStatus.eSUCCESS == ColorBook.LoadFromDgn(m_ent, "a", def2, False, GetDgnPlatformHost())

    colorData = {"name": "", "color": RgbColorDef()}
    assert BentleyStatus.eSUCCESS == GetEntry(m_colors, index, colorData)

    if exp != colorData["name"]:
        return BentleyStatus.eERROR
    
    assert expectedDef.red == colorData["color"].red
    assert expectedDef.green == colorData["color"].green
    assert expectedDef.blue == colorData["color"].blue

@pytest.mark.skip(reason = "Too many inbuild functions are not exposed for SaveDgn method.")
def test_LoadFromDgn_CRASH(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    m_ent.AddEntry("a", 5, 8, 9)
    dgnFile = ret[0].GetDgnFile()
    assert BentleyStatus.eSUCCESS == SaveToDgn(dgnFile, "a", ret, loadDgnFile)

    m_ent = None
    dgnFile2 = ret[0].GetDgnFile()
    assert BentleyStatus.eSUCCESS == ColorBook.LoadFromDgn(m_ent, "a", def2, false, BackDoor.GetDgnPlatformHost())

# There are some more tests that are not covered in this test as there are methodes that are not exposed yet.
# Tests not covered are:
# 1. LoadFromDgn_DgnLibsEmpty
# 2. LoadFromDgn_DgnLibs