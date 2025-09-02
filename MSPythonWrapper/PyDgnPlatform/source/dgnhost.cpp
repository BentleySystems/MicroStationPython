/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnhost.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnHost.h>



static const char * __doc_Bentley_DgnPlatform_DgnHost_SetHostObject =R"doc(Set the value of a host-based variable identified by key.

:param key:
    The key that identifies this variable. Keys must always be static
    variables, as their values are assigned when they are first used
    and must remain the same for the entire run of a host program.

:param val:
    The value to be associated with key for this DgnHost.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnHost_GetHostObject =R"doc(Get the value of a host-based variable identified by key.

:param key:
    The key that identifies this variable. Keys must always be static
    variables, as their values are assigned when they are first used
    and must remain the same for the entire run of a host program.

:returns:
    The value of the host variable identified by key. If the variable
    has never been set on this instance of DgnHost, the value will be
    0.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnHost_SetHostBoolVariable =R"doc(Set the value of a host-based boolean variable identified by key.

:param key:
    The key that identifies this variable. Keys must always be static
    variables, as their values are assigned when they are first used
    and must remain the same for the entire run of a host program.

:param val:
    The boolean value to be associated with key for this DgnHost.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnHost_GetHostBoolVariable =R"doc(Get the value of a host-based boolean variable identified by key.

:param key:
    The key that identifies this variable. Keys must always be static
    variables, as their values are assigned when they are first used
    and must remain the same for the entire run of a host program.

:returns:
    The boolean value of the host variable identified by key. If the
    variable has never been set on this instance of DgnHost, the value
    will be 0.)doc";

//=======================================================================================
// Publicist class for DgnHost::IHostObject.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IHostObjectPub : DgnHost::IHostObject
    {
    public:
        using DgnHost::IHostObject::_OnHostTermination;
    };

//=======================================================================================
// Trampoline class for DgnHost::IHostObject.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyHostObject : DgnHost::IHostObject
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnHostTermination(bool isProgramExit) override
            { PYBIND11_OVERRIDE_PURE_EX(void, DgnHost::IHostObject, _OnHostTermination, isProgramExit); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnHost(py::module_& m)
    {
    //=======================================================================================
    // struct DgnHost
    py::class_<DgnHost> c1(m, "DgnHost");

    if (true)
        {
        //=======================================================================================
        // struct Key
        py::class_<DgnHost::Key> c1_1(c1, "Key");
        c1_1.def(py::init<>());

        //=======================================================================================
        // struct IHostObject
        py::class_ < DgnHost::IHostObject, IPyHostObject, std::unique_ptr < DgnHost::IHostObject, py::nodelete> > c1_2(c1, "IHostobject");
        
        c1_2.def(py::init<>());
        c1_2.def("OnHostTermination", &DgnHost::IHostObject::OnHostTermination, "isProgramExit"_a);
        c1_2.def("_OnHostTermination", &IHostObjectPub::_OnHostTermination, "isProgramExit"_a);

        //=======================================================================================
        // struct HostObjectBase
        py::class_<DgnHost::HostObjectBase, DgnHost::IHostObject> c1_3(c1, "HostObjectBase");
        }

    c1.def("GetHostVariable", [] (DgnHost& self, DgnHost::Key& key)
           { 
           return (intptr_t) self.GetHostVariable(key); 
           }, "key"_a);

    c1.def("SetHostVariable", [] (DgnHost& self, DgnHost::Key& key, intptr_t value)
           {
           self.SetHostVariable(key, reinterpret_cast<void*>(value));
           }, "key"_a, "value"_a);

    c1.def("GetHostBoolVariable", &DgnHost::GetHostBoolVariable, "key"_a, DOC(Bentley, DgnPlatform, DgnHost, GetHostBoolVariable));
    c1.def("SetHostBoolVariable", &DgnHost::SetHostBoolVariable, "key"_a, "val"_a, DOC(Bentley, DgnPlatform, DgnHost, SetHostBoolVariable));

    c1.def("GetHostObject", &DgnHost::GetHostObject, "key"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnHost, GetHostObject));
    c1.def("SetHostObject", &DgnHost::SetHostObject, "key"_a, "val"_a, py::keep_alive<1, 3>(), DOC(Bentley, DgnPlatform, DgnHost, SetHostObject));

    //=======================================================================================
    // struct DgnHostWString
    py::class_< DgnHostWString, DgnHost::IHostObject> c2(m, "DgnHostWString");

    c2.def(py::init<wchar_t const*>(), "s"_a);
    c2.def(py::init<WStringCR>(), "ws"_a);

    c2.def_property_readonly("WString", py::overload_cast<>(&DgnHostWString::GetWString));
    c2.def("GetWString", py::overload_cast<>(&DgnHostWString::GetWString), py::return_value_policy::reference_internal);
    }