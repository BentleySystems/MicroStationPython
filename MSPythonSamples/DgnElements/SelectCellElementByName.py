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
This sample demonstrates how to select cell elements by name
'''

def selectCellElementsbyName(inputCellName):
    """
    Selects cell elements in the active DGN model by the specified cell name.

    :param inputCellName: The name of the cell to select.
    :type inputCellName: str

    :returns: None
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
            #2-D Cell Element (complex element, type 2)
            #3-D Cell Element (complex element, type 3)
            #Shared Cell Instance (type 35)
            if((eleType == 3 or eleType == 2) and cellName[1] == inputCellName):
                #It will select highlight all elements added in selection set
                selSetManager.AddElement(perElementRef,dgnModel)         

    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {len (agenda)} elements")
    # iterate using __iter__ over the selection set printing the element ids of elements in the selection set
    for element in agenda:
        print(f"  Element ID: {element.GetElementId()}")
    
    
#main
if __name__ == "__main__":
    #highlight all the elements with type 2,3
    inputCellName = "cellelement"
    selectCellElementsbyName(inputCellName)