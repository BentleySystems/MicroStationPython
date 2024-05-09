import os
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *


def AddStyleToFile (name, loadDgnFile, style1=None):
    style = None
    if(style1 == None):
        style = DgnTextStyle(name, loadDgnFile)
    if (style == None):
        return BentleyStatus.eERROR
    return style.Add()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateStyle(initDgnPlatformHost, loadDgnFile):
    name = "49"
    style1 =  DgnTextStyle(name, loadDgnFile)
    style2 =  DimensionStyle(name, loadDgnFile)
    style3 =  DgnTextSnippet.Create(name, loadDgnFile)
    assert style1 != None
    assert style2 != None
    assert style3 != None

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AddToSameFile(initDgnPlatformHost, loadDgnFile):
    name = "59"
    style1 =  DgnTextStyle(name, loadDgnFile)
    style2 =  DimensionStyle(name, loadDgnFile)
    style3 =  DgnTextSnippet.Create(name, loadDgnFile)
    assert style1 != None
    assert style2 != None
    assert style3 != None
    status1 = style1.Add ()
    status2 = style2.Add ()
    status3 = style3.Add ()
    assert status1 == BentleyStatus.eSUCCESS
    assert status2 == BentleyStatus.eSUCCESS
    assert status3 == BentleyStatus.eSUCCESS
    AddStyleToFile (name, loadDgnFile)
    fileStyle1 = DgnTextStyle.GetByName (name, loadDgnFile)
    fileStyle2 = DimensionStyle.GetByName (name, loadDgnFile)
    fileStyle3 = DgnTextSnippet.GetByName (name, loadDgnFile)
    assert fileStyle1 != None
    assert fileStyle2 != None
    assert fileStyle3 != None
    status1 = AddStyleToFile (name, loadDgnFile, style1)
    assert status1 != BentleyStatus.eSUCCESS
    newName = "74"
    style1.SetName (newName)
    status1 = style1.Add ()
    assert status1 == BentleyStatus.eSUCCESS



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Delete(initDgnPlatformHost, loadDgnFile):
    name = "85"
    AddStyleToFile (name, loadDgnFile)
    status1 = DgnTextStyle.Delete (name, loadDgnFile)
    assert status1 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, loadDgnFile)
    fileStyle2 = DimensionStyle.GetByName (name, loadDgnFile)
    fileStyle3 = DgnTextSnippet.GetByName (name, loadDgnFile)
    assert fileStyle1 == None
    assert fileStyle2 == None
    assert fileStyle3 == None

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Replace(initDgnPlatformHost, loadDgnFile):
    name = "100"
    status0 = AddStyleToFile (name, loadDgnFile)
    assert status0 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, loadDgnFile)
    assert fileStyle1 != None
    status1 = fileStyle1.Replace()
    assert status1 == BentleyStatus.eSUCCESS
    newName = "109"
    fileStyle1.SetName (newName)
    status1 = fileStyle1.Replace()              #Actually do nothing here
    assert status1 == BentleyStatus.eERROR      #ERROR expected
    newfileStyle1 = DgnTextStyle.GetByName (newName, loadDgnFile)
    assert newfileStyle1 == None
    status1 = fileStyle1.Replace(name)          #Passing old name will do the real replacment
    assert status1 == BentleyStatus.eSUCCESS
    newfileStyle1 = DgnTextStyle.GetByName (newName, loadDgnFile)
    assert newfileStyle1 != None


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetById(initDgnPlatformHost, loadDgnFile):
    name = "129"
    status1 =  AddStyleToFile (name, loadDgnFile)
    assert status1 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, loadDgnFile)
    assert fileStyle1 != None
    idStyle = DgnTextStyle.GetByID (fileStyle1.GetID(), loadDgnFile)
    assert idStyle != None
    assert name == repr(idStyle.GetName())


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Copy(initDgnPlatformHost, loadDgnFile):
    name = "147"
    status1 =  AddStyleToFile (name, loadDgnFile)
    assert status1 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, loadDgnFile)
    assert fileStyle1 != None
    newName = "154"
    newStyle1 =  DgnTextStyle(name, loadDgnFile)
    newStyle1.CopyValues (fileStyle1)
    diff = fileStyle1.Compare (newStyle1)
    assert not diff.AnyBitSet()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetName(initDgnPlatformHost, loadDgnFile):
    name = "167"
    newStyle1 =  DgnTextStyle (name, loadDgnFile)
    assert name == repr(newStyle1.GetName())


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetID(initDgnPlatformHost, loadDgnFile):
    name = "177"
    newStyle1 =  DgnTextStyle (name, loadDgnFile)
    assert name == repr(newStyle1.GetName())


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TextStyleComparisonTest(initDgnPlatformHost, loadDgnFile):
    myStyle1 = DgnTextStyle("MyTextStyle1", loadDgnFile)
    myStyle2 = DgnTextStyle("MyTextStyle2", loadDgnFile)
    mask1 = myStyle1.Compare (myStyle2)
    assert not mask1.AnyBitSet()
    assert not mask1.GetPropertyFlag(eTextStyle_Color)
    mask1.SetPropertyFlag(eTextStyle_Color, True)
    assert mask1.GetPropertyFlag(eTextStyle_Color) == True
    assert mask1.AnyBitSet() == True
    mask1.ResetFlags()
    assert mask1.AnyBitSet() == False