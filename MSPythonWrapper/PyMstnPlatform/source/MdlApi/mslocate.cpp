/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\mslocate.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <pybind11/functional.h>
#include <Mstn/MdlApi/mslocate.fdf>
#include "CallbackHelper.h"

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetPreLocateFunction = R"doc(@Description Set up the locate function for all elements that are in
the proximity of the test point, but **before** MicroStation applies
the Search Criteria. <p> Whenever a primitive command is started, the
locate user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling SetPreLocateFunction. <p>
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetPostLocateFunction = R"doc(@Description Set up the locate function for all elements that are in
the proximity of the test point, **after** the element has already
passed the Search Criteria. <p> Whenever a primitive command is
started, the locate user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling SetPostLocateFunction. <p>
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetAcceptFunction = R"doc(@Description Set up the locate function for when the user accepts the
highlighted element. This function is also set with the pAccept
argument to mdlState_startModifyCommand. <p> Whenever a primitive
command is started, the locate user functions are cleared. Therefore,
always call mdlState_startModifyCommand before calling
SetAcceptFunction. <p> 
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set,or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetShowFunction = R"doc(@Description Set up the locate function to show the result of a
selection. This function is also set with the pShow argument to
mdlState_startModifyCommand. <p> Whenever a primitive command is
started, the locate user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling SetShowFunction. <p>
@Param(input) newFunc The new function to call, or NULL.
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetCleanFunction = R"doc(@Description Set up the locate function to clean up the result of a
selection. This function is also set with the pClean argument to
mdlState_startModifyCommand. <p> Whenever a primitive command is
started, the locate user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling SetCleanFunction. <p>
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetNotFoundFunction = R"doc(@Description Set up the locate function that is called whenever
MicroStation attempts to Locate an element, but no acceptable elements
were found. <p> Whenever a primitive command is started, the locate
user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling SetNotFoundFunction. <p>
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetGlobalPreLocateFunction = R"doc(@Description This is the same as SetPreLocateFunction, except that
this function is remains active regardless of the active command.
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetGlobalPostLocateFunction = R"doc(@Description This is the same as SetPostLocateFunction, except that
this function is remains active regardless of the active command.
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The
return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetSelectCmdFunction = R"doc(@Description Set up the locate function that is called whenever
MicroStation attempts to Locate an element, but no acceptable elements
were found. <p> Whenever a primitive command is started, the locate
user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling SetSelectCmdFunction. <p>
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetOverridePathDescriptionFunction = R"doc(@Description Set up the locate function that is called to provide a
description of a DisplayPathCP for the user. <p> Whenever a primitive
command is started, the locate user functions are cleared. Therefore,
always call mdlState_startModifyCommand before calling
SetOverridePathDescriptionFunction. <p> 
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_LocateCallback_SetElementDoubleClickFunction = R"doc(@Description Set up the locate function to respond to double-click
events on an element. <p> Whenever a primitive command is started, the
locate user functions are cleared. Therefore, always call
mdlState_startModifyCommand before calling
SetElementDoubleClickFunction. <p> 
@Param(input) newFunc The new function to call, or NULL. 
@Param(input) funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set, or NULL.)doc";

typename OverridePathDescriptionCallbackHelper::OverridePathDescriptionFunctionType OverridePathDescriptionCallbackHelper::m_callbackFuncs[MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT];
typename OverridePathDescriptionCallbackHelper::OverridePathDescriptionCallbackPtrType OverridePathDescriptionCallbackHelper::m_callbackPtrs[MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT] = { 0 };
std::string OverridePathDescriptionCallbackHelper::m_callbackIDs[MAX_OVERRIDE_PATH_DESCRIPTION_CALLBACK_COUNT];

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_mslocate(py::module_& m)
{
    py::class_<LocateCallback> c1(m, "LocateCallback");

    c1.def_static("SetPreLocateFunction", [](std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>
        {
            ADD_FN_POINTER_CALLBACK_EIGHT_PARAMS(LocateCallback::SetPreLocateFunction, DgnPlatform::LOCATE_Action, MSElementCP, DgnModelRefP, UInt32, DPoint3dCP, int, HitPathCP, WStringR, DgnPlatform::LocateFilterStatus, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetPreLocateFunction));

    c1.def_static("SetPostLocateFunction", [](std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>
        {
            ADD_FN_POINTER_CALLBACK_EIGHT_PARAMS(LocateCallback::SetPostLocateFunction, DgnPlatform::LOCATE_Action, MSElementCP, DgnModelRefP, UInt32, DPoint3dCP, int, HitPathCP, WStringR, DgnPlatform::LocateFilterStatus, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetPostLocateFunction));

    c1.def_static("SetAcceptFunction", [](std::function<std::remove_pointer_t<MdlFunc_Accept>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<MdlFunc_Accept>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(LocateCallback::SetAcceptFunction, DPoint3dCP, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetAcceptFunction));

    c1.def_static("SetShowFunction", [](std::function<std::remove_pointer_t<MdlFunc_Show>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<MdlFunc_Show>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(LocateCallback::SetShowFunction, DPoint3dCP, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetShowFunction));

    c1.def_static("SetCleanFunction", [](std::function<std::remove_pointer_t<MdlFunc_Clean>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<MdlFunc_Clean>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(LocateCallback::SetCleanFunction, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetCleanFunction));

    c1.def_static("SetNotFoundFunction", [](std::function<std::remove_pointer_t<MdlFunc_NotFound>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<MdlFunc_NotFound>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(LocateCallback::SetNotFoundFunction, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetNotFoundFunction));

    c1.def_static("SetGlobalPreLocateFunction", [](std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>
        {
            ADD_FN_POINTER_CALLBACK_EIGHT_PARAMS(LocateCallback::SetGlobalPreLocateFunction, DgnPlatform::LOCATE_Action, MSElementCP, DgnModelRefP, UInt32, DPoint3dCP, int, HitPathCP, WStringR, DgnPlatform::LocateFilterStatus, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetGlobalPreLocateFunction));

    c1.def_static("SetGlobalPostLocateFunction", [](std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<LocateFunc_LocateFilter>>
        {
            ADD_FN_POINTER_CALLBACK_EIGHT_PARAMS(LocateCallback::SetGlobalPostLocateFunction, DgnPlatform::LOCATE_Action, MSElementCP, DgnModelRefP, UInt32, DPoint3dCP, int, HitPathCP, WStringR, DgnPlatform::LocateFilterStatus, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetGlobalPostLocateFunction));

    c1.def_static("SetSelectCmdFunction", [](std::function<std::remove_pointer_t<Select_UserFunction>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<Select_UserFunction>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(LocateCallback::SetSelectCmdFunction, DgnPlatform::SelectionSetAction*, UInt32, DgnModelRefP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetSelectCmdFunction));

    c1.def_static("SetOverridePathDescriptionFunction", [](std::function<void(DisplayPathCP, WString*)>& newFunc, const std::string& funcID) -> std::function<void(DisplayPathCP, WString*)>
        {
            OverridePathDescriptionCallbackHelper::OverridePathDescriptionCallbackPtrType oldCallback;
            if (newFunc)
            {
                OverridePathDescriptionCallbackHelper::OverridePathDescriptionCallbackPtrType callback = OverridePathDescriptionCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = LocateCallback::SetOverridePathDescriptionFunction(callback);
            }
            else
            {
                oldCallback = LocateCallback::SetOverridePathDescriptionFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return OverridePathDescriptionCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetOverridePathDescriptionFunction));

    c1.def_static("SetElementDoubleClickFunction", [](std::function<std::remove_pointer_t<LocateFunc_ElementDoubleClick>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<LocateFunc_ElementDoubleClick>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(LocateCallback::SetElementDoubleClickFunction, DisplayPathCP, bool, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, LocateCallback, SetElementDoubleClickFunction));
}
