# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Function to query rasters in the model
Use the GetRasterFrameHandler() method to get the raster handler 
of element instead of using GetHandler() method.

'''
def ListAndQueyRastersInModel():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()
    
    for elem in graphicalElements:
        elementId = elem.GetElementId()
        eh = ElementHandle(elem)
        IRasterQuery = eh.GetRasterFrameHandler()

        if (isinstance(IRasterQuery, IRasterAttachmentQuery)):
            print(f"Element {elementId} is a raster, its extent is:")
            print(IRasterQuery.GetExtent(eh))
        else:
            print(f"Element {elementId} isn't a raster")

    rasters = RasterFrameElementCollection(dgnModel)
    for raster in rasters:
        rasterHandler = raster.GetRasterFrameHandler()
        elementId = raster.GetElementId()
        if (isinstance(rasterHandler, RasterFrameHandler)):
            print(f"Handler of element {elementId} is a RasterFrameHandler")

if __name__ == "__main__":
    ListAndQueyRastersInModel()