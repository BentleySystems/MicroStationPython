/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\ecinstanceholderhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ECInstanceHolderHandler.h>



static const char * __doc_Bentley_DgnPlatform_ECInstanceHolderHandler_CreateECInstanceHolderElement =R"doc(Create a new ECInstanceHolder element.

Parameter ``eeh``:
    The new element.

Parameter ``modelRef``:
    Model to associate this element with.

Returns:
    SUCCESS if a valid element is created. Bentley Systems +----------
    -----+---------------+---------------+---------------+------------
    ---+------)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                    Chris.Wu                       6/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECInstanceHolderHandler(py::module_& m)
    {
    //===================================================================================
    // struct ECInstanceHolderHandler
    py::class_< ECInstanceHolderHandler, std::unique_ptr< ECInstanceHolderHandler, py::nodelete>, Handler> c1(m, "ECInstanceHolderHandler");

    c1.def_static("CreateECInstanceHolderElement", [](EditElementHandleR eeh, DgnModelRefR modelRef)
        {
        BentleyStatus retVal = ECInstanceHolderHandler::CreateECInstanceHolderElement(eeh, modelRef);
        return py::make_tuple(eeh, retVal);
        }, "eeh"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, ECInstanceHolderHandler, CreateECInstanceHolderElement));
    }

