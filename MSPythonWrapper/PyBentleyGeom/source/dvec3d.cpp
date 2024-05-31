/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dvec3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/OperatorOverload.h>

static const char* __doc_Bentley_Geom_DVec3d_InitFromXYAngleAndMagnitude = R"doc( Sets a vector from given angle and distance in xy plane. Z part is set to zero

Parameter ``[in]``:
    theta Angle from X axis to the vector, in the xy plane

Parameter ``[in]``:
    magnitude Vector magnitude)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsZero =R"doc( checks if the vector has all zeros)doc";

static const char * __doc_Bentley_Geom_DVec3d_AlmostEqual =R"doc(test if two points are equal. Uses library " small angle " as both
absolute and relative tolerance. points are equal if squared distance
between is less than (squared abstol) plus (squared relTol) * sum of
cmponent squares

Parameter ``[in]``:
    dataB second DVec3d

Returns:
    true if within tolerance.)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsEqual =R"doc( Test for exact equality between all components of two
vectors.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if the vectors are identical.)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsPerpendicularTo =R"doc( Tests if two vectors are perpendicular.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if vectors are perpendicular within tolerance)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsPositiveParallelTo =R"doc( Tests if two vectors are parallel and have positive dot
product (opposites are NOT considered parallel)

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if the vectors are parallel within tolerance)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsParallelTo =R"doc( Tests if two vectors are parallel (opposites are
considered parallel!)

Parameter ``[in]``:
    vector2 The second vector

Returns:
    true if the vectors are parallel within tolerance)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsVectorInCCWXYSector =R"doc( Test if the instance vector vector is " between " vector0
and vector1, with CCW direction using only xy parts.

Parameter ``[in]``:
    vector0 The boundary vector.

Parameter ``[in]``:
    vector1 The boundary vector.

Returns:
    true if test vector is within the angle.)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsVectorInCCWSector =R"doc( Test if the test vector vector is " between " vector0 and
vector1, with CCW direction resolved by an up vector. The cross
product of vector0 and vector1 is considered the positive plane normal
if its dot product with the up vector is positive.

Parameter ``[in]``:
    vector0 The boundary vector.

Parameter ``[in]``:
    vector1 The boundary vector.

Parameter ``[in]``:
    upVector The out of plane vector.

Returns:
    true if test vector is within the angle.)doc";

static const char * __doc_Bentley_Geom_DVec3d_IsVectorInSmallerSector =R"doc( Test a vector is " between " vector0 and vector1. If the
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

static const char * __doc_Bentley_Geom_DVec3d_AngleAndAxisOfRotationFromVectorToVector =R"doc(Compute an axis and angle to rotate from the instance vector to a
target.

Parameter ``[out]``:
    target direction that the instance is to rotate towards.

Parameter ``[out]``:
    axis returned axis of rotation

Parameter ``[out]``:
    radians returned rotation angle

Returns:
    true if both vectors are nonzero.)doc";

static const char * __doc_Bentley_Geom_DVec3d_PlanarAngleTo =R"doc( Computes the signed angle between the projection of two
vectors onto a plane with given normal.

Parameter ``[in]``:
    vector2 The second vector

Parameter ``[in]``:
    planeNormal The plane normal vector

Returns:
    The angle in plane)doc";

static const char * __doc_Bentley_Geom_DVec3d_SignedAngleTo =R"doc( Computes the signed angle from one vector to another, in
the plane of the two vectors. Initial computation using only the two
vectors yields two possible angles depending on which side of the
plane of the vectors is viewed. To choose which side to view, go on
the side whose normal has a positive dot product with the orientation
vector. This angle can be between -pi and +pi.

Parameter ``[in]``:
    vector2 The second vector

Parameter ``[in]``:
    orientationVector The vector used to determine orientation.

Returns:
    The signed angle)doc";

static const char * __doc_Bentley_Geom_DVec3d_AngleFromPerpendicular =R"doc( Returns the angle that two vectors deviate from being
perpendicular.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SmallerUnorientedAngleToXY =R"doc( Returns the angle between two vectors, considering both
the vectors and their negations and choosing the smaller. This angle
is between 0 and pi/2.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The angle between vectors.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SmallerUnorientedAngleTo =R"doc( Returns the angle between two vectors, choosing the
smaller of the two possible angles when both the vectors and their
negations are considered. This angle is between 0 and pi/2.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The angle between the vectors.)doc";

static const char * __doc_Bentley_Geom_DVec3d_AngleToXY =R"doc( Returns the angle from Vector1 to Vector2 using only xy
parts. This angle is between -pi and +pi.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The angle between vectors.)doc";

static const char * __doc_Bentley_Geom_DVec3d_AngleTo =R"doc( Returns the angle between two vectors. This angle is
between 0 and pi. Rotating the first vector by this angle around the
cross product between the vectors aligns it with the second vector.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The angle between the vectors.)doc";

static const char * __doc_Bentley_Geom_DVec3d_GetPerpendicularParts =R"doc(Decompose hypotenuse into a vector parallel to the instance and a
vector perpendicular to the instance.

Parameter ``[in]``:
    hypotenuse vector to decompose

Parameter ``[out]``:
    fraction position where hypotenuse projects onto the instance.

Parameter ``[out]``:
    parallelPart vector parallel to the instance

Parameter ``[out]``:
    perpendicularPart vector perpendicular to the instance)doc";

static const char * __doc_Bentley_Geom_DVec3d_ProjectToPlane =R"doc(Find the projection of the instance vector to a plane defined by two
vectors.

Parameter ``[in]``:
    vectorU u-direction vector of the plane.

Parameter ``[in]``:
    vectorV v-direction vector of the plane.

Parameter ``[out]``:
    uv fractional coordinates on vectors.

Returns:
    false if plane vectors are not independent. In this case the
    method attempts to project to the longer plane vector, and sets
    the other fraction to 0. If that fails uv is 00.)doc";

static const char * __doc_Bentley_Geom_DVec3d_ProjectToVector =R"doc(Find the fraction at which the instance projects to a vector.

Parameter ``[in]``:
    targetVector target vector.

Parameter ``[out]``:
    fraction projection fraction

Returns:
    false if targetVector has zero length. In this case the fraction
    is zero.)doc";

static const char * __doc_Bentley_Geom_DVec3d_GetNormalizedTriad =R"doc( Sets three vectors so that they are mutually
perpendicular unit vectors with the third (Z) vector in the direction
of the given axis vector. If the given axis vector contains only
zeros, a (0,0,1) vector is used instead.

Parameter ``[out]``:
    xAxis unit x direction vector

Parameter ``[out]``:
    yAxis unit y direction vector

Parameter ``[out]``:
    zAxis unit z direction vector

Returns:
    true unless given vector has zero length.)doc";

static const char * __doc_Bentley_Geom_DVec3d_GetTriad =R"doc( Sets three vectors so that they are mutually
perpendicular, the third (Z) vector is identical to the given axis
vector, and all have the same length. If the given axis vector
contains only zeros, a (0,0,1) vector is used instead.

Parameter ``[out]``:
    xAxis x direction of the coordinate system

Parameter ``[out]``:
    yAxis y direction of the coordinate system

Parameter ``[out]``:
    zAxis z direction of the coordinate system

Returns:
    true unless given vector is z zero vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_GetComponent =R"doc( Gets a single component of a vector. If the index is out
of range 0,1,2, it is interpreted cyclically.

Parameter ``[in]``:
    index Indicates which component is accessed. The values are 0=x,
    1=y, 2=z. Other values are treated cyclically.

Returns:
    The specified component of the vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SetComponent =R"doc( Set one of three components (x,y,z) of the vector.

Parameter ``[in]``:
    a The component value.

Parameter ``[in]``:
    index Selects the the axis:0=x, 1=y, 2=z, others cyclic.)doc";

static const char * __doc_Bentley_Geom_DVec3d_CrossProductXY =R"doc( Return the (scalar) cross product of the xy parts of two
vectors.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The 2d cross product.)doc";

static const char * __doc_Bentley_Geom_DVec3d_CrossProductMagnitude =R"doc(Compute the cross product with other and return is magnitude (but the
cross product is not returned)

Parameter ``[in]``:
    other second vector of cross product)doc";

static const char * __doc_Bentley_Geom_DVec3d_DistanceXY =R"doc( Computes the distance between two vectors, using only x
and y components.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The distance between the XY projections of the two vectors. (i.e.
    any z difference is ignored))doc";

static const char * __doc_Bentley_Geom_DVec3d_DistanceSquaredXY =R"doc( Computes the squared distance between two vectors, using
only the xy parts.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The squared distance between the XY projections of the two
    vectors. (i.e. any z difference is ignored))doc";

static const char * __doc_Bentley_Geom_DVec3d_DistanceSquared =R"doc( Computes the squared distance between two vectors.

Parameter ``[in]``:
    vector2 The second vector.

Returns:
    The squared distance between the vectors.)doc";

static const char * __doc_Bentley_Geom_DVec3d_Distance =R"doc( Computes the (cartesian) distance between two vectors

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The distance between vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_MaxAbs =R"doc( Finds the largest absolute value among the components of
a vector.

Returns:
    The largest absolute value among vector coordinates.)doc";

static const char * __doc_Bentley_Geom_DVec3d_MagnitudeSquaredXY =R"doc( Computes the squared magnitude of the xy part of a
vector.

Returns:
    The squared magnitude of the xy parts of the given vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_MagnitudeXY =R"doc( Computes the magnitude of the xy part of a vector.

Returns:
    The magnitude of the xy parts of the given vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_ValidatedFractionOfProjection =R"doc( Returns fraction at which other projects onto this, in
ValidatedDouble which records if the division was safe.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SafeOneOverMagnitudeSquared =R"doc( Returns 1 over the squared magnitude, or caller supplied
default if squared magnitude is too small.)doc";

static const char * __doc_Bentley_Geom_DVec3d_MagnitudeSquared =R"doc( Computes the squared magnitude of a vector.

Returns:
    The squared magnitude of the vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_Magnitude =R"doc( Computes the magnitude of a vector.

Returns:
    The length of the vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_TripleProduct =R"doc( Computes the triple product of three vectors. The
following are equivalent definitions of the triple product of three
vectors V1, V2, and V3:

<UL> <LI> (V1 cross V2) dot V3 <LI> V1 dot (V2 cross V3) <LI>The
determinant of the 3x3 matrix with the three vectors as its columns.
<LI>The determinant of the 3x3 matrix with the three vectors as its
rows. <LI>The (signed)volume of the parallelepiped whose 4 vertices
are at the origin and at the ends of the 3 vectors placed at the
origin. </UL>

Parameter ``[in]``:
    vector2 The second vector.

Parameter ``[in]``:
    vector3 The third vector.

Returns:
    The triple product)doc";

static const char * __doc_Bentley_Geom_DVec3d_DotProductMatrixColumn =R"doc(Returns the (scalar) dot product of this vector and a column of the
matrix part of the transform.

Parameter ``[in]``:
    matrix

Parameter ``[in]``:
    index column index.

Returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec3d_DotProductMatrixRow =R"doc(Returns the (scalar) dot product of this vector and a row of the
matrix part of the transform.

Parameter ``[in]``:
    matrix

Parameter ``[in]``:
    index row index.

Returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec3d_DotProductColumn =R"doc( Returns the (scalar) dot product of this vector and a
column of a matrix.

Parameter ``[in]``:
    matrix

Parameter ``[in]``:
    index column index.

Returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec3d_DotProductRow =R"doc(Returns the (scalar) dot product of this vector and a row of a matrix.

Parameter ``[in]``:
    matrix

Parameter ``[in]``:
    index row index.

Returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec3d_DotProductXY =R"doc( Returns the (scalar) dot product of xy parts of two
vectors.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The dot product of the xy parts of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec3d_DotProduct =R"doc( Returns the (scalar) dot product of two vectors.

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The dot product of the two vectors)doc";

static const char * __doc_Bentley_Geom_DVec3d_WeightedDifferenceCrossProduct =R"doc( Form the cross product of the weighted differences from
base poitn to two targets

Parameter ``[in]``:
    basePoint The common base point (second point for differences)

Parameter ``[in]``:
    target1 The first target point.

Parameter ``[in]``:
    target2 The second target point.)doc";

static const char * __doc_Bentley_Geom_DVec3d_WeightedDifferenceOf =R"doc( Scale each (homogeneous) point by the other's weight and
subtract, i.e. form (point1 * point2.w - point2 * point1.w). The
weight term vanishes. Copy the xyz parts back as a vector.

Parameter ``[in]``:
    hPoint1 The first homogeneous point

Parameter ``[in]``:
    hPoint2 The second homogeneous point.)doc";

static const char * __doc_Bentley_Geom_DVec3d_Negate =R"doc( Computes a negated (opposite) vector.

Parameter ``[in]``:
    vector The vector to be negated.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SafeDivide =R"doc( Try to divide each component of a vector by a scalar. If
the denominator near zero compared to any numerator component, return
the original vector.

Parameter ``[in]``:
    vector The initial vector.

Parameter ``[in]``:
    denominator The divisor.

Returns:
    true if division is numerically safe.)doc";

static const char * __doc_Bentley_Geom_DVec3d_Scale =R"doc( Multiplies a vector by a scale factor.

Parameter ``[in]``:
    vector The vector to be scaled.

Parameter ``[in]``:
    scale The scale factor.)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromScale =R"doc( Returns a scalar multiple of a DVec3d

Parameter ``[in]``:
    vector input vector

Parameter ``[in]``:
    scale scale factor)doc";

static const char * __doc_Bentley_Geom_DVec3d_Add =R"doc( Adds a vector to a pointer or vector, returns the result
in place.

Parameter ``[in]``:
    vector The vector to add.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SumOf =R"doc( Compute the sum of two vectors.

Parameter ``[in]``:
    vector1 The the first vector

Parameter ``[in]``:
    vector2 The second vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromInterpolateBilinear =R"doc( Returns a bilinear interpolation from corners
(00)(10)(01)(11)

Parameter ``[in]``:
    vector00 vector at (0,0)

Parameter ``[in]``:
    vector10 vector at (1,0)

Parameter ``[in]``:
    vector01 vector at (0,1)

Parameter ``[in]``:
    vector11 vector at (1,1)

Parameter ``[in]``:
    u interpolation fraction for edges (vector00,vector10) and
    (vector01,vector11)

Parameter ``[in]``:
    v interpolation fraction for edges (vector00,vector10) and
    (vector10,vector11))doc";

static const char * __doc_Bentley_Geom_DVec3d_Interpolate =R"doc( Computes a vector whose position is given by a fractional
argument and two vectors.

Parameter ``[in]``:
    vector0 The vector corresponding to fractionParameter of 0.

Parameter ``[in]``:
    fractionParameter The fractional parametric coordinate. 0.0 is the
    start of the segment, 1.0 is the end, 0.5 is middle

Parameter ``[in]``:
    vector1 The vector corresponding to fractionParameter of 1.)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromInterpolate =R"doc( Returns an interpolated vector.

Parameter ``[in]``:
    vector0 vector at fraction 0

Parameter ``[in]``:
    fraction fraction from interpolation.

Parameter ``[in]``:
    vector1 vector at fraction 1)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromUnitPerpendicularXY =R"doc( Compute a unit vector perpendicular to the xy parts of
given vector.

Parameter ``[in]``:
    vector The source vector

Returns:
    perpendicular vector, marked invalid if unable to divide.)doc";

static const char * __doc_Bentley_Geom_DVec3d_UnitPerpendicularXY =R"doc( Compute a unit vector perpendicular to the xy parts of
given vector.

Parameter ``[in]``:
    vector The source vector

Returns:
    true if the input vector has nonzero length)doc";

static const char * __doc_Bentley_Geom_DVec3d_RotateXY =R"doc( Rotate a vector around the z axis.

Parameter ``[in]``:
    vector vector to rotate.

Parameter ``[in]``:
    theta The rotation angle.)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromColumnCrossProduct =R"doc( return the cross product of vectors found in columns a
matrix

Parameter ``[in]``:
    matrix source transform

Parameter ``[in]``:
    i first column index

Parameter ``[in]``:
    j second column index)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromMatrixColumnCrossProduct =R"doc( return the cross product of vectors found in columns of
(the matrix part of) a transform.

Parameter ``[in]``:
    transform source transform

Parameter ``[in]``:
    i first column index

Parameter ``[in]``:
    j second column index)doc";

static const char * __doc_Bentley_Geom_DVec3d_GeometricMeanCrossProduct =R"doc( Computes the cross product of two vectors and scales it
to the geometric mean of the lengths of the two vectors. This is
useful because it has the direction of the cross product (i.e. normal
to the plane of the two vectors) and a size in between the two
vectors.

Parameter ``[in]``:
    vector1 The first vector

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The The length of unscaled cross product.)doc";

static const char * __doc_Bentley_Geom_DVec3d_SizedCrossProduct =R"doc( Computes the cross product of the two parameter vectors
and scales it to a given length. The scaled vector is stored as the
product vector, and the length of the original cross product vector is
returned.

Parameter ``[in]``:
    vector1 The first vector

Parameter ``[in]``:
    vector2 The second vector

Parameter ``[in]``:
    productLength The Desired length

Returns:
    The The length of unscaled cross product.)doc";

static const char * __doc_Bentley_Geom_DVec3d_NormalizedCrossProduct =R"doc( Compute the normalized cross product of two vectors and
return the length of the unnormalized cross product.

Parameter ``[in]``:
    vector1 The first vector

Parameter ``[in]``:
    vector2 The second vector

Returns:
    The length of the original (prenormalization) cross product vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromNormalizedCrossProduct =R"doc( return the normalized cross product of vectors

Parameter ``[in]``:
    vector0 first vector

Parameter ``[in]``:
    vector1 second vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromNormalizedCrossProductToPoints =R"doc( Returns the (normalized vector) cross product of two
vectors. The vectors are computed from the Origin to Target1 and
Target2. If the cross product is zero, a zero vector is returned.

Parameter ``[in]``:
    origin The base point for computing vectors.

Parameter ``[in]``:
    target1 The target point for the first vector.

Parameter ``[in]``:
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromCrossProductToPoints =R"doc( Returns the (vector) cross product of two vectors. The
vectors are computed from the Origin to Target1 and Target2.

Parameter ``[in]``:
    origin The base point for computing vectors.

Parameter ``[in]``:
    target1 The target point for the first vector.

Parameter ``[in]``:
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_CrossProductToPoints =R"doc( Sets the instance to the (vector) cross product of two
vectors. The vectors are computed from the Origin to Target1 and
Target2.

Parameter ``[in]``:
    origin The base point for computing vectors.

Parameter ``[in]``:
    target1 The target point for the first vector.

Parameter ``[in]``:
    target2 The target point for the second vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_CrossProduct =R"doc( Returns the (vector) cross product of two vectors.

Parameter ``[in]``:
    vector1 The first vector

Parameter ``[in]``:
    vector2 The second vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromCrossProduct =R"doc( return the cross product of vectors

Parameter ``[in]``:
    vector0 first vector

Parameter ``[in]``:
    vector1 second vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_XyzOf =R"doc( Sets the x,y, and z components of a DVec3d structure from
the corresponding parts of a DPoint4d. Weight part of DPoint4d is not
used.

Parameter ``[in]``:
    hPoint The homogeneous point)doc";

static const char * __doc_Bentley_Geom_DVec3d_MultiplyTranspose =R"doc( Returns the product of a matrix transpose times a vector.

Parameter ``[in]``:
    matrix The the matrix.

Parameter ``[in]``:
    vector The known vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_Multiply =R"doc( Returns the product of a matrix times a vector.

Parameter ``[in]``:
    matrix The matrix.

Parameter ``[in]``:
    vector The known vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromRow =R"doc( return a (cyclically indexed) row of the matrix.

Parameter ``[in]``:
    matrix source

Parameter ``[in]``:
    i row index)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromColumn =R"doc( return a (cyclically indexed) column of the matrix.

Parameter ``[in]``:
    matrix source

Parameter ``[in]``:
    i column index)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromMatrixRow =R"doc( return a (cyclically indexed) row of the matrix part of a
transform.

Parameter ``[in]``:
    transform source transform

Parameter ``[in]``:
    i row index)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromMatrixColumn =R"doc( return a (cyclically indexed) column of the matrix part
of a transform.

Parameter ``[in]``:
    transform source transform

Parameter ``[in]``:
    i column index)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromTranslation =R"doc( return the translation xyz as a DVec3d (which you can
pass as a DPoint3d where needed.)

Parameter ``[in]``:
    source source transform)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromXYAngleAndMagnitude =R"doc( Returns a DVec3d from given angle and distance in xy
plane. Z part is set to zero.

Parameter ``[in]``:
    theta Angle from X axis to the vector, in the xy plane.

Parameter ``[in]``:
    magnitude Vector magnitude)doc";

static const char * __doc_Bentley_Geom_DVec3d_Subtract =R"doc( Subtract two vectors, and return the result in place of
the first.

Parameter ``[in]``:
    vector2 The vector to subtract.)doc";

static const char * __doc_Bentley_Geom_DVec3d_DifferenceOf =R"doc( Subtract coordinates of two vectors. (Compute Vector1 -
Vector2)

Parameter ``[in]``:
    vector1 The first vector

Parameter ``[in]``:
    vector2 The second (subtracted) vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_NormalizedDifference =R"doc( Computes a unit vector in the direction of the difference
of the vectors or vectors (Second parameter vector is subtracted from
the first parameter vector, exactly as in the subtract function.)

Remark:
    In the 0-length error case, the vector is set to (1,0,0) in the
    legacy microstation style.

Parameter ``[in]``:
    target The target point.

Parameter ``[in]``:
    origin The origin point.

Returns:
    The length of original difference vector.)doc";

static const char * __doc_Bentley_Geom_DVec3d_ScaleToLength =R"doc( Scales a vector to specified length.

Remark:
    In the 0-length error case, the vector is set to (1,0,0) in the
    legacy microstation style.

Parameter ``[in]``:
    vector The original vector.

Parameter ``[in]``:
    length The requested length.

Returns:
    The length prior to scaling.)doc";

static const char * __doc_Bentley_Geom_DVec3d_ValidatedNormalize =R"doc( return a (possibly invalid) unit vector in the direction
of the calling instance.)doc";

static const char * __doc_Bentley_Geom_DVec3d_TryNormalize =R"doc( initialize this vector to unit vector in the direction of
source.

Remark:
    In the 0-length error case, the vector is set to (1,0,0) in the
    legacy microstation style.

Parameter ``[in]``:
    source The vector to be normalized.

Parameter ``[out]``:
    magnitude The orignal magnitude of the source vector;

Returns:
    true if the other vector length is large enough for
    DoubleOps::SafeDivide to compute 1/length.)doc";

static const char * __doc_Bentley_Geom_DVec3d_Normalize =R"doc( Normalizes (scales) a vector to length 1.

Remark:
    In the 0-length error case, the vector is set to (1,0,0) in the
    legacy microstation style.

Parameter ``[in]``:
    vector The vector to be normalized.

Returns:
    The length prior to normalization)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromRotateVectorAroundVector =R"doc( return a vector same length as source but rotated by
angle around axis. (Rodriguez formula))doc";

static const char * __doc_Bentley_Geom_DVec3d_FromRotate90Around =R"doc( return a vector same length as source but rotate 90
degrees around axis)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromRotate90Towards =R"doc( return a vector same length as source but rotate 90
degrees towards target)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromCCWPerpendicularXY =R"doc( return a vector same length as source but rotate 90
degrees CCW)doc";

static const char * __doc_Bentley_Geom_DVec3d_FromStartEndNormalize =R"doc( Returns a vector from start towards end, normalized if
nonzero.

Parameter ``[in]``:
    start start point

Parameter ``[in]``:
    end end point)doc";

static const char * __doc_Bentley_Geom_DVec3d_UnitZ =R"doc( unit Z vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_UnitY =R"doc( unit Y vector)doc";

static const char * __doc_Bentley_Geom_DVec3d_UnitX =R"doc( unit X vector)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DVec3d(py::module_& m)
    {
    //===================================================================================
    // struct DVec3d
    py::class_<DVec3d, DPoint3d> c1(m, "DVec3d");
    py::bind_vector<DVec3dArray>(m, "DVec3dArray", py::module_local(false));
    py::bind_vector<DVec3dVecArray>(m, "DVec3dVecArray", py::module_local(false));
    bind_ValidatedValue<DVec3d>(m, "ValidatedDVec3d", py::module_local(false));
    bind_BlockedVector<DVec3d>(m, "BlockedVectorDVec3d", py::module_local(false));

    c1.def_static("UnitX", &DVec3d::UnitX, DOC(Bentley, Geom, DVec3d, UnitX));
    c1.def_static("UnitY", &DVec3d::UnitY, DOC(Bentley, Geom, DVec3d, UnitY));
    c1.def_static("UnitZ", &DVec3d::UnitZ, DOC(Bentley, Geom, DVec3d, UnitZ));

    c1.def(py::init(&DVec3d::FromZero));
    c1.def(py::init(py::overload_cast<double, double, double>(&DVec3d::From)), "ax"_a, "ay"_a, "az"_a = 0.0);
    c1.def(py::init(py::overload_cast<DPoint3dCR>(&DVec3d::From)), "point"_a);
    c1.def(py::init(py::overload_cast<DVec2dCR>(&DVec3d::From)), "vector"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, DPoint3dCR>(&DVec3d::FromStartEnd)), "start"_a, "end"_a);
    c1.def(py::init(py::overload_cast<DPoint4dCR, DPoint4dCR>(&DVec3d::FromStartEnd)), "start"_a, "end"_a);
    c1.def(py::init(py::overload_cast<TransformCR, DPoint3dCR>(&DVec3d::FromStartEnd)), "start"_a, "target"_a);  

    c1.def(py::self * Transform());
    c1.def(py::self * RotMatrix());
    c1.def(py::self - py::self);
    c1.def(py::self + py::self);
    c1.def(py::self / double());
    c1.def(double() * py::self);
    c1.def(py::self * double());

    c1.def("__iadd__", [](DVec3dR self, DVec3dCR b)
        {
        self += b;
        return self;
        }, py::is_operator());

    c1.def("__iadd__", [](DVec3dR self, DPoint3dCR b)
        {
        self.x += b.x; self.y += b.y; self.z += b.z;
        return self;
        }, py::is_operator());

    c1.def("__isub__", [](DVec3dR self, DVec3dCR b)
        {
        self -= b;
        return self;
        }, py::is_operator());

    c1.def("__isub__", [](DVec3dR self, DPoint3dCR b)
        {
        self.x -= b.x; self.y -= b.y; self.z -= b.z;
        return self;
        }, py::is_operator());

    c1.def("__imul__", [](DVec3dR self, double const scalar)
        {
        self *= scalar;
        return self;
        }, py::is_operator()); 

    c1.def("__copy__", [](const DVec3d& self)
        {
        return DVec3d(self);
        });

    c1.def_static("From", py::overload_cast<DPoint3dCR>(&DVec3d::From), "point"_a);
    c1.def_static("From", py::overload_cast<DVec2dCR>(&DVec3d::From), "vector"_a);
    c1.def_static("From", py::overload_cast<double, double, double>(&DVec3d::From), "az"_a, "ay"_a, "az"_a = 0.0);
    c1.def_static("FromStartEnd", py::overload_cast<DPoint3dCR, DPoint3dCR>(&DVec3d::FromStartEnd), "start"_a, "end"_a);

    c1.def_static("FromStartEndNormalize", &DVec3d::FromStartEndNormalize, "start"_a, "end"_a, DOC(Bentley, Geom, DVec3d, FromStartEndNormalize));
    c1.def_static("FromCCWPerpendicularXY", &DVec3d::FromCCWPerpendicularXY, "source"_a, DOC(Bentley, Geom, DVec3d, FromCCWPerpendicularXY));
    c1.def_static("FromRotate90Towards", &DVec3d::FromRotate90Towards, "source"_a, "target"_a, DOC(Bentley, Geom, DVec3d, FromRotate90Towards));
    c1.def_static("FromRotate90Around", &DVec3d::FromRotate90Around, "source"_a, "target"_a, DOC(Bentley, Geom, DVec3d, FromRotate90Around));
    c1.def_static("FromRotateVectorAroundVector", &DVec3d::FromRotateVectorAroundVector, "source"_a, "axis"_a, "angle"_a, DOC(Bentley, Geom, DVec3d, FromRotateVectorAroundVector));

    c1.def("Normalize", py::overload_cast<DVec3dCR>(&DVec3d::Normalize), "vector"_a, DOC(Bentley, Geom, DVec3d, Normalize));
    c1.def("Normalize", py::overload_cast<>(&DVec3d::Normalize), DOC(Bentley, Geom, DVec3d, Normalize));
    c1.def("TryNormalize", [] (DVec3dR self, DVec3dCR source)
           {
           double magnitude = 0;
           bool bOk = self.TryNormalize(source, magnitude);
           return py::make_tuple(bOk, magnitude);
           }, "source"_a, DOC(Bentley, Geom, DVec3d, TryNormalize));

    c1.def("ValidatedNormalize", &DVec3d::ValidatedNormalize, DOC(Bentley, Geom, DVec3d, ValidatedNormalize));

    c1.def("ScaleToLength", py::overload_cast<DVec3dCR, double>(&DVec3d::ScaleToLength), "vector"_a, "length"_a, DOC(Bentley, Geom, DVec3d, ScaleToLength));
    c1.def("ScaleToLength", py::overload_cast<double>(&DVec3d::ScaleToLength), "length"_a, DOC(Bentley, Geom, DVec3d, ScaleToLength));
    c1.def("NormalizedDifference", &DVec3d::NormalizedDifference, "target"_a, "origin"_a, DOC(Bentley, Geom, DVec3d, NormalizedDifference));
    c1.def("DifferenceOf", py::overload_cast<DVec3dCR, DVec3dCR>(&DVec3d::DifferenceOf), "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec3d, DifferenceOf));
    c1.def("DifferenceOf", py::overload_cast<DPoint3dCR, DPoint3dCR>(&DVec3d::DifferenceOf), "target"_a, "base"_a, DOC(Bentley, Geom, DVec3d, DifferenceOf));
    c1.def("Subtract", &DVec3d::Subtract, "vector2"_a, DOC(Bentley, Geom, DVec3d, Subtract));

    c1.def_static("FromXYAngleAndMagnitude", &DVec3d::FromXYAngleAndMagnitude, "theta"_a, "magnitude"_a, DOC(Bentley, Geom, DVec3d, FromXYAngleAndMagnitude));
    c1.def_static("FromTranslation", &DVec3d::FromTranslation, "source"_a, DOC(Bentley, Geom, DVec3d, FromTranslation));
    c1.def_static("FromMatrixColumn", &DVec3d::FromMatrixColumn, "transform"_a, "i"_a, DOC(Bentley, Geom, DVec3d, FromMatrixColumn));
    c1.def_static("FromMatrixRow", &DVec3d::FromMatrixRow, "transform"_a, "i"_a, DOC(Bentley, Geom, DVec3d, FromMatrixRow));
    c1.def_static("FromColumn", &DVec3d::FromColumn, "matrix"_a, "i"_a, DOC(Bentley, Geom, DVec3d, FromColumn));
    c1.def_static("FromRow", &DVec3d::FromRow, "matrix"_a, "i"_a, DOC(Bentley, Geom, DVec3d, FromRow));

    c1.def("Multiply", py::overload_cast<RotMatrixCR, DVec3dCR>(&DVec3d::Multiply), "matrix"_a, "vector"_a, DOC(Bentley, Geom, DVec3d, Multiply));
    c1.def("Multiply", py::overload_cast<RotMatrixCR, double, double, double>(&DVec3d::Multiply), "matrix"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, DVec3d, Multiply));

    c1.def("MultiplyTranspose", py::overload_cast<RotMatrixCR, DVec3dCR>(&DVec3d::MultiplyTranspose), "matrix"_a, "vector"_a, DOC(Bentley, Geom, DVec3d, MultiplyTranspose));
    c1.def("MultiplyTranspose", py::overload_cast<RotMatrixCR, double, double, double>(&DVec3d::MultiplyTranspose), "matrix"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, DVec3d, MultiplyTranspose));

    c1.def("XyzOf", &DVec3d::XyzOf, "hPoint"_a, DOC(Bentley, Geom, DVec3d, XyzOf));

    c1.def_static("FromCrossProduct", py::overload_cast<DVec3dCR, DVec3dCR>(&DVec3d::FromCrossProduct), "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, FromCrossProduct));
    c1.def_static("FromCrossProduct",
                  py::overload_cast<double, double, double, double, double, double>(&DVec3d::FromCrossProduct),
                  "x0"_a, "y0"_a, "z0"_a, "x1"_a, "y1"_a, "z1"_a, DOC(Bentley, Geom, DVec3d, FromCrossProduct));

    c1.def("CrossProduct", py::overload_cast<DVec3dCR, DVec3dCR>(&DVec3d::CrossProduct), "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec3d, CrossProduct));
    c1.def("CrossProduct", py::overload_cast<DVec3dCR, DPoint3dCR>(&DVec3d::CrossProduct), "vector1"_a, "point2"_a, DOC(Bentley, Geom, DVec3d, CrossProduct));
    c1.def("CrossProduct", py::overload_cast<DPoint3dCR, DVec3dCR>(&DVec3d::CrossProduct), "point1"_a, "vector2"_a, DOC(Bentley, Geom, DVec3d, CrossProduct));

    c1.def("CrossProductToPoints", &DVec3d::CrossProductToPoints, "origin"_a, "target1"_a, "arget2"_a, DOC(Bentley, Geom, DVec3d, CrossProductToPoints));
    c1.def_static("FromCrossProductToPoints", &DVec3d::FromCrossProductToPoints, "origin"_a, "target1"_a, "arget2"_a, DOC(Bentley, Geom, DVec3d, FromCrossProductToPoints));
    c1.def_static("FromNormalizedCrossProductToPoints", &DVec3d::FromNormalizedCrossProductToPoints, "origin"_a, "target1"_a, "arget2"_a, DOC(Bentley, Geom, DVec3d, FromNormalizedCrossProductToPoints));

    c1.def_static("FromNormalizedCrossProduct", &DVec3d::FromNormalizedCrossProduct, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, FromNormalizedCrossProduct));

    c1.def("NormalizedCrossProduct", &DVec3d::NormalizedCrossProduct, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, NormalizedCrossProduct));

    c1.def("SizedCrossProduct", &DVec3d::SizedCrossProduct, "vector0"_a, "vector1"_a, "productLength"_a, DOC(Bentley, Geom, DVec3d, SizedCrossProduct));

    c1.def("GeometricMeanCrossProduct", &DVec3d::GeometricMeanCrossProduct, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, GeometricMeanCrossProduct));

    c1.def_static("FromMatrixColumnCrossProduct", &DVec3d::FromMatrixColumnCrossProduct, "transform"_a, "i"_a, "j"_a, DOC(Bentley, Geom, DVec3d, FromMatrixColumnCrossProduct));

    c1.def_static("FromColumnCrossProduct", &DVec3d::FromColumnCrossProduct, "matrix"_a, "i"_a, "j"_a, DOC(Bentley, Geom, DVec3d, FromColumnCrossProduct));

    c1.def("RotateXY", py::overload_cast<DVec3dCR, double>(&DVec3d::RotateXY), "vector"_a, "theta"_a, DOC(Bentley, Geom, DVec3d, RotateXY));

    c1.def("RotateXY", py::overload_cast<double>(&DVec3d::RotateXY), "theta"_a, DOC(Bentley, Geom, DVec3d, RotateXY));

    c1.def("UnitPerpendicularXY", &DVec3d::UnitPerpendicularXY, "vector"_a, DOC(Bentley, Geom, DVec3d, UnitPerpendicularXY));

    c1.def_static("FromUnitPerpendicularXY", &DVec3d::FromUnitPerpendicularXY, "vector"_a, DOC(Bentley, Geom, DVec3d, FromUnitPerpendicularXY));

    c1.def_static("FromInterpolate", &DVec3d::FromInterpolate, "vector0"_a, "fraction"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, FromInterpolate));

    c1.def("Interpolate", &DVec3d::Interpolate, "vector0"_a, "fraction"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, Interpolate));

    c1.def_static("FromInterpolateBilinear",
                  &DVec3d::FromInterpolateBilinear,
                  "vector00"_a, "vector10"_a, "vector01"_a, "vector11"_a, "u"_a, "v"_a, DOC(Bentley, Geom, DVec3d, FromInterpolateBilinear));

    c1.def("SumOf",
           py::overload_cast<DVec3dCR, DVec3dCR>(&DVec3d::SumOf),
           "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DVec3dCR, double, DVec3dCR, double>(&DVec3d::SumOf),
           "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, DOC(Bentley, Geom, DVec3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DVec3dCR, double, DVec3dCR, double, DVec3dCR, double>(&DVec3d::SumOf),
           "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, "vector3"_a, "scale3"_a, DOC(Bentley, Geom, DVec3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DVec3dCR, DVec3dCR, double>(&DVec3d::SumOf),
           "origin"_a, "vector"_a, "scale"_a, DOC(Bentley, Geom, DVec3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DVec3dCR, DVec3dCR, double, DVec3dCR, double>(&DVec3d::SumOf),
           "origin"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, DOC(Bentley, Geom, DVec3d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DVec3dCR, DVec3dCR, double, DVec3dCR, double, DVec3dCR, double>(&DVec3d::SumOf),
           "origin"_a, "vector1"_a, "scale1"_a, "vector2"_a, "scale2"_a, "vector3"_a, "scale3"_a, DOC(Bentley, Geom, DVec3d, SumOf));

    c1.def("Add", &DVec3d::Add, "vector"_a, DOC(Bentley, Geom, DVec3d, Add));

    c1.def_static("FromScale", &DVec3d::FromScale, "vector"_a, "scale"_a, DOC(Bentley, Geom, DVec3d, FromScale));

    c1.def("Scale", py::overload_cast<DVec3dCR, double>(&DVec3d::Scale), "vector"_a, "scale"_a, DOC(Bentley, Geom, DVec3d, Scale));
    c1.def("Scale", py::overload_cast<double>(&DVec3d::Scale), "scale"_a, DOC(Bentley, Geom, DVec3d, Scale));

    c1.def("SafeDivide", &DVec3d::SafeDivide, "vector"_a, "denominator"_a, DOC(Bentley, Geom, DVec3d, SafeDivide));

    c1.def("Negate", py::overload_cast<DVec3dCR>(&DVec3d::Negate), "vector"_a, DOC(Bentley, Geom, DVec3d, Negate));
    c1.def("Negate", py::overload_cast<>(&DVec3d::Negate), DOC(Bentley, Geom, DVec3d, Negate));

    c1.def("WeightedDifferenceOf", &DVec3d::WeightedDifferenceOf, "hPoint1"_a, "hPoint2"_a, DOC(Bentley, Geom, DVec3d, WeightedDifferenceOf));
    c1.def("WeightedDifferenceCrossProduct", &DVec3d::WeightedDifferenceCrossProduct, "basePoint"_a, "target1"_a, "target2"_a, DOC(Bentley, Geom, DVec3d, WeightedDifferenceCrossProduct));

    c1.def("DotProduct", py::overload_cast<DVec3dCR>(&DVec3d::DotProduct, py::const_), "vector2"_a, DOC(Bentley, Geom, DVec3d, DotProduct));
    c1.def("DotProduct", py::overload_cast<double, double, double>(&DVec3d::DotProduct, py::const_), "az"_a, "ay"_a, "az"_a, DOC(Bentley, Geom, DVec3d, DotProduct));
    c1.def("DotProduct", py::overload_cast<DPoint3dCR>(&DVec3d::DotProduct, py::const_), "point2"_a, DOC(Bentley, Geom, DVec3d, DotProduct));
    c1.def("DotProductXY", &DVec3d::DotProductXY, "vector2"_a, DOC(Bentley, Geom, DVec3d, DotProductXY));
    c1.def("DotProductRow", &DVec3d::DotProductRow, "matrix"_a, "index"_a, DOC(Bentley, Geom, DVec3d, DotProductRow));
    c1.def("DotProductColumn", &DVec3d::DotProductColumn, "matrix"_a, "index"_a, DOC(Bentley, Geom, DVec3d, DotProductColumn));
    c1.def("DotProductMatrixRow", &DVec3d::DotProductMatrixRow, "matrix"_a, "index"_a, DOC(Bentley, Geom, DVec3d, DotProductMatrixRow));
    c1.def("DotProductMatrixColumn", &DVec3d::DotProductMatrixColumn, "matrix"_a, "index"_a, DOC(Bentley, Geom, DVec3d, DotProductMatrixColumn));

    c1.def("TripleProduct", &DVec3d::TripleProduct, "vector2"_a, "vector3"_a, DOC(Bentley, Geom, DVec3d, TripleProduct));

    c1.def("Magnitude", &DVec3d::Magnitude, DOC(Bentley, Geom, DVec3d, Magnitude));
    c1.def("MagnitudeSquared", &DVec3d::MagnitudeSquared, DOC(Bentley, Geom, DVec3d, MagnitudeSquared));

    c1.def("SafeOneOverMagnitudeSquared", &DVec3d::SafeOneOverMagnitudeSquared, "defaultValue"_a, DOC(Bentley, Geom, DVec3d, SafeOneOverMagnitudeSquared));

    c1.def("ValidatedFractionOfProjection", &DVec3d::ValidatedFractionOfProjection, "vectorToProject"_a, "defaultValue"_a = 0.0, DOC(Bentley, Geom, DVec3d, ValidatedFractionOfProjection));

    c1.def("MagnitudeXY", &DVec3d::MagnitudeXY, DOC(Bentley, Geom, DVec3d, MagnitudeXY));
    c1.def("MagnitudeSquaredXY", &DVec3d::MagnitudeSquaredXY, DOC(Bentley, Geom, DVec3d, MagnitudeSquaredXY));
    c1.def("MaxAbs", &DVec3d::MaxAbs, DOC(Bentley, Geom, DVec3d, MaxAbs));

    c1.def("Distance", &DVec3d::Distance, "vector2"_a, DOC(Bentley, Geom, DVec3d, Distance));
    c1.def("DistanceSquared", &DVec3d::DistanceSquared, "vector2"_a, DOC(Bentley, Geom, DVec3d, DistanceSquared));
    c1.def("DistanceSquaredXY", &DVec3d::DistanceSquaredXY, "vector2"_a, DOC(Bentley, Geom, DVec3d, DistanceSquaredXY));
    c1.def("DistanceXY", &DVec3d::DistanceXY, "vector2"_a, DOC(Bentley, Geom, DVec3d, DistanceXY));

    c1.def("CrossProductMagnitude", &DVec3d::CrossProductMagnitude, "other"_a, DOC(Bentley, Geom, DVec3d, CrossProductMagnitude));

    c1.def("CrossProductXY", &DVec3d::CrossProductXY, "vector2"_a, DOC(Bentley, Geom, DVec3d, CrossProductXY));

    c1.def("SetComponent", &DVec3d::SetComponent, "a"_a, "index"_a, DOC(Bentley, Geom, DVec3d, SetComponent));

    c1.def("GetComponent", &DVec3d::GetComponent, "index"_a, DOC(Bentley, Geom, DVec3d, GetComponent));

    c1.def("GetComponents", [] (DVec3dCR self) { return py::make_tuple(self.x, self.y, self.z); });

    c1.def("GetTriad", &DVec3d::GetTriad, "xAxis"_a, "yAxis"_a, "zAxis"_a, DOC(Bentley, Geom, DVec3d, GetTriad));

    c1.def("GetNormalizedTriad", &DVec3d::GetNormalizedTriad, "xAxis"_a, "yAxis"_a, "zAxis"_a, DOC(Bentley, Geom, DVec3d, GetNormalizedTriad));

    c1.def("ProjectToVector", [] (DVec3dCR self, DVec3dCR targetVecgor)
           {
           double fraction = 0;
           bool bOk = self.ProjectToVector(targetVecgor, fraction);
           return py::make_tuple(bOk, fraction);
           }, "targetVector"_a, DOC(Bentley, Geom, DVec3d, ProjectToVector));

    c1.def("ProjectToPlane", &DVec3d::ProjectToPlane, "vectorU"_a, "vectorV"_a, "uv"_a, DOC(Bentley, Geom, DVec3d, ProjectToPlane));

    c1.def("GetPerpendicularParts", [] (DVec3dCR self, DVec3dCR hypotenuse, DVec3dR parallelPart, DVec3dR perpendicularPart)
           {
           double fraction = 0;
           bool bOk = self.GetPerpendicularParts(hypotenuse, fraction, parallelPart, perpendicularPart);
           return py::make_tuple(bOk, fraction);
           }, "hypotenuse"_a, "parallelPart"_a, "perpendicularPart"_a, DOC(Bentley, Geom, DVec3d, GetPerpendicularParts));

    c1.def("AngleTo", &DVec3d::AngleTo, "vector2"_a, DOC(Bentley, Geom, DVec3d, AngleTo));
    c1.def("AngleToXY", &DVec3d::AngleToXY, "vector2"_a, DOC(Bentley, Geom, DVec3d, AngleToXY));

    c1.def("SmallerUnorientedAngleTo", &DVec3d::SmallerUnorientedAngleTo, "vector2"_a, DOC(Bentley, Geom, DVec3d, SmallerUnorientedAngleTo));
    c1.def("SmallerUnorientedAngleToXY", &DVec3d::SmallerUnorientedAngleToXY, "vector2"_a, DOC(Bentley, Geom, DVec3d, SmallerUnorientedAngleToXY));
    c1.def("AngleFromPerpendicular", &DVec3d::AngleFromPerpendicular, "vector2"_a, DOC(Bentley, Geom, DVec3d, AngleFromPerpendicular));

    c1.def("SignedAngleTo", &DVec3d::SignedAngleTo, "vector2"_a, "orientationVector"_a, DOC(Bentley, Geom, DVec3d, SignedAngleTo));
    c1.def("PlanarAngleTo", &DVec3d::PlanarAngleTo, "vector2"_a, "planeNormal"_a, DOC(Bentley, Geom, DVec3d, PlanarAngleTo));

    c1.def("AngleAndAxisOfRotationFromVectorToVector", [] (DVec3dCR self, DVec3dCR target, DVec3dR axis)
           {
           double radians = 0;
           bool bOk = self.AngleAndAxisOfRotationFromVectorToVector(target, axis, radians);
           return py::make_tuple(bOk, radians);
           }, "target"_a, "axis"_a, DOC(Bentley, Geom, DVec3d, AngleAndAxisOfRotationFromVectorToVector));

    c1.def("IsVectorInSmallerSector", &DVec3d::IsVectorInSmallerSector, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DVec3d, IsVectorInSmallerSector));
    c1.def("IsVectorInCCWSector", &DVec3d::IsVectorInCCWSector, "vector0"_a, "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec3d, IsVectorInCCWSector));
    c1.def("IsVectorInCCWXYSector", &DVec3d::IsVectorInCCWXYSector, "vector1"_a, "vector2"_a, DOC(Bentley, Geom, DVec3d, IsVectorInCCWXYSector));
    c1.def("IsParallelTo", &DVec3d::IsParallelTo, "vector2"_a, DOC(Bentley, Geom, DVec3d, IsParallelTo));
    c1.def("IsPositiveParallelTo", &DVec3d::IsPositiveParallelTo, "vector2"_a, DOC(Bentley, Geom, DVec3d, IsPositiveParallelTo));
    c1.def("IsPerpendicularTo", &DVec3d::IsPerpendicularTo, "vector2"_a, DOC(Bentley, Geom, DVec3d, IsPerpendicularTo));
    c1.def("IsEqual", py::overload_cast<DVec3dCR>(&DVec3d::IsEqual, py::const_), "vector2"_a, DOC(Bentley, Geom, DVec3d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DVec3dCR, double> (&DVec3d::IsEqual, py::const_), "vector2"_a, "tolerance"_a, DOC(Bentley, Geom, DVec3d, IsEqual));

    c1.def("AlmostEqual", &DVec3d::AlmostEqual, "dataB"_a, DOC(Bentley, Geom, DVec3d, AlmostEqual));
    c1.def("IsZero", &DVec3d::IsZero, DOC(Bentley, Geom, DVec3d, IsZero));
    c1.def("InitFromXYAngleAndMagnitude", &DVec3d::InitFromXYAngleAndMagnitude, "theta"_a, "magnitude"_a, DOC(Bentley, Geom, DVec3d, InitFromXYAngleAndMagnitude));
    c1.def("InitFromColumn", &DVec3d::InitFromColumn, "matrix"_a, "col"_a);
    c1.def("InitFromRow", &DVec3d::InitFromRow, "matrix"_a, "row"_a);
    }