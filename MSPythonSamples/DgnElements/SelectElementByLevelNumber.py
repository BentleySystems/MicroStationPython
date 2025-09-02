# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import sys

'''
This sample demonstrates how to select elements by level number
'''

def selectElementsbyLevelNumber(userLevelNumber):
    """
    Select elements in the active model by their level number.

    This function retrieves all graphical elements from the active model and adds 
    elements with the specified level number to the selection set.

    :param userLevelNumber: The level number to filter elements by.
    :type userLevelNumber: int
    """
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()
    for perElementRef in graphicalElements:
        eeh = EditElementHandle(perElementRef, dgnModel)
        msElement = MSElement()
        msElement = eeh.GetElement ()
        levelId = msElement.ehdr.level
        #It will select highlight all elements added in selection set 
        if levelId == userLevelNumber:
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
    #highlight all the elements available on level 64
    userLevelNumber = 64
    selectElementsbyLevelNumber(userLevelNumber)