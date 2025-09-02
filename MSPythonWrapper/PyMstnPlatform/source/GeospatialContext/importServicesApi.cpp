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

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_GetClassName = R"doc(Get the class name of this feature specification.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_GetDisplayName = R"doc(Get the display name of this feature specification.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_GetExistingTemplateDgnFile = R"doc(Get the DgnFile containing the existing template of this feature specification. 

Returns:
    This method returns the DgnFile containing the existing element template associated with the import feature specification.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_SetExistingTemplateDgnFile = R"doc(Set the DgnFile containing the existing template of this feature specification. 

Parameter ``existingTemplateDgnFile``:
    DgnFile containing the existing element template.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_GetExistingTemplateFullPath = R"doc(Get the full path of the existing template of this feature specification. 

Returns:
    This method returns the full path of the existing template associated with the import feature specification.
    The full path includes the template group name and the template name. For example: "MyProject\\PACounties"
    Defaults to null, indicating that a default template group name based on the GDB folder name and template name based on the class name will be used. 
    If this template does not exist, it will be created. For example: "UnitedStates.gdb\\PACounties"
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_SetExistingTemplateFullPath = R"doc(Set the full path of the existing template of this feature specification. 

Parameter ``existingTemplateFullPath``:
    Full path of the existing template.
    The full path includes the template group name and the template name. For example: "MyProject\\PACounties"
    Defaults to null, indicating that a default template group name based on the GDB folder name and template name based on the class name will be used. 
    If this template does not exist, it will be created. For example: "UnitedStates.gdb\\PACounties"

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_GetIsSelected = R"doc(Get the selected state of this feature specification.

Returns:
bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_SetIsSelected = R"doc(Set the selected state of this feature specification.

Parameter ``isSelected``:
    Is feature specification selected.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_GetFlipCoordinates = R"doc(Get the boolean denoting flip coordinates state.

Returns:
bool value. Default value is false.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportFeatureSpecification_SetFlipCoordinates = R"doc(Set the boolean denoting flip coordinates state.

Parameter ``flipCoordinates``:
    Flip Coordinates. Default value is false.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_SHPImportSpecification_Import = R"doc(Import features as specified by the import specification.

Parameter ``[out]``:
    The returned Number of features imported.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_SHPImportSpecification_CreateDefaultElementTemplate = R"doc(Create the default element template with associated item type for feature as specified by the import specification.
This method is not normally called by the user, since it is called internally by the Import method to create(if not existing) the default element template with associated item type for the feature as specified by the import specification.
This method is useful if the element template must exist to be modified before the import is performed. For example, change the element template active point type from zero length line to cell before importing.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_GDBImportSpecification_GetGDBFolderDocument = R"doc(Get the GDB folder moniker.

Returns:
    This method returns the GDB folder moniker associated with the import specification.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_GDBImportSpecification_CreateDefaultElementTemplates = R"doc(Create the default element templates with associated item types for features as specified by the import specification.
This method is not normally called by the user, since it is called internally by the Import method to create(if not existing) the default element templates with associated item types for the features as specified by the import specification.
This method is useful if the element template must exist to be modified before the import is performed. For example, change the element template active point type from zero length line to cell before importing.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_GDBImportSpecification_GetImportFeatureSpecifications = R"doc(Get the list of import feature specifications.

Parameter ``importFeatureSpecs``:
    The List of import feature specifications associated with the import specification.

Returns:
    None.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportManager_GetManager = R"doc()doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportManager_IsImportedFeatureElement = R"doc(Is this element a feature instance element that has been imported.

Parameter ``element``:
    The Element to check.

Returns:
    Bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportManager_GetImportedFeatureClassNameFromElement = R"doc(Get the imported feature class name from the given element)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportManager_CreateSHPImportSpecification = R"doc(Create a new import specification for a SHP file

Parameter ``[out]``:
    The new Import specification.

Parameter ``shpFile``:
    The DgnDocumentMonikerPtr of the SHP file to import.

Parameter ``dgnContainingExistingTemplate``:
    The DgnFile containing the existing template.

Parameter ``existingTemplateFullPath``:
    The full path of the existing template. If not empty, the template is searched in the dgnContainingExistingTemplate. If empty, either the provided newTemplateName or a default template name is used.

Parameter ``flipCoordinates``:
    Flip XY coordinates.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ImportManager_CreateGDBImportSpecification = R"doc(Create a new import specification for a GDB file

Parameter ``[out]``:
    The new Import specification.

Parameter ``gdbFolder``:
    The DgnFolderMonikerPtr of the GDB file to import.

Returns:
    GeospatialContextStatus value.

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      11/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GeospatialContextImportServicesAPI(py::module_& m)
    {
    //===================================================================================
    // struct ImportFeatureSpecification
    py::class_<ImportFeatureSpecification, ImportFeatureSpecificationPtr> c0(m, "ImportFeatureSpecification");
    py::bind_vector< bvector<ImportFeatureSpecificationPtr> >(m, "ImportFeatureSpecificationPtrArray", py::module_local(false));

    c0.def("GetClassName", [](ImportFeatureSpecification& self) {return WString(self.GetClassName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetClassName));
    c0.def("GetDisplayName", [](ImportFeatureSpecification& self) {return WString(self.GetDisplayName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetDisplayName));
    c0.def("GetExistingTemplateFullPath", [](ImportFeatureSpecification& self) {return WString(self.GetExistingTemplateFullPath()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetExistingTemplateFullPath));
    c0.def("SetExistingTemplateFullPath", [](ImportFeatureSpecification& self, WStringCR existingTemplateFullPath) {self.SetExistingTemplateFullPath(existingTemplateFullPath); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetExistingTemplateFullPath));
    c0.def("GetExistingTemplateDgnFile", [](ImportFeatureSpecification& self) {return self.GetExistingTemplateDgnFile(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetExistingTemplateDgnFile));
    c0.def("SetExistingTemplateDgnFile", [](ImportFeatureSpecification& self, DgnFileP existingTemplateDgnFile) {self.SetExistingTemplateDgnFile(existingTemplateDgnFile); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetExistingTemplateDgnFile));
    c0.def_property("FlipCoordinates", &ImportFeatureSpecification::GetFlipCoordinates, &ImportFeatureSpecification::SetFlipCoordinates);
    c0.def("GetFlipCoordinates", &ImportFeatureSpecification::GetFlipCoordinates, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetFlipCoordinates));
    c0.def("SetFlipCoordinates", &ImportFeatureSpecification::SetFlipCoordinates, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetFlipCoordinates));

    c0.def_property("IsSelected", &ImportFeatureSpecification::GetIsSelected, &ImportFeatureSpecification::SetIsSelected);
    c0.def("GetIsSelected", &ImportFeatureSpecification::GetIsSelected, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetIsSelected));
    c0.def("SetIsSelected", &ImportFeatureSpecification::SetIsSelected, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetIsSelected));

    //===================================================================================
    // struct SHPImportSpecification
    py::class_<SHPImportSpecification, SHPImportSpecificationPtr> c1(m, "SHPImportSpecification");

    c1.def("GetExistingTemplateFullPath", [](SHPImportSpecification& self) {return WString(self.GetExistingTemplateFullPath()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetExistingTemplateFullPath));
    c1.def("SetExistingTemplateFullPath", [](SHPImportSpecification& self, WStringCR existingTemplateFullPath) {self.SetExistingTemplateFullPath(existingTemplateFullPath); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetExistingTemplateFullPath));
    c1.def("GetExistingTemplateDgnFile", [](SHPImportSpecification& self) {return self.GetExistingTemplateDgnFile(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetExistingTemplateDgnFile));
    c1.def("SetExistingTemplateDgnFile", [](SHPImportSpecification& self, DgnFileP existingTemplateDgnFile) {self.SetExistingTemplateDgnFile(existingTemplateDgnFile); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetExistingTemplateDgnFile));
    c1.def_property("FlipCoordinates", &SHPImportSpecification::GetFlipCoordinates, &SHPImportSpecification::SetFlipCoordinates);
    c1.def("GetFlipCoordinates", &SHPImportSpecification::GetFlipCoordinates, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, GetFlipCoordinates));
    c1.def("SetFlipCoordinates", &SHPImportSpecification::SetFlipCoordinates, DOC(Bentley, MstnPlatform, GeospatialContext, ImportFeatureSpecification, SetFlipCoordinates));
    c1.def("Import", [](SHPImportSpecification& self)
        {
            int nImported = 0;
            GeospatialContextStatus status = self.Import(nImported);
            return py::make_tuple(status, nImported);
        }, DOC(Bentley, MstnPlatform, GeospatialContext, SHPImportSpecification, Import));
    c1.def("CreateDefaultElementTemplate", &SHPImportSpecification::CreateDefaultElementTemplate, DOC(Bentley, MstnPlatform, GeospatialContext, SHPImportSpecification, CreateDefaultElementTemplate));

    //===================================================================================
    // struct GDBImportSpecification
    py::class_<GDBImportSpecification, GDBImportSpecificationPtr> c2(m, "GDBImportSpecification");

    c2.def("GetGDBFolderDocument", [](GDBImportSpecification& self) {return self.GetGDBFolderDocument(); }, DOC(Bentley, MstnPlatform, GeospatialContext, GDBImportSpecification, GetGDBFolderDocument));

    c2.def("GetImportFeatureSpecifications", ([](GDBImportSpecification& self, bvector<ImportFeatureSpecificationPtr>& importFeatureSpecs)
        {
            self.GetImportFeatureSpecifications(importFeatureSpecs);
        }), "importFeatureSpecs"_a, DOC(Bentley, MstnPlatform, GeospatialContext, GDBImportSpecification, GetImportFeatureSpecifications));

    c2.def("Import", [](GDBImportSpecification& self)
        {
            int nImported = 0;
            GeospatialContextStatus status = self.Import(nImported);
            return py::make_tuple(status, nImported);
        }, DOC(Bentley, MstnPlatform, GeospatialContext, SHPImportSpecification, Import));
    c2.def("CreateDefaultElementTemplates", &GDBImportSpecification::CreateDefaultElementTemplates, DOC(Bentley, MstnPlatform, GeospatialContext, GDBImportSpecification, CreateDefaultElementTemplates));

    //===================================================================================
    // struct ImportManager
    py::class_< ImportManager, std::unique_ptr < ImportManager, py::nodelete>> c3(m, "ImportManager");

    c3.def_property_readonly_static("Manager", [](py::object const&) { return std::unique_ptr< ImportManager, py::nodelete>(&ImportManager::GetManager()); });
    c3.def_static("GetManager", []() { return std::unique_ptr< ImportManager, py::nodelete>(&ImportManager::GetManager()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ImportManager, GetManager));

    c3.def_static("IsImportedFeatureElement", [](ElementHandleCR eh)
        {
            return ImportManager::IsImportedFeatureElement(eh);
        }, "eh"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ImportManager, IsImportedFeatureElement));

    c3.def_static("GetImportedFeatureClassNameFromElement", &ImportManager::GetImportedFeatureClassNameFromElement, "featureClassName"_a, "element"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ImportManager, GetImportedFeatureClassNameFromElement));

    c3.def("CreateSHPImportSpecification", [](ImportManager& self, DgnDocumentMonikerPtr shpFile, DgnFileP dgnContainingExistingTemplate, WStringCR existingTemplateFullPath, bool flipCoordinates)
        {
            SHPImportSpecificationPtr importSpec;
            GeospatialContextStatus status = self.CreateSHPImportSpecification(importSpec, shpFile, dgnContainingExistingTemplate, existingTemplateFullPath, flipCoordinates);
            return py::make_tuple(status, importSpec);
        }, "shpFile"_a, "dgnContainingExistingTemplate"_a, "existingTemplateFullPath"_a, "flipCoordinates"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ImportManager, CreateSHPImportSpecification));

    c3.def("CreateGDBImportSpecification", [](ImportManager& self, DgnFolderMonikerPtr gdbFolder)
        {
            GDBImportSpecificationPtr importSpec;
            GeospatialContextStatus status = self.CreateGDBImportSpecification(importSpec, gdbFolder);
            return py::make_tuple(status, importSpec);
        }, "gdbFolder"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ImportManager, CreateGDBImportSpecification));
    }
