/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\InternalAPI\OpqueTypes_MstnPlatform.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#pragma once
#include <Mstn/Plot/PlotApi.h>
#include <Mstn/Plot/IPrintDescription.h>
#include <Mstn/Plot/IPlotElemDisplayParams.h>
#include <Mstn/Plot/IPlotter.h>
#include <Mstn/Plot/IPrintEngine.h>
#include <Mstn/Plot/IPrinterDriver.h>
#include <Mstn/Plot/IPlotHook.h>

// Opaque types
DEFINE_BVECTOR_TYPE(PrintStyleName, PrintStyleNameArray);
DEFINE_BVECTOR_TYPE(PlotPaperSizeInfo, PlotPaperSizeInfoArray);
DEFINE_BVECTOR_TYPE(LevelOverrideInfo, LevelOverrideInfoArray);
DEFINE_BVECTOR_TYPE(ReferenceOverrideInfo, ReferenceOverrideInfoArray);