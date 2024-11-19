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


def validateSetup (expectedSetup, testSetup):
    assert expectedSetup.UseFixedAdaptationForView () == testSetup.UseFixedAdaptationForView ()
    assert expectedSetup.GetBrightnessMultiplierForView () == testSetup.GetBrightnessMultiplierForView ()
    assert expectedSetup.UseFixedAdaptationForLuxology () == testSetup.UseFixedAdaptationForLuxology ()
    assert expectedSetup.GetAdaptationLevelForLuxology () == testSetup.GetAdaptationLevelForLuxology ()
    assert expectedSetup.GetBrightnessMultiplierForLuxology () == testSetup.GetBrightnessMultiplierForLuxology ()
    assert expectedSetup.GetContrastForLuxology () == testSetup.GetContrastForLuxology ()
    assert expectedSetup.GetGammaForLuxology () == testSetup.GetGammaForLuxology ()
    assert expectedSetup.UseHistogramForLuxology () == testSetup.UseHistogramForLuxology ()
    # assert expectedSetup.GetSolarLight () == testSetup.GetSolarLight ()
    # assert expectedSetup.GetAmbientLight () == testSetup.GetAmbientLight ()
    # assert expectedSetup.GetSkyDomeLight () == testSetup.GetSkyDomeLight ()
    # assert expectedSetup.GetFlashLight () == testSetup.GetFlashLight ()


def createExpectedSetup1 ():
    result = LightSetup ()
    result.SetName ("Morning")

    result.SetUseFixedAdaptationForView (False)
    result.SetAdaptationLevelForView (14.16666)
    result.SetBrightnessMultiplierForView (1.0)
    result.SetUseFixedAdaptationForLuxology (False)
    result.SetAdaptationLevelForLuxology (0.0)
    result.SetBrightnessMultiplierForLuxology (1.0)
    result.SetContrastForLuxology (0)
    result.SetGammaForLuxology (1.7)
    result.SetUseHistogramForLuxology (False)
    result.SetFattalColorSaturation (0.0)
    result.SetFattalAttenuation (0.0)

    solarLight = result.GetSolarLight ()
    solarLight.SetSolarType (SolarLight.eSOLARTYPE_TimeLocation)
    solarLight.SetSolarType (SolarLight.eSOLARTYPE_TimeLocation)
    solarLight.GetColor ().red     = 1.0
    solarLight.GetColor ().green   = 0.95294100000000004
    solarLight.GetColor ().blue    = 0.91764699999999999
    solarLight.SetTemperatureInKelvin (1)
    solarLight.SetCloudiness (0)
    solarLight.SetHour (9)
    solarLight.SetMinute (0)
    solarLight.SetMonth (9)
    solarLight.SetDay (25)
    solarLight.SetYear (2001)
    solarLight.SetGmtOffset (-5.0)
    solarLight.SetUseDaylightSavings (True)
    solarLight.SetAzimuthAngle (122.182)
    solarLight.SetAltitudeAngle (16.2689999)
    solarLight.SetIntensity (1.0)
    solarLight.GetGeoLocation ().latitude  = 39.9333
    solarLight.GetGeoLocation ().longitude = -75.15
    solarLight.GetVectorOverride ().Init (0.812, -0.511, 0.28)

    solarLight.SetUseVolumetrics (False)
    solarLight.GetScatterColor ().red      = 0.5
    solarLight.GetScatterColor ().green    = 0.5
    solarLight.GetScatterColor ().blue     = 0.5
    solarLight.SetVolumeSampleCount (40)
    solarLight.SetVolumeHeightInMeters (20.0)
    solarLight.SetVolumeRadiusBaseInMeters (10.0)
    solarLight.SetVolumeScattering (50.0)
    solarLight.SetVolumeDensity (50.0)
    solarLight.SetVolumeAttenuation (10.0)
    solarLight.SetVolumeShift (0.0)
    solarLight.SetShadowType (AdvancedLight.eSHADOWTYPE_RayTrace)
    solarLight.SetDeepShadowSamples (1024)
    solarLight.GetShadowColor ().red       = 0.0
    solarLight.GetShadowColor ().green     = 0.0
    solarLight.GetShadowColor ().blue      = 0.0
    solarLight.SetVolumeAffectDiffuse (100.0)
    solarLight.SetVolumeAffectSpecular (100.0)
    solarLight.SetVolumeAffectCaustics (100.0)
    solarLight.SetSpreadAngleInRadians (0.017453292519943295)
    solarLight.SetCastsShadows (True)
    solarLight.SetShadowQuality (Light.eSHADOWQUALITY_Sharp)
    solarLight.SetTurbidity (3.0)
    solarLight.SetIsColorPhysicallyBased (True)

    solarLight.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    solarLight.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    solarLight.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)
    solarLight.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)

    map = solarLight.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor)
    map.SetIsEnabled (True)
    map.SetFileName ("BRICK02.jpg")

    map = solarLight.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Procedure)
    #LxoProcedure is not exposed
    # map.AddLxoProcedure (LxoProcedure.PROCEDURETYPE_Constant)

    ambientLight = result.GetAmbientLight ()
    ambientLight.SetIsEnabled (True)
    ambientLight.SetIntensity (0.3)
    ambientLight.GetColor ().red = ambientLight.GetColor ().green = ambientLight.GetColor ().blue = 1.0

    flashLight = result.GetFlashLight ()
    flashLight.SetIsEnabled (False)
    flashLight.SetIntensity (1.0)
    flashLight.GetColor ().red = flashLight.GetColor ().green = flashLight.GetColor ().blue = 1.0

    skyLight = result.GetSkyDomeLight ()
    skyLight.SetIsEnabled (False)
    skyLight.GetColor ().red = skyLight.GetColor ().green = skyLight.GetColor ().blue = 1.0
    skyLight.SetCastsShadows (False)
    skyLight.SetShadowQuality (Light.eSHADOWQUALITY_SoftMedium)
    skyLight.SetIntensity (-1.0)
    skyLight.SetIsColorPhysicallyBased (False)

    return result


@pytest.mark.parametrize('fileName', ['LightSetup.dgn'])
def test_LoadAndSaveSetup(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    modelID = srcDgnFile.GetDefaultModelId()
    ret = srcDgnFile.LoadRootModelById(modelID)
    dgnModel = ret[0]
    assert dgnModel is not None
    srcDgnFile.FillSectionsInModel(dgnModel)
    setup = LightManager.GetManager().LoadSetupFromModel ("Morning", dgnModel)
    flashLight = setup.GetFlashLight ()
    flashLight.SetIsEnabled (True)
    flashLight.SetIntensity (0.5)
    flashLight.GetColor().red = flashLight.GetColor().green = flashLight.GetColor().blue = 0.6
    LightManager.GetManager().SaveSetupToModel(setup, True, dgnModel)
    setupCompare = LightManager.GetManager().LoadSetupFromModel("Morning", dgnModel)
    assert setupCompare == setup


@pytest.mark.parametrize('fileName', ['LightSetup.dgn'])
def test_DeleteSetup(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    modelID = srcDgnFile.GetDefaultModelId()
    ret = srcDgnFile.LoadRootModelById(modelID)
    dgnModel = ret[0]
    assert dgnModel is not None
    srcDgnFile.FillSectionsInModel(dgnModel)
    setup = LightManager.GetManager().LoadSetupFromModel ("Morning", dgnModel)
    rse = LightManager.GetManager().DeleteLightSetup ("Morning", dgnModel)
    assert rse == eSUCCESS
    setup = LightManager.GetManager().LoadSetupFromModel ("Morning", dgnModel)
    assert setup is None

@pytest.mark.skip(reason="Ping.Chen, error in bb r platformtests")
@pytest.mark.parametrize('fileName', ['LightSetup.dgn'])
def test_FindSetupsInFile(initDgnPlatformHost, loadDgnFile):
    modelID = loadDgnFile.GetDefaultModelId()
    ret = loadDgnFile.LoadRootModelById(modelID)
    dgnModel = ret[0]
    assert dgnModel is not None
    loadDgnFile.FillSectionsInModel(dgnModel)
    setup = LightManager.GetManager().LoadSetupFromModel ("Morning", dgnModel)
    expectedSetup = createExpectedSetup1 ()
    validateSetup (expectedSetup, setup)