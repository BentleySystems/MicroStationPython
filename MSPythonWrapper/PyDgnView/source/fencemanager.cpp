/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnView\source\fencemanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnView/FenceManager.h>



static const char * __doc_Bentley_DgnPlatform_FenceManager_GetManager =R"doc(Get the current FenceManager instance.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_ClipElement =R"doc(Apply fence clip operation to input element.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_StretchElement =R"doc(Apply fence stretch operation to input element.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_GetActiveFenceClipFlags =R"doc(Get active fence clip behavior settings.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_GetActiveFenceStretchFlags =R"doc(Get active fence stretch behavior setting.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_BuildAgenda =R"doc(Collect elements that satisfy the supplied FenceParams/criteria.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_InitFromActiveFence =R"doc(Populate the supplied FenceParams with information for the active
fence.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_TransformFence =R"doc(Apply a transform to the active fence.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_DefineByPoints =R"doc(Set active fence by points.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_DefineByElement =R"doc(Set active fence from an element.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_GetFencePoints =R"doc(Get the points for a fence defined by points.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_GetFenceElem =R"doc(Get the element for a fence defined by element.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_GetFenceViewport =R"doc(Get the fence viewport for a fence defined by points.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_SetInhibitFenceDisplay =R"doc(For use in tools that need to automate fence creation/processing and
don't want the fence displayed in the view.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_DisplayFence =R"doc(For use in tools that manipulate fence contents. Draw transforms fence
as a decorator.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_ClearFence =R"doc(Clear any active points/element fence so that are is no longer a fence
active.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_IsDefinedByPoints =R"doc(Return whether a fence defined by points is currently active.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_IsDefinedByElem =R"doc(Return whether a fence defined by element is currently active.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_IsClipMode =R"doc(Return whether current fence mode is clip. Accept and clip elements
that overlap the fence boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_IsOverlapMode =R"doc(Return whether current fence mode is overlap. Accept elements that
overlap the fence boundary and aren't completely inside (or outside if
void mode).)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_IsVoidMode =R"doc(Return whether current fence mode is void. Accept elements outside
fence.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_IsFenceActive =R"doc(Return whether a fence is currently defined, either by points or
element.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceManager_UseActiveFence =R"doc(Check the active setting for whether a tool should use the fence if
one is currently active.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_FenceManager(py::module_& m)
    {
    //===================================================================================
    // struct FenceManager
    py::class_< FenceManager> c1(m, "FenceManager");

    if (true)
        {
        //===================================================================================
        // enum FenceDisplayMode
        py::enum_< FenceManager::FenceDisplayMode>(c1, "FenceDisplayMode", py::arithmetic())
            .value("eFENCE_NormalDraw", FenceManager::FENCE_NormalDraw)
            .value("eFENCE_InhibitDraw", FenceManager::FENCE_InhibitDraw)
            .value("eFENCE_InhibitFill", FenceManager::FENCE_InhibitFill)
            .export_values();
        }

    c1.def("UseActiveFence", &FenceManager::UseActiveFence, DOC(Bentley, DgnPlatform, FenceManager, UseActiveFence));
    c1.def("IsFenceActive", &FenceManager::IsFenceActive, DOC(Bentley, DgnPlatform, FenceManager, IsFenceActive));
    c1.def("IsVoidMode", &FenceManager::IsVoidMode, DOC(Bentley, DgnPlatform, FenceManager, IsVoidMode));
    c1.def("IsOverlapMode", &FenceManager::IsOverlapMode, DOC(Bentley, DgnPlatform, FenceManager, IsOverlapMode));
    c1.def("IsClipMode", &FenceManager::IsClipMode, DOC(Bentley, DgnPlatform, FenceManager, IsClipMode));
    c1.def("IsDefinedByElem", &FenceManager::IsDefinedByElem, DOC(Bentley, DgnPlatform, FenceManager, IsDefinedByElem));
    c1.def("IsDefinedByPoints", &FenceManager::IsDefinedByPoints, DOC(Bentley, DgnPlatform, FenceManager, IsDefinedByPoints));

    c1.def("ClearFence", &FenceManager::ClearFence, DOC(Bentley, DgnPlatform, FenceManager, ClearFence));
    c1.def("DisplayFence", [](FenceManager& self, ViewportP vp, TransformCP optTrans, boost::optional<int> optTransparency)
                           {
                               self.DisplayFence(vp, optTrans, optTransparency.get_ptr());
                           }, "vp"_a, "optTrans"_a = nullptr, "optTransparency"_a = nullptr, DOC(Bentley, DgnPlatform, FenceManager, DisplayFence));
    c1.def("SetInhibitFenceDisplay", &FenceManager::SetInhibitFenceDisplay, "inhibit"_a, DOC(Bentley, DgnPlatform, FenceManager, SetInhibitFenceDisplay));

    c1.def_property_readonly("FenceViewport", &FenceManager::GetFenceViewport);
    c1.def("GetFenceViewport", &FenceManager::GetFenceViewport, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FenceManager, GetFenceViewport));
    
    c1.def_property_readonly("FenceElem", &FenceManager::GetFenceElem);
    c1.def("GetFenceElem", &FenceManager::GetFenceElem, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FenceManager, GetFenceElem));
    
    c1.def("GetFencePoints", &FenceManager::GetFencePoints, "points"_a, DOC(Bentley, DgnPlatform, FenceManager, GetFencePoints));
    
    c1.def("DefineByElement", &FenceManager::DefineByElement, "eh"_a, "vp"_a, DOC(Bentley, DgnPlatform, FenceManager, DefineByElement));
    
    c1.def("DefineByPoints", [] (FenceManager& self, DPoint3dArray const& points, ViewportP vp)
           {
           return self.DefineByPoints(points.data(), (int) points.size(), vp);
           }, "points"_a, "vp"_a, DOC(Bentley, DgnPlatform, FenceManager, DefineByPoints));

    c1.def("TransformFence", &FenceManager::TransformFence, "transform"_a, DOC(Bentley, DgnPlatform, FenceManager, TransformFence));
    c1.def("InitFromActiveFence", &FenceManager::InitFromActiveFence, "fp"_a, "overlap"_a, "doClip"_a, "allowClipFlag"_a, DOC(Bentley, DgnPlatform, FenceManager, InitFromActiveFence));
    c1.def("BuildAgenda", &FenceManager::BuildAgenda, "fp"_a, "agenda"_a, "modelRefList"_a, "modifyOrig"_a, "allowLocked"_a, "callAsynch"_a, DOC(Bentley, DgnPlatform, FenceManager, BuildAgenda));
    
    c1.def_property_readonly("ActiveFenceStretchFlags", &FenceManager::GetActiveFenceStretchFlags);
    c1.def("GetActiveFenceStretchFlags", &FenceManager::GetActiveFenceStretchFlags, DOC(Bentley, DgnPlatform, FenceManager, GetActiveFenceStretchFlags));
    
    c1.def_property_readonly("ActiveFenceClipFlags", &FenceManager::GetActiveFenceClipFlags);
    c1.def("GetActiveFenceClipFlags", &FenceManager::GetActiveFenceClipFlags, DOC(Bentley, DgnPlatform, FenceManager, GetActiveFenceClipFlags));

    c1.def("StretchElement", &FenceManager::StretchElement, "fp"_a, "eeh"_a, "transform"_a, "flags"_a, DOC(Bentley, DgnPlatform, FenceManager, StretchElement));
    c1.def("ClipElement", &FenceManager::ClipElement, "fp"_a, "inside"_a, "outside"_a, "eh"_a, "flags"_a, DOC(Bentley, DgnPlatform, FenceManager, ClipElement));

    c1.def_static("GetManager", &FenceManager::GetManager, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, FenceManager, GetManager));
    }