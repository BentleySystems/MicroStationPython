/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dmatrix4d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Pybind11/numpy.h>



static const char * __doc_Bentley_Geom_DMatrix4d_ApproximateNullVectorForUpperTriangle =R"doc(Approximate solution of A*X=0, i.e. find an approximate null vector; A
is assumed upper triangular. Method:Find the smallest diagonal. Set
that entry in X to 1. Backsolve the linear system with RHS 0 and the
chosen X component fixed.

:param (output):
    nullVector approximate null space vector.

:param (output):
    residual estimate of error in A*X. (Squared residual.))doc";

static const char * __doc_Bentley_Geom_DMatrix4d_IsAffine =R"doc(Tests if the instance has 0001 final row, within tolerance.

:returns:
    true if matrix is approximately affine.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_IsIdentity =R"doc(Tests if pInstance is an identity transform and returns the bool
indicator. The matrix is considered an identity if the sum of squared
components after subtracting 1 from the diagonals is less than a small
tolerance

:returns:
    true if matrix is approximately an identity.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MaxAbsDiff =R"doc(Compute max absolute difference between various parts of matrices.

:param (input):
    other matrix to compare to.

:param (output):
    matrixDiff difference in matrix part.

:param (output):
    colDiff difference in final column XYZ part

:param (output):
    rowDiff difference in final row XYZ part

:param (output):
    weightDiff difference in final diagonal entry

:returns:
    max absolute difference)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MaxAbs =R"doc(Search the matrix for the entry with the largest absolute value.

:returns:
    max absolute value entry in the matrix.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_GetBlocks =R"doc(Return matrix, final row, final column, and scalar parts

:param (output):
    products upper 3x3 part

:param (output):
    row xyz parts of final row

:param (output):
    column xyz parts of final column

:param (output):
    scalar ww entry.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_SweepMomentProducts =R"doc(Return the product matrix resulting from sweeping geometry with given
baseProducts;

:param (input):
    baseProducts products integrated on base curve or area.

:param (input):
    sweepVector vector for sweep (extrusion)

:returns:
    products for integration over swept body.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_ConvertInertiaProductsToPrincipalWireMoments =R"doc(Input matrix contains products of inertia{[xx,xy,xz,x; xy yy yz y; xz
yz zz z; x y z v]}. returned values are centroid, principal directions
and 2nd moment tensor entries (yy+zz,xx+zz,xx+yy)

:param (input):
    localToWorld transformation from local coordinate system (where
    the products were computed) to world

:param (output):
    length length

:param (output):
    centroid center of mass

:param (output):
    axes columns of this matrix are the principal x,y,z directions.

:param (output):
    momentTensorDiagonal tensor entries (inertias for rotation around
    each axis))doc";

static const char * __doc_Bentley_Geom_DMatrix4d_ConvertInertiaProductsToPrincipalAreaMoments =R"doc(Input matrix contains products of inertia{[xx,xy,xz,x; xy yy yz y; xz
yz zz z; x y z v]}. returned values are centroid, principal directions
and 2nd moment tensor entries (yy+zz,xx+zz,xx+yy)

:param (input):
    localToWorld transformation from local coordinate system (where
    the products were computed) to world

:param (output):
    area area

:param (output):
    centroid center of mass

:param (output):
    axes columns of this matrix are the principal x,y,z directions.

:param (output):
    momentTensorDiagonal tensor entries (inertias for rotation around
    each axis))doc";

static const char * __doc_Bentley_Geom_DMatrix4d_ConvertInertiaProductsToPrincipalMoments =R"doc(Input matrix contains products of inertia{[xx,xy,xz,x; xy yy yz y; xz
yz zz z; x y z v]}. returned values are centroid, principal directions
and 2nd moment tensor entries (yy+zz,xx+zz,xx+yy)

:param (output):
    volume volume

:param (output):
    centroid center of mass

:param (output):
    axes columns of this matrix are the principal x,y,z directions.

:param (output):
    momentTensorDiagonal tensor entries (inertias for rotation around
    each axis))doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromSandwichProduct =R"doc(Return{A = T * B * Tt * s} where T is an affine transform (expanded
to 4x4 with 0001 final row), B is a DMatrix4d, and s is a scale
factor.

This is used to do change of basis when entries in B are xx,xy,xz,x
moments etc, T is the (possibly non-uniform) transformation, and s is
a scale factor for changing the integration domain. (If the
integrations were volume integrals, s is the determinant of the
orientation part of T. If the integrations were area integrals in a
plane, s is the jacobian of the plane-to-plane transformation.)

:param (input):
    transform transform to apply

:param (input):
    momentMatrix matrix{B}

:param (input):
    scaleFactor)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitSymmetricProduct =R"doc(Compute A = Bt * D * B where B is a matrix and D is a diagonal matrix
given as a vector. REMARK:This is a Very Bad Thing for numerical
purposes. Are you sure you can't get your result without forming this
product?

:param (input):
    sigma entries of diagonal matrix D

:param (input):
    B matrix B)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_Subtract =R"doc(Subtract a matrix (componentwise) from the instance

:param (input):
    delta matrix to subtract)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_CopyUpperTriangleToLower =R"doc(Copy all 6 values from the upper triangle to mirrored positions in the
lower triangle.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_AddSymmetricScaledOuterProduct =R"doc(Add [xx xy xz x; xy yy yz y; xz yz zz 1; x y z 1] * scale

:param (input):
    xyz x,y,z for products. Implicitly extened to DPoint4d [x,y,z,1]
    for products

:param (input):
    scale scale to apply to all terms.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_Scale =R"doc(Scale in place.

:param (input):
    scaleFactor scale to apply)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_Add =R"doc(Add a matrix (componentwise) to the instance.

:param (input):
    delta matrix to add)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_DifferenceOf =R"doc(Subtract two 4x4 matrices.

:param (input):
    A A matrix of A - B

:param (input):
    B B matrix of A - B)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitProduct =R"doc(Form the product of two 4x4 matrices.

:param (input):
    A first matrix of product A*B

:param (input):
    B second matrix of product A*B)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_PreMultiplyByTranslateAndScale =R"doc(Premultiply matirx A by a matrix with sx,sy,sz,1 on diagonal,
tx,ty,tz,1 in last column

:param (input):
    tx 03 entry (x translate) of mutliplier.

:param (input):
    ty 13 entry (y translate) of multiplier.

:param (input):
    tz 23 entry (z translate) of multiplier.

:param (input):
    sx 00 entry (x scale) of multiplier.

:param (input):
    sy 11 entry (y scale) of multiplier.

:param (input):
    sz 22 entry (z scale) of multiplier.

:param (input):
    matrixA existing matrix)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_GetRows =R"doc(Copy data from a matrix rows to DPoint4d structures.

:param (output):
    row0 row 0 data. May be NULL.

:param (output):
    row1 row 1 data. May be NULL.

:param (output):
    row2 row 2 data. May be NULL.

:param (output):
    row3 row 3 data. May be NULL.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_GetRow =R"doc(Copy data from a matrix row to a DPoint4d structure.

:param (output):
    vec point copied from row

:param (input):
    i index of row 0 <= i<4 whose values are to be set)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_GetColumn =R"doc(Copy data from a matrix column to a DPoint4d structure.

:param (output):
    vec point copied from column

:param (input):
    i index of column 0 <= i<4 whose values are to be set)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_SwapRows =R"doc(Install a DPoint4d in an indicated column of an DMatrix4d.

:param (input):
    i first column index

:param (input):
    j second column index)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_SwapColumns =R"doc(Install a DPoint4d in an indicated column of an DMatrix4d.

:param (input):
    i first column index

:param (input):
    j second column index)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_SetColumn =R"doc(Install r0, r1, r2, r3 in an indicated column of an DMatrix4d.

:param (input):
    i index of column 0 <= i<4 whose values are to be set

:param (input):
    r0 row 0 value

:param (input):
    r1 row 1 value

:param (input):
    r2 row 2 value

:param (input):
    r3 row 3 value)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_SetRow =R"doc(Install c0, c1, c2, c3 in an indicated row of an DMatrix4d.

:param (input):
    i index of row 0 <= i<4 whose values are to be set

:param (input):
    c0 column 0 value

:param (input):
    c1 column 1 value

:param (input):
    c2 column 2 value

:param (input):
    c3 column 3 value)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MultiplyTranspose =R"doc(Multiply the transformed matrix times points. (Equivalent to
multiplying transposed points times the matrix.)

:param (output):
    outPoint Array of homogeneous products A^T *pPoint[i]

:param (input):
    inPoint Array of homogeneous points

:param (input):
    n number of points)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MultiplyAffineVectors =R"doc(Matrix times vector multiplication, assume 0001 4th row and padding 3d
data with 0 weight.

:param (output):
    out Destination array

:param (input):
    in Source array

:param (input):
    n number of vectors)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MultiplyScaleAndTranslate =R"doc(Matrix*point multiplication, using full 4d points but assuming the
matrix is has 3D only scaling and translation.

:param (output):
    outPoint Array of homogeneous products A*pPoint[i]

:param (input):
    inPoint Array of homogeneous points

:param (input):
    n number of points)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MultiplyAffine =R"doc(Matrix*point multiplication, using full 4d points but assuming the
matrix is affine, i.e. assume 0001 4th row.

:param (output):
    outPoint Array of homogeneous products A*pPoint[i]

:param (input):
    inPoint Array of homogeneous points

:param (input):
    n number of points)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MultiplyAndNormalize =R"doc(Multiply an array of points by a matrix, using all components of both
the matrix and the points.

:param (output):
    outPoint Array of products A*inPoint[i] normalized

:param (input):
    inPoint Array of points points

:param (input):
    n number of points)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_MultiplyAndRenormalize =R"doc(Multiply an array of points by a matrix, using all components of both
the matrix and the points.

:param (output):
    outPoint Array of products A*pPoint[i] renormalized

:param (input):
    inPoint Array of points points

:param (input):
    n number of points)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_EvaluateImageGrid =R"doc(Evaluate pA*X for m*n points X arranged in a grid. The homogeneous
coordinates of the i,j point in the grid is (x0 + i, y0 + j, 0, 1) The
returned point grid[i * m + j] is the xy components of the image of
grid poitn ij AFTER normalization.

:param (output):
    grid Array of mXn mapped, normalized points

:param (input):
    x00 grid origin x

:param (input):
    y00 grid origin y

:param (input):
    m number of grid points in x direction

:param (input):
    n number of grid points in y direction

:param (input):
    tol relative tolerance for 0-weight tests. If 0, 1.0e-10 is used *)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_SymmetricEigenvectors =R"doc(Compute eigenvectors, assuming A is symmetric.

:param (output):
    Q orthogonal, unit eigenvectors.

:param (output):
    D corresponding eigenvalues.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_Multiply =R"doc(Matrix multiplication, using all components of both the matrix and the
points.

:param (output):
    outPoint Array of homogeneous products A*inPoint[i]

:param (input):
    inPoint Array of homogeneous points

:param (input):
    n number of points)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_TransposeOf =R"doc(Transpose a 4x4 matrix.

:param (input):
    B original matrix)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitFromRowValues =R"doc(Copies the double values directly into the rows of this instance.

:param (input):
    x00 (0,0) entry of matrix (row, column)

:param (input):
    x01 (0,1) entry

:param (input):
    x02 (0,2) entry

:param (input):
    x03 (0,3) entry

:param (input):
    x10 (1,0) entry of matrix (row, column)

:param (input):
    x11 (1,1) entry

:param (input):
    x12 (1,2) entry

:param (input):
    x13 (1,3) entry

:param (input):
    x20 (2,0) entry of matrix (row, column)

:param (input):
    x21 (2,1) entry

:param (input):
    x22 (2,2) entry

:param (input):
    x23 (2,3) entry

:param (input):
    x30 (3,0) entry of matrix (row, column)

:param (input):
    x31 (3,1) entry

:param (input):
    x32 (3,2) entry

:param (input):
    x33 (3,3) entry)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitFromPerspective =R"doc(Fill a matrix with entries in the perspective row, otherwise an
identity matrix.

:param (input):
    px x component

:param (input):
    py y component

:param (input):
    pz z component)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitFromTranslation =R"doc(Fill a 4x4 matrix with a given translation vector and otherwise an
identity.

:param (input):
    tx x component

:param (input):
    ty y component

:param (input):
    tz z component)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitFrom =R"doc(Copy a RotMatrix into corresponding parts of a 4x4 matrix with 4th row
and column both 0001.

:param (input):
    B 3x3 part to fill)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitFromColumnVectors =R"doc(Fill the affine part using xyz vectors for each column of the basis
part and an xyz vector for the translation

:param (input):
    col0 data for column 0 of leading 3x3 submatrix

:param (input):
    col1 data for column 1 of leading 3x3 submatrix

:param (input):
    col2 data for column 2 of leading 3x3 submatrix

:param (input):
    translation data for translation part of matrix)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitFromScaleAndTranslation =R"doc(Fill the scale and translate entries in an otherwise identity matrix

:param (input):
    scale scale factor for each diagonal of leading 3x3 submatrix

:param (input):
    translation translation vector)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_InitIdentity =R"doc(initialize an identity matrix.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromZero =R"doc(Fill a matrix with zeros.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromPerspective =R"doc(Fill a matrix with entries in the perspective row, otherwise an
identity matrix.

:param (input):
    px x component

:param (input):
    py y component

:param (input):
    pz z component)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromTranslation =R"doc(Fill a 4x4 matrix with a given translation vector and otherwise an
identity.

:param (input):
    tx x component

:param (input):
    ty y component

:param (input):
    tz z component)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_From =R"doc(Copy a RotMatrix into corresponding parts of a 4x4 matrix with 4th row
and column both 0001.

:param (input):
    B 3x3 part to fill)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromColumnVectors =R"doc(Fill the affine part using xyz vectors for each column of the basis
part and an xyz vector for the translation

:param (input):
    col0 data for column 0 of leading 3x3 submatrix

:param (input):
    col1 data for column 1 of leading 3x3 submatrix

:param (input):
    col2 data for column 2 of leading 3x3 submatrix

:param (input):
    translation data for translation part of matrix)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_From101WeightedProduct =R"doc(Promote 3 inputs to 4x4 carrier matrices, with respective scale terms
1,0,1. Return the product of the carriers. (Huh? What is this for? If
a transform is defined as A*F*C, and the derivative part of F is has
nonzero derivative B only for its matrix part, A*B*C is the derivative
4x4 matrix.

:param (input):
    transformA First term. Promoted to 4x4 with final row 0001.

:param (input):
    matrixB Second term. Promoted to 4x4 with final row 0000.

:param (input):
    transformC Third term. Promoted to 4x4 with final row 0001.)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromScaleAndTranslation =R"doc(Fill the scale and translate entries in an otherwise identity matrix

:param (input):
    scale scale factor for each diagonal of leading 3x3 submatrix

:param (input):
    translation translation vector)doc";

static const char * __doc_Bentley_Geom_DMatrix4d_FromRowValues =R"doc(Copies the double values directly into the rows of this instance.

:param (input):
    x00 (0,0) entry of matrix (row, column)

:param (input):
    x01 (0,1) entry

:param (input):
    x02 (0,2) entry

:param (input):
    x03 (0,3) entry

:param (input):
    x10 (1,0) entry of matrix (row, column)

:param (input):
    x11 (1,1) entry

:param (input):
    x12 (1,2) entry

:param (input):
    x13 (1,3) entry

:param (input):
    x20 (2,0) entry of matrix (row, column)

:param (input):
    x21 (2,1) entry

:param (input):
    x22 (2,2) entry

:param (input):
    x23 (2,3) entry

:param (input):
    x30 (3,0) entry of matrix (row, column)

:param (input):
    x31 (3,1) entry

:param (input):
    x32 (3,2) entry

:param (input):
    x33 (3,3) entry)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DMatrix4d(py::module_& m)
    {
    //===================================================================================
    // struct DMatrix4d
    py::class_<DMatrix4d> c1(m, "DMatrix4d");

    c1.def(py::init<>());

    c1.def_property("coff",
        [](DMatrix4d& self) {return py::array_t<T_Adouble>{ {4, 4}, self.coff[0], py::cast(self)}; },
        [](DMatrix4d& self, py::array_t<T_Adouble> const& arr)
        {
        py::buffer_info buf = arr.request();
        auto* ptr = static_cast<T_Adouble*>(buf.ptr);

        if (16 != arr.size())
            return;

        memcpy(self.coff[0], ptr, 16 * sizeof(T_Adouble));
        });

    c1.def_static("FromRowValues", &DMatrix4d::FromRowValues,
                  "x00"_a, "x01"_a, "x02"_a, "x03"_a, "x10"_a, "x11"_a, "x12"_a, "x13"_a, "x20"_a, "x21"_a, "x22"_a, "x23"_a, "x30"_a, "x31"_a, "x32"_a, "x33"_a, DOC(Bentley, Geom, DMatrix4d, FromRowValues));
    c1.def_static("FromScaleAndTranslation", &DMatrix4d::FromScaleAndTranslation, "scale"_a, "translation"_a, DOC(Bentley, Geom, DMatrix4d, FromScaleAndTranslation));
    c1.def_static("From101WeightedProduct", &DMatrix4d::From101WeightedProduct, "transformA"_a, "matrixB"_a, "transformC"_a, DOC(Bentley, Geom, DMatrix4d, From101WeightedProduct));
    c1.def_static("FromColumnVectors", &DMatrix4d::FromColumnVectors, "col0"_a, "col1"_a, "col2"_a, "translation"_a, DOC(Bentley, Geom, DMatrix4d, FromColumnVectors));
    c1.def_static("From", py::overload_cast<RotMatrixCR>(&DMatrix4d::From), "B"_a, DOC(Bentley, Geom, DMatrix4d, From));
    c1.def_static("From", py::overload_cast<TransformCR>(&DMatrix4d::From), "transform"_a, DOC(Bentley, Geom, DMatrix4d, From));
    c1.def_static("FromTranslation", &DMatrix4d::FromTranslation, "tx"_a, "ty"_a, "tz"_a, DOC(Bentley, Geom, DMatrix4d, FromTranslation));
    c1.def_static("FromPerspective", &DMatrix4d::FromPerspective, "px"_a, "py"_a, "pz"_a, DOC(Bentley, Geom, DMatrix4d, FromPerspective));
    c1.def_static("FromZero", &DMatrix4d::FromZero, DOC(Bentley, Geom, DMatrix4d, FromZero));

    c1.def("InitIdentity", &DMatrix4d::InitIdentity, DOC(Bentley, Geom, DMatrix4d, InitIdentity));
    c1.def("InitFromScaleAndTranslation", &DMatrix4d::InitFromScaleAndTranslation, "scale"_a, "translation"_a, DOC(Bentley, Geom, DMatrix4d, InitFromScaleAndTranslation));
    c1.def("InitFromColumnVectors", &DMatrix4d::InitFromColumnVectors, "col0"_a, "col1"_a, "col2"_a, "translation"_a, DOC(Bentley, Geom, DMatrix4d, InitFromColumnVectors));
    c1.def("InitFrom", py::overload_cast<RotMatrixCR>(&DMatrix4d::InitFrom), "B"_a, DOC(Bentley, Geom, DMatrix4d, InitFrom));
    c1.def("InitFrom", py::overload_cast<TransformCR>(&DMatrix4d::InitFrom), "transform"_a, DOC(Bentley, Geom, DMatrix4d, InitFrom));
    c1.def("InitFromTranslation", &DMatrix4d::InitFromTranslation, "tx"_a, "ty"_a, "tz"_a, DOC(Bentley, Geom, DMatrix4d, InitFromTranslation));
    c1.def("InitFromPerspective", &DMatrix4d::InitFromPerspective, "px"_a, "py"_a, "pz"_a, DOC(Bentley, Geom, DMatrix4d, InitFromPerspective));

    c1.def("InitFromRowValues", &DMatrix4d::InitFromRowValues,
           "x00"_a, "x01"_a, "x02"_a, "x03"_a, "x10"_a, "x11"_a, "x12"_a, "x13"_a, "x20"_a, "x21"_a, "x22"_a, "x23"_a, "x30"_a, "x31"_a, "x32"_a, "x33"_a, DOC(Bentley, Geom, DMatrix4d, InitFromRowValues));

    c1.def("TransposeOf", &DMatrix4d::TransposeOf, "B"_a, DOC(Bentley, Geom, DMatrix4d, TransposeOf));

    c1.def("Multiply", [] (DMatrix4dCR self, DPoint4dArray& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));


    c1.def("Multiply", py::overload_cast<DPoint3dCR, double>(&DMatrix4d::Multiply), "xyz"_a, "w"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));

    c1.def("SymmetricEigenvectors", &DMatrix4d::SymmetricEigenvectors, "Q"_a, "D"_a, DOC(Bentley, Geom, DMatrix4d, SymmetricEigenvectors));

    c1.def("Multiply", [] (DMatrix4dCR self, DPoint4dArray& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.Multiply(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));

    c1.def("Multiply", [] (DMatrix4dCR self, GraphicsPointVec& outPoints, GraphicsPointVec const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.Multiply(outPoints.data(), inPoints.data(), inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));

    c1.def("EvaluateImageGrid", [] (DMatrix4dCR self, DPoint2dArray& grid, double x00, double y00, int m, int n, double tol)
        {
        return self.EvaluateImageGrid(grid.data(), x00, y00, m, n, tol);
        }, "grid"_a, "x00"_a, "y00"_a, "m"_a, "n"_a, "tol"_a, DOC(Bentley, Geom, DMatrix4d, EvaluateImageGrid));

    c1.def("MultiplyAndRenormalize", [] (DMatrix4dCR self, DPoint3dArray& outPoints, DPoint3dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyAndRenormalize(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAndRenormalize));

    c1.def("MultiplyAndRenormalize", [] (DMatrix4dCR self, py::list& outPoints, py::list const& inPoints)
        {   
        if (inPoints.empty())
            return;

        CONVERT_PYLIST_TO_NEW_CPPARRAY(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(inPoints, cppInPoints, DPoint3dArray, DPoint3d);
        if (cppOutPoints.size() < cppInPoints.size())
            cppOutPoints.resize(cppInPoints.size());

        self.MultiplyAndRenormalize(cppOutPoints.data(), cppInPoints.data(), (int) cppInPoints.size());
        CONVERT_CPPARRAY_TO_PYLIST(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAndRenormalize));


    c1.def("MultiplyAndRenormalize", py::overload_cast<DPoint3dR, DPoint3dCR>(&DMatrix4d::MultiplyAndRenormalize, py::const_), "outPoint"_a, "inPoint"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAndRenormalize));

    c1.def("MultiplyAndNormalize", [] (DMatrix4dCR self, DPoint3dArray& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyAndNormalize(outPoints.data(), inPoints.data(), (size_t) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAndNormalize));

    c1.def("MultiplyAndNormalize", [] (DMatrix4dCR self, py::list& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        CONVERT_PYLIST_TO_NEW_CPPARRAY(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        if (cppOutPoints.size() < inPoints.size())
            cppOutPoints.resize(inPoints.size());

        self.MultiplyAndNormalize(cppOutPoints.data(), inPoints.data(), (size_t) inPoints.size());
        CONVERT_CPPARRAY_TO_PYLIST(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAndNormalize));

    c1.def("MultiplyAffine", [] (DMatrix4dCR self, DPoint4dArray& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyAffine(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAffine));

    c1.def("MultiplyScaleAndTranslate", [] (DMatrix4dCR self, DPoint4dArray& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyScaleAndTranslate(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyScaleAndTranslate));

    c1.def("MultiplyAffine", [] (DMatrix4dCR self, DPoint3dArray& outPoints, DPoint3dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyAffine(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAffine));
    
    c1.def("MultiplyAffine", [] (DMatrix4dCR self, py::list& outPoints, py::list const& inPoints)
        {
        if (inPoints.empty())
            return;

        CONVERT_PYLIST_TO_NEW_CPPARRAY(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(inPoints, cppInPoints, DPoint3dArray, DPoint3d);
        if (cppOutPoints.size() < cppInPoints.size())
            cppOutPoints.resize(cppInPoints.size());

        self.MultiplyAffine(cppOutPoints.data(), cppInPoints.data(), (int) cppInPoints.size());
        CONVERT_CPPARRAY_TO_PYLIST(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAffine));

    c1.def("MultiplyAffineVectors", [] (DMatrix4dCR self, DPoint3dArray& outPoints, DPoint3dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyAffineVectors(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAffineVectors));

    c1.def("MultiplyAffineVectors", [] (DMatrix4dCR self, py::list& outPoints, py::list const& inPoints)
        {
        if (inPoints.empty())
            return;

        CONVERT_PYLIST_TO_NEW_CPPARRAY(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(inPoints, cppInPoints, DPoint3dArray, DPoint3d);

        if (cppOutPoints.size() < cppInPoints.size())
            cppOutPoints.resize(cppInPoints.size());

        self.MultiplyAffineVectors(cppOutPoints.data(), cppInPoints.data(), (int) cppInPoints.size());
        CONVERT_CPPARRAY_TO_PYLIST(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyAffineVectors));

    c1.def("MultiplyScaleAndTranslate", [] (DMatrix4dCR self, DPoint3dArray& outPoints, DPoint3dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyScaleAndTranslate(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyScaleAndTranslate));

    c1.def("MultiplyScaleAndTranslate", [] (DMatrix4dCR self, py::list& outPoints, py::list const& inPoints)
        {
        if (inPoints.empty())
            return;

        CONVERT_PYLIST_TO_NEW_CPPARRAY(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        CONVERT_PYLIST_TO_NEW_CPPARRAY(inPoints, cppInPoints, DPoint3dArray, DPoint3d);
    
        if (cppOutPoints.size() < cppInPoints.size())
            cppOutPoints.resize(cppInPoints.size());

        self.MultiplyScaleAndTranslate(cppOutPoints.data(), cppInPoints.data(), (int) cppInPoints.size());
        CONVERT_CPPARRAY_TO_PYLIST(outPoints, cppOutPoints, DPoint3dArray, DPoint3d);
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyScaleAndTranslate));

    c1.def("Multiply", [] (DMatrix4dCR self, DPoint4dArray& outPoints, DPoint3dArray const& inPoints, DoubleArray const& weight)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.Multiply(outPoints.data(), inPoints.data(), weight.empty() ? nullptr : weight.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, "weight"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));

    c1.def("Multiply", [] (DMatrix4dCR self, DPoint4dArray& outPoints, py::list const& inPoints, DoubleArray const& weight)
        {
        if (inPoints.empty())
            return;

        CONVERT_PYLIST_TO_NEW_CPPARRAY(inPoints, cppInPoints, DPoint3dArray, DPoint3d);

        if (outPoints.size() < cppInPoints.size())
            outPoints.resize(cppInPoints.size());

        self.Multiply(outPoints.data(), cppInPoints.data(), weight.empty() ? nullptr : weight.data(), (int) cppInPoints.size());
        }, "outPoints"_a, "inPoints"_a, "weight"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));

    c1.def("Multiply", py::overload_cast<DPoint4dR, DPoint4dCR>(&DMatrix4d::Multiply, py::const_), "outPoint"_a, "inPoint"_a, DOC(Bentley, Geom, DMatrix4d, Multiply));

    c1.def("MultiplyTranspose", [] (DMatrix4dCR self, DPoint4dArray& outPoints, DPoint4dArray const& inPoints)
        {
        if (inPoints.empty())
            return;

        if (outPoints.size() < inPoints.size())
            outPoints.resize(inPoints.size());

        self.MultiplyTranspose(outPoints.data(), inPoints.data(), (int) inPoints.size());
        }, "outPoints"_a, "inPoints"_a, DOC(Bentley, Geom, DMatrix4d, MultiplyTranspose));

    c1.def("SetRow", py::overload_cast<int, double, double, double, double>(&DMatrix4d::SetRow), "i"_a, "c0"_a, "c1"_a, "c2"_a, "c3"_a, DOC(Bentley, Geom, DMatrix4d, SetRow));
    c1.def("SetRow", py::overload_cast<int, DPoint4dCR>(&DMatrix4d::SetRow), "i"_a, "data"_a, DOC(Bentley, Geom, DMatrix4d, SetRow));
    c1.def("SetColumn", py::overload_cast<int, double, double, double, double>(&DMatrix4d::SetRow), "i"_a, "r0"_a, "r1"_a, "r2"_a, "r3"_a, DOC(Bentley, Geom, DMatrix4d, SetColumn));
    c1.def("SetColumn", py::overload_cast<int, DPoint4dCR>(&DMatrix4d::SetRow), "i"_a, "point"_a, DOC(Bentley, Geom, DMatrix4d, SetColumn));
    c1.def("SwapColumns", &DMatrix4d::SwapColumns, "i"_a, "j"_a, DOC(Bentley, Geom, DMatrix4d, SwapColumns));
    c1.def("SwapRows", &DMatrix4d::SwapRows, "i"_a, "j"_a, DOC(Bentley, Geom, DMatrix4d, SwapRows));
    c1.def("GetColumn", &DMatrix4d::GetColumn, "vec"_a, "i"_a, DOC(Bentley, Geom, DMatrix4d, GetColumn));
    c1.def("GetRow", &DMatrix4d::GetRow, "vec"_a, "i"_a, DOC(Bentley, Geom, DMatrix4d, GetRow));
    c1.def("GetRows", &DMatrix4d::GetRows, "row0"_a, "row1"_a, "row2"_a, "row3"_a, DOC(Bentley, Geom, DMatrix4d, GetRows));    

    c1.def("PreMultiplyByTranslateAndScale", &DMatrix4d::PreMultiplyByTranslateAndScale, "tx"_a, "ty"_a, "tz"_a, "sx"_a, "sy"_a, "sz"_a, "matrixA"_a, DOC(Bentley, Geom, DMatrix4d, PreMultiplyByTranslateAndScale));
    c1.def("InitProduct", py::overload_cast<DMatrix4dCR, DMatrix4dCR>(&DMatrix4d::InitProduct), "A"_a, "B"_a, DOC(Bentley, Geom, DMatrix4d, InitProduct));
    c1.def("InitProduct", py::overload_cast<DMatrix4dCR, DMatrix4dCR, DMatrix4dCR>(&DMatrix4d::InitProduct), "A"_a, "B"_a, "C"_a, DOC(Bentley, Geom, DMatrix4d, InitProduct));

    c1.def("DifferenceOf", &DMatrix4d::DifferenceOf, "A"_a, "B"_a, DOC(Bentley, Geom, DMatrix4d, DifferenceOf));

    c1.def("Add", py::overload_cast<DMatrix4dCR>(&DMatrix4d::Add), "delta"_a, DOC(Bentley, Geom, DMatrix4d, Add));

    c1.def("Add", py::overload_cast<DMatrix4dCR, double>(&DMatrix4d::Add), "delta"_a, "scaleFactor"_a, DOC(Bentley, Geom, DMatrix4d, Add));

    c1.def("Scale", &DMatrix4d::Scale, "scaleFactor"_a, DOC(Bentley, Geom, DMatrix4d, Scale));

    c1.def("AddSymmetricScaledOuterProduct", py::overload_cast<DPoint3d, double>(&DMatrix4d::AddSymmetricScaledOuterProduct), "xyz"_a, "scale"_a, DOC(Bentley, Geom, DMatrix4d, AddSymmetricScaledOuterProduct));
    c1.def("AddSymmetricScaledOuterProduct", py::overload_cast<DPoint4dCR, double>(&DMatrix4d::AddSymmetricScaledOuterProduct), "xyzw"_a, "scale"_a, DOC(Bentley, Geom, DMatrix4d, AddSymmetricScaledOuterProduct));
    c1.def("AddSymmetricScaledOuterProduct", py::overload_cast<DPoint4dCR, DPoint4dCR, double>(&DMatrix4d::AddSymmetricScaledOuterProduct), "U"_a, "V"_a, "scale"_a, DOC(Bentley, Geom, DMatrix4d, AddSymmetricScaledOuterProduct));

    c1.def("CopyUpperTriangleToLower", &DMatrix4d::CopyUpperTriangleToLower, DOC(Bentley, Geom, DMatrix4d, CopyUpperTriangleToLower));

    c1.def("Subtract", &DMatrix4d::Subtract, "delta"_a, DOC(Bentley, Geom, DMatrix4d, Subtract));

    c1.def("InitSymmetricProduct", &DMatrix4d::InitSymmetricProduct, "sigma"_a, "B"_a, DOC(Bentley, Geom, DMatrix4d, InitSymmetricProduct));

    c1.def_static("FromSandwichProduct", &DMatrix4d::FromSandwichProduct, "transform"_a, "momentMatrix"_a, "scaleFactor"_a, DOC(Bentley, Geom, DMatrix4d, FromSandwichProduct));

    c1.def("ConvertInertiaProductsToPrincipalMoments", [] (DMatrix4dCR self)
        {
        double volume = 0.0;
        DVec3d centroid = DVec3d::FromZero();
        RotMatrix axes = RotMatrix::FromIdentity();
        DVec3d momentTensorDiagonal = DVec3d::FromZero();
        bool bOk = self.ConvertInertiaProductsToPrincipalMoments(volume, centroid, axes, momentTensorDiagonal);
        return py::make_tuple(bOk, volume, centroid, axes, momentTensorDiagonal);
        }, DOC(Bentley, Geom, DMatrix4d, ConvertInertiaProductsToPrincipalMoments));

    c1.def("ConvertInertiaProductsToPrincipalMoments", [] (DMatrix4dCR self, TransformCR localToWorld)
        {
        double volume = 0.0;
        DVec3d centroid = DVec3d::FromZero();
        RotMatrix axes = RotMatrix::FromIdentity();
        DVec3d momentTensorDiagonal = DVec3d::FromZero();
        bool bOk = self.ConvertInertiaProductsToPrincipalMoments(localToWorld, volume, centroid, axes, momentTensorDiagonal);
        return py::make_tuple(bOk, volume, centroid, axes, momentTensorDiagonal);
        }, "localToWorld"_a, DOC(Bentley, Geom, DMatrix4d, ConvertInertiaProductsToPrincipalMoments));

    c1.def("ConvertInertiaProductsToPrincipalAreaMoments", [] (DMatrix4dCR self, TransformCR localToWorld)
        {
        double area = 0.0;
        DVec3d centroid = DVec3d::FromZero();
        RotMatrix axes = RotMatrix::FromIdentity();
        DVec3d momentTensorDiagonal = DVec3d::FromZero();
        bool bOk = self.ConvertInertiaProductsToPrincipalAreaMoments(localToWorld, area, centroid, axes, momentTensorDiagonal);
        return py::make_tuple(bOk, area, centroid, axes, momentTensorDiagonal);
        }, "localToWorld"_a, DOC(Bentley, Geom, DMatrix4d, ConvertInertiaProductsToPrincipalAreaMoments));

    c1.def("ConvertInertiaProductsToPrincipalWireMoments", [] (DMatrix4dCR self, TransformCR localToWorld)
        {
        double length = 0.0;
        DVec3d centroid = DVec3d::FromZero();
        RotMatrix axes = RotMatrix::FromIdentity();
        DVec3d momentTensorDiagonal = DVec3d::FromZero();
        bool bOk = self.ConvertInertiaProductsToPrincipalWireMoments(localToWorld, length, centroid, axes, momentTensorDiagonal);
        return py::make_tuple(bOk, length, centroid, axes, momentTensorDiagonal);
        }, "localToWorld"_a, DOC(Bentley, Geom, DMatrix4d, ConvertInertiaProductsToPrincipalWireMoments));

    c1.def_static("SweepMomentProducts", &DMatrix4d::SweepMomentProducts, "baseProducts"_a, "sweepVector"_a, DOC(Bentley, Geom, DMatrix4d, SweepMomentProducts));

    c1.def("GetBlocks", [] (DMatrix4dCR self)
        {
        RotMatrix products;
        DVec3d row, column;
        double scalar;
        self.GetBlocks(products, row, column, scalar);
        return py::make_tuple(products, row, column, scalar);
        }, DOC(Bentley, Geom, DMatrix4d, GetBlocks));

    //Change the method name to MaxAbsValue to avoid duplication of name.
    c1.def("MaxAbsValue", py::overload_cast<>(&DMatrix4d::MaxAbs, py::const_), DOC(Bentley, Geom, DMatrix4d, MaxAbs));

    c1.def("MaxAbsDiff", [] (DMatrix4dCR self, DMatrix4dCR other)
        {
        double matrixDiff, colDiff, rowDiff, weightDiff;
        double retVal = self.MaxAbsDiff(other, matrixDiff, colDiff, rowDiff, weightDiff);
        return py::make_tuple(retVal, matrixDiff, colDiff, rowDiff, weightDiff);
        }, "other"_a, DOC(Bentley, Geom, DMatrix4d, MaxAbsDiff));

    c1.def("MaxAbs", [] (DMatrix4dCR self)
        {
        double matrixMax, colMax, rowMax, weightAbs;
        double retVal = self.MaxAbs(matrixMax, colMax, rowMax, weightAbs);
        return py::make_tuple(retVal, matrixMax, colMax, rowMax, weightAbs);
        }, DOC(Bentley, Geom, DMatrix4d, MaxAbs));

    c1.def("IsIdentity", &DMatrix4d::IsIdentity, DOC(Bentley, Geom, DMatrix4d, IsIdentity));

    c1.def("IsAffine", &DMatrix4d::IsAffine, DOC(Bentley, Geom, DMatrix4d, IsAffine));

    c1.def("ApproximateNullVectorForUpperTriangle", [] (DMatrix4dCR self)
        {
        DPoint4d nullVector;
        double residual;
        bool retVal = self.ApproximateNullVectorForUpperTriangle(nullVector, residual);
        return py::make_tuple(retVal, nullVector, residual);
        }, DOC(Bentley, Geom, DMatrix4d, ApproximateNullVectorForUpperTriangle));

    c1.def("__repr__", [] (DMatrix4dCR self)
           {
           return "[{}, {}, {}, {};\n{}, {}, {}, {};\n{}, {}, {}, {};\n{}, {}, {}, {}]"_s
               .format(self.coff[0][0], self.coff[0][1], self.coff[0][2], self.coff[0][3],
                       self.coff[1][0], self.coff[1][1], self.coff[1][2], self.coff[1][3],
                       self.coff[2][0], self.coff[2][1], self.coff[2][2], self.coff[2][3],
                       self.coff[3][0], self.coff[3][1], self.coff[3][2], self.coff[3][3]);
           });

    c1.def ("__copy__", [](const DMatrix4d& self) {return DMatrix4d(self); });
    }