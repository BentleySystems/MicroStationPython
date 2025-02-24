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
void def_SelectionSetManager(py::module_&);
void def_LocateSubEntityTool(py::module_&);

void def_IModifyElement(py::module_&);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyDgnView, m)
    {
    // Document for module
    m.doc() = "The MSPyDgnView library, provides the framework for locating, selecting and manipulating geometry in a DesignFile using a the concept of a Tool.";

    //From DgnPlatform
    def_IModifyElement(m);

    // class defines
    bind_container_PyDgnView(m);
    def_AccuDraw(m);
    def_AccuSnap(m);
    def_DgnTool(m);
    def_IRedraw(m);
    def_DgnElementSetTool(m);
    def_DgnRegionElementTool(m);    
    def_FenceManager(m);    
    def_SelectionSetManager(m);
    def_LocateSubEntityTool(m);
    }