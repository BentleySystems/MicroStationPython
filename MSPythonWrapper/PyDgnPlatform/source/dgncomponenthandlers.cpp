/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgncomponenthandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnComponentHandlers.h>



static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionModelHandler_InitializeRemapTable =R"doc(Initializes a table of remappings between current and updated
parameter set and parameter definition names, used when updating a
parametric cell definition

Parameter ``remapTable``:
    The table which will be initialized with default remappings

Parameter ``cellDef``:
    The existing parametric cell definition which is to be updated.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionModelHandler_UpdateCellDefinition =R"doc(Updates the parametric cell definition having the same name as this
handler's model in the specified DgnFile to match the current state of
the definition model.

Parameter ``targetFile``:
    The DgnFile containing the cell definition to be updated

Parameter ``remapTable``:
    Indicates how to remap names of parameter sets and parameter
    definitions between the previous and updated cell definitions

Returns:
    Success if the cell definition and all cell instances were
    updated, or else an error code)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionModelHandler_CreateCellDefinition =R"doc(Creates a parametric cell definition element (and associated hidden
cell model) from this handler's model in the specified DgnFile.

Parameter ``targetFile``:
    The DgnFile in which to create the parametric cell definition

Returns:
    Success if the cell definition was created, or else an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionModelHandler_DeleteParameterSet =R"doc(Deletes the specified parameter set

Parameter ``parameterSet``:
    The parameter set to delete

Returns:
    Success if the parameter set was deleted, or else an error code)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionModelHandler_CreateParameterSet =R"doc(Creates a new parameter set

Parameter ``parameterSet``:
    Holds the created parameter set.

Parameter ``name``:
    The name of the new parameter set. Must be non-empty and unique
    within all existing parameter sets.

Parameter ``description``:
    The description of the new parameter set, or null if no
    description is desired.

Parameter ``values``:
    The initial values of all parameters for the new parameter set.
    The values must come from this handler's DgnModel.

Returns:
    Success if the parameter set was created, or else an error code.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellRemapTable_Clear =R"doc(Clears all parameter set and parameter definition remappings.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellRemapTable_RemapVariable =R"doc(Specifies a remapping from an old parameter definition name to a new
name.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellRemapTable_RemapParameterSet =R"doc(Specifies a remapping from an old parameter set name to a new name.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellRemapTable_ResolveVariable =R"doc(Looks up the remapped name of a parameter definition.

Parameter ``oldVariableAccessString``:
    The previous internal name of the parameter definition

Returns:
    the new name, or null if the old name could not be remapped.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellRemapTable_ResolveParameterSet =R"doc(Looks up the remapped name of a parameter set.

Parameter ``oldParameterSetName``:
    The previous name of the parameter set.

Returns:
    the new name, or null if the old name could not be remapped.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionHandler_GetDefinitionModelHandler =R"doc(If the model managed by this handler can serve as a " definition model "
for parametric modeling purposes, returns a handler which exposes that
functionality; or else returns null.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionHandler_GetParameterSets =R"doc(Returns a collection of all parameter sets defined for the model
managed by this handler.)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnComponentDefinitionHandler_GetParameterDefinitions =R"doc(Returns the parameter definitions associated with the model managed by
this handler.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnComponentHandlers(py::module_& m)
    {
    //===================================================================================
    // struct IDgnComponentDefinitionHandler
    py::class_< IDgnComponentDefinitionHandler> c1(m, "IDgnComponentDefinitionHandler");

    c1.def_property_readonly("ParameterDefinitions", &IDgnComponentDefinitionHandler::GetParameterDefinitions);
    c1.def("GetParameterDefinitions", &IDgnComponentDefinitionHandler::GetParameterDefinitions, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionHandler, GetParameterDefinitions));

    c1.def_property_readonly("ParameterSets", &IDgnComponentDefinitionHandler::GetParameterSets);
    c1.def("GetParameterSets", &IDgnComponentDefinitionHandler::GetParameterSets, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionHandler, GetParameterSets));

    c1.def_property_readonly("DefinitionModelHandler", &IDgnComponentDefinitionHandler::GetDefinitionModelHandler);
    c1.def("GetDefinitionModelHandler", &IDgnComponentDefinitionHandler::GetDefinitionModelHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionHandler, GetDefinitionModelHandler));

    //===================================================================================
    // struct ParametricCellRemapTable
    py::class_< ParametricCellRemapTable> c2(m, "ParametricCellRemapTable");

    c2.def("ResolveParameterSet", &ParametricCellRemapTable::ResolveParameterSet, "oldParameterSetName"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParametricCellRemapTable, ResolveParameterSet));
    c2.def("ResolveVariable", &ParametricCellRemapTable::ResolveVariable, "oldVariableAccessString"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParametricCellRemapTable, ResolveVariable));
    c2.def("RemapParameterSet", &ParametricCellRemapTable::RemapParameterSet, "remapFrom"_a, "remapTo"_a, DOC(Bentley, DgnPlatform, ParametricCellRemapTable, RemapParameterSet));
    c2.def("RemapVariable", &ParametricCellRemapTable::RemapVariable, "remapFromAccessString"_a, "remapToAccessString"_a, DOC(Bentley, DgnPlatform, ParametricCellRemapTable, RemapVariable));
    c2.def("Clear", &ParametricCellRemapTable::Clear, DOC(Bentley, DgnPlatform, ParametricCellRemapTable, Clear));    

    //===================================================================================
    // enum class UpdateParametricCellDefStatus
    py::enum_< UpdateParametricCellDefStatus>(m, "UpdateParametricCellDefStatus")
        .value("eSuccess", UpdateParametricCellDefStatus::Success)
        .value("eSchemasDiffer", UpdateParametricCellDefStatus::SchemasDiffer)
        .value("eReadOnly", UpdateParametricCellDefStatus::ReadOnly)
        .value("eCellNotFound", UpdateParametricCellDefStatus::CellNotFound)
        .value("eError", UpdateParametricCellDefStatus::Error)
        .export_values();

    //===================================================================================
    // struct IDgnComponentDefinitionModelHandler
    py::class_< IDgnComponentDefinitionModelHandler, IDgnComponentDefinitionHandler> c3(m, "IDgnComponentDefinitionModelHandler");

    c3.def("CreateParameterSet", [] (IDgnComponentDefinitionModelHandler const& self, WCharCP name, WCharCP description, IParameterValuesCR values)
           {
           IParameterSetPtr parameterSet;
           auto retVal = self.CreateParameterSet(parameterSet, name, description, values);
           return py::make_tuple(retVal, parameterSet);
           }, "name"_a, "description"_a, "values"_a, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionModelHandler, CreateParameterSet));

    c3.def("DeleteParameterSet", &IDgnComponentDefinitionModelHandler::DeleteParameterSet, "parameterSet"_a, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionModelHandler, DeleteParameterSet));
    c3.def("CreateCellDefinition", &IDgnComponentDefinitionModelHandler::CreateCellDefinition, "targetFile"_a, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionModelHandler, CreateCellDefinition));
    c3.def("UpdateCellDefinition", &IDgnComponentDefinitionModelHandler::UpdateCellDefinition, "targetFile"_a, "remapTable"_a, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionModelHandler, UpdateCellDefinition));
    c3.def("InitializeRemapTable", &IDgnComponentDefinitionModelHandler::InitializeRemapTable, "remapTable"_a, "cellDef"_a, DOC(Bentley, DgnPlatform, IDgnComponentDefinitionModelHandler, InitializeRemapTable));
    }