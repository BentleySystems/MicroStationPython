/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dpoint4d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DPoint4d_TryNormalizePointAndDerivatives =R"doc(Return point and vectors that are the cartesian image of a homoegneous
point and derivatives ul> li>The return is marked invalid if weight is
zero. ul>

Returns:
    origin and vectors after normalization.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_InitDisconnect =R"doc(Initialize a point with all coordinates as the disconnect value.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_IsDisconnect =R"doc(Returns:
    true if the point has coordinates which indicate it is a
    disconnect (separator) ponit.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_GetRotationAngleAndVectorFromQuaternion =R"doc(Returns the angle of rotation represented by this instance quaternion
and sets axis to be the normalized vector about which this instance
rotates. The instance is assumed to be a normalized quaternion, i.e.
of the form (x,y,z,w) where

x*x + y*y + z*z + w*w = 1.

The angle is returned within the closed interval [0,Pi].

Parameter ``[out]``:
    axis normalized axis of rotation

Returns:
    rotation angle (in radians) between 0 and Pi, inclusive)doc";

static const char * __doc_Bentley_Geom_DPoint4d_MaxUnnormalizedXYZDiff =R"doc(Returns:
    largest absoluted value among xyz coordinates coordinates,
    ignoring weight.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_MaxAbsUnnormalizedXYZ =R"doc(Returns:
    largest absoluted value among xyz coordinates, ignoring weight.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_MaxAbs =R"doc(Returns:
    largest absoluted value among point coordinates.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_AlmostEqualReversed =R"doc(test for nearly equal points in two arrays, reversing the second)doc";

static const char * __doc_Bentley_Geom_DPoint4d_AlmostEqual =R"doc(test for nearly equal points in two arrays)doc";

static const char * __doc_Bentley_Geom_DPoint4d_IsEqual =R"doc(Exact equality test between points. (Also see method with same name
but added tolerance argument.)

Parameter ``[in]``:
    vec2 vector

Returns:
    true if the points are identical. (DPoint4dCR, double))doc";

static const char * __doc_Bentley_Geom_DPoint4d_Negate =R"doc(Negate a point.

Parameter ``[in]``:
    point input point)doc";

static const char * __doc_Bentley_Geom_DPoint4d_Scale =R"doc(sets pOutVec to pInVec*scale.

Parameter ``[in]``:
    point input vector

Parameter ``[in]``:
    scale scale)doc";

static const char * __doc_Bentley_Geom_DPoint4d_NormalizePlaneOf =R"doc(Normalizes a homogeneous plane (by dividing through by the vector
magnitude).

Parameter ``[in]``:
    plane0 homogeneous plane

Returns:
    true unless normal is zero vector.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_NormalizeWeightInPlace =R"doc(Divide through by weight component.

Returns:
    true if normalization succeeded)doc";

static const char * __doc_Bentley_Geom_DPoint4d_InitWithNormalizedWeight =R"doc(Initializes the instance by normalizing the weight of the source.

Returns:
    true if normalization succeeded)doc";

static const char * __doc_Bentley_Geom_DPoint4d_GetProjectedXYZ =R"doc(Normalizes a homogeneous point (by dividing by w part.)

Parameter ``[out]``:
    rPoint normalized point

Returns:
    true if normalization succeeded)doc";

static const char * __doc_Bentley_Geom_DPoint4d_SumOf =R"doc(Adds two homogeneous points.

Parameter ``[in]``:
    pt1 point 1

Parameter ``[in]``:
    pt2 point 2)doc";

static const char * __doc_Bentley_Geom_DPoint4d_DifferenceOf =R"doc(Subtract second point from first.

Parameter ``[in]``:
    point1 first point

Parameter ``[in]``:
    point2 second point)doc";

static const char * __doc_Bentley_Geom_DPoint4d_Subtract =R"doc(Subtract a vector from the instance.

Parameter ``[in]``:
    vector vector to subtract)doc";

static const char * __doc_Bentley_Geom_DPoint4d_Add =R"doc(Add a vector to the instance.

Parameter ``[in]``:
    vector vector to add)doc";

static const char * __doc_Bentley_Geom_DPoint4d_WeightedDifferenceOf =R"doc(Scale each point by the other's weight and return the difference)doc";

static const char * __doc_Bentley_Geom_DPoint4d_OriginAndNormalFromPlane =R"doc(Parameter ``[out]``:
    origin cartesian orign

Parameter ``[out]``:
    normal cartesian normal

Returns:
    true if)doc";

static const char * __doc_Bentley_Geom_DPoint4d_PlaneFromOriginAndVectors =R"doc(Computes the homogeneous coordinate vector for a plane defined by a
DPoint4d origin and a pair of 3D vectors.

Parameter ``[out]``:
    origin a point on the plane.

Parameter ``[out]``:
    vector0 a vector in the plane.

Parameter ``[out]``:
    vector1 another vector in the plane.

Returns:
    false if origin, vectors are not independent.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_PlaneFrom3Points =R"doc(Computes the homogeneous coordinate vector for a plane defined by 3 3D
points.

Parameter ``[out]``:
    origin origin point

Parameter ``[out]``:
    point1 another point on plane

Parameter ``[out]``:
    point2 another point on plane

Returns:
    true if normal is well defined.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_PlaneFromOriginAndNormal =R"doc(Computes the homogeneous vector for a plane defined by 3D origin and
normal. NOTE If the normal vector is null, a 0000 vector is returned.

Parameter ``[out]``:
    origin origin point

Parameter ``[out]``:
    normal normal vector

Returns:
    true unless normal is null)doc";

static const char * __doc_Bentley_Geom_DPoint4d_GetXYW =R"doc(Copy the xyw components out of a homogeneous point. The z component
not referenced. This is a copy, not a normalization.

Parameter ``[out]``:
    point xyw parts copied to xyz)doc";

static const char * __doc_Bentley_Geom_DPoint4d_GetXYZ =R"doc(Copy the xyz components out of a homogeneous point. The weight is not
referenced, i.e. the xyz components are NOT normalized.

Parameter ``[out]``:
    point cartesian point)doc";

static const char * __doc_Bentley_Geom_DPoint4d_InitFrom =R"doc(Initializ a homogeneous point from a 3D point and separate weight.
NOTE The xyz components copied unchanged, i.e. not multiplied by the
weight.

Parameter ``[in]``:
    point cartesian point

Parameter ``[in]``:
    w weight component)doc";

static const char * __doc_Bentley_Geom_DPoint4d_FromInterpolate =R"doc(Interpolates between two homogeneous vectors. |

Parameter ``[in]``:
    point0 s=0 point

Parameter ``[in]``:
    s interpolation parameter

Parameter ``[in]``:
    point1 s=1 point

Returns:
    interpolated point)doc";

static const char * __doc_Bentley_Geom_DPoint4d_Interpolate =R"doc(Interpolates between two homogeneous vectors. |

Parameter ``[in]``:
    point0 s=0 point

Parameter ``[in]``:
    s interpolation parameter

Parameter ``[in]``:
    point1 s=1 point)doc";

static const char * __doc_Bentley_Geom_DPoint4d_RealDistanceSquared =R"doc(Parameter ``[out]``:
    pDistanceSquared squared distance

Parameter ``[in]``:
    vec2 second point

Returns:
    true iff the homogeneous point was properly normalized.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_RealDistanceXY =R"doc(Parameter ``[out]``:
    distance distance between xy parts

Parameter ``[in]``:
    pointB other point.

Returns:
    true iff the homogeneous points could be normalized)doc";

static const char * __doc_Bentley_Geom_DPoint4d_RealDistanceSquaredXY =R"doc(Parameter ``[out]``:
    pDistanceSquared squared distance

Parameter ``[in]``:
    vec2 second point

Returns:
    true iff the homogeneous point was properly normalized.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_RealDistance =R"doc(Parameter ``[in]``:
    vec2 second point

Returns:
    distance between projections of two homnogeneous points.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_EyePlaneTest =R"doc(Return the dot product of a plane normal and a vector 'to the
eyepoint'. The plane is given as cartesian origin and normal; the eye
is given as homogeneous point, i.e. weight zero for flat view, nonzero
for perspective. Eyepoints constucted 'by hand' usually look like
this:Flat view " from infinity " looking in direction (xyz):eyepoint =
(x,y,z,0) i.e. a top view has eyepoint (0,0,1,0) Perspective from
eyepoint at (x,y,z):eyepoint (x,y,z,1) When viewing is constructed by
a sequence of homogeneous transformations, with the final (device)
projection to the xy plane, the (pretransform) eyepoint is 'by
definition' Tinverse * (0,0,1,0)' i.e column 2 (zero based) of the
composite viewing transform. (Note that the weight part can be
nonzero.)

Parameter ``[in]``:
    origin any cartesian point on plane

Parameter ``[in]``:
    normal cartesian plane normal

Returns:
    dot product of plane normal with vector towards eye.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_DotProductXYW =R"doc(Return the xyz dot product of two homogeneous points, i.e. ignore z.

Parameter ``[in]``:
    point second second

Returns:
    dot product of two homogeneous points.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_DotProductXYZ =R"doc(Return the xyz dot product of two homogeneous points, i.e. ignore w.

Parameter ``[in]``:
    point2 second point of dot product.

Returns:
    dot product of two homogeneous points.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_DotProductXY =R"doc(Return the dot product of only the xy parts of two homogeneous points.
Ignore z, ignore w.

Parameter ``[in]``:
    point second point

Returns:
    dot product of two homogeneous points.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_DotProduct =R"doc(Return the full 4d (xyzw) dot product of two homogeneous points.

Parameter ``[in]``:
    point second point of dot product.

Returns:
    dot product of two homogeneous points.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_MagnitudeXYZW =R"doc(magnitude as pure 4d point -- sqrt sum of squares.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_GetComponent =R"doc(Parameter ``[in]``:
    index 0=x, 1=y, 2=z, 3=w, others cyclic

Returns:
    specified component of the point or vector)doc";

static const char * __doc_Bentley_Geom_DPoint4d_SetComponent =R"doc(Set x,y,z or w component of a point.

Parameter ``[in]``:
    a component value

Parameter ``[in]``:
    index 0=x, 1=y, 2=z, 3=w, others cyclic)doc";

static const char * __doc_Bentley_Geom_DPoint4d_GetComponents =R"doc(Copies component data out of this instance into doubles pXCoord,
pYCoord, pZCoord and pWCoord.

Parameter ``[out]``:
    xCoord x component

Parameter ``[out]``:
    yCoord y component

Parameter ``[out]``:
    zCoord z component

Parameter ``[out]``:
    wCoord w component)doc";

static const char * __doc_Bentley_Geom_DPoint4d_Init =R"doc(Fill a DPoint4d, using given xyz components and weight. All components
are copied in directly -- the xyz components are not multiplied by the
weight.

Parameter ``[in]``:
    source xyz components

Parameter ``[in]``:
    w w component)doc";

static const char * __doc_Bentley_Geom_DPoint4d_SetComponents =R"doc(Parameter ``[in]``:
    xComponent x component

Parameter ``[in]``:
    yComponent y component

Parameter ``[in]``:
    zComponent z component

Parameter ``[in]``:
    wComponent w component)doc";

static const char * __doc_Bentley_Geom_DPoint4d_Zero =R"doc(zero out this point.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_FromCrossProduct =R"doc(Return a point " perpendicular " to all 3 inputs.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_FromMultiply =R"doc(Return product of 3d point with (possibly omitted) DMatrix4d

Parameter ``[in]``:
    matrix if missing, identity matrix is implied.

Parameter ``[in]``:
    point 3d point.)doc";

static const char * __doc_Bentley_Geom_DPoint4d_FromSumOf =R"doc(Return point with sum of scaled inputs)doc";

static const char * __doc_Bentley_Geom_DPoint4d_From =R"doc(Return point with direct initialization

Parameter ``[in]``:
    x x coordinate

Parameter ``[in]``:
    y y coordinate

Parameter ``[in]``:
    z z coordinate

Parameter ``[in]``:
    w w coordinate)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DPoint4d(py::module_& m)
    {
    //===================================================================================
    // struct DPoint4d
    py::class_<DPoint4d> c1(m, "DPoint4d");
    py::bind_vector< DPoint4dArray >(m, "DPoint4dArray", py::module_local(false));
    bind_ValidatedValue<DPoint4d>(m, "ValidatedDPoint4d", py::module_local(false));

    c1.def_readwrite("x", &DPoint4d::x);
    c1.def_readwrite("y", &DPoint4d::y);
    c1.def_readwrite("z", &DPoint4d::z);
    c1.def_readwrite("w", &DPoint4d::w);

    c1.def(py::init(py::overload_cast<double, double, double, double>(&DPoint4d::From)), "x"_a, "y"_a, "z"_a, "w"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, double>(&DPoint4d::From)), "xyz"_a, "w"_a);

    c1.def_static("From", py::overload_cast<double, double, double, double>(&DPoint4d::From), "x"_a, "y"_a, "z"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, From));
    c1.def_static("From", py::overload_cast<DPoint3dCR, double>(&DPoint4d::From), "xyz"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, From));        
    c1.def_static("FromSumOf", &DPoint4d::FromSumOf, "xyzw0"_a, "scale0"_a, "xyzw1"_a, "scale1"_a, "xyzw2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint4d, FromSumOf));
        
    c1.def_static("FromMultiply",
                  py::overload_cast<DMatrix4dCP, DPoint3dCR>(&DPoint4d::FromMultiply),
                  "matrix"_a, "point"_a, DOC(Bentley, Geom, DPoint4d, FromMultiply));

    c1.def_static("FromMultiply",
                  py::overload_cast<DMatrix4dCP, DPoint4dCR>(&DPoint4d::FromMultiply),
                  "matrix"_a, "point"_a, DOC(Bentley, Geom, DPoint4d, FromMultiply));

    c1.def_static("FromCrossProduct", &DPoint4d::FromCrossProduct, "pointA"_a, "pointB"_a, "pointC"_a, DOC(Bentley, Geom, DPoint4d, FromCrossProduct));

    c1.def("Zero", &DPoint4d::Zero, DOC(Bentley, Geom, DPoint4d, Zero));

    c1.def("SetComponents", &DPoint4d::SetComponents, "xComponent"_a, "yComponent"_a, "zComponent"_a, "wComponent"_a, DOC(Bentley, Geom, DPoint4d, SetComponents));

    c1.def("Init", py::overload_cast<DPoint3dCR, double>(&DPoint4d::Init), "source"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, Init));
    c1.def("Init", py::overload_cast<double, double, double, double>(&DPoint4d::Init), "x"_a, "y"_a, "z"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, Init));

    c1.def("GetComponents", [] (DPoint4dCR self)
        {
        return py::make_tuple(self.x, self.y, self.z, self.w);
        }, DOC(Bentley, Geom, DPoint4d, GetComponents));

    c1.def("SetComponent", &DPoint4d::SetComponent, "a"_a, "index"_a, DOC(Bentley, Geom, DPoint4d, SetComponent));
    c1.def("GetComponent", &DPoint4d::GetComponent, "index"_a, DOC(Bentley, Geom, DPoint4d, GetComponent));

    c1.def("MagnitudeXYZW", &DPoint4d::MagnitudeXYZW, DOC(Bentley, Geom, DPoint4d, MagnitudeXYZW));

    c1.def("DotProduct", py::overload_cast<DPoint4dCR>(&DPoint4d::DotProduct, py::const_), "point"_a, DOC(Bentley, Geom, DPoint4d, DotProduct));
    c1.def("DotProduct", py::overload_cast<double, double, double, double>(&DPoint4d::DotProduct, py::const_), "x"_a, "y"_a, "z"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, DotProduct));
    c1.def("DotProduct", py::overload_cast<DPoint3dCR, double>(&DPoint4d::DotProduct, py::const_), "point2"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, DotProduct));
    c1.def("DotProductXY", &DPoint4d::DotProductXY, "point"_a, DOC(Bentley, Geom, DPoint4d, DotProductXY));
    c1.def("DotProductXYZ", &DPoint4d::DotProductXYZ, "point"_a, DOC(Bentley, Geom, DPoint4d, DotProductXYZ));
    c1.def("DotProductXYW", &DPoint4d::DotProductXYW, "point"_a, DOC(Bentley, Geom, DPoint4d, DotProductXYW));

    c1.def("EyePlaneTest", &DPoint4d::EyePlaneTest, "origin"_a, "normal"_a, DOC(Bentley, Geom, DPoint4d, EyePlaneTest));
    c1.def("RealDistance", &DPoint4d::RealDistance, "vec2"_a, DOC(Bentley, Geom, DPoint4d, RealDistance));

    c1.def("RealDistanceSquaredXY", [] (DPoint4dCR self, DPoint3dCR vec2)
        {
        double dist2 = 0.0;
        bool bOk = self.RealDistanceSquaredXY(&dist2, vec2);
        return py::make_tuple(bOk, dist2);
        }, "vec2"_a, DOC(Bentley, Geom, DPoint4d, RealDistanceSquaredXY));

    c1.def("RealDistanceXY", [] (DPoint4dCR self, DPoint4dCR pointB)
        {
        double dist2 = 0.0;
        bool bOk = self.RealDistanceXY(dist2, pointB);
        return py::make_tuple(bOk, dist2);
        }, "vec2"_a, DOC(Bentley, Geom, DPoint4d, RealDistanceXY));

    c1.def("RealDistanceSquared", [] (DPoint4dCR self, DPoint3dCR vec2)
        {
        double dist2 = 0.0;
        bool bOk = self.RealDistanceSquared(&dist2, vec2);
        return py::make_tuple(bOk, dist2);
        }, "vec2"_a, DOC(Bentley, Geom, DPoint4d, RealDistanceSquared));

    c1.def("RealDistanceSquared", [] (DPoint4dCR self, DPoint4dCR vec2)
        {
        double dist2 = 0.0;
        bool bOk = self.RealDistanceSquared(&dist2, vec2);
        return py::make_tuple(bOk, dist2);
        }, "vec2"_a, DOC(Bentley, Geom, DPoint4d, RealDistanceSquared));
        
    c1.def("Interpolate", &DPoint4d::Interpolate, "point0"_a, "s"_a, "point1"_a, DOC(Bentley, Geom, DPoint4d, Interpolate));
    c1.def_static("FromInterpolate", &DPoint4d::FromInterpolate, "point0"_a, "s"_a, "point1"_a, DOC(Bentley, Geom, DPoint4d, FromInterpolate));
        
    c1.def("InitFrom", &DPoint4d::InitFrom, "point"_a, "w"_a, DOC(Bentley, Geom, DPoint4d, InitFrom));

    c1.def("GetXYZ", py::overload_cast<DPoint3dR>(&DPoint4d::GetXYZ, py::const_), "point"_a, DOC(Bentley, Geom, DPoint4d, GetXYZ));
    c1.def("GetXYZ", py::overload_cast<DPoint3dR, int, int, int>(&DPoint4d::GetXYZ, py::const_), "point"_a, "xIndex"_a, "yIndex"_a, "zIndex"_a, DOC(Bentley, Geom, DPoint4d, GetXYZ));
    c1.def("GetXYW", &DPoint4d::GetXYW, "point"_a, DOC(Bentley, Geom, DPoint4d, GetXYW));

    c1.def("PlaneFromOriginAndNormal", &DPoint4d::PlaneFromOriginAndNormal, "origin"_a, "normal"_a, DOC(Bentley, Geom, DPoint4d, PlaneFromOriginAndNormal));
    c1.def("PlaneFrom3Points", &DPoint4d::PlaneFrom3Points, "origin"_a, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint4d, PlaneFrom3Points));
    c1.def("PlaneFromOriginAndVectors", &DPoint4d::PlaneFromOriginAndVectors, "origin"_a, "vector0"_a, "vector1"_a, DOC(Bentley, Geom, DPoint4d, PlaneFromOriginAndVectors));
    c1.def("OriginAndNormalFromPlane", &DPoint4d::OriginAndNormalFromPlane, "origin"_a, "normal"_a, DOC(Bentley, Geom, DPoint4d, OriginAndNormalFromPlane));    

    c1.def("WeightedDifferenceOf", py::overload_cast<DPoint4dCR, DPoint4dCR>(&DPoint4d::WeightedDifferenceOf), "A"_a, "B"_a, DOC(Bentley, Geom, DPoint4d, WeightedDifferenceOf));
    c1.def("WeightedDifferenceOf", py::overload_cast<DPoint4dCR, DPoint3dCR, double>(&DPoint4d::WeightedDifferenceOf), "A"_a, "B"_a, "wB"_a, DOC(Bentley, Geom, DPoint4d, WeightedDifferenceOf));
    c1.def("WeightedDifferenceOf", py::overload_cast<DPoint3dCR, double, DPoint4dCR>(&DPoint4d::WeightedDifferenceOf), "A"_a, "wA"_a, "B"_a, DOC(Bentley, Geom, DPoint4d, WeightedDifferenceOf));
        
    c1.def("Add", &DPoint4d::Add, "vector"_a, DOC(Bentley, Geom, DPoint4d, Add));
    c1.def("Subtract", &DPoint4d::Subtract, "vector"_a, DOC(Bentley, Geom, DPoint4d, Subtract));
    c1.def("DifferenceOf", &DPoint4d::DifferenceOf, "point1"_a, "point2"_a, DOC(Bentley, Geom, DPoint4d, DifferenceOf));

    c1.def("SumOf", 
           py::overload_cast<DPoint4dCR, DPoint4dCR>(&DPoint4d::SumOf), 
           "pt1"_a, "pt2"_a, DOC(Bentley, Geom, DPoint4d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint4dCR, DPoint4dCR, double>(&DPoint4d::SumOf),
           "point0"_a, "point1"_a, "scale1"_a, DOC(Bentley, Geom, DPoint4d, SumOf));

    c1.def("SumOf", 
           py::overload_cast<DPoint4dCR, DPoint4dCR, double, DPoint4dCR, double>(&DPoint4d::SumOf), 
           "point0"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint4d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint4dCR, DPoint4dCR, double, DPoint4dCR, double, DPoint4dCR, double>(&DPoint4d::SumOf),
           "point0"_a, "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, "point3"_a, "scale3"_a, DOC(Bentley, Geom, DPoint4d, SumOf));

    c1.def("SumOf", 
           py::overload_cast<DPoint4dCR, double, DPoint4dCR, double>(&DPoint4d::SumOf), 
           "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, DOC(Bentley, Geom, DPoint4d, SumOf));

    c1.def("SumOf",
           py::overload_cast<DPoint4dCR, double, DPoint4dCR, double, DPoint4dCR, double>(&DPoint4d::SumOf),
           "point1"_a, "scale1"_a, "point2"_a, "scale2"_a, "point3"_a, "scale3"_a, DOC(Bentley, Geom, DPoint4d, SumOf));
        
    c1.def("GetProjectedXYZ", &DPoint4d::GetProjectedXYZ, "rPoint"_a, DOC(Bentley, Geom, DPoint4d, GetProjectedXYZ));

    c1.def("InitWithNormalizedWeight", &DPoint4d::InitWithNormalizedWeight, "source"_a, DOC(Bentley, Geom, DPoint4d, InitWithNormalizedWeight));
    c1.def("NormalizeWeightInPlace", &DPoint4d::NormalizeWeightInPlace, DOC(Bentley, Geom, DPoint4d, NormalizeWeightInPlace));
    c1.def("NormalizePlaneOf", &DPoint4d::NormalizePlaneOf, "plane0"_a, DOC(Bentley, Geom, DPoint4d, NormalizePlaneOf));

    c1.def("Scale", py::overload_cast<DPoint4dCR, double>(&DPoint4d::Scale), "point"_a, "scale"_a, DOC(Bentley, Geom, DPoint4d, Scale));
    c1.def("Scale", py::overload_cast<double>(&DPoint4d::Scale), "scale"_a, DOC(Bentley, Geom, DPoint4d, Scale));

    c1.def("Negate", py::overload_cast<DPoint4dCR>(&DPoint4d::Negate), "point"_a, DOC(Bentley, Geom, DPoint4d, Negate));
    c1.def("Negate", py::overload_cast<>(&DPoint4d::Negate), DOC(Bentley, Geom, DPoint4d, Negate));

    c1.def("IsEqual", py::overload_cast<DPoint4dCR>(&DPoint4d::IsEqual, py::const_), "vec2"_a, DOC(Bentley, Geom, DPoint4d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DPoint4dCR, double>(&DPoint4d::IsEqual, py::const_), "vec2"_a, "tolerance"_a, DOC(Bentley, Geom, DPoint4d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DPoint4dCR, double, double>(&DPoint4d::IsEqual, py::const_), "vec2"_a, "xyzTol"_a, "wTol"_a, DOC(Bentley, Geom, DPoint4d, IsEqual));

    c1.def_static("AlmostEqual",
                  py::overload_cast<DPoint4dArray const&, DPoint4dArray const&, double, double>(&DPoint4d::AlmostEqual),
                  "dataA"_a, "dataB"_a, "xyzTol"_a, "wTol"_a, DOC(Bentley, Geom, DPoint4d, AlmostEqual));

    c1.def_static("AlmostEqualReversed",
                  py::overload_cast<DPoint4dArray const&, DPoint4dArray const&, double, double>(&DPoint4d::AlmostEqualReversed),
                  "dataA"_a, "dataB"_a, "xyzTol"_a, "wTol"_a, DOC(Bentley, Geom, DPoint4d, AlmostEqualReversed));    

    c1.def("MaxAbs", &DPoint4d::MaxAbs, DOC(Bentley, Geom, DPoint4d, MaxAbs));
    c1.def("MaxAbsUnnormalizedXYZ", &DPoint4d::MaxAbsUnnormalizedXYZ, DOC(Bentley, Geom, DPoint4d, MaxAbsUnnormalizedXYZ));
    c1.def("MaxUnnormalizedXYZDiff", &DPoint4d::MaxUnnormalizedXYZDiff, "other"_a, DOC(Bentley, Geom, DPoint4d, MaxUnnormalizedXYZDiff));

    c1.def("GetRotationAngleAndVectorFromQuaternion", &DPoint4d::GetRotationAngleAndVectorFromQuaternion, "axis"_a, DOC(Bentley, Geom, DPoint4d, GetRotationAngleAndVectorFromQuaternion));
    c1.def("IsDisconnect", &DPoint4d::IsDisconnect, DOC(Bentley, Geom, DPoint4d, IsDisconnect));
    c1.def("InitDisconnect", &DPoint4d::InitDisconnect, DOC(Bentley, Geom, DPoint4d, InitDisconnect));

    c1.def_static("TryNormalizePointAndDerivatives", &DPoint4d::TryNormalizePointAndDerivatives, "homogeneousPoint"_a, "homogeneousDerivative1"_a, "homogeneousDerivative2"_a, DOC(Bentley, Geom, DPoint4d, TryNormalizePointAndDerivatives));

    c1.def("__repr__", [] (DPoint4dCR self) { return "[{}, {}, {}, {}]"_s.format(self.x, self.y, self.z, self.w); });
    c1.def("__copy__", [] (const DPoint4d& self) { return DPoint4d(self); });
    }