/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\extendedelementhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ExtendedElementHandler.h>



static const char * __doc_Bentley_DgnPlatform_ExtendedElementHandler_ClearPresentation =R"doc(Clear presentation graphics.

:param eh:
    The element to clear presentation graphics from.)doc";

static const char * __doc_Bentley_DgnPlatform_ExtendedElementHandler_ValidatePresentation =R"doc(Generate or update presentation to match the current state of the
element. This method will cause _GeneratePresentation to be called to
generate the presentation. It is not necessary to call this method if
the default extended element transaction handler is used and
_AutoGeneratePresentation returns true.

:param eh:
    The element.

:returns:
    SUCCESS if the presentation is validated sucessfully.)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ExtendedElementHandler(py::module_& m)
    {
    //===================================================================================
    // struct ExtendedElementHandler
    py::class_< 
        ExtendedElementHandler
        , DisplayHandler> c1(m, "ExtendedElementHandler");


    c1.def_static("InitializeElement", &ExtendedElementHandler::InitializeElement, "eeh"_a, "eh"_a, "modelRef"_a, "is3d"_a, "isComplexHeader"_a = 0);
    c1.def("ValidatePresentation", py::overload_cast<EditElementHandleR>(&ExtendedElementHandler::ValidatePresentation), "eeh"_a, DOC(Bentley, DgnPlatform, ExtendedElementHandler, ValidatePresentation));
    c1.def("ClearPresentation", &ExtendedElementHandler::ClearPresentation, "eeh"_a, DOC(Bentley, DgnPlatform, ExtendedElementHandler, ClearPresentation));
    c1.def("ValidatePresentation", py::overload_cast<EditElementHandleR, ISolidKernelEntityPtr>(&ExtendedElementHandler::ValidatePresentation), "eeh"_a, "solid"_a, DOC(Bentley, DgnPlatform, ExtendedElementHandler, ValidatePresentation));

    //===================================================================================
    py::class_< 
        ExtendedNonGraphicsHandler
        , Handler> c2(m, "ExtendedNonGraphicsHandler");

    c2.def_static("InitializeElement", &ExtendedNonGraphicsHandler::InitializeElement, "eeh"_a, "teh"_a, "modelRef"_a, "isComplexHeader"_a = false);

    }