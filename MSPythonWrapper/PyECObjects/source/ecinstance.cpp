/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecinstance.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECInstance.h>
#include <DgnPlatform/DgnECInstance.h>

//=======================================================================================
// Trampoline class for ICustomECStructSerializer
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyCustomECStructSerializer : ICustomECStructSerializer
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual bool UsesCustomStructXmlString(StructECPropertyP structProperty, IECInstanceCR ecInstance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, ICustomECStructSerializer, UsesCustomStructXmlString, false, structProperty, ecInstance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ECObjectsStatus GenerateXmlString(WString& xmlString, StructECPropertyP structProperty, IECInstanceCR ecInstance, WCharCP baseAccessString) const override
        { PYBIND11_OVERRIDE_PURE_EXR(ECObjectsStatus, ICustomECStructSerializer, GenerateXmlString, ECOBJECTS_STATUS_Error, xmlString, structProperty, ecInstance, baseAccessString); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void LoadStructureFromString(StructECPropertyP structProperty, IECInstanceR ecInstance, WCharCP baseAccessString, WCharCP valueString) override
        { PYBIND11_OVERRIDE_PURE_EX(void, ICustomECStructSerializer, LoadStructureFromString, structProperty, ecInstance, baseAccessString, valueString); }
    };


using ICustomECStructSerializerPtr = std::unique_ptr<ICustomECStructSerializer, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECInstance(py::module_& m)
    {
    //===================================================================================
    // struct ICustomECStructSerializer
    py::class_<ICustomECStructSerializer, ICustomECStructSerializerPtr, IPyCustomECStructSerializer> c1(m, "ICustomECStructSerializer");

    //c1.def(py::init<>());
    c1.def("UsesCustomStructXmlString", &ICustomECStructSerializer::UsesCustomStructXmlString, "structProperty"_a, "ecInstance"_a);
    c1.def("GenerateXmlString", &ICustomECStructSerializer::GenerateXmlString, "xmlString"_a, "structProperty"_a, "ecInstance"_a, "baseAccessString"_a);
    c1.def("LoadStructureFromString", &ICustomECStructSerializer::LoadStructureFromString, "structProperty"_a, "ecInstance"_a, "baseAccessString"_a, "valueString"_a);

    //===================================================================================
    // struct CustomStructSerializerManager
    py::class_< CustomStructSerializerManager, std::unique_ptr<CustomStructSerializerManager, py::nodelete> > c2(m, "CustomStructSerializerManager");

    c2.def("GetCustomSerializer", 
           py::overload_cast<StructECPropertyP, IECInstanceCR>(&CustomStructSerializerManager::GetCustomSerializer, py::const_),
           "structProperty"_a, "ecInstance"_a, py::return_value_policy::reference_internal);

    c2.def("AddCustomSerializer", &CustomStructSerializerManager::AddCustomSerializer, "serializerName"_a, "serializer"_a, py::keep_alive<1, 3>());
    c2.def_static("GetManager", &CustomStructSerializerManager::GetManager, py::return_value_policy::reference);
    
    //===================================================================================
    // struct IECInstance
    py::class_< IECInstance, IECInstancePtr> c3(m, "IECInstance");
    py::bind_vector<bvector< IECInstancePtr>>(m, "IECInstancePtrArray", py::module_local(false));

    c3.def("ChangeValuesAllowed", &IECInstance::ChangeValuesAllowed);
    
    c3.def_property_readonly("Enabler", &IECInstance::GetEnablerR);
    c3.def("GetEnabler", &IECInstance::GetEnablerR, py::return_value_policy::reference_internal);
    
    c3.def_property("InstanceId", &IECInstance::GetInstanceId, &IECInstance::SetInstanceId);
    c3.def("GetInstanceId", &IECInstance::GetInstanceId);
    c3.def("SetInstanceId", &IECInstance::SetInstanceId, "instanceId"_a);
    
    c3.def_property_readonly("InstanceIdForSerialization", &IECInstance::GetInstanceIdForSerialization);
    c3.def("GetInstanceIdForSerialization", &IECInstance::GetInstanceIdForSerialization);
    
    c3.def("IsReadOnly", &IECInstance::IsReadOnly);
    
    c3.def_property_readonly("Class", &IECInstance::GetClass);
    c3.def("GetClass", &IECInstance::GetClass, py::return_value_policy::reference_internal);

    c3.def("GetValue",
           py::overload_cast<ECValueR, WCharCP>(&IECInstance::GetValue, py::const_),
           "value"_a, "accessString"_a);

    c3.def("GetValue",
           py::overload_cast<ECValueR, WCharCP, uint32_t>(&IECInstance::GetValue, py::const_),
           "value"_a, "accessString"_a, "arrayIndex"_a);

    c3.def("GetValue",
           py::overload_cast<ECValueR, uint32_t>(&IECInstance::GetValue, py::const_),
           "value"_a, "propertyIndex"_a);

    c3.def("GetValue",
           py::overload_cast<ECValueR, uint32_t, uint32_t>(&IECInstance::GetValue, py::const_),
           "value"_a, "propertyIndex"_a, "arrayIndex"_a);

    c3.def("SetValue",
           py::overload_cast<WCharCP, ECValueCR>(&IECInstance::SetValue),
           "accessString"_a, "value"_a);

    c3.def("SetValue",
           py::overload_cast<WCharCP, ECValueCR, uint32_t>(&IECInstance::SetValue),
           "accessString"_a, "value"_a, "arrayIndex"_a);

    c3.def("SetValue",
           py::overload_cast<uint32_t, ECValueCR>(&IECInstance::SetValue),
           "propertyIndex"_a, "value"_a);

    c3.def("SetValue",
           py::overload_cast<uint32_t, ECValueCR, uint32_t>(&IECInstance::SetValue),
           "propertyIndex"_a, "value"_a, "arrayIndex"_a);

    c3.def("ChangeValue",
           py::overload_cast<WCharCP, ECValueCR>(&IECInstance::ChangeValue),
           "accessString"_a, "value"_a);

    c3.def("ChangeValue",
           py::overload_cast<WCharCP, ECValueCR, uint32_t>(&IECInstance::ChangeValue),
           "accessString"_a, "value"_a, "arrayIndex"_a);

    c3.def("ChangeValue",
           py::overload_cast<uint32_t, ECValueCR>(&IECInstance::ChangeValue),
           "propertyIndex"_a, "value"_a);

    c3.def("ChangeValue",
           py::overload_cast<uint32_t, ECValueCR, uint32_t>(&IECInstance::ChangeValue),
           "propertyIndex"_a, "value"_a, "arrayIndex"_a);

    c3.def("GetValueUsingAccessor", &IECInstance::GetValueUsingAccessor, "value"_a, "accessor"_a);
    c3.def("SetValueUsingAccessor", &IECInstance::SetValueUsingAccessor, "accessor"_a, "value"_a);

    c3.def("IsPropertyNull", [] (IECInstanceCR self, WCharCP accessString)
           {
           bool isNull = false;
           auto retVal = self.IsPropertyNull(isNull, accessString);
           return py::make_tuple(retVal, isNull);
           }, "accessString"_a);

    c3.def("IsPropertyNull", [] (IECInstanceCR self, WCharCP accessString, uint32_t arrayIndex)
           {
           bool isNull = false;
           auto retVal = self.IsPropertyNull(isNull, accessString, arrayIndex);
           return py::make_tuple(retVal, isNull);
           }, "accessString"_a, "arrayIndex"_a);

    c3.def("IsPropertyNull", [] (IECInstanceCR self, uint32_t propertyIndex)
           {
           bool isNull = false;
           auto retVal = self.IsPropertyNull(isNull, propertyIndex);
           return py::make_tuple(retVal, isNull);
           }, "propertyIndex"_a);

    c3.def("IsPropertyNull", [] (IECInstanceCR self, uint32_t propertyIndex, uint32_t arrayIndex)
           {
           bool isNull = false;
           auto retVal = self.IsPropertyNull(isNull, propertyIndex, arrayIndex);
           return py::make_tuple(retVal, isNull);
           }, "propertyIndex"_a, "arrayIndex"_a);


    c3.def_static("IsFixedArrayProperty", [] (ECN::IECInstanceR instance, WCharCP accessString)
                  {
                  uint32_t numFixedEntries = 0;
                  auto retVal = IECInstance::IsFixedArrayProperty(instance, accessString, &numFixedEntries);
                  return py::make_tuple(retVal, numFixedEntries);
                  }, "instance"_a, "accessString"_a);

    c3.def("IsPropertyReadOnly", py::overload_cast<WCharCP>(&IECInstance::IsPropertyReadOnly, py::const_), "accessString"_a);
    c3.def("IsPropertyReadOnly", py::overload_cast<uint32_t>(&IECInstance::IsPropertyReadOnly, py::const_), "propertyIndex"_a);
    
    c3.def("InsertArrayElements", py::overload_cast<WCharCP, uint32_t, uint32_t>(&IECInstance::InsertArrayElements), "accessString"_a, "index"_a, "size"_a);
    c3.def("RemoveArrayElement", py::overload_cast<WCharCP, uint32_t>(&IECInstance::RemoveArrayElement), "accessString"_a, "index"_a);
    c3.def("AddArrayElements", py::overload_cast<WCharCP, uint32_t>(&IECInstance::AddArrayElements), "accessString"_a, "index"_a);
    c3.def("ClearArray", py::overload_cast<WCharCP>(&IECInstance::ClearArray), "accessString"_a);

    c3.def("InsertArrayElements", py::overload_cast<uint32_t, uint32_t, uint32_t>(&IECInstance::InsertArrayElements), "propertyIndex"_a, "index"_a, "size"_a);
    c3.def("RemoveArrayElement", py::overload_cast<uint32_t, uint32_t>(&IECInstance::RemoveArrayElement), "propertyIndex"_a, "index"_a);
    c3.def("AddArrayElements", py::overload_cast<uint32_t, uint32_t>(&IECInstance::AddArrayElements), "propertyIndex"_a, "index"_a);
    c3.def("ClearArray", py::overload_cast<uint32_t>(&IECInstance::ClearArray), "propertyIndex"_a);

    c3.def("GetDisplayLabel", &IECInstance::GetDisplayLabel, "displayLabel"_a);
    c3.def("SetDisplayLabel", &IECInstance::SetDisplayLabel, "displayLabel"_a);
    
    c3.def_property_readonly("ECDBuffer", &IECInstance::GetECDBufferP);
    c3.def("GetECDBuffer", &IECInstance::GetECDBufferP, py::return_value_policy::reference_internal);
    
    c3.def("AsMemoryECInstance", &IECInstance::GetAsMemoryECInstanceP, py::return_value_policy::reference_internal);
    
    c3.def_property_readonly("OffsetToIECInstance", &IECInstance::GetOffsetToIECInstance);
    c3.def("GetOffsetToIECInstance", &IECInstance::GetOffsetToIECInstance);
    
    c3.def("ToString", &IECInstance::ToString, "indent"_a);
    c3.def("CreateCopyThroughSerialization", py::overload_cast<>(&IECInstance::CreateCopyThroughSerialization));
    c3.def("CreateCopyThroughSerialization", py::overload_cast<ECSchemaCR>(&IECInstance::CreateCopyThroughSerialization), "targetSchema"_a);

    c3.def_static("ReadFromXmlFile", [] (WCharCP fileName, ECInstanceReadContextR context)
                  {
                  IECInstancePtr ecInstance;
                  auto retVal = IECInstance::ReadFromXmlFile(ecInstance, fileName, context);
                  return py::make_tuple(retVal, ecInstance);
                  }, "fileName"_a, "context"_a);

    c3.def_static("ReadFromXmlString", [] (WCharCP xmlString, ECInstanceReadContextR context)
                  {
                  IECInstancePtr ecInstance;
                  auto retVal = IECInstance::ReadFromXmlString(ecInstance, xmlString, context);
                  return py::make_tuple(retVal, ecInstance);
                  }, "xmlString"_a, "context"_a);    

    c3.def("WriteToXmlFile", &IECInstance::WriteToXmlFile, "fileName"_a, "writeInstanceId"_a, "utf16"_a);
    c3.def("WriteToXmlString", py::overload_cast<Utf8StringR, bool, bool>(&IECInstance::WriteToXmlString), "ecInstanceXml"_a, "isStandAlone"_a, "writeInsanceId"_a);
    c3.def("WriteToXmlString", py::overload_cast<WStringR, bool, bool>(&IECInstance::WriteToXmlString), "ecInstanceXml"_a, "isStandAlone"_a, "writeInsanceId"_a);
    c3.def("SaveOnlyLoadedPropertiesToXml", &IECInstance::SaveOnlyLoadedPropertiesToXml);

    c3.def("CopyValues", &IECInstance::CopyValues, "source"_a);

    //===================================================================================
    // struct IECRelationshipInstance
    py::class_< IECRelationshipInstance, IECRelationshipInstancePtr, IECInstance> c4(m, "IECRelationshipInstance");

    c4.def_property("Source", &IECRelationshipInstance::GetSource, &IECRelationshipInstance::SetSource);
    c4.def("GetSource", &IECRelationshipInstance::GetSource);
    c4.def("SetSource", &IECRelationshipInstance::SetSource, "instance"_a);

    c4.def("GetSourceOrderId", [] (IECRelationshipInstanceCR self)
           {
           int64_t orderId = 0;
           auto retVal = self.GetSourceOrderId(orderId);
           return py::make_tuple(retVal, orderId);
           });

    c4.def_property("Target", &IECRelationshipInstance::GetTarget, &IECRelationshipInstance::SetTarget);
    c4.def("GetTarget", &IECRelationshipInstance::GetTarget);
    c4.def("SetTarget", &IECRelationshipInstance::SetTarget, "instance"_a);

    c4.def("GetTargetOrderId", [] (IECRelationshipInstanceCR self)
           {
           int64_t orderId = 0;
           auto retVal = self.GetTargetOrderId(orderId);
           return py::make_tuple(retVal, orderId);
           });
    }