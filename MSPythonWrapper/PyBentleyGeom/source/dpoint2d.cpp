/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dpoint2d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/OperatorOverload.h>



static const char * __doc_Bentley_Geom_DPoint2d_AlmostEqual =R"doc(test if two points are equal. Uses library " small angle " as both
absolute and relative tolerance. points are equal if squared distance
between is less than (squared abstol) plus (squared relTol) * sum of
cmponent squares

Parameter ``[in]``:
    dataB second DPoint2d

Returns:
    true if within tolerance.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_IsConvexPair =R"doc(return true if the point has x, y, and x+1 all between 0 and 1
(inclusive).)doc";

static const char * __doc_Bentley_Geom_DPoint2d_IsDisconnect =R"doc(Returns:
    true if the point has coordinates which indicate it is a
    disconnect (separator) ponit.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_MaxAbs =R"doc( Finds the largest absolute value among the components of
a point or vector.

Returns:
    largest absolute value among point coordinates.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_IsEqual =R"doc( Test if two points or vectors are exactly equal.

Parameter ``[in]``:
    vector2 Second point or vector

Returns:
    true if the points are identical. (DPoint2dCR, double))doc";

static const char * __doc_Bentley_Geom_DPoint2d_IsPerpendicularTo =R"doc( Test if two vectors are perpendicular.

Parameter ``[in]``:
    vector2 Second vector

Returns:
    true if vectors are (nearly) parallel.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_IsParallelTo =R"doc( Test if two vectors are parallel.

Parameter ``[in]``:
    vector2 Second vector

Returns:
    true if vectors are (nearly) parallel.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_AngleTo =R"doc( Returns (signed, counterclockwise) angle between two
vectors. The angle is in radians. The angle range is from -pi to +pi;
positive angles are counterclockwise, negative angles are clockwise.

Parameter ``[in]``:
    vector2 second vector

Returns:
    angle in radians)doc";

static const char * __doc_Bentley_Geom_DPoint2d_GetComponent =R"doc( Gets a single component of a point. If the index is out
of range 0,1, it is interpreted cyclically.

Parameter ``[in]``:
    index 0=x, 1=y, others cyclic

Returns:
    specified component of the point or vector.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_SetComponent =R"doc( Sets a single component of a point. If the index is out
of range 0,1, it is interpreted cyclically.

Parameter ``[in]``:
    a value for component

Parameter ``[in]``:
    index 0=x, 1=y, others cyclic)doc";

static const char * __doc_Bentley_Geom_DPoint2d_DotProductToPoints =R"doc( Returns the (scalar) dot product of two vectors. The
vectors are computed from the Origin to Target1 and Target2.

Parameter ``[in]``:
    target1 target of first vector

Parameter ``[in]``:
    target2 target of second vector)doc";

static const char * __doc_Bentley_Geom_DPoint2d_DotProduct =R"doc( Returns the (scalar) dot product of two vectors.

Parameter ``[in]``:
    vector2 second vector.

Returns:
    dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DPoint2d_CrossProductToPoints =R"doc( Returns the (scalar) cross product of two vectors. The
vectors are computed from the Origin to Target1 and Target2.

Parameter ``[in]``:
    target1 target of first vector

Parameter ``[in]``:
    target2 target of second vector)doc";

static const char * __doc_Bentley_Geom_DPoint2d_CrossProduct =R"doc( Returns the (scalar) cross product of two vectors.

Parameter ``[in]``:
    vector1 first vector)doc";

static const char * __doc_Bentley_Geom_DPoint2d_DistanceSquared =R"doc( Return the squared distance between two points or
vectors.

Parameter ``[in]``:
    point2 end point

Returns:
    squared distance between points)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Distance =R"doc( Returns the distance between 2 points

Parameter ``[in]``:
    point1 second point

Returns:
    distance from point 0 to point 1)doc";

static const char * __doc_Bentley_Geom_DPoint2d_MagnitudeSquared =R"doc(Returns:
    squared magnitude of the vector)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Magnitude =R"doc( Returns the magnitude (length) of a vector.

Returns:
    Length of the vector.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Swap =R"doc(Swap contents of instance, other.

Parameter ``[in,out]``:
    other second point.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_RotateCCW =R"doc(Parameter ``[in]``:
    vec original vector

Parameter ``[in]``:
    radians rotation angle

Remark:
    Note that this is a counterclockwise rotation. The " rotate " method
    in prior api was clockwise.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Rotate90 =R"doc(Parameter ``[in]``:
    vec original vector)doc";

static const char * __doc_Bentley_Geom_DPoint2d_FromInterpolateBilinear =R"doc( Returns a bilinear interpolation from corners
(00)(10)(01)(11)

Parameter ``[in]``:
    point00 point at (0,0)

Parameter ``[in]``:
    point10 point at (1,0)

Parameter ``[in]``:
    point01 point at (0,1)

Parameter ``[in]``:
    point11 point at (1,1)

Parameter ``[in]``:
    u interpolation fraction for edges (point00,point10) and
    (point01,point11)

Parameter ``[in]``:
    v interpolation fraction for edges (point00,point10) and
    (point10,point11))doc";

static const char * __doc_Bentley_Geom_DPoint2d_Interpolate =R"doc(Compute the point at an interpolated (fractional) position between a
start and end point.

Parameter ``[in]``:
    point0 start point (at parameter s=0)

Parameter ``[in]``:
    s interpolation parameter

Parameter ``[in]``:
    point1 end point (at parameter s=1))doc";

static const char * __doc_Bentley_Geom_DPoint2d_FromInterpolate =R"doc( Returns an interpolated point.

Parameter ``[in]``:
    point0 point at fraction 0

Parameter ``[in]``:
    fraction fraction from interpolation.

Parameter ``[in]``:
    point1 point at fraction 1)doc";

static const char * __doc_Bentley_Geom_DPoint2d_SumOf =R"doc( Compute the sum of two points or vectors.

Parameter ``[in]``:
    point1 First point or vector

Parameter ``[in]``:
    point2 Second point or vector)doc";

static const char * __doc_Bentley_Geom_DPoint2d_FromSumOf =R"doc( Returns a linear combination of points

Parameter ``[in]``:
    point0 first point

Parameter ``[in]``:
    scale0 first scale

Parameter ``[in]``:
    point1 second point

Parameter ``[in]``:
    scale1 second scale)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Normalize =R"doc(normalizes pVector1 in place, and returns the original magnitude. If
the original magnitude is 0 the vector is left unchanged.

Returns:
    original length)doc";

static const char * __doc_Bentley_Geom_DPoint2d_ScaleToLength =R"doc( Scales a vector to specified length. If the input vector
length is 0, the output vector is a zero vector and the returned
length is 0.

Parameter ``[in]``:
    source The original vector.

Parameter ``[in]``:
    length The requested length.

Returns:
    The length prior to scaling.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Negate =R"doc( returns the negative of a vector.

Parameter ``[in]``:
    vector input)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Scale =R"doc(Scale the instance coordinates from source

Parameter ``[in]``:
    source input point

Parameter ``[in]``:
    s scale factor)doc";

static const char * __doc_Bentley_Geom_DPoint2d_FromScale =R"doc( Returns a scalar multiple of a DPoint2d

Parameter ``[in]``:
    point input point

Parameter ``[in]``:
    scale scale factor)doc";

static const char * __doc_Bentley_Geom_DPoint2d_NormalizedDifferenceOf =R"doc(Sets pNormal to the unit vector in the direction of point1 point2

Parameter ``[in]``:
    point1 point 1

Parameter ``[in]``:
    point2 point 2

Returns:
    double distance between input points)doc";

static const char * __doc_Bentley_Geom_DPoint2d_DifferenceOf =R"doc( Return the difference of two points or vectors.

Parameter ``[in]``:
    point1 First point or vector.

Parameter ``[in]``:
    point2 Second (subtracted) point or vector.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Subtract =R"doc( Subtract one vector from another in place.

Parameter ``[in]``:
    vector vector to subtract)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Add =R"doc(Add a vector to the instance.

Parameter ``[in]``:
    vector vector to add)doc";

static const char * __doc_Bentley_Geom_DPoint2d_InitDisconnect =R"doc(Initialize a point with all coordinates as the disconnect value.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_One =R"doc( Returns a point or vector with all components 1.0.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Zero =R"doc( Sets all components of a point or vector to zero.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_Init =R"doc(Initialize with given components

Parameter ``[in]``:
    x x component

Parameter ``[in]``:
    y y component)doc";

static const char * __doc_Bentley_Geom_DPoint2d_FromOne =R"doc(Return a DPoint2d with xy = 1.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_FromZero =R"doc(Return a DPoint2d with xy = 0.)doc";

static const char * __doc_Bentley_Geom_DPoint2d_From =R"doc( Returns a DPoint2d with 2 components (xy) from given
components

Parameter ``[in]``:
    ax x coordinate

Parameter ``[in]``:
    ay y coordinate)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DPoint2d(py::module_& m)
    {
    //===================================================================================
    // struct DPoint2d
    py::class_<DPoint2d> c1(m, "DPoint2d");
    py::bind_vector<DPoint2dArray>(m, "DPoint2dArray", py::module_local(false));
    py::bind_vector<DPoint2dVecArray>(m, "DPoint2dVecArray", py::module_local(false));
    bind_ValidatedValue<DPoint2d>(m, "ValidatedDPoint2d", py::module_local(false));
    bind_BlockedVector<DPoint2d>(m, "BlockedVectorDPoint2d", py::module_local(false));

    c1.def_readwrite("x", &DPoint2d::x);
    c1.def_readwrite("y", &DPoint2d::y);

    c1.def(py::init(&DPoint2d::FromZero));

    c1.def(py::self == py::self);
    c1.def(py::self + DVec2d());
    c1.def(py::self - DVec2d());

    c1.def("__copy__", [](const DPoint2d& self)
        {
        return DPoint2d (self);
        });

    c1.def(py::init([] (DVec2d const& v) { return DPoint2d::From(v.x, v.y); }), "vector"_a);
    c1.def(py::init(py::overload_cast<double, double>(&DPoint2d::From)), "ax"_a, "ay"_a);
    c1.def_static("From", py::overload_cast<double, double>(&DPoint2d::From), "ax"_a, "ay"_a, DOC(Bentley, Geom, DPoint2d, From));
    c1.def_static("From", py::overload_cast<DPoint3dCR>(&DPoint2d::From), "source"_a, DOC(Bentley, Geom, DPoint2d, From));
    c1.def_static("FromZero", &DPoint2d::FromZero, DOC(Bentley, Geom, DPoint2d, FromZero));        
    c1.def_static("FromOne", &DPoint2d::FromOne, DOC(Bentley, Geom, DPoint2d, FromOne));
        
    c1.def("Init", py::overload_cast<double, double>(&DPoint2d::Init), "x"_a, "y"_a, DOC(Bentley, Geom, DPoint2d, Init));
    c1.def("Init", py::overload_cast<DPoint3dCR>(&DPoint2d::Init), "source"_a, DOC(Bentley, Geom, DPoint2d, Init));
    c1.def("Zero", &DPoint2d::Zero, DOC(Bentley, Geom, DPoint2d, Zero));        
    c1.def("One", &DPoint2d::One, DOC(Bentley, Geom, DPoint2d, One));
    c1.def("InitDisconnect", &DPoint2d::InitDisconnect, DOC(Bentley, Geom, DPoint2d, InitDisconnect));

    c1.def("Add", &DPoint2d::Add, "vector"_a, DOC(Bentley, Geom, DPoint2d, Add));
    c1.def("Subtract", &DPoint2d::Subtract, "vector"_a, DOC(Bentley, Geom, DPoint2d, Subtract));
    c1.def("DifferenceOf", &DPoint2d::DifferenceOf, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint2d, DifferenceOf));
    c1.def("NormalizedDifferenceOf", &DPoint2d::NormalizedDifferenceOf, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint2d, NormalizedDifferenceOf));

    c1.def_static("FromScale", &DPoint2d::FromScale, "point"_a, "scale"_a, DOC(Bentley, Geom, DPoint2d, FromScale));        
    c1.def("Scale", py::overload_cast<DPoint2dCR, double>(&DPoint2d::Scale), "source"_a, "s"_a, DOC(Bentley, Geom, DPoint2d, Scale));
    c1.def("Scale", py::overload_cast<double>(&DPoint2d::Scale), "s"_a, DOC(Bentley, Geom, DPoint2d, Scale));        
    c1.def("Negate", &DPoint2d::Negate, "vector"_a, DOC(Bentley, Geom, DPoint2d, Negate));

    c1.def("ScaleToLength", py::overload_cast<DPoint2dCR, double>(&DPoint2d::ScaleToLength), "source"_a, "length"_a, DOC(Bentley, Geom, DPoint2d, ScaleToLength));
    c1.def("ScaleToLength", py::overload_cast<double>(&DPoint2d::ScaleToLength), "length"_a, DOC(Bentley, Geom, DPoint2d, ScaleToLength));
        
    c1.def("Normalize", py::overload_cast<>(&DPoint2d::Normalize), DOC(Bentley, Geom, DPoint2d, Normalize));
    c1.def("Normalize", py::overload_cast<DPoint2dCR>(&DPoint2d::Normalize), "vector1"_a, DOC(Bentley, Geom, DPoint2d, Normalize));
        
    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint2dCR, double, DPoint2dCR, double>(&DPoint2d::FromSumOf),
                  "point0"_a, "scale0"_a, "point1"_a, "scale1"_a, DOC(Bentley, Geom, DPoint2d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint2dCR, double, DPoint2dCR, double, DPoint2dCR, double>(&DPoint2d::FromSumOf),
                  "point0"_a, "scale0"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint2d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint2dCR, DVec2dCR, double>(&DPoint2d::FromSumOf),
                  "origin"_a, "vector"_a, "scaleFactor"_a, DOC(Bentley, Geom, DPoint2d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint2dCR, DVec2dCR, double, DVec2dCR, double>(&DPoint2d::FromSumOf),
                  "origin"_a, "vector0"_a, "scaleFactor0"_a, "vector1"_a, "scaleFactor1"_a, DOC(Bentley, Geom, DPoint2d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint2dCR, DVec2dCR, double, DVec2dCR, double, DVec2dCR, double>(&DPoint2d::FromSumOf),
                  "origin"_a, "vector0"_a, "scaleFactor0"_a, "vector1"_a, "scaleFactor1"_a, "vector2"_a, "scaleFactor2"_a, DOC(Bentley, Geom, DPoint2d, FromSumOf));

    c1.def("SumOf", 
           py::overload_cast<DPoint2dCR, DPoint2dCR>(&DPoint2d::SumOf), 
           "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint2d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint2dCR, double, DPoint2dCR, double, DPoint2dCR, double>(&DPoint2d::SumOf),
           "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, "vector3"_a, "scale3"_a, DOC(Bentley, Geom, DPoint2d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint2dCR, DPoint2dCR, double>(&DPoint2d::SumOf),
           "point"_a, "vector"_a, "s"_a, DOC(Bentley, Geom, DPoint2d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint2dCR, DPoint2dCR, double, DPoint2dCR, double>(&DPoint2d::SumOf),
           "origin"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint2d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint2dCR, DPoint2dCR, double, DPoint2dCR, double, DPoint2dCR, double>(&DPoint2d::SumOf),
           "origin"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, "vector3"_a, "scale3"_a, DOC(Bentley, Geom, DPoint2d, SumOf));


    c1.def_static("FromInterpolate", &DPoint2d::FromInterpolate, "point0"_a, "fraction"_a, "point1"_a, DOC(Bentley, Geom, DPoint2d, FromInterpolate));

    c1.def("Interpolate", &DPoint2d::Interpolate, "point0"_a, "s"_a, "point1"_a, DOC(Bentley, Geom, DPoint2d, Interpolate));

    c1.def_static("FromInterpolateBilinear", &DPoint2d::FromInterpolateBilinear, "point00"_a, "point10"_a, "point01"_a, "point11"_a, "u"_a, "v"_a, DOC(Bentley, Geom, DPoint2d, FromInterpolateBilinear));

    c1.def("Rotate90", &DPoint2d::Rotate90, "vec"_a, DOC(Bentley, Geom, DPoint2d, Rotate90));
        
    c1.def("RotateCCW", &DPoint2d::RotateCCW, "vec"_a, "radians"_a, DOC(Bentley, Geom, DPoint2d, RotateCCW));

    c1.def("Swap", &DPoint2d::Swap, "other"_a, DOC(Bentley, Geom, DPoint2d, Swap));

    c1.def("Magnitude", &DPoint2d::Magnitude, DOC(Bentley, Geom, DPoint2d, Magnitude));
    c1.def("MagnitudeSquared", &DPoint2d::MagnitudeSquared, DOC(Bentley, Geom, DPoint2d, MagnitudeSquared));

    c1.def("Distance", &DPoint2d::Distance, "point1"_a, DOC(Bentley, Geom, DPoint2d, Distance));        
    c1.def("DistanceSquared", &DPoint2d::DistanceSquared, "point2"_a, DOC(Bentley, Geom, DPoint2d, DistanceSquared));
        
    c1.def("CrossProduct", &DPoint2d::CrossProduct, "vector1"_a, DOC(Bentley, Geom, DPoint2d, CrossProduct));
    c1.def("CrossProductToPoints", &DPoint2d::CrossProductToPoints, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint2d, CrossProductToPoints));

    c1.def("DotProduct", &DPoint2d::DotProduct, "vector2"_a, DOC(Bentley, Geom, DPoint2d, DotProduct));
    c1.def("DotProductToPoints", &DPoint2d::DotProductToPoints, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint2d, DotProductToPoints));

    c1.def("SetComponent", &DPoint2d::SetComponent, "a"_a, "index"_a, DOC(Bentley, Geom, DPoint2d, SetComponent));
    c1.def("GetComponent", &DPoint2d::GetComponent, "index"_a, DOC(Bentley, Geom, DPoint2d, GetComponent));        
    c1.def("GetComponents", [] (DPoint2dCR pt) { return std::make_pair(pt.x, pt.y); });
        
    c1.def("AngleTo", &DPoint2d::AngleTo, "vector2"_a, DOC(Bentley, Geom, DPoint2d, AngleTo));
    c1.def("IsParallelTo", &DPoint2d::IsParallelTo, "vector2"_a, DOC(Bentley, Geom, DPoint2d, IsParallelTo));
    c1.def("IsPerpendicularTo", &DPoint2d::IsPerpendicularTo, "vector2"_a, DOC(Bentley, Geom, DPoint2d, IsPerpendicularTo));

    c1.def("IsEqual", py::overload_cast<DPoint2dCR>(&DPoint2d::IsEqual, py::const_), "vector2"_a, DOC(Bentley, Geom, DPoint2d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DPoint2dCR, double>(&DPoint2d::IsEqual, py::const_), "vector2"_a, "tolerance"_a, DOC(Bentley, Geom, DPoint2d, IsEqual));

    c1.def("MaxAbs", &DPoint2d::MaxAbs, DOC(Bentley, Geom, DPoint2d, MaxAbs));
    c1.def("IsDisconnect", &DPoint2d::IsDisconnect, DOC(Bentley, Geom, DPoint2d, IsDisconnect));
    c1.def("IsConvexPair", &DPoint2d::IsConvexPair, DOC(Bentley, Geom, DPoint2d, IsConvexPair));

    c1.def("AlmostEqual", &DPoint2d::AlmostEqual, "dataB"_a, DOC(Bentley, Geom, DPoint2d, AlmostEqual));

    c1.def("__repr__", [] (DPoint2d& self) { return "[{}, {}]"_s.format(self.x, self.y); });
    }