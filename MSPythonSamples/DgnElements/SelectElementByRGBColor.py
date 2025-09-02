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
This sample demonstrates how to select elements by RGB color.
'''

def selectElementsbyColor(userColor):
    """
    Select elements in the active model by their RGB color.

    This function iterates through all graphical elements in the active model,
    checks their RGB color, and adds elements that match the specified color
    to the selection set.

    :param userColor: A dictionary containing the RGB values to match.
                      Example: {'r': 255, 'g': 0, 'b': 0} for red color.
    :type userColor: dict
    """
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
            eleinfoColor = DgnColorMap.ExtractElementColorInfo(color , dgnfile)
            rgbdef       = RgbColorDef
            rgbdef       = eleinfoColor[1].m_rgb #RGB in IntColorDef
            red   = rgbdef.red
            green = rgbdef.green
            blue  = rgbdef.blue 
            print("red,green,blue-->",red, green, blue)

            if (red   == userColor.get('r') and green == userColor.get('g') and blue  == userColor.get('b')):
                selSetManager.AddElement(perElementRef,dgnModel)

    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {len (agenda)} elements")
    # iterate using __iter__ over the selection set printing the element ids of elements in the selection set
    for editElementHandle in agenda:
        print(f"  Element ID: {editElementHandle.GetElementId()}")
        
# Prerequisite: Open MSPythonSamples\\data\\SelectExample.dgn with 'Color' model 
#main
if __name__ == "__main__":
    #highlight all the elements based on color
    userColor = {'r':255, 'g':128, 'b':66} 
    selectElementsbyColor(userColor)