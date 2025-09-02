/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\unitdefinition.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/UnitDefinition.h>



static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_Clone =R"doc(Create a copy of these options)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetSizeCriteria =R"doc(Set the iteration to filter units according to size. Since size
comparison is only valid within a single #UnitBase, this method will
restrict the iteration to only those units with the same base as the
specified unit.

:param (input):
    unitDef The unit on which to base the filtering.

:param (input):
    method The method used to compare candidate units to the specified
    unit.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetAllowAdditionalSystem =R"doc(Set the iteration to include the specified system in addition to the
ones already allowed.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetAllowSingleSystem =R"doc(Set the iteration to include only the specified system.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetAllowAdditionalBase =R"doc(Set the iteration to include the specified base in addition to the
ones already allowed.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetAllowSingleBase =R"doc(Set the iteration to include only the specified base.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetOrderDescending =R"doc(Set the iteration order from largest to smallest.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitIteratorOptions_SetOrderAscending =R"doc(Set the iteration order from smallest to largest.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_BuildUnitListForUI =R"doc(Build a list of UnitDefinitions that can be used in unit pickers in
the user interface. The list contains those units defined in the
user's workspace. The list may contain invalid UnitDefinitions which
represent separators.

:param includeUnit:
    The current value, always included in the list (or NULL). The base
    of this unit must be the same as " base " parameter.

:param compareUnit:
    Unit on which to base restrictions (or NULL). The base of this
    unit must be the same as " base " parameter.

:param base:
    The returned bvector will include only this base.

:param restrictSize:
    Only show units equal to or smaller than compareUnit.

:param restrictSystem:
    Only show units in the same system as compareUnit.

:param useSingularNames:
    Ex. true->" Meter " false->" Meters ".

:returns:
    A bvector containing the units.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetByLabel =R"doc(Find the definition of a unit from the user's workspace by matching
one of its labels.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetByNumber =R"doc(Find the definition of a unit from the user's workspace by matching
the number assigned to it in the current session.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetByName =R"doc(Find the definition of a unit from the user's workspace by matching
its name in the current language.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetNextSmaller =R"doc(Get the next smaller unit from the user's workspace. The returned unit
will have the same base and system as the search unit. If a smaller
unit cannot be found, the search unit is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetNextLarger =R"doc(Get the next larger unit from the user's workspace. The returned unit
will have the same base and system as the search unit. If a larger
unit cannot be found, the search unit is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetNumber =R"doc(Get the number of a unit from the user's workspace.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetSystemName =R"doc(Get the unit localized system name.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetName =R"doc(Get the name of a unit from the user's workspace.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetStandardName =R"doc(Get the name of a standard unit in the current language.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetStandardLabel =R"doc(Get the label of a standard unit in the current language.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_IsStandardUnit =R"doc(Determine if a unit definition is the same size as a standard unit.

:returns:
    StandardUnit::None if the input does not match a standard unit.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetStandardUnitByName =R"doc(Find the definition of a standard unit from its name in the current
language.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetStandardUnit =R"doc(Get the definition for a standard unit.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_SetLabel =R"doc(Change this Unit's label.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetLabel =R"doc(Get a copy of this Unit's label.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetDenominator =R"doc(Get the denominator of this Unit. The numerator divided by the
denominator is the scale factor between this unit and its base.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetNumerator =R"doc(Get the numerator of this Unit. The numerator divided by the
denominator is the scale factor between this unit and its base.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetSystem =R"doc(Get the system of this Unit.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetBase =R"doc(Get the base of this Unit.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_ConvertDistanceFrom =R"doc(Convert a distance expressed in the input unit to this unit.

Returns (Tuple, 0):
    ERROR if the units are not comparable. See #AreComparable.

Returns (Tuple, 1):
	outputVal.

)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_GetConversionFactorFrom =R"doc(Compute the scale factor used to convert distance from the input unit
to this unit. The factor is defined by the equation:distInA = distInB
* factorFromBtoA. The method #ConvertDistanceFrom is preferable since
that calculation is more direct.

Returns (Tuple, 0):
    ERROR if the units are not comparable. See #AreComparable.

Returns (Tuple,1):
	factor.

)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_CompareByScale =R"doc(Test if two units are the same size. See #IsEqual for a more strict
equality test.

:returns:
    an integer i, such that:- i == ERROR if the units could not be
    compared. See #AreComparable. - i<0 if this unit is larger than
    other. - i> 0 if other unit is larger than this unit. - i == 0 if
    the two units are the same size.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_AreComparable =R"doc(Test if the sizes of two units can be compared. Only units with a
common base can be compared.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_SetInvalid =R"doc(Make this unit invalid)doc";

static const char * __doc_Bentley_DgnPlatform_UnitDefinition_IsValid =R"doc(Test if the unit contains valid data.)doc";

static const char * __doc_Bentley_DgnPlatform_UnitSystemMask_HasAnyOverlap =R"doc(Returns true if this and other have the same bits set)doc";

static const char * __doc_Bentley_DgnPlatform_UnitSystemMask_GetBit =R"doc(Set the value for a single bit)doc";

static const char * __doc_Bentley_DgnPlatform_UnitSystemMask_SetBit =R"doc(Returns true if any bits in the mask are true)doc";

static const char * __doc_Bentley_DgnPlatform_UnitSystemMask_AnySet =R"doc(Set the value of all bits to true)doc";

static const char * __doc_Bentley_DgnPlatform_UnitSystemMask_SetAll =R"doc(Set the value of all bits to false)doc";

static const char * __doc_Bentley_DgnPlatform_UnitSystemMask_Clear =R"doc(Construct a mask from a list of systems)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_UnitDefinition(py::module_& m)
    {
    //===================================================================================
    // enum class UnitSystem
    py::enum_< UnitSystem>(m, "UnitSystem")
        .value("eUndefined", UnitSystem::Undefined)
        .value("eEnglish", UnitSystem::English)
        .value("eMetric", UnitSystem::Metric)
        .value("eUSSurvey", UnitSystem::USSurvey)
        .export_values();

    //===================================================================================
    // struct UnitSystemMask
    py::class_< UnitSystemMask> c1(m, "UnitSystemMask");

    c1.def(py::init<>());
    c1.def(py::init<std::initializer_list <UnitSystem>>());
    c1.def("Clear", &UnitSystemMask::Clear, DOC(Bentley, DgnPlatform, UnitSystemMask, Clear));
    c1.def("SetAll", &UnitSystemMask::SetAll, DOC(Bentley, DgnPlatform, UnitSystemMask, SetAll));
    c1.def("AnySet", &UnitSystemMask::AnySet, DOC(Bentley, DgnPlatform, UnitSystemMask, AnySet));
    c1.def("SetBit", &UnitSystemMask::SetBit, "sys"_a, "value"_a, DOC(Bentley, DgnPlatform, UnitSystemMask, SetBit));
    c1.def("GetBit", &UnitSystemMask::GetBit, "sys"_a, DOC(Bentley, DgnPlatform, UnitSystemMask, GetBit));
    c1.def("HasAnyOverlap", &UnitSystemMask::HasAnyOverlap, "other"_a, DOC(Bentley, DgnPlatform, UnitSystemMask, HasAnyOverlap));
    c1.def("__eq__", [] (UnitSystemMaskCR self, UnitSystemMaskCR other) { return self.IsEqual(other); });

    //===================================================================================
    // struct UnitInfo
    py::class_< UnitInfo> c2(m, "UnitInfo");

    c2.def(py::init<>());

    c2.def_readwrite("flags", &UnitInfo::flags);
    c2.def_readwrite("numerator", &UnitInfo::numerator);
    c2.def_readwrite("denominator", &UnitInfo::denominator);
    c2.def_property("label",
                    [] (UnitInfo const& self) { return self.label; },
                    [] (UnitInfo& self, WCharCP newValue) { wcsncpy(self.label, newValue, DGNPLATFORM_RESOURCE_MAX_UNIT_LABEL_LENGTH); });

    //===================================================================================
    // struct UnitDefinition
    py::class_< UnitDefinition> c3(m, "UnitDefinition");

    c3.def(py::init<>());
    c3.def(py::init<UnitBase, UnitSystem, double, double, WCharCP>(), "base"_a, "sys"_a, "num"_a, "den"_a, "label"_a);
    c3.def(py::init<UnitInfoCR>(), "unitInfo"_a);

    c3.def("IsValid", &UnitDefinition::IsValid, DOC(Bentley, DgnPlatform, UnitDefinition, IsValid));
    c3.def("SetInvalid", &UnitDefinition::SetInvalid, DOC(Bentley, DgnPlatform, UnitDefinition, SetInvalid));
    c3.def(py::self == py::self);
    c3.def(py::self != py::self);
    c3.def("AreComparable", &UnitDefinition::AreComparable, "other"_a, DOC(Bentley, DgnPlatform, UnitDefinition, AreComparable));
    c3.def("CompareByScale", &UnitDefinition::CompareByScale, "other"_a, DOC(Bentley, DgnPlatform, UnitDefinition, CompareByScale));

    c3.def("GetConversionFactorFrom", [] (UnitDefinition const& self, UnitDefinitionCR from)
           {
           double factor = 0;
           auto retVal = self.GetConversionFactorFrom(factor, from);
           return py::make_tuple(retVal, factor);
           }, "from"_a, DOC(Bentley, DgnPlatform, UnitDefinition, GetConversionFactorFrom));

    c3.def("ConvertDistanceFrom", [] (UnitDefinition const& self, double inputVal, UnitDefinitionCR fromUnit)
           {
           double outputVal = 0;
           auto retVal = self.ConvertDistanceFrom(outputVal, inputVal, fromUnit);
           return py::make_tuple(retVal, outputVal);
           }, "inputVal"_a, "fromUnit"_a, DOC(Bentley, DgnPlatform, UnitDefinition, ConvertDistanceFrom));

    c3.def_property_readonly("Base", &UnitDefinition::GetBase);
    c3.def("GetBase", &UnitDefinition::GetBase, DOC(Bentley, DgnPlatform, UnitDefinition, GetBase));
    
    c3.def_property_readonly("System", &UnitDefinition::GetSystem);
    c3.def("GetSystem", &UnitDefinition::GetSystem, DOC(Bentley, DgnPlatform, UnitDefinition, GetSystem));
    
    c3.def_property_readonly("Numerator", &UnitDefinition::GetNumerator);
    c3.def("GetNumerator", &UnitDefinition::GetNumerator, DOC(Bentley, DgnPlatform, UnitDefinition, GetNumerator));
    
    c3.def_property_readonly("Denominator", &UnitDefinition::GetDenominator);
    c3.def("GetDenominator", &UnitDefinition::GetDenominator, DOC(Bentley, DgnPlatform, UnitDefinition, GetDenominator));
    
    c3.def_property("Label", &UnitDefinition::GetLabel, &UnitDefinition::SetLabel);
    c3.def("GetLabel", &UnitDefinition::GetLabel, DOC(Bentley, DgnPlatform, UnitDefinition, GetLabel));
    c3.def("SetLabel", &UnitDefinition::SetLabel, "label"_a, DOC(Bentley, DgnPlatform, UnitDefinition, SetLabel));

    c3.def_static("GetStandardUnit", &UnitDefinition::GetStandardUnit, "iUnit"_a, DOC(Bentley, DgnPlatform, UnitDefinition, GetStandardUnit));
    c3.def_static("GetStandardUnitByName", &UnitDefinition::GetStandardUnitByName, "name"_a, DOC(Bentley, DgnPlatform, UnitDefinition, GetStandardUnitByName));
    
    c3.def("IsStandardUnit", &UnitDefinition::IsStandardUnit, DOC(Bentley, DgnPlatform, UnitDefinition, IsStandardUnit));
    
    c3.def_static("GetStandardLabel", &UnitDefinition::GetStandardLabel, "iUnit"_a, DOC(Bentley, DgnPlatform, UnitDefinition, GetStandardLabel));    
    c3.def_static("GetStandardName", &UnitDefinition::GetStandardName, "iUnit"_a, "singlar"_a = false, DOC(Bentley, DgnPlatform, UnitDefinition, GetStandardName));
    c3.def("GetName", &UnitDefinition::GetName, "singlar"_a = false, "alsoStandard"_a = false, DOC(Bentley, DgnPlatform, UnitDefinition, GetName));
    c3.def_static("GetSystemName", &UnitDefinition::GetSystemName, "system"_a, DOC(Bentley, DgnPlatform, UnitDefinition, GetSystemName));
    c3.def("GetNumber", &UnitDefinition::GetNumber, "alsoStandard"_a = false, DOC(Bentley, DgnPlatform, UnitDefinition, GetNumber));
    
    c3.def_property_readonly("NextLarger", &UnitDefinition::GetNextLarger);
    c3.def("GetNextLarger", &UnitDefinition::GetNextLarger, DOC(Bentley, DgnPlatform, UnitDefinition, GetNextLarger));
    
    c3.def_property_readonly("NextSmaller", &UnitDefinition::GetNextSmaller);
    c3.def("GetNextSmaller", &UnitDefinition::GetNextSmaller, DOC(Bentley, DgnPlatform, UnitDefinition, GetNextSmaller));
    
    c3.def_static("GetByName", &UnitDefinition::GetByName, "unitName"_a, "alsoStandard"_a = false, DOC(Bentley, DgnPlatform, UnitDefinition, GetByName));
    c3.def_static("GetByNumber", &UnitDefinition::GetByNumber, "unitNumber"_a, "alsoStandard"_a = false, DOC(Bentley, DgnPlatform, UnitDefinition, GetByNumber));
    c3.def_static("GetByLabel", &UnitDefinition::GetByLabel, "label"_a, "alsoStandard"_a = false, DOC(Bentley, DgnPlatform, UnitDefinition, GetByLabel));

    c3.def_static("BuildUnitListForUI", 
                  &UnitDefinition::BuildUnitListForUI, 
                  "includeUnit"_a, "compareUnit"_a, "base"_a, "restrictSize"_a, "restrictSystem"_a, "useSinglarNames"_a, DOC(Bentley, DgnPlatform, UnitDefinition, BuildUnitListForUI));
        
    //===================================================================================
    // struct UnitListItem
    py::class_< UnitListItem> c4(m, "UnitListItem");
    py::bind_vector<bvector< UnitListItem>>(m, "UnitListItemArray", py::module_local(false));

    c4.def_readwrite("name", &UnitListItem::m_name);
    c4.def_readwrite("unitDef", &UnitListItem::m_unitDef);

    //===================================================================================
    // struct UnitIteratorOptions
    py::class_< UnitIteratorOptions, UnitIteratorOptionsPtr> c5(m, "UnitIteratorOptions");

    if (true)
        {
        //===================================================================================
        // enum class UnitCompareMethod
        py::enum_< UnitIteratorOptions::UnitCompareMethod>(c5, "UnitCompareMethod")
            .value("eAllowSmaller", UnitIteratorOptions::UnitCompareMethod::AllowSmaller)
            .value("eAllowSmallerOrEqual", UnitIteratorOptions::UnitCompareMethod::AllowSmallerOrEqual)
            .value("eAllowLarger", UnitIteratorOptions::UnitCompareMethod::AllowLarger)
            .value("eAllowLargerOrEqual", UnitIteratorOptions::UnitCompareMethod::AllowLargerOrEqual)
            .export_values();
        }

    c5.def("SetOrderAscending", &UnitIteratorOptions::SetOrderAscending, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetOrderAscending));
    c5.def("SetOrderDescending", &UnitIteratorOptions::SetOrderDescending, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetOrderDescending));
    c5.def("SetAllowSingleBase", &UnitIteratorOptions::SetAllowSingleBase, "base"_a, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetAllowSingleBase));
    c5.def("SetAllowAdditionalBase", &UnitIteratorOptions::SetAllowAdditionalBase, "base"_a, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetAllowAdditionalBase));
    c5.def("SetAllowSingleSystem", &UnitIteratorOptions::SetAllowSingleSystem, "system"_a, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetAllowSingleSystem));
    c5.def("SetAllowAdditionalSystem", &UnitIteratorOptions::SetAllowAdditionalSystem, "system"_a, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetAllowAdditionalSystem));
    c5.def("SetSizeCriteria", &UnitIteratorOptions::SetSizeCriteria, "unitDef"_a, "method"_a, DOC(Bentley, DgnPlatform, UnitIteratorOptions, SetSizeCriteria));
    c5.def(py::init(&UnitIteratorOptions::Create));
    c5.def("Clone", &UnitIteratorOptions::Clone, DOC(Bentley, DgnPlatform, UnitIteratorOptions, Clone));

    //===================================================================================
    // struct StandardUnitCollection
    py::class_< StandardUnitCollection> c6(m, "StandardUnitCollection");

    if (true)
        {
        //===================================================================================
        // struct Entry
        py::class_< StandardUnitCollection::Entry> c6_1(c6, "Entry");
        
        c6_1.def(py::init<>());

        c6_1.def_property_readonly("UnitDef", &StandardUnitCollection::Entry::GetUnitDef);
        c6_1.def("GetUnitDef", &StandardUnitCollection::Entry::GetUnitDef);

        c6_1.def_property_readonly("Number", &StandardUnitCollection::Entry::GetNumber);
        c6_1.def("GetNumber", &StandardUnitCollection::Entry::GetNumber);

        c6_1.def("GetName", &StandardUnitCollection::Entry::GetName, "singular"_a = false);
        }

    c6.def(py::init<UnitIteratorOptionsCR>(), "options"_a);
    c6.def("__iter__", [] (StandardUnitCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct UserUnitCollection
    py::class_< UserUnitCollection> c7(m, "UserUnitCollection");

    if (true)
        {
        //===================================================================================
        // struct Entry
        py::class_< UserUnitCollection::Entry> c7_1(c7, "Entry");
        
        c7_1.def_property_readonly("UnitDef", &UserUnitCollection::Entry::GetUnitDef);
        c7_1.def("GetUnitDef", &UserUnitCollection::Entry::GetUnitDef);

        c7_1.def_property_readonly("Number", &UserUnitCollection::Entry::GetNumber);
        c7_1.def("GetNumber", &UserUnitCollection::Entry::GetNumber);

        c7_1.def("GetName", &UserUnitCollection::Entry::GetName, "singular"_a = false);
        }

    c7.def(py::init<UnitIteratorOptionsCR>(), "options"_a);
    c7.def("__iter__", [] (UserUnitCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }