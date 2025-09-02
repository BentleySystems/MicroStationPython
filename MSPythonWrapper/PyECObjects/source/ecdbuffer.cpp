/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecdbuffer.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECDBuffer.h>



static const char * __doc_Bentley_ECObjects_ECDBuffer_CopyFromBuffer = R"doc(Attempts to copy property values from source buffer. Expects source to
have a compatible class layout.

:param source:
    The ECDBuffer to copy values from)doc";

static const char * __doc_Bentley_ECObjects_ECDBuffer_ClearValues = R"doc(Sets all values to null)doc";

static const char * __doc_Bentley_ECObjects_ECDBuffer_IsEmpty = R"doc(Returns true if the buffer is empty (all values are null and all
arrays are empty))doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_IsEmpty = R"doc(Returns whether or not this SchemaLayout has any ClassLayouts defined.)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_GetMaxIndex = R"doc(Returns the max index in the ClassLayout

Remark:
    s This may often correspond to " number of ClassLayouts - 1 ", but
    not necessarily, because there can be gaps so when you call
    GetClassLayout (index) you might get NULLs. Even the last one
    could be NULL.

Remark:
    s NOTE:Check IsEmpty() before GetMaxIndex() to ensure there is at
    least one ClassLayout, otherwise the return value of GetMaxIndex()
    is undefined)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_FindAvailableClassIndex = R"doc(Finds the first available index for adding a class layout


Returns (Tuple, 0):
    SUCCESS if the index is found, ERROR otherwise

Returns (Tuple, 1):
	classIndex.  The first available index in the layout. This is not necessarily
    the size of the layout because there can be gaps.

)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_FindClassIndex = R"doc(Given a classname, tries to find the index of the corresponding
ClassLayout


:param className:
    The name of the class to find the ClassLayout index of

Returns (Tuple, 0):
    A pointer to the corresponding ClassLayout if found, NULL
    otherwise

Returns (Tuple, 1):
	classIndex.  The index of the corresponding ClassLayout, if found
)doc";
static const char * __doc_Bentley_ECObjects_SchemaLayout_FindClassLayout = R"doc(Given a classname, tries to find the corresponding ClassLayout

Parameter ``className``:
    The name of the class to find


)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_GetClassLayout = R"doc(Returns the ClassLayout at the given index

:param classIndex:
    The index of the desired ClassLayout

:returns:
    A pointer to the requested ClassLayout if the index is valid, NULL
    otherwise)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_ReplaceClassLayout = R"doc(Replaces the ClassLayout at the given index

Parameter ``classLayout``:
    The ClassLayout to replace

Parameter ``classIndex``:
    The index of the ClassLayout

Returns:
    ERROR if the class index is out of range.)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_AddClassLayout = R"doc(Adds the ClassLayout at the given index

:param classLayout:
    The ClassLayout to add

:param classIndex:
    The index where to add the ClassLayout

:returns:
    ERROR if a class layout already exists with the given index)doc";

static const char * __doc_Bentley_ECObjects_SchemaLayout_GetSchemaIndex = R"doc(Gets the SchemaIndex of this particular SchemaLayout.)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_ToString = R"doc(Returns a string containing a description of the class and its
properties)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_IsCompatible = R"doc(Checks the given classLayout to see if it is equal to, or a subset of,
this layout

:param layout:
    The ClassLayout to test compatibility of

:returns:
    true if the given ClassLayout is equal to or a subset of this
    layout, false otherwise)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_CalculateBytesUsed = R"doc(Determines the number of bytes used for property data, so far)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_SetPropertyReadOnly = R"doc(Sets the read-only status of a property, given its index within the
ClassLayout

:param propertyIndex:
    The index within the ClassLayout of the property to set the read-
    only flag for

:param readOnly:
    Flag indicating whether this property is read-only

:returns:
    The value of readOnly if successfully set, otherwise false)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_IsPropertyReadOnly = R"doc(Given a propertyIndex, will return whether the property is read-only
or not

Parameter ``propertyIndex``:
    The index within the ClassLayout of the property to check

Returns:
    true if the property is read-only, false otherwise)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetPropertyIndex = R"doc(Given an access string, will return the property index within the
ClassLayout


:param accessString:
    The access string for the desired property

Returns(Tuple, 0):
    ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
    ECOBJECTS_STATUS_Success otherwise

Returns (Tuple, 1):
	propertyIndex.  Will contain the index of the given property within the
    ClassLayout, if found


)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetPropertyLayoutIndex = R"doc(Given a property layout, will return the property index within the
ClassLayout


Parameter ``propertyLayout``:
    The propertyLayout of the property that we want the index for

Returns(Tuple, 0):
    ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
    ECOBJECTS_STATUS_Success otherwise

Returns (Tuple, 1):
	propertyIndex.    Will contain the index of the given property within the
    ClassLayout, if found

)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetPropertyLayoutByIndex = R"doc(Given a property index, will return the PropertyLayout

:param propertyLayout:
    Will point to the PropertyLayout if found

:param propertyIndex:
    The index in the ClassLayout of the desired property

:returns:
    ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
    ECOBJECTS_STATUS_Success otherwise)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetPropertyLayout = R"doc(Given a property access string, will return the PropertyLayout

Parameter ``propertyLayout``:
    Will point to the PropertyLayout if found

Parameter ``accessString``:
    The access string for the desired property

Returns:
    ECOBJECTS_STATUS_PropertyNotFound if the property is not found,
    ECOBJECTS_STATUS_Success otherwise)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetPropertyCountExcludingEmbeddedStructs = R"doc(Returns the number of properties this ClassLayout manages, not
counting embedded structs)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetPropertyCount = R"doc(Returns the number of properties this ClassLayout manages)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetChecksum = R"doc(Returns the checksum for this ClassLayout)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetECPointerIndex = R"doc(Returns the property index of the given relationship end

:param end:
    The ECRelationshipEnd for which to get the pointer index

:returns:
    The property index of the pointer for the given relationship end)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_GetECClassName = R"doc(Returns the name of the ECClass that this ClassLayout manages)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_CreateEmpty = R"doc(Creates an empty ClassLayout for a class with the given name

:param className:
    The name of the class that this ClassLayout will define)doc";

static const char * __doc_Bentley_ECObjects_ClassLayout_BuildFromClass = R"doc(Given a class, will create the ClassLayout that manages that class

Parameter ``ecClass``:
    The ECClass to build the ClassLayout from

Returns:
    ClassLayout pointer managing this ECClass)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_ToString = R"doc(Returns a string containing detailed information about this property's
characteristics (including access string, type name, offset,
nullflagsOffset, nullflagsBitmask)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetSizeInFixedSection = R"doc(Gets the size required for this PropertyValue in the fixed Section of
the IECInstance's memory Variable-sized types will have 4 byte
SecondaryOffset stored in the fixed Section.)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_HoldsCalculatedProperty = R"doc(Returns whether this property is actually a Calculated Property)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_IsFixedSized = R"doc(Returns whether this is a fixed-size property)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_IsReadOnlyProperty = R"doc(Returns whether this is a read-only property)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetModifierData = R"doc(Returns the data used with the modifier flag, like the length of a
fixed-sized string.)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetModifierFlags = R"doc(Returns the modifier flags that describe this property, which can
indicate @li that a string should be treated as fixed size @li that a
string should have a max length @li that a longer fixed size type
should be treated as an optional variable-sized type @li that for a
string, only an entry to the string table is stored @li a default
value should be used)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetTypeDescriptor = R"doc(Returns an ECTypeDescriptor that defines this property)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetNullflagsBitmask = R"doc(Returns a bit mask that has the a single bit set. It can be used to
AND with the bitmask at the offset returned by GetNullflagsOffset() to
determine if the property is NULL.)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetNullflagsOffset = R"doc(Returns the offset to Null flags bit mask.)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetOffset = R"doc(Returns the offset to either the data holding this property's value
(for fixed-size values) or to the offset at which the property's value
can be found)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetParentStructIndex = R"doc(Returns the property index of the struct parent of this property. If
this is a root property an index of zero is returned.)doc";

static const char * __doc_Bentley_ECObjects_PropertyLayout_GetAccessString = R"doc(Returns the access string for retrieving this property)doc";

using PropertyLayoutPtr = std::unique_ptr< PropertyLayout, py::nodelete>;
using SchemaLayoutPtr = std::unique_ptr< SchemaLayout, py::nodelete>;
using ECDBufferPtr = std::unique_ptr< ECDBuffer, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECDBuffer(py::module_& m)
    {
    //===================================================================================
    // enum ArrayModifierFlags
    py::enum_< ArrayModifierFlags>(m, "ArrayModifierFlags", py::arithmetic())
        .value("ePROPERTYLAYOUTMODIFIERFLAGS_None", PROPERTYLAYOUTMODIFIERFLAGS_None)
        .value("ePROPERTYLAYOUTMODIFIERFLAGS_IsArrayFixedCount", PROPERTYLAYOUTMODIFIERFLAGS_IsArrayFixedCount)
        .value("ePROPERTYLAYOUTMODIFIERFLAGS_IsReadOnly", PROPERTYLAYOUTMODIFIERFLAGS_IsReadOnly)
        .value("ePROPERTYLAYOUTMODIFIERFLAGS_IsCalculated", PROPERTYLAYOUTMODIFIERFLAGS_IsCalculated)
        .export_values();

    //===================================================================================
    // struct PropertyLayout
    py::class_< PropertyLayout, PropertyLayoutPtr> c1(m, "PropertyLayout");

    c1.def_property_readonly("AccessString", &PropertyLayout::GetAccessString);
    c1.def("GetAccessString", &PropertyLayout::GetAccessString, py::return_value_policy::reference_internal, DOC(Bentley, ECObjects, PropertyLayout, GetAccessString));
    
    c1.def_property_readonly("ParentStructIndex", &PropertyLayout::GetParentStructIndex);
    c1.def("GetParentStructIndex", &PropertyLayout::GetParentStructIndex, DOC(Bentley, ECObjects, PropertyLayout, GetParentStructIndex));
    
    c1.def_property_readonly("Offset", &PropertyLayout::GetOffset);
    c1.def("GetOffset", &PropertyLayout::GetOffset, DOC(Bentley, ECObjects, PropertyLayout, GetOffset));
    
    c1.def_property_readonly("NullflagsOffset", &PropertyLayout::GetNullflagsOffset);
    c1.def("GetNullflagsOffset", &PropertyLayout::GetNullflagsOffset, DOC(Bentley, ECObjects, PropertyLayout, GetNullflagsOffset));
    
    c1.def_property_readonly("NullflagsBitmask", &PropertyLayout::GetNullflagsBitmask);
    c1.def("GetNullflagsBitmask", &PropertyLayout::GetNullflagsBitmask, DOC(Bentley, ECObjects, PropertyLayout, GetNullflagsBitmask));
    
    c1.def_property_readonly("TypeDescriptor", &PropertyLayout::GetTypeDescriptor);
    c1.def("GetTypeDescriptor", &PropertyLayout::GetTypeDescriptor, DOC(Bentley, ECObjects, PropertyLayout, GetTypeDescriptor));
    
    c1.def_property_readonly("ModifierFlags", &PropertyLayout::GetModifierFlags);
    c1.def("GetModifierFlags", &PropertyLayout::GetModifierFlags, DOC(Bentley, ECObjects, PropertyLayout, GetModifierFlags));
    
    c1.def_property_readonly("ModifierData", &PropertyLayout::GetModifierData);
    c1.def("GetModifierData", &PropertyLayout::GetModifierData, DOC(Bentley, ECObjects, PropertyLayout, GetModifierData));
    
    c1.def_property("ReadOnlyProperty", &PropertyLayout::IsReadOnlyProperty, &PropertyLayout::SetReadOnlyMask);
    c1.def("IsReadOnlyProperty", &PropertyLayout::IsReadOnlyProperty, DOC(Bentley, ECObjects, PropertyLayout, IsReadOnlyProperty));
    c1.def("SetReadOnlyProperty", &PropertyLayout::SetReadOnlyMask, "mask"_a);
    
    c1.def("IsFixedSized", &PropertyLayout::IsFixedSized, DOC(Bentley, ECObjects, PropertyLayout, IsFixedSized));    
    c1.def("HoldsCalculatedProperty", &PropertyLayout::HoldsCalculatedProperty, DOC(Bentley, ECObjects, PropertyLayout, HoldsCalculatedProperty));
    
    c1.def_property_readonly("SizeInFixedSection", &PropertyLayout::GetSizeInFixedSection);
    c1.def("GetSizeInFixedSection", &PropertyLayout::GetSizeInFixedSection, DOC(Bentley, ECObjects, PropertyLayout, GetSizeInFixedSection));
    
    c1.def("ToString", &PropertyLayout::ToString, DOC(Bentley, ECObjects, PropertyLayout, ToString));

    //===================================================================================
    // struct ClassLayout
    py::class_< ClassLayout, ClassLayoutPtr> c2(m, "ClassLayout");

    c2.def_static("BuildFromClass", &ClassLayout::BuildFromClass, "ecClass"_a, DOC(Bentley, ECObjects, ClassLayout, BuildFromClass));
    c2.def_static("CreateEmpty", &ClassLayout::CreateEmpty, "className"_a, DOC(Bentley, ECObjects, ClassLayout, CreateEmpty));
    
    c2.def_property_readonly("ECClassName", &ClassLayout::GetECClassName);
    c2.def("GetECClassName", &ClassLayout::GetECClassName, py::return_value_policy::reference_internal, DOC(Bentley, ECObjects, ClassLayout, GetECClassName));
    
    c2.def("GetECPointerIndex", &ClassLayout::GetECPointerIndex, "end"_a, DOC(Bentley, ECObjects, ClassLayout, GetECPointerIndex));
    
    c2.def_property_readonly("Checksum", &ClassLayout::GetChecksum);
    c2.def("GetChecksum", &ClassLayout::GetChecksum, DOC(Bentley, ECObjects, ClassLayout, GetChecksum));
    
    c2.def_property_readonly("PropertyCount", &ClassLayout::GetPropertyCount);
    c2.def("GetPropertyCount", &ClassLayout::GetPropertyCount, DOC(Bentley, ECObjects, ClassLayout, GetPropertyCount));
    
    c2.def_property_readonly("PropertyCountExcludingEmbeddedStructs", &ClassLayout::GetPropertyCountExcludingEmbeddedStructs);
    c2.def("GetPropertyCountExcludingEmbeddedStructs", &ClassLayout::GetPropertyCountExcludingEmbeddedStructs, DOC(Bentley, ECObjects, ClassLayout, GetPropertyCountExcludingEmbeddedStructs));

    c2.def("GetPropertyLayout", [] (ClassLayout const& self, WCharCP accessString)
           {
           PropertyLayoutCP propLayout = nullptr;
           auto retVal = self.GetPropertyLayout(propLayout, accessString);
           return py::make_tuple(retVal, PropertyLayoutPtr(const_cast<PropertyLayoutP>(propLayout)));
           }, "accessString"_a, DOC(Bentley, ECObjects, ClassLayout, GetPropertyLayout));

    c2.def("GetPropertyLayoutByIndex", [] (ClassLayout const& self, uint32_t propertyIndex)
           {
           PropertyLayoutCP propLayout = nullptr;
           auto retVal = self.GetPropertyLayoutByIndex(propLayout, propertyIndex);
           return py::make_tuple(retVal, PropertyLayoutPtr(const_cast<PropertyLayoutP>(propLayout)));
           }, "propertyIndex"_a, DOC(Bentley, ECObjects, ClassLayout, GetPropertyLayoutByIndex));

    c2.def("GetPropertyLayoutIndex", [] (ClassLayout const& self, PropertyLayoutCR propertyLayout)
           {
           uint32_t propertyIndex = 0;
           auto retVal = self.GetPropertyLayoutIndex(propertyIndex, propertyLayout);
           return py::make_tuple(retVal, propertyIndex);
           }, "propertyLayout"_a, DOC(Bentley, ECObjects, ClassLayout, GetPropertyLayoutIndex));

    c2.def("GetPropertyIndex", [] (ClassLayout const& self, WCharCP accessString)
           {
           uint32_t propertyIndex = 0;
           auto retVal = self.GetPropertyIndex(propertyIndex, accessString);
           return py::make_tuple(retVal, propertyIndex);
           }, "accessString"_a, DOC(Bentley, ECObjects, ClassLayout, GetPropertyIndex));

    c2.def("IsPropertyReadOnly", &ClassLayout::IsPropertyReadOnly, "propertyIndex"_a, DOC(Bentley, ECObjects, ClassLayout, IsPropertyReadOnly));
    c2.def("SetPropertyReadOnly", &ClassLayout::SetPropertyReadOnly, "propertyIndex"_a, "readOnly"_a, DOC(Bentley, ECObjects, ClassLayout, SetPropertyReadOnly));

    c2.def("CalculateBytesUsed", [] (ClassLayout const& self, py::bytes const& propertyData)
           {
           std::string strData = propertyData.cast<std::string>();
           return self.CalculateBytesUsed((Byte const*) strData.data());
           }, "propertyData"_a, DOC(Bentley, ECObjects, ClassLayout, CalculateBytesUsed));

    c2.def("IsCompatible", &ClassLayout::IsCompatible, "layout"_a, DOC(Bentley, ECObjects, ClassLayout, IsCompatible));
    c2.def("ToString", &ClassLayout::ToString, DOC(Bentley, ECObjects, ClassLayout, ToString));

    //===================================================================================
    // struct SchemaLayout
    py::class_<SchemaLayout, SchemaLayoutPtr> c3(m, "SchemaLayout");

    c3.def_property_readonly("SchemaIndex", &SchemaLayout::GetSchemaIndex);
    c3.def("GetSchemaIndex", &SchemaLayout::GetSchemaIndex, DOC(Bentley, ECObjects, SchemaLayout, GetSchemaIndex));

    c3.def("AddClassLayout", &SchemaLayout::AddClassLayout, "classLayout"_a, "classIndex"_a, DOC(Bentley, ECObjects, SchemaLayout, AddClassLayout));
    c3.def("ReplaceClassLayout", &SchemaLayout::ReplaceClassLayout, "classLayout"_a, "classIndex"_a, DOC(Bentley, ECObjects, SchemaLayout, ReplaceClassLayout));
    c3.def("GetClassLayout", &SchemaLayout::GetClassLayout, "classIndex"_a, py::return_value_policy::reference_internal, DOC(Bentley, ECObjects, SchemaLayout, GetClassLayout));
    c3.def("FindClassLayout", py::overload_cast<WCharCP>(&SchemaLayout::FindClassLayout, py::const_), "className"_a, py::return_value_policy::reference_internal, DOC(Bentley, ECObjects, SchemaLayout, FindClassLayout));
    
    c3.def("FindClassIndex", [] (SchemaLayout const& self, WCharCP className)
           {
           ClassIndex classIndex = 0;
           auto retVal = self.FindClassIndex(classIndex, className);
           return py::make_tuple(retVal, classIndex);
           }, "className"_a, DOC(Bentley, ECObjects, SchemaLayout, FindClassIndex));

    c3.def("FindAvailableClassIndex", [] (SchemaLayout const& self)
           {
           ClassIndex classIndex = 0;
           auto retVal = self.FindAvailableClassIndex(classIndex);
           return py::make_tuple(retVal, classIndex);
           }, DOC(Bentley, ECObjects, SchemaLayout, FindAvailableClassIndex));

    c3.def_property_readonly("MaxIndex", &SchemaLayout::GetMaxIndex);
    c3.def("GetMaxIndex", &SchemaLayout::GetMaxIndex, DOC(Bentley, ECObjects, SchemaLayout, GetMaxIndex));

    c3.def("IsEmpty", &SchemaLayout::IsEmpty, DOC(Bentley, ECObjects, SchemaLayout, IsEmpty));
    c3.def(py::init(&SchemaLayout::Create), "index"_a);

    //===================================================================================
    // struct ECDBuffer
    py::class_< ECDBuffer, ECDBufferPtr> c4(m, "ECDBuffer");

    c4.def("IsEmpty", &ECDBuffer::IsEmpty, DOC(Bentley, ECObjects, ECDBuffer, IsEmpty));
    c4.def("ClearValues", &ECDBuffer::ClearValues, DOC(Bentley, ECObjects, ECDBuffer, ClearValues));
    c4.def("CopyFromBuffer", &ECDBuffer::CopyFromBuffer, "source"_a, DOC(Bentley, ECObjects, ECDBuffer, CopyFromBuffer));
    }

