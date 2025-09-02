# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $


from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''
Sample demonstrating how to create a model and change its type
''' 

def CreateModel(modelName):
    """
    Create a new model in the active DGN file if it does not already exist.

    :param modelName: The name of the model to create.
    :type modelName: str
    :return: True if the model was created or already exists, False otherwise.
    :rtype: bool
    """
    # Get active dgn model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    # Get current dgn file
    dgnFile  = ACTIVEMODEL.GetDgnFile()
    if dgnFile is None:
        return False
    
    # Get model ID by given model name, if ID is invalid then create new model with given name
    modelId = dgnFile.FindModelIdByName(modelName)
    if(INVALID_MODELID == modelId):
        error = MsPyDgnModelStatus ()
        if dgnFile.CreateNewModel(error, modelName, DgnModelType.eDrawing, False) is None:
            return False
            
    return True


def ChangeModelTypeToSheet(modelName):
    """
    Change the type of the specified model to a sheet model.

    :param modelName: The name of the model to change.
    :type modelName: str
    :return: True if the model type was successfully changed to sheet, False otherwise.
    :rtype: bool
    """
    # Get active dgn model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    # Get current dgn file
    dgnFile  = ACTIVEMODEL.GetDgnFile()
    if dgnFile is None:
        return False
    
    modelId = dgnFile.FindModelIdByName(modelName)
    if(INVALID_MODELID == modelId):
        return False

    dgnModel = dgnFile.LoadModelById(modelId)
    if dgnModel is None:
        return False

    if dgnModel.ModelInfo is None:
        return False
        
    if dgnModel.ModelInfo.GetModelType() == DgnModelType.eSheet:
        return True

    modelInfo = dgnModel.ModelInfo.MakeCopy()
    modelInfo.SetModelType(DgnModelType.eSheet)
    if eSUCCESS != dgnModel.SetModelInfo(modelInfo):
        return False

    return True




if __name__ == "__main__":
    modelName = "TestModel001"
    CreateModel(modelName)
    ChangeModelTypeToSheet(modelName)
    

