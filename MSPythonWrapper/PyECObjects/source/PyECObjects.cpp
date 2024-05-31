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
    m.doc() = R"doc(The MSPyECObjects library, ECObjects is a set of abstractions for working with engineering/business data and metadata. EC stands for Engineering Content. 
You can think of an ECClass as being like a Python,C++ or .NET class that only defines properties (ECClasses define no methods or behaviors.) In some ways, they are closer to .NET interfaces that hold only properties... or C++ pure virtual abstract base classes that only contain property getters and setters. They are also very analogous to a database table definition.
ECClasses contain ECProperties. These are property definitions, not values.
ECInstances represent instances of objects. Each belongs to an ECClass and holds ECPropertyValues. They are somewhat analogous to the rows of a database table.
An ECSchema is just a collection of ECClasses.
There are also ECRelationshipClasses that are ECClasses that also define RelationshipConstraints indicating what ECClasses they relate. ECRelationshipInstances represent the relationships between the ECInstances (defined/constrained by their ECRelationshipClass) ECRelationships work like a database foreign key constraint.)doc";

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


