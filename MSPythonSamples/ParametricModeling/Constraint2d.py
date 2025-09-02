# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import math
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
Sample demonstrating how to create 2D constraints
''' 

def addConstraintDataToModel(solverData):
    """
    Adds constraint data to the model using the provided solver data.
    
    :param solverData: The solver data to be added to the model.
    :type solverData: SolverData
    
    :return: True if the constraint data was successfully added, False otherwise.
    :rtype: bool
    """
    elementRefs = ElementRefPArray()
    solverData.GetElementRefs(elementRefs)

    if (not elementRefs):
        return False

    # Add constraint data to modle
    anyMember = ElementHandle(elementRefs[0])
    if (BentleyStatus.eSUCCESS != Constraint2dManager.AddSolverData (anyMember, solverData)):
        return False
    
    return True

def createComplexShapeAndAdd2Model(points, center, isClosed, dgnModel, add2Model):
    """
    Creates a complex shape from given points and adds it to the model.
    
    :param points: List of points to define the shape.
    :type points: list
    :param center: Center point for the arc.
    :type center: Point
    :param isClosed: Flag to indicate if the shape is closed.
    :type isClosed: bool
    :param dgnModel: The model to which the shape will be added.
    :type dgnModel: DgnModel
    :param add2Model: Flag to indicate if the shape should be added to the model.
    :type add2Model: bool
    
    :return: The handle to the created complex shape element, or None if creation failed.
    :rtype: EditElementHandle or None
    """
    if (dgnModel is None):
        return None

    # creaet header
    eeh = EditElementHandle()
    ComplexShapeHandler.CreateChainHeaderElement(eeh, None, isClosed, dgnModel.Is3d(), dgnModel)

    # draw the linestring
    ehLineString = PSampUtility.CreateLineStringAndAdd2Model(points, dgnModel, False)
    if (BentleyStatus.eSUCCESS != ComplexShapeHandler.AddComponentElement(eeh, ehLineString)):
        return None

    radius = math.fabs(points[2].x-points[1].x)/2.0
    ehArc = PSampUtility.CreateArcAndAdd2Model(center, radius, radius, Angle.Pi(), Angle.Pi(), dgnModel, False)
    if(BentleyStatus.eSUCCESS != ComplexShapeHandler.AddComponentElement(eeh, ehArc)):
        return None

    if(BentleyStatus.eSUCCESS != ComplexShapeHandler.AddComponentComplete(eeh)):
        return None

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh


def createLineCurveEntityId(point1, point2):
    """
    Creates a line curve entity identifier from two points.
    This function creates a line between two given points and adds it to the active DGN model.
    It then converts the created line element to a curve vector and returns a CurveEntityIdentifier
    if successful.
    
    :param point1: The starting point of the line.
    :type point1: Point2d
    :param point2: The ending point of the line.
    :type point2: Point2d
    
    :return: A CurveEntityIdentifier if the line creation and conversion are successful, otherwise None.
    :rtype: CurveEntityIdentifier or None
    """
    lineEh = PSampUtility.CreateLineAndAdd2Model(point1, point2, ISessionMgr.GetActiveDgnModel(), True)
    if(lineEh is None):
        return None

    status, curveVector = CurveEntityIdentifier.ElementToCurveVector(lineEh)
    if (BentleyStatus.eSUCCESS != status):
        return None

    # Create CurveEntityIdentifier
    return CurveEntityIdentifier(curveVector, None, 
                                   0, # 0-based index for edge
                                   VertexType.eEdge,
                                   lineEh.GetElementRef()
                                   )


def AddRadiusConstraintToElement(profileEditElementHandle, newValue, varName):
    """
    Adds a radius constraint to a given profile element.

    :param profileEditElementHandle: Handle to the profile element to which the radius constraint will be added.
    :type profileEditElementHandle: ProfileEditElementHandle
    :param newValue: The new radius value to be set.
    :type newValue: float
    :param varName: The variable name associated with the radius constraint.
    :type varName: str
    
    :return: Result of the constraint addition operation.
    :rtype: ConstraintResult
    """
    ModelRef.ActivateAndDisplay(profileEditElementHandle.GetModelRef())
    elems = ElementAgenda() # Define element agenda
    elems.Insert(profileEditElementHandle.GetElementRef(), profileEditElementHandle.GetModelRef()) # Add element ref to element agenda
    return Constraint2dManager.AddConstraint(elems, Constraint2dType.eRadius, 0, 0, 0, 0, newValue, varName) # Add constraint

def ExampleConstraintPerpendicular():
    """
    Creates two perpendicular line entities and adds a perpendicular constraint between them.
    This function performs the following steps:
    1. Creates two line entities using `createLineCurveEntityId`:
       - The first line is created from (0.0, 0.0) to (100000.0, 0.0).
       - The second line is created from (150000.0, 0.0) to (150000.0, 100000.0).
    2. Checks if the line entities were created successfully. If not, the function returns.
    3. Creates a perpendicular constraint using `Constraint2dData` and adds the line entities to it.
    4. Adds the constraint data to a `Constraint2dSolverData` object.
    5. Adds the constraint data to the model using `addConstraintDataToModel`.
    6. Evaluates the constraint model and updates the related member elements using `Constraint2dManager.EvaluateAndUpdate`.

    Returns:
        None
    """
    curveEntityId1 = createLineCurveEntityId(DPoint3d.From(0.0,0.0), DPoint3d.From(100000.0,0.0))
    curveEntityId2 = createLineCurveEntityId(DPoint3d.From(150000.0,0.0), DPoint3d.From(150000.0,100000.0))
    if (curveEntityId1 is None or curveEntityId2 is None):
        return

    constraintData = Constraint2dData(Constraint2dType.ePerpendicular)
    constraintData.AddCurveIdentifier(curveEntityId1)
    constraintData.AddCurveIdentifier(curveEntityId2)

    solverData = Constraint2dSolverData()
    solverData.m_constraints.append(constraintData)

    # Add constraint data to modle
    if (not addConstraintDataToModel (solverData)):
        return

    # Evaluate this constraint model and update related member elements
    noChanges = ElementRefPArray()
    isDynamic = False
    Constraint2dManager.EvaluateAndUpdate (solverData, ISessionMgr.GetActiveDgnModel(), noChanges, isDynamic, None)

def ExampleConstraintFixParallelEqualCoincidentPerpendicularAngle():
    """
    Demonstrates the creation of various 2D constraints in a DGN model.
    This function performs the following steps:
    1. Draws the first line from (0.0, 0.0) to (0.0, -100000.0).
    2. Draws the second line starting from (100000.0, 0.0) and ending at (50000.0, -50000.0).
    3. Draws a linestring with three points, starting from the end of the second line.
    4. Adds a fixed constraint to the first line.
    5. Adds a parallel constraint between the first and second lines.
    6. Adds an equal length constraint between the first and second lines.
    7. Adds a coincident constraint between the second line and the linestring.
    8. Adds a perpendicular constraint between the second line and the linestring.
    9. Adds an angle constraint of 135 degrees to the linestring.
    
    Returns:
        None
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    if (dgnModel is None):
        return

    # draw the first line
    start1 = DPoint3d.From(0.0, 0.0)
    end1 = DPoint3d.From(0.0, -100000.0)
    eeh1 = PSampUtility.CreateLineAndAdd2Model(start1, end1, dgnModel, True)

    # draw the second line
    start2 = DPoint3d.FromSumOf(start1, DPoint3d.From(100000.0, 0.0))
    end2 = DPoint3d.FromSumOf(start2, DPoint3d.From(-50000.0, -50000.0))
    eeh2 = PSampUtility.CreateLineAndAdd2Model(start2, end2, dgnModel, True)

    # draw the linestring
    points = DPoint3dArray()
    ptBase = start2
    ptBase = DPoint3d.FromSumOf(ptBase, DPoint3d.From(30000.0, 0.0))
    points.append(ptBase)
    ptBase = DPoint3d.FromSumOf(ptBase, DPoint3d.From(60000.0, -60000.0))
    points.append(ptBase)
    ptBase = DPoint3d.FromSumOf(ptBase, DPoint3d.From(0.0, 70000.0))
    points.append(ptBase)
    ehLineString = PSampUtility.CreateLineStringAndAdd2Model(points, dgnModel, True)

    elems = ElementAgenda()
    elems.Insert(eeh1.GetElementRef(), eeh1.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eFix)

    elems.Empty(False)
    elems.Insert(eeh1.GetElementRef(), eeh1.GetModelRef())
    elems.Insert(eeh2.GetElementRef(), eeh2.GetModelRef()) 
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel)

    elems.Empty(False)
    elems.Insert(eeh1.GetElementRef(), eeh1.GetModelRef())
    elems.Insert(eeh2.GetElementRef(), eeh2.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual)

    elems.Empty(False)
    elems.Insert(eeh2.GetElementRef(), eeh2.GetModelRef())
    elems.Insert(ehLineString.GetElementRef(), ehLineString.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident)

    elems.Empty(False)
    elems.Insert(eeh2.GetElementRef(), eeh2.GetModelRef())
    elems.Insert(ehLineString.GetElementRef(), ehLineString.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular)
    
    elems.Empty(False)
    elems.Insert(ehLineString.GetElementRef(), ehLineString.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eAngle, 0, 1, 0, 0, 135.0*3.1415 / 180.0)

def ExampleConstraintConcentricAndTangent():
    """
    Demonstrates the creation of various 2D geometric shapes and the application of concentric and tangent constraints 
    between them in a DGN model.
    The function performs the following steps:
    1. Retrieves the active DGN model.
    2. Creates a complex shape using a set of predefined points and adds it to the model.
    3. Creates three circles and one arc with specified centers and radii, and adds them to the model.
    4. Applies concentric constraints between the created circles.
    5. Applies tangent constraints between the complex shape and the first circle, the complex shape and the ellipse, 
       and the complex shape and the arc.
    
    Returns:
        None
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    if (dgnModel is None):
        return

    center = DPoint3d.From(0.0, 0.0, 0.0)
    points = DPoint3dArray()
    points.append(DPoint3d.From(40000.0, 0.0,     0.0))
    points.append(DPoint3d.From(40000.0, 40000.0, 0.0))
    points.append(DPoint3d.From(-40000.0, 40000.0, 0.0))
    points.append(DPoint3d.From(-40000.0, 0.0,     0.0))

    eehCplxShape = createComplexShapeAndAdd2Model(points, center, True, dgnModel, True)

    ptBase = center

    center1 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(-30000.0, 3 * 40000.0))
    radius1 = 20000.0
    eehCircle1 = PSampUtility.CreateEllipseAndAdd2Model(center1, radius1, radius1, dgnModel, True)

    center2 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(-30000.0, 2 * 40000.0))
    radius2 = 10000.0
    eehCircle2 = EditElementHandle()
    eehCircle2 = PSampUtility.CreateEllipseAndAdd2Model(center2, radius2, radius2, dgnModel, True)

    center3 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(30000.0, 2 * 40000.0))
    radius1 = 10000.0
    radius2 = 20000.0
    eehEllipse = EditElementHandle()
    eehEllipse = PSampUtility.CreateEllipseAndAdd2Model(center3, radius1, radius2, dgnModel, True)

    center4 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(40000.0+30000.0, 20000.0))
    radius4 = 20000.0
    eehArc = PSampUtility.CreateArcAndAdd2Model(center4, radius4, radius4, Angle.PiOver2(), Angle.Pi(), dgnModel, True)

    elems = ElementAgenda()
    elems.Insert(eehCircle1.GetElementRef(), eehCircle1.GetModelRef())
    elems.Insert(eehCircle2.GetElementRef(), eehCircle2.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eConcentric)

    elems.Empty(False)
    elems.Insert(eehCplxShape.GetElementRef(), eehCplxShape.GetModelRef())
    elems.Insert(eehCircle1.GetElementRef(), eehCircle1.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eTangent, 0, 1)

    elems.Empty(False)
    elems.Insert(eehCplxShape.GetElementRef(), eehCplxShape.GetModelRef())
    elems.Insert(eehEllipse.GetElementRef(), eehEllipse.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eTangent, 0, 1)

    elems.Empty(False)
    elems.Insert(eehCplxShape.GetElementRef(), eehCplxShape.GetModelRef())
    elems.Insert(eehArc.GetElementRef(), eehArc.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eTangent)

def ExampleConstraintDistanceAndEqualDistance():
    """
    Demonstrates the creation of lines and the application of distance and equal distance constraints 
    in a 2D parametric modeling environment.
    This function performs the following steps:
    1. Retrieves the active DGN model.
    2. Draws three lines at specified coordinates.
    3. Applies a distance constraint to the third line.
    4. Applies an equal distance constraint to all three lines.
    The constraints are managed using the `Constraint2dManager` and the elements are handled using 
    the `ElementAgenda`.
    
    Returns:
        None
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    if (dgnModel is None):
        return

    ptBase = DPoint3d.From(0.0, 0.0)

    # draw the first line
    start1 = ptBase
    end1 = DPoint3d.FromSumOf(start1, DPoint3d.From(200000.0, 0.0))
    eeh1 = PSampUtility.CreateLineAndAdd2Model(start1, end1, dgnModel, True)

    # draw the second line
    start2 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(0.0, 30000.0))
    end2 = DPoint3d.FromSumOf(start2, DPoint3d.From(100000.0, 0.0))
    eeh2 = PSampUtility.CreateLineAndAdd2Model(start2, end2, dgnModel, True)

    # draw the third line
    start3 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(0.0, 50000))
    end3 = DPoint3d.FromSumOf(start3, DPoint3d.From(250000.0, 0.0))
    eeh3 = PSampUtility.CreateLineAndAdd2Model(start3, end3, dgnModel, True)

    elems = ElementAgenda()
    elems.Insert(eeh3.GetElementRef(), eeh3.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, 0, 0, 0, 0, 150000.0)

    elems.Empty(False)
    elems.Insert(eeh1.GetElementRef(), eeh1.GetModelRef())
    elems.Insert(eeh2.GetElementRef(), eeh2.GetModelRef())
    elems.Insert(eeh3.GetElementRef(), eeh3.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual_Distance)

def ExampleConstraintAreaPerimeterRadiusAndMajorRadius():
    """
    Demonstrates the creation of various geometric shapes (circles, arc, ellipse) and 
    the application of 2D constraints (area, perimeter, major radius, radius) to them 
    in a DGN model.
    The function performs the following steps:
    1. Retrieves the active DGN model.
    2. Draws a circle at the base point with a specified radius.
    3. Draws a second circle offset from the base point.
    4. Draws an arc at a specified offset from the base point.
    5. Draws an ellipse at a specified offset from the base point.
    6. Adds an area constraint to the first circle.
    7. Adds a perimeter constraint to the second circle.
    8. Adds a major radius constraint to the ellipse.
    9. Adds a radius constraint to the arc.
    
    Returns:
        None
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    if (dgnModel is None):
        return

    ptBase = DPoint3d.From(0.0, 0.0, 0.0)

    #draw the first circle
    center1 = ptBase
    radius1 = 200000.0
    eehCircle1 = PSampUtility.CreateEllipseAndAdd2Model(center1, radius1, radius1, dgnModel, True)

    # draw the second circle
    center2 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(100000.0, 0.0))
    radius2 = 200000.0
    eehCircle2 = PSampUtility.CreateEllipseAndAdd2Model(center2, radius2, radius2, dgnModel, True)

    # draw the arc
    center4 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(200000.0, 0.0))
    radius4 = 2000.0
    eehArc = PSampUtility.CreateArcAndAdd2Model(center4, radius4, radius4, Angle.PiOver2(), Angle.Pi(), dgnModel, True)

    # draw the ellipse
    center3 = DPoint3d.FromSumOf(ptBase, DPoint3d.From(300000.0, 0.0))
    radius1 = 30000.0
    radius2 = 20000.0
    eehEllipse = PSampUtility.CreateEllipseAndAdd2Model(center3, radius1, radius2, dgnModel, True)

    elems = ElementAgenda()
    elems.Insert(eehCircle1.GetElementRef(), eehCircle1.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eArea, 0, 0, 0, 0, 500000000.0)

    elems.Empty(False)
    elems.Insert(eehCircle2.GetElementRef(), eehCircle2.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerimeter, 0, 0, 0, 0, 200000.0)

    elems.Empty(False)
    elems.Insert(eehEllipse.GetElementRef(), eehEllipse.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eMajor_Radius, 0, 0, 0, 0, 40000.0)

    elems.Empty(False)
    elems.Insert(eehArc.GetElementRef(), eehArc.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eRadius, 0, 0, 0, 0, 40000)

def ExampleConstraintDistanceWithVariable():
    """
    Demonstrates how to create a distance constraint with a variable in a DGN model.
    This function performs the following steps:
    1. Retrieves the active DGN model.
    2. Draws a line from a base point to a specified end point.
    3. Creates a variable with a specified name and value.
    4. Adds a distance constraint to the created line using the variable.
    
    Returns:
        None
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    if (dgnModel is None):
        return

    ptBase = DPoint3d.From(0.0, 0.0)

    # draw the first line
    start= ptBase
    end = DPoint3d.FromSumOf(start, DPoint3d.From(25000.0, 0.0))
    eeh = PSampUtility.CreateLineAndAdd2Model(start, end, dgnModel, True)

    # create a variable
    varName = "var"
    value = 15000.0
    VariableAndVariation.CreateVariable(varName, ParameterType.eDistance, value, dgnModel)

    elems = ElementAgenda()
    elems.Insert(eeh.GetElementRef(), eeh.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, 0, 0, 0, 0, value, varName)

def ExampleExtrudeFeatureWithRadiusConstraint(dgnModel):
    """
    Creates a parametric solid cylinder by extruding a circle profile with a radius constraint.
    
    :param dgnModel: The design model in which the elements will be created.
    :type dgnModel: object
    
    :return: The created parametric solid cylinder or None if the operation fails.
    :rtype: object or None
    """
    if (dgnModel is None):
        return None

    # Create variables and parameter sets
    VariableAndVariation.CreateCircleVariableAndParameterSets(dgnModel)

    # Create a circle element as the profile
    profileEditElementHandle = PSampUtility.CreateEllipseAndAdd2Model(DPoint3d.From(0.0, 0.0, 0.0), 20000.0, 20000.0, dgnModel, True)
    if (profileEditElementHandle is None):
        return None

    # Add 2D radius constraint to the ellipse element, set variable name as "Radius" which is defined in VariableAndVariation.CreateCircleVariableAndParameterSets()
    AddRadiusConstraintToElement(profileEditElementHandle, 20000.0, "Radius")

    # Make parametric solid cylinder by extruding the circle profile
    return ParametricSolid.CreateSmartFeatureElementExtrude(profileEditElementHandle)

def RunSamples(index = 1):
    """
    Run sample constraint functions based on the provided index.

    :param index: An integer representing the sample to run. Defaults to 1.
                    The valid values are:
                    0 - Run ExampleExtrudeFeatureWithRadiusConstraint.
                    1 - Run ExampleConstraintPerpendicular.
                    2 - Run ExampleConstraintConcentricAndTangent.
                    3 - Run ExampleConstraintFixParallelEqualCoincidentPerpendicularAngle.
                    4 - Run ExampleConstraintDistanceAndEqualDistance.
                    5 - Run ExampleConstraintAreaPerimeterRadiusAndMajorRadius.
                    6 - Run ExampleConstraintDistanceWithVariable.
                    7 - Run ExampleConstraintConcentricAndTangent.
    """
    if (1 == index):
        ExampleConstraintPerpendicular()
    elif(2 == index):
        ExampleConstraintConcentricAndTangent()
    elif(3 == index):
        ExampleConstraintFixParallelEqualCoincidentPerpendicularAngle()
    elif(4 == index):
        ExampleConstraintDistanceAndEqualDistance()
    elif(5 == index):
        ExampleConstraintAreaPerimeterRadiusAndMajorRadius()
    elif(6 == index):
        ExampleConstraintDistanceWithVariable()
    elif(7 == index):
        ExampleConstraintConcentricAndTangent()
    elif(0 == index):
        if (ExampleExtrudeFeatureWithRadiusConstraint(ISessionMgr.GetActiveDgnModel()) is None):
            print("Return false when calling ExampleExtrudeFeatureWithRadiusConstraint()")

if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    RunSamples(6)
