/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\textblockserialization.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextBlock/TextBlockSerialization.h>



static const char * __doc_Bentley_DgnPlatform_TextBlockXmlDeserializer_Deserialize =R"doc(Deserializes the Xml string into the provided TextBlock.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockXmlDeserializer_SetFallbackTextStyle =R"doc(Sets the fallback style to use when a missing style is encountered.
@note If none is provided, a blank / default style will be used
instead when a missing style is encountered. @note This utilizes the
ref-counted nature of DgnTextStyle to share ownership of the provided
object.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockXmlSerializer_Serialize =R"doc(Serializes the TextBlock into the provided Utf8String.)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockXmlSerializer_SetDocumentIDs =R"doc(Adds names of IDs as comments (e.g. gives names to style and font
IDs).)doc";

static const char * __doc_Bentley_DgnPlatform_TextBlockXmlSerializer_SetXmlIndentation =R"doc(Sets the indentation level used in the serialized XML string. By
default, no indentation (0) is used.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextBlockSerialization(py::module_& m)
    {
    //===================================================================================
    // struct TextBlockXmlSerializer
    py::class_< TextBlockXmlSerializer, TextBlockXmlSerializerPtr> c1(m, "TextBlockXmlSerializer");

    c1.def(py::init(&TextBlockXmlSerializer::Create), "textBlock"_a);
    c1.def("SetXmlIndentation", &TextBlockXmlSerializer::SetXmlIndentation, "indentLevel"_a, DOC(Bentley, DgnPlatform, TextBlockXmlSerializer, SetXmlIndentation));
    c1.def("SetDocumentIDs", &TextBlockXmlSerializer::SetDocumentIDs, "value"_a, DOC(Bentley, DgnPlatform, TextBlockXmlSerializer, SetDocumentIDs));
    c1.def("Serialize", &TextBlockXmlSerializer::Serialize, DOC(Bentley, DgnPlatform, TextBlockXmlSerializer, Serialize));

    //===================================================================================
    // struct TextBlockXmlDeserializer
    py::class_< TextBlockXmlDeserializer, TextBlockXmlDeserializerPtr> c2(m, "TextBlockXmlDeserializer");

    c2.def(py::init(&TextBlockXmlDeserializer::Create), "dgnModel"_a, "text"_a);
    c2.def("SetFallbackTextStyle", &TextBlockXmlDeserializer::SetFallbackTextStyle, "textStyle"_a, DOC(Bentley, DgnPlatform, TextBlockXmlDeserializer, SetFallbackTextStyle));
    c2.def("Deserialize", &TextBlockXmlDeserializer::Deserialize, DOC(Bentley, DgnPlatform, TextBlockXmlDeserializer, Deserialize));
    }