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
    py::enum_<TextStyleProperty>(m, "TextStyleProperty")
        .value("eTextStyle_InvalidProperty", TextStyleProperty::TextStyle_InvalidProperty)
        .value("eTextStyle_Color", TextStyleProperty::TextStyle_Color)
        .value("eTextStyle_ColorFlag", TextStyleProperty::TextStyle_ColorFlag)
        .value("eTextStyle_Font", TextStyleProperty::TextStyle_Font)
        .value("eTextStyle_ShxBigFont", TextStyleProperty::TextStyle_ShxBigFont)
        .value("eTextStyle_Width", TextStyleProperty::TextStyle_Width)
        .value("eTextStyle_Height", TextStyleProperty::TextStyle_Height)
        .value("eTextStyle_Slant", TextStyleProperty::TextStyle_Slant)
        .value("eTextStyle_Underline", TextStyleProperty::TextStyle_Underline)
        .value("eTextStyle_Overline", TextStyleProperty::TextStyle_Overline)
        .value("eTextStyle_Italics", TextStyleProperty::TextStyle_Italics)
        .value("eTextStyle_Bold", TextStyleProperty::TextStyle_Bold)
        .value("eTextStyle_Superscript", TextStyleProperty::TextStyle_Superscript)
        .value("eTextStyle_Subscript", TextStyleProperty::TextStyle_Subscript)
        .value("eTextStyle_Backgroundstyleflag", TextStyleProperty::TextStyle_Backgroundstyleflag)
        .value("eTextStyle_Backgroundstyle", TextStyleProperty::TextStyle_Backgroundstyle)
        .value("eTextStyle_Backgroundweight", TextStyleProperty::TextStyle_Backgroundweight)
        .value("eTextStyle_Backgroundcolor", TextStyleProperty::TextStyle_Backgroundcolor)
        .value("eTextStyle_Backgroundfillcolor", TextStyleProperty::TextStyle_Backgroundfillcolor)
        .value("eTextStyle_Backgroundborder", TextStyleProperty::TextStyle_Backgroundborder)
        .value("eTextStyle_Underlinestyle", TextStyleProperty::TextStyle_Underlinestyle)
        .value("eTextStyle_Underlineweight", TextStyleProperty::TextStyle_Underlineweight)
        .value("eTextStyle_Underlinecolor", TextStyleProperty::TextStyle_Underlinecolor)
        .value("eTextStyle_Underlinestyleflag", TextStyleProperty::TextStyle_Underlinestyleflag)
        .value("eTextStyle_UnderlineOffset", TextStyleProperty::TextStyle_UnderlineOffset)
        .value("eTextStyle_Overlinestyle", TextStyleProperty::TextStyle_Overlinestyle)
        .value("eTextStyle_Overlineweight", TextStyleProperty::TextStyle_Overlineweight)
        .value("eTextStyle_Overlinecolor", TextStyleProperty::TextStyle_Overlinecolor)
        .value("eTextStyle_Overlinestyleflag", TextStyleProperty::TextStyle_Overlinestyleflag)
        .value("eTextStyle_OverlineOffset", TextStyleProperty::TextStyle_OverlineOffset)
        .value("eTextStyle_LineSpacing", TextStyleProperty::TextStyle_LineSpacing)
        .value("eTextStyle_FixedSpacing", TextStyleProperty::TextStyle_FixedSpacing)
        .value("eTextStyle_LineOffset", TextStyleProperty::TextStyle_LineOffset)
        .value("eTextStyle_InterCharSpacing", TextStyleProperty::TextStyle_InterCharSpacing)
        .value("eTextStyle_LineSpacingType", TextStyleProperty::TextStyle_LineSpacingType)
        .value("eTextStyle_AcadInterCharSpacing", TextStyleProperty::TextStyle_AcadInterCharSpacing)
        .value("eTextStyle_Justification", TextStyleProperty::TextStyle_Justification)
        .value("eTextStyle_FullJustification", TextStyleProperty::TextStyle_FullJustification)
        .value("eTextStyle_LineLength", TextStyleProperty::TextStyle_LineLength)
        .value("eTextStyle_Backwards", TextStyleProperty::TextStyle_Backwards)
        .value("eTextStyle_Upsidedown", TextStyleProperty::TextStyle_Upsidedown)
        .value("eTextStyle_Fractions", TextStyleProperty::TextStyle_Fractions)
        .value("eTextStyle_Vertical", TextStyleProperty::TextStyle_Vertical)
        .value("eTextStyle_RightToLeft", TextStyleProperty::TextStyle_RightToLeft)
        .export_values();
    }