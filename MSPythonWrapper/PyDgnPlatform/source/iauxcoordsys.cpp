/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\iauxcoordsys.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/IAuxCoordSys.h>



static const char * __doc_Bentley_DgnPlatform_IACSManager_DropListener =R"doc(Drop a listener for acs events.)doc";

static const char * __doc_Bentley_DgnPlatform_IACSManager_AddListener =R"doc(Add a listener for acs events.)doc";

static const char * __doc_Bentley_DgnPlatform_IACSEvents__OnACSEvent =R"doc(Called when a particular ACS event occurs.)doc";

//=======================================================================================
// Trampoline class for IACSTraversalHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyACSTraversalHandler : IACSTraversalHandler
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual UInt32 _GetACSTraversalOptions() override
        { PYBIND11_OVERRIDE_PURE_EXR(UInt32, IACSTraversalHandler, _GetACSTraversalOptions, 0, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool _HandleACSTraversal(IAuxCoordSysR acs) override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IACSTraversalHandler, _HandleACSTraversal, false, acs); }
    };


//=======================================================================================
// Trampoline class for IACSEvents.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyACSEvents : IACSEvents
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual void _OnACSEvent(IAuxCoordSysP acs, ACSEventType eventType, DgnModelRefP modelRef) override
        { PYBIND11_OVERRIDE_PURE_EX(void, IACSEvents, _OnACSEvent, acs, eventType, modelRef); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IAuxCoordSys(py::module_& m)
    {
    //===================================================================================
    // enum class ACSType
    py::enum_< ACSType>(m, "ACSType")
        .value("eNone", ACSType::None)
        .value("eRectangular", ACSType::Rectangular)
        .value("eCylindrical", ACSType::Cylindrical)
        .value("eSpherical", ACSType::Spherical)
        .value("eExtended", ACSType::Extended)
        .export_values();

    //===================================================================================
    // enum class ACSSaveOptions
    py::enum_< ACSSaveOptions>(m, "ACSSaveOptions")
        .value("eOverwriteByElemId", ACSSaveOptions::OverwriteByElemId)
        .value("eOverwriteByName", ACSSaveOptions::OverwriteByName)
        .value("eAllowNew", ACSSaveOptions::AllowNew)
        .export_values();

    //===================================================================================
    // enum class ACSEventType
    py::enum_< ACSEventType>(m, "ACSEventType")
        .value("eNone", ACSEventType::None)
        .value("eParameterChanged", ACSEventType::ParameterChanged)
        .value("eGeometryChanged", ACSEventType::GeometryChanged)
        .value("eChangeWritten", ACSEventType::ChangeWritten)
        .value("eNewACS", ACSEventType::NewACS)
        .value("eDelete", ACSEventType::Delete)
        .export_values();

    //===================================================================================
    // enum class ACSDisplayOptions
    py::enum_< ACSDisplayOptions>(m, "ACSDisplayOptions")
        .value("eNone", ACSDisplayOptions::None)
        .value("eInactive", ACSDisplayOptions::Inactive)
        .value("eActive", ACSDisplayOptions::Active)
        .value("eHilite", ACSDisplayOptions::Hilite)
        .value("eDeemphasized", ACSDisplayOptions::Deemphasized)
        .value("eCheckVisible", ACSDisplayOptions::CheckVisible)
        .export_values();

    //===================================================================================
    // enum class ACSFlags
    py::enum_< ACSFlags>(m, "ACSFlags")
        .value("eNone", ACSFlags::None)
        .value("eDefault", ACSFlags::Default)
        .value("eViewIndependent", ACSFlags::ViewIndependent)
        .export_values();

    //===================================================================================
    // struct IACSTraversalHandler
    py::class_< IACSTraversalHandler, std::unique_ptr< IACSTraversalHandler, py::nodelete>, IPyACSTraversalHandler> c1(m, "IACSTraversalHandler");

    c1.def(py::init<>());
    c1.def("_GetACSTraversalOptions", &IACSTraversalHandler::_GetACSTraversalOptions);
    c1.def("_HandleACSTraversal", &IACSTraversalHandler::_HandleACSTraversal, "acs"_a);

    //===================================================================================
    // struct IACSEvents
    py::class_< IACSEvents, std::unique_ptr< IACSEvents, py::nodelete>, IPyACSEvents> c3(m, "IACSEvents");

    c3.def(py::init<>());
    c3.def("_OnACSEvent", &IACSEvents::_OnACSEvent, "acs"_a, "eventType"_a, "modelRef"_a, DOC(Bentley, DgnPlatform, IACSEvents, _OnACSEvent));

    //===================================================================================
    // struct IACSManager
    py::class_< IACSManager, std::unique_ptr< IACSManager, py::nodelete>, DgnHost::IHostObject> c4(m, "IACSManager");


    c4.def("AddListener", &IACSManager::AddListener, "acsListener"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, IACSManager, AddListener));
    c4.def("DropListener", &IACSManager::DropListener, "acsListener"_a, DOC(Bentley, DgnPlatform, IACSManager, DropListener));
    c4.def("CreateACS", py::overload_cast<>(&IACSManager::CreateACS));
    c4.def("GetActive", &IACSManager::GetActive, "vp"_a, py::return_value_policy::reference_internal);
    c4.def("SetActive", &IACSManager::SetActive, "auxCoordSys"_a, "vp"_a);
    c4.def("GetByName", &IACSManager::GetByName, "name"_a, "modelRef"_a, "options"_a);
    c4.def("Traverse", &IACSManager::Traverse, "handler"_a, "modelRef"_a);
    c4.def("Save", &IACSManager::Save, "auxCoordSys"_a, "modelRef"_a, "saveOptions"_a, "eventType"_a);
    c4.def("Delete", &IACSManager::Delete, "name"_a, "modelRef"_a);
    c4.def_static("GetManager", &IACSManager::GetManager, py::return_value_policy::reference);

    //===================================================================================
    // struct IAuxCoordSys
    py::class_< IAuxCoordSys
        , IAuxCoordSysPtr
    > c5(m, "IAuxCoordSys");


    c5.def("Clone", &IAuxCoordSys::Clone);
    c5.def("Equals", &IAuxCoordSys::Equals, "other"_a);
    
    c5.def_property("Name", &IAuxCoordSys::GetName, &IAuxCoordSys::SetName);
    c5.def("GetName", &IAuxCoordSys::GetName);
    c5.def("SetName", &IAuxCoordSys::SetName, "name"_a);
    
    c5.def_property("Description", &IAuxCoordSys::GetDescription, &IAuxCoordSys::SetDescription);
    c5.def("GetDescription", &IAuxCoordSys::GetDescription);
    c5.def("SetDescription", &IAuxCoordSys::SetDescription, "descr"_a);
    
    c5.def_property("Type", &IAuxCoordSys::GetType, &IAuxCoordSys::SetType);
    c5.def("GetType", &IAuxCoordSys::GetType);
    c5.def("SetType", &IAuxCoordSys::SetType, "type"_a);
    
    c5.def_property_readonly("TypeName", &IAuxCoordSys::GetTypeName);
    c5.def("GetTypeName", &IAuxCoordSys::GetTypeName);
    
    c5.def_property("Scale", &IAuxCoordSys::GetScale, &IAuxCoordSys::SetScale);
    c5.def("GetScale", &IAuxCoordSys::GetScale);
    c5.def("SetScale", &IAuxCoordSys::SetScale, "scale"_a);
    
    c5.def_property("Origin", &IAuxCoordSys::GetOrigin, &IAuxCoordSys::SetOrigin);
    c5.def("GetOrigin", &IAuxCoordSys::GetOrigin, "pOrigin"_a);
    c5.def("SetOrigin", &IAuxCoordSys::SetOrigin, "pOrigin"_a);
    c5.def("GetRotation", py::overload_cast<RotMatrixR>(&IAuxCoordSys::GetRotation, py::const_), "pRot"_a);
    c5.def_property_readonly("IsReadOnly", &IAuxCoordSys::GetIsReadOnly);
    c5.def("GetIsReadOnly", &IAuxCoordSys::GetIsReadOnly);

    c5.def_property("Flags", &IAuxCoordSys::GetFlags, &IAuxCoordSys::SetFlags);
    c5.def("GetFlags", &IAuxCoordSys::GetFlags);
    c5.def("SetFlags", &IAuxCoordSys::SetFlags, "flags"_a);

    c5.def("SetRotation", &IAuxCoordSys::SetRotation, "pRot"_a);
    c5.def("PointFromString", &IAuxCoordSys::PointFromString, "outPoint"_a, "errorMsg"_a, "inString"_a, "relative"_a, "lastPoint"_a, "modelRef"_a);
    c5.def("StringFromPoint", &IAuxCoordSys::StringFromPoint, "outPoint"_a, "errorMsg"_a, "inPoint"_a, "delta"_a, "deltaOrigin"_a, "modelRef"_a, "distanceFormatter"_a, "directionFormatter"_a);
    c5.def("SaveToFile", &IAuxCoordSys::SaveToFile, "modelRef"_a, "option"_a);
    c5.def("DeleteFromFile", &IAuxCoordSys::DeleteFromFile, "modelRef"_a);
    }