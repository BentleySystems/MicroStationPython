/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyECObjects\source\auiitem.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <ECPresentation/auiitem.h>


//=======================================================================================
// Trampoline class for IAUIDataContext
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyAUIDataContext : IAUIDataContext
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual ContextType _GetContextType() const override
            { PYBIND11_OVERRIDE_PURE_EXR(ContextType, IAUIDataContext, _GetContextType, ContextType::Custom, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void* GetCustomData() const override
            {
            try
                {
                py::gil_scoped_acquire gil;
                void* retVal = nullptr;
                py::function func = py::get_override(this, "GetCustomData");
                if (func)
                    {
                    auto obj = func();
                    auto holder = obj.cast<py::capsule>();
                    retVal = holder.get_pointer();
                    }
                else
                    retVal = __super::GetCustomData();

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return nullptr;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual ECInstanceIterableCP GetInstanceIterable() const override
            { PYBIND11_OVERRIDE_EXR(ECInstanceIterableCP, IAUIDataContext, GetInstanceIterable, nullptr, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual WString GetMoniker() const override
            { PYBIND11_OVERRIDE_EXR(WString, IAUIDataContext, GetMoniker, WString(), ); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_auiitem(py::module_& m)
    {
    //===================================================================================
    // struct IAUIDataContext
    py::class_< IAUIDataContext, IPyAUIDataContext> c3(m, "IAUIDataContext");

    if (true)
        {
        //===================================================================================
        // enum ContextType
        py::enum_< IAUIDataContext::ContextType>(c3, "ContextType", py::arithmetic())
            .value("eCustom", IAUIDataContext::Custom)
            .value("eInstanceID", IAUIDataContext::InstanceID)
            .value("eInstanceInterface", IAUIDataContext::InstanceInterface)
            .value("eECInstanceCollection", IAUIDataContext::ECInstanceCollection)
            .value("eDgnECInstanceCollection", IAUIDataContext::DgnECInstanceCollection)
            .value("eDgnHitPathInfo", IAUIDataContext::DgnHitPathInfo)
            .value("eDgnActionItemInfoType", IAUIDataContext::DgnActionItemInfoType)
            .value("eECGroupingNode", IAUIDataContext::ECGroupingNode)
            .value("eNodeCollection", IAUIDataContext::NodeCollection)
            .export_values();
        }

    c3.def("_GetContextType", &IAUIDataContext::_GetContextType);
    c3.def("GetCustomData", [] (IAUIDataContext& self) { return py::capsule(self.GetCustomData()); });
    c3.def("GetInstanceIterable", &IAUIDataContext::GetInstanceIterable, py::return_value_policy::reference_internal);
    c3.def("GetMoniker", &IAUIDataContext::GetMoniker);
    c3.def("GetContextType", &IAUIDataContext::GetContextType);
    }