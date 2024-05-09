/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\presentationmetadatahelper.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/PresentationMetadataHelper.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_PresentationMetadataHelper(py::module_& m)
    {
    //===================================================================================
    // enum class PropertySortPriority
    py::enum_< PropertySortPriority>(m, "PropertySortPriority")
        .value("eVeryHigh", PropertySortPriority::VeryHigh)
        .value("eHigh", PropertySortPriority::High)
        .value("eMedium", PropertySortPriority::Medium)
        .value("eLow", PropertySortPriority::Low)
        .value("eVeryLow", PropertySortPriority::VeryLow)
        .export_values();

    //===================================================================================
    // enum class CategorySortPriority
    py::enum_< CategorySortPriority>(m, "CategorySortPriority")
        .value("eVeryHigh", CategorySortPriority::VeryHigh)
        .value("eHigh", CategorySortPriority::High)
        .value("eMedium", CategorySortPriority::Medium)
        .value("eLow", CategorySortPriority::Low)
        .value("eVeryLow", CategorySortPriority::VeryLow)
        .export_values();

    //===================================================================================
    // struct PresentationMetadataHelper
    py::class_< PresentationMetadataHelper> c1(m, "PresentationMetadataHelper");

    c1.def(py::init<ECSchemaReadContextR>(), "schemaContext"_a);

    c1.def("SetStandardCategory", 
           &PresentationMetadataHelper::SetStandardCategory,
           "ecProperty"_a, "standardCategoryId"_a);

    c1.def("SetCustomCategory", 
           &PresentationMetadataHelper::SetCustomCategory,
           "ecProperty"_a, "uniqueName"_a, "displayLabel"_a, "priority"_a, "expand"_a = false, "description"_a = nullptr);

    c1.def("SetExtendedType", 
           py::overload_cast<ECPropertyR, int32_t>(&PresentationMetadataHelper::SetExtendedType, py::const_),
           "ecProperty"_a, "standardTypeId"_a);

    c1.def("SetExtendedType",
           py::overload_cast<ECPropertyR, WCharCP>(&PresentationMetadataHelper::SetExtendedType, py::const_),
           "ecProperty"_a, "standardTypeName"_a);

    c1.def("SetMemberExtendedType", 
           py::overload_cast<ArrayECPropertyR, int32_t>(&PresentationMetadataHelper::SetMemberExtendedType, py::const_),
           "ecProperty"_a, "standardTypeId"_a);

    c1.def("SetMemberExtendedType",
           py::overload_cast<ArrayECPropertyR, WCharCP>(&PresentationMetadataHelper::SetMemberExtendedType, py::const_),
           "ecProperty"_a, "standardTypeName"_a);

    c1.def("SetPriority", &PresentationMetadataHelper::SetPriority, "ecProperty"_a, "priority"_a);
    
    c1.def("SetIgnoreZ", &PresentationMetadataHelper::SetIgnoreZ, "ecProperty"_a);    

    c1.def("SetMembersIndependent", &PresentationMetadataHelper::SetMembersIndependent, "ecProperty"_a);

    c1.def("SetAlwaysExpand", &PresentationMetadataHelper::SetAlwaysExpand, "ecProperty"_a, "andArrayMembers"_a = false);

    c1.def("SetRequiresReload", &PresentationMetadataHelper::SetRequiresReload, "ecProperty"_a);

    c1.def("SetHideNullProperties", &PresentationMetadataHelper::SetHideNullProperties, "ecClass"_a);

    c1.def("SetStoresUnitsAsUORs", &PresentationMetadataHelper::SetStoresUnitsAsUORs, "ecSchema"_a);

    c1.def("HideProperty", 
           py::overload_cast<ECPropertyR>(&PresentationMetadataHelper::HideProperty, py::const_),
           "ecProperty"_a);

    c1.def("HideProperty",
           py::overload_cast<ECPropertyR, bool, bool>(&PresentationMetadataHelper::HideProperty, py::const_),
           "ecProperty"_a, "hideIf2D"_a, "hideIf3D"_a);
    }