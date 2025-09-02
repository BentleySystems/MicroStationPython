# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how the input callbacks work in python
'''

FILE = os.path.abspath(__file__)

# Callback that is called when command queue elements are dispatched to the appropriate command processor
def CommandFilter(queueElement):
    """
    Filters the command based on the type and processes it accordingly.

    :param queueElement: The element from the queue to be filtered.
    :type queueElement: QueueElement
    
    :return: The result of the command filter operation.
    :rtype: CommandFilterReturnValue
    """
    message = ""
    if(queueElement.hdr.cmdtype == 550):
        message = "queue element cmd taskId: " + str(queueElement.u_cmd.taskId)
        print("Callback CommandFilter:\n" + message)
    return CommandFilterReturnValue.eINPUT_COMMAND_ACCEPT

# Callback that is called when a queue element other than a command queue element is directed to the task
def OnMessageReceived(queueElement):
    """
    Callback function that is triggered when a message is received.

    :param queueElement: The element from the queue containing the message.
    :type queueElement: object
    """
    message = "queue element cmd type: " + str(queueElement.hdr.cmdtype)
    print("Callback OnMessageReceived:\n" + message)

# Callback that is called for each key-in
def OnPreprocessKeyin(keyin):
    """
    Callback function that preprocesses a key input.

    This function is called before a key input is processed. It allows for
    modification of the key input if necessary.

    :param keyin: The key input to be processed.
    :type keyin: KeyinType
    
    :return: The result of the input filter process.
    :rtype: InputFilterReturnValue
    """
    message = "keyin: " + str(keyin)
    # You can change the keyin here
    if keyin.Equals("Test Keyin"):
        keyin.AssignA("Changed Test Keyin")
    print("Callback OnPreprocessKeyin:\n" + message)
    return InputFilterReturnValue.eINPUT_ACCEPT

# Callback that is called for every queue element that the command processors will process
def InputFuncMonitor(queueElement):
    """
    Monitors input function and processes queue elements based on command type.

    :param queueElement: The element from the queue to be processed.
    :type queueElement: QueueElement
    
    :return: The input filter return value indicating acceptance.
    :rtype: InputFilterReturnValue
    """
    message = ""
    if(queueElement.hdr.cmdtype == 550):
        message = "queue element cmd taskId: " + str(queueElement.u_cmd.taskId)
        print("Callback InputFuncMonitor:\n" + message)
    return InputFilterReturnValue.eINPUT_ACCEPT

# Callback that is called for every time input loop enters Idle
def OnEnterIdle(idle):
    """
    Callback function that is triggered when the system enters an idle state.

    :param idle: The idle state information.
    :type idle: Any
    """
    message = "Idle: " + str(idle)
    print("Callback OnEnterIdle:\n" + message)


def SetCallbacks():
    """
    Sets various input callback functions for the system.

    This function registers the following callback functions:
    
    - CommandFilter: Filters commands.
    - OnMessageReceived: Handles received messages.
    - OnPreprocessKeyin: Preprocesses key inputs.
    - InputFuncMonitor: Monitors input functions with a specified filter.
    - OnEnterIdle: Handles the system entering an idle state.

    Each callback function is associated with a specific event and is identified by a unique string.

    """
    InputCallback.SetCommandFilterFunction(CommandFilter, FILE + ".CommandFilter")
    InputCallback.SetMessageReceivedFunction(OnMessageReceived, FILE + ".OnMessageReceived")
    InputCallback.SetPreprocessKeyinFunction(OnPreprocessKeyin, FILE + ".OnPreprocessKeyin")
    InputCallback.SetMonitorFunction(InputFuncMonitor, FILE + ".InputFuncMonitor", InputMonitorFilter.eMONITOR_ALL)
    InputCallback.SetEnterIdleFunction(OnEnterIdle, FILE + ".OnEnterIdle")

def ClearCallbacks():
    """
    Clears all input callback functions by setting them to None.

    This function resets the following input callbacks to their default state:
    
    - Command filter function
    - Message received function
    - Preprocess key-in function
    - Monitor function (with filter set to monitor all)
    - Enter idle function

    It ensures that no custom behavior is executed for these input events.
    """
    InputCallback.SetCommandFilterFunction(None, "")
    InputCallback.SetMessageReceivedFunction(None, "")
    InputCallback.SetPreprocessKeyinFunction(None, "")
    InputCallback.SetMonitorFunction(None, "", InputMonitorFilter.eMONITOR_ALL)
    InputCallback.SetEnterIdleFunction(None, "")


if __name__ == "__main__":
    SetCallbacks()
    #ClearCallbacks()
    