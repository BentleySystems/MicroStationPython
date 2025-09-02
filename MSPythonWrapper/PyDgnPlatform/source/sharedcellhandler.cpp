/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\sharedcellhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/SharedCellHandler.h>



static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_AddChildComplete =R"doc(Update the shared cell definitions range and component count once all
child elements have been added.

:param eeh:
    The shared cell definition element.

:returns:
    SUCCESS if the shared cell definition has children and it's range
    was sucessfully updated. Bentley Systems +---------------+--------
    -------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_AddChildElement =R"doc(Add another element as a child of the shared cell definition.

:param eeh:
    The shared cell definition to add the child to.

:param childEeh:
    The child element to add.

:returns:
    SUCCESS if child is suitable for a shared cell definition
    component and was successfully added. @note childEeh will be
    invalid after this call unless it represents a persistent element.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_CreateSharedCellDefElement =R"doc(Create a new SHAREDCELL_DEF_ELM with the supplied information. After
creating the shared cell definitionheader the application should use
AddChildElement to add child elements to the definition, and
AddChildComplete once all children have been added to finish the
shared cell definition creation.

:param eeh:
    The new element.

:param cellName:
    Name of the new shared cell definition element which may be NULL
    if creating an anonymous shared cell definition.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Will be returned from
    eeh.GetModelRef () and later used by AddChildComplete to updating
    the element's range. @note To create an anonymous shared cell
    definition call SetAnonymous on the new element. Bentley Systems +
    ---------------+---------------+---------------+---------------+--
    -------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetDimRotationOption =R"doc(Set the flag that controls the display behavior of dimensions in
nested shared cells with regards to whether to use the instance
rotation or parent rotation when creating a new element.

:param eeh:
    The element to modify.

:param rotateDimView:
    Dimension rotation flag.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetDimScaleOption =R"doc(Set the flag that controls the display behavior of dimensions when
displayed through a scaled shared cell instance when creating a new
element.

:param eeh:
    The element to modify.

:param nondefaultScaleForDims:
    Dimenion scale flag.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetMlineScaleOption =R"doc(Set the flag that controls the display behavior of Multiline offsets
when displayed through a scaled shared cell instance when creating a
new element.

:param eeh:
    The element to modify.

:param scaleMultilines:
    Multiline offset scale flag.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetDescription =R"doc(Set the given shared cell definition element's description when
creating a new element.

:param eeh:
    The element to modify.

:param descr:
    New shared cell definition description.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetName =R"doc(Set the given shared cell definition element's name when creating a
new element.

:param eeh:
    The element to modify.

:param cellName:
    New shared cell definition name.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetAnonymous =R"doc(Set the anonymouse cell status when creating a new shared cell
definition.

:param eeh:
    The element to modify.

:param isAnonymous:
    false for named shared cell, true for anonymous.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetAnnotation =R"doc(Set the annotation cell status when creating a new shared cell
definition.

:param eeh:
    The element to modify.

:param isAnnotation:
    New annotation cell status.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellDefHandler_SetPointCell =R"doc(Set the point cell status when creating a new shared cell definition.

:param eeh:
    The element to modify.

:param isPointCell:
    New point cell status.

:returns:
    SUCCESS if eeh is a SHAREDCELL_DEF_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellHandler_CreateSharedCellComplete =R"doc(Update the shared cell's range from the instance's transform and
shared cell definition.

:param eeh:
    The shared cell element.

:returns:
    SUCCESS if the shared cell definition exists and the range was
    sucessfully updated. @note Requires that the shared cell
    definition already exists in the destination model.

Remark:
    s This is merely a helper function that calls
    DisplayHandler::ValidateElementRange. Bentley Systems +-----------
    ----+---------------+---------------+---------------+-------------
    --+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellHandler_SetDefinitionID =R"doc(Set the shared cell definition id for the supplied shared cell
instance when creating a new element.

:param eeh:
    The element to modify.

:param elemID:
    ElementId of the shared cell defintion to associate this instance
    to.

:returns:
    SUCCESS if eeh is a SHARED_CELL_ELM and element was updated. @note
    Named shared cells may have an explicit dependency to their
    definition, however this is not required and normally reserved
    only for anonymous shared cells where it is required. Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellHandler_SetDescription =R"doc(Set the given shared cell element's description when creating a new
element.

:param eeh:
    The element to modify.

:param descr:
    New cell description.

:returns:
    SUCCESS if eeh is a SHARED_CELL_ELM and element was updated. @note
    A description that is common to all shared cell intances should be
    stored once on the shared cell definition, not on each instance.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellHandler_SetName =R"doc(Set the given shared cell element's name when creating a new element.

:param eeh:
    The element to modify.

:param cellName:
    New cell name.

:returns:
    SUCCESS if eeh is a SHARED_CELL_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellHandler_SetPointCell =R"doc(Set the given shared cell element's point cell status when creating a
new element.

:param eeh:
    The element to modify.

:param isPointCell:
    New point cell status.

:returns:
    SUCCESS if eeh is a SHARED_CELL_ELM and element was updated. @note
    Could affect shared cell's range. If creating a new instance or
    modifying an existing instance caller is expected to call
    CreateSharedCellComplete or ValidateElementRange after making all
    changes and before adding or replacing element in model. Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_SharedCellHandler_SetSharedCellOverrides =R"doc(Set the shared cell override values and flags that will be used when
visiting the components of the shared cell definition when creating a
new element.

:param eeh:
    The element to modify.

:param overrides:
    The new shared cell overrides.

:returns:
    SUCCESS if eeh is a SHARED_CELL_ELM and element was updated. @note
    Could affect shared cell's range. If creating a new instance or
    modifying an existing instance caller is expected to call
    CreateSharedCellComplete or ValidateElementRange after making all
    changes and before adding or replacing element in model. Bentley
    Systems +---------------+---------------+---------------+---------
    ------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SharedCellHandler(py::module_& m)
    {
    //===================================================================================
    // struct SharedCellHandler
    py::class_< SharedCellHandler
        , std::unique_ptr< SharedCellHandler, py::nodelete>
        , DisplayHandler
        , ISharedCellQuery
        , IAnnotationHandler> c1(m, "SharedCellHandler");


    c1.def_static("SetSharedCellOverrides", &SharedCellHandler::SetSharedCellOverrides, "eeh"_a, "overrides"_a, DOC(Bentley, DgnPlatform, SharedCellHandler, SetSharedCellOverrides));
    c1.def_static("SetPointCell", &SharedCellHandler::SetPointCell, "eeh"_a, "isPointCell"_a, DOC(Bentley, DgnPlatform, SharedCellHandler, SetPointCell));
    c1.def_static("SetName", &SharedCellHandler::SetName, "eeh"_a, "cellName"_a, DOC(Bentley, DgnPlatform, SharedCellHandler, SetName));
    c1.def_static("SetDescription", &SharedCellHandler::SetDescription, "eeh"_a, "descr"_a, DOC(Bentley, DgnPlatform, SharedCellHandler, SetDescription));
    c1.def_static("SetDefinitionID", &SharedCellHandler::SetDefinitionID, "eeh"_a, "elemId"_a, DOC(Bentley, DgnPlatform, SharedCellHandler, SetDefinitionID));
    
    c1.def_static("CreateSharedCellElement", 
                  &SharedCellHandler::CreateSharedCellElement, 
                  "eeh"_a, "templateEh"_a, "cellName"_a, "origin"_a, "rMatrix"_a, "scale"_a, "is3d"_a, "modelRef"_a);

    c1.def_static("CreateSharedCellComplete", &SharedCellHandler::CreateSharedCellComplete, "eeh"_a, DOC(Bentley, DgnPlatform, SharedCellHandler, CreateSharedCellComplete));
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<SharedCellHandler, py::nodelete>(&SharedCellHandler::GetInstance()); });
    c1.def_static("GetInstance", &SharedCellHandler::GetInstance, py::return_value_policy::reference);
        
    //===================================================================================
    // struct SharedCellDefHandler
    py::class_< SharedCellDefHandler
        , std::unique_ptr<SharedCellDefHandler, py::nodelete>
        , ComplexHeaderDisplayHandler
        , ITransactionHandler
        , ISharedCellQuery> c2(m, "SharedCellDefHandler");

    c2.def_static("SetPointCell", &SharedCellDefHandler::SetPointCell, "eeh"_a, "isPointCell"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetPointCell));
    c2.def_static("SetAnnotation", &SharedCellDefHandler::SetAnnotation, "eeh"_a, "isAnnotation"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetAnnotation));
    c2.def_static("SetAnonymous", &SharedCellDefHandler::SetAnonymous, "eeh"_a, "isAnonymous"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetAnonymous));
    c2.def_static("SetName", &SharedCellDefHandler::SetName, "eeh"_a, "cellName"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetName));
    c2.def_static("SetDescription", &SharedCellDefHandler::SetDescription, "eeh"_a, "descr"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetDescription));
    c2.def_static("SetMlineScaleOption", &SharedCellDefHandler::SetMlineScaleOption, "eeh"_a, "scaleMultilines"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetMlineScaleOption));
    c2.def_static("SetDimScaleOption", &SharedCellDefHandler::SetDimScaleOption, "eeh"_a, "nonDefaultScaleForDims"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetDimScaleOption));
    c2.def_static("SetDimRotationOption", &SharedCellDefHandler::SetDimRotationOption, "eeh"_a, "rotateDimView"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, SetDimRotationOption));
    c2.def_static("CreateSharedCellDefElement", &SharedCellDefHandler::CreateSharedCellDefElement, "eeh"_a, "celName"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, CreateSharedCellDefElement));
    c2.def_static("AddChildElement", &SharedCellDefHandler::AddChildElement, "eeh"_a, "childEeh"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, AddChildElement));
    c2.def_static("AddChildComplete", &SharedCellDefHandler::AddChildComplete, "eeh"_a, DOC(Bentley, DgnPlatform, SharedCellDefHandler, AddChildComplete));
    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<SharedCellDefHandler, py::nodelete>(&SharedCellDefHandler::GetInstance()); });
    c2.def_static("GetInstance", &SharedCellDefHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct NamedSharedCellDefCollection
    py::class_< NamedSharedCellDefCollection> c3(m, "NamedSharedCellDefCollection");

    c3.def(py::init<DgnFileR>(), "dgnFile"_a);
    c3.def("__iter__", [] (NamedSharedCellDefCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct AnonymousSharedCellDefCollection
    py::class_< AnonymousSharedCellDefCollection> c4(m, "AnonymousSharedCellDefCollection");

    c4.def(py::init<DgnFileR>(), "dgnFile"_a);
    c4.def("__iter__", [] (AnonymousSharedCellDefCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }

