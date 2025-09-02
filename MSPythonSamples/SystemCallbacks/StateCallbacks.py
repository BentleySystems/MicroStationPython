# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how state callback works in Python
'''

FILE = os.path.abspath(__file__)

# This callback will be called when the user enters a data point
def OnEnterDataPoint(point, view):
    """
    Callback function that is triggered when entering a data point.

    :param point: The data point that is being entered.
    :type point: Any
    :param view: The view associated with the data point.
    :type view: Any
    """
    message = "point: " + str(point)
    message += "\n"
    message += "view: " + str(view)
    print("Callback OnEnterDataPoint:\n" + message)

# This callback will be called when the user enters a Reset
def OnEnterReset(unused):
    """
    Callback function that is triggered when entering the reset state.

    :param unused: This parameter is not used in the function.
    :type unused: Any
    """
    print("Callback OnEnterReset.")

# This callback will be called when the user enters a key-in
def OnEnterKeyin(cmdstring, cmdsource, inputTaskId):
    """
    Callback function triggered upon entering a key input.

    :param cmdstring: The command string entered by the user.
    :type cmdstring: str
    :param cmdsource: The source of the command.
    :type cmdsource: int
    :param inputTaskId: The ID of the input task.
    :type inputTaskId: str
    :return: None
    :rtype: None
    """
    message = "cmdstring: " + cmdstring
    message += "\n"
    message += "cmdsource: " + str(cmdsource)
    message += "\n"
    message += "inputTaskId: " + inputTaskId
    print("Callback OnEnterKeyin:\n" + message)

# This callback will be called when the cursor is moved
def OnCursorMove(point, view, drawMode):
    """
    Callback function that is triggered when the cursor moves.

    :param point: The current position of the cursor.
    :type point: tuple or list
    :param view: The current view context.
    :type view: object
    :param drawMode: The current drawing mode.
    :type drawMode: int

    :return: None
    """
    message = "point: " + str(point)
    message += "\n"
    message += "view: " + str(view)
    message += "\n"
    message += "drawMode: " + str(int(drawMode))
    print("Callback OnCursorMove:\n" + message)

# This callback will be called when a command is terminated
def OnCommandTerminate(unused):
    """
    Callback function that is triggered when a command terminates.

    :param unused: This parameter is not used in the function.
    :type unused: Any
    """
    print("Callback OnCommandTerminate.")

# This callback will be called when undo
def OnOops(numActions):
    """
    Callback function that handles an "Oops" event.

    This function is called when an "Oops" event occurs and prints the number of actions involved.

    :param numActions: The number of actions that triggered the "Oops" event.
    :type numActions: int
    """
    message = "numActions: " + str(numActions)
    print("Callback OnOops:\n" + message)

# This callback will be called when redo
def OnRedo(unused):
    """
    Callback function that is triggered when a redo action is performed.

    :param unused: This parameter is not used in the function.
    :type unused: Any
    """
    print("Callback OnRedo.")


def SetCallbacks():
    """
    Set various state callback functions for the system.

    This function registers multiple callback functions to handle different
    state events in the system. The callbacks include handling data points,
    resets, key inputs, cursor movements, command terminations, oops events,
    and redo events.

    The following callbacks are set:
    
    - Data Point Function: `OnEnterDataPoint`
    - Reset Function: `OnEnterReset`
    - Keyin Function: `OnEnterKeyin`
    - Complex Dynamics Function: `OnCursorMove`
    - Command Cleanup Function: `OnCommandTerminate`
    - Oops Function: `OnOops`
    - Redo Function: `OnRedo`

    Each callback is associated with a specific event and is registered with
    the corresponding state callback function.

    :return: None
    """
    StateCallback.SetDataPointFunction(OnEnterDataPoint, FILE + ".OnEnterDataPoint")
    StateCallback.SetResetFunction(OnEnterReset, FILE + ".OnEnterReset")
    StateCallback.SetKeyinFunction(OnEnterKeyin, FILE + ".OnEnterKeyin")
    StateCallback.SetComplexDynamicsFunction(OnCursorMove, FILE + ".OnCursorMove")
    StateCallback.SetCommandCleanupFunction(OnCommandTerminate, FILE + ".OnCommandTerminate")
    StateCallback.SetOopsFunction(OnOops, FILE + ".OnOops")
    StateCallback.SetRedoFunction(OnRedo, FILE + ".OnRedo")

def ClearCallbacks():
    """
    Clears all state callback functions by setting them to None.

    This function resets the following state callback functions to their default state:
    - Data point function
    - Reset function
    - Key-in function
    - Complex dynamics function
    - Command cleanup function
    - Oops function
    - Redo function

    Each callback function is set to None and an empty string where applicable.
    """
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
    