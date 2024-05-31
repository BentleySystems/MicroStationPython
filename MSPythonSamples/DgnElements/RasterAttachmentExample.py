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


'''Create raster attachment in Microstation'''
def createRasterAttachment(extentInUOR=DPoint2d(100, 100)):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    eeh = EditElementHandle()
    identityTransform = Transform()
    
    fullPath = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\4521-5691.tif"
    moniker = DgnDocumentMoniker.CreateFromRawData("4521-5691.tif", 
                                                   fullPath,
                                                   None, "",
                                                   False, None)
    if moniker is None:
        return False
    
    status = IRasterAttachmentEdit.CreateRasterAttachment(eeh, None, 
                                                           moniker, 
                                                           identityTransform, 
                                                           extentInUOR, 
                                                           ACTIVEMODEL)
    if BentleyStatus.eSUCCESS != status:
        return False

    # add the raster attachment to the cache
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        return False
    
    return True


if __name__ == "__main__":
    if True != createRasterAttachment():
        print("Return false when call createRasterAttachment!")