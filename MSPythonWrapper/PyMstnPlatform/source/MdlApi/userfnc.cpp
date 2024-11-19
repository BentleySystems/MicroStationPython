/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\userfnc.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/userfnc.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_userfnc(py::module_& m)
{
    //===================================================================================
    // Enum FenceChangedType
    py::enum_<FenceChangedType>(m, "FenceChangedType", py::arithmetic())
        .value("eSYSTEM_FENCE_CLEARED", FenceChangedType::SYSTEM_FENCE_CLEARED)
        .value("eSYSTEM_FENCE_CREATED", FenceChangedType::SYSTEM_FENCE_CREATED)
        .export_values();
}