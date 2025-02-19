/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\dgnelementsettool.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/DgnElementSetTool.h>

//=======================================================================================
// Publicist class for ModifyOp
// @bsiclass                                                                   02/23
//=======================================================================================
class ModifyOpPub : ModifyOp
    {
    public:
        using ModifyOp::_OnElementModify;
        using ModifyOp::_SetWantMakeCopy;
        using ModifyOp::_SetWantGGLock;
        using ModifyOp::_WantMakeCopy;
        using ModifyOp::_WantCheckGGLock;
        using ModifyOp::_GetDestinationModelRef;
        using ModifyOp::_GetCopyContext;
        using ModifyOp::_ClearCopyContext;
        using ModifyOp::_DoOperationForModify;
        using ModifyOp::_OnPreElementModify;
        using ModifyOp::_ResetStop;
        using ModifyOp::_CheckStop;
    };

//=======================================================================================
// Trampoline class for ModifyOp
// @bsiclass                                                                   02/23
//=======================================================================================
class PyModifyOp : ModifyOp
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModify(EditElementHandleR eeh) override
           {
             try
                 {
                 py::gil_scoped_acquire gil;
                 py::function func = py::get_override(this, "_OnElementModify");
                 if (func)
                     {
                     EditElementHandleP elHandleP = &eeh;

                     auto obj = func(elHandleP);
                     StatusInt retVal = obj.cast<StatusInt>();

                     return retVal;
                     }
                 else
                     return ERROR;
                 }
             catch (std::exception& err)
                 {
                 ScriptEngineManager::Get().InjectException(err);
                 return ERROR;
                 }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetWantMakeCopy(bool val) override
            { PYBIND11_OVERRIDE_EX(void, ModifyOp, _SetWantMakeCopy, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetWantGGLock(bool val) override
            { PYBIND11_OVERRIDE_EX(void, ModifyOp, _SetWantGGLock, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantMakeCopy() const override
            { PYBIND11_OVERRIDE_EXR(bool, ModifyOp, _WantMakeCopy, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantCheckGGLock() const override
            { PYBIND11_OVERRIDE_EXR(bool, ModifyOp, _WantCheckGGLock, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DgnModelRefP _GetDestinationModelRef() override
            { PYBIND11_OVERRIDE_EXR(DgnModelRefP, ModifyOp, _GetDestinationModelRef, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElementCopyContextP _GetCopyContext() override
            { PYBIND11_OVERRIDE_EXR(ElementCopyContextP, ModifyOp, _GetCopyContext, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ClearCopyContext() override
            { PYBIND11_OVERRIDE_EX(void, ModifyOp, _ClearCopyContext, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoOperationForModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ModifyOp, _DoOperationForModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnPreElementModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ModifyOp, _OnPreElementModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ResetStop() override
            { PYBIND11_OVERRIDE_EX(void, ModifyOp, _ResetStop, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckStop() override
            { PYBIND11_OVERRIDE_EXR(bool, ModifyOp, _CheckStop, false, ); }
    };

//=======================================================================================
// Publicist class for DgnElementSetTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct DgnElementSetToolPub : DgnElementSetTool
    {
    public:
        // DgnTool
        using DgnElementSetTool::_GetToolName;
        using DgnElementSetTool::_PopulateToolSettings;
        using DgnElementSetTool::_OnCleanup;
        using DgnElementSetTool::_OnResetButtonUp;
        using DgnElementSetTool::_OnDataButtonUp;
        using DgnElementSetTool::_OnModelNoMotion;
        using DgnElementSetTool::_OnModelMotionStopped;
        using DgnElementSetTool::_OnMouseWheel;
        using DgnElementSetTool::_OnKeyTransition;
        using DgnElementSetTool::_On3DInputEvent;
        using DgnElementSetTool::_DisableEditAction;
        using DgnElementSetTool::_PerformEditAction;
        using DgnElementSetTool::_OverrideViewCursors;
        using DgnElementSetTool::_OnPreFilterButtonEvent;
        using DgnElementSetTool::_GetCursorForInactiveView;
        using DgnElementSetTool::_OnTouch;
        using DgnElementSetTool::_OnGestureNotify;
        using DgnElementSetTool::_OnGesture;
        using DgnElementSetTool::_OnFlick;
        using DgnElementSetTool::_OnTabletQuerySystemGestureStatus;

        // DgnPrimitiveTool
        using DgnElementSetTool::_ExitTool;
        using DgnElementSetTool::_OnRestartTool;
        using DgnElementSetTool::_IsSingleShot;
        using DgnElementSetTool::_CheckSingleShot;
        using DgnElementSetTool::_OnUndoPreviousStep;
        using DgnElementSetTool::_BeginDynamics;
        using DgnElementSetTool::_EndDynamics;
        using DgnElementSetTool::_GetDrawDynamicsTxnChanges;

        // IRedrawOperation
        // <Empty>
        
        // IModifyElement        
        // <Empty>

        // ModifyOp
        using DgnElementSetTool::_SetWantMakeCopy;
        using DgnElementSetTool::_SetWantGGLock;
        using DgnElementSetTool::_WantMakeCopy;
        using DgnElementSetTool::_WantCheckGGLock;
        using DgnElementSetTool::_GetCopyContext;
        using DgnElementSetTool::_ClearCopyContext;
        using DgnElementSetTool::_DoOperationForModify;
        using DgnElementSetTool::_OnPreElementModify;
        using DgnElementSetTool::_ResetStop;
        using DgnElementSetTool::_CheckStop;

        // DgnElementSetTool
        using DgnElementSetTool::_InstallToolImplementation;
        using DgnElementSetTool::_OnInstall;
        using DgnElementSetTool::_OnPostInstall;
        using DgnElementSetTool::_OnReinitialize;
        using DgnElementSetTool::_SetupAndPromptForNextAction;
        using DgnElementSetTool::SetupAndPromptForNextActionHelper;
        using DgnElementSetTool::OutputErrorMessage;
        using DgnElementSetTool::_NeedAcceptPoint;
        using DgnElementSetTool::_NeedPointForDynamics;
        using DgnElementSetTool::_NeedPointForSelection;
        using DgnElementSetTool::_AcceptIdentifiesNext;
        using DgnElementSetTool::_WantDynamics;
        using DgnElementSetTool::_OnDynamicFrame;
        using DgnElementSetTool::_OnRedrawOperation;
        using DgnElementSetTool::_OnResymbolize;
        using DgnElementSetTool::_OnRedrawInit;
        using DgnElementSetTool::_OnRedrawFinish;
        using DgnElementSetTool::_OnRedrawComplete;
        using DgnElementSetTool::_OnDataButton;
        using DgnElementSetTool::_OnResetButton;
        using DgnElementSetTool::_WantAccuSnap;
        using DgnElementSetTool::_WantAutoLocate;
        using DgnElementSetTool::_GetHitSource;
        using DgnElementSetTool::_SetHitSource;
        using DgnElementSetTool::_GetReferenceLocateOptions;
        using DgnElementSetTool::_SetLocateCriteria;
        using DgnElementSetTool::_OnPostLocate;
        using DgnElementSetTool::_SetLocateCursor;
        using DgnElementSetTool::_DoGroups;
        using DgnElementSetTool::_GetAdditionalLocateNumRequired;
        using DgnElementSetTool::_WantAdditionalLocate;
        using DgnElementSetTool::WantAdditionalLocateHelper;
        using DgnElementSetTool::_DoLocate;
        using DgnElementSetTool::_GetComponentMode;
        using DgnElementSetTool::_LocateOneElement;
        using DgnElementSetTool::_BuildLocateAgenda;
        using DgnElementSetTool::_RemoveAgendaElement;
        using DgnElementSetTool::_BeginPickElements;
        using DgnElementSetTool::_AllowDragSelect;
        using DgnElementSetTool::_DecorateScreen;
        using DgnElementSetTool::_OnModifierKeyTransition;
        using DgnElementSetTool::OnModifierKeyTransitionHelper;
        using DgnElementSetTool::_OnModelStartDrag;
        using DgnElementSetTool::_OnModelEndDrag;
        using DgnElementSetTool::_OnModelMotion;
        using DgnElementSetTool::_IsDragSelectActive;
        using DgnElementSetTool::_GetDragAnchorPoint;
        using DgnElementSetTool::_BuildDragSelectAgenda;
        using DgnElementSetTool::_GetDragSelectOverlapMode;
        using DgnElementSetTool::_GetDragSelectSymbology;
        using DgnElementSetTool::_GetBoxPoints;
        using DgnElementSetTool::_NotifyListeners;
        using DgnElementSetTool::_GetAgendaOperation;
        using DgnElementSetTool::_GetAgendaModify;
        using DgnElementSetTool::_UseActiveFence;
        using DgnElementSetTool::_AllowFence;
        using DgnElementSetTool::_AllowSelection;
        using DgnElementSetTool::_GetPreferredElemSource;
        using DgnElementSetTool::_GetElemSource;
        using DgnElementSetTool::_SetElemSource;
        using DgnElementSetTool::_HiliteFenceElems;
        using DgnElementSetTool::_HiliteAgendaEntries;
        using DgnElementSetTool::_UnHiliteAgendaEntries;
        using DgnElementSetTool::_FilterAgendaEntries;
        using DgnElementSetTool::_ModifyAgendaEntries;
        using DgnElementSetTool::_BuildAgenda;
        using DgnElementSetTool::GetElementAgenda;
        using DgnElementSetTool::_GetAnchorPoint;
        using DgnElementSetTool::_SetAnchorPoint;
        using DgnElementSetTool::_IsModifyOriginal;
        using DgnElementSetTool::_GetDestinationModelRef;
        using DgnElementSetTool::_IsFenceOverlap;
        using DgnElementSetTool::_IsFenceVoid;
        using DgnElementSetTool::_IsFenceClip;
        using DgnElementSetTool::_SetupForModify;
        using DgnElementSetTool::_GetFenceClipResult;
        using DgnElementSetTool::_DoFenceClip;
        using DgnElementSetTool::_OnElementModify;
        using DgnElementSetTool::_OnElementModifyClip;
        using DgnElementSetTool::_OnModifyComplete;
        using DgnElementSetTool::_GetGroupOperationCount;
        using DgnElementSetTool::_PreModifyAgenda;
        using DgnElementSetTool::_ModifyAgendaGroup;
        using DgnElementSetTool::_PostModifyAgenda;
        using DgnElementSetTool::_ProcessAgenda;
    };

//=======================================================================================
// Trampoline class for DgnElementSetTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnElementSetTool : DgnElementSetTool
    {
    public:
        using DgnElementSetTool::DgnElementSetTool;        

        /*---------------------------------------------------------------------------------**//**
        * DgnTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual void _GetToolName(WStringR name) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _GetToolName, name); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _PopulateToolSettings() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnCleanup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _PerformEditAction, ERROR, index); }

        /*---------------------------------------------------------------------------------**//**
        * Seems that it's useless to export.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        // virtual void _OverrideViewCursors(ViewportR, DgnDisplay::CursorP& active, DgnDisplay::CursorP& inactive) override

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPreFilterButtonEvent(ViewportP vp, bool& testDefault) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                bool retVal = false;
                py::function func = py::get_override(this, "_OnPreFilterButtonEvent");
                if (func)
                    {
                    auto obj = func(vp, testDefault);
                    auto tuple = obj.cast<py::tuple>();
                    retVal = tuple[0].cast<bool>();
                    testDefault = tuple[1].cast<bool>();
                    }
                else
                    retVal = __super::_OnPreFilterButtonEvent(vp, testDefault);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return false;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * Seems that it's useless to export.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        // virtual DgnDisplay::CursorP _GetCursorForInactiveView(bool& allowDynamics, ViewportP) { return NULL; }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnTouch(DgnTouchEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, DgnElementSetTool, _OnTabletQuerySystemGestureStatus, 0, ev); }

        /*---------------------------------------------------------------------------------**//**
        * DgnPrimitiveTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRestartTool() override
            { PYBIND11_OVERRIDE_PURE_EX(void, DgnElementSetTool, _OnRestartTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _IsSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _CheckSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoPreviousStep() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnUndoPreviousStep, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginDynamics() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _BeginDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _EndDynamics() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _EndDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual IDrawElementAgenda* _GetDrawDynamicsTxnChanges() override
            { PYBIND11_OVERRIDE_EXR(IDrawElementAgenda*, DgnElementSetTool, _GetDrawDynamicsTxnChanges, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * IRedrawOperation overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        

        /*---------------------------------------------------------------------------------**//**
        * IModifyElement overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        

        /*---------------------------------------------------------------------------------**//**
        * ModifyOp overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual void _SetWantMakeCopy(bool val) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetWantMakeCopy, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetWantGGLock(bool val) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetWantGGLock, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantMakeCopy() const override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _WantMakeCopy, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantCheckGGLock() const override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _WantCheckGGLock, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElementCopyContextP _GetCopyContext() override
            { PYBIND11_OVERRIDE_EXR(ElementCopyContextP, DgnElementSetTool, _GetCopyContext, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ClearCopyContext() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _ClearCopyContext, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoOperationForModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _DoOperationForModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnPreElementModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _OnPreElementModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ResetStop() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _ResetStop, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckStop() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _CheckStop, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * DgnElementSetTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnInstall, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnPostInstall, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetupAndPromptForNextAction() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetupAndPromptForNextAction, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedAcceptPoint() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _NeedAcceptPoint, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _NeedPointForDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForSelection() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _NeedPointForSelection, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AcceptIdentifiesNext() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _AcceptIdentifiesNext, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _WantDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDynamicFrame(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnDynamicFrame, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnRedrawOperation(EditElementHandleR el, ViewContextR context, bool* canUseCached) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                StatusInt retVal = ERROR;
                py::function func = py::get_override(this, "_OnRedrawOperation");
                if (func)
                    {
                    auto obj = func(el, context, *canUseCached);
                    auto tuple = obj.cast<py::tuple>();
                    retVal = tuple[0].cast<StatusInt>();
                    *canUseCached = tuple[1].cast<bool>();
                    }
                else
                    retVal = __super::_OnRedrawOperation(el, context, canUseCached);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return ERROR;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnResymbolize(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnResymbolize, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawInit(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnRedrawInit, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawFinish(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _OnRedrawFinish, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnRedrawComplete(ViewContextR context) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _OnRedrawComplete, ERROR, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnResetButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAccuSnap() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _WantAccuSnap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAutoLocate() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _WantAutoLocate, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitSource _GetHitSource() const override
            { PYBIND11_OVERRIDE_EXR(HitSource, DgnElementSetTool, _GetHitSource, HitSource::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetHitSource(HitSource source) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetHitSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RefLocateOption _GetReferenceLocateOptions() override
            { PYBIND11_OVERRIDE_EXR(RefLocateOption, DgnElementSetTool, _GetReferenceLocateOptions, REF_LOCATE_Normal, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCriteria() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetLocateCriteria, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPostLocate(HitPathCP path, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnPostLocate, false, path, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCursor(bool enableLocate) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetLocateCursor, enableLocate); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DoGroups() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _DoGroups, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual size_t _GetAdditionalLocateNumRequired() override
            { PYBIND11_OVERRIDE_EXR(size_t, DgnElementSetTool, _GetAdditionalLocateNumRequired, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAdditionalLocate(DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _WantAdditionalLocate, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitPathCP _DoLocate(DgnButtonEventCR ev, bool newSearch, ComponentMode complexComponent) override
            { PYBIND11_OVERRIDE_EXR(HitPathCP, DgnElementSetTool, _DoLocate, nullptr, ev, newSearch, complexComponent); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ComponentMode _GetComponentMode() override
            { PYBIND11_OVERRIDE_EXR(ComponentMode, DgnElementSetTool, _GetComponentMode, ComponentMode::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _LocateOneElement(DgnButtonEventCR ev, bool newSearch) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _LocateOneElement, ev, newSearch); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual EditElementHandleP _BuildLocateAgenda(HitPathCP path, DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(EditElementHandleP, DgnElementSetTool, _BuildLocateAgenda, nullptr, path, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _RemoveAgendaElement(EditElementHandleR el) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _RemoveAgendaElement, el); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginPickElements() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _BeginPickElements, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _AllowDragSelect() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, DgnElementSetTool, _AllowDragSelect, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _IsDragSelectActive() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, DgnElementSetTool, _IsDragSelectActive, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _GetDragAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _BuildDragSelectAgenda(FenceParamsP fp, DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _BuildDragSelectAgenda, false, fp, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragSelectOverlapMode(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _GetDragSelectOverlapMode, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _GetDragSelectSymbology(UInt32& color, UInt32& fillColor, UInt32& style, UInt32& weight, DgnButtonEventCR ev) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_GetDragSelectSymbology");
                if (func)
                    {
                    auto obj = func(ev);
                    auto tuple = obj.cast<py::tuple>();
                    color = tuple[0].cast<UInt32>();
                    fillColor = tuple[1].cast<UInt32>();
                    style = tuple[2].cast<UInt32>();
                    weight = tuple[3].cast<UInt32>();
                    }
                else
                    __super::_GetDragSelectSymbology(color, fillColor, style, weight, ev);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);                
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _GetBoxPoints(DPoint3dP shapePointsP, DgnCoordSystem sys, DPoint3dCR activeOrigin, DPoint3dCR activeCorner, ViewportP vp) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_GetBoxPoints");
                if (func)
                    {
                    DPoint3dArray pnts(5, DPoint3d::FromZero());
                    func(pnts, sys, activeOrigin, activeCorner, vp);
                    memcpy(shapePointsP, (const void*) pnts.data(), sizeof(DPoint3d) * 5);
                    }
                else
                    __super::_GetBoxPoints(shapePointsP, sys, activeOrigin, activeCorner, vp);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);                
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NotifyListeners(ElementAgendaR agenda, AgendaOperation agendaOp, AgendaModify agendaModify, AgendaEvent agendaEvt, void* eventArg = NULL)
            {
            try
                {
                py::gil_scoped_acquire gil;
                bool retVal = false;
                py::function func = py::get_override(this, "_NotifyListeners");
                if (func)
                    {
                    py::capsule arg(eventArg);
                    auto obj = func(agenda, agendaOp, agendaModify, agendaEvt, arg);
                    retVal = obj.cast<bool>();
                    }
                else
                    retVal = __super::_NotifyListeners(agenda, agendaOp, agendaModify, agendaEvt, eventArg);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return false;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AgendaOperation _GetAgendaOperation() override
            { PYBIND11_OVERRIDE_EXR(AgendaOperation, DgnElementSetTool, _GetAgendaOperation, AgendaOperation::NotSpecified, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AgendaModify _GetAgendaModify() override
            { PYBIND11_OVERRIDE_EXR(AgendaModify, DgnElementSetTool, _GetAgendaModify, AgendaModify::Original, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _UseActiveFence() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _UseActiveFence, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesFence _AllowFence() override
            { PYBIND11_OVERRIDE_EXR(UsesFence, DgnElementSetTool, _AllowFence, UsesFence::USES_FENCE_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesSelection _AllowSelection() override
            { PYBIND11_OVERRIDE_EXR(UsesSelection, DgnElementSetTool, _AllowSelection, UsesSelection::USES_SS_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetPreferredElemSource() override
            { PYBIND11_OVERRIDE_EXR(ElemSource, DgnElementSetTool, _GetPreferredElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetElemSource() const override
            { PYBIND11_OVERRIDE_EXR(ElemSource, DgnElementSetTool, _GetElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetElemSource(ElemSource source) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetElemSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _HiliteFenceElems() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _HiliteFenceElems, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _HiliteAgendaEntries(bool changed) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _HiliteAgendaEntries, changed); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _UnHiliteAgendaEntries(bool empty) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _UnHiliteAgendaEntries, empty); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _FilterAgendaEntries() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _FilterAgendaEntries, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ModifyAgendaEntries() override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _ModifyAgendaEntries, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BuildAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _BuildAgenda, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _GetAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetAnchorPoint(DPoint3dCP anchorPt) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _SetAnchorPoint, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsModifyOriginal() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _IsModifyOriginal, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DgnModelRefP _GetDestinationModelRef() override
            { PYBIND11_OVERRIDE_EXR(DgnModelRefP, DgnElementSetTool, _GetDestinationModelRef, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceOverlap() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _IsFenceOverlap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceVoid() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _IsFenceVoid, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceClip() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _IsFenceClip, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _SetupForModify(DgnButtonEventCR ev, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _SetupForModify, false, ev, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ClipResult _GetFenceClipResult() override
            { PYBIND11_OVERRIDE_EXR(ClipResult, DgnElementSetTool, _GetFenceClipResult, ClipResult::CLIP_RESULT_NotSupported, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoFenceClip() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _DoFenceClip, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModify(EditElementHandleR el) override
            {
             try
                 {
                 py::gil_scoped_acquire gil;
                 py::function func = py::get_override(this, "_OnElementModify");
                 if (func)
                     {
                     EditElementHandleP elHandleP = &el;

                     auto obj = func(elHandleP);
                     StatusInt retVal = obj.cast<StatusInt>();

                     return retVal;
                     }
                 else
                     return ERROR;
                 }
             catch (std::exception& err)
                 {
                 ScriptEngineManager::Get().InjectException(err);
                 return ERROR;
                 }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModifyClip(EditElementHandleR el, FenceParamsP fp, FenceClipFlags options) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _OnElementModifyClip, ERROR, el, fp, options); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifyComplete(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnElementSetTool, _OnModifyComplete, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UInt32 _GetGroupOperationCount() override
            { PYBIND11_OVERRIDE_EXR(UInt32, DgnElementSetTool, _GetGroupOperationCount, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PreModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _PreModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ModifyAgendaGroup(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp, UInt32 iGroupOp, bool redraw) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _ModifyAgendaGroup, ERROR, ev, agendaOp, agendaModify, isGroupOp, iGroupOp, redraw); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PostModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, DgnElementSetTool, _PostModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ProcessAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnElementSetTool, _ProcessAgenda, ERROR, ev); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnElementSetTool(py::module_& m)
    {
    //===================================================================================
    // class ModifyOp
    py::class_< ModifyOp, PyModifyOp, IModifyElement> c1(m, "ModifyOp");

    c1.def(py::init<>());
    c1.def("_SetWantMakeCopy", &ModifyOpPub::_SetWantMakeCopy, "val"_a);
    c1.def("_SetWantGGLock", &ModifyOpPub::_SetWantGGLock, "val"_a);
    c1.def("_WantMakeCopy", &ModifyOpPub::_WantMakeCopy);
    c1.def("_WantCheckGGLock", &ModifyOpPub::_WantCheckGGLock);
    c1.def("_GetDestinationModelRef", &ModifyOpPub::_GetDestinationModelRef, py::return_value_policy::reference_internal);
    c1.def("_GetCopyContext", &ModifyOpPub::_GetCopyContext, py::return_value_policy::reference_internal);
    c1.def("_ClearCopyContext", &ModifyOpPub::_ClearCopyContext);
    c1.def("_DoOperationForModify", &ModifyOpPub::_DoOperationForModify, "eeh"_a);
    c1.def("_OnPreElementModify", &ModifyOpPub::_OnPreElementModify, "eeh"_a);
    c1.def("_ResetStop", &ModifyOpPub::_ResetStop);
    c1.def("_CheckStop", &ModifyOpPub::_CheckStop);

    //===================================================================================
    // struct DgnElementSetTool
    py::class_< DgnElementSetTool, RefCountedPtr<DgnElementSetTool>, PyDgnElementSetTool, DgnPrimitiveTool/*, IRedrawOperation, ModifyOp*/> c2(m, "DgnElementSetTool", py::multiple_inheritance());

    if (true)
        {
        //===================================================================================
        // enum ElemSource
        py::enum_< DgnElementSetTool::ElemSource>(c2, "ElemSource", py::arithmetic())
            .value("eSOURCE_Pick", DgnElementSetTool::SOURCE_Pick)
            .value("eSOURCE_Fence", DgnElementSetTool::SOURCE_Fence)
            .value("eSOURCE_SelectionSet", DgnElementSetTool::SOURCE_SelectionSet)
            .export_values();

        //===================================================================================
        // enum UsesFence
        py::enum_< DgnElementSetTool::UsesFence>(c2, "UsesFence", py::arithmetic())
            .value("eUSES_FENCE_Check", DgnElementSetTool::USES_FENCE_Check)
            .value("eUSES_FENCE_Required", DgnElementSetTool::USES_FENCE_Required)
            .value("eUSES_FENCE_None", DgnElementSetTool::USES_FENCE_None)
            .export_values();

        //===================================================================================
        // enum UsesSelection
        py::enum_< DgnElementSetTool::UsesSelection>(c2, "UsesSelection", py::arithmetic())
            .value("eUSES_SS_Check", DgnElementSetTool::USES_SS_Check)
            .value("eUSES_SS_Required", DgnElementSetTool::USES_SS_Required)
            .value("eUSES_SS_None", DgnElementSetTool::USES_SS_None)
            .export_values();

        //===================================================================================
        // enum UsesDragSelect
        py::enum_< DgnElementSetTool::UsesDragSelect>(c2, "UsesDragSelect", py::arithmetic())
            .value("eUSES_DRAGSELECT_Box", DgnElementSetTool::USES_DRAGSELECT_Box)
            .value("eUSES_DRAGSELECT_Line", DgnElementSetTool::USES_DRAGSELECT_Line)
            .value("eUSES_DRAGSELECT_None", DgnElementSetTool::USES_DRAGSELECT_None)
            .export_values();

        //===================================================================================
        // enum ClipResult
        py::enum_< DgnElementSetTool::ClipResult>(c2, "ClipResult", py::arithmetic())
            .value("eCLIP_RESULT_NotSupported", DgnElementSetTool::CLIP_RESULT_NotSupported)
            .value("eCLIP_RESULT_NewElements", DgnElementSetTool::CLIP_RESULT_NewElements)
            .value("eCLIP_RESULT_OriginalElements", DgnElementSetTool::CLIP_RESULT_OriginalElements)
            .export_values();

        //===================================================================================
        // enum RefLocateOption
        py::enum_< DgnElementSetTool::RefLocateOption>(c2, "RefLocateOption", py::arithmetic())
            .value("eREF_LOCATE_Normal", DgnElementSetTool::REF_LOCATE_Normal)
            .value("eREF_LOCATE_SelfAttachment", DgnElementSetTool::REF_LOCATE_SelfAttachment)
            .value("eREF_LOCATE_Editable", DgnElementSetTool::REF_LOCATE_Editable)
            .value("eREF_LOCATE_TreatAsElement", DgnElementSetTool::REF_LOCATE_TreatAsElement)
            .export_values();

        //===================================================================================
        // enum ErrorNums
        py::enum_< DgnElementSetTool::ErrorNums>(c2, "ErrorNums", py::arithmetic())
            .value("eERROR_NUM_NoFence", DgnElementSetTool::ERROR_NUM_NoFence)
            .value("eERROR_NUM_NoFenceElems", DgnElementSetTool::ERROR_NUM_NoFenceElems)
            .value("eERROR_NUM_NoFenceElemsOutside", DgnElementSetTool::ERROR_NUM_NoFenceElemsOutside)
            .value("eERROR_NUM_NoSSElems", DgnElementSetTool::ERROR_NUM_NoSSElems)
            .value("eERROR_NUM_NotSuportedElmType", DgnElementSetTool::ERROR_NUM_NotSuportedElmType)
            .export_values();
        }

    c2.def("_InstallToolImplementation", &DgnElementSetToolPub::_InstallToolImplementation);
    c2.def("_OnInstall", &DgnElementSetToolPub::_OnInstall);
    c2.def("_OnPostInstall", &DgnElementSetToolPub::_OnPostInstall);
    c2.def("_OnReinitialize", &DgnElementSetToolPub::_OnReinitialize);
    c2.def("_SetupAndPromptForNextAction", &DgnElementSetToolPub::_SetupAndPromptForNextAction);
    c2.def("SetupAndPromptForNextActionHelper", &DgnElementSetToolPub::SetupAndPromptForNextActionHelper);
    c2.def_static("OutputErrorMessage", &DgnElementSetToolPub::OutputErrorMessage, "msg"_a);
    c2.def("_NeedAcceptPoint", &DgnElementSetToolPub::_NeedAcceptPoint);
    c2.def("_NeedPointForDynamics", &DgnElementSetToolPub::_NeedPointForDynamics);
    c2.def("_NeedPointForSelection", &DgnElementSetToolPub::_NeedPointForSelection);
    c2.def("_AcceptIdentifiesNext", &DgnElementSetToolPub::_AcceptIdentifiesNext);
    c2.def("_WantDynamics", &DgnElementSetToolPub::_WantDynamics);
    c2.def("_OnDynamicFrame", &DgnElementSetToolPub::_OnDynamicFrame);

    c2.def("_OnRedrawOperation", [] (DgnElementSetTool& self, EditElementHandleR el, ViewContextR context, bool canUseCached)
           {
           bool canUseCached_ {canUseCached};
           auto retVal = static_cast<DgnElementSetToolPub&>(self)._OnRedrawOperation(el, context, &canUseCached_);
           return py::make_tuple(retVal, canUseCached_);
           }, "el"_a, "context"_a, "canUseCached"_a);

    c2.def("_OnResymbolize", &DgnElementSetToolPub::_OnResymbolize, "context"_a);
    c2.def("_OnRedrawInit", &DgnElementSetToolPub::_OnRedrawInit, "context"_a);
    c2.def("_OnRedrawFinish", &DgnElementSetToolPub::_OnRedrawFinish, "context"_a);
    c2.def("_OnRedrawComplete", &DgnElementSetToolPub::_OnRedrawComplete, "context"_a);
    c2.def("_OnDataButton", &DgnElementSetToolPub::_OnDataButton, "ev"_a);
    c2.def("_OnResetButton", &DgnElementSetToolPub::_OnResetButton, "ev"_a);
    c2.def("_WantAccuSnap", &DgnElementSetToolPub::_WantAccuSnap);
    c2.def("_WantAutoLocate", &DgnElementSetToolPub::_WantAutoLocate);
    c2.def("_GetHitSource", &DgnElementSetToolPub::_GetHitSource);
    c2.def("_SetHitSource", &DgnElementSetToolPub::_SetHitSource);
    c2.def("_GetReferenceLocateOptions", &DgnElementSetToolPub::_GetReferenceLocateOptions);
    c2.def("_SetLocateCriteria", &DgnElementSetToolPub::_SetLocateCriteria);
    c2.def("_OnPostLocate", &DgnElementSetToolPub::_OnPostLocate, "path"_a, "cantAcceptReason"_a);
    c2.def("_SetLocateCursor", &DgnElementSetToolPub::_SetLocateCursor, "enableLocate"_a);
    c2.def("_DoGroups", &DgnElementSetToolPub::_DoGroups);
    c2.def("_GetAdditionalLocateNumRequired", &DgnElementSetToolPub::_GetAdditionalLocateNumRequired);
    c2.def("_WantAdditionalLocate", &DgnElementSetToolPub::_WantAdditionalLocate, "ev"_a);
    c2.def("WantAdditionalLocateHelper", &DgnElementSetToolPub::WantAdditionalLocateHelper, "ev"_a);   
    c2.def("_DoLocate", &DgnElementSetToolPub::_DoLocate, "ev"_a, "newSearch"_a, "complexComponent"_a);
    c2.def("_GetComponentMode", &DgnElementSetToolPub::_GetComponentMode);
    c2.def("_LocateOneElement", &DgnElementSetToolPub::_LocateOneElement, "ev"_a, "newSearch"_a);
    c2.def("_BuildLocateAgenda", &DgnElementSetToolPub::_BuildLocateAgenda, "path"_a, "ev"_a, py::return_value_policy::reference_internal);
    c2.def("_RemoveAgendaElement", &DgnElementSetToolPub::_RemoveAgendaElement, "el"_a);
    c2.def("_BeginPickElements", &DgnElementSetToolPub::_BeginPickElements);
    c2.def("_AllowDragSelect", &DgnElementSetToolPub::_AllowDragSelect);
    c2.def("_DecorateScreen", &DgnElementSetToolPub::_DecorateScreen, "vp"_a);
    c2.def("_OnModifierKeyTransition", &DgnElementSetToolPub::_OnModifierKeyTransition, "wentDown"_a, "key"_a);
    c2.def("OnModifierKeyTransitionHelper", &DgnElementSetToolPub::OnModifierKeyTransitionHelper, "wentDown"_a, "key"_a);
    c2.def("_OnModelStartDrag", &DgnElementSetToolPub::_OnModelStartDrag, "ev"_a);
    c2.def("_OnModelEndDrag", &DgnElementSetToolPub::_OnModelEndDrag, "ev"_a);
    c2.def("_OnModelMotion", &DgnElementSetToolPub::_OnModelMotion, "ev"_a);
    c2.def("_IsDragSelectActive", &DgnElementSetToolPub::_IsDragSelectActive);
    c2.def("_GetDragAnchorPoint", &DgnElementSetToolPub::_GetDragAnchorPoint, "anchorPt"_a);
    c2.def("_BuildDragSelectAgenda", &DgnElementSetToolPub::_BuildDragSelectAgenda, "fp"_a, "ev"_a);
    c2.def("_GetDragSelectOverlapMode", &DgnElementSetToolPub::_GetDragSelectOverlapMode, "ev"_a);

    c2.def("_GetDragSelectSymbology", [] (DgnElementSetTool& self, DgnButtonEventCR ev)
           {
           UInt32 color = 0, fillColor = 0, style = 0, weight = 0;
           static_cast<DgnElementSetToolPub&>(self)._GetDragSelectSymbology(color, fillColor, style, weight, ev);
           return py::make_tuple(color, fillColor, style, weight);
           }, "ev"_a);

    c2.def("_GetBoxPoints", [] (DgnElementSetTool& self, DPoint3dArray& shapePoints, DgnCoordSystem sys, DPoint3dCR activeOrigin, DPoint3dCR activeCorner, ViewportP vp)
           {
           if (shapePoints.size() < 5)
               shapePoints.resize(5);
           static_cast<DgnElementSetToolPub&>(self)._GetBoxPoints(shapePoints.data(), sys, activeOrigin, activeCorner, vp);
           }, "shapePoints"_a, "sys"_a, "activeOrigin"_a, "activeCorner"_a, "vp"_a);

    c2.def("_NotifyListeners", [] (DgnElementSetTool& self, ElementAgendaR agenda, AgendaOperation agendaOperation, AgendaModify agendaModify, AgendaEvent agendaEvt, py::capsule const& eventArg)
           {
           return static_cast<DgnElementSetToolPub&>(self)._NotifyListeners(agenda, agendaOperation, agendaModify, agendaEvt, eventArg.get_pointer());
           }, "agenda"_a, "agendaOperation"_a, "agendaModify"_a, "agendaEvt"_a, "eventArg"_a);

    c2.def("_GetAgendaOperation", &DgnElementSetToolPub::_GetAgendaOperation);
    c2.def("_GetAgendaModify", &DgnElementSetToolPub::_GetAgendaModify);
    c2.def("_UseActiveFence", &DgnElementSetToolPub::_UseActiveFence);
    c2.def("_AllowFence", &DgnElementSetToolPub::_AllowFence);
    c2.def("_AllowSelection", &DgnElementSetToolPub::_AllowSelection);
    c2.def("_GetPreferredElemSource", &DgnElementSetToolPub::_GetPreferredElemSource);
    c2.def("_GetElemSource", &DgnElementSetToolPub::_GetElemSource);
    c2.def("_SetElemSource", &DgnElementSetToolPub::_SetElemSource);
    c2.def("_HiliteFenceElems", &DgnElementSetToolPub::_HiliteFenceElems);
    c2.def("_HiliteAgendaEntries", &DgnElementSetToolPub::_HiliteAgendaEntries, "changed"_a);
    c2.def("_UnHiliteAgendaEntries", &DgnElementSetToolPub::_UnHiliteAgendaEntries, "empty"_a);
    c2.def("_FilterAgendaEntries", &DgnElementSetToolPub::_FilterAgendaEntries);
    c2.def("_ModifyAgendaEntries", &DgnElementSetToolPub::_ModifyAgendaEntries);
    c2.def("_BuildAgenda", &DgnElementSetToolPub::_BuildAgenda);
    c2.def("GetElementAgenda", &DgnElementSetToolPub::GetElementAgenda, py::return_value_policy::reference_internal);    
    c2.def("_GetAnchorPoint", &DgnElementSetToolPub::_GetAnchorPoint, "anchorPt"_a);
    c2.def("_SetAnchorPoint", &DgnElementSetToolPub::_SetAnchorPoint, "anchorPt"_a);
    c2.def("_IsModifyOriginal", &DgnElementSetToolPub::_IsModifyOriginal);
    c2.def("_GetDestinationModelRef", &DgnElementSetToolPub::_GetDestinationModelRef, py::return_value_policy::reference_internal);
    c2.def("_IsFenceOverlap", &DgnElementSetToolPub::_IsFenceOverlap);
    c2.def("_IsFenceVoid", &DgnElementSetToolPub::_IsFenceVoid);
    c2.def("_IsFenceClip", &DgnElementSetToolPub::_IsFenceClip);
    c2.def("_SetupForModify", &DgnElementSetToolPub::_SetupForModify, "ev"_a, "isDynamics"_a);
    c2.def("_GetFenceClipResult", &DgnElementSetToolPub::_GetFenceClipResult);
    c2.def("_DoFenceClip", &DgnElementSetToolPub::_DoFenceClip);
    c2.def("_OnElementModify", &DgnElementSetToolPub::_OnElementModify, "el"_a);
    c2.def("_OnElementModifyClip", &DgnElementSetToolPub::_OnElementModifyClip, "el"_a, "fp"_a, "options"_a);
    c2.def("_OnModifyComplete", &DgnElementSetToolPub::_OnModifyComplete);
    c2.def("_GetGroupOperationCount", &DgnElementSetToolPub::_GetGroupOperationCount);
    c2.def("_PreModifyAgenda", &DgnElementSetToolPub::_PreModifyAgenda, "ev"_a, "agendaOp"_a, "agendaModify"_a, "isGroupOp"_a);
    c2.def("_ModifyAgendaGroup", &DgnElementSetToolPub::_ModifyAgendaGroup, "ev"_a, "agendaOp"_a, "agendaModify"_a, "isGroupOp"_a, "iGroupOp"_a, "redraw"_a);
    c2.def("_PostModifyAgenda", &DgnElementSetToolPub::_PostModifyAgenda, "ev"_a, "agendaOp"_a, "agendaModify"_a, "isGroupOp"_a);
    c2.def("_ProcessAgenda", &DgnElementSetToolPub::_ProcessAgenda, "ev"_a);

    c2.def(py::init<>());
    c2.def(py::init<int>(), "toolId"_a);
    }