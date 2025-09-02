# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
# -*- coding: utf-8 -*-

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to create Raster Attachment
'''

def createRasterAttachment(extentInUOR=DPoint2d(100, 100)):
    """
    Creates a raster attachment in the active DGN model.

    :param extentInUOR: The extent of the raster in units of resolution (UOR).
    :type extentInUOR: DPoint2d

    :returns: True if the raster attachment is successfully created and added to the model, False otherwise.
    :rtype: bool
    """
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