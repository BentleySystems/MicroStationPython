from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import os

def save_active_view_to_image(file_format='PNG', width=1024, height=768):
    # Get the active view set
    vSet = IViewManager.GetActiveViewSet()
    viewport = vSet.GetSelectedViewport()

    if viewport is None:
        print("No view selected!")
        return

    viewIndex = viewport.GetViewNumber()

    # Define the image size
    imageSize = Point2d()
    imageSize.x = width
    imageSize.y = height

    # Define the file format
    if file_format.upper() == 'PNG':
        imageFileFormat = ImageFileFormat.eIMAGEFILE_PNG
    elif file_format.upper() == 'JPG':
        imageFileFormat = ImageFileFormat.eIMAGEFILE_JPEG
    elif file_format.upper() == 'TIFF':
        imageFileFormat = ImageFileFormat.eIMAGEFILE_TIFF
    else:
        print("Unsupported file format!")
        return

    # Create the image file path
    emptyDir = WString()
    ConfigurationManager.GetLocalTempDirectory(emptyDir, "")
    tempFileName = f"viewScreenshot.{file_format.lower()}"
    fileSpec = str(emptyDir) + str(tempFileName)
    BeFileName.BeDeleteFile(fileSpec)

    # Save the view screenshot to the image file
    retVal = MstnImage.saveView(fileSpec, imageSize, MSRenderMode.eConstantShade, imageFileFormat, False, False, viewIndex)

    if BentleyStatus.eSUCCESS == retVal:
        print(f"Image saved successfully at {fileSpec}")
    else:
        print("Failed to save view screenshot as an image")

# Example usage
save_active_view_to_image(file_format='PNG', width=1920, height=1080)