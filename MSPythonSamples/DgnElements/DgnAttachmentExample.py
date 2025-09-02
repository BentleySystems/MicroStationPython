# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to create a DGN attachment in an active model.
''' 

def createDgnAttachment():
    """
    Creates a new DGN attachment in the active DGN model.

    This function performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Loads the DGN file associated with the active model.
    3. Retrieves the moniker of the document associated with the DGN file.
    4. Checks if a model with the name 'MyNewModel' exists in the DGN file.
    5. If the model does not exist, creates a new model with the name 'MyNewModel'.
    6. Creates a new DGN attachment using the moniker and the model name 'MyNewModel'.

    :returns: True if the DGN attachment is successfully created, False otherwise.
    :rtype: bool
    """    
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    loadDgnFile  = ACTIVEMODEL.GetDgnFile()
    if loadDgnFile is None:
        return False
    
    moniker = loadDgnFile.GetDocument().GetMoniker()
    if moniker is None:
        return False
 
    modelName = 'MyNewModel'
    modelId = loadDgnFile.FindModelIdByName(modelName)
    if(INVALID_MODELID == modelId):
        error = MsPyDgnModelStatus ()
        ret = loadDgnFile.CreateNewModel(error, modelName, DgnModelType.eNormal, False)
        if error.value != eDGNMODEL_STATUS_Success:
            return False

    ret = ACTIVEMODEL.CreateDgnAttachment(moniker, 'MyNewModel', False)
    if BentleyStatus.eSUCCESS != ret[0]:
        return False
    
    return True


if __name__ == "__main__":
    if True != createDgnAttachment():
        print("Return false when call createDgnAttachment!")