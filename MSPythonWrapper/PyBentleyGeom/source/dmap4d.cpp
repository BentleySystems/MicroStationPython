/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dmap4d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DMap4d_IsIdentity =R"doc(:returns:
    true if the mapping is an identity)doc";

static const char * __doc_Bentley_Geom_DMap4d_Explode =R"doc(Copy various parts of the 4x4 matrix to separate data structures.

:param (output):
    matrix upper 3x3

:param (output):
    translation last column (above diagonal)

:param (output):
    perspective last row (including diagonal)

:param (input):
    inverse false for forward part, true for inverse

Remark:
    The separate pieces do not " mean " much if there is perspective.)doc";

static const char * __doc_Bentley_Geom_DMap4d_IsPerspective =R"doc(Test if a transform is perspective.

:returns:
    true if the mapping contains perspective.)doc";

static const char * __doc_Bentley_Geom_DMap4d_IsAffine =R"doc(Test if a transform is affiine.

:returns:
    true if the mapping is affine.)doc";

static const char * __doc_Bentley_Geom_DMap4d_IsSingular =R"doc(Test if a transform is singular

:returns:
    true if the mapping is singular)doc";

static const char * __doc_Bentley_Geom_DMap4d_IsIndependent =R"doc(Checks if the mapping is strictly a scale/translate in specified
directions.

:param (input):
    xChange 1 if x may change, 0 if it must stay fixed

:param (input):
    yChange 1 if y may change, 0 if it must stay fixed

:param (input):
    zChange 1 if z may change, 0 if it must stay fixed

:returns:
    true if independence tests are satisfied.)doc";

static const char * __doc_Bentley_Geom_DMap4d_InitProduct =R"doc(Multiply transforms

:param (input):
    A transform A

:param (input):
    B transform B)doc";

static const char * __doc_Bentley_Geom_DMap4d_SandwichOfBinverseAB =R"doc(Form the product Binv * A * B

:param (input):
    A inside term of sandwich

:param (input):
    B outer term of sandwich)doc";

static const char * __doc_Bentley_Geom_DMap4d_SandwichOfBABinverse =R"doc(Form the product B * A * BInv A NULL for B or C skips that part.

:param (input):
    A inside term of sandwich

:param (input):
    B outer term of sandwich)doc";

static const char * __doc_Bentley_Geom_DMap4d_SandwichOf =R"doc(Form the product C * Binv * A * B * Cinv

:param (input):
    A inside term of sandwich

:param (input):
    B middle term of sandwich

:param (input):
    C outer term of sandwich)doc";

static const char * __doc_Bentley_Geom_DMap4d_InverseOf =R"doc(Sets pA to the inverse of B.

:param (input):
    B original mapping)doc";

static const char * __doc_Bentley_Geom_DMap4d_ZFrustum =R"doc(:param (input):
    z0 reference z. Normalized projective coordinate is 0 at this z

:param (input):
    zetaHalf controls rate of growth of normalized projective z.
    Projective z at z0/k is k-1*zetahalf, i.e. is zetahalf at z0/2)doc";

static const char * __doc_Bentley_Geom_DMap4d_InitFromSkewBox =R"doc(Fill a mapping between a unit prism and homogeneous skew space.
Example use:We want to map a unit rectangle from font space to
screen, under a full perspective mapping. That is, given font space
point (x,y) we want A * (x,y,0,1)^T = the visible pixel. Also, given
pixel (i,j) we want Ainverse * (i,j,0,1) to map back into font space.
A long time ago, we were told points P0,P1,P2 which are the
preperspective points that correspond to font space (0,0), (1,0), and
(0,1). Since then, P00, P10, P01 have been through a homogeneous
transformation. (For instance, there may be 'weight' of other than 1
on each one.) The transformed (homogeneous) points are Q00, Q10, Q01
In device space, we do a projection in the z direction. Hence we need
a 4th point Qz=(0,0,1,0). Build this matrix by calling
jmdlDMap4d_fillHomogeneousSkewFrame (pHMap, Q00, Q10,Q01,Qz)

:param point0001:
    0001 in the unit space maps here

:param point1001:
    1001 in the unit space maps here

:param point0101:
    0100 in the unit space maps here

:param point0010:
    0010 in the unit space maps here

:returns:
    true if the 4 points are independent)doc";

static const char * __doc_Bentley_Geom_DMap4d_InitFromTransform =R"doc(:param (input):
    transform affine transformation 3x4 matrix

:param (input):
    invert true to treat this matrix as the inverse of the mapping,
    false if forward.

:returns:
    true if the Transfrom was invertible.)doc";

static const char * __doc_Bentley_Geom_DMap4d_InitFromTaper =R"doc(Initialize a transform with perspective entries for a (nonzero) taper
in the z direction.

:param (input):
    taper taper fraction

:returns:
    true if an invertible map was constructed.)doc";

static const char * __doc_Bentley_Geom_DMap4d_InitFromRanges =R"doc(Initialize a transform which translates and scales along principle
axes so box loAP..hiAP maps to box loBP..hiBP

:param (input):
    loAP corner of box A

:param (input):
    hiAP diagonally opposite corner of box A

:param (input):
    loBP corner of box B

:param (input):
    hiBP diagonally opposite corner of box B

:returns:
    int)doc";

static const char * __doc_Bentley_Geom_DMap4d_InitFrom =R"doc(Direct initialization from matrices. Caller is responsible for correct
inverse relationship.

:param (input):
    forwardMatrix " forward " matrix.

:param (input):
    inverseMatrix " inverse " matrix.)doc";

static const char * __doc_Bentley_Geom_DMap4d_FromTranslation =R"doc(Initialize a translation transform.

:param (input):
    tx x component of translation

:param (input):
    ty y component of translation

:param (input):
    tz z component of translation)doc";

static const char * __doc_Bentley_Geom_DMap4d_FromPrincipleProjection =R"doc(Initialize a transform that is a (noninvertible) projection to a
principle plane.

:param (input):
    height distance of plane from origin

:param (input):
    axis 0,1,2 for x,y,z normal)doc";

static const char * __doc_Bentley_Geom_DMap4d_FromScale =R"doc(Initialize a pure scaling transformation. If any scale factor is zero,
the corresponding inverse entry is also zero.

:param (input):
    ax x scale factor

:param (input):
    ay y scale factor

:param (input):
    az z scale factor)doc";

static const char * __doc_Bentley_Geom_DMap4d_FromQuadrantRotation =R"doc(Rotate about vx,yv,vz by an integer multiple of 90 degrees. Providing
the angle as an integer allows exact table lookup without
approximation of pi.

:param (input):
    multiple rotation angle is multiple * 90 degrees

:param (input):
    vx x component of rotation axis

:param (input):
    vy y component of rotation axis

:param (input):
    vz z component of rotation axis)doc";

static const char * __doc_Bentley_Geom_DMap4d_FromRotation =R"doc(Initialize a rotation about axis vx,vy,vz by angle whose cosine and
sine are (proportional to) c and s.

:param (input):
    c cosine of angle

:param (input):
    s sine of angle

:param (input):
    vx x component of rotation axis

:param (input):
    vy y component of rotation axis

:param (input):
    vz z component of rotation axis)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DMap4d(py::module_& m)
    {
    //===================================================================================
    // struct DMap4d
    py::class_<DMap4d> c1(m, "DMap4d");

    c1.def_readwrite("M0", &DMap4d::M0);
    c1.def_readwrite("M1", &DMap4d::M1);
    c1.def_readwrite("mask", &DMap4d::mask);

    c1.def(py::init(&DMap4d::FromIdentity));
    c1.def(py::init(&DMap4d::From), "forwardMatrix"_a, "inverseMatrix"_a);
    c1.def(py::init(py::overload_cast<double, double, double, double>(&DMap4d::FromRotation)), "radians"_a, "vx"_a, "vy"_a, "vz"_a);
    c1.def_static("FromRotation", py::overload_cast<double, double, double, double, double>(&DMap4d::FromRotation), "c"_a, "s"_a, "vx"_a, "vy"_a, "vz"_a, DOC(Bentley, Geom, DMap4d, FromRotation));
    c1.def_static("FromQuadrantRotation", &DMap4d::FromQuadrantRotation, "multiple"_a, "vx"_a, "vy"_a, "vz"_a, DOC(Bentley, Geom, DMap4d, FromQuadrantRotation));    
    c1.def_static("FromScale", py::overload_cast<double, double, double>(&DMap4d::FromScale), "ax"_a, "ay"_a, "az"_a, DOC(Bentley, Geom, DMap4d, FromScale));
    c1.def_static("FromPrincipleProjection", &DMap4d::FromPrincipleProjection, "height"_a, "axis"_a, DOC(Bentley, Geom, DMap4d, FromPrincipleProjection));
    c1.def_static("FromScale", py::overload_cast<double>(&DMap4d::FromScale), "a"_a, DOC(Bentley, Geom, DMap4d, FromScale));
    c1.def_static("FromTranslation", &DMap4d::FromTranslation, "tx"_a, "ty"_a, "tz"_a, DOC(Bentley, Geom, DMap4d, FromTranslation));

    c1.def("InitFrom", py::overload_cast<DMatrix4dCR, DMatrix4dCR>(&DMap4d::InitFrom), "forwardMatrix"_a, "inverseMatrix"_a, DOC(Bentley, Geom, DMap4d, InitFrom));
    c1.def("InitFromRanges", &DMap4d::InitFromRanges, "loAP"_a, "hiAP"_a, "loBP"_a, "hiBP"_a, DOC(Bentley, Geom, DMap4d, InitFromRanges));
    c1.def("InitFromTaper", &DMap4d::InitFromTaper, "taper"_a, DOC(Bentley, Geom, DMap4d, InitFromTaper));
    c1.def("InitFromTransform", &DMap4d::InitFromTransform, "transform"_a, "invert"_a, DOC(Bentley, Geom, DMap4d, InitFromTransform));
    c1.def("InitFromSkewBox", &DMap4d::InitFromSkewBox, "point0001"_a, "point1001"_a, "point0101"_a, "point0010"_a, DOC(Bentley, Geom, DMap4d, InitFromSkewBox));

    c1.def("ZFrustum", &DMap4d::ZFrustum, "z0"_a, "zetaHalf"_a, DOC(Bentley, Geom, DMap4d, ZFrustum));
    c1.def("InverseOf", &DMap4d::InverseOf, "B"_a, DOC(Bentley, Geom, DMap4d, InverseOf));
    c1.def("SandwichOf", &DMap4d::SandwichOf, "A"_a, "B"_a, "C"_a, DOC(Bentley, Geom, DMap4d, SandwichOf));
    c1.def("SandwichOfBABinverse", &DMap4d::SandwichOfBABinverse, "A"_a, "B"_a, DOC(Bentley, Geom, DMap4d, SandwichOfBABinverse));
    c1.def("SandwichOfBinverseAB", &DMap4d::SandwichOfBABinverse, "A"_a, "B"_a, DOC(Bentley, Geom, DMap4d, SandwichOfBinverseAB));

    c1.def("InitProduct", py::overload_cast<DMap4dCR, DMap4dCR>(&DMap4d::InitProduct), "A"_a, "B"_a, DOC(Bentley, Geom, DMap4d, InitProduct));
    c1.def("InitProduct", py::overload_cast<DMap4dCR, bool, DMap4dCR, bool>(&DMap4d::InitProduct), "A"_a, "invertA"_a, "B"_a, "invertB"_a, DOC(Bentley, Geom, DMap4d, InitProduct));

    c1.def("IsIndependent", &DMap4d::IsIndependent, "xChange"_a, "yChange"_a, "zChange"_a, DOC(Bentley, Geom, DMap4d, IsIndependent));
    c1.def("IsSingular", &DMap4d::IsSingular, DOC(Bentley, Geom, DMap4d, IsSingular));
    c1.def("IsAffine", &DMap4d::IsAffine, DOC(Bentley, Geom, DMap4d, IsAffine));
    c1.def("IsPerspective", &DMap4d::IsPerspective, DOC(Bentley, Geom, DMap4d, IsPerspective));
    c1.def("Explode", &DMap4d::Explode, "matrix"_a, "translation"_a, "perspective"_a, "inverse"_a, DOC(Bentley, Geom, DMap4d, Explode));
    c1.def("IsIdentity", &DMap4d::IsIdentity, DOC(Bentley, Geom, DMap4d, IsIdentity));

    c1.def("__repr__", [] (DMap4d& self)
           {
           return "(M0:{}, M1:{}, mask:{})"_s.format(self.M0, self.M1, self.mask);
           });

    c1.def("__copy__", [](const DMap4d& self)
        {
        return DMap4d(self);
        });
    }