/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\drange3d.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"



static const char * __doc_Bentley_Geom_DRange3d_MoveChangesIntersection =R"doc(Test if a modification of the given (instance) range would have a
different touching relationship with outerRange.

Remark:
    This may only be meaningful in context of range tree tests where
    some prior relationship among ranges is known to apply.

Parameter ``[in]``:
    newRange candidate for modified range relationship.

Parameter ``[in]``:
    outerRange containing range

Returns:
    true if touching condition occurs.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IntersectionExtentSquared =R"doc(Compute the intersection of given range with another range and return
the extentSquared of the intersection range.

Parameter ``[in]``:
    range2 second range

Returns:
    extentSquared() for the intersection range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IntersectBounded =R"doc(Compute the intersection of a range cube and a ray.

If there is not a finite intersection, both params are set to 0 and
and the output segment consists of only the start point.

Parameter ``[out]``:
    param0 ray parameter where cube is entered

Parameter ``[out]``:
    param1 ray parameter where cube is left

Parameter ``[out]``:
    clipped clipped segment

Parameter ``[out]``:
    segment line segment to intersect with range cube.

Returns:
    true if non-empty intersection.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IntersectRay =R"doc(Compute the intersection of a range cube and a ray.

If there is not a finite intersection, both params are set to 0 and
and both points to point0.

Parameter ``[out]``:
    param0 ray parameter where cube is entered

Parameter ``[out]``:
    param1 ray parameter where cube is left

Parameter ``[out]``:
    point0 entry point

Parameter ``[out]``:
    point1 exit point

Parameter ``[in]``:
    start start point of ray

Parameter ``[in]``:
    direction direction of ray

Returns:
    true if non-empty intersection.)doc";

static const char * __doc_Bentley_Geom_DRange3d_RestrictToMinMax =R"doc(Returns a range which is the intersection of two ranges. The first
range is treated as a signed range, i.e. decreasing values from low to
high are a nonempty range, and the output will maintain the direction.
In a direction where there is no overlap, instance high and low values
are identical and are at the limit of minMax that is nearer to the
values in range0. (Intended use:range0 is the 'actual' stroking range
of a surface i.e. may go 'backwards'. minMax is the nominal full
surface range, i.e. is known a priori to be 'forwards'. The clipping
restricts unreliable range0 to the nominal surface range pRange1.
range0 and instance may be the same address. minMax must be different.

Parameter ``[in]``:
    range0 range to be restricted

Parameter ``[in]``:
    minMax allowable minmax range. Assumed to have low<high)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsStrictlyContainedXY =R"doc(Test if the given range is a proper subset of outerRange, using only
xy parts

Parameter ``[in]``:
    outerRange outer range

Returns:
    true if the given range is a proper subset of outerRange.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsEqual =R"doc(Test if two ranges are exactly equal.

Parameter ``[in]``:
    range1 second range

Returns:
    true if ranges are identical in all components.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IntersectsWith =R"doc(Test if two ranges have strictly non-null overlap (intersection)

Parameter ``[in]``:
    range2 second range

Returns:
    true if ranges overlap, false if not.)doc";

static const char * __doc_Bentley_Geom_DRange3d_DistanceSquaredTo =R"doc( Compute the smallest distance to the other range. This is
0 if the ranges overlap.

Parameter ``[in]``:
    other second range

Returns:
    distance between range cubes (i.e. edge to edge or vertex to edge))doc";

static const char * __doc_Bentley_Geom_DRange3d_DistanceSquaredOutside =R"doc( Compute the smallest distance squared from xyz to the
range. This is 0 for any point inside the range.

Parameter ``[in]``:
    xyz space point.

Returns:
    distance squared from xyz to closest point of the range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_DistanceOutside =R"doc( Compute the smallest distance from xyz to the range. This
is 0 for any point inside the range.

Parameter ``[in]``:
    xyz space point.

Returns:
    distance from xyz to closest point of the range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsContainedXY =R"doc( Test if a point is contained in a range, using only xy
parts.

Parameter ``[in]``:
    point point to test.

Returns:
    true if the point is in (or on boundary of))doc";

static const char * __doc_Bentley_Geom_DRange3d_IsContained =R"doc( Test if the first range is contained in the second range.

Parameter ``[in]``:
    outerRange candidate outer range.

Returns:
    true if the inner range is a (possibly improper) subset of the
    outer range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_LocalToGlobal =R"doc(Convert fractional coordinates in x,y,z directions to global
coordinates.

Parameter ``[in]``:
    xFraction

Parameter ``[in]``:
    yFraction

Parameter ``[in]``:
    zFraction

Returns:
    interpolated point.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IndexOfMaximalAxis =R"doc(Return the index of the axis with largest absolute range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_GetCornerRange =R"doc(Compute range of dot products of ray.direction with vectors from
ray.origin to corners of the range. (The ray direction is NOT
renormalized on each call)

Parameter ``[in]``:
    ray origin and vector for dot products.)doc";

static const char * __doc_Bentley_Geom_DRange3d_GetComponentDRange1d =R"doc(Extract a single component (x,y,z) as a DRange1d.

Parameter ``[in]``:
    index component index interpretted cyclically.

Returns:
    single component range. Ranges may be null independently.)doc";

static const char * __doc_Bentley_Geom_DRange3d_GetEdges =R"doc(Generates individual DSegment3d for the 12 edges of the box.

Parameter ``[out]``:
    edges array of 12 edges)doc";

static const char * __doc_Bentley_Geom_DRange3d_Get6Planes =R"doc(Generates 6 planes for the faces of the box.

Parameter ``[out]``:
    planes array of 6 planes. (Declared and allocated by caller)

Parameter ``[in]``:
    normalLength scale factor for plane normals. 1.0 is outward unit
    normals, -1.0 is inward unit normals)doc";

static const char * __doc_Bentley_Geom_DRange3d_Get8Corners =R"doc(Generates an 8point box around around a range cube. Point ordering is
maintained from the cube.

Parameter ``[out]``:
    box array of 8 points of the box)doc";

static const char * __doc_Bentley_Geom_DRange3d_LargestCoordinateXY =R"doc(Returns:
    the largest individual XY coordinate value among (a) range min
    point, (b) range max point, and (c) range diagonal vector.)doc";

static const char * __doc_Bentley_Geom_DRange3d_MaxAbs =R"doc(Returns:
    the largest individual coordinate value among range low and high,
    zero if empty range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_LargestCoordinate =R"doc(Returns:
    the largest individual coordinate value among (a) range min point,
    (b) range max point, and (c) range diagonal vector.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsAlmostZeroX =R"doc(Test if x size is small compared to y and z)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsAlmostZeroY =R"doc(Test if y size is small compared to x and z)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsAlmostZeroZ =R"doc(Test if z size is small compared to x and y.)doc";

static const char * __doc_Bentley_Geom_DRange3d_DiagonalVectorXY =R"doc(Returns the XY part of the diagonal vector -- 000 if null range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_DiagonalVector =R"doc(Returns the diagonal vector -- 000 if null range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_DiagonalDistanceXY =R"doc(Returns the length of the xy diagonal -- 0 if null range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_DiagonalDistance =R"doc(Returns the length of the xyz diagonal -- 0 if null range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_ZLength =R"doc(Returns difference of high and low in z direction -- 0 if high<low.)doc";

static const char * __doc_Bentley_Geom_DRange3d_YLength =R"doc(Returns difference of high and low in y direction -- 0 if high<low.)doc";

static const char * __doc_Bentley_Geom_DRange3d_XLength =R"doc(Returns difference of high and low in x direction -- 0 if high<low.)doc";

static const char * __doc_Bentley_Geom_DRange3d_Volume =R"doc(returns product of axis extents. No test for zero or negative axes.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsPoint =R"doc(Returns:
    true if high is exactly equal to low in every direction.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsEmpty =R"doc(Test if low component is (strictly) less than high in any direction.
Note that equal components do not indicate empty. returns true if any
low component is less than the corresponding high component)doc";

static const char * __doc_Bentley_Geom_DRange3d_ExtentSquared =R"doc( returns 0 if the range is null (Range3dIsNull), otherwise
sum of squared axis extents.

Returns:
    squared magnitude of the diagonal vector.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IsNull =R"doc( Check if the range is exactly the same as the null ranges
of a just-initialized range.

Returns:
    true if the range is null.)doc";

static const char * __doc_Bentley_Geom_DRange3d_IntersectIndependentComponentsOf =R"doc(Compute intersection of x,y,z components independently.

Parameter ``[in]``:
    range1 first range

Parameter ``[in]``:
    range2 second range)doc";

static const char * __doc_Bentley_Geom_DRange3d_IntersectionOf =R"doc(Compute the intersection of two ranges. If any direction has no
intersection the result range is initialized to a null range. (Zero
thickness intersection is null.)

Parameter ``[in]``:
    range1 first range

Parameter ``[in]``:
    range2 second range)doc";

static const char * __doc_Bentley_Geom_DRange3d_UnionOf =R"doc( returns the union of two ranges.

Parameter ``[in]``:
    range0 first range

Parameter ``[in]``:
    range1 second range)doc";

static const char * __doc_Bentley_Geom_DRange3d_ExtendBySweep =R"doc( Extend either low or high of each axis by corresponding
vector entry for sweep of the range cube. Any axis with low> high is
left unchanged.

Parameter ``[in]``:
    vector sweep drection)doc";

static const char * __doc_Bentley_Geom_DRange3d_InitFromMinMax =R"doc( Initialize the range from given min and max in all
directions. Given values will be swapped if needed.

Parameter ``[in]``:
    v0 min (or max)

Parameter ``[in]``:
    v1 max (or min))doc";

static const char * __doc_Bentley_Geom_DRange3d_FromMinMax =R"doc( Initialize the range.InitFrom given min and max in all
directions. Given values will be swapped if needed.

Parameter ``[in]``:
    v0 min (or max)

Parameter ``[in]``:
    v1 max (or min))doc";

static const char * __doc_Bentley_Geom_DRange3d_Extend =R"doc( Extends the coordinates of the range cube points in
pRange so as to include the single additional point point.

Parameter ``[in]``:
    point new point to be included in the range.)doc";

static const char * __doc_Bentley_Geom_DRange3d_Init =R"doc( Initializes a range cube with (inverted) large positive
and negative values.)doc";

static const char * __doc_Bentley_Geom_DRange3d_NullRange =R"doc( Initializes a range cube with (inverted) large positive
and negative values.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DRange3d(py::module_& m)
    {
    //===================================================================================
    // struct DRange3d
    py::class_<DRange3d> c1(m, "DRange3d");
    bind_ValidatedValue<DRange3d>(m, "ValidatedDRange3d", py::module_local(false));
    bind_ValueSizeSize<DRange3d>(m, "DRange3dSizeSize", py::module_local(false));

    c1.def(py::init(&DRange3d::NullRange));
    c1.def_static("NullRange", &DRange3d::NullRange, DOC(Bentley, Geom, DRange3d, NullRange));        
    c1.def("Init", &DRange3d::Init, DOC(Bentley, Geom, DRange3d, Init));

    c1.def(py::init(py::overload_cast<DPoint3dCR>(&DRange3d::From)), "point"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, DPoint3dCR>(&DRange3d::From)), "point0"_a, "point1"_a);
    c1.def(py::init(py::overload_cast<DPoint3dCR, DPoint3dCR, DPoint3dCR>(&DRange3d::From)), "point0"_a, "point1"_a, "point2"_a);
    c1.def(py::init(py::overload_cast<double, double, double>(&DRange3d::From)), "x"_a, "y"_a, "z"_a);
    c1.def(py::init(py::overload_cast<double, double, double, double, double, double>(&DRange3d::From)), "x0"_a, "y0"_a, "z0"_a, "x1"_a, "y1"_a, "z1"_a);
    c1.def(py::init(py::overload_cast<DPoint2dArray const&, double>(&DRange3d::From)), "points"_a, "zVal"_a);
    c1.def(py::init(py::overload_cast<DPoint3dArray const&>(&DRange3d::From)), "points"_a);
    c1.def(py::init(py::overload_cast<DPoint4dArray const&>(&DRange3d::From)), "points"_a);
    c1.def(py::init(py::overload_cast<DPoint3dVecArray const&>(&DRange3d::From)), "points"_a);
    c1.def(py::init(py::overload_cast<DPoint3dVecVecArray const&>(&DRange3d::From)), "points"_a);
    c1.def(py::init([] (std::vector<DPoint3d> const& points, std::vector<double> const& weights)
                  { 
                  return DRange3d::From(points.data(), weights.data(), (int) points.size()); 
                  }), "points"_a, "weights"_a);

    c1.def(py::init([] (TransformCR transform, std::vector<DPoint3d> const& points, std::vector<double> const& weights)
                  {
                  return DRange3d::From(transform, points.data(), weights.data(), (int) points.size());
                  }), "transform"_a, "points"_a, "weights"_a);
    c1.def(py::init(py::overload_cast<TransformCR, DPoint3dArray const&>(&DRange3d::From)), "transform"_a, "points"_a);
    c1.def(py::init(py::overload_cast<TransformCR, DPoint4dArray const&>(&DRange3d::From)), "transform"_a, "points"_a);
        
    c1.def("Extend", py::overload_cast<double>(&DRange3d::Extend), "extend"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DRange3dCR>(&DRange3d::Extend), "range1"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DEllipse3dCR>(&DRange3d::Extend), "ellipse"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DPoint3dCR>(&DRange3d::Extend), "point"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DPoint3dCR, double>(&DRange3d::Extend), "point"_a, "weight"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DPoint4dCR>(&DRange3d::Extend), "point"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<double, double, double>(&DRange3d::Extend), "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DPoint2dArray const&, double>(&DRange3d::Extend), "points"_a, "zVal"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DPoint3dArray const&>(&DRange3d::Extend), "points"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<DPoint4dArray const&>(&DRange3d::Extend), "points"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<TransformCR, DPoint3dArray const&>(&DRange3d::Extend), "transform"_a, "points"_a, DOC(Bentley, Geom, DRange3d, Extend));
    c1.def("Extend", py::overload_cast<TransformCR, DPoint4dArray const&>(&DRange3d::Extend), "transform"_a, "points"_a, DOC(Bentley, Geom, DRange3d, Extend));    

    c1.def("Extend", [] (DRange3dR self, TransformCR transform, std::vector<DPoint3d> const& points, std::vector<double> const& weights)
           {
           self.Extend(transform, points.data(), weights.data(), (int) points.size());
           }, "transform"_a, "points"_a, "weights"_a, DOC(Bentley, Geom, DRange3d, Extend));

        
    c1.def_static("FromMinMax", &DRange3d::FromMinMax, "v0"_a, "v1"_a, DOC(Bentley, Geom, DRange3d, FromMinMax));
    c1.def("InitFromMinMax", &DRange3d::InitFromMinMax, "v0"_a, "v1"_a, DOC(Bentley, Geom, DRange3d, InitFromMinMax));
        
    c1.def("ExtendBySweep", &DRange3d::ExtendBySweep, "vector"_a, DOC(Bentley, Geom, DRange3d, ExtendBySweep));
    c1.def("UnionOf", &DRange3d::UnionOf, "range0"_a, "range1"_a, DOC(Bentley, Geom, DRange3d, UnionOf));
    c1.def("IntersectionOf", &DRange3d::IntersectionOf, "range1"_a, "range2"_a, DOC(Bentley, Geom, DRange3d, IntersectionOf));
    c1.def("IntersectIndependentComponentsOf", &DRange3d::IntersectIndependentComponentsOf, "range1"_a, "range2"_a, DOC(Bentley, Geom, DRange3d, IntersectIndependentComponentsOf));    

    c1.def("IsNull", &DRange3d::IsNull, DOC(Bentley, Geom, DRange3d, IsNull));
    c1.def("ExtentSquared", &DRange3d::ExtentSquared, DOC(Bentley, Geom, DRange3d, ExtentSquared));
    c1.def("IsEmpty", &DRange3d::IsEmpty, DOC(Bentley, Geom, DRange3d, IsEmpty));
    c1.def("IsPoint", &DRange3d::IsPoint, DOC(Bentley, Geom, DRange3d, IsPoint));
    c1.def("Volume", &DRange3d::Volume, DOC(Bentley, Geom, DRange3d, Volume));
    c1.def("XLength", &DRange3d::XLength, DOC(Bentley, Geom, DRange3d, XLength));
    c1.def("YLength", &DRange3d::YLength, DOC(Bentley, Geom, DRange3d, YLength));
    c1.def("ZLength", &DRange3d::ZLength, DOC(Bentley, Geom, DRange3d, ZLength));
    c1.def("DiagonalDistance", &DRange3d::DiagonalDistance, DOC(Bentley, Geom, DRange3d, DiagonalDistance));        
    c1.def("DiagonalDistanceXY", &DRange3d::DiagonalDistanceXY, DOC(Bentley, Geom, DRange3d, DiagonalDistanceXY));        
    c1.def("DiagonalVector", &DRange3d::DiagonalVector, DOC(Bentley, Geom, DRange3d, DiagonalVector));        
    c1.def("DiagonalVectorXY", &DRange3d::DiagonalVectorXY, DOC(Bentley, Geom, DRange3d, DiagonalVectorXY));
    c1.def("IsAlmostZeroZ", &DRange3d::IsAlmostZeroX, DOC(Bentley, Geom, DRange3d, IsAlmostZeroZ));
    c1.def("IsAlmostZeroY", &DRange3d::IsAlmostZeroY, DOC(Bentley, Geom, DRange3d, IsAlmostZeroY));
    c1.def("IsAlmostZeroX", &DRange3d::IsAlmostZeroZ, DOC(Bentley, Geom, DRange3d, IsAlmostZeroX));
    c1.def("LargestCoordinate", &DRange3d::LargestCoordinate, DOC(Bentley, Geom, DRange3d, LargestCoordinate));
    c1.def("MaxAbs", &DRange3d::MaxAbs, DOC(Bentley, Geom, DRange3d, MaxAbs));
    c1.def("LargestCoordinateXY", &DRange3d::LargestCoordinateXY, DOC(Bentley, Geom, DRange3d, LargestCoordinateXY));

    c1.def("Get8Corners", &DRange3d::Get8Corners, "box"_a, DOC(Bentley, Geom, DRange3d, Get8Corners));

    c1.def("Get6Planes", [] (DRange3dCR self, DPlane3dArray& planes, double normalLength)
           {
           if (planes.size() < 6)
               planes.resize(6);
           self.Get6Planes(&planes[0], normalLength);
           }, "planes"_a, "normalLength"_a = 1.0, DOC(Bentley, Geom, DRange3d, Get6Planes));

    c1.def("Get6Planes", [] (DRange3dCR self, DPoint3dArray& origins, DPoint3dArray& normals)
           {
           if (origins.size() < 6) origins.resize(6);
           if (normals.size() < 6) normals.resize(6);
           self.Get6Planes(&origins[0], &normals[0]);
           }, "origins"_a, "normals"_a = 1.0, DOC(Bentley, Geom, DRange3d, Get6Planes));    

    c1.def("GetEdges", &DRange3d::GetEdges, "edges"_a, DOC(Bentley, Geom, DRange3d, GetEdges));

    c1.def("GetComponentDRange1d", &DRange3d::GetComponentDRange1d, "index"_a, DOC(Bentley, Geom, DRange3d, GetComponentDRange1d));

    c1.def("GetCornerRange", py::overload_cast<DRay3dCR>(&DRange3d::GetCornerRange, py::const_), "ray"_a, DOC(Bentley, Geom, DRange3d, GetCornerRange));
    c1.def("GetCornerRange", py::overload_cast<DPlane3dCR>(&DRange3d::GetCornerRange, py::const_), "plane"_a, DOC(Bentley, Geom, DRange3d, GetCornerRange));

    c1.def("IndexOfMaximalAxis", &DRange3d::IndexOfMaximalAxis, DOC(Bentley, Geom, DRange3d, IndexOfMaximalAxis));

    c1.def("LocalToGlobal", &DRange3d::LocalToGlobal, "xFraction"_a, "yFraction"_a, "zFraction"_a, DOC(Bentley, Geom, DRange3d, LocalToGlobal));

    c1.def("IsContained", py::overload_cast<DRange3dCR>(&DRange3d::IsContained, py::const_), "outerRange"_a, DOC(Bentley, Geom, DRange3d, IsContained));
    c1.def("IsContained", py::overload_cast<DPoint3dCR>(&DRange3d::IsContained, py::const_), "point"_a, DOC(Bentley, Geom, DRange3d, IsContained));
    c1.def("IsContained", py::overload_cast<DPoint3dCR, int>(&DRange3d::IsContained, py::const_), "point"_a, "numDistance"_a, DOC(Bentley, Geom, DRange3d, IsContained));
    c1.def("IsContained", py::overload_cast<double, double, double>(&DRange3d::IsContained, py::const_), "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, DRange3d, IsContained));
    c1.def("IsContainedXY", &DRange3d::IsContainedXY, "point"_a, DOC(Bentley, Geom, DRange3d, IsContainedXY));

    c1.def("DistanceOutside", &DRange3d::DistanceOutside, "xyz"_a, DOC(Bentley, Geom, DRange3d, DistanceOutside));
    c1.def("DistanceSquaredOutside", &DRange3d::DistanceSquaredOutside, "xyz"_a, DOC(Bentley, Geom, DRange3d, DistanceSquaredOutside));        
    c1.def("DistanceSquaredTo", &DRange3d::DistanceSquaredTo, "other"_a, DOC(Bentley, Geom, DRange3d, DistanceSquaredTo));

    c1.def("IntersectsWith", py::overload_cast<DRange3dCR>(&DRange3d::IntersectsWith, py::const_), "range2"_a, DOC(Bentley, Geom, DRange3d, IntersectsWith));
    c1.def("IntersectsWith", py::overload_cast<DRange3dCR, int>(&DRange3d::IntersectsWith, py::const_), "range2"_a, "numDimensions"_a, DOC(Bentley, Geom, DRange3d, IntersectsWith));
    c1.def("IntersectsWith", py::overload_cast<DRange3dCR, double, int>(&DRange3d::IntersectsWith, py::const_), "range2"_a, "gapSize"_a, "numDimensions"_a, DOC(Bentley, Geom, DRange3d, IntersectsWith));

    c1.def("IsEqual", py::overload_cast<DRange3dCR>(&DRange3d::IsEqual, py::const_), "range1"_a, DOC(Bentley, Geom, DRange3d, IsEqual));
    c1.def("IsEqual", py::overload_cast<DRange3dCR, double>(&DRange3d::IsEqual, py::const_), "range1"_a, "tolerance"_a, DOC(Bentley, Geom, DRange3d, IsEqual));

    c1.def("IsStrictlyContainedXY", &DRange3d::IsStrictlyContainedXY, "outerRange"_a, DOC(Bentley, Geom, DRange3d, IsStrictlyContainedXY));
    c1.def("RestrictToMinMax", &DRange3d::RestrictToMinMax, "range0"_a, "minMax"_a, DOC(Bentley, Geom, DRange3d, RestrictToMinMax));

    c1.def("IntersectRay", [] (DRange3dCR self, DPoint3dR point0, DPoint3dR point1, DPoint3dCR start, DPoint3dCR direction)
           {
           double param0 = 0;
           double param1 = 0;
           bool bOk = self.IntersectRay(param0, param1, point0, point1, start, direction);
           return py::make_tuple(bOk, param0, param1);
           }, "point0"_a, "point1"_a, "start"_a, "direction"_a, DOC(Bentley, Geom, DRange3d, IntersectRay));

    c1.def("IntersectBounded", [] (DRange3dCR self, DSegment3dR clipped, DSegment3dCR segment)
           {
           double param0 = 0;
           double param1 = 0;
           bool bOk = self.IntersectBounded(param0, param1, clipped, segment);
           return py::make_tuple(bOk, param0, param1);
           }, "clipped"_a, "segment"_a, DOC(Bentley, Geom, DRange3d, IntersectBounded));
        
    c1.def("IntersectionExtentSquared", &DRange3d::IntersectionExtentSquared, "range2"_a, DOC(Bentley, Geom, DRange3d, IntersectionExtentSquared));
    c1.def("MoveChangesIntersection", &DRange3d::MoveChangesIntersection, "newRange"_a, "outerRange"_a, DOC(Bentley, Geom, DRange3d, MoveChangesIntersection));

    c1.def("__repr__", [] (DRange3d& self) { return "[low:{}, high:{}]"_s.format(self.low, self.high); });
    c1.def("__copy__", [] (const DRange3d& self) { return DRange3d(self); });
    }