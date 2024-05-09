# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import sys

'''
Function to iterate levels available on model
    lvlName : str      Level Name
    lvlId   : int      Level number
'''
def getLevelName(lvlName, lvlId):
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    levelCache = ACTIVEMODEL.GetDgnFile().GetLevelCache()

    it = iter(levelCache)
    for level in it:
        levelName = level.GetName()
        levelId   = level.GetLevelId()
        if lvlName == levelName and lvlId == levelId:
            return True

    return False

'''
Function to select elements by its level number
    userLevelNumber : int      Level number to select
'''
def selectElementsbyLevelName(userLevelName):
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()

    itgraphicalElements = iter(graphicalElements)

    for perElementRef in itgraphicalElements:
        eeh = EditElementHandle(perElementRef, dgnModel)
        msElement = MSElement()
        msElement = eeh.GetElement ()
        levelId = msElement.ehdr.level
        bMatch = getLevelName(userLevelName, levelId)

        #It will select highlight all elements added in selection set 
        if bMatch:
            selSetManager.AddElement(perElementRef,dgnModel)


#main
if __name__ == "__main__":
    #highlight all the elements available on level "Default"
    userLevelName = "Default"
    selectElementsbyLevelName(userLevelName)