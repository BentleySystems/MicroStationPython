/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\indentation.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/Indentation.h>



static const char * __doc_Bentley_DgnPlatform_IndentationData_SetTabStops =R"doc(Sets the collection of tab stops.

See also:
    GetTabStops for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_IndentationData_GetTabStops =R"doc(Gets a (read-only) collection of tab stops. @note These values are in
UORs. @note The paragraph indent is treated as a soft tab stop, and is
not present in this collection.)doc";

static const char * __doc_Bentley_DgnPlatform_IndentationData_SetHangingIndent =R"doc(Sets the indent for the non-first lines of the paragraph.

See also:
    SetHangingIndent for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_IndentationData_GetHangingIndent =R"doc(Gets the indent for the non-first lines of the paragraph. @note The
first line has a unique indent, and never obeys this value;

See also:
    GetFirstLineIndent.)doc";

static const char * __doc_Bentley_DgnPlatform_IndentationData_SetFirstLineIndent =R"doc(Sets the first-line indent for the paragraph.

See also:
    GetFirstLineIndent for additional notes)doc";

static const char * __doc_Bentley_DgnPlatform_IndentationData_GetFirstLineIndent =R"doc(Gets the first-line indent for the paragraph. @note This is a unqiue
indent for the first line of the paragraph; the rest of the lines are
indented according to the paragraph indent.)doc";

static const char * __doc_Bentley_DgnPlatform_IndentationData_Clone =R"doc(Creates a deep copy of this instance.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Indentation(py::module_& m)
    {
    //===================================================================================
    // struct IndentationData
    py::class_< IndentationData, IndentationDataPtr> c1(m, "IndentationData");

    c1.def(py::init(&IndentationData::Create));
    c1.def("Clone", &IndentationData::Clone, DOC(Bentley, DgnPlatform, IndentationData, Clone));

    c1.def_property("FirstLineIndent", &IndentationData::GetFirstLineIndent, &IndentationData::SetFirstLineIndent);
    c1.def("GetFirstLineIndent", &IndentationData::GetFirstLineIndent, DOC(Bentley, DgnPlatform, IndentationData, GetFirstLineIndent));
    c1.def("SetFirstLineIndent", &IndentationData::SetFirstLineIndent, "value"_a, DOC(Bentley, DgnPlatform, IndentationData, SetFirstLineIndent));
    
    c1.def_property("HangingIndent", &IndentationData::GetHangingIndent, &IndentationData::SetHangingIndent);
    c1.def("GetHangingIndent", &IndentationData::GetHangingIndent, DOC(Bentley, DgnPlatform, IndentationData, GetHangingIndent));
    c1.def("SetHangingIndent", &IndentationData::SetHangingIndent, "value"_a, DOC(Bentley, DgnPlatform, IndentationData, SetHangingIndent));
    
    c1.def_property("TabStops", &IndentationData::GetTabStops, py::overload_cast<T_DoubleVectorCR>(&IndentationData::SetTabStops));
    c1.def("GetTabStops", &IndentationData::GetTabStops, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IndentationData, GetTabStops));
    c1.def("SetTabStops", py::overload_cast<T_DoubleVectorCR>(&IndentationData::SetTabStops), "stops"_a, DOC(Bentley, DgnPlatform, IndentationData, SetTabStops));
    }