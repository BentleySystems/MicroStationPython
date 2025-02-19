/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msstate.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <pybind11/functional.h>
#include <Mstn/MdlApi/msstate.fdf>
#include "CallbackHelper.h"


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       9/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msstate(py::module_& m)
{
    //===================================================================================
    // Class StateCallback
    py::class_<StateCallback> c1(m, "StateCallback");

    c1.def_static("SetDataPointFunction", [](std::function<std::remove_pointer_t<StateFunc_DataPoint>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_DataPoint>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(StateCallback::SetDataPointFunction, DPoint3dCP, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetResetFunction", [](std::function<std::remove_pointer_t<StateFunc_Reset>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_Reset>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(StateCallback::SetResetFunction, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetKeyinFunction", [](std::function<std::remove_pointer_t<StateFunc_Keyin>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_Keyin>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(StateCallback::SetKeyinFunction, WCharCP, int, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetComplexDynamicsFunction", [](std::function<std::remove_pointer_t<StateFunc_ComplexDynamics>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_ComplexDynamics>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(StateCallback::SetComplexDynamicsFunction, DPoint3dCP, int, DgnPlatform::DgnDrawMode, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetCommandCleanupFunction", [](std::function<std::remove_pointer_t<StateFunc_CommandCleanup>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_CommandCleanup>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(StateCallback::SetCommandCleanupFunction, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetOopsFunction", [](std::function<std::remove_pointer_t<StateFunc_Oops>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_Oops>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(StateCallback::SetOopsFunction, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetDragInitFunction", [](std::function<std::remove_pointer_t<StateFunc_DragInit>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_DragInit>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(StateCallback::SetDragInitFunction, DPoint3dCP, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetRedoFunction", [](std::function<std::remove_pointer_t<StateFunc_Redo>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<StateFunc_Redo>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(StateCallback::SetRedoFunction, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);
}