/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displaystylemanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayStyleManager.h>



static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_ApplyDisplayStyleToView =R"doc(Applies a DisplayStyle to a ViewInfo. @note If this ViewInfo came from
a Viewport, you will also likely want to call
Viewport::SynchWithViewInfo, Viewport::ClearShadowList, and then
heal/update the viewport. @note This will fail if the provided display
style is not already in the views target's file.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_ImportDisplayStyle =R"doc(Performs high-level import logic to copy a display style from one file
to another. This differs from CopyDisplayStyleToFile in that it will
not replace an existing display style by-name if it already exists.
Additionally, it has better error detection. @note When cloning
elements, this method is preferred (over CopyDisplayStyleToFile)
because generally speaking, you will want to respect the desintation
file's version of the display style, if present.

Parameter ``sourceDgnFile``:
    IN source file form where style will be imported

Parameter ``destinationDgnFile``:
    IN the destination dgn file

Parameter ``sourceIndex``:
    IN this must be more than -1

Returns (Tuple, 0):
    SUCCESS if import is successful

Returns (Tuple,1):
	destinationIndex.

)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_DoesDisplayStyleExistInFile =R"doc(Determines if a display style, by-name, exists in a specific file.

Parameter ``styleName``:
    IN style name which needs to be checked

Parameter ``dgnFile``:
    IN the dgn on which we want to check the presence of style name

Returns:
    true if it is found)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_RenameDisplayStyleInFile =R"doc(Renames a display style in a file. Its ID remains the same. @note When
a display style is renamed, no attempts are currently made to
normalize existing elements. The is acceptable because all current
known elements store display style IDs, which are unaffected by this
operation.

Parameter ``originalName``:
    IN the old style name

Parameter ``newName``:
    IN the new style name

Parameter ``dgnFile``:
    IN the object of MSDgnFileR where it will be renamed)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_RemoveDisplayStyleFromFile =R"doc(Removes a display style from a file. Its ID cannot be re-used at this
point. @note When a display style is removed, no attempts are
currently made to normalize existing elements. Thus elements may still
attempt to reference a missing display style, but must be written to
assume such a display style doesn't exist.

Parameter ``styleName``:
    IN the style which will be removed

Parameter ``dgnFile``:
    IN the object of MSDgnFileR from where display style will be
    removed)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_CopyDisplayStyleToFile =R"doc(Copies a display style by-name from one file to another. This is
essentially a utility wrapper around WriteDisplayStyleToFile. @note
When cloning elements, the ImportDisplayStyle method is preferred over
this method because generally speaking, you will want to respect the
desintation file's version of the display style, if present; this
method will irregardless overwrite/update an existing display style
by-name.

See also:
    WriteDisplayStyleToFile for additional notes

See also:
    ImportDisplayStyle for a higher level alternative

Parameter ``styleName``:
    IN MSWCharCR

Parameter ``sourceDgnFile``:
    IN the object of MSDgnFileR from where it will copy into
    destination dgn file

Parameter ``destinationDgnFile``:
    IN the object of MSDgnFileR where data will be copied

Returns:
    DisplayStyleCP object type.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_WriteDisplayStyleToFile =R"doc(Writes the given display style to the given file. If one by the same
name already exists, it is replaced. A replaced display style retains
the ID of the version already in the file. The persisted version of
the display style is returned, and should be used from this point on.

Parameter ``displayStyle``:
    IN the object of type DisplayStyleCR

Parameter ``destinationDgnFile``:
    IN the object of MSDgnFileR

Returns:
    DisplayStyleCP type of object)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_EnsureDisplayStyleIsInFile =R"doc(This ensures that a display style by the given name exists in the
provided file. If a display style by the given name already exists, it
is returned; the provided display style is NOT written to the file
instead. If the display style by the given name doesn't exist, it is
written to the file, and the persisted version is returned. This
method will not return NULL under expected conditions.

Parameter ``displayStyle``:
    IN the object of DisplayStyleCR

Parameter ``destinationDgnFile``:
    IN the object of MSDgnFileR

Returns:
    DisplayStyleCP type of object)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_GetDisplayStyleByIndex =R"doc(Returns the display style, if present, from the file's display style
collection as indicated by the provided index.

Parameter ``index``:
    IN DisplayStyleList::size_type

Parameter ``dgnFile``:
    IN the object of MSDgnFileP

Returns:
    DisplayStyleCP type of object)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleManager_GetDisplayStyleForViewInfo =R"doc(Returns the display style, if present, from the file's display style
collection as indicated by the provided ViewInfo. @note The ViewInfo
root is used as the file to search in.

Parameter ``viewInfo``:
    IN the object of ViewInfoCR

Returns:
    DisplayStyleCP type of object)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetReflectionTypeDisplayed =R"doc(Sets the Environment Type which will be displayed

Parameter ``typeDisplayed``:
    IN UInt32 type parameter)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetReflectionTypeDisplayed =R"doc(Returns:
    Environment Type which will be displayed)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetReflectionMapName =R"doc(Changes the reflection map name

Parameter ``reflection``:
    map name IN WCharCP)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetReflectionMapName =R"doc(Returns:
    the reflection map name WStringCR)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_EnsureDisplayStyleHandler =R"doc(Ensures that it has a handler)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetGroundPlane =R"doc(Returns:
    the reference to ground plane for this display style)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetEnvironmentTypeDisplayed =R"doc(Sets the Environment Type which will be displayed

Parameter ``typeDisplayed``:
    IN UInt32 type parameter)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetEnvironmentTypeDisplayed =R"doc(Returns:
    Environment Type which will be displayed)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetEnvironmentName =R"doc(Changes the Environment name

Parameter ``environmentName``:
    IN WCharCP)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetEnvironmentName =R"doc(Returns:
    the environment name WStringCR)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_CopySettingsTo =R"doc(Pushes this display style's settings to the provided viewinfo, re-
mapping indices to ensure that they are compatible with the provided
file. @note This is a low-level method, and is only inteded to be used
with DgnPlatform. Users of the PowerPlatform should use
IViewManager::ApplyDisplayStyleToView instead. @note The provided file
should match the view's root.

Parameter ``viewInfo``:
    IN on which it apply the setting from other

Parameter ``destinationDgnFile``:
    IN the object of dgn file)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_IsValidForViewport =R"doc(True if this display style can be applied to the provided Viewport.
@note If you need more information about why a display style is not
valid for a Viewport, use another overload of this method.

Returns:
    true if is valid for the viewport)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_MatchesViewInfoData =R"doc(True if this display style effectively matches the provided view data.

Parameter ``viewInfo``:
    IN the object of ViewInfoCR)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetIsUsableForClipVolumes =R"doc(Sets if this display style can be used for individual sections.

Parameter ``isValid``:
    IN bool)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_IsUsableForClipVolumes =R"doc(True if this display style can be used for individual sections.

Returns:
    true if it is usable for clip volumes)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetIsUsableForViews =R"doc(Sets if this display style can be used for whole views.

Parameter ``isValid``:
    IN bool)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_IsUsableForViews =R"doc(True if this display style can be used for whole views.

Returns:
    true if it is usable for views)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetOverrides =R"doc(Sets the overrides (

See also:
    ViewDisplayOverrides). @note You must provide the file that the
    overrides are based on, since they contain file-specific IDs that
    will be remapped to be stored in this display style.

Parameter ``newOverrides``:
    IN the object of ViewDisplayOverridesCR

Parameter ``sourceDgnFile``:
    IN the source dgn file)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetOverrides =R"doc(Gets a read-only reference to the overrides (

See also:
    ViewDisplayOverrides).

Returns:
    the object of ViewDisplayOverridesCR)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetFlags =R"doc(Sets the flags (

See also:
    DisplayStyleFlags).

Parameter ``newFlags``:
    IN the object of DisplayStyleFlagsCR)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetFlags =R"doc(Returns:
    the object of DisplayStyleFlagsCR Gets a read-only reference to
    the flags (

See also:
    DisplayStyleFlags).)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_IsFromHardCodedDefault =R"doc(True if this display style originated from a hard-coded default

Returns:
    true if it is a hard coded default.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_IsFromFile =R"doc(True if this display style originated from a file.

Returns:
    true if it is from dgn file otherwise false)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_SetDisplayMode =R"doc(Sets the display mode.

See also:
    GetDisplayMode for additional notes

Parameter ``newDisplayMode``:
    IN UInt32 type)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetDisplayMode =R"doc(Gets the display mode. This is an intrinsic property, not an override.

Returns:
    UInt32 type.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetName =R"doc(Gets the name.

See also:
    DisplayStyleManager to rename a DisplayStyle

Returns:
    name of the display style WStringCR)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_GetIndex =R"doc(Gets the ID of this display style. Display styles do not have a valid
ID until they are written to the file. @note When writing a display
style to a file, make sure you re-read the display style (by-name) to
get its persisted ID.

Returns:
    int)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_IsInFile =R"doc(Determines if this display style is based on the provided file. @note
This method does not determine if the display style is actually
persisted in the given file; see DisplayStyleManager.

Returns:
    true if it is found otherwise false)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_Equals =R"doc(Performs a deep equality check. @note This overload is equivalent to
calling Equals(rhs, false), and is provided as a convenience.

Parameter ``rhs``:
    IN the object to compare with

Returns:
    true if this object and the rhs parameter are equal by-value;
    false otherwise)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyle_Clone =R"doc(Makes a deep copy of a display style. It will have the same name and
ID, allowing you to save it to the file, replacing the existing one.
@note This overload does not remap any IDs, and keeps the same file as
the original.

Returns:
    DisplayStylePtr " smart pointer ")doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_SetShowGroundFromBelow =R"doc(It will change the showing of ground plane from below

Parameter ``showGroundFromBelow``:
    IN the boolean parameter)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_ShowGroundFromBelow =R"doc(It will check for the ground plane whether it has been shown from
below or not

Returns:
    true if is matched.)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_SetTransparency =R"doc(It will change the Transparency of ground plane

Parameter ``transparency``:
    IN the double parameter)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_GetTransparency =R"doc(It will return the Transparency of the ground plane

Returns:
    double)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_SetHeight =R"doc(It will change the height of ground plane

Parameter ``height``:
    IN the double parameter)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_GetHeight =R"doc(It will return the height of the ground plane

Returns:
    double)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_SetGroundColor =R"doc(It will set the ground plane color

Parameter ``color``:
    IN the object of RGBFactor)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_GetGroundColor =R"doc(It will return the ground plane color

Returns:
    the RGBFactor)doc";

static const char * __doc_Bentley_DgnPlatform_DisplayStyleGroundPlane_Clone =R"doc(Performs a deep clone from given DisplayStyleGroundPlane.

Parameter ``rhs``:
    the DisplayStyleGroundPlane, from which it will creates the clone)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_ExtractMaterialPaletteAndName =R"doc(Resolves the material palette name and material name for this object's
material ID. Note that the lookup is done based on the file given.

Parameter ``paletteName``:
    the resolved material palette name

Parameter ``materialName``:
    the resolved material name

Parameter ``dgnFile``:
    the context to resolve material indices with Bentley Systems +----
    -----------+---------------+---------------+---------------+------
    ---------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_AreFlagsEqual =R"doc(Performs a by-value equality check between this object's flags and
another's.

Parameter ``rhs``:
    the object to compare flags with

Returns:
    true if this object's flags and the rhs parameter's flags are
    equal by-value; false otherwise Bentley Systems +---------------+-
    --------------+---------------+---------------+---------------+---
    ---)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_Equals =R"doc(Performs a deep by-value equality check between this object and
another. Note that this overload is file-invariant, meaning that color
and material indices will NOT be remapped to equivalent values if the
objects are from different files.

Parameter ``rhs``:
    the object to compare with

Returns:
    true if this object and the rhs parameter are equal by-value;
    false otherwise Bentley Systems +---------------+---------------+-
    --------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_Clone =R"doc(Performs a deep clone.

Parameter ``sourceDgnFile``:
    the source DGN file (used for color and material index remapping)

Parameter ``destinationDgnFile``:
    the destination DGN file (used for color and material index
    remapping)

Returns:
    a deep copy of this object Bentley Systems +---------------+------
    ---------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_GetDisplayStyleHandlerId =R"doc(Get the display style handler Id

Returns:
    the object of Element::XAttributeHandlerId)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_SetDisplayStyleHandlerById =R"doc(Change the display style handler Id

Parameter ``id``:
    IN the object of Element::XAttributeHandlerId)doc";

static const char * __doc_Bentley_DgnPlatform_ViewDisplayOverrides_ResolveDisplayStyleHandler =R"doc(Reloads the display style handler and settings from the handler id.
Bentley Systems +---------------+---------------+---------------+-----
----------+---------------+------)doc";

USING_NAMESPACE_BENTLEY_MSTNPLATFORM_MSPYTHON


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayStyleManager(py::module_& m)
    {
    //===================================================================================
    // enum class DisplayStyleImportStatus
    py::enum_< DisplayStyleImportStatus>(m, "DisplayStyleImportStatus")
        .value("eInvalidSourceIndex", DisplayStyleImportStatus::InvalidSourceIndex)
        .value("eNotRemapped", DisplayStyleImportStatus::NotRemapped)
        .value("eRemappedToExistingStyle", DisplayStyleImportStatus::RemappedToExistingStyle)
        .value("eRemappedToNewStyle", DisplayStyleImportStatus::RemappedToNewStyle)
        .export_values();

    //===================================================================================
    // enum class DisplayStyleBuiltInUsage
    py::enum_< DisplayStyleBuiltInUsage>(m, "DisplayStyleBuiltInUsage")
        .value("eView", DisplayStyleBuiltInUsage::View)
        .value("eClipVolume", DisplayStyleBuiltInUsage::ClipVolume)
        .export_values();

    //===================================================================================
    // enum class DisplayStyleApplyValidity
    py::enum_< DisplayStyleApplyValidity>(m, "DisplayStyleApplyValidity")
        .value("eCanBeApplied", DisplayStyleApplyValidity::CanBeApplied)
        .value("eNonWireframeForSheet", DisplayStyleApplyValidity::NonWireframeForSheet)
        .value("eShadowedOn2DModel", DisplayStyleApplyValidity::ShadowedOn2DModel)
        .value("eNotValidForHandler", DisplayStyleApplyValidity::NotValidForHandler)
        .export_values();

    //===================================================================================
    // enum class DisplayStyleSource
    py::enum_< DisplayStyleSource>(m, "DisplayStyleSource")
        .value("eFile", DisplayStyleSource::File)
        .value("eHardCodedDefault", DisplayStyleSource::HardCodedDefault)
        .export_values();

    //===================================================================================
    // enum class SpecialDisplayStyleIndex
    py::enum_< SpecialDisplayStyleIndex>(m, "SpecialDisplayStyleIndex", py::arithmetic())
        .value("eSpecialDisplayStyleIndex_None", SpecialDisplayStyleIndex::SpecialDisplayStyleIndex_None)
        .value("eSpecialDisplayStyleIndex_FromParent", SpecialDisplayStyleIndex::SpecialDisplayStyleIndex_FromParent)
        .export_values();

    //===================================================================================
    // enum class EnvironmentDisplay
    py::enum_< EnvironmentDisplay>(m, "EnvironmentDisplay")
        .value("eColor", EnvironmentDisplay::Color)
        .value("eLuxology", EnvironmentDisplay::Luxology)
        .value("eVue", EnvironmentDisplay::Vue)
        .export_values();

    //===================================================================================
    // struct DisplayStyleFlags
    py::class_< DisplayStyleFlags> c1(m, "DisplayStyleFlags");

    c1.def(py::init<>());
    c1.def_property("displayMode",
                    [] (DisplayStyleFlags const& self) { return (MSRenderMode) self.m_displayMode; },
                    [] (DisplayStyleFlags& self, MSRenderMode mode) { self.m_displayMode = (unsigned)mode; });
    c1.def_property("displayVisiableEdges",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_displayVisibleEdges; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_displayVisibleEdges = (unsigned) value; });
    c1.def_property("displayHiddenEdges",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_displayHiddenEdges; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_displayHiddenEdges = (unsigned) value; });
    c1.def_property("hiddenEdgeLineStyle",
                    [] (DisplayStyleFlags const& self) { return self.m_hiddenEdgeLineStyle; },
                    [] (DisplayStyleFlags& self, unsigned value) { self.m_hiddenEdgeLineStyle = value; });
    c1.def_property("displayShadows",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_displayShadows; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_displayShadows = (unsigned) value; });
    c1.def_property("legacyDrawOrder",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_legacyDrawOrder; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_legacyDrawOrder = (unsigned) value; });
    c1.def_property("overrideBackgroundColor",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_overrideBackgroundColor; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_overrideBackgroundColor = (unsigned) value; });
    c1.def_property("applyEdgeStyleToLines",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_applyEdgeStyleToLines; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_applyEdgeStyleToLines = (unsigned) value; });
    c1.def_property("ignoreGeometryMaps",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_ignoreGeometryMaps; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_ignoreGeometryMaps = (unsigned) value; });
    c1.def_property("ignoreImageMaps",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_ignoreImageMaps; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_ignoreImageMaps = (unsigned) value; });
    c1.def_property("hideInPickers",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_hideInPickers; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_hideInPickers = (unsigned) value; });
    c1.def_property("invisibleToCamera",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_invisibleToCamera; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_invisibleToCamera = (unsigned) value; });
    c1.def_property("displayGroundPlane",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_displayGroundPlane; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_displayGroundPlane = (unsigned) value; });
    c1.def_property("overrideReflectionColor",
                    [] (DisplayStyleFlags const& self) { return (bool) self.m_overrideReflectionColor; },
                    [] (DisplayStyleFlags& self, bool value) { self.m_overrideReflectionColor = (unsigned) value; });

    c1.def("__eq__", [] (DisplayStyleFlags const& self, DisplayStyleFlagsCR rhs) { return self.Equals(rhs); }, "rhs"_a);

    //===================================================================================
    // struct ViewDisplayOverrides
    py::class_< ViewDisplayOverrides> c2(m, "ViewDisplayOverrides");

    c2.def(py::init<>());
    c2.def("ResolveDisplayStyleHandler", &ViewDisplayOverrides::ResolveDisplayStyleHandler, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, ResolveDisplayStyleHandler));
    c2.def("SetDisplayStyleHandlerById", &ViewDisplayOverrides::SetDisplayStyleHandlerById, "id"_a, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, SetDisplayStyleHandlerById));
    c2.def_property_readonly("DisplayStyleHandlerId", &ViewDisplayOverrides::GetDisplayStyleHandlerId);
    c2.def("GetDisplayStyleHandlerId", &ViewDisplayOverrides::GetDisplayStyleHandlerId, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, GetDisplayStyleHandlerId));
    c2.def("Clone", &ViewDisplayOverrides::Clone, "sourceDgnFile"_a, "destDgnFile"_a, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, Clone));
    c2.def("__eq__", [] (ViewDisplayOverrides const& self, ViewDisplayOverridesCR rhs) { return self.Equals(rhs); }, "rhs"_a);
    c2.def("Equals", py::overload_cast<ViewDisplayOverridesCR, DgnFileR, DgnFileR>(&ViewDisplayOverrides::Equals, py::const_), "rhs"_a, "sourceDgnFile"_a, "rhsDgnFile"_a, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, Equals));
    c2.def("AreFlagsEqual", &ViewDisplayOverrides::AreFlagsEqual, "rhs"_a, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, AreFlagsEqual));
    c2.def("ExtractMaterialPaletteAndName", &ViewDisplayOverrides::ExtractMaterialPaletteAndName, "patternName"_a, "materialName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ViewDisplayOverrides, ExtractMaterialPaletteAndName));
    c2.def("HiddenEdgeWeightSameAsVisible", &ViewDisplayOverrides::HiddenEdgeWeightSameAsVisible);

    //===================================================================================
    // struct DisplayStyleGroundPlane
    py::class_< DisplayStyleGroundPlane> c3(m, "DisplayStyleGroundPlane");

    c3.def(py::init<>());
    c3.def("Clone", &DisplayStyleGroundPlane::Clone, "rhs"_a, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, Clone));
    c3.def("__eq__", [] (DisplayStyleGroundPlane const& self, DisplayStyleGroundPlane const& rhs) { return self.Equals(rhs); }, "rhs"_a);
    
    c3.def_property("GroundColor", &DisplayStyleGroundPlane::GetGroundColor, &DisplayStyleGroundPlane::SetGroundColor);
    c3.def("GetGroundColor", &DisplayStyleGroundPlane::GetGroundColor, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, GetGroundColor));
    c3.def("SetGroundColor", &DisplayStyleGroundPlane::SetGroundColor, "color"_a, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, SetGroundColor));
    
    c3.def_property("Height", &DisplayStyleGroundPlane::GetHeight, &DisplayStyleGroundPlane::SetHeight);
    c3.def("GetHeight", &DisplayStyleGroundPlane::GetHeight, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, GetHeight));
    c3.def("SetHeight", &DisplayStyleGroundPlane::SetHeight, "height"_a, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, SetHeight));
    
    c3.def_property("Transparency", &DisplayStyleGroundPlane::GetTransparency, &DisplayStyleGroundPlane::SetTransparency);
    c3.def("GetTransparency", &DisplayStyleGroundPlane::GetTransparency, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, GetTransparency));
    c3.def("SetTransparency", &DisplayStyleGroundPlane::SetTransparency, "value"_a, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, SetTransparency));
    
    c3.def("ShowGroundFromBelow", &DisplayStyleGroundPlane::ShowGroundFromBelow, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, ShowGroundFromBelow));
    c3.def("SetShowGroundFromBelow", &DisplayStyleGroundPlane::SetShowGroundFromBelow, "newVal"_a, DOC(Bentley, DgnPlatform, DisplayStyleGroundPlane, SetShowGroundFromBelow));

    //===================================================================================
    // struct DisplayStyle
    py::class_< DisplayStyle, DisplayStylePtr> c4(m, "DisplayStyle");
    bind_PointerVector<DisplayStyleCP>(m, "DisplayStyleCPArray", py::module_local(false));

    c4.def(py::init(&DisplayStyle::Create), "dgnFile"_a, "name"_a);
    c4.def("Clone", py::overload_cast<>(&DisplayStyle::Clone, py::const_), DOC(Bentley, DgnPlatform, DisplayStyle, Clone));
    c4.def("Clone", py::overload_cast<DgnFileR>(&DisplayStyle::Clone, py::const_), "destDgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyle, Clone));
    c4.def("Clone", py::overload_cast<DgnFileR, WCharCP>(&DisplayStyle::Clone, py::const_), "destDgnFile"_a, "name"_a, DOC(Bentley, DgnPlatform, DisplayStyle, Clone));
    c4.def("__eq__", [] (DisplayStyleCR self, DisplayStyleCR rhs) { return self.Equals(rhs); }, "rhs"_a);
    c4.def("Equals", py::overload_cast<DisplayStyleCR, bool>(&DisplayStyle::Equals, py::const_), "rhs"_a, "testSettingsOnly"_a, DOC(Bentley, DgnPlatform, DisplayStyle, Equals));
    
    c4.def_property_readonly("File", &DisplayStyle::GetFileR);
    c4.def("GetFile", &DisplayStyle::GetFileR, py::return_value_policy::reference_internal);
    
    c4.def("IsInFile", &DisplayStyle::IsInFile, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyle, IsInFile));

    c4.def_property_readonly("Index", &DisplayStyle::GetIndex);
    c4.def("GetIndex", &DisplayStyle::GetIndex, DOC(Bentley, DgnPlatform, DisplayStyle, GetIndex));
    
    c4.def_property_readonly("Name", &DisplayStyle::GetName);
    c4.def("GetName", &DisplayStyle::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyle, GetName));
    
    c4.def_property("DisplayMode", &DisplayStyle::GetDisplayMode, &DisplayStyle::SetDisplayMode);
    c4.def("GetDisplayMode", &DisplayStyle::GetDisplayMode, DOC(Bentley, DgnPlatform, DisplayStyle, GetDisplayMode));
    c4.def("SetDisplayMode", &DisplayStyle::SetDisplayMode, "mode"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetDisplayMode));
    
    c4.def("IsFromFile", &DisplayStyle::IsFromFile, DOC(Bentley, DgnPlatform, DisplayStyle, IsFromFile));    
    c4.def("IsFromHardCodedDefault", &DisplayStyle::IsFromHardCodedDefault, DOC(Bentley, DgnPlatform, DisplayStyle, IsFromHardCodedDefault));
    
    c4.def_property("Flags", &DisplayStyle::GetFlags, &DisplayStyle::SetFlags);
    c4.def("GetFlags", &DisplayStyle::GetFlags, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyle, GetFlags));
    c4.def("SetFlags", &DisplayStyle::SetFlags, "flags"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetFlags));
    
    c4.def("GetOverrides", &DisplayStyle::GetOverrides, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyle, GetOverrides));
    c4.def("SetOverrides", &DisplayStyle::SetOverrides, "newOverrides"_a, "sourceDgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetOverrides));

    c4.def_property("UsableForViews", &DisplayStyle::IsUsableForViews, &DisplayStyle::SetIsUsableForViews);
    c4.def("IsUsableForViews", &DisplayStyle::IsUsableForViews, DOC(Bentley, DgnPlatform, DisplayStyle, IsUsableForViews));
    c4.def("SetIsUsableForViews", &DisplayStyle::SetIsUsableForViews, "newVal"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetIsUsableForViews));
    
    c4.def_property("UsableForClipVolumes", &DisplayStyle::IsUsableForClipVolumes, &DisplayStyle::SetIsUsableForClipVolumes);
    c4.def("IsUsableForClipVolumes", &DisplayStyle::IsUsableForClipVolumes, DOC(Bentley, DgnPlatform, DisplayStyle, IsUsableForClipVolumes));
    c4.def("SetIsUsableForClipVolumes", &DisplayStyle::SetIsUsableForClipVolumes, "newVal"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetIsUsableForClipVolumes));
    
    c4.def("MatchesViewInfoData", &DisplayStyle::MatchesViewInfoData, "viewInfo"_a, DOC(Bentley, DgnPlatform, DisplayStyle, MatchesViewInfoData));
    c4.def("IsValidForViewport", py::overload_cast<ViewportCR>(&DisplayStyle::IsValidForViewport, py::const_), "viewport"_a, DOC(Bentley, DgnPlatform, DisplayStyle, IsValidForViewport));
    c4.def("CopySettingsTo", py::overload_cast<ViewInfoR, DgnFileR>(&DisplayStyle::CopySettingsTo, py::const_), "viewInfo"_a, "destDgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyle, CopySettingsTo));
    
    c4.def_property("EnvironmentName", &DisplayStyle::GetEnvironmentName, &DisplayStyle::SetEnvironmentName);
    c4.def("GetEnvironmentName", &DisplayStyle::GetEnvironmentName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyle, GetEnvironmentName));
    c4.def("SetEnvironmentName", &DisplayStyle::SetEnvironmentName, "name"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetEnvironmentName));

    c4.def_property("EnvironmentTypeDisplayed", &DisplayStyle::GetEnvironmentTypeDisplayed, &DisplayStyle::SetEnvironmentTypeDisplayed);
    c4.def("GetEnvironmentTypeDisplayed", &DisplayStyle::GetEnvironmentTypeDisplayed, DOC(Bentley, DgnPlatform, DisplayStyle, GetEnvironmentTypeDisplayed));
    c4.def("SetEnvironmentTypeDisplayed", &DisplayStyle::SetEnvironmentTypeDisplayed, "typeDisplayed"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetEnvironmentTypeDisplayed));

    c4.def_property_readonly("GroundPlane", &DisplayStyle::GetGroundPlaneP);
    c4.def("GetGroundPlane", &DisplayStyle::GetGroundPlaneP, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyle, GetGroundPlane));
    
    c4.def("EnsureDisplayStyleHandler", &DisplayStyle::EnsureDisplayStyleHandler, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyle, EnsureDisplayStyleHandler));
    
    c4.def_property("ReflectionMapName", &DisplayStyle::GetReflectionMapName, &DisplayStyle::SetReflectionMapName);
    c4.def("GetReflectionMapName", &DisplayStyle::GetReflectionMapName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyle, GetReflectionMapName));
    c4.def("SetReflectionMapName", &DisplayStyle::SetReflectionMapName, "mapName"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetReflectionMapName));
    
    c4.def_property("ReflectionTypeDisplayed", &DisplayStyle::GetReflectionTypeDisplayed, &DisplayStyle::SetReflectionTypeDisplayed);
    c4.def("GetReflectionTypeDisplayed", &DisplayStyle::GetReflectionTypeDisplayed, DOC(Bentley, DgnPlatform, DisplayStyle, GetReflectionTypeDisplayed));
    c4.def("SetReflectionTypeDisplayed", &DisplayStyle::SetReflectionTypeDisplayed, "typeDisplayed"_a, DOC(Bentley, DgnPlatform, DisplayStyle, SetReflectionTypeDisplayed));

    //===================================================================================
    // enum DisplayStyleListOptions
    py::enum_< DisplayStyleListOptions>(m, "DisplayStyleListOptions", py::arithmetic())
        .value("eDISPLAY_STYLE_LIST_OPTIONS_IncludeHiddenForPickers", DISPLAY_STYLE_LIST_OPTIONS_IncludeHiddenForPickers)
        .value("eDISPLAY_STYLE_LIST_OPTIONS_Default", DISPLAY_STYLE_LIST_OPTIONS_Default)
        .value("eDISPLAY_STYLE_LIST_OPTIONS_IncludeAll", DISPLAY_STYLE_LIST_OPTIONS_IncludeAll)
        .export_values();

    //===================================================================================
    // struct DisplayStyleList
    py::class_< DisplayStyleList, DisplayStyleCPVector> c5(m, "DisplayStyleList");
    c5.def(py::init(&DisplayStyleList::CreateForFile), "dgnFile"_a, "DisplayStyleListOptions"_a);
    c5.def("ContainsDisplayStyle", &DisplayStyleList::ContainsDisplayStyle, "styleName"_a);
    c5.def("FindDisplayStyleByName", &DisplayStyleList::FindDisplayStyleByName, "styleName"_a, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct IDisplayStyleEventHandler

    //===================================================================================
    // struct DisplayStyleManager
    py::class_< DisplayStyleManager> c9(m, "DisplayStyleManager");

    c9.def_static("GetDisplayStyleForViewInfo", &DisplayStyleManager::GetDisplayStyleForViewInfo, "viewInfo"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyleManager, GetDisplayStyleForViewInfo));
    c9.def_static("GetDisplayStyleByIndex", &DisplayStyleManager::GetDisplayStyleByIndex, "index"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyleManager, GetDisplayStyleByIndex));
    c9.def_static("EnsureDisplayStyleIsInFile", &DisplayStyleManager::EnsureDisplayStyleIsInFile, "displayStyle"_a, "destDgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyleManager, EnsureDisplayStyleIsInFile));
    
    c9.def_static("WriteDisplayStyleToFile", 
                  py::overload_cast<DisplayStyleCR, DgnFileR>(&DisplayStyleManager::WriteDisplayStyleToFile),
                  "displayStyle"_a, "destDgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyleManager, WriteDisplayStyleToFile));

    c9.def_static("CopyDisplayStyleToFile", &DisplayStyleManager::CopyDisplayStyleToFile, "styleName"_a, "sourceDgnFile"_a, "destDgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DisplayStyleManager, CopyDisplayStyleToFile));
    c9.def_static("RemoveDisplayStyleFromFile", &DisplayStyleManager::RemoveDisplayStyleFromFile, "styleName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyleManager, RemoveDisplayStyleFromFile));
    c9.def_static("RenameDisplayStyleInFile", &DisplayStyleManager::RenameDisplayStyleInFile, "originalName"_a, "newName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyleManager, RenameDisplayStyleInFile));
    c9.def_static("DoesDisplayStyleExistInFile", &DisplayStyleManager::DoesDisplayStyleExistInFile, "styleName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DisplayStyleManager, DoesDisplayStyleExistInFile));
    
    c9.def_static("ImportDisplayStyle", [] (DgnFileR sourceDgnFile, DgnFileR destinationDgnFile, int sourceIndex)
                  {
                  int destinationIndex = -1;
                  auto retVal = DisplayStyleManager::ImportDisplayStyle(sourceDgnFile, destinationDgnFile, sourceIndex, destinationIndex);
                  return py::make_tuple(retVal, destinationIndex);
                  }, "sourceDgnFile"_a, "destinationDgnFile"_a, "sourceIndex"_a, DOC(Bentley, DgnPlatform, DisplayStyleManager, ImportDisplayStyle));

    c9.def_static("ApplyDisplayStyleToView", &DisplayStyleManager::ApplyDisplayStyleToView, "displayStyle"_a, "viewInfo"_a, DOC(Bentley, DgnPlatform, DisplayStyleManager, ApplyDisplayStyleToView));
    }