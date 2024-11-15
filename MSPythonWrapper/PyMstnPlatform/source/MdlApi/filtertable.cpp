/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\filtertable.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/filtertable.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_filtertable(py::module_& m)
{
    //===================================================================================
    // Enum FilterChangeType
    py::enum_<FilterChangeType>(m, "FilterChangeType", py::arithmetic())
        .value("eFILTER_TABLE_CHANGE", FilterChangeType::FILTER_TABLE_CHANGE)
        .value("eFILTER_CHANGE_ACTIVE", FilterChangeType::FILTER_CHANGE_ACTIVE)
        .value("eFILTER_CREATE", FilterChangeType::FILTER_CREATE)
        .value("eFILTER_DELETE", FilterChangeType::FILTER_DELETE)
        .value("eFILTER_CHANGE_NAME", FilterChangeType::FILTER_CHANGE_NAME)
        .value("eFILTER_CHANGE_DESCRIPTION", FilterChangeType::FILTER_CHANGE_DESCRIPTION)
        .value("eFILTER_CHANGE_TYPE", FilterChangeType::FILTER_CHANGE_TYPE)
        .value("eFILTER_CHANGE_PERSISTENT", FilterChangeType::FILTER_CHANGE_PERSISTENT)
        .value("eFILTER_CHANGE_FLAG", FilterChangeType::FILTER_CHANGE_FLAG)
        .value("eFILTER_CHANGE_PARENT", FilterChangeType::FILTER_CHANGE_PARENT)
        .value("eFILTER_CHANGE_EXPRESSION", FilterChangeType::FILTER_CHANGE_EXPRESSION)
        .value("eFILTER_TABLE_IMPORT", FilterChangeType::FILTER_TABLE_IMPORT)
        .value("eFILTER_TABLE_UNDO", FilterChangeType::FILTER_TABLE_UNDO)
        .value("eFILTER_TABLE_REDO", FilterChangeType::FILTER_TABLE_REDO)
        .export_values();
}