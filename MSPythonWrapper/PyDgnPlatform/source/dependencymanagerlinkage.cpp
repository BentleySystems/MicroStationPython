/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dependencymanagerlinkage.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DependencyManagerLinkage.h>



/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DependencyManagerLinkage(py::module_& m)
    {
    //===================================================================================
    // struct DependencyRoot
    py::class_< DependencyRoot> c1(m, "DependencyRoot");
    py::bind_vector< bvector<DependencyRoot> >(m, "DependencyRootArray", py::module_local(false));

    c1.def_readwrite("elementId", &DependencyRoot::elemid);
    c1.def_readwrite("refAttId", &DependencyRoot::refattid);

    c1.def_property("elementRef",
                    [] (DependencyRoot const& self) { return self.ref; },
                    py::cpp_function([] (DependencyRoot& self, ElementRefP newRef) { self.ref = newRef; }, py::keep_alive<1, 2>()));

    c1.def_readwrite("refTransform", &DependencyRoot::refTransform);
    }