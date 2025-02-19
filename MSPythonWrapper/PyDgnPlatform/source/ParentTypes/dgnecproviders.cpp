/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnecproviders.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnECProviders.h>



static const char * __doc_Bentley_DgnPlatform_IDgnECProvider_FindECClassesOnElement =R"doc(Finds the schemaName className pairs for all instances on the element,
and sets a flag as to whether the primary instance on the element is
of that class.

Parameter ``rootElement``:
    The element to search

Parameter ``infos``:
    The list of schemaNameclassName pairs)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_GetDgnFile =R"doc(The Dgnfile through which this schema info was found.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_GetSchemaKey =R"doc(Get the schema key)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetVersionMinor =R"doc(Set minor version number

Parameter ``versionMinor``:
    Minor version number.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetVersionMajor =R"doc(Set major version number

Parameter ``versionMajor``:
    Major version number.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetElementCheckSum =R"doc(Set CheckSum value

Parameter ``checkSum``:
    Used to determine if schemas with same name and version are really
    the same.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_GetElementCheckSum =R"doc(Get the checksum of the schema stored on the element)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetStoredSchema =R"doc(Set Stored value

Parameter ``isStoredSchema``:
    Used to determine if schemas was stored in the design file.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_IsStoredSchema =R"doc(Test whether the schema is persisted to the file.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetLocation =R"doc(Set location

Parameter ``location``:
    Specifies the filename that held the schema)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_GetLocation =R"doc(Get the location of the schema if external.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetProviderName =R"doc(Set provider name

Parameter ``providerName``:
    Specifies the provider name that handles data from the schema
    (ECXAttributes/ECXData).)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_GetProviderName =R"doc(Get the provider associated with this schema)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_SetSchemaName =R"doc(Set schema name

Parameter ``schemaName``:
    Schema name.)doc";

static const char * __doc_Bentley_DgnPlatform_SchemaInfo_GetSchemaName =R"doc(Get the schema name)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnECProviders(py::module_& m)
    {
    //===================================================================================
    // Global constants
    m.attr("DgnECProviderId_ECXAttributes") = DgnECProviderId_ECXAttributes;
    m.attr("DgnECProviderId_ECXData") = DgnECProviderId_ECXData;
    m.attr("DgnECProviderId_Element") = DgnECProviderId_Element;
    m.attr("DgnECProviderId_Model") = DgnECProviderId_Model;
    m.attr("DgnECProviderId_File") = DgnECProviderId_File;
    m.attr("DgnECProviderId_FileExtrinsic") = DgnECProviderId_FileExtrinsic;
    m.attr("DgnECProviderId_ModelExtrinsic") = DgnECProviderId_ModelExtrinsic;
    m.attr("DgnECProviderId_Link") = DgnECProviderId_Link;
    m.attr("DgnECProviderId_View") = DgnECProviderId_View;
    m.attr("DgnECProviderId_Attachment") = DgnECProviderId_Attachment;
    m.attr("DgnECProviderId_Level") = DgnECProviderId_Level;
    m.attr("DgnECProviderId_Invalid") = DgnECProviderId_Invalid;

    //===================================================================================
    // enum ECSchemaPersistence
    py::enum_< ECSchemaPersistence>(m, "ECSchemaPersistence", py::arithmetic())
        .value("eECSCHEMAPERSISTENCE_Unknown", ECSCHEMAPERSISTENCE_Unknown)
        .value("eECSCHEMAPERSISTENCE_Stored", ECSCHEMAPERSISTENCE_Stored)
        .value("eECSCHEMAPERSISTENCE_External", ECSCHEMAPERSISTENCE_External)
        .value("eECSCHEMAPERSISTENCE_All", ECSCHEMAPERSISTENCE_All)
        .export_values();

    //===================================================================================
    // struct SchemaInfo
    py::class_< SchemaInfo> c1(m, "SchemaInfo");
    py::bind_vector<bvector<SchemaInfo>>(m, "SchemaInfoArray", py::module_local(false));

    c1.def(py::init<ECN::SchemaKeyCR, DgnFileR, WCharCP, WCharCP, UInt32, bool>(), 
           "schemaKey"_a, "dgnFile"_a, "providerName"_a = L"", "location"_a = L"", "checkSum"_a = 0, "storedSchema"_a = false);

    c1.def(py::self == py::self);
    c1.def(py::self < py::self);

    c1.def_property("SchemaName", &SchemaInfo::GetSchemaName, &SchemaInfo::SetSchemaName);
    c1.def("GetSchemaName", &SchemaInfo::GetSchemaName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SchemaInfo, GetSchemaName));
    c1.def("SetSchemaName", &SchemaInfo::SetSchemaName, "schemaName"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetSchemaName));

    c1.def_property("ProviderName", &SchemaInfo::GetProviderName, &SchemaInfo::SetProviderName);
    c1.def("GetProviderName", &SchemaInfo::GetProviderName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SchemaInfo, GetProviderName));
    c1.def("SetProviderName", &SchemaInfo::SetProviderName, "providerName"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetProviderName));

    c1.def_property("Location", &SchemaInfo::GetLocation, &SchemaInfo::SetLocation);
    c1.def("GetLocation", &SchemaInfo::GetLocation, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SchemaInfo, GetLocation));
    c1.def("SetLocation", &SchemaInfo::SetLocation, "location"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetLocation));

    c1.def_property("StoredSchema", &SchemaInfo::IsStoredSchema, &SchemaInfo::SetStoredSchema);
    c1.def("IsStoredSchema", &SchemaInfo::IsStoredSchema, DOC(Bentley, DgnPlatform, SchemaInfo, IsStoredSchema));
    c1.def("SetStoredSchema", &SchemaInfo::SetStoredSchema, "isStoredSchema"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetStoredSchema));

    c1.def_property("ElementCheckSum", &SchemaInfo::GetElementCheckSum, &SchemaInfo::SetElementCheckSum);
    c1.def("GetElementCheckSum", &SchemaInfo::GetElementCheckSum, DOC(Bentley, DgnPlatform, SchemaInfo, GetElementCheckSum));
    c1.def("SetElementCheckSum", &SchemaInfo::SetElementCheckSum, "checkSum"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetElementCheckSum));

    c1.def("SetVersionMajor", &SchemaInfo::SetVersionMajor, "versionMajor"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetVersionMajor));
    c1.def("SetVersionMinor", &SchemaInfo::SetVersionMinor, "versionMinor"_a, DOC(Bentley, DgnPlatform, SchemaInfo, SetVersionMinor));
    
    c1.def_property_readonly("SchemaKey", &SchemaInfo::GetSchemaKeyR);
    c1.def("GetSchemaKey", &SchemaInfo::GetSchemaKeyR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SchemaInfo, GetSchemaKey));
    
    c1.def_property_readonly("DgnFile", &SchemaInfo::GetDgnFile);
    c1.def("GetDgnFile", &SchemaInfo::GetDgnFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, SchemaInfo, GetDgnFile));
    
    //===================================================================================
    // enum SchemaImportStatus
    py::enum_< SchemaImportStatus>(m, "SchemaImportStatus", py::arithmetic())
        .value("eSCHEMAIMPORT_Success", SCHEMAIMPORT_Success)
        .value("eSCHEMAIMPORT_SchemaAlreadyStoredInFile", SCHEMAIMPORT_SchemaAlreadyStoredInFile)
        .value("eSCHEMAIMPORT_NotValidECSchemaXml", SCHEMAIMPORT_NotValidECSchemaXml)
        .value("eSCHEMAIMPORT_FailedToWriteElement", SCHEMAIMPORT_FailedToWriteElement)
        .value("eSCHEMAIMPORT_FailedToSerializeAsXml", SCHEMAIMPORT_FailedToSerializeAsXml)
        .value("eSCHEMAIMPORT_ProviderDoesNotSupportImport", SCHEMAIMPORT_ProviderDoesNotSupportImport)
        .value("eSCHEMAIMPORT_ProviderNotFound", SCHEMAIMPORT_ProviderNotFound)
        .value("eSCHEMAIMPORT_FailedToDeserializeXmlFile", SCHEMAIMPORT_FailedToDeserializeXmlFile)
        .value("eSCHEMAIMPORT_InvalidUserDefinedSchema", SCHEMAIMPORT_InvalidUserDefinedSchema)
        .export_values();        

    //===================================================================================
    // enum SchemaUpdateStatus
    py::enum_< SchemaUpdateStatus>(m, "SchemaUpdateStatus")
        .value("eSCHEMAUPDATE_Success", SCHEMAUPDATE_Success)
        .value("eSCHEMAUPDATE_SchemaNotFound", SCHEMAUPDATE_SchemaNotFound)
        .value("eSCHEMAUPDATE_NotValidECSchemaXml", SCHEMAUPDATE_NotValidECSchemaXml)
        .value("eSCHEMAUPDATE_FailedToWriteElement", SCHEMAUPDATE_FailedToWriteElement)
        .value("eSCHEMAUPDATE_FailedToSerializeAsXml", SCHEMAUPDATE_FailedToSerializeAsXml)
        .value("eSCHEMAUPDATE_ProviderDoesNotSupportUpdate", SCHEMAUPDATE_ProviderDoesNotSupportUpdate)
        .value("eSCHEMAUPDATE_ProviderNotFound", SCHEMAUPDATE_ProviderNotFound)
        .value("eSCHEMAUPDATE_FailedToDeserializeXmlFile", SCHEMAUPDATE_FailedToDeserializeXmlFile)
        .value("eSCHEMAUPDATE_SchemaVersionMismatch", SCHEMAUPDATE_SchemaVersionMismatch)
        .value("eSCHEMAUPDATE_ProviderDoesNotSupportInstanceUpdate", SCHEMAUPDATE_ProviderDoesNotSupportInstanceUpdate)
        .value("eSCHEMAUPDATE_FailedToUpdateInstances", SCHEMAUPDATE_FailedToUpdateInstances)
        .value("eSCHEMAUPDATE_FailedToUpdateReferencingSchemas", SCHEMAUPDATE_FailedToUpdateReferencingSchemas)
        .export_values();        

    //===================================================================================
    // enum SchemaDeleteStatus
    py::enum_< SchemaDeleteStatus>(m, "SchemaDeleteStatus", py::arithmetic())
        .value("eSCHEMADELETE_Success", SCHEMADELETE_Success)
        .value("eSCHEMADELETE_SchemaNotFound", SCHEMADELETE_SchemaNotFound)
        .value("eSCHEMADELETE_ProviderNotFound", SCHEMADELETE_ProviderNotFound)
        .value("eSCHEMADELETE_ProviderDoesNotSupportDelete", SCHEMADELETE_ProviderDoesNotSupportDelete)
        .value("eSCHEMADELETE_SchemaHasStoredInstances", SCHEMADELETE_SchemaHasStoredInstances)
        .value("eSCHEMADELETE_SchemaIsReferenced", SCHEMADELETE_SchemaIsReferenced)
        .value("eSCHEMADELETE_FailedToDeleteSchemaElement", SCHEMADELETE_FailedToDeleteSchemaElement)
        .export_values();        

    //===================================================================================
    // enum DeleteDgnECInstanceStatus
    py::enum_< DeleteDgnECInstanceStatus>(m, "DeleteDgnECInstanceStatus", py::arithmetic())
        .value("eDELETEDGNECINSTANCE_Success", DELETEDGNECINSTANCE_Success)
        .value("eDELETEDGNECINSTANCE_FileReadOnly", DELETEDGNECINSTANCE_FileReadOnly)
        .value("eDELETEDGNECINSTANCE_ProviderDoesNotSupportDelete", DELETEDGNECINSTANCE_ProviderDoesNotSupportDelete)
        .value("eDELETEDGNECINSTANCE_UnableToParseInstanceId", DELETEDGNECINSTANCE_UnableToParseInstanceId)
        .value("eDELETEDGNECINSTANCE_InvalidProviderId", DELETEDGNECINSTANCE_InvalidProviderId)
        .value("eDELETEDGNECINSTANCE_InvalidOrDeletedElement", DELETEDGNECINSTANCE_InvalidOrDeletedElement)
        .value("eDELETEDGNECINSTANCE_UnableToLocateInstance", DELETEDGNECINSTANCE_UnableToLocateInstance)
        .value("eDELETEDGNECINSTANCE_SchedulingDeleteNotSupportedByProvider", DELETEDGNECINSTANCE_SchedulingDeleteNotSupportedByProvider)
        .value("eDELETEDGNECINSTANCE_Error", DELETEDGNECINSTANCE_Error)
        .export_values();        


    //===================================================================================
    // struct DgnECRelationshipInfo
    py::class_< DgnECRelationshipInfo> c5(m, "DgnECRelationshipInfo");
    py::bind_vector<bvector< DgnECRelationshipInfo>>(m, "DgnECRelationshipInfoArray", py::module_local(false));

    c5.def_property_readonly("RelationshipClass", &DgnECRelationshipInfo::GetRelationshipClass);
    c5.def("GetRelationshipClass", &DgnECRelationshipInfo::GetRelationshipClass, py::return_value_policy::reference_internal);

    c5.def("SupportsForward", &DgnECRelationshipInfo::SupportsForward);
    c5.def("SetSupportsForward", &DgnECRelationshipInfo::SetSupportsForward, "support"_a);

    c5.def("SupportsBackward", &DgnECRelationshipInfo::SupportsBackward);
    c5.def("SetSupportsBackward", &DgnECRelationshipInfo::SetSupportsBackward, "support"_a);

    //===================================================================================
    // struct RelationshipEntry
    py::class_< RelationshipEntry> c6(m, "RelationshipEntry");
    py::bind_vector<RelationshipEntryVector>(m, "RelationshipEntryArray", py::module_local(false));

    c6.def_readwrite("relationshipClassName", &RelationshipEntry::RelationshipClassName);
    c6.def_readwrite("relationshipSchemaName", &RelationshipEntry::RelationshipSchemaName);
    c6.def_readwrite("relatedInstanceDirection", &RelationshipEntry::RelatedInstanceDirection);
    c6.def_readwrite("relatedInstanceStrength", &RelationshipEntry::RelatedInstanceStrength);
    c6.def_readwrite("sourceClassName", &RelationshipEntry::SourceClassName);
    c6.def_readwrite("sourceSchemaName", &RelationshipEntry::SourceSchemaName);
    c6.def_readwrite("targetClassName", &RelationshipEntry::TargetClassName);
    c6.def_readwrite("targetSchemaName", &RelationshipEntry::TargetSchemaName);
    c6.def_readwrite("sourceInstanceId", &RelationshipEntry::SourceInstanceId);
    c6.def_readwrite("targetInstanceId", &RelationshipEntry::TargetInstanceId);
    c6.def_readwrite("sourceEH", &RelationshipEntry::SourceEH);
    c6.def_readwrite("targetEH", &RelationshipEntry::TargetEH);
    c6.def_readwrite("sourceElementId", &RelationshipEntry::SourceElementId);
    c6.def_readwrite("targetElementId", &RelationshipEntry::TargetElementId);
    c6.def_readwrite("sourceModelName", &RelationshipEntry::SourceModelName);
    c6.def_readwrite("targetModelName", &RelationshipEntry::TargetModelName);

    //===================================================================================
    //struct IDgnECProvider
    py::class_< IDgnECProvider
        , std::unique_ptr<IDgnECProvider, py::nodelete>        
        , ECN::IECProvider
    > c8(m, "IDgnECProvider");

    c8.def("FindECClassesOnElement", &IDgnECProvider::FindECClassesOnElement, "rootElement"_a, "classes"_a, DOC(Bentley, DgnPlatform, IDgnECProvider, FindECClassesOnElement));        

    }