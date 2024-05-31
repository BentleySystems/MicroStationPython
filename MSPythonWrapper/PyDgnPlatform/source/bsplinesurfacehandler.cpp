/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\bsplinesurfacehandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/BSplineSurfaceHandler.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BSplineSurfaceHandler(py::module_& m)
    {
    //===================================================================================
    // struct BSplineSurfaceHandler
    py::class_<
        BSplineSurfaceHandler,        
        ComplexHeaderDisplayHandler,
        IBsplineSurfaceEdit> c1(m, "BSplineSurfaceHandler");

    c1.def_static("IsValidSurface", &BSplineSurfaceHandler::IsValidSurface, "surface"_a);
    c1.def_static("CreateBSplineSurfaceElement", &BSplineSurfaceHandler::CreateBSplineSurfaceElement, "eeh"_a, "templateEh"_a, "surface"_a, "modelRef"_a);  
    
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<BSplineSurfaceHandler, py::nodelete>(&BSplineSurfaceHandler::GetInstance()); });
    c1.def_static("GetInstance", &BSplineSurfaceHandler::GetInstance, py::return_value_policy::reference);
    }
