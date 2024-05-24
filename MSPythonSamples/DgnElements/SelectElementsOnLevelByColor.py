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
Function to iterate levels available on model
    lvlName : str      Level Name
    lvlId   : int      Level number
'''
def getLevelName(lvlName, lvlId):
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    levelCache = ACTIVEMODEL.GetDgnFile().GetLevelCache()

    it = iter(levelCache)
    for level in it:
        levelName = level.GetName()
        levelId   = level.GetLevelId()
        if lvlName == levelName and lvlId == levelId:
            return True

    return False

'''
Function to select elements by its level and color
    lvlName   : str      Level name
    userColor : dict     RGB value
'''
def selectElementsbyLevelAndColor(lvlName, userColor):
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
            #Level details
            levelId = msElement.ehdr.level
            bMatch = getLevelName(lvlName, levelId)

            propQuery    = ElementPropertiesGetter(eh)
            color        = propQuery.GetColor()
            eleinfoColor = DgnColorMap.ExtractElementColorInfo(color , dgnfile)
            rgbdef       = RgbColorDef
            rgbdef       = eleinfoColor[1].m_rgb #RGB in IntColorDef
            red   = rgbdef.red
            green = rgbdef.green
            blue  = rgbdef.blue 
            print("red,green,blue-->",red, green, blue)

            if (bMatch and 
                (red   == userColor.get('r') and 
                green == userColor.get('g') and
                blue  == userColor.get('b'))):
                 selSetManager.AddElement(perElementRef,dgnModel) 

'''
Prerequisite: Open MSPythonSamples\\data\\SelectExample.dgn with 'Color' model 
'''
#main
if __name__ == "__main__":
    #highlight all the elements available on level "Default"
    userColor = {'r':255, 'g':128, 'b':66}
    lvlName = 'Default' 
    selectElementsbyLevelAndColor(lvlName, userColor)