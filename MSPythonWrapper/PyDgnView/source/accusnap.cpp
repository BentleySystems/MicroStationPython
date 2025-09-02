/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\accusnap.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/AccuSnap.h>
#include <DgnView/DgnTool.h>



static const char * __doc_Bentley_DgnPlatform_AccuSnap_GetInstance =R"doc(Get the current AccuSnap instance.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_DropEventHandler =R"doc(Drop an AccuSnapHandler from list of installed AccuSnapHandlers. After
this call, handler will not be notified of future AccuSnapHandler
events.

:param accuSnapHandler:
    the AccuSnapHandler to drop.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_AddEventHandler =R"doc(Add a new AccuSnapHandler to the list of installed AccuSnapHandlers.

:param accuSnapHandler:
    New AccuSnapHandler to add)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_ResetButton =R"doc(Can be called by tools to advance to the next AccuSnap/AutoLocate hit
path when more than one element is under the cursor. @note Used in
default implementation of DgnElementSetTool::_OnResetButton.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_Suspend =R"doc(Can be called by a tool to temporarily suspend Accusnap. Calls to this
function should be paired.

:param doSuspend:
    true to suspend AccuSnap, false to resume it.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_Clear =R"doc(Clear the current AccuSnap/AutoLocate path so that it is no longer
snapped or hilited.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_SetComponentMode =R"doc(@note Resets to default value of ComponentMode::None whenever locate
is enabled.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_IsLocateEnabled =R"doc(:returns:
    true if AutoLocate has been enabled by the current tool.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_IsSnapEnabled =R"doc(:returns:
    true if AccuSnap has been enabled by the current tool.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_EnableLocate =R"doc(Set the enabled state of AutoLocate for the current tool @note Even if
yesNo is true, AutoLocate will not be enabled unless the user has also
enabled it.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_EnableSnap =R"doc(Set the enabled state of AccuSnap for the current tool @note Even if
yesNo is true, AccuSnap will not be enabled unless the user has also
enabled it.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_UserWantsLocates =R"doc(:returns:
    true if the user has enabled AutoLocate. Controlled by " Identify Elements Automatically " preference.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_UserWantsSnaps =R"doc(:returns:
    true if the user has enabled AccuSnap.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_IsHot =R"doc(:returns:
    true if AccuSnap is currently active and snapped to an element.)doc";

static const char * __doc_Bentley_DgnPlatform_AccuSnap_IsActive =R"doc(Determine whether AccuSnap is currently active. To be active both the
tool and the user must indicate that they want it.

:param ev:
    The current button event. Used to check the modifier keys that can
    temporarily enable/disable AccuSnap.

:returns:
    true if active.)doc";

static const char * __doc_Bentley_DgnPlatform_TentativePoint_GetInstance =R"doc(Get the current TentativePoint instance.)doc";

static const char * __doc_Bentley_DgnPlatform_TentativePoint_Clear =R"doc(Clear the current tentative point so that it is no longer active.)doc";

static const char * __doc_Bentley_DgnPlatform_TentativePoint_GetPoint =R"doc(:returns:
    The current tentative point location as adjusted by the snap mode
    and locks.)doc";

static const char * __doc_Bentley_DgnPlatform_TentativePoint_IsSnapped =R"doc(:returns:
    true if the tentative point is currently active and snapped to an
    element.)doc";

static const char * __doc_Bentley_DgnPlatform_TentativePoint_IsActive =R"doc(:returns:
    true if the tentative point is currently active.)doc";

//=======================================================================================
// Publicist class for AccuSnapHandler
// @bsiclass                                                                   02/23
//=======================================================================================
struct AccuSnapHandlerPub : AccuSnapHandler
    {
    public:
        using AccuSnapHandler::_GetHandlerPriority;
        using AccuSnapHandler::_ShowElemInfoPopup;
        using AccuSnapHandler::_RemoveElemInfoPopup;
        using AccuSnapHandler::_FlashHitInView;
        using AccuSnapHandler::_UnFlashView;
    };

//=======================================================================================
// Trampoline class for AccuSnapHandler
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyAccuSnapHandler : AccuSnapHandler
    {
    public:
        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual int _GetHandlerPriority() override
            { PYBIND11_OVERRIDE_EXR(int, AccuSnapHandler, _GetHandlerPriority, 0, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AsnapStatus _ShowElemInfoPopup(DPoint3dCP pt, ViewportP vp, WCharCP string) override
            { PYBIND11_OVERRIDE_PURE_EXR(AsnapStatus, AccuSnapHandler, _ShowElemInfoPopup, AccuSnapHandler::DontShow, pt, vp, string); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _RemoveElemInfoPopup() override
            { PYBIND11_OVERRIDE_PURE_EX(void, AccuSnapHandler, _RemoveElemInfoPopup, ); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual AsnapStatus _FlashHitInView(ViewportP vp, HitPathCP path) override
            { PYBIND11_OVERRIDE_PURE_EXR(AsnapStatus, AccuSnapHandler, _FlashHitInView, AccuSnapHandler::DontShow, vp, path); }

        /*---------------------------------------------------------------------------------**//**
        * @bsimethod                                                                       2/2023
        +---------------+---------------+---------------+---------------+---------------+------*/
        virtual void _UnFlashView(ViewportP vp) override
            { PYBIND11_OVERRIDE_PURE_EX(void, AccuSnapHandler, _UnFlashView, vp); }
    };

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_AccuSnap(py::module_& m)
    {
    //===================================================================================
    // enum AccuSnapEnableFlag
    py::enum_< AccuSnapEnableFlag>(m, "AccuSnapEnableFlag", py::arithmetic())
        .value("eACCUSNAP_ENABLE_OffByDefault", ACCUSNAP_ENABLE_OffByDefault)
        .value("eACCUSNAP_ENABLE_OnByDefault", ACCUSNAP_ENABLE_OnByDefault)
        .value("eACCUSNAP_ENABLE_Never", ACCUSNAP_ENABLE_Never)
        .export_values();

    //===================================================================================
    // struct AccuSnapHandler
    py::class_< AccuSnapHandler, std::unique_ptr<AccuSnapHandler, py::nodelete>, PyAccuSnapHandler> c1(m, "AccuSnapHandler");

    if (true)
        {
        //===================================================================================
        // enum AccuSnapEventHandlerPriority
        py::enum_< AccuSnapHandler::AccuSnapEventHandlerPriority>(c1, "AccuSnapEventHandlerPriority", py::arithmetic())
            .value("eACCUSNAPHANDLER_PRIORITY_Highest", AccuSnapHandler::ACCUSNAPHANDLER_PRIORITY_Highest)
            .value("eACCUSNAPHANDLER_PRIORITY_High", AccuSnapHandler::ACCUSNAPHANDLER_PRIORITY_High)
            .value("eACCUSNAPHANDLER_PRIORITY_Normal", AccuSnapHandler::ACCUSNAPHANDLER_PRIORITY_Normal)
            .value("eACCUSNAPHANDLER_PRIORITY_Low", AccuSnapHandler::ACCUSNAPHANDLER_PRIORITY_Low)
            .value("eACCUSNAPHANDLER_PRIORITY_Lowest", AccuSnapHandler::ACCUSNAPHANDLER_PRIORITY_Lowest)
            .export_values();

        //===================================================================================
        // enum AsnapStatus
        py::enum_< AccuSnapHandler::AsnapStatus>(c1, "AsnapStatus", py::arithmetic())
            .value("eOk", AccuSnapHandler::Ok)
            .value("eDontShow", AccuSnapHandler::DontShow)
            .export_values();
        }

    //c1.def(py::init<>());
    c1.def("_GetHandlerPriority", &AccuSnapHandlerPub::_GetHandlerPriority);
    c1.def("_ShowElemInfoPopup", &AccuSnapHandlerPub::_ShowElemInfoPopup, "pt"_a, "vp"_a, "string"_a);
    c1.def("_RemoveElemInfoPopup", &AccuSnapHandlerPub::_RemoveElemInfoPopup);
    c1.def("_FlashHitInView", &AccuSnapHandlerPub::_FlashHitInView, "vp"_a, "path"_a);
    c1.def("_UnFlashView", &AccuSnapHandlerPub::_UnFlashView, "vp"_a);


    //===================================================================================
    // struct TentativePoint
    py::class_< TentativePoint, std::unique_ptr<TentativePoint, py::nodelete> > c3(m, "TentativePoint");

    c3.def("IsActive", &TentativePoint::IsActive, DOC(Bentley, DgnPlatform, TentativePoint, IsActive));
    c3.def("IsSnapped", &TentativePoint::IsSnapped, DOC(Bentley, DgnPlatform, TentativePoint, IsSnapped));
    c3.def_property_readonly("Point", &TentativePoint::GetPoint);
    c3.def("GetPoint", &TentativePoint::GetPoint, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, TentativePoint, GetPoint));

    c3.def("Clear", &TentativePoint::Clear, "erase"_a, DOC(Bentley, DgnPlatform, TentativePoint, Clear));
    c3.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< TentativePoint, py::nodelete>(&TentativePoint::GetInstance()); });
    c3.def_static("GetInstance", [] () { return std::unique_ptr< TentativePoint, py::nodelete>(&TentativePoint::GetInstance()); }, DOC(Bentley, DgnPlatform, TentativePoint, GetInstance));

    //===================================================================================
    // struct AccuSnap
    py::class_< AccuSnap
        , std::unique_ptr<AccuSnap, py::nodelete>
    > c4(m, "AccuSnap");

    c4.def("IsActive", &AccuSnap::IsActive, "ev"_a, DOC(Bentley, DgnPlatform, AccuSnap, IsActive));
    c4.def("IsHot", &AccuSnap::IsHot, DOC(Bentley, DgnPlatform, AccuSnap, IsHot));
    c4.def("UserWantsSnaps", &AccuSnap::UserWantsSnaps, DOC(Bentley, DgnPlatform, AccuSnap, UserWantsSnaps));
    c4.def("UserWantsLocates", &AccuSnap::UserWantsLocates, DOC(Bentley, DgnPlatform, AccuSnap, UserWantsLocates));
    c4.def("EnableSnap", &AccuSnap::EnableSnap, "yesNo"_a, DOC(Bentley, DgnPlatform, AccuSnap, EnableSnap));
    c4.def("EnableLocate", &AccuSnap::EnableLocate, "yesNo"_a, DOC(Bentley, DgnPlatform, AccuSnap, EnableLocate));
    c4.def("IsSnapEnabled", &AccuSnap::IsSnapEnabled, DOC(Bentley, DgnPlatform, AccuSnap, IsSnapEnabled));
    c4.def("IsLocateEnabled", &AccuSnap::IsLocateEnabled, DOC(Bentley, DgnPlatform, AccuSnap, IsLocateEnabled));
    c4.def("SetComponentMode", &AccuSnap::SetComponentMode, "mode"_a, DOC(Bentley, DgnPlatform, AccuSnap, SetComponentMode));
    c4.def_property_readonly("CurrHit", [] (AccuSnap& self) { return RefCountedPtr<HitPath>(self.CurrHit()); });
    c4.def("GetCurrHit", [] (AccuSnap& self) { return RefCountedPtr<HitPath>(self.CurrHit()); });
    c4.def("Clear", &AccuSnap::Clear, DOC(Bentley, DgnPlatform, AccuSnap, Clear));
    c4.def("Suspend", &AccuSnap::Suspend, "doSuspend"_a, DOC(Bentley, DgnPlatform, AccuSnap, Suspend));
    c4.def("ResetButton", &AccuSnap::ResetButton, DOC(Bentley, DgnPlatform, AccuSnap, ResetButton));
    c4.def_static("AddEventHandler", &AccuSnap::AddEventHandler, "accuSnapHandler"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, AccuSnap, AddEventHandler));
    c4.def_static("DropEventHandler", &AccuSnap::DropEventHandler, "accuSnapHandler"_a, DOC(Bentley, DgnPlatform, AccuSnap, DropEventHandler));

    c4.def_property_readonly_static("Instance", [] (py::object const&) { return std::unique_ptr< AccuSnap, py::nodelete>(&AccuSnap::GetInstance()); });    
    c4.def_static("GetInstance", [] () { return std::unique_ptr< AccuSnap, py::nodelete>(&AccuSnap::GetInstance()); }, DOC(Bentley, DgnPlatform, AccuSnap, GetInstance));
    }