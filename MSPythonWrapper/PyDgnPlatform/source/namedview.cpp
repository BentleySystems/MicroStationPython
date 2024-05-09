/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\namedview.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/NamedView.h>



static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_SetViewData =R"doc(Sets the NamedViewDisplayableData corresponding to a NamedView
Displayable element

Parameter ``viewData``:
    The NamedViewDisplayableData

Parameter ``displayElement``:
    The Displayable element.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_GetViewData =R"doc(Gets the NamedViewDisplayableData corresponding to a NamedView
Displayable element

Parameter ``viewData``:
    The NamedViewDisplayableData

Parameter ``displayElement``:
    The Displayable element.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_GetViewInfo =R"doc(Gets the ViewInfo corresponding to a NamedView Displayable element

Parameter ``displayElement``:
    The Displayable element.

Returns:
    The ViewInfo)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_IsNamedViewDisplayable =R"doc(Returns true if the NamedView element corresponds to a NamedView that
has a Displayable element.

Parameter ``namedViewElement``:
    The NamedView element.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_GetClipElement =R"doc(Gets the clip element corresponding to the Displayable element

Parameter ``clipElement``:
    The clip element.

Parameter ``displayElement``:
    The Displayable element.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_GetNamedViewElement =R"doc(Gets the NamedView element corresponding to the Displayable element

Parameter ``namedViewElement``:
    The NamedView element.

Parameter ``displayElement``:
    The Displayable element.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_FindElement =R"doc(Find the NamedViewDisplayable element

Parameter ``displayElement``:
    The located Displayable element.

Parameter ``namedViewElement``:
    The NamedView

Parameter ``model``:
    The DgnModel of the NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewDisplayable_CreateElement =R"doc(Creates the NamedViewDisplayable element

Parameter ``displayElement``:
    The newly created Displayable element.

Parameter ``namedViewElement``:
    The NamedView

Parameter ``model``:
    The DgnModel of the NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_IsViewMemberOfNamedGroup =R"doc(Check if a view element is member of a namedgroup. If it is, return
the namedgroup.

Parameter ``group``:
    OUT Namedgroup pointer. Pass NULL if namedgroup is not needed.

Parameter ``viewEH``:
    IN View element to check

Returns:
    true if view is member of a namedgroup

Remark:
    s Caller is responsible for freeing group by calling
    group->Release ().)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_HideAllAnnotationAttachments =R"doc(De-annotate (hide) all annotation attachments

Parameter ``hostModel``:
    IN ModelRef to look annotations into.

Parameter ``viewElemRefToSkip``:
    IN View element whose annotation attachment should not be
    deannotated (optional, can pass NULL))doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_IsAnnotationAttachmentDisplayed =R"doc(Check if annotation cross-reference of a named view is displayed in
the given model.

Parameter ``hostModel``:
    IN Model to show annotation attachment in

Parameter ``drawingIndex``:
    IN Index of drawing in the list of all links. -1 for Default
    behavior (1st drawing link, if not found then 1st reference link)

Returns:
    true if annotated cross-reference is displayed)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_HideAnnotationAttachment =R"doc(Hide the annotation cross-reference of a named view in the given
model.

Parameter ``hostModel``:
    IN Model to hide annotation attachment in

Returns:
    non-zero error status if annotated cross-reference could not be
    hidden.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_ShowAnnotationAttachment =R"doc(Show the annotation cross-reference of a named view in the given
model.

Parameter ``hostModel``:
    IN Model to show annotation attachment in

Parameter ``viewRefModel``:
    IN Reference path from named view's root model to hostModel

Parameter ``drawingIndex``:
    IN Index of drawing in the list of all links. -1 for Default
    behavior (1st drawing link, if not found then 1st reference link)

Returns:
    non-zero error status if annotated cross-reference is not
    displayed or could not be created.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_Create =R"doc(Creates a new NamedView.

Parameter ``namedView``:
    The newly created NamedView.

Parameter ``dgnFile``:
    The DgnFile the NamedView will go into.

Parameter ``name``:
    The NamedView Name.

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_Apply =R"doc(Apply a named view to the specified viewport.

Parameter ``viewport``:
    The viewport to which to apply the NamedView.

Parameter ``options``:
    The apply options.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_Compare =R"doc(Compare this NamedView with another NamedView.

Parameter ``other``:
    The other NamedView.

Returns:
    A NamedViewPropMask with bits set that indicate differences
    between the two NamedViews.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetViewGraphicsType =R"doc(Get the type of graphics-capture to use when merging type type of view
of a reference into its parent model.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetViewTypeDescription =R"doc(Gets a human-readable description for this NamedView's type.

Remark:
    s This string should be translated. It is used only to describe
    the view.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetViewTypeName =R"doc(Gets a human-readable identifier for this NamedView's type.

Remark:
    s This string should NOT be translated. It is used by in
    expressions by Project Explorer to detect view subtypes.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_SetClipElement =R"doc(Sets the clip element of this NamedView.

Parameter ``clipElement``:
    The clip element.

Returns:
    SUCCESS or error code.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetClipElement =R"doc(Gets the clip element of this NamedView. For Associated clip element,
if clip element is not in the same model as saved view then it will
return the actual clip element from different model not the far
reference element in the saved view's model. Hence it is callers
responsibility to use it correctly while setting this clip element on
saved view again.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_CopyAndConvertToFile =R"doc(Creates a new NamedView from this NamedView and converts it to the
destination file.

Parameter ``destination``:
    The DgnFile to which the NamedView is to be converted.

Returns:
    The newly created NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_CompareName =R"doc(Compare the name of this NamedView with the argument.

Parameter ``compareName``:
    The name to compare to.

Parameter ``partialMatch``:
    If true, returns 0 if the NamedView name matches through all
    characters in compareName (i.e, a NamedView named " Future Site ",
    matches the name " Future " when partialMatch is true).

Returns:
    0 if match, otherwise the first character that differs.

Remark:
    s The comparis on is case-insensitive regardless of the value of
    partialMatch.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetDisplayableElement =R"doc(Gets the the ElementHandle of the displayable representation of this
NamedView.

Returns:
    STATUS_Success, or an error code.

Parameter ``displayableHandle``:
    The displayable element.

Parameter ``model``:
    The DgnModel of the displayable.

Parameter ``createIfNecessary``:
    Create the Displayable element if doesn't already exist.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_CopySettingsFromSeedView =R"doc(Copies the contents of the seed NamedView to this NamedView. Copies
only 'settings' data. Does not copy clip element - so, a named view
with existing clip element can call it to copy just the settings

Parameter ``seedView``:
    The source NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_DeleteFromFile =R"doc(Delete this NamedView from the DgnFile.

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.

Remark:
    s NamedViews are deleted undoably.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_WriteToFile =R"doc(Write this NamedView to the DgnFile.

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.

Remark:
    s NamedViews are written undoably.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_ConvertToFile =R"doc(Converts the information in this NamedView to the destination DgnFile.

Parameter ``destination``:
    The DgnFile to which the NamedView is to be converted.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_SynchViewBoundaryWithClipVolume =R"doc(Synch the saved view's boundary with the clip volume.

Parameter ``options``:
    ViewBoundary synch options.

Parameter ``rotMatrix``:
    orientation for saved view.

Returns:
    Success, if viewboundary synched with clip volume.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetIcon =R"doc(Gets the name of the Icon used to represent this type of NamedView in
the User Interface.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_SetViewPortInfo =R"doc(Sets the ViewPortInfo for this NamedView.

Parameter ``viewPortInfo``:
    The new ViewPortInfo for this NamedView.

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetViewPortInfo =R"doc(Gets a const reference to the ViewPortInfo for this NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_SetViewInfo =R"doc(Sets the ViewInfo for this NamedView.

Parameter ``viewInfo``:
    The new ViewInfo for this NamedView.

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetViewInfo =R"doc(Gets a const reference to the ViewInfo for this NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetElementRef =R"doc(Gets the ElementRefP of the persistent storage of this NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetElementId =R"doc(Gets the ElementId of the persistent storage of this NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_SetDescription =R"doc(Sets the description of this NamedView

Parameter ``description``:
    The new description for this NamedView.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetDescription =R"doc(Gets the description of this NamedView)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_SetName =R"doc(Sets the Name of this NamedView

Parameter ``name``:
    The new name for this NamedView.

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedView_GetName =R"doc(Gets the name of this NamedView)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewPropMask_From =R"doc(Creates a new NamedViewPropMask from an existing one.

Parameter ``other``:
    bitmask)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewPropMask_AnyBitSet =R"doc(Returns:
    true if any bit is set.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewPropMask_GetBit =R"doc(Gets the designated bit

Parameter ``bitToTest``:
    Which bit.

Returns:
    The state of the designated bit.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewPropMask_SetBit =R"doc(Sets the designated bit

Parameter ``bitToChange``:
    Which bit.

Parameter ``value``:
    Value to set.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewCollection_GetUniqueNameFromBase =R"doc(Gets a unique name for a NamedViewp given a " base " name.

Parameter ``uniqueName``:
    The generated uniqueName.

Parameter ``baseName``:
    The base name. If NULL, the name of the model (decorated with
    " transient " if transient is true) is used as the base name.

Parameter ``forCopy``:
    If the object with the new name is a copy of the object of
    'baseName', then new name will be built with " - Copy " suffix

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewCollection_NameUnused =R"doc(Returns true if the name tested is unique within this
NamedViewCollection.

Parameter ``name``:
    The name to test)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewCollection_Replace =R"doc(Replaces an existing named view with a new named view.

Parameter ``namedView``:
    The new named view.

Parameter ``nameOfViewReplaced``:
    The name of the named view to replace. If NULL, replaces the
    existing namedView with name namedView.GetName();

Returns:
    Success, or one of the NamedViewStatus values if there is an
    error.

Remark:
    The replacement named view is written to the DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewCollection_FindByElementId =R"doc(Finds a NamedView by the ElementId of the element that stores the
NamedView.

Parameter ``elementId``:
    The ElementId of the NamedView to search for.

Returns:
    The NamedViewPtr that references the NamedView with the given name
    or NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedViewCollection_FindByName =R"doc(Finds a NamedView by name.

Parameter ``name``:
    The name of the NamedView to search for.

Parameter ``partialMatch``:
    Allow partial match. See NamedView::CompareName.

Returns:
    The NamedViewPtr that references the NamedView with the given name
    or NULL.

Remark:
    s The comparison is case-insensitive.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_NamedView(py::module_& m)
    {
    //===================================================================================
    // enum class NamedViewStatus
    py::enum_< NamedViewStatus>(m, "NamedViewStatus")
        .value("eSuccess", NamedViewStatus::Success)
        .value("eNameTooShort", NamedViewStatus::NameTooShort)
        .value("eNameTooLong", NamedViewStatus::NameTooLong)
        .value("eNameNotUnique", NamedViewStatus::NameNotUnique)
        .value("eNameIllegalCharacter", NamedViewStatus::NameIllegalCharacter)
        .value("eViewNotFound", NamedViewStatus::ViewNotFound)
        .value("eNameOwningDgnFileUnknown", NamedViewStatus::NameOwningDgnFileUnknown)
        .value("eBadFile", NamedViewStatus::BadFile)
        .value("eCantWriteToFile", NamedViewStatus::CantWriteToFile)
        .value("eWrongHandler", NamedViewStatus::WrongHandler)
        .value("eCantSetHandler", NamedViewStatus::CantSetHandler)
        .value("eViewNotPersistent", NamedViewStatus::ViewNotPersistent)
        .value("eCouldNotDelete", NamedViewStatus::CouldNotDelete)
        .value("eCantReplaceInFile", NamedViewStatus::CantReplaceInFile)
        .value("eBadNamedView", NamedViewStatus::BadNamedView)
        .value("eBadTargetViewport", NamedViewStatus::BadTargetViewport)
        .value("eModelNotFound", NamedViewStatus::ModelNotFound)
        .value("eCantSaveXAttributes", NamedViewStatus::CantSaveXAttributes)
        .export_values();

    //===================================================================================
    // enum class AnnotationAttachmentStatus
    py::enum_< AnnotationAttachmentStatus>(m, "AnnotationAttachmentStatus")
        .value("eSuccess", AnnotationAttachmentStatus::Success)
        .value("eError", AnnotationAttachmentStatus::Error)
        .value("eNoDrawingLink", AnnotationAttachmentStatus::NoDrawingLink)
        .value("eNo3DReference", AnnotationAttachmentStatus::No3DReference)
        .value("eCantClip", AnnotationAttachmentStatus::CantClip)
        .value("eNotNamedView", AnnotationAttachmentStatus::NotNamedView)
        .value("eNoAnnotationAttachment", AnnotationAttachmentStatus::NoAnnotationAttachment)
        .value("eActiveAnnotationAttachment", AnnotationAttachmentStatus::ActiveAnnotationAttachment)
        .export_values();

    //===================================================================================
    // enum class RefRangePathStatus
    py::enum_< RefRangePathStatus>(m, "RefRangePathStatus")
        .value("eSuccess", RefRangePathStatus::Success)
        .value("eError", RefRangePathStatus::Error)
        .value("eThlReference", RefRangePathStatus::ThlReference)
        .value("eNo3DReference", RefRangePathStatus::No3DReference)
        .value("eNoIntersectingReference", RefRangePathStatus::NoIntersectingReference)
        .value("eDwgReference", RefRangePathStatus::DwgReference)
        .export_values();

    //===================================================================================
    // enum class ViewGraphicsType
    py::enum_< ViewGraphicsType>(m, "ViewGraphicsType")
        .value("eElements", ViewGraphicsType::Elements)
        .value("eWireFrame", ViewGraphicsType::WireFrame)
        .value("eVisibleEdges", ViewGraphicsType::VisibleEdges)
        .export_values();

    //===================================================================================
    // enum class NamedViewProp
    py::enum_< NamedViewProp>(m, "NamedViewProp")
        .value("eType", NamedViewProp::Type)
        .value("eName", NamedViewProp::Name)
        .value("eDescription", NamedViewProp::Description)
        .value("eLevelMasks", NamedViewProp::LevelMasks)
        .value("eGeomInfo_Origin", NamedViewProp::GeomInfo_Origin)
        .value("eGeomInfo_Delta", NamedViewProp::GeomInfo_Delta)
        .value("eGeomInfo_RotMatrix", NamedViewProp::GeomInfo_RotMatrix)
        .value("eGeomInfo_Activez", NamedViewProp::GeomInfo_Activez)
        .value("eGeomInfo_CameraAngle", NamedViewProp::GeomInfo_CameraAngle)
        .value("eGeomInfo_CameraFocalLen", NamedViewProp::GeomInfo_CameraFocalLen)
        .value("eGeomInfo_CameraPosition", NamedViewProp::GeomInfo_CameraPosition)
        .value("eGeomInfo_ViewFlags", NamedViewProp::GeomInfo_ViewFlags)
        .value("ePortInfo_RelativeRect", NamedViewProp::PortInfo_RelativeRect)
        .value("ePortInfo_AspectRatio", NamedViewProp::PortInfo_AspectRatio)
        .value("ePortInfo_ViewPixelRect", NamedViewProp::PortInfo_ViewPixelRect)
        .value("eTypeSpecificData", NamedViewProp::TypeSpecificData)
        .export_values();

    //===================================================================================
    m.attr("VIEWTYPE_Basic") = VIEWTYPE_Basic;
    m.attr("VIEWTYPE_Plan") = VIEWTYPE_Plan;
    m.attr("VIEWTYPE_Section") = VIEWTYPE_Section;
    m.attr("VIEWTYPE_Elevation") = VIEWTYPE_Elevation;
    m.attr("VIEWTYPE_Detail") = VIEWTYPE_Detail;
    m.attr("VIEWTYPE_Markup") = VIEWTYPE_Markup;

    //===================================================================================
    // struct NamedViewCollection
    py::class_< NamedViewCollection, std::unique_ptr<NamedViewCollection, py::nodelete> > c1(m, "NamedViewCollection");

    c1.def("FindByName", &NamedViewCollection::FindByName, "name"_a, "partialMatch"_a, DOC(Bentley, DgnPlatform, NamedViewCollection, FindByName));
    c1.def("FindByElementId", &NamedViewCollection::FindByElementId, "elementId"_a, DOC(Bentley, DgnPlatform, NamedViewCollection, FindByElementId));
    c1.def("Replace", &NamedViewCollection::Replace, "namedView"_a, "nameOfViewReplaced"_a, DOC(Bentley, DgnPlatform, NamedViewCollection, Replace));
    c1.def("NameUnused", &NamedViewCollection::NameUnused, "name"_a, DOC(Bentley, DgnPlatform, NamedViewCollection, NameUnused));
    c1.def("__len__", &NamedViewCollection::Size);
    c1.def("GetUniqueNameFromBase", &NamedViewCollection::GetUniqueNameFromBase, "uniqueName"_a, "baseName"_a, "forCopy"_a = false, DOC(Bentley, DgnPlatform, NamedViewCollection, GetUniqueNameFromBase));
    c1.def("__iter__", [] (NamedViewCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct NamedViewPropMask : public RefCountedBase
    py::class_< NamedViewPropMask, NamedViewPropMaskPtr> c2(m, "NamedViewPropMask");

    c2.def("SetBit", &NamedViewPropMask::SetBit, "bitToChange"_a, "value"_a, DOC(Bentley, DgnPlatform, NamedViewPropMask, SetBit));
    c2.def("GetBit", &NamedViewPropMask::GetBit, "bitToTest"_a, DOC(Bentley, DgnPlatform, NamedViewPropMask, GetBit));
    c2.def("AnyBitSet", &NamedViewPropMask::AnyBitSet, DOC(Bentley, DgnPlatform, NamedViewPropMask, AnyBitSet));
    c2.def("From", &NamedViewPropMask::From, "other"_a, DOC(Bentley, DgnPlatform, NamedViewPropMask, From));

    //===================================================================================
    // enum class ExtractReferenceViewInfoStatus
    py::enum_< ExtractReferenceViewInfoStatus>(m, "ExtractReferenceViewInfoStatus")
        .value("eSuccess", ExtractReferenceViewInfoStatus::Success)
        .value("eNotAssociatedToASavedView", ExtractReferenceViewInfoStatus::NotAssociatedToASavedView)
        .value("eIsSynchronizedWithSavedView", ExtractReferenceViewInfoStatus::IsSynchronizedWithSavedView)
        .value("eCouldNotAcquireViewData", ExtractReferenceViewInfoStatus::CouldNotAcquireViewData)
        .value("eUnexpectedError", ExtractReferenceViewInfoStatus::UnexpectedError)
        .export_values();

    //===================================================================================
    // struct ViewBoundarySynchOptions
    py::class_< ViewBoundarySynchOptions> c3(m, "ViewBoundarySynchOptions");

    c3.def_readwrite("ignoreMargins", &ViewBoundarySynchOptions::m_ignoreMargins);
    c3.def_readwrite("orientToStandardAxes", &ViewBoundarySynchOptions::m_orientToStandardAxes);
    c3.def(py::init<>());
    c3.def(py::init<bool, bool>(), "ignoreMargins"_a, "orientToStandardAxes"_a);

    //===================================================================================
    // struct NamedView
    py::class_< NamedView, NamedViewPtr> c4(m, "NamedView");

    c4.def_property("Name", &NamedView::GetName, &NamedView::SetName);
    c4.def("GetName", &NamedView::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetName));
    c4.def("SetName", &NamedView::SetName, "name"_a, DOC(Bentley, DgnPlatform, NamedView, SetName));
    
    c4.def_property("Description", &NamedView::GetDescription, &NamedView::SetDescription);
    c4.def("GetDescription", &NamedView::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetDescription));
    c4.def("SetDescription", &NamedView::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, NamedView, SetDescription));
    
    c4.def_property_readonly("ElementId", &NamedView::GetElementId);
    c4.def("GetElementId", &NamedView::GetElementId, DOC(Bentley, DgnPlatform, NamedView, GetElementId));
    
    c4.def_property_readonly("ElementRef", &NamedView::GetElementRef);
    c4.def("GetElementRef", &NamedView::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetElementRef));
    
    c4.def_property_readonly("DgnFile", &NamedView::GetDgnFileP);
    c4.def("GetDgnFile", &NamedView::GetDgnFileP, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("ElementHandler", &NamedView::GetElementHandlerP);    
    c4.def("GetElementHandler", &NamedView::GetElementHandlerP, py::return_value_policy::reference_internal);
    
    c4.def_property("ViewInfo", &NamedView::GetViewInfoR, &NamedView::SetViewInfo);
    c4.def("GetViewInfo", &NamedView::GetViewInfoR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetViewInfo));
    c4.def("SetViewInfo", &NamedView::SetViewInfo, "viewInfo"_a, DOC(Bentley, DgnPlatform, NamedView, SetViewInfo));
    
    c4.def_property("ViewPortInfo", &NamedView::GetViewPortInfoR, &NamedView::SetViewPortInfo);
    c4.def("GetViewPortInfo", &NamedView::GetViewPortInfoR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetViewPortInfo));
    c4.def("SetViewPortInfo", &NamedView::SetViewPortInfo, "vpInfo"_a, DOC(Bentley, DgnPlatform, NamedView, SetViewPortInfo));
    
    c4.def_property_readonly("Icon", &NamedView::GetIcon);
    c4.def("GetIcon", &NamedView::GetIcon, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetIcon));
    
    c4.def("SynchViewBoundaryWithClipVolume", &NamedView::SynchViewBoundaryWithClipVolume, "options"_a, "rotMatrix"_a = nullptr, DOC(Bentley, DgnPlatform, NamedView, SynchViewBoundaryWithClipVolume));
    c4.def("ConvertToFile", &NamedView::ConvertToFile, "destination"_a, DOC(Bentley, DgnPlatform, NamedView, ConvertToFile));
    c4.def("WriteToFile", &NamedView::WriteToFile, DOC(Bentley, DgnPlatform, NamedView, WriteToFile));
    c4.def("DeleteFromFile", &NamedView::DeleteFromFile, DOC(Bentley, DgnPlatform, NamedView, DeleteFromFile));
    c4.def("CopySettingsFromSeedView", &NamedView::CopySettingsFromSeedView, "seedView"_a, DOC(Bentley, DgnPlatform, NamedView, CopySettingsFromSeedView));
    c4.def("GetDisplayableElement", &NamedView::GetDisplayableElement, "diaplayableHandle"_a, "model"_a, "createIfNecessary"_a, DOC(Bentley, DgnPlatform, NamedView, GetDisplayableElement));
    c4.def("CompareName", &NamedView::CompareName, "compareName"_a, "partialMatch"_a, DOC(Bentley, DgnPlatform, NamedView, CompareName));
    c4.def("CopyAndConvertToFile", &NamedView::CopyAndConvertToFile, "destination"_a, DOC(Bentley, DgnPlatform, NamedView, CopyAndConvertToFile));
    c4.def("GetClipElement", &NamedView::GetClipElement, "clipEEH"_a, DOC(Bentley, DgnPlatform, NamedView, GetClipElement));
    c4.def("SetClipElement", &NamedView::SetClipElement, "clipEH"_a, DOC(Bentley, DgnPlatform, NamedView, SetClipElement));
    
    c4.def_property_readonly("ViewTypeName", &NamedView::GetViewTypeName);
    c4.def("GetViewTypeName", &NamedView::GetViewTypeName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedView, GetViewTypeName));
    
    c4.def_property_readonly("ViewTypeDescription", &NamedView::GetViewTypeDescription);
    c4.def("GetViewTypeDescription", &NamedView::GetViewTypeDescription, DOC(Bentley, DgnPlatform, NamedView, GetViewTypeDescription));
    
    c4.def_property_readonly("ViewGraphicsType", &NamedView::GetViewGraphicsType);
    c4.def("GetViewGraphicsType", &NamedView::GetViewGraphicsType, DOC(Bentley, DgnPlatform, NamedView, GetViewGraphicsType));
    
    c4.def("Compare", &NamedView::Compare, "other"_a, DOC(Bentley, DgnPlatform, NamedView, Compare));
    c4.def("Apply", &NamedView::Apply, "viewport"_a, "options"_a, DOC(Bentley, DgnPlatform, NamedView, Apply));
    
    c4.def_static("Create", [] (DgnFileR dgnFile, WCharCP name)
                  {
                  NamedViewPtr namedView;
                  auto retVal = NamedView::Create(namedView, dgnFile, name);
                  return py::make_tuple(retVal, namedView);
                  }, "dgnFile"_a, "name"_a, DOC(Bentley, DgnPlatform, NamedView, Create));

    c4.def("ShowAnnotationAttachment", &NamedView::ShowAnnotationAttachment, "hostModel"_a, "viewRefModel"_a, "drawingIndex"_a, DOC(Bentley, DgnPlatform, NamedView, ShowAnnotationAttachment));
    c4.def("HideAnnotationAttachment", &NamedView::HideAnnotationAttachment, "hostModel"_a, DOC(Bentley, DgnPlatform, NamedView, HideAnnotationAttachment));
    c4.def("IsAnnotationAttachmentDisplayed", &NamedView::IsAnnotationAttachmentDisplayed, "hostModel"_a, "drawingIndex"_a = -1, DOC(Bentley, DgnPlatform, NamedView, IsAnnotationAttachmentDisplayed));
    c4.def_static("HideAllAnnotationAttachments", &NamedView::HideAllAnnotationAttachments, "hostModel"_a, "viewElemRefToSkip"_a, DOC(Bentley, DgnPlatform, NamedView, HideAllAnnotationAttachments));
    
    c4.def_static("IsViewMemberOfNamedGroup", [] (ElementHandleCR viewEH)
                  {
                  NamedGroupPtr group;
                  auto retVal = NamedView::IsViewMemberOfNamedGroup(&group, viewEH);
                  return py::make_tuple(retVal, group);
                  }, "viewEH"_a, DOC(Bentley, DgnPlatform, NamedView, IsViewMemberOfNamedGroup));

    c4.def_static("GetViewListFromNamedGroup", [] (py::list& viewList, NamedGroupP group)
           {
           std::vector<ElementHandle> ehs;
           auto retVal = NamedView::GetViewListFromNamedGroup(ehs, group);
           if (retVal == SUCCESS && !ehs.empty())
               {
               for (auto& eh : ehs)
                   viewList.append(py::cast(eh));
               }
           return retVal;
           }, "viewList"_a, "group"_a);
    //===================================================================================
    // enum class MarkupViewType
    py::enum_< MarkupViewType>(m, "MarkupViewType")
        .value("eStandard", MarkupViewType::Standard)
        .value("eClash", MarkupViewType::Clash)
        .value("eDV", MarkupViewType::DV)
        .export_values();


    //===================================================================================
    // struct NamedViewDisplayableData
    py::class_< NamedViewDisplayableData> c8(m, "NamedViewDisplayableData");

    c8.def_readwrite("geomInfo", &NamedViewDisplayableData::m_geomInfo);
    c8.def_readwrite("transform", &NamedViewDisplayableData::m_trans);

    //===================================================================================
    //struct NamedViewDisplayable
    py::class_< NamedViewDisplayable> c9(m, "NamedViewDisplayable");

    c9.def_static("CreateElement", &NamedViewDisplayable::CreateElement, "displayElement"_a, "namedViewElement"_a, "model"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, CreateElement));
    c9.def_static("FindElement", &NamedViewDisplayable::FindElement, "displayElement"_a, "namedViewElement"_a, "model"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, FindElement));
    c9.def_static("GetNamedViewElement", &NamedViewDisplayable::GetNamedViewElement, "namedViewElement"_a, "displayElement"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, GetNamedViewElement));
    c9.def_static("GetClipElement", &NamedViewDisplayable::GetClipElement, "clipElement"_a, "displayElement"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, GetClipElement));
    c9.def_static("IsNamedViewDisplayable", &NamedViewDisplayable::IsNamedViewDisplayable, "namedViewElement"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, IsNamedViewDisplayable));
    c9.def_static("GetViewInfo", &NamedViewDisplayable::GetViewInfo, "displayElement"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, GetViewInfo));
    c9.def_static("GetViewData", &NamedViewDisplayable::GetViewData, "viewData"_a, "displayElement"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, GetViewData));
    c9.def_static("SetViewData", &NamedViewDisplayable::SetViewData, "viewData"_a, "displayElement"_a, DOC(Bentley, DgnPlatform, NamedViewDisplayable, SetViewData));
    }