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

FILE = os.path.abspath(__file__)

# This callback will be called when the user enters a data point
def OnEnterDataPoint(point, view):
    message = "point: " + str(point)
    message += "\n"
    message += "view: " + str(view)
    print("Callback OnEnterDataPoint:\n" + message)

# This callback will be called when the user enters a Reset
def OnEnterReset(unused):
    print("Callback OnEnterReset.")

# This callback will be called when the user enters a key-in
def OnEnterKeyin(cmdstring, cmdsource, inputTaskId):
    message = "cmdstring: " + cmdstring
    message += "\n"
    message += "cmdsource: " + str(cmdsource)
    message += "\n"
    message += "inputTaskId: " + inputTaskId
    print("Callback OnEnterKeyin:\n" + message)

# This callback will be called when the cursor is moved
def OnCursorMove(point, view, drawMode):
    message = "point: " + str(point)
    message += "\n"
    message += "view: " + str(view)
    message += "\n"
    message += "drawMode: " + str(int(drawMode))
    print("Callback OnCursorMove:\n" + message)

# This callback will be called when a command is terminated
def OnCommandTerminate(unused):
    print("Callback OnCommandTerminate.")

# This callback will be called when undo
def OnOops(numActions):
    message = "numActions: " + str(numActions)
    print("Callback OnOops:\n" + message)

# This callback will be called when redo
def OnRedo(unused):
    print("Callback OnRedo.")


def SetCallbacks():
    StateCallback.SetDataPointFunction(OnEnterDataPoint, FILE + ".OnEnterDataPoint")
    StateCallback.SetResetFunction(OnEnterReset, FILE + ".OnEnterReset")
    StateCallback.SetKeyinFunction(OnEnterKeyin, FILE + ".OnEnterKeyin")
    StateCallback.SetComplexDynamicsFunction(OnCursorMove, FILE + ".OnCursorMove")
    StateCallback.SetCommandCleanupFunction(OnCommandTerminate, FILE + ".OnCommandTerminate")
    StateCallback.SetOopsFunction(OnOops, FILE + ".OnOops")
    StateCallback.SetRedoFunction(OnRedo, FILE + ".OnRedo")

def ClearCallbacks():
    StateCallback.SetDataPointFunction(None, "")
    StateCallback.SetResetFunction(None, "")
    StateCallback.SetKeyinFunction(None, "")
    StateCallback.SetComplexDynamicsFunction(None, "")
    StateCallback.SetCommandCleanupFunction(None, "")
    StateCallback.SetOopsFunction(None, "")
    StateCallback.SetRedoFunction(None, "")


if __name__ == "__main__":
    SetCallbacks()
    #ClearCallbacks()
    