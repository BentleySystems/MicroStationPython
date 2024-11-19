#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
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



@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetMap(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnFile = ret[0].GetDgnFile()
    dgnLsMap = dgnFile.GetLineStyleMap ()
    if dgnLsMap is None :
        pytest.fail()
    for ls in dgnLsMap :
        styleNo = ls.GetStyleNumber ()
        name = ls.GetStyleName ()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DesignFileMapIterator(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnLsMap = LineStyleManager.GetLineStyleMap (loadDgnFile)
    if dgnLsMap is None :
        pytest.fail()
    for ls in dgnLsMap :
        StyleNumber = ls.GetStyleNumber ()
        styleName = ls.GetStyleName()

       
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SystemMapIterator(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    systemLsMap = LineStyleManager.GetSystemLineStyleMap ()
    assert systemLsMap != None
    for ls in systemLsMap :
        StyleNumber = ls.GetStyleNumber ()
        styleName = ls.GetStyleName()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindByNumberInFileMap(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnFile = ret[0].GetDgnFile()
    dgnLsMap = DgnFile.GetLineStyleMap (dgnFile)
    assert dgnLsMap != None
    entry = dgnLsMap.GetLineStyleEntry (-113)
    if entry is not None :
        entry.GetDefinitionLocation ()  #In C++ side, GetDefinitionLocation calls GetLocationType () directly
        entry.GetSourceFileName ()  #In C++ side, GetSourceFileName calls GetFileName () directly
        entry.GetStyleName ()
        entry.GetStyleNumber()

        #Following member functions are implemented in its base class LsDefinition, but LsDefinition is not published in SDK
        # entry.GetUnitsDefinition()
        # entry.IsPhysical ()
        # entry.IsUnitsUOR()
        # entry.IsUnitsMaster()
        # entry.IsUnitsDevice()
        # entry.IsSnappable ()
        # entry.IsContinuous ()
        # entry.IsElement()
        # entry.IsSCScaleIndependent()
        # comp = entry.GetComponentCP (None)
        # TraverseAnyComponent (comp)
        

    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindByNameInSystemMap(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    styleNames = ["{ -E- }", "{ Arrow }", "{ Origin Line }", "{ Tapered Dash }", "{ Wide Dash }"]
    systemLsMap = LsSystemMap.GetSystemMap ()
    for name in styleNames:
        entry = systemLsMap.GetLineStyleEntry (name)
        if entry is not None :
            entry.GetDefinitionLocation ()  #In C++ side, GetDefinitionLocation calls GetLocationType () directly
            entry.GetSourceFileName () #In C++ side, GetSourceFileName calls GetFileName () directly
            entry.GetStyleName ()
            entry.GetStyleNumber ()

            #Following member functions are implemented in its base class LsDefinition, but LsDefinition is not published in SDK
            # entry.GetUnitsDefinition()
            # entry.IsPhysical ()
            # entry.IsUnitsUOR()
            # entry.IsUnitsMaster()
            # entry.IsUnitsDevice()
            # entry.IsSnappable ()
            # entry.IsContinuous ()
            # entry.IsElement()
            # entry.IsSCScaleIndependent()
            # comp = entry.GetComponent (None)
            # TraverseAnyComponent (comp)


@pytest.mark.skip(reason="DimensionStyleManager is not exposed in python")
def test_CreateStyle(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)    
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnFile = srcDgnFile
    if dgnFile is None :
        pytest.fail()
    testName = { "TestName" }
    preTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    dimStyle = DimensionStyleManager.Create (testName, dgnFile)
    if DimensionStyleManager.AddToFile (dimStyle) != BentleyStatus.eSUCCESS :
        pytest.fail()
    postTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    if postTestStyle is None :
        pytest.fail()


@pytest.mark.skip(reason="DimensionStyleManager is not exposed in python. Needs work")
def test_CreateStyle_ERROR(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnFile = srcDgnFile
    preTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    dimStyle = DimensionStyleManager.Create (testName, dgnFile)
    if DimensionStyleManager.AddToFile (dimStyle) != BentleyStatus.eSUCCESS :
        pytest.fail()


@pytest.mark.skip(reason="DimensionStyleManager is not exposed in python. Needs work")
def test_ReplaceInFile(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    dgnFile = srcDgnFile
    assert dgnFile != None
    preTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    if preTestStyle is None :
        pytest.fail()
    dimStyle = DimensionStyleManager.Create (testName, dgnFile)
    if DimensionStyleManager.AddToFile (dimStyle) != BentleyStatus.eSUCCESS :
        pytest.fail()
    postTestStyle = DimensionStyleManager.GetByName (testName, dgnFile)
    if postTestStyle is None :
        pytest.fail()