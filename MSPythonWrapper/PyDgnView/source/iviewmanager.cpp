/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\iviewmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/IViewManager.h>
#include <DgnPlatform/QvViewport.h>



static const char * __doc_Bentley_DgnPlatform_IViewManager_AddViewDecoration =R"doc(@name Viewport Event Handlers)doc";

static const char * __doc_Bentley_DgnPlatform_IViewManager_GetCurrentViewNumber =R"doc(Return the index of the active viewport)doc";

static const char * __doc_Bentley_DgnPlatform_StopEvents_SetStopOnModifierKey =R"doc(Stop when the ctrl or shift key is pressed or released. )doc";

//=======================================================================================
// Publicist class for IViewDecoration.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IViewDecorationPub : IViewDecoration
    {
    public:
        using IViewDecoration::_DrawDecoration;
    };

//=======================================================================================
// Trampoline class for IViewDecoration.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyViewDecoration : IViewDecoration
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DrawDecoration(IndexedViewportR viewport) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, IViewDecoration, _DrawDecoration, false, viewport); }
    };


//=======================================================================================
// Publicist class for IModelTransientHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IModelTransientHandlerPub : IModelTransientHandler
    {
    public:
        using IModelTransientHandler::_DrawModelTransients;
    };

//=======================================================================================
// Trampoline class for IModelTransientHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyModelTransientHandler : IModelTransientHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DrawModelTransients(ViewContextR context, DgnModelRefR modelRef, ModelTransientPurpose purpose, void*& displayListUserData) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_DrawModelTransients");
                if (func)
                    {
                    auto obj = func(context, modelRef, purpose, py::capsule(displayListUserData));
                    auto holder = obj.cast <py::capsule>();
                    displayListUserData = holder.get_pointer();
                    }
                else
                    pybind11::pybind11_fail("Tried to call pure virtual function IModelTransientHandler::_DrawModelTransients");
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);                
                }
            }
    };

//=======================================================================================
// Publicist class for IViewMonitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IViewMonitorPub : IViewMonitor
    {
    public:
        using IViewMonitor::_OnViewChanged;
        using IViewMonitor::_OnViewOpen;
        using IViewMonitor::_OnViewClose;
        using IViewMonitor::_OnGetViewTitle;
        using IViewMonitor::_OnViewEnterOrExit;
        using IViewMonitor::_OnViewChangeJournalled;
    };

//=======================================================================================
// Trampoline class for IViewMonitor.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyViewMonitor : IViewMonitor
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnViewChanged(ViewportP viewport) override
            { PYBIND11_OVERRIDE_EX(void, IViewMonitor, _OnViewChanged, viewport); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnViewOpen(ViewportP viewport) override
            { PYBIND11_OVERRIDE_EX(void, IViewMonitor, _OnViewOpen, viewport); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnViewClose(ViewportP viewport) override
            { PYBIND11_OVERRIDE_EX(void, IViewMonitor, _OnViewClose, viewport); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnGetViewTitle(ViewportP viewport, WStringR title) override
            { PYBIND11_OVERRIDE_EX(void, IViewMonitor, _OnGetViewTitle, viewport, title); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnViewEnterOrExit(ViewportP viewport, int changeType) override
            { PYBIND11_OVERRIDE_EX(void, IViewMonitor, _OnViewEnterOrExit, viewport, changeType); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnViewChangeJournalled(ViewportP viewport, ViewChangeType changeType) override
            { PYBIND11_OVERRIDE_EX(void, IViewMonitor, _OnViewChangeJournalled, viewport, changeType); }
    };

//=======================================================================================
// Publicist class for IndexedViewport.
// @bsiclass                                                    
//=======================================================================================
struct IndexedViewportPub : IndexedViewport
    {
    };


//=======================================================================================
// Publicist class for IndexedViewSet.
// @bsiclass                                                  
//=======================================================================================
struct IndexedViewSetPub : IndexedViewSet
    {
    };
/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IViewManager(py::module_& m)
    {
    //===================================================================================
    // struct StopEvents
    py::class_< StopEvents> c1(m, "StopEvents");

    c1.def_property("keystrokes",
                    [] (StopEvents const& self) { return (bool) self.m_keystrokes; },
                    [] (StopEvents& self, bool newVal) { self.m_keystrokes = newVal; });

    c1.def_property("controlC",
                    [] (StopEvents const& self) { return (bool) self.m_controlC; },
                    [] (StopEvents& self, bool newVal) { self.m_controlC = newVal; });

    c1.def_property("wheel",
                    [] (StopEvents const& self) { return (bool) self.m_wheel; },
                    [] (StopEvents& self, bool newVal) { self.m_wheel = newVal; });

    c1.def_property("button",
                    [] (StopEvents const& self) { return (bool) self.m_button; },
                    [] (StopEvents& self, bool newVal) { self.m_button = newVal; });

    c1.def_property("paint",
                    [] (StopEvents const& self) { return (bool) self.m_paint; },
                    [] (StopEvents& self, bool newVal) { self.m_paint = newVal; });

    c1.def_property("focus",
                    [] (StopEvents const& self) { return (bool) self.m_focus; },
                    [] (StopEvents& self, bool newVal) { self.m_focus = newVal; });

    c1.def_property("modifierKeyTransition",
                    [] (StopEvents const& self) { return (bool) self.m_modifierKeyTransition; },
                    [] (StopEvents& self, bool newVal) { self.m_modifierKeyTransition = newVal; });

    c1.def("Clear", &StopEvents::Clear);
    c1.def(py::init<bool, bool, bool, bool, bool, bool>(), "keystrokes"_a, "controlC"_a, "wheel"_a, "button"_a, "paint"_a, "focus"_a);
    c1.def("SetStopOnModifierKey", &StopEvents::SetStopOnModifierKey, "stop"_a, DOC(Bentley, DgnPlatform, StopEvents, SetStopOnModifierKey));

    //===================================================================================
    // struct IViewDecoration
    py::class_< IViewDecoration, std::unique_ptr<IViewDecoration, py::nodelete>, IPyViewDecoration> c2(m, "IViewDecoration");

    c2.def(py::init<>());
    c2.def("_DrawDecoration", &IViewDecorationPub::_DrawDecoration, "viewport"_a);

    //===================================================================================
    // struct IModelTransientHandler
    py::class_< IModelTransientHandler, std::unique_ptr<IModelTransientHandler, py::nodelete>, IPyModelTransientHandler> c3(m, "IModelTransientHandler");

    if (true)
        {
        //===================================================================================
        // enum ModelTransientPurpose
        py::enum_< IModelTransientHandler::ModelTransientPurpose>(c3, "ModelTransientPurpose")
            .value("eModelTransientPurpose_Normal", IModelTransientHandler::ModelTransientPurpose_Normal)
            .value("eModelTransientPurpose_PreDisplayList", IModelTransientHandler::ModelTransientPurpose_PreDisplayList)
            .value("eModelTransientPurpose_PostDisplayList", IModelTransientHandler::ModelTransientPurpose_PostDisplayList)
            .export_values();
        }

    c3.def(py::init<>());
    c3.def("_DrawModelTransients", [] (IModelTransientHandler& self, ViewContextR context, DgnModelRefR modelRef, IModelTransientHandler::ModelTransientPurpose purpose, py::capsule const& displayListUserData)
           {
           void* userData = displayListUserData.get_pointer();
           static_cast<IModelTransientHandlerPub&>(self)._DrawModelTransients(context, modelRef, purpose, userData);
           return py::capsule(userData);
           }, "context"_a, "modelRef"_a, "purpose"_a, "displayListUserData"_a);

    //===================================================================================
    // struct IViewMonitor
    py::class_< IViewMonitor, IPyViewMonitor> c4(m, "IViewMonitor");

    c4.def(py::init<>());
    c4.def("_OnViewChanged", &IViewMonitorPub::_OnViewChanged, "viewport"_a);
    c4.def("_OnViewOpen", &IViewMonitorPub::_OnViewOpen, "viewport"_a);
    c4.def("_OnViewClose", &IViewMonitorPub::_OnViewClose, "viewport"_a);
    c4.def("_OnGetViewTitle", &IViewMonitorPub::_OnGetViewTitle, "viewport"_a, "title"_a);
    c4.def("_OnViewEnterOrExit", &IViewMonitorPub::_OnViewEnterOrExit, "viewport"_a, "changeType"_a);
    c4.def("_OnViewChangeJournalled", &IViewMonitorPub::_OnViewChangeJournalled, "viewport"_a, "changeType"_a);

    //===================================================================================
    // enum UpdateAbortReason
    py::enum_< UpdateAbortReason>(m, "UpdateAbortReason")
        .value("eUPDATE_ABORT_None", UPDATE_ABORT_None)
        .value("eUPDATE_ABORT_BadView", UPDATE_ABORT_BadView)
        .value("eUPDATE_ABORT_Motion", UPDATE_ABORT_Motion)
        .value("eUPDATE_ABORT_MotionStopped", UPDATE_ABORT_MotionStopped)
        .value("eUPDATE_ABORT_Keystroke", UPDATE_ABORT_Keystroke)
        .value("eUPDATE_ABORT_ControlC", UPDATE_ABORT_ControlC)
        .value("eUPDATE_ABORT_MouseWheel", UPDATE_ABORT_MouseWheel)
        .value("eUPDATE_ABORT_Timeout", UPDATE_ABORT_Timeout)
        .value("eUPDATE_ABORT_Button", UPDATE_ABORT_Button)
        .value("eUPDATE_ABORT_Paint", UPDATE_ABORT_Paint)
        .value("eUPDATE_ABORT_Focus", UPDATE_ABORT_Focus)
        .value("eUPDATE_ABORT_ModifierKey", UPDATE_ABORT_ModifierKey)
        .export_values();

    //===================================================================================
    // struct RefCounted<QvViewport>
    using QvViewportRef = RefCounted<QvViewport>;
    py::class_< QvViewportRef, std::unique_ptr<QvViewportRef, py::nodelete>, QvViewport> c4x(m, "QvViewportRef");

    //===================================================================================
    // struct IndexedViewport
    py::class_< IndexedViewport, RefCounted<QvViewport>> c5(m, "IndexedViewport");

    //===================================================================================
    // struct IndexedViewSet
    py::class_< IndexedViewSet> c6(m, "IndexedViewSet");


    if (true)
        {
        //===================================================================================
        // struct FullUpdateInfo
        py::class_< IndexedViewSet::FullUpdateInfo> c6_1(c6, "FullUpdateInfo");

        c6_1.def(py::init<>());
        c6_1.def("SetStopEvents", &IndexedViewSet::FullUpdateInfo::SetStopEvents, "stopEvents"_a);
        c6_1.def("SetIncludeList", &IndexedViewSet::FullUpdateInfo::SetIncludeList, "includeList"_a, py::keep_alive<1, 2>());
        
        c6_1.def_property("Incremental", &IndexedViewSet::FullUpdateInfo::GetIncremental, &IndexedViewSet::FullUpdateInfo::SetIncremental);
        c6_1.def("GetIncremental", &IndexedViewSet::FullUpdateInfo::GetIncremental);
        c6_1.def("SetIncremental", &IndexedViewSet::FullUpdateInfo::SetIncremental, "incremental"_a);
        
        c6_1.def("SetDeferShadows", &IndexedViewSet::FullUpdateInfo::SetDeferShadows, "deferShadows"_a);
        
        c6_1.def_property("StartEndMsg", &IndexedViewSet::FullUpdateInfo::GetStartEndMsg, &IndexedViewSet::FullUpdateInfo::SetStartEndMsg);
        c6_1.def("GetStartEndMsg", &IndexedViewSet::FullUpdateInfo::GetStartEndMsg);
        c6_1.def("SetStartEndMsg", &IndexedViewSet::FullUpdateInfo::SetStartEndMsg, "startEndMsg"_a);
        
        c6_1.def("SetStartAbortState", &IndexedViewSet::FullUpdateInfo::SetStartAbortState, "state"_a);
        c6_1.def("SetUseCachedElems", &IndexedViewSet::FullUpdateInfo::SetUseCachedElems, "useCacheElems"_a);
        c6_1.def("SetSubRect", &IndexedViewSet::FullUpdateInfo::SetSubRect, "subRect"_a);
        c6_1.def("SetFenceParams", &IndexedViewSet::FullUpdateInfo::SetFenceParams, "fp"_a, py::keep_alive<1, 2>());

        //===================================================================================
        // struct DynamicUpdateInfo
        py::class_< IndexedViewSet::DynamicUpdateInfo> c6_2(c6, "DynamicUpdateInfo");

        c6_2.def(py::init<>());
        c6_2.def_property_readonly("LastCursorPos", &IndexedViewSet::DynamicUpdateInfo::GetLastCursorPos);
        c6_2.def("GetLastCursorPos", &IndexedViewSet::DynamicUpdateInfo::GetLastCursorPos, py::return_value_policy::reference_internal);

        c6_2.def("ClearLastMotion", &IndexedViewSet::DynamicUpdateInfo::ClearLastMotion);
        c6_2.def("SetStopEvents", &IndexedViewSet::DynamicUpdateInfo::SetStopEvents, "stopEvents"_a);
        c6_2.def("SetIncludeList", &IndexedViewSet::DynamicUpdateInfo::SetIncludeList, "includeList"_a, py::keep_alive<1, 2>());
        c6_2.def("SetDoBackingStore", &IndexedViewSet::DynamicUpdateInfo::SetDoBackingStore, "doBackingStore"_a);
        c6_2.def("SetDeferShadows", &IndexedViewSet::DynamicUpdateInfo::SetDeferShadows, "deferShadows"_a);
        c6_2.def("SetMaxFrameTime", &IndexedViewSet::DynamicUpdateInfo::SetMaxFrameTime, "maxFrameTime"_a);
        c6_2.def("SetMinLODDelta", &IndexedViewSet::DynamicUpdateInfo::SetMinLODDelta, "minLodDelta"_a);
        c6_2.def("SetDynamicsStopInterval", &IndexedViewSet::DynamicUpdateInfo::SetDynamicsStopInterval, "dynamicsStopInterval"_a);
        c6_2.def("SetDynamicsMotionTolerance", &IndexedViewSet::DynamicUpdateInfo::SetDynamicsMotionTolerance, "dynamicsMotionTolerance"_a);
        }
    c6.def("__iter__", [] (IndexedViewSet& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    c6.def_property_readonly("DgnHost", &IndexedViewSet::GetDgnHost);
    c6.def("GetDgnHost", &IndexedViewSet::GetDgnHost, py::return_value_policy::reference_internal);
    
    c6.def("IsHealingEnabled", &IndexedViewSet::IsHealingEnabled);
    
    c6.def_property_readonly("SelectedViewport", &IndexedViewSet::GetSelectedViewport);
    c6.def("GetSelectedViewport", &IndexedViewSet::GetSelectedViewport, py::return_value_policy::reference_internal);
    
    c6.def_property_readonly("FirstOpenView", &IndexedViewSet::GetFirstOpenView);
    c6.def("GetFirstOpenView", &IndexedViewSet::GetFirstOpenView, py::return_value_policy::reference_internal);
    
    c6.def_property_readonly("SelectedView", &IndexedViewSet::GetSelectedView);
    c6.def("GetSelectedView", &IndexedViewSet::GetSelectedView);
    
    c6.def("GetViewTitle", &IndexedViewSet::GetViewTitle, "title"_a, "viewIndex"_a);
    c6.def("GetViewport", &IndexedViewSet::GetViewport, "viewNum"_a, py::return_value_policy::reference_internal);
    c6.def("SetViewport", &IndexedViewSet::SetViewport, "viewNum"_a, "vp"_a);
    c6.def("ForgetViewport", &IndexedViewSet::ForgetViewport, "viewNum"_a);
    
    c6.def("UpdateViewDynamic", 
           py::overload_cast<IndexedViewportP, IndexedViewSet::DynamicUpdateInfo&>(&IndexedViewSet::UpdateViewDynamic),
           "vp"_a, "info"_a);

    c6.def("UpdateView",
           py::overload_cast<IndexedViewportP, DgnDrawMode, DrawPurpose, IndexedViewSet::FullUpdateInfo&>(&IndexedViewSet::UpdateView),
           "vp"_a, "drawMode"_a, "drawPurpose"_a, "info"_a);

    c6.def("SetSelectedView", &IndexedViewSet::SetSelectedView, "inVp"_a, "setActiveModel"_a, "fromButtonEvent"_a);

    //===================================================================================
    // struct IViewManager
    py::class_< IViewManager
        , DgnHost::IHostObject
    > c7(m, "IViewManager");


    c7.def_static("GetManager", &IViewManager::GetManager, py::return_value_policy::reference);
    c7.def_static("GetActiveViewSet", &IViewManager::GetActiveViewSet, py::return_value_policy::reference);
    
    c7.def_property_readonly("CurrentViewNumber", &IViewManager::GetCurrentViewNumber);
    c7.def("GetCurrentViewNumber", &IViewManager::GetCurrentViewNumber, DOC(Bentley, DgnPlatform, IViewManager, GetCurrentViewNumber));
    
    c7.def("IsGraphicsOn", &IViewManager::IsGraphicsOn);
    c7.def("AddViewDecoration", &IViewManager::AddViewDecoration, "decorator"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, IViewManager, AddViewDecoration));
    c7.def("DropViewDecoration", &IViewManager::DropViewDecoration, "decorator"_a);
    c7.def("AddElementDecorator", &IViewManager::AddElementDecorator, "decorator"_a, py::keep_alive<1, 2>());
    c7.def("DropElementDecorator", &IViewManager::DropElementDecorator, "decorator"_a);
    c7.def("AddViewMonitor", &IViewManager::AddViewMonitor, "monitor"_a, py::keep_alive<1, 2>());
    c7.def("DropViewMonitor", &IViewManager::DropViewMonitor, "monitor"_a);
    c7.def("AddViewTransientHandler", &IViewManager::AddViewTransientHandler, "handler"_a, py::keep_alive<1, 2>());
    c7.def("DropViewTransientHandler", &IViewManager::DropViewTransientHandler, "handler"_a);
    c7.def("AddModelTransientHandler", &IViewManager::AddModelTransientHandler, "handler"_a, py::keep_alive<1, 2>());
    c7.def("DropModelTransientHandler", &IViewManager::DropModelTransientHandler, "handler"_a);
    }