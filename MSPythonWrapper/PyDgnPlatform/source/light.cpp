/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\sourceght.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Light.h>



static const char * __doc_Bentley_DgnPlatform_LightManager_ScaleColorForDisplay =R"doc(Clip the color to within the user-specified range. However, it is not
guaranteed that all types of material stores can be created or written
to.

:param colorToScale:
    Color in either 0-255 or 0-1 range based on isNormalized.

:param isNormalized:
    If true, colorToScale is 0-1. If false, colorToScale is 0-255.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_InitializeLightName =R"doc(Initialize light name

:param lightNameP:
    initialized light name

:param elemId:
    tag to use to generate name

:param modelRef:
    the model reference

:param type:
    the type of the light

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_FindIESFile =R"doc(Find IES file by specified name from the render dgn file.

:param iesName:
    the name of the Ies file.

:param renderDgnFile:
    the dng file to be scaned.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_GetLightingSearchPath =R"doc(Returns the lighting search path by the render dgn document moniker.

:param renderDgnMoniker:
    the moniker of the dgn document.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_DeleteLightSetup =R"doc(Delete the specified setup from the model.

:param setupName:
    the name of the setup to delete.

:param sourceModel:
    The model to search for.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_GetLightSetups =R"doc(Get the list of list setups as currently stored in the model. Note its
possible that this list can be empty when in a dgn file even though
there is an active and modeling setup. Due to these setups not having
been persisted yet

:param map:
    The map to populate with setups

:param sourceModel:
    The model to search for.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_SetActiveLightSetupForModel =R"doc(Update all the lights in the model and DgnAttachment useLights values
to the values stored in the light setup. Also making the setup passed
in the active setup.

:param setup:
    the setup to set active.

:param model:
    the model of the setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_SaveSetupToModel =R"doc()doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_GetActiveLightSetupForModel =R"doc(Returns the active light setup of the specified model.

:param useModelLighting:
    if use model lighting.

:param model:
    The specified model.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_LoadModelingSetup =R"doc(Load modeling setup of the source model, if not found it will create a
modeling setup for the model.

See also:
    LoadSetupFromModel, CreateModelingSetup

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_LoadSetupFromModelById =R"doc(Searches the specified model for the specified light setup. Older DGN
files do not have multiple light setups, but always have an active
light setup.

:param lightSetupElId:
    The elementId of the setup to load.

:param sourceModel:
    The model to search for the specified light setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_LoadSetupFromModel =R"doc(Searches the specified model for the specified light setup. Older DGN
files do not have multiple light setups, but always have an active
light setup.

:param setupName:
    The name of the setup to load. Pass NULL or L" " for setupName to
    get the active setup.

:param sourceModel:
    The model to search for the specified light setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_FindLightsInModelRef =R"doc(Returns all the light elements in the specified DgnModelRef.

:returns:
    NULL only if the DgnModelRef doesn't resolve to either a
    DgnAttachment or DgnModel.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_ConfigureLightSetupFromLegacySettings =R"doc(Configure the settings of the setup from legacy settings. the setup
will be configured from tcb settings first.

:param setup:
    the setup.

:param model:
    the model of the setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_GetActiveLightSetupPtrForModel =R"doc(Returns the active light setup of the specified model.

:param model:
    The specified model.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightManager_ConfigureSetupFromXml =R"doc(Configure the settings of the setup from given Xml.

:param lightSetup:
    the setup.

:param xml:
    the xml string in Utf16.

:param model:
    the model of the setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupCollection_AddLightSetup =R"doc(Add a LightSetup to this collection.

:param id:
    the element id of the LightSetup to be added.

:param setup:
    the LightSetup to be added.

:returns:
    the new entry or, if one already exists for this id, the existing
    entry.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupCollection_DeleteLightSetup =R"doc(Delete the LightSetup by the specified Element Id

:param id:
    the element id of the LightSetup to be removed.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupCollection_Copy =R"doc(Copy the contents of the specified LightSetupCollection.

:param rhs:
    The LightSetupCollection to be copied.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupCollection_InitDefaults =R"doc(Configure this LightSetupCollection with its default properties.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetNaturalFilmResponseExposure =R"doc(Sets the natural film response exposure of this LightSetup.

:param exposure:
    the new exposure value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetNaturalFilmResponseExposure =R"doc(Gets the natural film response exposure of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetToneMappingMode =R"doc(Sets the tone mapping mode of this LightSetup.

:param mode:
    the new tone mapping mode.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetToneMappingMode =R"doc(Gets the tone mapping mode of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetFattalAttenuation =R"doc(Sets the fattal attenuation of this LightSetup.

:param attenuation:
    the new fattal attenuation value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetFattalAttenuation =R"doc(Gets the fattal attenuation of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetFattalColorSaturation =R"doc(Sets the fattal color saturation of this LightSetup.

:param colorSaturation:
    the new fattal color saturation.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetFattalColorSaturation =R"doc(Gets the fattal color saturation of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetReinhardContrast =R"doc(Sets the reinhard contrast of this LightSetup.

:param contrast:
    the new reinhard contrast value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetReinhardContrast =R"doc(Gets the reinhard contrast of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetReinhardIntensity =R"doc(Sets the reinhard intensity of this LightSetup.

:param intensity:
    the new reinhard intensity value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetReinhardIntensity =R"doc(Gets the reinhard intensity of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetDragoExposure =R"doc(Sets the drago exposure of this LightSetup.

:param exposure:
    the new exposure value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetDragoExposure =R"doc(Gets the drago exposure of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetAutoCorrectColorMapGamma =R"doc(Sets if this LightSetup is auto correct color map gamma.

:param autoCorrect:
    if auto correct color map gamma.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetAutoCorrectColorMapGamma =R"doc(Returns if this LightSetup is auto correct color map gamma.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_IsModelingSetup =R"doc(Tests if this LightSetup is a modeling setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_IsActiveSetup =R"doc(Tests if this LightSetup is the active setup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetUseHistogramForLuxology =R"doc(Sets if this LightSetup is using histogram for luxology.

:param useHistogram:
    if using histogram for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_UseHistogramForLuxology =R"doc(Tests if this LightSetup is using histogram for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetGammaForLuxology =R"doc(Sets the gamma for luxology.

:param gamma:
    the new gamma value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetGammaForLuxology =R"doc(Gets the gamma for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetContrastForLuxology =R"doc(Sets the contrast for luxology.

:param contrast:
    the new contrast value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetContrastForLuxology =R"doc(Gets the contrast for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetBrightnessMultiplierForLuxology =R"doc(Sets the brightness multiplier for luxology.

:param multiplier:
    the new brightness multiplier.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetBrightnessMultiplierForLuxology =R"doc(Gets the brightness multiplier for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetAdaptationLevelForLuxology =R"doc(Sets the adaptation level for luxology.

:param level:
    the new adaptation level.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetAdaptationLevelForLuxology =R"doc(Gets the adaptation level for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetUseFixedAdaptationForLuxology =R"doc(Sets if this LightSetup is using fixed adaptation for luxology.

:param useAdaptation:
    if use fixed adaptation for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_UseFixedAdaptationForLuxology =R"doc(Tests if this LightSetup is using fixed adaptation for luxology.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetElementId =R"doc(Gets the element Id of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetBrightnessMultiplierForView =R"doc(Changes the brightness multiplier for view.

:param multiplier:
    the new brightness multiplier.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetBrightnessMultiplierForView =R"doc(Gets the brightness multiplier for view.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetAdaptationLevelForView =R"doc(Changes the adaptation level for view.

:param level:
    the new adaptation level.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetAdaptationLevelForView =R"doc(Gets the adaptation level for view.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetUseFixedAdaptationForView =R"doc(Sets if this LightSetup is using fixed adaptation for view.

:param useAdaptation:
    if use fixed adaptation.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_UseFixedAdaptationForView =R"doc(Tests if this LightSetup is using fixed adaptation for view.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetEntries =R"doc(Gets the constaning reference of the LightSetupEntryCollection of this
LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetSkyDomeLight =R"doc(Gets the constaning reference of the SkyDomeLight of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetFlashLight =R"doc(Gets the constaning reference of the FlashLight of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetAmbientLight =R"doc(Gets the constaning reference of the AmbientLight of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetSolarLight =R"doc(Gets the constaning reference of the SolarLight of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_SetName =R"doc(Sets the name of this LightSetup.

:param name:
    the new name.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_GetName =R"doc(Returns the name of this LightSetup.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_Copy =R"doc(Copy the contents of the specified LightSetup.

:param rhs:
    The LightSetup to be copied.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetup_InitDefaults =R"doc(Initializes a LightSetup to the default values.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntryCollection_SynchToLightList =R"doc(Synch this list of lights and references to the dgn file lights and
references

:param rootModelRef:
    the root model.

:param useCurrentLightValue:
    if use current light value to synch.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntryCollection_AddEntry =R"doc(Add a LightSetupEntry to this collection.

:param id:
    the element id of the LightSetupEntry to be added.

:returns:
    the new entry or, if one already exists for this id, the existing
    entry.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntryCollection_DeleteEntry =R"doc(Delete the LightSetupEntry by the specified Element Id

:param id:
    the element id of the LightSetupEntry to be removed.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntryCollection_Copy =R"doc(Copy the contents of the specified LightSetupEntryCollection.

:param rhs:
    The LightSetupEntryCollection to be copied.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntryCollection_InitDefaults =R"doc(Configure this LightSetupEntryCollection with its default properties.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntry_SetIntensity =R"doc(Sets the intensity of this LightSetupEntry.

:param intensity:
    the new intensity value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntry_GetIntensity =R"doc(Gets the intensity of this LightSetupEntry.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntry_SetIsEnabled =R"doc(Sets if the LightSetupEntry is enabled.

:param isEnabled:
    if enabled.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntry_IsEnabled =R"doc(Tests if the LightSetupEntry is enabled.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntry_Copy =R"doc(Copy the contents of the specified LightSetupEntry.

:param rhs:
    The LightSetupEntry to be copied.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightSetupEntry_InitDefaults =R"doc(Configure this LightSetupEntry with its default properties.

)doc";

static const char * __doc_Bentley_DgnPlatform_ModelingLightCollection_SetModelRef =R"doc(Sets the model of this light collection.

:param modelRef:
    Specify the model.

)doc";

static const char * __doc_Bentley_DgnPlatform_ModelingLightCollection_InsertLightElement =R"doc(Append the given light to this collection.

:param light:
    the light element to add to this collection.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElementCollection_GetModelRef =R"doc(Gets the constaining reference of the DgnModelRef.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElementCollection_Find =R"doc(Find the LightElement by id.

:param id:
    the element id of the light to find.

:returns:
    the constaining pointer of the LightElement.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyOpeningLight_SaveNewLight =R"doc(:param skyOpeningGeometryEEh:
    the element handle of geometry.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyOpeningLight_GetDirection =R"doc(Gets the direction of this sky opening light source.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyOpeningLight_SetMaximumSamples =R"doc(Sets the maximum samples of this sky opening light.

:param samples:
    the new maximum samples value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyOpeningLight_GetMaximumSamples =R"doc(Gets the maximum samples of this sky opening light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyOpeningLight_SetMinimumSamples =R"doc(Sets the minimum samples of this sky opening light.

:param samples:
    the new minimum samples value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyOpeningLight_GetMinimumSamples =R"doc(Gets the minimum samples of this sky opening light.

)doc";

static const char * __doc_Bentley_DgnPlatform_AreaLight_SaveNewLight =R"doc(:param areaGeometryEEh:
    the element handle of geometry.

)doc";

static const char * __doc_Bentley_DgnPlatform_AreaLight_GetLightGeometry =R"doc(Gets the light gemoetry of this area light.

:returns:
    the ElementRefP of the light area geometry.

)doc";

static const char * __doc_Bentley_DgnPlatform_AreaLight_GetDirection =R"doc(Gets the direction of this area light source.

)doc";

static const char * __doc_Bentley_DgnPlatform_AreaLight_SetBulbCount =R"doc(Sets the bulb count of this area light.

:param bulbCount:
    the new bulb count.

)doc";

static const char * __doc_Bentley_DgnPlatform_AreaLight_GetBulbCount =R"doc(Gets the bulb count of this area light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_GetDirection =R"doc(Gets the direction of this spot light source.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_SetBulbCount =R"doc(Sets the bulb count of this spot light.

:param count:
    the new bulb count.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_GetBulbCount =R"doc(Gets the bulb count of this spot light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_SetBulbSizeInUors =R"doc(Sets the bulb size in UORs of this spot light.

:param size:
    the new bulb size in Uors.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_GetBulbSizeInUors =R"doc(Gets the bulb size in UORs of this spot light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_GetInnerAngleInRadians =R"doc(Gets the inner angle of this SpotLight.

:returns:
    the inner angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_SetOuterAngleInRadians =R"doc(Sets the outer angle of this SpotLight.

:param angle:
    the outer angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_GetOuterAngleInRadians =R"doc(Gets the outer angle of this SpotLight.

:returns:
    the outer angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_SetDeltaAngleInRadians =R"doc(Sets the delta angle of this SpotLight.

:param angle:
    the new delta angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_SpotLight_GetDeltaAngleInRadians =R"doc(Gets the delta angle of this SpotLight.

:returns:
    the delta angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_PointLight_SetBulbCount =R"doc(Sets the bulb count of this point light.

:param count:
    the new bulb count.

)doc";

static const char * __doc_Bentley_DgnPlatform_PointLight_GetBulbCount =R"doc(Gets the bulb count of this point light.

)doc";

static const char * __doc_Bentley_DgnPlatform_PointLight_SetBulbSizeInUors =R"doc(Sets the bulb size in UORs of this point light.

:param size:
    the new bilb size in Uors.

)doc";

static const char * __doc_Bentley_DgnPlatform_PointLight_GetBulbSizeInUors =R"doc(Gets the bulb size in UORs of this point light.

)doc";

static const char * __doc_Bentley_DgnPlatform_DistantLight_GetDirection =R"doc(Gets the direction of this distant light source.)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_Save =R"doc(Save the light.

:param transform:
    An optional transformation to apply to the light

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetRMatrix =R"doc(Return the rotation matrix of this light element.

:param rMatrix:
    the rotation matrix of this light element.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetIesRotation =R"doc(Set the IES rotation angle of this light element. This setting is
ignored if the light type does not support IES.

:param rotation:
    the new Ies rotation value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetIesRotation =R"doc(Get the IES rotation angle of this light element. This setting is
ignored if the light type does not support IES.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetIesFileName =R"doc(Sets the IES file name of this light element. This setting is ignored
if the light type does not support IES.

:param fileName:
    the new Ies file path name.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetIesFileName =R"doc(Gets the IES file name of this light element. This setting is ignored
if the light type does not support IES.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetUsesIesData =R"doc(Sets if this light element is using IES data. This setting is ignored
if the light type does not support IES.

:param useIesData:
    if uses Ies date.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_UsesIesData =R"doc(Check if this light element is using IES data. This setting is ignored
if the light type does not support IES.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SupportsIes =R"doc(Check if this light element supports IES. Return true if this light
type supports IES.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetAttenuationDistance =R"doc(Sets the attenuation distance of this light.

:param distance:
    the new distance value.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetAttenuationDistance =R"doc(Gets the attenuation distance of this light. Provided for backwards
compatibility only. Unused.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_DoesLightAttenuate =R"doc(Check if the light attenuate. Provided for backwards compatibility
only. Unused.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetOrigin =R"doc(Gets the origin position of this light.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetPresetName =R"doc(Sets the preset name of this light. Used by GUI only.

:param name:
    the new preset name.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetPresetName =R"doc(Gets the preset name of this light. Used by GUI only - has no effect
on other settings.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetName =R"doc(Sets the name of this light.

:param name:
    the new name of the light.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetName =R"doc(Gets the name of this light.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_SetModelRef =R"doc(Sets the DgnModelRef of this light. Only required when creating a new
light for writing to file

:param modelRef:
    the specified model of this light.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_GetElementRef =R"doc(Gets the ElementRef of this light.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightElement_LoadFromElement =R"doc(Creates a new light element instance from the given ElementRef.

:param element:
    the ElementRef of the light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetGmtOffset =R"doc(Sets the GMT offset for the location of solar light. Used only if
SolarType is set to SOLARTYPE_TimeLocation.

:param offset:
    the new Gmt offset value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetGmtOffset =R"doc(Gets the GMT offset for the location of solar light. Used only if
SolarType is set to SOLARTYPE_TimeLocation.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetGeoLocation =R"doc(Gets the containing reference of the geographic 2D point of solar
light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetVectorOverride =R"doc(Gets the containing reference of the override vector of this light
emulates.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetAltitudeAngle =R"doc(Sets the angle of the Sun above the horizon (from 0-90 degrees). Used
only if SolarType is set to SOLARTYPE_Direction.

:param altitude:
    the new altitude value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetAltitudeAngle =R"doc(Gets the angle of the Sun above the horizon (from 0-90 degrees). Used
only if SolarType is set to SOLARTYPE_Direction.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetAzimuthAngle =R"doc(Sets the azimuth direction of the solar light emulates. Used only if
SolarType is set to SOLARTYPE_Direction.

:param azimuth:
    the new azimuth value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetAzimuthAngle =R"doc(Gets the azimuth direction of the solar light emulates (from 0-360
degrees). Used only if SolarType is set to SOLARTYPE_Direction.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetTurbidity =R"doc(Sets the turbidity of this light emulates.

:param turbidity:
    the new turbidity value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetTurbidity =R"doc(Gets the turbidity of this light emulates.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetCloudiness =R"doc(Sets the cloudiness of this light emulates.

:param cloudiness:
    the new cloudiness value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetCloudiness =R"doc(Gets the cloudiness of this light emulates.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetIsColorPhysicallyBased =R"doc(Sets if the color of this light emulates is physically based.

:param usePhysicalColor:
    if the color is physically based.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_IsColorPhysicallyBased =R"doc(Judge if the color of this light emulates is physically based.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetUseDaylightSavings =R"doc(Set if this light emulates is using day light saving. Used only if
SolarType is set to SOLARTYPE_TimeLocation.

:param useDst:
    is using day light saving.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_UseDaylightSavings =R"doc(Judge if this light emulates is using day light saving. Used only if
SolarType is set to SOLARTYPE_TimeLocation.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetYear =R"doc(Sets the year of this light emulates. Used only if SolarType is set to
SOLARTYPE_TimeLocation.

:param year:
    new year value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetYear =R"doc(Gets the year of this light emulates. Used only if SolarType is set to
SOLARTYPE_TimeLocation.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetMonth =R"doc(Sets the month of this light emulates. Used only if SolarType is set
to SOLARTYPE_TimeLocation.

:param month:
    Specified in range 0-11.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetMonth =R"doc(Gets the month of this light emulates. Used only if SolarType is set
to SOLARTYPE_TimeLocation.

:returns:
    the month the light emulates (from 0-11).

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetDay =R"doc(Sets the day of this light emulates. Used only if SolarType is set to
SOLARTYPE_TimeLocation.

:param day:
    new day value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetDay =R"doc(Gets the day of this light emulates. Used only if SolarType is set to
SOLARTYPE_TimeLocation.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetMinute =R"doc(Sets the minute of this light emulates. Used only if SolarType is set
to SOLARTYPE_TimeLocation.

:param minute:
    new minute value.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetMinute =R"doc(Gets the minute of this light emulates. Used only if SolarType is set
to SOLARTYPE_TimeLocation.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetHour =R"doc(Sets the hour this light emulates. Used only if SolarType is set to
SOLARTYPE_TimeLocation.

:param hour:
    Specified in range 1-24.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetHour =R"doc(Gets the hour of this light emulates. Used only if SolarType is set to
SOLARTYPE_TimeLocation.

:returns:
    the hour of the light emulates in (1-24).

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_SetSolarType =R"doc(Changes the SolarType of this solar light.

:param solarType:
    the new solar type.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_GetSolarType =R"doc(Gets the SolarType of this solar light.

)doc";

static const char * __doc_Bentley_DgnPlatform_SolarLight_Create =R"doc(Creates a new solar light instance that initialized the properties
from the SolarLight passed in.

:param solarLight:
    The specified SolarLight object.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetShadowColor =R"doc(Gets the shadow color of this light. Controls the color of shadows
from opaque objects. Options are Custom and Color Map. Using gray
color rather than black for shadows, you can remove overly dark
shadows from your scene even where only one bounce of light is used.
Using a color map the shadow color can be varied rather than being a
constant color.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetDeepShadowSamples =R"doc(Changes the deep shadow samples of this light.

:param samples:
    the new deep shadow samples.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetDeepShadowSamples =R"doc(Gets the deep shadow samples of this light.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetShadowType =R"doc(Sets the shadow type of this light.

:param type:
    the new shadow type. see GetShadowType().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetShadowType =R"doc(Gets the shadow type of this light. If shadow is on, sharpness of the
shadows is controlled by the Shadow option, which determines the
number of samples used to calculate the shadows. - Sharp - Number of
samples - 1 - Soft - Coarse - Number of samples - 16 - Soft - Medium -
Number of samples - 64 - Soft - Fine - Number of samples - 160 - Soft
- Very Fine - Number of samples - 256

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetCastsShadows =R"doc(Sets the casts shadows of this light. If on, shadows are generated by
the lighting.

:param castsShadows:
    if casts shadows.

See also:
    GetShadowType().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetScatterColor =R"doc(Gets the scatter color value. Scatter Color can be thought of as the
color of the " dust " particles making up the volume through which the
light is passing. You can select a Custom Map to control or vary the
scatter color to produce more interesting volume lighting effects.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetSpreadAngleInRadians =R"doc(Changes the spread angle of this light.

:param angle:
    the new apread angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetSpreadAngleInRadians =R"doc(Gets the spread angle of this light. This setting is used to soften
the solar shadows. Small values result in sharper shadows and larger
values produce softer shadows. A Spread Angle of 2 would produce
reasonably soft shadows whereas a value of 10 to 15 would produce very
soft shadows like you would expect on a overcast day.

:returns:
    the spread angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeAffectCaustics =R"doc(Changes the volume affect caustics of this light.

:param scale:
    the new affect caustics value.

See also:
    GetVolumeAffectCaustics().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeAffectCaustics =R"doc(Gets the amount as a percentage that the light contributes to a
caustic effect. A value of zero means that the light will not produce
caustic effects.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeAffectSpecular =R"doc(Changes the volume affect diffuse of this light.

:param scale:
    the new affect diffuse value.

See also:
    GetVolumeAffectSpecular().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeAffectSpecular =R"doc(Gets the amount as a percentage that the light affects specular within
the scene. A value of zero will produce no specular highlights.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeAffectDiffuse =R"doc(Changes the volume affect diffuse of this light.

:param scale:
    the new affect diffuse value.

See also:
    GetVolumeAffectDiffuse().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeAffectDiffuse =R"doc(Gets the volume affect diffuse of this light. This percentage value
will control how much the light contributes to the final Diffuse
shading of the scene. You can set this value to 0% if you want to hide
the light from Diffuse shading. This allows the creation of a
" specular only " light source.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeRadiusBaseInMeters =R"doc(Changes the volume radius or base value of this light. For spot light
set the base value, else set the radius value.

:param radius:
    the new radius or base value in meters.

See also:
    GetVolumeRadiusBaseInMeters().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeRadiusBaseInMeters =R"doc(Gets the volume radius or base value of this light. Applies to Point,
Directional, and Solar lights only. - For Solar and Directional
lights, Radius defines a cylinder radius. This, combined with the
height, creates the volume through which scattering occurs. - For
point lights, radius defines the radius of the sphere for the
scattering volume. - For spot lights, base defines the offset from the
spotlight at which the scattering can occur.

:returns:
    the base value for spot light or radius for other lights in
    meters.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeHeightInMeters =R"doc(Changes the volume height of this light.

:param height:
    the new height in meters.

See also:
    GetVolumeHeightInMeters().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeHeightInMeters =R"doc(Gets the volume height of this light, applies to Spot Lights,
Directional, and Solar lights only. Not applicable for point lights.
For distant and solar lights this is cylindrical with a diameter and
height. Height determines the length of the cylinder. For point lights
the effect is radial, so this occurs within a defined sphere and the
spot lights volume effects occur within a defined cone.

:returns:
    the volume height in meters.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeShift =R"doc(Changes the volume shift of this light.

:param scale:
    the new shift.

See also:
    GetVolumeShift().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeShift =R"doc(Gets the volume shift of this light. As the light is increasingly
attenuated, certain wavelengths are absorbed or scattered. This
setting can mimic these effects. Negative values push the color of the
volume increasingly toward light blues, while positive values push the
color towards warmer orange and red hues. The Attenuation value must
be a number above 0% to see any effect.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeAttenuation =R"doc(Changes the volume attenuation of this light.

:param scale:
    the new attenuation.

See also:
    GetVolumeAttenuation().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeAttenuation =R"doc(Gets the amount of attenuation of the effect. A value of 0% gives a
natural fall off and as the value increases the fall off becomes
greater.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeDensity =R"doc(Sets the density for the volumetric effect. Higher values will make
the volume thicker and more opaque.

:param scale:
    the new density.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeDensity =R"doc(Gets the volume density of this light.

See also:
    SetVolumeDensity().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeScattering =R"doc(Changes the volume scattering value of this light.

:param scale:
    the new scale.

See also:
    GetVolumeScattering().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeScattering =R"doc(Gets the volume scattering value of this light. The scattering value
controls the amount of light scattering which occurs inside the
volume. Higher values result in more scattering.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetVolumeSampleCount =R"doc(Changes the volume sample count of this light.

:param count:
    the new count.

See also:
    GetVolumeSampleCount().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetVolumeSampleCount =R"doc(Returns the volume sample count of this light. The sample count
controls the accuracy of the volumetric effect underneath shadowing
objects. Increasing the samples value improves the accuracy.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_SetUseVolumetrics =R"doc(Set this advanced light is using volumetrices. param(input)
useVolumetrics if using volumetrics.

See also:
    UseVolumetrics().

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_UseVolumetrics =R"doc(Test this advanced light is using volume effects, if true, volume
effects are calculated for Solar lighting.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_AddDefaultLightMaps =R"doc(Add default light maps if some of maps is not exist.

)doc";

static const char * __doc_Bentley_DgnPlatform_AdvancedLight_GetMaps =R"doc(Gets the containing LightMapCollection of this advanced light.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMapCollection_AddMap =R"doc(Create a LightMap by type and add it to this collection. If a map of
this type is already associated with this light, it will be replaced.

:param type:
    the map type to be added.

:returns:
    the LightMap pointer of given type.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMapCollection_DeleteMap =R"doc(Remove the LightMap by specified map type.

:param type:
    the map type to be deleted.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMapCollection_Size =R"doc(Gets the size of this collection.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMapCollection_Copy =R"doc(Copy the contents of the specified collection.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMapCollection_InitDefaults =R"doc(Configure this light map collection with its default properties. This
will remove all light maps.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_ClearLxoProcedure =R"doc(Remove all the LxoProcedures of this map.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_AddLxoProcedure =R"doc(Add a LxoProcedure to this map by LxoProcedure type. If a LxoProcedure
already exists for this map, it will be replaced.

:param type:
    the type of the procedure to be added.

:returns:
    the pointer of the added LxoProcedure.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetFileName =R"doc(Changes the image file name of this map if the style is
MAPSTYLE_Image.

:param fileName:
    the new file name of the map.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetFileName =R"doc(Gets the image file name of this map if the style is MAPSTYLE_Image.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetAngleInRadians =R"doc(Changes the rotation of this map.

:param angle:
    the new angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetAngleInRadians =R"doc(Gets the rotation of this map.

:returns:
    the angle in radians.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetOffset =R"doc(Units are meters unless map mode is set to MapMode::FrontProject, in
which case they are relative.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetSize =R"doc(Units are meters unless map mode is set to MapMode::FrontProject, in
which case they are relative.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetVerticalWrap =R"doc(Changes the vertical wrap mode of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetVerticalWrap =R"doc(Gets the vertical wrap mode of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetHorizontalWrap =R"doc(Changes the horizontal wrap mode of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetHorizontalWrap =R"doc(Gets the horizontal wrap mode of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetUnits =R"doc(Changes the map units of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetUnits =R"doc(Gets the map units of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetStyle =R"doc(Changes the map style of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetStyle =R"doc(Gets the map style of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetMode =R"doc(Changes the map mode of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetMode =R"doc(Gets the map mode of this LightMap.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_SetIsEnabled =R"doc(Sets if the light map is to be enabled.

:param isEnabled:
    true if the light map is to be enabled.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_IsEnabled =R"doc(Checks if the light map is enabled.

:returns:
    true if the light map is on, else return false if the light map is
    off.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_GetType =R"doc(Returns the type of this map.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_Copy =R"doc(This will copy everything except the map's type - map type must be set
when a map is first created.

)doc";

static const char * __doc_Bentley_DgnPlatform_LightMap_InitDefaults =R"doc(Sets all properties of this map to the default values except for map
type, which is set at creation and cannot be changed.

)doc";

static const char * __doc_Bentley_DgnPlatform_ModelDistantLight_GetDirection =R"doc(Gets the direction vector of this ModelDistantLight.

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyDomeLight_SetIsColorPhysicallyBased =R"doc(Sets if the light color is physically based.

:param usePhysicalColor:
    true if using physical color,false if user defined.

See also:
    IsColorPhysicallyBased().

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyDomeLight_IsColorPhysicallyBased =R"doc(Judges the type of light color used is physically based. There are two
kinds of color type:- User Defined - you can set the color manually,
via the Color setting, or automatically via the Temperature setting. -
Physically Based - Color is computed based on factors such as its
position in the sky, air quality, and cloudiness.

:returns:
    true if is physically based, else return false (if user defined).

)doc";

static const char * __doc_Bentley_DgnPlatform_SkyDomeLight_SetCastsShadows =R"doc(Sets if the light has cast shadows.

:param castsShadows:
    true if the light has cast shadows.

See also:
    CastsShadows(), GetShadowSamples().

)doc";

static const char * __doc_Bentley_DgnPlatform_AmbientLight_SetIsAutoAmbient =R"doc(Set percentage of solar.

:param isAuto:
    Is auto ambient or not.

)doc";

static const char * __doc_Bentley_DgnPlatform_AmbientLight_IsAutoAmbient =R"doc(Get if is auto ambient.

:returns:
    Is auto ambient or not.

)doc";

static const char * __doc_Bentley_DgnPlatform_AmbientLight_SetPercentageOfSolar =R"doc(Set percentage of solar.

:param percentage:
    The percentage value of solar. (0.0 to 1.0).

See also:
    GetPercentageOfSolar().

)doc";

static const char * __doc_Bentley_DgnPlatform_AmbientLight_GetPercentageOfSolar =R"doc(Get percentage of solar.

:returns:
    The percentage value of solar. (0.0 to 1.0).

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetShadowQualityFromSamples =R"doc(Gets the shadow quality by shadow samples value.

:param samples:
    the given samples.

See also:
    GetShadowSamples().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetSamplesFromShadowQuality =R"doc(Gets the shadow samples value by shadow quality.

:param quality:
    the given shadow quality.

See also:
    GetShadowSamples().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetShadowQuality =R"doc(Changes the shadow quality of the light.

:param quality:
    the new shadow quality.

See also:
    GetShadowSamples(), GetShadowQuality().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetShadowQuality =R"doc(Gets the shadow quality of the light.

See also:
    GetShadowSamples().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetShadowSamples =R"doc(Changes the shadow samples of the light.

:param samples:
    the new shadow samples value.

See also:
    CastsShadows(), GetShadowSamples().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetShadowSamples =R"doc(Gets the shadow samples of the light. Sharpness of the shadows is
controlled by the Shadow option, which determines the number of
samples used to calculate the shadows. - Sharp - Number of samples - 1
- Soft - Coarse - Number of samples - 16 - Soft - Medium - Number of
samples - 64 - Soft - Fine - Number of samples - 160 - Soft - Very
Fine - Number of samples - 256

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetTemperatureInKelvin =R"doc(Changes the temperature of the light.

:param temperature:
    The new temperature value in Kelvin.

See also:
    GetTemperatureInKelvin().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetTemperatureInKelvin =R"doc(Returns the temperature of the light in Kelvin. When the color type is
set to User Defined the temperature is a color temperature. While a
color is chosen manually, with the Color setting, Temperature is set
to Custom (0).

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetBrightness =R"doc(Changes the brightness of the light.

:param brightness:
    the new brightness value.

See also:
    GetBrightness().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetBrightness =R"doc(Gets the brightness of the light. Controls the brightness for the
rendering, in combination with the Adapt to Brightness/Brightness
Multiplier toggle. When Tone Mapping Mode is set to Brightness
Multiplier, sets the scale factor to be applied to the brightness of
the pixels for the next rendering. When Tone Mapping Mode is set to
Adapt to Brightness, sets the intensity (in lumens per square meter)
that should be used as the middle of the display range for the next
rendering. The allowable range depends on the selected mode:- Adapt
to Brightness - allowable range is 0.001 to 501188.0. - Brightness
Multiplier - allowable range is -4 to 4.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetIsEnabled =R"doc(Sets if the light is to be enabled.

:param enabled:
    true if the light is to be enabled.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_IsEnabled =R"doc(Checks if the light is enabled.

:returns:
    true if the light is on, else return false if the light is off.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetColor =R"doc(Sets the RGB factor of the light.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetColor =R"doc(Gets the RGB factor of the light color.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_SetIntensity =R"doc(Sets the brightness of the lighting from 0 (no Sun) to 100 (full Sun).

:param intensity:
    The new intensity value of the light.

See also:
    GetIntensity().

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetIntensity =R"doc(Gets the intensity of the light. The intensity controls how bright
(how much light) is produced by the environment at render time. - For
ambient and flashbulb, defines the intensities by lumens per square
meter. - For solar, its value represents the solar intensity in watts
per square meter. The default value of 1000 watts per square meter
represents very bright sunlight. - For other lights, its value
represents the brightness of the lighting from 0 (no Sun) to 100 (full
Sun).

:returns:
    The intensity value of the light (0.0 to 1.0).

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_GetType =R"doc(Returns the type of the light object.

See also:
    LightType.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_InitDefaults =R"doc(Configures this light with its default properties.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_Equals =R"doc(Test two lights for equality.

:param rhs:
    The another light object.

:param testPersistedOnly:
    if only test persisted settings.

:returns:
    true for equal, else return false.

)doc";

static const char * __doc_Bentley_DgnPlatform_Light_Copy =R"doc(Copy the contents of the specified light.

:param copyFrom:
    The light to be copied.

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Light(py::module_& m)
    {

    //===================================================================================
    // enum LightAnnouncerPriority
    py::enum_< LightAnnouncerPriority>(m, "LightAnnouncerPriority")
        .value("eFirst", LightAnnouncerPriority::First)
        .value("eAnimation", LightAnnouncerPriority::Animation)
        .export_values();

    //===================================================================================
    // enum LightAnnouncerPurpose
    py::enum_< LightAnnouncerPurpose>(m, "LightAnnouncerPurpose")
        .value("eViewUpdate", LightAnnouncerPurpose::ViewUpdate)
        .value("eModelFacetExport", LightAnnouncerPurpose::ModelFacetExport)
        .value("eSolarTimeElementHandler", LightAnnouncerPurpose::SolarTimeElementHandler)
        .value("eVueRender", LightAnnouncerPurpose::VueRender)
        .export_values();

    //===================================================================================
    // enum ToneMappingMode
    py::enum_< ToneMappingMode>(m, "ToneMappingMode")
        .value("eWard97", ToneMappingMode::Ward97)
        .value("eWard97Histogram", ToneMappingMode::Ward97Histogram)
        .value("eDrago03", ToneMappingMode::Drago03)
        .value("eReinhard05", ToneMappingMode::Reinhard05)
        .value("eFattal02", ToneMappingMode::Fattal02)
        .value("eNaturalFilmResponse", ToneMappingMode::NaturalFilmResponse)
        .export_values();
    
    //===================================================================================
    // struct Light
    py::class_< Light, RefCountedPtr<Light> > c2(m, "Light");

    if (true)
        {
        //===================================================================================
        // enum LightType
        py::enum_< Light::LightType>(c2, "LightType", py::arithmetic())
            .value("eLIGHTTYPE_Brightness", Light::LIGHTTYPE_Brightness)
            .value("eLIGHTTYPE_MaterialGlow", Light::LIGHTTYPE_MaterialGlow)
            .value("eLIGHTTYPE_SkyDome", Light::LIGHTTYPE_SkyDome)
            .value("eLIGHTTYPE_Solar", Light::LIGHTTYPE_Solar)
            .value("eLIGHTTYPE_Flash", Light::LIGHTTYPE_Flash)
            .value("eLIGHTTYPE_Ambient", Light::LIGHTTYPE_Ambient)
            .value("eLIGHTTYPE_Invalid", Light::LIGHTTYPE_Invalid)
            .value("eLIGHTTYPE_Distant", Light::LIGHTTYPE_Distant)
            .value("eLIGHTTYPE_Point", Light::LIGHTTYPE_Point)
            .value("eLIGHTTYPE_Spot", Light::LIGHTTYPE_Spot)
            .value("eLIGHTTYPE_Area", Light::LIGHTTYPE_Area)
            .value("eLIGHTTYPE_SkyOpening", Light::LIGHTTYPE_SkyOpening)
            .value("eLIGHTTYPE_ModelDistant", Light::LIGHTTYPE_ModelDistant)
            .export_values();

        //===================================================================================
        // enum ShadowQuality
        py::enum_< Light::ShadowQuality>(c2, "ShadowQuality", py::arithmetic())
            .value("eSHADOWQUALITY_Invalid", Light::SHADOWQUALITY_Invalid)
            .value("eSHADOWQUALITY_Sharp", Light::SHADOWQUALITY_Sharp)
            .value("eSHADOWQUALITY_SoftCoarse", Light::SHADOWQUALITY_SoftCoarse)
            .value("eSHADOWQUALITY_SoftMedium", Light::SHADOWQUALITY_SoftMedium)
            .value("eSHADOWQUALITY_SoftFine", Light::SHADOWQUALITY_SoftFine)
            .value("eSHADOWQUALITY_SoftVeryFine", Light::SHADOWQUALITY_SoftVeryFine)
            .value("eSHADOWQUALITY_Custom", Light::SHADOWQUALITY_Custom)
            .export_values();
        }

    c2.def("Copy", &Light::Copy, "copyFrom"_a, DOC(Bentley, DgnPlatform, Light, Copy));
    c2.def("Equals", &Light::Equals, "rhs"_a, "testPersistedOnly"_a, DOC(Bentley, DgnPlatform, Light, Equals));
    c2.def("InitDefaults", &Light::InitDefaults, DOC(Bentley, DgnPlatform, Light, InitDefaults));
    
    c2.def_property_readonly("Type", &Light::GetType);
    c2.def("GetType", &Light::GetType, DOC(Bentley, DgnPlatform, Light, GetType));
    
    c2.def_property("Intensity", &Light::GetIntensity, &Light::SetIntensity);
    c2.def("GetIntensity", &Light::GetIntensity, DOC(Bentley, DgnPlatform, Light, GetIntensity));
    c2.def("SetIntensity", &Light::SetIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, Light, SetIntensity));

    c2.def_property("Color", py::cpp_function(&Light::GetColor, py::return_value_policy::reference_internal), py::cpp_function(&Light::SetColor));
    c2.def("GetColor", &Light::GetColor, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Light, GetColor));
    c2.def("SetColor", &Light::SetColor, "color"_a, DOC(Bentley, DgnPlatform, Light, SetColor));
    
    c2.def_property("Enabled", &Light::IsEnabled, &Light::SetIsEnabled);
    c2.def("IsEnabled", &Light::IsEnabled, DOC(Bentley, DgnPlatform, Light, IsEnabled));
    c2.def("SetIsEnabled", &Light::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, Light, SetIsEnabled));
    
    c2.def_property("Brightness", &Light::GetBrightness, &Light::SetBrightness);
    c2.def("GetBrightness", &Light::GetBrightness, DOC(Bentley, DgnPlatform, Light, GetBrightness));
    c2.def("SetBrightness", &Light::SetBrightness, "bridgtness"_a, DOC(Bentley, DgnPlatform, Light, SetBrightness));
    
    c2.def_property("TemperatureInKelvin", &Light::GetTemperatureInKelvin, &Light::SetTemperatureInKelvin);
    c2.def("GetTemperatureInKelvin", &Light::GetTemperatureInKelvin, DOC(Bentley, DgnPlatform, Light, GetTemperatureInKelvin));
    c2.def("SetTemperatureInKelvin", &Light::SetTemperatureInKelvin, "temp"_a, DOC(Bentley, DgnPlatform, Light, SetTemperatureInKelvin));
    
    c2.def_property("ShadowSamples", &Light::GetShadowSamples, &Light::SetShadowSamples);
    c2.def("GetShadowSamples", &Light::GetShadowSamples, DOC(Bentley, DgnPlatform, Light, GetShadowSamples));
    c2.def("SetShadowSamples", &Light::SetShadowSamples, "samples"_a, DOC(Bentley, DgnPlatform, Light, SetShadowSamples));
    
    c2.def_property("ShadowQuality", &Light::GetShadowQuality, &Light::SetShadowQuality);
    c2.def("GetShadowQuality", &Light::GetShadowQuality, DOC(Bentley, DgnPlatform, Light, GetShadowQuality));
    c2.def("SetShadowQuality", &Light::SetShadowQuality, "quality"_a, DOC(Bentley, DgnPlatform, Light, SetShadowQuality));
    
    c2.def_static("GetSamplesFromShadowQuality", &Light::GetSamplesFromShadowQuality, "quality"_a, DOC(Bentley, DgnPlatform, Light, GetSamplesFromShadowQuality));
    c2.def_static("GetShadowQualityFromSamples", &Light::GetShadowQualityFromSamples, "samples"_a, DOC(Bentley, DgnPlatform, Light, GetShadowQualityFromSamples));

    //===================================================================================
    // struct AmbientLight
    py::class_< AmbientLight, AmbientLightPtr, Light> c3(m, "AmbientLight");

    c3.def(py::init(&AmbientLight::Create));
    
    c3.def_property("PercentageOfSolar", &AmbientLight::GetPercentageOfSolar, &AmbientLight::SetPercentageOfSolar);
    c3.def("GetPercentageOfSolar", &AmbientLight::GetPercentageOfSolar, DOC(Bentley, DgnPlatform, AmbientLight, GetPercentageOfSolar));
    c3.def("SetPercentageOfSolar", &AmbientLight::SetPercentageOfSolar, "percent"_a, DOC(Bentley, DgnPlatform, AmbientLight, SetPercentageOfSolar));
    
    c3.def_property("AutoAmbient", &AmbientLight::IsAutoAmbient, &AmbientLight::SetIsAutoAmbient);
    c3.def("IsAutoAmbient", &AmbientLight::IsAutoAmbient, DOC(Bentley, DgnPlatform, AmbientLight, IsAutoAmbient));
    c3.def("SetIsAutoAmbient", &AmbientLight::SetIsAutoAmbient, "auto"_a, DOC(Bentley, DgnPlatform, AmbientLight, SetIsAutoAmbient));

    //===================================================================================
    // struct FlashLight
    py::class_< FlashLight, FlashLightPtr, Light> c4(m, "FlashLight");

    c4.def(py::init(&FlashLight::Create), "initFrom"_a);

    //===================================================================================
    // struct SkyDomeLight
    py::class_< SkyDomeLight, SkyDomeLightPtr, Light> c5(m, "SkyDomeLight");

    c5.def("SetCastsShadows", &SkyDomeLight::SetCastsShadows, "castShadows"_a, DOC(Bentley, DgnPlatform, SkyDomeLight, SetCastsShadows));
    
    c5.def_property("ColorPhysicallyBased", &SkyDomeLight::IsColorPhysicallyBased, &SkyDomeLight::SetIsColorPhysicallyBased);
    c5.def("IsColorPhysicallyBased", &SkyDomeLight::IsColorPhysicallyBased, DOC(Bentley, DgnPlatform, SkyDomeLight, IsColorPhysicallyBased));
    c5.def("SetIsColorPhysicallyBased", &SkyDomeLight::SetIsColorPhysicallyBased, "value"_a, DOC(Bentley, DgnPlatform, SkyDomeLight, SetIsColorPhysicallyBased));
    
    c5.def(py::init(&SkyDomeLight::Create), "initFrom"_a);

    //===================================================================================
    // struct ModelDistantLight
    py::class_< ModelDistantLight, ModelDistantLightPtr, Light> c6(m, "ModelDistantLight");

    c6.def(py::init(&ModelDistantLight::Create), "light"_a);
    
    c6.def_property_readonly("Direction", &ModelDistantLight::GetDirection);
    c6.def("GetDirection", &ModelDistantLight::GetDirection, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelDistantLight, GetDirection));
    //===================================================================================
    // struct LightMap
    py::class_< LightMap, LightMapPtr> c7(m, "LightMap", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum MapType
        py::enum_< LightMap::MapType>(c7, "MapType", py::arithmetic())
            .value("eMAPTYPE_None", LightMap::MAPTYPE_None)
            .value("eMAPTYPE_Color", LightMap::MAPTYPE_Color)
            .value("eMAPTYPE_VolumetricDensity", LightMap::MAPTYPE_VolumetricDensity)
            .value("eMAPTYPE_VolumetricScatterColor", LightMap::MAPTYPE_VolumetricScatterColor)
            .value("eMAPTYPE_DiffuseAmount", LightMap::MAPTYPE_DiffuseAmount)
            .value("eMAPTYPE_SpecularAmount", LightMap::MAPTYPE_SpecularAmount)
            .value("eMAPTYPE_ShadowColor", LightMap::MAPTYPE_ShadowColor)
            .export_values();

        //===================================================================================
        // enum MapStyle
        py::enum_< LightMap::MapStyle>(c7, "MapStyle", py::arithmetic())
            .value("eMAPSTYLE_Image", LightMap::MAPSTYLE_Image)
            .value("eMAPSTYLE_Procedure", LightMap::MAPSTYLE_Procedure)
            .export_values();

        //===================================================================================
        // enum WrapMode
        py::enum_< LightMap::WrapMode>(c7, "WrapMode", py::arithmetic())
            .value("eWRAPMODE_Repeat", LightMap::WRAPMODE_Repeat)
            .value("eWRAPMODE_Reset", LightMap::WRAPMODE_Reset)
            .value("eWRAPMODE_Mirror", LightMap::WRAPMODE_Mirror)
            .value("eWRAPMODE_Edge", LightMap::WRAPMODE_Edge)
            .export_values();
        }

    c7.def("InitDefaults", &LightMap::InitDefaults, DOC(Bentley, DgnPlatform, LightMap, InitDefaults));
    c7.def("__eq__", [] (LightMapCR self, LightMapCR other) { return self.Equals(other); });
    c7.def("Copy", &LightMap::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, LightMap, Copy));
    
    c7.def_property_readonly("Type", &LightMap::GetType);
    c7.def("GetType", &LightMap::GetType, DOC(Bentley, DgnPlatform, LightMap, GetType));
    
    c7.def_property("Enabled", &LightMap::IsEnabled, &LightMap::SetIsEnabled);
    c7.def("IsEnabled", &LightMap::IsEnabled, DOC(Bentley, DgnPlatform, LightMap, IsEnabled));
    c7.def("SetIsEnabled", &LightMap::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, LightMap, SetIsEnabled));
    
    c7.def_property("Mode", &LightMap::GetMode, &LightMap::SetMode);
    c7.def("GetMode", &LightMap::GetMode, DOC(Bentley, DgnPlatform, LightMap, GetMode));
    c7.def("SetMode", &LightMap::SetMode, "mode"_a, DOC(Bentley, DgnPlatform, LightMap, SetMode));
    
    c7.def_property("Style", &LightMap::GetStyle, &LightMap::SetStyle);
    c7.def("GetStyle", &LightMap::GetStyle, DOC(Bentley, DgnPlatform, LightMap, GetStyle));
    c7.def("SetStyle", &LightMap::SetStyle, "style"_a, DOC(Bentley, DgnPlatform, LightMap, SetStyle));
    
    c7.def_property("Units", &LightMap::GetUnits, &LightMap::SetUnits);
    c7.def("GetUnits", &LightMap::GetUnits, DOC(Bentley, DgnPlatform, LightMap, GetUnits));
    c7.def("SetUnits", &LightMap::SetUnits, "units"_a, DOC(Bentley, DgnPlatform, LightMap, SetUnits));
    
    c7.def_property("HorizontalWrap", &LightMap::GetHorizontalWrap, &LightMap::SetHorizontalWrap);
    c7.def("GetHorizontalWrap", &LightMap::GetHorizontalWrap, DOC(Bentley, DgnPlatform, LightMap, GetHorizontalWrap));
    c7.def("SetHorizontalWrap", &LightMap::SetHorizontalWrap, "mode"_a, DOC(Bentley, DgnPlatform, LightMap, SetHorizontalWrap));
    
    c7.def_property("VerticalWrap", &LightMap::GetVerticalWrap, &LightMap::SetVerticalWrap);
    c7.def("GetVerticalWrap", &LightMap::GetVerticalWrap, DOC(Bentley, DgnPlatform, LightMap, GetVerticalWrap));
    c7.def("SetVerticalWrap", &LightMap::SetVerticalWrap, "mode"_a, DOC(Bentley, DgnPlatform, LightMap, SetVerticalWrap));
    
    c7.def_property_readonly("Size", &LightMap::GetSize);
    c7.def("GetSize", &LightMap::GetSize, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightMap, GetSize));
    
    c7.def_property_readonly("Offset", &LightMap::GetOffset);
    c7.def("GetOffset", &LightMap::GetOffset, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightMap, GetOffset));
    
    c7.def_property("AngleInRadians", &LightMap::GetAngleInRadians, &LightMap::SetAngleInRadians);    
    c7.def("GetAngleInRadians", &LightMap::GetAngleInRadians, DOC(Bentley, DgnPlatform, LightMap, GetAngleInRadians));
    c7.def("SetAngleInRadians", &LightMap::SetAngleInRadians, "angle"_a, DOC(Bentley, DgnPlatform, LightMap, SetAngleInRadians));
    
    c7.def_property("FileName", &LightMap::GetFileName, &LightMap::SetFileName);    
    c7.def("GetFileName", &LightMap::GetFileName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightMap, GetFileName));
    c7.def("SetFileName", &LightMap::SetFileName, "fileName"_a, DOC(Bentley, DgnPlatform, LightMap, SetFileName));
    
    c7.def("GetLxoProcedure", &LightMap::GetLxoProcedureP);
    c7.def("AddLxoProcedure", &LightMap::AddLxoProcedure, "type"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightMap, AddLxoProcedure));
    c7.def("ClearLxoProcedure", &LightMap::ClearLxoProcedure, DOC(Bentley, DgnPlatform, LightMap, ClearLxoProcedure));

    //===================================================================================
    // struct LightMapCollection
    py::class_< LightMapCollection, std::unique_ptr<LightMapCollection, py::nodelete> > c8(m, "LightMapCollection");
    
    c8.def("InitDefaults", &LightMapCollection::InitDefaults, DOC(Bentley, DgnPlatform, LightMapCollection, InitDefaults));
    c8.def("__eq__", [] (LightMapCollectionCR self, LightMapCollectionCR other) { return self.Equals(other); });
    c8.def("Copy", &LightMapCollection::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, LightMapCollection, Copy));
    c8.def("Size", &LightMapCollection::Size, DOC(Bentley, DgnPlatform, LightMapCollection, Size));
    c8.def("GetMap", &LightMapCollection::GetMapP, "type"_a);
    c8.def("DeleteMap", &LightMapCollection::DeleteMap, "type"_a, DOC(Bentley, DgnPlatform, LightMapCollection, DeleteMap));
    c8.def("AddMap", &LightMapCollection::AddMap, "type"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightMapCollection, AddMap));
    c8.def("__iter__", [] (LightMapCollectionR self) { return py::make_iterator(self.begin(), self.end()); });

    //===================================================================================
    // struct AdvancedLight
    py::class_< AdvancedLight, RefCountedPtr<AdvancedLight>, Light> c9(m, "AdvancedLight");

    if (true)
        {
        //===================================================================================
        // enum ShadowType
        py::enum_< AdvancedLight::ShadowType>(c9, "ShadowType", py::arithmetic())
            .value("eSHADOWTYPE_RayTrace", AdvancedLight::SHADOWTYPE_RayTrace)
            .value("eSHADOWTYPE_DeepShadowMap", AdvancedLight::SHADOWTYPE_DeepShadowMap)
            .export_values();
        }

    c9.def_property_readonly("Maps", &AdvancedLight::GetMaps);
    c9.def("GetMaps", &AdvancedLight::GetMaps, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AdvancedLight, GetMaps));

    c9.def("AddDefaultLightMaps", &AdvancedLight::AddDefaultLightMaps, DOC(Bentley, DgnPlatform, AdvancedLight, AddDefaultLightMaps));
    
    c9.def_property("IsUseVolumetrics", &AdvancedLight::UseVolumetrics, &AdvancedLight::SetUseVolumetrics);
    c9.def("UseVolumetrics", &AdvancedLight::UseVolumetrics, DOC(Bentley, DgnPlatform, AdvancedLight, UseVolumetrics));
    c9.def("SetUseVolumetrics", &AdvancedLight::SetUseVolumetrics, "useVolume"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetUseVolumetrics));
    
    c9.def_property("VolumeSampleCount", &AdvancedLight::GetVolumeSampleCount, &AdvancedLight::SetVolumeSampleCount);
    c9.def("GetVolumeSampleCount", &AdvancedLight::GetVolumeSampleCount, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeSampleCount));
    c9.def("SetVolumeSampleCount", &AdvancedLight::SetVolumeSampleCount, "sampleCount"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeSampleCount));
    
    c9.def_property("VolumeScattering", &AdvancedLight::GetVolumeScattering, &AdvancedLight::SetVolumeScattering);
    c9.def("GetVolumeScattering", &AdvancedLight::GetVolumeScattering, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeScattering));
    c9.def("SetVolumeScattering", &AdvancedLight::SetVolumeScattering, "scale"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeScattering));
    
    c9.def_property("VolumeDensity", &AdvancedLight::GetVolumeDensity, &AdvancedLight::SetVolumeDensity);
    c9.def("GetVolumeDensity", &AdvancedLight::GetVolumeDensity, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeDensity));
    c9.def("SetVolumeDensity", &AdvancedLight::SetVolumeDensity, "density"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeDensity));
    
    c9.def_property("VolumeAttenuation", &AdvancedLight::GetVolumeAttenuation, &AdvancedLight::SetVolumeAttenuation);
    c9.def("GetVolumeAttenuation", &AdvancedLight::GetVolumeAttenuation, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeAttenuation));
    c9.def("SetVolumeAttenuation", &AdvancedLight::SetVolumeAttenuation, "scale"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeAttenuation));
    
    c9.def_property("VolumeShift", &AdvancedLight::GetVolumeShift, &AdvancedLight::SetVolumeShift);
    c9.def("GetVolumeShift", &AdvancedLight::GetVolumeShift, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeShift));
    c9.def("SetVolumeShift", &AdvancedLight::SetVolumeShift, "shift"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeShift));
    
    c9.def_property("VolumeIntensity", &AdvancedLight::GetVolumeIntensity, &AdvancedLight::SetVolumeIntensity);
    c9.def("GetVolumeIntensity", &AdvancedLight::GetVolumeIntensity);
    c9.def("SetVolumeIntensity", &AdvancedLight::SetVolumeIntensity, "intensity"_a);
    
    c9.def_property("VolumeHeightInMeters", &AdvancedLight::GetVolumeHeightInMeters, &AdvancedLight::SetVolumeHeightInMeters);
    c9.def("GetVolumeHeightInMeters", &AdvancedLight::GetVolumeHeightInMeters, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeHeightInMeters));
    c9.def("SetVolumeHeightInMeters", &AdvancedLight::SetVolumeHeightInMeters, "height"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeHeightInMeters));
    
    c9.def_property("VolumeRadiusBaseInMeters", &AdvancedLight::GetVolumeRadiusBaseInMeters, &AdvancedLight::SetVolumeRadiusBaseInMeters);
    c9.def("GetVolumeRadiusBaseInMeters", &AdvancedLight::GetVolumeRadiusBaseInMeters, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeRadiusBaseInMeters));
    c9.def("SetVolumeRadiusBaseInMeters", &AdvancedLight::SetVolumeRadiusBaseInMeters, "radius"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeRadiusBaseInMeters));
    
    c9.def_property("VolumeAffectDiffuse", &AdvancedLight::GetVolumeAffectDiffuse, &AdvancedLight::SetVolumeAffectDiffuse);
    c9.def("GetVolumeAffectDiffuse", &AdvancedLight::GetVolumeAffectDiffuse, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeAffectDiffuse));
    c9.def("SetVolumeAffectDiffuse", &AdvancedLight::SetVolumeAffectDiffuse, "diffuse"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeAffectDiffuse));
    
    c9.def_property("VolumeAffectSpecular", &AdvancedLight::GetVolumeAffectSpecular, &AdvancedLight::SetVolumeAffectSpecular);
    c9.def("GetVolumeAffectSpecular", &AdvancedLight::GetVolumeAffectSpecular, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeAffectSpecular));
    c9.def("SetVolumeAffectSpecular", &AdvancedLight::SetVolumeAffectSpecular, "specular"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeAffectSpecular));
    
    c9.def_property("VolumeAffectCaustics", &AdvancedLight::GetVolumeAffectCaustics, &AdvancedLight::SetVolumeAffectCaustics);
    c9.def("GetVolumeAffectCaustics", &AdvancedLight::GetVolumeAffectCaustics, DOC(Bentley, DgnPlatform, AdvancedLight, GetVolumeAffectCaustics));
    c9.def("SetVolumeAffectCaustics", &AdvancedLight::SetVolumeAffectCaustics, "scale"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetVolumeAffectCaustics));
    
    c9.def_property("SpreadAngleInRadians", &AdvancedLight::GetSpreadAngleInRadians, &AdvancedLight::SetSpreadAngleInRadians);
    c9.def("GetSpreadAngleInRadians", &AdvancedLight::GetSpreadAngleInRadians, DOC(Bentley, DgnPlatform, AdvancedLight, GetSpreadAngleInRadians));
    c9.def("SetSpreadAngleInRadians", &AdvancedLight::SetSpreadAngleInRadians, "angle"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetSpreadAngleInRadians));
    
    c9.def_property_readonly("ScatterColor", &AdvancedLight::GetScatterColor);
    c9.def("GetScatterColor", &AdvancedLight::GetScatterColor, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AdvancedLight, GetScatterColor));
    
    c9.def("SetCastsShadows", &AdvancedLight::SetCastsShadows, "castsShadows"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetCastsShadows));
    
    c9.def_property("ShadowType", &AdvancedLight::GetShadowType, &AdvancedLight::SetShadowType);
    c9.def("GetShadowType", &AdvancedLight::GetShadowType, DOC(Bentley, DgnPlatform, AdvancedLight, GetShadowType));
    c9.def("SetShadowType", &AdvancedLight::SetShadowType, "type"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetShadowType));
    
    c9.def_property("DeepShadowSamples", &AdvancedLight::GetDeepShadowSamples, &AdvancedLight::SetDeepShadowSamples);
    c9.def("GetDeepShadowSamples", &AdvancedLight::GetDeepShadowSamples, DOC(Bentley, DgnPlatform, AdvancedLight, GetDeepShadowSamples));
    c9.def("SetDeepShadowSamples", &AdvancedLight::SetDeepShadowSamples, "samples"_a, DOC(Bentley, DgnPlatform, AdvancedLight, SetDeepShadowSamples));
    
    c9.def_property_readonly("ShadowColor", &AdvancedLight::GetShadowColor);
    c9.def("GetShadowColor", &AdvancedLight::GetShadowColor, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AdvancedLight, GetShadowColor));
        
    //===================================================================================
    // struct SolarLight
    py::class_< SolarLight, RefCountedPtr< SolarLight>, AdvancedLight> c10(m, "SolarLight");

    if (true)
        {
        //===================================================================================
        // enum SolarType
        py::enum_< SolarLight::SolarType>(c10, "SolarType", py::arithmetic())
            .value("eSOLARTYPE_TimeLocation", SolarLight::SOLARTYPE_TimeLocation)
            .value("eSOLARTYPE_Direction", SolarLight::SOLARTYPE_Direction)
            .export_values();
        }

    c10.def_static("Create", &SolarLight::Create, "solarLight"_a, DOC(Bentley, DgnPlatform, SolarLight, Create));
    
    c10.def_property("SolarType", &SolarLight::GetSolarType, &SolarLight::SetSolarType);
    c10.def("GetSolarType", &SolarLight::GetSolarType, DOC(Bentley, DgnPlatform, SolarLight, GetSolarType));
    c10.def("SetSolarType", &SolarLight::SetSolarType, "type"_a, DOC(Bentley, DgnPlatform, SolarLight, SetSolarType));
    
    c10.def_property("Hour", &SolarLight::GetHour, &SolarLight::SetHour);
    c10.def("GetHour", &SolarLight::GetHour, DOC(Bentley, DgnPlatform, SolarLight, GetHour));
    c10.def("SetHour", &SolarLight::SetHour, "hour"_a, DOC(Bentley, DgnPlatform, SolarLight, SetHour));
    
    c10.def_property("Minute", &SolarLight::GetMinute, &SolarLight::SetMinute);
    c10.def("GetMinute", &SolarLight::GetMinute, DOC(Bentley, DgnPlatform, SolarLight, GetMinute));
    c10.def("SetMinute", &SolarLight::SetMinute, "minute"_a, DOC(Bentley, DgnPlatform, SolarLight, SetMinute));
    
    c10.def_property("Day", &SolarLight::GetDay, &SolarLight::SetDay);
    c10.def("GetDay", &SolarLight::GetDay, DOC(Bentley, DgnPlatform, SolarLight, GetDay));
    c10.def("SetDay", &SolarLight::SetDay, "day"_a, DOC(Bentley, DgnPlatform, SolarLight, SetDay));
    
    c10.def_property("Month", &SolarLight::GetMonth, &SolarLight::SetMonth);
    c10.def("GetMonth", &SolarLight::GetMonth, DOC(Bentley, DgnPlatform, SolarLight, GetMonth));
    c10.def("SetMonth", &SolarLight::SetMonth, "month"_a, DOC(Bentley, DgnPlatform, SolarLight, SetMonth));
    
    c10.def_property("Year", &SolarLight::GetYear, &SolarLight::SetYear);
    c10.def("GetYear", &SolarLight::GetYear, DOC(Bentley, DgnPlatform, SolarLight, GetYear));
    c10.def("SetYear", &SolarLight::SetYear, "year"_a, DOC(Bentley, DgnPlatform, SolarLight, SetYear));
    
    c10.def_property("IsUseDaylightSavings", &SolarLight::UseDaylightSavings, &SolarLight::SetUseDaylightSavings);
    c10.def("UseDaylightSavings", &SolarLight::UseDaylightSavings, DOC(Bentley, DgnPlatform, SolarLight, UseDaylightSavings));
    c10.def("SetUseDaylightSavings", &SolarLight::SetUseDaylightSavings, "use"_a, DOC(Bentley, DgnPlatform, SolarLight, SetUseDaylightSavings));
    
    c10.def_property("ColorPhysicallyBased", &SolarLight::IsColorPhysicallyBased, &SolarLight::SetIsColorPhysicallyBased);
    c10.def("IsColorPhysicallyBased", &SolarLight::IsColorPhysicallyBased, DOC(Bentley, DgnPlatform, SolarLight, IsColorPhysicallyBased));
    c10.def("SetIsColorPhysicallyBased", &SolarLight::SetIsColorPhysicallyBased, "usePhysicColor"_a, DOC(Bentley, DgnPlatform, SolarLight, SetIsColorPhysicallyBased));
    
    c10.def_property("Cloudiness", &SolarLight::GetCloudiness, &SolarLight::SetCloudiness);
    c10.def("GetCloudiness", &SolarLight::GetCloudiness, DOC(Bentley, DgnPlatform, SolarLight, GetCloudiness));
    c10.def("SetCloudiness", &SolarLight::SetCloudiness, "cloudiness"_a, DOC(Bentley, DgnPlatform, SolarLight, SetCloudiness));
    
    c10.def_property("Turbidity", &SolarLight::GetTurbidity, &SolarLight::SetTurbidity);
    c10.def("GetTurbidity", &SolarLight::GetTurbidity, DOC(Bentley, DgnPlatform, SolarLight, GetTurbidity));
    c10.def("SetTurbidity", &SolarLight::SetTurbidity, "turbidity"_a, DOC(Bentley, DgnPlatform, SolarLight, SetTurbidity));
    
    c10.def_property("AzimuthAngle", &SolarLight::GetAzimuthAngle, &SolarLight::SetAzimuthAngle);
    c10.def("GetAzimuthAngle", &SolarLight::GetAzimuthAngle, DOC(Bentley, DgnPlatform, SolarLight, GetAzimuthAngle));
    c10.def("SetAzimuthAngle", &SolarLight::SetAzimuthAngle, "angle"_a, DOC(Bentley, DgnPlatform, SolarLight, SetAzimuthAngle));
    
    c10.def_property("AltitudeAngle", &SolarLight::GetAltitudeAngle, &SolarLight::SetAltitudeAngle);
    c10.def("GetAltitudeAngle", &SolarLight::GetAltitudeAngle, DOC(Bentley, DgnPlatform, SolarLight, GetAltitudeAngle));
    c10.def("SetAltitudeAngle", &SolarLight::SetAltitudeAngle, "angle"_a, DOC(Bentley, DgnPlatform, SolarLight, SetAltitudeAngle));
    
    c10.def_property_readonly("VectorOverride", &SolarLight::GetVectorOverride);
    c10.def("GetVectorOverride", &SolarLight::GetVectorOverride, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SolarLight, GetVectorOverride));
    
    c10.def_property_readonly("GeoLocation", &SolarLight::GetGeoLocation);
    c10.def("GetGeoLocation", &SolarLight::GetGeoLocation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SolarLight, GetGeoLocation));
    
    c10.def_property("GmtOffset", &SolarLight::GetGmtOffset, &SolarLight::SetGmtOffset);
    c10.def("GetGmtOffset", &SolarLight::GetGmtOffset, DOC(Bentley, DgnPlatform, SolarLight, GetGmtOffset));
    c10.def("SetGmtOffset", &SolarLight::SetGmtOffset, "offset"_a, DOC(Bentley, DgnPlatform, SolarLight, SetGmtOffset));


    //===================================================================================
    // struct LightElement
    py::class_< LightElement, RefCountedPtr< LightElement>, AdvancedLight> c12(m, "LightElement");

    c12.def(py::init(&LightElement::Create), "light"_a);
    c12.def_static("LoadFromElement", py::overload_cast<ElementRefP>(&LightElement::LoadFromElement), "element"_a, DOC(Bentley, DgnPlatform, LightElement, LoadFromElement));
    c12.def_static("LoadFromElement", py::overload_cast<ElementHandleCR>(&LightElement::LoadFromElement), "eh"_a, DOC(Bentley, DgnPlatform, LightElement, LoadFromElement));
    c12.def_property_readonly("ElementRef", &LightElement::GetElementRef);
    c12.def("GetElementRef", &LightElement::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElement, GetElementRef));
    
    c12.def_property("ModelRef", &LightElement::GetModelRefP, py::cpp_function(&LightElement::SetModelRef, py::keep_alive<1, 2>()));
    c12.def("GetModelRef", &LightElement::GetModelRefP, py::return_value_policy::reference_internal);
    c12.def("SetModelRef", &LightElement::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, LightElement, SetModelRef));
    
    c12.def_property("Name", &LightElement::GetName, py::cpp_function(&LightElement::SetName));
    c12.def("GetName", &LightElement::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElement, GetName));
    c12.def("SetName", &LightElement::SetName, "name"_a, DOC(Bentley, DgnPlatform, LightElement, SetName));
    
    c12.def_property("PresetName", &LightElement::GetPresetName, py::cpp_function(&LightElement::SetPresetName));
    c12.def("GetPresetName", &LightElement::GetPresetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElement, GetPresetName));
    c12.def("SetPresetName", &LightElement::SetPresetName, "name"_a, DOC(Bentley, DgnPlatform, LightElement, SetPresetName));
    
    c12.def_property_readonly("Origin", &LightElement::GetOrigin);
    c12.def("GetOrigin", &LightElement::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElement, GetOrigin));
    
    c12.def_property("UseLightAttenuate", &LightElement::DoesLightAttenuate, &LightElement::SetLightAttenuates);
    c12.def("DoesLightAttenuate", &LightElement::DoesLightAttenuate, DOC(Bentley, DgnPlatform, LightElement, DoesLightAttenuate));
    c12.def("SetLightAttenuate", &LightElement::SetLightAttenuates, "attenuates"_a);
    
    c12.def_property("AttenuationDistance", &LightElement::GetAttenuationDistance, &LightElement::SetAttenuationDistance);
    c12.def("GetAttenuationDistance", &LightElement::GetAttenuationDistance, DOC(Bentley, DgnPlatform, LightElement, GetAttenuationDistance));
    c12.def("SetAttenuationDistance", &LightElement::SetAttenuationDistance, "distance"_a, DOC(Bentley, DgnPlatform, LightElement, SetAttenuationDistance));
    
    c12.def("SupportsIes", &LightElement::SupportsIes, DOC(Bentley, DgnPlatform, LightElement, SupportsIes));
    
    c12.def_property("IsUsesIesData", &LightElement::UsesIesData, &LightElement::SetUsesIesData);
    c12.def("UsesIesData", &LightElement::UsesIesData, DOC(Bentley, DgnPlatform, LightElement, UsesIesData));
    c12.def("SetUsesIesData", &LightElement::SetUsesIesData, "useIes"_a, DOC(Bentley, DgnPlatform, LightElement, SetUsesIesData));
    
    c12.def_property("IesFileName", &LightElement::GetIesFileName, py::cpp_function(&LightElement::SetIesFileName));
    c12.def("GetIesFileName", &LightElement::GetIesFileName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElement, GetIesFileName));
    c12.def("SetIesFileName", &LightElement::SetIesFileName, "fileName"_a, DOC(Bentley, DgnPlatform, LightElement, SetIesFileName));
    
    c12.def_property("IesRotation", &LightElement::GetIesRotation, &LightElement::SetIesRotation);
    c12.def("GetIesRotation", &LightElement::GetIesRotation, DOC(Bentley, DgnPlatform, LightElement, GetIesRotation));
    c12.def("SetIesRotation", &LightElement::SetIesRotation, "rotation"_a, DOC(Bentley, DgnPlatform, LightElement, SetIesRotation));
    
    c12.def("GetRMatrix", &LightElement::GetRMatrix, "rMatrix"_a, DOC(Bentley, DgnPlatform, LightElement, GetRMatrix));
    c12.def("Save", &LightElement::Save, "transform"_a = nullptr, DOC(Bentley, DgnPlatform, LightElement, Save));    

    //===================================================================================
    // struct DistantLight
    py::class_< DistantLight, DistantLightPtr, LightElement> c13(m, "DistantLight");

    c13.def(py::init(&DistantLight::Create));
    c13.def_property_readonly("Direction", &DistantLight::GetDirection);
    c13.def("GetDirection", &DistantLight::GetDirection, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DistantLight, GetDirection));

    //===================================================================================
    // struct PointLight
    py::class_< PointLight, PointLightPtr, LightElement> c14(m, "PointLight");

    c14.def(py::init(&PointLight::Create));
    
    c14.def_property("BulbSizeInUors", &PointLight::GetBulbSizeInUors, &PointLight::SetBulbSizeInUors);
    c14.def("GetBulbSizeInUors", &PointLight::GetBulbSizeInUors, DOC(Bentley, DgnPlatform, PointLight, GetBulbSizeInUors));
    c14.def("SetBulbSizeInUors", &PointLight::SetBulbSizeInUors, "size"_a, DOC(Bentley, DgnPlatform, PointLight, SetBulbSizeInUors));

    c14.def_property("BulbCount", &PointLight::GetBulbCount, &PointLight::SetBulbCount);
    c14.def("GetBulbCount", &PointLight::GetBulbCount, DOC(Bentley, DgnPlatform, PointLight, GetBulbCount));
    c14.def("SetBulbCount", &PointLight::SetBulbCount, "count"_a, DOC(Bentley, DgnPlatform, PointLight, SetBulbCount));

    //===================================================================================
    // struct SpotLight
    py::class_< SpotLight, SpotLightPtr, LightElement> c15(m, "SpotLight");

    c15.def(py::init(&SpotLight::Create));
    
    c15.def_property("DeltaAngleInRadians", &SpotLight::GetDeltaAngleInRadians, &SpotLight::SetDeltaAngleInRadians);
    c15.def("GetDeltaAngleInRadians", &SpotLight::GetDeltaAngleInRadians, DOC(Bentley, DgnPlatform, SpotLight, GetDeltaAngleInRadians));
    c15.def("SetDeltaAngleInRadians", &SpotLight::SetDeltaAngleInRadians, "angle"_a, DOC(Bentley, DgnPlatform, SpotLight, SetDeltaAngleInRadians));
    
    c15.def_property("OuterAngleInRadians", &SpotLight::GetOuterAngleInRadians, &SpotLight::SetOuterAngleInRadians);
    c15.def("GetOuterAngleInRadians", &SpotLight::GetOuterAngleInRadians, DOC(Bentley, DgnPlatform, SpotLight, GetOuterAngleInRadians));
    c15.def("SetOuterAngleInRadians", &SpotLight::SetOuterAngleInRadians, "angle"_a, DOC(Bentley, DgnPlatform, SpotLight, SetOuterAngleInRadians));
    
    c15.def_property_readonly("InnerAngleInRadians", &SpotLight::GetInnerAngleInRadians);
    c15.def("GetInnerAngleInRadians", &SpotLight::GetInnerAngleInRadians, DOC(Bentley, DgnPlatform, SpotLight, GetInnerAngleInRadians));
    
    c15.def_property("BulbSizeInUors", &SpotLight::GetBulbSizeInUors, &SpotLight::SetBulbSizeInUors);
    c15.def("GetBulbSizeInUors", &SpotLight::GetBulbSizeInUors, DOC(Bentley, DgnPlatform, SpotLight, GetBulbSizeInUors));
    c15.def("SetBulbSizeInUors", &SpotLight::SetBulbSizeInUors, "size"_a, DOC(Bentley, DgnPlatform, SpotLight, SetBulbSizeInUors));
    
    c15.def_property("BulbCount", &SpotLight::GetBulbCount, &SpotLight::SetBulbCount);
    c15.def("GetBulbCount", &SpotLight::GetBulbCount, DOC(Bentley, DgnPlatform, SpotLight, GetBulbCount));
    c15.def("SetBulbCount", &SpotLight::SetBulbCount, "count"_a, DOC(Bentley, DgnPlatform, SpotLight, SetBulbCount));
    
    c15.def_property_readonly("Direction", &SpotLight::GetDirection);
    c15.def("GetDirection", &SpotLight::GetDirection, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SpotLight, GetDirection));

    //===================================================================================
    // struct AreaLight
    py::class_< AreaLight, AreaLightPtr, LightElement> c16(m, "AreaLight");

    c16.def(py::init(&AreaLight::Create));
    
    c16.def_property("BulbCount", &AreaLight::GetBulbCount, &AreaLight::SetBulbCount);
    c16.def("GetBulbCount", &AreaLight::GetBulbCount, DOC(Bentley, DgnPlatform, AreaLight, GetBulbCount));
    c16.def("SetBulbCount", &AreaLight::SetBulbCount, "count"_a, DOC(Bentley, DgnPlatform, AreaLight, SetBulbCount));
    
    c16.def_property_readonly("Direction", &AreaLight::GetDirection);
    c16.def("GetDirection", &AreaLight::GetDirection, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AreaLight, GetDirection));
    
    c16.def_property_readonly("LightGeometry", &AreaLight::GetLightGeometry);
    c16.def("GetLightGeometry", &AreaLight::GetLightGeometry, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, AreaLight, GetLightGeometry));
    c16.def("SaveNewLight", &AreaLight::SaveNewLight, "areaGeometryEeh"_a, DOC(Bentley, DgnPlatform, AreaLight, SaveNewLight));

    //===================================================================================
    // struct SkyOpeningLight
    py::class_< SkyOpeningLight, SkyOpeningLightPtr, LightElement> c17(m, "SkyOpeningLight");

    c17.def(py::init(&SkyOpeningLight::Create));
    
    c17.def_property("MinimumSamples", &SkyOpeningLight::GetMinimumSamples, &SkyOpeningLight::SetMinimumSamples);
    c17.def("GetMinimumSamples", &SkyOpeningLight::GetMinimumSamples, DOC(Bentley, DgnPlatform, SkyOpeningLight, GetMinimumSamples));
    c17.def("SetMinimumSamples", &SkyOpeningLight::SetMinimumSamples, "minSamples"_a, DOC(Bentley, DgnPlatform, SkyOpeningLight, SetMinimumSamples));
    
    c17.def_property("MaximumSamples", &SkyOpeningLight::GetMaximumSamples, &SkyOpeningLight::SetMaximumSamples);
    c17.def("GetMaximumSamples", &SkyOpeningLight::GetMaximumSamples, DOC(Bentley, DgnPlatform, SkyOpeningLight, GetMaximumSamples));
    c17.def("SetMaximumSamples", &SkyOpeningLight::SetMaximumSamples, "maxSamples"_a, DOC(Bentley, DgnPlatform, SkyOpeningLight, SetMaximumSamples));
    
    c17.def_property_readonly("Direction", &SkyOpeningLight::GetDirection);
    c17.def("GetDirection", &SkyOpeningLight::GetDirection, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SkyOpeningLight, GetDirection));
    c17.def("SaveNewLight", &SkyOpeningLight::SaveNewLight, "skyOpeningGeometryEEh"_a, DOC(Bentley, DgnPlatform, SkyOpeningLight, SaveNewLight));

    //===================================================================================
    // struct LightElementCollection
    py::class_< LightElementCollection, RefCountedPtr<LightElementCollection> > c18(m, "LightElementCollection", py::multiple_inheritance());

    c18.def("Find", py::overload_cast<ElementId>(&LightElementCollection::Find, py::const_), "id"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElementCollection, Find));
    
    c18.def_property_readonly("ModelRef", &LightElementCollection::GetModelRef);
    c18.def("GetModelRef", &LightElementCollection::GetModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightElementCollection, GetModelRef));
    
    c18.def("__len__", &LightElementCollection::Size);    
    c18.def("__iter__", [] (LightElementCollection& self) { return py::make_iterator(self.begin(), self.end()); });

    //===================================================================================
    // struct ModelingLightCollection
    py::class_< ModelingLightCollection, RefCountedPtr<ModelingLightCollection>, LightElementCollection> c19(m, "ModelingLightCollection");

    c19.def("InsertLightElement", [] (ModelingLightCollection& self, LightElementP light)
            { 
            LightElementPtr lightPtr(light);
            self.InsertLightElement(lightPtr); 
            }, "light"_a, DOC(Bentley, DgnPlatform, ModelingLightCollection, InsertLightElement));

    c19.def("SetModelRef", &ModelingLightCollection::SetModelRef, "modelRef"_a, DOC(Bentley, DgnPlatform, ModelingLightCollection, SetModelRef));

    //===================================================================================
    // struct LightSetupEntry
    py::class_< LightSetupEntry, LightSetupEntryPtr> c20(m, "LightSetupEntry", py::multiple_inheritance());

    c20.def("InitDefaults", &LightSetupEntry::InitDefaults, DOC(Bentley, DgnPlatform, LightSetupEntry, InitDefaults));
    c20.def("__eq__", [] (LightSetupEntryCR self, LightSetupEntryCR other) { return self.Equals(other); });
    c20.def("Copy", &LightSetupEntry::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, LightSetupEntry, Copy));
    
    c20.def_property("Enabled", &LightSetupEntry::IsEnabled, &LightSetupEntry::SetIsEnabled);
    c20.def("IsEnabled", &LightSetupEntry::IsEnabled, DOC(Bentley, DgnPlatform, LightSetupEntry, IsEnabled));
    c20.def("SetIsEnabled", &LightSetupEntry::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, LightSetupEntry, SetIsEnabled));
    
    c20.def_property("Intensity", &LightSetupEntry::GetIntensity, &LightSetupEntry::SetIntensity);
    c20.def("GetIntensity", &LightSetupEntry::GetIntensity, DOC(Bentley, DgnPlatform, LightSetupEntry, GetIntensity));
    c20.def("SetIntensity", &LightSetupEntry::SetIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, LightSetupEntry, SetIntensity));

    //===================================================================================
    // struct LightSetupEntryCollection
    py::class_< LightSetupEntryCollection, std::unique_ptr< LightSetupEntryCollection, py::nodelete> > c21(m, "LightSetupEntryCollection");

    c21.def("InitDefaults", &LightSetupEntryCollection::InitDefaults, DOC(Bentley, DgnPlatform, LightSetupEntryCollection, InitDefaults));
    c21.def("__eq__", [] (LightSetupEntryCollectionCR self, LightSetupEntryCollectionCR other) { return self.Equals(other); });
    c21.def("Copy", &LightSetupEntryCollection::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, LightSetupEntryCollection, Copy));
    c21.def("__len__", &LightSetupEntryCollection::Size);
    c21.def("GetEntry", &LightSetupEntryCollection::GetEntryCP, "id"_a, py::return_value_policy::reference_internal);
    c21.def("DeleteEntry", &LightSetupEntryCollection::DeleteEntry, "id"_a, DOC(Bentley, DgnPlatform, LightSetupEntryCollection, DeleteEntry));
    c21.def("AddEntry", &LightSetupEntryCollection::AddEntry, "id"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetupEntryCollection, AddEntry));
    c21.def("SynchToLightList", &LightSetupEntryCollection::SynchToLightList, "rootModelRef"_a, "useCurentLightValue"_a = false, DOC(Bentley, DgnPlatform, LightSetupEntryCollection, SynchToLightList));
    c21.def("__iter__", [] (LightSetupEntryCollection& self) { return py::make_iterator(self.begin(), self.end()); });

    //===================================================================================
    // struct LightSetup
    py::class_< LightSetup, LightSetupPtr> c22(m, "LightSetup", py::multiple_inheritance());

    c22.def("InitDefaults", &LightSetup::InitDefaults, DOC(Bentley, DgnPlatform, LightSetup, InitDefaults));
    c22.def("__eq__", [] (LightSetupCR self, LightSetupCR other) { return self.Equals(other); });
    c22.def("Copy", &LightSetup::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, LightSetup, Copy));
    c22.def(py::init(&LightSetup::Create));

    c22.def_property("Name", py::cpp_function(&LightSetup::GetName, py::return_value_policy::reference_internal), &LightSetup::SetName);
    c22.def("GetName", &LightSetup::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetup, GetName));
    c22.def("SetName", &LightSetup::SetName, "name"_a, DOC(Bentley, DgnPlatform, LightSetup, SetName));

    c22.def_property_readonly("SolarLight", &LightSetup::GetSolarLight);
    c22.def("GetSolarLight", &LightSetup::GetSolarLight, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetup, GetSolarLight));
    
    c22.def_property_readonly("AmbientLight", &LightSetup::GetAmbientLight);
    c22.def("GetAmbientLight", &LightSetup::GetAmbientLight, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetup, GetAmbientLight));
    
    c22.def_property_readonly("FlashLight", &LightSetup::GetFlashLight);
    c22.def("GetFlashLight", &LightSetup::GetFlashLight, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetup, GetFlashLight));
    
    c22.def_property_readonly("SkyDomeLight", &LightSetup::GetSkyDomeLight);
    c22.def("GetSkyDomeLight", &LightSetup::GetSkyDomeLight, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetup, GetSkyDomeLight));
    c22.def_property_readonly("Entries", &LightSetup::GetEntries);
    c22.def("GetEntries", &LightSetup::GetEntries, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightSetup, GetEntries));
    
    c22.def_property("IsUseFixedAdaptationForView", &LightSetup::UseFixedAdaptationForView, &LightSetup::SetUseFixedAdaptationForView);
    c22.def("UseFixedAdaptationForView", &LightSetup::UseFixedAdaptationForView, DOC(Bentley, DgnPlatform, LightSetup, UseFixedAdaptationForView));
    c22.def("SetUseFixedAdaptationForView", &LightSetup::SetUseFixedAdaptationForView, "useAdaper"_a, DOC(Bentley, DgnPlatform, LightSetup, SetUseFixedAdaptationForView));
    
    c22.def_property("AdaptationLevelForView", &LightSetup::GetAdaptationLevelForView, &LightSetup::SetAdaptationLevelForView);
    c22.def("GetAdaptationLevelForView", &LightSetup::GetAdaptationLevelForView, DOC(Bentley, DgnPlatform, LightSetup, GetAdaptationLevelForView));
    c22.def("SetAdaptationLevelForView", &LightSetup::SetAdaptationLevelForView, "level"_a, DOC(Bentley, DgnPlatform, LightSetup, SetAdaptationLevelForView));
    
    c22.def_property("BrightnessMultiplierForView", &LightSetup::GetBrightnessMultiplierForView, &LightSetup::SetBrightnessMultiplierForView);
    c22.def("GetBrightnessMultiplierForView", &LightSetup::GetBrightnessMultiplierForView, DOC(Bentley, DgnPlatform, LightSetup, GetBrightnessMultiplierForView));
    c22.def("SetBrightnessMultiplierForView", &LightSetup::SetBrightnessMultiplierForView, "multiplier"_a, DOC(Bentley, DgnPlatform, LightSetup, SetBrightnessMultiplierForView));
    
    c22.def_property_readonly("ElementId", &LightSetup::GetElementId);
    c22.def("GetElementId", &LightSetup::GetElementId, DOC(Bentley, DgnPlatform, LightSetup, GetElementId));
    c22.def_property("IsUseFixedAdaptationForLuxology", &LightSetup::UseFixedAdaptationForLuxology, &LightSetup::SetUseFixedAdaptationForLuxology);
    c22.def("UseFixedAdaptationForLuxology", &LightSetup::UseFixedAdaptationForLuxology, DOC(Bentley, DgnPlatform, LightSetup, UseFixedAdaptationForLuxology));
    c22.def("SetUseFixedAdaptationForLuxology", &LightSetup::SetUseFixedAdaptationForLuxology, "useAdaption"_a, DOC(Bentley, DgnPlatform, LightSetup, SetUseFixedAdaptationForLuxology));
    
    c22.def_property("AdaptationLevelForLuxology", &LightSetup::GetAdaptationLevelForLuxology, &LightSetup::SetAdaptationLevelForLuxology);
    c22.def("GetAdaptationLevelForLuxology", &LightSetup::GetAdaptationLevelForLuxology, DOC(Bentley, DgnPlatform, LightSetup, GetAdaptationLevelForLuxology));
    c22.def("SetAdaptationLevelForLuxology", &LightSetup::SetAdaptationLevelForLuxology, "level"_a, DOC(Bentley, DgnPlatform, LightSetup, SetAdaptationLevelForLuxology));
    
    c22.def_property("BrightnessMultiplierForLuxology", &LightSetup::GetBrightnessMultiplierForLuxology, &LightSetup::SetBrightnessMultiplierForLuxology);
    c22.def("GetBrightnessMultiplierForLuxology", &LightSetup::GetBrightnessMultiplierForLuxology, DOC(Bentley, DgnPlatform, LightSetup, GetBrightnessMultiplierForLuxology));
    c22.def("SetBrightnessMultiplierForLuxology", &LightSetup::SetBrightnessMultiplierForLuxology, "multiplier"_a, DOC(Bentley, DgnPlatform, LightSetup, SetBrightnessMultiplierForLuxology));
    
    c22.def_property("ContrastForLuxology", &LightSetup::GetContrastForLuxology, &LightSetup::SetContrastForLuxology);
    c22.def("GetContrastForLuxology", &LightSetup::GetContrastForLuxology, DOC(Bentley, DgnPlatform, LightSetup, GetContrastForLuxology));
    c22.def("SetContrastForLuxology", &LightSetup::SetContrastForLuxology, "contrast"_a, DOC(Bentley, DgnPlatform, LightSetup, SetContrastForLuxology));
    
    c22.def_property("GammaForLuxology", &LightSetup::GetGammaForLuxology, &LightSetup::SetGammaForLuxology);
    c22.def("GetGammaForLuxology", &LightSetup::GetGammaForLuxology, DOC(Bentley, DgnPlatform, LightSetup, GetGammaForLuxology));
    c22.def("SetGammaForLuxology", &LightSetup::SetGammaForLuxology, "gamma"_a, DOC(Bentley, DgnPlatform, LightSetup, SetGammaForLuxology));
    
    c22.def_property("IsUseHistogramForLuxology", &LightSetup::UseHistogramForLuxology, &LightSetup::SetUseHistogramForLuxology);    
    c22.def("UseHistogramForLuxology", &LightSetup::UseHistogramForLuxology, DOC(Bentley, DgnPlatform, LightSetup, UseHistogramForLuxology));
    c22.def("SetUseHistogramForLuxology", &LightSetup::SetUseHistogramForLuxology, "use"_a, DOC(Bentley, DgnPlatform, LightSetup, SetUseHistogramForLuxology));
    
    c22.def("IsActiveSetup", &LightSetup::IsActiveSetup, DOC(Bentley, DgnPlatform, LightSetup, IsActiveSetup));    
    c22.def("IsModelingSetup", &LightSetup::IsModelingSetup, DOC(Bentley, DgnPlatform, LightSetup, IsModelingSetup));
    
    c22.def_property("AutoCorrectColorMapGamma", &LightSetup::GetAutoCorrectColorMapGamma, &LightSetup::SetAutoCorrectColorMapGamma);
    c22.def("GetAutoCorrectColorMapGamma", &LightSetup::GetAutoCorrectColorMapGamma, DOC(Bentley, DgnPlatform, LightSetup, GetAutoCorrectColorMapGamma));
    c22.def("SetAutoCorrectColorMapGamma", &LightSetup::SetAutoCorrectColorMapGamma, "autoCorrect"_a, DOC(Bentley, DgnPlatform, LightSetup, SetAutoCorrectColorMapGamma));
    
    c22.def_property("DragoExposure", &LightSetup::GetDragoExposure, &LightSetup::SetDragoExposure);
    c22.def("GetDragoExposure", &LightSetup::GetDragoExposure, DOC(Bentley, DgnPlatform, LightSetup, GetDragoExposure));
    c22.def("SetDragoExposure", &LightSetup::SetDragoExposure, "exposure"_a, DOC(Bentley, DgnPlatform, LightSetup, SetDragoExposure));
    
    c22.def_property("ReinhardIntensity", &LightSetup::GetReinhardIntensity, &LightSetup::SetReinhardIntensity);
    c22.def("GetReinhardIntensity", &LightSetup::GetReinhardIntensity, DOC(Bentley, DgnPlatform, LightSetup, GetReinhardIntensity));
    c22.def("SetReinhardIntensity", &LightSetup::SetReinhardIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, LightSetup, SetReinhardIntensity));
    
    c22.def_property("ReinhardContrast", &LightSetup::GetReinhardContrast, &LightSetup::SetReinhardContrast);
    c22.def("GetReinhardContrast", &LightSetup::GetReinhardContrast, DOC(Bentley, DgnPlatform, LightSetup, GetReinhardContrast));
    c22.def("SetReinhardContrast", &LightSetup::SetReinhardContrast, "contrast"_a, DOC(Bentley, DgnPlatform, LightSetup, SetReinhardContrast));
    
    c22.def_property("FattalColorSaturation", &LightSetup::GetFattalColorSaturation, &LightSetup::SetFattalColorSaturation);
    c22.def("GetFattalColorSaturation", &LightSetup::GetFattalColorSaturation, DOC(Bentley, DgnPlatform, LightSetup, GetFattalColorSaturation));
    c22.def("SetFattalColorSaturation", &LightSetup::SetFattalColorSaturation, "colorSaturation"_a, DOC(Bentley, DgnPlatform, LightSetup, SetFattalColorSaturation));
    
    c22.def_property("FattalAttenuation", &LightSetup::GetFattalAttenuation, &LightSetup::SetFattalAttenuation);
    c22.def("GetFattalAttenuation", &LightSetup::GetFattalAttenuation, DOC(Bentley, DgnPlatform, LightSetup, GetFattalAttenuation));
    c22.def("SetFattalAttenuation", &LightSetup::SetFattalAttenuation, "attenuation"_a, DOC(Bentley, DgnPlatform, LightSetup, SetFattalAttenuation));
    
    c22.def_property("ToneMappingMode", &LightSetup::GetToneMappingMode, &LightSetup::SetToneMappingMode);
    c22.def("GetToneMappingMode", &LightSetup::GetToneMappingMode, DOC(Bentley, DgnPlatform, LightSetup, GetToneMappingMode));
    c22.def("SetToneMappingMode", &LightSetup::SetToneMappingMode, "mode"_a, DOC(Bentley, DgnPlatform, LightSetup, SetToneMappingMode));
    
    c22.def_property("NaturalFilmResponseExposure", &LightSetup::GetNaturalFilmResponseExposure, &LightSetup::SetNaturalFilmResponseExposure);
    c22.def("GetNaturalFilmResponseExposure", &LightSetup::GetNaturalFilmResponseExposure, DOC(Bentley, DgnPlatform, LightSetup, GetNaturalFilmResponseExposure));
    c22.def("SetNaturalFilmResponseExposure", &LightSetup::SetNaturalFilmResponseExposure, "exposure"_a, DOC(Bentley, DgnPlatform, LightSetup, SetNaturalFilmResponseExposure));

    //===================================================================================
    // struct LightSetupCollection
    py::class_< LightSetupCollection> c23(m, "LightSetupCollection");

    c23.def("InitDefaults", &LightSetupCollection::InitDefaults, DOC(Bentley, DgnPlatform, LightSetupCollection, InitDefaults));
    c23.def("__eq__", [] (LightSetupCollectionCR self, LightSetupCollectionCR other) { return self.Equals(other); });
    c23.def("Copy", &LightSetupCollection::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, LightSetupCollection, Copy));
    c23.def("__len__", &LightSetupCollection::Size);
    c23.def("GetLightSetup", &LightSetupCollection::GetLightSetupCP, "id"_a, py::return_value_policy::reference_internal);
    c23.def("DeleteLightSetup", &LightSetupCollection::DeleteLightSetup, "id"_a, DOC(Bentley, DgnPlatform, LightSetupCollection, DeleteLightSetup));
    c23.def("AddLightSetup", &LightSetupCollection::AddLightSetup, "id"_a, "setup"_a, DOC(Bentley, DgnPlatform, LightSetupCollection, AddLightSetup));
    c23.def("__iter__", [] (LightSetupCollection& self) { return py::make_iterator(self.begin(), self.end()); });

    //===================================================================================
    // struct LightManager
    py::class_< LightManager, std::unique_ptr< LightManager, py::nodelete> > c24(m, "LightManager");

    c24.def("ConfigureSetupFromXml", &LightManager::ConfigureSetupFromXml, "lightSetup"_a, "xml"_a, "model"_a, DOC(Bentley, DgnPlatform, LightManager, ConfigureSetupFromXml));
    c24.def("GetActiveLightSetupPtrForModel", &LightManager::GetActiveLightSetupPtrForModel, "model"_a, DOC(Bentley, DgnPlatform, LightManager, GetActiveLightSetupPtrForModel));
    c24.def("ConfigureLightSetupFromLegacySettings", &LightManager::ConfigureLightSetupFromLegacySettings, "setup"_a, "model"_a, DOC(Bentley, DgnPlatform, LightManager, ConfigureLightSetupFromLegacySettings));
    c24.def("FindLightsInModelRef", &LightManager::FindLightsInModelRef, "modelRef"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, LightManager, FindLightsInModelRef));
    c24.def("LoadSetupFromModel", &LightManager::LoadSetupFromModel, "setupName"_a, "sourceModel"_a, DOC(Bentley, DgnPlatform, LightManager, LoadSetupFromModel));
    c24.def("LoadSetupFromModelById", &LightManager::LoadSetupFromModelById, "lightSetupElemId"_a, "sourceModel"_a, DOC(Bentley, DgnPlatform, LightManager, LoadSetupFromModelById));
    c24.def("LoadModelingSetup", &LightManager::LoadModelingSetup, "sourceModel"_a, DOC(Bentley, DgnPlatform, LightManager, LoadModelingSetup));
    c24.def("GetActiveLightSetupForModel", &LightManager::GetActiveLightSetupForModel, "useModelLighting"_a, "model"_a, DOC(Bentley, DgnPlatform, LightManager, GetActiveLightSetupForModel));
    c24.def("SaveSetupToModel", &LightManager::SaveSetupToModel, "setup"_a, "saveSharedSettings"_a, "model"_a, DOC(Bentley, DgnPlatform, LightManager, SaveSetupToModel));
    c24.def("SetActiveLightSetupForModel", &LightManager::SetActiveLightSetupForModel, "setup"_a, "model"_a, DOC(Bentley, DgnPlatform, LightManager, SetActiveLightSetupForModel));
    c24.def("GetLightSetups", &LightManager::GetLightSetups, "map"_a, "sourceModel"_a, DOC(Bentley, DgnPlatform, LightManager, GetLightSetups));
    c24.def("DeleteLightSetup", &LightManager::DeleteLightSetup, "setupName"_a, "sourceModel"_a, DOC(Bentley, DgnPlatform, LightManager, DeleteLightSetup));
    c24.def_static("GetManager", &LightManager::GetManagerR, py::return_value_policy::reference);
    c24.def("GetLightingSearchPath", &LightManager::GetLightingSearchPath, "renderDgnMoniker"_a, DOC(Bentley, DgnPlatform, LightManager, GetLightingSearchPath));
    c24.def("FindIESFile", &LightManager::FindIESFile, "iesName"_a, "renderDgnFile"_a, DOC(Bentley, DgnPlatform, LightManager, FindIESFile));
    c24.def("InitializeLightName", py::overload_cast<WCharP, ElementId, DgnModelRefP, Light::LightType>(&LightManager::InitializeLightName), "lightName"_a, "elemId"_a, "modelRef"_a, "type"_a, DOC(Bentley, DgnPlatform, LightManager, InitializeLightName));
    c24.def("ScaleColorForDisplay", &LightManager::ScaleColorForDisplay, "colorToScale"_a, "isNormalized"_a, DOC(Bentley, DgnPlatform, LightManager, ScaleColorForDisplay));
    }