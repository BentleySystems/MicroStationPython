/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\auiprovider.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECPresentation/auiprovider.h>

//=======================================================================================
// Publicist class for IECPresentationProvider
// @bsiclass                                                                   02/23
//=======================================================================================
struct IECPresentationProviderPub : IECPresentationProvider
    {
    public:
        using IECPresentationProvider::_GetProviderId;
        using IECPresentationProvider::_GetProviderName;
        using IECPresentationProvider::_GetProviderType;
    };

//=======================================================================================
// Trampoline class for IECPresentationProvider
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyECPresentationProvider : IECPresentationProvider
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual size_t _GetProviderId(void) const override
            { PYBIND11_OVERRIDE_EXR(size_t, IECPresentationProvider, _GetProviderId, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WCharCP _GetProviderName(void) const override
            { PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IECPresentationProvider, _GetProviderName, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ProviderType _GetProviderType(void) const override
            { PYBIND11_OVERRIDE_PURE_EXR(ProviderType, IECPresentationProvider, _GetProviderType, ProviderType::CommandService, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_auiprovider(py::module_& m)
    {
    //===================================================================================
    // struct IECPresentationProvider
    py::class_< IECPresentationProvider, IPyECPresentationProvider> c1(m, "IECPresentationProvider");

    if (true)
        {
        //===================================================================================
        // enum ProviderType
        py::enum_< IECPresentationProvider::ProviderType>(c1, "ProviderType", py::arithmetic())
            .value("eViewService", IECPresentationProvider::ViewService)
            .value("eContentService", IECPresentationProvider::ContentService)
            .value("eCommandService", IECPresentationProvider::CommandService)
            .value("eImageService", IECPresentationProvider::ImageService)
            .value("eLocalizationService", IECPresentationProvider::LocalizationService)
            .value("eSelectionService", IECPresentationProvider::SelectionService)
            .value("eJournalService", IECPresentationProvider::JournalService)
            .export_values();
        }

    c1.def(py::init<>());
    c1.def("_GetProviderId", &IECPresentationProviderPub::_GetProviderId);
    c1.def("_GetProviderName", &IECPresentationProviderPub::_GetProviderName);
    c1.def("_GetProviderType", &IECPresentationProviderPub::_GetProviderType);

    c1.def_property_readonly("ProviderId", &IECPresentationProvider::GetProviderId);
    c1.def("GetProviderId", &IECPresentationProvider::GetProviderId);
    
    c1.def_property_readonly("ProviderName", &IECPresentationProvider::GetProviderName);
    c1.def("GetProviderName", &IECPresentationProvider::GetProviderName, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("ProviderType", &IECPresentationProvider::GetProviderType);
    c1.def("GetProviderType", &IECPresentationProvider::GetProviderType);
    }