/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textblock.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/TextBlock.h>



static const char * __doc_Bentley_DgnPlatform_TextBlock_ReplaceText =R"doc(Replaces a section of this TextBlock with the provided text. This
attempts to intelligently retain formatting, and will prevent edits
within atomic runs, such as fields, or across enter data field
boundaries. The end caret is taken by-reference (non-const), and it is
updated to the end of the newly replaced text. Remember that modifying
a TextBlock invalidates all other carets. This modified caret can be
used as the start when resuming a find operation.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetStyleProperties =R"doc(Applies select style properties to the specified range. This differs
from ApplyTextStyle in that the provided style object is treated as
merely a property vessel, and properties will be copied from it; it
will /not/ associate the style to the caret range. Corollary 1:This
will not respect existing overrides. Corollary 2:This will force
overrides on indicated properties if a style is already associated.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_ApplyTextStyle =R"doc(Applies a text style to the specified range. @note You should consider
calling PerformLayout after this operation. It will not be done
automatically, allowing you to perform several expensive operations
with a single layout call. @note If either endpoint is in the middle
of a run, it is split. @note If you provide a mask with all bits set
(a reasonable default), any intersecting paragraph will have
paragraph-level properties applied to the whole paragraph; similar for
the TextBlock's properties. You can use utility methods such as
TextBlockProperties::SetMaskForTextBlockProperties,
ParagraphProperties::SetMaskForParagraphProperties, and
RunProperties::SetMaskForRunProperties to limit propogration to
desired properties. @note See IDgnTextStyleApplyable::ApplyTextStyle
for rules about the style being in the file and respecting overrides.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_IsAlongElement =R"doc(Indicates that this TextBlock represents text that is associated to
another element; character layout, positioning, and orientation is
based on the target element. @note The details of " along element " text
are not currently available in the published API; if you encounter a
TextBlock that is along element, and you require graphical information
about it, you can use ElementGraphicsOutput to collect the underlying
_ProcessTextString calls.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetNominalRange =R"doc(Gets the nominal range of the entire TextBlock. This is a union of all
nominal ranges, which is a union of every character's cell box. @note
The nominal range is good to use if you want to generally know the
" size " of a TextBlock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_PerformLayout =R"doc(Forces TextBlock to re-layout all runs after the dirty caret. @note
You only need to call this method after modifying properties;
appending or inserting into the TextBlock automatically forces layout.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_ToString =R"doc(Creates a plain-text string representing the entire TextBlock. Note
that special runs such as fractions can no longer be uniquely
identified as such.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_Remove =R"doc(Removes all content between two carets (from inclusive, to exclusive).

Returns:
    The new position of the 'from' caret parameter. Note that the
    original 'from' caret can become invalid (e.g. if you remove the
    last run of a paragraph, the resulting paragraph is removed, and
    'from' is no longer pointing to a valid insert position).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertEnterDataField =R"doc(Inserts an enter data field. This is a fixed-length atomic node that
can be used as a placeholder for data. @note The value parameter's
length should be less than or equal to totalLength (otherwise it will
be truncated). If it is less, the resulting run will be padded with
space characters (U+0020) according to the EDF justification. @note
The maximum length of an enter data field is currently 128.

Returns:
    The new position of the insert caret. Note that this is not
    necessarily N insert positions from the original insert position
    (where N is the length of the string) (e.g. if you append a
    character to a word that causes it to word-wrap to the next line).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertStackedFraction =R"doc(Inserts a stacked fraction. Depending on type, this is analagous to
inserting a NoBarFraction, a HorizontalBarFraction, or a
DiagonalBarFraction.

Returns:
    The new position of the insert caret. Note that this is not
    necessarily N insert positions from the original insert position
    (where N is the length of the string) (e.g. if you append a
    character to a word that causes it to word-wrap to the next line).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertTab =R"doc(Inserts a tab. This is analagous to inserting a Tab.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertLineBreak =R"doc(Inserts a line break, beginning a new line in the same paragraph. This
is analagous to inserting a LineBreak.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertParagraphBreak =R"doc(Inserts a carriage return, beginning a new paragraph. This is
analagous to inserting a ParagraphBreak.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertText =R"doc(Inserts a string of like-formatted, single-line characters. This is
analagous to inserting a CharStream. @note The string will be
processed for control characters such as carriage returns, line feeds,
and tabs, and appropriate runs will be added on your behalf.

Returns:
    The new position of the insert caret. Note that this is not
    necessarily N insert positions from the original insert position
    (where N is the length of the string) (e.g. if you append a
    character to a word that causes it to word-wrap to the next line).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendEnterDataField =R"doc(Appends an enter data field. This is a fixed-length atomic node that
can be used as a placeholder for data. @note The maximum length of an
enter data field is currently 128. @note The value parameter's length
should be less than or equal to totalLength (otherwise it will be
truncated). If it is less, the resulting run will be padded with space
characters (U+0020) according to the EDF justification.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendStackedFraction =R"doc(Appends a stacked fraction. Depending on type, this is analagous to
appending a NoBarFraction, a HorizontalBarFraction, or a
DiagonalBarFraction.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendTab =R"doc(Appends a tab. This is analagous to appending a Tab.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendLineBreak =R"doc(Appends a line break, beginning a new line in the same paragraph. This
is analagous to appending a LineBreak.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendParagraphBreak =R"doc(Appends a carriage return, beginning a new paragraph. This is
analagous to appending a ParagraphBreak. @note This does not actually
append another paragraph; it merely marks the existing paragraph as
complete, and if another run is added, a new paragraph is then created
to contain it. Thus, it doesn't matter if you call
SetParagraphPropertiesForAdd before or after this method, as long as
it is before adding the first run to the new paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendText =R"doc(Appends a string of like-formatted, single-line characters. This is
analagous to appending a CharStream. @note The string will be
processed for control characters such as carriage returns, line feeds,
and tabs, and appropriate runs will be added on your behalf.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_IsEmpty =R"doc(Determines if this instance is empty.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_Clone =R"doc(Creates a deep copy of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetOrientation =R"doc(Sets the rotation.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetOrientation =R"doc(Gets the rotation.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetUserOrigin =R"doc(Sets the user origin.

See also:
    GetUserOrigin for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetUserOrigin =R"doc(Gets the user origin. The user origin is the data point that the user
selected when placing the text. Text flows around the user origin
based on justification (e.g. top-left text flows down and to the right
of the user origin, whereas bottom-right text start above and to the
left of the user origin, and flows towards it).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetRunPropertiesForAdd =R"doc(Sets the run properties that will be used when any future run DOM
nodes are created.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetRunPropertiesForAdd =R"doc(Gets the run properties that will be used when any future run DOM
nodes are created.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetParagraphPropertiesForAdd =R"doc(Sets the paragraph properties that will be used when any future
paragraph DOM nodes are created.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetParagraphPropertiesForAdd =R"doc(Gets the paragraph properties that will be used when any future
paragraph DOM nodes are created.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetProperties =R"doc(Sets the formatting properties. @note You should also call
PerformLayout to ensure that the internal structure of TextBlock is
up-to-date.

See also:
    GetProperties for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetProperties =R"doc(Gets the formatting properties. @note Non-formatting properties, such
as origin and rotation, are stored directly on the TextBlock. @note
Individual properties cannot be modified directly; to modify a single
property, you must clone the existing properties, mutate them, and
push them back.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_CreateEndCaret =R"doc(Create a new Caret that designates the end of this instance (one run
past the last run).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_CreateStartCaret =R"doc(Create a new Caret that designates the beginning of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_ValidateFields =R"doc(Attempts to evaluate all fields in the TextBlock. Returns false if any
fields cannot be evaluated successfully.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_SetField =R"doc(Associates the field with the specified position. If a field is
already associated with this position, it is replaced. If the field
spans multiple runs, may involve adjusting layout, which may affect
the insertion caret. Returns false if the field cannot be placed at
the specified position.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_GetField =R"doc(Returns the TextField located at the specified position, or NULL if no
TextField exists at this position. @note:The TextField returned is an
in-memory copy; modifications made to it will not affect the TextBlock
from which it originated.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_InsertField =R"doc(Inserts a field. Fields allow you to associate properties of other
objects (e.g. the file, models, or elements) to a section of text, and
have the displayed value evaluate to the value of the property. @note
This API is currently a Work in Progress (WIP) to allow direct access
to fields, and is a short-term workaround/solution.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlock_AppendField =R"doc(Appends a field. Fields allow you to associate properties of other
objects (e.g. the file, models, or elements) to a section of text, and
have the displayed value evaluate to the value of the property. @note
This API is currently a Work in Progress (WIP) to allow direct access
to fields, and is a short-term workaround/solution.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_ApplyScale =R"doc(Scales all scalar values in this instace. This includes the document
width value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_ClearAnnotationScale =R"doc(Removes annotation scale.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_HasAnnotationScale =R"doc(True if an annotation scale has been specified.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetAnnotationScale =R"doc(Sets the annotation scale. Calling this sets the value, and makes this
instance recognize it (e.g. via HasAnnotationScale).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_GetAnnotationScale =R"doc(Gets the annotation scale. @note This value is only valid if
HasAnnotationScale.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetDocumentWidth =R"doc(Sets the maximum width of the document (in UORs) at which lines will
wrap.

See also:
    GetDocumentWidth for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_GetDocumentWidth =R"doc(Gets the maximum width of the document (in UORs) at which lines will
wrap. Wrapping only occurs at word-break characters, which include
whitespace.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_ClearMaxCharactersPerLineOverride =R"doc(Clears the max characters per line property override flag and reverts
its value from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsMaxCharactersPerLineOverridden =R"doc(True if the max characters per line property is overridden from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetMaxCharactersPerLine =R"doc(Gets the maximum number of characters to place on a line.

See also:
    GetMaxCharactersPerLine for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_GetMaxCharactersPerLine =R"doc(Gets the maximum number of characters to place on a line.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_ClearIsVerticalOverride =R"doc(Clears the is vertical property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsVerticalOverridden =R"doc(True if the is vertical property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetIsVertical =R"doc(Sets the is vertical value.

See also:
    IsVertical for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsVertical =R"doc(Gets this is vertical value. This vertical flag means that individual
glyphs are layed out in a top-down fashing (e.g. as if a line feed
existing after every glyph), and is more of a decoration than a proper
way to represent vertically flowing languages. In these cases, you
will want to use a vertical font (e.g. a TrueType font with the '@'
indicator), and rotate the text 90 degrees.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetIsViewIndependent =R"doc(Sets the is view independent value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsViewIndependent =R"doc(Gets the is view independent value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_ClearIsUpsideDownOverride =R"doc(Clears the is upside down property override flag and reverts its value
from the underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsUpsideDownOverridden =R"doc(True if the is upside down property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetIsUpsideDown =R"doc(Sets the is upside down value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsUpsideDown =R"doc(Gets the is upside down value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_ClearIsBackwardsOverride =R"doc(Clears the is backwards override flag and reverts its value from the
underlying style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsBackwardsOverridden =R"doc(True if the is backwards property is overridden from the underlying
style.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_SetIsBackwards =R"doc(Sets the is backwards value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_IsBackwards =R"doc(Gets the is backwards value.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_Clone =R"doc(Creates a new instance as a deep copy of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_Create =R"doc(Creates a new instance of TextBlockProperties with default (e.g.
zero'ed) values.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockProperties_AsIDgnTextStyleApplyableR =R"doc(Provides access to the IDgnTextStyleApplyable interface that this
object effectively implements.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextBlock(py::module_& m)
    {
    //===================================================================================
    // struct TextBlockProperties
    py::class_< TextBlockProperties, RefCountedPtr<TextBlockProperties> > c1(m, "TextBlockProperties");

    c1.def("AsIDgnTextStyleApplyableR", &TextBlockProperties::AsIDgnTextStyleApplyableR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextBlockProperties, AsIDgnTextStyleApplyableR));
    c1.def_static("Create", py::overload_cast<DgnModelR>(&TextBlockProperties::Create), "dgnModel"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, Create));
    c1.def_static("Create", py::overload_cast<DgnTextStyleCR, DgnModelR>(&TextBlockProperties::Create), "textStyle"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, Create));
    c1.def("Clone", &TextBlockProperties::Clone, DOC(Bentley, DgnPlatform, TextBlockProperties, Clone));

    c1.def_property_readonly("DgnModel", &TextBlockProperties::GetDgnModelR);
    c1.def("GetDgnModel", &TextBlockProperties::GetDgnModelR, py::return_value_policy::reference_internal);

    c1.def_property("Backwards", &TextBlockProperties::IsBackwards, &TextBlockProperties::SetIsBackwards);
    c1.def("IsBackwards", &TextBlockProperties::IsBackwards, DOC(Bentley, DgnPlatform, TextBlockProperties, IsBackwards));
    c1.def("SetIsBackwards", &TextBlockProperties::SetIsBackwards, "backwards"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetIsBackwards));
    c1.def("IsBackwardsOverridden", &TextBlockProperties::IsBackwardsOverridden, DOC(Bentley, DgnPlatform, TextBlockProperties, IsBackwardsOverridden));
    c1.def("ClearIsBackwardsOverride", &TextBlockProperties::ClearIsBackwardsOverride, DOC(Bentley, DgnPlatform, TextBlockProperties, ClearIsBackwardsOverride));

    c1.def_property("UpsideDown", &TextBlockProperties::IsUpsideDown, &TextBlockProperties::SetIsUpsideDown);
    c1.def("IsUpsideDown", &TextBlockProperties::IsUpsideDown, DOC(Bentley, DgnPlatform, TextBlockProperties, IsUpsideDown));
    c1.def("SetIsUpsideDown", &TextBlockProperties::SetIsUpsideDown, "upsideDown"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetIsUpsideDown));
    c1.def("IsUpsideDownOverridden", &TextBlockProperties::IsUpsideDownOverridden, DOC(Bentley, DgnPlatform, TextBlockProperties, IsUpsideDownOverridden));
    c1.def("ClearIsUpsideDownOverride", &TextBlockProperties::ClearIsUpsideDownOverride, DOC(Bentley, DgnPlatform, TextBlockProperties, ClearIsUpsideDownOverride));

    c1.def_property("ViewIndependent", &TextBlockProperties::IsViewIndependent, &TextBlockProperties::SetIsViewIndependent);
    c1.def("IsViewIndependent", &TextBlockProperties::IsViewIndependent, DOC(Bentley, DgnPlatform, TextBlockProperties, IsViewIndependent));
    c1.def("SetIsViewIndependent", &TextBlockProperties::SetIsViewIndependent, "viewIndependent"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetIsViewIndependent));

    c1.def_property("Vertical", &TextBlockProperties::IsVertical, &TextBlockProperties::SetIsVertical);
    c1.def("IsVertical", &TextBlockProperties::IsVertical, DOC(Bentley, DgnPlatform, TextBlockProperties, IsVertical));
    c1.def("SetIsVertical", &TextBlockProperties::SetIsVertical, "vertical"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetIsVertical));
    c1.def("IsVerticalOverridden", &TextBlockProperties::IsVerticalOverridden, DOC(Bentley, DgnPlatform, TextBlockProperties, IsVerticalOverridden));
    c1.def("ClearIsVerticalOverride", &TextBlockProperties::ClearIsVerticalOverride, DOC(Bentley, DgnPlatform, TextBlockProperties, ClearIsVerticalOverride));

    c1.def_property("MaxCharactersPerLine", &TextBlockProperties::GetMaxCharactersPerLine, &TextBlockProperties::SetMaxCharactersPerLine);
    c1.def("GetMaxCharactersPerLine", &TextBlockProperties::GetMaxCharactersPerLine, DOC(Bentley, DgnPlatform, TextBlockProperties, GetMaxCharactersPerLine));
    c1.def("SetMaxCharactersPerLine", &TextBlockProperties::SetMaxCharactersPerLine, "maxChar"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetMaxCharactersPerLine));
    c1.def("IsMaxCharactersPerLineOverridden", &TextBlockProperties::IsMaxCharactersPerLineOverridden, DOC(Bentley, DgnPlatform, TextBlockProperties, IsMaxCharactersPerLineOverridden));
    c1.def("ClearMaxCharactersPerLineOverride", &TextBlockProperties::ClearMaxCharactersPerLineOverride, DOC(Bentley, DgnPlatform, TextBlockProperties, ClearMaxCharactersPerLineOverride));

    c1.def_property("DocumentWidth", &TextBlockProperties::GetDocumentWidth, &TextBlockProperties::SetDocumentWidth);
    c1.def("GetDocumentWidth", &TextBlockProperties::GetDocumentWidth, DOC(Bentley, DgnPlatform, TextBlockProperties, GetDocumentWidth));
    c1.def("SetDocumentWidth", &TextBlockProperties::SetDocumentWidth, "width"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetDocumentWidth));

    c1.def_property("AnnotationScale", &TextBlockProperties::GetAnnotationScale, &TextBlockProperties::SetAnnotationScale);
    c1.def("GetAnnotationScale", &TextBlockProperties::GetAnnotationScale, DOC(Bentley, DgnPlatform, TextBlockProperties, GetAnnotationScale));
    c1.def("SetAnnotationScale", &TextBlockProperties::SetAnnotationScale, "scale"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, SetAnnotationScale));

    c1.def("HasAnnotationScale", &TextBlockProperties::HasAnnotationScale, DOC(Bentley, DgnPlatform, TextBlockProperties, HasAnnotationScale));
    c1.def("ClearAnnotationScale", &TextBlockProperties::ClearAnnotationScale, DOC(Bentley, DgnPlatform, TextBlockProperties, ClearAnnotationScale));

    c1.def("ApplyScale", &TextBlockProperties::ApplyScale, "scale"_a, DOC(Bentley, DgnPlatform, TextBlockProperties, ApplyScale));

    //===================================================================================
    // struct TextBlock
    py::class_< TextBlock, TextBlockPtr> c2(m, "TextBlock");

    c2.def("AppendField", py::overload_cast<TextFieldCR>(&TextBlock::AppendField), "field"_a, DOC(Bentley, DgnPlatform, TextBlock, AppendField));
    c2.def("InsertField", &TextBlock::InsertField, "caret"_a, "field"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertField));
    c2.def("GetField", &TextBlock::GetField, "caret"_a, DOC(Bentley, DgnPlatform, TextBlock, GetField));
    c2.def("SetField", py::overload_cast<CaretR, TextFieldCR>(&TextBlock::SetField), "caret"_a, "field"_a, DOC(Bentley, DgnPlatform, TextBlock, SetField));
    c2.def("ValidateFields", &TextBlock::ValidateFields, DOC(Bentley, DgnPlatform, TextBlock, ValidateFields));

    c2.def(py::init(py::overload_cast<DgnModelR>(&TextBlock::Create)), "dgnModel"_a);
    
    c2.def(py::init(py::overload_cast<TextBlockPropertiesCR, ParagraphPropertiesCR, RunPropertiesCR, DgnModelR>(&TextBlock::Create)),
           "textBlockProps"_a, "paraProps"_a, "runProps"_a, "dgnModel"_a);

    c2.def(py::init(py::overload_cast<DgnTextStyleCR, DgnModelR>(&TextBlock::Create)), "textStyle"_a, "dgnModel"_a);

    c2.def("CreateStartCaret", &TextBlock::CreateStartCaret, DOC(Bentley, DgnPlatform, TextBlock, CreateStartCaret));
    c2.def("CreateEndCaret", &TextBlock::CreateEndCaret, DOC(Bentley, DgnPlatform, TextBlock, CreateEndCaret));
    
    c2.def_property_readonly("DgnModel", &TextBlock::GetDgnModelR);
    c2.def("GetDgnModel", &TextBlock::GetDgnModelR, py::return_value_policy::reference_internal);

    c2.def_property("Properties", &TextBlock::GetProperties, &TextBlock::SetProperties);
    c2.def("GetProperties", &TextBlock::GetProperties, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextBlock, GetProperties));
    c2.def("SetProperties", &TextBlock::SetProperties, "properties"_a, DOC(Bentley, DgnPlatform, TextBlock, SetProperties));
    
    c2.def_property("ParagraphPropertiesForAdd", &TextBlock::GetParagraphPropertiesForAddR, &TextBlock::SetParagraphPropertiesForAdd);
    c2.def("GetParagraphPropertiesForAdd", &TextBlock::GetParagraphPropertiesForAddR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextBlock, GetParagraphPropertiesForAdd));
    c2.def("SetParagraphPropertiesForAdd", &TextBlock::SetParagraphPropertiesForAdd, "properties"_a, DOC(Bentley, DgnPlatform, TextBlock, SetParagraphPropertiesForAdd));
    
    c2.def_property("RunPropertiesForAdd", &TextBlock::GetRunPropertiesForAddR, &TextBlock::SetRunPropertiesForAdd);
    c2.def("GetRunPropertiesForAdd", &TextBlock::GetRunPropertiesForAddR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextBlock, GetRunPropertiesForAdd));
    c2.def("SetRunPropertiesForAdd", &TextBlock::SetRunPropertiesForAdd, "properties"_a, DOC(Bentley, DgnPlatform, TextBlock, SetRunPropertiesForAdd));
    
    c2.def_property("UserOrigin", &TextBlock::GetUserOrigin, &TextBlock::SetUserOrigin);
    c2.def("GetUserOrigin", &TextBlock::GetUserOrigin, DOC(Bentley, DgnPlatform, TextBlock, GetUserOrigin));
    c2.def("SetUserOrigin", &TextBlock::SetUserOrigin, "origin"_a, DOC(Bentley, DgnPlatform, TextBlock, SetUserOrigin));
    
    c2.def_property("Orientation", &TextBlock::GetOrientation, &TextBlock::SetOrientation);
    c2.def("GetOrientation", &TextBlock::GetOrientation, DOC(Bentley, DgnPlatform, TextBlock, GetOrientation));
    c2.def("SetOrientation", &TextBlock::SetOrientation, "rMatrix"_a, DOC(Bentley, DgnPlatform, TextBlock, SetOrientation));

    c2.def("Clone", &TextBlock::Clone, DOC(Bentley, DgnPlatform, TextBlock, Clone));
    c2.def("IsEmpty", &TextBlock::IsEmpty, DOC(Bentley, DgnPlatform, TextBlock, IsEmpty));
    c2.def("__bool__", [] (TextBlock& self) { return !self.IsEmpty(); });

    c2.def("AppendText", &TextBlock::AppendText, "text"_a, DOC(Bentley, DgnPlatform, TextBlock, AppendText));
    c2.def("AppendParagraphBreak", &TextBlock::AppendParagraphBreak, DOC(Bentley, DgnPlatform, TextBlock, AppendParagraphBreak));
    c2.def("AppendLineBreak", &TextBlock::AppendLineBreak, DOC(Bentley, DgnPlatform, TextBlock, AppendLineBreak));
    c2.def("AppendTab", &TextBlock::AppendTab, DOC(Bentley, DgnPlatform, TextBlock, AppendTab));

    c2.def("AppendStackedFraction", 
           py::overload_cast<WCharCP, WCharCP, StackedFractionType, StackedFractionAlignment>(&TextBlock::AppendStackedFraction),
           "numeratorText"_a, "denominatorText"_a, "fractionType"_a, "alignment"_a, DOC(Bentley, DgnPlatform, TextBlock, AppendStackedFraction));
    
    c2.def("AppendEnterDataField", &TextBlock::AppendEnterDataField, "value"_a, "totalLength"_a, "justification"_a, DOC(Bentley, DgnPlatform, TextBlock, AppendEnterDataField));
    c2.def("InsertText", &TextBlock::InsertText, "caret"_a, "text"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertText));
    c2.def("InsertParagraphBreak", &TextBlock::InsertParagraphBreak, "caret"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertParagraphBreak));
    c2.def("InsertLineBreak", &TextBlock::InsertLineBreak, "caret"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertLineBreak));
    c2.def("InsertTab", &TextBlock::InsertTab, "caret"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertTab));
    c2.def("InsertStackedFraction", &TextBlock::InsertStackedFraction, "caret"_a, "numeratorText"_a, "denominatorText"_a, "fractionType"_a, "alignment"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertStackedFraction));
    c2.def("InsertEnterDataField", &TextBlock::InsertEnterDataField, "caret"_a, "value"_a, "totalLength"_a, "justification"_a, DOC(Bentley, DgnPlatform, TextBlock, InsertEnterDataField));
    c2.def("Remove", &TextBlock::Remove, "from"_a, "to"_a, DOC(Bentley, DgnPlatform, TextBlock, Remove));
    c2.def("ToString", py::overload_cast<>(&TextBlock::ToString, py::const_), DOC(Bentley, DgnPlatform, TextBlock, ToString));
    c2.def("ToString", py::overload_cast<CaretCR, CaretCR>(&TextBlock::ToString, py::const_), "from"_a, "to"_a, DOC(Bentley, DgnPlatform, TextBlock, ToString));
    c2.def("PerformLayout", &TextBlock::PerformLayout, DOC(Bentley, DgnPlatform, TextBlock, PerformLayout));
    
    c2.def_property_readonly("NominalRange", &TextBlock::GetNominalRange);
    c2.def("GetNominalRange", &TextBlock::GetNominalRange, DOC(Bentley, DgnPlatform, TextBlock, GetNominalRange));
    
    c2.def("IsAlongElement", &TextBlock::IsAlongElement, DOC(Bentley, DgnPlatform, TextBlock, IsAlongElement));    
    c2.def("ApplyTextStyle", &TextBlock::ApplyTextStyle, "textStyle"_a, "respectOverrides"_a, "from"_a, "to"_a, DOC(Bentley, DgnPlatform, TextBlock, ApplyTextStyle));
    c2.def("SetStyleProperties", &TextBlock::SetStyleProperties, "textStyle"_a, "propMask"_a, "from"_a, "to"_a, DOC(Bentley, DgnPlatform, TextBlock, SetStyleProperties));

    if (true)
        {
        //===================================================================================
        // struct FindTextParameters
        py::class_< TextBlock::FindTextParameters, TextBlock::FindTextParametersPtr> c2_1(c2, "FindTextParameters");

        c2_1.def(py::init(&TextBlock::FindTextParameters::Create));
        
        c2_1.def_property("IsUseRegularExpressions", &TextBlock::FindTextParameters::UseRegularExpressions, &TextBlock::FindTextParameters::SetUseRegularExpressions);
        c2_1.def("UseRegularExpressions", &TextBlock::FindTextParameters::UseRegularExpressions);
        c2_1.def("SetUseRegularExpressions", &TextBlock::FindTextParameters::SetUseRegularExpressions, "regularExpr"_a);
        
        c2_1.def_property("IsMatchWholeWords", &TextBlock::FindTextParameters::MatchWholeWords, &TextBlock::FindTextParameters::SetMatchWholeWords);
        c2_1.def("MatchWholeWords", &TextBlock::FindTextParameters::MatchWholeWords);
        c2_1.def("SetMatchWholeWords", &TextBlock::FindTextParameters::SetMatchWholeWords, "matchWholeWords"_a);
        
        c2_1.def_property("IsMatchCase", &TextBlock::FindTextParameters::MatchCase, &TextBlock::FindTextParameters::SetMatchCase);
        c2_1.def("MatchCase", &TextBlock::FindTextParameters::MatchCase);
        c2_1.def("SetMatchCase", &TextBlock::FindTextParameters::SetMatchCase, "matchCase"_a);

        //===================================================================================
        // struct FindTextMatch
        py::class_< TextBlock::FindTextMatch, TextBlock::FindTextMatchPtr> c2_2(c2, "FindTextMatch");

        c2_2.def("CanBeModified", &TextBlock::FindTextMatch::CanBeModified);

        c2_2.def_property_readonly("MatchStart", &TextBlock::FindTextMatch::GetMatchStart);
        c2_2.def("GetMatchStart", &TextBlock::FindTextMatch::GetMatchStart);
        
        c2_2.def_property_readonly("MatchEnd", &TextBlock::FindTextMatch::GetMatchEnd);
        c2_2.def("GetMatchEnd", &TextBlock::FindTextMatch::GetMatchEnd);
        }

    c2.def("FindText", 
           py::overload_cast<WCharCP, TextBlock::FindTextParametersCP, CaretCP, CaretCP>(&TextBlock::FindText, py::const_),
           "searchString"_a, "findParams"_a, "searchStart"_a, "searchEnd"_a);

    c2.def("ReplaceText", &TextBlock::ReplaceText, "newText"_a, "start"_a, "end"_a, DOC(Bentley, DgnPlatform, TextBlock, ReplaceText));
    }