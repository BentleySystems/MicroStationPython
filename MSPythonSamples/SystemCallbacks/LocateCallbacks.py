# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $


import os
from tkinter import messagebox
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''Sample demonstrating how the locate callbacks work in python'''

FILE = os.path.abspath(__file__)

# Move mouse over an element to call this callback
def OnPreLocate(action, element, modelRef, filePosition, point, viewNumber, hitPath, rejectReason):
    """
    Callback function that is called before locating an element.

    :param action: The action being performed.
    :type action: int
    :param element: The element being located.
    :type element: Element
    :param modelRef: The model reference.
    :type modelRef: ModelReference
    :param filePosition: The file position.
    :type filePosition: int
    :param point: The point in the model.
    :type point: Point3d
    :param viewNumber: The view number.
    :type viewNumber: int
    :param hitPath: The hit path.
    :type hitPath: HitPath
    :param rejectReason: The reason for rejection.
    :type rejectReason: int
    
    :return: The status of the locate filter.
    :rtype: LocateFilterStatus
    """
    message = "action: " + str(action)
    message += "\n"
    message += "element: " + str(element.hdr.ehdr.uniqueId)
    message += "\n"
    message += "modelRef: " + str(modelRef.GetDgnModel().GetModelName())
    message += "\n"
    message += "filePosition: " + str(filePosition)
    message += "\n"
    message += "point: " + str(point)
    message += "\n"
    message += "viewNumber: " + str(viewNumber)
    message += "\n"
    message += "hitPath: " + str(hitPath)
    message += "\n"
    message += "rejectReason: " + str(rejectReason)
    print("Callback OnPreLocate:\n" + message)
    return LocateFilterStatus.eLOCATE_FILTER_STATUS_Neutral

# Move mouse over an element to call this callback
def OnPostLocate(action, element, modelRef, filePosition, point, viewNumber, hitPath, rejectReason):
    """
    Callback function that is triggered after a locate operation.

    :param action: The action performed during the locate operation.
    :type action: int
    :param element: The element that was located.
    :type element: Element
    :param modelRef: The model reference where the element is located.
    :type modelRef: ModelReference
    :param filePosition: The file position of the located element.
    :type filePosition: int
    :param point: The point where the element was located.
    :type point: Point3d
    :param viewNumber: The view number in which the element was located.
    :type viewNumber: int
    :param hitPath: The hit path of the located element.
    :type hitPath: HitPath
    :param rejectReason: The reason for rejecting the locate operation, if any.
    :type rejectReason: int
    
    :return: The status of the locate filter.
    :rtype: LocateFilterStatus
    """
    message = "action: " + str(action)
    message += "\n"
    message += "element: " + str(element.hdr.ehdr.uniqueId)
    message += "\n"
    message += "modelRef: " + str(modelRef.GetDgnModel().GetModelName())
    message += "\n"
    message += "filePosition: " + str(filePosition)
    message += "\n"
    message += "point: " + str(point)
    message += "\n"
    message += "viewNumber: " + str(viewNumber)
    message += "\n"
    message += "hitPath: " + str(hitPath)
    message += "\n"
    message += "rejectReason: " + str(rejectReason)
    print("Callback OnPostLocate:\n" + message)
    return LocateFilterStatus.eLOCATE_FILTER_STATUS_Neutral

# Move mouse over an element to call this callback
def OnGlobalPreLocate(action, element, modelRef, filePosition, point, viewNumber, hitPath, rejectReason):
    """
    Callback function that is triggered before a locate operation.

    :param action: The action being performed.
    :type action: int
    :param element: The element being located.
    :type element: Element
    :param modelRef: The model reference.
    :type modelRef: ModelReference
    :param filePosition: The file position.
    :type filePosition: int
    :param point: The point in the model.
    :type point: Point3d
    :param viewNumber: The view number.
    :type viewNumber: int
    :param hitPath: The hit path.
    :type hitPath: HitPath
    :param rejectReason: The reason for rejection.
    :type rejectReason: int
    
    :return: The status of the locate filter.
    :rtype: LocateFilterStatus
    """
    message = "action: " + str(action)
    message += "\n"
    message += "element: " + str(element.hdr.ehdr.uniqueId)
    message += "\n"
    message += "modelRef: " + str(modelRef.GetDgnModel().GetModelName())
    message += "\n"
    message += "filePosition: " + str(filePosition)
    message += "\n"
    message += "point: " + str(point)
    message += "\n"
    message += "viewNumber: " + str(viewNumber)
    message += "\n"
    message += "hitPath: " + str(hitPath)
    message += "\n"
    message += "rejectReason: " + str(rejectReason)
    print("Callback OnGlobalPreLocate:\n" + message)
    return LocateFilterStatus.eLOCATE_FILTER_STATUS_Neutral

# Move mouse over an element to call this callback
def OnGlobalPostLocate(action, element, modelRef, filePosition, point, viewNumber, hitPath, rejectReason):
    """
    Callback function that is triggered after a global locate operation.

    :param action: The action performed during the locate operation.
    :type action: int
    :param element: The element that was located.
    :type element: Element
    :param modelRef: The model reference of the located element.
    :type modelRef: ModelReference
    :param filePosition: The file position of the located element.
    :type filePosition: int
    :param point: The point where the element was located.
    :type point: Point3d
    :param viewNumber: The view number in which the element was located.
    :type viewNumber: int
    :param hitPath: The hit path of the located element.
    :type hitPath: HitPath
    :param rejectReason: The reason for rejecting the locate operation, if any.
    :type rejectReason: int
    
    :return: The status of the locate filter operation.
    :rtype: LocateFilterStatus
    """
    message = "action: " + str(action)
    message += "\n"
    message += "element: " + str(element.hdr.ehdr.uniqueId)
    message += "\n"
    message += "modelRef: " + str(modelRef.GetDgnModel().GetModelName())
    message += "\n"
    message += "filePosition: " + str(filePosition)
    message += "\n"
    message += "point: " + str(point)
    message += "\n"
    message += "viewNumber: " + str(viewNumber)
    message += "\n"
    message += "hitPath: " + str(hitPath)
    message += "\n"
    message += "rejectReason: " + str(rejectReason)
    print("Callback OnGlobalPostLocate:\n" + message)
    return LocateFilterStatus.eLOCATE_FILTER_STATUS_Neutral

# Hover over an element to call this callback to modify the element description
def OnOverridePathDescription(path, description):
    """
    Callback function to override the description of a given path.
    This function is triggered to modify the description of an element
    identified by the given path. If the element is a graphical element,
    it updates the description with new values and prints the changes.
    
    :param path: The path object containing the cursor element.
    :type path: PathType
    :param description: The description object to be modified.
    :type description: DescriptionType
    """
    eh = ElementHandle(path.GetCursorElem())
    if not eh.IsValid:
        return
    
    el = eh.GetElement()
    if el.ehdr.isGraphics:
        message = "[elementId]: " + str(eh.ElementId)
        message += "\n"
        message += "[description]:\n" + str(description)
        description.AssignA("New description1")
        description.AppendA("\nNew description2")
        message += "\n"
        message += "[new description]:\n" + str(description)
        print("Callback OnOverridePathDescription:\n" + message)

# Click on an element to call this callback
def OnSelectCmd(action, filePos, modelRef):
    """
    Callback function that handles selection commands.
    
    :param action: The action performed during selection. Expected to be of type `SelectionSetAction`.
    :type action: SelectionSetAction
    :param filePos: The file position where the action occurred.
    :type filePos: int
    :param modelRef: A reference to the model where the action occurred.
    :type modelRef: ModelReference
    
    :return: Status of the callback execution.
    :rtype: BentleyStatus
    """
    if SelectionSetAction.eSELECT_DRAG_NEW == action:
        message = "[action]: " + str(action)
        message += "\n"
        message += "[filePos]: " + str(filePos)
        message += "\n"
        message += "[modelRef]: " + str(modelRef.GetDgnModel().GetModelName())
        print("Callback OnSelectCmd:\n" + message)

    return BentleyStatus.eSUCCESS

# Double click on an element to call this callback
def OnDoubleClick(path):
    """
    Callback function that is triggered on a double-click event.
    
    :param path: The path object that contains the cursor element.
    :type path: Path
    
    :return: True if the element is valid and a graphics element, otherwise None.
    :rtype: bool or None
    """
    eh = ElementHandle(path.GetCursorElem())
    if not eh.IsValid:
        return
    
    el = eh.GetElement()
    if el.ehdr.isGraphics:
        message = "[elementId]: " + str(eh.ElementId)
        print("Callback OnDoubleClick:\n" + message)

    return True


def SetCallbacks():
    """
    Set various callback functions for the LocateCallback system.

    This function assigns specific callback functions to handle different
    events in the LocateCallback system. The callbacks include pre-locate,
    post-locate, override path description, global pre-locate, global
    post-locate, select command, and element double-click events.

    The following callbacks are set:
    - Pre-locate: `OnPreLocate`
    - Post-locate: `OnPostLocate`
    - Override path description: `OnOverridePathDescription`
    - Global pre-locate: `OnGlobalPreLocate`
    - Global post-locate: `OnGlobalPostLocate`
    - Select command: `OnSelectCmd`
    - Element double-click: `OnDoubleClick`

    Each callback is associated with a specific function and a string
    identifier that includes the file name and the function name.

    :return: None
    """
    LocateCallback.SetPreLocateFunction(OnPreLocate, FILE + ".OnPreLocate")
    LocateCallback.SetPostLocateFunction(OnPostLocate, FILE + ".OnPostLocate")
    LocateCallback.SetOverridePathDescriptionFunction(OnOverridePathDescription, FILE + ".OnOverridePathDescription")
    LocateCallback.SetGlobalPreLocateFunction(OnGlobalPreLocate, FILE + ".OnGlobalPreLocate")
    LocateCallback.SetGlobalPostLocateFunction(OnGlobalPostLocate, FILE + ".OnGlobalPostLocate")
    LocateCallback.SetSelectCmdFunction(OnSelectCmd, FILE + ".OnSelectCmd")
    LocateCallback.SetElementDoubleClickFunction(OnDoubleClick, FILE + ".OnDoubleClick")


if __name__ == "__main__":
    SetCallbacks()
    