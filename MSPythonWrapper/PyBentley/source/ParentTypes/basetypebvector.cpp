/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\PyBentley.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_Bentley.h>

/*---------------------------------------------------------------------------------**//**
* STL-liked container instantiation.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void bind_container_PyBentley(py::module_& m)
    {
    // bvector instantiation
    py::bind_vector< Int8Array >(m, "Int8Array", py::module_local(false));
    py::bind_vector< UInt8Array >(m, "UInt8Array", py::module_local(false));
    py::bind_vector< Int16Array >(m, "Int16Array", py::module_local(false));
    py::bind_vector< UInt16Array >(m, "UInt16Array", py::module_local(false));
    py::bind_vector< Int32Array >(m, "Int32Array", py::module_local(false));
    py::bind_vector< UInt32Array >(m, "UInt32Array", py::module_local(false));
    py::bind_vector< Int64Array >(m, "Int64Array", py::module_local(false));
    py::bind_vector< Int64VecArray >(m, "Int64VecArray", py::module_local(false));
    py::bind_vector< UInt64Array >(m, "UInt64Array", py::module_local(false));
    py::bind_vector< UInt64VecArray >(m, "UInt64VecArray", py::module_local(false));
    py::bind_vector< FloatArray >(m, "FloatArray", py::module_local(false));
    py::bind_vector< DoubleArray >(m, "DoubleArray", py::module_local(false));
    py::bind_vector< BoolArray >(m, "BoolArray", py::module_local(false));

    //===================================================================================
    // struct UpdateSequenceList
    py::class_< UpdateSequenceList, bvector< ElementId> > c0(m, "UpdateSequenceList");
    c0.def(py::init<>());
    }
