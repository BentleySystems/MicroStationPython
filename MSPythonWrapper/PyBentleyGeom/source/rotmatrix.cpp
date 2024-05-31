/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\rotmatrix.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/OperatorOverload.h>
#include <Pybind11/numpy.h>


static const char * __doc_Bentley_Geom_RotMatrix_HyperbolicColumnOp =R"doc(Apply a hyperbolic " column operation ", i.e. pre-multiply by a
hyperbolic reflection matrix The matrix is an identity except for the
4 entries R(i0,i0)=R(i1,i1)=secant R(i0,i1)=R(i1,i0)=tangent

Parameter ``[in]``:
    secant The cosine of reflection.

Parameter ``[in]``:
    tangent The sine of reflection.

Parameter ``[in]``:
    i0 The index of the first affected row.

Parameter ``[in]``:
    i1 The index of the second affected row.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_HyperbolicRowOp =R"doc(Apply a hyperbolic " row operation ", i.e. pre-multiply by a hyperbolic
reflection matrix The matrix is an identity except for the 4 entries
R(i0,i0)=R(i1,i1)=secant R(i0,i1)=R(i1,i0)=tangent

Parameter ``[in]``:
    secant The cosine of reflection.

Parameter ``[in]``:
    tangent The sine of reflection.

Parameter ``[in]``:
    i0 The index of the first affected row.

Parameter ``[in]``:
    i1 The index of the second affected row.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GivensColumnOp =R"doc(Apply a Givens " column operation ", i.e. post-multiply by a Givens
rotation matrix. The Givens matrix is an identity except for the 4
rotational entries, viz R(i0,i0)=R(i1,i1)=c R(i0,i1)=-s R(i1,i0)=s

Parameter ``[in]``:
    c The cosine of givens rotation.

Parameter ``[in]``:
    s The sine of givens rotation.

Parameter ``[in]``:
    i0 The index of the first affected row.

Parameter ``[in]``:
    i1 The index of the second affected row.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GivensRowOp =R"doc(Apply a Givens " row operation ", i.e. pre-multiply by a Givens rotation
matrix. The Givens matrix is an identity except for the 4 rotational
entries, viz R(i0,i0)=R(i1,i1)=c R(i0,i1)=s R(i1,i0)=-s

Parameter ``[in]``:
    c The cosine of givens rotation.

Parameter ``[in]``:
    s The sine of givens rotation.

Parameter ``[in]``:
    i0 The index of the first affected row.

Parameter ``[in]``:
    i1 The index of the second affected row.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_ColumnXAngleXY =R"doc(Returns the (0 or positive) angle from (1,0) to the XY vector in the
first column.

Returns:
    rotation angle (in radians) between 0 and 2Pi)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetRotationAngleAndVector =R"doc(Returns the angle of rotation of this instance and sets axis to be the
normalized vector about which this instance rotates. NOTE:this
instance is assumed to be a (rigid body, i.e. orthogonal) rotation
matrix. Since negating both angle and axis produces an identical
rotation, calculations are simplified by assuming (and returning) the
angle in [0,Pi].

Parameter ``[out]``:
    axis normalized axis of rotation

Returns:
    rotation angle (in radians) between 0 and Pi, inclusive)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetQuaternion =R"doc(Parameter ``[out]``:
    quat quaternion, stored as xyzw

Parameter ``[in]``:
    transpose true if matrix is stored transposed)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitTransposedFromQuaternionWXYZ =R"doc(Initialization, compatible with mdlRMatrix_fromQuat.

Parameter ``[in]``:
    pQuatAsDoubleArray The quaternion, stored as (w,x,y,z) in an array
    of doubles.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FactorOrthogonalColumns =R"doc(Factor the instance as a product B*V^ where B has mutually
perpendicular columns and V is orthogonal.

Parameter ``[out]``:
    matrixB orthogonal columns

Parameter ``[out]``:
    matrixV transpose of right factor. (I.e. B = A*V))doc";

static const char * __doc_Bentley_Geom_RotMatrix_RotateAndSkewFactors =R"doc(Factor as{rotation*skewFactor} where the rotation favors indicated
primary and secondary axes.

Parameter ``[out]``:
    rotation the (orthogonal, right handed) rotation.

Parameter ``[out]``:
    skewFactor the scale and skew parts.

Parameter ``[in]``:
    primaryAxis selects column whose direction is preserved.

Parameter ``[in]``:
    secondaryAxis selects columns that defines plane (with
    primaryAxis)

Returns:
    true if primary and secondary are independent.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FactorRotateScaleRotate =R"doc(Factor as{rotation1 * scale * rotation2}

Returns:
    number of nonzero scales (independent columns).

Parameter ``[out]``:
    rotation1 pure rotation

Parameter ``[out]``:
    scalePoint scale factors, largest first.

Parameter ``[out]``:
    rotation2 pure rotation)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsEqual =R"doc( Tests for equality between two matrices " Equality " means
relative error less than 1.0e-12, in the sense that each component-
wise difference is less than 1.0e-12 times the largest absolute value
of the components of one matrix.

Parameter ``[in]``:
    matrix2 The second matrix

Returns:
    true if the matrices are identical.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsPlanar =R"doc( Tests if this instance matrix has no effects
perpendicular to any plane with the given normal. This will be true if
the matrix represents a combination of (a) scaling perpencicular to
the normal and (b) rotation around the normal.

Parameter ``[in]``:
    normal The plane normal

Returns:
    true if the matrix has no effects perpendicular to any plane with
    the given normal.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsNearRigidScale =R"doc(Determine if a matrix is close to a pure rotate and scale. If source
is not near rigid, return false and copy to the output. If near an
identity return identity. If nearly perpendicular with scales other
than 1, clean preserving the length and direction of the primary axis.
This is intended to be used with a crude (e.g. 1.0e-6) reltol to
identify old DGN file matrices that are " dirty " by modern standards
but were meant to be identity, rotation, or scaled rotations in the
UOR era.

Parameter ``[in]``:
    dest result matrix

Parameter ``[in]``:
    primaryAxis axis whose orientation and direction is preserved.

Parameter ``[in]``:
    tolerance relative tolerance for recognizing near-perpendicular
    conditions.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsRigidScale =R"doc( Test if this instance matrix is composed of only rigid
rotation and scaling.

Parameter ``[out]``:
    columns matrix containing the unit vectors along the columns.

Parameter ``[out]``:
    scale largest axis scale factor. If function value is true, the
    min scale is the same. Use areColumnsOrthonormal to get separate
    column scales.

Returns:
    true if the matrix is orthonormal.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsOrthonormal =R"doc( Test if this instance matrix has orthonormal columns,
i.e. its columns are all perpendicular to one another.

Parameter ``[out]``:
    columns matrix containing the unit vectors along the columns.

Parameter ``[out]``:
    axisScales point whose x, y, and z components are the magnitudes
    of the original columns.

Parameter ``[out]``:
    axisRatio smallest axis length divided by largest.

Returns:
    true if the matrix is orthonormal.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsOrthogonal =R"doc( Test if this instance matrix is orthogonal, i.e. its
transpose is its inverse. This class of matrices includes both rigid
body rotations and reflections.

Returns:
    true if the matrix is orthogonal.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsRigid =R"doc( Test if a matrix is a rigid body rotation, i.e. its
transpose is its inverse and it has a positive determinant.

Returns:
    true if the matrix is a rigid body rotation.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsNearSignedPermutation =R"doc( Test if this instance matrix does nothing more than
exchange and possibly negate principle axes, within a tolerance.

Parameter ``[out]``:
    result the nearby permutation, or the orignal matrix if none near.

Parameter ``[in]``:
    tolerance tolerance for comparison to the permutation

Returns:
    true if the matrix is a near permutation of the principle axes.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsSignedPermutation =R"doc( Test if this instance matrix does nothing more than
exchange and possibly negate principle axes.

Returns:
    true if the matrix is a permutation of the principle axes.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SumOffDiagonalSquares =R"doc( Computes the sum of the squares of the off-diagonal
entries of this instance matrix.

Returns:
    sum of square of off-diagonal entries of the matrix.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SumDiagonalSquares =R"doc( Computes the sum of the squares of the diagonal entries
of this instance matrix.

Returns:
    Sum of squares of diagonal entries)doc";

static const char * __doc_Bentley_Geom_RotMatrix_MaxDiff =R"doc( Returns the largest absolute value difference between
corresponding coefficients in Matrix1 and Matrix2.

Parameter ``[in]``:
    matrix2 The matrix to compare to

Returns:
    largest absolute difference between the two matrices.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_MaxAbs =R"doc( Find the largest absolute value of entries in the matrix.

Returns:
    largest absolute value in matrix)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SumSquares =R"doc( Return the sum of squares of coefficients in a matrix.

Returns:
    Sum of squares of all entries in matrix)doc";

static const char * __doc_Bentley_Geom_RotMatrix_DiagonalMaxAbs =R"doc( return the largest absolute value on the diagonal)doc";

static const char * __doc_Bentley_Geom_RotMatrix_UpperTriangleMaxAbs =R"doc( return the largest absolute value in the upper triangle.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_LowerTriangleMaxAbs =R"doc( return the largest absolute value in the lower triangle.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_UpperTriangleAbsRange =R"doc( return the range of absolute values strictly above the
diagonal.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_LowerTriangleAbsRange =R"doc( return the range of absolute values strictly below the
diagonal.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_OffDiagonalAbsRange =R"doc( Return the (absolute value) range of entries off the
diagonal.

Parameter ``[out]``:
    minValue smallest absolute value

Parameter ``[out]``:
    maxValue largest absolute value)doc";

static const char * __doc_Bentley_Geom_RotMatrix_OffDiagonalSignedRange =R"doc( Return the (signed) range of entries off the diagonal.

Parameter ``[out]``:
    minValue smallest signed value

Parameter ``[out]``:
    maxValue largest signed value)doc";

static const char * __doc_Bentley_Geom_RotMatrix_DiagonalAbsRange =R"doc( Return the (absolute value) range of entries on the
diagonal.

Parameter ``[out]``:
    minValue smallest absolute value

Parameter ``[out]``:
    maxValue largest absolute value)doc";

static const char * __doc_Bentley_Geom_RotMatrix_DiagonalSignedRange =R"doc( Return the (signed) range of entries on the diagonal.

Parameter ``[out]``:
    minValue smallest signed value

Parameter ``[out]``:
    maxValue largest signed value)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsUniformScale =R"doc( Tests if a matrix has (nearly) equal diagaonal entries
and (nearly) zero off diagonals. Tests use a tight relative tolerance.

Parameter ``[out]``:
    maxScale the largest diagaonal entry

Returns:
    true if matrix is approximately diagonal)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsDiagonal =R"doc( Tests if a matrix has small offdiagonal entries compared
to diagonals. The specific test condition is that the largest off
diagonal absolute value is less than a tight tolerance fraction times
the largest diagonal entry.

Returns:
    true if matrix is approximately diagonal)doc";

static const char * __doc_Bentley_Geom_RotMatrix_IsIdentity =R"doc( Tests if a matrix is the identity matrix.

Returns:
    true if matrix is approximately an identity.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_ConditionNumber =R"doc(Computes an estimate of the condition of this instance matrix. Values
near 0 are bad.

Returns:
    estimated condition number.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Determinant =R"doc( Returns the determinant of the matrix.

Returns:
    determinant of the matrix.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetRowValuesXY =R"doc( Copies 4 doubles from xx,xy,yx,yy positions into an
array.

Parameter ``[out]``:
    data returned data -- first 2 entries in row 0, then first 2 in
    row 1.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetRowValues =R"doc( Get all contents as individual doubles, moving along rows)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetComponentByRowAndColumn =R"doc( Returns a value from a specified row and column of the
matrix.

Parameter ``[in]``:
    row The index of row to read. Row indices are 0, 1, 2.

Parameter ``[in]``:
    col The index of column to read. Column indices are 0, 1, 2.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SetRow =R"doc( Set the components in a row.

Parameter ``[in]``:
    vector new values

Parameter ``[in]``:
    row The index of row to change. Row indices are 0, 1, 2.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SetColumn =R"doc( Set the components in a column.

Parameter ``[in]``:
    vector new values

Parameter ``[in]``:
    col The index of column to change. Column indices are 0, 1, 2.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetRow =R"doc( Returns a vector taken from a column of a matrix.

Parameter ``[out]``:
    vector filled vector

Parameter ``[in]``:
    row The index of row to extract. Row indices are 0, 1, and 2.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetColumn =R"doc( Returns a point taken from a column of a matrix.

Parameter ``[out]``:
    vector filled vector

Parameter ``[in]``:
    col The index of column to extract. Column indices are 0, 1, 2.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetRows =R"doc( Copies from rows of this instance matrix to corresponding
points.

Parameter ``[out]``:
    vectorU first row

Parameter ``[out]``:
    vectorV second row

Parameter ``[out]``:
    vectorW third row)doc";

static const char * __doc_Bentley_Geom_RotMatrix_GetColumns =R"doc( Copies from columns of this instance matrix to
corresponding points.

Parameter ``[out]``:
    vectorU first column

Parameter ``[out]``:
    vectorV second column

Parameter ``[out]``:
    vectorW third column)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SolveTranspose =R"doc( Return the product of a matrix inverse transpose and a
point.

Parameter ``[out]``:
    result result of the multiplication

Parameter ``[in]``:
    point The known point multipled by the matrix inverse.

Returns:
    false if this instance is singular.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Solve =R"doc( Return the product of a matrix inverse and a point.

Parameter ``[out]``:
    result the unknown point

Parameter ``[in]``:
    point The The known point

Returns:
    false if this instance is singular.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SolveArray =R"doc( Solve M*xyzOut[i] = xyzIn[i] for array of points.
(Equivalent to multiplying by the matrix inverse))doc";

static const char * __doc_Bentley_Geom_RotMatrix_MultiplyTransposeComponents =R"doc( Returns the product P = [x,y,z]*M where M is the input
matrix and P is the product point.

Parameter ``[out]``:
    result product point

Parameter ``[in]``:
    x The x component

Parameter ``[in]``:
    y The y component

Parameter ``[in]``:
    z The z component)doc";

static const char * __doc_Bentley_Geom_RotMatrix_MultiplyComponents =R"doc( Returns the product of a matrix times a point, with the
point given as separate components.

Parameter ``[out]``:
    result result of multiplication

Parameter ``[in]``:
    x The x component of input point

Parameter ``[in]``:
    y The y component of input point

Parameter ``[in]``:
    z The z component of input point)doc";

static const char * __doc_Bentley_Geom_RotMatrix_MultiplyTranspose =R"doc( Returns the product of a matrix transpose times a point.

Parameter ``[out]``:
    result result of the multiplication.

Parameter ``[in]``:
    point The known point.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Multiply =R"doc(Computes{M*P[i]} where M is this instance matrix and each P[i] is a
point in the input array point. Each result is placed in the
corresponding entry in the output array result. The same array may be
named for the input and output arrays.

Parameter ``[out]``:
    result output points

Parameter ``[in]``:
    point The input points

Parameter ``[in]``:
    numPoint The number of points)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Invert =R"doc( Inverts this instance matrix in place.

Returns:
    true if the matrix is invertible.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InverseOf =R"doc( Returns the inverse of the a matrix.

Parameter ``[in]``:
    forward The input matrix

Returns:
    true if the matrix is invertible.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Subtract =R"doc( Subtract a matrix (componentwise, in place).

Parameter ``[in]``:
    delta The matrix to subtract)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Add =R"doc( Add a matrix (componentwise, in place).

Parameter ``[in]``:
    delta The matrix to add)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SumOf =R"doc( Returns{Matrix0 + Matrix1*s1+Matrix2*s2}, i.e. the sum
of matrix M0, matrix M1 multiplied by scale s1, and matrix M2
multiplied by scale s2. Any combination of the matrix pointers may
have identical addresses.

Parameter ``[in]``:
    matrix0 The matrix0 of formula

Parameter ``[in]``:
    matrix1 The matrix1 of formula

Parameter ``[in]``:
    scale1 The scale factor to apply to Matrix1

Parameter ``[in]``:
    matrix2 The matrix2 of formula

Parameter ``[in]``:
    scale2 The scale factor to apply to Matrix2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Transpose =R"doc( Transposes a matrix in place.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_TransposeOf =R"doc( Initializes this instance as the transpose of a matrix.

Parameter ``[in]``:
    matrix The input matrix)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitProductRotMatrixRotMatrixTranspose =R"doc( Returns the product of rotMatrixA times the transpose of
rotMatrixB

Parameter ``[in]``:
    rotMatrixA The first factor

Parameter ``[in]``:
    rotMatrixB The second factor (to be transposed))doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitProductRotMatrixTransposeRotMatrix =R"doc( Returns the product of the transpose of rotMatrixA times
rotMatrixB

Parameter ``[in]``:
    rotMatrixA The first factor (to be transposed)

Parameter ``[in]``:
    rotMatrixB The second factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitProduct =R"doc( Returns the product{A*B} of two matrices.

Parameter ``[in]``:
    rotMatrixA The first factor

Parameter ``[in]``:
    rotMatrixB The second factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Copy =R"doc( Sets this instance matrix by copying from the matrix
parameter.

Parameter ``[in]``:
    in The source matrix)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SquareAndNormalizeColumnsAnyOrder =R"doc( Returns an orthogonal matrix that preserves aligns with
the columns of inMatrix. This is done by trying various combinations
of primary and secondary axes until one succeeds in
squareAndNormalizeColumns.

Parameter ``[in]``:
    inMatrix The input matrix

Parameter ``[in]``:
    preferredOrientation

* 1 for right handed system


* -1 for left handed system


* 0 to match orientation of input (but default to right handed if input is singular)
)doc";

static const char * __doc_Bentley_Geom_RotMatrix_SquareAndNormalizeColumns =R"doc( Adjust the direction and length of columns of the input
matrix to produce an instance matrix which has perpendicular, unit
length columns. The column whose index is primaryAxis (i.e. 0,1,2 for
x,y,z axis of coordinate frame) is normalized to unit length in its
current direction. The column whose index is secondaryAxis is unit
length and perpendicular to the primaryAxis column, and lies in the
same plane as that defined by the original primary and secondary
columns. To preserve X axis and XY plane, call with axis id's 0 and 1.
To preserve Z axis and ZX plane, call with axis id's 2 and 0. inMatrix
and pMatrix may be the same address.

Parameter ``[in]``:
    inMatrix The input matrix

Parameter ``[in]``:
    primaryAxis The axis id (0, 1, 2) which is to be normalized but
    left in its current direction

Parameter ``[in]``:
    secondaryAxis The axis id (0, 1, 2) which is to be kept within the
    plane of the primary and secondary axis.

Returns:
    false if primaryAxis and secondaryAxis are the same, or either
    axis has zero length)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitRotationFromVectorToVector =R"doc( (conditionally) initialize the instance as the (smallest)
rotation that moves startVector so it is in the direction of
endVector. In the normal case where the vectors are not parallel or
antiparallel, this is a rotation around their cross product.

Returns:
    false if one or both are zero vectors.

Remark:
    if the vectors are direction opposite, the rotation is around an
    arbitrarily)doc";

static const char * __doc_Bentley_Geom_RotMatrix_ShuffleColumnsOf =R"doc( Moves columns 0, 1, 2 of the input matrix into columns
i0, i1, i2 of the instance.

Parameter ``[in]``:
    inMatrix The input matrix

Parameter ``[in]``:
    i0 The column to receive input column 0

Parameter ``[in]``:
    i1 The column to receive input column 1

Parameter ``[in]``:
    i2 The column to receive input column 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_AddScaledOuterProductInPlace =R"doc( Accumulates a 'rank one' matrix defined as a scale factor
times the 'vector outer product' of two vectors, i.e. as the matrix
{s*U*V^T}

Parameter ``[in]``:
    vectorU The column vector U

Parameter ``[in]``:
    vectorV The row vector V

Parameter ``[in]``:
    scale The scale factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_Scale =R"doc( Returns a matrix formed from a scaling matrix which is
multiplied on the left and/or right with other matrices. That is, form
LeftMatrix * ScaleMatrix * RightMatrix where the ScaleMatrix is
constructed from the given scale factors.

Parameter ``[in]``:
    leftMatrix The matrix on left of product

Parameter ``[in]``:
    xs The x scale factor

Parameter ``[in]``:
    ys The y scale factor

Parameter ``[in]``:
    zs The z scale factor

Parameter ``[in]``:
    rightMatrix The matrix on right of product)doc";

static const char * __doc_Bentley_Geom_RotMatrix_NormalizeColumnsOf =R"doc( Returns a matrix whose rows are unit vectors in the same
drection as corresponding columns of the input matrix. Also
(optionally) stores the original column magnitudes as components of
the point.

Parameter ``[in]``:
    inMatrix The input matrix

Parameter ``[out]``:
    scaleVector length of original columns)doc";

static const char * __doc_Bentley_Geom_RotMatrix_NormalizeRowsOf =R"doc( Returns a matrix whose rows are unit vectors in the same
drection as corresponding rows of the input matrix. Also (optionally)
stores the original row magnitudes as components of the point.

Parameter ``[in]``:
    inMatrix The input matrix

Parameter ``[out]``:
    scaleVector length of original rows)doc";

static const char * __doc_Bentley_Geom_RotMatrix_ScaleColumns =R"doc( Applies scale factors to corresponding columns of the
input matrix, and places the result in this instance matrix.

Parameter ``[in]``:
    in The initial matrix

Parameter ``[in]``:
    xs The scale factor for column 0

Parameter ``[in]``:
    ys The scale factor for column 1

Parameter ``[in]``:
    zs The scale factor for column 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_ScaleRows =R"doc( Applies scale factors to corresponding rows of the input
matrix, and places the result in this instance matrix.

Parameter ``[in]``:
    inMatrix The initial matrix

Parameter ``[in]``:
    xScale The scale factor for row 0

Parameter ``[in]``:
    yScale The scale factor for row 1

Parameter ``[in]``:
    zScale The scale factor for row 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromQuaternion =R"doc(Parameter ``[in]``:
    quat The quaternion, stored as (xyzw))doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFrom =R"doc(Sets this instance matrix by copying the matrix part of the trasnform.

Parameter ``[in]``:
    transform The transformation whose matrix part is returned)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitRotationFromOriginXY =R"doc( Set this instance matrix to be an orthogonal (rotation)
matrix with column 0 in the direction from the origin to the x point,
column 1 in the plane of the 3 points, directed so the Y point on the
positive side, and column 2 as their cross product.

Parameter ``[in]``:
    origin The reference point

Parameter ``[in]``:
    xPoint The x axis target point

Parameter ``[in]``:
    yPoint The 3rd point defining xy plane.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFrom1Vector =R"doc( Initializes this instance matrix so that the indicated
axis (axis = 0,1,or 2) is aligned with the vector dir. The normalize
flag selects between normalized axes (all matrix columns of unit
length) and unnormalized axes (all matrix columns of same length as
the dir vector).

Parameter ``[in]``:
    dir The fixed direction vector

Parameter ``[in]``:
    axis The axis column to be aligned with direction

Parameter ``[in]``:
    normalize true to have normalized columns

Returns:
    true if the direction vector is nonzero.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromPrincipleAxisRotations =R"doc( Returns the product{RX*RY*RZ*M} where RX, RY, and RZ are
rotations (in radians) around X, Y, and Z axes, and M is the input
matrix.

Parameter ``[in]``:
    inMatrix The prior matrix

Parameter ``[in]``:
    xrot The x axis rotation

Parameter ``[in]``:
    yrot The y axis rotation

Parameter ``[in]``:
    zrot The z axis rotation)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromDirectionAndScale =R"doc( Initializes a matrix which scales along a vector
direction.

Parameter ``[in]``:
    vector The scaling direction

Parameter ``[in]``:
    scale The scale factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromAxisAndRotationAngle =R"doc( Returns a matrix of rotation about the x,y, or z axis
(indicated by axis = 0,1, or 2) by an angle in radians.

Parameter ``[in]``:
    axis The axis index 0=x, 1=y, 2=z

Parameter ``[in]``:
    radians The rotation angle in radians)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromRowVectors =R"doc( Initializes a matrix with 3 points copied to respective
rows.

Parameter ``[in]``:
    vectorU The vector to insert in row 0

Parameter ``[in]``:
    vectorV The vector to insert in row 1

Parameter ``[in]``:
    vectorW The vector to insert in row 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromColumnVectors =R"doc( Returns a matrix with 3 points copied to respective
columns.

Parameter ``[in]``:
    vectorU The vector to insert in column 0

Parameter ``[in]``:
    vectorV The vector to insert in column 1

Parameter ``[in]``:
    vectorW The vector to insert in column 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromRowValuesXY =R"doc( Initializes a matrix with the 4 specified coefficients in
xx,xy,yx,yy positions, and 1 in zz in " row major " order.

Parameter ``[in]``:
    x00 The 00 entry

Parameter ``[in]``:
    x01 The 01 entry

Parameter ``[in]``:
    x10 The 10 entry

Parameter ``[in]``:
    x11 The 11 entry)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromRowValues =R"doc( Initializes a matrix with the 9 specified coefficients
given in " row major " order.

Parameter ``[in]``:
    x00 The 00 entry

Parameter ``[in]``:
    x01 The 01 entry

Parameter ``[in]``:
    x02 The 02 entry

Parameter ``[in]``:
    x10 The 10 entry

Parameter ``[in]``:
    x11 The 11 entry

Parameter ``[in]``:
    x12 The 12 entry

Parameter ``[in]``:
    x20 The 20 entry

Parameter ``[in]``:
    x21 The 21 entry

Parameter ``[in]``:
    x22 The 22 entry)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromScaledOuterProduct =R"doc( Returns a 'rank one' matrix defined as a scale factor
times the 'vector outer product' of two vectors, i.e. as the matrix
{s*U*V^T}

Parameter ``[in]``:
    vectorU The column vector U

Parameter ``[in]``:
    vectorV The row vector V

Parameter ``[in]``:
    scale The scale factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitFromScaleFactors =R"doc( Returns a scaling matrix with respective x, y, and z
scaling factors.

Parameter ``[in]``:
    xscale The x direction scale factor

Parameter ``[in]``:
    yscale The y direction scale factor

Parameter ``[in]``:
    zscale The z direction scale factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_InitIdentity =R"doc( Initialize an identity matrix.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromQuaternion =R"doc(Parameter ``[in]``:
    quat The quaternion, stored as (xyzw))doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromTransposeOf =R"doc( Return (as function value) the transpose of a matrix.

Parameter ``[in]``:
    matrix The input matrix)doc";

static const char * __doc_Bentley_Geom_RotMatrix_From =R"doc( Returns a matrix copying the matrix part of the
trasnform.

Parameter ``[in]``:
    transform The transformation whose matrix part is returned)doc";

static const char * __doc_Bentley_Geom_RotMatrix_RotationFromOriginXY =R"doc( Set this instance matrix to be an orthogonal (rotation)
matrix with column 0 in the direction from the origin to the x point,
column 1 in the plane of the 3 points, directed so the Y point on the
positive side, and column 2 as their cross product.

Parameter ``[in]``:
    origin The reference point

Parameter ``[in]``:
    xPoint The x axis target point

Parameter ``[in]``:
    yPoint The 3rd point defining xy plane.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_From1Vector =R"doc( Initializes this instance matrix so that the indicated
axis (axis = 0,1,or 2) is aligned with the vector dir. The normalize
flag selects between normalized axes (all matrix columns of unit
length) and unnormalized axes (all matrix columns of same length as
the dir vector).

Parameter ``[in]``:
    dir The fixed direction vector

Parameter ``[in]``:
    axis The axis column to be aligned with direction

Parameter ``[in]``:
    normalize true to have normalized columns

Returns:
    true if the direction vector is nonzero.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromPrincipleAxisRotations =R"doc( Returns the product{RX*RY*RZ*M} where RX, RY, and RZ are
rotations (in radians) around X, Y, and Z axes, and M is the input
matrix.

Parameter ``[in]``:
    inMatrix The prior matrix

Parameter ``[in]``:
    xrot The x axis rotation

Parameter ``[in]``:
    yrot The y axis rotation

Parameter ``[in]``:
    zrot The z axis rotation)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromDirectionAndScale =R"doc( Returns a matrix which scales along a vector direction.

Parameter ``[in]``:
    vector The scaling direction

Parameter ``[in]``:
    scale The scale factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromRotate90 =R"doc(Return a matrix for retation of 90 degrees about a vector.)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromAxisAndRotationAngle =R"doc( Returns a matrix of rotation about the x,y, or z axis
(indicated by axis = 0,1, or 2) by an angle in radians.

Parameter ``[in]``:
    axis The axis index 0=x, 1=y, 2=z

Parameter ``[in]``:
    radians The rotation angle in radians)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromVectorAndRotationAngle =R"doc( Returns a matrix representing rotation around a vector.

Parameter ``[in]``:
    axis The axis of rotation

Parameter ``[in]``:
    radians The rotation angle)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromRowVectors =R"doc( Returns a matrix with 3 vectors copied to respective
rows.

Parameter ``[in]``:
    vectorU The vector to insert in row 0

Parameter ``[in]``:
    vectorV The vector to insert in row 1

Parameter ``[in]``:
    vectorW The vector to insert in row 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromColumnVectors =R"doc( Returns a matrix with 3 vectors copied to respective
columns.

Parameter ``[in]``:
    vectorU The vector to insert in column 0

Parameter ``[in]``:
    vectorV The vector to insert in column 1

Parameter ``[in]``:
    vectorW The vector to insert in column 2)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromRowValues =R"doc( Returns a matrix with the 9 specified coefficients given
in " row major " order.

Parameter ``[in]``:
    x00 The 00 entry

Parameter ``[in]``:
    x01 The 01 entry

Parameter ``[in]``:
    x02 The 02 entry

Parameter ``[in]``:
    x10 The 10 entry

Parameter ``[in]``:
    x11 The 11 entry

Parameter ``[in]``:
    x12 The 12 entry

Parameter ``[in]``:
    x20 The 20 entry

Parameter ``[in]``:
    x21 The 21 entry

Parameter ``[in]``:
    x22 The 22 entry)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromScaledOuterProduct =R"doc( Returns a 'rank one' matrix defined as a scale factor
times the 'vector outer product' of two vectors, i.e. as the matrix
{s*U*V^T}

Parameter ``[in]``:
    vectorU The column vector U

Parameter ``[in]``:
    vectorV The row vector V

Parameter ``[in]``:
    scale The scale factor)doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromScaleFactors =R"doc( Returns a scaling matrix with respective x, y, and z
scaling factors.

Parameter ``[in]``:
    xscale The x direction scale factor (00 diagonal)

Parameter ``[in]``:
    yscale The y direction scale factor (11 diagonal)

Parameter ``[in]``:
    zscale The z direction scale factor (22 diagonal))doc";

static const char * __doc_Bentley_Geom_RotMatrix_FromScale =R"doc( Returns a uniform scaling matrix.

Parameter ``[in]``:
    scale The scale factor.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_RotMatrix(py::module_& m)
    {
    //===================================================================================
    // struct RotMatrix
    py::class_<RotMatrix> c1(m, "RotMatrix");
    bind_ValidatedValue<RotMatrix>(m, "ValidatedRotMatrix", py::module_local(false));
    py::bind_vector< bvector<RotMatrix> >(m, "RotMatrixArray", py::module_local(false));

    c1.def(py::init(&RotMatrix::FromIdentity));

    c1.def(py::self * DVec3d());
    c1.def(py::self * py::self);
    c1.def(py::self * Transform());

    c1.def_property("form3d",
        [](RotMatrix& self) {return py::array_t<T_Adouble>{{3,3}, self.form3d[0], py::cast(self)};},
        [](RotMatrix& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (9 != arr.size())
            return;

        memcpy(self.form3d[0], ptr, 9 * sizeof(T_Adouble));
        });

    c1.def_static("FromScale", &RotMatrix::FromScale, "scale"_a, DOC(Bentley, Geom, RotMatrix, FromScale));
    c1.def_static("FromScaleFactors", &RotMatrix::FromScaleFactors, "xscale"_a, "yscale"_a, "zscale"_a, DOC(Bentley, Geom, RotMatrix, FromScaleFactors));
    c1.def_static("FromScaledOuterProduct", &RotMatrix::FromScaledOuterProduct, "vectorU"_a, "vectorV"_a, "scale"_a, DOC(Bentley, Geom, RotMatrix, FromScaledOuterProduct));
    c1.def_static("FromRowValues", &RotMatrix::FromRowValues,
                  "x00"_a, "x01"_a, "x02"_a,
                  "x10"_a, "x11"_a, "x12"_a,
                  "x20"_a, "x21"_a, "x22"_a, DOC(Bentley, Geom, RotMatrix, FromRowValues));
    c1.def_static("FromColumnVectors", &RotMatrix::FromColumnVectors, "vectorU"_a, "vectorV"_a, "vectorW"_a, DOC(Bentley, Geom, RotMatrix, FromColumnVectors));
    c1.def_static("FromRowVectors", &RotMatrix::FromRowVectors, "vectorU"_a, "vectorV"_a, "vectorW"_a, DOC(Bentley, Geom, RotMatrix, FromRowVectors));
    c1.def_static("FromVectorAndRotationAngle", py::overload_cast<DVec3dCR, double>(&RotMatrix::FromVectorAndRotationAngle), "axis"_a, "radians"_a, DOC(Bentley, Geom, RotMatrix, FromVectorAndRotationAngle));
    c1.def_static("FromVectorAndRotationAngle", py::overload_cast<DVec3dCR, double, RotMatrixR>(&RotMatrix::FromVectorAndRotationAngle), "axis"_a, "radians"_a, "deriviativeMatrix"_a, DOC(Bentley, Geom, RotMatrix, FromVectorAndRotationAngle));
    c1.def_static("FromAxisAndRotationAngle", &RotMatrix::FromAxisAndRotationAngle, "axis"_a, "radians"_a, DOC(Bentley, Geom, RotMatrix, FromAxisAndRotationAngle));
    c1.def_static("FromRotate90", &RotMatrix::FromRotate90, "axis"_a, DOC(Bentley, Geom, RotMatrix, FromRotate90));
    c1.def_static("FromDirectionAndScale", &RotMatrix::FromDirectionAndScale, "vector"_a, "scale"_a, DOC(Bentley, Geom, RotMatrix, FromDirectionAndScale));
    c1.def_static("FromPrincipleAxisRotations", &RotMatrix::FromPrincipleAxisRotations, "inMatrix"_a, "xrot"_a, "yrot"_a, "zrot"_a, DOC(Bentley, Geom, RotMatrix, FromPrincipleAxisRotations));
    c1.def_static("From1Vector", &RotMatrix::From1Vector, "dir"_a, "axis"_a, "normalize"_a, DOC(Bentley, Geom, RotMatrix, From1Vector));
    c1.def_static("From2Vector", &RotMatrix::From2Vectors, "xVector"_a, "yVector"_a);
    c1.def_static("RotationFromOriginXY", &RotMatrix::RotationFromOriginXY, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, RotMatrix, RotationFromOriginXY));
    c1.def_static("From", &RotMatrix::From, "transform"_a, DOC(Bentley, Geom, RotMatrix, From));
    c1.def_static("FromTransposeOf", &RotMatrix::FromTransposeOf, "matrix"_a, DOC(Bentley, Geom, RotMatrix, FromTransposeOf));
    c1.def_static("FromQuaternion", py::overload_cast<DPoint4dCR>(&RotMatrix::FromQuaternion), "quat"_a, DOC(Bentley, Geom, RotMatrix, FromQuaternion));    

    c1.def("InitIdentity", &RotMatrix::InitIdentity, DOC(Bentley, Geom, RotMatrix, InitIdentity));
    c1.def("InitFromScale", &RotMatrix::InitFromScale, "scale_a");
    c1.def("InitFromScaleFactors", &RotMatrix::InitFromScaleFactors, "xscale"_a, "yscale"_a, "zscale"_a, DOC(Bentley, Geom, RotMatrix, InitFromScaleFactors));
    c1.def("InitFromScaledOuterProduct", &RotMatrix::InitFromScaledOuterProduct, "vectorU"_a, "vectorV"_a, "scale"_a, DOC(Bentley, Geom, RotMatrix, InitFromScaledOuterProduct));
    c1.def("InitFromRowValues", &RotMatrix::InitFromRowValues,
                  "x00"_a, "x01"_a, "x02"_a,
                  "x10"_a, "x11"_a, "x12"_a,
                  "x20"_a, "x21"_a, "x22"_a, DOC(Bentley, Geom, RotMatrix, InitFromRowValues));
    c1.def("InitFromRowValuesXY", py::overload_cast<double, double, double, double>(&RotMatrix::InitFromRowValuesXY), "x00"_a, "x01"_a, "x10"_a, "x11"_a, DOC(Bentley, Geom, RotMatrix, InitFromRowValuesXY));
    c1.def("InitFromRowValuesXY", [] (RotMatrixR self, std::array<double, 4> const& value) { self.InitFromRowValuesXY(value.data()); }, "value"_a);
    c1.def("InitFromColumnVectors", &RotMatrix::InitFromColumnVectors, "vectorU"_a, "vectorV"_a, "vectorW"_a, DOC(Bentley, Geom, RotMatrix, InitFromColumnVectors));
    c1.def("InitFromRowVectors", &RotMatrix::InitFromRowVectors, "vectorU"_a, "vectorV"_a, "vectorW"_a, DOC(Bentley, Geom, RotMatrix, InitFromRowVectors));
    c1.def("InitFromVectorAndRotationAngle", py::overload_cast<DVec3dCR, double>(&RotMatrix::InitFromVectorAndRotationAngle), "axis"_a, "radians"_a);
    c1.def("InitFromAxisAndRotationAngle", &RotMatrix::InitFromAxisAndRotationAngle, "axis"_a, "radians"_a, DOC(Bentley, Geom, RotMatrix, InitFromAxisAndRotationAngle));
    c1.def("InitFromDirectionAndScale", &RotMatrix::InitFromDirectionAndScale, "vector"_a, "scale"_a, DOC(Bentley, Geom, RotMatrix, InitFromDirectionAndScale));
    c1.def("InitFromPrincipleAxisRotations", &RotMatrix::InitFromPrincipleAxisRotations, "inMatrix"_a, "xrot"_a, "yrot"_a, "zrot"_a, DOC(Bentley, Geom, RotMatrix, InitFromPrincipleAxisRotations));
    c1.def("InitFrom1Vector", &RotMatrix::InitFrom1Vector, "dir"_a, "axis"_a, "normalize"_a, DOC(Bentley, Geom, RotMatrix, InitFrom1Vector));
    c1.def("InitFrom2Vector", &RotMatrix::InitFrom2Vectors, "xVector"_a, "yVector"_a);
    c1.def("InitRotationFromOriginXY", &RotMatrix::InitRotationFromOriginXY, "origin"_a, "xPoint"_a, "yPoint"_a, DOC(Bentley, Geom, RotMatrix, InitRotationFromOriginXY));
    c1.def("InitFrom", &RotMatrix::InitFrom, "transform"_a, DOC(Bentley, Geom, RotMatrix, InitFrom));
    c1.def("InitFromQuaternion", py::overload_cast<DPoint4dCR>(&RotMatrix::InitFromQuaternion), "quat"_a, DOC(Bentley, Geom, RotMatrix, InitFromQuaternion));
    c1.def("InitFromQuaternion", [] (RotMatrixR self, std::array<double, 4> const& wxyzQuat) { self.InitFromQuaternion(wxyzQuat.data()); }, "wxyzQuat"_a);

    c1.def("ScaleRows", &RotMatrix::ScaleRows, "inMatrix"_a, "xScale"_a, "yScale"_a, "zScale"_a, DOC(Bentley, Geom, RotMatrix, ScaleRows));
    c1.def("ScaleColumns", py::overload_cast<RotMatrixCR, double, double, double>(&RotMatrix::ScaleColumns), "inMatrix"_a, "xScale"_a, "yScale"_a, "zScale"_a, DOC(Bentley, Geom, RotMatrix, ScaleColumns));
    c1.def("ScaleColumns", py::overload_cast<double, double, double>(&RotMatrix::ScaleColumns), "xScale"_a, "yScale"_a, "zScale"_a, DOC(Bentley, Geom, RotMatrix, ScaleColumns));
        
    c1.def("NormalizeRowsOf", &RotMatrix::NormalizeColumnsOf, "inMatrix"_a, "scaleVector"_a, DOC(Bentley, Geom, RotMatrix, NormalizeRowsOf));
    c1.def("NormalizeColumnsOf", &RotMatrix::NormalizeColumnsOf, "inMatrix"_a, "scaleVector"_a, DOC(Bentley, Geom, RotMatrix, NormalizeColumnsOf));

    c1.def("Scale", &RotMatrix::Scale, "leftMatrix"_a, "xs"_a, "ys"_a, "zs"_a, "rightMatrix"_a, DOC(Bentley, Geom, RotMatrix, Scale));
    c1.def("AddScaledOuterProductInPlace", &RotMatrix::AddScaledOuterProductInPlace, "vectorU"_a, "vectorV"_a, "scale"_a, DOC(Bentley, Geom, RotMatrix, AddScaledOuterProductInPlace));
    c1.def("ShuffleColumnsOf", &RotMatrix::ShuffleColumnsOf, "inMatrix"_a, "i0"_a, "i1"_a, "i2"_a, DOC(Bentley, Geom, RotMatrix, ShuffleColumnsOf));

    c1.def("InitRotationFromVectorToVector", &RotMatrix::InitRotationFromVectorToVector, "startVector"_a, "endVector"_a, DOC(Bentley, Geom, RotMatrix, InitRotationFromVectorToVector));        
    
    c1.def("SquareAndNormalizeColumns", 
           py::overload_cast<RotMatrixCR, int, int>(&RotMatrix::SquareAndNormalizeColumns),
           "inMatrix"_a, "primaryAxis"_a, "secondaryAxis"_a, DOC(Bentley, Geom, RotMatrix, SquareAndNormalizeColumns));

    c1.def("SquareAndNormalizeColumns",
           py::overload_cast<RotMatrixCR, int, int, int>(&RotMatrix::SquareAndNormalizeColumns),
           "inMatrix"_a, "primaryAxis"_a, "secondaryAxis"_a, "preferredOrientation"_a, DOC(Bentley, Geom, RotMatrix, SquareAndNormalizeColumns));

    c1.def("SquareAndNormalizeColumnsAnyOrder",
           py::overload_cast<RotMatrixCR, int>(&RotMatrix::SquareAndNormalizeColumnsAnyOrder),
           "inMatrix"_a, "preferredOrientation"_a, DOC(Bentley, Geom, RotMatrix, SquareAndNormalizeColumnsAnyOrder));

    c1.def("SquareAndNormalizeColumnsAnyOrder", py::overload_cast<RotMatrixCR>(&RotMatrix::SquareAndNormalizeColumnsAnyOrder), "inMatrix"_a, DOC(Bentley, Geom, RotMatrix, SquareAndNormalizeColumnsAnyOrder));
    c1.def("Copy", &RotMatrix::Copy, DOC(Bentley, Geom, RotMatrix, Copy));

    c1.def("InitProduct", 
           py::overload_cast<RotMatrixCR, RotMatrixCR>(&RotMatrix::InitProduct), 
           "rotMatrixA"_a, "rotMatrixB"_a, DOC(Bentley, Geom, RotMatrix, InitProduct));

    c1.def("InitProduct",
           py::overload_cast<RotMatrixCR, RotMatrixCR, RotMatrixCR>(&RotMatrix::InitProduct),
           "rotMatrixA"_a, "rotMatrixB"_a, "rotMatrixC"_a, DOC(Bentley, Geom, RotMatrix, InitProduct));

    c1.def("InitProduct",
           py::overload_cast<RotMatrixCR, TransformCR>(&RotMatrix::InitProduct),
           "rotMatrixA"_a, "transformB"_a, DOC(Bentley, Geom, RotMatrix, InitProduct));

    c1.def("InitProduct",
           py::overload_cast<TransformCR, RotMatrixCR>(&RotMatrix::InitProduct),
           "transformA"_a, "rotMatrixB"_a, DOC(Bentley, Geom, RotMatrix, InitProduct));

    c1.def("InitProductRotMatrixTransposeRotMatrix", &RotMatrix::InitProductRotMatrixTransposeRotMatrix, "rotMatrixA"_a, "rotMatrixB"_a, DOC(Bentley, Geom, RotMatrix, InitProductRotMatrixTransposeRotMatrix));
    c1.def("InitProductRotMatrixRotMatrixTranspose", &RotMatrix::InitProductRotMatrixRotMatrixTranspose, "rotMatrixA"_a, "rotMatrixB"_a, DOC(Bentley, Geom, RotMatrix, InitProductRotMatrixRotMatrixTranspose));
    c1.def("TransposeOf", &RotMatrix::TransposeOf, "matrix"_a, DOC(Bentley, Geom, RotMatrix, TransposeOf));
    c1.def("Transpose", &RotMatrix::Transpose, DOC(Bentley, Geom, RotMatrix, Transpose));
    c1.def("SumOf", &RotMatrix::SumOf, "matrix0"_a, "matrix1"_a, "scale1"_a, "matrix2"_a, "scale2"_a, DOC(Bentley, Geom, RotMatrix, SumOf));
    c1.def("Add", &RotMatrix::Add, "delta"_a, DOC(Bentley, Geom, RotMatrix, Add));
    c1.def("Subtract", &RotMatrix::Subtract, "delta"_a, DOC(Bentley, Geom, RotMatrix, Subtract));

    c1.def("InverseOf", &RotMatrix::InverseOf, "forward"_a, DOC(Bentley, Geom, RotMatrix, InverseOf));
    c1.def("Invert", &RotMatrix::Invert, DOC(Bentley, Geom, RotMatrix, Invert));

    c1.def("Multiply",
           py::overload_cast<DRange3dR, DRange3dCR>(&RotMatrix::Multiply, py::const_),
           "outRange"_a, "inRange"_a, DOC(Bentley, Geom, RotMatrix, Multiply));

    c1.def("Multiply",
           py::overload_cast<DPoint3dR>(&RotMatrix::Multiply, py::const_),
           "point"_a, DOC(Bentley, Geom, RotMatrix, Multiply));

    c1.def("Multiply",
           py::overload_cast<DPoint3dR, DPoint3dCR>(&RotMatrix::Multiply, py::const_),
           "result"_a, "point"_a, DOC(Bentley, Geom, RotMatrix, Multiply));

    c1.def("Multiply",
           py::overload_cast<DPoint4dArray&, DPoint4dArray const&>(&RotMatrix::Multiply, py::const_),
           "xyzwOut"_a, "xyzwIn"_a, DOC(Bentley, Geom, RotMatrix, Multiply));

    c1.def("Multiply",
           py::overload_cast<DPoint3dArray&, DPoint3dArray const&>(&RotMatrix::Multiply, py::const_),
           "xyzOut"_a, "xyzIn"_a, DOC(Bentley, Geom, RotMatrix, Multiply));

    c1.def("Multiply",
           py::overload_cast<DPoint2dArray&, DPoint2dArray const&>(&RotMatrix::Multiply, py::const_),
           "xyOut"_a, "xyIn"_a, DOC(Bentley, Geom, RotMatrix, Multiply));
        
    c1.def("MultiplyTranspose", py::overload_cast<DPoint3dR, DPoint3dCR>(&RotMatrix::MultiplyTranspose, py::const_), "result"_a, "point"_a, DOC(Bentley, Geom, RotMatrix, MultiplyTranspose));
    c1.def("MultiplyTranspose", py::overload_cast<DPoint3dR>(&RotMatrix::MultiplyTranspose, py::const_), "point"_a, DOC(Bentley, Geom, RotMatrix, MultiplyTranspose));
    c1.def("MultiplyTranspose", py::overload_cast<DPoint3dArray&, DPoint3dArray const&>(&RotMatrix::MultiplyTranspose, py::const_), "outXYZ"_a, "inXYZ"_a, DOC(Bentley, Geom, RotMatrix, MultiplyTranspose));

    c1.def("MultiplyComponents", &RotMatrix::MultiplyComponents, "result"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, RotMatrix, MultiplyComponents));
    c1.def("MultiplyTransposeComponents", &RotMatrix::MultiplyTransposeComponents, "result"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, RotMatrix, MultiplyTransposeComponents));
        
    c1.def("SolveArray", py::overload_cast<DPoint3dArray&, DPoint3dArray const&>(&RotMatrix::SolveArray, py::const_), "xyzOut"_a, "xyzIn"_a, DOC(Bentley, Geom, RotMatrix, SolveArray));    

    c1.def("Solve", &RotMatrix::Solve, "result"_a, "point"_a, DOC(Bentley, Geom, RotMatrix, Solve));
    c1.def("SolveTranspose", &RotMatrix::SolveTranspose, "result"_a, "point"_a, DOC(Bentley, Geom, RotMatrix, SolveTranspose));

    c1.def("GetColumns", &RotMatrix::GetColumns, "vectorU"_a, "vectorV"_a, "vectorW"_a, DOC(Bentley, Geom, RotMatrix, GetColumns));
    c1.def("GetRows", &RotMatrix::GetRows, "vectorU"_a, "vectorV"_a, "vectorW"_a, DOC(Bentley, Geom, RotMatrix, GetRows));
    c1.def("GetColumn", &RotMatrix::GetColumn, "vector"_a, "col"_a, DOC(Bentley, Geom, RotMatrix, GetColumn));
    c1.def("GetRow", &RotMatrix::GetRow, "vector"_a, "row"_a, DOC(Bentley, Geom, RotMatrix, GetRow));
    c1.def("SetColumn", &RotMatrix::SetColumn, "vector"_a, "col"_a, DOC(Bentley, Geom, RotMatrix, SetColumn));
    c1.def("SetRow", &RotMatrix::SetRow, "vector"_a, "row"_a, DOC(Bentley, Geom, RotMatrix, SetRow));

    c1.def("GetComponentByRowAndColumn", &RotMatrix::GetComponentByRowAndColumn, "row"_a, "col"_a, DOC(Bentley, Geom, RotMatrix, GetComponentByRowAndColumn));

    c1.def("GetRowValues", [] (RotMatrixCR self)
           {
           std::array<double, 9> v;
           self.GetRowValues(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8]);
           return v;
           }, DOC(Bentley, Geom, RotMatrix, GetRowValues));

    c1.def("GetRowValuesXY", [] (RotMatrixCR self, DoubleArray& data)
           {
           if (data.size() < 4)
               data.resize(4);
           self.GetRowValuesXY(data.data());
           }, DOC(Bentley, Geom, RotMatrix, GetRowValuesXY));

    c1.def("Determinant", &RotMatrix::Determinant, DOC(Bentley, Geom, RotMatrix, Determinant));
    c1.def("ConditionNumber", &RotMatrix::ConditionNumber, DOC(Bentley, Geom, RotMatrix, ConditionNumber));
    c1.def("IsIdentity", py::overload_cast<>(&RotMatrix::IsIdentity, py::const_), DOC(Bentley, Geom, RotMatrix, IsIdentity));
    c1.def("IsDiagonal", &RotMatrix::IsDiagonal, DOC(Bentley, Geom, RotMatrix, IsDiagonal));

    c1.def("IsUniformScale", [] (RotMatrixCR self)
           {
           double maxScale = 0;
           bool bOk = self.IsUniformScale(maxScale);
           return py::make_tuple(bOk, maxScale);
           }, DOC(Bentley, Geom, RotMatrix, IsUniformScale));

    c1.def("DiagonalSignedRange", [] (RotMatrixCR self)
           {
           double minVal, maxVal;
           self.DiagonalSignedRange(minVal, maxVal);
           return py::make_tuple(minVal, maxVal);
           }, DOC(Bentley, Geom, RotMatrix, DiagonalSignedRange));

    c1.def("DiagonalAbsRange", [] (RotMatrixCR self)
           {
           double minVal, maxVal;
           self.DiagonalAbsRange(minVal, maxVal);
           return py::make_tuple(minVal, maxVal);
           }, DOC(Bentley, Geom, RotMatrix, DiagonalAbsRange));

    c1.def("OffDiagonalSignedRange", [] (RotMatrixCR self)
           {
           double minVal, maxVal;
           self.OffDiagonalSignedRange(minVal, maxVal);
           return py::make_tuple(minVal, maxVal);
           }, DOC(Bentley, Geom, RotMatrix, OffDiagonalSignedRange));

    c1.def("OffDiagonalAbsRange", [] (RotMatrixCR self)
           {
           double minVal, maxVal;
           self.OffDiagonalAbsRange(minVal, maxVal);
           return py::make_tuple(minVal, maxVal);
           }, DOC(Bentley, Geom, RotMatrix, OffDiagonalAbsRange));

    c1.def("LowerTriangleAbsRange", &RotMatrix::LowerTriangleAbsRange, DOC(Bentley, Geom, RotMatrix, LowerTriangleAbsRange));
    c1.def("UpperTriangleAbsRange", &RotMatrix::UpperTriangleAbsRange, DOC(Bentley, Geom, RotMatrix, UpperTriangleAbsRange));
    c1.def("DiagonalAbsRange", py::overload_cast<>(&RotMatrix::DiagonalAbsRange), DOC(Bentley, Geom, RotMatrix, DiagonalAbsRange));
    c1.def("LowerTriangleMaxAbs", &RotMatrix::LowerTriangleMaxAbs, DOC(Bentley, Geom, RotMatrix, LowerTriangleMaxAbs));
    c1.def("UpperTriangleMaxAbs", &RotMatrix::UpperTriangleMaxAbs, DOC(Bentley, Geom, RotMatrix, UpperTriangleMaxAbs));
    c1.def("DiagonalMaxAbs", &RotMatrix::DiagonalMaxAbs, DOC(Bentley, Geom, RotMatrix, DiagonalMaxAbs));
    c1.def("SumSquares", &RotMatrix::SumSquares, DOC(Bentley, Geom, RotMatrix, SumSquares));
    c1.def("MaxAbs", &RotMatrix::MaxAbs, DOC(Bentley, Geom, RotMatrix, MaxAbs));
    c1.def("MaxDiff", &RotMatrix::MaxDiff, "matrix2"_a, DOC(Bentley, Geom, RotMatrix, MaxDiff));
    c1.def("SumDiagonalSquares", &RotMatrix::SumDiagonalSquares, DOC(Bentley, Geom, RotMatrix, SumDiagonalSquares));
    c1.def("SumOffDiagonalSquares", &RotMatrix::SumOffDiagonalSquares, DOC(Bentley, Geom, RotMatrix, SumOffDiagonalSquares));
    c1.def("IsSignedPermutation", &RotMatrix::IsSignedPermutation, DOC(Bentley, Geom, RotMatrix, IsSignedPermutation));
    c1.def("IsNearSignedPermutation", &RotMatrix::IsNearSignedPermutation, "result"_a, "tolerance"_a, DOC(Bentley, Geom, RotMatrix, IsNearSignedPermutation));
    c1.def("IsRigid", &RotMatrix::IsRigid, DOC(Bentley, Geom, RotMatrix, IsRigid));
    c1.def("IsOrthogonal", &RotMatrix::IsOrthogonal, DOC(Bentley, Geom, RotMatrix, IsOrthogonal));

    c1.def("IsOrthonormal", [] (RotMatrixCR self, RotMatrixR columns, DVec3dR axisScales)
           {
           double axisRatio = 0;
           bool bOk = self.IsOrthonormal(columns, axisScales, axisRatio);
           return py::make_tuple(bOk, axisRatio);
           }, DOC(Bentley, Geom, RotMatrix, IsOrthonormal));

    c1.def("IsRigidScale", [] (RotMatrixCR self, RotMatrixR columns)
           {
           double scale = 0;
           bool bOk = self.IsRigidScale(columns, scale);
           return py::make_tuple(bOk, scale);
           }, DOC(Bentley, Geom, RotMatrix, IsRigidScale));

    c1.def("IsNearRigidScale", &RotMatrix::IsNearRigidScale, "dest"_a, "primaryAxis"_a = 0, "tolerance"_a = 1.0e-6, DOC(Bentley, Geom, RotMatrix, IsNearRigidScale));
    c1.def("IsPlanar", &RotMatrix::IsPlanar, "normal"_a, DOC(Bentley, Geom, RotMatrix, IsPlanar));
    c1.def("IsEqual", py::overload_cast<RotMatrixCR>(&RotMatrix::IsEqual, py::const_), "maxtrix2"_a, DOC(Bentley, Geom, RotMatrix, IsEqual));
    c1.def("IsEqual", py::overload_cast<RotMatrixCR, double>(&RotMatrix::IsEqual, py::const_), "maxtrix2"_a, "tolerance"_a, DOC(Bentley, Geom, RotMatrix, IsEqual));

    c1.def("FactorRotateScaleRotate", &RotMatrix::FactorRotateScaleRotate, "rotation1"_a, "scalePoint"_a, "rotation2"_a, DOC(Bentley, Geom, RotMatrix, FactorRotateScaleRotate));
    c1.def("RotateAndSkewFactors", &RotMatrix::RotateAndSkewFactors, "rotation"_a, "skewFactor"_a = 0, "primiaryAxis"_a, "secondaryAxis"_a, DOC(Bentley, Geom, RotMatrix, RotateAndSkewFactors));
    c1.def("FactorOrthogonalColumns", &RotMatrix::FactorOrthogonalColumns, "matrixB"_a, "maxtrixV"_a, DOC(Bentley, Geom, RotMatrix, FactorOrthogonalColumns));

    c1.def("InitTransposedFromQuaternionWXYZ", &RotMatrix::InitTransposedFromQuaternionWXYZ, "wxyzQuat"_a, DOC(Bentley, Geom, RotMatrix, InitTransposedFromQuaternionWXYZ));
    c1.def("GetQuaternion", py::overload_cast<DPoint4dR, bool>(&RotMatrix::GetQuaternion, py::const_), "quat"_a, "transpose"_a, DOC(Bentley, Geom, RotMatrix, GetQuaternion));   
    
    c1.def("GetQuaternion", [] (RotMatrixCR self, DoubleArray& wxyzQuat, bool transpose)
           {
           if (wxyzQuat.size() < 4)
               wxyzQuat.resize(4);               
           self.GetQuaternion(wxyzQuat.data(), transpose);
           }, "wxyzQuat"_a, "transpose"_a, DOC(Bentley, Geom, RotMatrix, GetQuaternion));

    c1.def("GetRotationAngleAndVector", &RotMatrix::GetRotationAngleAndVector, "axis"_a, DOC(Bentley, Geom, RotMatrix, GetRotationAngleAndVector));
    c1.def("ColumnXAngleXY", &RotMatrix::ColumnXAngleXY, DOC(Bentley, Geom, RotMatrix, ColumnXAngleXY));
    c1.def("GivensRowOp", &RotMatrix::GivensRowOp, "c"_a, "s"_a, "i0"_a, "i1"_a, DOC(Bentley, Geom, RotMatrix, GivensRowOp));
    c1.def("GivensColumnOp", &RotMatrix::GivensColumnOp, "c"_a, "s"_a, "i0"_a, "i1"_a, DOC(Bentley, Geom, RotMatrix, GivensColumnOp));
    c1.def("HyperbolicRowOp", &RotMatrix::HyperbolicRowOp, "secant"_a, "tangent"_a, "i0"_a, "i1"_a, DOC(Bentley, Geom, RotMatrix, HyperbolicRowOp));
    c1.def("HyperbolicColumnOp", &RotMatrix::HyperbolicColumnOp, "secant"_a, "tangent"_a, "i0"_a, "i1"_a, DOC(Bentley, Geom, RotMatrix, HyperbolicColumnOp));

    c1.def("__repr__", [] (RotMatrix& self)
           {
           return "[{}, {}, {};\n{}, {}, {};\n{}, {}, {}]"_s
               .format(self.form3d[0][0], self.form3d[0][1], self.form3d[0][2],
                       self.form3d[1][0], self.form3d[1][1], self.form3d[1][2],
                       self.form3d[2][0], self.form3d[2][1], self.form3d[2][2]);
           });

    c1.def("__copy__", [](const RotMatrix& self)
        {
        return RotMatrix(self);
        });
    }