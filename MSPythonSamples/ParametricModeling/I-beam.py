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

'''
Example demonstrating how to create I-beam profile with 2D constraint
''' 

def createVariables(dgnModel):
    """
    Create and initialize distance variables in the given design model.
    This function creates five distance variables in the specified design model.
    Four of the variables are initialized with fixed values, while the fifth variable
    is initialized with an expression based on one of the other variables.
    
    :param dgnModel: The design model in which to create the variables.
    :type dgnModel: object
    
    :return: Returns True upon successful creation of the variables.
    :rtype: bool
    """
    VariableAndVariation.CreateVariable("var1", ParameterType.eDistance, 5000, dgnModel) # Create distance variable "var1"
    VariableAndVariation.CreateVariable("var2", ParameterType.eDistance, 110000, dgnModel) # Create distance variable "var2"
    VariableAndVariation.CreateVariable("var3", ParameterType.eDistance, 10000, dgnModel) # Create distance variable "var3"
    VariableAndVariation.CreateVariable("var4", ParameterType.eDistance, 100000, dgnModel) # Create distance variable "var4"
    VariableAndVariation.CreateVariableWithExpression("var5", ParameterType.eDistance, 50000, "var4/2", dgnModel) # Create distance expression variable "var5" which is half of var2

    return True

def ExampleCreateIbeamProfile():
    """
    Creates an I-beam profile in the active DGN model.
    This function performs the following steps:
    1. Creates variables used for the I-beam profile.
    2. Creates a base line as a construction element.
    3. Adds fixed constraints to the base line to fix its direction and base point.
    4. Creates lines for the I-beam profile without adding them to the model.
    5. Creates a complex shape header and adds the I-beam profile lines to it.
    6. Adds the complex shape to the model.
    7. Adds various constraints (equal, parallel, perpendicular, equal distance, distance, and coincident) to the lines in the complex shape.
    
    Returns:
        bool: True if the I-beam profile is successfully created and added to the model, False otherwise.
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()

    # Create variables which are used for the I-beam profile
    createVariables(dgnModel)

    # Create a base line as construction
    ehLine = PSampUtility.CreateLineAndAdd2Model(DPoint3d(0.0, 50000.0, 0.0), DPoint3d(0.0, 0.0, 0.0), dgnModel, True, 6, 2, DgnElementClass.eConstruction)

    # Add fixed constraint for the base line to fix it's direction and base point
    elems = ElementAgenda()
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eFix) # Fix the direction

    primitiveIds = Int32Array()
    subIndexs = Int32Array()
    vertexTypes = VertexTypeArray()

    primitiveIds.append(0)
    subIndexs.append(0)
    vertexTypes.append(VertexType.eEnd)
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eFix, primitiveIds, subIndexs, vertexTypes) # Fix the end point

    # Create I-beam profile lines for the which will be added to the complex shape, pass false not adding the lines to model as they will be added with the complex shape
    eh1 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(-55000, 50000.0, 0.0), DPoint3d(55000, 50000.0, 0.0), dgnModel, False)
    eh2 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(55000, 50000.0, 0.0), DPoint3d(55000, 40000.0, 0.0), dgnModel, False)
    eh3 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(55000, 40000.0, 0.0), DPoint3d(5000, 40000.0, 0.0), dgnModel, False)
    eh4 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(5000, 40000.0, 0.0), DPoint3d(5000, -40000.0, 0.0), dgnModel, False)
    eh5 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(5000, -40000.0, 0.0), DPoint3d(55000, -40000.0, 0.0), dgnModel, False)
    eh6 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(55000, -40000.0, 0.0), DPoint3d(55000, -50000.0, 0.0), dgnModel, False)
    eh7 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(55000, -50000.0, 0.0), DPoint3d(-55000, -50000.0, 0.0), dgnModel, False)
    eh8 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(-55000, -50000.0, 0.0), DPoint3d(-55000, -40000.0, 0.0), dgnModel, False)
    eh9 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(-55000, -40000.0, 0.0), DPoint3d(-5000, -40000.0, 0.0), dgnModel, False)
    eh10 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(-5000, -40000.0, 0.0), DPoint3d(-5000, 40000.0, 0.0), dgnModel, False)
    eh11 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(-5000, 40000.0, 0.0), DPoint3d(-55000, 40000.0, 0.0), dgnModel, False)
    eh12 = PSampUtility.CreateLineAndAdd2Model(DPoint3d(-55000, 40000.0, 0.0), DPoint3d(-55000, 50000.0, 0.0), dgnModel, False)

    # Creaet header will include all created lines above
    eehChainHeader = EditElementHandle()
    ComplexShapeHandler.CreateChainHeaderElement(eehChainHeader, None, True, dgnModel.Is3d(), dgnModel)

    # Add the lines to header for the complex shape
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh1)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh2)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh3)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh4)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh5)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh6)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh7)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh8)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh9)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh10)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh11)
    ComplexShapeHandler.AddComponentElement(eehChainHeader, eh12)

    # Add to model
    if (BentleyStatus.eSUCCESS != eehChainHeader.AddToModel()):
        return False

    # Add equal constrante for first line and the seventh line in the complex shape
    elems.Empty(False)
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 0, 0, 6, 0)

    # Add equal constrante for second line and the last line in the complex shape
    elems.Empty(False)
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 11, 0, 1, 0)

    # Add equal constrante for sixth line and the last line in the complex shape
    elems.Empty(False)
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 11, 0, 5, 0)

    # Add equal constrante for eighth line and the last line in the complex shape
    elems.Empty(False)
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual, 11, 0, 7, 0)

    # Add parallel constrante for base line and the second line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 1, 0)

    # Add parallel constrante for base line and the fourth line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 3, 0)

    # Add parallel constrante for base line and the sixth line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 5, 0)

    # Add parallel constrante for base line and the eighth line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 7, 0)

    # Add parallel constrante for base line and the tenth line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 9, 0)

    # Add parallel constrante for base line and the last line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eParallel, 0, 0, 11, 0)

    # Add perpendicular constrante for base line and the first line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular, 0, 0, 0, 0)

    # Add perpendicular constrante for base line and the third line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular, 0, 0, 2, 0)

    # Add perpendicular constrante for base line and the fifth line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular, 0, 0, 4, 0)

    # Add perpendicular constrante for base line and the seventh line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular, 0, 0, 6, 0)

    # Add perpendicular constrante for base line and the ninth line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular, 0, 0, 8, 0)

    # Add perpendicular constrante for base line and the eleventh line in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    Constraint2dManager.AddConstraint(elems, Constraint2dType.ePerpendicular, 0, 0, 10, 0)

    # Prepare elements for equal distance constrante between base line and the lines in the complex shape
    elems.Empty(False)
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())

    # Add equal distance constrante between base line and the fourth line, and between base line and the tenth line
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((3, 0, 9))
    subIndexs.extend((0, 0, 0))
    vertexTypes.extend((VertexType.eEdge, VertexType.eEdge, VertexType.eEdge))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual_Distance, primitiveIds, subIndexs, vertexTypes)

    # Add equal distance constrante between base line and the second line, and between base line and the last line
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((1, 0, 11))
    subIndexs.extend((0, 0, 0))
    vertexTypes.extend((VertexType.eEdge, VertexType.eEdge, VertexType.eEdge))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual_Distance, primitiveIds, subIndexs, vertexTypes)

    # Add equal distance constrante between base line and the sixth line, and between base line and the eighth line
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((5, 0, 7))
    subIndexs.extend((0, 0, 0))
    vertexTypes.extend((VertexType.eEdge, VertexType.eEdge, VertexType.eEdge))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eEqual_Distance, primitiveIds, subIndexs, vertexTypes)

    # Prepare elements for distance constrante between the lines in the complex shape
    elems.Empty(False)
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())

    # Add distance constrante for the last line(pass it's start point and end point as the vertex type), and associate it with "var1" variable
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((11, 11))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eStart, VertexType.eEnd))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 5000, "var1")

    # Add distance constrante for the first line(pass it's start point and end point as the vertex type), and associate it with "var2" variable
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((0, 0))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eStart, VertexType.eEnd))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 110000, "var2")

    # Add distance constrante the fourth line and the tenth line(pass start point of the fourth line and end point of the tenth line as the vertex type), and associate it with "var3" variable
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((3, 9))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eStart, VertexType.eEnd))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 10000, "var3")


    # Prepare elements for distance and coincident constrante between base line and the lines in the complex shape
    elems.Empty(False)
    elems.Insert(ehLine.GetElementRef(), ehLine.GetModelRef())
    elems.Insert(eehChainHeader.GetElementRef(), eehChainHeader.GetModelRef())

    # Add distance constrante between the end point of the base line and the first line in the complex shape
    # (pass end point of the fourth line and edge of the first line as the vertex type), and associate it with "var5" variable
    # "var5" is a expression variable which is half of "var4"
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((0, 0))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eEnd, VertexType.eEdge))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 50000, "var5")

    # Add distance constrante between the start point of the base line and the seventh line in the complex shape
    # (pass start point of the fourth line and edge of the seventh line as the vertex type), and associate it with "var4" variable
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((0, 6))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eStart, VertexType.eEdge))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eDistance, primitiveIds, subIndexs, vertexTypes, 100000, "var4")

    # Add coincident constrante for the start point of the base line and the first line in the complex shape
    # Pass start point of the base line and edge of the first line in complex shape as the vertex type)
    primitiveIds.clear()
    subIndexs.clear()
    vertexTypes.clear()
    primitiveIds.extend((0, 0))
    subIndexs.extend((0, 0))
    vertexTypes.extend((VertexType.eStart, VertexType.eEdge))
    Constraint2dManager.AddConstraint(elems, Constraint2dType.eCoincident, primitiveIds, subIndexs, vertexTypes)

    return True

if __name__ == "__main__":
    ExampleCreateIbeamProfile()
