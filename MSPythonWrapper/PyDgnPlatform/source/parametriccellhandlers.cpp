/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\parametriccellhandlers.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ParametricCellHandlers.h>



static const char * __doc_Bentley_DgnPlatform_ParametricCellHandler_IsAnnotation =R"doc(Returns true if this cell is an annotation. This is a property of the
cell definition.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellHandler_GetDefinitionElement =R"doc(Locates the ElementRef of the cell definition associated with a cell
instance)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellHandler_GetDefinitionID =R"doc(Extracts the ElementId of the associated cell definition from a cell
instance)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellHandler_GetCellInfo =R"doc(Extracts the ParametricCellInfo from an element)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellHandler_CreateCellElement =R"doc(Creates a new parametric cell element)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_Clone =R"doc(Clone)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_Create =R"doc(Constructs a ParametricCellInfo object to initialize a new parametric
cell element.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_Schedule =R"doc(Schedule ParametricCellInfo on a supplied element.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_SetOrigin =R"doc(Changes the origin of the cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_GetOrigin =R"doc(Returns the origin of the cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_SetRotation =R"doc(Changes the rotation of the cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_GetRotation =R"doc(Returns the rotation of the cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_SetParameterSetName =R"doc(Changes the parameter set associated with this cell, updating the
cell's parameter values to match those of the parameter set.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellInfo_GetParameterSetName =R"doc(Returns the name of the parameter set from which this cell was
created.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefHandler_GetCellDefinition =R"doc(Extracts a ParametricCellDefinition from a parametric cell definition
element)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefHandler_FindByName =R"doc(Returns the ElementRef associated with the parametric cell of the
specified name, or nullptr if no such cell exists)doc";

static const char * __doc_Bentley_DgnPlatform_IParametricCellDefEventListener__OnParametricCellDefChange =R"doc(Invoked when a parametric cell definition-related event occurs

Parameter ``before``:
    The state of the cell definition before the event, or null if this
    is a new cell definition.

Parameter ``after``:
    The state of the cell definition after the event, or null if the
    cell definition was deleted.

Parameter ``type``:
    The type of the event.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_DropEventListener =R"doc(Unregisters a listener previously registered with AddEventListener.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_AddEventListener =R"doc(Registers an object to be notified when parametric cell definition-
related events occur.)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_IsAnnotation =R"doc(Returns true if the cell definition can be placed as an annotation)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_Is3d =R"doc(Returns true if the cell is 3d)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_GetCellDescription =R"doc(Returns the description of the cell)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_GetCellName =R"doc(Returns the name of the cell, which is the same as the name of the
definition model from which it was created)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_GetParameterDefinitions =R"doc(Returns the definitions of all parameters associated with this cell
definition)doc";

static const char * __doc_Bentley_DgnPlatform_ParametricCellDefinition_GetParameterSets =R"doc(Returns the named parameter sets defined for this cell definition)doc";

//=======================================================================================
// Trampoline class for IParametricCellDefEventListener.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyParametricCellDefEventListener : IParametricCellDefEventListener
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnParametricCellDefChange(ParametricCellDefinitionCP before, ParametricCellDefinitionCP after, ParametricCellDefEventType type) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IParametricCellDefEventListener, _OnParametricCellDefChange, before, after, type); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ParametricCellHandlers(py::module_& m)
    {
    //===================================================================================
    // struct ParametricCellDefinition
    py::class_< ParametricCellDefinition, IParameterValues> c1(m, "ParametricCellDefinition", py::multiple_inheritance());

    c1.def_property_readonly("ParameterSets", &ParametricCellDefinition::GetParameterSets);
    c1.def("GetParameterSets", &ParametricCellDefinition::GetParameterSets, DOC(Bentley, DgnPlatform, ParametricCellDefinition, GetParameterSets));
    
    c1.def_property_readonly("ParameterDefinitions", &ParametricCellDefinition::GetParameterDefinitions);
    c1.def("GetParameterDefinitions", &ParametricCellDefinition::GetParameterDefinitions, DOC(Bentley, DgnPlatform, ParametricCellDefinition, GetParameterDefinitions));
    
    c1.def_property_readonly("CellName", &ParametricCellDefinition::GetCellName);
    c1.def("GetCellName", &ParametricCellDefinition::GetCellName, DOC(Bentley, DgnPlatform, ParametricCellDefinition, GetCellName));
    
    c1.def_property_readonly("CellDescription", &ParametricCellDefinition::GetCellDescription);
    c1.def("GetCellDescription", &ParametricCellDefinition::GetCellDescription, DOC(Bentley, DgnPlatform, ParametricCellDefinition, GetCellDescription));
    
    c1.def("Is3d", &ParametricCellDefinition::Is3d, DOC(Bentley, DgnPlatform, ParametricCellDefinition, Is3d));
    c1.def("IsAnnotation", &ParametricCellDefinition::IsAnnotation, DOC(Bentley, DgnPlatform, ParametricCellDefinition, IsAnnotation));
    c1.def_static("AddEventListener", &ParametricCellDefinition::AddEventListener, "listener"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, ParametricCellDefinition, AddEventListener));
    c1.def_static("DropEventListener", &ParametricCellDefinition::DropEventListener, "listener"_a, DOC(Bentley, DgnPlatform, ParametricCellDefinition, DropEventListener));

    //===================================================================================
    // struct ParametricCellDefCollection
    py::class_< ParametricCellDefCollection> c2(m, "ParametricCellDefCollection");

    c2.def(py::init<DgnFileR>(), "dgnFile"_a);
    c2.def("__iter__", [] (ParametricCellDefCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());


    //===================================================================================
    // enum class ParametricCellDefEventType
    py::enum_< DgnPlatform::ParametricCellDefEventType>(m, "ParametricCellDefEventType")
        .value("eAdd", DgnPlatform::ParametricCellDefEventType::Add)
        .value("eModify", DgnPlatform::ParametricCellDefEventType::Modify)
        .value("eDelete", DgnPlatform::ParametricCellDefEventType::Delete)
        .export_values();

    //===================================================================================
    // struct IParametricCellDefEventListener
    py::class_< IParametricCellDefEventListener, std::unique_ptr< IParametricCellDefEventListener, py::nodelete>, IPyParametricCellDefEventListener > c3(m, "IParametricCellDefEventListener");

    //c3.def(py::init<>());
    c3.def("_OnParametricCellDefChange", &IParametricCellDefEventListener::_OnParametricCellDefChange, "before"_a, "after"_a, "type"_a, DOC(Bentley, DgnPlatform, IParametricCellDefEventListener, _OnParametricCellDefChange));

    //===================================================================================
    // struct ParametricCellDefHandler
    py::class_ < ParametricCellDefHandler
        , std::unique_ptr < ParametricCellDefHandler, py::nodelete>
        , ExtendedNonGraphicsHandler
        , ITransactionHandler> c4(m, "ParametricCellDefHandler");

    c4.def("FindByName", &ParametricCellDefHandler::FindByName, "name"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParametricCellDefHandler, FindByName));
    c4.def("GetCellDefinition", &ParametricCellDefHandler::GetCellDefinition, "cellDefEh"_a, DOC(Bentley, DgnPlatform, ParametricCellDefHandler, GetCellDefinition));
    //===================================================================================
    // struct ParametricCellInfo
    py::class_< ParametricCellInfo, IParameterValues> c5(m, "ParametricCellInfo", py::multiple_inheritance());

    c5.def_property("ParameterSetName", &ParametricCellInfo::GetParameterSetName, &ParametricCellInfo::SetParameterSetName);
    c5.def("GetParameterSetName", &ParametricCellInfo::GetParameterSetName, DOC(Bentley, DgnPlatform, ParametricCellInfo, GetParameterSetName));
    c5.def("SetParameterSetName", &ParametricCellInfo::SetParameterSetName, "name"_a, DOC(Bentley, DgnPlatform, ParametricCellInfo, SetParameterSetName));
    
    c5.def_property("Rotation", &ParametricCellInfo::GetRotation, &ParametricCellInfo::SetRotation);
    c5.def("GetRotation", &ParametricCellInfo::GetRotation, DOC(Bentley, DgnPlatform, ParametricCellInfo, GetRotation));
    c5.def("SetRotation", &ParametricCellInfo::SetRotation, "rot"_a, DOC(Bentley, DgnPlatform, ParametricCellInfo, SetRotation));
    
    c5.def_property("Origin", &ParametricCellInfo::GetOrigin, &ParametricCellInfo::SetOrigin);
    c5.def("GetOrigin", &ParametricCellInfo::GetOrigin, DOC(Bentley, DgnPlatform, ParametricCellInfo, GetOrigin));
    c5.def("SetOrigin", &ParametricCellInfo::SetOrigin, "origin"_a, DOC(Bentley, DgnPlatform, ParametricCellInfo, SetOrigin));
    
    c5.def_property_readonly("CellDefinition", [] (ParametricCellInfo const& self) { return ParametricCellDefinitionPtr(const_cast<ParametricCellDefinitionP>(&self.GetCellDefinition())); });
    c5.def("GetCellDefinition", [] (ParametricCellInfo const& self) { return ParametricCellDefinitionPtr(const_cast<ParametricCellDefinitionP>(&self.GetCellDefinition())); });

    c5.def("Schedule", &ParametricCellInfo::Schedule, "eeh"_a, DOC(Bentley, DgnPlatform, ParametricCellInfo, Schedule));
    
    c5.def_static("Create", [] (ParametricCellDefinitionR cellDef, WCharCP parameterSetName, DgnModelR placementModel)
                  {
                  ParameterStatus status = ParameterStatus::Error;
                  auto retVal = ParametricCellInfo::Create(status, cellDef, parameterSetName, placementModel);
                  return py::make_tuple(retVal, status);
                  }, "cellDef"_a, "parameterSetName"_a, "placementModel"_a, DOC(Bentley, DgnPlatform, ParametricCellInfo, Create));

    c5.def("Clone", [] (ParametricCellInfo const& self)
           {
           ParameterStatus status = ParameterStatus::Error;
           auto retVal = self.Clone(status);
           return py::make_tuple(retVal, status);
           }, DOC(Bentley, DgnPlatform, ParametricCellInfo, Clone));

    //===================================================================================
    // struct ParametricCellHandler
    py::class_< ParametricCellHandler, std::unique_ptr< ParametricCellHandler, py::nodelete>, ExtendedElementHandler, IAnnotationHandler> c6(m, "ParametricCellHandler");

    c6.def("CreateCellElement", 
           py::overload_cast<EditElementHandleR, ParametricCellInfoCR>(&ParametricCellHandler::CreateCellElement),
           "cellEeh"_a, "cellInfo"_a, DOC(Bentley, DgnPlatform, ParametricCellHandler, CreateCellElement));

    c6.def("GetCellInfo", [] (ParametricCellHandler& self, ElementHandleCR eh)
           {
           ParameterStatus status = ParameterStatus::Error;
           auto retVal = self.GetCellInfo(status, eh);
           return py::make_tuple(retVal, status);
           }, "eh"_a, DOC(Bentley, DgnPlatform, ParametricCellHandler, GetCellInfo));

    c6.def("GetDefinitionID", [] (ParametricCellHandler& self, ElementHandleCR cellEh)
           {
           ElementId definitionId = INVALID_ELEMENTID;
           auto retVal = self.GetDefinitionID(definitionId, cellEh);
           return py::make_tuple(retVal, definitionId);
           }, "cellEh"_a, DOC(Bentley, DgnPlatform, ParametricCellHandler, GetDefinitionID));

    c6.def("GetDefinitionElement", &ParametricCellHandler::GetDefinitionElement, "cellEh"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ParametricCellHandler, GetDefinitionElement));
    c6.def("IsAnnotation", &ParametricCellHandler::IsAnnotation, "eh"_a, DOC(Bentley, DgnPlatform, ParametricCellHandler, IsAnnotation));

    }