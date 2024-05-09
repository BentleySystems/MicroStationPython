/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ixdatanodehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

typedef struct IXDataTreeTransactionListener IXDataTreeTransactionListener;
#include <DgnPlatform/IXDataNodeHandler.h>




/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IXDataNodeHandler(py::module_& m)
    {

    //===================================================================================
    //struct IXDataNodeHandler
    py::class_< IXDataNodeHandler
        , std::unique_ptr< IXDataNodeHandler, py::nodelete>        
        , Handler
    > c3(m, "IXDataNodeHandler", py::multiple_inheritance());

    c3.def("GetDescription", &IXDataNodeHandler::GetDescription, "el"_a, "string"_a, "desiredLength"_a);
    c3.def("CreateNode", &IXDataNodeHandler::CreateNode, "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);
    
    c3.def_property_readonly("InternalName", &IXDataNodeHandler::GetInternalName);
    c3.def("GetInternalName", &IXDataNodeHandler::GetInternalName);
    
    c3.def_property_readonly("HandlerID", &IXDataNodeHandler::GetHandlerID);
    c3.def("GetHandlerID", &IXDataNodeHandler::GetHandlerID);
    
    c3.def("AllowDuplicateSeparatorNames", &IXDataNodeHandler::AllowDuplicateSeparatorNames);
    }