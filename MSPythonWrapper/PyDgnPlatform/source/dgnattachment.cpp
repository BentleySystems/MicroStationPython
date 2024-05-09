/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnattachment.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/NamedView.h>
#include <DgnPlatform/DgnAttachment.h>



static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetNamedView =R"doc(Gets the named view to which this attachment refers in the referenced
file.

Returns:
    A named view, or a NamedViewPtr with IsNull() true if this
    attachment does not refer to a named view.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_ApplyStandardView =R"doc(Use a standard view to define the location and extent of this
attachment.

Parameter ``stdview``:
    The standard view to apply.

Parameter ``userScale``:
    The scale to be applied to the attachment.

Parameter ``acsScale``:
    An additional scale to be applied to the attachment. This normally
    comes from the current ACS, but only if the model's
    MODELFLAG_ACS_LOCK flag is set. Optional, with default of 1.0.

Returns:
    SUCCESS if successful or a non-zero error status if the view could
    not be applied.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetAttachDescription =R"doc(Sets the attachment description. A description is optional.

See also:
    GetAttachDescription
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetAttachDescription =R"doc(Gets the attachment description.

Returns:
    an empty string if the attachment has no description.

See also:
    SetAttachDescription
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetUniqueLogical =R"doc(Generates a unique logical name and sets the DgnAttachments logical
name to that unique name.

See also:
    SetLogicalName, GetLogicalName
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetLogicalName =R"doc(@name Description Sets the attachment logical name. Unique logical
names are required for duplicate attachments of the same model to the
parent model.

Returns:
    non-zero error status if this attachment is a duplicate and the
    specified logical is not unique.

See also:
    GetLogicalName, SetUniqueLogical
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetLogicalName =R"doc(Gets the attachment's logical name.

Returns:
    the logical name of the attachment or the empty string if not set.

See also:
    SetLogicalName, SetUniqueLogical

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetSynchWithNamedView =R"doc(Sets whether the attachment should get the level display, view flags,
and clip volume from the named view each time the referenced model is
loaded. See #ReferenceSynchOption for options. This only applies if
the attachment refers to a named view. See #GetNamedView.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetSynchWithNamedView =R"doc(Indicates how this attachment uses the level display, view flags, and
clip volume from the named view each time the referenced model is
loaded. See #ReferenceSynchOption for options. This only applies if
the attachment refers to a named view. See #GetNamedView.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetRotateClipping =R"doc(Sets the attachment clip rotation.

Parameter ``yesNo``:
    Set to false to have clipping points relative to view coordinate
    system. The clipping points are relative to the global X-Y plane
    if a value of true is specified.

Remark:
    s This method is provided to allow the " true " value to be set.
    Setting RotateClipping to false is of very little use and is
    highly discouraged.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsRotateClipping =R"doc(Indicates whether the clipping points are to be rotated to global
coordinate system.

Returns:
    false if clipping point are view independent and are relative to
    the view coordinate system.

Remark:
    s Nearly all attachments created in MicroStation V8 and later
    versions will return true. View independent clipping is not very
    useful.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetClipRotMatrix =R"doc(Sets the attachment clip rotation.

Parameter ``rotation``:
    Rotation matrix for clipping points.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetClipRotMatrix =R"doc(Gets the attachment clip rotation.
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetBackClipDepth =R"doc(Sets depth of back clipping plane.

Parameter ``depth``:
    Value for back clipping plane, this value must be less than the
    value for the front clip depth.

Returns:
    SUCCESS if specified clip depth can be set. ERROR typically means
    that the depth specified is greater than the front clip depth.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetBackClipDepth =R"doc(Gets the attachment back clip depth.

Returns:
    value of the back clip depth.

See also:
    HasFrontClip

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetFrontClipDepth =R"doc(Sets depth of front clipping plane.

Parameter ``depth``:
    Value for front clipping plane, this value must be greater than
    the value for the back clip depth.

Returns:
    SUCCESS if specified clip depth can be set. ERROR typically means
    that the depth specified is less than the back clip depth.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetFrontClipDepth =R"doc(Gets the attachment front clip depth.

Returns:
    value of the front clip depth.

See also:
    HasFrontClip

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_HasFrontClip =R"doc(Indicates whether the attachment has a back clip depth defined.

Returns:
    true if back clip depth is defined.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_HasBackClip =R"doc(Indicates whether the attachment has a back clip depth defined.

Returns:
    true if back clip depth is defined.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_AppendClipVoidPoints =R"doc(Append clip boundary points from points in a view coordinate system.
Clip points a relative to the origin specified, with the specified
rotation.

Parameter ``points``:
    An array of clip points, in the coordinate system of a view
    specified by the other arguments. The points in this array might
    be changed by this method.

Parameter ``numPoints``:
    The number of clip points in the array. The maximum number of
    points allowed is specified by MAX_REFCLIPPNTS.

Parameter ``viewRotMatrix``:
    The viewing rotation matrix.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetClipPoints =R"doc(Sets clip boundary points.

Parameter ``points``:
    An array of clip points, in UORs of the DgnAttachment model,
    relative to the DgnAttachment model's origin.

Parameter ``numPoints``:
    The number of clip points in the array. The maximum number of
    points allowed is specified by MAX_REFCLIPPNTS.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetClipPoints =R"doc(Gets clip boundary points.

Parameter ``clipPoints``:
    Vector of points to be populated. @DotNetMethodExclude

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetClipPointCount =R"doc(Gets the count of stored clip boundary points. Returns 0 if this
DgnAttachment is clipped by a clipping element. @DotNetMethodExclude

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_ClearClipElementId =R"doc(Clear the ElementId of the clipping element.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetClipElementId =R"doc(Sets the ElementId of the clipping element.

Parameter ``clipElement``:
    Element ID of clipping element.

Returns:
    ERROR if an element with the specified element ID is not found
    with the DgnAttachment's DgnModel.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetClipElementId =R"doc(Gets the ElementId of the clipping element. If no clipping element
defined then 0L is returned.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetClipBoundaries =R"doc(Gets the clip descriptor for this attachments clip boundary.

Parameter ``clip``:
    The ClipVector object that describes the clipping for this
    reference.

Parameter ``vp``:
    The viewport for which to get the ClipVector. This is needed in
    cases where the DgnAttachment is clipped by an element.

Parameter ``relativeToImmediateParent``:
    When true, the ClipVector coordinates are in the coordinate system
    of the immediate parent, rather than the coordinate system of the
    root model.

Parameter ``onlyMasksIfClipElement``:
    When true, and the DgnAttachment is clipped by an element, gets
    only the clip masks.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsClipped =R"doc(@name Clipping Indicates whether the attachment has a clip boundary or
mask defined. If this is a nested attachment then true is returned if
any parent has a clip boundary or mask defined.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsHighlighted =R"doc(Indicates whether this attachment is highlighted. An attachment is
highlighted if the attachment is highlighted or if its parent is
highlighted.

Parameter ``checkParents``:
    [in] If true, check the parent highlighted state, and return true
    if any parent is highlighted.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsInSS =R"doc(Indicates whether this attachment is in the selection set (SS). An
attachment is in the Selection Set if the attachment element is in the
Selection Set or if its parent is in the Selection Set.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetDoNotDisplayAsNested =R"doc(Specify if this attachment is not to be displayed as a nested
attachment

See also:
    GetDoNotDisplayAsNested

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetDoNotDisplayAsNested =R"doc(Indicates whether this attachment is not to be displayed as a nested
attachment

Remark:
    s When true, this DgnAttachment is displayed only when its parent
    model is the root model.

See also:
    SetDoNotDisplayAsNested

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetTransparency =R"doc(Sets display transparency.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetNestDepth =R"doc(Sets the nest depth. This limits the number of steps that DgnPlatform
will take along a path from a referenced model to the models that it
references when loading nested attachments. <p>Counting begins at the
direct attachment (the top-most reference that is attached to a
DgnModel). Nested references that are separated from the direct
attachment by more intermediate attachments than the nest depth are
not loaded or displayed. For example, a nest depth of 0 allows only
direct attachments to be loaded. Their nested attachments would not be
loaded. A nest depth of 1 allows direct attachments and their
immediate attachments. <p>Specify a large number such as 99 if you do
not want any limit placed on nested attachment loading.

See also:
    GetNestDepth

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetNestDepth =R"doc(Gets the nest depth.

See also:
    SetNestDepth

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetApplicationLocked =R"doc(Sets Application Locked to prevent user initiation of transform
operations like move, scale, rotate, and mirror.

Remark:
    s A DgnAttachment should be set to ApplicationLocked only if
    absolutely necessary, as it has the potential to confuse and
    irritate users.

See also:
    IsApplicationLocked

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsApplicationLocked =R"doc(Indicates whether the attachment is Application Locked. If a
DgnAttachment is Application Locked, transform operations like move,
scale, rotate, and mirror cannot be user-initiated.

See also:
    SetApplicationLocked

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_DoesLevelControlDisplay =R"doc(Indicates whether the attachment should be displayed only when its
level is displayed.

See also:
    SetLevelControlsDisplay

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetDgnAttachmentLevel =R"doc(Assign the attachment itself to a level in the parent file

Parameter ``[in]``:
    levelId The level to assign. Pass (LevelId) 0 to specify that the
    DgnAttachment is not on any level.

See also:
    GetDgnAttachmentLevel

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetDgnAttachmentLevel =R"doc(Gets the level of the attachment in the model that contains it.

See also:
    SetDgnAttachmentLevel

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsDisplayed =R"doc(Gets the state of the DgnAttachments display flag.

Remark:
    s A true value for the DgnAttachment display flag does not
    necessarily mean that the DgnAttachment is displayed. However, a
    false value guarantees that it is not displayed.

See also:
    SetIsDisplayed

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetIsDisplayed =R"doc(Sets the DgnAttachment's display flag.

Parameter ``state``:
    The new display state.

Parameter ``loadIfNecessary``:
    Load the attachment model, if not already loaded.

Parameter ``processAffected``:
    Whether to invoke dependency callbacks when loading the
    DgnAttachment is complete. This only matters if loadIfNecessary is
    true and the DgnAttachment model was not previously loaded.

Remark:
    s By default, undisplayed references are not loaded to save time
    and memory.

Remark:
    s Setting the Display flag to true does not guarantee that a
    DgnAttachment will be displayed. The DgnAttachment can be on a
    specific level, in which case that level must also be turned on.

Remark:
    s For a nested DgnAttachment to be displayed, all of its parent
    DgnAttachments must also be displayed.

See also:
    IsDisplayed

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetLocateStatus =R"doc(Gets the locate status of the attachment.

Remark:
    s This method checks the Locate lock of this DgnAttachment and all
    of its parent DgnAttachments.

See also:
    IsLocateLocked

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetDisplayScale =R"doc(Gets the attachment display scale in the referenced model. If the
scale mode is SCALE_MODE_Direct the displayed scale is the same as the
display scale - otherwise the displayed scale is calculated at load
time based on the stored scale, the ScaleMode, and the units of the
DgnAttachment model and the parent model.

See also:
    SetStoredScale, GetDisplayScale, GetScaleMode.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetSnapLock =R"doc(Sets the snap lock flag of the attachment

See also:
    IsSnapLocked

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsSnapLocked =R"doc(Gets the snap lock flag of the attachment

Remark:
    s To test if a nested attachment permits snapping, you must *and*
    the return value of this function with that of all of its parents.

See also:
    SetSnapLock

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetLocateLock =R"doc(Sets the locate lock flag of the attachment

See also:
    IsLocateLocked

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsLocateLocked =R"doc(@name Properties Gets the locate lock flag of the attachment

Remark:
    s To test if a nested attachment permits locate, you must *and*
    the return value of this function with that of all of its parents.

See also:
    SetLocateLock, GetLocateStatus

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetStoredScale =R"doc(Sets a scale factor to be applied when displaying elements from the
referenced model.

See also:
    GetStoredScale.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetStoredScale =R"doc(Gets the stored attachment scale in the referenced model. If the scale
mode is SCALE_MODE_Direct the displayed scale is the same as the
display scale - otherwise the displayed scale is calculated at load
time based on the stored scale, the ScaleMode, and the units of the
DgnAttachment model and the parent model.

See also:
    SetStoredScale, GetDisplayScale, GetScaleMode.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetScaleMode =R"doc(Sets the kind of scaling to apply when displaying elements from the
referenced model.

Remark:
    s SCALE_MODE_TrueScale is the most common and the most useful
    mode.

See also:
    GetScaleMode

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetScaleMode =R"doc(Gets the kind of scaling to apply when displaying elements from the
referenced model.

See also:
    SetScaleMode, GetTransformToParent

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetRefOrigin =R"doc(Sets the location in the referenced model that should coincide with
the master origin in the parent model. Defaults to 0,0,0. Specified in
referenced file UORs.

See also:
    GetRefOrigin

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetRefOrigin =R"doc(Gets the attachment origin in the referenced model.

See also:
    SetRefOrigin, GetTransformToParent

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetMasterOrigin =R"doc(Sets the location in the parent model at which the referenced model
should be displayed. Specified in parent model coordinates.

See also:
    GetMasterOrigin

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetMasterOrigin =R"doc(Gets the location in the parent model at which the referenced model
should be displayed.

See also:
    SetMasterOrigin, GetTransformToParent

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetRotMatrix =R"doc(Sets the rotation to be applied when displaying from the referenced
model.

See also:
    GetRotMatrix

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetRotMatrix =R"doc(Gets the rotation to be applied when displaying from the referenced
model.

See also:
    SetRotMatrix, GetTransformToParent

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetTransformToParent =R"doc(@name Reference Transform Gets the net transform to be applied when
displaying from the referenced model. The transform is composed of
unit scaling, the offset from the origin in the referenced model to
the master origin, any specified scale factor, and any specified
rotation matrix.

See also:
    SetRotMatrix, SetMasterOrigin, SetRefOrigin, SetScaleMode,
    SetScale

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetAttachMoniker =R"doc(Sets the moniker that identifies the referenced file

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetAttachMoniker =R"doc(Gets the moniker that identifies the referenced file

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsMissingGeoCoordSys =R"doc(Indicates whether the target model was not loaded because it is set to
be Geographically attached, but there is no Geographic Coordinate
System associated with either the attachment model or the parent
model.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsMissingGeoCoordApp =R"doc(Indicates whether the target model was not loaded because it is set to
be Geographically attached, but the geographic reprojection module is
not loaded.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsRevisionNotAvailable =R"doc(Indicates whether the target model was not loaded because it is set to
a particular DgnHistory revision, and that revision could not be
found.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsRightNotGranted =R"doc(Indicates whether the target model was not loaded because it is
protected is protected and the current process is unable to open it.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsMissingModel =R"doc(Indicates whether the target model was not found

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_IsMissingFile =R"doc(Indicates whether the target file was not found.

Remark:
    s This function returns true if there was any reason that the
    DgnAttachment could not be processed. It is actually an " or " of
    IsMissingModel, IsRightNotGranted, IsRevisionNotAvailable,
    IsMissingGeoCoordApp, and IsMissingGeoCoordSys.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetAttachModelName =R"doc(Gets the name of the model to be attached.

Remark:
    s This function returns the empty string if the referenced model
    is the default model.

Returns:
    the name of the model to be attached or blank for the default
    model.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetAttachFullFileSpec =R"doc(Gets the full path to the local file as attached.

Parameter ``dontFindIfPreviouslyNotFound``:
    Avoid repeating file system or network search if previous attempt
    to resolve the local file path failed.

Returns:
    the full filepath of the referenced file. @See GetAttachFileName

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetAttachFileName =R"doc(Gets the file name for this DgnAttachment.

Returns:
    the name of the referenced file or blank for the parent file.

Remark:
    s This function returns the empty string if the referenced model
    is in the same file as the DgnAttachment itself. @See
    GetAttachFullFileSpec

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetBaseDgnAttachment =R"doc(Gets the direct attachment that leads to this attachment.

Returns:
    If this DgnAttachment is a nested DgnAttachment, return its
    outermost (non-nested) parent DgnAttachment. This is sometimes
    referred to as the " direct attachment ". If this DgnAttachment is
    not a nested attachment, it returns itself.

See also:
    GetParentDgnAttachmentCP

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetParent =R"doc(Gets the model ref that owns this attachment.

Remark:
    s Every DgnAttachment has a parent.

Returns:
    the parent DgnModelRef of this DgnAttachment.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_FindAppData =R"doc(Search the DgnAttachmentAppData list for this DgnAttachment for an
entry with a particular key.

Returns:
    the DgnAttachmentAppData with *key,* or NULL. @See AddAppData
    @DotNetMethodCustomImplementation

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_DropAppData =R"doc(Remove DgnAttachmentAppData from this DgnAttachment.

Returns:
    SUCCESS if appData with key is found and was dropped. @See
    AddAppData @DotNetMethodCustomImplementation

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_AddAppData =R"doc(@name DgnAttachmentAppData Management Add (or replace)
DgnAttachmentAppData to this DgnAttachment.

Returns:
    SUCCESS if appData was successfully added. Note that it is illegal
    to add or remove AppData from within any of the AppData " _On "
    methods. If an entry with *key* already exists, it will be dropped
    and replaced with *appData.* @See DropAppData, FindAppData
    @DotNetMethodCustomImplementation

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetElementId =R"doc(Gets the ElementId of the reference attachment element. @See
DgnModelRef:;FindDgnAttachmentByElementId

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_Rewrite =R"doc(Rewrite the DgnAttachment definition to the parent model. Call this
after changing parameters using any Set methods.

Returns:
    Non-zero error status if the write operation failed. May be \li
    DGNATTACHMENT_ERROR_DuplicateLogical - You must call
    SetLogicalName or SetUniqueLogical \li DGNMODEL_STATUS_ReadOnly -
    the parent model is read-only <p>@See DgnFile::ProcessChanges

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_WriteToModel =R"doc(@name Persistence Write the DgnAttachment definition to the parent
model. Call this after creating a new attachment.

Returns:
    Non-zero error status if the write operation failed. May be \li
    DGNATTACHMENT_ERROR_DuplicateLogical - You must call
    SetLogicalName or SetUniqueLogical \li DGNMODEL_STATUS_ReadOnly -
    the parent model is read-only <p>@See DgnFile::ProcessChanges

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_SetAllowActivation =R"doc()doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachment_GetAllowActivation =R"doc()doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachmentAppData__OnRewrite =R"doc(Override this method to be notified when the attachment element is
rewritten (due to an attachment change).)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachmentAppData__OnCacheRelease =R"doc(Override this method to be notified when the DgnModel associated with
the DgnAttachment is about to be released (and possibly reloaded). If
the method returns true, the DgnAttachmentAppData is dropped from the
DgnAttachment. Do not delete your DgnAttachmentAppData in this method.
Instead, return true and delete your DgnAttachmentAppData in your
_OnCleanup method.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachmentAppData__OnCleanup =R"doc(Override this method to be notified when host DgnAttachment
DgnAttachmentAppData is about to be deleted from memory.)doc";

//=======================================================================================
// Trampoline class for DgnAttachmentAppData.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnAttachmentAppData : DgnAttachmentAppData
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnCleanup(DgnAttachmentR host) override
        { PYBIND11_OVERRIDE_PURE_EX(void, DgnAttachmentAppData, _OnCleanup, host); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _OnCacheRelease(DgnAttachmentR host) override
        { PYBIND11_OVERRIDE_EXR(bool, DgnAttachmentAppData, _OnCacheRelease, false, host); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void _OnRewrite(DgnAttachmentR host) override
        { PYBIND11_OVERRIDE_EX(void, DgnAttachmentAppData, _OnRewrite, host); }
    };

using DgnAttachmentPtr = std::unique_ptr<DgnAttachment, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnAttachment(py::module_& m)
    {
    //===================================================================================
    // enum class DgnAttachmentLocateStatus
    py::enum_< DgnAttachmentLocateStatus>(m, "DgnAttachmentLocateStatus")
        .value("eLocateOn", DgnAttachmentLocateStatus::LocateOn)
        .value("eLocateOff", DgnAttachmentLocateStatus::LocateOff)
        .value("eParentLocateOff", DgnAttachmentLocateStatus::ParentLocateOff)
        .value("eNoLocateRights", DgnAttachmentLocateStatus::NoLocateRights)
        .value("eParentNoLocateRights", DgnAttachmentLocateStatus::ParentNoLocateRights)
        .export_values();        

    //===================================================================================
    // enum class ProxyCacheStatus
    py::enum_< ProxyCacheStatus>(m, "ProxyCacheStatus")
        .value("eNotCached", ProxyCacheStatus::NotCached)
        .value("eUpToDate", ProxyCacheStatus::UpToDate)
        .value("eModelChanged", ProxyCacheStatus::ModelChanged)
        .value("eViewChanged", ProxyCacheStatus::ViewChanged)
        .value("eNotUsedInView", ProxyCacheStatus::NotUsedInView)
        .value("eAttachmentChanged", ProxyCacheStatus::AttachmentChanged)
        .value("eObsoleteVersion", ProxyCacheStatus::ObsoleteVersion)
        .value("eNotDisplayedInView", ProxyCacheStatus::NotDisplayedInView)
        .value("eMissingReferences", ProxyCacheStatus::MissingReferences)
        .value("eDisconnected", ProxyCacheStatus::Disconnected)
        .value("eReferenceNotFound", ProxyCacheStatus::ReferenceNotFound)
        .value("eReferenceLoadDisabled", ProxyCacheStatus::ReferenceLoadDisabled)
        .value("eObsoleteValidityHash", ProxyCacheStatus::ObsoleteValidityHash)
        .export_values();       

    //===================================================================================
    // struct DgnAttachmentAppData
    py::class_< DgnAttachmentAppData, PyDgnAttachmentAppData> c1(m, "DgnAttachmentAppData");
    if (true)
        {
        py::class_<DgnAttachmentAppData::Key, AppDataKey> c1_1(c1, "Key");
        }

    c1.def(py::init<>());
    c1.def("_OnCleanup", &DgnAttachmentAppData::_OnCleanup, "host"_a, DOC(Bentley, DgnPlatform, DgnAttachmentAppData, _OnCleanup));
    c1.def("_OnCacheRelease", &DgnAttachmentAppData::_OnCacheRelease, "host"_a, DOC(Bentley, DgnPlatform, DgnAttachmentAppData, _OnCacheRelease));
    c1.def("_OnRewrite", &DgnAttachmentAppData::_OnRewrite, "host"_a, DOC(Bentley, DgnPlatform, DgnAttachmentAppData, _OnRewrite));

    //===================================================================================
    // struct DgnAttachment
    py::class_<DgnAttachment, DgnAttachmentPtr, DgnModelRef> c2(m, "DgnAttachment");
    bind_PointerVector<DgnAttachmentP>(m, "DgnAttachmentPArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // enum ScaleMode
        py::enum_<DgnAttachment::ScaleMode>(c2, "ScaleMode", py::arithmetic())
            .value("eSCALE_MODE_TrueScale", DgnAttachment::SCALE_MODE_TrueScale)
            .value("eSCALE_MODE_StorageUnits", DgnAttachment::SCALE_MODE_StorageUnits)
            .value("eSCALE_MODE_Direct", DgnAttachment::SCALE_MODE_Direct)
            .export_values();

        //===================================================================================
        // struct ApplyViewClipOptions
        py::class_<DgnAttachment::ApplyViewClipOptions> c2_1(c2, "ApplyViewClipOptions");

        c2_1.def(py::init<>());
        c2_1.def("SetClipBoundary", &DgnAttachment::ApplyViewClipOptions::SetClipBoundary, "b"_a);
        c2_1.def("SetApplyFrontBackClip", &DgnAttachment::ApplyViewClipOptions::SetApplyFrontBackClip, "b"_a);
        c2_1.def("SetKeepMask", &DgnAttachment::ApplyViewClipOptions::SetKeepMask, "b"_a);
        }

    c2.def_property("AllowActivation", &DgnAttachment::GetAllowActivation, &DgnAttachment::SetAllowActivation);
    c2.def("GetAllowActivation", &DgnAttachment::GetAllowActivation, DOC(Bentley, DgnPlatform, DgnAttachment, GetAllowActivation));
    c2.def("SetAllowActivation", &DgnAttachment::SetAllowActivation, "yesNo"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetAllowActivation));
    c2.def("WriteToModel", &DgnAttachment::WriteToModel, "loadRasterRefs"_a = false, "treatAsNew"_a = false, DOC(Bentley, DgnPlatform, DgnAttachment, WriteToModel));
    c2.def("Rewrite", &DgnAttachment::Rewrite, "writeSettings"_a, "writeLevelDisplaySettings"_a, DOC(Bentley, DgnPlatform, DgnAttachment, Rewrite));
    c2.def("GetElementId", &DgnAttachment::GetElementId, DOC(Bentley, DgnPlatform, DgnAttachment, GetElementId));

    c2.def("AddAppData", &DgnAttachment::AddAppData, "key"_a, "appData"_a, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, DgnAttachment, AddAppData));
    c2.def("DropAppData", &DgnAttachment::DropAppData, "key"_a, DOC(Bentley, DgnPlatform, DgnAttachment, DropAppData));
    c2.def("FindAppData", &DgnAttachment::FindAppData, "key"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, FindAppData));

    c2.def_property_readonly("Parent", &DgnAttachment::GetParentR);
    c2.def("GetParent", &DgnAttachment::GetParentR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetParent));
    
    c2.def_property_readonly("ParentDgnAttachment", &DgnAttachment::GetParentDgnAttachmentP);
    c2.def("GetParentDgnAttachment", &DgnAttachment::GetParentDgnAttachmentP, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("BaseDgnAttachment", &DgnAttachment::GetBaseDgnAttachmentR);
    c2.def("GetBaseDgnAttachment", &DgnAttachment::GetBaseDgnAttachmentR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetBaseDgnAttachment));
    
    c2.def_property_readonly("AttachFileName", &DgnAttachment::GetAttachFileName);
    c2.def("GetAttachFileName", &DgnAttachment::GetAttachFileName, DOC(Bentley, DgnPlatform, DgnAttachment, GetAttachFileName));

    c2.def("GetAttachFullFileSpec", &DgnAttachment::GetAttachFullFileSpec, "dontFindIfPreviouslyNotFound"_a, DOC(Bentley, DgnPlatform, DgnAttachment, GetAttachFullFileSpec));
    
    c2.def_property_readonly("AttachModelName", &DgnAttachment::GetAttachModelName);
    c2.def("GetAttachModelName", &DgnAttachment::GetAttachModelName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetAttachModelName));

    c2.def("IsMissingFile", &DgnAttachment::IsMissingFile, DOC(Bentley, DgnPlatform, DgnAttachment, IsMissingFile));
    c2.def("IsMissingModel", &DgnAttachment::IsMissingModel, DOC(Bentley, DgnPlatform, DgnAttachment, IsMissingModel));
    c2.def("IsRightNotGranted", &DgnAttachment::IsRightNotGranted, DOC(Bentley, DgnPlatform, DgnAttachment, IsRightNotGranted));
    c2.def("IsRevisionNotAvailable", &DgnAttachment::IsRevisionNotAvailable, DOC(Bentley, DgnPlatform, DgnAttachment, IsRevisionNotAvailable));
    c2.def("IsMissingGeoCoordApp", &DgnAttachment::IsMissingGeoCoordApp, DOC(Bentley, DgnPlatform, DgnAttachment, IsMissingGeoCoordApp));
    c2.def("IsMissingGeoCoordSys", &DgnAttachment::IsMissingGeoCoordSys, DOC(Bentley, DgnPlatform, DgnAttachment, IsMissingGeoCoordSys));

    c2.def_property("AttachMoniker", &DgnAttachment::GetAttachMoniker, &DgnAttachment::SetAttachMoniker);
    c2.def("GetAttachMoniker", &DgnAttachment::GetAttachMoniker, DOC(Bentley, DgnPlatform, DgnAttachment, GetAttachMoniker));
    c2.def("SetAttachMoniker", &DgnAttachment::SetAttachMoniker, "moniker"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetAttachMoniker));

    c2.def("GetTransformToParent", &DgnAttachment::GetTransformToParent, "transform"_a, "scaleZfor2dRef"_a, DOC(Bentley, DgnPlatform, DgnAttachment, GetTransformToParent));
    
    c2.def_property("RotMatrix", &DgnAttachment::GetRotMatrix, &DgnAttachment::SetRotMatrix);
    c2.def("GetRotMatrix", &DgnAttachment::GetRotMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetRotMatrix));
    c2.def("SetRotMatrix", &DgnAttachment::SetRotMatrix, "rotMatrix"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetRotMatrix));
    
    c2.def_property("MasterOrigin",
                    [] (DgnAttachment const& self) { DPoint3d origin; self.GetMasterOrigin(origin); return origin; },
                    &DgnAttachment::SetMasterOrigin);
    c2.def("GetMasterOrigin", &DgnAttachment::GetMasterOrigin, "origin"_a, DOC(Bentley, DgnPlatform, DgnAttachment, GetMasterOrigin));
    c2.def("SetMasterOrigin", &DgnAttachment::SetMasterOrigin, "origin"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetMasterOrigin));
    
    c2.def_property("RefOrigin", &DgnAttachment::GetRefOrigin, &DgnAttachment::SetRefOrigin);
    c2.def("GetRefOrigin", &DgnAttachment::GetRefOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetRefOrigin));
    c2.def("SetRefOrigin", &DgnAttachment::SetRefOrigin, "origin"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetRefOrigin));
    
    c2.def_property("ScaleMode", &DgnAttachment::GetScaleMode, &DgnAttachment::SetScaleMode);
    c2.def("GetScaleMode", &DgnAttachment::GetScaleMode, DOC(Bentley, DgnPlatform, DgnAttachment, GetScaleMode));
    c2.def("SetScaleMode", &DgnAttachment::SetScaleMode, "mode"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetScaleMode));
    
    c2.def_property("StoredScale", &DgnAttachment::GetStoredScale, &DgnAttachment::SetStoredScale);
    c2.def("GetStoredScale", &DgnAttachment::GetStoredScale, DOC(Bentley, DgnPlatform, DgnAttachment, GetStoredScale));
    c2.def("SetStoredScale", &DgnAttachment::SetStoredScale, "scale"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetStoredScale));
    
    c2.def_property("LocateLocked", &DgnAttachment::IsLocateLocked, &DgnAttachment::SetLocateLock);
    c2.def("IsLocateLocked", &DgnAttachment::IsLocateLocked, DOC(Bentley, DgnPlatform, DgnAttachment, IsLocateLocked));
    c2.def("SetLocateLock", &DgnAttachment::SetLocateLock, "lock"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetLocateLock));
    
    c2.def_property("SnapLocked", &DgnAttachment::IsSnapLocked, &DgnAttachment::SetSnapLock);
    c2.def("IsSnapLocked", &DgnAttachment::IsSnapLocked, DOC(Bentley, DgnPlatform, DgnAttachment, IsSnapLocked));
    c2.def("SetSnapLock", &DgnAttachment::SetSnapLock, "lock"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetSnapLock));

    c2.def_property_readonly("DisplayScale", &DgnAttachment::GetDisplayScale);
    c2.def("GetDisplayScale", &DgnAttachment::GetDisplayScale, DOC(Bentley, DgnPlatform, DgnAttachment, GetDisplayScale));

    c2.def_property_readonly("LocateStatus", &DgnAttachment::GetLocateStatus);
    c2.def("GetLocateStatus", &DgnAttachment::GetLocateStatus, DOC(Bentley, DgnPlatform, DgnAttachment, GetLocateStatus));

    c2.def("SetIsDisplayed", &DgnAttachment::SetIsDisplayed, "state"_a, "loadIfNecessary"_a = true, "processAffected"_a = true, DOC(Bentley, DgnPlatform, DgnAttachment, SetIsDisplayed));
    c2.def("IsDisplayed", &DgnAttachment::IsDisplayed, DOC(Bentley, DgnPlatform, DgnAttachment, IsDisplayed));

    c2.def_property("DgnAttachmentLevel", &DgnAttachment::GetDgnAttachmentLevel, &DgnAttachment::SetDgnAttachmentLevel);
    c2.def("GetDgnAttachmentLevel", &DgnAttachment::GetDgnAttachmentLevel, DOC(Bentley, DgnPlatform, DgnAttachment, GetDgnAttachmentLevel));
    c2.def("SetDgnAttachmentLevel", &DgnAttachment::SetDgnAttachmentLevel, "levelId"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetDgnAttachmentLevel));
    
    c2.def_property("LevelControlDisplay", &DgnAttachment::DoesLevelControlDisplay, &DgnAttachment::SetLevelControlsDisplay);
    c2.def("DoesLevelControlDisplay", &DgnAttachment::DoesLevelControlDisplay, DOC(Bentley, DgnPlatform, DgnAttachment, DoesLevelControlDisplay));
    c2.def("SetLevelControlDisplay", &DgnAttachment::SetLevelControlsDisplay, "display"_a);
    
    c2.def_property("ApplicationLocked", &DgnAttachment::IsApplicationLocked, &DgnAttachment::SetApplicationLocked);
    c2.def("IsApplicationLocked", &DgnAttachment::IsApplicationLocked, DOC(Bentley, DgnPlatform, DgnAttachment, IsApplicationLocked));
    c2.def("SetApplicationLocked", &DgnAttachment::SetApplicationLocked, "locked"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetApplicationLocked));

    c2.def_property("NestDepth", &DgnAttachment::GetNestDepth, &DgnAttachment::SetNestDepth);
    c2.def("GetNestDepth", &DgnAttachment::GetNestDepth, DOC(Bentley, DgnPlatform, DgnAttachment, GetNestDepth));
    c2.def("SetNestDepth", &DgnAttachment::SetNestDepth, "depth"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetNestDepth));

    c2.def("SetTransparency", &DgnAttachment::SetTransparency, "value"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetTransparency));

    c2.def_property("DoNotDisplayAsNested", &DgnAttachment::GetDoNotDisplayAsNested, &DgnAttachment::SetDoNotDisplayAsNested);
    c2.def("GetDoNotDisplayAsNested", &DgnAttachment::GetDoNotDisplayAsNested, DOC(Bentley, DgnPlatform, DgnAttachment, GetDoNotDisplayAsNested));
    c2.def("SetDoNotDisplayAsNested", &DgnAttachment::SetDoNotDisplayAsNested, "display"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetDoNotDisplayAsNested));

    c2.def("IsInSS", &DgnAttachment::IsInSS, DOC(Bentley, DgnPlatform, DgnAttachment, IsInSS));
    c2.def("IsHighlighted", &DgnAttachment::IsHighlighted, "checkParents"_a = true, DOC(Bentley, DgnPlatform, DgnAttachment, IsHighlighted));
    c2.def("IsClipped", &DgnAttachment::IsClipped, DOC(Bentley, DgnPlatform, DgnAttachment, IsClipped));
    c2.def("GetClipBoundaries", &DgnAttachment::GetClipBoundaries, "clip"_a, "vp"_a, "relativeToImmediateParent"_a, "onlyMasksIfClipElement"_a, DOC(Bentley, DgnPlatform, DgnAttachment, GetClipBoundaries));

    c2.def_property("ClipElementId", &DgnAttachment::GetClipElementId, &DgnAttachment::SetClipElementId);
    c2.def("GetClipElementId", &DgnAttachment::GetClipElementId, DOC(Bentley, DgnPlatform, DgnAttachment, GetClipElementId));
    c2.def("SetClipElementId", &DgnAttachment::SetClipElementId, "clipElement"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetClipElementId));

    c2.def("ClearClipElementId", &DgnAttachment::ClearClipElementId, DOC(Bentley, DgnPlatform, DgnAttachment, ClearClipElementId));
    
    c2.def_property_readonly("ClipPointCount", &DgnAttachment::GetClipPointCount);
    c2.def("GetClipPointCount", &DgnAttachment::GetClipPointCount, DOC(Bentley, DgnPlatform, DgnAttachment, GetClipPointCount));
    
    c2.def("GetClipPoints", &DgnAttachment::GetClipPoints, "clipPoints"_a, DOC(Bentley, DgnPlatform, DgnAttachment, GetClipPoints));
    c2.def("SetClipPoints", &DgnAttachment::SetClipPoints, "points"_a, "numPoints"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetClipPoints));
    
    c2.def("SetClipBoundFromViewPoints",
           &DgnAttachment::SetClipBoundFromViewPoints,
           "points"_a, "numPoints"_a, "viewRotMatrix"_a, "viewOrigin"_a, "viewActiveZ"_a, "discardClipMasks"_a);

    c2.def("AppendClipVoidPoints", &DgnAttachment::AppendClipVoidPoints, "points"_a, "numPoints"_a, "viewRotMatrix"_a, DOC(Bentley, DgnPlatform, DgnAttachment, AppendClipVoidPoints));

    c2.def("HasBackClip", &DgnAttachment::HasBackClip, DOC(Bentley, DgnPlatform, DgnAttachment, HasBackClip));
    c2.def("HasFrontClip", &DgnAttachment::HasFrontClip, DOC(Bentley, DgnPlatform, DgnAttachment, HasFrontClip));
    
    c2.def_property("FrontClipDepth", &DgnAttachment::GetFrontClipDepth, &DgnAttachment::SetFrontClipDepth);
    c2.def("GetFrontClipDepth", &DgnAttachment::GetFrontClipDepth, DOC(Bentley, DgnPlatform, DgnAttachment, GetFrontClipDepth));
    c2.def("SetFrontClipDepth", &DgnAttachment::SetFrontClipDepth, "clipDepth"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetFrontClipDepth));
    
    c2.def_property("BackClipDepth", &DgnAttachment::GetBackClipDepth, &DgnAttachment::SetBackClipDepth);
    c2.def("GetBackClipDepth", &DgnAttachment::GetBackClipDepth, DOC(Bentley, DgnPlatform, DgnAttachment, GetBackClipDepth));
    c2.def("SetBackClipDepth", &DgnAttachment::SetBackClipDepth, "clipDepth"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetBackClipDepth));
    
    c2.def_property("ClipRotMatrix", &DgnAttachment::GetClipRotMatrix, &DgnAttachment::SetClipRotMatrix);
    c2.def("GetClipRotMatrix", &DgnAttachment::GetClipRotMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetClipRotMatrix));
    c2.def("SetClipRotMatrix", &DgnAttachment::SetClipRotMatrix, "rotation"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetClipRotMatrix));
    
    c2.def_property("RotateClipping", &DgnAttachment::IsRotateClipping, &DgnAttachment::SetRotateClipping);
    c2.def("IsRotateClipping", &DgnAttachment::IsRotateClipping, DOC(Bentley, DgnPlatform, DgnAttachment, IsRotateClipping));
    c2.def("SetRotateClipping", &DgnAttachment::SetRotateClipping, "yesNo"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetRotateClipping));
    
    c2.def_property("SynchWithNamedView", &DgnAttachment::GetSynchWithNamedView, &DgnAttachment::SetSynchWithNamedView);
    c2.def("GetSynchWithNamedView", &DgnAttachment::GetSynchWithNamedView, DOC(Bentley, DgnPlatform, DgnAttachment, GetSynchWithNamedView));
    c2.def("SetSynchWithNamedView", &DgnAttachment::SetSynchWithNamedView, "options"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetSynchWithNamedView));
    
    c2.def_property("LogicalName", &DgnAttachment::GetLogicalName, &DgnAttachment::SetLogicalName);
    c2.def("GetLogicalName", &DgnAttachment::GetLogicalName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetLogicalName));
    c2.def("SetLogicalName", &DgnAttachment::SetLogicalName, "name"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetLogicalName));
    
    c2.def("SetUniqueLogical", &DgnAttachment::SetUniqueLogical, DOC(Bentley, DgnPlatform, DgnAttachment, SetUniqueLogical));
    
    c2.def_property("AttachDescription", &DgnAttachment::GetAttachDescription, &DgnAttachment::SetAttachDescription);
    c2.def("GetAttachDescription", &DgnAttachment::GetAttachDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachment, GetAttachDescription));
    c2.def("SetAttachDescription", &DgnAttachment::SetAttachDescription, "description"_a, DOC(Bentley, DgnPlatform, DgnAttachment, SetAttachDescription));

    c2.def("ApplyNamedView", 
           &DgnAttachment::ApplyNamedView, 
           "viewName"_a, "userScale"_a, "acsScale"_a = 1.0, "clipOptions"_a = DgnAttachment::ApplyViewClipOptions(), "getModelFromView"_a = true, "auxRotation"_a = StandardView::NotStandard);

    c2.def("ApplyStandardView", &DgnAttachment::ApplyStandardView, "stdView"_a, "userScale"_a, "acsScale"_a = 1.0, DOC(Bentley, DgnPlatform, DgnAttachment, ApplyStandardView));
    
    c2.def_property_readonly("NamedView", &DgnAttachment::GetNamedView);    
    c2.def("GetNamedView", &DgnAttachment::GetNamedView, DOC(Bentley, DgnPlatform, DgnAttachment, GetNamedView));    
    }