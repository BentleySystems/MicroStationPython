/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\transform.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/OperatorOverload.h>
#include <Pybind11/numpy.h>


static const char * __doc_Bentley_Geom_Transform_OffsetPointByColumn =R"doc(Adds column i of the matrix part of this instance to point in and
places the result in out.

Parameter ``[out]``:
    out sum of in and column i

Parameter ``[in]``:
    in The base point for sum

Parameter ``[in]``:
    i The column index of matrix)doc";

static const char * __doc_Bentley_Geom_Transform_ScaleDoubleArrayByXColumnMagnitude =R"doc(scale all values in an array of doubles by the magnitude of a
specified column of the matrix.

Parameter ``[in]``:
    data array of doubles.

Parameter ``[in]``:
    n number of values.)doc";

static const char * __doc_Bentley_Geom_Transform_CorrectCoordinateFrameXYRange =R"doc(Input transforms placed " within " caller's geoemtry so that the
geometry range satisfies origin and scaling requirements indicatd by
frame type. Expected usage is that a local coordinate frame is placed
on some geometry and the range of the geometry is them computed within
that local system. The coordinate frame then needs some combination of
(a) move origin to lower left of the range, (b) rescale axes so that
one or both of x,y directions scale to 01.

Parameter ``[in,out]``:
    localToWorld local to world transformation to modify.

Parameter ``[in,out]``:
    worldToLocal world to lcoal transformation to modify.

Parameter ``[in,out]``:
    localRange range of subject data.

Parameter ``[in]``:
    frameType identifies target scaling and origin.

Parameter ``[out]``:
    appliedTransformOldLocalToNewLocal (optional) the transfrom
    applied to modify initial local geometry to final local geometry)doc";

static const char * __doc_Bentley_Geom_Transform_MultiplyTransformTranslation =R"doc(Multiply by a translation " from the left ":result = transformIn *
(Identity, scaled translationIn)

Parameter ``[in]``:
    transformIn full transform for right factor.

Parameter ``[in]``:
    translationIn translation vector for right term

Parameter ``[in]``:
    scaleFactor scale factor for translation)doc";

static const char * __doc_Bentley_Geom_Transform_MultiplyTranslationTransform =R"doc(Multiply by a translation " from the left ":result = (Identity, scaled
translationIn) * transformIn

Parameter ``[in]``:
    translationIn translation vector for left term

Parameter ``[in]``:
    scaleFactor factor for translation

Parameter ``[in]``:
    transformIn full transform for right factor.)doc";

static const char * __doc_Bentley_Geom_Transform_ScaleCompleteRows =R"doc(Scale the complete rows by respective factors. (See also
scaleMatrixColumns, scaleMatrixRows, which only act on the matrix
part)

Parameter ``[in]``:
    transform The input transform.

Parameter ``[in]``:
    xscale The x column scale factor

Parameter ``[in]``:
    yscale The y column scale factor

Parameter ``[in]``:
    zscale The z column scale factor)doc";

static const char * __doc_Bentley_Geom_Transform_ScaleMatrixRows =R"doc(Scale the rows of the matrix part by respective factors. Translation
part is unaffected. (See also scaleMatrixColumns, scaleTransformRows)

Parameter ``[in]``:
    transform The input transform.

Parameter ``[in]``:
    xscale The x column scale factor

Parameter ``[in]``:
    yscale The y column scale factor

Parameter ``[in]``:
    zscale The z column scale factor)doc";

static const char * __doc_Bentley_Geom_Transform_InitForwardAndInverseFromAxesAndOrigin =R"doc(Construct transforms between local and world for given origin and axis
directions.

Parameter ``[out]``:
    localToWorld transform from local system to world.

Parameter ``[out]``:
    worldToLocal transform from world to local system.

Parameter ``[in]``:
    axes coordinate directions of local system (relative to world)

Parameter ``[in]``:
    origin origin of local system (in world)

Returns:
    true if axes were independent)doc";

static const char * __doc_Bentley_Geom_Transform_ScaleMatrixColumns =R"doc(Scale the columns of the matrix part by respective factors.
Translation part is unaffected. (See also scaleMatrixRows,
scaleTransformRows)

Parameter ``[in]``:
    transform The input transform.

Parameter ``[in]``:
    xscale The x column scale factor

Parameter ``[in]``:
    yscale The y column scale factor

Parameter ``[in]``:
    zscale The z column scale factor)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromPrincipleAxisRotations =R"doc(Sets this instance to the transformation obtained by premultiplying
inTransform by 3 matrix rotations about principle axes, given by the
angles xrot, yrot and zrot. inTransform may be the same as this
instance. Symbolically, given transform [M t] and rotation matrices
X,Y,Z, the resulting transform is [X*Y*Z*M X*Y*Z*t]

Parameter ``[in]``:
    inTransform The base transformation

Parameter ``[in]``:
    xrot The x axis rotation, in radians

Parameter ``[in]``:
    yrot The y axis rotation, in radians

Parameter ``[in]``:
    zrot The z axis rotation, in radians)doc";

static const char * __doc_Bentley_Geom_Transform_TranslateInLocalCoordinates =R"doc(Sets this instance to a transformation that has the same matrix part
as transform in and a translation part that is the SUM of the
translation part of in plus the product of the matrix part of in times
the given point. If the translation part of in is interpreted as the
origin of a coordinate system (whose axis directions and sizes are
given by the columns of the matrix part), this instance becomes a
coordinate frame with the same axis directions and sizes, but with the
origin shifted to point x,y,z of the in system. That is, x,y,z are the
local coordinates of the new origin, and the translation part of this
instance becomes the global coordinates of the new origin. in may be
identical to this instance. Symbolically, if in is the transform [R t]
and the local origin coordinates x,y,z are in column vector p, the
result is the transformation [R t+R*p].

Parameter ``[in]``:
    in The input transformation

Parameter ``[in]``:
    x The x-coordinate of the local origin

Parameter ``[in]``:
    y The y-coordinate of the local origin

Parameter ``[in]``:
    z The z-coordinate of the local origin)doc";

static const char * __doc_Bentley_Geom_Transform_GetFixedPlane =R"doc( Compute the plane (if any) of points that are not
affected by this transformation. Returns false if the fixed point set
for the transform is empty, a single point, a line, or all points.

Parameter ``[out]``:
    fixedPoint A point on the line.

Parameter ``[out]``:
    planeVectorX a unit vector in the plane.

Parameter ``[out]``:
    planeVectorY another unit vector in the plane, perpendicular to
    pDirectionVectorX.

Returns:
    true if the transformation has a fixed point.)doc";

static const char * __doc_Bentley_Geom_Transform_GetFixedLine =R"doc( Compute the line (if any) of points that are not affected
by this transformation. Returns false if the fixed point set for the
transform is empty, a single point, a plane, or all points.

Parameter ``[out]``:
    fixedPoint A point on the line.

Parameter ``[out]``:
    directionVector vector along the line.

Returns:
    true if the transformation has a fixed point.)doc";

static const char * __doc_Bentley_Geom_Transform_GetAnyFixedPoint =R"doc( Compute any single point that remains unchanged by action
of a transform. Note that a pure translation has no fixed points,
while any other transformation does.

Parameter ``[out]``:
    fixedPoint Point that is not changed by the transformation.

Returns:
    true if the transformation has a fixed point.)doc";

static const char * __doc_Bentley_Geom_Transform_IsUniformScaleAndRotateAroundLine =R"doc( Returns true if the transform is a uniform scale combined
with a rotation. One, but not both, of the two steps may be null (unit
scale or no rotation)

Parameter ``[out]``:
    fixedPoint fixed point of scaling. This is also a point on the
    line.

Parameter ``[out]``:
    directionVector vector in the direction of the rotation.

Parameter ``[out]``:
    radians rotation angle

Parameter ``[out]``:
    scale scale factor.

Returns:
    true if the transformation has at least one of the scale, rotate
    effects.)doc";

static const char * __doc_Bentley_Geom_Transform_IsMirrorAboutPlane =R"doc( Returns true if the transform is a mirror with respect to
a plane.

Parameter ``[out]``:
    planePoint Some point on the plane.

Parameter ``[out]``:
    unitNormal unit vector perpendicular to the plane.

Returns:
    true if the transformation is a mirror.)doc";

static const char * __doc_Bentley_Geom_Transform_IsRotateAroundLine =R"doc( Returns true if the transform is a non-zero rotation
around a line.

Parameter ``[out]``:
    fixedPoint a point on the line.

Parameter ``[out]``:
    directionVector vector in the line direction.

Parameter ``[out]``:
    radians rotation angle in radians.

Returns:
    true if the transformation is a non-zero rotation.)doc";

static const char * __doc_Bentley_Geom_Transform_IsUniformScale =R"doc( Returns true if the transform is a uniform scale with
scale factor other than 1.0.

Parameter ``[out]``:
    fixedPoint (If function result is true) the (one) point which
    remains in place in the transformation.

Parameter ``[out]``:
    scale The scale factor. If the transform is not a scale, this is
    returned as 1.0.

Returns:
    true if the transformation is a uniform scale.)doc";

static const char * __doc_Bentley_Geom_Transform_IsTranslate =R"doc( Returns true if the transform is a simple translation.

Parameter ``[out]``:
    translation the translation vector. Zero of not a translation
    transform.

Returns:
    true if the transformation is a pure translation.)doc";

static const char * __doc_Bentley_Geom_Transform_IsPlanar =R"doc( Returns true if transformation effects are entirely
within the plane with given normal.

Parameter ``[in]``:
    normal The plane normal

Returns:
    true if the transform has no effects perpendicular to planes with
    the given normal.)doc";

static const char * __doc_Bentley_Geom_Transform_IsNearRigidScale =R"doc(Clean up a transform that is close to a pure rotate and scale. If
source is NOT near to a rigid scale, return false and copy to the
dest. If near an identity return identity. If nearly perpendicular
with scales other than 1, clean preserving the length and direction of
the primary axis. This is intended to be used with a crude (e.g.
1.0e-6) reltol to identify old DGN file matrices that are " dirty " by
modern standards but were meant to be identity, rotation, or scaled
rotations in the UOR era.

Parameter ``[in]``:
    dest result

Parameter ``[in]``:
    primaryAxis axis whose orientation and direction is preserved.

Parameter ``[in]``:
    tolerance relative tolerance for recognizing near-perpendicular
    conditions.)doc";

static const char * __doc_Bentley_Geom_Transform_IsRigidScale =R"doc( Returns true if the matrix part of a transform is a rigid
body rotation, i.e. its transpose is its inverse and it has a positive
determinant.

Parameter ``[out]``:
    scale scale factor.

Returns:
    true if the transformation is rigid (no scale or shear in the
    matrix part))doc";

static const char * __doc_Bentley_Geom_Transform_IsRigid =R"doc( Returns true if the matrix part of a transform is a rigid
body rotation, i.e. its transpose is its inverse and it has a positive
determinant.

Returns:
    true if the transformation is rigid (no scale or shear in the
    matrix part))doc";

static const char * __doc_Bentley_Geom_Transform_IsIdentity =R"doc( Returns true if the transform is the identity transform.

Returns:
    true if the transformation is within tolerance of the identity.)doc";

static const char * __doc_Bentley_Geom_Transform_TransformImplicitPlane =R"doc(Transform the a,b,c,d components for an implicit plane. The plane
equation format is ax+by+cz=d.

Parameter ``[out]``:
    aOut x coefficient in transformed plane equation

Parameter ``[out]``:
    bOut y coefficient in transformed plane equation

Parameter ``[out]``:
    cOut z coefficient in transformed plane equation

Parameter ``[out]``:
    dOut constant coefficient for equation.

Parameter ``[in]``:
    a The x coefficient in plane equation

Parameter ``[in]``:
    b The y coefficient in plane equation

Parameter ``[in]``:
    c The z coefficient in plane equation

Parameter ``[in]``:
    d The constant on right hand side of plane equation)doc";

static const char * __doc_Bentley_Geom_Transform_SolveArray =R"doc(Solves the linear systems TX=B, where T is this instance, B is the
matrix of numPoints input points and X is the matrix of numPoints
output points. No simplifying assumptions are made regarding the
matrix part of T. Symbolically, if T = [M t], then for each
input/output point i, X[i] = Q (B[i] - t), where Q is the inverse of M
(i.e., the i_th system is equivalent to MX[i] = B[i] - t). inPoint and
outPoint may have identical addresses.

Parameter ``[out]``:
    outPoint column points of solution matrix to system

Parameter ``[in]``:
    inPoint The column points of constant matrix of system

Parameter ``[in]``:
    numPoints The number of input/output points

Returns:
    false if the matrix part of this instance is singular.)doc";

static const char * __doc_Bentley_Geom_Transform_Solve =R"doc(Solves the linear system Tx=b, where T is this instance, b is the
input point and x is the output point. No simplifying assumptions are
made regarding the matrix part of T. Symbolically, if T = [M t], then
x = Q (b - t), where Q is the inverse of M (i.e., the system is
equivalent to Mx = b - t). inPoint and outPoint may have identical
addresses.

Parameter ``[out]``:
    outPoint solution to system

Parameter ``[in]``:
    inPoint The constant point of the system

Returns:
    false if the matrix part of this instance is singular.)doc";

static const char * __doc_Bentley_Geom_Transform_MultiplyWeighted =R"doc(Multiplies a " weighted point " in place. That is, the point is input
and output as (wx,wy,wz,w) where x,y,z are the cartesian image
coordinates.

Parameter ``[in,out]``:
    point point to be updated

Parameter ``[in]``:
    weight The weight)doc";

static const char * __doc_Bentley_Geom_Transform_MultiplyTransposeMatrixOnly =R"doc(Multiplies the row vector constructed from components x,y,z times the
matrix part of this instance. Symbolically, given transform [R t] and
row vector p, the returned point is p*R.

Parameter ``[out]``:
    point result of point * matrix operation

Parameter ``[in]``:
    x The x component of the point

Parameter ``[in]``:
    y The y component of the point

Parameter ``[in]``:
    z The z component of the point)doc";

static const char * __doc_Bentley_Geom_Transform_MultiplyMatrixOnly =R"doc(Multiplies the matrix part of this instance times the column vector
constructed from components x,y,z. Symbolically, given transform [R t]
and column vector p, the returned point is R*p.

Parameter ``[out]``:
    point result of matrix * point operation

Parameter ``[in]``:
    x The x component of the point

Parameter ``[in]``:
    y The y component of the point

Parameter ``[in]``:
    z The z component of the point)doc";

static const char * __doc_Bentley_Geom_Transform_MultiplyTranspose =R"doc(Multiplies this instance times each column vector in inPoint, using
the transpose of the matrix part of this instance in the
multiplications, and places the resulting points in outPoint.
Symbolically, given transform [R t], each returned point has the
equivalent form p*R + t, where p is a row vector. inPoint and outPoint
may be the same.

Parameter ``[out]``:
    outPoint transformed points

Parameter ``[in]``:
    inPoint The input points

Parameter ``[in]``:
    numPoint The number of points)doc";

static const char * __doc_Bentley_Geom_Transform_Multiply =R"doc( Multiplies a point by a transform, returning the result
in place of the input point.

Parameter ``[in,out]``:
    point point to be updated)doc";

static const char * __doc_Bentley_Geom_Transform_ColumnXMagnitude =R"doc(Return magnitude of X column. This is commonly considered as the scale
factor of the transform.)doc";

static const char * __doc_Bentley_Geom_Transform_Determinant =R"doc(Return the determinant of the matrix part.)doc";

static const char * __doc_Bentley_Geom_Transform_MaxDiff =R"doc( Returns the largest absolute value difference between
corresponding coefficients

Parameter ``[in]``:
    otherTransform

Returns:
    largest absolute difference between the two transforms)doc";

static const char * __doc_Bentley_Geom_Transform_IsEqual =R"doc( Returns true if two transforms have exact (bitwise)
equality.

Parameter ``[in]``:
    transform2 The second transform

Returns:
    true if the transforms are identical)doc";

static const char * __doc_Bentley_Geom_Transform_MatrixColumnMagnitude =R"doc(return the magnitude of a column of the matrix.

Parameter ``[in]``:
    i column index. Adjusted cyclically if outside 012)doc";

static const char * __doc_Bentley_Geom_Transform_GetMatrixRow =R"doc( Returns a row from the matrix part of the transformation.

Parameter ``[out]``:
    row row of matrix part.

Parameter ``[in]``:
    index column index)doc";

static const char * __doc_Bentley_Geom_Transform_SetMatrixRow =R"doc( Set a column of the matrix part.

Parameter ``[out]``:
    row row data

Parameter ``[in]``:
    index column index)doc";

static const char * __doc_Bentley_Geom_Transform_SetMatrixColumn =R"doc( Set a column of the matrix part.

Parameter ``[out]``:
    column column data

Parameter ``[in]``:
    index column index)doc";

static const char * __doc_Bentley_Geom_Transform_GetMatrixColumn =R"doc( Returns a column from the matrix part of the
transformation.

Parameter ``[out]``:
    column column of matrix part.

Parameter ``[in]``:
    index column index)doc";

static const char * __doc_Bentley_Geom_Transform_SetFixedPoint =R"doc(Sets the translation part of this instance so that it leaves point
point unchanged, i.e. so that this instance may be interpreted as
applying its matrix part as a rotation or scaling about point.
Symbolically, given transform [R t] and column vector p, the returned
transform is [R p-R*p]. (The prior translation part is destroyed, and
does not affect the result in any way.)

Parameter ``[in]``:
    point The point that is to remain fixed when multiplied by the
    modified transformation)doc";

static const char * __doc_Bentley_Geom_Transform_ZeroTranslation =R"doc(Sets the translation part of this instance to zero. The prior
translation part is overwritten, and the matrix part is unchanged.
Symbolically, this instance [R t] becomes the transformation [R 0].)doc";

static const char * __doc_Bentley_Geom_Transform_SetTranslation =R"doc(Sets the translation part of this instance to point. The prior
translation part is overwritten, and the matrix part is unchanged.
Symbolically, if point is u then this instance [R t] becomes the
transformation [R u].

Parameter ``[in]``:
    point The vector to insert)doc";

static const char * __doc_Bentley_Geom_Transform_GetTranslation =R"doc( Returns the translation (point) part of a transformation.

Parameter ``[out]``:
    point vector part of transformation)doc";

static const char * __doc_Bentley_Geom_Transform_Translation =R"doc(Return the translation (aka origin) part as a DVec3d.)doc";

static const char * __doc_Bentley_Geom_Transform_Origin =R"doc(Return the origin (aka translation) part as a DPoint3d.)doc";

static const char * __doc_Bentley_Geom_Transform_SetMatrix =R"doc( Overwrites the matrix part of a preexisting
transformation. The translation part is unchanged.

Parameter ``[in]``:
    matrix The matrix to insert)doc";

static const char * __doc_Bentley_Geom_Transform_Matrix =R"doc(Return the matrix part)doc";

static const char * __doc_Bentley_Geom_Transform_Get4Points =R"doc(Sets point0 to the origin (translation part), and sets point1, point2
point3 to the x, y and z points (translations of columns of matrix
part by origin) from this instance.

Parameter ``[out]``:
    point0 origin of transform coordinates

Parameter ``[out]``:
    point1 100 point of transform coordinates

Parameter ``[out]``:
    point2 010 point of transform coordinates

Parameter ``[out]``:
    point3 001 point of transform coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_GetOriginAndVectors =R"doc(Sets origin to the translation part, and sets vector0, vector1 vector2
to the columns of this instance.

Parameter ``[out]``:
    origin origin of transform coordinates

Parameter ``[out]``:
    vector0 100 vector of transform coordinates

Parameter ``[out]``:
    vector1 010 vector of transform coordinates

Parameter ``[out]``:
    vector2 001 vector of transform coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_GetPointComponent =R"doc( Returns a value from a specified component of the point
(translation) part of the transformation.

Parameter ``[in]``:
    row The index of point component to read. Indices are 0, 1, 2 for
    x, y, z)doc";

static const char * __doc_Bentley_Geom_Transform_GetFromMatrixByRowAndColumn =R"doc( Returns a value from a specified row and column of the
matrix part of the transformation.

Parameter ``[in]``:
    row The index of row to read. Row indices are 0, 1, 2.

Parameter ``[in]``:
    col The index of column to read. Column indices are 0, 1, 2.)doc";

static const char * __doc_Bentley_Geom_Transform_InitProduct =R"doc( Returns the product of two transformations. Symbolically,
given transforms [R t] and [S u], return the product transform [R t][S
u] = [R*S t+R*u].

Parameter ``[in]``:
    transform1 The first factor

Parameter ``[in]``:
    transform2 The second factor)doc";

static const char * __doc_Bentley_Geom_Transform_FromProduct =R"doc( Returns the product of two transforms.)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromProjectionToPlane =R"doc(Initialize a transform that projects to a plane.

Parameter ``[in]``:
    origin any point on the target plane.

Parameter ``[in]``:
    normal vector perpendicular to target plane)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromScalePerpendicularToPlane =R"doc(Initialize a transform that scales around a plane

Parameter ``[in]``:
    origin any point on the target plane

Parameter ``[in]``:
    normal vector perpendicular to target plane.

Parameter ``[in]``:
    scale scale factor. (e.g. 0.0 to project onto the plane, -1 to
    mirror))doc";

static const char * __doc_Bentley_Geom_Transform_InitFromMirrorPlane =R"doc(Initialize a transform that mirrors about a plane.

Parameter ``[in]``:
    origin any point on the mirror plane.

Parameter ``[in]``:
    normal vector perpendicular to mirror plane)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromLineAndRotationAngle =R"doc( Returns a transformation of rotation about a specified
line.

Parameter ``[in]``:
    point0 The start point of the line

Parameter ``[in]``:
    point1 The end point of the line

Parameter ``[in]``:
    radians The rotation angle)doc";

static const char * __doc_Bentley_Geom_Transform_From2Points =R"doc( Returns a transformation in the xy-plane with origin
origin, axis axisId towards xPoint, and the other axis perpendicular.
If normalize is false, both axes have length equal to the distance
between origin and xPoint.

Parameter ``[in]``:
    origin

Parameter ``[in]``:
    xPoint The target point of axis axisId of coordinate system

Parameter ``[in]``:
    axisId The axis (x=0, y=1) that points from origin to xPoint

Parameter ``[in]``:
    normalize true to have coordinate system normalized)doc";

static const char * __doc_Bentley_Geom_Transform_FromPlaneNormalToLine =R"doc( Returns a (possibly skewed) transformation with origin
origin, the axis axisId towards xPoint, and other axes perpendicular.
If normalize is false, all axes have length equal to the distance
between the two origin and xPoint. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The target point of axis axisId of coordinate system

Parameter ``[in]``:
    axisId The axis that points from origin to xPoint

Parameter ``[in]``:
    normalize true to have coordinate system normalized)doc";

static const char * __doc_Bentley_Geom_Transform_FromFixedPointAndScaleFactors =R"doc( Returns a transformation with x,y,z scales around a fixed
point.

Parameter ``[in]``:
    origin The fixed point.

Parameter ``[in]``:
    xScale x direction scale factor.

Parameter ``[in]``:
    yScale y direction scale factor.

Parameter ``[in]``:
    zScale z direction scale factor.)doc";

static const char * __doc_Bentley_Geom_Transform_FromPlaneOf3PointsZeroZ =R"doc( Returns a transformation with origin at origin, x-axis
from origin to xPoint, y-axis from origin to yPoint, and z-axis all
zeros. All axes are unnormalized. There is no effort to detect zero
length axes or degenerate points that define only a line or plane but
not a full plane.

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The 100 point of coordinate system

Parameter ``[in]``:
    yPoint The 010 point of coordinate system)doc";

static const char * __doc_Bentley_Geom_Transform_FromPlaneOf3Points =R"doc( Returns a transformation with origin at origin, x-axis
from origin to xPoint, y-axis from origin to yPoint, and z-axis equal
to the cross product of x and y axes. All axes are unnormalized. There
is no effort to detect zero length axes or degenerate points that
define only a line or plane but not a full coordinate system.

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The 100 point of coordinate system

Parameter ``[in]``:
    yPoint The 010 point of coordinate system)doc";

static const char * __doc_Bentley_Geom_Transform_From4Points =R"doc( Returns a transformation with origin at origin, x-axis
from origin to xPoint, y-axis from origin to yPoint, and z-axis from
origin to zPoint. All axes are unnormalized. There is no effort to
detect zero length axes or degenerate points that define only a line
or plane but not a full coordinate system. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of transformed coordinates

Parameter ``[in]``:
    xPoint The 100 point of transformed coordinates

Parameter ``[in]``:
    yPoint The 010 point of transformed coordinates

Parameter ``[in]``:
    zPoint The 001 point of transformed coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_FromOriginAndVectors =R"doc( Returns a transformation with origin at origin, x-axis
xVector, y-axis yVector, and z-axis zVector. All axes are
unnormalized. There is no effort to detect zero length axes or
degenerate points that define only a line or plane but not a full
coordinate system. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of transformed coordinates

Parameter ``[in]``:
    xVector The 100 point of transformed coordinates

Parameter ``[in]``:
    yVector The 010 point of transformed coordinates

Parameter ``[in]``:
    zVector The 001 point of transformed coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_FromPrincipleAxisRotations =R"doc(Sets this instance to the transformation obtained by premultiplying
inTransform by 3 matrix rotations about principle axes, given by the
angles xrot, yrot and zrot. inTransform may be the same as this
instance. Symbolically, given transform M and rotation matrices X,Y,Z,
the resulting transform is X*Y*Z*M

Parameter ``[in]``:
    inTransform The base transformation

Parameter ``[in]``:
    xrot The x axis rotation, in radians

Parameter ``[in]``:
    yrot The y axis rotation, in radians

Parameter ``[in]``:
    zrot The z axis rotation, in radians)doc";

static const char * __doc_Bentley_Geom_Transform_FromAxisAndRotationAngle =R"doc( Returns a transformation of rotation about a specified
ray, and also its derivative with respect to the angle.

Parameter ``[in]``:
    axis axis of rotation

Parameter ``[in]``:
    radians The rotation angle

Parameter ``derivativeTransform``:
    transform mapping rotated point (anywhere) to direction vector at
    its destination.)doc";

static const char * __doc_Bentley_Geom_Transform_FromLineAndRotationAngle =R"doc( Returns a transformation of rotation about a specified
line.

Parameter ``[in]``:
    point0 The start point of the line

Parameter ``[in]``:
    point1 The end point of the line

Parameter ``[in]``:
    radians The rotation angle)doc";

static const char * __doc_Bentley_Geom_Transform_TryRangeMapping =R"doc( Returns a transformation that maps corners of the source
range to corners of the destination range.

Returns:
    false if either range is null or any direction of the sourceRange
    has zero length.)doc";

static const char * __doc_Bentley_Geom_Transform_InvertRigidBodyTransformation =R"doc(Sets this instance to a matrix which is the inverse of in IN THE
SPECIAL CASE WHERE in HAS ONLY PURE ROTATION OR MIRRORING IN ITS
ROTATIONAL PART. These special conditions allow the 'inversion' to be
done by only a transposition and one matrix-times-point
multiplication, rather than the full effort of inverting a general
transformation. It is the caller's responsibility to be sure that
these special conditions hold. This usually occurs when the caller has
just constructed the transform by a sequence of translations and
rotations. If the caller has received the matrix from nonverified
external sources and therefore does not know if the special conditions
apply, the <CODE>inverseOf</CODE> method should be used instead. in
may be the same as this instance. The specific computations in this
special-case inversion are (1) the output transform's translation is
the input transform's matrix times the negative of the input
transform's translation, and (2) the output transform's matrix part is
the tranpose of the input transform's matrix part. Symbolically, given
transform [R t] return transform [R^ (R^)*(-t)] where ^ indicates
transposition.

Parameter ``[in]``:
    in The input transformation (TransformCR))doc";

static const char * __doc_Bentley_Geom_Transform_ValidatedInverse =R"doc(Return the inverse of the instance transform. This is a modestly
expensive floating point computation (33 multiplies, 14 adds).
Symbolically, given transform [R t] return transform [Q Q*(-t)] where
Q is the inverse of matrix R.

Returns:)doc";

static const char * __doc_Bentley_Geom_Transform_InverseOf =R"doc(Sets this instance to the inverse transform of in. in may be the same
as this instance. This is a modestly expensive floating point
computation (33 multiplies, 14 adds). Symbolically, given transform [R
t] return transform [Q Q*(-t)] where Q is the inverse of matrix R.

Parameter ``[in]``:
    in The input transformation

Remark:
    This is deprecated. Preferred call is{resutl =
    in.ValidatedInverse ();}

Returns:
    true if transform is invertible)doc";

static const char * __doc_Bentley_Geom_Transform_InitUniformScaleApproximation =R"doc( Construct a transform which preserves both a primary
column directon and a secondary column plane. Scale all columns to
length of primary axis.

Parameter ``[in]``:
    transform original matrix.

Parameter ``[in]``:
    primaryAxis axis to be retained.

Parameter ``[in]``:
    secondaryAxis axis defining plane to be maintained.)doc";

static const char * __doc_Bentley_Geom_Transform_InitFrom2Points =R"doc( Returns a transformation in the xy-plane with origin
origin, axis axisId towards xPoint, and the other axis perpendicular.
If normalize is false, both axes have length equal to the distance
between origin and xPoint. //! //!

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The target point of axis axisId of coordinate system

Parameter ``[in]``:
    axisId The axis (x=0, y=1) that points from origin to xPoint

Parameter ``[in]``:
    normalize true to have coordinate system normalized)doc";

static const char * __doc_Bentley_Geom_Transform_InitNormalizedFrameFromOriginXPointYPoint =R"doc( Attempt to set up a coordinate frame origin at origin,
x-axis from origin to xPoint, y-axis in plane with yPoint, All axes
are normalized. Return false with identity at origin if unable to do
cross products.

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The 100 point of coordinate system

Parameter ``[in]``:
    yPoint The 010 point of coordinate system)doc";

static const char * __doc_Bentley_Geom_Transform_InitFrom3Points =R"doc(Sets this instance to a transformation in the xy-plane with origin at
origin, x-axis from origin to xPoint and y-axis from origin to yPoint.
All axes are unnormalized. There is no effort to detect zero length
axes or degenerate points that define a line but not a full coordinate
system. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of transformed coordinates

Parameter ``[in]``:
    xPoint The 10 point of transformed coordinates

Parameter ``[in]``:
    yPoint The 01 point of transformed coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_FromOriginAndXVector =R"doc(Returns a transform with given origin and xVector. The yVector is a
CCW perpendicular to the xVector (with the same length) The zVecotor
is a unitZ.)doc";

static const char * __doc_Bentley_Geom_Transform_FromOriginAndBearingXY =R"doc( Returns a transformation with ul> li>translation xyz are
the origin li>xAxis in direction of bearing radians (parallel to xy
plane) li>yAxis perpenedicular to xAxis and also parallel to the xy
plane. li>zAxis is global (0,0,1) ul>)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromOriginAngleAndLengths =R"doc( Returns a transformation in the xy-plane with origin
origin and x,y-axes of the given lengths rotated counter-clockwise
from standard position by the given angle. The z-coordinate of the
origin is zero and the z-axis is unscaled.

Parameter ``[in]``:
    origin origin of coordinate system

Parameter ``[in]``:
    xAxisAngleRadians The ccw angle separating x-axis from its
    standard position

Parameter ``[in]``:
    xAxisLength The length of x-axis

Parameter ``[in]``:
    yAxisLength The length of y-axis)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromOriginAndLengths =R"doc( Returns a transformation in the xy-plane with origin
origin and x,y-axes of given lengths. The z-coordinate of the origin
is zero and the z-axis is unscaled.

Parameter ``[in]``:
    origin origin of coordinate system

Parameter ``[in]``:
    xAxisLength The length of x-axis

Parameter ``[in]``:
    yAxisLength The length of y-axis)doc";

static const char * __doc_Bentley_Geom_Transform_Copy =R"doc( Returns a copy of a transformation.

Parameter ``[in]``:
    source The source transform)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromPlaneNormalToLine =R"doc( Returns a (possibly skewed) transformation with origin
origin, the axis axisId towards xPoint, and other axes perpendicular.
If normalize is false, all axes have length equal to the distance
between the two origin and xPoint. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The target point of axis axisId of coordinate system

Parameter ``[in]``:
    axisId The axis that points from origin to xPoint

Parameter ``[in]``:
    normalize true to have coordinate system normalized)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromPlaneOf3Points =R"doc( Returns a transformation with origin at origin, x-axis
from origin to xPoint, y-axis from origin to yPoint, and z-axis equal
to the cross product of x and y axes. All axes are unnormalized. There
is no effort to detect zero length axes or degenerate points that
define only a line or plane but not a full coordinate system.

Parameter ``[in]``:
    origin The origin of coordinate system

Parameter ``[in]``:
    xPoint The 100 point of coordinate system

Parameter ``[in]``:
    yPoint The 010 point of coordinate system)doc";

static const char * __doc_Bentley_Geom_Transform_InitFrom4Points =R"doc( Returns a transformation with origin at origin, x-axis
from origin to xPoint, y-axis from origin to yPoint, and z-axis from
origin to zPoint. All axes are unnormalized. There is no effort to
detect zero length axes or degenerate points that define only a line
or plane but not a full coordinate system. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of transformed coordinates

Parameter ``[in]``:
    xPoint The 100 point of transformed coordinates

Parameter ``[in]``:
    yPoint The 010 point of transformed coordinates

Parameter ``[in]``:
    zPoint The 001 point of transformed coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromOriginXVectorYVectorSquareAndNormalize =R"doc( Returns a transformation with origin, x axis direction,
and xy plane All axes are normalized and perpendicular.

Parameter ``[in]``:
    origin The origin of transformed coordinates

Parameter ``[in]``:
    xVector direction for x axis

Parameter ``[in]``:
    yVector " In plane " direction for y axis. <returns>true if
    SquareAndOrthogonalizeColumns succeeds</returns>)doc";

static const char * __doc_Bentley_Geom_Transform_IsTranslateScaleRotateAroundZ =R"doc(Return true if the transform a combination of only 2 thing:(1) move
origin, (2) rotate around Z

Parameter ``[out]``:
    origin origin of frame.

Parameter ``[out]``:
    rigidAxes unit-length axes.

Parameter ``[out]``:
    scale scale factor on the original axes.

Parameter ``[out]``:
    radians positive rotation around Z)doc";

static const char * __doc_Bentley_Geom_Transform_InitFromOriginAndVectors =R"doc( Returns a transformation with origin at origin, x-axis
xVector, y-axis yVector, and z-axis zVector. All axes are
unnormalized. There is no effort to detect zero length axes or
degenerate points that define only a line or plane but not a full
coordinate system. The axes may be skewed.

Parameter ``[in]``:
    origin The origin of transformed coordinates

Parameter ``[in]``:
    xVector The 100 vector of transformed coordinates

Parameter ``[in]``:
    yVector The 010 vector of transformed coordinates

Parameter ``[in]``:
    zVector The 001 vector of transformed coordinates)doc";

static const char * __doc_Bentley_Geom_Transform_FromRowValues =R"doc( Returns a transformation copying the double values
directly into the rows of this instance.

Parameter ``[in]``:
    x00 The (0,0) entry of the matrix (row, column)

Parameter ``[in]``:
    x01 The (0,1) entry

Parameter ``[in]``:
    x02 The (0,2) entry

Parameter ``[in]``:
    tx The x-coordinate of the translation part

Parameter ``[in]``:
    x10 The (1,0) entry

Parameter ``[in]``:
    x11 The (1,1) entry

Parameter ``[in]``:
    x12 The (1,2) entry

Parameter ``[in]``:
    ty The y-coordinate of the translation part

Parameter ``[in]``:
    x20 The (2,0) entry

Parameter ``[in]``:
    x21 The (2,1) entry

Parameter ``[in]``:
    x22 The (2,2) entry

Parameter ``[in]``:
    tz The z-coordinate of the translation part)doc";

static const char * __doc_Bentley_Geom_Transform_FromMatrixAndFixedPoint =R"doc( Returns a transformation with given matrix part, and
translation part computed from the matrix and a given fixed point.
This translation part is generally different from the fixed point
itself. The resulting transformation will leave the fixed point
unchanged and apply whatever effects are contained in the matrix as if
the fixed point is the origin.

Parameter ``[in]``:
    matrix The matrix part

Parameter ``[in]``:
    origin The point that is to remain fixed when multiplied by the
    transformation.)doc";

static const char * __doc_Bentley_Geom_Transform_InitFrom =R"doc( Returns a transformation with the given matrix part and a
zero translation part.

Parameter ``[in]``:
    matrix The matrix part)doc";

static const char * __doc_Bentley_Geom_Transform_InitIdentity =R"doc( returns an identity transformation, i.e. zero translation
part and identity matrix part.)doc";

static const char * __doc_Bentley_Geom_Transform_From =R"doc( Returns a transformation with the given matrix part and a
zero translation part.

Parameter ``[in]``:
    matrix The matrix part)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Transform(py::module_& m)
    {
    //===================================================================================
    // struct Transform
    py::class_<Transform> c1(m, "Transform");
    bind_ValidatedValue<Transform>(m, "ValidatedTransform", py::module_local(false));
    py::bind_vector< bvector<Transform> >(m, "TransformArray", py::module_local(false));

    c1.def(py::init(&Transform::FromIdentity));
    
    c1.def_static("From", py::overload_cast<RotMatrixCR>(&Transform::From), "matrix"_a, DOC(Bentley, Geom, Transform, From));
    c1.def_static("From", py::overload_cast<RotMatrixCR, DPoint3dCR>(&Transform::From), "matrix"_a, "translation"_a, DOC(Bentley, Geom, Transform, From));
    c1.def_static("From", py::overload_cast<DPoint3dCR>(&Transform::From), "translation"_a, DOC(Bentley, Geom, Transform, From));
    c1.def_static("From", py::overload_cast<double, double, double>(&Transform::From), "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, Transform, From));        
    
    c1.def("InitIdentity", &Transform::InitIdentity, DOC(Bentley, Geom, Transform, InitIdentity));
    c1.def("InitFrom", py::overload_cast<RotMatrixCR>(&Transform::InitFrom), "matrix"_a, DOC(Bentley, Geom, Transform, InitFrom));
    c1.def("InitFrom", py::overload_cast<RotMatrixCR, DPoint3dCR>(&Transform::InitFrom), "matrix"_a, "translation"_a, DOC(Bentley, Geom, Transform, InitFrom));
    c1.def("InitFrom", py::overload_cast<DPoint3dCR>(&Transform::InitFrom), "translation"_a, DOC(Bentley, Geom, Transform, InitFrom));
    c1.def("InitFrom", [] (Transform& self, DVec3dCR translation) { self.InitFrom(translation); });
    c1.def("InitFrom", py::overload_cast<double, double, double>(&Transform::InitFrom), "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, Transform, InitFrom));

    c1.def(py::self * DVec3d());
    c1.def(py::self * DPoint3d());
    c1.def(py::self * py::self);
    c1.def(py::self * RotMatrix());

    c1.def_property("form3d",
        [](Transform& self) {return py::array_t<T_Adouble>{ {3, 4}, self.form3d[0], py::cast(self)}; },
        [](RotMatrix& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (9 != arr.size())
            return;

        memcpy(self.form3d[0], ptr, 12 * sizeof(T_Adouble));
        });

    c1.def("InitFrom", &Transform::InitFromRowValues,
           "x00"_a, "x01"_a, "x02"_a, "tx"_a,
           "x10"_a, "x11"_a, "x12"_a, "ty"_a,
           "x20"_a, "x21"_a, "x22"_a, "tz"_a, DOC(Bentley, Geom, Transform, InitFrom));

    c1.def_static("FromMatrixAndFixedPoint", &Transform::FromMatrixAndFixedPoint, "matrix"_a, "origin"_a, DOC(Bentley, Geom, Transform, FromMatrixAndFixedPoint));
    c1.def_static("FromRowValues", &Transform::FromRowValues,
                  "x00"_a, "x01"_a, "x02"_a, "tx"_a,
                  "x10"_a, "x11"_a, "x12"_a, "ty"_a,
                  "x20"_a, "x21"_a, "x22"_a, "tz"_a, DOC(Bentley, Geom, Transform, FromRowValues));
    
    c1.def("InitFromOriginAndVectors", 
           py::overload_cast<DPoint3dCR, DVec3dCR, DVec3dCR, DVec3dCR>(&Transform::InitFromOriginAndVectors),
           "origin"_a, "xVector"_a, "yVector"_a, "zVector"_a, DOC(Bentley, Geom, Transform, InitFromOriginAndVectors));

    c1.def("IsTranslateScaleRotateAroundZ", [] (TransformCR self, DPoint3dR origin, RotMatrixR rigidAxes)
        {
        double scale = 0;
        double radians = 0;
        bool bOk = self.IsTranslateScaleRotateAroundZ(origin, rigidAxes, scale, radians);
        return py::make_tuple(bOk, scale, radians);
        }, "origin"_a, "rigidAxes"_a, DOC(Bentley, Geom, Transform, IsTranslateScaleRotateAroundZ));
        
    c1.def("InitFromOriginXVectorYVectorSquareAndNormalize", &Transform::InitFromOriginXVectorYVectorSquareAndNormalize, "origin"_a, "xVector"_a, "yVector"_a, DOC(Bentley, Geom, Transform, InitFromOriginXVectorYVectorSquareAndNormalize));
    c1.def("InitFrom4Points", &Transform::InitFrom4Points, "origin"_a, "xPoint"_a, "yPoint"_a, "zPoint"_a, DOC(Bentley, Geom, Transform, InitFrom4Points));
    c1.def("InitFromPlaneOf3Points", &Transform::InitFromPlaneOf3Points, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, Transform, InitFromPlaneOf3Points));
    c1.def("InitFromPlaneNormalToLine", &Transform::InitFromPlaneNormalToLine, "origin"_a, "xPoint"_a, "axisId"_a, "normalize"_a, DOC(Bentley, Geom, Transform, InitFromPlaneNormalToLine));
    c1.def("InitFrom", py::overload_cast<DMap4dCR, int>(&Transform::InitFrom), "hMap"_a, "inverse"_a, DOC(Bentley, Geom, Transform, InitFrom));
        
    c1.def("Copy", &Transform::Copy, "source"_a, DOC(Bentley, Geom, Transform, Copy));

    c1.def("InitFromOriginAndLengths", &Transform::InitFromOriginAndLengths, "origin"_a, "xAxisLength"_a, "yAxisLength"_a, DOC(Bentley, Geom, Transform, InitFromOriginAndLengths));
    c1.def("InitFromOriginAngleAndLengths", &Transform::InitFromOriginAngleAndLengths, "origin"_a, "xAxisAngleRadians"_a, "xAxisLength"_a, "yAxisLength"_a, DOC(Bentley, Geom, Transform, InitFromOriginAngleAndLengths));
    c1.def("InitFromOriginAndVectors", py::overload_cast<DPoint2dCR, DVec2dR, DVec2dR>(&Transform::InitFromOriginAndVectors), "origin"_a, "xVector"_a, "yVector"_a, DOC(Bentley, Geom, Transform, InitFromOriginAndVectors));

    c1.def_static("FromOriginAndBearingXY", &Transform::FromOriginAndBearingXY, "origin"_a, "bearingRadians"_a, DOC(Bentley, Geom, Transform, FromOriginAndBearingXY));

    c1.def_static("FromOriginAndXVector", &Transform::FromOriginAndXVector, "origin"_a, "xVector"_a, DOC(Bentley, Geom, Transform, FromOriginAndXVector));

    c1.def("InitFrom3Points", &Transform::InitFrom3Points, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, Transform, InitFrom3Points));
    c1.def("InitNormalizedFrameFromOriginXPointYPoint", &Transform::InitNormalizedFrameFromOriginXPointYPoint, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, Transform, InitNormalizedFrameFromOriginXPointYPoint));
    c1.def("InitFrom", py::overload_cast<DMatrix4dCR>(&Transform::InitFrom), "matrix"_a, DOC(Bentley, Geom, Transform, InitFrom));
    c1.def("InitFrom2Points", &Transform::InitFrom2Points, "origin"_a, "xPoint"_a, "axisId"_a, "normalize"_a, DOC(Bentley, Geom, Transform, InitFrom2Points));
    c1.def("InitUniformScaleApproximation", &Transform::InitUniformScaleApproximation, "transform"_a, "primaryAxis"_a, "secondaryAxis"_a, DOC(Bentley, Geom, Transform, InitUniformScaleApproximation));
    
    c1.def("InverseOf", &Transform::InverseOf, "in"_a, DOC(Bentley, Geom, Transform, InverseOf));

    c1.def("ValidatedInverse", &Transform::ValidatedInverse, DOC(Bentley, Geom, Transform, ValidatedInverse));

    c1.def("InvertRigidBodyTransformation", &Transform::InvertRigidBodyTransformation, "in"_a, DOC(Bentley, Geom, Transform, InvertRigidBodyTransformation));

    c1.def_static("TryRangeMapping", &Transform::TryRangeMapping, "sourceRange"_a, "destRange"_a, "transform"_a, DOC(Bentley, Geom, Transform, TryRangeMapping));

    c1.def_static("FromLineAndRotationAngle", &Transform::FromLineAndRotationAngle, "point0"_a, "point1"_a, "radians"_a, DOC(Bentley, Geom, Transform, FromLineAndRotationAngle));
    c1.def_static("FromAxisAndRotationAngle", py::overload_cast<DRay3dCR, double, TransformR>(&Transform::FromAxisAndRotationAngle), "axis"_a, "radians"_a, "derivativeTransform"_a, DOC(Bentley, Geom, Transform, FromAxisAndRotationAngle));
    c1.def_static("FromAxisAndRotationAngle", py::overload_cast<DRay3dCR, double>(&Transform::FromAxisAndRotationAngle), "axis"_a, "radians"_a, DOC(Bentley, Geom, Transform, FromAxisAndRotationAngle));
    c1.def_static("FromPrincipleAxisRotations", &Transform::FromPrincipleAxisRotations, "inTransform"_a, "xrot"_a, "yrot"_a, "zrot"_a, DOC(Bentley, Geom, Transform, FromPrincipleAxisRotations));
    c1.def_static("FromOriginAndVectors", &Transform::FromOriginAndVectors, "origin"_a, "xVector"_a, "yVector"_a, "zVector"_a, DOC(Bentley, Geom, Transform, FromOriginAndVectors));
    c1.def_static("From4Points", &Transform::From4Points, "origin"_a, "xPoint"_a, "yPoint"_a, "zPoint"_a, DOC(Bentley, Geom, Transform, From4Points));
    c1.def_static("FromPlaneOf3Points", &Transform::FromPlaneOf3Points, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, Transform, FromPlaneOf3Points));
    c1.def_static("FromPlaneOf3PointsZeroZ", &Transform::FromPlaneOf3PointsZeroZ, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, Transform, FromPlaneOf3PointsZeroZ));
    c1.def_static("FromFixedPointAndScaleFactors", &Transform::FromFixedPointAndScaleFactors, "origin"_a, "xScale"_a, "yScale"_a, "zScale"_a, DOC(Bentley, Geom, Transform, FromFixedPointAndScaleFactors));
    c1.def_static("FromPlaneNormalToLine", &Transform::FromPlaneNormalToLine, "origin"_a, "xPoint"_a, "axisId"_a, "normalize"_a, DOC(Bentley, Geom, Transform, FromPlaneNormalToLine));
    c1.def_static("From2Points", &Transform::From2Points, "origin"_a, "xPoint"_a, "axisId"_a, "normalize"_a, DOC(Bentley, Geom, Transform, From2Points));

    c1.def("InitFromLineAndRotationAngle", &Transform::InitFromLineAndRotationAngle, "point0"_a, "point1"_a, "radians"_a, DOC(Bentley, Geom, Transform, InitFromLineAndRotationAngle));
    c1.def("InitFromMirrorPlane", &Transform::InitFromMirrorPlane, "origin"_a, "normal"_a, DOC(Bentley, Geom, Transform, InitFromMirrorPlane));
    c1.def("InitFromScalePerpendicularToPlane", &Transform::InitFromScalePerpendicularToPlane, "origin"_a, "normal"_a, "scale"_a, DOC(Bentley, Geom, Transform, InitFromScalePerpendicularToPlane));
    c1.def("InitFromProjectionToPlane", &Transform::InitFromProjectionToPlane, "origin"_a, "normal"_a, DOC(Bentley, Geom, Transform, InitFromProjectionToPlane));

    c1.def_static("FromProduct", py::overload_cast<TransformCR, TransformCR>(&Transform::FromProduct), "transformA"_a, "transformB"_a, DOC(Bentley, Geom, Transform, FromProduct));
    c1.def_static("FromProduct", py::overload_cast<TransformCR, TransformCR, TransformCR>(&Transform::FromProduct), "transformA"_a, "transformB"_a, "transformC"_a, DOC(Bentley, Geom, Transform, FromProduct));
    c1.def_static("FromProduct", py::overload_cast<RotMatrixCR, TransformCR>(&Transform::FromProduct), "matrixA"_a, "transformB"_a, DOC(Bentley, Geom, Transform, FromProduct));
    c1.def_static("FromProduct", py::overload_cast<TransformCR, RotMatrixCR>(&Transform::FromProduct), "transformA"_a, "matrixB"_a, DOC(Bentley, Geom, Transform, FromProduct));

    c1.def("InitProduct", py::overload_cast<TransformCR, TransformCR>(&Transform::InitProduct), "transform1"_a, "transform2"_a, DOC(Bentley, Geom, Transform, InitProduct));
    c1.def("InitProduct", py::overload_cast<RotMatrixCR, TransformCR>(&Transform::InitProduct), "matrix"_a, "transform"_a, DOC(Bentley, Geom, Transform, InitProduct));
    c1.def("InitProduct", py::overload_cast<TransformCR, RotMatrixCR>(&Transform::InitProduct), "transform"_a, "matrix"_a, DOC(Bentley, Geom, Transform, InitProduct));

    c1.def("GetFromMatrixByRowAndColumn", &Transform::GetFromMatrixByRowAndColumn, "row"_a, "col"_a, DOC(Bentley, Geom, Transform, GetFromMatrixByRowAndColumn));
    c1.def("GetPointComponent", &Transform::GetPointComponent, "row"_a, DOC(Bentley, Geom, Transform, GetPointComponent));
    c1.def("GetOriginAndVectors", 
           py::overload_cast<DPoint3dR, DVec3dR, DVec3dR, DVec3dR>(&Transform::GetOriginAndVectors, py::const_), 
           "origin"_a, "vector0"_a, "vector1"_a, "vector2"_a, DOC(Bentley, Geom, Transform, GetOriginAndVectors));
    c1.def("GetOriginAndVectors", py::overload_cast<DPoint2dR, DVec2dR, DVec2dR>(&Transform::GetOriginAndVectors, py::const_), "origin"_a, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, Transform, GetOriginAndVectors));
    c1.def("Get4Points", py::overload_cast<DPoint3dR, DPoint3dR, DPoint3dR, DPoint3dR>(&Transform::Get4Points, py::const_), "point0"_a, "point1"_a, "point2"_a, "point3"_a, DOC(Bentley, Geom, Transform, Get4Points));    

    c1.def("Matrix", &Transform::Matrix, DOC(Bentley, Geom, Transform, Matrix));
    c1.def("SetMatrix", &Transform::SetMatrix, "matrix"_a, DOC(Bentley, Geom, Transform, SetMatrix));
    c1.def("Origin", &Transform::Origin, DOC(Bentley, Geom, Transform, Origin));
    c1.def("Translation", &Transform::Translation, DOC(Bentley, Geom, Transform, Translation));

    c1.def("GetTranslation", py::overload_cast<DPoint3dR>(&Transform::GetTranslation, py::const_), "point"_a, DOC(Bentley, Geom, Transform, GetTranslation));
    c1.def("GetTranslation", py::overload_cast<DPoint2dR>(&Transform::GetTranslation, py::const_), "point"_a, DOC(Bentley, Geom, Transform, GetTranslation));
    c1.def("SetTranslation", py::overload_cast<DPoint3dCR>(&Transform::SetTranslation), "point"_a, DOC(Bentley, Geom, Transform, SetTranslation));
    c1.def("SetTranslation", py::overload_cast<DPoint2dCR>(&Transform::SetTranslation), "point"_a, DOC(Bentley, Geom, Transform, SetTranslation));

    c1.def("ZeroTranslation", &Transform::ZeroTranslation, DOC(Bentley, Geom, Transform, ZeroTranslation));

    c1.def("SetFixedPoint", py::overload_cast<DPoint2dCR>(&Transform::SetFixedPoint), "point"_a, DOC(Bentley, Geom, Transform, SetFixedPoint));
    c1.def("SetFixedPoint", py::overload_cast<DPoint3dCR>(&Transform::SetFixedPoint), "point"_a, DOC(Bentley, Geom, Transform, SetFixedPoint));

    c1.def("GetMatrixColumn", py::overload_cast<DVec3dR, int>(&Transform::GetMatrixColumn, py::const_), "column"_a, "index"_a, DOC(Bentley, Geom, Transform, GetMatrixColumn));    
    c1.def("SetMatrixColumn", &Transform::SetMatrixColumn, "column"_a, "index"_a, DOC(Bentley, Geom, Transform, SetMatrixColumn));

    c1.def("SetMatrixRow", &Transform::SetMatrixRow, "row"_a, "index"_a, DOC(Bentley, Geom, Transform, SetMatrixRow));
    c1.def("GetMatrixRow", &Transform::GetMatrixRow, "row"_a, "index"_a, DOC(Bentley, Geom, Transform, GetMatrixRow));

    c1.def("MatrixColumnMagnitude", &Transform::MatrixColumnMagnitude, "i"_a, DOC(Bentley, Geom, Transform, MatrixColumnMagnitude));

    c1.def("IsEqual", py::overload_cast<TransformCR>(&Transform::IsEqual, py::const_), "transform2"_a, DOC(Bentley, Geom, Transform, IsEqual));
    c1.def("IsEqual", py::overload_cast<TransformCR, double, double>(&Transform::IsEqual, py::const_), "transform2"_a, "matrixTolerance"_a, "pointTolerance"_a, DOC(Bentley, Geom, Transform, IsEqual));

    c1.def("MaxDiff", &Transform::MaxDiff, "otherTransform"_a, DOC(Bentley, Geom, Transform, MaxDiff));

    c1.def("Determinant", &Transform::Determinant, DOC(Bentley, Geom, Transform, Determinant));
    c1.def("ColumnXMagnitude", &Transform::ColumnXMagnitude, DOC(Bentley, Geom, Transform, ColumnXMagnitude));

    c1.def("Multiply", py::overload_cast<DPoint3dR>(&Transform::Multiply, py::const_), "point"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPoint3dR, DPoint3dCR>(&Transform::Multiply, py::const_), "result"_a, "point"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPoint3dR, double, double, double>(&Transform::Multiply, py::const_), "point"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, Transform, Multiply));
    
    c1.def("Multiply", [] (TransformCR self, DPoint3dArray& points)
           {
           self.Multiply(points.data(), (int) points.size());
           }, "points"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", [] (TransformCR self, DPoint3dArray& outPoints, DPoint3dArray const& inPoints)
           {
           self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
           }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DPoint2dR, DPoint2dCR>(&Transform::Multiply, py::const_), "result"_a, "point"_a, DOC(Bentley, Geom, Transform, Multiply));
    
    c1.def("Multiply", [] (TransformCR self, DPoint2dArray& outPoints, DPoint2dArray const& inPoints)
           {
           self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
           }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DPoint3dR, DPoint2dCR>(&Transform::Multiply, py::const_), "result"_a, "point"_a, DOC(Bentley, Geom, Transform, Multiply));
    
    c1.def("Multiply", [] (TransformCR self, DPoint3dArray& outPoints, DPoint2dArray const& inPoints)
           {
           self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
           }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DPoint2dR, DPoint3dCR>(&Transform::Multiply, py::const_), "result"_a, "point"_a, DOC(Bentley, Geom, Transform, Multiply));
    
    c1.def("Multiply", [] (TransformCR self, DPoint2dArray& outPoints, DPoint2dArray const& inPoints)
           {
           self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
           }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DPoint4dR, DPoint4dCR>(&Transform::Multiply, py::const_), "result"_a, "point"_a, DOC(Bentley, Geom, Transform, Multiply));
    
    c1.def("Multiply", [] (TransformCR self, DPoint4dArray& outPoints, DPoint4dArray const& inPoints)
           {
           self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
           }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("MultiplyTranspose", [] (TransformCR self, DPoint3dArray& outPoints, DPoint3dArray const& inPoints)
           {
           self.MultiplyTranspose(outPoints.data(), inPoints.data(), (int) inPoints.size());
           }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, Transform, MultiplyTranspose));

    c1.def("MultiplyTranspose", [] (TransformCR self, DPoint3dArray& points)
           {
           self.MultiplyTranspose(points.data(), (int) points.size());
           }, "points"_a, DOC(Bentley, Geom, Transform, MultiplyTranspose));

    c1.def("MultiplyMatrixOnly", py::overload_cast<DPoint3dR, double, double, double>(&Transform::MultiplyMatrixOnly, py::const_), "point"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, Transform, MultiplyMatrixOnly));
    c1.def("MultiplyMatrixOnly", py::overload_cast<DPoint3dR, DPoint3dCR>(&Transform::MultiplyMatrixOnly, py::const_), "outPoint"_a, "inPoint"_a, DOC(Bentley, Geom, Transform, MultiplyMatrixOnly));
    c1.def("MultiplyMatrixOnly", py::overload_cast<DPoint3dR>(&Transform::MultiplyMatrixOnly, py::const_), "point"_a, DOC(Bentley, Geom, Transform, MultiplyMatrixOnly));

    c1.def("MultiplyTransposeMatrixOnly", 
           py::overload_cast<DPoint3dR, double, double, double>(&Transform::MultiplyTransposeMatrixOnly, py::const_), 
           "point"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, Transform, MultiplyTransposeMatrixOnly));
    c1.def("MultiplyTransposeMatrixOnly", py::overload_cast<DPoint3dR, DPoint3dCR>(&Transform::MultiplyTransposeMatrixOnly, py::const_), "outPoint"_a, "inPoint"_a, DOC(Bentley, Geom, Transform, MultiplyTransposeMatrixOnly));
    c1.def("MultiplyTransposeMatrixOnly", py::overload_cast<DPoint3dR>(&Transform::MultiplyTransposeMatrixOnly, py::const_), "point"_a, DOC(Bentley, Geom, Transform, MultiplyTransposeMatrixOnly));        

    c1.def("MultiplyWeighted", py::overload_cast<DPoint3dR, double>(&Transform::MultiplyWeighted, py::const_), "point"_a, "weight"_a, DOC(Bentley, Geom, Transform, MultiplyWeighted));
    
    c1.def("MultiplyWeighted",
           py::overload_cast<DPoint3dArray&, DPoint3dArray const&, DoubleArray const*>(&Transform::MultiplyWeighted, py::const_),
           "weightedXYZOut"_a, "weightedXYZIn"_a, "weights"_a, DOC(Bentley, Geom, Transform, MultiplyWeighted));

    c1.def("Solve", &Transform::Solve, "outPoint"_a, "inPoint"_a, DOC(Bentley, Geom, Transform, Solve));
    
    c1.def("SolveArray", py::overload_cast<DPoint3dArray&, DPoint3dArray const&>(&Transform::SolveArray, py::const_), "xyzOut"_a, "xyzIn"_a, DOC(Bentley, Geom, Transform, SolveArray));

    c1.def("Multiply", py::overload_cast<DRange3dR, DRange3dCR>(&Transform::Multiply, py::const_), "outRange"_a, "inRange"_a, DOC(Bentley, Geom, Transform, Multiply));
    
    c1.def("Multiply", py::overload_cast<DEllipse3dR>(&Transform::Multiply, py::const_), "inoutEllipse"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DEllipse3dR, DEllipse3dCR>(&Transform::Multiply, py::const_), "outEllipse"_a, "inEllipse"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DPlane3dR>(&Transform::Multiply, py::const_), "inoutPlane"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPlane3dR, DPlane3dCR>(&Transform::Multiply, py::const_), "outPlane"_a, "inPlane"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DSegment3dR>(&Transform::Multiply, py::const_), "inoutSegment"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DSegment3dR, DSegment3dCR>(&Transform::Multiply, py::const_), "outSegment"_a, "inSegment"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("Multiply", py::overload_cast<DRay3dR>(&Transform::Multiply, py::const_), "inoutRay"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DRay3dR, DRay3dCR>(&Transform::Multiply, py::const_), "outRay"_a, "inRay"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("TransformImplicitPlane", [] (TransformCR self, double a, double b, double c, double d)
        {
        double aOut, bOut, cOut, dOut;
        bool bOk = self.TransformImplicitPlane(aOut, bOut, cOut, dOut, a, b, c, d);
        return py::make_tuple(bOk, aOut, bOut, cOut, dOut);
        }, "a"_a, "b"_a, "c"_a, "d"_a, DOC(Bentley, Geom, Transform, TransformImplicitPlane));

    c1.def("Multiply", py::overload_cast<DPoint4dArray&, DPoint4dArray const&>(&Transform::Multiply, py::const_), "xyzwOut"_a, "xyzwIn"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPoint3dArray&, DPoint3dArray const&>(&Transform::Multiply, py::const_), "xyzOut"_a, "xyzIn"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPoint2dArray&, DPoint2dArray const&>(&Transform::Multiply, py::const_), "xyOut"_a, "xyIn"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPoint3dArray&, DPoint2dArray const&>(&Transform::Multiply, py::const_), "xyzOut"_a, "xyIn"_a, DOC(Bentley, Geom, Transform, Multiply));
    c1.def("Multiply", py::overload_cast<DPoint2dArray&, DPoint3dArray const&>(&Transform::Multiply, py::const_), "xyOut"_a, "xyzIn"_a, DOC(Bentley, Geom, Transform, Multiply));

    c1.def("IsIdentity", &Transform::IsIdentity, DOC(Bentley, Geom, Transform, IsIdentity));
    c1.def("IsRigid", &Transform::IsRigid, DOC(Bentley, Geom, Transform, IsRigid));

    c1.def("IsRigidScale", [] (TransformCR self)
        {
        double scale = 0;
        bool bOk = self.IsRigidScale(scale);
        return py::make_tuple(bOk, scale);
        }, DOC(Bentley, Geom, Transform, IsRigidScale));

    c1.def("IsNearRigidScale", &Transform::IsNearRigidScale, "dest"_a, "primaryAxis"_a = 0, "tolerance"_a = 1.0e-6, DOC(Bentley, Geom, Transform, IsNearRigidScale));
    c1.def("IsPlanar", &Transform::IsPlanar, "normal"_a, DOC(Bentley, Geom, Transform, IsPlanar));
    c1.def("IsTranslate", &Transform::IsTranslate, "translation"_a, DOC(Bentley, Geom, Transform, IsTranslate));
        
    c1.def("IsUniformScale", [] (TransformCR self, DPoint3dR fixedPoint)
        {
        double scale = 0;
        bool bOk = self.IsUniformScale(fixedPoint, scale);
        return py::make_tuple(bOk, scale);
        }, "fixedPoint"_a, DOC(Bentley, Geom, Transform, IsUniformScale));

    c1.def("IsRotateAroundLine", [] (TransformCR self, DPoint3dR fixedPoint, DVec3dR directionVector)
        {
        double radians = 0;
        bool bOk = self.IsRotateAroundLine(fixedPoint, directionVector, radians);
        return py::make_tuple(bOk, radians);
        }, "fixedPoint"_a, "directionVector"_a, DOC(Bentley, Geom, Transform, IsRotateAroundLine));

    c1.def("IsMirrorAboutPlane", &Transform::IsMirrorAboutPlane, "planePoint"_a, "unitNormal"_a, DOC(Bentley, Geom, Transform, IsMirrorAboutPlane));

    c1.def("IsUniformScaleAndRotateAroundLine", [] (TransformCR self, DPoint3dR fixedPoint, DVec3dR directionVector)
        {
        double radians = 0;
        double scale = 0;
        bool bOk = self.IsUniformScaleAndRotateAroundLine(fixedPoint, directionVector, radians, scale);
        return py::make_tuple(bOk, radians, scale);
        }, "fixedPoint"_a, "directionVector"_a, DOC(Bentley, Geom, Transform, IsUniformScaleAndRotateAroundLine));

    c1.def("GetAnyFixedPoint", &Transform::GetAnyFixedPoint, "fixedPoint"_a, DOC(Bentley, Geom, Transform, GetAnyFixedPoint));
    c1.def("GetFixedLine", &Transform::GetFixedLine, "fixedPoint"_a, "directionVector"_a, DOC(Bentley, Geom, Transform, GetFixedLine));
    
    c1.def("GetFixedPlane",
           py::overload_cast<DPoint3dR, DVec3dR, DVec3dR>(&Transform::GetFixedPlane, py::const_),
           "fixedPoint"_a, "planeVectorX"_a, "planeVectorY"_a, DOC(Bentley, Geom, Transform, GetFixedPlane));

    c1.def("GetFixedPlane",
           py::overload_cast<TransformR, TransformR, DPoint3dR, DVec3dR>(&Transform::GetFixedPlane, py::const_),
           "residualTransform"_a, "mirrorTransform"_a, "planePoint"_a, "planeNormal"_a, DOC(Bentley, Geom, Transform, GetFixedPlane));

    c1.def("TranslateInLocalCoordinates", &Transform::TranslateInLocalCoordinates, "in"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, Transform, TranslateInLocalCoordinates));
    c1.def("InitFromPrincipleAxisRotations", &Transform::InitFromPrincipleAxisRotations, "inTransform"_a, "xRot"_a, "yRot"_a, "zRot"_a, DOC(Bentley, Geom, Transform, InitFromPrincipleAxisRotations));
    c1.def("ScaleMatrixColumns", py::overload_cast<TransformCR, double, double, double>(&Transform::ScaleMatrixColumns), "InTransform"_a, "xScale"_a, "yScale"_a, "zScale"_a, DOC(Bentley, Geom, Transform, ScaleMatrixColumns));

    c1.def_static("InitForwardAndInverseFromAxesAndOrigin", &Transform::InitForwardAndInverseFromAxesAndOrigin, "localToWorld"_a, "worldToLocal"_a, "axes"_a, "origin"_a, DOC(Bentley, Geom, Transform, InitForwardAndInverseFromAxesAndOrigin));

    c1.def("ScaleMatrixColumns", py::overload_cast<double, double, double>(&Transform::ScaleMatrixColumns), "xscale"_a, "yscale"_a, "zscale"_a, DOC(Bentley, Geom, Transform, ScaleMatrixColumns));
    c1.def("ScaleMatrixRows", &Transform::ScaleMatrixRows, "transform"_a, "xscale"_a, "yscale"_a, "zscale"_a, DOC(Bentley, Geom, Transform, ScaleMatrixRows));
    c1.def("ScaleCompleteRows", &Transform::ScaleCompleteRows, "transform"_a, "xscale"_a, "yscale"_a, "zscale"_a, DOC(Bentley, Geom, Transform, ScaleCompleteRows));

    c1.def("MultiplyTranslationTransform", &Transform::MultiplyTranslationTransform, "translation"_a, "scaleFactor"_a, "transform"_a, DOC(Bentley, Geom, Transform, MultiplyTranslationTransform));
    c1.def("MultiplyTransformTranslation", &Transform::MultiplyTransformTranslation, "transform"_a, "translation"_a, "scaleFactor"_a, DOC(Bentley, Geom, Transform, MultiplyTransformTranslation));
    c1.def_static("CorrectCoordinateFrameXYRange", &Transform::CorrectCoordinateFrameXYRange, 
           "localToWorld"_a, "worldToLocal"_a, "localRange"_a, "frameType"_a, "appliedTransformOldLocalToNewLocal"_a = nullptr, DOC(Bentley, Geom, Transform, CorrectCoordinateFrameXYRange));

    c1.def("ScaleDoubleArrayByXColumnMagnitude", &Transform::ScaleDoubleArrayByXColumnMagnitude, "data"_a, "n"_a, DOC(Bentley, Geom, Transform, ScaleDoubleArrayByXColumnMagnitude));
    c1.def("OffsetPointByColumn", &Transform::OffsetPointByColumn, "out"_a, "in"_a, "i"_a, DOC(Bentley, Geom, Transform, OffsetPointByColumn));

    c1.def("__repr__", [] (Transform& self)
           {
           return "[{}, {}, {}, {};\n{}, {}, {}, {}; {}, {}, {}, {}]"_s
               .format(self.form3d[0][0], self.form3d[0][1], self.form3d[0][2], self.form3d[0][3],
                       self.form3d[1][0], self.form3d[1][1], self.form3d[1][2], self.form3d[1][3],
                       self.form3d[2][0], self.form3d[2][1], self.form3d[2][2], self.form3d[2][3]);
           });

    c1.def("__copy__", [](const Transform& self)
        {
        return Transform(self);
        });
    }