
/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\IPlotElemDisplayParams.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>



static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetIsOverrideStyleDefined =R"doc(If a resymbolization application changes the symbology via this
interface, it should also set an override flag to indicate what should
be overriden. For example, if the application calls SetStyleIndex,
then calling SetIsOverrideStyleDefined (true) will prevent the style
from being affected by level symbology or other subsequent
resymbolization.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetIsOverrideStyleDefined =R"doc(Returns True if override style defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetIsOverrideWidthDefined =R"doc(If a resymbolization application changes the symbology via this
interface, it should also set an override flag to indicate what should
be overriden. For example, if the application calls SetWidthMM, then
calling SetIsOverrideWidthDefined (true) will prevent the width from
being affected by level symbology or other subsequent resymbolization.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetIsOverrideWidthDefined =R"doc(Returns True if override width defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetIsOverrideFillColorDefined =R"doc(If a resymbolization application changes the symbology via this
interface, it should also set an override flag to indicate what should
be overriden. For example, if the application calls SetFillColorTBGR,
then calling SetIsOverrideFillColorDefined (true) will prevent the
fill color from being affected by level symbology or other subsequent
resymbolization.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetIsOverrideFillColorDefined =R"doc(Returns True if override fill color defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetIsOverrideColorDefined =R"doc(If a resymbolization application changes the symbology via this
interface, it should also set an override flag to indicate what should
be overriden. For example, if the application calls SetLineColorTBGR,
then calling SetIsOverrideColorDefined (true) will prevent the color
from being affected by level symbology or other subsequent
resymbolization.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetIsOverrideColorDefined =R"doc(Returns True if override color defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetIsRenderable =R"doc(Indicates if the current element is renderable.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetIgnoreLevelSymb =R"doc(Gets the ignore level symbology flag.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetLevel =R"doc(Gets the current element level.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetZeroTransparency =R"doc(Indicates that 0.0 transparency should be used as an override.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetTransparency =R"doc(Set transparency. 0.0 indicates not transparent; 1.0 indicates
completely transparent.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetTransparency =R"doc(Get transparency. 0.0 indicates not transparent; 1.0 indicates
completely transparent.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetWidthMM =R"doc(Sets the line width in millimeters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetWidthMM =R"doc(Gets the line width in millimeters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetScreening =R"doc(Sets the screening value (0-100).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetScreening =R"doc(Gets the screening value.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetLineJoin =R"doc(Sets the line join.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetLineJoin =R"doc(Gets the line join.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetLineCap =R"doc(Sets the line cap.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetLineCap =R"doc(Gets the line cap.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetLineColorTBGR =R"doc(Sets the RGB line color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetLineColorTBGR =R"doc(Gets the RGB line color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetFillColorTBGR =R"doc(Sets the RGB fill color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetFillColorTBGR =R"doc(Gets the RGB fill color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetFillColor =R"doc(Sets the fill color index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetFillColor =R"doc(Gets the fill color index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetFillDisplay =R"doc(Sets the fill display mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetFillDisplay =R"doc(Gets the fill display mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetLineStyleParams =R"doc(Sets the line style parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetLineStyleParams =R"doc(Gets the line style parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetPriority =R"doc(Sets the priority.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetPriority =R"doc(Gets the priority.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetExtLineStyleIndex =R"doc(Sets the extended line style index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetExtLineStyleIndex =R"doc(Gets the extended line style index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetStyleIndex =R"doc(Sets the line style index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetStyleIndex =R"doc(Gets the line style index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetWeightIndex =R"doc(Sets the line weight index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetWeightIndex =R"doc(Gets the line weight index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetColorIndex =R"doc(Sets the line color index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetColorIndex =R"doc(Gets the line color index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_SetHasExtLineStyle =R"doc(Indicates that extended line style is defined.

Remark:
    s An extended line style is a line style code greater than 7.
    Internal use only.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasExtLineStyle =R"doc(Returns True if extended line style defined.

Remark:
    s An extended line style is a line style code greater than 7.
    Internal use only.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasLineStyleParams =R"doc(Returns True if line style parameters defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasLineWeightMM =R"doc(Returns True if line width in millimeters defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasLineCap =R"doc(Returns True if line cap defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasLineJoin =R"doc(Returns True if line join defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasTransparency =R"doc(Returns True if transparency defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetHasScreening =R"doc(Returns True if screening defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetUseFillColorRGB =R"doc(Returns True if RGB fill color defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElemDisplayParams_GetUseLineColorRGB =R"doc(Returns True if RGB line color defined.)doc";

//=======================================================================================
// Trampoline class for IPlotElemDisplayParams.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotElemDisplayParams : IPlotElemDisplayParams
{
public:
    using IPlotElemDisplayParams::IPlotElemDisplayParams;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetUseLineColorRGB() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetUseLineColorRGB, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetUseFillColorRGB() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetUseFillColorRGB, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasScreening() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasScreening, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasTransparency() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasTransparency, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasLineJoin() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasLineJoin, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasLineCap() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasLineCap, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasLineWeightMM() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasLineWeightMM, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasLineStyleParams() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasLineStyleParams, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetHasExtLineStyle() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetHasExtLineStyle, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetHasExtLineStyle(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetHasExtLineStyle, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetColorIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotElemDisplayParams, GetColorIndex, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetColorIndex(UInt32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetColorIndex, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetWeightIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotElemDisplayParams, GetWeightIndex, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetWeightIndex(UInt32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetWeightIndex, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Int32 GetStyleIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(Int32, IPlotElemDisplayParams, GetStyleIndex, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetStyleIndex(Int32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetStyleIndex, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Int32 GetExtLineStyleIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(Int32, IPlotElemDisplayParams, GetExtLineStyleIndex, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetExtLineStyleIndex(Int32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetExtLineStyleIndex, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Int32 GetPriority() const override
    {
        PYBIND11_OVERRIDE_PURE(Int32, IPlotElemDisplayParams, GetPriority, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPriority(Int32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetPriority, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual LineStyleParamsCP GetLineStyleParams() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(LineStyleParamsCP, IPlotElemDisplayParams, GetLineStyleParams, nullptr,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineStyleParams(LineStyleParamsCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetLineStyleParams, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotEdpFillDisplay GetFillDisplay() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotEdpFillDisplay, IPlotElemDisplayParams, GetFillDisplay, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetFillDisplay(PlotEdpFillDisplay value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetFillDisplay, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetFillColor() const override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotElemDisplayParams, GetFillColor, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetFillColor(UInt32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetFillColor, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetFillColorTBGR() const override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotElemDisplayParams, GetFillColorTBGR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetFillColorTBGR(UInt32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetFillColorTBGR, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 GetLineColorTBGR() const override
    {
        PYBIND11_OVERRIDE_PURE(UInt32, IPlotElemDisplayParams, GetLineColorTBGR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineColorTBGR(UInt32 value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetFillColorTBGR, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotEdpLineCap GetLineCap() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotEdpLineCap, IPlotElemDisplayParams, GetLineCap, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineCap(PlotEdpLineCap value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetLineCap, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotEdpLineJoin GetLineJoin() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotEdpLineJoin, IPlotElemDisplayParams, GetLineJoin, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineJoin(PlotEdpLineJoin value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetLineJoin, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetScreening() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotElemDisplayParams, GetScreening, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetScreening(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetScreening, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetWidthMM() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotElemDisplayParams, GetWidthMM, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetWidthMM(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetWidthMM, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetTransparency() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotElemDisplayParams, GetTransparency, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetTransparency(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetTransparency, value);
    }


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetZeroTransparency() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetZeroTransparency, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Int32 GetLevel() const override
    {
        PYBIND11_OVERRIDE_PURE(Int32, IPlotElemDisplayParams, GetLevel, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIgnoreLevelSymb() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetIgnoreLevelSymb, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsRenderable() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetIsRenderable, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsOverrideColorDefined() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetIsOverrideColorDefined, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsOverrideColorDefined(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetIsOverrideColorDefined, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsOverrideFillColorDefined() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetIsOverrideFillColorDefined, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsOverrideFillColorDefined(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetIsOverrideFillColorDefined, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsOverrideWidthDefined() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetIsOverrideWidthDefined, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsOverrideWidthDefined(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetIsOverrideWidthDefined, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsOverrideStyleDefined() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotElemDisplayParams, GetIsOverrideStyleDefined, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsOverrideStyleDefined(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotElemDisplayParams, SetIsOverrideStyleDefined, value);
    }
};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPlotElemDisplayParams(py::module_& m)
    {
    //===================================================================================
    // enum class PlotEdpFillDisplay
    py::enum_<PlotEdpFillDisplay>(m, "PlotEdpFillDisplay")
      .value("eNever", PlotEdpFillDisplay::Never)
      .value("eByView", PlotEdpFillDisplay::ByView)
      .value("eAlways", PlotEdpFillDisplay::Always)
      .value("eBlanking", PlotEdpFillDisplay::Blanking)
      .export_values();

    //===================================================================================
    // enum class PlotEdpLineJoin    
    py::enum_<PlotEdpLineJoin>(m, "PlotEdpLineJoin")
      .value("eNone", PlotEdpLineJoin::None)
      .value("eBevel", PlotEdpLineJoin::Bevel)
      .value("eMiter", PlotEdpLineJoin::Miter)
      .value("eRound", PlotEdpLineJoin::Round)
      .export_values();

    //===================================================================================
    // enum class PlotEdpLineCap        
    py::enum_<PlotEdpLineCap>(m, "PlotEdpLineCap")
      .value("eNone", PlotEdpLineCap::None)
      .value("eFlat", PlotEdpLineCap::Flat)
      .value("eSquare", PlotEdpLineCap::Square)
      .value("eRound", PlotEdpLineCap::Round)
      .value("eTriangle", PlotEdpLineCap::Triangle)
      .export_values();

    //===================================================================================
   //class IPlotElemDisplayParams
    py::class_<IPlotElemDisplayParams, IPyPlotElemDisplayParams> c0(m, "IPlotElemDisplayParams");
    c0.def(py::init<>());

    c0.def_property_readonly("UseLineColorRGB", &IPlotElemDisplayParams::GetUseLineColorRGB);
    c0.def("GetUseLineColorRGB", &IPlotElemDisplayParams::GetUseLineColorRGB, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetUseLineColorRGB));

    c0.def_property_readonly("UseFillColorRGB", &IPlotElemDisplayParams::GetUseFillColorRGB);
    c0.def("GetUseFillColorRGB", &IPlotElemDisplayParams::GetUseFillColorRGB, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetUseFillColorRGB));

    c0.def_property_readonly("HasScreening", &IPlotElemDisplayParams::GetHasScreening);
    c0.def("GetHasScreening", &IPlotElemDisplayParams::GetHasScreening, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasScreening));

    c0.def_property_readonly("HasTransparency", &IPlotElemDisplayParams::GetHasTransparency);
    c0.def("GetHasTransparency", &IPlotElemDisplayParams::GetHasTransparency, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasTransparency));

    c0.def_property_readonly("HasLineJoin", &IPlotElemDisplayParams::GetHasLineJoin);
    c0.def("GetHasLineJoin", &IPlotElemDisplayParams::GetHasLineJoin, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasLineJoin));

    c0.def_property_readonly("HasLineCap", &IPlotElemDisplayParams::GetHasLineCap);
    c0.def("GetHasLineCap", &IPlotElemDisplayParams::GetHasLineCap, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasLineCap));

    c0.def_property_readonly("HasLineWeightMM", &IPlotElemDisplayParams::GetHasLineWeightMM);
    c0.def("GetHasLineWeightMM", &IPlotElemDisplayParams::GetHasLineWeightMM, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasLineWeightMM));

    c0.def_property_readonly("HasLineStyleParams", &IPlotElemDisplayParams::GetHasLineStyleParams);
    c0.def("GetHasLineStyleParams", &IPlotElemDisplayParams::GetHasLineStyleParams, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasLineStyleParams));

    c0.def_property("HasExtLineStyle", &IPlotElemDisplayParams::GetHasExtLineStyle, &IPlotElemDisplayParams::SetHasExtLineStyle);
    c0.def("GetHasExtLineStyle", &IPlotElemDisplayParams::GetHasExtLineStyle, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetHasExtLineStyle));
    c0.def("SetHasExtLineStyle", &IPlotElemDisplayParams::SetHasExtLineStyle, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetHasExtLineStyle));

    c0.def_property("ColorIndex", &IPlotElemDisplayParams::GetColorIndex, &IPlotElemDisplayParams::SetColorIndex);
    c0.def("GetColorIndex", &IPlotElemDisplayParams::GetColorIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetColorIndex));
    c0.def("SetColorIndex", &IPlotElemDisplayParams::SetColorIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetColorIndex));

    c0.def_property("WeightIndex", &IPlotElemDisplayParams::GetWeightIndex, &IPlotElemDisplayParams::SetWeightIndex);
    c0.def("GetWeightIndex", &IPlotElemDisplayParams::GetWeightIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetWeightIndex));
    c0.def("SetWeightIndex", &IPlotElemDisplayParams::SetWeightIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetWeightIndex));

    c0.def_property("StyleIndex", &IPlotElemDisplayParams::GetStyleIndex, &IPlotElemDisplayParams::SetStyleIndex);
    c0.def("GetStyleIndex", &IPlotElemDisplayParams::GetStyleIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetStyleIndex));
    c0.def("SetStyleIndex", &IPlotElemDisplayParams::SetStyleIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetStyleIndex));

    c0.def_property("ExtLineStyleIndex", &IPlotElemDisplayParams::GetExtLineStyleIndex, &IPlotElemDisplayParams::SetExtLineStyleIndex);
    c0.def("GetExtLineStyleIndex", &IPlotElemDisplayParams::GetExtLineStyleIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetExtLineStyleIndex));
    c0.def("SetExtLineStyleIndex", &IPlotElemDisplayParams::SetExtLineStyleIndex, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetExtLineStyleIndex));

    c0.def_property("Priority", &IPlotElemDisplayParams::GetPriority, &IPlotElemDisplayParams::SetPriority);
    c0.def("GetPriority", &IPlotElemDisplayParams::GetPriority, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetPriority));
    c0.def("SetPriority", &IPlotElemDisplayParams::SetPriority, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetPriority));

    c0.def_property("LineStyleParams", &IPlotElemDisplayParams::GetLineStyleParams, &IPlotElemDisplayParams::SetLineStyleParams);
    c0.def("GetLineStyleParams", &IPlotElemDisplayParams::GetLineStyleParams, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetLineStyleParams));
    c0.def("SetLineStyleParams", &IPlotElemDisplayParams::SetLineStyleParams, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetLineStyleParams));

    c0.def_property("FillDisplay", &IPlotElemDisplayParams::GetFillDisplay, &IPlotElemDisplayParams::SetFillDisplay);
    c0.def("GetFillDisplay", &IPlotElemDisplayParams::GetFillDisplay, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetFillDisplay));
    c0.def("SetFillDisplay", &IPlotElemDisplayParams::SetFillDisplay, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetFillDisplay));

    c0.def_property("FillColor", &IPlotElemDisplayParams::GetFillColor, &IPlotElemDisplayParams::SetFillColor);
    c0.def("GetFillColor", &IPlotElemDisplayParams::GetFillColor, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetFillColor));
    c0.def("SetFillColor", &IPlotElemDisplayParams::SetFillColor, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetFillColor));

    c0.def_property("FillColorTBGR", &IPlotElemDisplayParams::GetFillColorTBGR, &IPlotElemDisplayParams::SetFillColorTBGR);
    c0.def("GetFillColorTBGR", &IPlotElemDisplayParams::GetFillColorTBGR, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetFillColorTBGR));
    c0.def("SetFillColorTBGR", &IPlotElemDisplayParams::SetFillColorTBGR, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetFillColorTBGR));

    c0.def_property("LineColorTBGR", &IPlotElemDisplayParams::GetLineColorTBGR, &IPlotElemDisplayParams::SetLineColorTBGR);
    c0.def("GetLineColorTBGR", &IPlotElemDisplayParams::GetLineColorTBGR, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetLineColorTBGR));
    c0.def("SetLineColorTBGR", &IPlotElemDisplayParams::SetLineColorTBGR, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetLineColorTBGR));

    c0.def_property("LineCap", &IPlotElemDisplayParams::GetLineCap, &IPlotElemDisplayParams::SetLineCap);
    c0.def("GetLineCap", &IPlotElemDisplayParams::GetLineCap, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetLineCap));
    c0.def("SetLineCap", &IPlotElemDisplayParams::SetLineCap, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetLineCap));

    c0.def_property("LineJoin", &IPlotElemDisplayParams::GetLineJoin, &IPlotElemDisplayParams::SetLineJoin);
    c0.def("GetLineJoin", &IPlotElemDisplayParams::GetLineJoin, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetLineJoin));
    c0.def("SetLineJoin", &IPlotElemDisplayParams::SetLineJoin, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetLineJoin));

    c0.def_property("Screening", &IPlotElemDisplayParams::GetScreening, &IPlotElemDisplayParams::SetScreening);
    c0.def("GetScreening", &IPlotElemDisplayParams::GetScreening, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetScreening));
    c0.def("SetScreening", &IPlotElemDisplayParams::SetScreening, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetScreening));

    c0.def_property("WidthMM", &IPlotElemDisplayParams::GetWidthMM, &IPlotElemDisplayParams::SetWidthMM);
    c0.def("GetWidthMM", &IPlotElemDisplayParams::GetWidthMM, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetWidthMM));
    c0.def("SetWidthMM", &IPlotElemDisplayParams::SetWidthMM, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetWidthMM));

    c0.def_property("Transparency", &IPlotElemDisplayParams::GetTransparency, &IPlotElemDisplayParams::SetTransparency);
    c0.def("GetTransparency", &IPlotElemDisplayParams::GetTransparency, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetTransparency));
    c0.def("SetTransparency", &IPlotElemDisplayParams::SetTransparency, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetTransparency));
    c0.def("SetZeroTransparency", &IPlotElemDisplayParams::SetZeroTransparency, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetZeroTransparency));

    c0.def_property_readonly("Level", &IPlotElemDisplayParams::GetLevel);
    c0.def("GetLevel", &IPlotElemDisplayParams::GetLevel, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetLevel));

    c0.def_property_readonly("IgnoreLevelSymb", &IPlotElemDisplayParams::GetIgnoreLevelSymb);
    c0.def("GetIgnoreLevelSymb", &IPlotElemDisplayParams::GetIgnoreLevelSymb, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetIgnoreLevelSymb));

    c0.def_property_readonly("IsRenderable", &IPlotElemDisplayParams::GetIsRenderable);
    c0.def("GetIsRenderable", &IPlotElemDisplayParams::GetIsRenderable, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetIsRenderable));

    c0.def_property("IsOverrideColorDefined", &IPlotElemDisplayParams::GetIsOverrideColorDefined, &IPlotElemDisplayParams::SetIsOverrideColorDefined);
    c0.def("GetIsOverrideColorDefined", &IPlotElemDisplayParams::GetIsOverrideColorDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetIsOverrideColorDefined));
    c0.def("SetIsOverrideColorDefined", &IPlotElemDisplayParams::SetIsOverrideColorDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetIsOverrideColorDefined));

    c0.def_property("IsOverrideFillColorDefined", &IPlotElemDisplayParams::GetIsOverrideFillColorDefined, &IPlotElemDisplayParams::SetIsOverrideFillColorDefined);
    c0.def("GetIsOverrideFillColorDefined", &IPlotElemDisplayParams::GetIsOverrideFillColorDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetIsOverrideFillColorDefined));
    c0.def("SetIsOverrideFillColorDefined", &IPlotElemDisplayParams::SetIsOverrideFillColorDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetIsOverrideFillColorDefined));

    c0.def_property("IsOverrideWidthDefined", &IPlotElemDisplayParams::GetIsOverrideWidthDefined, &IPlotElemDisplayParams::SetIsOverrideWidthDefined);
    c0.def("GetIsOverrideWidthDefined", &IPlotElemDisplayParams::GetIsOverrideWidthDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetIsOverrideWidthDefined));
    c0.def("SetIsOverrideWidthDefined", &IPlotElemDisplayParams::SetIsOverrideWidthDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetIsOverrideWidthDefined));

    c0.def_property("IsOverrideStyleDefined", &IPlotElemDisplayParams::GetIsOverrideStyleDefined, &IPlotElemDisplayParams::SetIsOverrideStyleDefined);
    c0.def("GetIsOverrideStyleDefined", &IPlotElemDisplayParams::GetIsOverrideStyleDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, GetIsOverrideStyleDefined));
    c0.def("SetIsOverrideStyleDefined", &IPlotElemDisplayParams::SetIsOverrideStyleDefined, DOC(Bentley, MstnPlatform, Print, IPlotElemDisplayParams, SetIsOverrideStyleDefined));
    }
