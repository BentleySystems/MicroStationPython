/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnitemindex.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/dgnitemindex.h>



static const char * __doc_Bentley_DgnPlatform_ModelIndex_CopyItems =R"doc(Copy the items out of the ModelIndex into a vector.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndex_GetItemByID =R"doc(Get a ModelItem from the index for a specified model id.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndex_GetItemByName =R"doc(Get a ModelItem from the index for a specified model name. Items will
not be returned for deleted models.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_GetLastSavedTime =R"doc(The last time the model was saved to disk.)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_GetModelType =R"doc(Type of model)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_IsMarkup =R"doc(Is this a markup model?)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_IsHidden =R"doc(Should this model be hidden from the user interface?)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_GetCellType =R"doc(Cell type)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_IsAnnotationCell =R"doc(Is this model intended to be placed as an annotation cell?)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_IsCell =R"doc(Is this model intended to be placed as a cell?)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_IsDeleted =R"doc(Is this model scheduled for deletion the next time
DgnFile::ProcessChanges is called?)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_Is3D =R"doc(Does this model contain 3-D elements?)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_GetDescription =R"doc(Description of the model)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_GetName =R"doc(Unique name of the model)doc";

static const char * __doc_Bentley_DgnPlatform_ModelIndexItem_GetModelId =R"doc(Unique ID of the model (never changes))doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnItemIndex(py::module_& m)
    {
    //===================================================================================
    // struct ModelIndexItem
    py::class_< ModelIndexItem> c1(m, "ModelIndexItem");

    c1.def_property_readonly("ModelId", &ModelIndexItem::GetModelId);
    c1.def("GetModelId", &ModelIndexItem::GetModelId, DOC(Bentley, DgnPlatform, ModelIndexItem, GetModelId));
    
    c1.def_property_readonly("Name", &ModelIndexItem::GetName);
    c1.def("GetName", &ModelIndexItem::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelIndexItem, GetName));
    
    c1.def_property_readonly("Description", &ModelIndexItem::GetDescription);
    c1.def("GetDescription", &ModelIndexItem::GetDescription, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelIndexItem, GetDescription));
    
    c1.def("Is3D", &ModelIndexItem::Is3D, DOC(Bentley, DgnPlatform, ModelIndexItem, Is3D));
    c1.def("IsDeleted", &ModelIndexItem::IsDeleted, DOC(Bentley, DgnPlatform, ModelIndexItem, IsDeleted));
    c1.def("IsCell", &ModelIndexItem::IsCell, DOC(Bentley, DgnPlatform, ModelIndexItem, IsCell));
    c1.def("IsAnnotationCell", &ModelIndexItem::IsAnnotationCell, DOC(Bentley, DgnPlatform, ModelIndexItem, IsAnnotationCell));
    
    c1.def_property_readonly("CellType", &ModelIndexItem::GetCellType);
    c1.def("GetCellType", &ModelIndexItem::GetCellType, DOC(Bentley, DgnPlatform, ModelIndexItem, GetCellType));
    
    c1.def("IsHidden", &ModelIndexItem::IsHidden, DOC(Bentley, DgnPlatform, ModelIndexItem, IsHidden));
    c1.def("IsMarkup", &ModelIndexItem::IsMarkup, DOC(Bentley, DgnPlatform, ModelIndexItem, IsMarkup));
    
    c1.def_property_readonly("ModelType", &ModelIndexItem::GetModelType);
    c1.def("GetModelType", &ModelIndexItem::GetModelType, DOC(Bentley, DgnPlatform, ModelIndexItem, GetModelType));
    
    c1.def_property_readonly("LastSavedTime", &ModelIndexItem::GetLastSavedTime);
    c1.def("GetLastSavedTime", &ModelIndexItem::GetLastSavedTime, DOC(Bentley, DgnPlatform, ModelIndexItem, GetLastSavedTime));

    //===================================================================================
    // struct ModelIndex
    py::class_< ModelIndex, std::unique_ptr<ModelIndex, py::nodelete> > c2(m, "ModelIndex");

    c2.def("__iter__", [] (ModelIndex& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c2.def("GetItemByName", &ModelIndex::GetItemByName, "name"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelIndex, GetItemByName));
    c2.def("GetItemByID", &ModelIndex::GetItemByID, "id"_a, "getIfDeleted"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ModelIndex, GetItemByID));
    c2.def("CopyItems", &ModelIndex::CopyItems, "outItems"_a, "includeDeletedModels"_a = false, DOC(Bentley, DgnPlatform, ModelIndex, CopyItems));
    }