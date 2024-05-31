from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyECObjects

class ArrayECProperty:
    """
    None
    """

    def AsArrayProperty(*args, **kwargs):
        """
        AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty
        """
        ...
    
    def AsPrimitiveProperty(*args, **kwargs):
        """
        AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty
        """
        ...
    
    def AsStructProperty(*args, **kwargs):
        """
        AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty
        """
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetBaseProperty(*args, **kwargs):
        """
        GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECProperty) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetIsArray(*args, **kwargs):
        """
        GetIsArray(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsPrimitive(*args, **kwargs):
        """
        GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsReadOnly(*args, **kwargs):
        """
        GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsStruct(*args, **kwargs):
        """
        GetIsStruct(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetKind(*args, **kwargs):
        """
        GetKind(self: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.ArrayKind
        """
        ...
    
    def GetMaxOccurs(*args, **kwargs):
        """
        GetMaxOccurs(self: MSPyECObjects.ArrayECProperty) -> int
        """
        ...
    
    def GetMinOccurs(*args, **kwargs):
        """
        GetMinOccurs(self: MSPyECObjects.ArrayECProperty) -> int
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetPrimitiveElementType(*args, **kwargs):
        """
        GetPrimitiveElementType(self: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.PrimitiveType
        """
        ...
    
    def GetStructElementType(*args, **kwargs):
        """
        GetStructElementType(self: MSPyECObjects.ArrayECProperty) -> Bentley.ECN.ECClass
        """
        ...
    
    def GetTypeName(*args, **kwargs):
        """
        GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECProperty) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def IsArray(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsCalculated(*args, **kwargs):
        """
        IsCalculated(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsPrimitive(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsReadOnly(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    @IsReadOnly.setter
    def IsReadOnly(arg0: MSPyECObjects.ECProperty, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsStruct(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def Kind(arg0: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.ArrayKind:
        ...
    
    @property
    def MaxOccurs(arg0: MSPyECObjects.ArrayECProperty) -> int:
        ...
    @MaxOccurs.setter
    def MaxOccurs(arg0: MSPyECObjects.ArrayECProperty, arg1: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def MinOccurs(arg0: MSPyECObjects.ArrayECProperty) -> int:
        ...
    @MinOccurs.setter
    def MinOccurs(arg0: MSPyECObjects.ArrayECProperty, arg1: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def PrimitiveElementType(arg0: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.PrimitiveType:
        ...
    @PrimitiveElementType.setter
    def PrimitiveElementType(arg0: MSPyECObjects.ArrayECProperty, arg1: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(*args, **kwargs):
        """
        SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCalculatedPropertySpecification(*args, **kwargs):
        """
        SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool
        """
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        SetIsReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetMaxOccurs(*args, **kwargs):
        """
        SetMaxOccurs(self: MSPyECObjects.ArrayECProperty, maxOccurs: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetMinOccurs(*args, **kwargs):
        """
        SetMinOccurs(self: MSPyECObjects.ArrayECProperty, minOccurs: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetPrimitiveElementType(*args, **kwargs):
        """
        SetPrimitiveElementType(self: MSPyECObjects.ArrayECProperty, type: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetStructElementType(*args, **kwargs):
        """
        SetStructElementType(self: MSPyECObjects.ArrayECProperty, type: Bentley.ECN.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTypeName(*args, **kwargs):
        """
        SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def StructElementType(arg0: MSPyECObjects.ArrayECProperty) -> Bentley.ECN.ECClass:
        ...
    @StructElementType.setter
    def StructElementType(arg0: MSPyECObjects.ArrayECProperty, arg1: Bentley.ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def TypeName(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @TypeName.setter
    def TypeName(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ArrayInfo:
    """
    None
    """

    @property
    def Count(arg0: MSPyECObjects.ArrayInfo) -> int:
        ...
    
    @property
    def ElementPrimitiveType(arg0: MSPyECObjects.ArrayInfo) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetCount(*args, **kwargs):
        """
        GetCount(self: MSPyECObjects.ArrayInfo) -> int
        """
        ...
    
    def GetElementPrimitiveType(*args, **kwargs):
        """
        GetElementPrimitiveType(self: MSPyECObjects.ArrayInfo) -> MSPyECObjects.PrimitiveType
        """
        ...
    
    def GetKind(*args, **kwargs):
        """
        GetKind(self: MSPyECObjects.ArrayInfo) -> MSPyECObjects.ValueKind
        """
        ...
    
    def IsFixedCount(*args, **kwargs):
        """
        IsFixedCount(self: MSPyECObjects.ArrayInfo) -> bool
        """
        ...
    
    def IsPrimitiveArray(*args, **kwargs):
        """
        IsPrimitiveArray(self: MSPyECObjects.ArrayInfo) -> bool
        """
        ...
    
    def IsStructArray(*args, **kwargs):
        """
        IsStructArray(self: MSPyECObjects.ArrayInfo) -> bool
        """
        ...
    
    @property
    def Kind(arg0: MSPyECObjects.ArrayInfo) -> MSPyECObjects.ValueKind:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ArrayKind:
    """
    Members:
    
    eARRAYKIND_Primitive
    
    eARRAYKIND_Struct
    """

    def __init__(self: MSPyECObjects.ArrayKind, value: int) -> None:
        ...
    
    eARRAYKIND_Primitive: ArrayKind
    
    eARRAYKIND_Struct: ArrayKind
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ArrayKind) -> int:
        ...
    
class ArrayModifierFlags:
    """
    Members:
    
    ePROPERTYLAYOUTMODIFIERFLAGS_None
    
    ePROPERTYLAYOUTMODIFIERFLAGS_IsArrayFixedCount
    
    ePROPERTYLAYOUTMODIFIERFLAGS_IsReadOnly
    
    ePROPERTYLAYOUTMODIFIERFLAGS_IsCalculated
    """

    def __init__(self: MSPyECObjects.ArrayModifierFlags, value: int) -> None:
        ...
    
    ePROPERTYLAYOUTMODIFIERFLAGS_IsArrayFixedCount: ArrayModifierFlags
    
    ePROPERTYLAYOUTMODIFIERFLAGS_IsCalculated: ArrayModifierFlags
    
    ePROPERTYLAYOUTMODIFIERFLAGS_IsReadOnly: ArrayModifierFlags
    
    ePROPERTYLAYOUTMODIFIERFLAGS_None: ArrayModifierFlags
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ArrayModifierFlags) -> int:
        ...
    
class CategorySortPriority:
    """
    Members:
    
    eVeryHigh
    
    eHigh
    
    eMedium
    
    eLow
    
    eVeryLow
    """

    def __init__(self: MSPyECObjects.CategorySortPriority, value: int) -> None:
        ...
    
    eHigh: CategorySortPriority
    
    eLow: CategorySortPriority
    
    eMedium: CategorySortPriority
    
    eVeryHigh: CategorySortPriority
    
    eVeryLow: CategorySortPriority
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.CategorySortPriority) -> int:
        ...
    
class ClassLayout:
    """
    None
    """

    def BuildFromClass(*args, **kwargs):
        """
        BuildFromClass(ecClass: Bentley.ECN.ECClass) -> MSPyECObjects.ClassLayout
        
        Given a class, will create the ClassLayout that manages that class
        
        Parameter ``ecClass``:
        The ECClass to build the ClassLayout from
        
        Returns:
        ClassLayout pointer managing this ECClass
        """
        ...
    
    def CalculateBytesUsed(*args, **kwargs):
        """
        CalculateBytesUsed(self: MSPyECObjects.ClassLayout, propertyData: bytes) -> int
        
        Determines the number of bytes used for property data, so far
        """
        ...
    
    @property
    def Checksum(arg0: MSPyECObjects.ClassLayout) -> int:
        ...
    
    def CreateEmpty(*args, **kwargs):
        """
        CreateEmpty(className: str) -> MSPyECObjects.ClassLayout
        
        Creates an empty ClassLayout for a class with the given name
        
        Parameter ``className``:
        The name of the class that this ClassLayout will define
        """
        ...
    
    @property
    def ECClassName(arg0: MSPyECObjects.ClassLayout) -> MSPyBentley.WString:
        ...
    
    def GetChecksum(*args, **kwargs):
        """
        GetChecksum(self: MSPyECObjects.ClassLayout) -> int
        
        Returns the checksum for this ClassLayout
        """
        ...
    
    def GetECClassName(*args, **kwargs):
        """
        GetECClassName(self: MSPyECObjects.ClassLayout) -> MSPyBentley.WString
        
        Returns the name of the ECClass that this ClassLayout manages
        """
        ...
    
    def GetECPointerIndex(*args, **kwargs):
        """
        GetECPointerIndex(self: MSPyECObjects.ClassLayout, end: Bentley.ECN.ECRelationshipEnd) -> int
        
        Returns the property index of the given relationship end
        
        Parameter ``end``:
        The ECRelationshipEnd for which to get the pointer index
        
        Returns:
        The property index of the pointer for the given relationship end
        """
        ...
    
    def GetPropertyCount(*args, **kwargs):
        """
        GetPropertyCount(self: MSPyECObjects.ClassLayout) -> int
        
        Returns the number of properties this ClassLayout manages
        """
        ...
    
    def GetPropertyCountExcludingEmbeddedStructs(*args, **kwargs):
        """
        GetPropertyCountExcludingEmbeddedStructs(self: MSPyECObjects.ClassLayout) -> int
        
        Returns the number of properties this ClassLayout manages, not
        counting embedded structs
        """
        ...
    
    def GetPropertyIndex(*args, **kwargs):
        """
        GetPropertyIndex(self: MSPyECObjects.ClassLayout, accessString: str) -> tuple
        
        Given an access string, will return the property index within the
        ClassLayout
        
        
        Parameter ``accessString``:
        The access string for the desired property
        
        Returns(Tuple, 0):
        ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
        ECOBJECTS_STATUS_Success otherwise
        
        Returns (Tuple, 1):
        propertyIndex.  Will contain the index of the given property within the
        ClassLayout, if found
        """
        ...
    
    def GetPropertyLayout(*args, **kwargs):
        """
        GetPropertyLayout(self: MSPyECObjects.ClassLayout, accessString: str) -> tuple
        
        Given a property access string, will return the PropertyLayout
        
        Parameter ``propertyLayout``:
        Will point to the PropertyLayout if found
        
        Parameter ``accessString``:
        The access string for the desired property
        
        Returns:
        ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
        ECOBJECTS_STATUS_Success otherwise
        """
        ...
    
    def GetPropertyLayoutByIndex(*args, **kwargs):
        """
        GetPropertyLayoutByIndex(self: MSPyECObjects.ClassLayout, propertyIndex: int) -> tuple
        
        Given a property index, will return the PropertyLayout
        
        Parameter ``propertyLayout``:
        Will point to the PropertyLayout if found
        
        Parameter ``propertyIndex``:
        The index in the ClassLayout of the desired property
        
        Returns:
        ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
        ECOBJECTS_STATUS_Success otherwise
        """
        ...
    
    def GetPropertyLayoutIndex(*args, **kwargs):
        """
        GetPropertyLayoutIndex(self: MSPyECObjects.ClassLayout, propertyLayout: MSPyECObjects.PropertyLayout) -> tuple
        
        Given a property layout, will return the property index within the
        ClassLayout
        
        
        Parameter ``propertyLayout``:
        The propertyLayout of the property that we want the index for
        
        Returns(Tuple, 0):
        ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
        ECOBJECTS_STATUS_Success otherwise
        
        Returns (Tuple, 1):
        propertyIndex.    Will contain the index of the given property within the
        ClassLayout, if found
        """
        ...
    
    def IsCompatible(*args, **kwargs):
        """
        IsCompatible(self: MSPyECObjects.ClassLayout, layout: MSPyECObjects.ClassLayout) -> bool
        
        Checks the given classLayout to see if it is equal to, or a subset of,
        this layout
        
        Parameter ``layout``:
        The ClassLayout to test compatibility of
        
        Returns:
        true if the given ClassLayout is equal to or a subset of this
        layout, false otherwise
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        IsPropertyReadOnly(self: MSPyECObjects.ClassLayout, propertyIndex: int) -> bool
        
        Given a propertyIndex, will return whether the property is read-only
        or not
        
        Parameter ``propertyIndex``:
        The index within the ClassLayout of the property to check
        
        Returns:
        true if the property is read-only, false otherwise
        """
        ...
    
    @property
    def PropertyCount(arg0: MSPyECObjects.ClassLayout) -> int:
        ...
    
    @property
    def PropertyCountExcludingEmbeddedStructs(arg0: MSPyECObjects.ClassLayout) -> int:
        ...
    
    def SetPropertyReadOnly(*args, **kwargs):
        """
        SetPropertyReadOnly(self: MSPyECObjects.ClassLayout, propertyIndex: int, readOnly: bool) -> bool
        
        Sets the read-only status of a property, given its index within the
        ClassLayout
        
        Parameter ``propertyIndex``:
        The index within the ClassLayout of the property to set the read-
        only flag for
        
        Parameter ``readOnly``:
        Flag indicating whether this property is read-only
        
        Returns:
        The value of readOnly if successfully set, otherwise false
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.ClassLayout) -> MSPyBentley.WString
        
        Returns a string containing a description of the class and its
        properties
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ContextSymbol:
    """
    None
    """

    def __init__(self: MSPyECObjects.ContextSymbol, name: str, context: MSPyECObjects.ExpressionContext) -> None:
        ...
    
class CustomStructSerializerManager:
    """
    None
    """

    def AddCustomSerializer(*args, **kwargs):
        """
        AddCustomSerializer(self: MSPyECObjects.CustomStructSerializerManager, serializerName: str, serializer: MSPyECObjects.ICustomECStructSerializer) -> Bentley.BentleyStatus
        """
        ...
    
    def GetCustomSerializer(*args, **kwargs):
        """
        GetCustomSerializer(self: MSPyECObjects.CustomStructSerializerManager, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ICustomECStructSerializer
        """
        ...
    
    def GetManager(*args, **kwargs):
        """
        GetManager() -> MSPyECObjects.CustomStructSerializerManager
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DateTimeInfo:
    """
    None
    """

    Default: BeDateTimeInfo
    
    def GetDefault(*args, **kwargs):
        """
        GetDefault() -> MSPyBentley.BeDateTimeInfo
        """
        ...
    
    def GetInfo(*args, **kwargs):
        """
        GetInfo(self: MSPyECObjects.DateTimeInfo, useDefaultIfUnset: bool) -> MSPyBentley.BeDateTimeInfo
        """
        ...
    
    def IsComponentNull(*args, **kwargs):
        """
        IsComponentNull(self: MSPyECObjects.DateTimeInfo) -> bool
        """
        ...
    
    def IsKindNull(*args, **kwargs):
        """
        IsKindNull(self: MSPyECObjects.DateTimeInfo) -> bool
        """
        ...
    
    def IsMatchedBy(*args, **kwargs):
        """
        IsMatchedBy(self: MSPyECObjects.DateTimeInfo, arg0: MSPyBentley.BeDateTimeInfo) -> bool
        
        rhs
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.DateTimeInfo) -> MSPyBentley.WString
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DateTimeInfo) -> None
        
        2. __init__(self: MSPyECObjects.DateTimeInfo, metadata: MSPyBentley.BeDateTimeInfo) -> None
        """
        ...
    
class ECClass:
    """
    None
    """

    def AddBaseClass(*args, **kwargs):
        """
        AddBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def BaseClasses(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def ClassesAreEqualByName(*args, **kwargs):
        """
        ClassesAreEqualByName(currentBaseClass: MSPyECObjects.ECClass, arg: capsule) -> bool
        """
        ...
    
    def CreateArrayProperty(*args, **kwargs):
        """
        CreateArrayProperty(*args, **kwargs)
        Overloaded function.
        
        1. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        
        3. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, structType: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    def CreatePrimitiveProperty(*args, **kwargs):
        """
        CreatePrimitiveProperty(*args, **kwargs)
        Overloaded function.
        
        1. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        """
        ...
    
    def CreateStructProperty(*args, **kwargs):
        """
        CreateStructProperty(*args, **kwargs)
        Overloaded function.
        
        1. CreateStructProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreateStructProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, structType: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    @property
    def DefaultStandaloneEnabler(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    @property
    def DerivedClasses(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECClass, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECClass, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def FullName(arg0: MSPyECObjects.ECClass) -> str:
        ...
    
    def GetBaseClasses(*args, **kwargs):
        """
        GetBaseClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetDefaultStandaloneEnabler(*args, **kwargs):
        """
        GetDefaultStandaloneEnabler(self: MSPyECObjects.ECClass) -> Bentley.ECN.StandaloneECEnabler
        """
        ...
    
    def GetDerivedClasses(*args, **kwargs):
        """
        GetDerivedClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetFullName(*args, **kwargs):
        """
        GetFullName(self: MSPyECObjects.ECClass) -> str
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECClass) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetIsCustomAttributeClass(*args, **kwargs):
        """
        GetIsCustomAttributeClass(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsDomainClass(*args, **kwargs):
        """
        GetIsDomainClass(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsFinal(*args, **kwargs):
        """
        GetIsFinal(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsStruct(*args, **kwargs):
        """
        GetIsStruct(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetProperties(*args, **kwargs):
        """
        GetProperties(*args, **kwargs)
        Overloaded function.
        
        1. GetProperties(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable
        
        2. GetProperties(self: MSPyECObjects.ECClass, includeBaseProperties: bool) -> MSPyECObjects.ECPropertyIterable
        """
        ...
    
    def GetProperty(*args, **kwargs):
        """
        GetProperty(*args, **kwargs)
        Overloaded function.
        
        1. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        2. GetProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        3. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetPropertyCount(*args, **kwargs):
        """
        GetPropertyCount(self: MSPyECObjects.ECClass, includeBaseProperties: bool = True) -> int
        """
        ...
    
    def GetQualifiedClassName(*args, **kwargs):
        """
        GetQualifiedClassName(primarySchema: Bentley.ECN.ECSchema, ecClass: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetRelationshipClass(*args, **kwargs):
        """
        GetRelationshipClass(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass
        """
        ...
    
    def GetSchema(*args, **kwargs):
        """
        GetSchema(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema
        """
        ...
    
    def HasBaseClasses(*args, **kwargs):
        """
        HasBaseClasses(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECClass) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def Is(*args, **kwargs):
        """
        Is(*args, **kwargs)
        Overloaded function.
        
        1. Is(self: MSPyECObjects.ECClass, targetClass: MSPyECObjects.ECClass) -> bool
        
        2. Is(self: MSPyECObjects.ECClass, name: str) -> bool
        
        3. Is(self: MSPyECObjects.ECClass, schemaName: str, className: str) -> bool
        """
        ...
    
    @property
    def IsCustomAttributeClass(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsCustomAttributeClass.setter
    def IsCustomAttributeClass(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    
    @property
    def IsDomainClass(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsDomainClass.setter
    def IsDomainClass(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsFinal(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsFinal.setter
    def IsFinal(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsStruct(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsStruct.setter
    def IsStruct(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def ParseClassName(*args, **kwargs):
        """
        ParseClassName(prefix: MSPyBentley.WString, className: MSPyBentley.WString, qualifiedClassName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Properties(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass:
        ...
    
    def RemoveBaseClass(*args, **kwargs):
        """
        RemoveBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def RemoveProperty(*args, **kwargs):
        """
        RemoveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Schema(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema:
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECClass, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECClass, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsCustomAttributeClass(*args, **kwargs):
        """
        SetIsCustomAttributeClass(*args, **kwargs)
        Overloaded function.
        
        1. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, isCustomAttribute: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsDomainClass(*args, **kwargs):
        """
        SetIsDomainClass(*args, **kwargs)
        Overloaded function.
        
        1. SetIsDomainClass(self: MSPyECObjects.ECClass, isDomainClass: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsDomainClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsFinal(*args, **kwargs):
        """
        SetIsFinal(*args, **kwargs)
        Overloaded function.
        
        1. SetIsFinal(self: MSPyECObjects.ECClass, isFinal: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsFinal(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsStruct(*args, **kwargs):
        """
        SetIsStruct(*args, **kwargs)
        Overloaded function.
        
        1. SetIsStruct(self: MSPyECObjects.ECClass, isStruct: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsStruct(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECClassCPArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECClassCPArray) -> None
        
        2. __init__(self: MSPyECObjects.ECClassCPArray, arg0: int) -> None
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.ECClassCPArray) -> None
        """
        ...
    
    def push_back(*args, **kwargs):
        """
        push_back(self: MSPyECObjects.ECClassCPArray, newItem: MSPyECObjects.ECClass) -> None
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.ECClassCPArray, arg0: MSPyECObjects.ECClass) -> None
        """
        ...
    
    def resize(*args, **kwargs):
        """
        resize(self: MSPyECObjects.ECClassCPArray, newSize: int) -> None
        """
        ...
    
class ECClassContainer:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECClassPArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECClassPArray) -> None
        
        2. __init__(self: MSPyECObjects.ECClassPArray, arg0: int) -> None
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.ECClassPArray) -> None
        """
        ...
    
    def push_back(*args, **kwargs):
        """
        push_back(self: MSPyECObjects.ECClassPArray, newItem: MSPyECObjects.ECClass) -> None
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.ECClassPArray, arg0: MSPyECObjects.ECClass) -> None
        """
        ...
    
    def resize(*args, **kwargs):
        """
        resize(self: MSPyECObjects.ECClassPArray, newSize: int) -> None
        """
        ...
    
class ECCustomAttributeInstanceIterable:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECDBuffer:
    """
    None
    """

    def ClearValues(*args, **kwargs):
        """
        ClearValues(self: MSPyECObjects.ECDBuffer) -> None
        
        Sets all values to null
        """
        ...
    
    def CopyFromBuffer(*args, **kwargs):
        """
        CopyFromBuffer(self: MSPyECObjects.ECDBuffer, source: MSPyECObjects.ECDBuffer) -> MSPyECObjects.ECObjectsStatus
        
        Attempts to copy property values from source buffer. Expects source to
        have a compatible class layout.
        
        Parameter ``source``:
        The ECDBuffer to copy values from
        """
        ...
    
    def IsEmpty(*args, **kwargs):
        """
        IsEmpty(self: MSPyECObjects.ECDBuffer) -> bool
        
        Returns true if the buffer is empty (all values are null and all
        arrays are empty)
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECEnabler:
    """
    None
    """

    @property
    def Class(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetEnablerForStructArrayMember(*args, **kwargs):
        """
        GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler
        """
        ...
    
    def GetFirstPropertyIndex(*args, **kwargs):
        """
        GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECEnabler) -> str
        """
        ...
    
    def GetNextPropertyIndex(*args, **kwargs):
        """
        GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int
        """
        ...
    
    def GetParentPropertyIndex(*args, **kwargs):
        """
        GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int
        """
        ...
    
    def GetPropertyIndex(*args, **kwargs):
        """
        GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple
        """
        ...
    
    def GetPropertyIndices(*args, **kwargs):
        """
        GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentley.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetStandaloneEnablerLocater(*args, **kwargs):
        """
        GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater
        """
        ...
    
    def HasChildProperties(*args, **kwargs):
        """
        HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECEnabler) -> str:
        ...
    
    @property
    def StandaloneEnablerLocater(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECErrorCategories:
    """
    Members:
    
    eECOBJECTS_ERROR_BASE
    
    eSCHEMA_READ_STATUS_BASE
    
    eSCHEMA_WRITE_STATUS_BASE
    
    eINSTANCE_READ_STATUS_BASE
    
    eINSTANCE_WRITE_STATUS_BASE
    
    eSUPPLEMENTED_SCHEMA_STATUS_BASE
    """

    def __init__(self: MSPyECObjects.ECErrorCategories, value: int) -> None:
        ...
    
    eECOBJECTS_ERROR_BASE: ECErrorCategories
    
    eINSTANCE_READ_STATUS_BASE: ECErrorCategories
    
    eINSTANCE_WRITE_STATUS_BASE: ECErrorCategories
    
    eSCHEMA_READ_STATUS_BASE: ECErrorCategories
    
    eSCHEMA_WRITE_STATUS_BASE: ECErrorCategories
    
    eSUPPLEMENTED_SCHEMA_STATUS_BASE: ECErrorCategories
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECErrorCategories) -> int:
        ...
    
class ECImageKey:
    """
    None
    """

    def GetIconId(*args, **kwargs):
        """
        GetIconId(self: MSPyECObjects.ECImageKey) -> int
        """
        ...
    
    def GetIconType(*args, **kwargs):
        """
        GetIconType(self: MSPyECObjects.ECImageKey) -> int
        """
        ...
    
    def GetImageName(*args, **kwargs):
        """
        GetImageName(self: MSPyECObjects.ECImageKey) -> MSPyBentley.WString
        """
        ...
    
    def GetImageType(*args, **kwargs):
        """
        GetImageType(self: MSPyECObjects.ECImageKey) -> MSPyECObjects.ECImageKey.ImageType
        """
        ...
    
    @property
    def IconId(arg0: MSPyECObjects.ECImageKey) -> int:
        ...
    @IconId.setter
    def IconId(arg0: MSPyECObjects.ECImageKey, arg1: int) -> None:
        ...
    
    @property
    def IconType(arg0: MSPyECObjects.ECImageKey) -> int:
        ...
    @IconType.setter
    def IconType(arg0: MSPyECObjects.ECImageKey, arg1: int) -> None:
        ...
    
    @property
    def ImageName(arg0: MSPyECObjects.ECImageKey) -> MSPyBentley.WString:
        ...
    @ImageName.setter
    def ImageName(arg0: MSPyECObjects.ECImageKey, arg1: MSPyBentley.WString) -> None:
        ...
    
    @property
    def ImageType(arg0: MSPyECObjects.ECImageKey) -> MSPyECObjects.ECImageKey.ImageType:
        ...
    @ImageType.setter
    def ImageType(arg0: MSPyECObjects.ECImageKey, arg1: MSPyECObjects.ECImageKey.ImageType) -> None:
        ...
    
    def SetIconId(*args, **kwargs):
        """
        SetIconId(self: MSPyECObjects.ECImageKey, rscId: int) -> None
        """
        ...
    
    def SetIconType(*args, **kwargs):
        """
        SetIconType(self: MSPyECObjects.ECImageKey, iconType: int) -> None
        """
        ...
    
    def SetImageName(*args, **kwargs):
        """
        SetImageName(self: MSPyECObjects.ECImageKey, name: MSPyBentley.WString) -> None
        """
        ...
    
    def SetImageType(*args, **kwargs):
        """
        SetImageType(self: MSPyECObjects.ECImageKey, type: MSPyECObjects.ECImageKey.ImageType) -> None
        """
        ...
    
    def __init__(self: MSPyECObjects.ECImageKey, name: MSPyBentley.WString, type: MSPyECObjects.ECImageKey.ImageType) -> None:
        ...
    
    eBitmap: ImageType
    
    eCursor: ImageType
    
    eIcon: ImageType
    
    eRscIcon: ImageType
    
class ECInstanceIterable:
    """
    None
    """

    def __init__(self: MSPyECObjects.ECInstanceIterable) -> None:
        ...
    
class ECInstanceReadContext:
    """
    None
    """

    def CreateContext(*args, **kwargs):
        """
        CreateContext(*args, **kwargs)
        Overloaded function.
        
        1. CreateContext(ecSchema: Bentley.ECN.ECSchema, locator: Bentley.ECN.IStandaloneEnablerLocater = None, typeResolver: MSPyECObjects.IPrimitiveTypeResolver = None) -> MSPyECObjects.ECInstanceReadContext
        
        - For use when the caller knows the schema of the instance he is
        deserializing.
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        foundSchema.
        
        
        
        2. CreateContext(readContext: MSPyECObjects.ECSchemaReadContext, fallbackSchema: Bentley.ECN.ECSchema) -> tuple
        
        - For use when the caller knows the schema of the instance he is
        deserializing.
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        foundSchema.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECNameValidation:
    """
    None
    """

    def DecodeFromValidName(*args, **kwargs):
        """
        DecodeFromValidName(decoded: MSPyBentley.WString, name: MSPyBentley.WString) -> bool
        """
        ...
    
    def EncodeToValidName(*args, **kwargs):
        """
        EncodeToValidName(encoded: MSPyBentley.WString, name: MSPyBentley.WString) -> bool
        """
        ...
    
    def IsValidAlphaNumericCharacter(*args, **kwargs):
        """
        IsValidAlphaNumericCharacter(char: str) -> bool
        """
        ...
    
    def IsValidName(*args, **kwargs):
        """
        IsValidName(name: str) -> bool
        """
        ...
    
    def Validate(*args, **kwargs):
        """
        Validate(name: str) -> MSPyECObjects.ECNameValidation.ValidationResult
        """
        ...
    
    class ValidationResult:
        """
        Members:
        
        eRESULT_Valid
        
        eRESULT_NullOrEmpty
        
        eRESULT_BeginsWithDigit
        
        eRESULT_IncludesInvalidCharacters
        """
    
        def __init__(self: MSPyECObjects.ECNameValidation.ValidationResult, value: int) -> None:
            ...
        
        eRESULT_BeginsWithDigit: ValidationResult
        
        eRESULT_IncludesInvalidCharacters: ValidationResult
        
        eRESULT_NullOrEmpty: ValidationResult
        
        eRESULT_Valid: ValidationResult
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ECNameValidation.ValidationResult) -> int:
            ...
        
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eRESULT_BeginsWithDigit: ValidationResult
    
    eRESULT_IncludesInvalidCharacters: ValidationResult
    
    eRESULT_NullOrEmpty: ValidationResult
    
    eRESULT_Valid: ValidationResult
    
class ECObjectsStatus:
    """
    Members:
    
    eECOBJECTS_STATUS_Success
    
    eECOBJECTS_STATUS_PropertyNotFound
    
    eECOBJECTS_STATUS_DataTypeMismatch
    
    eECOBJECTS_STATUS_ECInstanceImplementationNotSupported
    
    eECOBJECTS_STATUS_InvalidPropertyAccessString
    
    eECOBJECTS_STATUS_IndexOutOfRange
    
    eECOBJECTS_STATUS_ECClassNotSupported
    
    eECOBJECTS_STATUS_ECSchemaNotSupported
    
    eECOBJECTS_STATUS_AccessStringDisagreesWithNIndices
    
    eECOBJECTS_STATUS_EnablerNotFound
    
    eECOBJECTS_STATUS_OperationNotSupported
    
    eECOBJECTS_STATUS_ParseError
    
    eECOBJECTS_STATUS_NamedItemAlreadyExists
    
    eECOBJECTS_STATUS_PreconditionViolated
    
    eECOBJECTS_STATUS_SchemaNotFound
    
    eECOBJECTS_STATUS_ClassNotFound
    
    eECOBJECTS_STATUS_BaseClassUnacceptable
    
    eECOBJECTS_STATUS_SchemaInUse
    
    eECOBJECTS_STATUS_InvalidName
    
    eECOBJECTS_STATUS_DataTypeNotSupported
    
    eECOBJECTS_STATUS_UnableToAllocateMemory
    
    eECOBJECTS_STATUS_MemoryBoundsOverrun
    
    eECOBJECTS_STATUS_NullPointerValue
    
    eECOBJECTS_STATUS_NotCustomAttributeClass
    
    eECOBJECTS_STATUS_DuplicateSchema
    
    eECOBJECTS_STATUS_UnableToSetReadOnlyInstance
    
    eECOBJECTS_STATUS_UnableToSetReadOnlyProperty
    
    eECOBJECTS_STATUS_ArrayIndexDoesNotExist
    
    eECOBJECTS_STATUS_PropertyValueMatchesNoChange
    
    eECOBJECTS_STATUS_NoChildProperties
    
    eECOBJECTS_STATUS_UnableToAllocateManagedMemory
    
    eECOBJECTS_STATUS_MemoryAllocationCallbackRequired
    
    eECOBJECTS_STATUS_UnableToAddStructArrayMember
    
    eECOBJECTS_STATUS_UnableToSetStructArrayMemberInstance
    
    eECOBJECTS_STATUS_UnableToGetStructArrayMemberInstance
    
    eECOBJECTS_STATUS_InvalidIndexForPerPropertyFlag
    
    eECOBJECTS_STATUS_SchemaHasReferenceCycle
    
    eECOBJECTS_STATUS_SchemaNotSupplemented
    
    eECOBJECTS_STATUS_UnableToQueryForNullPropertyFlag
    
    eECOBJECTS_STATUS_UnableToResizeFixedSizedArray
    
    eECOBJECTS_STATUS_SchemaIsImmutable
    
    eECOBJECTS_STATUS_Error
    """

    def __init__(self: MSPyECObjects.ECObjectsStatus, value: int) -> None:
        ...
    
    eECOBJECTS_STATUS_AccessStringDisagreesWithNIndices: ECObjectsStatus
    
    eECOBJECTS_STATUS_ArrayIndexDoesNotExist: ECObjectsStatus
    
    eECOBJECTS_STATUS_BaseClassUnacceptable: ECObjectsStatus
    
    eECOBJECTS_STATUS_ClassNotFound: ECObjectsStatus
    
    eECOBJECTS_STATUS_DataTypeMismatch: ECObjectsStatus
    
    eECOBJECTS_STATUS_DataTypeNotSupported: ECObjectsStatus
    
    eECOBJECTS_STATUS_DuplicateSchema: ECObjectsStatus
    
    eECOBJECTS_STATUS_ECClassNotSupported: ECObjectsStatus
    
    eECOBJECTS_STATUS_ECInstanceImplementationNotSupported: ECObjectsStatus
    
    eECOBJECTS_STATUS_ECSchemaNotSupported: ECObjectsStatus
    
    eECOBJECTS_STATUS_EnablerNotFound: ECObjectsStatus
    
    eECOBJECTS_STATUS_Error: ECObjectsStatus
    
    eECOBJECTS_STATUS_IndexOutOfRange: ECObjectsStatus
    
    eECOBJECTS_STATUS_InvalidIndexForPerPropertyFlag: ECObjectsStatus
    
    eECOBJECTS_STATUS_InvalidName: ECObjectsStatus
    
    eECOBJECTS_STATUS_InvalidPropertyAccessString: ECObjectsStatus
    
    eECOBJECTS_STATUS_MemoryAllocationCallbackRequired: ECObjectsStatus
    
    eECOBJECTS_STATUS_MemoryBoundsOverrun: ECObjectsStatus
    
    eECOBJECTS_STATUS_NamedItemAlreadyExists: ECObjectsStatus
    
    eECOBJECTS_STATUS_NoChildProperties: ECObjectsStatus
    
    eECOBJECTS_STATUS_NotCustomAttributeClass: ECObjectsStatus
    
    eECOBJECTS_STATUS_NullPointerValue: ECObjectsStatus
    
    eECOBJECTS_STATUS_OperationNotSupported: ECObjectsStatus
    
    eECOBJECTS_STATUS_ParseError: ECObjectsStatus
    
    eECOBJECTS_STATUS_PreconditionViolated: ECObjectsStatus
    
    eECOBJECTS_STATUS_PropertyNotFound: ECObjectsStatus
    
    eECOBJECTS_STATUS_PropertyValueMatchesNoChange: ECObjectsStatus
    
    eECOBJECTS_STATUS_SchemaHasReferenceCycle: ECObjectsStatus
    
    eECOBJECTS_STATUS_SchemaInUse: ECObjectsStatus
    
    eECOBJECTS_STATUS_SchemaIsImmutable: ECObjectsStatus
    
    eECOBJECTS_STATUS_SchemaNotFound: ECObjectsStatus
    
    eECOBJECTS_STATUS_SchemaNotSupplemented: ECObjectsStatus
    
    eECOBJECTS_STATUS_Success: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToAddStructArrayMember: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToAllocateManagedMemory: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToAllocateMemory: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToGetStructArrayMemberInstance: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToQueryForNullPropertyFlag: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToResizeFixedSizedArray: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToSetReadOnlyInstance: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToSetReadOnlyProperty: ECObjectsStatus
    
    eECOBJECTS_STATUS_UnableToSetStructArrayMemberInstance: ECObjectsStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECObjectsStatus) -> int:
        ...
    
class ECProperty:
    """
    None
    """

    def AsArrayProperty(*args, **kwargs):
        """
        AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty
        """
        ...
    
    def AsPrimitiveProperty(*args, **kwargs):
        """
        AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty
        """
        ...
    
    def AsStructProperty(*args, **kwargs):
        """
        AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty
        """
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetBaseProperty(*args, **kwargs):
        """
        GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECProperty) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetIsArray(*args, **kwargs):
        """
        GetIsArray(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsPrimitive(*args, **kwargs):
        """
        GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsReadOnly(*args, **kwargs):
        """
        GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsStruct(*args, **kwargs):
        """
        GetIsStruct(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetTypeName(*args, **kwargs):
        """
        GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECProperty) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def IsArray(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsCalculated(*args, **kwargs):
        """
        IsCalculated(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsPrimitive(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsReadOnly(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    @IsReadOnly.setter
    def IsReadOnly(arg0: MSPyECObjects.ECProperty, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsStruct(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(*args, **kwargs):
        """
        SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCalculatedPropertySpecification(*args, **kwargs):
        """
        SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool
        """
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        SetIsReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTypeName(*args, **kwargs):
        """
        SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def TypeName(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @TypeName.setter
    def TypeName(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECPropertyIterable:
    """
    None
    """

    def FindByDisplayLabel(*args, **kwargs):
        """
        FindByDisplayLabel(self: MSPyECObjects.ECPropertyIterable, label: str) -> MSPyECObjects.ECProperty
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECPropertyValue:
    """
    None
    """

    @property
    def ChildValues(arg0: MSPyECObjects.ECPropertyValue) -> Bentley.ECN.ECValuesCollection:
        ...
    
    def GetChildValues(*args, **kwargs):
        """
        GetChildValues(self: MSPyECObjects.ECPropertyValue) -> Bentley.ECN.ECValuesCollection
        """
        ...
    
    def GetInstance(*args, **kwargs):
        """
        GetInstance(self: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetPropertyValue(*args, **kwargs):
        """
        GetPropertyValue(instance: MSPyECObjects.IECInstance, propertyAccessor: str) -> MSPyECObjects.ECPropertyValue
        """
        ...
    
    def GetValue(*args, **kwargs):
        """
        GetValue(self: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValue
        """
        ...
    
    def GetValueAccessor(*args, **kwargs):
        """
        GetValueAccessor(self: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValueAccessor
        """
        ...
    
    def HasChildValues(*args, **kwargs):
        """
        HasChildValues(self: MSPyECObjects.ECPropertyValue) -> bool
        """
        ...
    
    @property
    def Instance(arg0: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.IECInstance:
        ...
    
    @property
    def Value(arg0: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValue:
        ...
    
    @property
    def ValueAccessor(arg0: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValueAccessor:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECRelatedInstanceDirection:
    """
    Members:
    
    eSTRENGTHDIRECTION_Forward
    
    eSTRENGTHDIRECTION_Backward
    """

    def __init__(self: MSPyECObjects.ECRelatedInstanceDirection, value: int) -> None:
        ...
    
    eSTRENGTHDIRECTION_Backward: ECRelatedInstanceDirection
    
    eSTRENGTHDIRECTION_Forward: ECRelatedInstanceDirection
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECRelatedInstanceDirection) -> int:
        ...
    
class ECRelationshipClass:
    """
    None
    """

    def AddBaseClass(*args, **kwargs):
        """
        AddBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def BaseClasses(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def ClassesAreEqualByName(*args, **kwargs):
        """
        ClassesAreEqualByName(currentBaseClass: MSPyECObjects.ECClass, arg: capsule) -> bool
        """
        ...
    
    def CreateArrayProperty(*args, **kwargs):
        """
        CreateArrayProperty(*args, **kwargs)
        Overloaded function.
        
        1. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        
        3. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, structType: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    def CreatePrimitiveProperty(*args, **kwargs):
        """
        CreatePrimitiveProperty(*args, **kwargs)
        Overloaded function.
        
        1. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        """
        ...
    
    def CreateStructProperty(*args, **kwargs):
        """
        CreateStructProperty(*args, **kwargs)
        Overloaded function.
        
        1. CreateStructProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreateStructProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, structType: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    @property
    def DefaultStandaloneEnabler(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    @property
    def DerivedClasses(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECClass, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECClass, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def FullName(arg0: MSPyECObjects.ECClass) -> str:
        ...
    
    def GetBaseClasses(*args, **kwargs):
        """
        GetBaseClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetDefaultStandaloneEnabler(*args, **kwargs):
        """
        GetDefaultStandaloneEnabler(self: MSPyECObjects.ECClass) -> Bentley.ECN.StandaloneECEnabler
        """
        ...
    
    def GetDerivedClasses(*args, **kwargs):
        """
        GetDerivedClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetFullName(*args, **kwargs):
        """
        GetFullName(self: MSPyECObjects.ECClass) -> str
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECClass) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetIsCustomAttributeClass(*args, **kwargs):
        """
        GetIsCustomAttributeClass(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsDomainClass(*args, **kwargs):
        """
        GetIsDomainClass(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsFinal(*args, **kwargs):
        """
        GetIsFinal(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetIsOrdered(*args, **kwargs):
        """
        GetIsOrdered(self: MSPyECObjects.ECRelationshipClass) -> bool
        """
        ...
    
    def GetIsStruct(*args, **kwargs):
        """
        GetIsStruct(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetOrderedRelationshipPropertyName(*args, **kwargs):
        """
        GetOrderedRelationshipPropertyName(self: MSPyECObjects.ECRelationshipClass, propertyName: MSPyBentley.WString, end: MSPyECObjects.ECRelationshipEnd) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetProperties(*args, **kwargs):
        """
        GetProperties(*args, **kwargs)
        Overloaded function.
        
        1. GetProperties(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable
        
        2. GetProperties(self: MSPyECObjects.ECClass, includeBaseProperties: bool) -> MSPyECObjects.ECPropertyIterable
        """
        ...
    
    def GetProperty(*args, **kwargs):
        """
        GetProperty(*args, **kwargs)
        Overloaded function.
        
        1. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        2. GetProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        3. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetPropertyCount(*args, **kwargs):
        """
        GetPropertyCount(self: MSPyECObjects.ECClass, includeBaseProperties: bool = True) -> int
        """
        ...
    
    def GetQualifiedClassName(*args, **kwargs):
        """
        GetQualifiedClassName(primarySchema: Bentley.ECN.ECSchema, ecClass: MSPyECObjects.ECClass) -> MSPyBentley.WString
        """
        ...
    
    def GetRelationshipClass(*args, **kwargs):
        """
        GetRelationshipClass(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass
        """
        ...
    
    def GetSchema(*args, **kwargs):
        """
        GetSchema(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema
        """
        ...
    
    def GetSource(*args, **kwargs):
        """
        GetSource(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelationshipConstraint
        """
        ...
    
    def GetStrength(*args, **kwargs):
        """
        GetStrength(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.StrengthType
        """
        ...
    
    def GetStrengthDirection(*args, **kwargs):
        """
        GetStrengthDirection(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelatedInstanceDirection
        """
        ...
    
    def GetTarget(*args, **kwargs):
        """
        GetTarget(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelationshipConstraint
        """
        ...
    
    def HasBaseClasses(*args, **kwargs):
        """
        HasBaseClasses(self: MSPyECObjects.ECClass) -> bool
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECClass) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def Is(*args, **kwargs):
        """
        Is(*args, **kwargs)
        Overloaded function.
        
        1. Is(self: MSPyECObjects.ECClass, targetClass: MSPyECObjects.ECClass) -> bool
        
        2. Is(self: MSPyECObjects.ECClass, name: str) -> bool
        
        3. Is(self: MSPyECObjects.ECClass, schemaName: str, className: str) -> bool
        """
        ...
    
    @property
    def IsCustomAttributeClass(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsCustomAttributeClass.setter
    def IsCustomAttributeClass(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    
    @property
    def IsDomainClass(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsDomainClass.setter
    def IsDomainClass(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsFinal(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsFinal.setter
    def IsFinal(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsOrdered(arg0: MSPyECObjects.ECRelationshipClass) -> bool:
        ...
    
    @property
    def IsStruct(arg0: MSPyECObjects.ECClass) -> bool:
        ...
    @IsStruct.setter
    def IsStruct(arg0: MSPyECObjects.ECClass, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def ParseClassName(*args, **kwargs):
        """
        ParseClassName(prefix: MSPyBentley.WString, className: MSPyBentley.WString, qualifiedClassName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Properties(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass:
        ...
    
    def RemoveBaseClass(*args, **kwargs):
        """
        RemoveBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def RemoveProperty(*args, **kwargs):
        """
        RemoveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Schema(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema:
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECClass, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECClass, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsCustomAttributeClass(*args, **kwargs):
        """
        SetIsCustomAttributeClass(*args, **kwargs)
        Overloaded function.
        
        1. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, isCustomAttribute: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsDomainClass(*args, **kwargs):
        """
        SetIsDomainClass(*args, **kwargs)
        Overloaded function.
        
        1. SetIsDomainClass(self: MSPyECObjects.ECClass, isDomainClass: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsDomainClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsFinal(*args, **kwargs):
        """
        SetIsFinal(*args, **kwargs)
        Overloaded function.
        
        1. SetIsFinal(self: MSPyECObjects.ECClass, isFinal: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsFinal(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsStruct(*args, **kwargs):
        """
        SetIsStruct(*args, **kwargs)
        Overloaded function.
        
        1. SetIsStruct(self: MSPyECObjects.ECClass, isStruct: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsStruct(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetStrength(*args, **kwargs):
        """
        SetStrength(self: MSPyECObjects.ECRelationshipClass, strength: MSPyECObjects.StrengthType) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetStrengthDirection(*args, **kwargs):
        """
        SetStrengthDirection(self: MSPyECObjects.ECRelationshipClass, dir: MSPyECObjects.ECRelatedInstanceDirection) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Source(arg0: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelationshipConstraint:
        ...
    
    @property
    def Strength(arg0: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.StrengthType:
        ...
    @Strength.setter
    def Strength(arg0: MSPyECObjects.ECRelationshipClass, arg1: MSPyECObjects.StrengthType) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def StrengthDirection(arg0: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelatedInstanceDirection:
        ...
    @StrengthDirection.setter
    def StrengthDirection(arg0: MSPyECObjects.ECRelationshipClass, arg1: MSPyECObjects.ECRelatedInstanceDirection) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Target(arg0: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelationshipConstraint:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECRelationshipConstraint:
    """
    None
    """

    def AddClass(*args, **kwargs):
        """
        AddClass(self: MSPyECObjects.ECRelationshipConstraint, classConstraint: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Cardinality(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.RelationshipCardinality:
        ...
    @Cardinality.setter
    def Cardinality(arg0: MSPyECObjects.ECRelationshipConstraint, arg1: MSPyECObjects.RelationshipCardinality) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Classes(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.ECClassPArray:
        ...
    
    def CopyTo(*args, **kwargs):
        """
        CopyTo(self: MSPyECObjects.ECRelationshipConstraint, toRelationshipConstraint: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetCardinality(*args, **kwargs):
        """
        GetCardinality(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.RelationshipCardinality
        """
        ...
    
    def GetClasses(*args, **kwargs):
        """
        GetClasses(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.ECClassPArray
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(self: MSPyECObjects.ECRelationshipConstraint, classDefiniton: MSPyECObjects.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetInvariantRoleLabel(*args, **kwargs):
        """
        GetInvariantRoleLabel(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString
        """
        ...
    
    def GetIsMultiple(*args, **kwargs):
        """
        GetIsMultiple(self: MSPyECObjects.ECRelationshipConstraint) -> bool
        """
        ...
    
    def GetIsOrdered(*args, **kwargs):
        """
        GetIsOrdered(self: MSPyECObjects.ECRelationshipConstraint) -> bool
        """
        ...
    
    def GetIsPolymorphic(*args, **kwargs):
        """
        GetIsPolymorphic(self: MSPyECObjects.ECRelationshipConstraint) -> bool
        """
        ...
    
    def GetOrderIdStorageMode(*args, **kwargs):
        """
        GetOrderIdStorageMode(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.OrderIdStorageMode
        """
        ...
    
    def GetOrderedRelationshipPropertyName(*args, **kwargs):
        """
        GetOrderedRelationshipPropertyName(self: MSPyECObjects.ECRelationshipConstraint, propertyName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetRoleLabel(*args, **kwargs):
        """
        GetRoleLabel(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString
        """
        ...
    
    @property
    def InvariantRoleLabel(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString:
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsMultiple(arg0: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    
    @property
    def IsOrdered(arg0: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    
    @property
    def IsPolymorphic(arg0: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    @IsPolymorphic.setter
    def IsPolymorphic(arg0: MSPyECObjects.ECRelationshipConstraint, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def IsRoleLabelDefined(*args, **kwargs):
        """
        IsRoleLabelDefined(self: MSPyECObjects.ECRelationshipConstraint) -> bool
        """
        ...
    
    @property
    def OrderIdStorageMode(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.OrderIdStorageMode:
        ...
    
    def RemoveClass(*args, **kwargs):
        """
        RemoveClass(self: MSPyECObjects.ECRelationshipConstraint, classConstraint: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def RoleLabel(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString:
        ...
    @RoleLabel.setter
    def RoleLabel(arg0: MSPyECObjects.ECRelationshipConstraint, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCardinality(*args, **kwargs):
        """
        SetCardinality(*args, **kwargs)
        Overloaded function.
        
        1. SetCardinality(self: MSPyECObjects.ECRelationshipConstraint, val: MSPyECObjects.RelationshipCardinality) -> MSPyECObjects.ECObjectsStatus
        
        2. SetCardinality(self: MSPyECObjects.ECRelationshipConstraint, cardinality: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.ECRelationshipConstraint, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsPolymorphic(*args, **kwargs):
        """
        SetIsPolymorphic(*args, **kwargs)
        Overloaded function.
        
        1. SetIsPolymorphic(self: MSPyECObjects.ECRelationshipConstraint, val: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsPolymorphic(self: MSPyECObjects.ECRelationshipConstraint, isPolymorphic: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetRoleLabel(*args, **kwargs):
        """
        SetRoleLabel(self: MSPyECObjects.ECRelationshipConstraint, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECRelationshipEnd:
    """
    Members:
    
    eECRelationshipEnd_Source
    
    eECRelationshipEnd_Target
    """

    def __init__(self: MSPyECObjects.ECRelationshipEnd, value: int) -> None:
        ...
    
    eECRelationshipEnd_Source: ECRelationshipEnd
    
    eECRelationshipEnd_Target: ECRelationshipEnd
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECRelationshipEnd) -> int:
        ...
    
class ECRelationshipIterable:
    """
    None
    """

    def __init__(self: MSPyECObjects.ECRelationshipIterable) -> None:
        ...
    
class ECSchema:
    """
    None
    """

    def AddReferencedSchema(*args, **kwargs):
        """
        AddReferencedSchema(*args, **kwargs)
        Overloaded function.
        
        1. AddReferencedSchema(self: MSPyECObjects.ECSchema, refSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.ECObjectsStatus
        
        2. AddReferencedSchema(self: MSPyECObjects.ECSchema, refSchema: MSPyECObjects.ECSchema, prefix: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def ClassCount(arg0: MSPyECObjects.ECSchema) -> int:
        ...
    
    @property
    def Classes(arg0: MSPyECObjects.ECSchema) -> MSPyECObjects.ECClassContainer:
        ...
    
    def ComputeSchemaXmlStringCheckSum(*args, **kwargs):
        """
        ComputeSchemaXmlStringCheckSum(str: str, len: int) -> int
        """
        ...
    
    def CopyClass(*args, **kwargs):
        """
        CopyClass(self: MSPyECObjects.ECSchema, sourceClass: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    def CopySchema(*args, **kwargs):
        """
        CopySchema(self: MSPyECObjects.ECSchema) -> tuple
        """
        ...
    
    def CreateClass(*args, **kwargs):
        """
        CreateClass(self: MSPyECObjects.ECSchema, name: MSPyBentley.WString) -> tuple
        """
        ...
    
    def CreateRelationshipClass(*args, **kwargs):
        """
        CreateRelationshipClass(self: MSPyECObjects.ECSchema, name: MSPyBentley.WString) -> tuple
        """
        ...
    
    def CreateSchema(*args, **kwargs):
        """
        CreateSchema(schemaName: MSPyBentley.WString, versionMajor: int, versionMinor: int) -> tuple
        """
        ...
    
    @property
    def CustomAttributeContainer(arg0: MSPyECObjects.ECSchema) -> MSPyECObjects.IECCustomAttributeContainer:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECSchema, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECSchema, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def FindAllSchemasInGraph(*args, **kwargs):
        """
        FindAllSchemasInGraph(self: MSPyECObjects.ECSchema, allSchemas: MSPyECObjects.ECSchemaPArray, includeRootSchema: bool = True) -> None
        """
        ...
    
    def FindSchema(*args, **kwargs):
        """
        FindSchema(self: MSPyECObjects.ECSchema, schemaKey: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType) -> MSPyECObjects.ECSchema
        """
        ...
    
    def FormatSchemaVersion(*args, **kwargs):
        """
        FormatSchemaVersion(versionMajor: int, versionMinor: int) -> MSPyBentley.WString
        """
        ...
    
    @property
    def FullSchemaName(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECSchema, name: str) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetClassCount(*args, **kwargs):
        """
        GetClassCount(self: MSPyECObjects.ECSchema) -> int
        """
        ...
    
    def GetClasses(*args, **kwargs):
        """
        GetClasses(self: MSPyECObjects.ECSchema) -> MSPyECObjects.ECClassContainer
        """
        ...
    
    def GetCustomAttributeContainer(*args, **kwargs):
        """
        GetCustomAttributeContainer(self: MSPyECObjects.ECSchema) -> MSPyECObjects.IECCustomAttributeContainer
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetFullSchemaName(*args, **kwargs):
        """
        GetFullSchemaName(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECSchema) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetNamespacePrefix(*args, **kwargs):
        """
        GetNamespacePrefix(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString
        """
        ...
    
    def GetReferencedSchemas(*args, **kwargs):
        """
        GetReferencedSchemas(self: MSPyECObjects.ECSchema) -> Bentley.ECN.SchemaMapExact
        """
        ...
    
    def GetSchemaByNamespacePrefix(*args, **kwargs):
        """
        GetSchemaByNamespacePrefix(self: MSPyECObjects.ECSchema, namespacePrefix: MSPyBentley.WString) -> MSPyECObjects.ECSchema
        """
        ...
    
    def GetSchemaKey(*args, **kwargs):
        """
        GetSchemaKey(self: MSPyECObjects.ECSchema) -> MSPyECObjects.SchemaKey
        """
        ...
    
    def GetSupplementalInfo(*args, **kwargs):
        """
        GetSupplementalInfo(self: MSPyECObjects.ECSchema) -> Bentley.ECN.SupplementalSchemaInfo
        """
        ...
    
    def GetVersionMajor(*args, **kwargs):
        """
        GetVersionMajor(self: MSPyECObjects.ECSchema) -> int
        """
        ...
    
    def GetVersionMinor(*args, **kwargs):
        """
        GetVersionMinor(self: MSPyECObjects.ECSchema) -> int
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECSchema) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECSchema) -> bool:
        ...
    
    def IsSamePrimarySchema(*args, **kwargs):
        """
        IsSamePrimarySchema(self: MSPyECObjects.ECSchema, primarySchema: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def IsSchemaReferenced(*args, **kwargs):
        """
        IsSchemaReferenced(thisSchema: MSPyECObjects.ECSchema, potentiallyReferencedSchema: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def IsStandardSchema(*args, **kwargs):
        """
        IsStandardSchema(self: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def IsSupplementalSchema(*args, **kwargs):
        """
        IsSupplementalSchema(self: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def IsSupplemented(*args, **kwargs):
        """
        IsSupplemented(self: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def LocateSchema(*args, **kwargs):
        """
        LocateSchema(schema: MSPyECObjects.SchemaKey, schemaContext: MSPyECObjects.ECSchemaReadContext) -> MSPyECObjects.ECSchema
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.ECSchema, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def NamespacePrefix(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    @NamespacePrefix.setter
    def NamespacePrefix(arg0: MSPyECObjects.ECSchema, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ParseSchemaFullName(*args, **kwargs):
        """
        ParseSchemaFullName(fullName: str) -> tuple
        """
        ...
    
    def ParseVersionString(*args, **kwargs):
        """
        ParseVersionString(versionString: str) -> tuple
        """
        ...
    
    def ReadFromXmlFile(*args, **kwargs):
        """
        ReadFromXmlFile(ecSchemaXmlFile: str, schemaContext: MSPyECObjects.ECSchemaReadContext) -> tuple
        """
        ...
    
    def ReadFromXmlString(*args, **kwargs):
        """
        ReadFromXmlString(*args, **kwargs)
        Overloaded function.
        
        1. ReadFromXmlString(ecSchemaXml: str, schemaContext: MSPyECObjects.ECSchemaReadContext) -> tuple
        
        2. ReadFromXmlString(ecSchemaXml: str, schemaContext: MSPyECObjects.ECSchemaReadContext) -> tuple
        """
        ...
    
    @property
    def ReferencedSchemas(arg0: MSPyECObjects.ECSchema) -> Bentley.ECN.SchemaMapExact:
        ...
    
    def RemoveReferencedSchema(*args, **kwargs):
        """
        RemoveReferencedSchema(self: MSPyECObjects.ECSchema, refSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ResolveNamespacePrefix(*args, **kwargs):
        """
        ResolveNamespacePrefix(self: MSPyECObjects.ECSchema, schema: MSPyECObjects.ECSchema, namespacePrefix: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def SchemaKey(arg0: MSPyECObjects.ECSchema) -> MSPyECObjects.SchemaKey:
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECSchema, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECSchema, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetErrorHandling(*args, **kwargs):
        """
        SetErrorHandling(arg0: bool, arg1: bool) -> None
        """
        ...
    
    def SetImmutable(*args, **kwargs):
        """
        SetImmutable(self: MSPyECObjects.ECSchema) -> None
        """
        ...
    
    def SetName(*args, **kwargs):
        """
        SetName(self: MSPyECObjects.ECSchema, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetNamespacePrefix(*args, **kwargs):
        """
        SetNamespacePrefix(self: MSPyECObjects.ECSchema, prefix: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetVersionMajor(*args, **kwargs):
        """
        SetVersionMajor(self: MSPyECObjects.ECSchema, major: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetVersionMinor(*args, **kwargs):
        """
        SetVersionMinor(self: MSPyECObjects.ECSchema, minor: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ShouldNotBeStored(*args, **kwargs):
        """
        ShouldNotBeStored(self: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    @property
    def SupplementalInfo(arg0: MSPyECObjects.ECSchema) -> Bentley.ECN.SupplementalSchemaInfo:
        ...
    
    @property
    def VersionMajor(arg0: MSPyECObjects.ECSchema) -> int:
        ...
    @VersionMajor.setter
    def VersionMajor(arg0: MSPyECObjects.ECSchema, arg1: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def VersionMinor(arg0: MSPyECObjects.ECSchema) -> int:
        ...
    @VersionMinor.setter
    def VersionMinor(arg0: MSPyECObjects.ECSchema, arg1: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def WriteToXmlFile(*args, **kwargs):
        """
        WriteToXmlFile(self: MSPyECObjects.ECSchema, ecSchemaXmlFile: str, utf16: bool = False) -> MSPyECObjects.SchemaWriteStatus
        """
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
        WriteToXmlString(*args, **kwargs)
        Overloaded function.
        
        1. WriteToXmlString(self: MSPyECObjects.ECSchema, ecSchemaXml: MSPyBentley.WString) -> MSPyECObjects.SchemaWriteStatus
        
        2. WriteToXmlString(self: MSPyECObjects.ECSchema, ecSchemaXml: MSPyBentley.Utf8String) -> MSPyECObjects.SchemaWriteStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECSchemaCPArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECSchemaCPArray) -> None
        
        2. __init__(self: MSPyECObjects.ECSchemaCPArray, arg0: MSPyECObjects.ECSchemaCPArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ECSchemaCPArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.ECSchemaCPArray, x: MSPyECObjects.ECSchema) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.ECSchemaCPArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.ECSchemaCPArray, x: MSPyECObjects.ECSchema) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECSchemaCPArray, L: MSPyECObjects.ECSchemaCPArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECSchemaCPArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.ECSchemaCPArray, i: int, x: MSPyECObjects.ECSchema) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECSchemaCPArray) -> MSPyECObjects.ECSchema
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECSchemaCPArray, i: int) -> MSPyECObjects.ECSchema
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.ECSchemaCPArray, x: MSPyECObjects.ECSchema) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ECSchemaCache:
    """
    None
    """

    def AddSchema(*args, **kwargs):
        """
        AddSchema(self: MSPyECObjects.ECSchemaCache, schema: Bentley.ECN.ECSchema) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyECObjects.ECSchemaCache) -> None
        """
        ...
    
    @property
    def Count(arg0: MSPyECObjects.ECSchemaCache) -> int:
        ...
    
    def DropSchema(*args, **kwargs):
        """
        DropSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetCount(*args, **kwargs):
        """
        GetCount(self: MSPyECObjects.ECSchemaCache) -> int
        """
        ...
    
    def GetSchema(*args, **kwargs):
        """
        GetSchema(*args, **kwargs)
        Overloaded function.
        
        1. GetSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey) -> Bentley.ECN.ECSchema
        
        2. GetSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType) -> Bentley.ECN.ECSchema
        """
        ...
    
    def GetSchemaLocater(*args, **kwargs):
        """
        GetSchemaLocater(self: MSPyECObjects.ECSchemaCache) -> MSPyECObjects.IECSchemaLocater
        """
        ...
    
    def GetSchemas(*args, **kwargs):
        """
        GetSchemas(self: MSPyECObjects.ECSchemaCache, schemas: Bentley.Bstdcxx.bvector<Bentley.ECN.ECSchema * __ptr64,Bentley.BentleyAllocator<Bentley.ECN.ECSchema * __ptr64> >) -> int
        """
        ...
    
    @property
    def SchemaLocater(arg0: MSPyECObjects.ECSchemaCache) -> MSPyECObjects.IECSchemaLocater:
        ...
    
    def __init__(self: MSPyECObjects.ECSchemaCache) -> None:
        ...
    
class ECSchemaPArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECSchemaPArray) -> None
        
        2. __init__(self: MSPyECObjects.ECSchemaPArray, arg0: MSPyECObjects.ECSchemaPArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ECSchemaPArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.ECSchemaPArray, x: MSPyECObjects.ECSchema) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.ECSchemaPArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.ECSchemaPArray, x: MSPyECObjects.ECSchema) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECSchemaPArray, L: MSPyECObjects.ECSchemaPArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECSchemaPArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.ECSchemaPArray, i: int, x: MSPyECObjects.ECSchema) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECSchemaPArray) -> MSPyECObjects.ECSchema
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECSchemaPArray, i: int) -> MSPyECObjects.ECSchema
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.ECSchemaPArray, x: MSPyECObjects.ECSchema) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ECSchemaPtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECSchemaPtrArray) -> None
        
        2. __init__(self: MSPyECObjects.ECSchemaPtrArray, arg0: MSPyECObjects.ECSchemaPtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ECSchemaPtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.ECSchemaPtrArray, x: MSPyECObjects.ECSchema) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.ECSchemaPtrArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.ECSchemaPtrArray, x: MSPyECObjects.ECSchema) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECSchemaPtrArray, L: MSPyECObjects.ECSchemaPtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECSchemaPtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.ECSchemaPtrArray, i: int, x: MSPyECObjects.ECSchema) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECSchemaPtrArray) -> MSPyECObjects.ECSchema
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECSchemaPtrArray, i: int) -> MSPyECObjects.ECSchema
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.ECSchemaPtrArray, x: MSPyECObjects.ECSchema) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ECSchemaReadContext:
    """
    None
    """

    def AddCulture(*args, **kwargs):
        """
        AddCulture(self: MSPyECObjects.ECSchemaReadContext, culture: str) -> None
        
        Adds a culture string that will be appended to the existing search
        paths when looking for localization supplemental schemas.
        
        Parameter ``culture``:
        string in format cu-CU or just cu
        """
        ...
    
    def AddSchemaLocater(*args, **kwargs):
        """
        AddSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: Bentley.ECN.IECSchemaLocater, priority: int = 0) -> None
        
        Adds a schema locater to the current context
        
        Parameter ``locater``:
        Locater to add to the current context
        
        Parameter ``priority``:
        The priority this locater has when ordering all locaters for
        locating a schema
        """
        ...
    
    def AddSchemaPath(*args, **kwargs):
        """
        AddSchemaPath(self: MSPyECObjects.ECSchemaReadContext, path: str) -> None
        
        Adds a file path that should be used to search for a matching schema
        name
        
        Parameter ``path``:
        Path to the directory where schemas can be found
        """
        ...
    
    @property
    def Cache(arg0: MSPyECObjects.ECSchemaReadContext) -> Bentley.ECN.ECSchemaCache:
        ...
    
    def CreateContext(*args, **kwargs):
        """
        CreateContext(*args, **kwargs)
        Overloaded function.
        
        1. CreateContext(standaloneEnablerLocator: Bentley.ECN.IStandaloneEnablerLocater, acceptLegacyImperfectLatestCompatibleMatch: bool = False) -> MSPyECObjects.ECSchemaReadContext
        
        Creates a context for deserializing ECSchemas
        
        Parameter ``standaloneEnablerLocater``:
        Used to find enablers for instantiating instances of
        ECCustomAttributes used in the read ECSchema
        
        Parameter ``acceptLegacyImperfectLatestCompatibleMatch``:
        If true, LatestCompatible only checks that the major version
        matches. A warning will be logged if minor version is too low, but
        the ECSchema will be accepted
        
        Remark:
        s This more-flexible override is primarily for internal use
        
        2. CreateContext(acceptLegacyImperfectLatestCompatibleMatch: bool = False) -> MSPyECObjects.ECSchemaReadContext
        
        Creates a context for deserializing ECSchemas
        
        Parameter ``standaloneEnablerLocater``:
        Used to find enablers for instantiating instances of
        ECCustomAttributes used in the read ECSchema
        
        Parameter ``acceptLegacyImperfectLatestCompatibleMatch``:
        If true, LatestCompatible only checks that the major version
        matches. A warning will be logged if minor version is too low, but
        the ECSchema will be accepted
        
        Remark:
        s This more-flexible override is primarily for internal use
        """
        ...
    
    @property
    def Cultures(arg0: MSPyECObjects.ECSchemaReadContext) -> MSPyBentley.WStringArray:
        ...
    
    def GetCache(*args, **kwargs):
        """
        GetCache(self: MSPyECObjects.ECSchemaReadContext) -> Bentley.ECN.ECSchemaCache
        
        Gets the schemas cached by this context.
        
        Returns:
        Schemas cached by this context
        """
        ...
    
    def GetCultures(*args, **kwargs):
        """
        GetCultures(self: MSPyECObjects.ECSchemaReadContext) -> MSPyBentley.WStringArray
        
        Gets culture strings
        """
        ...
    
    def LocateSchema(*args, **kwargs):
        """
        LocateSchema(self: MSPyECObjects.ECSchemaReadContext, key: Bentley.ECN.SchemaKey, matchType: Bentley.ECN.SchemaMatchType) -> Bentley.ECN.ECSchema
        
        Find the schema matching the schema key and using matchType as the
        match criteria. This uses the prioritized list of locators to find the
        schema.
        
        Parameter ``key``:
        The SchemaKey that defines the schema (name and version
        information) that is being looked for
        
        Parameter ``matchType``:
        The match type criteria used to locate the requested schema
        
        Returns:
        An ECSchemaPtr. This ptr will return false for IsValid() if the
        schema could not be located.
        """
        ...
    
    class PriorityPartiion:
        """
        Members:
        
        eReaderContext
        
        eUserSpace
        
        eExternal
        
        eStandardPaths
        
        eFinal
        """
    
        def __init__(self: MSPyECObjects.ECSchemaReadContext.PriorityPartiion, value: int) -> None:
            ...
        
        eExternal: PriorityPartiion
        
        eFinal: PriorityPartiion
        
        eReaderContext: PriorityPartiion
        
        eStandardPaths: PriorityPartiion
        
        eUserSpace: PriorityPartiion
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ECSchemaReadContext.PriorityPartiion) -> int:
            ...
        
    def RemoveSchemaLocater(*args, **kwargs):
        """
        RemoveSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: Bentley.ECN.IECSchemaLocater) -> None
        
        Removes a schema locater from the current context
        
        Parameter ``locater``:
        Locater to remove from the current context
        """
        ...
    
    def SetFinalSchemaLocater(*args, **kwargs):
        """
        SetFinalSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: Bentley.ECN.IECSchemaLocater) -> None
        
        Set the last locater to be used when trying to find a schema
        
        Parameter ``locater``:
        Locater that should be used as the last locater when trying to
        find a schema
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eExternal: PriorityPartiion
    
    eFinal: PriorityPartiion
    
    eReaderContext: PriorityPartiion
    
    eStandardPaths: PriorityPartiion
    
    eUserSpace: PriorityPartiion
    
class ECTypeDescriptor:
    """
    None
    """

    @property
    def ArrayKind(arg0: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.ArrayKind:
        ...
    
    def CreatePrimitiveArrayTypeDescriptor(*args, **kwargs):
        """
        CreatePrimitiveArrayTypeDescriptor(primitiveType: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECTypeDescriptor
        """
        ...
    
    def CreatePrimitiveTypeDescriptor(*args, **kwargs):
        """
        CreatePrimitiveTypeDescriptor(primitiveType: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECTypeDescriptor
        """
        ...
    
    def CreateStructArrayTypeDescriptor(*args, **kwargs):
        """
        CreateStructArrayTypeDescriptor() -> MSPyECObjects.ECTypeDescriptor
        """
        ...
    
    def CreateStructTypeDescriptor(*args, **kwargs):
        """
        CreateStructTypeDescriptor() -> MSPyECObjects.ECTypeDescriptor
        """
        ...
    
    def GetArrayKind(*args, **kwargs):
        """
        GetArrayKind(self: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.ArrayKind
        """
        ...
    
    def GetPrimitiveType(*args, **kwargs):
        """
        GetPrimitiveType(self: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.PrimitiveType
        """
        ...
    
    def GetTypeKind(*args, **kwargs):
        """
        GetTypeKind(self: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.ValueKind
        """
        ...
    
    def IsArray(*args, **kwargs):
        """
        IsArray(self: MSPyECObjects.ECTypeDescriptor) -> bool
        """
        ...
    
    def IsPrimitive(*args, **kwargs):
        """
        IsPrimitive(self: MSPyECObjects.ECTypeDescriptor) -> bool
        """
        ...
    
    def IsPrimitiveArray(*args, **kwargs):
        """
        IsPrimitiveArray(self: MSPyECObjects.ECTypeDescriptor) -> bool
        """
        ...
    
    def IsStruct(*args, **kwargs):
        """
        IsStruct(self: MSPyECObjects.ECTypeDescriptor) -> bool
        """
        ...
    
    def IsStructArray(*args, **kwargs):
        """
        IsStructArray(self: MSPyECObjects.ECTypeDescriptor) -> bool
        """
        ...
    
    @property
    def PrimitiveType(arg0: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.PrimitiveType:
        ...
    
    @property
    def TypeKind(arg0: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.ValueKind:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECValue:
    """
    None
    """

    @property
    def ArrayInfo(arg0: MSPyECObjects.ECValue) -> MSPyECObjects.ArrayInfo:
        ...
    
    @property
    def Binary(arg0: MSPyECObjects.ECValue) -> bytes:
        ...
    @Binary.setter
    def Binary(arg0: MSPyECObjects.ECValue, arg1: bytes) -> None:
        ...
    
    @property
    def Boolean(arg0: MSPyECObjects.ECValue) -> bool:
        ...
    @Boolean.setter
    def Boolean(arg0: MSPyECObjects.ECValue, arg1: bool) -> Bentley.BentleyStatus:
        ...
    
    def CanConvertToPrimitiveType(*args, **kwargs):
        """
        CanConvertToPrimitiveType(self: MSPyECObjects.ECValue, type: MSPyECObjects.PrimitiveType) -> bool
        """
        ...
    
    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyECObjects.ECValue) -> None
        """
        ...
    
    @property
    def DateTime(arg0: MSPyECObjects.ECValue) -> MSPyBentley.BeDateTime:
        ...
    @DateTime.setter
    def DateTime(arg0: MSPyECObjects.ECValue, arg1: MSPyBentley.BeDateTime) -> Bentley.BentleyStatus:
        ...
    
    @property
    def DateTimeTicks(arg0: MSPyECObjects.ECValue) -> int:
        ...
    @DateTimeTicks.setter
    def DateTimeTicks(arg0: MSPyECObjects.ECValue, arg1: int) -> Bentley.BentleyStatus:
        ...
    
    @property
    def DateTimeUnixMillis(arg0: MSPyECObjects.ECValue) -> int:
        ...
    
    @property
    def Double(arg0: MSPyECObjects.ECValue) -> float:
        ...
    @Double.setter
    def Double(arg0: MSPyECObjects.ECValue, arg1: float) -> Bentley.BentleyStatus:
        ...
    
    def From(*args, **kwargs):
        """
        From(self: MSPyECObjects.ECValue, value: MSPyECObjects.ECValue) -> None
        """
        ...
    
    def GetArrayInfo(*args, **kwargs):
        """
        GetArrayInfo(self: MSPyECObjects.ECValue) -> MSPyECObjects.ArrayInfo
        """
        ...
    
    def GetBinary(*args, **kwargs):
        """
        GetBinary(self: MSPyECObjects.ECValue) -> bytes
        """
        ...
    
    def GetBoolean(*args, **kwargs):
        """
        GetBoolean(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def GetDateTime(*args, **kwargs):
        """
        GetDateTime(self: MSPyECObjects.ECValue) -> MSPyBentley.BeDateTime
        """
        ...
    
    def GetDateTimeTicks(*args, **kwargs):
        """
        GetDateTimeTicks(self: MSPyECObjects.ECValue) -> int
        """
        ...
    
    def GetDateTimeTicksEx(*args, **kwargs):
        """
        GetDateTimeTicksEx(self: MSPyECObjects.ECValue) -> tuple
        """
        ...
    
    def GetDateTimeUnixMillis(*args, **kwargs):
        """
        GetDateTimeUnixMillis(self: MSPyECObjects.ECValue) -> int
        """
        ...
    
    def GetDouble(*args, **kwargs):
        """
        GetDouble(self: MSPyECObjects.ECValue) -> float
        """
        ...
    
    def GetIGeometry(*args, **kwargs):
        """
        GetIGeometry(self: MSPyECObjects.ECValue) -> MSPyBentleyGeom.IGeometry
        """
        ...
    
    def GetInteger(*args, **kwargs):
        """
        GetInteger(self: MSPyECObjects.ECValue) -> int
        """
        ...
    
    def GetKind(*args, **kwargs):
        """
        GetKind(self: MSPyECObjects.ECValue) -> MSPyECObjects.ValueKind
        """
        ...
    
    def GetLong(*args, **kwargs):
        """
        GetLong(self: MSPyECObjects.ECValue) -> int
        """
        ...
    
    def GetPoint2D(*args, **kwargs):
        """
        GetPoint2D(self: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint2d
        """
        ...
    
    def GetPoint3D(*args, **kwargs):
        """
        GetPoint3D(self: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint3d
        """
        ...
    
    def GetPrimitiveType(*args, **kwargs):
        """
        GetPrimitiveType(self: MSPyECObjects.ECValue) -> MSPyECObjects.PrimitiveType
        """
        ...
    
    def GetString(*args, **kwargs):
        """
        GetString(self: MSPyECObjects.ECValue) -> str
        """
        ...
    
    def GetStruct(*args, **kwargs):
        """
        GetStruct(self: MSPyECObjects.ECValue) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetUtf8CP(*args, **kwargs):
        """
        GetUtf8CP(self: MSPyECObjects.ECValue) -> str
        """
        ...
    
    @property
    def IGeometry(arg0: MSPyECObjects.ECValue) -> MSPyBentleyGeom.IGeometry:
        ...
    @IGeometry.setter
    def IGeometry(arg0: MSPyECObjects.ECValue, arg1: MSPyBentleyGeom.IGeometry) -> Bentley.BentleyStatus:
        ...
    
    @property
    def Integer(arg0: MSPyECObjects.ECValue) -> int:
        ...
    @Integer.setter
    def Integer(arg0: MSPyECObjects.ECValue, arg1: int) -> Bentley.BentleyStatus:
        ...
    
    def IsArray(*args, **kwargs):
        """
        IsArray(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsBinary(*args, **kwargs):
        """
        IsBinary(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsBoolean(*args, **kwargs):
        """
        IsBoolean(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsDateTime(*args, **kwargs):
        """
        IsDateTime(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsDouble(*args, **kwargs):
        """
        IsDouble(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsIGeometry(*args, **kwargs):
        """
        IsIGeometry(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsInteger(*args, **kwargs):
        """
        IsInteger(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsLoaded(*args, **kwargs):
        """
        IsLoaded(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsLong(*args, **kwargs):
        """
        IsLong(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsNull(*args, **kwargs):
        """
        IsNull(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsPoint2D(*args, **kwargs):
        """
        IsPoint2D(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsPoint3D(*args, **kwargs):
        """
        IsPoint3D(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsPrimitive(*args, **kwargs):
        """
        IsPrimitive(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsReadOnly(*args, **kwargs):
        """
        IsReadOnly(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsString(*args, **kwargs):
        """
        IsString(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsStruct(*args, **kwargs):
        """
        IsStruct(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsUninitialized(*args, **kwargs):
        """
        IsUninitialized(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    def IsUtf8(*args, **kwargs):
        """
        IsUtf8(self: MSPyECObjects.ECValue) -> bool
        """
        ...
    
    @property
    def Kind(arg0: MSPyECObjects.ECValue) -> MSPyECObjects.ValueKind:
        ...
    
    @property
    def Loaded(arg0: MSPyECObjects.ECValue) -> bool:
        ...
    @Loaded.setter
    def Loaded(arg0: MSPyECObjects.ECValue, arg1: bool) -> None:
        ...
    
    @property
    def Long(arg0: MSPyECObjects.ECValue) -> int:
        ...
    @Long.setter
    def Long(arg0: MSPyECObjects.ECValue, arg1: int) -> Bentley.BentleyStatus:
        ...
    
    @property
    def Null(arg0: MSPyECObjects.ECValue) -> bool:
        ...
    @Null.setter
    def Null(arg0: MSPyECObjects.ECValue, arg1: bool) -> None:
        ...
    
    @property
    def Point2D(arg0: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint2d:
        ...
    @Point2D.setter
    def Point2D(arg0: MSPyECObjects.ECValue, arg1: MSPyBentleyGeom.DPoint2d) -> Bentley.BentleyStatus:
        ...
    
    @property
    def Point3D(arg0: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point3D.setter
    def Point3D(arg0: MSPyECObjects.ECValue, arg1: MSPyBentleyGeom.DPoint3d) -> Bentley.BentleyStatus:
        ...
    
    @property
    def PrimitiveType(arg0: MSPyECObjects.ECValue) -> MSPyECObjects.PrimitiveType:
        ...
    @PrimitiveType.setter
    def PrimitiveType(arg0: MSPyECObjects.ECValue, arg1: MSPyECObjects.PrimitiveType) -> Bentley.BentleyStatus:
        ...
    
    @property
    def ReadOnly(arg0: MSPyECObjects.ECValue) -> bool:
        ...
    @ReadOnly.setter
    def ReadOnly(arg0: MSPyECObjects.ECValue, arg1: bool) -> None:
        ...
    
    def SetBinary(*args, **kwargs):
        """
        SetBinary(self: MSPyECObjects.ECValue, arg0: bytes) -> None
        """
        ...
    
    def SetBoolean(*args, **kwargs):
        """
        SetBoolean(self: MSPyECObjects.ECValue, boolean: bool) -> Bentley.BentleyStatus
        """
        ...
    
    def SetDateTime(*args, **kwargs):
        """
        SetDateTime(self: MSPyECObjects.ECValue, dateTime: MSPyBentley.BeDateTime) -> Bentley.BentleyStatus
        """
        ...
    
    def SetDateTimeTicks(*args, **kwargs):
        """
        SetDateTimeTicks(*args, **kwargs)
        Overloaded function.
        
        1. SetDateTimeTicks(self: MSPyECObjects.ECValue, ceTicks: int) -> Bentley.BentleyStatus
        
        2. SetDateTimeTicks(self: MSPyECObjects.ECValue, ceTicks: int, dateTimeMetaData: MSPyBentley.BeDateTimeInfo) -> Bentley.BentleyStatus
        """
        ...
    
    def SetDouble(*args, **kwargs):
        """
        SetDouble(self: MSPyECObjects.ECValue, dblVal: float) -> Bentley.BentleyStatus
        """
        ...
    
    def SetIGeometry(*args, **kwargs):
        """
        SetIGeometry(self: MSPyECObjects.ECValue, geometry: MSPyBentleyGeom.IGeometry) -> Bentley.BentleyStatus
        """
        ...
    
    def SetInteger(*args, **kwargs):
        """
        SetInteger(self: MSPyECObjects.ECValue, integer: int) -> Bentley.BentleyStatus
        """
        ...
    
    def SetIsLoaded(*args, **kwargs):
        """
        SetIsLoaded(self: MSPyECObjects.ECValue, loaded: bool) -> None
        """
        ...
    
    def SetIsNull(*args, **kwargs):
        """
        SetIsNull(self: MSPyECObjects.ECValue, null: bool) -> None
        """
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        SetIsReadOnly(self: MSPyECObjects.ECValue, readOnly: bool) -> None
        """
        ...
    
    def SetLong(*args, **kwargs):
        """
        SetLong(self: MSPyECObjects.ECValue, long64: int) -> Bentley.BentleyStatus
        """
        ...
    
    def SetPoint2D(*args, **kwargs):
        """
        SetPoint2D(self: MSPyECObjects.ECValue, value: MSPyBentleyGeom.DPoint2d) -> Bentley.BentleyStatus
        """
        ...
    
    def SetPoint3D(*args, **kwargs):
        """
        SetPoint3D(self: MSPyECObjects.ECValue, value: MSPyBentleyGeom.DPoint3d) -> Bentley.BentleyStatus
        """
        ...
    
    def SetPrimitiveArrayInfo(*args, **kwargs):
        """
        SetPrimitiveArrayInfo(self: MSPyECObjects.ECValue, primitiveElementType: MSPyECObjects.PrimitiveType, count: int, isFixedSize: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetPrimitiveType(*args, **kwargs):
        """
        SetPrimitiveType(self: MSPyECObjects.ECValue, type: MSPyECObjects.PrimitiveType) -> Bentley.BentleyStatus
        """
        ...
    
    def SetString(*args, **kwargs):
        """
        SetString(*args, **kwargs)
        Overloaded function.
        
        1. SetString(self: MSPyECObjects.ECValue, string: MSPyBentley.WString, bool: bool = True) -> None
        
        2. SetString(self: MSPyECObjects.ECValue, string: MSPyBentley.Utf8String, bool: bool = True) -> None
        
        3. SetString(self: MSPyECObjects.ECValue, string: str, bool: bool = True) -> None
        """
        ...
    
    def SetStruct(*args, **kwargs):
        """
        SetStruct(self: MSPyECObjects.ECValue, instance: MSPyECObjects.IECInstance) -> Bentley.BentleyStatus
        """
        ...
    
    def SetStructArrayInfo(*args, **kwargs):
        """
        SetStructArrayInfo(self: MSPyECObjects.ECValue, count: int, isFixedSize: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetToNull(*args, **kwargs):
        """
        SetToNull(*args, **kwargs)
        Overloaded function.
        
        1. SetToNull(self: MSPyECObjects.ECValue) -> None
        
        2. SetToNull(self: MSPyECObjects.ECValue) -> None
        """
        ...
    
    @property
    def String(arg0: MSPyECObjects.ECValue) -> str:
        ...
    
    @property
    def Struct(arg0: MSPyECObjects.ECValue) -> MSPyECObjects.IECInstance:
        ...
    @Struct.setter
    def Struct(arg0: MSPyECObjects.ECValue, arg1: MSPyECObjects.IECInstance) -> Bentley.BentleyStatus:
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.ECValue) -> MSPyBentley.WString
        """
        ...
    
    @property
    def Utf8String(arg0: MSPyECObjects.ECValue) -> str:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECValue) -> None
        
        2. __init__(self: MSPyECObjects.ECValue, classification: MSPyECObjects.ValueKind) -> None
        
        3. __init__(self: MSPyECObjects.ECValue, primitive: MSPyECObjects.PrimitiveType) -> None
        
        4. __init__(self: MSPyECObjects.ECValue, integer32: int) -> None
        
        5. __init__(self: MSPyECObjects.ECValue, arg0: bool, arg1: bool) -> None
        
        6. __init__(self: MSPyECObjects.ECValue, arg0: int, arg1: bool) -> None
        
        7. __init__(self: MSPyECObjects.ECValue, doubleVal: float) -> None
        
        8. __init__(self: MSPyECObjects.ECValue, string: MSPyBentley.WString, bool: bool = True) -> None
        
        9. __init__(self: MSPyECObjects.ECValue, string: MSPyBentley.Utf8String, bool: bool = True) -> None
        
        10. __init__(self: MSPyECObjects.ECValue, string: str, bool: bool = True) -> None
        
        11. __init__(self: MSPyECObjects.ECValue, blob: bytes) -> None
        
        12. __init__(self: MSPyECObjects.ECValue, point2d: MSPyBentleyGeom.DPoint2d) -> None
        
        13. __init__(self: MSPyECObjects.ECValue, point3d: MSPyBentleyGeom.DPoint3d) -> None
        
        14. __init__(self: MSPyECObjects.ECValue, dateTime: MSPyBentley.BeDateTime) -> None
        """
        ...
    
class ECValueAccessor:
    """
    None
    """

    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyECObjects.ECValueAccessor) -> None
        """
        ...
    
    def DeepestLocation(*args, **kwargs):
        """
        DeepestLocation(self: MSPyECObjects.ECValueAccessor) -> MSPyECObjects.ECValueAccessor.Location
        """
        ...
    
    @property
    def Depth(arg0: MSPyECObjects.ECValueAccessor) -> int:
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        GetAccessString(*args, **kwargs)
        Overloaded function.
        
        1. GetAccessString(self: MSPyECObjects.ECValueAccessor) -> str
        
        2. GetAccessString(self: MSPyECObjects.ECValueAccessor, depth: int) -> str
        """
        ...
    
    def GetDepth(*args, **kwargs):
        """
        GetDepth(self: MSPyECObjects.ECValueAccessor) -> int
        """
        ...
    
    def GetManagedAccessString(*args, **kwargs):
        """
        GetManagedAccessString(self: MSPyECObjects.ECValueAccessor) -> MSPyBentley.WString
        """
        ...
    
    def GetPropertyName(*args, **kwargs):
        """
        GetPropertyName(self: MSPyECObjects.ECValueAccessor) -> MSPyBentley.WString
        """
        ...
    
    class Location:
        """
        None
        """
    
        @property
        def ECProperty(arg0: MSPyECObjects.ECValueAccessor.Location) -> MSPyECObjects.ECProperty:
            ...
        
        @property
        def Enabler(arg0: MSPyECObjects.ECValueAccessor.Location) -> MSPyECObjects.ECEnabler:
            ...
        
        def GetECProperty(*args, **kwargs):
            """
            GetECProperty(self: MSPyECObjects.ECValueAccessor.Location) -> MSPyECObjects.ECProperty
            """
            ...
        
        def GetEnabler(*args, **kwargs):
            """
            GetEnabler(self: MSPyECObjects.ECValueAccessor.Location) -> MSPyECObjects.ECEnabler
            """
            ...
        
        def __init__(*args, **kwargs):
            """
            Overloaded function.
            
            1. __init__(self: MSPyECObjects.ECValueAccessor.Location) -> None
            
            2. __init__(self: MSPyECObjects.ECValueAccessor.Location, enaber: MSPyECObjects.ECEnabler, propIdx: int, arrayIdx: int) -> None
            """
            ...
        
    @property
    def ManagedAccessString(arg0: MSPyECObjects.ECValueAccessor) -> MSPyBentley.WString:
        ...
    
    def PopLocation(*args, **kwargs):
        """
        PopLocation(self: MSPyECObjects.ECValueAccessor) -> None
        """
        ...
    
    def PopulateValueAccessor(*args, **kwargs):
        """
        PopulateValueAccessor(*args, **kwargs)
        Overloaded function.
        
        1. PopulateValueAccessor(va: MSPyECObjects.ECValueAccessor, instance: MSPyECObjects.IECInstance, managedAccessor: str) -> MSPyECObjects.ECObjectsStatus
        
        2. PopulateValueAccessor(va: MSPyECObjects.ECValueAccessor, enabler: MSPyECObjects.ECEnabler, managedAccessor: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def PropertyName(arg0: MSPyECObjects.ECValueAccessor) -> MSPyBentley.WString:
        ...
    
    def PushLocation(*args, **kwargs):
        """
        PushLocation(*args, **kwargs)
        Overloaded function.
        
        1. PushLocation(self: MSPyECObjects.ECValueAccessor, enabler: MSPyECObjects.ECEnabler, propertyIndex: int, arrayIndex: int = -1) -> None
        
        2. PushLocation(self: MSPyECObjects.ECValueAccessor, enabler: MSPyECObjects.ECEnabler, accessString: str, arrayIndex: int = -1) -> bool
        
        3. PushLocation(self: MSPyECObjects.ECValueAccessor, instance: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int = -1) -> None
        
        4. PushLocation(self: MSPyECObjects.ECValueAccessor, instance: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int = -1) -> bool
        """
        ...
    
    def __init__(self: MSPyECObjects.ECValueAccessor) -> None:
        ...
    
class ECValuesCollection:
    """
    None
    """

    def Create(*args, **kwargs):
        """
        Create(*args, **kwargs)
        Overloaded function.
        
        1. Create(instance: MSPyECObjects.IECInstance) -> MSPyECObjects.ECValuesCollection
        
        2. Create(propertyValue: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValuesCollection
        """
        ...
    
    def GetParentProperty(*args, **kwargs):
        """
        GetParentProperty(self: MSPyECObjects.ECValuesCollection) -> MSPyECObjects.ECPropertyValue
        """
        ...
    
    @property
    def ParentProperty(arg0: MSPyECObjects.ECValuesCollection) -> MSPyECObjects.ECPropertyValue:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class EvaluationOptions:
    """
    Members:
    
    eEVALOPT_Legacy
    
    eEVALOPT_SuppressTypeConversions
    
    eEVALOPT_EnforceUnits
    
    eEVALOPT_EnforceGlobalRepresentation
    """

    def __init__(self: MSPyECObjects.EvaluationOptions, value: int) -> None:
        ...
    
    eEVALOPT_EnforceGlobalRepresentation: EvaluationOptions
    
    eEVALOPT_EnforceUnits: EvaluationOptions
    
    eEVALOPT_Legacy: EvaluationOptions
    
    eEVALOPT_SuppressTypeConversions: EvaluationOptions
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.EvaluationOptions) -> int:
        ...
    
class EvaluationResult:
    """
    None
    """

    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyECObjects.EvaluationResult) -> None
        """
        ...
    
    @property
    def ECValue(arg0: MSPyECObjects.EvaluationResult) -> Bentley.ECN.ECValue:
        ...
    
    def GetECValue(*args, **kwargs):
        """
        GetECValue(self: MSPyECObjects.EvaluationResult) -> Bentley.ECN.ECValue
        """
        ...
    
    def GetInstanceList(*args, **kwargs):
        """
        GetInstanceList(self: MSPyECObjects.EvaluationResult) -> Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >
        """
        ...
    
    def GetUnits(*args, **kwargs):
        """
        GetUnits(self: MSPyECObjects.EvaluationResult) -> Bentley.ECN.UnitSpec
        """
        ...
    
    def GetValueType(*args, **kwargs):
        """
        GetValueType(self: MSPyECObjects.EvaluationResult) -> MSPyECObjects.ValueType
        """
        ...
    
    @property
    def InstanceList(arg0: MSPyECObjects.EvaluationResult) -> Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >:
        ...
    
    def IsECValue(*args, **kwargs):
        """
        IsECValue(self: MSPyECObjects.EvaluationResult) -> bool
        """
        ...
    
    def IsInstanceList(*args, **kwargs):
        """
        IsInstanceList(self: MSPyECObjects.EvaluationResult) -> bool
        """
        ...
    
    def IsLambda(*args, **kwargs):
        """
        IsLambda(self: MSPyECObjects.EvaluationResult) -> bool
        """
        ...
    
    def IsValueList(*args, **kwargs):
        """
        IsValueList(self: MSPyECObjects.EvaluationResult) -> bool
        """
        ...
    
    def SetInstance(*args, **kwargs):
        """
        SetInstance(self: MSPyECObjects.EvaluationResult, instance: Bentley.ECN.IECInstance) -> None
        """
        ...
    
    def SetInstanceList(*args, **kwargs):
        """
        SetInstanceList(self: MSPyECObjects.EvaluationResult, instanceList: Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >, makeCopy: bool) -> None
        """
        ...
    
    def SetUnits(*args, **kwargs):
        """
        SetUnits(self: MSPyECObjects.EvaluationResult, units: Bentley.ECN.UnitSpec) -> None
        """
        ...
    
    @property
    def Units(arg0: MSPyECObjects.EvaluationResult) -> Bentley.ECN.UnitSpec:
        ...
    @Units.setter
    def Units(arg0: MSPyECObjects.EvaluationResult, arg1: Bentley.ECN.UnitSpec) -> None:
        ...
    
    @property
    def ValueType(arg0: MSPyECObjects.EvaluationResult) -> MSPyECObjects.ValueType:
        ...
    
    def __init__(self: MSPyECObjects.EvaluationResult) -> None:
        ...
    
class ExpressionContext:
    """
    None
    """

    def AllowsTypeConversion(*args, **kwargs):
        """
        AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforceGlobalRepresentation(*args, **kwargs):
        """
        EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforcesUnits(*args, **kwargs):
        """
        EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(*args, **kwargs):
        """
        GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions
        """
        ...
    
    def SetEvaluationOptions(*args, **kwargs):
        """
        SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ExpressionResolver:
    """
    None
    """

    @property
    def ExpressionContext(arg0: MSPyECObjects.ExpressionResolver) -> MSPyECObjects.ExpressionContext:
        ...
    
    def GetExpressionContext(*args, **kwargs):
        """
        GetExpressionContext(self: MSPyECObjects.ExpressionResolver) -> MSPyECObjects.ExpressionContext
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ExpressionStatus:
    """
    Members:
    
    eExprStatus_Success
    
    eExprStatus_UnknownError
    
    eExprStatus_UnknownMember
    
    eExprStatus_PrimitiveRequired
    
    eExprStatus_StructRequired
    
    eExprStatus_ArrayRequired
    
    eExprStatus_UnknownSymbol
    
    eExprStatus_DotNotSupported
    
    eExprStatus_NotImpl
    
    eExprStatus_NeedsLValue
    
    eExprStatus_WrongType
    
    eExprStatus_IncompatibleTypes
    
    eExprStatus_MethodRequired
    
    eExprStatus_InstanceMethodRequired
    
    eExprStatus_StaticMethodRequired
    
    eExprStatus_InvalidTypesForDivision
    
    eExprStatus_DivideByZero
    
    eExprStatus_WrongNumberOfArguments
    
    eExprStatus_IndexOutOfRange
    
    eExprStatus_IncompatibleUnits
    """

    def __init__(self: MSPyECObjects.ExpressionStatus, value: int) -> None:
        ...
    
    eExprStatus_ArrayRequired: ExpressionStatus
    
    eExprStatus_DivideByZero: ExpressionStatus
    
    eExprStatus_DotNotSupported: ExpressionStatus
    
    eExprStatus_IncompatibleTypes: ExpressionStatus
    
    eExprStatus_IncompatibleUnits: ExpressionStatus
    
    eExprStatus_IndexOutOfRange: ExpressionStatus
    
    eExprStatus_InstanceMethodRequired: ExpressionStatus
    
    eExprStatus_InvalidTypesForDivision: ExpressionStatus
    
    eExprStatus_MethodRequired: ExpressionStatus
    
    eExprStatus_NeedsLValue: ExpressionStatus
    
    eExprStatus_NotImpl: ExpressionStatus
    
    eExprStatus_PrimitiveRequired: ExpressionStatus
    
    eExprStatus_StaticMethodRequired: ExpressionStatus
    
    eExprStatus_StructRequired: ExpressionStatus
    
    eExprStatus_Success: ExpressionStatus
    
    eExprStatus_UnknownError: ExpressionStatus
    
    eExprStatus_UnknownMember: ExpressionStatus
    
    eExprStatus_UnknownSymbol: ExpressionStatus
    
    eExprStatus_WrongNumberOfArguments: ExpressionStatus
    
    eExprStatus_WrongType: ExpressionStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ExpressionStatus) -> int:
        ...
    
class ExpressionToken:
    """
    Members:
    
    eTOKEN_None
    
    eTOKEN_Null
    
    eTOKEN_True
    
    eTOKEN_False
    
    eTOKEN_Like
    
    eTOKEN_Is
    
    eTOKEN_Star
    
    eTOKEN_Plus
    
    eTOKEN_Minus
    
    eTOKEN_Slash
    
    eTOKEN_Comma
    
    eTOKEN_IntegerDivide
    
    eTOKEN_LParen
    
    eTOKEN_RParen
    
    eTOKEN_Exponentiation
    
    eTOKEN_And
    
    eTOKEN_AndAlso
    
    eTOKEN_Or
    
    eTOKEN_OrElse
    
    eTOKEN_Concatenate
    
    eTOKEN_Mod
    
    eTOKEN_ShiftLeft
    
    eTOKEN_ShiftRight
    
    eTOKEN_Colon
    
    eTOKEN_LessEqual
    
    eTOKEN_GreaterEqual
    
    eTOKEN_Less
    
    eTOKEN_Greater
    
    eTOKEN_Equal
    
    eTOKEN_NotEqual
    
    eTOKEN_Not
    
    eTOKEN_Xor
    
    eTOKEN_UnsignedShiftRight
    
    eTOKEN_LeftBracket
    
    eTOKEN_RightBracket
    
    eTOKEN_Dot
    
    eTOKEN_IIf
    
    eTOKEN_LCurly
    
    eTOKEN_RCurly
    
    eTOKEN_If
    
    eTOKEN_Else
    
    eTOKEN_ElseIf
    
    eTOKEN_Select
    
    eTOKEN_End
    
    eTOKEN_EndIf
    
    eTOKEN_Lambda
    
    eTOKEN_EqualModify
    
    eTOKEN_NotEqualModify
    
    eTOKEN_NotModify
    
    eTOKEN_ModModify
    
    eTOKEN_OrElseModify
    
    eTOKEN_AndAlsoModify
    
    eTOKEN_DoubleColon
    
    eTOKEN_Error
    
    eTOKEN_Ident
    
    eTOKEN_StringConst
    
    eTOKEN_PointConst
    
    eTOKEN_DateTimeConst
    
    eTOKEN_IntegerConstant
    
    eTOKEN_HexConstant
    
    eTOKEN_FloatConst
    
    eTOKEN_UnitsConst
    
    eTOKEN_Unrecognized
    
    eTOKEN_BadNumber
    
    eTOKEN_BadOctalNumber
    
    eTOKEN_BadHexNumber
    
    eTOKEN_BadFloatingPointNumber
    
    eTOKEN_UnterminatedString
    
    eTOKEN_PrimaryList
    """

    def __init__(self: MSPyECObjects.ExpressionToken, value: int) -> None:
        ...
    
    eTOKEN_And: ExpressionToken
    
    eTOKEN_AndAlso: ExpressionToken
    
    eTOKEN_AndAlsoModify: ExpressionToken
    
    eTOKEN_BadFloatingPointNumber: ExpressionToken
    
    eTOKEN_BadHexNumber: ExpressionToken
    
    eTOKEN_BadNumber: ExpressionToken
    
    eTOKEN_BadOctalNumber: ExpressionToken
    
    eTOKEN_Colon: ExpressionToken
    
    eTOKEN_Comma: ExpressionToken
    
    eTOKEN_Concatenate: ExpressionToken
    
    eTOKEN_DateTimeConst: ExpressionToken
    
    eTOKEN_Dot: ExpressionToken
    
    eTOKEN_DoubleColon: ExpressionToken
    
    eTOKEN_Else: ExpressionToken
    
    eTOKEN_ElseIf: ExpressionToken
    
    eTOKEN_End: ExpressionToken
    
    eTOKEN_EndIf: ExpressionToken
    
    eTOKEN_Equal: ExpressionToken
    
    eTOKEN_EqualModify: ExpressionToken
    
    eTOKEN_Error: ExpressionToken
    
    eTOKEN_Exponentiation: ExpressionToken
    
    eTOKEN_False: ExpressionToken
    
    eTOKEN_FloatConst: ExpressionToken
    
    eTOKEN_Greater: ExpressionToken
    
    eTOKEN_GreaterEqual: ExpressionToken
    
    eTOKEN_HexConstant: ExpressionToken
    
    eTOKEN_IIf: ExpressionToken
    
    eTOKEN_Ident: ExpressionToken
    
    eTOKEN_If: ExpressionToken
    
    eTOKEN_IntegerConstant: ExpressionToken
    
    eTOKEN_IntegerDivide: ExpressionToken
    
    eTOKEN_Is: ExpressionToken
    
    eTOKEN_LCurly: ExpressionToken
    
    eTOKEN_LParen: ExpressionToken
    
    eTOKEN_Lambda: ExpressionToken
    
    eTOKEN_LeftBracket: ExpressionToken
    
    eTOKEN_Less: ExpressionToken
    
    eTOKEN_LessEqual: ExpressionToken
    
    eTOKEN_Like: ExpressionToken
    
    eTOKEN_Minus: ExpressionToken
    
    eTOKEN_Mod: ExpressionToken
    
    eTOKEN_ModModify: ExpressionToken
    
    eTOKEN_None: ExpressionToken
    
    eTOKEN_Not: ExpressionToken
    
    eTOKEN_NotEqual: ExpressionToken
    
    eTOKEN_NotEqualModify: ExpressionToken
    
    eTOKEN_NotModify: ExpressionToken
    
    eTOKEN_Null: ExpressionToken
    
    eTOKEN_Or: ExpressionToken
    
    eTOKEN_OrElse: ExpressionToken
    
    eTOKEN_OrElseModify: ExpressionToken
    
    eTOKEN_Plus: ExpressionToken
    
    eTOKEN_PointConst: ExpressionToken
    
    eTOKEN_PrimaryList: ExpressionToken
    
    eTOKEN_RCurly: ExpressionToken
    
    eTOKEN_RParen: ExpressionToken
    
    eTOKEN_RightBracket: ExpressionToken
    
    eTOKEN_Select: ExpressionToken
    
    eTOKEN_ShiftLeft: ExpressionToken
    
    eTOKEN_ShiftRight: ExpressionToken
    
    eTOKEN_Slash: ExpressionToken
    
    eTOKEN_Star: ExpressionToken
    
    eTOKEN_StringConst: ExpressionToken
    
    eTOKEN_True: ExpressionToken
    
    eTOKEN_UnitsConst: ExpressionToken
    
    eTOKEN_Unrecognized: ExpressionToken
    
    eTOKEN_UnsignedShiftRight: ExpressionToken
    
    eTOKEN_UnterminatedString: ExpressionToken
    
    eTOKEN_Xor: ExpressionToken
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ExpressionToken) -> int:
        ...
    
class IAUIDataContext:
    """
    None
    """

    class ContextType:
        """
        Members:
        
        eCustom
        
        eInstanceID
        
        eInstanceInterface
        
        eECInstanceCollection
        
        eDgnECInstanceCollection
        
        eDgnHitPathInfo
        
        eDgnActionItemInfoType
        
        eECGroupingNode
        
        eNodeCollection
        """
    
        def __init__(self: MSPyECObjects.IAUIDataContext.ContextType, value: int) -> None:
            ...
        
        eCustom: ContextType
        
        eDgnActionItemInfoType: ContextType
        
        eDgnECInstanceCollection: ContextType
        
        eDgnHitPathInfo: ContextType
        
        eECGroupingNode: ContextType
        
        eECInstanceCollection: ContextType
        
        eInstanceID: ContextType
        
        eInstanceInterface: ContextType
        
        eNodeCollection: ContextType
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.IAUIDataContext.ContextType) -> int:
            ...
        
    def GetContextType(*args, **kwargs):
        """
        GetContextType(self: MSPyECObjects.IAUIDataContext) -> MSPyECObjects.IAUIDataContext.ContextType
        """
        ...
    
    def GetCustomData(*args, **kwargs):
        """
        GetCustomData(self: MSPyECObjects.IAUIDataContext) -> capsule
        """
        ...
    
    def GetInstanceIterable(*args, **kwargs):
        """
        GetInstanceIterable(self: MSPyECObjects.IAUIDataContext) -> MSPyECObjects.ECInstanceIterable
        """
        ...
    
    def GetMoniker(*args, **kwargs):
        """
        GetMoniker(self: MSPyECObjects.IAUIDataContext) -> MSPyBentley.WString
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eCustom: ContextType
    
    eDgnActionItemInfoType: ContextType
    
    eDgnECInstanceCollection: ContextType
    
    eDgnHitPathInfo: ContextType
    
    eECGroupingNode: ContextType
    
    eECInstanceCollection: ContextType
    
    eInstanceID: ContextType
    
    eInstanceInterface: ContextType
    
    eNodeCollection: ContextType
    
class ICustomECStructSerializer:
    """
    None
    """

    def GenerateXmlString(*args, **kwargs):
        """
        GenerateXmlString(self: MSPyECObjects.ICustomECStructSerializer, xmlString: MSPyBentley.WString, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance, baseAccessString: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def LoadStructureFromString(*args, **kwargs):
        """
        LoadStructureFromString(self: MSPyECObjects.ICustomECStructSerializer, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance, baseAccessString: str, valueString: str) -> None
        """
        ...
    
    def UsesCustomStructXmlString(*args, **kwargs):
        """
        UsesCustomStructXmlString(self: MSPyECObjects.ICustomECStructSerializer, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IECCustomAttributeContainer:
    """
    None
    """

    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IECInstance:
    """
    None
    """

    def AddArrayElements(*args, **kwargs):
        """
        AddArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(*args, **kwargs):
        """
        AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase
        """
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        ChangeValue(*args, **kwargs)
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(*args, **kwargs):
        """
        ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        ClearArray(*args, **kwargs)
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(*args, **kwargs):
        """
        CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
        CreateCopyThroughSerialization(*args, **kwargs)
        Overloaded function.
        
        1. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance) -> MSPyECObjects.IECInstance
        
        2. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance, targetSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.IECInstance
        """
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetECDBuffer(*args, **kwargs):
        """
        GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer
        """
        ...
    
    def GetEnabler(*args, **kwargs):
        """
        GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler
        """
        ...
    
    def GetInstanceId(*args, **kwargs):
        """
        GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetInstanceIdForSerialization(*args, **kwargs):
        """
        GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetOffsetToIECInstance(*args, **kwargs):
        """
        GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int
        """
        ...
    
    def GetValue(*args, **kwargs):
        """
        GetValue(*args, **kwargs)
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(*args, **kwargs):
        """
        GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
        InsertArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. InsertArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        
        2. InsertArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def InstanceId(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    @InstanceId.setter
    def InstanceId(arg0: MSPyECObjects.IECInstance, arg1: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def InstanceIdForSerialization(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def IsFixedArrayProperty(*args, **kwargs):
        """
        IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple
        """
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        IsPropertyNull(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        IsPropertyReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(*args, **kwargs):
        """
        IsReadOnly(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def ReadFromXmlFile(*args, **kwargs):
        """
        ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def ReadFromXmlString(*args, **kwargs):
        """
        ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        RemoveArrayElement(*args, **kwargs)
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(*args, **kwargs):
        """
        SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetInstanceId(*args, **kwargs):
        """
        SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValue(*args, **kwargs):
        """
        SetValue(*args, **kwargs)
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(*args, **kwargs):
        """
        SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString
        """
        ...
    
    def WriteToXmlFile(*args, **kwargs):
        """
        WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
        WriteToXmlString(*args, **kwargs)
        Overloaded function.
        
        1. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.Utf8String, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        
        2. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.WString, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IECInstancePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.IECInstancePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.IECInstancePtrArray, arg0: MSPyECObjects.IECInstancePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.IECInstancePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.IECInstancePtrArray, x: MSPyECObjects.IECInstance) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.IECInstancePtrArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.IECInstancePtrArray, x: MSPyECObjects.IECInstance) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.IECInstancePtrArray, L: MSPyECObjects.IECInstancePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.IECInstancePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.IECInstancePtrArray, i: int, x: MSPyECObjects.IECInstance) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.IECInstancePtrArray) -> MSPyECObjects.IECInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.IECInstancePtrArray, i: int) -> MSPyECObjects.IECInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.IECInstancePtrArray, x: MSPyECObjects.IECInstance) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class IECPresentationProvider:
    """
    None
    """

    def GetProviderId(*args, **kwargs):
        """
        GetProviderId(self: MSPyECObjects.IECPresentationProvider) -> int
        """
        ...
    
    def GetProviderName(*args, **kwargs):
        """
        GetProviderName(self: MSPyECObjects.IECPresentationProvider) -> str
        """
        ...
    
    def GetProviderType(*args, **kwargs):
        """
        GetProviderType(self: MSPyECObjects.IECPresentationProvider) -> MSPyECObjects.IECPresentationProvider.ProviderType
        """
        ...
    
    @property
    def ProviderId(arg0: MSPyECObjects.IECPresentationProvider) -> int:
        ...
    
    @property
    def ProviderName(arg0: MSPyECObjects.IECPresentationProvider) -> str:
        ...
    
    @property
    def ProviderType(arg0: MSPyECObjects.IECPresentationProvider) -> MSPyECObjects.IECPresentationProvider.ProviderType:
        ...
    
    def __init__(self: MSPyECObjects.IECPresentationProvider) -> None:
        ...
    
    eCommandService: ProviderType
    
    eContentService: ProviderType
    
    eImageService: ProviderType
    
    eJournalService: ProviderType
    
    eLocalizationService: ProviderType
    
    eSelectionService: ProviderType
    
    eViewService: ProviderType
    
class IECProvider:
    """
    None
    """

    def GetProviderId(*args, **kwargs):
        """
        GetProviderId(self: MSPyECObjects.IECProvider) -> int
        """
        ...
    
    def GetProviderName(*args, **kwargs):
        """
        GetProviderName(self: MSPyECObjects.IECProvider) -> str
        """
        ...
    
    @property
    def ProviderId(arg0: MSPyECObjects.IECProvider) -> int:
        ...
    
    @property
    def ProviderName(arg0: MSPyECObjects.IECProvider) -> str:
        ...
    
    def __init__(self: MSPyECObjects.IECProvider) -> None:
        ...
    
class IECRelationshipEnabler:
    """
    None
    """

    def CreateWipRelationshipInstance(*args, **kwargs):
        """
        CreateWipRelationshipInstance(self: MSPyECObjects.IECRelationshipEnabler) -> Bentley.ECN.StandaloneECRelationshipInstance
        """
        ...
    
    def GetRelationshipClass(*args, **kwargs):
        """
        GetRelationshipClass(self: MSPyECObjects.IECRelationshipEnabler) -> MSPyECObjects.ECRelationshipClass
        """
        ...
    
    def __init__(self: MSPyECObjects.IECRelationshipEnabler) -> None:
        ...
    
class IECRelationshipInstance:
    """
    None
    """

    def AddArrayElements(*args, **kwargs):
        """
        AddArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(*args, **kwargs):
        """
        AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase
        """
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        ChangeValue(*args, **kwargs)
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(*args, **kwargs):
        """
        ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        ClearArray(*args, **kwargs)
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(*args, **kwargs):
        """
        CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
        CreateCopyThroughSerialization(*args, **kwargs)
        Overloaded function.
        
        1. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance) -> MSPyECObjects.IECInstance
        
        2. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance, targetSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.IECInstance
        """
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetECDBuffer(*args, **kwargs):
        """
        GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer
        """
        ...
    
    def GetEnabler(*args, **kwargs):
        """
        GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler
        """
        ...
    
    def GetInstanceId(*args, **kwargs):
        """
        GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetInstanceIdForSerialization(*args, **kwargs):
        """
        GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetOffsetToIECInstance(*args, **kwargs):
        """
        GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int
        """
        ...
    
    def GetSource(*args, **kwargs):
        """
        GetSource(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetSourceOrderId(*args, **kwargs):
        """
        GetSourceOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple
        """
        ...
    
    def GetTarget(*args, **kwargs):
        """
        GetTarget(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetTargetOrderId(*args, **kwargs):
        """
        GetTargetOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple
        """
        ...
    
    def GetValue(*args, **kwargs):
        """
        GetValue(*args, **kwargs)
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(*args, **kwargs):
        """
        GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
        InsertArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. InsertArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        
        2. InsertArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def InstanceId(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    @InstanceId.setter
    def InstanceId(arg0: MSPyECObjects.IECInstance, arg1: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def InstanceIdForSerialization(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def IsFixedArrayProperty(*args, **kwargs):
        """
        IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple
        """
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        IsPropertyNull(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        IsPropertyReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(*args, **kwargs):
        """
        IsReadOnly(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def ReadFromXmlFile(*args, **kwargs):
        """
        ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def ReadFromXmlString(*args, **kwargs):
        """
        ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        RemoveArrayElement(*args, **kwargs)
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(*args, **kwargs):
        """
        SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetInstanceId(*args, **kwargs):
        """
        SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetSource(*args, **kwargs):
        """
        SetSource(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None
        """
        ...
    
    def SetTarget(*args, **kwargs):
        """
        SetTarget(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None
        """
        ...
    
    def SetValue(*args, **kwargs):
        """
        SetValue(*args, **kwargs)
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(*args, **kwargs):
        """
        SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Source(arg0: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    @Source.setter
    def Source(arg0: MSPyECObjects.IECRelationshipInstance, arg1: MSPyECObjects.IECInstance) -> None:
        ...
    
    @property
    def Target(arg0: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    @Target.setter
    def Target(arg0: MSPyECObjects.IECRelationshipInstance, arg1: MSPyECObjects.IECInstance) -> None:
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString
        """
        ...
    
    def WriteToXmlFile(*args, **kwargs):
        """
        WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
        WriteToXmlString(*args, **kwargs)
        Overloaded function.
        
        1. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.Utf8String, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        
        2. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.WString, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IECSchemaLocater:
    """
    None
    """

    def LocateSchema(*args, **kwargs):
        """
        LocateSchema(self: MSPyECObjects.IECSchemaLocater, key: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType, schemaContext: MSPyECObjects.ECSchemaReadContext) -> Bentley.ECN.ECSchema
        """
        ...
    
    def __init__(self: MSPyECObjects.IECSchemaLocater) -> None:
        ...
    
class IECSymbolProvider:
    """
    None
    """

    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.IECSymbolProvider) -> str
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.IECSymbolProvider) -> str:
        ...
    
    def PublishSymbols(*args, **kwargs):
        """
        PublishSymbols(self: MSPyECObjects.IECSymbolProvider, context: MSPyECObjects.SymbolExpressionContext, requestedSymbolSets: MSPyBentley.WStringArray) -> None
        """
        ...
    
    def RegisterExternalSymbolPublisher(*args, **kwargs):
        """
        RegisterExternalSymbolPublisher(externalPublisher: std.function<void __cdecl(Bentley.ECN.SymbolExpressionContext & __ptr64,Bentley.Bstdcxx.bvector<Bentley.WString,Bentley.BentleyAllocator<Bentley.WString> > const & __ptr64)>) -> None
        """
        ...
    
    def __init__(self: MSPyECObjects.IECSymbolProvider) -> None:
        ...
    
class IECTypeAdapter:
    """
    None
    """

    def CanConvertFromString(*args, **kwargs):
        """
        CanConvertFromString(self: MSPyECObjects.IECTypeAdapter, context: MSPyECObjects.IECTypeAdapterContext) -> bool
        """
        ...
    
    def CanConvertToString(*args, **kwargs):
        """
        CanConvertToString(self: MSPyECObjects.IECTypeAdapter, context: MSPyECObjects.IECTypeAdapterContext) -> bool
        """
        ...
    
    def CondenseFormatterForSerialization(*args, **kwargs):
        """
        CondenseFormatterForSerialization(self: MSPyECObjects.IECTypeAdapter, formatter: Bentley.ECN.IECInstance) -> Bentley.ECN.IECInstance
        """
        ...
    
    def ConvertFromExpressionType(*args, **kwargs):
        """
        ConvertFromExpressionType(self: MSPyECObjects.IECTypeAdapter, value: Bentley.ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext) -> bool
        """
        ...
    
    def ConvertFromString(*args, **kwargs):
        """
        ConvertFromString(self: MSPyECObjects.IECTypeAdapter, value: Bentley.ECN.ECValue, str: str, context: MSPyECObjects.IECTypeAdapterContext) -> bool
        """
        ...
    
    def ConvertToExpressionType(*args, **kwargs):
        """
        ConvertToExpressionType(self: MSPyECObjects.IECTypeAdapter, value: Bentley.ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext) -> bool
        """
        ...
    
    def ConvertToString(*args, **kwargs):
        """
        ConvertToString(self: MSPyECObjects.IECTypeAdapter, str: MSPyBentley.WString, value: Bentley.ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext, formatter: Bentley.ECN.IECInstance = None) -> bool
        """
        ...
    
    def CreateDefaultFormatter(*args, **kwargs):
        """
        CreateDefaultFormatter(self: MSPyECObjects.IECTypeAdapter, includeAllValues: bool, forDwg: bool = False) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetUnits(*args, **kwargs):
        """
        GetUnits(self: MSPyECObjects.IECTypeAdapter, unit: Bentley.ECN.UnitSpec, context: MSPyECObjects.IECTypeAdapterContext) -> bool
        """
        ...
    
    def HasStandardValues(*args, **kwargs):
        """
        HasStandardValues(self: MSPyECObjects.IECTypeAdapter) -> bool
        """
        ...
    
    def IsStruct(*args, **kwargs):
        """
        IsStruct(self: MSPyECObjects.IECTypeAdapter) -> bool
        """
        ...
    
    def IsTreatedAsString(*args, **kwargs):
        """
        IsTreatedAsString(self: MSPyECObjects.IECTypeAdapter) -> bool
        """
        ...
    
    def PopulateDefaultFormatterProperties(*args, **kwargs):
        """
        PopulateDefaultFormatterProperties(self: MSPyECObjects.IECTypeAdapter, formatter: Bentley.ECN.IECInstance) -> Bentley.ECN.IECInstance
        """
        ...
    
    def RequiresExpressionTypeConversion(*args, **kwargs):
        """
        RequiresExpressionTypeConversion(self: MSPyECObjects.IECTypeAdapter, evalOptions: MSPyECObjects.EvaluationOptions = <EvaluationOptions.eEVALOPT_Legacy: 0>) -> bool
        """
        ...
    
    def SupportsUnits(*args, **kwargs):
        """
        SupportsUnits(self: MSPyECObjects.IECTypeAdapter) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IECTypeAdapterContext:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IPrimitiveTypeResolver:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IStandaloneEnablerLocater:
    """
    None
    """

    def LocateStandaloneEnabler(*args, **kwargs):
        """
        LocateStandaloneEnabler(self: MSPyECObjects.IStandaloneEnablerLocater, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class InstanceExpressionContext:
    """
    None
    """

    def AllowsTypeConversion(*args, **kwargs):
        """
        AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforceGlobalRepresentation(*args, **kwargs):
        """
        EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforcesUnits(*args, **kwargs):
        """
        EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(*args, **kwargs):
        """
        GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions
        """
        ...
    
    def SetEvaluationOptions(*args, **kwargs):
        """
        SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None
        """
        ...
    
    def SetInstance(*args, **kwargs):
        """
        SetInstance(self: MSPyECObjects.InstanceExpressionContext, instance: Bentley.ECN.IECInstance) -> None
        """
        ...
    
    def SetInstances(*args, **kwargs):
        """
        SetInstances(self: MSPyECObjects.InstanceExpressionContext, instances: Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >) -> None
        """
        ...
    
    def __init__(self: MSPyECObjects.InstanceExpressionContext, outer: MSPyECObjects.ExpressionContext = None) -> None:
        ...
    
class InstanceListExpressionContext:
    """
    None
    """

    def AllowsTypeConversion(*args, **kwargs):
        """
        AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforceGlobalRepresentation(*args, **kwargs):
        """
        EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforcesUnits(*args, **kwargs):
        """
        EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(*args, **kwargs):
        """
        GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions
        """
        ...
    
    def SetEvaluationOptions(*args, **kwargs):
        """
        SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        __init__(self: MSPyECObjects.InstanceListExpressionContext, instances: Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >, outer: MSPyECObjects.ExpressionContext = None) -> None
        """
        ...
    
class InstanceReadStatus:
    """
    Members:
    
    eINSTANCE_READ_STATUS_Success
    
    eINSTANCE_READ_STATUS_FileNotFound
    
    eINSTANCE_READ_STATUS_CantCreateStream
    
    eINSTANCE_READ_STATUS_CantCreateXmlReader
    
    eINSTANCE_READ_STATUS_CantSetStream
    
    eINSTANCE_READ_STATUS_NoElementName
    
    eINSTANCE_READ_STATUS_BadElement
    
    eINSTANCE_READ_STATUS_UnexpectedElement
    
    eINSTANCE_READ_STATUS_EmptyElement
    
    eINSTANCE_READ_STATUS_EndElementDoesntMatch
    
    eINSTANCE_READ_STATUS_XmlFileIncomplete
    
    eINSTANCE_READ_STATUS_XmlParseError
    
    eINSTANCE_READ_STATUS_ECClassNotFound
    
    eINSTANCE_READ_STATUS_BadECProperty
    
    eINSTANCE_READ_STATUS_BadPrimitivePropertyType
    
    eINSTANCE_READ_STATUS_BadBinaryData
    
    eINSTANCE_READ_STATUS_BadTimeValue
    
    eINSTANCE_READ_STATUS_BadDoubleValue
    
    eINSTANCE_READ_STATUS_BadIntegerValue
    
    eINSTANCE_READ_STATUS_BadLongValue
    
    eINSTANCE_READ_STATUS_BadPoint2dValue
    
    eINSTANCE_READ_STATUS_BadPoint3dValue
    
    eINSTANCE_READ_STATUS_BadArrayElement
    
    eINSTANCE_READ_STATUS_TypeMismatch
    
    eINSTANCE_READ_STATUS_CantSetValue
    
    eINSTANCE_READ_STATUS_ECSchemaNotFound
    
    eINSTANCE_READ_STATUS_UnableToGetStandaloneEnabler
    
    eINSTANCE_READ_STATUS_CommentOnly
    
    eINSTANCE_READ_STATUS_PropertyNotFound
    """

    def __init__(self: MSPyECObjects.InstanceReadStatus, value: int) -> None:
        ...
    
    eINSTANCE_READ_STATUS_BadArrayElement: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadBinaryData: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadDoubleValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadECProperty: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadElement: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadIntegerValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadLongValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadPoint2dValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadPoint3dValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadPrimitivePropertyType: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_BadTimeValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_CantCreateStream: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_CantCreateXmlReader: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_CantSetStream: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_CantSetValue: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_CommentOnly: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_ECClassNotFound: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_ECSchemaNotFound: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_EmptyElement: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_EndElementDoesntMatch: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_FileNotFound: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_NoElementName: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_PropertyNotFound: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_Success: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_TypeMismatch: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_UnableToGetStandaloneEnabler: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_UnexpectedElement: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_XmlFileIncomplete: InstanceReadStatus
    
    eINSTANCE_READ_STATUS_XmlParseError: InstanceReadStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.InstanceReadStatus) -> int:
        ...
    
class InstanceWriteStatus:
    """
    Members:
    
    eINSTANCE_WRITE_STATUS_Success
    
    eINSTANCE_WRITE_STATUS_CantCreateStream
    
    eINSTANCE_WRITE_STATUS_CantCreateXmlWriter
    
    eINSTANCE_WRITE_STATUS_CantSetStream
    
    eINSTANCE_WRITE_STATUS_XmlWriteError
    
    eINSTANCE_WRITE_STATUS_CantReadFromStream
    
    eINSTANCE_WRITE_STATUS_FailedToWriteFile
    
    eINSTANCE_WRITE_STATUS_BadPrimitivePropertyType
    """

    def __init__(self: MSPyECObjects.InstanceWriteStatus, value: int) -> None:
        ...
    
    eINSTANCE_WRITE_STATUS_BadPrimitivePropertyType: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_CantCreateStream: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_CantCreateXmlWriter: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_CantReadFromStream: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_CantSetStream: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_FailedToWriteFile: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_Success: InstanceWriteStatus
    
    eINSTANCE_WRITE_STATUS_XmlWriteError: InstanceWriteStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.InstanceWriteStatus) -> int:
        ...
    
class ItemsView[SchemaMapExact]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class KeysView[SchemaMapExact]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MemoryECInstanceBase:
    """
    None
    """

    def ClearValues(*args, **kwargs):
        """
        ClearValues(self: MSPyECObjects.MemoryECInstanceBase) -> None
        """
        ...
    
    def CopyFromBuffer(*args, **kwargs):
        """
        CopyFromBuffer(self: MSPyECObjects.ECDBuffer, source: MSPyECObjects.ECDBuffer) -> MSPyECObjects.ECObjectsStatus
        
        Attempts to copy property values from source buffer. Expects source to
        have a compatible class layout.
        
        Parameter ``source``:
        The ECDBuffer to copy values from
        """
        ...
    
    def GetData(*args, **kwargs):
        """
        GetData(self: MSPyECObjects.MemoryECInstanceBase) -> bytes
        """
        ...
    
    def IsEmpty(*args, **kwargs):
        """
        IsEmpty(self: MSPyECObjects.ECDBuffer) -> bool
        
        Returns true if the buffer is empty (all values are null and all
        arrays are empty)
        """
        ...
    
    def MergePropertiesFromInstance(*args, **kwargs):
        """
        MergePropertiesFromInstance(self: MSPyECObjects.MemoryECInstanceBase, fromNativeInstance: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetData(*args, **kwargs):
        """
        SetData(self: MSPyECObjects.MemoryECInstanceBase, data: bytes) -> None
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MemoryInstanceUsageBitmask:
    """
    Members:
    
    eMEMORYINSTANCEUSAGE_Empty
    
    eMEMORYINSTANCEUSAGE_IsPartiallyLoaded
    
    eMEMORYINSTANCEUSAGE_IsHidden
    """

    def __init__(self: MSPyECObjects.MemoryInstanceUsageBitmask, value: int) -> None:
        ...
    
    eMEMORYINSTANCEUSAGE_Empty: MemoryInstanceUsageBitmask
    
    eMEMORYINSTANCEUSAGE_IsHidden: MemoryInstanceUsageBitmask
    
    eMEMORYINSTANCEUSAGE_IsPartiallyLoaded: MemoryInstanceUsageBitmask
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.MemoryInstanceUsageBitmask) -> int:
        ...
    
class MethodSymbol:
    """
    None
    """

    def Create(*args, **kwargs):
        """
        Create(name: str, staticMethod: std.function<Bentley.ECN.ExpressionStatus __cdecl(Bentley.ECN.EvaluationResult & __ptr64,Bentley.Bstdcxx.bvector<Bentley.ECN.EvaluationResult,Bentley.BentleyAllocator<Bentley.ECN.EvaluationResult> > & __ptr64)>, instanceMethod: std.function<Bentley.ECN.ExpressionStatus __cdecl(Bentley.ECN.EvaluationResult & __ptr64,Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > > const & __ptr64,Bentley.Bstdcxx.bvector<Bentley.ECN.EvaluationResult,Bentley.BentleyAllocator<Bentley.ECN.EvaluationResult> > & __ptr64)>) -> MSPyECObjects.MethodSymbol
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class Node:
    """
    None
    """

    def GetValue(*args, **kwargs):
        """
        GetValue(self: MSPyECObjects.Node, context: MSPyECObjects.ExpressionContext) -> tuple
        """
        ...
    
    def ToExpressionString(*args, **kwargs):
        """
        ToExpressionString(self: MSPyECObjects.Node) -> MSPyBentley.WString
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.Node) -> MSPyBentley.WString
        """
        ...
    
    def Traverse(*args, **kwargs):
        """
        Traverse(self: MSPyECObjects.Node, visitor: MSPyECObjects.NodeVisitor) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class NodeVisitor:
    """
    None
    """

    def CloseParens(*args, **kwargs):
        """
        CloseParens(self: MSPyECObjects.NodeVisitor) -> bool
        """
        ...
    
    def Comma(*args, **kwargs):
        """
        Comma(self: MSPyECObjects.NodeVisitor) -> bool
        """
        ...
    
    def EndArguments(*args, **kwargs):
        """
        EndArguments(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool
        """
        ...
    
    def EndArrayIndex(*args, **kwargs):
        """
        EndArrayIndex(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool
        """
        ...
    
    def OpenParens(*args, **kwargs):
        """
        OpenParens(self: MSPyECObjects.NodeVisitor) -> bool
        """
        ...
    
    def ProcessNode(*args, **kwargs):
        """
        ProcessNode(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool
        """
        ...
    
    def ProcessUnits(*args, **kwargs):
        """
        ProcessUnits(self: MSPyECObjects.NodeVisitor, units: Bentley.ECN.UnitSpec) -> bool
        """
        ...
    
    def StartArguments(*args, **kwargs):
        """
        StartArguments(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool
        """
        ...
    
    def StartArrayIndex(*args, **kwargs):
        """
        StartArrayIndex(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool
        """
        ...
    
    def __init__(self: MSPyECObjects.NodeVisitor) -> None:
        ...
    
class OrderIdEntries:
    """
    None
    """

    def Clear(*args, **kwargs):
        """
        Clear(self: MSPyECObjects.OrderIdEntries) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetSourceNextOrderId(*args, **kwargs):
        """
        SetSourceNextOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetSourceOrderId(*args, **kwargs):
        """
        SetSourceOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTargetNextOrderId(*args, **kwargs):
        """
        SetTargetNextOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTargetOrderId(*args, **kwargs):
        """
        SetTargetOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def TryGetSourceNextOrderId(*args, **kwargs):
        """
        TryGetSourceNextOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple
        """
        ...
    
    def TryGetSourceOrderId(*args, **kwargs):
        """
        TryGetSourceOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple
        """
        ...
    
    def TryGetTargetNextOrderId(*args, **kwargs):
        """
        TryGetTargetNextOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple
        """
        ...
    
    def TryGetTargetOrderId(*args, **kwargs):
        """
        TryGetTargetOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class OrderIdStorageMode:
    """
    Members:
    
    eORDERIDSTORAGEMODE_None
    
    eORDERIDSTORAGEMODE_ProvidedByPersistence
    
    eORDERIDSTORAGEMODE_ProvidedByClient
    """

    def __init__(self: MSPyECObjects.OrderIdStorageMode, value: int) -> None:
        ...
    
    eORDERIDSTORAGEMODE_None: OrderIdStorageMode
    
    eORDERIDSTORAGEMODE_ProvidedByClient: OrderIdStorageMode
    
    eORDERIDSTORAGEMODE_ProvidedByPersistence: OrderIdStorageMode
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.OrderIdStorageMode) -> int:
        ...
    
class PresentationMetadataHelper:
    """
    None
    """

    def HideProperty(*args, **kwargs):
        """
        HideProperty(*args, **kwargs)
        Overloaded function.
        
        1. HideProperty(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        
        2. HideProperty(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, hideIf2D: bool, hideIf3D: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetAlwaysExpand(*args, **kwargs):
        """
        SetAlwaysExpand(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, andArrayMembers: bool = False) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCustomCategory(*args, **kwargs):
        """
        SetCustomCategory(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, uniqueName: str, displayLabel: str, priority: int, expand: bool = False, description: str = None) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetExtendedType(*args, **kwargs):
        """
        SetExtendedType(*args, **kwargs)
        Overloaded function.
        
        1. SetExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, standardTypeId: int) -> MSPyECObjects.ECObjectsStatus
        
        2. SetExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, standardTypeName: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetHideNullProperties(*args, **kwargs):
        """
        SetHideNullProperties(self: MSPyECObjects.PresentationMetadataHelper, ecClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIgnoreZ(*args, **kwargs):
        """
        SetIgnoreZ(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetMemberExtendedType(*args, **kwargs):
        """
        SetMemberExtendedType(*args, **kwargs)
        Overloaded function.
        
        1. SetMemberExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ArrayECProperty, standardTypeId: int) -> MSPyECObjects.ECObjectsStatus
        
        2. SetMemberExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ArrayECProperty, standardTypeName: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetMembersIndependent(*args, **kwargs):
        """
        SetMembersIndependent(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetPriority(*args, **kwargs):
        """
        SetPriority(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, priority: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetRequiresReload(*args, **kwargs):
        """
        SetRequiresReload(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetStandardCategory(*args, **kwargs):
        """
        SetStandardCategory(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, standardCategoryId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetStoresUnitsAsUORs(*args, **kwargs):
        """
        SetStoresUnitsAsUORs(self: MSPyECObjects.PresentationMetadataHelper, ecSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def __init__(self: MSPyECObjects.PresentationMetadataHelper, schemaContext: MSPyECObjects.ECSchemaReadContext) -> None:
        ...
    
class PrimitiveECProperty:
    """
    None
    """

    def AsArrayProperty(*args, **kwargs):
        """
        AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty
        """
        ...
    
    def AsPrimitiveProperty(*args, **kwargs):
        """
        AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty
        """
        ...
    
    def AsStructProperty(*args, **kwargs):
        """
        AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty
        """
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetBaseProperty(*args, **kwargs):
        """
        GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECProperty) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetIsArray(*args, **kwargs):
        """
        GetIsArray(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsPrimitive(*args, **kwargs):
        """
        GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsReadOnly(*args, **kwargs):
        """
        GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsStruct(*args, **kwargs):
        """
        GetIsStruct(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetType(*args, **kwargs):
        """
        GetType(self: MSPyECObjects.PrimitiveECProperty) -> MSPyECObjects.PrimitiveType
        """
        ...
    
    def GetTypeName(*args, **kwargs):
        """
        GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECProperty) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def IsArray(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsCalculated(*args, **kwargs):
        """
        IsCalculated(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsPrimitive(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsReadOnly(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    @IsReadOnly.setter
    def IsReadOnly(arg0: MSPyECObjects.ECProperty, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsStruct(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(*args, **kwargs):
        """
        SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCalculatedPropertySpecification(*args, **kwargs):
        """
        SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool
        """
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        SetIsReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetType(*args, **kwargs):
        """
        SetType(self: MSPyECObjects.PrimitiveECProperty, type: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTypeName(*args, **kwargs):
        """
        SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Type(arg0: MSPyECObjects.PrimitiveECProperty) -> MSPyECObjects.PrimitiveType:
        ...
    @Type.setter
    def Type(arg0: MSPyECObjects.PrimitiveECProperty, arg1: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def TypeName(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @TypeName.setter
    def TypeName(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PrimitiveType:
    """
    Members:
    
    ePRIMITIVETYPE_Binary
    
    ePRIMITIVETYPE_Boolean
    
    ePRIMITIVETYPE_DateTime
    
    ePRIMITIVETYPE_Double
    
    ePRIMITIVETYPE_Integer
    
    ePRIMITIVETYPE_Long
    
    ePRIMITIVETYPE_Point2D
    
    ePRIMITIVETYPE_Point3D
    
    ePRIMITIVETYPE_String
    
    ePRIMITIVETYPE_IGeometry
    """

    def __init__(self: MSPyECObjects.PrimitiveType, value: int) -> None:
        ...
    
    ePRIMITIVETYPE_Binary: PrimitiveType
    
    ePRIMITIVETYPE_Boolean: PrimitiveType
    
    ePRIMITIVETYPE_DateTime: PrimitiveType
    
    ePRIMITIVETYPE_Double: PrimitiveType
    
    ePRIMITIVETYPE_IGeometry: PrimitiveType
    
    ePRIMITIVETYPE_Integer: PrimitiveType
    
    ePRIMITIVETYPE_Long: PrimitiveType
    
    ePRIMITIVETYPE_Point2D: PrimitiveType
    
    ePRIMITIVETYPE_Point3D: PrimitiveType
    
    ePRIMITIVETYPE_String: PrimitiveType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.PrimitiveType) -> int:
        ...
    
class PropertyFlagIndex:
    """
    Members:
    
    ePROPERTYFLAGINDEX_IsLoaded
    
    ePROPERTYFLAGINDEX_IsReadOnly
    """

    def __init__(self: MSPyECObjects.PropertyFlagIndex, value: int) -> None:
        ...
    
    ePROPERTYFLAGINDEX_IsLoaded: PropertyFlagIndex
    
    ePROPERTYFLAGINDEX_IsReadOnly: PropertyFlagIndex
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.PropertyFlagIndex) -> int:
        ...
    
class PropertyLayout:
    """
    None
    """

    @property
    def AccessString(arg0: MSPyECObjects.PropertyLayout) -> str:
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        GetAccessString(self: MSPyECObjects.PropertyLayout) -> str
        
        Returns the access string for retrieving this property
        """
        ...
    
    def GetModifierData(*args, **kwargs):
        """
        GetModifierData(self: MSPyECObjects.PropertyLayout) -> int
        
        Returns the data used with the modifier flag, like the length of a
        fixed-sized string.
        """
        ...
    
    def GetModifierFlags(*args, **kwargs):
        """
        GetModifierFlags(self: MSPyECObjects.PropertyLayout) -> int
        
        Returns the modifier flags that describe this property, which can
        indicate @li that a string should be treated as fixed size @li that a
        string should have a max length @li that a longer fixed size type
        should be treated as an optional variable-sized type @li that for a
        string, only an entry to the string table is stored @li a default
        value should be used
        """
        ...
    
    def GetNullflagsBitmask(*args, **kwargs):
        """
        GetNullflagsBitmask(self: MSPyECObjects.PropertyLayout) -> int
        
        Returns a bit mask that has the a single bit set. It can be used to
        AND with the bitmask at the offset returned by GetNullflagsOffset() to
        determine if the property is NULL.
        """
        ...
    
    def GetNullflagsOffset(*args, **kwargs):
        """
        GetNullflagsOffset(self: MSPyECObjects.PropertyLayout) -> int
        
        Returns the offset to Null flags bit mask.
        """
        ...
    
    def GetOffset(*args, **kwargs):
        """
        GetOffset(self: MSPyECObjects.PropertyLayout) -> int
        
        Returns the offset to either the data holding this property's value
        (for fixed-size values) or to the offset at which the property's value
        can be found
        """
        ...
    
    def GetParentStructIndex(*args, **kwargs):
        """
        GetParentStructIndex(self: MSPyECObjects.PropertyLayout) -> int
        
        Returns the property index of the struct parent of this property. If
        this is a root property an index of zero is returned.
        """
        ...
    
    def GetSizeInFixedSection(*args, **kwargs):
        """
        GetSizeInFixedSection(self: MSPyECObjects.PropertyLayout) -> int
        
        Gets the size required for this PropertyValue in the fixed Section of
        the IECInstance's memory Variable-sized types will have 4 byte
        SecondaryOffset stored in the fixed Section.
        """
        ...
    
    def GetTypeDescriptor(*args, **kwargs):
        """
        GetTypeDescriptor(self: MSPyECObjects.PropertyLayout) -> Bentley.ECN.ECTypeDescriptor
        
        Returns an ECTypeDescriptor that defines this property
        """
        ...
    
    def HoldsCalculatedProperty(*args, **kwargs):
        """
        HoldsCalculatedProperty(self: MSPyECObjects.PropertyLayout) -> bool
        
        Returns whether this property is actually a Calculated Property
        """
        ...
    
    def IsFixedSized(*args, **kwargs):
        """
        IsFixedSized(self: MSPyECObjects.PropertyLayout) -> bool
        
        Returns whether this is a fixed-size property
        """
        ...
    
    def IsReadOnlyProperty(*args, **kwargs):
        """
        IsReadOnlyProperty(self: MSPyECObjects.PropertyLayout) -> bool
        
        Returns whether this is a read-only property
        """
        ...
    
    @property
    def ModifierData(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    @property
    def ModifierFlags(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    @property
    def NullflagsBitmask(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    @property
    def NullflagsOffset(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    @property
    def Offset(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    @property
    def ParentStructIndex(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    @property
    def ReadOnlyProperty(arg0: MSPyECObjects.PropertyLayout) -> bool:
        ...
    @ReadOnlyProperty.setter
    def ReadOnlyProperty(arg0: MSPyECObjects.PropertyLayout, arg1: bool) -> bool:
        ...
    
    def SetReadOnlyProperty(*args, **kwargs):
        """
        SetReadOnlyProperty(self: MSPyECObjects.PropertyLayout, mask: bool) -> bool
        """
        ...
    
    @property
    def SizeInFixedSection(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.PropertyLayout) -> MSPyBentley.WString
        
        Returns a string containing detailed information about this property's
        characteristics (including access string, type name, offset,
        nullflagsOffset, nullflagsBitmask
        """
        ...
    
    @property
    def TypeDescriptor(arg0: MSPyECObjects.PropertyLayout) -> Bentley.ECN.ECTypeDescriptor:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class PropertySortPriority:
    """
    Members:
    
    eVeryHigh
    
    eHigh
    
    eMedium
    
    eLow
    
    eVeryLow
    """

    def __init__(self: MSPyECObjects.PropertySortPriority, value: int) -> None:
        ...
    
    eHigh: PropertySortPriority
    
    eLow: PropertySortPriority
    
    eMedium: PropertySortPriority
    
    eVeryHigh: PropertySortPriority
    
    eVeryLow: PropertySortPriority
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.PropertySortPriority) -> int:
        ...
    
class QualifiedECAccessor:
    """
    None
    """

    @property
    def AccessString(arg0: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    @AccessString.setter
    def AccessString(arg0: MSPyECObjects.QualifiedECAccessor, arg1: str) -> None:
        ...
    
    @property
    def ClassName(arg0: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    @ClassName.setter
    def ClassName(arg0: MSPyECObjects.QualifiedECAccessor, arg1: str) -> None:
        ...
    
    def FromAccessString(*args, **kwargs):
        """
        FromAccessString(self: MSPyECObjects.QualifiedECAccessor, rootEnabler: Bentley.ECN.ECEnabler, accessString: str) -> bool
        """
        ...
    
    def FromString(*args, **kwargs):
        """
        FromString(self: MSPyECObjects.QualifiedECAccessor, str: str) -> bool
        """
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        GetAccessString(self: MSPyECObjects.QualifiedECAccessor) -> str
        """
        ...
    
    def GetClassName(*args, **kwargs):
        """
        GetClassName(self: MSPyECObjects.QualifiedECAccessor) -> str
        """
        ...
    
    def GetSchemaName(*args, **kwargs):
        """
        GetSchemaName(self: MSPyECObjects.QualifiedECAccessor) -> str
        """
        ...
    
    @property
    def SchemaName(arg0: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    @SchemaName.setter
    def SchemaName(arg0: MSPyECObjects.QualifiedECAccessor, arg1: str) -> None:
        ...
    
    def SetAccessString(*args, **kwargs):
        """
        SetAccessString(self: MSPyECObjects.QualifiedECAccessor, accessString: str) -> None
        """
        ...
    
    def SetClassName(*args, **kwargs):
        """
        SetClassName(self: MSPyECObjects.QualifiedECAccessor, name: str) -> None
        """
        ...
    
    def SetSchemaName(*args, **kwargs):
        """
        SetSchemaName(self: MSPyECObjects.QualifiedECAccessor, name: str) -> None
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.QualifiedECAccessor) -> MSPyBentley.WString
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.QualifiedECAccessor) -> None
        
        2. __init__(self: MSPyECObjects.QualifiedECAccessor, schemaName: str, className: str, accessString: str) -> None
        """
        ...
    
class RelationshipCardinality:
    """
    None
    """

    def GetLowerLimit(*args, **kwargs):
        """
        GetLowerLimit(self: MSPyECObjects.RelationshipCardinality) -> int
        """
        ...
    
    def GetUpperLimit(*args, **kwargs):
        """
        GetUpperLimit(self: MSPyECObjects.RelationshipCardinality) -> int
        """
        ...
    
    def IsUpperLimitUnbounded(*args, **kwargs):
        """
        IsUpperLimitUnbounded(self: MSPyECObjects.RelationshipCardinality) -> bool
        """
        ...
    
    @property
    def LowerLimit(arg0: MSPyECObjects.RelationshipCardinality) -> int:
        ...
    
    def OneMany(*args, **kwargs):
        """
        OneMany() -> MSPyECObjects.RelationshipCardinality
        """
        ...
    
    def OneOne(*args, **kwargs):
        """
        OneOne() -> MSPyECObjects.RelationshipCardinality
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.RelationshipCardinality) -> MSPyBentley.WString
        """
        ...
    
    @property
    def UpperLimit(arg0: MSPyECObjects.RelationshipCardinality) -> int:
        ...
    
    def ZeroMany(*args, **kwargs):
        """
        ZeroMany() -> MSPyECObjects.RelationshipCardinality
        """
        ...
    
    def ZeroOne(*args, **kwargs):
        """
        ZeroOne() -> MSPyECObjects.RelationshipCardinality
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.RelationshipCardinality) -> None
        
        2. __init__(self: MSPyECObjects.RelationshipCardinality, lowerLimit: int, upperLimit: int) -> None
        """
        ...
    
class SchemaKey:
    """
    None
    """

    def ParseSchemaFullName(*args, **kwargs):
        """
        ParseSchemaFullName(key: MSPyECObjects.SchemaKey, schemaFullName: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SchemaKey) -> None
        
        2. __init__(self: MSPyECObjects.SchemaKey, name: str, majorVersion: int, minorVersion: int) -> None
        """
        ...
    
    @property
    def checkSum(self: MSPyECObjects.SchemaKey) -> int:
        ...
    @checkSum.setter
    def checkSum(self: MSPyECObjects.SchemaKey, arg0: int) -> None:
        ...
    
    @property
    def schemaName(self: MSPyECObjects.SchemaKey) -> MSPyBentley.WString:
        ...
    @schemaName.setter
    def schemaName(self: MSPyECObjects.SchemaKey, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def versionMajor(self: MSPyECObjects.SchemaKey) -> int:
        ...
    @versionMajor.setter
    def versionMajor(self: MSPyECObjects.SchemaKey, arg0: int) -> None:
        ...
    
    @property
    def versionMinor(self: MSPyECObjects.SchemaKey) -> int:
        ...
    @versionMinor.setter
    def versionMinor(self: MSPyECObjects.SchemaKey, arg0: int) -> None:
        ...
    
class SchemaKeyToSchemaBPair:
    """
    None
    """

    def GetFirst(*args, **kwargs):
        """
        GetFirst(self: MSPyECObjects.SchemaKeyToSchemaBPair) -> MSPyECObjects.SchemaKey
        """
        ...
    
    def GetSecond(*args, **kwargs):
        """
        GetSecond(self: MSPyECObjects.SchemaKeyToSchemaBPair) -> MSPyECObjects.ECSchema
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SchemaKeyToSchemaBPair) -> None
        
        2. __init__(self: MSPyECObjects.SchemaKeyToSchemaBPair, key: MSPyECObjects.SchemaKey, value: MSPyECObjects.ECSchema) -> None
        """
        ...
    
class SchemaLayout:
    """
    None
    """

    def AddClassLayout(*args, **kwargs):
        """
        AddClassLayout(self: MSPyECObjects.SchemaLayout, classLayout: MSPyECObjects.ClassLayout, classIndex: int) -> Bentley.BentleyStatus
        
        Adds the ClassLayout at the given index
        
        Parameter ``classLayout``:
        The ClassLayout to add
        
        Parameter ``classIndex``:
        The index where to add the ClassLayout
        
        Returns:
        ERROR if a class layout already exists with the given index
        """
        ...
    
    def FindAvailableClassIndex(*args, **kwargs):
        """
        FindAvailableClassIndex(self: MSPyECObjects.SchemaLayout) -> tuple
        
        Finds the first available index for adding a class layout
        
        
        Returns (Tuple, 0):
        SUCCESS if the index is found, ERROR otherwise
        
        Returns (Tuple, 1):
        classIndex.  The first available index in the layout. This is not necessarily
        the size of the layout because there can be gaps.
        """
        ...
    
    def FindClassIndex(*args, **kwargs):
        """
        FindClassIndex(self: MSPyECObjects.SchemaLayout, className: str) -> tuple
        
        Given a classname, tries to find the index of the corresponding
        ClassLayout
        
        
        Parameter ``className``:
        The name of the class to find the ClassLayout index of
        
        Returns (Tuple, 0):
        A pointer to the corresponding ClassLayout if found, NULL
        otherwise
        
        Returns (Tuple, 1):
        classIndex.  The index of the corresponding ClassLayout, if found
        """
        ...
    
    def FindClassLayout(*args, **kwargs):
        """
        FindClassLayout(self: MSPyECObjects.SchemaLayout, className: str) -> MSPyECObjects.ClassLayout
        
        Given a classname, tries to find the corresponding ClassLayout
        
        Parameter ``className``:
        The name of the class to find
        """
        ...
    
    def GetClassLayout(*args, **kwargs):
        """
        GetClassLayout(self: MSPyECObjects.SchemaLayout, classIndex: int) -> MSPyECObjects.ClassLayout
        
        Returns the ClassLayout at the given index
        
        Parameter ``classIndex``:
        The index of the desired ClassLayout
        
        Returns:
        A pointer to the requested ClassLayout if the index is valid, NULL
        otherwise
        """
        ...
    
    def GetMaxIndex(*args, **kwargs):
        """
        GetMaxIndex(self: MSPyECObjects.SchemaLayout) -> int
        
        Returns the max index in the ClassLayout
        
        Remark:
        s This may often correspond to " number of ClassLayouts - 1 ", but
        not necessarily, because there can be gaps so when you call
        GetClassLayout (index) you might get NULLs. Even the last one
        could be NULL.
        
        Remark:
        s NOTE:Check IsEmpty() before GetMaxIndex() to ensure there is at
        least one ClassLayout, otherwise the return value of GetMaxIndex()
        is undefined
        """
        ...
    
    def GetSchemaIndex(*args, **kwargs):
        """
        GetSchemaIndex(self: MSPyECObjects.SchemaLayout) -> int
        
        Gets the SchemaIndex of this particular SchemaLayout.
        """
        ...
    
    def IsEmpty(*args, **kwargs):
        """
        IsEmpty(self: MSPyECObjects.SchemaLayout) -> bool
        
        Returns whether or not this SchemaLayout has any ClassLayouts defined.
        """
        ...
    
    @property
    def MaxIndex(arg0: MSPyECObjects.SchemaLayout) -> int:
        ...
    
    def ReplaceClassLayout(*args, **kwargs):
        """
        ReplaceClassLayout(self: MSPyECObjects.SchemaLayout, classLayout: MSPyECObjects.ClassLayout, classIndex: int) -> Bentley.BentleyStatus
        
        Replaces the ClassLayout at the given index
        
        Parameter ``classLayout``:
        The ClassLayout to replace
        
        Parameter ``classIndex``:
        The index of the ClassLayout
        
        Returns:
        ERROR if the class index is out of range.
        """
        ...
    
    @property
    def SchemaIndex(arg0: MSPyECObjects.SchemaLayout) -> int:
        ...
    
    def __init__(self: MSPyECObjects.SchemaLayout, index: int) -> None:
        ...
    
class SchemaMapExact:
    """
    None
    """

    def __init__(self: MSPyECObjects.SchemaMapExact) -> None:
        ...
    
    def items(*args, **kwargs):
        """
        items(self: MSPyECObjects.SchemaMapExact) -> MSPyECObjects.ItemsView[SchemaMapExact]
        """
        ...
    
    def keys(*args, **kwargs):
        """
        keys(self: MSPyECObjects.SchemaMapExact) -> MSPyECObjects.KeysView[SchemaMapExact]
        """
        ...
    
    def values(*args, **kwargs):
        """
        values(self: MSPyECObjects.SchemaMapExact) -> MSPyECObjects.ValuesView[SchemaMapExact]
        """
        ...
    
class SchemaMatchType:
    """
    Members:
    
    eSCHEMAMATCHTYPE_Identical
    
    eSCHEMAMATCHTYPE_Exact
    
    eSCHEMAMATCHTYPE_LatestCompatible
    
    eSCHEMAMATCHTYPE_Latest
    """

    def __init__(self: MSPyECObjects.SchemaMatchType, value: int) -> None:
        ...
    
    eSCHEMAMATCHTYPE_Exact: SchemaMatchType
    
    eSCHEMAMATCHTYPE_Identical: SchemaMatchType
    
    eSCHEMAMATCHTYPE_Latest: SchemaMatchType
    
    eSCHEMAMATCHTYPE_LatestCompatible: SchemaMatchType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SchemaMatchType) -> int:
        ...
    
class SchemaNameClassNamePair:
    """
    None
    """

    def Parse(*args, **kwargs):
        """
        Parse(self: MSPyECObjects.SchemaNameClassNamePair, schemaAndClassNameSeparatedByColon: MSPyBentley.WString) -> bool
        """
        ...
    
    def ToColonSeparatedString(*args, **kwargs):
        """
        ToColonSeparatedString(self: MSPyECObjects.SchemaNameClassNamePair) -> MSPyBentley.WString
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SchemaNameClassNamePair) -> None
        
        2. __init__(self: MSPyECObjects.SchemaNameClassNamePair, schemaName: str, className: str) -> None
        
        3. __init__(self: MSPyECObjects.SchemaNameClassNamePair, schemaAndClassNameSeparatedByColon: MSPyBentley.WString) -> None
        """
        ...
    
    @property
    def className(self: MSPyECObjects.SchemaNameClassNamePair) -> MSPyBentley.WString:
        ...
    @className.setter
    def className(self: MSPyECObjects.SchemaNameClassNamePair, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def schemaName(self: MSPyECObjects.SchemaNameClassNamePair) -> MSPyBentley.WString:
        ...
    @schemaName.setter
    def schemaName(self: MSPyECObjects.SchemaNameClassNamePair, arg0: MSPyBentley.WString) -> None:
        ...
    
class SchemaNameClassNamePairArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SchemaNameClassNamePairArray) -> None
        
        2. __init__(self: MSPyECObjects.SchemaNameClassNamePairArray, arg0: MSPyECObjects.SchemaNameClassNamePairArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.SchemaNameClassNamePairArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.SchemaNameClassNamePairArray, x: MSPyECObjects.SchemaNameClassNamePair) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.SchemaNameClassNamePairArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.SchemaNameClassNamePairArray, x: MSPyECObjects.SchemaNameClassNamePair) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.SchemaNameClassNamePairArray, L: MSPyECObjects.SchemaNameClassNamePairArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.SchemaNameClassNamePairArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.SchemaNameClassNamePairArray, i: int, x: MSPyECObjects.SchemaNameClassNamePair) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.SchemaNameClassNamePairArray) -> MSPyECObjects.SchemaNameClassNamePair
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.SchemaNameClassNamePairArray, i: int) -> MSPyECObjects.SchemaNameClassNamePair
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.SchemaNameClassNamePairArray, x: MSPyECObjects.SchemaNameClassNamePair) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class SchemaReadStatus:
    """
    Members:
    
    eSCHEMA_READ_STATUS_Success
    
    eSCHEMA_READ_STATUS_FailedToParseXml
    
    eSCHEMA_READ_STATUS_InvalidECSchemaXml
    
    eSCHEMA_READ_STATUS_ReferencedSchemaNotFound
    
    eSCHEMA_READ_STATUS_DuplicateSchema
    
    eSCHEMA_READ_STATUS_InvalidPrimitiveType
    
    eSCHEMA_READ_STATUS_HasReferenceCycle
    """

    def __init__(self: MSPyECObjects.SchemaReadStatus, value: int) -> None:
        ...
    
    eSCHEMA_READ_STATUS_DuplicateSchema: SchemaReadStatus
    
    eSCHEMA_READ_STATUS_FailedToParseXml: SchemaReadStatus
    
    eSCHEMA_READ_STATUS_HasReferenceCycle: SchemaReadStatus
    
    eSCHEMA_READ_STATUS_InvalidECSchemaXml: SchemaReadStatus
    
    eSCHEMA_READ_STATUS_InvalidPrimitiveType: SchemaReadStatus
    
    eSCHEMA_READ_STATUS_ReferencedSchemaNotFound: SchemaReadStatus
    
    eSCHEMA_READ_STATUS_Success: SchemaReadStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SchemaReadStatus) -> int:
        ...
    
class SchemaWriteStatus:
    """
    Members:
    
    eSCHEMA_WRITE_STATUS_Success
    
    eSCHEMA_WRITE_STATUS_FailedToSaveXml
    
    eSCHEMA_WRITE_STATUS_FailedToCreateXml
    
    eSCHEMA_WRITE_STATUS_FailedToWriteFile
    """

    def __init__(self: MSPyECObjects.SchemaWriteStatus, value: int) -> None:
        ...
    
    eSCHEMA_WRITE_STATUS_FailedToCreateXml: SchemaWriteStatus
    
    eSCHEMA_WRITE_STATUS_FailedToSaveXml: SchemaWriteStatus
    
    eSCHEMA_WRITE_STATUS_FailedToWriteFile: SchemaWriteStatus
    
    eSCHEMA_WRITE_STATUS_Success: SchemaWriteStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SchemaWriteStatus) -> int:
        ...
    
class StandaloneECEnabler:
    """
    None
    """

    @property
    def Class(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    @property
    def ClassLayout(arg0: MSPyECObjects.StandaloneECEnabler) -> MSPyECObjects.ClassLayout:
        ...
    
    def CreateInstance(*args, **kwargs):
        """
        CreateInstance(self: MSPyECObjects.StandaloneECEnabler, minimumInitialSize: int = 0) -> MSPyECObjects.StandaloneECInstance
        """
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetClassLayout(*args, **kwargs):
        """
        GetClassLayout(self: MSPyECObjects.StandaloneECEnabler) -> MSPyECObjects.ClassLayout
        """
        ...
    
    def GetEnablerForStructArrayMember(*args, **kwargs):
        """
        GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler
        """
        ...
    
    def GetFirstPropertyIndex(*args, **kwargs):
        """
        GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECEnabler) -> str
        """
        ...
    
    def GetNextPropertyIndex(*args, **kwargs):
        """
        GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int
        """
        ...
    
    def GetParentPropertyIndex(*args, **kwargs):
        """
        GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int
        """
        ...
    
    def GetPropertyIndex(*args, **kwargs):
        """
        GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple
        """
        ...
    
    def GetPropertyIndices(*args, **kwargs):
        """
        GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentley.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetStandaloneEnablerLocater(*args, **kwargs):
        """
        GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater
        """
        ...
    
    def HasChildProperties(*args, **kwargs):
        """
        HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECEnabler) -> str:
        ...
    
    @property
    def StandaloneEnablerLocater(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def __init__(self: MSPyECObjects.StandaloneECEnabler, ecClass: MSPyECObjects.ECClass, classLayout: MSPyECObjects.ClassLayout, structStandaloneEnablerLocater: MSPyECObjects.IStandaloneEnablerLocater) -> None:
        ...
    
class StandaloneECInstance:
    """
    None
    """

    def AddArrayElements(*args, **kwargs):
        """
        AddArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(*args, **kwargs):
        """
        AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase
        """
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        ChangeValue(*args, **kwargs)
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(*args, **kwargs):
        """
        ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        ClearArray(*args, **kwargs)
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(*args, **kwargs):
        """
        CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
        CreateCopyThroughSerialization(*args, **kwargs)
        Overloaded function.
        
        1. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance) -> MSPyECObjects.IECInstance
        
        2. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance, targetSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.IECInstance
        """
        ...
    
    def Duplicate(*args, **kwargs):
        """
        Duplicate(instance: MSPyECObjects.IECInstance) -> MSPyECObjects.StandaloneECInstance
        """
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetECDBuffer(*args, **kwargs):
        """
        GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer
        """
        ...
    
    def GetEnabler(*args, **kwargs):
        """
        GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler
        """
        ...
    
    def GetInstanceId(*args, **kwargs):
        """
        GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetInstanceIdForSerialization(*args, **kwargs):
        """
        GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetOffsetToIECInstance(*args, **kwargs):
        """
        GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int
        """
        ...
    
    def GetValue(*args, **kwargs):
        """
        GetValue(*args, **kwargs)
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(*args, **kwargs):
        """
        GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
        InsertArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. InsertArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        
        2. InsertArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def InstanceId(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    @InstanceId.setter
    def InstanceId(arg0: MSPyECObjects.IECInstance, arg1: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def InstanceIdForSerialization(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def IsFixedArrayProperty(*args, **kwargs):
        """
        IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple
        """
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        IsPropertyNull(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        IsPropertyReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(*args, **kwargs):
        """
        IsReadOnly(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def ReadFromXmlFile(*args, **kwargs):
        """
        ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def ReadFromXmlString(*args, **kwargs):
        """
        ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        RemoveArrayElement(*args, **kwargs)
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(*args, **kwargs):
        """
        SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetInstanceId(*args, **kwargs):
        """
        SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValue(*args, **kwargs):
        """
        SetValue(*args, **kwargs)
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(*args, **kwargs):
        """
        SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString
        """
        ...
    
    def WriteToXmlFile(*args, **kwargs):
        """
        WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
        WriteToXmlString(*args, **kwargs)
        Overloaded function.
        
        1. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.Utf8String, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        
        2. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.WString, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class StandaloneECInstancePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.StandaloneECInstancePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.StandaloneECInstancePtrArray, arg0: MSPyECObjects.StandaloneECInstancePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.StandaloneECInstancePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.StandaloneECInstancePtrArray, x: MSPyECObjects.StandaloneECInstance) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.StandaloneECInstancePtrArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.StandaloneECInstancePtrArray, x: MSPyECObjects.StandaloneECInstance) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.StandaloneECInstancePtrArray, L: MSPyECObjects.StandaloneECInstancePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.StandaloneECInstancePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.StandaloneECInstancePtrArray, i: int, x: MSPyECObjects.StandaloneECInstance) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.StandaloneECInstancePtrArray) -> MSPyECObjects.StandaloneECInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.StandaloneECInstancePtrArray, i: int) -> MSPyECObjects.StandaloneECInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.StandaloneECInstancePtrArray, x: MSPyECObjects.StandaloneECInstance) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class StandaloneECRelationshipEnabler:
    """
    None
    """

    @property
    def Class(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    @property
    def ClassLayout(arg0: MSPyECObjects.StandaloneECEnabler) -> MSPyECObjects.ClassLayout:
        ...
    
    def CreateInstance(*args, **kwargs):
        """
        CreateInstance(self: MSPyECObjects.StandaloneECEnabler, minimumInitialSize: int = 0) -> MSPyECObjects.StandaloneECInstance
        """
        ...
    
    def CreateRelationshipInstance(*args, **kwargs):
        """
        CreateRelationshipInstance(self: MSPyECObjects.StandaloneECRelationshipEnabler) -> MSPyECObjects.StandaloneECRelationshipInstance
        """
        ...
    
    @property
    def ECEnabler(arg0: MSPyECObjects.StandaloneECRelationshipEnabler) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetClassLayout(*args, **kwargs):
        """
        GetClassLayout(self: MSPyECObjects.StandaloneECEnabler) -> MSPyECObjects.ClassLayout
        """
        ...
    
    def GetECEnabler(*args, **kwargs):
        """
        GetECEnabler(self: MSPyECObjects.StandaloneECRelationshipEnabler) -> MSPyECObjects.ECEnabler
        """
        ...
    
    def GetEnablerForStructArrayMember(*args, **kwargs):
        """
        GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler
        """
        ...
    
    def GetFirstPropertyIndex(*args, **kwargs):
        """
        GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECEnabler) -> str
        """
        ...
    
    def GetNextPropertyIndex(*args, **kwargs):
        """
        GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int
        """
        ...
    
    def GetParentPropertyIndex(*args, **kwargs):
        """
        GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int
        """
        ...
    
    def GetPropertyIndex(*args, **kwargs):
        """
        GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple
        """
        ...
    
    def GetPropertyIndices(*args, **kwargs):
        """
        GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentley.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetStandaloneEnablerLocater(*args, **kwargs):
        """
        GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater
        """
        ...
    
    def HasChildProperties(*args, **kwargs):
        """
        HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECEnabler) -> str:
        ...
    
    @property
    def StandaloneEnablerLocater(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.StandaloneECRelationshipEnabler, ecClass: MSPyECObjects.ECRelationshipClass) -> None
        
        2. __init__(self: MSPyECObjects.StandaloneECRelationshipEnabler, ecClass: MSPyECObjects.ECRelationshipClass, classLayout: MSPyECObjects.ClassLayout, structStandaloneEnablerLocater: MSPyECObjects.IStandaloneEnablerLocater) -> None
        """
        ...
    
class StandaloneECRelationshipInstance:
    """
    None
    """

    def AddArrayElements(*args, **kwargs):
        """
        AddArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(*args, **kwargs):
        """
        AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase
        """
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        ChangeValue(*args, **kwargs)
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(*args, **kwargs):
        """
        ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        ClearArray(*args, **kwargs)
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(*args, **kwargs):
        """
        CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
        CreateCopyThroughSerialization(*args, **kwargs)
        Overloaded function.
        
        1. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance) -> MSPyECObjects.IECInstance
        
        2. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance, targetSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.IECInstance
        """
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetECDBuffer(*args, **kwargs):
        """
        GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer
        """
        ...
    
    def GetEnabler(*args, **kwargs):
        """
        GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler
        """
        ...
    
    def GetInstanceId(*args, **kwargs):
        """
        GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetInstanceIdForSerialization(*args, **kwargs):
        """
        GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString
        """
        ...
    
    def GetOffsetToIECInstance(*args, **kwargs):
        """
        GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int
        """
        ...
    
    def GetRelationshipClass(*args, **kwargs):
        """
        GetRelationshipClass(self: MSPyECObjects.StandaloneECRelationshipInstance) -> MSPyECObjects.ECRelationshipClass
        """
        ...
    
    def GetRelationshipEnabler(*args, **kwargs):
        """
        GetRelationshipEnabler(self: MSPyECObjects.StandaloneECRelationshipInstance) -> Bentley.ECN.StandaloneECRelationshipEnabler
        """
        ...
    
    def GetSource(*args, **kwargs):
        """
        GetSource(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetSourceAssociatedString(*args, **kwargs):
        """
        GetSourceAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance) -> str
        """
        ...
    
    def GetSourceOrderId(*args, **kwargs):
        """
        GetSourceOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple
        """
        ...
    
    def GetTarget(*args, **kwargs):
        """
        GetTarget(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetTargetAssociatedString(*args, **kwargs):
        """
        GetTargetAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance) -> str
        """
        ...
    
    def GetTargetOrderId(*args, **kwargs):
        """
        GetTargetOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple
        """
        ...
    
    def GetValue(*args, **kwargs):
        """
        GetValue(*args, **kwargs)
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(*args, **kwargs):
        """
        GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
        InsertArrayElements(*args, **kwargs)
        Overloaded function.
        
        1. InsertArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        
        2. InsertArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def InstanceId(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    @InstanceId.setter
    def InstanceId(arg0: MSPyECObjects.IECInstance, arg1: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def InstanceIdForSerialization(arg0: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def IsFixedArrayProperty(*args, **kwargs):
        """
        IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple
        """
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        IsPropertyNull(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        IsPropertyReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(*args, **kwargs):
        """
        IsReadOnly(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def OrderIdEntries(*args, **kwargs):
        """
        OrderIdEntries(self: MSPyECObjects.StandaloneECRelationshipInstance) -> MSPyECObjects.OrderIdEntries
        """
        ...
    
    def ReadFromXmlFile(*args, **kwargs):
        """
        ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    def ReadFromXmlString(*args, **kwargs):
        """
        ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple
        """
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    @property
    def RelationshipEnabler(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> Bentley.ECN.StandaloneECRelationshipEnabler:
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        RemoveArrayElement(*args, **kwargs)
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(*args, **kwargs):
        """
        SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetInstanceId(*args, **kwargs):
        """
        SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetSource(*args, **kwargs):
        """
        SetSource(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None
        """
        ...
    
    def SetSourceAssociatedString(*args, **kwargs):
        """
        SetSourceAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance, string: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetSourceOrderId(*args, **kwargs):
        """
        SetSourceOrderId(self: MSPyECObjects.StandaloneECRelationshipInstance, orderId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTarget(*args, **kwargs):
        """
        SetTarget(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None
        """
        ...
    
    def SetTargetAssociatedString(*args, **kwargs):
        """
        SetTargetAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance, string: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTargetOrderId(*args, **kwargs):
        """
        SetTargetOrderId(self: MSPyECObjects.StandaloneECRelationshipInstance, orderId: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValue(*args, **kwargs):
        """
        SetValue(*args, **kwargs)
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(*args, **kwargs):
        """
        SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Source(arg0: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    @Source.setter
    def Source(arg0: MSPyECObjects.IECRelationshipInstance, arg1: MSPyECObjects.IECInstance) -> None:
        ...
    
    @property
    def SourceAssociatedString(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> str:
        ...
    @SourceAssociatedString.setter
    def SourceAssociatedString(arg0: MSPyECObjects.StandaloneECRelationshipInstance, arg1: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Target(arg0: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    @Target.setter
    def Target(arg0: MSPyECObjects.IECRelationshipInstance, arg1: MSPyECObjects.IECInstance) -> None:
        ...
    
    @property
    def TargetAssociatedString(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> str:
        ...
    @TargetAssociatedString.setter
    def TargetAssociatedString(arg0: MSPyECObjects.StandaloneECRelationshipInstance, arg1: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ToString(*args, **kwargs):
        """
        ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString
        """
        ...
    
    def WriteToXmlFile(*args, **kwargs):
        """
        WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
        WriteToXmlString(*args, **kwargs)
        Overloaded function.
        
        1. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.Utf8String, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        
        2. WriteToXmlString(self: MSPyECObjects.IECInstance, ecInstanceXml: MSPyBentley.WString, isStandAlone: bool, writeInsanceId: bool) -> MSPyECObjects.InstanceWriteStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class StandardCustomAttributeHelper:
    """
    None
    """

    def CreateCustomAttributeInstance(*args, **kwargs):
        """
        CreateCustomAttributeInstance(atributeName: str) -> MSPyECObjects.IECInstance
        """
        ...
    
    def GetCustomAttributeClass(*args, **kwargs):
        """
        GetCustomAttributeClass(attributeName: str) -> MSPyECObjects.ECClass
        """
        ...
    
    def IsDynamicSchema(*args, **kwargs):
        """
        IsDynamicSchema(schema: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def IsSystemSchema(*args, **kwargs):
        """
        IsSystemSchema(schema: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def SetIsDynamicSchema(*args, **kwargs):
        """
        SetIsDynamicSchema(schema: MSPyECObjects.ECSchema, isDynamicSchema: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def TryGetDateTimeInfo(*args, **kwargs):
        """
        TryGetDateTimeInfo(dateTimeInfo: MSPyECObjects.DateTimeInfo, dateTimeProperty: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class StrengthType:
    """
    Members:
    
    eSTRENGTHTYPE_Referencing
    
    eSTRENGTHTYPE_Holding
    
    eSTRENGTHTYPE_Embedding
    """

    def __init__(self: MSPyECObjects.StrengthType, value: int) -> None:
        ...
    
    eSTRENGTHTYPE_Embedding: StrengthType
    
    eSTRENGTHTYPE_Holding: StrengthType
    
    eSTRENGTHTYPE_Referencing: StrengthType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.StrengthType) -> int:
        ...
    
class StructECProperty:
    """
    None
    """

    def AsArrayProperty(*args, **kwargs):
        """
        AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty
        """
        ...
    
    def AsPrimitiveProperty(*args, **kwargs):
        """
        AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty
        """
        ...
    
    def AsStructProperty(*args, **kwargs):
        """
        AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty
        """
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    @property
    def Description(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @Description.setter
    def Description(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @DisplayLabel.setter
    def DisplayLabel(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetBaseProperty(*args, **kwargs):
        """
        GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetClass(*args, **kwargs):
        """
        GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass
        """
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        GetCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        GetCustomAttributeLocal(*args, **kwargs)
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(*args, **kwargs):
        """
        GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetDescription(*args, **kwargs):
        """
        GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetDisplayLabel(*args, **kwargs):
        """
        GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetId(*args, **kwargs):
        """
        GetId(self: MSPyECObjects.ECProperty) -> int
        """
        ...
    
    def GetInvariantDescription(*args, **kwargs):
        """
        GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetInvariantDisplayLabel(*args, **kwargs):
        """
        GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetIsArray(*args, **kwargs):
        """
        GetIsArray(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsDisplayLabelDefined(*args, **kwargs):
        """
        GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsPrimitive(*args, **kwargs):
        """
        GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsReadOnly(*args, **kwargs):
        """
        GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetIsStruct(*args, **kwargs):
        """
        GetIsStruct(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def GetName(*args, **kwargs):
        """
        GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        GetPrimaryCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(*args, **kwargs):
        """
        GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable
        """
        ...
    
    def GetType(*args, **kwargs):
        """
        GetType(self: MSPyECObjects.StructECProperty) -> Bentley.ECN.ECClass
        """
        ...
    
    def GetTypeName(*args, **kwargs):
        """
        GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.ECProperty) -> int:
        ...
    
    @property
    def InvariantDescription(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantDisplayLabel(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    @property
    def IsArray(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsCalculated(*args, **kwargs):
        """
        IsCalculated(self: MSPyECObjects.ECProperty) -> bool
        """
        ...
    
    def IsDefined(*args, **kwargs):
        """
        IsDefined(*args, **kwargs)
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    @property
    def IsDisplayLabelDefined(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsPrimitive(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def IsReadOnly(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    @IsReadOnly.setter
    def IsReadOnly(arg0: MSPyECObjects.ECProperty, arg1: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def IsStruct(arg0: MSPyECObjects.ECProperty) -> bool:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        RemoveCustomAttribute(*args, **kwargs)
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(*args, **kwargs):
        """
        SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCalculatedPropertySpecification(*args, **kwargs):
        """
        SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool
        """
        ...
    
    def SetCustomAttribute(*args, **kwargs):
        """
        SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDescription(*args, **kwargs):
        """
        SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetDisplayLabel(*args, **kwargs):
        """
        SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        SetIsReadOnly(*args, **kwargs)
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetType(*args, **kwargs):
        """
        SetType(self: MSPyECObjects.StructECProperty, type: Bentley.ECN.ECClass) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTypeName(*args, **kwargs):
        """
        SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def Type(arg0: MSPyECObjects.StructECProperty) -> Bentley.ECN.ECClass:
        ...
    @Type.setter
    def Type(arg0: MSPyECObjects.StructECProperty, arg1: Bentley.ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def TypeName(arg0: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    @TypeName.setter
    def TypeName(arg0: MSPyECObjects.ECProperty, arg1: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SupplementalSchemaInfo:
    """
    None
    """

    def GetPrimarySchemaFullName(*args, **kwargs):
        """
        GetPrimarySchemaFullName(self: MSPyECObjects.SupplementalSchemaInfo) -> MSPyBentley.WString
        """
        ...
    
    def GetPurposeOfSupplementalSchema(*args, **kwargs):
        """
        GetPurposeOfSupplementalSchema(self: MSPyECObjects.SupplementalSchemaInfo, fullSchemaName: MSPyBentley.WString) -> MSPyBentley.WString
        """
        ...
    
    def GetSupplementalSchemaNames(*args, **kwargs):
        """
        GetSupplementalSchemaNames(self: MSPyECObjects.SupplementalSchemaInfo, supplementalSchemaNames: MSPyBentley.WStringArray) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetSupplementalSchemasWithPurpose(*args, **kwargs):
        """
        GetSupplementalSchemasWithPurpose(self: MSPyECObjects.SupplementalSchemaInfo, supplementalSchemaNames: MSPyBentley.WStringArray, purpose: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def HasSameSupplementalSchemasForPurpose(*args, **kwargs):
        """
        HasSameSupplementalSchemasForPurpose(self: MSPyECObjects.SupplementalSchemaInfo, secondSchema: MSPyECObjects.ECSchema, purpose: MSPyBentley.WString) -> bool
        """
        ...
    
    @property
    def PrimarySchemaFullName(arg0: MSPyECObjects.SupplementalSchemaInfo) -> MSPyBentley.WString:
        ...
    
    def __init__(self: MSPyECObjects.SupplementalSchemaInfo, primarySchemaFullName: MSPyBentley.WString, schemaFullNameToPurposeMapping: MSPyBentley.WStringWStringMap) -> None:
        ...
    
class SupplementalSchemaMetaData:
    """
    None
    """

    def CreateCustomAttribute(*args, **kwargs):
        """
        CreateCustomAttribute(self: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyECObjects.IECInstance
        """
        ...
    
    CustomAttributeAccessor: str
    
    CustomAttributeSchemaName: str
    
    def GetCustomAttributeAccessor(*args, **kwargs):
        """
        GetCustomAttributeAccessor() -> str
        """
        ...
    
    def GetCustomAttributeSchemaName(*args, **kwargs):
        """
        GetCustomAttributeSchemaName() -> str
        """
        ...
    
    def GetIsUserSpecificPropertyAccessor(*args, **kwargs):
        """
        GetIsUserSpecificPropertyAccessor() -> str
        """
        ...
    
    def GetPrecedencePropertyAccessor(*args, **kwargs):
        """
        GetPrecedencePropertyAccessor() -> str
        """
        ...
    
    def GetPrimarySchemaMajorVersion(*args, **kwargs):
        """
        GetPrimarySchemaMajorVersion(self: MSPyECObjects.SupplementalSchemaMetaData) -> int
        """
        ...
    
    def GetPrimarySchemaMajorVersionPropertyAccessor(*args, **kwargs):
        """
        GetPrimarySchemaMajorVersionPropertyAccessor() -> str
        """
        ...
    
    def GetPrimarySchemaMinorVersion(*args, **kwargs):
        """
        GetPrimarySchemaMinorVersion(self: MSPyECObjects.SupplementalSchemaMetaData) -> int
        """
        ...
    
    def GetPrimarySchemaMinorVersionPropertyAccessor(*args, **kwargs):
        """
        GetPrimarySchemaMinorVersionPropertyAccessor() -> str
        """
        ...
    
    def GetPrimarySchemaName(*args, **kwargs):
        """
        GetPrimarySchemaName(self: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyBentley.WString
        """
        ...
    
    def GetPrimarySchemaNamePropertyAccessor(*args, **kwargs):
        """
        GetPrimarySchemaNamePropertyAccessor() -> str
        """
        ...
    
    def GetPurposePropertyAccessor(*args, **kwargs):
        """
        GetPurposePropertyAccessor() -> str
        """
        ...
    
    def GetSupplementalSchemaPrecedence(*args, **kwargs):
        """
        GetSupplementalSchemaPrecedence(self: MSPyECObjects.SupplementalSchemaMetaData) -> int
        """
        ...
    
    def GetSupplementalSchemaPurpose(*args, **kwargs):
        """
        GetSupplementalSchemaPurpose(self: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyBentley.WString
        """
        ...
    
    def IsForPrimarySchema(*args, **kwargs):
        """
        IsForPrimarySchema(self: MSPyECObjects.SupplementalSchemaMetaData, schemaName: MSPyBentley.WString, majorVersion: int, minorVersion: int, matchType: MSPyECObjects.SchemaMatchType) -> bool
        """
        ...
    
    def IsSupplemental(*args, **kwargs):
        """
        IsSupplemental(self: MSPyECObjects.SupplementalSchemaMetaData, schema: MSPyECObjects.ECSchema) -> bool
        """
        ...
    
    def IsUserSpecific(*args, **kwargs):
        """
        IsUserSpecific(self: MSPyECObjects.SupplementalSchemaMetaData) -> bool
        """
        ...
    
    IsUserSpecificPropertyAccessor: str
    
    PrecedencePropertyAccessor: str
    
    @property
    def PrimarySchemaMajorVersion(arg0: MSPyECObjects.SupplementalSchemaMetaData) -> int:
        ...
    @PrimarySchemaMajorVersion.setter
    def PrimarySchemaMajorVersion(arg0: MSPyECObjects.SupplementalSchemaMetaData, arg1: int) -> None:
        ...
    
    PrimarySchemaMajorVersionPropertyAccessor: str
    
    @property
    def PrimarySchemaMinorVersion(arg0: MSPyECObjects.SupplementalSchemaMetaData) -> int:
        ...
    @PrimarySchemaMinorVersion.setter
    def PrimarySchemaMinorVersion(arg0: MSPyECObjects.SupplementalSchemaMetaData, arg1: int) -> None:
        ...
    
    PrimarySchemaMinorVersionPropertyAccessor: str
    
    @property
    def PrimarySchemaName(arg0: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyBentley.WString:
        ...
    @PrimarySchemaName.setter
    def PrimarySchemaName(arg0: MSPyECObjects.SupplementalSchemaMetaData, arg1: MSPyBentley.WString) -> None:
        ...
    
    PrimarySchemaNamePropertyAccessor: str
    
    PurposePropertyAccessor: str
    
    def SetMetadata(*args, **kwargs):
        """
        SetMetadata(supplementalSchema: MSPyECObjects.ECSchema, supplementalSchemaMetadata: MSPyECObjects.SupplementalSchemaMetaData) -> None
        """
        ...
    
    def SetPrimarySchemaMajorVersion(*args, **kwargs):
        """
        SetPrimarySchemaMajorVersion(self: MSPyECObjects.SupplementalSchemaMetaData, major: int) -> None
        """
        ...
    
    def SetPrimarySchemaMinorVersion(*args, **kwargs):
        """
        SetPrimarySchemaMinorVersion(self: MSPyECObjects.SupplementalSchemaMetaData, minor: int) -> None
        """
        ...
    
    def SetPrimarySchemaName(*args, **kwargs):
        """
        SetPrimarySchemaName(self: MSPyECObjects.SupplementalSchemaMetaData, name: MSPyBentley.WString) -> None
        """
        ...
    
    def SetSupplementalSchemaPrecedence(*args, **kwargs):
        """
        SetSupplementalSchemaPrecedence(self: MSPyECObjects.SupplementalSchemaMetaData, precedence: int) -> None
        """
        ...
    
    def SetSupplementalSchemaPurpose(*args, **kwargs):
        """
        SetSupplementalSchemaPurpose(self: MSPyECObjects.SupplementalSchemaMetaData, purpose: MSPyBentley.WString) -> None
        """
        ...
    
    def SetUserSpecific(*args, **kwargs):
        """
        SetUserSpecific(self: MSPyECObjects.SupplementalSchemaMetaData, userSpecific: bool) -> None
        """
        ...
    
    @property
    def SupplementalSchemaPrecedence(arg0: MSPyECObjects.SupplementalSchemaMetaData) -> int:
        ...
    @SupplementalSchemaPrecedence.setter
    def SupplementalSchemaPrecedence(arg0: MSPyECObjects.SupplementalSchemaMetaData, arg1: int) -> None:
        ...
    
    @property
    def SupplementalSchemaPurpose(arg0: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyBentley.WString:
        ...
    @SupplementalSchemaPurpose.setter
    def SupplementalSchemaPurpose(arg0: MSPyECObjects.SupplementalSchemaMetaData, arg1: MSPyBentley.WString) -> None:
        ...
    
    def TryGetFromSchema(*args, **kwargs):
        """
        TryGetFromSchema(supplementalSchema: MSPyECObjects.ECSchema) -> tuple
        """
        ...
    
    @property
    def UserSpecific(arg0: MSPyECObjects.SupplementalSchemaMetaData) -> bool:
        ...
    @UserSpecific.setter
    def UserSpecific(arg0: MSPyECObjects.SupplementalSchemaMetaData, arg1: bool) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SupplementalSchemaMetaData, schemaName: MSPyBentley.WString, majorVersion: int, minorVersion: int, schemaPrecedence: int, schemaPurpose: MSPyBentley.WString, isUserSpecific: bool) -> None
        
        2. __init__(self: MSPyECObjects.SupplementalSchemaMetaData, schemaMetaDataCustomAttribute: MSPyECObjects.IECInstance) -> None
        """
        ...
    
class SupplementedSchemaBuilder:
    """
    None
    """

    class SchemaPrecedence:
        """
        Members:
        
        eSCHEMA_PRECEDENCE_Lower
        
        eSCHEMA_PRECEDENCE_Equal
        
        eSCHEMA_PRECEDENCE_Greater
        """
    
        def __init__(self: MSPyECObjects.SupplementedSchemaBuilder.SchemaPrecedence, value: int) -> None:
            ...
        
        eSCHEMA_PRECEDENCE_Equal: SchemaPrecedence
        
        eSCHEMA_PRECEDENCE_Greater: SchemaPrecedence
        
        eSCHEMA_PRECEDENCE_Lower: SchemaPrecedence
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.SupplementedSchemaBuilder.SchemaPrecedence) -> int:
            ...
        
    def UpdateSchema(*args, **kwargs):
        """
        UpdateSchema(*args, **kwargs)
        Overloaded function.
        
        1. UpdateSchema(self: MSPyECObjects.SupplementedSchemaBuilder, primarySchema: MSPyECObjects.ECSchema, supplementalSchemaList: MSPyECObjects.ECSchemaPArray) -> MSPyECObjects.SupplementedSchemaStatus
        
        2. UpdateSchema(self: MSPyECObjects.SupplementedSchemaBuilder, primarySchema: MSPyECObjects.ECSchema, supplementalSchemaList: MSPyECObjects.ECSchemaPArray, locale: str) -> MSPyECObjects.SupplementedSchemaStatus
        """
        ...
    
    def __init__(self: MSPyECObjects.SupplementedSchemaBuilder) -> None:
        ...
    
    eSCHEMA_PRECEDENCE_Equal: SchemaPrecedence
    
    eSCHEMA_PRECEDENCE_Greater: SchemaPrecedence
    
    eSCHEMA_PRECEDENCE_Lower: SchemaPrecedence
    
class SupplementedSchemaStatus:
    """
    Members:
    
    eSUPPLEMENTED_SCHEMA_STATUS_Success
    
    eSUPPLEMENTED_SCHEMA_STATUS_Metadata_Missing
    
    eSUPPLEMENTED_SCHEMA_STATUS_Duplicate_Precedence_Error
    
    eSUPPLEMENTED_SCHEMA_STATUS_IECRelationship_Not_Allowed
    
    eSUPPLEMENTED_SCHEMA_STATUS_SchemaMergeException
    
    eSUPPLEMENTED_SCHEMA_STATUS_SupplementalClassHasBaseClass
    """

    def __init__(self: MSPyECObjects.SupplementedSchemaStatus, value: int) -> None:
        ...
    
    eSUPPLEMENTED_SCHEMA_STATUS_Duplicate_Precedence_Error: SupplementedSchemaStatus
    
    eSUPPLEMENTED_SCHEMA_STATUS_IECRelationship_Not_Allowed: SupplementedSchemaStatus
    
    eSUPPLEMENTED_SCHEMA_STATUS_Metadata_Missing: SupplementedSchemaStatus
    
    eSUPPLEMENTED_SCHEMA_STATUS_SchemaMergeException: SupplementedSchemaStatus
    
    eSUPPLEMENTED_SCHEMA_STATUS_Success: SupplementedSchemaStatus
    
    eSUPPLEMENTED_SCHEMA_STATUS_SupplementalClassHasBaseClass: SupplementedSchemaStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SupplementedSchemaStatus) -> int:
        ...
    
class Symbol:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class SymbolExpressionContext:
    """
    None
    """

    def AddSymbol(*args, **kwargs):
        """
        AddSymbol(self: MSPyECObjects.SymbolExpressionContext, symbol: Bentley.ECN.Symbol) -> Bentley.BentleyStatus
        """
        ...
    
    def AllowsTypeConversion(*args, **kwargs):
        """
        AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforceGlobalRepresentation(*args, **kwargs):
        """
        EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    def EnforcesUnits(*args, **kwargs):
        """
        EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool
        """
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(*args, **kwargs):
        """
        GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions
        """
        ...
    
    def SetEvaluationOptions(*args, **kwargs):
        """
        SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None
        """
        ...
    
    def __init__(self: MSPyECObjects.SymbolExpressionContext, outer: MSPyECObjects.ExpressionContext) -> None:
        ...
    
class ValueKind:
    """
    Members:
    
    eVALUEKIND_Uninitialized
    
    eVALUEKIND_Primitive
    
    eVALUEKIND_Struct
    
    eVALUEKIND_Array
    """

    def __init__(self: MSPyECObjects.ValueKind, value: int) -> None:
        ...
    
    eVALUEKIND_Array: ValueKind
    
    eVALUEKIND_Primitive: ValueKind
    
    eVALUEKIND_Struct: ValueKind
    
    eVALUEKIND_Uninitialized: ValueKind
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ValueKind) -> int:
        ...
    
class ValueResult:
    """
    None
    """

    def GetECValue(*args, **kwargs):
        """
        GetECValue(self: MSPyECObjects.ValueResult, ecValue: Bentley.ECN.ECValue) -> MSPyECObjects.ExpressionStatus
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ValueSymbol:
    """
    None
    """

    def __init__(self: MSPyECObjects.ValueSymbol, name: str, value: Bentley.ECN.ECValue) -> None:
        ...
    
class ValueType:
    """
    Members:
    
    eValType_None
    
    eValType_ECValue
    
    eValType_Custom
    
    eValType_InstanceList
    
    eValType_ValueList
    
    eValType_Lambda
    """

    def __init__(self: MSPyECObjects.ValueType, value: int) -> None:
        ...
    
    eValType_Custom: ValueType
    
    eValType_ECValue: ValueType
    
    eValType_InstanceList: ValueType
    
    eValType_Lambda: ValueType
    
    eValType_None: ValueType
    
    eValType_ValueList: ValueType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ValueType) -> int:
        ...
    
class ValuesView[SchemaMapExact]:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class WStringKey:
    """
    None
    """

    def GetKey(*args, **kwargs):
        """
        GetKey(self: MSPyECObjects.WStringKey) -> str
        """
        ...
    
    @property
    def Key(arg0: MSPyECObjects.WStringKey) -> str:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.WStringKey) -> None
        
        2. __init__(self: MSPyECObjects.WStringKey, key: str) -> None
        
        3. __init__(self: MSPyECObjects.WStringKey, key: MSPyBentley.WString) -> None
        """
        ...
    
class WStringKeyArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.WStringKeyArray) -> None
        
        2. __init__(self: MSPyECObjects.WStringKeyArray, arg0: MSPyECObjects.WStringKeyArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.WStringKeyArray, arg0: Iterable) -> None
        """
        ...
    
    def append(*args, **kwargs):
        """
        append(self: MSPyECObjects.WStringKeyArray, x: MSPyECObjects.WStringKey) -> None
        
        Add an item to the end of the list
        """
        ...
    
    def clear(*args, **kwargs):
        """
        clear(self: MSPyECObjects.WStringKeyArray) -> None
        
        Clear the contents
        """
        ...
    
    def count(*args, **kwargs):
        """
        count(self: MSPyECObjects.WStringKeyArray, x: MSPyECObjects.WStringKey) -> int
        
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        extend(*args, **kwargs)
        Overloaded function.
        
        1. extend(self: MSPyECObjects.WStringKeyArray, L: MSPyECObjects.WStringKeyArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.WStringKeyArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(*args, **kwargs):
        """
        insert(self: MSPyECObjects.WStringKeyArray, i: int, x: MSPyECObjects.WStringKey) -> None
        
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        pop(*args, **kwargs)
        Overloaded function.
        
        1. pop(self: MSPyECObjects.WStringKeyArray) -> MSPyECObjects.WStringKey
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.WStringKeyArray, i: int) -> MSPyECObjects.WStringKey
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(*args, **kwargs):
        """
        remove(self: MSPyECObjects.WStringKeyArray, x: MSPyECObjects.WStringKey) -> None
        
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
eARRAYKIND_Primitive: ArrayKind

eARRAYKIND_Struct: ArrayKind

eECOBJECTS_ERROR_BASE: ECErrorCategories

eECOBJECTS_STATUS_AccessStringDisagreesWithNIndices: ECObjectsStatus

eECOBJECTS_STATUS_ArrayIndexDoesNotExist: ECObjectsStatus

eECOBJECTS_STATUS_BaseClassUnacceptable: ECObjectsStatus

eECOBJECTS_STATUS_ClassNotFound: ECObjectsStatus

eECOBJECTS_STATUS_DataTypeMismatch: ECObjectsStatus

eECOBJECTS_STATUS_DataTypeNotSupported: ECObjectsStatus

eECOBJECTS_STATUS_DuplicateSchema: ECObjectsStatus

eECOBJECTS_STATUS_ECClassNotSupported: ECObjectsStatus

eECOBJECTS_STATUS_ECInstanceImplementationNotSupported: ECObjectsStatus

eECOBJECTS_STATUS_ECSchemaNotSupported: ECObjectsStatus

eECOBJECTS_STATUS_EnablerNotFound: ECObjectsStatus

eECOBJECTS_STATUS_Error: ECObjectsStatus

eECOBJECTS_STATUS_IndexOutOfRange: ECObjectsStatus

eECOBJECTS_STATUS_InvalidIndexForPerPropertyFlag: ECObjectsStatus

eECOBJECTS_STATUS_InvalidName: ECObjectsStatus

eECOBJECTS_STATUS_InvalidPropertyAccessString: ECObjectsStatus

eECOBJECTS_STATUS_MemoryAllocationCallbackRequired: ECObjectsStatus

eECOBJECTS_STATUS_MemoryBoundsOverrun: ECObjectsStatus

eECOBJECTS_STATUS_NamedItemAlreadyExists: ECObjectsStatus

eECOBJECTS_STATUS_NoChildProperties: ECObjectsStatus

eECOBJECTS_STATUS_NotCustomAttributeClass: ECObjectsStatus

eECOBJECTS_STATUS_NullPointerValue: ECObjectsStatus

eECOBJECTS_STATUS_OperationNotSupported: ECObjectsStatus

eECOBJECTS_STATUS_ParseError: ECObjectsStatus

eECOBJECTS_STATUS_PreconditionViolated: ECObjectsStatus

eECOBJECTS_STATUS_PropertyNotFound: ECObjectsStatus

eECOBJECTS_STATUS_PropertyValueMatchesNoChange: ECObjectsStatus

eECOBJECTS_STATUS_SchemaHasReferenceCycle: ECObjectsStatus

eECOBJECTS_STATUS_SchemaInUse: ECObjectsStatus

eECOBJECTS_STATUS_SchemaIsImmutable: ECObjectsStatus

eECOBJECTS_STATUS_SchemaNotFound: ECObjectsStatus

eECOBJECTS_STATUS_SchemaNotSupplemented: ECObjectsStatus

eECOBJECTS_STATUS_Success: ECObjectsStatus

eECOBJECTS_STATUS_UnableToAddStructArrayMember: ECObjectsStatus

eECOBJECTS_STATUS_UnableToAllocateManagedMemory: ECObjectsStatus

eECOBJECTS_STATUS_UnableToAllocateMemory: ECObjectsStatus

eECOBJECTS_STATUS_UnableToGetStructArrayMemberInstance: ECObjectsStatus

eECOBJECTS_STATUS_UnableToQueryForNullPropertyFlag: ECObjectsStatus

eECOBJECTS_STATUS_UnableToResizeFixedSizedArray: ECObjectsStatus

eECOBJECTS_STATUS_UnableToSetReadOnlyInstance: ECObjectsStatus

eECOBJECTS_STATUS_UnableToSetReadOnlyProperty: ECObjectsStatus

eECOBJECTS_STATUS_UnableToSetStructArrayMemberInstance: ECObjectsStatus

eECRelationshipEnd_Source: ECRelationshipEnd

eECRelationshipEnd_Target: ECRelationshipEnd

eEVALOPT_EnforceGlobalRepresentation: EvaluationOptions

eEVALOPT_EnforceUnits: EvaluationOptions

eEVALOPT_Legacy: EvaluationOptions

eEVALOPT_SuppressTypeConversions: EvaluationOptions

eExprStatus_ArrayRequired: ExpressionStatus

eExprStatus_DivideByZero: ExpressionStatus

eExprStatus_DotNotSupported: ExpressionStatus

eExprStatus_IncompatibleTypes: ExpressionStatus

eExprStatus_IncompatibleUnits: ExpressionStatus

eExprStatus_IndexOutOfRange: ExpressionStatus

eExprStatus_InstanceMethodRequired: ExpressionStatus

eExprStatus_InvalidTypesForDivision: ExpressionStatus

eExprStatus_MethodRequired: ExpressionStatus

eExprStatus_NeedsLValue: ExpressionStatus

eExprStatus_NotImpl: ExpressionStatus

eExprStatus_PrimitiveRequired: ExpressionStatus

eExprStatus_StaticMethodRequired: ExpressionStatus

eExprStatus_StructRequired: ExpressionStatus

eExprStatus_Success: ExpressionStatus

eExprStatus_UnknownError: ExpressionStatus

eExprStatus_UnknownMember: ExpressionStatus

eExprStatus_UnknownSymbol: ExpressionStatus

eExprStatus_WrongNumberOfArguments: ExpressionStatus

eExprStatus_WrongType: ExpressionStatus

eHigh: CategorySortPriority

eINSTANCE_READ_STATUS_BASE: ECErrorCategories

eINSTANCE_READ_STATUS_BadArrayElement: InstanceReadStatus

eINSTANCE_READ_STATUS_BadBinaryData: InstanceReadStatus

eINSTANCE_READ_STATUS_BadDoubleValue: InstanceReadStatus

eINSTANCE_READ_STATUS_BadECProperty: InstanceReadStatus

eINSTANCE_READ_STATUS_BadElement: InstanceReadStatus

eINSTANCE_READ_STATUS_BadIntegerValue: InstanceReadStatus

eINSTANCE_READ_STATUS_BadLongValue: InstanceReadStatus

eINSTANCE_READ_STATUS_BadPoint2dValue: InstanceReadStatus

eINSTANCE_READ_STATUS_BadPoint3dValue: InstanceReadStatus

eINSTANCE_READ_STATUS_BadPrimitivePropertyType: InstanceReadStatus

eINSTANCE_READ_STATUS_BadTimeValue: InstanceReadStatus

eINSTANCE_READ_STATUS_CantCreateStream: InstanceReadStatus

eINSTANCE_READ_STATUS_CantCreateXmlReader: InstanceReadStatus

eINSTANCE_READ_STATUS_CantSetStream: InstanceReadStatus

eINSTANCE_READ_STATUS_CantSetValue: InstanceReadStatus

eINSTANCE_READ_STATUS_CommentOnly: InstanceReadStatus

eINSTANCE_READ_STATUS_ECClassNotFound: InstanceReadStatus

eINSTANCE_READ_STATUS_ECSchemaNotFound: InstanceReadStatus

eINSTANCE_READ_STATUS_EmptyElement: InstanceReadStatus

eINSTANCE_READ_STATUS_EndElementDoesntMatch: InstanceReadStatus

eINSTANCE_READ_STATUS_FileNotFound: InstanceReadStatus

eINSTANCE_READ_STATUS_NoElementName: InstanceReadStatus

eINSTANCE_READ_STATUS_PropertyNotFound: InstanceReadStatus

eINSTANCE_READ_STATUS_Success: InstanceReadStatus

eINSTANCE_READ_STATUS_TypeMismatch: InstanceReadStatus

eINSTANCE_READ_STATUS_UnableToGetStandaloneEnabler: InstanceReadStatus

eINSTANCE_READ_STATUS_UnexpectedElement: InstanceReadStatus

eINSTANCE_READ_STATUS_XmlFileIncomplete: InstanceReadStatus

eINSTANCE_READ_STATUS_XmlParseError: InstanceReadStatus

eINSTANCE_WRITE_STATUS_BASE: ECErrorCategories

eINSTANCE_WRITE_STATUS_BadPrimitivePropertyType: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_CantCreateStream: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_CantCreateXmlWriter: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_CantReadFromStream: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_CantSetStream: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_FailedToWriteFile: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_Success: InstanceWriteStatus

eINSTANCE_WRITE_STATUS_XmlWriteError: InstanceWriteStatus

eLow: CategorySortPriority

eMEMORYINSTANCEUSAGE_Empty: MemoryInstanceUsageBitmask

eMEMORYINSTANCEUSAGE_IsHidden: MemoryInstanceUsageBitmask

eMEMORYINSTANCEUSAGE_IsPartiallyLoaded: MemoryInstanceUsageBitmask

eMedium: CategorySortPriority

eORDERIDSTORAGEMODE_None: OrderIdStorageMode

eORDERIDSTORAGEMODE_ProvidedByClient: OrderIdStorageMode

eORDERIDSTORAGEMODE_ProvidedByPersistence: OrderIdStorageMode

ePRIMITIVETYPE_Binary: PrimitiveType

ePRIMITIVETYPE_Boolean: PrimitiveType

ePRIMITIVETYPE_DateTime: PrimitiveType

ePRIMITIVETYPE_Double: PrimitiveType

ePRIMITIVETYPE_IGeometry: PrimitiveType

ePRIMITIVETYPE_Integer: PrimitiveType

ePRIMITIVETYPE_Long: PrimitiveType

ePRIMITIVETYPE_Point2D: PrimitiveType

ePRIMITIVETYPE_Point3D: PrimitiveType

ePRIMITIVETYPE_String: PrimitiveType

ePROPERTYFLAGINDEX_IsLoaded: PropertyFlagIndex

ePROPERTYFLAGINDEX_IsReadOnly: PropertyFlagIndex

ePROPERTYLAYOUTMODIFIERFLAGS_IsArrayFixedCount: ArrayModifierFlags

ePROPERTYLAYOUTMODIFIERFLAGS_IsCalculated: ArrayModifierFlags

ePROPERTYLAYOUTMODIFIERFLAGS_IsReadOnly: ArrayModifierFlags

ePROPERTYLAYOUTMODIFIERFLAGS_None: ArrayModifierFlags

eSCHEMAMATCHTYPE_Exact: SchemaMatchType

eSCHEMAMATCHTYPE_Identical: SchemaMatchType

eSCHEMAMATCHTYPE_Latest: SchemaMatchType

eSCHEMAMATCHTYPE_LatestCompatible: SchemaMatchType

eSCHEMA_READ_STATUS_BASE: ECErrorCategories

eSCHEMA_READ_STATUS_DuplicateSchema: SchemaReadStatus

eSCHEMA_READ_STATUS_FailedToParseXml: SchemaReadStatus

eSCHEMA_READ_STATUS_HasReferenceCycle: SchemaReadStatus

eSCHEMA_READ_STATUS_InvalidECSchemaXml: SchemaReadStatus

eSCHEMA_READ_STATUS_InvalidPrimitiveType: SchemaReadStatus

eSCHEMA_READ_STATUS_ReferencedSchemaNotFound: SchemaReadStatus

eSCHEMA_READ_STATUS_Success: SchemaReadStatus

eSCHEMA_WRITE_STATUS_BASE: ECErrorCategories

eSCHEMA_WRITE_STATUS_FailedToCreateXml: SchemaWriteStatus

eSCHEMA_WRITE_STATUS_FailedToSaveXml: SchemaWriteStatus

eSCHEMA_WRITE_STATUS_FailedToWriteFile: SchemaWriteStatus

eSCHEMA_WRITE_STATUS_Success: SchemaWriteStatus

eSTRENGTHDIRECTION_Backward: ECRelatedInstanceDirection

eSTRENGTHDIRECTION_Forward: ECRelatedInstanceDirection

eSTRENGTHTYPE_Embedding: StrengthType

eSTRENGTHTYPE_Holding: StrengthType

eSTRENGTHTYPE_Referencing: StrengthType

eSUPPLEMENTED_SCHEMA_STATUS_BASE: ECErrorCategories

eSUPPLEMENTED_SCHEMA_STATUS_Duplicate_Precedence_Error: SupplementedSchemaStatus

eSUPPLEMENTED_SCHEMA_STATUS_IECRelationship_Not_Allowed: SupplementedSchemaStatus

eSUPPLEMENTED_SCHEMA_STATUS_Metadata_Missing: SupplementedSchemaStatus

eSUPPLEMENTED_SCHEMA_STATUS_SchemaMergeException: SupplementedSchemaStatus

eSUPPLEMENTED_SCHEMA_STATUS_Success: SupplementedSchemaStatus

eSUPPLEMENTED_SCHEMA_STATUS_SupplementalClassHasBaseClass: SupplementedSchemaStatus

eTOKEN_And: ExpressionToken

eTOKEN_AndAlso: ExpressionToken

eTOKEN_AndAlsoModify: ExpressionToken

eTOKEN_BadFloatingPointNumber: ExpressionToken

eTOKEN_BadHexNumber: ExpressionToken

eTOKEN_BadNumber: ExpressionToken

eTOKEN_BadOctalNumber: ExpressionToken

eTOKEN_Colon: ExpressionToken

eTOKEN_Comma: ExpressionToken

eTOKEN_Concatenate: ExpressionToken

eTOKEN_DateTimeConst: ExpressionToken

eTOKEN_Dot: ExpressionToken

eTOKEN_DoubleColon: ExpressionToken

eTOKEN_Else: ExpressionToken

eTOKEN_ElseIf: ExpressionToken

eTOKEN_End: ExpressionToken

eTOKEN_EndIf: ExpressionToken

eTOKEN_Equal: ExpressionToken

eTOKEN_EqualModify: ExpressionToken

eTOKEN_Error: ExpressionToken

eTOKEN_Exponentiation: ExpressionToken

eTOKEN_False: ExpressionToken

eTOKEN_FloatConst: ExpressionToken

eTOKEN_Greater: ExpressionToken

eTOKEN_GreaterEqual: ExpressionToken

eTOKEN_HexConstant: ExpressionToken

eTOKEN_IIf: ExpressionToken

eTOKEN_Ident: ExpressionToken

eTOKEN_If: ExpressionToken

eTOKEN_IntegerConstant: ExpressionToken

eTOKEN_IntegerDivide: ExpressionToken

eTOKEN_Is: ExpressionToken

eTOKEN_LCurly: ExpressionToken

eTOKEN_LParen: ExpressionToken

eTOKEN_Lambda: ExpressionToken

eTOKEN_LeftBracket: ExpressionToken

eTOKEN_Less: ExpressionToken

eTOKEN_LessEqual: ExpressionToken

eTOKEN_Like: ExpressionToken

eTOKEN_Minus: ExpressionToken

eTOKEN_Mod: ExpressionToken

eTOKEN_ModModify: ExpressionToken

eTOKEN_None: ExpressionToken

eTOKEN_Not: ExpressionToken

eTOKEN_NotEqual: ExpressionToken

eTOKEN_NotEqualModify: ExpressionToken

eTOKEN_NotModify: ExpressionToken

eTOKEN_Null: ExpressionToken

eTOKEN_Or: ExpressionToken

eTOKEN_OrElse: ExpressionToken

eTOKEN_OrElseModify: ExpressionToken

eTOKEN_Plus: ExpressionToken

eTOKEN_PointConst: ExpressionToken

eTOKEN_PrimaryList: ExpressionToken

eTOKEN_RCurly: ExpressionToken

eTOKEN_RParen: ExpressionToken

eTOKEN_RightBracket: ExpressionToken

eTOKEN_Select: ExpressionToken

eTOKEN_ShiftLeft: ExpressionToken

eTOKEN_ShiftRight: ExpressionToken

eTOKEN_Slash: ExpressionToken

eTOKEN_Star: ExpressionToken

eTOKEN_StringConst: ExpressionToken

eTOKEN_True: ExpressionToken

eTOKEN_UnitsConst: ExpressionToken

eTOKEN_Unrecognized: ExpressionToken

eTOKEN_UnsignedShiftRight: ExpressionToken

eTOKEN_UnterminatedString: ExpressionToken

eTOKEN_Xor: ExpressionToken

eVALUEKIND_Array: ValueKind

eVALUEKIND_Primitive: ValueKind

eVALUEKIND_Struct: ValueKind

eVALUEKIND_Uninitialized: ValueKind

eValType_Custom: ValueType

eValType_ECValue: ValueType

eValType_InstanceList: ValueType

eValType_Lambda: ValueType

eValType_None: ValueType

eValType_ValueList: ValueType

eVeryHigh: CategorySortPriority

eVeryLow: CategorySortPriority

