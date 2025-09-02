/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\locatesubentitytool.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/DgnElementSetTool.h>
#include <DgnView/LocateSubEntityTool.h>



static const char * __doc_Bentley_DgnPlatform_LocateSubEntityTool_InitBoresite =R"doc(Compute boresite ray from space point and world to local matrix. (See
GetLocateInfo).)doc";

static const char * __doc_Bentley_DgnPlatform_LocateSubEntityTool_GetLocateInfo =R"doc(Compute locate information from button event GetRawPoint (adjusted to
eye). The spacePoint and maxDistance are returned in local coordinates
of path.)doc";

static const char * __doc_Bentley_DgnPlatform_LocateSubEntityTool_GetSpacePoint =R"doc(Compute space point from button event GetPoint. The spacePoint is
returned in local coordinates of path.)doc";

//=======================================================================================
// Publicist class for ElementGraphicsTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct ElementGraphicsToolPub : ElementGraphicsTool
    {
    public:
        // ElementGraphicsTool
        using ElementGraphicsTool::_CollectCurves;
        using ElementGraphicsTool::_CollectSurfaces;
        using ElementGraphicsTool::_CollectSolids;
        using ElementGraphicsTool::_CollectTextBoundaries;
        using ElementGraphicsTool::_CollectComplexComponents;
        using ElementGraphicsTool::_GetCollectDrawPurpose;
        using ElementGraphicsTool::GetElementGraphicsCache;
        using ElementGraphicsTool::GetElementGraphicsCacheCount;
        using ElementGraphicsTool::GetDisplayPath;
        using ElementGraphicsTool::IsFromLocatedComponent;
        using ElementGraphicsTool::GetLocatedComponentPath;
        using ElementGraphicsTool::TryGetAsBRep;
        using ElementGraphicsTool::TryGetAsPrimitive;
        using ElementGraphicsTool::TryGetAsSurface;
        using ElementGraphicsTool::TryGetAsPolyface;
        using ElementGraphicsTool::TryGetAsCurveVector;
        using ElementGraphicsTool::IsGeometrySolid;
        using ElementGraphicsTool::IsGeometrySheet;
        using ElementGraphicsTool::IsGeometryWire;
        using ElementGraphicsTool::IsGeometryMissing;
        using ElementGraphicsTool::_DoCollectElementGraphics;
        using ElementGraphicsTool::_OnProcessSolidKernelEntity;
        using ElementGraphicsTool::_OnProcessSolidPrimitive;
        using ElementGraphicsTool::_OnProcessBsplineSurface;
        using ElementGraphicsTool::_OnProcessPolyface;
        using ElementGraphicsTool::_OnProcessCurveVector;
        using ElementGraphicsTool::_BuildLocateAgenda;
        using ElementGraphicsTool::_IsElementValidForOperation;
        using ElementGraphicsTool::_OnPostLocate;
        using ElementGraphicsTool::_FilterAgendaEntries;
        using ElementGraphicsTool::_OnCleanup;
    };

//=======================================================================================
// Trampoline class for ElementGraphicsTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyElementGraphicsTool : ElementGraphicsTool
    {
    public:
        using ElementGraphicsTool::ElementGraphicsTool;

        /*---------------------------------------------------------------------------------**//**
        * DgnTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _GetToolName(WStringR name) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_GetToolName");
                if (func)
                    {
                    auto obj = func(name);
                    auto tuple = obj.cast<WString>();
                    name = tuple;
                    }
                else
                    __super::_GetToolName(name);

                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _PopulateToolSettings() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _PerformEditAction, ERROR, index); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPreFilterButtonEvent(ViewportP vp, bool& testDefault) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnPreFilterButtonEvent, false, vp, testDefault); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnTouch(DgnTouchEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, ElementGraphicsTool, _OnTabletQuerySystemGestureStatus, 0, ev); }

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
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetWantMakeCopy, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/            
        virtual void _SetWantGGLock(bool val) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetWantGGLock, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantMakeCopy() const override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _WantMakeCopy, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantCheckGGLock() const override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _WantCheckGGLock, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ClearCopyContext() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _ClearCopyContext, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoOperationForModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _DoOperationForModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnPreElementModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _OnPreElementModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ResetStop() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _ResetStop, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckStop() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CheckStop, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * DgnPrimitiveTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRestartTool() override
            { PYBIND11_OVERRIDE_PURE_EX(void, ElementGraphicsTool, _OnRestartTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _IsSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CheckSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoPreviousStep() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnUndoPreviousStep, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginDynamics() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _BeginDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _EndDynamics() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _EndDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual IDrawElementAgenda* _GetDrawDynamicsTxnChanges() override
            { PYBIND11_OVERRIDE_EXR(IDrawElementAgenda*, ElementGraphicsTool, _GetDrawDynamicsTxnChanges, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * DgnElementSetTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnInstall, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnPostInstall, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetupAndPromptForNextAction() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetupAndPromptForNextAction, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedAcceptPoint() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _NeedAcceptPoint, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _NeedPointForDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForSelection() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _NeedPointForSelection, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AcceptIdentifiesNext() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _AcceptIdentifiesNext, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _WantDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDynamicFrame(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnDynamicFrame, ev); }

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
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnResymbolize, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawInit(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnRedrawInit, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawFinish(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnRedrawFinish, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnRedrawComplete(ViewContextR context) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _OnRedrawComplete, ERROR, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnResetButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAccuSnap() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _WantAccuSnap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAutoLocate() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _WantAutoLocate, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitSource _GetHitSource() const override
            { PYBIND11_OVERRIDE_EXR(HitSource, ElementGraphicsTool, _GetHitSource, HitSource::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetHitSource(HitSource source) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetHitSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RefLocateOption _GetReferenceLocateOptions() override
            { PYBIND11_OVERRIDE_EXR(RefLocateOption, ElementGraphicsTool, _GetReferenceLocateOptions, RefLocateOption::REF_LOCATE_Normal, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCriteria() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetLocateCriteria, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCursor(bool enableLocate) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetLocateCursor, enableLocate); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DoGroups() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _DoGroups, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual size_t _GetAdditionalLocateNumRequired() override
            { PYBIND11_OVERRIDE_EXR(size_t, ElementGraphicsTool, _GetAdditionalLocateNumRequired, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAdditionalLocate(DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _WantAdditionalLocate, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitPathCP _DoLocate(DgnButtonEventCR ev, bool newSearch, ComponentMode complexComponent) override
            { PYBIND11_OVERRIDE_EXR(HitPathCP, ElementGraphicsTool, _DoLocate, nullptr, ev, newSearch, complexComponent); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ComponentMode _GetComponentMode() override
            { PYBIND11_OVERRIDE_EXR(ComponentMode, ElementGraphicsTool, _GetComponentMode, ComponentMode::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _LocateOneElement(DgnButtonEventCR ev, bool newSearch) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _LocateOneElement, ev, newSearch); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _RemoveAgendaElement(EditElementHandleR el) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _RemoveAgendaElement, el); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginPickElements() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _BeginPickElements, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _AllowDragSelect() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, ElementGraphicsTool, _AllowDragSelect, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _IsDragSelectActive() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, ElementGraphicsTool, _IsDragSelectActive, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _GetDragAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _BuildDragSelectAgenda(FenceParamsP fp, DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _BuildDragSelectAgenda, false, fp, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragSelectOverlapMode(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _GetDragSelectOverlapMode, false, ev); }

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
            { PYBIND11_OVERRIDE_EXR(AgendaOperation, ElementGraphicsTool, _GetAgendaOperation, AgendaOperation::NotSpecified, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AgendaModify _GetAgendaModify() override
            { PYBIND11_OVERRIDE_EXR(AgendaModify, ElementGraphicsTool, _GetAgendaModify, AgendaModify::Original, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _UseActiveFence() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _UseActiveFence, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesFence _AllowFence() override
            { PYBIND11_OVERRIDE_EXR(UsesFence, ElementGraphicsTool, _AllowFence, UsesFence::USES_FENCE_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesSelection _AllowSelection() override
            { PYBIND11_OVERRIDE_EXR(UsesSelection, ElementGraphicsTool, _AllowSelection, UsesSelection::USES_SS_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetPreferredElemSource() override
            { PYBIND11_OVERRIDE_EXR(ElemSource, ElementGraphicsTool, _GetPreferredElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetElemSource() const override
            { PYBIND11_OVERRIDE_EXR(ElemSource, ElementGraphicsTool, _GetElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetElemSource(ElemSource source) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetElemSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _HiliteFenceElems() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _HiliteFenceElems, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _HiliteAgendaEntries(bool changed) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _HiliteAgendaEntries, changed); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _UnHiliteAgendaEntries(bool empty) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _UnHiliteAgendaEntries, empty); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ModifyAgendaEntries() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _ModifyAgendaEntries, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BuildAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _BuildAgenda, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _GetAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetAnchorPoint(DPoint3dCP anchorPt) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _SetAnchorPoint, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsModifyOriginal() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _IsModifyOriginal, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DgnModelRefP _GetDestinationModelRef() override
            { PYBIND11_OVERRIDE_EXR(DgnModelRefP, ElementGraphicsTool, _GetDestinationModelRef, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceOverlap() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _IsFenceOverlap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceVoid() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _IsFenceVoid, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceClip() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _IsFenceClip, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _SetupForModify(DgnButtonEventCR ev, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _SetupForModify, false, ev, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ClipResult _GetFenceClipResult() override
            { PYBIND11_OVERRIDE_EXR(ClipResult, ElementGraphicsTool, _GetFenceClipResult, ClipResult::CLIP_RESULT_NotSupported, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoFenceClip() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _DoFenceClip, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModify(EditElementHandleR el) override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, ElementGraphicsTool, _OnElementModify, ERROR, el); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModifyClip(EditElementHandleR el, FenceParamsP fp, FenceClipFlags options) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _OnElementModifyClip, ERROR, el, fp, options); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifyComplete(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnModifyComplete, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UInt32 _GetGroupOperationCount() override
            { PYBIND11_OVERRIDE_EXR(UInt32, ElementGraphicsTool, _GetGroupOperationCount, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PreModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _PreModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ModifyAgendaGroup(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp, UInt32 iGroupOp, bool redraw) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _ModifyAgendaGroup, ERROR, ev, agendaOp, agendaModify, isGroupOp, iGroupOp, redraw); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PostModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _PostModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ProcessAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, ElementGraphicsTool, _ProcessAgenda, ERROR, ev); }

        /*---------------------------------------------------------------------------------**//**
        * ElementGraphicsTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectCurves() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CollectCurves, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectSurfaces() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CollectSurfaces, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectSolids() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CollectSolids, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectTextBoundaries() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CollectTextBoundaries, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectComplexComponents() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _CollectComplexComponents, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DrawPurpose _GetCollectDrawPurpose() override
            { PYBIND11_OVERRIDE_EXR(DrawPurpose, ElementGraphicsTool, _GetCollectDrawPurpose, DrawPurpose::CaptureGeometry, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DoCollectElementGraphics(ElementHandleCR eh) override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _DoCollectElementGraphics, eh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual BentleyStatus _OnProcessSolidKernelEntity(ISolidKernelEntityPtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessSolidKernelEntity");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessSolidKernelEntity(geomPtr, path);

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
        virtual BentleyStatus _OnProcessSolidPrimitive(ISolidPrimitivePtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessSolidPrimitive");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessSolidPrimitive(geomPtr, path);

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
        virtual BentleyStatus _OnProcessBsplineSurface(MSBsplineSurfacePtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessBsplineSurface");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessBsplineSurface(geomPtr, path);

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
        virtual BentleyStatus _OnProcessPolyface(PolyfaceHeaderPtr& geomPtr, DisplayPathCR path) override
            {
             try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessPolyface");
                if (func)
                    {
                    py::object geomP = py::cast(geomPtr, py::return_value_policy::reference);
                    auto obj = func(geomP, path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessPolyface(geomPtr, path);

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
        virtual BentleyStatus _OnProcessCurveVector(CurveVectorPtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessCurveVector");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessCurveVector(geomPtr, path);

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
        virtual EditElementHandleP _BuildLocateAgenda(HitPathCP path, DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(EditElementHandleP, ElementGraphicsTool, _BuildLocateAgenda, nullptr, path, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsElementValidForOperation(ElementHandleCR eh, HitPathCP path, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _IsElementValidForOperation, false, eh, path, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPostLocate(HitPathCP path, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _OnPostLocate, false, path, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _FilterAgendaEntries() override
            { PYBIND11_OVERRIDE_EXR(bool, ElementGraphicsTool, _FilterAgendaEntries, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, ElementGraphicsTool, _OnCleanup, ); }
    };

//=======================================================================================
// Publicist class for LocateSubEntityTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct LocateSubEntityToolPub : LocateSubEntityTool
    {
    public:
        // LocateSubEntityTool
        using LocateSubEntityTool::_GetSubEntityTypeMask;
        using LocateSubEntityTool::_RequireSubEntitySupport;
        using LocateSubEntityTool::_AcceptIdentifiesSubEntity;
        using LocateSubEntityTool::_GetRequiredSubEntityCount;
        using LocateSubEntityTool::_GetMaximumSubEntityHits;
        using LocateSubEntityTool::_AllowSubEntityDeselect;
        using LocateSubEntityTool::_FilterSubEntities;
        using LocateSubEntityTool::_WantSubEntityDisplay;

        using LocateSubEntityTool::GetAcceptedSubEntities;
        using LocateSubEntityTool::ResetSubEntityLocate;
        using LocateSubEntityTool::FindAgendaEntry;
        using LocateSubEntityTool::GetIElementGraphicsPtr;
        using LocateSubEntityTool::CreateSubEntityQvElem;
        using LocateSubEntityTool::IsSolidKernelSubEntity;
        using LocateSubEntityTool::TryGetAsCurveLocationDetail;
        using LocateSubEntityTool::TryGetAsFacetLocationDetail;
        using LocateSubEntityTool::TryGetAsSolidLocationDetail;
        using LocateSubEntityTool::GetFaceParameterRange;
        using LocateSubEntityTool::EvaluateFace;
        using LocateSubEntityTool::GetSubEntityGeometry;
        using LocateSubEntityTool::DoPickSubEntities;
        using LocateSubEntityTool::DoPickSurfaces;
        using LocateSubEntityTool::DoPickFace;
        using LocateSubEntityTool::GetClosestFace;

        using LocateSubEntityTool::_GetSubEntityColor;
        using LocateSubEntityTool::_GetSubEntityWeight;
        using LocateSubEntityTool::_GetSubEntityStyle;
        using LocateSubEntityTool::_PushSubEntitySymbology;
        using LocateSubEntityTool::_PopSubEntitySymbology;
        using LocateSubEntityTool::_DrawSubEntity;
        using LocateSubEntityTool::_DrawGeometry;
        using LocateSubEntityTool::_WantAdditionalSubEntities;
        using LocateSubEntityTool::_AllowMissToAccept;
        using LocateSubEntityTool::_DoLocateSubEntity;
        using LocateSubEntityTool::_IsValidForSubEntitySelection;        
    };

//=======================================================================================
// Trampoline class for LocateSubEntityTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyLocateSubEntityTool : LocateSubEntityTool
    {
    public:
        using LocateSubEntityTool::LocateSubEntityTool;

        /*---------------------------------------------------------------------------------**//**
        * DgnTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _GetToolName(WStringR name) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_GetToolName");
                if (func)
                    {
                    auto obj = func(name);
                    auto tuple = obj.cast<WString>();
                    name = tuple;
                    }
                else
                    __super::_GetToolName(name);

                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _PopulateToolSettings() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _PerformEditAction, ERROR, index); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPreFilterButtonEvent(ViewportP vp, bool& testDefault) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnPreFilterButtonEvent, false, vp, testDefault); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnTouch(DgnTouchEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, LocateSubEntityTool, _OnTabletQuerySystemGestureStatus, 0, ev); }

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
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetWantMakeCopy, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/            
        virtual void _SetWantGGLock(bool val) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetWantGGLock, val); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantMakeCopy() const override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantMakeCopy, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantCheckGGLock() const override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantCheckGGLock, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ClearCopyContext() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _ClearCopyContext, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoOperationForModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _DoOperationForModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnPreElementModify(EditElementHandleR eeh) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _OnPreElementModify, ERROR, eeh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ResetStop() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _ResetStop, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckStop() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CheckStop, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * DgnPrimitiveTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRestartTool() override
            { PYBIND11_OVERRIDE_PURE_EX(void, LocateSubEntityTool, _OnRestartTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CheckSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoPreviousStep() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnUndoPreviousStep, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginDynamics() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _BeginDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _EndDynamics() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _EndDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual IDrawElementAgenda* _GetDrawDynamicsTxnChanges() override
            { PYBIND11_OVERRIDE_EXR(IDrawElementAgenda*, LocateSubEntityTool, _GetDrawDynamicsTxnChanges, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * DgnElementSetTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnInstall, false, ); }        

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetupAndPromptForNextAction() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetupAndPromptForNextAction, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedAcceptPoint() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _NeedAcceptPoint, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _NeedPointForDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _NeedPointForSelection() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _NeedPointForSelection, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AcceptIdentifiesNext() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _AcceptIdentifiesNext, false, ); }

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
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnResymbolize, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawInit(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnRedrawInit, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRedrawFinish(ViewContextR context) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnRedrawFinish, context); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnRedrawComplete(ViewContextR context) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _OnRedrawComplete, ERROR, context); }                

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAutoLocate() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantAutoLocate, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitSource _GetHitSource() const override
            { PYBIND11_OVERRIDE_EXR(HitSource, LocateSubEntityTool, _GetHitSource, HitSource::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetHitSource(HitSource source) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetHitSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual RefLocateOption _GetReferenceLocateOptions() override
            { PYBIND11_OVERRIDE_EXR(RefLocateOption, LocateSubEntityTool, _GetReferenceLocateOptions, RefLocateOption::REF_LOCATE_Normal, ); }        

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCursor(bool enableLocate) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetLocateCursor, enableLocate); }        

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual size_t _GetAdditionalLocateNumRequired() override
            { PYBIND11_OVERRIDE_EXR(size_t, LocateSubEntityTool, _GetAdditionalLocateNumRequired, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAdditionalLocate(DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantAdditionalLocate, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual HitPathCP _DoLocate(DgnButtonEventCR ev, bool newSearch, ComponentMode complexComponent) override
            { PYBIND11_OVERRIDE_EXR(HitPathCP, LocateSubEntityTool, _DoLocate, nullptr, ev, newSearch, complexComponent); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ComponentMode _GetComponentMode() override
            { PYBIND11_OVERRIDE_EXR(ComponentMode, LocateSubEntityTool, _GetComponentMode, ComponentMode::None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _LocateOneElement(DgnButtonEventCR ev, bool newSearch) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _LocateOneElement, ev, newSearch); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _RemoveAgendaElement(EditElementHandleR el) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _RemoveAgendaElement, el); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginPickElements() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _BeginPickElements, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _AllowDragSelect() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, LocateSubEntityTool, _AllowDragSelect, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesDragSelect _IsDragSelectActive() override
            { PYBIND11_OVERRIDE_EXR(UsesDragSelect, LocateSubEntityTool, _IsDragSelectActive, UsesDragSelect::USES_DRAGSELECT_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _GetDragAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _BuildDragSelectAgenda(FenceParamsP fp, DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _BuildDragSelectAgenda, false, fp, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetDragSelectOverlapMode(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _GetDragSelectOverlapMode, false, ev); }

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
            { PYBIND11_OVERRIDE_EXR(AgendaOperation, LocateSubEntityTool, _GetAgendaOperation, AgendaOperation::NotSpecified, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AgendaModify _GetAgendaModify() override
            { PYBIND11_OVERRIDE_EXR(AgendaModify, LocateSubEntityTool, _GetAgendaModify, AgendaModify::Original, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _UseActiveFence() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _UseActiveFence, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesFence _AllowFence() override
            { PYBIND11_OVERRIDE_EXR(UsesFence, LocateSubEntityTool, _AllowFence, UsesFence::USES_FENCE_None, ); }        

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetPreferredElemSource() override
            { PYBIND11_OVERRIDE_EXR(ElemSource, LocateSubEntityTool, _GetPreferredElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ElemSource _GetElemSource() const override
            { PYBIND11_OVERRIDE_EXR(ElemSource, LocateSubEntityTool, _GetElemSource, ElemSource::SOURCE_SelectionSet, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetElemSource(ElemSource source) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetElemSource, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _HiliteFenceElems() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _HiliteFenceElems, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _HiliteAgendaEntries(bool changed) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _HiliteAgendaEntries, changed); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _UnHiliteAgendaEntries(bool empty) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _UnHiliteAgendaEntries, empty); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ModifyAgendaEntries() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _ModifyAgendaEntries, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BuildAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _BuildAgenda, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _GetAnchorPoint(DPoint3dP anchorPt) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _GetAnchorPoint, false, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetAnchorPoint(DPoint3dCP anchorPt) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetAnchorPoint, anchorPt); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsModifyOriginal() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsModifyOriginal, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DgnModelRefP _GetDestinationModelRef() override
            { PYBIND11_OVERRIDE_EXR(DgnModelRefP, LocateSubEntityTool, _GetDestinationModelRef, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceOverlap() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsFenceOverlap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceVoid() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsFenceVoid, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsFenceClip() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsFenceClip, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _SetupForModify(DgnButtonEventCR ev, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _SetupForModify, false, ev, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ClipResult _GetFenceClipResult() override
            { PYBIND11_OVERRIDE_EXR(ClipResult, LocateSubEntityTool, _GetFenceClipResult, ClipResult::CLIP_RESULT_NotSupported, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _DoFenceClip() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _DoFenceClip, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModify(EditElementHandleR el) override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, LocateSubEntityTool, _OnElementModify, ERROR, el); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _OnElementModifyClip(EditElementHandleR el, FenceParamsP fp, FenceClipFlags options) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _OnElementModifyClip, ERROR, el, fp, options); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifyComplete(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnModifyComplete, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UInt32 _GetGroupOperationCount() override
            { PYBIND11_OVERRIDE_EXR(UInt32, LocateSubEntityTool, _GetGroupOperationCount, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PreModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _PreModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ModifyAgendaGroup(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp, UInt32 iGroupOp, bool redraw) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _ModifyAgendaGroup, ERROR, ev, agendaOp, agendaModify, isGroupOp, iGroupOp, redraw); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PostModifyAgenda(DgnButtonEventCR ev, AgendaOperation agendaOp, AgendaModify agendaModify, bool isGroupOp) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _PostModifyAgenda, ev, agendaOp, agendaModify, isGroupOp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _ProcessAgenda(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, LocateSubEntityTool, _ProcessAgenda, ERROR, ev); }

        /*---------------------------------------------------------------------------------**//**
        * ElementGraphicsTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectCurves() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CollectCurves, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectSurfaces() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CollectSurfaces, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectSolids() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CollectSolids, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectTextBoundaries() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CollectTextBoundaries, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CollectComplexComponents() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _CollectComplexComponents, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual DrawPurpose _GetCollectDrawPurpose() override
            { PYBIND11_OVERRIDE_EXR(DrawPurpose, LocateSubEntityTool, _GetCollectDrawPurpose, DrawPurpose::CaptureGeometry, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DoCollectElementGraphics(ElementHandleCR eh) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _DoCollectElementGraphics, eh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual BentleyStatus _OnProcessSolidKernelEntity(ISolidKernelEntityPtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessSolidKernelEntity");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessSolidKernelEntity(geomPtr, path);

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
        virtual BentleyStatus _OnProcessSolidPrimitive(ISolidPrimitivePtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessSolidPrimitive");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessSolidPrimitive(geomPtr, path);

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
        virtual BentleyStatus _OnProcessBsplineSurface(MSBsplineSurfacePtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessBsplineSurface");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessBsplineSurface(geomPtr, path);

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
        virtual BentleyStatus _OnProcessPolyface(PolyfaceHeaderPtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessPolyface");
                if (func)
                    {
                    py::object geomP = py::cast(geomPtr, py::return_value_policy::reference);
                    auto obj = func(geomP, path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessPolyface(geomPtr, path);

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
        virtual BentleyStatus _OnProcessCurveVector(CurveVectorPtr& geomPtr, DisplayPathCR path) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                BentleyStatus retVal = ERROR;
                py::function func = py::get_override(this, "_OnProcessCurveVector");
                if (func)
                    {
                    auto obj = func(geomPtr.get(), path);
                    retVal = obj.cast< BentleyStatus>();
                    }
                else
                    retVal = __super::_OnProcessCurveVector(geomPtr, path);

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
        virtual EditElementHandleP _BuildLocateAgenda(HitPathCP path, DgnButtonEventCP ev) override
            { PYBIND11_OVERRIDE_EXR(EditElementHandleP, LocateSubEntityTool, _BuildLocateAgenda, nullptr, path, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsElementValidForOperation(ElementHandleCR eh, HitPathCP path, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsElementValidForOperation, false, eh, path, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _FilterAgendaEntries() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _FilterAgendaEntries, false, ); }        

        /*---------------------------------------------------------------------------------**//**
        * LocateSubEntityTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UsesSelection _AllowSelection() override
            { PYBIND11_OVERRIDE_EXR(UsesSelection, LocateSubEntityTool, _AllowSelection, UsesSelection::USES_SS_None, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DoGroups() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _DoGroups, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantDynamics() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantDynamics, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAccuSnap() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantAccuSnap, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ISubEntity::SubEntityType _GetSubEntityTypeMask() override
            { PYBIND11_OVERRIDE_EXR(ISubEntity::SubEntityType, LocateSubEntityTool, _GetSubEntityTypeMask, ISubEntity::SubEntityType::SubEntityType_Vertex, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _RequireSubEntitySupport() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _RequireSubEntitySupport, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AcceptIdentifiesSubEntity() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _AcceptIdentifiesSubEntity, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual size_t _GetRequiredSubEntityCount(ISubEntity::SubEntityType entityType) override
            { PYBIND11_OVERRIDE_EXR(size_t, LocateSubEntityTool, _GetRequiredSubEntityCount, 0, entityType); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual size_t _GetMaximumSubEntityHits(ISubEntity::SubEntityType entityType) override
            { PYBIND11_OVERRIDE_EXR(size_t, LocateSubEntityTool, _GetMaximumSubEntityHits, 0, entityType); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AllowSubEntityDeselect() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _AllowSubEntityDeselect, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _FilterSubEntities(bvector<ISubEntityPtr>& subEntities) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _FilterSubEntities, subEntities); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantSubEntityDisplay() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantSubEntityDisplay, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UInt32 _GetSubEntityColor(ViewportR vp, ISubEntity::SubEntityType entityType, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(UInt32, LocateSubEntityTool, _GetSubEntityColor, 0, vp, entityType, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual UInt32 _GetSubEntityWeight(ViewportR vp, ISubEntity::SubEntityType entityType, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(UInt32, LocateSubEntityTool, _GetSubEntityWeight, 0, vp, entityType, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual Int32 _GetSubEntityStyle(ViewportR vp, ISubEntity::SubEntityType entityType, bool isDynamics) override
            { PYBIND11_OVERRIDE_EXR(Int32, LocateSubEntityTool, _GetSubEntityStyle, 0, vp, entityType, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PushSubEntitySymbology(ViewContextR context, ISubEntity::SubEntityType entityType, bool isDynamics) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _PushSubEntitySymbology, context, entityType, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _PopSubEntitySymbology(ViewContextR context, ISubEntity::SubEntityType entityType, bool isDynamics) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _PopSubEntitySymbology, context, entityType, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DrawSubEntity(ElementHandleCR eh, ISubEntityCR subEntity, ViewContextR context, bool isDynamics) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _DrawSubEntity, eh, subEntity, context, isDynamics); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DrawGeometry(ElementHandleCR eh, IElementGraphicsPtr& geomPtr, ViewContextR context) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_DrawGeometry");
                if (func)
                    func(eh, geomPtr.get(), context);
                else
                    __super::_DrawGeometry(eh, geomPtr, context);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DrawTransients(ViewContextR context, bool isPreUpdate) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _DrawTransients, context, isPreUpdate); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDynamicFrame(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnDynamicFrame, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _WantAdditionalSubEntities(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _WantAdditionalSubEntities, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _AllowMissToAccept(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _AllowMissToAccept, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DoLocateSubEntity(DgnButtonEventCR ev, bool newSearch) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _DoLocateSubEntity, false, ev, newSearch); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsValidForSubEntitySelection() override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsValidForSubEntitySelection, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsValidForSubEntitySelection(ElementHandleCR eh) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsValidForSubEntitySelection, false, eh); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsValidForSubEntitySelection(DisplayPathCR path) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _IsValidForSubEntitySelection, false, path); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnPostLocate(HitPathCP path, WStringR cantAcceptReason) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnPostLocate, false, path, cantAcceptReason); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _SetLocateCriteria() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _SetLocateCriteria, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, LocateSubEntityTool, _OnResetButton, false, ev); }        

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnCleanup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, LocateSubEntityTool, _OnPostInstall, ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_LocateSubEntityTool(py::module_& m)
    {
    //===================================================================================
    // struct ElementGraphicsTool
    py::class_<ElementGraphicsTool, RefCountedPtr<ElementGraphicsTool>, PyElementGraphicsTool, DgnElementSetTool> c1(m, "ElementGraphicsTool");

    c1.def(py::init<>());
    c1.def("_CollectCurves", &ElementGraphicsToolPub::_CollectCurves);
    c1.def("_CollectSurfaces", &ElementGraphicsToolPub::_CollectSurfaces);
    c1.def("_CollectSolids", &ElementGraphicsToolPub::_CollectSolids);
    c1.def("_CollectTextBoundaries", &ElementGraphicsToolPub::_CollectTextBoundaries);
    c1.def("_CollectComplexComponents", &ElementGraphicsToolPub::_CollectComplexComponents);
    c1.def("_GetCollectDrawPurpose", &ElementGraphicsToolPub::_GetCollectDrawPurpose);
    c1.def("GetElementGraphicsCache", &ElementGraphicsToolPub::GetElementGraphicsCache, "eh"_a, "geomCache"_a);
    c1.def("GetElementGraphicsCacheCount", &ElementGraphicsToolPub::GetElementGraphicsCacheCount, "eh"_a);

    c1.def("GetDisplayPath", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).GetDisplayPath(geomPtr);
           }, "geom"_a);

    c1.def("IsFromLocatedComponent", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).IsFromLocatedComponent(geomPtr);
           }, "geom"_a);

    c1.def("GetLocatedComponentPath", &ElementGraphicsToolPub::GetLocatedComponentPath, "eh"_a);

    c1.def("TryGetAsBRep", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).TryGetAsBRep(geomPtr);
           }, "geom"_a);

    c1.def("TryGetAsPrimitive", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).TryGetAsPrimitive(geomPtr);
           }, "geom"_a);

    c1.def("TryGetAsSurface", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).TryGetAsSurface(geomPtr);
           }, "geom"_a);

    c1.def("TryGetAsPolyface", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).TryGetAsPolyface(geomPtr);
           }, "geom"_a);

    c1.def("TryGetAsCurveVector", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).TryGetAsCurveVector(geomPtr);
           }, "geom"_a);

    c1.def("IsGeometrySolid", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).IsGeometrySolid(geomPtr);
           }, "geom"_a);

    c1.def("IsGeometrySheet", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).IsGeometrySheet(geomPtr);
           }, "geom"_a);

    c1.def("IsGeometryWire", [] (ElementGraphicsTool& self, IRefCounted* geomP)
           {
           IElementGraphicsPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self).IsGeometryWire(geomPtr);
           }, "geom"_a);

    c1.def("IsGeometryMissing", &ElementGraphicsToolPub::IsGeometryMissing, "eh"_a);
    c1.def("_DoCollectElementGraphics", &ElementGraphicsToolPub::_DoCollectElementGraphics, "eh"_a);
    
    c1.def("_OnProcessSolidKernelEntity", [] (ElementGraphicsTool& self, ISolidKernelEntityP geomP, DisplayPathCR path)
           {
           ISolidKernelEntityPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self)._OnProcessSolidKernelEntity(geomPtr, path);
           }, "geom"_a, "path"_a);

    c1.def("_OnProcessSolidPrimitive", [] (ElementGraphicsTool& self, ISolidPrimitiveP geomP, DisplayPathCR path)
           {
           ISolidPrimitivePtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self)._OnProcessSolidPrimitive(geomPtr, path);
           }, "geom"_a, "path"_a);

    c1.def("_OnProcessBsplineSurface", [] (ElementGraphicsTool& self, RefCountedMSBsplineSurface* geomP, DisplayPathCR path)
           {
           MSBsplineSurfacePtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self)._OnProcessBsplineSurface(geomPtr, path);
           }, "geom"_a, "path"_a);

    c1.def("_OnProcessPolyface", [] (ElementGraphicsTool& self, PolyfaceHeaderP geomP, DisplayPathCR path)
           {
           PolyfaceHeaderPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self)._OnProcessPolyface(geomPtr, path);
           }, "geom"_a, "path"_a);

    c1.def("_OnProcessCurveVector", [] (ElementGraphicsTool& self, CurveVectorP geomP, DisplayPathCR path)
           {
           CurveVectorPtr geomPtr(geomP);
           return static_cast<ElementGraphicsToolPub&>(self)._OnProcessCurveVector(geomPtr, path);
           }, "geom"_a, "path"_a);

    c1.def("_BuildLocateAgenda", &ElementGraphicsToolPub::_BuildLocateAgenda, "path"_a, "ev"_a, py::return_value_policy::reference_internal);
    c1.def("_IsElementValidForOperation", &ElementGraphicsToolPub::_IsElementValidForOperation, "eh"_a, "path"_a, "cantAcceptReason"_a);
    c1.def("_OnPostLocate", &ElementGraphicsToolPub::_OnPostLocate, "path"_a, "cantAcceptReason"_a);
    c1.def("_FilterAgendaEntries", &ElementGraphicsToolPub::_FilterAgendaEntries);
    c1.def("_OnCleanup", &ElementGraphicsToolPub::_OnCleanup);

    //===================================================================================
    // struct LocateSubEntityTool
    py::class_< LocateSubEntityTool, RefCountedPtr< LocateSubEntityTool>, PyLocateSubEntityTool, ElementGraphicsTool/*, IViewTransients*/> c2(m, "LocateSubEntityTool", py::multiple_inheritance());

    c2.def(py::init<>());
    c2.def("_GetSubEntityTypeMask", &LocateSubEntityToolPub::_GetSubEntityTypeMask);
    c2.def("_RequireSubEntitySupport", &LocateSubEntityToolPub::_RequireSubEntitySupport);
    c2.def("_AcceptIdentifiesSubEntity", &LocateSubEntityToolPub::_AcceptIdentifiesSubEntity);
    c2.def("_GetRequiredSubEntityCount", &LocateSubEntityToolPub::_GetRequiredSubEntityCount, "entityType"_a);
    c2.def("_GetMaximumSubEntityHits", &LocateSubEntityToolPub::_GetMaximumSubEntityHits, "entityType"_a);
    c2.def("_AllowSubEntityDeselect", &LocateSubEntityToolPub::_AllowSubEntityDeselect);
    c2.def("_FilterSubEntities", &LocateSubEntityToolPub::_FilterSubEntities, "subEntities"_a);
    c2.def("_WantSubEntityDisplay", &LocateSubEntityToolPub::_WantSubEntityDisplay);
    c2.def("GetAcceptedSubEntities", &LocateSubEntityToolPub::GetAcceptedSubEntities, py::return_value_policy::reference_internal);
    c2.def("ResetSubEntityLocate", &LocateSubEntityToolPub::ResetSubEntityLocate);
    c2.def("FindAgendaEntry", &LocateSubEntityToolPub::FindAgendaEntry, "subEntity"_a, py::return_value_policy::reference_internal);
    c2.def("GetIElementGraphics", &LocateSubEntityToolPub::GetIElementGraphicsPtr, "subEntity"_a);

    c2.def("IsSolidKernelSubEntity", &LocateSubEntityToolPub::IsSolidKernelSubEntity, "subEntity"_a);
    c2.def("TryGetAsCurveLocationDetail", &LocateSubEntityToolPub::TryGetAsCurveLocationDetail, "location"_a, "subEntity"_a);
    c2.def("TryGetAsFacetLocationDetail", &LocateSubEntityToolPub::TryGetAsFacetLocationDetail, "location"_a, "subEntity"_a);
    c2.def("TryGetAsSolidLocationDetail", &LocateSubEntityToolPub::TryGetAsSolidLocationDetail, "location"_a, "subEntity"_a);
    c2.def("GetFaceParameterRange", &LocateSubEntityToolPub::GetFaceParameterRange, "subEntity"_a, "uRange"_a, "vRange"_a);
    c2.def("EvaluateFace", &LocateSubEntityToolPub::EvaluateFace, "subEntity"_a, "point"_a, "normal"_a, "uDir"_a, "vDir"_a, "uvParam"_a);
    
    c2.def("GetSubEntityGeometry", [] (LocateSubEntityTool& self, ISubEntityCR subEntity)
           {
           IGeometryPtr geom;
           auto retVal = static_cast<LocateSubEntityToolPub&>(self).GetSubEntityGeometry(geom, subEntity);
           return py::make_tuple(retVal, geom);
           }, "subEntity"_a);

    c2.def("DoPickSubEntities", &LocateSubEntityToolPub::DoPickSubEntities, "eh"_a, "ev"_a, "intersectEntities"_a, "intersectPts"_a, "intersectParams"_a);
    c2.def("DoPickSurfaces", &LocateSubEntityToolPub::DoPickSurfaces, "eh"_a, "ev"_a, "intersectEntities"_a, "intersectPts"_a, "intersectParams"_a);
    c2.def("DoPickFace", &LocateSubEntityToolPub::DoPickFace, "eh"_a, "subEntity"_a, "ev"_a, "intersectPts"_a, "intersectParams"_a);
    
    c2.def("GetClosestFace", [] (LocateSubEntityTool& self, ElementHandleCR eh, DgnButtonEventCR ev, DPoint3dR closePoint, DPoint2dR closeParam)
           {
           ISubEntityPtr closeEntity;
           auto retVal = static_cast<LocateSubEntityToolPub&>(self).GetClosestFace(eh, ev, closeEntity, closePoint, closeParam);
           return py::make_tuple(retVal, closeEntity);
           }, "eh"_a, "ev"_a, "closePoint"_a, "closeParam"_a);

    c2.def("_GetSubEntityColor", &LocateSubEntityToolPub::_GetSubEntityColor, "vp"_a, "entityType"_a, "isDynamics"_a);
    c2.def("_GetSubEntityWeight", &LocateSubEntityToolPub::_GetSubEntityWeight, "vp"_a, "entityType"_a, "isDynamics"_a);
    c2.def("_GetSubEntityStyle", &LocateSubEntityToolPub::_GetSubEntityStyle, "vp"_a, "entityType"_a, "isDynamics"_a);
    c2.def("_PushSubEntitySymbology", &LocateSubEntityToolPub::_PushSubEntitySymbology, "context"_a, "entityType"_a, "isDynamics"_a);
    c2.def("_PopSubEntitySymbology", &LocateSubEntityToolPub::_PopSubEntitySymbology, "context"_a, "entityType"_a, "isDynamics"_a);
    
    c2.def("_DrawSubEntity", &LocateSubEntityToolPub::_DrawSubEntity, "eh"_a, "entityType"_a, "context"_a, "isDynamics"_a);

    c2.def("_DrawGeometry", [] (LocateSubEntityTool& self, ElementHandleCR eh, IRefCountedP geomP, ViewContextR context)
           {
           IElementGraphicsPtr geomPtr(geomP);
           static_cast<LocateSubEntityToolPub&>(self)._DrawGeometry(eh, geomPtr, context);
           }, "eh"_a, "geom"_a, "context"_a);

    c2.def("_WantAdditionalSubEntities", &LocateSubEntityToolPub::_WantAdditionalSubEntities, "ev"_a);
    c2.def("_AllowMissToAccept", &LocateSubEntityToolPub::_AllowMissToAccept, "ev"_a);
    c2.def("_DoLocateSubEntity", &LocateSubEntityToolPub::_DoLocateSubEntity, "ev"_a, "newSearch"_a);
    
    c2.def("_IsValidForSubEntitySelection", [] (LocateSubEntityTool& self)
           {
           return static_cast<LocateSubEntityToolPub&>(self)._IsValidForSubEntitySelection();
           });

    c2.def("_IsValidForSubEntitySelection", [] (LocateSubEntityTool& self, ElementHandleCR eh)
           {
           return static_cast<LocateSubEntityToolPub&>(self)._IsValidForSubEntitySelection(eh);
           }, "eh"_a);

    c2.def("_IsValidForSubEntitySelection", [] (LocateSubEntityTool& self, DisplayPathCR path)
           {
           return static_cast<LocateSubEntityToolPub&>(self)._IsValidForSubEntitySelection(path);
           }, "path"_a);

    c2.def_static("GetSpacePoint", &LocateSubEntityTool::GetSpacePoint, "spacePoint"_a, "ev"_a, "path"_a, DOC(Bentley, DgnPlatform, LocateSubEntityTool, GetSpacePoint));
    c2.def_static("GetLocateInfo", [] (DPoint3dR spacePoint, DMatrix4dR viewToLocal, DgnButtonEventCR ev, DisplayPathCP path)
                  {
                  double maxDistance = 0;
                  LocateSubEntityTool::GetLocateInfo(spacePoint, viewToLocal, maxDistance, ev, path);
                  return maxDistance;
                  }, "spacePoint"_a, "viewToLocal"_a, "ev"_a, "path"_a, DOC(Bentley, DgnPlatform, LocateSubEntityTool, GetLocateInfo));

    c2.def_static("InitBoresite", &LocateSubEntityTool::InitBoresite, "boresite"_a, "spacePoint"_a, "worldToLocal"_a, DOC(Bentley, DgnPlatform, LocateSubEntityTool, InitBoresite));
    }
