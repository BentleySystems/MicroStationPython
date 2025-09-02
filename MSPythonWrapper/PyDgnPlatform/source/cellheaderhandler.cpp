/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\cellheaderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/CellHeaderHandler.h>



static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_AddChildComplete =R"doc(Update the cell's range, origin, range diagonal, and component count
once all child elements have been added.

:param eeh:
    The cell element.

:returns:
    SUCCESS if the cell has children and it's range was sucessfully
    updated. Bentley Systems +---------------+---------------+--------
    -------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_AddChildElement =R"doc(Add another element as a child of the cell.

:param eeh:
    The cell to add the child to.

:param childEeh:
    The child element to add.

:returns:
    SUCCESS if child is suitable for a cell component and was
    successfully added. @note childEeh will be invalid after this call
    unless it represents a persistent element. Bentley Systems +------
    ---------+---------------+---------------+---------------+--------
    -------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_CreateCellElement =R"doc(Create a new named CELL_HEADER_ELM with supplied origin and rotation.
After creating the cell header the application should use
AddChildElement to add child elements to the cell, and
AddChildComplete once all children have been added to finish the cell
creation.

:param eeh:
    The new element.

:param cellName:
    Name of the new cell element.

:param origin:
    new cell's origin.

:param rMatrix:
    new cell's rotation.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Will be returned from
    eeh.GetModelRef () and later used by AddChildComplete to update
    the cell's range. @note Use this method to create cells where the
    cellName represents a unique set of geometry such as a user
    defined cell. For application defined cells and groups orphan
    cells should be created instead.

See also:
    CreateOrphanCellElement Bentley Systems +---------------+---------
    ------+---------------+---------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_CreateOrphanCellElement =R"doc(Create a new anonymous orphan CELL_HEADER_ELM with origin at zero and
identity rotation. After creating the cell header the application
should use AddChildElement to add child elements to the cell, and
AddChildComplete once all children have been added to finish the cell
creation.

:param eeh:
    The new element.

:param cellName:
    Name of the new cell element which may be NULL.

:param is3d:
    Initialize the 2d or 3d element structure, typically
    modelRef->Is3d ().

:param modelRef:
    Model to associate this element with. Will be returned from
    eeh.GetModelRef () and later used by AddChildComplete to update
    the cell's range. @note An orphan (or anonymous) cell is a cell
    without a name or whose name doesn't necessarily identify a unique
    set of geometry. A user defined cells are NOT orphan cells.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_CreateGroupCellElement =R"doc(Create a new group cell (orphan cell) from a collection of elements.

:param eeh:
    The new element.

:param agenda:
    The child elements.

:param cellName:
    The cell name (optional) @note All child elements must be from the
    same model, the model to associate the new cell element with.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_SetDescription =R"doc(Set the given cell element's description when creating a new element.

:param eeh:
    The cell element.

:param descr:
    New cell description.

:returns:
    SUCCESS if eeh is a CELL_HEADER_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_SetName =R"doc(Set the given cell element's name when creating a new element.

:param eeh:
    The cell element.

:param cellName:
    New cell name.

:returns:
    SUCCESS if eeh is a CELL_HEADER_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

static const char * __doc_Bentley_DgnPlatform_NormalCellHeaderHandler_SetPointCell =R"doc(Set the given cell element's point cell status when creating a new
element.

:param eeh:
    The cell element.

:param isPointCell:
    New point cell status.

:returns:
    SUCCESS if eeh is a CELL_HEADER_ELM and element was updated.
    Bentley Systems +---------------+---------------+---------------+-
    --------------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CellHeaderHandler(py::module_& m)
    {
    //===================================================================================
    // struct Type2Handler
    py::class_<Type2Handler, ComplexHeaderDisplayHandler, ITransactionHandler> c1(m, "Type2Handler");

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<Type2Handler, py::nodelete>(&Type2Handler::GetInstance()); });
    c1.def_static("GetInstance", &Type2Handler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct NormalCellHeaderHandler
    py::class_ < NormalCellHeaderHandler, std::unique_ptr < NormalCellHeaderHandler, py::nodelete>, Type2Handler, ICellQuery> c2(m, "NormalCellHeaderHandler");

    c2.def_static("SetPointCell", &NormalCellHeaderHandler::SetPointCell, "eeh"_a, "isPointCell"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, SetPointCell));
    c2.def_static("SetName", &NormalCellHeaderHandler::SetName, "eeh"_a, "cellName"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, SetName));    
    c2.def_static("SetDescription", &NormalCellHeaderHandler::SetDescription, "eeh"_a, "descr"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, SetDescription));    
    c2.def_static("CreateGroupCellElement", &NormalCellHeaderHandler::CreateGroupCellElement, "eeh"_a, "agenda"_a, "cellName"_a = nullptr, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, CreateGroupCellElement));    
    c2.def_static("CreateOrphanCellElement", &NormalCellHeaderHandler::CreateOrphanCellElement, "eeh"_a, "cellName"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, CreateOrphanCellElement));    
    c2.def_static("CreateCellElement", &NormalCellHeaderHandler::CreateCellElement, "eeh"_a, "cellName"_a, "origin"_a, "rMatrix"_a, "is3d"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, CreateCellElement));    
    c2.def_static("AddChildElement", &NormalCellHeaderHandler::AddChildElement, "eeh"_a, "childEeh"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, AddChildElement));    
    c2.def_static("AddChildComplete", &NormalCellHeaderHandler::AddChildComplete, "eeh"_a, DOC(Bentley, DgnPlatform, NormalCellHeaderHandler, AddChildComplete));
    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<NormalCellHeaderHandler, py::nodelete>(&NormalCellHeaderHandler::GetInstance()); });
    c2.def_static("GetInstance", &NormalCellHeaderHandler::GetInstance, py::return_value_policy::reference);

    }