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
This sample demonstrates how to select elements by color
'''

def selectElementsbyColor(userColorIndex):
    """
    Select elements in the active model by their color index.

    This function retrieves all graphical elements from the active model and 
    selects those whose color index matches the specified userColorIndex.

    :param userColorIndex: The color index to match for selecting elements.
    :type userColorIndex: int
    """
    # Get 
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    dgnfile = dgnModel.GetDgnFile()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()

    for elRefCnt in range(len(list(graphicalElements))):
        perElementRef = list(graphicalElements)[elRefCnt]
        elementId = perElementRef.GetElementId()
        eeh = EditElementHandle(perElementRef, dgnModel)
        eh = ElementHandle(perElementRef)

        msElement = MSElement()
        msElement = eeh.GetElement ()
        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        if (isGraphics and not(isInvisible)):
            propQuery    = ElementPropertiesGetter(eh)
            color        = propQuery.GetColor()
            print("color-->",int(color))

            if (userColorIndex == int (color)):
                 selSetManager.AddElement(perElementRef,dgnModel) 

    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {len (agenda)} elements")
    # iterate using __iter__ over the selection set printing the element ids of elements in the selection set
    for editElementHandle in agenda:
        print(f"  Element ID: {editElementHandle.GetElementId()}")
    

#Prerequisite: Open MSPythonSamples\\data\\SelectExample.dgn with 'Color' model 
#main
if __name__ == "__main__":
    #highlight all the elements based on color
    userColorIndex = 1
    selectElementsbyColor(userColorIndex)