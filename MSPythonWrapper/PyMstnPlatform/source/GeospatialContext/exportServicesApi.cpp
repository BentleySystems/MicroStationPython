/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\3dModeling\meshapi.cpp $
|
|  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

#include <GeospatialContext\GeospatialContextApi.h>

USING_NAMESPACE_BENTLEY_MSTNPLATFORM_GEOSPATIALCONTEXT

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetElementFilterMode = R"doc(Get the element filter mode of export operation.

Returns :
ExportElementFilterMode.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetElementFilterMode = R"doc(Set the element filter mode of export operation.

Parameter ``mode``:
Mode of export operation.
The mode specifies the elements to be exported.

Returns :
    None.

)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_LevelSpecification_GetLevelName = R"doc(Gets the level name for a LevelSpecification".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_LevelSpecification_SetLevelName = R"doc(Sets the level name for a LevelSpecification".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_LevelSpecification_GetDgnFile = R"doc(Gets the DgnFile containing the level".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_LevelSpecification_SetDgnFile = R"doc(Sets the DgnFile containing the level".)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ItemTypeSpecification_GetItemTypeDgnFile = R"doc(Gets the DgnFile containing the item type.".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ItemTypeSpecification_SetItemTypeDgnFile = R"doc(Sets the DgnFile containing the item type.".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ItemTypeSpecification_GetItemTypeLibraryName = R"doc(Gets the Item type library name.".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ItemTypeSpecification_SetItemTypeLibraryName = R"doc(Sets the Item type library name.".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ItemTypeSpecification_GetItemTypeName = R"doc(Gets the Item type name.".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ItemTypeSpecification_SetItemTypeName = R"doc(Sets the Item type name.".)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetNamePrefix = R"doc(Gets the file name prefix for output files used when ExportElementFilterMode is ExportElementFilterMode::BySelectionSet. Defaults to "My_Prefix".)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetNamePrefix = R"doc(Sets the file name prefix for output files used when ExportElementFilterMode is ExportElementFilterMode::BySelectionSet. Defaults to "My_Prefix".)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetFolderMoniker = R"doc(Get the folder moniker.
This method returns the folder moniker associated with the export specification.

Returns:
DgnFolderMonikerPtr value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetFolderMoniker = R"doc(Set the folder moniker.
This method sets the folder moniker associated with the export specification.

Parameter ``folderMoniker``:
    Folder moniker.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetPreserveZ = R"doc(Get the indicator that 3D data is exported as 3D or 2D.

Returns:
bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetPreserveZ = R"doc(Set the indicator that 3D data is exported as 3D or 2D.

Parameter ``preserveZ``:
    Indicator that the Z values should be preserved when exporting elements.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetIncludeReferenceFiles = R"doc(Get the indicator that the reference files should be processed when exporting elements.
The IncludeReferenceFiles value only applies when the ExportElementFilterMode is one of: ByElementTemplate, ByItemType, ByLevel.

Returns:
bool value. Default value is false.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetIncludeReferenceFiles = R"doc(Set the indicator that the reference files should be processed when exporting elements.
The IncludeReferenceFiles value only applies when the ExportElementFilterMode is one of: ByElementTemplate, ByItemType, ByLevel.

Parameter ``includeReferenceFiles``:
    Indicator that the reference files should be processed when exporting elements. Default value is false.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetUseFenceOverlap = R"doc(Get the indicator that the active fence with non-clip overlap mode should be processed when exporting elements.
The UseFenceOverlap value only applies when there is an active fence and the ExportElementFilterMode is one of: ByElementTemplate, ByItemType, ByLevel.

Returns:
bool value. Default value is false.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetUseFenceOverlap = R"doc(Set the indicator that the active fence with non-clip overlap mode should be processed when exporting elements.
The UseFenceOverlap value only applies when there is an active fence and the ExportElementFilterMode is one of: ByElementTemplate, ByItemType, ByLevel.

Parameter ``useFenceOverlap``:
    Indicator that the active fence with non-clip overlap mode should be processed when exporting elements. Default value is false.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetExportTextString = R"doc(Gets the indicator that the element's text string should be exported to the output file.

Returns:
bool value. Default value is True.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetExportTextString = R"doc(Sets the indicator that the element's text string should be exported to the output file.

Parameter ``exportTextString``:
    Indicator that the element's text string should be exported to the output file. Default value is True.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetFacetCurves = R"doc(Get the indicator that curves(circle, curve, Bspline) should be faceted during export.

Returns:
bool value. Default value is false.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetFacetCurves = R"doc(Set the indicator that curves(circle, curve, Bspline) should be faceted during export.

Parameter ``facetCurves``:
    Indicator that curves should be faceted during export. Default value is false.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetMaxChordHeight = R"doc(Gets the Maximum Chord Height(The maximum chord height for all of the line segments is less than the Chord Height) used when FacetCurves=true.
Value is in Master Units. Defaults to 0.0.
To determine the maximum chord height value, use the Facet Curve tool with Method="Max. Chord Height" on your data.

Returns:
float value. Default value is 0.0.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_SetMaxChordHeight = R"doc(Sets the Maximum Chord Height, the maximum chord height for all of the line segments is less than the Chord Height, used when FacetCurves=true.
Value is in Master Units. Defaults to 0.0.
To determine the maximum chord height value, use the Facet Curve tool with Method="Max. Chord Height" on your data.

Parameter ``maxChordHeight``:
    Maximum Chord Height. Default value is 0.0.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_AddElementTemplateName = R"doc(Add Element Template name to export.
Call this method for each element template name to export.
Element Templates are prefixed by group name(s) followed by a backslashes ('\\'). For example: myTemplates\\templateOne
This only applies when the ExportElementFilterMode is: eExportElementFilterMode_ByElementTemplate.

Parameter ``elementTemplateName``:
    Element Template name.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetElementTemplateNames = R"doc(Get the list of element template names to export.
This method returns the list of element template names associated with the export specification.
This only applies when the ExportElementFilterMode is: eExportElementFilterMode_ByElementTemplate.

Parameter ``elementTemplateNames``:
    List of element template names.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_AddItemTypeName = R"doc(Add Item Type name to export.
Call this method for each item type name to export.
This only applies when the ExportElementFilterMode is: eExportElementFilterMode_ByItemType.

Parameter ``dgnContainingItemType``:
    DgnFile containing the item type.

Parameter ``itemTypeLibraryName``:
    Item type library name.

Parameter ``itemTypeName``:
    Item type name.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetItemTypeNames = R"doc(Get the list of item type specifications to export.
This only applies when the ExportElementFilterMode is: eExportElementFilterMode_ByItemType.

Parameter ``itemTypeNames``:
    List of item type specifications.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_AddLevelName = R"doc(Add Level name to export.
Call this method for each level name to export.
This only applies when the ExportElementFilterMode is: eExportElementFilterMode_ByLevel.

Parameter ``dgnContainingLevel``:
    DgnFile containing the level.

Parameter ``levelName``:
    Level name.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportSpecification_GetLevelNames = R"doc(Get the list of level names to export.
This only applies when the ExportElementFilterMode is: eExportElementFilterMode_ByLevel.

Parameter ``levelNames``:
    List of level specifications.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_SHPExportSpecification_Export = R"doc(Export elements as specified by the export specification.

Parameter ``[out]``:
    The returned Number of elements exported.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_GDBExportSpecification_GetExportSpecifications = R"doc(Get the list of export feature specifications.

Parameter ``exportFeatureSpecs``:
    The List of export feature specifications associated with the export specification.

Returns:
    None.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportManager_GetManager = R"doc()doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportManager_CreateSHPExportSpecification = R"doc(Create a new export specification for a SHP file
The export specification is a data structure that contains the information needed to export DGN elements to a SHP file.

Parameter ``[out]``:
    The new Export specification.

Parameter ``elementFilterMode``:
    The Element filter mode of the Export specification.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ExportManager_CreateGDBExportSpecification = R"doc(Create a new export specification for a GDB file.
The export specification is a data structure that contains the information needed to export DGN elements to a GDB file.

Parameter ``[out]``:
    The new Export specification.

Parameter ``elementFilterMode``:
    The Element filter mode of the Export specification.

Returns:
    GeospatialContextStatus value.

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      11/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GeospatialContextExportServicesAPI(py::module_& m)
    {
    //===================================================================================
    // enum ExportElementFilterMode
    py::enum_< ExportElementFilterMode>(m, "ExportElementFilterMode", py::arithmetic())
        .value("eExportElementFilterMode_ByLevel", ExportElementFilterMode::ByLevel)
        .value("eExportElementFilterMode_ByElementTemplate", ExportElementFilterMode::ByElementTemplate)
        .value("eExportElementFilterMode_ByItemType", ExportElementFilterMode::ByItemType)
        .value("eExportElementFilterMode_BySelectionSet", ExportElementFilterMode::BySelectionSet)
        .export_values();

    //===================================================================================
    // struct LevelSpecification
    py::class_<LevelSpecification, LevelSpecificationPtr> cLvlSpec(m, "LevelSpecification");
    py::bind_vector< bvector<LevelSpecificationPtr> >(m, "LevelSpecificationPtrArray", py::module_local(false));

    cLvlSpec.def("GetLevelName", [](LevelSpecification& self) {return WString(self.GetLevelName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, LevelSpecification, GetLevelName));
    cLvlSpec.def("SetLevelName", [](LevelSpecification& self, WStringCR levelName) {self.SetLevelName(levelName); }, "levelName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, LevelSpecification, SetLevelName));
    cLvlSpec.def("GetDgnFile", [](LevelSpecification& self) {return self.GetDgnFile(); }, DOC(Bentley, MstnPlatform, GeospatialContext, LevelSpecification, GetDgnFile));
    cLvlSpec.def("SetDgnFile", [](LevelSpecification& self, DgnFileP dgnFile) {self.SetDgnFile(dgnFile); }, "dgnFile"_a, DOC(Bentley, MstnPlatform, GeospatialContext, LevelSpecification, SetDgnFile));

    //===================================================================================
    // struct ItemTypeSpecification
    py::class_<ItemTypeSpecification, ItemTypeSpecificationPtr> cItemTypeSpec(m, "ItemTypeSpecification");
    py::bind_vector< bvector<ItemTypeSpecificationPtr> >(m, "ItemTypeSpecificationPtrArray", py::module_local(false));

    cItemTypeSpec.def("GetItemTypeDgnFile", [](ItemTypeSpecification& self) {return self.GetItemTypeDgnFile(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ItemTypeSpecification, GetItemTypeDgnFile));
    cItemTypeSpec.def("SetItemTypeDgnFile", [](ItemTypeSpecification& self, DgnFileP dgnFile) {self.SetItemTypeDgnFile(dgnFile); }, "dgnFile"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ItemTypeSpecification, SetItemTypeDgnFile));
    cItemTypeSpec.def("GetItemTypeLibraryName", [](ItemTypeSpecification& self) {return WString(self.GetItemTypeLibraryName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ItemTypeSpecification, GetItemTypeLibraryName));
    cItemTypeSpec.def("SetItemTypeLibraryName", [](ItemTypeSpecification& self, WStringCR itemTypeLibraryName) {self.SetItemTypeLibraryName(itemTypeLibraryName); }, "itemTypeLibraryName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ItemTypeSpecification, SetItemTypeLibraryName));
    cItemTypeSpec.def("GetItemTypeName", [](ItemTypeSpecification& self) {return WString(self.GetItemTypeName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ItemTypeSpecification, GetItemTypeName));
    cItemTypeSpec.def("SetItemTypeName", [](ItemTypeSpecification& self, WStringCR itemTypeName) {self.SetItemTypeName(itemTypeName); }, "itemTypeName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ItemTypeSpecification, SetItemTypeName));

    //===================================================================================
    // struct ExportSpecification
    py::class_<ExportSpecification, ExportSpecificationPtr> c0(m, "ExportSpecification");
    py::bind_vector< bvector<ExportSpecificationPtr> >(m, "ExportSpecificationPtrArray", py::module_local(false));

    c0.def_property("ElementFilterMode", &ExportSpecification::GetElementFilterMode, &ExportSpecification::SetElementFilterMode);
    c0.def("GetElementFilterMode", [](ExportSpecification& self) {return self.GetElementFilterMode(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetElementFilterMode));
    c0.def("SetElementFilterMode", [](ExportSpecification& self, ExportElementFilterMode mode) {self.SetElementFilterMode(mode); }, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetElementFilterMode));

    c0.def("GetFolderMoniker", [](ExportSpecification& self) {return self.GetFolderMoniker(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetFolderMoniker));
    c0.def("SetFolderMoniker", [](ExportSpecification& self, DgnFolderMonikerPtr folderMoniker) {self.SetFolderMoniker(folderMoniker); }, "folderMoniker"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetFolderMoniker));

    c0.def("GetNamePrefix", [](ExportSpecification& self) {return WString(self.GetNamePrefix()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetNamePrefix));
    c0.def("SetNamePrefix", [](ExportSpecification& self, WStringCR namePrefix) {self.SetNamePrefix(namePrefix); }, "namePrefix"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetNamePrefix));

    c0.def_property("IncludeReferenceFiles", &ExportSpecification::GetIncludeReferenceFiles, &ExportSpecification::SetIncludeReferenceFiles);
    c0.def("GetIncludeReferenceFiles", &ExportSpecification::GetIncludeReferenceFiles, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetIncludeReferenceFiles));
    c0.def("SetIncludeReferenceFiles", &ExportSpecification::SetIncludeReferenceFiles, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetIncludeReferenceFiles));

    c0.def_property("UseFenceOverlap", &ExportSpecification::GetUseFenceOverlap, &ExportSpecification::SetUseFenceOverlap);
    c0.def("GetUseFenceOverlap", &ExportSpecification::GetUseFenceOverlap, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetUseFenceOverlap));
    c0.def("SetUseFenceOverlap", &ExportSpecification::SetUseFenceOverlap, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetUseFenceOverlap));

    c0.def_property("PreserveZ", &ExportSpecification::GetPreserveZ, &ExportSpecification::SetPreserveZ);
    c0.def("GetPreserveZ", &ExportSpecification::GetPreserveZ, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetPreserveZ));
    c0.def("SetPreserveZ", &ExportSpecification::SetPreserveZ, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetPreserveZ));

    c0.def_property("ExportTextString", &ExportSpecification::GetExportTextString, &ExportSpecification::SetExportTextString);
    c0.def("GetExportTextString", &ExportSpecification::GetExportTextString, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetExportTextString));
    c0.def("SetExportTextString", &ExportSpecification::SetExportTextString, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetExportTextString));

    c0.def_property("FacetCurves", &ExportSpecification::GetFacetCurves, &ExportSpecification::SetFacetCurves);
    c0.def("GetFacetCurves", &ExportSpecification::GetFacetCurves, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetFacetCurves));
    c0.def("SetFacetCurves", &ExportSpecification::SetFacetCurves, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetFacetCurves));

    c0.def_property("MaxChordHeight", &ExportSpecification::GetMaxChordHeight, &ExportSpecification::SetMaxChordHeight);
    c0.def("GetMaxChordHeight", &ExportSpecification::GetMaxChordHeight, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetMaxChordHeight));
    c0.def("SetMaxChordHeight", &ExportSpecification::SetMaxChordHeight, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, SetMaxChordHeight));

    c0.def("AddElementTemplateName", [](ExportSpecification& self, WStringCR elementTemplateName) {self.AddElementTemplateName(elementTemplateName); }, "elementTemplateName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, AddElementTemplateName));
    c0.def("GetElementTemplateNames", ([](ExportSpecification& self, bvector<WString>& elementTemplateNames)
        {
            self.GetElementTemplateNames(elementTemplateNames);
        }), "elementTemplateNames"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetElementTemplateNames));

    c0.def("AddItemTypeName", [](ExportSpecification& self, DgnFileP dgnContainingItemType, WStringCR itemTypeLibraryName, WStringCR itemTypeName)
        {
            self.AddItemTypeName(dgnContainingItemType, itemTypeLibraryName, itemTypeName);
        }, "dgnContainingItemType"_a, "itemTypeLibraryName"_a, "itemTypeName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, AddItemTypeName));

    c0.def("GetItemTypeNames", ([](ExportSpecification& self, bvector<ItemTypeSpecificationPtr>& itemTypeNames)
        {
            self.GetItemTypeNames(itemTypeNames);
        }), "itemTypeNames"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetItemTypeNames));

    c0.def("AddLevelName", [](ExportSpecification& self, DgnFileP dgnContainingLevel, WStringCR levelName)
        {
            self.AddLevelName(dgnContainingLevel, levelName);
        }, "dgnContainingLevel"_a, "levelName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, AddLevelName));

    c0.def("GetLevelNames", ([](ExportSpecification& self, bvector<LevelSpecificationPtr>& levelNames)
        {
            self.GetLevelNames(levelNames);
        }), "levelNames"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportSpecification, GetLevelNames));

    //===================================================================================
    // struct SHPExportSpecification
    py::class_<SHPExportSpecification, ExportSpecification, SHPExportSpecificationPtr> c1(m, "SHPExportSpecification");

    c1.def("Export", [](SHPExportSpecification& self)
        {
            int nExported = 0;
            GeospatialContextStatus status = self.Export(nExported);
            return py::make_tuple(status, nExported);
        }, DOC(Bentley, MstnPlatform, GeospatialContext, SHPExportSpecification, Export));

    //===================================================================================
    // struct GDBExportSpecification
    py::class_<GDBExportSpecification, ExportSpecification, GDBExportSpecificationPtr> c2(m, "GDBExportSpecification");

    c2.def("GetExportSpecifications", ([](GDBExportSpecification& self, bvector<ExportSpecificationPtr>& exportFeatureSpecs)
        {
            self.GetExportSpecifications(exportFeatureSpecs);
        }), "exportFeatureSpecs"_a, DOC(Bentley, MstnPlatform, GeospatialContext, GDBExportSpecification, GetExportSpecifications));

    c2.def("Export", [](GDBExportSpecification& self)
        {
            int nExported = 0;
            GeospatialContextStatus status = self.Export(nExported);
            return py::make_tuple(status, nExported);
        }, DOC(Bentley, MstnPlatform, GeospatialContext, SHPExportSpecification, Export));

    //===================================================================================
    // struct ExportManager
    py::class_< ExportManager, std::unique_ptr < ExportManager, py::nodelete>> c3(m, "ExportManager");

    c3.def_property_readonly_static("Manager", [](py::object const&) { return std::unique_ptr< ExportManager, py::nodelete>(&ExportManager::GetManager()); });
    c3.def_static("GetManager", []() { return std::unique_ptr< ExportManager, py::nodelete>(&ExportManager::GetManager()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ExportManager, GetManager));

    c3.def("CreateSHPExportSpecification", [](ExportManager& self, ExportElementFilterMode elementFilterMode)
        {
            SHPExportSpecificationPtr exportSpec;
            GeospatialContextStatus status = self.CreateSHPExportSpecification(exportSpec, elementFilterMode);
            return py::make_tuple(status, exportSpec);
        }, "elementFilterMode"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportManager, CreateSHPExportSpecification));

    c3.def("CreateGDBExportSpecification", [](ExportManager& self, ExportElementFilterMode elementFilterMode)
        {
            GDBExportSpecificationPtr exportSpec;
            GeospatialContextStatus status = self.CreateGDBExportSpecification(exportSpec, elementFilterMode);
            return py::make_tuple(status, exportSpec);
        }, "elementFilterMode"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ExportManager, CreateGDBExportSpecification));
    }
