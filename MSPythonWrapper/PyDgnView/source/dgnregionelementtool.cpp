/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\dgnregionelementtool.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/DgnElementSetTool.h>
#include <DgnView/DgnRegionElementTool.h>



//=======================================================================================
// Publicist class for DgnRegionElementTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct DgnRegionElementToolPub : DgnRegionElementTool
    {
    public:
        // DgnTool
        using DgnRegionElementTool::_GetToolName;
        using DgnRegionElementTool::_PopulateToolSettings;
        using DgnRegionElementTool::_OnResetButtonUp;
        using DgnRegionElementTool::_OnDataButtonUp;
        using DgnRegionElementTool::_OnModelNoMotion;
        using DgnRegionElementTool::_OnModelMotionStopped;
        using DgnRegionElementTool::_OnMouseWheel;
        using DgnRegionElementTool::_OnKeyTransition;
        using DgnRegionElementTool::_On3DInputEvent;
        using DgnRegionElementTool::_DisableEditAction;
        using DgnRegionElementTool::_PerformEditAction;
        using DgnRegionElementTool::_OnPreFilterButtonEvent;
        using DgnRegionElementTool::_OnTouch;
        using DgnRegionElementTool::_OnGestureNotify;
        using DgnRegionElementTool::_OnGesture;
        using DgnRegionElementTool::_OnFlick;
        using DgnRegionElementTool::_OnTabletQuerySystemGestureStatus;

        // DgnPrimitiveTool
        using DgnRegionElementTool::_ExitTool;
        using DgnRegionElementTool::_OnRestartTool;
        using DgnRegionElementTool::_IsSingleShot;
        using DgnRegionElementTool::_CheckSingleShot;
        using DgnRegionElementTool::_BeginDynamics;
        using DgnRegionElementTool::_EndDynamics;
        using DgnRegionElementTool::_GetDrawDynamicsTxnChanges;

        // IRedrawOperation
        
        // IModifyElement
        
        // ModifyOp
        using DgnRegionElementTool::_SetWantMakeCopy;
        using DgnRegionElementTool::_SetWantGGLock;
        using DgnRegionElementTool::_WantMakeCopy;
        using DgnRegionElementTool::_WantCheckGGLock;
        using DgnRegionElementTool::_GetCopyContext;
        using DgnRegionElementTool::_ClearCopyContext;
        using DgnRegionElementTool::_DoOperationForModify;
        using DgnRegionElementTool::_OnPreElementModify;
        
        // DgnElementSetTool
        using DgnRegionElementTool::_InstallToolImplementation;
        using DgnRegionElementTool::_OnInstall;
        using DgnRegionElementTool::_OnReinitialize;
        using DgnRegionElementTool::_NeedPointForDynamics;
        using DgnRegionElementTool::_NeedPointForSelection;
        using DgnRegionElementTool::_OnRedrawOperation;
        using DgnRegionElementTool::_OnResymbolize;
        using DgnRegionElementTool::_OnRedrawInit;
        using DgnRegionElementTool::_OnRedrawFinish;
        using DgnRegionElementTool::_OnRedrawComplete;
        using DgnRegionElementTool::_WantAutoLocate;
        using DgnRegionElementTool::_GetHitSource;
        using DgnRegionElementTool::_SetHitSource;
        using DgnRegionElementTool::_GetReferenceLocateOptions;
        using DgnRegionElementTool::_SetLocateCursor;
        using DgnRegionElementTool::_GetAdditionalLocateNumRequired;
        using DgnRegionElementTool::_DoLocate;
        using DgnRegionElementTool::_GetComponentMode;
        using DgnRegionElementTool::_LocateOneElement;
        using DgnRegionElementTool::_BuildLocateAgenda;
        using DgnRegionElementTool::_RemoveAgendaElement;
        using DgnRegionElementTool::_BeginPickElements;
        using DgnRegionElementTool::_OnModelStartDrag;
        using DgnRegionElementTool::_OnModelEndDrag;
        using DgnRegionElementTool::_IsDragSelectActive;
        using DgnRegionElementTool::_GetDragAnchorPoint;
        using DgnRegionElementTool::_BuildDragSelectAgenda;
        using DgnRegionElementTool::_GetDragSelectOverlapMode;
        using DgnRegionElementTool::_GetDragSelectSymbology;
        using DgnRegionElementTool::_GetBoxPoints;
        using DgnRegionElementTool::_NotifyListeners;
        using DgnRegionElementTool::_GetAgendaOperation;
        using DgnRegionElementTool::_GetAgendaModify;
        using DgnRegionElementTool::_UseActiveFence;
        using DgnRegionElementTool::_AllowFence;
        using DgnRegionElementTool::_AllowSelection;
        using DgnRegionElementTool::_GetPreferredElemSource;
        using DgnRegionElementTool::_GetElemSource;
        using DgnRegionElementTool::_SetElemSource;
        using DgnRegionElementTool::_HiliteFenceElems;
        using DgnRegionElementTool::_ModifyAgendaEntries;
        using DgnRegionElementTool::_BuildAgenda;
        using DgnRegionElementTool::_GetAnchorPoint;
        using DgnRegionElementTool::_SetAnchorPoint;
        using DgnRegionElementTool::_GetDestinationModelRef;
        using DgnRegionElementTool::_IsFenceOverlap;
        using DgnRegionElementTool::_IsFenceVoid;
        using DgnRegionElementTool::_IsFenceClip;
        using DgnRegionElementTool::_SetupForModify;
        using DgnRegionElementTool::_GetFenceClipResult;
        using DgnRegionElementTool::_DoFenceClip;
        using DgnRegionElementTool::_OnElementModifyClip;
        using DgnRegionElementTool::_GetGroupOperationCount;
        using DgnRegionElementTool::_PreModifyAgenda;
        using DgnRegionElementTool::_ModifyAgendaGroup;
        using DgnRegionElementTool::_PostModifyAgenda;

        // IViewTransients        

        // DgnRegionElementTool
        using DgnRegionElementTool::GetRegionContext;
        using DgnRegionElementTool::GetCurrentToolPhase;
        using DgnRegionElementTool::IsFloodRegionSelected;
        using DgnRegionElementTool::GetRegionPointsCount;
        using DgnRegionElementTool::_GetRegionParams;
        using DgnRegionElementTool::_GetRegionCreateMode;
        using DgnRegionElementTool::_OnProcessRegionResult;
        using DgnRegionElementTool::_DoComputeRegionResult;
        using DgnRegionElementTool::_GetRegionPreviewSymbology;
        using DgnRegionElementTool::_GetAssociativeRegionName;
        using DgnRegionElementTool::_OnElementModify;
        using DgnRegionElementTool::_WantProcessOriginals;
        using DgnRegionElementTool::_WantFloodDynamicArea;
        using DgnRegionElementTool::_AllowPhysicallyClosed;
        using DgnRegionElementTool::_AcceptClosedElement;
        using DgnRegionElementTool::_IsModifyOriginal;
        using DgnRegionElementTool::_DoGroups;
        using DgnRegionElementTool::_WantDynamics;
        using DgnRegionElementTool::_WantAccuSnap;
        using DgnRegionElementTool::_WantAdditionalLocate;
        using DgnRegionElementTool::_NeedAcceptPoint;
        using DgnRegionElementTool::_AcceptIdentifiesNext;
        using DgnRegionElementTool::_AllowDragSelect;
        using DgnRegionElementTool::_CheckStop;
        using DgnRegionElementTool::_ResetStop;
        using DgnRegionElementTool::_DrawTransients;
        using DgnRegionElementTool::_DecorateScreen;
        using DgnRegionElementTool::_ProcessAgenda;
        using DgnRegionElementTool::_HiliteAgendaEntries;
        using DgnRegionElementTool::_UnHiliteAgendaEntries;
        using DgnRegionElementTool::_OnPostLocate;
        using DgnRegionElementTool::_FilterAgendaEntries;
        using DgnRegionElementTool::_SetLocateCriteria;
        using DgnRegionElementTool::_SetupAndPromptForNextAction;
        using DgnRegionElementTool::_OnDynamicFrame;
        using DgnRegionElementTool::_OnModelMotion;
        using DgnRegionElementTool::_OnModifierKeyTransition;
        using DgnRegionElementTool::_OnModifyComplete;
        using DgnRegionElementTool::_OnResetButton;
        using DgnRegionElementTool::_OnDataButton;
        using DgnRegionElementTool::_OnUndoPreviousStep;
        using DgnRegionElementTool::_OnCleanup;
        using DgnRegionElementTool::_OnPostInstall;
    };

//=======================================================================================
// Trampoline class for DgnRegionElementTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnRegionElementTool : DgnRegionElementTool
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * DgnTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/            
        virtual void _GetToolName(WStringR name) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _GetToolName, name); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _PopulateToolSettings() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _PerformEditAction, ERROR, index); }

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
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnTouch(DgnTouchEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, DgnRegionElementTool, _OnTabletQuerySystemGestureStatus, 0, ev); }

        /*---------------------------------------------------------------------------------**//**
        * DgnPrimitiveTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRestartTool() override
            { PYBIND11_OVERRIDE_PURE_EX(void, DgnRegionElementTool, _OnRestartTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _IsSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _CheckSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginDynamics() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _BeginDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _EndDynamics() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _EndDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual IDrawElementAgenda* _GetDrawDynamicsTxnChanges() override
            { PYBIND11_OVERRIDE_EXR(IDrawElementAgenda*, DgnRegionElementTool, _GetDrawDynamicsTxnChanges, nullptr, ); }

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
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetWantMakeCopy, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetWantGGLock(bool val) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetWantGGLock, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantMakeCopy() const override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantMakeCopy, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantCheckGGLock() const override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantCheckGGLock, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElementCopyContextP _GetCopyContext() override
            { PYBIND11_OVERRIDE_EXR(ElementCopyContextP, DgnRegionElementTool, _GetCopyContext, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ClearCopyContext() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _ClearCopyContext, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoOperationForModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _DoOperationForModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnPreElementModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _OnPreElementModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * DgnElementSetTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnInstall, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _NeedPointForDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForSelection() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _NeedPointForSelection, false, ); }

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
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnResymbolize, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawInit(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnRedrawInit, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawFinish(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnRedrawFinish, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnRedrawComplete(ViewContextR context) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _OnRedrawComplete, ERROR, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAutoLocate() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantAutoLocate, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitSource _GetHitSource() const override
            { PYBIND11_OVERRIDE_EXR(HitSource, DgnRegionElementTool, _GetHitSource, HitSource::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetHitSource(HitSource source) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetHitSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RefLocateOption _GetReferenceLocateOptions() override
            { PYBIND11_OVERRIDE_EXR(RefLocateOption, DgnRegionElementTool, _GetReferenceLocateOptions, RefLocateOption::REF_LOCATE_Normal, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCursor(bool enableLocate) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetLocateCursor, enableLocate); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual size_t _GetAdditionalLocateNumRequired() override
            { PYBIND11_OVERRIDE_EXR(size_t, DgnRegionElementTool, _GetAdditionalLocateNumRequired, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitPathCP _DoLocate(DgnButtonEventCR ev, bool newSearch, ComponentMode complexComponent) override
            { PYBIND11_OVERRIDE_EXR(HitPathCP, DgnRegionElementTool, _DoLocate, nullptr, ev, newSearch, complexComponent); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ComponentMode _GetComponentMode() override
            { PYBIND11_OVERRIDE_EXR(ComponentMode, DgnRegionElementTool, _GetComponentMode, ComponentMode::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _LocateOneElement(DgnButtonEventCR ev, bool newSearch) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _LocateOneElement, ev, newSearch); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual EditElementHandleP _BuildLocateAgenda(HitPathCP path, DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(EditElementHandleP, DgnRegionElementTool, _BuildLocateAgenda, nullptr, path, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _RemoveAgendaElement(EditElementHandleR el) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _RemoveAgendaElement, el); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginPickElements() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _BeginPickElements, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _IsDragSelectActive() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, DgnRegionElementTool, _IsDragSelectActive, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _GetDragAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _BuildDragSelectAgenda(FenceParamsP fp, DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _BuildDragSelectAgenda, false, fp, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragSelectOverlapMode(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _GetDragSelectOverlapMode, false, ev); }

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
        virtual bool _NotifyListeners(ElementAgendaR agenda, AgendaOperation agendaOp, AgendaModify agendaModify, AgendaEvent agendaEvt, void* eventArg = NULL) override
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
            { PYBIND11_OVERRIDE_EXR(AgendaOperation, DgnRegionElementTool, _GetAgendaOperation, AgendaOperation::NotSpecified, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AgendaModify _GetAgendaModify() override
            { PYBIND11_OVERRIDE_EXR(AgendaModify, DgnRegionElementTool, _GetAgendaModify, AgendaModify::Original, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _UseActiveFence() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _UseActiveFence, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesFence _AllowFence() override
            { PYBIND11_OVERRIDE_EXR(UsesFence, DgnRegionElementTool, _AllowFence, UsesFence::USES_FENCE_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesSelection _AllowSelection() override
            { PYBIND11_OVERRIDE_EXR(UsesSelection, DgnRegionElementTool, _AllowSelection, UsesSelection::USES_SS_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetPreferredElemSource() override
            { PYBIND11_OVERRIDE_EXR(ElemSource, DgnRegionElementTool, _GetPreferredElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetElemSource() const override
            { PYBIND11_OVERRIDE_EXR(ElemSource, DgnRegionElementTool, _GetElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetElemSource(ElemSource source) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetElemSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _HiliteFenceElems() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _HiliteFenceElems, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ModifyAgendaEntries() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _ModifyAgendaEntries, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BuildAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _BuildAgenda, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _GetAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetAnchorPoint(DPoint3dCP anchorPt) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetAnchorPoint, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DgnModelRefP _GetDestinationModelRef() override
            { PYBIND11_OVERRIDE_EXR(DgnModelRefP, DgnRegionElementTool, _GetDestinationModelRef, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceOverlap() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _IsFenceOverlap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceVoid() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _IsFenceVoid, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceClip() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _IsFenceClip, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _SetupForModify(DgnButtonEventCR ev, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _SetupForModify, false, ev, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ClipResult _GetFenceClipResult() override
            { PYBIND11_OVERRIDE_EXR(ClipResult, DgnRegionElementTool, _GetFenceClipResult, ClipResult::CLIP_RESULT_NotSupported, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoFenceClip() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _DoFenceClip, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModifyClip(EditElementHandleR el, FenceParamsP fp, FenceClipFlags options) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _OnElementModifyClip, ERROR, el, fp, options); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UInt32 _GetGroupOperationCount() override
            { PYBIND11_OVERRIDE_EXR(UInt32, DgnRegionElementTool, _GetGroupOperationCount, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PreModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _PreModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ModifyAgendaGroup(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp, UInt32 iGroupOp, bool redraw) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _ModifyAgendaGroup, ERROR, ev, agendaOp, agendaModify, isGroupOp, iGroupOp, redraw); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PostModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _PostModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * IViewTransients overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        
        /*---------------------------------------------------------------------------------**//**
        * DgnRegionElementTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        using RegionParamsCR = DgnPlatform::RegionParams const&;
        virtual DgnPlatform::RegionParams const& _GetRegionParams() override
            { PYBIND11_OVERRIDE_PURE(RegionParamsCR, DgnRegionElementTool, _GetRegionParams, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RegionCreateMode _GetRegionCreateMode() override
            { PYBIND11_OVERRIDE_PURE_EXR(RegionCreateMode, DgnRegionElementTool, _GetRegionCreateMode, RegionCreateMode::REGION_CREATE_ByParams, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual BentleyStatus _OnProcessRegionResult(EditElementHandleR elHandle) override
                    {
                    try
                        {
                        py::gil_scoped_acquire gil;
                        py::function func = py::get_override(this, "_OnProcessRegionResult");
                        if (func)
                            {
                            EditElementHandleP elHandleP = &elHandle;

                            auto obj = func(elHandleP);
                            BentleyStatus retVal = obj.cast<BentleyStatus>();

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
        virtual StatusInt _DoComputeRegionResult(ElementAgendaR result, DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _DoComputeRegionResult, ERROR, result, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _GetRegionPreviewSymbology(UInt32& lineColorTBGR, UInt32& fillColorTBGR, UInt32& lineWeight, UInt32& lineStyle, ViewportR vp, DgnDrawMode mode) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_GetRegionPreviewSymbology");
                if (func)
                    {
                    auto obj = func(vp, mode);
                    auto tuple = obj.cast<py::tuple>();
                    lineColorTBGR = tuple[0].cast<UInt32>();
                    fillColorTBGR = tuple[1].cast<UInt32>();
                    lineWeight = tuple[2].cast<UInt32>();
                    lineStyle = tuple[3].cast<UInt32>();
                    }
                else
                    __super::_GetRegionPreviewSymbology(lineColorTBGR, fillColorTBGR, lineWeight, lineStyle, vp, mode);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);                
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WCharCP _GetAssociativeRegionName() override
            { PYBIND11_OVERRIDE_EXR(WCharCP, DgnRegionElementTool, _GetAssociativeRegionName, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _OnElementModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantProcessOriginals() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantProcessOriginals, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantFloodDynamicArea() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantFloodDynamicArea, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AllowPhysicallyClosed() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _AllowPhysicallyClosed, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AcceptClosedElement(ElementHandleCR eh, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _AcceptClosedElement, false, eh, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsModifyOriginal() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _IsModifyOriginal, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DoGroups() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _DoGroups, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAccuSnap() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantAccuSnap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAdditionalLocate(DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _WantAdditionalLocate, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedAcceptPoint() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _NeedAcceptPoint, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AcceptIdentifiesNext() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _AcceptIdentifiesNext, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _AllowDragSelect() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, DgnRegionElementTool, _AllowDragSelect, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckStop() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _CheckStop, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ResetStop() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _ResetStop, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DrawTransients(ViewContextR context, bool isPreUpdate) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _DrawTransients, context, isPreUpdate); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ProcessAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnRegionElementTool, _ProcessAgenda, ERROR, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _HiliteAgendaEntries(bool changed) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _HiliteAgendaEntries, changed); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _UnHiliteAgendaEntries(bool empty) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _UnHiliteAgendaEntries, empty); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPostLocate(HitPathCP path, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnPostLocate, false, path, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _FilterAgendaEntries() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _FilterAgendaEntries, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCriteria() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetLocateCriteria, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetupAndPromptForNextAction() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _SetupAndPromptForNextAction, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDynamicFrame(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnDynamicFrame, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifyComplete(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnModifyComplete, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnResetButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnRegionElementTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoPreviousStep() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnUndoPreviousStep, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnCleanup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, DgnRegionElementTool, _OnPostInstall, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnRegionElementTool(py::module_& m)
    {
    //===================================================================================
    // struct DgnRegionElementTool
    py::class_< DgnRegionElementTool, RefCountedPtr<DgnRegionElementTool>, PyDgnRegionElementTool, DgnElementSetTool/*, IViewTransients*/> c1(m, "DgnRegionElementTool");

    if (true)
        {
        //===================================================================================
        // enum RegionCreateMode
        py::enum_< DgnRegionElementTool::RegionCreateMode>(c1, "RegionCreateMode", py::arithmetic())
            .value("eREGION_CREATE_Elements", DgnRegionElementTool::REGION_CREATE_Elements)
            .value("eREGION_CREATE_ByParams", DgnRegionElementTool::REGION_CREATE_ByParams)
            .value("eREGION_CREATE_Points", DgnRegionElementTool::REGION_CREATE_Points)
            .value("eREGION_CREATE_Fence", DgnRegionElementTool::REGION_CREATE_Fence)
            .export_values();

        //===================================================================================
        // enum RegionToolPhase
        py::enum_< DgnRegionElementTool::RegionToolPhase>(c1, "RegionToolPhase", py::arithmetic())
            .value("eREGION_PHASE_SelectBoundaries", DgnRegionElementTool::REGION_PHASE_SelectBoundaries)
            .value("eREGION_PHASE_CreateRegion", DgnRegionElementTool::REGION_PHASE_CreateRegion)
            .value("eREGION_PHASE_ProcessOriginals", DgnRegionElementTool::REGION_PHASE_ProcessOriginals)
            .export_values();
        }

    c1.def_property_readonly("RegionContext", &DgnRegionElementToolPub::GetRegionContext);
    c1.def("GetRegionContext", &DgnRegionElementToolPub::GetRegionContext, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("CurrentToolPhase", &DgnRegionElementToolPub::GetCurrentToolPhase);
    c1.def("GetCurrentToolPhase", &DgnRegionElementToolPub::GetCurrentToolPhase);
    
    c1.def("IsFloodRegionSelected", &DgnRegionElementToolPub::IsFloodRegionSelected);

    c1.def("_GetRegionParams", &DgnRegionElementToolPub::_GetRegionParams, py::return_value_policy::reference_internal);
    c1.def("_GetRegionCreateMode", &DgnRegionElementToolPub::_GetRegionCreateMode);
    c1.def("_OnProcessRegionResult", &DgnRegionElementToolPub::_OnProcessRegionResult, "elHandle"_a);
    c1.def("_DoComputeRegionResult", &DgnRegionElementToolPub::_DoComputeRegionResult, "result"_a, "ev"_a);

    c1.def("_GetRegionPreviewSymbology", [] (DgnRegionElementTool& self, ViewportR vp, DgnDrawMode mode)
           {
           UInt32 lineColorTBGR = 0, fillColorTBGR = 0, lineWeight = 0, lineStyle = 0;
           static_cast<DgnRegionElementToolPub&>(self)._GetRegionPreviewSymbology(lineColorTBGR, fillColorTBGR, lineWeight, lineStyle, vp, mode);
           return py::make_tuple(lineColorTBGR, fillColorTBGR, lineWeight, lineStyle);
           }, "vp"_a, "mode"_a);

    c1.def("_GetAssociativeRegionName", &DgnRegionElementToolPub::_GetAssociativeRegionName, py::return_value_policy::reference_internal);
    c1.def("_OnElementModify", &DgnRegionElementToolPub::_OnElementModify, "eeh"_a);
    c1.def("_WantProcessOriginals", &DgnRegionElementToolPub::_WantProcessOriginals);
    c1.def("_WantFloodDynamicArea", &DgnRegionElementToolPub::_WantFloodDynamicArea);
    c1.def("_AllowPhysicallyClosed", &DgnRegionElementToolPub::_AllowPhysicallyClosed);
    c1.def("_AcceptClosedElement", &DgnRegionElementToolPub::_AcceptClosedElement, "eh"_a, "cantAcceptReason"_a);
    c1.def(py::init<>());
    }