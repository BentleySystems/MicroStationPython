/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textstringproperties.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextStringProperties.h>



static const char * __doc_Bentley_DgnPlatform_TextStringProperties_ApplyScale =R"doc(Scales all scalar values in this instace. This includes text size, as
well as spacing and offset attributes.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_GetStackedFractionSection =R"doc(Gets the stacked fraction section (e.g. none, top, bottom).)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_GetStackedFractionType =R"doc(Gets the stacked fraction type (e.g. none, stacked with no divider,
diagonal, stacked with a divider).)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_SetJustification =R"doc(Sets the justification.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_GetJustification =R"doc(Gets the justification.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_SetIs3d =R"doc(Sets the Is3d flag.

See also:
    Is3d for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_Is3d =R"doc(True if the text is being drawn in a 3d view.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_IsViewIndependent =R"doc(True if text should be view independent.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_SetIsUpsideDown =R"doc(Sets the upside down flag.

See also:
    IsUpsideDown for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_IsUpsideDown =R"doc(Gets the upside down flag. @note This is essentially a mirror about
the horizontal axis.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_SetIsBackwards =R"doc(Sets the backwards flag.

See also:
    IsBackwards for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_IsBackwards =R"doc(Gets the backwards flag. @note This is essentially a mirror about the
vertical axis.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_SetIsVertical =R"doc(Sets the vertical flag. @note This controls MicroStation vertical text
layout logic, which simply takes the glyphs from a normal font as-is,
and effectively assumes soft line feeds after each character. This
does not work with \@... TrueType fonts, which have special glyphs for
more correct vertical text.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_IsVertical =R"doc(Gets the vertical flag. @note This controls MicroStation vertical text
layout logic, which simply takes the glyphs from a normal font as-is,
and effectively assumes soft line feeds after each character. This
does not work with \@... TrueType fonts, which have special glyphs for
more correct vertical text.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_ShouldShowOverline =R"doc(Determines if an overline should be drawn for the associated piece of
text. This not only takes into account the overline flag, but any
other relevant flags like IsVertical.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_ShouldShowUnderline =R"doc(Determines if an underline should be drawn for the associated piece of
text. This not only takes into account the underline flag, but any
other relevant flags like IsVertical.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_Clone =R"doc(Creates a new instance as a deep copy of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_TextStringProperties_Create =R"doc(Creates a new instance from the provided parameters; the rest of the
structure is zeroed.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextStringProperties(py::module_& m)
    {
    //===================================================================================
    // struct TextStringProperties
    py::class_< TextStringProperties, RefCountedPtr<TextStringProperties>, RunPropertiesBase> c1(m, "TextStringProperties");

    c1.def_static("Create", &TextStringProperties::Create, "font"_a, "bigFont"_a, "fontSize"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TextStringProperties, Create));
    c1.def("Clone", &TextStringProperties::Clone, DOC(Bentley, DgnPlatform, TextStringProperties, Clone));

    c1.def("ShouldShowUnderline", &TextStringProperties::ShouldShowUnderline, DOC(Bentley, DgnPlatform, TextStringProperties, ShouldShowUnderline));
    c1.def("ShouldShowOverline", &TextStringProperties::ShouldShowOverline, DOC(Bentley, DgnPlatform, TextStringProperties, ShouldShowOverline));
    
    c1.def_property("Vertical", &TextStringProperties::IsVertical, &TextStringProperties::SetIsVertical);
    c1.def("IsVertical", &TextStringProperties::IsVertical, DOC(Bentley, DgnPlatform, TextStringProperties, IsVertical));
    c1.def("SetIsVertical", &TextStringProperties::SetIsVertical, "vertical"_a, DOC(Bentley, DgnPlatform, TextStringProperties, SetIsVertical));
    
    c1.def_property("Backwards", &TextStringProperties::IsBackwards, &TextStringProperties::SetIsBackwards);
    c1.def("IsBackwards", &TextStringProperties::IsBackwards, DOC(Bentley, DgnPlatform, TextStringProperties, IsBackwards));
    c1.def("SetIsBackwards", &TextStringProperties::SetIsBackwards, "backwards"_a, DOC(Bentley, DgnPlatform, TextStringProperties, SetIsBackwards));
    
    c1.def_property("UpsideDown", &TextStringProperties::IsUpsideDown, &TextStringProperties::SetIsUpsideDown);
    c1.def("IsUpsideDown", &TextStringProperties::IsUpsideDown, DOC(Bentley, DgnPlatform, TextStringProperties, IsUpsideDown));
    c1.def("SetIsUpsideDown", &TextStringProperties::SetIsUpsideDown, "upsideDown"_a, DOC(Bentley, DgnPlatform, TextStringProperties, SetIsUpsideDown));
    
    c1.def("IsViewIndependent", &TextStringProperties::IsViewIndependent, DOC(Bentley, DgnPlatform, TextStringProperties, IsViewIndependent));
    
    c1.def("Is3d", &TextStringProperties::Is3d, DOC(Bentley, DgnPlatform, TextStringProperties, Is3d));
    c1.def("SetIs3d", &TextStringProperties::SetIs3d, "3d"_a, DOC(Bentley, DgnPlatform, TextStringProperties, SetIs3d));
    
    c1.def_property("Justification", &TextStringProperties::GetJustification, &TextStringProperties::SetJustification);
    c1.def("GetJustification", &TextStringProperties::GetJustification, DOC(Bentley, DgnPlatform, TextStringProperties, GetJustification));
    c1.def("SetJustification", &TextStringProperties::SetJustification, "justification"_a, DOC(Bentley, DgnPlatform, TextStringProperties, SetJustification));
    
    c1.def_property_readonly("StackedFractionType", &TextStringProperties::GetStackedFractionType);
    c1.def("GetStackedFractionType", &TextStringProperties::GetStackedFractionType, DOC(Bentley, DgnPlatform, TextStringProperties, GetStackedFractionType));
    
    c1.def_property_readonly("StackedFractionSection", &TextStringProperties::GetStackedFractionSection);
    c1.def("GetStackedFractionSection", &TextStringProperties::GetStackedFractionSection, DOC(Bentley, DgnPlatform, TextStringProperties, GetStackedFractionSection));
    
    c1.def("ApplyScale", &TextStringProperties::ApplyScale, "scale"_a, DOC(Bentley, DgnPlatform, TextStringProperties, ApplyScale));
    }