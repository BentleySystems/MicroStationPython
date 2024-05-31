/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\sheetdef.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/SheetDef.h>



static const char * __doc_Bentley_DgnPlatform_SheetDef_GetSheetName =R"doc(Get the Sheet name)doc";

static const char * __doc_Bentley_DgnPlatform_SheetDef_SetSheetName =R"doc(Set the Sheet name)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SheetDef(py::module_& m)
    {
    //===================================================================================
    // struct SheetDef
    py::class_< SheetDef> c1(m, "SheetDef");

    c1.def_property("Enabled", &SheetDef::IsEnabled, &SheetDef::Enable);
    c1.def("IsEnabled", &SheetDef::IsEnabled);
    c1.def("Enable", &SheetDef::Enable, "enable"_a);

    c1.def("SetSheetName", &SheetDef::SetSheetName, "sheetName"_a, DOC(Bentley, DgnPlatform, SheetDef, SetSheetName));
    c1.def("GetSheetName", &SheetDef::GetSheetName, "sheetName"_a, DOC(Bentley, DgnPlatform, SheetDef, GetSheetName));
    c1.def("GetOrigin", &SheetDef::GetOrigin, "sheetOrigin"_a);
    c1.def("SetOrigin", &SheetDef::SetOrigin, "sheetOrigin"_a);

    c1.def_property("Rotation", &SheetDef::GetRotation, &SheetDef::SetRotation);
    c1.def("GetRotation", &SheetDef::GetRotation);
    c1.def("SetRotation", &SheetDef::SetRotation, "rotation"_a);
    
    c1.def("GetSize", [] (SheetDef const& self)
           {
           double width = 0, height = 0;
           self.GetSize(width, height);
           return py::make_tuple(width, height);
           });

    c1.def("SetSize", &SheetDef::SetSize, "sheetWidth"_a, "sheetHeight"_a);
    c1.def("GetFormName", &SheetDef::GetFormName, "formatName"_a);
    c1.def("SetFormName", &SheetDef::SetFormName, "formatName"_a);
    c1.def("GetUnits", &SheetDef::GetUnits, "unitDef"_a);
    c1.def("SetUnits", &SheetDef::SetUnits, "unitDef"_a);
    
    c1.def("GetMargins", [] (SheetDef const& self)
           {
           double top = 0, left = 0, bottom = 0, right = 0;
           self.GetMargins(top, left, bottom, right);
           return py::make_tuple(top, left, bottom, right);
           });

    c1.def("SetMargins", &SheetDef::SetMargins, "topMargin"_a, "leftMargin"_a, "bottomMargin"_a, "rightMargin"_a);
    
    c1.def_property("PlotScaleFactor", &SheetDef::GetPlotScaleFactor, &SheetDef::SetPlotScaleFactor);
    c1.def("GetPlotScaleFactor", &SheetDef::GetPlotScaleFactor);
    c1.def("SetPlotScaleFactor", &SheetDef::SetPlotScaleFactor, "factor"_a);
    
    c1.def("GetWindowsPrinterName", &SheetDef::GetWindowsPrinterName, "printerName"_a);
    c1.def("SetWindowsPrinterName", &SheetDef::SetWindowsPrinterName, "printerName"_a);
    c1.def("GetPltFileName", &SheetDef::GetPltFileName, "pltFileName"_a);
    c1.def("SetPltFileName", &SheetDef::SetPltFileName, "pltFileName"_a);
    c1.def("GetPlotStyleTableFileName", &SheetDef::GetPlotStyleTableFileName, "pstFileName"_a);
    c1.def("SetPlotStyleTableFileName", &SheetDef::SetPlotStyleTableFileName, "pstFileName"_a);
    c1.def("GetPrintStyleName", &SheetDef::GetPrintStyleName, "printStyleName"_a);
    c1.def("SetPrintStyleName", &SheetDef::SetPrintStyleName, "printStyleName"_a);
    
    c1.def_property("SheetNumber", &SheetDef::GetSheetNumber, &SheetDef::SetSheetNumber);
    c1.def("GetSheetNumber", &SheetDef::GetSheetNumber);
    c1.def("SetSheetNumber", &SheetDef::SetSheetNumber, "number"_a);
    
    c1.def_property("BorderAttachmentId", &SheetDef::GetBorderAttachmentId, &SheetDef::SetBorderAttachmentId);
    c1.def("GetBorderAttachmentId", &SheetDef::GetBorderAttachmentId);
    c1.def("SetBorderAttachmentId", &SheetDef::SetBorderAttachmentId, "borderAttachId"_a);
    }