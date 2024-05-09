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
import sys

'''
Function to select elements by its level number
    userLevelNumber : int      Level number to select
'''
def selectElementsbyLevelNumber(userLevelNumber):
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()
    for perElementRef in graphicalElements:
        eeh = EditElementHandle(perElementRef, dgnModel)
        msElement = MSElement()
        msElement = eeh.GetElement ()
        levelId = msElement.ehdr.level
        #It will select highlight all elements added in selection set 
        if levelId == userLevelNumber:
            selSetManager.AddElement(perElementRef,dgnModel)
            


#main
if __name__ == "__main__":
    #highlight all the elements available on level 64
    userLevelNumber = 64
    selectElementsbyLevelNumber(userLevelNumber)