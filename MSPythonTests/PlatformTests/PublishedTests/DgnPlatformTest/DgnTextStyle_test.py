#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
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
def test_CreateStyle(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "49"
    style1 =  DgnTextStyle(name, dgnFile)
    style2 =  DimensionStyle(name, dgnFile)
    style3 =  DgnTextSnippet.Create(name, dgnFile)
    assert style1 != None
    assert style2 != None
    assert style3 != None

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AddToSameFile(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "59"
    style1 =  DgnTextStyle(name, dgnFile)
    style2 =  DimensionStyle(name, dgnFile)
    style3 =  DgnTextSnippet.Create(name, dgnFile)
    assert style1 != None
    assert style2 != None
    assert style3 != None
    status1 = style1.Add ()
    status2 = style2.Add ()
    status3 = style3.Add ()
    assert status1 == BentleyStatus.eSUCCESS
    assert status2 == BentleyStatus.eSUCCESS
    assert status3 == BentleyStatus.eSUCCESS
    AddStyleToFile (name, dgnFile)
    fileStyle1 = DgnTextStyle.GetByName (name, dgnFile)
    fileStyle2 = DimensionStyle.GetByName (name, dgnFile)
    fileStyle3 = DgnTextSnippet.GetByName (name, dgnFile)
    assert fileStyle1 != None
    assert fileStyle2 != None
    assert fileStyle3 != None
    status1 = AddStyleToFile (name, dgnFile, style1)
    assert status1 != BentleyStatus.eSUCCESS
    newName = "74"
    style1.SetName (newName)
    status1 = style1.Add ()
    assert status1 == BentleyStatus.eSUCCESS



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Delete(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "85"
    AddStyleToFile (name, dgnFile)
    status1 = DgnTextStyle.Delete (name, dgnFile)
    assert status1 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, dgnFile)
    fileStyle2 = DimensionStyle.GetByName (name, dgnFile)
    fileStyle3 = DgnTextSnippet.GetByName (name, dgnFile)
    assert fileStyle1 == None
    assert fileStyle2 == None
    assert fileStyle3 == None

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Replace(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "100"
    status0 = AddStyleToFile (name, dgnFile)
    assert status0 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, dgnFile)
    assert fileStyle1 != None
    status1 = fileStyle1.Replace()
    assert status1 == BentleyStatus.eSUCCESS
    newName = "109"
    fileStyle1.SetName (newName)
    status1 = fileStyle1.Replace()              #Actually do nothing here
    assert status1 == BentleyStatus.eERROR      #ERROR expected
    newfileStyle1 = DgnTextStyle.GetByName (newName, dgnFile)
    assert newfileStyle1 == None
    status1 = fileStyle1.Replace(name)          #Passing old name will do the real replacment
    assert status1 == BentleyStatus.eSUCCESS
    newfileStyle1 = DgnTextStyle.GetByName (newName, dgnFile)
    assert newfileStyle1 != None


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetById(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "129"
    status1 =  AddStyleToFile (name, dgnFile)
    assert status1 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, dgnFile)
    assert fileStyle1 != None
    idStyle = DgnTextStyle.GetByID (fileStyle1.GetID(), dgnFile)
    assert idStyle != None
    assert name == repr(idStyle.GetName())


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Copy(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "147"
    status1 =  AddStyleToFile (name, dgnFile)
    assert status1 == BentleyStatus.eSUCCESS
    fileStyle1 = DgnTextStyle.GetByName (name, dgnFile)
    assert fileStyle1 != None
    newName = "154"
    newStyle1 =  DgnTextStyle(name, dgnFile)
    newStyle1.CopyValues (fileStyle1)
    diff = fileStyle1.Compare (newStyle1)
    assert not diff.AnyBitSet()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetName(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "167"
    newStyle1 =  DgnTextStyle (name, dgnFile)
    assert name == repr(newStyle1.GetName())


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetID(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    name = "177"
    newStyle1 =  DgnTextStyle (name, dgnFile)
    assert name == repr(newStyle1.GetName())


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_TextStyleComparisonTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    myStyle1 = DgnTextStyle("MyTextStyle1", dgnFile)
    myStyle2 = DgnTextStyle("MyTextStyle2", dgnFile)
    mask1 = myStyle1.Compare (myStyle2)
    assert not mask1.AnyBitSet()
    assert not mask1.GetPropertyFlag(eTextStyle_Color)
    mask1.SetPropertyFlag(eTextStyle_Color, True)
    assert mask1.GetPropertyFlag(eTextStyle_Color) == True
    assert mask1.AnyBitSet() == True
    mask1.ResetFlags()
    assert mask1.AnyBitSet() == False