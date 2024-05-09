/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\materialsettings.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/MaterialSettings.h>



static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetPBREmissiveColor =R"doc(Set the PBR emissive color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetPBREmissiveColor =R"doc(Get the PBR emissive color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetPBRAmbientOcclusionMapScale =R"doc(Set the scale factor affecting the appearance of the Ambient Occlusion
map

Parameter ``[in]``:
    intensity The Ambient Occlusion map scale factor value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetPBRAmbientOcclusionMapScale =R"doc(Defines the scale factor affecting the appearance of the Ambient
Occlusion map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetPBRNormalMapScale =R"doc(Set the scale factor affecting the appearance of the Normal map

Parameter ``[in]``:
    intensity The normal map scale factor value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetPBRNormalMapScale =R"doc(Defines the scale factor affecting the appearance of the Normal map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetPBRHeightMapScale =R"doc(Set the scale factor affecting the appearance of the height map

Parameter ``[in]``:
    intensity The height map scale factor value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetPBRHeightMapScale =R"doc(Defines the scale factor affecting the appearance of the height map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetPBRRoughness =R"doc(Set the surface roughness

Parameter ``[in]``:
    intensity The surface roughness value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetPBRRoughness =R"doc(Defines the amount of incoming light that is scattered in all
directions equally.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetPBRMetalInsulatorRatio =R"doc(Set the property for the surface being metallic or dialectric, Rusty
surfaces is where this value would be inbetween 0 & 1

Parameter ``[in]``:
    intensity The diffuse value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetPBRMetalInsulatorRatio =R"doc(get the property for the surface being metallic or dialectric, Rusty
surfaces is where this value would be inbetween 0 & 1)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_IsPBRMaterial =R"doc(Get if this material is a PBR Material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetUseCutSectionMaterial =R"doc(Set if this material is to be used as a separate material for cut
sections.

Parameter ``[in]``:
    useCutSectionMaterial True to use a separate material for cut
    sections.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_UseCutSectionMaterial =R"doc(Is this material to use a separate material for cut sections.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetCutSectionMaterialPalette =R"doc(Get the palette name which contains the cut section material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetCutSectionMaterialName =R"doc(Set the material name to be used for cut sections. The maximum length
for a material name is 30 characters - if the provided name exceeds
that length, this function will return ERROR and the name will not be
changed.

Parameter ``[in]``:
    name The material name to be used for cut sections.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetCutSectionMaterialName =R"doc(Get the material name for a material to be used for cut sections.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasCustomSpecular =R"doc(Set if the material editor has a custom specular color. This is a flag
used by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasCustomSpecular =R"doc(Has the material editor has a custom specular color. This is a flag
used by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetLockRefractionRoughnessToFinish =R"doc(Set if the material editor locked roughness to finish. This is a flag
used by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_LockRefractionRoughnessToFinish =R"doc(Has the material editor locked roughness to finish. This is a flag
used by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetLockFresnelToReflect =R"doc(Set if the material editor locked fresnel to reflect. This is a flag
used by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_LockFresnelToReflect =R"doc(Has the material editor locked fresnel to reflect. This is a flag used
by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetLockFinishAndSpecular =R"doc(Set if the material editor locked finish and specular values. This is
a flag used by the GUI of MicroStation and its derivatives. Its effect
is not maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_LockFinishAndSpecular =R"doc(Has the material editor locked finish and specular values. This is a
flag used by the GUI of MicroStation and its derivatives. Its effect
is not maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetLockSpecularAndBase =R"doc(Set if the material editor locked specular and base colors. This is a
flag used by the GUI of MicroStation and its derivatives. Its effect
is not maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_LockSpecularAndBase =R"doc(Has the material editor locked specular and base colors. This is a
flag used by the GUI of MicroStation and its derivatives. Its effect
is not maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetLockEfficiency =R"doc(Set if the material editor has locked efficency. This is a flag used
by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_LockEfficiency =R"doc(Has the material editor locked efficiency. This is a flag used by the
GUI of MicroStation and its derivatives. Its effect is not maintained
when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetLockSpecularAndReflect =R"doc(Set if the material editor has locked specular and reflect. This is a
flag used by the GUI of MicroStation and its derivatives. Its effect
is not maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_LockSpecularAndReflect =R"doc(Has the material editor locked Specular and reflect. This is a flag
used by the GUI of MicroStation and its derivatives. Its effect is not
maintained when programmatically setting values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetBackFaceCulling =R"doc(Set how the faces of the elements are to be treated when processing
for luxology export

Parameter ``[in]``:
    backFaceCulling How the element is to be processed)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetBackFaceCulling =R"doc(Get how the faces of the elements are to be treated when processing
for luxology export)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetBlurRefractions =R"doc(Set if the blurry refraction values are to be used for this material

Parameter ``[in]``:
    blurRefractions True to blur reflections)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_BlurRefractions =R"doc(Are refractions to be blurred)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetBlurReflections =R"doc(Set if the blurry reflection values are to be used for this material

Parameter ``[in]``:
    blurReflections True to blur reflections)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_BlurReflections =R"doc(Are reflections to be blurred.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetRefractionRoughness =R"doc(Set the refraction roughness percentage

See also:
    GetRefractionRoughness ()

Parameter ``[in]``:
    roughness The roughness percentage. 0% is no blurry refractions.
    100% is maximum blur.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetRefractionRoughness =R"doc(This is for simulating diffused transparency similar to frosted glass.
The roughness percentage increases randomness of the direction of the
refraction rays fired.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetAbsorptionDistance =R"doc(Set the distance in meters that a ray must pass through to attain 100%
of the transparent color

Parameter ``[in]``:
    absorption The absorption distance)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetAbsorptionDistance =R"doc(Colored transparent surfaces produce different tints of color based on
the thickness of the transparent object. This setting sets the
distance in meters through the surface that the ray must travel to
attain the transparent color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetDissolveAmount =R"doc(Set the Dissolve amount.

Parameter ``[in]``:
    dissolve The percetange dissolve amount)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetDissolveAmount =R"doc(Dissolve makes the object fade from view. 100% dissolve will make the
object invisible)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetReflectionFresnel =R"doc(Set the reflection fresnel

Parameter ``[in]``:
    fresnel The reflection fresnel)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetReflectionFresnel =R"doc(Get the reflection frenel.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetScatterDistanceInMeters =R"doc(Set the scattering distance.

See also:
    GetScatterDistanceInMeters ()

Parameter ``[in]``:
    scatterDistance The distance light must travel through the surface
    to be tinted to the translucency color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetScatterDistanceInMeters =R"doc(Used with subsurface scattering/Translucency. This is the distance the
light has to travel through the surface to attain the translucent
color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetFrontWeightingAmount =R"doc(Set the front weighting amount for subsurface scattering/translucency

See also:
    GetFrontWeightingAmount ()

Parameter ``[in]``:
    frontWeighting The front weighting amount. as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetFrontWeightingAmount =R"doc(The Front Weighting setting with bias the subsurface scattering
sources towards the light source. At 50%, they scatter evenly in both
directions. At less than 50%, they scatter towards the light; less
than 50% they scatter away from the light.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetAnisotropyAmount =R"doc(Set the percentage amount of Anisotropy a surface has.

Parameter ``[in]``:
    anisotropy The anisotropy amount for the surface)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetAnisotropyAmount =R"doc(The Anisotropy value affects highlights, simulating the effect of
millions of microscopic scratches on a surface that will distort
highlights and reflections over their surface parallel to the
directions of the scratches. This is a percentage value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetClearcoatAmount =R"doc(Set the clearcoat percentage amount for the material.

Parameter ``[in]``:
    clearcoat The clearcoat amount)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetClearcoatAmount =R"doc(Get the clearcoat amount for the material. Clearcoat is a simulation
of a multi layering effect to add an unblurred untinted reflective
layer to a surface. This is a percentage value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetDispersionAmount =R"doc(Set the amount of dispersion

See also:
    GetDispersionAmount ()

Parameter ``[in]``:
    dispersion The dispersion amount)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetDispersionAmount =R"doc(Dispersion is the differing of refraction values for different
wavelengths of light. This typically seen when a prism is used to
split white light. The typical dispersion value for glass is 0.02 and
for diamond its 0.44)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetDisplacementDistanceInMillimeters =R"doc(Set the maximum displacement distance in millimeters

Parameter ``[in]``:
    distance The maximum displacement distance when using a
    displacement map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetDisplacementDistanceInMillimeters =R"doc(When using a displacement map. This value specifies the maximum height
that the displacement can reach)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetSubsurfaceSamples =R"doc(Set the number of samples for subsurface scattering/Translucency.

Parameter ``[in]``:
    samples The number of subsurface samples)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetSubsurfaceSamples =R"doc(Get the number of samples used for subsurface scattering/Translucency.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetRefractionRays =R"doc(Set the number of transmitted rays generated when an incoming ray hits
a surface.

Parameter ``[in]``:
    rays The number of transmitted rays)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetRefractionRays =R"doc(When blurry refraction is used this specifies the number of
transmitted rays generated when an incoming ray hits a surface.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetReflectionRays =R"doc(Set the number of reflection rays generated when an incoming ray hits
a surface.

Parameter ``[in]``:
    rays The number of reflection rays)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetReflectionRays =R"doc(When blurry reflections are used this specifies the number of
reflection rays generated when an incoming ray hits a surface.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetIsVisible =R"doc(Set if elements which use this material are visible

Parameter ``[in]``:
    isVisible True if elements which use this material are visible)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_IsVisible =R"doc(Are elements which use this material visible or invisible)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetCastsShadows =R"doc(Set if elements which use this material cast shadows

Parameter ``[in]``:
    castsShadows True if shadows are cast)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_CastsShadows =R"doc(Do elements which use this material cast shadows)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetTranslucencyScale =R"doc(Set the amount of light that penetrates the surface but is scattered
through out it

Parameter ``[in]``:
    scale The amount of light scattered on entering an object. 0
    (None) 1 (All))doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetTranslucencyScale =R"doc(The amount of light that penetrates the surface but is scattered
through out it)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetGlowIntensity =R"doc(Set the amount of light emmited by this material in
lumens/meterSquared

Parameter ``[in]``:
    intensity The glow value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetGlowIntensity =R"doc(Returns the amount of light emitted by this material in
lumens/meterSquared)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetRefractIndex =R"doc(Set the refractive index of the material

See also:
    GetRefractIndex ()

Parameter ``[in]``:
    index The refractive index)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetRefractIndex =R"doc(This is the refractive index of the material. It controls how light
changes direction as it passes through a transparent object.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetSpecularIntensity =R"doc(Set the amount of incoming light which is specularly reflected

Parameter ``[in]``:
    intensity The specular value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetSpecularIntensity =R"doc(Defines the amount of incoming light that is reflected in the opposite
direction of the incoming light. Values may range from 0 (dull) to 1
(shiny))doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetRoundedEdgeWidth =R"doc(Set the rounded edge width value.

Parameter ``[in]``:
    roundedEdgeWidth The rounded edge width value.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetRoundedEdgeWidth =R"doc(Defines the rounded edge width value.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetDiffuseRoughness =R"doc(Set the diffuse roughness value.

Parameter ``[in]``:
    diffuseRoughness The diffuse roughness value.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetDiffuseRoughness =R"doc(Defines the diffuse roughness value.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetDiffuseIntensity =R"doc(Set the amount of incoming light reflected in all directions equally

Parameter ``[in]``:
    intensity The diffuse value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetDiffuseIntensity =R"doc(Defines the amount of incoming light that is reflected in all
directions equally. This affects the overall brightness of the
material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetTransmitIntensity =R"doc(Set the transmit intensity

See also:
    GetTransmitIntensity ()

Parameter ``[in]``:
    intensity The transmit value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetTransmitIntensity =R"doc(Defines the amount of light which is specularly passed through the
material. Can vary from 0 (None) to 1 (Full))doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetReflectIntensity =R"doc(Set the reflect intensity

See also:
    GetReflectIntensity ()

Parameter ``[in]``:
    intensity The reflect value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetReflectIntensity =R"doc(Defines the amount of incoming light from other objects in the scene
that is reflected. Can vary from 0 (None) to 100 (Full))doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetFinishScale =R"doc(Set the finish value for the material.

See also:
    GetFinishScale ()

Parameter ``[in]``:
    scale The finish value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetFinishScale =R"doc(Get the finish value for the material. Small values result in rough
surfaces with large specular highlights. Large values result in smooth
surfaces with narrow specular highlights. Can vary from 1 (Rough) to
100 (Smooth).)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetAmbientIntensity =R"doc(Set the ambient intensity of the material

Parameter ``[in]``:
    intensity The ambient intensity of the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetAmbientIntensity =R"doc(Get the ambient intensity of the material.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetExitColor =R"doc(Set the exit color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetExitColor =R"doc(Get the exit color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetReflectColor =R"doc(Set the reflect color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetReflectColor =R"doc(Get the reflect color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetGlowColor =R"doc(Set the glow color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetGlowColor =R"doc(Get the glow color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetTranslucencyColor =R"doc(Set the translucent color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetTranslucencyColor =R"doc(Get the translucent color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetTransmitColor =R"doc(Set the transmit color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetTransmitColor =R"doc(Get the transmit color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetSpecularColor =R"doc(Set the specular color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetSpecularColor =R"doc(Get the specular color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetBaseColor =R"doc(Set the base (diffuse color) for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetBaseColor =R"doc(Get the base (diffuse color) for the material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasTransmitIntensity =R"doc(Set if the material has a transmit value

Parameter ``[in]``:
    hasTransmitIntensity True if the material has a transmit value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasTransmitIntensity =R"doc(Get if the material has a transmit value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasReflectIntensity =R"doc(Set if the material has a reflect value

Parameter ``[in]``:
    hasReflectIntensity True if the material has a reflect value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasReflectIntensity =R"doc(Get if the material has a reflect value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasRefractIndex =R"doc(Set if this material has a refractive index

Parameter ``[in]``:
    hasRefractIndex True if the material has a refractive index)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasRefractIndex =R"doc(Get if this material has a Refractive index)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasFinishScale =R"doc(Set if this material has a finish value

Parameter ``[in]``:
    hasFinishScale True if the material has a finish value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasFinishScale =R"doc(Does this material use a finish value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasSpecularIntensity =R"doc(Set if the material has a specular intensity value

Parameter ``[in]``:
    hasSpecularIntensity True if the material has a specular intensity)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasSpecularIntensity =R"doc(Does the material have a speculat intensity value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasDiffuseIntensity =R"doc(Set if the material has a diffuse intensity

Parameter ``[in]``:
    hasDiffuseIntensity True if the material has a diffuse intensity)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasDiffuseIntensity =R"doc(Does the material have a diffuse intensity value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasExitColor =R"doc(Set if the material has an exit color

Parameter ``[in]``:
    hasExitColor True if the material has an exit color, false and its
    calculated)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasExitColor =R"doc(Get if the material has a fixed exit color. Setting this to true can
be used to simplify complex transparency calculations)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasReflectColor =R"doc(Set if the material has a fixed reflect color or if it derives the
reflect color from the specular color

Parameter ``[in]``:
    hasReflectColor True if the reflect color is in this class, false,
    if it is derived from the specular color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasReflectColor =R"doc(Get if the material has a fixed reflect color or if it derives the
reflect color from the specular color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasGlowColor =R"doc(Get if the material has a fixed glow color or if it derives the glow
color from the base color

Parameter ``[in]``:
    hasGlowColor True if the glow color is in this class, false if it
    is derived from the base color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasGlowColor =R"doc(Get if the material has a fixed glow color or if it derives the glow
color from the base color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasTranslucencyColor =R"doc(Set if the material has a fixed translucency color or if it derives
the translucency color from the base color

Parameter ``[in]``:
    hasTranslucencyColor True if the translucency color is in this
    class, false if it is derived from the base color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasTranslucencyColor =R"doc(Get if the material has a fixed translucency color or if it derives
the translucency color from the base color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasTransmitColor =R"doc(Set if the material has a fixed transmit color or if it derives the
transmit color from the specular color

Parameter ``[in]``:
    hasTransmitColor True if the transmit color is in this class,
    false, if it is derived from the specular color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasTransmitColor =R"doc(Get if the material has a fixed transmit color or if it derives the
transmit color from the specular color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasSpecularColor =R"doc(Set if the material has a fixed specular color or if it derives its
specular color from the base color

Parameter ``[in]``:
    hasSpecularColor True if the specular color is in this class,
    false to get the color from the base color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasSpecularColor =R"doc(Get if the material has a fixed specular color or if it derives its
specular color from the base color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetHasBaseColor =R"doc(Set if the material has a fixed base color or if it derives its color
from the element color

Parameter ``[in]``:
    hasBaseColor True to use the base color in this class, false to
    get the color from the element)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_HasBaseColor =R"doc(Get if the material has a fixed base color or if it derives its color
from the element color)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetMaps =R"doc(Get the collection of maps)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_SetUseFur =R"doc(Switch on/off the use of fur for this material

Parameter ``[in]``:
    useFur True to enable the use of fur)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_UseFur =R"doc(Is the fur object enabled for this material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_DeleteFur =R"doc(Delete fur from this object)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_AddFur =R"doc(Add fur to this material. If this material already has fur, it will be
replaced.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetFur =R"doc(Get the MaterialFur object for these settings. If fur does not already
exist for this material, it will be added.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetMaterial =R"doc(Get the material these settings are for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_GetShaders =R"doc(Get the shader collection for this material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_Copy =R"doc(Copy the material settings from the method argument into this object

Parameter ``[in]``:
    rhs The object to copy from)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialSettings_InitDefaults =R"doc(Initialize default material settings. This will remove all maps and
make the setting contain a single shader)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetRefractIndex =R"doc(Set the refractive index of the material

See also:
    GetRefractIndex ()

Parameter ``[in]``:
    index The refractive index)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetRefractIndex =R"doc(This is the refractive index of the material. It controls how light
changes direction as it passes through a transparent object.)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetEmissiveColor =R"doc(Set the PBR emissive color for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetEmissiveColor =R"doc(Get the PBR emissive color for the material)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetAmbientOcclusionMapScale =R"doc(Set the scale factor affecting the appearance of the Ambient Occlusion
map

Parameter ``[in]``:
    intensity The Ambient Occlusion map scale factor value)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetAmbientOcclusionMapScale =R"doc(Defines the scale factor affecting the appearance of the Ambient
Occlusion map)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetNormalMapScale =R"doc(Set the scale factor affecting the appearance of the Normal map

Parameter ``[in]``:
    intensity The normal map scale factor value)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetNormalMapScale =R"doc(Defines the scale factor affecting the appearance of the Normal map)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetHeightMapScale =R"doc(Set the scale factor affecting the appearance of the Normal map

Parameter ``[in]``:
    intensity The normal map scale factor value)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetHeightMapScale =R"doc(Defines the scale factor affecting the appearance of the height map)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetRoughness =R"doc(Set the surface roughness

Parameter ``[in]``:
    intensity The surface roughness value)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetRoughness =R"doc(Defines the amount of incoming light that is scattered in all
directions equally.)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetMetalInsulatorRatio =R"doc(Set the property for the surface being metallic or dialectric, Rusty
surfaces is where this value would be inbetween 0 & 1

Parameter ``[in]``:
    intensity The diffuse value)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetMetalInsulatorRatio =R"doc(get the property for the surface being metallic or dialectric, Rusty
surfaces is where this value would be inbetween 0 & 1)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetTransmitIntensity =R"doc(Set the transmit intensity

See also:
    GetTransmitIntensity ()

Parameter ``[in]``:
    intensity The transmit value)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetTransmitIntensity =R"doc(Defines the amount of light which is specularly passed through the
material. Can vary from 0 (None) to 1 (Full))doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetBaseColor =R"doc(Set the base (diffuse color) for the material

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_SetHasBaseColor =R"doc(Set if the material has a fixed base color or if it derives its color
from the element color

Parameter ``[in]``:
    hasBaseColor True to use the base color in this class, false to
    get the color from the element)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_HasBaseColor =R"doc(Get if the material has a fixed base color or if it derives its color
from the element color)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetMaps =R"doc(Get the collection of maps)doc";

static const char * __doc_Bentley_DgnPlatform_PBRMaterialSettings_GetMaterial =R"doc(Get the material these settings are for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShaderCollection_AddShader =R"doc(Add a shader to the end of the collection.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShaderCollection_GetTopShader =R"doc(get the first shader in this collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShaderCollection_GetMaterial =R"doc(Returns:
    The containing material for these shaders.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShaderCollection_Copy =R"doc(Copy the collection from the method argument into this collection

Parameter ``[in]``:
    rhs The collection to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShaderCollection_InitDefaults =R"doc(Initialize this collection to the default empty collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetEffect =R"doc(Set the shader effect for this shader.

Parameter ``[in]``:
    effect The shader effect)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetEffect =R"doc(Get the shader effect for this shader)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetBlendMode =R"doc(Set the blend mode for this shader

Parameter ``[in]``:
    blendMode The blend mode to use)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetBlendMode =R"doc(Get the blend mode between this shader and other shaders which use the
same ShaderEffect settings)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIndirectIlluminationType =R"doc(Set the indirect illumination calculation type.

See also:
    GetIndirectIlluminationType ()

Parameter ``[in]``:
    type The type of indirect illumation calculation)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetIndirectIlluminationType =R"doc(This setting allows the type of indirect illumination calculation to
be calculated on a per material basis. The setting of None will mean
that the material will default to using the render setting value.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetOpacity =R"doc(Set the opacity of the shader

Parameter ``[in]``:
    opacity The opacity of the shader)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetOpacity =R"doc(Get the opacity of the shader. Changing this value will affect the
opacity of the entire material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIndirectIlluminationMultiplier =R"doc(Set the indirect illumination multiplier

See also:
    GetIndirectIlluminationMultiplier ()

Parameter ``[in]``:
    multiplier The multiplier value as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetIndirectIlluminationMultiplier =R"doc(Indirect Light comes from global illumination sources such as luminous
geometry, image based lighting via environments and simple bounced
light from diffuse surfaces. The indirect illumination multiplier
allows the ablility to adjust the amount of light being recieved by
geometry which uses this material. This value is a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetDirectIlluminationMultiplier =R"doc(Set the direct illumination multiplier

See also:
    GetDirectIlluminationMultiplier ()

Parameter ``[in]``:
    multiplier The multiplier value as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetDirectIlluminationMultiplier =R"doc(The direct illumation multiplier provides the ability to globally
adjust the incoming light from point, spot, area, direct lights to the
geometry using this material. The value is a percentage. This is
useful when balancing lighting in a scene)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetShadingRate =R"doc(Set the shading rate value

See also:
    GetShadingRate ()

Parameter ``[in]``:
    shadingRate The shading rate in pixels to use)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetShadingRate =R"doc(The Shading Rate determines how finely to shade each pixel in the
materials feeding the selected Shader Item during initial shading. The
default value of 1 indicates that the pixel will be evaluated once
before being evaluated for further refinement (see Refinement
Threshold). Decreasing the Shading Rate results in a more finely
evaluated pixel which generally yields longer render times. For
instance, if you change the value to .5 the pixel is effectively cut
in half horizontally and vertically and each " sub pixel " is evaluated.
In this case you have reduced the rate by half but increased the
amount of evaluation by 4 times.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsVisibleToRefractionRays =R"doc(Sets if the geometry which uses this material is visible in
refractions

Parameter ``[in]``:
    isVisible True if the geometry which uses this material visible in
    refractions)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsVisibleToRefractionRays =R"doc(Sets if the geometry which uses this material is visible in
refractions)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsVisibleToOcclusionRays =R"doc(Sets if the geometry which uses this material is visible to occlusion
rays

Parameter ``[in]``:
    isVisible True if the geometry which uses this material visible to
    occlusion rays)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsVisibleToOcclusionRays =R"doc(Is the geometry which uses this material is visible to occlusion rays)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsVisibleToReflectionRays =R"doc(Sets if the geometry which uses this material is visible in
reflections

Parameter ``[in]``:
    isVisible True if the geometry which uses this material visible in
    reflections)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsVisibleToReflectionRays =R"doc(Is the geometry which uses this material is visible in reflections)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsVisibleToIndirectRays =R"doc(Sets if the geometry which uses this material visible to indirect
illumination

Parameter ``[in]``:
    isVisible True if the geometry which uses this material visible to
    indirect illumination)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsVisibleToIndirectRays =R"doc(Is the geometry which uses this materia visible to indirect
illumination)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsVisibleToCamera =R"doc(Sets if the geometry which uses this material visible to the camera

Parameter ``[in]``:
    isVisible True if the geometry using this material is visible to
    the camera)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsVisibleToCamera =R"doc(Is the geometry which uses this material visible to the camera)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetCastsShadows =R"doc(Sets if the geometry which uses this material casts shadows

Parameter ``[in]``:
    castsShadows True for the geometry using this material to cast
    shadows)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetReceivesShadows =R"doc(Sets if the geometry which uses this material recieves shadows.

Parameter ``[in]``:
    receivesShadows True to make geometry using this material recieve
    shadows)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsInverted =R"doc(Set the inverted state for the shader

Parameter ``[in]``:
    isInverted True to invert the shader)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsInverted =R"doc(Is the shader inverted. This produces a negative effect in the image
for the layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetType =R"doc(Set the shader type

Parameter ``[in]``:
    type The type of the shader)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetType =R"doc(Get the shader type)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_SetIsEnabled =R"doc(Set this shader to be enabled

Parameter ``[in]``:
    isEnabled True to enable this shader)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_IsEnabled =R"doc(Is the shader enabled)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_GetMaterial =R"doc(Get the Material this shader is contained in)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_Copy =R"doc(Copy the contents of the passed in shader into this object

Parameter ``[in]``:
    rhs The object to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialShader_InitDefaults =R"doc(Initialize the shader to the default values.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetFurMaterialPalette =R"doc(If the fur object uses a material applied to the fur strands. This
returns the palette the material comes from)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetFurMaterialName =R"doc(Set the name of the material to use on the fur strands

Parameter ``[in]``:
    name The name of the fur material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetFurMaterialName =R"doc(If the fur object uses a material to be applied to the fur strands
this method will return the name of the material.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetFurBillboard =R"doc(Set the fur billboard setting

Parameter ``[in]``:
    billboard The type of billboarding to use)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetFurBillboard =R"doc(Get the fur billboard setting.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetSegmentCount =R"doc(Set the number of segments in each strand of fur

See also:
    GetSegmentCount ()

Parameter ``[in]``:
    count The number of segments in a fur strand)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetSegmentCount =R"doc(Get the number of segments in each strand of fur. More segments will
mean smoother curved fur strands but will use more memory for the
geometry)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetFurGuides =R"doc(Set the type of fur guides

Parameter ``[in]``:
    guides The type of fur guides. At this point only FURGUIDES_None
    is supported)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetFurGuides =R"doc(Get the type of fur guides used. At this point only FURGUIDES_None is
supported)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetType =R"doc(Set the fur type.

See also:
    GetType ()

Parameter ``[in]``:
    type The fur type)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetType =R"doc(This setting returns what type of geometry is created for the fur
strands)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetRate =R"doc(Set the fur rate

See also:
    GetRate ()

Parameter ``[in]``:
    rate The rate at which Adaptive Sampling reduces the strands)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetRate =R"doc(The fur rate specifies the threshold that Adaptive Sampling uses to
reduce strands, calculated as an average distance, in pixels, between
two strands. Adaptive Sampling and Fur Rate are best used on scenes
like grassy fields or any situation where large amounts of strands
recede into the distance.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetClumpRangeInMeters =R"doc(Set the clump range. This is the range at which the strands will
gather together

Parameter ``[in]``:
    range The clump range in meters)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetClumpRangeInMeters =R"doc(Get the clump range. This is the range at which the strands will
gather together)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetClumpScale =R"doc(Set the clump scale percentage

Parameter ``[in]``:
    scale The scale of the clumping)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetClumpScale =R"doc(Determines closeness of fur clumps. Increasing this percentage will
cause the tips of the strands to gather together)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetGuideLengthInMeters =R"doc(Set the length of the guide in meters

Parameter ``[in]``:
    length The length of the guide)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetGuideLengthInMeters =R"doc(This value allows the adjustment of the length of the fur without
adjusting the guide itself)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetGuideRangeInMeters =R"doc(Set the range around the root guild where the strands will be
generated

Parameter ``[in]``:
    range The range in meters around where the root guide will be
    generated)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetGuideRangeInMeters =R"doc(This value sets the range around the root guide where the strands will
be generated)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetBumpAmplitude =R"doc(Set the fur bump amplitude.

See also:
    GetBumpAmplitude ())doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetBumpAmplitude =R"doc(This setting controls the strength of influence a texture layer
assigned to the layer effect 'Fur Bump' has over the 'Root Bend' and
'Flex' direction of the fur, effectively controlling the growth
direction)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetCurls =R"doc(Set the curls percentage

See also:
    SetCurls

Parameter ``[in]``:
    curls The curls percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetCurls =R"doc(The curls setting adds a corkscrew swirl to the strands. Samall
percentages will make the strands look wavy large percentages will
increase the effect)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetRootBend =R"doc(Set the root bend percentage.

See also:
    GetRootBend ()

Parameter ``[in]``:
    rootBend The root bend percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetRootBend =R"doc(This value affects the direction the strand grows from its base
surface. If the value is 0% the strand is in the direction of the
surface normal, a value of 100% will cause the strand to be 90 degrees
from the normal)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetFlex =R"doc(Set the flex value for the fur strands

See also:
    GetFlex ()

Parameter ``[in]``:
    flex The flex percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetFlex =R"doc(The flex setting adds bending to the strands as if they were affected
by gravity. For strands growing straight up, like grass, a value of 0%
would produce straight strands, and a setting of 100% would produce a
strand tip that is bent a full 180 degrees from its root.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetSizeJitter =R"doc(Set the size randomization.

See also:
    GetSizeJitter ()

Parameter ``[in]``:
    jitter The jitter percentage for)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetSizeJitter =R"doc(This setting will randomize the overall size of each strand. Values
above 0% will increase the random scaling)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetDirectionJitter =R"doc(Set the direction randomization.

See also:
    GetDirectionJitter ()

Parameter ``[in]``:
    jitter The jitter percentage for direction)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetDirectionJitter =R"doc(This setting will randomize the angle of rotation for the root of a
strand. Similar to Strip Rotation, however it will also randomize a
strands bend direction. A setting of 0% will produce strads in a
uniform direction, values above 0% will increase the randomness of
rotations for each strand)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetPositionJitter =R"doc(Set the position jitter for the fur.

See also:
    GetPositionJitter ()

Parameter ``[in]``:
    jitter The jitter percentage for position)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetPositionJitter =R"doc(This setting will increase the randomness of the root positions of
strands. This a percentage value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetGrowthJitter =R"doc(Set the growth jitter value

See also:
    GetGrowthJitter ()

Parameter ``[in]``:
    jitter The jitter percentage for growth)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetGrowthJitter =R"doc(This setting will increase the randomness of a strand along its
length. A setting of 0% will produce straight strands, while
increasing values will produce increasing jagged and random strands.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetStripRotation =R"doc(Set the strip rotation for the individual fur strands at their root.

See also:
    GetStripRotation ()

Parameter ``[in]``:
    rotation The rotation percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetStripRotation =R"doc(This will randomy rotate individual fur strands at their root. The
larger the value the more rotation is applied. The value is a
percentage where. 100% means 180 degrees)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetOffsetInMeters =R"doc(Set the offset from the surface that the strands are generated at

Parameter ``[in]``:
    offset The offset in meters from the surface)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetOffsetInMeters =R"doc(The offset will shift the fur strands away from their surface by the
specified distance)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetTaperScale =R"doc(Set the taper for the fur strand

See also:
    GetTaperScale ()

Parameter ``[in]``:
    taper The percentage reduction along the width)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetTaperScale =R"doc(This value allows the user to narrow the width of individual strands
over their length. A value of 0% would produce strands that were equal
in thickness at the root and tip, while a value 100% would produce
tips with no thickness)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetWidthScale =R"doc(Set the width of the individual strand at its root. Expressed as a
percentage of the spacing distance.

Parameter ``[in]``:
    width The width percentage of the fur strand at its root)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetWidthScale =R"doc(Get the width of individual strands at the root. Expressed as a
percentage of the spacing distance.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetLengthInMeters =R"doc(Set the length of each fur strand from its root to tip

Parameter ``[in]``:
    length The length in meters of the strand)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetLengthInMeters =R"doc(Get the length of each fur strand from its root to tip)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetSpacingInMeters =R"doc(Set the average space between individual fur strands

Parameter ``[in]``:
    spacing The space between fur strands)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetSpacingInMeters =R"doc(Get the average space between individual fur strands)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetUseFrustumCulling =R"doc(Set if fur wont be generated outside the view frustum.

Parameter ``[in]``:
    frustumCulling True to enable frustum culling)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_UseFrustumCulling =R"doc(This setting if enabled will stop fur being generated outside of the
view frustum. This speeds up fur generation but if there are
reflective surfaces the fur wont necessarily be seen in the
reflections)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetUseFurMaterial =R"doc(Sets if the material for use on the fur strands is used

Parameter ``[in]``:
    useFurMaterial The setting for using a fur material)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_UseFurMaterial =R"doc(Get if a material to be used for the fur strands)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetUseHairShader =R"doc(Set if to ue the hair shader

See also:
    UseHairShader ()

Parameter ``[in]``:
    useHairShader True to use the hair shader)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_UseHairShader =R"doc(Use the hair shader. This shader will alter the render characteristics
to make the fur appear more like hair)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetUseAutoFading =R"doc(Set if to use autofading

See also:
    UseAutoFading ()

Parameter ``[in]``:
    useAutoFading True to use auto fading)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_UseAutoFading =R"doc(This works with 'Adaptive Sampling' by fading fibers in and out when
they are created or destroyed by 'Adaptive Sampling'. This is ideal
for animated sequences.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetRemoveBaseSurface =R"doc(Set if the surface that the fur was generated on is displayed

Parameter ``[in]``:
    removeBase True to remove the surface the fur was generated on)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_RemoveBaseSurface =R"doc(Get if the surface that the fur was generated on is displayed)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_SetUseAdaptiveSampling =R"doc(Set if adaptive sampling is to be used

See also:
    UseAdaptiveSampling ()

Parameter ``[in]``:
    useAdaptive True to use adaptive sampling)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_UseAdaptiveSampling =R"doc(Enabling 'Adaptive Sampling' will decrease the density of a fur layer
as it recedes away from the camera as based on the 'Fur Rate')doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_GetMaterial =R"doc(Returns:
    The containing material for this fur.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_Copy =R"doc(Copy the settings in the object passed in into this object

Parameter ``[in]``:
    rhs The fur object to copy from)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialFur_InitDefaults =R"doc(Initialize this fur object with the default settings)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapCollection_GetMaterial =R"doc(Returns:
    The containing material for these maps.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapCollection_AddMap =R"doc(Add a map of the specified type to the collection. If a map of this
type is already associated with this material, it will be replaced.

Parameter ``[in]``:
    type The type of the map to add

Returns:
    The map added)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapCollection_DeleteMap =R"doc(Delete a map from the collection

Parameter ``[in]``:
    type The type of the map to delete)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapCollection_Copy =R"doc(Copy the collection of maps passed in into this collection.

Parameter ``[in]``:
    rhs The collection to copy from)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapCollection_InitDefaults =R"doc(Initialize this collection of maps to an empty list)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetMaterial =R"doc(Returns:
    The containing material for this map.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetLayers =R"doc(Get the collection of layers contained by this map If GetLinkType ()
!= MapType_None the linked maps value will be returned/set)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetProjectionScale =R"doc(Set the scale of the projection If GetLinkType () != MapType_None the
linked maps value will be returned/set

Parameter ``[in]``:
    x The x size

Parameter ``[in]``:
    y The y size

Parameter ``[in]``:
    z The z size)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetProjectionScale =R"doc(Get the scale of the projection If GetLinkType () != MapType_None the
linked maps value will be returned/set)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetProjectionRotation =R"doc(Set the projection rotation for the map. The angles are in degrees If
GetLinkType () != MapType_None the linked maps value will be
returned/set

Parameter ``[in]``:
    x The x angle

Parameter ``[in]``:
    y The y angle

Parameter ``[in]``:
    z The z angle)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetProjectionRotation =R"doc(Get the projection rotation for the map. The angles are in degrees If
GetLinkType () != MapType_None the linked maps value will be
returned/set)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetProjectionOffset =R"doc(Set the projection offset for the map. The projection offset is only
valid for MapMode::DirectionalDrape and after map types. If
GetLinkType () != MapType_None the linked maps value will be
returned/set

Parameter ``[in]``:
    x The x offset

Parameter ``[in]``:
    y The y offset

Parameter ``[in]``:
    z The z offset)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetProjectionOffset =R"doc(Get the projection offset for the map. The projection offset is only
valid for MapMode::DirectionalDrape and after map types. If
GetLinkType () != MapType_None the linked maps value will be
returned/set)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetLinkedMapInvertOverride =R"doc(If the map is linked then the layers can have different invert values
from the linked map. Set the override value for a linked map

Parameter ``[in]``:
    invert The invert value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetLinkedMapInvertOverride =R"doc(If the map is linked then the layers can have different invert values
from the linked map. Get the override value for a linked map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetValue =R"doc(Set the value for the map

See also:
    GetValue ()

Parameter ``[in]``:
    value The value, For bump maps, it expresses the height of the
    map. For pattern maps, it expresses the weight of the pattern)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetValue =R"doc(This is only used by bump and pattern maps. For bump maps, it
expresses the height of the map. For pattern maps, it expresses the
weight of the pattern relative to the base material color.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetIsEnabled =R"doc(Set if this map is enabled

Parameter ``[in]``:
    isEnabled True to enable the map, false to disable it)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_IsEnabled =R"doc(Get if this map is enabled.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_SetLinkType =R"doc(Set the map that this map is linked to. If this map is linked to
another then the map will get all is settings from the linked map.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetLinkType =R"doc(Get the map that this map is linked to.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_GetType =R"doc(Get the type of the map. Different map types affect different
properties of a material.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_Copy =R"doc(Copy the contents of the map passed in into this map. This will copy
everything except the map's type - map type must be set when a map is
first created.

Parameter ``[in]``:
    rhs The map to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMap_InitDefaults =R"doc(Initialize the map to its default values)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_GetMaterial =R"doc(Returns:
    The containing material for these layers.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_GetMap =R"doc(Returns:
    The containing map for these layers.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_GetLastDataLayer =R"doc(Get the last data layer (image/procedrual/cell) in the collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_AddLayerToFront =R"doc(Add a layer at the begining of this collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_AddLayer =R"doc(Add a layer at the end of this collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_GetTopLayer =R"doc(Get the first entry in this collection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayerCollection_InitDefaults =R"doc(Initialize the collection to the default values)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetMap =R"doc(Returns:
    The containing map for this layer.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetMaterial =R"doc(Returns:
    The containing material for this layer.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetColumnSpacing =R"doc(Set the row spacing for geometry maps

Parameter ``[in]``:
    rowSpacing The row spacing in the units for the map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetColumnSpacing =R"doc(Get the column spacing for geometry maps)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetRowSpacing =R"doc(Set the row spacing for geometry maps

Parameter ``[in]``:
    rowSpacing The row spacing in the units for the map)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetRowSpacing =R"doc(Get the row spacing for geometry maps)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_ClearTextureReplicator =R"doc(Remove the texture replicator from this layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetImageMapMonikers =R"doc(Returns the vector of images used for this layer. The first image in
this vector is also returned by

See also:
    GetFileName () More than one image is used only when the layer
    type is LAYERTYPE_TextureReplicator

Returns:
    The set of images to be used by this layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_AddTextureReplicator =R"doc(Add a texture replicator to this layer. If one exists already then it
will be replaced. The layer should also have the type
LAYERTYPE_TextureReplicator set;

Returns:
    The texture replicator added)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_ClearLxoProcedure =R"doc(Remove the procedure from this layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_AddLxoProcedure =R"doc(Add an LxoProcedure for this layer. If an LxoProcedure already exists
for this map, it will be replaced.

Parameter ``[in]``:
    type The type of procedure to add

Returns:
    The newly created procedure)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetOperatorStringValue =R"doc(Set the string value associated with an operator layer

Parameter ``[in]``:
    value The string value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetOperatorStringValue =R"doc(Get a string value associated with an operator layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetOperatorColorValue =R"doc(Set the color value associated with an operator layer

Parameter ``[in]``:
    red The red component

Parameter ``[in]``:
    green The green component

Parameter ``[in]``:
    blue The blue component)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetOperatorColorValue =R"doc(Get the color value associated with an operator layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetOperatorDoubleValue =R"doc(Set the double value associated with an operator layer

Parameter ``[in]``:
    value The double value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetOperatorDoubleValue =R"doc(Get the double value associated with an operator layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetType =R"doc(Set the layer type

See also:
    GetType ()

Parameter ``[in]``:
    type The layer type)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetType =R"doc(Get the type of this layer. Layers are accumulated together to produce
a final resulting image. The layers are a Reverse Polish Notation
stack. A stack is used to accumulate the layers and their operators
together. An example of a simple 2 image layer stack would be Image,
Image, Normal. The calculation to get the final image would pop the
two images off the stack, then apply the normal operator to the two
images to get a result. All the operators are binary operators with
the exception of Alpha which will take 3 images/procedurals, one for
the foreground, one for the background and one as the mask. The tint
operator is a unary operator and as such will not consume any
images/procedurals off the stack. The layer type Cell is only
supported for the Pattern map type and can be the only layer in the
stack. The group operators act like perenthisis where the contents of
the group will be evaluated in a separate stack to produce a result
before returning to the main stack to carry on the calculation)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetTextureFilterType =R"doc(Set the texture filter type to be used

Parameter ``[in]``:
    type The texture filter type)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetTextureFilterType =R"doc(Get the texture filtering type to be used)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetMinimumSpot =R"doc(Set the spot size of the image.

See also:
    GetMinimumSpot ()

Parameter ``[in]``:
    minimumSpot The spot size on the surface)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetMinimumSpot =R"doc(Get the size on the surface which will be sampled for the texture when
a ray intersects it. There is generally no need to adjust this value
as its accurate to a sub pxiel level. Setting it to larger than 1 will
result in the texture being blurred)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetAntialiasStrength =R"doc(Set the antialiasing strength of the image

See also:
    GetAntiAliasStrength ()

Parameter ``[in]``:
    antialiasStrength The antialiasing strength as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetAntialiasStrength =R"doc(Active only when antialiasing is used. This setting will allow you to
control the amount of antialiasing. Setting this value above 100% will
cause a blurring effect on the image.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetHighValue =R"doc(Set the effective value of pixels which will be 255,255,255 rgb

See also:
    GetLowValue ()

Parameter ``[in]``:
    highValue The high value as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetHighValue =R"doc(Get the effective value of pixels which will be 255,255,255 rgb

See also:
    GetLowValue ())doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetLowValue =R"doc(Set the effective value of pixels which will be 0,0,0 rgb

See also:
    GetLowValue ()

Parameter ``[in]``:
    lowValue The low value as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetLowValue =R"doc(The Low/High values provide a means for users to re-map the total
range of tones in an image. This is useful for use with displacement
mapping where the low value can be set negative. This will cause the
displacement to be pushed into the element rather than come out of the
element. It can also be used to extend the range of the image similar
to an hdri image. The normal range of the image is low 0% high 100%
This method will return the low value as a percentage and determines
the effective value of pixels with 0,0,0 rgb)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsBackgroundTransparent =R"doc(Set if to use a transparent background for this texture.

See also:
    IsBackgroundTransparent ()

Parameter ``[in]``:
    isTransparent True if the first pixel in the image is to be used
    as a transparent pixel for the rest of the image)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsBackgroundTransparent =R"doc(Is the transparent background to be used. This will take the first
pixel in the image and whereever that pixel RGB values are found in
the image that pixel value will be set to a transparent pixel)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsCapped =R"doc(Set that the cylindrical projection is capped.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsCapped =R"doc(is this a capped cylidrical projection)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsInverted =R"doc(Set if the texture RGB pixel values are to be inverted

Parameter ``[in]``:
    isInverted Set to true to invert the image)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsInverted =R"doc(Get if the texture RGB pixel values are inverted)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetGamma =R"doc(Set the gamma adjustment to apply to the texture

Parameter ``[in]``:
    gamma Gamma value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetGamma =R"doc(Get the gamma adjustment to apply to the texture)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetOpacity =R"doc(Set the opacity of this layer

Parameter ``[in]``:
    opacity The opacity of the layer)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetOpacity =R"doc(Get the opacity of this layer (0-1 range). Note that if there is only
1 layer this value will always be 1)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetAdjustedOffset =R"doc(Set the offset of the texture. These values express the offset value
adjusted to units of the map's scale, with the sign of the x
coordinate reversed. This is how the material map editor presents the
actual stored (GetOffsetR) value to the user

Parameter ``[in]``:
    x The x texture offset

Parameter ``[in]``:
    y The y texture offset

Parameter ``[in]``:
    z The z texture offset. Only used for 3d procedural textures)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetAdjustedOffset =R"doc(These values express the offset value adjusted to units of the map's
scale, with the sign of the x coordinate reversed. This is how the
material map editor presents the actual stored (GetOffsetR) value to
the user

Parameter ``[out]``:
    offset The offset of the texture)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetOffset =R"doc(Set the offset for the texture based on the units specified

Parameter ``[in]``:
    x The x texture offset

Parameter ``[in]``:
    y The y texture offset

Parameter ``[in]``:
    z The z texture offset. Only used for 3d procedural textures)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetOffset =R"doc(Get the offset for the texture based on the units specified)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetScale =R"doc(Set the scale of the texture based on the units

Parameter ``[in]``:
    x The x texture scale

Parameter ``[in]``:
    y The y texture scale

Parameter ``[in]``:
    z The z texture scale. Only used for 3d procedural textures)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetScale =R"doc(Get the scale of the texture)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetRotation =R"doc(Set the rotation angle for the texture in degrees

Parameter ``[in]``:
    rotation The rotation angle to be used)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetRotation =R"doc(Get the rotation angle for the texture in degrees)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetUnits =R"doc(Set the units used for the texture sizing

Parameter ``[in]``:
    units The units to use)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetUnits =R"doc(Get the units used for the texture sizing)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetMode =R"doc(Set the UV texture coordinate generation mode

Parameter ``[in]``:
    mode The texture coordinate generation mode to use)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetMode =R"doc(Get the UV, texture coordinate generation mode)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetFileName =R"doc(Set the filename for the layer. This is only for if the layer type is
LAYERTYPE_Image

Parameter ``[in]``:
    fileName The filename of the image)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetFileName =R"doc(If the layer is of type LAYERTYPE_Image this method will return the
filename for the image. Otherwise it will return an empty string)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsAntialiasing =R"doc(Sets if the texture image will be antialiased

Parameter ``[in]``:
    antialiasing True to antialias the texture)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsAntialiasing =R"doc(Is the texture image to be antialiased)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsSnappable =R"doc(Sets if the geometry map cell texture repeated on the element is
snappable

Parameter ``[in]``:
    isSnappable True if the cell is snappable)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsSnappable =R"doc(Is the geometry map cell texture snapppable)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetUseCellColors =R"doc(Sets the geometry map to use the colors from the cell

Parameter ``[in]``:
    useCellColors True for the geometry map to use the colors from the
    cell element)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_UseCellColors =R"doc(Gets if the geometry map will use the colors from the cell)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsProjectionLocked =R"doc(Set if the projection size is locked

Parameter ``[in]``:
    isLocked The lock value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsProjectionLocked =R"doc(Get if the projection size is locked)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetLockSize =R"doc(Set if the size lock is enabled

Parameter ``[in]``:
    lockSize The size lock value)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetLockSize =R"doc(Get if the size lock is enabled. Size lock will force the x,y,z size
to be the same)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetRepeatV =R"doc(Set if the texture is repeated in the V texture axis

Parameter ``[in]``:
    repeat True if the texture is repeated)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetRepeatV =R"doc(Get if the texture is repeated in the V texture axis)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetRepeatU =R"doc(Set if the texture is repeated in the U texture axis

Parameter ``[in]``:
    repeat True if the texture is repeated)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetRepeatU =R"doc(Get if the texture is repeated in the U texture axis)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetMirrorU =R"doc(Set if the texture is mirrored in the U texture axis

Parameter ``[in]``:
    mirror True of the texxture is mirrored)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetMirrorU =R"doc(Get if the texture is mirrored in the U texture axis)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetFlipU =R"doc(Sets if the texture is flipped in the U texture axis

Parameter ``[in]``:
    flip True to flip the texture)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_GetFlipU =R"doc(Gets if the texture is flipped in the U texture axis)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_SetIsEnabled =R"doc(Sets if this layer is enabled

Parameter ``[in]``:
    isEnabled Sets this object enabled)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_IsEnabled =R"doc(Is this layer enabled.)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_Copy =R"doc(Copy the contents of the supplied object into this

Parameter ``[in]``:
    rhs The object to copy)doc";

static const char * __doc_Bentley_DgnPlatform_MaterialMapLayer_InitDefaults =R"doc(Initialize default values for this layer)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_SetLibrary =R"doc(Sets the document that this palette was originally derived from.

Parameter ``[in]``:
    library The document that this palette was originally derived
    from.)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_GetLibrary =R"doc(Returns the document that this palette was originally derived from.)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_SetType =R"doc(Set the type of this palette

Parameter ``[in]``:
    type The type of the palette)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_GetType =R"doc(Get the type of this palette)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_SetSource =R"doc(Set the file moniker for the palette

Parameter ``[in]``:
    source The moniker to set)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_GetSource =R"doc(Get the file moniker for the palette)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_SetName =R"doc(Set the name of this palette

Parameter ``[in]``:
    name The name to set)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_GetName =R"doc(Get the name of this palette)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_Copy =R"doc(Copy the settings from the passed in object into this PaletteInfo

Parameter ``[in]``:
    rhs Object to copy from)doc";

static const char * __doc_Bentley_DgnPlatform_PaletteInfo_Equals =R"doc(Compare this PaletteInfo to the passed in PaletteInfo for equality

Parameter ``[in]``:
    rhs the object to compare to

Parameter ``[in]``:
    testLibrary Include testing if the library monikers are equal

Returns:
    True if the objects are equal)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_DeleteSurfaceParticleGenerator =R"doc(Delete the surface particle generator associated with this texture
replicator)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_AddSurfaceParticleGenerator =R"doc(Add a surface particle generator associated to this texture
replicator. If one is already applied it will be replaced)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetSurfaceParticleGenerator =R"doc(Get the surface particle generator associated with this texture
replicator)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetIsLocalNormalAttenuation =R"doc(Sets the attenuation of the texture based on the surface normal at the
particle location

Parameter ``[in]``:
    localNormalAttenuation True to use normal attenuation)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_IsLocalNormalAttenuation =R"doc(Attenuation of the texture is based on the surface normal at the
particle location)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetIsLocalProjection =R"doc(Sets the replicated texture to warp to the contour of the surface it
is on

Parameter ``[in]``:
    localProjection True for the local normal projection to be used)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_IsLocalProjection =R"doc(When enabled the replicated texture is warped to the contour of the
surface it is on)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetRandomRotation =R"doc(Set the random angle value in radians which can adjust the rotation
angle applied in

See also:
    GetRotation ()

Parameter ``[in]``:
    rotation The random rotation angle in radians)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetRandomRotation =R"doc(Get the random angle value in radians which can adjust the rotation
angle applied in

See also:
    GetRotation ())doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetRotation =R"doc(Set the image rotation in radians

See also:
    GetRotation ()

Parameter ``[in]``:
    rotation The rotation to apply in radians)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetRotation =R"doc(Get the image rotation in radians. Each repeated texture is aligned to
the vertex normal of the source surface. this rotation will rotate the
image around this normal)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetRandomSize =R"doc(Set the random size setting

See also:
    GetRandomSize ()

Parameter ``[in]``:
    size The random size percentage applied to the clones. 0% is no
    random size change.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetRandomSize =R"doc(This size setting percentage allows the radomization of the size of
individual repeated textures.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetFallOffGain =R"doc(Set the gradient of the falloff transition

See also:
    GetFallOffGain ()

Parameter ``[in]``:
    gain The gradient of the falloff as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetFallOffGain =R"doc(Get the gradient of the falloff transition. 100% is a hard edge lower
values will cause the value to ramp down.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetFallOffBias =R"doc(Set the amount of fade applied to the texture.

See also:
    GetFallOffBias ()

Parameter ``[in]``:
    bias The amount of fade applied to the texture as a percentage)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetFallOffBias =R"doc(Get the amount of fade applied to the texture from its center to the
edge as a percentage. Lower values will keep the transparent edge
towards the edge of the texture higher values will move the start of
the transparency to the center of the texture)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_SetParticleSize =R"doc(Set the size of individual cloned images.

Parameter ``[in]``:
    size The size of the individual images)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_GetParticleSize =R"doc(Get the size of individual cloned images. Larger values result in
larger image areas.)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_Copy =R"doc(Copy the contents of the texture replicator passed in into this
texture replicator.

Parameter ``[in]``:
    rhs The texture replicator to copy)doc";

static const char * __doc_Bentley_DgnPlatform_TextureReplicator_InitDefaults =R"doc(Initialize the texture replicator to its default values)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_SetRandomSeed =R"doc(Set the seed value for the randomizer algorithm for placing particles.

Parameter ``[in]``:
    seed The seed value.)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_GetRandomSeed =R"doc(Get the seed value for the randomizer algorithm for placing particles.)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_SetMaximumParticles =R"doc(Set the maximum number of particles to be generated

Parameter ``[in]``:
    maximumParticles The maximum number of particles.)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_GetMaximumParticles =R"doc(Get the maximum number of particles to be generated.)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_SetScaleFactor =R"doc(Set the scale factor percentage applied to replicated textures.

Parameter ``[in]``:
    scaleFactor The scale factor percentage to apply to the textures.)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_GetScaleFactor =R"doc(Get the scale factor percentage applied to replicated textures. This
allows the size of the replicated textures to be modified.)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_SetParticleDensity =R"doc(Set the particle density multiplier percentage.

Parameter ``[in]``:
    density The particle density percentage)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_GetParticleDensity =R"doc(Get the particle density multiplier percentage. This will allow a
simple way to control the number of replicas over a surface)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_SetMinimumSpacingInMillimeters =R"doc(Set the minimum allowed spacing between particles on a surface in
millimeters

Parameter ``[in]``:
    minimumSpacing The minimum spacing)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_GetMinimumSpacingInMillimeters =R"doc(Get the minimum allowed spacing between particles on a surface in
millimeters)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_SetAverageSpacingInMillimeters =R"doc(Set the average spacing between particles on a surface in millimeters

Parameter ``[in]``:
    averageSpacing The average spacing)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_GetAverageSpacingInMillimeters =R"doc(Get the average spacing between particles on a surface in millimeters)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_Copy =R"doc(Copy the contents of the surface particle generator passed in into
this surface particle generator.

Parameter ``[in]``:
    rhs The surface particle generator to copy)doc";

static const char * __doc_Bentley_DgnPlatform_SurfaceParticleGenerator_InitDefaults =R"doc(Initialize the surface particle generator to its default values)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MaterialSettings(py::module_& m)
    {

    //===================================================================================
    // enum MapMode
    py::enum_< MapMode>(m, "MapMode")
        .value("eNone", MapMode::None)        
        .value("eParametric", MapMode::Parametric)
        .value("eElevationDrape", MapMode::ElevationDrape)
        .value("ePlanar", MapMode::Planar)
        .value("eDirectionalDrape", MapMode::DirectionalDrape)
        .value("eCubic", MapMode::Cubic)
        .value("eSpherical", MapMode::Spherical)
        .value("eCylindrical", MapMode::Cylindrical)
        .value("eSolid", MapMode::Solid)
        .value("eFrontProject", MapMode::FrontProject)
        .export_values();

    //===================================================================================
    // enum MapUnits
    py::enum_< MapUnits>(m, "MapUnits")
        .value("eRelative", MapUnits::Relative)
        .value("eMasterUnits", MapUnits::MasterUnits)
        .value("eSubUnits", MapUnits::SubUnits)
        .value("eMeters", MapUnits::Meters)
        .value("eMillimeters", MapUnits::Millimeters)
        .value("eFeet", MapUnits::Feet)
        .value("eInches", MapUnits::Inches)
        .export_values();

    //===================================================================================
    // enum ProjectionAttachmentType
    py::enum_< ProjectionAttachmentType>(m, "ProjectionAttachmentType")
        .value("eNone", ProjectionAttachmentType::None)
        .value("eMaterial", ProjectionAttachmentType::Material)
        .value("eGroup", ProjectionAttachmentType::Group)
        .value("eElement", ProjectionAttachmentType::Element)
        .export_values();

    //===================================================================================
    // enum ProjectionVariant
    py::enum_< ProjectionVariant>(m, "ProjectionVariant")
        .value("eNone", ProjectionVariant::None)
        .value("eCylindricalCapped", ProjectionVariant::CylindricalCapped)
        .export_values();

    //===================================================================================
    // struct MaterialProjectionParameters
    py::class_< MaterialProjectionParameters> c1(m, "MaterialProjectionParameters");

    c1.def("InitDefaults", &MaterialProjectionParameters::InitDefaults);
    
    c1.def_property_readonly("Offset", &MaterialProjectionParameters::GetOffset);
    c1.def("GetOffset", &MaterialProjectionParameters::GetOffset, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("Scale", &MaterialProjectionParameters::GetScale);
    c1.def("GetScale", &MaterialProjectionParameters::GetScale, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("XYZRotations", &MaterialProjectionParameters::GetXYZRotations);
    c1.def("GetXYZRotations", &MaterialProjectionParameters::GetXYZRotations, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("RMatrix", &MaterialProjectionParameters::GetRMatrix);
    c1.def("GetRMatrix", &MaterialProjectionParameters::GetRMatrix, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("AbsoluteSize", &MaterialProjectionParameters::GetAbsoluteSize);
    c1.def("GetAbsoluteSize", &MaterialProjectionParameters::GetAbsoluteSize, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("AbsoluteOrigin", &MaterialProjectionParameters::GetAbsoluteOrigin);
    c1.def("GetAbsoluteOrigin", &MaterialProjectionParameters::GetAbsoluteOrigin, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("AbsoluteRMatrix", &MaterialProjectionParameters::GetAbsoluteRMatrix);
    c1.def("GetAbsoluteRMatrix", &MaterialProjectionParameters::GetAbsoluteRMatrix, py::return_value_policy::reference_internal);
    
    c1.def_property("MapMode", &MaterialProjectionParameters::GetMapMode, &MaterialProjectionParameters::SetMapMode);
    c1.def("GetMapMode", &MaterialProjectionParameters::GetMapMode);
    c1.def("SetMapMode", &MaterialProjectionParameters::SetMapMode, "mode"_a);
    
    c1.def_property("ProjectionVariant", &MaterialProjectionParameters::GetProjectionVariant, &MaterialProjectionParameters::SetProjectionVariant);
    c1.def("GetProjectionVariant", &MaterialProjectionParameters::GetProjectionVariant);
    c1.def("SetProjectionVariant", &MaterialProjectionParameters::SetProjectionVariant, "newVal"_a);

    //===================================================================================
    // struct SurfaceParticleGenerator
    py::class_< SurfaceParticleGenerator, SurfaceParticleGeneratorPtr> c2(m, "SurfaceParticleGenerator", py::multiple_inheritance());

    c2.def(py::init(&SurfaceParticleGenerator::Create));
    c2.def("InitDefaults", &SurfaceParticleGenerator::InitDefaults, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, InitDefaults));
    c2.def("__eq__", [] (SurfaceParticleGenerator const& self, SurfaceParticleGenerator const& other) { return self.Equals(other); });
    c2.def("Copy", &SurfaceParticleGenerator::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, Copy));
    
    c2.def_property("AverageSpacingInMillimeters", &SurfaceParticleGenerator::GetAverageSpacingInMillimeters, &SurfaceParticleGenerator::SetAverageSpacingInMillimeters);
    c2.def("GetAverageSpacingInMillimeters", &SurfaceParticleGenerator::GetAverageSpacingInMillimeters, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, GetAverageSpacingInMillimeters));
    c2.def("SetAverageSpacingInMillimeters", &SurfaceParticleGenerator::SetAverageSpacingInMillimeters, "avgSpacing"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, SetAverageSpacingInMillimeters));
    
    c2.def_property("MinimumSpacingInMillimeters", &SurfaceParticleGenerator::GetMinimumSpacingInMillimeters, &SurfaceParticleGenerator::SetMinimumSpacingInMillimeters);
    c2.def("GetMinimumSpacingInMillimeters", &SurfaceParticleGenerator::GetMinimumSpacingInMillimeters, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, GetMinimumSpacingInMillimeters));
    c2.def("SetMinimumSpacingInMillimeters", &SurfaceParticleGenerator::SetMinimumSpacingInMillimeters, "minSpacing"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, SetMinimumSpacingInMillimeters));
    
    c2.def_property("ParticleDensity", &SurfaceParticleGenerator::GetParticleDensity, &SurfaceParticleGenerator::SetParticleDensity);
    c2.def("GetParticleDensity", &SurfaceParticleGenerator::GetParticleDensity, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, GetParticleDensity));
    c2.def("SetParticleDensity", &SurfaceParticleGenerator::SetParticleDensity, "density"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, SetParticleDensity));
    
    c2.def_property("ScaleFactor", &SurfaceParticleGenerator::GetScaleFactor, &SurfaceParticleGenerator::SetScaleFactor);
    c2.def("GetScaleFactor", &SurfaceParticleGenerator::GetScaleFactor, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, GetScaleFactor));
    c2.def("SetScaleFactor", &SurfaceParticleGenerator::SetScaleFactor, "factor"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, SetScaleFactor));
    
    c2.def_property("MaximumParticles", &SurfaceParticleGenerator::GetMaximumParticles, &SurfaceParticleGenerator::SetMaximumParticles);
    c2.def("GetMaximumParticles", &SurfaceParticleGenerator::GetMaximumParticles, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, GetMaximumParticles));
    c2.def("SetMaximumParticles", &SurfaceParticleGenerator::SetMaximumParticles, "maxParticles"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, SetMaximumParticles));
    
    c2.def_property("RandomSeed", &SurfaceParticleGenerator::GetRandomSeed, &SurfaceParticleGenerator::SetRandomSeed);
    c2.def("GetRandomSeed", &SurfaceParticleGenerator::GetRandomSeed, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, GetRandomSeed));
    c2.def("SetRandomSeed", &SurfaceParticleGenerator::SetRandomSeed, "seed"_a, DOC(Bentley, DgnPlatform, SurfaceParticleGenerator, SetRandomSeed));

    //===================================================================================
    // struct TextureReplicator
    py::class_< TextureReplicator, TextureReplicatorPtr> c3(m, "TextureReplicator", py::multiple_inheritance());

    c3.def(py::init(&TextureReplicator::Create));
    c3.def("InitDefaults", &TextureReplicator::InitDefaults, DOC(Bentley, DgnPlatform, TextureReplicator, InitDefaults));
    c3.def("__eq__", [] (TextureReplicator const& self, TextureReplicator const& other) { return self.Equals(other); });
    c3.def("Copy", &TextureReplicator::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, TextureReplicator, Copy));
    
    c3.def_property("ParticleSize", &TextureReplicator::GetParticleSize, &TextureReplicator::SetParticleSize);
    c3.def("GetParticleSize", &TextureReplicator::GetParticleSize, DOC(Bentley, DgnPlatform, TextureReplicator, GetParticleSize));
    c3.def("SetParticleSize", &TextureReplicator::SetParticleSize, "size"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetParticleSize));
    
    c3.def_property("FallOffBias", &TextureReplicator::GetFallOffBias, &TextureReplicator::SetFallOffBias);
    c3.def("GetFallOffBias", &TextureReplicator::GetFallOffBias, DOC(Bentley, DgnPlatform, TextureReplicator, GetFallOffBias));
    c3.def("SetFallOffBias", &TextureReplicator::SetFallOffBias, "bias"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetFallOffBias));
    
    c3.def_property("FallOffGain", &TextureReplicator::GetFallOffGain, &TextureReplicator::SetFallOffGain);
    c3.def("GetFallOffGain", &TextureReplicator::GetFallOffGain, DOC(Bentley, DgnPlatform, TextureReplicator, GetFallOffGain));
    c3.def("SetFallOffGain", &TextureReplicator::SetFallOffGain, "gain"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetFallOffGain));
    
    c3.def_property("RandomSize", &TextureReplicator::GetRandomSize, &TextureReplicator::SetRandomSize);
    c3.def("GetRandomSize", &TextureReplicator::GetRandomSize, DOC(Bentley, DgnPlatform, TextureReplicator, GetRandomSize));
    c3.def("SetRandomSize", &TextureReplicator::SetRandomSize, "size"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetRandomSize));
    
    c3.def_property("Rotation", &TextureReplicator::GetRotation, &TextureReplicator::SetRotation);
    c3.def("GetRotation", &TextureReplicator::GetRotation, DOC(Bentley, DgnPlatform, TextureReplicator, GetRotation));
    c3.def("SetRotation", &TextureReplicator::SetRotation, "rotation"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetRotation));
    
    c3.def_property("RandomRotation", &TextureReplicator::GetRandomRotation, &TextureReplicator::SetRandomRotation);
    c3.def("GetRandomRotation", &TextureReplicator::GetRandomRotation, DOC(Bentley, DgnPlatform, TextureReplicator, GetRandomRotation));
    c3.def("SetRandomRotation", &TextureReplicator::SetRandomRotation, "rotation"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetRandomRotation));
    
    c3.def_property("LocalProjection", &TextureReplicator::IsLocalProjection, &TextureReplicator::SetIsLocalProjection);
    c3.def("IsLocalProjection", &TextureReplicator::IsLocalProjection, DOC(Bentley, DgnPlatform, TextureReplicator, IsLocalProjection));
    c3.def("SetIsLocalProjection", &TextureReplicator::SetIsLocalProjection, "localProjection"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetIsLocalProjection));
    
    c3.def_property("LocalNormalAttenuation", &TextureReplicator::IsLocalNormalAttenuation, &TextureReplicator::SetIsLocalNormalAttenuation);
    c3.def("IsLocalNormalAttenuation", &TextureReplicator::IsLocalNormalAttenuation, DOC(Bentley, DgnPlatform, TextureReplicator, IsLocalNormalAttenuation));
    c3.def("SetIsLocalNormalAttenuation", &TextureReplicator::SetIsLocalNormalAttenuation, "newVal"_a, DOC(Bentley, DgnPlatform, TextureReplicator, SetIsLocalNormalAttenuation));
    
    c3.def_property_readonly("SurfaceParticleGenerator", &TextureReplicator::GetSurfaceParticleGeneratorP);
    c3.def("GetSurfaceParticleGenerator", &TextureReplicator::GetSurfaceParticleGeneratorP, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureReplicator, GetSurfaceParticleGenerator));
    
    c3.def("AddSurfaceParticleGenerator", &TextureReplicator::AddSurfaceParticleGenerator, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextureReplicator, AddSurfaceParticleGenerator));
    c3.def("DeleteSurfaceParticleGenerator", &TextureReplicator::DeleteSurfaceParticleGenerator, DOC(Bentley, DgnPlatform, TextureReplicator, DeleteSurfaceParticleGenerator));   

    //===================================================================================
    // struct PaletteInfo
    py::class_< PaletteInfo, PaletteInfoPtr> c4(m, "PaletteInfo", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum PaletteType
        py::enum_< PaletteInfo::PaletteType>(c4, "PaletteType", py::arithmetic())
            .value("ePALETTETYPE_Dgn", PaletteInfo::PALETTETYPE_Dgn)
            .value("ePALETTETYPE_Pal", PaletteInfo::PALETTETYPE_Pal)
            .value("ePALETTETYPE_Other", PaletteInfo::PALETTETYPE_Other)
            .export_values();
        }

    c4.def(py::init(py::overload_cast<>(&PaletteInfo::Create)));
    c4.def(py::init(py::overload_cast<WCharCP, DgnDocumentMonikerCR, PaletteInfo::PaletteType>(&PaletteInfo::Create)), "name"_a, "source"_a, "type"_a);
    c4.def(py::init(py::overload_cast<WCharCP, DgnDocumentMonikerCR, DgnDocumentMonikerCR, PaletteInfo::PaletteType>(&PaletteInfo::Create)), "name"_a, "source"_a, "library"_a, "type"_a);
    c4.def("Equals", &PaletteInfo::Equals, "rhs"_a, "testLibrary"_a, DOC(Bentley, DgnPlatform, PaletteInfo, Equals));
    c4.def("Copy", &PaletteInfo::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, PaletteInfo, Copy));

    c4.def_property("Name", &PaletteInfo::GetName, &PaletteInfo::SetName);
    c4.def("GetName", &PaletteInfo::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PaletteInfo, GetName));
    c4.def("SetName", &PaletteInfo::SetName, "name"_a, DOC(Bentley, DgnPlatform, PaletteInfo, SetName));
    
    c4.def_property("Source",&PaletteInfo::GetSourceR, &PaletteInfo::SetSource);
    c4.def("GetSource", &PaletteInfo::GetSourceR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PaletteInfo, GetSource));
    c4.def("SetSource", &PaletteInfo::SetSource, "source"_a, DOC(Bentley, DgnPlatform, PaletteInfo, SetSource));
    
    c4.def_property("Type", &PaletteInfo::GetType, &PaletteInfo::SetType);
    c4.def("GetType", &PaletteInfo::GetType, DOC(Bentley, DgnPlatform, PaletteInfo, GetType));
    c4.def("SetType", &PaletteInfo::SetType, "type"_a, DOC(Bentley, DgnPlatform, PaletteInfo, SetType));
    
    c4.def_property("Library", &PaletteInfo::GetLibraryR, &PaletteInfo::SetLibrary);
    c4.def("GetLibrary", &PaletteInfo::GetLibraryR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PaletteInfo, GetLibrary));
    c4.def("SetLibrary", &PaletteInfo::SetLibrary, "library"_a, DOC(Bentley, DgnPlatform, PaletteInfo, SetLibrary));


    //===================================================================================
    // struct MaterialMapLayer
    py::class_< MaterialMapLayer, MaterialMapLayerPtr> c6(m, "MaterialMapLayer", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        py::enum_< MaterialMapLayer::LayerType>(c6, "LayerType", py::arithmetic())
            .value("eLAYERTYPE_None", MaterialMapLayer::LAYERTYPE_None)
            .value("eLAYERTYPE_Image", MaterialMapLayer::LAYERTYPE_Image)
            .value("eLAYERTYPE_Procedure", MaterialMapLayer::LAYERTYPE_Procedure)
            .value("eLAYERTYPE_Gradient", MaterialMapLayer::LAYERTYPE_Gradient)
            .value("eLAYERTYPE_LxoProcedure", MaterialMapLayer::LAYERTYPE_LxoProcedure)
            .value("eLAYERTYPE_Cell", MaterialMapLayer::LAYERTYPE_Cell)
            .value("eLAYERTYPE_8119LxoProcedure", MaterialMapLayer::LAYERTYPE_8119LxoProcedure)
            .value("eLAYERTYPE_TextureReplicator", MaterialMapLayer::LAYERTYPE_TextureReplicator)
            .value("eLAYERTYPE_Operator", MaterialMapLayer::LAYERTYPE_Operator)
            .value("eLAYERTYPE_Normal", MaterialMapLayer::LAYERTYPE_Normal)
            .value("eLAYERTYPE_Add", MaterialMapLayer::LAYERTYPE_Add)
            .value("eLAYERTYPE_Subtract", MaterialMapLayer::LAYERTYPE_Subtract)
            .value("eLAYERTYPE_Alpha", MaterialMapLayer::LAYERTYPE_Alpha)
            .value("eLAYERTYPE_Dissolve", MaterialMapLayer::LAYERTYPE_Dissolve)
            .value("eLAYERTYPE_Atop", MaterialMapLayer::LAYERTYPE_Atop)
            .value("eLAYERTYPE_In", MaterialMapLayer::LAYERTYPE_In)
            .value("eLAYERTYPE_Out", MaterialMapLayer::LAYERTYPE_Out)
            .value("eLAYERTYPE_UnaryOperator", MaterialMapLayer::LAYERTYPE_UnaryOperator)
            .value("eLAYERTYPE_Tint", MaterialMapLayer::LAYERTYPE_Tint)
            .value("eLAYERTYPE_Negate", MaterialMapLayer::LAYERTYPE_Negate)
            .value("eLAYERTYPE_Equalize", MaterialMapLayer::LAYERTYPE_Equalize)
            .value("eLAYERTYPE_GroupStart", MaterialMapLayer::LAYERTYPE_GroupStart)
            .value("eLAYERTYPE_GroupEnd", MaterialMapLayer::LAYERTYPE_GroupEnd)
            .value("eLAYERTYPE_AlphaBackgroundStart", MaterialMapLayer::LAYERTYPE_AlphaBackgroundStart)
            .value("eLAYERTYPE_AlphaBackgroundEnd", MaterialMapLayer::LAYERTYPE_AlphaBackgroundEnd)
            .value("eLAYERTYPE_Difference", MaterialMapLayer::LAYERTYPE_Difference)
            .value("eLAYERTYPE_NormalMultiply", MaterialMapLayer::LAYERTYPE_NormalMultiply)
            .value("eLAYERTYPE_Divide", MaterialMapLayer::LAYERTYPE_Divide)
            .value("eLAYERTYPE_Multiply", MaterialMapLayer::LAYERTYPE_Multiply)
            .value("eLAYERTYPE_Screen", MaterialMapLayer::LAYERTYPE_Screen)
            .value("eLAYERTYPE_Overlay", MaterialMapLayer::LAYERTYPE_Overlay)
            .value("eLAYERTYPE_SoftLight", MaterialMapLayer::LAYERTYPE_SoftLight)
            .value("eLAYERTYPE_HardLight", MaterialMapLayer::LAYERTYPE_HardLight)
            .value("eLAYERTYPE_Darken", MaterialMapLayer::LAYERTYPE_Darken)
            .value("eLAYERTYPE_Lighten", MaterialMapLayer::LAYERTYPE_Lighten)
            .value("eLAYERTYPE_ColorDodge", MaterialMapLayer::LAYERTYPE_ColorDodge)
            .value("eLAYERTYPE_ColorBurn", MaterialMapLayer::LAYERTYPE_ColorBurn)
            .export_values();

        //===================================================================================
        py::enum_< MaterialMapLayer::TextureFilterType>(c6, "TextureFilterType", py::arithmetic())
            .value("eTEXTUREFILTERTYPE_Nearest", MaterialMapLayer::TEXTUREFILTERTYPE_Nearest)
            .value("eTEXTUREFILTERTYPE_Bilinear", MaterialMapLayer::TEXTUREFILTERTYPE_Bilinear)
            .value("eTEXTUREFILTERTYPE_Bicubic", MaterialMapLayer::TEXTUREFILTERTYPE_Bicubic)
            .export_values();
        }
    c6.def("InitDefaults", &MaterialMapLayer::InitDefaults, DOC(Bentley, DgnPlatform, MaterialMapLayer, InitDefaults));
    c6.def("__eq__", [] (MaterialMapLayerCR self, MaterialMapLayerCR other) { return self.Equals(other); });
    c6.def("Copy", &MaterialMapLayer::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, Copy));
    
    c6.def_property("Enabled", &MaterialMapLayer::IsEnabled, &MaterialMapLayer::SetIsEnabled);
    c6.def("IsEnabled", &MaterialMapLayer::IsEnabled, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsEnabled));
    c6.def("SetIsEnabled", &MaterialMapLayer::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsEnabled));
    
    c6.def_property("FlipU", &MaterialMapLayer::GetFlipU, &MaterialMapLayer::SetFlipU);
    c6.def("GetFlipU", &MaterialMapLayer::GetFlipU, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetFlipU));
    c6.def("SetFlipU", &MaterialMapLayer::SetFlipU, "flipU"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetFlipU));
    
    c6.def_property("MirrorU", &MaterialMapLayer::GetMirrorU, &MaterialMapLayer::SetMirrorU);
    c6.def("GetMirrorU", &MaterialMapLayer::GetMirrorU, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetMirrorU));
    c6.def("SetMirrorU", &MaterialMapLayer::SetMirrorU, "mirrorU"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetMirrorU));
    
    c6.def_property("RepeatU", &MaterialMapLayer::GetRepeatU, &MaterialMapLayer::SetRepeatU);
    c6.def("GetRepeatU", &MaterialMapLayer::GetRepeatU, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetRepeatU));
    c6.def("SetRepeatU", &MaterialMapLayer::SetRepeatU, "repeatU"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetRepeatU));
    
    c6.def_property("RepeatV", &MaterialMapLayer::GetRepeatV, &MaterialMapLayer::SetRepeatV);
    c6.def("GetRepeatV", &MaterialMapLayer::GetRepeatV, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetRepeatV));
    c6.def("SetRepeatV", &MaterialMapLayer::SetRepeatV, "repeatV"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetRepeatV));
    
    c6.def_property("LockSize", &MaterialMapLayer::GetLockSize, &MaterialMapLayer::SetLockSize);
    c6.def("GetLockSize", &MaterialMapLayer::GetLockSize, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetLockSize));
    c6.def("SetLockSize", &MaterialMapLayer::SetLockSize, "lockSize"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetLockSize));
    
    c6.def_property("ProjectionLocked", &MaterialMapLayer::IsProjectionLocked, &MaterialMapLayer::SetIsProjectionLocked);
    c6.def("IsProjectionLocked", &MaterialMapLayer::IsProjectionLocked, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsProjectionLocked));
    c6.def("SetIsProjectionLocked", &MaterialMapLayer::SetIsProjectionLocked, "locked"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsProjectionLocked));
    
    c6.def_property("IsUseCellColors", &MaterialMapLayer::UseCellColors, &MaterialMapLayer::SetUseCellColors);
    c6.def("UseCellColors", &MaterialMapLayer::UseCellColors, DOC(Bentley, DgnPlatform, MaterialMapLayer, UseCellColors));
    c6.def("SetUseCellColors", &MaterialMapLayer::SetUseCellColors, "useCellColor"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetUseCellColors));
    
    c6.def_property("Snappable", &MaterialMapLayer::IsSnappable, &MaterialMapLayer::SetIsSnappable);
    c6.def("IsSnappable", &MaterialMapLayer::IsSnappable, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsSnappable));
    c6.def("SetIsSnappable", &MaterialMapLayer::SetIsSnappable, "snappable"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsSnappable));
    
    c6.def_property("Antialiasing", &MaterialMapLayer::IsAntialiasing, &MaterialMapLayer::SetIsAntialiasing);
    c6.def("IsAntialiasing", &MaterialMapLayer::IsAntialiasing, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsAntialiasing));
    c6.def("SetIsAntialiasing", &MaterialMapLayer::SetIsAntialiasing, "newVal"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsAntialiasing));
    
    c6.def_property("FileName", &MaterialMapLayer::GetFileName, &MaterialMapLayer::SetFileName);
    c6.def("GetFileName", &MaterialMapLayer::GetFileName, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetFileName));
    c6.def("SetFileName", &MaterialMapLayer::SetFileName, "fileName"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetFileName));
    
    c6.def_property("Mode", &MaterialMapLayer::GetMode, &MaterialMapLayer::SetMode);
    c6.def("GetMode", &MaterialMapLayer::GetMode, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetMode));
    c6.def("SetMode", &MaterialMapLayer::SetMode, "mode"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetMode));
    
    c6.def_property("Units", &MaterialMapLayer::GetUnits, &MaterialMapLayer::SetUnits);
    c6.def("GetUnits", &MaterialMapLayer::GetUnits, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetUnits));
    c6.def("SetUnits", &MaterialMapLayer::SetUnits, "units"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetUnits));
    
    c6.def_property("Rotation", &MaterialMapLayer::GetRotation, &MaterialMapLayer::SetRotation);
    c6.def("GetRotation", &MaterialMapLayer::GetRotation, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetRotation));
    c6.def("SetRotation", &MaterialMapLayer::SetRotation, "rotation"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetRotation));
    
    c6.def_property("Scale",
                    &MaterialMapLayer::GetScale,
                    [] (MaterialMapLayer& self, DPoint3dCR scale) { self.SetScale(scale.x, scale.y, scale.z); });
    c6.def("GetScale", &MaterialMapLayer::GetScale, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetScale));
    c6.def("SetScale", &MaterialMapLayer::SetScale, "x"_a, "y"_a, "z"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetScale));

    c6.def_property("Offset",
                    &MaterialMapLayer::GetOffset,
                    [] (MaterialMapLayer& self, DPoint3dCR offset) { self.SetOffset(offset.x, offset.y, offset.z); });
    c6.def("GetOffset", &MaterialMapLayer::GetOffset, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetOffset));
    c6.def("SetOffset", &MaterialMapLayer::SetOffset, "x"_a, "y"_a, "z"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetOffset));

    c6.def("GetAdjustedOffset", &MaterialMapLayer::GetAdjustedOffset, "offset"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetAdjustedOffset));
    c6.def("SetAdjustedOffset", py::overload_cast<DPoint3dCR>(&MaterialMapLayer::SetAdjustedOffset), "offset"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetAdjustedOffset));

    c6.def_property("Opacity", &MaterialMapLayer::GetOpacity, &MaterialMapLayer::SetOpacity);
    c6.def("GetOpacity", &MaterialMapLayer::GetOpacity, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetOpacity));
    c6.def("SetOpacity", &MaterialMapLayer::SetOpacity, "opacity"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetOpacity));
    
    c6.def_property("Gamma", &MaterialMapLayer::GetGamma, &MaterialMapLayer::SetGamma);
    c6.def("GetGamma", &MaterialMapLayer::GetGamma, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetGamma));
    c6.def("SetGamma", &MaterialMapLayer::SetGamma, "gamma"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetGamma));
    
    c6.def_property("Inverted", &MaterialMapLayer::IsInverted, &MaterialMapLayer::SetIsInverted);
    c6.def("IsInverted", &MaterialMapLayer::IsInverted, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsInverted));
    c6.def("SetIsInverted", &MaterialMapLayer::SetIsInverted, "inverted"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsInverted));
    
    c6.def_property("Capped", &MaterialMapLayer::IsCapped, &MaterialMapLayer::SetIsCapped);
    c6.def("IsCapped", &MaterialMapLayer::IsCapped, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsCapped));
    c6.def("SetIsCapped", &MaterialMapLayer::SetIsCapped, "capped"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsCapped));
    
    c6.def_property("BackgroundTransparent", &MaterialMapLayer::IsBackgroundTransparent, &MaterialMapLayer::SetIsBackgroundTransparent);
    c6.def("IsBackgroundTransparent", &MaterialMapLayer::IsBackgroundTransparent, DOC(Bentley, DgnPlatform, MaterialMapLayer, IsBackgroundTransparent));
    c6.def("SetIsBackgroundTransparent", &MaterialMapLayer::SetIsBackgroundTransparent, "transparent"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetIsBackgroundTransparent));
    
    c6.def_property("LowValue", &MaterialMapLayer::GetLowValue, &MaterialMapLayer::SetLowValue);
    c6.def("GetLowValue", &MaterialMapLayer::GetLowValue, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetLowValue));
    c6.def("SetLowValue", &MaterialMapLayer::SetLowValue, "lowValue"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetLowValue));
    
    c6.def_property("HighValue", &MaterialMapLayer::GetHighValue, &MaterialMapLayer::SetHighValue);
    c6.def("GetHighValue", &MaterialMapLayer::GetHighValue, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetHighValue));
    c6.def("SetHighValue", &MaterialMapLayer::SetHighValue, "highValue"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetHighValue));
    
    c6.def_property("AntialiasStrength", &MaterialMapLayer::GetAntialiasStrength, &MaterialMapLayer::SetAntialiasStrength);
    c6.def("GetAntialiasStrength", &MaterialMapLayer::GetAntialiasStrength, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetAntialiasStrength));
    c6.def("SetAntialiasStrength", &MaterialMapLayer::SetAntialiasStrength, "strength"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetAntialiasStrength));
    
    c6.def_property("MinimumSpot", &MaterialMapLayer::GetMinimumSpot, &MaterialMapLayer::SetMinimumSpot);
    c6.def("GetMinimumSpot", &MaterialMapLayer::GetMinimumSpot, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetMinimumSpot));
    c6.def("SetMinimumSpot", &MaterialMapLayer::SetMinimumSpot, "minSpot"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetMinimumSpot));
    
    c6.def_property("TextureFilterType", &MaterialMapLayer::GetTextureFilterType, &MaterialMapLayer::SetTextureFilterType);
    c6.def("GetTextureFilterType", &MaterialMapLayer::GetTextureFilterType, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetTextureFilterType));
    c6.def("SetTextureFilterType", &MaterialMapLayer::SetTextureFilterType, "filterType"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetTextureFilterType));
    
    c6.def_property("Type", &MaterialMapLayer::GetType, &MaterialMapLayer::SetType);
    c6.def("GetType", &MaterialMapLayer::GetType, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetType));
    c6.def("SetType", &MaterialMapLayer::SetType, "type"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetType));
    
    c6.def_property("OperatorDoubleValue", &MaterialMapLayer::GetOperatorDoubleValue, &MaterialMapLayer::SetOperatorDoubleValue);
    c6.def("GetOperatorDoubleValue", &MaterialMapLayer::GetOperatorDoubleValue, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetOperatorDoubleValue));
    c6.def("SetOperatorDoubleValue", &MaterialMapLayer::SetOperatorDoubleValue, "value"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetOperatorDoubleValue));

    c6.def("GetOperatorColorValue", &MaterialMapLayer::GetOperatorColorValue, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetOperatorColorValue));
    c6.def("SetOperatorColorValue", &MaterialMapLayer::SetOperatorColorValue, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetOperatorColorValue));

    c6.def_property("OperatorStringValue", &MaterialMapLayer::GetOperatorStringValue, &MaterialMapLayer::SetOperatorStringValue);
    c6.def("GetOperatorStringValue", &MaterialMapLayer::GetOperatorStringValue, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetOperatorStringValue));
    c6.def("SetOperatorStringValue", &MaterialMapLayer::SetOperatorStringValue, "value"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetOperatorStringValue));

    c6.def_property_readonly("LxoProcedure", &MaterialMapLayer::GetLxoProcedureP);
    c6.def("GetLxoProcedure", &MaterialMapLayer::GetLxoProcedureP, py::return_value_policy::reference_internal);
    c6.def("AddLxoProcedure", &MaterialMapLayer::AddLxoProcedure, "type"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, AddLxoProcedure));
    c6.def("ClearLxoProcedure", &MaterialMapLayer::ClearLxoProcedure, DOC(Bentley, DgnPlatform, MaterialMapLayer, ClearLxoProcedure));

    c6.def_property_readonly("TextureReplicator", &MaterialMapLayer::GetTextureReplicatorP);
    c6.def("GetTextureReplicator", &MaterialMapLayer::GetTextureReplicatorP, py::return_value_policy::reference_internal);
    c6.def("AddTextureReplicator", &MaterialMapLayer::AddTextureReplicator, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, AddTextureReplicator));

    c6.def_property_readonly("ImageMapMonikers", &MaterialMapLayer::GetImageMapMonikersR);
    c6.def("GetImageMapMonikers", &MaterialMapLayer::GetImageMapMonikersR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetImageMapMonikers));
    c6.def("ClearTextureReplicator", &MaterialMapLayer::ClearTextureReplicator, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, ClearTextureReplicator));

    c6.def_property("RowSpacing", &MaterialMapLayer::GetRowSpacing, &MaterialMapLayer::SetRowSpacing);
    c6.def("GetRowSpacing", &MaterialMapLayer::GetRowSpacing, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetRowSpacing));
    c6.def("SetRowSpacing", &MaterialMapLayer::SetRowSpacing, "spacing"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetRowSpacing));
    
    c6.def_property("ColumnSpacing", &MaterialMapLayer::GetColumnSpacing, &MaterialMapLayer::SetColumnSpacing);
    c6.def("GetColumnSpacing", &MaterialMapLayer::GetColumnSpacing, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetColumnSpacing));
    c6.def("SetColumnSpacing", &MaterialMapLayer::SetColumnSpacing, "spacing"_a, DOC(Bentley, DgnPlatform, MaterialMapLayer, SetColumnSpacing));
    
    c6.def_property_readonly("Material", &MaterialMapLayer::GetMaterialR);
    c6.def("GetMaterial", &MaterialMapLayer::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetMaterial));
    
    c6.def_property_readonly("Map", &MaterialMapLayer::GetMapR);
    c6.def("GetMap", &MaterialMapLayer::GetMapR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayer, GetMap));

    //===================================================================================
    // struct MaterialMapLayerCollection
    py::class_< MaterialMapLayerCollection> c7(m, "MaterialMapLayerCollection");
    c7.def("InitDefaults", &MaterialMapLayerCollection::InitDefaults, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, InitDefaults));
    c7.def("__eq__", [] (MaterialMapLayerCollectionCR self, MaterialMapLayerCollectionCR other) { return self.Equals(other); });
    c7.def("__len__", &MaterialMapLayerCollection::Size);
    
    c7.def_property_readonly("TopLayer", &MaterialMapLayerCollection::GetTopLayerR);
    c7.def("GetTopLayer", &MaterialMapLayerCollection::GetTopLayerR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, GetTopLayer));
    
    c7.def("AddLayer", &MaterialMapLayerCollection::AddLayer, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, AddLayer));
    c7.def("AddLayerToFront", &MaterialMapLayerCollection::AddLayerToFront, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, AddLayerToFront));
    
    c7.def_property_readonly("LastDataLayer", &MaterialMapLayerCollection::GetLastDataLayer);
    c7.def("GetLastDataLayer", &MaterialMapLayerCollection::GetLastDataLayer, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, GetLastDataLayer));
    
    c7.def_property_readonly("Map", &MaterialMapLayerCollection::GetMapR);
    c7.def("GetMap", &MaterialMapLayerCollection::GetMapR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, GetMap));
    
    c7.def_property_readonly("Material", &MaterialMapLayerCollection::GetMaterialR);
    c7.def("GetMaterial", &MaterialMapLayerCollection::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapLayerCollection, GetMaterial));



    c7.def("__iter__", [] (MaterialMapLayerCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct MaterialMap
    py::class_< MaterialMap, MaterialMapPtr> c8(m, "MaterialMap", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum MapType
        py::enum_< MaterialMap::MapType>(c8, "MapType", py::arithmetic())
            .value("eMAPTYPE_None", MaterialMap::MAPTYPE_None)
            .value("eMAPTYPE_Pattern", MaterialMap::MAPTYPE_Pattern)
            .value("eMAPTYPE_Bump", MaterialMap::MAPTYPE_Bump)
            .value("eMAPTYPE_Specular", MaterialMap::MAPTYPE_Specular)
            .value("eMAPTYPE_Reflect", MaterialMap::MAPTYPE_Reflect)
            .value("eMAPTYPE_Transparency", MaterialMap::MAPTYPE_Transparency)
            .value("eMAPTYPE_Translucency", MaterialMap::MAPTYPE_Translucency)
            .value("eMAPTYPE_Finish", MaterialMap::MAPTYPE_Finish)
            .value("eMAPTYPE_Diffuse", MaterialMap::MAPTYPE_Diffuse)
            .value("eMAPTYPE_GlowAmount", MaterialMap::MAPTYPE_GlowAmount)
            .value("eMAPTYPE_ClearcoatAmount", MaterialMap::MAPTYPE_ClearcoatAmount)
            .value("eMAPTYPE_AnisotropicDirection", MaterialMap::MAPTYPE_AnisotropicDirection)
            .value("eMAPTYPE_SpecularColor", MaterialMap::MAPTYPE_SpecularColor)
            .value("eMAPTYPE_TransparentColor", MaterialMap::MAPTYPE_TransparentColor)
            .value("eMAPTYPE_TranslucencyColor", MaterialMap::MAPTYPE_TranslucencyColor)
            .value("eMAPTYPE_Displacement", MaterialMap::MAPTYPE_Displacement)
            .value("eMAPTYPE_Normal", MaterialMap::MAPTYPE_Normal)
            .value("eMAPTYPE_FurLength", MaterialMap::MAPTYPE_FurLength)
            .value("eMAPTYPE_FurDensity", MaterialMap::MAPTYPE_FurDensity)
            .value("eMAPTYPE_FurJitter", MaterialMap::MAPTYPE_FurJitter)
            .value("eMAPTYPE_FurFlex", MaterialMap::MAPTYPE_FurFlex)
            .value("eMAPTYPE_FurClumps", MaterialMap::MAPTYPE_FurClumps)
            .value("eMAPTYPE_FurDirection", MaterialMap::MAPTYPE_FurDirection)
            .value("eMAPTYPE_FurVector", MaterialMap::MAPTYPE_FurVector)
            .value("eMAPTYPE_FurBump", MaterialMap::MAPTYPE_FurBump)
            .value("eMAPTYPE_FurCurls", MaterialMap::MAPTYPE_FurCurls)
            .value("eMAPTYPE_GlowColor", MaterialMap::MAPTYPE_GlowColor)
            .value("eMAPTYPE_ReflectColor", MaterialMap::MAPTYPE_ReflectColor)
            .value("eMAPTYPE_RefractionRoughness", MaterialMap::MAPTYPE_RefractionRoughness)
            .value("eMAPTYPE_SpecularFresnel", MaterialMap::MAPTYPE_SpecularFresnel)
            .value("eMAPTYPE_Geometry", MaterialMap::MAPTYPE_Geometry)
            .value("eMAPTYPE_PBRRoughness", MaterialMap::MAPTYPE_PBRRoughness)
            .value("eMAPTYPE_PBRMetallic", MaterialMap::MAPTYPE_PBRMetallic)
            .value("eMAPTYPE_PBREmissiveColor", MaterialMap::MAPTYPE_PBREmissiveColor)
            .value("eMAPTYPE_PBRHeight", MaterialMap::MAPTYPE_PBRHeight)
            .value("eMAPTYPE_PBRAmbientOcclusion", MaterialMap::MAPTYPE_PBRAmbientOcclusion)
            .value("eMAPTYPE_PBROpacity", MaterialMap::MAPTYPE_PBROpacity)
            .export_values();
        }

    c8.def("InitDefaults", &MaterialMap::InitDefaults, DOC(Bentley, DgnPlatform, MaterialMap, InitDefaults));
    c8.def("__eq__", [] (MaterialMapCR self, MaterialMapCR other) { return self.Equals(other); });
    c8.def("Copy", &MaterialMap::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialMap, Copy));
    c8.def_property_readonly("Type", &MaterialMap::GetType);
    c8.def("GetType", &MaterialMap::GetType, DOC(Bentley, DgnPlatform, MaterialMap, GetType));
    
    c8.def_property("LinkType", &MaterialMap::GetLinkType, &MaterialMap::SetLinkType);
    c8.def("GetLinkType", &MaterialMap::GetLinkType, DOC(Bentley, DgnPlatform, MaterialMap, GetLinkType));
    c8.def("SetLinkType", &MaterialMap::SetLinkType, "linkType"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetLinkType));
    
    c8.def_property("Enabled", &MaterialMap::IsEnabled, &MaterialMap::SetIsEnabled);
    c8.def("IsEnabled", &MaterialMap::IsEnabled, DOC(Bentley, DgnPlatform, MaterialMap, IsEnabled));
    c8.def("SetIsEnabled", &MaterialMap::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetIsEnabled));
    
    c8.def_property("Value", &MaterialMap::GetValue, &MaterialMap::SetValue);
    c8.def("GetValue", &MaterialMap::GetValue, DOC(Bentley, DgnPlatform, MaterialMap, GetValue));
    c8.def("SetValue", &MaterialMap::SetValue, "newVal"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetValue));
    
    c8.def_property("LinkedMapInvertOverride", &MaterialMap::GetLinkedMapInvertOverride, &MaterialMap::SetLinkedMapInvertOverride);
    c8.def("GetLinkedMapInvertOverride", &MaterialMap::GetLinkedMapInvertOverride, DOC(Bentley, DgnPlatform, MaterialMap, GetLinkedMapInvertOverride));
    c8.def("SetLinkedMapInvertOverride", &MaterialMap::SetLinkedMapInvertOverride, "invert"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetLinkedMapInvertOverride));

    c8.def_property("ProjectionOffset",
                    &MaterialMap::GetProjectionOffset,
                    [] (MaterialMap& self, DPoint3dCR offset) { self.SetProjectionOffset(offset.x, offset.y, offset.z); });
    c8.def("GetProjectionOffset", &MaterialMap::GetProjectionOffset, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMap, GetProjectionOffset));
    c8.def("SetProjectionOffset", &MaterialMap::SetProjectionOffset, "x"_a, "y"_a, "z"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetProjectionOffset));

    c8.def_property("ProjectionRotation",
                    &MaterialMap::GetProjectionRotation,
                    [] (MaterialMap& self, DPoint3dCR rotation) { self.SetProjectionRotation(rotation.x, rotation.y, rotation.z); });
    c8.def("GetProjectionRotation", &MaterialMap::GetProjectionRotation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMap, GetProjectionRotation));
    c8.def("SetProjectionRotation", &MaterialMap::SetProjectionRotation, "x"_a, "y"_a, "z"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetProjectionRotation));

    c8.def_property("ProjectionScale",
                    &MaterialMap::GetProjectionScale,
                    [] (MaterialMap& self, DPoint3dCR scale) { self.SetProjectionScale(scale.x, scale.y, scale.z); });
    c8.def("GetProjectionScale", &MaterialMap::GetProjectionScale, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMap, GetProjectionScale));
    c8.def("SetProjectionScale", &MaterialMap::SetProjectionScale, "x"_a, "y"_a, "z"_a, DOC(Bentley, DgnPlatform, MaterialMap, SetProjectionScale));

    c8.def_property_readonly("Layers", &MaterialMap::GetLayersR);
    c8.def("GetLayers", &MaterialMap::GetLayersR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMap, GetLayers));
    
    c8.def_property_readonly("Material", &MaterialMap::GetMaterialR);
    c8.def("GetMaterial", &MaterialMap::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMap, GetMaterial));
    
    //===================================================================================
    // struct MaterialMapCollection
    py::class_< MaterialMapCollection> c9(m, "MaterialMapCollection");

    c9.def("InitDefaults", &MaterialMapCollection::InitDefaults, DOC(Bentley, DgnPlatform, MaterialMapCollection, InitDefaults));
    c9.def("__eq__", [] (MaterialMapCollectionCR self, MaterialMapCollectionCR other) { return self.Equals(other); });
    c9.def("Copy", &MaterialMapCollection::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialMapCollection, Copy));
    c9.def("__len__", &MaterialMapCollection::Size);
    c9.def("Map", &MaterialMapCollection::GetMapP, "type"_a, py::return_value_policy::reference_internal);
    c9.def("DeleteMap", &MaterialMapCollection::DeleteMap, "type"_a, DOC(Bentley, DgnPlatform, MaterialMapCollection, DeleteMap));
    c9.def("AddMap", &MaterialMapCollection::AddMap, "type"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapCollection, AddMap));

    c9.def_property_readonly("Material", &MaterialMapCollection::GetMaterialR);
    c9.def("GetMaterial", &MaterialMapCollection::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialMapCollection, GetMaterial));
    
    c9.def("__iter__", [] (MaterialMapCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct MaterialFur
    py::class_< MaterialFur, RefCountedPtr<MaterialFur> > c10(m, "MaterialFur", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum FurType
        py::enum_< MaterialFur::FurType>(c10, "FurType", py::arithmetic())
            .value("eFURTYPE_Strips", MaterialFur::FURTYPE_Strips)
            .value("eFURTYPE_Cylinders", MaterialFur::FURTYPE_Cylinders)
            .export_values();

        //===================================================================================
        // enum FurGuides
        py::enum_< MaterialFur::FurGuides>(c10, "FurGuides", py::arithmetic())
            .value("eFURGUIDES_None", MaterialFur::FURGUIDES_None)
            .value("eFURGUIDES_Clump", MaterialFur::FURGUIDES_Clump)
            .value("eFURGUIDES_Direction", MaterialFur::FURGUIDES_Direction)
            .value("eFURGUIDES_DirectionLength", MaterialFur::FURGUIDES_DirectionLength)
            .value("eFURGUIDES_Shape", MaterialFur::FURGUIDES_Shape)
            .value("eFURGUIDES_Range", MaterialFur::FURGUIDES_Range)
            .export_values();

        //===================================================================================
        // enum FurBillboard
        py::enum_< MaterialFur::FurBillboard>(c10, "FurBillboard", py::arithmetic())
            .value("eFURBILLBOARD_Off", MaterialFur::FURBILLBOARD_Off)
            .value("eFURBILLBOARD_Tree", MaterialFur::FURBILLBOARD_Tree)
            .value("eFURBILLBOARD_Leaves", MaterialFur::FURBILLBOARD_Leaves)
            .export_values();
        }

    c10.def("InitDefaults", &MaterialFur::InitDefaults, DOC(Bentley, DgnPlatform, MaterialFur, InitDefaults));
    c10.def("__eq__", [] (MaterialFurCR self, MaterialFurCR other) { return self.Equals(other); });
    c10.def("Copy", &MaterialFur::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialFur, Copy));
    
    c10.def_property_readonly("Material", &MaterialFur::GetMaterialR);
    c10.def("GetMaterial", &MaterialFur::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialFur, GetMaterial));
    
    c10.def_property("IsUseAdaptiveSampling", &MaterialFur::UseAdaptiveSampling, &MaterialFur::SetUseAdaptiveSampling);
    c10.def("UseAdaptiveSampling", &MaterialFur::UseAdaptiveSampling, DOC(Bentley, DgnPlatform, MaterialFur, UseAdaptiveSampling));
    c10.def("SetUseAdaptiveSampling", &MaterialFur::SetUseAdaptiveSampling, "useAdaptive"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetUseAdaptiveSampling));
    
    c10.def_property("IsRemoveBaseSurface", &MaterialFur::RemoveBaseSurface, &MaterialFur::SetRemoveBaseSurface);
    c10.def("RemoveBaseSurface", &MaterialFur::RemoveBaseSurface, DOC(Bentley, DgnPlatform, MaterialFur, RemoveBaseSurface));
    c10.def("SetRemoveBaseSurface", &MaterialFur::SetRemoveBaseSurface, "removeBase"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetRemoveBaseSurface));
    
    c10.def_property("IsUseAutoFading", &MaterialFur::UseAutoFading, &MaterialFur::SetUseAutoFading);
    c10.def("UseAutoFading", &MaterialFur::UseAutoFading, DOC(Bentley, DgnPlatform, MaterialFur, UseAutoFading));
    c10.def("SetUseAutoFading", &MaterialFur::SetUseAutoFading, "autoFading"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetUseAutoFading));
    
    c10.def_property("IsUseHairShader", &MaterialFur::UseHairShader, &MaterialFur::SetUseHairShader);
    c10.def("UseHairShader", &MaterialFur::UseHairShader, DOC(Bentley, DgnPlatform, MaterialFur, UseHairShader));
    c10.def("SetUseHairShader", &MaterialFur::SetUseHairShader, "useHairShader"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetUseHairShader));
    
    c10.def_property("IsUseFurMaterial", &MaterialFur::UseFurMaterial, &MaterialFur::SetUseFurMaterial);
    c10.def("UseFurMaterial", &MaterialFur::UseFurMaterial, DOC(Bentley, DgnPlatform, MaterialFur, UseFurMaterial));
    c10.def("SetUseFurMaterial", &MaterialFur::SetUseFurMaterial, "furMaterial"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetUseFurMaterial));
    
    c10.def_property("IsUseFrustumCulling", &MaterialFur::UseFrustumCulling, &MaterialFur::SetUseFrustumCulling);
    c10.def("UseFrustumCulling", &MaterialFur::UseFrustumCulling, DOC(Bentley, DgnPlatform, MaterialFur, UseFrustumCulling));
    c10.def("SetUseFrustumCulling", &MaterialFur::SetUseFrustumCulling, "frustumCulling"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetUseFrustumCulling));
    
    c10.def_property("SpacingInMeters", &MaterialFur::GetSpacingInMeters, &MaterialFur::SetSpacingInMeters);
    c10.def("GetSpacingInMeters", &MaterialFur::GetSpacingInMeters, DOC(Bentley, DgnPlatform, MaterialFur, GetSpacingInMeters));
    c10.def("SetSpacingInMeters", &MaterialFur::SetSpacingInMeters, "spacing"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetSpacingInMeters));
    
    c10.def_property("LengthInMeters", &MaterialFur::GetLengthInMeters, &MaterialFur::SetLengthInMeters);
    c10.def("GetLengthInMeters", &MaterialFur::GetLengthInMeters, DOC(Bentley, DgnPlatform, MaterialFur, GetLengthInMeters));
    c10.def("SetLengthInMeters", &MaterialFur::SetLengthInMeters, "length"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetLengthInMeters));
    
    c10.def_property("WidthScale", &MaterialFur::GetWidthScale, &MaterialFur::SetWidthScale);
    c10.def("GetWidthScale", &MaterialFur::GetWidthScale, DOC(Bentley, DgnPlatform, MaterialFur, GetWidthScale));
    c10.def("SetWidthScale", &MaterialFur::SetWidthScale, "widthScale"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetWidthScale));
    
    c10.def_property("TaperScale", &MaterialFur::GetTaperScale, &MaterialFur::SetTaperScale);
    c10.def("GetTaperScale", &MaterialFur::GetTaperScale, DOC(Bentley, DgnPlatform, MaterialFur, GetTaperScale));
    c10.def("SetTaperScale", &MaterialFur::SetTaperScale, "taperScale"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetTaperScale));
    
    c10.def_property("OffsetInMeters", &MaterialFur::GetOffsetInMeters, &MaterialFur::SetOffsetInMeters);
    c10.def("GetOffsetInMeters", &MaterialFur::GetOffsetInMeters, DOC(Bentley, DgnPlatform, MaterialFur, GetOffsetInMeters));
    c10.def("SetOffsetInMeters", &MaterialFur::SetOffsetInMeters, "offset"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetOffsetInMeters));
    
    c10.def_property("StripRotation", &MaterialFur::GetStripRotation, &MaterialFur::SetStripRotation);
    c10.def("GetStripRotation", &MaterialFur::GetStripRotation, DOC(Bentley, DgnPlatform, MaterialFur, GetStripRotation));
    c10.def("SetStripRotation", &MaterialFur::SetStripRotation, "stripRotation"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetStripRotation));
    
    c10.def_property("GrowthJitter", &MaterialFur::GetGrowthJitter, &MaterialFur::SetGrowthJitter);
    c10.def("GetGrowthJitter", &MaterialFur::GetGrowthJitter, DOC(Bentley, DgnPlatform, MaterialFur, GetGrowthJitter));
    c10.def("SetGrowthJitter", &MaterialFur::SetGrowthJitter, "jitter"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetGrowthJitter));
    
    c10.def_property("PositionJitter", &MaterialFur::GetPositionJitter, &MaterialFur::SetPositionJitter);
    c10.def("GetPositionJitter", &MaterialFur::GetPositionJitter, DOC(Bentley, DgnPlatform, MaterialFur, GetPositionJitter));
    c10.def("SetPositionJitter", &MaterialFur::SetPositionJitter, "jitter"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetPositionJitter));
    
    c10.def_property("DirectionJitter", &MaterialFur::GetDirectionJitter, &MaterialFur::SetDirectionJitter);
    c10.def("GetDirectionJitter", &MaterialFur::GetDirectionJitter, DOC(Bentley, DgnPlatform, MaterialFur, GetDirectionJitter));
    c10.def("SetDirectionJitter", &MaterialFur::SetDirectionJitter, "jitter"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetDirectionJitter));
    
    c10.def_property("SizeJitter", &MaterialFur::GetSizeJitter, &MaterialFur::SetSizeJitter);
    c10.def("GetSizeJitter", &MaterialFur::GetSizeJitter, DOC(Bentley, DgnPlatform, MaterialFur, GetSizeJitter));
    c10.def("SetSizeJitter", &MaterialFur::SetSizeJitter, "jitter"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetSizeJitter));
    
    c10.def_property("Flex", &MaterialFur::GetFlex, &MaterialFur::SetFlex);
    c10.def("GetFlex", &MaterialFur::GetFlex, DOC(Bentley, DgnPlatform, MaterialFur, GetFlex));
    c10.def("SetFlex", &MaterialFur::SetFlex, "flex"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetFlex));
    
    c10.def_property("RootBend", &MaterialFur::GetRootBend, &MaterialFur::SetRootBend);
    c10.def("GetRootBend", &MaterialFur::GetRootBend, DOC(Bentley, DgnPlatform, MaterialFur, GetRootBend));
    c10.def("SetRootBend", &MaterialFur::SetRootBend, "rootBend"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetRootBend));
    
    c10.def_property("Curls", &MaterialFur::GetCurls, &MaterialFur::SetCurls);
    c10.def("GetCurls", &MaterialFur::GetCurls, DOC(Bentley, DgnPlatform, MaterialFur, GetCurls));
    c10.def("SetCurls", &MaterialFur::SetCurls, "curls"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetCurls));
    
    c10.def_property("BumpAmplitude", &MaterialFur::GetBumpAmplitude, &MaterialFur::SetBumpAmplitude);
    c10.def("GetBumpAmplitude", &MaterialFur::GetBumpAmplitude, DOC(Bentley, DgnPlatform, MaterialFur, GetBumpAmplitude));
    c10.def("SetBumpAmplitude", &MaterialFur::SetBumpAmplitude, "amplitude"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetBumpAmplitude));
    
    c10.def_property("GuideRangeInMeters", &MaterialFur::GetGuideRangeInMeters, &MaterialFur::SetGuideRangeInMeters);
    c10.def("GetGuideRangeInMeters", &MaterialFur::GetGuideRangeInMeters, DOC(Bentley, DgnPlatform, MaterialFur, GetGuideRangeInMeters));
    c10.def("SetGuideRangeInMeters", &MaterialFur::SetGuideRangeInMeters, "guideRange"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetGuideRangeInMeters));
    
    c10.def_property("GuideLengthInMeters", &MaterialFur::GetGuideLengthInMeters, &MaterialFur::SetGuideLengthInMeters);
    c10.def("GetGuideLengthInMeters", &MaterialFur::GetGuideLengthInMeters, DOC(Bentley, DgnPlatform, MaterialFur, GetGuideLengthInMeters));
    c10.def("SetGuideLengthInMeters", &MaterialFur::SetGuideLengthInMeters, "guideLength"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetGuideLengthInMeters));
    
    c10.def_property("BlendAmount", &MaterialFur::GetBlendAmount, &MaterialFur::SetBlendAmount);
    c10.def("GetBlendAmount", &MaterialFur::GetBlendAmount);
    c10.def("SetBlendAmount", &MaterialFur::SetBlendAmount, "blendAmount"_a);
    
    c10.def_property("BlendAngle", &MaterialFur::GetBlendAngle, &MaterialFur::SetBlendAngle);
    c10.def("GetBlendAngle", &MaterialFur::GetBlendAngle);
    c10.def("SetBlendAngle", &MaterialFur::SetBlendAngle, "angle"_a);
    
    c10.def_property("ClumpScale", &MaterialFur::GetClumpScale, &MaterialFur::SetClumpScale);
    c10.def("GetClumpScale", &MaterialFur::GetClumpScale, DOC(Bentley, DgnPlatform, MaterialFur, GetClumpScale));
    c10.def("SetClumpScale", &MaterialFur::SetClumpScale, "scale"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetClumpScale));
    
    c10.def_property("ClumpRangeInMeters", &MaterialFur::GetClumpRangeInMeters, &MaterialFur::SetClumpRangeInMeters);
    c10.def("GetClumpRangeInMeters", &MaterialFur::GetClumpRangeInMeters, DOC(Bentley, DgnPlatform, MaterialFur, GetClumpRangeInMeters));
    c10.def("SetClumpRangeInMeters", &MaterialFur::SetClumpRangeInMeters, "clumpRange"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetClumpRangeInMeters));
    
    c10.def_property("Rate", &MaterialFur::GetRate, &MaterialFur::SetRate);
    c10.def("GetRate", &MaterialFur::GetRate, DOC(Bentley, DgnPlatform, MaterialFur, GetRate));
    c10.def("SetRate", &MaterialFur::SetRate, "rate"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetRate));
    
    c10.def_property("Type", &MaterialFur::GetType, &MaterialFur::SetType);
    c10.def("GetType", &MaterialFur::GetType, DOC(Bentley, DgnPlatform, MaterialFur, GetType));
    c10.def("SetType", &MaterialFur::SetType, "type"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetType));
    
    c10.def_property("FurGuides", &MaterialFur::GetFurGuides, &MaterialFur::SetFurGuides);
    c10.def("GetFurGuides", &MaterialFur::GetFurGuides, DOC(Bentley, DgnPlatform, MaterialFur, GetFurGuides));
    c10.def("SetFurGuides", &MaterialFur::SetFurGuides, "furGuides"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetFurGuides));
    
    c10.def_property("SegmentCount", &MaterialFur::GetSegmentCount, &MaterialFur::SetSegmentCount);
    c10.def("GetSegmentCount", &MaterialFur::GetSegmentCount, DOC(Bentley, DgnPlatform, MaterialFur, GetSegmentCount));
    c10.def("SetSegmentCount", &MaterialFur::SetSegmentCount, "count"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetSegmentCount));
    
    c10.def_property("FurBillboard", &MaterialFur::GetFurBillboard, &MaterialFur::SetFurBillboard);
    c10.def("GetFurBillboard", &MaterialFur::GetFurBillboard, DOC(Bentley, DgnPlatform, MaterialFur, GetFurBillboard));
    c10.def("SetFurBillboard", &MaterialFur::SetFurBillboard, "furBillboard"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetFurBillboard));
    
    c10.def_property("FurMaterialName", &MaterialFur::GetFurMaterialName, &MaterialFur::SetFurMaterialName);
    c10.def("GetFurMaterialName", &MaterialFur::GetFurMaterialName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialFur, GetFurMaterialName));
    c10.def("SetFurMaterialName", &MaterialFur::SetFurMaterialName, "name"_a, DOC(Bentley, DgnPlatform, MaterialFur, SetFurMaterialName));
    
    c10.def_property_readonly("FurMaterialPalette", &MaterialFur::GetFurMaterialPaletteR);
    c10.def("GetFurMaterialPalette", &MaterialFur::GetFurMaterialPaletteR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialFur, GetFurMaterialPalette));

    //===================================================================================
    // struct MaterialShader
    py::class_< MaterialShader, MaterialShaderPtr> c11(m, "MaterialShader", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum ShaderType
        py::enum_< MaterialShader::ShaderType>(c11, "ShaderType", py::arithmetic())
            .value("eSHADERTYPE_Default", MaterialShader::SHADERTYPE_Default)
            .value("eSHADERTYPE_MultiMaterial", MaterialShader::SHADERTYPE_MultiMaterial)
            .export_values();

        //===================================================================================
        // enum IlluminationType
        py::enum_< MaterialShader::IlluminationType>(c11, "IlluminationType", py::arithmetic())
            .value("eILLUMTYPE_None", MaterialShader::ILLUMTYPE_None)
            .value("eILLUMTYPE_MonteCarlo", MaterialShader::ILLUMTYPE_MonteCarlo)
            .value("eILLUMTYPE_IrradianceCaching", MaterialShader::ILLUMTYPE_IrradianceCaching)
            .export_values();

        //===================================================================================
        // enum BlendMode
        py::enum_< MaterialShader::BlendMode>(c11, "BlendMode", py::arithmetic())
            .value("eBLENDMODE_Normal", MaterialShader::BLENDMODE_Normal)
            .value("eBLENDMODE_Add", MaterialShader::BLENDMODE_Add)
            .value("eBLENDMODE_Subtract", MaterialShader::BLENDMODE_Subtract)
            .value("eBLENDMODE_Difference", MaterialShader::BLENDMODE_Difference)
            .value("eBLENDMODE_NormalMultiply", MaterialShader::BLENDMODE_NormalMultiply)
            .value("eBLENDMODE_Divide", MaterialShader::BLENDMODE_Divide)
            .value("eBLENDMODE_Multiply", MaterialShader::BLENDMODE_Multiply)
            .value("eBLENDMODE_Screen", MaterialShader::BLENDMODE_Screen)
            .value("eBLENDMODE_Overlay", MaterialShader::BLENDMODE_Overlay)
            .value("eBLENDMODE_SoftLight", MaterialShader::BLENDMODE_SoftLight)
            .value("eBLENDMODE_HardLight", MaterialShader::BLENDMODE_HardLight)
            .value("eBLENDMODE_Darken", MaterialShader::BLENDMODE_Darken)
            .value("eBLENDMODE_Lighten", MaterialShader::BLENDMODE_Lighten)
            .value("eBLENDMODE_ColorDodge", MaterialShader::BLENDMODE_ColorDodge)
            .value("eBLENDMODE_ColorBurn", MaterialShader::BLENDMODE_ColorBurn)
            .export_values();

        //===================================================================================
        // enum ShaderEffect
        py::enum_< MaterialShader::ShaderEffect>(c11, "ShaderEffect", py::arithmetic())
            .value("eSHADEREFFECT_FullShading", MaterialShader::SHADEREFFECT_FullShading)
            .value("eSHADEREFFECT_Diffuse", MaterialShader::SHADEREFFECT_Diffuse)
            .value("eSHADEREFFECT_Luminous", MaterialShader::SHADEREFFECT_Luminous)
            .value("eSHADEREFFECT_Reflection", MaterialShader::SHADEREFFECT_Reflection)
            .value("eSHADEREFFECT_Specular", MaterialShader::SHADEREFFECT_Specular)
            .value("eSHADEREFFECT_SubSurface", MaterialShader::SHADEREFFECT_SubSurface)
            .value("eSHADEREFFECT_Transparent", MaterialShader::SHADEREFFECT_Transparent)
            .value("eSHADEREFFECT_Fog", MaterialShader::SHADEREFFECT_Fog)
            .export_values();
        }

    c11.def("InitDefaults", &MaterialShader::InitDefaults, DOC(Bentley, DgnPlatform, MaterialShader, InitDefaults));
    c11.def("__eq__", [] (MaterialShaderCR self, MaterialShaderCR other) { return self.Equals(other); });
    c11.def("Copy", &MaterialShader::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialShader, Copy));
    
    c11.def_property_readonly("Material", &MaterialShader::GetMaterialR);
    c11.def("GetMaterial", &MaterialShader::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialShader, GetMaterial));
    
    c11.def_property("Enabled", &MaterialShader::IsEnabled, &MaterialShader::SetIsEnabled);
    c11.def("IsEnabled", &MaterialShader::IsEnabled, DOC(Bentley, DgnPlatform, MaterialShader, IsEnabled));
    c11.def("SetIsEnabled", &MaterialShader::SetIsEnabled, "enabled"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsEnabled));
    
    c11.def_property("Type", &MaterialShader::GetType, &MaterialShader::SetType);
    c11.def("GetType", &MaterialShader::GetType, DOC(Bentley, DgnPlatform, MaterialShader, GetType));
    c11.def("SetType", &MaterialShader::SetType, "type"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetType));
    
    c11.def_property("Inverted", &MaterialShader::IsInverted, &MaterialShader::SetIsInverted);
    c11.def("IsInverted", &MaterialShader::IsInverted, DOC(Bentley, DgnPlatform, MaterialShader, IsInverted));
    c11.def("SetIsInverted", &MaterialShader::SetIsInverted, "inverted"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsInverted));
    
    c11.def_property("ReceivesShadows", &MaterialShader::ReceivesShadows, &MaterialShader::SetReceivesShadows);
    c11.def("GetReceivesShadows", &MaterialShader::ReceivesShadows);
    c11.def("SetReceivesShadows", &MaterialShader::SetReceivesShadows, "receiveShadows"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetReceivesShadows));
    
    c11.def_property("CastsShadows", &MaterialShader::CastsShadows, &MaterialShader::SetCastsShadows);
    c11.def("GetCastsShadows", &MaterialShader::CastsShadows);
    c11.def("SetCastsShadows", &MaterialShader::SetCastsShadows, "castsShadows"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetCastsShadows));
    
    c11.def_property("VisibleToCamera", &MaterialShader::IsVisibleToCamera, &MaterialShader::SetIsVisibleToCamera);
    c11.def("IsVisibleToCamera", &MaterialShader::IsVisibleToCamera, DOC(Bentley, DgnPlatform, MaterialShader, IsVisibleToCamera));
    c11.def("SetIsVisibleToCamera", &MaterialShader::SetIsVisibleToCamera, "visible"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsVisibleToCamera));
    
    c11.def_property("VisibleToIndirectRays", &MaterialShader::IsVisibleToIndirectRays, &MaterialShader::SetIsVisibleToIndirectRays);
    c11.def("IsVisibleToIndirectRays", &MaterialShader::IsVisibleToIndirectRays, DOC(Bentley, DgnPlatform, MaterialShader, IsVisibleToIndirectRays));
    c11.def("SetIsVisibleToIndirectRays", &MaterialShader::SetIsVisibleToIndirectRays, "visible"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsVisibleToIndirectRays));
    
    c11.def_property("VisibleToReflectionRays", &MaterialShader::IsVisibleToReflectionRays, &MaterialShader::SetIsVisibleToReflectionRays);
    c11.def("IsVisibleToReflectionRays", &MaterialShader::IsVisibleToReflectionRays, DOC(Bentley, DgnPlatform, MaterialShader, IsVisibleToReflectionRays));
    c11.def("SetIsVisibleToReflectionRays", &MaterialShader::SetIsVisibleToReflectionRays, "visible"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsVisibleToReflectionRays));
    
    c11.def_property("VisibleToOcclusionRays", &MaterialShader::IsVisibleToOcclusionRays, &MaterialShader::SetIsVisibleToOcclusionRays);
    c11.def("IsVisibleToOcclusionRays", &MaterialShader::IsVisibleToOcclusionRays, DOC(Bentley, DgnPlatform, MaterialShader, IsVisibleToOcclusionRays));
    c11.def("SetIsVisibleToOcclusionRays", &MaterialShader::SetIsVisibleToOcclusionRays, "visible"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsVisibleToOcclusionRays));
    
    c11.def_property("VisibleToRefractionRays", &MaterialShader::IsVisibleToRefractionRays, &MaterialShader::SetIsVisibleToRefractionRays);
    c11.def("IsVisibleToRefractionRays", &MaterialShader::IsVisibleToRefractionRays, DOC(Bentley, DgnPlatform, MaterialShader, IsVisibleToRefractionRays));
    c11.def("SetIsVisibleToRefractionRays", &MaterialShader::SetIsVisibleToRefractionRays, "visible"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIsVisibleToRefractionRays));
    
    c11.def_property("ShadingRate", &MaterialShader::GetShadingRate, &MaterialShader::SetShadingRate);
    c11.def("GetShadingRate", &MaterialShader::GetShadingRate, DOC(Bentley, DgnPlatform, MaterialShader, GetShadingRate));
    c11.def("SetShadingRate", &MaterialShader::SetShadingRate, "rate"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetShadingRate));
    
    c11.def_property("DirectIlluminationMultiplier", &MaterialShader::GetDirectIlluminationMultiplier, &MaterialShader::SetDirectIlluminationMultiplier);
    c11.def("GetDirectIlluminationMultiplier", &MaterialShader::GetDirectIlluminationMultiplier, DOC(Bentley, DgnPlatform, MaterialShader, GetDirectIlluminationMultiplier));
    c11.def("SetDirectIlluminationMultiplier", &MaterialShader::SetDirectIlluminationMultiplier, "multiplier"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetDirectIlluminationMultiplier));
    
    c11.def_property("IndirectIlluminationMultiplier", &MaterialShader::GetIndirectIlluminationMultiplier, &MaterialShader::SetIndirectIlluminationMultiplier);
    c11.def("GetIndirectIlluminationMultiplier", &MaterialShader::GetIndirectIlluminationMultiplier, DOC(Bentley, DgnPlatform, MaterialShader, GetIndirectIlluminationMultiplier));
    c11.def("SetIndirectIlluminationMultiplier", &MaterialShader::SetIndirectIlluminationMultiplier, "multiplier"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIndirectIlluminationMultiplier));
    
    c11.def_property("Opacity", &MaterialShader::GetOpacity, &MaterialShader::SetOpacity);
    c11.def("GetOpacity", &MaterialShader::GetOpacity, DOC(Bentley, DgnPlatform, MaterialShader, GetOpacity));
    c11.def("SetOpacity", &MaterialShader::SetOpacity, "opacity"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetOpacity));
    
    c11.def_property("IndirectIlluminationType", &MaterialShader::GetIndirectIlluminationType, &MaterialShader::SetIndirectIlluminationType);
    c11.def("GetIndirectIlluminationType", &MaterialShader::GetIndirectIlluminationType, DOC(Bentley, DgnPlatform, MaterialShader, GetIndirectIlluminationType));
    c11.def("SetIndirectIlluminationType", &MaterialShader::SetIndirectIlluminationType, "type"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetIndirectIlluminationType));
    
    c11.def_property("BlendMode", &MaterialShader::GetBlendMode, &MaterialShader::SetBlendMode);
    c11.def("GetBlendMode", &MaterialShader::GetBlendMode, DOC(Bentley, DgnPlatform, MaterialShader, GetBlendMode));
    c11.def("SetBlendMode", &MaterialShader::SetBlendMode, "mode"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetBlendMode));
    
    c11.def_property("Effect", &MaterialShader::GetEffect, &MaterialShader::SetEffect);
    c11.def("GetEffect", &MaterialShader::GetEffect, DOC(Bentley, DgnPlatform, MaterialShader, GetEffect));
    c11.def("SetEffect", &MaterialShader::SetEffect, "effect"_a, DOC(Bentley, DgnPlatform, MaterialShader, SetEffect));

    //===================================================================================
    // struct MaterialShaderCollection
    py::class_< MaterialShaderCollection> c12(m, "MaterialShaderCollection");

    c12.def("InitDefaults", &MaterialShaderCollection::InitDefaults, DOC(Bentley, DgnPlatform, MaterialShaderCollection, InitDefaults));
    c12.def("__eq__", [] (MaterialShaderCollectionCR self, MaterialShaderCollectionCR other) { return self.Equals(other); });
    c12.def("Copy", &MaterialShaderCollection::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialShaderCollection, Copy));
    
    c12.def_property_readonly("Material", &MaterialShaderCollection::GetMaterialR);
    c12.def("GetMaterial", &MaterialShaderCollection::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialShaderCollection, GetMaterial));
    
    c12.def("__len__", &MaterialShaderCollection::Size);
    
    c12.def_property_readonly("TopShader", &MaterialShaderCollection::GetTopShaderR);
    c12.def("GetTopShader", &MaterialShaderCollection::GetTopShaderR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialShaderCollection, GetTopShader));
    
    c12.def("AddShader", &MaterialShaderCollection::AddShader, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialShaderCollection, AddShader));
    

    c12.def("__iter__", [] (MaterialShaderCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct PBRMaterialSettings
    py::class_< PBRMaterialSettings, PBRMaterialSettingsPtr> c13(m, "PBRMaterialSettings", py::multiple_inheritance());

    c13.def_property_readonly("Material", &PBRMaterialSettings::GetMaterialR);
    c13.def("GetMaterial", &PBRMaterialSettings::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetMaterial));
    
    c13.def_property_readonly("Maps", &PBRMaterialSettings::GetMapsR);
    c13.def("GetMaps", &PBRMaterialSettings::GetMapsR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetMaps));
    
    c13.def("HasBaseColor", &PBRMaterialSettings::HasBaseColor, DOC(Bentley, DgnPlatform, PBRMaterialSettings, HasBaseColor));
    c13.def("SetHasBaseColor", &PBRMaterialSettings::SetHasBaseColor, "hasBaseColor"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetHasBaseColor));

    c13.def_property("BaseColor",
                    &PBRMaterialSettings::GetBaseColorR,
                    [] (PBRMaterialSettings& self, RgbFactorCR color) { self.SetBaseColor(color.red, color.green, color.blue); });
    c13.def("GetBaseColor", &PBRMaterialSettings::GetBaseColor, py::return_value_policy::reference_internal);
    c13.def("SetBaseColor", &PBRMaterialSettings::SetBaseColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetBaseColor));

    c13.def_property("TransmitIntensity", &PBRMaterialSettings::GetTransmitIntensity, &PBRMaterialSettings::SetTransmitIntensity);
    c13.def("GetTransmitIntensity", &PBRMaterialSettings::GetTransmitIntensity, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetTransmitIntensity));
    c13.def("SetTransmitIntensity", &PBRMaterialSettings::SetTransmitIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetTransmitIntensity));
    
    c13.def_property("MetalInsulatorRatio", &PBRMaterialSettings::GetMetalInsulatorRatio, &PBRMaterialSettings::SetMetalInsulatorRatio);
    c13.def("GetMetalInsulatorRatio", &PBRMaterialSettings::GetMetalInsulatorRatio, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetMetalInsulatorRatio));
    c13.def("SetMetalInsulatorRatio", &PBRMaterialSettings::SetMetalInsulatorRatio, "ratio"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetMetalInsulatorRatio));
    
    c13.def_property("Roughness", &PBRMaterialSettings::GetRoughness, &PBRMaterialSettings::SetRoughness);
    c13.def("GetRoughness", &PBRMaterialSettings::GetRoughness, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetRoughness));
    c13.def("SetRoughness", &PBRMaterialSettings::SetRoughness, "roughness"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetRoughness));
    
    c13.def_property("HeightMapScale", &PBRMaterialSettings::GetHeightMapScale, &PBRMaterialSettings::SetHeightMapScale);
    c13.def("GetHeightMapScale", &PBRMaterialSettings::GetHeightMapScale, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetHeightMapScale));
    c13.def("SetHeightMapScale", &PBRMaterialSettings::SetHeightMapScale, "scale"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetHeightMapScale));
    
    c13.def_property("NormalMapScale", &PBRMaterialSettings::GetNormalMapScale, &PBRMaterialSettings::SetNormalMapScale);
    c13.def("GetNormalMapScale", &PBRMaterialSettings::GetNormalMapScale, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetNormalMapScale));
    c13.def("SetNormalMapScale", &PBRMaterialSettings::SetNormalMapScale, "scale"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetNormalMapScale));
    
    c13.def_property("AmbientOcclusionMapScale", &PBRMaterialSettings::GetAmbientOcclusionMapScale, &PBRMaterialSettings::SetAmbientOcclusionMapScale);
    c13.def("GetAmbientOcclusionMapScale", &PBRMaterialSettings::GetAmbientOcclusionMapScale, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetAmbientOcclusionMapScale));
    c13.def("SetAmbientOcclusionMapScale", &PBRMaterialSettings::SetAmbientOcclusionMapScale, "scale"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetAmbientOcclusionMapScale));

    c13.def_property("EmissiveColor", &PBRMaterialSettings::GetEmissiveColorR, [] (PBRMaterialSettings& self, RgbFactorCR color) { self.SetEmissiveColor(color.red, color.green, color.blue); });
    c13.def("GetEmissiveColor", &PBRMaterialSettings::GetEmissiveColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetEmissiveColor));
    c13.def("SetEmissiveColor", &PBRMaterialSettings::SetEmissiveColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetEmissiveColor));    

    c13.def_property("RefractIndex", &PBRMaterialSettings::GetRefractIndex, &PBRMaterialSettings::SetRefractIndex);
    c13.def("GetRefractIndex", &PBRMaterialSettings::GetRefractIndex, DOC(Bentley, DgnPlatform, PBRMaterialSettings, GetRefractIndex));
    c13.def("SetRefractIndex", &PBRMaterialSettings::SetRefractIndex, "index"_a, DOC(Bentley, DgnPlatform, PBRMaterialSettings, SetRefractIndex));

    //===================================================================================
    // struct MaterialSettings
    py::class_< MaterialSettings, std::unique_ptr<MaterialSettings, py::nodelete> > c14(m, "MaterialSettings");

    if (true)
        {
        //===================================================================================
        // enum ShaderEffect
        py::enum_< MaterialSettings::BackFaceCulling>(c14, "BackFaceCulling", py::arithmetic())
            .value("eBACKFACECULLING_UseGeometryDefault", MaterialSettings::BACKFACECULLING_UseGeometryDefault)
            .value("eBACKFACECULLING_ForceSingleSided", MaterialSettings::BACKFACECULLING_ForceSingleSided)
            .value("eBACKFACECULLING_ForceDoubleSided", MaterialSettings::BACKFACECULLING_ForceDoubleSided)
            .export_values();
        }
    c14.def("InitDefaults", &MaterialSettings::InitDefaults, DOC(Bentley, DgnPlatform, MaterialSettings, InitDefaults));
    c14.def("__eq__", [] (MaterialSettingsCR self, MaterialSettingsCR other) { return self.Equals(other); });
    c14.def("Copy", &MaterialSettings::Copy, "rhs"_a, DOC(Bentley, DgnPlatform, MaterialSettings, Copy));
    
    c14.def_property_readonly("Shaders", &MaterialSettings::GetShadersR);
    c14.def("GetShaders", &MaterialSettings::GetShadersR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetShaders));
    
    c14.def_property_readonly("Material", &MaterialSettings::GetMaterialR);
    c14.def("GetMaterial", &MaterialSettings::GetMaterialR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetMaterial));
    
    c14.def_property_readonly("Fur", &MaterialSettings::GetFurR);
    c14.def("GetFur", &MaterialSettings::GetFurR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetFur));
    
    c14.def("AddFur", &MaterialSettings::AddFur, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, AddFur));
    c14.def("DeleteFur", &MaterialSettings::DeleteFur, DOC(Bentley, DgnPlatform, MaterialSettings, DeleteFur));
    
    c14.def_property("IsUseFur", &MaterialSettings::UseFur, &MaterialSettings::SetUseFur);
    c14.def("UseFur", &MaterialSettings::UseFur, DOC(Bentley, DgnPlatform, MaterialSettings, UseFur));
    c14.def("SetUseFur", &MaterialSettings::SetUseFur, "useFur"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetUseFur));
    
    c14.def_property_readonly("Maps", &MaterialSettings::GetMapsR);
    c14.def("GetMaps", &MaterialSettings::GetMapsR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetMaps));

    c14.def("HasBaseColor", &MaterialSettings::HasBaseColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasBaseColor));
    c14.def("SetHasBaseColor", &MaterialSettings::SetHasBaseColor, "hasBaseColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasBaseColor));
    
    c14.def("HasSpecularColor", &MaterialSettings::HasSpecularColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasSpecularColor));
    c14.def("SetHasSpecularColor", &MaterialSettings::SetHasSpecularColor, "hasSpecularColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasSpecularColor));    
    
    c14.def("HasTransmitColor", &MaterialSettings::HasTransmitColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasTransmitColor));
    c14.def("SetHasTransmitColor", &MaterialSettings::SetHasTransmitColor, "hasTransmitColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasTransmitColor));    
    
    c14.def("HasTranslucencyColor", &MaterialSettings::HasTranslucencyColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasTranslucencyColor));
    c14.def("SetHasTranslucencyColor", &MaterialSettings::SetHasTranslucencyColor, "hasTranslucencyColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasTranslucencyColor));    
    
    c14.def("HasGlowColor", &MaterialSettings::HasGlowColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasGlowColor));
    c14.def("SetHasGlowColor", &MaterialSettings::SetHasGlowColor, "hasGlowColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasGlowColor));    
    
    c14.def("HasReflectColor", &MaterialSettings::HasReflectColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasReflectColor));
    c14.def("SetHasReflectColor", &MaterialSettings::SetHasReflectColor, "hasReflectColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasReflectColor));    
    
    c14.def("HasExitColor", &MaterialSettings::HasExitColor, DOC(Bentley, DgnPlatform, MaterialSettings, HasExitColor));
    c14.def("SetHasExitColor", &MaterialSettings::SetHasExitColor, "hasExitColor"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasExitColor));    
    
    c14.def("HasDiffuseIntensity", &MaterialSettings::HasDiffuseIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, HasDiffuseIntensity));
    c14.def("SetHasDiffuseIntensity", &MaterialSettings::SetHasDiffuseIntensity, "hasDiffuseIntensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasDiffuseIntensity));    
    
    c14.def("HasSpecularIntensity", &MaterialSettings::HasSpecularIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, HasSpecularIntensity));
    c14.def("SetHasSpecularIntensity", &MaterialSettings::SetHasSpecularIntensity, "hasSpecularIntensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasSpecularIntensity));    
    
    c14.def("HasFinishScale", &MaterialSettings::HasFinishScale, DOC(Bentley, DgnPlatform, MaterialSettings, HasFinishScale));
    c14.def("SetHasFinishScale", &MaterialSettings::SetHasFinishScale, "hasFinishScale"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasFinishScale));    
    
    c14.def("HasRefractIndex", &MaterialSettings::HasRefractIndex, DOC(Bentley, DgnPlatform, MaterialSettings, HasRefractIndex));
    c14.def("SetHasRefractIndex", &MaterialSettings::SetHasRefractIndex, "hasRefractIndex"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasRefractIndex));    
    
    c14.def("HasReflectIntensity", &MaterialSettings::HasReflectIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, HasReflectIntensity));
    c14.def("SetHasReflectIntensity", &MaterialSettings::SetHasReflectIntensity, "hasReflectIntensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasReflectIntensity));    
    
    c14.def("HasTransmitIntensity", &MaterialSettings::HasTransmitIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, HasTransmitIntensity));
    c14.def("SetHasTransmitIntensity", &MaterialSettings::SetHasTransmitIntensity, "hasTrasmitIntensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasTransmitIntensity));

    c14.def_property("BaseColor", &MaterialSettings::GetBaseColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetBaseColor(color.red, color.green, color.blue); });
    c14.def("GetBaseColor", &MaterialSettings::GetBaseColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetBaseColor));
    c14.def("SetBaseColor", &MaterialSettings::SetBaseColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetBaseColor));

    c14.def_property("SpecularColor", &MaterialSettings::GetSpecularColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetSpecularColor(color.red, color.green, color.blue); });
    c14.def("GetSpecularColor", &MaterialSettings::GetSpecularColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetSpecularColor));
    c14.def("SetSpecularColor", &MaterialSettings::SetSpecularColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetSpecularColor));

    c14.def_property("TransmitColor", &MaterialSettings::GetTransmitColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetTransmitColor(color.red, color.green, color.blue); });
    c14.def("GetTransmitColor", &MaterialSettings::GetTransmitColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetTransmitColor));
    c14.def("SetTransmitColor", &MaterialSettings::SetTransmitColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetTransmitColor));

    c14.def_property("TranslucencyColor", &MaterialSettings::GetTranslucencyColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetTranslucencyColor(color.red, color.green, color.blue); });
    c14.def("GetTranslucencyColor", &MaterialSettings::GetTranslucencyColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetTranslucencyColor));
    c14.def("SetTranslucencyColor", &MaterialSettings::SetTranslucencyColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetTranslucencyColor));

    c14.def_property("GlowColor", &MaterialSettings::GetGlowColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetGlowColor(color.red, color.green, color.blue); });
    c14.def("GetGlowColor", &MaterialSettings::GetGlowColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetGlowColor));
    c14.def("SetGlowColor", &MaterialSettings::SetGlowColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetGlowColor));

    c14.def_property("ReflectColor", &MaterialSettings::GetReflectColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetReflectColor(color.red, color.green, color.blue); });
    c14.def("GetReflectColor", &MaterialSettings::GetReflectColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetReflectColor));
    c14.def("SetReflectColor", &MaterialSettings::SetReflectColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetReflectColor));

    c14.def_property("ExitColor", &MaterialSettings::GetExitColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetExitColor(color.red, color.green, color.blue); });
    c14.def("GetExitColor", &MaterialSettings::GetExitColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetExitColor));
    c14.def("SetExitColor", &MaterialSettings::SetExitColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetExitColor));
    
    c14.def_property("AmbientIntensity", &MaterialSettings::GetAmbientIntensity, &MaterialSettings::SetAmbientIntensity);
    c14.def("GetAmbientIntensity", &MaterialSettings::GetAmbientIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, GetAmbientIntensity));
    c14.def("SetAmbientIntensity", &MaterialSettings::SetAmbientIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetAmbientIntensity));
    c14.def_property("FinishScale", &MaterialSettings::GetFinishScale, &MaterialSettings::SetFinishScale);
    c14.def("GetFinishScale", &MaterialSettings::GetFinishScale, DOC(Bentley, DgnPlatform, MaterialSettings, GetFinishScale));
    c14.def("SetFinishScale", &MaterialSettings::SetFinishScale, "scale"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetFinishScale));
    
    c14.def_property("ReflectIntensity", &MaterialSettings::GetReflectIntensity, &MaterialSettings::SetReflectIntensity);
    c14.def("GetReflectIntensity", &MaterialSettings::GetReflectIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, GetReflectIntensity));
    c14.def("SetReflectIntensity", &MaterialSettings::SetReflectIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetReflectIntensity));
    
    c14.def_property("TransmitIntensity", &MaterialSettings::GetTransmitIntensity, &MaterialSettings::SetTransmitIntensity);
    c14.def("GetTransmitIntensity", &MaterialSettings::GetTransmitIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, GetTransmitIntensity));
    c14.def("SetTransmitIntensity", &MaterialSettings::SetTransmitIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetTransmitIntensity));
    
    c14.def_property("DiffuseIntensity", &MaterialSettings::GetDiffuseIntensity, &MaterialSettings::SetDiffuseIntensity);
    c14.def("GetDiffuseIntensity", &MaterialSettings::GetDiffuseIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, GetDiffuseIntensity));
    c14.def("SetDiffuseIntensity", &MaterialSettings::SetDiffuseIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetDiffuseIntensity));
    
    c14.def_property("DiffuseRoughness", &MaterialSettings::GetDiffuseRoughness, &MaterialSettings::SetDiffuseRoughness);
    c14.def("GetDiffuseRoughness", &MaterialSettings::GetDiffuseRoughness, DOC(Bentley, DgnPlatform, MaterialSettings, GetDiffuseRoughness));
    c14.def("SetDiffuseRoughness", &MaterialSettings::SetDiffuseRoughness, "roughness"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetDiffuseRoughness));
    
    c14.def_property("RoundedEdgeWidth", &MaterialSettings::GetRoundedEdgeWidth, &MaterialSettings::SetRoundedEdgeWidth);
    c14.def("GetRoundedEdgeWidth", &MaterialSettings::GetRoundedEdgeWidth, DOC(Bentley, DgnPlatform, MaterialSettings, GetRoundedEdgeWidth));
    c14.def("SetRoundedEdgeWidth", &MaterialSettings::SetRoundedEdgeWidth, "width"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetRoundedEdgeWidth));
    
    c14.def_property("SpecularIntensity", &MaterialSettings::GetSpecularIntensity, &MaterialSettings::SetSpecularIntensity);
    c14.def("GetSpecularIntensity", &MaterialSettings::GetSpecularIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, GetSpecularIntensity));
    c14.def("SetSpecularIntensity", &MaterialSettings::SetSpecularIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetSpecularIntensity));
    
    c14.def_property("RefractIndex", &MaterialSettings::GetRefractIndex, &MaterialSettings::SetRefractIndex);
    c14.def("GetRefractIndex", &MaterialSettings::GetRefractIndex, DOC(Bentley, DgnPlatform, MaterialSettings, GetRefractIndex));
    c14.def("SetRefractIndex", &MaterialSettings::SetRefractIndex, "index"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetRefractIndex));
    
    c14.def_property("GlowIntensity", &MaterialSettings::GetGlowIntensity, &MaterialSettings::SetGlowIntensity);
    c14.def("GetGlowIntensity", &MaterialSettings::GetGlowIntensity, DOC(Bentley, DgnPlatform, MaterialSettings, GetGlowIntensity));
    c14.def("SetGlowIntensity", &MaterialSettings::SetGlowIntensity, "intensity"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetGlowIntensity));
    
    c14.def_property("TranslucencyScale", &MaterialSettings::GetTranslucencyScale, &MaterialSettings::SetTranslucencyScale);
    c14.def("GetTranslucencyScale", &MaterialSettings::GetTranslucencyScale, DOC(Bentley, DgnPlatform, MaterialSettings, GetTranslucencyScale));
    c14.def("SetTranslucencyScale", &MaterialSettings::SetTranslucencyScale, "scale"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetTranslucencyScale));
    
    c14.def_property("IsCastsShadows", &MaterialSettings::CastsShadows, &MaterialSettings::SetCastsShadows);
    c14.def("CastsShadows", &MaterialSettings::CastsShadows, DOC(Bentley, DgnPlatform, MaterialSettings, CastsShadows));
    c14.def("SetCastsShadows", &MaterialSettings::SetCastsShadows, "castsShadows"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetCastsShadows));
    
    c14.def_property("Visible", &MaterialSettings::IsVisible, &MaterialSettings::SetIsVisible);
    c14.def("IsVisible", &MaterialSettings::IsVisible, DOC(Bentley, DgnPlatform, MaterialSettings, IsVisible));
    c14.def("SetIsVisible", &MaterialSettings::SetIsVisible, "visible"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetIsVisible));
    
    c14.def_property("ReflectionRays", &MaterialSettings::GetReflectionRays, &MaterialSettings::SetReflectionRays);
    c14.def("GetReflectionRays", &MaterialSettings::GetReflectionRays, DOC(Bentley, DgnPlatform, MaterialSettings, GetReflectionRays));
    c14.def("SetReflectionRays", &MaterialSettings::SetReflectionRays, "rays"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetReflectionRays));
    
    c14.def_property("RefractionRays", &MaterialSettings::GetRefractionRays, &MaterialSettings::SetRefractionRays);
    c14.def("GetRefractionRays", &MaterialSettings::GetRefractionRays, DOC(Bentley, DgnPlatform, MaterialSettings, GetRefractionRays));
    c14.def("SetRefractionRays", &MaterialSettings::SetRefractionRays, "rays"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetRefractionRays));
    
    c14.def_property("SubsurfaceSamples", &MaterialSettings::GetSubsurfaceSamples, &MaterialSettings::SetSubsurfaceSamples);
    c14.def("GetSubsurfaceSamples", &MaterialSettings::GetSubsurfaceSamples, DOC(Bentley, DgnPlatform, MaterialSettings, GetSubsurfaceSamples));
    c14.def("SetSubsurfaceSamples", &MaterialSettings::SetSubsurfaceSamples, "samples"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetSubsurfaceSamples));
    
    c14.def_property("DisplacementDistanceInMillimeters", &MaterialSettings::GetDisplacementDistanceInMillimeters, &MaterialSettings::SetDisplacementDistanceInMillimeters);
    c14.def("GetDisplacementDistanceInMillimeters", &MaterialSettings::GetDisplacementDistanceInMillimeters, DOC(Bentley, DgnPlatform, MaterialSettings, GetDisplacementDistanceInMillimeters));
    c14.def("SetDisplacementDistanceInMillimeters", &MaterialSettings::SetDisplacementDistanceInMillimeters, "distance"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetDisplacementDistanceInMillimeters));
    
    c14.def_property("DispersionAmount", &MaterialSettings::GetDispersionAmount, &MaterialSettings::SetDispersionAmount);
    c14.def("GetDispersionAmount", &MaterialSettings::GetDispersionAmount, DOC(Bentley, DgnPlatform, MaterialSettings, GetDispersionAmount));
    c14.def("SetDispersionAmount", &MaterialSettings::SetDispersionAmount, "amount"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetDispersionAmount));
    
    c14.def_property("ClearcoatAmount", &MaterialSettings::GetClearcoatAmount, &MaterialSettings::SetClearcoatAmount);
    c14.def("GetClearcoatAmount", &MaterialSettings::GetClearcoatAmount, DOC(Bentley, DgnPlatform, MaterialSettings, GetClearcoatAmount));
    c14.def("SetClearcoatAmount", &MaterialSettings::SetClearcoatAmount, "amount"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetClearcoatAmount));
    
    c14.def_property("AnisotropyAmount", &MaterialSettings::GetAnisotropyAmount, &MaterialSettings::SetAnisotropyAmount);
    c14.def("GetAnisotropyAmount", &MaterialSettings::GetAnisotropyAmount, DOC(Bentley, DgnPlatform, MaterialSettings, GetAnisotropyAmount));
    c14.def("SetAnisotropyAmount", &MaterialSettings::SetAnisotropyAmount, "amount"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetAnisotropyAmount));
    
    c14.def_property("FrontWeightingAmount", &MaterialSettings::GetFrontWeightingAmount, &MaterialSettings::SetFrontWeightingAmount);
    c14.def("GetFrontWeightingAmount", &MaterialSettings::GetFrontWeightingAmount, DOC(Bentley, DgnPlatform, MaterialSettings, GetFrontWeightingAmount));
    c14.def("SetFrontWeightingAmount", &MaterialSettings::SetFrontWeightingAmount, "amount"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetFrontWeightingAmount));
    
    c14.def_property("ScatterDistanceInMeters", &MaterialSettings::GetScatterDistanceInMeters, &MaterialSettings::SetScatterDistanceInMeters);
    c14.def("GetScatterDistanceInMeters", &MaterialSettings::GetScatterDistanceInMeters, DOC(Bentley, DgnPlatform, MaterialSettings, GetScatterDistanceInMeters));
    c14.def("SetScatterDistanceInMeters", &MaterialSettings::SetScatterDistanceInMeters, "distance"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetScatterDistanceInMeters));
    
    c14.def_property("ReflectionFresnel", &MaterialSettings::GetReflectionFresnel, &MaterialSettings::SetReflectionFresnel);
    c14.def("GetReflectionFresnel", &MaterialSettings::GetReflectionFresnel, DOC(Bentley, DgnPlatform, MaterialSettings, GetReflectionFresnel));
    c14.def("SetReflectionFresnel", &MaterialSettings::SetReflectionFresnel, "reflection"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetReflectionFresnel));
    
    c14.def_property("DissolveAmount", &MaterialSettings::GetDissolveAmount, &MaterialSettings::SetDissolveAmount);
    c14.def("GetDissolveAmount", &MaterialSettings::GetDissolveAmount, DOC(Bentley, DgnPlatform, MaterialSettings, GetDissolveAmount));
    c14.def("SetDissolveAmount", &MaterialSettings::SetDissolveAmount, "amount"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetDissolveAmount));
    
    c14.def_property("AbsorptionDistance", &MaterialSettings::GetAbsorptionDistance, &MaterialSettings::SetAbsorptionDistance);
    c14.def("GetAbsorptionDistance", &MaterialSettings::GetAbsorptionDistance, DOC(Bentley, DgnPlatform, MaterialSettings, GetAbsorptionDistance));
    c14.def("SetAbsorptionDistance", &MaterialSettings::SetAbsorptionDistance, "distance"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetAbsorptionDistance));
    
    c14.def_property("RefractionRoughness", &MaterialSettings::GetRefractionRoughness, &MaterialSettings::SetRefractionRoughness);
    c14.def("GetRefractionRoughness", &MaterialSettings::GetRefractionRoughness, DOC(Bentley, DgnPlatform, MaterialSettings, GetRefractionRoughness));
    c14.def("SetRefractionRoughness", &MaterialSettings::SetRefractionRoughness, "roughness"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetRefractionRoughness));
    
    c14.def_property("IsBlurReflections", &MaterialSettings::BlurReflections, &MaterialSettings::SetBlurReflections);
    c14.def("BlurReflections", &MaterialSettings::BlurReflections, DOC(Bentley, DgnPlatform, MaterialSettings, BlurReflections));
    c14.def("SetBlurReflections", &MaterialSettings::SetBlurReflections, "reflection"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetBlurReflections));
    
    c14.def_property("IsBlurRefractions", &MaterialSettings::BlurRefractions, &MaterialSettings::SetBlurRefractions);
    c14.def("BlurRefractions", &MaterialSettings::BlurRefractions, DOC(Bentley, DgnPlatform, MaterialSettings, BlurRefractions));
    c14.def("SetBlurRefractions", &MaterialSettings::SetBlurRefractions, "refraction"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetBlurRefractions));
    
    c14.def_property("BackFaceCulling", &MaterialSettings::GetBackFaceCulling, &MaterialSettings::SetBackFaceCulling);
    c14.def("GetBackFaceCulling", &MaterialSettings::GetBackFaceCulling, DOC(Bentley, DgnPlatform, MaterialSettings, GetBackFaceCulling));
    c14.def("SetBackFaceCulling", &MaterialSettings::SetBackFaceCulling, "backFaceCulling"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetBackFaceCulling));
    
    c14.def_property("IsLockSpecularAndReflect", &MaterialSettings::LockSpecularAndReflect, &MaterialSettings::SetLockSpecularAndReflect);
    c14.def("LockSpecularAndReflect", &MaterialSettings::LockSpecularAndReflect, DOC(Bentley, DgnPlatform, MaterialSettings, LockSpecularAndReflect));
    c14.def("SetLockSpecularAndReflect", &MaterialSettings::SetLockSpecularAndReflect, "lock"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetLockSpecularAndReflect));
    
    c14.def_property("IsLockEfficiency", &MaterialSettings::LockEfficiency, &MaterialSettings::SetLockEfficiency);
    c14.def("LockEfficiency", &MaterialSettings::LockEfficiency, DOC(Bentley, DgnPlatform, MaterialSettings, LockEfficiency));
    c14.def("SetLockEfficiency", &MaterialSettings::SetLockEfficiency, "lock"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetLockEfficiency));
    
    c14.def_property("IsLockSpecularAndBase", &MaterialSettings::LockSpecularAndBase, &MaterialSettings::SetLockSpecularAndBase);
    c14.def("LockSpecularAndBase", &MaterialSettings::LockSpecularAndBase, DOC(Bentley, DgnPlatform, MaterialSettings, LockSpecularAndBase));
    c14.def("SetLockSpecularAndBase", &MaterialSettings::SetLockSpecularAndBase, "lock"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetLockSpecularAndBase));
    
    c14.def_property("IsLockFinishAndSpecular", &MaterialSettings::LockFinishAndSpecular, &MaterialSettings::SetLockFinishAndSpecular);
    c14.def("LockFinishAndSpecular", &MaterialSettings::LockFinishAndSpecular, DOC(Bentley, DgnPlatform, MaterialSettings, LockFinishAndSpecular));
    c14.def("SetLockFinishAndSpecular", &MaterialSettings::SetLockFinishAndSpecular, "lock"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetLockFinishAndSpecular));
    
    c14.def_property("IsLockFresnelToReflect", &MaterialSettings::LockFresnelToReflect, &MaterialSettings::SetLockFresnelToReflect);
    c14.def("LockFresnelToReflect", &MaterialSettings::LockFresnelToReflect, DOC(Bentley, DgnPlatform, MaterialSettings, LockFresnelToReflect));
    c14.def("SetLockFresnelToReflect", &MaterialSettings::SetLockFresnelToReflect, "lock"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetLockFresnelToReflect));
    
    c14.def_property("IsLockRefractionRoughnessToFinish", &MaterialSettings::LockRefractionRoughnessToFinish, &MaterialSettings::SetLockRefractionRoughnessToFinish);
    c14.def("LockRefractionRoughnessToFinish", &MaterialSettings::LockRefractionRoughnessToFinish, DOC(Bentley, DgnPlatform, MaterialSettings, LockRefractionRoughnessToFinish));
    c14.def("SetLockRefractionRoughnessToFinish", &MaterialSettings::SetLockRefractionRoughnessToFinish, "lock"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetLockRefractionRoughnessToFinish));
    
    c14.def("HasCustomSpecular", &MaterialSettings::HasCustomSpecular, DOC(Bentley, DgnPlatform, MaterialSettings, HasCustomSpecular));
    c14.def("SetHasCustomSpecular", &MaterialSettings::SetHasCustomSpecular, "hasCustomSpecular"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetHasCustomSpecular));
    
    c14.def_property("CutSectionMaterialName", &MaterialSettings::GetCutSectionMaterialName, &MaterialSettings::SetCutSectionMaterialName);    
    c14.def("GetCutSectionMaterialName", &MaterialSettings::GetCutSectionMaterialName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetCutSectionMaterialName));
    c14.def("SetCutSectionMaterialName", &MaterialSettings::SetCutSectionMaterialName, "name"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetCutSectionMaterialName));    
    
    c14.def_property_readonly("CutSectionMaterialPalette", &MaterialSettings::GetCutSectionMaterialPaletteR);
    c14.def("GetCutSectionMaterialPalette", &MaterialSettings::GetCutSectionMaterialPaletteR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetCutSectionMaterialPalette));
    
    c14.def_property("IsUseCutSectionMaterial", &MaterialSettings::UseCutSectionMaterial, &MaterialSettings::SetUseCutSectionMaterial);
    c14.def("UseCutSectionMaterial", &MaterialSettings::UseCutSectionMaterial, DOC(Bentley, DgnPlatform, MaterialSettings, UseCutSectionMaterial));
    c14.def("SetUseCutSectionMaterial", &MaterialSettings::SetUseCutSectionMaterial, "use"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetUseCutSectionMaterial));
    
    c14.def_property("PBRMaterial", &MaterialSettings::IsPBRMaterial, &MaterialSettings::SetIsPBRMaterial);
    c14.def("IsPBRMaterial", &MaterialSettings::IsPBRMaterial, DOC(Bentley, DgnPlatform, MaterialSettings, IsPBRMaterial));
    c14.def("SetIsPBRMaterial", &MaterialSettings::SetIsPBRMaterial, "isPbrMaterial");
    
    c14.def_property("PBRMetalInsulatorRatio", &MaterialSettings::GetPBRMetalInsulatorRatio, &MaterialSettings::SetPBRMetalInsulatorRatio);
    c14.def("GetPBRMetalInsulatorRatio", &MaterialSettings::GetPBRMetalInsulatorRatio, DOC(Bentley, DgnPlatform, MaterialSettings, GetPBRMetalInsulatorRatio));
    c14.def("SetPBRMetalInsulatorRatio", &MaterialSettings::SetPBRMetalInsulatorRatio, "ratio"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetPBRMetalInsulatorRatio));
    
    c14.def_property("PBRRoughness", &MaterialSettings::GetPBRRoughness, &MaterialSettings::SetPBRRoughness);
    c14.def("GetPBRRoughness", &MaterialSettings::GetPBRRoughness, DOC(Bentley, DgnPlatform, MaterialSettings, GetPBRRoughness));
    c14.def("SetPBRRoughness", &MaterialSettings::SetPBRRoughness, "roughness"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetPBRRoughness));
    
    c14.def_property("PBRHeightMapScale", &MaterialSettings::GetPBRHeightMapScale, &MaterialSettings::SetPBRHeightMapScale);
    c14.def("GetPBRHeightMapScale", &MaterialSettings::GetPBRHeightMapScale, DOC(Bentley, DgnPlatform, MaterialSettings, GetPBRHeightMapScale));
    c14.def("SetPBRHeightMapScale", &MaterialSettings::SetPBRHeightMapScale, "scale"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetPBRHeightMapScale));
    
    c14.def_property("PBRNormalMapScale", &MaterialSettings::GetPBRNormalMapScale, &MaterialSettings::SetPBRNormalMapScale);
    c14.def("GetPBRNormalMapScale", &MaterialSettings::GetPBRNormalMapScale, DOC(Bentley, DgnPlatform, MaterialSettings, GetPBRNormalMapScale));
    c14.def("SetPBRNormalMapScale", &MaterialSettings::SetPBRNormalMapScale, "scale"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetPBRNormalMapScale));
    
    c14.def_property("PBRAmbientOcclusionMapScale", &MaterialSettings::GetPBRAmbientOcclusionMapScale, &MaterialSettings::SetPBRAmbientOcclusionMapScale);
    c14.def("GetPBRAmbientOcclusionMapScale", &MaterialSettings::GetPBRAmbientOcclusionMapScale, DOC(Bentley, DgnPlatform, MaterialSettings, GetPBRAmbientOcclusionMapScale));
    c14.def("SetPBRAmbientOcclusionMapScale", &MaterialSettings::SetPBRAmbientOcclusionMapScale, "scale"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetPBRAmbientOcclusionMapScale));

    c14.def_property("PBREmissiveColor", &MaterialSettings::GetPBREmissiveColorR, [] (MaterialSettings& self, RgbFactorCR color) { self.SetPBREmissiveColor(color.red, color.green, color.blue); });
    c14.def("GetPBREmissiveColor", &MaterialSettings::GetPBREmissiveColorR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, MaterialSettings, GetPBREmissiveColor));
    c14.def("SetPBREmissiveColor", &MaterialSettings::SetPBREmissiveColor, "red"_a, "green"_a, "blue"_a, DOC(Bentley, DgnPlatform, MaterialSettings, SetPBREmissiveColor));
    }