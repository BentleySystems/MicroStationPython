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
Function to create display set by its level number
    userLevelName : str      Level name
'''
def selectElementsbyLevelName(userLevelName):
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()

    itgraphicalElements = iter(graphicalElements)
    #element.GetElementRef()->SetInDisplaySet (element.GetModelRef(), true);
    for perElementRef in itgraphicalElements:
        eeh = EditElementHandle(perElementRef, dgnModel)
        eh = ElementHandle(perElementRef)
        msElement = MSElement()
        msElement = eeh.GetElement ()
        levelId = msElement.ehdr.level
        bMatch = getLevelName(userLevelName, levelId)
        #if yesNo is false, then
        #if modelRef is NULL, set it up so that nothing is in the displaySet
        #otherwise, remove the given modelRef from the displaySet.
        #if yesNo is true, then
        #if modelRef is NULL, set it up so everything is in the displaySet.
        #otherwise, add the given modelRef from the displaySet.    
        perElementRef.SetInDisplaySet (None, True)
        #It will select highlight all elements added in selection set 
        if bMatch:
            perElementRef.SetInDisplaySet(None, False)
        print(perElementRef.IsInDisplaySet(None))

'''
Prerequisite : Run the sample on DisplaySetExample.dgn 
Update the View in Microstation to see the results in view
'''

#main
if __name__ == "__main__":
    #Add graphical elements to display set, which are part of "Default" level
    userLevelName = "Default"
    selectElementsbyLevelName(userLevelName)