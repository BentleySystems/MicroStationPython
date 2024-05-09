/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\scaledefinition.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/ScaleDefinition.h>



static const char * __doc_Bentley_DgnPlatform_ScaleCollection_FindByFactor =R"doc(Find the ScaleDefinition matching the specified scale factor.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleCollection_FindByName =R"doc(Find the ScaleDefinition with the specified name.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleIteratorOptions_Clone =R"doc(Create a copy of these options)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleIteratorOptions_SetAllowAdditionalSystem =R"doc(Set the iteration to include the specified system in addition to the
ones already allowed.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleIteratorOptions_SetAllowSingleSystem =R"doc(Set the iteration to include only the specified system.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleIteratorOptions_SetOrderDescending =R"doc(Set the iteration order from largest to smallest.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleIteratorOptions_SetOrderAscending =R"doc(Set the iteration order from smallest to largest.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_BuildScaleListForUI =R"doc(Build a list of ScaleDefinitions that can be used in scale pickers in
the user interface. The list contains those scales

Parameter ``includeScale``:
    The current value, always included in the list (or NULL).

Parameter ``restrictSystem``:
    Only show scales relevant for the specified system. Use
    UnitSystem::Undefined to show scales regardless of system.

Parameter ``alwaysAddCustom``:
    A custom row is added even if the include unit is found.

Returns:
    A bvector containing the scales.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_FormatNameAsRatio =R"doc(Change the name of this scale to be a string that describes its
factor. For example 2.5:1)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_GetUnitSystemMask =R"doc(Get the mask of unit systems associated with this sheet size. @Remarks
The mask is used to catagorize this scale definition.

Returns:
    The mask of unit systems)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_SetPostScale =R"doc(Change the scale's postScale.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_GetPostScale =R"doc(Get the preScale.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_SetPreScale =R"doc(Change the scale's preScale.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_GetPreScale =R"doc(Get the preScale.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_GetScale =R"doc(Get the scale factor. Computes preScale/postScale.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_SetName =R"doc(Change the scale's name.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_GetName =R"doc(Get the scale's name.)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_SetInvalid =R"doc(Make this scale invalid)doc";

static const char * __doc_Bentley_DgnPlatform_ScaleDefinition_IsValid =R"doc(Test if the scale contains valid data.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ScaleDefinition(py::module_& m)
    {
    //===================================================================================
    // struct ScaleDefinition
    py::class_< ScaleDefinition> c1(m, "ScaleDefinition");

    c1.def(py::init<>());
    c1.def(py::init<WCharCP, double, double, UnitSystemMaskCR>(), "name"_a, "pre"_a, "post"_a, "mask"_a);
    c1.def(py::init<double, bool>(), "scaleFactor"_a, "noCustomInName"_a = false);

    c1.def("IsValid", &ScaleDefinition::IsValid, DOC(Bentley, DgnPlatform, ScaleDefinition, IsValid));
    c1.def("SetInvalid", &ScaleDefinition::SetInvalid, DOC(Bentley, DgnPlatform, ScaleDefinition, SetInvalid));
    
    c1.def_property("Name", &ScaleDefinition::GetName, &ScaleDefinition::SetName);
    c1.def("GetName", &ScaleDefinition::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ScaleDefinition, GetName));
    c1.def("SetName", &ScaleDefinition::SetName, "name"_a, DOC(Bentley, DgnPlatform, ScaleDefinition, SetName));
    
    c1.def_property_readonly("Scale", &ScaleDefinition::GetScale);
    c1.def("GetScale", &ScaleDefinition::GetScale, DOC(Bentley, DgnPlatform, ScaleDefinition, GetScale));
    
    c1.def_property("PreScale", &ScaleDefinition::GetPreScale, &ScaleDefinition::SetPreScale);
    c1.def("GetPreScale", &ScaleDefinition::GetPreScale, DOC(Bentley, DgnPlatform, ScaleDefinition, GetPreScale));
    c1.def("SetPreScale", &ScaleDefinition::SetPreScale, "scale"_a, DOC(Bentley, DgnPlatform, ScaleDefinition, SetPreScale));
    
    c1.def_property("PostScale", &ScaleDefinition::GetPostScale, &ScaleDefinition::SetPostScale);
    c1.def("GetPostScale", &ScaleDefinition::GetPostScale, DOC(Bentley, DgnPlatform, ScaleDefinition, GetPostScale));
    c1.def("SetPostScale", &ScaleDefinition::SetPostScale, "scale"_a, DOC(Bentley, DgnPlatform, ScaleDefinition, SetPostScale));
    
    c1.def_property("UnitSystemMask", &ScaleDefinition::GetUnitSystemMask, &ScaleDefinition::SetUnitSystemMask);
    c1.def("GetUnitSystemMask", &ScaleDefinition::GetUnitSystemMask, DOC(Bentley, DgnPlatform, ScaleDefinition, GetUnitSystemMask));
    c1.def("SetUnitSystemMask", &ScaleDefinition::SetUnitSystemMask, "mask"_a);
    
    c1.def(py::self == py::self);
    c1.def("FormatNameAsRatio", &ScaleDefinition::FormatNameAsRatio, DOC(Bentley, DgnPlatform, ScaleDefinition, FormatNameAsRatio));

    c1.def_static("BuildScaleListForUI",
                  py::overload_cast<ScaleDefinitionCP, UnitSystem, bool>(&ScaleDefinition::BuildScaleListForUI),
                  "includeScale"_a, "restrictSystem"_a, "alwaysAddCustom"_a, DOC(Bentley, DgnPlatform, ScaleDefinition, BuildScaleListForUI));


    //===================================================================================
    // struct ScaleIteratorOptions
    py::class_< ScaleIteratorOptions, ScaleIteratorOptionsPtr> c2(m, "ScaleIteratorOptions");

    c2.def("SetOrderAscending", &ScaleIteratorOptions::SetOrderAscending, DOC(Bentley, DgnPlatform, ScaleIteratorOptions, SetOrderAscending));
    c2.def("SetOrderDescending", &ScaleIteratorOptions::SetOrderDescending, DOC(Bentley, DgnPlatform, ScaleIteratorOptions, SetOrderDescending));
    c2.def("SetAllowSingleSystem", &ScaleIteratorOptions::SetAllowSingleSystem, "system"_a, DOC(Bentley, DgnPlatform, ScaleIteratorOptions, SetAllowSingleSystem));
    c2.def("SetAllowAdditionalSystem", &ScaleIteratorOptions::SetAllowAdditionalSystem, "system"_a, DOC(Bentley, DgnPlatform, ScaleIteratorOptions, SetAllowAdditionalSystem));
    c2.def(py::init(&ScaleIteratorOptions::Create));
    c2.def("Clone", &ScaleIteratorOptions::Clone, DOC(Bentley, DgnPlatform, ScaleIteratorOptions, Clone));

    //===================================================================================
    // struct ScaleCollection
    py::class_< ScaleCollection> c3(m, "ScaleCollection");

    c3.def("__iter__", [] (ScaleCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c3.def("FindByName", &ScaleCollection::FindByName, "name"_a, DOC(Bentley, DgnPlatform, ScaleCollection, FindByName));
    c3.def("FindByFactor", &ScaleCollection::FindByFactor, "scale"_a, DOC(Bentley, DgnPlatform, ScaleCollection, FindByFactor));
    }