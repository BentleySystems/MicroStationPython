/*--------------------------------------------------------------------------------------+
|
|     $Source: \MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnecchangemanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnECChangeManager.h>


//=======================================================================================
// Trampoline class for IDgnECChangeListener.
// @bsiclass                                                                   08/2024
//=======================================================================================
struct IPyDgnECChangeListener : IDgnECChangeListener
    {
    IPyDgnECChangeListener (int priority) : IDgnECChangeListener (priority) {}

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       08/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool AcceptChangeFor (ECClassCR ecClass, TransactionType transactionType) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "AcceptChangeFor");
            if (pyfunc)
                {
                auto obj = pyfunc(const_cast<ECClassCP> (&ecClass), py::int_((int)transactionType));
                return obj.cast<bool>();
                }
            else
                {
                pybind11::pybind11_fail("Tried to call pure virtual function IDgnECChangeListener::AcceptChangeFor");
                return false;
                }
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            return false;
            }
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       08/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void RelationshipsChanged (DgnRelationChangeRecords& changedRecords, DgnFiles& files, TransactionType transactionType) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override (this, "RelationshipsChanged");
            if (pyfunc)
                {
                pyfunc(&changedRecords, &files, py::int_((int)transactionType));
                }
            else
                pybind11::pybind11_fail("Tried to call pure virtual function IDgnECChangeListener::RelationshipsChanged");
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       08/2024
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual void DgnECInstancesChanged (DgnInstanceChangeRecords& changedRecords, DgnFileR file, TransactionType transactionType) override
        {
        try
            {
            py::gil_scoped_acquire gil;
            py::function pyfunc = py::get_override(this, "DgnECInstancesChanged");
            if (pyfunc)
                {
                pyfunc (&changedRecords, &file, py::int_((int)transactionType));
                }
            else
                pybind11::pybind11_fail("Tried to call pure virtual function IDgnECChangeListener::DgnECInstancesChanged");
            }
        catch (std::exception& err)
            {
            ScriptEngineManager::Get().InjectException(err);
            }
        }
    };

using IDgnECChangeListenerPtr = std::unique_ptr< IDgnECChangeListener, py::nodelete>;
using DgnInstanceChangeRecordPtr = std::unique_ptr< DgnInstanceChangeRecord, py::nodelete>;
using DgnRelationChangeRecordPtr = std::unique_ptr< DgnRelationChangeRecord, py::nodelete>;

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       08/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnECChangeManager (py::module_& m)
    {
    //===================================================================================
    // struct IDgnECChangeListener
    py::class_< IDgnECChangeListener, IDgnECChangeListenerPtr, IPyDgnECChangeListener> c1(m, "IDgnECChangeListener");
    c1.def(py::init<int>(), "priority"_a);
    bind_PointerVector<IDgnECChangeListenerP>(m, "DgnECChangeListeners", py::module_local(false));

    c1.def_property_readonly("Priority", &IDgnECChangeListener::GetPriority);
    c1.def("GetPriority", &IDgnECChangeListener::GetPriority);
    c1.def_property("IsHandled", &IDgnECChangeListener::GetIsHandled, &IDgnECChangeListener::SetIsHandled);
    c1.def("AcceptChangeFor", &IDgnECChangeListener::AcceptChangeFor);
    c1.def("RelationshipsChanged", &IDgnECChangeListener::RelationshipsChanged);
    c1.def("DgnECInstancesChanged", &IDgnECChangeListener::DgnECInstancesChanged);

    //===================================================================================
    // struct DgnInstanceChangeRecord
    py::class_< DgnInstanceChangeRecord, DgnInstanceChangeRecordPtr> c2(m, "DgnInstanceChangeRecord");
    bind_PointerVector<DgnInstanceChangeRecordP>(m, "DgnInstanceChangeRecords", py::module_local(false));
    c2.def("GetChangeState", &DgnInstanceChangeRecord::GetChangeState);
    c2.def("GetClassOfChange", &DgnInstanceChangeRecord::GetClassOfChange);
    c2.def("GetDeletedInstanceId", &DgnInstanceChangeRecord::GetDeletedInstanceId);
    c2.def("GetAfterChangeInstance", &DgnInstanceChangeRecord::GetAfterChangeInstance);

    //===================================================================================
    // struct DgnRelationChangeRecord
    py::class_< DgnRelationChangeRecord, DgnRelationChangeRecordPtr> c3 (m, "DgnRelationChangeRecord");
    bind_PointerVector<DgnRelationChangeRecordP>(m, "DgnRelationChangeRecords", py::module_local(false));
    c3.def("GetChangeState", &DgnRelationChangeRecord::GetChangeState);
    c3.def("GetClassOfChange", &DgnRelationChangeRecord::GetClassOfChange);
    c3.def("GetBeforeChangeInstance", &DgnRelationChangeRecord::GetBeforeChangeInstance);
    c3.def("GetAfterChangeInstance", &DgnRelationChangeRecord::GetAfterChangeInstance);
    }