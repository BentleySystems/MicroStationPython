# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
import sys
import math

'''
Running this sample needs libraries pandas and matplotlib installed.
This sample uses library pandas to create a bar chart image . 
The image is attached in the active model as a raster element, and shows 
the element amount as per type.
'''
import pandas as pd
from matplotlib import pyplot as plt

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

METERTOINCH = 39.37007874
FIGDPI = 100
FACTOR = 0.5

'''
Function to attach the image
'''
def AttachRaster (fileName, fullPath, modelRef, extentInch=DPoint2d(6.4, 4.8), ptLocaton=DPoint3d(0.0, 0.0, 0.0)):
    moniker = DgnDocumentMoniker.CreateFromRawData(fileName, fullPath, None, "", False, None)
    if moniker is None:
        return False

    modelInfo   = modelRef.GetModelInfo()
    scaleFactor = modelInfo.GetUorPerMeter();

    extentInUOR = DPoint2d()
    extentInUOR.x = scaleFactor * extentInch.x / METERTOINCH
    extentInUOR.y = scaleFactor * extentInch.y / METERTOINCH

    pixelNumX = extentInch.x * FIGDPI
    pixelNumY = extentInch.y * FIGDPI

    uorsPerPixelX = extentInUOR.x / pixelNumX
    uorsPerPixelY = extentInUOR.y / pixelNumY

    rasterTransform = Transform()
    rasterTransform.SetTranslation(ptLocaton)
    rasterTransform.ScaleMatrixColumns (uorsPerPixelX, uorsPerPixelY, 1.0)

    eeh = EditElementHandle()
    status = IRasterAttachmentEdit.CreateRasterAttachment(eeh, None, moniker, rasterTransform, extentInUOR, modelRef)
    if BentleyStatus.eSUCCESS != status:
        return False

    # add the raster attachment to the cache
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        return False
    
    return True

'''
Function to define the size and location of the output image
'''
def GetImageSizeLocation():
    vSet = IViewManager.GetActiveViewSet()
    viewport = vSet.GetSelectedViewport()
    
    uorExtentPt = DPoint2d()

    if viewport is None:
        return uorExtentPt
    
    viewInfo = viewport.GetViewInfo()
    startPt = viewInfo.GetOrigin()

    delta =  viewInfo.GetDelta()
    viewRot = viewInfo.GetRotation()

    viewXVec = DVec3d()
    viewYVec = DVec3d()
    viewZVec = DVec3d()

    viewRot.GetRow (viewXVec, 0)
    viewRot.GetRow (viewYVec, 1)
    viewRot.GetRow (viewZVec, 2)

    endPoint = DPoint3d()
    endPoint.Init(0,0,0)
    endPoint.SumOf(startPt,  viewXVec, delta.x, viewYVec, delta.y, viewZVec, delta.z)

    uorExtentPt.x = (endPoint.x - startPt.x) / 3.0
    uorExtentPt.y = uorExtentPt.x * FACTOR

    return uorExtentPt, startPt

'''
Function to count elements as per type and display element amount with pandas chart for each type
'''
def CountElementsByType():
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()

    #Count the element number for each type and put the number into a dictionary with key type name
    elemAmountDict = {}
    typeString = WString()

    for elRef in graphicalElements:
        eeh = EditElementHandle(elRef, dgnModel)
        eeh.GetHandler().GetTypeName(typeString, 5000)

        if elemAmountDict.get(str(typeString)) != None:
            elemAmountDict[str(typeString)] += 1
        else:
            elemAmountDict[str(typeString)] = 1

    if len(elemAmountDict) == 0:
        print ("No Element in Model")
        return

    #Create a chart image with the element amount data and save the image as a png file
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    tmpImageFileName = os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'_image.png'
    tmpImageFullPath = str(emptyDir) + tmpImageFileName

    uorExtentPt, imageOrg = GetImageSizeLocation()

    modelInfo = ACTIVEMODEL.GetModelInfo()
    imageWidth  = uorExtentPt.x / modelInfo.GetUorPerMeter() * METERTOINCH #inch
    imageHeight = uorExtentPt.y / modelInfo.GetUorPerMeter() * METERTOINCH #inch

    plt.rcParams["figure.figsize"] = [imageWidth, imageHeight]
    plt.rcParams["figure.autolayout"] = True
    plt.rcParams["figure.dpi"] = FIGDPI

    df2=pd.DataFrame(elemAmountDict.values(),index=elemAmountDict.keys(), columns=pd.Index(['Amount']))
    df2.plot(kind='bar')

    plt.savefig(tmpImageFullPath)
    plt.close()

    #Attach the image to active model
    AttachRaster(tmpImageFileName, tmpImageFullPath, ACTIVEMODEL, DPoint2d(imageWidth, imageHeight), imageOrg)

if __name__ == "__main__":
    CountElementsByType()
