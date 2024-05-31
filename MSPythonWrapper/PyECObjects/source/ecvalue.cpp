/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecvalue.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECValue.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECValue(py::module_& m)
    {
    //===================================================================================
    // struct ArrayInfo
    py::class_< ArrayInfo> c1(m, "ArrayInfo");

    c1.def_property_readonly("Count", &ArrayInfo::GetCount);
    c1.def("GetCount", &ArrayInfo::GetCount);

    c1.def("IsFixedCount", &ArrayInfo::IsFixedCount);
    c1.def("IsPrimitiveArray", &ArrayInfo::IsPrimitiveArray);
    c1.def("IsStructArray", &ArrayInfo::IsStructArray);
    
    c1.def_property_readonly("Kind", &ArrayInfo::GetKind);
    c1.def("GetKind", &ArrayInfo::GetKind);
    
    c1.def_property_readonly("ElementPrimitiveType", &ArrayInfo::GetElementPrimitiveType);
    c1.def("GetElementPrimitiveType", &ArrayInfo::GetElementPrimitiveType);

    //===================================================================================
    // struct ECValue
    py::class_< ECValue> c2(m, "ECValue");

    c2.def("Clear", &ECValue::Clear);
    c2.def(py::init<>());
    c2.def(py::init<ValueKind>(), "classification"_a);
    c2.def(py::init<PrimitiveType>(), "primitive"_a);
    c2.def(py::init<Int32>(), "integer32"_a);

    //For C++ ECValue(bool), if we only true/false to it, in pybind11 logic, currently it calls ECValue(Int32)
    //for this case.To prevent this implicit convert, for its corresponding binding in pybind11 side, we implement its pybind11
    //binding as ECValue(bool, bool), a bool parameter is added to prevent this implicit convert. In this file if
    //c2.def(py::init<bool>(), py::arg("").noconvert()) is before c2.def(py::init<Int32>(), py::arg("").noconvert()),
    //we need to this way to binding C++ ECValue (int)
    //c2.def(py::init<bool>(), py::arg("").noconvert());
    c2.def(py::init ([](bool value, bool dummy) {return new ECValue(value);}));

    //For C++ ECValue(::Int64), if we only pass 3 to it, in pybind11 logic, currently it calls ECValue(Int32)
    //for this case.To prevent this implicit convert, for its corresponding binding in pybind11 side, we implement its pybind11
    //binding as ECValue(::Int64, bool), a bool parameter is added to prevent this implicit convert
    //c2.def(py::init<Int64>(), py::arg("").noconvert());
    c2.def(py::init([] (Int64 value, bool dummy) {return new ECValue(value);}));

    c2.def(py::init<double>(), "doubleVal"_a);
    c2.def(py::init([] (WStringCR string, bool holdADuplicate) { return new ECValue(string.c_str(), holdADuplicate); }), "string"_a, "bool"_a = true);
    c2.def(py::init([] (Utf8StringCR string, bool holdADuplicate) { return new ECValue(string.c_str(), holdADuplicate); }), "string"_a, "bool"_a = true);
    c2.def(py::init([](WCharCP string, bool holdADuplicate) { return new ECValue(string, holdADuplicate); }), "string"_a, "bool"_a = true);

    c2.def(py::init([] (py::bytes const& blob)
                    {
                    std::string strData = blob.cast<std::string>();
                    return new ECValue((const Byte*) strData.data(), strData.size());
                    }), "blob"_a);

    c2.def(py::init<DPoint2dCR>(), "point2d"_a);
    c2.def(py::init<DPoint3dCR>(), "point3d"_a);

    c2.def(py::init<DateTimeCR>(), "dateTime"_a);

    c2.def_property("ReadOnly", &ECValue::IsReadOnly, &ECValue::SetIsReadOnly);
    c2.def("IsReadOnly", &ECValue::IsReadOnly);
    c2.def("SetIsReadOnly", &ECValue::SetIsReadOnly, "readOnly"_a);
    
    c2.def_property("Null", &ECValue::IsNull, &ECValue::SetIsNull);
    c2.def("IsNull", &ECValue::IsNull);
    c2.def("SetIsNull", &ECValue::SetIsNull, "null"_a);
    
    c2.def_property("Loaded", &ECValue::IsLoaded, &ECValue::SetIsLoaded);    
    c2.def("IsLoaded", &ECValue::IsLoaded);
    c2.def("SetIsLoaded", &ECValue::SetIsLoaded, "loaded"_a);
    
    c2.def("SetToNull", &ECValue::SetToNull);
    c2.def("From", &ECValue::From, "value"_a);
    
    c2.def_property_readonly("Kind", &ECValue::GetKind);
    c2.def("GetKind", &ECValue::GetKind);
    
    c2.def("IsUninitialized", &ECValue::IsUninitialized);

    c2.def("SetToNull", &ECValue::SetToNull);
    c2.def("IsString", &ECValue::IsString);
    c2.def("IsUtf8", &ECValue::IsUtf8);
    c2.def("IsInteger", &ECValue::IsInteger);
    c2.def("IsLong", &ECValue::IsLong);
    c2.def("IsDouble", &ECValue::IsDouble);
    c2.def("IsBinary", &ECValue::IsBinary);
    c2.def("IsBoolean", &ECValue::IsBoolean);
    c2.def("IsPoint2D", &ECValue::IsPoint2D);
    c2.def("IsPoint3D", &ECValue::IsPoint3D);
    c2.def("IsDateTime", &ECValue::IsDateTime);
    c2.def("IsIGeometry", &ECValue::IsIGeometry);
    c2.def("IsArray", &ECValue::IsArray);
    c2.def("IsStruct", &ECValue::IsStruct);
    c2.def("IsPrimitive", &ECValue::IsPrimitive);

    c2.def_property("PrimitiveType", &ECValue::GetPrimitiveType, &ECValue::SetPrimitiveType);
    c2.def("GetPrimitiveType", &ECValue::GetPrimitiveType);
    c2.def("SetPrimitiveType", &ECValue::SetPrimitiveType, "type"_a);

    c2.def("CanConvertToPrimitiveType", &ECValue::CanConvertToPrimitiveType, "type"_a);
    c2.def("SetStructArrayInfo", &ECValue::SetStructArrayInfo, "count"_a, "isFixedSize"_a);
    c2.def("SetPrimitiveArrayInfo", &ECValue::SetPrimitiveArrayInfo, "primitiveElementType"_a, "count"_a, "isFixedSize"_a);
    c2.def_property_readonly("ArrayInfo", &ECValue::GetArrayInfo);
    c2.def("GetArrayInfo", &ECValue::GetArrayInfo);

    c2.def_property("Integer", &ECValue::GetInteger, &ECValue::SetInteger);
    c2.def("GetInteger", &ECValue::GetInteger);
    c2.def("SetInteger", &ECValue::SetInteger, "integer"_a);
    
    c2.def_property("Long", &ECValue::GetLong, &ECValue::SetLong);
    c2.def("GetLong", &ECValue::GetLong);
    c2.def("SetLong", &ECValue::SetLong, "long64"_a);
    
    c2.def_property("Boolean", &ECValue::GetBoolean, &ECValue::SetBoolean);
    c2.def("GetBoolean", &ECValue::GetBoolean);
    c2.def("SetBoolean", &ECValue::SetBoolean, "boolean"_a);
    
    c2.def_property("Double", &ECValue::GetDouble, &ECValue::SetDouble);
    c2.def("GetDouble", &ECValue::GetDouble);
    c2.def("SetDouble", &ECValue::SetDouble, "dblVal"_a);

    c2.def_property_readonly("String", &ECValue::GetString);
    c2.def("GetString", &ECValue::GetString, py::return_value_policy::reference_internal);

    c2.def_property_readonly("Utf8String", &ECValue::GetUtf8CP);
    c2.def("GetUtf8CP", &ECValue::GetUtf8CP, py::return_value_policy::reference_internal);

    c2.def("SetString", [] (ECValueR self, WStringCR string, bool holdADuplicate) { self.SetString(string.c_str(), holdADuplicate); }, "string"_a, "bool"_a = true);
    c2.def("SetString", [] (ECValueR self, Utf8StringCR string, bool holdADuplicate) { self.SetUtf8CP(string.c_str(), holdADuplicate); }, "string"_a, "bool"_a = true);
    c2.def("SetString", [] (ECValueR self, WCharCP string, bool holdADuplicate) { self.SetString(string, holdADuplicate); }, "string"_a, "bool"_a = true);

    c2.def_property("Binary",
                    [] (ECValueCR self)
                    {
                    py::bytes outVal;
                    size_t dataSize = 0;
                    const Byte* pData = self.GetBinary(dataSize);
                    if (nullptr != pData && dataSize > 0)
                        outVal = py::bytes((const char*) pData, dataSize);
                    return outVal;
                    },
                    [] (ECValueR self, py::bytes const& data)
                        {
                        if (py::len(data) > 0)
                            {
                            std::string strData = data.cast<std::string>();
                            self.SetBinary((const Byte*) strData.data(), strData.size(), true);
                            }
                        });
    c2.def("GetBinary", [] (ECValueCR self)
           {
           py::bytes outVal;
           size_t dataSize = 0;
           const Byte* pData = self.GetBinary(dataSize);
           if (nullptr != pData && dataSize > 0)
               outVal = py::bytes((const char*) pData, dataSize);
           return outVal;
           });

    c2.def("SetBinary", [] (ECValueR self, py::bytes const& data)
           {
           if (py::len(data) > 0)
               {
               std::string strData = data.cast<std::string>();
               self.SetBinary((const Byte*) strData.data(), strData.size(), true);
               }
           });

    c2.def_property("IGeometry", py::overload_cast<>(&ECValue::GetIGeometry, py::const_), py::overload_cast<IGeometryCR>(&ECValue::SetIGeometry));
    c2.def("GetIGeometry", py::overload_cast<>(&ECValue::GetIGeometry, py::const_));
    c2.def("SetIGeometry", py::overload_cast<IGeometryCR>(&ECValue::SetIGeometry), "geometry"_a);

    c2.def_property("Struct", &ECValue::GetStruct, &ECValue::SetStruct);
    c2.def("GetStruct", &ECValue::GetStruct);
    c2.def("SetStruct", &ECValue::SetStruct, "instance"_a);
    
    c2.def_property("DateTime", &ECValue::GetDateTime, &ECValue::SetDateTime);
    c2.def("GetDateTime", &ECValue::GetDateTime);
    c2.def("SetDateTime", &ECValue::SetDateTime, "dateTime"_a);

    c2.def_property("DateTimeTicks", py::overload_cast<>(&ECValue::GetDateTimeTicks, py::const_), py::overload_cast<int64_t>(&ECValue::SetDateTimeTicks));
    c2.def("GetDateTimeTicks", py::overload_cast<>(&ECValue::GetDateTimeTicks, py::const_));
    c2.def("SetDateTimeTicks", py::overload_cast<int64_t>(&ECValue::SetDateTimeTicks), "ceTicks"_a);

    c2.def_property_readonly("DateTimeUnixMillis", &ECValue::GetDateTimeUnixMillis);
    c2.def("GetDateTimeUnixMillis", &ECValue::GetDateTimeUnixMillis);

    c2.def("GetDateTimeTicksEx", [] (ECValueCR self)
           {
           bool hasMeta = false;
           DateTime::Info metaData;
           auto retVal = self.GetDateTimeTicks(hasMeta, metaData);
           return py::make_tuple(retVal, hasMeta, metaData);
           });

    c2.def("SetDateTimeTicks", py::overload_cast<int64_t, DateTime::Info const&>(&ECValue::SetDateTimeTicks), "ceTicks"_a, "dateTimeMetaData"_a);
    c2.def_property("Point2D", &ECValue::GetPoint2D, &ECValue::SetPoint2D);
    c2.def("GetPoint2D", &ECValue::GetPoint2D);
    c2.def("SetPoint2D", &ECValue::SetPoint2D, "value"_a);
    
    c2.def_property("Point3D", &ECValue::GetPoint3D, &ECValue::SetPoint3D);
    c2.def("GetPoint3D", &ECValue::GetPoint3D);
    c2.def("SetPoint3D", &ECValue::SetPoint3D, "value"_a);
    
    c2.def("ToString", &ECValue::ToString);
    c2.def("__eq__", [] (ECValueCR self, ECValueCR other) { return self.Equals(other); });

    //===================================================================================
    // struct ECValueAccessor
    py::class_< ECValueAccessor> c3(m, "ECValueAccessor");

    if (true)
        {
        //===================================================================================
        // struct Location
        py::class_< ECValueAccessor::Location> c3_1(c3, "Location");

        c3_1.def(py::init<>());
        c3_1.def(py::init<ECEnablerCP, int, int>(), "enaber"_a, "propIdx"_a, "arrayIdx"_a);
        c3_1.def_property_readonly("Enabler", &ECValueAccessor::Location::GetEnabler);
        c3_1.def("GetEnabler", &ECValueAccessor::Location::GetEnabler, py::return_value_policy::reference_internal);

        c3_1.def_property_readonly("ECProperty", [] (ECValueAccessor::Location const& self) 
                                   { 
                                   return std::unique_ptr<ECProperty, py::nodelete>(const_cast<ECPropertyP>(self.GetECProperty())); 
                                   });

        c3_1.def("GetECProperty", [] (ECValueAccessor::Location const& self) { return std::unique_ptr<ECProperty, py::nodelete>(const_cast<ECPropertyP>(self.GetECProperty())); });
        }

    c3.def(py::init<>());
    c3.def_property_readonly("Depth", &ECValueAccessor::GetDepth);    
    c3.def("GetDepth", &ECValueAccessor::GetDepth);    

    c3.def("GetAccessString", 
           py::overload_cast<>(&ECValueAccessor::GetAccessString, py::const_), 
           py::return_value_policy::reference_internal);

    c3.def("GetAccessString", 
           py::overload_cast<uint32_t>(&ECValueAccessor::GetAccessString, py::const_),
           "depth"_a, py::return_value_policy::reference_internal);

    c3.def("PushLocation",
           py::overload_cast<ECEnablerCR, int, int>(&ECValueAccessor::PushLocation),
           "enabler"_a, "propertyIndex"_a, "arrayIndex"_a = ECValueAccessor::INDEX_ROOT);

    c3.def("PushLocation",
           py::overload_cast<ECEnablerCR, WCharCP, int>(&ECValueAccessor::PushLocation),
           "enabler"_a, "accessString"_a, "arrayIndex"_a = ECValueAccessor::INDEX_ROOT);

    c3.def("PushLocation",
           py::overload_cast<IECInstanceCR, int, int>(&ECValueAccessor::PushLocation),
           "instance"_a, "propertyIndex"_a, "arrayIndex"_a = ECValueAccessor::INDEX_ROOT);

    c3.def("PushLocation",
           py::overload_cast<IECInstanceCR, WCharCP, int>(&ECValueAccessor::PushLocation),
           "instance"_a, "accessString"_a, "arrayIndex"_a = ECValueAccessor::INDEX_ROOT);

    c3.def("PopLocation", &ECValueAccessor::PopLocation);    
    c3.def("DeepestLocation", &ECValueAccessor::DeepestLocation);
    c3.def("Clear", &ECValueAccessor::Clear);
    
    c3.def_property_readonly("PropertyName", &ECValueAccessor::GetPropertyName);
    c3.def("GetPropertyName", &ECValueAccessor::GetPropertyName);
    
    c3.def_property_readonly("ManagedAccessString", &ECValueAccessor::GetManagedAccessString);
    c3.def("GetManagedAccessString", &ECValueAccessor::GetManagedAccessString);
    
    c3.def(py::self == py::self);
    c3.def(py::self != py::self);

    c3.def_static("PopulateValueAccessor",
                  py::overload_cast<ECValueAccessor&, IECInstanceCR, WCharCP>(&ECValueAccessor::PopulateValueAccessor),
                  "va"_a, "instance"_a, "managedAccessor"_a);

    c3.def_static("PopulateValueAccessor",
                  py::overload_cast<ECValueAccessor&, ECEnablerCR, WCharCP>(&ECValueAccessor::PopulateValueAccessor),
                  "va"_a, "enabler"_a, "managedAccessor"_a);

    //===================================================================================
    // struct ECPropertyValue
    py::class_< ECPropertyValue, ECPropertyValuePtr> c4(m, "ECPropertyValue");

    c4.def_property_readonly("Instance", &ECPropertyValue::GetInstance);
    c4.def("GetInstance", &ECPropertyValue::GetInstance, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("Value", &ECPropertyValue::GetValue);
    c4.def("GetValue", &ECPropertyValue::GetValue, py::return_value_policy::reference_internal);
    
    c4.def_property_readonly("ValueAccessor", &ECPropertyValue::GetValueAccessor);
    c4.def("GetValueAccessor", &ECPropertyValue::GetValueAccessor, py::return_value_policy::reference_internal);
    
    c4.def("HasChildValues", &ECPropertyValue::HasChildValues);
    
    c4.def_property_readonly("ChildValues", &ECPropertyValue::GetChildValues);
    c4.def("GetChildValues", &ECPropertyValue::GetChildValues, py::return_value_policy::reference_internal);
    
    c4.def_static("GetPropertyValue", &ECPropertyValue::GetPropertyValue, "instance"_a, "propertyAccessor"_a);

    //===================================================================================
    // struct ECValuesCollection
    py::class_< ECValuesCollection, ECValuesCollectionPtr> c5(m, "ECValuesCollection");

    c5.def_static ("Create", py::overload_cast<IECInstanceCR>(&ECValuesCollection::Create), "instance"_a);
    c5.def_static ("Create", py::overload_cast<ECPropertyValueCR>(&ECValuesCollection::Create), "propertyValue"_a);

    c5.def_property_readonly("ParentProperty", [] (ECValuesCollection const& self) { return ECPropertyValuePtr(const_cast<ECPropertyValueP>(&self.GetParentProperty())); }, py::keep_alive<0, 1>());
    c5.def("GetParentProperty", [] (ECValuesCollection const& self) { return ECPropertyValuePtr(const_cast<ECPropertyValueP>(&self.GetParentProperty())); }, py::keep_alive<0, 1>());
    c5.def("__iter__", [](ECValuesCollection& self) { return py::make_iterator<py::return_value_policy::move>(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }