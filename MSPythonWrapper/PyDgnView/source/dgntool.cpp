/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\dgntool.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/DgnTool.h>



static const char * __doc_Bentley_DgnPlatform_DgnPrimitiveTool_CallOnRestartTool =R"doc(Can be called to force restart of active tool in response to an
external event.

See also:
    _OnRestartTool.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnViewTool_GetPreferredViewport =R"doc(Call for viewing tools that have no tool settings or don't require a
data point to determine if there is enough context in which to choose
an initial viewport to use. Takes into account the preference for
viewing tools to apply to the active view. For viewing tools on the
view border, implement as an IconCmdX and setup
HOOKITEMID_ViewBorderIconCmdHook in order to be passed the view number
as unparsedP.

Parameter ``sourceFoundP``:
    OUT Source of preferred viewport.

Parameter ``unparsedP``:
    IN unparsed string containing a view number or NULL.

Parameter ``sourceToSearch``:
    IN Mask of allow sources for preferred viewport,
    PREFERRED_VIEW_Unparsed only used as an output, assumed if
    unparsedP isn't NULL.

Returns:
    Preferred viewport for tool or NULL.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_SetModifierKeyTransitionState =R"doc(Called to set the current modifier transition state.

Returns:
    The id of the current command promnpt. )doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_GetModifierKeyTransitionState =R"doc(Called to get the previous modifier transition state.

Returns:
    The id of the current command promnpt.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_ResetCurrentQualifierMask =R"doc(Internal method to reset the current qualifier mask.

Parameter ``mask``:
    IN New qualifier mask. )doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_SetAdjustedDataPoint =R"doc(Call to set an adjusted point as the last datapoint location. This is
the location that precision key-ins and axis/isometric lock will use.

Parameter ``ev``:
    IN new button event.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_GetCurrentDgnButtonEvent =R"doc(Call to get a button event representing the current cursor location.

Parameter ``ev``:
    IN Current button event.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_InstallTool =R"doc(Call to make this tool instance the current active command.

Returns:
    SUCCESS if new tool instance is now the current command.

See also:
    #_OnInstall #_OnPostInstall)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_SetToolPrompt =R"doc(Not used in Python implementation)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_GetToolPrompt =R"doc(Not used in Python implementation)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_SetToolId =R"doc(Not used in Python implementation override GetToolName instead)doc";

static const char * __doc_Bentley_DgnPlatform_DgnTool_GetToolId =R"doc(Not used in Python implementation override GetToolName instead)doc";

static const char * __doc_Bentley_DgnPlatform_DgnMouseWheelEvent_GetWheelDelta =R"doc(Get the " delta " movement of the mouse wheel (see Microsoft
documentation on mouse wheel events for units.))doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetKeyModifiers =R"doc(Returns:
    the complete key modifier mask when this event occurred.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_IsAltKey =R"doc(Returns:
    true if an Altkey was pressed when this event occurred.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_IsShiftKey =R"doc(Returns:
    true if a Shift key was pressed when this event occurred.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_IsControlKey =R"doc(Returns:
    true if a Control key was pressed when this event occurred.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetButtonSource =R"doc(Get the " input source " for this event. See Inputq_element#hdr.source
(msinputq.h))doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetCoordSource =R"doc(Get the source of this event.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetViewNum =R"doc(Get the view number from the viewport for this event.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_SetViewport =R"doc(Set the viewport.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetViewport =R"doc(Get the viewport in which the cursor resided for this event.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetViewPoint =R"doc(Get the location of the cursor in view coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetRawPoint =R"doc(Get the 'raw' (before adjustment for locks and snaps) location of the
cursor for this event in active coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_SetPoint =R"doc(Set the adjusted point location for this event (sometimes useful in
DgnTools).)doc";

static const char * __doc_Bentley_DgnPlatform_DgnButtonEvent_GetPoint =R"doc(Get the location of the cursor for this event in active coordinates.
The point has already been adjusted for locks and snaps.)doc";

//=======================================================================================
// Publicist class for DgnTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct DgnToolPub : DgnTool
    {
    public:
        using DgnTool::SetCmdName;
        using DgnTool::_GetToolName;
        using DgnTool::_PopulateToolSettings;
        using DgnTool::_InstallToolImplementation;
        using DgnTool::_OnInstall;
        using DgnTool::_OnPostInstall;
        using DgnTool::_ExitTool;
        using DgnTool::_OnReinitialize;
        using DgnTool::_OnCleanup;
        using DgnTool::_DecorateScreen;
        using DgnTool::_OnResetButton;
        using DgnTool::_OnResetButtonUp;
        using DgnTool::_OnDataButton;
        using DgnTool::_OnDataButtonUp;
        using DgnTool::_OnModelMotion;
        using DgnTool::_OnModelNoMotion;
        using DgnTool::_OnModelMotionStopped;
        using DgnTool::_OnModelStartDrag;
        using DgnTool::_OnModelEndDrag;
        using DgnTool::_OnMouseWheel;
        using DgnTool::_OnModifierKeyTransition;
        using DgnTool::_OnKeyTransition;
        using DgnTool::_On3DInputEvent;
        using DgnTool::_DisableEditAction;
        using DgnTool::_PerformEditAction;
        using DgnTool::_OnPreFilterButtonEvent;
        using DgnTool::_OnTouch;
        using DgnTool::_OnGestureNotify;
        using DgnTool::_OnGesture;
        using DgnTool::_OnFlick;
        using DgnTool::_OnTabletQuerySystemGestureStatus;
    };

//=======================================================================================
// Trampoline class for DgnTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnTool : DgnTool
    {
    public:
        using DgnTool::DgnTool;

        /*---------------------------------------------------------------------------------**//**
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
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_PURE_EXR(StatusInt, DgnTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnInstall, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, DgnTool, _OnPostInstall, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_PURE_EX(void, DgnTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, DgnTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, DgnTool, _OnCleanup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, DgnTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, DgnTool, _OnResetButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, DgnTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnTool, _PerformEditAction, ERROR, index); }

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
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, DgnTool, _OnTabletQuerySystemGestureStatus, 0, ev); }
    };

//=======================================================================================
// Publicist class for DgnViewTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct DgnViewToolPub : DgnViewTool
    {
    public:
        // DgnTool
        using DgnViewTool::_GetToolName;
        using DgnViewTool::_PopulateToolSettings;
        using DgnViewTool::_OnInstall;
        using DgnViewTool::_OnPostInstall;
        using DgnViewTool::_OnReinitialize;
        using DgnViewTool::_OnCleanup;
        using DgnViewTool::_DecorateScreen;
        using DgnViewTool::_OnResetButtonUp;
        using DgnViewTool::_OnDataButton;
        using DgnViewTool::_OnDataButtonUp;
        using DgnViewTool::_OnModelMotion;
        using DgnViewTool::_OnModelNoMotion;
        using DgnViewTool::_OnModelMotionStopped;
        using DgnViewTool::_OnModelStartDrag;
        using DgnViewTool::_OnModelEndDrag;
        using DgnViewTool::_OnMouseWheel;
        using DgnViewTool::_OnModifierKeyTransition;
        using DgnViewTool::_OnKeyTransition;
        using DgnViewTool::_On3DInputEvent;
        using DgnViewTool::_DisableEditAction;
        using DgnViewTool::_PerformEditAction;
        using DgnViewTool::_OnTouch;
        using DgnViewTool::_OnGestureNotify;
        using DgnViewTool::_OnGesture;
        using DgnViewTool::_OnFlick;
        using DgnViewTool::_OnTabletQuerySystemGestureStatus;

        // DgnViewTool
        using DgnViewTool::_InstallToolImplementation;
        using DgnViewTool::_ExitTool;
        using DgnViewTool::_OnResetButton;
        using DgnViewTool::_OnSelectedViewChange;
        using DgnViewTool::_OnPreFilterButtonEvent;
    };

//=======================================================================================
// Trampoline class for DgnViewTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnViewTool : DgnViewTool
    {
    public:
        using DgnViewTool::DgnViewTool;

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
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnInstall, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, DgnViewTool, _OnPostInstall, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, DgnViewTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, DgnViewTool, _OnCleanup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, DgnViewTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, DgnViewTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnViewTool, _PerformEditAction, ERROR, index); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnTouch(DgnTouchEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, DgnViewTool, _OnTabletQuerySystemGestureStatus, 0, ev); }

        /*---------------------------------------------------------------------------------**//**
        * DgnViewTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnViewTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_EX(void, DgnViewTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnViewTool, _OnResetButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnSelectedViewChange(int oldViewIndex, int newViewIndex) override
            { PYBIND11_OVERRIDE_EX(void, DgnViewTool, _OnSelectedViewChange, oldViewIndex, newViewIndex); }

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
    };

//=======================================================================================
// Publicist class for DgnPrimitiveTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct DgnPrimitiveToolPub : DgnPrimitiveTool
    {
    public:
        // DgnTool
        using DgnPrimitiveTool::_GetToolName;
        using DgnPrimitiveTool::_PopulateToolSettings;
        using DgnPrimitiveTool::_OnInstall;
        using DgnPrimitiveTool::_OnPostInstall;
        using DgnPrimitiveTool::_OnCleanup;
        using DgnPrimitiveTool::_DecorateScreen;
        using DgnPrimitiveTool::_OnResetButton;
        using DgnPrimitiveTool::_OnResetButtonUp;
        using DgnPrimitiveTool::_OnDataButton;
        using DgnPrimitiveTool::_OnDataButtonUp;
        using DgnPrimitiveTool::_OnModelMotion;
        using DgnPrimitiveTool::_OnModelNoMotion;
        using DgnPrimitiveTool::_OnModelMotionStopped;
        using DgnPrimitiveTool::_OnModelStartDrag;
        using DgnPrimitiveTool::_OnModelEndDrag;
        using DgnPrimitiveTool::_OnMouseWheel;
        using DgnPrimitiveTool::_OnModifierKeyTransition;
        using DgnPrimitiveTool::_OnKeyTransition;
        using DgnPrimitiveTool::_On3DInputEvent;
        using DgnPrimitiveTool::_DisableEditAction;
        using DgnPrimitiveTool::_PerformEditAction;
        using DgnPrimitiveTool::_OnPreFilterButtonEvent;
        using DgnPrimitiveTool::_OnTouch;
        using DgnPrimitiveTool::_OnGestureNotify;
        using DgnPrimitiveTool::_OnGesture;
        using DgnPrimitiveTool::_OnFlick;
        using DgnPrimitiveTool::_OnTabletQuerySystemGestureStatus;

        // DgnPrimitiveTool
        using DgnPrimitiveTool::_InstallToolImplementation;
        using DgnPrimitiveTool::_ExitTool;
        using DgnPrimitiveTool::_OnReinitialize;
        using DgnPrimitiveTool::_OnRestartTool;
        using DgnPrimitiveTool::_IsSingleShot;
        using DgnPrimitiveTool::_CheckSingleShot;
        using DgnPrimitiveTool::_OnUndoPreviousStep;
        using DgnPrimitiveTool::EnableUndoPreviousStep;
        using DgnPrimitiveTool::GetDynamicsStarted;
        using DgnPrimitiveTool::_BeginDynamics;
        using DgnPrimitiveTool::_EndDynamics;
        using DgnPrimitiveTool::_OnDynamicFrame;
        using DgnPrimitiveTool::_GetDrawDynamicsTxnChanges;
    };

//=======================================================================================
// Trampoline class for DgnPrimitiveTool
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDgnPrimitiveTool : DgnPrimitiveTool
    {
    public:
        using DgnPrimitiveTool::DgnPrimitiveTool;

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
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _PopulateToolSettings, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnInstall() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnInstall, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnPostInstall() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _OnPostInstall, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnCleanup() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _OnCleanup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _DecorateScreen(ViewportR vp) override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _DecorateScreen, vp); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, DgnPrimitiveTool, _OnResetButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnResetButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnResetButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButton(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, DgnPrimitiveTool, _OnDataButton, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnDataButtonUp(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnDataButtonUp, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnModelMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelNoMotion(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnModelNoMotion, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelMotionStopped(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnModelMotionStopped, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelStartDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnModelStartDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModelEndDrag(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnModelEndDrag, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnMouseWheel(DgnMouseWheelEvent const* ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnMouseWheel, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnModifierKeyTransition(bool wentDown, int key) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnModifierKeyTransition, false, wentDown, key); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnKeyTransition(bool wentDown, int key, bool shiftIsDown, bool ctrlIsDown) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnKeyTransition, false, wentDown, key, shiftIsDown, ctrlIsDown); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _On3DInputEvent(Dgn3DInputEvent const& ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _On3DInputEvent, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _DisableEditAction() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _DisableEditAction, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual StatusInt _PerformEditAction(int index) override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnPrimitiveTool, _PerformEditAction, ERROR, index); }

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
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnTouch, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGestureNotify(IndexedViewportR vp, intptr_t lParam) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnGestureNotify, false, vp, lParam); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnGesture(DgnGestureEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnGesture, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnFlick(DgnFlickEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _OnFlick, false, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual long _OnTabletQuerySystemGestureStatus(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EXR(long, DgnPrimitiveTool, _OnTabletQuerySystemGestureStatus, 0, ev); }

        /*---------------------------------------------------------------------------------**//**
        * DgnPrimitiveTool overrides.
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/        
        virtual StatusInt _InstallToolImplementation() override
            { PYBIND11_OVERRIDE_EXR(StatusInt, DgnPrimitiveTool, _InstallToolImplementation, ERROR, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _ExitTool() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _ExitTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnReinitialize() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _OnReinitialize, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnRestartTool() override
            { PYBIND11_OVERRIDE_PURE_EX(void, DgnPrimitiveTool, _OnRestartTool, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _IsSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _IsSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _CheckSingleShot() override
            { PYBIND11_OVERRIDE_EXR(bool, DgnPrimitiveTool, _CheckSingleShot, false, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoPreviousStep() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _OnUndoPreviousStep, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _BeginDynamics() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _BeginDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _EndDynamics() override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _EndDynamics, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDynamicFrame(DgnButtonEventCR ev) override
            { PYBIND11_OVERRIDE_EX(void, DgnPrimitiveTool, _OnDynamicFrame, ev); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual IDrawElementAgenda* _GetDrawDynamicsTxnChanges() override
            { PYBIND11_OVERRIDE_EXR(IDrawElementAgenda*, DgnPrimitiveTool, _GetDrawDynamicsTxnChanges, nullptr, ); }
    };
    

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnTool(py::module_& m)
    {
    //===================================================================================
    // enum KeyModifierMasks
    py::enum_< KeyModifierMasks>(m, "KeyModifierMasks", py::arithmetic())
        .value("eKEYMODIFIER_ShiftKey", KEYMODIFIER_ShiftKey)
        .value("eKEYMODIFIER_ControlKey", KEYMODIFIER_ControlKey)
        .value("eKEYMODIFIER_AltKey", KEYMODIFIER_AltKey)
        .export_values();

    //===================================================================================
    // enum CoordinateLockOverrides
    py::enum_< CoordinateLockOverrides>(m, "CoordinateLockOverrides", py::arithmetic())
        .value("eOVERRIDE_COORDINATE_LOCK_None", OVERRIDE_COORDINATE_LOCK_None)
        .value("eOVERRIDE_COORDINATE_LOCK_Axis", OVERRIDE_COORDINATE_LOCK_Axis)
        .value("eOVERRIDE_COORDINATE_LOCK_ACS", OVERRIDE_COORDINATE_LOCK_ACS)
        .value("eOVERRIDE_COORDINATE_LOCK_Grid", OVERRIDE_COORDINATE_LOCK_Grid)
        .value("eOVERRIDE_COORDINATE_LOCK_All", OVERRIDE_COORDINATE_LOCK_All)
        .export_values();

    //===================================================================================
    // struct DgnButtonEvent
    py::class_< DgnButtonEvent> c1(m, "DgnButtonEvent");

    if (true)
        {
        //===================================================================================
        // enum CoordSource
        py::enum_< DgnButtonEvent::CoordSource>(c1, "CoordSource", py::arithmetic())
            .value("eFROM_User", DgnButtonEvent::FROM_User)
            .value("eFROM_Precision", DgnButtonEvent::FROM_Precision)
            .value("eFROM_TentativePoint", DgnButtonEvent::FROM_TentativePoint)
            .value("eFROM_ElemSnap", DgnButtonEvent::FROM_ElemSnap)
            .export_values();
        }

    c1.def("IsValid", &DgnButtonEvent::IsValid);
    c1.def("Invalidate", &DgnButtonEvent::Invalidate);
    
    c1.def_property("Point", &DgnButtonEvent::GetPoint, &DgnButtonEvent::SetPoint);
    c1.def("GetPoint", &DgnButtonEvent::GetPoint, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetPoint));
    c1.def("SetPoint", &DgnButtonEvent::SetPoint, "pt"_a, DOC(Bentley, DgnPlatform, DgnButtonEvent, SetPoint));

    c1.def_property_readonly("RawPoint", &DgnButtonEvent::GetRawPoint);
    c1.def("GetRawPoint", &DgnButtonEvent::GetRawPoint, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetRawPoint));
    
    c1.def_property_readonly("ViewPoint", &DgnButtonEvent::GetViewPoint);
    c1.def("GetViewPoint", &DgnButtonEvent::GetViewPoint, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetViewPoint));
    
    c1.def_property("Viewport", &DgnButtonEvent::GetViewport, &DgnButtonEvent::SetViewport);
    c1.def("GetViewport", &DgnButtonEvent::GetViewport, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetViewport));
    c1.def("SetViewport", &DgnButtonEvent::SetViewport, "vp"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnButtonEvent, SetViewport));
    
    c1.def_property_readonly("ViewNum", &DgnButtonEvent::GetViewNum);
    c1.def("GetViewNum", &DgnButtonEvent::GetViewNum, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetViewNum));
    
    c1.def_property_readonly("CoordSource", &DgnButtonEvent::GetCoordSource);
    c1.def("GetCoordSource", &DgnButtonEvent::GetCoordSource, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetCoordSource));
    
    c1.def_property_readonly("ButtonSource", &DgnButtonEvent::GetButtonSource);
    c1.def("GetButtonSource", &DgnButtonEvent::GetButtonSource, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetButtonSource));
    
    c1.def("IsControlKey", &DgnButtonEvent::IsControlKey, DOC(Bentley, DgnPlatform, DgnButtonEvent, IsControlKey));    
    c1.def("IsShiftKey", &DgnButtonEvent::IsShiftKey, DOC(Bentley, DgnPlatform, DgnButtonEvent, IsShiftKey));    
    c1.def("IsAltKey", &DgnButtonEvent::IsAltKey, DOC(Bentley, DgnPlatform, DgnButtonEvent, IsAltKey));
    
    c1.def_property_readonly("KeyModifiers", &DgnButtonEvent::GetKeyModifiers);
    c1.def("GetKeyModifiers", &DgnButtonEvent::GetKeyModifiers, DOC(Bentley, DgnPlatform, DgnButtonEvent, GetKeyModifiers));

    //===================================================================================
    // struct DgnTouchEvent
    py::class_< DgnTouchEvent, DgnButtonEvent> c2(m, "DgnTouchEvent");

    if (true)
        {
        //===================================================================================
        // enum TouchFlags
        py::enum_< DgnTouchEvent::TouchFlags>(c2, "TouchFlags", py::arithmetic())
            .value("eTOUCHFLAGS_Move", DgnTouchEvent::TOUCHFLAGS_Move)
            .value("eTOUCHFLAGS_Down", DgnTouchEvent::TOUCHFLAGS_Down)
            .value("eTOUCHFLAGS_Up", DgnTouchEvent::TOUCHFLAGS_Up)
            .value("eTOUCHFLAGS_InRange", DgnTouchEvent::TOUCHFLAGS_InRange)
            .value("eTOUCHFLAGS_Primary", DgnTouchEvent::TOUCHFLAGS_Primary)
            .value("eTOUCHFLAGS_NoCoalesce", DgnTouchEvent::TOUCHFLAGS_NoCoalesce)
            .value("eTOUCHFLAGS_Pen", DgnTouchEvent::TOUCHFLAGS_Pen)
            .value("eTOUCHFLAGS_Palm", DgnTouchEvent::TOUCHFLAGS_Palm)
            .export_values();

        //===================================================================================
        // struct TouchInput
        py::class_< DgnTouchEvent::TouchInput> c2_1(c2, "TouchInput");

        c2_1.def("GetViewPoint", &DgnTouchEvent::TouchInput::GetViewPoint, "vp"_a);
        c2_1.def("IsUp", &DgnTouchEvent::TouchInput::IsUp);
        c2_1.def("IsDown", &DgnTouchEvent::TouchInput::IsDown);
        c2_1.def("IsMove", &DgnTouchEvent::TouchInput::IsMove);
        c2_1.def("IsPrimary", &DgnTouchEvent::TouchInput::IsPrimary);
        }

    c2.def_property_readonly("Touches", [] (DgnTouchEvent const& self)
                             {
                             py::list outVals;
                             size_t nItems = self.GetNumTouches();
                             DgnTouchEvent::TouchInput const* input = self.GetTouches();
                             if (nItems > 0 && nullptr != input)
                                 {
                                 for (size_t i = 0; i < nItems; i++)
                                     outVals.append(py::cast(input[i]));
                                 }
                             return outVals;
                             });
    c2.def("GetTouches", [] (DgnTouchEvent const& self)
           {
           py::list outVals;
           size_t nItems = self.GetNumTouches();
           DgnTouchEvent::TouchInput const* input = self.GetTouches();
           if (nItems > 0 && nullptr != input)
               {
               for (size_t i = 0; i < nItems; i++)
                   outVals.append(py::cast(input[i]));
               }
           return outVals;
           });

    //===================================================================================
    // struct DgnGestureEvent
    py::class_< DgnGestureEvent, DgnButtonEvent> c3(m, "DgnGestureEvent");

    if (true)
        {
        //===================================================================================
        // enum GestureIds
        py::enum_< DgnGestureEvent::GestureIds>(c3, "GestureIds", py::arithmetic())
            .value("eGESTUREID_Begin", DgnGestureEvent::GESTUREID_Begin)
            .value("eGESTUREID_End", DgnGestureEvent::GESTUREID_End)
            .value("eGESTUREID_Zoom", DgnGestureEvent::GESTUREID_Zoom)
            .value("eGESTUREID_Pan", DgnGestureEvent::GESTUREID_Pan)
            .value("eGESTUREID_Rotate", DgnGestureEvent::GESTUREID_Rotate)
            .value("eGESTUREID_TwoFingerTap", DgnGestureEvent::GESTUREID_TwoFingerTap)
            .value("eGESTUREID_PressAndTap", DgnGestureEvent::GESTUREID_PressAndTap)
            .value("eGESTUREID_Rollover", DgnGestureEvent::GESTUREID_Rollover)
            .export_values();

        //===================================================================================
        // struct GestureInfo
        py::class_< DgnGestureEvent::GestureInfo> c3_1(c3, "GestureInfo");

        c3_1.def("GetViewPoint", &DgnGestureEvent::GestureInfo::GetViewPoint, "vp"_a);

        c3_1.def_property_readonly("Distance", &DgnGestureEvent::GestureInfo::GetDistance);
        c3_1.def("GetDistance", &DgnGestureEvent::GestureInfo::GetDistance);
        }

    c3.def_property_readonly("Info", &DgnGestureEvent::GetInfo);
    c3.def("GetInfo", &DgnGestureEvent::GetInfo, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct DgnFlickEvent
    py::class_< DgnFlickEvent, DgnButtonEvent> c4(m, "DgnFlickEvent");

    if (true)
        {
        //===================================================================================
        // enum FlickDirection
        py::enum_< DgnFlickEvent::FlickDirection>(c4, "FlickDirection", py::arithmetic())
            .value("eFLICKDIRECTION_Right", DgnFlickEvent::FLICKDIRECTION_Right)
            .value("eFLICKDIRECTION_UpRight", DgnFlickEvent::FLICKDIRECTION_UpRight)
            .value("eFLICKDIRECTION_Up", DgnFlickEvent::FLICKDIRECTION_Up)
            .value("eFLICKDIRECTION_UpLeft", DgnFlickEvent::FLICKDIRECTION_UpLeft)
            .value("eFLICKDIRECTION_Left", DgnFlickEvent::FLICKDIRECTION_Left)
            .value("eFLICKDIRECTION_DownLeft", DgnFlickEvent::FLICKDIRECTION_DownLeft)
            .value("eFLICKDIRECTION_Down", DgnFlickEvent::FLICKDIRECTION_Down)
            .value("eFLICKDIRECTION_DownRight", DgnFlickEvent::FLICKDIRECTION_DownRight)
            .export_values();
        }

    c4.def_property_readonly("FlickDirection", &DgnFlickEvent::GetFlickDirection);
    c4.def("GetFlickDirection", &DgnFlickEvent::GetFlickDirection);

    //===================================================================================
    // struct DgnMouseWheelEvent
    py::class_< DgnMouseWheelEvent, DgnButtonEvent> c5(m, "DgnMouseWheelEvent");

    c5.def_property_readonly("WheelDelta", &DgnMouseWheelEvent::GetWheelDelta);
    c5.def("GetWheelDelta", &DgnMouseWheelEvent::GetWheelDelta, DOC(Bentley, DgnPlatform, DgnMouseWheelEvent, GetWheelDelta));

    //===================================================================================
    // struct Dgn3DInputEvent
    py::class_< Dgn3DInputEvent> c6(m, "Dgn3DInputEvent");

    c6.def_property_readonly("Time", &Dgn3DInputEvent::GetTime);
    c6.def("GetTime", &Dgn3DInputEvent::GetTime);
    
    c6.def_property_readonly("Rotation", &Dgn3DInputEvent::GetRotation);
    c6.def("GetRotation", &Dgn3DInputEvent::GetRotation, py::return_value_policy::reference_internal);
    
    c6.def_property_readonly("RotMagnitude", &Dgn3DInputEvent::GetRotMagnitude);
    c6.def("GetRotMagnitude", &Dgn3DInputEvent::GetRotMagnitude);
    
    c6.def_property_readonly("Translation", &Dgn3DInputEvent::GetTranslation);
    c6.def("GetTranslation", &Dgn3DInputEvent::GetTranslation, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct DgnTool
    py::class_< DgnTool, RefCountedPtr<DgnTool>, PyDgnTool> c7(m, "DgnTool");

    c7.def_property("ToolId", &DgnTool::GetToolId, &DgnTool::SetToolId);
    c7.def("GetToolId", &DgnTool::GetToolId, DOC(Bentley, DgnPlatform, DgnTool, GetToolId));
    c7.def("SetToolId", &DgnTool::SetToolId, "toolId"_a, DOC(Bentley, DgnPlatform, DgnTool, SetToolId));
    
    c7.def_property("ToolPrompt", &DgnTool::GetToolPrompt, &DgnTool::SetToolPrompt);
    c7.def("GetToolPrompt", &DgnTool::GetToolPrompt, DOC(Bentley, DgnPlatform, DgnTool, GetToolPrompt));
    c7.def("SetToolPrompt", &DgnTool::SetToolPrompt, "prompt"_a, DOC(Bentley, DgnPlatform, DgnTool, SetToolPrompt));

    c7.def("SetCmdName", &DgnToolPub::SetCmdName, "id"_a, "prompt"_a);
    c7.def("_GetToolName", &DgnToolPub::_GetToolName, "name"_a);
    c7.def("_PopulateToolSettings", &DgnToolPub::_PopulateToolSettings);
    c7.def("_InstallToolImplementation", &DgnToolPub::_InstallToolImplementation);
    c7.def("_OnInstall", &DgnToolPub::_OnInstall);
    c7.def("_OnPostInstall", &DgnToolPub::_OnPostInstall);
    c7.def("_ExitTool", &DgnToolPub::_ExitTool);
    c7.def("_OnReinitialize", &DgnToolPub::_OnReinitialize);
    c7.def("_OnCleanup", &DgnToolPub::_OnCleanup);
    c7.def("_DecorateScreen", &DgnToolPub::_DecorateScreen, "vp"_a);
    c7.def("_OnResetButton", &DgnToolPub::_OnResetButton, "ev"_a);
    c7.def("_OnResetButtonUp", &DgnToolPub::_OnResetButtonUp, "ev"_a);
    c7.def("_OnDataButton", &DgnToolPub::_OnDataButton, "ev"_a);
    c7.def("_OnDataButtonUp", &DgnToolPub::_OnDataButtonUp, "ev"_a);
    c7.def("_OnModelMotion", &DgnToolPub::_OnModelMotion, "ev"_a);
    c7.def("_OnModelNoMotion", &DgnToolPub::_OnModelNoMotion, "ev"_a);
    c7.def("_OnModelMotionStopped", &DgnToolPub::_OnModelMotionStopped, "ev"_a);
    c7.def("_OnModelStartDrag", &DgnToolPub::_OnModelStartDrag, "ev"_a);
    c7.def("_OnModelEndDrag", &DgnToolPub::_OnModelEndDrag, "ev"_a);
    c7.def("_OnMouseWheel", &DgnToolPub::_OnMouseWheel, "ev"_a);
    c7.def("_OnModifierKeyTransition", &DgnToolPub::_OnModifierKeyTransition, "wentDown"_a, "key"_a);
    c7.def("_OnKeyTransition", &DgnToolPub::_OnKeyTransition, "wentDown"_a, "key"_a, "shiftIsDown"_a, "ctrlIsDown"_a);
    c7.def("_On3DInputEvent", &DgnToolPub::_On3DInputEvent, "inputEvt"_a);
    c7.def("_DisableEditAction", &DgnToolPub::_DisableEditAction);
    c7.def("_PerformEditAction", &DgnToolPub::_PerformEditAction, "index"_a);
    
    c7.def("_OnPreFilterButtonEvent", [] (DgnTool& self, ViewportP vp, bool testDefault)
           {
           bool testDefault_ {testDefault};
           auto retVal = static_cast<DgnToolPub&>(self)._OnPreFilterButtonEvent(vp, testDefault_);
           return py::make_tuple(retVal, testDefault_);
           }, "vp"_a, "testDefault"_a);

    c7.def("_OnTouch", &DgnToolPub::_OnTouch, "ev"_a);
    c7.def("_OnGestureNotify", &DgnToolPub::_OnGestureNotify, "vp"_a, "lParam"_a);
    c7.def("_OnGesture", &DgnToolPub::_OnGesture, "ev"_a);
    c7.def("_OnFlick", &DgnToolPub::_OnFlick, "ev"_a);
    c7.def("_OnTabletQuerySystemGestureStatus", &DgnToolPub::_OnTabletQuerySystemGestureStatus, "ev"_a);

    c7.def(py::init<int, int>(), "toolId"_a, "toolPrompt"_a);
    c7.def("InstallTool", &DgnTool::InstallTool, DOC(Bentley, DgnPlatform, DgnTool, InstallTool));
    //c7.def_property_readonly("MdlDesc", &DgnTool::GetMdlDesc);
    c7.def("GetCurrentDgnButtonEvent", &DgnTool::GetCurrentDgnButtonEvent, "ev"_a, DOC(Bentley, DgnPlatform, DgnTool, GetCurrentDgnButtonEvent));
    c7.def("SetAdjustedDataPoint", &DgnTool::SetAdjustedDataPoint, "ev"_a, DOC(Bentley, DgnPlatform, DgnTool, SetAdjustedDataPoint));
    c7.def("ResetCurrentQualifierMask", &DgnTool::ResetCurrentQualifierMask, "mask"_a, DOC(Bentley, DgnPlatform, DgnTool, ResetCurrentQualifierMask));
    
    c7.def("GetModifierKeyTransitionState", [] (DgnTool& self)
           {
           int modifierKey = 0;
           bool modifierKeyWentDown = false;
           UInt32 currentQualifierMask = 0;
           self.GetModifierKeyTransitionState(&modifierKey, &modifierKeyWentDown, &currentQualifierMask);
           return py::make_tuple(modifierKey, modifierKeyWentDown, currentQualifierMask);
           }, DOC(Bentley, DgnPlatform, DgnTool, GetModifierKeyTransitionState));

    c7.def("SetModifierKeyTransitionState", &DgnTool::SetModifierKeyTransitionState, "modifierKey"_a, "modifierWentDown"_a, "currentQualifierMask"_a, DOC(Bentley, DgnPlatform, DgnTool, SetModifierKeyTransitionState));
    
    c7.def_property_readonly_static("ActiveViewTool", [] (py::object const&) { return RefCountedPtr<DgnTool>(DgnTool::GetActiveViewTool()); });
    c7.def_static("GetActiveViewTool", [] () { return RefCountedPtr<DgnTool>(DgnTool::GetActiveViewTool()); });

    c7.def_property_readonly_static("ActivePrimitiveTool", [] (py::object const&) { return RefCountedPtr<DgnPrimitiveTool>(DgnTool::GetActivePrimitiveTool()); });
    c7.def_static("GetActivePrimitiveTool", [] () { return RefCountedPtr<DgnPrimitiveTool>(DgnTool::GetActivePrimitiveTool()); });

    //===================================================================================
    // struct DgnViewTool
    py::class_< DgnViewTool, RefCountedPtr< DgnViewTool>, PyDgnViewTool, DgnTool> c8(m, "DgnViewTool");

    c8.def("_InstallToolImplementation", &DgnViewToolPub::_InstallToolImplementation);
    c8.def("_ExitTool", &DgnViewToolPub::_ExitTool);
    c8.def("_OnResetButton", &DgnViewToolPub::_OnResetButton, "ev"_a);
    c8.def("_OnSelectedViewChange", &DgnViewToolPub::_OnSelectedViewChange, "oldViewIndex"_a, "newViewIndex"_a);

    c8.def("_OnPreFilterButtonEvent", [] (DgnViewTool& self, ViewportP vp, bool testDefault)
           {
           bool testDefault_ {testDefault};
           auto retVal = static_cast<DgnViewToolPub&>(self)._OnPreFilterButtonEvent(vp, testDefault_);
           return py::make_tuple(retVal, testDefault_);
           }, "vp"_a, "testDefault"_a);

    c8.def(py::init<int, int>(), "toolName"_a, "toolPrompt"_a);

    if (true)
        {
        //===================================================================================
        // enum PreferredView
        py::enum_< DgnViewTool::PreferredView>(c8, "PreferredView", py::arithmetic())
            .value("ePREFERRED_VIEW_None", DgnViewTool::PREFERRED_VIEW_None)
            .value("ePREFERRED_VIEW_Unparsed", DgnViewTool::PREFERRED_VIEW_Unparsed)
            .value("ePREFERRED_VIEW_Selected", DgnViewTool::PREFERRED_VIEW_Selected)
            .value("ePREFERRED_VIEW_Single", DgnViewTool::PREFERRED_VIEW_Single)
            .export_values();
        }

    c8.def_static("GetPreferredViewport", [] (WCharCP unparsedP, DgnViewTool::PreferredView sourceToSearch)
                  {
                  DgnViewTool::PreferredView sourceFound = DgnViewTool::PreferredView::PREFERRED_VIEW_None;
                  auto retVal = DgnViewTool::GetPreferredViewport(&sourceFound, unparsedP, sourceToSearch);
                  return py::make_tuple(RefCountedPtr<IndexedViewport>(retVal), sourceFound);
                  }, "unparsed"_a, "sourceToSearch"_a, DOC(Bentley, DgnPlatform, DgnViewTool, GetPreferredViewport));

    //===================================================================================
    // struct DgnPrimitiveTool
    py::class_< DgnPrimitiveTool, RefCountedPtr< DgnPrimitiveTool>, PyDgnPrimitiveTool, DgnTool> c9(m, "DgnPrimitiveTool");

    c9.def("_InstallToolImplementation", &DgnPrimitiveToolPub::_InstallToolImplementation);
    c9.def("_ExitTool", &DgnPrimitiveToolPub::_ExitTool);
    c9.def("_OnReinitialize", &DgnPrimitiveToolPub::_OnReinitialize);
    c9.def("_OnRestartTool", &DgnPrimitiveToolPub::_OnRestartTool);
    c9.def("_IsSingleShot", &DgnPrimitiveToolPub::_IsSingleShot);
    c9.def("_CheckSingleShot", &DgnPrimitiveToolPub::_CheckSingleShot);
    c9.def("_OnUndoPreviousStep", &DgnPrimitiveToolPub::_OnUndoPreviousStep);
    c9.def("EnableUndoPreviousStep", &DgnPrimitiveToolPub::EnableUndoPreviousStep);

    c9.def_property_readonly("DynamicsStarted", &DgnPrimitiveToolPub::GetDynamicsStarted);
    c9.def("GetDynamicsStarted", &DgnPrimitiveToolPub::GetDynamicsStarted);
    
    c9.def("_BeginDynamics", &DgnPrimitiveToolPub::_BeginDynamics);
    c9.def("_EndDynamics", &DgnPrimitiveToolPub::_EndDynamics);
    c9.def("_OnDynamicFrame", &DgnPrimitiveToolPub::_OnDynamicFrame);
    c9.def("_GetDrawDynamicsTxnChanges", &DgnPrimitiveToolPub::_GetDrawDynamicsTxnChanges, py::return_value_policy::reference_internal);

    c9.def(py::init<int, int>(), "toolId"_a, "toolPrompt"_a);
    c9.def("CallOnRestartTool", &DgnPrimitiveTool::CallOnRestartTool, DOC(Bentley, DgnPlatform, DgnPrimitiveTool, CallOnRestartTool));

    }