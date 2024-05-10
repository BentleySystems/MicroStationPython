import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

SURFTYPE_PROJECTION = 0
SURFTYPE_REVOLUTION = 8
SOLIDTYPE_REVOLUTION = 1
EPSILON = 0.000000001
PI = 3.1415926535897932384626433
DISTANCE = 10.0
TOLERANCE_ExtrusionSkew = 5.0

def isDPoint3dNear(left, right , Epsilon):
    assert abs (left.x- right.x) <= Epsilon
    assert abs (left.y- right.y) <= Epsilon
    assert abs (left.z- right.z) <= Epsilon
    return (abs (left.x - right.x) < Epsilon and
            abs (left.y - right.y) < Epsilon and
            abs (left.z - right.z) < Epsilon)

def CalculateElementSize(size):
    return size//2;

def ConeElementSetUp(model, m_eeh):
    rMatrix = RotMatrix()
    top = DPoint3d (0,10,0)
    bottom = DPoint3d (0,0,0)
    rMatrix.InitIdentity ()
    assert BentleyStatus.eSUCCESS == ConeHandler.CreateConeElement(m_eeh, None, 1.000000000001, 0.0, top, bottom, rMatrix, True, model)

def TestValidProfile(isValid, type, model, lineNumber, ret, m_eeh):
    segment = DSegment3d()
    assert 0 == LineHandler.CreateLineElement(m_eeh, None, segment, ret[0].Is3d(), ret[0])
    assert True == ChainHeaderHandler.IsValidChainComponentType(m_eeh)

def CreateSolidProj(preferSolid, ret, handler, m_eeh, isModelAdded = False):
    points = DPoint3d()
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0)] * 5)
    origin = DPoint3d(0.0, 0.0, 0.0)
    GenerateRectangle (points, origin, DISTANCE, DISTANCE)
    if handler == "LineStringCreator":
        LineStringHandler.CreateLineStringElement(m_eeh, None, points, False, ret[0])
    elif handler == "ShapeCreator":
        ShapeHandler.CreateShapeElement(m_eeh, None, points, False, ret[0])
    extrudeDir = DVec3d.From (0.0, 0.0, DISTANCE)
    transform = Transform()
    transform.InitIdentity ()
    if isModelAdded == False:
        m_eeh.AddToModel()
    id = m_eeh.GetElementId()
    m_eh = ElementHandle(id, ret[0])
    var = SurfaceOrSolidHandler.CreateProjectionElement(m_eeh, None, m_eh, origin, extrudeDir, transform, preferSolid, ret[0])
    return BentleyStatus.eSUCCESS

def IsSurfaceOfProjection(m_eeh, isCapped):
    el = m_eeh.GetElement()
    if eSOLID_ELM != el.ehdr.type and eSURFACE_ELM != el.ehdr.type:
        return (False, None)
    if isCapped:
        isCapped = (eSOLID_ELM == el.ehdr.type)
    return (SURFTYPE_PROJECTION == el.surf.surftype, isCapped)

# GetProjectionParameters Function not exposed
def GetProjectionParameters(eh, profile, direction, distance, ignoreSkew, profileEeh):
    if IsSurfaceOfProjection(profileEeh, True)[0] == False:
        return BentleyStatus.eERROR
    primitive = ISolidPrimitiveQuery.ElementToSolidPrimitive(profileEeh, False)
    detail = DgnRuledSweepDetail()
    if not primitive or primitive.TryGetDgnRuledSweepDetail(detail) == False:
        return BentleyStatus.eERROR
    # m_sectionCurves method is not exposed.
    if 2 != detail.m_sectionCurves.size ():
        return BentleyStatus.eERROR
    extrusionVector = DVec3d()
    if not detail.GetSectionCurveTranslation(extrusionVector, 0, 1):
        return BentleyStatus.eERROR
    distance = direction.Normalize (extrusionVector)
    profile  = detail.m_sectionCurves.front ()
    if ignoreSkew:
        return BentleyStatus.eSUCCESS
    area = 0.0
    normal = startCross = DVec3d()
    centroid = DPoint3d()
    if not profile.CentroidNormalArea (centroid, normal, area):
            singleCurvePermit = profile.HasSingleCurvePrimitive()
            if(singleCurvePermit == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line):
                segment = profile.front().GetLineCP()
                offset = [DPoint3d(), DPoint3d()]
                closeParam = 0.0
                offset[0].SumOf(segment.point[0], extrusionVector)
                offset[1].SumOf(segment.point[1], extrusionVector)
                if not DRay3d.FromOriginAndTarget(offset[0], offset[1]).ProjectPointUnbounded(offset[0], closeParam, segment.point[0]):
                    return BentleyStatus.eERROR
                normal.NormalizedDifference(offset[0], segment.point[0])
            else:
                localRange = DRange3d(DPoint3d(), DPoint3d())
                localToWorld = worldToLocal = Transform()
                if not profile.IsPlanar(localToWorld, worldToLocal, localRange):
                    return BentleyStatus.eERROR
                normal.Init (0.0, 0.0, 1.0)
                localToWorld.MultiplyMatrixOnly (normal)
                normal.Normalize()
    startCross.CrossProduct (extrusionVector, normal)
    return BentleyStatus.eSUCCESS if startCross.Magnitude () < TOLERANCE_ExtrusionSkew else BentleyStatus.eERROR

def ExtractProjectionParameters(profileEeh, eh, direction, distance, ignoreSkew):
    profile = CurveVector(CurveVector.eBOUNDARY_TYPE_None)
    if GetProjectionParameters(eh, profile, direction, distance, ignoreSkew, profileEeh) != BentleyStatus.eSUCCESS:
        return BentleyStatus.eERROR
    if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(profileEeh, profile, None, eh.GetDgnModel()):
        return BentleyStatus.eERROR
    ElementPropertiesSetter.ApplyTemplate(profileEeh, profileEeh);
    return BentleyStatus.eSUCCESS

def CreateSolidRev(preferSolid, ret, handler, m_eeh):
    points = DPoint3d()
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0)] * 5)
    center = DPoint3d(0.0, 0.0, 0.0)
    SWEEP_ANGLE = PI/2.0
    GenerateRectangle (points, center, DISTANCE, DISTANCE);
    if handler == "LineStringCreator":
        LineStringHandler.CreateLineStringElement(m_eeh, None, points, False, ret[0])
    elif handler == "ShapeCreator":
        ShapeHandler.CreateShapeElement(m_eeh, None, points, False, ret[0])
    extrudeDir = DVec3d.From (0.0, 0.0, DISTANCE)
    transform = Transform()
    transform.InitIdentity ()
    m_eeh.AddToModel()
    id = m_eeh.GetElementId()
    m_eh = ElementHandle(id, ret[0])
    axis = DVec3d.From (0.0, 0.0, 1.0)
    var = SurfaceOrSolidHandler.CreateRevolutionElement(m_eeh, None, m_eh, center, axis, SWEEP_ANGLE, preferSolid, ret[0])
    return BentleyStatus.eSUCCESS

def isPossibleSurfaceOfRevolution(m_eeh):
    if eSOLID_ELM != m_eeh.GetElementType() and eSURFACE_ELM != m_eeh.GetElementType():
        return False
    el = m_eeh.GetElement()
    return SURFTYPE_PROJECTION != el.surf.surftype

def GetRevolutionParameters(profileEeh, eh, profile, center, axis, sweep, ret):
    if isPossibleSurfaceOfRevolution(profileEeh) != True:
        return BentleyStatus.eERROR
    primitive = ISolidPrimitiveQuery.ElementToSolidPrimitive(profileEeh, True)
    details = DgnRotationalSweepDetail()
    if not primitive or primitive.TryGetDgnRotationalSweepDetail(details) == False:
        return BentleyStatus.eERROR
    center = DPoint3d()
    axis = DVec3d()
    sweep = 0.0;
    if details.TryGetRotationAxis(center, axis) == False:
        return BentleyStatus.eERROR;
    profile = details.__repr__();
    return (BentleyStatus.eSUCCESS, center, axis)

def IsSurfaceOfRevolution(m_eeh, isCapped):
    el = m_eeh.GetElement()
    if eSOLID_ELM != el.ehdr.type and eSURFACE_ELM != el.ehdr.type:
        return (False, None)
    if isCapped:
        isCapped = (eSOLID_ELM == el.ehdr.type)
    return (SURFTYPE_REVOLUTION == el.surf.surftype or SOLIDTYPE_REVOLUTION == el.surf.surftype, isCapped)

def ExtractRevolutionParameters(profileEeh, eh, center, axis, sweep, ignoreNonStandardForms, ret):
    if ignoreNonStandardForms and IsSurfaceOfRevolution(profileEeh, True)[0] == False:
        return BentleyStatus.eERROR
    profile = CurveVector(CurveVector.eBOUNDARY_TYPE_None)
    retVal, center, axis = GetRevolutionParameters(profileEeh, eh, profile, center, axis, sweep, ret)
    if BentleyStatus.eSUCCESS != retVal:
        return BentleyStatus.eERROR
    curve = CurveVector(CurveVector.eBOUNDARY_TYPE_Open)
    if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(profileEeh, curve, None, True, ret[0]):
        return BentleyStatus.eERROR
    ElementPropertiesSetter.ApplyTemplate(profileEeh, profileEeh)
    return (BentleyStatus.eSUCCESS, center, axis)

def isRuleClassElement(el):
    if not el.ehdr.isGraphics:
        return False
    return DgnElementClass(DgnElementClass.ePrimaryRule) == el.hdr.dhdr.props.b.elementClass or DgnElementClass(DgnElementClass.eConstruction) == el.hdr.dhdr.props.b.elementClass

def countBoundaries (eh):
    if eBSPLINE_CURVE_ELM == eh.GetElementType():
        count = 1
        ExposeChildrenCount = ExposeChildrenReason(100)
        childEh = ChildElemIter(eh, ExposeChildrenCount)
        childEh.IsValid()
        while childEh:
            childEh = childEh.ToNext()
            childEh = ChildElemIter(eh, ExposeChildrenCount)
            childEh.IsValid()
            count += 1
        return count
    return 1

def GetProfiles(eh, profiles):
    if eSOLID_ELM != eh.GetElementType() and eSURFACE_ELM != eh.GetElementType():
        return BentleyStatus.eERROR
    ExposeChildrenCount = ExposeChildrenReason(100)
    childEh = ChildElemIter(eh, ExposeChildrenCount)
    if not childEh.IsValid():
        return BentleyStatus.eERROR
    nBoundElms = eh.GetElement().surf.boundelms + 1
    boundElmsProcessed = 0
    currentLoop = CurveVector(CurveVector.eBOUNDARY_TYPE_None)
    currentProfileLoops = CurveVectorPtrArray()
    while(childEh.IsValid() and childEh):
        if isRuleClassElement(childEh.GetElement()):
            continue
        childCurve = ICurvePathQuery.ElementToCurveVector(childEh)
        if not childCurve:
            continue
        if childCurve.IsClosedPath():
            if currentLoop != None:
                currentProfileLoops.append(currentLoop);
                currentLoop = None
            currentProfileLoops.append(childCurve)
        elif currentLoop == None:
            currentLoop = childCurve
        else:
            loopStartPt = DPoint3d()
            loopEndPt = DPoint3d()
            childStartPt = DPoint3d()
            currentLoop.GetStartEnd(loopStartPt, loopEndPt)
            childCurve.GetStartPoint(childStartPt)
            if childStartPt.IsEqual(loopEndPt, 2.0) or not loopStartPt.IsEqual(loopEndPt, 2.0):
                for tmpCurve in childCurve:
                    if not tmpCurve:
                        continue
                    currentLoop.Add(tmpCurve)
            else:
                currentProfileLoops.append(currentLoop)
                currentLoop = childCurve
        boundElmsProcessed += countBoundaries(childEh)
        if boundElmsProcessed < nBoundElms:
            continue
        if currentLoop != None:
            currentProfileLoops.append(currentLoop);
            currentLoop = None
        # SetBoundaryType method is not Exposed.
        size = len(currentProfileLoops)
        if size == 0:
            return BentleyStatus.eERROR
        elif(size ==1):
            tmpCurve = currentProfileLoops.pop(0)
            pts = [DPoint3d(), DPoint3d()]
            s_closureTolerance = 2.0
            if eSOLID_ELM == eh.GetElementType() and tmpCurve.IsOpenPath() and tmpCurve.GetStartEnd(pts[0], pts[1]) and pts[0].IsEqual(pts[1], EPSILON if tmpCurve.length() == 1 else s_closureTolerance):
                tc = CurveVector(CurveVector.eBOUNDARY_TYPE_Outer)
            profiles.append(tc);
        else:
            regionProfile = CurveVector(CurveVector.eBOUNDARY_TYPE_ParityRegion)
            for tmpCurve in currentProfileLoops:
                if(tmpCurve == currentProfileLoops[0]):
                    tc = CurveVector(CurveVector.eBOUNDARY_TYPE_Outer)
                else:
                    tc = CurveVector(CurveVector.eBOUNDARY_TYPE_Inner)
                regionProfile.Add(ICurvePrimitive.CreateChildCurveVector_SwapFromSource(tc));
            profiles.append(regionProfile);
        childEh = childEh.ToNext()
    return (BentleyStatus.eSUCCESS, profiles)

def ExtractProfiles (eh, agenda, m_eeh, ret):
    retVal, profiles = GetProfiles(m_eeh, [])
    if BentleyStatus.eSUCCESS != retVal:
        return BentleyStatus.eERROR
    for curve in profiles:
        if BentleyStatus.eSUCCESS != DraftingElementSchema.ToElement(m_eeh, curve, None, True, ret[0]):
            return BentleyStatus.eERROR
        ElementPropertiesSetter.ApplyTemplate(m_eeh, m_eeh)
        agenda.Insert(m_eeh);
    return BentleyStatus.eSUCCESS

def GenerateSpiralYAxis(points, sz):
    rads = 0.0
    incr = math.pi/180.0
    scale = 1000.0
    for i in range (sz):
        rads += incr
        x = scale * math.cos (rads)
        y = scale * rads
        z = scale * math.sin (rads)
        points.append(DPoint3d(x,y,z))

def GenerateRectangle (outPoints, lowerLeft, width, height):
    for i in range(5):
        outPoints[i] = lowerLeft;
    outPoints[1].x += width;
    outPoints[2].x += width;
    outPoints[2].y += height;
    outPoints[3].y += height;