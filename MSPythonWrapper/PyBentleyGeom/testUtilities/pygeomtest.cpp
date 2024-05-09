/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\test\pygeomtest.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* Forward declarations for class definition generators.
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Checkers(py::module_&);
void def_DoubleOps(py::module_&);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyGeomTest, m)
    {
    // Document for module
    m.doc() = "Pybind11 wrapper for GeomLibsTest.exe for python test";

    def_Checkers(m);
    def_DoubleOps(m);

    }


