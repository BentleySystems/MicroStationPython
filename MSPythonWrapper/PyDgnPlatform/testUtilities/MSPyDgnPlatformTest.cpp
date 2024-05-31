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
* @bsimethod                                                                       2/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECTestHelpers(py::module_& m);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyDgnPlatformTest, m)
    {
    // Document for module
    m.doc() = "Pybind11 wrapper for ECTestHelpers for python test";

    def_ECTestHelpers (m);
    }


