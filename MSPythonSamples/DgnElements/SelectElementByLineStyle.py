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
This sample demonstrates how to select elements by line style
'''

def selectElementsbyLineStyle(userLineStyle):
    """
    Select elements in the active model by their line style.

    This function retrieves all graphical elements from the active model and 
    selects those that match the specified line style. The selected elements 
    are added to the selection set.

    :param userLineStyle: The line style to match for selection.
    :type userLineStyle: int
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
            lineStyle = propQuery.GetLineStyle ()
            if(lineStyle == userLineStyle):
                #It will select highlight all elements added in selection set
                selSetManager.AddElement(perElementRef,dgnModel)         
    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {len (agenda)} elements")
    # iterate using __iter__ over the selection set printing the element ids of elements in the selection set
    for editElementHandle in agenda:
        print(f"  Element ID: {editElementHandle.GetElementId()}")

#main
if __name__ == "__main__":
    #highlight all the elements with LineStyle - Continue
    userLineStyle = 5
    selectElementsbyLineStyle(userLineStyle)