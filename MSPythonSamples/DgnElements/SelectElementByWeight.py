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
This sample demonstrates how to Selects and highlights all graphical elements in the active model that match the specified weight
'''

def selectElementsbyWeight(inputWeight):
    """
    Selects and highlights all graphical elements in the active model that match the specified weight.

    :param inputWeight: The weight of the elements to be selected.
    :type inputWeight: int
    """
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #name =  model.GetModelName()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    #eid 615
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
            propQuery = ElementPropertiesGetter(eh)
            weight = propQuery.GetWeight ()
            if(weight == inputWeight):
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
    #highlight all the elements with weight
    inputWeight = 5
    selectElementsbyWeight(inputWeight)