/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\xdatatreenode.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/XDataTreeNode.h>



static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_Create =R"doc(Create and return a new XDataTreeNode.

Parameter ``name``:
    The name of the new node.

Parameter ``sortPriority``:
    The sortPriority of the new node. If -1 if passed in the next
    available value is used.

Parameter ``allowChildNodes``:
    Boolean the specifies if this node should allow children.

Parameter ``parentNodeP``:
    Pointer to the parent node or NULL if root node.

Parameter ``owner``:
    The owner of the node. The owner can be determined by the
    DgnFileP. See XDataTreeManager::GetDgnXDataTreeOwner.

Parameter ``handlerId``:
    The HandlerId that specifies the XDataTree type.

Parameter ``seedInstances``:
    Pointer to a seed container of IECInstances.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetECInstanceByClassName =R"doc(Return a pointer to an IECIntance that is held in the node
XInstanceContainer.

Parameter ``className``:
    The class name to compare. This assumes that the
    XInstanceContainer only contains a single instance from a
    particular class.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetECInstanceBySchemaName =R"doc(Return a pointer to an IECIntance that is held in the node
XInstanceContainer.

Parameter ``fullSchemaName``:
    The schema name to compare. This assumes that the
    XInstanceContainer only contains a single instance from a
    particular schema.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_FindByElementId =R"doc(Return a reference counted pointer to an XDataTreeNode.

Parameter ``elemID``:
    The ElementId of the Type 66 element that holds the element
    template XAttribute data.

Parameter ``handlerId``:
    The HandlerId that specifies the XDataTree type to search.

Parameter ``owner``:
    The owner of the node. The owner can be determined by the
    DgnFileP. See XDataTreeManager::GetDgnXDataTreeOwner.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_ReloadXAttributeData =R"doc(Reload the XAttribute data which holds the node name, sort priority,
and parent node specification. This call can be used to clear any
XAttribute changes before they are written to the file. @Return
SUCCESS if the XAttribute data was successfully reloaded.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_ClearCachedInstances =R"doc(Clear the cached instances held by the XInstanceContainer. Subsequent
node request for data will then reload the data from the type 66
elements in the DgnFile. This call can be used to clear any
IECInstance changes before they are written to the file.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetOwner =R"doc(Return the XDataTreeOwner that hold the XDataTree that contains the
XDataTree node.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetXInstanceContainer =R"doc(Return a pointer to the XInstanceContainer that holds a list of
ECXAInstance associated with the node. A NULL will be return if no
instances are held by the node.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetHandlerId =R"doc(Return the HandlerId for the node. This is use to determine the type
of data the node contains, such as Element Template, Task, NamedTools,
Detailing Symbol Styles, etc.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_Write =R"doc(Write any node changes to the owner, which is typically a DgnFile.
@Return SUCCESS if the node is successfully written.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetElementRef =R"doc(Return the ElementRef of the Type 66 element that serves as a host for
the node.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetId =R"doc(Return the ElementId of the Type 66 element that serves as a host for
the node.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_SetSortPriority =R"doc(Set the Sort Priority which is used to determine the position of the
node under its parent node.

Parameter ``sortPriority``:
    The new priority value.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetSortPriority =R"doc(Return the Sort Priority which is used to determine the postion of the
node under its parent node.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetParentId =R"doc(Return the ElementId of the parent node. If the node is a root node a
value of 0 is returned.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_AllowChildNodes =R"doc(Return true if node is allowed to have child nodes.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_SetName =R"doc(Set the name of the XDataTreeNode. The node must be written to persist
the change.

Parameter ``name``:
    The new name for the node.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_GetFullPath =R"doc(Return the full heirarchial path to the XDataTreeNode.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_SortChildren =R"doc(Sort all children of this node if this node contains child nodes.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeNode_SortParent =R"doc(Sort all children of the parent of this node)doc";

static const char * __doc_Bentley_DgnPlatform_NameTreeNode_CreateRootNode =R"doc(Create the root node for a NameTree. @Return a RefCounted pointer to
the created node.)doc";

static const char * __doc_Bentley_DgnPlatform_NameTreeNode_AddChild =R"doc(Add a new child node a return pointer to it.

Parameter ``name``:
    The name of the child node to create.

Parameter ``id``:
    The ElementId of the child node. @Return a RefCounted pointer to
    the created node.)doc";

static const char * __doc_Bentley_DgnPlatform_NameTreeNode_LocateChild =R"doc(Return a child node with a specific name.

Parameter ``name``:
    The name of the child node to locate.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XDataTreeNode(py::module_& m)
    {
    //===================================================================================
    // struct NameTreeNode
    py::class_< NameTreeNode, NameTreeNodePtr> c1(m, "NameTreeNode");

    c1.def("LocateChild", &NameTreeNode::LocateChild, "name"_a, DOC(Bentley, DgnPlatform, NameTreeNode, LocateChild));
    c1.def("AddChild", &NameTreeNode::AddChild, "name"_a, "id"_a = 0, DOC(Bentley, DgnPlatform, NameTreeNode, AddChild));
    c1.def_static("CreateRootNode", &NameTreeNode::CreateRootNode, DOC(Bentley, DgnPlatform, NameTreeNode, CreateRootNode));

    //===================================================================================
    // struct XDataTreeNode
    py::class_< XDataTreeNode, XDataTreeNodePtr> c2(m, "XDataTreeNode");

    c2.def("SortParent", &XDataTreeNode::SortParent, DOC(Bentley, DgnPlatform, XDataTreeNode, SortParent));
    c2.def("SortChildren", &XDataTreeNode::SortChildren, DOC(Bentley, DgnPlatform, XDataTreeNode, SortChildren));

    c2.def_property_readonly("FullPath", &XDataTreeNode::GetFullPath);
    c2.def("GetFullPath", &XDataTreeNode::GetFullPath, DOC(Bentley, DgnPlatform, XDataTreeNode, GetFullPath));

    c2.def_property("Name", &XDataTreeNode::GetNameCP, &XDataTreeNode::SetName);
    c2.def("GetName", &XDataTreeNode::GetNameCP, py::return_value_policy::reference_internal);
    c2.def("SetName", &XDataTreeNode::SetName, "name"_a, DOC(Bentley, DgnPlatform, XDataTreeNode, SetName));
    
    c2.def("AllowChildNodes", &XDataTreeNode::AllowChildNodes, DOC(Bentley, DgnPlatform, XDataTreeNode, AllowChildNodes));
    
    c2.def_property_readonly("ParentId", &XDataTreeNode::GetParentId);
    c2.def("GetParentId", &XDataTreeNode::GetParentId, DOC(Bentley, DgnPlatform, XDataTreeNode, GetParentId));
    
    c2.def_property("SortPriority", &XDataTreeNode::GetSortPriority, &XDataTreeNode::SetSortPriority);
    c2.def("GetSortPriority", &XDataTreeNode::GetSortPriority, DOC(Bentley, DgnPlatform, XDataTreeNode, GetSortPriority));
    c2.def("SetSortPriority", &XDataTreeNode::SetSortPriority, "priority"_a, DOC(Bentley, DgnPlatform, XDataTreeNode, SetSortPriority));
    
    c2.def_property_readonly("Id", &XDataTreeNode::GetId);
    c2.def("GetId", &XDataTreeNode::GetId, DOC(Bentley, DgnPlatform, XDataTreeNode, GetId));
    
    c2.def_property_readonly("ElementRef", &XDataTreeNode::GetElementRef);
    c2.def("GetElementRef", &XDataTreeNode::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XDataTreeNode, GetElementRef));
    
    c2.def("Write", &XDataTreeNode::Write, DOC(Bentley, DgnPlatform, XDataTreeNode, Write));
    
    c2.def_property_readonly("HandlerId", &XDataTreeNode::GetHandlerId);
    c2.def("GetHandlerId", &XDataTreeNode::GetHandlerId, DOC(Bentley, DgnPlatform, XDataTreeNode, GetHandlerId));
    
    c2.def_property_readonly("XInstanceContainer", py::overload_cast<>(&XDataTreeNode::GetXInstanceContainer));
    c2.def("GetXInstanceContainer", py::overload_cast<>(&XDataTreeNode::GetXInstanceContainer), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XDataTreeNode, GetXInstanceContainer));
    
    c2.def_property_readonly("Owner", &XDataTreeNode::GetOwner);
    c2.def("GetOwner", &XDataTreeNode::GetOwner, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XDataTreeNode, GetOwner));
    
    c2.def("ClearCachedInstances", &XDataTreeNode::ClearCachedInstances, DOC(Bentley, DgnPlatform, XDataTreeNode, ClearCachedInstances));
    c2.def("ReloadXAttributeData", &XDataTreeNode::ReloadXAttributeData, DOC(Bentley, DgnPlatform, XDataTreeNode, ReloadXAttributeData));
    c2.def_static("FindByElementId", &XDataTreeNode::FindByElementId, "elemId"_a, "handlerId"_a, "owner"_a, DOC(Bentley, DgnPlatform, XDataTreeNode, FindByElementId));
    
    c2.def_property_readonly("PathSeparator", &XDataTreeNode::GetPathSeparatorCP);
    c2.def("GetPathSeparator", &XDataTreeNode::GetPathSeparatorCP, py::return_value_policy::reference_internal);
    
    c2.def("GetECInstanceBySchemaName", &XDataTreeNode::GetECInstanceBySchemaName, "fullSchemaName"_a, DOC(Bentley, DgnPlatform, XDataTreeNode, GetECInstanceBySchemaName));
    c2.def("GetECInstanceByClassName", &XDataTreeNode::GetECInstanceByClassName, "className"_a, DOC(Bentley, DgnPlatform, XDataTreeNode, GetECInstanceByClassName));
    c2.def_static("Create", &XDataTreeNode::Create, "name"_a, "sortPriority"_a, "allowChildNodes"_a, "parentNode"_a, "owner"_a, "handlerId"_a, "seedInstances"_a, DOC(Bentley, DgnPlatform, XDataTreeNode, Create));
    }