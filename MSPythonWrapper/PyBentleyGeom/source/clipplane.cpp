/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\clipplane.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_ClipPlane_ClipPlaneToRange =R"doc(Return the (possibly empty) polygon of intersection between a DRange3d
and an (unbounded) plane.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_FindPointOnBothPlanes =R"doc(Search an array of points for the first index at which the point is on
both of two planes.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_OffsetDistance =R"doc(Apply offset to plane.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_ConvexPolygonSplitInsideOutside =R"doc((input) original polygon (output) inside part (output) outside part (output) min
and max altitude values.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_PolygonCrossings =R"doc(Return crossings of all edges of a polygon (including final closure)
This uses simple zero tests -- does not try to filter double data at
vertex-on-plane case)doc";

static const char * __doc_Bentley_Geom_ClipPlane_ConvexPolygonClipInPlace =R"doc(Clip a convex polygon. caller supplies work and altitude arrays as
works space. result is written inplace to xyz.

* onPlaneHandling=0 means no special handling for all-oin.

* onPlaneHandling=1 means treat all-on as (input)

* onPlaneHandling= -1 means treat all-on as (output))doc";

static const char * __doc_Bentley_Geom_ClipPlane_Negate =R"doc(Flip the normal direction.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_MultiplyPlaneTimesMatrix =R"doc(multiply plane coefficients times a DMatrix4d (such as the worldToNPC
matrix) multiply [ax,ay,az,aw] * matrix)doc";

static const char * __doc_Bentley_Geom_ClipPlane_TransformInPlace =R"doc(Transform plane.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_BoundedSegmentHasSimpleIntersection =R"doc(Return true if the through{pointA} and{pointB} crosses the plane at
a fractional coordinate between 0 and 1. Note that if both points are
ON the plane the return value is false -- the " on " case is not a
simple intersection.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetDPlane4d =R"doc(Return the plane for use as h = [ax,ay,az,aw] DOT [x,y,z,1])doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetLocalToWorldTransform =R"doc(Return the plane as a transform with origin on plane, z vector
perpendicular.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetDPlane3d =R"doc(Return the plane as origin and normal.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_IsPointOn =R"doc(Return if the point is on plane within tolerance)doc";

static const char * __doc_Bentley_Geom_ClipPlane_IsPointOnOrInside =R"doc(Return if the point is on or inside plane.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_DotProduct =R"doc(Evaluate Dot Product with plane normal.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_EvaluatePoint =R"doc(Evaluate the plane equation at{point}.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetNormal =R"doc(Return the plane normal.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetDistance =R"doc(Return the plane distance.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_SetFlags =R"doc(Set flags.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetFlags =R"doc(Get flags.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_IsVisible =R"doc(Return whether cut for this flag should be displayed (!invisible &&
!isInterior);)doc";

static const char * __doc_Bentley_Geom_ClipPlane_SetInvisible =R"doc(Get invisible.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_GetIsInterior =R"doc(Return the interior flag.)doc";

static const char * __doc_Bentley_Geom_ClipPlane_FromPointsAndDistanceAlongPlaneNormal =R"doc(Create a clip plane perpendicular to upVvector, positioned a distance
forward or backward of given points. ul> li>)doc";

static const char * __doc_Bentley_Geom_ClipPlane_FromEdgeAndUpVector =R"doc(ul> li>For non-tilted case, (tiltAngle = 0), the inward normal vector
is upVector cross edge vector. li>If tilt is nonzero, that plane is
rotated around the (forward) edge vector. ul>)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ClipPlane(py::module_& m)
    {
    //===================================================================================
    // struct ClipPlane
    py::class_<ClipPlane> c1(m, "ClipPlane");
    py::bind_vector< T_ClipPlanes >(m, "ClipPlaneArray", py::module_local(false));
    bind_ValidatedValue<ClipPlane>(m, "ValidatedClipPlane", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<DVec3dCR, double, bool, bool>(), "normal"_a, "distance"_a, "invisible"_a = false, "interior"_a = false);
    c1.def(py::init<DVec3dCR, DPoint3dCR, bool, bool>(), "normal"_a, "point"_a, "invisible"_a = false, "interior"_a = false);
    c1.def(py::init<DPlane3dCR, bool, bool>(), "plane"_a, "invisible"_a = false, "interior"_a = false);
    c1.def("__copy__", [](const ClipPlane& self)
        {
        return ClipPlane (self);
        });

    c1.def_static("FromEdgeAndUpVector", &ClipPlane::FromEdgeAndUpVector, "point0"_a, "point1"_a, "upVector"_a, "tiltAngle"_a, DOC(Bentley, Geom, ClipPlane, FromEdgeAndUpVector));
    c1.def_static("FromPointsAndDistanceAlongPlaneNormal", &ClipPlane::FromPointsAndDistanceAlongPlaneNormal, "points"_a, "upVector"_a, "distance"_a, "pointInside"_a, DOC(Bentley, Geom, ClipPlane, FromPointsAndDistanceAlongPlaneNormal));

    c1.def("GetIsInterior", &ClipPlane::GetIsInterior, DOC(Bentley, Geom, ClipPlane, GetIsInterior));

    c1.def_property("IsInvisible", &ClipPlane::GetIsInvisible, &ClipPlane::SetInvisible);
    c1.def("GetInvisible", &ClipPlane::GetIsInvisible);
    c1.def("SetInvisible", &ClipPlane::SetInvisible, "invisible"_a, DOC(Bentley, Geom, ClipPlane, SetInvisible));

    c1.def("IsVisible", &ClipPlane::IsVisible, DOC(Bentley, Geom, ClipPlane, IsVisible));

    c1.def_property("Flags", &ClipPlane::GetFlags, py::overload_cast<uint32_t>(&ClipPlane::SetFlags));
    c1.def("GetFlags", &ClipPlane::GetFlags, DOC(Bentley, Geom, ClipPlane, GetFlags));
    c1.def("SetFlags", py::overload_cast<uint32_t>(&ClipPlane::SetFlags), "flags"_a, DOC(Bentley, Geom, ClipPlane, SetFlags));    
    c1.def("SetFlags", py::overload_cast<bool, bool>(&ClipPlane::SetFlags), "invisible"_a, "interior"_a, DOC(Bentley, Geom, ClipPlane, SetFlags));
    
    c1.def("GetDistance", &ClipPlane::GetDistance, DOC(Bentley, Geom, ClipPlane, GetDistance));
    c1.def("GetNormal", &ClipPlane::GetNormal, py::return_value_policy::reference_internal, DOC(Bentley, Geom, ClipPlane, GetNormal));

    c1.def("EvaluatePoint", &ClipPlane::EvaluatePoint, "point"_a, DOC(Bentley, Geom, ClipPlane, EvaluatePoint));

    c1.def("DotProduct", py::overload_cast<DVec3dCR>(&ClipPlane::DotProduct, py::const_), "normal"_a, DOC(Bentley, Geom, ClipPlane, DotProduct));
    c1.def("DotProduct", py::overload_cast<DPoint3dCR>(&ClipPlane::DotProduct, py::const_), "point"_a, DOC(Bentley, Geom, ClipPlane, DotProduct));

    c1.def("IsPointOnOrInside", py::overload_cast<DPoint3dCR>(&ClipPlane::IsPointOnOrInside, py::const_), "point"_a, DOC(Bentley, Geom, ClipPlane, IsPointOnOrInside));
    c1.def("IsPointOnOrInside", py::overload_cast<DPoint3dCR, double>(&ClipPlane::IsPointOnOrInside, py::const_), "point"_a, "tolerance"_a, DOC(Bentley, Geom, ClipPlane, IsPointOnOrInside));

    c1.def("IsPointOn", &ClipPlane::IsPointOn, "point"_a, "tolerance"_a, DOC(Bentley, Geom, ClipPlane, IsPointOn));

    c1.def("GetDPlane3d", &ClipPlane::GetDPlane3d, DOC(Bentley, Geom, ClipPlane, GetDPlane3d));
    
    c1.def("GetLocalToWorldTransform", 
           py::overload_cast<bool>(&ClipPlane::GetLocalToWorldTransform, py::const_), 
           "zPointsOut"_a = false, DOC(Bentley, Geom, ClipPlane, GetLocalToWorldTransform));

    c1.def("GetLocalToWorldTransform", 
           py::overload_cast<TransformR, TransformR, bool>(&ClipPlane::GetLocalToWorldTransform, py::const_), 
           "localToWorld"_a, "worldToLocal"_a, "zPointsOut"_a = false, DOC(Bentley, Geom, ClipPlane, GetLocalToWorldTransform));

    c1.def_property("DPlane4d", &ClipPlane::GetDPlane4d, &ClipPlane::SetDPlane4d);
    c1.def("GetDPlane4d", &ClipPlane::GetDPlane4d, DOC(Bentley, Geom, ClipPlane, GetDPlane4d));
    c1.def("SetDPlane4d", &ClipPlane::SetDPlane4d, "plane"_a);
    
    c1.def("BoundedSegmentHasSimpleIntersection", [] (ClipPlaneCR self, DPoint3dCR pointA, DPoint3dCR pointB)
          {
          double fraction = 0;
          bool bOn = self.BoundedSegmentHasSimpleIntersection(pointA, pointB, fraction);
          return py::make_tuple(bOn, fraction);
          }, "pointA"_a, "pointB"_a, DOC(Bentley, Geom, ClipPlane, BoundedSegmentHasSimpleIntersection));

    c1.def("TransformInPlace", &ClipPlane::TransformInPlace, "transform"_a, DOC(Bentley, Geom, ClipPlane, TransformInPlace));
    c1.def("MultiplyPlaneTimesMatrix", &ClipPlane::MultiplyPlaneTimesMatrix, "matrix"_a, DOC(Bentley, Geom, ClipPlane, MultiplyPlaneTimesMatrix));    
    c1.def("Negate", &ClipPlane::Negate, DOC(Bentley, Geom, ClipPlane, Negate));

    c1.def("ConvexPolygonClipInPlace", py::overload_cast<DPoint3dArray&, DPoint3dArray&, int>(&ClipPlane::ConvexPolygonClipInPlace, py::const_), "xyz"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));
    c1.def("ConvexPolygonClipInPlace", py::overload_cast<DPoint3dArray&, DPoint3dArray&>(&ClipPlane::ConvexPolygonClipInPlace, py::const_), "xyz"_a, "work"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("ConvexPolygonClipInPlace", [](ClipPlaneCR self, py::list& xyz, py::list const& work, int onPlaneHandling)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppwork, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClipInPlace(cppxyz, cppwork, onPlaneHandling);
        CONVERT_CPPARRAY_TO_PYLIST(xyz, cppxyz, DPoint3dArray, DPoint3d);
        }, "xyz"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("ConvexPolygonClipInPlace", [](ClipPlaneCR self, DPoint3dArray& xyz, py::list const& work, int onPlaneHandling)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppwork, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClipInPlace(xyz, cppwork, onPlaneHandling);
        }, "xyz"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("ConvexPolygonClipInPlace", [](ClipPlaneCR self, py::list& xyz, DPoint3dArray& work, int onPlaneHandling)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClipInPlace(cppxyz, work, onPlaneHandling);
        CONVERT_CPPARRAY_TO_PYLIST(xyz, cppxyz, DPoint3dArray, DPoint3d);
        }, "xyz"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("ConvexPolygonClipInPlace", [](ClipPlaneCR self, py::list& xyz, py::list const& work)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppwork, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClipInPlace(cppxyz, cppwork);
        CONVERT_CPPARRAY_TO_PYLIST(xyz, cppxyz, DPoint3dArray, DPoint3d);
        },"xyz"_a, "work"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("ConvexPolygonClipInPlace", [](ClipPlaneCR self, DPoint3dArray& xyz, py::list const& work)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppwork, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClipInPlace(xyz, cppwork);
        },"xyz"_a, "work"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("ConvexPolygonClipInPlace", [](ClipPlaneCR self, py::list& xyz, DPoint3dArray& work)
        {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(xyz, cppxyz, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClipInPlace(cppxyz, work);
        CONVERT_CPPARRAY_TO_PYLIST(xyz, cppxyz, DPoint3dArray, DPoint3d);
        },"xyz"_a, "work"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonClipInPlace));

    c1.def("PolygonCrossings", &ClipPlane::PolygonCrossings, "xyz"_a, "crossings"_a, DOC(Bentley, Geom, ClipPlane, PolygonCrossings));

    c1.def("SimpleIntersectionFractions", [] (ClipPlaneCR self, DEllipse3dCR arc, bool bounded)
          {
          double fractions[2];
          py::tuple outVal;
          int nItem = self.SimpleIntersectionFractions(arc, fractions, bounded);
          if (nItem == 1)
              outVal = py::make_tuple(fractions[0]);
          if (nItem == 2)
              outVal = py::make_tuple(fractions[0], fractions[1]);

          return outVal;
          }, "arc"_a, "bounded"_a);

    c1.def("ConvexPolygonSplitInsideOutside", &ClipPlane::ConvexPolygonSplitInsideOutside, "xyz"_a, "xyzIn"_a, "xyzOut"_a, "altitudeRange"_a, DOC(Bentley, Geom, ClipPlane, ConvexPolygonSplitInsideOutside));

    c1.def("OffsetDistance", &ClipPlane::OffsetDistance, "distance"_a, DOC(Bentley, Geom, ClipPlane, OffsetDistance));
    
    c1.def_static("FindPointOnBothPlanes", &ClipPlane::FindPointOnBothPlanes, "data"_a, "plane0"_a, "plane1"_a, "tolerance"_a, DOC(Bentley, Geom, ClipPlane, FindPointOnBothPlanes));
    c1.def_static("GetEvaluationCount", &ClipPlane::GetEvaluationCount, "clear"_a = false);
    c1.def_static("ClipPlaneToRange", &ClipPlane::ClipPlaneToRange, "range"_a, "plane"_a, "clippedPoints"_a, "largeRectangle"_a = nullptr, DOC(Bentley, Geom, ClipPlane, ClipPlaneToRange));

    c1.def("__repr__", [] (ClipPlane& self)
           {
           return "(Normal:[{},{},{}], Distance:{}, IsVisible:{}, IsInterior:{})"_s
               .format(self.GetNormal().x, self.GetNormal().y, self.GetNormal().z, self.GetDistance(), self.IsVisible(), self.GetIsInterior());
           });
    }