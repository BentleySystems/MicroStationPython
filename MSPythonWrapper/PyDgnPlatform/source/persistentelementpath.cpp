/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\persistentelementpath.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/PersistentElementPath.h>



static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_DisclosePointers =R"doc(Reports all elements referenced by this path. This function differs
from EvaluateElement in several ways:\li EvaluateElement returns only
the root element, while this function returns the root element *and*
all of the intermediate elements used to reach the root. If this path
includes DgnAttachments, shared cell definitions, feature solid
headers, etc., they are reported by this function. \li EvaluateElement
reports the modelref of the root element, while this function does
not. \li EvaluateElement will fail if the root element or any
intermediate element is deleted. This function will return deleted
elements, if they were deleted within the same session. This can be
helpful when validating relationships in the course of a transaction.

Parameter ``refs``:
    Where to store root ElementRefs.

Parameter ``dependentModel``:
    The model that contains the dependent element.

Remark:
    s This function will *read* DgnAttachments that are used in a
    path. This function will not, however, load or fill the root model
    of any attachment. It is up to the caller to load and fill the
    models that contain any root elements that it wishes to disclose.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_ContainsRemapKeys =R"doc(Query if this PersistentElementPath contains remap keys. If false,
then there is no need to call #OnPreprocessCopyRemapIds.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_OnPreprocessCopyRemapIds =R"doc(Phase II of copying a persistent display path:remap the display's IDs
to copied root elements

Parameter ``hostElement``:
    The host element.

Parameter ``unused``:
    For future use. Always pass false.

Parameter ``defaultToOriginal``:
    If root has not been copied, should the copied path point to the
    original root?

Parameter ``opt``:
    How to handle pointers between models.

Returns:
    non-zero error status if the remapping failed and the displaypath
    should be dropped.

See also:
    OnPreprocessCopy

See also:
    ElementCopying.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_OnPreprocessCopy =R"doc(Phase I of copying a persistent display path:deep-copy root elements
and/or replace stored IDs with remap keys

Parameter ``opt``:
    How to handle pointers between models.

Parameter ``cc``:
    The copy context.

Parameter ``hostElement``:
    The element that contains the XAttribute.

Returns:
    non-zero error status if the display path cannot be copied and
    should be dropped

Remark:
    s After this function returns, this persistent display path should
    be stored until OnPreprocessCopyRemapIds is called.

See also:
    OnPreprocessCopyRemapIds

See also:
    ElementCopying.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_IsExactMatch =R"doc(Query if two PersistentElementPathes match.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_DependsOnElementRef =R"doc(Does the path depend on this ElementRefP? If dependent and root
elements are in different models and/or root is a shared cell
instance, then this function will detect that the path points to the
DgnAttachment element(s), the shared cell definition element, etc.

Parameter ``root``:
    The element to look for.

Parameter ``dependentModel``:
    The model that contains the dependent element.

Returns:
    true if *root* appears anywhere in the path, or false if it does
    not appear or if the path could not be evaluated.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_EqualElementRef =R"doc(Test if *root* is the root element of this path

Parameter ``root``:
    The element to find

Parameter ``dependentModel``:
    The model that contains the dependent element.

Returns:
    true if *root* is the root element of this path. False if the root
    is a different element or if the path could not be evaluated.

Remark:
    s This function will return true even if the root element is
    deleted, as long as you pass in the correct root element ref. This
    is useful when handling an IDependencyHandler::OnRootsChanged
    callback and you find that a root has been deleted and need to
    determine which of many PersistentElementPaths within the
    dependent XAttribute contains the reference to the deleted root.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_IsEmpty =R"doc(@name Queries @{ Query if the PersistentElementPath does not contain a
path.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_ProcessPath =R"doc(Process the items in a PersistentElementPath. Use this method if you
want to learn more about a path that fails to evaluate.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_EvaluateElementRef =R"doc(Get the root element.

Parameter ``dependentModel``:
    The model that contains the dependent element.

Returns:
    an element handle that identifies the root element or an invalid
    handle if the path could not be evaluated.

Remark:
    s This function should *not* be used if this path contains
    DgnAttachments. To work with attachments, you must use
    EvaluateElement.

Remark:
    s This evaluation function is useful when you don't need a path
    and you don't have a modelRef. EvaluateElementRef will return NULL
    if the root element is deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_EvaluateElementFromHost =R"doc(Get the root element.

Returns:
    an ElementHandle that identifies the root element or an invalid
    handle if the path could not be evaluated.

Parameter ``referenceHolder``:
    Identifies the dependent element. This is normally the element
    that owns the XAttribute that contains this PeristentElementPath.

Remark:
    s The returned EditElementHandle will have a NULL DgnModelRef if
    *referenceHolder* has a NULL DgnModelRef. <p> This function is
    useful if you have an ElementHandle that identifies the dependent
    element element but a) you are not sure if the handle contains a
    model or an element ref, and b) you don't care if the returned
    handle has a model or not. \li If *referenceHolder* has a
    DgnModelRef, then this function calls EvaluateElement
    (DgnModelRefP). \li Else, if *referenceHolder* has an ElementRefP,
    then this function calls EvaluateElementRef. \li Else, this
    function returns an invalid EditElementHandle.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_EvaluateElement =R"doc(Get the root element.

Parameter ``dependentModel``:
    The model that contains the dependent element.

Returns:
    an ElementHandle that identifies the root element or an invalid
    handle if the path could not be evaluated.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_GetDisplayPath =R"doc(Resolve the reference to the root element.

Parameter ``dependentModel``:
    The model that contains the dependent element.

Returns:
    NULL if the root element is not found or not available.)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_ToWString =R"doc(Serialize the state of this PersistentElementPath

Returns:
    string that captures the persistent state of PersistentElementPath

See also:
    Store, FromString)doc";

static const char * __doc_Bentley_DgnPlatform_PersistentElementPath_FromWString =R"doc(Recreate a PersistentElementPath from stored state

Parameter ``source``:
    Previously stored state.

Returns:
    non-zero error status if the state is invalid

See also:
    Load, ToString)doc";

//=======================================================================================
// Trampoline class for PersistentElementPath::PathProcessor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyPathProcessor : PersistentElementPath::PathProcessor
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void OnElementId(ElementId elementId, ElementRefP ref, DgnModelP dependentModel) override
        { PYBIND11_OVERRIDE_PURE_EX(void, PersistentElementPath::PathProcessor, OnElementId, elementId, ref, dependentModel); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnReferenceAttachmentId(ElementId elementId, ElementRefP ref, DgnModelRefP referencedModel, DgnModelP dependentModel) override
        { PYBIND11_OVERRIDE_PURE_EX(void, PersistentElementPath::PathProcessor, OnReferenceAttachmentId, elementId, ref, referencedModel, dependentModel); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnModelId(ModelId mid, DgnModelP cacheFound, DgnFileP homeFile) override
        { PYBIND11_OVERRIDE_PURE_EX(void, PersistentElementPath::PathProcessor, OnModelId, mid, cacheFound, homeFile); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PersistentElementPath(py::module_& m)
    {
    //===================================================================================
    // struct PersistentElementPath
    py::class_< PersistentElementPath> c1(m, "PersistentElementPath");

    if (true)
        {
        //===================================================================================
        // enum CopyOption
        py::enum_< PersistentElementPath::CopyOption>(c1, "CopyOption", py::arithmetic())
            .value("eCOPYOPTION_RemapRootsWithinSelection", PersistentElementPath::COPYOPTION_RemapRootsWithinSelection)
            .value("eCOPYOPTION_DeepCopyAcrossFiles", PersistentElementPath::COPYOPTION_DeepCopyAcrossFiles)
            .value("eCOPYCONTEXT_DeepCopyRootsAlways", PersistentElementPath::COPYCONTEXT_DeepCopyRootsAlways)
            .value("eCOPYOPTION_PreserveReferences", PersistentElementPath::COPYOPTION_PreserveReferences)
            .value("eCOPYOPTION_RemapRootsToAnyCopy", PersistentElementPath::COPYOPTION_RemapRootsToAnyCopy)
            .export_values();

        //===================================================================================
        // enum QFR_Flags
        py::enum_< PersistentElementPath::QFR_Flags>(c1, "QFR_Flags", py::arithmetic())
            .value("eQFR_FLAG_IncludeNoExtraModels", PersistentElementPath::QFR_FLAG_IncludeNoExtraModels)
            .value("eQFR_FLAG_IncludeHomeModel", PersistentElementPath::QFR_FLAG_IncludeHomeModel)
            .value("eQFR_FLAG_IncludeRootModel", PersistentElementPath::QFR_FLAG_IncludeRootModel)
            .value("eQFR_FLAG_IncludeHomeAndRootModels", PersistentElementPath::QFR_FLAG_IncludeHomeAndRootModels)
            .export_values();

        //===================================================================================
        py::class_< PersistentElementPath::PathProcessor, std::unique_ptr< PersistentElementPath::PathProcessor, py::nodelete>, PyPathProcessor> c1_1(c1, "PathProcessor");

        c1_1.def(py::init<>());
        c1_1.def("OnElementId", &PersistentElementPath::PathProcessor::OnElementId, "elemId"_a, "ref"_a, "dependentModel"_a);
        c1_1.def("OnReferenceAttachmentId", &PersistentElementPath::PathProcessor::OnReferenceAttachmentId, "elemId"_a, "ref"_a, "referencedModel"_a, "dependentModel"_a);
        c1_1.def("OnModelId", &PersistentElementPath::PathProcessor::OnModelId, "mid"_a, "cacheFound"_a, "homeFile"_a);
        }

    c1.def(py::init<DisplayPathCP, DgnAttachmentCP>(), "path"_a, "exclude"_a = nullptr);
    c1.def(py::init<ElementRefP>(), "rootElement"_a);
    c1.def(py::init<DgnModelRefP, ElementRefP, DgnAttachmentCP>(), "rootModel"_a, "rootElement"_a, "exclude"_a = nullptr);
    c1.def(py::init<ElementId, ModelId, ElementId>(), "refAttId"_a, "mid"_a, "eid"_a);
    c1.def(py::init<DgnAttachmentCP>(), "ref"_a);
    c1.def(py::init<>());   

    c1.def("CaptureQualifiedFarReference",
           &PersistentElementPath::CaptureQualifiedFarReference,
           "rootElementInFile"_a, "toFile"_a, "flags"_a = PersistentElementPath::QFR_FLAG_IncludeHomeAndRootModels, "exclude"_a = nullptr);
    c1.def("Load", [] (PersistentElementPath& self, py::bytes const& data)
           {
           std::string strData = data.cast<std::string>();
           return self.Load((byte const*) strData.data(), strData.size());
           }, "data"_a);

    c1.def("FromWString", &PersistentElementPath::FromWString, "source"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, FromWString));
    c1.def("Store", [] (PersistentElementPath const& self, py::bytearray& data)
           {
           UInt8Array outData;
           self.Store(outData);
           if (!outData.empty())
               data = py::bytearray((const char*) outData.data(), outData.size());
           }, "data"_a);

    c1.def("ToWString", &PersistentElementPath::ToWString, DOC(Bentley, DgnPlatform, PersistentElementPath, ToWString));
    c1.def("GetDisplayPath", &PersistentElementPath::GetDisplayPath, "dependentModel"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, GetDisplayPath));
    c1.def("EvaluateElement", &PersistentElementPath::EvaluateElement, "dependentModel"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, EvaluateElement));
    c1.def("EvaluateElementFromHost", &PersistentElementPath::EvaluateElementFromHost, "referenceHolder"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, EvaluateElementFromHost));
    c1.def("EvaluateElementRef", &PersistentElementPath::EvaluateElementRef, "dependentModel"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, PersistentElementPath, EvaluateElementRef));
    c1.def("ProcessPath", &PersistentElementPath::ProcessPath, "processor"_a, "dependentModel"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, ProcessPath));


    c1.def("IsEmpty", &PersistentElementPath::IsEmpty, DOC(Bentley, DgnPlatform, PersistentElementPath, IsEmpty));
    c1.def("EqualElementRef", &PersistentElementPath::EqualElementRef, "root"_a, "dependentModel"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, EqualElementRef));
    c1.def("DependsOnElementRef", &PersistentElementPath::DependsOnElementRef, "root"_a, "dependentModel"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, DependsOnElementRef));
    c1.def("IsExactMatch", &PersistentElementPath::IsExactMatch, "rhs"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, IsExactMatch));
    c1.def("OnPreprocessCopy", &PersistentElementPath::OnPreprocessCopy, "hostElement"_a, "copyContext"_a, "option"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, OnPreprocessCopy));
    c1.def("OnPreprocessCopyRemapIds", &PersistentElementPath::OnPreprocessCopyRemapIds, "hostElement"_a, "unused"_a = false, "defaultOriginal"_a = true, "option"_a = 0, DOC(Bentley, DgnPlatform, PersistentElementPath, OnPreprocessCopyRemapIds));
    c1.def("ContainsRemapKeys", &PersistentElementPath::ContainsRemapKeys, DOC(Bentley, DgnPlatform, PersistentElementPath, ContainsRemapKeys));
    c1.def("DisclosePointers", &PersistentElementPath::DisclosePointers, "refs"_a, "dependentModel"_a, DOC(Bentley, DgnPlatform, PersistentElementPath, DisclosePointers));
    }