/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\supplementalschema.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/SupplementalSchema.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SupplementalSchema(py::module_& m)
    {
    //===================================================================================
    // struct SupplementalSchemaMetaData
    py::class_< SupplementalSchemaMetaData, SupplementalSchemaMetaDataPtr> c1(m, "SupplementalSchemaMetaData");

    c1.def(py::init<WString, uint32_t, uint32_t, uint32_t, WString, bool>(),
           "schemaName"_a, "majorVersion"_a, "minorVersion"_a, "schemaPrecedence"_a, "schemaPurpose"_a, "isUserSpecific"_a);

    c1.def(py::init<IECInstanceCR>(), "schemaMetaDataCustomAttribute"_a);

    c1.def("IsSupplemental", &SupplementalSchemaMetaData::IsSupplemental, "schema"_a);
    c1.def("CreateCustomAttribute", &SupplementalSchemaMetaData::CreateCustomAttribute);
    
    c1.def_property("PrimarySchemaName", &SupplementalSchemaMetaData::GetPrimarySchemaName, &SupplementalSchemaMetaData::SetPrimarySchemaName);
    c1.def("GetPrimarySchemaName", &SupplementalSchemaMetaData::GetPrimarySchemaName, py::return_value_policy::reference_internal);
    c1.def("SetPrimarySchemaName", &SupplementalSchemaMetaData::SetPrimarySchemaName, "name"_a);
    
    c1.def_property("PrimarySchemaMajorVersion", &SupplementalSchemaMetaData::GetPrimarySchemaMajorVersion, &SupplementalSchemaMetaData::SetPrimarySchemaMajorVersion);
    c1.def("GetPrimarySchemaMajorVersion", &SupplementalSchemaMetaData::GetPrimarySchemaMajorVersion);
    c1.def("SetPrimarySchemaMajorVersion", &SupplementalSchemaMetaData::SetPrimarySchemaMajorVersion, "major"_a);
    
    c1.def_property("PrimarySchemaMinorVersion", &SupplementalSchemaMetaData::GetPrimarySchemaMinorVersion, &SupplementalSchemaMetaData::SetPrimarySchemaMinorVersion);
    c1.def("GetPrimarySchemaMinorVersion", &SupplementalSchemaMetaData::GetPrimarySchemaMinorVersion);
    c1.def("SetPrimarySchemaMinorVersion", &SupplementalSchemaMetaData::SetPrimarySchemaMinorVersion, "minor"_a);
    
    c1.def_property("SupplementalSchemaPrecedence", &SupplementalSchemaMetaData::GetSupplementalSchemaPrecedence, &SupplementalSchemaMetaData::SetSupplementalSchemaPrecedence);
    c1.def("GetSupplementalSchemaPrecedence", &SupplementalSchemaMetaData::GetSupplementalSchemaPrecedence);
    c1.def("SetSupplementalSchemaPrecedence", &SupplementalSchemaMetaData::SetSupplementalSchemaPrecedence, "precedence"_a);
    
    c1.def_property("SupplementalSchemaPurpose", &SupplementalSchemaMetaData::GetSupplementalSchemaPurpose, &SupplementalSchemaMetaData::SetSupplementalSchemaPurpose);
    c1.def("GetSupplementalSchemaPurpose", &SupplementalSchemaMetaData::GetSupplementalSchemaPurpose);
    c1.def("SetSupplementalSchemaPurpose", &SupplementalSchemaMetaData::SetSupplementalSchemaPurpose, "purpose"_a);
    
    c1.def_property("UserSpecific", &SupplementalSchemaMetaData::IsUserSpecific, &SupplementalSchemaMetaData::SetUserSpecific);
    c1.def("IsUserSpecific", &SupplementalSchemaMetaData::IsUserSpecific);
    c1.def("SetUserSpecific", &SupplementalSchemaMetaData::SetUserSpecific, "userSpecific"_a);
    
    c1.def("IsForPrimarySchema", &SupplementalSchemaMetaData::IsForPrimarySchema, "schemaName"_a, "majorVersion"_a, "minorVersion"_a, "matchType"_a);

    c1.def_property_readonly_static("CustomAttributeAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetCustomAttributeAccessor(); });
    c1.def_static("GetCustomAttributeAccessor", &SupplementalSchemaMetaData::GetCustomAttributeAccessor, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("CustomAttributeSchemaName", [] (py::object const&) { return SupplementalSchemaMetaData::GetCustomAttributeSchemaName(); });
    c1.def_static("GetCustomAttributeSchemaName", &SupplementalSchemaMetaData::GetCustomAttributeSchemaName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("PrimarySchemaNamePropertyAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetPrimarySchemaNamePropertyAccessor(); });
    c1.def_static("GetPrimarySchemaNamePropertyAccessor", &SupplementalSchemaMetaData::GetPrimarySchemaNamePropertyAccessor, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("PrimarySchemaMajorVersionPropertyAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetPrimarySchemaMajorVersionPropertyAccessor(); });
    c1.def_static("GetPrimarySchemaMajorVersionPropertyAccessor", &SupplementalSchemaMetaData::GetPrimarySchemaMajorVersionPropertyAccessor, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("PrimarySchemaMinorVersionPropertyAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetPrimarySchemaMinorVersionPropertyAccessor(); });
    c1.def_static("GetPrimarySchemaMinorVersionPropertyAccessor", &SupplementalSchemaMetaData::GetPrimarySchemaMinorVersionPropertyAccessor, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("PrecedencePropertyAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetPrecedencePropertyAccessor(); });
    c1.def_static("GetPrecedencePropertyAccessor", &SupplementalSchemaMetaData::GetPrecedencePropertyAccessor, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("PurposePropertyAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetPurposePropertyAccessor(); });
    c1.def_static("GetPurposePropertyAccessor", &SupplementalSchemaMetaData::GetPurposePropertyAccessor, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("IsUserSpecificPropertyAccessor", [] (py::object const&) { return SupplementalSchemaMetaData::GetIsUserSpecificPropertyAccessor(); });
    c1.def_static("GetIsUserSpecificPropertyAccessor", &SupplementalSchemaMetaData::GetIsUserSpecificPropertyAccessor, py::return_value_policy::reference);

    c1.def_static("TryGetFromSchema", [] (ECSchemaCR supplementalSchema)
                  {
                  SupplementalSchemaMetaDataPtr supplementalSchemaMetadata;
                  auto retVal = SupplementalSchemaMetaData::TryGetFromSchema(supplementalSchemaMetadata, supplementalSchema);
                  return py::make_tuple(retVal, supplementalSchemaMetadata);
                  }, "supplementalSchema"_a);

    c1.def_static("SetMetadata", &SupplementalSchemaMetaData::SetMetadata, "supplementalSchema"_a, "supplementalSchemaMetadata"_a);    

    //===================================================================================
    // struct SupplementedSchemaBuilder
    py::class_< SupplementedSchemaBuilder> c2(m, "SupplementedSchemaBuilder");

    if (true)
        {
        //===================================================================================
        // enum SchemaPrecedence
        py::enum_< SupplementedSchemaBuilder::SchemaPrecedence>(c2, "SchemaPrecedence", py::arithmetic())
            .value("eSCHEMA_PRECEDENCE_Lower", SupplementedSchemaBuilder::SCHEMA_PRECEDENCE_Lower)
            .value("eSCHEMA_PRECEDENCE_Equal", SupplementedSchemaBuilder::SCHEMA_PRECEDENCE_Equal)
            .value("eSCHEMA_PRECEDENCE_Greater", SupplementedSchemaBuilder::SCHEMA_PRECEDENCE_Greater)
            .export_values();
        }

    c2.def(py::init<>());
    //c2.def_property_readonly("PrimarySchemaName", &SupplementedSchemaBuilder::GetPrimarySchemaName);

    c2.def("UpdateSchema",
           py::overload_cast<ECSchemaR, bvector<ECSchemaP>&>(&SupplementedSchemaBuilder::UpdateSchema),
           "primarySchema"_a, "supplementalSchemaList"_a);

    c2.def("UpdateSchema",
           py::overload_cast<ECSchemaR, bvector<ECSchemaP>&, WCharCP>(&SupplementedSchemaBuilder::UpdateSchema),
           "primarySchema"_a, "supplementalSchemaList"_a, "locale"_a);

    //===================================================================================
    // struct SupplementalSchemaInfo
    py::class_< SupplementalSchemaInfo, SupplementalSchemaInfoPtr> c3(m, "SupplementalSchemaInfo");

    c3.def(py::init<WStringCR, SchemaNamePurposeMap&>(), "primarySchemaFullName"_a, "schemaFullNameToPurposeMapping"_a);
    
    c3.def_property_readonly("PrimarySchemaFullName", &SupplementalSchemaInfo::GetPrimarySchemaFullName);
    c3.def("GetPrimarySchemaFullName", &SupplementalSchemaInfo::GetPrimarySchemaFullName, py::return_value_policy::reference_internal);
    
    c3.def("GetSupplementalSchemaNames", &SupplementalSchemaInfo::GetSupplementalSchemaNames, "supplementalSchemaNames"_a);
    c3.def("GetPurposeOfSupplementalSchema", &SupplementalSchemaInfo::GetPurposeOfSupplementalSchema, "fullSchemaName"_a, py::return_value_policy::reference_internal);
    c3.def("GetSupplementalSchemasWithPurpose", &SupplementalSchemaInfo::GetSupplementalSchemasWithPurpose, "supplementalSchemaNames"_a, "purpose"_a);
    c3.def("HasSameSupplementalSchemasForPurpose", &SupplementalSchemaInfo::HasSameSupplementalSchemasForPurpose, "secondSchema"_a, "purpose"_a);
    }