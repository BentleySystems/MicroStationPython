# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
# -*- coding: utf-8 -*-


from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to list and query raster elements in a model
'''

def ListAndQueyRastersInModel():
    """
    Lists and queries raster elements in the active DGN model.
    Use the GetRasterFrameHandler() method to get the raster handler 
    of element instead of using GetHandler() method.
    
    This function performs the following steps:
    1. Retrieves all graphical elements from the active DGN model.
    2. Checks if each element is a raster and prints its extent if it is.
    3. Retrieves all raster frame elements from the model and prints their handlers.

    :returns: None
    """
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