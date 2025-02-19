/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\userinterfacenode.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/UserInterfaceNode.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_UserInterfaceNode(py::module_& m)
    {
    //===================================================================================
    // struct UserInterfaceNode
    py::class_< UserInterfaceNode, UserInterfaceNodePtr, XDataTreeNode> c1(m, "UserInterfaceNode");

    c1.def_static("FromXDataTreeNodePtr", &UserInterfaceNode::FromXDataTreeNodePtr, "xDataNodePtr"_a);
    c1.def("GetNodeType", &UserInterfaceNode::GetNodeType, "nodeType"_a);
    c1.def("GetDefaultInstance", &UserInterfaceNode::GetDefaultInstance);
    c1.def("GetOrCreateDefaultInstance", &UserInterfaceNode::GetOrCreateDefaultInstance);

    //===================================================================================
    // struct ContextMenuNode
    py::class_< ContextMenuNode, ContextMenuNodePtr, UserInterfaceNode> c2(m, "ContextMenuNode");

    c2.def_static("FindByElementId", &ContextMenuNode::FindByElementId, "elemId"_a, "owner"_a);

    c2.def_static("CreateNode", 
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ContextMenuNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c2.def_static("CreateNode",
                  py::overload_cast<WCharCP, ContextMenuNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ContextMenuNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c2.def_static("FromXDataTreeNodePtr", &ContextMenuNode::FromXDataTreeNodePtr, "dtNode"_a);

    c2.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return ContextMenuNode::GetNodeHandlerId(); });
    c2.def_static("GetNodeHandlerId", &ContextMenuNode::GetNodeHandlerId);

    //===================================================================================
    // struct ExplorerContextMenuNode
    py::class_< ExplorerContextMenuNode, ExplorerContextMenuNodePtr, UserInterfaceNode> c3(m, "ExplorerContextMenuNode");

    c3.def_static("FindByElementId", &ExplorerContextMenuNode::FindByElementId, "elemId"_a, "owner"_a);

    c3.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ExplorerContextMenuNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c3.def_static("CreateNode",
                  py::overload_cast<WCharCP, ExplorerContextMenuNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ExplorerContextMenuNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c3.def_static("FromXDataTreeNodePtr", &ExplorerContextMenuNode::FromXDataTreeNodePtr, "dtNode"_a);
    
    c3.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return ExplorerContextMenuNode::GetNodeHandlerId(); });
    c3.def_static("GetNodeHandlerId", &ExplorerContextMenuNode::GetNodeHandlerId);

    //===================================================================================
    // struct MiniToolbarNode
    py::class_< MiniToolbarNode, MiniToolbarNodePtr, UserInterfaceNode> c4(m, "MiniToolbarNode");

    c4.def_static("FindByElementId", &MiniToolbarNode::FindByElementId, "elemId"_a, "owner"_a);

    c4.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&MiniToolbarNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c4.def_static("CreateNode",
                  py::overload_cast<WCharCP, MiniToolbarNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&MiniToolbarNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c4.def_static("FromXDataTreeNodePtr", &MiniToolbarNode::FromXDataTreeNodePtr, "dtNode"_a);

    c4.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return MiniToolbarNode::GetNodeHandlerId(); });
    c4.def_static("GetNodeHandlerId", &MiniToolbarNode::GetNodeHandlerId);

    //===================================================================================
    // struct MainTaskNode
    py::class_< MainTaskNode, MainTaskNodePtr, UserInterfaceNode> c5(m, "MainTaskNode");

    c5.def_static("FindByElementId", &MainTaskNode::FindByElementId, "elemId"_a, "owner"_a);

    c5.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&MainTaskNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c5.def_static("CreateNode",
                  py::overload_cast<WCharCP, MainTaskNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&MainTaskNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c5.def_static("FromXDataTreeNodePtr", &MainTaskNode::FromXDataTreeNodePtr, "dtNode"_a);
    
    c5.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return MainTaskNode::GetNodeHandlerId(); });
    c5.def_static("GetNodeHandlerId", &MainTaskNode::GetNodeHandlerId);

    //===================================================================================
    // struct MenuNode
    py::class_< MenuNode, MenuNodePtr, UserInterfaceNode> c6(m, "MenuNode");

    c6.def_static("FindByElementId", &MenuNode::FindByElementId, "elemId"_a, "owner"_a);

    c6.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&MenuNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c6.def_static("CreateNode",
                  py::overload_cast<WCharCP, MenuNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&MenuNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c6.def_static("FromXDataTreeNodePtr", &MenuNode::FromXDataTreeNodePtr, "dtNode"_a);
    c6.def("SetAlternateNode", &MenuNode::SetAlternateNode, "node"_a);
    c6.def("ClearAlternateNode", &MenuNode::ClearAlternateNode);
    c6.def("GetAlternateNode", &MenuNode::GetAlternateNodePtr);

    c6.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return MenuNode::GetNodeHandlerId(); });
    c6.def_static("GetNodeHandlerId", &MenuNode::GetNodeHandlerId);

    //===================================================================================
    // struct TaskNode
    py::class_< TaskNode, TaskNodePtr, UserInterfaceNode> c7(m, "TaskNode");

    c7.def_static("FindByElementId", &TaskNode::FindByElementId, "elemId"_a, "owner"_a);

    c7.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&TaskNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c7.def_static("CreateNode",
                  py::overload_cast<WCharCP, TaskNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&TaskNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c7.def_static("FromXDataTreeNodePtr", &TaskNode::FromXDataTreeNodePtr, "dtNode"_a);

    c7.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return TaskNode::GetNodeHandlerId(); });
    c7.def_static("GetNodeHandlerId", &TaskNode::GetNodeHandlerId);

    //===================================================================================
    // struct TentativePopupMenuNode
    py::class_< TentativePopupMenuNode, TentativePopupMenuNodePtr, UserInterfaceNode> c8(m, "TentativePopupMenuNode");

    c8.def_static("FindByElementId", &TentativePopupMenuNode::FindByElementId, "elemId"_a, "owner"_a);

    c8.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&TentativePopupMenuNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c8.def_static("CreateNode",
                  py::overload_cast<WCharCP, TentativePopupMenuNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&TentativePopupMenuNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c8.def_static("FromXDataTreeNodePtr", &TentativePopupMenuNode::FromXDataTreeNodePtr, "dtNode"_a);

    c8.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return TentativePopupMenuNode::GetNodeHandlerId(); });
    c8.def_static("GetNodeHandlerId", &TentativePopupMenuNode::GetNodeHandlerId);

    //===================================================================================
    // struct ToolBoxNode
    py::class_< ToolBoxNode, ToolBoxNodePtr, UserInterfaceNode> c9(m, "ToolBoxNode");

    c9.def_static("FindByElementId", &ToolBoxNode::FindByElementId, "elemId"_a, "owner"_a);

    c9.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ToolBoxNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c9.def_static("CreateNode",
                  py::overload_cast<WCharCP, ToolBoxNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ToolBoxNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c9.def_static("FromXDataTreeNodePtr", &ToolBoxNode::FromXDataTreeNodePtr, "dtNode"_a);

    c9.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return ToolBoxNode::GetNodeHandlerId(); });
    c9.def_static("GetNodeHandlerId", &ToolBoxNode::GetNodeHandlerId);

    //===================================================================================
    // struct ViewPopupMenuNode
    py::class_< ViewPopupMenuNode, ViewPopupMenuNodePtr, UserInterfaceNode> c10(m, "ViewPopupMenuNode");

    c10.def_static("FindByElementId", &ViewPopupMenuNode::FindByElementId, "elemId"_a, "owner"_a);

    c10.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ViewPopupMenuNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c10.def_static("CreateNode",
                  py::overload_cast<WCharCP, ViewPopupMenuNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ViewPopupMenuNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr);

    c10.def_static("FromXDataTreeNodePtr", &ViewPopupMenuNode::FromXDataTreeNodePtr, "dtNode"_a);

    c10.def_property_readonly_static("NodeHandlerId", [] (py::object const&) { return ViewPopupMenuNode::GetNodeHandlerId(); });
    c10.def_static("GetNodeHandlerId", &ViewPopupMenuNode::GetNodeHandlerId);
        
    //===================================================================================
    // struct ApplicationToolData
    py::class_< ApplicationToolData> c11(m, "ApplicationToolData");    

    c11.def_property("Owner",
                     [] (ApplicationToolData const& self) { return self.owner; },
                     py::cpp_function([] (ApplicationToolData& self, WCharCP szOwner) { self.owner = szOwner; }, py::keep_alive<1, 2>()));

    c11.def_property("iconOwner",
                     [] (ApplicationToolData const& self) { return self.iconOwner; },
                     py::cpp_function([] (ApplicationToolData& self, WCharCP szOwner) { self.iconOwner = szOwner; }, py::keep_alive<1, 2>()));

    c11.def_readwrite("rscType", &ApplicationToolData::rscType);
    c11.def_readwrite("rscId", &ApplicationToolData::rscId);
    c11.def_readwrite("itemArg", &ApplicationToolData::itemArg);
    c11.def_readwrite("iconType", &ApplicationToolData::iconType);
    c11.def_readwrite("iconID", &ApplicationToolData::iconID);
    c11.def_readwrite("cmdNum", &ApplicationToolData::cmdNum);

    //===================================================================================
    // struct UserInterfaceHelper
    py::class_< UserInterfaceHelper> c12(m, "UserInterfaceHelper");

    c12.def_static("SetNamedToolIconName", &UserInterfaceHelper::SetNamedToolIconName, "instance"_a, "iconName"_a);

    c12.def_static("SetTaskContainerIconName", &UserInterfaceHelper::SetTaskContainerIconName, "instance"_a, "iconName"_a);

    c12.def_static("SetNamedToolRefInstanceData", &UserInterfaceHelper::SetNamedToolRefInstanceData, "instance"_a, "referenceToolFullPath"_a);

    c12.def_static("SetApplicationToolRefInstanceData", &UserInterfaceHelper::SetApplicationToolRefInstanceData, "instance"_a, "appToolData"_a, "showHideCriteria"_a);

    c12.def_static("AddApplicationToolRefToToolTree", [] (WCharCP taskToolName, ToolBoxNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib,
                                                          ApplicationToolData& appToolData, WCharCP showHideCriteria)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddApplicationToolRefToToolTree(taskToolName, parentNode, sortValue, virtualDgnlib, appToolData, showHideCriteria);
                   return py::make_tuple(retVal, sortValue_);
                   }, "taskToolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "appToolData"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("AddApplicationToolRefToTaskTree", [] (WCharCP taskToolName, TaskNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib,
                                                          ApplicationToolData& appToolData, WCharCP showHideCriteria)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddApplicationToolRefToTaskTree(taskToolName, parentNode, sortValue, virtualDgnlib, appToolData, showHideCriteria);
                   return py::make_tuple(retVal, sortValue_);
                   }, "taskToolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "appToolData"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("AddNamedToolRefToTaskTree", [] (WCharCP taskToolName, TaskNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib, ToolBoxNodeCR referenceToolNode)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddNamedToolRefToTaskTree(taskToolName, parentNode, sortValue, virtualDgnlib, referenceToolNode);
                   return py::make_tuple(retVal, sortValue_);
                   }, "taskToolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "referenceToolNode"_a);

    c12.def_static("AddNamedToolRefByPathToTaskTree", [] (WCharCP taskToolName, TaskNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib, WCharCP referenceToolFullPath)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddNamedToolRefByPathToTaskTree(taskToolName, parentNode, sortValue, virtualDgnlib, referenceToolFullPath);
                   return py::make_tuple(retVal, sortValue_);
                   }, "taskToolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "referenceToolFullPath"_a);

    c12.def_static("SetKeyinToggleInstanceData", 
                   &UserInterfaceHelper::SetKeyinToggleInstanceData,
                   "instance"_a, "tooltip"_a, "keyin"_a, "iconName"_a, "toggleStateCriteria"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("SetKeyinToolInstanceData",
                   &UserInterfaceHelper::SetKeyinToolInstanceData,
                   "instance"_a, "tooltip"_a, "keyin"_a, "iconName"_a, "showHideCriteria"_a);

    c12.def_static("AddKeyinToolToToolBoxTree", [] (WCharCP toolName, ToolBoxNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib,
                                                    WCharCP toolTip, WCharCP keyin, WCharCP iconName, WCharCP showHideCriteria)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddKeyinToolToToolBoxTree(toolName, parentNode, sortValue_, virtualDgnlib, toolTip, keyin, iconName, showHideCriteria);
                   return py::make_tuple(retVal, sortValue_);
                   }, "toolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "tooltip"_a, "keyin"_a, "iconName"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("AddKeyinToggleToToolBoxTree", [] (WCharCP toolName, ToolBoxNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib,
                                                    WCharCP toolTip, WCharCP keyin, WCharCP iconName, WCharCP toggleStateCriteria, WCharCP showHideCriteria)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddKeyinToggleToToolBoxTree(toolName, parentNode, sortValue_, virtualDgnlib, toolTip, keyin, iconName, toggleStateCriteria, showHideCriteria);
                   return py::make_tuple(retVal, sortValue_);
                   }, "toolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "tooltip"_a, "keyin"_a, "iconName"_a, "toggleStateCriteria"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("AddKeyinToolToTaskTree", [] (WCharCP toolName, TaskNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib,
                                                      WCharCP toolTip, WCharCP keyin, WCharCP iconName, WCharCP showHideCriteria)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddKeyinToolToTaskTree(toolName, parentNode, sortValue_, virtualDgnlib, toolTip, keyin, iconName, showHideCriteria);
                   return py::make_tuple(retVal, sortValue_);
                   }, "toolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "tooltip"_a, "keyin"_a, "iconName"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("AddToolBoxContainer", [] (WCharCP toolName, ToolBoxNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib, WCharCP showHideCriteria)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddToolBoxContainer(toolName, parentNode, sortValue_, virtualDgnlib, showHideCriteria);
                   return py::make_tuple(retVal, sortValue_);
                   }, "toolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "showHideCriteria"_a = nullptr);

    c12.def_static("AddTaskContainer", [] (WCharCP toolName, TaskNodeP parentNode, int sortValue, XDataTreeOwnerR virtualDgnlib, WCharCP showHideCriteria, 
                                           bool showIcon, bool isWorkFlowNode, WCharCP iconName)
                   {
                   int sortValue_ {sortValue};
                   auto retVal = UserInterfaceHelper::AddTaskContainer(toolName, parentNode, sortValue_, virtualDgnlib, showHideCriteria, showIcon, isWorkFlowNode, iconName);
                   return py::make_tuple(retVal, sortValue_);
                   }, "toolName"_a, "parentNode"_a, "sortValue"_a, "virtualDgnlib"_a, "showHideCriteria"_a = nullptr, "showIcon"_a = true, 
                   "isWorkFlowMode"_a = false, "iconName"_a = nullptr);    
    }