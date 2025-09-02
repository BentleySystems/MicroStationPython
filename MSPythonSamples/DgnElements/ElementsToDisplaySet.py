# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import sys

'''
Sample demonstrating how to select elements in the active DGN model by the specified level name and  create display set by its level number
Prerequisite : Run the sample on DisplaySetExample.dgn 
'''

def getLevelName(lvlName, lvlId):
    """
    Checks if a level with the specified name and ID exists in the active DGN model. Iterates over all the levels in the active model to do this

    :param lvlName: The name of the level to check.
    :type lvlName: str
    :param lvlId: The ID of the level to check.
    :type lvlId: int

    :returns: True if the level with the specified name and ID exists, False otherwise.
    :rtype: bool
    """
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


def selectElementsbyLevelName(userLevelName):
    """
    Selects elements in the active DGN model by the specified level name and  create display set by its level number

    :param userLevelName: The name of the level to select elements from.
    :type userLevelName: str

    :returns: None
    """
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
Update the View in Microstation to see the results in view
'''

#main
if __name__ == "__main__":
    #Add graphical elements to display set, which are part of "Default" level
    userLevelName = "Default"
    selectElementsbyLevelName(userLevelName)