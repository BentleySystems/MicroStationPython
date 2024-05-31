/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\viewgroup.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ViewGroup.h>



static const char * __doc_Bentley_DgnPlatform_ViewGroup_FindFirstOpenView =R"doc(Return the index of the first open view in this viewgroup.


Returns (Tuple, 0):
    VG_Success if an open view was found and returned in viewNumber,
    or VG_OpenViewNotFound if no open view could be found.

Returns (Tuple, 1):
	viewNumber. The index of the first open view

)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_FindActiveViewGroup =R"doc(Find the active ViewGroup in *dgnFile.*


Parameter ``dgnFile``:
    The file to read

Returns (Tuple, 0):
    VG_Success if a viewgroup was found, created, and returned in
    activeViewGroup, or VG_ViewGroupNotFound if no viewgroup could be
    found

Returns (Tuple,1):
	activeViewGroup.  The active viewgroup

)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_Copy =R"doc(Creates a new instance of ViewGroup by attempting to find an existing
ViewGroup that references the designated source model.


Parameter ``rootModel``:
    The Root Model for every view in the new viewGroup.

Parameter ``sourceModel``:
    The Root Model for which to attempt to find an existing ViewGroup.

Parameter ``copyOptions``:
    Specifies certain copy behaviors. See ViewGroupCopyOptions

Remark:
    s If there is no ViewGroup for which every view has rootModel as
    its Root Model, uses #Create to create a new Named View.

Remark:
    s If a ViewGroup is created, it is transient only if
    copyOptions.m_copyType is ViewGroupCopyTypeOption::MakeTransient.

Remark:
    s If there are multiple eligible ViewGroups in the DgnFile of
    sourceModel, uses the ViewGroup that was active at the last " Save Settings " if that ViewGroup matches, otherwise the most recently
    modified matching ViewGroup.
    
Returns(Tuple, 0):
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.

Returns (Tuple, 1):
	copiedViewGroup.   The ViewGroup that was instantiated.


)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_Create =R"doc(Creates a new instance of ViewGroup


Parameter ``rootModel``:
    The model that becomes the Root Model of all views in the
    ViewGroup.

Parameter ``transient``:
    True to create a temporary ViewGroup that is not saved to the
    DgnFile.

Parameter ``name``:
    The ViewGroup name. If name is NULL, generates a new unique name.

Parameter ``addToCollection``:
    If true, the ViewGroup is added to the ViewGroupCollection
    associated with the DgnFile.

Remark:
    s If transient is false and AddToCollection is true, the ViewGroup
    will be persisted to the DgnFile when
    ViewGroupCollection::SaveChanges is called.
    
Returns(Tuple, 0):
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.

Returns (Tuple, 1):
	createdViewGroup.  The ViewGroup that was instantiated.


)doc";


static const char * __doc_Bentley_DgnPlatform_ViewGroup_From =R"doc(Copies the contents of the source ViewGroup to this ViewGroup.

Parameter ``source``:
    The source ViewGroup.

Parameter ``copyOptions``:
    Specifies certain copy behaviors. See ViewGroupCopyOptions)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetActiveStyle =R"doc(Sets the active line style associated with this view group.

Parameter ``activeStyle``:
    The active style.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetActiveStyle =R"doc(Gets the active line style associated with this view group.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetActiveWeight =R"doc(Sets the active line weight associated with this view group.

Parameter ``activeWeight``:
    The active weight.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetActiveWeight =R"doc(Gets the active line weight associated with this view group.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetActiveColor =R"doc(Sets the active color associated with this view group.

Parameter ``activeColor``:
    The active color.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetActiveColor =R"doc(Gets the active color associated with this view group.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetActiveLevel =R"doc(Sets the active level associated with this view group.

Parameter ``activeLevel``:
    The active level.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetActiveLevel =R"doc(Gets the active level associated with this view group.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_AllViewsOneModel =R"doc(Returns true if all views reference the same Root Model


    
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	onlyModel.  If the method returns true, onlyModel is set to the modelID of the
    Root Model shared by all views.

)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_WriteImmediatelyToFile =R"doc(Write this ViewGroup immediately to the DgnFile.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SaveChanges =R"doc(Save the changes to this ViewGroup persistently to the DgnFile.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_ResetEffectiveLevelMasksForChildren =R"doc(Direct that effective level display mask for all descendants of the
indicated model, but not the model itself.

Parameter ``modelRef``:
    The model whose descendant effectiveLevelMaks should be
    recalculated.

Remark:
    s The effective level mask reveals what levels are to be
    displayed, considering the per-view level display mask and the
    on/off and frozen state of the levels. This method directs that
    the effective level masks for descendants of the indicated
    modelRef be recalculated.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_ResetEffectiveLevelMasksForModel =R"doc(Direct that effective level display mask for the indicated model and,
optionally, its descendants be recalculated for every view.

Parameter ``modelRef``:
    The model at which to start the traversal.

Parameter ``includeChildModelRefs``:
    If true, traverse all child modelRefs.

Remark:
    s The effective level mask reveals what levels are to be
    displayed, considering the per-view level display mask and the
    on/off and frozen state of the levels. This method directs that
    the effective level masks for the modelRef and all descendants be
    recalculated.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_ResetEffectiveLevelMasks =R"doc(Direct that effective level display mask for every model in every view
be recalculated.

Remark:
    s The effective level mask reveals what levels are to be
    displayed, comsidering the per-view level display mask and the
    on/off and frozen state of the levels. This method directs that
    all of these level masks be recalculated.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_EnsureLevelMaskCoverage =R"doc(Traverse the modelRef and its descendants, and make sure that there is
a per-view level display mask for each in every view.

Parameter ``modelRef``:
    The model at which to start the traversal.

Parameter ``fromExchange``:
    If true, do not revert to level masks stored in reference, even if
    the refernce has REF_NESTOVERRIDES_NEVER set.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SynchViewDisplay =R"doc(Tells the host to synchronize the displayed view with the state stored
in this ViewGroup

Parameter ``viewNumber``:
    The view to synchronize.

Parameter ``levelsChanged``:
    Informs the host that the per-view level display has been
    manipulated.

Parameter ``undoable``:
    Informs the host that the manipulation should be treated as
    undoable.

Parameter ``synchViewTitle``:
    Informs the host that the view title may need to be updated.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_MatchesModel =R"doc(Returns true if this ViewGroup matches the indicated Model.

Parameter ``modelID``:
    The model for which to test.

Parameter ``allViewsMatch``:
    If true, returns true only if the root model of all views matches
    modelID.

Parameter ``thisViewMatches``:
    If between 0 and MAX_VIEWS-1, inclusive, returns true if that view
    has modelID as its root Model. Otherwise, returns true if the
    first view that is on matches modelID.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetViewPortInfo =R"doc(Sets the ViewPortInfo for the indicated view.

Parameter ``viewPortInfo``:
    The ViewPortInfo to set.

Parameter ``viewNumber``:
    The view for which the ViewPortInfo is set)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetViewInfo =R"doc(Sets the ViewInfo for the indicated view, copy of viewInfo will be
made and then copied one will be set at the viewNumber index in
viewGroup. It is not taking ownership of viewInfo.

Parameter ``viewInfo``:
    The ViewInfo to set.

Parameter ``viewNumber``:
    The view for which the ViewInfo is set.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetViewPortInfo =R"doc(Gets a const reference to the ViewPortInfo for the indicated view.

Parameter ``viewNumber``:
    The view for which the ViewPortInfo is requested)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetViewInfo =R"doc(Gets a const reference to the ViewInfo for the indicated view.

Parameter ``viewNumber``:
    The view for which the ViewInfo is requested)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetTransient =R"doc(Sets this ViewGroup's transient status

Parameter ``transient``:
    True if the ViewGroup should be treated as transient.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_IsTransient =R"doc(Returns true if this ViewGroup was created temporarily and will not be
persisted in the DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetElementRef =R"doc(Gets the ElementRefP of the persistent storage of this ViewGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetElementId =R"doc(Gets the ElementId of the persistent storage of this ViewGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetUIDisplayOrder =R"doc(Sets the User Interface display order value for this ViewGroup

Parameter ``value``:
    The new UI display order value.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetUIDisplayOrder =R"doc(Gets an integer representing the desired User Interface display order
of this ViewGroup.

Remark:
    s In the user interface, ViewGroups are sorted by their
    UIDisplayOrder.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetDescription =R"doc(Sets the description of this ViewGroup

Parameter ``description``:
    The new description for this ViewGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetDescription =R"doc(Gets the description of this ViewGroup)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_SetName =R"doc(Sets the Name of this ViewGroup

Parameter ``name``:
    The new name for this ViewGroup.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroup_GetName =R"doc(Gets the name of this ViewGroup)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_SetNewDescription =R"doc(The new description for the copied ViewGroup. If not specified, copies
description from source.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_SetNewName =R"doc(The new named for the copied ViewGroup. If not specified, generates a
unique name.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_SetDoNotAddToCollection =R"doc(Do not add the view to the ViewGroupCollection)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_SetCopyViewLevels =R"doc(Copy the view levels.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_SetCopyViewClip =R"doc(Copy the view Clipping.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_SetCopyType =R"doc(Determines whether the output is a transient ViewGroup or not.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCopyOptions_Duplicate =R"doc(Copy an existing options object.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_GetUniqueNameFromBase =R"doc(Gets a unique name for a ViewGroup given a " base " name.

Parameter ``uniqueName``:
    The generated uniqueName.

Parameter ``baseName``:
    The base name. If NULL, the name of the model (decorated with
    " transient " if transient is true) is used as the base name.

Parameter ``model``:
    The model. Used only to get the base name if the baseName argument
    is NULL.

Parameter ``transient``:
    True if the name should be generated for a transient ViewGroup.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_MakeActive =R"doc(Attempt to make the indicated ViewGroup the active ViewGroup.

Parameter ``newActive``:
    The ViewGroup which is to be made active.

Parameter ``deferInitialUpdate``:
    Passed to the host application to indicate that the initial update
    of the Views associated with the ViewGroup should be deferred.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.

Remark:
    s The host's
    DgnPlatformLib::Host:ViewStateAdmin::_OnViewGroupBeforeMakeActive
    method is called, and that method can reject the attempt to make
    the ViewGroup active. If the ViewGroup is accepted, it is saved as
    the Active ViewGroup (see #GetActiveCP) and the host's
    DgnPlatformLib::Host::ViewStateAdmin::_OnViewGroupMadeActive
    method is called.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_FindLastModifiedMatchingModel =R"doc(Finds a ViewGroup by the ModelId of the Root Model of its view(s).

Parameter ``preferredElementID``:
    The ElementId of a ViewGroup that tested first, and if it matches,
    is preferentially returned.

Parameter ``modelID``:
    The ModelId to search for.

Parameter ``allViewsMatch``:
    If true, every view must have modelID as the Root Model, and
    thisViewMatches is ignored.

Parameter ``thisViewMatches``:
    If between 0 and MAX_VIEWS-1, inclusive, returns a viewgroup for
    which that view has modelID as its root Model. Otherwise, returns
    a viewgroup for which the first view that is on matches modelID.

Returns:
    The ViewGroupPtr that references the ViewGroup with the given name
    or NULL.

Remark:
    s If there are multiple ViewGroups that qualify as matches (but
    the ViewGroup corresponding to preferredElementID does not), the
    method returns the ViewGroup that was most recently modified.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_Delete =R"doc(Deletes the designated ViewGroup from this ViewGroupCollection.

Parameter ``viewGroup``:
    The ViewGroup to delete.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.

Remark:
    s If the ViewGroup is not transient, its persistent representation
    is immediately deleted from the DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_Add =R"doc(Adds the designated ViewGroup to this ViewGroupCollection.

Parameter ``viewGroup``:
    The ViewGroup to add.

Returns:
    VG_Success, or one of the ViewGroupStatus values if there is an
    error.

Remark:
    s If the ViewGroup is not transient, the ViewGroup will be
    persisted to the DgnFile when ViewGroupCollection::SaveChanges is
    called.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_NameUnused =R"doc(Returns true if the name tested is unique within this
ViewGroupCollection.

Parameter ``name``:
    The name to test)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_SaveChanges =R"doc(Save the changes to all the ViewGroups in the collection to the
DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_FindByModelId =R"doc(Finds a ViewGroup by the ModelId of the Root Model of its view(s).

Parameter ``modelID``:
    The ModelId to search for.

Parameter ``allViewsMatch``:
    If true, every view must have modelID as the Root Model, and the
    thisViewMatches argument is ignored.

Parameter ``thisViewMatches``:
    If between 0 and MAX_VIEWS-1, inclusive, returns true if that view
    has modelID as its root Model. Otherwise, returns true if the
    first view that is on matches modelID.

Returns:
    The ViewGroupPtr that references the ViewGroup with the given name
    or NULL.

Remark:
    s If there are multiple ViewGroups that qualify as matches, the
    method returns the ViewGroup that was active at the last " Save Settings " if that matches, otherwise the most recently modified
    matching ViewGroup.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_FindByElementId =R"doc(Finds a ViewGroup by the ElementId of the element that stores the
ViewGroup.

Parameter ``elementID``:
    The elementID of the ViewGroup to search for.

Returns:
    The ViewGroupPtr that references the ViewGroup with the given name
    or NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_ViewGroupCollection_FindByName =R"doc(Finds a ViewGroup by name.

Parameter ``name``:
    The name of the ViewGroup to search for.

Returns:
    The ViewGroupPtr that references the ViewGroup with the given name
    or NULL.

Remark:
    s The comparison is case-insensitive.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ViewGroup(py::module_& m)
    {
    //===================================================================================
    // enum ViewGroupStatus
    py::enum_< ViewGroupStatus>(m, "ViewGroupStatus", py::arithmetic())
        .value("eVG_Success", VG_Success)
        .value("eVG_NameTooShort", VG_NameTooShort)
        .value("eVG_NameTooLong", VG_NameTooLong)
        .value("eVG_NameNotUnique", VG_NameNotUnique)
        .value("eVG_NameIllegalCharacter", VG_NameIllegalCharacter)
        .value("eVG_OwningDgnFileUnknown", VG_OwningDgnFileUnknown)
        .value("eVG_WrongFile", VG_WrongFile)
        .value("eVG_CantCreateElement", VG_CantCreateElement)
        .value("eVG_CantWriteToFile", VG_CantWriteToFile)
        .value("eVG_TransientNotSaved", VG_TransientNotSaved)
        .value("eVG_CantDeleteFromFile", VG_CantDeleteFromFile)
        .value("eVG_NotInCollection", VG_NotInCollection)
        .value("eVG_ActivateRejected", VG_ActivateRejected)
        .value("eVG_NoReplacementActiveFound", VG_NoReplacementActiveFound)
        .value("eVG_CantSetElementId", VG_CantSetElementId)
        .value("eVG_BadArgument", VG_BadArgument)
        .value("eVG_ViewGroupNotFound", VG_ViewGroupNotFound)
        .value("eVG_OpenViewNotFound", VG_OpenViewNotFound)
        .export_values();

    //===================================================================================
    // enum ViewGroupCopyTypeOption
    py::enum_< ViewGroupCopyTypeOption>(m, "ViewGroupCopyTypeOption")
        .value("eSourceType", ViewGroupCopyTypeOption::SourceType)
        .value("eMakeTransient", ViewGroupCopyTypeOption::MakeTransient)
        .value("eMakePermanent", ViewGroupCopyTypeOption::MakePermanent)
        .export_values();

    //===================================================================================
    // struct ViewGroupCollection
    py::class_< ViewGroupCollection, std::unique_ptr<ViewGroupCollection, py::nodelete> > c1(m, "ViewGroupCollection");

    c1.def("__iter__", [] (ViewGroupCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c1.def("FindByName", &ViewGroupCollection::FindByName, "name"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, FindByName));
    c1.def("FindByElementId", &ViewGroupCollection::FindByElementId, "elemId"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, FindByElementId));
    c1.def("FindByModelId", &ViewGroupCollection::FindByModelId, "modelId"_a, "allViewMatch"_a, "thisViewMatches"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, FindByModelId));

    c1.def("SaveChanges", &ViewGroupCollection::SaveChanges, DOC(Bentley, DgnPlatform, ViewGroupCollection, SaveChanges));
    c1.def("NameUnused", &ViewGroupCollection::NameUnused, "name"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, NameUnused));
    
    c1.def_property_readonly("Size", &ViewGroupCollection::Size);
    c1.def("__len__", &ViewGroupCollection::Size);
    
    c1.def("Add", py::overload_cast<ViewGroupP>(&ViewGroupCollection::Add), "viewGroup"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, Add));
    c1.def("Delete", &ViewGroupCollection::Delete, "viewGroup"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, Delete));
    c1.def("FindLastModifiedMatchingModel", &ViewGroupCollection::FindLastModifiedMatchingModel, "preferredElementId"_a, "modelId"_a, "allViewMatch"_a, "thisViewMatches"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, FindLastModifiedMatchingModel));
    
    c1.def_property_readonly("ActiveViewGroup", &ViewGroupCollection::GetActiveP);
    c1.def("GetActive", &ViewGroupCollection::GetActiveP, py::return_value_policy::reference_internal);
    
    c1.def("MakeActive", &ViewGroupCollection::MakeActive, "newActive"_a, "deferInitialUpdate"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, MakeActive));
    c1.def("GetActiveViewInfo", &ViewGroupCollection::GetActiveViewInfoP, "viewNumber"_a, py::return_value_policy::reference_internal);
    c1.def("GetActiveViewPortInfo", &ViewGroupCollection::GetActiveViewPortInfoP, "viewNumber"_a, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("DgnFile", &ViewGroupCollection::GetDgnFileP);
    c1.def("GetDgnFile", &ViewGroupCollection::GetDgnFileP, py::return_value_policy::reference_internal);
    
    c1.def("GetUniqueNameFromBase", &ViewGroupCollection::GetUniqueNameFromBase, "uniqueName"_a, "baseName"_a, "dgnModel"_a, "transient"_a, DOC(Bentley, DgnPlatform, ViewGroupCollection, GetUniqueNameFromBase));

    //===================================================================================
    // struct ViewGroupCopyOptions
    py::class_< ViewGroupCopyOptions, ViewGroupCopyOptionsPtr> c2(m, "ViewGroupCopyOptions");

    c2.def(py::init(&ViewGroupCopyOptions::CreateOptions));
    //c2.def_static("Duplicate", &ViewGroupCopyOptions::Duplicate, "seedOptions"_a, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, Duplicate));
    c2.def("SetCopyType", &ViewGroupCopyOptions::SetCopyType, "options"_a, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, SetCopyType));
    c2.def("SetCopyViewClip", &ViewGroupCopyOptions::SetCopyViewClip, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, SetCopyViewClip));
    c2.def("SetCopyViewLevels", &ViewGroupCopyOptions::SetCopyViewLevels, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, SetCopyViewLevels));
    c2.def("SetCopyViewACSSetCopyViewACS", &ViewGroupCopyOptions::SetCopyViewACS);
    c2.def("SetDoNotAddToCollection", &ViewGroupCopyOptions::SetDoNotAddToCollection, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, SetDoNotAddToCollection));
    c2.def("SetNewName", &ViewGroupCopyOptions::SetNewName, "name"_a, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, SetNewName));
    c2.def("SetNewDescription", &ViewGroupCopyOptions::SetNewDescription, "descr"_a, DOC(Bentley, DgnPlatform, ViewGroupCopyOptions, SetNewDescription));

    //===================================================================================
    // struct ViewGroup
    py::class_< ViewGroup, ViewGroupPtr> c3(m, "ViewGroup", py::multiple_inheritance());

    c3.def_property("Name", &ViewGroup::GetName, py::overload_cast<WCharCP>(&ViewGroup::SetName));
    c3.def("GetName", &ViewGroup::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewGroup, GetName));
    c3.def("SetName", py::overload_cast<WCharCP>(&ViewGroup::SetName), "name"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetName));
    
    c3.def_property("Description", &ViewGroup::GetDescription, &ViewGroup::SetDescription);
    c3.def("GetDescription", &ViewGroup::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewGroup, GetDescription));
    c3.def("SetDescription", &ViewGroup::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetDescription));
    
    c3.def_property("UIDisplayOrder", &ViewGroup::GetUIDisplayOrder, &ViewGroup::SetUIDisplayOrder);
    c3.def("GetUIDisplayOrder", &ViewGroup::GetUIDisplayOrder, DOC(Bentley, DgnPlatform, ViewGroup, GetUIDisplayOrder));
    c3.def("SetUIDisplayOrder", &ViewGroup::SetUIDisplayOrder, "order"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetUIDisplayOrder));
    
    c3.def_property_readonly("ElementId", &ViewGroup::GetElementId);
    c3.def("GetElementId", &ViewGroup::GetElementId, DOC(Bentley, DgnPlatform, ViewGroup, GetElementId));
    
    c3.def_property_readonly("ElementRef", &ViewGroup::GetElementRef);
    c3.def("GetElementRef", &ViewGroup::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewGroup, GetElementRef));
    
    c3.def_property_readonly("DgnFile", &ViewGroup::GetDgnFileP);
    c3.def("GetDgnFile", &ViewGroup::GetDgnFileP, py::return_value_policy::reference_internal);
    
    c3.def_property("Transient", &ViewGroup::IsTransient, &ViewGroup::SetTransient);
    c3.def("IsTransient", &ViewGroup::IsTransient, DOC(Bentley, DgnPlatform, ViewGroup, IsTransient));
    c3.def("SetTransient", &ViewGroup::SetTransient, "transient"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetTransient));
    
    c3.def("GetViewInfo", &ViewGroup::GetViewInfoR, "viewNumber"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewGroup, GetViewInfo));
    c3.def("GetViewPortInfo", &ViewGroup::GetViewPortInfoR, "viewNumber"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ViewGroup, GetViewPortInfo));
    c3.def("SetViewInfo", &ViewGroup::SetViewInfo, "viewInfo"_a, "viewNumber"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetViewInfo));
    c3.def("SetViewPortInfo", &ViewGroup::SetViewPortInfo, "viewPortInfo"_a, "viewNumber"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetViewPortInfo));
    c3.def("MatchesModel", &ViewGroup::MatchesModel, "modelId"_a, "allViewsMatch"_a, "thisViewMatches"_a, DOC(Bentley, DgnPlatform, ViewGroup, MatchesModel));
    c3.def("SynchViewDisplay", &ViewGroup::SynchViewDisplay, "viewNumber"_a, "levelsChanges"_a, "undoable"_a, "synchViewTitle"_a, DOC(Bentley, DgnPlatform, ViewGroup, SynchViewDisplay));
    c3.def("EnsureLevelMaskCoverage", &ViewGroup::EnsureLevelMaskCoverage, "modelRef"_a, "fromExchange"_a, DOC(Bentley, DgnPlatform, ViewGroup, EnsureLevelMaskCoverage));
    c3.def("ResetEffectiveLevelMasks", &ViewGroup::ResetEffectiveLevelMasks, DOC(Bentley, DgnPlatform, ViewGroup, ResetEffectiveLevelMasks));
    c3.def("ResetEffectiveLevelMasksForModel", &ViewGroup::ResetEffectiveLevelMasksForModel, "modelRef"_a, "includeChildModelRefs"_a, DOC(Bentley, DgnPlatform, ViewGroup, ResetEffectiveLevelMasksForModel));
    c3.def("ResetEffectiveLevelMasksForChildren", &ViewGroup::ResetEffectiveLevelMasksForChildren, "modelRef"_a, DOC(Bentley, DgnPlatform, ViewGroup, ResetEffectiveLevelMasksForChildren));

    c3.def("SaveChanges", &ViewGroup::SaveChanges, DOC(Bentley, DgnPlatform, ViewGroup, SaveChanges));
    c3.def("WriteImmediatelyToFile", &ViewGroup::WriteImmediatelyToFile, DOC(Bentley, DgnPlatform, ViewGroup, WriteImmediatelyToFile));
    
    c3.def_property_readonly("FirstRootModel", &ViewGroup::GetFirstRootModelP);
    c3.def("GetFirstRootModel", &ViewGroup::GetFirstRootModelP, py::return_value_policy::reference_internal);

    c3.def("GetZOrder", [] (ViewGroup const& self, UInt8Array& zOrder) { self.GetZOrder(zOrder.data(), zOrder.size()); }, "zOrder"_a);
    c3.def("SetZOrder", [] (ViewGroup& self, UInt8Array& zOrder) { self.SetZOrder(zOrder.data(), zOrder.size()); }, "zOrder"_a);
    
    c3.def("AllViewsOneModel", [] (ViewGroup const& self)
           {
           ModelId onlyModel = INVALID_MODELID;
           auto retVal = self.AllViewsOneModel(onlyModel);
           return py::make_tuple(retVal, onlyModel);
           }, DOC(Bentley, DgnPlatform, ViewGroup, AllViewsOneModel));

    c3.def_property("ActiveLevel", &ViewGroup::GetActiveLevel, &ViewGroup::SetActiveLevel);
    c3.def("GetActiveLevel", &ViewGroup::GetActiveLevel, DOC(Bentley, DgnPlatform, ViewGroup, GetActiveLevel));
    c3.def("SetActiveLevel", &ViewGroup::SetActiveLevel, "levelId"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetActiveLevel));
    
    c3.def_property("ActiveColor", &ViewGroup::GetActiveColor, &ViewGroup::SetActiveColor);
    c3.def("GetActiveColor", &ViewGroup::GetActiveColor, DOC(Bentley, DgnPlatform, ViewGroup, GetActiveColor));
    c3.def("SetActiveColor", &ViewGroup::SetActiveColor, "color"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetActiveColor));
    
    c3.def_property("ActiveWeight", &ViewGroup::GetActiveWeight, &ViewGroup::SetActiveWeight);
    c3.def("GetActiveWeight", &ViewGroup::GetActiveWeight, DOC(Bentley, DgnPlatform, ViewGroup, GetActiveWeight));
    c3.def("SetActiveWeight", &ViewGroup::SetActiveWeight, "weight"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetActiveWeight));
    
    c3.def_property("ActiveStyle", &ViewGroup::GetActiveStyle, &ViewGroup::SetActiveStyle);
    c3.def("GetActiveStyle", &ViewGroup::GetActiveStyle, DOC(Bentley, DgnPlatform, ViewGroup, GetActiveStyle));
    c3.def("SetActiveStyle", &ViewGroup::SetActiveStyle, "style"_a, DOC(Bentley, DgnPlatform, ViewGroup, SetActiveStyle));

    c3.def("From", &ViewGroup::From, "source"_a, "copyOptions"_a, DOC(Bentley, DgnPlatform, ViewGroup, From));

    c3.def_static("Create", [] (DgnModelR rootModel, bool transient, WCharCP name, bool addToCollection)
                  {
                  ViewGroupPtr createdViewGroup;
                  auto retVal = ViewGroup::Create(createdViewGroup, rootModel, transient, name, addToCollection);
                  return py::make_tuple(retVal, createdViewGroup);
                  }, "rootModel"_a, "transient"_a, "name"_a, "addToCollection"_a, DOC(Bentley, DgnPlatform, ViewGroup, Create));

    c3.def_static("Create", [] (ModelId rootModelId, DgnFileR dgnFile, bool transient, WCharCP name, bool addToCollection)
                  {
                  ViewGroupPtr createdViewGroup;
                  auto retVal = ViewGroup::Create(createdViewGroup, rootModelId, dgnFile, transient, name, addToCollection);
                  return py::make_tuple(retVal, createdViewGroup);
                  }, "rootModelId"_a, "dgnFile"_a, "transient"_a, "name"_a, "addToCollection"_a, DOC(Bentley, DgnPlatform, ViewGroup, Create));

    c3.def_static("Copy", [] (DgnModelR rootModel, DgnModelRefR sourceModel, ViewGroupCopyOptions const& copyOptions)
                  {
                  ViewGroupPtr copiedViewGroup;
                  auto retVal = ViewGroup::Copy(copiedViewGroup, rootModel, sourceModel, copyOptions);
                  return py::make_tuple(retVal, copiedViewGroup);
                  }, "rootModel"_a, "sourceModel"_a, "copyOptions"_a, DOC(Bentley, DgnPlatform, ViewGroup, Copy));

    c3.def_static("Copy", [] (DgnModelR rootModel, ViewGroupCR source, ViewGroupCopyOptions const& copyOptions)
                  {
                  ViewGroupPtr copiedViewGroup;
                  auto retVal = ViewGroup::Copy(copiedViewGroup, rootModel, source, copyOptions);
                  return py::make_tuple(retVal, copiedViewGroup);
                  }, "rootModel"_a, "source"_a, "copyOptions"_a, DOC(Bentley, DgnPlatform, ViewGroup, Copy));

    c3.def_static("FindActiveViewGroup", [] (DgnFileR dgnFile)
                  {
                  ViewGroupPtr activeViewGroup;
                  auto retVal = ViewGroup::FindActiveViewGroup(activeViewGroup, dgnFile);
                  return py::make_tuple(retVal, activeViewGroup);
                  }, "dgnFile"_a, DOC(Bentley, DgnPlatform, ViewGroup, FindActiveViewGroup));

    c3.def("FindFirstOpenView", [] (ViewGroup& self)
           {
           int viewNumber = -1;
           auto retVal = self.FindFirstOpenView(viewNumber);
           return py::make_tuple(retVal, viewNumber);
           }, DOC(Bentley, DgnPlatform, ViewGroup, FindFirstOpenView));
    }