# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to use the ChangeTracking callback API
'''

file = os.path.abspath(__file__)

def Mark():
    print('Mark')

def UndoRedoFinished(isUndo):
    """
    Callback function that gets called when an undo or redo operation is finished.

    :param isUndo: A boolean indicating whether the operation was an undo (True) or a redo (False).
    :type isUndo: bool
    """
    if isUndo:
        print('Undo Finished')
    else:
        print('Redo Finished')

def UndoRedoFinishedG(isUndo):
    """
    Callback function that is triggered when an undo or redo operation is finished.

    :param isUndo: A boolean indicating whether the operation was an undo (True) or a redo (False).
    :type isUndo: bool
    """
    if isUndo:
        print('Undo FinishedG')
    else:
        print('Redo FinishedG')

def XAttributeChanged(xAttr, info, cantBeUndoneFlag):
    """
    Callback function that is triggered when an X attribute changes.

    :param xAttr: The attribute that has changed.
    :type xAttr: Any
    :param info: Additional information about the change.
    :type info: Any
    :param cantBeUndoneFlag: Flag indicating whether the change can be undone.
    :type cantBeUndoneFlag: bool
    """
    print('XAttributeChanged')

def Changed(newDescr, oldDescr, info, cantBeUndoneFlag):
    """
    Callback function that is triggered when a change occurs.

    :param newDescr: The new description after the change.
    :type newDescr: str
    :param oldDescr: The old description before the change.
    :type oldDescr: str
    :param info: Additional information about the change.
    :type info: dict
    :param cantBeUndoneFlag: Flag indicating if the change cannot be undone.
    :type cantBeUndoneFlag: bool
    """
    print('Changed')

def UndoRedoXAttribute(xAttr, action, isUndo, info, source):
    """
    Handles the undo and redo actions for the XAttribute.

    :param xAttr: The XAttribute to be modified.
    :type xAttr: Any
    :param action: The action to be performed.
    :type action: Any
    :param isUndo: Flag indicating whether the action is an undo (True) or redo (False).
    :type isUndo: bool
    :param info: Additional information related to the action.
    :type info: Any
    :param source: The source of the action.
    :type source: Any
    """
    if isUndo:
        print('Undo XAttribute')
    else:
        print('Redo XAttribute')

def UndoRedo(afterUndoRedo, beforeUndoRedo, action, isUndo, info, source):
    """
    Callback function to handle undo and redo actions.

    :param afterUndoRedo: State of the system after the undo/redo action.
    :type afterUndoRedo: Any
    :param beforeUndoRedo: State of the system before the undo/redo action.
    :type beforeUndoRedo: Any
    :param action: The action that was performed.
    :type action: Any
    :param isUndo: Flag indicating if the action is an undo (True) or redo (False).
    :type isUndo: bool
    :param info: Additional information about the action.
    :type info: Any
    :param source: The source of the action.
    :type source: Any
    """
    if isUndo:
        print('Undo')
    else:
        print('Redo')

def TransientChanged(newDescr, oldDescr, info, cantBeUndoneFlag):
    """
    Callback function that is triggered when a transient change occurs.

    :param newDescr: Description of the new state after the change.
    :type newDescr: str
    :param oldDescr: Description of the old state before the change.
    :type oldDescr: str
    :param info: Additional information about the change.
    :type info: str
    :param cantBeUndoneFlag: Flag indicating whether the change can be undone.
    :type cantBeUndoneFlag: bool
    """
    print('TransientChanged')

def AddFunctions():
    """
    Registers various callback functions for change tracking.

    This function adds several callback functions to the `ChangeTrackCallback` object. Each callback function is associated with a specific event or action, such as changes, undo/redo operations, attribute changes, and marking.

    The following callback functions are registered:
    
    - `Changed`: Called when a change occurs.
    - `UndoRedo`: Called during undo/redo operations.
    - `XAttributeChanged`: Called when an X attribute changes.
    - `UndoRedoXAttribute`: Called during undo/redo operations for X attributes.
    - `UndoRedoFinished`: Called when undo/redo operations are finished.
    - `Mark`: Called to mark a specific state or point.
    - `TransientChanged`: Called when a transient change occurs.

    Each callback function is registered with a corresponding identifier that includes the file name and the specific event/action.

    :return: None
    """
    ChangeTrackCallback.AddChangedFunction(Changed, file + '.Changed')
    ChangeTrackCallback.AddUndoRedoFunction(UndoRedo, file + '.UndoRedo')
    ChangeTrackCallback.AddXAttributeChangedFunction(XAttributeChanged, file + '.XAttributeChanged')
    ChangeTrackCallback.AddUndoRedoXAttributeFunction(UndoRedoXAttribute, file + '.UndoRedoXAttribute')
    ChangeTrackCallback.AddUndoRedoFinishedFunction(UndoRedoFinished, file + '.UndoRedoFinished')
    ChangeTrackCallback.AddMarkFunction(Mark, file + '.Mark')
    ChangeTrackCallback.AddTransientChangedFunction(TransientChanged, file + '.TransientChanged')

def RemoveFunctions():
    """
    Removes various change tracking callback functions.

    This function removes the following callback functions:
    
    - Changed function
    - Undo/Redo function
    - XAttribute changed function
    - Undo/Redo XAttribute function
    - Undo/Redo finished function
    - Mark function
    - Transient changed function

    Each callback function is removed using the corresponding 
    `ChangeTrackCallback.Remove*Function` method.
    """
    ChangeTrackCallback.RemoveChangedFunction(Changed, file + '.Changed')
    ChangeTrackCallback.RemoveUndoRedoFunction(UndoRedo, file + '.UndoRedo')
    ChangeTrackCallback.RemoveXAttributeChangedFunction(XAttributeChanged, file + '.XAttributeChanged')
    ChangeTrackCallback.RemoveUndoRedoXAttributeFunction(UndoRedoXAttribute, file + '.UndoRedoXAttribute')
    ChangeTrackCallback.RemoveUndoRedoFinishedFunction(UndoRedoFinished, file + '.UndoRedoFinished')
    ChangeTrackCallback.RemoveMarkFunction(Mark, file + '.Mark')
    ChangeTrackCallback.RemoveTransientChangedFunction(TransientChanged, file + '.TransientChanged')

if __name__ == '__main__':
    keyinXml = os.path.dirname(__file__) + '/ChangeTrackCallbacks.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))