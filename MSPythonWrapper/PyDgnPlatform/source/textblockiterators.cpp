/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textblockiterator.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/TextBlockIterators.h>



static const char * __doc_Bentley_DgnPlatform_RunRange_GetEndCaret =R"doc(Gets the end caret used to create this range.)doc";

static const char * __doc_Bentley_DgnPlatform_RunRange_GetStartCaret =R"doc(Gets the start caret used to create this range.)doc";

static const char * __doc_Bentley_DgnPlatform_RunIterator_ToCaret =R"doc(Attempts to create a Caret representing this iterator's paragraph.

:returns:
    Can return NULL if this is an end iterator (one past the last
    valid).)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphRange_GetEndCaret =R"doc(Gets the end caret used to create this range.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphRange_GetStartCaret =R"doc(Gets the start caret used to create this range.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphIterator_ToCaret =R"doc(Attempts to create a Caret representing this iterator's paragraph.

:returns:
    Can return NULL if this is an end iterator (one past the last
    valid).)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphIterator_CreateRunEnd =R"doc(Creates a RunIterator pointing just past the last run in the current
paragraph.)doc";

static const char * __doc_Bentley_DgnPlatform_ParagraphIterator_CreateRunBegin =R"doc(Creates a RunIterator pointing at the first run in the current
paragraph.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextBlockIterators(py::module_& m)
    {
    //===================================================================================
    // struct ParagraphIterator
    py::class_< ParagraphIterator> c1(m, "ParagraphIterator");

    c1.def(py::self == py::self);
    c1.def(py::self != py::self);
    c1.def("CreateRunBegin", &ParagraphIterator::CreateRunBegin, DOC(Bentley, DgnPlatform, ParagraphIterator, CreateRunBegin));
    c1.def("CreateRunEnd", &ParagraphIterator::CreateRunEnd, DOC(Bentley, DgnPlatform, ParagraphIterator, CreateRunEnd));
    c1.def("ToCaret", &ParagraphIterator::ToCaret, DOC(Bentley, DgnPlatform, ParagraphIterator, ToCaret));

    //===================================================================================
    // struct ParagraphRange
    py::class_< ParagraphRange> c2(m, "ParagraphRange");

    c2.def(py::init<TextBlockCR>(), "textBlock"_a);
    c2.def(py::init<CaretCR, CaretCR>(), "begin"_a, "end"_a);
    
    c2.def_property_readonly("StartCaret", &ParagraphRange::GetStartCaret);
    c2.def("GetStartCaret", &ParagraphRange::GetStartCaret, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParagraphRange, GetStartCaret));
    
    c2.def_property_readonly("EndCaret", &ParagraphRange::GetEndCaret);
    c2.def("GetEndCaret", &ParagraphRange::GetEndCaret, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParagraphRange, GetEndCaret));
    //c2.def("__iter__", [] (ParagraphRange& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct RunIterator
    py::class_< RunIterator> c3(m, "RunIterator");

    c3.def(py::self == py::self);
    c3.def(py::self != py::self);
    
    c3.def_property_readonly("CurrentParagraph", [] (RunIterator const& self) { return std::unique_ptr<Paragraph, py::nodelete>(const_cast<ParagraphP>(self.GetCurrentParagraphCP())); });
    c3.def("GetCurrentParagraph", [] (RunIterator const& self) { return std::unique_ptr<Paragraph, py::nodelete>(const_cast<ParagraphP>(self.GetCurrentParagraphCP())); });

    c3.def("ToCaret", &RunIterator::ToCaret, DOC(Bentley, DgnPlatform, RunIterator, ToCaret));

    //===================================================================================
    // struct RunRange
    py::class_< RunRange> c4(m, "RunRange");

    c4.def(py::init<TextBlockCR>(), "textBlock"_a);
    c4.def(py::init<CaretCR, CaretCR>(), "begin"_a, "end"_a);
    
    c4.def_property_readonly("StartCaret", &RunRange::GetStartCaret);
    c4.def("GetStartCaret", &RunRange::GetStartCaret, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RunRange, GetStartCaret));
    
    c4.def_property_readonly("EndCaret", &RunRange::GetEndCaret);
    c4.def("GetEndCaret", &RunRange::GetEndCaret, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RunRange, GetEndCaret));
    
    c4.def("__iter__", [] (RunRange& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }