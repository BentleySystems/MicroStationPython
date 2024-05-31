/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\brepcellhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/BRepCellHandler.h>
#include <DgnPlatform/DgnStoreHandlers.h>



static const char * __doc_Bentley_DgnPlatform_BrepCellHeaderHandler_CreateBRepCellElement =R"doc(Create a new BRep cell from the supplied ISolidKernelEntity.

Parameter ``eeh``:
    The new element.

Parameter ``templateEh``:
    Optional template element.

Parameter ``entity``:
    The brep data.

Parameter ``modelRef``:
    Model to associate this element with. Will be returned from
    eeh.GetModelRef () and later used by AddChildComplete to update
    the cell's range.

Remark:
    s Requires host implementation of SolidsKernelAdmin.

Returns:
    SUCCESS if a valid element is created and range was sucessfully
    calculated. Bentley Systems +---------------+---------------+-----
    ----------+---------------+---------------+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BRepCellHandler(py::module_& m)
    {
    //===================================================================================
    // struct BrepCellHeaderHandler
    py::class_< 
        BrepCellHeaderHandler
        ,Type2Handler
        ,IBRepEdit
    > c1(m, "BrepCellHeaderHandler", py::multiple_inheritance());

    c1.def_static("CreateBRepCellElement", &BrepCellHeaderHandler::CreateBRepCellElement, "eeh"_a, "templateEh"_a, "entity"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, BrepCellHeaderHandler, CreateBRepCellElement)); 

    c1.def_static("GetInstance", &BrepCellHeaderHandler::GetInstance, py::return_value_policy::reference);
    }
