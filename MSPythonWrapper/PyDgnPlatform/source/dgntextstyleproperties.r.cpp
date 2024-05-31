/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgntextstyleproperties.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnTextStyleProperties.r.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnTextStyleProperties_r(py::module_& m)
    {
    //===================================================================================
    // enum TextStyleProperty
    py::enum_< TextStyleProperty>(m, "TextStyleProperty", py::arithmetic())
        .value("eTextStyle_InvalidProperty", TextStyle_InvalidProperty)
        .value("eTextStyle_Color", TextStyle_Color)
        .value("eTextStyle_ColorFlag", TextStyle_ColorFlag)
        .value("eTextStyle_Font", TextStyle_Font)
        .value("eTextStyle_ShxBigFont", TextStyle_ShxBigFont)
        .value("eTextStyle_Width", TextStyle_Width)
        .value("eTextStyle_Height", TextStyle_Height)
        .value("eTextStyle_Slant", TextStyle_Slant)
        .value("eTextStyle_Underline", TextStyle_Underline)
        .value("eTextStyle_Overline", TextStyle_Overline)
        .value("eTextStyle_Italics", TextStyle_Italics)
        .value("eTextStyle_Bold", TextStyle_Bold)
        .value("eTextStyle_Superscript", TextStyle_Superscript)
        .value("eTextStyle_Subscript", TextStyle_Subscript)
        .value("eTextStyle_Backgroundstyleflag", TextStyle_Backgroundstyleflag)
        .value("eTextStyle_Backgroundstyle", TextStyle_Backgroundstyle)
        .value("eTextStyle_Backgroundweight", TextStyle_Backgroundweight)
        .value("eTextStyle_Backgroundcolor", TextStyle_Backgroundcolor)
        .value("eTextStyle_Backgroundfillcolor", TextStyle_Backgroundfillcolor)
        .value("eTextStyle_Backgroundborder", TextStyle_Backgroundborder)
        .value("eTextStyle_Underlinestyle", TextStyle_Underlinestyle)
        .value("eTextStyle_Underlineweight", TextStyle_Underlineweight)
        .value("eTextStyle_Underlinecolor", TextStyle_Underlinecolor)
        .value("eTextStyle_Underlinestyleflag", TextStyle_Underlinestyleflag)
        .value("eTextStyle_UnderlineOffset", TextStyle_UnderlineOffset)
        .value("eTextStyle_Overlinestyle", TextStyle_Overlinestyle)
        .value("eTextStyle_Overlineweight", TextStyle_Overlineweight)
        .value("eTextStyle_Overlinecolor", TextStyle_Overlinecolor)
        .value("eTextStyle_Overlinestyleflag", TextStyle_Overlinestyleflag)
        .value("eTextStyle_OverlineOffset", TextStyle_OverlineOffset)
        .value("eTextStyle_LineSpacing", TextStyle_LineSpacing)
        .value("eTextStyle_FixedSpacing", TextStyle_FixedSpacing)
        .value("eTextStyle_LineOffset", TextStyle_LineOffset)
        .value("eTextStyle_InterCharSpacing", TextStyle_InterCharSpacing)
        .value("eTextStyle_LineSpacingType", TextStyle_LineSpacingType)
        .value("eTextStyle_AcadInterCharSpacing", TextStyle_AcadInterCharSpacing)
        .value("eTextStyle_Justification", TextStyle_Justification)
        .value("eTextStyle_FullJustification", TextStyle_FullJustification)
        .value("eTextStyle_LineLength", TextStyle_LineLength)
        .value("eTextStyle_Backwards", TextStyle_Backwards)
        .value("eTextStyle_Upsidedown", TextStyle_Upsidedown)
        .value("eTextStyle_Fractions", TextStyle_Fractions)
        .value("eTextStyle_Vertical", TextStyle_Vertical)
        .value("eTextStyle_RightToLeft", TextStyle_RightToLeft)
        .export_values();
    }