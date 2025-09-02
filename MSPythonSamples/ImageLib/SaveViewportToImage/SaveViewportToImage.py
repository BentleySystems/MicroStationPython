# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
This sample demonstrates how to save a screenshot of the active view to a PNG file.
'''

def SaveViewScreenshotToPNG():
    """
    This function captures the currently selected viewport from the active view set
    and saves it as a PNG image. It performs the following steps:
    
    1. Retrieves the active view set using `IViewManager.GetActiveViewSet()`.
    2. Gets the selected viewport from the view set.
    3. Checks if a viewport is selected. If not, it prints a message and exits.
    4. Obtains the view index of the selected viewport.
    5. Creates an instance of `ViewPortInfo` and initializes it with the contents of the numbered view.
    6. Retrieves the origin and corner of the viewport in pixels.
    7. Calculates the width and height of the viewport in pixels.
    8. Saves the view screenshot to an RGBA buffer using `MstnImage.saveViewToRGBA`.
    9. Checks the return value to determine if the screenshot was saved successfully. If not, it prints an error message and exits.

    :raises: None
    :returns: None
    """
    print("Save view screenshot an image started")

    vSet = IViewManager.GetActiveViewSet()  # Get the active view set
    viewport = vSet.GetSelectedViewport()   # Get the selected viewport from the view set

    if viewport is None:
        print ("No view selected!")
        return  # Return if there is no selected viewport
    
    viewIndex = viewport.GetViewNumber() # Get the active view index
    viewportInfo = ViewPortInfo()        # Create an instance of ViewPortInfo 
    MstnViewPortInfo.From(viewportInfo, viewIndex) # Initialize the ViewPortInfo instance with the contents of the numbered view

    origin = viewportInfo.GetPixelOrigin () # Get the viewport origin in pixels
    corner = viewportInfo.GetPixelCorner () # Get the viewport corner in pixels

    imagesize = Point2d()
    imagesize.x = corner.x - origin.x # Get viewport width in pixels
    imagesize.y = corner.y - origin.y # Get viewport height in pixels

    #Save view screenshot to RGBA buffer
    retVal, imageMap = MstnImage.saveViewToRGBA(imagesize, MSRenderMode.eConstantShade, False, False, viewIndex)

    if BentleyStatus.eSUCCESS != retVal:
        print("Failed to save view screenshot as an image")
        return

    # Create the png save path.
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    tempFileName = "viewScreenshot.png"
    fileSpec = str (emptyDir) + str (tempFileName)
    BeFileName.BeDeleteFile (fileSpec)

    #Save RGBA buffer as a png Image
    retVal = MstnImage.extCreateFileFromRGB(fileSpec, ImageFileFormat.eIMAGEFILE_PNG, ImageColorMode.eRGBA, imagesize, 
                                            imageMap, CompressionType.eCOMPRESSTYPE_DEFAULT, 
                                            CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, None)
    
    if BentleyStatus.eSUCCESS == retVal:
            print (fileSpec + str(" generated"))  # Output message to report the png file path if succeeded
    else:
            print("Failed to save view screenshot as an image") # Output message to report failure if not succeeded

if __name__ == "__main__":
    SaveViewScreenshotToPNG()

