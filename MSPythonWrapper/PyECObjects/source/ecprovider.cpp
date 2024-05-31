/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecprovider.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ecprovider.h>

//=======================================================================================
// Publicist class for IECProvider
// @bsiclass                                                                   02/23
//=======================================================================================
struct IECProviderPub : IECProvider
    {
    public:
        using IECProvider::_GetProviderId;
        using IECProvider::_GetProviderName;
    };

//=======================================================================================
// Trampoline class for IECProvider
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyECProvider : IECProvider
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual uint16_t _GetProviderId() const override
            { PYBIND11_OVERRIDE_PURE_EXR(uint16_t, IECProvider, _GetProviderId, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WCharCP _GetProviderName() const override
            { PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IECProvider, _GetProviderName, nullptr, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECProvider(py::module_& m)
    {
    //===================================================================================
    // struct IECProvider
    py::class_< IECProvider, std::unique_ptr< IECProvider, py::nodelete>, IPyECProvider> c1(m, "IECProvider");

    c1.def(py::init<>());
    c1.def("_GetProviderId", &IECProviderPub::_GetProviderId);
    c1.def("_GetProviderName", &IECProviderPub::_GetProviderName, py::return_value_policy::reference_internal);

    c1.def_property_readonly("ProviderId", &IECProvider::GetProviderId);
    c1.def("GetProviderId", &IECProvider::GetProviderId);

    c1.def_property_readonly("ProviderName", &IECProvider::GetProviderName);
    c1.def("GetProviderName", &IECProvider::GetProviderName, py::return_value_policy::reference_internal);
    }