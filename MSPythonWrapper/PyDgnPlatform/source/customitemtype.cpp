/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\customitemtype.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/CustomItemType.h>



static const char * __doc_Bentley_DgnPlatform_IPickListProvider_IsValidSettings =R"doc(Check PickList Settings are valid for particular provider

:param providerName:
    $:param strSettings:)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_GetStandardValues =R"doc(Get string collection of PickList values

:param DgnFileP:
    dgnFile

:param ECPropertyCP:
    Property for which picklist values are needed

:param PrimitiveType:
    PrimitiveType of value that ECProperty holds

:param PickList:
    value collection)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_IsActive =R"doc(If IsActive returns false, we will not get call in GetStandardValues.
Override this method, if you want to disable provider)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_SetDisplayLabel =R"doc(Set DisplayLabel of provider. If DisplayLabel is not set, it will
return Name

:param Label:)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_GetDisplayLabel =R"doc(Name of pickList provider

:returns:
    Name of picklist provider)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_GetName =R"doc(Name of pickList provider

:returns:
    Name of picklist provider)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_GetProviderSettings =R"doc(Get Provider Settings for input property

:param ecProperty.:
    $:param PickList:

Provider Settings value)doc";

static const char * __doc_Bentley_DgnPlatform_IPickListProvider_GetProviderName =R"doc(Get Provider Name for input property

:param ecProperty.:
    $:param PickList:

Provider Name)doc";

static const char * __doc_Bentley_DgnPlatform_CustomItemHost_CopyCustomItems =R"doc(Copies Items from the specified host to this host.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomItemHost_ApplyCustomItem =R"doc(Attaches an Item of the specified type to this host)doc";

static const char * __doc_Bentley_DgnPlatform_CustomItemHost_GetCustomItem =R"doc(Returns the Item attached to this host with the specified library and
ItemType name)doc";

static const char * __doc_Bentley_DgnPlatform_CustomItemHost_GetCustomItemsCount =R"doc(Returns the number of Items attached to this host)doc";

static const char * __doc_Bentley_DgnPlatform_CustomItemHost_GetCustomItems =R"doc(Populates a list of Items attached to this host and returns the number
of Items)doc";

static const char * __doc_Bentley_DgnPlatform_CustomItemHost_GetDgnFile =R"doc(Returns the DgnFile which contains this host)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibraries_size =R"doc(Returns the number of ItemTypeLibraries within this collection)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibraries_GetDgnFile =R"doc(Returns the DgnFile associated with this collection)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_IsItemTypeSchema =R"doc(Returns true if the specified ECSchema name refers to an
ItemTypeLibrary)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_CloneForFile =R"doc(Clones this library for use with the specified DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_FindBySchemaName =R"doc(Returns the ItemTypeLibrary with the specified internal name within
the specified DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_FindByName =R"doc(Returns the ItemTypeLibrary with the specified user-visible name
within the specified DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetPropertyContainerById =R"doc(Returns the CustomPropertyContainer with the specified ID within this
library, or nullptr if no such container exists)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetPropertyContainerByName =R"doc(Returns the CustomPropertyContainer with the specified name within
this library, or nullptr if no such container exists)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetCustomTypeCount =R"doc(Returns the number of CustomPropertyTypes within this library)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetItemTypeCount =R"doc(Returns the number of ItemTypes within this library)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_CompareTo =R"doc(Returns true if this library is equivalent to the specified library)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_Delete =R"doc(Deletes this library from its DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_Write =R"doc(Writes any in-memory modifications to the DgnFile)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_Revert =R"doc(Reverts all in-memory modifications made to this library to match the
persistent state, if the library is persistent)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_RemoveCustomType =R"doc(Removes the CustomPropertyType with the specified ID)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_RemoveItemType =R"doc(Removes the ItemType with the specified ID)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetDgnFile =R"doc(Returns the DgnFile associated with this library.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_IsPersistent =R"doc(Returns true if this library has been written to its DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetId =R"doc(Returns the ID of the element which hosts this library, or
INVALID_ELEMENTID if the library is not persistent)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetInternalName =R"doc(Returns the internal name of this library, which is the same name as
the underlying ECSchema.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_SetName =R"doc(Changes the user-visible name of this library)doc";

static const char * __doc_Bentley_DgnPlatform_ItemTypeLibrary_GetName =R"doc(Returns the user-visible name of this library)doc";

static const char * __doc_Bentley_DgnPlatform_ItemType_SetLabelProperty =R"doc(Sets the property whose value should be used as the label for Items of
this type in the UI. If passed nullptr, the ItemType name will be used
for the Item label.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemType_SetIsIdentifyingItem =R"doc(Sets whether or not this Item Type, when attached to an element,
provides the label for that element in the UI.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemType_IsIdentifyingItem =R"doc(Returns true if, when attached to an element, this Item Type provides
the label for that element in the UI.)doc";

static const char * __doc_Bentley_DgnPlatform_ItemType_CompareTo =R"doc(Returns true if this ItemType is equivalent to the specified ItemType)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyType_CompareTo =R"doc(Returns true if this type is equivalent to the specified type)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyType_IsReferenced =R"doc(Returns true if this type serves as the type of any CustomProperty
within the containing ItemTypeLibrary)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyContainer_RemoveProperty =R"doc(Removes the property with the specified ID.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyContainer_GetPropertyCount =R"doc(Returns the number of properties within this container)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyContainer_GetId =R"doc(Returns the unique ID of this container within its ItemTypeLibrary)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyContainer_SetName =R"doc(Attempts to change the name of this container)doc";

static const char * __doc_Bentley_DgnPlatform_CustomPropertyContainer_GetName =R"doc(Returns the name of this container)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetUseLastValidValueOnExpressionFailure =R"doc(Returns the UseLastValidValueOnExpressionFailure value for this
property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetExpression =R"doc(Changes the CalculationExpression of this property

:param expression:
    CalculatedECExpression

:param expressionFailureValue:
    If expression fails, failuer value will be returned

:returns:
    true if the calculationExpression was successfully set.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetExpressionFailureValue =R"doc(Returns the Failure value for CalculatedECExpression of this property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetExpression =R"doc(Returns the CalculatedECExpression of this property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetPickListName =R"doc(Changes the PickList Name of this property This will set PickList
source as 'DgnFile' & PickList setting as

:param pickListName:
    $:param pickListName:

The PickList Name to be set.

:returns:
    true if the pickListName was successfully set.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetPickListName =R"doc(Returns the PickList Name of this property This will return
PickListSetting if PickListSource is DgnFile.

:param v:
    Holds the PickList Name, if it was obtained successfully

:returns:
    true if the PickList Name was obtained.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_CompareTo =R"doc(Returns true if this property is equivalent to the specified property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetDefaultValue =R"doc(Changes the default value of this property. The value must be of a
type compatible with GetType(). Default values are not supported for
properties of Type::Custom

:param v:
    The new default value.

:returns:
    true if the default value was successfully set.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetDefaultValue =R"doc(Returns the default value of this property.

:param v:
    Holds the default value, if it was obtained successfully

:returns:
    true if the default value was obtained.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_DecrementPriority =R"doc(Decrements the priority of this property, if a property of lower
priority exists.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_IncrementPriority =R"doc(Increments the priority of this property, if a property of higher
priority exists.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetPriority =R"doc(Returns the priority of this property. The priority controls the order
in which properties are displayed in the UI.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetId =R"doc(Returns the unique ID of this property within its
CustomPropertyContainer.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetContainerId =R"doc(Returns the ID of the CustomPropertyContainer to which this property
belongs. The ID is unique within the containing ItemTypeLibrary.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetContainer =R"doc(Returns the CustomPropertyContainer to which the property belongs)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetUnits =R"doc(Changes the units associated with this property, if the property type
supports units. @See SupportsUnits If you pass empty unit, like
SetUnits(DgnECUnit()), it will clear unit already set to property.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetUnits =R"doc(Returns the units associated with this property.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SupportsUnits =R"doc(Returns true if this property is of a type which supports units.
Properties of type Double and Point support units.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetIsArray =R"doc(Sets whether or not this property is an array.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_IsArray =R"doc(Returns true if this property is an array)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetName =R"doc(Changes the name of this property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetName =R"doc(Returns the name of this property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SupportsCustomType =R"doc(Returns true if the property can be assigned a Custom type. Properties
of CustomPropertyTypes cannot themselves be of a Custom type.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetType =R"doc(Changes the type of this property.

:param type:
    The new type. Cannot be Type::Custom - use
    SetType(CustomPropertyTypeCR) overload to set the custom type.

:returns:
    true if the type was successfully changed.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetType =R"doc(Returns the type of this property)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetIsReadOnlyProperty =R"doc(Sets whether or not this property is readOnly.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_IsReadOnlyProperty =R"doc(Returns true if this property is readOnly)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetIsHiddenProperty =R"doc(Sets whether or not this property is hidden.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_IsHiddenProperty =R"doc(Returns true if this property is hidden)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetPickListSource =R"doc(Returns registered IPickListProvider name

:param v:
    Holds the name of IPickListProvider

:returns:
    true if the PickList setting was obtained.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetPickListSource =R"doc(Set the pickList source on property. IPickListProvider with input name
must exist

:param IPickListProvider:
    Name

:returns:
    true if settings was successfully set.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetPickListSettings =R"doc(Returns the PickList settings

:param v:
    Holds the PickList settings for registered IPickListProvider

:returns:
    true if the PickList setting was obtained.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_SetPickListSettings =R"doc(Set the pickList setting on property

:param Settings:
    as per registered IPickListProvider

:returns:
    true if settings was successfully set.)doc";

static const char * __doc_Bentley_DgnPlatform_CustomProperty_GetInternalName =R"doc(Retuens Internal name)doc";


//=======================================================================================
// Trampoline class for IPickListProvider.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyPickListProvider : IPickListProvider
    {
    public:
        using IPickListProvider::IPickListProvider;

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool IsActive() const override
            { PYBIND11_OVERRIDE_EXR(bool, IPickListProvider, IsActive, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool GetStandardValues(DgnFileP dgnFile, ECN::ECPropertyCP ecProperty, ECN::PrimitiveType primitiveType, StandardValuesCollection& values) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, IPickListProvider, GetStandardValues, false, dgnFile, ecProperty, primitiveType, values); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool IsValidSettings(WCharCP settings) const override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, IPickListProvider, IsValidSettings, false, settings); }
    };

/*---------------------------------------------------------------------------------**//**
* Bind generator for ItemTypeLibraryComponent.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
template <typename ValueType, typename holder_type = std::unique_ptr< ItemTypeLibraryComponent<ValueType> >, typename... Args>
py::class_<ItemTypeLibraryComponent<ValueType>, holder_type> bind_ItemTypeLibraryComponent(py::handle scope, std::string const& name, Args &&...args)
    {
    using Container = ItemTypeLibraryComponent<ValueType>;
    using Class_ = py::class_<Container, holder_type>;

    auto* vtype_info = py::detail::get_type_info(typeid(ValueType));
    bool local = !vtype_info || vtype_info->module_local;

    Class_ cl(scope, name.c_str(), py::module_local(local), std::forward<Args>(args)...);

    cl.def_property_readonly("Guid", &Container::GetGuid);
    cl.def("GetGuid", &Container::GetGuid);

    cl.def_property_readonly("Library", [] (Container& self) { return ItemTypeLibraryPtr(&self.GetLibrary()); });
    cl.def("GetLibrary", [] (Container& self) { return ItemTypeLibraryPtr(&self.GetLibrary()); });

    return cl;
    }

using CustomPropertyPtr = std::unique_ptr<CustomProperty, py::nodelete>;
using CustomPropertyTypePtr = std::unique_ptr<CustomPropertyType, py::nodelete>;
using ItemTypePtr = std::unique_ptr<ItemType, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CustomItemType(py::module_& m)
    {
    //===================================================================================
    // struct CustomProperty
    auto ItemTypeLibraryComponentECProperty = bind_ItemTypeLibraryComponent<ECN::ECProperty>(m, "ItemTypeLibraryComponentECProperty", py::module_local(false));
    py::class_<CustomProperty, CustomPropertyPtr> c1(m, "CustomProperty", ItemTypeLibraryComponentECProperty);
    //py::bind_vector<CustomPropertyArray>(m, "CustomPropertyArray", py::module_local(false));

    if (true)
        {
        py::enum_<CustomProperty::Type>(c1, "Type1")
            .value("eBoolean", CustomProperty::Type::Boolean)
            .value("eDateTime", CustomProperty::Type::DateTime)
            .value("eDouble", CustomProperty::Type::Double)
            .value("eInteger", CustomProperty::Type::Integer)
            .value("ePoint", CustomProperty::Type::Point)
            .value("eString", CustomProperty::Type::String)
            .value("eCustom", CustomProperty::Type::Custom)
            .export_values();
        }

    c1.def_property_readonly("InternalName", &CustomProperty::GetInternalName);
    c1.def("GetInternalName", &CustomProperty::GetInternalName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CustomProperty, GetInternalName));

    c1.def("SetPickListSettings", &CustomProperty::SetPickListSettings, "settings"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetPickListSettings));
    c1.def("GetPickListSettings", &CustomProperty::GetPickListSettings, "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, GetPickListSettings));
    c1.def("SetPickListSource", &CustomProperty::SetPickListSource, "picklistSource"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetPickListSource));
    c1.def("GetPickListSource", &CustomProperty::GetPickListSource, "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, GetPickListSource));

    c1.def_property("HiddenProperty", &CustomProperty::IsHiddenProperty, &CustomProperty::SetIsHiddenProperty);
    c1.def("IsHiddenProperty", &CustomProperty::IsHiddenProperty, DOC(Bentley, DgnPlatform, CustomProperty, IsHiddenProperty));
    c1.def("SetIsHiddenProperty", &CustomProperty::SetIsHiddenProperty, "hidden"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetIsHiddenProperty));
    
    c1.def_property("ReadOnlyProperty", &CustomProperty::IsReadOnlyProperty, &CustomProperty::SetIsReadOnlyProperty);
    c1.def("IsReadOnlyProperty", &CustomProperty::IsReadOnlyProperty, DOC(Bentley, DgnPlatform, CustomProperty, IsReadOnlyProperty));
    c1.def("SetIsReadOnlyProperty", &CustomProperty::SetIsReadOnlyProperty, "readOnly"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetIsReadOnlyProperty));
    
    c1.def("SetIsDefaultValueExpression", &CustomProperty::SetIsDefaultValueExpression, "IsDefaultValueExpression"_a);

    c1.def_property("Type", &CustomProperty::GetType, py::overload_cast<CustomProperty::Type>(&CustomProperty::SetType));
    c1.def("GetType", &CustomProperty::GetType, DOC(Bentley, DgnPlatform, CustomProperty, GetType));
    c1.def("SetType", py::overload_cast<CustomProperty::Type>(&CustomProperty::SetType), "type"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetType));
    
    c1.def_property_readonly("CustomType", [] (CustomProperty const& self) { return CustomPropertyTypePtr(const_cast<CustomPropertyTypeP>(self.GetCustomType())); });
    c1.def("GetCustomType", [] (CustomProperty const& self) { return CustomPropertyTypePtr(const_cast<CustomPropertyTypeP>(self.GetCustomType())); });

    c1.def("SupportsCustomType", &CustomProperty::SupportsCustomType, DOC(Bentley, DgnPlatform, CustomProperty, SupportsCustomType));    
    
    c1.def_property("Name", [](const CustomProperty& self) { return self.GetName(); }, [](CustomProperty& self, const WCharCP name) { self.SetName(name); });
    c1.def("GetName", &CustomProperty::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CustomProperty, GetName));
    c1.def("SetName", py::overload_cast<WCharCP>(&CustomProperty::SetName), "name"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetName));
    c1.def("SetName", py::overload_cast<WCharCP, bool>(&CustomProperty::SetName), "name"_a, "updateRefProperties"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetName));
    
    c1.def_property("Array", &CustomProperty::IsArray, &CustomProperty::SetIsArray);
    c1.def("IsArray", &CustomProperty::IsArray, DOC(Bentley, DgnPlatform, CustomProperty, IsArray));
    c1.def("SetIsArray", &CustomProperty::SetIsArray, "isArray"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetIsArray));

    c1.def("SupportsUnits", &CustomProperty::SupportsUnits, DOC(Bentley, DgnPlatform, CustomProperty, SupportsUnits));

    c1.def_property("Units", &CustomProperty::GetUnits, &CustomProperty::SetUnits);
    c1.def("GetUnits", &CustomProperty::GetUnits, DOC(Bentley, DgnPlatform, CustomProperty, GetUnits));
    c1.def("SetUnits", &CustomProperty::SetUnits, "unit"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetUnits));
    
    c1.def_property_readonly("Container", py::overload_cast<>(&CustomProperty::GetContainer));
    c1.def("GetContainer", py::overload_cast<>(&CustomProperty::GetContainer), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CustomProperty, GetContainer));
    
    c1.def_property_readonly("ContainerId", &CustomProperty::GetContainerId);
    c1.def("GetContainerId", &CustomProperty::GetContainerId, DOC(Bentley, DgnPlatform, CustomProperty, GetContainerId));

    c1.def_property_readonly("Id", &CustomProperty::GetId);
    c1.def("GetId", &CustomProperty::GetId, DOC(Bentley, DgnPlatform, CustomProperty, GetId));

    c1.def_property_readonly("Priority", &CustomProperty::GetPriority);
    c1.def("GetPriority", &CustomProperty::GetPriority, DOC(Bentley, DgnPlatform, CustomProperty, GetPriority));

    c1.def("IncrementPriority", &CustomProperty::IncrementPriority, DOC(Bentley, DgnPlatform, CustomProperty, IncrementPriority));
    c1.def("DecrementPriority", &CustomProperty::DecrementPriority, DOC(Bentley, DgnPlatform, CustomProperty, DecrementPriority));
    c1.def("SetType", py::overload_cast<CustomPropertyTypeCR>(&CustomProperty::SetType), "customType"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetType));
    c1.def("GetDefaultValue", &CustomProperty::GetDefaultValue, "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, GetDefaultValue));
    c1.def("SetDefaultValue", py::overload_cast<ECN::ECValueCR>(&CustomProperty::SetDefaultValue), "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetDefaultValue));
    c1.def("CompareTo", &CustomProperty::CompareTo, "other"_a, DOC(Bentley, DgnPlatform, CustomProperty, CompareTo));
    c1.def("GetPickListName", &CustomProperty::GetPickListName, "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, GetPickListName));
    c1.def("SetPickListName", &CustomProperty::SetPickListName, "pickListName"_a, DOC(Bentley, DgnPlatform, CustomProperty, SetPickListName));
    c1.def("GetExpression", &CustomProperty::GetExpression, "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, GetExpression));
    c1.def("GetExpressionFailureValue", &CustomProperty::GetExpressionFailureValue, "v"_a, DOC(Bentley, DgnPlatform, CustomProperty, GetExpressionFailureValue));
    c1.def("SetExpression", py::overload_cast<WCharCP, WCharCP>(&CustomProperty::SetExpression), "expression"_a, "failureValue"_a = nullptr, DOC(Bentley, DgnPlatform, CustomProperty, SetExpression));
    c1.def("SetExpression", py::overload_cast<WCharCP, bool, WCharCP>(&CustomProperty::SetExpression), "expression"_a, "useLastValidValueOnFailure"_a, "failureValue"_a = nullptr, DOC(Bentley, DgnPlatform, CustomProperty, SetExpression));
    c1.def("GetUseLastValidValueOnExpressionFailure", &CustomProperty::GetUseLastValidValueOnExpressionFailure, DOC(Bentley, DgnPlatform, CustomProperty, GetUseLastValidValueOnExpressionFailure));

    //===================================================================================
    // struct CustomPropertyContainer
    auto ItemTypeLibraryComponentECClass = bind_ItemTypeLibraryComponent<ECN::ECClass>(m, "ItemTypeLibraryComponentECClass", py::module_local(false));
    py::class_<CustomPropertyContainer> c2(m, "CustomPropertyContainer", ItemTypeLibraryComponentECClass);

    c2.def("GetInternalName", &CustomPropertyContainer::GetInternalName, py::return_value_policy::reference_internal);
    
    c2.def_property("Name", &CustomPropertyContainer::GetName, &CustomPropertyContainer::SetName);
    c2.def("GetName", &CustomPropertyContainer::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CustomPropertyContainer, GetName));
    c2.def("SetName", &CustomPropertyContainer::SetName, "name"_a, DOC(Bentley, DgnPlatform, CustomPropertyContainer, SetName));

    c2.def_property_readonly("Id", &CustomPropertyContainer::GetId);
    c2.def("GetId", &CustomPropertyContainer::GetId, DOC(Bentley, DgnPlatform, CustomPropertyContainer, GetId));

    c2.def_property_readonly("PropertyCount", &CustomPropertyContainer::GetPropertyCount);
    c2.def("GetPropertyCount", &CustomPropertyContainer::GetPropertyCount, DOC(Bentley, DgnPlatform, CustomPropertyContainer, GetPropertyCount));

    c2.def("__getitem__", [] (CustomPropertyContainerR self, size_t index)
           {
           if (index >= self.GetPropertyCount())
               throw py::index_error();

           CustomProperty& prop = *(self.begin() + index);
           return CustomPropertyPtr(&prop);
           });

    c2.def("GetPropertyById", [] (CustomPropertyContainer& self, UInt32 id) { return CustomPropertyPtr(self.GetPropertyById(id)); }, "id"_a);
    c2.def("GetPropertyByName", [] (CustomPropertyContainer& self, WCharCP name) { return CustomPropertyPtr(self.GetPropertyByName(name)); }, "name"_a);
    c2.def("GetPropertyByInternalName", [] (CustomPropertyContainer& self, WCharCP name) { return CustomPropertyPtr(self.GetPropertyByInternalName(name)); }, "name"_a);
    c2.def("AddProperty", [] (CustomPropertyContainer& self, WCharCP name, bool forCopy) { return CustomPropertyPtr(self.AddProperty(name, forCopy)); }, "name"_a, "forCopy"_a = false);
    c2.def("RemoveProperty", &CustomPropertyContainer::RemoveProperty, "id"_a, DOC(Bentley, DgnPlatform, CustomPropertyContainer, RemoveProperty));

    //===================================================================================
    // struct CustomPropertyType
    py::class_< CustomPropertyType, CustomPropertyTypePtr, CustomPropertyContainer> c3(m, "CustomPropertyType");
    
    c3.def("IsReferenced", &CustomPropertyType::IsReferenced, DOC(Bentley, DgnPlatform, CustomPropertyType, IsReferenced));
    c3.def("CompareTo", &CustomPropertyType::CompareTo, "other"_a, DOC(Bentley, DgnPlatform, CustomPropertyType, CompareTo));

    //===================================================================================
    // struct ItemType
    py::class_< ItemType, ItemTypePtr, CustomPropertyContainer> c4(m, "ItemType");

    c4.def("CompareTo", &ItemType::CompareTo, "other"_a, DOC(Bentley, DgnPlatform, ItemType, CompareTo));

    c4.def_property("IdentifyingItem", &ItemType::IsIdentifyingItem, &ItemType::SetIsIdentifyingItem);
    c4.def("IsIdentifyingItem", &ItemType::IsIdentifyingItem, DOC(Bentley, DgnPlatform, ItemType, IsIdentifyingItem));
    c4.def("SetIsIdentifyingItem", &ItemType::SetIsIdentifyingItem, "isIdentifyingItem"_a, DOC(Bentley, DgnPlatform, ItemType, SetIsIdentifyingItem));
    
    c4.def_property("LabelProperty",
                    [] (ItemType const& self) { return CustomPropertyPtr(const_cast<CustomPropertyP>(self.GetLabelProperty())); },
                    & ItemType::SetLabelProperty);
    c4.def("GetLabelProperty", [] (ItemType const& self) { return CustomPropertyPtr(const_cast<CustomPropertyP>(self.GetLabelProperty())); });    
    c4.def("SetLabelProperty", &ItemType::SetLabelProperty, "prop"_a, DOC(Bentley, DgnPlatform, ItemType, SetLabelProperty));

    //===================================================================================
    // struct ItemTypeLibrary
    py::class_<ItemTypeLibrary, ItemTypeLibraryPtr> c5(m, "ItemTypeLibrary");

    c5.def(py::init(&ItemTypeLibrary::Create), "name"_a, "dgnfile"_a, "forCopy"_a = false);
    c5.def_static("UpgradeIModelSchema", &ItemTypeLibrary::UpgradeIModelSchema, "schema"_a, "dgnfile"_a);    
    
    c5.def_property("Name", &ItemTypeLibrary::GetName, &ItemTypeLibrary::SetName);
    c5.def("GetName", &ItemTypeLibrary::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetName));
    c5.def("SetName", &ItemTypeLibrary::SetName, "name"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, SetName));

    c5.def_property_readonly("InternalName", &ItemTypeLibrary::GetInternalName);
    c5.def("GetInternalName", &ItemTypeLibrary::GetInternalName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetInternalName));
    
    c5.def_property_readonly("Id", &ItemTypeLibrary::GetId);
    c5.def("GetId", &ItemTypeLibrary::GetId, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetId));
    
    c5.def("IsPersistent", &ItemTypeLibrary::IsPersistent, DOC(Bentley, DgnPlatform, ItemTypeLibrary, IsPersistent));
    
    c5.def_property_readonly("DgnFile", &ItemTypeLibrary::GetDgnFile);
    c5.def("GetDgnFile", &ItemTypeLibrary::GetDgnFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetDgnFile));
    
    c5.def("AddItemType", [] (ItemTypeLibrary& self, WCharCP name, bool forCopy) { return ItemTypePtr(self.AddItemType(name, forCopy)); }, "name"_a, "forCopy"_a = false);
    c5.def("AddCustomType", [] (ItemTypeLibrary& self, WCharCP name, bool forCopy) { return CustomPropertyTypePtr(self.AddCustomType(name, forCopy)); }, "name"_a, "forCopy"_a = false);
    c5.def("RemoveItemType", &ItemTypeLibrary::RemoveItemType, "id"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, RemoveItemType));
    c5.def("RemoveCustomType", &ItemTypeLibrary::RemoveCustomType, "id"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, RemoveCustomType));
    c5.def("Revert", &ItemTypeLibrary::Revert, DOC(Bentley, DgnPlatform, ItemTypeLibrary, Revert));

    c5.def("Write", py::overload_cast<>(&ItemTypeLibrary::Write), DOC(Bentley, DgnPlatform, ItemTypeLibrary, Write));
    c5.def("Delete", &ItemTypeLibrary::Delete, DOC(Bentley, DgnPlatform, ItemTypeLibrary, Delete));
    c5.def("CompareTo", &ItemTypeLibrary::CompareTo, "other"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, CompareTo));

    c5.def_property_readonly("ItemTypeCount", &ItemTypeLibrary::GetItemTypeCount);
    c5.def("GetItemTypeCount", &ItemTypeLibrary::GetItemTypeCount, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetItemTypeCount));

    c5.def("GetItemTypeByName", [] (ItemTypeLibrary& self, WCharCP name) { return ItemTypePtr(self.GetItemTypeByName(name)); }, "name"_a);
    c5.def("GetItemTypeByInternalName", [] (ItemTypeLibrary& self, WCharCP name) { return ItemTypePtr(self.GetItemTypeByInternalName(name)); }, "name"_a);
    c5.def("GetItemTypeById", [] (ItemTypeLibrary& self, UInt32 id) { return ItemTypePtr(self.GetItemTypeById(id)); }, "id"_a);

    c5.def("GetItemTypeAt", [] (ItemTypeLibrary& self, size_t index)
           {
           if (index >= self.GetItemTypeCount())
               throw py::index_error();

           ItemType& itemType = *(self.begin() + index);
           return ItemTypePtr(&itemType);
           }, "index"_a);

    c5.def_property_readonly("CustomTypeCount", &ItemTypeLibrary::GetCustomTypeCount);
    c5.def("GetCustomTypeCount", &ItemTypeLibrary::GetCustomTypeCount, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetCustomTypeCount));

    c5.def("GetCustomTypeByName", [] (ItemTypeLibrary& self, WCharCP name) { return CustomPropertyTypePtr(self.GetCustomTypeByName(name)); }, "name"_a);
    c5.def("GetCustomTypeByInternalName", [] (ItemTypeLibrary& self, WCharCP name) { return CustomPropertyTypePtr(self.GetCustomTypeByInternalName(name)); }, "name"_a);
    c5.def("GetCustomTypeById", [] (ItemTypeLibrary& self, UInt32 id) { return CustomPropertyTypePtr(self.GetCustomTypeById(id)); }, "id"_a);

    c5.def("GetCustomTypeAt", [] (ItemTypeLibrary& self, size_t index)
           {
           if (index >= self.GetCustomTypeCount())
               throw py::index_error();

           CustomPropertyType& customType = *(self.CustomTypesBegin() + index);
           return CustomPropertyTypePtr(&customType);
           }, "index"_a);

    c5.def("GetPropertyContainerByName", py::overload_cast<WCharCP>(&ItemTypeLibrary::GetPropertyContainerByName), py::return_value_policy::reference_internal, "name"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetPropertyContainerByName));
    c5.def("GetPropertyContainerById", py::overload_cast<UInt32>(&ItemTypeLibrary::GetPropertyContainerById), py::return_value_policy::reference_internal, "id"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, GetPropertyContainerById));
    c5.def("GetPropertyByGuid", [] (ItemTypeLibrary& self, UInt32 guid) { return CustomPropertyPtr(self.GetPropertyByGuid(guid)); }, "guid"_a);
    c5.def_static("FindByName", &ItemTypeLibrary::FindByName, "name"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, FindByName));
    c5.def_static("FindBySchemaName", &ItemTypeLibrary::FindBySchemaName, "schemaName"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, FindBySchemaName));
    c5.def("CloneForFile", &ItemTypeLibrary::CloneForFile, "destFile"_a, "forReplacement"_a = false, DOC(Bentley, DgnPlatform, ItemTypeLibrary, CloneForFile));
    c5.def_static("IsItemTypeSchema", [] (WCharCP szSchemaName) { return ItemTypeLibrary::IsItemTypeSchema(szSchemaName); }, "schemaName"_a);
    c5.def_static("IsItemTypeSchema", py::overload_cast<ECN::ECSchemaCR>(&ItemTypeLibrary::IsItemTypeSchema), "schema"_a, DOC(Bentley, DgnPlatform, ItemTypeLibrary, IsItemTypeSchema));

    //===================================================================================
    // struct ItemTypeLibraries
    py::class_<ItemTypeLibraries, ItemTypeLibrariesPtr> c6(m, "ItemTypeLibraries");    
    
    if (true)
        {
        //===================================================================================
        // struct Entry
        py::class_<ItemTypeLibraries::Entry> c6_1(c6, "Entry");
        c6_1.def(py::init<ItemTypeLibraries::Entry const&>(), "other"_a);

        c6_1.def_property_readonly("Schema", &ItemTypeLibraries::Entry::GetSchema);
        c6_1.def("GetSchema", &ItemTypeLibraries::Entry::GetSchema, py::return_value_policy::reference_internal);
        
        c6_1.def_property_readonly("Id", &ItemTypeLibraries::Entry::GetId);
        c6_1.def("GetId", &ItemTypeLibraries::Entry::GetId);
        
        c6_1.def_property_readonly("Library", &ItemTypeLibraries::Entry::ObtainLibrary);
        c6_1.def("ObtainLibrary", &ItemTypeLibraries::Entry::ObtainLibrary);
        }

    c6.def_property_readonly("DgnFile", &ItemTypeLibraries::GetDgnFile);
    c6.def("GetDgnFile", &ItemTypeLibraries::GetDgnFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ItemTypeLibraries, GetDgnFile));

    c6.def("__iter__", [] (ItemTypeLibrariesR self) { return py::make_iterator(self.begin(), self.end()); });
    c6.def("__len__", &ItemTypeLibraries::size);
    c6.def("size", &ItemTypeLibraries::size, DOC(Bentley, DgnPlatform, ItemTypeLibraries, size));
    c6.def(py::init(&ItemTypeLibraries::Create), "dgnFile"_a);

    //===================================================================================
    // struct CustomItemHost
    py::class_< CustomItemHost> c7(m, "CustomItemHost");

    c7.def(py::init<ElementHandleCR>(), "eh"_a);
    c7.def(py::init<EditElementHandleR, bool>(), "eeh"_a, "scheduleItems"_a = true);
    c7.def(py::init<DgnModelR>(), "model"_a);
    c7.def(py::init<DgnFileR>(), "dgnFile"_a);
    c7.def(py::init<ViewGroupR, UInt32>(), "viewGroup"_a, "viewIndex"_a);


    c7.def_property_readonly("DgnFile", &CustomItemHost::GetDgnFile);
    c7.def("GetDgnFile", &CustomItemHost::GetDgnFile, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, CustomItemHost, GetDgnFile));

    c7.def("GetCustomItems", py::overload_cast<DgnECInstanceVector&>(&CustomItemHost::GetCustomItems, py::const_), "items"_a, DOC(Bentley, DgnPlatform, CustomItemHost, GetCustomItems));

    c7.def_property_readonly("CustomItemsCount", &CustomItemHost::GetCustomItemsCount);
    c7.def("GetCustomItemsCount", &CustomItemHost::GetCustomItemsCount, DOC(Bentley, DgnPlatform, CustomItemHost, GetCustomItemsCount));
    
    c7.def("GetCustomItem", &CustomItemHost::GetCustomItem, "libraryName"_a, "itemTypeName"_a, DOC(Bentley, DgnPlatform, CustomItemHost, GetCustomItem));
    c7.def("ApplyCustomItem", py::overload_cast<ItemTypeCR>(&CustomItemHost::ApplyCustomItem, py::const_), "itemType"_a, DOC(Bentley, DgnPlatform, CustomItemHost, ApplyCustomItem));
    c7.def("ApplyCustomItem", py::overload_cast<ItemTypeCR, bool>(&CustomItemHost::ApplyCustomItem, py::const_), "itemType"_a, "importLibiariesIfRequired"_a, DOC(Bentley, DgnPlatform, CustomItemHost, ApplyCustomItem));
    c7.def("CopyCustomItems", py::overload_cast<CustomItemHostCR, bool>(&CustomItemHost::CopyCustomItems, py::const_), "src"_a, "importLibrariesIfRequired"_a = false, DOC(Bentley, DgnPlatform, CustomItemHost, CopyCustomItems));

    //===================================================================================
    // struct IPickListProvider
    py::class_< IPickListProvider, IPyPickListProvider> c9(m, "IPickListProvider");

    c9.def_static("GetProviderName", &IPickListProvider::GetProviderName, "ecProperty"_a, "v"_a, DOC(Bentley, DgnPlatform, IPickListProvider, GetProviderName));
    c9.def_static("GetProviderSettings", &IPickListProvider::GetProviderSettings, "ecProperty"_a, "v"_a, DOC(Bentley, DgnPlatform, IPickListProvider, GetProviderSettings));
    c9.def(py::init<WCharCP>(), "name"_a);

    c9.def_property_readonly("Name", &IPickListProvider::GetName);
    c9.def("GetName", &IPickListProvider::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IPickListProvider, GetName));    
    
    c9.def_property("DisplayLabel", &IPickListProvider::GetDisplayLabel, &IPickListProvider::SetDisplayLabel);
    c9.def("GetDisplayLabel", &IPickListProvider::GetDisplayLabel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IPickListProvider, GetDisplayLabel));
    c9.def("SetDisplayLabel", &IPickListProvider::SetDisplayLabel, "displayLabel"_a, DOC(Bentley, DgnPlatform, IPickListProvider, SetDisplayLabel));    
    
    c9.def("IsActive", &IPickListProvider::IsActive, DOC(Bentley, DgnPlatform, IPickListProvider, IsActive));
    c9.def("GetStandardValues", &IPickListProvider::GetStandardValues, "dgnFile"_a, "ecProperty"_a, "primitiveType"_a, "values"_a, DOC(Bentley, DgnPlatform, IPickListProvider, GetStandardValues));
    c9.def("IsValidSettings", py::overload_cast<WCharCP>(&IPickListProvider::IsValidSettings, py::const_), "settings"_a, DOC(Bentley, DgnPlatform, IPickListProvider, IsValidSettings));
    }