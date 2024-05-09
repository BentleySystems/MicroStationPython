/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\standardcustomattributehelper.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/StandardCustomAttributeHelper.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_StandardCustomAttributeHelper(py::module_& m)
    {
    //===================================================================================
    // struct DateTimeInfo
    py::class_< DateTimeInfo> c1(m, "DateTimeInfo");

    c1.def(py::init<>());
    c1.def(py::init<DateTime::Info const&>(), "metadata"_a);
    c1.def(py::self == py::self);
    c1.def(py::self != py::self);
    c1.def("IsKindNull", &DateTimeInfo::IsKindNull);
    c1.def("IsComponentNull", &DateTimeInfo::IsComponentNull);
    c1.def("GetInfo", py::overload_cast<bool>(&DateTimeInfo::GetInfo, py::const_), "useDefaultIfUnset"_a);
    
    c1.def_property_readonly_static("Default", [] (py::object const&) { return DateTimeInfo::GetDefault(); });
    c1.def_static("GetDefault", &DateTimeInfo::GetDefault, py::return_value_policy::reference);
    
    c1.def("IsMatchedBy", &DateTimeInfo::IsMatchedBy, "rhs");
    c1.def("ToString", &DateTimeInfo::ToString);

    //===================================================================================
    // struct StandardCustomAttributeHelper
    py::class_< StandardCustomAttributeHelper, std::unique_ptr<StandardCustomAttributeHelper, py::nodelete> > c2(m, "StandardCustomAttributeHelper");

    c2.def_static("TryGetDateTimeInfo", &StandardCustomAttributeHelper::TryGetDateTimeInfo, "dateTimeInfo"_a, "dateTimeProperty"_a);
    c2.def_static("IsSystemSchema", &StandardCustomAttributeHelper::IsSystemSchema, "schema"_a);
    c2.def_static("IsDynamicSchema", &StandardCustomAttributeHelper::IsDynamicSchema, "schema"_a);
    c2.def_static("SetIsDynamicSchema", &StandardCustomAttributeHelper::SetIsDynamicSchema, "schema"_a, "isDynamicSchema"_a);
    c2.def_static("GetCustomAttributeClass", &StandardCustomAttributeHelper::GetCustomAttributeClass, "attributeName"_a, py::return_value_policy::reference);
    c2.def_static("CreateCustomAttributeInstance", &StandardCustomAttributeHelper::CreateCustomAttributeInstance, "atributeName"_a);
    }