import os
import pytest
import math
import numpy
import copy

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyGeomTest import *

'''
Test vector DirectInitialization.
'''
def test_DVec3d_DirectInitialization():
    nameStr = ''
    vector0 = DVec3d()
    vector0.Init (1, 2, 3)
    Check.Near (vector0.x, 1.0, nameStr)
    Check.Near (vector0.y, 2.0, nameStr)
    Check.Near (vector0.z, 3.0, nameStr)

'''
Test vector DotProduct.
'''
def test_DVec3d_DotProduct():
    nameStr = ''
    vector0 = DVec3d()
    vector1 = DVec3d()
    vector0.Init (1, 2, 3)
    vector1.Init (5, 7, 11)
    Check.Near (vector0.DotProduct (vector1), vector0.DotProduct (vector1.x, vector1.y, vector1.z), nameStr)
    Check.Near (vector0.DotProduct (vector1), vector1.DotProduct (vector0), nameStr)

'''
Test vector FromXYZ.
'''
def test_DVec3d_FromXYZ():
    nameStr = ''
    objInit = DVec3d()
    x = 2.3
    y = 3.4
    z = 4.5
    objInit.Init (x, y, z)
    objFromXYZ = DVec3d.From (x, y, z)
    Check.Near (objInit.x, objFromXYZ.x, nameStr)
    Check.Near (objInit.y, objFromXYZ.y, nameStr)
    Check.Near (objInit.z, objFromXYZ.z, nameStr)

'''
Test vector FromPoint.
'''
def test_DVec3d_FromPoint():
    nameStr = ''
    objInit = DVec3d()
    x = 2.3
    y = 3.4
    z = 4.5
    point = DVec3d.From (x, y, z)
    objInit.Init (point)
    objFromPoint = DVec3d.From(point)
    Check.Near (objInit.x, objFromPoint.x, nameStr)
    Check.Near (objInit.y, objFromPoint.y, nameStr)
    Check.Near (objInit.z, objFromPoint.z, nameStr)
    Check.Near (objInit.x, point.x, nameStr)
    Check.Near (objInit.y, point.y, nameStr)
    Check.Near (objInit.z, point.z, nameStr)

'''
Test vector FromXY.
'''
def test_DVec3d_FromXY():
    nameStr = ''
    objInit = DVec3d()
    x = 2.3
    y = 3.4
    objInit.Init (x, y)
    objFromXY = DVec3d.From (x, y)
    Check.Near (objInit.x, objFromXY.x, nameStr)
    Check.Near (objInit.y, objFromXY.y, nameStr)
    Check.Near (objInit.z, 0.0, nameStr)
    Check.Near (objInit.x, x, nameStr)
    Check.Near (objInit.y, y, nameStr)


'''
Test vector FromXYAngleAndMagnitude.
'''
def test_DVec3d_FromXYAngleAndMagnitude():
    nameStr = ''
    objInit = DVec3d()
    theta = math.pi
    magnitude = 12
    objInit.InitFromXYAngleAndMagnitude (theta, magnitude)
    objFromXYAngleAndMagnitude = DVec3d.FromXYAngleAndMagnitude (theta, magnitude)
    Check.Near (objInit.x, objFromXYAngleAndMagnitude.x, nameStr)
    Check.Near (objInit.y, objFromXYAngleAndMagnitude.y, nameStr)
    Check.Near (objInit.z, 0.0, nameStr)
    Check.Near (objFromXYAngleAndMagnitude.z, 0.0, nameStr)
    Check.Near (objInit.x, 12 * math.cos(theta), nameStr)
    Check.Near (objInit.y, 12 * math.sin(theta), nameStr)


'''
Test vector ConstructByMatrixAndTransformAccess.
'''
def test_DVec3d_ConstructByMatrixAndTransformAccess():
    nameStr = ''
    matrix = RotMatrix.FromRowValues (
                1,2,3,
                5,7,11,
                13,17,19
                )
    translationAsPoint = DPoint3d.From (23, 27, 29)
    transform = Transform.From (matrix, translationAsPoint)
    translationAsVector = DVec3d.FromTranslation (transform)
    Check.Near (translationAsPoint, translationAsVector, nameStr)
    mag = [math.sqrt (1 * 1 + 5 * 5 + 13 * 13),
           math.sqrt (2 * 2 + 7 * 7 + 17 * 17),
           math.sqrt (3 * 3 + 11 * 11 + 19 * 19)]
    vectorQ = DVec3d.From (0.3, 1.2, 5.3)
    for j in numpy.arange (-1, 3, 1):
        for i in numpy.arange (0, 3, 1):
            k = 3 * j + i
            Check.Int (i, Angle.Cyclic3dAxis (k), nameStr)
            Check.Near (DVec3d.FromMatrixColumn (transform, i), DVec3d.FromMatrixColumn (transform,k), nameStr)
            Check.Near (DVec3d.FromMatrixRow (transform, i), DVec3d.FromMatrixRow (transform, k), nameStr)
            Check.Near (DVec3d.FromColumn (matrix, i), DVec3d.FromColumn (matrix, k), nameStr)
            Check.Near (DVec3d.FromRow (matrix, i), DVec3d.FromRow (matrix, k), nameStr)
            getRow = DVec3d()
            getCol = DVec3d()
            getCol.InitFromColumn (matrix, k)
            getRow.InitFromRow (matrix, k)
            Check.Near (DVec3d.FromColumn (matrix, i), getCol, nameStr)
            Check.Near (DVec3d.FromRow (matrix, i), getRow, nameStr)
            Check.Near (getRow.DotProduct (vectorQ), vectorQ.DotProductRow (matrix, k), nameStr)
            Check.Near (getCol.DotProduct (vectorQ), vectorQ.DotProductColumn (matrix, k), nameStr)
            Check.Near (getRow.DotProduct (vectorQ), vectorQ.DotProductMatrixRow (transform, k), nameStr)
            Check.Near (getCol.DotProduct (vectorQ), vectorQ.DotProductMatrixColumn (transform, k), nameStr)
            Check.Near (DVec3d.FromColumn (matrix,i), DVec3d.FromMatrixColumn (transform, k), nameStr)
            Check.Near (DVec3d.FromRow (matrix,i), DVec3d.FromMatrixRow (transform, k), nameStr)
    for iA in numpy.arange (0, 3, 1):
        for iB in numpy.arange (0, 3, 1):
            vectorA = DVec3d.FromColumn (matrix, iA)
            vectorB = DVec3d.FromColumn (matrix, iB)
            Check.Near (mag[iA], vectorA.Magnitude(), nameStr)
            Check.Near (mag[iB], vectorB.Magnitude(), nameStr)
            vectorAB0 = DVec3d.FromCrossProduct (vectorA, vectorB)
            vectorAB1 = DVec3d.FromColumnCrossProduct (matrix, iA, iB)
            vectorAB2 = DVec3d.FromMatrixColumnCrossProduct (transform, iA, iB)
            Check.Near (vectorAB0, vectorAB1, nameStr)
            Check.Near (vectorAB0, vectorAB2, nameStr)
            if (iA == iB):
                Check.Near (0.0, vectorAB0.MaxAbs(), nameStr)
            else:
                Check.Near (0.0, vectorAB0.DotProduct (vectorA), nameStr)
                Check.Near (0.0, vectorAB0.DotProduct (vectorB), nameStr)
                a = mag[iA] * mag[iB] * math.sin(vectorA.AngleTo (vectorB))
                b = vectorAB0.Magnitude()
                Check.Near (a, b, nameStr)

'''
Test cross product and dot product.
'''
def TestProducts (vector0, vector1):
    nameStr = ''
    matrix = RotMatrix()
    transform = Transform()
    length0 = vector0.Magnitude()
    length1 = vector1.Magnitude()
    cross = DVec3d.FromCrossProduct (vector0, vector1)
    Check.NearZero (cross.DotProduct (vector0), nameStr)
    Check.NearZero (cross.DotProduct (vector1), nameStr)
    theta = vector0.AngleTo (vector1)
    Check.Near (length0 * length1 * math.sin (theta), cross.Magnitude(), nameStr)
    Check.Near (length0 * length1 * math.cos (theta), vector0.DotProduct (vector1), nameStr)
    Check.Near (cross, DVec3d.FromCrossProduct (vector0.x, vector0.y, vector0.z,
                                                vector1.x, vector1.y, vector1.z), nameStr)
    matrix.SetColumn (vector0, 0)
    matrix.SetColumn (vector1, 1)
    matrix.SetColumn (cross, 2)
    transform.InitFrom (matrix)
    M01 = DVec3d.FromColumnCrossProduct (matrix, 0, 1)
    T01 = DVec3d.FromMatrixColumnCrossProduct (transform, 0, 1)
    Check.Near (cross, M01, nameStr)
    Check.Near (cross, T01, nameStr)
    Check.Near (DVec3d.FromColumnCrossProduct (matrix, 0,2),
                DVec3d.FromMatrixColumnCrossProduct (transform, 0, 2), nameStr)
    Check.Near (DVec3d.FromColumnCrossProduct (matrix, 1,2),
                DVec3d.FromMatrixColumnCrossProduct (transform, 1, 2), nameStr)
    dot = vector0.DotProduct (vector1)
    Check.Near (dot, vector0.DotProduct (vector1.x, vector1.y, vector1.z), nameStr)
    Check.Near (dot, vector1.DotProductColumn (matrix, 0), nameStr)
    
    point0 = vector0
    point1 = vector1
    Check.Near (dot, vector0.DotProduct (point1), nameStr)
    Check.Near (dot - vector0.z * vector1.z, vector0.DotProductXY (vector1), nameStr)
    W00 = DVec3d()
    W01 = DVec3d()
    W10 = DVec3d()
    W00.CrossProduct (vector0, vector1)
    W01.CrossProduct (vector0, point1)
    W10.CrossProduct (point0, vector1)
    Check.Near (cross, W00, nameStr)
    Check.Near (cross, W01, nameStr)
    Check.Near (cross, W10, nameStr)

    pointA = DPoint3d()
    pointA0 = DPoint3d()
    pointA1 = DPoint3d()
    pointA.Init (2.3, 5.4, 0.99923)
    pointA0.SumOf (pointA, vector0)
    pointA1.SumOf (pointA, vector1)
    crossToPoints = DVec3d()
    crossToPoints.CrossProductToPoints (pointA, pointA0, pointA1)
    Check.Near (cross, crossToPoints, nameStr)
    Check.Near (cross.z, vector0.CrossProductXY (vector1), nameStr)

    cross1 = DVec3d()
    crossAlpha = DVec3d()
    crossM = DVec3d()
    alpha = 2.19090
    cross1.NormalizedCrossProduct (vector0, vector1)
    crossAlpha.SizedCrossProduct (vector0, vector1, alpha)
    crossM.GeometricMeanCrossProduct (vector0, vector1)
    Check.IsTrue (cross1.IsParallelTo (cross), nameStr)
    Check.IsTrue (crossAlpha.IsParallelTo (cross), nameStr)
    Check.IsTrue (crossM.IsParallelTo (cross), nameStr)
    Check.Near (1.0, cross1.Magnitude (), nameStr)
    Check.Near (alpha, crossAlpha.Magnitude (), nameStr)
    Check.Near (math.sqrt (length0) * math.sqrt (length1), crossM.Magnitude (), nameStr)

    unit = [DVec3d.From (0.0, 0.0, 0.0), DVec3d.From (0.0, 0.0, 0.0), DVec3d.From (0.0, 0.0, 0.0)]
    axes = [DVec3d.From (0.0, 0.0, 0.0), DVec3d.From (0.0, 0.0, 0.0), DVec3d.From (0.0, 0.0, 0.0)]
    vector0.GetNormalizedTriad (unit[0], unit[1], unit[2])
    vector0.GetTriad (axes[0], axes[1], axes[2])
    a = vector0.Magnitude()
    for i in numpy.arange (0, 3, 1):
        j = (i + 1) % 3
        Check.Near (1.0, unit[i].Magnitude(), nameStr)
        Check.Near (vector0.Magnitude(), axes[i].Magnitude(), nameStr)
        Check.NearZero (unit[i].DotProduct (unit[j]), nameStr)
        Check.NearZero (axes[i].DotProduct (axes[j]), nameStr)
        Check.Near (1.0, unit[0].TripleProduct (unit[1], unit[2]), nameStr)
        Check.Near (a * a * a, axes[0].TripleProduct (axes[1], axes[2]), nameStr)

'''
Test vector Difference, SetComponent, GetComponent etc.
'''
def TestMeasures (vector0, vector1):
    nameStr = ''
    vector01_constructor = DVec3d (vector0, vector1)
    vector01_difference = DVec3d()
    vector01_normalizedDifference = DVec3d()
    vector01_normalizedDifference.NormalizedDifference (vector1, vector0)
    vector01_difference.DifferenceOf (vector1, vector0)
    Check.Near (vector01_constructor.Magnitude(), vector0.Distance (vector1), nameStr)
    Check.Near (vector01_constructor.MagnitudeSquared(), vector0.DistanceSquared (vector1), nameStr)
    Check.IsTrue (vector01_difference.IsParallelTo (vector01_normalizedDifference), nameStr)
    Check.Near (1.0, vector01_normalizedDifference.Magnitude(), nameStr)
    Check.Near (vector01_constructor.MagnitudeXY(), vector0.DistanceXY (vector1), nameStr)
    a = 2.0 * vector0.Magnitude()
    for i in numpy.arange (-6, 10, 1):
        workVector = vector0
        b = a + workVector.GetComponent (i)
        workVector.SetComponent (b, i)
        Check.Near (b, workVector.MaxAbs(), nameStr)
    tol = 1.0e-8 * vector0.Magnitude()
    smaller = 0.01 * tol
    large = 100.0 * tol
    for i in numpy.arange (-6, 10, 1):
        vector2 = copy.copy(vector1)
        Check.IsTrue (vector1.IsEqual (vector2), nameStr)
        vector2.SetComponent (vector1.GetComponent (i) + smaller, i)
        Check.IsFalse (vector1.IsEqual (vector2), nameStr)
        Check.IsTrue (vector1.IsEqual (vector2, tol), nameStr)
        vector2.SetComponent (vector1.GetComponent (i) + large, i)
        Check.IsFalse (vector1.IsEqual (vector2), nameStr)
        Check.IsFalse (vector1.IsEqual (vector2, tol), nameStr)

'''
Test vector Normalize, ScaleToLength, IsParallelTo etc.
'''
def TestOps (vector0, vector1):
    nameStr = ''
    unitA = DVec3d()
    unitB = DVec3d()
    unitA.Normalize (vector0)
    unitB = vector0
    unitB.Normalize()
    Check.Near (unitA, unitB, nameStr)
    b = 2.901
    scaleA = DVec3d()
    scaleB = DVec3d()
    scaleB = vector0
    scaleA.ScaleToLength (vector0, b)
    scaleB.ScaleToLength (b)
    Check.Near (scaleA, scaleB, nameStr)
    Check.IsTrue (scaleA.IsParallelTo (vector0), nameStr)
    Check.Near (b, scaleA.Magnitude(), nameStr)
    
    c = 4.201
    scaleC = DVec3d()
    scaleD = DVec3d()
    scaleE = DVec3d()
    scaleC = vector1
    scaleC.Scale (c)
    scaleD.Scale (vector1, c)
    Check.Near (scaleC, scaleD, nameStr)
    Check.IsTrue (scaleC.IsParallelTo(vector1), nameStr)
    Check.Near (c * vector1.Magnitude(), scaleC.Magnitude(), nameStr)

    Check.IsTrue (scaleE.SafeDivide (scaleC, c), nameStr)
    Check.Near (vector1, scaleE, nameStr)

    negE = copy.copy (vector1)
    negF = DVec3d()
    negE.Negate()
    negF.Negate (vector1)
    Check.Near (negE, negF, nameStr)
    d = vector1.DotProduct (negE)
    Check.IsTrue (vector1.DotProduct (negE) < 0.0, nameStr)
    Check.Near (vector1.DotProduct (negE), -vector1.MagnitudeSquared(), nameStr)
    ones = DVec3d()
    ones.One()
    zero = DVec3d()
    zero.Zero()
    Check.Near (0.0, zero.MaxAbs(), nameStr)
    Check.Near (1.0, ones.MaxAbs(), nameStr)
    Check.Near (zero, DVec3d.From (0, 0, 0), nameStr)
    Check.Near (ones, DVec3d.From (1, 1, 1), nameStr)

    reverse1 = DVec3d.FromScale (vector1, -1.0)
    Check.IsTrue (vector1.IsParallelTo (vector1), nameStr)
    Check.IsTrue (vector1.IsParallelTo (reverse1), nameStr)
    Check.IsFalse (vector1.IsParallelTo (vector0), nameStr)

    Check.IsTrue (vector1.IsPositiveParallelTo (vector1), nameStr)
    Check.IsFalse (vector1.IsPositiveParallelTo (reverse1), nameStr)
    Check.IsFalse (vector1.IsPositiveParallelTo (vector0), nameStr)

'''
Test vector ReadWrite.
'''
def TestReadWrite (vector0, vector1, vector2):
    nameStr = ''
    origin = DPoint3d.From (5, 2, -1)
    originVector = DVec3d.From (origin)

    matrix = RotMatrix.FromColumnVectors (vector0, vector1, vector2)
    transpose = RotMatrix.FromRowVectors (vector0, vector1, vector2)

    transform = Transform.From (matrix, origin)

    for i in numpy.arange (-6, 10, 3):
        Check.Near (DVec3d.FromColumn (matrix, i),    vector0, nameStr)
        Check.Near (DVec3d.FromColumn (matrix, i+1),  vector1, nameStr)
        Check.Near (DVec3d.FromColumn (matrix, i+2),  vector2, nameStr)
        
        Check.Near (DVec3d.FromRow (transpose, i),    vector0, nameStr)
        Check.Near (DVec3d.FromRow (transpose, i+1),  vector1, nameStr)
        Check.Near (DVec3d.FromRow (transpose, i+2),  vector2, nameStr)

    a0 = 2.9
    a1 = -1.2
    a2 = -3.4

    vector_0p1A = DVec3d()
    vector_0p1B = DVec3d()
    vector_0p1C = DVec3d()

    vector_0p1A.SumOf (vector0, vector1)
    vector_0p1B = vector0
    vector_0p1B.Add (vector1)
    vector_0p1C.Multiply (matrix, 1.0, 1.0, 1.0)
    Check.Near (vector_0p1A, vector_0p1B, nameStr)
    Check.Near (vector_0p1A, vector_0p1C, nameStr)

    vector01A = DVec3d()
    vector01B = DVec3d()
    vector01C = DVec3d()
    vector01A = DVec3d.FromStartEnd (vector0, vector1)
    vector01B = vector1
    vector01B.Subtract (vector0)
    vector01C.DifferenceOf (vector1, vector0)
    Check.Near (vector01A, vector01B, nameStr)
    Check.Near (vector01A, vector01C, nameStr)

    f = 0.23491
    vectorF0 = DVec3d ()
    vectorF1 = DVec3d ()
    vectorF0.Interpolate (vector0, f, vector1)
    vectorF1.SumOf (vector0, vector01A, f)
    Check.Near (vectorF0, vectorF1, nameStr)

    vectorX = DVec3d()
    vectorX.Init (a0, a1, a2)
    sum = DVec3d()
    product = DVec3d()
    product.Multiply (matrix, vectorX)
    sum.SumOf (vector0, a0, vector1, a1, vector2, a2)
    Check.Near (product, sum, nameStr)
    product.Multiply (matrix, a0, a1, 0.0)
    sum.SumOf (vector0, a0, vector1, a1)
    Check.Near (product, sum, nameStr)

    b2 = -3.9

    sum.SumOf (originVector, vector2, b2)
    pointA = DPoint3d.FromProduct (transform, 0.0, 0.0, b2)
    Check.Near (sum, DVec3d.From(pointA), nameStr)

    sum.SumOf (originVector, vector1)
    Check.Near (sum, DPoint3d.FromProduct (transform, 0.0, 1.0, 0.0), nameStr)

    sum.SumOf (originVector, vector0, a0, vector1, a1)
    Check.Near (sum, DPoint3d.FromProduct (transform, a0, a1, 0.0), nameStr)

    sum.SumOf (originVector, vector0, a0, vector1, a1, vector2, a2)
    Check.Near (sum, DPoint3d.FromProduct (transform, a0, a1, a2), nameStr)

    wTA_0 = DVec3d()
    wTA_1 = DVec3d()
    w = DVec3d.From (a0, a1, a2)
    wTA_0.MultiplyTranspose (matrix, a0, a1, a2)
    wTA_1.MultiplyTranspose (matrix, w)
    Check.Near (wTA_0, wTA_1, nameStr)

    v1 = DVec3d()
    v2 = DVec3d()
    v3 = DVec3d()
    v1.Init (vector0.x, vector0.y, vector0.z)
    Check.Near (vector0, v1, nameStr)
    v2.Init (vector0.x, vector0.y, 0.0)
    v3.Init (vector0.x, vector0.y)
    Check.Near (v2, v3, nameStr)
    p4 = vector0
    v4 = DVec3d()
    v4.Init (p4)
    Check.Near (vector0, v4, nameStr)

    vector0XY = DVec3d.From (vector0.x, vector0.y)
    theta = math.atan2 (vector0.y, vector0.x)
    thetaA = DVec3d.From (1,0,0).AngleToXY (vector0)
    Check.Near (theta, thetaA, nameStr)
    rho   = vector0.MagnitudeXY ()
    rho2  = vector0.MagnitudeSquaredXY ()
    Check.Near (rho2, rho * rho, "MagnitudeSquaredXY")
    vector0XY_A = DVec3d()
    vector0XY_A.InitFromXYAngleAndMagnitude (theta, rho)
    vector0XY_B = DVec3d.FromXYAngleAndMagnitude (theta, rho)
    Check.Near (vector0XY, vector0XY_A, nameStr)
    Check.Near (vector0XY, vector0XY_B, nameStr)

    alpha = 0.3
    rotatedA = DVec3d()
    rotatedB = DVec3d()
    rotatedA.RotateXY (vector0, alpha)
    rotatedB = vector0
    rotatedB.RotateXY (alpha)
    Check.Near (rotatedA, rotatedB, nameStr)
    Check.Near (vector0.MagnitudeXY (), rotatedA.MagnitudeXY (), nameStr)
    Check.Near (alpha, vector0.AngleToXY (rotatedA), nameStr)
    Check.Near (vector0.z, rotatedA.z, nameStr)
        
    perpXY = DVec3d()
    perpXY.UnitPerpendicularXY (vector0)
    Check.Near (0.5 * Angle.Pi (), vector0.AngleToXY (perpXY), nameStr)
    Check.Near (1.0, perpXY.MagnitudeXY(), nameStr)
    Check.Near (0.0, perpXY.z, nameStr)

'''
Find tolerance.
'''
def FindTolerance (vector0):
    eps = 1.0e-1
    a = vector0.Magnitude ()
    approxTol = (1.0 + a) * DoubleOps.SmallCoordinateRelTol()
    rangeFactor = 10.0
    printToleranceDetails = False
    for i in numpy.arange (0, 50, 1):
        eps *= 0.5
        vector1 = copy.copy(vector0)
        absDelta = abs (eps * a)
        vector1.x += absDelta
        if vector0.AlmostEqual (vector1):
            Check.IsTrue (absDelta < approxTol * rangeFactor and absDelta > approxTol / rangeFactor, "Tolerance Search")
            if printToleranceDetails:
                printf (" (%g,%g,%g) Apparent AlmostEqual (reltol %g) (absDelta %g)\n",
                    vector0.x, vector0.y, vector0.z, eps, absDelta)
            return
    Check.IsTrue (False, "UNABLE TO FIND TOLERANCE FOR ALMOSTEQUAL")

'''
Test vector angles.
'''
def TestAngles_go (vec0, vec1):
    nameStr = ''
    Check.IsFalse (vec0.IsParallelTo (vec1), nameStr)
    Check.IsTrue (vec0.IsParallelTo (vec0))
  
    positiveAngle = vec0.AngleTo (vec1)
    perp1 = DVec3d.FromCrossProduct (vec0, vec1)
    perp2 = DVec3d.FromCrossProduct (vec1, vec0)
    smallerAngle = vec0.SmallerUnorientedAngleTo (vec1)
    signedAngle1 = vec0.SignedAngleTo (vec1, perp1)
    signedAngle2 = vec0.SignedAngleTo (vec1, perp2)

    Check.IsTrue (perp1.IsParallelTo (vec0), nameStr)
    Check.IsTrue (perp2.IsParallelTo (vec1), nameStr)

    Check.Near (signedAngle1, -signedAngle2, nameStr)
    acuteAngle = positiveAngle < Angle.PiOver2 ()
    sums = []
    sums[0].SumOf (vec0, 1.0,  vec1, 1.0)
    sums[1].SumOf (vec0, -1.0, vec1, 1.0)
    sums[2].SumOf (vec0, -1.0, vec1, -1.0)
    sums[3].SumOf (vec0, 1.0, vec1, -1.0)
    Check.IsTrue  (sums[0].IsVectorInSmallerSector  (vec0, vec1), nameStr)
    Check.IsFalse (sums[1].IsVectorInSmallerSector (vec0, vec1), nameStr)
    Check.IsFalse (sums[2].IsVectorInSmallerSector (vec0, vec1), nameStr)
    Check.IsFalse (sums[3].IsVectorInSmallerSector (vec0, vec1), nameStr)

    Check.IsTrue  (sums[0].IsVectorInCCWSector (vec0, vec1, perp1), nameStr)
    Check.IsFalse (sums[1].IsVectorInCCWSector (vec0, vec1, perp1), nameStr)
    Check.IsFalse (sums[2].IsVectorInCCWSector (vec0, vec1, perp1), nameStr)
    Check.IsFalse (sums[3].IsVectorInCCWSector (vec0, vec1, perp1), nameStr)

    Check.IsFalse (sums[0].IsVectorInCCWSector (vec0, vec1, perp2), nameStr)
    Check.IsTrue  (sums[1].IsVectorInCCWSector (vec0, vec1, perp2), nameStr)
    Check.IsTrue  (sums[2].IsVectorInCCWSector (vec0, vec1, perp2), nameStr)
    Check.IsTrue  (sums[3].IsVectorInCCWSector (vec0, vec1, perp2), nameStr)

    if acuteAngle:
        Check.Near (positiveAngle, smallerAngle, nameStr)
    else:
        Check.Near (smallerAngle, Angle.PiOver2() - positiveAngle)

    tilt0 = DVec3d()
    tilt1 = DVec3d()
    tilt0.SumOf (vec0, 1.3, perp1, 0.3)
    tilt1.SumOf (vec1, 0.3, perp1, -0.2)
    Check.Near (signedAngle1, tilt0.PlanarAngleTo (tilt1, perp1))
    Check.IsFalse (tilt0.IsParallelTo (vec0), nameStr)
    Check.IsFalse (tilt0.IsPerpendicularTo (vec0), nameStr)
    Check.IsFalse (tilt0.IsPerpendicularTo (perp1), nameStr)

'''
Test angles.
'''
def TestAngles (vec0, vec1):
    neg0 = DVec3d()
    neg1 = DVec3d()
    neg0.Negate (vec0)
    neg1.Negate (vec1)

    TestAngle_go (vec0, vec1)
    TestAngles_go (neg0, vec1)
    TestAngles_go (vec0, neg1)
    TestAngles_go (neg0, neg1)

'''
Test vector DifferenceOf.
'''
def TestDifferenceOf (point0, point1):
    nameStr = ''
    vecA = DVec3d.FromStartEnd (point0, point1)
    vecB = DVec3d()
    vecB.DifferenceOf (point1, point0)
    Check.Near (vecA, vecB, nameStr)
    point1A = point0
    point1A.Add (vecA)
    point0A = point1
    point0A.Subtract (vecA)
    Check.Near (point0, point0A, nameStr)
    Check.Near (point1, point1A, nameStr)

'''
All vector tests.
'''
def AllTests (vector0, vector1, vector2):
    TestProducts (vector0, vector1)
    TestMeasures (vector0, vector1)
    TestOps      (vector0, vector1)
    TestDifferenceOf (vector0, vector1)
    TestReadWrite (vector0, vector1, vector2)
    FindTolerance (vector0)
    FindTolerance (vector1)
    FindTolerance (vector2)
    for power in numpy.arange (-10, 10, 3):
        vector = DVec3d() 
        vector.Scale (vector2, pow (10.0, power))
        FindTolerance (vector)

'''
Run all tests of vectors.
'''
def test_DVec3d_All():
    vector0 = DVec3d.From (1,2,3)
    vector1 = DVec3d.From (4,5,-6)
    cross = DVec3d.FromCrossProduct (vector0, vector1)
    vector2 = DVec3d()
    vector2.SumOf (vector0, 1.2, vector1, -1.3, cross, 0.144)
    AllTests (vector0, vector1, vector2)

'''
Test vector PerpendicularParts.
'''
def TestPerpendicularParts (ux, uy, uz, vx, vy, vz):
    U = DVec3d.From (ux,uy,uz)
    V = DVec3d.From (vx,vy,vz)
    Check.StartScope ("PerpendicularParts")
    V0 = DVec3d()
    V1 = DVec3d()
    (bRet, f) = U.GetPerpendicularParts (V, V0, V1)
    if bRet:
        Check.Near (V.MagnitudeSquared (), V0.MagnitudeSquared () + V1.MagnitudeSquared (), "Pythagoras")
        Check.IsTrue (U.IsParallelTo (V0), "Parallel part direction")
        Check.IsTrue (U.IsPerpendicularTo (V1), "Parallel part direction")
    Check.EndScope ()

'''
Run vector PerpendicularParts tests.
'''
def test_DVed3d_PerpendicularParts():
    TestPerpendicularParts (1,0,0,0,1,0)
    TestPerpendicularParts (1,1,1,0,1,0)
    TestPerpendicularParts (1,2,3,6,5,7)
    TestPerpendicularParts (1,2,3,1,2,3)

































