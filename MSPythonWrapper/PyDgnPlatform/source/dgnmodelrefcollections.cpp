/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnmodelrefcollections.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/DgnModelRefCollections.h>



static const char * __doc_Bentley_DgnPlatform_ReachableElementOptions_GetModelRefOptions =R"doc(Get the options which will be used for choosing which modelRefs to
consider.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableElementOptions_ExcludeGraphicsSection =R"doc(The iterator should skip elements in the model's graphics section.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableElementOptions_ExcludeControlSection =R"doc(The iterator should skip elements in the model's control section.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeUndisplayedAttachments =R"doc(The iterator should skip attachments that are not displayed.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeRedundantAttachments =R"doc(The iterator should skip redundant attachments.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeNestedAttachments =R"doc(The iterator should skip modelrefs that are not directly attached to
the root model.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeNonEmbeddedFileRefs =R"doc(The iterator should skip modelrefs that reference models which are not
in embedded files.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeEmbeddedFileRefs =R"doc(The iterator should skip modelrefs that reference models in embedded
files.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeIntraFileRefs =R"doc(The iterator should skip modelrefs that reference models in the same
file as the root.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeInterFileRefs =R"doc(The iterator should skip modelrefs that reference models in a
different file than the root.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_ExcludeRootModelRef =R"doc(The iterator should skip the root modelref.)doc";

static const char * __doc_Bentley_DgnPlatform_ReachableModelRefOptions_Duplicate =R"doc(Copy an existing options object.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnModelRefCollections(py::module_& m)
    {
    //===================================================================================
    // struct ReachableModelRefOptions
    py::class_< ReachableModelRefOptions, ReachableModelRefOptionsPtr> c1(m, "ReachableModelRefOptions");

    c1.def(py::init(&ReachableModelRefOptions::CreateOptions));
    c1.def_static("Duplicate", py::overload_cast<ReachableModelRefOptionsCR>(&ReachableModelRefOptions::Duplicate), "seedOptions"_a, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, Duplicate));
    c1.def("ExcludeRootModelRef", &ReachableModelRefOptions::ExcludeRootModelRef, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeRootModelRef));
    c1.def("ExcludeInterFileRefs", &ReachableModelRefOptions::ExcludeInterFileRefs, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeInterFileRefs));
    c1.def("ExcludeIntraFileRefs", &ReachableModelRefOptions::ExcludeIntraFileRefs, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeIntraFileRefs));
    c1.def("ExcludeEmbeddedFileRefs", &ReachableModelRefOptions::ExcludeEmbeddedFileRefs, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeEmbeddedFileRefs));
    c1.def("ExcludeNonEmbeddedFileRefs", &ReachableModelRefOptions::ExcludeNonEmbeddedFileRefs, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeNonEmbeddedFileRefs));
    c1.def("ExcludeNestedAttachments", &ReachableModelRefOptions::ExcludeNestedAttachments, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeNestedAttachments));
    c1.def("ExcludeRedundantAttachments", &ReachableModelRefOptions::ExcludeRedundantAttachments, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeRedundantAttachments));
    c1.def("ExcludeUndisplayedAttachments", &ReachableModelRefOptions::ExcludeUndisplayedAttachments, DOC(Bentley, DgnPlatform, ReachableModelRefOptions, ExcludeUndisplayedAttachments));

    //===================================================================================
    // struct ReachableModelRefCollection
    py::class_< ReachableModelRefCollection> c2(m, "ReachableModelRefCollection");

    c2.def("__bool__", [] (ReachableModelRefCollection& self) { return !self.empty(); });
    c2.def("__iter__", [] (ReachableModelRefCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct ReachableElementOptions
    py::class_< ReachableElementOptions, ReachableElementOptionsPtr> c3(m, "ReachableElementOptions");

    c3.def(py::init(&ReachableElementOptions::CreateOptions));
    c3.def_static("Duplicate", &ReachableElementOptions::Duplicate, "seedOptions"_a);
    c3.def("ExcludeControlSection", &ReachableElementOptions::ExcludeControlSection, DOC(Bentley, DgnPlatform, ReachableElementOptions, ExcludeControlSection));
    c3.def("ExcludeGraphicsSection", &ReachableElementOptions::ExcludeGraphicsSection, DOC(Bentley, DgnPlatform, ReachableElementOptions, ExcludeGraphicsSection));

    c3.def_property_readonly("ModelRefOptions", &ReachableElementOptions::GetModelRefOptions);
    c3.def("GetModelRefOptions", &ReachableElementOptions::GetModelRefOptions, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ReachableElementOptions, GetModelRefOptions));

    //===================================================================================
    // struct ReachableElementCollection
    py::class_< ReachableElementCollection> c4(m, "ReachableElementCollection");

    c4.def("__iter__", [] (ReachableElementCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }