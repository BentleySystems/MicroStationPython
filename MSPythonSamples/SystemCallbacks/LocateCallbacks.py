# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
from tkinter import messagebox
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

FILE = os.path.abspath(__file__)

# Move mouse over an element to call this callback
def OnPreLocate(action, element, modelRef, filePosition, point, viewNumber, hitPath, rejectReason):
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
    eh = ElementHandle(path.GetCursorElem())
    if not eh.IsValid:
        return
    
    el = eh.GetElement()
    if el.ehdr.isGraphics:
        message = "[elementId]: " + str(eh.ElementId)
        print("Callback OnDoubleClick:\n" + message)

    return True


def SetCallbacks():
    LocateCallback.SetPreLocateFunction(OnPreLocate, FILE + ".OnPreLocate")
    LocateCallback.SetPostLocateFunction(OnPostLocate, FILE + ".OnPostLocate")
    LocateCallback.SetOverridePathDescriptionFunction(OnOverridePathDescription, FILE + ".OnOverridePathDescription")
    LocateCallback.SetGlobalPreLocateFunction(OnGlobalPreLocate, FILE + ".OnGlobalPreLocate")
    LocateCallback.SetGlobalPostLocateFunction(OnGlobalPostLocate, FILE + ".OnGlobalPostLocate")
    LocateCallback.SetSelectCmdFunction(OnSelectCmd, FILE + ".OnSelectCmd")
    LocateCallback.SetElementDoubleClickFunction(OnDoubleClick, FILE + ".OnDoubleClick")


if __name__ == "__main__":
    SetCallbacks()
    