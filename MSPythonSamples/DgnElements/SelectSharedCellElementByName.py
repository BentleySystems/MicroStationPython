# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import ctypes
import sys

'''
This sample demonstrates how to select shared cell elements in the active model that match the given cell name
'''

def selectCellElementsbyName(inputCellName):
    """
    Selects and highlights all shared cell elements in the active model that match the given cell name.

    This function retrieves all graphical elements from the active model, checks if they are visible and of type 
    shared cell instance (type 35), and if their name matches the input cell name. If these conditions are met, 
    the elements are added to the selection set and highlighted.

    :param inputCellName: The name of the cell to be selected.
    :type inputCellName: str
    """
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()
        eeh = EditElementHandle(perElementRef, dgnModel)
        eh = ElementHandle(perElementRef)

        msElement = MSElement()
        msElement = eeh.GetElement ()

        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        if (isGraphics and not(isInvisible)):
            eleType = eh.GetElementType()
            cellName = NormalCellHeaderHandler.Instance.ExtractName(eh)  
            #Shared Cell Instance (type 35)
            if((eleType == 35) and cellName[1] == inputCellName):
                #It will select highlight all elements added in selection set
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
    #highlight all the elements with type 35
    inputCellName = "sharedcell"
    selectCellElementsbyName(inputCellName)