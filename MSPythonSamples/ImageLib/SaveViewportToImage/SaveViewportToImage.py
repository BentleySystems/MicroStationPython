# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Save the screenshot of active view  as a png file.
'''
def SaveViewScreenshotToPNG():
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

