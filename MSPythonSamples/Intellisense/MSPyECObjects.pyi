from typing import Any, Optional, overload, Type, Sequence, Iterable, Union, Callable
from enum import Enum
import MSPyECObjects

class ApplicationToolData:
    """
    None
    """

    @property
    def Owner(arg0: MSPyECObjects.ApplicationToolData) -> str:
        ...
    @Owner.setter
    def Owner(arg0: MSPyECObjects.ApplicationToolData, arg1: str) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    @property
    def cmdNum(self: MSPyECObjects.ApplicationToolData) -> int:
        ...
    @cmdNum.setter
    def cmdNum(self: MSPyECObjects.ApplicationToolData, arg0: int) -> None:
        ...
    
    @property
    def iconID(self: MSPyECObjects.ApplicationToolData) -> int:
        ...
    @iconID.setter
    def iconID(self: MSPyECObjects.ApplicationToolData, arg0: int) -> None:
        ...
    
    @property
    def iconOwner(arg0: MSPyECObjects.ApplicationToolData) -> str:
        ...
    @iconOwner.setter
    def iconOwner(arg0: MSPyECObjects.ApplicationToolData, arg1: str) -> None:
        ...
    
    @property
    def iconType(self: MSPyECObjects.ApplicationToolData) -> int:
        ...
    @iconType.setter
    def iconType(self: MSPyECObjects.ApplicationToolData, arg0: int) -> None:
        ...
    
    @property
    def itemArg(self: MSPyECObjects.ApplicationToolData) -> int:
        ...
    @itemArg.setter
    def itemArg(self: MSPyECObjects.ApplicationToolData, arg0: int) -> None:
        ...
    
    @property
    def rscId(self: MSPyECObjects.ApplicationToolData) -> int:
        ...
    @rscId.setter
    def rscId(self: MSPyECObjects.ApplicationToolData, arg0: int) -> None:
        ...
    
    @property
    def rscType(self: MSPyECObjects.ApplicationToolData) -> int:
        ...
    @rscType.setter
    def rscType(self: MSPyECObjects.ApplicationToolData, arg0: int) -> None:
        ...
    
class ArrayAccessorArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ArrayAccessorArray) -> None
        
        2. __init__(self: MSPyECObjects.ArrayAccessorArray, arg0: MSPyECObjects.ArrayAccessorArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ArrayAccessorArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.ArrayAccessorArray, x: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ArrayAccessorArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ArrayAccessorArray, L: MSPyECObjects.ArrayAccessorArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ArrayAccessorArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ArrayAccessorArray, i: int, x: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ArrayAccessorArray) -> MSPyECObjects.ReportColumnAccessor.ArrayAccessor
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ArrayAccessorArray, i: int) -> MSPyECObjects.ReportColumnAccessor.ArrayAccessor
        
        Remove and return the item at index ``i``
        """
        ...
    
class ArrayECProperty:
    """
    None
    """

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> ECN.StructECProperty:
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> ECN.ECClass:
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
    
    def GetClass(self: MSPyECObjects.ECProperty) -> ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetPrimitiveElementType(self: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.PrimitiveType:
        ...
    
    def GetStructElementType(self: MSPyECObjects.ArrayECProperty) -> ECN.ECClass:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    
    def SetStructElementType(self: MSPyECObjects.ArrayECProperty, type: ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def StructElementType(arg0: MSPyECObjects.ArrayECProperty) -> ECN.ECClass:
        ...
    @StructElementType.setter
    def StructElementType(arg0: MSPyECObjects.ArrayECProperty, arg1: ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
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
    def BuildFromClass(ecClass: ECN.ECClass) -> MSPyECObjects.ClassLayout:
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
        
        :param className:
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
    
    def GetECPointerIndex(self: MSPyECObjects.ClassLayout, end: ECN.ECRelationshipEnd) -> int:
        """
        Returns the property index of the given relationship end
        
        :param end:
        The ECRelationshipEnd for which to get the pointer index
        
        :returns:
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
        
        
        :param accessString:
        The access string for the desired property
        
        Returns(Tuple, 0):
        ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
        ECOBJECTS_STATUS_Success otherwise
        
        Returns (Tuple, 1):
        propertyIndex. Will contain the index of the given property within the
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
        
        :param propertyLayout:
        Will point to the PropertyLayout if found
        
        :param propertyIndex:
        The index in the ClassLayout of the desired property
        
        :returns:
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
        propertyIndex. Will contain the index of the given property within the
        ClassLayout, if found
        """
        ...
    
    def IsCompatible(self: MSPyECObjects.ClassLayout, layout: MSPyECObjects.ClassLayout) -> bool:
        """
        Checks the given classLayout to see if it is equal to, or a subset of,
        this layout
        
        :param layout:
        The ClassLayout to test compatibility of
        
        :returns:
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
        
        :param propertyIndex:
        The index within the ClassLayout of the property to set the read-
        only flag for
        
        :param readOnly:
        Flag indicating whether this property is read-only
        
        :returns:
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
    
class ColumnDefinitionNode:
    """
    None
    """

    @property
    def Accessors(arg0: MSPyECObjects.ColumnDefinitionNode) -> MSPyECObjects.ReportColumnAccessorArray:
        ...
    @Accessors.setter
    def Accessors(arg0: MSPyECObjects.ColumnDefinitionNode, arg1: MSPyECObjects.ReportColumnAccessorArray) -> bool:
        ...
    
    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAccessors(self: MSPyECObjects.ColumnDefinitionNode) -> MSPyECObjects.ReportColumnAccessorArray:
        """
        Returns the list of accessors from which this column will obtain its
        values
        """
        ...
    
    def GetArraySortingOptions(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetArraySortingOptions(self: MSPyECObjects.ColumnDefinitionNode, createIfNotFound: bool) -> MSPyECObjects.IECInstance
        
        Returns the options which will be used to sort within array values for
        ArrayOption.AllMembers or ArrayOption.List
        
        2. GetArraySortingOptions(self: MSPyECObjects.ColumnDefinitionNode) -> MSPyECObjects.IECInstance
        
        Returns the options which will be used to sort within array values for
        ArrayOption.AllMembers or ArrayOption.List
        """
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFormattingOptions(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetFormattingOptions(self: MSPyECObjects.ColumnDefinitionNode, createIfNotFound: bool) -> MSPyECObjects.IECInstance
        
        Returns the options which will be used to format values in this column
        for display
        
        2. GetFormattingOptions(self: MSPyECObjects.ColumnDefinitionNode) -> MSPyECObjects.IECInstance
        
        Returns the options which will be used to format values in this column
        for display
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    @property
    def GetListDelimiter(arg0: MSPyECObjects.ColumnDefinitionNode) -> MSPyBentley.WString:
        ...
    @GetListDelimiter.setter
    def GetListDelimiter(arg0: MSPyECObjects.ColumnDefinitionNode, arg1: str) -> bool:
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetNumAccessors(self: MSPyECObjects.ColumnDefinitionNode) -> int:
        """
        Returns the number of accessors (ECPropertyValues) associated with
        this column.
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def NumAccessors(arg0: MSPyECObjects.ColumnDefinitionNode) -> int:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetAccessors(self: MSPyECObjects.ColumnDefinitionNode, accessors: MSPyECObjects.ReportColumnAccessorArray) -> bool:
        """
        Sets the list of accessors from which this column will obtain its
        values
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(self: MSPyECObjects.ColumnDefinitionNode, node: MSPyECObjects.ECReportNode) -> None:
        ...
    
class ColumnDefinitionNodePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ColumnDefinitionNodePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.ColumnDefinitionNodePtrArray, arg0: MSPyECObjects.ColumnDefinitionNodePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ColumnDefinitionNodePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.ColumnDefinitionNodePtrArray, x: MSPyECObjects.ColumnDefinitionNode) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ColumnDefinitionNodePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.ColumnDefinitionNodePtrArray, x: MSPyECObjects.ColumnDefinitionNode) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ColumnDefinitionNodePtrArray, L: MSPyECObjects.ColumnDefinitionNodePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ColumnDefinitionNodePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ColumnDefinitionNodePtrArray, i: int, x: MSPyECObjects.ColumnDefinitionNode) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ColumnDefinitionNodePtrArray) -> MSPyECObjects.ColumnDefinitionNode
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ColumnDefinitionNodePtrArray, i: int) -> MSPyECObjects.ColumnDefinitionNode
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.ColumnDefinitionNodePtrArray, x: MSPyECObjects.ColumnDefinitionNode) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ColumnGroupNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    @property
    def ColumnDefinitions(arg0: MSPyECObjects.ColumnGroupNode) -> MSPyECObjects.ColumnDefinitionNodePtrArray:
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    def CreateColumnDefinition(self: MSPyECObjects.ColumnGroupNode, name: str, sortPriority: int) -> MSPyECObjects.ColumnDefinitionNode:
        """
        Creates and returns a new column definition
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetColumnDefinitions(self: MSPyECObjects.ColumnGroupNode) -> MSPyECObjects.ColumnDefinitionNodePtrArray:
        """
        Returns the list of column definitions
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(self: MSPyECObjects.ColumnGroupNode, node: MSPyECObjects.ECReportNode) -> None:
        ...
    
class ContextMenuNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ContextMenuNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.ContextMenuNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ContextMenuNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ContextMenuNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ContextMenuNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
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

    def AddCustomSerializer(self: MSPyECObjects.CustomStructSerializerManager, serializerName: str, serializer: MSPyECObjects.ICustomECStructSerializer) -> BentleyStatus:
        ...
    
    def GetCustomSerializer(self: MSPyECObjects.CustomStructSerializerManager, structProperty: MSPyECObjects.StructECProperty, ecInstance: ECN.IECInstance) -> MSPyECObjects.ICustomECStructSerializer:
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
    
class DeleteDgnECInstanceStatus:
    """
    Members:
    
    eDELETEDGNECINSTANCE_Success
    
    eDELETEDGNECINSTANCE_FileReadOnly
    
    eDELETEDGNECINSTANCE_ProviderDoesNotSupportDelete
    
    eDELETEDGNECINSTANCE_UnableToParseInstanceId
    
    eDELETEDGNECINSTANCE_InvalidProviderId
    
    eDELETEDGNECINSTANCE_InvalidOrDeletedElement
    
    eDELETEDGNECINSTANCE_UnableToLocateInstance
    
    eDELETEDGNECINSTANCE_SchedulingDeleteNotSupportedByProvider
    
    eDELETEDGNECINSTANCE_Error
    """

    def __init__(self: MSPyECObjects.DeleteDgnECInstanceStatus, value: int) -> None:
        ...
    
    eDELETEDGNECINSTANCE_Error: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_FileReadOnly: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_InvalidOrDeletedElement: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_InvalidProviderId: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_ProviderDoesNotSupportDelete: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_SchedulingDeleteNotSupportedByProvider: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_Success: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_UnableToLocateInstance: DeleteDgnECInstanceStatus
    
    eDELETEDGNECINSTANCE_UnableToParseInstanceId: DeleteDgnECInstanceStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.DeleteDgnECInstanceStatus) -> int:
        ...
    
class DgnActionItemContext:
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
    
    def GetHitPath(self: MSPyECObjects.DgnActionItemContext) -> MSPyDgnPlatform.HitPath:
        """
        When the item context is invoked from the view window, If the mouse is
        not over any element, path will be NULL.
        """
        ...
    
    def GetInstanceIterable(self: MSPyECObjects.IAUIDataContext) -> MSPyECObjects.ECInstanceIterable:
        ...
    
    def GetMoniker(self: MSPyECObjects.IAUIDataContext) -> MSPyBentley.WString:
        ...
    
    def GetPoint(self: MSPyECObjects.DgnActionItemContext) -> MSPyBentleyGeom.DPoint3d:
        """
        The active coordinate location of the mouse
        """
        ...
    
    def GetRootElement(self: MSPyECObjects.DgnActionItemContext) -> MSPyDgnPlatform.ElementHandle:
        """
        Utility function to get the root element from the hitpath
        """
        ...
    
    def GetView(self: MSPyECObjects.DgnActionItemContext) -> MSPyDgnPlatform.Viewport:
        """
        The viewport of the mouse
        """
        ...
    
    @property
    def HitPath(arg0: MSPyECObjects.DgnActionItemContext) -> MSPyDgnPlatform.HitPath:
        ...
    
    @property
    def Point(arg0: MSPyECObjects.DgnActionItemContext) -> MSPyBentleyGeom.DPoint3d:
        ...
    
    @property
    def RootElement(arg0: MSPyECObjects.DgnActionItemContext) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def View(arg0: MSPyECObjects.DgnActionItemContext) -> MSPyDgnPlatform.Viewport:
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
    
class DgnECExtendedType:
    """
    None
    """

    class StandardType:
        """
        Members:
        
        eElementType
        
        eLevel
        
        eColor
        
        eWeight
        
        eStyle
        
        eElementClass
        
        eCoordinates
        
        eDistance
        
        eArea
        
        eVolume
        
        eAngle
        
        eTextStyle
        
        eRenderingMaterial
        
        eDirectionAngle
        
        eUnitlessPoint
        
        eNamedScale
        
        eProjectionNamedGroup
        
        eFileSize
        
        eFileSizeLong
        
        eDisplayPriority
        
        eFontName
        
        eBigFontName
        
        eElementID
        
        eHatchCell
        
        eXyzRotations
        
        eUnitDefinition
        """
    
        def __init__(self: MSPyECObjects.DgnECExtendedType.StandardType, value: int) -> None:
            ...
        
        eAngle: StandardType
        
        eArea: StandardType
        
        eBigFontName: StandardType
        
        eColor: StandardType
        
        eCoordinates: StandardType
        
        eDirectionAngle: StandardType
        
        eDisplayPriority: StandardType
        
        eDistance: StandardType
        
        eElementClass: StandardType
        
        eElementID: StandardType
        
        eElementType: StandardType
        
        eFileSize: StandardType
        
        eFileSizeLong: StandardType
        
        eFontName: StandardType
        
        eHatchCell: StandardType
        
        eLevel: StandardType
        
        eNamedScale: StandardType
        
        eProjectionNamedGroup: StandardType
        
        eRenderingMaterial: StandardType
        
        eStyle: StandardType
        
        eTextStyle: StandardType
        
        eUnitDefinition: StandardType
        
        eUnitlessPoint: StandardType
        
        eVolume: StandardType
        
        eWeight: StandardType
        
        eXyzRotations: StandardType
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.DgnECExtendedType.StandardType) -> int:
            ...
        
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eAngle: StandardType
    
    eArea: StandardType
    
    eBigFontName: StandardType
    
    eColor: StandardType
    
    eCoordinates: StandardType
    
    eDirectionAngle: StandardType
    
    eDisplayPriority: StandardType
    
    eDistance: StandardType
    
    eElementClass: StandardType
    
    eElementID: StandardType
    
    eElementType: StandardType
    
    eFileSize: StandardType
    
    eFileSizeLong: StandardType
    
    eFontName: StandardType
    
    eHatchCell: StandardType
    
    eLevel: StandardType
    
    eNamedScale: StandardType
    
    eProjectionNamedGroup: StandardType
    
    eRenderingMaterial: StandardType
    
    eStyle: StandardType
    
    eTextStyle: StandardType
    
    eUnitDefinition: StandardType
    
    eUnitlessPoint: StandardType
    
    eVolume: StandardType
    
    eWeight: StandardType
    
    eXyzRotations: StandardType
    
class DgnECHostIterable:
    """
    None
    """

    def __init__(self: MSPyECObjects.DgnECHostIterable, primaryInstances: MSPyDgnPlatform.DgnECInstanceIterable, context: MSPyECObjects.DgnECHostSpecificationsContext) -> None:
        ...
    
class DgnECHostRelationshipSpecification:
    """
    None
    """

    @property
    def Direction(arg0: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.ECRelatedInstanceDirection:
        ...
    @Direction.setter
    def Direction(arg0: MSPyECObjects.DgnECHostRelationshipSpecification, arg1: MSPyECObjects.ECRelatedInstanceDirection) -> None:
        ...
    
    class Flags:
        """
        Members:
        
        ekFlag_Required
        
        ekFlag_Backward
        
        ekFlag_RelatedPolymorphic
        
        ekFlag_RelationshipPolymorphic
        
        ekFlags_None
        
        ekFlags_Default
        """
    
        def __init__(self: MSPyECObjects.DgnECHostRelationshipSpecification.Flags, value: int) -> None:
            ...
        
        ekFlag_Backward: Flags
        
        ekFlag_RelatedPolymorphic: Flags
        
        ekFlag_RelationshipPolymorphic: Flags
        
        ekFlag_Required: Flags
        
        ekFlags_Default: Flags
        
        ekFlags_None: Flags
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.DgnECHostRelationshipSpecification.Flags) -> int:
            ...
        
    def GetDirection(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.ECRelatedInstanceDirection:
        """
        Returns the direction in which the ECRelationship will be queried
        """
        ...
    
    def GetNestedSpecification(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.DgnECHostRelationshipSpecification:
        """
        Returns the specifications for any ECInstances related to this related
        ECInstance which should be included in the report definition.
        """
        ...
    
    def GetRelatedClass(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.SchemaNameClassNamePair:
        """
        Returns the schema and class name of the related ECClass
        """
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.SchemaNameClassNamePair:
        """
        Returns the schema and class name of the ECRelationshipClass
        """
        ...
    
    def IsRelatedPolymorphic(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> bool:
        """
        Returns whether related ECInstances will be queried polymorphically
        """
        ...
    
    def IsRelationshipPolymorphic(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> bool:
        """
        Returns whether ECRelationships will be queried polymorphically
        """
        ...
    
    def IsRequired(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> bool:
        """
        Returns whether the source ECInstance will be excluded if this
        specification fails to find a related ECInstance
        """
        ...
    
    @property
    def NestedSpecification(arg0: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.DgnECHostRelationshipSpecification:
        ...
    @NestedSpecification.setter
    def NestedSpecification(arg0: MSPyECObjects.DgnECHostRelationshipSpecification, arg1: MSPyECObjects.DgnECHostRelationshipSpecification) -> None:
        ...
    
    @property
    def RelatedClass(arg0: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.SchemaNameClassNamePair:
        ...
    @RelatedClass.setter
    def RelatedClass(arg0: MSPyECObjects.DgnECHostRelationshipSpecification, arg1: MSPyECObjects.SchemaNameClassNamePair) -> None:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.DgnECHostRelationshipSpecification) -> MSPyECObjects.SchemaNameClassNamePair:
        ...
    @RelationshipClass.setter
    def RelationshipClass(arg0: MSPyECObjects.DgnECHostRelationshipSpecification, arg1: MSPyECObjects.SchemaNameClassNamePair) -> None:
        ...
    
    def SetDirection(self: MSPyECObjects.DgnECHostRelationshipSpecification, dir: MSPyECObjects.ECRelatedInstanceDirection) -> None:
        """
        Sets the direction in which the ECRelationship will be queried
        """
        ...
    
    def SetNestedSpecification(self: MSPyECObjects.DgnECHostRelationshipSpecification, spec: MSPyECObjects.DgnECHostRelationshipSpecification) -> None:
        """
        Sets specifications for any ECInstances related to this ECInstance
        which should be included in the report definition
        """
        ...
    
    def SetRelatedClass(self: MSPyECObjects.DgnECHostRelationshipSpecification, pair: MSPyECObjects.SchemaNameClassNamePair) -> None:
        """
        Sets the schema and class name of the related ECInstance
        """
        ...
    
    def SetRelatedPolymorphic(self: MSPyECObjects.DgnECHostRelationshipSpecification, poly: bool) -> None:
        """
        Sets whether related ECInstances will be queried polymorphically
        """
        ...
    
    def SetRelationshipClass(self: MSPyECObjects.DgnECHostRelationshipSpecification, pair: MSPyECObjects.SchemaNameClassNamePair) -> None:
        """
        Sets the schema and class name of the ECRelationshipClass
        """
        ...
    
    def SetRelationshipPolymorphic(self: MSPyECObjects.DgnECHostRelationshipSpecification, poly: bool) -> None:
        """
        Sets whether ECRelationships will be queried polymorphically
        """
        ...
    
    def SetRequired(self: MSPyECObjects.DgnECHostRelationshipSpecification, required: bool) -> None:
        """
        Sets whether failure to find a related ECInstance matching this
        specification will exclude the source ECInstance from the report
        results
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECHostRelationshipSpecification, relationship: MSPyECObjects.SchemaNameClassNamePair, related: MSPyECObjects.SchemaNameClassNamePair, dir: MSPyECObjects.ECRelatedInstanceDirection = <ECRelatedInstanceDirection.eSTRENGTHDIRECTION_Forward: 1>, required: bool = False, relationshipPolymorphic: bool = True, relatedPolymorphic: bool = True) -> None
        
        2. __init__(self: MSPyECObjects.DgnECHostRelationshipSpecification, rhs: MSPyECObjects.DgnECHostRelationshipSpecification) -> None
        
        3. __init__(self: MSPyECObjects.DgnECHostRelationshipSpecification) -> None
        """
        ...
    
    ekFlag_Backward: Flags
    
    ekFlag_RelatedPolymorphic: Flags
    
    ekFlag_RelationshipPolymorphic: Flags
    
    ekFlag_Required: Flags
    
    ekFlags_Default: Flags
    
    ekFlags_None: Flags
    
class DgnECHostRelationshipSpecificationArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> None
        
        2. __init__(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, arg0: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, x: MSPyECObjects.DgnECHostRelationshipSpecification) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, L: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, i: int, x: MSPyECObjects.DgnECHostRelationshipSpecification) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> MSPyECObjects.DgnECHostRelationshipSpecification
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnECHostRelationshipSpecificationArray, i: int) -> MSPyECObjects.DgnECHostRelationshipSpecification
        
        Remove and return the item at index ``i``
        """
        ...
    
class DgnECHostSpecification:
    """
    None
    """

    def GetPrimaryClasses(self: MSPyECObjects.DgnECHostSpecification) -> MSPyECObjects.SchemaNameClassNamePairArray:
        """
        Returns the schema and class names of the primary ECInstances
        """
        ...
    
    def GetRelationships(self: MSPyECObjects.DgnECHostSpecification) -> MSPyECObjects.DgnECHostRelationshipSpecificationArray:
        """
        Returns the list of specifications for ECInstances related to the
        primary ECInstances to also be included in the report results
        """
        ...
    
    @property
    def PrimaryClasses(arg0: MSPyECObjects.DgnECHostSpecification) -> MSPyECObjects.SchemaNameClassNamePairArray:
        ...
    @PrimaryClasses.setter
    def PrimaryClasses(arg0: MSPyECObjects.DgnECHostSpecification, arg1: MSPyECObjects.SchemaNameClassNamePairArray) -> None:
        ...
    
    @property
    def Relationships(arg0: MSPyECObjects.DgnECHostSpecification) -> MSPyECObjects.DgnECHostRelationshipSpecificationArray:
        ...
    @Relationships.setter
    def Relationships(arg0: MSPyECObjects.DgnECHostSpecification, arg1: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> None:
        ...
    
    def SetPrimaryClasses(self: MSPyECObjects.DgnECHostSpecification, classes: MSPyECObjects.SchemaNameClassNamePairArray) -> None:
        """
        Sets the schema and class names of the primary ECInstances from which
        the report results will be populated
        """
        ...
    
    def SetRelationships(self: MSPyECObjects.DgnECHostSpecification, rels: MSPyECObjects.DgnECHostRelationshipSpecificationArray) -> None:
        """
        Sets the specifications for ECInstances related to the primary
        ECInstances to also be included in the report results
        """
        ...
    
    def __init__(self: MSPyECObjects.DgnECHostSpecification) -> None:
        ...
    
class DgnECHostSpecificationArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECHostSpecificationArray) -> None
        
        2. __init__(self: MSPyECObjects.DgnECHostSpecificationArray, arg0: MSPyECObjects.DgnECHostSpecificationArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnECHostSpecificationArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnECHostSpecificationArray, x: MSPyECObjects.DgnECHostSpecification) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnECHostSpecificationArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnECHostSpecificationArray, L: MSPyECObjects.DgnECHostSpecificationArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnECHostSpecificationArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnECHostSpecificationArray, i: int, x: MSPyECObjects.DgnECHostSpecification) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnECHostSpecificationArray) -> MSPyECObjects.DgnECHostSpecification
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnECHostSpecificationArray, i: int) -> MSPyECObjects.DgnECHostSpecification
        
        Remove and return the item at index ``i``
        """
        ...
    
class DgnECHostSpecificationsContext:
    """
    None
    """

    def __init__(self: MSPyECObjects.DgnECHostSpecificationsContext, hostSpecs: MSPyECObjects.DgnECHostSpecificationArray) -> None:
        ...
    
class DgnECHostType:
    """
    Members:
    
    eUnknown
    
    eElement
    
    eModel
    
    eFile
    
    eDesignLink
    
    eView
    
    eAttachment
    
    eLevel
    
    eAll
    """

    def __init__(self: MSPyECObjects.DgnECHostType, value: int) -> None:
        ...
    
    eAll: DgnECHostType
    
    eAttachment: DgnECHostType
    
    eDesignLink: DgnECHostType
    
    eElement: DgnECHostType
    
    eFile: DgnECHostType
    
    eLevel: DgnECHostType
    
    eModel: DgnECHostType
    
    eUnknown: DgnECHostType
    
    eView: DgnECHostType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.DgnECHostType) -> int:
        ...
    
class DgnECInstance:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
    
    def Delete(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceStatus:
        """
        If supported, delete the instance from the design file.
        """
        ...
    
    def DeleteAndIgnoreOwnership(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceStatus:
        """
        If supported, delete the instance from the design file but do not
        delete any Host Element.
        """
        ...
    
    @property
    def DgnECInstanceEnabler(arg0: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceEnabler:
        ...
    
    @property
    def DgnModelRef(arg0: MSPyECObjects.DgnECInstance) -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetAsElementInstance(self: MSPyECObjects.DgnECInstance) -> MSPyDgnPlatform.DgnElementECInstance:
        """
        To avoid expensive dynamic casting use this method to see if the
        instance is an instance associated with a specific Element as opposed
        to a Model or File.
        """
        ...
    
    def GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def GetDgnECInstanceEnabler(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceEnabler:
        """
        Get the enabler used to create the instance
        """
        ...
    
    def GetDgnModelRef(self: MSPyECObjects.DgnECInstance) -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    def GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetHostType(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECHostType:
        """
        Get the hosttype in which this instance is persisted.
        """
        ...
    
    def GetInstanceHost(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceHost:
        """
        Returns the object which hosts this ECInstance. The returned
        DgnECInstanceHost does not own the host object - it remains valid only
        so long as this DgnECInstance does.
        """
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
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueAsString(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValueAsString(self: MSPyECObjects.DgnECInstance, strVal: MSPyBentley.WString, accessString: str, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Get the value of a property as a string. An IDgnECTypeAdapter is used
        to convert value to string.
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param accessString:
        The name of the property to set the value of
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        
        2. GetValueAsString(self: MSPyECObjects.DgnECInstance, strVal: MSPyBentley.WString, propertyIndex: int, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Get the value of a property as a string. An IDgnECTypeAdapter is used
        to convert value to string.
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param accessString:
        The name of the property to set the value of
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def HostType(arg0: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECHostType:
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
        Overloaded function.
        
        1. InsertArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        
        2. InsertArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def InstanceHost(arg0: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceHost:
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
    
    def ScheduleDelete(self: MSPyECObjects.DgnECInstance, element: MSPyDgnPlatform.EditElementHandle) -> MSPyECObjects.DgnECInstanceStatus:
        """
        If supported, schedule the delete of the instance from the element.
        The instance is removed when the element is written.
        
        :param element:
        Element that serves as a host for the instance.
        """
        ...
    
    def ScheduleWriteChanges(self: MSPyECObjects.DgnECInstance, eeh: MSPyDgnPlatform.EditElementHandle) -> int:
        """
        Schedule to write any in-memory modifications when its associated
        element is written.
        
        :param eeh:
        Element that will host the instance.
        """
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetReadOnly(self: MSPyECObjects.DgnECInstance, isReadonly: bool) -> None:
        """
        Set Instance ReadOnly setting. May be ignored if implementation does
        not support setting read-only flag.
        
        :param isReadOnly:
        Read-only flag
        """
        ...
    
    def SetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueAsString(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValueAsString(self: MSPyECObjects.DgnECInstance, accessString: str, strVal: str, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Set the value of a property as a string. An IDgnECTypeAdapter is used
        to convert string to value.
        
        :param accessString:
        The name of the property to set the value of
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        
        2. SetValueAsString(self: MSPyECObjects.DgnECInstance, propertyIndex: int, strVal: str, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Set the value of a property as a string. An IDgnECTypeAdapter is used
        to convert string to value.
        
        :param accessString:
        The name of the property to set the value of
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString:
        ...
    
    def WriteChanges(self: MSPyECObjects.DgnECInstance) -> int:
        """
        Write any in-memory modifications made to the instance to the design
        file.
        """
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
    
class DgnECInstanceCreateContext:
    """
    None
    """

    def CreateReadOnly(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether create readonly ECInstance.
        """
        ...
    
    def ExposesHidden(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether " hidden " ECInstances are permitted. " Hidden "
        ECInstances include those attached to hidden models or elements, or
        otherwise explicitly flagged as " hidden ".
        """
        ...
    
    def ExposesHistorical(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether the " historical " properties of an object are returned.
        Chiefly used for Design History.
        """
        ...
    
    def GetSelectedProperties(self: MSPyECObjects.DgnECInstanceCreateContext) -> MSPyECObjects.SelectedProperties:
        """
        Returns the set of properties which will be selected in the
        DgnECInstance
        """
        ...
    
    def HasPathBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether the instance's ID will include a unique identifier for
        the containing DgnFile.
        """
        ...
    
    def HasQualifiedPepBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether an element-hosted instance's ID will include a
        qualified PersistentElementPath identifier
        """
        ...
    
    @property
    def SelectedProperties(arg0: MSPyECObjects.DgnECInstanceCreateContext) -> MSPyECObjects.SelectedProperties:
        ...
    @SelectedProperties.setter
    def SelectedProperties(arg0: MSPyECObjects.DgnECInstanceCreateContext, arg1: MSPyECObjects.SelectedProperties) -> None:
        ...
    
    def SetCreateReadOnly(self: MSPyECObjects.DgnECInstanceCreateOptions, readonly: bool) -> None:
        """
        Sets whether create readonly ECInstance.
        """
        ...
    
    def SetExposesHidden(self: MSPyECObjects.DgnECInstanceCreateOptions, exposes: bool) -> None:
        """
        Sets whether " hidden " ECInstances are permitted. " Hidden " ECInstances
        include those attached to hidden models or elements, or otherwise
        explicitly flagged as " hidden ".
        """
        ...
    
    def SetExposesHistorical(self: MSPyECObjects.DgnECInstanceCreateOptions, exposes: bool) -> None:
        """
        Sets whether the " historical " properties of an object are returned.
        Chiefly used for Design History.
        """
        ...
    
    def SetPathBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions, pathBased: bool) -> None:
        """
        Sets whether the instance's ID will include a unique identifier for
        the containing DgnFile.
        """
        ...
    
    def SetQualifiedPepBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions, qulified: bool) -> None:
        """
        Sets whether an element-hosted instance's ID will include a qualified
        PersistentElementPath identifier
        """
        ...
    
    def SetSelectedProperties(self: MSPyECObjects.DgnECInstanceCreateContext, selectedProperties: MSPyECObjects.SelectedProperties) -> None:
        """
        Returns the set of properties which will be selected in the
        DgnECInstance
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECInstanceCreateContext, selectedProperties: MSPyECObjects.SelectedProperties = None, options: MSPyECObjects.DgnECInstanceCreateOptions = <MSPyECObjects.DgnECInstanceCreateOptions object at 0x0000027C27AD12F0>) -> None
        
        2. __init__(self: MSPyECObjects.DgnECInstanceCreateContext, options: MSPyECObjects.DgnECInstanceCreateOptions = <MSPyECObjects.DgnECInstanceCreateOptions object at 0x0000027C27A8C1F0>) -> None
        """
        ...
    
class DgnECInstanceCreateOptions:
    """
    None
    """

    def CreateReadOnly(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether create readonly ECInstance.
        """
        ...
    
    def ExposesHidden(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether " hidden " ECInstances are permitted. " Hidden "
        ECInstances include those attached to hidden models or elements, or
        otherwise explicitly flagged as " hidden ".
        """
        ...
    
    def ExposesHistorical(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether the " historical " properties of an object are returned.
        Chiefly used for Design History.
        """
        ...
    
    def HasPathBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether the instance's ID will include a unique identifier for
        the containing DgnFile.
        """
        ...
    
    def HasQualifiedPepBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions) -> bool:
        """
        Returns whether an element-hosted instance's ID will include a
        qualified PersistentElementPath identifier
        """
        ...
    
    def SetCreateReadOnly(self: MSPyECObjects.DgnECInstanceCreateOptions, readonly: bool) -> None:
        """
        Sets whether create readonly ECInstance.
        """
        ...
    
    def SetExposesHidden(self: MSPyECObjects.DgnECInstanceCreateOptions, exposes: bool) -> None:
        """
        Sets whether " hidden " ECInstances are permitted. " Hidden " ECInstances
        include those attached to hidden models or elements, or otherwise
        explicitly flagged as " hidden ".
        """
        ...
    
    def SetExposesHistorical(self: MSPyECObjects.DgnECInstanceCreateOptions, exposes: bool) -> None:
        """
        Sets whether the " historical " properties of an object are returned.
        Chiefly used for Design History.
        """
        ...
    
    def SetPathBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions, pathBased: bool) -> None:
        """
        Sets whether the instance's ID will include a unique identifier for
        the containing DgnFile.
        """
        ...
    
    def SetQualifiedPepBasedId(self: MSPyECObjects.DgnECInstanceCreateOptions, qulified: bool) -> None:
        """
        Sets whether an element-hosted instance's ID will include a qualified
        PersistentElementPath identifier
        """
        ...
    
    def __init__(self: MSPyECObjects.DgnECInstanceCreateOptions, pathBasedId: bool = False, qualifiedPepBasedId: bool = False) -> None:
        ...
    
class DgnECInstanceEnabler:
    """
    None
    """

    @property
    def Class(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    def CreateInstanceAsElement(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, modelRef: MSPyDgnPlatform.DgnModelRef, instanceOwnsElement: bool = False) -> tuple:
        """
        Creates an DgnElementECInstance as a new element. You must call
        SupportsCreateInstanceAsElement to determine if it is safe to call
        this on a given DgnECInstanceEnabler.
        
        
        :param wipInstance:
        A ECN.StandaloneECInstance that was probably obtained from
        #GetSharedWipInstance It should have been intialized with all of
        the values to allow efficient one-shot creation of the new
        persistent DgnElementECInstance.
        
        :param modelRef:
        The modelRef to be used by the returned DgnElementECInstance.
        Typically you should pass *elementRef.GetDgnModelP(). The
        exception is if you will be using the returned
        DgnElementECInstance to create an ECRelationship to another
        DgnElementECInstance that does not reside in the same DgnModel. In
        that case, you must pass the DgnModelRef of the particular
        attachment that will be used by that ECRelationship. See docs for
        DgnECManager.CreateRelationship.
        
        :param instanceOwnsElement:
        If true, when the instance is deleted the element will be deleted
        as well.
        
        See also:
        GetSharedWipInstance();
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        dgnecInstance.
        """
        ...
    
    def CreateInstanceOnElement(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateInstanceOnElement(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, eh: MSPyDgnPlatform.EditElementHandle, instanceOwnsElement: bool = False) -> tuple
        
        Creates an DgnElementECInstance on an persistent element. The instance
        will be written to the element immediately. You must call
        SupportsCreateInstanceOnElement to determine if it is safe to call
        this on a given DgnECInstanceEnabler.
        
        :param wipInstance:
        A ECN.StandaloneECInstance that was probably obtained from
        #GetSharedWipInstance. It should have been intialized with all of
        the values
        
        :param eh:
        ElementHandle containing the ElementRef and DgnModelRef to be used
        by the returned DgnElementECInstance. The ElementHandle must
        contain a valid ElementRef. Typically the DgnModelRef should come
        from the ElementRef. The exception is if you will be using the
        returned DgnElementECInstance to create an ECRelationship to
        another DgnElementECInstance that does not reside in the same
        DgnModel. In that case, you must pass the DgnModelRef of the
        particular attachment that will be used by that ECRelationship.
        See docs for DgnECManager.CreateRelationship.
        
        :param instanceOwnsElement:
        If true, when the instance is deleted the element will be deleted
        as well.
        
        See also:
        GetSharedWipInstance();
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        dgnecInstance.
        
        
        
        2. CreateInstanceOnElement(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, eh: MSPyDgnPlatform.EditElementHandle, intendedLocalId: int, instanceOwnsElement: bool = False) -> tuple
        
        Creates an DgnElementECInstance on an persistent element. The instance
        will be written to the element immediately. You must call
        SupportsCreateInstanceOnElement to determine if it is safe to call
        this on a given DgnECInstanceEnabler.
        
        :param wipInstance:
        A ECN.StandaloneECInstance that was probably obtained from
        #GetSharedWipInstance. It should have been intialized with all of
        the values
        
        :param eh:
        ElementHandle containing the ElementRef and DgnModelRef to be used
        by the returned DgnElementECInstance. The ElementHandle must
        contain a valid ElementRef. Typically the DgnModelRef should come
        from the ElementRef. The exception is if you will be using the
        returned DgnElementECInstance to create an ECRelationship to
        another DgnElementECInstance that does not reside in the same
        DgnModel. In that case, you must pass the DgnModelRef of the
        particular attachment that will be used by that ECRelationship.
        See docs for DgnECManager.CreateRelationship.
        
        :param instanceOwnsElement:
        If true, when the instance is deleted the element will be deleted
        as well.
        
        See also:
        GetSharedWipInstance();
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        dgnecInstance.
        """
        ...
    
    def CreateInstanceOnFile(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, dgnFile: MSPyDgnPlatform.DgnFile) -> tuple:
        """
        Create an instance which is stored on the DgnFile.
        
        
        :param wipInstance:
        A template instance from which to get properties of the new
        instance.
        
        :param dgnfile:
        The DgnFile on which to store the instance
        
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        dgnecInstance.
        """
        ...
    
    def CreateInstanceOnHost(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateInstanceOnHost(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, host: MSPyECObjects.DgnECInstanceHost, intendedLocalId: int, createContext: MSPyECObjects.DgnECInstanceCreateContext = <MSPyECObjects.DgnECInstanceCreateContext object at 0x0000027C27AA6130>, instanceOwnsHost: bool = False) -> tuple
        
        Create an instance which is stored on the specified host.
        
        :param wipInstance:
        A standalone instance from to get properties of the new instance.
        
        :param host:
        The host on which to create the ECInstance
        
        :param intendedLocalId:
        If INVALID_XATTR_ID, then use the next available Id, Otherwise use
        the provided ID and error if not available.
        
        :param createContext:
        Context with which to create the ECInstance
        
        :param instanceOwnsHost:
        (if supported) indicates that if the ECInstance is later deleted,
        the host on which it resides will be deleted as well.
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        dgnecInstance.
        
        
        
        2. CreateInstanceOnHost(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, host: MSPyECObjects.DgnECInstanceHost, createContext: MSPyECObjects.DgnECInstanceCreateContext = <MSPyECObjects.DgnECInstanceCreateContext object at 0x0000027C27AD1670>, instanceOwnsHost: bool = False) -> tuple
        
        Create an instance which is stored on the specified host.
        
        :param wipInstance:
        A standalone instance from to get properties of the new instance.
        
        :param host:
        The host on which to create the ECInstance
        
        :param intendedLocalId:
        If INVALID_XATTR_ID, then use the next available Id, Otherwise use
        the provided ID and error if not available.
        
        :param createContext:
        Context with which to create the ECInstance
        
        :param instanceOwnsHost:
        (if supported) indicates that if the ECInstance is later deleted,
        the host on which it resides will be deleted as well.
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        dgnecInstance.
        """
        ...
    
    def CreateInstanceOnLinkNode(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, linkNode: MSPyDgnPlatform.DgnLinkTreeNode) -> tuple:
        """
        Create an instance which is stored on a DgnLinkTreeNode (ex:Folders
        and Links in a Link Set or Sheet Index)
        
        :param wipInstance:
        A standalone instance from to get properties of the new instance.
        
        :param linknode:
        The linknode on which to store
        
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        dgnecInstance.
        """
        ...
    
    def CreateInstanceOnModel(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, dgnModel: MSPyDgnPlatform.DgnModel) -> tuple:
        """
        Create an instance which is stored on the model or attachment.
        
        
        :param wipInstance:
        A standalone instance from to get properties of the new instance.
        
        :param model:
        The dgnmodel on which to store
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        dgnecInstance.
        """
        ...
    
    def GetAccessString(self: MSPyECObjects.ECEnabler, propertyIndex: int) -> tuple:
        ...
    
    def GetClass(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.ECClass:
        ...
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> ECN.StandaloneECEnabler:
        ...
    
    def GetFirstPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int) -> int:
        ...
    
    def GetName(self: MSPyECObjects.ECEnabler) -> str:
        ...
    
    def GetNextPropertyIndex(self: MSPyECObjects.ECEnabler, parentIndex: int, inputIndex: int) -> int:
        ...
    
    def GetParentPropertyIndex(self: MSPyECObjects.ECEnabler, childIndex: int) -> int:
        ...
    
    def GetPrivateWipInstance(self: MSPyECObjects.DgnECInstanceEnabler) -> MSPyECObjects.StandaloneECInstance:
        """
        Gets a private StandaloneECInstance for use with this
        DgnECInstanceEnabler's CreateInstance* methods.
        
        Remark:
        s The instance is setup (memory allocated) for efficient usage
        with those methods. The property values in the returned instance
        will all be null. It is private and you control its lifetime, so
        you can have many of them " in play " at once. It is typcially used
        in scenarios when populating struct array values on a shared wip
        instance, before actually creating the primary instance on an
        element. Each such struct element in the array value must exist in
        memory independently and therefore can not use a shared wip
        instance. In cases where you are creating primary ECInstances (not
        struct values) you normally want to use GetSharedWipInstance for
        better performance.
        """
        ...
    
    def GetPropertyIndex(self: MSPyECObjects.ECEnabler, accessString: str) -> tuple:
        ...
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentleyGeom.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetSharedWipInstance(self: MSPyECObjects.DgnECInstanceEnabler) -> MSPyECObjects.StandaloneECInstance:
        """
        Gets a StandaloneECInstance to be used as a template when creating new
        persistent ECInstances with one of this DgnECInstanceEnabler's
        CreateInstance* methods. The instance is setup (memory allocated) for
        efficient usage with those methods. This technique avoids initially
        writing an empty ECInstance and then making subsequent modifications
        (avoiding overhead in undo buffer, design history, etc.) The property
        values in the returned instance will initially all be null. It is
        shared to avoid repeated mallocs and frees when creating many
        DgnElementECInstances, forcing you to initialize and create
        DgnElementECInstances one-at-a-time. You should never delete/free the
        WIP IECInstance. It's values will be cleared the next time it is
        requested.
        
        
        See also:
        GetPrivateWipInstance
        """
        ...
    
    def GetStandaloneECInstanceEnabler(self: MSPyECObjects.DgnECInstanceEnabler) -> MSPyECObjects.StandaloneECEnabler:
        """
        Used to create StandaloneECInstances that use the same enabler as the
        " WIP " ECInstances (and are thus may be used with
        CreateInstanceOnElement and similar methods)
        """
        ...
    
    def GetStandaloneEnablerLocater(self: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def HasChildProperties(self: MSPyECObjects.ECEnabler, parentIndex: int) -> bool:
        ...
    
    def IsEnablerValidForDgnFile(self: MSPyECObjects.DgnECInstanceEnabler, dgnFile: MSPyDgnPlatform.DgnFile) -> bool:
        """
        Returns true if the enabler supports writing instances to DgnFile.
        
        :param dgnFile:
        The destination DGN file for the instance
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.ECEnabler) -> str:
        ...
    
    @property
    def PrivateWipInstance(arg0: MSPyECObjects.DgnECInstanceEnabler) -> MSPyECObjects.StandaloneECInstance:
        ...
    
    def ScheduleInstanceOnElement(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, eh: MSPyDgnPlatform.EditElementHandle, instanceOwnsElement: bool = False) -> tuple:
        """
        Schedules the creation an DgnElementECInstance on an existing element.
        The instance will be persisted when the EditElementHandle is written.
        You must call SupportsCreateInstanceOnElement to determine if it is
        safe to call this on a given DgnECInstanceEnabler.
        
        
        :param wipInstance:
        An ECN.StandaloneECInstance that was probably obtained from
        #GetSharedWipInstance It should have been intialized with all of
        the values
        
        :param eh:
        The element on which to schedule the newly-created
        DgnElementECInstance
        
        :param instanceOwnsElement:
        If true, when the instance is deleted the element will be deleted
        as well.
        
        See also:
        GetSharedWipInstance();
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        dgnecInstance.
        """
        ...
    
    def ScheduleReplaceInstanceOnElement(self: MSPyECObjects.DgnECInstanceEnabler, wipInstance: MSPyECObjects.IECInstance, modelRef: MSPyDgnPlatform.DgnModelRef, eh: MSPyDgnPlatform.EditElementHandle, localId: int) -> tuple:
        """
        Schedules the replacement of an existing instance associated with an
        element that is identified by the localid. The element is identified
        by an EditElementHandle.
        
        
        :param wipInstance:
        A ECN.StandaloneECInstance that was probably a " shared " instance
        with its memory shared with a managed ECDInstance.
        
        :param modelRef:
        The modelRef to be used by the returned DgnECInstance. Typically
        you should pass *elementRef.GetDgnModelP(). The exception is if
        you will be using the returned DgnECInstance to create an
        ECRelationship to another DgnECInstance that does not reside in
        the same DgnModel. In that case, you must pass the DgnModelRef of
        the particular attachment that will be used by that
        ECRelationship. See docs for DgnECManager.CreateRelationship.
        
        :param eh:
        The element on which to persist the newly-created DgnECInstance
        
        :param localId:
        Identifies the existing instance to replace. Typically the
        xattribute id.
        
        Returns (Tuple,0):
        retVal.
        
        Returns (Tuple,1):
        dgnecInstance.
        """
        ...
    
    @property
    def SharedWipInstance(arg0: MSPyECObjects.DgnECInstanceEnabler) -> MSPyECObjects.StandaloneECInstance:
        ...
    
    @property
    def StandaloneECInstanceEnabler(arg0: MSPyECObjects.DgnECInstanceEnabler) -> MSPyECObjects.StandaloneECEnabler:
        ...
    
    @property
    def StandaloneEnablerLocater(arg0: MSPyECObjects.ECEnabler) -> MSPyECObjects.IStandaloneEnablerLocater:
        ...
    
    def SupportsCreateInstanceAsElement(self: MSPyECObjects.DgnECInstanceEnabler) -> bool:
        """
        Return true if the enabler supports creating an instance on a new
        element.
        """
        ...
    
    def SupportsCreateInstanceOnElement(self: MSPyECObjects.DgnECInstanceEnabler) -> bool:
        """
        Return true if the enabler supports creating instances on a Dgn
        element.
        """
        ...
    
    def SupportsCreateInstanceOnHost(self: MSPyECObjects.DgnECInstanceEnabler, hostType: MSPyECObjects.DgnECHostType) -> bool:
        """
        Check whether this enabler supports creating instances which are
        stored on objects of the specified host type
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DgnECInstanceHost:
    """
    None
    """

    @property
    def Attachment(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnAttachment:
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def EditElementHandle(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.EditElementHandle:
        ...
    
    @property
    def ElementHandle(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetAttachment(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnAttachment:
        ...
    
    def GetDgnFile(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnFile:
        ...
    
    def GetEditElementHandle(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.EditElementHandle:
        ...
    
    def GetElementHandle(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    def GetLevel(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.LevelHandle:
        ...
    
    def GetLinkNode(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnLinkTreeNode:
        ...
    
    def GetModel(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnModel:
        ...
    
    def GetModelItem(self: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.ModelIndexItem:
        ...
    
    def GetType(self: MSPyECObjects.DgnECInstanceHost) -> MSPyECObjects.DgnECHostType:
        ...
    
    def IsAttachment(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    def IsDesignLink(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    def IsDgnFile(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    def IsElement(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    def IsLevel(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    def IsModel(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    def IsView(self: MSPyECObjects.DgnECInstanceHost) -> bool:
        ...
    
    @property
    def Level(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.LevelHandle:
        ...
    
    @property
    def LinkNode(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnLinkTreeNode:
        ...
    
    @property
    def Model(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.DgnModel:
        ...
    
    @property
    def ModelItem(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.ModelIndexItem:
        ...
    
    @property
    def Type(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyECObjects.DgnECHostType:
        ...
    
    @property
    def View(arg0: MSPyECObjects.DgnECInstanceHost) -> MSPyDgnPlatform.ViewGroup:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECInstanceHost) -> None
        
        2. __init__(self: MSPyECObjects.DgnECInstanceHost, eh: MSPyDgnPlatform.ElementHandle) -> None
        
        3. __init__(self: MSPyECObjects.DgnECInstanceHost, eeh: MSPyDgnPlatform.EditElementHandle) -> None
        
        4. __init__(self: MSPyECObjects.DgnECInstanceHost, model: MSPyDgnPlatform.DgnModel) -> None
        
        5. __init__(self: MSPyECObjects.DgnECInstanceHost, dgnFile: MSPyDgnPlatform.DgnFile, modelId: int) -> None
        
        6. __init__(self: MSPyECObjects.DgnECInstanceHost, dgnFile: MSPyDgnPlatform.DgnFile) -> None
        
        7. __init__(self: MSPyECObjects.DgnECInstanceHost, attachment: MSPyDgnPlatform.DgnAttachment) -> None
        
        8. __init__(self: MSPyECObjects.DgnECInstanceHost, modelRef: MSPyDgnPlatform.DgnModelRef, levelId: int) -> None
        
        9. __init__(self: MSPyECObjects.DgnECInstanceHost, viewGroup: MSPyDgnPlatform.ViewGroup, viewIndex: int) -> None
        
        10. __init__(self: MSPyECObjects.DgnECInstanceHost, linkNode: MSPyDgnPlatform.DgnLinkTreeNode) -> None
        """
        ...
    
class DgnECInstanceIterable:
    """
    None
    """

    def IsNull(self: MSPyECObjects.DgnECInstanceIterable) -> bool:
        """
        Utility method to check whether the collection is initialized
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    def empty(self: MSPyECObjects.DgnECInstanceIterable) -> bool:
        """
        Utility method to check whether the current collection has any
        instances
        """
        ...
    
class DgnECInstanceIterableArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECInstanceIterableArray) -> None
        
        2. __init__(self: MSPyECObjects.DgnECInstanceIterableArray, arg0: MSPyECObjects.DgnECInstanceIterableArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnECInstanceIterableArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnECInstanceIterableArray, x: MSPyECObjects.DgnECInstanceIterable) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnECInstanceIterableArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnECInstanceIterableArray, L: MSPyECObjects.DgnECInstanceIterableArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnECInstanceIterableArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnECInstanceIterableArray, i: int, x: MSPyECObjects.DgnECInstanceIterable) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnECInstanceIterableArray) -> MSPyECObjects.DgnECInstanceIterable
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnECInstanceIterableArray, i: int) -> MSPyECObjects.DgnECInstanceIterable
        
        Remove and return the item at index ``i``
        """
        ...
    
class DgnECInstanceStatus:
    """
    Members:
    
    eDGNECINSTANCESTATUS_Success
    
    eDGNECINSTANCESTATUS_InstanceIsStale
    
    eDGNECINSTANCESTATUS_InstanceIsDeletedOrUndone
    
    eDGNECINSTANCESTATUS_InvalidElementRef
    
    eDGNECINSTANCESTATUS_InstanceIsAlreadyAsleep
    
    eDGNECINSTANCESTATUS_IncompatibleWipInstance
    
    eDGNECINSTANCESTATUS_UnableToAddInstance
    
    eDGNECINSTANCESTATUS_NoInstanceFound
    
    eDGNECINSTANCESTATUS_InvalidInstance
    
    eDGNECINSTANCESTATUS_UnableToUpdateInstance
    
    eDGNECINSTANCESTATUS_XAttributeHasBeenRemoved
    
    eDGNECINSTANCESTATUS_ClassLayoutNotStored
    
    eDGNECINSTANCESTATUS_RelationshipInstanceNotCreated
    
    eDGNECINSTANCESTATUS_EnablerNotValidForFile
    
    eDGNECINSTANCESTATUS_DuplicateRelationshipFound
    
    eDGNECINSTANCESTATUS_RequiresSingleEndedRelationshipClass
    
    eDGNECINSTANCESTATUS_PropertyNotFound
    
    eDGNECINSTANCESTATUS_Error
    """

    def __init__(self: MSPyECObjects.DgnECInstanceStatus, value: int) -> None:
        ...
    
    eDGNECINSTANCESTATUS_ClassLayoutNotStored: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_DuplicateRelationshipFound: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_EnablerNotValidForFile: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_Error: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_IncompatibleWipInstance: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_InstanceIsAlreadyAsleep: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_InstanceIsDeletedOrUndone: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_InstanceIsStale: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_InvalidElementRef: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_InvalidInstance: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_NoInstanceFound: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_PropertyNotFound: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_RelationshipInstanceNotCreated: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_RequiresSingleEndedRelationshipClass: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_Success: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_UnableToAddInstance: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_UnableToUpdateInstance: DgnECInstanceStatus
    
    eDGNECINSTANCESTATUS_XAttributeHasBeenRemoved: DgnECInstanceStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.DgnECInstanceStatus) -> int:
        ...
    
class DgnECInstanceVector:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECInstanceVector) -> None
        
        2. __init__(self: MSPyECObjects.DgnECInstanceVector, arg0: MSPyECObjects.DgnECInstanceVector) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnECInstanceVector, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnECInstanceVector, x: MSPyECObjects.DgnECInstance) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnECInstanceVector) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.DgnECInstanceVector, x: MSPyECObjects.DgnECInstance) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnECInstanceVector, L: MSPyECObjects.DgnECInstanceVector) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnECInstanceVector, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnECInstanceVector, i: int, x: MSPyECObjects.DgnECInstance) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnECInstanceVector) -> MSPyECObjects.DgnECInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnECInstanceVector, i: int) -> MSPyECObjects.DgnECInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.DgnECInstanceVector, x: MSPyECObjects.DgnECInstance) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
DgnECProviderId_Attachment: int

DgnECProviderId_ECXAttributes: int

DgnECProviderId_ECXData: int

DgnECProviderId_Element: int

DgnECProviderId_File: int

DgnECProviderId_FileExtrinsic: int

DgnECProviderId_Invalid: int

DgnECProviderId_Level: int

DgnECProviderId_Link: int

DgnECProviderId_Model: int

DgnECProviderId_ModelExtrinsic: int

DgnECProviderId_View: int

class DgnECRelationshipEnabler:
    """
    None
    """

    def CreateRelationship(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateRelationship(self: MSPyECObjects.DgnECRelationshipEnabler, wipRelationship: MSPyECObjects.StandaloneECRelationshipInstance, instanceA: MSPyECObjects.DgnElementECInstance, instanceB: MSPyECObjects.DgnElementECInstance, hostModelRef: MSPyDgnPlatform.DgnModelRef = None, hostElementRef: MSPyDgnPlatform.ElementRefBase = None) -> tuple
        
        Method to create a relationship between two DgnElementECInstance.
        
        :param wipRelationship:
        A reference to a StandaloneInstance that will contain properties
        of the relationship instance.
        
        :param instanceA:
        DgnElementECInstance to be related to instanceB.
        
        :param instanceB:
        DgnElementECInstance to be related to instanceA.
        
        :param hostModelRef:
        Optional modelRef of element to receive relationship (may be
        different then either source or target host element). For future
        use.
        
        :param hostElementRef:
        Optional element to receive relationship (may be different then
        either source or target host element). For future use.
        
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        createdRelationship.
        
        
        
        
        
        2. CreateRelationship(self: MSPyECObjects.DgnECRelationshipEnabler, instanceA: MSPyECObjects.DgnElementECInstance, instanceB: MSPyECObjects.DgnElementECInstance, hostModelRef: MSPyDgnPlatform.DgnModelRef = None, hostElementRef: MSPyDgnPlatform.ElementRefBase = None) -> tuple
        
        Method to create a relationship between two DgnElementECInstance.
        
        :param wipRelationship:
        A reference to a StandaloneInstance that will contain properties
        of the relationship instance.
        
        :param instanceA:
        DgnElementECInstance to be related to instanceB.
        
        :param instanceB:
        DgnElementECInstance to be related to instanceA.
        
        :param hostModelRef:
        Optional modelRef of element to receive relationship (may be
        different then either source or target host element). For future
        use.
        
        :param hostElementRef:
        Optional element to receive relationship (may be different then
        either source or target host element). For future use.
        
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple,1):
        createdRelationship.
        """
        ...
    
    def CreateWipRelationshipInstance(self: MSPyECObjects.IECRelationshipEnabler) -> ECN.StandaloneECRelationshipInstance:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.IECRelationshipEnabler) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    def GetSharedStandaloneWipInstance(self: MSPyECObjects.DgnECRelationshipEnabler) -> MSPyECObjects.StandaloneECRelationshipInstance:
        """
        Get a Shared WIP instance that can be passed CreateRelationship to
        specify properties to be set in the relationship instance.
        """
        ...
    
    @property
    def SharedStandaloneWipInstance(arg0: MSPyECObjects.DgnECRelationshipEnabler) -> MSPyECObjects.StandaloneECRelationshipInstance:
        ...
    
    def SupportsRelationshipProperties(self: MSPyECObjects.DgnECRelationshipEnabler) -> bool:
        """
        Returns true if the enabler supports relationship properties.
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DgnECRelationshipInfo:
    """
    None
    """

    def GetRelationshipClass(self: MSPyECObjects.DgnECRelationshipInfo) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    @property
    def RelationshipClass(arg0: MSPyECObjects.DgnECRelationshipInfo) -> MSPyECObjects.ECRelationshipClass:
        ...
    
    def SetSupportsBackward(self: MSPyECObjects.DgnECRelationshipInfo, support: bool) -> None:
        ...
    
    def SetSupportsForward(self: MSPyECObjects.DgnECRelationshipInfo, support: bool) -> None:
        ...
    
    def SupportsBackward(self: MSPyECObjects.DgnECRelationshipInfo) -> bool:
        ...
    
    def SupportsForward(self: MSPyECObjects.DgnECRelationshipInfo) -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class DgnECRelationshipInfoArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECRelationshipInfoArray) -> None
        
        2. __init__(self: MSPyECObjects.DgnECRelationshipInfoArray, arg0: MSPyECObjects.DgnECRelationshipInfoArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnECRelationshipInfoArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnECRelationshipInfoArray, x: MSPyECObjects.DgnECRelationshipInfo) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnECRelationshipInfoArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.DgnECRelationshipInfoArray, x: MSPyECObjects.DgnECRelationshipInfo) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnECRelationshipInfoArray, L: MSPyECObjects.DgnECRelationshipInfoArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnECRelationshipInfoArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnECRelationshipInfoArray, i: int, x: MSPyECObjects.DgnECRelationshipInfo) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnECRelationshipInfoArray) -> MSPyECObjects.DgnECRelationshipInfo
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnECRelationshipInfoArray, i: int) -> MSPyECObjects.DgnECRelationshipInfo
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.DgnECRelationshipInfoArray, x: MSPyECObjects.DgnECRelationshipInfo) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class DgnECRelationshipIterable:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    def empty(self: MSPyECObjects.DgnECRelationshipIterable) -> bool:
        ...
    
class DgnECRelationshipIterableArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECRelationshipIterableArray) -> None
        
        2. __init__(self: MSPyECObjects.DgnECRelationshipIterableArray, arg0: MSPyECObjects.DgnECRelationshipIterableArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnECRelationshipIterableArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnECRelationshipIterableArray, x: MSPyECObjects.DgnECRelationshipIterable) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnECRelationshipIterableArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnECRelationshipIterableArray, L: MSPyECObjects.DgnECRelationshipIterableArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnECRelationshipIterableArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnECRelationshipIterableArray, i: int, x: MSPyECObjects.DgnECRelationshipIterable) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnECRelationshipIterableArray) -> MSPyECObjects.DgnECRelationshipIterable
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnECRelationshipIterableArray, i: int) -> MSPyECObjects.DgnECRelationshipIterable
        
        Remove and return the item at index ``i``
        """
        ...
    
class DgnECUnit:
    """
    None
    """

    @property
    def ECUnitName(arg0: MSPyECObjects.DgnECUnit) -> str:
        ...
    
    @staticmethod
    def FromID(id: str) -> MSPyECObjects.DgnECUnit:
        """
        Initialize from invariant ID.
        
        :param id:
        Invariant ID string
        
        :returns:
        A DgnECUnit corresponding to the invariant ID. Does not validate
        ECUnit names against the schema.
        """
        ...
    
    def GetECUnitName(self: MSPyECObjects.DgnECUnit) -> str:
        """
        :returns:
        the name of the ECUnit, or NULL if not an ECUnit
        """
        ...
    
    def GetID(self: MSPyECObjects.DgnECUnit) -> str:
        """
        :returns:
        the invariant ID of this unit.
        """
        ...
    
    def GetWorkingUnit(self: MSPyECObjects.DgnECUnit) -> MSPyECObjects.DgnECUnit.WorkingUnit:
        """
        :returns:
        the working unit associated with this DgnECUnit
        """
        ...
    
    @property
    def ID(arg0: MSPyECObjects.DgnECUnit) -> str:
        ...
    
    def IsECUnit(self: MSPyECObjects.DgnECUnit) -> bool:
        """
        :returns:
        true if this unit represents an ECUnit. Does not validate the unit
        name actually exists in the standard units schema
        """
        ...
    
    def IsSpecified(self: MSPyECObjects.DgnECUnit) -> bool:
        """
        :returns:
        true if this unit represents an ECUnit or a Working Unit
        """
        ...
    
    def IsWorkingUnit(self: MSPyECObjects.DgnECUnit) -> bool:
        """
        :returns:
        true if this unit specifies a working unit
        """
        ...
    
    @property
    def WorkingUnit(arg0: MSPyECObjects.DgnECUnit) -> MSPyECObjects.DgnECUnit.WorkingUnit:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnECUnit, workingUnit: MSPyECObjects.DgnECUnit.WorkingUnit = <WorkingUnit.eUnspecified: 255>) -> None
        
        2. __init__(self: MSPyECObjects.DgnECUnit, standardECUnitName: str) -> None
        """
        ...
    
    eAngle: WorkingUnit
    
    eArea: WorkingUnit
    
    eDistance: WorkingUnit
    
    eUnspecified: WorkingUnit
    
    eVolume: WorkingUnit
    
class DgnElementECInstance:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
    
    def Delete(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceStatus:
        """
        If supported, delete the instance from the design file.
        """
        ...
    
    def DeleteAndIgnoreOwnership(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceStatus:
        """
        If supported, delete the instance from the design file but do not
        delete any Host Element.
        """
        ...
    
    @property
    def DgnECInstanceEnabler(arg0: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceEnabler:
        ...
    
    @property
    def DgnModelRef(arg0: MSPyECObjects.DgnECInstance) -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    @property
    def ECDBuffer(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    @property
    def ElementHandle(arg0: MSPyECObjects.DgnElementECInstance) -> MSPyDgnPlatform.ElementHandle:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.DgnElementECInstance) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @property
    def Enabler(arg0: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetAsElementInstance(self: MSPyECObjects.DgnECInstance) -> MSPyDgnPlatform.DgnElementECInstance:
        """
        To avoid expensive dynamic casting use this method to see if the
        instance is an instance associated with a specific Element as opposed
        to a Model or File.
        """
        ...
    
    def GetClass(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECClass:
        ...
    
    def GetDgnECInstanceEnabler(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceEnabler:
        """
        Get the enabler used to create the instance
        """
        ...
    
    def GetDgnModelRef(self: MSPyECObjects.DgnECInstance) -> MSPyDgnPlatform.DgnModelRef:
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def GetECDBuffer(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECDBuffer:
        ...
    
    def GetElementHandle(self: MSPyECObjects.DgnElementECInstance) -> MSPyDgnPlatform.ElementHandle:
        """
        Get the element handle where this DgnElementInstance is stored
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.DgnElementECInstance) -> MSPyDgnPlatform.ElementRefBase:
        """
        Get ElementRefP of element containing the instance, if the instance is
        stored on a persistent element.
        """
        ...
    
    def GetEnabler(self: MSPyECObjects.IECInstance) -> MSPyECObjects.ECEnabler:
        ...
    
    def GetHostType(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECHostType:
        """
        Get the hosttype in which this instance is persisted.
        """
        ...
    
    def GetInstanceHost(self: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceHost:
        """
        Returns the object which hosts this ECInstance. The returned
        DgnECInstanceHost does not own the host object - it remains valid only
        so long as this DgnECInstance does.
        """
        ...
    
    def GetInstanceId(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetInstanceIdForSerialization(self: MSPyECObjects.IECInstance) -> MSPyBentley.WString:
        ...
    
    def GetLocalId(self: MSPyECObjects.DgnElementECInstance) -> int:
        """
        Get LocalId of the instance. For XAttribute-based instances this is an
        XAttribute ID.
        """
        ...
    
    def GetModelRef(self: MSPyECObjects.DgnElementECInstance) -> MSPyDgnPlatform.DgnModelRef:
        """
        Get root DgnModelRef from which this instance was obtained. This may
        differ from the DgnModel containing the instance's element (see
        GetDgnModelP()).
        """
        ...
    
    def GetOffsetToIECInstance(self: MSPyECObjects.IECInstance) -> int:
        ...
    
    def GetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueAsString(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValueAsString(self: MSPyECObjects.DgnECInstance, strVal: MSPyBentley.WString, accessString: str, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Get the value of a property as a string. An IDgnECTypeAdapter is used
        to convert value to string.
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param accessString:
        The name of the property to set the value of
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        
        2. GetValueAsString(self: MSPyECObjects.DgnECInstance, strVal: MSPyBentley.WString, propertyIndex: int, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Get the value of a property as a string. An IDgnECTypeAdapter is used
        to convert value to string.
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param accessString:
        The name of the property to set the value of
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def HostType(arg0: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECHostType:
        ...
    
    def InsertArrayElements(*args, **kwargs):
        """
        Overloaded function.
        
        1. InsertArrayElements(self: MSPyECObjects.IECInstance, accessString: str, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        
        2. InsertArrayElements(self: MSPyECObjects.IECInstance, propertyIndex: int, index: int, size: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    @property
    def InstanceHost(arg0: MSPyECObjects.DgnECInstance) -> MSPyECObjects.DgnECInstanceHost:
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
    def LocalId(arg0: MSPyECObjects.DgnElementECInstance) -> int:
        ...
    
    @property
    def ModelRef(arg0: MSPyECObjects.DgnElementECInstance) -> MSPyDgnPlatform.DgnModelRef:
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
    
    def ScheduleDelete(self: MSPyECObjects.DgnECInstance, element: MSPyDgnPlatform.EditElementHandle) -> MSPyECObjects.DgnECInstanceStatus:
        """
        If supported, schedule the delete of the instance from the element.
        The instance is removed when the element is written.
        
        :param element:
        Element that serves as a host for the instance.
        """
        ...
    
    def ScheduleWriteChanges(self: MSPyECObjects.DgnECInstance, eeh: MSPyDgnPlatform.EditElementHandle) -> int:
        """
        Schedule to write any in-memory modifications when its associated
        element is written.
        
        :param eeh:
        Element that will host the instance.
        """
        ...
    
    def SetDisplayLabel(self: MSPyECObjects.IECInstance, displayLabel: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetInstanceId(self: MSPyECObjects.IECInstance, instanceId: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetReadOnly(self: MSPyECObjects.DgnECInstance, isReadonly: bool) -> None:
        """
        Set Instance ReadOnly setting. May be ignored if implementation does
        not support setting read-only flag.
        
        :param isReadOnly:
        Read-only flag
        """
        ...
    
    def SetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueAsString(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetValueAsString(self: MSPyECObjects.DgnECInstance, accessString: str, strVal: str, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Set the value of a property as a string. An IDgnECTypeAdapter is used
        to convert string to value.
        
        :param accessString:
        The name of the property to set the value of
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        
        2. SetValueAsString(self: MSPyECObjects.DgnECInstance, propertyIndex: int, strVal: str, useArrayIndex: bool, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        Set the value of a property as a string. An IDgnECTypeAdapter is used
        to convert string to value.
        
        :param accessString:
        The name of the property to set the value of
        
        :param strVal:
        If successful, will contain the value of the property
        
        :param useArrayIndex:
        Set this to true if retrieving an entry in an array. If this is
        false arrayIndex is ignored;
        
        :param arrayIndex:
        The array index, if this is an ArrayProperty
        
        :returns:
        ECOBJECTS_STATUS_Success if successful, otherwise an error code
        indicating the failure
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def ToString(self: MSPyECObjects.IECInstance, indent: str) -> MSPyBentley.WString:
        ...
    
    def WriteChanges(self: MSPyECObjects.DgnECInstance) -> int:
        """
        Write any in-memory modifications made to the instance to the design
        file.
        """
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
    
class DgnElementECInstancePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.DgnElementECInstancePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.DgnElementECInstancePtrArray, arg0: MSPyECObjects.DgnElementECInstancePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.DgnElementECInstancePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.DgnElementECInstancePtrArray, x: MSPyECObjects.DgnElementECInstance) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.DgnElementECInstancePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.DgnElementECInstancePtrArray, x: MSPyECObjects.DgnElementECInstance) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.DgnElementECInstancePtrArray, L: MSPyECObjects.DgnElementECInstancePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.DgnElementECInstancePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.DgnElementECInstancePtrArray, i: int, x: MSPyECObjects.DgnElementECInstance) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.DgnElementECInstancePtrArray) -> MSPyECObjects.DgnElementECInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.DgnElementECInstancePtrArray, i: int) -> MSPyECObjects.DgnElementECInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.DgnElementECInstancePtrArray, x: MSPyECObjects.DgnElementECInstance) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
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
    def DefaultStandaloneEnabler(arg0: MSPyECObjects.ECClass) -> ECN.StandaloneECEnabler:
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
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDefaultStandaloneEnabler(self: MSPyECObjects.ECClass) -> ECN.StandaloneECEnabler:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
    def GetQualifiedClassName(primarySchema: ECN.ECSchema, ecClass: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.ECClass) -> ECN.ECRelationshipClass:
        ...
    
    def GetSchema(self: MSPyECObjects.ECClass) -> ECN.ECSchema:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
    def RelationshipClass(arg0: MSPyECObjects.ECClass) -> ECN.ECRelationshipClass:
        ...
    
    def RemoveBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def RemoveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Schema(arg0: MSPyECObjects.ECClass) -> ECN.ECSchema:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
        
        :param source:
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
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> ECN.StandaloneECEnabler:
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
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentleyGeom.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
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
    
class ECExpressionCriterion:
    """
    None
    """

    def Accept(self: MSPyECObjects.WhereCriterion, instance: MSPyDgnPlatform.DgnECInstance) -> bool:
        """
        Apply this WhereCriterion to the specified DgnECInstance, binding the
        expressions in the criterion to the instance and evaluating their
        values for this instance.
        """
        ...
    
    def AcceptCollection(self: MSPyECObjects.WhereCriterion, iterable: MSPyDgnPlatform.DgnECInstanceIterable) -> bool:
        """
        Apply this WhereCriterion to an instance collection, binding the
        expressions in the criterion to the instance and evaluating their
        values.
        """
        ...
    
    class CompareOp:
        """
        Members:
        
        eEQ
        
        eNE
        
        eGT
        
        eGE
        
        eLT
        
        eLE
        
        eIS_IN
        
        eNOT_IN
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.CompareOp, value: int) -> None:
            ...
        
        eEQ: CompareOp
        
        eGE: CompareOp
        
        eGT: CompareOp
        
        eIS_IN: CompareOp
        
        eLE: CompareOp
        
        eLT: CompareOp
        
        eNE: CompareOp
        
        eNOT_IN: CompareOp
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.CompareOp) -> int:
            ...
        
    def ComparePrimitiveValues(lhs: MSPyECObjects.ECValue, op: MSPyECObjects.WhereCriterion.CompareOp, rhs: MSPyECObjects.ECValue) -> bool:
        """
        Utility to compare two values according to a comparison operator. This
        function will call PromoteValueToPrimitiveType in order to convert the
        values to compatible types, if possible.
        
        :returns:
        true if the values satisfy the comparison.
        
        :param lhs:
        the value on the left
        
        :param rhs:
        the value on the right
        
        :param op:
        how to compare the values
        
        Remark:
        s false is returned if either value is Null or is uninitialized.
        
        Remark:
        s false is returned if either value is not a primitive type.
        
        Remark:
        s Comparing arrays or structs as such is not supported.
        """
        ...
    
    def CreateComparison(lhs: MSPyECObjects.WhereExpression, op: MSPyECObjects.WhereCriterion.CompareOp, rhs: MSPyECObjects.WhereExpression, isCaseSensitive: bool = False) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that compares the values of two expressions.
        
        See also:
        CreatePropertyExpression, CreateLogical
        
        :param lhs:
        left side WhereExpression to evaluate
        
        :param op:
        how to compare the values of the expressions, e.g.
        WhereCriterion.EQ, etc
        
        :param rhs:
        right side WhereExpression to evaluate
        
        :param isCaseSensitive:
        If true, the match will do a case sensitive match. Otherwise, it
        will be case insensitive.
        """
        ...
    
    def CreateLogical(lhs: MSPyECObjects.WhereCriterion, op: MSPyECObjects.WhereCriterion.LogicalOp, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that combines the results of other criteria.
        @See CreateComparison, CreateRelatedCriterion
        
        :param lhs:
        a criterion to evalute
        
        :param op:
        how to combine the criteria
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    def CreateLogicalAnd(lhs: MSPyECObjects.WhereCriterion, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that ANDs two criteria together. @See
        CreateComparison.
        
        :param lhs:
        a criterion to evalute
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    def CreateLogicalOr(lhs: MSPyECObjects.WhereCriterion, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that ORs two criteria together. @See
        CreateComparison.
        
        :param lhs:
        a criterion to evalute
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    def CreateNonNullPropertyTest(accessString: MSPyBentley.WString, arrayIndex: int = -1) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion which evaluates true if the specified property
        value exists and is not null
        
        :param accessString:
        The access string of the ECProperty
        
        :param arrayIndex:
        The array index, if the property is an array; or else -1
        """
        ...
    
    def CreateNullPropertyTest(accessString: MSPyBentley.WString, arrayIndex: int = -1) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion which evaluates true if the specified property
        value does not exist or is null
        
        :param accessString:
        The access string of the ECProperty
        
        :param arrayIndex:
        The array index, if the property is an array; or else -1
        """
        ...
    
    def CreateNumberFilter(lhs: MSPyECObjects.WhereExpression, filter: str, ifMatch: bool) -> tuple:
        ...
    
    def CreatePropertyComparison(ecPropertyName: str, op: MSPyECObjects.WhereCriterion.CompareOp, value: MSPyECObjects.ECValue) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that compares a named ECProperty to a known
        value. This is a convenience method that just returns
        (*WhereExpression.CreatePropertyExpression (ecPropertyName), op,
        *WhereExpression.CreateConstant (value))
        
        :param ecPropertyName:
        Name of the ECProperty
        
        :param op:
        Comparison operator, e.g. WhereCriterion.EQ, etc.
        
        :param value:
        ECValue to compare
        """
        ...
    
    def CreateRegexFilter(lhs: MSPyECObjects.WhereExpression, regexPattern: str, isCaseSensitive: bool) -> tuple:
        ...
    
    def CreateRelatedCriterion(lhs: MSPyECObjects.WhereCriterion.RelatedInstanceFinder, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that applies a criterion to a related
        instance. @See CreateLogical
        
        :param lhs:
        a related instance
        
        :param rhs:
        a criterion to apply to the related instance
        """
        ...
    
    def CreateRelatedInstanceFinder(source: MSPyECObjects.WhereCriterion.RelatedInstanceFinder, targetRelationship: MSPyECObjects.QueryRelatedClassSpecifier, relationshipCriterion: MSPyECObjects.WhereCriterion = None) -> MSPyECObjects.WhereCriterion.RelatedInstanceFinder:
        """
        Create an agent that looks up a related instance, nested in another
        related instance.
        
        :param source:
        Optional. The nested relationship to start from. If NULL, then
        this function will traverse *targetRelationship* on the current
        instance. If not NULL, then this function will evaluate *source*
        against the current instance in order to get a related instance
        and then traverse *targetRelationship* on the related instance.
        
        :param targetRelationship:
        The kind of relationship to look for
        
        :param relationshipCriterion:
        Optional. How to select instances of the specified relationship
        class.
        """
        ...
    
    def CreateStringFilter(lhs: MSPyECObjects.WhereExpression, filter: str, ifMatch: bool, isCaseSensitive: bool) -> tuple:
        ...
    
    class LogicalOp:
        """
        Members:
        
        eLOGICAL_AND
        
        eLOGICAL_OR
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.LogicalOp, value: int) -> None:
            ...
        
        eLOGICAL_AND: LogicalOp
        
        eLOGICAL_OR: LogicalOp
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.LogicalOp) -> int:
            ...
        
    class NumberFilterError:
        """
        Members:
        
        eNUMBER_FILTER_ERROR_InvalidSyntax
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.NumberFilterError, value: int) -> None:
            ...
        
        eNUMBER_FILTER_ERROR_InvalidSyntax: NumberFilterError
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.NumberFilterError) -> int:
            ...
        
    def PromoteValueToPrimitiveType(v: MSPyECObjects.ECValue, typeWanted: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECValue:
        """
        Utility to do simple primitive type conversions.
        
        :returns:
        value converted to type type wanted or an *uninitialized* value if
        the conversion could not be done. Supported conversions:
        PRIMITIVETYPE_Boolean -> PRIMITIVETYPE_Integer,
        PRIMITIVETYPE_Double, PRIMITIVETYPE_Long PRIMITIVETYPE_Integer
        -> PRIMITIVETYPE_Double, PRIMITIVETYPE_Long
        PRIMITIVETYPE_String -> PRIMITIVETYPE_Integer,
        PRIMITIVETYPE_Double, PRIMITIVETYPE_Long PRIMITIVETYPE_Long ->
        cannot be converted to any other type. However, a request to
        convert PRIMITIVETYPE_Long to an integer type is not considered an
        error and will return the input value unchanged.
        PRIMITIVETYPE_Double -> cannot be converted to any other type.
        However, a request to convert PRIMITIVETYPE_Double to an integer
        type is not considered an error and will return the input value
        unchanged. All other conversion requests are errors, and an
        uninitialized value is returned. If the input value is not a
        primitive type, an uninitialized value is returned.
        """
        ...
    
    class RelatedInstanceFinder:
        """
        None
        """
    
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    class StringFilterError:
        """
        Members:
        
        eSTRING_FILTER_ERROR_InvalidSyntax
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.StringFilterError, value: int) -> None:
            ...
        
        eSTRING_FILTER_ERROR_InvalidSyntax: StringFilterError
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.StringFilterError) -> int:
            ...
        
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eEQ: CompareOp
    
    eGE: CompareOp
    
    eGT: CompareOp
    
    eIS_IN: CompareOp
    
    eLE: CompareOp
    
    eLOGICAL_AND: LogicalOp
    
    eLOGICAL_OR: LogicalOp
    
    eLT: CompareOp
    
    eNE: CompareOp
    
    eNOT_IN: CompareOp
    
    eNUMBER_FILTER_ERROR_InvalidSyntax: NumberFilterError
    
    eSTRING_FILTER_ERROR_InvalidSyntax: StringFilterError
    
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
        
        1. CreateContext(ecSchema: ECN.ECSchema, locator: ECN.IStandaloneEnablerLocater = None, typeResolver: MSPyECObjects.IPrimitiveTypeResolver = None) -> MSPyECObjects.ECInstanceReadContext
        
        - For use when the caller knows the schema of the instance he is
        deserializing.
        Returns (Tuple, 0):
        retVal.
        
        Returns (Tuple, 1):
        foundSchema.
        
        
        
        2. CreateContext(readContext: MSPyECObjects.ECSchemaReadContext, fallbackSchema: ECN.ECSchema) -> tuple
        
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

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> ECN.StructECProperty:
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> ECN.ECClass:
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
    
    def GetClass(self: MSPyECObjects.ECProperty) -> ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    def ChildValues(arg0: MSPyECObjects.ECPropertyValue) -> ECN.ECValuesCollection:
        ...
    
    def GetChildValues(self: MSPyECObjects.ECPropertyValue) -> ECN.ECValuesCollection:
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
    
class ECQuery:
    """
    None
    """

    def AddPropertyNameToSelect(self: MSPyECObjects.ECQuery, propertyName: str) -> None:
        """
        Tell this query to create the instance that contains the following
        property.
        """
        ...
    
    def AddSearchClass(self: MSPyECObjects.ECQuery, schemaName: str, className: str, isPolymorphic: bool = False) -> None:
        """
        Tell this query to choose only instances of the specified class and
        any other classes passed to this method.
        
        :param schemaName:
        The schema
        
        :param className:
        The class
        
        :param isPolymorphic:
        True to include derived classes
        """
        ...
    
    @staticmethod
    def CreateQuery(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateQuery(query: MSPyECObjects.ECQuery, copyWhereCriteria: bool) -> MSPyECObjects.ECQuery
        
        Construct an ECQuery. Specify ECQUERY_PROCESS_SearchAllClasses for the
        query to consider instances of all classes. Use ECQUERY_PROCESS_Empty
        and then call #AddSearchClass to specify classes. Also, see
        #SetWhereCriterion to specify a 'where' clause.
        
        2. CreateQuery(flags: MSPyECObjects.ECQueryProcessFlags) -> MSPyECObjects.ECQuery
        
        Construct an ECQuery. Specify ECQUERY_PROCESS_SearchAllClasses for the
        query to consider instances of all classes. Use ECQUERY_PROCESS_Empty
        and then call #AddSearchClass to specify classes. Also, see
        #SetWhereCriterion to specify a 'where' clause.
        
        3. CreateQuery(schemaName: str, className: str, isPolymorphic: bool = False) -> MSPyECObjects.ECQuery
        
        Construct an ECQuery. Specify ECQUERY_PROCESS_SearchAllClasses for the
        query to consider instances of all classes. Use ECQUERY_PROCESS_Empty
        and then call #AddSearchClass to specify classes. Also, see
        #SetWhereCriterion to specify a 'where' clause.
        
        4. CreateQuery(ecClass: MSPyECObjects.ECClass, isPolymorphic: bool = False) -> MSPyECObjects.ECQuery
        
        Construct an ECQuery. Specify ECQUERY_PROCESS_SearchAllClasses for the
        query to consider instances of all classes. Use ECQUERY_PROCESS_Empty
        and then call #AddSearchClass to specify classes. Also, see
        #SetWhereCriterion to specify a 'where' clause.
        """
        ...
    
    def SetPropertyValuePreFilter(self: MSPyECObjects.ECQuery, filter: MSPyECObjects.IECPropertyValueFilter) -> None:
        """
        How to filter *before* creating instances and applying query where
        criteria. How to search for substrings in text-valued properties. A
        text search is an attribute of a query. The text to search for is
        associated with a query. The query mechanism used to do text searching
        is called " property value pre - filtering ". Thus, a text search is
        specified by supplying an ECSubstringPropertyValueFilter to the query.
        A query containing a text search pre-filter can be set up to search
        all classes or only specific classes, as usual. The query can contain
        a where criterion that applies additional tests to the instances that
        contain the desired text. The query applies its property value pre-
        filter after filtering on class and before applying where criteria.
        /code FindInstancesScopePtr scope = FindInstancesScope.Create(*model,
        true); ECQuery query; query.SetSearchAllClasses ();
        ECSubstringPropertyValueFilter textSearch (L" EQRSVD ");
        query.SetPropertyValuePreFilter (&textSearch); for each
        (DgnElementECInstancePtr inst in dgnECManager.FindElementInstances
        (*scope, query, model)) ++haveText; /endcode
        """
        ...
    
    def SetSelectProperties(self: MSPyECObjects.ECQuery, value: bool) -> None:
        """
        Set to indicate if found ECInstances should contain ECPropertyValues
        
        :param value:
        Pass false to return empty ECInstances (they will still have
        ECInstanceId)
        """
        ...
    
    def SetWhereCriterion(self: MSPyECObjects.ECQuery, wh: MSPyECObjects.WhereCriterion) -> None:
        """
        Specify the WhereCiterion that this query should apply when used to
        choose DgnECInstances.
        
        :param wh:
        The where criterion that this query should apply when used to
        choose DgnECInstances
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECQueryProcessFlags:
    """
    Members:
    
    eECQUERY_PROCESS_Empty
    
    eECQUERY_PROCESS_SearchAllIntrinsic
    
    eECQUERY_PROCESS_SearchAllExtrinsic
    
    eECQUERY_PROCESS_SearchSpecifiedClasses
    
    eECQUERY_PROCESS_SearchAllClasses
    """

    def __init__(self: MSPyECObjects.ECQueryProcessFlags, value: int) -> None:
        ...
    
    eECQUERY_PROCESS_Empty: ECQueryProcessFlags
    
    eECQUERY_PROCESS_SearchAllClasses: ECQueryProcessFlags
    
    eECQUERY_PROCESS_SearchAllExtrinsic: ECQueryProcessFlags
    
    eECQUERY_PROCESS_SearchAllIntrinsic: ECQueryProcessFlags
    
    eECQUERY_PROCESS_SearchSpecifiedClasses: ECQueryProcessFlags
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECQueryProcessFlags) -> int:
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
    def DefaultStandaloneEnabler(arg0: MSPyECObjects.ECClass) -> ECN.StandaloneECEnabler:
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
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetDefaultStandaloneEnabler(self: MSPyECObjects.ECClass) -> ECN.StandaloneECEnabler:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
    
    def GetQualifiedClassName(primarySchema: ECN.ECSchema, ecClass: MSPyECObjects.ECClass) -> MSPyBentley.WString:
        ...
    
    def GetRelationshipClass(self: MSPyECObjects.ECClass) -> ECN.ECRelationshipClass:
        ...
    
    def GetSchema(self: MSPyECObjects.ECClass) -> ECN.ECSchema:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
    def RelationshipClass(arg0: MSPyECObjects.ECClass) -> ECN.ECRelationshipClass:
        ...
    
    def RemoveBaseClass(self: MSPyECObjects.ECClass, baseClass: MSPyECObjects.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def RemoveProperty(self: MSPyECObjects.ECClass, name: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Schema(arg0: MSPyECObjects.ECClass) -> ECN.ECSchema:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    
    def GetCustomAttribute(self: MSPyECObjects.ECRelationshipConstraint, classDefiniton: MSPyECObjects.ECClass) -> ECN.IECInstance:
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
    
    def SetCustomAttribute(self: MSPyECObjects.ECRelationshipConstraint, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    
class ECReportNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    @staticmethod
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ECReportNodePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ECReportNodePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.ECReportNodePtrArray, arg0: MSPyECObjects.ECReportNodePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ECReportNodePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.ECReportNodePtrArray, x: MSPyECObjects.ECReportNode) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ECReportNodePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.ECReportNodePtrArray, x: MSPyECObjects.ECReportNode) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ECReportNodePtrArray, L: MSPyECObjects.ECReportNodePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ECReportNodePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ECReportNodePtrArray, i: int, x: MSPyECObjects.ECReportNode) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ECReportNodePtrArray) -> MSPyECObjects.ECReportNode
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ECReportNodePtrArray, i: int) -> MSPyECObjects.ECReportNode
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.ECReportNodePtrArray, x: MSPyECObjects.ECReportNode) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class ECReportNodeType:
    """
    Members:
    
    eUnknown
    
    eCategory
    
    eReportDefinition
    
    eColumnGroup
    
    eSortingGroup
    
    eColumnDefinition
    
    eSortingRule
    """

    def __init__(self: MSPyECObjects.ECReportNodeType, value: int) -> None:
        ...
    
    eCategory: ECReportNodeType
    
    eColumnDefinition: ECReportNodeType
    
    eColumnGroup: ECReportNodeType
    
    eReportDefinition: ECReportNodeType
    
    eSortingGroup: ECReportNodeType
    
    eSortingRule: ECReportNodeType
    
    eUnknown: ECReportNodeType
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECReportNodeType) -> int:
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
    
    def GetReferencedSchemas(self: MSPyECObjects.ECSchema) -> ECN.SchemaMapExact:
        ...
    
    def GetSchemaByNamespacePrefix(self: MSPyECObjects.ECSchema, namespacePrefix: MSPyBentley.WString) -> MSPyECObjects.ECSchema:
        ...
    
    def GetSchemaKey(self: MSPyECObjects.ECSchema) -> MSPyECObjects.SchemaKey:
        ...
    
    def GetSupplementalInfo(self: MSPyECObjects.ECSchema) -> ECN.SupplementalSchemaInfo:
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
    def ReferencedSchemas(arg0: MSPyECObjects.ECSchema) -> ECN.SchemaMapExact:
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
    def SupplementalInfo(arg0: MSPyECObjects.ECSchema) -> ECN.SupplementalSchemaInfo:
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

    def AddSchema(self: MSPyECObjects.ECSchemaCache, schema: ECN.ECSchema) -> MSPyECObjects.ECObjectsStatus:
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
        
        1. GetSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey) -> ECN.ECSchema
        
        2. GetSchema(self: MSPyECObjects.ECSchemaCache, key: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType) -> ECN.ECSchema
        """
        ...
    
    def GetSchemaLocater(self: MSPyECObjects.ECSchemaCache) -> MSPyECObjects.IECSchemaLocater:
        ...
    
    def GetSchemas(self: MSPyECObjects.ECSchemaCache, schemas: List[ECN.ECSchema ]) -> int:
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
    
class ECSchemaPersistence:
    """
    Members:
    
    eECSCHEMAPERSISTENCE_Unknown
    
    eECSCHEMAPERSISTENCE_Stored
    
    eECSCHEMAPERSISTENCE_External
    
    eECSCHEMAPERSISTENCE_All
    """

    def __init__(self: MSPyECObjects.ECSchemaPersistence, value: int) -> None:
        ...
    
    eECSCHEMAPERSISTENCE_All: ECSchemaPersistence
    
    eECSCHEMAPERSISTENCE_External: ECSchemaPersistence
    
    eECSCHEMAPERSISTENCE_Stored: ECSchemaPersistence
    
    eECSCHEMAPERSISTENCE_Unknown: ECSchemaPersistence
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.ECSchemaPersistence) -> int:
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
        
        :param culture:
        string in format cu-CU or just cu
        """
        ...
    
    def AddSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: ECN.IECSchemaLocater, priority: int = 0) -> None:
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
    def Cache(arg0: MSPyECObjects.ECSchemaReadContext) -> ECN.ECSchemaCache:
        ...
    
    @staticmethod
    def CreateContext(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateContext(standaloneEnablerLocator: ECN.IStandaloneEnablerLocater, acceptLegacyImperfectLatestCompatibleMatch: bool = False) -> MSPyECObjects.ECSchemaReadContext
        
        Creates a context for deserializing ECSchemas
        
        :param standaloneEnablerLocater:
        Used to find enablers for instantiating instances of
        ECCustomAttributes used in the read ECSchema
        
        :param acceptLegacyImperfectLatestCompatibleMatch:
        If true, LatestCompatible only checks that the major version
        matches. A warning will be logged if minor version is too low, but
        the ECSchema will be accepted
        
        Remark:
        s This more-flexible override is primarily for internal use
        
        2. CreateContext(acceptLegacyImperfectLatestCompatibleMatch: bool = False) -> MSPyECObjects.ECSchemaReadContext
        
        Creates a context for deserializing ECSchemas
        
        :param standaloneEnablerLocater:
        Used to find enablers for instantiating instances of
        ECCustomAttributes used in the read ECSchema
        
        :param acceptLegacyImperfectLatestCompatibleMatch:
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
    
    def GetCache(self: MSPyECObjects.ECSchemaReadContext) -> ECN.ECSchemaCache:
        """
        Gets the schemas cached by this context.
        
        :returns:
        Schemas cached by this context
        """
        ...
    
    def GetCultures(self: MSPyECObjects.ECSchemaReadContext) -> MSPyBentley.WStringArray:
        """
        Gets culture strings
        """
        ...
    
    def LocateSchema(self: MSPyECObjects.ECSchemaReadContext, key: ECN.SchemaKey, matchType: ECN.SchemaMatchType) -> ECN.ECSchema:
        """
        Find the schema matching the schema key and using matchType as the
        match criteria. This uses the prioritized list of locators to find the
        schema.
        
        :param key:
        The SchemaKey that defines the schema (name and version
        information) that is being looked for
        
        :param matchType:
        The match type criteria used to locate the requested schema
        
        :returns:
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
        
    def RemoveSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: ECN.IECSchemaLocater) -> None:
        """
        Removes a schema locater from the current context
        
        :param locater:
        Locater to remove from the current context
        """
        ...
    
    def SetFinalSchemaLocater(self: MSPyECObjects.ECSchemaReadContext, locator: ECN.IECSchemaLocater) -> None:
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
    
class ECSubstringPropertyValueFilter:
    """
    None
    """

    def Accept(self: MSPyECObjects.IECPropertyValueFilter, propertyValue: MSPyECObjects.ECPropertyValue) -> bool:
        """
        Applies this filter to the specified property value to determine if it
        meets the criterion
        
        :param propertyValue:
        The property value to accept or reject
        
        :returns:
        true if the property value meets the criterion of this filter
        """
        ...
    
    def AddChainedFilter(self: MSPyECObjects.IECPropertyValueFilter, chainedFilter: MSPyECObjects.IECPropertyValueFilter) -> None:
        """
        Add a chained filter to be executed on any property values which pass
        this filter If a chained filter already exists, it will be replaced
        
        :param chainedFilter:
        The filter to add
        """
        ...
    
    @property
    def ChainedFilter(arg0: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.IECPropertyValueFilter:
        ...
    
    def ConsiderChildValues(self: MSPyECObjects.IECPropertyValueFilter, parentPropertyValue: MSPyECObjects.ECPropertyValue) -> bool:
        """
        Get whether members of the specified array or struct property should
        be examined by this filter. This allows arrays and structs to be
        trivially skipped in circumstances under which the filter will not
        accept any of them
        
        :param parentPropertyValue:
        The array or struct property value
        
        :returns:
        true if child values should be examined by the filter.
        """
        ...
    
    def GetChainedFilter(self: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.IECPropertyValueFilter:
        """
        Get the next filter in the chain, if one exists
        
        :returns:
        The filter executed after this one.
        """
        ...
    
    def GetRequiredPrimitiveType(self: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.PrimitiveType:
        """
        Gets the primitive property type this filter applies to
        
        :returns:
        The primitive type this filter applies to, or 0 if it applies to
        properties of any type
        """
        ...
    
    @property
    def RequiredPrimitiveType(arg0: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.PrimitiveType:
        ...
    
    def __init__(self: MSPyECObjects.ECSubstringPropertyValueFilter, pv: str) -> None:
        ...
    
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
    def Boolean(arg0: MSPyECObjects.ECValue, arg1: bool) -> BentleyStatus:
        ...
    
    def CanConvertToPrimitiveType(self: MSPyECObjects.ECValue, type: MSPyECObjects.PrimitiveType) -> bool:
        ...
    
    def Clear(self: MSPyECObjects.ECValue) -> None:
        ...
    
    @property
    def DateTime(arg0: MSPyECObjects.ECValue) -> MSPyBentley.BeDateTime:
        ...
    @DateTime.setter
    def DateTime(arg0: MSPyECObjects.ECValue, arg1: MSPyBentley.BeDateTime) -> BentleyStatus:
        ...
    
    @property
    def DateTimeTicks(arg0: MSPyECObjects.ECValue) -> int:
        ...
    @DateTimeTicks.setter
    def DateTimeTicks(arg0: MSPyECObjects.ECValue, arg1: int) -> BentleyStatus:
        ...
    
    @property
    def DateTimeUnixMillis(arg0: MSPyECObjects.ECValue) -> int:
        ...
    
    @property
    def Double(arg0: MSPyECObjects.ECValue) -> float:
        ...
    @Double.setter
    def Double(arg0: MSPyECObjects.ECValue, arg1: float) -> BentleyStatus:
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
    def IGeometry(arg0: MSPyECObjects.ECValue, arg1: MSPyBentleyGeom.IGeometry) -> BentleyStatus:
        ...
    
    @property
    def Integer(arg0: MSPyECObjects.ECValue) -> int:
        ...
    @Integer.setter
    def Integer(arg0: MSPyECObjects.ECValue, arg1: int) -> BentleyStatus:
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
    def Long(arg0: MSPyECObjects.ECValue, arg1: int) -> BentleyStatus:
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
    def Point2D(arg0: MSPyECObjects.ECValue, arg1: MSPyBentleyGeom.DPoint2d) -> BentleyStatus:
        ...
    
    @property
    def Point3D(arg0: MSPyECObjects.ECValue) -> MSPyBentleyGeom.DPoint3d:
        ...
    @Point3D.setter
    def Point3D(arg0: MSPyECObjects.ECValue, arg1: MSPyBentleyGeom.DPoint3d) -> BentleyStatus:
        ...
    
    @property
    def PrimitiveType(arg0: MSPyECObjects.ECValue) -> MSPyECObjects.PrimitiveType:
        ...
    @PrimitiveType.setter
    def PrimitiveType(arg0: MSPyECObjects.ECValue, arg1: MSPyECObjects.PrimitiveType) -> BentleyStatus:
        ...
    
    @property
    def ReadOnly(arg0: MSPyECObjects.ECValue) -> bool:
        ...
    @ReadOnly.setter
    def ReadOnly(arg0: MSPyECObjects.ECValue, arg1: bool) -> None:
        ...
    
    def SetBinary(self: MSPyECObjects.ECValue, arg0: bytes) -> None:
        ...
    
    def SetBoolean(self: MSPyECObjects.ECValue, boolean: bool) -> BentleyStatus:
        ...
    
    def SetDateTime(self: MSPyECObjects.ECValue, dateTime: MSPyBentley.BeDateTime) -> BentleyStatus:
        ...
    
    def SetDateTimeTicks(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetDateTimeTicks(self: MSPyECObjects.ECValue, ceTicks: int) -> BentleyStatus
        
        2. SetDateTimeTicks(self: MSPyECObjects.ECValue, ceTicks: int, dateTimeMetaData: MSPyBentley.BeDateTimeInfo) -> BentleyStatus
        """
        ...
    
    def SetDouble(self: MSPyECObjects.ECValue, dblVal: float) -> BentleyStatus:
        ...
    
    def SetIGeometry(self: MSPyECObjects.ECValue, geometry: MSPyBentleyGeom.IGeometry) -> BentleyStatus:
        ...
    
    def SetInteger(self: MSPyECObjects.ECValue, integer: int) -> BentleyStatus:
        ...
    
    def SetIsLoaded(self: MSPyECObjects.ECValue, loaded: bool) -> None:
        ...
    
    def SetIsNull(self: MSPyECObjects.ECValue, null: bool) -> None:
        ...
    
    def SetIsReadOnly(self: MSPyECObjects.ECValue, readOnly: bool) -> None:
        ...
    
    def SetLong(self: MSPyECObjects.ECValue, long64: int) -> BentleyStatus:
        ...
    
    def SetPoint2D(self: MSPyECObjects.ECValue, value: MSPyBentleyGeom.DPoint2d) -> BentleyStatus:
        ...
    
    def SetPoint3D(self: MSPyECObjects.ECValue, value: MSPyBentleyGeom.DPoint3d) -> BentleyStatus:
        ...
    
    def SetPrimitiveArrayInfo(self: MSPyECObjects.ECValue, primitiveElementType: MSPyECObjects.PrimitiveType, count: int, isFixedSize: bool) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetPrimitiveType(self: MSPyECObjects.ECValue, type: MSPyECObjects.PrimitiveType) -> BentleyStatus:
        ...
    
    def SetString(*args, **kwargs):
        """
        Overloaded function.
        
        1. SetString(self: MSPyECObjects.ECValue, string: MSPyBentley.WString, bool: bool = True) -> None
        
        2. SetString(self: MSPyECObjects.ECValue, string: MSPyBentley.Utf8String, bool: bool = True) -> None
        
        3. SetString(self: MSPyECObjects.ECValue, string: str, bool: bool = True) -> None
        """
        ...
    
    def SetStruct(self: MSPyECObjects.ECValue, instance: MSPyECObjects.IECInstance) -> BentleyStatus:
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
    def Struct(arg0: MSPyECObjects.ECValue, arg1: MSPyECObjects.IECInstance) -> BentleyStatus:
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
    
class ElementTemplateNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ElementTemplateNode
        
        Create and return a pointer to an ElementTemplateNode.
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.ElementTemplateNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ElementTemplateNode
        
        Create and return a pointer to an ElementTemplateNode.
        """
        ...
    
    @property
    def DefaultInstance(arg0: MSPyECObjects.ElementTemplateNode) -> MSPyECObjects.IECInstance:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ElementTemplateNode:
        """
        Return a pointer to an ElementTemplateNode for an existing element.
        
        :param elemID:
        The ElementId of the Type 66 element that holds the element
        template XAttribute data.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        """
        ...
    
    @staticmethod
    def FromXDataTreeNode(xDataTreeNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ElementTemplateNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.ElementTemplateNode) -> MSPyECObjects.IECInstance:
        """
        Return the " default " IECInstance used to store symbology paraemeters
        in Element Templates. It is possible for an element template to hold
        instance data for other applications. The default instance holds the
        symbology parameters used by MicroStation and its derivatives.
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId used to designate an element as an
        ElementTemplate Node.
        """
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.ElementTemplateNode) -> MSPyECObjects.IECInstance:
        """
        Return the " default " IECInstance used to store symbology paraemeters
        in Element Templates. It is possible for an element template to hold
        instance data for other applications. The default instance holds the
        symbology parameters used by MicroStation and its derivatives. This
        method with create an instance so it can be populated if one does not
        exist.
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
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
    def ECValue(arg0: MSPyECObjects.EvaluationResult) -> ECN.ECValue:
        ...
    
    def GetECValue(self: MSPyECObjects.EvaluationResult) -> ECN.ECValue:
        ...
    
    def GetInstanceList(self: MSPyECObjects.EvaluationResult) -> List[ECN.IECInstance]:
        ...
    
    def GetUnits(self: MSPyECObjects.EvaluationResult) -> ECN.UnitSpec:
        ...
    
    def GetValueType(self: MSPyECObjects.EvaluationResult) -> MSPyECObjects.ValueType:
        ...
    
    @property
    def InstanceList(arg0: MSPyECObjects.EvaluationResult) -> List[ECN.IECInstance]:
        ...
    
    def IsECValue(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def IsInstanceList(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def IsLambda(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def IsValueList(self: MSPyECObjects.EvaluationResult) -> bool:
        ...
    
    def SetInstance(self: MSPyECObjects.EvaluationResult, instance: ECN.IECInstance) -> None:
        ...
    
    def SetInstanceList(self: MSPyECObjects.EvaluationResult, instanceList: List[ECN.IECInstance], makeCopy: bool) -> None:
        ...
    
    def SetUnits(self: MSPyECObjects.EvaluationResult, units: ECN.UnitSpec) -> None:
        ...
    
    @property
    def Units(arg0: MSPyECObjects.EvaluationResult) -> ECN.UnitSpec:
        ...
    @Units.setter
    def Units(arg0: MSPyECObjects.EvaluationResult, arg1: ECN.UnitSpec) -> None:
        ...
    
    @property
    def ValueType(arg0: MSPyECObjects.EvaluationResult) -> MSPyECObjects.ValueType:
        ...
    
    def __init__(self: MSPyECObjects.EvaluationResult) -> None:
        ...
    
class ExplorerContextMenuNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ExplorerContextMenuNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.ExplorerContextMenuNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ExplorerContextMenuNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ExplorerContextMenuNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ExplorerContextMenuNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
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
    
class HostExpressionCriterion:
    """
    None
    """

    def Accept(self: MSPyECObjects.WhereCriterion, instance: MSPyDgnPlatform.DgnECInstance) -> bool:
        """
        Apply this WhereCriterion to the specified DgnECInstance, binding the
        expressions in the criterion to the instance and evaluating their
        values for this instance.
        """
        ...
    
    def AcceptCollection(self: MSPyECObjects.WhereCriterion, iterable: MSPyDgnPlatform.DgnECInstanceIterable) -> bool:
        """
        Apply this WhereCriterion to an instance collection, binding the
        expressions in the criterion to the instance and evaluating their
        values.
        """
        ...
    
    class CompareOp:
        """
        Members:
        
        eEQ
        
        eNE
        
        eGT
        
        eGE
        
        eLT
        
        eLE
        
        eIS_IN
        
        eNOT_IN
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.CompareOp, value: int) -> None:
            ...
        
        eEQ: CompareOp
        
        eGE: CompareOp
        
        eGT: CompareOp
        
        eIS_IN: CompareOp
        
        eLE: CompareOp
        
        eLT: CompareOp
        
        eNE: CompareOp
        
        eNOT_IN: CompareOp
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.CompareOp) -> int:
            ...
        
    def ComparePrimitiveValues(lhs: MSPyECObjects.ECValue, op: MSPyECObjects.WhereCriterion.CompareOp, rhs: MSPyECObjects.ECValue) -> bool:
        """
        Utility to compare two values according to a comparison operator. This
        function will call PromoteValueToPrimitiveType in order to convert the
        values to compatible types, if possible.
        
        :returns:
        true if the values satisfy the comparison.
        
        :param lhs:
        the value on the left
        
        :param rhs:
        the value on the right
        
        :param op:
        how to compare the values
        
        Remark:
        s false is returned if either value is Null or is uninitialized.
        
        Remark:
        s false is returned if either value is not a primitive type.
        
        Remark:
        s Comparing arrays or structs as such is not supported.
        """
        ...
    
    def CreateComparison(lhs: MSPyECObjects.WhereExpression, op: MSPyECObjects.WhereCriterion.CompareOp, rhs: MSPyECObjects.WhereExpression, isCaseSensitive: bool = False) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that compares the values of two expressions.
        
        See also:
        CreatePropertyExpression, CreateLogical
        
        :param lhs:
        left side WhereExpression to evaluate
        
        :param op:
        how to compare the values of the expressions, e.g.
        WhereCriterion.EQ, etc
        
        :param rhs:
        right side WhereExpression to evaluate
        
        :param isCaseSensitive:
        If true, the match will do a case sensitive match. Otherwise, it
        will be case insensitive.
        """
        ...
    
    def CreateLogical(lhs: MSPyECObjects.WhereCriterion, op: MSPyECObjects.WhereCriterion.LogicalOp, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that combines the results of other criteria.
        @See CreateComparison, CreateRelatedCriterion
        
        :param lhs:
        a criterion to evalute
        
        :param op:
        how to combine the criteria
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    def CreateLogicalAnd(lhs: MSPyECObjects.WhereCriterion, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that ANDs two criteria together. @See
        CreateComparison.
        
        :param lhs:
        a criterion to evalute
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    def CreateLogicalOr(lhs: MSPyECObjects.WhereCriterion, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that ORs two criteria together. @See
        CreateComparison.
        
        :param lhs:
        a criterion to evalute
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    def CreateNonNullPropertyTest(accessString: MSPyBentley.WString, arrayIndex: int = -1) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion which evaluates true if the specified property
        value exists and is not null
        
        :param accessString:
        The access string of the ECProperty
        
        :param arrayIndex:
        The array index, if the property is an array; or else -1
        """
        ...
    
    def CreateNullPropertyTest(accessString: MSPyBentley.WString, arrayIndex: int = -1) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion which evaluates true if the specified property
        value does not exist or is null
        
        :param accessString:
        The access string of the ECProperty
        
        :param arrayIndex:
        The array index, if the property is an array; or else -1
        """
        ...
    
    def CreateNumberFilter(lhs: MSPyECObjects.WhereExpression, filter: str, ifMatch: bool) -> tuple:
        ...
    
    def CreatePropertyComparison(ecPropertyName: str, op: MSPyECObjects.WhereCriterion.CompareOp, value: MSPyECObjects.ECValue) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that compares a named ECProperty to a known
        value. This is a convenience method that just returns
        (*WhereExpression.CreatePropertyExpression (ecPropertyName), op,
        *WhereExpression.CreateConstant (value))
        
        :param ecPropertyName:
        Name of the ECProperty
        
        :param op:
        Comparison operator, e.g. WhereCriterion.EQ, etc.
        
        :param value:
        ECValue to compare
        """
        ...
    
    def CreateRegexFilter(lhs: MSPyECObjects.WhereExpression, regexPattern: str, isCaseSensitive: bool) -> tuple:
        ...
    
    def CreateRelatedCriterion(lhs: MSPyECObjects.WhereCriterion.RelatedInstanceFinder, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that applies a criterion to a related
        instance. @See CreateLogical
        
        :param lhs:
        a related instance
        
        :param rhs:
        a criterion to apply to the related instance
        """
        ...
    
    def CreateRelatedInstanceFinder(source: MSPyECObjects.WhereCriterion.RelatedInstanceFinder, targetRelationship: MSPyECObjects.QueryRelatedClassSpecifier, relationshipCriterion: MSPyECObjects.WhereCriterion = None) -> MSPyECObjects.WhereCriterion.RelatedInstanceFinder:
        """
        Create an agent that looks up a related instance, nested in another
        related instance.
        
        :param source:
        Optional. The nested relationship to start from. If NULL, then
        this function will traverse *targetRelationship* on the current
        instance. If not NULL, then this function will evaluate *source*
        against the current instance in order to get a related instance
        and then traverse *targetRelationship* on the related instance.
        
        :param targetRelationship:
        The kind of relationship to look for
        
        :param relationshipCriterion:
        Optional. How to select instances of the specified relationship
        class.
        """
        ...
    
    def CreateStringFilter(lhs: MSPyECObjects.WhereExpression, filter: str, ifMatch: bool, isCaseSensitive: bool) -> tuple:
        ...
    
    class LogicalOp:
        """
        Members:
        
        eLOGICAL_AND
        
        eLOGICAL_OR
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.LogicalOp, value: int) -> None:
            ...
        
        eLOGICAL_AND: LogicalOp
        
        eLOGICAL_OR: LogicalOp
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.LogicalOp) -> int:
            ...
        
    class NumberFilterError:
        """
        Members:
        
        eNUMBER_FILTER_ERROR_InvalidSyntax
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.NumberFilterError, value: int) -> None:
            ...
        
        eNUMBER_FILTER_ERROR_InvalidSyntax: NumberFilterError
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.NumberFilterError) -> int:
            ...
        
    def PromoteValueToPrimitiveType(v: MSPyECObjects.ECValue, typeWanted: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECValue:
        """
        Utility to do simple primitive type conversions.
        
        :returns:
        value converted to type type wanted or an *uninitialized* value if
        the conversion could not be done. Supported conversions:
        PRIMITIVETYPE_Boolean -> PRIMITIVETYPE_Integer,
        PRIMITIVETYPE_Double, PRIMITIVETYPE_Long PRIMITIVETYPE_Integer
        -> PRIMITIVETYPE_Double, PRIMITIVETYPE_Long
        PRIMITIVETYPE_String -> PRIMITIVETYPE_Integer,
        PRIMITIVETYPE_Double, PRIMITIVETYPE_Long PRIMITIVETYPE_Long ->
        cannot be converted to any other type. However, a request to
        convert PRIMITIVETYPE_Long to an integer type is not considered an
        error and will return the input value unchanged.
        PRIMITIVETYPE_Double -> cannot be converted to any other type.
        However, a request to convert PRIMITIVETYPE_Double to an integer
        type is not considered an error and will return the input value
        unchanged. All other conversion requests are errors, and an
        uninitialized value is returned. If the input value is not a
        primitive type, an uninitialized value is returned.
        """
        ...
    
    class RelatedInstanceFinder:
        """
        None
        """
    
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    class StringFilterError:
        """
        Members:
        
        eSTRING_FILTER_ERROR_InvalidSyntax
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.StringFilterError, value: int) -> None:
            ...
        
        eSTRING_FILTER_ERROR_InvalidSyntax: StringFilterError
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.StringFilterError) -> int:
            ...
        
    def __init__(self: MSPyECObjects.HostExpressionCriterion, expressionString: str, hostSymbolName: str, hostSpecContext: MSPyECObjects.DgnECHostSpecificationsContext) -> None:
        ...
    
    eEQ: CompareOp
    
    eGE: CompareOp
    
    eGT: CompareOp
    
    eIS_IN: CompareOp
    
    eLE: CompareOp
    
    eLOGICAL_AND: LogicalOp
    
    eLOGICAL_OR: LogicalOp
    
    eLT: CompareOp
    
    eNE: CompareOp
    
    eNOT_IN: CompareOp
    
    eNUMBER_FILTER_ERROR_InvalidSyntax: NumberFilterError
    
    eSTRING_FILTER_ERROR_InvalidSyntax: StringFilterError
    
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

    def GenerateXmlString(self: MSPyECObjects.ICustomECStructSerializer, xmlString: MSPyBentley.WString, structProperty: MSPyECObjects.StructECProperty, ecInstance: ECN.IECInstance, baseAccessString: str) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def LoadStructureFromString(self: MSPyECObjects.ICustomECStructSerializer, structProperty: MSPyECObjects.StructECProperty, ecInstance: ECN.IECInstance, baseAccessString: str, valueString: str) -> None:
        ...
    
    def UsesCustomStructXmlString(self: MSPyECObjects.ICustomECStructSerializer, structProperty: MSPyECObjects.StructECProperty, ecInstance: ECN.IECInstance) -> bool:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IDgnECProvider:
    """
    None
    """

    def FindECClassesOnElement(*args, **kwargs):
        """
        FindECClassesOnElement(self: MSPyECObjects.IDgnECProvider, rootElement: MSPyDgnPlatform.ElementRefBase, classes: bmap<ECN::SchemaNameClassNamePair,bool,std::less<ECN::SchemaNameClassNamePair>,32,BentleyAllocator<Bstdcxx::bpair<ECN::SchemaNameClassNamePair const ,bool> > >) -> None
        
        Finds the schemaName className pairs for all instances on the element,
        and sets a flag as to whether the primary instance on the element is
        of that class.
        
        :param rootElement:
        The element to search
        
        :param infos:
        The list of schemaNameclassName pairs
        """
        ...
    
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
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IDgnECRelationshipInstance:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
    
    def Delete(self: MSPyECObjects.IDgnECRelationshipInstance) -> MSPyECObjects.DgnECInstanceStatus:
        """
        Delete the XAttributes that hold the relationship data.
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
    
    def GetRelatedInstance(self: MSPyECObjects.IDgnECRelationshipInstance, end: MSPyECObjects.ECRelationshipEnd, createContext: MSPyECObjects.DgnECInstanceCreateContext) -> MSPyECObjects.DgnElementECInstance:
        """
        Gets the associated instance data
        """
        ...
    
    def GetSource(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    
    def GetSourceAssociatedString(self: MSPyECObjects.IDgnECRelationshipInstance) -> tuple:
        """
        Gets the source property string
        
        Returns (Tuple,0):
        retVal.
        
        Returns (Tuple,1):
        propString.
        """
        ...
    
    def GetSourceOrderId(self: MSPyECObjects.IDgnECRelationshipInstance) -> tuple:
        """
        Gets the source order id
        
        Returns (Tuple,0):
        retVal.
        
        Returns (Tuple,1):
        sourceOrderId.
        """
        ...
    
    def GetTarget(self: MSPyECObjects.IECRelationshipInstance) -> MSPyECObjects.IECInstance:
        ...
    
    def GetTargetAssociatedString(self: MSPyECObjects.IDgnECRelationshipInstance) -> tuple:
        """
        Gets the source property string
        
        Returns (Tuple,0):
        retVal.
        
        Returns (Tuple,1):
        propString.
        """
        ...
    
    def GetTargetOrderId(self: MSPyECObjects.IDgnECRelationshipInstance) -> tuple:
        """
        Gets the target order id
        
        
        Returns (Tuple,0):
        retVal.
        
        Returns (Tuple,1):
        targetOrderId.
        """
        ...
    
    def GetValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
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
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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
    
class IDgnECRelationshipInstancePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, arg0: MSPyECObjects.IDgnECRelationshipInstancePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, x: MSPyECObjects.IDgnECRelationshipInstance) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, x: MSPyECObjects.IDgnECRelationshipInstance) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, L: MSPyECObjects.IDgnECRelationshipInstancePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, i: int, x: MSPyECObjects.IDgnECRelationshipInstance) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray) -> MSPyECObjects.IDgnECRelationshipInstance
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, i: int) -> MSPyECObjects.IDgnECRelationshipInstance
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.IDgnECRelationshipInstancePtrArray, x: MSPyECObjects.IDgnECRelationshipInstance) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
        ...
    
class IDgnECStandaloneTypeAdapterContext:
    """
    None
    """

    def CreateStandalone(ecproperty: MSPyECObjects.ECProperty, instance: MSPyECObjects.IECInstance, accessString: str, componentIndex: int = 4294967295, dgnFile: MSPyDgnPlatform.DgnFile = None, modelRef: MSPyDgnPlatform.DgnModelRef = None, elemRef: MSPyDgnPlatform.ElementRefBase = None) -> MSPyDgnPlatform.IDgnECStandaloneTypeAdapterContext:
        """
        Create a context for an IECInstance. If the instance can be cast to
        DgnECInstance and the file/modelRef/elemRef arguments are NULL, they
        will be taken from the DgnECInstance Standalone contexts can be re-
        initialized and re-used, which is useful for avoiding repeated
        allocations.
        
        :param ecproperty:
        The ECProperty the type adapter will operate on
        
        :param instance:
        The IECInstance which will supply the property values
        
        :param accessString:
        The access string of the property within the instance.
        
        :param componentIndex:
        For point properties, the component index (x=0,y=1,z=2) if the
        type adapter should operate only on a single component of the
        point
        
        :param dgnFile:
        The DgnFile from which the property value originated
        
        :param modelRef:
        The DgnModelRef associated with the property value
        
        :param elemRef:
        The ElementRef associated with the property value
        
        :returns:
        a reusable context which can be passed to an IDgnECTypeAdapter
        """
        ...
    
    def ReInitialize(self: MSPyECObjects.IDgnECStandaloneTypeAdapterContext, ecproperty: MSPyECObjects.ECProperty, instance: MSPyECObjects.IECInstance, accessString: str, componentIndex: int = 4294967295, dgnFile: MSPyDgnPlatform.DgnFile = None, modelRef: MSPyDgnPlatform.DgnModelRef = None, elemRef: MSPyDgnPlatform.ElementRefBase = None) -> bool:
        """
        Re-initialize this context If instance can be cast to DgnECInstance
        and the file/modelRef/elemRef arguments are NULL, they will be taken
        from the DgnECInstance
        
        :param ecproperty:
        The ECProperty the type adapter will operate on
        
        :param instance:
        The IECInstance which will supply the property values
        
        :param accessString:
        The access string of the property within the instance.
        
        :param componentIndex:
        For point properties, the component index (x=0,y=1,z=2) if the
        type adapter should operate only on a single component of the
        point
        
        :param dgnFile:
        The DgnFile from which the property value originated
        
        :param modelRef:
        The DgnModelRef associated with the property value
        
        :param elemRef:
        The ElementRef associated with the property value
        
        :returns:
        true if the context was successfully re-initialized
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IDgnECTypeAdapter:
    """
    None
    """

    @staticmethod
    def GetForArrayMember(arrayProperty: MSPyECObjects.ArrayECProperty) -> MSPyECObjects.IDgnECTypeAdapter:
        """
        Obtain a type adapter for members of the specified array property. If
        the property specifies a MemberExtendedType custom attribute, it will
        be used to locate the type adapter.
        
        :param arrayProperty:
        The array property for which to obtain a member type adapter
        
        :returns:
        a type adapter for members of the specified array property
        """
        ...
    
    @staticmethod
    def GetForProperty(ecProperty: MSPyECObjects.ECProperty) -> MSPyECObjects.IDgnECTypeAdapter:
        """
        Obtain a type adapter for the specified property. If the property
        specifies an ExtendType custom attribute, it will be used to locate
        the type adapter.
        
        :param ecProperty:
        The property for which to obtain a type adapter
        
        :returns:
        a type adapter for the specified property
        """
        ...
    
    def GetStandardValues(self: MSPyECObjects.IDgnECTypeAdapter, values: MSPyBentley.WStringArray, context: MSPyECObjects.IDgnECTypeAdapterContext) -> bool:
        """
        Get a list of strings representing permissible values for this
        property
        
        :param values:
        Permissible values, as a list of user-friendly strings
        
        :param context:
        The context under which to evaluate
        
        :returns:
        true if the list of permissible values was populated successfully
        """
        ...
    
    def Validate(self: MSPyECObjects.IDgnECTypeAdapter, v: MSPyECObjects.ECValue, context: MSPyECObjects.IDgnECTypeAdapterContext) -> bool:
        """
        Determine if the proposed value is valid for the ECProperty specified
        by the context
        
        :param v:
        The proposed value
        
        :param context:
        The context in which to evaluate
        
        :returns:
        true if the value is valid for the property
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class IDgnECTypeAdapterContext:
    """
    None
    """

    @staticmethod
    def CreateStandalone(ecproperty: MSPyECObjects.ECProperty, instance: MSPyECObjects.IECInstance, accessString: str, componentIndex: int = 4294967295, dgnFile: MSPyDgnPlatform.DgnFile = None, modelRef: MSPyDgnPlatform.DgnModelRef = None, elemRef: MSPyDgnPlatform.ElementRefBase = None) -> MSPyDgnPlatform.IDgnECStandaloneTypeAdapterContext:
        """
        Create a context for an IECInstance. If the instance can be cast to
        DgnECInstance and the file/modelRef/elemRef arguments are NULL, they
        will be taken from the DgnECInstance Standalone contexts can be re-
        initialized and re-used, which is useful for avoiding repeated
        allocations.
        
        :param ecproperty:
        The ECProperty the type adapter will operate on
        
        :param instance:
        The IECInstance which will supply the property values
        
        :param accessString:
        The access string of the property within the instance.
        
        :param componentIndex:
        For point properties, the component index (x=0,y=1,z=2) if the
        type adapter should operate only on a single component of the
        point
        
        :param dgnFile:
        The DgnFile from which the property value originated
        
        :param modelRef:
        The DgnModelRef associated with the property value
        
        :param elemRef:
        The ElementRef associated with the property value
        
        :returns:
        a reusable context which can be passed to an IDgnECTypeAdapter
        """
        ...
    
    def __init__(self: MSPyECObjects.IDgnECTypeAdapterContext, ecproperty: MSPyECObjects.ECProperty, instance: MSPyDgnPlatform.DgnECInstance, accessString: str, componentIndex: int = 4294967295) -> None:
        ...
    
class IECCustomAttributeContainer:
    """
    None
    """

    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetPrimaryCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def IsDefined(*args, **kwargs):
        """
        Overloaded function.
        
        1. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def RemoveCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> bool
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
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
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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
    
class IECPropertyValueFilter:
    """
    None
    """

    def Accept(self: MSPyECObjects.IECPropertyValueFilter, propertyValue: MSPyECObjects.ECPropertyValue) -> bool:
        """
        Applies this filter to the specified property value to determine if it
        meets the criterion
        
        :param propertyValue:
        The property value to accept or reject
        
        :returns:
        true if the property value meets the criterion of this filter
        """
        ...
    
    def AddChainedFilter(self: MSPyECObjects.IECPropertyValueFilter, chainedFilter: MSPyECObjects.IECPropertyValueFilter) -> None:
        """
        Add a chained filter to be executed on any property values which pass
        this filter If a chained filter already exists, it will be replaced
        
        :param chainedFilter:
        The filter to add
        """
        ...
    
    @property
    def ChainedFilter(arg0: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.IECPropertyValueFilter:
        ...
    
    def ConsiderChildValues(self: MSPyECObjects.IECPropertyValueFilter, parentPropertyValue: MSPyECObjects.ECPropertyValue) -> bool:
        """
        Get whether members of the specified array or struct property should
        be examined by this filter. This allows arrays and structs to be
        trivially skipped in circumstances under which the filter will not
        accept any of them
        
        :param parentPropertyValue:
        The array or struct property value
        
        :returns:
        true if child values should be examined by the filter.
        """
        ...
    
    def GetChainedFilter(self: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.IECPropertyValueFilter:
        """
        Get the next filter in the chain, if one exists
        
        :returns:
        The filter executed after this one.
        """
        ...
    
    def GetRequiredPrimitiveType(self: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.PrimitiveType:
        """
        Gets the primitive property type this filter applies to
        
        :returns:
        The primitive type this filter applies to, or 0 if it applies to
        properties of any type
        """
        ...
    
    @property
    def RequiredPrimitiveType(arg0: MSPyECObjects.IECPropertyValueFilter) -> MSPyECObjects.PrimitiveType:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
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

    def CreateWipRelationshipInstance(self: MSPyECObjects.IECRelationshipEnabler) -> ECN.StandaloneECRelationshipInstance:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
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
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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

    def LocateSchema(self: MSPyECObjects.IECSchemaLocater, key: MSPyECObjects.SchemaKey, matchType: MSPyECObjects.SchemaMatchType, schemaContext: MSPyECObjects.ECSchemaReadContext) -> ECN.ECSchema:
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
        RegisterExternalSymbolPublisher(externalPublisher: std::function<void __cdecl(ECN::SymbolExpressionContext & __ptr64,Bstdcxx::bvector<WString,BentleyAllocator<WString> > const & __ptr64)>) -> None
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
    
    def CondenseFormatterForSerialization(self: MSPyECObjects.IECTypeAdapter, formatter: ECN.IECInstance) -> ECN.IECInstance:
        ...
    
    def ConvertFromExpressionType(self: MSPyECObjects.IECTypeAdapter, value: ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def ConvertFromString(self: MSPyECObjects.IECTypeAdapter, value: ECN.ECValue, str: str, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def ConvertToExpressionType(self: MSPyECObjects.IECTypeAdapter, value: ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def ConvertToString(self: MSPyECObjects.IECTypeAdapter, str: MSPyBentley.WString, value: ECN.ECValue, context: MSPyECObjects.IECTypeAdapterContext, formatter: ECN.IECInstance = None) -> bool:
        ...
    
    def CreateDefaultFormatter(self: MSPyECObjects.IECTypeAdapter, includeAllValues: bool, forDwg: bool = False) -> ECN.IECInstance:
        ...
    
    def GetUnits(self: MSPyECObjects.IECTypeAdapter, unit: ECN.UnitSpec, context: MSPyECObjects.IECTypeAdapterContext) -> bool:
        ...
    
    def HasStandardValues(self: MSPyECObjects.IECTypeAdapter) -> bool:
        ...
    
    def IsStruct(self: MSPyECObjects.IECTypeAdapter) -> bool:
        ...
    
    def IsTreatedAsString(self: MSPyECObjects.IECTypeAdapter) -> bool:
        ...
    
    def PopulateDefaultFormatterProperties(self: MSPyECObjects.IECTypeAdapter, formatter: ECN.IECInstance) -> ECN.IECInstance:
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

    def LocateStandaloneEnabler(self: MSPyECObjects.IStandaloneEnablerLocater, schemaKey: MSPyECObjects.SchemaKey, className: str) -> ECN.StandaloneECEnabler:
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
    
    def SetInstance(self: MSPyECObjects.InstanceExpressionContext, instance: ECN.IECInstance) -> None:
        ...
    
    def SetInstances(self: MSPyECObjects.InstanceExpressionContext, instances: List[ECN.IECInstance]) -> None:
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
    
    def __init__(self: MSPyECObjects.InstanceListExpressionContext, instances: List[ECN.IECInstance], outer: MSPyECObjects.ExpressionContext = None) -> None:
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
    
class MainTaskNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.MainTaskNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.MainTaskNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.MainTaskNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.MainTaskNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.MainTaskNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
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
        
        :param source:
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
    
class MenuNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearAlternateNode(self: MSPyECObjects.MenuNode) -> None:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.MenuNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.MenuNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.MenuNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.MenuNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.MenuNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAlternateNode(self: MSPyECObjects.MenuNode) -> MSPyECObjects.MenuNode:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetAlternateNode(self: MSPyECObjects.MenuNode, node: MSPyECObjects.MenuNode) -> None:
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MethodSymbol:
    """
    None
    """

    @staticmethod
    def Create(*args, **kwargs):
        """
        Create(name: str, staticMethod: std::function<ECN::ExpressionStatus __cdecl(ECN::EvaluationResult & __ptr64,Bstdcxx::bvector<ECN::EvaluationResult,BentleyAllocator<ECN::EvaluationResult> > & __ptr64)>, instanceMethod: std::function<ECN::ExpressionStatus __cdecl(ECN::EvaluationResult & __ptr64,Bstdcxx::bvector<RefCountedPtr<ECN::IECInstance>,BentleyAllocator<RefCountedPtr<ECN::IECInstance> > > const & __ptr64,Bstdcxx::bvector<ECN::EvaluationResult,BentleyAllocator<ECN::EvaluationResult> > & __ptr64)>) -> MSPyECObjects.MethodSymbol
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class MiniToolbarNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.MiniToolbarNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.MiniToolbarNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.MiniToolbarNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.MiniToolbarNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.MiniToolbarNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class NameTreeNode:
    """
    None
    """

    def AddChild(self: MSPyECObjects.NameTreeNode, name: str, id: int = 0) -> MSPyECObjects.NameTreeNode:
        """
        Add a new child node a return pointer to it.
        
        :param name:
        The name of the child node to create.
        
        :param id:
        The ElementId of the child node. @Return a RefCounted pointer to
        the created node.
        """
        ...
    
    @staticmethod
    def CreateRootNode() -> MSPyECObjects.NameTreeNode:
        """
        Create the root node for a NameTree. @Return a RefCounted pointer to
        the created node.
        """
        ...
    
    def LocateChild(self: MSPyECObjects.NameTreeNode, name: str) -> MSPyECObjects.NameTreeNode:
        """
        Return a child node with a specific name.
        
        :param name:
        The name of the child node to locate.
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
    
    def EndArguments(self: MSPyECObjects.NodeVisitor, node: ECN.Node) -> bool:
        ...
    
    def EndArrayIndex(self: MSPyECObjects.NodeVisitor, node: ECN.Node) -> bool:
        ...
    
    def OpenParens(self: MSPyECObjects.NodeVisitor) -> bool:
        ...
    
    def ProcessNode(self: MSPyECObjects.NodeVisitor, node: ECN.Node) -> bool:
        ...
    
    def ProcessUnits(self: MSPyECObjects.NodeVisitor, units: ECN.UnitSpec) -> bool:
        ...
    
    def StartArguments(self: MSPyECObjects.NodeVisitor, node: ECN.Node) -> bool:
        ...
    
    def StartArrayIndex(self: MSPyECObjects.NodeVisitor, node: ECN.Node) -> bool:
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

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> ECN.StructECProperty:
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> ECN.ECClass:
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
    
    def GetClass(self: MSPyECObjects.ECProperty) -> ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    
    def GetTypeDescriptor(self: MSPyECObjects.PropertyLayout) -> ECN.ECTypeDescriptor:
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
    def TypeDescriptor(arg0: MSPyECObjects.PropertyLayout) -> ECN.ECTypeDescriptor:
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
    
    def FromAccessString(self: MSPyECObjects.QualifiedECAccessor, rootEnabler: ECN.ECEnabler, accessString: str) -> bool:
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
    
class QueryRelatedClassSpecifier:
    """
    None
    """

    @staticmethod
    def Create(*args, **kwargs):
        """
        Create(relationshipClass: MSPyECObjects.ECRelationshipClass, dc: MSPyECObjects.ECClass = None, dir: MSPyECObjects.ECRelatedInstanceDirection = <ECRelatedInstanceDirection.eSTRENGTHDIRECTION_Forward: 1>, isRelationshipPolyMorphic: bool = False, isRelatedPolyMorphic: bool = False, process: MSPyECObjects.ECQueryProcessFlags = <ECQueryProcessFlags.eECQUERY_PROCESS_SearchAllClasses: 6>) -> MSPyECObjects.QueryRelatedClassSpecifier
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
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
    
class RelationshipEntry:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    @property
    def relatedInstanceDirection(self: MSPyECObjects.RelationshipEntry) -> MSPyECObjects.ECRelatedInstanceDirection:
        ...
    @relatedInstanceDirection.setter
    def relatedInstanceDirection(self: MSPyECObjects.RelationshipEntry, arg0: MSPyECObjects.ECRelatedInstanceDirection) -> None:
        ...
    
    @property
    def relatedInstanceStrength(self: MSPyECObjects.RelationshipEntry) -> MSPyECObjects.StrengthType:
        ...
    @relatedInstanceStrength.setter
    def relatedInstanceStrength(self: MSPyECObjects.RelationshipEntry, arg0: MSPyECObjects.StrengthType) -> None:
        ...
    
    @property
    def relationshipClassName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @relationshipClassName.setter
    def relationshipClassName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def relationshipSchemaName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @relationshipSchemaName.setter
    def relationshipSchemaName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def sourceClassName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @sourceClassName.setter
    def sourceClassName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def sourceEH(self: MSPyECObjects.RelationshipEntry) -> MSPyDgnPlatform.ElementHandle:
        ...
    @sourceEH.setter
    def sourceEH(self: MSPyECObjects.RelationshipEntry, arg0: MSPyDgnPlatform.ElementHandle) -> None:
        ...
    
    @property
    def sourceElementId(self: MSPyECObjects.RelationshipEntry) -> int:
        ...
    @sourceElementId.setter
    def sourceElementId(self: MSPyECObjects.RelationshipEntry, arg0: int) -> None:
        ...
    
    @property
    def sourceInstanceId(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @sourceInstanceId.setter
    def sourceInstanceId(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def sourceModelName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @sourceModelName.setter
    def sourceModelName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def sourceSchemaName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @sourceSchemaName.setter
    def sourceSchemaName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def targetClassName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @targetClassName.setter
    def targetClassName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def targetEH(self: MSPyECObjects.RelationshipEntry) -> MSPyDgnPlatform.ElementHandle:
        ...
    @targetEH.setter
    def targetEH(self: MSPyECObjects.RelationshipEntry, arg0: MSPyDgnPlatform.ElementHandle) -> None:
        ...
    
    @property
    def targetElementId(self: MSPyECObjects.RelationshipEntry) -> int:
        ...
    @targetElementId.setter
    def targetElementId(self: MSPyECObjects.RelationshipEntry, arg0: int) -> None:
        ...
    
    @property
    def targetInstanceId(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @targetInstanceId.setter
    def targetInstanceId(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def targetModelName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @targetModelName.setter
    def targetModelName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
    @property
    def targetSchemaName(self: MSPyECObjects.RelationshipEntry) -> MSPyBentley.WString:
        ...
    @targetSchemaName.setter
    def targetSchemaName(self: MSPyECObjects.RelationshipEntry, arg0: MSPyBentley.WString) -> None:
        ...
    
class RelationshipEntryArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.RelationshipEntryArray) -> None
        
        2. __init__(self: MSPyECObjects.RelationshipEntryArray, arg0: MSPyECObjects.RelationshipEntryArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.RelationshipEntryArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.RelationshipEntryArray, x: MSPyECObjects.RelationshipEntry) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.RelationshipEntryArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.RelationshipEntryArray, L: MSPyECObjects.RelationshipEntryArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.RelationshipEntryArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.RelationshipEntryArray, i: int, x: MSPyECObjects.RelationshipEntry) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.RelationshipEntryArray) -> MSPyECObjects.RelationshipEntry
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.RelationshipEntryArray, i: int) -> MSPyECObjects.RelationshipEntry
        
        Remove and return the item at index ``i``
        """
        ...
    
class ReportCategoryNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    def CreateReportDefinition(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateReportDefinition(self: MSPyECObjects.ReportCategoryNode, name: str, sortPriority: int) -> MSPyECObjects.ReportDefinitionNode
        
        Creates and returns a new report definition with the specified name
        and priority
        
        2. CreateReportDefinition(self: MSPyECObjects.ReportCategoryNode, name: str, sortPriority: int, hideEmptyRow: bool) -> MSPyECObjects.ReportDefinitionNode
        
        Creates and returns a new report definition with the specified name
        and priority
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    @staticmethod
    def FindByName(name: str, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ReportCategoryNode:
        """
        Find a category node by name in the specified DgnFile
        """
        ...
    
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GenerateReportFromClass(self: MSPyECObjects.ReportCategoryNode, ecClass: MSPyECObjects.ECClass, name: str, sortPriority: int = -1) -> MSPyECObjects.ReportDefinitionNode:
        """
        Generates a report definition from an ECClass
        """
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ReportCategoryNode, node: MSPyECObjects.ECReportNode) -> None
        
        Extract a category node from an ECReportNode
        
        2. __init__(self: MSPyECObjects.ReportCategoryNode, name: str, sortPriority: int, dgnFile: MSPyDgnPlatform.DgnFile) -> None
        """
        ...
    
class ReportColumnAccessor:
    """
    None
    """

    @property
    def Accessor(arg0: MSPyECObjects.ReportColumnAccessor) -> MSPyECObjects.QualifiedECAccessor:
        ...
    
    class ArrayAccessor:
        """
        None
        """
    
        @property
        def AccessString(arg0: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> str:
            ...
        
        def GetAccessString(self: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> str:
            ...
        
        def GetOption(self: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> MSPyECObjects.ReportColumnAccessor.ArrayOption:
            ...
        
        @property
        def Option(arg0: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> MSPyECObjects.ReportColumnAccessor.ArrayOption:
            ...
        
        def __init__(*args, **kwargs):
            """
            Overloaded function.
            
            1. __init__(self: MSPyECObjects.ReportColumnAccessor.ArrayAccessor) -> None
            
            2. __init__(self: MSPyECObjects.ReportColumnAccessor.ArrayAccessor, memberAccessor: str, option: MSPyECObjects.ReportColumnAccessor.ArrayOption = <ArrayOption.eNone: 0>) -> None
            """
            ...
        
    @property
    def ArrayAccessors(arg0: MSPyECObjects.ReportColumnAccessor) -> MSPyECObjects.ArrayAccessorArray:
        ...
    
    class ArrayOption:
        """
        Members:
        
        eAllMembers
        
        eFirst
        
        eLast
        
        eCount
        
        eList
        
        eNone
        """
    
        def __init__(self: MSPyECObjects.ReportColumnAccessor.ArrayOption, value: int) -> None:
            ...
        
        eAllMembers: ArrayOption
        
        eCount: ArrayOption
        
        eFirst: ArrayOption
        
        eLast: ArrayOption
        
        eList: ArrayOption
        
        eNone: ArrayOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ReportColumnAccessor.ArrayOption) -> int:
            ...
        
    def GetAccessor(self: MSPyECObjects.ReportColumnAccessor) -> MSPyECObjects.QualifiedECAccessor:
        """
        Returns the accessor for the root ECPropertyValue
        """
        ...
    
    def GetArrayAccessors(self: MSPyECObjects.ReportColumnAccessor) -> MSPyECObjects.ArrayAccessorArray:
        """
        Returns the list of accessors for struct array members.
        """
        ...
    
    def GetArrayOption(self: MSPyECObjects.ReportColumnAccessor) -> MSPyECObjects.ReportColumnAccessor.ArrayOption:
        """
        Returns the options for handling the root ECPropertyValue as an array
        property
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ReportColumnAccessor) -> None
        
        2. __init__(self: MSPyECObjects.ReportColumnAccessor, accessor: MSPyECObjects.QualifiedECAccessor, option: MSPyECObjects.ReportColumnAccessor.ArrayOption = <ArrayOption.eNone: 0>) -> None
        
        3. __init__(self: MSPyECObjects.ReportColumnAccessor, schemaName: str, className: str, accessString: str, option: MSPyECObjects.ReportColumnAccessor.ArrayOption = <ArrayOption.eNone: 0>) -> None
        """
        ...
    
    eAllMembers: ArrayOption
    
    eCount: ArrayOption
    
    eFirst: ArrayOption
    
    eLast: ArrayOption
    
    eList: ArrayOption
    
    eNone: ArrayOption
    
class ReportColumnAccessorArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ReportColumnAccessorArray) -> None
        
        2. __init__(self: MSPyECObjects.ReportColumnAccessorArray, arg0: MSPyECObjects.ReportColumnAccessorArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.ReportColumnAccessorArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.ReportColumnAccessorArray, x: MSPyECObjects.ReportColumnAccessor) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.ReportColumnAccessorArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.ReportColumnAccessorArray, L: MSPyECObjects.ReportColumnAccessorArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.ReportColumnAccessorArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.ReportColumnAccessorArray, i: int, x: MSPyECObjects.ReportColumnAccessor) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.ReportColumnAccessorArray) -> MSPyECObjects.ReportColumnAccessor
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.ReportColumnAccessorArray, i: int) -> MSPyECObjects.ReportColumnAccessor
        
        Remove and return the item at index ``i``
        """
        ...
    
class ReportDefinitionCollection:
    """
    None
    """

    @property
    def Count(arg0: MSPyECObjects.ReportDefinitionCollection) -> int:
        ...
    
    def GetReportDefinitionAt(self: MSPyECObjects.ReportDefinitionCollection, index: int) -> MSPyECObjects.ReportDefinitionNode:
        ...
    
    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.ReportDefinitionCollection) -> None
        
        2. __init__(self: MSPyECObjects.ReportDefinitionCollection, dgnFile: MSPyDgnPlatform.DgnFile) -> None
        """
        ...
    
class ReportDefinitionNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def Category(arg0: MSPyECObjects.ReportDefinitionNode) -> MSPyDgnPlatform.ReportCategoryNode:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    @property
    def ColumnCount(arg0: MSPyECObjects.ReportDefinitionNode) -> int:
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    def CreateColumnDefinition(self: MSPyECObjects.ReportDefinitionNode, name: str, sortPriority: int) -> MSPyECObjects.ColumnDefinitionNode:
        """
        Creates and returns a new column definition with the specified name
        and priority
        """
        ...
    
    def CreateSortingRule(self: MSPyECObjects.ReportDefinitionNode, columnName: str, sortPriority: int) -> MSPyECObjects.SortingRuleNode:
        """
        Creates and returns a new sorting rule with the specified name and
        priority. The name must refer to an existing ColumnDefinitionNode
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    @staticmethod
    def FindById(id: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ReportDefinitionNode:
        """
        Locate a report definition by ID within the specified DgnFile
        """
        ...
    
    @staticmethod
    def FindByPath(path: str, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ReportDefinitionNode:
        """
        Locate a report definition by its full path (including category name)
        within the specified DgnFile
        """
        ...
    
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetCategory(self: MSPyECObjects.ReportDefinitionNode) -> MSPyDgnPlatform.ReportCategoryNode:
        """
        Returns the category node containing this report definition
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetColumnByName(self: MSPyECObjects.ReportDefinitionNode, name: str) -> MSPyECObjects.ColumnDefinitionNode:
        """
        Returns the column definition with the specified name
        """
        ...
    
    def GetColumnCount(self: MSPyECObjects.ReportDefinitionNode) -> int:
        """
        Returns the number of columns defined for this report definition
        """
        ...
    
    def GetColumnGroupNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetColumnGroupNode(self: MSPyECObjects.ReportDefinitionNode, createIfNotFound: bool) -> MSPyDgnPlatform.ColumnGroupNode
        
        Returns the node which holds this report definition's column
        definitions
        
        2. GetColumnGroupNode(self: MSPyECObjects.ReportDefinitionNode) -> MSPyDgnPlatform.ColumnGroupNode
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetHostSpecifications(self: MSPyECObjects.ReportDefinitionNode, specs: MSPyECObjects.DgnECHostSpecificationArray) -> bool:
        """
        Extracts the specifications which define the ECInstances which will be
        included in the report results
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetIncludeItemTypeOption(self: MSPyECObjects.ReportDefinitionNode) -> MSPyECObjects.ReportScope.IncludeItemTypeOption:
        """
        Get IncludeItemTypeOption which is used for selecting used or
        all/unreferenced classes for report. Returns the IncludeItemTypeOption
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetRowFilter(self: MSPyECObjects.ReportDefinitionNode) -> MSPyBentley.WString:
        """
        Returns the ECExpression which is used to filter out rows of the
        report results based on their ECPropertyValues
        """
        ...
    
    def GetScope(self: MSPyECObjects.ReportDefinitionNode) -> MSPyECObjects.ReportScope:
        """
        Returns the scope which will be searched to find ECInstances from
        which to populated the report results
        """
        ...
    
    def GetScopeType(self: MSPyECObjects.ReportDefinitionNode) -> MSPyECObjects.ReportScope.Type:
        """
        Returns the type of this report definition's scope.
        """
        ...
    
    def GetSelectionScopeOption(self: MSPyECObjects.ReportDefinitionNode) -> MSPyECObjects.ReportScope.SelectionScopeOption:
        """
        Get SelectionScopeOption which is used for report all, by fence, or by
        current selection Returns the SelectionScopeOption
        """
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetSortingGroupNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetSortingGroupNode(self: MSPyECObjects.ReportDefinitionNode, createIfNotFound: bool) -> MSPyDgnPlatform.SortingGroupNode
        
        Returns the node which holds this report definition's sorting rules
        
        2. GetSortingGroupNode(self: MSPyECObjects.ReportDefinitionNode) -> MSPyDgnPlatform.SortingGroupNode
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    def Import(self: MSPyECObjects.ReportDefinitionNode, destDgnFile: MSPyDgnPlatform.DgnFile, renameIfNecessary: bool) -> MSPyECObjects.ReportDefinitionNode:
        """
        Imports this definition into the specified DgnFile, renaming it if
        necessary
        """
        ...
    
    def IsReferenced(self: MSPyECObjects.ReportDefinitionNode) -> bool:
        """
        Returns true if any TextTable elements exist with an association to
        this report definition
        """
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    @property
    def RowFilter(arg0: MSPyECObjects.ReportDefinitionNode) -> MSPyBentley.WString:
        ...
    @RowFilter.setter
    def RowFilter(arg0: MSPyECObjects.ReportDefinitionNode, arg1: str) -> bool:
        ...
    
    @property
    def ScopeType(arg0: MSPyECObjects.ReportDefinitionNode) -> MSPyECObjects.ReportScope.Type:
        ...
    
    def SetHostSpecifications(self: MSPyECObjects.ReportDefinitionNode, specs: MSPyECObjects.DgnECHostSpecificationArray) -> bool:
        """
        Sets the specifications which define the ECInstances which will be
        included in the report results
        """
        ...
    
    def SetIncludeItemTypeOption(self: MSPyECObjects.ReportDefinitionNode, option: MSPyECObjects.ReportScope.IncludeItemTypeOption) -> int:
        """
        Set IncludeItemTypeOption which is used for selecting used or
        all/unreferenced classes for report.
        
        :param IncludeItemTypeOption:
        the IncludeItemTypeOption to be set
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetRowFilter(self: MSPyECObjects.ReportDefinitionNode, expr: str) -> bool:
        """
        Sets the ECExpression which is used to filter out rows of the report
        results based on their ECPropertyValues
        """
        ...
    
    def SetScope(self: MSPyECObjects.ReportDefinitionNode, scope: MSPyECObjects.ReportScope) -> bool:
        """
        Returns the scope which will be searched to find ECInstances from
        which to populated the report results
        """
        ...
    
    def SetSelectionScopeOption(self: MSPyECObjects.ReportDefinitionNode, option: MSPyECObjects.ReportScope.SelectionScopeOption) -> int:
        """
        Set SelectionScopeOption which is used for report all, by fence, or by
        current selection
        
        :param selectionScopeOption:
        the SelectionScopeOption to be set
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(self: MSPyECObjects.ReportDefinitionNode, node: MSPyECObjects.ECReportNode) -> None:
        """
        Extracts a ReportDefinitionNode from an ECReportNode
        """
        ...
    
class ReportResults:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ReportResultsEntry:
    """
    None
    """

    @property
    def Content(arg0: MSPyECObjects.ReportResultsEntry) -> MSPyBentley.WString:
        ...
    
    def GetContent(self: MSPyECObjects.ReportResultsEntry) -> MSPyBentley.WString:
        ...
    
    def GetSourceAccessor(self: MSPyECObjects.ReportResultsEntry) -> MSPyECObjects.ReportColumnAccessor:
        ...
    
    def GetSourceFileName(self: MSPyECObjects.ReportResultsEntry) -> MSPyBentley.WString:
        ...
    
    def GetSourceInstanceId(self: MSPyECObjects.ReportResultsEntry) -> MSPyBentley.WString:
        ...
    
    @property
    def SourceAccessor(arg0: MSPyECObjects.ReportResultsEntry) -> MSPyECObjects.ReportColumnAccessor:
        ...
    
    @property
    def SourceFileName(arg0: MSPyECObjects.ReportResultsEntry) -> MSPyBentley.WString:
        ...
    
    @property
    def SourceInstanceId(arg0: MSPyECObjects.ReportResultsEntry) -> MSPyBentley.WString:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ReportScope:
    """
    None
    """

    def GetIncludeItemTypeOption(self: MSPyECObjects.ReportScope) -> MSPyECObjects.ReportScope.IncludeItemTypeOption:
        """
        Get IncludeItemTypeOption which is used for selecting used or
        all/unreferenced classes for report. Returns the IncludeItemTypeOption
        """
        ...
    
    def GetLocation(self: MSPyECObjects.ReportScope) -> str:
        """
        Returns the location associated with this scope
        """
        ...
    
    def GetQualifier(self: MSPyECObjects.ReportScope) -> str:
        """
        Returns the " location qualifier " associated with this scope's
        location. Usually the name of a DgnModel.
        """
        ...
    
    def GetReferencedModelOption(self: MSPyECObjects.ReportScope) -> MSPyECObjects.ReportScope.ReferencedModelOption:
        """
        Returns the options for searching reference attachments for
        ReportScope.Type.Model
        """
        ...
    
    def GetSelectionScopeOption(self: MSPyECObjects.ReportScope) -> MSPyECObjects.ReportScope.SelectionScopeOption:
        """
        Get SelectionScopeOption which is used for report all, by fence, or by
        current selection Returns the SelectionScopeOption
        """
        ...
    
    def GetType(self: MSPyECObjects.ReportScope) -> MSPyECObjects.ReportScope.Type:
        """
        Returns the type of this ReportScope
        """
        ...
    
    class IncludeItemTypeOption:
        """
        Members:
        
        eIncludeUsedClasses
        
        eIncludeAllClasses
        """
    
        def __init__(self: MSPyECObjects.ReportScope.IncludeItemTypeOption, value: int) -> None:
            ...
        
        eIncludeAllClasses: IncludeItemTypeOption
        
        eIncludeUsedClasses: IncludeItemTypeOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ReportScope.IncludeItemTypeOption) -> int:
            ...
        
    def IncludesChildElements(self: MSPyECObjects.ReportScope) -> bool:
        """
        Returns whether public children of complex elements will be searched
        when populating report results
        """
        ...
    
    def InitForActiveModel(*args, **kwargs):
        """
        InitForActiveModel(self: MSPyECObjects.ReportScope, refOut: MSPyECObjects.ReportScope.ReferencedModelOption = <ReferencedModelOption.eNone: 2>) -> None
        
        Initializes a ReportScope for the active model
        """
        ...
    
    def InitForDefaultModel(*args, **kwargs):
        """
        InitForDefaultModel(self: MSPyECObjects.ReportScope, moniker: MSPyDgnPlatform.DgnDocumentMoniker, refOut: MSPyECObjects.ReportScope.ReferencedModelOption = <ReferencedModelOption.eNone: 2>) -> None
        
        Initializes a ReportScope for the default model. If moniker is null,
        refers to the active file.
        """
        ...
    
    def InitForFile(self: MSPyECObjects.ReportScope, moniker: MSPyDgnPlatform.DgnDocumentMoniker) -> None:
        """
        Initializes a ReportScope based on the active file (if moniker is
        null), or the file specified by the moniker
        """
        ...
    
    def InitForModel(*args, **kwargs):
        """
        InitForModel(self: MSPyECObjects.ReportScope, modelName: str, moniker: MSPyDgnPlatform.DgnDocumentMoniker, refOut: MSPyECObjects.ReportScope.ReferencedModelOption = <ReferencedModelOption.eNone: 2>) -> None
        
        Initializes a ReportScope for a specific model identified by name. If
        moniker is null, refers to the active file.
        """
        ...
    
    def InitForPath(self: MSPyECObjects.ReportScope, cfgVarExpression: str) -> None:
        """
        Initializes a path-based ReportScope for the specified configuration
        variable expression
        """
        ...
    
    @property
    def Location(arg0: MSPyECObjects.ReportScope) -> str:
        ...
    
    @property
    def Qualifier(arg0: MSPyECObjects.ReportScope) -> str:
        ...
    
    class ReferencedModelOption:
        """
        Members:
        
        eAll
        
        eNone
        """
    
        def __init__(self: MSPyECObjects.ReportScope.ReferencedModelOption, value: int) -> None:
            ...
        
        eAll: ReferencedModelOption
        
        eNone: ReferencedModelOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ReportScope.ReferencedModelOption) -> int:
            ...
        
    class ReportSummaryOption:
        """
        Members:
        
        eShow
        
        eHide
        """
    
        def __init__(self: MSPyECObjects.ReportScope.ReportSummaryOption, value: int) -> None:
            ...
        
        eHide: ReportSummaryOption
        
        eShow: ReportSummaryOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ReportScope.ReportSummaryOption) -> int:
            ...
        
    class SelectionScopeOption:
        """
        Members:
        
        eAll
        
        eByFence
        
        eCurrentSelection
        """
    
        def __init__(self: MSPyECObjects.ReportScope.SelectionScopeOption, value: int) -> None:
            ...
        
        eAll: SelectionScopeOption
        
        eByFence: SelectionScopeOption
        
        eCurrentSelection: SelectionScopeOption
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ReportScope.SelectionScopeOption) -> int:
            ...
        
    def SetIncludeChildElements(self: MSPyECObjects.ReportScope, include: bool) -> None:
        """
        Sets whether public children of complex elements will be searched when
        populating report results
        """
        ...
    
    def SetIncludeItemTypeOption(self: MSPyECObjects.ReportScope, options: MSPyECObjects.ReportScope.IncludeItemTypeOption) -> None:
        """
        Set SetIncludeItemTypeOption which is used for selecting used or
        all/unreferenced classes for report.
        
        :param includeItemTypeOption:
        the IncludeItemTypeOption to be set
        """
        ...
    
    def SetReferencedModelOption(self: MSPyECObjects.ReportScope, opt: MSPyECObjects.ReportScope.ReferencedModelOption) -> None:
        """
        Sets how reference attachments will be searched for
        ReportScope.Type.Model
        """
        ...
    
    def SetSelectionScopeOption(self: MSPyECObjects.ReportScope, options: MSPyECObjects.ReportScope.SelectionScopeOption) -> None:
        """
        Set SelectionScopeOption which is used for report all, by fence, or by
        current selection
        
        :param selectionScopeOption:
        the SelectionScopeOption to be set
        """
        ...
    
    class Type:
        """
        Members:
        
        eModel
        
        eFile
        
        ePath
        """
    
        def __init__(self: MSPyECObjects.ReportScope.Type, value: int) -> None:
            ...
        
        eFile: Type
        
        eModel: Type
        
        ePath: Type
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.ReportScope.Type) -> int:
            ...
        
    def __init__(self: MSPyECObjects.ReportScope) -> None:
        ...
    
    eAll: SelectionScopeOption
    
    eByFence: SelectionScopeOption
    
    eCurrentSelection: SelectionScopeOption
    
    eFile: Type
    
    eHide: ReportSummaryOption
    
    eIncludeAllClasses: IncludeItemTypeOption
    
    eIncludeUsedClasses: IncludeItemTypeOption
    
    eModel: Type
    
    eNone: ReferencedModelOption
    
    ePath: Type
    
    eShow: ReportSummaryOption
    
class SchemaDeleteStatus:
    """
    Members:
    
    eSCHEMADELETE_Success
    
    eSCHEMADELETE_SchemaNotFound
    
    eSCHEMADELETE_ProviderNotFound
    
    eSCHEMADELETE_ProviderDoesNotSupportDelete
    
    eSCHEMADELETE_SchemaHasStoredInstances
    
    eSCHEMADELETE_SchemaIsReferenced
    
    eSCHEMADELETE_FailedToDeleteSchemaElement
    """

    def __init__(self: MSPyECObjects.SchemaDeleteStatus, value: int) -> None:
        ...
    
    eSCHEMADELETE_FailedToDeleteSchemaElement: SchemaDeleteStatus
    
    eSCHEMADELETE_ProviderDoesNotSupportDelete: SchemaDeleteStatus
    
    eSCHEMADELETE_ProviderNotFound: SchemaDeleteStatus
    
    eSCHEMADELETE_SchemaHasStoredInstances: SchemaDeleteStatus
    
    eSCHEMADELETE_SchemaIsReferenced: SchemaDeleteStatus
    
    eSCHEMADELETE_SchemaNotFound: SchemaDeleteStatus
    
    eSCHEMADELETE_Success: SchemaDeleteStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SchemaDeleteStatus) -> int:
        ...
    
class SchemaImportStatus:
    """
    Members:
    
    eSCHEMAIMPORT_Success
    
    eSCHEMAIMPORT_SchemaAlreadyStoredInFile
    
    eSCHEMAIMPORT_NotValidECSchemaXml
    
    eSCHEMAIMPORT_FailedToWriteElement
    
    eSCHEMAIMPORT_FailedToSerializeAsXml
    
    eSCHEMAIMPORT_ProviderDoesNotSupportImport
    
    eSCHEMAIMPORT_ProviderNotFound
    
    eSCHEMAIMPORT_FailedToDeserializeXmlFile
    
    eSCHEMAIMPORT_InvalidUserDefinedSchema
    """

    def __init__(self: MSPyECObjects.SchemaImportStatus, value: int) -> None:
        ...
    
    eSCHEMAIMPORT_FailedToDeserializeXmlFile: SchemaImportStatus
    
    eSCHEMAIMPORT_FailedToSerializeAsXml: SchemaImportStatus
    
    eSCHEMAIMPORT_FailedToWriteElement: SchemaImportStatus
    
    eSCHEMAIMPORT_InvalidUserDefinedSchema: SchemaImportStatus
    
    eSCHEMAIMPORT_NotValidECSchemaXml: SchemaImportStatus
    
    eSCHEMAIMPORT_ProviderDoesNotSupportImport: SchemaImportStatus
    
    eSCHEMAIMPORT_ProviderNotFound: SchemaImportStatus
    
    eSCHEMAIMPORT_SchemaAlreadyStoredInFile: SchemaImportStatus
    
    eSCHEMAIMPORT_Success: SchemaImportStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SchemaImportStatus) -> int:
        ...
    
class SchemaInfo:
    """
    None
    """

    @property
    def DgnFile(arg0: MSPyECObjects.SchemaInfo) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def ElementCheckSum(arg0: MSPyECObjects.SchemaInfo) -> int:
        ...
    @ElementCheckSum.setter
    def ElementCheckSum(arg0: MSPyECObjects.SchemaInfo, arg1: int) -> None:
        ...
    
    def GetDgnFile(self: MSPyECObjects.SchemaInfo) -> MSPyDgnPlatform.DgnFile:
        """
        The Dgnfile through which this schema info was found.
        """
        ...
    
    def GetElementCheckSum(self: MSPyECObjects.SchemaInfo) -> int:
        """
        Get the checksum of the schema stored on the element
        """
        ...
    
    def GetLocation(self: MSPyECObjects.SchemaInfo) -> str:
        """
        Get the location of the schema if external.
        """
        ...
    
    def GetProviderName(self: MSPyECObjects.SchemaInfo) -> str:
        """
        Get the provider associated with this schema
        """
        ...
    
    def GetSchemaKey(self: MSPyECObjects.SchemaInfo) -> MSPyECObjects.SchemaKey:
        """
        Get the schema key
        """
        ...
    
    def GetSchemaName(self: MSPyECObjects.SchemaInfo) -> str:
        """
        Get the schema name
        """
        ...
    
    def IsStoredSchema(self: MSPyECObjects.SchemaInfo) -> bool:
        """
        Test whether the schema is persisted to the file.
        """
        ...
    
    @property
    def Location(arg0: MSPyECObjects.SchemaInfo) -> str:
        ...
    @Location.setter
    def Location(arg0: MSPyECObjects.SchemaInfo, arg1: str) -> None:
        ...
    
    @property
    def ProviderName(arg0: MSPyECObjects.SchemaInfo) -> str:
        ...
    @ProviderName.setter
    def ProviderName(arg0: MSPyECObjects.SchemaInfo, arg1: str) -> None:
        ...
    
    @property
    def SchemaKey(arg0: MSPyECObjects.SchemaInfo) -> MSPyECObjects.SchemaKey:
        ...
    
    @property
    def SchemaName(arg0: MSPyECObjects.SchemaInfo) -> str:
        ...
    @SchemaName.setter
    def SchemaName(arg0: MSPyECObjects.SchemaInfo, arg1: str) -> None:
        ...
    
    def SetElementCheckSum(self: MSPyECObjects.SchemaInfo, checkSum: int) -> None:
        """
        Set CheckSum value
        
        :param checkSum:
        Used to determine if schemas with same name and version are really
        the same.
        """
        ...
    
    def SetLocation(self: MSPyECObjects.SchemaInfo, location: str) -> None:
        """
        Set location
        
        :param location:
        Specifies the filename that held the schema
        """
        ...
    
    def SetProviderName(self: MSPyECObjects.SchemaInfo, providerName: str) -> None:
        """
        Set provider name
        
        :param providerName:
        Specifies the provider name that handles data from the schema
        (ECXAttributes/ECXData).
        """
        ...
    
    def SetSchemaName(self: MSPyECObjects.SchemaInfo, schemaName: str) -> None:
        """
        Set schema name
        
        :param schemaName:
        Schema name.
        """
        ...
    
    def SetStoredSchema(self: MSPyECObjects.SchemaInfo, isStoredSchema: bool) -> None:
        """
        Set Stored value
        
        :param isStoredSchema:
        Used to determine if schemas was stored in the design file.
        """
        ...
    
    def SetVersionMajor(self: MSPyECObjects.SchemaInfo, versionMajor: int) -> None:
        """
        Set major version number
        
        :param versionMajor:
        Major version number.
        """
        ...
    
    def SetVersionMinor(self: MSPyECObjects.SchemaInfo, versionMinor: int) -> None:
        """
        Set minor version number
        
        :param versionMinor:
        Minor version number.
        """
        ...
    
    @property
    def StoredSchema(arg0: MSPyECObjects.SchemaInfo) -> bool:
        ...
    @StoredSchema.setter
    def StoredSchema(arg0: MSPyECObjects.SchemaInfo, arg1: bool) -> None:
        ...
    
    def __init__(self: MSPyECObjects.SchemaInfo, schemaKey: MSPyECObjects.SchemaKey, dgnFile: MSPyDgnPlatform.DgnFile, providerName: str = '', location: str = '', checkSum: int = 0, storedSchema: bool = False) -> None:
        ...
    
class SchemaInfoArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SchemaInfoArray) -> None
        
        2. __init__(self: MSPyECObjects.SchemaInfoArray, arg0: MSPyECObjects.SchemaInfoArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.SchemaInfoArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.SchemaInfoArray, x: MSPyECObjects.SchemaInfo) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.SchemaInfoArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.SchemaInfoArray, x: MSPyECObjects.SchemaInfo) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.SchemaInfoArray, L: MSPyECObjects.SchemaInfoArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.SchemaInfoArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.SchemaInfoArray, i: int, x: MSPyECObjects.SchemaInfo) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.SchemaInfoArray) -> MSPyECObjects.SchemaInfo
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.SchemaInfoArray, i: int) -> MSPyECObjects.SchemaInfo
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.SchemaInfoArray, x: MSPyECObjects.SchemaInfo) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
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

    def AddClassLayout(self: MSPyECObjects.SchemaLayout, classLayout: MSPyECObjects.ClassLayout, classIndex: int) -> BentleyStatus:
        """
        Adds the ClassLayout at the given index
        
        :param classLayout:
        The ClassLayout to add
        
        :param classIndex:
        The index where to add the ClassLayout
        
        :returns:
        ERROR if a class layout already exists with the given index
        """
        ...
    
    def FindAvailableClassIndex(self: MSPyECObjects.SchemaLayout) -> tuple:
        """
        Finds the first available index for adding a class layout
        
        
        Returns (Tuple, 0):
        SUCCESS if the index is found, ERROR otherwise
        
        Returns (Tuple, 1):
        classIndex. The first available index in the layout. This is not necessarily
        the size of the layout because there can be gaps.
        """
        ...
    
    def FindClassIndex(self: MSPyECObjects.SchemaLayout, className: str) -> tuple:
        """
        Given a classname, tries to find the index of the corresponding
        ClassLayout
        
        
        :param className:
        The name of the class to find the ClassLayout index of
        
        Returns (Tuple, 0):
        A pointer to the corresponding ClassLayout if found, NULL
        otherwise
        
        Returns (Tuple, 1):
        classIndex. The index of the corresponding ClassLayout, if found
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
        
        :param classIndex:
        The index of the desired ClassLayout
        
        :returns:
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
    
    def ReplaceClassLayout(self: MSPyECObjects.SchemaLayout, classLayout: MSPyECObjects.ClassLayout, classIndex: int) -> BentleyStatus:
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
    
class SchemaUpdateStatus:
    """
    Members:
    
    eSCHEMAUPDATE_Success
    
    eSCHEMAUPDATE_SchemaNotFound
    
    eSCHEMAUPDATE_NotValidECSchemaXml
    
    eSCHEMAUPDATE_FailedToWriteElement
    
    eSCHEMAUPDATE_FailedToSerializeAsXml
    
    eSCHEMAUPDATE_ProviderDoesNotSupportUpdate
    
    eSCHEMAUPDATE_ProviderNotFound
    
    eSCHEMAUPDATE_FailedToDeserializeXmlFile
    
    eSCHEMAUPDATE_SchemaVersionMismatch
    
    eSCHEMAUPDATE_ProviderDoesNotSupportInstanceUpdate
    
    eSCHEMAUPDATE_FailedToUpdateInstances
    
    eSCHEMAUPDATE_FailedToUpdateReferencingSchemas
    """

    def __init__(self: MSPyECObjects.SchemaUpdateStatus, value: int) -> None:
        ...
    
    eSCHEMAUPDATE_FailedToDeserializeXmlFile: SchemaUpdateStatus
    
    eSCHEMAUPDATE_FailedToSerializeAsXml: SchemaUpdateStatus
    
    eSCHEMAUPDATE_FailedToUpdateInstances: SchemaUpdateStatus
    
    eSCHEMAUPDATE_FailedToUpdateReferencingSchemas: SchemaUpdateStatus
    
    eSCHEMAUPDATE_FailedToWriteElement: SchemaUpdateStatus
    
    eSCHEMAUPDATE_NotValidECSchemaXml: SchemaUpdateStatus
    
    eSCHEMAUPDATE_ProviderDoesNotSupportInstanceUpdate: SchemaUpdateStatus
    
    eSCHEMAUPDATE_ProviderDoesNotSupportUpdate: SchemaUpdateStatus
    
    eSCHEMAUPDATE_ProviderNotFound: SchemaUpdateStatus
    
    eSCHEMAUPDATE_SchemaNotFound: SchemaUpdateStatus
    
    eSCHEMAUPDATE_SchemaVersionMismatch: SchemaUpdateStatus
    
    eSCHEMAUPDATE_Success: SchemaUpdateStatus
    
    @property
    def name(self: handle) -> str:
        ...
    
    @property
    def value(arg0: MSPyECObjects.SchemaUpdateStatus) -> int:
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
    
class SearchClass:
    """
    None
    """

    def __init__(self: MSPyECObjects.SearchClass, schemaName: MSPyBentley.WString, className: MSPyBentley.WString, isPoly: bool) -> None:
        ...
    
class SearchClassArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SearchClassArray) -> None
        
        2. __init__(self: MSPyECObjects.SearchClassArray, arg0: MSPyECObjects.SearchClassArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.SearchClassArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.SearchClassArray, x: MSPyECObjects.SearchClass) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.SearchClassArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.SearchClassArray, L: MSPyECObjects.SearchClassArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.SearchClassArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.SearchClassArray, i: int, x: MSPyECObjects.SearchClass) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.SearchClassArray) -> MSPyECObjects.SearchClass
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.SearchClassArray, i: int) -> MSPyECObjects.SearchClass
        
        Remove and return the item at index ``i``
        """
        ...
    
class SelectedProperties:
    """
    None
    """

    def AddPropertyNameToSelect(self: MSPyECObjects.SelectedProperties, accessString: str) -> None:
        """
        Adds a property name to select/populate in the DgnECInstance.
        Currently only ECXA Instances support partial instance loading.
        
        :param accessString:
        Property name to select
        """
        ...
    
    def Duplicate(self: MSPyECObjects.SelectedProperties) -> MSPyECObjects.SelectedProperties:
        """
        Create a deep copy
        """
        ...
    
    def __init__(self: MSPyECObjects.SelectedProperties, selectAllProperties: bool = False) -> None:
        ...
    
class SortingGroupNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    def CreateSortingRule(self: MSPyECObjects.SortingGroupNode, columnName: str, priority: int) -> MSPyECObjects.SortingRuleNode:
        """
        Creates and returns a new sorting rule. The column name must refer to
        an existing column definition
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetRuleForColumn(self: MSPyECObjects.SortingGroupNode, arg0: str) -> MSPyECObjects.SortingRuleNode:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetSortingRules(self: MSPyECObjects.SortingGroupNode) -> MSPyECObjects.SortingRuleNodePtrArray:
        """
        Returns the list of sorting rules
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    @property
    def SortingRules(arg0: MSPyECObjects.SortingGroupNode) -> MSPyECObjects.SortingRuleNodePtrArray:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(self: MSPyECObjects.SortingGroupNode, node: MSPyECObjects.ECReportNode) -> None:
        ...
    
class SortingRuleNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ApplyBeforeFormatting(self: MSPyECObjects.SortingRuleNode) -> bool:
        """
        Returns whether the values are sorted by their internal values, or
        their (string) display values
        """
        ...
    
    @property
    def Ascending(arg0: MSPyECObjects.SortingRuleNode) -> bool:
        ...
    @Ascending.setter
    def Ascending(arg0: MSPyECObjects.SortingRuleNode, arg1: bool) -> bool:
        ...
    
    @property
    def AssociatedReportDefinition(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        ...
    
    @property
    def CaseSensitive(arg0: MSPyECObjects.SortingRuleNode) -> bool:
        ...
    @CaseSensitive.setter
    def CaseSensitive(arg0: MSPyECObjects.SortingRuleNode, arg1: bool) -> bool:
        ...
    
    @property
    def ChildNodes(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    @property
    def ColumnName(arg0: MSPyECObjects.SortingRuleNode) -> str:
        ...
    @ColumnName.setter
    def ColumnName(arg0: MSPyECObjects.SortingRuleNode, arg1: str) -> bool:
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @property
    def DgnFile(arg0: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        ...
    
    @property
    def DisplayLabel(arg0: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(*args, **kwargs):
        """
        Overloaded function.
        
        1. FindByElementId(elemId: int, dgnFile: MSPyDgnPlatform.DgnFile) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        
        2. FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ECReportNode
        
        Locates a node by its ID
        """
        ...
    
    def FromXDataTreeNode(node: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ECReportNode:
        """
        Extracts an ECReportNode from an XDataTreeNode
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetAssociatedReportDefinition(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.ReportDefinitionNode:
        """
        Returns the ReportDefinitionNode associated with this node, or nullptr
        if this is a category node.
        """
        ...
    
    def GetChildByName(self: MSPyECObjects.ECReportNode, name: str) -> MSPyECObjects.ECReportNode:
        """
        Returns the child node with the specified name
        """
        ...
    
    def GetChildNodes(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodePtrArray:
        """
        Returns a list of this node's child nodes
        """
        ...
    
    def GetColumnName(self: MSPyECObjects.SortingRuleNode) -> str:
        """
        Returns the name of the column to which this sorting rule applies
        """
        ...
    
    def GetDgnFile(self: MSPyECObjects.ECReportNode) -> MSPyDgnPlatform.DgnFile:
        """
        Returns the DgnFile in which this node resides
        """
        ...
    
    def GetDisplayLabel(self: MSPyECObjects.ECReportNode) -> MSPyBentley.WString:
        """
        Returns the display label for this node
        """
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        """
        Returns the type of this node
        """
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetParentNode(self: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        """
        Returns the parent of this node, if any
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    def HideDuplicateValues(self: MSPyECObjects.SortingRuleNode) -> bool:
        """
        Returns whether successive rows with identical values will be shown as
        empty
        """
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def IsApplyBeforeFormatting(arg0: MSPyECObjects.SortingRuleNode) -> bool:
        ...
    @IsApplyBeforeFormatting.setter
    def IsApplyBeforeFormatting(arg0: MSPyECObjects.SortingRuleNode, arg1: bool) -> bool:
        ...
    
    def IsAscending(self: MSPyECObjects.SortingRuleNode) -> bool:
        """
        Returns whether the sorting is performed in ascending order
        """
        ...
    
    def IsCaseSensitive(self: MSPyECObjects.SortingRuleNode) -> bool:
        """
        Returns whether the sorting is applied with case-sensitivity
        """
        ...
    
    @property
    def IsHideDuplicateValues(arg0: MSPyECObjects.SortingRuleNode) -> bool:
        ...
    @IsHideDuplicateValues.setter
    def IsHideDuplicateValues(arg0: MSPyECObjects.SortingRuleNode, arg1: bool) -> bool:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def NodeType(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNodeType:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def ParentNode(arg0: MSPyECObjects.ECReportNode) -> MSPyECObjects.ECReportNode:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetApplyBeforeFormatting(self: MSPyECObjects.SortingRuleNode, apply: bool) -> bool:
        """
        Sets whether the values are sorted by their internal values, or their
        (string) display values
        """
        ...
    
    def SetAscending(self: MSPyECObjects.SortingRuleNode, ascending: bool) -> bool:
        """
        Sets whether the sorting is performed in ascending order
        """
        ...
    
    def SetCaseSensitive(self: MSPyECObjects.SortingRuleNode, sensitive: bool) -> bool:
        """
        Sets whether the sorting is applied with case-sensitivity.
        """
        ...
    
    def SetColumnName(self: MSPyECObjects.SortingRuleNode, name: str) -> bool:
        """
        Sets the name of the column to which this sorting rule applies
        """
        ...
    
    def SetHideDuplicateValues(self: MSPyECObjects.SortingRuleNode, hide: bool) -> bool:
        """
        Sets whether successive rows with identical values will be shown as
        empty
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(self: MSPyECObjects.SortingRuleNode, node: MSPyECObjects.ECReportNode) -> None:
        ...
    
class SortingRuleNodePtrArray:
    """
    None
    """

    def __init__(*args, **kwargs):
        """
        Overloaded function.
        
        1. __init__(self: MSPyECObjects.SortingRuleNodePtrArray) -> None
        
        2. __init__(self: MSPyECObjects.SortingRuleNodePtrArray, arg0: MSPyECObjects.SortingRuleNodePtrArray) -> None
        
        Copy constructor
        
        3. __init__(self: MSPyECObjects.SortingRuleNodePtrArray, arg0: Iterable) -> None
        """
        ...
    
    def append(self: MSPyECObjects.SortingRuleNodePtrArray, x: MSPyECObjects.SortingRuleNode) -> None:
        """
        Add an item to the end of the list
        """
        ...
    
    def clear(self: MSPyECObjects.SortingRuleNodePtrArray) -> None:
        """
        Clear the contents
        """
        ...
    
    def count(self: MSPyECObjects.SortingRuleNodePtrArray, x: MSPyECObjects.SortingRuleNode) -> int:
        """
        Return the number of times ``x`` appears in the list
        """
        ...
    
    def extend(*args, **kwargs):
        """
        Overloaded function.
        
        1. extend(self: MSPyECObjects.SortingRuleNodePtrArray, L: MSPyECObjects.SortingRuleNodePtrArray) -> None
        
        Extend the list by appending all the items in the given list
        
        2. extend(self: MSPyECObjects.SortingRuleNodePtrArray, L: Iterable) -> None
        
        Extend the list by appending all the items in the given list
        """
        ...
    
    def insert(self: MSPyECObjects.SortingRuleNodePtrArray, i: int, x: MSPyECObjects.SortingRuleNode) -> None:
        """
        Insert an item at a given position.
        """
        ...
    
    def pop(*args, **kwargs):
        """
        Overloaded function.
        
        1. pop(self: MSPyECObjects.SortingRuleNodePtrArray) -> MSPyECObjects.SortingRuleNode
        
        Remove and return the last item
        
        2. pop(self: MSPyECObjects.SortingRuleNodePtrArray, i: int) -> MSPyECObjects.SortingRuleNode
        
        Remove and return the item at index ``i``
        """
        ...
    
    def remove(self: MSPyECObjects.SortingRuleNodePtrArray, x: MSPyECObjects.SortingRuleNode) -> None:
        """
        Remove the first item from the list whose value is x. It is an error if there is no such item.
        """
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
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> ECN.StandaloneECEnabler:
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
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentleyGeom.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
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
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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
    
    def GetEnablerForStructArrayMember(self: MSPyECObjects.ECEnabler, schemaKey: MSPyECObjects.SchemaKey, className: str) -> ECN.StandaloneECEnabler:
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
    
    def GetPropertyIndices(self: MSPyECObjects.ECEnabler, indices: MSPyBentleyGeom.UInt32Array, parentIndex: int) -> MSPyECObjects.ECObjectsStatus:
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
    
    def AsMemoryECInstance(self: MSPyECObjects.IECInstance) -> ECN.MemoryECInstanceBase:
        ...
    
    def ChangeValue(*args, **kwargs):
        """
        Overloaded function.
        
        1. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. ChangeValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. ChangeValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
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
    
    def GetRelationshipEnabler(self: MSPyECObjects.StandaloneECRelationshipInstance) -> ECN.StandaloneECRelationshipEnabler:
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
        
        1. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str) -> MSPyECObjects.ECObjectsStatus
        
        2. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessString: str, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        4. GetValue(self: MSPyECObjects.IECInstance, value: ECN.ECValue, propertyIndex: int, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def GetValueUsingAccessor(self: MSPyECObjects.IECInstance, value: ECN.ECValue, accessor: ECN.ECValueAccessor) -> MSPyECObjects.ECObjectsStatus:
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
    def RelationshipEnabler(arg0: MSPyECObjects.StandaloneECRelationshipInstance) -> ECN.StandaloneECRelationshipEnabler:
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
        
        1. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        2. SetValue(self: MSPyECObjects.IECInstance, accessString: str, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        
        3. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus
        
        4. SetValue(self: MSPyECObjects.IECInstance, propertyIndex: int, value: ECN.ECValue, arrayIndex: int) -> MSPyECObjects.ECObjectsStatus
        """
        ...
    
    def SetValueUsingAccessor(self: MSPyECObjects.IECInstance, accessor: ECN.ECValueAccessor, value: ECN.ECValue) -> MSPyECObjects.ECObjectsStatus:
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

    def AsArrayProperty(self: MSPyECObjects.ECProperty) -> ECN.ArrayECProperty:
        ...
    
    def AsPrimitiveProperty(self: MSPyECObjects.ECProperty) -> ECN.PrimitiveECProperty:
        ...
    
    def AsStructProperty(self: MSPyECObjects.ECProperty) -> ECN.StructECProperty:
        ...
    
    @property
    def BaseProperty(arg0: MSPyECObjects.ECProperty) -> MSPyECObjects.ECProperty:
        ...
    @BaseProperty.setter
    def BaseProperty(arg0: MSPyECObjects.ECProperty, arg1: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Class(arg0: MSPyECObjects.ECProperty) -> ECN.ECClass:
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
    
    def GetClass(self: MSPyECObjects.ECProperty) -> ECN.ECClass:
        ...
    
    def GetCustomAttribute(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributeLocal(*args, **kwargs):
        """
        Overloaded function.
        
        1. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetCustomAttributeLocal(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
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
        
        1. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, schemaName: MSPyBentley.WString, className: MSPyBentley.WString) -> ECN.IECInstance
        
        2. GetPrimaryCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> ECN.IECInstance
        """
        ...
    
    def GetPrimaryCustomAttributes(self: MSPyECObjects.IECCustomAttributeContainer, includeBase: bool) -> ECN.ECCustomAttributeInstanceIterable:
        ...
    
    def GetType(self: MSPyECObjects.StructECProperty) -> ECN.ECClass:
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
        
        2. IsDefined(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
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
        
        2. RemoveCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, classDefiniton: ECN.ECClass) -> bool
        """
        ...
    
    def SetBaseProperty(self: MSPyECObjects.ECProperty, prop: MSPyECObjects.ECProperty) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetCalculatedPropertySpecification(self: MSPyECObjects.ECProperty, expressionAttribute: ECN.IECInstance) -> bool:
        ...
    
    def SetCustomAttribute(self: MSPyECObjects.IECCustomAttributeContainer, customAtributeInstance: ECN.IECInstance) -> MSPyECObjects.ECObjectsStatus:
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
    
    def SetType(self: MSPyECObjects.StructECProperty, type: ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    def SetTypeName(self: MSPyECObjects.ECProperty, typeName: MSPyBentley.WString) -> MSPyECObjects.ECObjectsStatus:
        ...
    
    @property
    def Type(arg0: MSPyECObjects.StructECProperty) -> ECN.ECClass:
        ...
    @Type.setter
    def Type(arg0: MSPyECObjects.StructECProperty, arg1: ECN.ECClass) -> MSPyECObjects.ECObjectsStatus:
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

    def AddSymbol(self: MSPyECObjects.SymbolExpressionContext, symbol: ECN.Symbol) -> BentleyStatus:
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
    
class TaskNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.TaskNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.TaskNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.TaskNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.TaskNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.TaskNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class TentativePopupMenuNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.TentativePopupMenuNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.TentativePopupMenuNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.TentativePopupMenuNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.TentativePopupMenuNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.TentativePopupMenuNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class ToolBoxNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ToolBoxNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.ToolBoxNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ToolBoxNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ToolBoxNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ToolBoxNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class UserInterfaceHelper:
    """
    None
    """

    @staticmethod
    def AddApplicationToolRefToTaskTree(taskToolName: str, parentNode: MSPyECObjects.TaskNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, appToolData: MSPyECObjects.ApplicationToolData, showHideCriteria: str = None) -> tuple:
        ...
    
    @staticmethod
    def AddApplicationToolRefToToolTree(taskToolName: str, parentNode: MSPyECObjects.ToolBoxNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, appToolData: MSPyECObjects.ApplicationToolData, showHideCriteria: str = None) -> tuple:
        ...
    
    @staticmethod
    def AddKeyinToggleToToolBoxTree(toolName: str, parentNode: MSPyECObjects.ToolBoxNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, tooltip: str, keyin: str, iconName: str, toggleStateCriteria: str, showHideCriteria: str = None) -> tuple:
        ...
    
    @staticmethod
    def AddKeyinToolToTaskTree(toolName: str, parentNode: MSPyECObjects.TaskNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, tooltip: str, keyin: str, iconName: str, showHideCriteria: str = None) -> tuple:
        ...
    
    @staticmethod
    def AddKeyinToolToToolBoxTree(toolName: str, parentNode: MSPyECObjects.ToolBoxNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, tooltip: str, keyin: str, iconName: str, showHideCriteria: str = None) -> tuple:
        ...
    
    @staticmethod
    def AddNamedToolRefByPathToTaskTree(taskToolName: str, parentNode: MSPyECObjects.TaskNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, referenceToolFullPath: str) -> tuple:
        ...
    
    @staticmethod
    def AddNamedToolRefToTaskTree(taskToolName: str, parentNode: MSPyECObjects.TaskNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, referenceToolNode: MSPyECObjects.ToolBoxNode) -> tuple:
        ...
    
    @staticmethod
    def AddTaskContainer(toolName: str, parentNode: MSPyECObjects.TaskNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, showHideCriteria: str = None, showIcon: bool = True, isWorkFlowMode: bool = False, iconName: str = None) -> tuple:
        ...
    
    @staticmethod
    def AddToolBoxContainer(toolName: str, parentNode: MSPyECObjects.ToolBoxNode, sortValue: int, virtualDgnlib: MSPyDgnPlatform.XDataTreeOwner, showHideCriteria: str = None) -> tuple:
        ...
    
    @staticmethod
    def SetApplicationToolRefInstanceData(instance: MSPyECObjects.IECInstance, appToolData: MSPyECObjects.ApplicationToolData, showHideCriteria: str) -> None:
        ...
    
    @staticmethod
    def SetKeyinToggleInstanceData(instance: MSPyECObjects.IECInstance, tooltip: str, keyin: str, iconName: str, toggleStateCriteria: str, showHideCriteria: str = None) -> None:
        ...
    
    @staticmethod
    def SetKeyinToolInstanceData(instance: MSPyECObjects.IECInstance, tooltip: str, keyin: str, iconName: str, showHideCriteria: str) -> None:
        ...
    
    @staticmethod
    def SetNamedToolIconName(instance: MSPyECObjects.IECInstance, iconName: str) -> None:
        ...
    
    @staticmethod
    def SetNamedToolRefInstanceData(instance: MSPyECObjects.IECInstance, referenceToolFullPath: str) -> None:
        ...
    
    @staticmethod
    def SetTaskContainerIconName(instance: MSPyECObjects.IECInstance, iconName: str) -> None:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class UserInterfaceNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    def FindByElementId(elemId: int, handlerId: MSPyDgnPlatform.HandlerId, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.XDataTreeNode:
        """
        Return a reference counted pointer to an XDataTreeNode.
        
        :param elemID:
        The ElementId of the Type 66 element that holds the element
        template XAttribute data.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type to search.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        """
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(xDataNodePtr: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.UserInterfaceNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
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

    def GetECValue(self: MSPyECObjects.ValueResult, ecValue: ECN.ECValue) -> MSPyECObjects.ExpressionStatus:
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

    def __init__(self: MSPyECObjects.ValueSymbol, name: str, value: ECN.ECValue) -> None:
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
    
class ViewPopupMenuNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @staticmethod
    def CreateNode(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateNode(name: str, parentId: int, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ViewPopupMenuNode
        
        2. CreateNode(name: str, parentNode: MSPyECObjects.ViewPopupMenuNode, allowChildNodes: bool, sortPriority: int, owner: MSPyDgnPlatform.XDataTreeOwner, seedContainer: MSPyDgnPlatform.XInstanceContainer = None) -> MSPyECObjects.ViewPopupMenuNode
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.ViewPopupMenuNode:
        ...
    
    @staticmethod
    def FromXDataTreeNodePtr(dtNode: MSPyECObjects.XDataTreeNode) -> MSPyECObjects.ViewPopupMenuNode:
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    @staticmethod
    def GetNodeHandlerId() -> MSPyDgnPlatform.HandlerId:
        ...
    
    def GetNodeType(self: MSPyECObjects.UserInterfaceNode, nodeType: MSPyBentley.WString) -> int:
        ...
    
    def GetOrCreateDefaultInstance(self: MSPyECObjects.UserInterfaceNode) -> MSPyECObjects.IECInstance:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    NodeHandlerId: HandlerId
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
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
    
class WhereCriterion:
    """
    None
    """

    def Accept(self: MSPyECObjects.WhereCriterion, instance: MSPyDgnPlatform.DgnECInstance) -> bool:
        """
        Apply this WhereCriterion to the specified DgnECInstance, binding the
        expressions in the criterion to the instance and evaluating their
        values for this instance.
        """
        ...
    
    def AcceptCollection(self: MSPyECObjects.WhereCriterion, iterable: MSPyDgnPlatform.DgnECInstanceIterable) -> bool:
        """
        Apply this WhereCriterion to an instance collection, binding the
        expressions in the criterion to the instance and evaluating their
        values.
        """
        ...
    
    class CompareOp:
        """
        Members:
        
        eEQ
        
        eNE
        
        eGT
        
        eGE
        
        eLT
        
        eLE
        
        eIS_IN
        
        eNOT_IN
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.CompareOp, value: int) -> None:
            ...
        
        eEQ: CompareOp
        
        eGE: CompareOp
        
        eGT: CompareOp
        
        eIS_IN: CompareOp
        
        eLE: CompareOp
        
        eLT: CompareOp
        
        eNE: CompareOp
        
        eNOT_IN: CompareOp
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.CompareOp) -> int:
            ...
        
    @staticmethod
    def ComparePrimitiveValues(lhs: MSPyECObjects.ECValue, op: MSPyECObjects.WhereCriterion.CompareOp, rhs: MSPyECObjects.ECValue) -> bool:
        """
        Utility to compare two values according to a comparison operator. This
        function will call PromoteValueToPrimitiveType in order to convert the
        values to compatible types, if possible.
        
        :returns:
        true if the values satisfy the comparison.
        
        :param lhs:
        the value on the left
        
        :param rhs:
        the value on the right
        
        :param op:
        how to compare the values
        
        Remark:
        s false is returned if either value is Null or is uninitialized.
        
        Remark:
        s false is returned if either value is not a primitive type.
        
        Remark:
        s Comparing arrays or structs as such is not supported.
        """
        ...
    
    @staticmethod
    def CreateComparison(lhs: MSPyECObjects.WhereExpression, op: MSPyECObjects.WhereCriterion.CompareOp, rhs: MSPyECObjects.WhereExpression, isCaseSensitive: bool = False) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that compares the values of two expressions.
        
        See also:
        CreatePropertyExpression, CreateLogical
        
        :param lhs:
        left side WhereExpression to evaluate
        
        :param op:
        how to compare the values of the expressions, e.g.
        WhereCriterion.EQ, etc
        
        :param rhs:
        right side WhereExpression to evaluate
        
        :param isCaseSensitive:
        If true, the match will do a case sensitive match. Otherwise, it
        will be case insensitive.
        """
        ...
    
    @staticmethod
    def CreateLogical(lhs: MSPyECObjects.WhereCriterion, op: MSPyECObjects.WhereCriterion.LogicalOp, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that combines the results of other criteria.
        @See CreateComparison, CreateRelatedCriterion
        
        :param lhs:
        a criterion to evalute
        
        :param op:
        how to combine the criteria
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    @staticmethod
    def CreateLogicalAnd(lhs: MSPyECObjects.WhereCriterion, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that ANDs two criteria together. @See
        CreateComparison.
        
        :param lhs:
        a criterion to evalute
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    @staticmethod
    def CreateLogicalOr(lhs: MSPyECObjects.WhereCriterion, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that ORs two criteria together. @See
        CreateComparison.
        
        :param lhs:
        a criterion to evalute
        
        :param rhs:
        a criterion to evalute
        """
        ...
    
    @staticmethod
    def CreateNonNullPropertyTest(accessString: MSPyBentley.WString, arrayIndex: int = -1) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion which evaluates true if the specified property
        value exists and is not null
        
        :param accessString:
        The access string of the ECProperty
        
        :param arrayIndex:
        The array index, if the property is an array; or else -1
        """
        ...
    
    @staticmethod
    def CreateNullPropertyTest(accessString: MSPyBentley.WString, arrayIndex: int = -1) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion which evaluates true if the specified property
        value does not exist or is null
        
        :param accessString:
        The access string of the ECProperty
        
        :param arrayIndex:
        The array index, if the property is an array; or else -1
        """
        ...
    
    @staticmethod
    def CreateNumberFilter(lhs: MSPyECObjects.WhereExpression, filter: str, ifMatch: bool) -> tuple:
        ...
    
    @staticmethod
    def CreatePropertyComparison(ecPropertyName: str, op: MSPyECObjects.WhereCriterion.CompareOp, value: MSPyECObjects.ECValue) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that compares a named ECProperty to a known
        value. This is a convenience method that just returns
        (*WhereExpression.CreatePropertyExpression (ecPropertyName), op,
        *WhereExpression.CreateConstant (value))
        
        :param ecPropertyName:
        Name of the ECProperty
        
        :param op:
        Comparison operator, e.g. WhereCriterion.EQ, etc.
        
        :param value:
        ECValue to compare
        """
        ...
    
    @staticmethod
    def CreateRegexFilter(lhs: MSPyECObjects.WhereExpression, regexPattern: str, isCaseSensitive: bool) -> tuple:
        ...
    
    @staticmethod
    def CreateRelatedCriterion(lhs: MSPyECObjects.WhereCriterion.RelatedInstanceFinder, rhs: MSPyECObjects.WhereCriterion) -> MSPyECObjects.WhereCriterion:
        """
        Create a WhereCriterion that applies a criterion to a related
        instance. @See CreateLogical
        
        :param lhs:
        a related instance
        
        :param rhs:
        a criterion to apply to the related instance
        """
        ...
    
    @staticmethod
    def CreateRelatedInstanceFinder(source: MSPyECObjects.WhereCriterion.RelatedInstanceFinder, targetRelationship: MSPyECObjects.QueryRelatedClassSpecifier, relationshipCriterion: MSPyECObjects.WhereCriterion = None) -> MSPyECObjects.WhereCriterion.RelatedInstanceFinder:
        """
        Create an agent that looks up a related instance, nested in another
        related instance.
        
        :param source:
        Optional. The nested relationship to start from. If NULL, then
        this function will traverse *targetRelationship* on the current
        instance. If not NULL, then this function will evaluate *source*
        against the current instance in order to get a related instance
        and then traverse *targetRelationship* on the related instance.
        
        :param targetRelationship:
        The kind of relationship to look for
        
        :param relationshipCriterion:
        Optional. How to select instances of the specified relationship
        class.
        """
        ...
    
    @staticmethod
    def CreateStringFilter(lhs: MSPyECObjects.WhereExpression, filter: str, ifMatch: bool, isCaseSensitive: bool) -> tuple:
        ...
    
    class LogicalOp:
        """
        Members:
        
        eLOGICAL_AND
        
        eLOGICAL_OR
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.LogicalOp, value: int) -> None:
            ...
        
        eLOGICAL_AND: LogicalOp
        
        eLOGICAL_OR: LogicalOp
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.LogicalOp) -> int:
            ...
        
    class NumberFilterError:
        """
        Members:
        
        eNUMBER_FILTER_ERROR_InvalidSyntax
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.NumberFilterError, value: int) -> None:
            ...
        
        eNUMBER_FILTER_ERROR_InvalidSyntax: NumberFilterError
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.NumberFilterError) -> int:
            ...
        
    @staticmethod
    def PromoteValueToPrimitiveType(v: MSPyECObjects.ECValue, typeWanted: MSPyECObjects.PrimitiveType) -> MSPyECObjects.ECValue:
        """
        Utility to do simple primitive type conversions.
        
        :returns:
        value converted to type type wanted or an *uninitialized* value if
        the conversion could not be done. Supported conversions:
        PRIMITIVETYPE_Boolean -> PRIMITIVETYPE_Integer,
        PRIMITIVETYPE_Double, PRIMITIVETYPE_Long PRIMITIVETYPE_Integer
        -> PRIMITIVETYPE_Double, PRIMITIVETYPE_Long
        PRIMITIVETYPE_String -> PRIMITIVETYPE_Integer,
        PRIMITIVETYPE_Double, PRIMITIVETYPE_Long PRIMITIVETYPE_Long ->
        cannot be converted to any other type. However, a request to
        convert PRIMITIVETYPE_Long to an integer type is not considered an
        error and will return the input value unchanged.
        PRIMITIVETYPE_Double -> cannot be converted to any other type.
        However, a request to convert PRIMITIVETYPE_Double to an integer
        type is not considered an error and will return the input value
        unchanged. All other conversion requests are errors, and an
        uninitialized value is returned. If the input value is not a
        primitive type, an uninitialized value is returned.
        """
        ...
    
    class RelatedInstanceFinder:
        """
        None
        """
    
        def __init__(*args, **kwargs):
            """
            Initialize self.  See help(type(self)) for accurate signature.
            """
            ...
        
    class StringFilterError:
        """
        Members:
        
        eSTRING_FILTER_ERROR_InvalidSyntax
        """
    
        def __init__(self: MSPyECObjects.WhereCriterion.StringFilterError, value: int) -> None:
            ...
        
        eSTRING_FILTER_ERROR_InvalidSyntax: StringFilterError
        
        @property
        def name(self: handle) -> str:
            ...
        
        @property
        def value(arg0: MSPyECObjects.WhereCriterion.StringFilterError) -> int:
            ...
        
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
    eEQ: CompareOp
    
    eGE: CompareOp
    
    eGT: CompareOp
    
    eIS_IN: CompareOp
    
    eLE: CompareOp
    
    eLOGICAL_AND: LogicalOp
    
    eLOGICAL_OR: LogicalOp
    
    eLT: CompareOp
    
    eNE: CompareOp
    
    eNOT_IN: CompareOp
    
    eNUMBER_FILTER_ERROR_InvalidSyntax: NumberFilterError
    
    eSTRING_FILTER_ERROR_InvalidSyntax: StringFilterError
    
class WhereExpression:
    """
    None
    """

    @staticmethod
    def CreateConstant(v: MSPyECObjects.ECValue) -> MSPyECObjects.WhereExpression:
        """
        Create an expression that holds a constant value. This is useful for
        testing property values. @See CreateConstantSet, CreateComparison.
        
        :param v:
        The value of the constant
        """
        ...
    
    @staticmethod
    def CreateConstantSet(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreateConstantSet(s: MSPyBentley.WStringArray) -> MSPyECObjects.WhereExpression
        
        Create an expression that is a set of constant values. A set can be
        used as the right side of the IS_IN operator. @See CreateConstant,
        CreateComparison.
        
        :param s:
        The set constant values
        
        2. CreateConstantSet(s: MSPyBentleyGeom.Int64Array) -> MSPyECObjects.WhereExpression
        
        Create an expression that is a set of constant values. A set can be
        used as the right side of the IS_IN operator. @See CreateConstant,
        CreateComparison.
        
        :param s:
        The set constant values
        
        3. CreateConstantSet(s: MSPyBentleyGeom.DoubleArray) -> MSPyECObjects.WhereExpression
        
        Create an expression that is a set of constant values. A set can be
        used as the right side of the IS_IN operator. @See CreateConstant,
        CreateComparison.
        
        :param s:
        The set constant values
        """
        ...
    
    @staticmethod
    def CreateECInstanceIdExpression() -> MSPyECObjects.WhereExpression:
        """
        Create an WhereExpression that accesses the InstanceId of a
        DgnElementECInstance. @See CreateConstant, CreateConstantSet,
        CreateComparison.
        
        Remark:
        s If the value of the property is an array, then the array itself
        is the value of this expression.
        """
        ...
    
    @staticmethod
    def CreatePropertyExpression(*args, **kwargs):
        """
        Overloaded function.
        
        1. CreatePropertyExpression(accessString: MSPyBentley.WString, useDisplayValue: bool = False) -> MSPyECObjects.WhereExpression
        
        Create an WhereExpression that accesses the value of the specified
        property on a DgnElementECInstance. @See CreateConstant,
        CreateConstantSet, CreateComparison.
        
        Remark:
        s If the value of the property is an array, then the array itself
        is the value of this expression.
        
        :param accessString:
        identifies the property
        
        :param useDisplayValue:
        if true, the property value will be round-tripped from its display
        value
        
        2. CreatePropertyExpression(accessString: MSPyBentley.WString, arrayIndex: int, useDisplayValue: bool = False) -> MSPyECObjects.WhereExpression
        
        Create an WhereExpression that accesses the value of the specified
        property on a DgnElementECInstance. @See CreateConstant,
        CreateConstantSet, CreateComparison.
        
        Remark:
        s If the value of the property is an array, then the array itself
        is the value of this expression.
        
        :param accessString:
        identifies the property
        
        :param useDisplayValue:
        if true, the property value will be round-tripped from its display
        value
        """
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
class XDataTreeNode:
    """
    None
    """

    def AllowChildNodes(self: MSPyECObjects.XDataTreeNode) -> bool:
        """
        Return true if node is allowed to have child nodes.
        """
        ...
    
    def ClearCachedInstances(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Clear the cached instances held by the XInstanceContainer. Subsequent
        node request for data will then reload the data from the type 66
        elements in the DgnFile. This call can be used to clear any
        IECInstance changes before they are written to the file.
        """
        ...
    
    @staticmethod
    def Create(name: MSPyBentley.WString, sortPriority: int, allowChildNodes: bool, parentNode: MSPyECObjects.XDataTreeNode, owner: MSPyDgnPlatform.XDataTreeOwner, handlerId: MSPyDgnPlatform.HandlerId, seedInstances: MSPyDgnPlatform.XInstanceContainer) -> MSPyECObjects.XDataTreeNode:
        """
        Create and return a new XDataTreeNode.
        
        :param name:
        The name of the new node.
        
        :param sortPriority:
        The sortPriority of the new node. If -1 if passed in the next
        available value is used.
        
        :param allowChildNodes:
        Boolean the specifies if this node should allow children.
        
        :param parentNodeP:
        Pointer to the parent node or NULL if root node.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type.
        
        :param seedInstances:
        Pointer to a seed container of IECInstances.
        """
        ...
    
    @property
    def ElementRef(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        ...
    
    @staticmethod
    def FindByElementId(elemId: int, handlerId: MSPyDgnPlatform.HandlerId, owner: MSPyDgnPlatform.XDataTreeOwner) -> MSPyECObjects.XDataTreeNode:
        """
        Return a reference counted pointer to an XDataTreeNode.
        
        :param elemID:
        The ElementId of the Type 66 element that holds the element
        template XAttribute data.
        
        :param handlerId:
        The HandlerId that specifies the XDataTree type to search.
        
        :param owner:
        The owner of the node. The owner can be determined by the
        DgnFileP. See XDataTreeManager.GetDgnXDataTreeOwner.
        """
        ...
    
    @property
    def FullPath(arg0: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        ...
    
    def GetECInstanceByClassName(self: MSPyECObjects.XDataTreeNode, className: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param className:
        The class name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular class.
        """
        ...
    
    def GetECInstanceBySchemaName(self: MSPyECObjects.XDataTreeNode, fullSchemaName: str) -> MSPyECObjects.IECInstance:
        """
        Return a pointer to an IECIntance that is held in the node
        XInstanceContainer.
        
        :param fullSchemaName:
        The schema name to compare. This assumes that the
        XInstanceContainer only contains a single instance from a
        particular schema.
        """
        ...
    
    def GetElementRef(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.ElementRefBase:
        """
        Return the ElementRef of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetFullPath(self: MSPyECObjects.XDataTreeNode) -> MSPyBentley.WString:
        """
        Return the full heirarchial path to the XDataTreeNode.
        """
        ...
    
    def GetHandlerId(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        """
        Return the HandlerId for the node. This is use to determine the type
        of data the node contains, such as Element Template, Task, NamedTools,
        Detailing Symbol Styles, etc.
        """
        ...
    
    def GetId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the Type 66 element that serves as a host for
        the node.
        """
        ...
    
    def GetName(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetOwner(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        """
        Return the XDataTreeOwner that hold the XDataTree that contains the
        XDataTree node.
        """
        ...
    
    def GetParentId(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the ElementId of the parent node. If the node is a root node a
        value of 0 is returned.
        """
        ...
    
    def GetPathSeparator(self: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def GetSortPriority(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Return the Sort Priority which is used to determine the postion of the
        node under its parent node.
        """
        ...
    
    def GetXInstanceContainer(self: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        """
        Return a pointer to the XInstanceContainer that holds a list of
        ECXAInstance associated with the node. A NULL will be return if no
        instances are held by the node.
        """
        ...
    
    @property
    def HandlerId(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.HandlerId:
        ...
    
    @property
    def Id(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def Name(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    @Name.setter
    def Name(arg0: MSPyECObjects.XDataTreeNode, arg1: str) -> None:
        ...
    
    @property
    def Owner(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XDataTreeOwner:
        ...
    
    @property
    def ParentId(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    
    @property
    def PathSeparator(arg0: MSPyECObjects.XDataTreeNode) -> str:
        ...
    
    def ReloadXAttributeData(self: MSPyECObjects.XDataTreeNode) -> BentleyStatus:
        """
        Reload the XAttribute data which holds the node name, sort priority,
        and parent node specification. This call can be used to clear any
        XAttribute changes before they are written to the file. @Return
        SUCCESS if the XAttribute data was successfully reloaded.
        """
        ...
    
    def SetName(self: MSPyECObjects.XDataTreeNode, name: str) -> None:
        """
        Set the name of the XDataTreeNode. The node must be written to persist
        the change.
        
        :param name:
        The new name for the node.
        """
        ...
    
    def SetSortPriority(self: MSPyECObjects.XDataTreeNode, priority: int) -> None:
        """
        Set the Sort Priority which is used to determine the position of the
        node under its parent node.
        
        :param sortPriority:
        The new priority value.
        """
        ...
    
    def SortChildren(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of this node if this node contains child nodes.
        """
        ...
    
    def SortParent(self: MSPyECObjects.XDataTreeNode) -> None:
        """
        Sort all children of the parent of this node
        """
        ...
    
    @property
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode) -> int:
        ...
    @SortPriority.setter
    def SortPriority(arg0: MSPyECObjects.XDataTreeNode, arg1: int) -> None:
        ...
    
    def Write(self: MSPyECObjects.XDataTreeNode) -> int:
        """
        Write any node changes to the owner, which is typically a DgnFile.
        @Return SUCCESS if the node is successfully written.
        """
        ...
    
    @property
    def XInstanceContainer(arg0: MSPyECObjects.XDataTreeNode) -> MSPyDgnPlatform.XInstanceContainer:
        ...
    
    def __init__(*args, **kwargs):
        """
        Initialize self.  See help(type(self)) for accurate signature.
        """
        ...
    
eARRAYKIND_Primitive: ArrayKind

eARRAYKIND_Struct: ArrayKind

eAll: DgnECHostType

eAttachment: DgnECHostType

eCategory: ECReportNodeType

eColumnDefinition: ECReportNodeType

eColumnGroup: ECReportNodeType

eDELETEDGNECINSTANCE_Error: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_FileReadOnly: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_InvalidOrDeletedElement: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_InvalidProviderId: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_ProviderDoesNotSupportDelete: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_SchedulingDeleteNotSupportedByProvider: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_Success: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_UnableToLocateInstance: DeleteDgnECInstanceStatus

eDELETEDGNECINSTANCE_UnableToParseInstanceId: DeleteDgnECInstanceStatus

eDGNECINSTANCESTATUS_ClassLayoutNotStored: DgnECInstanceStatus

eDGNECINSTANCESTATUS_DuplicateRelationshipFound: DgnECInstanceStatus

eDGNECINSTANCESTATUS_EnablerNotValidForFile: DgnECInstanceStatus

eDGNECINSTANCESTATUS_Error: DgnECInstanceStatus

eDGNECINSTANCESTATUS_IncompatibleWipInstance: DgnECInstanceStatus

eDGNECINSTANCESTATUS_InstanceIsAlreadyAsleep: DgnECInstanceStatus

eDGNECINSTANCESTATUS_InstanceIsDeletedOrUndone: DgnECInstanceStatus

eDGNECINSTANCESTATUS_InstanceIsStale: DgnECInstanceStatus

eDGNECINSTANCESTATUS_InvalidElementRef: DgnECInstanceStatus

eDGNECINSTANCESTATUS_InvalidInstance: DgnECInstanceStatus

eDGNECINSTANCESTATUS_NoInstanceFound: DgnECInstanceStatus

eDGNECINSTANCESTATUS_PropertyNotFound: DgnECInstanceStatus

eDGNECINSTANCESTATUS_RelationshipInstanceNotCreated: DgnECInstanceStatus

eDGNECINSTANCESTATUS_RequiresSingleEndedRelationshipClass: DgnECInstanceStatus

eDGNECINSTANCESTATUS_Success: DgnECInstanceStatus

eDGNECINSTANCESTATUS_UnableToAddInstance: DgnECInstanceStatus

eDGNECINSTANCESTATUS_UnableToUpdateInstance: DgnECInstanceStatus

eDGNECINSTANCESTATUS_XAttributeHasBeenRemoved: DgnECInstanceStatus

eDesignLink: DgnECHostType

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

eECQUERY_PROCESS_Empty: ECQueryProcessFlags

eECQUERY_PROCESS_SearchAllClasses: ECQueryProcessFlags

eECQUERY_PROCESS_SearchAllExtrinsic: ECQueryProcessFlags

eECQUERY_PROCESS_SearchAllIntrinsic: ECQueryProcessFlags

eECQUERY_PROCESS_SearchSpecifiedClasses: ECQueryProcessFlags

eECRelationshipEnd_Source: ECRelationshipEnd

eECRelationshipEnd_Target: ECRelationshipEnd

eECSCHEMAPERSISTENCE_All: ECSchemaPersistence

eECSCHEMAPERSISTENCE_External: ECSchemaPersistence

eECSCHEMAPERSISTENCE_Stored: ECSchemaPersistence

eECSCHEMAPERSISTENCE_Unknown: ECSchemaPersistence

eEVALOPT_EnforceGlobalRepresentation: EvaluationOptions

eEVALOPT_EnforceUnits: EvaluationOptions

eEVALOPT_Legacy: EvaluationOptions

eEVALOPT_SuppressTypeConversions: EvaluationOptions

eElement: DgnECHostType

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

eFile: DgnECHostType

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

eLevel: DgnECHostType

eLow: CategorySortPriority

eMEMORYINSTANCEUSAGE_Empty: MemoryInstanceUsageBitmask

eMEMORYINSTANCEUSAGE_IsHidden: MemoryInstanceUsageBitmask

eMEMORYINSTANCEUSAGE_IsPartiallyLoaded: MemoryInstanceUsageBitmask

eMedium: CategorySortPriority

eModel: DgnECHostType

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

eReportDefinition: ECReportNodeType

eSCHEMADELETE_FailedToDeleteSchemaElement: SchemaDeleteStatus

eSCHEMADELETE_ProviderDoesNotSupportDelete: SchemaDeleteStatus

eSCHEMADELETE_ProviderNotFound: SchemaDeleteStatus

eSCHEMADELETE_SchemaHasStoredInstances: SchemaDeleteStatus

eSCHEMADELETE_SchemaIsReferenced: SchemaDeleteStatus

eSCHEMADELETE_SchemaNotFound: SchemaDeleteStatus

eSCHEMADELETE_Success: SchemaDeleteStatus

eSCHEMAIMPORT_FailedToDeserializeXmlFile: SchemaImportStatus

eSCHEMAIMPORT_FailedToSerializeAsXml: SchemaImportStatus

eSCHEMAIMPORT_FailedToWriteElement: SchemaImportStatus

eSCHEMAIMPORT_InvalidUserDefinedSchema: SchemaImportStatus

eSCHEMAIMPORT_NotValidECSchemaXml: SchemaImportStatus

eSCHEMAIMPORT_ProviderDoesNotSupportImport: SchemaImportStatus

eSCHEMAIMPORT_ProviderNotFound: SchemaImportStatus

eSCHEMAIMPORT_SchemaAlreadyStoredInFile: SchemaImportStatus

eSCHEMAIMPORT_Success: SchemaImportStatus

eSCHEMAMATCHTYPE_Exact: SchemaMatchType

eSCHEMAMATCHTYPE_Identical: SchemaMatchType

eSCHEMAMATCHTYPE_Latest: SchemaMatchType

eSCHEMAMATCHTYPE_LatestCompatible: SchemaMatchType

eSCHEMAUPDATE_FailedToDeserializeXmlFile: SchemaUpdateStatus

eSCHEMAUPDATE_FailedToSerializeAsXml: SchemaUpdateStatus

eSCHEMAUPDATE_FailedToUpdateInstances: SchemaUpdateStatus

eSCHEMAUPDATE_FailedToUpdateReferencingSchemas: SchemaUpdateStatus

eSCHEMAUPDATE_FailedToWriteElement: SchemaUpdateStatus

eSCHEMAUPDATE_NotValidECSchemaXml: SchemaUpdateStatus

eSCHEMAUPDATE_ProviderDoesNotSupportInstanceUpdate: SchemaUpdateStatus

eSCHEMAUPDATE_ProviderDoesNotSupportUpdate: SchemaUpdateStatus

eSCHEMAUPDATE_ProviderNotFound: SchemaUpdateStatus

eSCHEMAUPDATE_SchemaNotFound: SchemaUpdateStatus

eSCHEMAUPDATE_SchemaVersionMismatch: SchemaUpdateStatus

eSCHEMAUPDATE_Success: SchemaUpdateStatus

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

eSortingGroup: ECReportNodeType

eSortingRule: ECReportNodeType

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

eUnknown: DgnECHostType

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

eView: DgnECHostType

