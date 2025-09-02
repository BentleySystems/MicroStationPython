/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnlinktree.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnLinkTree.h>

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetLastModifiedTime =R"doc(returned as unix millis)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_FindNodeById =R"doc(Find a node at the given index by recursively traversing the tree's
nodes)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetTreeId =R"doc(Get this tree's index (count) on the hosted element)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_SetBookmarkProviderNode =R"doc(If this tree is of type DgnLinkTreeKey::Bookmarks, then set the leaf
node that generated it)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetBookmarkProviderNode =R"doc(If this tree is of type DgnLinkTreeKey::Bookmarks, then find the leaf
node that generated it)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_FindNode =R"doc(Find the node at the given path)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_SetRoot =R"doc(Set the root node of this tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetRoot =R"doc(Get the root node of this tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_TransformTo =R"doc(Transform this tree's file path relative to the file pointed by the
given moniker)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetFilePath =R"doc(Get the path of the file that hosts this tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetTreeSpec =R"doc(Get DgnLinkTreeSpec that describes this tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTree_GetName =R"doc(Get name of the tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_Compare =R"doc(Compare this with the data stored by the given DgnLinkTreeSpec)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_GetElementId =R"doc(Get the element id that hosts the DgnLinkTree described by this
DgnLinkTreeSpec. This is valid only for trees of type
DgnLinkTreeKey::Annotation.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_GetModelName =R"doc(Get the model name of DgnLinkTree described by this DgnLinkTreeSpec.
This is valid only for trees of type DgnLinkTreeKey::Annotation.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_GetDocumentMoniker =R"doc(Get the file location moniker of DgnLinkTree described by this
DgnLinkTreeSpec)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_GetFilePath =R"doc(Get the file location of DgnLinkTree described by this DgnLinkTreeSpec)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_GetTreeName =R"doc(Get the name of DgnLinkTree described by this DgnLinkTreeSpec)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeSpec_GetTypeKey =R"doc(Get the type of DgnLinkTree described by this DgnLinkTreeSpec)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeLeaf_GetSequenceNumber =R"doc(Find the child index number of this leaf among its parent's child
nodes)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeLeaf_GetHandler =R"doc(Get the handler object that handles the link associated with this leaf)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_DeepCopy =R"doc(Recursively copy this branch and all its child nodes into a new tree
of the given tree spec)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_GetUniqueChildName =R"doc(Prepare a unique name for a new child by comparing with all child
nodes)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_DropChild =R"doc(Remove the child node at the given index)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_AddChild =R"doc(Add a new child node at the given index)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_FindChildIndex =R"doc(Find the index of the child node of the given name)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_FindChildNode =R"doc(Find the (nested) child node from the given path)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_GetChildCount =R"doc(Get the number of immediate child nodes of this branch)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeBranch_GetHandler =R"doc(Get the handler for this DgnLinkTree's type of linkset)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetNodeId =R"doc(Get a unique identifier for this node within its tree)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetUserDataList =R"doc(Get the user data collection)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_RemoveUserData =R"doc(Remove the user data from the node)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_AddUserData =R"doc(Add the user data to the node)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetUserData =R"doc(Get the user data for given appID and subID stored at given index)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetUserDataCount =R"doc(Get the user data count)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_ClearDirtyFlag =R"doc(Clear the dirty flag. It denotes that all changes to the node are
processed.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_SetDirtyFlag =R"doc(Change the state of the node to dirty. It denotes that the node has
changed.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_IsDirty =R"doc(Check if the node has changed since it was last saved.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetHandlerKey =R"doc(Get the link handler key. The link handler key is associated with the)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetHybridPathName =R"doc(Get the path to the current node in the current link tree. Also
include the parent tree path if this is a bookmark tree.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetPathName =R"doc(Get the path in the current link tree.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_GetName =R"doc(Get the name of this node.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_SetName =R"doc(Set the name of the node)doc";

static const char * __doc_Bentley_DgnPlatform_DgnLinkTreeNode_Copy =R"doc(Copy the node to given link tree specification)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnLinkTree(py::module_& m)
    {
    //===================================================================================
    // enum class DgnLinkTreeKey
    py::enum_< DgnLinkTreeKey>(m, "DgnLinkTreeKey")
        .value("eInvalid", DgnLinkTreeKey::Invalid)
        .value("eProject", DgnLinkTreeKey::Project)
        .value("eBookmarks", DgnLinkTreeKey::Bookmarks)
        .value("eAnnotation", DgnLinkTreeKey::Annotation)
        .value("eSheetIndex", DgnLinkTreeKey::SheetIndex)
        .export_values();

    //===================================================================================
    // enum class DgnLinkAddChildStatus
    py::enum_< DgnLinkAddChildStatus>(m, "DgnLinkAddChildStatus")
        .value("eSuccess", DgnLinkAddChildStatus::Success)
        .value("eGeneralError", DgnLinkAddChildStatus::GeneralError)
        .value("eDuplicateChild", DgnLinkAddChildStatus::DuplicateChild)
        .export_values();

    //===================================================================================
    // struct DgnLinkUserDataList
    py::class_< DgnLinkUserDataList> c1(m, "DgnLinkUserDataList");

    c1.def(py::init<DgnLinkUserDataList const&>(), "list"_a);
    c1.def("__iter__", [] (DgnLinkUserDataList& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct DgnLinkTreeNode
    py::class_< DgnLinkTreeNode, TempObjectOwner<DgnLinkTreeNode> > c2(m, "DgnLinkTreeNode");

    c2.def("Copy", &DgnLinkTreeNode::Copy, "treeSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, Copy));
    c2.def("SetName", &DgnLinkTreeNode::SetName, "name"_a, "checkDuplicateNames"_a = true, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, SetName));
    
    c2.def_property_readonly("Name", &DgnLinkTreeNode::GetName);
    c2.def("GetName", &DgnLinkTreeNode::GetName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetName));
    
    c2.def_property_readonly("PathName", &DgnLinkTreeNode::GetPathName);
    c2.def("GetPathName", &DgnLinkTreeNode::GetPathName, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetPathName));
    
    c2.def("GetHybridPathName", &DgnLinkTreeNode::GetHybridPathName, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetHybridPathName));
    
    c2.def_property_readonly("HandlerKey", &DgnLinkTreeNode::GetHandlerKey);
    c2.def("GetHandlerKey", &DgnLinkTreeNode::GetHandlerKey, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetHandlerKey));
    
    c2.def_property_readonly("Tree", [] (DgnLinkTreeNodeR self) { return DgnLinkTreePtr(self.GetTreeP()); });
    c2.def("GetTree", [] (DgnLinkTreeNodeR self) { return DgnLinkTreePtr(self.GetTreeP()); });
    
    c2.def_property_readonly("Parent", &DgnLinkTreeNode::GetParentP);
    c2.def("GetParent", &DgnLinkTreeNode::GetParentP, py::return_value_policy::reference_internal);
    
    c2.def("IsDirty", &DgnLinkTreeNode::IsDirty, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, IsDirty));    
    c2.def("SetDirtyFlag", &DgnLinkTreeNode::SetDirtyFlag, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, SetDirtyFlag));
    c2.def("ClearDirtyFlag", &DgnLinkTreeNode::ClearDirtyFlag, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, ClearDirtyFlag));
    c2.def("GetUserDataCount",
        [](DgnLinkTreeNodeR self, boost::optional<UInt32> appID, boost::optional<UInt32> subID)
        {
            return self.GetUserDataCount(appID.get_ptr(), subID.get_ptr());
        },
        "appId"_a, "subId"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetUserDataCount));
    c2.def("GetUserData",
        [](DgnLinkTreeNodeR self, boost::optional<UInt32> appID, boost::optional<UInt32> subID, UInt32 index)
        {
            return self.GetUserData(appID.get_ptr(), subID.get_ptr(), index);
        }, 
        "appId"_a, "subId"_a, "index"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetUserData));
    c2.def("AddUserData", &DgnLinkTreeNode::AddUserData, "userData"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, AddUserData));
    c2.def("RemoveUserData", &DgnLinkTreeNode::RemoveUserData, "userData"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, RemoveUserData));
    
    c2.def_property_readonly("UserDataList", &DgnLinkTreeNode::GetUserDataList);
    c2.def("GetUserDataList", &DgnLinkTreeNode::GetUserDataList, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetUserDataList));
    
    c2.def_property_readonly("NodeId", &DgnLinkTreeNode::GetNodeId);
    c2.def("GetNodeId", &DgnLinkTreeNode::GetNodeId, DOC(Bentley, DgnPlatform, DgnLinkTreeNode, GetNodeId));
    
    c2.def("AsDgnLinkTreeBranch", &DgnLinkTreeNode::AsDgnLinkTreeBranchP, py::return_value_policy::reference_internal);
    c2.def("AsDgnLinkTreeLeaf", &DgnLinkTreeNode::AsDgnLinkTreeLeafP, py::return_value_policy::reference_internal);

    //===================================================================================
    // struct DgnLinkTreeLeaf
    py::class_< DgnLinkTreeLeaf, TempObjectOwner<DgnLinkTreeLeaf>, DgnLinkTreeNode> c4(m, "DgnLinkTreeLeaf");
    c4.def_property_readonly("Handler", &DgnLinkTreeLeaf::GetHandler);
    c4.def("GetHandler", &DgnLinkTreeLeaf::GetHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTreeLeaf, GetHandler));

    c4.def_property_readonly("Link", &DgnLinkTreeLeaf::GetLinkP);
    c4.def("GetLink", &DgnLinkTreeLeaf::GetLinkP, py::return_value_policy::reference_internal);

    c4.def_property("ValidFlags", &DgnLinkTreeLeaf::GetValidFlag, &DgnLinkTreeLeaf::SetValidFlag);
    c4.def("GetValidFlags", &DgnLinkTreeLeaf::GetValidFlag);
    c4.def("SetValidFlags", &DgnLinkTreeLeaf::SetValidFlag, "flag"_a);

    c4.def_property_readonly("SequenceNumber", &DgnLinkTreeLeaf::GetSequenceNumber);
    c4.def("GetSequenceNumber", &DgnLinkTreeLeaf::GetSequenceNumber, DOC(Bentley, DgnPlatform, DgnLinkTreeLeaf, GetSequenceNumber));

    //===================================================================================
    // struct DgnLinkTreeBranch
    py::class_< DgnLinkTreeBranch, TempObjectOwner<DgnLinkTreeBranch>, DgnLinkTreeNode> c3(m, "DgnLinkTreeBranch");

    c3.def_property_readonly("Handler", &DgnLinkTreeBranch::GetHandler);
    c3.def("GetHandler", &DgnLinkTreeBranch::GetHandler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, GetHandler));

    c3.def_property_readonly("LinkSet", [] (DgnLinkTreeBranch& self) { return DgnLinkSetPtr(self.GetLinkSetP()); });
    c3.def("GetLinkSet", [] (DgnLinkTreeBranch& self) { return DgnLinkSetPtr(self.GetLinkSetP()); });

    c3.def_property_readonly("ChildCount", &DgnLinkTreeBranch::GetChildCount);
    c3.def("GetChildCount", &DgnLinkTreeBranch::GetChildCount, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, GetChildCount));

    c3.def("GetChild", &DgnLinkTreeBranch::GetChildP, "iChild"_a, py::return_value_policy::reference_internal);
    c3.def("FindChildNode", py::overload_cast<WCharCP, bool>(&DgnLinkTreeBranch::FindChildNode), "path"_a, "searchProxyTrees"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, FindChildNode));

    c3.def("FindChildIndex", [] (DgnLinkTreeBranchCR self, WCharCP name)
           {
           size_t iIndex;
           auto retVal = self.FindChildIndex(name, iIndex);
           return std::make_pair(retVal, iIndex);
           }, "name"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, FindChildIndex));

    c3.def("FindChildIndex", py::overload_cast<DgnLinkTreeNodeCR>(&DgnLinkTreeBranch::FindChildIndex, py::const_), "child"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, FindChildIndex));
    c3.def("AddChild", &DgnLinkTreeBranch::AddChild, "newNode"_a, "index"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, AddChild));
    c3.def("DropChild", &DgnLinkTreeBranch::DropChild, "iChild"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, DropChild));
    c3.def("GetUniqueChildName", &DgnLinkTreeBranch::GetUniqueChildName, "namePrefix"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, GetUniqueChildName));
    c3.def("DeepCopy", &DgnLinkTreeBranch::DeepCopy, "treeSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeBranch, DeepCopy));

    //===================================================================================
    // struct DgnLinkTreeSpec
    py::class_< DgnLinkTreeSpec, DgnLinkTreeSpecPtr> c5(m, "DgnLinkTreeSpec");
    py::bind_vector<bvector< DgnLinkTreeSpecPtr>>(m, "DgnLinkTreeSpecPtrArray", py::module_local(false));

    c5.def_property_readonly("TypeKey", &DgnLinkTreeSpec::GetTypeKey);
    c5.def("GetTypeKey", &DgnLinkTreeSpec::GetTypeKey, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, GetTypeKey));
    
    c5.def_property_readonly("TreeName", &DgnLinkTreeSpec::GetTreeName);
    c5.def("GetTreeName", &DgnLinkTreeSpec::GetTreeName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, GetTreeName));
    
    c5.def_property_readonly("FilePath", &DgnLinkTreeSpec::GetFilePath);
    c5.def("GetFilePath", &DgnLinkTreeSpec::GetFilePath, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, GetFilePath));
    
    c5.def_property_readonly("DocumentMoniker", &DgnLinkTreeSpec::GetDocumentMonikerPtr);
    c5.def("GetDocumentMoniker", &DgnLinkTreeSpec::GetDocumentMonikerPtr, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, GetDocumentMoniker));
    
    c5.def_property_readonly("ModelName", &DgnLinkTreeSpec::GetModelName);
    c5.def("GetModelName", &DgnLinkTreeSpec::GetModelName, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, GetModelName));
    
    c5.def_property_readonly("ElementId", &DgnLinkTreeSpec::GetElementId);
    c5.def("GetElementId", &DgnLinkTreeSpec::GetElementId, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, GetElementId));
    
    c5.def("Compare", &DgnLinkTreeSpec::Compare, "otherSpec"_a, DOC(Bentley, DgnPlatform, DgnLinkTreeSpec, Compare));

    //===================================================================================
    // struct DgnLinkTree
    py::class_< DgnLinkTree, DgnLinkTreePtr> c6(m, "DgnLinkTree");

    c6.def(py::init(&DgnLinkTree::Create), "root"_a, "ownerMoniker"_a, "provider"_a);
    
    c6.def_property_readonly("Name", &DgnLinkTree::GetName);
    c6.def("GetName", &DgnLinkTree::GetName, DOC(Bentley, DgnPlatform, DgnLinkTree, GetName));
    
    c6.def_property_readonly("TreeSpec", &DgnLinkTree::GetTreeSpecPtr);
    c6.def("GetTreeSpec", &DgnLinkTree::GetTreeSpecPtr, DOC(Bentley, DgnPlatform, DgnLinkTree, GetTreeSpec));
    
    c6.def_property_readonly("FilePath", &DgnLinkTree::GetFilePath);
    c6.def("GetFilePath", &DgnLinkTree::GetFilePath, DOC(Bentley, DgnPlatform, DgnLinkTree, GetFilePath));
    
    c6.def("TransformTo", &DgnLinkTree::TransformTo, "dest"_a, DOC(Bentley, DgnPlatform, DgnLinkTree, TransformTo));
    
    c6.def_property("Root", &DgnLinkTree::GetRootR, py::cpp_function(&DgnLinkTree::SetRoot, py::keep_alive<1, 2>()));
    c6.def("GetRoot", &DgnLinkTree::GetRootR, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTree, GetRoot));
    c6.def("SetRoot", &DgnLinkTree::SetRoot, "root"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnLinkTree, SetRoot));

    c6.def("FindNode", [] (DgnLinkTree& self, WCharCP path, bool searchBookmarkTree)
           {
           return std::unique_ptr< DgnLinkTreeNode, py::nodelete>(self.FindNode(path, searchBookmarkTree));
           }, "path"_a, "searchBookmarkTree"_a, DOC(Bentley, DgnPlatform, DgnLinkTree, FindNode));
    
    c6.def_property("BookmarkProviderNode", &DgnLinkTree::GetBookmarkProviderNode, py::cpp_function(&DgnLinkTree::SetBookmarkProviderNode, py::keep_alive<1, 2>()));
    c6.def("GetBookmarkProviderNode", &DgnLinkTree::GetBookmarkProviderNode, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnLinkTree, GetBookmarkProviderNode));
    c6.def("SetBookmarkProviderNode", &DgnLinkTree::SetBookmarkProviderNode, "providerNode"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnLinkTree, SetBookmarkProviderNode));

    c6.def_property_readonly("TreeId", &DgnLinkTree::GetTreeId);
    c6.def("GetTreeId", &DgnLinkTree::GetTreeId, DOC(Bentley, DgnPlatform, DgnLinkTree, GetTreeId));
    
    c6.def("FindNodeById", [] (DgnLinkTree& self, UInt32 nodeId)
           {
           return std::unique_ptr< DgnLinkTreeNode, py::nodelete>(self.FindNodeById(nodeId));
           }, "nodeId"_a, DOC(Bentley, DgnPlatform, DgnLinkTree, FindNodeById));

    c6.def_property_readonly("LastModifiedTime", &DgnLinkTree::GetLastModifiedTime);
    c6.def("GetLastModifiedTime", &DgnLinkTree::GetLastModifiedTime, DOC(Bentley, DgnPlatform, DgnLinkTree, GetLastModifiedTime));
    }
