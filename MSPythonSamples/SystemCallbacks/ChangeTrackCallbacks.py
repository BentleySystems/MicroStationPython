# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

file = os.path.abspath(__file__)

def Mark():
    print('Mark')

def UndoRedoFinished(isUndo):
    if isUndo:
        print('Undo Finished')
    else:
        print('Redo Finished')

def UndoRedoFinishedG(isUndo):
    if isUndo:
        print('Undo FinishedG')
    else:
        print('Redo FinishedG')

def XAttributeChanged(xAttr, info, cantBeUndoneFlag):
    print('XAttributeChanged')

def Changed(newDescr, oldDescr, info, cantBeUndoneFlag):
    print('Changed')

def UndoRedoXAttribute(xAttr, action, isUndo, info, source):
    if isUndo:
        print('Undo XAttribute')
    else:
        print('Redo XAttribute')

def UndoRedo(afterUndoRedo, beforeUndoRedo, action, isUndo, info, source):
    if isUndo:
        print('Undo')
    else:
        print('Redo')

def TransientChanged(newDescr, oldDescr, info, cantBeUndoneFlag):
    print('TransientChanged')

def AddFunctions():
    ChangeTrackCallback.AddChangedFunction(Changed, file + '.Changed')
    ChangeTrackCallback.AddUndoRedoFunction(UndoRedo, file + '.UndoRedo')
    ChangeTrackCallback.AddXAttributeChangedFunction(XAttributeChanged, file + '.XAttributeChanged')
    ChangeTrackCallback.AddUndoRedoXAttributeFunction(UndoRedoXAttribute, file + '.UndoRedoXAttribute')
    ChangeTrackCallback.AddUndoRedoFinishedFunction(UndoRedoFinished, file + '.UndoRedoFinished')
    ChangeTrackCallback.AddMarkFunction(Mark, file + '.Mark')
    ChangeTrackCallback.AddTransientChangedFunction(TransientChanged, file + '.TransientChanged')

def RemoveFunctions():
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