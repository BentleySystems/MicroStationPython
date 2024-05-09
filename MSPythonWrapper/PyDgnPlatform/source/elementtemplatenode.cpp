/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\elementtemplatenode.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ElementTemplateNode.h>



static const char * __doc_Bentley_DgnPlatform_ElementTemplateNode_GetNodeHandlerId =R"doc(Return the HandlerId used to designate an element as an
ElementTemplate Node.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateNode_GetOrCreateDefaultInstance =R"doc(Return the " default " IECInstance used to store symbology paraemeters
in Element Templates. It is possible for an element template to hold
instance data for other applications. The default instance holds the
symbology parameters used by MicroStation and its derivatives. This
method with create an instance so it can be populated if one does not
exist.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateNode_GetDefaultInstance =R"doc(Return the " default " IECInstance used to store symbology paraemeters
in Element Templates. It is possible for an element template to hold
instance data for other applications. The default instance holds the
symbology parameters used by MicroStation and its derivatives.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateNode_CreateNode =R"doc(Create and return a pointer to an ElementTemplateNode.)doc";

static const char * __doc_Bentley_DgnPlatform_ElementTemplateNode_FindByElementId =R"doc(Return a pointer to an ElementTemplateNode for an existing element.

Parameter ``elemID``:
    The ElementId of the Type 66 element that holds the element
    template XAttribute data.

Parameter ``owner``:
    The owner of the node. The owner can be determined by the
    DgnFileP. See XDataTreeManager::GetDgnXDataTreeOwner.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ElementTemplateNode(py::module_& m)
    {
    //===================================================================================
    // struct ElementTemplateNode
    py::class_< ElementTemplateNode, ElementTemplateNodePtr, XDataTreeNode> c1(m, "ElementTemplateNode");

    c1.def_static("FindByElementId", &ElementTemplateNode::FindByElementId, "elemId"_a, "owner"_a, DOC(Bentley, DgnPlatform, ElementTemplateNode, FindByElementId));

    c1.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementId, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ElementTemplateNode::CreateNode),
                  "name"_a, "parentId"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr, DOC(Bentley, DgnPlatform, ElementTemplateNode, CreateNode));

    c1.def_static("CreateNode",
                  py::overload_cast<WCharCP, ElementTemplateNodeP, bool, int, XDataTreeOwner&, XInstanceContainer*>(&ElementTemplateNode::CreateNode),
                  "name"_a, "parentNode"_a, "allowChildNodes"_a, "sortPriority"_a, "owner"_a, "seedContainer"_a = nullptr, DOC(Bentley, DgnPlatform, ElementTemplateNode, CreateNode));

    c1.def_static("FromXDataTreeNode", &ElementTemplateNode::FromXDataTreeNodePtr, "xDataTreeNode"_a);
    
    c1.def_property_readonly("DefaultInstance", &ElementTemplateNode::GetDefaultInstance);
    c1.def("GetDefaultInstance", &ElementTemplateNode::GetDefaultInstance, DOC(Bentley, DgnPlatform, ElementTemplateNode, GetDefaultInstance));

    c1.def("GetOrCreateDefaultInstance", &ElementTemplateNode::GetOrCreateDefaultInstance, DOC(Bentley, DgnPlatform, ElementTemplateNode, GetOrCreateDefaultInstance));
    c1.def_static("GetNodeHandlerId", &ElementTemplateNode::GetNodeHandlerId, DOC(Bentley, DgnPlatform, ElementTemplateNode, GetNodeHandlerId));
    }