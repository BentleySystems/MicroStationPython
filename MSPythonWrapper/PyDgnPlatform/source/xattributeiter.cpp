/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\xattributeiter.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnFileIO/XAttributeIter.h>



static const char * __doc_Bentley_DgnPlatform_XAttributeHandle_HasAttribute =R"doc(Convenience method to determine whether an XAttribute exists on a
given element.)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributeHandle_GetHandlerId =R"doc(Get the XAttributeHandlerId of the XAttribute this XAttributeHandle
references.)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributeHandle_GetId =R"doc(Get the XAttributeId of the XAttribute this XAttributeHandle
references.)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributeHandle_GetElementRef =R"doc(Get the ElementRefP from which this XAttributeHandle was constructed.)doc";

static const char * __doc_Bentley_DgnPlatform_XAttributeHandle_IsValid =R"doc(Determine whether this XAttributeHandle is valid or not.

:returns:
    true if this XAttributeHandle is valid. If this method returns
    false, all other methods on this XAttributeHandle will fail or
    crash.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_XAttributeIter(py::module_& m)
    {
    //===================================================================================
    // struct XAttributeHandle
    py::class_< XAttributeHandle> c1(m, "XAttributeHandle");
    bind_PointerVector< XAttributeHandleCP>(m, "XAttributeHandleCPArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // Local constants
        c1.attr("INVALID_XATTR_ID") = (UInt32)XAttributeHandle::INVALID_XATTR_ID;
        c1.attr("MATCH_ANY_ID") = (UInt32)XAttributeHandle::MATCH_ANY_ID;
        }

    c1.def(py::init<>());
    c1.def(py::init<ElementRefP, XAttributeHandlerId, UInt32>(), "elRef"_a, "handler"_a, "id"_a);
    c1.def("IsValid", &XAttributeHandle::IsValid, DOC(Bentley, DgnPlatform, XAttributeHandle, IsValid));
    c1.def("__bool__", [] (XAttributeHandle& self) { return self.IsValid(); });
    
    c1.def_property_readonly("ElementRef", &XAttributeHandle::GetElementRef);
    c1.def("GetElementRef", &XAttributeHandle::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, XAttributeHandle, GetElementRef));
    
    c1.def_property_readonly("Id", &XAttributeHandle::GetId);
    c1.def("GetId", &XAttributeHandle::GetId, DOC(Bentley, DgnPlatform, XAttributeHandle, GetId));
    
    c1.def_property_readonly("HandlerId", &XAttributeHandle::GetHandlerId);
    c1.def("GetHandlerId", &XAttributeHandle::GetHandlerId, DOC(Bentley, DgnPlatform, XAttributeHandle, GetHandlerId));
    c1.def_property_readonly("Data", [] (XAttributeHandle& self)
                             {
                             py::bytes outData;
                             if (self.GetSize() > 0 && nullptr != self.PeekData())
                                 outData = py::bytes((const char*) self.PeekData(), self.GetSize());
                             return outData;
                             });
    c1.def("GetData", [] (XAttributeHandle& self)
           {
           py::bytes outData;
           if (self.GetSize() > 0 && nullptr != self.PeekData())
               outData = py::bytes((const char*) self.PeekData(), self.GetSize());
           return outData;
           });

    c1.def_static("HasAttribute", &XAttributeHandle::HasAttribute, "elRef"_a, "handlerId"_a, "id"_a, DOC(Bentley, DgnPlatform, XAttributeHandle, HasAttribute));

    //===================================================================================
    // struct XAttributeCollection
    py::class_< XAttributeCollection> c2(m, "XAttributeCollection");

    if (true)
        {
        //===================================================================================
        // struct Entry
        py::class_< XAttributeCollection::Entry, XAttributeHandle> c2_1(c2, "Entry", py::multiple_inheritance());

        c2_1.def(py::init<ElementRefP, XAttributeHandlerId, UInt32>(), "elRef"_a, "searchId"_a, "id"_a = (UInt32)XAttributeHandle::MATCH_ANY_ID);
        c2_1.def(py::self == py::self);
        c2_1.def(py::self != py::self);
        }

    c2.def(py::init<ElementRefP, XAttributeHandlerId>(), "elRef"_a, "handlerId"_a = XAttributeHandlerId(0, 0));
    c2.def("__iter__", [] (XAttributeCollection& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    }