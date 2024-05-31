/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\compounddrawstate.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_CompoundDrawState_GetConditionalBlockIndices =R"doc(return (reference to) the stored block indices.)doc";

static const char * __doc_Bentley_Geom_CompoundDrawState_SetDrawGeomMethodIndex =R"doc(set the drawGeom index.)doc";

static const char * __doc_Bentley_Geom_CompoundDrawState_Load =R"doc(Copy data from the caller's memory into this CompoundDrawState.)doc";

static const char * __doc_Bentley_Geom_CompoundDrawState_Store =R"doc(copy all data into the caller's bvector.)doc";

static const char * __doc_Bentley_Geom_CompoundDrawState_GetDebugString =R"doc(Return debug representation.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CompoundDrawState(py::module_& m)
    {
    //===================================================================================
    // struct CompoundDrawState
    py::class_<CompoundDrawState, CompoundDrawStatePtr> c1(m, "CompoundDrawState");

    c1.def(py::init(py::overload_cast<>(&CompoundDrawState::Create)));
    c1.def(py::init(py::overload_cast<size_t, UInt64Array&>(&CompoundDrawState::Create)), "drawIndex"_a, "conditionBlockIndices"_a);
    c1.def(py::init(py::overload_cast<CompoundDrawStateCR>(&CompoundDrawState::Create)), "rhs"_a);
    
    c1.def("__copy__", [](const CompoundDrawState& self)
        {
        return CompoundDrawState(self);
        });

    c1.def_property_readonly("DebugString", &CompoundDrawState::GetDebugString);
    c1.def("GetDebugString", &CompoundDrawState::GetDebugString, DOC(Bentley, Geom, CompoundDrawState, GetDebugString));

    c1.def(py::self == py::self);
    c1.def(py::self < py::self);

    c1.def("Store", &CompoundDrawState::Store, DOC(Bentley, Geom, CompoundDrawState, Store));
    c1.def("Load", [] (CompoundDrawStateR self, UInt16Array const& data)
           {
           self.Load((void const*) &data[0], sizeof(uint16_t) * data.size());
           }, "data"_a, DOC(Bentley, Geom, CompoundDrawState, Load));

    c1.def_property("DrawGeomMethodIndex", &CompoundDrawState::GetDrawGeomMethodIndex, &CompoundDrawState::SetDrawGeomMethodIndex);
    c1.def("GetDrawGeomMethodIndex", &CompoundDrawState::GetDrawGeomMethodIndex);
    c1.def("SetDrawGeomMethodIndex", &CompoundDrawState::SetDrawGeomMethodIndex, "index"_a, DOC(Bentley, Geom, CompoundDrawState, SetDrawGeomMethodIndex));

    c1.def_property_readonly("ConditionalBlockIndices", &CompoundDrawState::GetConditionalBlockIndicesR);
    c1.def("GetConditionalBlockIndices", &CompoundDrawState::GetConditionalBlockIndicesR, py::return_value_policy::reference_internal, DOC(Bentley, Geom, CompoundDrawState, GetConditionalBlockIndices));

    c1.def("__repr__", [] (CompoundDrawState& self) { return self.GetDebugString().c_str(); });
    }