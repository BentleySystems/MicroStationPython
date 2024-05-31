/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msinput.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msinput.fdf>
#include <Mstn/PythonMacro/PyCommandState.h>


USING_NAMESPACE_BENTLEY_MSTNPLATFORM
/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      3/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_mscommandstate(py::module_& m)
    {
    py::class_<PyCommandState> c1 (m, "PyCommandState");
    c1.def_static ("StartDefaultCommand", &PyCommandState::StartDefaultCommand);
    }