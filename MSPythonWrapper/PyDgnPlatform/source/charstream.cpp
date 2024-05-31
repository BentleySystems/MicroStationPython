/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\charstream.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/CharStream.h>



static const char * __doc_Bentley_DgnPlatform_EdfCharStream_GetEdfJustification =R"doc(Returns the justification of this EDF. This justification controls how
space characters are distributed to reach the total length.)doc";

static const char * __doc_Bentley_DgnPlatform_CharStream_GetString =R"doc(Returns this instance's internal string. It is returned as Unicode,
regardless of the fonts' encoding. @note This is more efficient than
Run::ToString, becuse it returns a reference to this instance's
internal string, as opposed to creating a new one.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CharStream(py::module_& m)
    {
    //===================================================================================
    // struct CharStream
    py::class_< CharStream, Run> c1(m, "CharStream");

    c1.def_property_readonly("String", &CharStream::GetString);
    c1.def("GetString", &CharStream::GetString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CharStream, GetString));

    //===================================================================================
    // struct EdfCharStream
    py::class_< EdfCharStream, CharStream> c2(m, "EdfCharStream");

    c2.def_property_readonly("EdfJustification", &EdfCharStream::GetEdfJustification);
    c2.def("GetEdfJustification", &EdfCharStream::GetEdfJustification, DOC(Bentley, DgnPlatform, EdfCharStream, GetEdfJustification));
    }