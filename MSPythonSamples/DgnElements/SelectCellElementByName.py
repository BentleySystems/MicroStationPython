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
import sys


'''
Function to select cell element by its name
    inputCellName : str      Cell name string
'''
def selectCellElementsbyName(inputCellName):
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

#main
if __name__ == "__main__":
    #highlight all the elements with type 2,3
    inputCellName = "cellelement"
    selectCellElementsbyName(inputCellName)