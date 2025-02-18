#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import debugpy
from tkinter import messagebox

FILE = os.path.abspath(__file__)

g_modelChangeCallbackFired = False
g_callbackDgnModelRef = None
g_modelChangeType = None

g_fileSaveAsCallbackFired = False
g_fileSaveAsName = ""
g_postFileSaveAs = False

g_levelChangeCallbackFired = False
g_levelPreChangeCallbackFired = False
g_callbackLevelId = -100
g_levelChangeType = None


def OnModelChange(modelRef,  changeType):
    global g_modelChangeCallbackFired, g_callbackDgnModelRef, g_modelChangeType
    g_modelChangeCallbackFired = True
    g_callbackDgnModelRef = modelRef
    g_modelChangeType = changeType

def OnLevelChange(modelRef, levelId, changeTypeId):
    global g_levelChangeCallbackFired, g_callbackLevelId, g_levelChangeType, g_callbackDgnModelRef

    g_levelChangeCallbackFired = True
    g_callbackLevelId = levelId
    g_levelChangeType = changeTypeId
    g_callbackDgnModelRef = modelRef

def OnLevelPreChange(modelRef, levelId, changeTypeId):
    global g_levelPreChangeCallbackFired, g_callbackLevelId, g_levelChangeType, g_callbackDgnModelRef

    g_levelPreChangeCallbackFired = True
    g_callbackLevelId = levelId
    g_levelChangeType = changeTypeId
    g_callbackDgnModelRef = modelRef

    return BentleyStatus.eSUCCESS


''' Callback when create and active model  ''' 
def test_OnModelChange_Create_Active ():
    global g_modelChangeCallbackFired, g_callbackDgnModelRef, g_modelChangeType
    SystemCallback.SetModelChangeFunction(OnModelChange, FILE + '.OnModelChange')

    g_modelChangeCallbackFired = False
    g_callbackDgnModelRef = None
    g_modelChangeType = None

    dgnFile = ISessionMgr.ActiveDgnFile
    error = MsPyDgnModelStatus ()
    newModel = dgnFile.CreateNewModel(error, 'TestCreateModel', DgnModelType.eNormal, True)
    assert newModel is not None
    assert error.value == DgnModelStatus.eDGNMODEL_STATUS_Success

    assert g_modelChangeCallbackFired == True
    assert newModel.GetModelId() == g_callbackDgnModelRef.GetDgnModel().GetModelId()
    assert g_modelChangeType == ModelChangeType.eMODEL_CHANGE_Create

    g_modelChangeCallbackFired = False
    g_callbackDgnModelRef = None
    g_modelChangeType = None
    assert not ISessionMgr.GetManager().IsActiveModel(newModel)

    assert BentleyStatus.eSUCCESS == ModelRef.ActivateAndDisplay(newModel)

    assert ISessionMgr.GetManager().IsActiveModel(newModel)
    assert g_modelChangeCallbackFired == True
    assert newModel.GetModelId() == g_callbackDgnModelRef.GetDgnModel().GetModelId()
    assert g_modelChangeType == ModelChangeType.eMODEL_CHANGE_Active

    SystemCallback.SetModelChangeFunction(None, '')
    assert BentleyStatus.eSUCCESS == dgnFile.DeleteModel(newModel)

''' Callback when create and delete level ''' 
def test_OnLevelChange_Create_PreDelete():
    global g_levelChangeCallbackFired, g_levelPreChangeCallbackFired, g_callbackLevelId, g_levelChangeType, g_callbackDgnModelRef

    SystemCallback.SetLevelChangeFunction(OnLevelChange, FILE + '.OnLevelChange')
    g_levelChangeCallbackFired = False
    g_callbackDgnModelRef = None
    g_callbackLevelId = -100
    g_levelChangeType = None
    model = ISessionMgr.ActiveDgnModelRef
    assert model is not None

    ret = Level.Create (model, "TestLevel", 100)
    assert BentleyStatus.eSUCCESS == ret[0]

    assert g_levelChangeCallbackFired
    assert ret[1] == g_callbackLevelId
    assert LevelChangeType.eLEVEL_CREATE == g_levelChangeType
    SystemCallback.SetLevelChangeFunction(None, '')

    SystemCallback.SetLevelPreChangeFunction(OnLevelPreChange, FILE + '.OnLevelPreChange')
    g_levelPreChangeCallbackFired = False
    g_callbackDgnModelRef = None
    g_callbackLevelId = -100
    g_levelChangeType = None

    assert BentleyStatus.eSUCCESS == Level.Delete(model, ret[1])

    assert g_levelPreChangeCallbackFired
    assert ret[1] == g_callbackLevelId
    assert LevelChangeType.eLEVEL_PRE_DELETE == g_levelChangeType
    SystemCallback.SetLevelPreChangeFunction(None, '')

def runAllTest():
    test_OnModelChange_Create_Active()
    test_OnLevelChange_Create_PreDelete()

if __name__ == "__main__":
    #debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
    #print("Waiting for debugger attach")
    #debugpy.wait_for_client()
    #debugpy.breakpoint()
    runAllTest()
