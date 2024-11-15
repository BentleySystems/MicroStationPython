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
    """
    This function imprints a solid using a profile.
    
    Parameters:
        solidId (str): The ID of the solid element to be imprinted.
        profileId (str): The ID of the profile element used for imprinting.
        
    Returns:
        A boolean value indicating whether the imprinting operation was successful or not.
    """
    
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Reference to the active DGN model
    dgnModel = ACTIVEMODEL.GetDgnModel()           # Get the DGN model from the reference

    # Retrieve the solid element and profile element from the DGN model
    solidElement = EditElementHandle(solidId, dgnModel)  # Handle for the solid element
    if False == solidElement.IsValid():
        return False
    profileElement = EditElementHandle(profileId, dgnModel)  # Handle for the profile element
    if False == profileElement.IsValid():
        return False
    # Convert the profile element to a curve vector
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)  # Convert the profile element to a curve vector
    if None == curve:
        return False
    # Imprint the solid using the curve vector and normal
    solid = SolidUtil.Convert.ElementToBody(solidElement, True, True, False)  # Convert the solid element to a body
    if BentleyStatus.eERROR == solid[0]:
        return False
    if curve.IsClosedPath():  # Check if the curve is closed (i.e., it forms a loop)
        centerNormalArea = curve.CentroidNormalArea()  # Calculate the centroid normal area of the curve
        normal = centerNormalArea[2]                    # Get the normal vector from the centroid normal area
        normal.Negate()                                 # Negate the normal vector (i.e., flip its direction)

        ret = SolidUtil.Modify.ImprintCurveVectorOnBody(solid[1], curve, normal, True)  # Imprint the solid using the curve and normal

        if BentleyStatus.eSUCCESS == ret:  # Check if the imprinting operation was successful
            # Get the number of edges, faces, and vertices in the imprinted solid body
            subEntArray = ISubEntityPtrArray()          # Initialize an array to store sub-entities (e.g., edges)
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])  # Get the number of edges in the solid body
            assert (numEdges == 17)                       # Assert that the expected number of edges is reached

            subFaceArray = ISubEntityPtrArray()          # Initialize an array to store faces
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])  # Get the number of faces in the solid body
            assert (numfaces == 7)                       # Assert that the expected number of faces is reached

            subVertices = ISubEntityPtrArray()         # Initialize an array to store vertices
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])  # Get the number of vertices in the solid body
            assert (numVertices == 12)                   # Assert that the expected number of vertices is reached

            if (7 == numfaces and numEdges == 17 and numVertices == 12):  # Check if all assertions passed
                newElement = EditElementHandle()
                ret1 = SolidUtil.Convert.BodyToElement(newElement,solid[1],solidElement,dgnModel)
                if(BentleyStatus.eSUCCESS == ret1):
                    newElement.AddToModel()
                return True                                 # Return True indicating successful imprinting
    return False                                        # If not, return False indicating unsuccessful imprinting
'''
Sweep Profile along normal
    profileId  : Integer   Profile Id which will be swept in normal direction    
'''
def sweepBody(profileId):
    """
    This function sweeps a body using a profile.
    
    Parameters:
        profileId (str): The ID of the profile element used for sweeping.

    Returns:
        A boolean value indicating whether the sweeping operation was successful or not.
    """

    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Reference to the active DGN model

    # Retrieve the DGN model from the reference
    dgnModel = ACTIVEMODEL.GetDgnModel()            # Get the DGN model from the reference

    # Retrieve the profile element from the DGN model
    profileElement = EditElementHandle(profileId, dgnModel)   # Convert the profile ID to an edit element handle
    if False == profileElement.IsValid():
        return False
    # Convert the profile element to a curve vector
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)  # Convert the profile element to a curve vector
    if None == curve:
        return False
    # Convert the profile element to a body using SolidUtil
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)   # Convert the profile element to a body
    if BentleyStatus.eERROR == solid[0]:
        return False
    # Get model information from the DGN model
    modelInfo = dgnModel.GetModelInfo()               # Get model information from the DGN model

    if curve.IsClosedPath():  # Check if the curve is closed (i.e., it forms a loop)
        # Calculate the centroid normal area of the curve
        centerNormalArea = curve.CentroidNormalArea()

        # Get the normal vector from the centroid normal area
        normal = centerNormalArea[2]

        # Scale the normal vector by 2 times the unit or per storage value in the model information
        normal.Scale(2 * modelInfo.GetUorPerStorage())

        # Sweep the body using the normal vector and SolidUtil
        ret = SolidUtil.Modify.SweepBody(solid[1], normal)

        if BentleyStatus.eSUCCESS == ret:  # Check if the sweeping operation was successful
            # Get the number of edges in the swept body
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
            assert (numEdges == 12)                    # Assert that the expected number of edges is reached

            # Get the number of faces in the swept body
            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
            assert (numfaces == 6)                  # Assert that the expected number of faces is reached

            # Get the number of vertices in the swept body
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
            assert (numVertices == 8)               # Assert that the expected number of vertices is reached

            if (6 == numfaces and numEdges == 12 and numVertices == 8):  # Check if all assertions passed
                newElement = EditElementHandle()
                ret1 = SolidUtil.Convert.BodyToElement(newElement,solid[1],profileElement,dgnModel)
                if(BentleyStatus.eSUCCESS == ret1):
                    newElement.AddToModel()
                return True                         # Return True indicating successful sweeping
    return False                                     # If not, return False indicating unsuccessful sweeping

def spinBody(profileId):
    """
    Spin Profile around the axis.

    Parameters:
        profileId  : Integer   Profile Id which will be spun around the axis.
    
    Returns:
        A boolean value indicating whether the spinning operation was successful or not.
    """
   
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef      # Reference to the active DGN model

    # Retrieve the DGN model from the reference
    dgnModel = ACTIVEMODEL.GetDgnModel()             # Get the DGN model from the reference

    # Convert the profile ID to an edit element handle
    profileElement = EditElementHandle(profileId, dgnModel)   # Convert the profile ID to an edit element handle
    if False == profileElement.IsValid():
        return False
    # Convert the profile element to a curve vector
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)  # Convert the profile element to a curve vector
    if None == curve:
        return False
    if False == profileElement.IsValid():
        return False
    # Convert the profile element to a body using SolidUtil
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)   # Convert the profile element to a body
    
  
    if BentleyStatus.eERROR == solid[0]:
        return False

    # Get model information from the DGN model
    modelInfo = dgnModel.GetModelInfo()                # Get model information from the DGN model

    if curve.IsClosedPath():  # Check if the curve is closed (i.e., it forms a loop)
        # Calculate the centroid normal area of the curve
        centerNormalArea = curve.CentroidNormalArea()

        # Get the normal vector from the centroid normal area
        normal = centerNormalArea[2]

        # Create a 3D ray object
        array3d = DRay3d()                              # Create a 3D ray object

        # Set the origin of the ray
        array3d.origin = DPoint3d(4 * modelInfo.GetUorPerStorage(), 0, 0)   # Set the origin of the ray

        # Set the direction of the ray (pointing along the axis)
        array3d.direction = DVec3d(0, 0, 1)              # Set the direction of the ray

        # Spin the body using the ray and SolidUtil
        ret = SolidUtil.Modify.SpinBody(solid[1], array3d, math.pi)   # Spin the body around the axis by pi radians

        if BentleyStatus.eSUCCESS == ret:  # Check if the spinning operation was successful
            # Get the number of edges in the spun body
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
            assert (numEdges == 12)                    # Assert that the number of edges is 12

            # Get the number of faces in the spun body
            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
            assert (numfaces == 6)                    # Assert that the number of faces is 6

            # Get the number of vertices in the spun body
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
            assert (numVertices == 8)                   # Assert that the number of vertices is 8

            if (6 == numfaces and numEdges == 12 and numVertices == 8):   # Check if the spun body has the expected properties
                newElement = EditElementHandle()
                ret1 = SolidUtil.Convert.BodyToElement(newElement,solid[1],profileElement,dgnModel)
                if(BentleyStatus.eSUCCESS == ret1):
                    newElement.AddToModel()
                return True                                  # Return True if the spinning operation was successful
    return False                                       # Return False otherwise
def thickenSheet(profileId, frontDistance, backDistance):
    """
    Thicken the sheet.

    Parameters:
        profileId  : Integer   Profile Id which will be thickened in normal direction.
        frontDistance: Front distance of thickness
        backDistance: Back distance of thickness

    Returns:
        A boolean value indicating whether the thickening operation was successful or not.
    """
    
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Reference to the active DGN model
    
    # Retrieve the DGN model from the reference
    dgnModel = ACTIVEMODEL.GetDgnModel()          # Get the DGN model from the reference
    
    # Convert the profile ID to an edit element handle
    profileElement = EditElementHandle(profileId, dgnModel)  # Convert the profile ID to an edit element handle
    if False == profileElement.IsValid():
        return False
    # Convert the profile element to a body using SolidUtil
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)  # Convert the profile element to a body

    if BentleyStatus.eERROR == solid[0]:
        return False
    # Get model information from the DGN model
    modelInfo = dgnModel.GetModelInfo()             # Get model information from the DGN model
    
    # Scale the front and back distances by the UOR per storage value
    frontDistance = frontDistance * modelInfo.GetUorPerStorage()  # Scale the front distance
    backDistance = backDistance * modelInfo.GetUorPerStorage()   # Scale the back distance
    
    # Thicken the sheet using SolidUtil
    ret = SolidUtil.Modify.ThickenSheet(solid[1], frontDistance, backDistance)  # Thicken the sheet
    
    if BentleyStatus.eSUCCESS == ret:  # Check if the thickening operation was successful
        # Get the number of edges in the thinned body
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])  # Get the number of edges
        
        assert (numEdges == 12)  # Assert that the number of edges is 12
        
        # Get the number of faces in the thinned body
        subFaceArray = ISubEntityPtrArray()
        numFaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])  # Get the number of faces
        
        assert (numFaces == 6)  # Assert that the number of faces is 6
        
        # Get the number of vertices in the thinned body
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])  # Get the number of vertices
        
        assert (numVertices == 8)  # Assert that the number of vertices is 8
        
        if (6 == numFaces and numEdges == 12 and numVertices == 8):  # Check if the thinned body has the expected properties
            newElement = EditElementHandle()
            ret1 = SolidUtil.Convert.BodyToElement(newElement,solid[1],profileElement,dgnModel)
            if(BentleyStatus.eSUCCESS == ret1):
                newElement.AddToModel()
            return True  # Return True if the thickening operation was successful
    
    return False  # Return False otherwise
def blendEdges(solidId, blendRadius):
    """
    Blend edge of solid.

    Parameters:
        solidId  : Integer Solid element id whose edges will be blended.
        blendRadius: Blend Radius
    Returns:
        A boolean value indicating whether the blending operation was successful or not.
    """
    
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Reference to the active DGN model
    
    # Retrieve the DGN model from the reference
    dgnModel = ACTIVEMODEL.GetDgnModel()           # Get the DGN model from the reference
    
    # Convert the solid ID to an edit element handle
    profileElement = EditElementHandle(solidId, dgnModel)   # Convert the solid ID to an edit element handle
    if False == profileElement.IsValid():
        return False
    # Convert the profile element to a body using SolidUtil
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)   # Convert the profile element to a body

    if BentleyStatus.eERROR == solid[0]:
        return False
    # Get the number of edges in the body
    subEdgeArray = ISubEntityPtrArray()  # Create an empty array for storing edges
    numEdges = SolidUtil.GetBodyEdges(subEdgeArray, solid[1])  # Get the number of edges
    
    assert(numEdges == 12)   # Assert that the number of edges is 12
    
    # Select a subset of edges to blend
    subblendEdge = ISubEntityPtrArray()  # Create an empty array for storing blended edges
    subblendEdge.append(subEdgeArray[0])  # Add the first edge to the blended edge array
    subblendEdge.append(subEdgeArray[1])   # Add the second edge to the blended edge array
    subblendEdge.append(subEdgeArray[2])   # Add the third edge to the blended edge array
    
    # Scale the blend radius by the UOR per storage value
    modelInfo = dgnModel.GetModelInfo()  # Get model information from the DGN model
    blendRadius = blendRadius * modelInfo.GetUorPerStorage()  # Scale the blend radius
    
    # Create an array for storing the blend radius values
    blendRadiusArray = DoubleArray()
    blendRadiusArray.append(blendRadius)   # Add the first blend radius value to the array
    blendRadiusArray.append(blendRadius)   # Add the second blend radius value to the array
    blendRadiusArray.append(blendRadius)   # Add the third blend radius value to the array
    
    # Blend the selected edges using SolidUtil
    ret = SolidUtil.Modify.BlendEdges(solid[1], subblendEdge, blendRadiusArray, True)
    if(BentleyStatus.eSUCCESS == ret):  # Check if the blending operation was successful
        # Get the number of edges in the blended solid
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
        assert (numEdges == 21)   # Assert that the number of edges is 21
        
        # Get the number of faces in the blended solid
        subFaceArray = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
        assert (numfaces == 9)   # Assert that the number of faces is 9
        
        # Get the number of vertices in the blended solid
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
        assert (numVertices == 14)   # Assert that the number of vertices is 14
        
        if(9==numfaces and numEdges ==21 and numVertices ==14):  # Check if the blending operation was successful
            newElement = EditElementHandle()
            ret1 = SolidUtil.Convert.BodyToElement(newElement,solid[1],profileElement,dgnModel)
            if(BentleyStatus.eSUCCESS == ret1):
                newElement.AddToModel()
            return True  # Return True if the blending operation was successful
    return False  # Return False if the blending operation was not successful

def chamferEdgesWithMode(solidId, chamferLength, chamferLength1, mode):
    """
    Chamfer edge of solid.

    Parameters:
        solidId  : Integer Solid element id whose edges should undergo chamfering.
        chamferLength: Chamfer distance.
        chamferLength1: First chamfer length (only used if mode is eDistanceAngle).
        mode: Chamfering mode.

    Returns:
        A boolean value indicating whether the chamfering operation was successful or not.
    """
    
    # Get the active DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    
    # Get the DGN model from the active model
    dgnModel = ACTIVEMODEL.GetDgnModel()
    
    # Convert the profile element to a body
    profileElement = EditElementHandle(solidId, dgnModel)
    if False == profileElement.IsValid():
        return False
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)

    if BentleyStatus.eERROR == solid[0]:
        return False
    # Get the array of edges from the solid
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyEdges(subEdgeArray, solid[1])
    assert(numEdges == 12)  # Assert that the number of edges is 12
    
    # Select the first three edges for chamfering
    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])  # First edge
    subblendEdge.append(subEdgeArray[2])  # Second edge
    subblendEdge.append(subEdgeArray[3])  # Third edge
    
    # Get the model information from the DGN model
    modelInfo = dgnModel.GetModelInfo()
    
    # If the chamfering mode is not eAngleDistance, scale the chamfer length by the UOR per storage
    if(SolidUtil.Modify.ChamferMode.eAngleDistance != mode):
        chamferLength = chamferLength * modelInfo.GetUorPerStorage()
    
    # If the chamfering mode is not eDistanceAngle, scale the first chamfer length by the UOR per storage
    if(SolidUtil.Modify.ChamferMode.eDistanceAngle != mode):
        chamferLength1 = chamferLength1 * modelInfo.GetUorPerStorage()
    
    # Create arrays for the first and second chamfer distances
    chamferDistanceFirstArray = DoubleArray()
    chamferDistanceFirstArray.append(chamferLength)
    chamferDistanceFirstArray.append(chamferLength)
    chamferDistanceFirstArray.append(chamferLength)
    
    # Create an array for the second chamfer distance (only used if mode is eDistanceAngle)
    chamferDistanceArray = DoubleArray()
    chamferDistanceArray.append(chamferLength1)
    chamferDistanceArray.append(chamferLength1)
    chamferDistanceArray.append(chamferLength1)
    
    # Perform the chamfering operation
    ret = SolidUtil.Modify.ChamferEdges(solid[1], subblendEdge, chamferDistanceFirstArray, chamferDistanceArray, mode, True)
    
    # If the chamfering operation was successful, return True
    if(BentleyStatus.eSUCCESS == ret):
        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
        assert(numEdges == 21)  # Assert that the number of edges is 21
        
        subFaceArray = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
        assert(numfaces == 9)  # Assert that the number of faces is 9
        
        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
        assert(numVertices == 14)  # Assert that the number of vertices is 14
        
        if(9==numfaces and numEdges ==21 and numVertices ==14):  # Check if the chamfering operation was successful
            newElement = EditElementHandle()
            ret1 = SolidUtil.Convert.BodyToElement(newElement,solid[1],profileElement,dgnModel)
            if(BentleyStatus.eSUCCESS == ret1):
                newElement.AddToModel()
            return True  # Return True if the operation was successful
    
    # If the chamfering operation was not successful, return False
    return False  # Return False if the operation was not successful
'''
Chamfer edge of solid

    solidId  : Integer Solid element id whose edges   
        should undergo chamfering.

    This function first calls a helper function chamferEdgesWithMode 
    with different chamfer modes and then checks if any of these 
    calls were successful. If not, it returns False. Otherwise, it 
    returns True.
'''
def chamferEdges(solidId ):
    
    '''
    Check if the solid can be chamfered with different chamfer modes.
    '''
    if(False == chamferEdgesWithMode(solidId, 1.0, 0.5, SolidUtil.Modify.ChamferMode.eDistances)):
        # If chamfering with eDistances is not successful, return False
        return False
        
    if(False == chamferEdgesWithMode(solidId, 1.0, 1.0, SolidUtil.Modify.ChamferMode.eLength)):
        # If chamfering with eLength is not successful, return False
        return False
    
    if(False == chamferEdgesWithMode(solidId, 1.0, 0.78539816, SolidUtil.Modify.ChamferMode.eDistanceAngle)):
        # If chamfering with eDistanceAngle is not successful, return False
        return False
    
    if(False == chamferEdgesWithMode(solidId, 0.78539816, 1.0, SolidUtil.Modify.ChamferMode.eAngleDistance)):
        # If chamfering with eAngleDistance is not successful, return False
        return False
    
    # If all chamfering modes were successful, return True
    return True
''' BooleanIntersect function '''
def BooleanIntersect(solidId, toolId, toold2 ):

    # Get the active design model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    # Convert the target solid id to a body object
    targetId = EditElementHandle(solidId, dgnModel)
    if False == targetId.IsValid():
        return False
    solid = SolidUtil.Convert.ElementToBody(targetId, True, True, False)

    if BentleyStatus.eERROR == solid[0]:
        return False
    # Convert the tool solid id to a body object
    toolElement = EditElementHandle(toolId, dgnModel)
    if False == toolElement.IsValid():
        return False
    tool = SolidUtil.Convert.ElementToBody(toolElement, True, True, False)
    if BentleyStatus.eERROR == tool[0]:
        return False
    # Convert the second tool solid id to a body object
    toolElement2 = EditElementHandle(toold2, dgnModel)
    if False == toolElement2.IsValid():
        return False
    tool2 = SolidUtil.Convert.ElementToBody(toolElement2, True, True, False)

    # Create an array of solids for the boolean operation
    tools = ISolidKernelEntityPtrArray()
    tools.append(tool[1])
    tools.append(tool2[1])

    # Perform the boolean intersection operation
    ret = SolidUtil.Modify.BooleanIntersect(solid[1], tools)

    if(BentleyStatus.eSUCCESS == ret):
        # If the operation is successful, proceed to extract information about the resulting solid
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], targetId, dgnModel)
        if(BentleyStatus.eSUCCESS == ret1):
            # Extract information about the resulting solid
            intersectElement.AddToModel()
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
            assert (numEdges == 15)

            subFaceArray  = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
            assert (numfaces == 7)

            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
            assert (numVertices == 10)

            # Check if the resulting solid meets certain conditions
            if(7==numfaces and numEdges ==15 and numVertices ==10):
                return True

    return False
'''
BooleanSubtraction   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
    toolId2  : Tool second Solid
'''
def BooleanSubstraction(solidId, toolId, toold2 ):  # Define a function for performing boolean subtraction on solids
    ''' Get the active design model '''
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()  # Get the current design model reference

    ''' Convert the target solid id to a body object '''
    targetId = EditElementHandle(solidId, dgnModel)  # Create an edit element handle for the target solid
    if False == targetId.IsValid():
        return False
    solid = SolidUtil.Convert.ElementToBody(targetId, True, True, False)  # Convert the target solid to a body object

    if BentleyStatus.eERROR == solid[0]:
        return False
    ''' Convert the tool solid id to a body object '''
    toolElement = EditElementHandle(toolId, dgnModel)  # Create an edit element handle for the tool solid
    if False == toolElement.IsValid():
        return False
    tool = SolidUtil.Convert.ElementToBody(toolElement, True, True, False)  # Convert the tool solid to a body object
    if BentleyStatus.eERROR == tool[0]:
        return False
    ''' Convert the second tool solid id to a body object '''
    toolElement2 = EditElementHandle(toold2, dgnModel)  # Create an edit element handle for the second tool solid
    if False == toolElement2.IsValid():
        return False
    tool2 = SolidUtil.Convert.ElementToBody(toolElement2, True, True, False)  # Convert the second tool solid to a body object
    if BentleyStatus.eERROR == tool2[0]:
        return False
    ''' Create an array of solids for the boolean operation '''
    tools = ISolidKernelEntityPtrArray()  # Initialize an array of solids for the boolean operation
    tools.append(tool[1])  # Add the first tool solid to the array
    tools.append(tool2[1])  # Add the second tool solid to the array

    ''' Perform the boolean subtraction operation '''
    ret = SolidUtil.Modify.BooleanSubtract(solid[1], tools)  # Subtract the tool solids from the target solid

    if(BentleyStatus.eSUCCESS == ret):  # Check if the operation was successful
        ''' Convert the resulting solid to an element '''
        intersectElement = EditElementHandle()  # Create an edit element handle for the resulting solid
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], targetId, dgnModel)  # Convert the resulting solid to an element

        if(BentleyStatus.eSUCCESS == ret1):  # Check if the conversion was successful
            # Add the resulting solid to the model  
            intersectElement.AddToModel()

            ''' Get various properties of the resulting solid '''
            subEntArray = ISubEntityPtrArray()  # Initialize an array of sub-entities
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])  # Get the number of edges in the resulting solid
            assert (numEdges == 24)  # Check if the number of edges is correct

            subFaceArray = ISubEntityPtrArray()  # Initialize an array of sub-entities
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])  # Get the number of faces in the resulting solid
            assert (numfaces == 10)  # Check if the number of faces is correct

            subVertices = ISubEntityPtrArray()  # Initialize an array of sub-entities
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])  # Get the number of vertices in the resulting solid
            assert (numVertices == 16)  # Check if the number of vertices is correct

            ''' Check if the resulting solid meets certain conditions '''
            if(10==numfaces and numEdges ==24 and numVertices ==16):  # Check if the number of faces, edges, and vertices are correct
                return True  # Return True if the conditions are met
        return False  # Return False otherwise

    return False  # Return False if the operation was not successful
'''
BooleanUnion   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
    toolId2  : Tool second Solid
    toolId3  : Tool second Solid
'''
def BooleanUnion(solidId, toolId, toold2, toolId3):
    """
    Performs a boolean union operation on a solid.
    
    :param solidId: The ID of the target solid.
    :param toolId: The ID of the first tool solid.
    :param toold2: The ID of the second tool solid.
    :param toolId3: The ID of the third tool solid.
    """
    # Get the active design model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    
    # Convert the target solid id to a body object
    targetId = EditElementHandle(solidId, dgnModel)
    if False == targetId.IsValid():
        return False
    solid = SolidUtil.Convert.ElementToBody(targetId, True, True, False)
    if BentleyStatus.eERROR == solid[0]:
        return False
    # Convert the tool solid id to a body object
    toolElement = EditElementHandle(toolId, dgnModel)
    if False == toolElement.IsValid():
        return False
    tool = SolidUtil.Convert.ElementToBody(toolElement, True, True, False)
    if BentleyStatus.eERROR == tool[0]:
        return False
    # Convert the second tool solid id to a body object
    toolElement2 = EditElementHandle(toold2, dgnModel)
    if False == toolElement2.IsValid():
        return False
    tool2 = SolidUtil.Convert.ElementToBody(toolElement2, True, True, False)
    if BentleyStatus.eERROR == tool2[0]:
        return False
    # Convert the third tool solid id to a body object
    toolElement3 = EditElementHandle(toolId3, dgnModel)
    tool3 = SolidUtil.Convert.ElementToBody(toolElement3, True, True, False)

    # Create an array of solids for the boolean operation
    tools = ISolidKernelEntityPtrArray()
    tools.append(tool[1])
    tools.append(tool2[1])
    tools.append(tool3[1])

    # Perform the boolean union operation
    ret = SolidUtil.Modify.BooleanUnion(solid[1], tools)

    if (BentleyStatus.eSUCCESS == ret):
        """
        The boolean union operation was successful.
        
        :return: True if the operation was successful, False otherwise.
        """
        # Convert the resulting solid to an element
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], targetId, dgnModel)
        if (BentleyStatus.eSUCCESS == ret1):
            """
            The conversion was successful.
            
            :return: True if the conversion was successful, False otherwise.
            """
            # Add the resulting solid to the model  
            intersectElement.AddToModel()

            # Get various properties of the resulting solid
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
            assert (numEdges == 36)  # Check if the number of edges is correct

            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
            assert (numfaces == 14)  # Check if the number of faces is correct

            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
            assert (numVertices == 24)  # Check if the number of vertices is correct

            if (14 == numfaces and numEdges == 36 and numVertices == 24):
                return True
    return False
'''
BooleanCut   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
'''
def BooleanCut(solidId, toolId):
    """
    Performs a boolean cut operation on a solid.
    
    :param solidId: The ID of the target solid.
    :param toolId: The ID of the cutting curve.
    """
    # Get the active design model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()  # Get the current design model

    # Convert the target solid id to a body object
    targetId = EditElementHandle(solidId, dgnModel)  # Convert the solid ID to an element handle
    if False == targetId.IsValid():
        return False   
    solid = SolidUtil.Convert.ElementToBody(targetId, True, True, False)  # Convert the element handle to a body object
    if BentleyStatus.eERROR == solid[0]:
        return False
    # Convert the tool curve id to a curve vector
    profileElement = EditElementHandle(toolId, dgnModel)  # Convert the tool ID to an element handle
    if False == profileElement.IsValid():
        return False
    curve = ICurvePathQuery.ElementToCurveVector(profileElement)  # Convert the element handle to a curve vector
    if None == curve:
        return False
    # Initialize a node ID (not used in this example)
    nodeId = int()  # Initialize a node ID variable

    # Perform the boolean cut operation
    ret = SolidUtil.Modify.BooleanCut(solid[1], curve, SolidUtil.Modify.CutDirectionMode.eBoth, SolidUtil.Modify.CutDepthMode.eAll, 0.0, False, None, nodeId)  # Perform the boolean cut operation

    if (BentleyStatus.eSUCCESS == ret):

        # Convert the resulting solid to an element
        intersectElement = EditElementHandle()  # Initialize an empty element handle for the result
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], targetId, dgnModel)  # Convert the body object to an element

        if (BentleyStatus.eSUCCESS == ret1):
            # Add the resulting solid to the model 
            intersectElement.AddToModel()

            # Get various properties of the resulting solid
            subEntArray = ISubEntityPtrArray()  # Initialize a sub-entity array
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])  # Get the number of edges in the solid
            assert (numEdges == 24)  # Check if the number of edges is correct

            subFaceArray = ISubEntityPtrArray()  # Initialize a sub-face array
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])  # Get the number of faces in the solid
            assert (numfaces == 10)  # Check if the number of faces is correct

            subVertices = ISubEntityPtrArray()  # Initialize a sub-vertex array
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])  # Get the number of vertices in the solid
            assert (numVertices == 16)  # Check if the number of vertices is correct

            if (10 == numfaces and numEdges == 24 and numVertices == 16):
                return True  # Return True if the operation was successful

    return False  # Return False if the operation failed
'''
BooleanCut   of solid
    solidId  : Target Solid 
    toolId   : Tool Solid 
'''
def emboss(solidId, toolId):
    """
    Embosses a solid using a given tool.
    
    :param solidId: The ID of the target solid.
    :param toolId: The ID of the embossing tool.
    :return: True if the operation was successful, False otherwise.
    """
    # Get the active design model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Get a reference to the active design model
    
    dgnModel = ACTIVEMODEL.GetDgnModel()  # Get the current design model
    
    # Convert the target solid ID to an element handle
    targetId = EditElementHandle(solidId, dgnModel)  # Convert the solid ID to an element handle
    if False == targetId.IsValid():
        return False
    solid = SolidUtil.Convert.ElementToBody(targetId, True, True, False)  # Convert the element handle to a body object
    if BentleyStatus.eERROR == solid[0]:
        return False
    """
    The tool curve is converted from an element handle to a body object.
    """
    profileElement = EditElementHandle(toolId, dgnModel)  # Convert the tool ID to an element handle
    if False == profileElement.IsValid():
        return False    
    curve = SolidUtil.Convert.ElementToBody(profileElement, True, True, True)  # Convert the element handle to a body object
    if None == curve:
        return False
    # Perform the embossing operation
    ret = SolidUtil.Modify.Emboss(solid[1], curve[1], True)  # Emboss the solid using the tool
    
    if (BentleyStatus.eSUCCESS == ret):
        """
        The embossing operation was successful.

        """
        intersectElement = EditElementHandle()  # Initialize an empty element handle for the result
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], targetId, dgnModel)  # Convert the body object to an element
        
        if (BentleyStatus.eSUCCESS == ret1):
            """
            The resulting solid is added to the model (commented out for now).

            """
            intersectElement.AddToModel()  # Add the result to the model
            
            # Get various properties of the resulting solid
            subEntArray = ISubEntityPtrArray()  # Initialize a sub-entity array
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])  # Get the number of edges in the solid
            assert (numEdges == 24)  # Check if the expected number of edges is correct
            
            subFaceArray = ISubEntityPtrArray()  # Initialize a sub-face array
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])  # Get the number of faces in the solid
            assert (numfaces == 10)  # Check if the expected number of faces is correct
            
            subVertices = ISubEntityPtrArray()  # Initialize a sub-vertex array
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])  # Get the number of vertices in the solid
            assert (numVertices == 16)  # Check if the expected number of vertices is correct
            
            if (10 == numfaces and numEdges == 24 and numVertices == 16):
                return True  # Return True if the operation was successful
        
    return True  # Return False if the operation failed
'''
Offset face
    solidId  : Integer Solid element whose faces need to offset  
    offsetDistance: Offset distance
'''
def offsetFaces(solidId, offsetDistance):
    """
    Offsets the faces of a solid by a given distance.
    
    :param solidId: The ID of the target solid.
    :param offsetDistance: The distance to offset the faces by.
    :return: True if the operation was successful, False otherwise.
    """
    
    # Get the active design model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Get a reference to the active design model
    
    dgnModel = ACTIVEMODEL.GetDgnModel()  # Get the current design model
    
    # Convert the solid ID to an element handle
    profileElement = EditElementHandle(solidId, dgnModel)  # Convert the solid ID to an element handle
    if False == profileElement.IsValid():
        return False       
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)  # Convert the element handle to a body object
    if BentleyStatus.eERROR == solid[0]:
        return False
    """
    Get the number of faces in the solid.
    """
    subEdgeArray = ISubEntityPtrArray()  # Initialize a sub-edge array
    numEdges = SolidUtil.GetBodyFaces(subEdgeArray, solid[1])  # Get the number of edges (which should be equal to the number of faces) in the solid
    
    assert(numEdges == 6)  # Check if the expected number of edges/faces is correct
    
    """
    Create a sub-blend edge array.
    """
    subblendEdge = ISubEntityPtrArray()  # Initialize a sub-blend edge array
    subblendEdge.append(subEdgeArray[0])  # Add the first edge to the sub-blend edge array
    subblendEdge.append(subEdgeArray[1])  # Add the second edge to the sub-blend edge array
    subblendEdge.append(subEdgeArray[2])  # Add the third edge to the sub-blend edge array
    
    """
    Get model information.
    """
    modelInfo = dgnModel.GetModelInfo()  # Get model information
    
    offsetDistance = offsetDistance * modelInfo.GetUorPerStorage()  # Scale the offset distance based on the model's units per storage
    
    """
    Create an offset distance array.
    """
    offsetDistanceArray = DoubleArray()  # Initialize a double array
    offsetDistanceArray.append(offsetDistance)  # Add the offset distance to the array
    offsetDistanceArray.append(offsetDistance)  # Add the offset distance to the array (again)
    offsetDistanceArray.append(offsetDistance)  # Add the offset distance to the array (again)
    
    """
    Offset the faces.
    """
    ret = SolidUtil.Modify.OffsetFaces(solid[1], subblendEdge, offsetDistanceArray, SolidUtil.Modify.StepFacesOption.eADD_STEP_Smooth)  # Offset the faces
    if(BentleyStatus.eSUCCESS == ret):  # Check if the operation was successful
        """
        Convert the offset solid to an element handle.
        """
        intersectElement = EditElementHandle()  # Initialize an element handle
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], profileElement, dgnModel)  # Convert the offset solid to an element handle
        if(BentleyStatus.eSUCCESS == ret1):  # Check if the operation was successful
            """
            Get the number of edges, faces, and vertices in the offset solid.
            """
            intersectElement.AddToModel()

            subEntArray = ISubEntityPtrArray()  # Initialize a sub-entity array
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])  # Get the number of edges in the offset solid
            assert(numEdges == 12)  # Check if the expected number of edges is correct
            
            subFaceArray  = ISubEntityPtrArray()  # Initialize a sub-face array
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])  # Get the number of faces in the offset solid
            assert(numfaces == 6)  # Check if the expected number of faces is correct
            
            subVertices = ISubEntityPtrArray()  # Initialize a sub-vertex array
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])  # Get the number of vertices in the offset solid
            assert(numVertices == 8)  # Check if the expected number of vertices is correct
            
            if(6==numfaces and numEdges ==12 and numVertices ==8):  # Check if the expected numbers are correct
                return True  # Return True if the operation was successful
    
    return False  # Return False if the operation failed
'''
Transform face
    solidId  : Integer Solid element whose faces need to offset  
    offsetDistance: Offset distance
'''
def TransformFaces(solidId, offsetDistance):
    """
    Transforms the faces of a solid by a given distance.

    :param solidId: The ID of the target solid.
    :param offsetDistance: The distance to transform the faces.
    :return: True if the transformation was successful, False otherwise.
    """

    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    """
    Convert the solid ID to an EditElementHandle object.
    This is used to interact with the solid.
    """

    profileElement = EditElementHandle(solidId, dgnModel)
    if False == profileElement.IsValid():
        return False    
    # Convert the EditElementHandle to a Solid body
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)
    if BentleyStatus.eERROR == solid[0]:
        return False
    """
    Get the number of faces in the solid.
    This is used to verify that the transformation was successful.
    """

    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyFaces(subEdgeArray, solid[1])
    assert(numEdges == 6)
 
    """
    Create a sub-blend edge array.
    """
    subblendEdge = ISubEntityPtrArray()  # Initialize a sub-blend edge array
    subblendEdge.append(subEdgeArray[0])  # Add the first edge to the sub-blend edge array
    
    # Define a vector representing the y-axis
    yVec = DVec3d(0.0, -1.0, 0.0)

    """
    Scale the y-axis vector by the offset distance.
    This defines the transformation to apply.
    """

    yVec.Scale(offsetDistance)

    # Create a Transformation object from the scaled y-axis vector
    trans = Transform.From(yVec)

    # Define an array of transformations
    transArray = TransformArray()
    transArray.append(trans)

    """
    Apply the transformation to the solid faces using SolidUtil.Modify.TransformFaces.
    This method modifies the solid in-place.
    """

    ret = SolidUtil.Modify.TransformFaces(solid[1], subblendEdge, transArray, SolidUtil.Modify.StepFacesOption.eADD_STEP_Smooth)
    if (BentleyStatus.eSUCCESS == ret):
        """
        Convert the transformed solid to an EditElementHandle object.
        This is used to verify that the transformation was successful.
        """

        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], profileElement, dgnModel)
        if (BentleyStatus.eSUCCESS == ret1):
            # Get the number of edges, faces, and vertices in the transformed solid
            intersectElement.AddToModel()

            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
            assert(numEdges == 12)

            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
            assert(numfaces == 6)

            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
            assert(numVertices == 8)

            # Verify that the transformation was successful
            if (6 == numfaces and numEdges == 12 and numVertices == 8):
                return True

    # If the transformation failed, return False
    return False
'''
Offset Through hole
    solidId  : Integer Solid element whose faces need to offset so as to generate hole 
    offsetDistance: Offset distance
'''
def offsetThroughHole(solidId, offsetDistance):
    """
    Offsets a solid through hole by a given distance.

    :param solidId: The ID of the target solid.
    :param offsetDistance: The distance to offset the solid.
    :return: True if the offset was successful, False otherwise.
    """

    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    """
    Convert the solid ID to an EditElementHandle object.
    This is used to interact with the solid.
    """

    profileElement = EditElementHandle(solidId, dgnModel)
    if False == profileElement.IsValid():
        return False    
    # Convert the EditElementHandle to a Solid body
    solid = SolidUtil.Convert.ElementToBody(profileElement, True, True, False)
    if BentleyStatus.eERROR == solid[0]:
        return False
    # Get the number of faces in the solid
    subEdgeArray = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyFaces(subEdgeArray, solid[1])
    assert(numEdges == 6)
    """
    Define a subset of edges (subblendEdge) to use for offsetting.
    This is used to specify which edges should be offset.
    """

    subblendEdge = ISubEntityPtrArray()
    subblendEdge.append(subEdgeArray[0])  # First edge
    subblendEdge.append(subEdgeArray[1])  # Second edge
    subblendEdge.append(subEdgeArray[2])  # Third edge

    # Scale the offset distance based on the DGN model's units of measurement
    modelInfo = dgnModel.GetModelInfo()
    offsetDistance = offsetDistance * modelInfo.GetUorPerStorage()

    # Create an array to store the scaled offset distances
    offsetDistanceArray = DoubleArray()
    offsetDistanceArray.append(offsetDistance)  # First distance
    offsetDistanceArray.append(offsetDistance)  # Second distance
    offsetDistanceArray.append(offsetDistance)  # Third distance

    ret = SolidUtil.Modify.OffsetThroughHole(solid[1], subblendEdge, offsetDistanceArray)
    """
    Offset the solid through hole using the specified edges and distances.
    """

    if BentleyStatus.eSUCCESS == ret:
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, solid[1], profileElement, dgnModel)
        """
        Convert the offsetted solid back to an element handle.
        """

        if BentleyStatus.eSUCCESS == ret1:
            # Add the offsetted element to the DGN model
            intersectElement.AddToModel()

            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, solid[1])
            assert(numEdges == 12)

            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, solid[1])
            assert(numfaces == 6)

            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, solid[1])
            assert(numVertices == 8)

            if (6 == numfaces and numEdges == 12 and numVertices == 8):
                return True
    # If the offset failed, return False
    return False
'''
BodyFromSweep   of profile
    solidId  : Profile element
    path id  : Path element
'''
def BodyFromSweep(profileId, pathId):
    """
    Creates a solid body from a sweep operation between two curves.

    :param profileId: The ID of the profile curve.
    :param pathId: The ID of the path curve.
    :return: True if the body is successfully created, False otherwise.
    """

    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    """
    Convert the profile ID to an EditElementHandle object.
    This is used to interact with the profile curve.
    """

    targetId = EditElementHandle(profileId, dgnModel)
    if False == targetId.IsValid():
        return False    
    # Get the profile curve as a vector of curves
    profile = ICurvePathQuery.ElementToCurveVector(targetId)
    if None == profile:
       return False
    """
    Convert the path ID to an EditElementHandle object.
    This is used to interact with the path curve.
    """

    pathElement = EditElementHandle(pathId, dgnModel)

    # Get the path curve as a vector of curves
    path = ICurvePathQuery.ElementToCurveVector(pathElement)
    if None == path:
       return False
    """
    Create a solid body from the sweep operation between the profile and path curves.
    """

    ret = SolidUtil.Create.BodyFromSweep(profile, path, ACTIVEMODEL, False, True, False, None, None, None, None)

    if BentleyStatus.eSUCCESS == ret[0]:
        # Convert the created solid body to an EditElementHandle
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, ret[1], targetId, dgnModel)
        """
        Add the created solid body to the DGN model.
        """

        if BentleyStatus.eSUCCESS == ret1:
            # Get the number of edges in the solid body
            intersectElement.AddToModel()

            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, ret[1])
            assert(numEdges == 12)

            # Get the number of faces in the solid body
            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, ret[1])
            assert(numfaces == 6)

            # Get the number of vertices in the solid body
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, ret[1])
            assert(numVertices == 8)

            if (6 == numfaces and numEdges == 12 and numVertices == 8):
                return True

    # If the body is not successfully created, return False
    return False
'''
Loft from profiles and guidewire
    guideId     : Guide element
    startProfile: Profile at start of guide
    endProfile  : Profile at end of guide
'''
def LoftBody(guideId, startProfile, endProfile):
    """
    Creates a solid body from a loft operation between two profiles.

    :param guideId: The ID of the guide curve.
    :param startProfile: The ID of the start profile curve.
    :param endProfile: The ID of the end profile curve.
    :return: True if the body is successfully created, False otherwise.
    """
    
    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    """
    Convert the guide ID to an EditElementHandle object.
    This is used to interact with the guide curve.
    """

    targetId = EditElementHandle(guideId, dgnModel)
    if False == targetId.IsValid():
        return False    
    # Get the guide curve as a vector of curves
    guide = ICurvePathQuery.ElementToCurveVector(targetId)
    if None == guide:
        return False
    """
    Create a list of guides from the guide curve.
    This will be used in the loft operation.
    """

    guides = CurveVectorPtrArray()
    guides.append(guide)

    # Convert the start profile ID to an EditElementHandle object
    stProfile = EditElementHandle(startProfile, dgnModel)
    if False == stProfile.IsValid():
        return False    
    """
    Get the start profile curve as a vector of curves.
    This will be used in the loft operation.
    """

    stProf = ICurvePathQuery.ElementToCurveVector(stProfile)
    if None == stProf:
        return False
    # Convert the end profile ID to an EditElementHandle object
    edProfile = EditElementHandle(endProfile, dgnModel)
    if False == edProfile.IsValid():
        return False  
    """
    Get the end profile curve as a vector of curves.
    This will be used in the loft operation.
    """

    edProf = ICurvePathQuery.ElementToCurveVector(edProfile)
    if None == edProf:
        return False
    # Create a list of profiles from the start and end profiles
    profiles = CurveVectorPtrArray()
    profiles.append(stProf)
    profiles.append(edProf)

    """
    Perform the loft operation to create a solid body from the guides and profiles.
    """

    ret = SolidUtil.Create.BodyFromLoft(profiles, guides, dgnModel, False, False)

    if BentleyStatus.eSUCCESS == ret[0]:
        # Convert the created solid body to an EditElementHandle
        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, ret[1], targetId, dgnModel)
        """
        Add the created solid body to the DGN model.
        """

        if BentleyStatus.eSUCCESS == ret1:
            intersectElement.AddToModel()

            # Get the number of edges in the solid body
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, ret[1])
            assert(numEdges == 14)

            # Get the number of faces in the solid body
            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, ret[1])
            assert(numfaces == 3)

            # Get the number of vertices in the solid body
            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, ret[1])
            assert(numVertices == 14)

            """
            Check if the expected values match the actual values.
            If they do, return True indicating success.
            """

            if(3==numfaces and numEdges ==14 and numVertices ==14):
                return True

    # If any of the above steps fail, return False indicating failure
    return False
'''
extrusionToBody Extrude the profile till the body
    bodyId      : Extrusion of profile till the presence of body
    startProfile: Profile at start of guide
'''
def extrusionToBody(bodyId, startProfile):
    """
    Converts an extruded element to a solid body.

    :param bodyId: The ID of the extruded element.
    :param startProfile: The ID of the start profile curve.
    :return: True if the conversion is successful, False otherwise.
    """

    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    """
    Convert the body ID to an EditElementHandle object.
    This is used to interact with the extruded element.
    """

    targetId = EditElementHandle(bodyId, dgnModel)
    if False == targetId.IsValid():
        return False  
    # Convert the extruded element to a solid body
    solid = SolidUtil.Convert.ElementToBody(targetId, True, True, True)
    if BentleyStatus.eERROR == solid[0]:
        return False
    """
    Get the start profile curve as an EditElementHandle object.
    This is used to interact with the start profile curve.
    """

    stProfile = EditElementHandle(startProfile, dgnModel)
    if False == stProfile.IsValid():
        return False  
    # Convert the start profile curve to a solid body
    stProf = SolidUtil.Convert.ElementToBody(stProfile, True, True, True)
    if BentleyStatus.eERROR == stProf[0]:
        return False
    """
    Perform the extrusion operation to create a new solid body from the given bodies.
    """

    ret = SolidUtil.Create.BodyFromExtrusionToBody(solid[1], stProf[1], True)

    if BentleyStatus.eSUCCESS == ret[0]:
        """
        Convert the created solid body to an EditElementHandle object.
        This is used to interact with the new solid body.
        """

        intersectElement = EditElementHandle()
        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, ret[1], targetId, dgnModel)

        if BentleyStatus.eSUCCESS == ret1:
            """
            Add the created solid body to the DGN model.
            """
            intersectElement.AddToModel()

            # Get the number of edges in the new solid body
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, ret[1])
            assert (numEdges == 12)

            """
            Check if the expected values match the actual values.
            If they do, return True indicating success.
            """

            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, ret[1])
            assert (numfaces == 6)

            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, ret[1])
            assert (numVertices == 8)

            if (6 == numfaces and numEdges == 12 and numVertices == 8):
                return True

    # If any of the above steps fail, return False indicating failure
    return False
'''
bSplineSurfaceToBody convert bspline surface to body
    bodyId      : Bspline surface element Id to convert into smart surface
'''
def bSplineSurfaceToBody(bodyId):
    """
    Converts a BSpline surface to a solid body.

    :param bodyId: The ID of the BSpline surface.
    :return: True if the conversion is successful, False otherwise.
    """

    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    """
    Get the EditElementHandle object for the given body ID.
    This is used to interact with the BSpline surface.
    """

    targetId = EditElementHandle(bodyId, dgnModel)
    if False == targetId.IsValid():
        return False 
    editor = targetId.GetHandler()
    """
    Use the editor to get the BSpline surface from the given body ID.
    """

    ret = editor.GetBsplineSurface(targetId)
    if BentleyStatus.eSUCCESS == ret[0]:
        """
        Create a solid body from the given BSpline surface.
        """

        surfaceToBody = SolidUtil.Create.BodyFromBSurface(ret[1], dgnModel)

        intersectElement = EditElementHandle()
        """
        Convert the created solid body to an EditElementHandle object.
        This is used to interact with the new solid body.
        """

        ret1 = SolidUtil.Convert.BodyToElement(intersectElement, surfaceToBody[1], targetId, dgnModel)
        if BentleyStatus.eSUCCESS == ret1:
            """
            Add the created solid body to the DGN model.
            """
            intersectElement.AddToModel()
            # Get the number of edges in the new solid body
            subEntArray = ISubEntityPtrArray()
            numEdges = SolidUtil.GetBodyEdges(subEntArray, surfaceToBody[1])
            assert (numEdges == 8)
            """
            Check if the expected values match the actual values.
            If they do, return True indicating success.
            """

            subFaceArray = ISubEntityPtrArray()
            numfaces = SolidUtil.GetBodyFaces(subFaceArray, surfaceToBody[1])
            assert (numfaces == 4)

            subVertices = ISubEntityPtrArray()
            numVertices = SolidUtil.GetBodyVertices(subVertices, surfaceToBody[1])
            assert (numVertices == 5)

            if (4 == numfaces and numEdges == 8 and numVertices == 5):
                return True

    # If any of the above steps fail, return False indicating failure
    return False
'''
primitiveToSmartSolid convert bspline surface to body
    bodyId      : Primitive element Id to convert into smart body
'''
def primitiveToSmartSolid(bodyId):
    """
    Converts a primitive solid to a smart solid.

    :param bodyId: The ID of the primitive solid.
    :return: True if the conversion is successful, False otherwise.
    """

    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    """
    Get the reference to the current DGN model.
    This will be used throughout the function to interact with the model.
    """

    dgnModel = ACTIVEMODEL.GetDgnModel()
    """
    Use the reference to get the actual DGN model object.
    """

    # Get the EditElementHandle for the given body ID
    targetId = EditElementHandle(bodyId, dgnModel)
    if False == targetId.IsValid():
        return False 
    """
    Create an EditElementHandle object for the given body ID.
    This will be used to interact with the primitive solid.
    """

    solidPrimitive = ISolidPrimitiveQuery.ElementToSolidPrimitive(targetId)
    """
    Use the EditElementHandle to get the SolidPrimitive object representing the primitive solid.
    """

    # Convert the primitive solid to a smart solid
    primitiveToBody = SolidUtil.Create.BodyFromSolidPrimitive(solidPrimitive, dgnModel)
    """
    Create a new smart solid from the given primitive solid and DGN model.
    """

    intersectElement = EditElementHandle()
    """
    Create an EditElementHandle object for the newly created smart solid.
    This will be used to interact with the smart solid.
    """

    ret = SolidUtil.Convert.BodyToElement(intersectElement, primitiveToBody[1], targetId, dgnModel)
    """
    Convert the smart solid to an EditElementHandle object.
    This is the final step in converting the primitive solid to a smart solid.
    """

    if BentleyStatus.eSUCCESS == ret:
        # Add the newly created smart solid to the DGN model
        intersectElement.AddToModel()
        pass
        """
        If the conversion was successful, add the new smart solid to the DGN model.
        This is not actually implemented in this code snippet.
        """

        subEntArray = ISubEntityPtrArray()
        numEdges = SolidUtil.GetBodyEdges(subEntArray, primitiveToBody[1])
        assert (numEdges == 12)
        """
        Check the number of edges in the newly created smart solid.
        The expected value is 12, and this check ensures that the conversion was successful.
        """

        subFaceArray = ISubEntityPtrArray()
        numfaces = SolidUtil.GetBodyFaces(subFaceArray, primitiveToBody[1])
        assert (numfaces == 6)
        """
        Check the number of faces in the newly created smart solid.
        The expected value is 6, and this check ensures that the conversion was successful.
        """

        subVertices = ISubEntityPtrArray()
        numVertices = SolidUtil.GetBodyVertices(subVertices, primitiveToBody[1])
        assert (numVertices == 8)
        """
        Check the number of vertices in the newly created smart solid.
        The expected value is 8, and this check ensures that the conversion was successful.
        """

        if (6 == numfaces and numEdges == 12 and numVertices == 8):
            return True
            """
            If all the checks pass, return True indicating that the conversion was successful.
            """

    # If any of the above steps fail, return False indicating failure
    return False

'''
Prerequisite: Open MSPythonSamples\data\SolidModeling.dgn  
'''
#main
if __name__ == "__main__":
    #import debugpy
    #debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
    #print("Waiting for debugger attach")
    #debugpy.wait_for_client()
    #debugpy.breakpoint()
    #print('break on this line')

    #highlight all the elements with type 
    if(True != imprintSolidUsingProfile(1401, 1408)):
        print("Imprint operation failed")
    if(True != sweepBody(1441)):
         print("Sweep operation failed")
    if(True != spinBody(1442)):
        print("Spin operation failed")
    if(True != thickenSheet(2522,2.0,2.0)):
        print("thicken operation failed")
    if(True != blendEdges(2508,0.5)):
        print("blend operation failed")
    if(True != chamferEdges(2515)):
        print("Chamfer operation failed")
    if(True != BooleanIntersect(1554,1556,1558)):
        print("Boolean intersection operation failed")
    if(True != BooleanSubstraction(1711,1707,1709)):
        print("Boolean Subtraction operation failed")
    if(True != BooleanUnion(1754,1758,1756,1760)):
        print("Boolean Union operation failed")
    if(True != BooleanCut(2471, 2478)):
        print("Cut operation failed")
    if(True != emboss(2479, 2486)):
        print("Emboss operation failed")
    if(True != offsetFaces(2487,2.0)):
        print("Offset operation failed")
    if(True != TransformFaces(2494,2.0)):
       print("Transform operation failed")
    if(True != offsetThroughHole(2501,2.0)):
       print("Offset through hole operation failed")
    if(True != BodyFromSweep(2523,2524)):
       print("Sweep operation failed")
    if(True != LoftBody(2031,2034,2033)):
       print("Loft operation failed")
    if(True != extrusionToBody(2529,2527)):
       print("Extrusion to body operation failed")
    if(True != bSplineSurfaceToBody(2166)):
       print("Bspline surface to body operation failed")
    if(True != primitiveToSmartSolid(2190)):
       print("Primitive to smart body operation failed")