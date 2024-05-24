/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\msinput.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/MdlApi/msinput.fdf>
extern "C" __declspec(dllimport) void mdlDialog_AttachTkinterToolSetting(int hTkWin);
extern "C" __declspec(dllimport) void mdlDialog_AttachQtToolSetting(int hQtWin);
#include <Mstn/PythonMacro/PyCadInputQueue.h>


USING_NAMESPACE_BENTLEY_MSTNPLATFORM
/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      3/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msinput(py::module_& m)
    {
    py::enum_<MSInputQueuePos> (m, "MSInputQueuePos")
        .value("eINPUTQ_HEAD", MSInputQueuePos::INPUTQ_HEAD)
        .value("eINPUTQ_EOQ", MSInputQueuePos::INPUTQ_EOQ);

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
        .value("eFROM_OPER_SYSTEM", InputQueueSourceEnum::FROM_OPER_SYSTEM);

    py::enum_<CadInputType>(m, "CadInputType")
        .value("eCadInputTypeNone", CadInputType::CadInputTypeNone)
        .value("eCadInputTypeCommand", CadInputType::CadInputTypeCommand)
        .value("eCadInputTypeReset", CadInputType::CadInputTypeReset)
        .value("eCadInputTypeDataPoint", CadInputType::CadInputTypeDataPoint)
        .value("eCadInputTypeKeyin", CadInputType::CadInputTypeKeyin)
        .value("eCadInputTypeAny", CadInputType::CadInputTypeAny);

    py::class_<PyCadInputQueue> c1 (m, "PyCadInputQueue");
    c1.def_static ("SendKeyin", &PyCadInputQueue::SendKeyin, "keyinStr"_a);
    c1.def_static ("SendDataPoint", &PyCadInputQueue::SendDataPoint, "point"_a, "view"_a);
    c1.def_static ("SendReset", &PyCadInputQueue::SendReset);
    c1.def_static ("SendCommand", &PyCadInputQueue::SendCommand, "commandStr"_a);
    c1.def_static ("SendDataPointForLocate", &PyCadInputQueue::SendDataPointForLocate, "element"_a, "point"_a);
    c1.def_static ("GetInput", &PyCadInputQueue::GetInput, "type1"_a, "type2"_a, "type3"_a, "type4"_a);
    c1.def_static ("SequeueLastInput", &mdlInput_requeueLastInput, "position"_a);
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

    }
