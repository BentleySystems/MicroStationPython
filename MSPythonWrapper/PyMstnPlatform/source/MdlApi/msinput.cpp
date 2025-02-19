/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msinput.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/IEditAction.h>
#include <Mstn/MdlApi/msinput.fdf>
extern "C" __declspec(dllimport) void mdlDialog_AttachTkinterToolSetting(int hTkWin);
extern "C" __declspec(dllimport) void mdlDialog_AttachQtToolSetting(int hQtWin);
#include <Mstn/PythonMacro/PyCadInputQueue.h>
#include "CallbackHelper.h"


class PreprocessKeyinCallbackHelper {
public:
    typedef InputFilterReturnValue(*PreprocessKeyinCallbackPtrType)(WCharP);
    typedef std::function<InputFilterReturnValue(WString*)> PreprocessKeyinFunctionType;

#define DEFINE_FN_POINTER_PRE_PROCESS_KEY_IN_CALLBACK(index) \
    case index: \
        m_callbackFuncs[index] = fn; \
        m_callbackIDs[index] = fnID; \
        m_callbackPtrs[index] = [](WCharP keyinP) \
        { \
            try \
            { \
                WString keyin(keyinP); \
                InputFilterReturnValue returnVal = m_callbackFuncs[index](&keyin); \
                wcscpy(keyinP, keyin.GetWCharCP()); \
                return returnVal; \
            } \
            catch (std::exception& ex) \
            { \
                Bentley::MstnPlatform::MSPython::ScriptEngineManager::Get().InjectException(ex); \
                throw ex; \
            } \
        }; \
        return m_callbackPtrs[index];

    static PreprocessKeyinCallbackPtrType SetCallback(PreprocessKeyinFunctionType& fn, const std::string& fnID)
    {
        int index = GetCallbackIndex(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, fn, fnID, MAX_CALLBACK_COUNT_20);
        if (nullptr != m_callbackPtrs[index])
        {
            return m_callbackPtrs[index];
        }
        DEFINE_FN_POINTER_CALLBACKS_20(DEFINE_FN_POINTER_PRE_PROCESS_KEY_IN_CALLBACK);
    }

    static PreprocessKeyinFunctionType GetOldCallbackFunction(PreprocessKeyinCallbackPtrType oldCallbackPtr)
    {
        return GetOldCallbackFunctionTmplate(m_callbackPtrs, m_callbackFuncs, m_callbackIDs, oldCallbackPtr, MAX_CALLBACK_COUNT_20);
    }

private:
    static PreprocessKeyinFunctionType m_callbackFuncs[MAX_CALLBACK_COUNT_20];
    static PreprocessKeyinCallbackPtrType m_callbackPtrs[MAX_CALLBACK_COUNT_20];
    static std::string m_callbackIDs[MAX_CALLBACK_COUNT_20];
};
typename PreprocessKeyinCallbackHelper::PreprocessKeyinFunctionType PreprocessKeyinCallbackHelper::m_callbackFuncs[MAX_CALLBACK_COUNT_20];
typename PreprocessKeyinCallbackHelper::PreprocessKeyinCallbackPtrType PreprocessKeyinCallbackHelper::m_callbackPtrs[MAX_CALLBACK_COUNT_20] = { 0 };
std::string PreprocessKeyinCallbackHelper::m_callbackIDs[MAX_CALLBACK_COUNT_20];


USING_NAMESPACE_BENTLEY_MSTNPLATFORM
/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      3/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msinput(py::module_& m)
    {
    py::enum_<MSInputQueuePos> (m, "MSInputQueuePos")
        .value("eINPUTQ_HEAD", MSInputQueuePos::INPUTQ_HEAD)
        .value("eINPUTQ_EOQ", MSInputQueuePos::INPUTQ_EOQ)
        .export_values();

    py::enum_<InputQueueSourceEnum>(m, "InputQueueSourceEnum")
        .value("eFROM_KEYBOARD", InputQueueSourceEnum::FROM_KEYBOARD)
        .value("eFROM_CMDFILE", InputQueueSourceEnum::FROM_CMDFILE)
        .value("eFROM_APP", InputQueueSourceEnum::FROM_APP)
        .value("eFROM_UCM", InputQueueSourceEnum::FROM_UCM)
        .value("eTABLET_MENU", InputQueueSourceEnum::TABLET_MENU)
        .value("eSCREEN_MENU", InputQueueSourceEnum::SCREEN_MENU)
        .value("eFUNCKEY_MENU", InputQueueSourceEnum::FUNCKEY_MENU)
        .value("eCURSOR_BUTTON_MENU", InputQueueSourceEnum::CURSOR_BUTTON_MENU)
        .value("ePULLDOWN_MENU", InputQueueSourceEnum::PULLDOWN_MENU)
        .value("eCONTROL_STRIP_MENU", InputQueueSourceEnum::CONTROL_STRIP_MENU)
        .value("eHIERARCHICAL_MENU", InputQueueSourceEnum::HIERARCHICAL_MENU)
        .value("eWINDOW_ICON", InputQueueSourceEnum::WINDOW_ICON)
        .value("ePALETTE_MENU", InputQueueSourceEnum::PALETTE_MENU)
        .value("eFROM_STARTUP", InputQueueSourceEnum::FROM_STARTUP)
        .value("eFROM_DIALOG", InputQueueSourceEnum::FROM_DIALOG)
        .value("eFROM_PROCESS", InputQueueSourceEnum::FROM_PROCESS)
        .value("eFROM_MDL", InputQueueSourceEnum::FROM_MDL)
        .value("eFROM_PRDFPI", InputQueueSourceEnum::FROM_PRDFPI)
        .value("eFROM_OPER_SYSTEM", InputQueueSourceEnum::FROM_OPER_SYSTEM)
        .export_values();

    py::enum_<CadInputType>(m, "CadInputType")
        .value("eCadInputTypeNone", CadInputType::CadInputTypeNone)
        .value("eCadInputTypeCommand", CadInputType::CadInputTypeCommand)
        .value("eCadInputTypeReset", CadInputType::CadInputTypeReset)
        .value("eCadInputTypeDataPoint", CadInputType::CadInputTypeDataPoint)
        .value("eCadInputTypeKeyin", CadInputType::CadInputTypeKeyin)
        .value("eCadInputTypeAny", CadInputType::CadInputTypeAny)
        .export_values();

    py::enum_<CommandFilterReturnValue>(m, "CommandFilterReturnValue")
        .value("eINPUT_COMMAND_ACCEPT" , CommandFilterReturnValue::INPUT_COMMAND_ACCEPT)
        .value("eINPUT_COMMAND_REJECT" , CommandFilterReturnValue::INPUT_COMMAND_REJECT)
        .value("eINPUT_COMMAND_CHANGED", CommandFilterReturnValue::INPUT_COMMAND_CHANGED)
        .export_values();

    py::enum_<InputFilterReturnValue>(m, "InputFilterReturnValue")
        .value("eINPUT_ACCEPT", InputFilterReturnValue::INPUT_ACCEPT)
        .value("eINPUT_REJECT", InputFilterReturnValue::INPUT_REJECT)
        .export_values();

    py::enum_<InputMonitorFilter>(m, "InputMonitorFilter")
        .value("eMONITOR_NOT_FROM_APP", InputMonitorFilter::MONITOR_NOT_FROM_APP)
        .value("eMONITOR_FROM_APP"    , InputMonitorFilter::MONITOR_FROM_APP)
        .value("eMONITOR_ALL"         , InputMonitorFilter::MONITOR_ALL)
        .export_values();

    py::class_<PyCadInputQueue> c1 (m, "PyCadInputQueue");
    c1.def_static ("SendKeyin", &PyCadInputQueue::SendKeyin, "keyinStr"_a);
    c1.def_static ("SendDataPoint", &PyCadInputQueue::SendDataPoint, "point"_a, "view"_a, "qualifiers"_a = 0);
    c1.def_static ("SendReset", &PyCadInputQueue::SendReset);
    c1.def_static ("SendCommand", &PyCadInputQueue::SendCommand, "commandStr"_a);
    c1.def_static ("SendDataPointForLocate", &PyCadInputQueue::SendDataPointForLocate, "element"_a, "point"_a);
    c1.def_static ("GetInput", &PyCadInputQueue::GetInput, "type1"_a, "type2"_a, "type3"_a, "type4"_a);
    c1.def_static ("RequeueLastInput", &mdlInput_requeueLastInput, "position"_a);
    c1.def_static ("PythonMainLoop", &mdlInput_pythonMainLoop);
    c1.def_static ("AttachTkinterToolSetting", &mdlDialog_AttachTkinterToolSetting, "hTkWin"_a);
    c1.def_static("AttachQtToolSetting", &mdlDialog_AttachQtToolSetting, "hQtWin"_a);
    c1.def_static ("SendKeyinToPython", &PyCadInputQueue::SendKeyinToPython, "keyinStr"_a);

    py::class_<PyCadInputMessage> c2 (m, "PyCadInputMessage");
    c2.def ("GetCommandKeyin", &PyCadInputMessage::GetCommandKeyin);
    c2.def ("GetCursorButton", &PyCadInputMessage::GetCursorButton);
    c2.def ("GetPoint", &PyCadInputMessage::GetPoint);
    c2.def ("GetKeyin", &PyCadInputMessage::GetKeyin);
    c2.def ("GetInputType", &PyCadInputMessage::GetInputType);
    c2.def ("GetScreenPoint", &PyCadInputMessage::GetScreenPoint);
    c2.def ("GetView", &PyCadInputMessage::GetView);

    py::class_<Inputq_keyin> c3(m, "Inputq_keyin");
    c3.def_property_readonly("len",
        [](Inputq_keyin const& self) {return &self.len; });
    c3.def_property_readonly("type",
        [](Inputq_keyin const& self) {return &self.type; });
    c3.def_property_readonly("keyin",
        [](Inputq_keyin const& self) {return self.keyin; });

    py::class_<Inputq_pnt> c4(m, "Inputq_pnt");
    c4.def_property_readonly("view",
        [](Inputq_pnt const& self) {return &self.view; });
    c4.def_property_readonly("phys_screen",
        [](Inputq_pnt const& self) {return &self.phys_screen; });
    c4.def_property_readonly("cmdpoint",
        [](Inputq_pnt const& self) {return &self.cmdpoint; });
    c4.def_property_readonly("region",
        [](Inputq_pnt const& self) {return &self.region; });
    c4.def_property_readonly("scrnpoint",
        [](Inputq_pnt const& self) {return &self.scrnpoint; });
    c4.def_property_readonly("rawUors",
        [](Inputq_pnt const& self) {return &self.rawUors; });
    c4.def_property_readonly("uors",
        [](Inputq_pnt const& self) {return &self.uors; });
    c4.def_property_readonly("buttonTrans",
        [](Inputq_pnt const& self) {return &self.buttonTrans; });
    c4.def_property_readonly("qualifierMask",
        [](Inputq_pnt const& self) {return &self.qualifierMask; });

    py::class_<Inputq_datapnt> c5(m, "Inputq_datapnt");
    c5.def_property_readonly("pnt",
        [](Inputq_datapnt const& self) {return &self.pnt; });
    c5.def_property_readonly("precision",
        [](Inputq_datapnt const& self) {return &self.precision; });
    c5.def_property_readonly("viewflags",
        [](Inputq_datapnt const& self) {return std::vector<bool>(std::begin (self.viewflags), std::end(self.viewflags)); });

    py::class_<Inputq_rawButton> c6(m, "Inputq_rawButton");
    c6.def_property_readonly("buttonNumber",
        [](Inputq_rawButton const& self) {return &self.buttonNumber; });
    c6.def_property_readonly("buttonTrans",
        [](Inputq_rawButton const& self) {return &self.buttonTrans; });
    c6.def_property_readonly("buttonTime",
        [](Inputq_rawButton const& self) {return &self.buttonTime; });
    c6.def_property_readonly("qualifierMask",
        [](Inputq_rawButton const& self) {return &self.qualifierMask; });
    c6.def_property_readonly("scrnPoint",
        [](Inputq_rawButton const& self) {return &self.scrnPoint; });
    c6.def_property_readonly("tabletPoint",
        [](Inputq_rawButton const& self) {return &self.tabletPoint; });
    c6.def_property_readonly("region",
        [](Inputq_rawButton const& self) {return &self.region; });
    c6.def_property_readonly("physScreen",
        [](Inputq_rawButton const& self) {return &self.physScreen; });
    c6.def_property_readonly("originalButtonNumber",
        [](Inputq_rawButton const& self) {return &self.originalButtonNumber; });

    py::class_<Inputq_command> c7(m, "Inputq_command");
    c7.def_property_readonly("commandClass",
        [](Inputq_command const& self) {return &self.commandClass; });
    c7.def_property_readonly("immediate",
        [](Inputq_command const& self) {return &self.immediate; });
    c7.def_property_readonly("command",
        [](Inputq_command const& self) {return &self.command; });
    c7.def_property_readonly("taskId",
        [](Inputq_command const& self) {return self.taskId; });
    c7.def_property_readonly("button",
        [](Inputq_command const& self) {return &self.button; });
    c7.def_property_readonly("unparsed",
        [](Inputq_command const& self) {return self.unparsed; });

    py::class_<Inputq_tentpnt> c8(m, "Inputq_tentpnt");
    c8.def_property_readonly("pnt",
        [](Inputq_tentpnt const& self) {return &self.pnt; });

    py::class_<Inputq_reset> c9(m, "Inputq_reset");
    c9.def_property_readonly("reset",
        [](Inputq_reset const& self) {return &self.reset; });

    py::class_<Inputq_partial> c10(m, "Inputq_partial");
    c10.def_property_readonly("len",
        [](Inputq_partial const& self) {return &self.len; });
    c10.def_property_readonly("keyin",
        [](Inputq_partial const& self) {return self.keyin; });

    py::class_<Inputq_unassignedcb> c11(m, "Inputq_unassignedcb");
    c11.def_property_readonly("pnt",
        [](Inputq_unassignedcb const& self) {return &self.pnt; });
    c11.def_property_readonly("cursbutn",
        [](Inputq_unassignedcb const& self) {return &self.cursbutn; });

    py::class_<Inputq_menumsg> c12(m, "Inputq_menumsg");
    c12.def_property_readonly("message",
        [](Inputq_menumsg const& self) {return self.message; });

    py::class_<Inputq_submenu> c13(m, "Inputq_submenu");
    c13.def_property_readonly("subname",
        [](Inputq_submenu const& self) {return self.subname; });

    py::class_<Inputq_menuwait> c14(m, "Inputq_menuwait");
    c14.def_property_readonly("prompt",
        [](Inputq_menuwait const& self) {return &self.prompt; });
    c14.def_property_readonly("waittype",
        [](Inputq_menuwait const& self) {return &self.waittype; });

    py::class_<MentryContents> c15(m, "MentryContents");
    c15.def_property_readonly("type",
        [](MentryContents const& self) {return &self.type; });
    c15.def_property_readonly("data_prim",
        [](MentryContents const& self) {return &self.data.prim; });
    c15.def_property_readonly("data_interpcmd",
        [](MentryContents const& self) {return &self.data.interpcmd; });
    c15.def_property_readonly("data_ucmd",
        [](MentryContents const& self) {return &self.data.ucmd; });
    c15.def_property_readonly("data_symbol",
        [](MentryContents const& self) {return &self.data.symbol; });
    c15.def_property_readonly("data_intype",
        [](MentryContents const& self) {return &self.data.intype; });
    c15.def_property_readonly("data_offset",
        [](MentryContents const& self) {return &self.data.offset; });

    py::class_<Inputq_contents> c16(m, "Inputq_contents");
    c16.def_property_readonly("contents",
        [](Inputq_contents const& self) {return &self.contents; });
    c16.def_property_readonly("unparsed",
        [](Inputq_contents const& self) {return self.unparsed; });

    py::class_<Inputq_null> c17(m, "Inputq_null");
    c17.def_property_readonly("breaknow",
        [](Inputq_null const& self) {return &self.breaknow; });

    py::class_<Inputq_nullcmd> c18(m, "Inputq_nullcmd");
    c18.def_property_readonly("nullcmd",
        [](Inputq_nullcmd const& self) {return &self.nullcmd; });

    py::class_<Inputq_rawKeyStroke> c19(m, "Inputq_rawKeyStroke");
    c19.def_property_readonly("keyStroke",
        [](Inputq_rawKeyStroke const& self) {return &self.keyStroke; });
    c19.def_property_readonly("qualifierMask",
        [](Inputq_rawKeyStroke const& self) {return &self.qualifierMask; });
    c19.def_property_readonly("scanCode",
        [](Inputq_rawKeyStroke const& self) {return &self.scanCode; });

    py::class_<Inputq_cookedKey> c20(m, "Inputq_cookedKey");
    c20.def_property_readonly("keyStroke",
        [](Inputq_cookedKey const& self) {return &self.keyStroke; });
    c20.def_property_readonly("qualifierMask",
        [](Inputq_cookedKey const& self) {return &self.qualifierMask; });
    c20.def_property_readonly("virtualKey",
        [](Inputq_cookedKey const& self) {return &self.virtualKey; });
    c20.def_property_readonly("scanCode",
        [](Inputq_cookedKey const& self) {return &self.scanCode; });

    py::class_<Inputq_rawIconEvent> c21(m, "Inputq_rawIconEvent");
    c21.def_property_readonly("rawButton",
        [](Inputq_rawIconEvent const& self) {return &self.rawButton; });
    c21.def_property_readonly("controlRect",
        [](Inputq_rawIconEvent const& self) {return self.controlRectP; });
    c21.def_property_readonly("callBackID_data",
        [](Inputq_rawIconEvent const& self) {return &self.callBackID.data; });

    py::class_<Inputq_virtualEOQ> c22(m, "Inputq_virtualEOQ");
    c22.def_property_readonly("process",
        [](Inputq_virtualEOQ const& self) {return &self.process; });

    py::class_<Inputq_3DInputEvent> c23(m, "Inputq_3DInputEvent");
    c23.def_property_readonly("m_time",
        [](Inputq_3DInputEvent const& self) {return &self.m_time; });
    c23.def_property_readonly("m_rotDirection",
        [](Inputq_3DInputEvent const& self) {return &self.m_rotDirection; });
    c23.def_property_readonly("m_rotMagnitude",
        [](Inputq_3DInputEvent const& self) {return &self.m_rotMagnitude; });
    c23.def_property_readonly("m_translation",
        [](Inputq_3DInputEvent const& self) {return &self.m_translation; });

    py::class_<Inputq_queuedAction> c24(m, "Inputq_queuedAction");
    c24.def_property_readonly("m_action",
        [](Inputq_queuedAction const& self) {return self.m_action; });

    py::class_<Inputq_header> c25(m, "Inputq_header");
    c25.def_property_readonly("bytes",
        [](Inputq_header const& self) {return &self.bytes; });
    c25.def_property_readonly("cmdtype",
        [](Inputq_header const& self) {return &self.cmdtype; });
    c25.def_property_readonly("source",
        [](Inputq_header const& self) {return &self.source; });
    c25.def_property_readonly("uc_fno_value",
        [](Inputq_header const& self) {return &self.uc_fno_value; });
    c25.def_property_readonly("sourcepid",
        [](Inputq_header const& self) {return &self.sourcepid; });
    c25.def_property_readonly("taskId",
        [](Inputq_header const& self) {return self.taskId; });

    py::class_<Inputq_element> c30(m, "Inputq_element");
    c30.def_property_readonly("hdr",
        [](Inputq_element const& self) {return &self.hdr; });
    c30.def_property_readonly("u_keyin",
        [](Inputq_element const& self) {return &self.u.keyin; });
    c30.def_property_readonly("u_data",
        [](Inputq_element const& self) {return &self.u.data; });
    c30.def_property_readonly("u_cmd",
        [](Inputq_element const& self) {return &self.u.cmd; });
    c30.def_property_readonly("u_tent",
        [](Inputq_element const& self) {return &self.u.tent; });
    c30.def_property_readonly("u_reset",
        [](Inputq_element const& self) {return &self.u.reset; });
    c30.def_property_readonly("u_partial",
        [](Inputq_element const& self) {return &self.u.partial; });
    c30.def_property_readonly("u_cursbutn",
        [](Inputq_element const& self) {return &self.u.cursbutn; });
    c30.def_property_readonly("u_menumsg",
        [](Inputq_element const& self) {return &self.u.menumsg; });
    c30.def_property_readonly("u_submenu",
        [](Inputq_element const& self) {return &self.u.submenu; });
    c30.def_property_readonly("u_menuwait",
        [](Inputq_element const& self) {return &self.u.menuwait; });
    c30.def_property_readonly("u_contents",
        [](Inputq_element const& self) {return &self.u.contents; });
    c30.def_property_readonly("u_nullqelem",
        [](Inputq_element const& self) {return &self.u.nullqelem; });
    c30.def_property_readonly("u_nullcmd",
        [](Inputq_element const& self) {return &self.u.nullcmd; });
    c30.def_property_readonly("u_rawButton",
        [](Inputq_element const& self) {return &self.u.rawButton; });
    c30.def_property_readonly("u_rawKeyStroke",
        [](Inputq_element const& self) {return &self.u.rawKeyStroke; });
    c30.def_property_readonly("u_cookedKey",
        [](Inputq_element const& self) {return &self.u.cookedKey; });
    c30.def_property_readonly("u_rawIconEvent",
        [](Inputq_element const& self) {return &self.u.rawIconEvent; });
    c30.def_property_readonly("u_virtualEOQ",
        [](Inputq_element const& self) {return &self.u.virtualEOQ; });
    c30.def_property_readonly("u_m_3DInput",
        [](Inputq_element const& self) {return &self.u.m_3DInput; });
    c30.def_property_readonly("u_m_queuedAction",
        [](Inputq_element const& self) {return &self.u.m_queuedAction; });

    py::class_<InputCallback> c31(m, "InputCallback");
    c31.def_static("SetCommandFilterFunction", [](std::function<std::remove_pointer_t<InputFunc_CommandFilter>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<InputFunc_CommandFilter>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(InputCallback::SetCommandFilterFunction, Inputq_element*, CommandFilterReturnValue, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c31.def_static("SetMessageReceivedFunction", [](std::function<std::remove_pointer_t<InputFunc_MessageReceived>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<InputFunc_MessageReceived>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(InputCallback::SetMessageReceivedFunction, Inputq_element*, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);

    c31.def_static("SetPreprocessKeyinFunction", [](std::function<InputFilterReturnValue(WString*)>& newFunc, const std::string& funcID) -> std::function<InputFilterReturnValue(WString*)>
        {
            PreprocessKeyinCallbackHelper::PreprocessKeyinCallbackPtrType oldCallback;
            if (newFunc)
            {
                PreprocessKeyinCallbackHelper::PreprocessKeyinCallbackPtrType callback = PreprocessKeyinCallbackHelper::SetCallback(newFunc, funcID);
                oldCallback = InputCallback::SetPreprocessKeyinFunction(callback);
            }
            else
            {
                oldCallback = InputCallback::SetPreprocessKeyinFunction(nullptr);
            }
            if (nullptr != oldCallback)
            {
                return PreprocessKeyinCallbackHelper::GetOldCallbackFunction(oldCallback);
            }
            else
            {
                return nullptr;
            }
        }, "newFunc"_a, "funcID"_a);

    c31.def_static("SetMonitorFunction", [](std::function<std::remove_pointer_t<InputFunc_Monitor>>& newFunc, const std::string& funcID, InputMonitorFilter filter) -> std::function<std::remove_pointer_t<InputFunc_Monitor>>
        {
            if (newFunc)
            {
                InputFilterReturnValue(*callback)(Inputq_element*) = CallbackHelperOneParam<Inputq_element*, InputFilterReturnValue>::SetCallback(newFunc, funcID);
                return InputCallback::SetMonitorFunction(callback, filter);
            }
            else
            {
                return InputCallback::SetMonitorFunction(nullptr, filter);
            }
        }, "newFunc"_a, "funcID"_a, "filter"_a);

    c31.def_static("SetEnterIdleFunction", [](std::function<std::remove_pointer_t<InputFunc_EnterIdle>>& newFunc, const std::string& funcID) -> std::function<std::remove_pointer_t<InputFunc_EnterIdle>>
        {
            ADD_FN_POINTER_CALLBACK_ONE_PARAM(InputCallback::SetEnterIdleFunction, int, void, newFunc, funcID)
        }, "newFunc"_a, "funcID"_a);
    }
