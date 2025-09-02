/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecschema.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECSchema.h>
#include <ObjIdl.h>

//=======================================================================================
// Publicist class for IECSchemaLocater
// @bsiclass                                                                   02/23
//=======================================================================================
struct IECSchemaLocaterPub : IECSchemaLocater
    {
    public:
        using IECSchemaLocater::_LocateSchema;
    };

//=======================================================================================
// Trampoline class for IECSchemaLocater
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyECSchemaLocater : IECSchemaLocater
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ECSchemaPtr _LocateSchema(SchemaKeyR key, SchemaMatchType matchType, ECSchemaReadContextR schemaContext) override
            { PYBIND11_OVERRIDE_PURE(ECSchemaPtr, IECSchemaLocater, _LocateSchema, nullptr, key, matchType, schemaContext); }
    };

DEFINE_NODELETE_HOLDER_TYPE(IECCustomAttributeContainer);
DEFINE_NODELETE_HOLDER_TYPE(ECProperty);
DEFINE_NODELETE_HOLDER_TYPE(PrimitiveECProperty);
DEFINE_NODELETE_HOLDER_TYPE(StructECProperty);
DEFINE_NODELETE_HOLDER_TYPE(ArrayECProperty);
DEFINE_NODELETE_HOLDER_TYPE(ECClass);
DEFINE_NODELETE_HOLDER_TYPE(ECRelationshipConstraint);

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECSchema(py::module_& m)
    {
    //===================================================================================
    // struct WStringKey
    py::class_< WStringKey> c1(m, "WStringKey");
    py::bind_vector<bvector<WStringKey>>(m, "WStringKeyArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<WCharCP>(), "key"_a);
    c1.def(py::init<WStringCR>(), "key"_a);
    c1.def(py::self < py::self);
    c1.def(py::self == py::self);
    c1.def_property_readonly("Key", &WStringKey::GetKey);
    c1.def("GetKey", &WStringKey::GetKey, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct ECNameValidation
    py::class_< ECNameValidation> c2(m, "ECNameValidation");

    if (true)
        {
        //===================================================================================
        // enum ValidationResult
        py::enum_< ECNameValidation::ValidationResult>(c2, "ValidationResult", py::arithmetic())
            .value("eRESULT_Valid", ECNameValidation::RESULT_Valid)
            .value("eRESULT_NullOrEmpty", ECNameValidation::RESULT_NullOrEmpty)
            .value("eRESULT_BeginsWithDigit", ECNameValidation::RESULT_BeginsWithDigit)
            .value("eRESULT_IncludesInvalidCharacters", ECNameValidation::RESULT_IncludesInvalidCharacters)
            .export_values();
        }

    c2.def_static("EncodeToValidName", py::overload_cast<WStringR, WStringCR>(&ECNameValidation::EncodeToValidName), "encoded"_a, "name"_a);
    c2.def_static("DecodeFromValidName", &ECNameValidation::DecodeFromValidName, "decoded"_a, "name"_a);
    c2.def_static("Validate", &ECNameValidation::Validate, "name"_a);
    c2.def_static("IsValidName", &ECNameValidation::IsValidName, "name"_a);
    c2.def_static("IsValidAlphaNumericCharacter", &ECNameValidation::IsValidAlphaNumericCharacter, "char"_a);

    //===================================================================================
    // struct ECTypeDescriptor
    py::class_< ECTypeDescriptor> c3(m, "ECTypeDescriptor");

    c3.def_static("CreatePrimitiveTypeDescriptor", &ECTypeDescriptor::CreatePrimitiveTypeDescriptor, "primitiveType"_a);
    c3.def_static("CreatePrimitiveArrayTypeDescriptor", &ECTypeDescriptor::CreatePrimitiveArrayTypeDescriptor, "primitiveType"_a);
    c3.def_static("CreateStructArrayTypeDescriptor", &ECTypeDescriptor::CreateStructArrayTypeDescriptor);
    c3.def_static("CreateStructTypeDescriptor", &ECTypeDescriptor::CreateStructTypeDescriptor);
    c3.def_property_readonly("TypeKind", &ECTypeDescriptor::GetTypeKind);
    c3.def("GetTypeKind", &ECTypeDescriptor::GetTypeKind);
    
    c3.def_property_readonly("ArrayKind", &ECTypeDescriptor::GetArrayKind);
    c3.def("GetArrayKind", &ECTypeDescriptor::GetArrayKind);
    
    c3.def("IsPrimitive", &ECTypeDescriptor::IsPrimitive);    
    c3.def("IsStruct", &ECTypeDescriptor::IsStruct);    
    c3.def("IsArray", &ECTypeDescriptor::IsArray);    
    c3.def("IsPrimitiveArray", &ECTypeDescriptor::IsPrimitiveArray);    
    c3.def("IsStructArray", &ECTypeDescriptor::IsStructArray);
    
    c3.def_property_readonly("PrimitiveType", &ECTypeDescriptor::GetPrimitiveType);
    c3.def("GetPrimitiveType", &ECTypeDescriptor::GetPrimitiveType);

    //===================================================================================
    // struct IECCustomAttributeContainer
    py::class_< IECCustomAttributeContainer, IECCustomAttributeContainerPtr> c4(m, "IECCustomAttributeContainer");

    c4.def("IsDefined",
           py::overload_cast<WStringCR, WStringCR>(&IECCustomAttributeContainer::IsDefined, py::const_),
           "schemaName"_a, "className"_a);

    c4.def("IsDefined",
           py::overload_cast<ECClassCR>(&IECCustomAttributeContainer::IsDefined, py::const_),
           "classDefiniton"_a);

    c4.def("GetCustomAttribute",
           py::overload_cast<WStringCR, WStringCR>(&IECCustomAttributeContainer::GetCustomAttribute, py::const_),
           "schemaName"_a, "className"_a);

    c4.def("GetCustomAttribute",
           py::overload_cast<ECClassCR>(&IECCustomAttributeContainer::GetCustomAttribute, py::const_),
           "classDefiniton"_a);

    c4.def("GetCustomAttributeLocal",
           py::overload_cast<WStringCR, WStringCR>(&IECCustomAttributeContainer::GetCustomAttributeLocal, py::const_),
           "schemaName"_a, "className"_a);

    c4.def("GetCustomAttributeLocal",
           py::overload_cast<ECClassCR>(&IECCustomAttributeContainer::GetCustomAttributeLocal, py::const_),
           "classDefiniton"_a);

    c4.def("GetPrimaryCustomAttribute",
           py::overload_cast<WStringCR, WStringCR>(&IECCustomAttributeContainer::GetPrimaryCustomAttribute, py::const_),
           "schemaName"_a, "className"_a);

    c4.def("GetPrimaryCustomAttribute",
           py::overload_cast<ECClassCR>(&IECCustomAttributeContainer::GetPrimaryCustomAttribute, py::const_),
           "classDefiniton"_a);

    c4.def("GetCustomAttributes", &IECCustomAttributeContainer::GetCustomAttributes, "includeBase"_a);
    c4.def("GetPrimaryCustomAttributes", &IECCustomAttributeContainer::GetPrimaryCustomAttributes, "includeBase"_a);
    c4.def("SetCustomAttribute", &IECCustomAttributeContainer::SetCustomAttribute, "customAtributeInstance"_a);

    c4.def("RemoveCustomAttribute",
           py::overload_cast<WStringCR, WStringCR>(&IECCustomAttributeContainer::RemoveCustomAttribute),
           "schemaName"_a, "className"_a);

    c4.def("RemoveCustomAttribute",
           py::overload_cast<ECClassCR>(&IECCustomAttributeContainer::RemoveCustomAttribute),
           "classDefiniton"_a);

    //===================================================================================
    // struct ECCustomAttributeInstanceIterable
    py::class_< ECCustomAttributeInstanceIterable> c5(m, "ECCustomAttributeInstanceIterable");

    c5.def("__iter__", [] (ECCustomAttributeInstanceIterable& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct IECTypeAdapterContext
    py::class_< IECTypeAdapterContext, IECTypeAdapterContextPtr> c6(m, "IECTypeAdapterContext");

    //===================================================================================
    // struct IECTypeAdapter
    py::class_< IECTypeAdapter, RefCountedPtr<IECTypeAdapter> > c7(m, "IECTypeAdapter");

    c7.def("CanConvertToString", &IECTypeAdapter::CanConvertToString, "context"_a);
    c7.def("CanConvertFromString", &IECTypeAdapter::CanConvertFromString, "context"_a);
    c7.def("ConvertToString", &IECTypeAdapter::ConvertToString, "str"_a, "value"_a, "context"_a, "formatter"_a = nullptr);
    c7.def("ConvertFromString", &IECTypeAdapter::ConvertFromString, "value"_a, "str"_a, "context"_a);
    c7.def("RequiresExpressionTypeConversion", &IECTypeAdapter::RequiresExpressionTypeConversion, "evalOptions"_a = EVALOPT_Legacy);
    c7.def("ConvertToExpressionType", &IECTypeAdapter::ConvertToExpressionType, "value"_a, "context"_a);
    c7.def("ConvertFromExpressionType", &IECTypeAdapter::ConvertFromExpressionType, "value"_a, "context"_a);
    c7.def("CreateDefaultFormatter", &IECTypeAdapter::CreateDefaultFormatter, "includeAllValues"_a, "forDwg"_a = false);
    c7.def("HasStandardValues", &IECTypeAdapter::HasStandardValues);
    c7.def("IsStruct", &IECTypeAdapter::IsStruct);
    c7.def("IsTreatedAsString", &IECTypeAdapter::IsTreatedAsString);
    c7.def("CondenseFormatterForSerialization", &IECTypeAdapter::CondenseFormatterForSerialization, "formatter"_a);
    c7.def("PopulateDefaultFormatterProperties", &IECTypeAdapter::PopulateDefaultFormatterProperties, "formatter"_a);
    c7.def("SupportsUnits", &IECTypeAdapter::SupportsUnits);
    c7.def("GetUnits", &IECTypeAdapter::GetUnits, "unit"_a, "context"_a);

    //===================================================================================
    // struct ECProperty
    py::class_< ECProperty, ECPropertyPtr, IECCustomAttributeContainer> c8(m, "ECProperty");

    c8.def("IsCalculated", &ECProperty::IsCalculated);
    c8.def("SetCalculatedPropertySpecification", &ECProperty::SetCalculatedPropertySpecification, "expressionAttribute"_a);
    
    c8.def_property_readonly("Id", &ECProperty::GetId);
    c8.def("GetId", &ECProperty::GetId);
    
    c8.def_property_readonly("Class", &ECProperty::GetClass);
    c8.def("GetClass", &ECProperty::GetClass, py::return_value_policy::reference_internal);
    
    c8.def_property_readonly("Name", &ECProperty::GetName);
    c8.def("GetName", &ECProperty::GetName, py::return_value_policy::reference_internal);
    
    c8.def_property_readonly("IsDisplayLabelDefined", &ECProperty::GetIsDisplayLabelDefined);
    c8.def("GetIsDisplayLabelDefined", &ECProperty::GetIsDisplayLabelDefined);
    
    c8.def_property_readonly("IsStruct", &ECProperty::GetIsStruct);
    c8.def("GetIsStruct", &ECProperty::GetIsStruct);
    
    c8.def_property_readonly("IsArray", &ECProperty::GetIsArray);
    c8.def("GetIsArray", &ECProperty::GetIsArray);
    
    c8.def_property_readonly("IsPrimitive", &ECProperty::GetIsPrimitive);
    c8.def("GetIsPrimitive", &ECProperty::GetIsPrimitive);

    c8.def_property("TypeName", &ECProperty::GetTypeName, &ECProperty::SetTypeName);
    c8.def("GetTypeName", &ECProperty::GetTypeName);
    c8.def("SetTypeName", &ECProperty::SetTypeName, "typeName"_a);
    
    c8.def_property("Description", &ECProperty::GetDescription, &ECProperty::SetDescription);
    c8.def("GetDescription", &ECProperty::GetDescription, py::return_value_policy::reference_internal);
    c8.def("SetDescription", &ECProperty::SetDescription, "description"_a);
    
    c8.def_property_readonly("InvariantDescription", &ECProperty::GetInvariantDescription);
    c8.def("GetInvariantDescription", &ECProperty::GetInvariantDescription, py::return_value_policy::reference_internal);
    
    c8.def_property("DisplayLabel", &ECProperty::GetDisplayLabel, &ECProperty::SetDisplayLabel);
    c8.def("GetDisplayLabel", &ECProperty::GetDisplayLabel, py::return_value_policy::reference_internal);
    c8.def("SetDisplayLabel", &ECProperty::SetDisplayLabel, "label"_a);
    
    c8.def_property_readonly("InvariantDisplayLabel", &ECProperty::GetInvariantDisplayLabel);
    c8.def("GetInvariantDisplayLabel", &ECProperty::GetInvariantDisplayLabel, py::return_value_policy::reference_internal);
    
    c8.def_property("IsReadOnly", &ECProperty::GetIsReadOnly, py::overload_cast<bool>(&ECProperty::SetIsReadOnly));
    c8.def("GetIsReadOnly", &ECProperty::GetIsReadOnly);
    c8.def("SetIsReadOnly", py::overload_cast<bool>(&ECProperty::SetIsReadOnly), "readOnly"_a);
    
    c8.def_property("BaseProperty", &ECProperty::GetBaseProperty, &ECProperty::SetBaseProperty);
    c8.def("GetBaseProperty", &ECProperty::GetBaseProperty, py::return_value_policy::reference_internal);
    c8.def("SetBaseProperty", &ECProperty::SetBaseProperty, "prop"_a);
    
    c8.def("SetIsReadOnly", py::overload_cast<WCharCP>(&ECProperty::SetIsReadOnly), "isReadOnly"_a);
    c8.def("AsPrimitiveProperty", [] (ECProperty& self) { return PrimitiveECPropertyPtr(self.GetAsPrimitivePropertyP()); });
    c8.def("AsArrayProperty", [] (ECProperty& self) { return ArrayECPropertyPtr(self.GetAsArrayPropertyP()); });
    c8.def("AsStructProperty", [] (ECProperty& self) { return StructECPropertyPtr(self.GetAsStructPropertyP()); });

    //===================================================================================
    // struct PrimitiveECProperty
    py::class_< PrimitiveECProperty, PrimitiveECPropertyPtr, ECProperty> c9(m, "PrimitiveECProperty");

    c9.def_property("Type", &PrimitiveECProperty::GetType, &PrimitiveECProperty::SetType);
    c9.def("GetType", &PrimitiveECProperty::GetType);
    c9.def("SetType", &PrimitiveECProperty::SetType, "type"_a);

    //===================================================================================
    // struct StructECProperty
    py::class_< ECN::StructECProperty, StructECPropertyPtr, ECProperty> c10(m, "StructECProperty");

    c10.def_property("Type", &ECN::StructECProperty::GetType, &ECN::StructECProperty::SetType);
    c10.def("GetType", &ECN::StructECProperty::GetType);
    c10.def("SetType", &ECN::StructECProperty::SetType, "type"_a);

    //===================================================================================
    // struct ArrayECProperty
    py::class_< ECN::ArrayECProperty, ArrayECPropertyPtr, ECProperty> c11(m, "ArrayECProperty");

    c11.def_property_readonly("Kind", &ECN::ArrayECProperty::GetKind);
    c11.def("GetKind", &ECN::ArrayECProperty::GetKind);

    c11.def_property("PrimitiveElementType", &ECN::ArrayECProperty::GetPrimitiveElementType, &ECN::ArrayECProperty::SetPrimitiveElementType);
    c11.def("GetPrimitiveElementType", &ECN::ArrayECProperty::GetPrimitiveElementType);
    c11.def("SetPrimitiveElementType", &ECN::ArrayECProperty::SetPrimitiveElementType, "type"_a);
    
    c11.def_property("StructElementType", &ECN::ArrayECProperty::GetStructElementType, &ECN::ArrayECProperty::SetStructElementType);
    c11.def("GetStructElementType", &ECN::ArrayECProperty::GetStructElementType);
    c11.def("SetStructElementType", &ECN::ArrayECProperty::SetStructElementType, "type"_a);
    
    c11.def_property("MinOccurs", &ECN::ArrayECProperty::GetMinOccurs, py::overload_cast<uint32_t>(&ECN::ArrayECProperty::SetMinOccurs));
    c11.def("GetMinOccurs", &ECN::ArrayECProperty::GetMinOccurs);
    c11.def("SetMinOccurs", py::overload_cast<uint32_t>(&ECN::ArrayECProperty::SetMinOccurs), "minOccurs"_a);
    
    c11.def_property("MaxOccurs", &ECN::ArrayECProperty::GetMaxOccurs, py::overload_cast<uint32_t>(&ECN::ArrayECProperty::SetMaxOccurs));
    c11.def("GetMaxOccurs", &ECN::ArrayECProperty::GetMaxOccurs);
    c11.def("SetMaxOccurs", py::overload_cast<uint32_t>(&ECN::ArrayECProperty::SetMaxOccurs), "maxOccurs"_a);

    //===================================================================================
    // struct ECPropertyIterable
    py::class_< ECPropertyIterable> c12(m, "ECPropertyIterable");

    c12.def("__iter__", [] (ECPropertyIterable& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    c12.def("FindByDisplayLabel", [] (ECPropertyIterable const& self, WCharCP label)
            { 
            return ECPropertyPtr(const_cast<ECPropertyP>(self.FindByDisplayLabel(label))); 
            }, "label"_a);

    //===================================================================================
    // struct ECClass
    py::class_< ECClass, ECClassPtr, IECCustomAttributeContainer> c13(m, "ECClass");
    bind_PointerVector<ECN::ECClassCP>(m, "ECClassCPArray", py::module_local(false));
    bind_PointerVector<ECN::ECClassP>(m, "ECClassPArray", py::module_local(false));

    c13.def_property_readonly("Id", &ECClass::GetId);
    c13.def("GetId", &ECClass::GetId);
    
    c13.def_property_readonly("DefaultStandaloneEnabler", &ECClass::GetDefaultStandaloneEnabler);
    c13.def("GetDefaultStandaloneEnabler", &ECClass::GetDefaultStandaloneEnabler, py::return_value_policy::reference_internal);
    
    c13.def_property_readonly("RelationshipClass", &ECClass::GetRelationshipClassP);
    c13.def("GetRelationshipClass", &ECClass::GetRelationshipClassP, py::return_value_policy::reference_internal);
    
    c13.def_property_readonly("Schema", &ECClass::GetSchema);
    c13.def("GetSchema", &ECClass::GetSchema, py::return_value_policy::reference_internal);
    
    c13.def_property_readonly("Name", &ECClass::GetName);
    c13.def("GetName", &ECClass::GetName, py::return_value_policy::reference_internal);
    
    c13.def_property_readonly("FullName", &ECClass::GetFullName);
    c13.def("GetFullName", &ECClass::GetFullName, py::return_value_policy::reference_internal);
    
    c13.def_property_readonly("IsDisplayLabelDefined", &ECClass::GetIsDisplayLabelDefined);
    c13.def("GetIsDisplayLabelDefined", &ECClass::GetIsDisplayLabelDefined);
    
    c13.def_property_readonly("Properties", py::overload_cast<>(&ECClass::GetProperties, py::const_));
    c13.def("GetProperties", py::overload_cast<>(&ECClass::GetProperties, py::const_), py::return_value_policy::reference_internal);
    
    c13.def("GetPropertyCount", &ECClass::GetPropertyCount, "includeBaseProperties"_a = true);
    
    c13.def_property_readonly("BaseClasses", &ECClass::GetBaseClasses);
    c13.def("GetBaseClasses", &ECClass::GetBaseClasses, py::return_value_policy::reference_internal);
    
    c13.def_property_readonly("DerivedClasses", &ECClass::GetDerivedClasses);
    c13.def("GetDerivedClasses", &ECClass::GetDerivedClasses, py::return_value_policy::reference_internal);

    c13.def_property("Description", &ECClass::GetDescription, &ECClass::SetDescription);
    c13.def("GetDescription", &ECClass::GetDescription, py::return_value_policy::reference_internal);
    c13.def("SetDescription", &ECClass::SetDescription, "description"_a);
    
    c13.def_property_readonly("InvariantDescription", &ECClass::GetInvariantDescription);
    c13.def("GetInvariantDescription", &ECClass::GetInvariantDescription, py::return_value_policy::reference_internal);
    
    c13.def_property("DisplayLabel", &ECClass::GetDisplayLabel, &ECClass::SetDisplayLabel);
    c13.def("GetDisplayLabel", &ECClass::GetDisplayLabel, py::return_value_policy::reference_internal);
    c13.def("SetDisplayLabel", &ECClass::SetDisplayLabel, "label"_a);
    
    c13.def_property_readonly("InvariantDisplayLabel", &ECClass::GetInvariantDisplayLabel);
    c13.def("GetInvariantDisplayLabel", &ECClass::GetInvariantDisplayLabel, py::return_value_policy::reference_internal);
    
    c13.def("GetProperties", py::overload_cast<bool>(&ECClass::GetProperties, py::const_), "includeBaseProperties"_a);

    c13.def("SetIsStruct", py::overload_cast<WCharCP>(&ECClass::SetIsStruct), "isStruct"_a);
    
    c13.def_property("IsStruct", &ECClass::GetIsStruct, py::overload_cast<bool>(&ECClass::SetIsStruct));
    c13.def("GetIsStruct", &ECClass::GetIsStruct);
    c13.def("SetIsStruct", py::overload_cast<bool>(&ECClass::SetIsStruct), "val"_a);

    c13.def("SetIsCustomAttributeClass", py::overload_cast<WCharCP>(&ECClass::SetIsCustomAttributeClass), "isCustomAttribute"_a);
    
    c13.def_property("IsCustomAttributeClass", &ECClass::GetIsCustomAttributeClass, py::overload_cast<bool>(&ECClass::SetIsCustomAttributeClass));
    c13.def("GetIsCustomAttributeClass", &ECClass::GetIsCustomAttributeClass);
    c13.def("SetIsCustomAttributeClass", py::overload_cast<bool>(&ECClass::SetIsCustomAttributeClass), "val"_a);

    c13.def("SetIsDomainClass", py::overload_cast<WCharCP>(&ECClass::SetIsDomainClass), "isDomainClass"_a);
    
    c13.def_property("IsDomainClass", &ECClass::GetIsDomainClass, py::overload_cast<bool>(&ECClass::SetIsDomainClass));
    c13.def("GetIsDomainClass", &ECClass::GetIsDomainClass);
    c13.def("SetIsDomainClass", py::overload_cast<bool>(&ECClass::SetIsDomainClass), "val"_a);

    c13.def("SetIsFinal", py::overload_cast<WCharCP>(&ECClass::SetIsFinal), "isFinal"_a);
    
    c13.def_property("IsFinal", &ECClass::GetIsFinal, py::overload_cast<bool>(&ECClass::SetIsFinal));
    c13.def("GetIsFinal", &ECClass::GetIsFinal);
    c13.def("SetIsFinal", py::overload_cast<bool>(&ECClass::SetIsFinal), "val"_a);

    c13.def("AddBaseClass", &ECClass::AddBaseClass, "baseClass"_a, py::keep_alive<1, 2>());    
    c13.def("HasBaseClasses", &ECClass::HasBaseClasses);    
    c13.def("RemoveBaseClass", &ECClass::RemoveBaseClass, "baseClass"_a);

    c13.def("Is", py::overload_cast<ECClassCP>(&ECClass::Is, py::const_), "targetClass"_a);
    c13.def("Is", py::overload_cast<WCharCP>(&ECClass::Is, py::const_), "name"_a);
    c13.def("Is", py::overload_cast<WCharCP, WCharCP>(&ECClass::Is, py::const_), "schemaName"_a, "className"_a);

    c13.def("CreatePrimitiveProperty", [] (ECClass& self, WStringCR name)
            {
            PrimitiveECPropertyP prop = nullptr;
            auto retVal = self.CreatePrimitiveProperty(prop, name);
            return py::make_tuple(retVal, PrimitiveECPropertyPtr(prop));
            }, "name"_a);

    c13.def("CreatePrimitiveProperty", [] (ECClass& self, WStringCR name, PrimitiveType primitiveType)
            {
            PrimitiveECPropertyP prop = nullptr;
            auto retVal = self.CreatePrimitiveProperty(prop, name, primitiveType);
            return py::make_tuple(retVal, PrimitiveECPropertyPtr(prop));
            }, "name"_a, "primitiveType"_a);

    c13.def("CreateStructProperty", [] (ECClass& self, WStringCR name)
            {
            StructECPropertyP prop = nullptr;
            auto retVal = self.CreateStructProperty(prop, name);
            return py::make_tuple(retVal, StructECPropertyPtr(prop));
            }, "name"_a);

    c13.def("CreateStructProperty", [] (ECClass& self, WStringCR name, ECClassCR structType)
            {
            StructECPropertyP prop = nullptr;
            auto retVal = self.CreateStructProperty(prop, name, structType);
            return py::make_tuple(retVal, StructECPropertyPtr(prop));
            }, "name"_a, "structType"_a);

    c13.def("CreateArrayProperty", [] (ECClass& self, WStringCR name)
            {
            ArrayECPropertyP prop = nullptr;
            auto retVal = self.CreateArrayProperty(prop, name);
            return py::make_tuple(retVal, ArrayECPropertyPtr(prop));
            }, "name"_a);

    c13.def("CreateArrayProperty", [] (ECClass& self, WStringCR name, PrimitiveType primitiveType)
            {
            ArrayECPropertyP prop = nullptr;
            auto retVal = self.CreateArrayProperty(prop, name, primitiveType);
            return py::make_tuple(retVal, ArrayECPropertyPtr(prop));
            }, "name"_a, "primitiveType"_a);

    c13.def("CreateArrayProperty", [] (ECClass& self, WStringCR name, ECClassCP structType)
            {
            ArrayECPropertyP prop = nullptr;
            auto retVal = self.CreateArrayProperty(prop, name, structType);
            return py::make_tuple(retVal, ArrayECPropertyPtr(prop));
            }, "name"_a, "structType"_a);

    c13.def("RemoveProperty", py::overload_cast<WStringCR>(&ECClass::RemoveProperty), "name"_a);

    c13.def("GetProperty", [] (ECClassCR self, WCharCP name, bool includeBaseClasses)
            {
            return ECPropertyPtr(self.GetPropertyP(name, includeBaseClasses));
            }, "name"_a, "inludeBaseClasses"_a = true);

    c13.def("GetProperty", [] (ECClassCR self, WStringCR name, bool includeBaseClasses)
            {
            return ECPropertyPtr(self.GetPropertyP(name, includeBaseClasses));
            }, "name"_a, "inludeBaseClasses"_a = true);

    c13.def("GetProperty", [](ECClassCR self, Utf8CP name, bool includeBaseClasses)
        {
            return ECPropertyPtr(self.GetPropertyP(name, includeBaseClasses));
        }, "name"_a, "inludeBaseClasses"_a = true);

    c13.def_static("ParseClassName", &ECClass::ParseClassName, "prefix"_a, "className"_a, "qualifiedClassName"_a);
    c13.def_static("GetQualifiedClassName", &ECClass::GetQualifiedClassName, "primarySchema"_a, "ecClass"_a);
    c13.def_static ("ClassesAreEqualByName", &ECClass::ClassesAreEqualByName, "currentBaseClass"_a, "arg"_a);

    //===================================================================================
    // enum OrderIdStorageMode
    py::enum_< OrderIdStorageMode>(m, "OrderIdStorageMode", py::arithmetic())
        .value("eORDERIDSTORAGEMODE_None", ORDERIDSTORAGEMODE_None)
        .value("eORDERIDSTORAGEMODE_ProvidedByPersistence", ORDERIDSTORAGEMODE_ProvidedByPersistence)
        .value("eORDERIDSTORAGEMODE_ProvidedByClient", ORDERIDSTORAGEMODE_ProvidedByClient)
        .export_values();

    //===================================================================================
    // enum ECRelationshipEnd
    py::enum_< ECRelationshipEnd>(m, "ECRelationshipEnd", py::arithmetic())
        .value("eECRelationshipEnd_Source", ECRelationshipEnd_Source)
        .value("eECRelationshipEnd_Target", ECRelationshipEnd_Target)
        .export_values();

    //===================================================================================
    // enum ECRelatedInstanceDirection
    py::enum_< ECRelatedInstanceDirection>(m, "ECRelatedInstanceDirection", py::arithmetic())
        .value("eSTRENGTHDIRECTION_Forward", STRENGTHDIRECTION_Forward)
        .value("eSTRENGTHDIRECTION_Backward", STRENGTHDIRECTION_Backward)
        .export_values();

    //===================================================================================
    // enum StrengthType
    py::enum_< StrengthType>(m, "StrengthType", py::arithmetic())
        .value("eSTRENGTHTYPE_Referencing", STRENGTHTYPE_Referencing)
        .value("eSTRENGTHTYPE_Holding", STRENGTHTYPE_Holding)
        .value("eSTRENGTHTYPE_Embedding", STRENGTHTYPE_Embedding)
        .export_values();

    //===================================================================================
    // struct RelationshipCardinality
    py::class_< RelationshipCardinality> c14(m, "RelationshipCardinality");

    c14.def(py::init<>());
    c14.def(py::init<uint32_t, uint32_t>(), "lowerLimit"_a, "upperLimit"_a);
    
    c14.def_property_readonly("LowerLimit", &RelationshipCardinality::GetLowerLimit);
    c14.def("GetLowerLimit", &RelationshipCardinality::GetLowerLimit);
    
    c14.def_property_readonly("UpperLimit", &RelationshipCardinality::GetUpperLimit);
    c14.def("GetUpperLimit", &RelationshipCardinality::GetUpperLimit);
    
    c14.def("IsUpperLimitUnbounded", &RelationshipCardinality::IsUpperLimitUnbounded);    
    c14.def("ToString", &RelationshipCardinality::ToString);
    
    c14.def_static("ZeroOne", &RelationshipCardinality::ZeroOne, py::return_value_policy::reference);    
    c14.def_static("ZeroMany", &RelationshipCardinality::ZeroMany, py::return_value_policy::reference);    
    c14.def_static("OneOne", &RelationshipCardinality::OneOne, py::return_value_policy::reference);    
    c14.def_static("OneMany", &RelationshipCardinality::OneMany, py::return_value_policy::reference);

    //===================================================================================
    // struct ECRelationshipConstraint
    py::class_< ECRelationshipConstraint, ECRelationshipConstraintPtr, IECCustomAttributeContainer> c15(m, "ECRelationshipConstraint", py::multiple_inheritance());

    c15.def_property_readonly("IsMultiple", &ECRelationshipConstraint::GetIsMultiple);
    c15.def("GetIsMultiple", &ECRelationshipConstraint::GetIsMultiple);
    
    c15.def_property("RoleLabel", &ECRelationshipConstraint::GetRoleLabel, &ECRelationshipConstraint::SetRoleLabel);
    c15.def("GetRoleLabel", &ECRelationshipConstraint::GetRoleLabel);
    c15.def("SetRoleLabel", &ECRelationshipConstraint::SetRoleLabel, "label"_a);
    
    c15.def_property_readonly("InvariantRoleLabel", &ECRelationshipConstraint::GetInvariantRoleLabel);
    c15.def("GetInvariantRoleLabel", &ECRelationshipConstraint::GetInvariantRoleLabel);
    
    c15.def("IsRoleLabelDefined", &ECRelationshipConstraint::IsRoleLabelDefined);

    c15.def_property("IsPolymorphic", &ECRelationshipConstraint::GetIsPolymorphic, py::overload_cast<bool>(&ECRelationshipConstraint::SetIsPolymorphic));
    c15.def("GetIsPolymorphic", &ECRelationshipConstraint::GetIsPolymorphic);
    c15.def("SetIsPolymorphic", py::overload_cast<bool>(&ECRelationshipConstraint::SetIsPolymorphic), "val"_a);
    
    c15.def("SetIsPolymorphic", py::overload_cast<WCharCP>(&ECRelationshipConstraint::SetIsPolymorphic), "isPolymorphic"_a);

    c15.def_property("Cardinality", &ECRelationshipConstraint::GetCardinality, py::overload_cast<RelationshipCardinalityCR>(&ECRelationshipConstraint::SetCardinality));
    c15.def("GetCardinality", &ECRelationshipConstraint::GetCardinality, py::return_value_policy::reference_internal);
    c15.def("SetCardinality", py::overload_cast<RelationshipCardinalityCR>(&ECRelationshipConstraint::SetCardinality), "val"_a);
    
    c15.def("SetCardinality", py::overload_cast<WCharCP>(&ECRelationshipConstraint::SetCardinality), "cardinality"_a);
    
    c15.def("AddClass", &ECRelationshipConstraint::AddClass, "classConstraint"_a, py::keep_alive<1, 2>());
    c15.def("RemoveClass", &ECRelationshipConstraint::RemoveClass, "classConstraint"_a);
    
    c15.def_property_readonly("Classes", &ECRelationshipConstraint::GetClasses);
    c15.def("GetClasses", &ECRelationshipConstraint::GetClasses, py::return_value_policy::reference_internal);
    
    c15.def("CopyTo", &ECRelationshipConstraint::CopyTo, "toRelationshipConstraint"_a);
    
    c15.def_property_readonly("IsOrdered", &ECRelationshipConstraint::GetIsOrdered);
    c15.def("GetIsOrdered", &ECRelationshipConstraint::GetIsOrdered);
    
    c15.def_property_readonly("OrderIdStorageMode", &ECRelationshipConstraint::GetOrderIdStorageMode);
    c15.def("GetOrderIdStorageMode", &ECRelationshipConstraint::GetOrderIdStorageMode);
    
    c15.def("GetOrderedRelationshipPropertyName", &ECRelationshipConstraint::GetOrderedRelationshipPropertyName, "propertyName"_a);

    c15.def("SetCustomAttribute", &ECRelationshipConstraint::SetCustomAttribute, "customAtributeInstance"_a);
    c15.def("GetCustomAttribute", py::overload_cast<ECClassCR>(&IECCustomAttributeContainer::GetCustomAttribute, py::const_), "classDefiniton"_a);

    //===================================================================================
    // struct ECRelationshipClass
    py::class_< ECRelationshipClass, std::unique_ptr<ECRelationshipClass, py::nodelete>, ECClass> c16(m, "ECRelationshipClass");

    c16.def("GetOrderedRelationshipPropertyName", &ECRelationshipClass::GetOrderedRelationshipPropertyName, "propertyName"_a, "end"_a);
    
    c16.def_property("Strength", &ECRelationshipClass::GetStrength, py::overload_cast<StrengthType>(&ECRelationshipClass::SetStrength));
    c16.def("GetStrength", &ECRelationshipClass::GetStrength);
    c16.def("SetStrength", py::overload_cast<StrengthType>(&ECRelationshipClass::SetStrength), "strength"_a);
    
    c16.def_property("StrengthDirection", &ECRelationshipClass::GetStrengthDirection, py::overload_cast<ECRelatedInstanceDirection>(&ECRelationshipClass::SetStrengthDirection));
    c16.def("GetStrengthDirection", &ECRelationshipClass::GetStrengthDirection);
    c16.def("SetStrengthDirection", py::overload_cast<ECRelatedInstanceDirection>(&ECRelationshipClass::SetStrengthDirection), "dir"_a);
    
    c16.def_property_readonly("Target", [] (ECRelationshipClass const& self) { return std::unique_ptr < ECRelationshipConstraint, py::nodelete>(&self.GetTarget()); });
    c16.def("GetTarget", [] (ECRelationshipClass const& self) { return std::unique_ptr < ECRelationshipConstraint, py::nodelete>(&self.GetTarget()); });
    
    c16.def_property_readonly("Source", [] (ECRelationshipClass const& self) { return std::unique_ptr < ECRelationshipConstraint, py::nodelete>(&self.GetSource()); });
    c16.def("GetSource", [] (ECRelationshipClass const& self) { return std::unique_ptr < ECRelationshipConstraint, py::nodelete>(&self.GetSource()); });
    
    c16.def_property_readonly("IsOrdered", &ECRelationshipClass::GetIsOrdered);
    c16.def("GetIsOrdered", &ECRelationshipClass::GetIsOrdered);

    //===================================================================================
    // enum SchemaMatchType
    py::enum_< SchemaMatchType>(m, "SchemaMatchType", py::arithmetic())
        .value("eSCHEMAMATCHTYPE_Identical", SCHEMAMATCHTYPE_Identical)
        .value("eSCHEMAMATCHTYPE_Exact", SCHEMAMATCHTYPE_Exact)
        .value("eSCHEMAMATCHTYPE_LatestCompatible", SCHEMAMATCHTYPE_LatestCompatible)
        .value("eSCHEMAMATCHTYPE_Latest", SCHEMAMATCHTYPE_Latest)
        .export_values();

    //===================================================================================
    // struct SchemaKey
    py::class_< SchemaKey> c17(m, "SchemaKey");

    c17.def_readwrite("schemaName", &SchemaKey::m_schemaName);
    c17.def_readwrite("versionMajor", &SchemaKey::m_versionMajor);
    c17.def_readwrite("versionMinor", &SchemaKey::m_versionMinor);
    c17.def_readwrite("checkSum", &SchemaKey::m_checkSum);

    c17.def(py::init<>());
    c17.def(py::init<WCharCP, uint32_t, uint32_t>(), "name"_a, "majorVersion"_a, "minorVersion"_a);
    c17.def_static("ParseSchemaFullName", &SchemaKey::ParseSchemaFullName, "key"_a, "schemaFullName"_a);
    c17.def(py::self == py::self);
    c17.def(py::self != py::self);
    c17.def(py::self < py::self);

    //===================================================================================
    // struct SchemaNameClassNamePair
    py::class_< SchemaNameClassNamePair> c18(m, "SchemaNameClassNamePair");
    py::bind_vector<bvector< SchemaNameClassNamePair>>(m, "SchemaNameClassNamePairArray", py::module_local(false));

    c18.def_readwrite("schemaName", &SchemaNameClassNamePair::m_schemaName);
    c18.def_readwrite("className", &SchemaNameClassNamePair::m_className);
    c18.def(py::init<>());
    c18.def(py::init<WCharCP, WCharCP>(), "schemaName"_a, "className"_a);
    c18.def(py::init<WStringCR>(), "schemaAndClassNameSeparatedByColon"_a);
    c18.def("Parse", &SchemaNameClassNamePair::Parse, "schemaAndClassNameSeparatedByColon"_a);
    c18.def(py::self < py::self);
    c18.def(py::self == py::self);
    c18.def("ToColonSeparatedString", &SchemaNameClassNamePair::ToColonSeparatedString);
    c18.def("__hash__", [](SchemaNameClassNamePair const& self)
            {
            size_t h1 = std::hash<WCharCP>{}(self.m_schemaName.c_str ());
            size_t h2 = std::hash<WCharCP>{}(self.m_className.c_str ());
            return h1 ^ (h2 << 1);
            }
           );
    c18.def("__eq__", [](SchemaNameClassNamePair const& self, SchemaNameClassNamePair const& other)
        {
        return self.m_schemaName == other.m_schemaName && self.m_className == other.m_className;
        }
    );

    //===================================================================================
    // struct QualifiedECAccessor
    py::class_< QualifiedECAccessor> c19(m, "QualifiedECAccessor");

    c19.def(py::init<>());
    c19.def(py::init<WCharCP, WCharCP, WCharCP>(), "schemaName"_a, "className"_a, "accessString"_a);
    
    c19.def_property("SchemaName", &QualifiedECAccessor::GetSchemaName, &QualifiedECAccessor::SetSchemaName);
    c19.def("GetSchemaName", &QualifiedECAccessor::GetSchemaName, py::return_value_policy::reference_internal);
    c19.def("SetSchemaName", &QualifiedECAccessor::SetSchemaName, "name"_a);
    
    c19.def_property("ClassName", &QualifiedECAccessor::GetClassName, &QualifiedECAccessor::SetClassName);
    c19.def("GetClassName", &QualifiedECAccessor::GetClassName, py::return_value_policy::reference_internal);
    c19.def("SetClassName", &QualifiedECAccessor::SetClassName, "name"_a);
    
    c19.def_property("AccessString", &QualifiedECAccessor::GetAccessString, &QualifiedECAccessor::SetAccessString);
    c19.def("GetAccessString", &QualifiedECAccessor::GetAccessString, py::return_value_policy::reference_internal);
    c19.def("SetAccessString", &QualifiedECAccessor::SetAccessString, "accessString"_a);
    
    c19.def("ToString", &QualifiedECAccessor::ToString);
    c19.def("FromString", &QualifiedECAccessor::FromString, "str"_a);
    c19.def("FromAccessString", &QualifiedECAccessor::FromAccessString, "rootEnabler"_a, "accessString"_a);

    //===================================================================================
    // struct ECClassContainer
    py::class_< ECClassContainer> c20(m, "ECClassContainer");

    c20.def("__iter__", [] (ECClassContainer& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct IStandaloneEnablerLocater
    py::class_< IStandaloneEnablerLocater, std::unique_ptr< IStandaloneEnablerLocater, py::nodelete> > c21(m, "IStandaloneEnablerLocater");

    c21.def("LocateStandaloneEnabler", &IStandaloneEnablerLocater::LocateStandaloneEnabler, "schemaKey"_a, "className"_a);

    //===================================================================================
    // struct IECSchemaLocater
    py::class_< IECSchemaLocater, std::unique_ptr< IECSchemaLocater, py::nodelete>, IPyECSchemaLocater> c22(m, "IECSchemaLocater");

    c22.def(py::init<>());
    c22.def("_LocateSchema", &IECSchemaLocaterPub::_LocateSchema, "key"_a, "matchType"_a, "schemaContext"_a);
    c22.def("LocateSchema", &IECSchemaLocater::LocateSchema, "key"_a, "matchType"_a, "schemaContext"_a);

    //===================================================================================
    // struct ECSchemaCache
    py::class_< ECSchemaCache, ECSchemaCachePtr/*, IECSchemaLocater*/> c23(m, "ECSchemaCache", py::multiple_inheritance());

    c23.def("AddSchema", &ECSchemaCache::AddSchema, "schema"_a);
    c23.def("DropSchema", &ECSchemaCache::DropSchema, "key"_a);
    c23.def("GetSchema", py::overload_cast<SchemaKeyCR>(&ECSchemaCache::GetSchema), "key"_a);
    c23.def("GetSchema", py::overload_cast<SchemaKeyCR, SchemaMatchType>(&ECSchemaCache::GetSchema), "key"_a, "matchType"_a);
    c23.def(py::init(&ECSchemaCache::Create));

    c23.def_property_readonly("Count", &ECSchemaCache::GetCount);
    c23.def("GetCount", &ECSchemaCache::GetCount);
    
    c23.def("Clear", &ECSchemaCache::Clear);
    
    c23.def_property_readonly("SchemaLocater", &ECSchemaCache::GetSchemaLocater);
    c23.def("GetSchemaLocater", &ECSchemaCache::GetSchemaLocater, py::return_value_policy::reference_internal);
    
    c23.def("GetSchemas", &ECSchemaCache::GetSchemas, "schemas"_a);

    //===================================================================================
    // struct ECSchema
    py::class_< ECSchema, ECSchemaPtr/*, IECCustomAttributeContainer*/> c24(m, "ECSchema", py::multiple_inheritance());
    py::bind_vector<ECSchemaPtrArray>(m, "ECSchemaPtrArray", py::module_local(false));
    py::bind_vector<ECSchemaPArray>(m, "ECSchemaPArray", py::module_local(false));
    py::bind_vector<ECSchemaCPArray>(m, "ECSchemaCPArray", py::module_local(false));

    c24.def_property_readonly("SchemaKey", &ECSchema::GetSchemaKey);
    c24.def("GetSchemaKey", &ECSchema::GetSchemaKey, py::return_value_policy::reference_internal);
    
    c24.def_property_readonly("Id", &ECSchema::GetId);
    c24.def("GetId", &ECSchema::GetId);
    
    c24.def_property("Name", &ECSchema::GetName, &ECSchema::SetName);
    c24.def("GetName", &ECSchema::GetName, py::return_value_policy::reference_internal);
    c24.def("SetName", &ECSchema::SetName, "name"_a);
    
    c24.def_property("NamespacePrefix", &ECSchema::GetNamespacePrefix, &ECSchema::SetNamespacePrefix);
    c24.def("GetNamespacePrefix", &ECSchema::GetNamespacePrefix, py::return_value_policy::reference_internal);
    c24.def("SetNamespacePrefix", &ECSchema::SetNamespacePrefix, "prefix"_a);
    
    c24.def_property("Description", &ECSchema::GetDescription, &ECSchema::SetDescription);
    c24.def("GetDescription", &ECSchema::GetDescription, py::return_value_policy::reference_internal);
    c24.def("SetDescription", &ECSchema::SetDescription, "description"_a);
    
    c24.def_property_readonly("InvariantDescription", &ECSchema::GetInvariantDescription);
    c24.def("GetInvariantDescription", &ECSchema::GetInvariantDescription, py::return_value_policy::reference_internal);
    
    c24.def_property("DisplayLabel", &ECSchema::GetDisplayLabel, &ECSchema::SetDisplayLabel);
    c24.def("GetDisplayLabel", &ECSchema::GetDisplayLabel, py::return_value_policy::reference_internal);
    c24.def("SetDisplayLabel", &ECSchema::SetDisplayLabel, "label"_a);
    
    c24.def_property_readonly("InvariantDisplayLabel", &ECSchema::GetInvariantDisplayLabel);
    c24.def("GetInvariantDisplayLabel", &ECSchema::GetInvariantDisplayLabel, py::return_value_policy::reference_internal);
    
    c24.def_property("VersionMajor", &ECSchema::GetVersionMajor, &ECSchema::SetVersionMajor);
    c24.def("GetVersionMajor", &ECSchema::GetVersionMajor);
    c24.def("SetVersionMajor", &ECSchema::SetVersionMajor, "major"_a);
    
    c24.def_property("VersionMinor", &ECSchema::GetVersionMinor, &ECSchema::SetVersionMinor);
    c24.def("GetVersionMinor", &ECSchema::GetVersionMinor);
    c24.def("SetVersionMinor", &ECSchema::SetVersionMinor, "minor"_a);
    
    c24.def_property_readonly("Classes", &ECSchema::GetClasses);
    c24.def("GetClasses", &ECSchema::GetClasses, py::return_value_policy::reference_internal);
    
    c24.def_property_readonly("ClassCount", &ECSchema::GetClassCount);
    c24.def("GetClassCount", &ECSchema::GetClassCount);
    
    c24.def_property_readonly("IsDisplayLabelDefined", &ECSchema::GetIsDisplayLabelDefined);
    c24.def("GetIsDisplayLabelDefined", &ECSchema::GetIsDisplayLabelDefined);
    
    c24.def("IsStandardSchema", py::overload_cast<>(&ECSchema::IsStandardSchema, py::const_));
    c24.def("IsSamePrimarySchema", &ECSchema::IsSamePrimarySchema, "primarySchema"_a);
    c24.def("IsSupplementalSchema", &ECSchema::IsSupplementalSchema);
    c24.def("IsSupplemented", &ECSchema::IsSupplemented);
    
    c24.def_property_readonly("SupplementalInfo", &ECSchema::GetSupplementalInfo);
    c24.def("GetSupplementalInfo", &ECSchema::GetSupplementalInfo);
    
    c24.def("ShouldNotBeStored", py::overload_cast<>(&ECSchema::ShouldNotBeStored, py::const_));

    c24.def("CreateClass", [] (ECSchema& self, WStringCR name)
            {
            ECClassP ecClass = nullptr;
            auto retVal = self.CreateClass(ecClass, name);
            return py::make_tuple(retVal, ECClassPtr(ecClass));
            }, "name"_a);

    c24.def("CreateRelationshipClass", [] (ECSchema& self, WStringCR name)
            {
            ECRelationshipClassP ecClass = nullptr;
            auto retVal = self.CreateRelationshipClass(ecClass, name);
            return py::make_tuple(retVal, std::unique_ptr< ECRelationshipClass, py::nodelete>(ecClass));
            }, "name"_a);

    c24.def("GetSchemaByNamespacePrefix", [] (ECSchema const& self, WStringCR namespacePrefix)
            {
            return ECSchemaPtr(const_cast<ECSchemaP>(self.GetSchemaByNamespacePrefixP(namespacePrefix)));
            }, "namespacePrefix"_a);

    c24.def("ResolveNamespacePrefix", &ECSchema::ResolveNamespacePrefix, "schema"_a, "namespacePrefix"_a);
    c24.def("GetClass", [] (ECSchema& self, WCharCP name) { return ECClassPtr(self.GetClassP(name)); }, "name"_a);
    
    c24.def_property_readonly("ReferencedSchemas", &ECSchema::GetReferencedSchemas);
    c24.def("GetReferencedSchemas", &ECSchema::GetReferencedSchemas, py::return_value_policy::reference_internal);
    
    c24.def("AddReferencedSchema", py::overload_cast<ECSchemaR>(&ECSchema::AddReferencedSchema), "refSchema"_a);
    c24.def("AddReferencedSchema", py::overload_cast<ECSchemaR, WStringCR>(&ECSchema::AddReferencedSchema), "refSchema"_a, "prefix"_a);
    c24.def("RemoveReferencedSchema", &ECSchema::RemoveReferencedSchema, "refSchema"_a);
    c24.def("WriteToXmlString", py::overload_cast<WStringR>(&ECSchema::WriteToXmlString, py::const_), "ecSchemaXml"_a);
    c24.def("WriteToXmlString", py::overload_cast<Utf8StringR>(&ECSchema::WriteToXmlString, py::const_), "ecSchemaXml"_a);
    c24.def("WriteToXmlFile", &ECSchema::WriteToXmlFile, "ecSchemaXmlFile"_a, "utf16"_a = false);
    
    c24.def_property_readonly("FullSchemaName", &ECSchema::GetFullSchemaName);
    c24.def("GetFullSchemaName", &ECSchema::GetFullSchemaName);
    
    c24.def("CopyClass", [] (ECSchemaR self, ECClassCR sourceClass)
            {
            ECClassP targetClass = nullptr;
            auto retVal = self.CopyClass(targetClass, sourceClass);
            return py::make_tuple(retVal, ECClassPtr(targetClass));
            }, "sourceClass"_a);

    c24.def("CopySchema", [] (ECSchemaCR self)
            {
            ECSchemaPtr schemaOut;
            auto retVal = self.CopySchema(schemaOut);
            return py::make_tuple(retVal, schemaOut);
            });

    c24.def_property_readonly("CustomAttributeContainer", py::overload_cast<>(&ECSchema::GetCustomAttributeContainer));
    c24.def("GetCustomAttributeContainer", py::overload_cast<>(&ECSchema::GetCustomAttributeContainer), py::return_value_policy::reference_internal);
    //c24.def("SetCustomAttribute", &ECSchema::SetCustomAttribute, "customAtributeInstance"_a);
    //c24.def("GetCustomAttributes", &ECSchema::GetCustomAttributes, "includeBase"_a);

    c24.def_static("ComputeSchemaXmlStringCheckSum", &ECSchema::ComputeSchemaXmlStringCheckSum, "str"_a, "len"_a);

    c24.def_static("CreateSchema", [] (WStringCR schemaName, uint32_t versionMajor, uint32_t versionMinor)
                   {
                   ECSchemaPtr schemaOut;
                   auto retVal = ECSchema::CreateSchema(schemaOut, schemaName, versionMajor, versionMinor);
                   return py::make_tuple(retVal, schemaOut);
                   }, "schemaName"_a, "versionMajor"_a, "versionMinor"_a);

    c24.def_static("FormatSchemaVersion", &ECSchema::FormatSchemaVersion, "versionMajor"_a, "versionMinor"_a);
    
    c24.def_static("ParseSchemaFullName", [] (WCharCP fullName)
                   {
                   WString schemaName;
                   uint32_t versionMajor, versionMinor;
                   auto retVal = ECSchema::ParseSchemaFullName(schemaName, versionMajor, versionMinor, fullName);
                   return py::make_tuple(retVal, schemaName, versionMajor, versionMinor);
                   }, "fullName"_a);

    c24.def_static("ParseVersionString", [] (WCharCP versionString)
                   {
                   uint32_t versionMajor, versionMinor;
                   auto retVal = ECSchema::ParseVersionString(versionMajor, versionMinor, versionString);
                   return py::make_tuple(retVal, versionMajor, versionMinor);
                   }, "versionString"_a);
    
    c24.def_static("IsSchemaReferenced", &ECSchema::IsSchemaReferenced, "thisSchema"_a, "potentiallyReferencedSchema"_a);
    
    c24.def_static("ReadFromXmlFile", [] (WCharCP ecSchemaXmlFile, ECSchemaReadContextR schemaContext)
                   {
                   ECSchemaPtr schemaOut;
                   auto retVal = ECSchema::ReadFromXmlFile(schemaOut, ecSchemaXmlFile, schemaContext);
                   return py::make_tuple(retVal, schemaOut);
                   }, "ecSchemaXmlFile"_a, "schemaContext"_a);

    c24.def_static("LocateSchema", &ECSchema::LocateSchema, "schema"_a, "schemaContext"_a);

    c24.def_static("ReadFromXmlString", [] (WCharCP ecSchemaXml, ECSchemaReadContextR schemaContext)
                   {
                   ECSchemaPtr schemaOut;
                   auto retVal = ECSchema::ReadFromXmlString(schemaOut, ecSchemaXml, schemaContext);
                   return py::make_tuple(retVal, schemaOut);
                   }, "ecSchemaXml"_a, "schemaContext"_a);

    c24.def_static("ReadFromXmlString", [](Utf8CP ecSchemaXml, ECSchemaReadContextR schemaContext)
        {
            ECSchemaPtr schemaOut;
            auto retVal = ECSchema::ReadFromXmlString(schemaOut, ecSchemaXml, schemaContext);
            return py::make_tuple(retVal, schemaOut);
        }, "ecSchemaXml"_a, "schemaContext"_a);

    c24.def("FindAllSchemasInGraph", py::overload_cast<bvector<ECN::ECSchemaP>&, bool>(&ECSchema::FindAllSchemasInGraph), "allSchemas"_a, "includeRootSchema"_a = true);
    c24.def("FindSchema", &ECSchema::FindSchemaP, "schemaKey"_a, "matchType"_a, py::return_value_policy::reference_internal);
    c24.def("SetImmutable", &ECSchema::SetImmutable);
    c24.def_static("SetErrorHandling", &ECSchema::SetErrorHandling);

    py::class_<Bentley::Bstdcxx::bpair<Bentley::ECN::SchemaKey const, Bentley::RefCountedPtr<Bentley::ECN::ECSchema> >> c26(m, "SchemaKeyToSchemaBPair", py::multiple_inheritance());
    //c26.def("GetFirst", [](Bentley::Bstdcxx::bpair<Bentley::ECN::SchemaKey const, Bentley::RefCountedPtr<Bentley::ECN::ECSchema> >& self) {return self.first; });
    //c26.def("GetSecond", [](Bentley::Bstdcxx::bpair<Bentley::ECN::SchemaKey const, Bentley::RefCountedPtr<Bentley::ECN::ECSchema> >& self) {return self.second; });

    c26.def(py::init<>());
    c26.def(py::init<Bentley::ECN::SchemaKey const, Bentley::RefCountedPtr<Bentley::ECN::ECSchema>>(), "key"_a, "value"_a);
    c26.def(py::self == py::self);

    // struct SchemaMapExact
    py::bind_map< SchemaMapExact > (m, "SchemaMapExact", py::module_local(false));

    // struct AssertDisabler
    //py::class_< AssertDisabler> c27 (m, "AssertDisabler", py::multiple_inheritance());  //Need to comment out when pushing
    //c27.def(py::init<>());
    }