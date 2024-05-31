# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''Create level by given name in active model'''
def createLevel(levelName):
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


'''Create a set of parallel lines in Microstation'''
def createLine(basePoint, length=200, count=10, step=10):
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


'''Change properties of the line element in active model'''
def changeLineProperties():
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
