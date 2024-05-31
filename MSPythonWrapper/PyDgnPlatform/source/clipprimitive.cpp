/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\clipprimitive.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/ClipPrimitive.h>



static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ExpandClipPlanes =R"doc(expand clip planes by supplied distance.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_TransformFromClip =R"doc(Transform the given point from clip to world coordinates)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_TransformToClip =R"doc(Transform the given point from world to clip coordinates)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ClassifyPointContainment =R"doc(Classify the given points for containment within this ClipPrimitive's
boundary)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ApplyCameraToPlanes =R"doc(Prepare clip planes by projecting the clip points to the given focal
length along the z-direction)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ParseClipPlanes =R"doc(Prepare clip planes and mask planes of this ClipPrimitive)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ContainsZClip =R"doc(Test if this ClipPrimitive has any clip plane whose normal is not in
the XY plane)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_IsXYPolygon =R"doc(Test if this ClipPrimitive lies on the XY plane)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SphereInside =R"doc(Check if the given sphere is inside this ClipPrimitive's boundary)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_PointInside =R"doc(Check if the given point is on or inside this ClipPrimitive's boundary)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetPolygon =R"doc(Get a ClipPolygon representation of this ClipPrimitive if feasible)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SetZHigh =R"doc(Set Z-High clip distance)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetZHigh =R"doc(Get Z-High clip distance)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SetZLow =R"doc(Set Z-Low clip distance)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetZLow =R"doc(Get Z-Low clip distance)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SetClipZLow =R"doc(Set if this ClipPrimitive applies clip on Z-Low side)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ClipZLow =R"doc(Query if this ClipPrimitive applies clip on Z-Low side)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SetClipZHigh =R"doc(Set if this ClipPrimitive applies clip on Z-High side)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_ClipZHigh =R"doc(Query if this ClipPrimitive applies clip on Z-High side)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SetIsMask =R"doc(Mark this ClipPrimitive to act as a mask. If false, it acts as a clip.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_IsMask =R"doc(Query if this ClipPrimitive acts as a mask. If false, it acts as a
clip.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_TransformInPlace =R"doc(Apply the given transform to the clip points and clip planes)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetTransforms =R"doc(Get transforms from world to clip and clip to world coordinates)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_SetInvisible =R"doc(Mark this ClipPrimitive as invisible)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetInvisible =R"doc(Query the invisible state of the clip primitive)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetTransformFromClip =R"doc(Get Transform from clip to world coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetTransformToClip =R"doc(Get Transform from world to clip coordinates.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetRange =R"doc(Get the range of the entire clip primitive)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetBCurve =R"doc(Get clip points in the form of MSBsplineCurve if available)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetGPA =R"doc(Get GPArray of clip points if available)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetMaskOrClipPlanes =R"doc(Get clip planes or mask planes if available)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetMaskPlanes =R"doc(Get mask planes if available)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_GetClipPlanes =R"doc(Get clip planes if available)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_CreateFromConvexPolyface =R"doc(Create a ClipPrimitive from a convex polyface.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_CreateFromBoundaryCurveVector =R"doc(Create a ClipPrimitive from a CurveVector.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_CreateFromGPA =R"doc(Create a ClipPrimitive from a GPArray.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_CreateFromClipPlanes =R"doc(Create a ClipPrimitive from the given extents.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_CreateFromShape =R"doc(Create a ClipPrimitive from the given extents.)doc";

static const char * __doc_Bentley_DgnPlatform_ClipPrimitive_CreateFromBlock =R"doc(Create a ClipPrimitive from the given extents. The z-extents will be
applied depending on clipMask)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ClipPrimitive(py::module_& m)
    {
    //===================================================================================
    // struct ClipPrimitive
    py::class_<ClipPrimitive, ClipPrimitivePtr> c2(m, "ClipPrimitive");
    py::bind_vector<T_ClipPrimitiveVector>(m, "ClipPrimitivePtrArray", py::module_local(false));

    c2.def(py::init(&ClipPrimitive::CreateCopy), "primitive"_a);
    c2.def_static("CreateFromBlock", &ClipPrimitive::CreateFromBlock, "low"_a, "high"_a, "outside"_a, "clipMask"_a, "transformFromClip"_a, "invisible"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, CreateFromBlock));
    
    c2.def_static("CreateFromShape",
        [](DPoint2dArray const& points, bool outside, boost::optional<double> zLow, boost::optional<double> zHigh, TransformCP transformFromClip, bool invisible)
        {
            return ClipPrimitive::CreateFromShape(&points[0], points.size(), outside, zLow.get_ptr(), zHigh.get_ptr(), transformFromClip, invisible);
        },
        "points"_a, "outside"_a, "zLow"_a, "zHigh"_a, "transformFromClip"_a, "invisible"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, CreateFromShape));
    
    c2.def_static("CreateFromClipPlanes", &ClipPrimitive::CreateFromClipPlanes, "planes"_a, "invisible"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, CreateFromClipPlanes));

    c2.def_static("CreateFromGPA", 
        [](GPArrayCR gpa, double chordTolerance, double angleTolerance, bool isMask, boost::optional<double> zLow, boost::optional<double> zHigh, TransformCP transformFromClip, bool invisible)
        {
            return ClipPrimitive::CreateFromGPA(gpa, chordTolerance, angleTolerance, isMask, zLow.get_ptr(), zHigh.get_ptr(), transformFromClip, invisible);
        },
        "gpa"_a, "chordTolerance"_a, "angleTolerance"_a, "isMask"_a, "zLow"_a, "zHigh"_a, "transformFromClip"_a, "invisible"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, CreateFromGPA));
    c2.def_static("CreateFromBoundaryCurveVector",
        [](CurveVectorCR curveVector, double chordTolerance, double angleTolerance, boost::optional<double> zLow, boost::optional<double> zHigh, TransformCP transformFromClip, bool invisible = false)
        {
            return ClipPrimitive::CreateFromBoundaryCurveVector(curveVector, chordTolerance, angleTolerance, zLow.get_ptr(), zHigh.get_ptr(), transformFromClip, invisible);
        }, "curveVector"_a, "chordTolerance"_a, "angleTolerance"_a, "zLow"_a, "zHigh"_a, "transformFromClip"_a, "invisible"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, CreateFromBoundaryCurveVector));
    c2.def_static("CreateFromConvexPolyface", &ClipPrimitive::CreateFromConvexPolyface, "polyface"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, CreateFromConvexPolyface));

    c2.def_property_readonly("ClipPlanes", &ClipPrimitive::GetClipPlanes);
    c2.def("GetClipPlanes", &ClipPrimitive::GetClipPlanes, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetClipPlanes));
    
    c2.def_property_readonly("MaskPlanes", &ClipPrimitive::GetMaskPlanes);
    c2.def("GetMaskPlanes", &ClipPrimitive::GetMaskPlanes, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetMaskPlanes));
    
    c2.def_property_readonly("MaskOrClipPlanes", &ClipPrimitive::GetMaskOrClipPlanes);
    c2.def("GetMaskOrClipPlanes", &ClipPrimitive::GetMaskOrClipPlanes, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetMaskOrClipPlanes));
    
    c2.def("GetGPA", &ClipPrimitive::GetGPA, py::return_value_policy::reference, "onlyIfNonLinear"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, GetGPA));
    
    c2.def_property_readonly("BCurve", &ClipPrimitive::GetBCurve);
    c2.def("GetBCurve", &ClipPrimitive::GetBCurve, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetBCurve));
    
    c2.def("GetRange", &ClipPrimitive::GetRange, "range"_a, "transform"_a, "returnMaskRange"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, GetRange));
    
    c2.def("GetTransformToClip", &ClipPrimitive::GetTransformToClip, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetTransformToClip));    
    c2.def("GetTransformFromClip", &ClipPrimitive::GetTransformFromClip, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetTransformFromClip));
    
    c2.def_property("Invisible", &ClipPrimitive::GetInvisible, &ClipPrimitive::SetInvisible);
    c2.def("GetInvisible", &ClipPrimitive::GetInvisible, DOC(Bentley, DgnPlatform, ClipPrimitive, GetInvisible));
    c2.def("SetInvisible", &ClipPrimitive::SetInvisible, "invisible"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SetInvisible));

    c2.def("GetTransforms", &ClipPrimitive::GetTransforms, "forward"_a, "inverse"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, GetTransforms));
    c2.def("TransformInPlace", &ClipPrimitive::TransformInPlace, "transform"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, TransformInPlace));
    
    c2.def("IsMask", &ClipPrimitive::IsMask, DOC(Bentley, DgnPlatform, ClipPrimitive, IsMask));
    c2.def("SetIsMask", &ClipPrimitive::SetIsMask, "isMask"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SetIsMask));
    
    c2.def("ClipZHigh", &ClipPrimitive::ClipZHigh, DOC(Bentley, DgnPlatform, ClipPrimitive, ClipZHigh));
    c2.def("SetClipZHigh", &ClipPrimitive::SetClipZHigh, "clipZHigh"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SetClipZHigh));
    
    c2.def("ClipZLow", &ClipPrimitive::ClipZLow, DOC(Bentley, DgnPlatform, ClipPrimitive, ClipZLow));
    c2.def("SetClipZLow", &ClipPrimitive::SetClipZLow, "clipZLow"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SetClipZLow));
    
    c2.def_property("ZLow", &ClipPrimitive::GetZLow, &ClipPrimitive::SetZLow);
    c2.def("GetZLow", &ClipPrimitive::GetZLow, DOC(Bentley, DgnPlatform, ClipPrimitive, GetZLow));
    c2.def("SetZLow", &ClipPrimitive::SetZLow, "zLow"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SetZLow));
    
    c2.def_property("ZHigh", &ClipPrimitive::GetZHigh, &ClipPrimitive::SetZHigh);
    c2.def("GetZHigh", &ClipPrimitive::GetZHigh, DOC(Bentley, DgnPlatform, ClipPrimitive, GetZHigh));
    c2.def("SetZHigh", &ClipPrimitive::SetZHigh, "zHigh"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SetZHigh));

    c2.def_property_readonly("Polygon", &ClipPrimitive::GetPolygon);
    c2.def("GetPolygon", &ClipPrimitive::GetPolygon, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, ClipPrimitive, GetPolygon));

    c2.def("PointInside", &ClipPrimitive::PointInside, "point"_a, "onTolerance"_a = 0.0, DOC(Bentley, DgnPlatform, ClipPrimitive, PointInside));
    c2.def("SphereInside", &ClipPrimitive::SphereInside, "point"_a, "radius"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, SphereInside));
    
    c2.def("IsXYPolygon", &ClipPrimitive::IsXYPolygon, DOC(Bentley, DgnPlatform, ClipPrimitive, IsXYPolygon));
    c2.def("ContainsZClip", &ClipPrimitive::ContainsZClip, DOC(Bentley, DgnPlatform, ClipPrimitive, ContainsZClip));
    c2.def("ParseClipPlanes", &ClipPrimitive::ParseClipPlanes, DOC(Bentley, DgnPlatform, ClipPrimitive, ParseClipPlanes));
    c2.def("ApplyCameraToPlanes", &ClipPrimitive::ApplyCameraToPlanes, "focalLength"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, ApplyCameraToPlanes));
    
    c2.def("ClassifyPointContainment", [] (ClipPrimitiveCR self, std::vector<DPoint3d> const& points, bool ignoreMasks)
           {
           return self.ClassifyPointContainment(points.data(), points.size(), ignoreMasks);
           }, "points"_a, "ignoreMasks"_a = false, DOC(Bentley, DgnPlatform, ClipPrimitive, ClassifyPointContainment));

    c2.def("TransformToClip", &ClipPrimitive::TransformToClip, "point"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, TransformToClip));
    c2.def("TransformFromClip", &ClipPrimitive::TransformFromClip, "point"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, TransformFromClip));
    c2.def("ExpandClipPlanes", &ClipPrimitive::ExpandClipPlanes, "distance"_a, DOC(Bentley, DgnPlatform, ClipPrimitive, ExpandClipPlanes));
    }