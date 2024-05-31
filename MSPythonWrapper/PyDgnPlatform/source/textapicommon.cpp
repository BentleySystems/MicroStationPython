/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textapicommon.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/TextAPICommon.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextAPICommon(py::module_& m)
    {
    //===================================================================================
    // enum class DgnLineSpacingType
    py::enum_< DgnLineSpacingType>(m, "DgnLineSpacingType")
        .value("eExact", DgnLineSpacingType::Exact)
        .value("eAutomatic", DgnLineSpacingType::Automatic)
        .value("eExactFromLineTop", DgnLineSpacingType::ExactFromLineTop)
        .value("eAtLeast", DgnLineSpacingType::AtLeast)
        .export_values();

    //===================================================================================
    // enum class StackedFractionAlignment
    py::enum_< StackedFractionAlignment>(m, "StackedFractionAlignment")
        .value("eBottom", StackedFractionAlignment::Bottom)
        .value("eMiddle", StackedFractionAlignment::Middle)
        .value("eTop", StackedFractionAlignment::Top)
        .value("eNone", StackedFractionAlignment::None)
        .export_values();

    //===================================================================================
    // enum class EdfJustification
    py::enum_< EdfJustification>(m, "EdfJustification")
        .value("eLeft", EdfJustification::Left)
        .value("eCenter", EdfJustification::Center)
        .value("eRight", EdfJustification::Right)
        .export_values();

    //===================================================================================
    // enum TextBlockToElementResult
    py::enum_< TextBlockToElementResult>(m, "TextBlockToElementResult", py::arithmetic())
        .value("eTEXTBLOCK_TO_ELEMENT_RESULT_Success", TEXTBLOCK_TO_ELEMENT_RESULT_Success)
        .value("eTEXTBLOCK_TO_ELEMENT_RESULT_Error", TEXTBLOCK_TO_ELEMENT_RESULT_Error)
        .value("eTEXTBLOCK_TO_ELEMENT_RESULT_Empty", TEXTBLOCK_TO_ELEMENT_RESULT_Empty)
        .export_values();
    }