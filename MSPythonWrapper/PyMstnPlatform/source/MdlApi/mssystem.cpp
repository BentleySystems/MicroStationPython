/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\mssystem.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <pybind11/functional.h>
#include <Mstn/MdlApi/mssystem.fdf>
#include "CallbackHelper.h"

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetUnloadProgramFunction = R"doc(@Description An MDL application can use this to set a function to be
called when the application is about to be unloaded. 
@Param[in]unloadFunction The new function to call, or NULL. 
@Param[in] funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set for this MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetMessageCenterWriteFunction = R"doc(@description Set a function that is called when a message is written
to the Message Center.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetPromptOutputFunction = R"doc(@description Set a function that is called when a prompt is output to
the Status Bar.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetStatusOutputFunction = R"doc(@description Set a function that is called when a status message is
output to the Status Bar.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetApplicationAreaChangeFunction = R"doc(@description Set a function that is called when the Application Area
has changed.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetFenceChangedFunction = R"doc(@description Set a function that is called when a fence is defined or
cleared.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetElmDscrCopyFunction = R"doc(@description Set a function that is called when an element is being
copied between models.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetAcsOperationFunction = R"doc(@description Set a function that is called when an ACS is created,
deleted, or modified.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.

Remark:
    s Applications should register a DgnPlatform::IACSEvents listener
    instead.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetLockChangedFunction = R"doc(@description Set a function that is called when the state of an active
lock changes.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetActiveParamChangedFunction = R"doc(@description Set a function that is called when the state of an active
parameter changes.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetUpdateSequenceChangedFunction = R"doc(@description Set a function that is called when the model update
sequence is defined or modified.

Parameter ``newFunc``:
    The new function to call.

Parameter ``funcID``:
    Unique ID of the callback function that user defines.

Returns:
    The return value is the previous function that was set for this
    MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetDimStyleChangeFunction = R"doc(@Description Set a function that is called each time a dimension style
is added, deleted, or updated in a file. Also called when the active
dimension style changes. 

@Param[in] newFunc The new function to call.
@Param[in] funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set for
this MdlApp, or NULL.

Remark:
    s This method is superceded by DimensionStyle::AddListener which
    provides more detailed information.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetTextStyleChangeFunction = R"doc(@Description Set a function that is called each time a text style is
added, deleted, or updated in a file. Also called when the active text
style changes. 
@Param[in] newFunc The new function to call. 
@Param[in] funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set for this
MdlApp, or NULL.

Remark:
    s This method is superceded by DgnTextStyle::AddListener which
    provides more detailed information.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetWorkspaceChangedFunction = R"doc(@Description Set a function that is called when the workspace,
project, or interface changes. 
@Param[in] newFunc The new function to call. 
@Param[in] funcID Unique ID of the callback function that user defines.
@Return The return value is the previous function that was set
for this MdlApp, or NULL.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetMainToolBoxTaskChangedFunction = R"doc(@description Allows you to be notified after the current UI "main"
task (e.g. via task navigation) has changed.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetTaskNavigationTaskChangingFunction = R"doc(@description Allows you to be notified before the current UI task is
changed. This allows you to cancel the task change, leaving the
current task active.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetActiveElementTemplateChangedFunction = R"doc(@description Allows you to be notified after the active Element
Template is changed.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetClipboardUpdatedFunction = R"doc(@description Allows you to be notified when the Clipboard has been
updated.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetDgnLibsChangedFunction = R"doc(@description Allows you to be notified when the set of DgnLibs has
changed.)doc";

static const char* __doc_Bentley_MstnPlatform_SystemCallback_SetRibbonBackstageOpenedFunction = R"doc(@description Allows you to be notified when the Ribbon's Backstage is
opened.)doc";

std::function<void(BoolWrapper*, WCharCP, WCharCP)> TaskChangingCallbackHelper::m_callbackFuncs[MAX_TASK_CHANGING_CALLBACK_COUNT];
typename TaskChangingCallbackHelper::TaskChangingCallbackPtrType TaskChangingCallbackHelper::m_callbackPtrs[MAX_TASK_CHANGING_CALLBACK_COUNT] = { 0 };
std::string TaskChangingCallbackHelper::m_callbackIDs[MAX_TASK_CHANGING_CALLBACK_COUNT];

typename CompressDgnFileCallbackHelper::CompressDgnFileFunctionType CompressDgnFileCallbackHelper::m_callbackFuncs[MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT];
typename CompressDgnFileCallbackHelper::CompressDgnFileCallbackPtrType CompressDgnFileCallbackHelper::m_callbackPtrs[MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT] = { 0 };
std::string CompressDgnFileCallbackHelper::m_callbackIDs[MAX_COMPRESS_DGN_FILE_CALLBACK_COUNT];

typename ElmDscrCopyCallbackHelper::ElmDscrCopyFunctionType ElmDscrCopyCallbackHelper::m_callbackFuncs[MAX_ELM_DSCR_COPY_CALLBACK_COUNT];
typename ElmDscrCopyCallbackHelper::ElmDscrCopyCallbackPtrType ElmDscrCopyCallbackHelper::m_callbackPtrs[MAX_ELM_DSCR_COPY_CALLBACK_COUNT] = { 0 };
std::string ElmDscrCopyCallbackHelper::m_callbackIDs[MAX_ELM_DSCR_COPY_CALLBACK_COUNT];

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       7/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_mssystem(py::module_& m)
{
    bind_TypeWrapper<int>(m, "MsPyInt");
    bind_TypeWrapper<double>(m, "MsPyDouble");
    bind_TypeWrapper<bool>(m, "MsPyBool");

    //===================================================================================
    // Enum CompressType
    py::enum_<CompressType>(m, "CompressType", py::arithmetic())
        .value("ePRE_COMPRESS_DGNFILE", CompressType::PRE_COMPRESS_DGNFILE)
        .value("ePOST_COMPRESS_DGNFILE", CompressType::POST_COMPRESS_DGNFILE)
        .export_values();

    //===================================================================================
    // Enum NewDesignFileReason
    py::enum_<NewDesignFileReason>(m, "NewDesignFileReason", py::arithmetic())
        .value("eSYSTEM_NEWFILE_CLOSE", NewDesignFileReason::SYSTEM_NEWFILE_CLOSE)
        .value("eSYSTEM_NEWFILE_COMPLETE", NewDesignFileReason::SYSTEM_NEWFILE_COMPLETE)
        .export_values();

    //===================================================================================
    // Enum UnloadProgramReason
    py::enum_<UnloadProgramReason>(m, "UnloadProgramReason", py::arithmetic())
        .value("eSYSTEM_TERMINATED_UNLOADING_APPDOMAIN", UnloadProgramReason::SYSTEM_TERMINATED_UNLOADING_APPDOMAIN)
        .value("eSYSTEM_TERMINATED_ENTERING_RESTRICTED_RIGHTS_MODE", UnloadProgramReason::SYSTEM_TERMINATED_ENTERING_RESTRICTED_RIGHTS_MODE)
        .value("eSYSTEM_TERMINATED_UNLOAD_UI_SERVERS", UnloadProgramReason::SYSTEM_TERMINATED_UNLOAD_UI_SERVERS)
        .value("eSYSTEM_TERMINATED_LIBRARY_UNLOAD", UnloadProgramReason::SYSTEM_TERMINATED_LIBRARY_UNLOAD)
        .value("eSYSTEM_TERMINATED_SHUTDOWN", UnloadProgramReason::SYSTEM_TERMINATED_SHUTDOWN)
        .value("eSYSTEM_TERMINATED_FATAL", UnloadProgramReason::SYSTEM_TERMINATED_FATAL)
        .value("eSYSTEM_TERMINATED_COMMAND", UnloadProgramReason::SYSTEM_TERMINATED_COMMAND)
        .value("eSYSTEM_TERMINATED_EXIT", UnloadProgramReason::SYSTEM_TERMINATED_EXIT)
        .value("eSYSTEM_TERMINATED_BY_APP", UnloadProgramReason::SYSTEM_TERMINATED_BY_APP)
        .value("eSYSTEM_TERMINATED_EXCEPTION", UnloadProgramReason::SYSTEM_TERMINATED_EXCEPTION)
        .export_values();

    //===================================================================================
    // Enum SystemRefAttachQueueState
    py::enum_<SystemRefAttachQueueState>(m, "SystemRefAttachQueueState", py::arithmetic())
        .value("eSYSTEM_REFATTACHQUEUE_Start", SystemRefAttachQueueState::SYSTEM_REFATTACHQUEUE_Start)
        .value("eSYSTEM_REFATTACHQUEUE_Done", SystemRefAttachQueueState::SYSTEM_REFATTACHQUEUE_Done)
        .export_values();

    //===================================================================================
    // Enum FileOutdatedCheck_Reason
    py::enum_<FileOutdatedCheck_Reason>(m, "FileOutdatedCheck_Reason", py::arithmetic())
        .value("eFILEOUTDATED_REF_QUERY", FileOutdatedCheck_Reason::FILEOUTDATED_REF_QUERY)
        .value("eFILEOUTDATED_REF_RELOAD", FileOutdatedCheck_Reason::FILEOUTDATED_REF_RELOAD)
        .value("eFILEOUTDATED_REF_FORCERELOAD", FileOutdatedCheck_Reason::FILEOUTDATED_REF_FORCERELOAD)
        .export_values();

    //===================================================================================
    // Enum LockChanged_Events
    py::enum_<LockChanged_Events>(m, "LockChanged_Events", py::arithmetic())
        .value("eLOCKCHANGED_Snap", LockChanged_Events::LOCKCHANGED_Snap)
        .value("eLOCKCHANGED_Grid", LockChanged_Events::LOCKCHANGED_Grid)
        .value("eLOCKCHANGED_Unit", LockChanged_Events::LOCKCHANGED_Unit)
        .value("eLOCKCHANGED_Angle", LockChanged_Events::LOCKCHANGED_Angle)
        .value("eLOCKCHANGED_Textnode", LockChanged_Events::LOCKCHANGED_Textnode)
        .value("eLOCKCHANGED_Axis", LockChanged_Events::LOCKCHANGED_Axis)
        .value("eLOCKCHANGED_Scale", LockChanged_Events::LOCKCHANGED_Scale)
        .value("eLOCKCHANGED_GraphicGroup", LockChanged_Events::LOCKCHANGED_GraphicGroup)
        .value("eLOCKCHANGED_Level", LockChanged_Events::LOCKCHANGED_Level)
        .value("eLOCKCHANGED_CellStretch", LockChanged_Events::LOCKCHANGED_CellStretch)
        .value("eLOCKCHANGED_ConstructionPlane", LockChanged_Events::LOCKCHANGED_ConstructionPlane)
        .value("eLOCKCHANGED_Isometric", LockChanged_Events::LOCKCHANGED_Isometric)
        .value("eLOCKCHANGED_Association", LockChanged_Events::LOCKCHANGED_Association)
        .value("eLOCKCHANGED_Depth", LockChanged_Events::LOCKCHANGED_Depth)
        .value("eLOCKCHANGED_ConstructionPlanePerp", LockChanged_Events::LOCKCHANGED_ConstructionPlanePerp)
        .value("eLOCKCHANGED_FenceMode", LockChanged_Events::LOCKCHANGED_FenceMode)
        .value("eLOCKCHANGED_IsometricPlane", LockChanged_Events::LOCKCHANGED_IsometricPlane)
        .value("eLOCKCHANGED_UseAnnotationScale", LockChanged_Events::LOCKCHANGED_UseAnnotationScale)
        .value("eLOCKCHANGED_ACSContext", LockChanged_Events::LOCKCHANGED_ACSContext)
        .value("eLOCKCHANGED_ElementTemplateAssociation", LockChanged_Events::LOCKCHANGED_ElementTemplateAssociation)
        .value("eLOCKCHANGED_SharedCells", LockChanged_Events::LOCKCHANGED_SharedCells)
        .export_values();

    //===================================================================================
    // Enum MlineStyleMsgType
    py::enum_<MlineStyleMsgType>(m, "MlineStyleMsgType", py::arithmetic())
        .value("eMLINESTYLE_PreActivate", MlineStyleMsgType::MLINESTYLE_PreActivate)
        .value("eMLINESTYLE_PostActivate", MlineStyleMsgType::MLINESTYLE_PostActivate)
        .value("eMLINESTYLE_PostAdd", MlineStyleMsgType::MLINESTYLE_PostAdd)
        .value("eMLINESTYLE_PostDelete", MlineStyleMsgType::MLINESTYLE_PostDelete)
        .value("eMLINESTYLE_PostChange", MlineStyleMsgType::MLINESTYLE_PostChange)
        .value("eMLINESTYLE_UndoDelete", MlineStyleMsgType::MLINESTYLE_UndoDelete)
        .value("eMLINESTYLE_UndoAdd", MlineStyleMsgType::MLINESTYLE_UndoAdd)
        .value("eMLINESTYLE_UndoModify", MlineStyleMsgType::MLINESTYLE_UndoModify)
        .value("eMLINESTYLE_RedoDelete", MlineStyleMsgType::MLINESTYLE_RedoDelete)
        .value("eMLINESTYLE_RedoAdd", MlineStyleMsgType::MLINESTYLE_RedoAdd)
        .value("eMLINESTYLE_RedoModify", MlineStyleMsgType::MLINESTYLE_RedoModify)
        .value("eMLINESTYLE_PreActivateByName", MlineStyleMsgType::MLINESTYLE_PreActivateByName)
        .export_values();

    //===================================================================================
    // Enum BatchProcessing_States
    py::enum_<BatchProcessing_States>(m, "BatchProcessing_States", py::arithmetic())
        .value("ePROCESSSTATE_Inactive", BatchProcessing_States::PROCESSSTATE_Inactive)
        .value("ePROCESSSTATE_Processing", BatchProcessing_States::PROCESSSTATE_Processing)
        .value("ePROCESSSTATE_Paused", BatchProcessing_States::PROCESSSTATE_Paused)
        .value("ePROCESSSTATE_Done", BatchProcessing_States::PROCESSSTATE_Done)
        .value("ePROCESSSTATE_Cancelled", BatchProcessing_States::PROCESSSTATE_Cancelled)
        .value("ePROCESSSTATE_OpeningFile", BatchProcessing_States::PROCESSSTATE_OpeningFile)
        .value("ePROCESSSTATE_AnalyzeFile", BatchProcessing_States::PROCESSSTATE_AnalyzeFile)
        .value("ePROCESSSTATE_ClosedFile", BatchProcessing_States::PROCESSSTATE_ClosedFile)
        .export_values();

    py::class_<SystemCallback> c1(m, "SystemCallback");

    c1.def_static("SetUnloadProgramFunction", [](std::function<std::remove_pointer_t<SystemFunc_UnloadProgram>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_UnloadProgram>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetUnloadProgramFunction, UnloadProgramReason, bool, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetUnloadProgramFunction));

    c1.def_static("SetNewDesignFileFunction", [](std::function<std::remove_pointer_t<SystemFunc_NewDesignFile>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_NewDesignFile>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetNewDesignFileFunction, WCharCP, NewDesignFileReason, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetCompressDgnFileFunction", [](std::function<StatusInt(WString*, CompressType)>& newFunc, const std::string& funcID) -> std::function<StatusInt(WString*, CompressType)>
        {
            CompressDgnFileCallbackHelper::CompressDgnFileCallbackPtrType oldCallback;
            if (newFunc)
            {
                CompressDgnFileCallbackHelper::CompressDgnFileCallbackPtrType callback = CompressDgnFileCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = SystemCallback::SetCompressDgnFileFunction(callback);
            }
            else
            {
                oldCallback = SystemCallback::SetCompressDgnFileFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return CompressDgnFileCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetCompressDgnModelFunction", [](std::function<std::remove_pointer_t<SystemFunc_CompressDgnModel>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_CompressDgnModel>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetCompressDgnModelFunction, DgnModelP, CompressType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetDgnFileLoadedFunction", [](std::function<std::remove_pointer_t<SystemFunc_DgnFileLoaded>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_DgnFileLoaded>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetDgnFileLoadedFunction, DgnFileP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetDgnFileUnloadingFunction", [](std::function<std::remove_pointer_t<SystemFunc_DgnFileUnloading>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_DgnFileUnloading>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetDgnFileUnloadingFunction, DgnFileP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetQueryHasPendingFunction", [](std::function<std::remove_pointer_t<SystemFunc_QueryHasPending>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_QueryHasPending>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetQueryHasPendingFunction, DgnFileP, bool, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetDgnCacheUnloadingFunction", [](std::function<std::remove_pointer_t<SystemFunc_DgnCacheUnloading>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_DgnCacheUnloading>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetDgnCacheUnloadingFunction, DgnModelP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetMasterfileClosedFunction", [](std::function<std::remove_pointer_t<SystemFunc_MasterfileClosed>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_MasterfileClosed>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetMasterfileClosedFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetModelChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_ModelChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ModelChange>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetModelChangeFunction, DgnModelRefP, ModelChangeType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetModelRefDestroyFunction", [](std::function<std::remove_pointer_t<SystemFunc_ModelRefDestroy>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ModelRefDestroy>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetModelRefDestroyFunction, DgnModelRefP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetExitDesignFileStateFunction", [](std::function<std::remove_pointer_t<SystemFunc_ExitDesignFileState>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ExitDesignFileState>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetExitDesignFileStateFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetFileSaveAsFunction", [](std::function<std::remove_pointer_t<SystemFunc_FileSaveAs>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_FileSaveAs>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetFileSaveAsFunction, bool, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetFileSaveFunction", [](std::function<std::remove_pointer_t<SystemFunc_FileSave>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_FileSave>>
        {
            ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(SystemCallback::SetFileSaveFunction, DgnPlatform::ProcessChangesWhen, DgnPlatform::DgnFileChanges, DgnPlatform::DgnSaveReason, double, DgnFileP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

        c1.def_static("SetMessageCenterWriteFunction", [](std::function<std::remove_pointer_t<SystemFunc_MessageCenterWrite>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_MessageCenterWrite>>
        {
            ADD_FN_POINTER_CALLBACK_FOUR_PARAMS(SystemCallback::SetMessageCenterWriteFunction, DgnPlatform::OutputMessagePriority, WCharCP, WCharCP, long, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetMessageCenterWriteFunction));

    c1.def_static("SetPromptOutputFunction", [](std::function<std::remove_pointer_t<SystemFunc_PromptOutput>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_PromptOutput>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetPromptOutputFunction, WCharCP, WCharCP, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetPromptOutputFunction));

    c1.def_static("SetStatusOutputFunction", [](std::function<void(WCharP, int)>& newFunc, const std::string& funcID) -> std::function<void(WCharP, int)>
        {
            if (newFunc)
            {
                void(*callback)(WCharP, int) = CallbackHelperTwoParams<WCharP, int, void>::SetCallback(newFunc, funcID);
                return SystemCallback::SetStatusOutputFunction((SystemFunc_StatusOutput)callback);
            }
            else
            {
                return SystemCallback::SetStatusOutputFunction(nullptr);
            }
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetStatusOutputFunction));

    c1.def_static("SetApplicationAreaChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_ApplicationAreaChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ApplicationAreaChange>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetApplicationAreaChangeFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetApplicationAreaChangeFunction));

        c1.def_static("SetFenceChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_FenceChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_FenceChanged>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetFenceChangedFunction, FenceChangedType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetFenceChangedFunction));

    c1.def_static("SetReferenceBeforeAttachFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceBeforeAttach>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceBeforeAttach>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetReferenceBeforeAttachFunction, WCharCP, DgnModelRefP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceAttachFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceAttach>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceAttach>>
        {
            ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(SystemCallback::SetReferenceAttachFunction, WCharP, WCharCP, DgnModelRefP, WCharCP, DgnPlatform::ElementId, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceAttachedFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceAttached>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceAttached>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetReferenceAttachedFunction, DgnModelRefP, DgnPlatform::DgnAttachmentAttachedReason, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceAttachQueueFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceAttachQueue>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceAttachQueue>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetReferenceAttachQueueFunction, SystemRefAttachQueueState, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceDetachFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceDetach>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceDetach>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetReferenceDetachFunction, DgnModelRefP, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceDetachedFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceDetached>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceDetached>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetReferenceDetachedFunction, DgnModelRefP, WCharCP, DgnPlatform::DgnAttachmentDetachedReason, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceModifiedFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceModified>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceModified>>
        {
            ADD_FN_POINTER_CALLBACK_FIVE_PARAMS(SystemCallback::SetReferenceModifiedFunction, DgnAttachmentCP, DgnAttachmentCP, DgnModelRefP, bool, bool, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetReferenceNestingFunction", [](std::function<std::remove_pointer_t<SystemFunc_ReferenceNesting>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ReferenceNesting>>
        {
            ADD_FN_POINTER_CALLBACK_SIX_PARAMS(SystemCallback::SetReferenceNestingFunction, DgnModelRefP, DgnPlatform::RefAttachNestMode, int, DgnPlatform::RefAttachNestMode, int, bool, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetFileOutdatedFunction", [](std::function<std::remove_pointer_t<SystemFunc_FileOutdated>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_FileOutdated>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetFileOutdatedFunction, DgnFileP, DgnModelRefP, FileOutdatedCheck_Reason, bool, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetBeforeReferenceWriteFunction", [](std::function<std::remove_pointer_t<SystemFunc_BeforeReferenceWrite>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_BeforeReferenceWrite>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetBeforeReferenceWriteFunction, DgnModelRefP, bool, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetElmDscrCopyFunction", [](std::function<void(EditElementHandle*, DgnModelRefP, DgnModelRefP, bool)>& newFunc, const std::string& funcID) -> std::function<void(EditElementHandle*, DgnModelRefP, DgnModelRefP, bool)>
        {
            ElmDscrCopyCallbackHelper::ElmDscrCopyCallbackPtrType oldCallback;
            if (newFunc)
            {
                ElmDscrCopyCallbackHelper::ElmDscrCopyCallbackPtrType callback = ElmDscrCopyCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = SystemCallback::SetElmDscrCopyFunction(callback);
            }
            else
            {
                oldCallback = SystemCallback::SetElmDscrCopyFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return ElmDscrCopyCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetElmDscrCopyFunction));

    c1.def_static("SetSaveSettingsFunction", [](std::function<std::remove_pointer_t<SystemFunc_SaveSettings>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_SaveSettings>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetSaveSettingsFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetAcsOperationFunction", [](std::function<std::remove_pointer_t<SystemFunc_AcsOperation>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_AcsOperation>>
        {
            ADD_FN_POINTER_CALLBACK_SIX_PARAMS(SystemCallback::SetAcsOperationFunction, WCharCP, WCharCP, DgnPlatform::ACSType, AcsChangeType, IAuxCoordSysP, DgnPlatform::ACSEventType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetAcsOperationFunction));

    c1.def_static("SetSelectedViewChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_SelectedViewChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_SelectedViewChanged>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetSelectedViewChangedFunction, int, int, bool, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetBeforeViewsOpenFunction", [](std::function<std::remove_pointer_t<SystemFunc_BeforeViewsOpen>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_BeforeViewsOpen>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetBeforeViewsOpenFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetViewGroupCacheChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_ViewGroupCacheChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ViewGroupCacheChange>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetViewGroupCacheChangeFunction, WCharCP, WCharCP, ViewGroupChangeType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetMonitorViewCommandsFunction", [](std::function<std::remove_pointer_t<SystemFunc_MonitorViewCommands>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_MonitorViewCommands>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetMonitorViewCommandsFunction, bool, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetLockChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_LockChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_LockChanged>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetLockChangedFunction, LockChanged_Events, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetLockChangedFunction));

    c1.def_static("SetActiveParamChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_ActiveParamChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ActiveParamChanged>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetActiveParamChangedFunction, UInt32, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetActiveParamChangedFunction));

    c1.def_static("SetUpdateSequenceChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_UpdateSequenceChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_UpdateSequenceChanged>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetUpdateSequenceChangedFunction, DgnModelRefP, UpdateSequenceListP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetUpdateSequenceChangedFunction));

    c1.def_static("SetDimStyleChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_DimStyleChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_DimStyleChange>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetDimStyleChangeFunction, DgnModelRefP, DgnPlatform::ElementId, DimensionStyleChangeType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetDimStyleChangeFunction));

    c1.def_static("SetTextStyleChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_TextStyleChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_TextStyleChange>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetTextStyleChangeFunction, DgnModelRefP, UInt32, TextStyleChangeType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetTextStyleChangeFunction));

    c1.def_static("SetLevelChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_LevelChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_LevelChange>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetLevelChangeFunction, DgnModelRefP, UInt32, LevelChangeType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetLevelPreChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_LevelPreChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_LevelPreChange>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetLevelPreChangeFunction, DgnModelRefP, UInt32, LevelChangeType, StatusInt, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetLevelMaskCachePreChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_LevelMaskCacheChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_LevelMaskCacheChange>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetLevelMaskCachePreChangeFunction, DgnModelRefP, UInt32, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetLevelMaskCachePostChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_LevelMaskCacheChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_LevelMaskCacheChange>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetLevelMaskCachePostChangeFunction, DgnModelRefP, UInt32, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetFilterChangeFunction", [](std::function<std::remove_pointer_t<SystemFunc_FilterChange>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_FilterChange>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetFilterChangeFunction, WCharCP, UInt32, FilterChangeType, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetMonitorBatchProcessingFunction", [](std::function<std::remove_pointer_t<SystemFunc_MonitorBatchProcessing>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_MonitorBatchProcessing>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetMonitorBatchProcessingFunction, BatchProcessing_States, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetUpgradeV7ToV8Function", [](std::function<std::remove_pointer_t<SystemFunc_UpgradeV7ToV8>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_UpgradeV7ToV8>>
        {
            ADD_FN_POINTER_CALLBACK_THREE_PARAMS(SystemCallback::SetUpgradeV7ToV8Function, DgnFileP, bool, bool, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c1.def_static("SetWorkspaceChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_WorkspaceChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_WorkspaceChanged>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetWorkspaceChangedFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetWorkspaceChangedFunction));

    c1.def_static("SetMainToolBoxTaskChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_MainToolBoxTaskChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_MainToolBoxTaskChanged>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetMainToolBoxTaskChangedFunction, WCharCP, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetMainToolBoxTaskChangedFunction));

    c1.def_static("SetTaskNavigationTaskChangingFunction", [](std::function<void(BoolWrapper*, WCharCP, WCharCP)>& newFunc, const std::string& funcID) -> std::function<void(BoolWrapper*, WCharCP, WCharCP)>
        {
            static TaskChangingCallbackHelper::TaskChangingCallbackPtrType oldCallback;
            if (newFunc)
            {
                TaskChangingCallbackHelper::TaskChangingCallbackPtrType callback = TaskChangingCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = SystemCallback::SetTaskNavigationTaskChangingFunction(callback);
            }
            else
            {
                oldCallback = SystemCallback::SetTaskNavigationTaskChangingFunction(nullptr);
            }
            if (oldCallback)
            {
                return [](BoolWrapper* cancelTaskChange, WCharCP currentPath, WCharCP newPath)
                {
                    (*oldCallback)((bool*)cancelTaskChange, currentPath, newPath);
                };
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetTaskNavigationTaskChangingFunction));

    c1.def_static("SetActiveElementTemplateChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_ActiveElementTemplateChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ActiveElementTemplateChanged>>
        {
            ADD_FN_POINTER_CALLBACK_TWO_PARAMS(SystemCallback::SetActiveElementTemplateChangedFunction, WCharCP, WCharCP, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetActiveElementTemplateChangedFunction));

    c1.def_static("SetClipboardUpdatedFunction", [](std::function<std::remove_pointer_t<SystemFunc_ClipboardUpdated>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_ClipboardUpdated>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetClipboardUpdatedFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetClipboardUpdatedFunction));

    c1.def_static("SetDgnLibsChangedFunction", [](std::function<std::remove_pointer_t<SystemFunc_DgnLibsChanged>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_DgnLibsChanged>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(SystemCallback::SetDgnLibsChangedFunction, MstnPlatform::DgnLibSelector, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetDgnLibsChangedFunction));

    c1.def_static("SetRibbonBackstageOpenedFunction", [](std::function<std::remove_pointer_t<SystemFunc_RibbonBackstageOpened>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<SystemFunc_RibbonBackstageOpened>>
        {
            ADD_FN_POINTER_CALLBACK_NO_PARAM(SystemCallback::SetRibbonBackstageOpenedFunction, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a, DOC(Bentley, MstnPlatform, SystemCallback, SetRibbonBackstageOpenedFunction));

    // These below callbacks have parameter types not easy to bind or not published, so not bind them for now,
    // if in future we get feedback from user any callback is needed, we can then investigate more and bind them,
    // but it seems these callbacks are not common and it will not be an issue we don't bind them.
    // SetMenuBarChangeFunction
    // SetWindowCloseFunction
    // SetCmdWindowOpenFunction
    // SetWindowsKeystrokeMessageFunction
    // SetDialogFindFunction
    // SetElmDscrToFileFunction
    // SetColorMapChangeFunction
    // SetCreateLibraryCellFunction
    // SetMultilineStyleChangedFunction
    // SetSymbologyChangedFunction
    // SetMonitorBatchConvertFunction
    // SetTaskNavigationTaskChangedFunction
    // SystemFunc_ReloadProgram
    // SetMdlChildTerminatedFunction
    // SetAllMdlUnloadsFunction
    // SetDgnCacheFilledFunction
    // SetDgnCacheFillFunction
    // SetCellLibraryChangeFunction
}