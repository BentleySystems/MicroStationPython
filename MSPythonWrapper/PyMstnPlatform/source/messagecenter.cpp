/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\messagecenter.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msoutput.fdf>

//=======================================================================================
// Concrete implementation that provide functions similar to Bentley.MstnPlatform.MessageCenter.
// @bsiclass                                                                   02/23
//=======================================================================================
class MessageCenter
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void setStatusCommand(WCharCP value) { mdlOutput_commandU(value); }
        
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void setStatusPrompt(WCharCP value)  { mdlOutput_promptU(value); }
        
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void setStatusMessage(WCharCP value) { mdlOutput_statusU(value); }
        
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void setStatusWarning(WCharCP value) { mdlOutput_errorU(value); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void ShowErrorMessage(WCharCP briefMsg, WCharCP detailedMsg, bool openAlertBox)
            {
            mdlOutput_messageCenter(OutputMessagePriority::Error, briefMsg, detailedMsg, openAlertBox ? OutputMessageAlert::Dialog : OutputMessageAlert::None);
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void ShowInfoMessage(WCharCP briefMsg, WCharCP detailedMsg, bool openAlertBox)
            {
            mdlOutput_messageCenter(OutputMessagePriority::Info, briefMsg, detailedMsg, openAlertBox ? OutputMessageAlert::Dialog : OutputMessageAlert::None);
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        static void ShowDebugMessage(WCharCP briefMsg, WCharCP detailedMsg, bool openAlertBox)
            {
            mdlOutput_messageCenter(OutputMessagePriority::Debug, briefMsg, detailedMsg, openAlertBox ? OutputMessageAlert::Dialog : OutputMessageAlert::None);
            }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MessageCenter(py::module_& m)
    {
    py::class_<MessageCenter> c1(m, "MessageCenter");

    c1.def_property_static("StatusCommand",
                           nullptr, 
                           [] (py::object const&, WCharCP value) { MessageCenter::setStatusCommand(value); });

    c1.def_property_static("StatusPrompt",
                           nullptr,
                           [] (py::object const&, WCharCP value) { MessageCenter::setStatusPrompt(value); });

    c1.def_property_static("StatusMessage",
                           nullptr,
                           [] (py::object const&, WCharCP value) { MessageCenter::setStatusMessage(value); });

    c1.def_property_static("StatusWarning",
                           nullptr,
                           [] (py::object const&, WCharCP value) { MessageCenter::setStatusWarning(value); });

    c1.def_static("ShowErrorMessage", &MessageCenter::ShowErrorMessage, "briefMessage"_a, "detailedMessage"_a, "openAlertBox"_a);
    c1.def_static("ShowInfoMessage", &MessageCenter::ShowInfoMessage, "briefMessage"_a, "detailedMessage"_a, "openAlertBox"_a);
    c1.def_static("ShowDebugMessage", &MessageCenter::ShowDebugMessage, "briefMessage"_a, "detailedMessage"_a, "openAlertBox"_a);
    }