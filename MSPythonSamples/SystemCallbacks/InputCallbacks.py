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

# Callback that is called when command queue elements are dispatched to the appropriate command processor
def CommandFilter(queueElement):
    message = ""
    if(queueElement.hdr.cmdtype == 550):
        message = "queue element cmd taskId: " + str(queueElement.u_cmd.taskId)
        print("Callback CommandFilter:\n" + message)
    return CommandFilterReturnValue.eINPUT_COMMAND_ACCEPT

# Callback that is called when a queue element other than a command queue element is directed to the task
def OnMessageReceived(queueElement):
    message = "queue element cmd type: " + str(queueElement.hdr.cmdtype)
    print("Callback OnMessageReceived:\n" + message)

# Callback that is called for each key-in
def OnPreprocessKeyin(keyin):
    message = "keyin: " + str(keyin)
    # You can change the keyin here
    if keyin.Equals("Test Keyin"):
        keyin.AssignA("Changed Test Keyin")
    print("Callback OnPreprocessKeyin:\n" + message)
    return InputFilterReturnValue.eINPUT_ACCEPT

# Callback that is called for every queue element that the command processors will process
def InputFuncMonitor(queueElement):
    message = ""
    if(queueElement.hdr.cmdtype == 550):
        message = "queue element cmd taskId: " + str(queueElement.u_cmd.taskId)
        print("Callback InputFuncMonitor:\n" + message)
    return InputFilterReturnValue.eINPUT_ACCEPT

# Callback that is called for every time input loop enters Idle
def OnEnterIdle(idle):
    message = "Idle: " + str(idle)
    print("Callback OnEnterIdle:\n" + message)


def SetCallbacks():
    InputCallback.SetCommandFilterFunction(CommandFilter, FILE + ".CommandFilter")
    InputCallback.SetMessageReceivedFunction(OnMessageReceived, FILE + ".OnMessageReceived")
    InputCallback.SetPreprocessKeyinFunction(OnPreprocessKeyin, FILE + ".OnPreprocessKeyin")
    InputCallback.SetMonitorFunction(InputFuncMonitor, FILE + ".InputFuncMonitor", InputMonitorFilter.eMONITOR_ALL)
    InputCallback.SetEnterIdleFunction(OnEnterIdle, FILE + ".OnEnterIdle")

def ClearCallbacks():
    InputCallback.SetCommandFilterFunction(None, "")
    InputCallback.SetMessageReceivedFunction(None, "")
    InputCallback.SetPreprocessKeyinFunction(None, "")
    InputCallback.SetMonitorFunction(None, "", InputMonitorFilter.eMONITOR_ALL)
    InputCallback.SetEnterIdleFunction(None, "")


if __name__ == "__main__":
    SetCallbacks()
    #ClearCallbacks()
    