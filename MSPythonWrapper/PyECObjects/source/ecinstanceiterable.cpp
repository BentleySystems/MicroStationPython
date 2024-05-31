/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\ecinstanceiterable.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECObjects/ECInstanceIterable.h>

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECInstanceIterable(py::module_& m)
    {
    //===================================================================================
    // struct ECInstanceIterable
    py::class_< ECInstanceIterable> c1(m, "ECInstanceIterable");

    c1.def(py::init<>());
    c1.def("__bool__", [] (ECInstanceIterable& self) { return !self.empty(); });
    c1.def("__iter__", [] (ECInstanceIterable& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct ECRelationshipIterable
    py::class_< ECRelationshipIterable> c2(m, "ECRelationshipIterable");

    c2.def(py::init<>());
    c2.def("__bool__", [] (ECRelationshipIterable& self) { return !self.empty(); });
    c2.def("__iter__", [] (ECRelationshipIterable& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());    
    }