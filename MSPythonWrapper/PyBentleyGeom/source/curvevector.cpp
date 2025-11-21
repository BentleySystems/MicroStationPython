/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\curvevector.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/CurvePrimitive.h>



static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_DistanceXYFromPathStart =R"doc(Given a path location, find the projected curve distance from the path
start.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_SearchFirstIntersectionWithCircleXY =R"doc(Start at specified location. Make a circle of given radius. Look for
the " first " intersection of the circle with the path, moving only
forward if the radius is positive and only backward if negative.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_SearchClosestPointBounded =R"doc(Search for curve point closest to given space point.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_SearchByDistanceFromPathStartXY =R"doc(Return detailed curve location for the position at targetDistance
along the curve, measuring in path distance. WARNING:The distance
entry in the PositionLocationDetail is true distance (with z
variation))doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_SearchByDistanceFromPathStart =R"doc(Return detailed curve location for the position at targetDistance
along the curve.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_DistanceBetweenPointsXY =R"doc(projected distance between points)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_AtEnd =R"doc(Return the final location.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_AtStart =R"doc(Return the start location.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_TotalPathLengthXY =R"doc(Return complete path length as flattened into the view.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_TotalPathLength =R"doc(Return complete path length.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_SetExtendedPath =R"doc(Announce the path to be indexed. This will 1) Construct line segments
to extend in the directions of the start and end tangents. 2) create
the <curve,distance> index 3) return PositionLocationDetails for the
limits of the bounded path.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_SetPath =R"doc(Announce the path to be indexed. This will:1) save a pointer to the
path. 2) create an index of <curve,distance> to support fast search
and navigation by distance.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_NumberOfPrimitives =R"doc(Return the total number of curve primitives in the path.)doc";

static const char * __doc_Bentley_Geom_CurveVectorWithDistanceIndex_IsEmpty =R"doc(Return true if there are no curves.)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_IsLessThan_ByPathDistance =R"doc(Comparison using only the stored distance.)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_DistanceFromPathStart =R"doc(Query the stored distance to path start. Note that this is not a
recompute -- just a member access.)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_DistanceSquaredToPoint =R"doc(distance squared to given point.)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_DistanceToPoint =R"doc(distance between points of this and other detail.)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_GetPrimitiveIndex =R"doc(Get the index of this detail's curve within its containing
CurveVectorWithDistanceIndex)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_HasCurve =R"doc(Test if there is a curve.)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_GetCurveLocationDetail =R"doc(Query CurveLocationDetail with fractional position for queries)doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_PointAndUnitTangent =R"doc(Query xyz coordinates and normalized tangent vector. (This reevaluates
the curve))doc";

static const char * __doc_Bentley_Geom_PathLocationDetail_Point =R"doc(Query xyz coordinates)doc";

static const char * __doc_Bentley_Geom_CurveCurve_IntersectRotatedCurveSpaceCurve =R"doc(Compute intersections of (a) a curve rotated around an axis and (b) a
space curve.)doc";

static const char * __doc_Bentley_Geom_CurveCurve_TransverseRegionIntersectionSegments =R"doc(Determine the line of intersection of the planes of the two containing
planes. In that line, find all segments as split by the two curve
vectors. Return false if the curve vectors are not individually planar
or are not closed)doc";

static const char * __doc_Bentley_Geom_CurveCurve_GetPartialCurveDetailPair =R"doc(Convenience function for extracting PartialCurveDetail data from two
arrays returned by CurveCurve::IntersectionsXY return false if index
out of range or addresses something other than PartialCurveData.

:param (input):
    intersectionA first source vector

:param (input):
    intersectionB second source vector

:param (input):
    i index to acccess in source vectors.

:param (output):
    detailA data from intersectionA

:param (output):
    detailB data from intersectionB)doc";

static const char * __doc_Bentley_Geom_CurveCurve_IsContained =R"doc(Test if interval i is contained in interval j.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CreateXYHatch =R"doc(Return a curve vector (of type BOUNDARY_TYPE_None) containing hatch
sticks.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ReduceToCCWAreas =R"doc(Return a curve vector containing only clockwise areas. Loops within
parity regions are fixed first. Then multiple regions in a union are
combined.

:param (input):
    regionA input areas)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreaAnalysis =R"doc(Return a curve vector containing the " inside " areas by various
conditions.

:param (input):
    region Region that may have loops back over its area.

:param (input):
    select1 Rule for classifying single area:one of
    AreaSelect_Parity, AreaSelect_CCWPositiveWindingNumber,
    AreaSelect_CCWNonzeroWindingNumber,
    AreaSelect_CCWNegativeWindingNumber

:param (input):
    select2 Rule for combining leaf left results:One of
    BoolSelect_Parity, BoolSelect_Union, BoolSelect_Sum_Parity,
    BoolSelect_CCWPositiveWindingNumber,
    BoolSelect_CCWNonzeroWindingNumber,
    BoolSelect_CCWNegativeWindingNumber

:param (input):
    reverse to return the opposite set of faces.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreaParity =R"doc(Return a curve vector containing the parity of input areas.

:param (input):
    regionA left operand

:param (input):
    regionB right operand

:param [in,out]:
    newToOld (optional) pointer to bvector to receive paring of new
    and old curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreaIntersection =R"doc(Return a curve vector containing the intersection of input areas.

:param (input):
    regionA left operand

:param (input):
    regionB right operand

:param [in,out]:
    newToOld (optional) pointer to bvector to receive paring of new
    and old curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreaDifference =R"doc(Return a curve vector containing the difference of input areas.

:param (input):
    regionA left operand

:param (input):
    regionB right operand

:param [in,out]:
    newToOld (optional) pointer to bvector to receive paring of new
    and old curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreaUnion =R"doc(Return a curve vector containing the union of input areas.

:param (input):
    regionA left operand

:param (input):
    regionB right operand

:param [in,out]:
    newToOld (optional) pointer to bvector to receive paring of new
    and old curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AssembleChains =R"doc(Join curve primitives head to tail. Return a top level
BOUNDARY_TYPE_None containing the various BOUNDARY_TYPE_Open and
BOUNDARY_TYPE_Outer)doc";

static const char * __doc_Bentley_Geom_CurveVector_ReorderForSmallGaps =R"doc(Reorder curve primitives to produce small head-to-tail gaps.
reordering is applied only within boundary types None, Open, and
Closed. other types are updated recursively. Return the largest gap.)doc";

static const char * __doc_Bentley_Geom_CurveVector_FixupXYOuterInner =R"doc(Update order, boundary type, and direction of contained loops. Loop A
is considered " inside " loop B if (a) loop A has smaller area and (b)
the start point of loop A is inside loop B. A loop that is " inside " an
ODD number of other loops is considered to be a " hole " (inner loop)
within the containing loop that has smallest area. Any other loop is
considered an outer loop.

* If there is a single outer loop, the (modified) curve vector is
marked as a parity region. The outer loop is moved first and the inner
loops follows.

* If there are multiple outer loops, the (modified) curve vector is
marked as a union region. Within the UnionRegion

* Outer loops with no contained loops are present as simple Outer
loops.

* Outer loops with holes are parity regions.

:param (input):
    fullGeometryCheck if true, perform all (expensive) tests for
    intersections among curves. When this is enabled, the returned
    curve vector is typically a (possibly significantly modified)
    clone of the original.)doc";

static const char * __doc_Bentley_Geom_CurveVector_SimplifyLinestrings =R"doc(Inplace update to consolidate colinear interior points of linestrings.
If distance tolerance is nonpositive a tolerance will be assigned from
the range.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ConsolidateAdjacentPrimitives =R"doc(Inplace update to consolidate contiguous parts. Adjacent lines and
linestrings become a single linestring. Interior colinear points of
linestrings are eliminated. Adjacent and compatible arcs become single
arc.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ReverseCurvesInPlace =R"doc(Recursively reverse. All leaf curves are reversed. Primitive order
within path types (_Outer, _Inner, _Open) is reversed. All others
(_Union, _Parity, _None) are unchanged.)doc";

static const char * __doc_Bentley_Geom_CurveVector_TransformInPlace =R"doc(Apply a transform to all contained curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_RayPierceInOnOut =R"doc(Test for a ray hit in the curve vector's planar region. return
INOUT_Unknown if the CurveVector is not an area. (i.e. type
BOUNDARY_TYPE_Outer, BOUNDARY_TYPE_Inner, BOUNDARY_TYPE_ParityRegion,
or BOUNDARY_TYPE_Union)doc";

static const char * __doc_Bentley_Geom_CurveVector_PointInOnOutXY =R"doc(Test if a point is in, on, or outside when looking at xy plane. return
INOUT_Unknown if the CurveVector is not an area. (i.e. type
BOUNDARY_TYPE_Outer, BOUNDARY_TYPE_Inner, BOUNDARY_TYPE_ParityRegion,
or BOUNDARY_TYPE_Union

:param (input):
    xyz test point)doc";

static const char * __doc_Bentley_Geom_CurveVector_PlaneSection =R"doc(Compute intersections of closed CurveVector with a plane and organize
as start end pairs by parity rules. Return as a single curve primitive
(which may be child vector of multiple primitives) If there are no
intersections the smart pointer is empty (IsValid () returns false)

:param (input):
    plane

:param (input):
    tolerance for on-plane decisions. If 0, a tolerance is computed
    based on the coordinates in the curve.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AppendClosedCurvePlaneIntersections =R"doc(Compute intersections of closed CurveVector with a plane and organize
as start end pairs by parity rules. Intersections are reported as
CurveLocationDetailPairs for start and end of segments.

:param (input):
    plane

:param (output):
    intersections intersection details

:param (input):
    tolerance for on-plane decisions. If 0, a tolerance is computed
    based on the coordinates in the curve.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AppendCurvePlaneIntersections =R"doc(Compute simple points of intersection of the curve with a plane.
Single point intersection appears as a CurveLocationDetailPair with
identical locations for both parts of the pair (SameCurveAndFraction)
Curve-on-plane appears as CurveLocationDetailPair with curve,fraction
data for start and end of on-plane sections.

:param (input):
    plane

:param (output):
    intersections intersection details

:param (input):
    tolerance for on-plane decisions. If 0, a tolerance is computed
    based on the coordinates in the curve.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ContainsNonLinearPrimitive =R"doc(Return true if CurveVector has a component that is not a line or
linestring.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GenerateAllParts =R"doc(Return a CurveVector (BOUNDARY_TYPE_None) which is a collection of
open CurveVectors that collectively contain all parts of the input For
(indexA,fractionA) prededing (indexB,fractionB) the output traces the
input in the forward direction and has the following possibilities (of
which null ones are skipped) ul> li> BOUNDARY_TYPE_Open - (A B), (B to
end), (start to A) li> BOUNDARY_TYPE_Inner or BOUNDARY_TYPE_Outer - (A
B), (B to where A appears in the next period) li>
BOUNDARY_TYPE_ParityRegion, BOUNDARY_TYPE_UnionRegion,
BOUNDARY_TYPE_None -- no output. ul> For (indexA,fractionA) prededing
(indexB,fractionB) the output traces the input in the reverse
direction and has the following possibilities (of which null ones are
skipped) ul> li> BOUNDARY_TYPE_Open - (A backwards to B), (B backwards
to start), (end backwards to A) li> BOUNDARY_TYPE_Inner or
BOUNDARY_TYPE_Outer - (A backwards to B), (B backwards to where A
appears in the previous period.) li> BOUNDARY_TYPE_ParityRegion,
BOUNDARY_TYPE_UnionRegion, BOUNDARY_TYPE_None -- no output. ul>)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneReversed =R"doc(Return a new curve vector that has all components reversed.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneBetweenDirectedFractions =R"doc(Return a new vector containing curves from index0,fraction0 to
index1,fraction1 with the (signed int!!) indices restricted to array
bounds.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneBetweenCyclicIndexedFractions =R"doc(Return a new vector containing curves from index0,fraction0 to
index1,fraction1 with the (signed int!!) indices interpretted
cyclically.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ResolveTolerance =R"doc(return larger of given tolerance and default tolerance based on
FastMasAbs of contents ...)doc";

static const char * __doc_Bentley_Geom_CurveVector_CurveLocationDetailCompare =R"doc(return 0 of locations are equal, -1 if location 0 is less than
location 1, and 1 if location 0> location 1. This is a lexical
comparison using (only) the curve index and the fraction.)doc";

static const char * __doc_Bentley_Geom_CurveVector_FindParentOfPrimitive =R"doc(Search the tree (below the calling instance) for the curve vector
which is the immediate parent of given primitive.)doc";

static const char * __doc_Bentley_Geom_CurveVector_FindIndexOfPrimitive =R"doc(return index of primitive in vector (only valid for a vector that is a
single open or closed path). Returns SIZE_MAX if not found.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CurveLocationDetailIndex =R"doc(return index of curve location detail in vector (only valid for a
vector that is a single open or closed path). Returns SIZE_MAX if not
found.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetCyclic =R"doc(return child at cyclic index, propertly corrected for negatives.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CyclicIndex =R"doc(return mod of index with vector length, properly corrected for
negatives.)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsPlanarWithDefaultNormal =R"doc(Test if the contained curves are planar. If so, return transforms and
local range.

:param (output):
    localToWorld A coordinate frame somewhere on the curves. The
    curves are on the xy plane.

:param (output):
    worldToLocal Inverse of localToWorld.

:param (output):
    range range of the curves when worldToLocal is applied.

:param (input):
    normal optional normal to resolve ambiguous cases. If this is
    NULL, any perpendicular to an ambiguous line will be used.

:returns:
    true if range is computed and has small z component.)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsPlanar =R"doc(Test if the contained curves are planar. If so, return transforms and
local range.

:param (output):
    localToWorld A coordinate frame somewhere on the curves. The
    curves are on the xy plane.

:param (output):
    worldToLocal Inverse of localToWorld.

:param (output):
    range range of the curves when worldToLocal is applied.

:returns:
    true if range is computed and has small z component.

Remark:
    returns true (planar!!) for a single line. Test the local range
    with IsAlmostZeroY to identify this condition.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetRange =R"doc(Return the xyz range of contained curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsSameStructureAndGeometry =R"doc(Recursive check for match (tree structure. leaf type, and geometry)
with a peer. <param name=" other ">peer for comparison</param> <param
name=" tolerance ">distance tolerance. (See DoubleOps::AlmostEqual
())</param>)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsSameStructure =R"doc(Recursive check for structural match (tree structure and leaf type)
with the other curve vector.)doc";

static const char * __doc_Bentley_Geom_CurveVector_FastMaxAbs =R"doc(Return a fast estimate of the maximum absolute value in any
coordinate. This will examine all curves, but is allowed to use safe
approximations like bspline pole coordinates instead of exact curve
calculations.)doc";

static const char * __doc_Bentley_Geom_CurveVector_MaxGapWithinPath =R"doc(Maximum gap distance between end of primitive and start of its
successor within Open, outer, or Inner loop.)doc";

static const char * __doc_Bentley_Geom_CurveVector_FastLength =R"doc(Sum lengths of contained curves, using fast method that may
overestimate the length but is reasonable for setting tolerances.)doc";

static const char * __doc_Bentley_Geom_CurveVector_Length =R"doc(Sum lengths of contained curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetStartPoint =R"doc(Return start point of the primitive (or first primitive in deep
search)

:param (output):
    point start point.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetStartEnd =R"doc(Return first/last among children.

:param (output):
    pointA start point

:param (output):
    pointB end point)doc";

static const char * __doc_Bentley_Geom_CurveVector_AnnounceKeyPoints =R"doc(Search for various keypoints (as requested by the collector) During
recursion, extension bits are changed to false for interior points of
paths)doc";

static const char * __doc_Bentley_Geom_CurveVector_ClosestCurveOrRegionPoint =R"doc(Search for closest point on curve. If CV is a region type, also look
for projection onto interior of the region.

:param (input):
    spacePoint fixed point of search

:param (output):
    curveOrRegionPoint computed point on curve or region interior.

:returns:
    INOUT_On if the point is a curve point. INOUT_In if the point is a
    projection to the region interior. INOUT_Unknown for empty curve
    vector.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ClosestPointBoundedXY =R"doc(Search for the closest point on any contained curve, using only xy
(viewed) coordinates.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ClosestPointBounded =R"doc(Search for the closest point on any contained curve.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetBsplineCurve =R"doc(Represent a curve vector that denotes an open or closed path as a
single bspline curve.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ToBsplineCurve =R"doc(Represent a curve vector that denotes an open or closed path as a
single bspline curve.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AddSpacedPoints =R"doc(Compute points at (many) specified distances along the (many) curves
in the CurveVector. Intervals between successive distances can " jump "
from one curve to the next. If curves to not connect head to tail, the
gap is NOT filled -- measurement just picks up after the gap.

:param (input):
    distances vector of distances, all measured from the start of the
    first primitive.

:param (output):
    locations vector of locations. (This is NOT cleared at start --
    points are just added.))doc";

static const char * __doc_Bentley_Geom_CurveVector_CollectLinearGeometry =R"doc(Add strokes from the instance curves.
* The output retains structure as complex as "union of multi-loop parity regions".
* For a BOUNDARY_TYPE_None, each child is added recursively.

:regionsPoints [out]:
    collection of collections of loops; regionsPoints[i] is an array of loops, regionPoints[i][j] is a loop, regionPoints[i][j][k] is a point of a loop.

:strokeOptions [input]:
    stroke options. If null all curved geometry is skipped.

:returns:
    true if and only if no geometry was skipped and no unexpected was structure encountered.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AddStrokePoints =R"doc(Add stroke points form all children to output. Strokes from all
children are concatenated into the same vector, separated only by
DISCONNECT points. Use Stroke() to get structured strokes.

:param [in,out]:
    points growing vector of strokes.

:param (input):
    options options for stroke density. chordTolerance,
    angleTolerance, and maxEdgeLength will be used.)doc";

static const char * __doc_Bentley_Geom_CurveVector_Stroke =R"doc(Return a " deep copy " with primitives replaced by strokes. The tree
upper levels of the tree structure are retained -- i.e. the output
contains corresponding tree structure ParityRegion, UnionRegion,
OuterLoop, and InnerLoop ul> li>UnionRegion and ParityRegion vectors:
Create a new CurveVector of the same type. Recursively create
children. li>OuterLoop, InnerLoop, OpenPath:Create a new curve vector
of the same type. Stroke all curve primitives into a single linestring
with the child curves' AddStrokes method. ul>)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneAsBsplines =R"doc(Return a " deep copy " with primitives replaced by bsplines The tree
upper levels of the tree structure are retained -- i.e. the output
contains corresponding tree structure ParityRegion, UnionRegion,
OuterLoop, and InnerLoop ul> li>UnionRegion and ParityRegion vectors:
Create a new CurveVector of the same type. Recursively create
children. li>OuterLoop, InnerLoop, OpenPath:Create a new curve vector
of the same type. li>Primitives:Each primitive is copied as a bspline
curve primitive. ul>)doc";

static const char * __doc_Bentley_Geom_CurveVector_CreateDisk =R"doc(Create a (deep) curve vector structure for a complete elliptic
(circular) disk.

:param (input):
    arc boundary ellipse

:param (input):
    boundaryType is one of

* BOUNDARY_TYPE_Outer:force to counterclockwise and positive area as
seen looking at xy plane.

* BOUNDARY_TYPE_Inner:force to clockwise and negative area as seen
looking at xy plane.

* BOUNDARY_TYPE_Open, BOUNDARY_TYPE_None:ellipse inserted with its
own direction.

* BOUNDARY_TYPE_UnionRegion, BOUNDARY_TYPE_ParityRegion create two-
level structure with arc at second level with BOUNDARY_TYPE_Outer

:param (input):
    forceXYOrientation if true, reverse arc sweep so it acts as
    requested inner/outer in xy view.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CreateRectangle =R"doc(Create a rectangle from xy corners.

:param (input):
    x0 start point x coordinate

:param (input):
    y0 start point y coordinate

:param (input):
    x1 opposite corner x coordinate

:param (input):
    y1 opposite corner y coordinate

:param (input):
    z z value for all points.

:param (input):
    boundaryType is one of

* BOUNDARY_TYPE_Outer:force to counterclockwise and positive area

* BOUNDARY_TYPE_Inner:force to clockwise and negative area

* BOUNDARY_TYPE_Open, BOUNDARY_TYPE_None:point order
(x0,y0)(x1,y0),(x1,y1),(x0,y1)

* BOUNDARY_TYPE_UnionRegion, BOUNDARY_TYPE_ParityRegion create two-
level structure with rectangle at second level with
BOUNDARY_TYPE_Outer)doc";

static const char * __doc_Bentley_Geom_CurveVector_CreateLinear =R"doc(Create a linestring or polygon from xyz data.

:param (input):
    points vertex coordinates points.

:param (input):
    boundaryType is one of

* BOUNDARY_TYPE_Outer, or BOUNDARY_TYPE_INNER:Duplication forced on
first/last point. Orientation optionally enforced.

* BOUNDARY_TYPE_Open, BOUNDARY_TYPE_None:points copied unchanged.

* BOUNDARY_TYPE_UnionRegion, BOUNDARY_TYPE_ParityRegion create two-
level structure with polygon at second level with BOUNDARY_TYPE_Outer.

:param (input):
    forceXYOrientation true to force outer and inner loops to have
    correct (CCW/CW) order.)doc";

static const char * __doc_Bentley_Geom_CurveVector_TryUVFractionToXYZ =R"doc(convert u,v fraction to xyz and derivatives. This is an expensive
operation. It has to call CloneInLocalCoordinates before it can
multiply uv by the localToWorld transformation. To do this efficiently
many times, call CloneInLocalCoordinates once and reuse the
localToWorld transform.

:param (input):
    uFraction fractional coordinate in u direction.

:param (input):
    vFraction fractional coordinate in v direction.

:param (output):
    xyz point on face.

:param (output):
    dXdu derivative of face point wrt uFraction.

:param (output):
    dXdv derivative of face point wrt vFraction.)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetAnyFrenetFrame =R"doc(Deep search for any curve primitive that has a well defined coordinate
frame.

:param (output):
    frame coordinate frame with origin on a primitive.

:returns:
    true if a primitive was found.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneInLocalCoordinates =R"doc(Return curve copy and transforms for a local coordinate system related
to the curves. The local x and y axes are parallel to the x and y axes
of the Frenet frame at the curve start.

:returns:
    curves transformed to local system.

:param (output):
    localToWorld local to world transform

:param (output):
    worldToLocal world to local transform

:param (output):
    localRange curve vector range in the local frame.

:param (input):
    frameType Selects how the geometry size is represented in the
    scale. ul> li>LOCAL_COORDINATE_SCALE_UnitAxesAtStart -- x,y,z
    columns in the transform are unit vectors. localRange values are
    true geometry sizes. origin is at start point of first primitive.
    li>LOCAL_COORDINATE_SCALE_UnitAxesAtLowerLeft -- x,y,z columns in
    the transform are unit vectors. localRange values are true
    geometry sizes. origin is at lower left of range.
    li>LOCAL_COORDINATE_SCALE_01RangeBothAxes -- x column is a vector
    spanning the x range from min to max. y column is a vector
    spanning the y range from min to max. localRange values are 0..1
    (inclusive) in both directions. origin is at lower left of range.
    li>LOCAL_COORDINATE_SCALE_01RangeLargerAxis -- x and y columns
    have the same length, large enough to span the larger direction.
    localRange values are 0..1 in the larger direction, 0..f in the
    smaller direction, where f is that direction's size as a fraction
    of the larger direction. origin is at lower left of range. ul>)doc";

static const char * __doc_Bentley_Geom_CurveVector_ProjectedParameterRange =R"doc(Return the range of ray parameters when contents of the CurveVector
are projected to a ray. return DRange1d with range data.

:param (input):
    ray test ray.

Remark:
    If the ray's direction vector is a unit vector, the projected
    parameters are physical distances.

Remark:
    If the ray's direction vector is NOT a unit vector, the projected
    parameters are fractions of the ray's direction vector.

Remark:
    If the CurveVector has no curves, the returned range returns true
    on the DRange1d::IsNull() predicate.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CentroidAreaXY =R"doc(Return the centroid and area of the curve vector as viewed in the xy
plane. return false if the CurveVector is not one of the area types
(union region, parity region, or closed loop)

Remark:
    Union region moments are the simple sum of constituents (i.e
    overlap is not determined)

Remark:
    Parity region moments are signed sum per area, assuming largest is
    outer and all others are inner (subtractive)

:param (output):
    centroid curve centroid

:param (output):
    area area of region.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ComputeSecondMomentWireProducts =R"doc(Return the area, centroid, orientation, and principal moments,
treating this as a wire

:param (output):
    products integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y z 1]
    dA)doc";

static const char * __doc_Bentley_Geom_CurveVector_ComputeSecondMomentDifferentialWireRotationProducts =R"doc(Return the moment products [xx,xy,xz,xw; etc] of the wire as a
differential rotational contribution

:param (input):
    rotationAxis the origin and z axis of the rotation.

:param (output):
    rotationToWorld transformation from rotation system (origin on
    rotation axis) to world. The products are base don local
    coordinates in the system.

:param (output):
    products products in the rotation system.

:returns:
    false if invalid area for rotational sweep.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ComputeSecondMomentDifferentialAreaRotationProducts =R"doc(Return the moment products [xx,xy,xz,xw; etc] of the area as a
differential rotational slice.

:param (input):
    rotationAxis the origin and z axis of the rotation.

:param (output):
    rotationToWorld transformation from rotation system (origin on
    rotation axis) to world. The products are base don local
    coordinates in the system.

:param (output):
    products products in the rotation system.

:returns:
    false if invalid area for rotational sweep.)doc";

static const char * __doc_Bentley_Geom_CurveVector_ComputeSecondMomentAreaProducts =R"doc(Return the area, centroid, orientation, and principal moments,
treating this as a thin planar sheet.

:param (output):
    products integrated [xx xy xz x; xy yy yz y; xz yz zz z; x y z 1]
    dA)doc";

static const char * __doc_Bentley_Geom_CurveVector_CentroidNormalArea =R"doc(Return the centroid, normal and area of the curve vector. return false
if the CurveVector is not one of the area types (union region, parity
region, or closed loop)

Remark:
    Union region moments are the simple sum of constituents (i.e
    overlap is not determined)

Remark:
    Parity region moments are signed sum per area, assuming largest is
    outer and all others are inner (subtractive)

Remark:
    If curves are non-planar, the centroid and normal are
    approximations with no particular guarantees.

:param (output):
    centroid curve centroid

:param (output):
    normal curve normal

:param (output):
    area area of region.)doc";

static const char * __doc_Bentley_Geom_CurveVector_WireCentroid =R"doc(Return the centroid of the contained curves, considered as wires.
(Isolated points are not considered.) (Bounded area centroids are not
computed. The boundary curves are used as wires.) return false if no
curves are found.

:param (output):
    length curve length

:param (output):
    centroid curve centroid)doc";

static const char * __doc_Bentley_Geom_CurveVector_AppendSplitCurvesByPlane =R"doc(Return curves (not regions) that are below, above, and on a plane)doc";

static const char * __doc_Bentley_Geom_CurveVector_AppendSplitCurvesByRegion =R"doc(Return curves (not regions) that are inside, outside, or on a region.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CountPrimitivesOfType =R"doc(Count primitives of specified type.

:param (input):
    targetType primitive type to count.)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreaOffset =R"doc(return a (deep) clone with all areas increased or decreased according
to the offset distance.

Remark:
    A positive offset is to the right of the curve (i.e. CCW outer
    loop offsets to a larger area))doc";

static const char * __doc_Bentley_Geom_CurveVector_Add =R"doc(add single curve primitive)doc";

static const char * __doc_Bentley_Geom_CurveVector_AddPrimitives =R"doc(recurse through source. append all leaf primitives to this. Return
number added.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneWithExplodedLinestrings =R"doc(Return a curve vector that is a clone, but with all polylines split
into individual line segments.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneWithSplits =R"doc(Return a curve vector that is a clone, but with all primitives split
at intersections with any splitter curve. Optionally omit tree
structure and only copy primitives.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneOffsetCurvesXY =R"doc(return a (deep) clone with all curves offset by signed distance. This
is a curve operation, and may result in self-intersecting offset
curves.

Remark:
    A positive offset is to the right of the curve (i.e. CCW outer
    loop offsets to a larger area))doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneWithBlends =R"doc(return a (deep) clone with fillets inserted between successive curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneWithGapsClosed =R"doc(return a (deep) clone with endpoint gaps closed. When gaps are found
larger than gapTolerance, line segments are added. The options that
will be used are:1) options.SetEqualPointTolerance(value):Gaps
smaller than this are acceptable. This Suggested value:around 1e-7 in
master units. 2) options.SetMaxDirectAdjustTolerance:gaps this small
may be closed by directly moving endopints of lines or linestrings.
SuggestedValue:10 to 1000 times the equal point tolerance 3)
options.SetRemovePriorGapPrimitives(true):primitives marked as gaps
are purged. (And the gaps are re-closed) Suggested value:true.
(default is true) 4) options.SetMaxAdjustAlongPrimitive:points may
move this far if the final point is on the extended element.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneWithFillets =R"doc(return a (deep) clone with fillets inserted between successive curves.)doc";

static const char * __doc_Bentley_Geom_CurveVector_CloneDereferenced =R"doc(Return a " deep copy " with PartialCurve primitives replaced by full
curves.

:param (input):
    maximumDeref true to recurse through all steps of PartialCurve
    chains

:param (input):
    allowExtrapolation true to allow extension before/after endpoints.)doc";

static const char * __doc_Bentley_Geom_CurveVector_Clone =R"doc(Return a " deep copy ")doc";

static const char * __doc_Bentley_Geom_CurveVector_SwapContents =R"doc(Swap bvectors and type.)doc";

static const char * __doc_Bentley_Geom_CurveVector_SwapAt =R"doc(Swap the entries at given indices. Return false if either index is out
of bounds.)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsRectangle =R"doc(Query:Is this a rectangle?

:param (output):
    localToWorld transform with origin at start, x and y vectors to
    adjacent points, z vector unit normal. (i.e. the x and y vector
    lengths are the side lengths)

:param (output):
    worldToLocal transform to map rectangle to 0..1 in each direction.)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsPhysicallyClosedPath =R"doc(Query:Is this a nominally open path but with matching start and end?)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsEllipticDisk =R"doc(Query:Is this an outer loop with an ellipse as its only curve?)doc";

static const char * __doc_Bentley_Geom_CurveVector_AreStartEndAlmostEqual =R"doc(Query:Does this have start and end points and are the points almost
equal?)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsAnyRegionType =R"doc(Query:is this any closed area type (single, parity, union))doc";

static const char * __doc_Bentley_Geom_CurveVector_IsUnionRegion =R"doc(Query:is this a collection of areas with union rules?)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsParityRegion =R"doc(Query:Is this a collection of loops with parity rules?)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsClosedPath =R"doc(Query:Is this (single) closed path?)doc";

static const char * __doc_Bentley_Geom_CurveVector_IsOpenPath =R"doc(Query:Is this an open path?)doc";

static const char * __doc_Bentley_Geom_CurveVector_GetBoundaryType =R"doc(Return the type code indicating whether the vector is a path, outer
boundary, inner boundary, or higher level grouping.)doc";

static const char * __doc_Bentley_Geom_CurveVector_HasSingleCurvePrimitive =R"doc(Return true if the curve vector has a single element and that element
is a primitive.)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CurveVector(py::module_& m)
    {
    //===================================================================================
    // struct CurveVector
    py::class_<CurveVector, CurveVectorPtr/*, ICurvePrimitiveArray*/> c1(m, "CurveVector", py::multiple_inheritance());
    py::bind_vector< CurveVectorArray >(m, "CurveVectorPtrArray", py::module_local(false));

    if (true)
        {
        py::enum_<CurveVector::BoundaryType>(c1, "BoundaryType", py::arithmetic())
            .value("eBOUNDARY_TYPE_None", CurveVector::BOUNDARY_TYPE_None)
            .value("eBOUNDARY_TYPE_Open", CurveVector::BOUNDARY_TYPE_Open)
            .value("eBOUNDARY_TYPE_Outer", CurveVector::BOUNDARY_TYPE_Outer)
            .value("eBOUNDARY_TYPE_Inner", CurveVector::BOUNDARY_TYPE_Inner)
            .value("eBOUNDARY_TYPE_ParityRegion", CurveVector::BOUNDARY_TYPE_ParityRegion)
            .value("eBOUNDARY_TYPE_UnionRegion", CurveVector::BOUNDARY_TYPE_UnionRegion)
            .export_values();

        py::enum_<CurveVector::InOutClassification>(c1, "InOutClassification", py::arithmetic())
            .value("eINOUT_Unknown", CurveVector::INOUT_Unknown)
            .value("eINOUT_In", CurveVector::INOUT_In)
            .value("eINOUT_Out", CurveVector::INOUT_Out)
            .value("eINOUT_On", CurveVector::INOUT_On)
            .export_values();
        }

    c1.def(py::init(py::overload_cast<CurveVector::BoundaryType>(&CurveVector::Create)), "boundaryType"_a);
    c1.def(py::init(py::overload_cast<CurveVector::BoundaryType, ICurvePrimitivePtr>(&CurveVector::Create)), "boundaryType"_a, "primitive"_a);
    c1.def(py::init(py::overload_cast<DSegment3dArray const&>(&CurveVector::Create)), "segments"_a);
    
    c1.def(py::init([](py::list const& segments){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(segments, cppSegments, DSegment3dArray, DSegment3d);
        return CurveVector::Create(cppSegments);
    }), "segments"_a);
    
    c1.def(py::init(py::overload_cast<ICurvePrimitivePtr, CurveVector::BoundaryType>(&CurveVector::Create)), "child"_a, "boundaryType"_a);

    c1.def("HasSingleCurvePrimitive", &CurveVector::HasSingleCurvePrimitive, DOC(Bentley, Geom, CurveVector, HasSingleCurvePrimitive));
    
    c1.def_property_readonly("BoundaryType", &CurveVector::GetBoundaryType);
    c1.def("GetBoundaryType", &CurveVector::GetBoundaryType, DOC(Bentley, Geom, CurveVector, GetBoundaryType));
    
    c1.def("IsOpenPath", &CurveVector::IsOpenPath, DOC(Bentley, Geom, CurveVector, IsOpenPath));
    c1.def("IsClosedPath", &CurveVector::IsClosedPath, DOC(Bentley, Geom, CurveVector, IsClosedPath));
    c1.def("IsParityRegion", &CurveVector::IsParityRegion, DOC(Bentley, Geom, CurveVector, IsParityRegion));
    c1.def("IsUnionRegion", &CurveVector::IsUnionRegion, DOC(Bentley, Geom, CurveVector, IsUnionRegion));
    c1.def("IsAnyRegionType", &CurveVector::IsAnyRegionType, DOC(Bentley, Geom, CurveVector, IsAnyRegionType));
    c1.def("AreStartEndAlmostEqual", &CurveVector::AreStartEndAlmostEqual, DOC(Bentley, Geom, CurveVector, AreStartEndAlmostEqual));
    c1.def("IsEllipticDisk", &CurveVector::IsEllipticDisk, "ellipse"_a, DOC(Bentley, Geom, CurveVector, IsEllipticDisk));
    c1.def("IsPhysicallyClosedPath", &CurveVector::IsPhysicallyClosedPath, DOC(Bentley, Geom, CurveVector, IsPhysicallyClosedPath));
    c1.def("IsRectangle", &CurveVector::IsRectangle, "localToWorld"_a, "worldToLocal"_a, DOC(Bentley, Geom, CurveVector, IsRectangle));

    c1.def("SwapAt", &CurveVector::SwapAt, "index0"_a, "index1"_a, DOC(Bentley, Geom, CurveVector, SwapAt));
    c1.def("SwapContents", &CurveVector::SwapContents, "other"_a, DOC(Bentley, Geom, CurveVector, SwapContents));

    c1.def("Clone", &CurveVector::Clone, DOC(Bentley, Geom, CurveVector, Clone));
    c1.def("CloneDereferenced", &CurveVector::CloneDereferenced, "allowExtrapolation"_a = false, "maximumDeref"_a = true, DOC(Bentley, Geom, CurveVector, CloneDereferenced));
    c1.def("CloneWithFillets", &CurveVector::CloneWithFillets, "radius"_a, DOC(Bentley, Geom, CurveVector, CloneWithFillets));
    c1.def("CloneWithGapsClosed", &CurveVector::CloneWithGapsClosed, "options"_a, DOC(Bentley, Geom, CurveVector, CloneWithGapsClosed));

    c1.def("CloneWithBlends", [] (CurveVectorCR self, BlendType blendType, double radiusA, double radiusB)
        {
        return self.CloneWithBlends(blendType, radiusA, radiusB);
        }, "blendType"_a, "radiusA"_a, "radiusB"_a, DOC(Bentley, Geom, CurveVector, CloneWithBlends));

    c1.def("CloneOffsetCurvesXY", &CurveVector::CloneOffsetCurvesXY, "options"_a, DOC(Bentley, Geom, CurveVector, CloneOffsetCurvesXY));
    c1.def("CloneWithSplits", &CurveVector::CloneWithSplits, "splitterCurves"_a, "primitivesOnly"_a = false, DOC(Bentley, Geom, CurveVector, CloneWithSplits));
    c1.def("CloneWithExplodedLinestrings", &CurveVector::CloneWithExplodedLinestrings, DOC(Bentley, Geom, CurveVector, CloneWithExplodedLinestrings));

    c1.def("AddPrimitives", &CurveVector::AddPrimitives, "source"_a, DOC(Bentley, Geom, CurveVector, AddPrimitives));
    c1.def("Add", py::overload_cast<ICurvePrimitivePtr>(&CurveVector::Add), "child"_a, DOC(Bentley, Geom, CurveVector, Add));
    c1.def("Add", py::overload_cast<CurveVectorPtr>(&CurveVector::Add), "child"_a, DOC(Bentley, Geom, CurveVector, Add));    
    
    c1.def("AreaOffset", &CurveVector::AreaOffset, "options"_a, DOC(Bentley, Geom, CurveVector, AreaOffset));
    c1.def("CountPrimitivesOfType", &CurveVector::CountPrimitivesOfType, "targetType"_a, DOC(Bentley, Geom, CurveVector, CountPrimitivesOfType));
    
    c1.def("AppendSplitCurvesByRegion", &CurveVector::AppendSplitCurvesByRegion, "region"_a, "insideCollector"_a, "outsideCollector"_a, "onCollector"_a, DOC(Bentley, Geom, CurveVector, AppendSplitCurvesByRegion));            
    c1.def("AppendSplitCurvesByPlane", &CurveVector::AppendSplitCurvesByPlane, "plane"_a, "belowCollector"_a, "aboveCollector"_a, "onCollector"_a, DOC(Bentley, Geom, CurveVector, AppendSplitCurvesByPlane));    

    c1.def("WireCentroid", [] (CurveVectorCR self)
        {
        double len = 0.0;
        DPoint3d centroid = DPoint3d::FromZero();
        bool bOk = self.WireCentroid(len, centroid);
        return py::make_tuple(bOk, len, centroid);
        }, DOC(Bentley, Geom, CurveVector, WireCentroid));

    c1.def("CentroidNormalArea", [] (CurveVectorCR self)
        {
        double area = 0.0;
        DPoint3d centroid = DPoint3d::FromZero();
        DVec3d normal = DVec3d::FromZero();
        bool bOk = self.CentroidNormalArea(centroid, normal, area);
        return  py::make_tuple(bOk, centroid, normal, area);
        }, DOC(Bentley, Geom, CurveVector, CentroidNormalArea));
    
    c1.def("ComputeSecondMomentAreaProducts", &CurveVector::ComputeSecondMomentAreaProducts, "products"_a, DOC(Bentley, Geom, CurveVector, ComputeSecondMomentAreaProducts));
    c1.def("ComputeSecondMomentDifferentialAreaRotationProducts", &CurveVector::ComputeSecondMomentDifferentialAreaRotationProducts, "rotationAxis"_a, "rotationToWorld"_a, "products"_a, DOC(Bentley, Geom, CurveVector, ComputeSecondMomentDifferentialAreaRotationProducts));
    c1.def("ComputeSecondMomentDifferentialWireRotationProducts", &CurveVector::ComputeSecondMomentDifferentialWireRotationProducts, "rotationAxis"_a, "rotationToWorld"_a, "products"_a, DOC(Bentley, Geom, CurveVector, ComputeSecondMomentDifferentialWireRotationProducts));
    c1.def("ComputeSecondMomentWireProducts", &CurveVector::ComputeSecondMomentWireProducts, "products"_a, DOC(Bentley, Geom, CurveVector, ComputeSecondMomentWireProducts));

    c1.def("CentroidAreaXY", [] (CurveVectorCR self)
        {
        DPoint3d centroid = DPoint3d::FromZero();
        double area = 0.0;
        bool bOk = self.CentroidAreaXY(centroid, area);
        return py::make_tuple(bOk, centroid, area);
        }, DOC(Bentley, Geom, CurveVector, CentroidAreaXY));
    
    c1.def("ProjectedParameterRange", &CurveVector::ProjectedParameterRange, "ray"_a, DOC(Bentley, Geom, CurveVector, ProjectedParameterRange));
    c1.def("CloneInLocalCoordinates", &CurveVector::CloneInLocalCoordinates, "rameType"_a, "localToWorld"_a, "worldToLocal"_a, "localRange"_a, DOC(Bentley, Geom, CurveVector, CloneInLocalCoordinates));
    c1.def("GetAnyFrenetFrame", py::overload_cast<TransformR>(&CurveVector::GetAnyFrenetFrame, py::const_), "frame"_a, DOC(Bentley, Geom, CurveVector, GetAnyFrenetFrame));
    c1.def("GetAnyFrenetFrame", py::overload_cast<TransformR, int>(&CurveVector::GetAnyFrenetFrame, py::const_), "frame"_a, "searchPreference"_a, DOC(Bentley, Geom, CurveVector, GetAnyFrenetFrame));
    c1.def("TryUVFractionToXYZ", &CurveVector::TryUVFractionToXYZ, "uFraction"_a, "vFraction"_a, "xyz"_a, "dXdu"_a, "dXdv"_a, DOC(Bentley, Geom, CurveVector, TryUVFractionToXYZ));

    c1.def_static("CreateLinear", 
                  py::overload_cast<DPoint3dArray const&, CurveVector::BoundaryType, bool>(&CurveVector::CreateLinear), 
                  "points"_a, "boundaryType"_a = CurveVector::BOUNDARY_TYPE_Open, "forceXYOrientation"_a = false, DOC(Bentley, Geom, CurveVector, CreateLinear));

    c1.def_static("CreateLinear", [] (py::list const &points, CurveVector::BoundaryType boundaryType, bool forceXYOrientation) 
    {
        if (points.empty()) {
            return CurveVector::CreateLinear((DPoint3d*)NULL, 0, boundaryType, forceXYOrientation);
        }
            
        py::object first = points[0];
        if (py::isinstance<DPoint2d>(first)) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint2dArray, DPoint2d);
            return CurveVector::CreateLinear(&cpppoints[0], cpppoints.size(), boundaryType, forceXYOrientation);
        } else if (py::isinstance<DPoint3d>(first)) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint3dArray, DPoint3d);
            return CurveVector::CreateLinear(cpppoints, boundaryType, forceXYOrientation);
        } else {
            throw std::invalid_argument("Unsupported point type in list. Expected DPoint2d or DPoint3d.");
        }
        }, "points"_a, "boundaryType"_a = CurveVector::BOUNDARY_TYPE_Open, "forceXYOrientation"_a = false, DOC(Bentley, Geom, CurveVector, CreateLinear));

    c1.def_static("CreateLinear", [] (DPoint2dArray const& points, CurveVector::BoundaryType boundaryType, bool forceXYOrientation)
        {
        return CurveVector::CreateLinear(&points[0], points.size(), boundaryType, forceXYOrientation);
        }, "points"_a, "boundaryType"_a = CurveVector::BOUNDARY_TYPE_Open, "forceXYOrientation"_a = false, DOC(Bentley, Geom, CurveVector, CreateLinear));
            
    c1.def_static("CreateRectangle", &CurveVector::CreateRectangle, "x0"_a, "y0"_a, "x1"_a, "y1"_a, "z"_a, "boundaryType"_a = CurveVector::BOUNDARY_TYPE_Outer, DOC(Bentley, Geom, CurveVector, CreateRectangle));
    
    c1.def_static("CreateRegularPolygonXY", &CurveVector::CreateRegularPolygonXY, "center"_a, "xDistance"_a, "numEdge"_a, "isOuterRadius"_a, "boundaryType"_a = CurveVector::BOUNDARY_TYPE_Outer);

    c1.def_static("CreateDisk", &CurveVector::CreateDisk, "arc"_a, "boundaryType"_a = CurveVector::BOUNDARY_TYPE_Outer, "forceXYOrientation"_a = false, DOC(Bentley, Geom, CurveVector, CreateDisk));
    c1.def("CloneAsBsplines", &CurveVector::CloneAsBsplines, DOC(Bentley, Geom, CurveVector, CloneAsBsplines));

    c1.def("Stroke", &CurveVector::Stroke, "options"_a, DOC(Bentley, Geom, CurveVector, Stroke));
    c1.def("AddStrokePoints", &CurveVector::AddStrokePoints, "points"_a, "options"_a, DOC(Bentley, Geom, CurveVector, AddStrokePoints));

    c1.def("CollectLinearGeometry",
        py::overload_cast<bvector<bvector<bvector<DPoint3d>>>&>(&CurveVector::CollectLinearGeometry, py::const_),
        "regionsPoints"_a, DOC(Bentley, Geom, CurveVector, CollectLinearGeometry));

    c1.def("CollectLinearGeometry",
        py::overload_cast<bvector<bvector<bvector<DPoint3d>>>&, IFacetOptionsP>(&CurveVector::CollectLinearGeometry, py::const_),
        "regionsPoints"_a, "strokeOptions"_a, DOC(Bentley, Geom, CurveVector, CollectLinearGeometry));

    c1.def("CollectLinearGeometry",
        py::overload_cast<bvector<bvector<DPoint3d>>&, IFacetOptionsP>(&CurveVector::CollectLinearGeometry, py::const_),
        "regionsPoints"_a, "strokeOptions"_a = nullptr, DOC(Bentley, Geom, CurveVector, CollectLinearGeometry));

    c1.def("AddSpacedPoints", &CurveVector::AddSpacedPoints, "distances"_a, "locations"_a, DOC(Bentley, Geom, CurveVector, AddSpacedPoints));
    c1.def("ToBsplineCurve", &CurveVector::ToBsplineCurve, "curve"_a, DOC(Bentley, Geom, CurveVector, ToBsplineCurve));
    c1.def("GetBsplineCurve", &CurveVector::GetBsplineCurve, DOC(Bentley, Geom, CurveVector, GetBsplineCurve));

    c1.def("ClosestPointBounded", py::overload_cast<DPoint3dCR, CurveLocationDetailR>(&CurveVector::ClosestPointBounded, py::const_), "spacePoint"_a, "location"_a, DOC(Bentley, Geom, CurveVector, ClosestPointBounded));
    c1.def("ClosestPointBounded", py::overload_cast<DPoint3dCR, CurveLocationDetailR, bool, bool>(&CurveVector::ClosestPointBounded, py::const_), "spacePoint"_a, "location"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, CurveVector, ClosestPointBounded));
    c1.def("ClosestPointBoundedXY", py::overload_cast<DPoint3dCR, DMatrix4dCP, CurveLocationDetailR>(&CurveVector::ClosestPointBoundedXY, py::const_), "spacePoint"_a, "worldToLocal"_a, "location"_a, DOC(Bentley, Geom, CurveVector, ClosestPointBoundedXY));
    c1.def("ClosestPointBoundedXY", py::overload_cast<DPoint3dCR, DMatrix4dCP, CurveLocationDetailR, bool, bool>(&CurveVector::ClosestPointBoundedXY, py::const_), "spacePoint"_a, "worldToLocal"_a, "location"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, CurveVector, ClosestPointBoundedXY));            
    c1.def("ClosestCurveOrRegionPoint", &CurveVector::ClosestCurveOrRegionPoint, "spacePoint"_a, "curveOrRegionPoint"_a, DOC(Bentley, Geom, CurveVector, ClosestCurveOrRegionPoint));

    c1.def("AnnounceKeyPoints", &CurveVector::AnnounceKeyPoints, "spacePoint"_a, "collector"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, CurveVector, AnnounceKeyPoints));

    c1.def("GetStartEnd", py::overload_cast<DPoint3dR, DPoint3dR>(&CurveVector::GetStartEnd, py::const_), "pointA"_a, "pointB"_a, DOC(Bentley, Geom, CurveVector, GetStartEnd));
    c1.def("GetStartEnd", py::overload_cast<DPoint3dR, DPoint3dR, DVec3dR, DVec3dR>(&CurveVector::GetStartEnd, py::const_), "pointA"_a, "pointB"_a, "unitTangentA"_a, "unitTangentB"_a, DOC(Bentley, Geom, CurveVector, GetStartEnd));
    c1.def("GetStartPoint", &CurveVector::GetStartPoint, "point"_a, DOC(Bentley, Geom, CurveVector, GetStartPoint));

    c1.def("Length", py::overload_cast<>(&CurveVector::Length, py::const_), DOC(Bentley, Geom, CurveVector, Length));
    c1.def("Length", py::overload_cast<RotMatrixCP>(&CurveVector::Length, py::const_), "worldToLocal"_a, DOC(Bentley, Geom, CurveVector, Length));
    c1.def("FastLength", &CurveVector::FastLength, DOC(Bentley, Geom, CurveVector, FastLength));

    c1.def("MaxGapWithinPath", &CurveVector::MaxGapWithinPath, DOC(Bentley, Geom, CurveVector, MaxGapWithinPath));
    c1.def("FastMaxAbs", &CurveVector::FastMaxAbs, DOC(Bentley, Geom, CurveVector, FastMaxAbs));
    c1.def("IsSameStructure", &CurveVector::IsSameStructure, "other"_a, DOC(Bentley, Geom, CurveVector, IsSameStructure));
    c1.def("IsSameStructureAndGeometry", &CurveVector::IsSameStructureAndGeometry, "other"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, CurveVector, IsSameStructureAndGeometry));

    c1.def("GetRange", py::overload_cast<DRange3dR>(&CurveVector::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, CurveVector, GetRange));
    c1.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&CurveVector::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, CurveVector, GetRange));
            
    c1.def("IsPlanar", &CurveVector::IsPlanar, "localToWorld"_a, "worldToLocal"_a, "range"_a, DOC(Bentley, Geom, CurveVector, IsPlanar));
    c1.def("IsPlanarWithDefaultNormal", &CurveVector::IsPlanarWithDefaultNormal, "localToWorld"_a, "worldToLocal"_a, "range"_a, "normal"_a, DOC(Bentley, Geom, CurveVector, IsPlanarWithDefaultNormal));

    c1.def("CyclicIndex", &CurveVector::CyclicIndex, "index"_a, DOC(Bentley, Geom, CurveVector, CyclicIndex));            
    c1.def("GetCyclic", &CurveVector::GetCyclic, "index"_a, DOC(Bentley, Geom, CurveVector, GetCyclic));

    c1.def("CurveLocationDetailIndex", &CurveVector::CurveLocationDetailIndex, "location"_a, DOC(Bentley, Geom, CurveVector, CurveLocationDetailIndex));
    c1.def("FindIndexOfPrimitive", &CurveVector::FindIndexOfPrimitive, "primitive"_a, DOC(Bentley, Geom, CurveVector, FindIndexOfPrimitive));
    c1.def("FindParentOfPrimitive", &CurveVector::FindParentOfPrimitive, "primitive"_a, DOC(Bentley, Geom, CurveVector, FindParentOfPrimitive));
    c1.def("CurveLocationDetailCompare", &CurveVector::CurveLocationDetailCompare, "location0"_a, "location1"_a, DOC(Bentley, Geom, CurveVector, CurveLocationDetailCompare));
    c1.def("ResolveTolerance", &CurveVector::ResolveTolerance, "tolerance"_a, DOC(Bentley, Geom, CurveVector, ResolveTolerance));    

    c1.def("CloneBetweenCyclicIndexedFractions", &CurveVector::CloneBetweenCyclicIndexedFractions, "index0"_a, "fraction0"_a, "index1"_a, "fraction1"_a, DOC(Bentley, Geom, CurveVector, CloneBetweenCyclicIndexedFractions));

    c1.def("CloneBetweenDirectedFractions", py::overload_cast<int, double, int, double, bool, bool>(&CurveVector::CloneBetweenDirectedFractions, py::const_),
        "index0"_a, "fraction0"_a, "index1"_a, "fraction1"_a, "allowExtrapolation"_a, "usePartialCurves"_a = false, DOC(Bentley, Geom, CurveVector, CloneBetweenDirectedFractions));
    c1.def("CloneBetweenDirectedFractions", py::overload_cast<CurveLocationDetailCR, CurveLocationDetailCR, bool, bool>(&CurveVector::CloneBetweenDirectedFractions, py::const_),
        "location0"_a, "location1"_a, "allowExtrapolation"_a = false, "usePartialCurves"_a = false, DOC(Bentley, Geom, CurveVector, CloneBetweenDirectedFractions));

    
    c1.def("CloneReversed", &CurveVector::CloneReversed, DOC(Bentley, Geom, CurveVector, CloneReversed));

    c1.def("GenerateAllParts", &CurveVector::GenerateAllParts, "indexA"_a, "fractionA"_a, "indexB"_a, "fractionB"_a, DOC(Bentley, Geom, CurveVector, GenerateAllParts));
    c1.def("ContainsNonLinearPrimitive", &CurveVector::ContainsNonLinearPrimitive, DOC(Bentley, Geom, CurveVector, ContainsNonLinearPrimitive));

    c1.def("AppendCurvePlaneIntersections", &CurveVector::AppendCurvePlaneIntersections, "plane"_a, "intersections"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, CurveVector, AppendCurvePlaneIntersections));
    c1.def("AppendClosedCurvePlaneIntersections", &CurveVector::AppendClosedCurvePlaneIntersections, "plane"_a, "intersections"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, CurveVector, AppendClosedCurvePlaneIntersections));

    c1.def("PlaneSection", &CurveVector::PlaneSection, "plane"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, CurveVector, PlaneSection));
    c1.def("PointInOnOutXY", &CurveVector::PointInOnOutXY, "xyz"_a, DOC(Bentley, Geom, CurveVector, PointInOnOutXY));
    c1.def("RayPierceInOnOut", &CurveVector::RayPierceInOnOut, "ray"_a, "hitDetail"_a, DOC(Bentley, Geom, CurveVector, RayPierceInOnOut));
    c1.def("TransformInPlace", &CurveVector::TransformInPlace, "transform"_a, DOC(Bentley, Geom, CurveVector, TransformInPlace));
    c1.def("ReverseCurvesInPlace", &CurveVector::ReverseCurvesInPlace, DOC(Bentley, Geom, CurveVector, ReverseCurvesInPlace));

    c1.def("ConsolidateAdjacentPrimitives", py::overload_cast<>(&CurveVector::ConsolidateAdjacentPrimitives), DOC(Bentley, Geom, CurveVector, ConsolidateAdjacentPrimitives));
    c1.def("ConsolidateAdjacentPrimitives", py::overload_cast<bool>(&CurveVector::ConsolidateAdjacentPrimitives), "doSimplifyLinestrings"_a, DOC(Bentley, Geom, CurveVector, ConsolidateAdjacentPrimitives));

    c1.def("SimplifyLinestrings", &CurveVector::SimplifyLinestrings, "distanceTol"_a, "eliminateOverdraw"_a, "wrap"_a, DOC(Bentley, Geom, CurveVector, SimplifyLinestrings));
    c1.def("FixupXYOuterInner", &CurveVector::FixupXYOuterInner, "fullGeometryCheck"_a = false, DOC(Bentley, Geom, CurveVector, FixupXYOuterInner));
    c1.def("ReorderForSmallGaps", &CurveVector::ReorderForSmallGaps, DOC(Bentley, Geom, CurveVector, ReorderForSmallGaps));
    c1.def("AssembleChains", &CurveVector::AssembleChains, DOC(Bentley, Geom, CurveVector, AssembleChains));

    c1.def("FlattenNestedUnionRegions", &CurveVector::FlattenNestedUnionRegions);
    c1.def("HasNestedUnionRegion", &CurveVector::HasNestedUnionRegion);

    c1.def_static("AreaUnion", &CurveVector::AreaUnion, "regionA"_a, "regionB"_a, "newToOld"_a = nullptr, DOC(Bentley, Geom, CurveVector, AreaUnion));
    c1.def_static("AreaDifference", &CurveVector::AreaDifference, "regionA"_a, "regionB"_a, "newToOld"_a = nullptr, DOC(Bentley, Geom, CurveVector, AreaDifference));
    c1.def_static("AreaIntersection", &CurveVector::AreaIntersection, "regionA"_a, "regionB"_a, "newToOld"_a = nullptr, DOC(Bentley, Geom, CurveVector, AreaIntersection));
    c1.def_static("AreaParity", &CurveVector::AreaParity, "regionA"_a, "regionB"_a, "newToOld"_a = nullptr, DOC(Bentley, Geom, CurveVector, AreaParity));
    c1.def_static("AreaAnalysis", &CurveVector::AreaAnalysis, "region"_a, "select1"_a, "select2"_a, "reverse"_a, DOC(Bentley, Geom, CurveVector, AreaAnalysis));

    c1.def_static("ReduceToCCWAreas", &CurveVector::ReduceToCCWAreas, "regionA"_a, DOC(Bentley, Geom, CurveVector, ReduceToCCWAreas));
    c1.def_static("CreateXYHatch", &CurveVector::CreateXYHatch, "boundary"_a, "startPoint"_a, "angleRadians"_a, "spacing"_a, "selection"_a = 0, DOC(Bentley, Geom, CurveVector, CreateXYHatch));

    c1.def("__repr__", [] (CurveVector& self)
           {
           DPoint3d startPnt, endPnt;
           self.GetStartEnd(startPnt, endPnt);

           return "(BoundaryType:{}, NumCurves:{}, Length:{}, Start:{}, End:{})"_s
               .format(self.GetBoundaryType(), self.size(), self.Length(), startPnt, endPnt);
           });

    c1.def("__len__", &CurveVector::size);
    c1.def("__iter__", [] (CurveVector& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());
    c1.def("__getitem__", [] (CurveVector const& self, size_t index)
           {
           if (index >= self.size())
               throw py::index_error();

           return self[index];
           }, py::keep_alive<0, 1>());

    c1.def("__setitem__", [] (CurveVector& self, size_t index, ICurvePrimitiveP value)
           {
           if (index >= self.size())
               throw py::index_error();

           self[index] = ICurvePrimitivePtr(value);
           });

    //===================================================================================
    // struct CurveCurve
    py::class_<CurveCurve> c2(m, "CurveCurve");

    if (true)
        {
        //===================================================================================
        // struct FilletDetail
        py::class_<CurveCurve::FilletDetail> c2_1(c2, "FilletDetail");
        py::bind_vector< FilletDetailArray >(m, "FilletDetailArray", py::module_local(false));

        c2_1.def_readwrite("detailA", &CurveCurve::FilletDetail::detailA);
        c2_1.def_readwrite("detailB", &CurveCurve::FilletDetail::detailB);
        c2_1.def_readwrite("arc", &CurveCurve::FilletDetail::arc);
        c2_1.def("__repr__", [] (CurveCurve::FilletDetail& self) { return "(detailA:{}, detailB:{}, arc:{})"_s.format(self.detailA, self.detailB, self.arc); });
        }
    
    c2.def_static("IntersectionsXY", 
                  py::overload_cast<CurveVectorR, CurveVectorR, CurveVectorR, CurveVectorR, DMatrix4dCP>(&CurveCurve::IntersectionsXY), 
                  "intersectionA"_a, "intersectionB"_a, "curveA"_a, "curveB"_a, "pWorldToLocal"_a);

    c2.def_static("IntersectionsXY",
                  py::overload_cast<CurveVectorR, CurveVectorR, ICurvePrimitiveP, ICurvePrimitiveP, DMatrix4dCP, bool>(&CurveCurve::IntersectionsXY),
                  "intersectionA"_a, "intersectionB"_a, "curveA"_a, "curveB"_a, "pWorldToLocal"_a, "extend"_a = false);

    c2.def_static("IntersectionsXY",
                  py::overload_cast<CurveVectorR, CurveVectorR, ICurvePrimitiveR, CurveVectorR, DMatrix4dCP>(&CurveCurve::IntersectionsXY),
                  "intersectionA"_a, "intersectionB"_a, "curveA"_a, "curveB"_a, "pWorldToLocal"_a);

    c2.def_static("IntersectionsXY",
        py::overload_cast<CurveVectorR, CurveVectorR, ICurvePrimitiveP, ICurvePrimitiveP, DMatrix4dCP, bool, bool, bool, bool>(&CurveCurve::IntersectionsXY),
        "intersectionA"_a, "intersectionB"_a, "curveA"_a, "curveB"_a, "pWorldToLocal"_a, "extendA0"_a, "extendA1"_a, "extendB0"_a, "extendB1"_a);

    c2.def_static("CloseApproach", 
                  py::overload_cast<CurveVectorR, CurveVectorR, ICurvePrimitiveP, ICurvePrimitiveP, double>(&CurveCurve::CloseApproach),
                  "pointsOnA"_a, "pointsOnB"_a, "curveA"_a, "curveB"_a, "maxDist"_a = DBL_MAX);

    c2.def_static("ClosestApproachNewton", [] (ICurvePrimitiveCR curveA, ICurvePrimitiveCR curveB)
        {
        double fractionA = 0.0;
        double fractionB = 0.0;
        DPoint3d xyzA = DPoint3d::FromZero();
        DPoint3d xyzB = DPoint3d::FromZero();
        bool bOK = CurveCurve::ClosestApproachNewton(curveA, curveB, fractionA, fractionB, xyzA, xyzB);
        return py::make_tuple(bOK, fractionA, fractionB, xyzA, xyzB);
        });

    c2.def_static("ClosestApproach",
                  py::overload_cast<CurveLocationDetailR, CurveLocationDetailR, ICurvePrimitiveP, ICurvePrimitiveP>(&CurveCurve::ClosestApproach),
                  "pointOnA"_a, "pointOnB"_a, "curveA"_a, "curveB"_a);

    c2.def_static("ClosestApproach",
                  py::overload_cast<CurveLocationDetailR, CurveLocationDetailR, CurveVectorCR, CurveVectorCR>(&CurveCurve::ClosestApproach),
                  "pointOnA"_a, "pointOnB"_a, "chainA"_a, "chainB"_a);

    c2.def_static("IsSinglePointPair", [] (CurveVectorR intersectionA, CurveVectorR intersectionB, size_t i)
        {
        double fractionA = 0.0;
        double fractionB = 0.0;
        DPoint3d pointA = DPoint3d::FromZero();
        DPoint3d pointB = DPoint3d::FromZero();
        bool bOk = CurveCurve::IsSinglePointPair(intersectionA, intersectionB, i, fractionA, pointA, fractionB, pointB);
        return py::make_tuple(bOk, fractionA, pointA, fractionB, pointB);
        });
    
    c2.def_static("IsSinglePointPair",
                  py::overload_cast<CurveVectorR, CurveVectorR, size_t, CurveLocationDetailR, CurveLocationDetailR>(&CurveCurve::IsSinglePointPair),
                  "intersectionA"_a, "intersectionB"_a, "i"_a, "detailA"_a, "detailB"_a);

    c2.def_static("IsContained", &CurveCurve::IsContained, "intersectionA"_a, "intersectionB"_a, "i"_a, "j"_a, "considerSinglePoints"_a, "considerIntervals"_a, DOC(Bentley, Geom, CurveCurve, IsContained));
    c2.def_static("GetPartialCurveDetailPair", &CurveCurve::GetPartialCurveDetailPair, "intersectionA"_a, "intersectionB"_a, "i"_a, "detailA"_a, "detailB"_a, DOC(Bentley, Geom, CurveCurve, GetPartialCurveDetailPair));

    c2.def_static("CollectFilletArcs", 
                  py::overload_cast<ICurvePrimitiveR, ICurvePrimitiveR, double, bool, FilletDetailArray&>(&CurveCurve::CollectFilletArcs),
                  "curveA"_a, "curveB"_a, "radius"_a, "extend"_a, "arcs"_a);

    c2.def_static("CollectFilletArcs", [](ICurvePrimitiveR curveA, ICurvePrimitiveR curveB, double radius, bool extend, py::list& arcs){
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(arcs, cppArcs, FilletDetailArray, CurveCurve::FilletDetail);
                  CurveCurve::CollectFilletArcs(curveA, curveB, radius, extend, cppArcs);
                  CONVERT_CPPARRAY_TO_PYLIST(arcs, cppArcs, FilletDetailArray, CurveCurve::FilletDetail);
                 }, "curveA"_a, "curveB"_a, "radius"_a, "extend"_a, "arcs"_a);
  
    c2.def_static("CollectFilletArcs",
                  py::overload_cast<CurveVectorCR, CurveVectorCR, double, bool, FilletDetailArray&>(&CurveCurve::CollectFilletArcs),
                  "chainA"_a, "chainB"_a, "radius"_a, "extend"_a, "arcs"_a);

    c2.def_static("CollectFilletArcs", [](CurveVectorCR chainA, CurveVectorCR chainB, double radius, bool extend, py::list &arcs)
                  {
                 CONVERT_PYLIST_TO_NEW_CPPARRAY(arcs, cppArcs, FilletDetailArray, CurveCurve::FilletDetail);
                 CurveCurve::CollectFilletArcs(chainA, chainB, radius, extend, cppArcs);
                 CONVERT_CPPARRAY_TO_PYLIST(arcs, cppArcs, FilletDetailArray, CurveCurve::FilletDetail); }, "chainA"_a, "chainB"_a, "radius"_a, "extend"_a, "arcs"_a);

    c2.def_static("CollectBlends",
                  py::overload_cast<ICurvePrimitiveR, ICurvePrimitiveR, BlendType, double, double, bool, BlendDetailArray&>(&CurveCurve::CollectBlends),
                  "curveA"_a, "curveB"_a, "blendType"_a, "distanceA"_a, "distanceB"_a, "extend"_a, "blendCurves"_a);

    c2.def_static("CollectBlends", [](ICurvePrimitiveR curveA, ICurvePrimitiveR curveB, BlendType blendType, double distanceA, double distanceB, bool extend, py::list &blendCurves)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(blendCurves, cppBlendCurves, BlendDetailArray, BlendDetail);
                  CurveCurve::CollectBlends(curveA, curveB, blendType, distanceA, distanceB, extend, cppBlendCurves);
                  CONVERT_CPPARRAY_TO_PYLIST(blendCurves, cppBlendCurves, BlendDetailArray, BlendDetail); }, "curveA"_a, "curveB"_a, "blendType"_a, "distanceA"_a, "distanceB"_a, "extend"_a, "blendCurves"_a);

    c2.def_static("CollectBlends",
                  py::overload_cast<CurveVectorCR, CurveVectorCR, BlendType, double, double, bool, BlendDetailArray&>(&CurveCurve::CollectBlends),
                  "chainA"_a, "chainB"_a, "blendType"_a, "distanceA"_a, "distanceB"_a, "extend"_a, "blendCurves"_a);

    c2.def_static("CollectBlends", [](CurveVectorCR chainA, CurveVectorCR chainB, BlendType blendType, double distanceA, double distanceB, bool extend, py::list& blendCurves) {
                   CONVERT_PYLIST_TO_NEW_CPPARRAY(blendCurves, cppBlendCurves, BlendDetailArray, BlendDetail);
                   CurveCurve::CollectBlends(chainA, chainB, blendType, distanceA, distanceB, extend, cppBlendCurves);
                   CONVERT_CPPARRAY_TO_PYLIST(blendCurves, cppBlendCurves, BlendDetailArray, BlendDetail); 
                }, "chainA"_a, "chainB"_a, "blendType"_a, "distanceA"_a, "distanceB"_a, "extend"_a, "blendCurves"_a);
                     
    c2.def_static("TransverseRegionIntersectionSegments", &CurveCurve::TransverseRegionIntersectionSegments, "regionA"_a, "regionB"_a, "segments"_a, DOC(Bentley, Geom, CurveCurve, TransverseRegionIntersectionSegments));
    c2.def_static("IntersectRotatedCurveSpaceCurve", &CurveCurve::IntersectRotatedCurveSpaceCurve, "worldToLocal"_a, "rotatedCurve"_a, "spaceCurve"_a, "detailA"_a, "detailB"_a, DOC(Bentley, Geom, CurveCurve, IntersectRotatedCurveSpaceCurve));

   
    //===================================================================================
    // struct PathLocationDetail
    py::class_<PathLocationDetail> c3(m, "PathLocationDetail");

    c3.def(py::init<>());
    c3.def(py::init<PathLocationDetail const&>(), "other"_a);
    c3.def(py::init<CurveLocationDetailCR, int, double>(), "curveDetail"_a, "pathIndex"_a = -1, "distance"_a = DBL_MAX);
    c3.def(py::init<CurveLocationDetailCR, size_t, double>(), "curveDetail"_a, "pathIndex"_a, "distance"_a = DBL_MAX);
    c3.def(py::init<double>(), "distance"_a);

    c3.def("FractionToPositionLocationDetail", &PathLocationDetail::FractionToPositionLocationDetail, "f"_a, "evaluateDistance"_a = true);
    c3.def("Point", &PathLocationDetail::Point, DOC(Bentley, Geom, PathLocationDetail, Point));            
    c3.def("PointAndUnitTangent", &PathLocationDetail::PointAndUnitTangent, "unitTangent"_a, DOC(Bentley, Geom, PathLocationDetail, PointAndUnitTangent));            
    
    c3.def_property_readonly("CurveLocationDetail", &PathLocationDetail::GetCurveLocationDetail);
    c3.def("GetCurveLocationDetail", &PathLocationDetail::GetCurveLocationDetail, DOC(Bentley, Geom, PathLocationDetail, GetCurveLocationDetail));
    
    c3.def("HasCurve", &PathLocationDetail::HasCurve, DOC(Bentley, Geom, PathLocationDetail, HasCurve));
    
    c3.def_property_readonly("PrimitiveIndex", &PathLocationDetail::GetPrimitiveIndex);
    c3.def("GetPrimitiveIndex", &PathLocationDetail::GetPrimitiveIndex, DOC(Bentley, Geom, PathLocationDetail, GetPrimitiveIndex));
    
    c3.def("DistanceToPoint", py::overload_cast<PathLocationDetail const&>(&PathLocationDetail::DistanceToPoint, py::const_), "other"_a, DOC(Bentley, Geom, PathLocationDetail, DistanceToPoint));
    c3.def("DistanceToPoint", py::overload_cast<DPoint3dCR>(&PathLocationDetail::DistanceToPoint, py::const_), "xyz"_a, DOC(Bentley, Geom, PathLocationDetail, DistanceToPoint));            
    c3.def("DistanceSquaredToPoint", &PathLocationDetail::DistanceSquaredToPoint, "xyz"_a, DOC(Bentley, Geom, PathLocationDetail, DistanceSquaredToPoint));            
    c3.def("DistanceFromPathStart", &PathLocationDetail::DistanceFromPathStart, DOC(Bentley, Geom, PathLocationDetail, DistanceFromPathStart));
    c3.def_static("IsLessThan_ByPathDistance", &PathLocationDetail::IsLessThan_ByPathDistance, "dataA"_a, "dataB"_a, DOC(Bentley, Geom, PathLocationDetail, IsLessThan_ByPathDistance));

    c3.def("__repr__", [] (PathLocationDetail& self)
           {
           return "(CurveLocationDetail:{}, Point:{}, PrimitiveIndex:{})"_s.format(self.GetCurveLocationDetail(), self.Point(), self.GetPrimitiveIndex());
           });

    c3.def("__copy__", [](const PathLocationDetail& self)
        {
        return PathLocationDetail(self);
        });
    
    //===================================================================================
    // struct CurveVectorWithDistanceIndex
    py::class_<CurveVectorWithDistanceIndex, CurveVectorWithDistanceIndexPtr> c4(m, "CurveVectorWithDistanceIndex");

    c4.def(py::init(py::overload_cast<RotMatrix>(&CurveVectorWithDistanceIndex::Create)), "worldToView"_a);
    c4.def(py::init(py::overload_cast<>(&CurveVectorWithDistanceIndex::Create)));

    c4.def("IsEmpty", &CurveVectorWithDistanceIndex::IsEmpty, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, IsEmpty));
    c4.def("NumberOfPrimitives", &CurveVectorWithDistanceIndex::NumberOfPrimitives, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, NumberOfPrimitives));
    c4.def("SetPath", &CurveVectorWithDistanceIndex::SetPath, "path"_a, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, SetPath));

    c4.def("SetExtendedPath", 
           &CurveVectorWithDistanceIndex::SetExtendedPath, 
           "path"_a, "extensionDistance"_a, "boundedStart"_a, "boundedEnd"_a, "measureExtensionInView"_a = false, "maxExtensionFactor"_a = 4.0, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, SetExtendedPath));

    c4.def("TotalPathLength", &CurveVectorWithDistanceIndex::TotalPathLength, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, TotalPathLength));
    c4.def("TotalPathLengthXY", &CurveVectorWithDistanceIndex::TotalPathLengthXY, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, TotalPathLengthXY));

    c4.def("AtStart", &CurveVectorWithDistanceIndex::AtStart, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, AtStart));
    c4.def("AtEnd", &CurveVectorWithDistanceIndex::AtEnd, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, AtEnd));

    c4.def("DistanceBetweenPointsXY", &CurveVectorWithDistanceIndex::DistanceBetweenPointsXY, "xyzA"_a, "xyzB"_a, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, DistanceBetweenPointsXY));

    c4.def("SearchByDistanceFromPathStart", 
           py::overload_cast<double, PathLocationDetail&>(&CurveVectorWithDistanceIndex::SearchByDistanceFromPathStart, py::const_),
           "targetDistance"_a, "detail"_a, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, SearchByDistanceFromPathStart));

    c4.def("SearchByDistanceFromPathStartXY", &CurveVectorWithDistanceIndex::SearchByDistanceFromPathStartXY, "targetDistanceXY"_a, "detail"_a, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, SearchByDistanceFromPathStartXY));

    c4.def("SearchClosestPointBounded", &CurveVectorWithDistanceIndex::SearchClosestPointBounded, "spacePoint"_a, "computeDistanceAlong"_a, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, SearchClosestPointBounded));

    c4.def("SearchFirstIntersectionWithCircleXY", &CurveVectorWithDistanceIndex::SearchFirstIntersectionWithCircleXY, "startLocation"_a, "signedRadius"_a, "intersectionLocation"_a, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, SearchFirstIntersectionWithCircleXY));

    c4.def("DistanceXYFromPathStart", [] (CurveVectorWithDistanceIndex const& self, PathLocationDetail const& detail)
        {
        double distance = 0;
        bool bOk = self.DistanceXYFromPathStart(detail, distance);
        return py::make_tuple(bOk, distance);
        }, DOC(Bentley, Geom, CurveVectorWithDistanceIndex, DistanceXYFromPathStart));
    c4.def("__copy__", [](const CurveVectorWithDistanceIndex& self)
        {
        return CurveVectorWithDistanceIndex(self);
        });
    }