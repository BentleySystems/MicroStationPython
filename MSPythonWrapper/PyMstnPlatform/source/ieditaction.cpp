/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\ieditaction.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <mstn/IEditAction.h>



static const char * __doc_Bentley_MstnPlatform_QueuedAction_AddToInputq =R"doc()doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_IEditAction(py::module_& m)
    {
    //===================================================================================
    // struct QueuedAction
    py::class_< QueuedAction, RefCountedPtr<QueuedAction> > c1(m, "QueuedAction");

    c1.def_static("CreateAction", [] (IEditAction& cmd) { return RefCountedPtr<QueuedAction>(QueuedAction::CreateAction(cmd)); }, "cmd"_a);
    c1.def("AddToInputq", &QueuedAction::AddToInputq, DOC(Bentley, MstnPlatform, QueuedAction, AddToInputq));

    //===================================================================================
    // bsiInterface IEditActionMenu
    py::class_< IEditActionMenu
        , std::unique_ptr<IEditActionMenu, py::nodelete>
    > c2(m, "IEditActionMenu");

    c2.def("AddEntry", &IEditActionMenu::AddEntry, "newMenuItem"_a, "parentMenuItem"_a, "action"_a, "labelOverride"_a, "imageOverride"_a);
    c2.def("AddDefaultMenuType", &IEditActionMenu::AddDefaultMenuType, "newMenuItem"_a, "parentMenuItem"_a, "action"_a, "labelOverride"_a, "imageOverride"_a);

    //===================================================================================
    // struct IEditActionArray
    py::class_< IEditActionArray        
        , std::unique_ptr<IEditActionArray, py::nodelete>
    > c4(m, "IEditActionArray");

    c4.def("AddEditAction", &IEditActionArray::AddEditAction, "action"_a, py::keep_alive<1, 2>());
    c4.def("GetEditAction", &IEditActionArray::GetEditAction, "index"_a, py::return_value_policy::reference_internal);
    c4.def("GetAcceleratorAction", &IEditActionArray::GetAcceleratorAction, "index"_a, py::return_value_policy::reference_internal);    
    }