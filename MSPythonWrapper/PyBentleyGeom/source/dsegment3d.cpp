/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dsegment3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Pybind11/numpy.h>


static const char * __doc_Bentley_Geom_DSegment3d_IntersectXY =R"doc(Return the (simple, single point) intersection of two (unbounded)
segments as viewed in XY. (z coordinates of the outputs pointA and
pointB may differ)

:param (output):
    fractionA fractional position on segmentA

:param (output):
    fractionB fractional position on segmentB

:param (output):
    pointA point on segmentA

:param (output):
    pointB point on segmentB

:param (input):
    segmentA first line segment.

:param (input):
    segmentB second line segment.

:returns:
    false if segments are parallel.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ClosestApproachBoundedXY =R"doc(Find the closest approach of two bounded segments, considering only xy
parts of distance

:param (output):
    fraction0 parameter on first segment

:param (output):
    fraction1 parameter on second segment

:param (output):
    point0 point on first ray.

:param (output):
    point1 point on second ray.

:param (output):
    segment0 first segment

:param (output):
    segment1 second segment)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ClosestApproachUnbounded =R"doc(Find the closest approach of two unbounded segments

:param (output):
    fraction0 parameter on first segment.

:param (output):
    fraction1 parameter on second segment.

:param (output):
    point0 point on first ray.

:param (output):
    point1 point on second ray.

:param (output):
    segment0 first segment

:param (output):
    segment1 second segment

:returns:
    false if parallel segments)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ClosestApproachBounded =R"doc(Find the closest approach of two bounded segments

:param (output):
    fraction0 parameter on first segment.

:param (output):
    fraction1 parameter on second segment.

:param (output):
    point0 point on first ray.

:param (output):
    point1 point on second ray.

:param (output):
    segment0 first segment

:param (output):
    segment1 second segment)doc";

static const char * __doc_Bentley_Geom_DSegment3d_WireCentroid =R"doc(Compute the length (unit density) and wire centroid. Note that a zero
length line has zero length but the (single) coordinate is a well
defined centroid.

:param (output):
    length line length.

:param (output):
    centroid centroid point.

:param (input):
    fraction0 start fraction for interval to measure.

:param (input):
    fraction1 end fraction for interval to measure.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ClosestPointBoundedXY =R"doc(Find the closest point (projection or end), as viewed in xy plane,
after applying optional transformation.

:param (output):
    closePoint closest point, in coordinates of the input segment.

:param (output):
    closeParam parameter at closest point

:param (output):
    distanceXY distance in transformed coordinates

:param (input):
    spacePoint world coordinates of test point.

:param (input):
    worldToLocal optional transformation.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_LengthToFraction =R"doc(Compute the fraction parameter corresponding to a specified arc length
away from a specified start fraction. (inverse of fractions to
arcStep)

:param (output):
    fraction1 fraction at end of interval.

:param (input):
    fraction0 start fraction for interval to measure.

:param (input):
    arcStep arc length to move. Negative arc length moves backwards.

:returns:
    true if the fractional step was computed.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_FractionToLength =R"doc(Compute the (signed) arc length between specified fractional
parameters.

:param (output):
    arcLength computed arc length. Negative if fraction1<fraction0.

:param (input):
    fraction0 start fraction for interval to measure.

:param (input):
    fraction1 end fraction for interval to measure.

:returns:
    true if the arc length was computed.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_Length =R"doc(:returns:
    line segment length.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_InterpolateUniformArray =R"doc(Computes equidistant points along the segment.

:param (output):
    points array of computed points

:param (input):
    numPoints # points to compute.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_SetPoint =R"doc(:param (output):
    pt returned point.

:param (input):
    index index of point to return.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_GetPoint =R"doc(:param (output):
    pt returned point.

:param (input):
    index index of point to return.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_FractionParameterToTangent =R"doc(:param (output):
    point point on line at fractional parameter.

:param (output):
    tangent tangent vector at fractional parameter.

:param (input):
    param fractional parameter.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_PointToFractionParameter =R"doc( Returns the parameter at which a point projects to the
*unbounded) line containing the segment. Parameters less than zero and
greater than one mean the projection is outside the bounds of the line
segment.

:param (output):
    param fraction where point projects to the line.

:param (input):
    point point to project to the line.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_FractionToPoint =R"doc(:returns:
    point coordinates at fractional parameter.

:param (input):
    fraction fractional parameter)doc";

static const char * __doc_Bentley_Geom_DSegment3d_FractionParameterToPoint =R"doc(:param (output):
    point coordinates at fractional parameter.

:param (input):
    param fractional parameter

Remark:
    This is a deprecated form of FractionToPoint.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_SetEndPoint =R"doc(Set the " end " point for the line segment.

:param point:
    new end point.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_GetEndPoint =R"doc(Get end point from the line segment.

:param (output):
    pt end point of object.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_SetStartPoint =R"doc(Set the " start " point for the line segment.

:param point:
    new start point.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_GetStartPoint =R"doc(Get start point from the line segment.

:param (output):
    pt start point of object.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_Intersect =R"doc(Return the intersection of the (unbounded) segment with a plane.

:param (input):
    intPoint intersection point

:param (input):
    intParam parameter along the line

:param (input):
    plane plane (origin and normal)

:returns:
    false if line, plane are parallel.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ProjectPointBounded =R"doc(Project a point onto the bounded line in 3D. If nearest point of
extended line is outside the 0..1 parameter range, returned values are
optinally restricted to nearest endpoint.

:param (output):
    closestPoint point on extended line

:param (output):
    closestParam parameter for closest point

:param (input):
    point space point.

:param (input):
    extend0 true to extend backwards before 0

:param (input):
    extend1 true to extend forwards from 1)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ProjectPointXY =R"doc(Project a point onto the extended line using only xy parts.

:param (output):
    closestPoint point on extended line

:param (output):
    closestParam parameter for closest point

:param (input):
    point space point.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ProjectPoint =R"doc(Project a point onto the extended line in 3D.

:param (output):
    closestPoint point on extended line

:param (output):
    closestParam parameter for closest point

:param (input):
    point space point.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_ProjectedParameterRange =R"doc(:returns:
    range when projected to fraction space of the ray

:param (input):
    ray)doc";

static const char * __doc_Bentley_Geom_DSegment3d_GetRange =R"doc(:param (output):
    range range of segment.

:returns:
    always true)doc";

static const char * __doc_Bentley_Geom_DSegment3d_IsAlmostSinglePoint =R"doc(:returns:
    true if endpoint are AlmostEqual())doc";

static const char * __doc_Bentley_Geom_DSegment3d_IsSinglePoint =R"doc(:returns:
    true if endpoint are identical (bitwise))doc";

static const char * __doc_Bentley_Geom_DSegment3d_IsAlmostEqual =R"doc(:returns:
    true if AlmostEqual endpoints)doc";

static const char * __doc_Bentley_Geom_DSegment3d_LengthSquared =R"doc(:returns:
    squared length of the segment.)doc";

static const char * __doc_Bentley_Geom_DSegment3d_GetEndPoints =R"doc(Return the endpoints of the segment.

:param (output):
    point0 start point

:param (output):
    point1 end point)doc";

static const char * __doc_Bentley_Geom_DSegment3d_InitProduct =R"doc( initialize as transform of other segment.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DSegment3d(py::module_& m)
    {
    //===================================================================================
    // struct DSegment3d
    py::class_<DSegment3d> c1(m, "DSegment3d");
    py::bind_vector<DSegment3dArray>(m, "DSegment3dArray", py::module_local(false));
    bind_ValidatedValue<DSegment3d>(m, "ValidatedDSegment3d", py::module_local(false));

    c1.def_property("point",
        [](DSegment3dR self)
        {
        DPoint3d ptSt;
        self.GetStartPoint(ptSt);

        DPoint3d ptEnd;
        self.GetEndPoint (ptEnd);

        return py::make_tuple (ptSt, ptEnd);

        //return points; //py::array_t<DPoint3d>{ 2, self.point, py::cast(self)};
        },
        [](DSegment3dR self, py::array_t<DPoint3d> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<DPoint3d*>(buf.ptr);

        if (2 != arr.size())
            return;

        memcpy(self.point, ptr, 2 * sizeof(DPoint3d));
        });

    c1.def(py::init(&DSegment3d::FromZero));
    c1.def(py::init(py::overload_cast<DRay3dCR>(&DSegment3d::From)), "ray"_a);
    c1.def(py::init(py::overload_cast<double, double, double, double, double, double>(&DSegment3d::From)), "x0"_a, "y0"_a, "z0"_a, "x1"_a, "y1"_a, "z1"_a);
    c1.def(py::init(py::overload_cast<DPoint2dCR, DPoint2dCR>(&DSegment3d::From)), "point0"_a, "point1"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, DPoint3dCR>(&DSegment3d::From)), "point0"_a, "point1"_a);
    c1.def(py::init(&DSegment3d::FromOriginAndDirection), "point0"_a, "tangent"_a);
    c1.def(py::init(py::overload_cast<DSegment3dCR, double, double>(&DSegment3d::FromFractionInterval)), "parent"_a, "startFraction"_a, "endFraction"_a);
    c1.def(py::init(py::overload_cast<DSegment3dCR, DSegment1dCR>(&DSegment3d::FromFractionInterval)), "parent"_a, "interval"_a);

    c1.def("Init", py::overload_cast<double, double, double, double, double, double>(&DSegment3d::Init), "x0"_a, "y0"_a, "z0"_a, "x1"_a, "y1"_a, "z1"_a);
    c1.def("Init", py::overload_cast<DPoint3dCR, DPoint3dCR>(&DSegment3d::Init), "point0"_a, "point1"_a);
    c1.def("Init", py::overload_cast<DPoint2dCR, DPoint2dCR>(&DSegment3d::Init), "point0"_a, "point1"_a);
    c1.def("InitFrom", &DSegment3d::InitFrom, "ray"_a);
    c1.def("InitFromOriginAndDirection", &DSegment3d::InitFromOriginAndDirection, "point0"_a, "tangent"_a);
    c1.def("InitProduct", &DSegment3d::InitProduct, "transform"_a, "other"_a, DOC(Bentley, Geom, DSegment3d, InitProduct));            
    c1.def("GetEndPoints", &DSegment3d::GetEndPoints, "point0"_a, "point1"_a, DOC(Bentley, Geom, DSegment3d, GetEndPoints));
    c1.def("LengthSquared", &DSegment3d::LengthSquared, DOC(Bentley, Geom, DSegment3d, LengthSquared));
    c1.def("IsAlmostEqual", &DSegment3d::IsAlmostEqual, "other"_a, "tolerance"_a, DOC(Bentley, Geom, DSegment3d, IsAlmostEqual));
    
    c1.def("IsSinglePoint", &DSegment3d::IsSinglePoint, DOC(Bentley, Geom, DSegment3d, IsSinglePoint));
    c1.def("IsAlmostSinglePoint", &DSegment3d::IsAlmostSinglePoint, DOC(Bentley, Geom, DSegment3d, IsAlmostSinglePoint));

    c1.def("GetRange", &DSegment3d::GetRange, "range"_a, DOC(Bentley, Geom, DSegment3d, GetRange));
    c1.def("ProjectedParameterRange", &DSegment3d::ProjectedParameterRange, "ray"_a, DOC(Bentley, Geom, DSegment3d, ProjectedParameterRange));

    c1.def("ProjectPoint", [] (DSegment3dCR self, DPoint3dCR point)
        {
        DPoint3d closestPoint = DPoint3d::FromZero();
        double closestParam = 0.0;
        bool bOk = self.ProjectPoint(closestPoint, closestParam, point);
        return py::make_tuple(bOk, closestPoint, closestParam);
        }, "point"_a, DOC(Bentley, Geom, DSegment3d, ProjectPoint));

    c1.def("ProjectPointXY", [] (DSegment3dCR self, DPoint3dCR point)
        {
        DPoint3d closestPoint = DPoint3d::FromZero();
        double closestParam = 0.0;
        bool bOk = self.ProjectPointXY(closestPoint, closestParam, point);
        return py::make_tuple(bOk, closestPoint, closestParam);
        }, "point"_a, DOC(Bentley, Geom, DSegment3d, ProjectPointXY));

    c1.def("ProjectPointBounded", [] (DSegment3dCR self, DPoint3dCR point)
        {
        DPoint3d closestPoint = DPoint3d::FromZero();
        double closestParam = 0.0;
        bool bOk = self.ProjectPointBounded(closestPoint, closestParam, point);
        return py::make_tuple(bOk, closestPoint, closestParam);
        }, "point"_a, DOC(Bentley, Geom, DSegment3d, ProjectPointBounded));

    c1.def("ProjectPointBounded", [] (DSegment3dCR self, DPoint3dCR point, bool extend0, bool extend1)
        {
        DPoint3d closestPoint = DPoint3d::FromZero();
        double closestParam = 0.0;
        bool bOk = self.ProjectPointBounded(closestPoint, closestParam, point, extend0, extend1);
        return py::make_tuple(bOk, closestPoint, closestParam);
        }, "point"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, DSegment3d, ProjectPointBounded));

    c1.def("Intersect", [] (DSegment3dCR self, DPlane3dCR plane)
        {
        DPoint3d intPoint = DPoint3d::FromZero();
        double intParam = 0.0;
        bool bOk = self.Intersect(intPoint, intParam, plane);
        return py::make_tuple(bOk, intPoint, intParam);
        }, "point"_a, DOC(Bentley, Geom, DSegment3d, Intersect));

    c1.def("IntersectCircleXY", [] (DSegment3dCR self, DPoint3dCR center, double radius)
        {
        DPoint3d intPoint[2];
        double intParam[2];
        py::list outVal;
        int nPnts = self.IntersectCircleXY(intPoint, intParam, center, radius);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(intPoint[i], intParam[i]);
            outVal.append(item);
            }

        return outVal;
        }, "center"_a, "radius"_a);

    c1.def_property("StartPoint",
                    [] (DSegment3d const& self) { DPoint3d pt; self.GetStartPoint(pt); return pt; },
                    [] (DSegment3d& self, DPoint3dCR pt) { self.SetStartPoint(pt); });
    c1.def("GetStartPoint", &DSegment3d::GetStartPoint, "pt"_a, DOC(Bentley, Geom, DSegment3d, GetStartPoint));
    c1.def("SetStartPoint", &DSegment3d::SetStartPoint, "point"_a, DOC(Bentley, Geom, DSegment3d, SetStartPoint));

    c1.def_property("EndPoint",
                    [] (DSegment3d const& self) { DPoint3d pt; self.GetEndPoint(pt); return pt; },
                    [] (DSegment3d& self, DPoint3dCR pt) { self.SetEndPoint(pt); });
    c1.def("GetEndPoint", &DSegment3d::GetEndPoint, "pt"_a, DOC(Bentley, Geom, DSegment3d, GetEndPoint));    
    c1.def("SetEndPoint", &DSegment3d::SetEndPoint, "point"_a, DOC(Bentley, Geom, DSegment3d, SetEndPoint));

    c1.def("FractionParameterToPoint", &DSegment3d::FractionParameterToPoint, "point"_a, "param"_a, DOC(Bentley, Geom, DSegment3d, FractionParameterToPoint));

    c1.def("FractionToPoint", &DSegment3d::FractionToPoint, "fraction"_a, DOC(Bentley, Geom, DSegment3d, FractionToPoint));

    c1.def("PointToFractionParameter", [] (DSegment3dCR self, DPoint3dCR point)
        {
        double param = 0.0;
        bool bOk = self.PointToFractionParameter(param, point);
        return py::make_tuple(bOk, param);
        }, "point"_a, DOC(Bentley, Geom, DSegment3d, PointToFractionParameter));

    c1.def("FractionParameterToTangent", &DSegment3d::FractionParameterToTangent, "point"_a, "tangent"_a, "param"_a, DOC(Bentley, Geom, DSegment3d, FractionParameterToTangent));

    c1.def("GetPoint", &DSegment3d::GetPoint, "pt"_a, "index"_a, DOC(Bentley, Geom, DSegment3d, GetPoint));

    c1.def("SetPoint", &DSegment3d::SetPoint, "pt"_a, "index"_a, DOC(Bentley, Geom, DSegment3d, SetPoint));

    c1.def("InterpolateUniformArray", &DSegment3d::InterpolateUniformArray, "points"_a, "numPoints"_a, DOC(Bentley, Geom, DSegment3d, InterpolateUniformArray));

    c1.def("Length", &DSegment3d::Length, DOC(Bentley, Geom, DSegment3d, Length));

    c1.def("FractionToLength", [] (DSegment3dCR self, double fraction0, double fraction1)
        {
        double arcLength = 0.0;
        bool bOk = self.FractionToLength(arcLength, fraction0, fraction1);
        return py::make_tuple(bOk, arcLength);
        }, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, DSegment3d, FractionToLength));

    c1.def("LengthToFraction", [] (DSegment3dCR self, double fraction0, double arcStep)
        {
        double fraction1 = 0.0;
        bool bOk = self.LengthToFraction(fraction1, fraction0, arcStep);
        return py::make_tuple(bOk, fraction1);
        }, "fraction0"_a, "arcStep"_a, DOC(Bentley, Geom, DSegment3d, LengthToFraction));

    c1.def("ClosestPointBoundedXY", [] (DSegment3dCR self, DPoint3dCR spacePoint, DMatrix4dCP worldToLocal)
        {
        DPoint3d closePoint = DPoint3d::FromZero();
        double closeParam = 0;
        double distanceXY = 0;
        bool bOk = self.ClosestPointBoundedXY(closePoint, closeParam, distanceXY, spacePoint, worldToLocal);
        return py::make_tuple(bOk, closePoint, closeParam, distanceXY);
        }, "spacePoint"_a, "worldToLocal"_a, DOC(Bentley, Geom, DSegment3d, ClosestPointBoundedXY));

    c1.def("ClosestPointBoundedXY", [] (DSegment3dCR self, DPoint3dCR spacePoint, DMatrix4dCP worldToLocal, bool extend0, bool extend1)
        {
        DPoint3d closePoint = DPoint3d::FromZero();
        double closeParam = 0;
        double distanceXY = 0;
        bool bOk = self.ClosestPointBoundedXY(closePoint, closeParam, distanceXY, spacePoint, worldToLocal, extend0, extend1);
        return py::make_tuple(bOk, closePoint, closeParam, distanceXY);
        }, "spacePoint"_a, "worldToLocal"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, DSegment3d, ClosestPointBoundedXY));

    c1.def("WireCentroid", [] (DSegment3dCR self, double fraction0, double fraction1)
        {
        DPoint3d centroid = DPoint3d::FromZero();
        double length = 0;
        self.WireCentroid(length, centroid, fraction0, fraction1);
        return py::make_tuple(length, centroid);
        }, "fraction0"_a = 0.0, "fraction1"_a = 1.0, DOC(Bentley, Geom, DSegment3d, WireCentroid));

    c1.def_static("ClosestApproachBounded", [] (DSegment3dCR segment0, DSegment3dCR segment1)
        {
        double fraction0 = 0;
        double fraction1 = 0;
        DPoint3d point0 = DPoint3d::FromZero();
        DPoint3d point1 = DPoint3d::FromZero();
        DSegment3d::ClosestApproachBounded(fraction0, fraction1, point0, point1, segment0, segment1);
        return py::make_tuple(fraction0, fraction1, point0, point1);
        }, "segment0"_a, "segment1"_a, DOC(Bentley, Geom, DSegment3d, ClosestApproachBounded));

    c1.def_static("ClosestApproachUnbounded", [] (DSegment3dCR segment0, DSegment3dCR segment1)
        {
        double fraction0 = 0;
        double fraction1 = 0;
        DPoint3d point0 = DPoint3d::FromZero();
        DPoint3d point1 = DPoint3d::FromZero();
        DSegment3d::ClosestApproachUnbounded(fraction0, fraction1, point0, point1, segment0, segment1);
        return py::make_tuple(fraction0, fraction1, point0, point1);
        }, "segment0"_a, "segment1"_a, DOC(Bentley, Geom, DSegment3d, ClosestApproachUnbounded));

    c1.def_static("ClosestApproachBoundedXY", [] (DSegment3dCR segment0, DSegment3dCR segment1)
        {
        double fraction0 = 0;
        double fraction1 = 0;
        DPoint3d point0 = DPoint3d::FromZero();
        DPoint3d point1 = DPoint3d::FromZero();
        DSegment3d::ClosestApproachBoundedXY(fraction0, fraction1, point0, point1, segment0, segment1);
        return py::make_tuple(fraction0, fraction1, point0, point1);
        }, "segment0"_a, "segment1"_a, DOC(Bentley, Geom, DSegment3d, ClosestApproachBoundedXY));

    c1.def_static("IntersectXY", [] (DSegment3dCR segment0, DSegment3dCR segment1)
        {
        double fraction0 = 0;
        double fraction1 = 0;
        DPoint3d point0 = DPoint3d::FromZero();
        DPoint3d point1 = DPoint3d::FromZero();
        bool bOk = DSegment3d::IntersectXY(fraction0, fraction1, point0, point1, segment0, segment1);
        return py::make_tuple(bOk, fraction0, fraction1, point0, point1);
        }, "segment0"_a, "segment1"_a, DOC(Bentley, Geom, DSegment3d, IntersectXY));

    c1.def("__repr__", [] (DSegment3dCR self)
           {
           DPoint3d p0, p1;
           self.GetEndPoints(p0, p1);
           return "(Start:{}, End:{})"_s.format(p0, p1);
           });

    c1.def("__copy__", [](const DSegment3d& self)
        {
        return DSegment3d(self);
        });
    }