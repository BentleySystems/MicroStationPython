/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\templatesymbologyremapper.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/TemplateSymbologyRemapper.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_TemplateSymbologyRemapper(py::module_& m)
    {
    //===================================================================================
    // enum ActivePointType
    py::enum_< ActivePointType>(m, "ActivePointType", py::arithmetic())
        .value("eACTIVEPOINTTYPE_ZeroLengthLine", ACTIVEPOINTTYPE_ZeroLengthLine)
        .value("eACTIVEPOINTTYPE_Character", ACTIVEPOINTTYPE_Character)
        .value("eACTIVEPOINTTYPE_Cell", ACTIVEPOINTTYPE_Cell)
        .export_values();

    //===================================================================================
    // enum ElementColorSource
    py::enum_< ElementColorSource>(m, "ElementColorSource", py::arithmetic())
        .value("eCOLORSOURCE_Element", COLORSOURCE_Element)
        .value("eCOLORSOURCE_ByLevel", COLORSOURCE_ByLevel)
        .value("eCOLORSOURCE_ByCell", COLORSOURCE_ByCell)
        .export_values();

    //===================================================================================
    // enum ElementFillModeType
    py::enum_< ElementFillModeType>(m, "ElementFillModeType", py::arithmetic())
        .value("eFILLMODE_UseActive", FILLMODE_UseActive)
        .value("eFILLMODE_NotFilled", FILLMODE_NotFilled)
        .value("eFILLMODE_Filled", FILLMODE_Filled)
        .value("eFILLMODE_Outlined", FILLMODE_Outlined)
        .export_values();

    //===================================================================================
    // enum ElementColorType
    py::enum_< ElementColorType>(m, "ElementColorType", py::arithmetic())
        .value("eCOLORTYPE_None", COLORTYPE_None)
        .value("eCOLORTYPE_Indexed", COLORTYPE_Indexed)
        .value("eCOLORTYPE_RGB", COLORTYPE_RGB)
        .value("eCOLORTYPE_ColorBook", COLORTYPE_ColorBook)
        .value("eCOLORTYPE_GradientFill", COLORTYPE_GradientFill)
        .export_values();

    //===================================================================================
    // struct ElementColorData
    py::class_< ElementColorData> c1(m, "ElementColorData");

    c1.def_readwrite("colorSource", &ElementColorData::colorSource);
    c1.def_readwrite("colorType", &ElementColorData::colorType);
    c1.def_readwrite("colorIndex", &ElementColorData::colorIndex);
    c1.def_readwrite("red", &ElementColorData::red);
    c1.def_readwrite("green", &ElementColorData::green);
    c1.def_readwrite("blue", &ElementColorData::blue);
    
    c1.def_property("ColorBook",
                    [] (ElementColorData const& self) { return self.colorBook; },
                    [] (ElementColorData& self, WCharCP colorBook) { wcsncpy_s(self.colorBook, colorBook, MAX_LINKAGE_STRING_LENGTH - 1); });

    c1.def_property("ColorName",
                    [] (ElementColorData const& self) { return self.colorName; },
                    [] (ElementColorData& self, WCharCP colorName) { wcsncpy(self.colorName, colorName, MAX_LINKAGE_STRING_LENGTH - 1); });

    //===================================================================================
    // struct Elementfillcolordata
    py::class_< ElementFillColorData> c2(m, "ElementFillColorData");

    c2.def_readwrite("colorData", &ElementFillColorData::colorData);
    c2.def_readwrite("active", &ElementFillColorData::active);
    c2.def_readwrite("mode", &ElementFillColorData::mode);
    c2.def_readwrite("flags", &ElementFillColorData::flags);
    c2.def_readonly("nKeys", &ElementFillColorData::nKeys);
    c2.def_readwrite("angle", &ElementFillColorData::angle);
    c2.def_readwrite("tint", &ElementFillColorData::tint);
    c2.def_readwrite("shift", &ElementFillColorData::shift);

    c2.def("GetColorAt", [] (ElementFillColorData const& self, UInt16 index)
           {
           if (index >= self.nKeys)
               throw py::index_error();
           return self.colors[index];
           });

    c2.def("SetColorAt", [] (ElementFillColorData& self, UInt16 index, RgbColorDefCR newColor)
           {
           if (index >= self.nKeys)
               throw py::index_error();
           self.colors[index] = newColor;
           });

    c2.def("GetValueAt", [] (ElementFillColorData const& self, UInt16 index)
           {
           if (index >= self.nKeys)
               throw py::index_error();
           return self.values[index];
           });

    c2.def("SetValueAt", [] (ElementFillColorData& self, UInt16 index, double newValue)
           {
           if (index >= self.nKeys)
               throw py::index_error();
           self.values[index] = newValue;
           });

    }