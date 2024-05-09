/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgncore.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnCore.h>



static const char * __doc_Bentley_DgnPlatform_HandlerId_IsValid =R"doc(Test if the HandlerId has a non-zero major Id portion)doc";

static const char * __doc_Bentley_DgnPlatform_HandlerId_GetMinorId =R"doc(Gets the minor ID portion of the HandlerID.)doc";

static const char * __doc_Bentley_DgnPlatform_HandlerId_GetMajorId =R"doc(Gets the major ID portion of the HandlerId.)doc";

static const char * __doc_Bentley_DgnPlatform_HandlerId_GetId =R"doc(Gets the full 32-bit ID.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnCore(py::module_& m)
    {
    //===================================================================================
    // struct  HandlerId
    py::class_<HandlerId> c1(m, "HandlerId");

    c1.def(py::init<>());
    c1.def(py::init<UInt16, UInt16>(), "major"_a, "minor"_a);
    
    c1.def_property_readonly("Id", &HandlerId::GetId);
    c1.def("GetId", &HandlerId::GetId, DOC(Bentley, DgnPlatform, HandlerId, GetId));
    
    c1.def_property_readonly("MajorId", &HandlerId::GetMajorId);
    c1.def("GetMajorId", &HandlerId::GetMajorId, DOC(Bentley, DgnPlatform, HandlerId, GetMajorId));
    
    c1.def_property_readonly("MinorId", &HandlerId::GetMinorId);
    c1.def("GetMinorId", &HandlerId::GetMinorId, DOC(Bentley, DgnPlatform, HandlerId, GetMinorId));
    
    c1.def(py::self == py::self);
    c1.def(py::self != py::self);
    c1.def(py::self < py::self);
    c1.def("IsValid", &HandlerId::IsValid, DOC(Bentley, DgnPlatform, HandlerId, IsValid));  
    c1.def("__repr__", [] (HandlerId& self) { return "(Id:{}, majorId:{}, minorId:{})"_s.format(self.GetId(), self.GetMajorId(), self.GetMinorId()); });

    //===================================================================================
    // struct ElementHandlerId
    py::class_<DgnPlatform::ElementHandlerId, HandlerId> c2(m, "ElementHandlerId");
    
    c2.def(py::init<>());
    c2.def(py::init<UInt16, UInt16>(), "major"_a, "minor"_a);

    //===================================================================================
    // struct XAttributeHandlerId
    py::class_<DgnPlatform::XAttributeHandlerId, HandlerId> c3(m, "XAttributeHandlerId");
    
    c3.def(py::init<>());
    c3.def(py::init<UInt16, UInt16>(), "major"_a, "minor"_a);

    //===================================================================================
    // struct DgnModelHandlerId
    py::class_< DgnPlatform::DgnModelHandlerId, HandlerId> c4(m, "DgnModelHandlerId");
    
    c4.def(py::init<UInt16, UInt16>(), "major"_a, "minor"_a);
    }