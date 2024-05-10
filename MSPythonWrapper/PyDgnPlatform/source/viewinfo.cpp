/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\viewinfo.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ViewInfo.h>



static const char * __doc_Bentley_DgnPlatform_ViewPortInfo_CopyFrom =R"doc(Parameter ``source``:
    The source ViewPortInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewPortInfo_GetAspectRatio =R"doc(Gets the aspect ratio of the view.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewPortInfo_Clear =R"doc(Clears the ViewPortInfo)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetStandardViewByName =R"doc(Gets a standard view by name.

Parameter ``rotP``:
    [optional] The orientation of the standard view

Parameter ``standardIdP``:
    [optional] The identifier of the standard view

Parameter ``viewName``:
    The name of the standard view to look up. Note that the comparison
    is case-insensitive.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetStandardViewName =R"doc(Gets the name of a StandardView.

Parameter ``viewName``:
    True to check the 3D members of StandardRotation.

Parameter ``standardView``:
    The StandardView orientation.

Returns:
    A member of the StandardView enumeration.
    StandardView::NotStandard indicates that rotation does not match
    any.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_IsStandardViewRotation =R"doc(Tests whether an orientation matrix corresponds to one of the
StandardView orientations.

Parameter ``rotation``:
    The orientation to test.

Parameter ``check3D``:
    True to check the 3D members of StandardRotation.

Returns:
    A member of the StandardView enumeration.
    StandardView::NotStandard indicates that rotation does not match
    any.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetDefaultFlags =R"doc(Get the default values for ViewFlags.

Parameter ``viewFlags``:
    The default ViewFlags.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_Create =R"doc(Creates a new ViewInfo.

Parameter ``namedView``:
    True if the ViewInfo will be used for a NamedView, false if it is
    to be used for a numbered view.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetEffectiveLevelDisplayMask =R"doc(Returns the BitMask that indicates whether levels are actually
displayed for the given model, taking into account the per-view level
display (see #GetLevelDisplayMask) and the on/off and frozen states of
the levels.

Parameter ``levelBitMask``:
    The per-view level display mask.

Parameter ``model``:
    The model for which the display is desired. Must be rootModel or a
    descendant of the rootModel (see #GetRootModelP).

Returns:
    VI_Success or VI_BadModelRef if the model is not the rootModel or
    a descendant of rootModel.

Remark:
    s The BitMask is indexed by LevelId-1. Level 0 is a special level
    and is considered always on. @See EnsureLevelMaskCoverage,
    ViewInfoCodeSamples)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetEffectiveLevelDisplay =R"doc(Returns true if the level is displayed within the view, taking into
account the per-view level display bit (see #GetLevelDisplay) and the
on/off and frozen state of the level.



Parameter ``model``:
    The model for which the display is desired. Must be rootModel or a
    descendant of the rootModel (see #GetRootModelP).

Parameter ``levelID``:
    The level for which the display is desired. @See
    EnsureLevelMaskCoverage, ViewInfoCodeSamples

Returns (Tuple, 0):
    VI_Success or VI_BadModelRef if the model is not the rootModel or
    a descendant of rootModel.

Returns (Tuple, 1):
	isDisplayed.   The display state.

)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetLevelDisplayMask =R"doc(Sets the per-view level display mask for the the given model.

Parameter ``model``:
    The model for which the display is desired. Must be rootModel or a
    descendant of the rootModel (see #GetRootModelP).

Parameter ``levelBitMask``:
    The new per-view level display mask.

Returns:
    VI_Success or VI_BadModelRef if the model is not the rootModel or
    a descendant of rootModel.

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.

Remark:
    s The BitMask is indexed by LevelId-1. Level 0 is a special level
    and is considered always on.

Remark:
    s The levelBitMask is copied into the ViewInfo. The caller is
    responsible for freeing the levelBitMask if appropriate.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetLevelDisplayMask =R"doc(Returns the BitMask containing the per-view level display for the
given model.

Parameter ``levelBitMask``:
    The per-view level display mask.

Parameter ``model``:
    The model for which the display is desired. Must be rootModel or a
    descendant of the rootModel (see #GetRootModelP).

Returns:
    VI_Success or VI_BadModelRef if the model is not the rootModel or
    a descendant of rootModel.

Remark:
    s This method returns the BitMask that describes the state of the
    per-view level display bits. Levels are not actually displayed if
    the level itself is turned off or frozen. See
    #GetEffectiveLevelDisplayMask

Remark:
    s The BitMask is indexed by LevelId-1. Level 0 is a special level
    and is considered always on.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetLevelDisplay =R"doc(Sets the per-view level display bit for the the given model and level.

Parameter ``model``:
    The model for which the display is desired. Must be rootModel or a
    descendant of the rootModel (see #GetRootModelP).

Parameter ``levelID``:
    The level for which the display is desired.

Parameter ``onOff``:
    The new state for the per-view level display bit.

Returns:
    VI_Success or VI_BadModelRef if the model is not the rootModel or
    a descendant of rootModel.

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetLevelDisplay =R"doc(Returns true if the per-view level display bit is turned on for the
given model and level.


Parameter ``model``:
    The model for which the display is desired. Must be rootModel or a
    descendant of the rootModel (see #GetRootModelP).

Parameter ``levelID``:
    The level for which the display is desired.

Remark:
    s This method returns the state of the per-view level display bit.
    The level is not actually displayed if the level itself is turned
    off or frozen. See #GetEffectiveLevelDisplay

Returns(Tuple, 0):
    VI_Success or VI_BadModelRef if the model is not the rootModel or
    a descendant of rootModel.

Returns (Tuple, 1):
	isOn.    The state of the per-view level display bit.

)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetTargetModelRef =R"doc(Sets the Target ModelRef for this ViewInfo.

Parameter ``target``:
    The target model that is modified by user inputs in this view.

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetGeometry =R"doc(Sets the geometry that determines the portion of the model that is
visible.

Parameter ``origin``:
    The lower left front point that is visible.

Parameter ``delta``:
    The extent of the visible area.

Parameter ``rotation``:
    The view orientation.

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_IsEqual =R"doc(Tests this ViewInfo for equality with another ViewInfo.

Parameter ``other``:
    The other ViewInfo

r ``compareACS``:
    True if the ACS of the two should be compared.

Parameter ``compareDisplayStyleFlags``:
    True if the display style portion of ViewFlags of the two should
    be compared.

Remark:
    s The DisplayStyleFlags are the renderMode, renderDisplayEdges,
    renderDisplayHidden, hiddenLineStyle, silhouetteAndClips,
    renderDisplayShadows, and overrideBackground flags.

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	changeType.    A mask of the differences found.

)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetRootModel =R"doc(Sets the root model for this ViewInfo.

Parameter ``rootModel``:
    The new RootModel for this ViewInfo.

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetDynamicViewSettings =R"doc(Sets the the DynamicViewSettings for this ViewInfo.

Parameter ``settings``:
    The new DynamicViewSettings.

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetDynamicViewSettings =R"doc(Gets a const reference to the DynamicViewSettings that apply to this
ViewInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_Clear =R"doc(Clears the ViewInfo)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_Init =R"doc(Initializes the ViewInfo to the unused state.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetAuxCoordinateSystem =R"doc(Sets the Auxiliary Coordinate System to use in the view.

Parameter ``acs``:
    The Auxiliary Coordinate System.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetAuxCoordinateSystem =R"doc(Gets the Auxiliary Coordinate System in use in the view.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetAspectRatioSkew =R"doc(Returns the aspect ratio distortion for a specialized view. Usually
returns 1.0.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_TreatViewAs3D =R"doc(Returns true if the view should be treated as though it has 3D
content, even if the RootModel is a 2D model.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetBackgroundColor =R"doc(Sets the backgroun color of the view.

Parameter ``color``:
    The background color

Remark:
    s If the ViewInfo applies to one of the displayed views, the
    caller should call ViewGroup::SynchViewDisplay to inform the host
    that the view contents have been changed.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_IsNamed =R"doc(Returns true if the ViewInfo is hosted by a NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetBackgroundColor =R"doc(Gets the background color used in the view.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetRootModelId =R"doc(Gets the ModelId of the model displayed in the view.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetViewFlags =R"doc(Gets a const reference to the ViewFlags.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_SetGeomInfo =R"doc(Copy the ViewGeompInfo from the source.

Parameter ``source``:
    The source ViewGeomInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetGeomInfo =R"doc(Gets a const reference to the ViewGeomInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetCamera =R"doc(Gets a const reference to the CameraInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetActiveZ =R"doc(Gets the displacement of the active z from the view front, along the
view normal.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetRotation =R"doc(Gets the view orientation.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetDelta =R"doc(Gets the view extent.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetOrigin =R"doc(Gets the view origin.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_GetViewNumber =R"doc(Gets the view number.

Remark:
    s For a ViewInfo retrieved from a ViewGroup, the ViewNumber will
    be from 0 through MAX_VIEWS-1, inclusive. For a ViewInfo retrieved
    from a NamedView, it will be -1.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewInfo_EnsureLevelMaskCoverage =R"doc(Make sure that there is a per-view level display mask in every view.
@See ViewGroup::EnsureLevelMaskCoverage)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_SetClippingDepths =R"doc(Set the front and back clipping planes distances.

Parameter ``frontClip``:
    The distance to the front clipping plane from design plane origin
    (or NULL).

Parameter ``backClip``:
    The distance to the back clipping plane from design plane origin
    (or NULL).)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_CopyVolume =R"doc(Copies the view volume from the source viewInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_SetCameraFocalLength =R"doc(Sets the focal length of the view camera. If the view doesn't use the
camera (m_viewFlags.camera false),)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_GetTargetPoint =R"doc(The target point of the view camera. If the view doesn't use the
camera (m_viewFlags.camera false), the Center is returned.

Parameter ``target``:
    The target point.

Returns:
    The target argument, so that further calculations can conveniently
    use that value.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_GetCenter =R"doc(Get the center point of the view.

Parameter ``center``:
    The center point.

Returns:
    The center argument, so that further calculations can conveniently
    use that value.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_ApplyTransform =R"doc(Applies the given transform to the view position and orientation.

Parameter ``transform``:
    The transformation to apply.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGeomInfo_SetActiveDepthPoint =R"doc(Set the active depth given a point in world coordinates.

Parameter ``point``:
    The point from which to calculate m_activez.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ViewInfo(py::module_& m)
    {
    //===================================================================================
    // enum class ViewCategory
    py::enum_< ViewCategory>(m, "ViewCategory")
        .value("eDefault", ViewCategory::Default)
        .value("eDrafting", ViewCategory::Drafting)
        .value("eModeling", ViewCategory::Modeling)
        .value("eVisualization", ViewCategory::Visualization)
        .value("eSheet", ViewCategory::Sheet)
        .export_values();

    //===================================================================================
    // enum class ViewInfoStatus
    py::enum_< ViewInfoStatus>(m, "ViewInfoStatus", py::arithmetic())
        .value("eVI_Success", VI_Success)
        .value("eVI_BadModelRef", VI_BadModelRef)
        .value("eVI_CameraNotInUse", VI_CameraNotInUse)
        .export_values();

    //===================================================================================
    // struct ViewGeomInfo
    py::class_< ViewGeomInfo> c1(m, "ViewGeomInfo");

    c1.def("SetActiveDepthPoint", &ViewGeomInfo::SetActiveDepthPoint, "point"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, SetActiveDepthPoint));
    c1.def("ApplyTransform", &ViewGeomInfo::ApplyTransform, "transform"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, ApplyTransform));
    c1.def("GetCenter", &ViewGeomInfo::GetCenter, "center"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, GetCenter));
    c1.def("GetTargetPoint", &ViewGeomInfo::GetTargetPoint, "target"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, GetTargetPoint));
    c1.def("SetCameraFocalLength", &ViewGeomInfo::SetCameraFocalLength, "focalLength"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, SetCameraFocalLength));
    c1.def("CopyVolume", &ViewGeomInfo::CopyVolume, "sourceGeomInfo"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, CopyVolume));
    c1.def("SetClippingDepths",
        [](ViewGeomInfo& self, boost::optional<double> frontClip, boost::optional<double> backClip)
        {
            return self.SetClippingDepths(frontClip.get_ptr(), backClip.get_ptr());
        },
        "frontClip"_a, "backClip"_a, DOC(Bentley, DgnPlatform, ViewGeomInfo, SetClippingDepths));

    //===================================================================================
    // enum class ViewChangeType
    py::enum_< ViewChangeType>(m, "ViewChangeType")
        .value("eNone", ViewChangeType::None)
        .value("eGeometry", ViewChangeType::Geometry)
        .value("eRootModel", ViewChangeType::RootModel)
        .value("eLevels", ViewChangeType::Levels)
        .value("eBGColor", ViewChangeType::BGColor)
        .value("eDisplayFlags", ViewChangeType::DisplayFlags)
        .value("eDynamicView", ViewChangeType::DynamicView)
        .value("eACS", ViewChangeType::ACS)
        .value("eBackgroundMap", ViewChangeType::BackgroundMap)
        .value("eAll", ViewChangeType::All)
        .export_values();

    //===================================================================================
    // struct ViewInfo
    py::class_< ViewInfo, ViewInfoPtr> c2(m, "ViewInfo", py::multiple_inheritance());

    c2.def("EnsureLevelMaskCoverage", py::overload_cast<>(&ViewInfo::EnsureLevelMaskCoverage), DOC(Bentley, DgnPlatform, ViewInfo, EnsureLevelMaskCoverage));

    if (true)
        {
        //===================================================================================
        // enum LevelMaskCloneOpts
        py::enum_< ViewInfo::LevelMaskCloneOpts>(c2, "LevelMaskCloneOpts", py::arithmetic())
            .value("eLEVELMASKCLONE_Never", ViewInfo::LEVELMASKCLONE_Never)
            .value("eLEVELMASKCLONE_Copy", ViewInfo::LEVELMASKCLONE_Copy)
            .value("eLEVELMASKCLONE_CopyIfDifferent", ViewInfo::LEVELMASKCLONE_CopyIfDifferent)
            .value("eLEVELMASKCLONE_Transfer", ViewInfo::LEVELMASKCLONE_Transfer)
            .export_values();
        }

    c2.def_property_readonly("ViewNumber", &ViewInfo::GetViewNumber);
    c2.def("GetViewNumber", &ViewInfo::GetViewNumber, DOC(Bentley, DgnPlatform, ViewInfo, GetViewNumber));
    c2.def_property_readonly("Origin", &ViewInfo::GetOrigin);
    c2.def("GetOrigin", &ViewInfo::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetOrigin));
    
    c2.def_property_readonly("Delta", &ViewInfo::GetDelta);
    c2.def("GetDelta", &ViewInfo::GetDelta, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetDelta));
    
    c2.def_property_readonly("Rotation", &ViewInfo::GetRotation);
    c2.def("GetRotation", &ViewInfo::GetRotation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetRotation));
    
    c2.def_property_readonly("ActiveZ", &ViewInfo::GetActiveZ);
    c2.def("GetActiveZ", &ViewInfo::GetActiveZ, DOC(Bentley, DgnPlatform, ViewInfo, GetActiveZ));
    
    c2.def_property_readonly("Camera", &ViewInfo::GetCameraR);
    c2.def("GetCamera", &ViewInfo::GetCameraR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetCamera));
    
    c2.def_property("GeomInfo", &ViewInfo::GetGeomInfoR, &ViewInfo::SetGeomInfo);
    c2.def("GetGeomInfo", &ViewInfo::GetGeomInfoR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetGeomInfo));
    c2.def("SetGeomInfo", &ViewInfo::SetGeomInfo, "source"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetGeomInfo));
    
    c2.def_property_readonly("ViewFlags", &ViewInfo::GetViewFlagsR);
    c2.def("GetViewFlags", &ViewInfo::GetViewFlagsR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetViewFlags));
    
    c2.def_property_readonly("RootModelId", &ViewInfo::GetRootModelId);
    c2.def("GetRootModelId", &ViewInfo::GetRootModelId, DOC(Bentley, DgnPlatform, ViewInfo, GetRootModelId));

    c2.def("GetRootModel", &ViewInfo::GetRootModelP, "createIfNecessary"_a = false, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("RootDgnFile", &ViewInfo::GetRootDgnFileP);
    c2.def("GetRootDgnFile", &ViewInfo::GetRootDgnFileP, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("TargetModelRef", &ViewInfo::GetTargetModelRefP);
    c2.def("GetTargetModelRef", &ViewInfo::GetTargetModelRefP, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("BackgroundColor", &ViewInfo::GetBackgroundColor);
    c2.def("GetBackgroundColor", &ViewInfo::GetBackgroundColor, DOC(Bentley, DgnPlatform, ViewInfo, GetBackgroundColor));
    
    c2.def("IsNamed", &ViewInfo::IsNamed, DOC(Bentley, DgnPlatform, ViewInfo, IsNamed));    
    c2.def("AdjustAspectRatio", &ViewInfo::AdjustAspectRatio, "newAspect"_a, "expendView"_a);
    c2.def("SetBackgroundColor", &ViewInfo::SetBackgroundColor, "color"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetBackgroundColor));
    c2.def("TreatViewAs3D", &ViewInfo::TreatViewAs3D, DOC(Bentley, DgnPlatform, ViewInfo, TreatViewAs3D));

    c2.def_property_readonly("AspectRatioSkew", &ViewInfo::GetAspectRatioSkew);
    c2.def("GetAspectRatioSkew", &ViewInfo::GetAspectRatioSkew, DOC(Bentley, DgnPlatform, ViewInfo, GetAspectRatioSkew));
    
    c2.def_property("AuxCoordinateSystem", &ViewInfo::GetAuxCoordinateSystem, &ViewInfo::SetAuxCoordinateSystem);
    c2.def("GetAuxCoordinateSystem", &ViewInfo::GetAuxCoordinateSystem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetAuxCoordinateSystem));
    c2.def("SetAuxCoordinateSystem", &ViewInfo::SetAuxCoordinateSystem, "acs"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetAuxCoordinateSystem));
    
    c2.def("Init", py::overload_cast<>(&ViewInfo::Init), DOC(Bentley, DgnPlatform, ViewInfo, Init));
    c2.def("Clear", &ViewInfo::Clear, DOC(Bentley, DgnPlatform, ViewInfo, Clear));

    c2.def_property_readonly("DisplayStyle", &ViewInfo::GetDisplayStyleCP);
    c2.def("GetDisplayStyle", &ViewInfo::GetDisplayStyleCP, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("DisplayOverrides", &ViewInfo::GetDisplayOverridesCP);
    c2.def("GetDisplayOverrides", &ViewInfo::GetDisplayOverridesCP, py::return_value_policy::reference_internal);
    
    c2.def_property("DynamicViewSettings", &ViewInfo::GetDynamicViewSettingsR, &ViewInfo::SetDynamicViewSettings);
    c2.def("GetDynamicViewSettings", &ViewInfo::GetDynamicViewSettingsR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewInfo, GetDynamicViewSettings));
    c2.def("SetDynamicViewSettings", &ViewInfo::SetDynamicViewSettings, "settings"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetDynamicViewSettings));
    
    c2.def("SetRootModel", py::overload_cast<DgnModelP>(&ViewInfo::SetRootModel), "rootModel"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetRootModel));
    c2.def("SetRootModel", py::overload_cast<ModelId, DgnFileP>(&ViewInfo::SetRootModel), "rootModelId"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetRootModel));

    c2.def("IsEqual", [] (ViewInfo const& self, ViewInfoCP other, bool compareACS, bool compareDisplayStyleFlags)
           {
           ViewChangeType changeType;
           auto retVal = self.IsEqual(other, changeType, compareACS, compareDisplayStyleFlags);
           return py::make_tuple(retVal, changeType);
           }, "other"_a, "compareACS"_a = true, "compareDisplayStyleFlags"_a = true, DOC(Bentley, DgnPlatform, ViewInfo, IsEqual));

    c2.def("SetGeometry", &ViewInfo::SetGeometry, "origin"_a, "delta"_a, "rotation"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetGeometry));
    c2.def("SetTargetModelRef", &ViewInfo::SetTargetModelRef, "target"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetTargetModelRef));

    c2.def("Init",
           py::overload_cast<UInt32, DgnModelP, DRange3dCR, BSIRectCP, RotMatrixCP, ViewFlagsCP, bool>(&ViewInfo::Init),
           "viewNumber"_a, "rootModel"_a, "range"_a, "windowRect"_a, "rotation"_a, "flags"_a, "isOn"_a, DOC(Bentley, DgnPlatform, ViewInfo, Init));

    c2.def("GetLevelDisplay", [] (ViewInfo const& self, DgnModelRefP model, LevelId levelID)
           {
           bool isOn = false;
           auto retVal = self.GetLevelDisplay(isOn, model, levelID);
           return py::make_tuple(retVal, isOn);
           }, "modelRef"_a, "levelID"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetLevelDisplay));

    c2.def("SetLevelDisplay", &ViewInfo::SetLevelDisplay, "modelRef"_a, "levelId"_a, "onOff"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetLevelDisplay));

    c2.def("GetLevelDisplayMask", [] (ViewInfo const& self, DgnModelRefP model)
           {
           BitMaskCP levelBitMask = nullptr;
           auto retVal = self.GetLevelDisplayMask(levelBitMask, model);
           return py::make_tuple(retVal, std::unique_ptr< BitMask, py::nodelete>(const_cast<BitMaskP>(levelBitMask)));
           }, "modelRef"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetLevelDisplayMask));

    c2.def("SetLevelDisplayMask", &ViewInfo::SetLevelDisplayMask, "modelRef"_a, "levelBitMask"_a, DOC(Bentley, DgnPlatform, ViewInfo, SetLevelDisplayMask));

    c2.def("GetEffectiveLevelDisplay", [] (ViewInfo const& self, DgnModelRefP model, LevelId levelID)
           {
           bool isDisplayed = false;
           auto retVal = self.GetEffectiveLevelDisplay(isDisplayed, model, levelID);
           return py::make_tuple(retVal, isDisplayed);
           }, "modelRef"_a, "levelId"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetEffectiveLevelDisplay));

    c2.def("GetEffectiveLevelDisplayMask", [] (ViewInfo const& self, DgnModelRefP model)
           {
           BitMaskCP levelBitMask = nullptr;
           auto retVal = self.GetEffectiveLevelDisplayMask(levelBitMask, model);
           return py::make_tuple(retVal, std::unique_ptr< BitMask, py::nodelete>(const_cast<BitMaskP>(levelBitMask)));
           }, "modelRef"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetEffectiveLevelDisplayMask));
    c2.def_static("Create", py::overload_cast<bool>(&ViewInfo::Create), "namedView"_a, DOC(Bentley, DgnPlatform, ViewInfo, Create));
    c2.def_static("Create", py::overload_cast<bool, DgnModelP, UInt32, DRange3dCR, BSIRectCP, StandardView, bool>(&ViewInfo::Create),
                  "namedView"_a, "rootModel"_a, "viewNumber"_a, "range"_a, "windowRect"_a, "standardView"_a, "isOn"_a, DOC(Bentley, DgnPlatform, ViewInfo, Create));
    c2.def_static("GetDefaultFlags", &ViewInfo::GetDefaultFlags, "viewFlags"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetDefaultFlags));
    c2.def_static("IsStandardViewRotation", &ViewInfo::IsStandardViewRotation, "rotation"_a, "check3D"_a, DOC(Bentley, DgnPlatform, ViewInfo, IsStandardViewRotation));
    c2.def_static("GetStandardViewName", &ViewInfo::GetStandardViewName, "viewName"_a, "standardView"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetStandardViewName));
    c2.def_static("GetStandardViewByName", &ViewInfo::GetStandardViewByName, "rMatrix"_a, "standardView"_a, "viewName"_a, DOC(Bentley, DgnPlatform, ViewInfo, GetStandardViewByName));    

    //===================================================================================
    // struct ViewPortInfo
    py::class_< ViewPortInfo, ViewPortInfoPtr> c3(m, "ViewPortInfo", py::multiple_inheritance());

    c3.def("Clear", &ViewPortInfo::Clear, DOC(Bentley, DgnPlatform, ViewPortInfo, Clear));
    c3.def("__eq__", [] (ViewPortInfoCP self, ViewPortInfoCP other) { return self->IsEqual(other); });
    
    c3.def_property_readonly("RelativeOrigin", &ViewPortInfo::GetRelativeOrigin);
    c3.def("GetRelativeOrigin", &ViewPortInfo::GetRelativeOrigin);
    
    c3.def_property_readonly("RelativeCorner", &ViewPortInfo::GetRelativeCorner);
    c3.def("GetRelativeCorner", &ViewPortInfo::GetRelativeCorner);
    
    c3.def_property_readonly("PixelOrigin", &ViewPortInfo::GetPixelOrigin);
    c3.def("GetPixelOrigin", &ViewPortInfo::GetPixelOrigin);
    
    c3.def_property_readonly("PixelCorner", &ViewPortInfo::GetPixelCorner);
    c3.def("GetPixelCorner", &ViewPortInfo::GetPixelCorner);
    
    c3.def_property_readonly("ScreenNumber", &ViewPortInfo::GetScreenNumber);
    c3.def("GetScreenNumber", &ViewPortInfo::GetScreenNumber);
    
    c3.def_property_readonly("IsDefined", &ViewPortInfo::GetIsDefined);
    c3.def("GetIsDefined", &ViewPortInfo::GetIsDefined);
    
    c3.def_property_readonly("AspectRatio", &ViewPortInfo::GetAspectRatio);
    c3.def("GetAspectRatio", &ViewPortInfo::GetAspectRatio, DOC(Bentley, DgnPlatform, ViewPortInfo, GetAspectRatio));

    c3.def(py::init(py::overload_cast<>(&ViewPortInfo::Create)));
    c3.def(py::init(py::overload_cast<BSIRectCR, BSIRectCR, UInt32, bool>(&ViewPortInfo::Create)), "windowRect"_a, "screenRect"_a, "screenNumber"_a, "wasDefined"_a);
    c3.def_static("CopyFrom", &ViewPortInfo::CopyFrom, "source"_a, DOC(Bentley, DgnPlatform, ViewPortInfo, CopyFrom));
    }