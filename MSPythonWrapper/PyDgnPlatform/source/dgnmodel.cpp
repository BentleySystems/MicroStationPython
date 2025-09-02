/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnmodel.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnModel.h>
#include <DgnPlatform/DgnComponentHandlers.h>
#include "PyDgnPlatform.h"

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetGraphicElmStart =R"doc(Get the FilePos of the first Graphic Element for this DgnModel.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetControlElmStart =R"doc(Get the FilePos of the first Control Element for this DgnModel.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_FindAppData =R"doc(Search for appData on this model that was added with the specified
key.

:returns:
    the DgnModelAppData with *key,* or NULL.
    @DotNetMethodCustomImplementation)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_DropAppData =R"doc(Remove appData from this model.

:returns:
    SUCCESS if appData with key is found and was dropped.

Remark:
    s Calls the app data object's _OnCleanup method.
    @DotNetMethodCustomImplementation)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_AddAppData =R"doc(@name DgnModelAppData Add (or replace) appData to this model.

:returns:
    SUCCESS if appData was successfully added. Note that it is illegal
    to add or remove AppData from within any of the AppData " _On "
    methods. If an entry with *key* already exists, it will be dropped
    and replaced with *appData.* @DotNetMethodCustomImplementation)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetRange =R"doc(Get the spatial extent of all elements in this model.

:param range:
    Filled with the union of all of the ranges of the elements in
    model.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_IsReadOnly =R"doc(Determine whether this is a readonly DgnModel or not.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetModelName =R"doc(Shortcut for querying the model name for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_SaveModelSettings =R"doc(Save the settings for this DgnModel's ModelInfo.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetModelInfo =R"doc(Get the ModelInfo for this model.

Remark:
    s To modify the modelinfo you must create a copy of the returned
    one, modify it, and call #SetModelInfo () with the changed
    version. @See ModelInfo::MakeCopy @See SetModelInfo)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetModelId =R"doc(Get the ModelId for this model.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetElementsCollection =R"doc(@See GetControlElementsP @See GetGraphicElementsP)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_Release =R"doc(Decrement the reference count of this model.

:returns:
    the new reference count)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_AddRef =R"doc(Increment the reference count of this model.

:returns:
    the new reference count)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_IsDictionaryModel =R"doc(Determine whether this model is a dictionary model.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetFileLevelCache =R"doc(Get read-only access to levels defined in the DgnFile associated with
this DgnModel.

:returns:
    a const reference to the FileLevelCache of the DgnFile associated
    with this DgnModel. @note Since a DgnModel always has an open
    DgnFile (in contrast to a DgnModelRef, which can be a
    DgnAttachment for which the DgnFile is not resolved or not
    loaded), it is always possible to obtain the FileLevelCache, so
    this method can return a reference rather than a pointer.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_GetElementCount =R"doc(Get the number of elements in this model.

:param sections:
    the DgnModel sections to include in the count.

:returns:
    the number of elements in the requested sections of this model.
    @note The model must be filled before calling this method. The
    count only includes elements from filled sections. @note The
    element count includes deleted elements.

See also:
    FillSections)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_IsFilled =R"doc(Determine whether this model has been " filled " from disk or not.

:param sections:
    the DgnModelSections to test.

:returns:
    the mask of the DgnModelSections that have been filled.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_Empty =R"doc(Empty the contents of this model.

:param evenIfDirty:
    If false, the DgnModel will not be emptied if there are unsaved
    changes.

:param andFree:
    If true, the DgnModel will not be able to be reloaded again.)doc";

static const char* __doc_Bentley_DgnPlatform_DgnModel_FillSections = R"doc(Read elements from the physical file into this model.

Parameter ``sectionsToFill``:
    The sections of this model to fill. The Control and Graphic elements can be loaded independently, but
    are usually filled together..
    
Returns:
    Whenever the first section of any DgnModel is filled for a Bentley::DgnPlatform::DgnFile, the Dictionary model for that file is filled as well.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModel_SetModelInfo =R"doc(Sets ModelInfo to new one if possible. Fails if New ModelInfo is
incompatible with current model. If successful, the ModelInfo will be
updated to reflect any changes done internally.  Cannot change
2d/3d property.  Cannot modify properties of a locked ModelInfo
unless unlocking.  Cannot modify properties of a read-only
DgnModel.  Cannot change to/from
DgnModelType::Extraction_Deprecated. Returns
DGNMODEL_STATUS_InvalidModelTypeSwitch. If ModelType is Sheet or
Drawing, this propagates the background color out to other models of
the same type. If BorderAttachmentId on the ModelInfo's SheetDef has
changed, the SheetDef's properties will be updated to be in sync with
the BorderAttachment. Applies ModelInfo changes to TxnManager and
sends out pre/post change notifications. @Returns
DGNMODEL_STATUS_Success if no different than current ModelInfo or if
new one is used.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnSaveModelProperties =R"doc(Override this method to be notified when a model's properties are
changed.

:param host:
    The host model.

:param original:
    The model's original properties)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnElementAdded =R"doc(Override this method to be notified when a (top-level) element is
added to the host DgnModel.

Remark:
    s This is called before the element is added to the range index.

:param host:
    The host model.

:param elem:
    The element that was just added to the host model. Note that only
    top-level elements are reported.

:param isGraphicsList:
    Is this element in the graphics list of the host model?)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnModelUnDelete =R"doc(Override this method to be notified after the persistent MicroStation
Model is undeleted.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnModelDelete =R"doc(Override this method to be notified before the persistent MicroStation
Model is marked for delete. The actual delete happens when the DgnFile
holding the DgnModel is closed.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnEmptied =R"doc(Override this method to be notified after host DgnModel has been
emptied. Won't be called unless #_OnEmpty returns false.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnEmpty =R"doc(Override this method to be notified when host DgnModel is about to be
emptied.

:returns:
    true to be dropped from host (_OnCleanup will be called.))doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnFilled =R"doc(Override this method to be notified after host DgnModel has been
filled.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnModelAppData__OnCleanup =R"doc(Override this method to be notified when host DgnModel is about to be
deleted from memory or when this appdata is being dropped from the
host model. @note The persistent DgnModel is not being deleted, just
this in-memory copy of it.)doc";


static const char* __doc_Bentley_DgnPlatform_DgnModel_GetControlElementsP = R"doc(Get the list of control elements in this model.

Returns:
    the list of control elements in this model)doc";

static const char* __doc_Bentley_DgnPlatform_DgnModel_GetGraphicElementsP = R"doc(Get the list of graphic elements in this model.

Returns:
    the list of graphic elements in this model)doc";

static const char* __doc_Bentley_DgnPlatform_DgnModel_GetReferencedBy = R"doc(Get the list of Bentley::DgnPlatform::DgnAttachments that reference this model.

Returns:
    the list of Bentley::DgnPlatform::DgnAttachments)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnModel(py::module_& m)
    {
    m.attr("INVALID_MODELREF") = INVALID_MODELREF;
    m.attr("INVALID_MODELID") = INVALID_MODELID;
    m.attr("INVALID_ELEMENTID") = INVALID_ELEMENTID;

    //===================================================================================
    // enum class GeoAttachmentHandling
    py::enum_< GeoAttachmentHandling>(m, "GeoAttachmentHandling")
        .value("eDefault", GeoAttachmentHandling::Default)
        .value("eDoNotReproject", GeoAttachmentHandling::DoNotReproject)
        .value("eAcceptUnprojected", GeoAttachmentHandling::AcceptUnprojected)
        .export_values();

    //===================================================================================
    // struct DgnModelAppData
    py::class_< DgnModelAppData, PyDgnModelAppData<DgnModelAppData>, std::shared_ptr<DgnModelAppData> > c9(m, "DgnModelAppData");

    if (true)
        {
        //===================================================================================
        // struct Key
        py::class_< DgnModelAppData::Key, AppDataKey> c9_1(c9, "Key");
        c9_1.def(py::init<>());
        }

    c9.def(py::init_alias<>());
    c9.def("_OnCleanup", &DgnModelAppData::_OnCleanup, "host"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnCleanup));
    c9.def("_OnFilled", &DgnModelAppData::_OnFilled, "host"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnFilled));
    c9.def("_OnEmpty", &DgnModelAppData::_OnEmpty, "host"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnEmpty));
    c9.def("_OnEmptied", &DgnModelAppData::_OnEmptied, "host"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnEmptied));
    c9.def("_OnModelDelete", &DgnModelAppData::_OnModelDelete, "host"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnModelDelete));
    c9.def("_OnModelUnDelete", &DgnModelAppData::_OnModelUnDelete, "host"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnModelUnDelete));
    c9.def("_OnElementAdded", &DgnModelAppData::_OnElementAdded, "host"_a, "elem"_a, "isGraphicsList"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnElementAdded));    
    c9.def("_OnSaveModelProperties", &DgnModelAppData::_OnSaveModelProperties, "host"_a, "original"_a, DOC(Bentley, DgnPlatform, DgnModelAppData, _OnSaveModelProperties));        

    //===================================================================================
    // struct PersistentElementRefList
    py::class_< PersistentElementRefList, std::unique_ptr<PersistentElementRefList, py::nodelete>> c11(m, "PersistentElementRefList");

    c11.def("IsEmpty", &PersistentElementRefList::IsEmpty);
    c11.def("GetDgnModel", &PersistentElementRefList::GetDgnModelP, py::return_value_policy::reference_internal);
    c11.def("__iter__", [](PersistentElementRefList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct ReferencedByArray
    py::class_< ReferencedByArray, bvector<DgnAttachmentP>>(m, "ReferencedByArray");

    //===================================================================================
    // struct DgnModel
    py::class_< DgnModel, DgnModelRef> c10(m, "DgnModel");
    bind_PointerVector<DgnModelP>(m, "DgnModelPArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // struct ElementsCollection
        py::class_<DgnModel::ElementsCollection> c10_1(m, "ElementsCollection");
        c10_1.def("__iter__", [](DgnModel::ElementsCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
        c10_1.def_property_readonly("Count", [](DgnModel::ElementsCollection& self) { return std::distance(self.begin(), self.end()); });
        c10_1.def("__len__", [](DgnModel::ElementsCollection& self) { return std::distance(self.begin(), self.end()); });
        }

    c10.def_property_readonly("DgnComponentDefinitionHandler", &DgnModel::GetDgnComponentDefinitionHandler);
    c10.def("GetDgnComponentDefinitionHandler", &DgnModel::GetDgnComponentDefinitionHandler, py::return_value_policy::reference_internal);
    c10.def("SetModelInfo", &DgnModel::SetModelInfo, "modelInfo"_a, DOC(Bentley, DgnPlatform, DgnModel, SetModelInfo));

    c10.def("FillSections", [](DgnModel& self, DgnModelSections sectionsToFill) 
        {
        return self.FillSections(sectionsToFill);
        },"sectionsToFill"_a, DOC(Bentley, DgnPlatform, DgnModel, FillSections));

    c10.def("Empty", &DgnModel::Empty, "evenIfDirty"_a = false, "andFree"_a = false, DOC(Bentley, DgnPlatform, DgnModel, Empty));
    c10.def("IsFilled", &DgnModel::IsFilled, "sections"_a, DOC(Bentley, DgnPlatform, DgnModel, IsFilled));
    c10.def("GetElementCount", &DgnModel::GetElementCount, "sections"_a, DOC(Bentley, DgnPlatform, DgnModel, GetElementCount));
    
    c10.def_property_readonly("FileLevelCache", &DgnModel::GetFileLevelCacheR);
    c10.def("GetFileLevelCache", &DgnModel::GetFileLevelCacheR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnModel, GetFileLevelCache));
    
    c10.def("IsDictionaryModel", &DgnModel::IsDictionaryModel, DOC(Bentley, DgnPlatform, DgnModel, IsDictionaryModel));

    c10.def("GetControlElements", [](DgnModel& self)
        {
        return std::unique_ptr<PersistentElementRefList, py::nodelete>(self.GetControlElementsP());
        }, DOC(Bentley, DgnPlatform, DgnModel, GetControlElementsP));

    c10.def("GetGraphicElements", [](DgnModel& self)
        {
        return std::unique_ptr<PersistentElementRefList, py::nodelete>(self.GetGraphicElementsP());
        }, DOC(Bentley, DgnPlatform, DgnModel, GetGraphicElementsP));

    c10.def("GetReferencedBy", &DgnModel::GetReferencedBy, py::return_value_policy::reference_internal,  DOC(Bentley, DgnPlatform, DgnModel, GetReferencedBy));
    
    c10.def("AddRef", &DgnModel::AddRef, DOC(Bentley, DgnPlatform, DgnModel, AddRef));
    c10.def("Release", &DgnModel::Release, DOC(Bentley, DgnPlatform, DgnModel, Release));

    c10.def_property_readonly("ElementsCollection", &DgnModel::GetElementsCollection);
    c10.def("GetElementsCollection", [](DgnModelCR self) 
         {
         DgnModel::ElementsCollection* elemcolP = new DgnModel::ElementsCollection(self.GetElementsCollection());
         return std::unique_ptr<DgnModel::ElementsCollection>(elemcolP);
         }, DOC(Bentley, DgnPlatform, DgnModel, GetElementsCollection));

    c10.def_property_readonly("ModelId", &DgnModel::GetModelId);
    c10.def("GetModelId", &DgnModel::GetModelId, DOC(Bentley, DgnPlatform, DgnModel, GetModelId));
    
    c10.def_property_readonly("ModelInfo", &DgnModel::GetModelInfo);
    c10.def("GetModelInfo", &DgnModel::GetModelInfo, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnModel, GetModelInfo));
    c10.def("SaveModelSettings", &DgnModel::SaveModelSettings, DOC(Bentley, DgnPlatform, DgnModel, SaveModelSettings));
    
    c10.def_property_readonly("ModelName", &DgnModel::GetModelName);
    c10.def("GetModelName", &DgnModel::GetModelName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnModel, GetModelName));
    
    c10.def("IsReadOnly", py::overload_cast<>(&DgnModel::IsReadOnly, py::const_), DOC(Bentley, DgnPlatform, DgnModel, IsReadOnly));
    
    c10.def_property_readonly("DgnFile", [] (DgnModelCR self) { return DgnFilePtr(self.GetDgnFileP()); });
    c10.def("GetDgnFile", [] (DgnModelCR self) { return DgnFilePtr(self.GetDgnFileP()); });
    
    c10.def("GetRange", py::overload_cast<ScanRangeR>(&DgnModel::GetRange), "range"_a, DOC(Bentley, DgnPlatform, DgnModel, GetRange));
    c10.def("GetRange", py::overload_cast<DRange3dR>(&DgnModel::GetRange), "range"_a, DOC(Bentley, DgnPlatform, DgnModel, GetRange));
    c10.def("AddAppData", &DgnModel::AddAppData, "key"_a, "appData"_a, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, DgnModel, AddAppData));
    c10.def("DropAppData", &DgnModel::DropAppData, "key"_a, DOC(Bentley, DgnPlatform, DgnModel, DropAppData));
    c10.def("FindAppData", &DgnModel::FindAppData, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnModel, FindAppData));
    
    c10.def_property_readonly("ControlElmStart", &DgnModel::GetControlElmStart);
    c10.def("GetControlElmStart", &DgnModel::GetControlElmStart, DOC(Bentley, DgnPlatform, DgnModel, GetControlElmStart));
    
    c10.def_property_readonly("GraphicElmStart", &DgnModel::GetGraphicElmStart);
    c10.def("GetGraphicElmStart", &DgnModel::GetGraphicElmStart, DOC(Bentley, DgnPlatform, DgnModel, GetGraphicElmStart));
    
    c10.def("FindElementByID", &DgnModel::FindElementByID, py::return_value_policy::reference);

    py::class_< PersistentElementRef, ElementRefBase>(m, "PersistentElementRef");
    }
