/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dray3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DRay3d_IntersectZPlane =R"doc(Return the intersection of this ray with a specified z plane of a
coordinate frame.

:param (input):
    frame coordinate frame, e.g. often called localWorldFrame for an
    object

:param (input):
    localZ z coordinate in local frame (e.g. 0 for local xy plane
    pierce point.)

:param (output):
    uvw local uvw coordinates. (w matches input z)

:param (output):
    t parameter along ray.

:returns:
    true if the ray is not parallel to the plane)doc";

static const char * __doc_Bentley_Geom_DRay3d_Intersect =R"doc(Return the intersection of the (unbounded) ray with a plane.

:param (output):
    intPoint intersection point

:param (output):
    intParam parameter along the ray

:param (input):
    plane plane (origin and normal)

:returns:
    false if ray, plane are parallel.)doc";

static const char * __doc_Bentley_Geom_DRay3d_ClosestApproachUnboundedRayUnboundedRay =R"doc(:param (output):
    fractionA computed fraction on (unbounded) ray

:param (output):
    fractionB computed fraction on (bounded) segment

:param (output):
    pointA computed point on (unbounded) ray

:param (output):
    pointB computed point on (bounded) segment

:param (input):
    rayA unbounded ray

:param (input):
    rayB bounded segment

:returns:
    false (with rayA start projected to rayB) if parallel rays.)doc";

static const char * __doc_Bentley_Geom_DRay3d_ClosestApproachUnboundedRayBoundedSegment =R"doc(:param (output):
    fractionRay computed fraction on (unbounded) ray

:param (output):
    fractionSegment computed fraction on (bounded) segment

:param (output):
    pointRay computed point on (unbounded) ray

:param (output):
    pointSegment computed point on (bounded) segment

:param (input):
    ray unbounded ray

:param (input):
    segment bounded segment)doc";

static const char * __doc_Bentley_Geom_DRay3d_ProjectPointBounded =R"doc(Project a point onto the bounded line in 3D. If nearest point of
extended line is outside the 0..1 parameter range, returned values are
for nearest endpoint.

:param (output):
    closestPoint computed point

:param (output):
    closestParam fraction parameter at closest point.

:param (input):
    point space point)doc";

static const char * __doc_Bentley_Geom_DRay3d_DirectionDotVector =R"doc(:param (input):
    vector

:returns:
    dot product of (unnormalized) ray vector with input vector.)doc";

static const char * __doc_Bentley_Geom_DRay3d_DirectionDotVectorToTarget =R"doc(:param (input):
    target

:returns:
    dot product of (unnormalized) ray vector with vector from ray
    origin to given point.)doc";

static const char * __doc_Bentley_Geom_DRay3d_FractionParameterToPoint =R"doc(:param (input):
    param fractional parameter

:returns:
    evaluated point.)doc";

static const char * __doc_Bentley_Geom_DRay3d_EvaluateEndPoints =R"doc(Return the origin and target of the ray.)doc";

static const char * __doc_Bentley_Geom_DRay3d_InitFromPlanePlaneIntersection =R"doc(Initialize as intersection of two planes.

:returns:
    false if planes are parallel.)doc";

static const char * __doc_Bentley_Geom_DRay3d_InitFromOriginAndTarget =R"doc(Initialize a ray from 2d endpoints)doc";

static const char * __doc_Bentley_Geom_DRay3d_InitFromOriginAndVector =R"doc(Initialize a ray from origina and vector)doc";

static const char * __doc_Bentley_Geom_DRay3d_InitFrom =R"doc(Initialize a ray from a segment.)doc";

static const char * __doc_Bentley_Geom_DRay3d_ValidatedNormalize =R"doc(Return a (validated) copy with normalized direction.)doc";

static const char * __doc_Bentley_Geom_DRay3d_FromIinterpolateWithScaledDifference =R"doc(Return a ray with origin interpolated between points. The ray
direction is the point0 to point1 vector scaled by vectorScale)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DRay3d(py::module_& m)
    {
    //===================================================================================
    // struct DRay3d
    py::class_<DRay3d> c1(m, "DRay3d");
    bind_ValidatedValue<DRay3d>(m, "ValidatedDRay3d", py::module_local(false));

    c1.def_readwrite("origin", &DRay3d::origin);
    c1.def_readwrite("direction", &DRay3d::direction);

    c1.def(py::init<>());
    c1.def(py::init(&DRay3d::From), "segment"_a);
    c1.def(py::init(&DRay3d::FromOriginAndVector), "origin"_a, "vector"_a);
    c1.def(py::init(py::overload_cast<DPoint2dCR, DPoint2dCR>(&DRay3d::FromOriginAndTarget)), "point0"_a, "point1"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, DPoint3dCR>(&DRay3d::FromOriginAndTarget)), "point0"_a, "point1"_a);
    c1.def_static("FromIinterpolateWithScaledDifference", &DRay3d::FromIinterpolateWithScaledDifference, "point0"_a, "fraction"_a, "point1"_a, "vectorScale"_a, DOC(Bentley, Geom, DRay3d, FromIinterpolateWithScaledDifference));
    c1.def("ValidatedNormalize", &DRay3d::ValidatedNormalize, DOC(Bentley, Geom, DRay3d, ValidatedNormalize));

    c1.def("InitFrom", &DRay3d::InitFrom, "segment"_a, DOC(Bentley, Geom, DRay3d, InitFrom));
    c1.def("InitFromOriginAndVector", &DRay3d::InitFromOriginAndVector, "origin"_a, "vector"_a, DOC(Bentley, Geom, DRay3d, InitFromOriginAndVector));
    c1.def("InitFromOriginAndTarget", py::overload_cast<DPoint2dCR, DPoint2dCR>(&DRay3d::InitFromOriginAndTarget), "point0"_a, "point1"_a, DOC(Bentley, Geom, DRay3d, InitFromOriginAndTarget));
    c1.def("InitFromOriginAndTarget", py::overload_cast<DPoint3dCR, DPoint3dCR>(&DRay3d::InitFromOriginAndTarget), "point0"_a, "point1"_a, DOC(Bentley, Geom, DRay3d, InitFromOriginAndTarget));
    c1.def("InitFromPlanePlaneIntersection", &DRay3d::InitFromPlanePlaneIntersection, "planeA"_a, "planeB"_a, DOC(Bentley, Geom, DRay3d, InitFromPlanePlaneIntersection));

    c1.def("EvaluateEndPoints", &DRay3d::EvaluateEndPoints, "point0"_a, "point1"_a, DOC(Bentley, Geom, DRay3d, EvaluateEndPoints));
    c1.def("FractionParameterToPoint", &DRay3d::FractionParameterToPoint, "param"_a, DOC(Bentley, Geom, DRay3d, FractionParameterToPoint));
    c1.def("DirectionDotVectorToTarget", &DRay3d::DirectionDotVectorToTarget, "target"_a, DOC(Bentley, Geom, DRay3d, DirectionDotVectorToTarget));
    c1.def("DirectionDotVector", &DRay3d::DirectionDotVector, "vector"_a, DOC(Bentley, Geom, DRay3d, DirectionDotVector));

    c1.def("ProjectPointBounded", [] (DRay3dCR self, DPoint3dCR point)
        {
        DPoint3d closestPoint = DPoint3d::FromZero();
        double closestParam = 0.0;
        bool bOk = self.ProjectPointBounded(closestPoint, closestParam, point);
        return py::make_tuple(bOk, closestPoint, closestParam);
        }, "point"_a, DOC(Bentley, Geom, DRay3d, ProjectPointBounded));

    c1.def("ProjectPointUnBounded", [] (DRay3dCR self, DPoint3dCR point)
        {
        DPoint3d closestPoint = DPoint3d::FromZero();
        double closestParam = 0.0;
        bool bOk = self.ProjectPointUnbounded(closestPoint, closestParam, point);
        return py::make_tuple(bOk, closestPoint, closestParam);
        }, "point"_a);

    c1.def_static("ClosestApproachUnboundedRayBoundedSegment", [] (DRay3dCR ray, DSegment3dCR segment)
        {
        double fractionRay = 0.0;
        double fractionSegment = 0.0;
        DPoint3d pointRay = DPoint3d::FromZero();
        DPoint3d pointSegment = DPoint3d::FromZero();
        DRay3d::ClosestApproachUnboundedRayBoundedSegment(fractionRay, fractionSegment, pointRay, pointSegment, ray, segment);
        return py::make_tuple(fractionRay, fractionSegment, pointRay, pointSegment);
        }, "ray"_a, "segment"_a, DOC(Bentley, Geom, DRay3d, ClosestApproachUnboundedRayBoundedSegment));

    c1.def_static("ClosestApproachUnboundedRayUnboundedRay", [] (DRay3dCR rayA, DRay3dCR rayB)
        {
        double fractionA = 0.0;
        double fractionB = 0.0;
        DPoint3d pointA = DPoint3d::FromZero();
        DPoint3d pointB = DPoint3d::FromZero();
        bool bOk = DRay3d::ClosestApproachUnboundedRayUnboundedRay(fractionA, fractionB, pointA, pointB, rayA, rayB);
        return py::make_tuple(bOk, fractionA, fractionB, pointA, pointB);
        }, "rayA"_a, "rayB"_a, DOC(Bentley, Geom, DRay3d, ClosestApproachUnboundedRayUnboundedRay));

    c1.def("Intersect", [] (DRay3dCR self, DPlane3dCR plane)
        {
        DPoint3d intPoint = DPoint3d::FromZero();
        double intParam = 0.0;
        bool bOk = self.Intersect(intPoint, intParam, plane);
        return py::make_tuple(bOk, intPoint, intParam);
        }, "plane"_a, DOC(Bentley, Geom, DRay3d, Intersect));

    c1.def("IntersectZPlane", [] (DRay3dCR self, TransformR frame, double localZ)
        {
        DPoint3d uvw = DPoint3d::FromZero();
        double t = 0.0;
        bool bOk = self.IntersectZPlane(frame, localZ, uvw, t);
        return py::make_tuple(bOk, uvw, t);
        }, "frame"_a, "localZ"_a, DOC(Bentley, Geom, DRay3d, IntersectZPlane));

    c1.def("IntersectCircleXY", [] (DRay3dCR self, DPoint3dCR center, double radius)
        {
        py::list outVal;
        DPoint3d intPoints[2];
        double intParams[2];
        int nPnts = self.IntersectCircleXY(intPoints, intParams, center, radius);
        for (int i = 0; i < nPnts; i++)
            {
            auto item = py::make_tuple(intPoints[i], intParams[i]);
            outVal.append(item);
            }
        return outVal;
        }, "center"_a, "radius"_a);

    c1.def("__repr__", [] (DRay3dCR& self)
           { 
           return "(origin:{}, direction:{})"_s.format(self.origin, self.direction); 
           });

    c1.def("__copy__", [](const DRay3d& self)
        {
        return DRay3d(self);
        });
    }