/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\Plot\IPlotter.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <OpqueTypes_MstnPlatform.h>



static const char * __doc_Bentley_MstnPlatform_Print_PlotterRef_Copy =R"doc(Copy the plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_PlotterRef_Create =R"doc(Create an unintialized plotter instance.

Remark:
    s Callers must initialize before use.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetEngineBackgroundColor =R"doc(Gets the print background color.

Remark:
    s Should only be called only during print processing.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetEngineColorFromIndex =R"doc(Gets the effective print color for the given color table index.

Remark:
    s Should only be called only during print processing.

Parameter ``colorIndex``:
    Color table index (range 0-255))doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetEngineColorFromPen =R"doc(Gets the effective print color for the given pen number.

Remark:
    s Should only be called only during print processing.

Parameter ``pen``:
    Pen number (range 0-255))doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetEngineLineStyle =R"doc(Gets print engine line style pattern in dots for a particular index.

Remark:
    s Should only be called only during print processing.

Parameter ``styleIndex``:
    Line style index (range 0-(MAX_LINESTYLES+NumExtLineStyles-1)))doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetEngineLineWidth =R"doc(Sets the print engine line width for a particular weight index.

Remark:
    s Should only be called only during print processing. Note that
    the return value is only from the base weight-to-width mapping
    table. The actual print width may come from the color-index-to-
    width table or elsewhere. Should only be called only during print
    processing.

Parameter ``weight``:
    Weight index (range 0 to 31)

Parameter ``lineWidthDots``:
    New print width in dots.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetEngineLineWidth =R"doc(Gets the print engine line width for a particular weight.

Remark:
    s The value is print width in dots. Note that the returned value
    is only from the base weight-to-width mapping table. The actual
    print width may come from the color-index-to-width table or
    elsewhere. Should only be called only during print processing.

Parameter ``weight``:
    Weight index (range 0 to 31).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetEngineError =R"doc(Sets the current error code in the Plotter instance. Should only be
called only during print processing.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetEngineError =R"doc(Gets the current error code from the Plotter instance. Should only be
called only during print processing.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_FindBestFitForm =R"doc(Gets the form that best fits the specified width and height.

Parameter ``requestWidthDots``:
    Requested form width in dots.

Parameter ``requestHeightDots``:
    Requested form height in dots.

Parameter ``requestUnits``:
    Indicates preference for standard ANSI or ISO forms; must be
    PlotUnits::in or PlotUnits::mm.

Parameter ``bestFitFormIndexP``:
    Returns index of the form that best fits the requested size.

Parameter ``selectedFormFitsP``:
    Returns True if the selected form accomodates the requested size
    without clipping. May be NULL.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetSystemPrinterOrientation =R"doc(Sets the system printer orientation.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SelectSystemPrinter =R"doc(Selects the specified system printer name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetSystemPrinterName =R"doc(Selects the currently selected system printer name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_FindCompanionFile =R"doc(Searches for a companion file to the printer driver configuration file
in the same directory as the .pltcfg file, or in MS_PLTCFG_PATH.
Intended to be called only by printer drivers.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_FindFormByNameSizeMatch =R"doc(Attempts to locate the closest matching form defined for this plotter
to the specified form.

Remark:
    s The first check is for identical form name and form size. If no
    such match exists, the best-fitting form is chosen.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_IsPrintToIpserver =R"doc(Indicates if the current plot destination is InterPlot Server.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_IsPrintToMetafile =R"doc(Indicates if the current plot destination is a Windows metafile.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_IsPrintToFile =R"doc(Indicates if the current plot destination is a file.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetHwTextMode =R"doc(Sets the hardware text mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetHwTextMode =R"doc(Gets the hardware text mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetPlotDestination =R"doc(Sets the plotter default plot destination.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPlotDestination =R"doc(Gets the plotter default plot destination.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_OleParam =R"doc(Gets the interface used to modify OLE plotting parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_RasterizedParam =R"doc(Gets the interface used to modify rasterized plotting parameters.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_RoundPaperSize =R"doc(Rounds the given paper size to nearest value appropriate for the
specified rounding units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetDriverCoordSysOrigin =R"doc(Sets the current driver coordinate system origin.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetDriverCoordSysOrigin =R"doc(Gets the current driver coordinate system origin.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetDriverOutputMode =R"doc(Sets the current driver output mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetDriverOutputMode =R"doc(Gets the current driver output mode.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPrinterDriver =R"doc(Gets the printer driver interface associated with this plotter
instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetRasterOptions =R"doc(Sets the raster options in the plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetRasterOptions =R"doc(Gets a copy of the raster options structure.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_FlushBuffer =R"doc(Flushes the plotting buffer.

Remark:
    s Normally, a plotter driver never needs to call this. As a driver
    calls WriteCommand, FlushBuffer is called automatically. It is
    also called at the end of the plot.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_CopyFileIntoPlotFile =R"doc(Copies the contents of the specified file into the plot output file.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SelectTrayByName =R"doc(Selects the specified tray name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SelectFormByName =R"doc(Selects the specified form name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_FontMaps =R"doc(Gets the interface used to add/remove/edit the plotter hardware font
maps.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_FormsCP =R"doc(Gets the interface used to query the plotter paper sizes.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_Forms =R"doc(Gets the interface used to add/remove/edit/query the plotter paper
sizes.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetExtLineStyles =R"doc(Sets the array of extended line style definitions. Units must be dots.
Internal use only.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetExtLineStyles =R"doc(Gets the array of extended line style definitions.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetNumExtLineStyles =R"doc(Gets the number of extended line style definitions.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetLineStyle =R"doc(Sets the print line style for the specified line style index.

Remark:
    s This value is converted into pixels by the print engine at the
    time of print processing, taking into account the paper size line
    style scale factor. Should be called prior to starting the print
    engine. param styleIndex[in] Line style index (range 0-7). param
    lineStyle[in] New line style definition.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetLineStyle =R"doc(Gets the print line style for the specified line style index. param
styleIndex[in] Line style index (range 0-7).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetLineWidth =R"doc(Sets the line width in physical units for the specified weight.

Remark:
    s This value is converted into pixels by the print engine at the
    time of print processing, taking into account the paper size line
    width scale factor. Should be called prior to starting the print
    engine.

Parameter ``weight``:
    (range 0-31).

Parameter ``units``:
    Units for physical width.

Parameter ``width``:
    New physical width.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetLineWidth =R"doc(Gets the line width in physical units for the specified weight.

Parameter ``weight``:
    (range 0-31).

Parameter ``unitsP``:
    Units for physical width.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetRasterCompression =R"doc(Gets a constant reference to the RasterCompression structure.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetPenSetup =R"doc(Call to set pen characteristics for a particular pen number.

Parameter ``pen``:
    Pen number (range 0-255), where 0=background pen

Parameter ``penSetup``:
    Input pen setup structure.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPenSetup =R"doc(Gets pen characteristics for a particular pen number.

Parameter ``pen``:
    Pen number (range 0-255), where 0=background pen)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetIsPenColorDefined =R"doc(Indicates whether the particular pen color was set in the printer
driver configuration file.

Parameter ``pen``:
    Pen number (range 0-255), where 0=background pen)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPenColor =R"doc(Gets the color for a particular pen number.

Parameter ``pen``:
    Pen number (range 0-255), where 0=background pen)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetPenFromColorIndex =R"doc(Sets the pen number corresponding to the given color table index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPenFromColorIndex =R"doc(Gets the pen number corresponding to the given color table index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_ConvertUnits =R"doc(Converts values from one units to another.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetPlotterUnits =R"doc(Sets the plotter units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPlotterUnits =R"doc(Gets the plotter units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetIsDefinedInPltcfg =R"doc(Sets a flag indicating if the specified property was defined in the
printer driver configuration file.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetIsDefinedInPltcfg =R"doc(Gets a flag indicating if the specified property was defined in the
printer driver configuration file.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetFileSpecCP =R"doc(Gets a const FileSpec value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetFileSpecP =R"doc(Gets a FileSpec value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetTriState =R"doc(Sets a tristate value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetTriState =R"doc(Gets a tristate value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetString =R"doc(Sets a string value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetString =R"doc(Gets a string value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetDPoint3d =R"doc(Sets a DPoint3d value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetDPoint3d =R"doc(Gets a DPoint3d value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetDPoint2d =R"doc(Sets a DPoint2d value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetDPoint2d =R"doc(Gets a DPoint2d value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetDouble =R"doc(Sets a double value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetDouble =R"doc(Gets a double value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetInt =R"doc(Sets an integer value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetInt =R"doc(Gets an integer value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_SetBool =R"doc(Sets a boolean value in the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetBool =R"doc(Gets a boolean value from the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_GetPltcfgFspec =R"doc(Gets the printer driver configuration file specification for this
Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_Copy =R"doc(Duplicates the Plotter instance.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotter_Initialize =R"doc(Initializes the Plotter instance from the specified printer driver
configuration file.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotOleParam_GetRasterize =R"doc(Gets whether or not OLE objects should always be rasterized.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotOleParam_SetRasterize =R"doc(Sets whether or not OLE objects should always be rasterized.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotOleParam_GetQuality =R"doc(Gets the ratio of rasterized OLE resolution over vector plot
resolution.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotOleParam_SetQuality =R"doc(Sets the ratio of rasterized OLE resolution over vector plot
resolution.

Remark:
    s This setting has no effect on non-rasterized OLE objects, e.g.
    those output by the system printer driver in non-rasterized mode.

Parameter ``value``:
    Range 0.0<value <= 1.0.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterizedParam_GetQuality =R"doc(Gets the ratio of rasterized plot resolution over vector plot
resolution.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotRasterizedParam_SetQuality =R"doc(Sets the ratio of rasterized plot resolution over vector plot
resolution.

Parameter ``value``:
    Range 0.0<value <= 1.0.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMapList_RemoveAllFontMaps =R"doc(Removes all font maps.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMapList_RemoveFontMap =R"doc(Removes the font map at the specified index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMapList_GetDgnFontMapP =R"doc(Gets the font map at the specified index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMapList_GetNumFontMaps =R"doc(Get the number of font maps.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_GetHwSizeRatio =R"doc(Gets the hardware font size ratio.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_SetHwSizeRatio =R"doc(Sets the hardware font size ratio.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_GetHwKern =R"doc(Gets the hardware font kerning value.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_SetHwKern =R"doc(Sets the hardware font kerning value.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_GetHwFontName =R"doc(Gets the hardware font name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_SetHwFontName =R"doc(Sets the hardware font name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_GetMsFontName =R"doc(Gets the MicroStation font name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_SetMsFontName =R"doc(Sets the MicroStation font name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_GetMsFontNumber =R"doc(Gets the MicroStation font number.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_GetMsFontType =R"doc(Gets the MicroStation font type.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotFontMap_SetMsFontType =R"doc(Sets the MicroStation font type.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_RemoveAllForms =R"doc(Removes all forms from the list.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_RemoveForm =R"doc(Removes a form from the list.

Parameter ``formListIndex``:
    Index into the form list, or -1 for current form.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_AppendForm =R"doc(Creates a new form in the list.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetFormByPaperSizeNumber =R"doc(Gets information about a particular form paper size number.

Parameter ``searchPaperSizeNumber``:
    Paper size number to search for.

Parameter ``formListIndexP``:
    Returned index into the form list of new form (may be NULL).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetFormByName =R"doc(Gets information about a particular form name.

Parameter ``searchName``:
    Form name to search for.

Parameter ``formListIndexP``:
    Returned index into the form list of new form (may be NULL).)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetFormByIndex =R"doc(Gets information about a particular form index.

Parameter ``formListIndex``:
    Index into the form list, or -1 for current form.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetDefaultFormIndex =R"doc(Gets the index of the default form in the form list. Will be -1 if no
default form defined.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetCurrentFormIndex =R"doc(Gets the index of the current form in the form list.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetCurrentForm =R"doc(Gets the current form in the form list. May be NULL.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_SetCurrentForm =R"doc(Sets the current form in the form list.

Parameter ``formListIndex``:
    Index into the form list, or -1 for current form.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterFormList_GetNumForms =R"doc(Gets the number of forms defined for the plotter.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_IsNoneForm =R"doc(Indicates whether this form is the reserved " NONE " form.

Remark:
    s The NONE form is used in conjunction with InterPlot Server.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetAutoRotate =R"doc(Gets the form auto rotation direction.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetAutoRotate =R"doc(Sets the form auto rotation direction.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetLineStyleScale =R"doc(Gets the form line style scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetLineStyleScale =R"doc(Sets the form line style scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetLineWeightScale =R"doc(Gets the form line weight scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetLineWeightScale =R"doc(Sets the form line weight scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetDefaultFormScale =R"doc(Gets the form default scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetDefaultFormScale =R"doc(Sets the form default scale.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetFormIndex =R"doc(Gets the form index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetFormIndex =R"doc(Sets the form index.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetPaperSizeNumber =R"doc(Gets the form paper size number.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetPaperSizeNumber =R"doc(Sets the form paper size number.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetPrintableOffset =R"doc(Gets the form printable offset.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetPrintableOffset =R"doc(Sets the form printable offset.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetPrintableSize =R"doc(Gets the form printable size.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetPrintableSize =R"doc(Sets the form printable size.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetTotalSize =R"doc(Gets the form total size.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetTotalSize =R"doc(Sets the form total size.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_IsFormSizeIdentical =R"doc(Indicates whether this form has the same size as the specified form.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetOrientation =R"doc(Gets the form orientation.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetOrientation =R"doc(Sets the form orientation.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetUnits =R"doc(Gets the form units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetUnits =R"doc(Sets the form units.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetActualName =R"doc(Gets the form actual name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetActualName =R"doc(Sets the form actual name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_GetName =R"doc(Gets the form name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_SetName =R"doc(Sets the form name.)doc";

static const char * __doc_Bentley_MstnPlatform_Print_IPlotterForm_Clone =R"doc(Clones this form.)doc";

//=======================================================================================
// Trampoline class for IPlotter.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotter : IPlotter
{
public:
    using IPlotter::IPlotter;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt Initialize(PlotFileSpecR pltcfgFspec) override
        {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPlotter, Initialize, ERROR, pltcfgFspec);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterP Copy() const override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterP, IPlotter, Copy, nullptr,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCR GetPltcfgFspec() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotFileSpecCR, IPlotter, GetPltcfgFspec, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetBool(PlotTagBool tag) const override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, GetBool, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetBool(PlotTagBool tag, bool value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetBool, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetInt(PlotTagInt tag) const override
        {
        PYBIND11_OVERRIDE_PURE(int, IPlotter, GetInt, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetInt(PlotTagInt tag, int value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetInt, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetDouble(PlotTagDbl tag) const override
        {
        PYBIND11_OVERRIDE_PURE(double, IPlotter, GetDouble, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDouble(PlotTagDbl tag, double value)  override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetDouble, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2d GetDPoint2d(PlotTagDPoint2d tag) const override
        {
        PYBIND11_OVERRIDE_PURE(DPoint2d, IPlotter, GetDPoint2d, tag);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDPoint2d(PlotTagDPoint2d tag, DPoint2dCR value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetDPoint2d, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint3d GetDPoint3d(PlotTagDPoint3d tag) const override
        {
        PYBIND11_OVERRIDE_PURE(DPoint3d, IPlotter, GetDPoint3d, tag);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDPoint3d(PlotTagDPoint3d tag, DPoint3dCR value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetDPoint3d, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetString(PlotTagStr tag, WStringR value) const override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, GetString, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetString(PlotTagStr tag, WCharCP value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetString, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void* GetPointer(PlotTagPtr tag) const override
        {
        try
            {
            py::gil_scoped_acquire gil;
            void* retVal = nullptr;
            py::function func = py::get_override(this, "GetPointer");
            if (func)
                {
                auto obj = func(tag);
                auto holder = obj.cast<py::capsule>();
                retVal = holder.get_pointer();
                }

            return retVal;
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }

        return nullptr;
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPointer(PlotTagPtr tag, void* value) override
        {
        if (!value)
            return; 

        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "SetPointer");
            if (func)
                {
                py::capsule arg(value);
                func(tag, arg);
                }
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotTriState GetTriState(PlotTagTriState tag) const override
        {
        PYBIND11_OVERRIDE_PURE(PlotTriState, IPlotter, GetTriState, tag);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetTriState(PlotTagTriState tag, PlotTriState value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetTriState, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecP GetFileSpecP(PlotTagFileSpec tag) override
        {
        PYBIND11_OVERRIDE_PURE_EXR(PlotFileSpecP, IPlotter, GetFileSpecP, nullptr, tag);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotFileSpecCP GetFileSpecCP(PlotTagFileSpec tag) const override
        {
        PYBIND11_OVERRIDE_PURE_EXR(PlotFileSpecCP, IPlotter, GetFileSpecCP, nullptr, tag);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsDefinedInPltcfg(PlotTagIsDefinedInPltcfg tag) const override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, GetIsDefinedInPltcfg, tag);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetIsDefinedInPltcfg(PlotTagIsDefinedInPltcfg tag, bool value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetIsDefinedInPltcfg, tag, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotUnits GetPlotterUnits() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotUnits, IPlotter, GetPlotterUnits, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotterUnits(PlotUnits units) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetPlotterUnits, units);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double ConvertUnits(double value, PlotUnits fromUnits, PlotUnits toUnits) const override
        {
        PYBIND11_OVERRIDE_PURE(double, IPlotter, ConvertUnits, value, fromUnits, toUnits);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double ConvertUnits(double value, PlotUnits units, bool convertStoredToUnits) const override
        {
        PYBIND11_OVERRIDE_PURE(double, IPlotter, ConvertUnits, value, units, convertStoredToUnits);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetPenFromColorIndex(int index) const override
        {
        PYBIND11_OVERRIDE_PURE(int, IPlotter, GetPenFromColorIndex, index);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPenFromColorIndex(int index, int pen) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetPenFromColorIndex, index, pen);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbaColorDef GetPenColor(int pen) const override
        {
        PYBIND11_OVERRIDE_PURE(RgbaColorDef, IPlotter, GetPenColor, pen);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPenColorDefined(int pen) const override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, GetIsPenColorDefined, pen);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotPenSetup GetPenSetup(int pen) const override
        {
        PYBIND11_OVERRIDE_PURE(PlotPenSetup, IPlotter, GetPenSetup, pen);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPenSetup(int pen, PlotPenSetupCR penSetup) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetPenSetup, pen, penSetup);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotRasterComprCR GetRasterCompression() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotRasterComprCR, IPlotter, GetRasterCompression,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetLineWidth(int weight, PlotUnits* unitsP) const override
        {
        PYBIND11_OVERRIDE_PURE(double, IPlotter, GetLineWidth, weight, unitsP);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineWidth(int weight, PlotUnits units, double width) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetLineWidth, weight, units, width);
        }


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotLineStyleDefCR GetLineStyle(int styleIndex) const override
        {
        PYBIND11_OVERRIDE_PURE(PlotLineStyleDefCR, IPlotter, GetLineStyle, styleIndex);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineStyle(int styleIndex, PlotLineStyleDefCR lineStyle) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetLineStyle, styleIndex, lineStyle);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumExtLineStyles() const override
        {
        PYBIND11_OVERRIDE_PURE(int, IPlotter, GetNumExtLineStyles,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotLineStyleDefP GetExtLineStyles() override
        {
        PYBIND11_OVERRIDE_PURE_EXR(PlotLineStyleDefP, IPlotter, GetExtLineStyles, nullptr, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetExtLineStyles(int numExtLineStyles, PlotLineStyleDefCP extLineStylesDots) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetExtLineStyles, numExtLineStyles, extLineStylesDots);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormListP Forms() override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormListP, IPlotter, Forms, nullptr,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormListCP FormsCP() const override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormListCP, IPlotter, FormsCP, nullptr, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotFontMapListP FontMaps() override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotFontMapListP, IPlotter, FontMaps, nullptr, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SelectFormByName(WCharCP formName) override
        {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPlotter, SelectFormByName, ERROR, formName);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SelectTrayByName(WCharCP trayName) override
        {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPlotter, SelectTrayByName, ERROR, trayName);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void WriteCommand(byte const* buffer, int numBytes) override
        {   
        if (!buffer || numBytes < 1)
            return;

        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "WriteCommand");
            if (func)
                {
                py::bytes inData = py::bytes((const char*)buffer, numBytes);
                func(inData);
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
    virtual void WriteString(byte const* buffer) override
        {
        size_t numBytes(0);

        if (!buffer || (numBytes = strlen((const char*)buffer)) < 1 )
            return;

        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "WriteString");
            if (func)
                {
                py::str inVal((const char*)buffer);
                func(inVal);
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
    virtual void CopyFileIntoPlotFile(WCharCP filename) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, CopyFileIntoPlotFile, filename);
        }


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void FlushBuffer() override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, FlushBuffer, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotRasterOptionsCR GetRasterOptions() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotRasterOptionsCR, IPlotter, GetRasterOptions, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetRasterOptions(PlotRasterOptionsCR rasterOptions) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetRasterOptions, rasterOptions);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrinterDriverBaseP GetPrinterDriver() const override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPrinterDriverBaseP, IPlotter, GetPrinterDriver, nullptr,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPrinterDriver(IPrinterDriverBaseP driverP) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetPrinterDriver, driverP );
        }


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DriverOutputMode GetDriverOutputMode() const override
        {
        PYBIND11_OVERRIDE_PURE(DriverOutputMode, IPlotter, GetDriverOutputMode,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDriverOutputMode(DriverOutputMode mode) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetDriverOutputMode, mode);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DriverCoordSysOrigin GetDriverCoordSysOrigin() const override
        {
        PYBIND11_OVERRIDE_PURE(DriverCoordSysOrigin, IPlotter, GetDriverCoordSysOrigin, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDriverCoordSysOrigin(DriverCoordSysOrigin origin) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetDriverCoordSysOrigin, origin);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RoundPaperSize(PlotUnits roundingUnits, PlotUnits sizeUnits, DPoint2dP size) const override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, RoundPaperSize, roundingUnits, sizeUnits, size);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotRasterizedParamR RasterizedParam() override
        {
        PYBIND11_OVERRIDE_PURE(IPlotRasterizedParamR, IPlotter, RasterizedParam,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotOleParamR OleParam() override
        {
        PYBIND11_OVERRIDE_PURE(IPlotOleParamR, IPlotter, OleParam, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotDestination GetPlotDestination() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotDestination, IPlotter, GetPlotDestination, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPlotDestination(PlotDestination destination) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetPlotDestination, destination);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotHwTextMode GetHwTextMode() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotHwTextMode, IPlotter, GetHwTextMode, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetHwTextMode(PlotHwTextMode value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetHwTextMode, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPrintToFile() const override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, IsPrintToFile, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPrintToMetafile() const override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, IsPrintToMetafile, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsPrintToIpserver() const override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, IsPrintToIpserver, );
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP FindFormByNameSizeMatch(IPlotterFormP requestForm, PlotUnits requestUnits) const override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormP, IPlotter, FindFormByNameSizeMatch, nullptr, requestForm, requestUnits);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool FindCompanionFile(PlotFileSpecR fileSpec) override
        {
        PYBIND11_OVERRIDE_PURE(bool, IPlotter, FindCompanionFile, fileSpec);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetSystemPrinterName(WStringR printerName) const override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, GetSystemPrinterName, printerName);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SelectSystemPrinter(WCharCP printerName) override
        {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPlotter, SelectSystemPrinter, ERROR, printerName);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual StatusInt SetSystemPrinterOrientation(PlotOrientation orientation) override
        {
        PYBIND11_OVERRIDE_PURE_EXR(StatusInt, IPlotter, SetSystemPrinterOrientation, ERROR, orientation);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void FindBestFitForm(double requestWidthDots, double requestHeightDots, PlotUnits requestUnits,
        int* bestFitFormIndexP, bool* selectedFormFitsP) const override
        {

        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "FindBestFitForm");
            if (func)
                {
                Int32Array indexArray;
                BoolArray  fitArray;
                func(requestWidthDots, requestHeightDots, requestUnits, indexArray, fitArray);

                if (bestFitFormIndexP)
                    memcpy ((void*)bestFitFormIndexP, (const void*)indexArray.data(), indexArray.size());

                if (selectedFormFitsP)
                    memcpy ((void*)selectedFormFitsP, (const void*)fitArray.data(), fitArray.size());;
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
    virtual PlotError GetEngineError() const override
        {
        PYBIND11_OVERRIDE_PURE(PlotError, IPlotter, GetEngineError,);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetEngineError(PlotError value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetEngineError, value);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetEngineLineWidth(int weight) const override
        {
        PYBIND11_OVERRIDE_PURE(int, IPlotter, GetEngineLineWidth, weight);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetEngineLineWidth(int pen, int weight) const override
        {
        PYBIND11_OVERRIDE_PURE(int, IPlotter, GetEngineLineWidth, pen, weight);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetEngineLineWidth(int weight, int lineWidthDots) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotter, SetEngineLineWidth, weight, lineWidthDots);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotLineStyleDefCR GetEngineLineStyle(int styleIndex) const override
        {
        PYBIND11_OVERRIDE_PURE(PlotLineStyleDefCR, IPlotter, GetEngineLineStyle, styleIndex);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbaColorDef GetEngineColorFromPen(int pen) const override
        {
        PYBIND11_OVERRIDE_PURE(RgbaColorDef, IPlotter, GetEngineColorFromPen, pen);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbaColorDef GetEngineColorFromIndex(int colorIndex) const override
        {
        PYBIND11_OVERRIDE_PURE(RgbaColorDef, IPlotter, GetEngineColorFromIndex, colorIndex);
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual RgbaColorDef GetEngineBackgroundColor() const override
        {
        PYBIND11_OVERRIDE_PURE(RgbaColorDef, IPlotter, GetEngineBackgroundColor, );
        }
};


//=======================================================================================
// Trampoline class for IPlotterForm.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotterForm : IPlotterForm
{
public:
    using IPlotterForm::IPlotterForm;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP Clone() const override
        {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormP, IPlotterForm, Clone, nullptr,);
        }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetName(WCharCP value) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetName, );
        }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, GetName, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetActualName(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetActualName, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void GetActualName(WStringR value) const override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, GetActualName, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetUnits(PlotUnits value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetUnits, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotUnits GetUnits() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotUnits, IPlotterForm, GetUnits, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetOrientation(PlotOrientation value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetOrientation, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotOrientation GetOrientation() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotOrientation, IPlotterForm, GetOrientation, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsFormSizeIdentical(IPlotterFormCP plotterForm, bool comparePrintableArea) const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotterForm, IsFormSizeIdentical, plotterForm, comparePrintableArea);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetTotalSize(DPoint2d value, PlotUnits units) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetTotalSize, value, units);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2d GetTotalSize(PlotUnits units) const override
    {
        PYBIND11_OVERRIDE_PURE(DPoint2d, IPlotterForm, GetTotalSize, units);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPrintableSize(DPoint2d value, PlotUnits units) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetPrintableSize, value, units);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2d GetPrintableSize(PlotUnits units) const override
    {
        PYBIND11_OVERRIDE_PURE(DPoint2d, IPlotterForm, GetPrintableSize, units);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPrintableOffset(DPoint2d value, PlotUnits units) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetPrintableOffset, value, units);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DPoint2d GetPrintableOffset(PlotUnits units) const override
    {
        PYBIND11_OVERRIDE_PURE(DPoint2d, IPlotterForm, GetPrintableOffset, units);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetPaperSizeNumber(int value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetPaperSizeNumber, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetPaperSizeNumber() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotterForm, GetPaperSizeNumber, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetFormIndex(int value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetFormIndex, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetFormIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotterForm, GetFormIndex, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetDefaultFormScale(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetDefaultFormScale, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetDefaultFormScale() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotterForm, GetDefaultFormScale, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineWeightScale(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetLineWeightScale, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetLineWeightScale() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotterForm, GetLineWeightScale, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetLineStyleScale(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetLineStyleScale, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetLineStyleScale() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotterForm, GetLineStyleScale, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetAutoRotate(PlotRotateDir value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterForm, SetAutoRotate, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual PlotRotateDir GetAutoRotate() const override
    {
        PYBIND11_OVERRIDE_PURE(PlotRotateDir, IPlotterForm, GetAutoRotate, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool IsNoneForm() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotterForm, IsNoneForm, );
    }
};

//=======================================================================================
// Trampoline class for IPlotterFormList.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotterFormList : IPlotterFormList
{
public:
    using IPlotterFormList::IPlotterFormList;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumForms() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotterFormList, GetNumForms, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetCurrentForm(int formListIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterFormList, SetCurrentForm, formListIndex);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP GetCurrentForm() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormP, IPlotterFormList, GetCurrentForm, nullptr,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetCurrentFormIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotterFormList, GetCurrentFormIndex, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetDefaultFormIndex() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotterFormList, GetDefaultFormIndex, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP GetFormByIndex(int formListIndex) const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormP, IPlotterFormList, GetFormByIndex, nullptr, formListIndex);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP GetFormByName(WCharCP searchName, int* formListIndexP = 0) const override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetFormByName");
            IPlotterFormP retVal = nullptr;
            if (func)
                {
                auto obj = func(searchName);
                auto tuple = obj.cast<py::tuple>();

                if (py::isinstance<IPlotterForm>(tuple[0]))
                    retVal = tuple[0].cast<IPlotterFormP>(); //WIP: need a test to check how obj.cast works on pointer 

                if(!formListIndexP && py::isinstance<py::int_>(tuple[1]))
                    *formListIndexP = tuple[1].cast<int32_t>();
                }

            return retVal;
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }

        return nullptr;
        }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP GetFormByPaperSizeNumber(int searchPaperSizeNumber, int* formListIndexP = 0) const override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "GetFormByPaperSizeNumber");
            IPlotterFormP retVal = nullptr;
            if (func)
                {
                auto obj = func(searchPaperSizeNumber);
                auto tuple = obj.cast<py::tuple>();

                if (py::isinstance<IPlotterForm>(tuple[0]))
                    retVal = tuple[0].cast<IPlotterFormP>(); //WIP: need a test to check how obj.cast works on pointer 

                if (!formListIndexP && py::isinstance<py::int_>(tuple[1]))
                    *formListIndexP = tuple[1].cast<int32_t>();
                }

            return retVal;
            }
        catch (std::exception& ex)
            {
            ScriptEngineManager::Get().InjectException(ex);
            }

        return nullptr;
        }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterFormP AppendForm() override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotterFormP, IPlotterFormList, AppendForm, nullptr,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RemoveForm(int formListIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterFormList, RemoveForm, formListIndex );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RemoveAllForms() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotterFormList, RemoveAllForms, );
    }
};

//=======================================================================================
// Trampoline class for IPlotFontMap.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotFontMap : IPlotFontMap
{
public:
    using IPlotFontMap::IPlotFontMap;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetMsFontType(DgnPlatform::DgnFontType value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMap, SetMsFontType,value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual DgnPlatform::DgnFontType GetMsFontType() const override
    {
        PYBIND11_OVERRIDE_PURE(DgnPlatform::DgnFontType, IPlotFontMap, GetMsFontType,);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetMsFontNumber(int value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMap, SetMsFontNumber, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetMsFontNumber() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotFontMap, GetMsFontNumber, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetMsFontName(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMap, SetMsFontName, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual WCharCP GetMsFontName() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IPlotFontMap, GetMsFontName, nullptr, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetHwFontName(WCharCP value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMap, SetHwFontName, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual WCharCP GetHwFontName() const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(WCharCP, IPlotFontMap, GetHwFontName, nullptr, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetHwKern(int value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMap, SetHwKern, value );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetHwKern() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotFontMap, GetHwKern, );
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetHwSizeRatio(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMap, SetHwSizeRatio, value);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetHwSizeRatio() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotFontMap, GetHwSizeRatio, );
    }
};

//=======================================================================================
// Trampoline class for IPlotFontMapList.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotFontMapList : IPlotFontMapList
{
public:
    using IPlotFontMapList::IPlotFontMapList;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual int GetNumFontMaps() const override
    {
        PYBIND11_OVERRIDE_PURE(int, IPlotFontMapList, GetNumFontMaps, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotFontMapP GetDgnFontMapP(int fontMapListIndex) const override
    {
        PYBIND11_OVERRIDE_PURE_EXR(IPlotFontMapP, IPlotFontMapList, GetDgnFontMapP, nullptr, fontMapListIndex);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotFontMapP FindFontMap(DgnPlatform::DgnFontType msFontType, WCharCP msFontName) const override
    {
        PYBIND11_OVERRIDE_PURE_NAME_EXR(IPlotFontMapP, IPlotFontMapList, "FindFontMapByName", FindFontMap, nullptr, msFontType, msFontName);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotFontMapP FindFontMap(int msFontNumber) const override
    {
        PYBIND11_OVERRIDE_PURE_NAME_EXR(IPlotFontMapP, IPlotFontMapList, "FindFontMapByNum", FindFontMap, nullptr, msFontNumber);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotFontMapP AddFontMap(int* fontMapListIndexP = 0)  override
    {
        try
        {
            py::gil_scoped_acquire gil;
            py::function func = py::get_override(this, "AddFontMap");
            IPlotFontMapP retVal = nullptr;
            if (func)
            {
                int index = fontMapListIndexP ? *fontMapListIndexP : -1;

                auto obj = func(index);
                if (py::isinstance<IPlotFontMap>(obj))
                    retVal = obj.cast<IPlotFontMapP>(); //WIP: need a test to check how obj.cast works on pointer 
            }

            return retVal;
        }
        catch (std::exception& ex)
        {
            ScriptEngineManager::Get().InjectException(ex);
        }

        return nullptr;
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RemoveFontMap(int fontMapListIndex) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMapList, RemoveFontMap, fontMapListIndex);
    }
    
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RemoveAllFontMaps() override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotFontMapList, RemoveAllFontMaps,);
    }
};

//=======================================================================================
// Trampoline class for IPlotRasterizedParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotRasterizedParam : IPlotRasterizedParam
{
public:
    using IPlotRasterizedParam::IPlotRasterizedParam;


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetQuality(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotRasterizedParam, SetQuality, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetQuality() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotRasterizedParam, GetQuality, );
    }
};

//=======================================================================================
// Trampoline class for IPlotOleParam.
// @bsiclass                                                                   06/24
//=======================================================================================
struct IPyPlotOleParam : IPlotOleParam
{
public:
    using IPlotOleParam::IPlotOleParam;


    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetQuality(double value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotOleParam, SetQuality, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual double GetQuality() const override
    {
        PYBIND11_OVERRIDE_PURE(double, IPlotOleParam, GetQuality, );
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void SetRasterize(bool value) override
    {
        PYBIND11_OVERRIDE_PURE_EX(void, IPlotOleParam, SetRasterize, value);
    }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       6/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetRasterize() const override
    {
        PYBIND11_OVERRIDE_PURE(bool, IPlotOleParam, GetRasterize, );
    }
};

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       6/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IPlotter(py::module_& m)
   {
    //===================================================================================
    // enum class PlotTagBool
    py::enum_<PlotTagBool>(m, "PlotTagBool")
      .value("eIsSystemPrinter", PlotTagBool::IsSystemPrinter)
      .value("eDrawBorder", PlotTagBool::DrawBorder)
      .value("ePrintPoints", PlotTagBool::PrintPoints)
      .value("eAutoIncExt", PlotTagBool::AutoIncExt)
      .value("eAutoOverwritePlotFile", PlotTagBool::AutoOverwritePlotFile)
      .value("eAutoOpenPlotFile", PlotTagBool::AutoOpenPlotFile)
      .value("eAutoCenter", PlotTagBool::AutoCenter)
      .value("ePrintFence", PlotTagBool::PrintFence)
      .value("eUseDefaultScale", PlotTagBool::UseDefaultScale)
      .value("ePrintBorderTime", PlotTagBool::PrintBorderTime)
      .value("ePrintBorderFile", PlotTagBool::PrintBorderFile)
      .value("ePrintBorderModel", PlotTagBool::PrintBorderModel)
      .value("ePrintBorderOutline", PlotTagBool::PrintBorderOutline)
      .value("eBorderOutlineDisabled", PlotTagBool::BorderOutlineDisabled)
      .value("eSysprinterFullSheet", PlotTagBool::SysprinterFullSheet)
      .value("eNoPlotFile", PlotTagBool::NoPlotFile)
      .value("eRasterized", PlotTagBool::Rasterized)
      .value("eIsPrintSetCapable", PlotTagBool::IsPrintSetCapable)
      .value("eHonorRasterTransparency", PlotTagBool::HonorRasterTransparency)
      .value("eUseModelForDefaultPlotFileName", PlotTagBool::UseModelForDefaultPlotFileName)
      .value("eAcceptsNonTransparentBitmaps", PlotTagBool::AcceptsNonTransparentBitmaps)
      .value("ePostPlotBorderText", PlotTagBool::PostPlotBorderText)
      .value("eEnableOrientation", PlotTagBool::EnableOrientation)
      .value("eRasterizeUsingBands", PlotTagBool::RasterizeUsingBands)
      .value("eUseSimpleGdi", PlotTagBool::UseSimpleGdi)
      .value("eOptimizeRasterColorDepth", PlotTagBool::OptimizeRasterColorDepth)
      .value("eRgbRasterOnly", PlotTagBool::RgbRasterOnly)
      .value("eRgbaRasterOnly", PlotTagBool::RgbaRasterOnly)
      .value("eBitmapRasterOnly", PlotTagBool::BitmapRasterOnly)
      .value("eStrokeRaster", PlotTagBool::StrokeRaster)
      .value("eNoPlotOrigin", PlotTagBool::NoPlotOrigin)
      .value("eSupportsPlotTo3d", PlotTagBool::SupportsPlotTo3d)
      .value("eIsPlotTo3d", PlotTagBool::IsPlotTo3d)
      .value("eStrokeBezierCurves", PlotTagBool::StrokeBezierCurves)
      .value("eExportRenditionId", PlotTagBool::ExportRenditionId)
      .value("eExportRenditionData", PlotTagBool::ExportRenditionData)
      .value("eDisablePathSupport", PlotTagBool::DisablePathSupport)
      .value("eCropRasterTransparency", PlotTagBool::CropRasterTransparency)
      .value("eEnableDriverClipping", PlotTagBool::EnableDriverClipping)
      .value("eSupportsCopies", PlotTagBool::SupportsCopies)
      .value("eMergeExportedRaster", PlotTagBool::MergeExportedRaster)
      .value("eEnablePssPassThru", PlotTagBool::EnablePssPassThru)
      .value("eEnableOutputWidth", PlotTagBool::EnableOutputWidth)
      .value("eAllowZeroPenWidth", PlotTagBool::AllowZeroPenWidth)
      .value("eUseScreenedVectors", PlotTagBool::UseScreenedVectors)
      .value("eSupportsExtLineStyles", PlotTagBool::SupportsExtLineStyles)
      .value("eSupportsPlotMetadata", PlotTagBool::SupportsPlotMetadata)
      .value("eSupportsOutputOle", PlotTagBool::SupportsOutputOle)
      .value("eSupportsOutputPdf", PlotTagBool::SupportsOutputPdf)
      .value("eEnableCurrentForm", PlotTagBool::EnableCurrentForm)
      .value("eUseLocalTempFileForPseudoOutputFile", PlotTagBool::UseLocalTempFileForPseudoOutputFile)
      .value("eAllowBinaryRaster", PlotTagBool::AllowBinaryRaster)
      .value("eSupportsNoneForm", PlotTagBool::SupportsNoneForm)
      .export_values();
              
    //===================================================================================
    // enum class PlotTagInt
    py::enum_<PlotTagInt>(m, "PlotTagInt")
      .value("eNumPens", PlotTagInt::NumPens)
      .value("eNumForms", PlotTagInt::NumForms)
      .value("eHpglQuality", PlotTagInt::HpglQuality)
      .value("eDefaultNumCopies", PlotTagInt::DefaultNumCopies)
      .value("eMoveMode", PlotTagInt::MoveMode)
      .value("ePlotDriver", PlotTagInt::PlotDriver)
      .value("ePlotterModel", PlotTagInt::PlotterModel)
      .value("eDefaultLineCap", PlotTagInt::DefaultLineCap)
      .value("eDefaultLineJoin", PlotTagInt::DefaultLineJoin)
      .value("eStartPlotCmd", PlotTagInt::StartPlotCmd)
      .value("eEndPlotCmd", PlotTagInt::EndPlotCmd)
      .value("eBorderPen", PlotTagInt::BorderPen)
      .value("eFencePen", PlotTagInt::FencePen)
      .value("eDisplayUnits", PlotTagInt::DisplayUnits)
      .value("ePlotViewIndex", PlotTagInt::PlotViewIndex)
      .value("eRollOrientation", PlotTagInt::RollOrientation)
      .value("eRequiredOrientation", PlotTagInt::RequiredOrientation)
      .value("ePlotFileHandle", PlotTagInt::PlotFileHandle)
      .value("eDesiredColorMode", PlotTagInt::DesiredColorMode)
      .value("eHighestColorMode", PlotTagInt::HighestColorMode)
      .value("eLevelOfDetailMode", PlotTagInt::LevelOfDetailMode)
      .value("eSysprinterOrientation", PlotTagInt::SysprinterOrientation)
      .value("eSysprinterNumCopies", PlotTagInt::SysprinterNumCopies)
      .value("eSysprinterMaxCopies", PlotTagInt::SysprinterMaxCopies)
      .value("eCurrentRenditionId", PlotTagInt::CurrentRenditionId)
      .value("eRenditionDataSize", PlotTagInt::RenditionDataSize)
      .value("eVisible", PlotTagInt::Visible)
      .export_values();

    //===================================================================================
    // enum class PlotTagDbl
    py::enum_<PlotTagDbl>(m, "PlotTagDbl")
      .value("eCurveTolerance", PlotTagDbl::CurveTolerance)
      .value("eBorderTextHeightCM", PlotTagDbl::BorderTextHeightCM)
      .value("eBorderWidthCM", PlotTagDbl::BorderWidthCM)
      .value("eMiterLimit", PlotTagDbl::MiterLimit)
      .value("eDefaultScale", PlotTagDbl::DefaultScale)
      .value("eCurrentReferenceScale", PlotTagDbl::CurrentReferenceScale)
      .value("eMaxMiterAngleRads", PlotTagDbl::MaxMiterAngleRads)
      .value("ePlotRotationRads", PlotTagDbl::PlotRotationRads)
      .value("eMinimumLevelOfDetail", PlotTagDbl::MinimumLevelOfDetail)
      .export_values();
    
    //===================================================================================
    // enum class PlotTagStr
    py::enum_<PlotTagStr>(m, "PlotTagStr")
      .value("eBorderFontName", PlotTagStr::BorderFontName)
      .value("eDefaultOutputFile", PlotTagStr::DefaultOutputFile)
      .value("eDriverName", PlotTagStr::DriverName)
      .value("eSysprinterName", PlotTagStr::SysprinterName)
      .value("eSysprinterFormName", PlotTagStr::SysprinterFormName)
      .value("eSysprinterTrayName", PlotTagStr::SysprinterTrayName)
      .value("eDefaultExtension", PlotTagStr::DefaultExtension)
      .value("eBorderComment", PlotTagStr::BorderComment)
      .value("eDefaultPenTableFile", PlotTagStr::DefaultPenTableFile)
      .value("eDefaultDesignScriptFile", PlotTagStr::DefaultDesignScriptFile)
      .value("ePrintStyleName", PlotTagStr::PrintStyleName)
      .value("eConfigFileDisplayLabel", PlotTagStr::ConfigFileDisplayLabel)
      .value("eDriverDisplayName", PlotTagStr::DriverDisplayName)
      .export_values();
  
    //===================================================================================
    // enum class PlotTagFileSpec
    py::enum_<PlotTagFileSpec>(m, "PlotTagFileSpec")
      .value("ePrologFile", PlotTagFileSpec::PrologFile)
      .value("ePrefixFile", PlotTagFileSpec::PrefixFile)
      .value("eSuffixFile", PlotTagFileSpec::SuffixFile)
      .value("eRenderingAttributesFile", PlotTagFileSpec::RenderingAttributesFile)
      .export_values();
    
    //===================================================================================
    // enum class PlotTagDPoint2d
    py::enum_<PlotTagDPoint2d>(m, "PlotTagDPoint2d")
      .value("eDeviceResolution", PlotTagDPoint2d::DeviceResolution)
      .value("eApparentResolution", PlotTagDPoint2d::ApparentResolution)
      .value("ePlotOrigin", PlotTagDPoint2d::PlotOrigin)
      .value("ePlotSize", PlotTagDPoint2d::PlotSize)
      .value("ePlotScale", PlotTagDPoint2d::PlotScale)
      .value("eScaleAdjustmentFactor", PlotTagDPoint2d::ScaleAdjustmentFactor)
      .value("eBorderTextOffsetCM", PlotTagDPoint2d::BorderTextOffsetCM)
      .value("eP1", PlotTagDPoint2d::P1)
      .value("eP2", PlotTagDPoint2d::P2)
      .value("eEffectivePlotScale", PlotTagDPoint2d::EffectivePlotScale)
      .export_values();

   //===================================================================================
   // enum class PlotTagDPoint3d   
    py::enum_<PlotTagDPoint3d>(m, "PlotTagDPoint3d")
      .value("eViewOriginUors", PlotTagDPoint3d::ViewOriginUors)
      .value("eViewDeltaUors", PlotTagDPoint3d::ViewDeltaUors)
      .export_values();

    //===================================================================================
    // enum class PlotTagTransform
    py::enum_<PlotTagTransform>(m, "PlotTagTransform")
      .value("eLocalToWorld", PlotTagTransform::LocalToWorld)
      .value("eLocalToPlot", PlotTagTransform::LocalToPlot)
      .value("eWorldToPlot", PlotTagTransform::WorldToPlot)
      .value("eWorldToView", PlotTagTransform::WorldToView)
      .value("eViewToPlot", PlotTagTransform::ViewToPlot)
      .export_values();

    //===================================================================================
    // enum class PlotTagPtr
    py::enum_<PlotTagPtr>(m, "PlotTagPtr")
      .value("eDriverDllHmodule", PlotTagPtr::DriverDllHmodule)
      .value("eCurrentRenditionData", PlotTagPtr::CurrentRenditionData)
      .export_values();

    //===================================================================================
    // enum class PlotTagTriState
    py::enum_<PlotTagTriState>(m, "PlotTagTriState")
      .value("eReplTransMaskWithTransColor", PlotTagTriState::ReplTransMaskWithTransColor)
      .export_values();
  
    //===================================================================================
    // enum class PlotTagIsDefinedInPltcfg
    py::enum_<PlotTagIsDefinedInPltcfg>(m, "PlotTagIsDefinedInPltcfg")
      .value("eDefaultPrinter", PlotTagIsDefinedInPltcfg::DefaultPrinter)
      .value("eDefaultForm", PlotTagIsDefinedInPltcfg::DefaultForm)
      .value("eDefaultTray", PlotTagIsDefinedInPltcfg::DefaultTray)
      .export_values();

   //===================================================================================
   // enum class PlotDriver   
    py::enum_<PlotDriver>(m, "PlotDriver")
      .value("eUnknown", PlotDriver::Unknown)
      .value("eCALS", PlotDriver::CALS)
      .value("eDPR", PlotDriver::DPR)
      .value("eHPGL2", PlotDriver::HPGL2)
      .value("eHPGLRTL", PlotDriver::HPGLRTL)
      .value("eLORIP", PlotDriver::LORIP)
      .value("ePDF", PlotDriver::PDF)
      .value("ePSCRIPT", PlotDriver::PSCRIPT)
      .value("eSYSPRINTER", PlotDriver::SYSPRINTER)
      .value("eTIFF", PlotDriver::TIFF)
      .export_values();
   
    //===================================================================================
    // enum class PlotFilterLodMode  
    py::enum_<PlotFilterLodMode>(m, "PlotFilterLodMode")
      .value("eOff", PlotFilterLodMode::Off)
      .value("eShowRange", PlotFilterLodMode::ShowRange)
      .value("eShowNothing", PlotFilterLodMode::ShowNothing)
      .export_values();

    //===================================================================================
    // enum class PlotMoveMode  
    py::enum_<PlotMoveMode>(m, "PlotMoveMode")
      .value("eAbsolute", PlotMoveMode::Absolute)
      .value("eRelative", PlotMoveMode::Relative)
      .export_values();
 
    //===================================================================================
    // enum class PlotReqOrientation  
    py::enum_<PlotReqOrientation>(m, "PlotReqOrientation")
      .value("eUndefined", PlotReqOrientation::Undefined)
      .value("ePortrait", PlotReqOrientation::Portrait)
      .value("eLandscape", PlotReqOrientation::Landscape)
      .export_values();
    

    //===================================================================================
    // enum class PlotStartStopCmd  
    py::enum_<PlotStartStopCmd>(m, "PlotStartStopCmd")
      .value("eNone", PlotStartStopCmd::None)
      .value("ePause", PlotStartStopCmd::Pause)
      .value("eEject", PlotStartStopCmd::Eject)
      .value("eReplot", PlotStartStopCmd::Replot)
      .value("eBeep", PlotStartStopCmd::Beep)
      .export_values();

    //===================================================================================
    // enum class PlotterModel  
    py::enum_<PlotterModel>(m, "PlotterModel")
      .value("eUndefined", PlotterModel::Undefined)
      .value("eHPLJET3", PlotterModel::HPLJET3)
      .value("eSysprinter", PlotterModel::Sysprinter)
      .value("eSysprinterMetafile", PlotterModel::SysprinterMetafile)
      .export_values();

    //===================================================================================
    // enum class PlotLineCap  
    py::enum_<PlotLineCap>(m, "PlotLineCap")
      .value("eUndefined", PlotLineCap::Undefined)
      .value("eFlat", PlotLineCap::Flat)
      .value("eSquare", PlotLineCap::Square)
      .value("eTriangle", PlotLineCap::Triangle)
      .value("eRound", PlotLineCap::Round)
      .export_values();

    //===================================================================================
    // enum class PlotLineJoin  
    py::enum_<PlotLineJoin>(m, "PlotLineJoin")
      .value("eUndefined", PlotLineJoin::Undefined)
      .value("eMiter", PlotLineJoin::Miter)
      .value("eMiterBevel", PlotLineJoin::MiterBevel)
      .value("eTriangle", PlotLineJoin::Triangle)
      .value("eRound", PlotLineJoin::Round)
      .value("eBevel", PlotLineJoin::Bevel)
      .value("eButt", PlotLineJoin::Butt)
      .export_values();

    //===================================================================================
    // enum class PlotRotateDir   
    py::enum_<PlotRotateDir>(m, "PlotRotateDir")
      .value("eCCW", PlotRotateDir::CCW)
      .value("eCW", PlotRotateDir::CW)
      .value("eNone", PlotRotateDir::None)
      .value("eRot180", PlotRotateDir::Rot180)
      .export_values();

    //===================================================================================
    // enum class DriverOutputMode  
    py::enum_<DriverOutputMode>(m, "DriverOutputMode")
      .value("eUndefined", DriverOutputMode::Undefined)
      .value("eForceRasterized", DriverOutputMode::ForceRasterized)
      .value("ePreferRasterized", DriverOutputMode::PreferRasterized)
      .value("eForceNonrasterized", DriverOutputMode::ForceNonrasterized)
      .value("ePreferNonrasterized", DriverOutputMode::PreferNonrasterized)
      .export_values();

    //===================================================================================
    // enum class DriverCoordSysOrigin 
    py::enum_<DriverCoordSysOrigin>(m, "DriverCoordSysOrigin")
      .value("eLowerLeft", DriverCoordSysOrigin::LowerLeft)
      .value("eUpperLeft", DriverCoordSysOrigin::UpperLeft)
      .export_values();

    //===================================================================================
    // enum class PlotTriState 
    py::enum_<PlotTriState>(m, "PlotTriState")
      .value("eFalse", PlotTriState::False)
      .value("eTrue", PlotTriState::True)
      .value("eUndefined", PlotTriState::Undefined)
      .export_values();

    //===================================================================================
    // enum class PlotHwTextMode 
    py::enum_<PlotHwTextMode>(m, "PlotHwTextMode")
      .value("eNone", PlotHwTextMode::None)
      .value("eNormal", PlotHwTextMode::Normal)
      .value("eNormalAllFonts", PlotHwTextMode::NormalAllFonts)
      .value("eAlways", PlotHwTextMode::Always)
      .value("ePDFEditable", PlotHwTextMode::PDFEditable)
      .export_values();

    //===================================================================================
    //class PlotLineStyleDef
    py::class_<PlotLineStyleDef> c0(m, "PlotLineStyleDef");
    c0.def_readwrite("units", &PlotLineStyleDef::units);
    c0.def_readwrite("numOnOff", &PlotLineStyleDef::numOnOff);

    c0.def_property("noHardware",
        [](PlotLineStyleDef const& self) {return self.noHardware; },
        [](PlotLineStyleDef& self, unsigned int value) {self.noHardware = value; });

    c0.def_property("reserved",
        [](PlotLineStyleDef const& self) {return self.reserved; },
        [](PlotLineStyleDef& self, unsigned int value) {self.reserved = value; });

    c0.def_property("onOff",
        [](PlotLineStyleDef const& self)
            {
            py::list ptArray;
            for (size_t i = 0; i < MAX_DOWNUP_PER_LINESTYLE; i++)
                ptArray.append(py::cast(self.onOff[i], py::return_value_policy::reference));
            return ptArray;
            },
        [](PlotLineStyleDef& self, DoubleArray const& dblArray)
            {
            size_t validNumber = dblArray.size();
            validNumber = validNumber > MAX_DOWNUP_PER_LINESTYLE ? MAX_DOWNUP_PER_LINESTYLE : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.onOff[i] = dblArray[i];
            });
    
    //===================================================================================
    //class PlotPenSetup
    py::class_<PlotPenSetup> c1(m, "PlotPenSetup");
    c1.def_property("isColorValid",
        [](PlotPenSetup const& self) {return self.isColorValid; },
        [](PlotPenSetup& self, unsigned int value) {self.isColorValid = value; });
    c1.def_property("isGrayscale",
        [](PlotPenSetup const& self) {return self.isGrayscale; },
        [](PlotPenSetup& self, unsigned int value) {self.isGrayscale = value; });
    c1.def_property("isWidthValid",
        [](PlotPenSetup const& self) {return self.isWidthValid; },
        [](PlotPenSetup& self, unsigned int value) {self.isWidthValid = value; });
    c1.def_property("reserved",
        [](PlotPenSetup const& self) {return self.reserved; },
        [](PlotPenSetup& self, unsigned int value) {self.reserved = value; });

    c1.def_readwrite("color", &PlotPenSetup::color);
    c1.def_readwrite("widthMM", &PlotPenSetup::widthMM);
    c1.def_readwrite("screen", &PlotPenSetup::screen);
    
    //===================================================================================
    //class PlotRasterOptions
    py::class_<PlotRasterOptions> c2(m, "PlotRasterOptions");
    
    c1.def_property("plotRasterImages",
        [](PlotRasterOptions const& self) {return self.plotRasterImages; },
        [](PlotRasterOptions& self, unsigned int value) {self.plotRasterImages = value; });

    c1.def_property("plotGrayscale",
        [](PlotRasterOptions const& self) {return self.plotGrayscale; },
        [](PlotRasterOptions& self, unsigned int value) {self.plotGrayscale = value; });

    c1.def_property("plotMonochromeAsIs",
        [](PlotRasterOptions const& self) {return self.plotMonochromeAsIs; },
        [](PlotRasterOptions& self, unsigned int value) {self.plotMonochromeAsIs = value; });

    c1.def_property("reserved",
        [](PlotRasterOptions const& self) {return self.reserved; },
        [](PlotRasterOptions& self, unsigned int value) {self.reserved = value; });

    c2.def_readwrite("pixelsPerInch", &PlotRasterOptions::pixelsPerInch);
    c2.def_readwrite("quality", &PlotRasterOptions::quality);
    c2.def_readwrite("contrast", &PlotRasterOptions::contrast);
    c2.def_readwrite("brightness", &PlotRasterOptions::brightness);

    //===================================================================================
    //class PlotRasterCompr
    py::class_<PlotRasterCompr> c3(m, "PlotRasterCompr");
    
    c3.def_readwrite("format", &PlotRasterCompr::format);

    c3.def_property("methods",
        [](PlotRasterCompr const& self)
        {
            py::list ptArray;
            for (size_t i = 0; i < 20; i++)
                ptArray.append(py::cast(self.methods[i], py::return_value_policy::reference));
            return ptArray;
        },
        [](PlotRasterCompr& self, Int64Array const& lgnArray)
        {
            size_t validNumber = lgnArray.size();
            validNumber = validNumber > 20 ? 20 : validNumber;

            for (size_t i = 0; i < validNumber; i++)
                self.methods[i] = (long)lgnArray[i];
        });


    //===================================================================================
    //class IPlotterForm
    py::class_<IPlotterForm, IPyPlotterForm> c4(m, "IPlotterForm");
    c4.def(py::init<>());

    c4.def("Clone", &IPlotterForm::Clone, DOC(Bentley, MstnPlatform, Print, IPlotterForm, Clone));
    c4.def("SetName", &IPlotterForm::SetName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetName));
    c4.def("GetName", &IPlotterForm::GetName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetName));

    c4.def("SetActualName", &IPlotterForm::SetActualName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetActualName));
    c4.def("GetActualName", &IPlotterForm::GetActualName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetActualName));

    c4.def_property("Units", &IPlotterForm::GetUnits, &IPlotterForm::SetUnits);
    c4.def("SetUnits", &IPlotterForm::SetUnits, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetUnits));
    c4.def("GetUnits", &IPlotterForm::GetUnits, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetUnits));

    c4.def_property("Orientation", &IPlotterForm::GetOrientation, &IPlotterForm::SetOrientation);
    c4.def("SetOrientation", &IPlotterForm::SetOrientation, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetOrientation));
    c4.def("GetOrientation", &IPlotterForm::GetOrientation, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetOrientation));

    c4.def("IsFormSizeIdentical", &IPlotterForm::IsFormSizeIdentical, "plotterForm"_a, "comparePrintableArea"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, IsFormSizeIdentical));
    c4.def("SetTotalSize", &IPlotterForm::SetTotalSize, "value"_a, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetTotalSize));
    c4.def("GetTotalSize", &IPlotterForm::GetTotalSize, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetTotalSize));

    c4.def("SetPrintableSize", &IPlotterForm::SetPrintableSize, "value"_a, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetPrintableSize));
    c4.def("GetPrintableSize", &IPlotterForm::GetPrintableSize, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetPrintableSize));

    c4.def("SetPrintableOffset", &IPlotterForm::SetPrintableOffset, "value"_a, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetPrintableOffset));
    c4.def("GetPrintableOffset", &IPlotterForm::GetPrintableOffset, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetPrintableOffset));

    c4.def_property("PaperSizeNumber", &IPlotterForm::GetPaperSizeNumber, &IPlotterForm::SetPaperSizeNumber);
    c4.def("SetPaperSizeNumber", &IPlotterForm::SetPaperSizeNumber, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetPaperSizeNumber));
    c4.def("GetPaperSizeNumber", &IPlotterForm::GetPaperSizeNumber, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetPaperSizeNumber));

    c4.def_property("FormIndex", &IPlotterForm::GetFormIndex, &IPlotterForm::SetFormIndex);
    c4.def("SetFormIndex", &IPlotterForm::SetFormIndex, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetFormIndex));
    c4.def("GetFormIndex", &IPlotterForm::GetFormIndex, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetFormIndex));

    c4.def_property("DefaultFormScale", &IPlotterForm::GetDefaultFormScale, &IPlotterForm::SetDefaultFormScale);
    c4.def("SetDefaultFormScale", &IPlotterForm::SetDefaultFormScale, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetDefaultFormScale));
    c4.def("GetDefaultFormScale", &IPlotterForm::GetDefaultFormScale, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetDefaultFormScale));

    c4.def_property("LineWeightScale", &IPlotterForm::GetLineWeightScale, &IPlotterForm::SetLineWeightScale);
    c4.def("SetLineWeightScale", &IPlotterForm::SetLineWeightScale, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetLineWeightScale));
    c4.def("GetLineWeightScale", &IPlotterForm::GetLineWeightScale, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetLineWeightScale));

    c4.def_property("LineStyleScale", &IPlotterForm::GetLineStyleScale, &IPlotterForm::SetLineStyleScale);
    c4.def("SetLineStyleScale", &IPlotterForm::SetLineStyleScale, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetLineStyleScale));
    c4.def("GetLineStyleScale", &IPlotterForm::GetLineStyleScale, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetLineStyleScale));

    c4.def_property("AutoRotate", &IPlotterForm::SetAutoRotate, &IPlotterForm::SetAutoRotate);
    c4.def("SetAutoRotate", &IPlotterForm::SetAutoRotate, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotterForm, SetAutoRotate));
    c4.def("GetAutoRotate", &IPlotterForm::GetAutoRotate, DOC(Bentley, MstnPlatform, Print, IPlotterForm, GetAutoRotate));
    c4.def("IsNoneForm", &IPlotterForm::IsNoneForm, DOC(Bentley, MstnPlatform, Print, IPlotterForm, IsNoneForm));

    //===================================================================================
    //class IPlotterFormList
    py::class_<IPlotterFormList, IPyPlotterFormList> c5(m, "IPlotterFormList");
    c5.def(py::init<>());

    c5.def("GetNumForms", &IPlotterFormList::GetNumForms, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetNumForms));

    c5.def_property("CurrentForm", &IPlotterFormList::GetCurrentForm, &IPlotterFormList::SetCurrentForm);
    c5.def("SetCurrentForm", &IPlotterFormList::SetCurrentForm, "formListIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, SetCurrentForm));
    c5.def("GetCurrentForm", &IPlotterFormList::GetCurrentForm, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetCurrentForm));

    c5.def("GetCurrentFormIndex", &IPlotterFormList::GetCurrentFormIndex, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetCurrentFormIndex));
    c5.def("GetDefaultFormIndex", &IPlotterFormList::GetDefaultFormIndex, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetDefaultFormIndex));
    c5.def("GetFormByIndex", &IPlotterFormList::GetFormByIndex, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetFormByIndex));
    c5.def("GetFormByName", [](IPlotterFormList const& self, WCharCP searchName)->py::tuple
        {
        py::tuple outVal;
        outVal = py::cast(std::make_tuple((IPlotterFormP)nullptr, -1));
        return outVal;
        }, "searchName"_a, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetFormByName));

    c5.def("GetFormByPaperSizeNumber", [](IPlotterFormList const& self, int searchPaperSizeNumber)->py::tuple
        {
        py::tuple outVal;
        outVal = py::cast(std::make_tuple((IPlotterFormP)nullptr, -1));
        return outVal;
        }, "searchPaperSizeNumber"_a, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, GetFormByPaperSizeNumber));


    c5.def("AppendForm", &IPlotterFormList::AppendForm, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, AppendForm));
    c5.def("RemoveForm", &IPlotterFormList::RemoveForm, "formListIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, RemoveForm));
    c5.def("RemoveAllForms", &IPlotterFormList::RemoveAllForms, DOC(Bentley, MstnPlatform, Print, IPlotterFormList, RemoveAllForms));

    //===================================================================================
    //class IPlotFontMap
    py::class_<IPlotFontMap, IPyPlotFontMap> c6(m, "IPlotFontMap");
    c6.def(py::init<>());

    c6.def_property("MsFontType", &IPlotFontMap::GetMsFontType, &IPlotFontMap::SetMsFontType);
    c6.def("SetMsFontType", &IPlotFontMap::SetMsFontType, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, SetMsFontType));
    c6.def("GetMsFontType", &IPlotFontMap::GetMsFontType, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, GetMsFontType));


    c6.def_property("MsFontNumber", &IPlotFontMap::GetMsFontNumber, &IPlotFontMap::SetMsFontNumber);
    c6.def("SetMsFontNumber", &IPlotFontMap::SetMsFontNumber,"value");
    c6.def("GetMsFontNumber", &IPlotFontMap::GetMsFontNumber, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, GetMsFontNumber));

    c6.def_property("MsFontName", &IPlotFontMap::GetMsFontName, &IPlotFontMap::SetMsFontName);
    c6.def("SetMsFontName", &IPlotFontMap::SetMsFontName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, SetMsFontName));
    c6.def("GetMsFontName", &IPlotFontMap::GetMsFontName, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, GetMsFontName));

    c6.def_property("HwFontName", &IPlotFontMap::GetHwFontName, &IPlotFontMap::SetHwFontName);
    c6.def("SetHwFontName", &IPlotFontMap::SetHwFontName, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, SetHwFontName));
    c6.def("GetHwFontName", &IPlotFontMap::GetHwFontName, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, GetHwFontName));

    c6.def_property("HwKern", &IPlotFontMap::GetHwKern, &IPlotFontMap::SetHwKern);
    c6.def("SetHwKern", &IPlotFontMap::SetHwKern, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, SetHwKern));
    c6.def("GetHwKern", &IPlotFontMap::GetHwKern, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, GetHwKern));

    c6.def_property("HwSizeRatio", &IPlotFontMap::GetHwSizeRatio, &IPlotFontMap::SetHwSizeRatio);
    c6.def("SetHwSizeRatio", &IPlotFontMap::SetHwSizeRatio, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, SetHwSizeRatio));
    c6.def("GetHwSizeRatio", &IPlotFontMap::GetHwSizeRatio, DOC(Bentley, MstnPlatform, Print, IPlotFontMap, GetHwSizeRatio));

    //===================================================================================
    //class IPlotFontMapList
    py::class_<IPlotFontMapList, IPyPlotFontMapList> c7(m, "IPlotFontMapList");
    c7.def(py::init<>());

    c7.def("GetNumFontMaps", &IPlotFontMapList::GetNumFontMaps, DOC(Bentley, MstnPlatform, Print, IPlotFontMapList, GetNumFontMaps));
    c7.def("GetDgnFontMapP", &IPlotFontMapList::GetDgnFontMapP, "fontMapListIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMapList, GetDgnFontMapP));

    c7.def("FindFontMapByName", [](IPlotFontMapListCR self, DgnPlatform::DgnFontType msFontType, WCharCP msFontName){ return nullptr; }, "msFontType"_a, "msFontName"_a);
    c7.def("FindFontMapByNum", [](IPlotFontMapListCR self, int msFontNumber){ return nullptr; }, "msFontNumber"_a);
    c7.def("AddFontMap", [](IPlotFontMapList const& self, int fontMapListIndex) {return nullptr;}, "fontMapListIndex");

    c7.def("RemoveFontMap", &IPlotFontMapList::RemoveFontMap, "fontMapListIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotFontMapList, RemoveFontMap));
    c7.def("RemoveAllFontMaps", &IPlotFontMapList::RemoveAllFontMaps, DOC(Bentley, MstnPlatform, Print, IPlotFontMapList, RemoveAllFontMaps));


    //===================================================================================
    //class IPlotRasterizedParam
    py::class_<IPlotRasterizedParam, IPyPlotRasterizedParam> c8(m, "IPlotRasterizedParam");
    c8.def(py::init<>());

    c8.def_property("Quality", &IPlotRasterizedParam::GetQuality, &IPlotRasterizedParam::SetQuality);
    c8.def("SetQuality", &IPlotRasterizedParam::SetQuality, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotRasterizedParam, SetQuality));
    c8.def("GetQuality", &IPlotRasterizedParam::GetQuality, DOC(Bentley, MstnPlatform, Print, IPlotRasterizedParam, GetQuality));

    //===================================================================================
    //class IPlotOleParam
    py::class_<IPlotOleParam, IPyPlotOleParam> c9(m, "IPlotOleParam");
    c9.def(py::init<>());

    c9.def_property("Quality", &IPlotOleParam::GetQuality, &IPlotOleParam::SetQuality);
    c9.def("SetQuality", &IPlotOleParam::SetQuality, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotOleParam, SetQuality));
    c9.def("GetQuality", &IPlotOleParam::GetQuality, DOC(Bentley, MstnPlatform, Print, IPlotOleParam, GetQuality));

    c9.def_property("Rasterize", &IPlotOleParam::GetRasterize, &IPlotOleParam::SetRasterize);
    c9.def("SetRasterize", &IPlotOleParam::SetRasterize, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotOleParam, SetRasterize));
    c9.def("GetRasterize", &IPlotOleParam::GetRasterize, DOC(Bentley, MstnPlatform, Print, IPlotOleParam, GetRasterize));

    //===================================================================================
    //class IPlotter
    py::class_<IPlotter, IPyPlotter> c10(m, "IPlotter");
    c10.def(py::init<>());
    c10.def("Initialize", &IPlotter::Initialize, "pltcfgFspec"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, Initialize));

    c10.def("Copy", &IPlotter::Copy, DOC(Bentley, MstnPlatform, Print, IPlotter, Copy));
    c10.def("GetPltcfgFspec", &IPlotter::GetPltcfgFspec, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPltcfgFspec));

    c10.def("GetBool", &IPlotter::GetBool, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetBool));
    c10.def("SetBool", &IPlotter::SetBool, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetBool));

    c10.def("GetInt", &IPlotter::GetInt, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetInt));
    c10.def("SetInt", &IPlotter::SetInt, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetInt));

    c10.def("GetDouble", &IPlotter::GetDouble, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetDouble));
    c10.def("SetDouble", &IPlotter::SetDouble, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetDouble));

    c10.def("GetDPoint2d", &IPlotter::GetDPoint2d, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetDPoint2d));
    c10.def("SetDPoint2d", &IPlotter::SetDPoint2d, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetDPoint2d));

    c10.def("GetDPoint3d", &IPlotter::GetDPoint3d, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetDPoint3d));
    c10.def("SetDPoint3d", &IPlotter::SetDPoint3d, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetDPoint3d));

    c10.def("GetString", &IPlotter::GetString, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetString));
    c10.def("SetString", &IPlotter::SetString, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetString));

    c10.def("GetPointer", [](IPlotter& self, PlotTagPtr tag) {}, "tag"_a);
    c10.def("SetPointer", [](IPlotter& self, PlotTagPtr tag, py::capsule const& value) {}, "tag"_a, "value"_a);

    c10.def("GetTriState", &IPlotter::GetTriState, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetTriState));
    c10.def("SetTriState", &IPlotter::SetTriState, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetTriState));

    c10.def("GetFileSpecP", &IPlotter::GetFileSpecP, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetFileSpecP));
    c10.def("GetFileSpecCP", &IPlotter::GetFileSpecCP, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetFileSpecCP));

    c10.def("GetIsDefinedInPltcfg", &IPlotter::GetIsDefinedInPltcfg, "tag"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetIsDefinedInPltcfg));
    c10.def("SetIsDefinedInPltcfg", &IPlotter::SetIsDefinedInPltcfg, "tag"_a, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetIsDefinedInPltcfg));

    c10.def("GetPlotterUnits", &IPlotter::GetPlotterUnits, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPlotterUnits));
    c10.def("SetPlotterUnits", &IPlotter::SetPlotterUnits, "units"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetPlotterUnits));

    c10.def("ConvertUnits", py::overload_cast<double, PlotUnits, PlotUnits>(&IPlotter::ConvertUnits, py::const_), "value"_a, "fromUnits"_a, "toUnits"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, ConvertUnits));
    c10.def("ConvertUnits", py::overload_cast<double, PlotUnits, bool>(&IPlotter::ConvertUnits, py::const_), "value"_a, "units"_a, "convertStoredToUnits"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, ConvertUnits));

    c10.def("GetPenFromColorIndex", &IPlotter::GetPenFromColorIndex, "index"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPenFromColorIndex));
    c10.def("SetPenFromColorIndex", &IPlotter::SetPenFromColorIndex, "index"_a, "pen"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetPenFromColorIndex));

    c10.def("GetPenColor", &IPlotter::GetPenColor, "pen"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPenColor));
    c10.def("GetIsPenColorDefined", &IPlotter::GetIsPenColorDefined, "pen"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetIsPenColorDefined));

    c10.def("GetPenSetup", &IPlotter::GetPenSetup, "pen"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPenSetup));
    c10.def("SetPenSetup", &IPlotter::SetPenSetup, "pen"_a, "penSetup"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetPenSetup));

    c10.def("GetRasterCompression", &IPlotter::GetRasterCompression, DOC(Bentley, MstnPlatform, Print, IPlotter, GetRasterCompression));
    c10.def("GetLineWidth", &IPlotter::GetLineWidth, "weight"_a, "unitsP"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetLineWidth));
    c10.def("SetLineWidth", &IPlotter::SetLineWidth, "weight"_a, "units"_a, "width"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetLineWidth));

    c10.def("GetLineStyle", &IPlotter::GetLineStyle, "styleIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetLineStyle));
    c10.def("SetLineStyle", &IPlotter::SetLineStyle, "styleIndex"_a, "lineStyle"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetLineStyle));

    c10.def("GetNumExtLineStyles", &IPlotter::GetNumExtLineStyles, DOC(Bentley, MstnPlatform, Print, IPlotter, GetNumExtLineStyles));
    c10.def("GetExtLineStyles", &IPlotter::GetExtLineStyles, DOC(Bentley, MstnPlatform, Print, IPlotter, GetExtLineStyles));
    c10.def("SetExtLineStyles", &IPlotter::SetExtLineStyles, "numExtLineStyles"_a, "extLineStylesDots"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetExtLineStyles));

    c10.def("Forms", &IPlotter::Forms, DOC(Bentley, MstnPlatform, Print, IPlotter, Forms));
    c10.def("FormsCP", &IPlotter::FormsCP, DOC(Bentley, MstnPlatform, Print, IPlotter, FormsCP));
    c10.def("FontMaps", &IPlotter::FontMaps, DOC(Bentley, MstnPlatform, Print, IPlotter, FontMaps));

    c10.def("SelectFormByName", &IPlotter::SelectFormByName, "formName"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SelectFormByName));
    c10.def("SelectTrayByName", &IPlotter::SelectTrayByName, "trayName"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SelectTrayByName));

    c10.def("WriteCommand", [](IPlotter& self, py::bytes const& buffer) {}, "buffer"_a);
    c10.def("WriteString", [](IPlotter& self, py::str const& buffer) {}, "buffer"_a);

    c10.def("CopyFileIntoPlotFile", &IPlotter::CopyFileIntoPlotFile, "filename"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, CopyFileIntoPlotFile));
    c10.def("FlushBuffer", &IPlotter::FlushBuffer, DOC(Bentley, MstnPlatform, Print, IPlotter, FlushBuffer));

    c10.def("GetRasterOptions", &IPlotter::GetRasterOptions, DOC(Bentley, MstnPlatform, Print, IPlotter, GetRasterOptions));
    c10.def("SetRasterOptions", &IPlotter::SetRasterOptions, "rasterOptions"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetRasterOptions));

    c10.def("GetPrinterDriver", &IPlotter::GetPrinterDriver, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPrinterDriver));
    c10.def("SetPrinterDriver", &IPlotter::SetPrinterDriver, "driverP");

    c10.def("GetDriverOutputMode", &IPlotter::GetDriverOutputMode, DOC(Bentley, MstnPlatform, Print, IPlotter, GetDriverOutputMode));
    c10.def("SetDriverOutputMode", &IPlotter::SetDriverOutputMode, "mode"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetDriverOutputMode));

    c10.def("GetDriverCoordSysOrigin", &IPlotter::GetDriverCoordSysOrigin, DOC(Bentley, MstnPlatform, Print, IPlotter, GetDriverCoordSysOrigin));
    c10.def("SetDriverCoordSysOrigin", &IPlotter::SetDriverCoordSysOrigin, "origin"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetDriverCoordSysOrigin));

    c10.def("RoundPaperSize", &IPlotter::RoundPaperSize, "roundingUnits"_a, "sizeUnits"_a, "size"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, RoundPaperSize));
    c10.def("RasterizedParam", &IPlotter::RasterizedParam, DOC(Bentley, MstnPlatform, Print, IPlotter, RasterizedParam));
    c10.def("OleParam", &IPlotter::OleParam, DOC(Bentley, MstnPlatform, Print, IPlotter, OleParam));
    c10.def("GetPlotDestination", &IPlotter::GetPlotDestination, DOC(Bentley, MstnPlatform, Print, IPlotter, GetPlotDestination));
    c10.def("SetPlotDestination", &IPlotter::SetPlotDestination, "destination"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetPlotDestination));
    c10.def("GetHwTextMode", &IPlotter::GetHwTextMode, DOC(Bentley, MstnPlatform, Print, IPlotter, GetHwTextMode));
    c10.def("SetHwTextMode", &IPlotter::SetHwTextMode, "value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetHwTextMode));
    c10.def("IsPrintToFile", &IPlotter::IsPrintToFile, DOC(Bentley, MstnPlatform, Print, IPlotter, IsPrintToFile));
    c10.def("IsPrintToMetafile", &IPlotter::IsPrintToMetafile, DOC(Bentley, MstnPlatform, Print, IPlotter, IsPrintToMetafile));
    c10.def("IsPrintToIpserver", &IPlotter::IsPrintToIpserver, DOC(Bentley, MstnPlatform, Print, IPlotter, IsPrintToIpserver));
    c10.def("FindFormByNameSizeMatch", &IPlotter::FindFormByNameSizeMatch, "requestForm"_a, "requestUnits"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, FindFormByNameSizeMatch));
    c10.def("FindCompanionFile", &IPlotter::FindCompanionFile, "fileSpec"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, FindCompanionFile));
    c10.def("GetSystemPrinterName", &IPlotter::GetSystemPrinterName, "printerName"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetSystemPrinterName));
    c10.def("SelectSystemPrinter", &IPlotter::SelectSystemPrinter, "printerName"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SelectSystemPrinter));
    c10.def("SetSystemPrinterOrientation", &IPlotter::SetSystemPrinterOrientation, "orientation"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetSystemPrinterOrientation));

    c10.def("FindBestFitForm", [](IPlotter& self, double requestWidthDots, double requestHeightDots, PlotUnits requestUnits,
    Int32Array& bestFitFormIndex, BoolArray& selectedFormFits)
    {}, "requestWidthDots"_a, "requestHeightDots"_a, "requestUnits"_a, "bestFitFormIndexP"_a, "selectedFormFitsP"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, FindBestFitForm));

    c10.def("GetEngineError", &IPlotter::GetEngineError, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineError));
    c10.def("SetEngineError", &IPlotter::SetEngineError,"value"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetEngineError));
    c10.def("GetEngineLineWidth", py::overload_cast<int>(&IPlotter::GetEngineLineWidth, py::const_), "weight"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineLineWidth));
    c10.def("GetEngineLineWidth", py::overload_cast<int, int>(&IPlotter::GetEngineLineWidth, py::const_), "pen"_a, "weight"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineLineWidth));
    c10.def("SetEngineLineWidth", &IPlotter::SetEngineLineWidth, "weight"_a, "lineWidthDots"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, SetEngineLineWidth));
    c10.def("GetEngineLineStyle", &IPlotter::GetEngineLineStyle, "styleIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineLineStyle));
    c10.def("GetEngineColorFromPen", &IPlotter::GetEngineColorFromPen, "pen"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineColorFromPen));
    c10.def("GetEngineColorFromIndex", &IPlotter::GetEngineColorFromIndex, "colorIndex"_a, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineColorFromIndex));
    c10.def("GetEngineBackgroundColor", &IPlotter::GetEngineBackgroundColor, DOC(Bentley, MstnPlatform, Print, IPlotter, GetEngineBackgroundColor));

    //===================================================================================
    //class PlotterRef
    py::class_<PlotterRef, PlotterPtr> c11(m, "PlotterRef");

    c11.def(py::init(&PlotterRef::Create));

    c11.def_static("Create", &PlotterRef::Create, DOC(Bentley, MstnPlatform, Print, PlotterRef, Create));
    c11.def("Copy", &PlotterRef::Copy, DOC(Bentley, MstnPlatform, Print, PlotterRef, Copy));
    c11.def("GetP", &PlotterRef::GetP, py::return_value_policy::reference_internal);
   }
