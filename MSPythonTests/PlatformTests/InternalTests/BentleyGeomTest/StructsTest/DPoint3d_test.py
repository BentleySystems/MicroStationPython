import os
import pytest
import math
import numpy

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyGeomTest import *

'''
Test set point to Zero or One.
'''
def test_DPoint3d_Zero ():
    namestr = ''
    point0 = DPoint3d.From (12.9, -4.3, -3.4)
    point1 = DPoint3d.From (0.0, 0.0, 0.0)
    point2 = DPoint3d.From (1.0, 1.0, 1.0)
    point3 = DPoint3d.From (-54.0, 3.6, -78.9)
    # Test DPoint3d.Zero.
    point0.Zero ()
    # Test DPoint3d.One.
    point3.One ()
    isNear = Check.Near (point1, point0, namestr)
    print (isNear)
    assert True == isNear
    isNear = Check.Near (point2, point3, namestr)
    assert True == isNear

'''
Test point addition.
'''
def test_DPoint3d_Add():
    nameStr = ''
    point0 = DPoint3d (5.0, 5.0, -1.0)
    vec0 = DVec3d (1.0, 1.0, 1.0)
    # Test addition of 2 points.
    result = point0 + vec0
    expectedResult = DPoint3d (6.0, 6.0, 0.0)
    print("\n Test point addition: ")
    print(" Point0 is :         ", point0)
    print(" Vec0 is :           ", vec0)
    print(" Result is :         ", result)
    print(" Expected result is: ", expectedResult)
    assert Check.Near (expectedResult, result, nameStr)
    # Test addition assignment of point.
    point0 += vec0
    print("\n Test point additon assignment:")    
    print(" Result is :         ", point0)
    print(" Expected result is: ", expectedResult)
    assert Check.Near (expectedResult, point0, nameStr)


'''
Test point substraction.
'''
def test_DPoint3d_Substract():
    nameStr = ''
    point0 = DPoint3d (5.0, 5.0, -1.0)
    vec0 = DVec3d (1.0, 1.0, 1.0)
    # Test substraction of 2 points.
    result = point0 - vec0
    expectedResult = DPoint3d (4.0, 4.0, -2.0)
    print("\n Test point substraction:")
    print(" Point0 is :         ", point0)
    print(" Vec0 is :           ", vec0)
    print(" Result is :         ", result)
    print(" Expected result is: ", expectedResult)
    assert Check.Near (expectedResult, result, nameStr)
    # Test substraction assignment of point.
    point0 -= vec0
    print("\n Test point subtraction assignment: ")
    print(" Result is :         ", point0)
    print(" Expected result is: ", expectedResult)
    assert Check.Near (expectedResult, point0, nameStr)

''' 
Test point equal of DPoint3d.
'''
def test_DPoint3d_Equal():
    nameStr = ''
    point0 = DPoint3d.FromOne()
    point1 = DPoint3d.From(1.0, 1.0, 1.0)
    print("\n Test point equal:")
    assert point0 == point1

'''
Test swap of 2 points of DPoint3d.
'''
def test_DPoint3d_Swap():
    nameStr = ''
    point0 = DPoint3d.FromOne()
    point1 = DPoint3d.FromZero()
    point0.Swap (point1)
    print("\n Test point swap:")
    assert point0 == DPoint3d.FromZero()
    assert point1 == DPoint3d.FromOne()

'''
Test cross product, dot product and triple product of points.
'''
def test_DPoint3d_CrossProductToPointsXY():
    nameStr = ''
    point0 = DPoint3d (0.0, 0.0, 0.0)
    point1 = DPoint3d (1.0, 1.0, 1.0)
    point2 = DPoint3d (4.0, 5.0, 6.0)
    point3 = DPoint3d (3.0, 4.0, 8.0)
    vec0 = DVec3d (2.0, 3.0, 4.0)
    # Test cross product of xy parts of points.
    cross = point0.CrossProductToPointsXY (point1, point2)
    # Test dot product of points.
    dot0 = point0.DotProductToPoints (point1, point2)
    # Test dot product of xy parts of points.
    dot1 = point0.DotProductToPointsXY (point1, point2)
    # Test dot difference of 2 vectors.
    dot2 = point2.DotDifference (point0, vec0)
    # Test triple product of vectors from a base point three target points.
    triple = point0.TripleProductToPoints (point1, point2, point3)
    print ("\n Test point CrossProductToPointsXY:")
    print (type(cross))
    print (type(1.0))
    assert Check.Near (1.0, cross, nameStr)
    print ("\n Test point DotProductToPoints:")
    assert Check.Near (15.0, dot0, nameStr)
    print ("\n Test point DotProductToPointsXY:")
    assert Check.Near (9.0, dot1, nameStr)
    print ("\n Test point DotDifference:")
    assert Check.Near (47.0, dot2, nameStr)
    print ("\n Test point TripleProductToPoints:")
    assert Check.Near (3.0, triple, nameStr)

'''
Test point initialization of DPoint3d.
'''
def test_DPoint3d_Init():
    nameStr = ''
    point1 = DPoint3d (2.0, -7.9, 8.9)
    point4 = DPoint3d (2.0, -7.9, 0.0)
    point = DPoint3d.FromZero()
    # Initialize a DPoint3d from DPoint2d.
    point.Init (DPoint2d (2.0, -7.9))
    print ("\n Test point Init from DPoint2d:")
    assert Check.Near (point4, point, nameStr) 
    # Initialize a DPoint3d from xyz.   
    point.Init (2.0, -7.9, 8.9)
    print ("\n Test point Init from xyz:")
    assert Check.Near (point1, point, nameStr)
    # Initialize a DPoint3d from xy.
    point.Init (2.0, -7.9)
    print ("\n Test point Init from xy:")
    assert Check.Near (point4, point, nameStr)  
    # Initialize a DPoint3d from vector.
    point.Init (DVec3d (2.0, -7.9, 8.9))
    print ("\n Test point Init from DVec3d:")
    assert Check.Near (point1, point, nameStr)

'''
Test set component of DPoint3d.
'''
def test_DPoint3d_SetComponent():
    nameStr = ''
    point1 = DPoint3d.From (2.0, -7.9,  5.0)
    point2 = DPoint3d.From (4.0, -7.9,  5.0)
    point3 = DPoint3d.From (2.0,  9.3,  5.0)
    point4 = DPoint3d.From (-5.1, -7.9, 5.0)
    point5 = DPoint3d.From (2.0,  -7.9, 9.0)
    xx = 2.0
    yy = -7.9
    zz = 5.0
    index0 = 0
    index1 = 1
    index2 = 2
    index3 = 3
    point2.SetComponent (xx, index0)
    point3.SetComponent (yy, index1)
    point4.SetComponent (xx, index3)
    point5.SetComponent (zz, index2)
    component0 = point1.GetComponent (index0)
    component1 = point1.GetComponent (index1)
    component2 = point1.GetComponent (index2)
    component3 = point1.GetComponent (index3)
    (xCoord, yCoord, zCoord) = point1.GetComponents ()
    print ("\n Test point Components")
    Check.Near (point1, point2, nameStr)
    Check.Near (point1, point3, nameStr)
    Check.Near (point1, point4, nameStr)
    Check.Near (point1, point5, nameStr)
    Check.Near (xx, component0, nameStr)
    Check.Near (yy, component1, nameStr)
    Check.Near (zz, component2, nameStr)
    Check.Near (xx, xCoord, nameStr)
    Check.Near (yy, yCoord, nameStr)

'''
Test point interpolate of DPoint3d.
'''
def test_DPoint3d_Interpolate():
    nameStr = ''
    point0 = DPoint3d.FromZero()
    point1 = DPoint3d.From (0.0, 1.0, 0.0)
    point2 = DPoint3d.FromZero()
    point3 = DPoint3d.From (0.0, 0.5, 0.0)
    s = 0.5
    point0.Interpolate (point2, s, point1)
    print ("\n Test point Interpolate")
    Check.Near (point3, point0, nameStr)

'''
Test IsPointInSmallerSector of DPoint3d.
'''
def test_DPoint3d_IsPointInSmallerSector():
    nameStr = ''
    point0 = DPoint3d.FromZero()
    vector0 = DPoint3d.From (1.0,  0.0,  0.0)
    vector1 = DPoint3d.From (0.0,  1.0,  0.0)
    vector2 = DPoint3d.From (0.5,  0.5,  0.0)
    vector3 = DPoint3d.From (-0.5, 0.5,  0.0)
    vector4 = DPoint3d.From (-0.5, -0.5, 0.0)
    vector5 = DPoint3d.From (0.5,  -0.5, 0.0)
    upVector = DVec3d.From (0.0, 1.0, 0.0)
    print ("\n Test point IsPointInSmallerSector")
    Check.IsTrue (vector2.IsPointInSmallerSector(point0, vector0, vector1), nameStr)
    Check.IsTrue (not vector3.IsPointInSmallerSector (point0, vector0, vector1), nameStr)
    Check.IsTrue (not vector4.IsPointInSmallerSector (point0, vector0, vector1), nameStr)
    Check.IsTrue (not vector5.IsPointInSmallerSector (point0, vector0, vector1), nameStr)
    Check.IsTrue (not vector2.IsPointInCCWector (point0, vector0, vector1, upVector), nameStr)
    Check.IsTrue (vector3.IsPointInCCWector (point0, vector0, vector1, upVector), nameStr)
    Check.IsTrue (vector4.IsPointInCCWector (point0, vector0, vector1, upVector), nameStr)
    Check.IsTrue (vector5.IsPointInCCWector (point0, vector0, vector1, upVector), nameStr)

'''
Test point distance of DPoint3d.
'''
def test_DPoint3d_Distance():
    nameStr = ''
    vector0 = DPoint3d.FromZero()
    vector1 = DPoint3d.From (4.0,  5.0,  0.0)
    vector2 = DPoint3d.From (-1.0, -7.8, 1.0)
    matrix0 = DMatrix4d.FromRowValues (1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0)
    distance = 0.0
    #Test DPoint3d.Distance.
    distanceBetweenVec0Vec0 = vector0.Distance (vector0)
    distanceBetweenVec1Vec2 = vector1.Distance (vector2)
    #Test DPoint3d.DistanceSquared.
    distanceSquaredBetweenVec1Vec2 = vector1.DistanceSquared (vector2)
    #Test DPoint3d.DistanceSquaredXY.
    distanceSquaredXYBetweenVec1Vec2 = vector1.DistanceSquaredXY (vector2)
    #Test DPoint3d.DistanceXY.
    distanceXYBetweenVec1Vec2 = vector1.DistanceXY (vector2)
    print ("\n Test point distance")
    (bRet, distance) = vector1.DistanceXY (vector2, matrix0)
    Check.IsTrue (bRet, 'distance with transform')    
    Check.Near (0.0, distanceBetweenVec0Vec0, nameStr)
    Check.Near (math.sqrt(189.84), distanceBetweenVec1Vec2, nameStr)
    Check.Near (189.84, distanceSquaredBetweenVec1Vec2, nameStr)
    Check.Near (188.84, distanceSquaredXYBetweenVec1Vec2, nameStr)
    Check.Near (math.sqrt(188.84), distanceXYBetweenVec1Vec2, nameStr)
    Check.Near (math.sqrt(188.84), distance, nameStr)

'''
Test point MaxAbs.
'''
def test_DPoint3d_MaxAbs():
    nameStr = ''
    point0 = DPoint3d.From (-2.0, -15.0, 1.0)
    point1 = DPoint3d.From (4.0, -5.0, 1.0)
    maxVal0 = point0.MaxAbs()
    maxVal1 = point1.MaxAbs()
    print ("\n Test point MaxAbs")
    Check.Near (15.0, maxVal0, nameStr)
    Check.Near (5.0, maxVal1, nameStr)

'''
Test point IsEqual.
'''
def test_DPoint3d_IsEqual():
    nameStr = ''
    point0 = DPoint3d.From (2.0, 2.0, 2.0)
    point1 = DPoint3d.From (2.0, 2.0, 2.0)
    point2 = DPoint3d.From (1.0, 1.0, 1.0)
    point3 = DPoint3d.From (0.0, 0.0, 0.0)
    point4 = DPoint3d.From (0.00001, 0.00001, 0.00001)
    tol0 = 0.01
    tol1 = -0.0001
    print ("\n Test point IsEqual")
    Check.IsTrue (point0.IsEqual (point1), nameStr)
    Check.IsTrue (not point0.IsEqual (point2), nameStr)
    Check.IsTrue (point3.IsEqual (point4, tol0), nameStr)
    Check.IsTrue (not point3.IsEqual (point4, tol1), nameStr)

'''
Test point NpcCoordinatesOf.
'''
def test_DPoint3d_NpcCoordinatesOf():
    nameStr = ''
    point0 = DPoint3d.FromZero()
    point1 = DPoint3d.From (2.0, 2.0, 2.0)
    point2 = DPoint3d.FromZero()
    point3 = DPoint3d.FromZero()
    point4 = DPoint3d.From (1.0, 1.0, 1.0)
    point5 = DPoint3d.From (0.5, 0.5, 0.5)
    point6 = DPoint3d.FromZero()
    range0 = DRange3d (point0, point1)
    point2.NpcCoordinatesOf (point0, range0)
    point3.NpcCoordinatesOf (point1, range0)
    point6.NpcCoordinatesOf (point4, range0)
    print ("\n Test point NpcCoordinatesOf")
    Check.Near (point0, point2, nameStr)
    Check.Near (point4, point3, nameStr)
    Check.Near (point5, point6, nameStr)

'''
Test point initialze by sum.
'''
def test_DPoint3d_Initialize():
    nameStr = ''
    point0 = point2 = point4 = point6 = point8 = point10 = DPoint3d.FromZero()
    point1 = DPoint3d (1.0, 2.0, 3.0)
    point3 = DPoint3d (2.0, 4.0, 6.0)
    point5 = point1
    point7 = DPoint3d.FromZero()
    point9 = DPoint3d (11.0, 16.0, 21.0)
    point11 = DPoint3d (-9.0, 8.0, 9.0)
    vector0 = DVec3d (1.0, 2.0, 3.0)
    vector1 = DVec3d (3.0, 4.0, 5.0)
    vector2 = DVec3d (-5.0, -2.0, -3.0)
    scale0 = 2.0
    scale1 = 3.0
    scale2 = 4.0
    # Initialize point by vector.
    point0.Init (vector0)
    # Initialze point by sum of a point and a vector.
    point2.SumOf (point1, vector0)
    # Initalize point by subtract of a point and a vector.
    point4.Subtract (point3, vector0)
    point5.Add (vector0)
    point6.SumOf (point7, vector0, scale0)
    point8.SumOf (point7, vector0, scale0, vector1, scale1)
    point10.SumOf (point7, vector0, scale0, vector1, scale1, vector2, scale2)
    print ("\n Test point Init")
    Check.Near (point1, point0, nameStr)
    Check.Near (point3, point2, nameStr)
    Check.Near (point1, point4, nameStr)
    Check.Near (point3, point5, nameStr)
    Check.Near (point3, point6, nameStr)
    Check.Near (point9, point8, nameStr)
    Check.Near (point11, point10, nameStr)

'''
Test point cross product.
'''
def test_DPoint3d_CrossProduct():
    nameStr = ''
    point0 = point6 = point7 = point8 = point9 = point10 = DPoint3d.FromZero()
    point1 = DPoint3d.From (1.0,  2.0,  3.0)
    point3 = DPoint3d.From (2.0,  5.0,  6.0)
    point4 = DPoint3d.From (-3.0, 0.0,  1.0)
    point5 = DPoint3d.From (0.0,  0.0,  0.0)
    c = math.sqrt (math.sqrt (910.0))
    point0.CrossProduct (point1, point3)
    point6.CrossProductToPoints (point5, point1, point3)
    cross0 = point1.CrossProductXY (point3)
    magnitude0 = point7.NormalizedCrossProduct (point1, point3)
    magnitude2 = point8.SizedCrossProduct (point1, point3, 1.0)
    magnitude3 = point9.GeometricMeanCrossProduct (point1, point3)
    point10.Scale (point4, c/magnitude3)
    print ("\n Test point CrossProduct")
    Check.Near (point4, point0, nameStr)
    Check.Near (point4, point6, nameStr)
    Check.Near (1.0, cross0, nameStr)
    magnitude1 = point4.Normalize ()
    Check.Near (point4, point7, nameStr)
    Check.Near (magnitude1, magnitude0, nameStr)
    Check.Near (point4, point8, nameStr)
    Check.Near (magnitude1, magnitude2, nameStr)
    Check.Near (magnitude1, magnitude3, nameStr)
    Check.Near (point10, point9, nameStr)

'''
Test point dot product.
'''
def test_DPoint3d_DotProduct():
    nameStr = ''
    point0 = DPoint3d.From (1.0, 2.0, 3.0)
    point1 = DPoint3d.From (2.0, 5.0, 6.0)
    point2 = DPoint3d.FromZero()
    point3 = DPoint3d.From (1.0, 3.0, 3.0)
    dot0 = point0.DotProduct (point1)
    dot1 = point0.DotProductXY (point1)
    dot2 = point0.DotProduct (2.0, 5.0, 6.0)
    length0 = point2.NormalizedDifference (point1, point0)
    length1 = point3.Normalize ()
    print ("\n Test point DotProduct")
    Check.Near (30.0, dot0, nameStr)
    Check.Near (12.0, dot1, nameStr)
    Check.Near (30.0, dot2, nameStr)
    Check.Near (length1, length0, nameStr)
    Check.Near (point3, point2, nameStr)

'''
Test point AngleTo.
'''
def test_DPoint3d_AngleTo():
    nameStr = ''
    point0 = DPoint3d.From (1.0, 0.0, 0.0)
    point1 = DPoint3d.From (0.0, 1.0, 0.0)
    point2 = DPoint3d.From (1.0, 1.0, 0.0)
    point3 = DPoint3d.From (1.0, -1.0, 0.0)
    point4 = DPoint3d.From (0.0, 0.0, 1.0)
    angle0 = point0.AngleTo (point1)
    angle1 = point0.AngleTo (point2)
    angle2 = point2.AngleTo (point0)
    angle3 = point1.SmallerUnorientedAngleTo (point3)
    angle4 = point0.AngleToXY (point1)
    angle5 = point0.AngleToXY (point2)
    angle6 = point2.AngleToXY (point0)
    angle7 = point1.SmallerUnorientedAngleToXY (point3)
    angle8 = point2.SignedAngleTo (point0, point4)
    angle9 = point0.PlanarAngleTo (point1, point4)
    angle10 = point1.PlanarAngleTo (point0, point4)
    print ("\n Test point AngleTo")
    Check.Near (math.pi/2, angle0, nameStr)
    Check.Near (math.pi/4, angle1, nameStr)
    Check.Near (math.pi/4, angle2, nameStr)
    Check.Near (math.pi/4, angle3, nameStr)
    Check.Near (math.pi/2, angle4, nameStr)
    Check.Near (math.pi/4, angle5, nameStr)
    Check.Near (-math.pi/4, angle6, nameStr)
    Check.Near (math.pi/4, angle7, nameStr)
    Check.Near (-math.pi/4, angle8, nameStr)
    Check.Near (math.pi/2, angle9, nameStr)
    Check.Near (-math.pi/2, angle10, nameStr)

'''
Test point IsVectorInCCWSector and IsVectorInCCWSector. 
Return if the test vector vector is "between" vector0 and vector1 or with CCW direction.
'''
def test_DPoint3d_IsVectorInSmallerSector():
    nameStr = ''
    vector0 = DPoint3d.From (1.0, 0.0, 0.0)
    vector1 = DPoint3d.From (0.0, 1.0, 0.0)
    vector2 = DPoint3d.From (0.5, 0.5, 0.0)
    vector3 = DPoint3d.From (-0.5, 0.5, 0.0)
    vector4 = DPoint3d.From (-0.5, -0.5, 0.0)
    vector5 = DPoint3d.From (0.5, -0.5, 0.0)
    upVector = DVec3d.From (0.0, 1.0, 0.0)
    Check.IsTrue (vector2.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue (not vector3.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue (not vector4.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue (not vector5.IsVectorInSmallerSector (vector0, vector1), nameStr)
    Check.IsTrue (not vector2.IsVectorInCCWSector (vector0, vector1, upVector), nameStr)
    Check.IsTrue (vector3.IsVectorInCCWSector (vector0, vector1, upVector), nameStr)
    Check.IsTrue (vector4.IsVectorInCCWSector (vector0, vector1, upVector), nameStr)
    Check.IsTrue (vector5.IsVectorInCCWSector (vector0, vector1, upVector), nameStr)
    
'''
Test point rotate.
'''
def test_DPoint3d_RotateXY():
    nameStr = ''
    point1 = DPoint3d.From (1.0, 0.0, 0.0)
    point2 = DPoint3d.From (0.0, 1.0, 0.0)
    point6 = DPoint3d.From (0.0, -1.0, 0.0)
    point0 = point5 = DPoint3d.FromZero()
    radian0 = math.pi/2
    radian1 = -math.pi
    point0.RotateXY (point1, radian0)
    point1.RotateXY (radian0)
    point5.RotateXY (point2, radian1)
    print ("\n Test point RotateXY")
    Check.Near (point2, point0, nameStr)
    Check.Near (point2, point1, nameStr)
    Check.Near (point6, point5, nameStr)

'''
Test point WeightedDifferenceOf which scale each point by the other's weight and subtract.
'''
def test_DPoint3d_WeightedDifferenceOf():
    nameStr = ''
    point0 = point5 = point7 = DPoint3d.FromZero()
    point1 = DPoint4d.From (5.0, 6.0, 3.0, 7.0)
    point2 = DPoint4d.From (2.0, 6.0, 3.0, 4.0)
    point3 = DPoint3d.From (6.0, -18.0, -9.0)
    point4 = DPoint4d.From (3.0, 5.0, 1.0, 2.0)
    point8 = DPoint3d.From (-11.0, -23.0, -1.0)
    point9 = DPoint3d.From (-8.0, -8.0, 2.0)
    point0.WeightedDifferenceOf (point1, point2)
    point5.WeightedDifferenceCrossProduct (point4, point1, point2)
    point7.CrossProduct (point8, point9)
    print ("\n Test point WeightedDifferenceOf")
    Check.Near (point3, point0, nameStr)
    Check.Near (point7, point5, nameStr)

'''
Test point Magnitude.
'''
def test_DPoint3d_MagnitudeSquared():
    nameStr = ''
    point0 = DPoint3d.From (6.0, -18.0, -9.0)
    point1 = DPoint3d.FromZero()
    point2 = DPoint3d.From (12.0, -36.0, -18.0)
    point3 = DPoint3d.From (11.0, -4.0, -16.0)
    point4 = DPoint3d.From (22.0, -8.0, -32.0)
    scale0 = 2.0
    magnitude0 = point0.MagnitudeSquared ()
    magnitude1 = point0.MagnitudeXY ()
    magnitude2 = point0.MagnitudeSquaredXY ()
    magnitude3 = point0.Magnitude ()
    point1.Scale (point0, scale0)
    point3.Scale (scale0)
    print ("\n Test point MagnitudeSquared")
    Check.Near (441.0, magnitude0, nameStr)
    Check.Near (math.sqrt (360.0), magnitude1, nameStr)
    Check.Near (360.0, magnitude2, nameStr)
    Check.Near (math.sqrt (441.0), magnitude3, nameStr)
    Check.Near (point2, point1, nameStr)
    Check.Near (point4, point3, nameStr)

'''
Test point UnitPerpendicularXY.
'''
def test_DPoint3d_UnitPerpendicularXY():
    nameStr = ''
    point0 = DPoint3d.FromZero()
    point1 = DPoint3d.From (2.0, 0.0, 0.0)
    point2 = DPoint3d.From (0.0, 1.0, 0.0)
    Check.IsTrue (point0.UnitPerpendicularXY (point1), nameStr)
    Check.Near (point2, point0, nameStr)

'''
Test point Negate.
'''
def test_DPoint3d_Negate():
    nameStr = ''
    point0 = point3 = DPoint3d.FromZero()
    point1 = DPoint3d.From (2.0, -5.0, 1.0)
    point2 = DPoint3d.From (-2.0, 5.0, -1.0)
    point0.Negate (point1)
    print ("\n Test point Negate")
    Check.Near (point2, point0, nameStr)
    point2.Negate ()
    Check.Near (point1, point2, nameStr)
    length0 = point3.Normalize (point1)
    length1 = point3.Magnitude ()
    f = 1.0 / (math.sqrt (30.0))
    point4 = DPoint3d.From (2.0 * f, -5.0 * f, 1.0 * f)
    Check.Near (math.sqrt (30.0), length0, nameStr)
    Check.Near (1.0, length1, nameStr)
    Check.Near (point4, point3, nameStr)
    
'''
Test point ScaleToLength which scales a vector to specified length.
'''
def test_DPoint3d_ScaleToLength():
    nameStr = ''
    point0 = DPoint3d.FromZero()
    point1 = DPoint3d.From (1.0, 0.0, 0.0)
    point2 = DPoint3d.From (2.0, 0.0, 0.0)
    point3 = DPoint3d.From (1.0, 0.0, 0.0)
    scale0 = 2.0
    length0 = point0.ScaleToLength (point1, scale0)
    print ("\n Test point ScaleToLength")
    Check.Near (point2, point0, nameStr)
    Check.Near (1.0, length0, nameStr)
    length1 = point1.ScaleToLength (scale0)
    Check.Near (point2, point1, nameStr)
    Check.Near (1.0, length1, nameStr)
    length2 = point2.Normalize ()
    Check.Near (2.0, length2, nameStr)
    Check.Near (point3, point2, nameStr)

'''
Test point IsParallelTo.
'''
def test_DPoint_IsParallelTo():
    nameStr = ''
    point0 = DPoint3d.From (2.0, 2.0, 2.0)
    point1 = DPoint3d.From (1.0, 1.0, 1.0)
    point2 = DPoint3d.From (1.0, 0.0, 0.0)
    point3 = DPoint3d.From (0.0, 1.0, 0.0)
    print ("\n Test point IsParallelTo")
    Check.IsTrue (point0.IsParallelTo (point1), nameStr)
    Check.IsTrue (not point0.IsParallelTo (point2), nameStr)
    Check.IsTrue (point2.IsPerpendicularTo (point3), nameStr)
    Check.IsTrue (not point2.IsPerpendicularTo (point1), nameStr)

'''
Test point SafeDivide which try to divide each component of a vector by a scalar. If the denominator
near zero compared to any numerator component, return the original.
'''
def test_DPoint3d_SafeDivide():
    nameStr = ''
    point0 = point3 = DPoint3d.FromZero()
    point1 = DPoint3d.From (1.0, 1.0, 1.0)
    point2 = DPoint3d.From (0.5, 0.5, 0.5)
    point5 = DPoint3d.From (2.0, 3.0, 4.0)
    denominator0 = 0.0
    denominator1 = 2.0
    print ("\n Test point SafeDivide")
    Check.IsTrue (not point0.SafeDivide (point1, denominator0), nameStr)
    Check.IsTrue (point3.SafeDivide (point1, denominator1), nameStr)
    product = point2.TripleProduct (point1, point5)
    Check.Near (point2, point3, nameStr)
    Check.Near (0.0, product, nameStr)


'''
Test point Subtract.
'''
def test_DPoint3d_Subtract():
    nameStr = ''
    point0 = DPoint3d.From (1.0, 1.0, 1.0)
    point1 = DPoint3d.From (0.5, 0.5, 0.5)
    point2 = point4 = point7 = point11 = point15 = DPoint3d.FromZero()
    point3 = DPoint3d.From (0.0, 0.0, 0.0)
    point5 = DPoint3d.From (1.5, 1.5, 1.5)
    point6 = DPoint3d.From (2.0, 3.0, 4.0)
    point8 = DPoint3d.From (5.5, 7.5, 9.5)
    point9 = DPoint3d.From (8.0, 7.0, 5.0)
    point10 = DPoint3d.From (37.5, 35.5, 29.5)
    point12 = DPoint3d.From (5.0, 2.0, 1.0)
    point13 = DPoint3d.From (2.0, 8.0, 4.0)
    point14 = DPoint3d.From (7.0, 10.0, 5.0)
    point16 = DPoint3d.From (9.0, 18.0, 9.0)
    scale0 = 3.0
    scale1 = 2.0
    scale2 = 4.0
    point0.Subtract (point1)
    point2.DifferenceOf (point0, point1)
    point4.SumOf (point3, point1, scale0)
    point7.SumOf (point3, point1, scale0, point6, scale1)
    point11.SumOf (point3, point1, scale0, point6, scale1, point9, scale2)
    point12.Add (point13)
    point15.SumOf (point12, point13)
    print ("\n Test point Subtract")
    Check.Near (point1, point0, nameStr)
    Check.Near (point3, point2, nameStr)
    Check.Near (point5, point4, nameStr)
    Check.Near (point8, point7, nameStr)
    Check.Near (point10, point11, nameStr)
    Check.Near (point14, point12, nameStr)
    Check.Near (point16, point15, nameStr)

'''
Test point MultiplyArrayByScales.
'''
def test_DPoint3d_MultiplyArrayByScales():
    nameStr = ''
    point0 = DPoint3dArray() 
    point0.append (DPoint3d.FromZero())
    point0.append (DPoint3d.FromZero()) 
    point1 = DPoint3dArray()
    point1.append (DPoint3d.From (0.5, 0.5, 0.5))
    point1.append (DPoint3d.From (2.0, 3.0, 4.0))
    point2 = DPoint3d.From (1.5, 1.5, 1.5)
    point3 = DPoint3d.From (6.0, 9.0, 12.0)
    scale0 = DoubleArray()
    scale0.append (3.0)
    scale0.append (3.0)
    DPoint3d.MultiplyArrayByScales (point0, point1, scale0)
    print ("\n Test point MultiplyArrayByScales")
    Check.Near (point2, point0[0], nameStr)
    Check.Near (point3, point0[1], nameStr)

'''
Test point DivideArrayByScales.
'''
def test_DPoint3d_DivideArrayByScales():
    nameStr = ''
    point0 = DPoint3dArray() 
    point1 = DPoint3dArray()
    point0.append (DPoint3d.FromZero())
    point0.append (DPoint3d.FromZero()) 
    point1.append (DPoint3d.From (1.5, 1.5, 1.5))
    point1.append (DPoint3d.From (6.0, 9.0, 12.0))
    point2 = DPoint3d.From (0.5, 0.5, 0.5)
    point3 = DPoint3d.From (2.0, 3.0, 4.0)
    scale0 = DoubleArray()
    scale0.append (3.0)
    scale0.append (3.0)
    DPoint3d.DivideArrayByScales (point0, point1, scale0)
    print ("\n Test point DivideArrayByScales")
    Check.Near (point2, point0[0], nameStr)
    Check.Near (point3, point0[1], nameStr)

'''
Test point initialization by FromProduct.
'''
def test_DPoint3d_FromProduct():
    nameStr = ''
    transform0 = Transform ()
    point0 = DPoint3d.FromProduct (transform0, 2.0, 3.0, 4.0)
    point1 = DPoint3d.From (2.0, 3.0, 4.0)
    point2 = DPoint3d.From (0.0, 0.0, 0.0)
    matrix0 = RotMatrix ()
    point3 = DPoint3d.FromProduct (point2, matrix0, 2.0, 3.0, 4.0)
    point4 = DPoint3d.FromProduct (transform0, point1)
    print ("\n Test point FromProduct")
    Check.Near (point1, point0, nameStr)
    Check.Near (point1, point3, nameStr)
    Check.Near (point1, point4, nameStr)

'''
Test point initialization by FromInterpolate.
'''
def test_DPoint3d_FromInterpolate():
    nameStr = ''
    point0 = DPoint3d.From (2.0, 3.0, 4.0)
    point1 = DPoint3d.From (5.0, 8.0, 6.0)
    fraction = 0.5
    point2 = DPoint3d.FromInterpolate (point0, fraction, point1)
    point3 = DPoint3d.From (3.5, 5.5, 5.0)
    print ("\n Test point FromInterpolate")
    Check.Near (point3, point2, nameStr)

'''
Test point Sumof.
'''
def test_DPoint3d_Sumof_Variants():
    nameStr = ''
    origin = DPoint3d.From (1.0, 2.0, 3.0)
    xVec = DVec3d (4.0, 7.0, 8.0)
    yVec = DVec3d (-2.0, 3.0,1.5)
    zVec = DVec3d (1.3, 2.34, -0.4)
    ax = 2
    ay = 3
    az = 0.12312
    sum1    = DPoint3d.FromSumOf (origin, xVec, ax)
    sum2    = DPoint3d.FromSumOf (origin, xVec, ax, yVec, ay)
    sum3    = DPoint3d.FromSumOf (origin, xVec, ax, yVec, ay, zVec, az)
    sum12   = DPoint3d.FromSumOf (sum2, zVec, az)
    sum2a   = DPoint3d.FromSumOf (sum1, yVec, ay)
    print ("\n Test DPoint3d Sumof_Variants")
    Check.Near (sum3, sum12, "FromSumOf")
    Check.Near (sum2, sum2a, "FromSumOf")
    alpha0  = DPoint3d.FromScale (xVec, ax)
    beta0   = DPoint3d.FromSumOf (xVec, ax, yVec, ay)
    gamma0  = DPoint3d.FromSumOf (xVec, ax, yVec, ay, zVec, az)
    zeta0   = DPoint3d.FromScale (zVec, az)
    mu0     = DPoint3d.FromSumOf (beta0, 1.0, zeta0, 1.0)
    Check.Near (mu0, gamma0, "PointType::FromSumOf")
    alpha1  = DVec3d.FromScale (xVec, ax)
    beta1   = DVec3d.FromSumOf (xVec, ax, yVec, ay)
    gamma1  = DVec3d.FromSumOf (xVec, ax, yVec, ay, zVec, az)
    mu1     = DVec3d.FromSumOf (beta1, 1.0, zVec, az)
    Check.Near (mu1, gamma1, "VectorType::FromSumOf")
    Check.Near (alpha0, alpha1, "FromScale as point, vector")
    Check.Near (beta0, beta1, "FromScale as point, vector")
    Check.Near (gamma0, gamma1, "FromScale as point, vector")
    target = DPoint3d.FromSumOf (origin, xVec, 1.0)  
    for f in numpy.arange(-0.25, 1.5, 0.25):
        point0 = DPoint3d.FromSumOf (origin, xVec, f)
        point1 = DPoint3d.FromInterpolate (origin, f, target)
        Check.Near (point0, point1, "Interpolation vs direct sum")

'''
Get point from plane fractions.
'''
def PlaneFractionsToPoint (planeOrigin, planeXTarget, planeYTarget, planeXFraction, planeYFraction):
    planeXDirection = DVec3d (planeOrigin, planeXTarget)
    planeYDirection = DVec3d (planeOrigin, planeYTarget)
    return DPoint3d.FromSumOf (planeOrigin, planeXDirection, planeXFraction, planeYDirection, planeYFraction)

'''
Check point and plane intersection.
'''
def RayBy2PointsIntersectPlaneBy3Points (rayOrigin, rayTarget, planeOrigin, planeXTarget, planeYTarget, rayFraction, planeXFraction, planeYFraction):
    rayDirection = DVec3d (rayOrigin, rayTarget)
    planeXDirection = DVec3d (planeOrigin, planeXTarget)
    planeYDirection = DVec3d (planeOrigin, planeYTarget)
    matrix = RotMatrix.FromColumnVectors (planeXDirection, planeYDirection, rayDirection)
    rhs = DVec3d (planeOrigin, rayOrigin)
    stLambda = DVec3d (0.0, 0.0, 0.0)
    if matrix.Solve (stLambda, rhs):
        planeXFraction = stLambda.x
        planeYFraction = stLambda.y
        rayFraction    = -stLambda.z
        return True
    return False

'''
Test point RayPlaneExample.
'''
def test_DPoint3d_RayPlaneExample():
    rayOrigin = DPoint3d.From (1.0, 2.0, 3.0)
    rayTarget = DPoint3d.From (5.0, 2.0, 9.0)
    planeOrigin = DPoint3d.From (10.0, 12.0, 0.0)
    planeXTarget = DPoint3d.From (10.0, 0.0, 0.0)
    planeYTarget = DPoint3d.From (10.0, 12.0, 20.0)
    rayFraction = planeXFraction = planeYFraction = 0.0
    print ("\n Test point RayPlaneExample")
    Check.IsTrue (RayBy2PointsIntersectPlaneBy3Points (rayOrigin, rayTarget, planeOrigin, planeXTarget, planeYTarget, rayFraction, planeXFraction, planeYFraction), "ray plane intersection")
    planePoint = PlaneFractionsToPoint (planeOrigin, planeXTarget, planeYTarget, planeXFraction, planeYFraction)
    rayPoint = DPoint3d.FromInterpolate (rayOrigin, rayFraction, rayTarget)
    Check.Near (rayPoint, planePoint, "rayPlane intersection resolved")

'''
Test point4d Interpolate.
'''
def test_DPoint4d_Interpolate():
    pointA = DPoint4d.From (1.0, 2.0, 3.0, 1.25)
    pointB = DPoint4d.From (7.0, 5.0, 11.0, 0.75)
    deltaAB = deltaAC = pointC = pointD = DPoint4d.From (0.0, 0.0, 0.0, 0.0)
    for f in numpy.arange (-2.0, 3.0, 0.25):
        pointC.Interpolate (pointA, f, pointB)
        pointD.Interpolate (pointB, 1.0 - f, pointA)
        Check.Near (pointC, pointD, "Reverse interpolation")
        deltaAB.DifferenceOf (pointB, pointA)
        deltaAC.DifferenceOf (pointC, pointA)
        Check.Near (deltaAC.MagnitudeXYZW(), math.fabs (f) * deltaAB.MagnitudeXYZW(), "interpolated distance")