/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\xdatatreemanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/XDataTreeManager.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XDataTreeManager(py::module_& m)
    {
    //===================================================================================
    // struct XDataTreeManager
    py::class_< XDataTreeManager> c1(m, "XDataTreeManager");

    c1.def_static("GetDgnXDataTreeOwner", &XDataTreeManager::GetDgnXDataTreeOwner, "dgnFile", py::return_value_policy::reference);

    c1.def_static("GetVirtualDgnXDataTreeOwner", 
                  &XDataTreeManager::GetVirtualDgnXDataTreeOwner,
                  "dataMapName"_a, "label"_a = nullptr, "createIfNotFound"_a = false, py::return_value_policy::reference);

    c1.def_static("UpgradeInstanceIfNecessary", &XDataTreeManager::UpgradeInstanceIfNecessary, "instance"_a);
    c1.def_static("StaticInitialize", &XDataTreeManager::StaticInitialize);
    c1.def_static("ClearVirtualDgnData", &XDataTreeManager::ClearVirtualDgnData, "dataMapName"_a);
    c1.def_static("ReloadHandlerSpecificFileAppDataCache", &XDataTreeManager::ReloadHandlerSpecificFileAppDataCache, "dgnFile"_a, "hid"_a);
    c1.def_static("ReloadFileAppDataCache", &XDataTreeManager::ReloadFileAppDataCache, "dgnFile"_a);

    c1.def_static("GetListOfDependents", &XDataTreeManager::GetListOfDependents, "dependentElements"_a, "elRef"_a);
    c1.def_static("GetTopParentRef", &XDataTreeManager::GetTopParentRef, "childRef"_a, py::return_value_policy::reference);
    c1.def_static("GetPathUsingElementRef", &XDataTreeManager::GetPathUsingElementRef, "elemRef"_a, "hid"_a);

    c1.def_property_readonly_static("UserInterfaceSchemaName", [] (py::object const&) { return XDataTreeManager::GetUserInterfaceSchemaName(); });
    c1.def_static("GetUserInterfaceSchemaName", &XDataTreeManager::GetUserInterfaceSchemaName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("ElementTemplatesSchemaName", [] (py::object const&) { return XDataTreeManager::GetElementTemplatesSchemaName(); });
    c1.def_static("GetElementTemplatesSchemaName", &XDataTreeManager::GetElementTemplatesSchemaName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("DetailingSymbolStyleSchemaName", [] (py::object const&) { return XDataTreeManager::GetDetailingSymbolStyleSchemaName(); });
    c1.def_static("GetDetailingSymbolStyleSchemaName", &XDataTreeManager::GetDetailingSymbolStyleSchemaName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("ECReportSchemaName", [] (py::object const&) { return XDataTreeManager::GetECReportSchemaName(); });
    c1.def_static("GetECReportSchemaName", &XDataTreeManager::GetECReportSchemaName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("UserInterfaceBaseClassName", [] (py::object const&) { return XDataTreeManager::GetUserInterfaceBaseClassName(); });
    c1.def_static("GetUserInterfaceBaseClassName", &XDataTreeManager::GetUserInterfaceBaseClassName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("ElementTemplatesBaseClassName", [] (py::object const&) { return XDataTreeManager::GetElementTemplatesBaseClassName(); });
    c1.def_static("GetElementTemplatesBaseClassName", &XDataTreeManager::GetElementTemplatesBaseClassName, py::return_value_policy::reference);
    
    c1.def_property_readonly_static("DetailSymbolExtenderBaseClassName", [] (py::object const&) { return XDataTreeManager::GetDetailSymbolExtenderBaseClassName(); });
    c1.def_static("GetDetailSymbolExtenderBaseClassName", &XDataTreeManager::GetDetailSymbolExtenderBaseClassName, py::return_value_policy::reference);

    c1.def_static("GetDetailingSymbolStyleInstanceEnablerForFile", &XDataTreeManager::GetDetailingSymbolStyleInstanceEnablerForFile, "dgnFile"_a, py::return_value_policy::reference);
    c1.def_static("GetDetailingSymbolStyleInstanceEnabler", &XDataTreeManager::GetDetailingSymbolStyleInstanceEnabler, "owner"_a, py::return_value_policy::reference);
    c1.def_static("GetElementTemplateInstanceEnablerForFile", &XDataTreeManager::GetElementTemplateInstanceEnablerForFile, "dgnFile"_a, py::return_value_policy::reference);
    c1.def_static("GetElementTemplateInstanceEnabler", &XDataTreeManager::GetElementTemplateInstanceEnabler, "owner"_a, py::return_value_policy::reference);
    c1.def_static("GetUserInterfaceInstanceEnablerForFile", &XDataTreeManager::GetUserInterfaceInstanceEnablerForFile, "dgnFile"_a, py::return_value_policy::reference);
    c1.def_static("GetUserInterfaceInstanceEnabler", &XDataTreeManager::GetUserInterfaceInstanceEnabler, "owner"_a, py::return_value_policy::reference);
    
    c1.def_static("GetXDataTreeNodeFromPath",
                  py::overload_cast<WCharP, XDataTreeOwner&, HandlerId>(&XDataTreeManager::GetXDataTreeNodeFromPath),
                  "wPath"_a, "owner"_a, "handlerId"_a);

    c1.def_static("GetXDataTreeNodeFromPath",
                  py::overload_cast<WCharP, DgnFileR, HandlerId>(&XDataTreeManager::GetXDataTreeNodeFromPath),
                  "wPath"_a, "dgnFile"_a, "handlerId"_a);

    c1.def_static("GetXDataTreeNodeById", &XDataTreeManager::GetXDataTreeNodeById, "templateId"_a, "dgnFile"_a, "handlerId"_a);
    c1.def_static("GetStandaloneECEnabler", &XDataTreeManager::GetStandaloneECEnabler, "fullSchemaName"_a, "className"_a, "iXDataTreeOwner"_a);
    }