/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iareafillproperties.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IAreaFillProperties.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IAreaFillProperties(py::module_& m)
    {
    //===================================================================================
    // struct IAreaFillPropertiesQuery
    py::class_< IAreaFillPropertiesQuery, std::unique_ptr< IAreaFillPropertiesQuery, py::nodelete> > c1(m, "IAreaFillPropertiesQuery");

    c1.def("GetAreaType", [] (IAreaFillPropertiesQuery const& self, ElementHandleCR eh)
           {
           bool isHole = false;
           auto retVal = self.GetAreaType(eh, &isHole);
           return py::make_tuple(retVal, isHole);
           }, "eh"_a);

    c1.def("GetSolidFill", [] (IAreaFillPropertiesQuery const& self, ElementHandleCR eh)
           {
           UInt32 fillColor;
           bool alwaysFilled = false;
           auto retVal = self.GetSolidFill(eh, &fillColor, &alwaysFilled);
           return py::make_tuple(retVal, fillColor, alwaysFilled);
           }, "eh"_a);

    c1.def("GetGradientFill", [] (IAreaFillPropertiesQuery const& self, ElementHandleCR eh)
           {
           GradientSymbPtr symb;
           auto retVal = self.GetGradientFill(eh, symb);
           return py::make_tuple(retVal, symb);
           }, "eh"_a);

    c1.def("GetPattern", [] (IAreaFillPropertiesQuery const& self, ElementHandleCR eh, bvector<DwgHatchDefLine>* hatchDefLinesP, DPoint3dP originP, int index)
           {
           PatternParamsPtr params;
           auto retVal = self.GetPattern(eh, params, hatchDefLinesP, originP, index);
           return py::make_tuple(retVal, params);
           }, "eh"_a, "hatchDefLines"_a, "origin"_a, "index"_a);

    c1.def("GetPattern", [] (IAreaFillPropertiesQuery const& self, ElementHandleCR eh, py::list hatchDefLinesP, DPoint3dP originP, int index)
           {
           PatternParamsPtr params;
           CONVERT_PYLIST_TO_NEW_CPPARRAY(hatchDefLinesP, hatchDefLines, bvector<DwgHatchDefLine>, DwgHatchDefLine);
           auto retVal = self.GetPattern(eh, params, &hatchDefLines, originP, index);
           return py::make_tuple(retVal, params);
           }, "eh"_a, "hatchDefLines"_a, "origin"_a, "index"_a);

    //===================================================================================
    // struct IAreaFillPropertiesEdit
    py::class_< IAreaFillPropertiesEdit, std::unique_ptr< IAreaFillPropertiesEdit, py::nodelete>, IAreaFillPropertiesQuery> c2(m, "IAreaFillPropertiesEdit");

    c2.def("SetAreaType", &IAreaFillPropertiesEdit::SetAreaType, "eeh"_a, "isHole"_a);
    c2.def("RemoveAreaFill", &IAreaFillPropertiesEdit::RemoveAreaFill, "eeh"_a);
    c2.def("RemovePattern", &IAreaFillPropertiesEdit::RemovePattern, "eeh"_a, "index"_a);
    c2.def("AddSolidFill", &IAreaFillPropertiesEdit::AddSolidFill, "eeh"_a, "fillColor"_a, "alwaysFilled"_a);
    c2.def("AddGradientFill", &IAreaFillPropertiesEdit::AddGradientFill, "eeh"_a, "symb"_a);
    c2.def("AddPattern", &IAreaFillPropertiesEdit::AddPattern, "eeh"_a, "params"_a, "hatchDefLines"_a, "index"_a = 0);
    }