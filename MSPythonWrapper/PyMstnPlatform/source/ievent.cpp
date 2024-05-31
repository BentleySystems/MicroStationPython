/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ievent.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Mstn/Plot/IPrintEngine.h>
#include <Mstn/IEvent.h>



static const char * __doc_Bentley_MstnPlatform_MstnEventManager_GetManager =R"doc(Get the MstnEventManager instance.)doc";

static const char * __doc_Bentley_MstnPlatform_MstnEventManager_DropPrintEventHandler =R"doc(Drop an IPrintEventHandler from list of installed PrintEventHandlers.
After this call, handler will not be notified of future print events.

Parameter ``[in]``:
    handler to drop.)doc";

static const char * __doc_Bentley_MstnPlatform_MstnEventManager_AddPrintEventHandler =R"doc(Add a new IPrintEventHandler to MicroStation's list of installed
PrintEventHandlers.

Parameter ``[in]``:
    handler New handler to add)doc";

static const char * __doc_Bentley_MstnPlatform_MstnEventManager_DropMouseWheelHandler =R"doc(Drop an IMouseWheelHandler from list of installed MouseWheelHandlers.
After this call, handler will not be notified of future MouseWheel
events.

Parameter ``[in]``:
    mwHandler the IMouseWheelHandler to drop.)doc";

static const char * __doc_Bentley_MstnPlatform_MstnEventManager_AddMouseWheelHandler =R"doc(Add a new IMouseWheelHandler to MicroStation's list of installed
MouseWheelHandlers.

Parameter ``[in]``:
    mwHandler New IMouseWheelHandler to add)doc";

static const char * __doc_Bentley_MstnPlatform_MstnEventManager_DropEditActionSource =R"doc(Drop an DgnPlatform::IEditActionSource from list of installed
EditActionSources. After this call, handler will not be notified of
future EditActionSource events.

Parameter ``[in]``:
    source the DgnPlatform::IEditActionSource to drop.)doc";

static const char * __doc_Bentley_MstnPlatform_MstnEventManager_AddEditActionSource =R"doc(Add a new DgnPlatform::IEditActionSource to MicroStation's list of
installed EditActionSources. After this call, handler will be notified
of all future EditActionSource events.

Parameter ``[in]``:
    source New DgnPlatform::IEditActionSource to add)doc";

//=======================================================================================
// Publicist class for IEventHandlerPrioritized
// @bsiclass                                                                   02/23
//=======================================================================================
struct IEventHandlerPrioritizedPub : IEventHandlerPrioritized
    {
    public:
        using IEventHandlerPrioritized::_GetHandlerPriority;        
    };

//=======================================================================================
// Trampoline class for IEventHandlerPrioritized
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyEventHandlerPrioritized : IEventHandlerPrioritized
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int _GetHandlerPriority() override
            { PYBIND11_OVERRIDE_PURE_EXR(int, IEventHandlerPrioritized, _GetHandlerPriority, 0, ); }
    };

//=======================================================================================
// Publicist class for IMouseWheelHandler
// @bsiclass                                                                   02/23
//=======================================================================================
struct IMouseWheelHandlerPub : IMouseWheelHandler
    {
    public:
        using IMouseWheelHandler::_GetHandlerPriority;
        using IMouseWheelHandler::_OnWheelMotion;
    };

//=======================================================================================
// Trampoline class for IMouseWheelHandler
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyMouseWheelHandler : IMouseWheelHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int _GetHandlerPriority() override
            { PYBIND11_OVERRIDE_PURE_EXR(int, IMouseWheelHandler, _GetHandlerPriority, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual bool _OnWheelMotion(MSWindowP gwP, UInt32 modifierKeys, long xPos, long yPos, long wheelDelta) override
            { PYBIND11_OVERRIDE_PURE_EXR(bool, IMouseWheelHandler, _OnWheelMotion, false, gwP, modifierKeys, xPos, yPos, wheelDelta); }
    };

//=======================================================================================
// Trampoline class for IBeginPrintPageParam
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyBeginPrintPageParam : IBeginPrintPageParam
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPrintEngineCP GetPrintEngine() const override
        { PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineCP, IBeginPrintPageParam, GetPrintEngine, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPrintEnginePlotter() const override
        { PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IBeginPrintPageParam, GetPrintEnginePlotter, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPreview() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IBeginPrintPageParam, GetIsPreview, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPartOfPrintSet() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IBeginPrintPageParam, GetIsPartOfPrintSet, false, ); }
    };

//=======================================================================================
// Trampoline class for IEndPrintPageParam
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyEndPrintPageParam : IEndPrintPageParam
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/        
    virtual IPrintEngineCP GetPrintEngine() const override
        { PYBIND11_OVERRIDE_PURE_EXR(IPrintEngineCP, IEndPrintPageParam, GetPrintEngine, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual IPlotterCP GetPrintEnginePlotter() const override
        { PYBIND11_OVERRIDE_PURE_EXR(IPlotterCP, IEndPrintPageParam, GetPrintEnginePlotter, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPreview() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IEndPrintPageParam, GetIsPreview, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsPartOfPrintSet() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IEndPrintPageParam, GetIsPartOfPrintSet, false, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    virtual bool GetIsSuccess() const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, IEndPrintPageParam, GetIsSuccess, false, ); }
    };

//=======================================================================================
// Trampoline class for IPrintEventHandler
// @bsiclass                                                                   02/23
//=======================================================================================
struct IPyPrintEventHandler : IPrintEventHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/    
        virtual int _GetHandlerPriority() override
            { PYBIND11_OVERRIDE_PURE_EXR(int, IPrintEventHandler, _GetHandlerPriority, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void BeginPrintPage(IBeginPrintPageParamP param) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler, BeginPrintPage, param); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void EndPrintPage(IEndPrintPageParamP param) override
            { PYBIND11_OVERRIDE_PURE_EX(void, IPrintEventHandler, EndPrintPage, param); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IEvent(py::module_& m)
    {
    //===================================================================================
    // struct IEventHandlerPrioritized
    py::class_< IEventHandlerPrioritized, std::unique_ptr<IEventHandlerPrioritized, py::nodelete>, IPyEventHandlerPrioritized> c1(m, "IEventHandlerPrioritized");

    c1.def(py::init<>());
    c1.def("_GetHandlerPriority", &IEventHandlerPrioritizedPub::_GetHandlerPriority);

    //===================================================================================
    // struct IMouseWheelHandler
    py::class_< IMouseWheelHandler, std::unique_ptr<IMouseWheelHandler, py::nodelete>, IPyMouseWheelHandler, IEventHandlerPrioritized> c2(m, "IMouseWheelHandler");

    c2.def(py::init<>());
    c2.def("_OnWheelMotion", &IMouseWheelHandlerPub::_OnWheelMotion, "gwP"_a, "modifierKeys"_a, "xPos"_a, "yPos"_a, "wheelDelta"_a);

    //===================================================================================
    // struct IBeginPrintPageParam
    py::class_< IBeginPrintPageParam, std::unique_ptr<IBeginPrintPageParam, py::nodelete>, IPyBeginPrintPageParam> c3(m, "IBeginPrintPageParam");

    c3.def(py::init<>());
    c3.def("GetPrintEngine", &IBeginPrintPageParam::GetPrintEngine, py::return_value_policy::reference_internal);
    c3.def("GetPrintEnginePlotter", &IBeginPrintPageParam::GetPrintEnginePlotter, py::return_value_policy::reference_internal);
    c3.def("GetIsPreview", &IBeginPrintPageParam::GetIsPreview);
    c3.def("GetIsPartOfPrintSet", &IBeginPrintPageParam::GetIsPartOfPrintSet);

    //===================================================================================
    // struct IEndPrintPageParam
    py::class_< IEndPrintPageParam, std::unique_ptr<IEndPrintPageParam, py::nodelete>, IPyEndPrintPageParam> c4(m, "IEndPrintPageParam");

    c4.def(py::init<>());
    c4.def("GetPrintEngine", &IEndPrintPageParam::GetPrintEngine, py::return_value_policy::reference_internal);
    c4.def("GetPrintEnginePlotter", &IEndPrintPageParam::GetPrintEnginePlotter, py::return_value_policy::reference_internal);
    c4.def("GetIsPreview", &IEndPrintPageParam::GetIsPreview);
    c4.def("GetIsPartOfPrintSet", &IEndPrintPageParam::GetIsPartOfPrintSet);
    c4.def("GetIsSuccess", &IEndPrintPageParam::GetIsSuccess);

    //===================================================================================
    // struct IPrintEventHandler
    py::class_< IPrintEventHandler, std::unique_ptr<IPrintEventHandler, py::nodelete>, IPyPrintEventHandler, IEventHandlerPrioritized> c5(m, "IPrintEventHandler");

    c5.def(py::init<>());
    c5.def("BeginPrintPage", &IPrintEventHandler::BeginPrintPage, "param"_a);
    c5.def("EndPrintPage", &IPrintEventHandler::EndPrintPage, "param"_a);

    //===================================================================================
    // struct MstnEventManager
    py::class_< MstnEventManager> c6(m, "MstnEventManager");

    c6.def("AddEditActionSource", &MstnEventManager::AddEditActionSource, "source"_a, py::keep_alive<1, 2>(), DOC(Bentley, MstnPlatform, MstnEventManager, AddEditActionSource));
    c6.def("DropEditActionSource", &MstnEventManager::DropEditActionSource, "source"_a, DOC(Bentley, MstnPlatform, MstnEventManager, DropEditActionSource));
    c6.def("AddMouseWheelHandler", &MstnEventManager::AddMouseWheelHandler, "handler"_a, py::keep_alive<1, 2>(), DOC(Bentley, MstnPlatform, MstnEventManager, AddMouseWheelHandler));
    c6.def("DropMouseWheelHandler", &MstnEventManager::DropMouseWheelHandler, "handler"_a, DOC(Bentley, MstnPlatform, MstnEventManager, DropMouseWheelHandler));
    c6.def("AddPrintEventHandler", &MstnEventManager::AddPrintEventHandler, "handler"_a, py::keep_alive<1, 2>(), DOC(Bentley, MstnPlatform, MstnEventManager, AddPrintEventHandler));
    c6.def("DropPrintEventHandler", &MstnEventManager::DropPrintEventHandler, "handler"_a, DOC(Bentley, MstnPlatform, MstnEventManager, DropPrintEventHandler));
    c6.def_static("GetManager", &MstnEventManager::GetManager, py::return_value_policy::reference, DOC(Bentley, MstnPlatform, MstnEventManager, GetManager));
    }