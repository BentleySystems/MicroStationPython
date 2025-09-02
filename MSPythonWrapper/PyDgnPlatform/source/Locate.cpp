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
    // enum class ComponentMode
    py::enum_< ComponentMode>(m, "ComponentMode")
        .value("eNone", ComponentMode::None)
        .value("eInnermost", ComponentMode::Innermost)
        .value("eNormalChild", ComponentMode::NormalChild)
        .value("eSharedChild", ComponentMode::SharedChild)
        .export_values();

    //===================================================================================
    // enum class TestPathStatus
    py::enum_< TestPathStatus>(m, "TstPathStatus")
        .value("eTESTPATH_NotOnPath", TestPathStatus::TESTPATH_NotOnPath)
        .value("eTESTPATH_IsOnPath", TestPathStatus::TESTPATH_IsOnPath)
        .value("eTESTPATH_TestAborted", TestPathStatus::TESTPATH_TestAborted)
        .export_values();

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

    //===================================================================================
    // enum class LocateFailureValue
    py::enum_< LocateFailureValue>(m, "LocateFailureValue")
    .value("eLOCATE_FAILURE_None", LocateFailureValue::LOCATE_FAILURE_None)
    .value("eLOCATE_FAILURE_NoElements", LocateFailureValue::LOCATE_FAILURE_NoElements)
    .value("eLOCATE_FAILURE_LockedFile", LocateFailureValue::LOCATE_FAILURE_LockedFile)
    .value("eLOCATE_FAILURE_LevelLock", LocateFailureValue::LOCATE_FAILURE_LevelLock)
    .value("eLOCATE_FAILURE_LockedElem", LocateFailureValue::LOCATE_FAILURE_LockedElem)
    .value("eLOCATE_FAILURE_LockedLevel", LocateFailureValue::LOCATE_FAILURE_LockedLevel)
    .value("eLOCATE_FAILURE_ViewOnly", LocateFailureValue::LOCATE_FAILURE_ViewOnly)
    .value("eLOCATE_FAILURE_ByApp", LocateFailureValue::LOCATE_FAILURE_ByApp)
    .value("eLOCATE_FAILURE_ByCommand", LocateFailureValue::LOCATE_FAILURE_ByCommand)
    .value("eLOCATE_FAILURE_ByType", LocateFailureValue::LOCATE_FAILURE_ByType)
    .value("eLOCATE_FAILURE_ByProperties", LocateFailureValue::LOCATE_FAILURE_ByProperties)
    .value("eLOCATE_FAILURE_Transient", LocateFailureValue::LOCATE_FAILURE_Transient)
    .value("eLOCATE_FAILURE_FileNotAllowed", LocateFailureValue::LOCATE_FAILURE_FileNotAllowed)
    .value("eLOCATE_FAILURE_FileReadOnly", LocateFailureValue::LOCATE_FAILURE_FileReadOnly)
    .value("eLOCATE_FAILURE_RefernceFile", LocateFailureValue::LOCATE_FAILURE_RefernceFile)
    .value("eLOCATE_FAILURE_NotSnappable", LocateFailureValue::LOCATE_FAILURE_NotSnappable)
    .value("eLOCATE_FAILURE_NonSnappableRef", LocateFailureValue::LOCATE_FAILURE_NonSnappableRef)
    .value("eLOCATE_FAILURE_ParentNoLocate", LocateFailureValue::LOCATE_FAILURE_ParentNoLocate)
    .value("eLOCATE_FAILURE_RefNoRights", LocateFailureValue::LOCATE_FAILURE_RefNoRights)
    .value("eLOCATE_FAILURE_ParentRefNoRights", LocateFailureValue::LOCATE_FAILURE_ParentRefNoRights)
    .value("eLOCATE_FAILURE_LockedComponent", LocateFailureValue::LOCATE_FAILURE_LockedComponent)
    .value("eLOCATE_FAILURE_NotInWorkingSet", LocateFailureValue::LOCATE_FAILURE_NotInWorkingSet)
    .value("eLOCATE_FAILURE_RejectedByElement", LocateFailureValue::LOCATE_FAILURE_RejectedByElement)
    .value("eLOCATE_FAILURE_NotInActiveRef", LocateFailureValue::LOCATE_FAILURE_NotInActiveRef)
    .value("eLOCATE_FAILURE_RefNotNowActive", LocateFailureValue::LOCATE_FAILURE_RefNotNowActive)
    .export_values();

    //===================================================================================
    // enum class SnapTypeEnum
    py::enum_< SnapTypeEnum>(m, "SnapTypeEnum")
        .value("eSNAP_TYPE_Points", SnapTypeEnum::SNAP_TYPE_Points)
        .value("eSNAP_TYPE_Constraints", SnapTypeEnum::SNAP_TYPE_Constraints)
        .export_values();
    }
