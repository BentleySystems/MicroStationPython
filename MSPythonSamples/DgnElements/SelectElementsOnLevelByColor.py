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
This sample demonstrates how to selects elements based on their level and color
'''

def getLevelName(lvlName, lvlId):
    """
    Check if a level with the specified name and ID exists in the active model.

    :param str lvlName: The name of the level to check.
    :param int lvlId: The ID of the level to check.
    :return: True if a level with the specified name and ID exists, False otherwise.
    :rtype: bool
    """
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


def selectElementsbyLevelAndColor(lvlName, userColor):
    """
    Select elements in the active model based on their level and color.

    :param lvlName: The name of the level to filter elements by.
    :type lvlName: str
    :param userColor: A dictionary containing the RGB values to filter elements by.
                      The dictionary should have keys 'r', 'g', and 'b' for red, green, and blue respectively.
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
    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {agenda.GetCount()} elements")
    # iterate over the selection set printing the element ids of elements in the selection set
    for i in range(agenda.GetCount()):
        editElementHandle = agenda.GetEntry(i)
        print (f"  Element ID: {editElementHandle.GetElementId()}")
    
#Prerequisite: Open MSPythonSamples\\data\\SelectExample.dgn with 'Color' model 
#main
if __name__ == "__main__":
    #highlight all the elements available on level "Default"
    userColor = {'r':255, 'g':128, 'b':66}
    lvlName = 'Default' 
    selectElementsbyLevelAndColor(lvlName, userColor)