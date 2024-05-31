/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\notificationmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/NotificationManager.h>



static const char * __doc_Bentley_DgnPlatform_NotificationManager_SetDispatchEvents =R"doc(Set a flag to dispatch events to update the host Message Center during
a long-running process.

Parameter ``value``:
    Indicates whether to dispatch events during a long-running
    process.)doc";

static const char * __doc_Bentley_DgnPlatform_NotificationManager_OpenMessageBox =R"doc(Output a MessageBox and wait for response from the user.

Parameter ``mbType``:
    The MessageBox type.

Parameter ``message``:
    The message to display.

Parameter ``icon``:
    The MessageBox icon type.

Returns:
    the response from the user.)doc";

static const char * __doc_Bentley_DgnPlatform_NotificationManager_OutputMessage =R"doc(Output a message and/or alert to the user.

Parameter ``message``:
    The message details.

Returns:
    SUCCESS if the message was displayed, ERROR if an invalid priority
    is specified.)doc";

static const char * __doc_Bentley_DgnPlatform_NotificationManager_OutputPrompt =R"doc(Output a prompt to the user. A 'prompt' is intended to indicate an
action the user should take to proceed.

Parameter ``prompt``:
    The prompt string.)doc";

static const char * __doc_Bentley_DgnPlatform_NotifyMessageDetails_GetDetailedMsg =R"doc(Get the detailed message for this NotifyMessageDetails.)doc";

static const char * __doc_Bentley_DgnPlatform_NotifyMessageDetails_GetBriefMsg =R"doc(Get the brief message for this NotifyMessageDetails.)doc";

static const char * __doc_Bentley_DgnPlatform_NotifyMessageDetails_GetMsgAttributes =R"doc(Get the MsgAttributes value of this NotifyMessageDetails.)doc";

static const char * __doc_Bentley_DgnPlatform_NotifyMessageDetails_GetOpenAlert =R"doc(Get the OpenAlert value of this NotifyMessageDetails)doc";

static const char * __doc_Bentley_DgnPlatform_NotifyMessageDetails_GetPriority =R"doc(Get the priority value of this NotifyMessageDetails.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_NotificationManager(py::module_& m)
    {
    //===================================================================================
    // struct NotifyMessageDetails
    py::class_< NotifyMessageDetails> c1(m, "NotifyMessageDetails");

    c1.def(py::init<OutputMessagePriority, WCharCP, WCharCP, long, OutputMessageAlert>(),
           "priority"_a,
           "briefMsg"_a,
           "detailedMsg"_a = nullptr,
           "msgAttr"_a = 0,
           "openAlert"_a = OutputMessageAlert::None);

    c1.def_property_readonly("Priority", &NotifyMessageDetails::GetPriority);
    c1.def("GetPriority", &NotifyMessageDetails::GetPriority, DOC(Bentley, DgnPlatform, NotifyMessageDetails, GetPriority));
    
    c1.def_property_readonly("OpenAlert", &NotifyMessageDetails::GetOpenAlert);
    c1.def("GetOpenAlert", &NotifyMessageDetails::GetOpenAlert, DOC(Bentley, DgnPlatform, NotifyMessageDetails, GetOpenAlert));
    
    c1.def_property_readonly("MsgAttributes", &NotifyMessageDetails::GetMsgAttributes);
    c1.def("GetMsgAttributes", &NotifyMessageDetails::GetMsgAttributes, DOC(Bentley, DgnPlatform, NotifyMessageDetails, GetMsgAttributes));
    
    c1.def_property_readonly("BriefMsg", &NotifyMessageDetails::GetBriefMsg);
    c1.def("GetBriefMsg", &NotifyMessageDetails::GetBriefMsg, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NotifyMessageDetails, GetBriefMsg));
    
    c1.def_property_readonly("DetailedMsg", &NotifyMessageDetails::GetDetailedMsg);
    c1.def("GetDetailedMsg", &NotifyMessageDetails::GetDetailedMsg, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, NotifyMessageDetails, GetDetailedMsg));

    //===================================================================================
    // struct NotificationManager
    py::class_< NotificationManager> c2(m, "NotificationManager");

    if (true)
        {
        //===================================================================================
        // enum MessageBoxType
        py::enum_< NotificationManager::MessageBoxType>(c2, "MessageBoxType", py::arithmetic())
            .value("eMESSAGEBOX_TYPE_OkCancel", NotificationManager::MESSAGEBOX_TYPE_OkCancel)
            .value("eMESSAGEBOX_TYPE_Ok", NotificationManager::MESSAGEBOX_TYPE_Ok)
            .value("eMESSAGEBOX_TYPE_LargeOk", NotificationManager::MESSAGEBOX_TYPE_LargeOk)
            .value("eMESSAGEBOX_TYPE_MediumAlert", NotificationManager::MESSAGEBOX_TYPE_MediumAlert)
            .value("eMESSAGEBOX_TYPE_YesNoCancel", NotificationManager::MESSAGEBOX_TYPE_YesNoCancel)
            .value("eMESSAGEBOX_TYPE_YesNo", NotificationManager::MESSAGEBOX_TYPE_YesNo)
            .export_values();

        //===================================================================================
        // enum MessageBoxIconType
        py::enum_< NotificationManager::MessageBoxIconType>(c2, "MessageBoxIconType", py::arithmetic())
            .value("eMESSAGEBOX_ICON_NoSymbol", NotificationManager::MESSAGEBOX_ICON_NoSymbol)
            .value("eMESSAGEBOX_ICON_Information", NotificationManager::MESSAGEBOX_ICON_Information)
            .value("eMESSAGEBOX_ICON_Question", NotificationManager::MESSAGEBOX_ICON_Question)
            .value("eMESSAGEBOX_ICON_Warning", NotificationManager::MESSAGEBOX_ICON_Warning)
            .value("eMESSAGEBOX_ICON_Critical", NotificationManager::MESSAGEBOX_ICON_Critical)
            .export_values();

        //===================================================================================
        // enum MessageBoxValue
        py::enum_< NotificationManager::MessageBoxValue>(c2, "MessageBoxValue", py::arithmetic())
            .value("eMESSAGEBOX_VALUE_Apply", NotificationManager::MESSAGEBOX_VALUE_Apply)
            .value("eMESSAGEBOX_VALUE_Reset", NotificationManager::MESSAGEBOX_VALUE_Reset)
            .value("eMESSAGEBOX_VALUE_Ok", NotificationManager::MESSAGEBOX_VALUE_Ok)
            .value("eMESSAGEBOX_VALUE_Cancel", NotificationManager::MESSAGEBOX_VALUE_Cancel)
            .value("eMESSAGEBOX_VALUE_Default", NotificationManager::MESSAGEBOX_VALUE_Default)
            .value("eMESSAGEBOX_VALUE_Yes", NotificationManager::MESSAGEBOX_VALUE_Yes)
            .value("eMESSAGEBOX_VALUE_No", NotificationManager::MESSAGEBOX_VALUE_No)
            .value("eMESSAGEBOX_VALUE_Retry", NotificationManager::MESSAGEBOX_VALUE_Retry)
            .value("eMESSAGEBOX_VALUE_Stop", NotificationManager::MESSAGEBOX_VALUE_Stop)
            .value("eMESSAGEBOX_VALUE_Help", NotificationManager::MESSAGEBOX_VALUE_Help)
            .value("eMESSAGEBOX_VALUE_YesToAll", NotificationManager::MESSAGEBOX_VALUE_YesToAll)
            .value("eMESSAGEBOX_VALUE_NoToAll", NotificationManager::MESSAGEBOX_VALUE_NoToAll)
            .export_values();
        }

    c2.def_static("OutputPrompt", &NotificationManager::OutputPrompt, "prompt"_a, DOC(Bentley, DgnPlatform, NotificationManager, OutputPrompt));
    c2.def_static("OutputMessage", &NotificationManager::OutputMessage, "message"_a, DOC(Bentley, DgnPlatform, NotificationManager, OutputMessage));
    c2.def_static("OpenMessageBox", &NotificationManager::OpenMessageBox, "mtype"_a, "message"_a, "icon"_a, DOC(Bentley, DgnPlatform, NotificationManager, OpenMessageBox));
    c2.def_static("SetDispatchEvents", &NotificationManager::SetDispatchEvents, "value"_a, DOC(Bentley, DgnPlatform, NotificationManager, SetDispatchEvents));
    }