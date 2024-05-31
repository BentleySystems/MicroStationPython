/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\fenceparams.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/FenceParams.h>



static const char * __doc_Bentley_DgnPlatform_FenceParams_Delete =R"doc(Frees a FenceParams instance.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_BuildAgenda =R"doc(Parameter ``agenda``:
    The list of elements that satisfied the fence criteria.

Parameter ``searchList``:
    The list of candidate models to search for elements that pass the
    fence criteria.

Returns:
    SUCCESS If one or more elements were found that satisfied the
    fence criteria. @note Populates agenda with un-clipped elements
    that satisfy the fence criteria. Set overlap mode to false and
    clip mode to none to collect only those elements completely inside
    the fence, otherwise both inside and overlapping elements are
    collected.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_AcceptElement =R"doc(Return true if the given element satisfies the fence criteria.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetToModelRef =R"doc(Push view clipping (for a root model) and DgnAttachment
transform/clipping onto the fence.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_HasOverlaps =R"doc(Return true if AcceptElement detected an overlap.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_PointInside =R"doc(Return true if the supplied point is inside the fence.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_GetFocalLength =R"doc(Return camera focal length, only valid when IsCameraOn returns true.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_IsCameraOn =R"doc(Return true if fence was defined by 2d points in a camera view.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_ClippingPointsFromRootPoints =R"doc(Return 2d clipping points suitable for calling StoreClippingPoints
from 3d input points in the coordinates of the view's root model.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_StoreClippingElement =R"doc(Setup the fence clip boundary from an element that represents a planar
region or simple extruded volume.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_StoreClippingPoints =R"doc(Setup the fence clip boundary from 2d clipping points. Pass true for
blockIfPossible to create CLIPBLOCK instead of CLIPSHAPE when points
define a rectangle.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetLocateInteriors =R"doc(Specify whether overlap testing should detect a fence that is
completely contained within a region/surface element.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetOverlapMode =R"doc(Set fence mode to inside or overlap for when the clip model is none.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_AllowOverlaps =R"doc(Return true if fence overlap mode is set.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetTransform =R"doc(Set the current fence to root transform. This is normally set by
calling SetViewParams.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_GetTransform =R"doc(Return current fence to root transform.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_GetViewport =R"doc(Return current fence viewport.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_GetClipVector =R"doc(Return a pointer to the fence's clip boundary.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetClipMode =R"doc(Set the fence clip mode.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_GetClipMode =R"doc(Return current fence clip mode.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetModelRef =R"doc(Set the fence destination model.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_GetModelRef =R"doc(Return current fence model.)doc";

static const char * __doc_Bentley_DgnPlatform_FenceParams_SetViewParams =R"doc(Setup the fence parameters from the supplied viewport.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_FenceParams(py::module_& m)
    {
    //===================================================================================
    // enum class FenceClipMode
    py::enum_< FenceClipMode>(m, "FenceClipMode")
        .value("eNone", FenceClipMode::None)
        .value("eOriginal", FenceClipMode::Original)
        .value("eCopy", FenceClipMode::Copy)
        .export_values();

    //===================================================================================
    // struct FenceParams
    py::class_< FenceParams, std::unique_ptr<FenceParams, py::nodelete> > c1(m, "FenceParams");


    c1.def("SetViewParams", &FenceParams::SetViewParams, "vp"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, FenceParams, SetViewParams));    

    c1.def_property("ModelRef", &FenceParams::GetModelRef, py::cpp_function(&FenceParams::SetModelRef, py::keep_alive<1, 2>()));
    c1.def("GetModelRef", &FenceParams::GetModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FenceParams, GetModelRef));
    c1.def("SetModelRef", &FenceParams::SetModelRef, "modelRef"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, FenceParams, SetModelRef));
    
    c1.def_property("ClipMode", &FenceParams::GetClipMode, &FenceParams::SetClipMode);
    c1.def("GetClipMode", &FenceParams::GetClipMode, DOC(Bentley, DgnPlatform, FenceParams, GetClipMode));
    c1.def("SetClipMode", &FenceParams::SetClipMode, "mode"_a, DOC(Bentley, DgnPlatform, FenceParams, SetClipMode));
    
    c1.def_property("ClipVector", &FenceParams::GetClipVector, &FenceParams::SetClip);
    c1.def("GetClipVector", &FenceParams::GetClipVector, DOC(Bentley, DgnPlatform, FenceParams, GetClipVector));
    c1.def("SetClipVector", &FenceParams::SetClip, "clip"_a);
    
    c1.def_property_readonly("Viewport", &FenceParams::GetViewport);
    c1.def("GetViewport", &FenceParams::GetViewport, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FenceParams, GetViewport));
    
    c1.def_property("Transform", &FenceParams::GetTransform, py::cpp_function(&FenceParams::SetTransform, py::keep_alive<1, 2>()));
    c1.def("GetTransform", &FenceParams::GetTransform, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, FenceParams, GetTransform));
    c1.def("SetTransform", &FenceParams::SetTransform, "transform"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, FenceParams, SetTransform));
    
    c1.def_property("OverlapMode", &FenceParams::AllowOverlaps, &FenceParams::SetOverlapMode);
    c1.def("AllowOverlaps", &FenceParams::AllowOverlaps, DOC(Bentley, DgnPlatform, FenceParams, AllowOverlaps));
    c1.def("SetOverlapMode", &FenceParams::SetOverlapMode, "mode"_a, DOC(Bentley, DgnPlatform, FenceParams, SetOverlapMode));
    
    c1.def("SetLocateInteriors", &FenceParams::SetLocateInteriors, "pref"_a, DOC(Bentley, DgnPlatform, FenceParams, SetLocateInteriors));
    
    c1.def("StoreClippingPoints", [] (FenceParamsR self, bool outside, DPoint2dArray& points)
           {
           return self.StoreClippingPoints(outside, points.data(), (int) points.size());
           }, "outside"_a, "points"_a, DOC(Bentley, DgnPlatform, FenceParams, StoreClippingPoints));

    c1.def("StoreClippingElement", &FenceParams::StoreClippingElement, "eh"_a, "outside"_a, DOC(Bentley, DgnPlatform, FenceParams, StoreClippingElement));
    
    c1.def("ClippingPointsFromRootPoints", [] (FenceParamsR self, DPoint2dArray& points1, DPoint3dArray& points2, ViewportP vp)
           {
           self.ClippingPointsFromRootPoints(points1.data(), points2.data(), (int) points1.size(), vp);
           }, "points1"_a, "points2"_a, "vp"_a, DOC(Bentley, DgnPlatform, FenceParams, ClippingPointsFromRootPoints));

    c1.def("IsCameraOn", &FenceParams::IsCameraOn, DOC(Bentley, DgnPlatform, FenceParams, IsCameraOn));
    
    c1.def_property_readonly("FocalLength", &FenceParams::GetFocalLength);
    c1.def("GetFocalLength", &FenceParams::GetFocalLength, DOC(Bentley, DgnPlatform, FenceParams, GetFocalLength));
    
    c1.def("PointInside", &FenceParams::PointInside, "testPoint"_a, DOC(Bentley, DgnPlatform, FenceParams, PointInside));    
    c1.def("HasOverlaps", &FenceParams::HasOverlaps, DOC(Bentley, DgnPlatform, FenceParams, HasOverlaps));    
    c1.def("SetToModelRef", &FenceParams::SetToModelRef, "modelRef"_a, DOC(Bentley, DgnPlatform, FenceParams, SetToModelRef));
    c1.def("AcceptElement", &FenceParams::AcceptElement, "eh"_a, DOC(Bentley, DgnPlatform, FenceParams, AcceptElement));
    c1.def("BuildAgenda", &FenceParams::BuildAgenda, "agenda"_a, "searchList"_a, DOC(Bentley, DgnPlatform, FenceParams, BuildAgenda));
    c1.def(py::init(&FenceParams::Create), "modelRef"_a, py::keep_alive<1, 2>());
    c1.def_static("Delete", &FenceParams::Delete, DOC(Bentley, DgnPlatform, FenceParams, Delete));
    }