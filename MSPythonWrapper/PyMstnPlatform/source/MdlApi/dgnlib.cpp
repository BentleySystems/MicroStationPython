/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\dgnlib.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/dgnlib.h>


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_dgnlib(py::module_& m)
{
    //===================================================================================
    // Enum DgnLibSelector
    py::enum_<DgnLibSelector>(m, "DgnLibSelector", py::arithmetic())
        .value("eNone", DgnLibSelector::None)
        .value("eElementStyles", DgnLibSelector::ElementStyles)
        .value("eRendering", DgnLibSelector::Rendering)
        .value("eLinks", DgnLibSelector::Links)
        .value("ePrinting", DgnLibSelector::Printing)
        .value("eClashDetection", DgnLibSelector::ClashDetection)
        .value("eGuiLibs", DgnLibSelector::GuiLibs)
        .value("eSystemGuiLibs", DgnLibSelector::SystemGuiLibs)
        .value("eSystem", DgnLibSelector::System)
        .value("eLevelsOnly", DgnLibSelector::LevelsOnly)
        .value("eTextFavoritesOnly", DgnLibSelector::TextFavoritesOnly)
        .value("eTextStylesOnly", DgnLibSelector::TextStylesOnly)
        .value("eDimensionStylesOnly", DgnLibSelector::DimensionStylesOnly)
        .value("eDisplayStylesOnly", DgnLibSelector::DisplayStylesOnly)
        .value("eDrawingSeedsOnly", DgnLibSelector::DrawingSeedsOnly)
        .value("eLineStylesOnly", DgnLibSelector::LineStylesOnly)
        .value("eDetailingSymbolStylesOnly", DgnLibSelector::DetailingSymbolStylesOnly)
        .value("eElementTemplatesOnly", DgnLibSelector::ElementTemplatesOnly)
        .value("eItemTypesOnly", DgnLibSelector::ItemTypesOnly)
        .value("eNamedExpressions", DgnLibSelector::NamedExpressions)
        .export_values();
}