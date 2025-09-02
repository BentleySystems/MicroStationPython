/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\xcommand.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/XCommand.h>



static const char * __doc_Bentley_MstnPlatform_ApplicationRefXCommand_SetTreatAsPushButton =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_ApplicationRefXCommand_GetTreatAsPushButton =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_UserKeyinXCommand_SetTreatAsPushButton =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_UserKeyinXCommand_GetTreatAsPushButton =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_UserKeyinXCommand_SetCommandId =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_UserKeyinXCommand_SetCmdString =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_UserKeyinXCommand_GetCmdString =R"doc()doc";

static const char * __doc_Bentley_MstnPlatform_XCommand_SetJournal =R"doc(Set property to journal the command for macro recording.

:param journal:
    set to true if the command is to be recorded. The default is to
    journal.

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommand_GetJournal =R"doc(Return the setting of the property that allows command to be saved for
macro recording.

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommand_SetIsUserDefined =R"doc(Marks the Command as being user created.

:param isUserDefined:
    set to true if the command is user defined.

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommand_SetCmdNumber =R"doc(Sets the Command Number.

:param cmdNumber:
    The command number

:param taskId:
    The Id of the task owning the Command Number

:param unparsed:
    The string parameter for this command

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XCommand(py::module_& m)
    {
    //===================================================================================
    // class XCommand
    py::class_< XCommand, RefCountedPtr<XCommand>, IXCommand> c1(m, "XCommand");

    c1.def(py::init(&XCommand::Create), "commandId"_a);
    c1.def("SetCmdNumber", &XCommand::SetCmdNumber, "cmdNumber"_a, "taskId"_a, "unparsed"_a, DOC(Bentley, MstnPlatform, XCommand, SetCmdNumber));
    c1.def("SetIsUserDefined", &XCommand::SetIsUserDefined, "isUserDefined"_a = true, DOC(Bentley, MstnPlatform, XCommand, SetIsUserDefined));
    
    c1.def_property("Journal", &XCommand::GetJournal, &XCommand::SetJournal);
    c1.def("GetJournal", &XCommand::GetJournal, DOC(Bentley, MstnPlatform, XCommand, GetJournal));
    c1.def("SetJournal", &XCommand::SetJournal, "journal"_a, DOC(Bentley, MstnPlatform, XCommand, SetJournal));

    //===================================================================================
    // class UserKeyinXCommand
    py::class_< UserKeyinXCommand, RefCountedPtr< UserKeyinXCommand>, XCommand> c2(m, "UserKeyinXCommand");

    c2.def(py::init(&UserKeyinXCommand::Create), "commandString"_a = nullptr, "label"_a = nullptr, "description"_a = nullptr);
    
    c2.def_property("CmdString", &UserKeyinXCommand::GetCmdString, &UserKeyinXCommand::SetCmdString);
    c2.def("GetCmdString", &UserKeyinXCommand::GetCmdString, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, UserKeyinXCommand, GetCmdString));
    c2.def("SetCmdString", &UserKeyinXCommand::SetCmdString, "cmdString"_a, DOC(Bentley, MstnPlatform, UserKeyinXCommand, SetCmdString));
    
    c2.def("SetCommandId", &UserKeyinXCommand::SetCommandId, "cmdId"_a, DOC(Bentley, MstnPlatform, UserKeyinXCommand, SetCommandId));
    
    c2.def_property("TreatAsPushButton", &UserKeyinXCommand::GetTreatAsPushButton, &UserKeyinXCommand::SetTreatAsPushButton);
    c2.def("GetTreatAsPushButton", &UserKeyinXCommand::GetTreatAsPushButton, DOC(Bentley, MstnPlatform, UserKeyinXCommand, GetTreatAsPushButton));
    c2.def("SetTreatAsPushButton", &UserKeyinXCommand::SetTreatAsPushButton, "treatAsButton"_a, DOC(Bentley, MstnPlatform, UserKeyinXCommand, SetTreatAsPushButton));

    //===================================================================================
    // class ApplicationRefXCommand
    py::class_< ApplicationRefXCommand, RefCountedPtr< ApplicationRefXCommand>, XCommand> c3(m, "ApplicationRefXCommand");

    c3.def(py::init(&ApplicationRefXCommand::Create), "cmdNumber"_a, "taskId"_a = nullptr, "unparsed"_a = nullptr);

    c3.def_property("TreatAsPushButton", &ApplicationRefXCommand::GetTreatAsPushButton, &ApplicationRefXCommand::SetTreatAsPushButton);
    c3.def("GetTreatAsPushButton", &ApplicationRefXCommand::GetTreatAsPushButton, DOC(Bentley, MstnPlatform, ApplicationRefXCommand, GetTreatAsPushButton));
    c3.def("SetTreatAsPushButton", &ApplicationRefXCommand::SetTreatAsPushButton, "treatAsButton"_a, DOC(Bentley, MstnPlatform, ApplicationRefXCommand, SetTreatAsPushButton));
    }