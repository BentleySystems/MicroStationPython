# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

'''
Running this sample needs to open GlassColor.dgn.
This sample shows how to change the glass panels color from darker to lighter from the top row to bottom row.
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import random


''' Check whether the element color need to be changed. '''
def needToChangeColor(msElement):
    # Element should be graphic, visible, not deleted and not construction
    if ((not msElement.ehdr.isGraphics) or msElement.hdr.dhdr.props.b.invisible
        or msElement.ehdr.deleted or msElement.hdr.dhdr.props.b.elementClass != 0):
        return False
    
    # Element should be on level "A-GLAZ" or "A-WALL-METL"
    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "A-GLAZ")
    if(ret1[0] != BentleyStatus.eSUCCESS):
        return False
    ret2 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "A-WALL-METL")
    if(ret2[0] != BentleyStatus.eSUCCESS):
        return False

    levelID1 = ret1[1]
    levelID2 = ret2[1]
    if(msElement.ehdr.level != levelID1 and msElement.ehdr.level != levelID2):
        return False
    
    return True

def GetElementByXCoordinate():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()
    categorizedElementsByX = {}
    for elementRef in graphicalElements:
        eeh = EditElementHandle(elementRef, dgnModel)
        msElement = eeh.GetElement ()

        if(not needToChangeColor(msElement)):
            continue

        # Categorize elements by z-coordinate
        xCoordinate = msElement.hdr.dhdr.range.xlowlim
        if round(xCoordinate/10000000) not in categorizedElementsByX:
            categorizedElementsByX[round(xCoordinate/10000000)] = []
        categorizedElementsByX[round(xCoordinate/10000000)].append(elementRef)

    return categorizedElementsByX

''' Change the glass panels color '''
def ChangeGlassWallColor(graphicalElements):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    categorizedElements = {}
    for elementRef in graphicalElements:
        eeh = EditElementHandle(elementRef, dgnModel)
        msElement = eeh.GetElement ()

        if(not needToChangeColor(msElement)):
            continue

        # Categorize elements by z-coordinate
        zCoordinate = msElement.hdr.dhdr.range.zlowlim
        if zCoordinate not in categorizedElements:
            categorizedElements[zCoordinate] = []
        categorizedElements[zCoordinate].append(elementRef)


    color = 80
    transparency = 0
    # Change glass panels color for each row
    for zCoordinate in sorted(categorizedElements, reverse=True):
        for elementRef in categorizedElements[zCoordinate]:
            eeh = EditElementHandle(elementRef, dgnModel)
            propertiesSetter = ElementPropertiesSetter()
            propertiesSetter.SetColor(round(color))
            propertiesSetter.SetTransparency(transparency)
            if True == propertiesSetter.Apply(eeh):
                eeh.ReplaceInModel(elementRef)

        if (len(categorizedElements) > 1):
            color += 15/(len(categorizedElements) - 1)
            transparency += 0.8/(len(categorizedElements) - 1)

def ChangeGlassColor():
    categorizedElementsByX = GetElementByXCoordinate()
    for xCoordinate in sorted(categorizedElementsByX, reverse=True):
        ChangeGlassWallColor(categorizedElementsByX[xCoordinate])

if __name__ == "__main__":
    ChangeGlassColor()
    

