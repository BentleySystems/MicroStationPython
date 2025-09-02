/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\texthandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TextHandlers.h>



static const char * __doc_Bentley_DgnPlatform_TextElemHandler_InitTextString =R"doc(Initializes a TextString to represent a text element. Any existing
data in the TextString is cleared before use.  This is here on
TextElemHandler instead of TextHandlerBase because you cannot make
TextString objects out of text nodes; see TextBlock for more generic
support.)doc";

static const char * __doc_Bentley_DgnPlatform_TextHandlerBase_DropText =R"doc(Drops a text element, and if it was view-independent, optionally
orients it to the provided (view) rotation.

Remark:
    s This essentially replaces the former
    mdlText_strokeToElementDescr function.)doc";

static const char * __doc_Bentley_DgnPlatform_TextHandlerBase_GetFirstTextPartValue =R"doc(A convenience wrapper around ITextQuery::GetText that gets the value
of the first text part. @note While normal text and text node elements
only expose a single text part, other text-enabled elements may expose
more, so this is **NOT** always safe to use.

See also:
    ITextQuery::IsTextElement to determine if an element is a normal
    text or text node element.)doc";

static const char * __doc_Bentley_DgnPlatform_TextHandlerBase_CreateElement =R"doc(Creates a new text element from the given TextBlock.  If no
template element is provided (or it is not a text or text node
element), you will get a type 17 text element unless a type 7 text
node in required (based on the contents of the TextBlock). If a
template element is provided, and it is a text node, the resulting
element will be a text node regardless of whether one is actually
required (if it is a text element, you may still get a node depending
on the contents of the TextBlock).  You cannot create elements
from a TextString object; see TextBlock.  The DgnModelRefP used
is that of the provided TextBlock.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TextHandlers(py::module_& m)
    {
    //===================================================================================
    // struct TextHandlerBase
    py::class_< TextHandlerBase, std::unique_ptr< TextHandlerBase, py::nodelete>, DisplayHandler, ITextEdit> c1(m, "TextHandlerBase");

    c1.def_static("CreateElement", 
                  py::overload_cast<EditElementHandleR, ElementHandleCP, TextBlockCR>(&TextHandlerBase::CreateElement), 
                  "eeh"_a, "templateEh"_a, "textBlock"_a, DOC(Bentley, DgnPlatform, TextHandlerBase, CreateElement));

    c1.def_static("CreateElement",
                  py::overload_cast<EditElementHandleR, ElementHandleCP, DgnModelRefP, TextBlockCR>(&TextHandlerBase::CreateElement),
                  "eeh"_a, "templateEh"_a, "targetModelRef"_a, "textBlock"_a, DOC(Bentley, DgnPlatform, TextHandlerBase, CreateElement));

    c1.def_static("GetFirstTextPartValue", &TextHandlerBase::GetFirstTextPartValue, "eh"_a, DOC(Bentley, DgnPlatform, TextHandlerBase, GetFirstTextPartValue));
    c1.def_static("DropText", &TextHandlerBase::DropText, "eh"_a, "agenda"_a, "rotMatrix"_a, DOC(Bentley, DgnPlatform, TextHandlerBase, DropText));
    c1.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< DisplayHandler, py::nodelete>(&TextHandlerBase::GetInstance()); });
    c1.def_static("GetInstance", &TextHandlerBase::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct TextNodeHandler
    py::class_< TextNodeHandler
        , std::unique_ptr< TextNodeHandler, py::nodelete>
        , TextHandlerBase
        , ITransactionHandler
        , IAnnotationHandler> c2(m, "TextNodeHandler");

    c2.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< TextNodeHandler, py::nodelete>(&TextNodeHandler::GetInstance()); });
    c2.def_static("GetInstance", &TextNodeHandler::GetInstance, py::return_value_policy::reference);

    //===================================================================================
    // struct TextElemHandler
    py::class_< TextElemHandler
        , std::unique_ptr< TextElemHandler, py::nodelete>
        , TextHandlerBase
        , IAnnotationHandler> c3(m, "TextElemHandler");

    c3.def("InitTextString", &TextElemHandler::InitTextString, "eh"_a, "textString"_a, DOC(Bentley, DgnPlatform, TextElemHandler, InitTextString));
    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< TextElemHandler, py::nodelete>(&TextElemHandler::GetInstance()); });
    c3.def_static("GetInstance", &TextElemHandler::GetInstance, py::return_value_policy::reference);
    }