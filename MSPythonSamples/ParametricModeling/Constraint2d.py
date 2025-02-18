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
Function to add ConstraintData to Model
'''
def addConstraintDataToModel(solverData):
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


'''
Function to create CurveEntityIdentifier
'''
def createLineCurveEntityId(point1, point2):
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


'''
Function to add radius 2D constraint to element,
you can specifi a variable to the constraint, so that the constraint will use the variable value as radius
if variable name is empty, then new value specified will be used as the radius constraint
'''
def AddRadiusConstraintToElement(profileEditElementHandle, newValue, varName):
    ModelRef.ActivateAndDisplay(profileEditElementHandle.GetModelRef())
    elems = ElementAgenda() # Define element agenda
    elems.Insert(profileEditElementHandle.GetElementRef(), profileEditElementHandle.GetModelRef()) # Add element ref to element agenda
    return Constraint2dManager.AddConstraint(elems, Constraint2dType.eRadius, 0, 0, 0, 0, newValue, varName) # Add constraint

'''
Example to show how to append a perpendicular constraint on two lines
'''
def ExampleConstraintPerpendicular():
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

'''
Example for 2D constraint: Fix, Parallel, Equal, Coincident, Perpendicular and Angle 
''' 
def ExampleConstraintFixParallelEqualCoincidentPerpendicularAngle():
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

'''
Example for 2D constraint: Concentric And Tangent
''' 
def ExampleConstraintConcentricAndTangent():
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

'''
Example for 2D constraint: Distance And EqualDistance
''' 
def ExampleConstraintDistanceAndEqualDistance():
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

'''
Example for 2D constraint: Area, Perimeter, Radius And MajorRadius
''' 
def ExampleConstraintAreaPerimeterRadiusAndMajorRadius():
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

'''
Example for Distance constraint with variable
''' 
def ExampleConstraintDistanceWithVariable():
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

'''
Example to show how to create a cylinder by extruding a circle which has a 2D radius constraint
'''
def ExampleExtrudeFeatureWithRadiusConstraint(dgnModel):
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
    elif(0 == index):
        if (ExampleExtrudeFeatureWithRadiusConstraint(ISessionMgr.GetActiveDgnModel()) is None):
            print("Return false when calling ExampleExtrudeFeatureWithRadiusConstraint()")

if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    RunSamples(6)
