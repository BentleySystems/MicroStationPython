/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyBentleyGeom\source\angle.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <Geom/Angle.h>



static const char * __doc_Bentley_Geom_YawPitchRollAngles_MaxDiffDegrees =R"doc(return the maximum absolute difference among radians among the angles.)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_MaxAbsDegrees =R"doc(return the maximum absolute radians among the angles.)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_MaxDiffRadians =R"doc(return the maximum absolute difference among radians among the angles.)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_MaxAbsRadians =R"doc(return the maximum absolute radians among the angles.)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_IsIdentity =R"doc(test for near-zero angles.)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_ToTransform =R"doc(Convert the angles and an origin to a Transform.)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_ToRotMatrix =R"doc(Convert the angles to a RotMatrix)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_TryFromRotMatrix =R"doc(Try to extract angles from a RotMatrix)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_FromDegrees =R"doc(constructor from all angles in degrees)doc";

static const char * __doc_Bentley_Geom_YawPitchRollAngles_FromRadians =R"doc(constructor from all angles in radians)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_FromAtan2 =R"doc(Construct from xy vector components (with y first as usual for atan2))doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_Sin =R"doc(Return the sine of the angle)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_Cos =R"doc(Return the cosine of the angle)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_Radians =R"doc(Return the angle in radians as a simple double.)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_Degrees =R"doc(Return the angle in degrees as simple double)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_FromDegrees =R"doc(Construct angle in degrees from input in degrees.)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_FromRadians =R"doc(Construct angle in degrees from input in radians)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_AlmostEqual =R"doc(approximate equality test)doc";

static const char * __doc_Bentley_Geom_AngleInDegrees_SmallAngleInDegrees =R"doc(The degrees form of the system small angle (for radians,
Angle::SmallAngle ()))doc";

static const char * __doc_Bentley_Geom_Angle_TrigIntegrals =R"doc(Return integrals of [cc cs c; cs ss s; c s 1] from theta0 to theta1

:param (input):
    theta0 beginning of integration interval

:param (input):
    theta1 end of integration interval

:param (output):
    integrals symmetric matrix of integrals.)doc";

static const char * __doc_Bentley_Geom_Angle_ConstructGivensWeights =R"doc(Construct cosine and sine of vector to (a,b). (Just normalize a and
b.)

:param (output):
    cosine

:param (output):
    sine

:param (input):
    a

:param (input):
    b)doc";

static const char * __doc_Bentley_Geom_Angle_ApplyGivensWeights =R"doc(:param (output):
    aOut{(a,b) DOT (cos,sin)}

:param (output):
    bOut{(cross,sin) DOT (a,b)}

:param (input):
    a x coordiante

:param (input):
    b y coordinate

:param (input):
    cos cosine term of Givens rotation.

:param (input):
    sin sine term of Givens rotation.)doc";

static const char * __doc_Bentley_Geom_Angle_Cyclic3dAxes =R"doc(:param (output):
    i0 i adjusted to [0,1,2] with wraparound

:param (output):
    i1 i+1 adjusted to [0,1,2] with wraparound

:param (output):
    i2 i+2 adjusted to [0,1,2] with wraparound

:param (input):
    i initial axis)doc";

static const char * __doc_Bentley_Geom_Angle_Cyclic3dAxis =R"doc(:returns:
    i adjusted to [0,1,2] with wraparound.)doc";

static const char * __doc_Bentley_Geom_Angle_Cyclic2dAxis =R"doc(:returns:
    i adjusted to [0,1] with wraparound.)doc";

static const char * __doc_Bentley_Geom_Angle_Asin =R"doc(Return asin of arg, but cap arg at +- 1)doc";

static const char * __doc_Bentley_Geom_Angle_Acos =R"doc(Return acos of arg, but cap arg at +- 1)doc";

static const char * __doc_Bentley_Geom_Angle_Atan2 =R"doc(Return the arctan of numerator/denominator, in full -PI to PI range.
0,0 returns 0.)doc";

static const char * __doc_Bentley_Geom_Angle_EvaluateTrigCombination =R"doc(Evaluate{f(theta) = constCoff + cosCoff * cos(theta) + sinCoff *
sin(theta)}

:param (input):
    constCoff constant coefficient

:param (input):
    cosCoff cosine coefficient

:param (input):
    sinCoff sine coefficient

:param (input):
    theta evaluation angle)doc";

static const char * __doc_Bentley_Geom_Angle_TrigCombinationRange =R"doc(Find the min and max values of{f(theta) = constCoff + cosCoff *
cos(theta) + sinCoff * sin(theta)} in [-pi,pi]

:param (input):
    constCoff constant coefficient

:param (input):
    cosCoff cosine coefficient

:param (input):
    sinCoff sine coefficient

:param (input):
    thetaMin angle where min occurs

:param (input):
    fMin minimum value

:param (input):
    thetaMax angle where max occurs

:param (input):
    fMax maximum value)doc";

static const char * __doc_Bentley_Geom_Angle_TrigCombinationRangeInSweep =R"doc(Find the min and max values of{f(theta) = constCoff + cosCoff *
cos(theta) + sinCoff * sin(theta)} in [thetaA, thetaB].

:param (input):
    constCoff constant coefficient

:param (input):
    cosCoff cosine coefficient

:param (input):
    sinCoff sine coefficient

:param (input):
    thetaA angle range limit

:param (input):
    sweep sweep angle

:param (input):
    thetaMin angle where min occurs

:param (input):
    fMin minimum value

:param (input):
    thetaMax angle where max occurs

:param (input):
    fMax maximum value)doc";

static const char * __doc_Bentley_Geom_Angle_Rotate90UntilSmallAngle =R"doc(Find a vector that differs from (x0,y0) by a multiple of 90 degrees,
x1 is positive, and y1 is as small as possible in absolute value, i.e.
points to the right.)doc";

static const char * __doc_Bentley_Geom_Angle_HalfAngleFuctions =R"doc(Given trig functions (cosine and sine) of some (double) angle 2A, find
trig functions for the angle A.)doc";

static const char * __doc_Bentley_Geom_Angle_ForwardComplement =R"doc(Angle which sweeps in the same direction to return to sum of 2pi
Examples

* ForwardComplement of{pi/2}{3pi/2}

* ForwardComplement of{-pi/2}{-3pi/2})doc";

static const char * __doc_Bentley_Geom_Angle_ReverseComplement =R"doc(Angle which sweeps in the other direction to the same end angle
(modulo 2pi) as the given sweep.)doc";

static const char * __doc_Bentley_Geom_Angle_PeriodShift =R"doc(Add a multiple of 2PI to theta...)doc";

static const char * __doc_Bentley_Geom_Angle_InSweepAllowPeriodShift =R"doc(Test if theta or any shift by multiple of 2pi is in sweep.)doc";

static const char * __doc_Bentley_Geom_Angle_InExactSweep =R"doc(Test if angle is in sweep with no tolerance or period shift)doc";

static const char * __doc_Bentley_Geom_Angle_NormalizeToSweep =R"doc(Shift{theta} so it is within one period of{thetaStart} in the
direction of{sweep}. Return FRACTIONAL position.)doc";

static const char * __doc_Bentley_Geom_Angle_AdjustToSweep =R"doc(Shift{theta} so it is within one period of{thetaStart} in the
direction of{sweep}. Return angle in radians)doc";

static const char * __doc_Bentley_Geom_Angle_CircleFractionToRadians =R"doc(Convert radians to degrees)doc";

static const char * __doc_Bentley_Geom_Angle_RadiansToDegrees =R"doc(Convert radians to degrees)doc";

static const char * __doc_Bentley_Geom_Angle_DegreesToRadians =R"doc(Convert degrees to radians)doc";

static const char * __doc_Bentley_Geom_Angle_PiOver2 =R"doc(consant{PI/2})doc";

static const char * __doc_Bentley_Geom_Angle_TwoPi =R"doc(constant{2*PI})doc";

static const char * __doc_Bentley_Geom_Angle_Pi =R"doc(constant{PI})doc";

static const char * __doc_Bentley_Geom_Angle_MediumAngle =R"doc(Medium angle used in toleranced angle comparisons.)doc";

static const char * __doc_Bentley_Geom_Angle_TinyAngle =R"doc(About 10 times unit roundoff . . .)doc";

static const char * __doc_Bentley_Geom_Angle_SmallAngle =R"doc(Small angle used in toleranced angle comparisons.)doc";

static const char * __doc_Bentley_Geom_Angle_NearlyEqualAllowPeriodShift =R"doc(Test if two angles are within{SmallAngle}, allowing 2pi shift.)doc";

static const char * __doc_Bentley_Geom_Angle_NearlyEqual =R"doc(Test if two angles are within{SmallAngle} (NOT allowing 2pi shift!!))doc";

static const char * __doc_Bentley_Geom_Angle_IsNearZeroAllowPeriodShift =R"doc(Test if{radians} is{SmallAngle} or smaller.)doc";

static const char * __doc_Bentley_Geom_Angle_IsNearZero =R"doc(Test if{radians} is{SmallAngle} or smaller.)doc";

static const char * __doc_Bentley_Geom_Angle_IsFullCircle =R"doc(Return true if{fabs(radians)} is within{Angle:SmallAngle} of 2PI.)doc";

static const char * __doc_Bentley_Geom_Angle_Degrees =R"doc(Return the angle in degrees)doc";

static const char * __doc_Bentley_Geom_Angle_Radians =R"doc(Return the angle in radians)doc";

static const char * __doc_Bentley_Geom_Angle_Cos =R"doc(return the cosine of the angle.)doc";

static const char * __doc_Bentley_Geom_Angle_Sin =R"doc(return the sine of the angle.)doc";

static const char * __doc_Bentley_Geom_Angle_FromFullCircle =R"doc(Strongly typed " constructor " (static method) for full circle angle)doc";

static const char * __doc_Bentley_Geom_Angle_FromAtan2 =R"doc(Strongly typed " constructor " (static method))doc";

static const char * __doc_Bentley_Geom_Angle_FromRadians =R"doc(Strongly typed " constructor " (static method))doc";

static const char * __doc_Bentley_Geom_Angle_FromDegrees =R"doc(Strongly typed " constructor " (static method))doc";

/*---------------------------------------------------------------------------------**//**
* Class generator for Angle.
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_Angle(py::module_& m)
    {
    //===================================================================================
    // struct Angle
    py::class_<Angle> c1(m, "Angle");

    c1.def(py::init<>());
    c1.def(py::init<AngleCR>());
    
    c1.def(py::self == py::self);
    c1.def(py::self < py::self);
    c1.def(py::self > py::self);
    c1.def(py::self * double());
    c1.def(double() * py::self);
    c1.def(-py::self);
    c1.def(py::self + py::self);
    c1.def(py::self - py::self);

    c1.def("__copy__", [](const Angle& self)
        {
        return Angle (self);
        });
    
    c1.def_static("FromDegrees", &Angle::FromDegrees, "degrees"_a, DOC(Bentley, Geom, Angle, FromDegrees));
    c1.def_static("FromRadians", &Angle::FromRadians, "radians"_a, DOC(Bentley, Geom, Angle, FromRadians));
    c1.def_static("FromAtan2", &Angle::FromAtan2, "sine"_a, "cosine"_a, DOC(Bentley, Geom, Angle, FromAtan2));
    c1.def_static("FromFullCircle", &Angle::FromFullCircle, DOC(Bentley, Geom, Angle, FromFullCircle));
    
    c1.def("Sin", &Angle::Sin, DOC(Bentley, Geom, Angle, Sin));
    c1.def("Cos", &Angle::Cos, DOC(Bentley, Geom, Angle, Cos));
    c1.def("Radians", &Angle::Radians, DOC(Bentley, Geom, Angle, Radians));
    c1.def("Degrees", &Angle::Degrees, DOC(Bentley, Geom, Angle, Degrees));
    
    c1.def_static("IsFullCircle", &Angle::IsFullCircle, "radians"_a, DOC(Bentley, Geom, Angle, IsFullCircle));
    c1.def_static("IsNearZero", &Angle::IsNearZero, "radians"_a, DOC(Bentley, Geom, Angle, IsNearZero));
    c1.def_static("IsNearZeroAllowPeriodShift", py::overload_cast<double>(&Angle::IsNearZeroAllowPeriodShift), "radians"_a, DOC(Bentley, Geom, Angle, IsNearZeroAllowPeriodShift));
    c1.def_static("IsNearZeroAllowPeriodShift", py::overload_cast<double, double>(&Angle::IsNearZeroAllowPeriodShift), "radians"_a, "radiansTol"_a, DOC(Bentley, Geom, Angle, IsNearZeroAllowPeriodShift));
    c1.def_static("NearlyEqual", &Angle::NearlyEqual, "radiansA"_a, "radiansB"_a, DOC(Bentley, Geom, Angle, NearlyEqual));
    c1.def_static("NearlyEqualAllowPeriodShift", &Angle::NearlyEqualAllowPeriodShift, "radiansA"_a, "radiansB"_a, DOC(Bentley, Geom, Angle, NearlyEqualAllowPeriodShift));
    
    c1.def_static("SmallAngle", &Angle::SmallAngle, DOC(Bentley, Geom, Angle, SmallAngle));
    c1.def_static("TinyAngle", &Angle::TinyAngle, DOC(Bentley, Geom, Angle, TinyAngle));
    c1.def_static("MediumAngle", &Angle::MediumAngle, DOC(Bentley, Geom, Angle, MediumAngle));
    c1.def_static("Pi", &Angle::Pi, DOC(Bentley, Geom, Angle, Pi));
    c1.def_static("TwoPi", &Angle::TwoPi, DOC(Bentley, Geom, Angle, TwoPi));
    c1.def_static("PiOver2", &Angle::PiOver2, DOC(Bentley, Geom, Angle, PiOver2));
    
    c1.def_static("DegreesToRadians", &Angle::DegreesToRadians, "degrees"_a, DOC(Bentley, Geom, Angle, DegreesToRadians));
    c1.def_static("RadiansToDegrees", &Angle::RadiansToDegrees, "radians"_a, DOC(Bentley, Geom, Angle, RadiansToDegrees));
    c1.def_static("CircleFractionToRadians", &Angle::CircleFractionToRadians, "fraction"_a, DOC(Bentley, Geom, Angle, CircleFractionToRadians));
    c1.def_static("AdjustToSweep", &Angle::AdjustToSweep, "theta"_a, "thetaStart"_a, "sweep"_a, DOC(Bentley, Geom, Angle, AdjustToSweep));
    c1.def_static("NormalizeToSweep", py::overload_cast<double, double, double>(&Angle::NormalizeToSweep), "theta"_a, "thetaStart"_a, "sweep"_a, DOC(Bentley, Geom, Angle, NormalizeToSweep));
    c1.def_static("NormalizeToSweep", py::overload_cast<double, double, double, bool, bool>(&Angle::NormalizeToSweep), 
                  "theta"_a, "thetaStart"_a, "sweep"_a, "extend0"_a, "extend1"_a, DOC(Bentley, Geom, Angle, NormalizeToSweep));    
    c1.def_static("InExactSweep", &Angle::InExactSweep, "theta"_a, "thetaStart"_a, "sweep"_a, DOC(Bentley, Geom, Angle, InExactSweep));    
    c1.def_static("InSweepAllowPeriodShift", &Angle::InSweepAllowPeriodShift, "theta"_a, "thetaStart"_a, "sweep"_a, DOC(Bentley, Geom, Angle, InSweepAllowPeriodShift));
    
    c1.def_static("PeriodShift", &Angle::PeriodShift, "theta"_a, "periods"_a, DOC(Bentley, Geom, Angle, PeriodShift));    
    c1.def_static("ReverseComplement", &Angle::ReverseComplement, "radians"_a, DOC(Bentley, Geom, Angle, ReverseComplement));    
    c1.def_static("ForwardComplement", &Angle::ForwardComplement, "radians"_a, DOC(Bentley, Geom, Angle, ForwardComplement));
    
    c1.def_static("HalfAngleFuctions", [] (double rCos2A, double rSin2A)
                 {
                 double cosA, sinA;
                 Angle::HalfAngleFuctions(cosA, sinA, rCos2A, rSin2A);
                 return py::make_tuple(cosA, sinA);
                 }, "rCos2A"_a, "rSin2A"_a, DOC(Bentley, Geom, Angle, HalfAngleFuctions));

    c1.def_static("Rotate90UntilSmallAngle", [] (double x0, double y0)
                 {
                 double x1, y1;
                 Angle::Rotate90UntilSmallAngle(x1, y1, x0, y0);
                 return py::make_tuple(x1, y1);
                 }, "x0"_a, "y0"_a, DOC(Bentley, Geom, Angle, Rotate90UntilSmallAngle));

    c1.def_static("TrigCombinationRangeInSweep", [] (double constCoff, double cosCoff, double sinCoff, double thetaA, double sweep)
                 {
                 double thetaMin, fMin, thetaMax, fMax;
                 Angle::TrigCombinationRangeInSweep(constCoff, cosCoff, sinCoff, thetaA, sweep, thetaMin, fMin, thetaMax, fMax);
                 return std::make_tuple(thetaMin, fMin, thetaMax, fMax);
                 }, "constCoff"_a, "cosCoff"_a, "sinCoff"_a, "thetaA"_a, "sweep"_a, DOC(Bentley, Geom, Angle, TrigCombinationRangeInSweep));

    c1.def_static("TrigCombinationRange", [] (double constCoff, double cosCoff, double sinCoff)
                 {
                 double thetaMin, fMin, thetaMax, fMax;
                 Angle::TrigCombinationRange(constCoff, cosCoff, sinCoff, thetaMin, fMin, thetaMax, fMax);
                 return py::make_tuple(thetaMin, fMin, thetaMax, fMax);
                 }, "constCoff"_a, "cosCoff"_a, "sinCoff"_a, DOC(Bentley, Geom, Angle, TrigCombinationRange));

    c1.def_static("EvaluateTrigCombination", &Angle::EvaluateTrigCombination, "constCoff"_a, "cosCoff"_a, "sinCoff"_a, "theta"_a, DOC(Bentley, Geom, Angle, EvaluateTrigCombination));
    
    c1.def_static("Atan2", &Angle::Atan2, "numerator"_a, "denominator"_a, DOC(Bentley, Geom, Angle, Atan2));
    c1.def_static("Acos", &Angle::Acos, "arg"_a, DOC(Bentley, Geom, Angle, Acos));        
    c1.def_static("Asin", &Angle::Asin, "arg"_a, DOC(Bentley, Geom, Angle, Asin));

    c1.def_static("Cyclic2dAxis", &Angle::Cyclic2dAxis, "i"_a, DOC(Bentley, Geom, Angle, Cyclic2dAxis));
    c1.def_static("Cyclic3dAxis", &Angle::Cyclic3dAxis, "i"_a, DOC(Bentley, Geom, Angle, Cyclic3dAxis));

    c1.def_static("Cyclic3dAxes", [] (int i)
                 {
                 int i0, i1, i2;
                 Angle::Cyclic3dAxes(i0, i1, i2, i);
                 return py::make_tuple(i0, i1, i2);
                 }, "i"_a, DOC(Bentley, Geom, Angle, Cyclic3dAxes));

    c1.def_static("ApplyGivensWeights", [] (double a, double b, double cos, double sin)
                 {
                 double aOut, bOut;
                 Angle::ApplyGivensWeights(aOut, bOut, a, b, cos, sin);
                 return py::make_tuple(aOut, bOut);
                 }, "a"_a, "b"_a, "cos"_a, "sin"_a, DOC(Bentley, Geom, Angle, ApplyGivensWeights));

    c1.def_static("ConstructGivensWeights", [] (double a, double b)
                 {
                 double cosine, sine;
                 Angle::ConstructGivensWeights(cosine, sine, a, b);
                 return py::make_tuple(cosine, sine);
                 }, "a"_a, "b"_a, DOC(Bentley, Geom, Angle, ConstructGivensWeights));

    c1.def_static("TrigIntegrals", &Angle::TrigIntegrals, "theta0"_a, "theta1"_a, "integrals"_a, DOC(Bentley, Geom, Angle, TrigIntegrals));
    c1.def("__repr__", [] (AngleCR self)
           {
           return "<Degree:{}, Radians:{}>"_s.format(self.Degrees(), self.Radians());
           });

    //===================================================================================
    // struct AngleInDegrees
    py::class_<AngleInDegrees> c2(m, "AngleInDegrees");

    c2.def(py::init<>());
    c2.def(py::init<AngleInDegrees const&>());
    c2.def(py::init<Angle const&>());

    c2.def_static("SmallAngleInDegrees", &AngleInDegrees::SmallAngleInDegrees, DOC(Bentley, Geom, AngleInDegrees, SmallAngleInDegrees));

    c2.def(py::self == py::self);
    c2.def(py::self < py::self);
    c2.def(py::self <= py::self);
    c2.def(py::self > py::self);
    c2.def(py::self >= py::self);
    c2.def(py::self != py::self);
    c2.def(py::self + py::self);

    c2.def("AlmostEqual", &AngleInDegrees::AlmostEqual, "other"_a, DOC(Bentley, Geom, AngleInDegrees, AlmostEqual));
    c2.def_static("FromRadians", &AngleInDegrees::FromRadians, "radians"_a, DOC(Bentley, Geom, AngleInDegrees, FromRadians));
    c2.def_static("FromDegrees", &AngleInDegrees::FromDegrees, "degrees"_a, DOC(Bentley, Geom, AngleInDegrees, FromDegrees));

    c2.def("Degrees", &AngleInDegrees::Degrees, DOC(Bentley, Geom, AngleInDegrees, Degrees));
    c2.def("Radians", &AngleInDegrees::Radians, DOC(Bentley, Geom, AngleInDegrees, Radians));
    c2.def("Cos", &AngleInDegrees::Cos, DOC(Bentley, Geom, AngleInDegrees, Cos));
    c2.def("Sin", &AngleInDegrees::Sin, DOC(Bentley, Geom, AngleInDegrees, Sin));
    
    c2.def_static("FromAtan2", &AngleInDegrees::FromAtan2, "y"_a, "x"_a, DOC(Bentley, Geom, AngleInDegrees, FromAtan2));
    c2.def("__repr__", [] (AngleInDegrees const& self)
           {
           return "<Degree:{}>"_s.format(self.Degrees());
           });

    c2.def("__copy__", [](const AngleInDegrees& self)
        {
        return AngleInDegrees(self);
        });

    //===================================================================================
    // struct YawPitchRollAngles
    py::class_<YawPitchRollAngles> c3(m, "YawPitchRollAngles");
    
    c3.def(py::init<>());
    c3.def(py::init<AngleInDegrees, AngleInDegrees, AngleInDegrees>(), "yaw"_a, "pitch"_a, "roll"_a);
    c3.def(py::init<Angle, Angle, Angle>(), "yaw"_a, "pitch"_a, "roll"_a);

    c3.def_property_readonly("Yaw", &YawPitchRollAngles::GetYaw);
    c3.def("GetYaw", &YawPitchRollAngles::GetYaw);

    c3.def_property_readonly("Pitch", &YawPitchRollAngles::GetPitch);
    c3.def("GetPitch", &YawPitchRollAngles::GetPitch);
    
    c3.def_property_readonly("Roll", &YawPitchRollAngles::GetRoll);
    c3.def("GetRoll", &YawPitchRollAngles::GetRoll);

    c3.def_static("FromRadians", &YawPitchRollAngles::FromRadians, "yawRadians"_a, "pitchRadians"_a, "rollRadians"_a, DOC(Bentley, Geom, YawPitchRollAngles, FromRadians));
    c3.def_static("FromDegrees", &YawPitchRollAngles::FromDegrees, "yawDegrees"_a, "pitchDegrees"_a, "rollDegrees"_a, DOC(Bentley, Geom, YawPitchRollAngles, FromDegrees));
    c3.def_static("TryFromRotMatrix", &YawPitchRollAngles::TryFromRotMatrix, "angles"_a, "matrix"_a, DOC(Bentley, Geom, YawPitchRollAngles, TryFromRotMatrix));
    
    c3.def("ToRotMatrix", &YawPitchRollAngles::ToRotMatrix, DOC(Bentley, Geom, YawPitchRollAngles, ToRotMatrix));
    c3.def("ToTransform", &YawPitchRollAngles::ToTransform, "origin"_a, DOC(Bentley, Geom, YawPitchRollAngles, ToTransform));
    
    c3.def("IsIdentity", &YawPitchRollAngles::IsIdentity, DOC(Bentley, Geom, YawPitchRollAngles, IsIdentity));
    c3.def("MaxAbsRadians", &YawPitchRollAngles::MaxAbsRadians, DOC(Bentley, Geom, YawPitchRollAngles, MaxAbsRadians));
    c3.def("MaxDiffRadians", &YawPitchRollAngles::MaxDiffRadians, "other"_a, DOC(Bentley, Geom, YawPitchRollAngles, MaxDiffRadians));
    c3.def("MaxAbsDegrees", &YawPitchRollAngles::MaxAbsDegrees, DOC(Bentley, Geom, YawPitchRollAngles, MaxAbsDegrees));
    c3.def("MaxDiffDegrees", &YawPitchRollAngles::MaxDiffDegrees, "other"_a, DOC(Bentley, Geom, YawPitchRollAngles, MaxDiffDegrees));

    c3.def("__repr__", [] (YawPitchRollAngles const& self)
           {
           return "[yaw:{}, pitch:{}, roll:{}]"_s.format(self.GetYaw().Degrees(), self.GetPitch().Degrees(), self.GetRoll().Degrees());
           });
    c3.def("__copy__", [](const YawPitchRollAngles& self)
        {
        return YawPitchRollAngles(self);
        });
    }

