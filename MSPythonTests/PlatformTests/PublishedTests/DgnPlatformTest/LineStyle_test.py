import os
import pytest
import math
import sys
import numpy as np
from numpy import arange
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *


def TraverseComponent (comp) :
    comp.IsV7 ()
    range = DRange3d()
    comp.GetRange (range)
    comp.GetStoredUnitScale ()
    comp.GetUnitScale ()
    comp.IsNoScale ()
    comp.Is3d ()

def TraverseAnyComponent (compIn) :
    if compIn is None :
        return
    resource_type = compIn.GetResourceType ()
    if resource_type == LS_RESOURCE_Compound:
        comp = compIn
        TraverseComponent (comp)
    elif resource_type == LS_RESOURCE_LineCode:
        comp = compIn
        TraverseComponent (comp)
    elif resource_type == LS_RESOURCE_LinePoint:
        comp = compIn
        TraverseComponent (comp)
    elif resource_type in [LS_RESOURCE_PointSymbol, LS_RESOURCE_PointSymbolV7]:
        comp = compIn
        TraverseComponent (comp)
    else :
        pass


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetMap(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnFile = ret[0].GetDgnFile()
    dgnLsMap = dgnFile.GetLineStyleMap ()
    if dgnLsMap is None :
        pytest.fail()
    for ls in dgnLsMap :
        styleNo = ls.GetStyleNumber ()
        name = ls.GetStyleName ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DesignFileMapIterator(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnLsMap = LineStyleManager.GetLineStyleMap (loadDgnFile)
    if dgnLsMap is None :
        pytest.fail()
    for ls in dgnLsMap :
        StyleNumber = ls.GetStyleNumber ()
        styleName = ls.GetStyleName()

       
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SystemMapIterator(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    systemLsMap = LineStyleManager.GetSystemLineStyleMap ()
    assert systemLsMap != None
    for ls in systemLsMap :
        StyleNumber = ls.GetStyleNumber ()
        styleName = ls.GetStyleName()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindByNumberInFileMap(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnFile = ret[0].GetDgnFile()
    dgnLsMap = DgnFile.GetLineStyleMap (dgnFile)
    assert dgnLsMap != None
    entry = dgnLsMap.GetLineStyleEntry (-113)
    if entry is not None :
        entry.GetLocationType ()
        entry.GetFileName ()
        entry.GetStyleName ()
        entry.GetUnitsDefinition()
        entry.IsPhysical ()
        entry.IsUnitsUOR()
        entry.IsUnitsMaster()
        entry.IsUnitsDevice()
        entry.GetStyleNumber()
        entry.IsSnappable ()
        entry.IsContinuous ()
        entry.IsElement()
        entry.IsSCScaleIndependent()
        comp = entry.GetComponentCP (None)
        TraverseAnyComponent (comp)
        

    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindByNameInSystemMap(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    styleNames = ["{ -E- }", "{ Arrow }", "{ Origin Line }", "{ Tapered Dash }", "{ Wide Dash }"]
    systemLsMap = LsSystemMap.GetSystemMap ()
    for name in styleNames:
        entry = systemLsMap.GetLineStyleEntry (name)
        if entry is not None :
            entry.GetLocationType ()
            entry.GetFileName ()
            entry.GetStyleName ()
            entry.GetUnitsDefinition()
            entry.IsPhysical ()
            entry.IsUnitsUOR()
            entry.IsUnitsMaster()
            entry.IsUnitsDevice()
            entry.GetStyleNumber()
            entry.IsSnappable ()
            entry.IsContinuous ()
            entry.IsElement()
            entry.IsSCScaleIndependent()
            comp = entry.GetComponent (None)
            TraverseAnyComponent (comp)


@pytest.mark.skip(reason="DimensionStyleManager is not exposed in python")
def test_CreateStyle(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnFile = loadDgnFile
    if dgnFile is None :
        pytest.fail()
    testName = { "TestName" }
    preTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    dimStyle = DimensionStyleManager.Create (testName, dgnFile)
    if DimensionStyleManager.AddToFile (dimStyle) != SUCCESS :
        pytest.fail()
    postTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    if postTestStyle is None :
        pytest.fail()


@pytest.mark.skip(reason="DimensionStyleManager is not exposed in python. Needs work")
def test_CreateStyle_ERROR(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnFile = loadDgnFile
    preTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    dimStyle = DimensionStyleManager.Create (testName, dgnFile)
    if DimensionStyleManager.AddToFile (dimStyle) != SUCCESS :
        pytest.fail()


@pytest.mark.skip(reason="DimensionStyleManager is not exposed in python. Needs work")
def test_ReplaceInFile(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.Normal, False)
    dgnFile = loadDgnFile
    assert dgnFile != None
    preTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    if preTestStyle is None :
        pytest.fail()
    dimStyle = DimensionStyleManager.Create (testName, dgnFile)
    if DimensionStyleManager.AddToFile (dimStyle) != SUCCESS :
        pytest.fail()
    postTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    if postTestStyle is None :
        pytest.fail()