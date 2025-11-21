/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\dspiral2dbase.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/BSIQuadrature.h>
#include <Geom/DTriangle3d.h>
#include <Geom/DSpiral2dBase.h>



static const char * __doc_Bentley_Geom_DCatenary3dPlacement_AppendPlaneIntersections =R"doc(compute intersections with a plane. Return x values)doc";

static const char * __doc_Bentley_Geom_DCatenary3dPlacement_EndDistance =R"doc(Return the local coordinate (parameter) of the catenary end.)doc";

static const char * __doc_Bentley_Geom_DCatenary3dPlacement_StartDistance =R"doc(Return the local coordinate (parameter) of the catenary start.)doc";

static const char * __doc_Bentley_Geom_DCatenary3dPlacement_Get =R"doc(Get explicit contents ...)doc";

static const char * __doc_Bentley_Geom_DCatenary3dPlacement_CloneBetweenFractions =R"doc(Return a clone over a fractional interval within the existing curve.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_CoshIntersectHomogeneousLine =R"doc(Solve for simultaneous roots of

* y = cosh(x)

* x*hLine.x + y*hLine.y + hLine.z = 0

* Note that the cosh(x) is raw x -- NOT divided by the " a " parameter
used in the catenary.

* At most 2 roots are possible.

* A false return is detection of failed iteration.

* A true return with 0,1,or 2 roots is normal.

* The false case is probably due to very large numbers. cosh(x) gets
large very quickly.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_CoshIntersectLine =R"doc(Solve for roots of alpha + beta*x + gamma * cosh(x) = 0

* Note that the cosh(x) is raw x -- NOT divided by the " a " parameter
used in the catenary.

* At most 2 roots are possible.

* A false return is detection of failed iteration.

* A true return with 0,1,or 2 roots is normal.

* The false case is probably due to very large numbers. cosh(x) gets
large very quickly.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_CurvatureAtLength =R"doc(return curvature at (signed) distance along.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_DerivativesAtLength =R"doc(Return the point and 2 derivatives at distance from min point)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_RadiansAtLength =R"doc(Return the tangent angle at distance)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_TangentAtLength =R"doc(Return the tangent vector (unit), derivative of XY wrt s.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_XYAtLength =R"doc(return x,y at arc length from the min point.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_LengthAtX =R"doc(Return curve length from origin to x. This is signed.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_RadiansAtX =R"doc(Return curve angle (from X axis) at x.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_d2YdX2AtX =R"doc(Return 2nd derivative at x.)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_dYdXAtX =R"doc(Return slope at x)doc";

static const char * __doc_Bentley_Geom_DCatenaryXY_YAtX =R"doc(Return curve y value at x)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_DisplacementBetweenFractions =R"doc(return the displacement between fractions. Having a close f0 is much
faster than FractionToPoint with no starter fraction.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_MappedSpiralLengthActiveInterval =R"doc(Length of the spiral after mapping by matrix*frame.matrix)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_SpiralLengthActiveInterval =R"doc(absolute length of the partial spiral (between start and end
fractions))doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_SpiralLength01 =R"doc(absolute length of the reference spiral (between 0 and 1))doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_ActiveFractionToDerivatives =R"doc(return xyz first, second, third derivatives as columns, scaled for
active interval.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_FractionToDerivatives =R"doc(return xyz first, second, third derivatives as columns.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_AlmostEqual01 =R"doc(Apply AlmostEqual to all components except fractions)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_AlmostEqual =R"doc(Apply AlmostEqual to all components)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_ReverseInPlace =R"doc(Reverse the fractions !!)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_ReplaceSpiral =R"doc(Free the current spiral pointer and replace by (possibly NULL) arg.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPlacement_Clone =R"doc(Return a clone.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dJapaneseCubic_EvaluateAtFractionInStandardOrientation =R"doc(Evaluate at distance a spiral in standard orientation -- zero
curvature at origin.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectHalfCosine_EvaluateAtFractionInStandardOrientation =R"doc(Evaluate at distance a spiral in standard orientation -- zero
curvature at origin.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dMXCubicAlongArc_EvaluateAtFractionInStandardOrientation =R"doc(Evaluate at fraction standard orientation -- zero curvature at origin.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPolish_ValidateSeriesInversion =R"doc(Execute unit test of the series inversion logic.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPolish_GetBezierPoles =R"doc(Return poles for preferred representation as a bezier curve These are
in the local coordinates of the standard orientation)doc";

static const char * __doc_Bentley_Geom_DSpiral2dPolish_EvaluateAtFractionOfAxisLengthInStandardOrientation =R"doc(Evaluate at distance a spiral in standard orientation -- zero
curvature at origin.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dCzechAlongTangent_GetBezierPoles =R"doc(Return poles for preferred representation as a bezier curve These are
in the local coordinates of the standard orientation)doc";

static const char * __doc_Bentley_Geom_DSpiral2dCzechAlongTangent_EvaluateAtFractionAlongTangentInStandardOrientation =R"doc(Evaluate at distance a spiral in standard orientation -- zero
curvature at origin.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dCzech_EvaluateAtFractionOfNominalLengthInStandardOrientation =R"doc(Evaluate at distance a spiral in standard orientation -- zero
curvature at origin.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectEvaluation_ApplyCCWRotation =R"doc(rotate xy and optional derivatives by radians. (To be called by
derived class EvaluateAtDistance when to rotate EvaluateAtDistance
results from standard position))doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectEvaluation_FractionToLocalAngle =R"doc(Return the tangent angle (in radians) in local coordinates)doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectEvaluation_FractionToVelocity =R"doc(Return the magnitude of the true derivative of position wrt fraction.
Implemented in DSpiral2dDirectEvaluation, not individual classes.
Assume EvaluateAtFraction.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectEvaluation_FractionToDCurvatureDFraction =R"doc(Return the true curvature derivative wrt fraction. Implemented in
DSpiral2dDirectEvaluation, not individual classes. Assume
EvaluateAtFraction.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectEvaluation_FractionToCurvature =R"doc(Return the true curvature at fractional position. Implemented in
DSpiral2dDirectEvaluation, not individual classes. Assume
EvaluateAtFraction.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dDirectEvaluation_EvaluateAtFraction =R"doc(Evaluate the spiral and derivatives at specified fractional position
return true if valid evaluation. DSpiral2dDirectEvaluation default
implementation returns false.)doc";

static const char * __doc_Bentley_Geom_DSPiral2dWeightedViennese_FillExtraDataArray =R"doc(Return the extra data array for the parameters of a weighted viennese
spiral)doc";

static const char * __doc_Bentley_Geom_DSPiral2dViennese_FillExtraDataArray =R"doc(Return the extra data array for the parameters of a viennese spiral)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_IsValidRLCombination =R"doc( test if a length-from-inflection and final radius
combination is " small enough " for reasonable use. Test depends on
spiral type:

* DSpiral2dBase::TransitionType_None indicates apply the strictest
test (same as Czech and Italian)

* DSpiral2dBase::TransitionType_Czech and
DSpiral2dBase::TransitionType_Italian indicate a strict test L<2*R

* other types have no restrictions.

:param (input):
    lengthFromInflection (input) distance along spiral starting at
    inflection and ending at finalRadius.

:param (input):
    finalRadius (input) final radius

:param (input):
    spiralType (input) spiral type.

:param (input):
    lengthFactor expansion or reduction factor to apply to the allowed
    length. +---------------+---------------+---------------+---------
    ------+------)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_SymmetricPointShoulderTargetTransition =R"doc( compute 2 spirals.

:param (input):
    startPoint start point

:param (input):
    shoulderPoint target point for first and last tangents

:param (input):
    targetPoint target point for last tangent

:param [in,out]:
    spiralA On input, a spiral of the desired type. On output all
    fields are set.

:param [in,out]:
    spiralB On input, a spiral of the desired type. On output all
    fields are set.

:param (output):
    junctionPoint transition between spirals. This is the max
    curvature point.

:param (output):
    endPoint end of second spiral.

:returns:
    false if unable to construct)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_SymmetricLineSpiralSpiralLineTransition =R"doc( compute spirals and arc to make a line-to-line
transition.

:param (input):
    lineAPoint point on line A.

:param (input):
    lineBPoint point on line B.

:param (input):
    lineLineIntersection intersection of lines.

:param (input):
    length length of spiral from line A to junction

:param [in,out]:
    spiralA On input, a spiral of the desired type. On output all
    fields are set.

:param [in,out]:
    spiralB On input, a spiral of the desired type. On output all
    fields are set.

:param (output):
    lineToSpiralA tangency point from line to spiral

:param (output):
    lineToSpiralB tangency point from line to spiral

:param (output):
    spiralToSpiral tangency point from spiral to to spiral

:param (output):
    junctionRadius radius at transition between the spirals.

:returns:
    false if unable to construct)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_LineSpiralArcSpiralLineTransition =R"doc( compute spirals and arc to make a line-to-line
transition.

:param (input):
    lineAPoint point on line A.

:param (input):
    lineBPoint point on line B.

:param (input):
    lineLineIntersection intersection of lines.

:param (input):
    radius radius for circular part of transition.

:param (input):
    lengthA length of spiral from line A to circle.

:param (input):
    lengthB length of spiral from line B to circle.

:param [in,out]:
    spiralA On input, a spiral of the desired type. On output all
    fields are set.

:param [in,out]:
    spiralB On input, a spiral of the desired type. On output all
    fields are set.

:param (output):
    lineToSpiralA tangency point from line to spiral

:param (output):
    spiralAToArc tangency point from spiral to arc

:param (output):
    lineToSpiralB tangency point from line to spiral

:param (output):
    spiralBToArc tangency point from spiral to arc

:param (output):
    arc arc between spirals.

:returns:
    false if unable to construct)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_EvaluateTwoTermClothoidSeriesAtDistanceInStandardOrientation =R"doc((input) distance for evaluation (input) nominal length. ASSUMED NONZERO (input)
exit curvature. ASSUMED NONZERO (output) coordinates on spiral (output)
first derivative wrt distance (output) second derivative wrt distance
(output) third derivative wrt distance)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_ClosestPoint =R"doc( Compute the closest spiral point for a given space point.

:param (input):
    spiral spiral to evaluate.

:param (input):
    startFraction start fraction of search range

:param (input):
    endFraction endFraction of search range

:param (input):
    spiralToWorld transform placing the spiral local coordinates into
    the world coordinate system

:param (input):
    spacePoint world coordinates of space point.

:param (output):
    spiralPoint world coordinates of closest point on spiral

:param (output):
    spiralFraction fractional coordinates of closest point on spiral

:param (output):
    minDistance distance from space point to spiralPoint.

:returns:
    false if unable to construct)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_GetIntervalCount =R"doc(Return an interval count for stroking or integration. Except for
degenerate single interval cases, the interval count is always even.
That is the possible values are

:param (input):
    spiral spiral being queried.

:param (input):
    startFraction start of interval to stroke.

:param (input):
    endFraction end of interval to stroke.

:param (input):
    maxRadians max turn between strokes.

:param (input):
    minInterval smallest number of intervals.

:param (input):
    maxStrokeLength largest stroke size. Recommended 10 meters)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_StrokeToAnnouncer =R"doc( Integrate the vector displacements of a clothoid over a
fractional interval. This uses the angles, curvatures, and length.

:param (input):
    spiral spiral to stroke

:param (input):
    startFraction start fraction for integral.

:param (input):
    endFraction end fraction for integral.

:param (input):
    maxRadians maximum bearing change between computed points. A
    default is used if 0.0 is passed.

:param (input):
    F object with a method F->Announce (f, uv) called to announce
    fraction and coordinate as computed.

:param (output):
    errorBound estimated bound on error.

:param (output):
    minInterval smallest number of intervals allowed

:param (output):
    maxStrokeLength maximum allowed stroke length

:returns:
    false if point integration failed)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_Stroke =R"doc( Integrate the vector displacements of a clothoid from its
start point to multiple points up to its end point. This uses the
angles, curvatures, and length.

:param (input):
    spiral spiral to stroke

:param (input):
    maxRadians maximum bearing change between computed points.
    Recommended value is 0.08.

:param [in,out]:
    pDXY buffer to receive points.

:param (output):
    numDXY number of points computed.

:param (input):
    maxDXY maximum number of points to compute. If zero or negative,
    only the final vector is stored (and pDXY is assumed to be valid
    for one vector).

:param (output):
    errorBound estimated bound on error.

:returns:
    false if point buffer exceeded.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_SetBearingCurvatureLengthBearing =R"doc( Set start bearing, start curvature, length, and end
curvature. (Compute end bearing)

:param (input):
    theta0 start bearing

:param (input):
    curvature0 start curvature

:param (input):
    length arc length

:param (input):
    theta1 end bearing)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_CreateBearingCurvatureLengthCurvature =R"doc(invoke appropriate concrete class constructor ...)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_CreateBearingCurvatureBearingCurvature =R"doc(invoke appropriate concrete class constructor ...)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_TransitionTypeToString =R"doc(return the string name of the type)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_StringToTransitionType =R"doc(return the integer code for the string name.)doc";

static const char * __doc_Bentley_Geom_DSpiral2dBase_GetExtraData =R"doc(Get the extra data for this spiral. REMARK:This should be a virtual,
but is implemented as special cases because of API change restriction)doc";

//=======================================================================================
// Trampoline class for DSpiral2dBase::ASLSACollector.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyASLSACollector : DSpiral2dBase::ASLSACollector
    {
    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    void Collect(DPoint3dCR centerA, DPoint3dCR arcToSpiralA, DSpiral2dBase& spiralA, DPoint3dCR spiralToLineA, 
                 DPoint3dCR centerB, DPoint3dCR arcToSpiralB, DSpiral2dBase& spiralB, DPoint3dCR spiralToLineB) override
        {
        PYBIND11_OVERRIDE_PURE_EX(void, DSpiral2dBase::ASLSACollector, Collect, 
                               centerA, arcToSpiralA, spiralA, spiralToLineA,
                               centerB, arcToSpiralB, spiralB, spiralToLineB);
        }
    };

//=======================================================================================
// Trampoline class for DSpiral2dBase.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDSpiral2dBase : DSpiral2dBase
    {
    using DSpiral2dBase::DSpiral2dBase;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    double DistanceToLocalAngle(double distance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(double, DSpiral2dBase, DistanceToLocalAngle, 0.0, distance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    double DistanceToCurvature(double distance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(double, DSpiral2dBase, DistanceToCurvature, 0.0, distance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    double DistanceToCurvatureDerivative(double distance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(double, DSpiral2dBase, DistanceToCurvatureDerivative, 0.0, distance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    int GetTransitionTypeCode() const override
        { PYBIND11_OVERRIDE_PURE_EXR(int, DSpiral2dBase, GetTransitionTypeCode, -1, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    DSpiral2dBaseP Clone() const override
        { PYBIND11_OVERRIDE_PURE_EXR(DSpiral2dBaseP, DSpiral2dBase, Clone, nullptr, ); }
    };

//=======================================================================================
// Trampoline class for DSpiral2dDirectEvaluation.
// @bsiclass                                                                   02/23
//=======================================================================================
struct PyDSpiral2dDirectEvaluation : DSpiral2dDirectEvaluation
    {
    using DSpiral2dDirectEvaluation::DSpiral2dDirectEvaluation;

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    double DistanceToLocalAngle(double distance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(double, DSpiral2dDirectEvaluation, DistanceToLocalAngle, 0.0, distance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    double DistanceToCurvature(double distance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(double, DSpiral2dDirectEvaluation, DistanceToCurvature, 0.0, distance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    double DistanceToCurvatureDerivative(double distance) const override
        { PYBIND11_OVERRIDE_PURE_EXR(double, DSpiral2dDirectEvaluation, DistanceToCurvatureDerivative, 0.0, distance); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    int GetTransitionTypeCode() const override
        { PYBIND11_OVERRIDE_PURE_EXR(int, DSpiral2dDirectEvaluation, GetTransitionTypeCode, -1, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    DSpiral2dBaseP Clone() const override
        { PYBIND11_OVERRIDE_PURE_EXR(DSpiral2dBaseP, DSpiral2dDirectEvaluation, Clone, nullptr, ); }

    /*---------------------------------------------------------------------------------**//**
    * @bsimethod                                                                       2/2023
    +---------------+---------------+---------------+---------------+---------------+------*/
    bool EvaluateAtFraction(double fraction, DPoint2dR xyz, DVec2dP d1XYZ, DVec2dP d2XYZ, DVec2dP d3XYZ) const override
        { PYBIND11_OVERRIDE_PURE_EXR(bool, DSpiral2dDirectEvaluation, EvaluateAtFraction, fraction, false, xyz, d1XYZ, d2XYZ, d3XYZ); }
    };

DEFINE_NODELETE_HOLDER_TYPE(AnnounceDoubleDPoint2d);

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DSpiral2dBase(py::module_& m)
    {
    //===================================================================================
    // struct AnnounceDoubleDPoint2d
    py::class_<AnnounceDoubleDPoint2d, AnnounceDoubleDPoint2dPtr > c1(m, "AnnounceDoubleDPoint2d");
    c1.def("Announce", &AnnounceDoubleDPoint2d::Announce, "fraction"_a, "xy"_a);

    //===================================================================================
    // struct DSpiral2dBase
    py::class_<DSpiral2dBase, PyDSpiral2dBase, BSIVectorIntegrand> c2(m, "DSpiral2dBase");
    
    c2.def(py::init<>());
    c2.def(py::init(py::overload_cast<int>(&DSpiral2dBase::Create)), "transitionType"_a);
    c2.def(py::init(py::overload_cast<int, DoubleArray const&>(&DSpiral2dBase::Create)), "transitionType"_a, "extraData"_a);
    c2.def(py::init([](int transitionType, py::list const& extraData){
        CONVERT_PYLIST_TO_NEW_CPPARRAY(extraData, cppExtraData, DoubleArray, double);
        return DSpiral2dBase::Create(transitionType, cppExtraData);
    }), "transitionType"_a, "extraData"_a);
    c2.def(py::init(&DSpiral2dBase::CreateWithNominalLength), "transitionType"_a, "parameter"_a);    

    c2.attr("TransitionType_Unknown") = DSpiral2dBase::TransitionType_Unknown;
    c2.attr("TransitionType_Clothoid") = DSpiral2dBase::TransitionType_Clothoid;
    c2.attr("TransitionType_Bloss") = DSpiral2dBase::TransitionType_Bloss;
    c2.attr("TransitionType_Biquadratic") = DSpiral2dBase::TransitionType_Biquadratic;
    c2.attr("TransitionType_Cosine") = DSpiral2dBase::TransitionType_Cosine;
    c2.attr("TransitionType_Sine") = DSpiral2dBase::TransitionType_Sine;
    c2.attr("TransitionType_Viennese") = DSpiral2dBase::TransitionType_Viennese;
    c2.attr("TransitionType_WeightedViennese") = DSpiral2dBase::TransitionType_WeightedViennese;
    c2.attr("TransitionType_FirstDirectEvaluate") = DSpiral2dBase::TransitionType_FirstDirectEvaluate;
    c2.attr("TransitionType_WesternAustralian") = DSpiral2dBase::TransitionType_WesternAustralian;
    c2.attr("TransitionType_Czech") = DSpiral2dBase::TransitionType_Czech;
    c2.attr("TransitionType_AustralianRailCorp") = DSpiral2dBase::TransitionType_AustralianRailCorp;
    c2.attr("TransitionType_Italian") = DSpiral2dBase::TransitionType_Italian;
    c2.attr("TransitionType_PolishCubic") = DSpiral2dBase::TransitionType_PolishCubic;
    c2.attr("TransitionType_Arema") = DSpiral2dBase::TransitionType_Arema;
    c2.attr("TransitionType_MXCubicAlongArc") = DSpiral2dBase::TransitionType_MXCubicAlongArc;
    c2.attr("TransitionType_MXCubicAlongTangent") = DSpiral2dBase::TransitionType_MXCubicAlongTangent;
    c2.attr("TransitionType_ChineseCubic") = DSpiral2dBase::TransitionType_ChineseCubic;
    c2.attr("TransitionType_DirectHalfCosine") = DSpiral2dBase::TransitionType_DirectHalfCosine;
    c2.attr("TransitionType_JapaneseCubic") = DSpiral2dBase::TransitionType_JapaneseCubic;
    c2.attr("TransitionType_CzechAlongTangent") = DSpiral2dBase::TransitionType_CzechAlongTangent;

    c2.def_property_readonly ("mLength", [](DSpiral2dBase const& self) { return self.mLength; });


    c2.def("GetExtraData", &DSpiral2dBase::GetExtraData, "extraData"_a, DOC(Bentley, Geom, DSpiral2dBase, GetExtraData));

    c2.def_static("StringToTransitionType", &DSpiral2dBase::StringToTransitionType, "name"_a, DOC(Bentley, Geom, DSpiral2dBase, StringToTransitionType));

    c2.def_static("TransitionTypeToString", [] (int type)
        {
        Utf8String strVal;
        py::str outVal;
        if (DSpiral2dBase::TransitionTypeToString(type, strVal))
            outVal = py::cast(strVal.c_str());

        return outVal;
        }, "type"_a, DOC(Bentley, Geom, DSpiral2dBase, TransitionTypeToString));

    c2.def_static("CreateBearingCurvatureBearingCurvature",
                  py::overload_cast<int, double, double, double, double>(&DSpiral2dBase::CreateBearingCurvatureBearingCurvature), 
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "endRadians"_a, "endCurvature"_a, DOC(Bentley, Geom, DSpiral2dBase, CreateBearingCurvatureBearingCurvature));

    c2.def_static("CreateBearingCurvatureBearingCurvature",
                  py::overload_cast<int, double, double, double, double, DoubleArray const&>(&DSpiral2dBase::CreateBearingCurvatureBearingCurvature),
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "endRadians"_a, "endCurvature"_a, "extraData"_a, DOC(Bentley, Geom, DSpiral2dBase, CreateBearingCurvatureBearingCurvature));

     c2.def_static("CreateBearingCurvatureBearingCurvature", [](int transitionType, double startRadians, double startCurvature, double endRadians, double endCurvature, py::list const& extraData) {
                   CONVERT_PYLIST_TO_NEW_CPPARRAY(extraData, cppExtraData, DoubleArray, double);
                   return DSpiral2dBase::CreateBearingCurvatureBearingCurvature(transitionType, startRadians, startCurvature, endRadians, endCurvature, cppExtraData);
                }, "transitionType"_a, "startRadians"_a, "startCurvature"_a, "endRadians"_a, "endCurvature"_a, "extraData"_a, DOC(Bentley, Geom, DSpiral2dBase, CreateBearingCurvatureBearingCurvature));
                
    c2.def_static("CreateBearingCurvatureLengthCurvature",
                  py::overload_cast<int, double, double, double, double>(&DSpiral2dBase::CreateBearingCurvatureLengthCurvature),
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "length"_a, "endCurvature"_a, DOC(Bentley, Geom, DSpiral2dBase, CreateBearingCurvatureLengthCurvature));

    c2.def_static("CreateBearingCurvatureLengthCurvature",
                  py::overload_cast<int, double, double, double, double, DoubleArray const&>(&DSpiral2dBase::CreateBearingCurvatureLengthCurvature),
                  "transitionType"_a, "startRadians"_a, "startCurvature"_a, "length"_a, "endCurvature"_a, "extraData"_a, DOC(Bentley, Geom, DSpiral2dBase, CreateBearingCurvatureLengthCurvature));

    c2.def_static("CreateBearingCurvatureLengthCurvature", [](int transitionType, double startRadians, double startCurvature, double length, double endCurvature, py::list const& extraData) {
                  CONVERT_PYLIST_TO_NEW_CPPARRAY(extraData, cppExtraData, DoubleArray, double);
                  return DSpiral2dBase::CreateBearingCurvatureLengthCurvature(transitionType, startRadians, startCurvature, length, endCurvature, cppExtraData);
                }, "transitionType"_a, "startRadians"_a, "startCurvature"_a, "length"_a, "endCurvature"_a, "extraData"_a, DOC(Bentley, Geom, DSpiral2dBase, CreateBearingCurvatureLengthCurvature));
                
    c2.def_static("DefaultStrokeAngle", &DSpiral2dBase::DefaultStrokeAngle);    
            
    c2.def("SetBearingAndCurvatureLimits", &DSpiral2dBase::SetBearingAndCurvatureLimits, "theta0"_a, "curvature0"_a, "theta1"_a, "curvature1"_a);
    c2.def("SetBearingCurvatureLengthCurvature", &DSpiral2dBase::SetBearingCurvatureLengthCurvature, "theta0"_a, "curvature0"_a, "length"_a, "curvature1"_a);
    c2.def("SetBearingCurvatureLengthBearing", &DSpiral2dBase::SetBearingCurvatureLengthBearing, "theta0"_a, "curvature0"_a, "length"_a, "theta1"_a, DOC(Bentley, Geom, DSpiral2dBase, SetBearingCurvatureLengthBearing));

    c2.def("CopyBaseParameters", &DSpiral2dBase::CopyBaseParameters, "pSource"_a);

    c2.def("DistanceToFraction", &DSpiral2dBase::DistanceToFraction, "distance"_a);            
    c2.def("FractionToDistance", &DSpiral2dBase::FractionToDistance, "fraction"_a);

    c2.def("GetVectorIntegrandCount", &DSpiral2dBase::GetVectorIntegrandCount);
    c2.def("EvaluateVectorIntegrand", &DSpiral2dBase::EvaluateVectorIntegrand, "distance"_a, "pF"_a);

    c2.def("DistanceToGlobalAngle", &DSpiral2dBase::DistanceToGlobalAngle, "distance"_a);
    c2.def("ScaleInPlace", &DSpiral2dBase::ScaleInPlace, "s"_a);
    c2.def("FractionToDerivatives", &DSpiral2dBase::FractionToDerivatives, "fraction"_a, "dXdf"_a, "ddXdfdf"_a, "dddXdfdfdf"_a);
    
    c2.def("DistanceToLocalAngle", &DSpiral2dBase::DistanceToLocalAngle, "distance"_a);
    c2.def("DistanceToCurvature", &DSpiral2dBase::DistanceToCurvature, "distance"_a);
    c2.def("Clone", &DSpiral2dBase::Clone, py::return_value_policy::take_ownership);
    c2.def("DistanceToCurvatureDerivative", &DSpiral2dBase::DistanceToCurvatureDerivative, "distance");
    c2.def("GetTransitionTypeCode", &DSpiral2dBase::GetTransitionTypeCode);

    c2.def_static("Stroke", [] (DSpiral2dBase &spiral, double maxRadians, DVec2d *pDXY, int maxDXY)
        {
        double errorBound = 0;
        int numDXY = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, maxRadians, pDXY, numDXY, maxDXY, errorBound);
        return py::make_tuple(bOk, numDXY, errorBound);
        }, "spiral"_a, "maxRadians"_a, "pDXY"_a, "maxDXY"_a, DOC(Bentley, Geom, DSpiral2dBase, Stroke));

    c2.def_static("Stroke", [] (DSpiral2dBase &spiral, double maxRadians, DPoint3dCR xyz0, DPoint3dP pXYZ, int maxDXY)
        {
        double errorBound = 0;
        int numXYZ = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, maxRadians, xyz0, pXYZ, numXYZ, maxDXY, errorBound);
        return py::make_tuple(bOk, numXYZ, errorBound);
        }, "spiral"_a, "maxRadians"_a, "xyz0"_a, "pXYZ"_a, "maxDXY"_a, DOC(Bentley, Geom, DSpiral2dBase, Stroke));

    c2.def_static("Stroke", [] (DSpiral2dBase &spiral, double startFraction, double endFraction, double maxRadians, DVec2dR delta)
        {
        double errorBound = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, delta, errorBound);
        return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "delta"_a, DOC(Bentley, Geom, DSpiral2dBase, Stroke));

    c2.def_static("Stroke", [] (DSpiral2dBase &spiral, double startFraction, double endFraction, double maxRadians, DVec2d *pDXY, int maxDXY)
        {
        double errorBound = 0;
        int numDXY = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, pDXY, numDXY, maxDXY, errorBound);
        return py::make_tuple(bOk, numDXY, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "pDXY"_a, "maxDXY"_a, DOC(Bentley, Geom, DSpiral2dBase, Stroke));

    c2.def_static("Stroke", [] (DSpiral2dBase &spiral, double startFraction, double endFraction, double maxRadians, DVec2d *pDXY, double *pFraction, int maxDXY)
        {
        double errorBound = 0;
        int numDXY = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, pDXY, pFraction, numDXY, maxDXY, errorBound);
        return py::make_tuple(bOk, numDXY, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "pDXY"_a, "pFraction"_a, "maxDXY"_a, DOC(Bentley, Geom, DSpiral2dBase, Stroke));

    c2.def_static("Stroke", [] (DSpiral2dBase &spiral, double startFraction, double endFraction, double maxRadians, DVec2dR delta, double maxStrokeLength)
        {
        double errorBound = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, delta, errorBound, maxStrokeLength);
        return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "delta"_a, "maxStrokeLength"_a, DOC(Bentley, Geom, DSpiral2dBase, Stroke));

    c2.def_static("Stroke", 
                  [] (DSpiral2dBase &spiral, 
                      double startFraction, 
                      double endFraction, 
                      double maxRadians, 
                      DVec2dArray& uvPoints, 
                      DoubleArray& fractions, 
                      double maxStrokeLength)
        {
        double errorBound = 0;
        bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, uvPoints, fractions, errorBound, maxStrokeLength);
        return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "uvPoints"_a, "fractions"_a, "maxStrokeLength"_a = DEFAULT_SPIRAL_MAX_STROKE_LENGTH);

    c2.def_static("Stroke", [](DSpiral2dBase& spiral, double startFraction, double endFraction, double maxRadians, py::list& uvPoints, py::list& fractions, double maxStrokeLength = DEFAULT_SPIRAL_MAX_STROKE_LENGTH) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(uvPoints, cppUvPoints, DVec2dArray, DVec2d);
            CONVERT_PYLIST_TO_NEW_CPPARRAY(fractions, cppFractions, DoubleArray, double);
        
            double errorBound = 0;
            bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, cppUvPoints, cppFractions, errorBound, maxStrokeLength);
                
            return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "uvPoints"_a, "fractions"_a, "maxStrokeLength"_a = DEFAULT_SPIRAL_MAX_STROKE_LENGTH);
        
    c2.def_static("Stroke", [](DSpiral2dBase& spiral, double startFraction, double endFraction, double maxRadians, py::list& uvPoints, DoubleArray& fractions, double maxStrokeLength = DEFAULT_SPIRAL_MAX_STROKE_LENGTH) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(uvPoints, cppUvPoints, DVec2dArray, DVec2d);       
            double errorBound = 0;
            bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, cppUvPoints, fractions, errorBound, maxStrokeLength);       
            return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "uvPoints"_a, "fractions"_a, "maxStrokeLength"_a = DEFAULT_SPIRAL_MAX_STROKE_LENGTH);

    c2.def_static("Stroke", [](DSpiral2dBase& spiral, double startFraction, double endFraction, double maxRadians, DVec2dArray& uvPoints, py::list& fractions, double maxStrokeLength = DEFAULT_SPIRAL_MAX_STROKE_LENGTH) {
            CONVERT_PYLIST_TO_NEW_CPPARRAY(fractions, cppFractions, DoubleArray, double);
            double errorBound = 0;
            bool bOk = DSpiral2dBase::Stroke(spiral, startFraction, endFraction, maxRadians, uvPoints, cppFractions, errorBound, maxStrokeLength);     
            return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "uvPoints"_a, "fractions"_a, "maxStrokeLength"_a = DEFAULT_SPIRAL_MAX_STROKE_LENGTH);   
        
    c2.def_static("StrokeToAnnouncer", [] (DSpiral2dBase &spiral, double startFraction, double endFraction, double maxRadians, AnnounceDoubleDPoint2dR F, int minInterval, double maxStrokeLength)
        {
        double errorBound = 0;
        bool bOk = DSpiral2dBase::StrokeToAnnouncer(spiral, startFraction, endFraction, maxRadians, F, errorBound, minInterval, maxStrokeLength);
        return py::make_tuple(bOk, errorBound);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "F"_a, "minIndex"_a = 0, "maxStrokeLength"_a = DEFAULT_SPIRAL_MAX_STROKE_LENGTH, DOC(Bentley, Geom, DSpiral2dBase, StrokeToAnnouncer));

    c2.def_static("GetIntervalCount",
                  &DSpiral2dBase::GetIntervalCount,
                  "spiral"_a, "startFraction"_a, "endFraction"_a, "maxRadians"_a, "minInterval"_a = 0, "maxStrokeLength"_a = DEFAULT_SPIRAL_MAX_STROKE_LENGTH, DOC(Bentley, Geom, DSpiral2dBase, GetIntervalCount));
            
    c2.def_static("ClosestPoint", [] (DSpiral2dBase &spiral, double startFraction, double endFraction, TransformCR spiralToWorld, DPoint3dCR spacePoint)
        {
        double fraction = 0;
        double minDistance = 0;
        DPoint3d spiralPoint = DPoint3d::FromZero();
        bool bOk = DSpiral2dBase::ClosestPoint(spiral, startFraction, endFraction, spiralToWorld, spacePoint, spiralPoint, fraction, minDistance);
        return py::make_tuple(bOk, fraction, minDistance);
        }, "spiral"_a, "startFraction"_a, "endFraction"_a, "spiralToWorld"_a, "spacePoint"_a, DOC(Bentley, Geom, DSpiral2dBase, ClosestPoint));

    c2.def_static("EvaluateTwoTermClothoidSeriesAtDistanceInStandardOrientation",
                  &DSpiral2dBase::EvaluateTwoTermClothoidSeriesAtDistanceInStandardOrientation,
                  "s"_a, "length"_a, "curvature1"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dBase, EvaluateTwoTermClothoidSeriesAtDistanceInStandardOrientation));

    c2.def_static("LineSpiralArcSpiralLineTransition",
                  &DSpiral2dBase::LineSpiralArcSpiralLineTransition,
                  "lineAPoint"_a, "lineBPoint"_a, "lineLineIntersection"_a, "radius"_a, "lengthA"_a, "lengthB"_a, "spiralA"_a, "spiralB"_a, "lineToSpiralA"_a, "lineToSpiralB"_a, "spiralAToArc"_a, "spiralBToArc"_a, "arc"_a, DOC(Bentley, Geom, DSpiral2dBase, LineSpiralArcSpiralLineTransition));
            
    c2.def_static("SymmetricLineSpiralSpiralLineTransition", [] (DPoint3dCR lineAPoint, DPoint3dCR lineBPoint, DPoint3dCR lineLineIntersection, double length, DSpiral2dBase& spiralA, DSpiral2dBase& spiralB, DPoint3dR lineToSpiralA, DPoint3dR lineToSpiralB, DPoint3dR spiralToSpiral)
                  {
                  double junctionRadius = 0;
                  bool bOk = DSpiral2dBase::SymmetricLineSpiralSpiralLineTransition(lineAPoint, lineBPoint, lineLineIntersection, length, spiralA, spiralB, lineToSpiralA, lineToSpiralB, spiralToSpiral, junctionRadius);
                  return py::make_tuple(bOk, junctionRadius);
                  }, "lineAPoint"_a, "lineBPoint"_a, "lineLineIntersection"_a, "length"_a, "spiralA"_a, "spiralB"_a, "lineToSpiralA"_a, "lineToSpiralB"_a, "spiralToSpiral"_a, DOC(Bentley, Geom, DSpiral2dBase, SymmetricLineSpiralSpiralLineTransition));

    c2.def_static("SymmetricPointShoulderTargetTransition", &DSpiral2dBase::SymmetricPointShoulderTargetTransition,
                  "startPoint"_a, "shoulderPoint"_a, "targetPoint"_a, "spiralA"_a, "spiralB"_a, "junctionPoint"_a, "endPoint"_a, DOC(Bentley, Geom, DSpiral2dBase, SymmetricPointShoulderTargetTransition));    

    if (true)
        {
        //===================================================================================
        // struct ASLSACollector
        py::class_<DSpiral2dBase::ASLSACollector, std::unique_ptr<DSpiral2dBase::ASLSACollector, py::nodelete>, PyASLSACollector> c2_1(c2, "ASLSACollector");

        c2_1.def(py::init<>());
        c2_1.def("Collect", &DSpiral2dBase::ASLSACollector::Collect, "centerA"_a, "arcToSpiralA"_a, "sprialA"_a, "sprialToLineA"_a, "centerB"_a, "arcToSpiralB"_a, "spiralB"_a, "spiralToLibeB"_a);
        }

    c2.def_static("ArcSpiralLineSpiralArcTransition",
                  &DSpiral2dBase::ArcSpiralLineSpiralArcTransition,
                  "centerA"_a, "radiusA"_a, "lengthA"_a, "centerB"_a, "radiusB"_a, "lengthB"_a, "spiralA"_a, "spiralB"_a, "collector"_a);

    c2.def_static("IsValidRLCombination", &DSpiral2dBase::IsValidRLCombination, "lengthFromInflection"_a, "radius"_a, "spiralType"_a = DSpiral2dBase::TransitionType_Unknown, DOC(Bentley, Geom, DSpiral2dBase, IsValidRLCombination));

    c2.def("__repr__", [] (DSpiral2dBase& self)
           {
           Utf8String codeStr;
           DSpiral2dBase::TransitionTypeToString(self.GetTransitionTypeCode(), codeStr);

           return "(type:{}, theta0:{}, curvature0:{}, theta1:{}, curvature1:{}, length:{})"_s
               .format(codeStr, self.mTheta0, self.mCurvature0, self.mTheta0, self.mCurvature1, self.mLength);
           });

    //===================================================================================
    // struct DSpiral2dClothoid
    py::class_<DSpiral2dClothoid, DSpiral2dBase> c3(m, "DSpiral2dClothoid");
    c3.def(py::init<>());

    //===================================================================================
    // struct DSpiral2dBloss
    py::class_<DSpiral2dBloss, DSpiral2dBase> c4(m, "DSpiral2dBloss");
    c4.def(py::init<>());

    //===================================================================================
    // struct DSpiral2dBiQuadratic
    py::class_<DSpiral2dBiQuadratic, DSpiral2dBase> c5(m, "DSpiral2dBiQuadratic");
    c5.def(py::init<>());

    //===================================================================================
    // struct DSpiral2dCosine
    py::class_<DSpiral2dCosine, DSpiral2dBase> c6(m, "DSpiral2dCosine");
    c6.def(py::init<>());

    //===================================================================================
    // struct DSpiral2dSine
    py::class_<DSpiral2dSine, DSpiral2dBase> c7(m, "DSpiral2dSine");
    c7.def(py::init<>());

    //===================================================================================
    // struct DSPiral2dViennese
    py::class_<DSPiral2dViennese, DSpiral2dBase> c8(m, "DSPiral2dViennese");

    c8.def(py::init<double, double, double>(), "cant"_a, "h"_a, "e"_a);
    c8.def_static("FillExtraDataArray", &DSPiral2dViennese::FillExtraDataArray, "extraData"_a, "cant"_a, "h"_a, "e"_a, DOC(Bentley, Geom, DSPiral2dViennese, FillExtraDataArray));

    //===================================================================================
    // struct DSPiral2dWeightedViennese
    py::class_<DSPiral2dWeightedViennese, DSpiral2dBase> c9(m, "DSPiral2dWeightedViennese");

    c9.def(py::init<double, double, double, double, double>(), "cant"_a, "h"_a, "e"_a, "weight0"_a, "weight1"_a);
    c9.def_static("FillExtraDataArray", &DSPiral2dWeightedViennese::FillExtraDataArray, "extraData"_a, "cant"_a, "h"_a, "e"_a, "weight0"_a, "weight1"_a, DOC(Bentley, Geom, DSPiral2dWeightedViennese, FillExtraDataArray));

    //===================================================================================
    // struct DSpiral2dDirectEvaluation
    py::class_<DSpiral2dDirectEvaluation, PyDSpiral2dDirectEvaluation, DSpiral2dBase> c10(m, "DSpiral2dDirectEvaluation");

    c10.def(py::init<double>(), "nominalLength"_a);
    c10.def("EvaluateAtFraction", &DSpiral2dDirectEvaluation::EvaluateAtFraction, "fraction"_a, "xyz"_a, "d1XYZ"_a, "d2XYZ"_a, "d3XYZ"_a, DOC(Bentley, Geom, DSpiral2dDirectEvaluation, EvaluateAtFraction));
    c10.def("FractionToCurvature", &DSpiral2dDirectEvaluation::FractionToCurvature, "fraction"_a, DOC(Bentley, Geom, DSpiral2dDirectEvaluation, FractionToCurvature));

    c10.def("FractionToDCurvatureDFraction", [] (DSpiral2dDirectEvaluation const& self, double fraction)
            {
            double curvature = 0;
            double dCurvatureDFraction = 0;
            bool bOk = self.FractionToDCurvatureDFraction(fraction, curvature, dCurvatureDFraction);
            return py::make_tuple(bOk, curvature, dCurvatureDFraction);
            }, "fraction"_a, DOC(Bentley, Geom, DSpiral2dDirectEvaluation, FractionToDCurvatureDFraction));

    c10.def("FractionToVelocity", &DSpiral2dDirectEvaluation::FractionToVelocity, "fraction"_a, DOC(Bentley, Geom, DSpiral2dDirectEvaluation, FractionToVelocity));
    c10.def("FractionToLocalAngle", &DSpiral2dDirectEvaluation::FractionToLocalAngle, "fraction"_a, DOC(Bentley, Geom, DSpiral2dDirectEvaluation, FractionToLocalAngle));
    c10.def_static("ApplyCCWRotation", &DSpiral2dDirectEvaluation::ApplyCCWRotation, "radians"_a, "xyz"_a, "d1XYZ"_a, "d2XYZ"_a, "d3XYZ"_a, DOC(Bentley, Geom, DSpiral2dDirectEvaluation, ApplyCCWRotation));

    //===================================================================================
    // struct DSpiral2dWesternAustralian
    py::class_<DSpiral2dWesternAustralian, DSpiral2dDirectEvaluation> c11(m, "DSpiral2dWesternAustralian");

    c11.def(py::init<double>());    

    //===================================================================================
    // struct DSpiral2dCzech
    py::class_< DSpiral2dCzech, DSpiral2dDirectEvaluation> c12(m, "DSpiral2dCzech");

    c12.def(py::init<double>(), "nominalLength"_a);
    c12.def_static("EvaluateAtFractionOfNominalLengthInStandardOrientation",
                   &DSpiral2dCzech::EvaluateAtFractionOfNominalLengthInStandardOrientation,
                   "fraction"_a, "Lx"_a, "Ls"_a, "radius1"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dCzech, EvaluateAtFractionOfNominalLengthInStandardOrientation));

    //===================================================================================
    // struct DSpiral2dCzechAlongTangent
    py::class_<DSpiral2dCzechAlongTangent, DSpiral2dDirectEvaluation> c13(m, "DSpiral2dCzechAlongTangent");

    c13.def(py::init<double>(), "nominalLength"_a);
    c13.def_static("EvaluateAtFractionAlongTangentInStandardOrientation",
                   &DSpiral2dCzechAlongTangent::EvaluateAtFractionAlongTangentInStandardOrientation,
                   "fraction"_a, "axisLength"_a, "radius1"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dCzechAlongTangent, EvaluateAtFractionAlongTangentInStandardOrientation));
    c13.def("GetBezierPoles", &DSpiral2dCzechAlongTangent::GetBezierPoles, "poles"_a, "startFraction"_a, "endFraction"_a, DOC(Bentley, Geom, DSpiral2dCzechAlongTangent, GetBezierPoles));

    //===================================================================================
    // struct DSpiral2dPolish
    py::class_<DSpiral2dPolish, DSpiral2dDirectEvaluation> c14(m, "DSpiral2dPolish");

    c14.def(py::init<double>(), "nominalLength"_a);

    c14.def_static("EvaluateAtFractionOfAxisLengthInStandardOrientation",
                   [] (double fraction, double Ls, double radius1, bool mapDerivativesWRTSeriesDistance, DPoint2dR xy, DVec2dP d1XY, DVec2dP d2XY, DVec2dP d3XY)
                   {
                   double Lx = 0;
                   bool bOk = DSpiral2dPolish::EvaluateAtFractionOfAxisLengthInStandardOrientation(fraction, Lx, Ls, radius1, mapDerivativesWRTSeriesDistance, xy, d1XY, d2XY, d3XY);
                   return std::make_pair(bOk, Lx);
                   }, "fraction"_a, "Ls"_a, "radius1"_a, "mapDerivativesWRTSeriesDistance"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dPolish, EvaluateAtFractionOfAxisLengthInStandardOrientation));

    c14.def("GetBezierPoles", &DSpiral2dPolish::GetBezierPoles, "poles"_a, "startFraction"_a, "endFraction"_a, DOC(Bentley, Geom, DSpiral2dPolish, GetBezierPoles));
    c14.def("ValidateSeriesInversion", &DSpiral2dPolish::ValidateSeriesInversion, DOC(Bentley, Geom, DSpiral2dPolish, ValidateSeriesInversion));

    //===================================================================================
    // struct DSpiral2dItalian
    py::class_<DSpiral2dItalian, DSpiral2dDirectEvaluation> c15(m, "DSpiral2dItalian");

    c15.def(py::init<double>(), "pseudoLength"_a);

    //===================================================================================
    // struct DSpiral2dAustralianRailCorp
    py::class_< DSpiral2dAustralianRailCorp, DSpiral2dDirectEvaluation> c16(m, "DSpiral2dAustralianRailCorp");

    c16.def(py::init<double>(), "nominalLength"_a);
    
    //===================================================================================
    // struct DSpiral2dMXCubicAlongArc
    py::class_< DSpiral2dMXCubicAlongArc, DSpiral2dDirectEvaluation> c17(m, "DSpiral2dMXCubicAlongArc");

    c17.def(py::init<double>(), "nominalLength"_a);
    c17.def_static("EvaluateAtFractionInStandardOrientation",
                   &DSpiral2dMXCubicAlongArc::EvaluateAtFractionInStandardOrientation,
                   "fraction"_a, "length"_a, "curvature1"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dMXCubicAlongArc, EvaluateAtFractionInStandardOrientation));

    //===================================================================================
    // struct DSpiral2dDirectHalfCosine
    py::class_< DSpiral2dDirectHalfCosine, DSpiral2dDirectEvaluation> c18(m, "DSpiral2dDirectHalfCosine");

    c18.def(py::init<double>(), "axisLength"_a);
    c18.def_static("EvaluateAtFractionInStandardOrientation",
                   &DSpiral2dDirectHalfCosine::EvaluateAtFractionInStandardOrientation,
                   "s"_a, "axisLength"_a, "radius1"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dDirectHalfCosine, EvaluateAtFractionInStandardOrientation));

    //===================================================================================
    // struct DSpiral2dJapaneseCubic
    py::class_< DSpiral2dJapaneseCubic, DSpiral2dDirectEvaluation> c19(m, "DSpiral2dJapaneseCubic");

    c19.def(py::init<double>(), "axisLength"_a);
    c19.def_static("EvaluateAtFractionInStandardOrientation",
                   &DSpiral2dJapaneseCubic::EvaluateAtFractionInStandardOrientation,
                   "s"_a, "axisLength"_a, "radius1"_a, "xy"_a, "d1XY"_a, "d2XY"_a, "d3XY"_a, DOC(Bentley, Geom, DSpiral2dJapaneseCubic, EvaluateAtFractionInStandardOrientation));

    //===================================================================================
    // struct DSpiral2dChinese
    py::class_< DSpiral2dChinese, DSpiral2dDirectEvaluation> c20(m, "DSpiral2dChinese");

    c20.def(py::init<double>(), "nominalLength"_a);
    
    //===================================================================================
    // struct DSpiral2dArema
    py::class_< DSpiral2dArema, DSpiral2dDirectEvaluation> c21(m, "DSpiral2dArema");

    c21.def(py::init<double>(), "nominalLength"_a);

    //===================================================================================
    // struct DSpiral2dPlacement
    py::class_< DSpiral2dPlacement> c22(m, "DSpiral2dPlacement");

    c22.def_readwrite("spiral", &DSpiral2dPlacement::spiral);
    c22.def_readwrite("frame", &DSpiral2dPlacement::frame);
    c22.def_readwrite("fractionA", &DSpiral2dPlacement::fractionA);
    c22.def_readwrite("fractionB", &DSpiral2dPlacement::fractionB);

    c22.def(py::init<>());
    c22.def(py::init<DSpiral2dBaseCR, TransformCR, double, double>(), "source"_a, "frame"_a, "fractionA"_a, "fractionB"_a);

    c22.def("Clone", &DSpiral2dPlacement::Clone, "source"_a, DOC(Bentley, Geom, DSpiral2dPlacement, Clone));        
    c22.def("ReplaceSpiral", &DSpiral2dPlacement::ReplaceSpiral, py::keep_alive<1, 2>(), "callerSpiral"_a, DOC(Bentley, Geom, DSpiral2dPlacement, ReplaceSpiral));        
    c22.def("ReverseInPlace", &DSpiral2dPlacement::ReverseInPlace, DOC(Bentley, Geom, DSpiral2dPlacement, ReverseInPlace));        
    c22.def("AlmostEqual", &DSpiral2dPlacement::AlmostEqual, "other"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, DSpiral2dPlacement, AlmostEqual));
    c22.def("AlmostEqual01", &DSpiral2dPlacement::AlmostEqual01, "other"_a, "tolerance"_a = 0.0, DOC(Bentley, Geom, DSpiral2dPlacement, AlmostEqual01));
        
    c22.def("FractionInterval", &DSpiral2dPlacement::FractionInterval);
    c22.def("FractionToPoint", &DSpiral2dPlacement::FractionToPoint, "fraction"_a);
    c22.def("FractionToPointAndDerivative", &DSpiral2dPlacement::FractionToPointAndDerivative, "fraction"_a);
    c22.def("FractionToPointAndUnitTangent", &DSpiral2dPlacement::FractionToPointAndUnitTangent, "fraction"_a);

    c22.def("ActiveFractionToPoint", &DSpiral2dPlacement::ActiveFractionToPoint, "fraction"_a);
    c22.def("ActiveFractionToGlobalFraction", &DSpiral2dPlacement::ActiveFractionToGlobalFraction, "activeFraction"_a);
    c22.def("GlobalFractionToActiveFraction", &DSpiral2dPlacement::GlobalFractionToActiveFraction, "globalFraction"_a);

    c22.def("FractionToDerivatives", &DSpiral2dPlacement::FractionToDerivatives, "fraction"_a, DOC(Bentley, Geom, DSpiral2dPlacement, FractionToDerivatives));
    c22.def("ActiveFractionToDerivatives", &DSpiral2dPlacement::ActiveFractionToDerivatives, "fraction"_a, DOC(Bentley, Geom, DSpiral2dPlacement, ActiveFractionToDerivatives));

    c22.def("FractionToFrenetFrame", &DSpiral2dPlacement::FractionToFrenetFrame, "fraction"_a);
    c22.def("ActiveFractionToFrenetFrame", &DSpiral2dPlacement::ActiveFractionToFrenetFrame, "fraction"_a);
    c22.def("SpiralLength01", &DSpiral2dPlacement::SpiralLength01, DOC(Bentley, Geom, DSpiral2dPlacement, SpiralLength01));
    c22.def("SpiralLengthActiveInterval", &DSpiral2dPlacement::SpiralLengthActiveInterval, DOC(Bentley, Geom, DSpiral2dPlacement, SpiralLengthActiveInterval));
    c22.def("MappedSpiralLengthActiveInterval", &DSpiral2dPlacement::MappedSpiralLengthActiveInterval, "matrix"_a, DOC(Bentley, Geom, DSpiral2dPlacement, MappedSpiralLengthActiveInterval));

    c22.def("DisplacementBetweenFractions", &DSpiral2dPlacement::DisplacementBetweenFractions, "f0"_a, "f1"_a, DOC(Bentley, Geom, DSpiral2dPlacement, DisplacementBetweenFractions));
    c22.def("DisplacementBetweenActiveFractions", &DSpiral2dPlacement::DisplacementBetweenActiveFractions, "g0"_a, "g1"_a);

    c22.def("__repr__", [] (DSpiral2dPlacement& self)
            {
            return "(spiral:{}, frame:{}, fractionA:{}, fractionB:{})"_s.format(self.spiral, self.frame, self.fractionA, self.fractionB);
            });

    //===================================================================================
    // struct DCatenaryXY
    py::class_<DCatenaryXY> c23(m, "DCatenaryXY");

    c23.def(py::init<>());
    c23.def(py::init<double>(), "a"_a);

    c23.def("YAtX", &DCatenaryXY::YAtX, "x"_a, DOC(Bentley, Geom, DCatenaryXY, YAtX));
    c23.def("dYdXAtX", &DCatenaryXY::dYdXAtX, "x"_a, DOC(Bentley, Geom, DCatenaryXY, dYdXAtX));        
    c23.def("d2YdX2AtX", &DCatenaryXY::d2YdX2AtX, "x"_a, DOC(Bentley, Geom, DCatenaryXY, d2YdX2AtX));
    c23.def("RadiansAtX", &DCatenaryXY::RadiansAtX, "x"_a, DOC(Bentley, Geom, DCatenaryXY, RadiansAtX));        
    c23.def("LengthAtX", &DCatenaryXY::LengthAtX, "x"_a, DOC(Bentley, Geom, DCatenaryXY, LengthAtX));        
    c23.def("XYAtLength", &DCatenaryXY::XYAtLength, "s"_a, DOC(Bentley, Geom, DCatenaryXY, XYAtLength));

    c23.def("TangentAtLength", &DCatenaryXY::TangentAtLength, "s"_a, DOC(Bentley, Geom, DCatenaryXY, TangentAtLength));        
    c23.def("RadiansAtLength", &DCatenaryXY::RadiansAtLength, "s"_a, DOC(Bentley, Geom, DCatenaryXY, RadiansAtLength));        
    c23.def("DerivativesAtLength", &DCatenaryXY::DerivativesAtLength, "s"_a, "uv"_a, "duv"_a, "dduv"_a, "ddduv"_a, DOC(Bentley, Geom, DCatenaryXY, DerivativesAtLength));        
    c23.def("CurvatureAtLength", &DCatenaryXY::CurvatureAtLength, "s"_a, DOC(Bentley, Geom, DCatenaryXY, CurvatureAtLength));
    
    c23.def("AlmostEqual", &DCatenaryXY::AlmostEqual, "other"_a, "tolerance"_a);
    c23.def_static("CoshIntersectLine", &DCatenaryXY::CoshIntersectLine, "alpha"_a, "beta"_a, "gamma"_a, "roots"_a, DOC(Bentley, Geom, DCatenaryXY, CoshIntersectLine));
    c23.def_static("CoshIntersectHomogeneousLine", &DCatenaryXY::CoshIntersectHomogeneousLine, "hLine"_a, "roots"_a, DOC(Bentley, Geom, DCatenaryXY, CoshIntersectHomogeneousLine));

    //===================================================================================
    // struct DCatenary3dPlacement
    py::class_<DCatenary3dPlacement> c24(m, "DCatenary3dPlacement");

    c24.def(py::init<>());
    c24.def(py::init<double, DPlane3dByVectorsCR, double, double>(), "a"_a, "basis"_a, "distance0"_a, "distance1"_a);
    c24.def(py::init<DCatenaryXY const&, DPlane3dByVectorsCR, double, double>(), "xyCurve"_a, "basis"_a, "x0"_a, "x1"_a);
    c24.def(py::init<DCatenary3dPlacement const&>(), "other"_a);
    
    c24.def("CloneBetweenFractions", &DCatenary3dPlacement::CloneBetweenFractions, "fraction0"_a, "fraction1"_a, DOC(Bentley, Geom, DCatenary3dPlacement, CloneBetweenFractions));

    c24.def("Get", [] (DCatenary3dPlacement const& self, DPlane3dByVectorsR basis, DSegment1dR segment)
            {
            double a = 0;
            self.Get(a, basis, segment);
            return a;
            }, "basis"_a, "segment"_a, DOC(Bentley, Geom, DCatenary3dPlacement, Get));

    c24.def("StartDistance", &DCatenary3dPlacement::StartDistance, DOC(Bentley, Geom, DCatenary3dPlacement, StartDistance));
    c24.def("EndDistance", &DCatenary3dPlacement::EndDistance, DOC(Bentley, Geom, DCatenary3dPlacement, EndDistance));

    c24.def("AlmostEqual", &DCatenary3dPlacement::AlmostEqual, "other"_a, "tolerance"_a);

    c24.def("ReverseInPlace", &DCatenary3dPlacement::ReverseInPlace);
    c24.def("MultiplyInPlace", &DCatenary3dPlacement::MultiplyInPlace, "transform");
    c24.def("FractionToPoint", &DCatenary3dPlacement::FractionToPoint, "f"_a);
    c24.def("FractionToPointAndTangent", &DCatenary3dPlacement::FractionToPointAndTangent, "f"_a);
    c24.def("FractionToPointAndDerivatives", &DCatenary3dPlacement::FractionToPointAndDerivatives, "f"_a);

    c24.def("Stroke", &DCatenary3dPlacement::Stroke, "xyz"_a, "fraction"_a, "fraction0"_a, "fraction1"_a, "chordTolerance"_a, "angleTolerance"_a, "maxEdgeLength"_a);            
    c24.def("AppendPlaneIntersections", &DCatenary3dPlacement::AppendPlaneIntersections, "plane"_a, "xValues"_a, "bounded"_a, DOC(Bentley, Geom, DCatenary3dPlacement, AppendPlaneIntersections));
    }