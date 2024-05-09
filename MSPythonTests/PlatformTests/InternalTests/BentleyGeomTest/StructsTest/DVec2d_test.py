import os
import pytest
import math
import numpy

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyGeomTest import *

'''
Test vector Initialization.
'''
def test_DVec2d_Initialization():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 2.0)
    vector1 = DVec2d()
    vector1.Init (1.0, 2.0)
    Check.Near (vector0.x, 1.0, nameStr)
    Check.Near (vector0.y, 2.0, nameStr)
    Check.Near (vector0, vector1, nameStr)

'''
Test vector CrossProduct and DotProduct.
'''
def test_DVec2d_CrossProduct():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 2.0)
    vector1 = DVec2d.From (3.0, 4.0)
    point0 = DPoint2d.From (1.0, 2.0)
    point1 = DPoint2d.From (3.0, 4.0)
    vectorCrossProductCodedMethod = vector0.CrossProduct (vector1)
    vectorCrossProductAlternateMethod = vector0.Magnitude () * vector1.Magnitude () * math.sin (vector0.AngleTo(vector1))
    vectorCrossProductSquaredCodedMethod = vector0.CrossProductSquared (vector1)
    vectorDotProductCodedMethod = vector0.DotProduct (vector1)
    vectorDotProductAlternateMethod = vector0.Magnitude () * vector1.Magnitude () * math.cos (vector0.AngleTo(vector1))
    pointDotProductCodedMethod = point0.DotProduct (point1)
    pointDotProductAlternateMethod = point0.Magnitude () * point1.Magnitude () * math.cos (point0.AngleTo(point1))
    vectorDotProductPassedWithValuesCodedMethod = vector0.DotProduct (3.0, 4.0)
    vectorDotProductPassedWithValuesAlternateMethod = vector0.Magnitude () * vector1.Magnitude () * math.cos (vector0.AngleTo(vector1))
    Check.Near (vectorCrossProductCodedMethod, vectorCrossProductAlternateMethod, nameStr)
    Check.Near (vectorCrossProductCodedMethod * vectorCrossProductCodedMethod, vectorCrossProductSquaredCodedMethod, nameStr)
    Check.Near (vectorDotProductCodedMethod, vectorDotProductAlternateMethod, nameStr)
    Check.Near (pointDotProductCodedMethod, pointDotProductAlternateMethod, nameStr)
    Check.Near (vectorDotProductPassedWithValuesCodedMethod, vectorDotProductPassedWithValuesAlternateMethod, nameStr)

'''
Test vector NormalizedDifference.
'''
def test_DVec2d_NormalizedDifference():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 2.0)
    vector1 = DVec2d.From (3.0, 4.0)
    vector2 = DVec2d.From (5.0, 6.0)
    point0 = DPoint2d.From (5.0, 6.0)
    point1 = DPoint2d.From (0.0, 0.0)
    vector0.Normalize()
    vector0NormalizedMagnitude = vector0.Magnitude ()
    vector0PreNormalized = DVec2d.From (1.0, 2.0)
    angleBetweenPreNormalizedVectorAndNormalizedVector = vector0PreNormalized.AngleTo (vector0)
    vector1.NormalizedDifference (point0, point1)
    vector1NormalizedMagnitude = vector1.Magnitude ()
    vector2.Normalize ()
    Check.Near (1.0, vector0NormalizedMagnitude, nameStr)
    Check.Near (0.0, angleBetweenPreNormalizedVectorAndNormalizedVector, nameStr);
    Check.Near (1.0, vector1NormalizedMagnitude, nameStr)
    Check.Near (vector1, vector2, nameStr)

'''
Test vector AngleTo.
'''
def test_DVec2d_AngleTo():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 0.0)
    vector1 = DVec2d.From (1.0, 1.0)
    vector2 = DVec2d.From (0.0, 1.0)
    vector3 = DVec2d.From (2.3, 4.5)
    vector4 = DVec2d.From (2.3, 4.5)
    vector5 = DVec2d.From (-1.0, 1.0)
    angleFromVec0ToVec1 = vector0.AngleTo (vector1)
    angleFromVec0ToVec0 = vector0.AngleTo (vector0)
    angleFromVec0ToVec2 = vector0.AngleTo (vector2)
    angleFromVec2ToVec0 = vector2.AngleTo (vector0)
    vector3.RotateCCW (0.67)
    angleFromVec4ToVec3 = vector4.AngleTo (vector3)
    smallAngleFromVec0ToVec5 = vector0.SmallerUnorientedAngleTo (vector5)
    smallAngleFromVec4ToVec3 = vector4.SmallerUnorientedAngleTo (vector3)
    Check.Near (math.pi/4, angleFromVec0ToVec1, nameStr)
    Check.Near (0.0, angleFromVec0ToVec0, nameStr)
    Check.Near (math.pi/2, angleFromVec0ToVec2, nameStr)
    Check.Near (-math.pi/2, angleFromVec2ToVec0, nameStr)
    Check.Near (0.67, angleFromVec4ToVec3, nameStr)
    Check.Near (math.pi/4, smallAngleFromVec0ToVec5, nameStr)
    Check.Near (0.67, smallAngleFromVec4ToVec3, nameStr)

'''
Test vector AngleInSector.
'''
def test_DVec2d_AngleInSector():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 0.0)
    vector1 = DVec2d.From (0.0, 1.0)
    vector2 = DVec2d.From (0.5, 0.5)
    vector3 = DVec2d.From (-0.5, 0.5)
    vector4 = DVec2d.From (-0.5, -0.5)
    vector5 = DVec2d.From (0.5, -0.5)
    Check.IsTrue(vector2.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue(not vector3.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue(not vector4.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue(not vector5.IsVectorInSmallerSector (vector0, vector1), nameStr)
    baseVector = DVec2d()
    endVector = DVec2d()
    testVector = DVec2d()
    checkVector = DVec2d()
    for baseAngle in numpy.arange (0.1, Angle.TwoPi(), 1.0):
        baseVector = DVec2d.From (math.cos (baseAngle), math.sin (baseAngle))
        for sweepAngle in numpy.arange (0.42, Angle.TwoPi(), 1.0):
            endVector.RotateCCW (baseVector, sweepAngle)
            checkVector = baseVector
            checkVector.RotateCCW (sweepAngle)
            Check.Near (endVector, checkVector, nameStr)
            checkVector.RotateCCW (-sweepAngle)
            Check.Near (baseVector, checkVector, nameStr)
            sweepAngle1 = baseVector.AngleTo (endVector)
            Check.IsTrue (Angle.NearlyEqualAllowPeriodShift (sweepAngle, sweepAngle1), nameStr)
            Check.Bool (sweepAngle < Angle.Pi (), Angle.NearlyEqual (sweepAngle, sweepAngle1), nameStr)
            for testAngle in numpy.arange (0.1234, Angle.TwoPi(), 0.041):
                testVector.RotateCCW (baseVector, testAngle)
                if testAngle < sweepAngle:
                    Check.IsTrue (testVector.IsVectorInCCWSector (baseVector, endVector), nameStr)
                else:
                    Check.IsFalse (testVector.IsVectorInCCWSector (baseVector, endVector), nameStr)
                Check.IsTrue (testVector.IsVectorInCCWSector (baseVector, endVector) !=
                               testVector.IsVectorInCCWSector (endVector, baseVector), nameStr)
                Check.Bool (testVector.IsVectorInSmallerSector (baseVector, endVector),
                           testVector.IsVectorInSmallerSector (endVector, baseVector), nameStr)
                if (sweepAngle < Angle.Pi ()):
                    Check.Bool (testAngle < sweepAngle, testVector.IsVectorInSmallerSector (baseVector, endVector), nameStr)
                else:
                    Check.Bool (testAngle > sweepAngle, testVector.IsVectorInSmallerSector (baseVector, endVector), nameStr)


'''
Test vector RotateCCW.
'''
def test_DVec2d_RotateCCW():
    nameStr = ''
    baseVector = DVec2d.From (1.0, 0.0)
    rotVector = DVec2d.From (2.0, 3.0)
    theta = 0.5
    rotVector.RotateCCW (baseVector, theta)
    angleFromBaseVecToRotVec = baseVector.AngleTo (rotVector)
    Check.Near (theta, angleFromBaseVecToRotVec, nameStr)

'''
Test vector MagnitudeSquared.
'''
def test_DVec2d_MagnitudeSquared():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    magnitude = vector0.Magnitude ()
    magnitudeSquared = vector0.MagnitudeSquared ()
    Check.Near (magnitude * magnitude, magnitudeSquared, nameStr)

'''
Test vector UnitPerpendicular.
'''
def test_DVec2d_UnitPerpendicular():
    nameStr = ''
    vector0 = DVec2d.From (2.5, 7.9)
    vector1 = DVec2d.From (3.4, 6.8)
    vector0.UnitPerpendicular (vector1)
    angleFromVec1ToVec0 = vector1.AngleTo (vector0)
    magnitudeVec0 = vector0.Magnitude ()
    Check.Near (math.pi/2, angleFromVec1ToVec0, nameStr)
    Check.Near (1.0, magnitudeVec0, nameStr)

'''
Test vector Magnitude.
'''
def test_DVec2d_Magnitude():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 0.0)
    vector1 = DVec2d.From (2.5, 3.0)
    vector2 = DVec2d.From (0.0, 0.0)
    magnitudeVec0 = vector0.Magnitude ()
    magnitudeVec1 = vector1.Magnitude ()
    magnitudeVec2 = vector2.Magnitude ()
    Check.Near (1.0, magnitudeVec0, nameStr)
    Check.Near (math.sqrt (15.25), magnitudeVec1, nameStr)
    Check.Near (0.0, magnitudeVec2, nameStr)

'''
Test vector Scale.
'''
def test_DVec2d_Scale():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 0.0)
    vector1 = DVec2d.From (1.0, 1.0)
    vector2 = DVec2d.From (5.0, 5.0)
    scale = 5.0
    vector0.Scale (vector1, scale)
    vector1.Scale (scale)
    Check.Near (vector0, vector2, nameStr)
    Check.Near (vector1, vector2, nameStr)

'''
Test vector Negate.
'''
def test_DVec2d_Negate():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 0.0)
    vector1 = DVec2d.From (1.0, 1.0)
    vector2 = DVec2d.From (-1.0, -1.0)
    vector0.Negate (vector1)
    vector1.Negate ()
    Check.Near (vector0, vector2, nameStr)
    Check.Near (vector1, vector2, nameStr)

'''
Test vector Normalize.
'''
def test_DVec2d_Normalize():
    nameStr = ''
    vector1 = DVec2d.From (13.8, 5.7);
    vector2 = DVec2d.From (-1.0, -8.0);
    vector3 = DVec2d.From (0.0, 0.0);
    unit1 = DVec2d()
    unit2 = DVec2d()
    unit3 = DVec2d()
    mag1 = unit1.Normalize (vector1)
    mag2 = unit2.Normalize (vector2)
    mag3 = unit3.Normalize (vector3)
    Check.Near (mag1, vector1.Magnitude (), nameStr)
    Check.Near (mag2, vector2.Magnitude (), nameStr)
    Check.Near (1.0, unit1.Magnitude (), nameStr)
    Check.Near (1.0, unit2.Magnitude (), nameStr)
    Check.Near (1.0, unit3.Magnitude (), nameStr)
    Check.IsTrue (unit1.IsParallelTo (vector1), nameStr)
    Check.IsTrue (unit2.IsParallelTo (vector2), nameStr)
    Check.Near (0.0, mag3, nameStr)

'''
Test vector ScaleToLength.
'''
def test_DVec2d_ScaleToLength():
    nameStr = ''
    vector0 = DVec2d.From (0.0, 0.0)
    vector1 = DVec2d.From (0.0, 0.0)
    vector2 = DVec2d.From (9.6, 3.4)
    vector3 = DVec2d.From (5.0, 0.0)
    vector4 = DVec2d.From (3.2, 7.1)
    vector5 = DVec2d.From (0.0, 0.0)
    length = 5.0;
    magnitudeVec1 = vector1.Magnitude ()
    returnedLengthVec1 = vector0.ScaleToLength (vector1, length)
    magnitudeVec0 = vector0.Magnitude ()
    magnitudeVec4 = vector4.Magnitude ()
    returnedLengthVec4 = vector2.ScaleToLength (vector4, length)
    magnitudeVec2 = vector2.Magnitude ()
    magnitudeVec5 = vector5.Magnitude ()
    returnedLentghVec5 = vector5.ScaleToLength (length)
    magnitudeVec5AfterScale = vector5.Magnitude ()
    Check.Near (magnitudeVec1, returnedLengthVec1, nameStr)
    Check.Near (vector3, vector0, nameStr)
    Check.Near (5.0, magnitudeVec0, nameStr)
    Check.Near (magnitudeVec4, returnedLengthVec4, nameStr)
    Check.Near (5.0, magnitudeVec2, nameStr)
    Check.Near (magnitudeVec5, returnedLentghVec5, nameStr)
    Check.Near (5.0, magnitudeVec5AfterScale, nameStr)
    Check.Near (vector3, vector5, nameStr)

'''
Test vector IsParallelTo.
'''
def test_DVec2d_IsParallelTo():
    nameStr = ''
    vector0 = DVec2d.From (0.0, 1.0)
    vector1 = DVec2d.From (0.0, -5.0)
    vector2 = DVec2d.From (1.0, 0.0)
    vector3 = DVec2d.From (8.0, 0.0)
    vector4 = DVec2d.From (2.5, 2.5)
    vector5 = DVec2d.From (7.5, 7.5)
    Check.IsTrue (vector0.IsParallelTo (vector1), nameStr)
    Check.IsTrue (not vector0.IsParallelTo (vector2), nameStr)
    Check.IsTrue (vector2.IsParallelTo (vector3), nameStr)
    Check.IsTrue (not vector2.IsParallelTo (vector1), nameStr)
    Check.IsTrue (vector4.IsParallelTo (vector5), nameStr)
    Check.IsTrue (not vector4.IsParallelTo (vector3), nameStr)

'''
Test vector IsPerpendicularTo.
'''
def test_DVec2d_IsPerpendicularTo():
    nameStr = ''
    vector0 = DVec2d.From (1.0, 0.0)
    vector1 = DVec2d.From (0.0, 1.0)
    vector2 = DVec2d.From (3.4, 5.6)
    Check.IsTrue (vector0.IsPerpendicularTo (vector1), nameStr)
    Check.IsTrue (not vector0.IsPerpendicularTo (vector2), nameStr)

'''
Test vector SafeDivide.
'''
def test_DVed2d_SafeDivide():
    nameStr = ''
    vector0 = DVec2d.From (0.0, 0.0)
    vector1 = DVec2d.From (1.0, 1.0)
    vector2 = DVec2d.From (0.5, 0.5)
    denominator0 = 0.0
    denominator1 = 2.0
    denominator2 = 0.000000000001
    Check.IsTrue (not vector0.SafeDivide (vector1, denominator0), nameStr)
    Check.Near (vector0, vector1, nameStr)
    Check.IsTrue (vector0.SafeDivide (vector1, denominator1), nameStr)
    Check.Near (vector2, vector0, nameStr)
    Check.IsTrue (not vector0.SafeDivide (vector1, denominator2), nameStr)
    Check.Near (vector0, vector1, nameStr)

'''
Test vector MaxAbs.
'''
def test_DVed2d_MaxAbs():
    nameStr = ''
    vector0 = DVec2d.From (2.0, -7.8)
    vector1 = DVec2d.From (2.0, 7.8)
    vector2 = DVec2d.From (0.0, 0.0)
    maxValVec0 = vector0.MaxAbs ()
    maxValVec1 = vector1.MaxAbs ()
    maxValVec2 = vector2.MaxAbs ()
    Check.Near (7.8, maxValVec0, nameStr)
    Check.Near (7.8, maxValVec1, nameStr)
    Check.Near (0.0, maxValVec2, nameStr)

'''
Test vector Zero.
'''
def test_DVec2d_Zero():
    nameStr = ''
    vector0 = DVec2d.From (2.0, -7.8)
    vector1 = DVec2d.From (20.0, 34.8)
    vector2 = DVec2d.From (0.0, 0.0)
    vector3 = DVec2d.From (1.0, 1.0)
    vector0.Zero ()
    vector1.Zero ()
    Check.Near (vector2, vector0, nameStr)
    Check.Near (vector2, vector1, nameStr)
    vector0.One ()
    vector1.One ()
    vector2.One ()
    Check.Near (vector3, vector0, nameStr)
    Check.Near (vector3, vector1, nameStr)
    Check.Near (vector3, vector2, nameStr)

'''
Test vector Init.
'''
def test_DVec2d_Init():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (1.0, 2.0)
    vector2 = DVec2d.From (4.0, 9.0)
    vector3 = DVec2d.From (3.0, 5.6)
    point0 = DPoint2d.From (1.0, 2.0)
    ax = 3.0
    ay = 5.6
    # Init a vector from a point.
    vector0.Init (point0)
    # Init a vector from xy components.
    vector2.Init (ax, ay)
    Check.Near (vector1, vector0, nameStr)
    Check.Near (vector3, vector2, nameStr)

'''
Test vector XyOf.
'''
def test_DVec2d_XyOf():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (1.0, 2.0)
    point0 = DPoint4d.From (1.0, 2.0, 3.0, 4.0)
    vector0.XyOf (point0)
    Check.Near (vector1, vector0, nameStr)

'''
Test vector SetComponent.
'''
def test_DVec2d_SetComponent():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (8.0, 5.0)
    vector2 = DVec2d.From (8.0, 8.0)
    component0 = 8.0
    index0 = 0
    index1 = 1
    vector0.SetComponent (component0, index0)
    Check.Near (vector1, vector0, nameStr)
    vector0.SetComponent (component0, index1)
    Check.Near (vector2, vector0, nameStr)

'''
Test vector GetComponent.
'''
def test_DVec2d_GetComponent():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (4.0, 5.0)
    index0 = 0
    index1 = 1
    index2 = 2
    index3 = 3
    xCoord = 7.8
    yCoord = 9.2
    returnedComponentX0 = vector0.GetComponent (index0)
    returnedComponentY0 = vector0.GetComponent (index1)
    returnedComponentX1 = vector0.GetComponent (index2)
    returnedComponentY1 = vector0.GetComponent (index3)
    (xCoord, yCoord) = vector1.GetComponents()
    Check.Near (3.0, returnedComponentX0, nameStr)
    Check.Near (5.0, returnedComponentY0, nameStr)
    Check.Near (3.0, returnedComponentX1, nameStr)
    Check.Near (5.0, returnedComponentY1, nameStr)
    Check.Near (4.0, xCoord, nameStr)
    Check.Near (5.0, yCoord, nameStr)

'''
Test vector SumOf.
'''
def test_DVec2d_SumOf():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (4.0, 5.0)
    vector2 = DVec2d.From (7.7, 5.3)
    vector3 = DVec2d.From (11.7, 10.3)
    vector4 = DVec2d.From (45.67, 36.89)
    vector5 = DVec2d.From (53.37, 42.19)
    vector6 = DVec2d.From (99.04, 79.08)
    vector7 = DVec2d.From (266.85, 210.95)
    vector8 = DVec2d.From (268.85, 218.95)
    vector9 = DVec2d.From (10.3, 8.2)
    vector10 = DVec2d.From (29.1, 5.2)
    vector11 = DVec2d.From (175.72, 70.84)
    vector12 = DVec2d.From (17.72, 7.84)
    vector13 = DVec2d.From (301.532, 126.504)
    origin0 = DVec2d.From (0.0, 0.0)
    origin1 = DVec2d.From (2.0, 8.0)
    scale = 5.0
    scale1 = 4.2
    scale2 = 7.1
    vector0.SumOf (vector1, vector2)
    Check.Near (vector3, vector0, nameStr)
    vector1.SumOf (vector2, vector4)
    Check.Near (vector5, vector1, nameStr)
    vector4.Add (vector5)
    Check.Near (vector6, vector4, nameStr)
    vector6.SumOf (origin0, vector5, scale)
    Check.Near (vector7, vector6, nameStr)
    vector6.SumOf (origin1, vector5, scale)
    Check.Near (vector8, vector6, nameStr)
    vector0.SumOf (origin1, vector9, scale, vector10, scale1)
    Check.Near (vector11, vector0, nameStr)
    vector0.SumOf (origin1, vector9, scale, vector10, scale1, vector12, scale2)
    Check.Near (vector13, vector0, nameStr)

'''
Test vector Subtract.
'''
def test_DVec2d_Subtract():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (4.0, 5.0)
    vector2 = DVec2d.From (-1.0, 0.0)
    vector3 = DVec2d.From (38.98, 53.23)
    vector4 = DVec2d.From (49.01, 95.38)
    vector5 = DVec2d.From (-10.03, -42.15)
    vector0.Subtract (vector1)
    vector3.Subtract (vector4)
    Check.Near (vector2, vector0, nameStr)
    Check.Near (vector5, vector3, nameStr)

'''
Test vector DifferenceOf.
'''
def test_DVec2d_DifferenceOf():
    nameStr = ''
    vector0 = DVec2d.From (3.0, 5.0)
    vector1 = DVec2d.From (4.0, 5.0)
    vector2 = DVec2d.From (-1.0, 0.0)
    vector3 = DVec2d.From (5.0, 5.0)
    vector4 = DVec2d.From (5.9, 15.0)
    vector5 = DVec2d.From (-2.0, 1.5)
    point0 = DPoint2d.From (1.0, 6.0)
    point1 = DPoint2d.From (3.0, 4.5)
    vector0.DifferenceOf (vector1, vector2)
    vector4.DifferenceOf (point0, point1)
    Check.Near (vector3, vector0, nameStr)
    Check.Near (vector5, vector4, nameStr)

'''
Test vector Distance.
'''
def test_DVec2d_Distance():
    nameStr = ''
    vector0 = DVec2d.From (0.0, 0.0)
    vector1 = DVec2d.From (4.0, 5.0)
    vector2 = DVec2d.From (-1.0, -7.8)
    distanceBetweenVec0Vec0 = vector0.Distance (vector0)
    distanceBetweenVec1Vec2 = vector1.Distance (vector2)
    distanceSquaredBetweenVec1Vec2 = vector1.DistanceSquared (vector2)
    Check.Near (0.0, distanceBetweenVec0Vec0, nameStr)
    Check.Near (math.sqrt (188.84), distanceBetweenVec1Vec2, nameStr)
    Check.Near (188.84, distanceSquaredBetweenVec1Vec2, nameStr)

'''
Test vector IsEqual.
'''
def test_DVec2d_IsEqual():
    nameStr = ''
    vector0 = DVec2d.From (4.0, 5.0)
    vector1 = DVec2d.From (4.0, 5.0)
    vector2 = DVec2d.From (-1.0, -7.8)
    vector3 = DVec2d.From (4.0001, 5.00001)
    vector4 = DVec2d.From (4.01, 5.01)
    tolerance0 = 0.0
    tolerance1 = 0.001
    Check.IsTrue (vector0.IsEqual (vector1), nameStr)
    Check.IsTrue (not vector0.IsEqual (vector2), nameStr)
    Check.IsTrue (vector0.IsEqual (vector1, tolerance0), nameStr)
    Check.IsTrue (vector0.IsEqual (vector3, tolerance1), nameStr)
    Check.IsTrue (not vector0.IsEqual (vector4, tolerance1), nameStr)

'''
Check root round trip.
'''
def CheckRootRoundTrip (a):
    b = a * a
    a1 = math.sqrt (b)
    vector = DVec2d.From (a, 0.0)
    a1 = vector.Magnitude ()
    s_relTol = 2.0e-16
    if not Check.IsTrue (abs (a1-a) < s_relTol * (1.0 + a), "System sqrt"):
        printf ("(a = %20.17le) (sqrt (a*a) = %22.17le) (diff %10.4le)\n", a, a1, a1-a)

'''
Test vector MagnitudeRoundOff.
'''
def test_DVec2d_MagnitudeRoundOff():
    CheckRootRoundTrip (1.0)
    CheckRootRoundTrip (0.0)
    CheckRootRoundTrip (1.0/3.0)
    CheckRootRoundTrip (math.sqrt (2.0))
    CheckRootRoundTrip (math.sqrt (15.0))
    CheckRootRoundTrip (math.pow (5.02342343, 0.2346237467))