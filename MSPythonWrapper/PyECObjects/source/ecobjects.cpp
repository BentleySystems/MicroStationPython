/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecobjects.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECObjects(py::module_& m)
    {
    //===================================================================================
    // enum ECErrorCategories
    py::enum_< ECErrorCategories>(m, "ECErrorCategories", py::arithmetic())
        .value("eECOBJECTS_ERROR_BASE", ECOBJECTS_ERROR_BASE)
        .value("eSCHEMA_READ_STATUS_BASE", SCHEMA_READ_STATUS_BASE)
        .value("eSCHEMA_WRITE_STATUS_BASE", SCHEMA_WRITE_STATUS_BASE)
        .value("eINSTANCE_READ_STATUS_BASE", INSTANCE_READ_STATUS_BASE)
        .value("eINSTANCE_WRITE_STATUS_BASE", INSTANCE_WRITE_STATUS_BASE)
        .value("eSUPPLEMENTED_SCHEMA_STATUS_BASE", SUPPLEMENTED_SCHEMA_STATUS_BASE)
        .export_values();

    //===================================================================================
    // enum ECObjectsStatus
    py::enum_< ECObjectsStatus>(m, "ECObjectsStatus", py::arithmetic())
        .value("eECOBJECTS_STATUS_Success", ECOBJECTS_STATUS_Success)
        .value("eECOBJECTS_STATUS_PropertyNotFound", ECOBJECTS_STATUS_PropertyNotFound)
        .value("eECOBJECTS_STATUS_DataTypeMismatch", ECOBJECTS_STATUS_DataTypeMismatch)
        .value("eECOBJECTS_STATUS_ECInstanceImplementationNotSupported", ECOBJECTS_STATUS_ECInstanceImplementationNotSupported)
        .value("eECOBJECTS_STATUS_InvalidPropertyAccessString", ECOBJECTS_STATUS_InvalidPropertyAccessString)
        .value("eECOBJECTS_STATUS_IndexOutOfRange", ECOBJECTS_STATUS_IndexOutOfRange)
        .value("eECOBJECTS_STATUS_ECClassNotSupported", ECOBJECTS_STATUS_ECClassNotSupported)
        .value("eECOBJECTS_STATUS_ECSchemaNotSupported", ECOBJECTS_STATUS_ECSchemaNotSupported)
        .value("eECOBJECTS_STATUS_AccessStringDisagreesWithNIndices", ECOBJECTS_STATUS_AccessStringDisagreesWithNIndices)
        .value("eECOBJECTS_STATUS_EnablerNotFound", ECOBJECTS_STATUS_EnablerNotFound)
        .value("eECOBJECTS_STATUS_OperationNotSupported", ECOBJECTS_STATUS_OperationNotSupported)
        .value("eECOBJECTS_STATUS_ParseError", ECOBJECTS_STATUS_ParseError)
        .value("eECOBJECTS_STATUS_NamedItemAlreadyExists", ECOBJECTS_STATUS_NamedItemAlreadyExists)
        .value("eECOBJECTS_STATUS_PreconditionViolated", ECOBJECTS_STATUS_PreconditionViolated)
        .value("eECOBJECTS_STATUS_SchemaNotFound", ECOBJECTS_STATUS_SchemaNotFound)
        .value("eECOBJECTS_STATUS_ClassNotFound", ECOBJECTS_STATUS_ClassNotFound)
        .value("eECOBJECTS_STATUS_BaseClassUnacceptable", ECOBJECTS_STATUS_BaseClassUnacceptable)
        .value("eECOBJECTS_STATUS_SchemaInUse", ECOBJECTS_STATUS_SchemaInUse)
        .value("eECOBJECTS_STATUS_InvalidName", ECOBJECTS_STATUS_InvalidName)
        .value("eECOBJECTS_STATUS_DataTypeNotSupported", ECOBJECTS_STATUS_DataTypeNotSupported)
        .value("eECOBJECTS_STATUS_UnableToAllocateMemory", ECOBJECTS_STATUS_UnableToAllocateMemory)
        .value("eECOBJECTS_STATUS_MemoryBoundsOverrun", ECOBJECTS_STATUS_MemoryBoundsOverrun)
        .value("eECOBJECTS_STATUS_NullPointerValue", ECOBJECTS_STATUS_NullPointerValue)
        .value("eECOBJECTS_STATUS_NotCustomAttributeClass", ECOBJECTS_STATUS_NotCustomAttributeClass)
        .value("eECOBJECTS_STATUS_DuplicateSchema", ECOBJECTS_STATUS_DuplicateSchema)
        .value("eECOBJECTS_STATUS_UnableToSetReadOnlyInstance", ECOBJECTS_STATUS_UnableToSetReadOnlyInstance)
        .value("eECOBJECTS_STATUS_UnableToSetReadOnlyProperty", ECOBJECTS_STATUS_UnableToSetReadOnlyProperty)
        .value("eECOBJECTS_STATUS_ArrayIndexDoesNotExist", ECOBJECTS_STATUS_ArrayIndexDoesNotExist)
        .value("eECOBJECTS_STATUS_PropertyValueMatchesNoChange", ECOBJECTS_STATUS_PropertyValueMatchesNoChange)
        .value("eECOBJECTS_STATUS_NoChildProperties", ECOBJECTS_STATUS_NoChildProperties)
        .value("eECOBJECTS_STATUS_UnableToAllocateManagedMemory", ECOBJECTS_STATUS_UnableToAllocateManagedMemory)
        .value("eECOBJECTS_STATUS_MemoryAllocationCallbackRequired", ECOBJECTS_STATUS_MemoryAllocationCallbackRequired)
        .value("eECOBJECTS_STATUS_UnableToAddStructArrayMember", ECOBJECTS_STATUS_UnableToAddStructArrayMember)
        .value("eECOBJECTS_STATUS_UnableToSetStructArrayMemberInstance", ECOBJECTS_STATUS_UnableToSetStructArrayMemberInstance)
        .value("eECOBJECTS_STATUS_UnableToGetStructArrayMemberInstance", ECOBJECTS_STATUS_UnableToGetStructArrayMemberInstance)
        .value("eECOBJECTS_STATUS_InvalidIndexForPerPropertyFlag", ECOBJECTS_STATUS_InvalidIndexForPerPropertyFlag)
        .value("eECOBJECTS_STATUS_SchemaHasReferenceCycle", ECOBJECTS_STATUS_SchemaHasReferenceCycle)
        .value("eECOBJECTS_STATUS_SchemaNotSupplemented", ECOBJECTS_STATUS_SchemaNotSupplemented)
        .value("eECOBJECTS_STATUS_UnableToQueryForNullPropertyFlag", ECOBJECTS_STATUS_UnableToQueryForNullPropertyFlag)
        .value("eECOBJECTS_STATUS_UnableToResizeFixedSizedArray", ECOBJECTS_STATUS_UnableToResizeFixedSizedArray)
        .value("eECOBJECTS_STATUS_SchemaIsImmutable", ECOBJECTS_STATUS_SchemaIsImmutable)
        .value("eECOBJECTS_STATUS_Error", ECOBJECTS_STATUS_Error)
        .export_values();

    //===================================================================================
    // enum SchemaReadStatus
    py::enum_< SchemaReadStatus>(m, "SchemaReadStatus", py::arithmetic())
        .value("eSCHEMA_READ_STATUS_Success", SCHEMA_READ_STATUS_Success)
        .value("eSCHEMA_READ_STATUS_FailedToParseXml", SCHEMA_READ_STATUS_FailedToParseXml)
        .value("eSCHEMA_READ_STATUS_InvalidECSchemaXml", SCHEMA_READ_STATUS_InvalidECSchemaXml)
        .value("eSCHEMA_READ_STATUS_ReferencedSchemaNotFound", SCHEMA_READ_STATUS_ReferencedSchemaNotFound)
        .value("eSCHEMA_READ_STATUS_DuplicateSchema", SCHEMA_READ_STATUS_DuplicateSchema)
        .value("eSCHEMA_READ_STATUS_InvalidPrimitiveType", SCHEMA_READ_STATUS_InvalidPrimitiveType)
        .value("eSCHEMA_READ_STATUS_HasReferenceCycle", SCHEMA_READ_STATUS_HasReferenceCycle)
        .export_values();

    //===================================================================================
    // enum SchemaWriteStatus
    py::enum_< SchemaWriteStatus>(m, "SchemaWriteStatus", py::arithmetic())
        .value("eSCHEMA_WRITE_STATUS_Success", SCHEMA_WRITE_STATUS_Success)
        .value("eSCHEMA_WRITE_STATUS_FailedToSaveXml", SCHEMA_WRITE_STATUS_FailedToSaveXml)
        .value("eSCHEMA_WRITE_STATUS_FailedToCreateXml", SCHEMA_WRITE_STATUS_FailedToCreateXml)
        .value("eSCHEMA_WRITE_STATUS_FailedToWriteFile", SCHEMA_WRITE_STATUS_FailedToWriteFile)
        .export_values();

    //===================================================================================
    // enum InstanceReadStatus
    py::enum_< InstanceReadStatus>(m, "InstanceReadStatus", py::arithmetic())
        .value("eINSTANCE_READ_STATUS_Success", INSTANCE_READ_STATUS_Success)
        .value("eINSTANCE_READ_STATUS_FileNotFound", INSTANCE_READ_STATUS_FileNotFound)
        .value("eINSTANCE_READ_STATUS_CantCreateStream", INSTANCE_READ_STATUS_CantCreateStream)
        .value("eINSTANCE_READ_STATUS_CantCreateXmlReader", INSTANCE_READ_STATUS_CantCreateXmlReader)
        .value("eINSTANCE_READ_STATUS_CantSetStream", INSTANCE_READ_STATUS_CantSetStream)
        .value("eINSTANCE_READ_STATUS_NoElementName", INSTANCE_READ_STATUS_NoElementName)
        .value("eINSTANCE_READ_STATUS_BadElement", INSTANCE_READ_STATUS_BadElement)
        .value("eINSTANCE_READ_STATUS_UnexpectedElement", INSTANCE_READ_STATUS_UnexpectedElement)
        .value("eINSTANCE_READ_STATUS_EmptyElement", INSTANCE_READ_STATUS_EmptyElement)
        .value("eINSTANCE_READ_STATUS_EndElementDoesntMatch", INSTANCE_READ_STATUS_EndElementDoesntMatch)
        .value("eINSTANCE_READ_STATUS_XmlFileIncomplete", INSTANCE_READ_STATUS_XmlFileIncomplete)
        .value("eINSTANCE_READ_STATUS_XmlParseError", INSTANCE_READ_STATUS_XmlParseError)
        .value("eINSTANCE_READ_STATUS_ECClassNotFound", INSTANCE_READ_STATUS_ECClassNotFound)
        .value("eINSTANCE_READ_STATUS_BadECProperty", INSTANCE_READ_STATUS_BadECProperty)
        .value("eINSTANCE_READ_STATUS_BadPrimitivePropertyType", INSTANCE_READ_STATUS_BadPrimitivePropertyType)
        .value("eINSTANCE_READ_STATUS_BadBinaryData", INSTANCE_READ_STATUS_BadBinaryData)
        .value("eINSTANCE_READ_STATUS_BadTimeValue", INSTANCE_READ_STATUS_BadTimeValue)
        .value("eINSTANCE_READ_STATUS_BadDoubleValue", INSTANCE_READ_STATUS_BadDoubleValue)
        .value("eINSTANCE_READ_STATUS_BadIntegerValue", INSTANCE_READ_STATUS_BadIntegerValue)
        .value("eINSTANCE_READ_STATUS_BadLongValue", INSTANCE_READ_STATUS_BadLongValue)
        .value("eINSTANCE_READ_STATUS_BadPoint2dValue", INSTANCE_READ_STATUS_BadPoint2dValue)
        .value("eINSTANCE_READ_STATUS_BadPoint3dValue", INSTANCE_READ_STATUS_BadPoint3dValue)
        .value("eINSTANCE_READ_STATUS_BadArrayElement", INSTANCE_READ_STATUS_BadArrayElement)
        .value("eINSTANCE_READ_STATUS_TypeMismatch", INSTANCE_READ_STATUS_TypeMismatch)
        .value("eINSTANCE_READ_STATUS_CantSetValue", INSTANCE_READ_STATUS_CantSetValue)
        .value("eINSTANCE_READ_STATUS_ECSchemaNotFound", INSTANCE_READ_STATUS_ECSchemaNotFound)
        .value("eINSTANCE_READ_STATUS_UnableToGetStandaloneEnabler", INSTANCE_READ_STATUS_UnableToGetStandaloneEnabler)
        .value("eINSTANCE_READ_STATUS_CommentOnly", INSTANCE_READ_STATUS_CommentOnly)
        .value("eINSTANCE_READ_STATUS_PropertyNotFound", INSTANCE_READ_STATUS_PropertyNotFound)
        .export_values();

    //===================================================================================
    // enum InstanceWriteStatus
    py::enum_< InstanceWriteStatus>(m, "InstanceWriteStatus", py::arithmetic())
        .value("eINSTANCE_WRITE_STATUS_Success", INSTANCE_WRITE_STATUS_Success)
        .value("eINSTANCE_WRITE_STATUS_CantCreateStream", INSTANCE_WRITE_STATUS_CantCreateStream)
        .value("eINSTANCE_WRITE_STATUS_CantCreateXmlWriter", INSTANCE_WRITE_STATUS_CantCreateXmlWriter)
        .value("eINSTANCE_WRITE_STATUS_CantSetStream", INSTANCE_WRITE_STATUS_CantSetStream)
        .value("eINSTANCE_WRITE_STATUS_XmlWriteError", INSTANCE_WRITE_STATUS_XmlWriteError)
        .value("eINSTANCE_WRITE_STATUS_CantReadFromStream", INSTANCE_WRITE_STATUS_CantReadFromStream)
        .value("eINSTANCE_WRITE_STATUS_FailedToWriteFile", INSTANCE_WRITE_STATUS_FailedToWriteFile)
        .value("eINSTANCE_WRITE_STATUS_BadPrimitivePropertyType", INSTANCE_WRITE_STATUS_BadPrimitivePropertyType)
        .export_values();

    //===================================================================================
    // enum SupplementedSchemaStatus
    py::enum_< SupplementedSchemaStatus>(m, "SupplementedSchemaStatus", py::arithmetic())
        .value("eSUPPLEMENTED_SCHEMA_STATUS_Success", SUPPLEMENTED_SCHEMA_STATUS_Success)
        .value("eSUPPLEMENTED_SCHEMA_STATUS_Metadata_Missing", SUPPLEMENTED_SCHEMA_STATUS_Metadata_Missing)
        .value("eSUPPLEMENTED_SCHEMA_STATUS_Duplicate_Precedence_Error", SUPPLEMENTED_SCHEMA_STATUS_Duplicate_Precedence_Error)
        .value("eSUPPLEMENTED_SCHEMA_STATUS_IECRelationship_Not_Allowed", SUPPLEMENTED_SCHEMA_STATUS_IECRelationship_Not_Allowed)
        .value("eSUPPLEMENTED_SCHEMA_STATUS_SchemaMergeException", SUPPLEMENTED_SCHEMA_STATUS_SchemaMergeException)
        .value("eSUPPLEMENTED_SCHEMA_STATUS_SupplementalClassHasBaseClass", SUPPLEMENTED_SCHEMA_STATUS_SupplementalClassHasBaseClass)
        .export_values();

    //===================================================================================
    // enum EvaluationOptions
    py::enum_< EvaluationOptions>(m, "EvaluationOptions", py::arithmetic())
        .value("eEVALOPT_Legacy", EVALOPT_Legacy)
        .value("eEVALOPT_SuppressTypeConversions", EVALOPT_SuppressTypeConversions)
        .value("eEVALOPT_EnforceUnits", EVALOPT_EnforceUnits)
        .value("eEVALOPT_EnforceGlobalRepresentation", EVALOPT_EnforceGlobalRepresentation)
        .export_values();

    //===================================================================================
    // enum ValueKind
    py::enum_< ValueKind>(m, "ValueKind", py::arithmetic())
        .value("eVALUEKIND_Uninitialized", VALUEKIND_Uninitialized)
        .value("eVALUEKIND_Primitive", VALUEKIND_Primitive)
        .value("eVALUEKIND_Struct", VALUEKIND_Struct)
        .value("eVALUEKIND_Array", VALUEKIND_Array)
        .export_values();

    //===================================================================================
    // enum ArrayKind
    py::enum_< ArrayKind>(m, "ArrayKind", py::arithmetic())
        .value("eARRAYKIND_Primitive", ARRAYKIND_Primitive)
        .value("eARRAYKIND_Struct", ARRAYKIND_Struct)
        .export_values();

    //===================================================================================
    // enum PrimitiveType
    py::enum_< PrimitiveType>(m, "PrimitiveType", py::arithmetic())
        .value("ePRIMITIVETYPE_Binary", PRIMITIVETYPE_Binary)
        .value("ePRIMITIVETYPE_Boolean", PRIMITIVETYPE_Boolean)
        .value("ePRIMITIVETYPE_DateTime", PRIMITIVETYPE_DateTime)
        .value("ePRIMITIVETYPE_Double", PRIMITIVETYPE_Double)
        .value("ePRIMITIVETYPE_Integer", PRIMITIVETYPE_Integer)
        .value("ePRIMITIVETYPE_Long", PRIMITIVETYPE_Long)
        .value("ePRIMITIVETYPE_Point2D", PRIMITIVETYPE_Point2D)
        .value("ePRIMITIVETYPE_Point3D", PRIMITIVETYPE_Point3D)
        .value("ePRIMITIVETYPE_String", PRIMITIVETYPE_String)
        .value("ePRIMITIVETYPE_IGeometry", PRIMITIVETYPE_IGeometry)
        .export_values();

    //===================================================================================
    // enum ExpressionStatus
    py::enum_< ExpressionStatus>(m, "ExpressionStatus", py::arithmetic())
        .value("eExprStatus_Success", ExprStatus_Success)
        .value("eExprStatus_UnknownError", ExprStatus_UnknownError)
        .value("eExprStatus_UnknownMember", ExprStatus_UnknownMember)
        .value("eExprStatus_PrimitiveRequired", ExprStatus_PrimitiveRequired)
        .value("eExprStatus_StructRequired", ExprStatus_StructRequired)
        .value("eExprStatus_ArrayRequired", ExprStatus_ArrayRequired)
        .value("eExprStatus_UnknownSymbol", ExprStatus_UnknownSymbol)
        .value("eExprStatus_DotNotSupported", ExprStatus_DotNotSupported)
        .value("eExprStatus_NotImpl", ExprStatus_NotImpl)
        .value("eExprStatus_NeedsLValue", ExprStatus_NeedsLValue)
        .value("eExprStatus_WrongType", ExprStatus_WrongType)
        .value("eExprStatus_IncompatibleTypes", ExprStatus_IncompatibleTypes)
        .value("eExprStatus_MethodRequired", ExprStatus_MethodRequired)
        .value("eExprStatus_InstanceMethodRequired", ExprStatus_InstanceMethodRequired)
        .value("eExprStatus_StaticMethodRequired", ExprStatus_StaticMethodRequired)
        .value("eExprStatus_InvalidTypesForDivision", ExprStatus_InvalidTypesForDivision)
        .value("eExprStatus_DivideByZero", ExprStatus_DivideByZero)
        .value("eExprStatus_WrongNumberOfArguments", ExprStatus_WrongNumberOfArguments)
        .value("eExprStatus_IndexOutOfRange", ExprStatus_IndexOutOfRange)
        .value("eExprStatus_IncompatibleUnits", ExprStatus_IncompatibleUnits)
        .export_values();
    }