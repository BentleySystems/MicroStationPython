# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $


from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import sys

'''
This sample demonstrates how to select elements by level name
'''

def getLevelName(lvlName, lvlId):
    """
    Check if a level with the specified name and ID exists in the active model.

    :param str lvlName: The name of the level to search for.
    :param int lvlId: The ID of the level to search for.
    :return: True if a level with the specified name and ID exists, False otherwise.
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
    Select and highlight all graphical elements in the active model that belong to the specified level name.

    :param str userLevelName: The name of the level to select elements from.
    """
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
    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {agenda.GetCount()} elements")
    # iterate over the selection set printing the element ids of elements in the selection set
    for i in range(agenda.GetCount()):
        editElementHandle = agenda.GetEntry(i)
        print (f"  Element ID: {editElementHandle.GetElementId()}")
   

#main
if __name__ == "__main__":
    #highlight all the elements available on level "Default"
    userLevelName = "Default"
    selectElementsbyLevelName(userLevelName)