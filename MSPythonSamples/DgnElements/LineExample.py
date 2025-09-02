# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''
This sample demonstrates how to changes the color, linestyle, weight, and level of an element
'''

def createLevel(levelName):
    """
    Creates a level in the active DGN file if it does not already exist.

    :param levelName: The name of the level to create.
    :type levelName: str

    :returns: The ID of the created or existing level if successful, False otherwise.
    :rtype: int or bool
    """
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if dgnFile is None:
        return False

    levelCatch = dgnFile.GetLevelCache()
    if levelCatch is None:
        return False

    LevelHandle = levelCatch.GetLevelByName(levelName)
    if not LevelHandle.IsValid():
        LevelHandle = levelCatch.CreateLevel(levelName, LEVEL_NULL_CODE, LEVEL_NULL_ID)
        if not LevelHandle.IsValid():
            return False
        levelCatch.Write()

    return LevelHandle.GetLevelId()



def createLine(basePoint, length=200, count=10, step=10):
    """
    Creates multiple lines in the active DGN model.

    :param basePoint: The starting point for the first line.
    :type basePoint: DPoint3d
    :param length: The length of each line.
    :type length: float
    :param count: The number of lines to create.
    :type count: int
    :param step: The distance between the starting points of consecutive lines.
    :type step: float

    :returns: True if all lines are successfully created and added to the model, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False

    eeh = EditElementHandle()
    xDir = DVec3d(1, 0, 0)
    yDir = DVec3d(0, 1, 0)
    
    # Create lines into current model
    for i in range(count):
        point1 = basePoint + i * step * yDir
        point2 = point1 + length * xDir
        seg = DSegment3d(point1, point2)
        
        # Create line element
        status = LineHandler.CreateLineElement(eeh, None, seg, 
                                               ACTIVEMODEL.Is3d(), 
                                               ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != status:
            return False
        
        # Set color, weight to the created line element
        color = 100
        lineWeight = 2
        propertiesSetter = ElementPropertiesSetter()
        propertiesSetter.SetColor(color)
        propertiesSetter.SetWeight(lineWeight)
        propertiesSetter.Apply(eeh)
            
        # Add the line element to model
        if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False

    return True


def changeLineProperties():
    """
    Changes the properties of line elements in the active DGN model.

    This function performs the following steps:
    1. Creates a new level named "MyNewLevel".
    2. Retrieves all graphical elements from the active DGN model.
    3. Changes the color, linestyle, weight, and level of line elements.

    :returns: True if the properties of all line elements are successfully changed, False otherwise.
    :rtype: bool
    """
    dgnModel = ISessionMgr.ActiveDgnModel
    if dgnModel is None:
        return False

    levelID = createLevel("MyNewLevel")
    # Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    for elementRef in graphicalElements:
        eeh = EditElementHandle(elementRef, dgnModel)
        msElement = eeh.GetElement()
        isGraphics = msElement.ehdr.isGraphics
        isVisible = not(msElement.hdr.dhdr.props.b.invisible)
        eleType = eeh.GetElementType()
        # Change color, linestyle, weight to the line element
        if (isGraphics and isVisible and MSElementTypes.eLINE_ELM == eleType):
            color = 50
            lineStyle = 4
            lineWeight = 5
            propertiesSetter = ElementPropertiesSetter()
            propertiesSetter.SetColor(color)
            propertiesSetter.SetLinestyle(lineStyle, None)
            propertiesSetter.SetWeight(lineWeight)
            propertiesSetter.SetLevel(levelID)
            if True == propertiesSetter.Apply(eeh):
                # Save the changes to model
                if BentleyStatus.eSUCCESS != eeh.ReplaceInModel(elementRef):
                    return False
            
        
    return True


if __name__ == "__main__":
    if True != createLine(DPoint3d(0, 0, 0)):
        print("Return false when call createLine!")    
    if True != changeLineProperties():
        print("Return false when call changeLineProperties!")
