/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\viewgroup.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/viewgroup.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_viewgroup(py::module_& m)
{
    //===================================================================================
    // Enum ViewGroupChangeType
    py::enum_<ViewGroupChangeType>(m, "ViewGroupChangeType", py::arithmetic())
        .value("eVIEWGROUP_CACHE_CHANGE_CREATE", ViewGroupChangeType::VIEWGROUP_CACHE_CHANGE_CREATE)
        .value("eVIEWGROUP_CACHE_CHANGE_DELETE", ViewGroupChangeType::VIEWGROUP_CACHE_CHANGE_DELETE)
        .value("eVIEWGROUP_CACHE_CHANGE_PROPERTY_EDIT", ViewGroupChangeType::VIEWGROUP_CACHE_CHANGE_PROPERTY_EDIT)
        .value("eVIEWGROUP_CACHE_CHANGE_ACTIVATE", ViewGroupChangeType::VIEWGROUP_CACHE_CHANGE_ACTIVATE)
        .value("eVIEWGROUP_CACHE_CHANGE_REDIRECT", ViewGroupChangeType::VIEWGROUP_CACHE_CHANGE_REDIRECT)
        .export_values();
}