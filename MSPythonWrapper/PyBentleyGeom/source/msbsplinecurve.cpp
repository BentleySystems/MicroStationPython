/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\msbsplinecurve.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom\MSBsplineCurve.h>



static const char * __doc_Bentley_Geom_MSBsplineCurve_AlmostEqual =R"doc(Compare curves.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AreSameKnots =R"doc(Compare knots. Absolute tolerance 1e-8 for knots in -1..1. Relative
tolerance 1e-8 outside.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AreSameWeights =R"doc(Compare weights with arbitrary but consistent tolerance.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ApproximateAnyCurve =R"doc(This routine computes a B-spline curve approximated the old one.
return ERROR if no results.

Parameter ``[in]``:
    pIn Input G1 curve.

Parameter ``[in]``:
    tolerance Geometric tolerance, this should be in general the chord
    height tol.

Parameter ``[in]``:
    order Desired degree of the pOut, 4 is recommended.

Parameter ``[in]``:
    parametrization CHORDLENGTH = 2, CENTRIPETAL = 3.

Parameter ``[in]``:
    bMaintainEndTangents true to maintain the end tangents.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_InitFromBeziers =R"doc(Create a B-spline curve from a series of Bezier curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_InitFromDEllipse3d =R"doc(Initialize the B-spline curve for an ellipse.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AppendCurves =R"doc(Create the B-spline curve by appending two input curves with
continuity and reparameterization constraints.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CleanKnots =R"doc(Clean all unnecessary knots.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetRemovalKnotBound =R"doc(Compute the bound of remove r-th knot s times)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_RemoveKnotsBounded =R"doc(Remove all removable knots with the tolerance and end condition
constraints.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ProjectToZFocalPlane =R"doc(convert to a weighted curve whose normalized points fall on a focal
plane)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_TransformCurve4d =R"doc(Transform the B-spline curve using a 4d transformation.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_TransformCurve =R"doc(Transform the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_RotateCurve =R"doc(Rotate the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetRangeOfProjectionOnRay =R"doc(Get the range of parameters of the projection of (a fractional portion
of the curve onto a ray return range whose low and high values are the
extreme parameters (in ray fractions) of the projection of the curve
onto the ray.

Parameter ``[in]``:
    ray ray to project to

Parameter ``[in]``:
    fraction0 start of active part of the curve

Parameter ``[in]``:
    fraction1 end of active part of the curve)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetRange =R"doc(Get the range of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetPoleRange =R"doc(Get the range of the poles of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_Resolution =R"doc(Get a (fairly tight) tolerance for the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_PolygonLength =R"doc(Compute the length of the control polygon of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetC1DiscontinuousFractions =R"doc(Get all C1 fractional Discontinuities. This inspects xyz and tangent
at each knot break. (It does not look for intraknot cusps)
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MakeBeziers =R"doc(Create a series of Bezier curve for the B-spline curve.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MakeBezier =R"doc(Create equivalent Bezier curve for the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ElevateDegree =R"doc(Elevate the degree (increases the order) of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_IsSameGeometry =R"doc(Check if the B-spline curves has same parameters with the given curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AppendCurve =R"doc(Change the B-spline curve by appending a given curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateFromPointsAndOrder =R"doc(Create the B-spline curve from point array and order.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AllParallellTangentsXY =R"doc(Find all curve points X where the tangents is parallel to the given
vector.

Parameter ``[out]``:
    points array to receive points.

Parameter ``[out]``:
    fractions array to receive fraction parameters.

Parameter ``[in]``:
    vector given direction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AllTangents =R"doc(For space point Q, find all curve points X where line XQ is tangent to
the curve.

Parameter ``[out]``:
    points array to receive points.

Parameter ``[out]``:
    fractions array to receive fraction parameters.

Parameter ``[in]``:
    spacePoint space point.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AllTangentsXY =R"doc(For space point Q (spacePoint), find all curve points X where line XQ
is tangent to the curve.

Parameter ``[out]``:
    points array to receive points.

Parameter ``[out]``:
    fractions array to receive fraction parameters.

Parameter ``[in]``:
    spacePoint space point.

Parameter ``[in]``:
    matrix optional transformation into viewing space.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetStrokeCount =R"doc(Compute stroke count)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_PointsAtUniformArcLength =R"doc(Compute points at uniform arclength steps.

Parameter ``[out]``:
    points array to receive points.

Parameter ``[out]``:
    fractions array to receive fractions.

Parameter ``[in]``:
    numPoints number of points.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_PointsAtUniformFractions =R"doc(Compute strokes at uniform fraction step.

Parameter ``[out]``:
    points array to receive points.

Parameter ``[out]``:
    fractions array to receive fractions.

Parameter ``[in]``:
    numPoints number of points.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ExtractEndPoints =R"doc(Extract the start or end point of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ExtractSegmentBetweenKnots =R"doc(Exteact the curve from the B-spline curve at the interval
[unnormalizedKnotA, unnormalizedKnotB].)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MakeRational =R"doc(Make an equivalent rational B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MakeReversed =R"doc(Reverse the direction of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MakeClosed =R"doc(Close the open B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MakeOpen =R"doc(Open the closed B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AddCuspsXY =R"doc(Find full cusps as viewed in xy.

Parameter ``[out]``:
    points array to receive xyz of cusps.

Parameter ``[out]``:
    fractionParameters array to receive fraction parameters of cusps.

Parameter ``[in]``:
    matrix optional transformation into viewing space.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AddCusps =R"doc(Find full 3d cusps.

Parameter ``[out]``:
    points array to receive xyz of cusps.

Parameter ``[out]``:
    fractionParameters array to receive fraction parameters of cusps.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ComputeInflectionPointsXY =R"doc(Calculate the parameters and location of the all inflection points of
a B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ComputeInflectionPoints =R"doc(Calculate the parameters and location of the all inflection points of
a B-spline curve. @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_Length =R"doc(compute the length of the B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetTailBezierSelect =R"doc(return an index to use to start " Retreat " order bezier access.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_FindKnotInterval =R"doc(Return the index of the knot at the left of the interval containing
specified knot. When knotValue exactly matches a knot, the returned
index is of the knot to the left - i.e. knotValue appears at the RIGHT
of the returned interval. (favor knot[index]<knotValue <= knot[index
+ 1]))doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CountDistinctBeziers =R"doc(Count the number of beziers that have non-null knot intervals.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetBezier =R"doc(Get poles for a single bezier poles from the curve. return false if
invalid bezierSelect. Note that the bezierSelect for a high
multiplicity knot returns true for the function but marks the interval
as null. Normal usage is to loop over all beziers in a bspline but
skip processing the null intervals.

Parameter ``[out]``:
    segment a filled BCurveSegment.

Parameter ``[in]``:
    bezierSelect selects a bezier interval within the bspline
    @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopyTransformed =R"doc(Create B-spline curve by transforming a B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopyFractionSegment =R"doc(Create B-spline curve by extracting a part of a B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopySegment =R"doc(Create B-spline curve by extracting a part of a B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopyReversed =R"doc(Create B-spline curve by reserving the direction of a B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopyClosed =R"doc(Create B-spline curve by closing a open B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopyOpen =R"doc(Create B-spline curve by opening a closed B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_NormalizeKnots =R"doc(Normalize knots to 01)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AddKnot =R"doc(Add a given knot value to the B-spline curve. that newMultiplicity is
the desired final multiplicity of a knot that may already exist.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_MapKnots =R"doc(rewrite knot values in a..b. Return true if a,b and current start,end
define a valid scale factor)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetPolygonDisplay =R"doc(Set the polygon display flag.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetPolygonDisplay =R"doc(Return polygon display flag.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetCurveDisplay =R"doc(Set the curve display flag.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetCurveDisplay =R"doc(Return curve display flag.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AreKnotsValid =R"doc(Return false if knot counts or values are invalid.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetKnots =R"doc(Copy all knots out into caller array.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetWeights =R"doc(Copy all weights out into caller array.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetPoles =R"doc(Copy all poles out into caller array.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetUnWeightedPoles =R"doc(Copy all poles out into caller array, dividing each by its weight)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetPoleDPoint4d =R"doc(return pole by index. returns 0 point if out of range. (Use
NumberAllocatedPoles to determine index range). @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_WeightPoles =R"doc(if the curve is rational, multiply (wx,wy,wz) style poles by the
weights)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_UnWeightPoles =R"doc(if the curve is rational, divide (wx,wy,wz) style poles by the weights)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetKnots =R"doc(set weight by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetWeights =R"doc(set weight by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetPoles =R"doc(set pole by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetKnot =R"doc(set weight by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetWeight =R"doc(set weight by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetReWeightedPole =R"doc(set pole by index. returns false if index out of range. If the curve
is weighted, the current weight is multiplied into the input pole.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SetPole =R"doc(set pole by index. returns false if index out of range.
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetKnotP =R"doc(return pointer to contiguous knots. @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetWeightP =R"doc(return pointer to contiguous weights @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetPoleP =R"doc(return pointer to contiguous poles. @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_TransformPoles =R"doc(Apply a transform to a single pole.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetUnWeightedPole =R"doc(return pole by index. returns 0 point if out of range. If spline is
weighted, the weight is divided out. If weight zero, no division
happens. (Use NumberAllocatedPoles to determine index range).
@DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetReverseWeight =R"doc(return weight by index, counting from the last weight. (i.e. index 0
is the final weight) Returns 1.0 if out of range. (Use
NumberAllocatedPoles to determine index range). @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetReversePole =R"doc(return pole by index, counting from the last pole . (i.e. index 0 is
the final weight) Returns 0 point if out of range. (Use
NumberAllocatedPoles to determine index range). @DotNetMethodExclude)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetKnot =R"doc(return knot by index. returns 0 if out of range. (Use
NumberAllocatedKnots to determine index range).)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetKnotRange =R"doc(Return the knot values corresponding to fraction 0 and fraction 1 ...)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_KnotToFraction =R"doc(Return the fractional parameter corresponding to a knot value ...)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_FractionToKnot =R"doc(Return the knot value at a fractional parameter ...)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ComputeDerivatives =R"doc(Calculate the number of derivatives specified by numDervs of the
B-spline curve at a particular fraction.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ComputeUniformKnots =R"doc(Compute uniformly spaced knots. This uses counts from params.

Returns:
    false if param counts are not set.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CopyFrom =R"doc()doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AllocateWeights =R"doc(<summary>Allocate weight pointer to specified count. (Optionally)copy
data from callers buffer</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AllocateKnots =R"doc(<summary>Allocate knot pointer to specified count. (Optionally)copy
data from callers buffer</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AllocatePoles =R"doc(<summary>Allocate pole pointer to specified count. (Optionally)copy
data from callers buffer</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ReleaseMem =R"doc(Free memory allocated for the poles, weights and knot vector of a
B-spline curve.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_Allocate =R"doc(Allocate memory arrays to match the current counts.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_SwapContents =R"doc(Exchange all bits with other. Usually used to transfer poles etc and
leave zeros behind.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_Zero =R"doc(<summary>Zero out the curve. This is customarily applied immediately
after allocation on stack or heap. This does NOT free memory from
prior contents. </summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_HasWeights =R"doc(Check whether the B-spline curve has stored weights (This does not
check if any are other than 1.0))doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_IsClosed =R"doc(Check whether the B-spline curve is periodic.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_IsPhysicallyClosed =R"doc(Check whether the B-spline curve is physically closed. A B-spline
curve may be non-periodic, but still return true if its first and last
poles coincide.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_AreCompatible =R"doc(<summary>Test if two curves have compatible knots, order, and pole
count</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateInterpolationBetweenCurves =R"doc(<summary>Create a curve whose poles are interpolated between the poles
of two curves.</summary> <remarks>This will only succeed if the curves
have the same pole, knot, and order structure</remarks>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetC1DiscontinuousCurves =R"doc(Create copies of each segment with breaks at point or tangent changes.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_GetDisjointCurves =R"doc(Create copies of each segment with breaks at disjoint knot points.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyOffsetXY =R"doc(<summary>Copy with offset in XY plane.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyBezier =R"doc(<summary>Copy with all knots saturated.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyTransformed =R"doc(<summary>Copy with transform applied to poles.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyReversed =R"doc(<summary>Complete copy with reversed parameterization.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyBetweenKnots =R"doc(<summary>Copy the portion between specified knots.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyBetweenFractions =R"doc(<summary>Copy the portion between specified fractions.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyClosed =R"doc(<summary>Return copy as smart pointer target; if physically closed
revise poles to be a closed bspline</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyOpenAtKnot =R"doc(<summary>Return copy as smart pointer target; if closed, open it at
knot.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopyOpenAtFraction =R"doc(<summary>Return copy as smart pointer target; if closed, open it at
fraction.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCopy =R"doc(<summary>Return copy as smart pointer target.</summary>)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_ExtractTo =R"doc(Copy bits into simple structure. Caller instance zeroed.)doc";

static const char * __doc_Bentley_Geom_MSBsplineCurve_CreateCapture =R"doc(<summary>Copy bits into smart pointer. Caller instance zeroed
out.<summary>)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_MSBsplineCurve(py::module_& m)
    {
    //===================================================================================
    // struct MSBsplineCurve
    py::class_<MSBsplineCurve> c1(m, "MSBsplineCurve");
    py::bind_vector<MSBsplineCurveArray>(m, "MSBsplineCurveArray", py::module_local(false));
    py::class_<RefCountedMSBsplineCurve, std::unique_ptr<RefCountedMSBsplineCurve, py::nodelete>, MSBsplineCurve> cx(m, "RefCountedMSBsplineCurve", py::multiple_inheritance());
    py::bind_vector<MSBsplineCurvePtrArray>(m, "MSBsplineCurvePtrArray", py::module_local(false));

    if (true)
        {
        //===================================================================================
        // Enum MSBsplineCurve::KnotPosition
        py::enum_<MSBsplineCurve::KnotPosition>(c1, "KnotPosition", py::arithmetic())
            .value("eKNOTPOS_BEFORE_START", MSBsplineCurve::KNOTPOS_BEFORE_START)
            .value("eKNOTPOS_START", MSBsplineCurve::KNOTPOS_START)
            .value("eKNOTPOS_INTERVAL", MSBsplineCurve::KNOTPOS_INTERVAL)
            .value("eKNOTPOS_INTERIOR", MSBsplineCurve::KNOTPOS_INTERIOR)
            .value("eKNOTPOS_FINAL", MSBsplineCurve::KNOTPOS_FINAL)
            .value("eKNOTPOS_AFTER_FINAL", MSBsplineCurve::KNOTPOS_AFTER_FINAL)
            .export_values();
        }

    c1.def_static("Create", &MSBsplineCurve::CreatePtr);

    c1.def_static("CreateFromPolesAndOrder",
                  py::overload_cast<DPoint3dArray const&, DoubleArray const*, DoubleArray const*, int, bool, bool>(&MSBsplineCurve::CreateFromPolesAndOrder),
                  "poles"_a, "weights"_a, "knots"_a, "order"_a, "closed"_a, "inputPolesAlreadyWeighted"_a = true);

    c1.def_static("CreateFromPolesAndOrder", [](DPoint3dArray const& poles, int order, bool closed = true)
        {
        return MSBsplineCurve::CreateFromPolesAndOrder(poles.data(), (int)poles.size(), order, closed);
        }, "poles"_a, "order"_a, "closed"_a = true);

    c1.def_static("CreateFromPolesAndOrder", [](DPoint2dArray const& poles, int order, bool closed = true)
        {
        return MSBsplineCurve::CreateFromPolesAndOrder(poles.data(), (int)poles.size(), order, closed);
        }, "poles"_a, "order"_a, "closed"_a = true);

    c1.def("CreateCapture", &MSBsplineCurve::CreateCapture, DOC(Bentley, Geom, MSBsplineCurve, CreateCapture));    
    c1.def("ExtractTo", &MSBsplineCurve::ExtractTo, "dest"_a, DOC(Bentley, Geom, MSBsplineCurve, ExtractTo));    
    c1.def("CreateCopy", &MSBsplineCurve::CreateCopy, DOC(Bentley, Geom, MSBsplineCurve, CreateCopy));

    c1.def("CreateCopyOpenAtFraction", &MSBsplineCurve::CreateCopyOpenAtFraction, "fraction"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyOpenAtFraction));
    c1.def("CreateCopyOpenAtKnot", &MSBsplineCurve::CreateCopyOpenAtKnot, "knot"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyOpenAtKnot));
    c1.def("CreateCopyClosed", &MSBsplineCurve::CreateCopyClosed, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyClosed));

    c1.def("CreateCopyBetweenFractions", &MSBsplineCurve::CreateCopyBetweenFractions, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyBetweenFractions));
    c1.def("CreateCopyBetweenKnots", &MSBsplineCurve::CreateCopyBetweenKnots, "konot0"_a, "knot1"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyBetweenKnots));

    c1.def("CreateCopyReversed", &MSBsplineCurve::CreateCopyReversed, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyReversed));
    c1.def("CreateCopyTransformed", &MSBsplineCurve::CreateCopyTransformed, "transform"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyTransformed));
    c1.def("CreateCopyBezier", &MSBsplineCurve::CreateCopyBezier, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyBezier));
    c1.def("CreateCopyOffsetXY", &MSBsplineCurve::CreateCopyOffsetXY, "offset0"_a, "offset1"_a, "options"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateCopyOffsetXY));
    
    c1.def_static("CreateFromInterpolationAtBasisFunctionPeaks", &MSBsplineCurve::CreateFromInterpolationAtBasisFunctionPeaks, 
                  "xyz"_a, "order"_a, "selector"_a = 0);

    c1.def_static("CreateFromInterpolationAtGrevilleKnots", &MSBsplineCurve::CreateFromInterpolationAtGrevilleKnots, 
                  "curve"_a, "numPoles"_a, "order"_a, "normalizeKnots"_a, "knotSelector"_a = 0);

    c1.def_static("CreateFromInterpolationPointsWithKnots", &MSBsplineCurve::CreateFromInterpolationPointsWithKnots,
                  "xyz"_a, "interpolationKnots"_a, "curveKnots"_a, "order"_a);
    
    c1.def("GetDisjointCurves", &MSBsplineCurve::GetDisjointCurves, "curves"_a, DOC(Bentley, Geom, MSBsplineCurve, GetDisjointCurves));
    c1.def("GetC1DiscontinuousCurves", &MSBsplineCurve::GetC1DiscontinuousCurves, "fractions"_a, "curves"_a, DOC(Bentley, Geom, MSBsplineCurve, GetC1DiscontinuousCurves));
    
    c1.def_static("CreateInterpolationBetweenCurves", &MSBsplineCurve::CreateInterpolationBetweenCurves, "curveA"_a, "fraction"_a, "curveB"_a, DOC(Bentley, Geom, MSBsplineCurve, CreateInterpolationBetweenCurves));
    c1.def_static("AreCompatible", &MSBsplineCurve::AreCompatible, "curveA"_a, "curveB"_a, DOC(Bentley, Geom, MSBsplineCurve, AreCompatible));

    c1.def("IsPhysicallyClosed", &MSBsplineCurve::IsPhysicallyClosed, "tolerance"_a, DOC(Bentley, Geom, MSBsplineCurve, IsPhysicallyClosed));
    c1.def("IsClosed", &MSBsplineCurve::IsClosed, DOC(Bentley, Geom, MSBsplineCurve, IsClosed));    

    c1.def("IsParabola", [] (MSBsplineCurveCR self, TransformR localToWorld, TransformR worldToLocal, DPoint3dR localStart, DPoint3dR localEnd)
           {
           double vertexFraction = 0;
           double xSquaredCoefficient = 0;
           bool bOk = self.IsParabola(localToWorld, worldToLocal, vertexFraction, localStart, localEnd, xSquaredCoefficient);
           return py::make_tuple(bOk, vertexFraction, xSquaredCoefficient);
           }, "localToWorld"_a, "worldToLocal"_a, "localStart"_a, "localEnd"_a);

    c1.def("HasWeights", &MSBsplineCurve::HasWeights, DOC(Bentley, Geom, MSBsplineCurve, HasWeights));
    c1.def("Zero", &MSBsplineCurve::Zero, DOC(Bentley, Geom, MSBsplineCurve, Zero));

    c1.def("SwapContents", &MSBsplineCurve::SwapContents, "other"_a, DOC(Bentley, Geom, MSBsplineCurve, SwapContents));
    c1.def("Allocate", py::overload_cast<>(&MSBsplineCurve::Allocate), DOC(Bentley, Geom, MSBsplineCurve, Allocate));
    c1.def("Allocate", py::overload_cast<int, int, bool, bool>(&MSBsplineCurve::Allocate), "numPoles"_a, "order"_a, "closed"_a, "rational"_a, DOC(Bentley, Geom, MSBsplineCurve, Allocate));
    c1.def("ReleaseMem", &MSBsplineCurve::ReleaseMem, DOC(Bentley, Geom, MSBsplineCurve, ReleaseMem));

    c1.def("AllocatePoles", &MSBsplineCurve::AllocatePoles, "count"_a, "data"_a = nullptr, DOC(Bentley, Geom, MSBsplineCurve, AllocatePoles));
    c1.def("AllocateKnots", &MSBsplineCurve::AllocateKnots, "count"_a, "data"_a = nullptr, DOC(Bentley, Geom, MSBsplineCurve, AllocateKnots));
    c1.def("AllocateWeights", &MSBsplineCurve::AllocateWeights, "count"_a, "data"_a = nullptr, DOC(Bentley, Geom, MSBsplineCurve, AllocateWeights));

    c1.def("CopyFrom", &MSBsplineCurve::CopyFrom, "source"_a, DOC(Bentley, Geom, MSBsplineCurve, CopyFrom));
    c1.def("ComputeUniformKnots", &MSBsplineCurve::ComputeUniformKnots, DOC(Bentley, Geom, MSBsplineCurve, ComputeUniformKnots));

    c1.def("FractionToPoint",
           py::overload_cast<DPoint3dR, double>(&MSBsplineCurve::FractionToPoint, py::const_),
           "xyz"_a, "f"_a);

    c1.def("FractionToPoint",
           py::overload_cast<DPoint3dR, DVec3dR, double>(&MSBsplineCurve::FractionToPoint, py::const_),
           "xyz"_a, "tangent"_a, "f"_a);

    c1.def("FractionToPoint", [] (MSBsplineCurveCR self, DPoint3dR xyz, DVec3dR tangent, double f)
           {
           double weight = 0;
           self.FractionToPoint(xyz, weight, tangent, f);
           return weight;
           }, "xyz"_a, "tangent"_a, "f"_a);

    c1.def("FractionToPoint",
           py::overload_cast<DPoint3dR, DVec3dR, DVec3dR, double>(&MSBsplineCurve::FractionToPoint, py::const_),
           "xyz"_a, "dXYZ"_a, "ddXYZ"_a, "f"_a);

    c1.def("FractionToPoints",
           py::overload_cast<DPoint3dArray&, size_t>(&MSBsplineCurve::FractionToPoints),
           "points"_a, "numPoints"_a);

    c1.def("FractionToPoints",
           py::overload_cast<DPoint3dArray&, DoubleArray&>(&MSBsplineCurve::FractionToPoints),
           "points"_a, "fractions"_a);

    c1.def("GetFrenetFrame", [] (MSBsplineCurveCR self, DVec3dArray frame, DPoint3dR point, double u)
           {
           double curvature = 0;
           double torsion = 0;
           MSBsplineStatus retVal = self.GetFrenetFrame(frame.data(), point, curvature, torsion, u);
           return py::make_tuple(retVal, curvature, torsion);
           }, "frame"_a, "point"_a, "u"_a);

    c1.def("GetFrenetFrame",
           py::overload_cast<TransformR, double>(&MSBsplineCurve::GetFrenetFrame, py::const_),
           "frame"_a, "u"_a);

    c1.def("ComputeDerivatives", [](MSBsplineCurveCR self, DVec3dArray& dervs, int numDervs, double u)
            {
            DVec3d* pDervs = new DVec3d[numDervs+1];
            self.ComputeDerivatives (pDervs , numDervs, u);
            for (int i = 0; i < numDervs+1; i++)
                dervs.push_back (pDervs[i]);

            delete[] pDervs;
            pDervs = nullptr;
            });

    c1.def("ClosestPoint", [] (MSBsplineCurveCR self, DPoint3dR curvePoint, DPoint3dCR spacePoint)
           {
           double fraction = 0;
           self.ClosestPoint(curvePoint, fraction, spacePoint);
           return fraction;
           }, "curvePoint"_a, "spacePoint"_a);

    c1.def("ClosestPointXY", [] (MSBsplineCurveCR self, DPoint3dR curvePoint, DPoint3dCR spacePoint, DMatrix4dCP viewMatrix)
           {
           double fraction = 0;
           double xyDistance = 0;
           self.ClosestPointXY(curvePoint, fraction, xyDistance, spacePoint, viewMatrix);
           return py::make_tuple(fraction, xyDistance);
           }, "curvePoint"_a, "spacePoint"_a, "viewMatrix"_a);

    c1.def("FractionToKnot", &MSBsplineCurve::FractionToKnot, "f"_a, DOC(Bentley, Geom, MSBsplineCurve, FractionToKnot));
    c1.def("KnotToFraction", &MSBsplineCurve::KnotToFraction, "knot"_a, DOC(Bentley, Geom, MSBsplineCurve, KnotToFraction));
            
    c1.def_static("MapFractions", &MSBsplineCurve::MapFractions,
                  "params"_a, "derivatives"_a, "i0"_a, "knot0"_a, "knot1"_a, "select"_a, "curve"_a);

    c1.def("GetKnotRange", [] (MSBsplineCurveCR self)
           {
           double knotA, knotB;
           int indexA, indexB;
           double knotTolerance;
           self.GetKnotRange(knotA, knotB, indexA, indexB, knotTolerance);
           return py::make_tuple(knotA, knotB, indexA, indexB, knotTolerance);
           });

    c1.def("GetKnotRange", py::overload_cast<>(&MSBsplineCurve::GetKnotRange, py::const_), DOC(Bentley, Geom, MSBsplineCurve, GetKnotRange));

    c1.def("GetKnot", &MSBsplineCurve::GetKnot, "index"_a, DOC(Bentley, Geom, MSBsplineCurve, GetKnot));

    c1.def("KnotToBlendFunctions", [] (MSBsplineCurveCR self, double* blend, double* blendDerivative, double u)
           {
           size_t knotIndex = 0;
           self.KnotToBlendFunctions(blend, blendDerivative, knotIndex, u);
           return knotIndex;
           }, "blend"_a, "blendDerivatives"_a, "u"_a); //TODO

    c1.def("GetPole", py::overload_cast<size_t>(&MSBsplineCurve::GetPole, py::const_), "index"_a);
    c1.def("GetReversePole", py::overload_cast<size_t>(&MSBsplineCurve::GetReversePole, py::const_), "index"_a, DOC(Bentley, Geom, MSBsplineCurve, GetReversePole));
    c1.def("GetReverseWeight", py::overload_cast<size_t>(&MSBsplineCurve::GetReverseWeight, py::const_), "index"_a, DOC(Bentley, Geom, MSBsplineCurve, GetReverseWeight));
    c1.def("GetUnWeightedPole", py::overload_cast<size_t, bool>(&MSBsplineCurve::GetUnWeightedPole, py::const_), "index"_a, "reverse"_a = false, DOC(Bentley, Geom, MSBsplineCurve, GetUnWeightedPole));

    c1.def("TransformPoles", &MSBsplineCurve::TransformPoles, "transform"_a, "index"_a, "n"_a, DOC(Bentley, Geom, MSBsplineCurve, TransformPoles));
    c1.def("GetPoleP", &MSBsplineCurve::GetPoleP, py::return_value_policy::reference, DOC(Bentley, Geom, MSBsplineCurve, GetPoleP));
    c1.def("GetWeightP", &MSBsplineCurve::GetWeightP, py::return_value_policy::reference, DOC(Bentley, Geom, MSBsplineCurve, GetWeightP));
    c1.def("GetKnotP", &MSBsplineCurve::GetKnotP, py::return_value_policy::reference, DOC(Bentley, Geom, MSBsplineCurve, GetKnotP));
        
    c1.def("GetWeightRange", &MSBsplineCurve::GetWeightRange);
    c1.def("SetPole", py::overload_cast<size_t, DPoint3dCR>(&MSBsplineCurve::SetPole), "index"_a, "value"_a, DOC(Bentley, Geom, MSBsplineCurve, SetPole));
    c1.def("SetPole", py::overload_cast<size_t, double, double, double>(&MSBsplineCurve::SetPole), "index"_a, "x"_a, "y"_a, "z"_a, DOC(Bentley, Geom, MSBsplineCurve, SetPole));
    c1.def("SetReWeightedPole", py::overload_cast<size_t, DPoint3dCR, bool>(&MSBsplineCurve::SetReWeightedPole), "index"_a, "value"_a, "reverse"_a = false, DOC(Bentley, Geom, MSBsplineCurve, SetReWeightedPole));    
    c1.def("SetWeight", py::overload_cast<size_t, double>(&MSBsplineCurve::SetWeight), "index"_a, "value"_a, DOC(Bentley, Geom, MSBsplineCurve, SetWeight));
    c1.def("SetKnot", py::overload_cast<size_t, double>(&MSBsplineCurve::SetKnot), "index"_a, "value"_a, DOC(Bentley, Geom, MSBsplineCurve, SetKnot));

    c1.def("TransformPoles", &MSBsplineCurve::TransformPoles, "transform"_a, "index"_a, "n"_a, DOC(Bentley, Geom, MSBsplineCurve, TransformPoles));
        
    c1.def("SetPoles", &MSBsplineCurve::SetPoles, "index"_a, "value"_a, "n"_a, DOC(Bentley, Geom, MSBsplineCurve, SetPoles));
    c1.def("SetWeights", &MSBsplineCurve::SetWeights, "index"_a, "value"_a, "n"_a, DOC(Bentley, Geom, MSBsplineCurve, SetWeights));
    c1.def("SetKnots", &MSBsplineCurve::SetKnots, "index"_a, "value"_a, "n"_a, DOC(Bentley, Geom, MSBsplineCurve, SetKnots));
    c1.def("UnWeightPoles", &MSBsplineCurve::UnWeightPoles, DOC(Bentley, Geom, MSBsplineCurve, UnWeightPoles));
    c1.def("WeightPoles", &MSBsplineCurve::WeightPoles, DOC(Bentley, Geom, MSBsplineCurve, WeightPoles));

    c1.def("GetPoleDPoint4d", &MSBsplineCurve::GetPoleDPoint4d, "index"_a, DOC(Bentley, Geom, MSBsplineCurve, GetPoleDPoint4d));
    c1.def("GetWeight", py::overload_cast<size_t>(&MSBsplineCurve::GetWeight, py::const_), "index");
    c1.def("GetUnWeightedPoles", &MSBsplineCurve::GetUnWeightedPoles, "outData"_a, DOC(Bentley, Geom, MSBsplineCurve, GetUnWeightedPoles));
    c1.def("GetPoles", &MSBsplineCurve::GetPoles, "outData"_a, DOC(Bentley, Geom, MSBsplineCurve, GetPoles));
    c1.def("GetWeights", &MSBsplineCurve::GetWeights, "outData"_a, DOC(Bentley, Geom, MSBsplineCurve, GetWeights));
    c1.def("GetKnots", &MSBsplineCurve::GetKnots, "outData"_a, DOC(Bentley, Geom, MSBsplineCurve, GetKnots));
        
    c1.def_static("CompressKnots", [] (DoubleArray const& inKnot, int order, DoubleArray& outKnot, UInt64Array& multiplicities)
                  {
                  size_t lowActiveIndex, highActiveIndex;
                  MSBsplineCurve::CompressKnots(inKnot, order, outKnot, multiplicities, lowActiveIndex, highActiveIndex);
                  return py::make_tuple(lowActiveIndex, highActiveIndex);
                  }, "inKnot"_a, "order"_a, "outKnot"_a, "multiplicities"_a);

    c1.def("GetKnots", &MSBsplineCurve::GetPoles4d, "outData"_a, DOC(Bentley, Geom, MSBsplineCurve, GetKnots));

    c1.def("GetOrder", &MSBsplineCurve::GetOrder);
    c1.def("GetNumPoles", &MSBsplineCurve::GetNumPoles);
    c1.def("GetNumKnots", &MSBsplineCurve::GetNumKnots);
    c1.def("AreKnotsValid", &MSBsplineCurve::AreKnotsValid, "clampingRequired"_a = true, DOC(Bentley, Geom, MSBsplineCurve, AreKnotsValid));

    c1.def_property("CurveDisplay", &MSBsplineCurve::GetCurveDisplay, &MSBsplineCurve::SetCurveDisplay);
    c1.def("GetCurveDisplay", &MSBsplineCurve::GetCurveDisplay, DOC(Bentley, Geom, MSBsplineCurve, GetCurveDisplay));
    c1.def("SetCurveDisplay", &MSBsplineCurve::SetCurveDisplay, "value"_a, DOC(Bentley, Geom, MSBsplineCurve, SetCurveDisplay));

    c1.def_property("PolygonDisplay", &MSBsplineCurve::GetPolygonDisplay, &MSBsplineCurve::SetPolygonDisplay);
    c1.def("GetPolygonDisplay", &MSBsplineCurve::GetPolygonDisplay, DOC(Bentley, Geom, MSBsplineCurve, GetPolygonDisplay));
    c1.def("SetPolygonDisplay", &MSBsplineCurve::SetPolygonDisplay, "value"_a, DOC(Bentley, Geom, MSBsplineCurve, SetPolygonDisplay));

    c1.def("MapKnots", &MSBsplineCurve::MapKnots, "a"_a, "b"_a, DOC(Bentley, Geom, MSBsplineCurve, MapKnots));
    c1.def("AddKnot", &MSBsplineCurve::AddKnot, "unnormalizedKnotValue"_a, "newMultiplicity"_a, DOC(Bentley, Geom, MSBsplineCurve, AddKnot));
    c1.def("NormalizeKnots", &MSBsplineCurve::NormalizeKnots, DOC(Bentley, Geom, MSBsplineCurve, NormalizeKnots));
    c1.def("ComputeGrevilleAbscissa", &MSBsplineCurve::ComputeGrevilleAbscissa, "averageKnots"_a = true);
    c1.def_static("ComputeUniformKnotGrevilleAbscissa", &MSBsplineCurve::ComputeUniformKnotGrevilleAbscissa, "averageKnots"_a, "numInterval"_a, "order"_a);

    c1.def("CopyOpen", &MSBsplineCurve::CopyOpen, "source"_a, "unnormalizedKnot"_a, DOC(Bentley, Geom, MSBsplineCurve, CopyOpen));
    c1.def("CopyClosed", &MSBsplineCurve::CopyClosed, "source"_a, DOC(Bentley, Geom, MSBsplineCurve, CopyClosed));
    c1.def("CopyReversed", &MSBsplineCurve::CopyReversed, "source"_a, DOC(Bentley, Geom, MSBsplineCurve, CopyReversed));
    c1.def("CopySegment", &MSBsplineCurve::CopySegment, "source"_a, "unnormalizedKnotA"_a, "unnormalizedKnotB"_a, DOC(Bentley, Geom, MSBsplineCurve, CopySegment));
    c1.def("CopyFractionSegment", &MSBsplineCurve::CopyFractionSegment, "source"_a, "fractionA"_a, "fractionB"_a, DOC(Bentley, Geom, MSBsplineCurve, CopyFractionSegment));
    c1.def("CopyTransformed", &MSBsplineCurve::CopyTransformed, "source"_a, "transform"_a, DOC(Bentley, Geom, MSBsplineCurve, CopyTransformed));
    c1.def("GetBezier", &MSBsplineCurve::GetBezier, "segment"_a, "bezierSelect"_a, DOC(Bentley, Geom, MSBsplineCurve, GetBezier));
    c1.def("CountDistinctBeziers", &MSBsplineCurve::CountDistinctBeziers, DOC(Bentley, Geom, MSBsplineCurve, CountDistinctBeziers));
    c1.def("FindKnotInterval", &MSBsplineCurve::FindKnotInterval, "knotValue"_a, DOC(Bentley, Geom, MSBsplineCurve, FindKnotInterval));

    c1.def("AdvanceToBezierInKnotInterval", [] (MSBsplineCurveCR self, BCurveSegmentR segment, size_t& bezierSelect, DRange1dCR interval)
           {
           bool bOk = self.AdvanceToBezierInKnotInterval(segment, bezierSelect, interval);
           return py::make_tuple(bOk, bezierSelect);
           }, "segment"_a, "bezierSelect"_a, "interval"_a);

    c1.def("AdvanceToBezierInFractionInterval", [] (MSBsplineCurveCR self, BCurveSegmentR segment, DRange1dCR interval)
           {
           size_t bezierSelect = 0;
           bool bOk = self.AdvanceToBezierInFractionInterval(segment, bezierSelect, interval);
           return py::make_tuple(bOk, bezierSelect);
           }, "segment"_a, "interval"_a);

    c1.def("GetTailBezierSelect", &MSBsplineCurve::GetTailBezierSelect, DOC(Bentley, Geom, MSBsplineCurve, GetTailBezierSelect));

    c1.def("RetreatToBezierInKnotInterval", [] (MSBsplineCurveCR self, BCurveSegmentR segment, size_t& bezierSelect, DRange1dCR interval)
           {
           bool bOk = self.RetreatToBezierInKnotInterval(segment, bezierSelect, interval);
           return py::make_tuple(bOk, bezierSelect);
           }, "segment"_a, "bezierSelect"_a, "interval"_a);

    c1.def("SearchKnot", [] (MSBsplineCurveCR self, double unnormalizedKnotValue)
           {
           int k0, k1;
           double correctedKnotValue;
           auto retVal = self.SearchKnot(unnormalizedKnotValue, k0, k1, correctedKnotValue);
           return py::make_tuple(retVal, k0, k1, correctedKnotValue);
           }, "unnormalizedKnotValue"_a);

    c1.def("Length", py::overload_cast<>(&MSBsplineCurve::Length, py::const_), DOC(Bentley, Geom, MSBsplineCurve, Length));
    c1.def("Length", py::overload_cast<RotMatrixCP>(&MSBsplineCurve::Length, py::const_), "worldToLocal"_a, DOC(Bentley, Geom, MSBsplineCurve, Length));
    
    c1.def("LengthBetweenKnots", 
           py::overload_cast<double, double>(&MSBsplineCurve::LengthBetweenKnots, py::const_), 
           "startKnot"_a, "endKnot"_a);

    c1.def("LengthBetweenKnots", 
           py::overload_cast<RotMatrixCP, double, double>(&MSBsplineCurve::LengthBetweenKnots, py::const_), 
           "worldToLocal"_a, "startKnot"_a, "endKnot"_a);

    c1.def("LengthBetweenFractions",
           py::overload_cast<double, double>(&MSBsplineCurve::LengthBetweenFractions, py::const_),
           "startKnot"_a, "endKnot"_a);

    c1.def("LengthBetweenFractions",
           py::overload_cast<RotMatrixCP, double, double>(&MSBsplineCurve::LengthBetweenFractions, py::const_),
           "worldToLocal"_a, "startKnot"_a, "endKnot"_a);

    c1.def("FractionAtSignedDistance", [] (MSBsplineCurveCR self, double startParam, double signedDistance)
           {
           double endParam = 0;
           double actualSignedDistance = 0;
           bool bOk = self.FractionAtSignedDistance(startParam, signedDistance, endParam, actualSignedDistance);
           return py::make_tuple(bOk, endParam, actualSignedDistance);
           }, "startParam"_a, "signedDistance"_a);

    c1.def("FractionAtSignedDistance", [] (MSBsplineCurveCR self, RotMatrixCP worldToLocal, double startParam, double signedDistance)
           {
           double endParam = 0;
           double actualSignedDistance = 0;
           bool bOk = self.FractionAtSignedDistance(worldToLocal, startParam, signedDistance, endParam, actualSignedDistance);
           return py::make_tuple(bOk, endParam, actualSignedDistance);
           }, "worldToLocal"_a, "startParam"_a, "signedDistance"_a);      
        

     c1.def("ComputeInflectionPoints", py::overload_cast<DPoint3dArray&, DoubleArray&>(&MSBsplineCurve::ComputeInflectionPoints), "points"_a, "params"_a, DOC(Bentley, Geom, MSBsplineCurve, ComputeInflectionPoints));
     c1.def("ComputeInflectionPointsXY", &MSBsplineCurve::ComputeInflectionPointsXY, "points"_a, "params"_a, "transform"_a, DOC(Bentley, Geom, MSBsplineCurve, ComputeInflectionPointsXY));

     c1.def("AddPlaneIntersections",
            py::overload_cast<DPoint3dArray*, DoubleArray*, DPlane3dCR>(&MSBsplineCurve::AddPlaneIntersections, py::const_),
            "point"_a, "fractionParameters"_a, "plane"_a);

     c1.def("AddPlaneIntersections",
            py::overload_cast<DPoint3dArray*, DoubleArray*, DPoint4dCR>(&MSBsplineCurve::AddPlaneIntersections, py::const_),
            "point"_a, "fractionParameters"_a, "planeCoeffs"_a);

    c1.def("AddLineIntersectionsXY", 
            py::overload_cast<DPoint3dArray*, DoubleArray*, DPoint3dArray*, DoubleArray*, DSegment3dCR, bool, DMatrix4dCP>(&MSBsplineCurve::AddLineIntersectionsXY, py::const_),
            "curvePoints"_a, "curveFractions"_a, "linePoints"_a, "lineFractions"_a, "segment"_a, "extendSegment"_a, "matrix"_a);

    c1.def("AddLineIntersectionsXY", 
            py::overload_cast<DPoint3dArray*, DoubleArray*, DPoint3dArray*, DoubleArray*, DSegment3dCR, bool, bool, DMatrix4dCP>(&MSBsplineCurve::AddLineIntersectionsXY, py::const_),
            "curvePoints"_a, "curveFractions"_a, "linePoints"_a, "lineFractions"_a, "segment"_a, "extendSegment0"_a, "extendSegment1"_a, "matrix"_a);

     c1.def("AddLinestringIntersectionsXY", 
            py::overload_cast<DPoint3dArray*, DoubleArray*, DPoint3dArray*, DoubleArray*, DPoint3dArray const&, DMatrix4dCP>(&MSBsplineCurve::AddLinestringIntersectionsXY, py::const_),
            "curveAPoints"_a, "curveAFractions"_a, "curveBPoints"_a, "curveBFractions"_a, "lineString"_a, "matrix"_a);

     c1.def("AddLinestringIntersectionsXY",
            py::overload_cast<DPoint3dArray*, DoubleArray*, DPoint3dArray*, DoubleArray*, DPoint3dArray const&, bool, DMatrix4dCP>(&MSBsplineCurve::AddLinestringIntersectionsXY, py::const_),
            "curveAPoints"_a, "curveAFractions"_a, "curveBPoints"_a, "curveBFractions"_a, "lineString"_a, "extendLineString"_a, "matrix"_a);

     c1.def("AddArcIntersectionsXY", &MSBsplineCurve::AddArcIntersectionsXY,
            "curvePoints"_a, "curveFractions"_a, "ellipsePoints"_a, "ellipseFractions"_a, "arc"_a, "extendConic"_a, "matrix"_a);

     c1.def("AddCurveIntersectionsXY", &MSBsplineCurve::AddCurveIntersectionsXY,
            "curveAPoints"_a, "curveAFractions"_a, "curveBPoints"_a, "curveBFractions"_a, "curveB"_a, "matrix"_a);
        
     c1.def("AddCusps", &MSBsplineCurve::AddCusps, "points"_a, "fractionParameters"_a, DOC(Bentley, Geom, MSBsplineCurve, AddCusps));
     c1.def("AddCuspsXY", &MSBsplineCurve::AddCuspsXY, "points"_a, "fractionParameters"_a, "matrix"_a, DOC(Bentley, Geom, MSBsplineCurve, AddCuspsXY));
     c1.def("MakeOpen", &MSBsplineCurve::MakeOpen, "u"_a, DOC(Bentley, Geom, MSBsplineCurve, MakeOpen));
     c1.def("MakeClosed", &MSBsplineCurve::MakeClosed, DOC(Bentley, Geom, MSBsplineCurve, MakeClosed));
     c1.def("MakeReversed", &MSBsplineCurve::MakeReversed, DOC(Bentley, Geom, MSBsplineCurve, MakeReversed));
     c1.def("MakeRational", &MSBsplineCurve::MakeRational, DOC(Bentley, Geom, MSBsplineCurve, MakeRational));
     c1.def("ExtractSegmentBetweenKnots", &MSBsplineCurve::ExtractSegmentBetweenKnots, "target"_a, "unnormalizedKnotA"_a, "unnormalizedKnotB"_a, DOC(Bentley, Geom, MSBsplineCurve, ExtractSegmentBetweenKnots));
     c1.def("ExtractEndPoints", &MSBsplineCurve::ExtractEndPoints, "start"_a, "end"_a, DOC(Bentley, Geom, MSBsplineCurve, ExtractEndPoints));

     c1.def("ExtractCurveNormal", [] (MSBsplineCurveCR self, DVec3dR normal, DPoint3dR position)
            {
            double planarDeviation = 0;
            auto retVal = self.ExtractCurveNormal(normal, position, planarDeviation);
            return py::make_tuple(retVal, planarDeviation);
            }, "normal"_a, "position"_a);

     c1.def("AddStrokes", 
            py::overload_cast<DPoint3dArray&, double, double, double, bool>(&MSBsplineCurve::AddStrokes, py::const_),
            "points"_a, "chordTol"_a = 0.0, "angleTol"_a = 0.20, "maxEdgeLength"_a = 0.0, "includeStartPoint"_a = true);

     c1.def("AddStrokes",
            py::overload_cast<DPoint3dArray&, DVec3dArray*, DoubleArray*, double, double, double, bool, CurveParameterMapping>(&MSBsplineCurve::AddStrokes, py::const_),
            "points"_a, "derivatives"_a = nullptr, "params"_a = nullptr, "chordTol"_a = 0.0, "angleTol"_a = 0.20, "maxEdgeLength"_a = 0.0, "includeStartPoint"_a = true, "parameterSelect"_a = CURVE_PARAMETER_MAPPING_CurveKnot);

     c1.def("AddStrokes",
            py::overload_cast<IFacetOptionsCR, DPoint3dArray&, DVec3dArray*, DoubleArray*, bool>(&MSBsplineCurve::AddStrokes, py::const_),
            "options"_a, "points"_a, "derivatives"_a = nullptr, "params"_a = nullptr, "includeStart"_a = true);

     c1.def("AddStrokes",
            py::overload_cast<size_t, DPoint3dArray&, DVec3dArray*, DoubleArray*, bool, CurveParameterMapping>(&MSBsplineCurve::AddStrokes, py::const_),
            "numPoints"_a, "points"_a, "derivatives"_a = nullptr, "params"_a = nullptr, "includeStartPoint"_a = true, "parameterSelect"_a = CURVE_PARAMETER_MAPPING_CurveKnot);

     c1.def("PointsAtUniformFractions", &MSBsplineCurve::PointsAtUniformFractions, "points"_a, "fractions"_a, "numPoints"_a, DOC(Bentley, Geom, MSBsplineCurve, PointsAtUniformFractions));
     c1.def("PointsAtUniformArcLength", &MSBsplineCurve::PointsAtUniformArcLength, "points"_a, "fractions"_a, "numPoints"_a, DOC(Bentley, Geom, MSBsplineCurve, PointsAtUniformArcLength));

     c1.def("GetStrokeCount", &MSBsplineCurve::GetStrokeCount, "chordTol"_a, "angleTol"_a, "maxEdgeLength"_a, DOC(Bentley, Geom, MSBsplineCurve, GetStrokeCount));
     c1.def("AllTangentsXY", &MSBsplineCurve::AllTangentsXY, "points"_a, "fractions"_a, "spacePoint"_a, "matrix"_a, DOC(Bentley, Geom, MSBsplineCurve, AllTangentsXY));
     c1.def("AllTangents", &MSBsplineCurve::AllTangents, "points"_a, "fractions"_a, "spacePoint"_a, DOC(Bentley, Geom, MSBsplineCurve, AllTangents));

     c1.def("ClosestTangentXY", [] (MSBsplineCurveCR self, DPoint3dR curvePoint, DPoint3dCR spacePoint, DPoint3dCR biasPoint, DMatrix4dCP matrix)
            {
            double curveFraction = 0;
            bool bOk = self.ClosestTangentXY(curvePoint, curveFraction, spacePoint, biasPoint, matrix);
            return py::make_tuple(bOk, curveFraction);
            }, "curvePoint"_a, "spacePoint"_a, "biasPoint"_a, "matrix"_a);

     c1.def("ClosestTangent", [] (MSBsplineCurveCR self, DPoint3dR curvePoint, DPoint3dCR spacePoint, DPoint3dCR biasPoint)
            {
            double curveFraction = 0;
            bool bOk = self.ClosestTangent(curvePoint, curveFraction, spacePoint, biasPoint);
            return py::make_tuple(bOk, curveFraction);
            }, "curvePoint"_a, "spacePoint"_a, "biasPoint"_a);
     
     c1.def("AllParallellTangentsXY", &MSBsplineCurve::AllParallellTangentsXY, "points"_a, "fractions"_a, "vector"_a, DOC(Bentley, Geom, MSBsplineCurve, AllParallellTangentsXY));

     c1.def("CreateFromPointsAndOrder", [](MSBsplineCurveR self, DPoint3dArray const &pointArray, int order, bool closed)
            {
            return self.CreateFromPointsAndOrder (pointArray.data(), (int)pointArray.size(), order, closed);
            }, "pointArray"_a, "order"_a, "closed"_a = false, DOC(Bentley, Geom, MSBsplineCurve, CreateFromPointsAndOrder));

     c1.def("Populate",
            py::overload_cast<DPoint3dArray const&, DoubleArray const*, DoubleArray const*, int, bool, bool>(&MSBsplineCurve::Populate),
            "pointVector"_a, "weightVector"_a, "knotVector"_a, "order"_a, "closed"_a, "inputPolesAlreadyWeighted"_a);

     c1.def("AppendCurve", &MSBsplineCurve::AppendCurve, "inCurve"_a, DOC(Bentley, Geom, MSBsplineCurve, AppendCurve));
     c1.def("IsSameGeometry", &MSBsplineCurve::IsSameGeometry, "other"_a, DOC(Bentley, Geom, MSBsplineCurve, IsSameGeometry));
     c1.def("ElevateDegree", &MSBsplineCurve::ElevateDegree, "newDegree"_a, DOC(Bentley, Geom, MSBsplineCurve, ElevateDegree));
     
     c1.def("MakeBezier", &MSBsplineCurve::MakeBezier, "bezierCurve"_a, DOC(Bentley, Geom, MSBsplineCurve, MakeBezier));
     c1.def("MakeBeziers", &MSBsplineCurve::MakeBeziers, "beziers"_a, DOC(Bentley, Geom, MSBsplineCurve, MakeBeziers));
     
     c1.def("GetC1DiscontinuousFractions", &MSBsplineCurve::GetC1DiscontinuousFractions, "fractions"_a, DOC(Bentley, Geom, MSBsplineCurve, GetC1DiscontinuousFractions));
     c1.def("PolygonLength", &MSBsplineCurve::PolygonLength, DOC(Bentley, Geom, MSBsplineCurve, PolygonLength));
     
     c1.def("Resolution", py::overload_cast<>(&MSBsplineCurve::Resolution, py::const_), DOC(Bentley, Geom, MSBsplineCurve, Resolution));
     c1.def("Resolution", py::overload_cast<double, double>(&MSBsplineCurve::Resolution, py::const_), "abstol"_a, "reltol"_a, DOC(Bentley, Geom, MSBsplineCurve, Resolution));

     c1.def("GetPoleRange", &MSBsplineCurve::GetPoleRange, "range"_a, DOC(Bentley, Geom, MSBsplineCurve, GetPoleRange));

     c1.def_property_readonly("Range", &MSBsplineCurve::GetRange);
     c1.def("GetRange", &MSBsplineCurve::GetRange, DOC(Bentley, Geom, MSBsplineCurve, GetRange));
     
     c1.def("GetRangeOfProjectionOnRay", &MSBsplineCurve::GetRangeOfProjectionOnRay, "ray"_a, "fraction0"_a = 0.0, "fraction1"_a = 1.0, DOC(Bentley, Geom, MSBsplineCurve, GetRangeOfProjectionOnRay));

     c1.def("RotateCurve", &MSBsplineCurve::RotateCurve, "rMatrix"_a, DOC(Bentley, Geom, MSBsplineCurve, RotateCurve));
     c1.def("TransformCurve", &MSBsplineCurve::TransformCurve, "transform"_a, DOC(Bentley, Geom, MSBsplineCurve, TransformCurve));
     c1.def("TransformCurve4d", &MSBsplineCurve::TransformCurve4d, "transform4d"_a, DOC(Bentley, Geom, MSBsplineCurve, TransformCurve4d));

     c1.def("ProjectToZFocalPlane", &MSBsplineCurve::ProjectToZFocalPlane, "focalLength"_a, DOC(Bentley, Geom, MSBsplineCurve, ProjectToZFocalPlane));
     c1.def("RemoveKnotsBounded", &MSBsplineCurve::RemoveKnotsBounded, "tol"_a, "startPreservation"_a, "endPreservation"_a, DOC(Bentley, Geom, MSBsplineCurve, RemoveKnotsBounded));
     c1.def_static("GetRemovalKnotBound", &MSBsplineCurve::GetRemovalKnotBound, "curve"_a, "r"_a, "s"_a, DOC(Bentley, Geom, MSBsplineCurve, GetRemovalKnotBound));

     c1.def("CleanKnots", &MSBsplineCurve::CleanKnots, DOC(Bentley, Geom, MSBsplineCurve, CleanKnots));

     c1.def("AppendCurves", &MSBsplineCurve::AppendCurves, "inCurve1"_a, "inCurve2"_a, "forceContinuity"_a, "reparam"_a, DOC(Bentley, Geom, MSBsplineCurve, AppendCurves));
     c1.def("WireCentroid", [] (MSBsplineCurveCR self, DPoint3dR centroid, double fraction0, double fraction1)
            {
            double length = 0;
            self.WireCentroid(length, centroid, fraction0, fraction1);
            return length;
            }, "centroid"_a, "fraction0"_a, "fraction1"_a);

     c1.def("InitEllipticArc", &MSBsplineCurve::InitEllipticArc,
            "center"_a, "rX"_a, "rY"_a, "startRadians"_a = 0.0, "sweepRadians"_a = msGeomConst_2pi, "axes"_a = nullptr);

     c1.def("InitFromDEllipse3d", &MSBsplineCurve::InitFromDEllipse3d, "ellipse"_a, DOC(Bentley, Geom, MSBsplineCurve, InitFromDEllipse3d));
     c1.def("InitFromPoints", [] (MSBsplineCurveR self, DPoint3dArray const& points)
            {
            self.InitFromPoints(&points[0], (int)points.size()); 
            }, "points"_a);

     c1.def("InitAkima", [] (MSBsplineCurveR self, DPoint3dArray const& points, bool compressPoints)
            {
            self.InitAkima(&points[0], points.size(), compressPoints);
            }, "points"_a, "compressPoints"_a);

     c1.def("InitFromBeziers", &MSBsplineCurve::InitFromBeziers, "beziers"_a, DOC(Bentley, Geom, MSBsplineCurve, InitFromBeziers));

     c1.def("InitFromDPoint4dArray", [] (MSBsplineCurveR self, DPoint4dArray const& points, int order)
            {
            self.InitFromDPoint4dArray(&points[0], (int) points.size(), order);
            }, "points"_a, "order"_a);

     c1.def("ApproximateAnyCurve", &MSBsplineCurve::ApproximateAnyCurve, "inCurve"_a, "tolerance"_a, "order"_a, "parameterization"_a, "bMaintainEndTangents"_a, DOC(Bentley, Geom, MSBsplineCurve, ApproximateAnyCurve));

     c1.def("InitFromLeastSquaresFit",
            &MSBsplineCurve::InitFromLeastSquaresFit,
            "points"_a, "numPoints"_a, "endControl"_a, "sTangent"_a, "eTangent"_a, "keepTanMag"_a, "iterDegree"_a, "reqDegree"_a, "singleKnot"_a, "tolerance"_a);

     c1.def("InitFromGeneralLeastSquares",
            &MSBsplineCurve::InitFromGeneralLeastSquares,
            "avgDistance"_a, "maxDistance"_a, "info"_a, "knts"_a, "pnts"_a, "uValues"_a, "numPnts"_a);

     c1.def("InitFromInterpolatePoints", [](MSBsplineCurve& self, DPoint3dArray const& points, int parametrization, bool endControl, DVec3dCP sTangent, DVec3dCP eTangent, bool keepTanMag, int order)
            {
             size_t numPoints = points.size();
             self.InitFromInterpolatePoints(points.data(), (int)numPoints, parametrization, endControl, sTangent, eTangent, keepTanMag, order);
            }, "points"_a, "parameterization"_a, "endControl"_a, "sTangent"_a, "eTangent"_a, "keepTanMag"_a, "order"_a);

     c1.def_static("SampleG1CurveByPoints",
            &MSBsplineCurve::SampleG1CurveByPoints,
            "P"_a, "up"_a, "uq"_a, "curve"_a, "par"_a, "Eg"_a, "ptol"_a);

     c1.def_static("GeneralLeastSquaresApproximation",
                   &MSBsplineCurve::GeneralLeastSquaresApproximation,
                   "outCurve"_a, "Q"_a, "u"_a, "knots"_a, "numPoles"_a, "order"_a);

     c1.def_static("WeightedLeastSquaresFit",
                   &MSBsplineCurve::WeightedLeastSquaresFit,
                   "outCurve"_a, "Q"_a, "u"_a, "endControl"_a, "sTangent"_a, "eTangent"_a, "numPoles"_a, "order"_a);
        
     c1.def_static("KnotRefinement", &MSBsplineCurve::KnotRefinement, "X"_a, "curve"_a);

     c1.def_static("ApproximateG1Curve", 
                   &MSBsplineCurve::ApproximateG1Curve,
                   "outCurve"_a, "inCurve"_a, "degree"_a, "keepTangent"_a, "parametrization"_a, "geomTol"_a, "paramTol"_a, "pointTol"_a);

     c1.def_static("ApproximateNurbsCurve",
                   &MSBsplineCurve::ApproximateNurbsCurve,
                   "outCurve"_a, "inCurve"_a, "degree"_a, "keepTangent"_a, "parametrization"_a, "tol"_a);

     c1.def_static("AreSameWeights", &MSBsplineCurve::AreSameWeights, "w0"_a, "w1"_a, DOC(Bentley, Geom, MSBsplineCurve, AreSameWeights));
     c1.def_static("AreSameKnots", &MSBsplineCurve::AreSameKnots, "knot0"_a, "knot1"_a, DOC(Bentley, Geom, MSBsplineCurve, AreSameKnots));

     c1.def("AlmostEqual", py::overload_cast<MSBsplineCurveCR>(&MSBsplineCurve::AlmostEqual, py::const_), "other"_a, DOC(Bentley, Geom, MSBsplineCurve, AlmostEqual));
     c1.def("AlmostEqual", py::overload_cast<MSBsplineCurveCR, double>(&MSBsplineCurve::AlmostEqual, py::const_), "other"_a, "tolerance"_a, DOC(Bentley, Geom, MSBsplineCurve, AlmostEqual));

     c1.def_static("AddRuleSurfaceRayIntersections",
                   &MSBsplineCurve::AddRuleSurfaceRayIntersections,
                   "pickData"_a, "curveA"_a, "curveB"_a, "ray"_a);

     c1.def_static("RuledSurfaceClosestPoint",
                   &MSBsplineCurve::RuledSurfaceClosestPoint,
                   "pickData"_a, "curveA"_a, "curveB"_a, "spacePoint"_a);

     c1.def("HasValidPoleAllocation", &MSBsplineCurve::HasValidPoleAllocation);
     c1.def("HasValidWeightAllocation", &MSBsplineCurve::HasValidWeightAllocation);
     c1.def("HasValidKnotAllocation", &MSBsplineCurve::HasValidKnotAllocation);
     c1.def("HasValidOrder", &MSBsplineCurve::HasValidOrder);
     c1.def("HasValidPoleCounts", &MSBsplineCurve::HasValidPoleCounts);
     c1.def("HasValidCountsAndAllocations", &MSBsplineCurve::HasValidCountsAndAllocations);

     c1.def("SegmentAkimaCurve",
            &MSBsplineCurve::SegmentAkimaCurve,
            "segment"_a, "akimaCurve"_a, "transform"_a, "param0"_a, "param1"_a, "tolerance"_a = -1.0);  

     c1.def_readwrite("type", &MSBsplineCurve::type);
     c1.def_readwrite("rational", &MSBsplineCurve::rational);
     c1.def_readwrite("display", &MSBsplineCurve::display);
     c1.def_readwrite("params", &MSBsplineCurve::params);

     c1.def_property_readonly("poles",
         [](MSBsplineCurve& self)
        {
         py::list poleArray;
         for (int32_t i = 0; i < self.params.numPoles; i++)
             poleArray.append(py::cast(self.poles[i], py::return_value_policy::reference));
         return poleArray;
        });

     c1.def_property_readonly("knots",
         [](MSBsplineCurve& self)
        {
         py::list knotArray;
         for (int32_t i = 0; i < self.params.numKnots; i++)
             knotArray.append(py::cast(self.knots[i], py::return_value_policy::reference));
         return knotArray;
        });

     c1.def_property_readonly("weights",
         [](MSBsplineCurve& self)
        {
         py::list wArray;

         if (self.rational)
            {
            for (int32_t i = 0; i < self.params.numPoles; i++)
                wArray.append(py::cast(self.weights[i], py::return_value_policy::reference));
            }

         return wArray;
        });

     c1.def("__repr__", [] (MSBsplineCurve& self)
            {
            return "(order:{}, numKnots:{}, numPoles:{})"_s.format(self.GetOrder(), self.GetNumKnots(), self.GetNumPoles());
            });

     c1.def("__copy__", [](const MSBsplineCurve& self)
        {
         return MSBsplineCurve(self);
        });
    }