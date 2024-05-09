/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\hudmarker.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/HUDMarker.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_HUDMarker(py::module_& m)
    {
    //===================================================================================
    // struct HUDMarkerTreeNode
    py::class_< HUDMarkerTreeNode, std::unique_ptr< HUDMarkerTreeNode, py::nodelete> > c1(m, "HUDMarkerTreeNode");

    //===================================================================================
    // struct HUDMarkerCategory
    py::class_< HUDMarkerCategory, HUDMarkerTreeNode> c2(m, "HUDMarkerCategory");
    }