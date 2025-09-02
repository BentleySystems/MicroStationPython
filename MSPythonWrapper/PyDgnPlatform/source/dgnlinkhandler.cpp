/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnlinkhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnLinkHandler.h>



static const char * __doc_Bentley_DgnPlatform_DgnLinkSetHandler_CreateLinkSet =R"doc(Creates the linkset from optional key type and link tree branch.

:param branch:
    a object of type DgnLinkTreeBranch.

:returns:
    the DgnLinkSet pointer.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetHandler_GetKey =R"doc(Gets the key from given link tree node.

:param branch:
    a object of DgnLinkTreeBranch.

:returns:
    the key)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSetHandler_CanHandleKey =R"doc(Checks whether the provided linkset type is a valid key and can be
handled or not.

:param key:
    a type of linkset key

:returns:
    the status of function)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkHandler_GetKey =R"doc(Gets the key from given link tree node.

:param leaf:
    a object of DgnLinkTreeLeaf.

:returns:
    the key)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkHandler_CanHandleKey =R"doc(Check whether this can handle the provided link type

:param key:
    denotes the type of link.

:returns:
    the status of function)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkSchemaProvider_CreateECInstance =R"doc(Gets the instance enabler for the given class.

:param ecClassName:
    name of the class

:returns:
    the object of type StandaloneECInstance)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnLinkHandler(py::module_& m)
    {
    //===================================================================================
    // struct DgnLinkSchemaProvider
    py::class_< DgnLinkSchemaProvider
        , std::unique_ptr<DgnLinkSchemaProvider, py::nodelete>
    > c1(m, "DgnLinkSchemaProvider");

    c1.def("GetSchema", [] (DgnLinkSchemaProvider& self, DgnFileP dgnFile) { return ECN::ECSchemaPtr(self.GetSchema(dgnFile)); }, "dgnFile"_a);
    c1.def("CreateECInstance", &DgnLinkSchemaProvider::CreateECInstance, "ecClassName"_a, DOC(Bentley, DgnPlatform, DgnLinkSchemaProvider, CreateECInstance));        

    //===================================================================================
    // struct DgnLinkHandler
    py::class_< DgnLinkHandler
        , DgnLinkSchemaProvider> c2(m, "DgnLinkHandler");

    c2.def("CanHandleKey", &DgnLinkHandler::CanHandleKey, "key"_a, DOC(Bentley, DgnPlatform, DgnLinkHandler, CanHandleKey));
    c2.def("GetKey", &DgnLinkHandler::GetKey, "leaf"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkHandler, GetKey));

    //===================================================================================
    // struct DgnLinkSetHandler
    py::class_< DgnLinkSetHandler
        , DgnLinkSchemaProvider> c15(m, "DgnLinkSetHandler");

    c15.def("CanHandleKey", &DgnLinkSetHandler::CanHandleKey, "key"_a, DOC(Bentley, DgnPlatform, DgnLinkSetHandler, CanHandleKey));
    c15.def("GetKey", &DgnLinkSetHandler::GetKey, "branch"_a, DOC(Bentley, DgnPlatform, DgnLinkSetHandler, GetKey));
    c15.def("CreateLinkSet", &DgnLinkSetHandler::CreateLinkSet, "branch"_a, DOC(Bentley, DgnPlatform, DgnLinkSetHandler, CreateLinkSet));    
    }