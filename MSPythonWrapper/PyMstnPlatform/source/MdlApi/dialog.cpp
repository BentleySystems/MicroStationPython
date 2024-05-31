/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\MdlApi\dialog.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <pybind11/functional.h>
#include <Mstn/PythonMacro/PyEventHandler.h>

USING_NAMESPACE_BENTLEY_MSTNPLATFORM

/*---------------------------------------------------------------------------------**//**
* @bsiclass                                                                        9/2023
+---------------+---------------+---------------+---------------+---------------+------*/
struct IPyModalDialogEventsWrapper : public IPyModalDialogEvents
{
public:
    using IPyModalDialogEvents::IPyModalDialogEvents;

    virtual int OnDialogOpened (WCharCP dialogBoxName) override
        {
        PYBIND11_OVERRIDE_PURE_EXR (int, IPyModalDialogEvents, OnDialogOpened, PyMsdDialogBoxResult::PyMsdDialogBoxResultCancel, dialogBoxName);
        }

    virtual void OnDialogClosed (WCharCP dialogBoxName, PyMsdDialogBoxResult dialogResult) override
        {
        PYBIND11_OVERRIDE_PURE_EX (void, IPyModalDialogEvents, OnDialogClosed, dialogBoxName, dialogResult);
        }

};


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      3/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_msdialog (py::module_& m)
    {
    py::enum_< PyMsdDialogBoxResult> (m, "PyMsdDialogBoxResult")
        .value("ePyMsdDialogBoxResultApply", PyMsdDialogBoxResult::PyMsdDialogBoxResultApply)
        .value("ePyMsdDialogBoxResultReset", PyMsdDialogBoxResult::PyMsdDialogBoxResultReset)
        .value("ePyMsdDialogBoxResultOK", PyMsdDialogBoxResult::PyMsdDialogBoxResultOK)
        .value("ePyMsdDialogBoxResultCancel", PyMsdDialogBoxResult::PyMsdDialogBoxResultCancel)
        .value("ePyMsdDialogBoxResultDefault", PyMsdDialogBoxResult::PyMsdDialogBoxResultDefault)
        .value("ePyMsdDialogBoxResultYes", PyMsdDialogBoxResult::PyMsdDialogBoxResultYes)
        .value("ePyMsdDialogBoxResultNo", PyMsdDialogBoxResult::PyMsdDialogBoxResultNo)
        .value("ePyMsdDialogBoxResultRetry", PyMsdDialogBoxResult::PyMsdDialogBoxResultRetry)
        .value("ePyMsdDialogBoxResultStop", PyMsdDialogBoxResult::PyMsdDialogBoxResultStop)
        .value("ePyMsdDialogBoxResultHelp", PyMsdDialogBoxResult::PyMsdDialogBoxResultHelp)
        .value("ePyMsdDialogBoxResultYesToAll", PyMsdDialogBoxResult::PyMsdDialogBoxResultYesToAll);

    py::class_<IPyModalDialogEvents, std::unique_ptr< IPyModalDialogEvents, py::nodelete>, IPyModalDialogEventsWrapper> c1(m, "IPyModalDialogEvents");
    c1.def (py::init<>());
    c1.def ("OnDialogOpened", &IPyModalDialogEvents::OnDialogOpened);
    c1.def ("OnDialogClosed", &IPyModalDialogEvents::OnDialogClosed);

    py::class_<PyEventsHandler> c2(m, "PyEventsHandler");
    c2.def_static ("AddModalDialogEventsHandler", &PyEventsHandler::AddModalDialogEventsHandler, "eventHandler"_a);
    c2.def_static ("RemoveModalDialogEventsHandler", &PyEventsHandler::RemoveModalDialogEventsHandler, "eventHandler"_a);
    
    }

