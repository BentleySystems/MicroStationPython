/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\registeredapp.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/RegisteredApp.h>



static const char * __doc_Bentley_DgnPlatform_RegisteredApp_GetElementId =R"doc(Gets the ElementID of the component element that contains the
RegisteredApp Entry.)doc";

static const char * __doc_Bentley_DgnPlatform_RegisteredApp_GetName =R"doc(Gets the name of this RegisteredApp.)doc";

static const char * __doc_Bentley_DgnPlatform_RegisteredAppCollection_WriteToFile =R"doc(Writes the RegisteredAppCollection to the dgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_RegisteredAppCollection_DeleteRegisteredApp =R"doc(Deletes a RegisteredApp to the RegisteredAppCollection.

:param registeredAppName:
    The name of the RegisteredApp to delete.)doc";

static const char * __doc_Bentley_DgnPlatform_RegisteredAppCollection_AddRegisteredApp =R"doc(Adds a RegisteredApp to the RegisteredAppCollection.

:param registeredAppName:
    The name for the RegisteredApp.)doc";

static const char * __doc_Bentley_DgnPlatform_RegisteredAppCollection_FindByName =R"doc(Finds a RegisteredApp by name.

:param registeredAppName:
    The name of the RegisteredApp to search for.

:returns:
    The RegisteredAppPtr that references the RegisteredApp with the
    given name or NULL.

Remark:
    s The comparison is case-insensitive.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RegisteredApp(py::module_& m)
    {
    //===================================================================================
    // enum RegisteredAppStatus
    py::enum_< RegisteredAppStatus>(m, "RegisteredAppStatus", py::arithmetic())
        .value("eRA_Success", RA_Success)
        .value("eRA_NameNotUnique", RA_NameNotUnique)
        .value("eRA_NotFound", RA_NotFound)
        .value("eRA_CantWriteToFile", RA_CantWriteToFile)
        .value("eRA_CantCreateElement", RA_CantCreateElement)
        .export_values();

    //===================================================================================
    // struct RegisteredAppCollection
    py::class_< RegisteredAppCollection, RegisteredAppCollectionPtr> c1(m, "RegisteredAppCollection", py::multiple_inheritance());

    c1.def("__iter__", [] (RegisteredAppCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c1.def(py::init(&RegisteredAppCollection::Create), "dgnFile"_a);
    c1.def("__len__", &RegisteredAppCollection::Size);
    c1.def("FindByName", &RegisteredAppCollection::FindByName, "registeredAppName"_a, DOC(Bentley, DgnPlatform, RegisteredAppCollection, FindByName));
    
    c1.def_property_readonly("DgnFile", &RegisteredAppCollection::GetDgnFileR);
    c1.def("GetDgnFile", &RegisteredAppCollection::GetDgnFileR, py::return_value_policy::reference_internal);

    c1.def("AddRegisteredApp", py::overload_cast<WCharCP>(&RegisteredAppCollection::AddRegisteredApp), "registeredAppName"_a, DOC(Bentley, DgnPlatform, RegisteredAppCollection, AddRegisteredApp));
    c1.def("DeleteRegisteredApp", &RegisteredAppCollection::DeleteRegisteredApp, "registeredAppName"_a, DOC(Bentley, DgnPlatform, RegisteredAppCollection, DeleteRegisteredApp));
    c1.def("WriteToFile", &RegisteredAppCollection::WriteToFile, DOC(Bentley, DgnPlatform, RegisteredAppCollection, WriteToFile));
    //===================================================================================
    // struct RegisteredApp
    py::class_< RegisteredApp, RegisteredAppPtr> c2(m, "RegisteredApp");

    c2.def_property_readonly("Name", &RegisteredApp::GetName);
    c2.def("GetName", &RegisteredApp::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, RegisteredApp, GetName));
    c2.def_property_readonly("ElementId", &RegisteredApp::GetElementId);
    c2.def("GetElementId", &RegisteredApp::GetElementId, DOC(Bentley, DgnPlatform, RegisteredApp, GetElementId));
    }