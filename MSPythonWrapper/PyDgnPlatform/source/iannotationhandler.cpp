/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iannotationhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IAnnotationHandler.h>



static const char * __doc_Bentley_DgnPlatform_IAnnotationHandler_RemoveAnnotationScale =R"doc(Remove annotation scale from *eh.*

Returns:
    non-zero error status if annotation scale could not be removed.)doc";

static const char * __doc_Bentley_DgnPlatform_IAnnotationHandler_AddAnnotationScale =R"doc(Set up annotation scale on *eh.*

Returns:
    non-zero error status if annotation scale could not be
    initialized.)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IAnnotationHandler(py::module_& m)
    {
    //===================================================================================
    // struct IAnnotationHandler
    py::class_< IAnnotationHandler
        , std::unique_ptr< IAnnotationHandler, py::nodelete>
    > c1(m, "IAnnotationHandler");


    c1.def("HasAnnotationScale", [] (IAnnotationHandler const& self, ElementHandleCR eh)
           {
           double annotationScale = 0;
           auto retVal = self.HasAnnotationScale(&annotationScale, eh);
           return py::make_tuple(retVal, annotationScale);
           }, "eh"_a);

    c1.def("AddAnnotationScale", &IAnnotationHandler::AddAnnotationScale, "eeh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, IAnnotationHandler, AddAnnotationScale));
    c1.def("RemoveAnnotationScale", &IAnnotationHandler::RemoveAnnotationScale, "eeh"_a, DOC(Bentley, DgnPlatform, IAnnotationHandler, RemoveAnnotationScale));


    }