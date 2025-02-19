# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''Create dgn attachment in Microstation'''
def createDgnAttachment():
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