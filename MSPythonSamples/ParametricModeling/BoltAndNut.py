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

'''
Sample demonstrating how to create bolts, nuts, screws using parametric solid
'''

def createVariables(dgnModel):
    """
    Creates variables in the given design model.
    This function creates three variables in the specified design model using the 
    VariableAndVariation module. The variables are defined as follows:
    - var1: A distance parameter with a value of 500.
    - var2: A distance parameter with a value of 250, defined with an expression based on var1.
    - var3: A distance parameter with a value of 250, defined with an expression based on half of var1.
    
    :param dgnModel: The design model in which to create the variables.
    :type dgnModel: object
    
    :return: Returns True upon successful creation of the variables.
    :rtype: bool
    """
    VariableAndVariation.CreateVariable("var1", ParameterType.eDistance, 500, dgnModel) 
    VariableAndVariation.CreateVariableWithExpression("var2", ParameterType.eDistance, 250, "var1", dgnModel) 
    VariableAndVariation.CreateVariableWithExpression("var3", ParameterType.eDistance, 250, "var1/2", dgnModel) 

    return True

def getFeatureChamferNode(ehh, edgeIndex, length, angle):
    """
    Creates a chamfer feature node on a specified edge of a solid element.
    
    :param ehh: The element handle of the solid element.
    :type ehh: ElementHandle
    :param edgeIndex: The index of the edge to be chamfered.
    :type edgeIndex: int
    :param length: The length of the chamfer.
    :type length: float
    :param angle: The angle of the chamfer.
    :type angle: float
    
    :return: The created chamfer feature node if successful, otherwise False.
    :rtype: FeatureNode or bool
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
    Create a base circle in the given model with fixed and radius constraints.
    
    :param center: The center point of the circle.
    :type center: Point3d
    :param radius: The radius of the circle.
    :type radius: float
    :param dgnModel: The design model where the circle will be created.
    :type dgnModel: DgnModelRef
    :param radiusConstraintVariable: The variable to associate with the radius constraint.
    :type radiusConstraintVariable: ConstraintVariable
    
    :return: The created circle element.
    :rtype: ElementHandle
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
    Create a base line in the given model and add constraints to it.
    This function creates a line between the given start and end points in the specified model.
    It then adds a fixed constraint to the line. Additionally, it adds a constraint to ensure
    that the center point of the given circle is on the created line.
    
    :param start: The start point of the line.
    :type start: Point3d
    :param end: The end point of the line.
    :type end: Point3d
    :param eehCircle: The element handle of the circle to be constrained.
    :type eehCircle: ElementHandle
    :param dgnModel: The model in which the line is to be created.
    :type dgnModel: DgnModelRef
    
    :return: The element handle of the created line.
    :rtype: ElementHandle
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
    Create a shape cut profile to cut the bolt head and add constraints to form a regular hexagon.
    This function creates a shape cut profile using a set of points and adds it to the given model.
    It then adds constraints to ensure the shape is a regular hexagon with all vertices coincident
    with a base circle and all edges equal in length.
    
    :param eehCircle: The element handle of the base circle.
    :type eehCircle: ElementHandle
    :param dgnModel: The design model to which the shape cut profile will be added.
    :type dgnModel: DgnModel
    
    :return: The element handle of the created shape cut profile.
    :rtype: ElementHandle
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
    Create an extruded profile for a bolt screw and add constraints.
    This function creates an elliptical profile for a bolt screw, adds it to the given model,
    and applies radius and concentric constraints to it.
    
    :param center: The center point of the ellipse.
    :type center: Point3d
    :param radius: The radius of the ellipse.
    :type radius: float
    :param eehBaseCircle: The element handle of the base circle.
    :type eehBaseCircle: ElementHandle
    :param dgnModel: The design model to which the ellipse will be added.
    :type dgnModel: DgnModelRef
    :param radiusConstraintVariable: The variable for the radius constraint.
    :type radiusConstraintVariable: Variable
    
    :return: The element handle of the created elliptical profile.
    :rtype: ElementHandle
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
    Create an extrude profile for a bolt head and add constraints.
    This function creates an elliptical profile for a bolt head, adds it to the given model,
    and applies radius and concentric constraints.
    
    :param center: The center point of the ellipse.
    :type center: Point3d
    :param radius: The radius of the ellipse.
    :type radius: float
    :param eehBaseCircle: The base circle element handle.
    :type eehBaseCircle: ElementHandle
    :param dgnModel: The design model to which the ellipse will be added.
    :type dgnModel: DgnModelRef
    :param radiusConstraintVariable: The variable for the radius constraint.
    :type radiusConstraintVariable: Variable
    
    :return: The element handle of the created extrude profile bolt head.
    :rtype: ElementHandle
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
    Creates a bolt head from a given profile by extruding it, applying a chamfer, and cutting it to form a regular hexagon.
    
    :param eehExtrudeProfileBoltHead: The profile to be extruded for the bolt head.
    :type eehExtrudeProfileBoltHead: ElementHandle
    :param eehShapeCutProfile: The profile used to cut the extruded bolt head.
    :type eehShapeCutProfile: ElementHandle
    :param height: The height to extrude the bolt head profile.
    :type height: float
    :param chamferLength: The length of the chamfer to be applied to the bolt head.
    :type chamferLength: float
    :param chamferAngle: The angle of the chamfer to be applied to the bolt head.
    :type chamferAngle: float
    
    :return: The handle to the final bolt head element after extrusion, chamfering, and cutting.
    :rtype: EditElementHandle or None
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
    Creates a bolt screw from a given profile by extruding it and applying a chamfer feature.
    
    :param eehExtrudeProfileBoltScrew: The profile to be extruded into a bolt screw.
    :type eehExtrudeProfileBoltScrew: ElementHandle
    
    :return: The handle to the chamfered bolt screw element, or None if the operation fails.
    :rtype: EditElementHandle or None
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
    Unites the bolt head and screw into a single smart feature element.
    
    :param ehhBoltHead: The element handle for the bolt head.
    :type ehhBoltHead: ElementHandle
    :param ehhBoltScrew: The element handle for the bolt screw.
    :type ehhBoltScrew: ElementHandle
    
    :return: The combined bolt element handle if successful, otherwise None.
    :rtype: EditElementHandle or None
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
    Creates a bolt model with specified parameters.
    
    :param boltModel: The model to which the bolt will be added.
    :type boltModel: object
    
    :return: True if the bolt creation is successful, False otherwise.
    :rtype: bool
    The function performs the following steps:
    1. Creates variables for the bolt.
    2. Creates a base circle and sets constraints.
    3. Creates horizontal and vertical base lines.
    4. Creates an extrusion profile for the bolt head and sets constraints.
    5. Creates a shape for the cut profile.
    6. Creates an extrusion profile for the bolt screw and sets constraints.
    7. Creates the bolt head from the extrusion and cut profiles.
    8. Creates the bolt screw from the extrusion profile.
    9. Unions the bolt head and bolt screw together.
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
    Create a shape revolution profile and add constraints to it.
    This function creates a shape to be used as a cut profile for cutting a bolt head.
    It then adds various constraints to the shape and returns the created shape element.
    
    :param eehLineZ: The element handle for the Z-axis line.
    :type eehLineZ: ElementHandle
    :param dgnModel: The design model to which the shape will be added.
    :type dgnModel: DgnModel
    :param varName1: The variable name for the first distance constraint.
    :type varName1: str
    :param varName2: The variable name for the second distance constraint.
    :type varName2: str
    
    :return: The created shape revolution profile element handle.
    :rtype: ElementHandle
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
    Creates a nut from given profiles by performing a series of geometric operations.
    
    :param eehShapeRevolutionProfile: The profile used for the revolution shape of the nut.
    :type eehShapeRevolutionProfile: ElementHandle
    :param eehShapeCutProfile: The profile used for cutting the nut to form a hexagon.
    :type eehShapeCutProfile: ElementHandle
    :param chamferLength: The length of the chamfer to be applied to the nut.
    :type chamferLength: float
    :param chamferAngle: The angle of the chamfer to be applied to the nut.
    :type chamferAngle: float
    
    :return: The handle to the final nut element, or None if the creation failed.
    :rtype: EditElementHandle or None
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
    Creates a nut model with specified parameters.
    
    :param nutModel: The model to which the nut will be added.
    :type nutModel: object
    
    :return: True if the nut creation is successful, False otherwise.
    :rtype: bool
    
    This function performs the following steps:
    1. Creates base circle as construction type, sets fixed constraint, sets radius constraint, and associates variable "var2".
    2. Creates horizontal base line as construction type.
    3. Creates vertical base line as construction type.
    4. Creates z-axis base line as construction type.
    5. Creates a shape as revolution profile with variable names for inner radius and outer radius.
    6. Creates a shape as cut profile.
    7. Creates the nut with the given revolution profile and cut profile.
    If any of the creation steps fail, the function returns False.
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
    """
    Run sample functions to create and display bolt and nut models.
    
    This function performs the following steps:
    1. Creates or retrieves a model named "BoltModel" and activates it.
    2. Calls the ExampleCreateBolt function to create a bolt in the "BoltModel".
    3. Creates or retrieves a model named "NutModel" and activates it.
    4. Calls the ExampleCreateNut function to create a nut in the "NutModel".
    
    Returns:
        None
    """
    boltModel = PSampUtility.GetOrCreateModel("BoltModel", True)
    ModelRef.ActivateAndDisplay(boltModel)
    ExampleCreateBolt(boltModel)

    nutModel = PSampUtility.GetOrCreateModel("NutModel", True)
    ModelRef.ActivateAndDisplay(nutModel)
    ExampleCreateNut(nutModel)

if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    RunSamples()

