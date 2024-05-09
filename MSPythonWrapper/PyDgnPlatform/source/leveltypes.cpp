/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\leveltypes.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/LevelTypes.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_LevelTypes(py::module_& m)
    {
    //===================================================================================
    // Level Table Flags Defines

    //===================================================================================
    // Level ID defines
    m.attr("LEVEL_NULL_ID") = LEVEL_NULL_ID;
    m.attr("LEVEL_DEFAULT_LEVEL_ID") = LEVEL_DEFAULT_LEVEL_ID;
    m.attr("LEVEL_NULL_CODE") = LEVEL_NULL_CODE;
    m.attr("LEVEL_DEFAULT_LEVEL_CODE") = LEVEL_DEFAULT_LEVEL_CODE;
    m.attr("LEVEL_DICT_NULL_ID") = LEVEL_DICT_NULL_ID;

    //===================================================================================
    // Assign an index for each level attribute, //<used by the compare/copy
    // function to enable incremental comparison/copy
    m.attr("LEVEL_ID_ATTRIBUTE") = LEVEL_ID_ATTRIBUTE;
    m.attr("LEVEL_CREATE_TIME_STAMP_ATTRIBUTE") = LEVEL_CREATE_TIME_STAMP_ATTRIBUTE;
    m.attr("LEVEL_CODE_ATTRIBUTE") = LEVEL_CODE_ATTRIBUTE;
    m.attr("LEVEL_NAME_ATTRIBUTE") = LEVEL_NAME_ATTRIBUTE;
    m.attr("LEVEL_DESCRIPTION_ATTRIBUTE") = LEVEL_DESCRIPTION_ATTRIBUTE;
    m.attr("LEVEL_COLOR_ATTRIBUTE") = LEVEL_COLOR_ATTRIBUTE;
    m.attr("LEVEL_STYLE_ATTRIBUTE") = LEVEL_STYLE_ATTRIBUTE;
    m.attr("LEVEL_WEIGHT_ATTRIBUTE") = LEVEL_WEIGHT_ATTRIBUTE;
    m.attr("LEVEL_ELEMENT_COLOR_ATTRIBUTE") = LEVEL_ELEMENT_COLOR_ATTRIBUTE;
    m.attr("LEVEL_ELEMENT_STYLE_ATTRIBUTE") = LEVEL_ELEMENT_STYLE_ATTRIBUTE;
    m.attr("LEVEL_ELEMENT_WEIGHT_ATTRIBUTE") = LEVEL_ELEMENT_WEIGHT_ATTRIBUTE;
    m.attr("LEVEL_PLOTSTYLE_ATTRIBUTE") = LEVEL_PLOTSTYLE_ATTRIBUTE;
    m.attr("LEVEL_ELEMENT_ACCESS_ATTRIBUTE") = LEVEL_ELEMENT_ACCESS_ATTRIBUTE;
    m.attr("LEVEL_COLOR_OVERRIDE_ATTRIBUTE") = LEVEL_COLOR_OVERRIDE_ATTRIBUTE;
    m.attr("LEVEL_STYLE_OVERRIDE_ATTRIBUTE") = LEVEL_STYLE_OVERRIDE_ATTRIBUTE;
    m.attr("LEVEL_WEIGHT_OVERRIDE_ATTRIBUTE") = LEVEL_WEIGHT_OVERRIDE_ATTRIBUTE;
    m.attr("LEVEL_DISPLAY_ATTRIBUTE") = LEVEL_DISPLAY_ATTRIBUTE;
    m.attr("LEVEL_PLOT_ATTRIBUTE") = LEVEL_PLOT_ATTRIBUTE;
    m.attr("LEVEL_EXTERNAL_ATTRIBUTE") = LEVEL_EXTERNAL_ATTRIBUTE;
    m.attr("LEVEL_BYCELL_ATTRIBUTE") = LEVEL_BYCELL_ATTRIBUTE;
    m.attr("LEVEL_HIDDEN_ATTRIBUTE") = LEVEL_HIDDEN_ATTRIBUTE;
    m.attr("LEVEL_READ_ONLY_ATTRIBUTE") = LEVEL_READ_ONLY_ATTRIBUTE;
    m.attr("LEVEL_SNAP_ATTRIBUTE") = LEVEL_SNAP_ATTRIBUTE;
    m.attr("LEVEL_FROZEN_ATTRIBUTE") = LEVEL_FROZEN_ATTRIBUTE;
    m.attr("LEVEL_CUSTOM_STYLE_FROM_MASTER_ATTRIBUTE") = LEVEL_CUSTOM_STYLE_FROM_MASTER_ATTRIBUTE;
    m.attr("LEVEL_DISPLAY_PRIORITY_ATTRIBUTE") = LEVEL_DISPLAY_PRIORITY_ATTRIBUTE;
    m.attr("LEVEL_TRANSPARENCY_ATTRIBUTE") = LEVEL_TRANSPARENCY_ATTRIBUTE;
    m.attr("LEVEL_COLOR_BOOK_FROM_MASTER_ATTRIBUTE") = LEVEL_COLOR_BOOK_FROM_MASTER_ATTRIBUTE;
    m.attr("LEVEL_MATERIAL_ATTRIBUTE") = LEVEL_MATERIAL_ATTRIBUTE;
    m.attr("LEVEL_ELEMENT_MATERIAL_ATTRIBUTE") = LEVEL_ELEMENT_MATERIAL_ATTRIBUTE;
    m.attr("LEVEL_MATERIAL_OVERRIDE_ATTRIBUTE") = LEVEL_MATERIAL_OVERRIDE_ATTRIBUTE;
    m.attr("LEVEL_LOCATE_ATTRIBUTE") = LEVEL_LOCATE_ATTRIBUTE;

    //===================================================================================
    // enum class LevelElementAccess
    py::enum_< LevelElementAccess>(m, "LevelElementAccess")
        .value("eAll", LevelElementAccess::All)
        .value("eLocked", LevelElementAccess::Locked)
        .value("eReadOnly", LevelElementAccess::ReadOnly)
        .value("eViewOnly", LevelElementAccess::ViewOnly)
        .export_values();
    }