/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnmodelref.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_TreatAs3d =R"doc(Query if this model should be treated as a 3D model for user interface
purposes. It is true if the model is 3D and not a sheet model.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_Is3d =R"doc(Query if this is a 3D model)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_GetLevelCache =R"doc(Get the level cache for this model reference.

:returns:
    a LevelCache. If this model is a
    Bentley::DgnPlatform::DgnAttachment, then the returned level cache
    will be a Bentley::DgnPlatform::DgnAttachmentLevelCache.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_GetModelRefType =R"doc(Query if this model is an attachment and if so what type of
attachment.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_IsDefault =R"doc(Query if this references the default model in its file)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_IsDwgStyleAttachment =R"doc(Query if this is a Bentley::DgnPlatform::DgnAttachment that is a DWG
style attachment.

See also:
    GetModelRefType)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_IsNestedDgnAttachment =R"doc(Query if this is a Bentley::DgnPlatform::DgnAttachment that is itself
an attachment owned by another DgnAttachment.

See also:
    GetModelRefType)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_IsDirectDgnAttachment =R"doc(Query if this is a Bentley::DgnPlatform::DgnAttachment that is itself
a direct attachment.

See also:
    GetModelRefType)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_IsDgnAttachment =R"doc(Query if this is a Bentley::DgnPlatform::DgnAttachment. This function
is equivalent to testing the result of AsDgnAttachmentCP.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_ReadAndLoadDgnAttachments =R"doc(Detects attachments in this model, creates a
Bentley::DgnPlatform::DgnAttachment for each, and then loads the
attached models. This operation is then applied recursively to
attachments of the attached models. This function returns immediately
if the attachments of this model have already been loaded. Loads Dgn
attachments @DotNetMethodCustomImplementation)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_FindDgnAttachmentByElementId =R"doc(Gets the Bentley::DgnPlatform::DgnAttachment structure that for a
reference given the element ID of its attachment element.

Remark:
    s This function looks only for attachments owned by this model,
    i.e., direct attachments. It does not recurse and look for nested
    attachments.

:param attachmentID:
    The element id of the attachment element

See also:
    Bentley::DgnPlatform::DgnAttachment::GetElementId)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_GetReachableElements =R"doc(Get an iterable collection of elements reachable from this modelRef.
The reachable set includes all elements in this model as well as all
elements in models attached to this model, including nested
attachments.

:returns:
    A collection of Elements. <p><h3>Example:</h3>
)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_GetReachableModelRefs =R"doc(Get an iterable collection of modelRefs that includes 'this' modelRef,
its attachments and all nested attachments. The returned modelRefs can
refer to missing attachments, so a NULL check is required to determine
if each modelRef refers to an actual model.

:returns:
    A collection of modelRefs. <p><h3>Example:</h3>

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelRef_CreateDgnAttachment =R"doc(Attach the specified model in the specified file to this model. This
creates a new Bentley::DgnPlatform::DgnAttachment.

:param attachment:
    newly created attachment

:param moniker:
    Identifies the document to be referenced

:param modelName:
    The model within the target file to be referenced

:param loadCache:
    True to load the dgnModel.

:returns:
    non-zero status if the reference could not be created. Typically,
    the error will be one of: DGNOPEN_STATUS_FileNotFound The file
    identified by *document* could not be found. 
    DGNMODEL_STATUS_NotFound The model identified by *modelName* could
    not be found in the file. Other DGNOPEN errors could also be
    returned. @Remarks The parameters of the new
    Bentley::DgnPlatform::DgnAttachment are set up as follows:
    scale mode = true scale  display, display raster = on if
    primary attachment, off if nested attachment  lstyle scale = on
    for DWG, otherwise off  origin and rotation = coincident 
    reference number = next available  logical name = computed
    unique logical name @Remarks This function does not add the new
    attachment as an element to the model. Call
    Bentley::DgnPlatform::DgnAttachment::Write @Remarks If *fileName*
    does not provide a full file specification, the master file path
    and the environment variables MS_RFDIR and MS_DEF are searched
    sequentially for the file. @See
    Bentley::DgnPlatform::DgnAttachment::Write)doc";

static const char * __doc_Bentley_DgnPlatform_DgnAttachmentBuilder_AddToParent =R"doc(Don't delete the pointer! Make the DgnAttachment persistent *and*
transfer ownship of it to its parent.

Remark:
    s This smart pointer becomes empty as a result of calling this
    function.)doc";

using DgnAttachmentArrayPtr = std::unique_ptr<DgnAttachmentArray, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnModelRef(py::module_& m)
    {
    //===================================================================================
    // enum class DgnModelRefType
    py::enum_< DgnModelRefType>(m, "DgnModelRefType")
        .value("eRoot", DgnModelRefType::Root)
        .value("ePrimaryRef", DgnModelRefType::PrimaryRef)
        .value("eProxy", DgnModelRefType::Proxy)
        .value("eNonModel", DgnModelRefType::NonModel)
        .value("eTransient", DgnModelRefType::Transient)
        .export_values();       

    //===================================================================================
    // struct DgnAttachmentArray
    py::class_< DgnAttachmentArray, DgnAttachmentArrayPtr> c1(m, "DgnAttachmentArray");

    c1.def("__len__", &DgnAttachmentArray::size);
    c1.def("__getitem__", [] (DgnAttachmentArray const& self, size_t index)
           {
           if (index >= self.size())
               throw py::index_error();
           return self.at(index);
           }, py::return_value_policy::reference_internal);

    c1.def("__iter__", [] (DgnAttachmentArray& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());    

    //===================================================================================
    // struct DgnAttachmentBuilder
    py::class_< DgnAttachmentBuilder> c2(m, "DgnAttachmentBuilder");

    c2.def(py::init<>());
    c2.def(py::init<DgnAttachmentBuilder&>(), "rhs"_a);

    c2.def_property_readonly("DgnAttachment", &DgnAttachmentBuilder::GetDgnAttachmentP);
    c2.def("GetDgnAttachment", &DgnAttachmentBuilder::GetDgnAttachmentP, py::return_value_policy::reference_internal);
    
    c2.def("AddToParent", &DgnAttachmentBuilder::AddToParent, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnAttachmentBuilder, AddToParent));

    //===================================================================================
    // struct DgnAttachmentLoadOptions
    py::class_< DgnAttachmentLoadOptions> c3(m, "DgnAttachmentLoadOptions");

    c3.def(py::init<bool, bool, bool>(), "loadCaches"_a = true, "loadUndisplayed"_a = false, "loadRasterRefs"_a = true);
    c3.def_readwrite("loadCaches", &DgnAttachmentLoadOptions::m_loadCaches);
    c3.def_readwrite("topLevelModel", &DgnAttachmentLoadOptions::m_topLevelModel);
    c3.def_readwrite("loadUndisplayed", &DgnAttachmentLoadOptions::m_loadUndisplayed);
    c3.def_readwrite("oneLevelOnly", &DgnAttachmentLoadOptions::m_oneLevelDeep);
    c3.def_readwrite("redundancyCheck", &DgnAttachmentLoadOptions::m_redundancyCheck);
    c3.def_readwrite("applyOverrides", &DgnAttachmentLoadOptions::m_applyOverrides);
    c3.def_readwrite("sectionsToFill", &DgnAttachmentLoadOptions::m_sectionsToFill);
    c3.def_readwrite("maxDepth", &DgnAttachmentLoadOptions::m_maxDepth);
    c3.def_readwrite("showProgressMeter", &DgnAttachmentLoadOptions::m_showProgressMeter);
    c3.def_readwrite("limitLoading", &DgnAttachmentLoadOptions::m_limitLoading);

    //===================================================================================
    // struct DgnModelRef
    py::class_< DgnModelRef, std::unique_ptr<DgnModelRef, py::nodelete> > c4(m, "DgnModelRef");
    bind_PointerVector<DgnModelRefP>(m, "DgnModelRefPArray", py::module_local(false));

    c4.def("CreateDgnAttachment", [] (DgnModelRefR self, DgnDocumentMonikerR moniker, WCharCP modelName, bool loadCache)
           {
           DgnAttachmentP pAtt = nullptr;
           StatusInt retVal = self.CreateDgnAttachment(pAtt, moniker, modelName, loadCache);
           return py::make_tuple(retVal, std::unique_ptr< DgnAttachment, py::nodelete>(pAtt));
           }, "moniker"_a, "modelName"_a, "loadCache"_a = true, DOC(Bentley, DgnPlatform, DgnModelRef, CreateDgnAttachment));

    c4.def("DeleteDgnAttachment", [] (DgnModelRefR self, DgnAttachment* attachment) { return self.DeleteDgnAttachment(attachment); }, "attachment"_a);

    c4.def_property_readonly("DgnAttachments", [] (DgnModelRefR self) { return DgnAttachmentArrayPtr(self.GetDgnAttachmentsP()); });
    c4.def("GetDgnAttachments", [] (DgnModelRefR self) { return DgnAttachmentArrayPtr(self.GetDgnAttachmentsP()); });

    c4.def("GetReachableModelRefs", &DgnModelRef::GetReachableModelRefs, "options"_a = nullptr, DOC(Bentley, DgnPlatform, DgnModelRef, GetReachableModelRefs));
    c4.def("GetReachableElements", &DgnModelRef::GetReachableElements, "options"_a = nullptr, DOC(Bentley, DgnPlatform, DgnModelRef, GetReachableElements));
    c4.def("FindDgnAttachmentByElementId", &DgnModelRef::FindDgnAttachmentByElementId, "attachmentId"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnModelRef, FindDgnAttachmentByElementId));
    c4.def("ReadAndLoadDgnAttachments", &DgnModelRef::ReadAndLoadDgnAttachments, "options"_a, DOC(Bentley, DgnPlatform, DgnModelRef, ReadAndLoadDgnAttachments));
    
    c4.def_property_readonly("ParentModelRef", &DgnModelRef::GetParentModelRefP);
    c4.def("GetParentModelRef", &DgnModelRef::GetParentModelRefP, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("DgnModel", &DgnModelRef::GetDgnModelP);
    c4.def("GetDgnModel", &DgnModelRef::GetDgnModelP, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("DgnFile", &DgnModelRef::GetDgnFileP);
    c4.def("GetDgnFile", &DgnModelRef::GetDgnFileP, py::return_value_policy::reference_internal);

    c4.def_property_readonly("ModelInfo", &DgnModelRef::GetModelInfoCP);
    c4.def("GetModelInfo", &DgnModelRef::GetModelInfoCP, py::return_value_policy::reference_internal);
    
    c4.def("IsDgnAttachment", &DgnModelRef::IsDgnAttachment, DOC(Bentley, DgnPlatform, DgnModelRef, IsDgnAttachment));
    c4.def("IsDirectDgnAttachment", &DgnModelRef::IsDirectDgnAttachment, DOC(Bentley, DgnPlatform, DgnModelRef, IsDirectDgnAttachment));
    c4.def("IsNestedDgnAttachment", &DgnModelRef::IsNestedDgnAttachment, DOC(Bentley, DgnPlatform, DgnModelRef, IsNestedDgnAttachment));
    c4.def("IsDwgStyleAttachment", &DgnModelRef::IsDwgStyleAttachment, DOC(Bentley, DgnPlatform, DgnModelRef, IsDwgStyleAttachment));
    c4.def("IsDefault", &DgnModelRef::IsDefault, DOC(Bentley, DgnPlatform, DgnModelRef, IsDefault));

    c4.def_property_readonly("ModelRefType", &DgnModelRef::GetModelRefType);
    c4.def("GetModelRefType", &DgnModelRef::GetModelRefType, DOC(Bentley, DgnPlatform, DgnModelRef, GetModelRefType));

    c4.def("AsDgnAttachment", [] (DgnModelRef& self) { return std::unique_ptr<DgnAttachment, py::nodelete>(self.AsDgnAttachmentP()); });
    
    c4.def_property_readonly("LevelCache", &DgnModelRef::GetLevelCacheR);
    c4.def("GetLevelCache", &DgnModelRef::GetLevelCacheR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnModelRef, GetLevelCache));
    
    c4.def_property_readonly("FileLevelCache", &DgnModelRef::GetFileLevelCacheP);
    c4.def("GetFileLevelCache", &DgnModelRef::GetFileLevelCacheP, py::return_value_policy::reference_internal);
    
    c4.def("Is3d", &DgnModelRef::Is3d, DOC(Bentley, DgnPlatform, DgnModelRef, Is3d));    
    c4.def("TreatAs3d", &DgnModelRef::TreatAs3d, DOC(Bentley, DgnPlatform, DgnModelRef, TreatAs3d));
    
    c4.def_property_readonly("SymbologySourceDgnFile", &DgnModelRef::GetSymbologySourceDgnFileP);
    c4.def("GetSymbologySourceDgnFile", &DgnModelRef::GetSymbologySourceDgnFileP, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct DgnModelRefList
    py::class_< DgnModelRefList, bvector< DgnModelRefP> > c5(m, "DgnModelRefList");

    }