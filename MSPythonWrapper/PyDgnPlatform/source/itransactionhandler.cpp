/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\itransactionhandler.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ITransactionHandler.h>



//=======================================================================================
// Publicist class for ITransactionHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct ITransactionHandlerPub : ITransactionHandler
    {
    public:
        using ITransactionHandler::PreActionStatus;
        using ITransactionHandler::_OnUndoRedo;
        using ITransactionHandler::_OnHistoryRestore;
        using ITransactionHandler::_OnUndoRedoFinished;
        using ITransactionHandler::_OnDeleted;
        using ITransactionHandler::_OnAdded;
        using ITransactionHandler::_OnAddedComplete;
        using ITransactionHandler::_OnModified;
        using ITransactionHandler::_OnUndoRedoXAttributeChange;
        using ITransactionHandler::_OnXAttributeChanged;
        using ITransactionHandler::_OnAdd;
        using ITransactionHandler::_OnReplace;
        using ITransactionHandler::_OnDelete;
        using ITransactionHandler::_OnRemoveHandler;
    };

//=======================================================================================
// Trampoline class for ITransactionHandler.
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyTransactionHandler : ITransactionHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoRedo(ElementHandleP afterUndoRedo, ElementHandleP beforeUndoRedo, ChangeTrackAction action, bool isUndo, ChangeTrackSource source) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnUndoRedo, afterUndoRedo, beforeUndoRedo, action, isUndo, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnHistoryRestore(ElementHandleP after, ElementHandleP before, ChangeTrackAction actionStep, BentleyDgnHistoryElementChangeType effectiveChange) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnHistoryRestore, after, before, actionStep, effectiveChange); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoRedoFinished(ElementRefP element, bool isUndo) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnUndoRedoFinished, element, isUndo); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnDeleted(ElementHandleP element) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnDeleted, element); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnAdded(ElementHandleP element) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnAdded, element); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnAddedComplete(ElementHandleP element) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnAddedComplete, element); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnModified(ElementHandleP newElement, ElementHandleP oldElement, ChangeTrackAction action, bool* cantBeUndoneFlag) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnModified");
                if (pyfunc)
                    {
                    // _OnModified(newElement, oldElement, action) -> cantBeUndoneFlag
                    auto obj = pyfunc(newElement, oldElement, action);
                    if (cantBeUndoneFlag)
                        *cantBeUndoneFlag = obj.cast<bool>();
                    }
                else
                    __super::_OnModified(newElement, oldElement, action, cantBeUndoneFlag);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnUndoRedoXAttributeChange(XAttributeHandleCR xAttr, ChangeTrackAction action, bool isUndo, ChangeTrackSource source) override
            { PYBIND11_OVERRIDE_EX(void, ITransactionHandler, _OnUndoRedoXAttributeChange, xAttr, action, isUndo, source); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _OnXAttributeChanged(XAttributeHandleCR xAttr, ChangeTrackAction action, bool* cantBeUndoneFlag) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnXAttributeChanged");
                if (pyfunc)
                    {
                    // _OnXAttributeChanged(xAttr, action) -> cantBeUndoneFlag
                    auto obj = pyfunc(xAttr, action);
                    if (cantBeUndoneFlag)
                        *cantBeUndoneFlag = obj.cast<bool>();
                    }
                else
                    __super::_OnXAttributeChanged(xAttr, action, cantBeUndoneFlag);
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual PreActionStatus _OnAdd(EditElementHandleR eeh) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnWillAdd");
                PreActionStatus retVal = PRE_ACTION_Ok;
                if (pyfunc)
                    {
                    // _OnWillAdd(eeh) -> bool
                    auto obj = pyfunc(eeh);
                    bool bOk = obj.cast<bool>();
                    retVal = bOk ? PRE_ACTION_Ok : PRE_ACTION_Block;
                    }
                else
                    retVal = __super::_OnAdd(eeh);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return PRE_ACTION_Block;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual PreActionStatus _OnReplace(EditElementHandleR target, ElementHandleCR source) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnWillReplace");
                PreActionStatus retVal = PRE_ACTION_Ok;
                if (pyfunc)
                    {
                    // _OnWillReplace(target, source) -> bool
                    auto obj = pyfunc(target, source);
                    bool bOk = obj.cast<bool>();
                    retVal = bOk ? PRE_ACTION_Ok : PRE_ACTION_Block;
                    }
                else
                    retVal = __super::_OnReplace(target, source);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return PRE_ACTION_Block;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual PreActionStatus _OnDelete(ElementHandleCR eh) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnWillDelete");
                PreActionStatus retVal = PRE_ACTION_Ok;
                if (pyfunc)
                    {
                    // _OnWillDelete(eh) -> bool
                    auto obj = pyfunc(eh);
                    bool bOk = obj.cast<bool>();
                    retVal = bOk ? PRE_ACTION_Ok : PRE_ACTION_Block;
                    }
                else
                    retVal = __super::_OnDelete(eh);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return PRE_ACTION_Block;
                }
            }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual PreActionStatus _OnRemoveHandler(ElementHandleCR eh) override
            {
            try
                {
                py::gil_scoped_acquire gil;
                py::function pyfunc = py::get_override(this, "_OnWillRemoveHandler");
                PreActionStatus retVal = PRE_ACTION_Ok;
                if (pyfunc)
                    {
                    // _OnWillRemoveHandler(eh) -> bool
                    auto obj = pyfunc(eh);
                    bool bOk = obj.cast<bool>();
                    retVal = bOk ? PRE_ACTION_Ok : PRE_ACTION_Block;
                    }
                else
                    retVal = __super::_OnRemoveHandler(eh);

                return retVal;
                }
            catch (std::exception& ex)
                {
                ScriptEngineManager::Get().InjectException(ex);
                return PRE_ACTION_Block;
                }
            }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ITransactionHandler(py::module_& m)
    {
    //===================================================================================
    // struct ITransactionHandler
    py::class_< ITransactionHandler, std::unique_ptr< ITransactionHandler, py::nodelete>, IPyTransactionHandler> c1(m, "ITransactionHandler");

    c1.def(py::init<>());
    c1.def("_OnUndoRedo", &ITransactionHandlerPub::_OnUndoRedo, "afterUndoRedo"_a, "beforeUndoRedo"_a, "action"_a, "isUndo"_a, "source"_a);
    c1.def("_OnHistoryRestore", &ITransactionHandlerPub::_OnHistoryRestore, "after"_a, "before"_a, "actionStep"_a, "effectiveChange"_a);
    c1.def("_OnUndoRedoFinished", &ITransactionHandlerPub::_OnUndoRedoFinished, "element"_a, "isUndo"_a);
    c1.def("_OnDeleted", &ITransactionHandlerPub::_OnDeleted, "element"_a);
    c1.def("_OnAdded", &ITransactionHandlerPub::_OnAdded, "element"_a);
    c1.def("_OnAddedComplete", &ITransactionHandlerPub::_OnAddedComplete, "element"_a);
    
    c1.def("_OnModified", [] (ITransactionHandler& self, ElementHandleP newElement, ElementHandleP oldElement, ChangeTrackAction action)
           {
           bool cantBeUndoneFlag = false;
           static_cast<ITransactionHandlerPub&>(self)._OnModified(newElement, oldElement, action, &cantBeUndoneFlag);
           return cantBeUndoneFlag;
           }, "newElement"_a, "oldElement"_a, "action"_a);

    c1.def("_OnUndoRedoXAttributeChange", &ITransactionHandlerPub::_OnUndoRedoXAttributeChange, "xAttr"_a, "action"_a, "isUndo"_a, "source"_a);

    c1.def("_OnXAttributeChanged", [] (ITransactionHandler& self, XAttributeHandleCR xAttr, ChangeTrackAction action)
           {
           bool cantBeUndoneFlag = false;
           static_cast<ITransactionHandlerPub&>(self)._OnXAttributeChanged(xAttr, action, &cantBeUndoneFlag);
           return cantBeUndoneFlag;
           }, "xAttr"_a, "action"_a);

    c1.def("_OnWillAdd", [] (ITransactionHandler& self, EditElementHandleR eeh)
           {
           auto retVal = static_cast<ITransactionHandlerPub&>(self)._OnAdd(eeh);
           return (int) retVal == 0 ? true : false;
           }, "eeh"_a);

    c1.def("_OnWillReplace", [] (ITransactionHandler& self, EditElementHandleR target, ElementHandleCR source)
           {
           auto retVal = static_cast<ITransactionHandlerPub&>(self)._OnReplace(target, source);
           return (int) retVal == 0 ? true : false;
           }, "target"_a, "source"_a);

    c1.def("_OnWillDelete", [] (ITransactionHandler& self, EditElementHandleR eeh)
           {
           auto retVal = static_cast<ITransactionHandlerPub&>(self)._OnDelete(eeh);
           return (int) retVal == 0 ? true : false;
           }, "eeh"_a);

    c1.def("_OnWillRemoveHandler", [] (ITransactionHandler& self, EditElementHandleR eeh)
           {
           auto retVal = static_cast<ITransactionHandlerPub&>(self)._OnRemoveHandler(eeh);
           return (int) retVal == 0 ? true : false;
           }, "eeh"_a);

    c1.def_static("CallOnAdded", &ITransactionHandler::CallOnAdded, "eh"_a);
    c1.def_static("CallOnAddedComplete", &ITransactionHandler::CallOnAddedComplete, "eh"_a);
    }