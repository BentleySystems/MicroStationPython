/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\displayhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DisplayHandler.h>




/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DisplayHandler(py::module_& m)
    {
    //===================================================================================
    // struct DisplayHandler
    py::class_< DisplayHandler
        , std::unique_ptr<DisplayHandler, py::nodelete>
        , Handler> c1(m, "DisplayHandler");

    c1.def("GetPathDescription", &DisplayHandler::GetPathDescription, "eh"_a, "string"_a, "path"_a, "levelStr"_a, "modelStr"_a, "groupStr"_a, "delimiterStr"_a);
    c1.def("GetTransformOrigin", &DisplayHandler::GetTransformOrigin, "eh"_a, "origin"_a);
    c1.def("GetSnapOrigin", &DisplayHandler::GetSnapOrigin, "eh"_a, "origin"_a);
    c1.def("GetOrientation", &DisplayHandler::GetOrientation, "eh"_a, "orientation"_a);
    c1.def("GetBasisTransform", &DisplayHandler::GetBasisTransform, "eh"_a, "transform"_a);
    c1.def("GetBasisRange", &DisplayHandler::GetBasisRange, "eh"_a, "range"_a);
    c1.def("SetBasisRange", &DisplayHandler::SetBasisRange, "eeh"_a, "range"_a);
    c1.def("SetBasisTransform", &DisplayHandler::SetBasisTransform, "eeh"_a, "transform"_a);
    c1.def_static("InitializeBasis", &DisplayHandler::InitializeBasis, "eeh"_a, "transform"_a, "range"_a);
    c1.def("IsRenderable", &DisplayHandler::IsRenderable, "eh"_a);
    c1.def("IsPlanar", &DisplayHandler::IsPlanar, "eh"_a, "normal"_a, "point"_a, "inputDefaultNormal"_a);
    c1.def("IsVisible", &DisplayHandler::IsVisible, "eh"_a, "context"_a, "testRange"_a, "testLevel"_a, "testClass"_a);
    c1.def("Drop", &DisplayHandler::Drop, "eh"_a, "dropGeom"_a, "geometry"_a);
    c1.def("CalcElementRange", &DisplayHandler::CalcElementRange, "eh"_a, "range"_a, "transform"_a);
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr<DisplayHandler, py::nodelete>(&DisplayHandler::GetInstance()); });
    c1.def_static("GetInstance", &DisplayHandler::GetInstance, py::return_value_policy::reference);

    }