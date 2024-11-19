from math import fabs
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

MESH_HEADER_ELM = 105
MESH_ELM_STYLE_INDEXED_FACE_LOOPS = 1
MESH_ELM_STYLE_POINT_CLOUD = 2
MESH_ELM_STYLE_COORDINATE_TRIANGLES = 3
MESH_ELM_STYLE_COORDINATE_QUADS = 4
MESH_ELM_STYLE_TRIANGLE_GRID = 5
MESH_ELM_STYLE_QUAD_GRID = 6
MESH_ELM_STYLE_LARGE_MESH = 7
STRING_LINKAGE_KEY_IlluminatedMesh = 66
MAXFILELENGTH = 1000
EPSILON = 0.000000001

def ConfirmProperties(mesh, volume0, numFace0, minPerFace0, maxPerFace0, hasNonPlanar0, hasConcave0):
    origin = DPoint3d()
    origin.Init(0, 0, 0)
    volume1 = PolyfaceQuery.SumTetrahedralVolumes(mesh, origin)
    ok = True
    ok &= fabs(volume1 - volume0) < (0.000000000001) * fabs(volume0)
    (numFace1, minPerFace1, maxPerFace1, hasNonPlanar1, hasConcave1) = mesh.InspectFaces()
    ok &= (numFace0 == numFace1)
    ok &= (minPerFace0 == minPerFace1)
    ok &= (maxPerFace0 == maxPerFace1)
    ok &= (hasNonPlanar0 == hasNonPlanar1)
    ok &= (hasConcave0 == hasConcave1)
    return ok

def CreateCube(variableSize, x0, y0, z0, a, b, c):
    header0 = PolyfaceHeader.CreateVariableSizeIndexed ()
    header0.SetMeshStyle(MESH_ELM_STYLE_INDEXED_FACE_LOOPS);
    header0.SetTwoSided(False)
    x1 = x0 + a
    y1 = y0 + b
    z1 = z0 + c
    points = DPoint3dArray()
    points.append(DPoint3d(x0,y0,z0))
    points.append(DPoint3d(x1,y0,z0))
    points.append(DPoint3d(x0,y1,z0))
    points.append(DPoint3d(x1,y1,z0))
    points.append(DPoint3d(x0,y0,z1))
    points.append(DPoint3d(x1,y0,z1))
    points.append(DPoint3d(x0,y1,z1))
    points.append(DPoint3d(x1,y1,z1))
    indices = [2,1,3,4,0,
                   5,6,8,7,0,
                   2,4,8,6,0,
                   1,5,7,3,0,
                   6,5,1,2,0,
                   8,4,3,7,0]
    header0.Point().Active = True
    header0.PointIndex().Active = True
    for i in range(0, len(points)):
            header0.Point().append(points[i])
    numPerFace = PushIndices(header0.PointIndex(), indices, len(indices), variableSize)
    header0.SetNumPerFace(numPerFace)
    if numPerFace <= 1:
        numPerFace = 1
    header0.PointIndex().StructsPerRow = numPerFace
    return header0

def PushIndices( dest, indices, count, padToMaxFaceSize):
    numPerFace = 0
    if padToMaxFaceSize: 
        maxCount = 0
        currCount = 0;
        for i in range(0, count):
            if indices[i] == 0:
                if currCount > maxCount:
                    maxCount = currCount
                currCount = 0
            else:
                currCount += 1
        numPerFace = maxCount
        currCount = 0;
        for i in range(0, count):
            if indices[i] == 0:
                while (currCount < maxCount):
                    dest.append(0)
                    currCount += 1
                currCount = 0
            else:
                currCount += 1
                dest.append(indices[i]);
    else:
        for i in range(0, count):
            dest.append(indices[i])
        numPerFace = 0
    return numPerFace

def CreateSweep(basePoints, numBasePoints, sweepVector):
    header0 = PolyfaceHeader.CreateVariableSizeIndexed()
    header0.SetMeshStyle(MESH_ELM_STYLE_INDEXED_FACE_LOOPS);
    header0.SetTwoSided(False)
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0)] * 1000)
    indices = [0] * 1000
    for i in range(0, numBasePoints):
        points[i] = basePoints[i]
    for i in range(0, numBasePoints):
        points[i + numBasePoints].SumOf(points[i], sweepVector)
    numPoints = 2 * numBasePoints
    # Base polygon in reverse order
    m = 0
    for i in range(0, numBasePoints):
        indices[m] = numBasePoints - i
        m += 1
    indices[m] = 0
    m += 1
    # Top
    for i in range(0, numBasePoints):
        indices[m] = numBasePoints + i + 1
        m += 1
    indices[m] = 0
    m += 1
    # Sides
    for i in range(0, numBasePoints):
        j = (i + 1) % numBasePoints;
        indices[m] = 1 + i;
        m += 1
        indices[m] = 1 + j;
        m += 1
        indices[m] = 1 + j + numBasePoints;
        m += 1
        indices[m] = 1 + i + numBasePoints;
        m += 1
        indices[m] = 0;
        m += 1
    header0.Point().Active = True
    header0.PointIndex().Active = True
    for i in range(0, numPoints):
        header0.Point().append(points[i])
    numPerFace = PushIndices(header0.PointIndex(), indices, m, True)
    header0.SetNumPerFace(numPerFace)
    if numPerFace <= 1:
        numPerFace = 1
    header0.PointIndex().StructsPerRow = numPerFace
    return header0

def isDPoint3dNear(left, right , Epsilon):
    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon
    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)

def Read(headerHandle, a):
    headerElement = headerHandle.GetElement()
    if headerElement.ehdr.type != MESH_HEADER_ELM:
        return False
    # ElementHandle does not have property meshHeader.
    # meshStyle = headerElement.meshHeader.meshStyle
    # should return the above line.
    return PolyfaceQuery.MeshStyle

# This function is incomplete
def PolyfaceFromElement(meshData, eh):
    meshStyle = Read(eh, 0)
    if not meshStyle:
        return BentleyStatus.eERROR
    myMesh = PolyfaceHeader.CreateVariableSizeIndexed()
    faceToColorIndex = BlockedVectorInt()
    vertexToColorIndex = BlockedVectorInt()
    myMesh.SetTwoSided(True)
    if meshStyle == MESH_ELM_STYLE_QUAD_GRID or meshStyle == MESH_ELM_STYLE_COORDINATE_QUADS:
        myMesh.SetNumPerFace(4)
    elif meshStyle == MESH_ELM_STYLE_TRIANGLE_GRID or meshStyle == MESH_ELM_STYLE_COORDINATE_TRIANGLES:
        myMesh.SetNumPerFace(3)
    else:
        myMesh.SetNumPerFace(0)
    # LinkageUtil::ExtractNamedStringLinkageByIndex This function is not yet exposed
    illuminatedTexture = ""
    # if BentleyStatus.eSUCCESS != LinkageUtil.ExtractNamedStringLinkageByIndex(illuminatedTexture, MAXFILELENGTH, STRING_LINKAGE_KEY_IlluminatedMesh, 0, eh.GetElement()):
    #     myMesh.SetIlluminationName(illuminatedTexture)
    ExposeChildrenCount = ExposeChildrenReason(100)
    childEh = ChildElemIter(eh, ExposeChildrenCount)
    if not childEh.IsValid():
        return BentleyStatus.eERROR
    while(childEh.IsValid() and childEh):
        childEh = childEh.ToNext()
    return BentleyStatus.eSUCCESS

def CreateMesh00(eeh, model):
    header0 = PolyfaceHeader.CreateVariableSizeIndexed()
    header0.SetMeshStyle(MESH_ELM_STYLE_INDEXED_FACE_LOOPS);
    header0.SetTwoSided(False)
    header0.SetNumPerFace(0)
    points = DPoint3dArray()
    points.append(DPoint3d(1.0, 1.0, 0.0))
    points.append(DPoint3d(2.0, 1.0, 0.0))
    points.append(DPoint3d(2.0, 2.0, 0.0))
    points.append(DPoint3d(1.0, 2.0, 0.0))
    indices = [1,2,-3,0, 3,4,-1,0]
    header0.Point().Active = True
    header0.PointIndex().Active = True
    for i in range(0, len(indices)):
        header0.PointIndex().append(indices[i])
    for i in range(0, len(points)):
        header0.Point().append(points[i])
    return header0

def MatchedIndexVectors(vector0, vector1):
    n0 = len(vector0)
    n1 = len(vector1)
    error = 0
    if vector0.Active != vector1.Active:
        error += 1
    if n0 != n1:
        error += 1
    else:
        for i in range(0, n0):
            if vector0[i] != vector1[i]:
                error += 1
    return error == 0

def CreateElement(eeh, ret):
    errors = 0;
    header0 = CreateMesh00(eeh, ret[0])
    assert header0 != None

    stat1 = MeshHeaderHandler.CreateMeshElement(eeh, None , header0, True, ret[0])
    assert stat1 == BentleyStatus.eSUCCESS

    header1 = PolyfaceHeaderPtrArray()
    if PolyfaceFromElement(header1, eeh) == BentleyStatus.eSUCCESS:
        # For now.
        header1 = header0
        a = MatchedIndexVectors(header0.PointIndex(), header1.PointIndex())
        assert a == True
        visitor0 = PolyfaceVisitor.Attach(header0)
        visitor1 = PolyfaceVisitor.Attach(header0)
        while visitor0.Reset() and visitor1.Reset():
            n0 = len(visitor0.Point())
            n1 = len(visitor1.Point())
            if n0 != n1:
                errors += 1
            else:
                for i in range(0, n0):
                    if visitor0.ClientPointIndex()[i] != visitor1.ClientPointIndex()[i]:
                        errors += 1
            visitor0 = visitor0.AdvanceToNextFace()
            visitor1 = visitor1.AdvanceToNextFace()
        assert errors == 0
        # assert visitor0.AdvanceToNextFace() == False
        # assert visitor1.AdvanceToNextFace() == False
        return
    if(type == "LineString"):
        
        NV = 5
        points = DPoint3dArray()
        GeneratePoints(points, NV)

        assert BentleyStatus.eSUCCESS == LineStringHandler.CreateLineStringElement(eeh, None, points, ret[0].is3d(), ret[0])
        return
         
    if(type == "nShape"):
        NUM_POINTS = 20
        points = DPoint3dArray()
        InitPoints(points, NUM_POINTS)

        assert BentleyStatus.eSUCCESS == ShapeHandler.CreateShapeElement (eeh, None, points, ret[0].is3d(), ret[0])
        return
    
    # if type == "nSharedCell":
    #     CreateDef(model, is3d);
    #     SharedCellSetUp(eeh, model, is3d);
    #     return;

    if(type == "Complex"):    #DSegment3d.point() method is not exposed. 
        ChainHeaderHandler.CreateChainHeaderElement (eeh, None, True, ret[0].is3d(), model)
        NV = 2
        line = EditElementHandle()
        segment = DSegment3d()
    
        InitPoints_Complex (segment.point, NV)

        assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement (line, None, segment, ret[0].is3d(), ret[0])
        ChainHeaderHandler.AddComponentElement (eeh, line)
        ChainHeaderHandler.AddComponentComplete(eeh)
        line.Invalidate()
        return

    if(type == "BSpline"):
        spline = MSBsplineCurve.Create()
        NUM_POINTS = 4
        poles = DPoint3dArray()
        InitPoints(poles, NUM_POINTS)
        spline.InitFromPoints (poles)

        assert BentleyStatus.eSUCCESS ==  BSplineCurveHandler.CreateBSplineCurveElement (eeh, None, spline, ret[0].is3d(), ret[0])
        spline.ReleaseMem()
        return
