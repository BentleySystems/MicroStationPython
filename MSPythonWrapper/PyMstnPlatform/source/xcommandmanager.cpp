/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\xcommandmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/XCommandManager.h>



static const char * __doc_Bentley_MstnPlatform_XCommandManager_ExecuteXCommand =R"doc(Execute a registered XCommand.

:param commandId:
    The Id of the IXCommand

:param unparsedP:
    Command parameters *

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommandManager_FindXCommandByIconName =R"doc(Finds an IXCommand in the list by Icon Name.

:param iconName:
    The icon name of the IXCommand *

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommandManager_GetAvailableXCommands =R"doc(Populates a bvector with all the IXCommands in the list.

:param xCommands:
    A bvector that is populated with a list of the IXCommands *

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommandManager_FindXCommand =R"doc(Finds an IXCommand in the list.

:param commandId:
    The Id of the IXCommand *

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommandManager_DeregisterXCommand =R"doc(Deregisters an IXCommand and removes it from the list.

:param commandId:
    The Id of the IXCommand *

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommandManager_RegisterXCommand =R"doc(Registers an IXCommand and adds it to the list.

:param commandId:
    The Id of the IXCommand

:param xCommand:
    Pointer to an instance of an implementation of the IXCommand
    interface *

)doc";

static const char * __doc_Bentley_MstnPlatform_XCommandManager_GetManager =R"doc(Gets the singleton instance of the XCommandManager. *

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XCommandManager(py::module_& m)
    {
    //===================================================================================
    // struct XCommandManager
    py::class_< XCommandManager, std::unique_ptr<XCommandManager, py::nodelete> > c1(m, "XCommandManager");

    c1.def_property_readonly_static("Manager", [] (py::object const&) { return std::unique_ptr< XCommandManager, py::nodelete>(&XCommandManager::GetManager()); });
    c1.def_static("GetManager", [] () { return std::unique_ptr< XCommandManager, py::nodelete>(&XCommandManager::GetManager()); }, DOC(Bentley, MstnPlatform, XCommandManager, GetManager));

    c1.def("RegisterXCommand", &XCommandManager::RegisterXCommand, "commandId"_a, "xCommand"_a, py::keep_alive<1, 3>(), DOC(Bentley, MstnPlatform, XCommandManager, RegisterXCommand));
    c1.def("DeregisterXCommand", &XCommandManager::DeregisterXCommand, "commandId"_a, DOC(Bentley, MstnPlatform, XCommandManager, DeregisterXCommand));
    c1.def("FindXCommand", &XCommandManager::FindXCommand, "commandId"_a, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, XCommandManager, FindXCommand));
    c1.def("GetAvailableXCommands", &XCommandManager::GetAvailableXCommands, "xCommands"_a, DOC(Bentley, MstnPlatform, XCommandManager, GetAvailableXCommands));
    c1.def("FindXCommandByIconName", &XCommandManager::FindXCommandByIconName, "iconName"_a, py::return_value_policy::reference_internal, DOC(Bentley, MstnPlatform, XCommandManager, FindXCommandByIconName));
    c1.def("ExecuteXCommand", &XCommandManager::ExecuteXCommand, "commandId"_a, "unparsed"_a, DOC(Bentley, MstnPlatform, XCommandManager, ExecuteXCommand));
    }