/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textparam.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextParam.h>



static const char * __doc_Bentley_DgnPlatform_TextParamWide_SetCodePage =R"doc(Sets the code page value of the given TextParmWide structure, and sets
the code page flag to true if the code page value is non-zero (false
otherwise). @note The code page in the TextParamWide structure is
deprecated in 8.11, but should still be maintained for backwards
compatibility. This code page value is not actually the code page that
the text is stored as in the element, but rather the keyboard code
page used to create the text. In other words, this is the original
locale code page. As noted, please continue to set this value for
backwards compatibility, but if you think you must read this value for
dealing with the text of the element, see
DgnFontManager::GetEffectiveCodePage.)doc";

static const char * __doc_Bentley_DgnPlatform_TextParamWide_ApplyScaleFactor =R"doc(Applies the provided scale factor to all applicable length and offset
values. @note Because TextParamWide is compressed when written to the
file (e.g. values are only written if non-default), attempting to
scale may require a size change, which is not valid for every caller;
use allowSizeChange to limit this.)doc";

static const char * __doc_Bentley_DgnPlatform_TextParamWide_Initialize =R"doc(Initializes this structure. This essentially means it is zeroed, with
the exception of scale values, which are set to 1.0.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextParam(py::module_& m)
    {
    //===================================================================================
    // Global constants

    //===================================================================================
    // enum class CharacterSpacingType
    py::enum_< CharacterSpacingType>(m, "CharacterSpacingType")
        .value("eAbsolute", CharacterSpacingType::Absolute)
        .value("eFixedWidth", CharacterSpacingType::FixedWidth)
        .value("eFactor", CharacterSpacingType::Factor)
        .export_values();

    //===================================================================================
    // enum class StackedFractionType
    py::enum_< StackedFractionType>(m, "StackedFractionType")
        .value("eNone", StackedFractionType::None)
        .value("eNoBar", StackedFractionType::NoBar)
        .value("eDiagonalBar", StackedFractionType::DiagonalBar)
        .value("eHorizontalBar", StackedFractionType::HorizontalBar)
        .export_values();

    //===================================================================================
    // enum class StackedFractionSection
    py::enum_< StackedFractionSection>(m, "StackedFractionSection")
        .value("eNone", StackedFractionSection::None)
        .value("eNumerator", StackedFractionSection::Numerator)
        .value("eDenominator", StackedFractionSection::Denominator)
        .export_values();    

    //===================================================================================
    // struct TextDrawFlags
    py::class_< TextDrawFlags> c1(m, "TextDrawFlags");

    c1.def_property("InterCharSpacing",
                    [] (TextDrawFlags const& self) { return (bool) self.interCharSpacing; },
                    [] (TextDrawFlags& self, bool value) { self.interCharSpacing = value ? 1 : 0; });

    c1.def_property("FixedWidthSpacing",
                    [] (TextDrawFlags const& self) { return (bool) self.fixedWidthSpacing; },
                    [] (TextDrawFlags& self, bool value) { self.fixedWidthSpacing = value ? 1 : 0; });

    c1.def_property("Underline",
                    [] (TextDrawFlags const& self) { return (bool) self.underline; },
                    [] (TextDrawFlags& self, bool value) { self.underline = value ? 1 : 0; });

    c1.def_property("Slant",
                    [] (TextDrawFlags const& self) { return (bool) self.slant; },
                    [] (TextDrawFlags& self, bool value) { self.slant = value ? 1 : 0; });

    c1.def_property("Vertical",
                    [] (TextDrawFlags const& self) { return (bool) self.vertical; },
                    [] (TextDrawFlags& self, bool value) { self.vertical = value ? 1 : 0; });

    c1.def_property("Offset",
                    [] (TextDrawFlags const& self) { return (bool) self.offset; },
                    [] (TextDrawFlags& self, bool value) { self.offset = value ? 1 : 0; });

    c1.def_property("ShxBigFont",
                    [] (TextDrawFlags const& self) { return (bool) self.shxBigFont; },
                    [] (TextDrawFlags& self, bool value) { self.shxBigFont = value ? 1 : 0; });

    c1.def_property("BgColor",
                    [] (TextDrawFlags const& self) { return (bool) self.bgColor; },
                    [] (TextDrawFlags& self, bool value) { self.bgColor = value ? 1 : 0; });

    c1.def_property("Subscript",
                    [] (TextDrawFlags const& self) { return (bool) self.subscript; },
                    [] (TextDrawFlags& self, bool value) { self.subscript = value ? 1 : 0; });

    c1.def_property("Superscript",
                    [] (TextDrawFlags const& self) { return (bool) self.superscript; },
                    [] (TextDrawFlags& self, bool value) { self.superscript = value ? 1 : 0; });

    c1.def_property("TextStyle",
                    [] (TextDrawFlags const& self) { return (bool) self.textStyle; },
                    [] (TextDrawFlags& self, bool value) { self.textStyle = value ? 1 : 0; });

    c1.def_property_readonly("AreAnyFlagsSet", &TextDrawFlags::AreAnyFlagsSet);

    //===================================================================================
    // struct TextExFlags
    py::class_< TextExFlags> c2(m, "TextExFlags");

    c2.def_property("Overline",
                    [] (TextExFlags const& self) { return (bool) self.overline; },
                    [] (TextExFlags& self, bool value) { self.overline = value ? 1 : 0; });

    c2.def_property("StackedFractionSection",
                    [] (TextExFlags const& self) { return (UInt32) self.stackedFractionSection; },
                    [] (TextExFlags& self, UInt32 value) { self.stackedFractionSection = (UInt32)value; });

    c2.def_property("StackedFractionAlign",
                    [] (TextExFlags const& self) { return (UInt32) self.stackedFractionAlign; },
                    [] (TextExFlags& self, UInt32 value) { self.stackedFractionAlign = (UInt32)value; });

    c2.def_property("StackedFractionType",
                    [] (TextExFlags const& self) { return (UInt32) self.stackedFractionType; },
                    [] (TextExFlags& self, UInt32 value) { self.stackedFractionType = (UInt32)value; });

    c2.def_property("CRCount",
                    [] (TextExFlags const& self) { return (UInt32) self.crCount; },
                    [] (TextExFlags& self, UInt32 value) { self.crCount = (UInt32)value; });

    c2.def_property("Bold",
                    [] (TextExFlags const& self) { return (bool) self.bold; },
                    [] (TextExFlags& self, bool value) { self.bold = value ? 1 : 0; });

    c2.def_property("UnderlineStyle",
                    [] (TextExFlags const& self) { return (bool) self.underlineStyle; },
                    [] (TextExFlags& self, bool value) { self.underlineStyle = value ? 1:0; });

    c2.def_property("OverlineStyle",
                    [] (TextExFlags const& self) { return (bool) self.overlineStyle; },
                    [] (TextExFlags& self, bool value) { self.overlineStyle = value ? 1 : 0; });

    c2.def_property("StyleOverrides",
                    [] (TextExFlags const& self) { return (bool) self.styleOverrides; },
                    [] (TextExFlags& self, bool value) { self.styleOverrides = value ? 1 : 0; });

    c2.def_property("WordWrapTextNode",
                    [] (TextExFlags const& self) { return (bool) self.wordWrapTextNode; },
                    [] (TextExFlags& self, bool value) { self.wordWrapTextNode = value ? 1 : 0; });

    c2.def_property("FullJustification",
                    [] (TextExFlags const& self) { return (bool) self.fullJustification; },
                    [] (TextExFlags& self, bool value) { self.fullJustification = value ? 1 : 0; });

    c2.def_property("Color",
                    [] (TextExFlags const& self) { return (bool) self.color; },
                    [] (TextExFlags& self, bool value) { self.color = value ? 1 : 0; });

    c2.def_property("AcadInterCharSpacing",
                    [] (TextExFlags const& self) { return (bool) self.acadInterCharSpacing; },
                    [] (TextExFlags& self, bool value) { self.acadInterCharSpacing = value ? 1 : 0; });

    c2.def_property("AcadLineSpacingType",
                    [] (TextExFlags const& self) { return (UInt32) self.acadLineSpacingType; },
                    [] (TextExFlags& self, UInt32 value) { self.acadLineSpacingType = value; });

    c2.def_property("Backwards",
                    [] (TextExFlags const& self) { return (bool) self.backwards; },
                    [] (TextExFlags& self, bool value) { self.backwards = value ? 1 : 0; });

    c2.def_property("Upsidedown",
                    [] (TextExFlags const& self) { return (bool) self.upsidedown; },
                    [] (TextExFlags& self, bool value) { self.upsidedown = value ? 1 : 0; });

    c2.def_property("AcadFittedText",
                    [] (TextExFlags const& self) { return (bool) self.acadFittedText; },
                    [] (TextExFlags& self, bool value) { self.acadFittedText = value ? 1 : 0; });

    c2.def_property("AnnotationScale",
                    [] (TextExFlags const& self) { return (bool) self.annotationScale; },
                    [] (TextExFlags& self, bool value) { self.annotationScale = value ? 1 : 0; });

    c2.def_property("RenderPercentsAsMText",
                    [] (TextExFlags const& self) { return (bool) self.renderPercentsAsMText; },
                    [] (TextExFlags& self, bool value) { self.renderPercentsAsMText = value ? 1 : 0; });

    c2.def_property("BitMaskContainsTabCRLF",
                    [] (TextExFlags const& self) { return (bool) self.bitMaskContainsTabCRLF; },
                    [] (TextExFlags& self, bool value) { self.bitMaskContainsTabCRLF = value ? 1 : 0; });

    c2.def_property("IsField",
                    [] (TextExFlags const& self) { return (bool) self.isField; },
                    [] (TextExFlags& self, bool value) { self.isField = value ? 1 : 0; });

    c2.def_property_readonly("AreAnyFlagsSet", &TextExFlags::AreAnyFlagsSet);
        
    //===================================================================================
    // struct TextRenderingFlags
    py::class_< TextRenderingFlags> c3(m, "TextRenderingFlags");

    c3.def_property("AlignEdge",
                    [] (TextRenderingFlags const& self) { return (bool) self.alignEdge; },
                    [] (TextRenderingFlags& self, bool value) { self.alignEdge = value ? 1 : 0; });

    c3.def_property("LineAlignment",
                    [] (TextRenderingFlags const& self) { return (UInt32) self.lineAlignment; },
                    [] (TextRenderingFlags& self, UInt32 value) { self.lineAlignment = value; });

    c3.def_property("DocumentType",
                    [] (TextRenderingFlags const& self) { return (UInt32) self.documentType; },
                    [] (TextRenderingFlags& self, UInt32 value) { self.documentType = value; });   
        
    //===================================================================================
    // struct MSTextSize
    py::class_< MSTextSize> c4(m, "MSTextSize");

    c4.def_readwrite("width", &MSTextSize::width);
    c4.def_readwrite("height", &MSTextSize::height);

    //===================================================================================
    // struct TextSizeParam
    py::class_< TextSizeParam> c5(m, "TextSizeParam");

    c5.def_readwrite("mode", &TextSizeParam::mode);
    c5.def_readwrite("size", &TextSizeParam::size);
    c5.def_readwrite("aspectRatio", &TextSizeParam::aspectRatio);

    //===================================================================================
    // struct TextParam
    py::class_< TextParam> c6(m, "TextParam");

    c6.def_readwrite("font", &TextParam::font);
    c6.def_readwrite("justification", &TextParam::just);
    c6.def_readwrite("viewIndependent", &TextParam::viewIndependent);

    //===================================================================================
    // struct TextParamWide
    py::class_< TextParamWide> c7(m, "TextParamWide");

    c7.def_readwrite("font", &TextParamWide::font);
    c7.def_readwrite("justification", &TextParamWide::just);
    c7.def_readwrite("viewIndependent", &TextParamWide::viewIndependent);
    c7.def_readwrite("nodeNumber", &TextParamWide::nodeNumber);
    c7.def_readwrite("shxBigFont", &TextParamWide::shxBigFont);
    c7.def_readwrite("backgroundFillColor", &TextParamWide::backgroundFillColor);
    c7.def_readwrite("textStyleId", &TextParamWide::textStyleId);
    c7.def_readwrite("color", &TextParamWide::color);
    c7.def_readwrite("slant", &TextParamWide::slant);
    c7.def_readwrite("lineSpacing", &TextParamWide::lineSpacing);
    c7.def_readwrite("characterSpacing", &TextParamWide::characterSpacing);
    c7.def_readwrite("underlineSpacing", &TextParamWide::underlineSpacing);
    c7.def_readwrite("textnodeWordWrapLength", &TextParamWide::textnodeWordWrapLength);
    c7.def_readwrite("flags", &TextParamWide::flags);
    c7.def_readwrite("exFlags", &TextParamWide::exFlags);
    c7.def_readwrite("lineOffset", &TextParamWide::lineOffset);
    c7.def_readwrite("backgroundBorder", &TextParamWide::backgroundBorder);
    c7.def_readwrite("assocId", &TextParamWide::assocId);
    c7.def_readwrite("backgroundColor", &TextParamWide::backgroundColor);
    c7.def_readwrite("backgroundStyle", &TextParamWide::backgroundStyle);
    c7.def_readwrite("backgroundWeight", &TextParamWide::backgroundWeight);
    c7.def_readwrite("underlineColor", &TextParamWide::underlineColor);
    c7.def_readwrite("underlineStyle", &TextParamWide::underlineStyle);
    c7.def_readwrite("underlineWeight", &TextParamWide::underlineWeight);
    c7.def_readwrite("overlineSpacing", &TextParamWide::overlineSpacing);
    c7.def_readwrite("overridesFromStyle", &TextParamWide::overridesFromStyle);
    c7.def_readwrite("widthFactor", &TextParamWide::widthFactor);
    c7.def_readwrite("annotationScale", &TextParamWide::annotationScale);
    c7.def_readwrite("renderingFlags", &TextParamWide::renderingFlags);

    c7.def(py::init<>());
    c7.def("Initialize", &TextParamWide::Initialize, DOC(Bentley, DgnPlatform, TextParamWide, Initialize));

    c7.def("ApplyScaleFactor", 
           py::overload_cast<double, bool, bool>(&TextParamWide::ApplyScaleFactor),
           "uniformScaleFactor"_a, "isTextNode"_a, "allowSizeChange"_a, DOC(Bentley, DgnPlatform, TextParamWide, ApplyScaleFactor));

    c7.def("ApplyScaleFactor", 
           py::overload_cast<DPoint2dCR, bool, bool>(&TextParamWide::ApplyScaleFactor), 
           "scaleFactor"_a, "isTextNode"_a, "allowSizeChange"_a, DOC(Bentley, DgnPlatform, TextParamWide, ApplyScaleFactor));

    c7.def("SetCodePage", &TextParamWide::SetCodePage, "codePage"_a, DOC(Bentley, DgnPlatform, TextParamWide, SetCodePage));
    c7.def("__eq__", [](TextParamWideCR self, TextParamWideCR other) { return 0 == memcmp(&self, &other, sizeof(other)); });

    //===================================================================================
    // struct TextEDField
    py::class_< TextEDField> c8(m, "TextEDField");

    c8.def_readwrite("start", &TextEDField::start);
    c8.def_readwrite("length", &TextEDField::len);
    c8.def_readwrite("justification", &TextEDField::just);

    //===================================================================================
    // struct TextEDParam
    py::class_< TextEDParam> c9(m, "TextEDParam");

    c9.def_readwrite("numEDFields", &TextEDParam::numEDFields);
    c9.def_property("edField",
                    [] (TextEDParam const& self) { return self.edField; },
                    py::cpp_function([] (TextEDParam& self, TextEDFieldP value) { self.edField = value; }, py::keep_alive<1, 2>()));

    //===================================================================================
    // struct TextScale
    py::class_< TextScale> c10(m, "TextScale");

    c10.def_readwrite("x", &TextScale::x);
    c10.def_readwrite("y", &TextScale::y);

    //===================================================================================
    // struct TextFlags
    py::class_< TextFlags> c11(m, "TextFlags");

    c11.def_property("upper",
                    [] (TextFlags const& self) { return (bool) self.upper; },
                    [] (TextFlags& self, bool value) { self.upper = value ? 1 : 0; });

    c11.def_property("lower",
                     [] (TextFlags const& self) { return (bool) self.lower; },
                     [] (TextFlags& self, bool value) { self.lower = value ? 1 : 0; });

    c11.def_property("fraction",
                     [] (TextFlags const& self) { return (bool) self.fract; },
                     [] (TextFlags& self, bool value) { self.fract = value ? 1 : 0; });

    c11.def_property("international",
                     [] (TextFlags const& self) { return (bool) self.intl; },
                     [] (TextFlags& self, bool value) { self.intl = value ? 1 : 0; });

    c11.def_property("fast",
                     [] (TextFlags const& self) { return (bool) self.fast; },
                     [] (TextFlags& self, bool value) { self.fast = value ? 1 : 0; });

    c11.def_property("space",
                     [] (TextFlags const& self) { return (bool) self.space; },
                     [] (TextFlags& self, bool value) { self.space = value ? 1 : 0; });

    c11.def_property("filled",
                     [] (TextFlags const& self) { return (bool) self.filled; },
                     [] (TextFlags& self, bool value) { self.filled = value ? 1 : 0; });

    //===================================================================================
    // struct TextStyleInfo
    py::class_< TextStyleInfo> c12(m, "TextStyleInfo");

    c12.def_readwrite("font", &TextStyleInfo::font);
    c12.def_readwrite("slant", &TextStyleInfo::slant);
    c12.def_readwrite("bold", &TextStyleInfo::bold);
    c12.def_readwrite("italics", &TextStyleInfo::italics);
    c12.def_readwrite("bigFont", &TextStyleInfo::bigFont);

    //===================================================================================
    // struct TextFontInfo
    py::class_< TextFontInfo> c13(m, "TextFontInfo");

    c13.def_readwrite("lettersType", &TextFontInfo::lettersType);
    c13.def_readwrite("charType", &TextFontInfo::charType);
    c13.def_readwrite("vectorSize", &TextFontInfo::vectorSize);
    c13.def_readwrite("graphicType", &TextFontInfo::graphicType);
    c13.def_readwrite("charSize", &TextFontInfo::charSize);
    c13.def_readwrite("tileSize", &TextFontInfo::tileSize);
    c13.def_readwrite("dataSize", &TextFontInfo::dataSize);
    c13.def_readwrite("origin", &TextFontInfo::origin);
    c13.def_readwrite("scale", &TextFontInfo::scale);

    //===================================================================================
    // struct TextStyleOverrideFlags
    py::class_< TextStyleOverrideFlags> c14(m, "TextStyleOverrideFlags");

    c14.def_property("fontNo",
        [](TextStyleOverrideFlags const& self) { return (bool)self.fontNo; },
        [](TextStyleOverrideFlags& self, bool value) { self.fontNo = value ? 1 : 0; });

    c14.def_property("shxBigFont", 
        [](TextStyleOverrideFlags const& self) { return (bool)self.shxBigFont; },
        [](TextStyleOverrideFlags& self, bool value) { self.shxBigFont = value ? 1 : 0; });


    c14.def_property("width",
        [](TextStyleOverrideFlags const& self) { return (bool)self.width; },
        [](TextStyleOverrideFlags& self, bool value) { self.width = value ? 1 : 0; });

    c14.def_property("height",
        [](TextStyleOverrideFlags const& self) { return (bool)self.height; },
        [](TextStyleOverrideFlags& self, bool value) { self.height = value ? 1 : 0; });

    c14.def_property("slant",
        [](TextStyleOverrideFlags const& self) { return (bool)self.slant; },
        [](TextStyleOverrideFlags& self, bool value) { self.slant = value ? 1 : 0; });

    c14.def_property("linespacing",
        [](TextStyleOverrideFlags const& self) { return (bool)self.linespacing; },
        [](TextStyleOverrideFlags& self, bool value) { self.linespacing = value ? 1 : 0; });

    c14.def_property("interCharSpacing",
        [](TextStyleOverrideFlags const& self) { return (bool)self.interCharSpacing; },
        [](TextStyleOverrideFlags& self, bool value) { self.interCharSpacing = value ? 1 : 0; });

    c14.def_property("underlineOffset",
        [](TextStyleOverrideFlags const& self) { return (bool)self.underlineOffset; },
        [](TextStyleOverrideFlags& self, bool value) { self.underlineOffset = value ? 1 : 0; });

    c14.def_property("overlineOffset",
        [](TextStyleOverrideFlags const& self) { return (bool)self.overlineOffset; },
        [](TextStyleOverrideFlags& self, bool value) { self.overlineOffset = value ? 1 : 0; });

    c14.def_property("just",
        [](TextStyleOverrideFlags const& self) { return (bool)self.just; },
        [](TextStyleOverrideFlags& self, bool value) { self.just = value ? 1 : 0; });

    c14.def_property("nodeJust",
        [](TextStyleOverrideFlags const& self) { return (bool)self.nodeJust; },
        [](TextStyleOverrideFlags& self, bool value) { self.nodeJust = value ? 1 : 0; });

    c14.def_property("lineLength",
        [](TextStyleOverrideFlags const& self) { return (bool)self.lineLength; },
        [](TextStyleOverrideFlags& self, bool value) { self.lineLength = value ? 1 : 0; });

    c14.def_property("direction",
        [](TextStyleOverrideFlags const& self) { return (bool)self.direction; },
        [](TextStyleOverrideFlags& self, bool value) { self.direction = value ? 1 : 0; });

    c14.def_property("underline",
        [](TextStyleOverrideFlags const& self) { return (bool)self.underline; },
        [](TextStyleOverrideFlags& self, bool value) { self.underline = value ? 1 : 0; });

    c14.def_property("overline",
        [](TextStyleOverrideFlags const& self) { return (bool)self.overline; },
        [](TextStyleOverrideFlags& self, bool value) { self.overline = value ? 1 : 0; });

    c14.def_property("italics",
        [](TextStyleOverrideFlags const& self) { return (bool)self.italics; },
        [](TextStyleOverrideFlags& self, bool value) { self.italics = value ? 1 : 0; });

    c14.def_property("bold",
        [](TextStyleOverrideFlags const& self) { return (bool)self.bold; },
        [](TextStyleOverrideFlags& self, bool value) { self.bold = value ? 1 : 0; });

    c14.def_property("superscript",
        [](TextStyleOverrideFlags const& self) { return (bool)self.superscript; },
        [](TextStyleOverrideFlags& self, bool value) { self.superscript = value ? 1 : 0; });

    c14.def_property("subscript",
        [](TextStyleOverrideFlags const& self) { return (bool)self.subscript; },
        [](TextStyleOverrideFlags& self, bool value) { self.subscript = value ? 1 : 0; });

    c14.def_property("fixedSpacing",
        [](TextStyleOverrideFlags const& self) { return (bool)self.fixedSpacing; },
        [](TextStyleOverrideFlags& self, bool value) { self.fixedSpacing = value ? 1 : 0; });

    c14.def_property("background",
        [](TextStyleOverrideFlags const& self) { return (bool)self.background; },
        [](TextStyleOverrideFlags& self, bool value) { self.background = value ? 1 : 0; });

    c14.def_property("backgroundstyle",
        [](TextStyleOverrideFlags const& self) { return (bool)self.backgroundstyle; },
        [](TextStyleOverrideFlags& self, bool value) { self.backgroundstyle = value ? 1 : 0; });

    c14.def_property("backgroundweight",
        [](TextStyleOverrideFlags const& self) { return (bool)self.backgroundweight; },
        [](TextStyleOverrideFlags& self, bool value) { self.backgroundweight = value ? 1 : 0; });

    c14.def_property("backgroundcolor",
        [](TextStyleOverrideFlags const& self) { return (bool)self.backgroundcolor; },
        [](TextStyleOverrideFlags& self, bool value) { self.backgroundcolor = value ? 1 : 0; });

    c14.def_property("backgroundfillcolor",
        [](TextStyleOverrideFlags const& self) { return (bool)self.backgroundfillcolor; },
        [](TextStyleOverrideFlags& self, bool value) { self.backgroundfillcolor = value ? 1 : 0; });

    c14.def_property("backgroundborder",
        [](TextStyleOverrideFlags const& self) { return (bool)self.backgroundborder; },
        [](TextStyleOverrideFlags& self, bool value) { self.backgroundborder = value ? 1 : 0; });

    c14.def_property("underlinestyle",
        [](TextStyleOverrideFlags const& self) { return (bool)self.underlinestyle; },
        [](TextStyleOverrideFlags& self, bool value) { self.underlinestyle = value ? 1 : 0; });

    c14.def_property("underlineweight",
        [](TextStyleOverrideFlags const& self) { return (bool)self.underlineweight; },
        [](TextStyleOverrideFlags& self, bool value) { self.underlineweight = value ? 1 : 0; });

    c14.def_property("underlinecolor",
        [](TextStyleOverrideFlags const& self) { return (bool)self.underlinecolor; },
        [](TextStyleOverrideFlags& self, bool value) { self.underlinecolor = value ? 1 : 0; });

    c14.def_property("overlinestyle",
        [](TextStyleOverrideFlags const& self) { return (bool)self.overlinestyle; },
        [](TextStyleOverrideFlags& self, bool value) { self.overlinestyle = value ? 1 : 0; });

    c14.def_property("overlineweight",
        [](TextStyleOverrideFlags const& self) { return (bool)self.overlineweight; },
        [](TextStyleOverrideFlags& self, bool value) { self.overlineweight = value ? 1 : 0; });

    c14.def_property("overlinecolor",
        [](TextStyleOverrideFlags const& self) { return (bool)self.overlinecolor; },
        [](TextStyleOverrideFlags& self, bool value) { self.overlinecolor = value ? 1 : 0; });

    c14.def_property("lineOffset",
        [](TextStyleOverrideFlags const& self) { return (bool)self.lineOffset; },
        [](TextStyleOverrideFlags& self, bool value) { self.lineOffset = value ? 1 : 0; });

    c14.def_property("fractions",
        [](TextStyleOverrideFlags const& self) { return (bool)self.fractions; },
        [](TextStyleOverrideFlags& self, bool value) { self.fractions = value ? 1 : 0; });

    c14.def_property("overlinestyleflag",
        [](TextStyleOverrideFlags const& self) { return (bool)self.overlinestyleflag; },
        [](TextStyleOverrideFlags& self, bool value) { self.overlinestyleflag = value ? 1 : 0; });

    c14.def_property("underlinestyleflag",
        [](TextStyleOverrideFlags const& self) { return (bool)self.underlinestyleflag; },
        [](TextStyleOverrideFlags& self, bool value) { self.underlinestyleflag = value ? 1 : 0; });

    c14.def_property("color",
        [](TextStyleOverrideFlags const& self) { return (bool)self.color; },
        [](TextStyleOverrideFlags& self, bool value) { self.color = value ? 1 : 0; });

    c14.def_property("widthFactor",
        [](TextStyleOverrideFlags const& self) { return (bool)self.widthFactor; },
        [](TextStyleOverrideFlags& self, bool value) { self.widthFactor = value ? 1 : 0; });

    c14.def_property("colorFlag",
        [](TextStyleOverrideFlags const& self) { return (bool)self.colorFlag; },
        [](TextStyleOverrideFlags& self, bool value) { self.colorFlag = value ? 1 : 0; });

    c14.def_property("fullJustification",
        [](TextStyleOverrideFlags const& self) { return (bool)self.fullJustification; },
        [](TextStyleOverrideFlags& self, bool value) { self.fullJustification = value ? 1 : 0; });

    c14.def_property("acadLineSpacingType",
        [](TextStyleOverrideFlags const& self) { return (bool)self.acadLineSpacingType; },
        [](TextStyleOverrideFlags& self, bool value) { self.acadLineSpacingType = value ? 1 : 0; });

    c14.def_property("backwards",
        [](TextStyleOverrideFlags const& self) { return (bool)self.backwards; },
        [](TextStyleOverrideFlags& self, bool value) { self.backwards = value ? 1 : 0; });

    c14.def_property("upsidedown",
        [](TextStyleOverrideFlags const& self) { return (bool)self.upsidedown; },
        [](TextStyleOverrideFlags& self, bool value) { self.upsidedown = value ? 1 : 0; });

    c14.def_property("acadInterCharSpacing",
        [](TextStyleOverrideFlags const& self) { return (bool)self.acadInterCharSpacing; },
        [](TextStyleOverrideFlags& self, bool value) { self.acadInterCharSpacing = value ? 1 : 0; });

    c14.def_property("reserved",
        [](TextStyleOverrideFlags const& self) { return self.reserved; },
        [](TextStyleOverrideFlags& self, bool value) { self.reserved = value; });

    c14.def_property("reserved2",
        [](TextStyleOverrideFlags const& self) { return self.reserved2; },
        [](TextStyleOverrideFlags& self, int value) { self.reserved2 = value; });
    }