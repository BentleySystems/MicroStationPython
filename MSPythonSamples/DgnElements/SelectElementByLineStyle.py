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
Function to select elements by its line style
    userLineStyle : int      Line style number from user
'''
def selectElementsbyLineStyle(userLineStyle):
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


#main
if __name__ == "__main__":
    #highlight all the elements with LineStyle - Continue
    userLineStyle = 5
    selectElementsbyLineStyle(userLineStyle)