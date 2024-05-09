/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\PyECObjects.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

/*---------------------------------------------------------------------------------**//**
* STL-liked container instantiation.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void bind_container_PyEC(py::module_& m)
    {
    // bvector instantiation    
    }

/*---------------------------------------------------------------------------------**//**
* Forward declarations for class definition generators.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ECContext(py::module_&);
void def_ECDBuffer(py::module_&);
void def_ECEnabler(py::module_&);
void def_ECExpressions(py::module_&);
void def_ECInstance(py::module_&);
void def_ECInstanceIterable(py::module_&);
void def_ECObjects(py::module_&);
void def_ECProvider(py::module_&);
void def_ECSchema(py::module_&);
void def_ECValue(py::module_&);
void def_PresentationMetadataHelper(py::module_&);
void def_StandaloneECInstance(py::module_&);
void def_StandaloneECRelationshipInstance(py::module_&);
void def_StandardCustomAttributeHelper(py::module_&);
void def_SupplementalSchema(py::module_&);

void def_auiitem(py::module_&);
void def_auiprovider(py::module_&);
void def_ecimagekey(py::module_&);

/*---------------------------------------------------------------------------------**//**
* Module definition.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
PYBIND11_MODULE(MSPyECObjects, m)
    {
    // Document for module
    m.doc() = "Pybind11 wrapper for ECObjects.dll";

    // class defines
    bind_container_PyEC(m);
    def_ECObjects(m);
    def_ECContext(m);
    def_ECDBuffer(m);
    def_ECSchema(m);
    def_ECEnabler(m);
    def_ECExpressions(m);
    def_ECInstance(m);
    def_ECInstanceIterable(m);    
    def_ECProvider(m);    
    def_ECValue(m);
    def_PresentationMetadataHelper(m);
    def_StandaloneECInstance(m);
    def_StandaloneECRelationshipInstance(m);
    def_StandardCustomAttributeHelper(m);
    def_SupplementalSchema(m);
    def_auiprovider(m);
    def_auiitem(m);    
    def_ecimagekey(m);
    }


