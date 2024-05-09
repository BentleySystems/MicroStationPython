/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnplatformlib.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnPlatformLib.h>
#include <PSolid/PSolidCoreAPI.h>




/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnPlatformLib(py::module_& m)
    {
    m.def("DgnPlatformFixture_Initialize", &DgnPlatformFixture_Initialize);
    }