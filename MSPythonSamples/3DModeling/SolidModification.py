# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import ctypes
import sys
import debugpy
import os
import pytest
import shutil
import math
'''
Imprint solid using  profile
    solidId  : Integer   Solid which needs to be imprinted
    profileId : Integer  Profile which needs to be imprinted on solid 
'''
def imprintSolidUsingProfile(solidId, profileId):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    solidElement = EditElementHandle(solidId,dgnModel)
    profileElement = EditElementHandle(profileId,dgnModel)
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)
    solid = SolidUtil.Convert.ElementToBody(solidElement,True,True,False)
     
    if curve.IsClosedPath():
        centerNormalArea = curve.CentroidNormalArea()
        normal = centerNormalArea[2]
        normal.Negate()
        ret = SolidUtil.Modify.ImprintCurveVectorOnBody(solid[1],curve,normal,True)
        if(BentleyStatus.eSUCCESS == ret):
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 17)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 7)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 12)
            if(7==numfaces and numEdges ==17 and numVertices ==12):
                return True
    return False
'''
Sweep Profile along normal
    profileId  : Integer   Profile Id which will be swept in normal direction    
'''
def sweepBody(profileId):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(profileId,dgnModel)
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    modelInfo = dgnModel.GetModelInfo()

    if curve.IsClosedPath():
        centerNormalArea = curve.CentroidNormalArea()
        normal = centerNormalArea[2]
        normal.Scale(2*modelInfo.GetUorPerStorage())
        ret = SolidUtil.Modify.SweepBody(solid[1],normal)
        if(BentleyStatus.eSUCCESS == ret):
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
    return False
'''
Spin Profile around the axis
    profileId  : Integer   Profile Id which will be spin around the axis    
'''
def spinBody(profileId):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(profileId,dgnModel)
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    modelInfo = dgnModel.GetModelInfo()

    if curve.IsClosedPath():
        centerNormalArea = curve.CentroidNormalArea()
        normal = centerNormalArea[2]
        array3d = DRay3d()
        array3d.origin = DPoint3d(4*modelInfo.GetUorPerStorage(),0,0)
        array3d.direction = DVec3d(0,0,1)
        ret = SolidUtil.Modify.SpinBody(solid[1],array3d,math.pi)
        if(BentleyStatus.eSUCCESS == ret):
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
    return False
'''
Thicken the sheet
    profileId  : Integer   Profile Id which will be thicken in normal direction    
    frontDistance: Front distance of thickness
    backDistance: back distance of thickness
'''
def thickenSheet(profileId,frontDistance,backDistance):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(profileId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    modelInfo = dgnModel.GetModelInfo()
    frontDistance = frontDistance*modelInfo.GetUorPerStorage()
    backDistance = backDistance*modelInfo.GetUorPerStorage()

    ret = SolidUtil.Modify.ThickenSheet(solid[1],frontDistance,backDistance)
    if(BentleyStatus.eSUCCESS == ret):
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
        assert (numEdges == 12)
        subFaceArray  = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
        assert (numfaces == 6)
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
        assert (numVertices == 8)
        if(6==numfaces and numEdges ==12 and numVertices ==8):
            return True
    return False
'''
Blend edge of solid
    solidId  : Integer Solid element id whose edges   
    blendRadius: Blend Radius
'''
def blendEdges(solidId,blendRadius):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyEdges(subEdgeArray,solid[1])
    assert(numEdges == 12)
    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])
    subblendEdge.append(subEdgeArray[1])
    subblendEdge.append(subEdgeArray[2])
    modelInfo = dgnModel.GetModelInfo()
    blendRadius = blendRadius*modelInfo.GetUorPerStorage()
    blendRadiusArray = DoubleArray()
    blendRadiusArray.append(blendRadius)
    blendRadiusArray.append(blendRadius)
    blendRadiusArray.append(blendRadius)
    ret = SolidUtil.Modify.BlendEdges(solid[1],subblendEdge,blendRadiusArray,True)
    if(BentleyStatus.eSUCCESS == ret):
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
        assert (numEdges == 21)
        subFaceArray  = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
        assert (numfaces == 9)
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
        assert (numVertices == 14)
        if(9==numfaces and numEdges ==21 and numVertices ==14):
            return True
    return False

'''
Chamfer edge of solid
    solidId  : Integer Solid element id whose edges should undergo chamfering
    chamferLength: Chamfer distance
    chamferLength1: Chamfer distance
    mode:  Chamfering mode
'''
def chamferEdgesWithMode(solidId,chamferLength,chamferLength1 ,mode):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyEdges(subEdgeArray,solid[1])
    assert(numEdges == 12)
    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])
    subblendEdge.append(subEdgeArray[2])
    subblendEdge.append(subEdgeArray[3])
    modelInfo = dgnModel.GetModelInfo()
    if(SolidUtil.Modify.ChamferMode.eAngleDistance != mode):
        chamferLength = chamferLength*modelInfo.GetUorPerStorage()
    if(SolidUtil.Modify.ChamferMode.eDistanceAngle != mode):
        chamferLength1 = chamferLength1*modelInfo.GetUorPerStorage()
    chamferDistanceFirstArray = DoubleArray()
    chamferDistanceFirstArray.append(chamferLength)
    chamferDistanceFirstArray.append(chamferLength)
    chamferDistanceFirstArray.append(chamferLength)
    chamferDistanceArray = DoubleArray()
    chamferDistanceArray.append(chamferLength1)
    chamferDistanceArray.append(chamferLength1)
    chamferDistanceArray.append(chamferLength1)
    ret = SolidUtil.Modify.ChamferEdges(solid[1],subblendEdge,chamferDistanceFirstArray,chamferDistanceArray,mode,True)
    if(BentleyStatus.eSUCCESS == ret):
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
        assert (numEdges == 21)
        subFaceArray  = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
        assert (numfaces == 9)
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
        assert (numVertices == 14)
        if(9==numfaces and numEdges ==21 and numVertices ==14):
            return True
    return False
'''
Chamfer edge of solid
    solidId  : Integer Solid element id whose edges   
'''
def chamferEdges(solidId ):
   
    if(False == chamferEdgesWithMode(solidId,1.0,0.5,SolidUtil.Modify.ChamferMode.eDistances)):
       return False 
    if(False == chamferEdgesWithMode(solidId,1.0,1.0,SolidUtil.Modify.ChamferMode.eLength)):
       return False  
    if(False == chamferEdgesWithMode(solidId,1.0,0.785398163397,SolidUtil.Modify.ChamferMode.eDistanceAngle)):
       return False  
    if(False == chamferEdgesWithMode(solidId,0.785398163397,1.0,SolidUtil.Modify.ChamferMode.eAngleDistance)):
       return False  
    return True
'''
BooleanIntersect   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
    toolId2  : Tool second Solid
'''
def BooleanIntersect(solidId,toolId,toold2 ):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(targetId,True,True,False)
    toolElement = EditElementHandle(toolId,dgnModel)
    tool = SolidUtil.Convert.ElementToBody(toolElement,True,True,False)
    toolElement2 = EditElementHandle(toold2,dgnModel)
    tool2 = SolidUtil.Convert.ElementToBody(toolElement2,True,True,False)
    tools = ISolidKernelEntityPtrArray()
    tools.append(tool[1])
    tools.append(tool2[1])
    ret = SolidUtil.Modify.BooleanIntersect(solid[1], tools)

    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 15)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 7)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 10)
            if(7==numfaces and numEdges ==15 and numVertices ==10):
                return True
   
    return False
'''
BooleanSubtraction   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
    toolId2  : Tool second Solid
'''
def BooleanSubstraction(solidId,toolId,toold2 ):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(targetId,True,True,False)
    toolElement = EditElementHandle(toolId,dgnModel)
    tool = SolidUtil.Convert.ElementToBody(toolElement,True,True,False)
    toolElement2 = EditElementHandle(toold2,dgnModel)
    tool2 = SolidUtil.Convert.ElementToBody(toolElement2,True,True,False)
    tools = ISolidKernelEntityPtrArray()
    tools.append(tool[1])
    tools.append(tool2[1])
    ret = SolidUtil.Modify.BooleanSubtract(solid[1], tools)

    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 24)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 10)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 16)
            if(10==numfaces and numEdges ==24 and numVertices ==16):
                return True
   
    return False
'''
BooleanUnion   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
    toolId2  : Tool second Solid
    toolId3  : Tool second Solid
'''
def BooleanUnion(solidId,toolId,toold2,toolId3 ):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(targetId,True,True,False)
    toolElement = EditElementHandle(toolId,dgnModel)
    tool = SolidUtil.Convert.ElementToBody(toolElement,True,True,False)
    toolElement2 = EditElementHandle(toold2,dgnModel)
    tool2 = SolidUtil.Convert.ElementToBody(toolElement2,True,True,False)
    toolElement3 = EditElementHandle(toolId3,dgnModel)
    tool3 = SolidUtil.Convert.ElementToBody(toolElement3,True,True,False)
    tools = ISolidKernelEntityPtrArray()
    tools.append(tool[1])
    tools.append(tool2[1])
    tools.append(tool3[1])
    ret = SolidUtil.Modify.BooleanUnion(solid[1], tools)

    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 36)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 14)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 24)
            if(14==numfaces and numEdges ==36 and numVertices ==24):
                return True
  
    return False
'''
BooleanCut   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
'''
def BooleanCut(solidId,toolId ):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(targetId,True,True,False)
    
    profileElement = EditElementHandle(toolId,dgnModel)
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)
    nodeId = int()
    ret = SolidUtil.Modify.BooleanCut(solid[1], curve,SolidUtil.Modify.CutDirectionMode.eBoth,SolidUtil.Modify.CutDepthMode.eAll,0.0,False,None,nodeId)

    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 24)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 10)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 16)
            if(10==numfaces and numEdges ==24 and numVertices ==16):
                return True
  
    return False
'''
BooleanCut   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
'''
def emboss(solidId,toolId ):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(targetId,True,True,False)
    
    profileElement = EditElementHandle(toolId,dgnModel)
    curve =SolidUtil.Convert.ElementToBody(profileElement,True,True,True)
 
    ret = SolidUtil.Modify.Emboss(solid[1], curve[1],True)

    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 24)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 10)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 16)
            if(10==numfaces and numEdges ==24 and numVertices ==16):
                return True
  
    return True
'''
Offset face
    solidId  : Integer Solid element whose faces need to offset  
    offsetDistance: Offset distance
'''
def offsetFaces(solidId,offsetDistance):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyFaces(subEdgeArray,solid[1])
    assert(numEdges == 6)
    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])
    subblendEdge.append(subEdgeArray[1])
    subblendEdge.append(subEdgeArray[2])
    modelInfo = dgnModel.GetModelInfo()
    offsetDistance = offsetDistance*modelInfo.GetUorPerStorage()
    offsetDistanceArray = DoubleArray()
    offsetDistanceArray.append(offsetDistance)
    offsetDistanceArray.append(offsetDistance)
    offsetDistanceArray.append(offsetDistance)
    ret = SolidUtil.Modify.OffsetFaces(solid[1],subblendEdge,offsetDistanceArray,SolidUtil.Modify.StepFacesOption.eADD_STEP_Smooth)
    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],profileElement,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
    return False
'''
Transform face
    solidId  : Integer Solid element whose faces need to offset  
    offsetDistance: Offset distance
'''
def TransformFaces(solidId,offsetDistance):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyFaces(subEdgeArray,solid[1])
    assert(numEdges == 6)
    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])
    
    modelInfo = dgnModel.GetModelInfo()
    offsetDistance = offsetDistance*modelInfo.GetUorPerStorage()
    transArray = TransformArray()
    yVec = DVec3d(0.0,-1.0,0.0)
    yVec.Scale(offsetDistance)
    trans = Transform.From(yVec)
    transArray.append(trans)
    ret = SolidUtil.Modify.TransformFaces(solid[1],subblendEdge,transArray,SolidUtil.Modify.StepFacesOption.eADD_STEP_Smooth)
    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],profileElement,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
    return False
'''
Offset Through hole
    solidId  : Integer Solid element whose faces need to offset so as to generate hole 
    offsetDistance: Offset distance
'''
def offsetThroughHole(solidId,offsetDistance):
   
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    profileElement = EditElementHandle(solidId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(profileElement,True,True,False)
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyFaces(subEdgeArray,solid[1])
    assert(numEdges == 6)
    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])
    subblendEdge.append(subEdgeArray[1])
    subblendEdge.append(subEdgeArray[2])
    modelInfo = dgnModel.GetModelInfo()
    offsetDistance = offsetDistance*modelInfo.GetUorPerStorage()
    offsetDistanceArray = DoubleArray()
    offsetDistanceArray.append(offsetDistance)
    offsetDistanceArray.append(offsetDistance)
    offsetDistanceArray.append(offsetDistance)
    ret = SolidUtil.Modify.OffsetThroughHole(solid[1],subblendEdge,offsetDistanceArray )
    if(BentleyStatus.eSUCCESS == ret):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,solid[1],profileElement,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,solid[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,solid[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,solid[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
    return False
'''
BodyfromSweep   of profile
    solidId  : Profile element
    path id  : Path element
'''
def BodyfromSweep(profileId,pathId):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(profileId,dgnModel)
 
    profile = ICurvePathQuery.ElementToCurveVector(targetId)
    
    pathElement = EditElementHandle(pathId,dgnModel)
 
    path = ICurvePathQuery.ElementToCurveVector(pathElement)
    ret = SolidUtil.Create.BodyFromSweep(profile, path,ACTIVEMODEL,False,True,False,None,None,None,None)

    if(BentleyStatus.eSUCCESS == ret[0]):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,ret[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,ret[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,ret[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,ret[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
  
    return False
'''
Loft from profiles and guidewire
    guideId     : Guide element
    startProfile: Profile at start of guide
    endProfile  : Profile at end of guide
'''
def LoftBody(guideId,startProfile,endProfile):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(guideId,dgnModel)
 
    guide = ICurvePathQuery.ElementToCurveVector(targetId)
    guides = CurveVectorPtrArray()
    guides.append(guide)
 
    stProfile = EditElementHandle(startProfile,dgnModel)
    stProf = ICurvePathQuery.ElementToCurveVector(stProfile)
    edProfile = EditElementHandle(endProfile,dgnModel)
    edProf = ICurvePathQuery.ElementToCurveVector(edProfile)
    profiles = CurveVectorPtrArray()
    profiles.append(stProf)
    profiles.append(edProf)

    ret = SolidUtil.Create.BodyFromLoft(profiles,guides, dgnModel,False,False)

    if(BentleyStatus.eSUCCESS == ret[0]):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,ret[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,ret[1])
            assert (numEdges == 14)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,ret[1])
            assert (numfaces == 3)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,ret[1])
            assert (numVertices == 14)
            if(3==numfaces and numEdges ==14 and numVertices ==14):
                return True
  
    return False
'''
extrusionToBody Extrude the profile till the body
    bodyId      : Extrusion of profile till the presence of body
    startProfile: Profile at start of guide
'''
def extrusionToBody(bodyId,startProfile):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(bodyId,dgnModel)
    solid = SolidUtil.Convert.ElementToBody(targetId,True,True,True)

    stProfile = EditElementHandle(startProfile,dgnModel)
    stProf = SolidUtil.Convert.ElementToBody(stProfile,True,True,True)

    ret = SolidUtil.Create.BodyFromExtrusionToBody(solid[1],stProf[1], True)

    if(BentleyStatus.eSUCCESS == ret[0]):
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,ret[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            #intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,ret[1])
            assert (numEdges == 12)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,ret[1])
            assert (numfaces == 6)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,ret[1])
            assert (numVertices == 8)
            if(6==numfaces and numEdges ==12 and numVertices ==8):
                return True
  
    return False
'''
bSplineSurfaceToBody convert bspline surface to body
    bodyId      : Bspline surface element Id to convert into smart surface
'''
def bSplineSurfaceToBody(bodyId):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(bodyId,dgnModel)
    editor = targetId.GetHandler()
    ret = editor.GetBsplineSurface(targetId)
    if(BentleyStatus.eSUCCESS == ret[0]):
        surfaceToBody = SolidUtil.Create.BodyFromBSurface(ret[1],dgnModel)
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement,surfaceToBody[1],targetId,dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
           # intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray,surfaceToBody[1])
            assert (numEdges == 8)
            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray,surfaceToBody[1])
            assert (numfaces == 4)
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices,surfaceToBody[1])
            assert (numVertices == 5)
            if(4==numfaces and numEdges ==8 and numVertices ==5):
                return True
 
    return False
'''
primitiveToSmartSolid convert bspline surface to body
    bodyId      : Primitive element Id to convert into smart body
'''
def primitiveToSmartSolid(bodyId):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    targetId = EditElementHandle(bodyId,dgnModel)
    solidPrimitive = ISolidPrimitiveQuery.ElementToSolidPrimitive(targetId)
    primitiveToBody = SolidUtil.Create.BodyFromSolidPrimitive(solidPrimitive ,dgnModel)
    intersectElement = EditElementHandle()
    ret = SolidUtil.Convert.BodyToElement(intersectElement,primitiveToBody[1] ,targetId,dgnModel)
    if(BentleyStatus.eSUCCESS == ret):
        #intersectElement.AddToModel()
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray,primitiveToBody[1])
        assert (numEdges == 12)
        subFaceArray  = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray,primitiveToBody[1])
        assert (numfaces == 6)
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices,primitiveToBody[1])
        assert (numVertices == 8)
        if(6==numfaces and numEdges ==12 and numVertices ==8):
            return True
        return True
    return False

'''
Prerequisite: Open MSPythonSamples\data\CutToolSample.dgn  
'''
#main
if __name__ == "__main__":
    
    debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
    print("Waiting for debugger attach")
    debugpy.wait_for_client()
    debugpy.breakpoint()

    #highlight all the elements with type 
    solidId = 1401
    profileId = 1408
    if(True != imprintSolidUsingProfile(solidId, profileId)):
        print("Imprint operation failed")
    if(True != sweepBody(1441)):
         print("Sweep operation failed")
    if(True != spinBody(1442)):
        print("Spin operation failed")
    if(True != thickenSheet(1441,2.0,2.0)):
        print("thicken operation failed")
    if(True != blendEdges(1401,0.5)):
        print("blend operation failed")
    if(True != chamferEdges(1401)):
        print("Chamfer operation failed")
    if(True != BooleanIntersect(1554,1556,1558)):
        print("Boolean intersection operation failed")
    if(True != BooleanSubstraction(1711,1707,1709)):
        print("Boolean Subtraction operation failed")
    if(True != BooleanUnion(1754,1758,1756,1760)):
        print("Boolean Union operation failed")
    if(True != BooleanCut(solidId, profileId)):
        print("Cut operation failed")
    if(True != emboss(solidId, profileId)):
        print("Emboss operation failed")
    if(True != offsetFaces(solidId,2.0)):
        print("Offset operation failed")
    if(True != TransformFaces(solidId,2.0)):
       print("Offset operation failed")
    if(True != offsetThroughHole(solidId,2.0)):
       print("Offset operation failed")
    if(True != BodyfromSweep(1442,1443)):
       print("Sweep operation failed")
    if(True != LoftBody(2031,2034,2033)):
       print("Loft operation failed")
    if(True != extrusionToBody(2121,1442)):
       print("Extrusion to body operation failed")
    if(True != bSplineSurfaceToBody(2166)):
       print("Bspline surface to body operation failed")
    if(True != primitiveToSmartSolid(2190)):
       print("Primitive to smart body operation failed")


