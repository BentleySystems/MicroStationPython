# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import ctypes
import pywin.debugger
import sys
pywin.debugger.set_trace()

'''
Function to select elements by its RGBColor
    userColorIndex : int      color index value
'''
def selectElementsbyColor(userColorIndex):
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

'''
Prerequisite: Open MSPythonSamples\data\SelectExample.dgn with 'Color' model 
'''
#main
if __name__ == "__main__":
    #highlight all the elements based on color
    userColorIndex = 1
    selectElementsbyColor(userColorIndex)