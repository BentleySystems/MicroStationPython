# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
/*=================================================================================**//**
* Example showing how to use DgnModelAppData to listen to DgnModel events.
* 
* Application-defined object that is stored with a DgnModel. This object is notified as significant events occur
* for its "host" DgnModel. By creating a subclass of this class, applications can maintain relevant information about
* a DgnModel with the DgnModel for efficient lookup and lifecycle management.
* 
* @bsiclass                                                               Bentley Systems
+===============+===============+===============+===============+===============+======*/
'''
class MyModelAppData(object):

    def __init__(self):
        self.ElementsCount = 0
        self.graphicElementsCount = 0
        self.controlElementsCount = 0
        self.cleanUpCalled = False
        self.filledCalled = False
        self.emptyCalled = False
        self.emptiedCalled = False
        self.modelDeleteCalled = False
        self.modelUnDeleteCalled = False
        self.onElementAdd = False
        self.onSaveModelProps = False

class MyModelListener (DgnModelAppData):

    def __init__(self):
        DgnModelAppData.__init__(self)
        self.datainfo = MyModelAppData()

    def _OnCleanup(self, host):
        self.datainfo.cleanUpCalled = True
        print("_OnCleanup Called")
    
    def __OnFilled(self, host):
        self.datainfo.filledCalled = True
        print("__OnFilled Called")
     
    def _OnEmpty(self, host):
        self.datainfo.emptyCalled = True
        print("_OnEmpty called")
        return False
    
    def _OnEmptied(self, host):
        self.datainfo.emptiedCalled = True
        print("_OnEmptied called")
        return False
    
    def _OnModelDelete(self, host):
        self.datainfo.modelDeleteCalled = True
        print("_OnModelDelete called")
    
    def _OnModelUnDelete(self, host):
        self.datainfo.modelUnDeleteCalled = True
        print("_OnModelUnDelete called")
    
    def _OnElementAdded(self, host, elem, isGraphicsList):
        self.datainfo.onElementAdd = True
        self.datainfo.ElementsCount += 1
        print("_OnElementAdded called")
    
    def _OnSaveModelProperties(self, host, original):
        print("_OnSaveModelProperties called")
    
    def GetKey(self):
        return DgnModelAppData.Key()
    
def AddElement(model):
    center  = DPoint3d (0,0,0)
    eeh = EditElementHandle()
    ell = DEllipse3d.FromCenterRadiusXY(center, 1000)
    if (BentleyStatus.eSUCCESS == ArcHandler.CreateArcElement(eeh, None, ell, True, model)):
        eeh.AddToModel()
        return eeh

    return None

def InvokeModelAppDataListener():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    loadDgnFile  = ACTIVEMODEL.GetDgnFile()
    modelName = 'NewModelWithAppData'
    modelid = loadDgnFile.FindModelIdByName (modelName)

    # Init model app data and key
    appdata = MyModelListener()
    appdataKey = appdata.GetKey()

    if(INVALID_MODELID != modelid):
        modelNew = loadDgnFile.LoadModelById (modelid)
        modelNew.AddAppData(appdataKey, appdata)
        modelNew.FillSections(DgnModelSections.eAll)
    else:
        error = MsPyDgnModelStatus ()
        modelNew = loadDgnFile.CreateNewModel (error, modelName, DgnModelType.eNormal, True)
        modelNew.AddAppData(appdataKey, appdata)

    # invoke DgnModelAppData._OnElementAdded
    AddElement(modelNew)

    # invoke DgnModelAppData._OnSaveModelProperties
    modelInfo = modelNew.ModelInfo.MakeCopy()
    clockwise = not modelInfo.GetDirectionClockwise()
    modelInfo.SetDirectionClockwise (clockwise)
    modelNew.SetModelInfo(modelInfo)
    modelNew.SaveModelSettings()

    loadDgnFile.ProcessChanges(DgnSaveReason.eUserInitiated)

    # invoke DgnModelAppData._OnEmpty
    modelNew.Empty(True)

    # invoke DgnModelAppData.__OnFilled
    modelNew.FillSections(DgnModelSections.eModel)

    # invoke DgnModelAppData._OnModelDelete
    loadDgnFile.DeleteModel(modelNew)

    # invoke DgnModelAppData._OnCleanup
    modelNew.DropAppData(appdataKey)

if __name__ == "__main__":
    InvokeModelAppDataListener()
