/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textstring.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextString.h>



static const char * __doc_Bentley_DgnPlatform_TextString_GetRotMatrix =R"doc(Gets the orientation.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_GetString =R"doc(Gets the Unicode string.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_IsUnicodeFont =R"doc(Determines if the font is effectively Unicode (e.g. 'normal' font is
Unicode, and no SHX big font exists).)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_IsTrueTypeFont =R"doc(Determines if the properties' font is a TrueType font.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_IsShxFont =R"doc(Determines if the properties' font is an SHX font.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_IsRscFont =R"doc(Determines if the properties' font is an RSC font.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_GetProperties =R"doc(Gets the formatting properties.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_SetOriginFromUserOrigin =R"doc(Sets the user origin of this instance. \note The internal cached data
is independent of user origin, so this can be changed after
initialization.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_ComputeUserOrigin =R"doc(Gets the user origin of this instance.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_GetOrigin =R"doc(Gets the lower-left origin of the text.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_GetHeight =R"doc(Gets the height of the extents.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_GetWidth =R"doc(Gets the width of the extents.)doc";

static const char * __doc_Bentley_DgnPlatform_TextString_GetExtents =R"doc(Gets the bounds of this entire instance in local coordinates. \note
The bounds computed are known as the " justification range ", and
describe the bounds that are used for positioning and snapping. This
is opposed to pure exact (black box) and nominal (cell box) ranges.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextString(py::module_& m)
    {
    //===================================================================================
    // struct TextString
    py::class_< TextString, TextStringPtr> c1(m, "TextString");

    c1.def(py::init(py::overload_cast<>(TextString::Create)));
    c1.def(py::init(py::overload_cast<WCharCP, DPoint3dCP, RotMatrixCP, TextStringPropertiesCR>(TextString::Create)), "string"_a, "lowerLeft"_a, "rMatrix"_a, "props"_a);
    
    c1.def_property_readonly("Extents", &TextString::GetExtents);
    c1.def("GetExtents", &TextString::GetExtents, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextString, GetExtents));
    
    c1.def_property_readonly("Width", &TextString::GetWidth);
    c1.def("GetWidth", &TextString::GetWidth, DOC(Bentley, DgnPlatform, TextString, GetWidth));
    
    c1.def_property_readonly("Height", &TextString::GetHeight);
    c1.def("GetHeight", &TextString::GetHeight, DOC(Bentley, DgnPlatform, TextString, GetHeight));
    
    c1.def_property_readonly("Origin", &TextString::GetOrigin);
    c1.def("GetOrigin", &TextString::GetOrigin, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextString, GetOrigin));
    
    c1.def("ComputeUserOrigin", &TextString::ComputeUserOrigin, "origin"_a, DOC(Bentley, DgnPlatform, TextString, ComputeUserOrigin));
    c1.def("SetOriginFromUserOrigin", &TextString::SetOriginFromUserOrigin, "userOrigin"_a, DOC(Bentley, DgnPlatform, TextString, SetOriginFromUserOrigin));
    
    c1.def_property_readonly("Properties", &TextString::GetProperties);
    c1.def("GetProperties", &TextString::GetProperties, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextString, GetProperties));
    
    c1.def("IsRscFont", &TextString::IsRscFont, DOC(Bentley, DgnPlatform, TextString, IsRscFont));    
    c1.def("IsShxFont", &TextString::IsShxFont, DOC(Bentley, DgnPlatform, TextString, IsShxFont));    
    c1.def("IsTrueTypeFont", &TextString::IsTrueTypeFont, DOC(Bentley, DgnPlatform, TextString, IsTrueTypeFont));    
    c1.def("IsUnicodeFont", &TextString::IsUnicodeFont, DOC(Bentley, DgnPlatform, TextString, IsUnicodeFont));
    
    c1.def_property_readonly("String", &TextString::GetString);
    c1.def("GetString", &TextString::GetString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextString, GetString));

    c1.def_property_readonly("RotMatrix", &TextString::GetRotMatrix);
    c1.def("GetRotMatrix", &TextString::GetRotMatrix, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TextString, GetRotMatrix));
    }