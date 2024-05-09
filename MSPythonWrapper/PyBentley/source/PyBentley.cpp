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
    }

/*---------------------------------------------------------------------------------**//**
* Forward declarations for class definition generators.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Base64Utilities(py::module_&);
void def_BeDirectoryIterator(py::module_&);
void def_BeFile(py::module_&);
void def_BeFileListIterator(py::module_&);
void def_BeFileName(py::module_&);
void def_BeTextFile(py::module_&);
void def_CodePages(py::module_&);
void def_ValueFormat(py::module_&);
void def_ValueFormat_r(py::module_&);
void def_DateTime(py::module_&);
void def_Dsig(py::module_&);
void def_HeapZone(py::module_&);
void def_WString(py::module_&);
void def_BeStringUtilities(py::module_&);
void def_NameSpaceManager (py::module_&);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyBentley, m)
    {
    // Document for module
    m.doc() = "Pybind11 wrapper for Bentley.dll";

    // class defines
    bind_container_PyBentley (m);

    def_WString(m);
    def_Base64Utilities(m);
    def_BeFile(m);
    def_BeFileListIterator(m);
    def_BeFileName(m);
    def_BeTextFile(m);
    def_CodePages(m);
    def_ValueFormat(m);
    def_ValueFormat_r(m);    
    def_DateTime(m);
    def_Dsig(m);
    def_HeapZone(m);    
    def_BeStringUtilities(m);
    def_NameSpaceManager(m);
    }
