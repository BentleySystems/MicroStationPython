# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

'''
Running this sample needs to open GlassColor.dgn.
This sample shows how to change the glass panels with random color and transparency.
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

''' Change the glass panels color '''
def ChangeGlassColor():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()
    for elementRef in graphicalElements:
        eeh = EditElementHandle(elementRef, dgnModel)
        msElement = eeh.GetElement ()

        if(not needToChangeColor(msElement)):
            continue

        propertiesSetter = ElementPropertiesSetter()
        propertiesSetter.SetColor(random.randint(1, 255))
        propertiesSetter.SetTransparency(random.random())
        if True == propertiesSetter.Apply(eeh):
            eeh.ReplaceInModel(elementRef)


if __name__ == "__main__":
    ChangeGlassColor()
    

