/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dpoint3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/OperatorOverload.h>



static const char * __doc_Bentley_Geom_DPoint3d_AlmostEqualXY =R"doc(test if two points are equal. Uses library " small angle " as both
absolute and relative tolerance. points are equal if squared distance
between is less than (squared abstol) plus (squared relTol) * sum of
cmponent squares

:param (input):
    dataB second DPoint3d

:returns:
    true if within tolerance.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_AlmostEqual =R"doc(test if two points are equal. Uses library " small angle " as both
absolute and relative tolerance. points are equal if squared distance
between is less than (squared abstol) plus (squared relTol) * sum of
cmponent squares

:param (input):
    dataB second DPoint3d

:returns:
    true if within tolerance.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromScale =R"doc(@description Returns a scalar multiple of a DPoint3d

:param (input):
    point input point

:param (input):
    scale scale factor)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromSumOf =R"doc(Add a point and a vector.

:param (input):
    origin start point

:param (input):
    vector vector add)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromInterpolateBilinear =R"doc(@description Returns a bilinear interpolation from corners
(00)(10)(01)(11)

:param (input):
    point00 point at (0,0)

:param (input):
    point10 point at (1,0)

:param (input):
    point01 point at (0,1)

:param (input):
    point11 point at (1,1)

:param (input):
    u interpolation fraction for edges (point00,point10) and
    (point01,point11)

:param (input):
    v interpolation fraction for edges (point00,point10) and
    (point10,point11))doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromWeightedAverage =R"doc(return the centroid for points with specified weights)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromInterpolateAndPerpendicularXY =R"doc(interpolate between points. Then add a shift in the xy plane by a
fraction of the XY projection perpendicular

:param (input):
    pointA start point

:param (input):
    fraction fractional parameter along the line from A to B

:param (input):
    pointB end point

:param (input):
    fractionXYPerp fractional parameter applied to vector that is the
    XY parts of (B-A), rotated CCW in plane.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromInterpolate =R"doc(interpolate between points.

:param (input):
    pointA start point

:param (input):
    fraction fractional parameter

:param (input):
    pointB end point)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromProduct =R"doc(return product of transform times point given as components.

:param (input):
    transform affine transform.

:param (input):
    x x component

:param (input):
    y y component

:param (input):
    z z component)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DivideArrayByScales =R"doc(@description Divide each point in an array by its corresponding scale
factor. Leave any point with near zero weight unchanged.

:param (output):
    pDest destination array.

:param (input):
    pSource source array.

:param (input):
    pScales scale factors

:param (input):
    n number of points.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MultiplyArrayByScales =R"doc(@description Multiply each point in an array by its corresponding
scale factor.

:param (output):
    pDest destination array.

:param (input):
    pSource source array.

:param (input):
    pScales scale factors

:param (input):
    n number of points.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DifferenceOf =R"doc(@description Subtract coordinates of two vectors or points. (Compute
Point1 - Point2)

:param (input):
    point1 The first point

:param (input):
    point2 The second (subtracted) point.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_TripleProduct =R"doc(@description Computes the triple product of three vectors. The
following are equivalent definitions of the triple product of three
vectors V1, V2, and V3:

<UL> <LI> (V1 cross V2) dot V3 <LI> V1 dot (V2 cross V3) <LI>The
determinant of the 3x3 matrix with the three vectors as its columns.
<LI>The determinant of the 3x3 matrix with the three vectors as its
rows. <LI>The (signed)volume of the parallelepiped whose 4 vertices
are at the origin and at the ends of the 3 vectors placed at the
origin. </UL>

:param (input):
    point2 The second vector.

:param (input):
    point3 The third vector.

:returns:
    The triple product)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SafeDivide =R"doc(@description Try to divide each component of a vector by a scalar. If
the denominator near zero compared to any numerator component, return
the original vector.

:param (input):
    vector The initial vector.

:param (input):
    denominator The divisor.

:returns:
    true if division is numerically safe.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsPerpendicularTo =R"doc(@description Tests if two vectors are perpendicular.

:param (input):
    point2 The second vector

:returns:
    true if vectors are perpendicular within default tolerance)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsParallelTo =R"doc(@description Tests if two vectors are parallel.

:param (input):
    point2 The second vector

:returns:
    true if the vectors are parallel within default tolerance)doc";

static const char * __doc_Bentley_Geom_DPoint3d_ScaleToLength =R"doc(@description Scales a vector to specified length. If the input vector
length is 0, the output vector is a zero vector and the returned
length is 0.

:param (input):
    vector The original vector.

:param (input):
    length The requested length.

:returns:
    The length prior to scaling.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Normalize =R"doc(@description Normalizes (scales) a vector to length 1. If the input
vector length is 0, the output vector is a zero vector and the
returned length is 0.

:param (input):
    vector The vector to be normalized.

:returns:
    The length prior to normalization)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Negate =R"doc(@description Computes a negated (opposite) vector.

:param (input):
    vector The vector to be negated.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Scale =R"doc(@description Multiplies a vector by a scale factor.

:param (input):
    vector The vector to be scaled.

:param (input):
    scale The scale factor.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_UnitPerpendicularXY =R"doc(@description Compute a unit vector perpendicular to the xy parts of
given vector.

:param (input):
    vector The source vector

:returns:
    true if the input vector has nonzero length)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MagnitudeSquaredXY =R"doc(@description Computes the squared magnitude of the xy part of a
vector.

:returns:
    The squared magnitude of the xy parts of the given vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MagnitudeXY =R"doc(@description Computes the magnitude of the xy part of a vector.

:returns:
    The magnitude of the xy parts of the given vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MagnitudeSquared =R"doc(@description Computes the squared magnitude of a vector.

:returns:
    The squared magnitude of the vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Magnitude =R"doc(@description Computes the magnitude of a vector.

:returns:
    The length of the vector)doc";

static const char * __doc_Bentley_Geom_DPoint3d_WeightedDifferenceCrossProduct =R"doc(@description Form the cross product of the weighted differences from
point0 to point1 and point2.

:param (input):
    basePoint The common base point (second point for differences)

:param (input):
    target1 The first target point.

:param (input):
    target2 The second target point.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_WeightedDifferenceOf =R"doc(@description Scale each point by the other's weight and subtract, i.e.
form (point1 * point2.w - point2 * point1.w). The weight term
vanishes. Copy the xyz parts back as a vector.

:param (input):
    point1 The first point

:param (input):
    point2 The second pont.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_PlanarAngleTo =R"doc(@description Computes the signed angle between the projection of two
vectors onto a plane with given normal.

:param (input):
    point2 The second vector

:param (input):
    planeNormal The plane normal vector

:returns:
    The angle in plane)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SignedAngleTo =R"doc(@description Computes the signed from one vector to another, in the
plane of the two vectors. Initial computation using only the two
vectors yields two possible angles depending on which side of the
plane of the vectors is viewed. To choose which side to view, go on
the side whose normal has a positive dot product with the orientation
vector. This angle can be between -pi and +pi.

:param (input):
    point2 The second vector

:param (input):
    orientationVector The vector used to determine orientation.

:returns:
    The signed angle)doc";

static const char * __doc_Bentley_Geom_DPoint3d_RotateXY =R"doc(@description Rotate vector around the z axis, return as calling
instance.

:param (input):
    vector vector to rotate.

:param (input):
    theta The rotation angle.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SmallerUnorientedAngleToXY =R"doc(@description Returns the angle between two vectors, considering both
the vectors and their negations and choosing the smaller. This angle
is between 0 and pi/2.

:param (input):
    point2 The second vector

:returns:
    The angle between vectors.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_AngleToXY =R"doc(@description Returns the angle from Vector1 to Vector2 using only xy
parts. This angle is between -pi and +pi.

:param (input):
    point2 The second vector

:returns:
    The angle between vectors.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsVectorInCCWSector =R"doc(@description Test if the test vector vector is " between " point0 and
point1, with CCW direction resolved by an up vector. The cross product
of point0 and point1 is considered the positive plane normal if its
dot product with the up vector is positive.

:param (input):
    point0 The boundary vector.

:param (input):
    point1 The boundary vector.

:param (input):
    upVector The out of plane vector.

:returns:
    true if test vector is within the angle.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsVectorInSmallerSector =R"doc(@description Test a vector is " between " point0 and point1. If the
vectors are coplanar and point0 is neither parallel nor antiparallel
to point1, betweenness has the expected meaning:there are two angles
between point0 and point1; one is less than 180; the test vector is
tested to see if it is in the smaller angle. If the vectors are not
coplanar, the test is based on the projection of the test vector into
the plane of the other two vectors.

Zero testing is untoleranced, and is biased to all parallel conditions
" false ". That is, if any pair of the input vectors is parallel or
antiparallel, the mathematical answer is false. Floating point
tolerances will cause " nearby " cases to be unpredictable. It is
assumed that if the caller considers the " parallel " cases important
they will be checked explicitly.

:param (input):
    point0 The first boundary vector.

:param (input):
    point1 The second boundary vector.

:returns:
    true if the test vector is within the angle.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SmallerUnorientedAngleTo =R"doc(@description Returns the angle between two vectors, choosing the
smaller of the two possible angles when both the vectors and their
negations are considered. This angle is between 0 and pi/2.

:param (input):
    point2 The second vector

:returns:
    The angle between the vectors.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_AngleXY =R"doc(@description Computes the (signed) angle from xy axis to the vector,
using only xy parts.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_AngleTo =R"doc(@description Returns the angle between two vectors. This angle is
between 0 and pi. Rotating the first vector by this angle around the
cross product between the vectors aligns it with the second vector.

:param (input):
    point2 The second vector

:returns:
    The angle between the vectors.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_NormalizedDifference =R"doc(@description Computes a unit vector in the direction of the difference
of the points or vectors (Second parameter vector is subtracted from
the first parameter vector, exactly as in the subtract function.)

:param (input):
    target The target point.

:param (input):
    origin The origin point.

:returns:
    The length of original difference vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DotProductXY =R"doc(@description Returns the (scalar) dot product of xy parts of two
vectors.

:param (input):
    point2 The second vector

:returns:
    The dot product of the xy parts of the two vectors)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DotProduct =R"doc(@description Returns the (scalar) dot product of two vectors.

:param (input):
    point2 The second vector

:returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DPoint3d_GeometricMeanCrossProduct =R"doc(@description Computes the cross product of two vectors and scales it
to the geometric mean of the lengths of the two vectors. This is
useful because it has the direction of the cross product (i.e. normal
to the plane of the two vectors) and a size in between the two
vectors.

:param (input):
    point1 The first vector

:param (input):
    point2 The second vector

:returns:
    The length of original vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SizedCrossProduct =R"doc(@description Computes the cross product of the two parameter vectors
and scales it to a given length. The scaled vector is stored as the
product vector, and the length of the original cross product vector is
returned.

:param (input):
    point1 The first vector

:param (input):
    point2 The second vector

:param (input):
    productLength The Desired length

:returns:
    The length of original vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_NormalizedCrossProduct =R"doc(@description Compute the normalized cross product of two vectors and
return the length of the unnormalized cross product.

:param (input):
    point1 The first vector

:param (input):
    point2 The second vector

:returns:
    The length of the original (prenormalization) cross product vector)doc";

static const char * __doc_Bentley_Geom_DPoint3d_CrossProductXY =R"doc(@description Return the (scalar) cross product of the xy parts of two
vectors.

:param (input):
    point2 The second vector

:returns:
    The 2d cross product.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_CrossProductToPoints =R"doc(@description Returns the (vector) cross product of two vectors. The
vectors are computed from the Origin to target1 and target2.

:param (input):
    origin The base point for computing vectors.

:param (input):
    target1 The target point for the first vector.

:param (input):
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_CrossProduct =R"doc(@description Returns the cross (vector) cross product of two vectors.

:param (input):
    point1 The first vector

:param (input):
    point2 The second vector)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SumOf =R"doc(@description Adds an origin and a scaled vector.

:param (input):
    origin Origin for the sum.

:param (input):
    vector The vector to be added.

:param (input):
    scale The scale factor.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_AddToArray =R"doc(Add translation to all points.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Add =R"doc(@description Adds a vector to a pointer or vector, returns the result
in place.

:param (input):
    vector The vector to add.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Subtract =R"doc(@description Subtract a vector from a point.

:param (input):
    base The the first point or vector

:param (input):
    vector The second point or vector)doc";

static const char * __doc_Bentley_Geom_DPoint3d_InitDisconnect =R"doc(Initialize a point with all coordinates as the disconnect value.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsDisconnect =R"doc(:returns:
    true if the point has coordinates which indicate it is a
    disconnect (separator) ponit.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_NpcCoordinatesOf =R"doc(@description Computes the coordinates of point under the translation
and scaling that puts 000 at cube>low and 111 at cube>high.

:param (input):
    point Point whose NPC coordinates are to be computed

:param (input):
    cube Cube whose corners map to 000 and 111)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsEqual =R"doc(@description Test for exact equality between all components of two
points or vectors.

:param (input):
    point2 The second point or vector

:returns:
    true if the points are identical.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_ComponentRange =R"doc(:returns:
    min and max of componetns.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MinAbsIndex =R"doc(return in the index of the MinAbs () value)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MaxAbsIndex =R"doc(return in the index of the MaxAbs () value.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MinAbs =R"doc(@description Finds the smallest absolute value among the components of
a point or vector.

:returns:
    The smallest absolute value among point coordinates.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_MaxAbs =R"doc(@description Finds the largest absolute value among the components of
a point or vector.

:returns:
    The largest absolute value among point coordinates.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DistanceXY =R"doc(@description Computes the distance between two points, using only x
and y components.

:param (input):
    point2 The second point

:returns:
    The distance between the XY projections of the two points. (i.e.
    any z difference is ignored))doc";

static const char * __doc_Bentley_Geom_DPoint3d_DistanceSquaredXY =R"doc(@description Computes the squared distance between two points, using
only the xy parts.

:param (input):
    point2 The second point

:returns:
    The squared distance between the XY projections of the two points.
    (i.e. any z difference is ignored))doc";

static const char * __doc_Bentley_Geom_DPoint3d_DistanceSquared =R"doc(@description Computes the squared distance between two points.

:param (input):
    point2 The second point.

:returns:
    The squared distance between the points.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Distance =R"doc(@description Computes the (cartesian) distance between two points

:param (input):
    point2 The second point

:returns:
    The distance between points.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsPointInCCWector =R"doc(@description Test if a point is within the counter-clockwise sector
defined by an origin and two boundary points, with an up vector to
determine which direction is counter clockwise.

:param (input):
    origin The point to test.

:param (input):
    target0 The first target point.

:param (input):
    target1 The second target point.

:param (input):
    upVector vector towards eye to resolve direction.

:returns:
    true if the test point is within the angle.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_IsPointInSmallerSector =R"doc(@description Form vectors from the origin to the test point and the
two boundary vectors. Test if the test vector is within the smaller
angle between the other two vectors.

:param (input):
    origin The point to test.

:param (input):
    target1 The first target point.

:param (input):
    target2 The second target point.

:returns:
    true if the test point is within the angle.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Interpolate =R"doc(@description Computes a point whose position is given by a fractional
argument and two endpoints.

:param (input):
    point0 The point corresponding to fractionParameter of 0.

:param (input):
    fractionParameter The fractional parametric coordinate. 0.0 is the
    start of the segment, 1.0 is the end, 0.5 is midpoint.

:param (input):
    point1 The point corresponding to fractionParameter of 1.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_GetComponent =R"doc(@description Gets a single component of a point. If the index is out
of range 0,1,2, it is interpreted cyclically.

:param (input):
    index Indicates which component is accessed. The values are 0=x,
    1=y, 2=z. Other values are treated cyclically.

:returns:
    The specified component of the point or vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_SetComponent =R"doc(@description Set one of three components (x,y,z) of the point.

:param (input):
    a The component value.

:param (input):
    index Selects the the axis:0=x, 1=y, 2=z, others cyclic.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_XyzOf =R"doc(@description Sets the x,y, and z components of a DPoint3d structure
from the corresponding parts of a DPoint4d. Weight part of DPoint4d is
not used.

:param (input):
    hPoint The homogeneous point)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Init =R"doc(@description Copy from a 2d point setting z to zero.

:param (input):
    source source point)doc";

static const char * __doc_Bentley_Geom_DPoint3d_One =R"doc(@description Returns a point or vector with all components 1.0.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Zero =R"doc(@description Sets all components of a point or vector to zero.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_TripleProductToPoints =R"doc(@description Computes the triple product of vectors from a base point
three target points.

:param (input):
    target1 The target point for the first vector.

:param (input):
    target2 The target point for the second vector.

:param (input):
    target3 The target point for the third vector.

:returns:
    The triple product)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DotDifference =R"doc(@description Returns the (scalar) dot product of a two vectors. One
vector is computed internally as the difference of the TargetPoint and
Origin. (TargetPoint-Origin) The other is given directly as a single
argument.

:param (input):
    origin The start (orign) point of the first vector of the cross
    product.

:param (input):
    vector The second)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DotProductToPointsXY =R"doc(@description Returns the (scalar) dot product of xy parts of two
vectors. The vectors are computed from the BasePoint to target1 and
target2.

:param (input):
    target1 The target point for the first vector.

:param (input):
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_DotProductToPoints =R"doc(@description Returns the (scalar) dot product of two vectors. The
vectors are computed from the Origin to target1 and target2.

:param (input):
    target1 The target point for the first vector.

:param (input):
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_CrossProductToPointsXY =R"doc(@description Returns the (scalar) cross product of the xy parts of two
vectors. The vectors are computed from the Origin to target1 and
target2.

:param (input):
    target1 The target point for the first vector.

:param (input):
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_Swap =R"doc(Swap contents of instance, other.

:param [in,out]:
    other second point.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromOne =R"doc(Return a DPoint3d with xyz = 1.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_FromZero =R"doc(Return a DPoint3d with xyz = 0.)doc";

static const char * __doc_Bentley_Geom_DPoint3d_From =R"doc(Return a DPoint3d with given xyz.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DPoint3d(py::module_& m)
    {
    //===================================================================================
    // struct DPoint3d
    py::class_<DPoint3d> c1(m, "DPoint3d");
    py::bind_vector<DPoint3dArray>(m, "DPoint3dArray", py::module_local(false));
    py::bind_vector<DPoint3dVecArray>(m, "DPoint3dVecArray", py::module_local(false));
    py::bind_vector<DPoint3dVecVecArray>(m, "DPoint3dVecVecArray", py::module_local(false));
    bind_ValidatedValue<DPoint3d>(m, "ValidatedDPoint3d", py::module_local(false));
    bind_ValueSizeSize<DPoint3d>(m, "DPoint3dSizeSize", py::module_local(false));
    bind_BlockedVector<DPoint3d>(m, "BlockedVectorDPoint3d", py::module_local(false));

    c1.def_readwrite("x", &DPoint3d::x);
    c1.def_readwrite("y", &DPoint3d::y);
    c1.def_readwrite("z", &DPoint3d::z);

    c1.def_readwrite("X", &DPoint3d::x);
    c1.def_readwrite("Y", &DPoint3d::y);
    c1.def_readwrite("Z", &DPoint3d::z);

    c1.def(py::init([] (DVec3d const& v) { return DPoint3d::From(v.x, v.y, v.z); }), "vector"_a);
    c1.def(py::init(&DPoint3d::FromZero));
    c1.def(py::init(py::overload_cast<double, double, double>(&DPoint3d::From)), "x"_a, "y"_a, "z"_a = 0.0);
    c1.def(py::init(py::overload_cast<DPoint2dCR>(&DPoint3d::From)), "xy"_a);  
    
    c1.def(py::self + DVec3d());
    c1.def(py::self - DVec3d());
    c1.def(py::self - py::self);
    c1.def(py::self == py::self);

    c1.def("__iadd__", [](DPoint3dR self, DPoint3dCR b)
        {
        self.x += b.x; self.y += b.y; self.z += b.z;
        return self;
        }, py::is_operator());

    c1.def("__iadd__", [](DPoint3dR self, DVec3dCR b)
        {
        self += b;
        return self;
        }, py::is_operator());

    c1.def("__isub__", [](DPoint3dR self, DPoint3dCR b)
        {
        self.x -= b.x; self.y -= b.y; self.z -= b.z;
        return self;
        }, py::is_operator());

    c1.def("__isub__", [](DPoint3dR self, DVec3dCR b)
        {
        self -= b;
        return self;
        }, py::is_operator());

    c1.def("__copy__", [](const DPoint3d& self)
        {
        return DPoint3d (self);
        });

    c1.def_static("From", py::overload_cast<double, double, double>(&DPoint3d::From), "x"_a, "y"_a, "z"_a = 0.0, DOC(Bentley, Geom, DPoint3d, From));
    c1.def_static("From", py::overload_cast<DPoint2dCR>(&DPoint3d::From), "xy"_a, DOC(Bentley, Geom, DPoint3d, From));        
    c1.def_static("FromZero", &DPoint3d::FromZero, DOC(Bentley, Geom, DPoint3d, FromZero));
    c1.def_static("FromOne", &DPoint3d::FromOne, DOC(Bentley, Geom, DPoint3d, FromOne));

    c1.def("Swap", &DPoint3d::Swap, "other"_a, DOC(Bentley, Geom, DPoint3d, Swap));
    c1.def("CrossProductToPointsXY", &DPoint3d::CrossProductToPointsXY, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint3d, CrossProductToPointsXY));
    c1.def("DotProductToPoints", &DPoint3d::DotProductToPoints, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint3d, DotProductToPoints));
    c1.def("DotProductToPointsXY", &DPoint3d::DotProductToPointsXY, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint3d, DotProductToPointsXY));
    c1.def("DotDifference", &DPoint3d::DotDifference, "origin"_a, "vector"_a, DOC(Bentley, Geom, DPoint3d, DotDifference));
    c1.def("TripleProductToPoints", &DPoint3d::TripleProductToPoints, "target1"_a, "target2"_a, "target3"_a, DOC(Bentley, Geom, DPoint3d, TripleProductToPoints));
    c1.def("Zero", &DPoint3d::Zero, DOC(Bentley, Geom, DPoint3d, Zero));
    c1.def("One", &DPoint3d::One, DOC(Bentley, Geom, DPoint3d, One));

    c1.def("Init", py::overload_cast<DPoint2dCR>(&DPoint3d::Init), "source"_a, DOC(Bentley, Geom, DPoint3d, Init));
    c1.def("Init", py::overload_cast<double, double, double>(&DPoint3d::Init), "ax"_a, "ay"_a, "az"_a, DOC(Bentley, Geom, DPoint3d, Init));
    c1.def("Init", py::overload_cast<double, double>(&DPoint3d::Init), "ax"_a, "ay"_a, DOC(Bentley, Geom, DPoint3d, Init));
    c1.def("Init", py::overload_cast<DVec3dCR>(&DPoint3d::Init), "vector"_a, DOC(Bentley, Geom, DPoint3d, Init));

    c1.def("XyzOf", &DPoint3d::XyzOf, "hPoint"_a, DOC(Bentley, Geom, DPoint3d, XyzOf));
    c1.def("SetComponent", &DPoint3d::SetComponent, "a"_a, "index"_a, DOC(Bentley, Geom, DPoint3d, SetComponent));
    c1.def("GetComponent", &DPoint3d::GetComponent, "index"_a, DOC(Bentley, Geom, DPoint3d, GetComponent));        
    c1.def("GetComponents", [] (DPoint3dCR pt) { return std::make_tuple(pt.x, pt.y, pt.z); });

    c1.def("Interpolate", &DPoint3d::Interpolate, "point0"_a, "fractionParameter"_a, "point1"_a, DOC(Bentley, Geom, DPoint3d, Interpolate));
    c1.def("IsPointInSmallerSector", &DPoint3d::IsPointInSmallerSector, "origin"_a, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint3d, IsPointInSmallerSector));
    c1.def("IsPointInCCWector", &DPoint3d::IsPointInCCWector, "origin"_a, "target0"_a, "target1"_a, "upVector"_a, DOC(Bentley, Geom, DPoint3d, IsPointInCCWector));

    c1.def("Distance", &DPoint3d::Distance, "point2"_a, DOC(Bentley, Geom, DPoint3d, Distance));
    c1.def("DistanceSquared", &DPoint3d::DistanceSquared, "point2"_a, DOC(Bentley, Geom, DPoint3d, DistanceSquared));

    c1.def("DistanceSquaredXY", &DPoint3d::DistanceSquaredXY, "point2"_a, DOC(Bentley, Geom, DPoint3d, DistanceSquaredXY));

    c1.def("DistanceXY", py::overload_cast<DPoint3dCR>(&DPoint3d::DistanceXY, py::const_), "point2"_a, DOC(Bentley, Geom, DPoint3d, DistanceXY));

    c1.def("DistanceXY", [] (DPoint3dCR self, DPoint3dCR otherPoint, DMatrix4dCP matrix)
        {
        double distance = 0;
        bool bOk = self.DistanceXY(otherPoint, matrix, distance);
        return py::make_tuple(bOk, distance);
        }, "otherPoint"_a, "matrix"_a, DOC(Bentley, Geom, DPoint3d, DistanceXY));

        
    c1.def("MaxAbs", &DPoint3d::MaxAbs, DOC(Bentley, Geom, DPoint3d, MaxAbs));
    c1.def("MinAbs", &DPoint3d::MinAbs, DOC(Bentley, Geom, DPoint3d, MinAbs));
    c1.def("MaxAbsIndex", &DPoint3d::MaxAbsIndex, DOC(Bentley, Geom, DPoint3d, MaxAbsIndex));
    c1.def("MinAbsIndex", &DPoint3d::MinAbsIndex, DOC(Bentley, Geom, DPoint3d, MinAbsIndex));
    c1.def("ComponentRange", &DPoint3d::ComponentRange, DOC(Bentley, Geom, DPoint3d, ComponentRange));
        
    c1.def("IsEqual", py::overload_cast<DPoint3dCR>(&DPoint3d::IsEqual, py::const_), "point2"_a, DOC(Bentley, Geom, DPoint3d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DPoint3dCR, double>(&DPoint3d::IsEqual, py::const_), "point2"_a, "tolerance"_a, DOC(Bentley, Geom, DPoint3d, IsEqual));
        
    c1.def("NpcCoordinatesOf", &DPoint3d::NpcCoordinatesOf, "point"_a, "cube"_a, DOC(Bentley, Geom, DPoint3d, NpcCoordinatesOf));

    c1.def("IsDisconnect", &DPoint3d::IsDisconnect, DOC(Bentley, Geom, DPoint3d, IsDisconnect));
    c1.def("InitDisconnect", &DPoint3d::InitDisconnect, DOC(Bentley, Geom, DPoint3d, InitDisconnect));    

    c1.def("Subtract", py::overload_cast<DPoint3dCR, DVec3dCR>(&DPoint3d::Subtract), "base"_a, "vector"_a, DOC(Bentley, Geom, DPoint3d, Subtract));
    c1.def("Subtract", py::overload_cast<DPoint3dCR>(&DPoint3d::Subtract), "point2"_a, DOC(Bentley, Geom, DPoint3d, Subtract));

    c1.def("Add", py::overload_cast<DVec3dCR>(&DPoint3d::Add), "vector"_a, DOC(Bentley, Geom, DPoint3d, Add));
    c1.def("Add", py::overload_cast<DPoint3dCR>(&DPoint3d::Add), "vector"_a, DOC(Bentley, Geom, DPoint3d, Add));

    c1.def_static("AddToArray", [] (DPoint3dArray& points, DPoint3dCR delta)
        {
        if (!points.empty())
            DPoint3d::AddToArray(&points[0], (int) points.size(), delta);
        }, "points"_a, "delta"_a, DOC(Bentley, Geom, DPoint3d, AddToArray));

    c1.def_static("AddToArray", [](py::list &points, DPoint3dCR delta)
        {
        if (!points.empty()){
            CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cppPoints, DPoint3dArray, DPoint3d);
            DPoint3d::AddToArray(&cppPoints[0], (int) cppPoints.size(), delta);
            CONVERT_CPPARRAY_TO_PYLIST(points, cppPoints, DPoint3dArray, DPoint3d);
        } }, "points"_a, "delta"_a, DOC(Bentley, Geom, DPoint3d, AddToArray));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DVec3dCR, double>(&DPoint3d::SumOf),
           "origin"_a, "vector"_a, "scale"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DVec3dCR, double, DVec3dCR, double>(&DPoint3d::SumOf),
           "origin"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DVec3dCR, double, DVec3dCR, double, DVec3dCR, double>(&DPoint3d::SumOf),
           "origin"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, "point3"_a, "scale3"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DPoint3dCR, double>(&DPoint3d::SumOf),
           "origin"_a, "vector"_a, "scale"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::SumOf),
           "origin"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DPoint3dCR, double, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::SumOf),
           "origin"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, "point3"_a, "scale3"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::SumOf),
           "point1"_a, "a1"_a, "point2"_a, "a2"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, double, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::SumOf),
           "point1"_a, "a1"_a, "point2"_a, "a2"_a, "point3"_a, "a3"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint3dCR, DPoint3dCR>(&DPoint3d::SumOf),
           "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint3d, SumOf));

    c1.def("CrossProduct", &DPoint3d::CrossProduct, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint3d, CrossProduct));
    c1.def("CrossProductToPoints", &DPoint3d::CrossProductToPoints, "origin"_a, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint3d, CrossProductToPoints));
    c1.def("CrossProductXY", &DPoint3d::CrossProductXY, "point2"_a, DOC(Bentley, Geom, DPoint3d, CrossProductXY));
    c1.def("NormalizedCrossProduct", &DPoint3d::NormalizedCrossProduct, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint3d, NormalizedCrossProduct));
    c1.def("SizedCrossProduct", &DPoint3d::SizedCrossProduct, "point1"_a, "point2"_a, "productLength"_a, DOC(Bentley, Geom, DPoint3d, SizedCrossProduct));
    c1.def("GeometricMeanCrossProduct", &DPoint3d::GeometricMeanCrossProduct, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint3d, GeometricMeanCrossProduct));

    c1.def("DotProduct", py::overload_cast<DPoint3dCR>(&DPoint3d::DotProduct, py::const_), "point2"_a, DOC(Bentley, Geom, DPoint3d, DotProduct));
    c1.def("DotProduct", py::overload_cast<double, double, double>(&DPoint3d::DotProduct, py::const_), "ax"_a, "ay"_a, "az"_a, DOC(Bentley, Geom, DPoint3d, DotProduct));
    c1.def("DotProductXY", &DPoint3d::DotProductXY, "point2"_a, DOC(Bentley, Geom, DPoint3d, DotProductXY));
        
    c1.def("NormalizedDifference", &DPoint3d::NormalizedDifference, "target"_a, "origin"_a, DOC(Bentley, Geom, DPoint3d, NormalizedDifference));
    c1.def("AngleTo", &DPoint3d::AngleTo, "point2"_a, DOC(Bentley, Geom, DPoint3d, AngleTo));
    c1.def("AngleXY", &DPoint3d::AngleXY, DOC(Bentley, Geom, DPoint3d, AngleXY));        
    c1.def("SmallerUnorientedAngleTo", &DPoint3d::SmallerUnorientedAngleTo, "point2"_a, DOC(Bentley, Geom, DPoint3d, SmallerUnorientedAngleTo));

    c1.def("IsVectorInSmallerSector", &DPoint3d::IsVectorInSmallerSector, "point0"_a, "point1"_a, DOC(Bentley, Geom, DPoint3d, IsVectorInSmallerSector));
    c1.def("IsVectorInCCWSector", &DPoint3d::IsVectorInCCWSector, "point0"_a, "point1"_a, "upVector"_a, DOC(Bentley, Geom, DPoint3d, IsVectorInCCWSector));

    c1.def("AngleToXY", &DPoint3d::AngleToXY, "point2"_a, DOC(Bentley, Geom, DPoint3d, AngleToXY));
    c1.def("SmallerUnorientedAngleToXY", &DPoint3d::SmallerUnorientedAngleToXY, "point2"_a, DOC(Bentley, Geom, DPoint3d, SmallerUnorientedAngleToXY));

    c1.def("RotateXY", py::overload_cast<DPoint3dCR, double>(&DPoint3d::RotateXY), "vector"_a, "theta"_a, DOC(Bentley, Geom, DPoint3d, RotateXY));
    c1.def("RotateXY", py::overload_cast<double>(&DPoint3d::RotateXY), "theta"_a, DOC(Bentley, Geom, DPoint3d, RotateXY));

    c1.def("SignedAngleTo", &DPoint3d::SignedAngleTo, "point2"_a, "orientationVector"_a, DOC(Bentley, Geom, DPoint3d, SignedAngleTo));
    c1.def("PlanarAngleTo", &DPoint3d::PlanarAngleTo, "point2"_a, "planeNormal"_a, DOC(Bentley, Geom, DPoint3d, PlanarAngleTo));
    c1.def("WeightedDifferenceOf", &DPoint3d::WeightedDifferenceOf, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint3d, WeightedDifferenceOf));
    c1.def("WeightedDifferenceCrossProduct", &DPoint3d::WeightedDifferenceCrossProduct, "basePoint"_a, "target1"_a, "target2"_a, DOC(Bentley, Geom, DPoint3d, WeightedDifferenceCrossProduct));

    c1.def("Magnitude", &DPoint3d::Magnitude, DOC(Bentley, Geom, DPoint3d, Magnitude));    
    c1.def("MagnitudeSquared", &DPoint3d::MagnitudeSquared, DOC(Bentley, Geom, DPoint3d, MagnitudeSquared));
    c1.def("MagnitudeXY", &DPoint3d::MagnitudeXY, DOC(Bentley, Geom, DPoint3d, MagnitudeXY));
    c1.def("MagnitudeSquaredXY", &DPoint3d::MagnitudeSquaredXY, DOC(Bentley, Geom, DPoint3d, MagnitudeSquaredXY));

    c1.def("UnitPerpendicularXY", &DPoint3d::UnitPerpendicularXY, "vector"_a, DOC(Bentley, Geom, DPoint3d, UnitPerpendicularXY));

    c1.def("Scale", py::overload_cast<DPoint3dCR, double>(&DPoint3d::Scale), "vector"_a, "scale"_a, DOC(Bentley, Geom, DPoint3d, Scale));
    c1.def("Scale", py::overload_cast<double>(&DPoint3d::Scale), "scale"_a, DOC(Bentley, Geom, DPoint3d, Scale));
    c1.def("Negate", py::overload_cast<DPoint3dCR>(&DPoint3d::Negate), "vector"_a, DOC(Bentley, Geom, DPoint3d, Negate));
    c1.def("Negate", py::overload_cast<>(&DPoint3d::Negate), DOC(Bentley, Geom, DPoint3d, Negate));
    c1.def("Normalize", py::overload_cast<DPoint3dCR>(&DPoint3d::Normalize), "vector"_a, DOC(Bentley, Geom, DPoint3d, Normalize));
    c1.def("Normalize", py::overload_cast<>(&DPoint3d::Normalize), DOC(Bentley, Geom, DPoint3d, Normalize));
    c1.def("ScaleToLength", py::overload_cast<DPoint3dCR, double>(&DPoint3d::ScaleToLength), "vector"_a, "length"_a, DOC(Bentley, Geom, DPoint3d, ScaleToLength));
    c1.def("ScaleToLength", py::overload_cast<double>(&DPoint3d::ScaleToLength), "length"_a, DOC(Bentley, Geom, DPoint3d, ScaleToLength));
    c1.def("IsParallelTo", &DPoint3d::IsParallelTo, "point2"_a, DOC(Bentley, Geom, DPoint3d, IsParallelTo));
    c1.def("IsPerpendicularTo", &DPoint3d::IsPerpendicularTo, "point2"_a, DOC(Bentley, Geom, DPoint3d, IsPerpendicularTo));
    c1.def("SafeDivide", &DPoint3d::SafeDivide, "vector"_a, "denominator"_a, DOC(Bentley, Geom, DPoint3d, SafeDivide));
    c1.def("TripleProduct", &DPoint3d::TripleProduct, "point2"_a, "point3"_a, DOC(Bentley, Geom, DPoint3d, TripleProduct));
    
    c1.def("DifferenceOf", &DPoint3d::DifferenceOf, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint3d, DifferenceOf));
        
    c1.def_static("MultiplyArrayByScales", [] (DPoint3dArray& outPoints, DPoint3dArray const& inPoints, DoubleArray& scales)
        {
        if (outPoints.size() != inPoints.size() || inPoints.size() != scales.size() || scales.empty())
            return;

        DPoint3d::MultiplyArrayByScales(outPoints.data(), inPoints.data(), scales.data(), (int) scales.size());            
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));

    c1.def_static("MultiplyArrayByScales", [] (py::list& outList, DPoint3dArray const& inPoints, DoubleArray& scales) {
            if (outList.size() != inPoints.size() || inPoints.size() != scales.size() || scales.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::MultiplyArrayByScales(cppOut.data(), inPoints.data(), scales.data(), (int)scales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("MultiplyArrayByScales", [] (DPoint3dArray& outPoints, py::list const& inList, DoubleArray& scales) {
            if (outPoints.size() != inList.size() || inList.size() != scales.size() || scales.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            DPoint3d::MultiplyArrayByScales(outPoints.data(), cppIn.data(), scales.data(), (int)scales.size());
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("MultiplyArrayByScales", [] (DPoint3dArray& outPoints, DPoint3dArray const& inPoints, py::list& scaleList) {
            if (outPoints.size() != inPoints.size() || inPoints.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            DPoint3d::MultiplyArrayByScales(outPoints.data(), inPoints.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("MultiplyArrayByScales", [] (py::list& outList, py::list const& inList, DoubleArray& scales) {
            if (outList.size() != inList.size() || inList.size() != scales.size() || scales.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::MultiplyArrayByScales(cppOut.data(), cppIn.data(), scales.data(), (int)scales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("MultiplyArrayByScales", [] (py::list& outList, DPoint3dArray const& inPoints, py::list& scaleList) {
            if (outList.size() != inPoints.size() || inPoints.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::MultiplyArrayByScales(cppOut.data(), inPoints.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("MultiplyArrayByScales", [] (DPoint3dArray& outPoints, py::list const& inList, py::list& scaleList) {
            if (outPoints.size() != inList.size() || inList.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            DPoint3d::MultiplyArrayByScales(outPoints.data(), cppIn.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("MultiplyArrayByScales", [] (py::list outList, py::list inList, py::list scaleList) {
            if (outList.size() != inList.size() || inList.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::MultiplyArrayByScales(cppOut.data(), cppIn.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, MultiplyArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (DPoint3dArray& outPoints, DPoint3dArray const& inPoints, DoubleArray& scales)
        {
        if (outPoints.size() != inPoints.size() || inPoints.size() != scales.size() || scales.empty())
            return;

        DPoint3d::DivideArrayByScales(outPoints.data(), inPoints.data(), scales.data(), (int) scales.size());
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));

    c1.def_static("DivideArrayByScales", [] (py::list& outList, DPoint3dArray const& inPoints, DoubleArray& scales) {
            if (outList.size() != inPoints.size() || inPoints.size() != scales.size() || scales.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::DivideArrayByScales(cppOut.data(), inPoints.data(), scales.data(), (int)scales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (DPoint3dArray& outPoints, py::list const& inList, DoubleArray& scales) {
            if (outPoints.size() != inList.size() || inList.size() != scales.size() || scales.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            DPoint3d::DivideArrayByScales(outPoints.data(), cppIn.data(), scales.data(), (int)scales.size());
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (DPoint3dArray& outPoints, DPoint3dArray const& inPoints, py::list& scaleList) {
            if (outPoints.size() != inPoints.size() || inPoints.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            DPoint3d::DivideArrayByScales(outPoints.data(), inPoints.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (py::list& outList, py::list const& inList, DoubleArray& scales) {
            if (outList.size() != inList.size() || inList.size() != scales.size() || scales.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::DivideArrayByScales(cppOut.data(), cppIn.data(), scales.data(), (int)scales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (py::list& outList, DPoint3dArray const& inPoints, py::list& scaleList) {
            if (outList.size() != inPoints.size() || inPoints.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::DivideArrayByScales(cppOut.data(), inPoints.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (DPoint3dArray& outPoints, py::list const& inList, py::list& scaleList) {
            if (outPoints.size() != inList.size() || inList.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            DPoint3d::DivideArrayByScales(outPoints.data(), cppIn.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));
    
    c1.def_static("DivideArrayByScales", [] (py::list outList, py::list inList, py::list scaleList) {
            if (outList.size() != inList.size() || inList.size() != scaleList.size() || scaleList.empty())
                return;
            CONVERT_PYLIST_TO_NEW_CPPARRAY(inList, cppIn, DPoint3dArray, DPoint3d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(scaleList, cppScales, DoubleArray, double);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(outList, cppOut, DPoint3dArray, DPoint3d);
            DPoint3d::DivideArrayByScales(cppOut.data(), cppIn.data(), cppScales.data(), (int)cppScales.size());
            CONVERT_CPPARRAY_TO_PYLIST(outList, cppOut, DPoint3dArray, DPoint3d);
            CONVERT_CPPARRAY_TO_PYLIST(scaleList, cppScales, DoubleArray, double);
        }, "outPoints"_a, "inPoints"_a, "scales"_a, DOC(Bentley, Geom, DPoint3d, DivideArrayByScales));

    c1.def_static("FromProduct", py::overload_cast<TransformCR, double, double, double>(&DPoint3d::FromProduct), "transform"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, DPoint3d, FromProduct));
    c1.def_static("FromProduct", py::overload_cast<TransformCR, DPoint3dCR>(&DPoint3d::FromProduct), "transform"_a, "point"_a, DOC(Bentley, Geom, DPoint3d, FromProduct));
    c1.def_static("FromInterpolate", &DPoint3d::FromInterpolate, "pointA"_a, "fraction"_a, "pointB"_a, DOC(Bentley, Geom, DPoint3d, FromInterpolate));
    c1.def_static("FromInterpolateAndPerpendicularXY", &DPoint3d::FromInterpolateAndPerpendicularXY, "pointA"_a, "fraction"_a, "pointB"_a, "fractionXYPerp"_a, DOC(Bentley, Geom, DPoint3d, FromInterpolateAndPerpendicularXY));

    c1.def_static("FromWeightedAverage",
                  py::overload_cast<DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::FromWeightedAverage),
                  "pointA"_a, "weightA"_a, "pointB"_a, "weightB"_a, DOC(Bentley, Geom, DPoint3d, FromWeightedAverage));

    c1.def_static("FromWeightedAverage",
                  py::overload_cast<DPoint3dCR, double, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::FromWeightedAverage),
                  "pointA"_a, "weightA"_a, "pointB"_a, "weightB"_a, "pointC"_a, "weightC"_a, DOC(Bentley, Geom, DPoint3d, FromWeightedAverage));
        
    c1.def_static("FromInterpolateBilinear", &DPoint3d::FromInterpolateBilinear, "point00"_a, "point10"_a, "point01"_a, "point11"_a, "u"_a, "v"_a, DOC(Bentley, Geom, DPoint3d, FromInterpolateBilinear));

    c1.def_static("FromSumOf", 
                  py::overload_cast<DPoint3dCR, DPoint3dCR>(&DPoint3d::FromSumOf), 
                  "origin"_a, "vector"_a, DOC(Bentley, Geom, DPoint3d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint3dCR, DPoint3dCR, double>(&DPoint3d::FromSumOf),
                  "origin"_a, "vector"_a, "scaleFactor"_a, DOC(Bentley, Geom, DPoint3d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint3dCR, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::FromSumOf),
                  "origin"_a, "point0"_a, "scaleFactor0"_a, "point1"_a, "scaleFactor1"_a, DOC(Bentley, Geom, DPoint3d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint3dCR, DPoint3dCR, double, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::FromSumOf),
                  "origin"_a, "point0"_a, "scaleFactor0"_a, "point1"_a, "scaleFactor1"_a, "point2"_a, "scaleFactor2"_a, DOC(Bentley, Geom, DPoint3d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::FromSumOf),
                  "point0"_a, "scale0"_a, "point1"_a, "scale1"_a, DOC(Bentley, Geom, DPoint3d, FromSumOf));

    c1.def_static("FromSumOf",
                  py::overload_cast<DPoint3dCR, double, DPoint3dCR, double, DPoint3dCR, double>(&DPoint3d::FromSumOf),
                  "point0"_a, "scale0"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint3d, FromSumOf));

    c1.def_static("FromScale", &DPoint3d::FromScale, "point"_a, "scale"_a, DOC(Bentley, Geom, DPoint3d, FromScale));

    c1.def_static("FromProduct",
                  py::overload_cast<DPoint3dCR, RotMatrixCR, double, double, double>(&DPoint3d::FromProduct),
                  "point"_a, "matrix"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, DPoint3d, FromProduct));

    c1.def_static("FromProduct",
                  py::overload_cast<DPoint3dCR, RotMatrixCR, DVec3dCR>(&DPoint3d::FromProduct),
                  "point"_a, "matrix"_a, "vector"_a, DOC(Bentley, Geom, DPoint3d, FromProduct));

    c1.def("AlmostEqual",
           py::overload_cast<DPoint3dCR>(&DPoint3d::AlmostEqual, py::const_),
           "dataB"_a, DOC(Bentley, Geom, DPoint3d, AlmostEqual));

    c1.def("AlmostEqual",
           py::overload_cast<DPoint3dCR, double>(&DPoint3d::AlmostEqual, py::const_),
           "dataB"_a, "abstol"_a, DOC(Bentley, Geom, DPoint3d, AlmostEqual));

    c1.def("AlmostEqualXY",
           py::overload_cast<DPoint3dCR>(&DPoint3d::AlmostEqualXY, py::const_),
           "dataB"_a, DOC(Bentley, Geom, DPoint3d, AlmostEqualXY));

    c1.def("AlmostEqualXY",
           py::overload_cast<DPoint3dCR, double>(&DPoint3d::AlmostEqualXY, py::const_),
           "dataB"_a, "abstol"_a, DOC(Bentley, Geom, DPoint3d, AlmostEqualXY));    

    c1.def("__repr__", [] (DPoint3dCR self) { return "[{}, {}, {}]"_s.format(self.x, self.y, self.z); });
    }