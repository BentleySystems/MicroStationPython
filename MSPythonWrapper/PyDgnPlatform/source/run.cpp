/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\run.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/Run.h>



static const char * __doc_Bentley_DgnPlatform_Run_ToString =R"doc(Creates a simple string representation of this run. @note Non
CharStream runs will encode themselves as a string, which will not
necessarily convey enough information for a 1:1 correlation (e.g. both
a date in a CharStream and a Fraction may appear the same:" 1 / 2 "; you
must dynamic_cast the run object to determine full information).)doc";

static const char * __doc_Bentley_DgnPlatform_Run_GetProperties =R"doc(Gets the properties for this run.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Run(py::module_& m)
    {
    //===================================================================================
    // struct Run
    py::class_<Run> c1(m, "Run");

    c1.def_property_readonly("Properties", &Run::GetProperties);
    c1.def("GetProperties", &Run::GetProperties, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, Run, GetProperties));

    c1.def("ToString", py::overload_cast<>(&Run::ToString, py::const_), DOC(Bentley, DgnPlatform, Run, ToString));
    }