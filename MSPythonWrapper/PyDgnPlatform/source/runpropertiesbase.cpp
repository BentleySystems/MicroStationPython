/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\runpropertiesbase.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/RunPropertiesBase.h>



static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ApplyScale =R"doc(Scales all scalar values in this instace. This includes text size, as
well as spacing and offset attributes.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetWidthFactor =R"doc(Divides the height by the width to compute the effective width factor.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetFontSize =R"doc(Sets the size, in UORs, that the glyphs will be drawn.

See also:
    GetFontSize for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetFontSize =R"doc(Gets the size, in UORs, that the glyphs will be drawn.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetShouldIgnoreLSB =R"doc(Sets whether the left side bearing should be ignored when measuring
the text.

See also:
    ShouldIgnoreLSB for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ShouldIgnoreLSB =R"doc(True if the left side bearing should be ignored when measuring the
text. @note This should not normally be controlled; it is used for DWG
compatibility.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetIsSuperScript =R"doc(Sets whether the text should be drawn as superscript.

See also:
    IsSuperScript for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_IsSuperScript =R"doc(True is the text should be drawn as superscript. @note Superscript
text is automatically scaled and shifted to appear as superscript.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetIsSubScript =R"doc(Sets whether the text should be drawn as subscript.

See also:
    IsSubScript for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_IsSubScript =R"doc(True if the text should be drawn as subscript. @note Subscript text is
automatically scaled and shifted to appear as subscript.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetRunOffset =R"doc(Sets the run offset.

See also:
    GetRunOffset for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetRunOffset =R"doc(Gets the run offset. @note Run offset should not be manually adjusted
for fraction runs.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetBackgroundStyle =R"doc(Sets background style attributes. Pass NULL for any values you don't
wish to set; they will retain their current value.

See also:
    ShouldUseBackground for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetBackgroundStyle =R"doc(Gets background style attributes. Pass NULL for any values you don't
wish to receive.

See also:
    ShouldUseBackground for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetShouldUseBackground =R"doc(Sets if a background and border should be drawn behind the text.

See also:
    ShouldUseBackground for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ShouldUseBackground =R"doc(True if a background and border should be drawn behind the text.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetCharacterSpacingValue =R"doc(Sets the character spacing value.

See also:
    GetCharacterSpacingType for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetCharacterSpacingValue =R"doc(Gets the character spacing value

See also:
    GetCharacterSpacingType for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetCharacterSpacingType =R"doc(Sets the character spacing type.

See also:
    GetCharacterSpacingType for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetCharacterSpacingType =R"doc(Gets the character spacing type. @note A character spacing of
CharacterSpacingType::Absolute with a value of 0.0 is nominal
character spacing.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetOverlineOffset =R"doc(Sets the overline offset.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetOverlineOffset =R"doc(Gets the overline offset.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetOverlineStyle =R"doc(Sets overline style attributes. Pass NULL for any values you don't
wish to set; they will retain their current value.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetOverlineStyle =R"doc(Gets overline style attributes. Pass NULL for any values you don't
wish to receive.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetShouldUseOverlineStyle =R"doc(Sets if an overline style is specified.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ShouldUseOverlineStyle =R"doc(True if an overline style is specified.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetIsOverlined =R"doc(Sets if an overline should be drawn.

See also:
    IsOverlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_IsOverlined =R"doc(True if an overline should be drawn. @note If no overline style is
specified, the overline color / style / weight will be text color /
solid / 0.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetUnderlineOffset =R"doc(Sets the underline offset.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetUnderlineOffset =R"doc(Gets the underline offset.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetUnderlineStyle =R"doc(Sets underline style attributes. Pass NULL for any values you won't
wish to set; they will remain as-is.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetUnderlineStyle =R"doc(Gets underline style attributes. Pass NULL for any values you don't
wish to receive.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetShouldUseUnderlineStyle =R"doc(Sets if an underline style is specified.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ShouldUseUnderlineStyle =R"doc(True if an underline style is specified.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetIsUnderlined =R"doc(Sets if an underline should be drawn.

See also:
    IsUnderlined for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_IsUnderlined =R"doc(True if an underline should be drawn. @note If no underline style is
specified, the underline color / style / weight will be text color /
solid / 0.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetCustomSlantAngle =R"doc(Sets the custom slant angle.

See also:
    GetCustomSlantAngle for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetCustomSlantAngle =R"doc(Gets the custom slant angle.

See also:
    IsItalic for additional notes @note This is only used if the
    italic flag is also set.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ShouldUseItalicTypeface =R"doc(True if an italic typeface should be selected.

See also:
    IsItalic for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetIsItalic =R"doc(Sets if text should be drawn italic.

See also:
    IsItalic for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_IsItalic =R"doc(True if text should be drawn italicized. @note Italic text is normally
drawn with a geometric shear; however, TrueType-based text without a
custom slant angle will use its italic typeface instead. TrueType-
based text with a custom slant angle will use the nominal typeface
with a geometric shear.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetIsBold =R"doc(Sets if text should be drawn bold.

See also:
    IsBold for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_IsBold =R"doc(True if text should be drawn bold. @note This is only valid for
TrueType text, and selects the bold typeface when drawing.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetColor =R"doc(Sets the text color index.

See also:
    GetColor for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetColor =R"doc(Gets the text color index.

See also:
    HasColor since this value is optional @note Color indices are per-
    file. For TextString, this index will pass through to the view
    context, and effectively indicates what color to use out of the
    view root. For TextBlock, this color is in relation to the
    TextBlock's file (derived from its DGN cache). @note If color is
    not specified, it comes from the display header.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_ClearColor =R"doc(Clears the text color index and indicates that a color is no longer
specified.

See also:
    GetColor for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_HasColor =R"doc(True if a text color is specified.

See also:
    GetColor for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetBigFont =R"doc(Sets the 'big' font; can be NULL. The value is ignored if it is not an
SHX big font.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_SetFont =R"doc(Sets the 'normal' font. The value is ignored if it is an SHX big font.)doc";

static const char * __doc_Bentley_DgnPlatform_RunPropertiesBase_GetFont =R"doc(Gets the resolved 'normal' font. This instance will always have a font
object, even if it had to be resolved through fallback fonts.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RunPropertiesBase(py::module_& m)
    {
    //===================================================================================
    // struct RunPropertiesBase
    py::class_<RunPropertiesBase,  RefCountedPtr<RunPropertiesBase>> c1(m, "RunPropertiesBase");

    c1.def_property("Font", &RunPropertiesBase::GetFont, &RunPropertiesBase::SetFont);
    c1.def("GetFont", &RunPropertiesBase::GetFont, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetFont));
    c1.def("SetFont", &RunPropertiesBase::SetFont, "font"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetFont));
    
    c1.def_property("BigFont", &RunPropertiesBase::GetBigFontCP, &RunPropertiesBase::SetBigFont);
    c1.def("GetBigFont", &RunPropertiesBase::GetBigFontCP, py::return_value_policy::reference_internal);
    c1.def("SetBigFont", &RunPropertiesBase::SetBigFont, "font"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetBigFont));
    
    c1.def("HasColor", &RunPropertiesBase::HasColor, DOC(Bentley, DgnPlatform, RunPropertiesBase, HasColor));    
    c1.def("ClearColor", &RunPropertiesBase::ClearColor, DOC(Bentley, DgnPlatform, RunPropertiesBase, ClearColor));
    
    c1.def_property("Color", &RunPropertiesBase::GetColor, &RunPropertiesBase::SetColor);
    c1.def("GetColor", &RunPropertiesBase::GetColor, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetColor));
    c1.def("SetColor", &RunPropertiesBase::SetColor, "color"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetColor));
    
    c1.def_property("Bold", &RunPropertiesBase::IsBold, &RunPropertiesBase::SetIsBold);
    c1.def("IsBold", &RunPropertiesBase::IsBold, DOC(Bentley, DgnPlatform, RunPropertiesBase, IsBold));
    c1.def("SetIsBold", &RunPropertiesBase::SetIsBold, "bold"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetIsBold));
    
    c1.def_property("Italic", &RunPropertiesBase::IsItalic, &RunPropertiesBase::SetIsItalic);
    c1.def("IsItalic", &RunPropertiesBase::IsItalic, DOC(Bentley, DgnPlatform, RunPropertiesBase, IsItalic));
    c1.def("SetIsItalic", &RunPropertiesBase::SetIsItalic, "italic"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetIsItalic));
    
    c1.def("ShouldUseItalicTypeface", &RunPropertiesBase::ShouldUseItalicTypeface, DOC(Bentley, DgnPlatform, RunPropertiesBase, ShouldUseItalicTypeface));
    
    c1.def_property("CustomSlantAngle", &RunPropertiesBase::GetCustomSlantAngle, &RunPropertiesBase::SetCustomSlantAngle);
    c1.def("GetCustomSlantAngle", &RunPropertiesBase::GetCustomSlantAngle, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetCustomSlantAngle));
    c1.def("SetCustomSlantAngle", &RunPropertiesBase::SetCustomSlantAngle, "angle"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetCustomSlantAngle));
    
    c1.def_property("Underlined", &RunPropertiesBase::IsUnderlined, &RunPropertiesBase::SetIsUnderlined);
    c1.def("IsUnderlined", &RunPropertiesBase::IsUnderlined, DOC(Bentley, DgnPlatform, RunPropertiesBase, IsUnderlined));
    c1.def("SetIsUnderlined", &RunPropertiesBase::SetIsUnderlined, "underlined"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetIsUnderlined));
    
    c1.def_property("IsShouldUseUnderlineStyle", &RunPropertiesBase::ShouldUseUnderlineStyle, &RunPropertiesBase::SetShouldUseUnderlineStyle);
    c1.def("ShouldUseUnderlineStyle", &RunPropertiesBase::ShouldUseUnderlineStyle, DOC(Bentley, DgnPlatform, RunPropertiesBase, ShouldUseUnderlineStyle));
    c1.def("SetShouldUseUnderlineStyle", &RunPropertiesBase::SetShouldUseUnderlineStyle, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetShouldUseUnderlineStyle));
    
    c1.def("GetUnderlineStyle", [] (RunPropertiesBase const& self)
           {
           UInt32 color, weight;
           Int32 lineStyle;
           self.GetUnderlineStyle(&color, &lineStyle, &weight);
           return py::make_tuple(color, lineStyle, weight);
           }, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetUnderlineStyle));

    c1.def("SetUnderlineStyle",
        [](RunPropertiesBase& self, boost::optional<UInt32> color, boost::optional<Int32> lineStyle, boost::optional<UInt32> weight)
        {
            self.SetUnderlineStyle(color.get_ptr(), lineStyle.get_ptr(), weight.get_ptr());
        },
        "color"_a, "lineStyle"_a, "weight"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetUnderlineStyle));
    
    c1.def_property("UnderlineOffset", &RunPropertiesBase::GetUnderlineOffset, &RunPropertiesBase::SetUnderlineOffset);
    c1.def("GetUnderlineOffset", &RunPropertiesBase::GetUnderlineOffset, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetUnderlineOffset));
    c1.def("SetUnderlineOffset", &RunPropertiesBase::SetUnderlineOffset, "offset"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetUnderlineOffset));
    
    c1.def_property("Overlined", &RunPropertiesBase::IsOverlined, &RunPropertiesBase::SetIsOverlined);
    c1.def("IsOverlined", &RunPropertiesBase::IsOverlined, DOC(Bentley, DgnPlatform, RunPropertiesBase, IsOverlined));
    c1.def("SetIsOverlined", &RunPropertiesBase::SetIsOverlined, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetIsOverlined));
    
    c1.def_property("IsShouldUseOverlineStyle", &RunPropertiesBase::ShouldUseOverlineStyle, &RunPropertiesBase::SetShouldUseOverlineStyle);
    c1.def("ShouldUseOverlineStyle", &RunPropertiesBase::ShouldUseOverlineStyle, DOC(Bentley, DgnPlatform, RunPropertiesBase, ShouldUseOverlineStyle));
    c1.def("SetShouldUseOverlineStyle", &RunPropertiesBase::SetShouldUseOverlineStyle, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetShouldUseOverlineStyle));

    c1.def("GetOverlineStyle", [] (RunPropertiesBase const& self)
           {
           UInt32 color, weight;
           Int32 lineStyle;
           self.GetOverlineStyle(&color, &lineStyle, &weight);
           return py::make_tuple(color, lineStyle, weight);
           }, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetOverlineStyle));

    c1.def("SetOverlineStyle",
        [](RunPropertiesBase& self, boost::optional<UInt32> color, boost::optional<Int32> lineStyle, boost::optional<UInt32> weight)
        {
            self.SetOverlineStyle(color.get_ptr(), lineStyle.get_ptr(), weight.get_ptr());
        },
        "color"_a, "lineStyle"_a, "weight"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetOverlineStyle));

    c1.def_property("OverlineOffset", &RunPropertiesBase::GetOverlineOffset, &RunPropertiesBase::SetOverlineOffset);
    c1.def("GetOverlineOffset", &RunPropertiesBase::GetOverlineOffset, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetOverlineOffset));
    c1.def("SetOverlineOffset", &RunPropertiesBase::SetOverlineOffset, "offset"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetOverlineOffset));
    
    c1.def_property("CharacterSpacingType", &RunPropertiesBase::GetCharacterSpacingType, &RunPropertiesBase::SetCharacterSpacingType);
    c1.def("GetCharacterSpacingType", &RunPropertiesBase::GetCharacterSpacingType, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetCharacterSpacingType));
    c1.def("SetCharacterSpacingType", &RunPropertiesBase::SetCharacterSpacingType, "type"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetCharacterSpacingType));
    
    c1.def_property("CharacterSpacingValue", &RunPropertiesBase::GetCharacterSpacingValue, &RunPropertiesBase::SetCharacterSpacingValue);
    c1.def("GetCharacterSpacingValue", &RunPropertiesBase::GetCharacterSpacingValue, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetCharacterSpacingValue));
    c1.def("SetCharacterSpacingValue", &RunPropertiesBase::SetCharacterSpacingValue, "value"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetCharacterSpacingValue));
    
    c1.def_property("IsShouldUseBackground", &RunPropertiesBase::ShouldUseBackground, &RunPropertiesBase::SetShouldUseBackground);
    c1.def("ShouldUseBackground", &RunPropertiesBase::ShouldUseBackground, DOC(Bentley, DgnPlatform, RunPropertiesBase, ShouldUseBackground));
    c1.def("SetShouldUseBackground", &RunPropertiesBase::SetShouldUseBackground, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetShouldUseBackground));

    c1.def("GetBackgroundStyle", [] (RunPropertiesBase const& self)
           {
           UInt32 fillColor, borderColor, borderWeight;
           Int32 borderLineStyle;
           DPoint2d borderPadding;
           self.GetBackgroundStyle(&fillColor, &borderColor, &borderLineStyle, &borderWeight, &borderPadding);
           return py::make_tuple(fillColor, borderColor, borderLineStyle, borderWeight, borderPadding);
           }, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetBackgroundStyle));

    c1.def("SetBackgroundStyle",
        [](RunPropertiesBase& self, boost::optional<UInt32> fillColor, boost::optional<UInt32> borderColor, boost::optional<Int32> borderLineStyle, boost::optional<UInt32> borderWeight, DPoint2d const* borderPadding)
        {
            self.SetBackgroundStyle(fillColor.get_ptr(), borderColor.get_ptr(), borderLineStyle.get_ptr(), borderWeight.get_ptr(), borderPadding);
        },
        "fillColor"_a, "borderColor"_a, "borderLineStyle"_a, "borderWeight"_a, "borderPadding"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetBackgroundStyle));

    c1.def_property("RunOffset", &RunPropertiesBase::GetRunOffset, &RunPropertiesBase::SetRunOffset);
    c1.def("GetRunOffset", &RunPropertiesBase::GetRunOffset, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetRunOffset));
    c1.def("SetRunOffset", &RunPropertiesBase::SetRunOffset, "offset"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetRunOffset));
    
    c1.def_property("SubScript", &RunPropertiesBase::IsSubScript, &RunPropertiesBase::SetIsSubScript);
    c1.def("IsSubScript", &RunPropertiesBase::IsSubScript, DOC(Bentley, DgnPlatform, RunPropertiesBase, IsSubScript));
    c1.def("SetIsSubScript", &RunPropertiesBase::SetIsSubScript, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetIsSubScript));
    
    c1.def_property("SuperScript", &RunPropertiesBase::IsSuperScript, &RunPropertiesBase::SetIsSuperScript);
    c1.def("IsSuperScript", &RunPropertiesBase::IsSuperScript, DOC(Bentley, DgnPlatform, RunPropertiesBase, IsSuperScript));
    c1.def("SetIsSuperScript", &RunPropertiesBase::SetIsSuperScript, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetIsSuperScript));
    
    c1.def_property("IsShouldIgnoreLSB", &RunPropertiesBase::ShouldIgnoreLSB, &RunPropertiesBase::SetShouldIgnoreLSB);
    c1.def("ShouldIgnoreLSB", &RunPropertiesBase::ShouldIgnoreLSB, DOC(Bentley, DgnPlatform, RunPropertiesBase, ShouldIgnoreLSB));
    c1.def("SetShouldIgnoreLSB", &RunPropertiesBase::SetShouldIgnoreLSB, "newVal"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetShouldIgnoreLSB));
    
    c1.def_property("FontSize", &RunPropertiesBase::GetFontSize, &RunPropertiesBase::SetFontSize);
    c1.def("GetFontSize", &RunPropertiesBase::GetFontSize, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetFontSize));
    c1.def("SetFontSize", &RunPropertiesBase::SetFontSize, "fontSize"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, SetFontSize));
    
    c1.def_property_readonly("WidthFactor", &RunPropertiesBase::GetWidthFactor);
    c1.def("GetWidthFactor", &RunPropertiesBase::GetWidthFactor, DOC(Bentley, DgnPlatform, RunPropertiesBase, GetWidthFactor));
    
    c1.def("ApplyScale", &RunPropertiesBase::ApplyScale, "scale"_a, "isVertical"_a, DOC(Bentley, DgnPlatform, RunPropertiesBase, ApplyScale));
    }