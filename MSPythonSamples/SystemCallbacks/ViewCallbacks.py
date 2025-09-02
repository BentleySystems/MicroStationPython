# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import ctypes

'''
Sample demonstrating how view callback works in Python
'''

FILE = os.path.abspath(__file__)

# Callback that is called before a view updates
def OnPreUpdate(isPreUpdate, eraseMode, modelList, regions, context, numCovers, displayDescr):
    """
    Callback function that is called before an update operation.

    :param bool isPreUpdate: Indicates if this is a pre-update operation.
    :param bool eraseMode: Indicates if the erase mode is active.
    :param list modelList: List of models involved in the update.
    :param list regions: List of regions involved in the update. The first region's view number is accessed.
    :param context: Context object that may contain camera information. If not None, checks if the camera is on.
    :type context: object or None
    :param list numCovers: List containing the number of covers. The first element is accessed.
    :param list displayDescr: List containing display descriptions. The first element is accessed.
    
    :return: Always returns 0.
    :rtype: int
    """
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
    """
    Callback function that is called after an update.

    :param bool isPreUpdate: Indicates if the update is a pre-update.
    :param bool eraseMode: Indicates if the erase mode is active.
    :param list modelList: List of models involved in the update.
    :param list regions: List of regions, where each region has a `viewnum` attribute.
    :param context: Context object that may have a `IsCameraOn` method.
    :type context: object or None
    :param list numCovers: List containing the number of covers.
    :param list displayDescr: List containing the display description.

    :return: Always returns 0.
    :rtype: int
    """
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
    """
    Callback function that is triggered when the cursor is moved.

    :param window: The window object where the cursor movement occurred.
    :type window: Window
    :param xCoord: The x-coordinate of the cursor.
    :type xCoord: int
    :param yCoord: The y-coordinate of the cursor.
    :type yCoord: int
    """
    message = "window: " + str(window.GetTitle())
    message += "\n"
    message += "xCoord: " + str(xCoord)
    message += "\n"
    message += "yCoord: " + str(yCoord)
    print("Callback OnCursorMoved:\n" + message)

# Callback that is called when the cursor is stopped in a view
def OnCursorStopped(window, xCoord, yCoord):
    """
    Callback function that is triggered when the cursor stops moving.

    :param window: The window object where the cursor stopped.
    :type window: Window
    :param xCoord: The x-coordinate of the cursor position.
    :type xCoord: int
    :param yCoord: The y-coordinate of the cursor position.
    :type yCoord: int
    """
    message = "window: " + str(window.GetTitle())
    message += "\n"
    message += "xCoord: " + str(xCoord)
    message += "\n"
    message += "yCoord: " + str(yCoord)
    print("Callback OnCursorStopped:\n" + message)

# Set or clear an "element substitution hook" to modify the display of elements in MicroStation views
def OnSubstituteElem(newElem, viewport, purpose, context, elem):
    """
    Callback function to substitute an element with a specified color based on the viewport.
    This function is called to set the color of an element to 4 in view 1 and 8 in view 2.
    It checks various properties of the element to determine if it should be substituted.
    
    :param newElem: The new element to be substituted.
    :type newElem: Element
    :param viewport: The viewport in which the element is being displayed.
    :type viewport: Viewport
    :param purpose: The purpose of the substitution.
    :type purpose: Purpose
    :param context: The context in which the substitution is occurring.
    :type context: Context
    :param elem: The element to be substituted.
    :type elem: Element
    
    :return: The status of the substitution.
    :rtype: SubstituteElemStatus
    """
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
    """
    Set various callback functions for view updates and cursor movements.

    This function registers the following callbacks:
    
    - Pre-update function
    - Post-update function
    - Cursor moved function
    - Cursor stopped function
    - Substitute element function

    The callbacks are set using the `ViewCallback` module and are associated with specific functions defined elsewhere in the code.

    :return: None
    """
    ViewCallback.SetUpdatePreFunction(OnPreUpdate, FILE + ".OnPreUpdate")
    ViewCallback.SetUpdatePostFunction(OnPostUpdate, FILE + ".OnPostUpdate")
    ViewCallback.SetMotionFunction(OnCursorMoved, FILE + ".OnCursorMoved")
    ViewCallback.SetNoMotionFunction(OnCursorStopped, FILE + ".OnCursorStopped")
    ViewCallback.SetSubstituteElemFunction(OnSubstituteElem, FILE + ".OnSubstituteElem")

def ClearCallbacks():
    """
    Clears all the view callbacks by setting them to None.

    This function resets the following callbacks to None:
    - Update pre-function
    - Update post-function
    - Motion function
    - No motion function
    - Substitute element function

    It uses the `ViewCallback` class to set each callback to None.
    """
    ViewCallback.SetUpdatePreFunction(None, "")
    ViewCallback.SetUpdatePostFunction(None, "")
    ViewCallback.SetMotionFunction(None, "")
    ViewCallback.SetNoMotionFunction(None, "")
    ViewCallback.SetSubstituteElemFunction(None, "")


if __name__ == "__main__":
    SetCallbacks()
    #ClearCallbacks()
    