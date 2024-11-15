from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyECObjects

class ArrayECProperty:
    """
    None
    """

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty:
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
    
    def GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    
    def GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetId(self: MSPyECObjects.ECProperty) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetIsArray(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsStruct(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetKind(self: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.ArrayKind:
        ...
    
    def GetMaxOccurs(self: MSPyECObjects.ArrayECProperty) -> int:
        ...
    
    def GetMinOccurs(self: MSPyECObjects.ArrayECProperty) -> int:
        ...
    
    def GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetPrimitiveElementType(self: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetStructElementType(self: MSPyECObjects.ArrayECProperty) -> Bentley.ECN.ECClass:
        ...
    
    def GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
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
    
    def IsCalculated(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsDefined(*args, **kwargs):
        """
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
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetMaxOccurs(self: MSPyECObjects.ArrayECProperty, maxOccurs: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetMinOccurs(self: MSPyECObjects.ArrayECProperty, minOccurs: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetPrimitiveElementType(self: MSPyECObjects.ArrayECProperty, type: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetStructElementType(self: MSPyECObjects.ArrayECProperty, type: Bentley.ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
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
    
    def GetCount(self: MSPyECObjects.ArrayInfo) -> int:
        ...
    
    def GetElementPrimitiveType(self: MSPyECObjects.ArrayInfo) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetKind(self: MSPyECObjects.ArrayInfo) -> MSPyECObjects.ValueKind:
        ...
    
    def IsFixedCount(self: MSPyECObjects.ArrayInfo) -> bool:
        ...
    
    def IsPrimitiveArray(self: MSPyECObjects.ArrayInfo) -> bool:
        ...
    
    def IsStructArray(self: MSPyECObjects.ArrayInfo) -> bool:
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

    @staticmethod
    def BuildFromClass(ecClass: Bentley.ECN.ECClass) -> MSPyECObjects.ClassLayout:
        """
        Given a class, will create the ClassLayout that manages that class
        
        Parameter ``ecClass``:
        The ECClass to build the ClassLayout from
        
        Returns:
        ClassLayout pointer managing this ECClass
        """
        ...
    
    def CalculateBytesUsed(self: MSPyECObjects.ClassLayout, propertyData: bytes) -> int:
        """
        Determines the number of bytes used for property data, so far
        """
        ...
    
    @property
    def Checksum(arg0: MSPyECObjects.ClassLayout) -> int:
        ...
    
    @staticmethod
    def CreateEmpty(className: str) -> MSPyECObjects.ClassLayout:
        """
        Creates an empty ClassLayout for a class with the given name
        
        Parameter ``className``:
        The name of the class that this ClassLayout will define
        """
        ...
    
    @property
    def ECClassName(arg0: MSPyECObjects.ClassLayout) -> MSPyBentley.WString:
        ...
    
    def GetChecksum(self: MSPyECObjects.ClassLayout) -> int:
        """
        Returns the checksum for this ClassLayout
        """
        ...
    
    def GetECClassName(self: MSPyECObjects.ClassLayout) -> MSPyBentley.WString:
        """
        Returns the name of the ECClass that this ClassLayout manages
        """
        ...
    
    def GetECPointerIndex(self: MSPyECObjects.ClassLayout, end: Bentley.ECN.ECRelationshipEnd) -> int:
        """
        Returns the property index of the given relationship end
        
        Parameter ``end``:
        The ECRelationshipEnd for which to get the pointer index
        
        Returns:
        The property index of the pointer for the given relationship end
        """
        ...
    
    def GetPropertyCount(self: MSPyECObjects.ClassLayout) -> int:
        """
        Returns the number of properties this ClassLayout manages
        """
        ...
    
    def GetPropertyCountExcludingEmbeddedStructs(self: MSPyECObjects.ClassLayout) -> int:
        """
        Returns the number of properties this ClassLayout manages, not
        counting embedded structs
        """
        ...
    
    def GetPropertyIndex(self: MSPyECObjects.ClassLayout, accessString: str) -> tuple:
        """
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
    
    def GetPropertyLayout(self: MSPyECObjects.ClassLayout, accessString: str) -> tuple:
        """
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
    
    def GetPropertyLayoutByIndex(self: MSPyECObjects.ClassLayout, propertyIndex: int) -> tuple:
        """
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
    
    def GetPropertyLayoutIndex(self: MSPyECObjects.ClassLayout, propertyLayout: MSPyECObjects.PropertyLayout) -> tuple:
        """
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
    
    def IsCompatible(self: MSPyECObjects.ClassLayout, layout: MSPyECObjects.ClassLayout) -> bool:
        """
        Checks the given classLayout to see if it is equal to, or a subset of,
        this layout
        
        Parameter ``layout``:
        The ClassLayout to test compatibility of
        
        Returns:
        true if the given ClassLayout is equal to or a subset of this
        layout, false otherwise
        """
        ...
    
    def IsPropertyReadOnly(self: MSPyECObjects.ClassLayout, propertyIndex: int) -> bool:
        """
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
    
    def SetPropertyReadOnly(self: MSPyECObjects.ClassLayout, propertyIndex: int, readOnly: bool) -> bool:
        """
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
    
    def ToString(self: MSPyECObjects.ClassLayout) -> MSPyBentley.WString:
        """
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

    def AddCustomSerializer(self: MSPyECObjects.CustomStructSerializerManager, serializerName: str, serializer: MSPyECObjects.ICustomECStructSerializer) -> Bentley.BentleyStatus:
        ...
    
    def GetCustomSerializer(self: MSPyECObjects.CustomStructSerializerManager, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ICustomECStructSerializer:
        ...
    
    @staticmethod
    def GetManager() -> MSPyECObjects.CustomStructSerializerManager:
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
    
    @staticmethod
    def GetDefault() -> MSPyBentley.BeDateTimeInfo:
        ...
    
    def GetInfo(self: MSPyECObjects.DateTimeInfo, useDefaultIfUnset: bool) -> MSPyBentley.BeDateTimeInfo:
        ...
    
    def IsComponentNull(self: MSPyECObjects.DateTimeInfo) -> bool:
        ...
    
    def IsKindNull(self: MSPyECObjects.DateTimeInfo) -> bool:
        ...
    
    def IsMatchedBy(self: MSPyECObjects.DateTimeInfo, arg0: MSPyBentley.BeDateTimeInfo) -> bool:
        """
        rhs
        """
        ...
    
    def ToString(self: MSPyECObjects.DateTimeInfo) -> MSPyBentley.WString:
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

    def AddBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def BaseClasses(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    @staticmethod
    def ClassesAreEqualByName(currentBaseClass: MSPyECObjects.ECClass, arg: capsule) -> bool:
        ...
    
    def CreateArrayProperty(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        
        3. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, structType: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    def CreatePrimitiveProperty(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        """
        ...
    
    def CreateStructProperty(*args, **kwargs):
        """
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
    
    def GetBaseClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDefaultStandaloneEnabler(self: MSPyECObjects.ECClass) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    def GetDerivedClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def GetDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetFullName(self: MSPyECObjects.ECClass) -> str:
        ...
    
    def GetId(self: MSPyECObjects.ECClass) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetIsCustomAttributeClass(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsDomainClass(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsFinal(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsStruct(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetProperties(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetProperties(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable
        
        2. GetProperties(self: MSPyECObjects.ECClass, includeBaseProperties: bool) -> MSPyECObjects.ECPropertyIterable
        """
        ...
    
    def GetProperty(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        2. GetProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        3. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetPropertyCount(self: MSPyECObjects.ECClass, includeBaseProperties: bool = True) -> int:
        ...
    
    @staticmethod
    def GetQualifiedClassName(primarySchema: Bentley.ECN.ECSchema, ecClass: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass:
        ...
    
    def GetSchema(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema:
        ...
    
    def HasBaseClasses(self: MSPyECObjects.ECClass) -> bool:
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
    
    @staticmethod
    def ParseClassName(prefix: MSPyBentley.WString, className: MSPyBentley.WString, qualifiedClassName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Properties(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass:
        ...
    
    def RemoveBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def RemoveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Schema(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDescription(self: MSPyECObjects.ECClass, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECClass, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsCustomAttributeClass(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, isCustomAttribute: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsDomainClass(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsDomainClass(self: MSPyECObjects.ECClass, isDomainClass: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsDomainClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsFinal(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsFinal(self: MSPyECObjects.ECClass, isFinal: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsFinal(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsStruct(*args, **kwargs):
        """
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
    
    def clear(self: MSPyECObjects.ECClassCPArray) -> None:
        ...
    
    def push_back(self: MSPyECObjects.ECClassCPArray, newItem: MSPyECObjects.ECClass) -> None:
        ...
    
    def remove(self: MSPyECObjects.ECClassCPArray, arg0: MSPyECObjects.ECClass) -> None:
        ...
    
    def resize(self: MSPyECObjects.ECClassCPArray, newSize: int) -> None:
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
    
    def clear(self: MSPyECObjects.ECClassPArray) -> None:
        ...
    
    def push_back(self: MSPyECObjects.ECClassPArray, newItem: MSPyECObjects.ECClass) -> None:
        ...
    
    def remove(self: MSPyECObjects.ECClassPArray, arg0: MSPyECObjects.ECClass) -> None:
        ...
    
    def resize(self: MSPyECObjects.ECClassPArray, newSize: int) -> None:
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

    def ClearValues(self: MSPyECObjects.ECDBuffer) -> None:
        """
        Sets all values to null
        """
        ...
    
    def CopyFromBuffer(self: MSPyECObjects.ECDBuffer, source: MSPyECObjects.ECDBuffer) -> MSPyECObjects.ECObjectsStatus:
        """
        Attempts to copy property values from source buffer. Expects source to
        have a compatible class layout.
        
        Parameter ``source``:
        The ECDBuffer to copy values from
        """
        ...
    
    def IsEmpty(self: MSPyECObjects.ECDBuffer) -> bool:
        """
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
    
    def GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple:
        ...
    
    def GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    def GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int:
        ...
    
    def GetName(self: MSPyECObjects.ECEnabler) -> str:
        ...
    
    def GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int:
        ...
    
    def GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int:
        ...
    
    def GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple:
        ...
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentley.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool:
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

    def GetIconId(self: MSPyECObjects.ECImageKey) -> int:
        ...
    
    def GetIconType(self: MSPyECObjects.ECImageKey) -> int:
        ...
    
    def GetImageName(self: MSPyECObjects.ECImageKey) -> MSPyBentley.WString:
        ...
    
    def GetImageType(self: MSPyECObjects.ECImageKey) -> MSPyECObjects.ECImageKey.ImageType:
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
    
    def SetIconId(self: MSPyECObjects.ECImageKey, rscId: int) -> None:
        ...
    
    def SetIconType(self: MSPyECObjects.ECImageKey, iconType: int) -> None:
        ...
    
    def SetImageName(self: MSPyECObjects.ECImageKey, name: MSPyBentley.WString) -> None:
        ...
    
    def SetImageType(self: MSPyECObjects.ECImageKey, type: MSPyECObjects.ECImageKey.ImageType) -> None:
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

    @staticmethod
    def CreateContext(*args, **kwargs):
        """
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

    @staticmethod
    def DecodeFromValidName(decoded: MSPyBentley.WString, name: MSPyBentley.WString) -> bool:
        ...
    
    @staticmethod
    def EncodeToValidName(encoded: MSPyBentley.WString, name: MSPyBentley.WString) -> bool:
        ...
    
    @staticmethod
    def IsValidAlphaNumericCharacter(char: str) -> bool:
        ...
    
    @staticmethod
    def IsValidName(name: str) -> bool:
        ...
    
    @staticmethod
    def Validate(name: str) -> MSPyECObjects.ECNameValidation.ValidationResult:
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

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty:
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
    
    def GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    
    def GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetId(self: MSPyECObjects.ECProperty) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetIsArray(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsStruct(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
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
    
    def IsCalculated(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsDefined(*args, **kwargs):
        """
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
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
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

    def FindByDisplayLabel(self: MSPyECObjects.ECPropertyIterable, label: str) -> MSPyECObjects.ECProperty:
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
    
    def GetChildValues(self: MSPyECObjects.ECPropertyValue) -> Bentley.ECN.ECValuesCollection:
        ...
    
    def GetInstance(self: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.IECInstance:
        ...
    
    @staticmethod
    def GetPropertyValue(instance: MSPyECObjects.IECInstance, propertyAccessor: str) -> MSPyECObjects.ECPropertyValue:
        ...
    
    def GetValue(self: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValue:
        ...
    
    def GetValueAccessor(self: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValueAccessor:
        ...
    
    def HasChildValues(self: MSPyECObjects.ECPropertyValue) -> bool:
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

    def AddBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def BaseClasses(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def ClassesAreEqualByName(currentBaseClass: MSPyECObjects.ECClass, arg: capsule) -> bool:
        ...
    
    def CreateArrayProperty(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        
        3. CreateArrayProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, structType: MSPyECObjects.ECClass) -> tuple
        """
        ...
    
    def CreatePrimitiveProperty(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> tuple
        
        2. CreatePrimitiveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, primitiveType: MSPyECObjects.PrimitiveType) -> tuple
        """
        ...
    
    def CreateStructProperty(*args, **kwargs):
        """
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
    
    def GetBaseClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDefaultStandaloneEnabler(self: MSPyECObjects.ECClass) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    def GetDerivedClasses(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECClassPArray:
        ...
    
    def GetDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetFullName(self: MSPyECObjects.ECClass) -> str:
        ...
    
    def GetId(self: MSPyECObjects.ECClass) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetIsCustomAttributeClass(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsDomainClass(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsFinal(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetIsOrdered(self: MSPyECObjects.ECRelationshipClass) -> bool:
        ...
    
    def GetIsStruct(self: MSPyECObjects.ECClass) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetOrderedRelationshipPropertyName(self: MSPyECObjects.ECRelationshipClass, propertyName: MSPyBentley.WString, end: MSPyECObjects.ECRelationshipEnd) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetProperties(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetProperties(self: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable
        
        2. GetProperties(self: MSPyECObjects.ECClass, includeBaseProperties: bool) -> MSPyECObjects.ECPropertyIterable
        """
        ...
    
    def GetProperty(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        2. GetProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        
        3. GetProperty(self: MSPyECObjects.ECClass, name: str, inludeBaseClasses: bool = True) -> MSPyECObjects.ECProperty
        """
        ...
    
    def GetPropertyCount(self: MSPyECObjects.ECClass, includeBaseProperties: bool = True) -> int:
        ...
    
    def GetQualifiedClassName(primarySchema: Bentley.ECN.ECSchema, ecClass: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass:
        ...
    
    def GetSchema(self: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema:
        ...
    
    def GetSource(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelationshipConstraint:
        ...
    
    def GetStrength(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.StrengthType:
        ...
    
    def GetStrengthDirection(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelatedInstanceDirection:
        ...
    
    def GetTarget(self: MSPyECObjects.ECRelationshipClass) -> MSPyECObjects.ECRelationshipConstraint:
        ...
    
    def HasBaseClasses(self: MSPyECObjects.ECClass) -> bool:
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
    
    def ParseClassName(prefix: MSPyBentley.WString, className: MSPyBentley.WString, qualifiedClassName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Properties(arg0: MSPyECObjects.ECClass) -> MSPyECObjects.ECPropertyIterable:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECRelationshipClass:
        ...
    
    def RemoveBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def RemoveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Schema(arg0: MSPyECObjects.ECClass) -> Bentley.ECN.ECSchema:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDescription(self: MSPyECObjects.ECClass, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECClass, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsCustomAttributeClass(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, isCustomAttribute: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsCustomAttributeClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsDomainClass(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsDomainClass(self: MSPyECObjects.ECClass, isDomainClass: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsDomainClass(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsFinal(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsFinal(self: MSPyECObjects.ECClass, isFinal: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsFinal(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetIsStruct(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsStruct(self: MSPyECObjects.ECClass, isStruct: str) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsStruct(self: MSPyECObjects.ECClass, val: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetStrength(self: MSPyECObjects.ECRelationshipClass, strength: MSPyECObjects.StrengthType) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetStrengthDirection(self: MSPyECObjects.ECRelationshipClass, dir: MSPyECObjects.ECRelatedInstanceDirection) -> MSPyECObjects.ECObjectsStatus:
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

    def AddClass(self: MSPyECObjects.ECRelationshipConstraint, classConstraint: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
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
    
    def CopyTo(self: MSPyECObjects.ECRelationshipConstraint, toRelationshipConstraint: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetCardinality(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.RelationshipCardinality:
        ...
    
    def GetClasses(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.ECClassPArray:
        ...
    
    def GetCustomAttribute(self: MSPyECObjects.ECRelationshipConstraint, classDefiniton: MSPyECObjects.ECClass) -> Bentley.ECN.IECInstance:
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetInvariantRoleLabel(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString:
        ...
    
    def GetIsMultiple(self: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    
    def GetIsOrdered(self: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    
    def GetIsPolymorphic(self: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    
    def GetOrderIdStorageMode(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.OrderIdStorageMode:
        ...
    
    def GetOrderedRelationshipPropertyName(self: MSPyECObjects.ECRelationshipConstraint, propertyName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetRoleLabel(self: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString:
        ...
    
    @property
    def InvariantRoleLabel(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyBentley.WString:
        ...
    
    def IsDefined(*args, **kwargs):
        """
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
    
    def IsRoleLabelDefined(self: MSPyECObjects.ECRelationshipConstraint) -> bool:
        ...
    
    @property
    def OrderIdStorageMode(arg0: MSPyECObjects.ECRelationshipConstraint) -> MSPyECObjects.OrderIdStorageMode:
        ...
    
    def RemoveClass(self: MSPyECObjects.ECRelationshipConstraint, classConstraint: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
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
        Overloaded function.
        
        1. SetCardinality(self: MSPyECObjects.ECRelationshipConstraint, val: MSPyECObjects.RelationshipCardinality) -> MSPyECObjects.ECObjectsStatus
        
        2. SetCardinality(self: MSPyECObjects.ECRelationshipConstraint, cardinality: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.ECRelationshipConstraint, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsPolymorphic(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsPolymorphic(self: MSPyECObjects.ECRelationshipConstraint, val: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsPolymorphic(self: MSPyECObjects.ECRelationshipConstraint, isPolymorphic: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetRoleLabel(self: MSPyECObjects.ECRelationshipConstraint, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
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
    
    @staticmethod
    def ComputeSchemaXmlStringCheckSum(str: str, len: int) -> int:
        ...
    
    def CopyClass(self: MSPyECObjects.ECSchema, sourceClass: MSPyECObjects.ECClass) -> tuple:
        ...
    
    def CopySchema(self: MSPyECObjects.ECSchema) -> tuple:
        ...
    
    def CreateClass(self: MSPyECObjects.ECSchema, name: MSPyBentley.WString) -> tuple:
        ...
    
    def CreateRelationshipClass(self: MSPyECObjects.ECSchema, name: MSPyBentley.WString) -> tuple:
        ...
    
    @staticmethod
    def CreateSchema(schemaName: MSPyBentley.WString, versionMajor: int, versionMinor: int) -> tuple:
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
    
    def FindAllSchemasInGraph(self: MSPyECObjects.ECSchema, allSchemas: MSPyECObjects.ECSchemaPArray, includeRootSchema: bool = True) -> None:
        ...
    
    def FindSchema(self: MSPyECObjects.ECSchema, schemaKey: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType) -> MSPyECObjects.ECSchema:
        ...
    
    @staticmethod
    def FormatSchemaVersion(versionMajor: int, versionMinor: int) -> MSPyBentley.WString:
        ...
    
    @property
    def FullSchemaName(arg0: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetClass(self: MSPyECObjects.ECSchema, name: str) -> MSPyECObjects.ECClass:
        ...
    
    def GetClassCount(self: MSPyECObjects.ECSchema) -> int:
        ...
    
    def GetClasses(self: MSPyECObjects.ECSchema) -> MSPyECObjects.ECClassContainer:
        ...
    
    def GetCustomAttributeContainer(self: MSPyECObjects.ECSchema) -> MSPyECObjects.IECCustomAttributeContainer:
        ...
    
    def GetDescription(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetFullSchemaName(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetId(self: MSPyECObjects.ECSchema) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECSchema) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetNamespacePrefix(self: MSPyECObjects.ECSchema) -> MSPyBentley.WString:
        ...
    
    def GetReferencedSchemas(self: MSPyECObjects.ECSchema) -> Bentley.ECN.SchemaMapExact:
        ...
    
    def GetSchemaByNamespacePrefix(self: MSPyECObjects.ECSchema, namespacePrefix: MSPyBentley.WString) -> MSPyECObjects.ECSchema:
        ...
    
    def GetSchemaKey(self: MSPyECObjects.ECSchema) -> MSPyECObjects.SchemaKey:
        ...
    
    def GetSupplementalInfo(self: MSPyECObjects.ECSchema) -> Bentley.ECN.SupplementalSchemaInfo:
        ...
    
    def GetVersionMajor(self: MSPyECObjects.ECSchema) -> int:
        ...
    
    def GetVersionMinor(self: MSPyECObjects.ECSchema) -> int:
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
    
    def IsSamePrimarySchema(self: MSPyECObjects.ECSchema, primarySchema: MSPyECObjects.ECSchema) -> bool:
        ...
    
    @staticmethod
    def IsSchemaReferenced(thisSchema: MSPyECObjects.ECSchema, potentiallyReferencedSchema: MSPyECObjects.ECSchema) -> bool:
        ...
    
    def IsStandardSchema(self: MSPyECObjects.ECSchema) -> bool:
        ...
    
    def IsSupplementalSchema(self: MSPyECObjects.ECSchema) -> bool:
        ...
    
    def IsSupplemented(self: MSPyECObjects.ECSchema) -> bool:
        ...
    
    @staticmethod
    def LocateSchema(schema: MSPyECObjects.SchemaKey, schemaContext: MSPyECObjects.ECSchemaReadContext) -> MSPyECObjects.ECSchema:
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
    
    @staticmethod
    def ParseSchemaFullName(fullName: str) -> tuple:
        ...
    
    @staticmethod
    def ParseVersionString(versionString: str) -> tuple:
        ...
    
    @staticmethod
    def ReadFromXmlFile(ecSchemaXmlFile: str, schemaContext: MSPyECObjects.ECSchemaReadContext) -> tuple:
        ...
    
    @staticmethod
    def ReadFromXmlString(*args, **kwargs):
        """
        Overloaded function.
        
        1. ReadFromXmlString(ecSchemaXml: str, schemaContext: MSPyECObjects.ECSchemaReadContext) -> tuple
        
        2. ReadFromXmlString(ecSchemaXml: str, schemaContext: MSPyECObjects.ECSchemaReadContext) -> tuple
        """
        ...
    
    @property
    def ReferencedSchemas(arg0: MSPyECObjects.ECSchema) -> Bentley.ECN.SchemaMapExact:
        ...
    
    def RemoveReferencedSchema(self: MSPyECObjects.ECSchema, refSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ResolveNamespacePrefix(self: MSPyECObjects.ECSchema, schema: MSPyECObjects.ECSchema, namespacePrefix: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def SchemaKey(arg0: MSPyECObjects.ECSchema) -> MSPyECObjects.SchemaKey:
        ...
    
    def SetDescription(self: MSPyECObjects.ECSchema, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECSchema, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @staticmethod
    def SetErrorHandling(arg0: bool, arg1: bool) -> None:
        ...
    
    def SetImmutable(self: MSPyECObjects.ECSchema) -> None:
        ...
    
    def SetName(self: MSPyECObjects.ECSchema, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetNamespacePrefix(self: MSPyECObjects.ECSchema, prefix: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetVersionMajor(self: MSPyECObjects.ECSchema, major: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetVersionMinor(self: MSPyECObjects.ECSchema, minor: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ShouldNotBeStored(self: MSPyECObjects.ECSchema) -> bool:
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
    
    def WriteToXmlFile(self: MSPyECObjects.ECSchema, ecSchemaXmlFile: str, utf16: bool = False) -> MSPyECObjects.SchemaWriteStatus:
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
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
    
    def append(self: MSPyECObjects.ECSchemaCPArray, x: MSPyECObjects.ECSchema) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ECSchemaCPArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.ECSchemaCPArray, x: MSPyECObjects.ECSchema) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECSchemaCPArray, L: MSPyECObjects.ECSchemaCPArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECSchemaCPArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ECSchemaCPArray, i: int, x: MSPyECObjects.ECSchema) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECSchemaCPArray) -> MSPyECObjects.ECSchema
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECSchemaCPArray, i: int) -> MSPyECObjects.ECSchema
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.ECSchemaCPArray, x: MSPyECObjects.ECSchema) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ECSchemaCache:
    """
    None
    """

    def AddSchema(self: MSPyECObjects.ECSchemaCache, schema: Bentley.ECN.ECSchema) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def Clear(self: MSPyECObjects.ECSchemaCache) -> None:
        ...
    
    @property
    def Count(arg0: MSPyECObjects.ECSchemaCache) -> int:
        ...
    
    def DropSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetCount(self: MSPyECObjects.ECSchemaCache) -> int:
        ...
    
    def GetSchema(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey) -> Bentley.ECN.ECSchema
        
        2. GetSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType) -> Bentley.ECN.ECSchema
        """
        ...
    
    def GetSchemaLocater(self: MSPyECObjects.ECSchemaCache) -> MSPyECObjects.IECSchemaLocater:
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
    
    def append(self: MSPyECObjects.ECSchemaPArray, x: MSPyECObjects.ECSchema) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ECSchemaPArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.ECSchemaPArray, x: MSPyECObjects.ECSchema) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECSchemaPArray, L: MSPyECObjects.ECSchemaPArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECSchemaPArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ECSchemaPArray, i: int, x: MSPyECObjects.ECSchema) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECSchemaPArray) -> MSPyECObjects.ECSchema
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECSchemaPArray, i: int) -> MSPyECObjects.ECSchema
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.ECSchemaPArray, x: MSPyECObjects.ECSchema) -> None:
        """
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
    
    def append(self: MSPyECObjects.ECSchemaPtrArray, x: MSPyECObjects.ECSchema) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ECSchemaPtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.ECSchemaPtrArray, x: MSPyECObjects.ECSchema) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECSchemaPtrArray, L: MSPyECObjects.ECSchemaPtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECSchemaPtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ECSchemaPtrArray, i: int, x: MSPyECObjects.ECSchema) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECSchemaPtrArray) -> MSPyECObjects.ECSchema
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECSchemaPtrArray, i: int) -> MSPyECObjects.ECSchema
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.ECSchemaPtrArray, x: MSPyECObjects.ECSchema) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ECSchemaReadContext:
    """
    None
    """

    def AddCulture(self: MSPyECObjects.ECSchemaReadContext, culture: str) -> None:
        """
        Adds a culture string that will be appended to the existing search
        paths when looking for localization supplemental schemas.
        
        Parameter ``culture``:
        string in format cu-CU or just cu
        """
        ...
    
    def AddSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: Bentley.ECN.IECSchemaLocater, priority: int = 0) -> None:
        """
        Adds a schema locater to the current context
        
        Parameter ``locater``:
        Locater to add to the current context
        
        Parameter ``priority``:
        The priority this locater has when ordering all locaters for
        locating a schema
        """
        ...
    
    def AddSchemaPath(self: MSPyECObjects.ECSchemaReadContext, path: str) -> None:
        """
        Adds a file path that should be used to search for a matching schema
        name
        
        Parameter ``path``:
        Path to the directory where schemas can be found
        """
        ...
    
    @property
    def Cache(arg0: MSPyECObjects.ECSchemaReadContext) -> Bentley.ECN.ECSchemaCache:
        ...
    
    @staticmethod
    def CreateContext(*args, **kwargs):
        """
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
    
    def GetCache(self: MSPyECObjects.ECSchemaReadContext) -> Bentley.ECN.ECSchemaCache:
        """
        Gets the schemas cached by this context.
        
        Returns:
        Schemas cached by this context
        """
        ...
    
    def GetCultures(self: MSPyECObjects.ECSchemaReadContext) -> MSPyBentley.WStringArray:
        """
        Gets culture strings
        """
        ...
    
    def LocateSchema(self: MSPyECObjects.ECSchemaReadContext, key: Bentley.ECN.SchemaKey, matchType: Bentley.ECN.SchemaMatchType) -> Bentley.ECN.ECSchema:
        """
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
        
    def RemoveSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: Bentley.ECN.IECSchemaLocater) -> None:
        """
        Removes a schema locater from the current context
        
        Parameter ``locater``:
        Locater to remove from the current context
        """
        ...
    
    def SetFinalSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: Bentley.ECN.IECSchemaLocater) -> None:
        """
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
    
    @staticmethod
    def CreatePrimitiveArrayTypeDescriptor(primitiveType: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECTypeDescriptor:
        ...
    
    @staticmethod
    def CreatePrimitiveTypeDescriptor(primitiveType: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECTypeDescriptor:
        ...
    
    @staticmethod
    def CreateStructArrayTypeDescriptor() -> MSPyECObjects.ECTypeDescriptor:
        ...
    
    @staticmethod
    def CreateStructTypeDescriptor() -> MSPyECObjects.ECTypeDescriptor:
        ...
    
    def GetArrayKind(self: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.ArrayKind:
        ...
    
    def GetPrimitiveType(self: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetTypeKind(self: MSPyECObjects.ECTypeDescriptor) -> MSPyECObjects.ValueKind:
        ...
    
    def IsArray(self: MSPyECObjects.ECTypeDescriptor) -> bool:
        ...
    
    def IsPrimitive(self: MSPyECObjects.ECTypeDescriptor) -> bool:
        ...
    
    def IsPrimitiveArray(self: MSPyECObjects.ECTypeDescriptor) -> bool:
        ...
    
    def IsStruct(self: MSPyECObjects.ECTypeDescriptor) -> bool:
        ...
    
    def IsStructArray(self: MSPyECObjects.ECTypeDescriptor) -> bool:
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
    
    def CanConvertToPrimitiveType(self: MSPyECObjects.ECValue, type: MSPyECObjects.PrimitiveType) -> bool:
        ...
    
    def Clear(self: MSPyECObjects.ECValue) -> None:
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
    
    def From(self: MSPyECObjects.ECValue, value: MSPyECObjects.ECValue) -> None:
        ...
    
    def GetArrayInfo(self: MSPyECObjects.ECValue) -> MSPyECObjects.ArrayInfo:
        ...
    
    def GetBinary(self: MSPyECObjects.ECValue) -> bytes:
        ...
    
    def GetBoolean(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def GetDateTime(self: MSPyECObjects.ECValue) -> MSPyBentley.BeDateTime:
        ...
    
    def GetDateTimeTicks(self: MSPyECObjects.ECValue) -> int:
        ...
    
    def GetDateTimeTicksEx(self: MSPyECObjects.ECValue) -> tuple:
        ...
    
    def GetDateTimeUnixMillis(self: MSPyECObjects.ECValue) -> int:
        ...
    
    def GetDouble(self: MSPyECObjects.ECValue) -> float:
        ...
    
    def GetIGeometry(self: MSPyECObjects.ECValue) -> MSPyBentleyGeom.IGeometry:
        ...
    
    def GetInteger(self: MSPyECObjects.ECValue) -> int:
        ...
    
    def GetKind(self: MSPyECObjects.ECValue) -> MSPyECObjects.ValueKind:
        ...
    
    def GetLong(self: MSPyECObjects.ECValue) -> int:
        ...
    
    def GetPoint2D(self: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint2d:
        ...
    
    def GetPoint3D(self: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    def GetPrimitiveType(self: MSPyECObjects.ECValue) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetString(self: MSPyECObjects.ECValue) -> str:
        ...
    
    def GetStruct(self: MSPyECObjects.ECValue) -> MSPyECObjects.IECInstance:
        ...
    
    def GetUtf8CP(self: MSPyECObjects.ECValue) -> str:
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
    
    def IsArray(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsBinary(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsBoolean(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsDateTime(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsDouble(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsIGeometry(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsInteger(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsLoaded(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsLong(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsNull(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsPoint2D(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsPoint3D(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsPrimitive(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsReadOnly(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsString(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsStruct(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsUninitialized(self: MSPyECObjects.ECValue) -> bool:
        ...
    
    def IsUtf8(self: MSPyECObjects.ECValue) -> bool:
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
    
    def SetBinary(self: MSPyECObjects.ECValue, arg0: bytes) -> None:
        ...
    
    def SetBoolean(self: MSPyECObjects.ECValue, boolean: bool) -> Bentley.BentleyStatus:
        ...
    
    def SetDateTime(self: MSPyECObjects.ECValue, dateTime: MSPyBentley.BeDateTime) -> Bentley.BentleyStatus:
        ...
    
    def SetDateTimeTicks(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetDateTimeTicks(self: MSPyECObjects.ECValue, ceTicks: int) -> Bentley.BentleyStatus
        
        2. SetDateTimeTicks(self: MSPyECObjects.ECValue, ceTicks: int, dateTimeMetaData: MSPyBentley.BeDateTimeInfo) -> Bentley.BentleyStatus
        """
        ...
    
    def SetDouble(self: MSPyECObjects.ECValue, dblVal: float) -> Bentley.BentleyStatus:
        ...
    
    def SetIGeometry(self: MSPyECObjects.ECValue, geometry: MSPyBentleyGeom.IGeometry) -> Bentley.BentleyStatus:
        ...
    
    def SetInteger(self: MSPyECObjects.ECValue, integer: int) -> Bentley.BentleyStatus:
        ...
    
    def SetIsLoaded(self: MSPyECObjects.ECValue, loaded: bool) -> None:
        ...
    
    def SetIsNull(self: MSPyECObjects.ECValue, null: bool) -> None:
        ...
    
    def SetIsReadOnly(self: MSPyECObjects.ECValue, readOnly: bool) -> None:
        ...
    
    def SetLong(self: MSPyECObjects.ECValue, long64: int) -> Bentley.BentleyStatus:
        ...
    
    def SetPoint2D(self: MSPyECObjects.ECValue, value: MSPyBentleyGeom.DPoint2d) -> Bentley.BentleyStatus:
        ...
    
    def SetPoint3D(self: MSPyECObjects.ECValue, value: MSPyBentleyGeom.DPoint3d) -> Bentley.BentleyStatus:
        ...
    
    def SetPrimitiveArrayInfo(self: MSPyECObjects.ECValue, primitiveElementType: MSPyECObjects.PrimitiveType, count: int, isFixedSize: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetPrimitiveType(self: MSPyECObjects.ECValue, type: MSPyECObjects.PrimitiveType) -> Bentley.BentleyStatus:
        ...
    
    def SetString(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetString(self: MSPyECObjects.ECValue, string: MSPyBentley.WString, bool: bool = True) -> None
        
        2. SetString(self: MSPyECObjects.ECValue, string: MSPyBentley.Utf8String, bool: bool = True) -> None
        
        3. SetString(self: MSPyECObjects.ECValue, string: str, bool: bool = True) -> None
        """
        ...
    
    def SetStruct(self: MSPyECObjects.ECValue, instance: MSPyECObjects.IECInstance) -> Bentley.BentleyStatus:
        ...
    
    def SetStructArrayInfo(self: MSPyECObjects.ECValue, count: int, isFixedSize: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetToNull(*args, **kwargs):
        """
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
    
    def ToString(self: MSPyECObjects.ECValue) -> MSPyBentley.WString:
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

    def Clear(self: MSPyECObjects.ECValueAccessor) -> None:
        ...
    
    def DeepestLocation(self: MSPyECObjects.ECValueAccessor) -> MSPyECObjects.ECValueAccessor.Location:
        ...
    
    @property
    def Depth(arg0: MSPyECObjects.ECValueAccessor) -> int:
        ...
    
    def GetAccessString(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetAccessString(self: MSPyECObjects.ECValueAccessor) -> str
        
        2. GetAccessString(self: MSPyECObjects.ECValueAccessor, depth: int) -> str
        """
        ...
    
    def GetDepth(self: MSPyECObjects.ECValueAccessor) -> int:
        ...
    
    def GetManagedAccessString(self: MSPyECObjects.ECValueAccessor) -> MSPyBentley.WString:
        ...
    
    def GetPropertyName(self: MSPyECObjects.ECValueAccessor) -> MSPyBentley.WString:
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
        
        def GetECProperty(self: MSPyECObjects.ECValueAccessor.Location) -> MSPyECObjects.ECProperty:
            ...
        
        def GetEnabler(self: MSPyECObjects.ECValueAccessor.Location) -> MSPyECObjects.ECEnabler:
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
    
    def PopLocation(self: MSPyECObjects.ECValueAccessor) -> None:
        ...
    
    @staticmethod
    def PopulateValueAccessor(*args, **kwargs):
        """
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

    @staticmethod
    def Create(*args, **kwargs):
        """
        Overloaded function.
        
        1. Create(instance: MSPyECObjects.IECInstance) -> MSPyECObjects.ECValuesCollection
        
        2. Create(propertyValue: MSPyECObjects.ECPropertyValue) -> MSPyECObjects.ECValuesCollection
        """
        ...
    
    def GetParentProperty(self: MSPyECObjects.ECValuesCollection) -> MSPyECObjects.ECPropertyValue:
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

    def Clear(self: MSPyECObjects.EvaluationResult) -> None:
        ...
    
    @property
    def ECValue(arg0: MSPyECObjects.EvaluationResult) -> Bentley.ECN.ECValue:
        ...
    
    def GetECValue(self: MSPyECObjects.EvaluationResult) -> Bentley.ECN.ECValue:
        ...
    
    def GetInstanceList(*args, **kwargs):
        """
        GetInstanceList(self: MSPyECObjects.EvaluationResult) -> Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >
        """
        ...
    
    def GetUnits(self: MSPyECObjects.EvaluationResult) -> Bentley.ECN.UnitSpec:
        ...
    
    def GetValueType(self: MSPyECObjects.EvaluationResult) -> MSPyECObjects.ValueType:
        ...
    
    @property
    def InstanceList(arg0: MSPyECObjects.EvaluationResult) -> Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >:
        ...
    
    def IsECValue(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def IsInstanceList(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def IsLambda(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def IsValueList(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def SetInstance(self: MSPyECObjects.EvaluationResult, instance: Bentley.ECN.IECInstance) -> None:
        ...
    
    def SetInstanceList(*args, **kwargs):
        """
        SetInstanceList(self: MSPyECObjects.EvaluationResult, instanceList: Bentley.Bstdcxx.bvector<Bentley.RefCountedPtr<Bentley.ECN.IECInstance>,Bentley.BentleyAllocator<Bentley.RefCountedPtr<Bentley.ECN.IECInstance> > >, makeCopy: bool) -> None
        """
        ...
    
    def SetUnits(self: MSPyECObjects.EvaluationResult, units: Bentley.ECN.UnitSpec) -> None:
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

    def AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    
    def SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None:
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
    
    def GetExpressionContext(self: MSPyECObjects.ExpressionResolver) -> MSPyECObjects.ExpressionContext:
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
        
    def GetContextType(self: MSPyECObjects.IAUIDataContext) -> MSPyECObjects.IAUIDataContext.ContextType:
        ...
    
    def GetCustomData(self: MSPyECObjects.IAUIDataContext) -> capsule:
        ...
    
    def GetInstanceIterable(self: MSPyECObjects.IAUIDataContext) -> MSPyECObjects.ECInstanceIterable:
        ...
    
    def GetMoniker(self: MSPyECObjects.IAUIDataContext) -> MSPyBentley.WString:
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

    def GenerateXmlString(self: MSPyECObjects.ICustomECStructSerializer, xmlString: MSPyBentley.WString, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance, baseAccessString: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def LoadStructureFromString(self: MSPyECObjects.ICustomECStructSerializer, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance, baseAccessString: str, valueString: str) -> None:
        ...
    
    def UsesCustomStructXmlString(self: MSPyECObjects.ICustomECStructSerializer, structProperty: MSPyECObjects.StructECProperty, ecInstance: Bentley.ECN.IECInstance) -> bool:
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
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def IsDefined(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
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
    
    def GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    def GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int:
        ...
    
    def GetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
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
    
    @staticmethod
    def IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple:
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    @staticmethod
    def ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    @staticmethod
    def ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString:
        ...
    
    def WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus:
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
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
    
    def append(self: MSPyECObjects.IECInstancePtrArray, x: MSPyECObjects.IECInstance) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.IECInstancePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.IECInstancePtrArray, x: MSPyECObjects.IECInstance) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.IECInstancePtrArray, L: MSPyECObjects.IECInstancePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.IECInstancePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.IECInstancePtrArray, i: int, x: MSPyECObjects.IECInstance) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.IECInstancePtrArray) -> MSPyECObjects.IECInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.IECInstancePtrArray, i: int) -> MSPyECObjects.IECInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.IECInstancePtrArray, x: MSPyECObjects.IECInstance) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class IECPresentationProvider:
    """
    None
    """

    def GetProviderId(self: MSPyECObjects.IECPresentationProvider) -> int:
        ...
    
    def GetProviderName(self: MSPyECObjects.IECPresentationProvider) -> str:
        ...
    
    def GetProviderType(self: MSPyECObjects.IECPresentationProvider) -> MSPyECObjects.IECPresentationProvider.ProviderType:
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

    def GetProviderId(self: MSPyECObjects.IECProvider) -> int:
        ...
    
    def GetProviderName(self: MSPyECObjects.IECProvider) -> str:
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

    def CreateWipRelationshipInstance(self: MSPyECObjects.IECRelationshipEnabler) -> Bentley.ECN.StandaloneECRelationshipInstance:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.IECRelationshipEnabler) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    def __init__(self: MSPyECObjects.IECRelationshipEnabler) -> None:
        ...
    
class IECRelationshipInstance:
    """
    None
    """

    def AddArrayElements(*args, **kwargs):
        """
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
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
    
    def GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    def GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int:
        ...
    
    def GetSource(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    
    def GetSourceOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple:
        ...
    
    def GetTarget(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    
    def GetTargetOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple:
        ...
    
    def GetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
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
    
    def IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple:
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    def ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetSource(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None:
        ...
    
    def SetTarget(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None:
        ...
    
    def SetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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
    
    def ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString:
        ...
    
    def WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus:
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
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

    def LocateSchema(self: MSPyECObjects.IECSchemaLocater, key: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType, schemaContext: MSPyECObjects.ECSchemaReadContext) -> Bentley.ECN.ECSchema:
        ...
    
    def __init__(self: MSPyECObjects.IECSchemaLocater) -> None:
        ...
    
class IECSymbolProvider:
    """
    None
    """

    def GetName(self: MSPyECObjects.IECSymbolProvider) -> str:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.IECSymbolProvider) -> str:
        ...
    
    def PublishSymbols(self: MSPyECObjects.IECSymbolProvider, context: MSPyECObjects.SymbolExpressionContext, requestedSymbolSets: MSPyBentley.WStringArray) -> None:
        ...
    
    @staticmethod
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

    def CanConvertFromString(self: MSPyECObjects.IECTypeAdapter, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def CanConvertToString(self: MSPyECObjects.IECTypeAdapter, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def CondenseFormatterForSerialization(self: MSPyECObjects.IECTypeAdapter, formatter: Bentley.ECN.IECInstance) -> Bentley.ECN.IECInstance:
        ...
    
    def ConvertFromExpressionType(self: MSPyECObjects.IECTypeAdapter, value: Bentley.ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def ConvertFromString(self: MSPyECObjects.IECTypeAdapter, value: Bentley.ECN.ECValue, str: str, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def ConvertToExpressionType(self: MSPyECObjects.IECTypeAdapter, value: Bentley.ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def ConvertToString(self: MSPyECObjects.IECTypeAdapter, str: MSPyBentley.WString, value: Bentley.ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext, formatter: Bentley.ECN.IECInstance = None) -> bool:
        ...
    
    def CreateDefaultFormatter(self: MSPyECObjects.IECTypeAdapter, includeAllValues: bool, forDwg: bool = False) -> Bentley.ECN.IECInstance:
        ...
    
    def GetUnits(self: MSPyECObjects.IECTypeAdapter, unit: Bentley.ECN.UnitSpec, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def HasStandardValues(self: MSPyECObjects.IECTypeAdapter) -> bool:
        ...
    
    def IsStruct(self: MSPyECObjects.IECTypeAdapter) -> bool:
        ...
    
    def IsTreatedAsString(self: MSPyECObjects.IECTypeAdapter) -> bool:
        ...
    
    def PopulateDefaultFormatterProperties(self: MSPyECObjects.IECTypeAdapter, formatter: Bentley.ECN.IECInstance) -> Bentley.ECN.IECInstance:
        ...
    
    def RequiresExpressionTypeConversion(*args, **kwargs):
        """
        RequiresExpressionTypeConversion(self: MSPyECObjects.IECTypeAdapter, evalOptions: MSPyECObjects.EvaluationOptions = <EvaluationOptions.eEVALOPT_Legacy: 0>) -> bool
        """
        ...
    
    def SupportsUnits(self: MSPyECObjects.IECTypeAdapter) -> bool:
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

    def LocateStandaloneEnabler(self: MSPyECObjects.IStandaloneEnablerLocater, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler:
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

    def AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    
    def SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def SetInstance(self: MSPyECObjects.InstanceExpressionContext, instance: Bentley.ECN.IECInstance) -> None:
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

    def AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    
    def SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None:
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

    def ClearValues(self: MSPyECObjects.MemoryECInstanceBase) -> None:
        ...
    
    def CopyFromBuffer(self: MSPyECObjects.ECDBuffer, source: MSPyECObjects.ECDBuffer) -> MSPyECObjects.ECObjectsStatus:
        """
        Attempts to copy property values from source buffer. Expects source to
        have a compatible class layout.
        
        Parameter ``source``:
        The ECDBuffer to copy values from
        """
        ...
    
    def GetData(self: MSPyECObjects.MemoryECInstanceBase) -> bytes:
        ...
    
    def IsEmpty(self: MSPyECObjects.ECDBuffer) -> bool:
        """
        Returns true if the buffer is empty (all values are null and all
        arrays are empty)
        """
        ...
    
    def MergePropertiesFromInstance(self: MSPyECObjects.MemoryECInstanceBase, fromNativeInstance: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetData(self: MSPyECObjects.MemoryECInstanceBase, data: bytes) -> None:
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

    @staticmethod
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

    def GetValue(self: MSPyECObjects.Node, context: MSPyECObjects.ExpressionContext) -> tuple:
        ...
    
    def ToExpressionString(self: MSPyECObjects.Node) -> MSPyBentley.WString:
        ...
    
    def ToString(self: MSPyECObjects.Node) -> MSPyBentley.WString:
        ...
    
    def Traverse(self: MSPyECObjects.Node, visitor: MSPyECObjects.NodeVisitor) -> bool:
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

    def CloseParens(self: MSPyECObjects.NodeVisitor) -> bool:
        ...
    
    def Comma(self: MSPyECObjects.NodeVisitor) -> bool:
        ...
    
    def EndArguments(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool:
        ...
    
    def EndArrayIndex(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool:
        ...
    
    def OpenParens(self: MSPyECObjects.NodeVisitor) -> bool:
        ...
    
    def ProcessNode(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool:
        ...
    
    def ProcessUnits(self: MSPyECObjects.NodeVisitor, units: Bentley.ECN.UnitSpec) -> bool:
        ...
    
    def StartArguments(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool:
        ...
    
    def StartArrayIndex(self: MSPyECObjects.NodeVisitor, node: Bentley.ECN.Node) -> bool:
        ...
    
    def __init__(self: MSPyECObjects.NodeVisitor) -> None:
        ...
    
class OrderIdEntries:
    """
    None
    """

    def Clear(self: MSPyECObjects.OrderIdEntries) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetSourceNextOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetSourceOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTargetNextOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTargetOrderId(self: MSPyECObjects.OrderIdEntries, orderId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def TryGetSourceNextOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple:
        ...
    
    def TryGetSourceOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple:
        ...
    
    def TryGetTargetNextOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple:
        ...
    
    def TryGetTargetOrderId(self: MSPyECObjects.OrderIdEntries) -> tuple:
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
        Overloaded function.
        
        1. HideProperty(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus
        
        2. HideProperty(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, hideIf2D: bool, hideIf3D: bool) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetAlwaysExpand(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, andArrayMembers: bool = False) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCustomCategory(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, uniqueName: str, displayLabel: str, priority: int, expand: bool = False, description: str = None) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetExtendedType(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, standardTypeId: int) -> MSPyECObjects.ECObjectsStatus
        
        2. SetExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, standardTypeName: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetHideNullProperties(self: MSPyECObjects.PresentationMetadataHelper, ecClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIgnoreZ(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetMemberExtendedType(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetMemberExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ArrayECProperty, standardTypeId: int) -> MSPyECObjects.ECObjectsStatus
        
        2. SetMemberExtendedType(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ArrayECProperty, standardTypeName: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetMembersIndependent(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetPriority(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, priority: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetRequiresReload(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetStandardCategory(self: MSPyECObjects.PresentationMetadataHelper, ecProperty: MSPyECObjects.ECProperty, standardCategoryId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetStoresUnitsAsUORs(self: MSPyECObjects.PresentationMetadataHelper, ecSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def __init__(self: MSPyECObjects.PresentationMetadataHelper, schemaContext: MSPyECObjects.ECSchemaReadContext) -> None:
        ...
    
class PrimitiveECProperty:
    """
    None
    """

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty:
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
    
    def GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    
    def GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetId(self: MSPyECObjects.ECProperty) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetIsArray(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsStruct(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetType(self: MSPyECObjects.PrimitiveECProperty) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
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
    
    def IsCalculated(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsDefined(*args, **kwargs):
        """
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
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetType(self: MSPyECObjects.PrimitiveECProperty, type: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
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
    
    def GetAccessString(self: MSPyECObjects.PropertyLayout) -> str:
        """
        Returns the access string for retrieving this property
        """
        ...
    
    def GetModifierData(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Returns the data used with the modifier flag, like the length of a
        fixed-sized string.
        """
        ...
    
    def GetModifierFlags(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Returns the modifier flags that describe this property, which can
        indicate @li that a string should be treated as fixed size @li that a
        string should have a max length @li that a longer fixed size type
        should be treated as an optional variable-sized type @li that for a
        string, only an entry to the string table is stored @li a default
        value should be used
        """
        ...
    
    def GetNullflagsBitmask(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Returns a bit mask that has the a single bit set. It can be used to
        AND with the bitmask at the offset returned by GetNullflagsOffset() to
        determine if the property is NULL.
        """
        ...
    
    def GetNullflagsOffset(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Returns the offset to Null flags bit mask.
        """
        ...
    
    def GetOffset(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Returns the offset to either the data holding this property's value
        (for fixed-size values) or to the offset at which the property's value
        can be found
        """
        ...
    
    def GetParentStructIndex(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Returns the property index of the struct parent of this property. If
        this is a root property an index of zero is returned.
        """
        ...
    
    def GetSizeInFixedSection(self: MSPyECObjects.PropertyLayout) -> int:
        """
        Gets the size required for this PropertyValue in the fixed Section of
        the IECInstance's memory Variable-sized types will have 4 byte
        SecondaryOffset stored in the fixed Section.
        """
        ...
    
    def GetTypeDescriptor(self: MSPyECObjects.PropertyLayout) -> Bentley.ECN.ECTypeDescriptor:
        """
        Returns an ECTypeDescriptor that defines this property
        """
        ...
    
    def HoldsCalculatedProperty(self: MSPyECObjects.PropertyLayout) -> bool:
        """
        Returns whether this property is actually a Calculated Property
        """
        ...
    
    def IsFixedSized(self: MSPyECObjects.PropertyLayout) -> bool:
        """
        Returns whether this is a fixed-size property
        """
        ...
    
    def IsReadOnlyProperty(self: MSPyECObjects.PropertyLayout) -> bool:
        """
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
    
    def SetReadOnlyProperty(self: MSPyECObjects.PropertyLayout, mask: bool) -> bool:
        ...
    
    @property
    def SizeInFixedSection(arg0: MSPyECObjects.PropertyLayout) -> int:
        ...
    
    def ToString(self: MSPyECObjects.PropertyLayout) -> MSPyBentley.WString:
        """
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
    
    def FromAccessString(self: MSPyECObjects.QualifiedECAccessor, rootEnabler: Bentley.ECN.ECEnabler, accessString: str) -> bool:
        ...
    
    def FromString(self: MSPyECObjects.QualifiedECAccessor, str: str) -> bool:
        ...
    
    def GetAccessString(self: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    
    def GetClassName(self: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    
    def GetSchemaName(self: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    
    @property
    def SchemaName(arg0: MSPyECObjects.QualifiedECAccessor) -> str:
        ...
    @SchemaName.setter
    def SchemaName(arg0: MSPyECObjects.QualifiedECAccessor, arg1: str) -> None:
        ...
    
    def SetAccessString(self: MSPyECObjects.QualifiedECAccessor, accessString: str) -> None:
        ...
    
    def SetClassName(self: MSPyECObjects.QualifiedECAccessor, name: str) -> None:
        ...
    
    def SetSchemaName(self: MSPyECObjects.QualifiedECAccessor, name: str) -> None:
        ...
    
    def ToString(self: MSPyECObjects.QualifiedECAccessor) -> MSPyBentley.WString:
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

    def GetLowerLimit(self: MSPyECObjects.RelationshipCardinality) -> int:
        ...
    
    def GetUpperLimit(self: MSPyECObjects.RelationshipCardinality) -> int:
        ...
    
    def IsUpperLimitUnbounded(self: MSPyECObjects.RelationshipCardinality) -> bool:
        ...
    
    @property
    def LowerLimit(arg0: MSPyECObjects.RelationshipCardinality) -> int:
        ...
    
    @staticmethod
    def OneMany() -> MSPyECObjects.RelationshipCardinality:
        ...
    
    @staticmethod
    def OneOne() -> MSPyECObjects.RelationshipCardinality:
        ...
    
    def ToString(self: MSPyECObjects.RelationshipCardinality) -> MSPyBentley.WString:
        ...
    
    @property
    def UpperLimit(arg0: MSPyECObjects.RelationshipCardinality) -> int:
        ...
    
    @staticmethod
    def ZeroMany() -> MSPyECObjects.RelationshipCardinality:
        ...
    
    @staticmethod
    def ZeroOne() -> MSPyECObjects.RelationshipCardinality:
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

    @staticmethod
    def ParseSchemaFullName(key: MSPyECObjects.SchemaKey, schemaFullName: str) -> MSPyECObjects.ECObjectsStatus:
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

    def GetFirst(self: MSPyECObjects.SchemaKeyToSchemaBPair) -> MSPyECObjects.SchemaKey:
        ...
    
    def GetSecond(self: MSPyECObjects.SchemaKeyToSchemaBPair) -> MSPyECObjects.ECSchema:
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

    def AddClassLayout(self: MSPyECObjects.SchemaLayout, classLayout: MSPyECObjects.ClassLayout, classIndex: int) -> Bentley.BentleyStatus:
        """
        Adds the ClassLayout at the given index
        
        Parameter ``classLayout``:
        The ClassLayout to add
        
        Parameter ``classIndex``:
        The index where to add the ClassLayout
        
        Returns:
        ERROR if a class layout already exists with the given index
        """
        ...
    
    def FindAvailableClassIndex(self: MSPyECObjects.SchemaLayout) -> tuple:
        """
        Finds the first available index for adding a class layout
        
        
        Returns (Tuple, 0):
        SUCCESS if the index is found, ERROR otherwise
        
        Returns (Tuple, 1):
        classIndex.  The first available index in the layout. This is not necessarily
        the size of the layout because there can be gaps.
        """
        ...
    
    def FindClassIndex(self: MSPyECObjects.SchemaLayout, className: str) -> tuple:
        """
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
    
    def FindClassLayout(self: MSPyECObjects.SchemaLayout, className: str) -> MSPyECObjects.ClassLayout:
        """
        Given a classname, tries to find the corresponding ClassLayout
        
        Parameter ``className``:
        The name of the class to find
        """
        ...
    
    def GetClassLayout(self: MSPyECObjects.SchemaLayout, classIndex: int) -> MSPyECObjects.ClassLayout:
        """
        Returns the ClassLayout at the given index
        
        Parameter ``classIndex``:
        The index of the desired ClassLayout
        
        Returns:
        A pointer to the requested ClassLayout if the index is valid, NULL
        otherwise
        """
        ...
    
    def GetMaxIndex(self: MSPyECObjects.SchemaLayout) -> int:
        """
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
    
    def GetSchemaIndex(self: MSPyECObjects.SchemaLayout) -> int:
        """
        Gets the SchemaIndex of this particular SchemaLayout.
        """
        ...
    
    def IsEmpty(self: MSPyECObjects.SchemaLayout) -> bool:
        """
        Returns whether or not this SchemaLayout has any ClassLayouts defined.
        """
        ...
    
    @property
    def MaxIndex(arg0: MSPyECObjects.SchemaLayout) -> int:
        ...
    
    def ReplaceClassLayout(self: MSPyECObjects.SchemaLayout, classLayout: MSPyECObjects.ClassLayout, classIndex: int) -> Bentley.BentleyStatus:
        """
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
    
    def items(self: MSPyECObjects.SchemaMapExact) -> MSPyECObjects.ItemsView[SchemaMapExact]:
        ...
    
    def keys(self: MSPyECObjects.SchemaMapExact) -> MSPyECObjects.KeysView[SchemaMapExact]:
        ...
    
    def values(self: MSPyECObjects.SchemaMapExact) -> MSPyECObjects.ValuesView[SchemaMapExact]:
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

    def Parse(self: MSPyECObjects.SchemaNameClassNamePair, schemaAndClassNameSeparatedByColon: MSPyBentley.WString) -> bool:
        ...
    
    def ToColonSeparatedString(self: MSPyECObjects.SchemaNameClassNamePair) -> MSPyBentley.WString:
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
    
    def append(self: MSPyECObjects.SchemaNameClassNamePairArray, x: MSPyECObjects.SchemaNameClassNamePair) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.SchemaNameClassNamePairArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.SchemaNameClassNamePairArray, x: MSPyECObjects.SchemaNameClassNamePair) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.SchemaNameClassNamePairArray, L: MSPyECObjects.SchemaNameClassNamePairArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.SchemaNameClassNamePairArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.SchemaNameClassNamePairArray, i: int, x: MSPyECObjects.SchemaNameClassNamePair) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.SchemaNameClassNamePairArray) -> MSPyECObjects.SchemaNameClassNamePair
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.SchemaNameClassNamePairArray, i: int) -> MSPyECObjects.SchemaNameClassNamePair
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.SchemaNameClassNamePairArray, x: MSPyECObjects.SchemaNameClassNamePair) -> None:
        """
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
    
    def CreateInstance(self: MSPyECObjects.StandaloneECEnabler, minimumInitialSize: int = 0) -> MSPyECObjects.StandaloneECInstance:
        ...
    
    def GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple:
        ...
    
    def GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    def GetClassLayout(self: MSPyECObjects.StandaloneECEnabler) -> MSPyECObjects.ClassLayout:
        ...
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    def GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int:
        ...
    
    def GetName(self: MSPyECObjects.ECEnabler) -> str:
        ...
    
    def GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int:
        ...
    
    def GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int:
        ...
    
    def GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple:
        ...
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentley.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool:
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
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance) -> MSPyECObjects.IECInstance
        
        2. CreateCopyThroughSerialization(self: MSPyECObjects.IECInstance, targetSchema: MSPyECObjects.ECSchema) -> MSPyECObjects.IECInstance
        """
        ...
    
    @staticmethod
    def Duplicate(instance: MSPyECObjects.IECInstance) -> MSPyECObjects.StandaloneECInstance:
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    def GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int:
        ...
    
    def GetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
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
    
    def IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple:
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    def ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString:
        ...
    
    def WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus:
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
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
    
    def append(self: MSPyECObjects.StandaloneECInstancePtrArray, x: MSPyECObjects.StandaloneECInstance) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.StandaloneECInstancePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.StandaloneECInstancePtrArray, x: MSPyECObjects.StandaloneECInstance) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.StandaloneECInstancePtrArray, L: MSPyECObjects.StandaloneECInstancePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.StandaloneECInstancePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.StandaloneECInstancePtrArray, i: int, x: MSPyECObjects.StandaloneECInstance) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.StandaloneECInstancePtrArray) -> MSPyECObjects.StandaloneECInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.StandaloneECInstancePtrArray, i: int) -> MSPyECObjects.StandaloneECInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.StandaloneECInstancePtrArray, x: MSPyECObjects.StandaloneECInstance) -> None:
        """
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
    
    def CreateInstance(self: MSPyECObjects.StandaloneECEnabler, minimumInitialSize: int = 0) -> MSPyECObjects.StandaloneECInstance:
        ...
    
    def CreateRelationshipInstance(self: MSPyECObjects.StandaloneECRelationshipEnabler) -> MSPyECObjects.StandaloneECRelationshipInstance:
        ...
    
    @property
    def ECEnabler(arg0: MSPyECObjects.StandaloneECRelationshipEnabler) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple:
        ...
    
    def GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    def GetClassLayout(self: MSPyECObjects.StandaloneECEnabler) -> MSPyECObjects.ClassLayout:
        ...
    
    def GetECEnabler(self: MSPyECObjects.StandaloneECRelationshipEnabler) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> Bentley.ECN.StandaloneECEnabler:
        ...
    
    def GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int:
        ...
    
    def GetName(self: MSPyECObjects.ECEnabler) -> str:
        ...
    
    def GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int:
        ...
    
    def GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int:
        ...
    
    def GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple:
        ...
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentley.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool:
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
        Overloaded function.
        
        1. AddArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. AddArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> Bentley.ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def ChangeValuesAllowed(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def ClearArray(*args, **kwargs):
        """
        Overloaded function.
        
        1. ClearArray(self: MSPyECObjects.IECInstance, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. ClearArray(self: MSPyECObjects.IECInstance, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def CopyValues(self: MSPyECObjects.IECInstance, source: MSPyECObjects.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def CreateCopyThroughSerialization(*args, **kwargs):
        """
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
    
    def GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    def GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.StandaloneECRelationshipInstance) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    def GetRelationshipEnabler(self: MSPyECObjects.StandaloneECRelationshipInstance) -> Bentley.ECN.StandaloneECRelationshipEnabler:
        ...
    
    def GetSource(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    
    def GetSourceAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance) -> str:
        ...
    
    def GetSourceOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple:
        ...
    
    def GetTarget(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    
    def GetTargetAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance) -> str:
        ...
    
    def GetTargetOrderId(self: MSPyECObjects.IECRelationshipInstance) -> tuple:
        ...
    
    def GetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: Bentley.ECN.ECValue, accessor: Bentley.ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
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
    
    def IsFixedArrayProperty(instance: MSPyECObjects.IECInstance, accessString: str) -> tuple:
        ...
    
    def IsPropertyNull(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str) -> tuple
        
        2. IsPropertyNull(self: MSPyECObjects.IECInstance, accessString: str, arrayIndex: int) -> tuple
        
        3. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int) -> tuple
        
        4. IsPropertyNull(self: MSPyECObjects.IECInstance, propertyIndex: int, arrayIndex: int) -> tuple
        """
        ...
    
    def IsPropertyReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, accessString: str) -> bool
        
        2. IsPropertyReadOnly(self: MSPyECObjects.IECInstance, propertyIndex: int) -> bool
        """
        ...
    
    def IsReadOnly(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    @property
    def OffsetToIECInstance(arg0: MSPyECObjects.IECInstance) -> int:
        ...
    
    def OrderIdEntries(self: MSPyECObjects.StandaloneECRelationshipInstance) -> MSPyECObjects.OrderIdEntries:
        ...
    
    def ReadFromXmlFile(fileName: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    def ReadFromXmlString(xmlString: str, context: MSPyECObjects.ECInstanceReadContext) -> tuple:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    @property
    def RelationshipEnabler(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> Bentley.ECN.StandaloneECRelationshipEnabler:
        ...
    
    def RemoveArrayElement(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveArrayElement(self: MSPyECObjects.IECInstance, accessString: str, index: int) -> MSPyECObjects.ECObjectsStatus
        
        2. RemoveArrayElement(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SaveOnlyLoadedPropertiesToXml(self: MSPyECObjects.IECInstance) -> bool:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetSource(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None:
        ...
    
    def SetSourceAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance, string: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetSourceOrderId(self: MSPyECObjects.StandaloneECRelationshipInstance, orderId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTarget(self: MSPyECObjects.IECRelationshipInstance, instance: MSPyECObjects.IECInstance) -> None:
        ...
    
    def SetTargetAssociatedString(self: MSPyECObjects.StandaloneECRelationshipInstance, string: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTargetOrderId(self: MSPyECObjects.StandaloneECRelationshipInstance, orderId: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: Bentley.ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: Bentley.ECN.ECValueAccessor, value: Bentley.ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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
    
    def ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString:
        ...
    
    def WriteToXmlFile(self: MSPyECObjects.IECInstance, fileName: str, writeInstanceId: bool, utf16: bool) -> MSPyECObjects.InstanceWriteStatus:
        ...
    
    def WriteToXmlString(*args, **kwargs):
        """
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

    @staticmethod
    def CreateCustomAttributeInstance(atributeName: str) -> MSPyECObjects.IECInstance:
        ...
    
    @staticmethod
    def GetCustomAttributeClass(attributeName: str) -> MSPyECObjects.ECClass:
        ...
    
    @staticmethod
    def IsDynamicSchema(schema: MSPyECObjects.ECSchema) -> bool:
        ...
    
    @staticmethod
    def IsSystemSchema(schema: MSPyECObjects.ECSchema) -> bool:
        ...
    
    @staticmethod
    def SetIsDynamicSchema(schema: MSPyECObjects.ECSchema, isDynamicSchema: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @staticmethod
    def TryGetDateTimeInfo(dateTimeInfo: MSPyECObjects.DateTimeInfo, dateTimeProperty: MSPyECObjects.ECProperty) -> bool:
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

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> Bentley.ECN.StructECProperty:
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
    
    def GetBaseProperty(self: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    
    def GetClass(self: MSPyECObjects.ECProperty) -> Bentley.ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetId(self: MSPyECObjects.ECProperty) -> int:
        ...
    
    def GetInvariantDescription(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetInvariantDisplayLabel(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetIsArray(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsDisplayLabelDefined(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsPrimitive(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsReadOnly(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetIsStruct(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> Bentley.ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> Bentley.ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> Bentley.ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetType(self: MSPyECObjects.StructECProperty) -> Bentley.ECN.ECClass:
        ...
    
    def GetTypeName(self: MSPyECObjects.ECProperty) -> MSPyBentley.WString:
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
    
    def IsCalculated(self: MSPyECObjects.ECProperty) -> bool:
        ...
    
    def IsDefined(*args, **kwargs):
        """
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
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: Bentley.ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: Bentley.ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: Bentley.ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDescription(self: MSPyECObjects.ECProperty, description: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.ECProperty, label: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetIsReadOnly(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetIsReadOnly(self: MSPyECObjects.ECProperty, readOnly: bool) -> MSPyECObjects.ECObjectsStatus
        
        2. SetIsReadOnly(self: MSPyECObjects.ECProperty, isReadOnly: str) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetType(self: MSPyECObjects.StructECProperty, type: Bentley.ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
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

    def GetPrimarySchemaFullName(self: MSPyECObjects.SupplementalSchemaInfo) -> MSPyBentley.WString:
        ...
    
    def GetPurposeOfSupplementalSchema(self: MSPyECObjects.SupplementalSchemaInfo, fullSchemaName: MSPyBentley.WString) -> MSPyBentley.WString:
        ...
    
    def GetSupplementalSchemaNames(self: MSPyECObjects.SupplementalSchemaInfo, supplementalSchemaNames: MSPyBentley.WStringArray) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetSupplementalSchemasWithPurpose(self: MSPyECObjects.SupplementalSchemaInfo, supplementalSchemaNames: MSPyBentley.WStringArray, purpose: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def HasSameSupplementalSchemasForPurpose(self: MSPyECObjects.SupplementalSchemaInfo, secondSchema: MSPyECObjects.ECSchema, purpose: MSPyBentley.WString) -> bool:
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

    def CreateCustomAttribute(self: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyECObjects.IECInstance:
        ...
    
    CustomAttributeAccessor: str
    
    CustomAttributeSchemaName: str
    
    @staticmethod
    def GetCustomAttributeAccessor() -> str:
        ...
    
    @staticmethod
    def GetCustomAttributeSchemaName() -> str:
        ...
    
    @staticmethod
    def GetIsUserSpecificPropertyAccessor() -> str:
        ...
    
    @staticmethod
    def GetPrecedencePropertyAccessor() -> str:
        ...
    
    def GetPrimarySchemaMajorVersion(self: MSPyECObjects.SupplementalSchemaMetaData) -> int:
        ...
    
    @staticmethod
    def GetPrimarySchemaMajorVersionPropertyAccessor() -> str:
        ...
    
    def GetPrimarySchemaMinorVersion(self: MSPyECObjects.SupplementalSchemaMetaData) -> int:
        ...
    
    @staticmethod
    def GetPrimarySchemaMinorVersionPropertyAccessor() -> str:
        ...
    
    def GetPrimarySchemaName(self: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyBentley.WString:
        ...
    
    @staticmethod
    def GetPrimarySchemaNamePropertyAccessor() -> str:
        ...
    
    @staticmethod
    def GetPurposePropertyAccessor() -> str:
        ...
    
    def GetSupplementalSchemaPrecedence(self: MSPyECObjects.SupplementalSchemaMetaData) -> int:
        ...
    
    def GetSupplementalSchemaPurpose(self: MSPyECObjects.SupplementalSchemaMetaData) -> MSPyBentley.WString:
        ...
    
    def IsForPrimarySchema(self: MSPyECObjects.SupplementalSchemaMetaData, schemaName: MSPyBentley.WString, majorVersion: int, minorVersion: int, matchType: MSPyECObjects.SchemaMatchType) -> bool:
        ...
    
    def IsSupplemental(self: MSPyECObjects.SupplementalSchemaMetaData, schema: MSPyECObjects.ECSchema) -> bool:
        ...
    
    def IsUserSpecific(self: MSPyECObjects.SupplementalSchemaMetaData) -> bool:
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
    
    @staticmethod
    def SetMetadata(supplementalSchema: MSPyECObjects.ECSchema, supplementalSchemaMetadata: MSPyECObjects.SupplementalSchemaMetaData) -> None:
        ...
    
    def SetPrimarySchemaMajorVersion(self: MSPyECObjects.SupplementalSchemaMetaData, major: int) -> None:
        ...
    
    def SetPrimarySchemaMinorVersion(self: MSPyECObjects.SupplementalSchemaMetaData, minor: int) -> None:
        ...
    
    def SetPrimarySchemaName(self: MSPyECObjects.SupplementalSchemaMetaData, name: MSPyBentley.WString) -> None:
        ...
    
    def SetSupplementalSchemaPrecedence(self: MSPyECObjects.SupplementalSchemaMetaData, precedence: int) -> None:
        ...
    
    def SetSupplementalSchemaPurpose(self: MSPyECObjects.SupplementalSchemaMetaData, purpose: MSPyBentley.WString) -> None:
        ...
    
    def SetUserSpecific(self: MSPyECObjects.SupplementalSchemaMetaData, userSpecific: bool) -> None:
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
    
    @staticmethod
    def TryGetFromSchema(supplementalSchema: MSPyECObjects.ECSchema) -> tuple:
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

    def AddSymbol(self: MSPyECObjects.SymbolExpressionContext, symbol: Bentley.ECN.Symbol) -> Bentley.BentleyStatus:
        ...
    
    def AllowsTypeConversion(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforceGlobalRepresentation(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    def EnforcesUnits(self: MSPyECObjects.ExpressionContext) -> bool:
        ...
    
    @property
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    @EvaluationOptions.setter
    def EvaluationOptions(arg0: MSPyECObjects.ExpressionContext, arg1: MSPyECObjects.EvaluationOptions) -> None:
        ...
    
    def GetEvaluationOptions(self: MSPyECObjects.ExpressionContext) -> MSPyECObjects.EvaluationOptions:
        ...
    
    def SetEvaluationOptions(self: MSPyECObjects.ExpressionContext, options: MSPyECObjects.EvaluationOptions) -> None:
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

    def GetECValue(self: MSPyECObjects.ValueResult, ecValue: Bentley.ECN.ECValue) -> MSPyECObjects.ExpressionStatus:
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

    def GetKey(self: MSPyECObjects.WStringKey) -> str:
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
    
    def append(self: MSPyECObjects.WStringKeyArray, x: MSPyECObjects.WStringKey) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.WStringKeyArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.WStringKeyArray, x: MSPyECObjects.WStringKey) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.WStringKeyArray, L: MSPyECObjects.WStringKeyArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.WStringKeyArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.WStringKeyArray, i: int, x: MSPyECObjects.WStringKey) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.WStringKeyArray) -> MSPyECObjects.WStringKey
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.WStringKeyArray, i: int) -> MSPyECObjects.WStringKey
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.WStringKeyArray, x: MSPyECObjects.WStringKey) -> None:
        """
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

