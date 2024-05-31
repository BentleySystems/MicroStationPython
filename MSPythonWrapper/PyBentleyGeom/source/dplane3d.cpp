/*--------------------------------------------------------------------------------------+
|= R"
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dplane3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DPlane3d_Intersect3Planes =R"doc(Compute the point of intersection of 3 planes given as normal and
distance from origin. ul> li>All normals are ASSUMED to be unit
length.

Returns:
    valid point if the three normals are independent. Otherwise
    returns origin of planeA, but marked invalid.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_InitFromArray =R"doc( Compute the origin and normal so the plane passes
(approximiately) through the array of points.

Parameter ``[in]``:
    points array of points defining the plane

Returns:
    true if the points define a clear plane (and are close to it!!!)
    false if the points are (a) closely clustered, (b) nearly
    colinear, or (c) not close to a single plane.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_EvaluateRange =R"doc(Returns:
    min and max signed evaluations among points in an array.

Parameter ``[in]``:
    points points to search

Parameter ``[in]``:
    n number of points

Parameter ``[out]``:
    maxIndex index where (signed) max occurs.

Parameter ``[out]``:
    minIndex index where (signed) min occurs.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_EvaluateMaxAbs =R"doc(Returns:
    The maximum absolute value of plane evaluation among points in an
    array.

Parameter ``[in]``:
    points points to search

Parameter ``[in]``:
    n number of points.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_EvaluateVector =R"doc( Dot the plane normal with the given vector.

Remark:
    s If the plane normal is a unit vector, this is the true distance
    of altitude change due to motion along by this vector. If not, it
    is a scaled distance.

Parameter ``[in]``:
    vector vector for evaluation

Returns:
    dot product)doc";

static const char * __doc_Bentley_Geom_DPlane3d_Evaluate =R"doc( Dot the plane normal with the vector from the plane
origin to the point.

Remark:
    s If the plane normal is a unit vector, this is the true distance
    from the plane to the point. If not, it is a scaled distance.

Parameter ``[in]``:
    point point for evaluation

Returns:
    dot product)doc";

static const char * __doc_Bentley_Geom_DPlane3d_ProjectPoint =R"doc( Project a (generally off-plane) point onto the plane.

Parameter ``[out]``:
    projection projection of point onto the plane

Parameter ``[in]``:
    point point to project to plane

Returns:
    true if the plane has a well defined normal.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_IsZero =R"doc( Test if the numeric entries in the plane are all
absolutely zero (no tolerances).

Returns:
    true if the plane contains only zero coordinates.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_Zero =R"doc( Fill the plane data with zeros.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_GetCoefficients =R"doc( Convert the plane to implicit coeffcients ax+by+cz=d.

Remark:
    s WARNING:Check your usage. It is about equally common to write
    the plane equation with negated d, i.e. ax+by+cz+d=0. If so, pass
    in (a,b,c,-d).

Parameter ``[out]``:
    coffA 4D plane x-coefficient

Parameter ``[out]``:
    coffB 4D plane y-coefficient

Parameter ``[out]``:
    coffC 4D plane z-coefficient

Parameter ``[out]``:
    coffD 4D plane constant coefficient)doc";

static const char * __doc_Bentley_Geom_DPlane3d_GetDPoint4d =R"doc( Return the plane as a DPoint4d.

Parameter ``[out]``:
    hPlane 4D plane coefficients)doc";

static const char * __doc_Bentley_Geom_DPlane3d_Init =R"doc( Extract origin and normal from 4D plane coefficients.

Parameter ``[in]``:
    hPlane 4D plane coefficients

Returns:
    true if plane has a nonzero normal)doc";

static const char * __doc_Bentley_Geom_DPlane3d_InitFrom3Points =R"doc( Initialize with first point as origin, normal as
unnormalized cross product of vectors to 2nd and 3rd points.

Parameter ``[in]``:
    origin origin point

Parameter ``[in]``:
    xPoint first point in plane (e.g., x-axis point)

Parameter ``[in]``:
    yPoint second point in plane (e.g., y-axis point))doc";

static const char * __doc_Bentley_Geom_DPlane3d_Normalize =R"doc( Normalize the plane vector.

Returns:
    true if normal vector has nonzero length.)doc";

static const char * __doc_Bentley_Geom_DPlane3d_InitFromOriginAndNormal =R"doc( Store origin and unnormalized vector.

Parameter ``[in]``:
    x0 x-coordinate of origin point

Parameter ``[in]``:
    y0 y-coordinate of origin point

Parameter ``[in]``:
    z0 z-coordinate of origin point

Parameter ``[in]``:
    ux x-coordinate of normal vector

Parameter ``[in]``:
    uy y-coordinate of normal vector

Parameter ``[in]``:
    uz z-coordinate of normal vector)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DPlane3d(py::module_& m)
    {
    //===================================================================================
    // struct DPlane3d
    py::class_<DPlane3d> c1(m, "DPlane3d");
    py::bind_vector<DPlane3dArray>(m, "DPlane3dArray", py::module_local(false));
    bind_ValidatedValue<DPlane3d>(m, "ValidatedDPlane3d", py::module_local(false));

    c1.def_readwrite("origin", &DPlane3d::origin);
    c1.def_readwrite("normal", &DPlane3d::normal);

    c1.def(py::init<>());
    c1.def(py::init(py::overload_cast<double, double, double, double, double, double>(&DPlane3d::FromOriginAndNormal)),
                  "x0"_a, "y0"_a, "z0"_a, "ux"_a, "uy"_a, "uz"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, DVec3dCR>(&DPlane3d::FromOriginAndNormal)), "origin"_a, "normal"_a);
    c1.def(py::init(&DPlane3d::FromNormalAndDistance), "normal"_a, "distance"_a);
    c1.def(py::init(&DPlane3d::From3Points), "origin"_a, "xpoint"_a, "ypoint"_a);

    c1.def("InitFromOriginAndNormal",
           py::overload_cast<double, double, double, double, double, double>(&DPlane3d::InitFromOriginAndNormal),
           "x0"_a, "y0"_a, "z0"_a, "ux"_a, "uy"_a, "uz"_a, DOC(Bentley, Geom, DPlane3d, InitFromOriginAndNormal));
    c1.def("InitFromOriginAndNormal", py::overload_cast<DPoint3dCR, DVec3dCR>(&DPlane3d::InitFromOriginAndNormal), "origin"_a, "normal"_a, DOC(Bentley, Geom, DPlane3d, InitFromOriginAndNormal));

    c1.def("Normalize", &DPlane3d::Normalize, DOC(Bentley, Geom, DPlane3d, Normalize));
    c1.def("InitFrom3Points", &DPlane3d::InitFrom3Points, "origin"_a, "xpoint"_a, "ypoint"_a, DOC(Bentley, Geom, DPlane3d, InitFrom3Points));
    c1.def("Init", py::overload_cast<DPoint4dCR>(&DPlane3d::Init), "hPlane"_a, DOC(Bentley, Geom, DPlane3d, Init));
    c1.def("Init", py::overload_cast<double, double, double, double>(&DPlane3d::Init), "a"_a, "b"_a, "c"_a, "d"_a, DOC(Bentley, Geom, DPlane3d, Init));

    c1.def("GetDPoint4d", &DPlane3d::GetDPoint4d, "hPlane"_a, DOC(Bentley, Geom, DPlane3d, GetDPoint4d));
    c1.def("GetCoefficients", [] (DPlane3dCR self)
        {
        double a, b, c, d;
        self.GetCoefficients(a, b, c, d);
        return py::make_tuple(a, b, c, d);
        }, DOC(Bentley, Geom, DPlane3d, GetCoefficients));

    c1.def("Zero", &DPlane3d::Zero, DOC(Bentley, Geom, DPlane3d, Zero));
    c1.def("IsZero", &DPlane3d::IsZero, DOC(Bentley, Geom, DPlane3d, IsZero));
    c1.def("ProjectPoint", &DPlane3d::ProjectPoint, "projection"_a, "point"_a, DOC(Bentley, Geom, DPlane3d, ProjectPoint));

    c1.def("Evaluate", &DPlane3d::Evaluate, "point"_a, DOC(Bentley, Geom, DPlane3d, Evaluate));
    c1.def("EvaluateVector", &DPlane3d::EvaluateVector, "vector"_a, DOC(Bentley, Geom, DPlane3d, EvaluateVector));
    c1.def("EvaluateMaxAbs", py::overload_cast<DPoint3dArray const&>(&DPlane3d::EvaluateMaxAbs, py::const_), "points"_a, DOC(Bentley, Geom, DPlane3d, EvaluateMaxAbs));
    c1.def("EvaluateRange", [] (DPlane3dCR self, DPoint3dArray const& points)
        {
        size_t minIndex, maxIndex;
        DRange1d range = self.EvaluateRange(points, minIndex, maxIndex);
        return py::make_tuple(range, minIndex, maxIndex);
        }, "points"_a, DOC(Bentley, Geom, DPlane3d, EvaluateRange));

    c1.def("InitFromArray", py::overload_cast<DPoint3dArray const&>(&DPlane3d::InitFromArray), "points"_a, DOC(Bentley, Geom, DPlane3d, InitFromArray));

    c1.def_static("Intersect3Planes",
                  py::overload_cast<DVec3dCR, double, DVec3dCR, double, DVec3dCR, double>(&DPlane3d::Intersect3Planes),
                  "unitNormalA"_a, "distanceA"_a, "unitNormalB"_a, "distanceB"_a, "unitNormalC"_a, "distanceC"_a, DOC(Bentley, Geom, DPlane3d, Intersect3Planes));
    c1.def_static("Intersect3Planes",
                  py::overload_cast<DPlane3dCR, DPlane3dCR, DPlane3dCR>(&DPlane3d::Intersect3Planes),
                  "planeA"_a, "planeB"_a, "planeC"_a, DOC(Bentley, Geom, DPlane3d, Intersect3Planes));       

    c1.def("__repr__", [] (DPlane3dCR self)
           {
           return "(origin:{}, normal:{})"_s.format(self.origin, self.normal);
           });

    c1.def("__copy__", [](const DPlane3d& self)
        {
        return DPlane3d(self);
        });
    }
