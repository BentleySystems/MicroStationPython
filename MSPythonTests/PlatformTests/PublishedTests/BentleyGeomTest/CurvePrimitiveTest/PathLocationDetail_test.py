import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *

def test_DetailConstructors():
    data = []
    for i in range(0,3):
        curveRef = CurveLocationDetail()
        data.append(PathLocationDetail(curveRef, i, i + 0.0))
        data.append(PathLocationDetail(curveRef, i, i + 0.2))
        data.append(PathLocationDetail(curveRef, i, i + 0.5))
    for i in range(0, len(data)):
        for j in range(i + 1, len(data)):
            assert PathLocationDetail.IsLessThan_ByPathDistance (data[i], data[j])

def Interpolate(dataA, fraction, dataB):
    return dataA + fraction * (dataB - dataA)

def ExerciseSearcher(searcher, numTest = 5, isInViewPlane = True):
    location0 = searcher.AtStart()
    location1 = searcher.AtEnd()
    if numTest < 2:
        numTest = 2
    s_circleFraction = 0.25
    pathDistance = location1.DistanceFromPathStart()
    circleRadius = s_circleFraction * pathDistance / numTest
    for i in range (0, numTest+1):
        f = i / numTest
        f = f + 0.0
        targetDistance = Interpolate(location0.DistanceFromPathStart(), f, location1.DistanceFromPathStart())
        locationA = PathLocationDetail()
        print(locationA)
        assert searcher.SearchByDistanceFromPathStart(targetDistance, locationA)
        locationB = searcher.SearchClosestPointBounded(locationA.Point(), True)
        #Check::Near (targetDistance, locationB.DistanceFromPathStart ());
        if locationA.DistanceToPoint(location0) > circleRadius:
            circleIntersection = PathLocationDetail()
            if searcher.SearchFirstIntersectionWithCircleXY(locationA, circleRadius, circleIntersection):
                assert PathLocationDetail.IsLessThan_ByPathDistance(circleIntersection, locationA)
                #Check::Near (circleRadius, searcher.DistanceBetweenPointsXY (circleIntersection.Point (), locationA.Point ()))
        if locationA.DistanceToPoint(location1) > circleRadius:
            circleIntersection = PathLocationDetail()
            if searcher.SearchFirstIntersectionWithCircleXY(locationA, circleRadius, circleIntersection):
                assert PathLocationDetail.IsLessThan_ByPathDistance (locationA, circleIntersection)
                #Check::Near (circleRadius, searcher.DistanceBetweenPointsXY (circleIntersection.Point (), locationA.Point ()))


def PathTestLines(upVector):
    worldToView = RotMatrix()
    viewToWorld = RotMatrix()
    xVec = yVec = zVec = DVec3d()
    upVector.GetNormalizedTriad(xVec, yVec, zVec)
    viewToWorld = RotMatrix.FromColumnVectors(xVec, yVec, zVec)
    worldToView.TransposeOf(viewToWorld)

    xyzA = DPoint3d.From(10, 0, 0)
    line = ICurvePrimitive.CreateLine(DSegment3d(DPoint3d.From(0,0,0), xyzA))
    path = CurveVector(CurveVector.eBOUNDARY_TYPE_Open)
    path.Add(line)
    searcher = CurveVectorWithDistanceIndex(worldToView)
    searcher.SetPath(path)
    ExerciseSearcher(searcher, 4)
    lsAxyz = DPoint3dArray()
    lsAxyz.append(xyzA)
    lsAxyz.append(DPoint3d.FromSumOf(xyzA, DVec3d.From(3,5,0)))
    lsAxyz.append(DPoint3d.FromSumOf(xyzA, DVec3d.From(7,2,0)))
    lsA = ICurvePrimitive.CreateLineString(lsAxyz)
    path.Add(lsA)
    searcher.SetPath(path)
    ExerciseSearcher(searcher, 4)

def test_OneLine():
    PathTestLines(DVec3d(DVec3d.From(0, 0, 1)))
    PathTestLines(DVec3d(DVec3d.From(0, 1, 3)))
    PathTestLines(DVec3d(DVec3d.From(1, 0, 3)))

@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_ExtendedPath():
    xyzA = DPoint3d.From(10, 0, 0)
    line = ICurvePrimitive.CreateLine(DSegment3d(DPoint3d.From(0,0,0,), xyzA))
    path = CurveVector(CurveVector.eBOUNDARY_TYPE_Open)
    path.Add(line)
    worldToView = RotMatrix()
    viewToWorld = RotMatrix()
    upVector = DVec3d(DVec3d.From(1,1,4))
    xVec = yVec = zVec = DVec3d()
    upVector.GetNormalizedTriad(xVec, yVec, zVec)
    viewToWorld = RotMatrix.FromColumnVectors (xVec, yVec, zVec)
    worldToView.TransposeOf (viewToWorld)
    
    searcher = CurveVectorWithDistanceIndex(worldToView)

    boundedStart = PathLocationDetail()
    boundedEnd = PathLocationDetail()
    searcher.SetExtendedPath(arr,
     2.0,
     boundedStart, boundedEnd,
     True,
     5.0
     )

