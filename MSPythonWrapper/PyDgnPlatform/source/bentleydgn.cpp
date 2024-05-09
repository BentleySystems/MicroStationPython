/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\bentleydgn.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/BentleyDgn.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_BentleyDgn(py::module_& m)
    {
    //===================================================================================
    // enum class DgnModelSections
    py::enum_< DgnModelSections>(m, "DgnModelSections")
        .value("eNone", DgnModelSections::None)
        .value("eDictionary", DgnModelSections::Dictionary)
        .value("eControlElements", DgnModelSections::ControlElements)
        .value("eGraphicElements", DgnModelSections::GraphicElements)
        .value("eModel", DgnModelSections::Model)
        .value("eAll", DgnModelSections::All)
        .export_values();
    }