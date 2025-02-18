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
* Forward declarations for class definition generators.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Base64Utilities(py::module_&);
void def_BeDirectoryIterator(py::module_&);
void def_BeFile(py::module_&);
void def_BeFileListIterator(py::module_&);
void def_BeFileName(py::module_&);
void def_CodePages(py::module_&);
void def_ValueFormat_r(py::module_&);
void def_DateTime(py::module_&);
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
    m.doc() = "The MSPyBentley library, is the lowest level Python API library for MicroStation, it provides basic services such as String, File, Date manipulation which are then used by child libraries";

    // class defines
    def_WString(m);
    def_Base64Utilities(m);
    def_BeFile(m);
    def_BeFileListIterator(m);
    def_BeFileName(m);
    def_CodePages(m);
    def_ValueFormat_r(m);    
    def_DateTime(m);
    def_HeapZone(m);    
    def_BeStringUtilities(m);
    def_NameSpaceManager(m);
    }
