/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecenabler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECEnabler.h>

//=======================================================================================
// Publicist class for IECRelationshipEnabler
// @bsiclass                                                                   02/23
//=======================================================================================
struct IECRelationshipEnablerPub : IECRelationshipEnabler
    {
    public:
        using IECRelationshipEnabler::_CreateWipRelationshipInstance;
        using IECRelationshipEnabler::_GetRelationshipClass;
    };

//=======================================================================================
// Trampoline class for IECRelationshipEnabler
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyECRelationshipEnabler : IECRelationshipEnabler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StandaloneECRelationshipInstancePtr _CreateWipRelationshipInstance() const override
            { PYBIND11_OVERRIDE_PURE_EXR(StandaloneECRelationshipInstancePtr, IECRelationshipEnabler, _CreateWipRelationshipInstance, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ECN::ECRelationshipClassCR _GetRelationshipClass() const override
            { PYBIND11_OVERRIDE_PURE(ECRelationshipClassCR, IECRelationshipEnabler, _GetRelationshipClass, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECEnabler(py::module_& m)
    {
    //===================================================================================
    // struct ECEnabler
    py::class_< ECEnabler, ECEnablerPtr
    > c1(m, "ECEnabler", py::multiple_inheritance());

    c1.def_property_readonly("Name", &ECEnabler::GetName);
    c1.def("GetName", &ECEnabler::GetName, py::return_value_policy::reference_internal);

    c1.def_property_readonly("Class", &ECEnabler::GetClass);
    c1.def("GetClass", &ECEnabler::GetClass, py::return_value_policy::reference_internal);

    c1.def("GetPropertyIndex", [] (ECEnablerCR self, WCharCP propertyAccessString)
           {
           uint32_t propIndex = 0;
           auto retVal = self.GetPropertyIndex(propIndex, propertyAccessString);
           return py::make_tuple(retVal, propIndex);
           }, "accessString"_a);

    c1.def("GetAccessString", [] (ECEnablerCR self, uint32_t propertyIndex)
           {
           WCharCP accessString = nullptr;
           auto retVal = self.GetAccessString(accessString, propertyIndex);
           return py::make_tuple(retVal, accessString);
           }, "propertyIndex"_a);

    c1.def("GetFirstPropertyIndex", &ECEnabler::GetFirstPropertyIndex, "parentIndex"_a);
    c1.def("GetNextPropertyIndex", &ECEnabler::GetNextPropertyIndex, "parentIndex"_a, "inputIndex"_a);
    c1.def("HasChildProperties", &ECEnabler::HasChildProperties, "parentIndex"_a);
    c1.def("GetParentPropertyIndex", &ECEnabler::GetParentPropertyIndex, "childIndex"_a);
    c1.def("GetPropertyIndices", &ECEnabler::GetPropertyIndices, "indices"_a, "parentIndex"_a);
    
    c1.def_property_readonly("StandaloneEnablerLocater", &ECEnabler::GetStandaloneEnablerLocater);
    c1.def("GetStandaloneEnablerLocater", &ECEnabler::GetStandaloneEnablerLocater, py::return_value_policy::reference_internal);
    
    c1.def("GetEnablerForStructArrayMember", &ECEnabler::GetEnablerForStructArrayMember, "schemaKey"_a, "className"_a, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct IECRelationshipEnabler
    py::class_< IECRelationshipEnabler, std::unique_ptr< IECRelationshipEnabler, py::nodelete>, IPyECRelationshipEnabler> c2(m, "IECRelationshipEnabler");

    c2.def(py::init<>());
    c2.def("_CreateWipRelationshipInstance", &IECRelationshipEnablerPub::_CreateWipRelationshipInstance);
    c2.def("_GetRelationshipClass", &IECRelationshipEnablerPub::_GetRelationshipClass);

    c2.def("CreateWipRelationshipInstance", &IECRelationshipEnabler::CreateWipRelationshipInstance);
    c2.def("GetRelationshipClass", &IECRelationshipEnabler::GetRelationshipClass);
    }