/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\heapzone.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <RmgrTools/ExportMacros.h>
#ifndef HeapZoneP
namespace Bentley { struct HeapZone; typedef struct HeapZone* HeapZoneP; }
#endif
#include <RmgrTools/Tools/HeapZone.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_HeapZone(py::module_& m)
    {
    //===================================================================================
    // struct HeapZone
    py::class_< HeapZone> c1(m, "HeapZone");    
    }