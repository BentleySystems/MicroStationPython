# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import ctypes

FILE = os.path.abspath(__file__)

# Callback that is called before a view updates
def OnPreUpdate(isPreUpdate, eraseMode, modelList, regions, context, numCovers, displayDescr):
    message = "isPreUpdate: " + str(isPreUpdate)
    message += "\n"
    message += "eraseMode: " + str(eraseMode)
    message += "\n"
    message += "modelList: " + str(modelList)
    message += "\n"
    message += "regions view number: " + str(regions[0].viewnum)
    message += "\n"
    if context is not None:
        message += "context is camera on: " + str(context.IsCameraOn())
    else:
        message += "context" + str(context)
    message += "\n"
    message += "numCovers: " + str(numCovers[0])
    message += "\n"
    message += "displayDescr: " + str(displayDescr[0])
    print("Callback OnPreUpdate:\n" + message)
    return 0

# Callback that is called before a view updates
def OnPostUpdate(isPreUpdate, eraseMode, modelList, regions, context, numCovers, displayDescr):
    message = "isPreUpdate: " + str(isPreUpdate)
    message += "\n"
    message += "eraseMode: " + str(eraseMode)
    message += "\n"
    message += "modelList: " + str(modelList)
    message += "\n"
    message += "regions view number: " + str(regions[0].viewnum)
    message += "\n"
    if context is not None:
        message += "context is camera on: " + str(context.IsCameraOn())
    else:
        message += "context" + str(context)
    message += "\n"
    message += "numCovers: " + str(numCovers[0])
    message += "\n"
    message += "displayDescr: " + str(displayDescr[0])
    print("Callback OnPostUpdate:\n" + message)
    return 0

# Callback that is called when the cursor moved in a view
def OnCursorMoved(window, xCoord, yCoord):
    message = "window: " + str(window.GetTitle())
    message += "\n"
    message += "xCoord: " + str(xCoord)
    message += "\n"
    message += "yCoord: " + str(yCoord)
    print("Callback OnCursorMoved:\n" + message)

# Callback that is called when the cursor is stopped in a view
def OnCursorStopped(window, xCoord, yCoord):
    message = "window: " + str(window.GetTitle())
    message += "\n"
    message += "xCoord: " + str(xCoord)
    message += "\n"
    message += "yCoord: " + str(yCoord)
    print("Callback OnCursorStopped:\n" + message)

# Set or clear an "element substitution hook" to modify the display of elements in MicroStation views
def OnSubstituteElem(newElem, viewport, purpose, context, elem):
    message = "viewport: " + str(viewport)
    message += "\n"
    message += "purpose: " + str(purpose)
    message += "\n"
    message += "context: " + str(context)
    message += "\n"
    message += "elem: " + str(elem)
    print("Callback OnSubstituteElem to set color to 4 in view 1 and 8 in view 2 to display:\n" + message)

    if (elem.Element is None or (not elem.Element.ehdr.isGraphics) or elem.Element.hdr.dhdr.props.b.invisible
        or elem.Element.ehdr.deleted or elem.Element.hdr.dhdr.props.b.elementClass != 0):
        return SubstituteElemStatus.eSUBSTELEM_STATUS_Normal

    color = 0
    if (viewport.GetViewNumber() == 0):
        color = 4
    elif (viewport.GetViewNumber() == 1):
        color = 8

    ret = elem.GetElementDescr().DuplicateSingle()
    if(ret[0] == BentleyStatus.eSUCCESS and color != 0):
        propertiesSetter = ElementPropertiesSetter()
        propertiesSetter.SetColor(color)
        eeh = EditElementHandle(ret[1], True, False)
        propertiesSetter.Apply(eeh)
        newElem.value = eeh.ExtractElementDescr()
    
    return SubstituteElemStatus.eSUBSTELEM_STATUS_Normal


def SetCallbacks():
    ViewCallback.SetUpdatePreFunction(OnPreUpdate, FILE + ".OnPreUpdate")
    ViewCallback.SetUpdatePostFunction(OnPostUpdate, FILE + ".OnPostUpdate")
    ViewCallback.SetMotionFunction(OnCursorMoved, FILE + ".OnCursorMoved")
    ViewCallback.SetNoMotionFunction(OnCursorStopped, FILE + ".OnCursorStopped")
    ViewCallback.SetSubstituteElemFunction(OnSubstituteElem, FILE + ".OnSubstituteElem")

def ClearCallbacks():
    ViewCallback.SetUpdatePreFunction(None, "")
    ViewCallback.SetUpdatePostFunction(None, "")
    ViewCallback.SetMotionFunction(None, "")
    ViewCallback.SetNoMotionFunction(None, "")
    ViewCallback.SetSubstituteElemFunction(None, "")


if __name__ == "__main__":
    SetCallbacks()
    #ClearCallbacks()
    