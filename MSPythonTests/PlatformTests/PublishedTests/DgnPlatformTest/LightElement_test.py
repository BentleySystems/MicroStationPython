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


msGeomConst_radiansPerDegree = 7.85398163397448280000e-001 / 45.0
def createLightElement1 (setTypeOnly):
    result = PointLight ()
    if setTypeOnly :
        return result
    result.SetIntensity (1.0)
    result.GetColor ().red = result.GetColor ().green = result.GetColor ().blue = 1.0
    result.SetIsEnabled (True)
    result.SetBrightness (2650)
    result.SetUseVolumetrics (False)
    result.SetVolumeSampleCount (40)
    result.SetVolumeScattering (50.0)
    result.SetVolumeDensity (50.0)
    result.SetVolumeAttenuation (10.0)
    result.SetVolumeShift (0.0)
    result.SetVolumeHeightInMeters (2.0)
    result.SetVolumeRadiusBaseInMeters (1.0)
    result.GetScatterColor ().red = result.GetScatterColor ().green = result.GetScatterColor ().blue = 0.5
    result.SetShadowType (AdvancedLight.eSHADOWTYPE_RayTrace)
    result.SetDeepShadowSamples (1024)
    result.SetVolumeAffectDiffuse (100.0)
    result.SetVolumeAffectSpecular (100.0)
    result.SetVolumeAffectCaustics (100.0)
    result.SetCastsShadows (True)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_Sharp)
    result.GetShadowColor ().red = result.GetShadowColor ().green = result.GetShadowColor ().blue = 0.0
    result.SetName ("Point Light (1)")
    result.SetPresetName ("[Select]")
    result.SetUsesIesData (False)
    result.SetIesFileName ("")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (0.0, 0.0, 1.0)
    result.SetIesRotation (0.0)
    result.SetBulbSizeInUors (0.0)
    result.SetBulbCount (1)
    result.SetTemperatureInKelvin (0)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)
    return result


def createLightElement2 (setTypeOnly):
    result = PointLight ()
    if setTypeOnly :
        return result
    result.SetIntensity (0.7975)
    result.GetColor ().red = 0.212
    result.GetColor ().green = 1.0
    result.GetColor ().blue = 0.682
    result.SetIsEnabled (True)
    result.SetBrightness (1700)

    result.SetUseVolumetrics (True)
    result.SetVolumeSampleCount (60)
    result.SetVolumeScattering (33.333333)
    result.SetVolumeDensity (75.362318)
    result.SetVolumeAttenuation (30.434782)
    result.SetVolumeShift (36.231884)
    result.SetVolumeHeightInMeters (2.0)
    result.SetVolumeRadiusBaseInMeters (3.5)
    result.GetScatterColor ().red = 128.0 / 255.0
    result.GetScatterColor ().green = result.GetScatterColor ().blue = 0.0

    result.SetShadowType (AdvancedLight.eSHADOWTYPE_RayTrace)
    result.SetDeepShadowSamples (1024)
    result.SetVolumeAffectDiffuse (73.913043)
    result.SetVolumeAffectSpecular (46.376812)
    result.SetVolumeAffectCaustics (50.724638)
    result.SetCastsShadows (True)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_SoftMedium)
    result.GetShadowColor ().red = 158.0 / 255.0
    result.GetShadowColor ().green = 85.0 / 255.0
    result.GetShadowColor ().blue = 102.0 / 255.0

    result.SetName ("Alvin Gentry")
    result.SetPresetName ("halogen 100W Bulb")
    result.SetUsesIesData (False)
    result.SetIesFileName ("")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (0.0, 0.0, 1.0)
    result.SetIesRotation (0.0)

    result.SetBulbSizeInUors (762.0)
    result.SetBulbCount (1)
    result.SetTemperatureInKelvin (0)

    result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)
    return result


def createLightElement3 (setTypeOnly) :
    result = DistantLight ()
    if setTypeOnly :
        return result
    result.SetIntensity (4.65)
    result.GetColor ().red = 1.0
    result.GetColor ().green = 0.647
    result.GetColor ().blue = 0.31
    result.SetIsEnabled (True)
    result.SetBrightness (2650)

    result.SetUseVolumetrics (False)
    result.SetVolumeSampleCount (40)
    result.SetVolumeScattering (50.0)
    result.SetVolumeDensity (50.0)
    result.SetVolumeAttenuation (10.0)
    result.SetVolumeShift (0.0)
    result.SetVolumeHeightInMeters (2.0)
    result.SetVolumeRadiusBaseInMeters (1.0)
    result.GetScatterColor ().red = result.GetScatterColor ().green = result.GetScatterColor ().blue = 0.5

    result.SetShadowType (AdvancedLight.eSHADOWTYPE_RayTrace)
    result.SetDeepShadowSamples (1024)
    result.SetVolumeAffectDiffuse (100.0)
    result.SetVolumeAffectSpecular (100.0)
    result.SetVolumeAffectCaustics (100.0)
    result.SetCastsShadows (False)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_SoftMedium)
    result.GetShadowColor ().red = 176.0 / 255.0
    result.GetShadowColor ().green = 176.0 / 255.0
    result.GetShadowColor ().blue = 176.0 / 255.0

    result.SetName ("Directional Light (1)")
    result.SetPresetName ("[Select]")
    result.SetUsesIesData (False)
    result.SetIesFileName ("")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (0.0, -1.0, 0.0)
    result.SetIesRotation (0.0)

    result.SetTemperatureInKelvin (2600)

    result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)

    map = result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Image)
    # map.SetUnits (MAPUNITS_Meters)
    map.GetSize ().Init (3.0, 2.0, 1.0)
    map.GetOffset ().Init (5.0, 7.0, 0.0)
    map.SetAngleInRadians (25.0 * msGeomConst_radiansPerDegree)
    map.SetHorizontalWrap (LightMap.eWRAPMODE_Mirror)
    map.SetVerticalWrap (LightMap.eWRAPMODE_Edge)
    # map.SetMode (MAPMODE_Spherical)
    map.SetFileName ("block08.jpg")
    return result


def createLightElement4 (setTypeOnly) :
    result = SpotLight ()
    if setTypeOnly :
        return result
    result.SetIntensity (1.0)
    result.GetColor ().red = result.GetColor ().green = result.GetColor ().blue = 1.0
    result.SetIsEnabled (True)
    result.SetBrightness (15)

    result.SetUseVolumetrics (True)
    result.SetVolumeSampleCount (40)
    result.SetVolumeScattering (50.0)
    result.SetVolumeDensity (50.0)
    result.SetVolumeAttenuation (10.0)
    result.SetVolumeShift (0.0)
    result.SetVolumeHeightInMeters (2.0)
    result.SetVolumeRadiusBaseInMeters (0.0)
    result.GetScatterColor ().red = result.GetScatterColor ().green = result.GetScatterColor ().blue = 0.5

    result.SetShadowType (AdvancedLight.eSHADOWTYPE_RayTrace)
    result.SetVolumeAffectDiffuse (62.318841)
    result.SetVolumeAffectSpecular (85.507246)
    result.SetVolumeAffectCaustics (49.275362)
    result.SetCastsShadows (True)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_Sharp)
    result.GetShadowColor ().red = result.GetShadowColor ().green = result.GetShadowColor ().blue = 0.0

    result.SetName ("Caetano Veloso")
    result.SetPresetName ("[Select]")
    result.SetUsesIesData (False)
    result.SetIesFileName ("")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (0.0, 0.0, 1.0)
    result.SetIesRotation (0.0)

    result.SetTemperatureInKelvin (0)
    result.SetDeltaAngleInRadians (5.0 * msGeomConst_radiansPerDegree)
    result.SetOuterAngleInRadians (30.0 * msGeomConst_radiansPerDegree)
    result.SetBulbCount (1)
    result.SetBulbSizeInUors (0.0)

    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)

    map = result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Procedure)
    # map.SetUnits (MAPUNITS_Meters)
    map.GetSize ().Init (1.0, 1.0, 1.0)
    map.GetOffset ().Init (0.0, 0.0, 0.0)
    map.SetAngleInRadians (0.0)
    map.SetHorizontalWrap (LightMap.eWRAPMODE_Mirror)
    map.SetVerticalWrap (LightMap.eWRAPMODE_Repeat)


    map = result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Procedure)
    # map.SetUnits (MAPUNITS_Relative)
    map.GetSize ().Init (1.0, 1.0, 1.0)
    map.GetOffset ().Init (0.0, 0.0, 0.0)
    map.SetAngleInRadians (0.0)
    map.SetHorizontalWrap (LightMap.eWRAPMODE_Repeat)
    map.SetVerticalWrap (LightMap.eWRAPMODE_Repeat)
    # map.SetMode (MAPMODE_FrontProject)

    return result


def createLightElement6 (setTypeOnly) :
    result = DistantLight ()
    if setTypeOnly :
        return result
    result.SetIntensity (7.8)
    result.GetColor ().red = 1.0
    result.GetColor ().green = 0.976
    result.GetColor ().blue = 0.992
    result.SetIsEnabled (True)
    result.SetBrightness (2650)

    result.SetUseVolumetrics (True)
    result.SetVolumeSampleCount (40)
    result.SetVolumeScattering (27.536232)
    result.SetVolumeDensity (97.36)
    result.SetVolumeAttenuation (33.43)
    result.SetVolumeShift (97.3)
    result.SetVolumeHeightInMeters (5.0)
    result.SetVolumeRadiusBaseInMeters (0.35)
    result.SetSpreadAngleInRadians (15.0 * msGeomConst_radiansPerDegree)
    result.GetScatterColor ().red = 69.0 / 255.0
    result.GetScatterColor ().green = 196.0 / 255.0
    result.GetScatterColor ().blue = 130.0 / 255.0

    result.SetShadowType (AdvancedLight.eSHADOWTYPE_DeepShadowMap)
    result.SetDeepShadowSamples (2048)
    result.SetVolumeAffectDiffuse (56.521739)
    result.SetVolumeAffectSpecular (47.826087)
    result.SetVolumeAffectCaustics (73.913043)
    result.SetCastsShadows (True)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_SoftCoarse)
    result.GetShadowColor ().red = result.GetShadowColor ().green = result.GetShadowColor ().blue = 0.0

    result.SetName ("Ray Davies")
    result.SetPresetName ("[Select]")
    result.SetUsesIesData (False)
    result.SetIesFileName ("")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (1.0, 0.0, 0.0)
    result.SetIesRotation (0.0)

    result.SetTemperatureInKelvin (6500)

    result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor).SetIsEnabled (False)

    map = result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Image)
    # map.SetUnits (MAPUNITS_Feet)
    map.GetSize ().Init (0.6096, 0.762, 0.3048)
    map.GetOffset ().Init (1.2192, 2.1336, 0.0)
    map.SetAngleInRadians (70.0 * msGeomConst_radiansPerDegree)
    map.SetHorizontalWrap (LightMap.eWRAPMODE_Edge)
    map.SetVerticalWrap (LightMap.eWRAPMODE_Mirror)
    # map.SetMode (MAPMODE_Planar)
    map.SetFileName ("brick06.jpg")

    map = result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Image)
    # map.SetUnits (MAPUNITS_Meters)
    map.GetSize ().Init (1.0, 1.0, 1.0)
    map.GetOffset ().Zero ()
    map.SetAngleInRadians (0.0)
    map.SetHorizontalWrap (LightMap.eWRAPMODE_Repeat)
    map.SetVerticalWrap (LightMap.eWRAPMODE_Repeat)
    # map.SetMode (MAPMODE_Cylindrical)
    map.SetFileName ("bikelane dirty.jpg")
    return result


def createLightElement7 (setTypeOnly) :
    result = SpotLight ()
    if setTypeOnly :
        return result
    result.SetIntensity (0.4177)
    result.GetColor ().red = 1.0
    result.GetColor ().green = 0.788
    result.GetColor ().blue = 0.58
    result.SetIsEnabled (False)
    result.SetBrightness (4200)

    result.SetUseVolumetrics (True)
    result.SetVolumeSampleCount (15)
    result.SetVolumeScattering (74.35)
    result.SetVolumeDensity (29.76)
    result.SetVolumeAttenuation (18.5)
    result.SetVolumeShift (25.0)
    result.SetVolumeHeightInMeters (0.25)
    result.SetVolumeRadiusBaseInMeters (2.5)
    result.GetScatterColor ().red = result.GetScatterColor ().green = result.GetScatterColor ().blue = 0.5

    result.SetShadowType (AdvancedLight.eSHADOWTYPE_DeepShadowMap)
    result.SetDeepShadowSamples (512)
    result.SetVolumeAffectDiffuse (100.0)
    result.SetVolumeAffectSpecular (100.0)
    result.SetVolumeAffectCaustics (100.0)
    result.SetCastsShadows (True)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_SoftVeryFine)
    result.GetShadowColor ().red = 27.0 / 255.0
    result.GetShadowColor ().green = 178.0 / 255.0
    result.GetShadowColor ().blue = 62.0 / 255.0

    result.SetName ("Spot Light")
    result.SetPresetName ("[Select]")
    result.SetUsesIesData (False)
    result.SetIesFileName ("")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (0.0, -1.0, 0.0)
    result.SetIesRotation (0.0)

    result.SetTemperatureInKelvin (3700)
    result.SetDeltaAngleInRadians (12.0 * msGeomConst_radiansPerDegree)
    result.SetOuterAngleInRadians (22.0 * msGeomConst_radiansPerDegree)
    result.SetBulbCount (3)
    result.SetBulbSizeInUors (35000)

    result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)

    map = result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount)
    map.SetIsEnabled (True)
    map.SetStyle (LightMap.eMAPSTYLE_Procedure)
    # map.SetUnits (MAPUNITS_Meters)
    map.GetSize ().Init (2.75, 4.25, 3.5)
    map.GetOffset ().Init (12.0, 0.0, 3.5)
    map.SetAngleInRadians (0.0)
    map.SetHorizontalWrap (LightMap.eWRAPMODE_Reset)
    map.SetVerticalWrap (LightMap.eWRAPMODE_Reset)
    # map.SetMode (MAPMODE_Solid)


    return result


def createLightElement5 (setTypeOnly): 
    result = AreaLight ()
    if (setTypeOnly) :
        return result ()
    result.SetIntensity (0.9)
    result.GetColor ().red = 0.38
    result.GetColor ().green = 0.592
    result.GetColor ().blue = 0.788
    result.SetIsEnabled (True)
    result.SetBrightness (5000)

    result.SetShadowType (AdvancedLight.eSHADOWTYPE_RayTrace)
    result.SetDeepShadowSamples (1024)
    result.SetVolumeAffectDiffuse (62.318841)
    result.SetVolumeAffectSpecular (97.101449)
    result.SetVolumeAffectCaustics (56.521739)
    result.SetCastsShadows (True)
    result.SetShadowQuality (LightElement.eSHADOWQUALITY_SoftVeryFine)
    result.GetShadowColor ().red = 37.0 / 255.0
    result.GetShadowColor ().green = 37.0 / 255.0
    result.GetShadowColor ().blue = 204.0 / 255.0

    result.SetName ("Area Light")
    result.SetPresetName ("halogen 250W Bulb")
    result.SetUsesIesData (True)
    result.SetIesFileName ("sample.ies")
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (1.0, 0.0, 0.0)
    result.SetIesRotation (1.0)

    result.SetBulbCount (3)
    result.SetTemperatureInKelvin (0)

    result.GetMaps ().AddMap (LightMap.eMAPTYPE_Color).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_DiffuseAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_SpecularAmount).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricScatterColor).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_ShadowColor).SetIsEnabled (False)
    result.GetMaps ().AddMap (LightMap.eMAPTYPE_VolumetricDensity).SetIsEnabled (False)
    return result


def createLightElement8 (setTypeOnly) :
    result = SkyOpeningLight ()
    if (setTypeOnly) :
        return result.get ()
    result.SetName ("Sky Opening")
    result.SetMinimumSamples (16)
    result.SetMaximumSamples (64)
    # GetIesReference is not exposed in python
    # result.GetIesReference ().Init (-1.0, 0.0, 0.0)
    return result




@pytest.mark.parametrize('fileName', ['3dMetricGeneral.dgn'])
def test_LoadAndSaveSetup(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    
    # Need to find the light cell to create a light. 
    dataDir = os.environ['MSPYTESTDATA']
    ConfigurationManager.DefineVariable ("_USTN_DGNLIBLIST_SYSTEM", dataDir)
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, True)
    light1 = createLightElement1 (False)
    light2 = createLightElement2 (False)
    light3 = createLightElement3 (False)
    light4 = createLightElement4 (False)
    light6 = createLightElement6 (False)
    light7 = createLightElement7 (False)

    light1.SetModelRef (ret[0])
    light2.SetModelRef (ret[0])
    light3.SetModelRef (ret[0])
    light4.SetModelRef (ret[0])
    light6.SetModelRef (ret[0])
    light7.SetModelRef (ret[0])
    
    assert light1.Save () == BentleyStatus.eSUCCESS
    assert light2.Save () == BentleyStatus.eSUCCESS
    assert light3.Save () == BentleyStatus.eSUCCESS
    assert light4.Save () == BentleyStatus.eSUCCESS
    assert light6.Save () == BentleyStatus.eSUCCESS
    assert light7.Save () == BentleyStatus.eSUCCESS

    # loadedLight1 = LightElement.LoadFromElement (light1.GetElementRef ())
    areaShapeEEh = EditElementHandle()
    openSkyShapeEEh = EditElementHandle()
    verts = DPoint3dArray()
    verts.append(DPoint3d(-500,-500,0))
    verts.append(DPoint3d(500,-500,0))
    verts.append(DPoint3d(500,500,0))
    verts.append(DPoint3d(-500,500,0))
    assert ShapeHandler.CreateShapeElement (areaShapeEEh, None, verts, True, ret[0]) == BentleyStatus.eSUCCESS
    assert ShapeHandler.CreateShapeElement (openSkyShapeEEh, None, verts, True, ret[0]) == BentleyStatus.eSUCCESS
    areaShapeEEh.AddToModel ()
    openSkyShapeEEh.AddToModel ()
    light5 = createLightElement5 (False)
    light8 = createLightElement8 (False)
    areaLight = light5
    skyLight = light8
    light5.SetModelRef (ret[0])
    light8.SetModelRef (ret[0])
    assert areaLight != None
    assert skyLight != None
    # assert areaLight.SaveNewLight (areaShapeEEh) == BentleyStatus.eSUCCESS
    # assert skyLight.SaveNewLight (openSkyShapeEEh) == BentleyStatus.eSUCCESS
    loadedLight5 = LightElement.LoadFromElement (light5.GetElementRef ())
    # assert loadedLight5 is not None
    loadedLight8 = LightElement.LoadFromElement (light8.GetElementRef ())
    # assert loadedLight8 is not None


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_LightSetupSynch(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    light1 = createLightElement1 (False)
    light2 = createLightElement2 (False)
    light3 = createLightElement3 (False)
    light4 = createLightElement4 (False)
    light5 = createLightElement6 (False)
    light6 = createLightElement7 (False)

    light1.SetModelRef (ret[0])
    light2.SetModelRef (ret[0])
    light3.SetModelRef (ret[0])
    light4.SetModelRef (ret[0])
    light5.SetModelRef (ret[0])
    light6.SetModelRef (ret[0])

    # assert light1.Save () == BentleyStatus.eSUCCESS
    # assert light2.Save () == BentleyStatus.eSUCCESS
    # assert light3.Save () == BentleyStatus.eSUCCESS
    # assert light4.Save () == BentleyStatus.eSUCCESS
    # assert light5.Save () == BentleyStatus.eSUCCESS
    # assert light6.Save () == BentleyStatus.eSUCCESS

    setup = LightSetup()
    setup.SetName ("MySetup")
    setup.GetEntries ().SynchToLightList (ret[0])
    # assert len(setup.GetEntries ()) == 6
    LightManager.GetManager ().SaveSetupToModel (setup, True, ret[0])
    setupCompare = LightManager.GetManager ().LoadSetupFromModel ("MySetup", ret[0])