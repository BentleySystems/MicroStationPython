
/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\IPrintEngine.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>



static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_Capability =R"doc(Gets/Sets print engine capabilities.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetLicenseLabel =R"doc(Get the license string to be added to the plot border label.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_IsPlotBorderLicenseLabelNeeded =R"doc(Indicates whether a license string must be added to the plot border
label.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetPrintDefinitionPropertyValue =R"doc(Gets the value of the specified property for the current print
definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetPrintSetPropertyValue =R"doc(Gets the value of the specified property for the current print set.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetPrintDefinitionSourceFspec =R"doc(Gets the source file specification of the current print definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetPrintDefinitionName =R"doc(Gets the name of the current print definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetOutputFileSpec =R"doc(Gets the output file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetTransform =R"doc(Gets the value of the requested print transform.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_WasGeometryOutput =R"doc(Indicates whether any geometry was output during print processing.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_GetNumCopies =R"doc(Gets the number of copies.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_IsRasterized =R"doc(Indicates if printing in rasterized mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_IsPartOfPrintSet =R"doc(Indicates if printing as a set.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_IsLegacyPreview =R"doc(Indicates if legacy print preview (e.g. plotdlg) is currently in
progress.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngine_IsPreview =R"doc(Indicates if print preview is currently in progress.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_SetEnableDynamicPlot =R"doc(@deprecated Obsolete; has no effect.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_GetEnableDynamicPlot =R"doc(@deprecated Obsolete; always False.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_SetEnablePropertyMap =R"doc(Enable or disable property map capability.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_GetEnablePropertyMap =R"doc(Indicates if property map capability is enabled.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_SetEnablePostStrokeLineStyles =R"doc(Enable or disable post-stroke line style capability.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_GetEnablePostStrokeLineStyles =R"doc(Indicates if post-stroke line style capability is enabled.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_SetEnableSortOrder =R"doc(Enable or disable non-rasterized sort order capability.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEngineCapability_GetEnableSortOrder =R"doc(Indicates if non-rasterized sort order capability is enabled.)doc";

//=======================================================================================
// Trampoline class for IPrintEngineCapability.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintEngineCapability : IPrintEngineCapability
{
public:
    using IPrintEngineCapability::IPrintEngineCapability;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetEnableSortOrder() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngineCapability, GetEnableSortOrder, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetEnableSortOrder(bool value)override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngineCapability, SetEnableSortOrder, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetEnablePostStrokeLineStyles() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngineCapability, GetEnablePostStrokeLineStyles, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetEnablePostStrokeLineStyles(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngineCapability, SetEnablePostStrokeLineStyles, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetEnablePropertyMap() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngineCapability, GetEnablePropertyMap,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetEnablePropertyMap(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngineCapability, SetEnablePropertyMap, value );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetEnableDynamicPlot() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(bool, IPrintEngineCapability, GetEnableDynamicPlot, false,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    //! @remarks May be NULL. Internal use only.
    virtual void SetEnableDynamicPlot(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngineCapability, SetEnableDynamicPlot, value);
    }
};

//=======================================================================================
// Trampoline class for IPrintEngine.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintEngine : IPrintEngine
{
public:
    using IPrintEngine::IPrintEngine;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterP GetEnginePlotter() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterP, IPrintEngine, GetEnginePlotter,nullptr,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPreview() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngine, IsPreview, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsLegacyPreview() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngine, IsLegacyPreview, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPartOfPrintSet() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngine, IsPartOfPrintSet, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsRasterized() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngine, IsRasterized, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumCopies() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPrintEngine, GetNumCopies, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool WasGeometryOutput() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngine, WasGeometryOutput, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Transform GetTransform(PlotTagTransform tag) const override
    {
        PYBIND11_OVERRIDE_PURE(Transform, IPrintEngine, GetTransform, tag);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCR GetOutputFileSpec() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotFileSpecCR, IPrintEngine, GetOutputFileSpec, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngine, GetPrintDefinitionName, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionSourceFspec(PlotFileSpecR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngine, GetPrintDefinitionSourceFspec, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintSetPropertyValue(WCharCP name, PlotPropValueR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngine, GetPrintSetPropertyValue, name, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionPropertyValue(WCharCP name, PlotPropValueR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngine, GetPrintDefinitionPropertyValue, name, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPlotBorderLicenseLabelNeeded() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintEngine, IsPlotBorderLicenseLabelNeeded,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetLicenseLabel(WStringR label) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEngine, GetLicenseLabel, label);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineCapabilityR Capability() override
    {
        PYBIND11_OVERRIDE_PURE(IPrintEngineCapabilityR, IPrintEngine, Capability,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    * @remarks May be NULL. Internal use only.
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ICadPrintHandlerP GetCadPrintHandler() override
    {
        return nullptr;
    }
};


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPrintEngine(py::module_& m)
    {
    //===================================================================================
    //class IPrintEngineCapability
    py::class_<IPrintEngineCapability, IPyPrintEngineCapability> c0(m, "IPrintEngineCapability");

    c0.def(py::init<>());

    c0.def_property("EnableSortOrder", &IPrintEngineCapability::GetEnableSortOrder, &IPrintEngineCapability::SetEnableSortOrder);
    c0.def("GetEnableSortOrder", &IPrintEngineCapability::GetEnableSortOrder, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, GetEnableSortOrder));
    c0.def("SetEnableSortOrder", &IPrintEngineCapability::SetEnableSortOrder, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, SetEnableSortOrder));

    c0.def_property("EnablePostStrokeLineStyles", &IPrintEngineCapability::GetEnablePostStrokeLineStyles, &IPrintEngineCapability::SetEnablePostStrokeLineStyles);
    c0.def("GetEnablePostStrokeLineStyles", &IPrintEngineCapability::GetEnablePostStrokeLineStyles, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, GetEnablePostStrokeLineStyles));
    c0.def("SetEnablePostStrokeLineStyles", &IPrintEngineCapability::SetEnablePostStrokeLineStyles, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, SetEnablePostStrokeLineStyles));

    c0.def_property("EnablePropertyMap", &IPrintEngineCapability::GetEnablePropertyMap, &IPrintEngineCapability::SetEnablePropertyMap);
    c0.def("GetEnablePropertyMap", &IPrintEngineCapability::GetEnablePropertyMap, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, GetEnablePropertyMap));
    c0.def("SetEnablePropertyMap", &IPrintEngineCapability::SetEnablePropertyMap, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, SetEnablePropertyMap));

    c0.def_property("EnableDynamicPlot", &IPrintEngineCapability::GetEnableDynamicPlot, &IPrintEngineCapability::SetEnableDynamicPlot);
    c0.def("GetEnableDynamicPlot", &IPrintEngineCapability::GetEnableDynamicPlot, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, GetEnableDynamicPlot));
    c0.def("SetEnableDynamicPlot", &IPrintEngineCapability::SetEnableDynamicPlot, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngineCapability, SetEnableDynamicPlot));

    //===================================================================================
    //class IPrintEngine
    py::class_<IPrintEngine, IPyPrintEngine> c1(m, "IPrintEngine");

    c1.def(py::init<>());

    c1.def("IsPreview", &IPrintEngine::IsPreview, DOC(Bentley, MstnPlatform, Print, IPrintEngine, IsPreview));
    c1.def("IsLegacyPreview", &IPrintEngine::IsLegacyPreview, DOC(Bentley, MstnPlatform, Print, IPrintEngine, IsLegacyPreview));
    c1.def("IsPartOfPrintSet", &IPrintEngine::IsPartOfPrintSet, DOC(Bentley, MstnPlatform, Print, IPrintEngine, IsPartOfPrintSet));
    c1.def("IsRasterized", &IPrintEngine::IsRasterized, DOC(Bentley, MstnPlatform, Print, IPrintEngine, IsRasterized));
    c1.def("GetNumCopies", &IPrintEngine::GetNumCopies, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetNumCopies));
    c1.def("WasGeometryOutput", &IPrintEngine::WasGeometryOutput, DOC(Bentley, MstnPlatform, Print, IPrintEngine, WasGeometryOutput));
    c1.def("GetTransform", &IPrintEngine::GetTransform, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetTransform));
    c1.def("GetOutputFileSpec", &IPrintEngine::GetOutputFileSpec, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetOutputFileSpec));
    c1.def("GetPrintDefinitionName", &IPrintEngine::GetPrintDefinitionName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetPrintDefinitionName));
    c1.def("GetPrintDefinitionSourceFspec", &IPrintEngine::GetPrintDefinitionSourceFspec, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetPrintDefinitionSourceFspec));
    c1.def("GetPrintSetPropertyValue", &IPrintEngine::GetPrintSetPropertyValue, "name"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetPrintSetPropertyValue));
    c1.def("GetPrintDefinitionPropertyValue", &IPrintEngine::GetPrintDefinitionPropertyValue, "name"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetPrintDefinitionPropertyValue));
    c1.def("IsPlotBorderLicenseLabelNeeded", &IPrintEngine::IsPlotBorderLicenseLabelNeeded, DOC(Bentley, MstnPlatform, Print, IPrintEngine, IsPlotBorderLicenseLabelNeeded));
    c1.def("GetLicenseLabel", &IPrintEngine::GetLicenseLabel, "label"_a, DOC(Bentley, MstnPlatform, Print, IPrintEngine, GetLicenseLabel));
    c1.def("Capability", &IPrintEngine::Capability, DOC(Bentley, MstnPlatform, Print, IPrintEngine, Capability));
    }
