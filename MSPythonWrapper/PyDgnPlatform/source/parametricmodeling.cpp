/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\parametricmodeling.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ParametricModeling.h>



static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_SetParamSetValue =R"doc(Sets the value of a paramter set for a given parameter definition
converted with respect to the current unit system if any conversion is
needed for any type of parameter.

:param def:
    The parameter definition for which we are setting the value of the
    paramter set.

:param pSet:
    The parameter set for which we are setting the value.

:param value:
    The value in char to be stored in as the value of the paramter
    set.

:param unitFactor:
    The value in double is used to convert the value with respect to
    the current model unit for some type of parameter

:returns:
    status of the setting of the value to the parameter set. If true
    then it is successfule else failed)doc";

static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_ReadFromCsv =R"doc(Reads the contents of the specified CSV of a format compatible with
that produced by IParameterDefinitions::WriteToCsv(), and applies the
data to these parameter definitions.

:param src:
    The CSV file from which to read the data

:param context:
    The context in which to read the contents. In particular, this
    context specifies which sections of the CSV to include and which
    to ignore.

:returns:
    The sections of CSV which were successfully read and applied.)doc";

static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_SetExpressionForParameter =R"doc(Associates an expression with a parameter, or removes an existing
expression. If an expression is associated with a parameter, the
parameter becomes read-only and its value will be calculated
dynamically by evaluating the expression. Expressions can reference
other parameters, as well as various functions and constants.

:param accessString:
    The internal name of the parameter associated with the expression

:param expr:
    The expression to be associated with the parameter, or nullptr if
    the existing expression is to be removed

:returns:
    Success if the expression was updated for the specified parameter,
    or an error status)doc";

static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_SetDomainParameters =R"doc(Adds or replaces the domain parameters, or removes them if nullptr is
passed. Domain parameters are obtained from an ECClass (e.g., as
defined by a CustomItemType) supplied by the user or application. All
ECProperties within the ECClass which are usable for parametric
modeling (i.e., of a type convertible to one of those defined by
ParameterType enum) will become " domain " parameters. Domain parameters
support more limited modification than local (" working ") parameters -
in particular, their names and types cannot be modified as they are
defined by the user's ECSchema. The scope and visibility of a domain
parameter can be modified, and their values can be defined by
expressions. The property values of the supplied IECInstance will
provide the initial values of each domain parameter. These values will
be applied to all IParameterSets as well.

:param domainParams:
    An IECInstance of the desired ECClass, or nullptr to remove
    existing domain parameters.

:returns:
    Success if the domain parameters were successfully updated, or an
    error status.)doc";

static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_Replace =R"doc(Updates the parameter definition with the same internal name as the
specified parameter definition

:param def:
    The updated parameter definition

:returns:
    Success if the parameter definition was updated, or an error
    status)doc";

static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_Remove =R"doc(Removes the parameter definition with the specified name Removes the
parameter definition with the specified internal name

:param accessString:
    The internal name of the parameter

:returns:
    Success if the parameter was successfully removed, or else an
    error status)doc";

static const char * __doc_Bentley_DgnPlatform_IEditParameterDefinitions_Add =R"doc(Creates a new parameter definition of type distance, angle, or scalar.
The value will be applied to the host model's active parameters and
any existing parameter sets. Distance values should be specified in
UORs, angles in radians, areas in square UORs

:param label:
    The user-visible name of the new parameter. Must be non-empty and
    unique within all existing parameters.

:param type:
    The type of the new parameter. Must be one of the types which is
    stored as a floating point value.

:param value:
    The initial value of the new parameter. This value will be applied
    to all variations as well.

:param hidden:
    If true, the parameter will be flagged as hidden.

:returns:
    a status Success if the parameter was successfully created, or an
    error status)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_GetParamSetValue =R"doc(Gets the parameter set value for a given parameter definition

:param def:
    The parameter definition for which the parameter set value we are
    trying to get.

:param pSet:
    The parameter set from the parameter definition for which we are
    trying to get the value.

:param sections:
    sections Identifies which sections of data are to be included in
    object creation of the ParameterCsvWriter class.

:returns:
    the value in string format.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_EvaluateExpressions =R"doc(Attempts to evaluate all expressions defined for these parameter
definitions, and assigns the result of each expression to the
corresponding parameter value in the supplied IParameterValues.

:param values:
    The values to which the result of each expression are to be
    assigned.

:returns:
    a status indicating any error which occurred during evaluation.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_WriteToCsv =R"doc(Exports these parameter definitions to a .csv file in a format which
can subsequently be imported into a parametric model.

:param file:
    The file to which the CSV is to be written

:param sections:
    Identifies which sections of data are to be included in the
    exported CSV

:returns:
    a status indicating any error which occurred while writing to the
    file.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_GetExpressionHandler =R"doc(Returns the handler responsible for parsing and deserializing
parameter expressions defined for these parameter definitions.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_IsParameterReferenced =R"doc(Returns true if the specified parameter is referenced, e.g. by
property dependencies, constraints, or expressions.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_GetForModel =R"doc(Returns the parameter definitions for the specified model, or nullptr
if the model does not support parameters.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_FindByLabel =R"doc(Attempts to retrieve the parameter definition with the specified user-
visible name)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_FindByAccessString =R"doc(Attempts to retrieve the parameter definition with the specified
internal name)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_GetParameterSortOrder =R"doc(Retrieves the sorting order of the parameter with the specified access
string, or -1 if no such parameter exists.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_GetLocalParameterCount =R"doc(Returns the number of local (" working ") parameters defined)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterDefinitions_GetDomainClass =R"doc(Returns the ECClass supplied as domain parameters, or nullptr if no
domain parameters are defined.)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterCsvSectionPresenceFlags_SetAll =R"doc(Toggles on the presence of all sections)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterCsvSectionPresenceFlags_ClearAll =R"doc(Sets to an empty state (no sections present))doc";

static const char * __doc_Bentley_DgnPlatform_ParameterCsvSectionPresenceFlags_IsEmpty =R"doc(Returns true if no sections are marked as present)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterCsvSectionPresenceFlags_SetPresent =R"doc(Toggles the presence of the specified section)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterExpressionHandler_Parse =R"doc(Attempts to parse a parameter expression string into an
IParameterExpression object.

:param input:
    The expression string to be parsed

:param context:
    The context in which the expression is to be parsed

:returns:
    a ParseParameterExpressionResult encapsulating the return status,
    details about any parse errors encountered, and the
    IParameterExpression object if parsing succeeded.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterExpression_Evaluate =R"doc(Evaluates this expression against the supplied context

:param pv:
    Holds the value of the evaluated expression, if evaluation
    succeeds

:param context:
    The context against which the expression is to be evaluated

:returns:
    ParameterStatus.Success if evaluation succeeds, or else an error
    code.)doc";

static const char * __doc_Bentley_DgnPlatform_IEvaluateParameterExpressionContext_GetParameterValues =R"doc(Returns the IParameterValues from which values of parameters within
the expression are to be obtained.)doc";

static const char * __doc_Bentley_DgnPlatform_IParseParameterExpressionContext_GetTargetAccessString =R"doc(Returns the access string of the parameter to which the parsed
expression is to be assigned, or null if no assignment is specified.)doc";

static const char * __doc_Bentley_DgnPlatform_IParseParameterExpressionContext_GetResultType =R"doc(Returns the type to which the expression is expected to resolve. The
parser will attempt to coerce the result to this type)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterExpressionContext_GetParameterDefinitions =R"doc(Returns the parameter definitions against which parsing or evaluation
is to be performed)doc";

static const char * __doc_Bentley_DgnPlatform_ParseParameterExpressionResult_GetParsedExpression =R"doc(Returns the object representing the parsed expression, if parsing was
successful)doc";

static const char * __doc_Bentley_DgnPlatform_IActiveParameters_ApplyParameters =R"doc(Applies the specified values to the active parameters)doc";

static const char * __doc_Bentley_DgnPlatform_IActiveParameters_GetDependencyRoot =R"doc(Returns the element to which property and constraint dependencies are
bound.)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_SetVariableValue =R"doc(Sets value of a parameter)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_IsCalculated =R"doc(If true, this parameter's value is calculated using an expression, and
otherwise treated as read-only)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_IsDomainParameter =R"doc(If true, this parameter originates from a pre-defined ECClass supplied
by the creator of the component.)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_SetIsHidden =R"doc(Sets whether this parameter will be hidden when the parametric model
is placed as a cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_IsHidden =R"doc(If true, when the parametric model is placed as a cell, this parameter
will not be shown as a property of the cell.)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_SetDefinitionScope =R"doc(Sets whether this parameter's value is not allowed to be overridden
when the parametric model is placed as a cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_IsDefinitionScope =R"doc(If true, when the parametric model is placed as a cell, the value of
this parameter cannot be overridden per-cell.)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_SetType =R"doc(Changes the type of this parameter.)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_GetType =R"doc(Returns the parameter type)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_GetAccessString =R"doc(Returns the internal access string which is used to refer to the
parameter in code)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_SetDisplayLabel =R"doc(Sets the user-visible parameter name)doc";

static const char * __doc_Bentley_DgnPlatform_ParameterDefinition_GetDisplayLabel =R"doc(Returns the user-visible parameter name)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSetCollection_FindByName =R"doc(Attempts to retrieve a parameter set within this collection by name)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSet_SetSortOrder =R"doc(Sets the sorting priority of this parameter set.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSet_GetSortOrder =R"doc(Returns the sorting order of this parameter set.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSet_SetDescription =R"doc(Sets the optional description of this parameter set.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSet_GetDescription =R"doc(Returns the optional description of this parameter set.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSet_SetName =R"doc(Sets the name of this parameter set. The name must be unique and non-
empty.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterSet_GetName =R"doc(Returns the name of this parameter set)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterValues_WriteValues =R"doc(Writes any changes made via SetValue() persistently)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterValues_SetValue =R"doc(Modifies the value of the specified parameter in memory. The change
does not become persistent until WriteValues() is invoked.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterValues_IsReadOnly =R"doc(Returns whether the values held by this object are read-only. If it
returns true, methods like SetValue() and WriteValues() which attempt
to modify the values will fail.)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterValues_GetValue =R"doc(Attempts to retrieve the value of a parameter by access string)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterValues_GetHostModel =R"doc(Returns the model in which the parameter values are hosted)doc";

static const char * __doc_Bentley_DgnPlatform_IParameterValues_GetProperties =R"doc(Returns these parameter values as a collection of DgnECInstances)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ParametricModeling(py::module_& m)
    {

    //===================================================================================
    // enum ByLevelSymbologyFlag
    py::enum_< ByLevelSymbologyFlag>(m, "ByLevelSymbologyFlag", py::arithmetic())
        .value("eFlagByLevel_NotDefined", FlagByLevel_NotDefined)
        .value("eFlagByLevel_IsColorByLevel", FlagByLevel_IsColorByLevel)
        .value("eFlagByLevel_IsWeightByLevel", FlagByLevel_IsWeightByLevel)
        .value("eFlagByLevel_IsLineStyleByLevel", FlagByLevel_IsLineStyleByLevel)
        .export_values();

    //===================================================================================
    // enum class ParameterStatus
    py::enum_< ParameterStatus>(m, "ParameterStatus")
        .value("eSuccess", ParameterStatus::Success)
        .value("eDuplicateName", ParameterStatus::DuplicateName)
        .value("eInvalidName", ParameterStatus::InvalidName)
        .value("eInvalidParameterDefinition", ParameterStatus::InvalidParameterDefinition)
        .value("eParameterNotFound", ParameterStatus::ParameterNotFound)
        .value("eOperationInvalidForDomainParameter", ParameterStatus::OperationInvalidForDomainParameter)
        .value("eInvalidParameterValues", ParameterStatus::InvalidParameterValues)
        .value("eParameterSetNotFound", ParameterStatus::ParameterSetNotFound)
        .value("eInvalidCellDefinition", ParameterStatus::InvalidCellDefinition)
        .value("eMismatchedTypes", ParameterStatus::MismatchedTypes)
        .value("eReadOnly", ParameterStatus::ReadOnly)
        .value("eRecursiveCellDefinition", ParameterStatus::RecursiveCellDefinition)
        .value("eError", ParameterStatus::Error)
        .export_values();
    bind_TypeWrapper<ParameterStatus>(m, "MsPyParameterStatus");

    //===================================================================================
    // enum class ParameterType
    py::enum_< ParameterType>(m, "ParameterType")
        .value("eCustom", ParameterType::Custom)
        .value("eDistance", ParameterType::Distance)
        .value("eAngle", ParameterType::Angle)
        .value("eScalar", ParameterType::Scalar)
        .value("eInteger", ParameterType::Integer)
        .value("eBoolean", ParameterType::Boolean)
        .value("eArea", ParameterType::Area)
        .value("eString", ParameterType::String)
        .value("eUnknown", ParameterType::Unknown)
        .export_values();

    //===================================================================================
    // struct ParameterValue
    py::class_< ParameterValue> c1(m, "ParameterValue");

    c1.def(py::init<>());
    
    c1.def_property_readonly("ECValue", &ParameterValue::GetECValue);
    c1.def("GetECValue", &ParameterValue::GetECValue, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("Type", &ParameterValue::GetType);
    c1.def("GetType", &ParameterValue::GetType);
    
    c1.def("IsNull", &ParameterValue::IsNull);
    c1.def("SetDistance", &ParameterValue::SetDistance, "distance"_a);
    c1.def("SetArea", &ParameterValue::SetArea, "area"_a);
    c1.def("SetAngle", &ParameterValue::SetAngle, "angle"_a);
    c1.def("SetScalar", &ParameterValue::SetScalar, "value"_a);
    c1.def("SetInteger", &ParameterValue::SetInteger, "value"_a);
    c1.def("SetBoolean", &ParameterValue::SetBoolean, "value"_a);
    c1.def("SetString", &ParameterValue::SetString, "value"_a);
    c1.def("SetCustom", &ParameterValue::SetCustom, "value"_a);
    c1.def("Clear", &ParameterValue::Clear);
    c1.def("ConvertTo", &ParameterValue::ConvertTo, "newType"_a, "dgnModel"_a);
    c1.def_static("MakeBoolean", &ParameterValue::MakeBoolean, "value"_a);
    c1.def_static("MakeInteger", &ParameterValue::MakeInteger, "value"_a);
    c1.def_static("MakeScalar", &ParameterValue::MakeScalar, "value"_a);
    c1.def_static("MakeDistance", &ParameterValue::MakeDistance, "valueInMeters"_a);
    c1.def_static("MakeArea", &ParameterValue::MakeArea, "valueInSquareMeters"_a);
    c1.def_static("MakeAngle", &ParameterValue::MakeAngle, "valueInDegrees"_a);
    c1.def_static("MakeString", &ParameterValue::MakeString, "value"_a);

    //===================================================================================
    // enum class ParameterUnits
    py::enum_< ParameterUnits>(m, "ParameterUnits")
        .value("eStorage", ParameterUnits::Storage)
        .value("eInvariant", ParameterUnits::Invariant)
        .value("eModel", ParameterUnits::Model)
        .export_values();

    //===================================================================================
    // struct IParameterValues
    py::class_< IParameterValues, std::unique_ptr< IParameterValues, py::nodelete> > c2(m, "IParameterValues");

    c2.def_property_readonly("Properties", py::overload_cast<>(&IParameterValues::GetProperties));
    c2.def("GetProperties", py::overload_cast<>(&IParameterValues::GetProperties), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IParameterValues, GetProperties));

    c2.def_property_readonly("HostModel", &IParameterValues::GetHostModel);
    c2.def("GetHostModel", &IParameterValues::GetHostModel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IParameterValues, GetHostModel));

    c2.def("GetValue", 
           py::overload_cast<ECN::ECValueR, WCharCP, ParameterUnits>(&IParameterValues::GetValue, py::const_), 
           "v"_a, "accessString"_a, "units"_a = ParameterUnits::Storage, DOC(Bentley, DgnPlatform, IParameterValues, GetValue));

    c2.def("IsReadOnly", &IParameterValues::IsReadOnly, DOC(Bentley, DgnPlatform, IParameterValues, IsReadOnly));
    c2.def("SetValue", &IParameterValues::SetValue, "accessString"_a, "value"_a, "units"_a = ParameterUnits::Storage, DOC(Bentley, DgnPlatform, IParameterValues, SetValue));
    c2.def("WriteValues", &IParameterValues::WriteValues, DOC(Bentley, DgnPlatform, IParameterValues, WriteValues));

    //===================================================================================
    // struct IParameterSet
    py::class_< IParameterSet, IParameterValues> c4(m, "IParameterSet", py::multiple_inheritance());

    c4.def_property("Name", &IParameterSet::GetName, &IParameterSet::SetName);
    c4.def("GetName", &IParameterSet::GetName, DOC(Bentley, DgnPlatform, IParameterSet, GetName));
    c4.def("SetName", &IParameterSet::SetName, "name"_a, DOC(Bentley, DgnPlatform, IParameterSet, SetName));
    
    c4.def_property("Description", &IParameterSet::GetDescription, &IParameterSet::SetDescription);
    c4.def("GetDescription", &IParameterSet::GetDescription, DOC(Bentley, DgnPlatform, IParameterSet, GetDescription));
    c4.def("SetDescription", &IParameterSet::SetDescription, "description"_a, DOC(Bentley, DgnPlatform, IParameterSet, SetDescription));
    
    c4.def_property("SortOrder", &IParameterSet::GetSortOrder, &IParameterSet::SetSortOrder);
    c4.def("GetSortOrder", &IParameterSet::GetSortOrder, DOC(Bentley, DgnPlatform, IParameterSet, GetSortOrder));
    c4.def("SetSortOrder", &IParameterSet::SetSortOrder, "order"_a, DOC(Bentley, DgnPlatform, IParameterSet, SetSortOrder));
    
    c4.def_property_readonly("DisplayLabel", &IParameterSet::GetDisplayLabel);
    c4.def("GetDisplayLabel", &IParameterSet::GetDisplayLabel);
    //===================================================================================
    // struct IParameterSetCollection
    py::class_< IParameterSetCollection, IParameterSetCollectionPtr> c5(m, "IParameterSetCollection", py::multiple_inheritance());

    c5.def("__iter__", [] (IParameterSetCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c5.def("FindByName", &IParameterSetCollection::FindByName, "name"_a, DOC(Bentley, DgnPlatform, IParameterSetCollection, FindByName));

    //===================================================================================
    // struct ParameterDefinition
    py::class_< ParameterDefinition> c6(m, "ParameterDefinition");

    c6.def(py::init<>());
    
    c6.def_property("DisplayLabel", &ParameterDefinition::GetDisplayLabel, &ParameterDefinition::SetDisplayLabel);
    c6.def("GetDisplayLabel", &ParameterDefinition::GetDisplayLabel, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParameterDefinition, GetDisplayLabel));
    c6.def("SetDisplayLabel", &ParameterDefinition::SetDisplayLabel, "label"_a, DOC(Bentley, DgnPlatform, ParameterDefinition, SetDisplayLabel));
    
    c6.def_property_readonly("AccessString", &ParameterDefinition::GetAccessString);
    c6.def("GetAccessString", &ParameterDefinition::GetAccessString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParameterDefinition, GetAccessString));
    
    c6.def_property("Type", &ParameterDefinition::GetType, &ParameterDefinition::SetType);
    c6.def("GetType", &ParameterDefinition::GetType, DOC(Bentley, DgnPlatform, ParameterDefinition, GetType));
    c6.def("SetType", &ParameterDefinition::SetType, "type"_a, DOC(Bentley, DgnPlatform, ParameterDefinition, SetType));
    
    c6.def_property("DefinitionScope", &ParameterDefinition::IsDefinitionScope, &ParameterDefinition::SetDefinitionScope);
    c6.def("IsDefinitionScope", &ParameterDefinition::IsDefinitionScope, DOC(Bentley, DgnPlatform, ParameterDefinition, IsDefinitionScope));
    c6.def("SetDefinitionScope", &ParameterDefinition::SetDefinitionScope, "value"_a, DOC(Bentley, DgnPlatform, ParameterDefinition, SetDefinitionScope));
    
    c6.def_property("Hidden", &ParameterDefinition::IsHidden, &ParameterDefinition::SetIsHidden);
    c6.def("IsHidden", &ParameterDefinition::IsHidden, DOC(Bentley, DgnPlatform, ParameterDefinition, IsHidden));
    c6.def("SetIsHidden", &ParameterDefinition::SetIsHidden, "hidden"_a, DOC(Bentley, DgnPlatform, ParameterDefinition, SetIsHidden));
    
    c6.def_property_readonly("Type", &ParameterDefinition::GetType);
    c6.def("GetType", &ParameterDefinition::GetType, DOC(Bentley, DgnPlatform, ParameterDefinition, GetType));
    
    c6.def("IsDomainParameter", &ParameterDefinition::IsDomainParameter, DOC(Bentley, DgnPlatform, ParameterDefinition, IsDomainParameter));
    c6.def("IsCalculated", &ParameterDefinition::IsCalculated, DOC(Bentley, DgnPlatform, ParameterDefinition, IsCalculated));
    c6.def("SetVariableValue", &ParameterDefinition::SetVariableValue, "dest"_a, "input"_a, "model"_a, "unitFactor"_a, DOC(Bentley, DgnPlatform, ParameterDefinition, SetVariableValue));

    //===================================================================================
    // struct IActiveParameters
    py::class_< IActiveParameters, IParameterValues> c7(m, "IActiveParameters", py::multiple_inheritance());

    c7.def_property_readonly("DependencyRoot", &IActiveParameters::GetDependencyRoot);
    c7.def("GetDependencyRoot", &IActiveParameters::GetDependencyRoot, DOC(Bentley, DgnPlatform, IActiveParameters, GetDependencyRoot));
    c7.def("ApplyParameters", &IActiveParameters::ApplyParameters, "values"_a, DOC(Bentley, DgnPlatform, IActiveParameters, ApplyParameters));

    //===================================================================================
    // enum class ParameterExpressionStatus
    py::enum_< ParameterExpressionStatus>(m, "ParameterExpressionStatus")
        .value("eSuccess", ParameterExpressionStatus::Success)
        .value("eIncompatibleType", ParameterExpressionStatus::IncompatibleType)
        .value("eIncompatibleUnits", ParameterExpressionStatus::IncompatibleUnits)
        .value("eWrongNumberOfArguments", ParameterExpressionStatus::WrongNumberOfArguments)
        .value("eDivisionByZero", ParameterExpressionStatus::DivisionByZero)
        .value("eNullValue", ParameterExpressionStatus::NullValue)
        .value("eFailedToObtainParameterValue", ParameterExpressionStatus::FailedToObtainParameterValue)
        .value("eUnexpectedEndOfInput", ParameterExpressionStatus::UnexpectedEndOfInput)
        .value("eUnknownSymbol", ParameterExpressionStatus::UnknownSymbol)
        .value("eMismatchedDelimiters", ParameterExpressionStatus::MismatchedDelimiters)
        .value("eMaxArgumentCountExceeded", ParameterExpressionStatus::MaxArgumentCountExceeded)
        .value("eFailedToParseValue", ParameterExpressionStatus::FailedToParseValue)
        .value("eCircularDependency", ParameterExpressionStatus::CircularDependency)
        .value("eFailedToAssignValue", ParameterExpressionStatus::FailedToAssignValue)
        .value("eError", ParameterExpressionStatus::Error)
        .export_values();

    //===================================================================================
    // struct ParseParameterExpressionResult
    py::class_< ParseParameterExpressionResult> c8(m, "ParseParameterExpressionResult");

    c8.def_property_readonly("ParsedExpression", py::overload_cast<>(&ParseParameterExpressionResult::GetParsedExpression));
    c8.def("GetParsedExpression", py::overload_cast<>(&ParseParameterExpressionResult::GetParsedExpression), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParseParameterExpressionResult, GetParsedExpression));

    //===================================================================================
    // struct IParameterExpressionContext
    py::class_< IParameterExpressionContext, IParameterExpressionContextPtr> c9(m, "IParameterExpressionContext");

    c9.def_property_readonly("ParameterDefinitions", &IParameterExpressionContext::GetParameterDefinitions);
    c9.def("GetParameterDefinitions", &IParameterExpressionContext::GetParameterDefinitions, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IParameterExpressionContext, GetParameterDefinitions));

    c9.def_property_readonly("HostModel", &IParameterExpressionContext::GetHostModel);
    c9.def("GetHostModel", &IParameterExpressionContext::GetHostModel, py::return_value_policy::reference_internal);

    c9.def(py::init(&IParameterExpressionContext::Create), "defs"_a);

    //===================================================================================
    // struct IParseParameterExpressionContext
    py::class_< IParseParameterExpressionContext, IParseParameterExpressionContextPtr, IParameterExpressionContext> c10(m, "IParseParameterExpressionContext");

    c10.def_property_readonly("ResultType", &IParseParameterExpressionContext::GetResultType);
    c10.def("GetResultType", &IParseParameterExpressionContext::GetResultType, DOC(Bentley, DgnPlatform, IParseParameterExpressionContext, GetResultType));

    c10.def_property_readonly("TargetAccessString", &IParseParameterExpressionContext::GetTargetAccessString);
    c10.def("GetTargetAccessString", &IParseParameterExpressionContext::GetTargetAccessString, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IParseParameterExpressionContext, GetTargetAccessString));

    c10.def_static("Create", &IParseParameterExpressionContext::Create, "defs"_a, "resultType"_a, "targetAccessString"_a = nullptr);

    //===================================================================================
    // struct IEvaluateParameterExpressionContext
    py::class_< IEvaluateParameterExpressionContext, IEvaluateParameterExpressionContextPtr, IParameterExpressionContext> c11(m, "IEvaluateParameterExpressionContext");

    c11.def_property_readonly("ParameterValues", &IEvaluateParameterExpressionContext::GetParameterValues);    
    c11.def("GetParameterValues", &IEvaluateParameterExpressionContext::GetParameterValues, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IEvaluateParameterExpressionContext, GetParameterValues));

    //===================================================================================
    // struct IParameterExpression
    py::class_< IParameterExpression, IParameterExpressionPtr> c12(m, "IParameterExpression");

    c12.def("Evaluate", &IParameterExpression::Evaluate, "pv"_a, "context"_a, DOC(Bentley, DgnPlatform, IParameterExpression, Evaluate));
    //===================================================================================
    // struct ParameterExpressionHandlerId
    py::class_< ParameterExpressionHandlerId, HandlerId> c13(m, "ParameterExpressionHandlerId");

    c13.def(py::init<>());
    c13.def(py::init<UInt16>(), "id"_a);        

    //===================================================================================
    // struct IParameterExpressionHandler
    py::class_< IParameterExpressionHandler
        , std::unique_ptr< IParameterExpressionHandler, py::nodelete>
    > c14(m, "IParameterExpressionHandler");

    c14.def("Parse", &IParameterExpressionHandler::Parse, "input"_a, "context"_a, DOC(Bentley, DgnPlatform, IParameterExpressionHandler, Parse));
    //===================================================================================
    // enum class ParameterCsvSection
    py::enum_< ParameterCsvSection>(m, "ParameterCsvSection")
        .value("eItemType", ParameterCsvSection::ItemType)
        .value("eLocalVariables", ParameterCsvSection::LocalVariables)
        .value("eExpressions", ParameterCsvSection::Expressions)
        .value("eActiveValues", ParameterCsvSection::ActiveValues)
        .value("eVariations", ParameterCsvSection::Variations)
        .value("eWorkingUnits", ParameterCsvSection::WorkingUnits)
        .value("eVisibility", ParameterCsvSection::Visibility)
        .value("eScope", ParameterCsvSection::Scope)
        .export_values();

    //===================================================================================
    // struct ParameterCsvSectionPresenceFlags
    py::class_< ParameterCsvSectionPresenceFlags> c15(m, "ParameterCsvSectionPresenceFlags");

    c15.def(py::init<>());
    c15.def(py::init<uint32_t>(), "mask"_a);
    c15.def("SetPresent", &ParameterCsvSectionPresenceFlags::SetPresent, "section"_a, "present"_a, DOC(Bentley, DgnPlatform, ParameterCsvSectionPresenceFlags, SetPresent));
    c15.def("IsEmpty", &ParameterCsvSectionPresenceFlags::IsEmpty, DOC(Bentley, DgnPlatform, ParameterCsvSectionPresenceFlags, IsEmpty));
    c15.def("ClearAll", &ParameterCsvSectionPresenceFlags::ClearAll, DOC(Bentley, DgnPlatform, ParameterCsvSectionPresenceFlags, ClearAll));
    c15.def("SetAll", &ParameterCsvSectionPresenceFlags::SetAll, DOC(Bentley, DgnPlatform, ParameterCsvSectionPresenceFlags, SetAll));
    //===================================================================================
    // struct ParameterCsvReadContext
    py::class_< ParameterCsvReadContext> c16(m, "ParameterCsvReadContext");

    c16.def(py::init<ParameterCsvSectionPresenceFlagsCR>(), "presenceFlags"_a);
    //===================================================================================
    // struct IParameterDefinitions
    py::class_< IParameterDefinitions, IActiveParameters, std::unique_ptr< IParameterDefinitions, mspydelete > > c17(m, "IParameterDefinitions");

    c17.def("__iter__", [] (IParameterDefinitions& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c17.def("GetForEdit", [] (IParameterDefinitions& self) { return IEditParameterDefinitionsPtr(self.GetForEdit()); });
    
    c17.def_property_readonly("DomainClass", &IParameterDefinitions::GetDomainClass);
    c17.def("GetDomainClass", &IParameterDefinitions::GetDomainClass, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IParameterDefinitions, GetDomainClass));
    
    c17.def_property_readonly("LocalParameterCount", &IParameterDefinitions::GetLocalParameterCount);
    c17.def("GetLocalParameterCount", &IParameterDefinitions::GetLocalParameterCount, DOC(Bentley, DgnPlatform, IParameterDefinitions, GetLocalParameterCount));
    
    c17.def("GetParameterSortOrder", &IParameterDefinitions::GetParameterSortOrder, "accessString"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, GetParameterSortOrder));
    c17.def("FindByAccessString", &IParameterDefinitions::FindByAccessString, "def"_a, "accessString"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, FindByAccessString));
    c17.def("FindByLabel", &IParameterDefinitions::FindByLabel, "def"_a, "label"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, FindByLabel));
    c17.def_static("GetForModel", &IParameterDefinitions::GetForModel, "model"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, GetForModel));
    c17.def("IsParameterReferenced", &IParameterDefinitions::IsParameterReferenced, "accessString"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, IsParameterReferenced));
    
    c17.def_property_readonly("ExpressionHandler", &IParameterDefinitions::GetExpressionHandler);
    c17.def("GetExpressionHandler", &IParameterDefinitions::GetExpressionHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IParameterDefinitions, GetExpressionHandler));

    c17.def("WriteToCsv", &IParameterDefinitions::WriteToCsv, "file"_a, "sections"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, WriteToCsv));
    c17.def("EvaluateExpressions", &IParameterDefinitions::EvaluateExpressions, "values"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, EvaluateExpressions));
    c17.def("GetParamSetValue", &IParameterDefinitions::GetParamSetValue, "def"_a, "values"_a, "sections"_a, DOC(Bentley, DgnPlatform, IParameterDefinitions, GetParamSetValue));
    //===================================================================================
    // struct IEditParameterDefinitions
    py::class_< IEditParameterDefinitions, IParameterDefinitions, std::unique_ptr< IEditParameterDefinitions, mspydelete > > c18(m, "IEditParameterDefinitions");

    c18.def("Add",
            py::overload_cast<WCharCP, ParameterType, double, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "type"_a, "value"_a, "hidden"_a = false, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, Int32, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "value"_a, "hidden"_a = false, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, bool, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "value"_a, "hidden"_a = false, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, WCharCP, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "value"_a, "hidden"_a = false, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, ParameterType, double, bool, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "type"_a, "value"_a, "hidden"_a, "isScoped"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, Int32, bool, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "value"_a, "hidden"_a, "isScoped"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, bool, bool, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "value"_a, "hidden"_a, "isScoped"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Add",
            py::overload_cast<WCharCP, WCharCP, bool, bool>(&IEditParameterDefinitions::Add),
            "label"_a, "value"_a, "hidden"_a, "isScoped"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Add));

    c18.def("Remove", &IEditParameterDefinitions::Remove, "accessString"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Remove));
    c18.def("Replace", &IEditParameterDefinitions::Replace, "def"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, Replace));
    c18.def("SetDomainParameters", &IEditParameterDefinitions::SetDomainParameters, "domainParams"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, SetDomainParameters));
    c18.def("SetExpressionForParameter", &IEditParameterDefinitions::SetExpressionForParameter, "accessString"_a, "expr"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, SetExpressionForParameter));
    c18.def("ReadFromCsv", &IEditParameterDefinitions::ReadFromCsv, "srcFile"_a, "context"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, ReadFromCsv));
    c18.def("SetParamSetValue", &IEditParameterDefinitions::SetParamSetValue, "def"_a, "values"_a, "value"_a, "unitFactor"_a, DOC(Bentley, DgnPlatform, IEditParameterDefinitions, SetParamSetValue));

    }
