/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\namespacemanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_Bentley.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_NameSpaceManager (py::module_& m)
    {
    PyNameSpaceManager::SetDefaultNameSpaceList();

    //===================================================================================
    //Struct PyNameSpaceManager
    py::class_< PyNameSpaceManager> c0(m, "PyNameSpaceManager");

    // Enum NameSpaceID
    py::enum_<PyNameSpaceManager::NameSpaceID>(c0, "NameSpaceID")
        .value("eBentley_DgnPlatform", PyNameSpaceManager::Bentley_DgnPlatform)
        .value("eBentley_DgnPlatform_Raster", PyNameSpaceManager::Bentley_DgnPlatform_Raster)
        .value("eBentley_Geometry", PyNameSpaceManager::Bentley_Geometry)
        .value("eBentley_GeoCoordinates", PyNameSpaceManager::Bentley_GeoCoordinates)
        .export_values();

    c0.def_static ("UsingNameSpace", &PyNameSpaceManager::UsingNameSpace, "namespaceID"_a);
    c0.def_static ("IsNameSpaceUsing", &PyNameSpaceManager::IsNameSpaceUsing, "namespaceID"_a);
    c0.def_static ("DelNameSpaceUsing", &PyNameSpaceManager::DelNameSpaceUsing, "namespaceID"_a);
    c0.def_static ("ClearNameSpaceUsing", &PyNameSpaceManager::ClearNameSpaceUsing);
    c0.def_static ("SetDefaultNameSpaceList", &PyNameSpaceManager::SetDefaultNameSpaceList);
    }
