/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\xdatatreeowner.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/XDataTreeOwner.h>



static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_GetConcreteObjectPointer =R"doc(Returns pointer to concrete object that can be stored in managed
object.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_GetStandaloneECEnabler =R"doc(Returns the StandaloneECEnabler that can be used to create IECInstance
to store on an XDataTreeNode.

:param fullSchemaName:
    Name of Schema that define the ECClass specified by className.

:param className:
    Name of class to be created by enabler.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_ContainsNodes =R"doc(Returns true if the XDataTree of the specified type contains
XDataTreeNodes.

:param hid:
    HandlerId of XDataTree type.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_GetNextAvailableName =R"doc(Returns the next available unique node name given a proposed name.

:param baseName:
    Proposed name for new node.

:param parentId:
    ElementId of parent node. Used to limit scope of unique name
    checking.

:param handlerId:
    HandlerId of XDataTree type.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_IsNodeElementReferenced =R"doc(Returns true if XDataTreeNode specified by the ElementId of its host
type 66 element is referenced by any elements in any loaded models.

:param nodeID:
    ElementId of host Type 66 element.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_SortNodesByName =R"doc(Sorts the XDataTreeNodes in a tree by name. Typically the nodes are
arranged by sort priority.

:param parentNodeID:
    ElementId of parent node, pass 0 to sort root level nodes.

:param hid:
    HandlerId of XDataTree type. Returns true if the nodes were
    sorted.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_CopyNodeFromFile =R"doc(Copy XDataTreeNode into this XDataTreeOwner.

:param sourceNode:
    XDataTreeNode to be copied. Returns a pointer to the copied node
    in XDataTreeOwner.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_AddNewNode =R"doc(Create a new node in the XDataTree owner which creates a new type 66
element to host the node data.

:param nodeToAdd:
    The XDataTreeNode to add to the owner.

:param seedInstanceContainer:
    If pointer to seed instance container is specified, the instances
    it contains are also written. Returns SUCCESS if successfull.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_FindNodeByPath =R"doc(Return a pointer to an existing XDataTreeNode.

:param locatePath:
    The path of the node to locate.

:param handlerId:
    The HandlerId of the type of XDataTree to search.

:param pathSeparator:
    The path separator character used in the locatePath. This defaults
    to " \\ ". Returns a valid ElementTemplateNodePtr if the template can
    be located.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_FindXDataTree =R"doc(Returns a pointer of XDataTree that holds XDataTreeNodes a specific
type.

:param handlerId:
    HandlerId of XDataTree type.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_GetXDataTree =R"doc(Returns a pointer of XDataTree that holds XDataTreeNodes a specific
type. This call will create the XDataTree if necessary.

:param handlerId:
    HandlerId of XDataTree type.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_FindByElementId =R"doc(Returns XDataTreeNode pointer using ElementId of host Type 66 element
and handlerId of XDataTree type.

:param elementID:
    ElementId of host Type 66 element.

:param handlerId:
    HandlerId of XDataTree type.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_IsReadOnly =R"doc(Returns true if the Owner is ReadOnly. WARNING:This may return false
for XDataTreeOwner associated with a read-only DgnFile!)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_DeleteNode =R"doc(Delete the specified node from the owner.

:param node:
    The cached XDataTreeNode to write.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_WriteXData =R"doc(Write the list of IECInstance held by the node to the owner which is
typically a DgnFile. The instances are stored as ECXAttribute data.

:param node:
    The cached XDataTreeNode to write.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_WriteHeader =R"doc(Write the node header data to the owner which is typically a DgnFile.
The header data consists of the node name, its parent, and sort
priority.

:param node:
    The cached XDataTreeNode to write.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_Write =R"doc(Write the node to the owner which is typically a DgnFile. This writes
both the node header data and the ECXAttribute instance data held by
the node.

:param node:
    The cached XDataTreeNode to write.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_GetLabel =R"doc(Return label of XDataTreeOwner which is typically used as a display
label in the UI used to display XDataTree data in edit dialogs.)doc";

static const char * __doc_Bentley_DgnPlatform_XDataTreeOwner_GetName =R"doc(Return name of XDataTreeOwner. This is commonly the owning Design File
name.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XDataTreeOwner(py::module_& m)
    {
    //===================================================================================
    // struct XDataTreeOwner
    py::class_< XDataTreeOwner, std::unique_ptr<XDataTreeOwner, py::nodelete> > c1(m, "XDataTreeOwner");

    c1.def_property_readonly("Name", &XDataTreeOwner::GetName);
    c1.def("GetName", &XDataTreeOwner::GetName, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetName));
    
    c1.def_property_readonly("Label", &XDataTreeOwner::GetLabel);
    c1.def("GetLabel", &XDataTreeOwner::GetLabel, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetLabel));
    
    c1.def("Write", &XDataTreeOwner::Write, "node"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, Write));
    c1.def("WriteHeader", &XDataTreeOwner::WriteHeader, "node"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, WriteHeader));
    c1.def("WriteXData", &XDataTreeOwner::WriteXData, "node"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, WriteXData));
    c1.def("DeleteNode", &XDataTreeOwner::DeleteNode, "node"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, DeleteNode));
    c1.def("IsReadOnly", &XDataTreeOwner::IsReadOnly, DOC(Bentley, DgnPlatform, XDataTreeOwner, IsReadOnly));
    
    c1.def_property_readonly("DgnFile", &XDataTreeOwner::GetFileP);
    c1.def("GetDgnFile", &XDataTreeOwner::GetFileP, py::return_value_policy::reference_internal);
    
    c1.def("FindByElementId", &XDataTreeOwner::FindByElementId, "elementId"_a, "handlerId"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, FindByElementId));
    c1.def("GetXDataTree", &XDataTreeOwner::GetXDataTree, "handlerId"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetXDataTree));
    c1.def("FindXDataTree", &XDataTreeOwner::FindXDataTree, "handlerId"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XDataTreeOwner, FindXDataTree));
    c1.def("FindNodeByPath", &XDataTreeOwner::FindNodeByPath, "locatePath"_a, "handlerId"_a, "pathSeparator"_a = L'\\', DOC(Bentley, DgnPlatform, XDataTreeOwner, FindNodeByPath));
    c1.def("AddNewNode", &XDataTreeOwner::AddNewNode, "nodeToAdd"_a, "seedInstances"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, AddNewNode));
    c1.def("CopyNodeFromFile", &XDataTreeOwner::CopyNodeFromFile, "sourceNode"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, CopyNodeFromFile));
    c1.def("SortNodesByName", &XDataTreeOwner::SortNodesByName, "parentNodeId"_a, "hid"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, SortNodesByName));
    c1.def("IsNodeElementReferenced", &XDataTreeOwner::IsNodeElementReferenced, "nodeId"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, IsNodeElementReferenced));

    c1.def("GetNextAvailableName", 
           py::overload_cast<WCharCP, ElementId, HandlerId>(&XDataTreeOwner::GetNextAvailableName), 
           "baseName"_a, "parentId"_a, "handlerId"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetNextAvailableName));

    c1.def("GetNextAvailableName",
           py::overload_cast<WCharCP, ElementId, HandlerId, bool>(&XDataTreeOwner::GetNextAvailableName),
           "baseName"_a, "parentId"_a, "handlerId"_a, "forCopy"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetNextAvailableName));

    c1.def("ContainsNodes", &XDataTreeOwner::ContainsNodes, "hid"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, ContainsNodes));
    c1.def("GetStandaloneECEnabler", &XDataTreeOwner::GetStandaloneECEnabler, "fullSchemaName"_a, "className"_a, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetStandaloneECEnabler));
    c1.def_property_readonly("ConcreteObjectPointer", &XDataTreeOwner::GetConcreteObjectPointer);
    c1.def("GetConcreteObjectPointer", &XDataTreeOwner::GetConcreteObjectPointer, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XDataTreeOwner, GetConcreteObjectPointer));
    }