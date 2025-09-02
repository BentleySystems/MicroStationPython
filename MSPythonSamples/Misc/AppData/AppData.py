# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to use DgnModelAppData to listen for events in a DgnModel
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
        """
        Perform cleanup operations for the given host.

        This method sets the `cleanUpCalled` attribute of `datainfo` to True
        and prints a message indicating that the cleanup has been called.

        :param host: The host object that requires cleanup.
        :type host: object
        """
        self.datainfo.cleanUpCalled = True
        print("_OnCleanup Called")
    
    def __OnFilled(self, host):
        """
        Private method that is called when the data is filled.

        :param host: The host object that triggers the filled event.
        :type host: object
        """
        self.datainfo.filledCalled = True
        print("__OnFilled Called")
     
    def _OnEmpty(self, host):
        """
        Handles the event when the data is empty.

        This method sets the `emptyCalled` attribute of `datainfo` to True and prints a message indicating that the method was called.

        :param host: The host object that triggers this method.
        :type host: object
        
        :returns: Always returns False.
        :rtype: bool
        """
        self.datainfo.emptyCalled = True
        print("_OnEmpty called")
        return False
    
    def _OnEmptied(self, host):
        """
        Handle the event when the data is emptied.

        This method sets the `emptiedCalled` attribute of `datainfo` to True
        and prints a message indicating that the method was called.

        :param host: The host object that triggered the event.
        :type host: object
        
        :returns: Always returns False.
        :rtype: bool
        """
        self.datainfo.emptiedCalled = True
        print("_OnEmptied called")
        return False
    
    def _OnModelDelete(self, host):
        """
        Handles the deletion of a model.

        This method is called when a model is deleted. It sets the 
        `modelDeleteCalled` attribute of `datainfo` to True and prints 
        a message indicating that the method was called.

        :param host: The host object associated with the model being deleted.
        :type host: object
        """
        self.datainfo.modelDeleteCalled = True
        print("_OnModelDelete called")
    
    def _OnModelUnDelete(self, host):
        """
        Handles the event when a model is undeleted.

        This method is called when a model is restored from a deleted state.
        It sets the `modelUnDeleteCalled` attribute of `datainfo` to True and 
        prints a message indicating that the method was called.

        :param host: The host object that triggered the undelete event.
        :type host: object
        """
        self.datainfo.modelUnDeleteCalled = True
        print("_OnModelUnDelete called")
    
    def _OnElementAdded(self, host, elem, isGraphicsList):
        """
        Handles the event when an element is added.

        :param host: The host object where the element is added.
        :type host: object
        :param elem: The element that is added.
        :type elem: object
        :param isGraphicsList: Flag indicating if the element is part of a graphics list.
        :type isGraphicsList: bool
        """
        self.datainfo.onElementAdd = True
        self.datainfo.ElementsCount += 1
        print("_OnElementAdded called")
    
    def _OnSaveModelProperties(self, host, original):
        """
        Handles the event of saving model properties.

        This method is called when the model properties need to be saved. It performs
        necessary actions to save the properties of the model.

        :param host: The host object that contains the model properties.
        :type host: object
        :param original: The original properties of the model before saving.
        :type original: object
        """
        print("_OnSaveModelProperties called")
    
    def GetKey(self):
        """
        Retrieve the key associated with the DgnModelAppData.

        :returns: The key of the DgnModelAppData.
        :rtype: object
        """
        return DgnModelAppData.Key()
    
def AddElement(model):
    """
    Adds an elliptical element to the given model.
    
    :param model: The model to which the element will be added.
    :type model: ModelType
    
    :return: The handle to the created element if successful, otherwise None.
    :rtype: EditElementHandle or None
    """
    center  = DPoint3d (0,0,0)
    eeh = EditElementHandle()
    ell = DEllipse3d.FromCenterRadiusXY(center, 1000)
    if (BentleyStatus.eSUCCESS == ArcHandler.CreateArcElement(eeh, None, ell, True, model)):
        eeh.AddToModel()
        return eeh

    return None

def InvokeModelAppDataListener():
    """
    This function demonstrates the usage of model app data in a DGN file. It performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Loads the DGN file associated with the active model.
    3. Searches for a model by name within the DGN file.
    4. Initializes model app data and its key.
    5. If the model is found, it loads the model and adds app data to it. Otherwise, it creates a new model and adds app data to it.
    6. Invokes the `_OnElementAdded` event by adding an element to the model.
    7. Invokes the `_OnSaveModelProperties` event by modifying and saving model properties.
    8. Processes changes in the DGN file.
    9. Invokes the `_OnEmpty` event by emptying the model.
    10. Invokes the `__OnFilled` event by filling model sections.
    11. Invokes the `_OnModelDelete` event by deleting the model.
    12. Invokes the `_OnCleanup` event by dropping the app data from the model.
    """
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
