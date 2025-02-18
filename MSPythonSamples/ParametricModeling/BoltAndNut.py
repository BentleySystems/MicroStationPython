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
from MSPyDgnView import *
from MSPyMstnPlatform import *
import PSampUtility
import VariableAndVariation
import ParametricSolid

def createVariables(dgnModel):
    """
    Creates variables for parametric modeling, and associate them with expressions.

    Args:
        dgnModel (DgnModel): The DgnModel object.

    Returns:
        bool: True if the variables are created successfully, False otherwise.
    """
    VariableAndVariation.CreateVariable("var1", ParameterType.eDistance, 500, dgnModel) 
    VariableAndVariation.CreateVariableWithExpression("var2", ParameterType.eDistance, 250, "var1", dgnModel) 
    VariableAndVariation.CreateVariableWithExpression("var3", ParameterType.eDistance, 250, "var1/2", dgnModel) 

    return True

def getFeatureChamferNode(ehh, edgeIndex, length, angle):
    """
    Creates a chamfer feature on a specific edge of a solid body.

    Parameters:
    - ehh: The element handle of the solid body.
    - edgeIndex: The index of the edge to be chamfered.
    - length: The length of the chamfer.
    - angle: The angle of the chamfer.

    Returns:
    - featureNode: The feature node representing the chamfer feature.

    """
    status, solid = SolidUtil.Convert.ElementToBody(ehh, True, True, False) # Convert element to body
    if BentleyStatus.eERROR == status:
        return False

    edges = ISubEntityPtrArray()
    numEdges = SolidUtil.GetBodyEdges(edges, solid)
    edgesToBeChamfered = ISubEntityPtrArray()
    edgesToBeChamfered.append(edges[edgeIndex])
    edgeSetting = ChamferEdgeSettings() # Define chamfer edge settings
    edgeSetting.length = length
    edgeSetting.angle = angle
    status, featureNode = FeatureCreate.CreateChamferFeature(edgesToBeChamfered,  edgeSetting) # Create chamfer feature node
    return featureNode

def createBaseCircle(center, radius, dgnModel, radiusConstraintVariable):
    """
    Creates a base circle with the given center and radius and adds it to the specified dgnModel,
    set fixed construction and radius constraint, and associate radius constraint with variable "var2".

    Args:
        center: The center point of the circle.
        radius: The radius of the circle.
        dgnModel: The dgnModel to which the circle will be added.
		radiusConstraintVariable: The variable name for the radius constraint.

    Returns:
        The created base circle element.

    """
    elems = ElementAgenda()
    primitiveIds = Int32Array()
    subIndexs = Int32Array()
    vertexTypes = VertexTypeArray()

    eehCircle = PSampUtility.CreateEllipseAndAdd2Model(center, radius, radius, dgnModel, True, 6, 2, DgnElementClass.eConstruction) # Create a circle in the given model
    elems.Empty(False)
    elems.Insert(eehCircle.GetElementRef(), eehCircle.GetModelRef())
    primitiveIds.append(0)
    subIndexs.append(0)
    vertexTypes.append(VertexType.eCenter)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eFix, primitiveIds, subIndexs, vertexTypes) # Add fixed constraint to the circle
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eRadius, 0, 0, 0, 0, radius, radiusConstraintVariable) # Add radius constraint ot the circle and associate to the variable

    return eehCircle

def createBaseLine(start, end, eehCircle, dgnModel):
    """
    Creates a baseline between two points and adds constraints to the base circle and base line.

    Args:
        start (Point3d): The starting point of the baseline.
        end (Point3d): The ending point of the baseline.
        eehCircle (ElementHandle): The base circle element.
        dgnModel (DgnModel): The model to which the elements will be added.

    Returns:
        ElementHandle: The created baseline element.
    """
    elems = ElementAgenda()
    primitiveIds = Int32Array()
    subIndexs = Int32Array()
    vertexTypes = VertexTypeArray()

    eehLine = PSampUtility.CreateLineAndAdd2Model(start, end, dgnModel, True, 6, 2, DgnElementClass.eConstruction) # Create a line in given model
    elems.Empty(False)
    elems.Insert(eehLine.GetElementRef(), eehLine.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eFix)
    primitiveIds.append(0)
    subIndexs.append(0)
    vertexTypes.append(VertexType.eStart)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eFix, primitiveIds, subIndexs, vertexTypes) # Add fixed constraint to the line

    # Add constraint to the base circle and base line, to make the center point of the circle is on the line
    elems.Empty(False)
    elems.Insert(eehCircle.GetElementRef(), eehCircle.GetModelRef())
    elems.Insert(eehLine.GetElementRef(), eehLine.GetModelRef())
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((0, 0))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eCenter, VertexType.eEdge)) # Set vertext type as center for the circle and edge for the line
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes) # Add constraint to the base circle and base line, to make the center point of the circle is on the line

    return eehLine

def createShapeCutProfile(eehCircle, dgnModel):
    """
    Creates a shape as a cut profile to cut the bolt head.

    Args:
        eehCircle (ElementHandle): The base circle element.
        dgnModel (DgnModel): The DgnModel to add the shape to.

    Returns:
        ElementHandle: The created shape cut profile element.
    """
    elems = ElementAgenda()
    primitiveIds = Int32Array()
    subIndexs = Int32Array()
    vertexTypes = VertexTypeArray()

    # Create shape as cut profile to cut the bolt head
    points = DPoint3dArray()
    points.append(DPoint3d.From(500.0, 0.0, 0.0))
    points.append(DPoint3d.From(250.0, -433.0, 0.0))
    points.append(DPoint3d.From(-250.0, -433.0, 0.0))
    points.append(DPoint3d.From(-500.0, 0.0, 0.0))
    points.append(DPoint3d.From(-250.0, 433.0, 0.0))
    points.append(DPoint3d.From(250.0, 433.0, 0.0))
    points.append(DPoint3d.From(500.0, 0.0, 0.0))
    eehShapeCutProfile = PSampUtility.CreateShapeAndAdd2Model(points, dgnModel, True)

    # Add constraint to the cut profile, to make it as a regular hexagon, and all end point is on the base circle
    # Adding coincident constraint to make all the vertext of the regular hexagon on the circle
    elems.Insert(eehCircle.GetElementRef(), eehCircle.GetModelRef())
    elems.Insert(eehShapeCutProfile.GetElementRef(), eehShapeCutProfile.GetModelRef())
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((0, 0))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eEdge, VertexType.eStart))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    subIndexs.clear()
    subIndexs.extend((0, 1))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    subIndexs.clear()
    subIndexs.extend((0, 2))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    subIndexs.clear()
    subIndexs.extend((0, 3))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    subIndexs.clear()
    subIndexs.extend((0, 4))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    subIndexs.clear()
    subIndexs.extend((0, 5))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    # Add equal constraint for the 6 edges to make all edges equal
    elems.Empty(False)
    elems.Insert(eehShapeCutProfile.GetElementRef(), eehShapeCutProfile.GetModelRef())
    elems.Insert(eehShapeCutProfile.GetElementRef(), eehShapeCutProfile.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 0, 0, 0, 1)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 0, 1, 0, 2)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 0, 2, 0, 3)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 0, 3, 0, 4)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 0, 4, 0, 5)

    return eehShapeCutProfile

def createExtrudeProfileBoltScrew(center, radius, eehBaseCircle, dgnModel, radiusConstraintVariable):
    """
    Creates an extrude profile for a bolt screw.

    Args:
        center (Point3d): The center point of the extrude profile.
        radius (float): The radius of the extrude profile.
        eehBaseCircle (ElementHandle): The base circle element.
        dgnModel (DgnModel): The model reference.
        radiusConstraintVariable (str): The variable name for the radius constraint.

    Returns:
        ElementHandle: The extrude profile bolt screw element.
    """
    elems = ElementAgenda()

    eehExtrudeProfileBoltScrew = PSampUtility.CreateEllipseAndAdd2Model(center, radius, radius, dgnModel, True)
    elems.Empty(False)
    elems.Insert(eehExtrudeProfileBoltScrew.GetElementRef(), eehExtrudeProfileBoltScrew.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eRadius, 0, 0, 0, 0, 250, radiusConstraintVariable)
    # Add constraint to base circle and the bolt screw profile to make them concentric
    elems.Empty(False)
    elems.Insert(eehBaseCircle.GetElementRef(), eehBaseCircle.GetModelRef())
    elems.Insert(eehExtrudeProfileBoltScrew.GetElementRef(), eehExtrudeProfileBoltScrew.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eConcentric)

    return eehExtrudeProfileBoltScrew

def createExtrudeProfileBoltHead(center, radius, eehBaseCircle, dgnModel, radiusConstraintVariable):
    """
    Creates an extrude profile for a bolt head.

    Args:
        center (DPoint3d): The center coordinates of the bolt head.
        radius (float): The radius of the bolt head.
        eehBaseCircle (object): The base circle element.
        dgnModel (DgnModel): The model to add the bolt head profile to.
        radiusConstraintVariable (str): The variable name for the radius constraint.

    Returns:
        object: The extrude profile of the bolt head.
    """
    elems = ElementAgenda()

    eehExtrudeProfileBoltHead = PSampUtility.CreateEllipseAndAdd2Model(center, radius, radius, dgnModel, True)
    elems.Empty(False)
    elems.Insert(eehExtrudeProfileBoltHead.GetElementRef(), eehExtrudeProfileBoltHead.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eRadius, 0, 0, 0, 0, 500, radiusConstraintVariable)
    # Add constraint to base circle and the bolt head profile to make them concentric
    elems.Empty(False)
    elems.Insert(eehBaseCircle.GetElementRef(), eehBaseCircle.GetModelRef())
    elems.Insert(eehExtrudeProfileBoltHead.GetElementRef(), eehExtrudeProfileBoltHead.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eConcentric)

    return eehExtrudeProfileBoltHead

def createBoltHeadFromProfile(eehExtrudeProfileBoltHead, eehShapeCutProfile, height, chamferLength, chamferAngle):
    """
    Creates a bolt head from a given profiles by performing extrusion, chamfering, and cutting operations.

    Args:
        eehExtrudeProfileBoltHead (ElementHandle): The extrude profile of the bolt head.
        eehShapeCutProfile (ElementHandle): The shape cut profile.
        height (float): The height of the bolt head.
        chamferLength (float): The length of the chamfer.
        chamferAngle (float): The angle of the chamfer.

    Returns:
        ElementHandle: The element handle of the cut feature representing the bolt head, or None if the creation fails.
    """
    # Extrude the bolt head profile as the bolt head
    ehhBoltHeadExtruded = ParametricSolid.CreateSmartFeatureElementExtrude(eehExtrudeProfileBoltHead, height)

    # Create chamfer feature node of the extruded bolt head
    chamferFeatureNode = getFeatureChamferNode(ehhBoltHeadExtruded, 0, chamferLength, chamferAngle)
    if (chamferFeatureNode is None):
        return None

    # Create chamfer feature of the extruded bolt head
    controlFlags = BoolArray()
    controlFlags.append(False)
    controlFlags.append(False)
    controlFlags.append(False)
    childElementToControlFlagsMap = {ehhBoltHeadExtruded.GetElementRef(): controlFlags}
    eehChamferBoltHead = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehChamferBoltHead, ehhBoltHeadExtruded, ehhBoltHeadExtruded.GetDgnModel(), chamferFeatureNode, childElementToControlFlagsMap, False)):
        return None

    # Create cut feature node of the chamfered bolt head
    status, cutNode = FeatureCreate.CreateCutFeature(SolidUtil.Modify.CutDepthMode.eAll, SolidUtil.Modify.CutDirectionMode.eBackward, True, 0, DVec3d.From(0.0, 0.0, 1.0))
    if (cutNode is None):
        return None

    # Create cut feature of the extruded bolt head to make it regular hexagon
    childElementToControlFlagsMap.clear()
    childElementToControlFlagsMap[eehChamferBoltHead.GetElementRef()] = controlFlags
    controlFlags1 = BoolArray()
    controlFlags1.append(False)
    controlFlags1.append(False)
    controlFlags1.append(True)
    childElementToControlFlagsMap[eehShapeCutProfile.GetElementRef()] = controlFlags1
    eehCut = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehCut, eehChamferBoltHead, eehChamferBoltHead.GetDgnModel(), cutNode, childElementToControlFlagsMap, True)):
        return None

    return eehCut

def createBoltScrewFromProfile(eehExtrudeProfileBoltScrew):
    """
    Creates a bolt screw from the given extrude profile by performing extrusion and chamfering operations

    Args:
        eehExtrudeProfileBoltScrew (EditElementHandle): The extrude profile of the bolt screw.

    Returns:
        EditElementHandle: The element handle to the created bolt screw if successful, None otherwise.
    """
    ehhBoltScrewExtruded = ParametricSolid.CreateSmartFeatureElementExtrude(eehExtrudeProfileBoltScrew, -1500)
    chamferFeatureNode = getFeatureChamferNode(ehhBoltScrewExtruded, 0, 50, 45)
    if (chamferFeatureNode is None):
        return None

    controlFlags = BoolArray()
    controlFlags.append(False)
    controlFlags.append(False)
    controlFlags.append(False)
    childElementToControlFlagsMap = {ehhBoltScrewExtruded.GetElementRef(): controlFlags}
    # Create and write smart feature element
    eehChamferBoltScrew = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehChamferBoltScrew, ehhBoltScrewExtruded, ehhBoltScrewExtruded.GetDgnModel(), chamferFeatureNode, childElementToControlFlagsMap, False)):
        return None

    return eehChamferBoltScrew

def unionBoltHeadAndScrew(ehhBoltHead, ehhBoltScrew):
    """
    Creates a union feature by combining the bolt head and bolt screw.

    Args:
        ehhBoltHead (EditElementHandle): The EditElementHandle of the bolt head.
        ehhBoltScrew (EditElementHandle): The EditElementHandle of the bolt screw.

    Returns:
        EditElementHandle: The EditElementHandle of the created union feature, or None if creation fails.
    """
    status, unionFeatureNode = FeatureCreate.CreateUnionFeature()
    if (unionFeatureNode is None):
        return None

    controlFlags = BoolArray()
    controlFlags.append(False)
    controlFlags.append(False)
    controlFlags.append(False)
    childElementToControlFlagsMap = {ehhBoltHead.GetElementRef(): controlFlags}
    childElementToControlFlagsMap[ehhBoltScrew.GetElementRef()] = controlFlags

    # Create and write smart feature element
    eehBolt = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehBolt, ehhBoltHead, ehhBoltHead.GetDgnModel(), unionFeatureNode, childElementToControlFlagsMap, True)):
        return None

    ehhBoltScrew.DeleteFromModel()

    return eehBolt

def ExampleCreateBolt(boltModel):
    """
    Creates a bolt using parametric modeling techniques.

    Returns:
        bool: True if the bolt creation is successful, False otherwise.
    """
    dgnModel = boltModel
    if (dgnModel is None):
        return False

    # Create variables which will be used for the bolt
    createVariables(dgnModel)

    # Create base circle as construction type, set fixed constraint, set radius constraint and associate variable "var2"
    eehCircle = createBaseCircle(DPoint3d.From(0.0, 0.0, 0.0), 500.0, dgnModel, "var2")
    if (eehCircle is None):
        return False

    # Create horizontal base line as construction type
    start1 = DPoint3d.From(-1000.0, 0.0)
    end1 = DPoint3d.FromSumOf(start1, DPoint3d.From(2000.0, 0.0))
    eehLineHorizontal = createBaseLine(start1, end1, eehCircle, dgnModel)
    if (eehLineHorizontal is None):
        return False

    # Create vertical base line as construction type
    start2 = DPoint3d.From(0.0, 1000.0)
    end2 = DPoint3d.FromSumOf(start2, DPoint3d.From(0.0, -2000))
    eehLineVertical = createBaseLine(start2, end2, eehCircle, dgnModel)
    if (eehLineVertical is None):
        return False

    # Create circle as extrution profile of the bolt head, set radius constraint and associate to variable "var2"
    eehExtrudeProfileBoltHead = createExtrudeProfileBoltHead(DPoint3d.From(0.0, 0.0, 0.0), 500.0, eehCircle, dgnModel, "var2")
    if (eehExtrudeProfileBoltHead is None):
        return False

    # Create shape as cut profile
    eehShapeCutProfile = createShapeCutProfile (eehCircle, dgnModel)
    if (eehShapeCutProfile is None):
        return False

    # Create circle as extrution profile of the bolt screw, set radius constraint and associate to variable "var3"
    eehExtrudeProfileBoltScrew = createExtrudeProfileBoltScrew(DPoint3d.From(0.0, 0.0, 0.0), 250.0, eehCircle, dgnModel, "var3")
    if (eehExtrudeProfileBoltScrew is None):
        return False

    # Create the bolt head from extrude profile and cut profile and write smart feature element
    ehhBoltHead = createBoltHeadFromProfile(eehExtrudeProfileBoltHead, eehShapeCutProfile, 350, 100, 45)
    if(ehhBoltHead is None):
        return False

    # Create bolt screw  from extrude profile and write smart feature element
    ehhBoltScrew = createBoltScrewFromProfile(eehExtrudeProfileBoltScrew)
    if(ehhBoltScrew is None):
        return False

    # Union the bolt head and bolt screw together
    if(unionBoltHeadAndScrew(ehhBoltHead, ehhBoltScrew) is None):
        return False

    return True

def createShapeRevolutionProfile(eehLineZ, dgnModel, varName1, varName2):
    """
    Creates a shape revolution profile for revolving nut.

    Args:
        eehLineZ (ElementHandle): The element handle of the line element.
        dgnModel (DgnModel): The model to which the elements will be added.
        varName1 (str): The variable name which will associate to the distance constraint of inner radius.
        varName1 (str): The variable name which will associate to the distance constraint of outer radius..

    Returns:
        ElementHandle: The element handle of the shape revolution profile.

    """
    elems = ElementAgenda()
    primitiveIds = Int32Array()
    subIndexs = Int32Array()
    vertexTypes = VertexTypeArray()

    # Create shape as cut profile to cut the bolt head
    points = DPoint3dArray()
    points.append(DPoint3d.From(0.0, 0.0, 0.0))
    points.append(DPoint3d.From(250.0, 0.0, 0.0))
    points.append(DPoint3d.From(250.0, 0.0, 250.0))
    points.append(DPoint3d.From(0.0, 0.0, 250.0))
    eehShapeRevolutionProfile = PSampUtility.CreateShapeAndAdd2Model(points, dgnModel, True)

    elems.Empty(False)
    elems.Insert(eehShapeRevolutionProfile.GetElementRef(), eehShapeRevolutionProfile.GetModelRef())
    elems.Insert(eehShapeRevolutionProfile.GetElementRef(), eehShapeRevolutionProfile.GetModelRef())
    primitiveIds.append(0)
    primitiveIds.append(0)
    subIndexs.append(1)
    subIndexs.append(1)
    vertexTypes.append(VertexType.eStart)
    vertexTypes.append(VertexType.eEnd)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 350)

    elems.Empty(False)
    elems.Insert(eehShapeRevolutionProfile.GetElementRef(), eehShapeRevolutionProfile.GetModelRef())
    elems.Insert(eehShapeRevolutionProfile.GetElementRef(), eehShapeRevolutionProfile.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 0, 2)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 1, 0, 3,)

    elems.Empty(False)
    elems.Insert(eehLineZ.GetElementRef(), eehLineZ.GetModelRef())
    elems.Insert(eehShapeRevolutionProfile.GetElementRef(), eehShapeRevolutionProfile.GetModelRef())
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.append(0)
    primitiveIds.append(0)
    subIndexs.append(0)
    subIndexs.append(3)
    vertexTypes.append(VertexType.eEdge)
    vertexTypes.append(VertexType.eEdge)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 250, varName1)
    
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.append(0)
    primitiveIds.append(0)
    subIndexs.append(0)
    subIndexs.append(1)
    vertexTypes.append(VertexType.eEdge)
    vertexTypes.append(VertexType.eEdge)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 500, varName2)

    return eehShapeRevolutionProfile

def createNutFromProfiles(eehShapeRevolutionProfile, eehShapeCutProfile, chamferLength, chamferAngle):
    """
    Creates a nut from given profiles and parameters.

    Args:
        eehShapeRevolutionProfile: The revolution profile for creating the nut.
        eehShapeCutProfile: The cut profile for creating the nut.
        chamferLength: The length of  chamfer feature.
        chamferAngle: The angle of chamfer feature.

    Returns:
        The created nut as an EditElementHandle, or None if the creation fails.
    """
    status, curveVector = SmartFeatureUtil.GetCurveVector (eehShapeRevolutionProfile, True)
    if (BentleyStatus.eSUCCESS != status or curveVector is None):
        return None

    # Init settings
    buttonEvent = DgnButtonEvent() # mock the DgnButtonEvent
    buttonEvent.SetPoint(DPoint3d.From(0.0, 0.0, 0.0))
    buttonEvent.SetViewport(IViewManager.GetActiveViewSet().GetViewport(0))

    settings = RevolveSettings(DPoint3d.From(0.0, 0.0, 0.0), False, 360, 0, DPoint3d.From(0.0, 0.0, 0.0), DPoint3d.From(0.0, 0.0, 1.0), curveVector, 0, 0.0, IViewManager.GetActiveViewSet().GetSelectedViewport())
    revolueFeatureNode = FeatureCreate.CreateRevolveFeature(settings)
    if (revolueFeatureNode is None):
        return None

    controlFlags = BoolArray()
    controlFlags.append(False)
    controlFlags.append(False)
    controlFlags.append(False)
    childElementToControlFlagsMap = {eehShapeRevolutionProfile.GetElementRef(): controlFlags}
    # Create and write smart feature element
    eehRevolve = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehRevolve, eehShapeRevolutionProfile, eehShapeRevolutionProfile.GetDgnModel(), revolueFeatureNode, childElementToControlFlagsMap, False)):
        return None

    # Create chamfer feature node of the extruded bolt head
    chamferFeatureNode = getFeatureChamferNode(eehRevolve, 1, chamferLength, chamferAngle)
    if (chamferFeatureNode is None):
        return None

    childElementToControlFlagsMap.clear()
    childElementToControlFlagsMap = {eehRevolve.GetElementRef(): controlFlags}
    eehChamfer = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehChamfer, eehRevolve, eehRevolve.GetDgnModel(), chamferFeatureNode, childElementToControlFlagsMap, False)):
        return None

    # Create cut feature node of the chamfered bolt head
    status, cutNode = FeatureCreate.CreateCutFeature(SolidUtil.Modify.CutDepthMode.eAll, SolidUtil.Modify.CutDirectionMode.eBackward, True, 0, DVec3d.From(0.0, 0.0, 1.0))
    if (cutNode is None):
        return None

    # Create cut feature of the extruded bolt head to make it regular hexagon
    childElementToControlFlagsMap.clear()
    childElementToControlFlagsMap[eehRevolve.GetElementRef()] = controlFlags
    controlFlags1 = BoolArray()
    controlFlags1.append(False)
    controlFlags1.append(False)
    controlFlags1.append(True)
    childElementToControlFlagsMap[eehShapeCutProfile.GetElementRef()] = controlFlags1
    eehCut = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(eehCut, eehRevolve, eehRevolve.GetDgnModel(), cutNode, childElementToControlFlagsMap, True)):
        return None

    return eehCut

def ExampleCreateNut(nutModel):
    """
    Creates a parametric nut in the given nutModel.

    Parameters:
    nutModel (DgnModel): The model in which the parametric will be created.

    Returns:
    bool: True if the nut model is successfully created, False otherwise.
    """
    dgnModel = nutModel
    if (dgnModel is None):
        return False
    
    createVariables(dgnModel)

    # Create base circle as construction type, set fixed constraint, set radius constraint and associate variable "var2"
    eehCircle = createBaseCircle(DPoint3d.From(0.0, 0.0, 0.0), 500.0, dgnModel, "var2")
    if (eehCircle is None):
        return False

    # Create horizontal base line as construction type
    start1 = DPoint3d.From(-1000.0, 0.0)
    end1 = DPoint3d.FromSumOf(start1, DPoint3d.From(2000.0, 0.0))
    eehLineX = createBaseLine(start1, end1, eehCircle, dgnModel)
    if (eehLineX is None):
        return False

    # Create vertical base line as construction type
    start2 = DPoint3d.From(0.0, 1000.0)
    end2 = DPoint3d.FromSumOf(start2, DPoint3d.From(0.0, -2000))
    eehLineY = createBaseLine(start2, end2, eehCircle, dgnModel)
    if (eehLineY is None):
        return False

    # Create z-axis base line as construction type
    start3 = DPoint3d.From(0.0, 0.0, 0.0)
    end3 = DPoint3d.FromSumOf(start3, DPoint3d.From(0.0, 0.0, 2000))
    eehLineZ = createBaseLine(start3, end3, eehCircle, dgnModel)
    if (eehLineZ is None):
        return False

    # Create a shape as revolution profile with variable names for inner radius and outer radius
    eehShapeRevolutionProfile = createShapeRevolutionProfile(eehLineZ, dgnModel, "var3", "var2")
    if (eehShapeRevolutionProfile is None):
        return False

    # Create a shape as cut profile
    eehShapeCutProfile = createShapeCutProfile (eehCircle, dgnModel)
    if (eehShapeCutProfile is None):
        return False

    # Create the nut with given revolution profile and cut profile
    if(createNutFromProfiles(eehShapeRevolutionProfile, eehShapeCutProfile, 100, 45) is None):
        return False

    return True

def RunSamples():
    boltModel = PSampUtility.GetOrCreateModel("BoltModel", True)
    ModelRef.ActivateAndDisplay(boltModel)
    ExampleCreateBolt(boltModel)

    nutModel = PSampUtility.GetOrCreateModel("NutModel", True)
    ModelRef.ActivateAndDisplay(nutModel)
    ExampleCreateNut(nutModel)

if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    RunSamples()

