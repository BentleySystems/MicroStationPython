/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\namedboundary.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/NamedBoundary.h>



static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_FindElementById =R"doc(Search a particular named boundary group by element id of the group.

Parameter ``elementId``:
    IN element id of named boundary group

Parameter ``model``:
    IN the model to which the named boundary group belongs.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_FindByName =R"doc(Search a particular named boundary group by name of the group.

Parameter ``groupName``:
    IN the named boundary group to be searched.

Parameter ``model``:
    IN the model to which the named boundary group belongs.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_WriteToFile =R"doc(Saves the named boundary group. After every performed on the named
boundary group, its important to implement this, in order to save the
changes.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_Delete =R"doc(Deletes the named boundary group.

Parameter ``retainBoundariesAsOrphans``:
    IN decides whether after the delete operation the named group
    elements within the group would independently exist as orphan
    named boundaries or not.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_TraverseMembers =R"doc(Traverse through the named boundary group.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_FindGroupContainingBoundary =R"doc(Find the group to which a particular named boundary belongs.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_FindBoundaryByIndex =R"doc(Find a named boundary by index in a named boundary group.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_FindBoundary =R"doc(Find a named boundary in a named boundary group.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_RemoveAllBoundaries =R"doc(Remove all the named boundaries in a named boundary group, but may or
may not be retained as an orphan named boundary(not included in any
group).

Remark:
    s:if the boolean value passed is false, then the named boundary
    ceases to exist as it gets deleted from the dictionary too.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_RemoveBoundary =R"doc(Remove a named boundary from the group, but may or may not be retained
as an orphan named boundary(not included in any group).

Remark:
    s:if the boolean value passed is false, then the named boundary
    ceases to exist as it gets deleted from the dictionary too.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_InsertBoundary =R"doc(Add a new named boundary to the named boundary group.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_GetType =R"doc(Get the type of the namedboundary group.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_GetElement =R"doc(Get the element of the named boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_SetDescription =R"doc(set the decription for the named boundary)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_GetDescription =R"doc(gets the description for the named boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_SetName =R"doc(sets the name of the named boundary .)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryGroup_GetName =R"doc(gets the name of the named boundary .)doc";

static const char * __doc_Bentley_DgnPlatform_INamedBoundaryGroupMemberVisitor_VisitMember =R"doc(Returns:
    SUCCESS to continue traversal, or ERROR to abort)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetIgnoreMarginForViewSync =R"doc(Sets whether to ignore the clip margins while creating saved view from
this named boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetIgnoreMarginForViewSync =R"doc(Gets whether to ignore clip margins while creating saved view from
this named boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_FindByIndex =R"doc(Parameter ``modelRef``:
    IN indicates the file containing the boundary.

Parameter ``index``:
    IN index from where the named boundary would be retrieved

Returns:
    SUCCESS if the named boundary is successfully found at given index
    else returns an appropriate error status.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_FindOrphanByName =R"doc(Find orphan named boundary element.

Parameter ``name``:
    IN The boundary name.

Parameter ``modelRef``:
    IN indicates the file containing the boundary.

Returns:
    SUCCESS if the named boundary is successfully found else returns
    an appropriate error status .)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_FindByName =R"doc(Find named boundary element.

Parameter ``name``:
    IN The boundary name.

Parameter ``parentGroup``:
    IN parent group to search in. NULL to find in all boundaries.

Parameter ``modelRef``:
    IN indicates the file containing the boundary.

Returns:
    SUCCESS if the named boundary is successfully found else returns
    an appropriate error status .)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetParentGroup =R"doc(If this named boundary is part of a group, returns the parent group.

Returns:
    parent group, or NULL if boundary is orphan)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_Save =R"doc(Saves the named boundary to file.

Remark:
    s Named Boundary does not support ToElement () to return a non-
    persistent ElementHandle to a single named boundary because named
    boundary elements cannot be saved individually by calling
    AddToModel (). Instead, call Save () to save the element, and then
    call GetElement () to get the persistent ElementRef.

Returns:
    SUCCESS if the boundary is successfully saved else returns an
    appropriate error status.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_Delete =R"doc(Deletes the named boundary

Returns:
    SUCCESS if the named boundary is successfully deleted and an
    appropriate error status otherwise.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_Clone =R"doc(Make a copy of a given boundary. If source named boundary is part of a
named boundary group, cloned named boundary will not be added to that
groupe implecitely. Cloned NamedBoundary will have to be added to the
group explecitely.

Parameter ``newName``:
    IN name of new boundary

Parameter ``srcBoundary``:
    IN source boundary to be cloned)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetFromGraphicalElement =R"doc(Get associated NamedBoundary from graphical element

Parameter ``el``:
    IN ElementHandle of the graphical element.

Returns:
    a named boundary pointer if no named boundary associated return
    NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_Create =R"doc(Creates the named boundary (using the other available methods for
adding information about the named boundary).)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetViewOrientation =R"doc(Sets the view Orientation on Named Boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetViewOrientation =R"doc(Gets the view Orientation on Named Boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_PeekGraphicalElement =R"doc(Gets the graphical element held by the named boundary.

Remark:
    s:preferred when the named boundary information itself contains
    the type of graphical element held.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetGraphicalElement =R"doc(Sets the named Boundary to the particular type of graphical element it
represents.

Returns:
    SUCCESS if element is closed shape element else ERROR.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetGraphicalElement =R"doc(Gets the graphical element which the named boundary represents.But
this method is preferred only when the graphical element is not held
by the named boundary.

Remark:
    s:Doing this would require loading the model to which the
    graphical element belongs, which can prove expensive.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetModelRef =R"doc(Sets the model which would contain the named boundary .)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetModelRef =R"doc(Gets the model in which the particular named boundary would be placed.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetElement =R"doc(Gets the element type which is represented by the named boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetDrawingScale =R"doc(Gets the drawing scale to which the boundary needs to be scaled on the
drawing sheet.
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	scale.

)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetDrawingScale =R"doc(Sets the drawing scale to which the boundary needs to be scaled on the
drawing sheet.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetDescription =R"doc(Sets the description of the named boundary)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetDescription =R"doc(Gets the description of the named boundary)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_SetName =R"doc(Sets the name of the boundary

Remark:
    s This name is unique only within the parent group. If this named
    boundary is orphan, then this name is unique only among orphans.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundary_GetName =R"doc(Gets the name of the boundary

Remark:
    s This name is unique only within the parent group. If named
    boundary is orphan, then this name is unique only among orphans.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_AppendToElement =R"doc(Append the named boundary clipping depths from the graphical element
associated to a named boundary)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_ExtractFromElement =R"doc(Extract the named boundary clipping depths from the graphical element
associated to a named boundary)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_SetFlipDirection =R"doc(Set the flag that indicates direction of clipping

Parameter ``flipDirection``:
    IN set the flip direction.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_GetFlipDirection =R"doc(Get the flag that indicates direction of clipping

Returns:
    return whether direction of clipping depth is flipped.)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_SetCropBack =R"doc(Set the flag that indicates whether back clipping should be infinite
or cropped at back depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_GetCropBack =R"doc(Get the flag that indicates whether back clipping should be infinite
or cropped at back depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_SetCropFront =R"doc(Set the flag that indicates whether front clipping should be infinite
or cropped at front depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_GetCropFront =R"doc(Get the flag that indicates whether front clipping should be infinite
or cropped at front depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_SetBackDepth =R"doc(Set the back clipping depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_GetBackDepth =R"doc(Get the back clipping depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_SetFrontDepth =R"doc(Set the front clipping depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_GetFrontDepth =R"doc(Get the front clipping depth)doc";

static const char * __doc_Bentley_DgnPlatform_NamedBoundaryClipDepths_Init =R"doc(Initialize data)doc";

//=======================================================================================
// Trampoline class for INamedBoundaryGroupMemberVisitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyNamedBoundaryGroupMemberVisitor : INamedBoundaryGroupMemberVisitor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual StatusInt VisitMember(NamedBoundaryCP boundary, NamedBoundaryGroupCP group, UInt32 index) override
        { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, INamedBoundaryGroupMemberVisitor, VisitMember, ERROR, boundary, group, index); }
    };


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_NamedBoundary(py::module_& m)
    {
    //===================================================================================
    // struct NamedBoundaryClipDepths
    py::class_< NamedBoundaryClipDepths> c1(m, "NamedBoundaryClipDepths");

    c1.def(py::init<>());
    c1.def("Init", &NamedBoundaryClipDepths::Init, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, Init));
    
    c1.def_property("FrontDepth", &NamedBoundaryClipDepths::GetFrontDepth, &NamedBoundaryClipDepths::SetFrontDepth);
    c1.def("GetFrontDepth", &NamedBoundaryClipDepths::GetFrontDepth, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, GetFrontDepth));
    c1.def("SetFrontDepth", &NamedBoundaryClipDepths::SetFrontDepth, "frontDepth"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, SetFrontDepth));
    
    c1.def_property("BackDepth", &NamedBoundaryClipDepths::GetBackDepth, &NamedBoundaryClipDepths::SetBackDepth);
    c1.def("GetBackDepth", &NamedBoundaryClipDepths::GetBackDepth, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, GetBackDepth));
    c1.def("SetBackDepth", &NamedBoundaryClipDepths::SetBackDepth, "backDepth"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, SetBackDepth));
    
    c1.def_property("CropFront", &NamedBoundaryClipDepths::GetCropFront, &NamedBoundaryClipDepths::SetCropFront);
    c1.def("GetCropFront", &NamedBoundaryClipDepths::GetCropFront, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, GetCropFront));
    c1.def("SetCropFront", &NamedBoundaryClipDepths::SetCropFront, "cropFront"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, SetCropFront));
    
    c1.def_property("CropBack", &NamedBoundaryClipDepths::GetCropBack, &NamedBoundaryClipDepths::SetCropBack);
    c1.def("GetCropBack", &NamedBoundaryClipDepths::GetCropBack, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, GetCropBack));
    c1.def("SetCropBack", &NamedBoundaryClipDepths::SetCropBack, "cropBack"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, SetCropBack));
    
    c1.def_property("FlipDirection", &NamedBoundaryClipDepths::GetFlipDirection, &NamedBoundaryClipDepths::SetFlipDirection);
    c1.def("GetFlipDirection", &NamedBoundaryClipDepths::GetFlipDirection, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, GetFlipDirection));
    c1.def("SetFlipDirection", &NamedBoundaryClipDepths::SetFlipDirection, "flip"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, SetFlipDirection));
    
    c1.def("ExtractFromElement", &NamedBoundaryClipDepths::ExtractFromElement, "eh"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, ExtractFromElement));
    c1.def("AppendToElement", py::overload_cast<EditElementHandleR>(&NamedBoundaryClipDepths::AppendToElement, py::const_), "eeh"_a, DOC(Bentley, DgnPlatform, NamedBoundaryClipDepths, AppendToElement));
    
    //===================================================================================
    // struct NamedBoundary
    py::class_< NamedBoundary, NamedBoundaryPtr> c2(m, "NamedBoundary");

    c2.def_property("Name", &NamedBoundary::GetName, &NamedBoundary::SetName);
    c2.def("GetName", &NamedBoundary::GetName, DOC(Bentley, DgnPlatform, NamedBoundary, GetName));
    c2.def("SetName", &NamedBoundary::SetName, "name"_a, DOC(Bentley, DgnPlatform, NamedBoundary, SetName));
    
    c2.def_property("Description", &NamedBoundary::GetDescription, &NamedBoundary::SetDescription);
    c2.def("GetDescription", &NamedBoundary::GetDescription, DOC(Bentley, DgnPlatform, NamedBoundary, GetDescription));
    c2.def("SetDescription", &NamedBoundary::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, NamedBoundary, SetDescription));

    c2.def("SetDrawingScale", &NamedBoundary::SetDrawingScale, "scale"_a, DOC(Bentley, DgnPlatform, NamedBoundary, SetDrawingScale));

    c2.def("GetDrawingScale", [] (NamedBoundaryCR self)
           {
           double scale = 0;
           auto retVal = self.GetDrawingScale(scale);
           return py::make_tuple(retVal, scale);
           }, DOC(Bentley, DgnPlatform, NamedBoundary, GetDrawingScale));
    
    c2.def_property_readonly("Element", &NamedBoundary::GetElement);    
    c2.def("GetElement", &NamedBoundary::GetElement, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedBoundary, GetElement));

    c2.def_property("ModelRef", &NamedBoundary::GetModelRef, py::cpp_function(&NamedBoundary::SetModelRef, py::keep_alive<1, 2>()));    
    c2.def("GetModelRef", &NamedBoundary::GetModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedBoundary, GetModelRef));
    c2.def("SetModelRef", &NamedBoundary::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, NamedBoundary, SetModelRef));
    
    c2.def_property("GraphicalElement", &NamedBoundary::GetGraphicalElement, &NamedBoundary::SetGraphicalElement);
    c2.def("GetGraphicalElement", &NamedBoundary::GetGraphicalElement, DOC(Bentley, DgnPlatform, NamedBoundary, GetGraphicalElement));
    c2.def("SetGraphicalElement", &NamedBoundary::SetGraphicalElement, "eh"_a, DOC(Bentley, DgnPlatform, NamedBoundary, SetGraphicalElement));
    
    c2.def("PeekGraphicalElement", &NamedBoundary::PeekGraphicalElement, DOC(Bentley, DgnPlatform, NamedBoundary, PeekGraphicalElement));
    c2.def("GetViewOrientation", &NamedBoundary::GetViewOrientation, "rotMatrix"_a, DOC(Bentley, DgnPlatform, NamedBoundary, GetViewOrientation));
    c2.def("SetViewOrientation", &NamedBoundary::SetViewOrientation, "rotMatrix"_a, DOC(Bentley, DgnPlatform, NamedBoundary, SetViewOrientation));
    c2.def_static("Create", py::overload_cast<>(&NamedBoundary::Create), DOC(Bentley, DgnPlatform, NamedBoundary, Create));
    c2.def_static("Create", py::overload_cast<ElementHandleCR>(&NamedBoundary::Create), "eh"_a, DOC(Bentley, DgnPlatform, NamedBoundary, Create));
    c2.def_static("GetFromGraphicalElement", &NamedBoundary::GetFromGraphicalElement, "eh"_a, DOC(Bentley, DgnPlatform, NamedBoundary, GetFromGraphicalElement));
    c2.def_static("Clone", &NamedBoundary::Clone, "newName"_a, "srcBoundary"_a, DOC(Bentley, DgnPlatform, NamedBoundary, Clone));
    c2.def("Delete", &NamedBoundary::Delete, DOC(Bentley, DgnPlatform, NamedBoundary, Delete));
    c2.def("Save", &NamedBoundary::Save, DOC(Bentley, DgnPlatform, NamedBoundary, Save));
    
    c2.def_property_readonly("ParentGroup", &NamedBoundary::GetParentGroup);
    c2.def("GetParentGroup", &NamedBoundary::GetParentGroup, DOC(Bentley, DgnPlatform, NamedBoundary, GetParentGroup));
    
    c2.def_static("FindByName", &NamedBoundary::FindByName, "name"_a, "parentGroup"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedBoundary, FindByName));
    c2.def_static("FindOrphanByName", &NamedBoundary::FindOrphanByName, "name"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedBoundary, FindOrphanByName));
    c2.def_static("FindByIndex", &NamedBoundary::FindByIndex, "index"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedBoundary, FindByIndex));
    
    c2.def_property("IgnoreMarginForViewSync", &NamedBoundary::GetIgnoreMarginForViewSync, &NamedBoundary::SetIgnoreMarginForViewSync);
    c2.def("GetIgnoreMarginForViewSync", &NamedBoundary::GetIgnoreMarginForViewSync, DOC(Bentley, DgnPlatform, NamedBoundary, GetIgnoreMarginForViewSync));
    c2.def("SetIgnoreMarginForViewSync", &NamedBoundary::SetIgnoreMarginForViewSync, "val"_a, DOC(Bentley, DgnPlatform, NamedBoundary, SetIgnoreMarginForViewSync));

    //===================================================================================
    // struct NamedBoundaryCollection
    py::class_< NamedBoundaryCollection, NamedBoundaryCollectionPtr> c3(m, "NamedBoundaryCollection");

    c3.def("__len__", &NamedBoundaryCollection::GetCount);
    c3.def("__bool__", [] (NamedBoundaryCollection& self) { return !self.empty(); });
    c3.def(py::init(py::overload_cast<DgnModelCR>(&NamedBoundaryCollection::Create)), "model"_a);
    c3.def(py::init(py::overload_cast<DgnModelCR, NamedBoundaryGroupP>(&NamedBoundaryCollection::Create)), "model"_a, "group"_a);
    c3.def("__iter__", [] (NamedBoundaryCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct INamedBoundaryGroupMemberVisitor
    py::class_< INamedBoundaryGroupMemberVisitor, std::unique_ptr< INamedBoundaryGroupMemberVisitor, py::nodelete>, IPyNamedBoundaryGroupMemberVisitor> c4(m, "INamedBoundaryGroupMemberVisitor");

    c4.def(py::init<>());
    c4.def("VisitMember", &INamedBoundaryGroupMemberVisitor::VisitMember, "boundary"_a, "group"_a, "index"_a, DOC(Bentley, DgnPlatform, INamedBoundaryGroupMemberVisitor, VisitMember));

    //===================================================================================
    // struct NamedBoundaryGroup
    py::class_< NamedBoundaryGroup, NamedBoundaryGroupPtr> c5(m, "NamedBoundaryGroup");

    c5.def_property("Name", &NamedBoundaryGroup::GetName, &NamedBoundaryGroup::SetName);
    c5.def("GetName", &NamedBoundaryGroup::GetName, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, GetName));
    c5.def("SetName", &NamedBoundaryGroup::SetName, "name"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, SetName));
    
    c5.def_property("Description", &NamedBoundaryGroup::GetDescription, &NamedBoundaryGroup::SetDescription);
    c5.def("GetDescription", &NamedBoundaryGroup::GetDescription, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, GetDescription));
    c5.def("SetDescription", &NamedBoundaryGroup::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, SetDescription));
    
    c5.def_property_readonly("Element", &NamedBoundaryGroup::GetElement);
    c5.def("GetElement", &NamedBoundaryGroup::GetElement, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, GetElement));
    
    c5.def_property_readonly("Type", &NamedBoundaryGroup::GetType);
    c5.def("GetType", &NamedBoundaryGroup::GetType, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, GetType));
    
    c5.def("InsertBoundary", [] (NamedBoundaryGroup& self, NamedBoundaryP boundary)
           { 
           return self.InsertBoundary(NamedBoundaryPtr(boundary)); 
           }, "boundary"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, InsertBoundary));

    c5.def("InsertBoundary", [] (NamedBoundaryGroup& self, NamedBoundaryP boundary, int index)
           {
           return self.InsertBoundary(NamedBoundaryPtr(boundary), index);
           }, "boundary"_a, "index"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, InsertBoundary));

    c5.def("RemoveBoundary", [] (NamedBoundaryGroup& self, NamedBoundaryP boundary, bool retainAsOrphan)
           {
           return self.RemoveBoundary(NamedBoundaryPtr(boundary), retainAsOrphan);
           }, "boundary"_a, "retainAsOrphan"_a = false, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, RemoveBoundary));

    c5.def("RemoveAllBoundaries", &NamedBoundaryGroup::RemoveAllBoundaries, "retainBoundariesAsOrphans"_a = false, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, RemoveAllBoundaries));
    c5.def("FindBoundary", &NamedBoundaryGroup::FindBoundary, "name"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, FindBoundary));
    c5.def("FindBoundaryByIndex", &NamedBoundaryGroup::FindBoundaryByIndex, "index"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, FindBoundaryByIndex));
    c5.def_static("FindGroupContainingBoundary", &NamedBoundaryGroup::FindGroupContainingBoundary, "boundary"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, FindGroupContainingBoundary));
    c5.def("__len__", &NamedBoundaryGroup::GetCount);
    c5.def("TraverseMembers", &NamedBoundaryGroup::TraverseMembers, "visitor"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, TraverseMembers));
    c5.def(py::init(py::overload_cast<DgnModelR, WStringCR, WStringCR>(NamedBoundaryGroup::Create)), "model"_a, "suggestedName"_a, "descr"_a);
    c5.def(py::init(py::overload_cast<ElementHandleCR>(NamedBoundaryGroup::Create)), "eh"_a);
    c5.def("Delete", &NamedBoundaryGroup::Delete, "retainBoundariesAsOrphans"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, Delete));
    c5.def("WriteToFile", &NamedBoundaryGroup::WriteToFile, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, WriteToFile));
    c5.def_static("FindByName", &NamedBoundaryGroup::FindByName, "groupName"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, FindByName));
    c5.def_static("FindElementById", &NamedBoundaryGroup::FindElementById, "elementId"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NamedBoundaryGroup, FindElementById));

    //===================================================================================
    // struct NamedBoundaryGroupCollection
    py::class_< NamedBoundaryGroupCollection, NamedBoundaryGroupCollectionPtr> c6(m, "NamedBoundaryGroupCollection", py::multiple_inheritance());

    c6.def(py::init(&NamedBoundaryGroupCollection::Create), "modelRef"_a);
    c6.def("__iter__", [] (NamedBoundaryGroupCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    }