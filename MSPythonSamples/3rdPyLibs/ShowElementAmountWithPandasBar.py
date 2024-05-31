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
def AttachRaster(fileName, fullPath, modelRef, extentInch=DPoint2d(6.4, 4.8), ptLocation=DPoint3d(0.0, 0.0, 0.0)):
    moniker = DgnDocumentMoniker.CreateFromRawData(fileName, fullPath, None, "", False, None)   # Create a moniker from the file name and full path
    if moniker is None:
        return False     # Return False if the moniker creation failed

    modelInfo    = modelRef.GetModelInfo()  # Get information about the model
    scaleFactor = modelInfo.GetUorPerMeter();   # Get the scale factor from the model info

    extentInUOR = DPoint2d()
    extentInUOR.x = scaleFactor * extentInch.x / METERTOINCH  # Convert the extent in inches to UOR units
    extentInUOR.y = scaleFactor * extentInch.y / METERTOINCH   # Convert the extent in inches to UOR units

    pixelNumX = extentInch.x * FIGDPI  # Calculate the number of pixels for the X axis
    pixelNumY = extentInch.y * FIGDPI   # Calculate the number of pixels for the Y axis

    uorsPerPixelX = extentInUOR.x / pixelNumX  # Calculate the UORs per pixel for the X axis
    uorsPerPixelY = extentInUOR.y / pixelNumY  # Calculate the UORs per pixel for the Y axis

    rasterTransform = Transform()
    rasterTransform.SetTranslation(ptLocation)   # Set the translation of the raster transform to the given point location
    rasterTransform.ScaleMatrixColumns (uorsPerPixelX, uorsPerPixelY, 1.0)   # Scale the matrix columns based on the UORs per pixel

    eeh = EditElementHandle()
    status = IRasterAttachmentEdit.CreateRasterAttachment(eeh, None, moniker, rasterTransform, extentInUOR, modelRef)
    if BentleyStatus.eSUCCESS != status:
        return False     # Return False if creating the raster attachment failed

    # add the raster attachment to the cache
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        return False   # Return False if adding the raster attachment to the model failed
    
    return True      # Return True if all operations were successful

'''
Function to define the size and location of the output image
'''
def GetImageSizeLocation():
    vSet = IViewManager.GetActiveViewSet()  # Get the active view set
    viewport = vSet.GetSelectedViewport()   # Get the selected viewport from the view set

    uorExtentPt = DPoint2d()

    if viewport is None:
        return uorExtentPt  # Return an empty point (x, y) if there is no viewport

    viewInfo = viewport.GetViewInfo()   # Get information about the viewport
    startPt = viewInfo.GetOrigin()      # Get the origin (starting) point of the viewport

    delta =  viewInfo.GetDelta()        # Get the delta (distance) from the origin to the end of the viewport
    viewRot = viewInfo.GetRotation()    # Get the rotation information about the viewport

    viewXVec = DVec3d()                  # Initialize vectors for X, Y, and Z axes
    viewYVec = DVec3d()
    viewZVec = DVec3d()

    viewRot.GetRow (viewXVec, 0)       # Get the X vector from the rotation information
    viewRot.GetRow (viewYVec, 1)       # Get the Y vector from the rotation information
    viewRot.GetRow (viewZVec, 2)      # Get the Z vector from the rotation information

    endPoint = DPoint3d()              # Initialize a point for the end of the viewport
    endPoint.Init(0,0,0)             # Set the coordinates to 0,0,0
    endPoint.SumOf(startPt,  viewXVec, delta.x, viewYVec, delta.y, viewZVec, delta.z)   # Calculate the end point based on the start point and viewport information

    uorExtentPt.x = (endPoint.x - startPt.x) / 3.0       # Calculate the X coordinate of the extent point
    uorExtentPt.y = uorExtentPt.x * FACTOR           # Calculate the Y coordinate of the extent point based on the X coordinate and a factor

    return uorExtentPt, startPt   # Return the extent point and the starting point

'''Function to count elements as per type and display element amount with pandas chart for each type'''
def CountElementsByType():
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()  # Get the current design model

    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()  # Get all graphical elements (e.g., shapes, text)

    #Count the element number for each type and put the number into a dictionary with key type name
    elemAmountDict = {}  # Initialize an empty dictionary to store element counts
    typeString = WString()  # Initialize an empty string to store type names

    for elRef in graphicalElements:
        eeh = EditElementHandle(elRef, dgnModel)  # Get the edit element handle for each graphical element
        eeh.GetHandler().GetTypeName(typeString, 5000)  # Get the name of each element (e.g., shape type)

        if elemAmountDict.get(str(typeString)) != None:
            elemAmountDict[str(typeString)] += 1  # Increment the count for each unique element name
        else:
            elemAmountDict[str(typeString)] = 1  # Set the initial count for each unique element name

    if len(elemAmountDict) == 0:
        print ("No Element in Model")  # Print a message if there are no elements in the model
        return  # Return from the function without creating an image

    #Create a chart image with the element amount data and save the image as a png file
    emptyDir = WString ()  # Get the local temporary directory path
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")  # Initialize an empty string for the temporary directory

    tmpImageFileName = os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno) + '_image.png'  # Create a file name based on the current script and line number
    tmpImageFullPath = str(emptyDir) + tmpImageFileName  # Get the full path of the temporary image file

    uorExtentPt, imageOrg = GetImageSizeLocation()  # Get the size of the chart image in pixels (x, y)

    modelInfo = ACTIVEMODEL.GetModelInfo()  # Get information about the current design model
    imageWidth  = uorExtentPt.x / modelInfo.GetUorPerMeter() * METERTOINCH  # Calculate the width of the chart image in inches
    imageHeight = uorExtentPt.y / modelInfo.GetUorPerMeter() * METERTOINCH  # Calculate the height of the chart image in inches

    plt.rcParams["figure.figsize"] = [imageWidth, imageHeight]  # Set the size of the chart image in inches (x, y)
    plt.rcParams["figure.autolayout"] = True  # Automatically adjust the layout of the chart
    plt.rcParams["figure.dpi"] = FIGDPI  # Set the resolution of the chart image in dots per inch

    df2=pd.DataFrame(elemAmountDict.values(),index=elemAmountDict.keys(), columns=pd.Index(['Amount']))  # Create a pandas DataFrame from the element counts dictionary
    df2.plot(kind='bar')  # Plot the data as a bar chart

    plt.savefig(tmpImageFullPath)   # Save the chart image to the temporary file path
    plt.close()  # Close the plot

    #Attach the image to active model
    AttachRaster(tmpImageFileName, tmpImageFullPath, ACTIVEMODEL, DPoint2d(imageWidth, imageHeight), imageOrg)  # Attach the chart image to the current design model at the specified coordinates (x, y)
if __name__ == "__main__":
    CountElementsByType()
