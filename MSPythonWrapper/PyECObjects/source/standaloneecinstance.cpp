/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\standaloneecinstance.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/StandaloneECInstance.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_StandaloneECInstance(py::module_& m)
    {
    //===================================================================================
    // enum PropertyFlagIndex
    py::enum_< PropertyFlagIndex>(m, "PropertyFlagIndex", py::arithmetic())
        .value("ePROPERTYFLAGINDEX_IsLoaded", PROPERTYFLAGINDEX_IsLoaded)
        .value("ePROPERTYFLAGINDEX_IsReadOnly", PROPERTYFLAGINDEX_IsReadOnly)
        .export_values();

    //===================================================================================
    // enum MemoryInstanceUsageBitmask
    py::enum_< MemoryInstanceUsageBitmask>(m, "MemoryInstanceUsageBitmask", py::arithmetic())
        .value("eMEMORYINSTANCEUSAGE_Empty", MEMORYINSTANCEUSAGE_Empty)
        .value("eMEMORYINSTANCEUSAGE_IsPartiallyLoaded", MEMORYINSTANCEUSAGE_IsPartiallyLoaded)
        .value("eMEMORYINSTANCEUSAGE_IsHidden", MEMORYINSTANCEUSAGE_IsHidden)
        .export_values();

    //===================================================================================
    // struct MemoryECInstanceBase
    py::class_< MemoryECInstanceBase,  std::unique_ptr<MemoryECInstanceBase, py::nodelete>, ECDBuffer> c1(m, "MemoryECInstanceBase");

    c1.def("SetData", [] (MemoryECInstanceBase& self, py::bytes const& data)
           {
           if (py::len(data) > 0)
               {
               std::string strData = data.cast<std::string>();
               self.SetData((const Byte*) strData.data(), (uint32_t) strData.size(), true);
               }
           }, "data"_a);

    c1.def("GetData", [] (MemoryECInstanceBase const& self)
           {
           Byte const* pData = self.GetData();
           uint32_t dataSize = self.GetBytesUsed();
           py::bytes outData;
           if (nullptr != pData && dataSize > 0)
               outData = py::bytes((const char*) pData, dataSize);
           return outData;
           });

    c1.def("MergePropertiesFromInstance", &MemoryECInstanceBase::MergePropertiesFromInstance, "fromNativeInstance"_a);
    c1.def("ClearValues", &ECDBuffer::ClearValues);

    //===================================================================================
    // struct StandaloneECInstance
    py::class_< StandaloneECInstance, StandaloneECInstancePtr, IECInstance/*, MemoryECInstanceBase*/> c2(m, "StandaloneECInstance", py::multiple_inheritance());
    py::bind_vector<bvector< StandaloneECInstancePtr>>(m, "StandaloneECInstancePtrArray", py::module_local(false));

    c2.def_static("Duplicate", &StandaloneECInstance::Duplicate, "instance"_a);
    //c2.def("MergePropertiesFromInstance", &MemoryECInstanceBase::MergePropertiesFromInstance, "fromNativeInstance"_a);
    //c2.def("ClearValues", &MemoryECInstanceBase::ClearValues);

    //===================================================================================
    // struct StandaloneECEnabler
    py::class_< StandaloneECEnabler, StandaloneECEnablerPtr, ECEnabler> c3(m, "StandaloneECEnabler");

    c3.def(py::init(&StandaloneECEnabler::CreateEnabler), "ecClass"_a, "classLayout"_a, "structStandaloneEnablerLocater"_a);

    c3.def("CreateInstance", &StandaloneECEnabler::CreateInstance, "minimumInitialSize"_a = 0);
    c3.def_property_readonly("ClassLayout", py::overload_cast<>(&StandaloneECEnabler::GetClassLayout));
    c3.def("GetClassLayout", py::overload_cast<>(&StandaloneECEnabler::GetClassLayout), py::return_value_policy::reference_internal);
    }