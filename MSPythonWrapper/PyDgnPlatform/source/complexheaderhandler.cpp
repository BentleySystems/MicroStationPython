/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\complexheaderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ComplexHeaderHandler.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ComplexHeaderHandler(py::module_& m)
    {
    //===================================================================================
    // struct ComplexHeaderDisplayHandler
    py::class_< ComplexHeaderDisplayHandler, DisplayHandler> c1(m, "ComplexHeaderDisplayHandler");

    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<ComplexHeaderDisplayHandler, py::nodelete>(&ComplexHeaderDisplayHandler::GetInstance()); });
    c1.def_static("GetInstance", &ComplexHeaderDisplayHandler::GetInstance, py::return_value_policy::reference);
    }