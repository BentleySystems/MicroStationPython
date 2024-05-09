/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnecfinders.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnECFinders.h>



static const char * __doc_Bentley_DgnPlatform_FindInstancesScope_Empty =R"doc(Test whether the scope contains any location to search for.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScope_GetFile =R"doc(Get the dgn file associated with this scope.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScope_GetHostType =R"doc(Get the host type associated with this scope. Its a bitmask and hence
can be a combination of multiple types.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScope_CreateScope =R"doc(Create a scope which finds instances accessible through a dgn file.

Parameter ``file``:
    Dgn file to traverse from

Parameter ``options``:
    The options structure controls how the scope is iterated.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_SetSearchFileInstances =R"doc(Utility method to allow searching of instances from file header)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_SetSearchModelInstances =R"doc(Utility method to allow searching of instances from model header)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_SetReachableModelOptions =R"doc(Set the how the scope scans a model and its attachments

Parameter ``[in]``:
    options Set an options pointer to override the default behavior)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_GetReachableModelOptions =R"doc(Get the how the scope scans a model and its attachments)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_SetSearchPublicChildren =R"doc(Set true to search for public children of element

Parameter ``[in]``:
    searchChildren if true will search for public children)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_GetSearchPublicChildren =R"doc(Get whether the scope will search for public children of elements.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_SetSearchAttachments =R"doc(Set true to look for instance in attachment of a scope containing a
model. The behavior is dependant on GetReachableModelOptions

Parameter ``[in]``:
    includeAttachments Set true to look for attachments in the scope.

Remark:
    s DgnECManager API does not auto load the attachments. So the
    caller needs to make sure all the attachments are loaded by using
    Only supported for scopes which have a defined root DgnModelRef.
    the dgnattachment API.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_GetSearchAttachments =R"doc(Check whether to find instances in attachment of a scope containing a
model.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_SetHostType =R"doc(Set the host type from which instances are generated

Parameter ``[in]``:
    hostType the type of instances to search for.)doc";

static const char * __doc_Bentley_DgnPlatform_FindInstancesScopeOption_GetHostType =R"doc(Determine which type of instances to search for.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnECFinders(py::module_& m)
    {

    //===================================================================================
    // struct FindInstancesScopeOption
    py::class_< FindInstancesScopeOption> c6(m, "FindInstancesScopeOption");

    c6.def(py::init<>());
    c6.def(py::init<DgnECHostType>(), "hostType"_a);
    c6.def(py::init<DgnECHostType, bool>(), "hostType"_a, "includeAttachments"_a);
    c6.def_property("HostType", &FindInstancesScopeOption::GetHostType, &FindInstancesScopeOption::SetHostType);
    c6.def("GetHostType", &FindInstancesScopeOption::GetHostType, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, GetHostType));
    c6.def("SetHostType", &FindInstancesScopeOption::SetHostType, "hostType"_a, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, SetHostType));

    c6.def_property("SearchAttachments", &FindInstancesScopeOption::GetSearchAttachments, &FindInstancesScopeOption::SetSearchAttachments);
    c6.def("GetSearchAttachments", &FindInstancesScopeOption::GetSearchAttachments, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, GetSearchAttachments));
    c6.def("SetSearchAttachments", &FindInstancesScopeOption::SetSearchAttachments, "includeAttachments"_a, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, SetSearchAttachments));

    c6.def_property("SearchPublicChildren", &FindInstancesScopeOption::GetSearchPublicChildren, &FindInstancesScopeOption::SetSearchPublicChildren);
    c6.def("GetSearchPublicChildren", &FindInstancesScopeOption::GetSearchPublicChildren, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, GetSearchPublicChildren));
    c6.def("SetSearchPublicChildren", &FindInstancesScopeOption::SetSearchPublicChildren, "searchChild"_a, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, SetSearchPublicChildren));

    c6.def_property("ReachableModelOptions", &FindInstancesScopeOption::GetReachableModelOptions, &FindInstancesScopeOption::SetReachableModelOptions);
    c6.def("GetReachableModelOptions", &FindInstancesScopeOption::GetReachableModelOptions, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, GetReachableModelOptions));
    c6.def("SetReachableModelOptions", &FindInstancesScopeOption::SetReachableModelOptions, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, SetReachableModelOptions));

    c6.def("SetSearchModelInstances", &FindInstancesScopeOption::SetSearchModelInstances, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, SetSearchModelInstances));
    c6.def("SetSearchFileInstances", &FindInstancesScopeOption::SetSearchFileInstances, DOC(Bentley, DgnPlatform, FindInstancesScopeOption, SetSearchFileInstances));

    //===================================================================================
    // struct FindInstancesScope
    py::class_< FindInstancesScope, FindInstancesScopePtr> c7(m, "FindInstancesScope");
    py::bind_vector<bvector< FindInstancesScopePtr>>(m, "FindInstancesScopePtrArray", py::module_local(false));


    c7.def_static("CreateScope",
                  py::overload_cast<DgnFileR, FindInstancesScopeOptionCR>(&FindInstancesScope::CreateScope),
                  "file"_a, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<bvector<DgnModelRefP> const& ,FindInstancesScopeOptionCR, DgnFileR>(&FindInstancesScope::CreateScope),
                  "models"_a, "options"_a, "file"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<DgnModelRefR, FindInstancesScopeOptionCR>(&FindInstancesScope::CreateScope),
                  "modelRef"_a, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<ViewportR, FindInstancesScopeOptionCR>(&FindInstancesScope::CreateScope),
                  "viewport"_a, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<DgnModelRefR, ElementAgendaCR, FindInstancesScopeOptionCR>(&FindInstancesScope::CreateScope),
                  "modelRef"_a, "agenda"_a, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<ElementHandleCR, FindInstancesScopeOptionCR>(&FindInstancesScope::CreateScope),
                  "elemHandle"_a, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<DgnLinkTreeNodeCR>(&FindInstancesScope::CreateScope),
                  "linkNode"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));

    c7.def_static("CreateScope",
                  py::overload_cast<DgnLinkTreeNodeCR, DgnECInstanceCreateOptionsCR>(&FindInstancesScope::CreateScope),
                  "linkNode"_a, "options"_a, DOC(Bentley, DgnPlatform, FindInstancesScope, CreateScope));


    c7.def_property_readonly("HostType", &FindInstancesScope::GetHostType);
    c7.def("GetHostType", &FindInstancesScope::GetHostType, DOC(Bentley, DgnPlatform, FindInstancesScope, GetHostType));

    c7.def_property_readonly("File", &FindInstancesScope::GetFile);
    c7.def("GetFile", &FindInstancesScope::GetFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FindInstancesScope, GetFile));

    c7.def("Empty", &FindInstancesScope::Empty, DOC(Bentley, DgnPlatform, FindInstancesScope, Empty));

    }