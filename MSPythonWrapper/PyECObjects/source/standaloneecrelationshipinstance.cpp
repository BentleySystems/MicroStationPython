/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\standaloneecrelationshipinstance.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/StandaloneECRelationshipInstance.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_StandaloneECRelationshipInstance(py::module_& m)
    {
    //===================================================================================
    // struct OrderIdEntries
    py::class_< OrderIdEntries> c1(m, "OrderIdEntries");

    c1.def("SetSourceOrderId", &OrderIdEntries::SetSourceOrderId, "orderId"_a);
    c1.def("SetTargetOrderId", &OrderIdEntries::SetTargetOrderId, "orderId"_a);
    c1.def("SetSourceNextOrderId", &OrderIdEntries::SetSourceNextOrderId, "orderId"_a);
    c1.def("SetTargetNextOrderId", &OrderIdEntries::SetTargetNextOrderId, "orderId"_a);

    c1.def("TryGetSourceOrderId", [] (OrderIdEntries const& self)
           {
           int64_t orderId = 0;
           auto retVal = self.TryGetSourceOrderId(orderId);
           return py::make_tuple(retVal, orderId);
           });

    c1.def("TryGetTargetOrderId", [] (OrderIdEntries const& self)
           {
           int64_t orderId = 0;
           auto retVal = self.TryGetTargetOrderId(orderId);
           return py::make_tuple(retVal, orderId);
           });

    c1.def("TryGetSourceNextOrderId", [] (OrderIdEntries const& self)
           {
           int64_t orderId = 0;
           auto retVal = self.TryGetSourceNextOrderId(orderId);
           return py::make_tuple(retVal, orderId);
           });

    c1.def("TryGetTargetNextOrderId", [] (OrderIdEntries const& self)
           {
           int64_t orderId = 0;
           auto retVal = self.TryGetTargetNextOrderId(orderId);
           return py::make_tuple(retVal, orderId);
           });

    c1.def("Clear", &OrderIdEntries::Clear);

    //===================================================================================
    // struct StandaloneECRelationshipInstance
    py::class_< StandaloneECRelationshipInstance, StandaloneECRelationshipInstancePtr, IECRelationshipInstance/*, MemoryECInstanceBase*/> c2(m, "StandaloneECRelationshipInstance", py::multiple_inheritance());

    c2.def("SetSourceOrderId", &StandaloneECRelationshipInstance::SetSourceOrderId, "orderId"_a);
    c2.def("SetTargetOrderId", &StandaloneECRelationshipInstance::SetTargetOrderId, "orderId"_a);
    
    c2.def_property_readonly("RelationshipEnabler", &StandaloneECRelationshipInstance::GetRelationshipEnabler);
    c2.def("GetRelationshipEnabler", &StandaloneECRelationshipInstance::GetRelationshipEnabler, py::return_value_policy::reference_internal);
    
    c2.def_property_readonly("RelationshipClass", &StandaloneECRelationshipInstance::GetRelationshipClass);
    c2.def("GetRelationshipClass", &StandaloneECRelationshipInstance::GetRelationshipClass, py::return_value_policy::reference_internal);
    
    c2.def_property("SourceAssociatedString", &StandaloneECRelationshipInstance::GetSourceAssociatedString, &StandaloneECRelationshipInstance::SetSourceAssociatedString);
    c2.def("GetSourceAssociatedString", &StandaloneECRelationshipInstance::GetSourceAssociatedString, py::return_value_policy::reference_internal);
    c2.def("SetSourceAssociatedString", &StandaloneECRelationshipInstance::SetSourceAssociatedString, "string"_a);
    
    c2.def_property("TargetAssociatedString", &StandaloneECRelationshipInstance::GetTargetAssociatedString, &StandaloneECRelationshipInstance::SetTargetAssociatedString);
    c2.def("GetTargetAssociatedString", &StandaloneECRelationshipInstance::GetTargetAssociatedString, py::return_value_policy::reference_internal);
    c2.def("SetTargetAssociatedString", &StandaloneECRelationshipInstance::SetTargetAssociatedString, "string"_a);
    
    c2.def("OrderIdEntries", &StandaloneECRelationshipInstance::OrderIdEntries, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct StandaloneECRelationshipEnabler
    py::class_< StandaloneECRelationshipEnabler, StandaloneECRelationshipEnablerPtr/*, IECRelationshipEnabler*/, StandaloneECEnabler> c3(m, "StandaloneECRelationshipEnabler", py::multiple_inheritance());

    c3.def(py::init(py::overload_cast<ECRelationshipClassCR>(&StandaloneECRelationshipEnabler::CreateStandaloneRelationshipEnabler)), "ecClass"_a);

    c3.def(py::init(py::overload_cast<ECRelationshipClassCR, ClassLayoutR, IStandaloneEnablerLocaterP>(&StandaloneECRelationshipEnabler::CreateStandaloneRelationshipEnabler)),
           "ecClass"_a, "classLayout"_a, "structStandaloneEnablerLocater"_a);

    c3.def("CreateRelationshipInstance", &StandaloneECRelationshipEnabler::CreateRelationshipInstance);

    c3.def_property_readonly("ECEnabler", &StandaloneECRelationshipEnabler::GetECEnabler);
    c3.def("GetECEnabler", &StandaloneECRelationshipEnabler::GetECEnabler, py::return_value_policy::reference_internal);
    }