/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\sheetsizedefinition.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/SheetSizeDefinition.h>



static const char * __doc_Bentley_DgnPlatform_SheetSizeCollection_FindByCustomInfo =R"doc(Find the sheet size definition with the specified parameters)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeCollection_FindByName =R"doc(Find the sheet size definition with the specified name.)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeIteratorOptions_Clone =R"doc(Create a copy of these options)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeIteratorOptions_SetAllowAdditionalSystem =R"doc(Set the iteration to include the specified system in addition to the
ones already allowed. English and USSurvey are considered the same
system.)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeIteratorOptions_SetAllowSingleSystem =R"doc(Set the iteration to include only the specified system. English and
USSurvey are considered the same system.)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeIteratorOptions_SetOrderDescending =R"doc(Set the iteration order from largest to smallest.)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeIteratorOptions_SetOrderAscending =R"doc(Set the iteration order from smallest to largest.)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeDefinition_BuildSheetSizeListForUI =R"doc(Build a list of SheetSizeDefinitions that can be used for pickers in
the user interface. The list contains those sheet sizes

Parameter ``includeSize``:
    The current value, always included in the list (or NULL).

Parameter ``restrictSystem``:
    Only show sheet sizes relevant for the specified system. Use
    UnitSystem::Undefined to show scales regardless of system.

Parameter ``alwaysAddCustom``:
    A custom row is added even if the include unit is found.

Returns:
    A bvector containing the scales.)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeDefinition_SetInvalid =R"doc(Make this sheet size invalid)doc";

static const char * __doc_Bentley_DgnPlatform_SheetSizeDefinition_IsValid =R"doc(Test if the sheet size contains valid data.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_SheetSizeDefinition(py::module_& m)
    {
    //===================================================================================
    // struct SheetSizeDefinition
    py::class_< SheetSizeDefinition> c1(m, "SheetSizeDefinition");

    c1.def(py::init<>());
    c1.def(py::init<WCharCP, double, double, UnitDefinitionCR, UnitSystemMaskCR>(), "name"_a, "height"_a, "width"_a, "unitDef"_a, "mask"_a);
    c1.def("IsValid", &SheetSizeDefinition::IsValid, DOC(Bentley, DgnPlatform, SheetSizeDefinition, IsValid));
    c1.def("SetInvalid", &SheetSizeDefinition::SetInvalid, DOC(Bentley, DgnPlatform, SheetSizeDefinition, SetInvalid));
    
    c1.def_property("Name", &SheetSizeDefinition::GetName, &SheetSizeDefinition::SetName);
    c1.def("GetName", &SheetSizeDefinition::GetName, py::return_value_policy::reference_internal);
    c1.def("SetName", &SheetSizeDefinition::SetName, "name"_a);
    
    c1.def_property("Width", &SheetSizeDefinition::GetWidth, &SheetSizeDefinition::SetWidth);
    c1.def("GetWidth", &SheetSizeDefinition::GetWidth);
    c1.def("SetWidth", &SheetSizeDefinition::SetWidth, "width"_a);
    
    c1.def_property("Height", &SheetSizeDefinition::GetHeight, &SheetSizeDefinition::SetHeight);
    c1.def("GetHeight", &SheetSizeDefinition::GetHeight);
    c1.def("SetHeight", &SheetSizeDefinition::SetHeight, "height"_a);
    
    c1.def_property("UnitDefinition", &SheetSizeDefinition::GetUnitDefinition, &SheetSizeDefinition::SetUnitDefinition);
    c1.def("GetUnitDefinition", &SheetSizeDefinition::GetUnitDefinition);
    c1.def("SetUnitDefinition", &SheetSizeDefinition::SetUnitDefinition, "unitDef"_a);
    
    c1.def_property("TopMargin", &SheetSizeDefinition::GetTopMargin, &SheetSizeDefinition::SetTopMargin);
    c1.def("GetTopMargin", &SheetSizeDefinition::GetTopMargin);
    c1.def("SetTopMargin", &SheetSizeDefinition::SetTopMargin, "margin"_a);
    
    c1.def_property("LeftMargin", &SheetSizeDefinition::GetLeftMargin, &SheetSizeDefinition::SetLeftMargin);
    c1.def("GetLeftMargin", &SheetSizeDefinition::GetLeftMargin);
    c1.def("SetLeftMargin", &SheetSizeDefinition::SetLeftMargin, "margin"_a);
    
    c1.def_property("BottomMargin", &SheetSizeDefinition::GetBottomMargin, &SheetSizeDefinition::SetBottomMargin);
    c1.def("GetBottomMargin", &SheetSizeDefinition::GetBottomMargin);
    c1.def("SetBottomMargin", &SheetSizeDefinition::SetBottomMargin, "margin"_a);
    
    c1.def_property("RightMargin", &SheetSizeDefinition::GetRightMargin, &SheetSizeDefinition::SetRightMargin);
    c1.def("GetRightMargin", &SheetSizeDefinition::GetRightMargin);
    c1.def("SetRightMargin", &SheetSizeDefinition::SetRightMargin, "margin"_a);
    
    c1.def("GetMarginAt", &SheetSizeDefinition::GetMarginAt, "index"_a);
    c1.def("SetMarginAt", &SheetSizeDefinition::SetMarginAt, "margin"_a, "index"_a);
    
    c1.def_property("UnitSystemMask", &SheetSizeDefinition::GetUnitSystemMask, &SheetSizeDefinition::SetUnitSystemMask);
    c1.def("GetUnitSystemMask", &SheetSizeDefinition::GetUnitSystemMask);
    c1.def("SetUnitSystemMask", &SheetSizeDefinition::SetUnitSystemMask, "mask"_a);

    c1.def_static("BuildSheetSizeListForUI", 
                  py::overload_cast<SheetSizeDefinitionCP, UnitSystem, bool>(&SheetSizeDefinition::BuildSheetSizeListForUI),
                  "includeSize"_a, "restrictSystem"_a, "alwaysAddCustom"_a, DOC(Bentley, DgnPlatform, SheetSizeDefinition, BuildSheetSizeListForUI));

    //===================================================================================
    // struct SheetSizeIteratorOptions
    py::class_< SheetSizeIteratorOptions, SheetSizeIteratorOptionsPtr> c2(m, "SheetSizeIteratorOptions");

    c2.def("SetOrderAscending", &SheetSizeIteratorOptions::SetOrderAscending, DOC(Bentley, DgnPlatform, SheetSizeIteratorOptions, SetOrderAscending));
    c2.def("SetOrderDescending", &SheetSizeIteratorOptions::SetOrderDescending, DOC(Bentley, DgnPlatform, SheetSizeIteratorOptions, SetOrderDescending));
    c2.def("SetAllowSingleSystem", &SheetSizeIteratorOptions::SetAllowSingleSystem, "system"_a, DOC(Bentley, DgnPlatform, SheetSizeIteratorOptions, SetAllowSingleSystem));
    c2.def("SetAllowAdditionalSystem", &SheetSizeIteratorOptions::SetAllowAdditionalSystem, "system"_a, DOC(Bentley, DgnPlatform, SheetSizeIteratorOptions, SetAllowAdditionalSystem));
    c2.def(py::init(&SheetSizeIteratorOptions::Create));
    c2.def("Clone", &SheetSizeIteratorOptions::Clone, DOC(Bentley, DgnPlatform, SheetSizeIteratorOptions, Clone));

    //===================================================================================
    // struct SheetSizeCollection
    py::class_< SheetSizeCollection> c3(m, "SheetSizeCollection");

    c3.def(py::init<SheetSizeIteratorOptionsCR>(), "options"_a);
    c3.def("__iter__", [] (SheetSizeCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c3.def("FindByName", &SheetSizeCollection::FindByName, "name"_a, DOC(Bentley, DgnPlatform, SheetSizeCollection, FindByName));
    c3.def("FindByCustomInfo", &SheetSizeCollection::FindByCustomInfo, "width"_a, "height"_a, "units"_a, DOC(Bentley, DgnPlatform, SheetSizeCollection, FindByCustomInfo));
    }