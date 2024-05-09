/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\PyDgnView.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* STL-liked container instantiation.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void bind_container_PyDgnView(py::module_& m)
    {
    // bvector instantiation    
    }

/*---------------------------------------------------------------------------------**//**
* Forward declarations for class definition generators.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_AccuDraw(py::module_&);
void def_AccuSnap(py::module_&);
void def_DgnElementSetTool(py::module_&);
void def_DgnRegionElementTool(py::module_&);
void def_DgnTool(py::module_&);
void def_FenceManager(py::module_&);
void def_IRedraw(py::module_&);
void def_IViewManager(py::module_&);
void def_SelectionSetManager(py::module_&);
void def_LocateSubEntityTool(py::module_&);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyDgnView, m)
    {
    // Document for module
    m.doc() = "Pybind11 wrapper for DgnView.dll";

    // class defines
    bind_container_PyDgnView(m);
    def_AccuDraw(m);
    def_AccuSnap(m);
    def_DgnTool(m);
    def_IRedraw(m);
    def_DgnElementSetTool(m);
    def_DgnRegionElementTool(m);    
    def_FenceManager(m);    
    def_IViewManager(m);
    def_SelectionSetManager(m);
    def_LocateSubEntityTool(m);
    }