/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\curveprimitive.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/BSIQuadrature.h>
#include <Geom/DTriangle3d.h>
#include <Geom/DSpiral2dBase.h>
#include <Geom/DBilinearPatch3d.h>



static const char * __doc_Bentley_Geom_ICurvePrimitive_AddRuledSurfaceRayIntersections =R"doc(Compute intersections of a ray with a ruled surface between two
primitves.

:returns:
    false if primitives are not compatible

:param (output):
    pickData array to receive picks

:param (input):
    curveA first curve

:param (input):
    curveB second curve

:param (input):
    ray ray)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetStrokeCount =R"doc(Return the number of strokes needed to approximate this curve
primitive.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_AddStrokes =R"doc(Stroke the curve and add points to the bvector. return true if this is
a strokable primitive -- Line, Arc, Bspline, Spiral, Akima, or partial
curve. false for non-strokable -- i.e. child vector or point vector.

:param [in,out]:
    points growing vector of strokes.

:param (input):
    options stroke tolerance.

:param (input):
    includeStartPoint if false, do NOT put start point in the output.

:param (input):
    startFraction start of partial curve interval.

:param (input):
    endFraction end of partial curve interval.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_WireCentroid =R"doc(Return the centroid of (a portion of) the curve.

:param (output):
    length curve length

:param (output):
    centroid curve centroid

:param (input):
    fraction0 start fraction of active part of sweep.

:param (input):
    fraction1 end fraction of active part of sweep.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_AppendCurveBilinearPatchIntersections =R"doc(Return intesections of curve primitive with a bilinear patch)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_AppendCurveRangeIntersections =R"doc(Return intesections of curve primitive with a range box.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_AppendCurvePlaneIntersections =R"doc(Return vector of intersections with a plane. Single point intersection
appears as a CurveLocationDetailPair with identical locations for both
parts of the pair (SameCurveAndFraction) Curve-on-plane appears as
CurveLocationDetailPair with curve,fraction data for start and end of
on-plane sections.

:param (input):
    plane

:param (output):
    intersections intersection details

:param (input):
    tolerance for on-plane decisions. If 0, a tolerance is computed
    based on the coordinates in the curve.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_ReverseCurvesInPlace =R"doc(reverse the parameterization in place.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TransformInPlace =R"doc(Transform in place.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_IsPeriodicFractionSpace =R"doc(Return true if the curve is part of a (possibly larger) periodic
curve.

:param (output):
    period period as a multiple of the bounded curve's fraction space.
    For example, a quarter arc has a period of 4.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_IsFractionSpace =R"doc(Test if this is a curve (i.e. not a child vector or point string))doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_IsMappableFractionSpace =R"doc(Test if cloned fractional intervals map linearly back to parent
fractions. (Not true for linestrings and child curve vectors.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_IsExtensibleFractionSpace =R"doc(Test if fractional queries allow extension. When this is true, the
CurvePrimitive recognizes fractions outside of 0..1.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TrySetEnd =R"doc(Modify the end point if possible)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TrySetStart =R"doc(Modify the start point if possible)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetStartPoint =R"doc(Return first primitive in a deep search.

:param (output):
    point start point.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetStartEnd =R"doc(return the start and end points of the curve

:param (output):
    pointA start point

:param (output):
    pointB end point

Remark:
    For ChildCurveVector, the first and last component endpoints are
    determined.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_ClosestPointBoundedXY =R"doc(Find closest point, measuring in xy plane after applying a (possibly
perspective) transform to both the curve and space point.

:param (input):
    spacePoint reference point.

:param (input):
    worldToLocal optional transform.

:param (output):
    location details of closest point. See ClosestPointBounded.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_AnnounceKeyPoints =R"doc(Search for various keypoints (as requested by the collector) During
recursion, extension bits are changed to false for interior points of
paths)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_ClosestPointBounded =R"doc(Find the closest point to a space point. return false if not a simple
curve. (EXAMPLE:ChildCurveVector)

:param (input):
    spacePoint reference point.

:param (output):
    fraction fractional position at closest point.

:param (output):
    curvePoint coordinates on curve)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_PointAtSignedDistanceFromFraction =R"doc(Attempt to move a specified distance from given fraction.

:param (input):
    startFraction starting position.

:param (input):
    signedDistance distance for attempted move.

:param (input):
    allowExtension controls extended behaior of line, arc, and
    linestring.

:param (output):
    location fraction and point after move.{a} field indicates actual
    signed distance moved (which may be less than request!!)

Remark:
    If extension is not allowed, there are fussy rules for both the
    input and output. (1) The startFraction is clamped to{0..1} (2)
    Movement stops at the endpoint in the indicated direction.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_SignedDistanceBetweenFractions =R"doc(Return distance between fractions. Primitives that do not have
extensible fraction spaces will SILENTLY clamp the fractions to 0..1.
return false if this is not a parameterized curve (EXAMPLE:A
ChildCurveVector)

:param (input):
    startFraction starting position for partial curve.

:param (input):
    endFraction end position for partial curve.

:param (output):
    signedDistance distance along curve, negative if fraction
    direction is reversed.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_AdjustFractionToBreakFraction =R"doc(Move a fraction to the nearest break fraction.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetBreakFraction =R"doc(Return the fractional postion of a point where the curve's continuity
has a break.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_NumComponent =R"doc(Return the number of components that can be parameterized. This is ul>
li> 1 for all curves except linestrings. li> 0 for child curve vector
li> the number of edges in a linestring. ul>)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_IsSameStructureAndGeometry =R"doc(Recursive check for match (tree structure. leaf type, and geometry)
with a peer. <param name=" other ">peer for comparison</param> <param
name=" tolerance ">distance tolerance. (See DoubleOps::AlmostEqual
())</param>)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_IsSameStructure =R"doc(Recursive check for structural match (tree structure and leaf type)
with the other curve primitive.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_FastMaxAbs =R"doc(Return a representative large coordinate. This is not required to be a
true range limit. For instance, a max abs of a bspline pole range is
acceptable.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_ProjectedParameterRange =R"doc(Return the range the primitive projected onto a ray. return DRange1d
with range data.

:param (input):
    ray test ray.

:param (input):
    fraction0 start fraction of active part.

:param (input):
    fraction1 end fraction of active part.

Remark:
    If the ray's direction vector is a unit vector, the projected
    parameters are physical distances.

Remark:
    If the ray's direction vector is NOT a unit vector, the projected
    parameters are fractions of the ray's direction vector.

Remark:
    If the primitive has no curves, the returned range returns true on
    the DRange1d::IsNull() predicate.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetRange =R"doc(Return range of the primitive.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_FastLength =R"doc(Compute a fast approximation of curve length. return false if no
measurable curves.

:param (output):
    length curve length. For ChildCurveVector, length of contained
    curves is summed.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_Length =R"doc(Compute curve length. return false if no measurable curves.

:param (output):
    length curve length. For ChildCurveVector, length of contained
    curves is summed.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_FractionToFrenetFrame =R"doc(Evaluate curve point at fractional position within its parameter
space.

:returns:
    false if this is not a parameterized curve (EXAMPLE:A
    ChildCurveVector)

:param (input):
    f evaluation fraction.

:param (output):
    frame Coordinate frame with origin on curve, x direction along
    curve, y direction in curvature plane, z direction perpendicular.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_ComponentFractionToPoint =R"doc(Evaluate curve fractional position within the parameter space of a
component. (For anything except a linestring, componentIndex is
ignored and this is equivalent to FractionToPoint) return false if
this is not a parameterized curve (EXAMPLE:A ChildCurveVector)

:param (input):
    componentIndex index of the component to evaluate.

:param (input):
    f evaluation fraction.

:param (output):
    point point on curve.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_FractionToPointWithTwoSidedDerivative =R"doc(Evaluate curve fractional position within its parameter space.

* On a smooth curve, incoming and outgoing derivatives will be
identical.

* Incoming and outgoing derivatives can differ at linestring interior
points and bspline knots.

return false if this is not a parameterized curve (EXAMPLE:A
ChildCurveVector)

:param (input):
    f evaluation fraction.

:param (output):
    point point on curve.

:param (output):
    derivativeA first derivative with respect to the fractional
    coordinate, taken on the inbound (lower parameter) side of the
    parameter.

:param (output):
    derivativeB first derivative with respect to the fractional
    coordinate, taken on the outbound (higher parameter) side of the
    parameter.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_FractionToPoint =R"doc(Evaluate curve fractional position within its parameter space. return
false if this is not a parameterized curve (EXAMPLE:A
ChildCurveVector)

:param (input):
    f evaluation fraction.

:param (output):
    point point on curve.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateChildCurveVector_SwapFromSource =R"doc(Create a child vector; contents of source are taken, source itself is
cleared.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateChildCurveVector_CopyFromSource =R"doc(Create child vector, making deep copy of the source.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateChildCurveVector =R"doc(Create a curve primitive with (ref coutnted pointer to preexisting
refcounted child.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CloneDereferenced =R"doc(Return a (deep) clone with all partial curves replaced by complete
curves.

:param (input):
    maximumDeref true to recurse through all steps of PartialCurve
    chains

:param (input):
    allowExtrapolation true to allow extension before/after endpoints.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CloneAsSingleOffsetPrimitiveXY =R"doc(Return an offset primitive. This operates only on single primtives
that can offset to another single primitive.

:param (input):
    options contains tolerance for bspline and ellipse offset.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CloneBetweenFractions =R"doc(Return a copy of a subset. The fraction interval may be high to low;
fraction clamping respects the interval direction. return null pointer
if fraction clamping resulted in zero-length interval.

:param (input):
    fractionA start of returned invterval.

:param (input):
    fractionB end of returned interval.

:param (input):
    allowExtrapolation If false, out of bounds values are clamped.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CloneComponent =R"doc(Return a copy of a component. Component index only applies to
linestring. Any invalid index clones entire linestring. All others are
complete Clone.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_Clone =R"doc(Return a deep copy)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateInterpolationBetweenCurves =R"doc(Create a curve that is interpolated between parents.

:param (input):
    curveA first curve

:param (input):
    curveB second curve

:param (input):
    fraction interpolation position.

:returns:
    null curve pointer if curves are not compatible for interpolation.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreatePartialCurve =R"doc(Allocate and fill a reference to a portion of a parent curve.

:param (input):
    parentCurve pointer to another curve.

:param (input):
    fraction0 start of active portion of parent.

:param (input):
    fraction1 end of active portion of parent.

:param (input):
    index application data.

Remark:
    fraction0 and fraction1 may be in forward or reverse relationship.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreatePseudoSpiralPointBearingRadiusLengthRadius =R"doc(Construct a spiral with start radius, spiral length, and end radius.
ul> li> The spiral is paralllel to the xy plane. li> This is a special
construction for " cubic " approximations. li> The constructed spiral is
a fractional subset of another spiral that includes its inflection
point (which may be outside the active fractional subset). ul>)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateSpiralBearingCurvatureLengthCurvature =R"doc(Allocate and fill a spiral curve.

:param (input):
    startRadians bearing at start

:param (input):
    startCurvature curvature at start (or 0 if flat)

:param (input):
    length length along spiral

:param (input):
    endCurvature curvature at end (or 0 if flat)

:param (input):
    transitionType (see DSpiral2dBase)

:param (input):
    frame placement frame

:param (input):
    fractionA start fraction for active portion of curve

:param (input):
    fractionB end fraction for active portion of curve @praam (input)
    extraData type-specific extra data.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateSpiralBearingRadiusLengthRadius =R"doc(Allocate and fill a spiral curve.

:param (input):
    startRadians bearing at start

:param (input):
    startRadius radius at start (or 0 if flat)

:param (input):
    length length along spiral

:param (input):
    endRadius radius at end (or 0 if flat)

:param (input):
    transitionType (see DSpiral2dBase)

:param (input):
    frame placement frame

:param (input):
    fractionA start fraction for active portion of curve

:param (input):
    fractionB end fraction for active portion of curve @praam (input)
    extraData type-specific extra data.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateSpiralBearingRadiusBearingRadius =R"doc(Allocate and fill a spiral curve.

:param (input):
    startRadians bearing at start

:param (input):
    startRadius radius at start (or 0 of flat)

:param (input):
    endRadians bearing at end

:param (input):
    endRadius radius at end (or 0 if flat)

:param (input):
    transitionType (see DSpiral2dBase)

:param (input):
    frame placement frame

:param (input):
    fractionA start fraction for active portion of curve

:param (input):
    fractionB end fraction for active portion of curve @praam (input)
    extraData type-specific extra data.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateSpiralBearingCurvatureBearingCurvature =R"doc(Allocate and fill a spiral curve.

:param (input):
    startRadians bearing at start

:param (input):
    startCurvature curvature at start (or 0 of flat)

:param (input):
    endRadians bearing at end

:param (input):
    endCurvature curvature at end (or 0 if flat)

:param (input):
    transitionType (see DSpiral2dBase)

:param (input):
    frame placement frame

:param (input):
    fractionA start fraction for active portion of curve

:param (input):
    fractionB end fraction for active portion of curve)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateSpiral =R"doc(Allocate and fill a spiral curve.

:param (input):
    spiral spiral structure (to be cloned -- caller still responsible
    for deallocation)

:param (input):
    frame placement frame

:param (input):
    fractionA start fraction for active portion of curve

:param (input):
    fractionB end fraction for active portion of curve)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateRectangle =R"doc(Create a rectangle from xy corners.

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
    areaSignPreference is one of

* any positive integer to force positive xy areLa.

* 0 to take order (x0,y0)(x1,y0),(x1,y1),(x0,y1)

* any negative integer to force negative xy area.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreatePointString =R"doc(Allocate and fill a new point string

:param (input):
    points coordinates to copy into the primitive

:param (input):
    nPoints number of points)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateAkimaCurve =R"doc(Allocate and fill a new akima curve

:param (input):
    points akima control points to copy into the primitive. First two
    and final two points are slope end condition controls. Others are
    pass-through.

:param (input):
    nPoints control point count.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateInterpolationCurveSwapFromSource =R"doc(Allocate and fill a new interpolation curve

:param (input):
    fitCurve source curve. Data is swapped into the curve. input
    fitCurve is zeroed.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateInterpolationCurve =R"doc(Allocate and fill a new interpolation curve

:param (input):
    fitCurve source curve. Data is COPIED into the new object. Caller
    is still responsible for freeing the input fitCurve.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateBsplineCurveSwapFromSource =R"doc(Allocate and fill a new bspline curve

:param (input):
    curve source curve. Bits (including pointers) are copied to the
    CurvePrimtive. source curve is zeroed -- caller has no " free "
    responsibilities.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateBsplineCurve =R"doc(Allocate and fill a new bspline curve

:param (input):
    curve source curve. A copy (clone, repeat allocation of memory) of
    the curve is placed into the new object. Caller is still
    responsible for freeing the input curve.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateArc =R"doc(Allocate and fill a new elliptic arc

:param (input):
    ellipse source ellipse.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateLineString =R"doc(Allocate and fill a new linestring

:param (input):
    points source coordinates.

:param (input):
    nPoints point count.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_CreateLine =R"doc(Allocate and fill a new line segemnt.

:param (input):
    segment source segment.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TryAddLineStringPoint =R"doc(If this is a linestring, add a point.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TryGetSegmentInLineString =R"doc(If this is a linestring and index is valid, get the (single) indexed
segment.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TryGetArc =R"doc(If this is a line primitive, copy its coordinate data to a DEllipse3d.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_TryGetLine =R"doc(If this is a line primitive, copy its coordinate data to a DSegment3d.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetCurvePrimitiveType =R"doc(Return the integer type code for the curve primitive type.)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetIntTag =R"doc(Get the Int64 tag (cast to int))doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_SetTag =R"doc(Set the Int64 tag)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetTag =R"doc(Get the Int64 tag ...)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_SetMarkerBit =R"doc(Set the specified marker bit on or off)doc";

static const char * __doc_Bentley_Geom_ICurvePrimitive_GetMarkerBit =R"doc(Ask if specified marker bit is on or off)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_CurvePrimitive(py::module_& m)
    {
    //===================================================================================
    // struct ICurvePrimitive
    py::class_<ICurvePrimitive, ICurvePrimitivePtr> c1(m, "ICurvePrimitive");
    py::bind_vector<ICurvePrimitiveArray>(m, "ICurvePrimitivePtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // Enum CurvePrimitiveType
        py::enum_<ICurvePrimitive::CurvePrimitiveType>(c1, "CurvePrimitiveType", py::arithmetic())
            .value("eCURVE_PRIMITIVE_TYPE_Invalid", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Invalid)
            .value("eCURVE_PRIMITIVE_TYPE_Line", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Line)
            .value("eCURVE_PRIMITIVE_TYPE_LineString", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_LineString)
            .value("eCURVE_PRIMITIVE_TYPE_Arc", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Arc)
            .value("eCURVE_PRIMITIVE_TYPE_BsplineCurve", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_BsplineCurve)
            .value("eCURVE_PRIMITIVE_TYPE_InterpolationCurve", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_InterpolationCurve)
            .value("eCURVE_PRIMITIVE_TYPE_AkimaCurve", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_AkimaCurve)
            .value("eCURVE_PRIMITIVE_TYPE_PointString", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_PointString)
            .value("eCURVE_PRIMITIVE_TYPE_CurveVector", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_CurveVector)
            .value("eCURVE_PRIMITIVE_TYPE_Spiral", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_Spiral)
            .value("eCURVE_PRIMITIVE_TYPE_PartialCurve", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_PartialCurve)
            .value("eCURVE_PRIMITIVE_TYPE_NotClassified", ICurvePrimitive::CURVE_PRIMITIVE_TYPE_NotClassified)
            .export_values();

        py::enum_<ICurvePrimitive::CurvePrimitiveMarkerBit>(c1, "CurvePrimitiveMarkerBit", py::arithmetic())
            .value("eCURVE_PRIMITIVE_BIT_GapCurve", ICurvePrimitive::CURVE_PRIMITIVE_BIT_GapCurve)
            .value("eCURVE_PRIMITIVE_BIT_AllApplicationBits", ICurvePrimitive::CURVE_PRIMITIVE_BIT_AllApplicationBits)
            .export_values();
        }

    c1.def("GetMarkerBit", &ICurvePrimitive::GetMarkerBit, "selector"_a, DOC(Bentley, Geom, ICurvePrimitive, GetMarkerBit));
    c1.def("SetMarkerBit", &ICurvePrimitive::SetMarkerBit, "selector"_a, "value"_a, DOC(Bentley, Geom, ICurvePrimitive, SetMarkerBit));
    
    c1.def_property("Tag", &ICurvePrimitive::GetTag, py::overload_cast<int64_t>(&ICurvePrimitive::SetTag));
    c1.def("GetTag", &ICurvePrimitive::GetTag, DOC(Bentley, Geom, ICurvePrimitive, GetTag));
    c1.def("SetTag", py::overload_cast<int64_t>(&ICurvePrimitive::SetTag), "tag"_a, DOC(Bentley, Geom, ICurvePrimitive, SetTag));

    c1.def_property("IntTag", &ICurvePrimitive::GetIntTag, py::overload_cast<int>(&ICurvePrimitive::SetTag));
    c1.def("GetIntTag", &ICurvePrimitive::GetIntTag, DOC(Bentley, Geom, ICurvePrimitive, GetIntTag));
    c1.def("SetIntTag", py::overload_cast<int>(&ICurvePrimitive::SetTag), "tag"_a);

    c1.def_property_readonly("Id", &ICurvePrimitive::GetId);
    c1.def("GetId", &ICurvePrimitive::GetId);

    c1.def_property_readonly("CurvePrimitiveType", &ICurvePrimitive::GetCurvePrimitiveType);
    c1.def("GetCurvePrimitiveType", &ICurvePrimitive::GetCurvePrimitiveType, DOC(Bentley, Geom, ICurvePrimitive, GetCurvePrimitiveType));

    c1.def("TryGetLine", &ICurvePrimitive::TryGetLine, "segment"_a, DOC(Bentley, Geom, ICurvePrimitive, TryGetLine));
    c1.def("TryGetArc", &ICurvePrimitive::TryGetArc, "arc"_a, DOC(Bentley, Geom, ICurvePrimitive, TryGetArc));

    c1.def_property_readonly("Line", &ICurvePrimitive::GetLineCP);
    c1.def("GetLine", &ICurvePrimitive::GetLineCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("LineString", &ICurvePrimitive::GetLineStringCP);
    c1.def("GetLineString", &ICurvePrimitive::GetLineStringCP, py::return_value_policy::reference_internal);

    c1.def("TryGetSegmentInLineString", &ICurvePrimitive::TryGetSegmentInLineString, "segment"_a, "startPointIndex"_a, DOC(Bentley, Geom, ICurvePrimitive, TryGetSegmentInLineString));
    c1.def("TryAddLineStringPoint", &ICurvePrimitive::TryAddLineStringPoint, "xyz"_a, DOC(Bentley, Geom, ICurvePrimitive, TryAddLineStringPoint));

    c1.def_property_readonly("Arc", &ICurvePrimitive::GetArcCP);
    c1.def("GetArc", &ICurvePrimitive::GetArcCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("BsplineCurve", &ICurvePrimitive::GetBsplineCurvePtr);
    c1.def("GetBsplineCurve", &ICurvePrimitive::GetBsplineCurvePtr);

    c1.def_property_readonly("ProxyBsplineCurve", &ICurvePrimitive::GetProxyBsplineCurvePtr);
    c1.def("GetProxyBsplineCurve", &ICurvePrimitive::GetProxyBsplineCurvePtr);

    c1.def_property_readonly("InterpolationCurve", &ICurvePrimitive::GetInterpolationCurveCP);
    c1.def("GetInterpolationCurve", &ICurvePrimitive::GetInterpolationCurveCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("AkimaCurve", &ICurvePrimitive::GetAkimaCurveCP);
    c1.def("GetAkimaCurve", &ICurvePrimitive::GetAkimaCurveCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("PointString", &ICurvePrimitive::GetPointStringCP);
    c1.def("GetPointString", &ICurvePrimitive::GetPointStringCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("ChildCurveVector", &ICurvePrimitive::GetChildCurveVectorCP);
    c1.def("GetChildCurveVector", &ICurvePrimitive::GetChildCurveVectorCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("SpiralPlacement", &ICurvePrimitive::GetSpiralPlacementCP);
    c1.def("GetSpiralPlacement", &ICurvePrimitive::GetSpiralPlacementCP, py::return_value_policy::reference_internal);

    c1.def_property_readonly("PartialCurveDetail", &ICurvePrimitive::GetPartialCurveDetailCP);
    c1.def("GetPartialCurveDetail", &ICurvePrimitive::GetPartialCurveDetailCP, py::return_value_policy::reference_internal);

    c1.def("TryGetPartialCurveData", [] (ICurvePrimitiveCR self)
           {
           double fractionA, fractionB;
           ICurvePrimitivePtr parentCurve;
           int64_t tag;
           py::tuple outVal;
           if (self.TryGetPartialCurveData(fractionA, fractionB, parentCurve, tag))
               outVal = py::make_tuple(fractionA, fractionB, parentCurve, tag);

           return outVal;
           });

    c1.def_static("CreateLine", &ICurvePrimitive::CreateLine, "segment"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateLine));
    c1.def_static("CreateLineString", py::overload_cast<DPoint3dArray const&>(&ICurvePrimitive::CreateLineString), "points"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateLineString));
    c1.def_static("CreateLineString", []( py::list const& points){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint3dArray, DPoint3d)
        return ICurvePrimitive::CreateLineString(cpppoints);
    }, "points"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateLineString));
    c1.def_static("CreateArc", &ICurvePrimitive::CreateArc, "ellipse"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateArc));
    c1.def_static("CreateBsplineCurve", py::overload_cast<MSBsplineCurveCR>(&ICurvePrimitive::CreateBsplineCurve), "curve"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateBsplineCurve));
    c1.def_static("CreateBsplineCurveSwapFromSource", &ICurvePrimitive::CreateBsplineCurveSwapFromSource, "curve"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateBsplineCurveSwapFromSource));
    c1.def_static("CreateBsplineCurve", py::overload_cast<MSBsplineCurvePtr>(&ICurvePrimitive::CreateBsplineCurve), "curve"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateBsplineCurve));
    c1.def_static("CreateInterpolationCurve", &ICurvePrimitive::CreateInterpolationCurve, "fitCurve"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateInterpolationCurve));
    c1.def_static("CreateInterpolationCurveSwapFromSource", &ICurvePrimitive::CreateInterpolationCurveSwapFromSource, "fitCurve"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateInterpolationCurveSwapFromSource));
    c1.def_static("CreateAkimaCurve", [] (DPoint3dArray const& points)
                  {
                  return ICurvePrimitive::CreateAkimaCurve(&points[0], points.size());
                  }, "points"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateAkimaCurve));

    c1.def_static("CreateAkimaCurve", [](py::list const& points)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint3dArray, DPoint3d); 
                  return ICurvePrimitive::CreateAkimaCurve(&cpppoints[0], cpppoints.size()); 
                  }, "points"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateAkimaCurve));

    c1.def_static("CreatePointString", py::overload_cast<DPoint3dArray&>(&ICurvePrimitive::CreatePointString), "points"_a, DOC(Bentley, Geom, ICurvePrimitive, CreatePointString));
    c1.def_static("CreatePointString", [](py::list const& points)
                  {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint3dArray, DPoint3d); 
                  return ICurvePrimitive:: CreatePointString(cpppoints); 
                  }, "points"_a, DOC(Bentley, Geom, ICurvePrimitive, CreatePointString));
    c1.def_static("CreateRectangle", &ICurvePrimitive::CreateRectangle, "x0"_a, "y0"_a, "x1"_a, "y1"_a, "z"_a, "areaSignPreference"_a = 0, DOC(Bentley, Geom, ICurvePrimitive, CreateRectangle));
    c1.def_static("CreateSpiral", &ICurvePrimitive::CreateSpiral, "spiral"_a, "frame"_a, "fractionA"_a, "fractionB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiral));
    c1.def_static("CreateXYCatenaryVertexCoefficientSignedDistanceLimits", &ICurvePrimitive::CreateXYCatenaryVertexCoefficientSignedDistanceLimits, "a"_a, "basis"_a, "s0"_a, "s1"_a);
    c1.def_static("CreateSpiralBearingCurvatureBearingCurvature",
                  &ICurvePrimitive::CreateSpiralBearingCurvatureBearingCurvature,
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "endRadians"_a, "endCurvature"_a, "frame"_a, "fractionA"_a, "fractionB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingCurvatureBearingCurvature));
    c1.def_static("CreateSpiralBearingRadiusBearingRadius",
                  py::overload_cast<int, double, double, double, double, TransformCR, double, double, DoubleArray const&>(&ICurvePrimitive::CreateSpiralBearingRadiusBearingRadius),
                  "transitionType"_a, "startRadians"_a, "startRadius"_a, "endRadians"_a, "endRadius"_a, "frame"_a, "fractionA"_a, "fractionB"_a, "extraData"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingRadiusBearingRadius));

    c1.def_static("CreateSpiralBearingRadiusBearingRadius",
                  py::overload_cast<int, double, double, double, double, TransformCR, double, double>(&ICurvePrimitive::CreateSpiralBearingRadiusBearingRadius),
                  "transitionType"_a, "startRadians"_a, "startRadius"_a, "endRadians"_a, "endRadius"_a, "frame"_a, "fractionA"_a, "fractionB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingRadiusBearingRadius));

    c1.def_static("CreateSpiralBearingRadiusLengthRadius",
                  py::overload_cast<int, double, double, double, double, TransformCR, double, double, DoubleArray const&>(&ICurvePrimitive::CreateSpiralBearingRadiusLengthRadius),
                  "transitionType"_a, "startRadians"_a, "startRadius"_a, "length"_a, "endRadius"_a, "frame"_a, "fractionA"_a, "fractionB"_a, "extraData"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingRadiusLengthRadius));
    c1.def_static("CreateSpiralBearingRadiusLengthRadius",
                  py::overload_cast<int, double, double, double, double, TransformCR, double, double>(&ICurvePrimitive::CreateSpiralBearingRadiusLengthRadius),
                  "transitionType"_a, "startRadians"_a, "startRadius"_a, "length"_a, "endRadius"_a, "frame"_a, "fractionA"_a, "fractionB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingRadiusLengthRadius));

    c1.def_static("CreateSpiralBearingCurvatureLengthCurvature",
                  py::overload_cast<int, double, double, double, double, TransformCR, double, double, DoubleArray const&>(&ICurvePrimitive::CreateSpiralBearingCurvatureLengthCurvature),
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "length"_a, "endCurvature"_a, "frame"_a, "fractionA"_a, "fractionB"_a, "extraData"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingCurvatureLengthCurvature));
    c1.def_static("CreateSpiralBearingCurvatureLengthCurvature",
                  py::overload_cast<int, double, double, double, double, TransformCR, double, double>(&ICurvePrimitive::CreateSpiralBearingCurvatureLengthCurvature),
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "length"_a, "endCurvature"_a, "frame"_a, "fractionA"_a, "fractionB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateSpiralBearingCurvatureLengthCurvature));

    c1.def_static("CreatePseudoSpiralPointBearingRadiusLengthRadius",
                  py::overload_cast<int, DPoint3dCR, double, double, double, double>(&ICurvePrimitive::CreatePseudoSpiralPointBearingRadiusLengthRadius),
                  "typeCode"_a, "startPoint"_a, "startRadians"_a, "radiusA"_a, "lengthAB"_a, "radiusB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreatePseudoSpiralPointBearingRadiusLengthRadius));

    c1.def_static("CreatePseudoSpiralPointBearingRadiusLengthRadius",
                  py::overload_cast<int, DPoint3dCR, double, double, double, double, double, double>(&ICurvePrimitive::CreatePseudoSpiralPointBearingRadiusLengthRadius),
                  "typeCode"_a, "startPoint"_a, "startRadians"_a, "radiusA"_a, "lengthAB"_a, "radiusB"_a, "startFraction"_a, "endFraction"_a, DOC(Bentley, Geom, ICurvePrimitive, CreatePseudoSpiralPointBearingRadiusLengthRadius));

    c1.def_static("CreatePseudolSpiralWithTrueRadiusLengthRadius",
                  &ICurvePrimitive::CreatePseudolSpiralWithTrueRadiusLengthRadius,
                  "transitionType"_a, "startPoint"_a, "startRadians"_a, "startRadius"_a, "targetLength"_a, "endRadius"_a);

    c1.def_static("CreateAustralianRailCorpBearingRadiusLengthRadius",
                  &ICurvePrimitive::CreateAustralianRailCorpBearingRadiusLengthRadius,
                  "startPoint"_a, "startRadians"_a, "startRadius"_a, "targetLength"_a, "endRadius"_a);

    c1.def_static("CreatePartialCurve", &ICurvePrimitive::CreatePartialCurve, "parentCurve"_a, "fraction0"_a, "fraction1"_a, "index"_a = 0, DOC(Bentley, Geom, ICurvePrimitive, CreatePartialCurve));
    c1.def_static("CreateInterpolationBetweenCurves", &ICurvePrimitive::CreateInterpolationBetweenCurves, "curveA"_a, "fraction"_a, "curveB"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateInterpolationBetweenCurves));

    c1.def("Clone", &ICurvePrimitive::Clone, DOC(Bentley, Geom, ICurvePrimitive, Clone));
    c1.def("CloneComponent", &ICurvePrimitive::CloneComponent, "componentIndex"_a, DOC(Bentley, Geom, ICurvePrimitive, CloneComponent));
    c1.def("CloneBetweenFractions", &ICurvePrimitive::CloneBetweenFractions, "fractionA"_a, "fractionB"_a, "allowExtrapolation"_a, DOC(Bentley, Geom, ICurvePrimitive, CloneBetweenFractions));
    c1.def("CloneAsSingleOffsetPrimitiveXY", &ICurvePrimitive::CloneAsSingleOffsetPrimitiveXY, "options"_a, DOC(Bentley, Geom, ICurvePrimitive, CloneAsSingleOffsetPrimitiveXY));
    c1.def("CloneDereferenced", &ICurvePrimitive::CloneDereferenced, "allowExtrapolation"_a = false, "maximumDeref"_a = true, DOC(Bentley, Geom, ICurvePrimitive, CloneDereferenced));

    c1.def_static("CreateChildCurveVector", &ICurvePrimitive::CreateChildCurveVector, "source"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateChildCurveVector));
    c1.def_static("CreateChildCurveVector_CopyFromSource", &ICurvePrimitive::CreateChildCurveVector_CopyFromSource, "source"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateChildCurveVector_CopyFromSource));
    c1.def_static("CreateChildCurveVector_SwapFromSource", &ICurvePrimitive::CreateChildCurveVector_SwapFromSource, "source"_a, DOC(Bentley, Geom, ICurvePrimitive, CreateChildCurveVector_SwapFromSource));

    c1.def("FractionToPoint", py::overload_cast<double, DPoint3dR>(&ICurvePrimitive::FractionToPoint, py::const_), "f"_a, "point"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPoint));
    c1.def("FractionToPoint", py::overload_cast<double, DPoint3dR, DVec3dR>(&ICurvePrimitive::FractionToPoint, py::const_), "f"_a, "point"_a, "tangent"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPoint));
    c1.def("FractionToPoint", py::overload_cast<double, DRay3dR>(&ICurvePrimitive::FractionToPoint, py::const_), "f"_a, "ray"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPoint));
    c1.def("FractionToPoint", py::overload_cast<double, CurveLocationDetail&>(&ICurvePrimitive::FractionToPoint, py::const_), "f"_a, "detail"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPoint));
    c1.def("FractionToPoint", py::overload_cast<double, DPoint3dR, DVec3dR, DVec3dR>(&ICurvePrimitive::FractionToPoint, py::const_), "f"_a, "point"_a, "tangent"_a, "derivate2"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPoint));
    c1.def("FractionToPoint", py::overload_cast<double, DPoint3dR, DVec3dR, DVec3dR, DVec3dR>(&ICurvePrimitive::FractionToPoint, py::const_), "f"_a, "point"_a, "tangent"_a, "derivate2"_a, "derivate3"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPoint));
    c1.def("FractionToPointWithTwoSidedDerivative", &ICurvePrimitive::FractionToPointWithTwoSidedDerivative, "f"_a, "point"_a, "derivativeA"_a, "derivativeB"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToPointWithTwoSidedDerivative));

    c1.def("ComponentFractionToPoint", py::overload_cast<ptrdiff_t, double, DPoint3dR>(&ICurvePrimitive::ComponentFractionToPoint, py::const_), "componentIndex"_a, "f"_a, "point"_a, DOC(Bentley, Geom, ICurvePrimitive, ComponentFractionToPoint));
    c1.def("ComponentFractionToPoint", py::overload_cast<ptrdiff_t, double, DPoint3dR, DVec3dR>(&ICurvePrimitive::ComponentFractionToPoint, py::const_), "componentIndex"_a, "f"_a, "point"_a, "tangent"_a, DOC(Bentley, Geom, ICurvePrimitive, ComponentFractionToPoint));

    c1.def("FractionToFrenetFrame", py::overload_cast<double, TransformR>(&ICurvePrimitive::FractionToFrenetFrame, py::const_), "f"_a, "frame"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToFrenetFrame));
    c1.def("FractionToFrenetFrame", [] (ICurvePrimitiveCR self, double f, TransformR frame)
           {
           double c1, c2;
           py::tuple outVal;
           if (self.FractionToFrenetFrame(f, frame, c1, c2))
               outVal = py::make_tuple(c1, c2);

           return outVal;
           }, "f"_a, "frame"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToFrenetFrame));
    c1.def("FractionToFrenetFrame", py::overload_cast<double>(&ICurvePrimitive::FractionToFrenetFrame, py::const_), "f"_a, DOC(Bentley, Geom, ICurvePrimitive, FractionToFrenetFrame));

    c1.def("Length", [] (ICurvePrimitiveCR self)
           {
           double len = 0.0;
           bool bOk = self.Length(len);
           return py::make_tuple(bOk, len);
           }, DOC(Bentley, Geom, ICurvePrimitive, Length));

    c1.def("Length", [] (ICurvePrimitiveCR self, RotMatrixCP worldToLocal)
           {
           double len = 0.0;
           bool bOk = self.Length(worldToLocal, len);
           return py::make_tuple(bOk, len);
           }, DOC(Bentley, Geom, ICurvePrimitive, Length));

    c1.def("FastLength", [] (ICurvePrimitiveCR self)
           {
           double len = 0.0;
           bool bOk = self.FastLength(len);
           return py::make_tuple(bOk, len);
           }, DOC(Bentley, Geom, ICurvePrimitive, FastLength));

    c1.def("GetRange", py::overload_cast<DRange3dR>(&ICurvePrimitive::GetRange, py::const_), "range"_a, DOC(Bentley, Geom, ICurvePrimitive, GetRange));
    c1.def("GetRange", py::overload_cast<DRange3dR, TransformCR>(&ICurvePrimitive::GetRange, py::const_), "range"_a, "transform"_a, DOC(Bentley, Geom, ICurvePrimitive, GetRange));
    c1.def("ProjectedParameterRange", py::overload_cast<DRay3dCR>(&ICurvePrimitive::ProjectedParameterRange, py::const_), "ray"_a, DOC(Bentley, Geom, ICurvePrimitive, ProjectedParameterRange));
    c1.def("ProjectedParameterRange", py::overload_cast<DRay3dCR, double, double>(&ICurvePrimitive::ProjectedParameterRange, py::const_), "ray"_a, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, ICurvePrimitive, ProjectedParameterRange));   
            
    c1.def("FastMaxAbs", &ICurvePrimitive::FastMaxAbs, DOC(Bentley, Geom, ICurvePrimitive, FastMaxAbs));            
    c1.def("IsSameStructure", &ICurvePrimitive::IsSameStructure, "other"_a, DOC(Bentley, Geom, ICurvePrimitive, IsSameStructure));

    c1.def("IsSameStructureAndGeometry", &ICurvePrimitive::IsSameStructureAndGeometry, "other"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, ICurvePrimitive, IsSameStructureAndGeometry));

    c1.def("NumComponent", &ICurvePrimitive::NumComponent, DOC(Bentley, Geom, ICurvePrimitive, NumComponent));

    c1.def("GetBreakFraction", [] (ICurvePrimitiveCR self, size_t breakFractionIndex)
           {
           double fraction = 0.0;
           bool bOk = self.GetBreakFraction(breakFractionIndex, fraction);
           return py::make_tuple(bOk, fraction);
           }, DOC(Bentley, Geom, ICurvePrimitive, GetBreakFraction));

    c1.def("AdjustFractionToBreakFraction", [] (ICurvePrimitiveCR self, double fraction, Rounding::RoundingMode mode)
           {
           size_t breakIndex = 0;
           double adjustedFraction = 0;
           bool bOk = self.AdjustFractionToBreakFraction(fraction, mode, breakIndex, adjustedFraction);
           return py::make_tuple(bOk, breakIndex, adjustedFraction);
           }, DOC(Bentley, Geom, ICurvePrimitive, AdjustFractionToBreakFraction));

    c1.def("GetMSBsplineCurvePtr", &ICurvePrimitive::GetMSBsplineCurvePtr, "fraction0"_a = 0.0, "fraction1"_a = 1.0);

    c1.def("SignedDistanceBetweenFractions", [] (ICurvePrimitiveCR self, double startFraction, double endFraction)
           {
           double signedDistance = 0;
           bool bOk = self.SignedDistanceBetweenFractions(startFraction, endFraction, signedDistance);
           return py::make_tuple(bOk, signedDistance);
           }, "startFraction"_a, "endFraction"_a, DOC(Bentley, Geom, ICurvePrimitive, SignedDistanceBetweenFractions));

    c1.def("SignedDistanceBetweenFractions", [] (ICurvePrimitiveCR self, RotMatrixCP worldToLocal, double startFraction, double endFraction)
           {
           double signedDistance = 0;
           bool bOk = self.SignedDistanceBetweenFractions(worldToLocal, startFraction, endFraction, signedDistance);
           return py::make_tuple(bOk, signedDistance);
           }, "worldToLocal"_a, "startFraction"_a, "endFraction"_a, DOC(Bentley, Geom, ICurvePrimitive, SignedDistanceBetweenFractions));

    c1.def("PointAtSignedDistanceFromFraction",
           py::overload_cast<double, double, bool, CurveLocationDetailR>(&ICurvePrimitive::PointAtSignedDistanceFromFraction, py::const_),
           "startFraction"_a, "signedDistance"_a, "allowExtension"_a, "location"_a, DOC(Bentley, Geom, ICurvePrimitive, PointAtSignedDistanceFromFraction));

    c1.def("PointAtSignedDistanceFromFraction",
           py::overload_cast<RotMatrixCP, double, double, bool, CurveLocationDetailR>(&ICurvePrimitive::PointAtSignedDistanceFromFraction, py::const_),
           "worldToView"_a, "startFraction"_a, "signedDistance"_a, "allowExtension"_a, "location"_a, DOC(Bentley, Geom, ICurvePrimitive, PointAtSignedDistanceFromFraction));

    c1.def("ClosestPointBounded", [] (ICurvePrimitiveCR self, DPoint3dCR spacePoint)
           {
           double fraction = 0;
           DPoint3d curvePoint = DPoint3d::FromZero();
           bool bOk = self.ClosestPointBounded(spacePoint, fraction, curvePoint);
           return py::make_tuple(bOk, fraction, curvePoint);
           }, "spacePoint"_a, DOC(Bentley, Geom, ICurvePrimitive, ClosestPointBounded));

    c1.def("AnnounceKeyPoints", &ICurvePrimitive::AnnounceKeyPoints, "spacePoint"_a, "collector"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, ICurvePrimitive, AnnounceKeyPoints));

    c1.def("ClosestPointBounded", 
           py::overload_cast<DPoint3dCR, CurveLocationDetailR, bool, bool>(&ICurvePrimitive::ClosestPointBounded, py::const_),
           "spacePoint"_a, "location"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, ICurvePrimitive, ClosestPointBounded));
    c1.def("ClosestPointBounded",
           py::overload_cast<DPoint3dCR, CurveLocationDetailR>(&ICurvePrimitive::ClosestPointBounded, py::const_),
           "spacePoint"_a, "location"_a, DOC(Bentley, Geom, ICurvePrimitive, ClosestPointBounded));
    c1.def("ClosestPointBoundedXY",
           py::overload_cast<DPoint3dCR, DMatrix4dCP, CurveLocationDetailR>(&ICurvePrimitive::ClosestPointBoundedXY, py::const_),
           "spacePoint"_a, "worldToLocal"_a,"location"_a, DOC(Bentley, Geom, ICurvePrimitive, ClosestPointBoundedXY));
    c1.def("ClosestPointBoundedXY",
           py::overload_cast<DPoint3dCR, DMatrix4dCP, CurveLocationDetailR, bool, bool>(&ICurvePrimitive::ClosestPointBoundedXY, py::const_),
           "spacePoint"_a, "worldToLocal"_a, "location"_a, "entend0"_a, "extend1"_a, DOC(Bentley, Geom, ICurvePrimitive, ClosestPointBoundedXY));

    c1.def("GetStartEnd", py::overload_cast<DPoint3dR, DPoint3dR>(&ICurvePrimitive::GetStartEnd, py::const_), "pointA"_a, "pointB"_a, DOC(Bentley, Geom, ICurvePrimitive, GetStartEnd));
    c1.def("GetStartEnd", py::overload_cast<DPoint3dR, DPoint3dR, DVec3dR, DVec3dR>(&ICurvePrimitive::GetStartEnd, py::const_), "pointA"_a, "pointB"_a, "unitTangentA"_a, "unitTangentB"_a, DOC(Bentley, Geom, ICurvePrimitive, GetStartEnd));

    c1.def("GetStartPoint", &ICurvePrimitive::GetStartPoint, "point"_a, DOC(Bentley, Geom, ICurvePrimitive, GetStartPoint));
    c1.def("TrySetStart", &ICurvePrimitive::TrySetStart, "xyz"_a, DOC(Bentley, Geom, ICurvePrimitive, TrySetStart));            
    c1.def("TrySetEnd", &ICurvePrimitive::TrySetEnd, "xyz"_a, DOC(Bentley, Geom, ICurvePrimitive, TrySetEnd));

    c1.def("IsExtensibleFractionSpace", &ICurvePrimitive::IsExtensibleFractionSpace, DOC(Bentley, Geom, ICurvePrimitive, IsExtensibleFractionSpace));
    c1.def("IsMappableFractionSpace", &ICurvePrimitive::IsMappableFractionSpace, DOC(Bentley, Geom, ICurvePrimitive, IsMappableFractionSpace));
    c1.def("IsFractionSpace", &ICurvePrimitive::IsFractionSpace, DOC(Bentley, Geom, ICurvePrimitive, IsFractionSpace));

    c1.def("IsPeriodicFractionSpace", [] (ICurvePrimitiveCR self)
           {
           double period = 0;
           return py::make_tuple(self.IsPeriodicFractionSpace(period), period);
           }, DOC(Bentley, Geom, ICurvePrimitive, IsPeriodicFractionSpace));

    c1.def("TransformInPlace", &ICurvePrimitive::TransformInPlace, "transform"_a, DOC(Bentley, Geom, ICurvePrimitive, TransformInPlace));

    c1.def("ReverseCurvesInPlace", &ICurvePrimitive::ReverseCurvesInPlace, DOC(Bentley, Geom, ICurvePrimitive, ReverseCurvesInPlace));

    c1.def("AppendCurvePlaneIntersections", 
           py::overload_cast<DPlane3dCR, CurveLocationDetailPairArray&, double>(&ICurvePrimitive::AppendCurvePlaneIntersections, py::const_),
           "plane"_a, "intersections"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, ICurvePrimitive, AppendCurvePlaneIntersections));

    c1.def("AppendCurvePlaneIntersections",
           py::overload_cast<DPlane3dByVectorsCR, UVBoundarySelect, CurveAndSolidLocationDetailArray&>(&ICurvePrimitive::AppendCurvePlaneIntersections, py::const_),
           "plane"_a, "bounded"_a, "intersections"_a, DOC(Bentley, Geom, ICurvePrimitive, AppendCurvePlaneIntersections));

    c1.def("AppendCurveRangeIntersections", &ICurvePrimitive::AppendCurveRangeIntersections, "range"_a, "intersections"_a, DOC(Bentley, Geom, ICurvePrimitive, AppendCurveRangeIntersections));

    c1.def("AppendCurveBilinearPatchIntersections", &ICurvePrimitive::AppendCurveBilinearPatchIntersections, "patch"_a, "intersections"_a, DOC(Bentley, Geom, ICurvePrimitive, AppendCurveBilinearPatchIntersections));

    c1.def("WireCentroid", [] (ICurvePrimitiveCR self, double fraction0, double fraction1)
           {
           double len = 0;
           DPoint3d centroid = DPoint3d::FromZero();
           bool bOk = self.WireCentroid(len, centroid, fraction0, fraction1);
           return py::make_tuple(bOk, len, centroid);
           }, "fraction0"_a = 0.0, "fraction1"_a = 1.0, DOC(Bentley, Geom, ICurvePrimitive, WireCentroid));

    c1.def("AddStrokes",
           py::overload_cast<DPoint3dArray&, IFacetOptionsR, bool, double, double>(&ICurvePrimitive::AddStrokes, py::const_),
           "points"_a, "options"_a, "includeStartPoint"_a = true, "startFraction"_a = 0.0, "endFraction"_a = 1.0, DOC(Bentley, Geom, ICurvePrimitive, AddStrokes));

    c1.def("AddStrokes", [](ICurvePrimitiveCR self, py::list &points, IFacetOptionsR options, bool includeStartPoint, double startFraction, double endFraction)
           {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(points, cpppoints, DPoint3dArray, DPoint3d); 
            return self.AddStrokes(cpppoints, options, includeStartPoint, startFraction, endFraction); 
           }, "points"_a, "options"_a, "includeStartPoint"_a = true, "startFraction"_a = 0.0, "endFraction"_a = 1.0, DOC(Bentley, Geom, ICurvePrimitive, AddStrokes));

    c1.def("AddStrokes",
           py::overload_cast<DPoint3dDoubleUVCurveArrays&, IFacetOptionsCR, double, double>(&ICurvePrimitive::AddStrokes, py::const_),
           "points"_a, "options"_a, "startFraction"_a = 0.0, "endFraction"_a = 1.0, DOC(Bentley, Geom, ICurvePrimitive, AddStrokes));
            
    c1.def("GetStrokeCount", &ICurvePrimitive::GetStrokeCount, "options"_a, "startFraction"_a = 0.0, "endFraction"_a = 1.0, DOC(Bentley, Geom, ICurvePrimitive, GetStrokeCount));

    c1.def_static("AddRuledSurfaceRayIntersections", &ICurvePrimitive::AddRuledSurfaceRayIntersections, "pickData"_a, "curveA"_a, "curveB"_a, "ray"_a, DOC(Bentley, Geom, ICurvePrimitive, AddRuledSurfaceRayIntersections));

    c1.def("__repr__", [] (ICurvePrimitive& self)
           {
           return "(Tag:{}, Id:{}, Type:{})"_s.format(self.GetTag(), self.GetId(), self.GetCurvePrimitiveType());
           });
    }