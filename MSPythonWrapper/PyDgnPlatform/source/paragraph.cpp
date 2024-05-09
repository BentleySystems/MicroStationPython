/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\paragraph.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/Paragraph.h>



static const char * __doc_Bentley_DgnPlatform_Paragraph_GetProperties =R"doc(Gets this paragraph's properties.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_ApplyScale =R"doc(Scales all scalar values in this instace. This includes the line
spacing value.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_SetIndentation =R"doc(Sets the indentation of this paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_ClearLineSpacingValueOverride =R"doc(Clears the line spacing value property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_IsLineSpacingValueOverridden =R"doc(True if the line spacing value property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_SetLineSpacingValue =R"doc(Sets the line spacing value.

See also:
    GetLineSpacingValue for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_GetLineSpacingValue =R"doc(Gets the line spacing value. This value has different meaning
according to the value available from GetLineSpacingType (e.g. it
could be a distance in UORs, or a factor).)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_ClearLineSpacingTypeOverride =R"doc(Clears the line spacing type property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_IsLineSpacingTypeOverridden =R"doc(True if the line spacing type property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_SetLineSpacingType =R"doc(Sets the line spacing type.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_GetLineSpacingType =R"doc(Gets the line spacing type.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_ClearIsFullJustifiedOverride =R"doc(Clears the is full justified property override flag and reverts its
value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_IsFullJustifiedOverridden =R"doc(True if the is full justified property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_SetIsFullJustified =R"doc(Sets if lines should be full justified.

See also:
    IsFullJustified for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_IsFullJustified =R"doc(Determines if lines should be full justified. Full justification means
that the space between words is adjusted so that every line begins and
ends in a uniform location. The longest measured line is the base
width, and all other lines have additional space inserted between
words to pad them to take the same width. The last line of a full-
justified paragraph is never adjusted, and is layed out normally
according to the value available from GetJustification.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_ClearJustificationOverride =R"doc(Clears the property override flag and reverts its value from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_IsJustificationOverridden =R"doc(True if the property is overridden from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_SetJustification =R"doc(Sets the justification.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_GetJustification =R"doc(Gets the justification. @note Mixing justifications within the same
TextBlock is experimental at this time.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_Clone =R"doc(Creates a new instance as a deep copy of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_Create =R"doc(Creates a new instance of ParagraphProperties with default (e.g.
zero'ed) values.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphProperties_AsIDgnTextStyleApplyableR =R"doc(Provides access to the IDgnTextStyleApplyable interface that this
object effectively implements.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Paragraph(py::module_& m)
    {
    //===================================================================================
    // struct ParagraphProperties
    py::class_< ParagraphProperties, RefCountedPtr<ParagraphProperties> > c1(m, "ParagraphProperties");

    c1.def("AsIDgnTextStyleApplyableR", &ParagraphProperties::AsIDgnTextStyleApplyableR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParagraphProperties, AsIDgnTextStyleApplyableR));
    c1.def_static("Create", py::overload_cast<DgnModelR>(&ParagraphProperties::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, Create));
    c1.def_static("Create", py::overload_cast<DgnTextStyleCR, DgnModelR>(&ParagraphProperties::Create), "textStyle"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, Create));
    c1.def_static("Create", py::overload_cast<DgnTextStyleCR, DgnModelR, double>(&ParagraphProperties::Create), "textStyle"_a, "dgnModel"_a, "annotationScale"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, Create));
    c1.def("Clone", &ParagraphProperties::Clone, DOC(Bentley, DgnPlatform, ParagraphProperties, Clone));

    c1.def_property_readonly("DgnModel", &ParagraphProperties::GetDgnModelR);
    c1.def("GetDgnModel", &ParagraphProperties::GetDgnModelR, py::return_value_policy::reference_internal);
    
    c1.def_property("Justification", &ParagraphProperties::GetJustification, &ParagraphProperties::SetJustification);
    c1.def("GetJustification", &ParagraphProperties::GetJustification, DOC(Bentley, DgnPlatform, ParagraphProperties, GetJustification));
    c1.def("SetJustification", &ParagraphProperties::SetJustification, "justification"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, SetJustification));

    c1.def("IsJustificationOverridden", &ParagraphProperties::IsJustificationOverridden, DOC(Bentley, DgnPlatform, ParagraphProperties, IsJustificationOverridden));
    c1.def("ClearJustificationOverride", &ParagraphProperties::ClearJustificationOverride, DOC(Bentley, DgnPlatform, ParagraphProperties, ClearJustificationOverride));

    c1.def_property("FullJustified", &ParagraphProperties::IsFullJustified, &ParagraphProperties::SetIsFullJustified);
    c1.def("IsFullJustified", &ParagraphProperties::IsFullJustified, DOC(Bentley, DgnPlatform, ParagraphProperties, IsFullJustified));
    c1.def("SetIsFullJustified", &ParagraphProperties::SetIsFullJustified, "fullJustified"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, SetIsFullJustified));

    c1.def("IsFullJustifiedOverridden", &ParagraphProperties::IsFullJustifiedOverridden, DOC(Bentley, DgnPlatform, ParagraphProperties, IsFullJustifiedOverridden));
    c1.def("ClearIsFullJustifiedOverride", &ParagraphProperties::ClearIsFullJustifiedOverride, DOC(Bentley, DgnPlatform, ParagraphProperties, ClearIsFullJustifiedOverride));

    c1.def_property("LineSpacingType", &ParagraphProperties::GetLineSpacingType, &ParagraphProperties::SetLineSpacingType);
    c1.def("GetLineSpacingType", &ParagraphProperties::GetLineSpacingType, DOC(Bentley, DgnPlatform, ParagraphProperties, GetLineSpacingType));
    c1.def("SetLineSpacingType", &ParagraphProperties::SetLineSpacingType, "type"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, SetLineSpacingType));

    c1.def("IsLineSpacingTypeOverridden", &ParagraphProperties::IsLineSpacingTypeOverridden, DOC(Bentley, DgnPlatform, ParagraphProperties, IsLineSpacingTypeOverridden));
    c1.def("ClearLineSpacingTypeOverride", &ParagraphProperties::ClearLineSpacingTypeOverride, DOC(Bentley, DgnPlatform, ParagraphProperties, ClearLineSpacingTypeOverride));

    c1.def_property("LineSpacingValue", &ParagraphProperties::GetLineSpacingValue, &ParagraphProperties::SetLineSpacingValue);
    c1.def("GetLineSpacingValue", &ParagraphProperties::GetLineSpacingValue, DOC(Bentley, DgnPlatform, ParagraphProperties, GetLineSpacingValue));
    c1.def("SetLineSpacingValue", &ParagraphProperties::SetLineSpacingValue, "value"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, SetLineSpacingValue));

    c1.def("IsLineSpacingValueOverridden", &ParagraphProperties::IsLineSpacingValueOverridden, DOC(Bentley, DgnPlatform, ParagraphProperties, IsLineSpacingValueOverridden));
    c1.def("ClearLineSpacingValueOverride", &ParagraphProperties::ClearLineSpacingValueOverride, "annotationScale"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, ClearLineSpacingValueOverride));

    c1.def_property("Indentation", [] (ParagraphProperties const& self) { return IndentationDataPtr(const_cast<IndentationDataP>(&self.GetIndentation())); }, &ParagraphProperties::SetIndentation);
    c1.def("GetIndentation", [] (ParagraphProperties const& self) { return IndentationDataPtr(const_cast<IndentationDataP>(&self.GetIndentation())); });
    c1.def("SetIndentation", &ParagraphProperties::SetIndentation, "newVal"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, SetIndentation));

    c1.def("ApplyScale", &ParagraphProperties::ApplyScale, "scale"_a, "isVertical"_a, DOC(Bentley, DgnPlatform, ParagraphProperties, ApplyScale));

    //===================================================================================
    // struct Paragraph
    py::class_< Paragraph> c2(m, "Paragraph");

    c2.def_property_readonly("Properties", &Paragraph::GetProperties);
    c2.def("GetProperties", &Paragraph::GetProperties, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Paragraph, GetProperties));
    }