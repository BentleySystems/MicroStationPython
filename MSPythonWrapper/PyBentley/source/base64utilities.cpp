/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentley\source\base64utilities.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

#include <Bentley/Base64Utilities.h>





DEFINE_NODELETE_HOLDER_TYPE(Base64Utilities);

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Base64Utilities(py::module_& m)
    {
    //===================================================================================
    // struct Base64Utilities
    py::class_< Base64Utilities, Base64UtilitiesPtr> c1(m, "Base64Utilities");

    c1.def_static("Encode", py::overload_cast<Utf8StringCR>(&Base64Utilities::Encode), "stringToEncode"_a);
    c1.def_static("Decode", py::overload_cast<Utf8StringCR>(&Base64Utilities::Decode), "encodedString"_a);
    c1.def_static("Alphabet", &Base64Utilities::Alphabet, py::return_value_policy::reference);
    c1.def_static("MatchesAlphabet", &Base64Utilities::MatchesAlphabet, "input"_a);
    }