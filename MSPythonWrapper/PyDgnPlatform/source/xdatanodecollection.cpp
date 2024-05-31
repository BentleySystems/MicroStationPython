/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\xdatanodecollection.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/XDataNodeCollection.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XDataNodeCollection(py::module_& m)
    {
    //===================================================================================
    // struct XDataNodeCollection
    py::class_< XDataNodeCollection> c1(m, "XDataNodeCollection");

    c1.def(py::init<XDataTreeOwnerR, HandlerId>(), "treeOwner"_a, "hid"_a);
    c1.def(py::init<XDataTreeNodeR>(), "parentNode"_a);
    c1.def(py::init<XDataTreeOwnerR, ElementId, HandlerId>(), "treeOwner"_a, "parentId"_a, "hid"_a);
    c1.def("__iter__", [] (XDataNodeCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c1.def("GetNodeAtIndex", &XDataNodeCollection::GetNodeAtIndex, "index"_a);
    c1.def("GetFirstNodeWithName", &XDataNodeCollection::GetFirstNodeWithName, "name"_a);
    c1.def("GetNumNodes", &XDataNodeCollection::GetNumNodes, "incudeChildren"_a = false);
    c1.def("Sort", &XDataNodeCollection::Sort);
    c1.def("SortByName", &XDataNodeCollection::SortByName);
    c1.def("IsValid", &XDataNodeCollection::IsValid);
    }