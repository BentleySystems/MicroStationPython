import os
import pytest
import math
import numpy

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyGeomTest import *

'''
Test point MagnitudeSquard, CrossProduct, DotProduct, DistanceSquared etc.
'''
def test_DPoint2d_MagnitudeSquared ():
    nameStr = ''
    point0 = DPoint2d.From (0.0, 1.0)
    point1 = DPoint2d.From (1.0, 1.0)
    point2 = DPoint2d.From (0.0, 0.0)
    point3 = DPoint2d()
    point4 = DPoint2d.From (2.0, 2.0)
    point5 = DPoint2d()
    point6 = DPoint2d.From (0.0, 0.5)
    point7 = DPoint2d()
    point8 = DPoint2d.From (1.0, 2.0)
    point9 = DPoint2d.From (0.0, 1.0)
    point10 = DPoint2d.From (1.0, 1.0)
    point11 = DPoint2d.From (1.0, 0.0)
    point12 = DPoint2d()
    point13 = DPoint2d.From (-1.0, 0.0)
    point14 = DPoint2d()
    scale = 2.0
    s = 0.5
    # Calculate squared magnitude of vector.
    magnitudeSqr0 = point0.MagnitudeSquared()
    # Calculate cross product of 2 points.
    cross0 = point0.CrossProduct (point1)
    # Calculate cross product to 2 points.
    cross1 = point2.CrossProductToPoints (point0, point1)
    # Calculate dot product.
    dot0 = point0.DotProduct (point1)
    # Calculate dot product to 2 points.
    dot1 = point2.DotProductToPoints (point0, point1)
    # Calculate squared distance of 2 points.
    distanceSqr0 = point0.DistanceSquared (point1)
    # Calculate scaled sum of 2 points.
    point3.SumOf (point2, point1, scale)
    # Compute the point at an interpolated (fractional) position
    # between a start and end point.
    point5.Interpolate (point2, s, point0)
    # Get a point from sum of 2 points.
    point7.SumOf (point0, point1)
    # Add a point.
    point9.Add (point1)
    # Substract a point.
    point10.Subtract (point0)
    # Calculate the difference of 2 points.
    point12.DifferenceOf (point0, point1)
    # Scale a point.
    point14.Scale (point1, scale)
    Check.Near (1.0, magnitudeSqr0, nameStr)
    Check.Near (-1.0, cross0, nameStr)
    Check.Near (-1.0, cross1, nameStr)
    Check.Near (1.0, dot0, nameStr)
    Check.Near (1.0, dot1, nameStr)
    Check.Near (1.0, distanceSqr0, nameStr)
    Check.Near (point4, point3, nameStr)
    Check.Near (point6, point5, nameStr)
    Check.Near (point8, point7, nameStr)
    Check.Near (point8, point9, nameStr)
    Check.Near (point11, point10, nameStr)
    Check.Near (point13, point12, nameStr)
    Check.Near (point4, point14, nameStr)

'''
Test point normalize.
'''
def test_DPoint2d_Normalize():
    nameStr = ''
    point0 = DPoint2d.From (0.0, 0.0)
    point1 = DPoint2d.From (-1.0, 2.0)
    point5 = DPoint2d.From (-1.0, 2.0)
    point2 = DPoint2d.From (-1.0 / math.sqrt(5.0), 2.0 / math.sqrt(5.0))
    point3 = DPoint2d()
    point4 = DPoint2d()
    magnitude0 = point0.Normalize()
    magnitude1 = point1.Normalize()
    magnitude2 = point3.Normalize (point0)
    magnitude3 = point4.Normalize (point5)
    Check.Near (0.0, magnitude0, nameStr)
    Check.Near (math.sqrt (5.0), magnitude1, nameStr)
    Check.Near (point2, point1, nameStr)
    Check.Near (0.0, magnitude2, nameStr)
    Check.Near (math.sqrt (5.0), magnitude3, nameStr)
    Check.Near (point2, point4, nameStr)

'''
Test point rotate.
'''
def test_DPoint2d_Rotate90():
    nameStr = ''
    point0 = DPoint2d()
    point1 = DPoint2d.From (1.0, 0.0)
    point2 = DPoint2d.From (0.0, 1.0)
    point4 = DPoint2d()
    point5 = DPoint2d()
    point6 = DPoint2d.From (0.0, -1.0)
    radian0 = math.pi/2
    radian1 = -math.pi/2
    point0.Rotate90 (point1)
    point4.RotateCCW (point1, radian0)
    point5.RotateCCW (point1, radian1)
    Check.Near (point2, point0, nameStr)
    Check.Near (point2, point4, nameStr)
    Check.Near (point6, point5, nameStr)

'''
Test point Zero and One.
'''
def test_DPoint2d_Zero():
    nameStr = ''
    point0 = DPoint2d.From (12.9, -4.3)
    point1 = DPoint2d.From (0.0, 0.0)
    point2 = DPoint2d.From (1.0, 1.0)
    point3 = DPoint2d.From (-54.0, 3.6)
    point0.Zero()
    point3.One()
    Check.Near (point1, point0, nameStr)
    Check.Near (point2, point3, nameStr)

'''
Test point set components.
'''
def test_DPoint2d_SetComponents():
    nameStr = ''
    point0 = DPoint2d()
    point1 = DPoint2d.From (2.0, -7.9)
    point2 = DPoint2d.From (4.0, -7.9)
    point3 = DPoint2d.From (2.0, 9.3)
    point4 = DPoint2d.From (-5.1, -7.9)
    xx = 2.0
    yy = -7.9
    index0 = 0
    index1 = 1
    index2 = 2
    xCoord = 0.0
    yCoord = 0.0
    point0.Init (xx, yy)
    point2.SetComponent (xx, index0)
    point3.SetComponent (yy, index1)
    point4.SetComponent (xx, index2)
    component0 = point1.GetComponent (index0)
    component1 = point1.GetComponent (index1)
    component2 = point1.GetComponent (index2)
    (xCoord, yCoord) = point1.GetComponents ()
    Check.Near (point1, point0, nameStr)
    Check.Near (point1, point2, nameStr)
    Check.Near (point1, point3, nameStr)
    Check.Near (point1, point4, nameStr)
    Check.Near (xx, component0, nameStr)
    Check.Near (yy, component1, nameStr)
    Check.Near (xx, component2, nameStr)
    Check.Near (xx, xCoord, nameStr)
    Check.Near (yy, yCoord, nameStr)


'''
Test point SumOf.
'''
def test_DPoint2d_SumOf():
    nameStr = ''
    point0 = DPoint2d()
    point1 = DPoint2d.From (0.0, 0.0)
    point2 = DPoint2d.From (2.0, -7.9)
    point3 = DPoint2d.From (4.0, -7.9)
    point4 = DPoint2d.From (8.0, 7.9)
    point5 = DPoint2d.From (3.0, 2.0)
    point6 = DPoint2d()
    point7 = DPoint2d.From (-5.0, 9.9)
    scale0 = 2.0
    scale1 = -3.0
    scale2 = 1.0
    point0.SumOf (point1, point2, scale0, point3, scale1)
    point6.SumOf (point1, point2, scale0, point3, scale1, point5, scale2)
    Check.Near (point4, point0, nameStr)
    Check.Near (point7, point6, nameStr)

'''
Test point NormalizedDifferenceOf.
'''
def test_DPoint2d_NormalizedDifferenceOf():
    nameStr = ''
    point0 = DPoint2d()
    point1 = DPoint2d.From (2.0, -7.9)
    point2 = DPoint2d.From (4.0, -7.9)
    point3 = DPoint2d.From (-1.0, 0.0)
    magnitude0 = point0.NormalizedDifferenceOf (point1, point2)
    magnitude1 = point0.Magnitude ()
    Check.Near (2.0, magnitude0, nameStr)
    Check.Near (1.0, magnitude1, nameStr)
    Check.Near (point3, point0, nameStr)

'''
Test point AngleTo.
'''
def test_DPoint2d_AngleTo():
    nameStr = ''
    point0 = DPoint2d.From (1.0, 0.0)
    point1 = DPoint2d.From (0.0, 1.0)
    point2 = DPoint2d.From (1.0, 1.0)
    angle0 = point0.AngleTo (point1)
    angle1 = point0.AngleTo (point2)
    angle2 = point2.AngleTo (point0)
    Check.Near (math.pi/2, angle0, nameStr)
    Check.Near (math.pi/4, angle1, nameStr)
    Check.Near (-math.pi/4, angle2, nameStr)

'''
Test point Distance.
'''
def test_DPoint2d_Distance():
    nameStr = ''
    point0 = DPoint2d.From (1.0, 0.0)
    point1 = DPoint2d.From (2.0, 0.0)
    point2 = DPoint2d.From (-2.0, 0.0)
    point3 = DPoint2d()
    distance0 = point0.Distance (point1)
    distance1 = point0.Distance (point2)
    magnitude0 = point0.Magnitude ()
    magnitude1 = point2.Magnitude ()
    point3.Negate (point2)
    Check.Near (1.0, distance0, nameStr)
    Check.Near (3.0, distance1, nameStr)
    Check.Near (1.0, magnitude0, nameStr)
    Check.Near (2.0, magnitude1, nameStr)
    Check.Near (point1, point3, nameStr)

'''
Test point IsParallelTo.
'''
def test_DPoint2d_IsParallelTo():
    nameStr = ''
    point0 = DPoint2d.From (2.0, 2.0)
    point1 = DPoint2d.From (1.0, 1.0)
    point2 = DPoint2d.From (1.0, 0.0)
    point3 = DPoint2d.From (0.0, 1.0)
    Check.IsTrue (point0.IsParallelTo (point1), nameStr)
    Check.IsTrue (not point0.IsParallelTo (point2), nameStr)
    Check.IsTrue (point2.IsPerpendicularTo (point3), nameStr)
    Check.IsTrue (not point2.IsPerpendicularTo (point1), nameStr)

'''
Test point IsEqual.
'''
def test_DPoint2d_IsEqual():
    nameStr = ''
    point0 = DPoint2d.From (2.0, 2.0)
    point1 = DPoint2d.From (2.0, 2.0)
    point2 = DPoint2d.From (1.0, 1.0)
    point3 = DPoint2d.From (0.0, 0.0)
    point4 = DPoint2d.From (0.00001, 0.00001)
    tol0 = 0.01
    tol1 = -0.0001
    Check.IsTrue (point0.IsEqual (point1), nameStr)
    Check.IsTrue (not point0.IsEqual (point2), nameStr)
    Check.IsTrue (point3.IsEqual (point4, tol0), nameStr)
    Check.IsTrue (not point3.IsEqual (point4, tol1), nameStr)

'''
Test point MaxAbs.
'''
def test_DPoint2d_MaxAbs():
    nameStr = ''
    point0 = DPoint2d.From (-2.0, -15.0)
    point1 = DPoint2d.From (4.0, -5.0)
    maxVal0 = point0.MaxAbs ()
    maxVal1 = point1.MaxAbs ()
    Check.Near (15.0, maxVal0, nameStr)
    Check.Near (5.0, maxVal1, nameStr)

'''
Test point IsDisconnect.
'''
def test_DPoint2d_IsDisconnect():
    nameStr = ''
    point0 = DPoint2d()
    point1 = DPoint2d.From (-2.0, -15.0)
    point0.InitDisconnect ()
    Check.IsTrue (point0.IsDisconnect (), nameStr)
    Check.IsTrue (not point1.IsDisconnect (), nameStr)

'''
Determine the sign of a number.
'''
def signOf (d):
    if d < 0.0:
       return -1.0
    else:
       return 1.0

'''
Test interpolate.
'''
def TestInterpolate (pointA, pointB):
    nameStr = ''
    errors = 0
    pointA = DPoint2d.From (1,3)
    pointB = DPoint2d.From (5,11)
    vectorAB = DVec2d (pointA, pointB)
    dotUU = vectorAB.DotProduct (vectorAB)
    dAB = pointA.Distance (pointB)
    for f in numpy.arange(-0.75, 1.8, 0.25):
        pointC = DPoint2d.FromInterpolate (pointA, f, pointB)
        vectorAC = DVec2d (pointA, pointC)
        dotUV = vectorAB.DotProduct (vectorAC)
        g = dotUV/dotUU;
        if abs(f-g) > 1.0e-11:
            errors += 1
        dAC = pointA.Distance (pointC)
        dBC = pointB.Distance (pointC)
        e = signOf (f) * dAC + signOf (1.0 - f) * dBC
        if abs(e - dAB) > 1.0e-11:
            errors += 1
        pointD = DPoint2d()
        pointD.Interpolate (pointA, f, pointB)
        if not pointC.AlmostEqual (pointD):
            errors += 1
    return errors == 0

'''
Test point interpolate.
'''
def test_DPoint2d_Interpolate():
    nameStr = ''
    Check.IsTrue (TestInterpolate (DPoint2d.From (1,3), DPoint2d.From (5,11)), nameStr)






