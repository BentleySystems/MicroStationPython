/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msmodel.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msmodel.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msmodel(py::module_& m)
{
    //===================================================================================
    // Enum ModelChangeType
    py::enum_<ModelChangeType>(m, "ModelChangeType", py::arithmetic())
        .value("eMODEL_CHANGE_Create", ModelChangeType::MODEL_CHANGE_Create)
        .value("eMODEL_CHANGE_Delete", ModelChangeType::MODEL_CHANGE_Delete)
        .value("eMODEL_CHANGE_Properties", ModelChangeType::MODEL_CHANGE_Properties)
        .value("eMODEL_CHANGE_Settings", ModelChangeType::MODEL_CHANGE_Settings)
        .value("eMODEL_CHANGE_Active", ModelChangeType::MODEL_CHANGE_Active)
        .value("eMODEL_CHANGE_BeforeDelete", ModelChangeType::MODEL_CHANGE_BeforeDelete)
        .value("eMODEL_CHANGE_UnCreate", ModelChangeType::MODEL_CHANGE_UnCreate)
        .value("eMODEL_CHANGE_UnDelete", ModelChangeType::MODEL_CHANGE_UnDelete)
        .value("eMODEL_CHANGE_BeforeUnCreate", ModelChangeType::MODEL_CHANGE_BeforeUnCreate)
        .value("eMODEL_CHANGE_Name", ModelChangeType::MODEL_CHANGE_Name)
        .value("eMODEL_CHANGE_BeforeActive", ModelChangeType::MODEL_CHANGE_BeforeActive)
        .value("eMODEL_CHANGE_BeforeName", ModelChangeType::MODEL_CHANGE_BeforeName)
        .value("eMODEL_CHANGE_BeforeSettings", ModelChangeType::MODEL_CHANGE_BeforeSettings)
        .value("eMODEL_CHANGE_BeforeProperties", ModelChangeType::MODEL_CHANGE_BeforeProperties)
        .value("eMODEL_CHANGE_BeforeCreate", ModelChangeType::MODEL_CHANGE_BeforeCreate)
        .value("eMODEL_CHANGE_BeforeUnDelete", ModelChangeType::MODEL_CHANGE_BeforeUnDelete)
        .value("eMODEL_CHANGE_PropagateAnnotationScale", ModelChangeType::MODEL_CHANGE_PropagateAnnotationScale)
        .value("eMODEL_CHANGE_BeforeCopy", ModelChangeType::MODEL_CHANGE_BeforeCopy)
        .value("eMODEL_CHANGE_Copied", ModelChangeType::MODEL_CHANGE_Copied)
        .value("eMODEL_CHANGE_BeforeUndoProperties", ModelChangeType::MODEL_CHANGE_BeforeUndoProperties)
        .value("eMODEL_CHANGE_UndoProperties", ModelChangeType::MODEL_CHANGE_UndoProperties)
        .export_values();
}