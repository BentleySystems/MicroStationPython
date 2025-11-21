/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\clipplaneset.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/ClipPlaneSet.h>



static const char * __doc_Bentley_Geom_ClipPlaneSet_ClipAndMaskPlanarRegion =R"doc(Clip a planar region to the (optional) outsideClip. Subtract the
(optional) holeClip.

:param outsideClip:
    (input) optional outer clip

:param holeClip:
    (input) optional hole clip

:param planarRegion:
    A CurveVector of type Loop or ParityRegion.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClipPlanarRegion =R"doc(Clip a planar region to this ClipPlaneset

:param planarRegion:
    (input) A CurveVector of type Loop or ParityRegion.

:param localToWorld:
    (output) transform from the plane of the planarRegion to world

:param worldToLocal:
    (output) transform from world to the plane of the planarRegion)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_SweptPolygonClipPolyface =R"doc(Clip a polyface to a swept polygon. This produces side faces where the
sweep makes a closed cut. If the polyface is not closed, cut faces may
be produced where sections are closed loops.

:param polyface:
    (input) polyface to test

:param polygon:
    (input) polygon points.

:param sweepDirection:
    (input) sweep direction for the polygon.

:param constructNewFacetsOnClipSetPlanes:
    (input) true to construct new faces where clip planes are inside the
    facet.

:param inside:
    (output) (optional) " inside " parts

:param outside:
    (output) (optional) " outside " parts)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClipPlaneSetIntersectPolyface =R"doc(Clip a polyface to a a postive ClipPlaneSet. This produces cut faces
where the clipSet is inside the polyface. If the polyface is not
closed, cut faces may be produced where sections are closed loops.

:param polyface:
    (input) polyface to test

:param clipSet:
    (input) the positive clip set

:param constructNewFacetsOnClipSetPlanes:
    (input) true to construct new faces where clip planes are inside the
    facet.

:param inside:
    (output) (optional) " inside " parts

:param outside:
    (output) (optional) " outside " parts

:param distanceTolerance:
    (optional) if nonzero, this is the distance tolerance for various
    internal steps. It is recommended that callers with metric data
    pass DoubleOps::SmallMetricDistance ().)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClipToSetDifference =R"doc(Clip a polyface to a a postive ClipPlaneSet and a mask (hole)
ClipPlaneSet.

:param polyface:
    (input) polyface to test

:param clipSet:
    (input) the positive clip set

:param maskSet:
    (input) the negative (holes) clip set

:param inside:
    (output) (optional) " inside " parts

:param outside:
    (output) (optional) " outside " parts)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClassifyPolyfaceInSetDifference =R"doc(Determine if a Polyface is completely in, completely out, or mixed
with respect to a postive ClipPlaneSet and a mask (hole) ClipPlaneSet.

:param polyface:
    (input) polyface to test

:param clipSet:
    (input) the positive clip set

:param maskSet:
    (input) the negative (holes) clip set)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClassifyCurvePrimitiveInSetDifference =R"doc(Determine if a CurveVector is completely in, completely out, or mixed
with respect to a postive ClipPlaneSet and a mask (hole) ClipPlaneSet.

:param curve:
    (input) curve to test

:param clipSet:
    (input) the positive clip set

:param maskSet:
    (input) the negative (holes) clip set)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClassifyCurveVectorInSetDifference =R"doc(Determine if a CurveVector is completely in, completely out, or mixed
with respect to a postive ClipPlaneSet and a mask (hole) ClipPlaneSet.

:param curves:
    (input) curves or region to clip.

:param clipSet:
    (input) the positive clip set

:param maskSet:
    (input) the negative (holes) clip set

:param considerRegions:
    (input) if true, treat Outer, Inner, Parity, and Union regions as
    areas. If false, only consider boundaries.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_AppendCrossings =R"doc(Compute crossings of this ClipPlaneSet with curve primitives within a
CurveVector.

:param (input):
    curves candidate curves

:param (output):
    crossings detailed crossing data.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_AppendIntervals =R"doc(Enumerate the " in " intervals .. the array is NOT cleared)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_IsAnyPointInOrOn =R"doc(Clip a bounded line segment)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_GetRange =R"doc(Get range of this ClipPlaneSet.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_ClassifyPointContainment =R"doc(@description return a summary classification

* ClipPlaneContainment_StronglyInside All points are inside the plane
set

* ClipPlaneContainment_Ambiguous

* ClipPlaneContainment_StronglyOut Strongly out. All points are out,
and are all on one side of one of planes, so edges joining pairs of
points will always be out also.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_GetRayIntersection =R"doc(Get nearest intersect distance along ray.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_TestRayIntersect =R"doc(Test for intersection with ray.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_MultiplyPlanesTimesMatrix =R"doc(multiply plane coefficients times a DMatrix4d (such as the worldToNPC
matrix) multiply [ax,ay,az,aw] * matrix)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_TransformInPlace =R"doc(Transform each plane set.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_IsSphereInside =R"doc(Test if point is inside to supplied tolerance.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_IsPointOnOrInside =R"doc(Test if point is inside to supplied tolerance.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_IsPointInside =R"doc(Test if point is inside.)doc";

static const char * __doc_Bentley_Geom_ClipPlaneSet_FromSweptPolygon =R"doc(Create a (chain of) convex clippers for an (unbounded) polygon sweep
in given direction. polygon may have disconnects. default sweep
direction is Z)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_AppendCrossings =R"doc(Compute crossings of this set's planes with curve primitives within a
CurveVector.

:param (input):
    curves candidate curves

:param (output):
    crossings detailed crossing data.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_AppendIntervals =R"doc(Enumerate the " in " intervals .. the array is NOT cleared If the
intervals array is nullptr, returns true immediately when any interior
interval is found.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_ConvexPolygonClip =R"doc(Return the (polygon) of intersection)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_ReloadSweptConvexPolygon =R"doc(reinitialize to clip to a swept polygon. ul> li> 1 -- success, and the
sweep vector and polygon area normal have positive dot product li> -1
-- success, and the sweep vector and polygon area normal have negative
dot product ul> 0 -- failure - polygon normal is perpendicular to
sweep.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_GetRange =R"doc(Get range of this ConvexClipPlaneSet.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_MultiplyPlanesTimesMatrix =R"doc(multiply plane coefficients times a DMatrix4d (such as the worldToNPC
matrix) multiply [ax,ay,az,aw] * matrix)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_TransformInPlace =R"doc(Transform plane set.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_ClipPointsOnOrInside =R"doc(Clip points.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_ClassifyPointContainment =R"doc(@description return a summary classification

* ClipPlaneContainment_StronglyInside All points are inside the plane
set

* ClipPlaneContainment_Ambiguous

* ClipPlaneContainment_StronglyOut Strongly out. All points are out,
and are all on one side of one of planes, so edges joining pairs of
points will always be out also.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_Add =R"doc(Add the plane if it is valid.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_AddSweptPolyline =R"doc(Add space " to the left of a polyline ", with left determined by edges
and an upvector. ul> li>If teh polyline is closed, an orientation test
is done and the point order is reveresed if needed to be sure the
planes are oriented to enclose the space. li>For each edge of the
polyline, the primary plane has its primary outward normal as edge
vector cross up vector. li>The normal is then rotated by the tilt
angle towards the up vector. li>to close around a polygon, repeat the
first point at end. li>When closed, this correspondes to a CCW polygon
with the upVector pointing at the eye, and the volume expands behind
the polygon li> ul>)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_FromXYPolyLine =R"doc(Create clip plane set for regiosn to one side of a polyline. If
hiddenEdge is an empty array, all clips are marked as regular
clippers. The hiddenEdge array must contain a boolean (usual false)
for each point of the points array. If (true), clip output from that
intersections with that edge may be made invisible by some later
methods.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_ClipUnBoundedSegment =R"doc(Clip an unbounded line to this set of planes.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_ClipBoundedSegment =R"doc(Clip a (bounded) line segment to this set of planes.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_IsSphereInside =R"doc(Test if sphere is inside all planes.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_IsPointOnOrInside =R"doc(Test if point is inside all planes to supplied tolerance.)doc";

static const char * __doc_Bentley_Geom_ConvexClipPlaneSet_IsPointInside =R"doc(Test if point is inside all planes.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_ClipPlaneSet(py::module_& m)
    {
    //===================================================================================
    // Enum ClipPlaneContainment
    py::enum_<ClipPlaneContainment>(m, "ClipPlaneContainment", py::arithmetic())
        .value("eClipPlaneContainment_StronglyInside", ClipPlaneContainment::ClipPlaneContainment_StronglyInside)
        .value("eClipPlaneContainment_Ambiguous", ClipPlaneContainment::ClipPlaneContainment_Ambiguous)
        .value("eClipPlaneContainment_StronglyOutside", ClipPlaneContainment::ClipPlaneContainment_StronglyOutside)
        .export_values();

    //===================================================================================
    // struct ConvexClipPlaneSet
    py::class_<ConvexClipPlaneSet, T_ClipPlanes> c1(m, "ConvexClipPlaneSet");
    py::bind_vector<ConvexClipPlaneSetArray>(m, "ConvexClipPlaneSetArray", py::module_local(false));

    c1.def(py::init<>());
    c1.def(py::init<size_t>(), "n"_a);
    c1.def(py::init([] (T_ClipPlanes const& planes) { return new ConvexClipPlaneSet(&planes[0], planes.size()); }), "planes"_a);

    c1.def("IsPointInside", &ConvexClipPlaneSet::IsPointInside, "point"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, IsPointInside));
    c1.def("IsPointOnOrInside", &ConvexClipPlaneSet::IsPointOnOrInside, "point"_a, "tolerance"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, IsPointOnOrInside));    
    c1.def("IsSphereInside", &ConvexClipPlaneSet::IsSphereInside, "point"_a, "tolerance"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, IsSphereInside));
    
    c1.def("ClipBoundedSegment", [] (ConvexClipPlaneSetCR self, DPoint3dCR pointA, DPoint3dCR pointB, double planeSign)
          {
          double fraction0, fraction1;
          py::tuple outVal;
          if (self.ClipBoundedSegment(pointA, pointB, fraction0, fraction1, planeSign))
              outVal = py::cast(std::make_tuple(fraction0, fraction1));

          return outVal;
          }, "pointA"_a, "pointB"_a, "planeSign"_a = 1.0, DOC(Bentley, Geom, ConvexClipPlaneSet, ClipBoundedSegment));

    c1.def("ClipUnBoundedSegment", [] (ConvexClipPlaneSetCR self, DPoint3dCR pointA, DPoint3dCR pointB, double planeSign)
          {
          double fraction0, fraction1;
          py::tuple outVal;
          if (self.ClipUnBoundedSegment(pointA, pointB, fraction0, fraction1, planeSign))
              outVal = py::cast(std::make_tuple(fraction0, fraction1));

          return outVal;
          }, "pointA"_a, "pointB"_a, "planeSign"_a = 1.0, DOC(Bentley, Geom, ConvexClipPlaneSet, ClipUnBoundedSegment));

    c1.def_static("FromXYPolyLine", &ConvexClipPlaneSet::FromXYPolyLine, "points"_a, "hiddenEdge"_a, "leftIsInside"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, FromXYPolyLine));
    c1.def("AddSweptPolyline", &ConvexClipPlaneSet::AddSweptPolyline, "points"_a, "upVector"_a, "tiltAngle"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, AddSweptPolyline));    
    c1.def("Add", &ConvexClipPlaneSet::Add, "plane"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, Add));

    c1.def("ClassifyPointContainment", [] (ConvexClipPlaneSetCR self, std::vector<DPoint3d> const& points, bool onIsOutside)
          {
          return self.ClassifyPointContainment(points.data(), points.size(), onIsOutside);
          }, "points"_a, "onIsOutsize"_a = false, DOC(Bentley, Geom, ConvexClipPlaneSet, ClassifyPointContainment));

    c1.def("ClipPointsOnOrInside", &ConvexClipPlaneSet::ClipPointsOnOrInside, "points"_a, "inOrOn"_a, "out"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ClipPointsOnOrInside));
    c1.def("TransformInPlace", &ConvexClipPlaneSet::TransformInPlace, "transform"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, TransformInPlace));
    c1.def("MultiplyPlanesTimesMatrix", &ConvexClipPlaneSet::MultiplyPlanesTimesMatrix, "matrix"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, MultiplyPlanesTimesMatrix));
    c1.def("GetRange", &ConvexClipPlaneSet::GetRange, "range"_a, "transform"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, GetRange));
    c1.def("ReloadSweptConvexPolygon", &ConvexClipPlaneSet::ReloadSweptConvexPolygon, "points"_a, "sweepDirection"_a, "sideSelect"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ReloadSweptConvexPolygon));

    c1.def("ConvexPolygonClip", py::overload_cast<DPoint3dArray const&, DPoint3dArray&, DPoint3dArray&>(&ConvexClipPlaneSet::ConvexPolygonClip, py::const_), "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, py::list &output, py::list &work)
    {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClip(cppInput, cppOutput, cppWork);
        CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d);
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, py::list &output, DPoint3dArray &work)
    {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClip(cppInput, cppOutput, work);
        CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d);
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, DPoint3dArray &output, py::list &work)
    {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClip(cppInput, output, cppWork);
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, DPoint3dArray const &input, py::list &output, py::list &work)
    {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
           self.ConvexPolygonClip(input, cppOutput, cppWork);
           CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d); 
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, DPoint3dArray const &input, DPoint3dArray &output, py::list &work)
    {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
            self.ConvexPolygonClip(input, output, cppWork); 
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, DPoint3dArray const &input, py::list &output, DPoint3dArray &work)
    {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
            self.ConvexPolygonClip(input, cppOutput, work);
            CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d); 
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, DPoint3dArray &output, DPoint3dArray &work)
    {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
            self.ConvexPolygonClip(cppInput, output, work); 
    }, "input"_a, "output"_a, "work"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", py::overload_cast<DPoint3dArray const&, DPoint3dArray&, DPoint3dArray&, int>(&ConvexClipPlaneSet::ConvexPolygonClip, py::const_), "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, py::list &output, py::list &work, int onPlaneHandling)
    {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClip(cppInput, cppOutput, cppWork, onPlaneHandling);
        CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d);
    }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, py::list &output, DPoint3dArray &work, int onPlaneHandling)
    {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClip(cppInput, cppOutput, work, onPlaneHandling);
        CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d);
    }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, DPoint3dArray &output, py::list &work, int onPlaneHandling)
    {
        CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
        self.ConvexPolygonClip(cppInput, output, cppWork, onPlaneHandling);
    }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, DPoint3dArray const &input, py::list &output, py::list &work, int onPlaneHandling)
    {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
           CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
           self.ConvexPolygonClip(input, cppOutput, cppWork, onPlaneHandling);
           CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d); }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, DPoint3dArray const &input, DPoint3dArray &output, py::list &work, int onPlaneHandling)
    {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(work, cppWork, DPoint3dArray, DPoint3d);
            self.ConvexPolygonClip(input, output, cppWork, onPlaneHandling); }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, DPoint3dArray const &input, py::list &output, DPoint3dArray &work, int onPlaneHandling)
    {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(output, cppOutput, DPoint3dArray, DPoint3d);
            self.ConvexPolygonClip(input, cppOutput, work, onPlaneHandling);
            CONVERT_CPPARRAY_TO_PYLIST(output, cppOutput, DPoint3dArray, DPoint3d); }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("ConvexPolygonClip", [](ConvexClipPlaneSetCR self, py::list const &input, DPoint3dArray &output, DPoint3dArray &work, int onPlaneHandling)
    {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(input, cppInput, DPoint3dArray, DPoint3d);
            self.ConvexPolygonClip(cppInput, output, work, onPlaneHandling); }, "input"_a, "output"_a, "work"_a, "onPlaneHandling"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, ConvexPolygonClip));

    c1.def("AppendIntervals", py::overload_cast<DEllipse3dCR, DSegment1dArray*, double>(&ConvexClipPlaneSet::AppendIntervals, py::const_), "arc"_a, "intervals"_a, "planeSign"_a = 1.0, DOC(Bentley, Geom, ConvexClipPlaneSet, AppendIntervals));

    c1.def("AppendIntervals", [](ConvexClipPlaneSetCR self, DEllipse3dCR arc, py::list intervals, double planeSign = 1.0){
           CONVERT_PYLIST_TO_NEW_CPPARRAY(intervals, cppIntervals, DSegment1dArray, DSegment1d);
           bool isIntervals = self.AppendIntervals(arc, &cppIntervals, planeSign);
           CONVERT_CPPARRAY_TO_PYLIST(intervals, cppIntervals, DSegment1dArray, DSegment1d);
           return isIntervals;
    }, "arc"_a, "intervals"_a, "planeSign"_a = 1.0, DOC(Bentley, Geom, ConvexClipPlaneSet, AppendIntervals));

    c1.def("AppendIntervals", py::overload_cast<MSBsplineCurveCR, DSegment1dArray*>(&ConvexClipPlaneSet::AppendIntervals, py::const_), "curve"_a, "intervals"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, AppendIntervals));

    c1.def("AppendIntervals", [](ConvexClipPlaneSetCR self, MSBsplineCurveCR curve, py::list intervals){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(intervals, cppIntervals, DSegment1dArray, DSegment1d);
        bool isIntervals = self.AppendIntervals(curve, &cppIntervals);
        CONVERT_CPPARRAY_TO_PYLIST(intervals, cppIntervals, DSegment1dArray, DSegment1d);
        return isIntervals;
    }, "curve"_a, "intervals"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, AppendIntervals));

    c1.def("AppendCrossings", py::overload_cast<CurveVectorCR, bvector<CurveLocationDetailPair>&>(&ConvexClipPlaneSet::AppendCrossings, py::const_), "curves"_a, "crossings"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, AppendCrossings));
    c1.def("AppendCrossings", py::overload_cast<ICurvePrimitiveCR, bvector<CurveLocationDetailPair>&>(&ConvexClipPlaneSet::AppendCrossings, py::const_), "curve"_a, "crossings"_a, DOC(Bentley, Geom, ConvexClipPlaneSet, AppendCrossings));

    c1.def("__repr__", [] (ConvexClipPlaneSet& self)
           {
           std::ostringstream os;
           os << "[" << std::endl;
           for (size_t i=0; i<self.size(); i++)
               {
               auto& item = self[i];
               os << py::str(py::cast(item)).cast<std::string>();
               if (i != self.size() - 1)
                   os << ",";
               os << std::endl;
               }
           os << "]" << std::endl;

           return os.str().c_str();
           });

    //===================================================================================
    // struct ClipPlaneSet
    py::class_<ClipPlaneSet, ConvexClipPlaneSetArray> c2(m, "ClipPlaneSet");

    c2.def(py::init<>());
    c2.def(py::init([] (T_ClipPlanes const& planes) { return new ClipPlaneSet(&planes[0], planes.size()); }), "planes"_a);    
    c2.def(py::init<ConvexClipPlaneSetCR>(), "convexSet"_a);

    c2.def_static("FromSweptPolygon", [] (DPoint3dArray const& points, DVec3dCP direction)
                  {
                  return ClipPlaneSet::FromSweptPolygon(&points[0], points.size(), direction);
                  }, "points"_a, "direction"_a = nullptr, DOC(Bentley, Geom, ClipPlaneSet, FromSweptPolygon));

    c2.def_static("FromSweptPolygon", [] (py::list const& points, DVec3dCP direction)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint3dArray, DPoint3d);
                  return ClipPlaneSet::FromSweptPolygon(&cpppoints[0], cpppoints.size(), direction);
                  }, "points"_a, "direction"_a = nullptr, DOC(Bentley, Geom, ClipPlaneSet, FromSweptPolygon));

    c2.def("IsPointInside", &ClipPlaneSet::IsPointInside, "point"_a, DOC(Bentley, Geom, ClipPlaneSet, IsPointInside));
    c2.def("IsPointOnOrInside", &ClipPlaneSet::IsPointOnOrInside, "point"_a, "tolerance"_a, DOC(Bentley, Geom, ClipPlaneSet, IsPointOnOrInside));
    c2.def("IsSphereInside", &ClipPlaneSet::IsSphereInside, "point"_a, "radius"_a, DOC(Bentley, Geom, ClipPlaneSet, IsSphereInside));

    c2.def("TransformInPlace", &ClipPlaneSet::TransformInPlace, "transform"_a, DOC(Bentley, Geom, ClipPlaneSet, TransformInPlace));
    c2.def("MultiplyPlanesTimesMatrix", &ClipPlaneSet::MultiplyPlanesTimesMatrix, "matrix"_a, DOC(Bentley, Geom, ClipPlaneSet, MultiplyPlanesTimesMatrix));

    c2.def("TestRayIntersect", &ClipPlaneSet::TestRayIntersect, "point"_a, "direction"_a, DOC(Bentley, Geom, ClipPlaneSet, TestRayIntersect));
    c2.def("GetRayIntersection", [] (ClipPlaneSetCR self, DPoint3dCR point, DVec3dCR direction)
           {
           double tNear = 0.0;
           bool bOk = self.GetRayIntersection(tNear, point, direction);
           return py::make_tuple(bOk, tNear);
           }, "point"_a, "direction"_a, DOC(Bentley, Geom, ClipPlaneSet, GetRayIntersection));


    c2.def("ClassifyPointContainment", [] (ClipPlaneSetCR self, std::vector<DPoint3d> const& points, bool onIsOutside)
           {
           return self.ClassifyPointContainment(points.data(), points.size(), onIsOutside);
           }, "points"_a, "onIsOutsize"_a = false, DOC(Bentley, Geom, ClipPlaneSet, ClassifyPointContainment));

    c2.def("GetRange", &ClipPlaneSet::GetRange, "range"_a, "transform"_a, DOC(Bentley, Geom, ClipPlaneSet, GetRange));

    c2.def("IsAnyPointInOrOn", py::overload_cast<DSegment3dCR>(&ClipPlaneSet::IsAnyPointInOrOn, py::const_), "segment"_a, DOC(Bentley, Geom, ClipPlaneSet, IsAnyPointInOrOn));
    c2.def("IsAnyPointInOrOn", py::overload_cast<DEllipse3dCR>(&ClipPlaneSet::IsAnyPointInOrOn, py::const_), "arc"_a, DOC(Bentley, Geom, ClipPlaneSet, IsAnyPointInOrOn));
    c2.def("IsAnyPointInOrOn", py::overload_cast<MSBsplineCurveCR>(&ClipPlaneSet::IsAnyPointInOrOn, py::const_), "curve"_a, DOC(Bentley, Geom, ClipPlaneSet, IsAnyPointInOrOn));

    c2.def("AppendIntervals", py::overload_cast<DSegment3dCR, DSegment1dArray&>(&ClipPlaneSet::AppendIntervals, py::const_), "segment"_a, "intervals"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendIntervals));
   
    c2.def("AppendIntervals", [](ClipPlaneSetCR self, DSegment3dCR segment, py::list& intervals){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(intervals, cppIntervals, DSegment1dArray, DSegment1d);
        self.AppendIntervals(segment, cppIntervals);
        CONVERT_CPPARRAY_TO_PYLIST(intervals, cppIntervals, DSegment1dArray, DSegment1d);
    }, "segment"_a, "intervals"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendIntervals));

    c2.def("AppendIntervals", py::overload_cast<DEllipse3dCR, DSegment1dArray&>(&ClipPlaneSet::AppendIntervals, py::const_), "arc"_a, "intervals"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendIntervals));

    c2.def("AppendIntervals", [](ClipPlaneSetCR self, DEllipse3dCR arc, py::list& intervals){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(intervals, cppIntervals, DSegment1dArray, DSegment1d);
        self.AppendIntervals(arc, cppIntervals);
        CONVERT_CPPARRAY_TO_PYLIST(intervals, cppIntervals, DSegment1dArray, DSegment1d); }, "arc"_a, "intervals"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendIntervals));

    c2.def("AppendIntervals", py::overload_cast<MSBsplineCurveCR, DSegment1dArray&>(&ClipPlaneSet::AppendIntervals, py::const_), "curve"_a, "intervals"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendIntervals));

    c2.def("AppendIntervals", [](ClipPlaneSetCR self, MSBsplineCurveCR curve, py::list& intervals){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(intervals, cppIntervals, DSegment1dArray, DSegment1d);
        self.AppendIntervals(curve, cppIntervals);
        CONVERT_CPPARRAY_TO_PYLIST(intervals, cppIntervals, DSegment1dArray, DSegment1d); }, "curve"_a, "intervals"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendIntervals));

    c2.def("AppendCrossings", py::overload_cast<CurveVectorCR, bvector<CurveLocationDetailPair>&>(&ClipPlaneSet::AppendCrossings, py::const_), "curves"_a, "crossings"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendCrossings));
    c2.def("AppendCrossings", py::overload_cast<ICurvePrimitiveCR, bvector<CurveLocationDetailPair>&>(&ClipPlaneSet::AppendCrossings, py::const_), "curve"_a, "crossings"_a, DOC(Bentley, Geom, ClipPlaneSet, AppendCrossings));
        
    c2.def_static("ClassifyCurveVectorInSetDifference", &ClipPlaneSet::ClassifyCurveVectorInSetDifference, "curves"_a, "clipSet"_a, "maskSet"_a, "considerRegions"_a, DOC(Bentley, Geom, ClipPlaneSet, ClassifyCurveVectorInSetDifference));        
    c2.def_static("ClassifyCurvePrimitiveInSetDifference", &ClipPlaneSet::ClassifyCurvePrimitiveInSetDifference, "curve"_a, "clipSet"_a, "maskSet"_a, DOC(Bentley, Geom, ClipPlaneSet, ClassifyCurvePrimitiveInSetDifference));
    c2.def_static("ClassifyPolyfaceInSetDifference", &ClipPlaneSet::ClassifyPolyfaceInSetDifference, "polyface"_a, "clipSet"_a, "maskSet"_a, DOC(Bentley, Geom, ClipPlaneSet, ClassifyPolyfaceInSetDifference));

    c2.def_static("ClipToSetDifference", [] (PolyfaceQueryCR polyface, ClipPlaneSetCR clipSet, ClipPlaneSetCP maskSet)
                  {
                  PolyfaceHeaderPtr inside, outside;
                  ClipPlaneSet::ClipToSetDifference(polyface, clipSet, maskSet, &inside, &outside);
                  return py::make_tuple(inside, outside);
                  }, "polyface"_a, "clipSet"_a, "maskSet"_a, DOC(Bentley, Geom, ClipPlaneSet, ClipToSetDifference));

    c2.def_static("ClipPlaneSetIntersectPolyface", [] (PolyfaceQueryCR polyface, ClipPlaneSetCR clipSet, bool constructNewFacetsOnClipSetPlanes)
                  {
                  PolyfaceHeaderPtr inside, outside;
                  ClipPlaneSet::ClipPlaneSetIntersectPolyface(polyface, clipSet, constructNewFacetsOnClipSetPlanes, &inside, &outside);
                  return py::make_tuple(inside, outside);
                  }, "polyface"_a, "clipSet"_a, "constructNewFacetsOnClipSetPlanes"_a, DOC(Bentley, Geom, ClipPlaneSet, ClipPlaneSetIntersectPolyface));

    c2.def_static("SweptPolygonClipPolyface", [](PolyfaceQueryCR polyface, bvector<DPoint3d>& polygon, DVec3dCR sweepDirection, bool constructNewFacetsOnClipSetPlanes)
                  {
                  PolyfaceHeaderPtr inside, outside;
                  ClipPlaneSet::SweptPolygonClipPolyface(polyface, polygon, sweepDirection, constructNewFacetsOnClipSetPlanes, &inside, &outside);
                  return py::make_tuple(inside, outside);
                  }, "polyface"_a, "polygon"_a, "sweepDirection"_a, "constructNewFacetsOnClipSetPlanes"_a, DOC(Bentley, Geom, ClipPlaneSet, SweptPolygonClipPolyface));

    c2.def("ClipPlanarRegion", &ClipPlaneSet::ClipPlanarRegion, "planarRegion"_a, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, ClipPlaneSet, ClipPlanarRegion));    
    c2.def_static("ClipAndMaskPlanarRegion", &ClipPlaneSet::ClipAndMaskPlanarRegion, "outsideClip"_a, "holeClip"_a, "planarRegion"_a, DOC(Bentley, Geom, ClipPlaneSet, ClipAndMaskPlanarRegion));
    }