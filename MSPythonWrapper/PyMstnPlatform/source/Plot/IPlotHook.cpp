

/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\IPlotHook.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>



static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefCreateEventHandler_PrintDefCollectState =R"doc(Called when design state is collected prior to creating a print
definition.

Remark:
    s This event allows a handler to insert custom properties into the
    print definition that is created or updated from the collected
    design state, using information from the active design file. These
    custom properties may be referenced in expressions for print
    definition names and print output file names.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintSetEventHandler_PrePrintSetDefinition =R"doc(Called before processing each print definition when printing as a set.

Remark:
    s This event is not invoked unless printing as a set, to printer
    drivers that support set printing (i.e. PDF). This event is only
    called within the interative (primary) process. It is not invoked
    within the Print Organizer worker process. Important:The
    capability to change the output file name here is provided for use
    by printer drivers only. Normal print event handlers should *not*
    attempt to change the output file name during this event.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintSetEventHandler_EndPrintSet =R"doc(Called after the last page in a print set has been completed.

Remark:
    s This event is not invoked unless printing as a set, to printer
    drivers that support set printing (i.e. PDF). This event is only
    called within the interative (primary) process. It is not invoked
    within the Print Organizer worker process. This event is called
    even if the print job fails. Use param.GetIsSuccess to query the
    job status.

:param param:
    Event parameters.

:returns:
    SUCCESS or ERROR.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintSetEventHandler_BeginPrintSet =R"doc(Called before the print engine begins work on the first page of a
print set.

Remark:
    s This event is not invoked unless printing as a set to printer
    drivers that support set printing (i.e. PDF). This event is only
    called within the interative (primary) process. It is not invoked
    within the Print Organizer worker process. Neither the global
    print engine nor its internal Plotter instance has been created
    yet, so no IPrintEngine or IPlotter calls are permitted during
    this event.

:param param:
    Event parameters.

:returns:
    SUCCESS to continue print processing; ERROR to abort the plot.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PostPlotFileClosed =R"doc(Called during cleanup operations after plot processing has finished.

Remark:
    s The plot buffer has been flushed, and the plot file (if one) has
    been closed. Post-plot operating system commands (if any) have not
    yet been executed. This event is not called for print preview, or
    in the event of plot failure.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PostPlotFileOpen =R"doc(Called during cleanup operations after plot processing has finished.

Remark:
    s The plot buffer has not been flushed, and the plot file (if one)
    is still open. It is not called for print preview, or in the event
    of plot failure.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_Resymbolize =R"doc(Gives applications the opportunity to modify the current output
symbology.

Remark:
    s This event may be invoked multiple times for a given element.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PostElementOutput =R"doc(Called after the specified element has been output.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PreElementOutput =R"doc(Called before the specified element has been output.

Remark:
    s Depending on the actions of other print event handlers, this
    element may be different than the one seen in the BeginElement
    event. Elements ignored by BeginElement handlers will not be seen
    by the PreElementOutput/PostElementOutput events.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_EndElement =R"doc(Called when the print engine has finished output and post-processing
of the specified element.

Remark:
    s The EndElement event is invoked for every element seen by
    BeginElement, even if that element was not printed.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_BeginElement =R"doc(Gives applications the opportunity to replace the element being
plotted, or defer the element with an assigned display list priority.

Remark:
    s Priority may be assigned without replacing the element. The
    input element descriptor may not be modified in any way. For
    example, this method may implement text substution or patterning
    appending linkages or changing the text characters. Since copying
    element descriptors hurts performance, simple symbology changes
    are best performed in the Resymbolize event.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PreDynamicViewClip =R"doc(Called before the plot begins to acquire the dynamic view clip for a
model.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PreModel =R"doc(Called before the print engine begins scanning elements in the
specified model, after plot structure setup for the model has been
completed.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_OnNewModelRef =R"doc(Called before the specified model is printed, and before any of the
transformations and other settings related to the model have been set
up.

Remark:
    s This event provides the opportunity to prevent the model from
    printing before any of the setup processing has begun.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_GetColorTable =R"doc(Called just after the print engine gets the color table for a model.

Remark:
    s Applications may use this event to override the default color
    table. Printing-specific overrides such as automatic white-to-
    black inversion and printer-driver-defined output colors are
    applied after this method returns.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PostElementScan =R"doc(Called just after the print engine finishes the element scanning loop.

Remark:
    s When printing in rasterized mode, this event is called once per
    tile.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PreElementScan =R"doc(Called just before the print engine begins the element scanning loop.

Remark:
    s At this point, the print engine and printer driver are fully
    initialized. Note that when printing in rasterized mode, this
    event is called once for each tile.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PrePenChart =R"doc(Called during print engine setup, before the print engine plotter is
completely configured.

Remark:
    s Non-system-printer drivers have been loaded, but have not yet
    been initialized. This event gives applications the opportunity to
    override the printer driver's pen setup before the print engine
    configures its pen chart and color table.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintEventHandler2_PrePrintDefinition =R"doc(Called before processing each print definition.

Remark:
    s Invoked after the source file has been loaded into the worker
    process and before the print output file name has been determined
    for Print Organizer. Primary purpose is to obtain the print output
    file name in the context of the Print Organizer worker process.

:param param:
    Event parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefCollectStateParam_CustomProperties =R"doc(Gets the collection of custom properties.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefCollectStateParam_SetCustomProperty =R"doc(Sets a custom property in the print definition that will be created or
updated from the collected design state.

:param name:
    Custom property name.

:param value:
    Custom property value. If NULL or empty, property will be removed
    if defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefCollectStateParam_GetRootModelRef =R"doc(Gets the root modelRef of the model for which design state is being
collected.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPreDynamicViewClipParam_SetIgnoreClip =R"doc(Indicate if dynamic view clip is to be ignored.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPreDynamicViewClipParam_GetModelRef =R"doc(Gets the modelRef for the model being printed.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreModelParam_GetIsTransientUpdate =R"doc(True if inside the transient element pass.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreModelParam_SetIgnoreModel =R"doc(Indicate whether the model is to be printed.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreModelParam_GetModelRef =R"doc(Gets the modelRef for the model about to be printed.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotGetColorTableParam_SetUseBackgroundColorFromView =R"doc(Indicate if background color is to be obtained from the view.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotGetColorTableParam_GetUseBackgroundColorFromView =R"doc(True if background color is to be obtained from the view.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotGetColorTableParam_SetApplyRefColorAdjustment =R"doc(Indicate if reference color adjustment is to be applied.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotGetColorTableParam_GetApplyRefColorAdjustment =R"doc(True if reference color adjustment is to be applied.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotGetColorTableParam_EligibleInvertWhiteToBlackColors =R"doc(Gets/Sets bitmask indicating which color indices are eligible for
automatic white/black color inversion.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotGetColorTableParam_GetModelRef =R"doc(Gets the modelRef for the model about to be printed.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPostElementOutputParam_GetElementStack =R"doc(Gets the element parameter stack.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPostElementOutputParam_GetElementDescrCP =R"doc(Gets the element descriptor.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPostElementOutputParam_GetElemHandleCP =R"doc(Gets the element handle.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreElementOutputParam_GetElementStack =R"doc(Gets the element parameter stack.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreElementOutputParam_GetElementDescrCP =R"doc(Gets the element descriptor.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreElementOutputParam_GetElemHandleCP =R"doc(Gets the element handle.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotEndElementParam_GetElementStack =R"doc(Gets the element parameter stack.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotEndElementParam_GetElementDescrCP =R"doc(Gets the element descriptor.

Remark:
    s Always the same original element descriptor passed to the
    BeginElement event.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotEndElementParam_GetElemHandleCP =R"doc(Gets the element handle.

Remark:
    s Always the same original element handle passed to the
    BeginElement event.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_SetTextBoundaryColor =R"doc(Sets the text boundary color.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_SetIsTextBoundaryColorValid =R"doc(Indicates that the text boundary color has been set.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_SetPostStrokeLineStyleIndex =R"doc(Sets the post-stroke line style index.

Remark:
    s Only supported when printing in non-rasterized mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_SetSortOrder =R"doc(Sets the post-stroke sort order.

Remark:
    s Only supported when printing in non-rasterized mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_ReplaceTextFont =R"doc(Replace all text fonts inside this element with the given font number.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_ReplaceTextString =R"doc(Replace all text strings inside this element with the given string.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_ReplaceElement =R"doc(Temporarily replace the original element with the specified one when
printing.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_IgnoreElement =R"doc(Instruct the print engine not to print this element.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_IsElementIgnored =R"doc(True if the print engine has been instructed not to print this
element.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_GetReplacementElemHandleCP =R"doc(Gets the original element descriptor.

Remark:
    s May differ from GetElementDescrCP() if another print event
    handler has replaced the element.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_GetOriginalElemHandleCP =R"doc(Gets the original element handle.

Remark:
    s May differ from GetElemHandleCP() if another print event handler
    has replaced the element.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_GetElementStack =R"doc(Gets the element parameter stack.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_GetElementDescrCP =R"doc(Gets the element descriptor.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotBeginElementParam_GetElemHandleCP =R"doc(Gets the element handle.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPostElementScanParam_IsFirstElementScan =R"doc(True if this is the first element scan.

Remark:
    s When printing in rasterized mode, the element scan is invoked
    multiple times.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPostElementScanParam_GetPrintEngine =R"doc(Gets the print engine interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreElementScanParam_IsFirstElementScan =R"doc(True if this is the first element scan.

Remark:
    s When printing in rasterized mode, the element scan is invoked
    multiple times.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPreElementScanParam_GetPrintEngine =R"doc(Gets the print engine interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotPrePenChartParam_GetPrintEngine =R"doc(Gets the print engine interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintDefinitionParam_GetIsWorker =R"doc(True if called in the context of the print worker process.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintDefinitionParam_GetIsPartOfPrintSet =R"doc(True if printing as a set.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintDefinitionParam_GetIsPreview =R"doc(True if print preview.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintDefinitionParam_GetSourceFileName =R"doc(Gets the print definition source file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintDefinitionParam_GetPrintDefinitionName =R"doc(Gets the print definition name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_SetOutputFileName =R"doc(Sets the print output file name for this print definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_GetOutputFileName =R"doc(Gets the print output file name for this print definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_GetIsPreview =R"doc(True if print preview.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_GetPrintDefinitionSourceFspec =R"doc(Gets the print definition source file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_GetPrintDefinitionFullName =R"doc(Gets the print definition full name, deliminated by forward slashes.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_GetPrintDefinitionName =R"doc(Gets the print definition name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrePrintSetDefinitionParam_GetPlotter =R"doc(Gets the plotter interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetPrinterDriverOptions =R"doc(Gets the printer driver override options. @since Version 10.02.00.00.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetPlotter =R"doc(Gets the plotter interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetEnableDynamicPlot =R"doc(@deprecated Obsolete; always False.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetIsPreview =R"doc(True if print preview.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetOutputFileSpec =R"doc(Gets the print set output file specification. May be NULL if printing
to device.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetPrintSetName =R"doc(Gets the print set name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IEndPrintSetParam_GetIsSuccess =R"doc(True if print set processing was successful.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IBeginPrintSetParam_GetPrinterDriverOptions =R"doc(Gets the printer driver override options. @since Version 10.02.00.00.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IBeginPrintSetParam_GetPlotter =R"doc(Gets the plotter interface.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IBeginPrintSetParam_GetEnableDynamicPlot =R"doc(@deprecated Obsolete; always False.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IBeginPrintSetParam_GetIsPreview =R"doc(True if print preview.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IBeginPrintSetParam_GetOutputFileSpec =R"doc(Gets the print set output file specification. May be NULL if printing
to device.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IBeginPrintSetParam_GetPrintSetName =R"doc(Gets the print set name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElementParam_GetTransform =R"doc(Gets the LocalToPlot transform for this element.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotElementParam_GetElementHandle =R"doc(Gets the element handle.)doc";

//=======================================================================================
// Trampoline class for IPlotElementParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotElementParam : IPlotElementParam
{
public:
    using IPlotElementParam::IPlotElementParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCR GetElementHandle() const override
    {
        PYBIND11_OVERRIDE_PURE(ElementHandleCR, IPlotElementParam, GetElementHandle, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual TransformCR GetTransform(PlotTagTransform tag) const override
    {
        PYBIND11_OVERRIDE_PURE(TransformCR, IPlotElementParam, GetTransform, tag);
    }

};

//=======================================================================================
// Trampoline class for IBeginPrintSetParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyBeginPrintSetParam : IBeginPrintSetParam
{
public:
    using IBeginPrintSetParam::IBeginPrintSetParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintSetName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IBeginPrintSetParam, GetPrintSetName, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCP GetOutputFileSpec() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(PlotFileSpecCP, IBeginPrintSetParam, GetOutputFileSpec, nullptr);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPreview() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IBeginPrintSetParam, GetIsPreview,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetEnableDynamicPlot() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IBeginPrintSetParam, GetEnableDynamicPlot, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPlotter() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IBeginPrintSetParam, GetPlotter, nullptr);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapCR GetPrinterDriverOptions() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapCR, IBeginPrintSetParam, GetPrinterDriverOptions, );
    }
};

//=======================================================================================
// Trampoline class for IEndPrintSetParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyEndPrintSetParam : IEndPrintSetParam
{
public:
    using IEndPrintSetParam::IEndPrintSetParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsSuccess() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IEndPrintSetParam, GetIsSuccess, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintSetName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IEndPrintSetParam, GetPrintSetName, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCP GetOutputFileSpec() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(PlotFileSpecCP, IEndPrintSetParam, GetOutputFileSpec, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPreview() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IEndPrintSetParam, GetIsPreview, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetEnableDynamicPlot() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IEndPrintSetParam, GetEnableDynamicPlot, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPlotter() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IEndPrintSetParam, GetPlotter, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapCR GetPrinterDriverOptions() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapCR, IEndPrintSetParam, GetPrinterDriverOptions, );
    }

};

//=======================================================================================
// Trampoline class for IPrePrintSetDefinitionParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrePrintSetDefinitionParam : IPrePrintSetDefinitionParam
{
public:
    using IPrePrintSetDefinitionParam::IPrePrintSetDefinitionParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPlotter() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IPrePrintSetDefinitionParam, GetPlotter, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintSetDefinitionParam, GetPrintDefinitionName, value );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionFullName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintSetDefinitionParam, GetPrintDefinitionFullName, value );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionSourceFspec(PlotFileSpecR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintSetDefinitionParam, GetPrintDefinitionSourceFspec, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPreview() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrePrintSetDefinitionParam, GetIsPreview, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetOutputFileName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintSetDefinitionParam, GetOutputFileName, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetOutputFileName(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintSetDefinitionParam, GetOutputFileName, value);
    }

};

//=======================================================================================
// Trampoline class for IPrePrintDefinitionParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrePrintDefinitionParam : IPrePrintDefinitionParam
{
public:
    using IPrePrintDefinitionParam::IPrePrintDefinitionParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPrintDefinitionName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintDefinitionParam, GetPrintDefinitionName, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetSourceFileName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrePrintDefinitionParam, GetSourceFileName, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPreview() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrePrintDefinitionParam, GetIsPreview, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPartOfPrintSet() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrePrintDefinitionParam, GetIsPartOfPrintSet, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsWorker() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrePrintDefinitionParam, GetIsWorker, );
    }
};


//=======================================================================================
// Trampoline class for IPlotPrePenChartParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPrePenChartParam : IPlotPrePenChartParam
{
public:
    using IPlotPrePenChartParam::IPlotPrePenChartParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineP GetPrintEngine() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineP, IPlotPrePenChartParam, GetPrintEngine, nullptr,);
    }
};

//=======================================================================================
// Trampoline class for IPlotPreElementScanParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPreElementScanParam : IPlotPreElementScanParam
{
public:
    using IPlotPreElementScanParam::IPlotPreElementScanParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineP GetPrintEngine() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineP, IPlotPreElementScanParam, GetPrintEngine, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsFirstElementScan() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPreElementScanParam, IsFirstElementScan,);
    }
};


//=======================================================================================
// Trampoline class for IPlotPostElementScanParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPostElementScanParam : IPlotPostElementScanParam
{
public:
    using IPlotPostElementScanParam::IPlotPostElementScanParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineP GetPrintEngine() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineP, IPlotPostElementScanParam, GetPrintEngine, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsFirstElementScan() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPostElementScanParam, IsFirstElementScan, );
    }
};


//=======================================================================================
// Trampoline class for IPlotBeginElementParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotBeginElementParam : IPlotBeginElementParam
{
public:
    using IPlotBeginElementParam::IPlotBeginElementParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotBeginElementParam, GetElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MSElementDescrCP GetElementDescrCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(MSElementDescrCP, IPlotBeginElementParam, GetElementDescrCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotElemParamStackCR GetElementStack() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotElemParamStackCR, IPlotBeginElementParam, GetElementStack, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetOriginalElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotBeginElementParam, GetOriginalElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetReplacementElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotBeginElementParam, GetReplacementElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsElementIgnored() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotBeginElementParam, IsElementIgnored, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void IgnoreElement() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, IgnoreElement, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MSElementDescrCP ReplaceElement(MSElementDescrCP edP) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(MSElementDescrCP, IPlotBeginElementParam, ReplaceElement, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void ReplaceTextString(WCharCP textString) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, ReplaceTextString, textString );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void ReplaceTextFont(UInt32 fontNum) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, ReplaceTextFont, fontNum);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetSortOrder(int sortOrder) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, SetSortOrder, sortOrder);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPostStrokeLineStyleIndex(int lineStyleIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, SetPostStrokeLineStyleIndex, lineStyleIndex);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsTextBoundaryColorValid(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, SetIsTextBoundaryColorValid, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetTextBoundaryColor(UInt32 color)override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotBeginElementParam, SetTextBoundaryColor, color);
    }
};

//=======================================================================================
// Trampoline class for IPlotEndElementParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotEndElementParam : IPlotEndElementParam
{
public:
    using IPlotEndElementParam::IPlotEndElementParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotEndElementParam, GetElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MSElementDescrCP GetElementDescrCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(MSElementDescrCP, IPlotEndElementParam, GetElementDescrCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotElemParamStackCR GetElementStack() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotElemParamStackCR, IPlotEndElementParam, GetElementStack,);
    }
};


//=======================================================================================
// Trampoline class for IPlotPreElementOutputParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPreElementOutputParam : IPlotPreElementOutputParam
{
public:
    using IPlotPreElementOutputParam::IPlotPreElementOutputParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotPreElementOutputParam, GetElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MSElementDescrCP GetElementDescrCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(MSElementDescrCP, IPlotPreElementOutputParam, GetElementDescrCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotElemParamStackCR GetElementStack() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotElemParamStackCR, IPlotPreElementOutputParam, GetElementStack, );
    }
};

//=======================================================================================
// Trampoline class for IPlotPostElementOutputParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPostElementOutputParam : IPlotPostElementOutputParam
{
public:
    using IPlotPostElementOutputParam::IPlotPostElementOutputParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotPostElementOutputParam, GetElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MSElementDescrCP GetElementDescrCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(MSElementDescrCP, IPlotPostElementOutputParam, GetElementDescrCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotElemParamStackCR GetElementStack() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotElemParamStackCR, IPlotPostElementOutputParam, GetElementStack, );
    }
};

//=======================================================================================
// Trampoline class for IPlotResymbolizeParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotResymbolizeParam : IPlotResymbolizeParam
{
public:
    using IPlotResymbolizeParam::IPlotResymbolizeParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotResymbolizeParam, GetElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual MSElementDescrCP GetElementDescrCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(MSElementDescrCP, IPlotResymbolizeParam, GetElementDescrCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ElementHandleCP GetBeginElemHandleCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(ElementHandleCP, IPlotResymbolizeParam, GetBeginElemHandleCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotElemParamStackCR GetElementStack() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotElemParamStackCR, IPlotResymbolizeParam, GetElementStack, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotElemDisplayParamsP DisplayParams() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotElemDisplayParamsP, IPlotResymbolizeParam, DisplayParams, nullptr,);
    }
};


//=======================================================================================
// Trampoline class for IPlotGetColorTableParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotGetColorTableParam : IPlotGetColorTableParam
{
public:
    using IPlotGetColorTableParam::IPlotGetColorTableParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DgnModelRefP GetModelRef() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(DgnModelRefP, IPlotGetColorTableParam, GetModelRef, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    * @remarks Returns array of 768 bytes.
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual Byte* ColorTable() override
    {
    try
        {
        py::gil_scoped_acquire gil;
        py::function func = py::get_override(this, "ColorTable");
        if (func)
            {
            py::bytes outData = func();
            std::string strData = outData.cast<std::string>();

            if (strData.size()<1) 
                return nullptr;

            static Byte clrTable[768];

            size_t bytesNum = strData.size() > 768 ? 768 : strData.size();
            memcpy(clrTable, (const void*)strData.data(), bytesNum);

            return clrTable;
            }
        }
    catch (std::exception& err)
        {
        ScriptEngineManager::Get().InjectException(err);
        }
    return nullptr;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual BitMaskP EligibleInvertWhiteToBlackColors() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(BitMaskP, IPlotGetColorTableParam, EligibleInvertWhiteToBlackColors, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetApplyRefColorAdjustment() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotGetColorTableParam, GetApplyRefColorAdjustment, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetApplyRefColorAdjustment(bool applyRefColorAdjustment) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotGetColorTableParam, SetApplyRefColorAdjustment, applyRefColorAdjustment);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetUseBackgroundColorFromView() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotGetColorTableParam, GetUseBackgroundColorFromView, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetUseBackgroundColorFromView(bool useBackgroundColorFromView) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotGetColorTableParam, SetUseBackgroundColorFromView, useBackgroundColorFromView);
    }
};

//=======================================================================================
// Trampoline class for IPlotPreModelParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotPreModelParam : IPlotPreModelParam
{
public:
    using IPlotPreModelParam::IPlotPreModelParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DgnModelRefP GetModelRef() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(DgnModelRefP, IPlotPreModelParam, GetModelRef, nullptr,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIgnoreModel(bool ignoreModel) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotPreModelParam, SetIgnoreModel, ignoreModel );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsTransientUpdate() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotPreModelParam, GetIsTransientUpdate, );
    }

};

//=======================================================================================
// Trampoline class for IPreDynamicViewClipParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPreDynamicViewClipParam : IPreDynamicViewClipParam
{
public:
    using IPreDynamicViewClipParam::IPreDynamicViewClipParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DgnModelRefP GetModelRef() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(DgnModelRefP, IPreDynamicViewClipParam, GetModelRef, nullptr,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIgnoreClip(bool ignoreClip) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPreDynamicViewClipParam, SetIgnoreClip, ignoreClip );
    }
};

//=======================================================================================
// Trampoline class for IPrintDefCollectStateParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintDefCollectStateParam : IPrintDefCollectStateParam
{
public:
    using IPrintDefCollectStateParam::IPrintDefCollectStateParam;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DgnModelRefP GetRootModelRef() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(DgnModelRefP, IPrintDefCollectStateParam, GetRootModelRef, nullptr,);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetCustomProperty(WCharCP name, WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDefCollectStateParam, SetCustomProperty, name, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapCR CustomProperties() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapCR, IPrintDefCollectStateParam, CustomProperties,);
    }
};

//=======================================================================================
// Trampoline class for IPrintEventHandler2.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintEventHandler2 : IPrintEventHandler2
{
public:
    using IPrintEventHandler2::IPrintEventHandler2;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PrePrintDefinition(IPrePrintDefinitionParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PrePrintDefinition, param);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PrePenChart(IPlotPrePenChartParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PrePenChart, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PreElementScan(IPlotPreElementScanParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PreElementScan, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PostElementScan(IPlotPostElementScanParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PostElementScan, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetColorTable(IPlotGetColorTableParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, GetColorTable, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void OnNewModelRef(IPlotPreModelParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, OnNewModelRef, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PreModel(IPlotPreModelParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PreModel, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PreDynamicViewClip(IPreDynamicViewClipParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PreDynamicViewClip, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void BeginElement(IPlotBeginElementParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, BeginElement, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void EndElement(IPlotEndElementParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, EndElement, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PreElementOutput(IPlotPreElementOutputParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PreElementOutput, param);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PostElementOutput(IPlotPostElementOutputParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PostElementOutput, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void Resymbolize(IPlotResymbolizeParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, Resymbolize, param);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PostPlotFileOpen() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, Resymbolize,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PostPlotFileClosed() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler2, PostPlotFileClosed, );
    }
};

//=======================================================================================
// Trampoline class for IPrintSetEventHandler.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintSetEventHandler : IPrintSetEventHandler
{
public:
    using IPrintSetEventHandler::IPrintSetEventHandler;


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt BeginPrintSet(IBeginPrintSetParamP param)override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintSetEventHandler, BeginPrintSet, ERROR, param);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt EndPrintSet(IEndPrintSetParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintSetEventHandler, EndPrintSet, ERROR, param);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PrePrintSetDefinition(IPrePrintSetDefinitionParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintSetEventHandler, PrePrintSetDefinition, param);
    }
};

//=======================================================================================
// Trampoline class for IPrintDefCreateEventHandler.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintDefCreateEventHandler : IPrintDefCreateEventHandler
{
public:
    using IPrintDefCreateEventHandler::IPrintDefCreateEventHandler;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void PrintDefCollectState (IPrintDefCollectStateParamP param) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDefCreateEventHandler, PrintDefCollectState, param);
    }
};


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPlotHook(py::module_& m)
    {
    //===================================================================================
    //class IPlotElementParam
    py::class_<IPlotElementParam, IPyPlotElementParam> c0(m, "IPlotElementParam");
    c0.def(py::init<>());

    c0.def("GetElementHandle", &IPlotElementParam::GetElementHandle, DOC(Bentley, MstnPlatform, Print, IPlotElementParam, GetElementHandle));
    c0.def("GetTransform", &IPlotElementParam::GetTransform, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotElementParam, GetTransform));

    //===================================================================================
    //class IBeginPrintSetParam
    py::class_<IBeginPrintSetParam, IPyBeginPrintSetParam> c1(m, "IBeginPrintSetParam");
    c1.def(py::init<>());

    c1.def("GetPrintSetName", &IBeginPrintSetParam::GetPrintSetName, "value"_a, DOC(Bentley, MstnPlatform, Print, IBeginPrintSetParam, GetPrintSetName));
    c1.def("GetOutputFileSpec", &IBeginPrintSetParam::GetOutputFileSpec, DOC(Bentley, MstnPlatform, Print, IBeginPrintSetParam, GetOutputFileSpec));
    c1.def("GetIsPreview", &IBeginPrintSetParam::GetIsPreview, DOC(Bentley, MstnPlatform, Print, IBeginPrintSetParam, GetIsPreview));
    c1.def("GetEnableDynamicPlot", &IBeginPrintSetParam::GetEnableDynamicPlot, DOC(Bentley, MstnPlatform, Print, IBeginPrintSetParam, GetEnableDynamicPlot));
    c1.def("GetPlotter", &IBeginPrintSetParam::GetPlotter, DOC(Bentley, MstnPlatform, Print, IBeginPrintSetParam, GetPlotter));
    c1.def("GetPrinterDriverOptions", &IBeginPrintSetParam::GetPrinterDriverOptions, DOC(Bentley, MstnPlatform, Print, IBeginPrintSetParam, GetPrinterDriverOptions));

    //===================================================================================
    //class IEndPrintSetParam
    py::class_<IEndPrintSetParam, IPyEndPrintSetParam> c2(m, "IEndPrintSetParam");
    c2.def(py::init<>());

    c2.def("GetIsSuccess", &IEndPrintSetParam::GetIsSuccess, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetIsSuccess));
    c2.def("GetPrintSetName", &IEndPrintSetParam::GetPrintSetName, "value"_a, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetPrintSetName));
    c2.def("GetOutputFileSpec", &IEndPrintSetParam::GetOutputFileSpec, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetOutputFileSpec));
    c2.def("GetIsPreview", &IEndPrintSetParam::GetIsPreview, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetIsPreview));
    c2.def("GetEnableDynamicPlot", &IEndPrintSetParam::GetEnableDynamicPlot, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetEnableDynamicPlot));
    c2.def("GetPlotter", &IEndPrintSetParam::GetPlotter, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetPlotter));
    c2.def("GetPrinterDriverOptions", &IEndPrintSetParam::GetPrinterDriverOptions, DOC(Bentley, MstnPlatform, Print, IEndPrintSetParam, GetPrinterDriverOptions));

    //===================================================================================
    //class IPrePrintSetDefinitionParam
    py::class_<IPrePrintSetDefinitionParam, IPyPrePrintSetDefinitionParam> c3(m, "IPrePrintSetDefinitionParam");
    c3.def(py::init<>());

    c3.def("GetPlotter", &IPrePrintSetDefinitionParam::GetPlotter, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, GetPlotter));
    c3.def("GetPrintDefinitionName", &IPrePrintSetDefinitionParam::GetPrintDefinitionName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, GetPrintDefinitionName));
    c3.def("GetPrintDefinitionFullName", &IPrePrintSetDefinitionParam::GetPrintDefinitionFullName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, GetPrintDefinitionFullName));
    c3.def("GetPrintDefinitionSourceFspec", &IPrePrintSetDefinitionParam::GetPrintDefinitionSourceFspec, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, GetPrintDefinitionSourceFspec));
    c3.def("GetIsPreview", &IPrePrintSetDefinitionParam::GetIsPreview, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, GetIsPreview));
    c3.def("GetOutputFileName", &IPrePrintSetDefinitionParam::GetOutputFileName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, GetOutputFileName));
    c3.def("SetOutputFileName", &IPrePrintSetDefinitionParam::SetOutputFileName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintSetDefinitionParam, SetOutputFileName));

    //===================================================================================
    //class IPrePrintDefinitionParam
    py::class_<IPrePrintDefinitionParam, IPyPrePrintDefinitionParam> c4(m, "IPrePrintDefinitionParam");
    c4.def(py::init<>());

    c4.def("GetPrintDefinitionName", &IPrePrintDefinitionParam::GetPrintDefinitionName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintDefinitionParam, GetPrintDefinitionName));
    c4.def("GetSourceFileName", &IPrePrintDefinitionParam::GetSourceFileName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrePrintDefinitionParam, GetSourceFileName));
    c4.def("GetIsPreview", &IPrePrintDefinitionParam::GetIsPreview, DOC(Bentley, MstnPlatform, Print, IPrePrintDefinitionParam, GetIsPreview));
    c4.def("GetIsPartOfPrintSet", &IPrePrintDefinitionParam::GetIsPartOfPrintSet, DOC(Bentley, MstnPlatform, Print, IPrePrintDefinitionParam, GetIsPartOfPrintSet));
    c4.def("GetIsWorker", &IPrePrintDefinitionParam::GetIsWorker, DOC(Bentley, MstnPlatform, Print, IPrePrintDefinitionParam, GetIsWorker));

    //===================================================================================
    //class IPlotPrePenChartParam
    py::class_<IPlotPrePenChartParam, IPyPlotPrePenChartParam> c5(m, "IPlotPrePenChartParam");
    c5.def(py::init<>());

    c5.def("GetPrintEngine", &IPlotPrePenChartParam::GetPrintEngine, DOC(Bentley, MstnPlatform, Print, IPlotPrePenChartParam, GetPrintEngine));

    //===================================================================================
    //class IPlotPreElementScanParam
    py::class_<IPlotPreElementScanParam, IPyPlotPreElementScanParam> c6(m, "IPlotPreElementScanParam");
    c6.def(py::init<>());

    c6.def("GetPrintEngine", &IPlotPreElementScanParam::GetPrintEngine, DOC(Bentley, MstnPlatform, Print, IPlotPreElementScanParam, GetPrintEngine));
    c6.def("IsFirstElementScan", &IPlotPreElementScanParam::IsFirstElementScan, DOC(Bentley, MstnPlatform, Print, IPlotPreElementScanParam, IsFirstElementScan));

    //===================================================================================
    //class IPlotPostElementScanParam
    py::class_<IPlotPostElementScanParam, IPyPlotPostElementScanParam> c7(m, "IPlotPostElementScanParam");
    c7.def(py::init<>());

    c7.def("GetPrintEngine", &IPlotPostElementScanParam::GetPrintEngine, DOC(Bentley, MstnPlatform, Print, IPlotPostElementScanParam, GetPrintEngine));
    c7.def("IsFirstElementScan", &IPlotPostElementScanParam::IsFirstElementScan, DOC(Bentley, MstnPlatform, Print, IPlotPostElementScanParam, IsFirstElementScan));

    //===================================================================================
    //class IPlotBeginElementParam
    py::class_<IPlotBeginElementParam, IPyPlotBeginElementParam> c8(m, "IPlotBeginElementParam");
    c8.def(py::init<>());

    c8.def("GetElemHandleCP", &IPlotBeginElementParam::GetElemHandleCP, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, GetElemHandleCP));
    c8.def("GetElementDescrCP", &IPlotBeginElementParam::GetElementDescrCP, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, GetElementDescrCP));
    c8.def("GetElementStack", &IPlotBeginElementParam::GetElementStack, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, GetElementStack));
    c8.def("GetOriginalElemHandleCP", &IPlotBeginElementParam::GetOriginalElemHandleCP, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, GetOriginalElemHandleCP));
    c8.def("GetReplacementElemHandleCP", &IPlotBeginElementParam::GetReplacementElemHandleCP, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, GetReplacementElemHandleCP));
    c8.def("IsElementIgnored", &IPlotBeginElementParam::IsElementIgnored, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, IsElementIgnored));
    c8.def("IgnoreElement", &IPlotBeginElementParam::IgnoreElement, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, IgnoreElement));
    c8.def("ReplaceElement", &IPlotBeginElementParam::ReplaceElement, "edP"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, ReplaceElement));
    c8.def("ReplaceTextString", &IPlotBeginElementParam::ReplaceTextString, "textString"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, ReplaceTextString));
    c8.def("ReplaceTextFont", &IPlotBeginElementParam::ReplaceTextFont, "fontNum"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, ReplaceTextFont));
    c8.def("SetSortOrder", &IPlotBeginElementParam::SetSortOrder, "sortOrder"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, SetSortOrder));
    c8.def("SetPostStrokeLineStyleIndex", &IPlotBeginElementParam::SetPostStrokeLineStyleIndex, "lineStyleIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, SetPostStrokeLineStyleIndex));
    c8.def("SetIsTextBoundaryColorValid", &IPlotBeginElementParam::SetIsTextBoundaryColorValid, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, SetIsTextBoundaryColorValid));
    c8.def("SetTextBoundaryColor", &IPlotBeginElementParam::SetTextBoundaryColor, "color"_a, DOC(Bentley, MstnPlatform, Print, IPlotBeginElementParam, SetTextBoundaryColor));

    //===================================================================================
    //class IPlotEndElementParam
    py::class_<IPlotEndElementParam, IPyPlotEndElementParam> c9(m, "IPlotEndElementParam");
    c9.def(py::init<>());

    c9.def("GetElemHandleCP", &IPlotEndElementParam::GetElemHandleCP, DOC(Bentley, MstnPlatform, Print, IPlotEndElementParam, GetElemHandleCP));
    c9.def("GetElementDescrCP", &IPlotEndElementParam::GetElementDescrCP, DOC(Bentley, MstnPlatform, Print, IPlotEndElementParam, GetElementDescrCP));
    c9.def("GetElementStack", &IPlotEndElementParam::GetElementStack, DOC(Bentley, MstnPlatform, Print, IPlotEndElementParam, GetElementStack));

    //===================================================================================
    //class IPlotPreElementOutputParam
    py::class_<IPlotPreElementOutputParam, IPyPlotPreElementOutputParam> c10(m, "IPlotPreElementOutputParam");
    c10.def(py::init<>());

    c10.def("GetElemHandleCP", &IPlotPreElementOutputParam::GetElemHandleCP, DOC(Bentley, MstnPlatform, Print, IPlotPreElementOutputParam, GetElemHandleCP));
    c10.def("GetElementDescrCP", &IPlotPreElementOutputParam::GetElementDescrCP, DOC(Bentley, MstnPlatform, Print, IPlotPreElementOutputParam, GetElementDescrCP));
    c10.def("GetElementStack", &IPlotPreElementOutputParam::GetElementStack, DOC(Bentley, MstnPlatform, Print, IPlotPreElementOutputParam, GetElementStack));

    //===================================================================================
    //class IPlotPostElementOutputParam
    py::class_<IPlotPostElementOutputParam, IPyPlotPostElementOutputParam> c11(m, "IPlotPostElementOutputParam");
    c11.def(py::init<>());

    c11.def("GetElemHandleCP", &IPlotPostElementOutputParam::GetElemHandleCP, DOC(Bentley, MstnPlatform, Print, IPlotPostElementOutputParam, GetElemHandleCP));
    c11.def("GetElementDescrCP", &IPlotPostElementOutputParam::GetElementDescrCP, DOC(Bentley, MstnPlatform, Print, IPlotPostElementOutputParam, GetElementDescrCP));
    c11.def("GetElementStack", &IPlotPostElementOutputParam::GetElementStack, DOC(Bentley, MstnPlatform, Print, IPlotPostElementOutputParam, GetElementStack));
    
    //===================================================================================
    //class IPlotPostElementOutputParam
    py::class_<IPlotGetColorTableParam, IPyPlotGetColorTableParam> c12(m, "IPlotGetColorTableParam");
    c12.def(py::init<>());

    c12.def("GetModelRef", &IPlotGetColorTableParam::GetModelRef, DOC(Bentley, MstnPlatform, Print, IPlotGetColorTableParam, GetModelRef));
    c1.def("ColorTable", [](IPlotGetColorTableParam const& self)->py::bytes { return py::bytes(); });

    c12.def("EligibleInvertWhiteToBlackColors", &IPlotGetColorTableParam::EligibleInvertWhiteToBlackColors, DOC(Bentley, MstnPlatform, Print, IPlotGetColorTableParam, EligibleInvertWhiteToBlackColors));
    c12.def("GetApplyRefColorAdjustment", &IPlotGetColorTableParam::GetApplyRefColorAdjustment, DOC(Bentley, MstnPlatform, Print, IPlotGetColorTableParam, GetApplyRefColorAdjustment));
    c12.def("SetApplyRefColorAdjustment", &IPlotGetColorTableParam::SetApplyRefColorAdjustment, "applyRefColorAdjustment"_a, DOC(Bentley, MstnPlatform, Print, IPlotGetColorTableParam, SetApplyRefColorAdjustment));
    c12.def("GetUseBackgroundColorFromView", &IPlotGetColorTableParam::GetUseBackgroundColorFromView, DOC(Bentley, MstnPlatform, Print, IPlotGetColorTableParam, GetUseBackgroundColorFromView));
    c12.def("SetUseBackgroundColorFromView", &IPlotGetColorTableParam::SetUseBackgroundColorFromView, "useBackgroundColorFromView"_a, DOC(Bentley, MstnPlatform, Print, IPlotGetColorTableParam, SetUseBackgroundColorFromView));

    //===================================================================================
    //class IPlotPreModelParam
    py::class_<IPlotPreModelParam, IPyPlotPreModelParam> c13(m, "IPlotPreModelParam");
    c13.def(py::init<>());

    c13.def("GetModelRef", &IPlotPreModelParam::GetModelRef, DOC(Bentley, MstnPlatform, Print, IPlotPreModelParam, GetModelRef));
    c13.def("SetIgnoreModel", &IPlotPreModelParam::SetIgnoreModel, DOC(Bentley, MstnPlatform, Print, IPlotPreModelParam, SetIgnoreModel));
    c13.def("GetIsTransientUpdate", &IPlotPreModelParam::GetIsTransientUpdate, DOC(Bentley, MstnPlatform, Print, IPlotPreModelParam, GetIsTransientUpdate));


    //===================================================================================
    //class IPreDynamicViewClipParam
    py::class_<IPreDynamicViewClipParam, IPyPreDynamicViewClipParam> c14(m, "IPreDynamicViewClipParam");
    c14.def(py::init<>());

    c14.def("GetModelRef", &IPreDynamicViewClipParam::GetModelRef, DOC(Bentley, MstnPlatform, Print, IPreDynamicViewClipParam, GetModelRef));
    c14.def("SetIgnoreClip", &IPreDynamicViewClipParam::SetIgnoreClip, DOC(Bentley, MstnPlatform, Print, IPreDynamicViewClipParam, SetIgnoreClip));

    //===================================================================================
    //class IPrintDefCollectStateParam
    py::class_<IPrintDefCollectStateParam, IPyPrintDefCollectStateParam> c15(m, "IPrintDefCollectStateParam");
    c15.def(py::init<>());

    c15.def("GetRootModelRef", &IPrintDefCollectStateParam::GetRootModelRef, DOC(Bentley, MstnPlatform, Print, IPrintDefCollectStateParam, GetRootModelRef));
    c15.def("SetCustomProperty", &IPrintDefCollectStateParam::SetCustomProperty, "name"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDefCollectStateParam, SetCustomProperty));
    c15.def("CustomProperties", &IPrintDefCollectStateParam::CustomProperties, DOC(Bentley, MstnPlatform, Print, IPrintDefCollectStateParam, CustomProperties));

    //===================================================================================
    //class IPrintEventHandler2
    py::class_<IPrintEventHandler2, IPyPrintEventHandler2> c16(m, "IPrintEventHandler2");
    c16.def(py::init<>());

    c16.def("PrePrintDefinition", &IPrintEventHandler2::PrePrintDefinition, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PrePrintDefinition));
    c16.def("PrePenChart", &IPrintEventHandler2::PrePenChart, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PrePenChart));
    c16.def("PreElementScan", &IPrintEventHandler2::PreElementScan, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PreElementScan));
    c16.def("PostElementScan", &IPrintEventHandler2::PostElementScan, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PostElementScan));
    c16.def("GetColorTable", &IPrintEventHandler2::GetColorTable, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, GetColorTable));
    c16.def("OnNewModelRef", &IPrintEventHandler2::OnNewModelRef, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, OnNewModelRef));
    c16.def("PreModel", &IPrintEventHandler2::PreModel, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PreModel));
    c16.def("PreDynamicViewClip", &IPrintEventHandler2::PreDynamicViewClip, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PreDynamicViewClip));
    c16.def("BeginElement", &IPrintEventHandler2::BeginElement, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, BeginElement));
    c16.def("EndElement", &IPrintEventHandler2::EndElement, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, EndElement));
    c16.def("PreElementOutput", &IPrintEventHandler2::PreElementOutput, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PreElementOutput));
    c16.def("PostElementOutput", &IPrintEventHandler2::PostElementOutput, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PostElementOutput));
    c16.def("Resymbolize", &IPrintEventHandler2::Resymbolize, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, Resymbolize));
    c16.def("PostPlotFileOpen", &IPrintEventHandler2::PostPlotFileOpen, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PostPlotFileOpen));
    c16.def("PostPlotFileClosed", &IPrintEventHandler2::PostPlotFileClosed, DOC(Bentley, MstnPlatform, Print, IPrintEventHandler2, PostPlotFileClosed));


    //===================================================================================
    //class IPrintSetEventHandler
    py::class_<IPrintSetEventHandler, IPyPrintSetEventHandler> c17(m, "IPrintSetEventHandler");
    c17.def(py::init<>());

    c17.def("BeginPrintSet", &IPrintSetEventHandler::BeginPrintSet, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintSetEventHandler, BeginPrintSet));
    c17.def("EndPrintSet", &IPrintSetEventHandler::EndPrintSet, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintSetEventHandler, EndPrintSet));
    c17.def("PrePrintSetDefinition", &IPrintSetEventHandler::PrePrintSetDefinition, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintSetEventHandler, PrePrintSetDefinition));


    //===================================================================================
    //class IPrintDefCreateEventHandler
    py::class_<IPrintDefCreateEventHandler, IPyPrintDefCreateEventHandler> c18(m, "IPrintDefCreateEventHandler");
    c18.def(py::init<>());

    c18.def("PrintDefCollectState", &IPrintDefCreateEventHandler::PrintDefCollectState, "param"_a, DOC(Bentley, MstnPlatform, Print, IPrintDefCreateEventHandler, PrintDefCollectState));
    }
