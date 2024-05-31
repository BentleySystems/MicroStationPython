/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dvec2d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/OperatorOverload.h>



static const char * __doc_Bentley_Geom_DVec2d_AlmostEqual =R"doc(test if two points are equal. Uses library " small angle " as both
absolute and relative tolerance. points are equal if squared distance
between is less than (squared abstol) plus (squared relTol) * sum of
cmponent squares

Parameter ``[in]``:
    dataB second DVec2d

Returns:
    true if within tolerance.)doc";

static const char * __doc_Bentley_Geom_DVec2d_IsEqual =R"doc( Test for exact equality between all components of two
vectors.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if the vectors are identical.)doc";

static const char * __doc_Bentley_Geom_DVec2d_IsPerpendicularTo =R"doc( Tests if two vectors are perpendicular.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if vectors are perpendicular within tolerance)doc";

static const char * __doc_Bentley_Geom_DVec2d_IsParallelTo =R"doc( Tests if two vectors are parallel.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if the vectors are parallel within tolerance)doc";

static const char * __doc_Bentley_Geom_DVec2d_IsVectorInCCWSector =R"doc( test if the instance is " between " vector0 and vector1
when vector0 is rotated counterclockwise towards vector1.

Parameter ``[in]``:
    vector0 start vector for CCW sweep.

Parameter ``[in]``:
    vector1 end vector for CCW sweep.)doc";

static const char * __doc_Bentley_Geom_DVec2d_IsVectorInSmallerSector =R"doc( Test a vector is " between " vector0 and vector1. If the
vectors are coplanar and vector0 is neither parallel nor antiparallel
to vector1, betweenness has the expected meaning:there are two angles
between vector0 and vector1; one is less than 180; the test vector is
tested to see if it is in the smaller angle. If the vectors are not
coplanar, the test is based on the projection of the test vector into
the plane of the other two vectors.

Zero testing is untoleranced, and is biased to all parallel conditions
" false ". That is, if any pair of the input vectors is parallel or
antiparallel, the mathematical answer is false. Floating point
tolerances will cause " nearby " cases to be unpredictable. It is
assumed that if the caller considers the " parallel " cases important
they will be checked explicitly.

Parameter ``[in]``:
    vector0 The first boundary vector.

Parameter ``[in]``:
    vector1 The second boundary vector.

Returns:
    true if the test vector is within the angle.)doc";

static const char * __doc_Bentley_Geom_DVec2d_SmallerUnorientedAngleTo =R"doc( Returns the angle between two vectors, choosing the
smaller of the two possible angles when both the vectors and their
negations are considered. This angle is between 0 and pi/2.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The angle between the vectors.)doc";

static const char * __doc_Bentley_Geom_DVec2d_AngleTo =R"doc( Returns the angle between two vectors. This angle is
between 0 and pi. Rotating the first vector by this angle around the
cross product between the vectors aligns it with the second vector.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The angle between the vectors.)doc";

static const char * __doc_Bentley_Geom_DVec2d_CrossProductSquared =R"doc( Returns the (vector) cross product of two vectors.

Parameter ``[in]``:
    vector2 The second vector)doc";

static const char * __doc_Bentley_Geom_DVec2d_CrossProduct =R"doc( Returns the (vector) cross product of two vectors.

Parameter ``[in]``:
    vector2 The second vector)doc";

static const char * __doc_Bentley_Geom_DVec2d_DotProduct =R"doc( Returns the (scalar) dot product of two vectors.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec2d_SetComponent =R"doc( Set one of three components (x,y) of the vector.

Parameter ``[in]``:
    a The component value.

Parameter ``[in]``:
    index Selects the the axis:0=x, 1=y)doc";

static const char * __doc_Bentley_Geom_DVec2d_GetComponent =R"doc( Gets a single component of a vector. If the index is out
of range 0,1 it is interpretted cyclically.

Parameter ``[in]``:
    index Indicates which component is accessed. The values are 0=x,
    1=y Other values are treated cyclically.

Returns:
    The specified component of the vector.)doc";

static const char * __doc_Bentley_Geom_DVec2d_DistanceSquared =R"doc( Computes the squared distance between two vectors.

Parameter ``[in]``:
    vector2 The second vector.

Returns:
    The squared distance between the vectors.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Distance =R"doc( Computes the (cartesian) distance between two vectors

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The distance between vector.)doc";

static const char * __doc_Bentley_Geom_DVec2d_MaxAbs =R"doc( Finds the largest absolute value among the components of
a vector.

Returns:
    The largest absolute value among vector coordinates.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Magnitude =R"doc( Computes the magnitude of a vector.

Returns:
    The length of the vector)doc";

static const char * __doc_Bentley_Geom_DVec2d_MagnitudeSquared =R"doc( Computes the squared magnitude of a vector.

Returns:
    The squared magnitude of the vector.)doc";

static const char * __doc_Bentley_Geom_DVec2d_XyOf =R"doc( Sets the x,y, and z components of a DVec2d structure from
the corresponding parts of a DPoint4d. Weight part of DPoint4d is not
used.

Parameter ``[in]``:
    hPoint The homogeneous point)doc";

static const char * __doc_Bentley_Geom_DVec2d_UnitPerpendicular =R"doc( Compute a unit vector perpendicular given vector.

Remark:
    s Input may equal output.

Parameter ``[in]``:
    vector The source vector

Returns:
    true if the input vector has nonzero length)doc";

static const char * __doc_Bentley_Geom_DVec2d_RotateCCW =R"doc( Rotate a vector COUNTERCLOCKWISE around the z axis.

Parameter ``[in]``:
    vector vector to rotate.

Parameter ``[in]``:
    theta The rotation angle.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Interpolate =R"doc( Computes a vector whose position is given by a fractional
argument and two vectors.

Parameter ``[in]``:
    vector0 The vector corresponding to fractionParameter of 0.

Parameter ``[in]``:
    fractionParameter The fractional parametric coordinate. 0.0 is the
    start of the segment, 1.0 is the end, 0.5 is middle

Parameter ``[in]``:
    vector1 The vector corresponding to fractionParameter of 1.)doc";

static const char * __doc_Bentley_Geom_DVec2d_SafeDivide =R"doc( Try to divide each component of a vector by a scalar. If
the denominator near zero compared to any numerator component, return
the original vector.

Parameter ``[in]``:
    vector The initial vector.

Parameter ``[in]``:
    denominator The divisor.

Returns:
    true if division is numerically safe.)doc";

static const char * __doc_Bentley_Geom_DVec2d_ScaleToLength =R"doc( Scales a vector to specified length.

Remark:
    In the 0-length error case, the vector is set to (1,0) in the
    legacy microstation style.

Parameter ``[in]``:
    vector The original vector.

Parameter ``[in]``:
    length The requested length.

Returns:
    The length prior to scaling.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Normalize =R"doc( Normalizes (scales) a vector to length 1.

Remark:
    In the 0-length error case, the vector is set to (1,0) in the
    legacy microstation style.

Parameter ``[in]``:
    vector The vector to be normalized.

Returns:
    The length prior to normalization)doc";

static const char * __doc_Bentley_Geom_DVec2d_NormalizedDifference =R"doc( Computes a unit vector in the direction of the difference
of the vectors or vectors (Second parameter vector is subtracted from
the first parameter vector, exactly as in the subtract function.)

Remark:
    In the 0-length error case, the vector is set to (1,0) in the
    legacy microstation style.

Parameter ``[in]``:
    target The target point.

Parameter ``[in]``:
    origin The origin point.

Returns:
    The length of original difference vector.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Subtract =R"doc( Subtract two vectors, and return the result in place of
the first.

Parameter ``[in]``:
    vector2 The vector to subtract.)doc";

static const char * __doc_Bentley_Geom_DVec2d_DifferenceOf =R"doc( Subtract coordinates of two vectors. (Compute Vector1 -
Vector2)

Parameter ``[in]``:
    vector1 The first vector

Parameter ``[in]``:
    vector2 The second (subtracted) vector)doc";

static const char * __doc_Bentley_Geom_DVec2d_FromSumOf =R"doc( Returns a linear combination of vectors

Parameter ``[in]``:
    vector0 first vector

Parameter ``[in]``:
    scale0 first scale

Parameter ``[in]``:
    vector1 second vector

Parameter ``[in]``:
    scale1 second scale)doc";

static const char * __doc_Bentley_Geom_DVec2d_Scale =R"doc( Multiplies a vector by a scale factor.

Parameter ``[in]``:
    vector The vector to be scaled.

Parameter ``[in]``:
    scale The scale factor.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Add =R"doc( Adds a vector to a pointer or vector, returns the result
in place.

Parameter ``[in]``:
    vector The vector to add.)doc";

static const char * __doc_Bentley_Geom_DVec2d_SumOf =R"doc( Compute the sum of two vectors or vectors.

Parameter ``[in]``:
    vector1 The the first vector

Parameter ``[in]``:
    vector2 The second vector)doc";

static const char * __doc_Bentley_Geom_DVec2d_Negate =R"doc( Computes a negated (opposite) vector.

Parameter ``[in]``:
    vector The vector to be negated.)doc";

static const char * __doc_Bentley_Geom_DVec2d_One =R"doc( Returns a vector with all components 1.0.)doc";

static const char * __doc_Bentley_Geom_DVec2d_Zero =R"doc( Sets all components of a vector to zero.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DVec2d(py::module_& m)
    {
    //===================================================================================
    // struct DVec2d
    py::class_<DVec2d, DPoint2d> c1(m, "DVec2d");
    py::bind_vector<DVec2dArray>(m, "DVec2dArray", py::module_local(false));
    bind_ValidatedValue<DVec2d>(m, "ValidatedDVec2d", py::module_local(false));

    c1.def(py::init([] () { DVec2d v; v.Zero(); return v; }));
    c1.def(py::init(py::overload_cast<double, double>(DVec2d::From)), "x"_a, "y"_a);
    c1.def(py::init(py::overload_cast<DPoint2dCR>(DVec2d::From)), "point"_a);
    c1.def(py::init(py::overload_cast<DPoint2dCR, DPoint2dCR>(DVec2d::FromStartEnd)), "start"_a, "end"_a);
    c1.def(py::init(py::overload_cast<DVec2dCR, double>(DVec2d::FromScale)), "vector"_a, "scale"_a);
    
    c1.def_static("From", py::overload_cast<double, double>(&DVec2d::From), "ax"_a, "ay"_a);

    c1.def(py::self * double());
    c1.def(double() * py::self);
    c1.def(py::self + py::self);

    c1.def("__copy__", [](const DVec2d& self)
        {
        return DVec2d(self);
        });

    c1.def("Init", py::overload_cast<DPoint2dCR>(&DVec2d::Init), "point"_a);
    c1.def("Init", py::overload_cast<double, double>(&DVec2d::Init), "x"_a, "y"_a);

    c1.def("Zero", &DVec2d::Zero, DOC(Bentley, Geom, DVec2d, Zero));
    c1.def("One", &DVec2d::One, DOC(Bentley, Geom, DVec2d, One));

    c1.def("Negate", py::overload_cast<DVec2dCR>(&DVec2d::Negate), "vector"_a, DOC(Bentley, Geom, DVec2d, Negate));
    c1.def("Negate", py::overload_cast<>(&DVec2d::Negate), DOC(Bentley, Geom, DVec2d, Negate));

    c1.def("SumOf", 
           py::overload_cast<DVec2dCR, DVec2dCR>(&DVec2d::SumOf), 
           "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec2d, SumOf));

    c1.def("SumOf", 
           py::overload_cast<DVec2dCR, DVec2dCR, double>(&DVec2d::SumOf), 
           "vector1"_a, "vector2"_a, "scale"_a, DOC(Bentley, Geom, DVec2d, SumOf));

    c1.def("SumOf", 
           py::overload_cast<DVec2dCR, DVec2dCR, double, DVec2dCR, double>(&DVec2d::SumOf), 
           "origin"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, DOC(Bentley, Geom, DVec2d, SumOf));

    c1.def("SumOf", 
           py::overload_cast<DVec2dCR, DVec2dCR, double, DVec2dCR, double, DVec2dCR, double>(&DVec2d::SumOf), 
           "origin"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, "vector3"_a, "scale3"_a, DOC(Bentley, Geom, DVec2d, SumOf));

    c1.def("Add", &DVec2d::Add, "vector"_a, DOC(Bentley, Geom, DVec2d, Add));

    c1.def("Scale", py::overload_cast<DVec2dCR, double>(&DVec2d::Scale), "vector"_a, "scale"_a, DOC(Bentley, Geom, DVec2d, Scale));
    c1.def("Scale", py::overload_cast<double>(&DVec2d::Scale), "scale"_a, DOC(Bentley, Geom, DVec2d, Scale));

    c1.def_static("FromSumOf",
                  py::overload_cast<DVec2dCR, double, DVec2dCR, double>(&DVec2d::FromSumOf),
                  "vector0"_a, "scale0"_a, "vector1"_a, "scale1"_a, DOC(Bentley, Geom, DVec2d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DVec2dCR, double, DVec2dCR, double, DVec2dCR, double>(&DVec2d::FromSumOf),
                  "vector0"_a, "scale0"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, DOC(Bentley, Geom, DVec2d, FromSumOf));

    c1.def("DifferenceOf", py::overload_cast<DVec2dCR, DVec2dCR>(&DVec2d::DifferenceOf), "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec2d, DifferenceOf));
    c1.def("DifferenceOf", py::overload_cast<DPoint2dCR, DPoint2dCR>(&DVec2d::DifferenceOf), "target"_a, "base"_a, DOC(Bentley, Geom, DVec2d, DifferenceOf));

    c1.def("Subtract", &DVec2d::Subtract, "vector2"_a, DOC(Bentley, Geom, DVec2d, Subtract));

    c1.def("NormalizedDifference", &DVec2d::NormalizedDifference, "target"_a, "origin"_a, DOC(Bentley, Geom, DVec2d, NormalizedDifference));
    c1.def("Normalize", py::overload_cast<DVec2dCR>(&DVec2d::Normalize), "vector"_a, DOC(Bentley, Geom, DVec2d, Normalize));
    c1.def("Normalize", py::overload_cast<>(&DVec2d::Normalize), DOC(Bentley, Geom, DVec2d, Normalize));

    c1.def("ScaleToLength", py::overload_cast<DVec2dCR, double>(&DVec2d::ScaleToLength), "vector"_a, "length"_a, DOC(Bentley, Geom, DVec2d, ScaleToLength));
    c1.def("ScaleToLength", py::overload_cast<double>(&DVec2d::ScaleToLength), "length"_a, DOC(Bentley, Geom, DVec2d, ScaleToLength));

    c1.def("SafeDivide", &DVec2d::SafeDivide, "vector"_a, "denominator"_a, DOC(Bentley, Geom, DVec2d, SafeDivide));
    c1.def("Interpolate", &DVec2d::Interpolate, "vector0"_a, "fractionParameter"_a, "vector1"_a, DOC(Bentley, Geom, DVec2d, Interpolate));    

    c1.def("RotateCCW", py::overload_cast<DVec2dCR, double>(&DVec2d::RotateCCW), "vector"_a, "theta"_a, DOC(Bentley, Geom, DVec2d, RotateCCW));
    c1.def("RotateCCW", py::overload_cast<double>(&DVec2d::RotateCCW), "theta"_a, DOC(Bentley, Geom, DVec2d, RotateCCW));
    c1.def("UnitPerpendicular", &DVec2d::UnitPerpendicular, "vector"_a, DOC(Bentley, Geom, DVec2d, UnitPerpendicular));

    c1.def("XyOf", &DVec2d::XyOf, "hPoint"_a, DOC(Bentley, Geom, DVec2d, XyOf));

    c1.def("MagnitudeSquared", &DVec2d::MagnitudeSquared, DOC(Bentley, Geom, DVec2d, MagnitudeSquared));
    c1.def("Magnitude", &DVec2d::Magnitude, DOC(Bentley, Geom, DVec2d, Magnitude));
    c1.def("MaxAbs", &DVec2d::MaxAbs, DOC(Bentley, Geom, DVec2d, MaxAbs));

    c1.def("Distance", &DVec2d::Distance, "vector2"_a, DOC(Bentley, Geom, DVec2d, Distance));
    c1.def("DistanceSquared", &DVec2d::DistanceSquared, "vector2"_a, DOC(Bentley, Geom, DVec2d, DistanceSquared));

    c1.def("GetComponent", &DVec2d::GetComponent, "index"_a, DOC(Bentley, Geom, DVec2d, GetComponent));
    c1.def("SetComponent", &DVec2d::SetComponent, "a"_a, "index"_a, DOC(Bentley, Geom, DVec2d, SetComponent));
    c1.def("GetComponents", [] (DVec2dCR v) { return py::make_tuple(v.x, v.y); });

    c1.def("DotProduct", py::overload_cast<DVec2dCR>(&DVec2d::DotProduct, py::const_), "vector2"_a, DOC(Bentley, Geom, DVec2d, DotProduct));
    c1.def("DotProduct", py::overload_cast<double, double>(&DVec2d::DotProduct, py::const_), "ax"_a, "ay"_a, DOC(Bentley, Geom, DVec2d, DotProduct));
    c1.def("DotProduct", py::overload_cast<DPoint2dCR>(&DVec2d::DotProduct, py::const_), "point2"_a, DOC(Bentley, Geom, DVec2d, DotProduct));
    c1.def("CrossProduct", &DVec2d::CrossProduct, "vector2"_a, DOC(Bentley, Geom, DVec2d, CrossProduct));
    c1.def("CrossProductSquared", &DVec2d::CrossProductSquared, "vector2"_a, DOC(Bentley, Geom, DVec2d, CrossProductSquared));
        
    c1.def("AngleTo", &DVec2d::AngleTo, "vector2"_a, DOC(Bentley, Geom, DVec2d, AngleTo));
    c1.def("SmallerUnorientedAngleTo", &DVec2d::SmallerUnorientedAngleTo, "vector2"_a, DOC(Bentley, Geom, DVec2d, SmallerUnorientedAngleTo));
    c1.def("IsVectorInSmallerSector", &DVec2d::IsVectorInSmallerSector, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec2d, IsVectorInSmallerSector));
    c1.def("IsVectorInCCWSector", &DVec2d::IsVectorInCCWSector, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec2d, IsVectorInCCWSector));
    c1.def("IsParallelTo", &DVec2d::IsParallelTo, "vector2"_a, DOC(Bentley, Geom, DVec2d, IsParallelTo));
    c1.def("IsPerpendicularTo", &DVec2d::IsPerpendicularTo, "vector2"_a, DOC(Bentley, Geom, DVec2d, IsPerpendicularTo));

    c1.def("IsEqual", py::overload_cast<DVec2dCR>(&DVec2d::IsEqual, py::const_), "vector2"_a, DOC(Bentley, Geom, DVec2d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DVec2dCR, double>(&DVec2d::IsEqual, py::const_), "vector2"_a, "tolerance"_a, DOC(Bentley, Geom, DVec2d, IsEqual));
    c1.def("AlmostEqual", &DVec2d::AlmostEqual, "vector2"_a, DOC(Bentley, Geom, DVec2d, AlmostEqual));        
    }