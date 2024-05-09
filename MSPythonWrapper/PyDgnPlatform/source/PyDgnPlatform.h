/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\PyDgnPlatform.h $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include <DgnPlatform/DgnModel.h>

//=======================================================================================
// Trampoline class for DgnModelAppData.
// @bsiclass                                                                   02/23
//=======================================================================================
template <class DgnModelAppDataBase = DgnModelAppData> 
class PyDgnModelAppData : public DgnModelAppDataBase
    {
    public:
        using DgnModelAppDataBase::DgnModelAppDataBase;

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual void _OnCleanup(DgnModelR host) override
            { PYBIND11_OVERRIDE_PURE_EX(void, DgnModelAppDataBase, _OnCleanup, host); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnFilled(DgnModelR host) override
            { PYBIND11_OVERRIDE_EX(void, DgnModelAppDataBase, _OnFilled, host); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnEmpty(DgnModelR host) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnModelAppDataBase, _OnEmpty, false, host); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnEmptied(DgnModelR host) override
            { PYBIND11_OVERRIDE_EXR(bool, DgnModelAppDataBase, _OnEmptied, false, host); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnModelDelete(DgnModelR host) override
            { PYBIND11_OVERRIDE_EX(void, DgnModelAppDataBase, _OnModelDelete, host); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnModelUnDelete(DgnModelR host) override
            { PYBIND11_OVERRIDE_EX(void, DgnModelAppDataBase, _OnModelUnDelete, host); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnElementAdded(DgnModelR host, PersistentElementRef& elem, bool isGraphicsList) override
            { PYBIND11_OVERRIDE_EX(void, DgnModelAppDataBase, _OnElementAdded, host, elem, isGraphicsList); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnSaveModelProperties(DgnModelR host, ModelInfoCR original) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function func = py::get_override(this, "_OnSaveModelProperties");
                if (func)
                    {
                    ModelInfoPtr copyptr = original.MakeCopy(); // ModelInfo has Private copy constructor, replace it with holder type
                    func(host, copyptr);
                    }
                else
                    __super::_OnSaveModelProperties(host, original);
                }
            catch (std::exception& err)
                {
                ScriptEngineManager::Get().InjectException(err);
                }
            }
    };

