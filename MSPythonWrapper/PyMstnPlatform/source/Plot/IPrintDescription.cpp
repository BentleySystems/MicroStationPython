/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\IPrintDescription.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>



static const char * __doc_Bentley_MstnPlatform_Print_PrintDescriptionRef_Copy =R"doc(Copy the print definition instance.

Parameter ``copyPlotter``:
    If False, print definitions will share plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PrintDescriptionRef_Create =R"doc(Create an unintialized print description instance.

Remark:
    s Callers must initialize before use. )doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsPrintTo3DDisabled =R"doc(Indicates if the 'print to 3D' control should be disabled.

Remark:
    s 'Print to 3D' is only supported by the PDF printer driver, and
    when printing a 3D master design model.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsPrintFenceBoundaryDisabled =R"doc(Indicates if the fence print boundary control should be disabled.

Remark:
    s The fence boundary cannot be printed in rasterized mode, or if
    the print area mode is not Fence.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsNonOrthoPlotRotationDisabled =R"doc(Indicates if only orthogonal print rotations are supported.

Remark:
    s Non-orthogonal print rotations are not supported when camera is
    enabled, the view is rendered, or when printing to 3D.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsMirrorDisabled =R"doc(Indicates if the mirror control should be disabled.

Remark:
    s Mirrored printing is not supported when camera is enabled, the
    view is rendered, or when printing to 3D.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsColorModeDisabled =R"doc(Indicates if the print color mode control should be disabled.

Remark:
    s Some cases require printing in true color mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsRasterizedDisabled =R"doc(Indicates if the rasterized control should be disabled.

Remark:
    s Some cases, such as models containing point clouds, require
    rasterized printing. Other cases, such as vector printer drivers,
    require non-rasterized printing.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsDefaultToRasterizedMode =R"doc(Indicates if the print description should default to rasterized mode.

Remark:
    s Returns True if the maximum render mode is shaded, or point
    clouds are detected inside the active model or its references.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsRendered =R"doc(Indicates if the maximum view mode is shaded, and the print
description is not set to non-rasterized mode or 'print to 3D'.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetRasterOptions =R"doc(Sets the print description raster options.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetRasterOptions =R"doc(Gets the print description raster options.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetIsFullSheet =R"doc(Sets the full sheet mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetIsFullSheet =R"doc(Gets the full sheet mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetIsPrintTo3D =R"doc(Sets the 'print to 3D' flag.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetIsPrintTo3D =R"doc(Gets the 'print to 3D' flag.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetRasterized =R"doc(Sets the rasterized mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsRasterized =R"doc(Gets the rasterized mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPropPubMethod =R"doc(Sets the property publishing method.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPropPubMethod =R"doc(Gets the property publishing method.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_ReferenceOverrides =R"doc(Gets/Sets the print description reference overrides.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_LevelOverrides =R"doc(Gets/Sets the print description level overrides.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetColorMode =R"doc(Sets the print color mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetColorMode =R"doc(Gets the print color mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetViewGroupName =R"doc(Gets the print description view group name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetMasterModelName =R"doc(Gets the print description master model name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotFlags =R"doc(Sets the plot flags.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotFlags =R"doc(Gets the plot flags.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetViewFlags =R"doc(Sets the print view flags.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetViewFlags =R"doc(Gets the print view flags.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPropertyFilterFspec =R"doc(Sets the property publishing filter file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPropertyFilterFspec =R"doc(Gets the property publishing filter file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetDesignScriptFspec =R"doc(Sets the design script file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetDesignScriptFspec =R"doc(Gets the design script file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPenTableFspec =R"doc(Sets the pen table file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPenTableFspec =R"doc(Gets the pen table file specification.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetBorderComment =R"doc(Sets the border comment.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetBorderComment =R"doc(Gets the border comment.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetAutoFenceAlignMode =R"doc(Sets the automatic fence alignment mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetAutoFenceAlignMode =R"doc(Gets the automatic fence alignment mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetAutoCenterMode =R"doc(Sets the automatic centering mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetAutoCenterMode =R"doc(Gets the automatic centering mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotRescale =R"doc(Sets the print rescale factor (post print rotation scaling).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotRescale =R"doc(Gets the print rescale factor (post print rotation scaling).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsPlotRotation90or270 =R"doc(Indicates if the print rotation is 90 or 270 degrees.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsPlotRotationOrthogonal =R"doc(Indicates if the print rotation is orthogonal (e.g. 0, 90, 180, or 270
degrees).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_RotateForBestFit =R"doc(Sets either paper rotation or print rotation to achieve best fit.

Remark:
    s Print origin and size are automatically adjusted.

Parameter ``allowOrientationChange``:
    True to allow paper orientation change.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotRotation =R"doc(Sets the print rotation in radians (range -PI to PI).

Remark:
    s Print origin and size are automatically adjusted.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotRotation =R"doc(Gets the angle of print rotation in radians (range -PI to PI).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetMirrorAboutY =R"doc(Indicate that the plot is mirrored about the Y axis.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetMirrorAboutX =R"doc(Indicate that the plot is mirrored about the X axis.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetMirrorAboutY =R"doc(Indicates if the plot is mirrored about the Y axis.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetMirrorAboutX =R"doc(Indicates if the plot is mirrored about the X axis.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetOriginY =R"doc(Sets the Y origin (bottom offset of plot from edge of printable area).

Remark:
    s The print scale and size are automatically adjusted if
    necessary. Units are assumed to be current print description units
    as set by SetUnits. Value is the vertical offset whether
    orientation is portrait or landscape.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetOriginX =R"doc(Sets the X origin (left offset of plot from edge of printable area).

Remark:
    s The print scale and size are automatically adjusted if
    necessary. Units are assumed to be current print description units
    as set by SetUnits. Value is the horizontal offset whether
    orientation is portrait or landscape.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetOriginY =R"doc(Gets the Y origin (bottom offset of plot from edge of printable area).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetOriginX =R"doc(Gets the X origin (left offset of plot from edge of printable area).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotSizeY =R"doc(Sets the print Y size (vertical size).

Remark:
    s The print size (X and Y) must fit within the selected form size.
    Units are assumed to be print description units as set by
    SetUnits. Value is the horizontal size whether orientation is
    portrait or landscape. Print scale, X size, and origin are
    automatically adjusted.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotSizeX =R"doc(Sets the print X size (horizontal size).

Remark:
    s The print size (X and Y) must fit within the selected form size.
    Units are assumed to be print description units as set by
    SetUnits. Value is the horizontal size whether orientation is
    portrait or landscape. Print scale, Y size, and origin are
    automatically adjusted.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotSizeY =R"doc(Gets the print Y size (vertical size).

Remark:
    s Units are the print description units as set by SetUnits. Value
    is the horizontal size whether orientation is portrait or
    landscape.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotSizeX =R"doc(Gets the print X size (horizontal size).

Remark:
    s Units are the print description units as set by SetUnits. Value
    is the horizontal size whether orientation is portrait or
    landscape.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetScale =R"doc(Sets the print scale using separate master units and paper units
components.

Remark:
    s Print origin and size are automatically adjusted.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetScaleRatio =R"doc(Sets the print scale ratio (ratio of master units to paper units).

Remark:
    s Print origin and size are automatically adjusted.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetScalePU =R"doc(Gets the paper units component of the print scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetScaleMU =R"doc(Gets the master units component of the print scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetScaleRatio =R"doc(Gets the print scale ratio (ratio of master units to paper units).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_Maximize =R"doc(Maximizes the print size (e.g. sets the print size to the largest
possible value while still fitting within the selected form).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPaperOrientation =R"doc(Sets the paper orientation.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPaperOrientation =R"doc(Gets the paper orientation.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPaperDimensions =R"doc(Gets printable and/or total paper size.

Parameter ``printableSize``:
    Size of usable paper area (overall - unprintable margins). May be
    NULL.

Parameter ``totalSize``:
    Overall paper size. May be NULL.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetFormSizeY =R"doc(Sets the Y size (vertical size) of the form.

Remark:
    s Changes the paper size, not the print size. Units are assumed to
    be print description units as set by SetUnits. Value is the
    vertical size whether orientation is portrait or landscape.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetFormSizeX =R"doc(Sets the X size (horizontal size) of the form.

Remark:
    s Changes the paper size, not the print size. Units are assumed to
    be print description units as set by SetUnits. Value is the
    horizontal size whether orientation is portrait or landscape.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetFormName =R"doc(Sets the form name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetFormCP =R"doc(Gets the selected form.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetForm =R"doc(Gets the selected form.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetUnits =R"doc(Sets the print description units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetUnits =R"doc(Gets the print description units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsSheetDefined =R"doc(Indicates if the print description contains a sheet definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_IsFenceDefined =R"doc(Indicates if the print description contains a fence definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetFenceFromFitRange =R"doc(Calculates a fence from the range of all elements in the active model
and applies it to the print definition.

Parameter ``fitAll``:
    True to include references in the range calculation.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetFenceFromTCB =R"doc(Applies the fence defined in the active session to the print
description.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetViewIndex =R"doc(Sets the print description view index.

Parameter ``viewIndex``:
    view index (range 0-7).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetViewIndex =R"doc(Gets the print description view index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotArea =R"doc(Sets the print area mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotArea =R"doc(Gets the print area mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_Print =R"doc(Print to the device.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetNumCopies =R"doc(Sets the number of copies to print.

Remark:
    s Not all printer drivers support multiple copies.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetNumCopies =R"doc(Gets the number of copies to print.

Remark:
    s Not all printer drivers support multiple copies.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetPlotDestination =R"doc(Sets the print destination.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetPlotDestination =R"doc(Gets the print destination.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SelectSystemPrinter =R"doc(Sets the Windows printer name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetSystemPrinterName =R"doc(Gets the Windows printer name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_SetIsSilentMode =R"doc(Sets the print description silent mode.

Remark:
    s In silent mode, no error, warning, or informational messages are
    generated.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_GetIsSilentMode =R"doc(Indicates if the print description is in silent mode.

Remark:
    s In silent mode, no error, warning, or informational messages are
    generated.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_UpdateAfterDeviceInfoChange =R"doc(Updates the print description following a change to the Windows
printer device settings stored in the underlying Plotter instance,
when that change did not include a switch to a different Windows
printer. Settings that may have changed include the form name, form
size, orientation, and number of copies.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_UpdateAfterPrinterChange =R"doc(Updates the print description following a change to the Windows
printer in the underlying Plotter instance.

Parameter ``preserveRasterQuality``:
    True to keep the current raster quality factor.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_UpdateFromTCB =R"doc(Updates the print description from the active MicroStation session.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_InitializeFromIniFile =R"doc(Initialize a print description instance using settings from the active
session and the specified legacy .ini print definition file.

Remark:
    s The caller must ensure that the active design file and model are
    the same as when the print definition file was created.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDescription_InitializeFromTCB =R"doc(Initializes a print description instance using settings from the
active session and the specified printer driver configuration file.

Parameter ``pltcfgLfs``:
    Name of a printer driver configuration (.pltcfg or .plt) file to
    use to initialize the print description.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefinition_CustomProperties =R"doc(Gets/Sets custom properties.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefinition_SetPaperSource =R"doc(Sets the paper source (e.g. tray name).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefinition_GetPaperSource =R"doc(Gets the paper source (e.g. tray name).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefinition_GetPlotter =R"doc(Gets the print definition plotter.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPrintDefinition_SetPlotter =R"doc(Change the print definition plotter.

Parameter ``plotter``:
    New plotter. The caller retains ownership.

Parameter ``preserveLayout``:
    If true, will attempt to preserve existing paper size, scale, etc.

Parameter ``identicalPlotters``:
    If true, caller guarantees that Plotter instance is from identical
    .pltcfg.)doc";


//=======================================================================================
// Trampoline class for IPrintDefinition.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintDefinition : IPrintDefinition
{
public:
    using IPrintDefinition::IPrintDefinition;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotter(IPlotterP plotter, bool preserveLayout, bool identicalPlotters) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDefinition, SetPlotter, plotter, preserveLayout, identicalPlotters);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                        6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterP GetPlotter() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterP, IPrintDefinition, GetPlotter, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                      6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPlotterCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IPrintDefinition, GetPlotterCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                        6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPaperSource(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDefinition, GetPaperSource, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                        6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetPaperSource(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDefinition, SetPaperSource, ERROR, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapCR CustomPropertiesCR() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapCR, IPrintDefinition, CustomPropertiesCR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapR CustomProperties() override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapR, IPrintDefinition, CustomProperties, );
    }
};


//=======================================================================================
// Trampoline class for IPrintDescription.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPrintDescription : IPrintDescription
{
public:
    using IPrintDescription::IPrintDescription;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotter(IPlotterP plotter, bool preserveLayout, bool identicalPlotters) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotter, plotter, preserveLayout, identicalPlotters);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                        6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterP GetPlotter() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterP, IPrintDescription, GetPlotter, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                      6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPlotterCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IPrintDescription, GetPlotterCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                        6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPaperSource(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, GetPaperSource, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                        6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetPaperSource(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SetPaperSource, ERROR, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapCR CustomPropertiesCR() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapCR, IPrintDescription, CustomPropertiesCR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPropertyMapR CustomProperties() override
    {
        PYBIND11_OVERRIDE_PURE(PlotPropertyMapR, IPrintDescription, CustomProperties, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt InitializeFromTCB(WCharCP pltcfgLfs) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, InitializeFromTCB, ERROR, pltcfgLfs);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt InitializeFromTCB(IPlotterP plotter) override
    {
        PYBIND11_OVERRIDE_PURE_NAME_EXR(StatusInt, IPrintDescription, "InitializeFromPlotter", InitializeFromTCB, ERROR, plotter);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt InitializeFromIniFile(WCharCP iniFileLfs) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, InitializeFromIniFile, ERROR, iniFileLfs);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt UpdateFromTCB() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, UpdateFromTCB, ERROR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void UpdateAfterPrinterChange(bool preserveRasterQuality) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, UpdateAfterPrinterChange, preserveRasterQuality);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void UpdateAfterDeviceInfoChange() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, UpdateAfterDeviceInfoChange, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsSilentMode() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, GetIsSilentMode, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsSilentMode(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetIsSilentMode, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetSystemPrinterName(WStringR name) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, GetSystemPrinterName, name);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SelectSystemPrinter(WCharCP printerName) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SelectSystemPrinter, ERROR, printerName);
    }

    /*---------------------------------------------------------------------------------**//**
   * @bsimethod                                                                       6/2024
   +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotDestination GetPlotDestination() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotDestination, IPrintDescription, GetPlotDestination, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotDestination(PlotDestination destination) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotDestination, destination);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumCopies() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPrintDescription, GetNumCopies, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetNumCopies(int numCopies) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetNumCopies, numCopies);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt Print() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, Print, ERROR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt Print(WCharCP outFile) const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, Print, ERROR, outFile);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt Print(WCharCP outFile, PlotPropertyMapCR printSetProps, PlotPropertyMapCR printDefProps) const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, Print, ERROR, outFile, printSetProps, printDefProps);
    }

    /*---------------------------------------------------------------------------------**//**
   * @bsimethod                                                                       6/2024
   +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotAreaMode GetPlotArea() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotAreaMode, IPrintDescription, GetPlotArea, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetPlotArea(PlotAreaMode plotArea) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SetPlotArea, ERROR, plotArea);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetViewIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPrintDescription, GetViewIndex, );
    }


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetViewIndex(int viewIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SetViewIndex, ERROR, viewIndex);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt EvaluateFenceFromTCB(bool* plotPolyChangedP) const override
    {
        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "EvaluateFenceFromTCB");
            if (func)
            {
                auto obj = func();
                if (py::isinstance<py::bool_>(obj))
                {
                    *plotPolyChangedP = obj.cast<bool>();
                    return SUCCESS;
                }
                else
                    return ERROR;
            }
        }
        catch (std::exception& err)
        {
            ScriptEngineManager::Get().InjectException(err);
        }

        return ERROR;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetFenceFromTCB() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SetFenceFromTCB, ERROR, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetFenceFromFitRange(bool fitAll) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SetFenceFromFitRange, ERROR, fitAll);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetViewDependentFence(int* numPointsP, DPoint2dP pointsP) const override
    {
        if (!numPointsP || !pointsP)
            return;
        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetViewDependentFence");
            if (func)
            {
                DPoint2dArray dp2dArray;
                func(dp2dArray);
                *numPointsP = (int)dp2dArray.size();

                memcpy((void*)pointsP, (const void*)dp2dArray.data(), sizeof(DPoint2d) * (*numPointsP));
            }
        }
        catch (std::exception& err)
        {
            ScriptEngineManager::Get().InjectException(err);
        }
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetViewDependentFence(int numPoints, DPoint2dCP points) override
    {
        if (numPoints < 1 || !points)
            return ERROR;

        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "SetViewDependentFence");
            if (func)
            {
                DPoint2dArray dp2dArray;

                for (int i = 0; i < numPoints; i++)
                    dp2dArray.push_back(*(points + i));

                auto obj = func(dp2dArray);

                if (py::isinstance<py::int_>(obj))
                    return obj.cast<int32_t>();
                else
                    return ERROR;
            }
        }
        catch (std::exception& err)
        {
            ScriptEngineManager::Get().InjectException(err);
        }

        return ERROR;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetViewIndependentFence(int* numPointsP, DPoint3dP pointsP) const override
    {
        if (!numPointsP || !pointsP)
            return;
        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetViewIndependentFence");
            if (func)
            {
                DPoint3dArray dp3dArray;
                func(dp3dArray);
                *numPointsP = (int)dp3dArray.size();

                memcpy((void*)pointsP, (const void*)dp3dArray.data(), sizeof(DPoint3d) * (*numPointsP));
            }
        }
        catch (std::exception& err)
        {
            ScriptEngineManager::Get().InjectException(err);
        }
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetViewIndependentFence(int numPoints, DPoint3dCP points)  override
    {
        if (numPoints < 1 || !points)
            return ERROR;

        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "SetViewIndependentFence");
            if (func)
            {
                DPoint3dArray dp3dArray;

                for (int i = 0; i < numPoints; i++)
                    dp3dArray.push_back(*(points + i));

                auto obj = func(dp3dArray);

                if (py::isinstance<py::int_>(obj))
                    return obj.cast<int32_t>();
                else
                    return ERROR;
            }
        }
        catch (std::exception& err)
        {
            ScriptEngineManager::Get().InjectException(err);
        }

        return ERROR;
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetViewIndependentWorkingFence(int* numPointsP, DPoint3dP pointsP) const override
    {
        if (!numPointsP || !pointsP)
            return;

        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetViewIndependentWorkingFence");
            if (func)
            {
                DPoint3dArray dp3dArray;
                func(dp3dArray);
                *numPointsP = (int)dp3dArray.size();

                memcpy((void*)pointsP, (const void*)dp3dArray.data(), sizeof(DPoint3d) * (*numPointsP));
            }
        }
        catch (std::exception& err)
        {
            ScriptEngineManager::Get().InjectException(err);
        }
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsFenceDefined() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsFenceDefined, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsSheetDefined() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsSheetDefined, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotUnits GetUnits() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotUnits, IPrintDescription, GetUnits, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetUnits(PlotUnits units) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetUnits, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP GetForm()  override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormP, IPrintDescription, GetForm, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormCP GetFormCP() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormCP, IPrintDescription, GetFormCP, nullptr, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetFormName(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPrintDescription, SetFormName, ERROR, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetFormSizeX(double x) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetFormSizeX, x);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetFormSizeY(double y) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetFormSizeY, y);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetPaperDimensions(DPoint2dP printableSize, DPoint2dP totalSize) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, GetPaperDimensions, printableSize, totalSize);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotOrientation GetPaperOrientation() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotOrientation, IPrintDescription, GetPaperOrientation, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPaperOrientation(PlotOrientation orientation) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPaperOrientation, orientation);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void Maximize() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, Maximize, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetScaleRatio() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetScaleRatio, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetScaleMU() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetScaleMU, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetScalePU() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetScalePU, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetScaleRatio(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetScaleRatio, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetScale(double scaleMasterUnits, double scalePaperUnits) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetScale, scaleMasterUnits, scalePaperUnits);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetPlotSizeX() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetPlotSizeX, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetPlotSizeY() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetPlotSizeY, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotSizeX(double x) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotSizeX, x);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotSizeY(double y) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotSizeX, y);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetOriginX() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetOriginX, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetOriginY() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetOriginY, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetOriginX(double x) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetOriginX, x);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetOriginY(double y) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetOriginY, y);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetMirrorAboutX() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, GetMirrorAboutX, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetMirrorAboutY() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, GetMirrorAboutY, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetMirrorAboutX(bool isMirroredAboutX) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetMirrorAboutX, isMirroredAboutX);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetMirrorAboutY(bool isMirroredAboutY) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetMirrorAboutY, isMirroredAboutY);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetPlotRotation() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPrintDescription, GetPlotRotation, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotRotation(double angleRads) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotRotation, angleRads);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RotateForBestFit(bool allowOrientationChange) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, RotateForBestFit, allowOrientationChange);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPlotRotationOrthogonal() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsPlotRotationOrthogonal, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPlotRotation90or270() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsPlotRotation90or270, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2d GetPlotRescale() const override
    {
        PYBIND11_OVERRIDE_PURE(DPoint2d, IPrintDescription, GetPlotRescale, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotRescale(DPoint2d plotRescale) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotRescale, plotRescale);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetAutoCenterMode() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, GetAutoCenterMode, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetAutoCenterMode(bool autoCenter) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetAutoCenterMode, autoCenter);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotAutoAlignMode GetAutoFenceAlignMode() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotAutoAlignMode, IPrintDescription, GetAutoFenceAlignMode, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetAutoFenceAlignMode(PlotAutoAlignMode autoFenceAlignMode) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetAutoFenceAlignMode, autoFenceAlignMode);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetBorderComment(WStringR comment) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, GetBorderComment, comment);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetBorderComment(WCharCP comment) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetBorderComment, comment);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCR GetPenTableFspec() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotFileSpecCR, IPrintDescription, GetPenTableFspec, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPenTableFspec(PlotFileSpecCR value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPenTableFspec, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCR GetDesignScriptFspec() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotFileSpecCR, IPrintDescription, GetDesignScriptFspec, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDesignScriptFspec(PlotFileSpecCR value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetDesignScriptFspec, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCR GetPropertyFilterFspec() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotFileSpecCR, IPrintDescription, GetPropertyFilterFspec, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPropertyFilterFspec(PlotFileSpecCR value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPropertyFilterFspec, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ViewFlagsCR GetViewFlags() const override
    {
        PYBIND11_OVERRIDE_PURE(ViewFlagsCR, IPrintDescription, GetViewFlags, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetViewFlags(ViewFlagsCR viewFlags) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetViewFlags, viewFlags);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFlagsCR GetPlotFlags() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotFlagsCR, IPrintDescription, GetPlotFlags, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotFlags(PlotFlagsCR plotFlags) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPlotFlags, plotFlags);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetMasterModelName(WStringR modelName) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, GetMasterModelName, modelName);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetViewGroupName(WStringR viewGroupName) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, GetViewGroupName, viewGroupName);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotColorMode GetColorMode() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotColorMode, IPrintDescription, GetColorMode, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetColorMode(PlotColorMode colorMode) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetColorMode, colorMode);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual LevelOverrideList& LevelOverrides() override
    {
        PYBIND11_OVERRIDE_PURE(LevelOverrideList&, IPrintDescription, LevelOverrides, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual ReferenceOverrideList& ReferenceOverrides() override
    {
        PYBIND11_OVERRIDE_PURE(ReferenceOverrideList&, IPrintDescription, ReferenceOverrides, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PropPubMethod GetPropPubMethod() const override
    {
        PYBIND11_OVERRIDE_PURE(PropPubMethod, IPrintDescription, GetPropPubMethod, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPropPubMethod(PropPubMethod value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetPropPubMethod, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsRasterized() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsRasterized, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetRasterized(bool isRasterized) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetRasterized, isRasterized);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPrintTo3D() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, GetIsPrintTo3D, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsPrintTo3D(bool isPrintTo3D) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetIsPrintTo3D, isPrintTo3D);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsFullSheet() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, GetIsFullSheet, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsFullSheet(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetIsFullSheet, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotRasterOptionsCR GetRasterOptions() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotRasterOptionsCR, IPrintDescription, GetRasterOptions, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetRasterOptions(PlotRasterOptionsCR rasterOptions) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPrintDescription, SetRasterOptions, rasterOptions);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsRendered() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsRendered, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsDefaultToRasterizedMode() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsDefaultToRasterizedMode, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsRasterizedDisabled() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsRasterizedDisabled, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsColorModeDisabled() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsColorModeDisabled, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsMirrorDisabled() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsMirrorDisabled, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsNonOrthoPlotRotationDisabled() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsNonOrthoPlotRotationDisabled, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPrintFenceBoundaryDisabled() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsPrintFenceBoundaryDisabled, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPrintTo3DDisabled() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPrintDescription, IsPrintTo3DDisabled, );
    }
};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPrintDescription(py::module_& m)
    {
    //===================================================================================
    // enum class PlotColorMode
    py::enum_< PlotColorMode>(m, "PlotColorMode")
        .value("eUndefined", PlotColorMode::Undefined)
        .value("eMonochrome", PlotColorMode::Monochrome)
        .value("eGrayscale", PlotColorMode::Grayscale)
        .value("eTrueColor", PlotColorMode::TrueColor)
        .export_values();

    //===================================================================================
    // enum class PlotAutoAlignMode
    py::enum_< PlotAutoAlignMode>(m, "PlotAutoAlignMode")
        .value("eNone", PlotAutoAlignMode::None)
        .value("eXAxis", PlotAutoAlignMode::XAxis)
        .value("eYAxis", PlotAutoAlignMode::YAxis)
        .export_values();

    //===================================================================================
    // enum class PropPubMethod
    py::enum_< PropPubMethod>(m, "PropPubMethod")
        .value("eNone", PropPubMethod::None)
        .value("eAll", PropPubMethod::All)
        .value("ePropFilterFile", PropPubMethod::PropFilterFile)
        .export_values();

    //===================================================================================
    //class PlotFlags
    py::class_<PlotFlags> c0(m, "PlotFlags");

    c0.def_property("plotFence",
        [](PlotFlags const& self) {return self.plotFence; },
        [](PlotFlags& self, unsigned int value) {self.plotFence = value; });

    c0.def_property("plotBorder",
        [](PlotFlags const& self) {return self.plotBorder; },
        [](PlotFlags& self, unsigned int value) {self.plotBorder = value; });

    c0.def_property("plotBrokenAssocSymb",
        [](PlotFlags const& self) {return self.plotBrokenAssocSymb; },
        [](PlotFlags& self, unsigned int value) {self.plotBrokenAssocSymb = value; });

    c0.def_property("useViewBackgroundColorForRender",
        [](PlotFlags const& self) {return self.useViewBackgroundColorForRender; },
        [](PlotFlags& self, unsigned int value) {self.useViewBackgroundColorForRender = value; });

    c0.def_property("applyColorModeToRaster",
        [](PlotFlags const& self) {return self.applyColorModeToRaster; },
        [](PlotFlags& self, unsigned int value) {self.applyColorModeToRaster = value; });

    c0.def_property("printPoints",
        [](PlotFlags const& self) {return self.printPoints; },
        [](PlotFlags& self, unsigned int value) {self.printPoints = value; });

    c0.def_property("reserved",
        [](PlotFlags const& self) {return self.reserved; },
        [](PlotFlags& self, unsigned int value) {self.reserved = value; });

    //===================================================================================
    //class LevelOverrideInfo
    py::class_<LevelOverrideInfo> c1(m, "LevelOverrideInfo");
    py::bind_vector< LevelOverrideInfoArray>(m, "LevelOverrideInfoArray", py::module_local(false));

    c1.def_readwrite("LevelNameRegex", &LevelOverrideInfo::LevelNameRegex);
    c1.def_readwrite("FileNameRegex", &LevelOverrideInfo::FileNameRegex);
    c1.def_readwrite("IsOn", &LevelOverrideInfo::IsOn);

    //===================================================================================
    //class ReferenceOverrideInfo
    py::class_<ReferenceOverrideInfo> c2(m, "ReferenceOverrideInfo");
    py::bind_vector< ReferenceOverrideInfoArray>(m, "ReferenceOverrideInfoArray", py::module_local(false));

    c2.def_readwrite("FileNameRegex", &ReferenceOverrideInfo::FileNameRegex);
    c2.def_readwrite("IsOn", &ReferenceOverrideInfo::IsOn);

    //===================================================================================
    //class IPrintDefinition
    py::class_<IPrintDefinition, IPyPrintDefinition> c3(m, "IPrintDefinition");

    c3.def(py::init<>());
    c3.def("SetPlotter", &IPrintDefinition::SetPlotter, "plotter"_a, "preserveLayout"_a, "identicalPlotters"_a, DOC(Bentley, MstnPlatform, Print, IPrintDefinition, SetPlotter));
    c3.def("GetPlotter", &IPrintDefinition::GetPlotter, DOC(Bentley, MstnPlatform, Print, IPrintDefinition, GetPlotter));
    c3.def("GetPaperSource", &IPrintDefinition::GetPaperSource, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDefinition, GetPaperSource));
    c3.def("SetPaperSource", &IPrintDefinition::SetPaperSource, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDefinition, SetPaperSource));
    c3.def("CustomProperties", &IPrintDefinition::CustomProperties, DOC(Bentley, MstnPlatform, Print, IPrintDefinition, CustomProperties));

    //===================================================================================
    //class IPrintDefinition
    py::class_<IPrintDescription, IPrintDefinition, IPyPrintDescription> c4(m, "IPrintDescription");

    c4.def(py::init<>());
    c4.def("InitializeFromTCB", py::overload_cast<WCharCP>(&IPrintDescription::InitializeFromTCB), "pltcfgLfs"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, InitializeFromTCB));
    c4.def("InitializeFromTCB", py::overload_cast<IPlotterP>(&IPrintDescription::InitializeFromTCB), "plotter"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, InitializeFromTCB));
    c4.def("InitializeFromIniFile", &IPrintDescription::InitializeFromIniFile, "iniFileLfs"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, InitializeFromIniFile));
    c4.def("UpdateFromTCB", &IPrintDescription::UpdateFromTCB, DOC(Bentley, MstnPlatform, Print, IPrintDescription, UpdateFromTCB));
    c4.def("UpdateAfterPrinterChange", &IPrintDescription::UpdateAfterPrinterChange, "preserveRasterQuality"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, UpdateAfterPrinterChange));
    c4.def("UpdateAfterDeviceInfoChange", &IPrintDescription::UpdateAfterDeviceInfoChange, DOC(Bentley, MstnPlatform, Print, IPrintDescription, UpdateAfterDeviceInfoChange));
    c4.def("GetIsSilentMode", &IPrintDescription::GetIsSilentMode, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetIsSilentMode));
    c4.def("SetIsSilentMode", &IPrintDescription::SetIsSilentMode, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetIsSilentMode));
    c4.def("GetSystemPrinterName", &IPrintDescription::GetSystemPrinterName, "name"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetSystemPrinterName));
    c4.def("SelectSystemPrinter", &IPrintDescription::SelectSystemPrinter, "printerName"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SelectSystemPrinter));
    c4.def("GetPlotDestination", &IPrintDescription::GetPlotDestination, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotDestination));
    c4.def("SetPlotDestination", &IPrintDescription::SetPlotDestination, "destination"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotDestination));
    c4.def("GetNumCopies", &IPrintDescription::GetNumCopies, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetNumCopies));
    c4.def("SetNumCopies", &IPrintDescription::SetNumCopies, "numCopies"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetNumCopies));
    c4.def("Print", py::overload_cast<>(&IPrintDescription::Print, py::const_), DOC(Bentley, MstnPlatform, Print, IPrintDescription, Print));
    c4.def("Print", py::overload_cast<WCharCP>(&IPrintDescription::Print, py::const_), "outFile"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, Print));
    c4.def("Print", py::overload_cast<WCharCP, PlotPropertyMapCR, PlotPropertyMapCR>(&IPrintDescription::Print, py::const_), "outFile"_a, "printSetProps"_a, "printDefProps"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, Print));
    c4.def("GetPlotArea", &IPrintDescription::GetPlotArea, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotArea));
    c4.def("SetPlotArea", &IPrintDescription::SetPlotArea, "plotArea"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotArea));
    c4.def("GetViewIndex", &IPrintDescription::GetViewIndex, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetViewIndex));
    c4.def("SetViewIndex", &IPrintDescription::SetViewIndex, "viewIndex"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetViewIndex));

    c4.def("EvaluateFenceFromTCB", [](IPrintDescription& self) {return false; });
    c4.def("SetFenceFromTCB", &IPrintDescription::SetFenceFromTCB, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetFenceFromTCB));
    c4.def("SetFenceFromFitRange", &IPrintDescription::SetFenceFromFitRange, "fitAll"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetFenceFromFitRange));
    c4.def("GetViewDependentFence", [](IPrintDescription& self, DPoint2dArray& dp2dArray) {}, "dp2dArray"_a);
    c4.def("SetViewDependentFence", [](IPrintDescription& self, const DPoint2dArray& dp2dArray) {return ERROR;}, "dp2dArray"_a);
    c4.def("GetViewIndependentFence", [](IPrintDescription& self, DPoint3dArray& dp3dArray) {}, "dp3dArray"_a);
    c4.def("SetViewIndependentFence", [](IPrintDescription& self, const DPoint3dArray& dp3dArray) {return ERROR; }, "dp3dArray"_a);
    c4.def("GetViewIndependentWorkingFence", [](IPrintDescription& self, DPoint3dArray& dp3dArray) {}, "dp3dArray"_a);

    c4.def("IsFenceDefined", &IPrintDescription::IsFenceDefined, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsFenceDefined));
    c4.def("IsSheetDefined", &IPrintDescription::IsSheetDefined, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsSheetDefined));
    c4.def("GetUnits", &IPrintDescription::GetUnits, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetUnits));
    c4.def("SetUnits", &IPrintDescription::SetUnits, "units"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetUnits));
    c4.def("GetForm", &IPrintDescription::GetForm, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetForm));
    c4.def("GetFormCP", &IPrintDescription::GetFormCP, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetFormCP));
    c4.def("SetFormName", &IPrintDescription::SetFormName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetFormName));
    c4.def("SetFormSizeX", &IPrintDescription::SetFormSizeX, "x"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetFormSizeX));
    c4.def("SetFormSizeY", &IPrintDescription::SetFormSizeY, "y"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetFormSizeY));
    c4.def("GetPaperDimensions", &IPrintDescription::GetPaperDimensions, "printableSize"_a, "totalSize"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPaperDimensions));
    c4.def("GetPaperOrientation", &IPrintDescription::GetPaperOrientation, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPaperOrientation));
    c4.def("SetPaperOrientation", &IPrintDescription::SetPaperOrientation, "orientation"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPaperOrientation));
    c4.def("Maximize", &IPrintDescription::Maximize, DOC(Bentley, MstnPlatform, Print, IPrintDescription, Maximize));
    c4.def("GetScaleRatio", &IPrintDescription::GetScaleRatio, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetScaleRatio));
    c4.def("GetScaleMU", &IPrintDescription::GetScaleMU, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetScaleMU));
    c4.def("GetScalePU", &IPrintDescription::GetScalePU, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetScalePU));
    c4.def("SetScaleRatio", &IPrintDescription::SetScaleRatio, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetScaleRatio));
    c4.def("SetScale", &IPrintDescription::SetScale, "scaleMasterUnits"_a, "scalePaperUnits"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetScale));
    c4.def("GetPlotSizeX", &IPrintDescription::GetPlotSizeX, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotSizeX));
    c4.def("GetPlotSizeY", &IPrintDescription::GetPlotSizeY, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotSizeY));
    c4.def("SetPlotSizeX", &IPrintDescription::SetPlotSizeX, "x"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotSizeX));
    c4.def("SetPlotSizeY", &IPrintDescription::SetPlotSizeY, "y"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotSizeY));
    c4.def("GetOriginX", &IPrintDescription::GetOriginX, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetOriginX));
    c4.def("GetOriginY", &IPrintDescription::GetOriginY, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetOriginY));
    c4.def("SetOriginX", &IPrintDescription::SetOriginX, "x"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetOriginX));
    c4.def("SetOriginY", &IPrintDescription::SetOriginY, "y"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetOriginY));
    c4.def("GetMirrorAboutX", &IPrintDescription::GetMirrorAboutX, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetMirrorAboutX));
    c4.def("GetMirrorAboutY", &IPrintDescription::GetMirrorAboutY, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetMirrorAboutY));
    c4.def("SetMirrorAboutX", &IPrintDescription::SetMirrorAboutX, "isMirroredAboutX"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetMirrorAboutX));
    c4.def("SetMirrorAboutY", &IPrintDescription::SetMirrorAboutY, "isMirroredAboutY"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetMirrorAboutY));
    c4.def("GetPlotRotation", &IPrintDescription::GetPlotRotation, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotRotation));
    c4.def("SetPlotRotation", &IPrintDescription::SetPlotRotation, "angleRads"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotRotation));
    c4.def("RotateForBestFit", &IPrintDescription::RotateForBestFit, "allowOrientationChange"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, RotateForBestFit));
    c4.def("IsPlotRotationOrthogonal", &IPrintDescription::IsPlotRotationOrthogonal, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsPlotRotationOrthogonal));
    c4.def("IsPlotRotation90or270", &IPrintDescription::IsPlotRotation90or270, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsPlotRotation90or270));
    c4.def("GetPlotRescale", &IPrintDescription::GetPlotRescale, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotRescale));
    c4.def("SetPlotRescale", &IPrintDescription::SetPlotRescale, "plotRescale"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotRescale));
    c4.def("GetAutoCenterMode", &IPrintDescription::GetAutoCenterMode, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetAutoCenterMode));
    c4.def("SetAutoCenterMode", &IPrintDescription::SetAutoCenterMode, "autoCenter"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetAutoCenterMode));
    c4.def("GetAutoFenceAlignMode", &IPrintDescription::GetAutoFenceAlignMode, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetAutoFenceAlignMode));
    c4.def("SetAutoFenceAlignMode", &IPrintDescription::SetAutoFenceAlignMode, "autoFenceAlignMode"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetAutoFenceAlignMode));
    c4.def("GetBorderComment", &IPrintDescription::GetBorderComment, "comment"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetBorderComment));
    c4.def("SetBorderComment", &IPrintDescription::SetBorderComment, "comment"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetBorderComment));
    c4.def("GetPenTableFspec", &IPrintDescription::GetPenTableFspec, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPenTableFspec));
    c4.def("SetPenTableFspec", &IPrintDescription::SetPenTableFspec, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPenTableFspec));
    c4.def("GetDesignScriptFspec", &IPrintDescription::GetDesignScriptFspec, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetDesignScriptFspec));
    c4.def("SetDesignScriptFspec", &IPrintDescription::SetDesignScriptFspec, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetDesignScriptFspec));
    c4.def("GetPropertyFilterFspec", &IPrintDescription::GetPropertyFilterFspec, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPropertyFilterFspec));
    c4.def("SetPropertyFilterFspec", &IPrintDescription::SetPropertyFilterFspec, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPropertyFilterFspec));
    c4.def("GetViewFlags", &IPrintDescription::GetViewFlags, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetViewFlags));
    c4.def("SetViewFlags", &IPrintDescription::SetViewFlags, "viewFlags"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetViewFlags));
    c4.def("GetPlotFlags", &IPrintDescription::GetPlotFlags, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPlotFlags));
    c4.def("SetPlotFlags", &IPrintDescription::SetPlotFlags, "plotFlags"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPlotFlags));
    c4.def("GetMasterModelName", &IPrintDescription::GetMasterModelName, "modelName"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetMasterModelName));
    c4.def("GetViewGroupName", &IPrintDescription::GetViewGroupName, "viewGroupName"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetViewGroupName));
    c4.def("GetColorMode", &IPrintDescription::GetColorMode, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetColorMode));
    c4.def("SetColorMode", &IPrintDescription::SetColorMode, "colorMode"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetColorMode));
    c4.def("LevelOverrides", &IPrintDescription::LevelOverrides, DOC(Bentley, MstnPlatform, Print, IPrintDescription, LevelOverrides));
    c4.def("ReferenceOverrides", &IPrintDescription::ReferenceOverrides, DOC(Bentley, MstnPlatform, Print, IPrintDescription, ReferenceOverrides));
    c4.def("GetPropPubMethod", &IPrintDescription::GetPropPubMethod, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetPropPubMethod));
    c4.def("SetPropPubMethod", &IPrintDescription::SetPropPubMethod, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetPropPubMethod));
    c4.def("IsRasterized", &IPrintDescription::IsRasterized, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsRasterized));
    c4.def("SetRasterized", &IPrintDescription::SetRasterized, "isRasterized"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetRasterized));
    c4.def("GetIsPrintTo3D", &IPrintDescription::GetIsPrintTo3D, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetIsPrintTo3D));
    c4.def("SetIsPrintTo3D", &IPrintDescription::SetIsPrintTo3D, "isPrintTo3D"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetIsPrintTo3D));
    c4.def("GetIsFullSheet", &IPrintDescription::GetIsFullSheet, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetIsFullSheet));
    c4.def("SetIsFullSheet", &IPrintDescription::SetIsFullSheet, "value"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetIsFullSheet));
    c4.def("GetRasterOptions", &IPrintDescription::GetRasterOptions, DOC(Bentley, MstnPlatform, Print, IPrintDescription, GetRasterOptions));
    c4.def("SetRasterOptions", &IPrintDescription::SetRasterOptions, "rasterOptions"_a, DOC(Bentley, MstnPlatform, Print, IPrintDescription, SetRasterOptions));
    c4.def("IsRendered", &IPrintDescription::IsRendered, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsRendered));
    c4.def("IsDefaultToRasterizedMode", &IPrintDescription::IsDefaultToRasterizedMode, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsDefaultToRasterizedMode));
    c4.def("IsRasterizedDisabled", &IPrintDescription::IsRasterizedDisabled, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsRasterizedDisabled));
    c4.def("IsColorModeDisabled", &IPrintDescription::IsColorModeDisabled, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsColorModeDisabled));
    c4.def("IsMirrorDisabled", &IPrintDescription::IsMirrorDisabled, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsMirrorDisabled));
    c4.def("IsNonOrthoPlotRotationDisabled", &IPrintDescription::IsNonOrthoPlotRotationDisabled, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsNonOrthoPlotRotationDisabled));
    c4.def("IsPrintFenceBoundaryDisabled", &IPrintDescription::IsPrintFenceBoundaryDisabled, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsPrintFenceBoundaryDisabled));
    c4.def("IsPrintTo3DDisabled", &IPrintDescription::IsPrintTo3DDisabled, DOC(Bentley, MstnPlatform, Print, IPrintDescription, IsPrintTo3DDisabled));

    //===================================================================================
    //class PrintDescriptionRef
    py::class_<PrintDescriptionRef, PrintDescriptionPtr> c5(m, "PrintDescriptionRef");

    c5.def(py::init(&PrintDescriptionRef::Create));

    c5.def_static("Create", &PrintDescriptionRef::Create, DOC(Bentley, MstnPlatform, Print, PrintDescriptionRef, Create));
    c5.def("Copy", &PrintDescriptionRef::Copy, "copyPlotter"_a, DOC(Bentley, MstnPlatform, Print, PrintDescriptionRef, Copy));
    c5.def("GetP", &PrintDescriptionRef::GetP, py::return_value_policy::reference_internal);
    }


