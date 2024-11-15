# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

isMark = False
isChanged = False
isUndoRedo = False
isUndoRedoFinished = False
isTransientChanged = False
isXAttributeChanged = False
isUndoRedoXAttribute = False
ModelName = 'Default'
file = os.path.abspath(__file__)

# function to get folder location
def getRoot(fileLocation):
    origin = os.getenv('SrcRoot')
    if not origin:
        return origin
    origin += fileLocation
    return origin

def GetDgnAttachmentByAttachedModelName():
    attachments = ISessionMgr.ActiveDgnModelRef.GetDgnAttachments()
    if None == attachments:
        return None

    for attachment in attachments:
        if ModelName == attachment.GetAttachModelName():
            return attachment

    return None

def ChangeSnapLock():
    requiredRef = GetDgnAttachmentByAttachedModelName()
    if None == requiredRef:
        return False

    requiredRef.SetSnapLock(not requiredRef.SnapLocked)
    if BentleyStatus.eSUCCESS != requiredRef.WriteToModel():
        return False

    return True

def Mark():
    global isMark
    isMark = True
    print('Mark')

def UndoRedoFinished(isUndo):
    global isUndoRedoFinished
    isUndoRedoFinished = True
    if isUndo:
        print('Undo Finished')
    else:
        print('Redo Finished')

def XAttributeChanged(xAttr, info, cantBeUndoneFlag):
    global isXAttributeChanged
    isXAttributeChanged = True
    print('XAttributeChanged')

def Changed(newDescr, oldDescr, info, cantBeUndoneFlag):
    global isChanged
    isChanged = True
    print('Changed')

def UndoRedoXAttribute(xAttr, action, isUndo, info, source):
    global isUndoRedoXAttribute
    isUndoRedoXAttribute = True
    if isUndo:
        print('Undo XAttribute')
    else:
        print('Redo XAttribute')

def UndoRedo(afterUndoRedo, beforeUndoRedo, action, isUndo, info, source):
    global isUndoRedo
    isUndoRedo = True
    if isUndo:
        print('Undo')
    else:
        print('Redo')

def TransientChanged(newDescr, oldDescr, info, cantBeUndoneFlag):
    global isTransientChanged
    isTransientChanged = True
    print('TransientChanged')

def test_TransientChanged_Mark():
    global isTransientChanged, isMark
    isTransientChanged = False
    isMark = False

    ChangeTrackCallback.AddTransientChangedFunction(TransientChanged, file + '.TransientChanged')
    ChangeTrackCallback.AddMarkFunction(Mark, file + '.Mark')

    PyCadInputQueue.SendKeyin('PLACE SMARTLINE')
    point = DPoint3d(30.0, 0.0, 0.0)
    PyCadInputQueue.SendDataPoint(point, 1)
    point.y += 30.0
    PyCadInputQueue.SendDataPoint(point, 1)
    PyCommandState.StartDefaultCommand()

    ChangeTrackCallback.RemoveTransientChangedFunction(TransientChanged, file + '.TransientChanged')
    ChangeTrackCallback.RemoveMarkFunction(Mark, file + '.Mark')

    assert isTransientChanged
    assert isMark

def test_XAttributeChanged_UndoRedo():
    global isChanged, isUndoRedo, isUndoRedoFinished, isXAttributeChanged, isUndoRedoXAttribute
    isChanged = False
    isUndoRedo = False
    isUndoRedoFinished = False
    isXAttributeChanged = False
    isUndoRedoXAttribute = False

    fileLocation = 'MSPython\\MSPythonTests\\PlatformTests\\data\\'
    dataDir = getRoot(fileLocation)
    doc = DgnDocument.CreateFromFileName ('ChangeTrack.dgn', dataDir, -101, DgnDocument.FetchMode.eWrite)[0]
    ISessionMgr.GetManager().SwitchToNewFile(doc, '', GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)

    ChangeTrackCallback.AddChangedFunction(Changed, file + '.Changed')
    ChangeTrackCallback.AddUndoRedoFunction(UndoRedo, file + '.UndoRedo')
    ChangeTrackCallback.AddXAttributeChangedFunction(XAttributeChanged, file + '.XAttributeChanged')
    ChangeTrackCallback.AddUndoRedoXAttributeFunction(UndoRedoXAttribute, file + '.UndoRedoXAttribute')
    ChangeTrackCallback.AddUndoRedoFinishedFunction(UndoRedoFinished, file + '.UndoRedoFinished')

    ChangeSnapLock()
    PyCadInputQueue.SendKeyin('UNDO')
    PyCadInputQueue.SendKeyin('REDO')
    
    ChangeTrackCallback.RemoveChangedFunction(Changed, file + '.Changed')
    ChangeTrackCallback.RemoveUndoRedoFunction(UndoRedo, file + '.UndoRedo')
    ChangeTrackCallback.RemoveXAttributeChangedFunction(XAttributeChanged, file + '.XAttributeChanged')
    ChangeTrackCallback.RemoveUndoRedoXAttributeFunction(UndoRedoXAttribute, file + '.UndoRedoXAttribute')
    ChangeTrackCallback.RemoveUndoRedoFinishedFunction(UndoRedoFinished, file + '.UndoRedoFinished')

    assert isChanged
    assert isUndoRedo
    assert isUndoRedoFinished
    assert isXAttributeChanged
    assert isUndoRedoXAttribute

#if __name__ == '__main__':
#    test_TransientChanged_Mark()
#    test_XAttributeChanged_UndoRedo()