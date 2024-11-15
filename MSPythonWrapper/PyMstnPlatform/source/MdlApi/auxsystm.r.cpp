/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\auxsystm.r.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/auxsystm.r.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_auxsystm_r(py::module_& m)
{
    //===================================================================================
    // Enum AcsChangeType
    py::enum_<AcsChangeType>(m, "AcsChangeType", py::arithmetic())
        .value("eACS_CHANGE_SAVE", AcsChangeType::ACS_CHANGE_SAVE)
        .value("eACS_CHANGE_DELETE", AcsChangeType::ACS_CHANGE_DELETE)
        .value("eACS_CHANGE_REWRITE", AcsChangeType::ACS_CHANGE_REWRITE)
        .value("eACS_SYNCH_TO_DATA", AcsChangeType::ACS_SYNCH_TO_DATA)
        .export_values();
}