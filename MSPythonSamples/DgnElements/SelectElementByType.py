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
This sample demonstrates how to select elements of a specific type
'''

'''
Function to select elements by its type
    inputElementType : int      Element type
'''
def selectElementsbyType(inputElementType):
    """
    Select elements of a specific type from the active model.

    This function retrieves all graphical elements from the active model and adds 
    elements of the specified type to the selection set.

    :param inputElementType: The type of elements to select.
    :type inputElementType: int
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
            eleType = eh.GetElementType()
            if(eleType == inputElementType):
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
    #highlight all the elements with type 
    #2-D/3-D Line Element (type 3)
    #2-D/3-D Line String Element (type 4)
    #2-D/3-D Ellipse Element (type 15)
    #2-D/3-D Arc Element (type 16)
    inputElementType = 3
    selectElementsbyType(inputElementType)