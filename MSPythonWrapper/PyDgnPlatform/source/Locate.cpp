/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\Locate.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/Locate.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       8/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Locate(py::module_& m)
    {
    //===================================================================================
    // enum class LOCATE_Action
    py::enum_< LOCATE_Action>(m, "LOCATE_Action")
        .value("eGLOBAL_LOCATE_IDENTIFY"    , LOCATE_Action::GLOBAL_LOCATE_IDENTIFY)
        .value("eGLOBAL_LOCATE_SELECTIONSET", LOCATE_Action::GLOBAL_LOCATE_SELECTIONSET)
        .value("eGLOBAL_LOCATE_FENCE"       , LOCATE_Action::GLOBAL_LOCATE_FENCE)
        .value("eGLOBAL_LOCATE_FENCECLIP"   , LOCATE_Action::GLOBAL_LOCATE_FENCECLIP)
        .value("eGLOBAL_LOCATE_SNAP"        , LOCATE_Action::GLOBAL_LOCATE_SNAP)
        .value("eGLOBAL_LOCATE_AUTOLOCATE"  , LOCATE_Action::GLOBAL_LOCATE_AUTOLOCATE)
        .export_values();

    //===================================================================================
    // enum class LocateFilterStatus
    py::enum_< LocateFilterStatus>(m, "LocateFilterStatus")
        .value("eLOCATE_FILTER_STATUS_Reject" , LocateFilterStatus::LOCATE_FILTER_STATUS_Reject)
        .value("eLOCATE_FILTER_STATUS_Neutral", LocateFilterStatus::LOCATE_FILTER_STATUS_Neutral)
        .value("eLOCATE_FILTER_STATUS_Accept" , LocateFilterStatus::LOCATE_FILTER_STATUS_Accept)
        .export_values();
    }
