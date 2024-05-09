/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\caret.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/Caret.h>



static const char * __doc_Bentley_DgnPlatform_Caret_CreateRunEnd =R"doc(Creates a RunIterator just beyond this location's run. The resulting
iterator is meant to be exclusive of the current run.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_CreateRunBegin =R"doc(Creates a RunIterator at this location's run. The resulting iterator
is meant to be inclusive of the current run.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_CreateParagraphEnd =R"doc(Creates a ParagraphIterator just beyond this location's paragraph. The
resulting iterator is meant to be exclusive of the current paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_CreateParagraphBegin =R"doc(Creates a ParagraphIterator at this location's paragraph. The
resulting iterator is meant to be inclusive of the current paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToPreviousCharacter =R"doc(Rewinds the caret to the previous character; resets the other sub-run
indices to zero. @note Returns ERROR if this instance is already at
the beginning of the text block.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToPreviousRunInParagraph =R"doc(Rewinds the caret to the previous run in the current paragraph; resets
the other sub-run indices to zero. @note Returns ERROR if this
instance is already at the first run of the current paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToPreviousRun =R"doc(Rewinds the caret to the previous run; resets the other sub-run
indices to zero. @note Returns ERROR if this instance is already at
the beginning of the text block.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToPreviousParagraph =R"doc(Rewinds the caret to the previous paragraph; resets the other sub-
paragraph indices to zero. @note Returns ERROR if this instance is
already at the beginning of the text block.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToNextCharacter =R"doc(Advances the caret to the next character, advancing to the next run if
necessary; resets the other sub-run indices to zero. @note Returns
ERROR if this instance is already at the end of the text block.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToNextRunInParagraph =R"doc(Advances the caret to the next run in the current paragraph; resets
the other sub-run indices to zero. @note Returns ERROR if this
instance is already at the last run of the current paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToNextField =R"doc(Advances the caret to the next run containing a unique field. Fields
can span multiple runs; in this case each adjacent run holds a pointer
to the same field data.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToNextRun =R"doc(Advances the caret to the next run, advancing to the next paragraph if
necessary; resets the other sub-run indices to zero. @note Returns
ERROR if this instance is already at the end of the text block.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_MoveToNextParagraph =R"doc(Advances the caret to the next paragraph; resets the other sub-
paragraph indices to zero. @note Returns ERROR if this instance is
already at the end of the text block.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_GetCurrentField =R"doc(Gets the field at current position, if one exists.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsInField =R"doc(Returns true if there is a field at the current position)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsAtEnd =R"doc(True if this instance is at or beyond the end of its associated
TextBlock. @note The end is one past the last run, similar to an STL
iterator. @note If it is at the end, you cannot move or look next to
the caret.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsAtBeginning =R"doc(True if this instance is at the beginning of its associated TextBlock.
@note If it is at the beginning, you cannot move or look previous to
the caret.)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsAfterOrAt =R"doc(Determines if this caret is after or at another (equivalent to >=).
@note Assumes the same TextBlock (otherwise the answer is
meaningless).)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsAfter =R"doc(Determines if this caret is strictly after another (equivalent to >).
@note Assumes the same TextBlock (otherwise the answer is
meaningless).)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsBeforeOrAt =R"doc(Determines if this caret is before or at another (equivalent to <=).
@note Assumes the same TextBlock (otherwise the answer is
meaningless).)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsBefore =R"doc(Determines if this caret is strictly before another (equivalent to <).
@note Assumes the same TextBlock (otherwise the answer is
meaningless).)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_IsAt =R"doc(Determines if this caret is at the same location as another. @note
This only takes into account indices; two carets may have the same
indices (i.e. this returns true), but appear differently when rendered
in bi-directional text. @note Assumes the same TextBlock (otherwise
the answer is meaningless).)doc";

static const char * __doc_Bentley_DgnPlatform_Caret_Clone =R"doc(Creates a deep copy of this instance.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Caret(py::module_& m)
    {
    //===================================================================================
    // struct Caret
    py::class_< Caret, CaretPtr> c1(m, "Caret");

    c1.def("Clone", &Caret::Clone, DOC(Bentley, DgnPlatform, Caret, Clone));
    c1.def("IsAt", &Caret::IsAt, "caret"_a, DOC(Bentley, DgnPlatform, Caret, IsAt));
    c1.def("IsBefore", &Caret::IsBefore, "caret"_a, DOC(Bentley, DgnPlatform, Caret, IsBefore));
    c1.def("IsBeforeOrAt", &Caret::IsBeforeOrAt, "caret"_a, DOC(Bentley, DgnPlatform, Caret, IsBeforeOrAt));
    c1.def("IsAfter", &Caret::IsAfter, "caret"_a, DOC(Bentley, DgnPlatform, Caret, IsAfter));
    c1.def("IsAfterOrAt", &Caret::IsAfterOrAt, "caret"_a, DOC(Bentley, DgnPlatform, Caret, IsAfterOrAt));
    c1.def("IsAtBeginning", &Caret::IsAtBeginning, DOC(Bentley, DgnPlatform, Caret, IsAtBeginning));
    c1.def("IsAtEnd", &Caret::IsAtEnd, DOC(Bentley, DgnPlatform, Caret, IsAtEnd));

    c1.def_property_readonly("CurrentParagraph", [] (Caret const& self) { return std::unique_ptr<Paragraph, py::nodelete>(const_cast<ParagraphP>(self.GetCurrentParagraphCP())); });
    c1.def("GetCurrentParagraph", [] (Caret const& self) { return std::unique_ptr<Paragraph, py::nodelete>(const_cast<ParagraphP>(self.GetCurrentParagraphCP())); });
    
    c1.def_property_readonly("CurrentRun", &Caret::GetCurrentRunCP);
    c1.def("GetCurrentRun", &Caret::GetCurrentRunCP, py::return_value_policy::reference_internal);
    
    c1.def("IsInField", &Caret::IsInField, DOC(Bentley, DgnPlatform, Caret, IsInField));
    
    c1.def_property_readonly("CurrentField", &Caret::GetCurrentField);
    c1.def("GetCurrentField", &Caret::GetCurrentField, DOC(Bentley, DgnPlatform, Caret, GetCurrentField));
    
    c1.def("PreviousCharacter", &Caret::GetPreviousCharacter);
    c1.def("NextCharacter", &Caret::GetNextCharacter);

    c1.def("MoveToNextParagraph", &Caret::MoveToNextParagraph, DOC(Bentley, DgnPlatform, Caret, MoveToNextParagraph));
    c1.def("MoveToNextRun", &Caret::MoveToNextRun, DOC(Bentley, DgnPlatform, Caret, MoveToNextRun));
    c1.def("MoveToNextField", &Caret::MoveToNextField, DOC(Bentley, DgnPlatform, Caret, MoveToNextField));
    c1.def("MoveToNextRunInParagraph", &Caret::MoveToNextRunInParagraph, DOC(Bentley, DgnPlatform, Caret, MoveToNextRunInParagraph));
    c1.def("MoveToNextCharacter", &Caret::MoveToNextCharacter, DOC(Bentley, DgnPlatform, Caret, MoveToNextCharacter));
    c1.def("MoveToPreviousParagraph", &Caret::MoveToPreviousParagraph, DOC(Bentley, DgnPlatform, Caret, MoveToPreviousParagraph));
    c1.def("MoveToPreviousRun", &Caret::MoveToPreviousRun, DOC(Bentley, DgnPlatform, Caret, MoveToPreviousRun));
    c1.def("MoveToPreviousRunInParagraph", &Caret::MoveToPreviousRunInParagraph, DOC(Bentley, DgnPlatform, Caret, MoveToPreviousRunInParagraph));
    c1.def("MoveToPreviousCharacter", &Caret::MoveToPreviousCharacter, DOC(Bentley, DgnPlatform, Caret, MoveToPreviousCharacter));
    c1.def("CreateParagraphBegin", &Caret::CreateParagraphBegin, DOC(Bentley, DgnPlatform, Caret, CreateParagraphBegin));
    c1.def("CreateParagraphEnd", &Caret::CreateParagraphEnd, DOC(Bentley, DgnPlatform, Caret, CreateParagraphEnd));
    c1.def("CreateRunBegin", &Caret::CreateRunBegin, DOC(Bentley, DgnPlatform, Caret, CreateRunBegin));
    c1.def("CreateRunEnd", &Caret::CreateRunEnd, DOC(Bentley, DgnPlatform, Caret, CreateRunEnd));
    }
