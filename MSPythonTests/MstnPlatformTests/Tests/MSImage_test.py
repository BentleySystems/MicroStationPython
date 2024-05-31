import os
import pytest
import shutil
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import debugpy

# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    if not origin:
        return origin
    origin += fileLocation
    return origin

''' Get a DgnDocument from a filename and directory       '''    
def getFileFromDirectory(fileName, fileDir):
    ret = DgnDocument.CreateFromFileName (fileName, fileDir, -101, DgnDocument.FetchMode.eWrite)
    return ret

class MyModalEventHandler(IPyModalDialogEvents):

    ''' Callback when a modal Microstation dialog is opened ''' 
    def OnDialogOpened (self, dialogBoxName):
        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK
        
    ''' Callback when a modal Microstation dialog is closed ''' 
    def OnDialogClosed (delf, dialogBoxName, result):
        pass


def test_saveViewToRGB ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    status, img = MstnImage.saveViewToRGB (size, 1, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (len (img) ==1024*768*3)

def test_saveViewToRGBA ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    status, img = MstnImage.saveViewToRGBA (size, 1, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (len (img) ==1024*768*4)

def test_saveViewToFileWireFrame ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc, "", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    newFile = emptyDir + WString ("\\Test.jpg")
    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))
    status = MstnImage.saveView (str (newFile), size, 1, ImageFileFormat.eIMAGEFILE_JPEG, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))

def test_saveViewToFileHiddenLine ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc, "", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    newFile = emptyDir + WString ("\\Test1.jpg")
    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))
    status = MstnImage.saveView (str (newFile), size, 3, ImageFileFormat.eIMAGEFILE_JPEG, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))

def test_saveViewToFileConstant ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc, "", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    newFile = emptyDir + WString ("\\Test2.jpg")
    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))
    status = MstnImage.saveView (str (newFile), size, 5, ImageFileFormat.eIMAGEFILE_JPEG, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))

def test_saveViewToFileSmooth ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc, "", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    newFile = emptyDir + WString ("\\Test3.jpg")
    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))
    status = MstnImage.saveView (str (newFile), size, 6, ImageFileFormat.eIMAGEFILE_JPEG, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))

@pytest.mark.skip(reason="Somehow consumes pytest output")
def test_saveViewToFileVueRayTrace ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc, "", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    newFile = emptyDir + WString ("\\Test4.jpg")
    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))
    status = MstnImage.saveView (str (newFile), size, 13, ImageFileFormat.eIMAGEFILE_JPEG, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))

@pytest.mark.skip(reason="Somehow consumes pytest output")
def test_saveViewToFileVuePathTrace ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc, "", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    newFile = emptyDir + WString ("\\Test5.jpg")
    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))
    status = MstnImage.saveView (str (newFile), size, 14, ImageFileFormat.eIMAGEFILE_JPEG, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))   

    retVal, imageSize, colorMode, orientation = MstnImage.readFileInfo (str (newFile), ImageFileFormat.eIMAGEFILE_JPEG)
    assert (retVal == BentleyStatus.eSUCCESS)
    assert (imageSize.x == 1024)
    assert (imageSize.y == 768)
    assert (colorMode == ImageColorMode.eRGB)
    assert (orientation == 0)



def test_resizeImage ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    status, img = MstnImage.saveViewToRGB (size, 1, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (len (img) ==1024*768*3)

    newSize = Point2d ()
    newSize.x = 500
    newSize.y = 500

    status, img2 = MstnImage.resize (newSize, img, size)

    assert (status == BentleyStatus.eSUCCESS)
    assert (len (img2) ==500*500*3)


def test_readImageFile ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    status, imageMap, imageSize = MstnImage.readFileToRGB (str(newFile), ImageFileFormat.eIMAGEFILE_JPEG, None)
    assert (status == BentleyStatus.eSUCCESS)
    assert (imageSize.x == 1024)
    assert (imageSize.y == 768)    
    assert (len (imageMap) ==1024*768*3)


def test_extCreateFileFromRGB () :
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    size = Point2d ()
    size.x = 1024
    size.y = 768
    
    status, img = MstnImage.saveViewToRGB (size, 1, False, False, 0)

    assert (status == BentleyStatus.eSUCCESS)
    assert (len (img) ==1024*768*3)
    
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test6.jpg")

    if (os.path.exists (str (newFile))) :
        os.remove (str (newFile))

    status, newImg = MstnImage.RGBToRGBSeparate (img, size, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)

    transparency = bytearray ()
    status = MstnImage.extCreateFileFromRGB (str (newFile), ImageFileFormat.eIMAGEFILE_JPEG, ImageColorMode.eRGB, size, newImg, CompressionType.eCOMPRESSTYPE_DEFAULT, CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, transparency)
    assert (status == BentleyStatus.eSUCCESS)
    assert (os.path.exists (str (newFile)))   

def test_getExtension ():
    status, ext = MstnImage.getExtension (ImageFileFormat.eIMAGEFILE_JPEG)
    assert (status == BentleyStatus.eSUCCESS)
    assert (ext == 'jpg')

def test_getExportSupport ():
    status, defaultMode, rgbSupport, palette256Support, palette16Support, greyScaleSupport, monochromeSupport = MstnImage.getExportSupport (ImageFileFormat.eIMAGEFILE_JPEG)
    assert (status == BentleyStatus.eSUCCESS)
    assert (defaultMode == ImageColorMode.eRGB)
    assert (rgbSupport)
    assert (False == palette256Support)
    assert (False == palette16Support)
    assert (True == greyScaleSupport)
    assert (False == monochromeSupport)

def test_getImportFormatString ():

    status, formatName = MstnImage.getImportFormatString (ImageFileFormat.eIMAGEFILE_JPEG)

    assert (status == BentleyStatus.eSUCCESS)


def test_getExportFormatString ():

    status, formatName = MstnImage.getExportFormatString (ImageFileFormat.eIMAGEFILE_JPEG)

    assert (status == BentleyStatus.eSUCCESS)


def test_typeFromExtension ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    format= MstnImage.typeFromExtension (str (newFile))

    assert (format == ImageFileFormat.eIMAGEFILE_JPEG)

def test_applyGamma ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    status, imageMap, imageSize = MstnImage.readFileToRGB (str(newFile), ImageFileFormat.eIMAGEFILE_JPEG, None)
    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.RGBSeparateToRGBInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)

    MstnImage.applyGamma (imageMap, imageSize, 2.0)

    status = MstnImage.RGBToRGBSeparateInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)
    newFile2 = emptyDir + WString ("\\Test7.jpg")
    if (os.path.exists (str (newFile2))) :
        os.remove (str (newFile2))    
    transparency = bytearray ()
    status = MstnImage.extCreateFileFromRGB (str (newFile2), ImageFileFormat.eIMAGEFILE_JPEG, ImageColorMode.eRGB, imageSize, imageMap, CompressionType.eCOMPRESSTYPE_DEFAULT, CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, transparency)
    assert (status == BentleyStatus.eSUCCESS)

def test_negate ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    status, imageMap, imageSize = MstnImage.readFileToRGB (str(newFile), ImageFileFormat.eIMAGEFILE_JPEG, None)
    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.RGBSeparateToRGBInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)

    MstnImage.negate (imageMap, imageSize)

    status = MstnImage.RGBToRGBSeparateInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)
    newFile2 = emptyDir + WString ("\\Test8.jpg")
    if (os.path.exists (str (newFile2))) :
        os.remove (str (newFile2))    
    transparency = bytearray ()
    status = MstnImage.extCreateFileFromRGB (str (newFile2), ImageFileFormat.eIMAGEFILE_JPEG, ImageColorMode.eRGB, imageSize, imageMap, CompressionType.eCOMPRESSTYPE_DEFAULT, CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, transparency)
    assert (status == BentleyStatus.eSUCCESS)


def test_extractSubImage ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    status, imageMap, imageSize = MstnImage.readFileToRGB (str(newFile), ImageFileFormat.eIMAGEFILE_JPEG, None)
    assert (status == BentleyStatus.eSUCCESS)

    outSize = Point2d ()
    outSize.x = 200
    outSize.y = 200
    section  = BSIRect ()
    section.origin.x = 400
    section.origin.y = 300
    section.corner.x = section.origin.x + outSize.x -1
    section.corner.y = section.origin.y + outSize.y -1

    status, out = MstnImage.extractSubImage (outSize, imageMap, imageSize, section, ImageFormat.eIMAGEFORMAT_RGBSeparate)

    assert (status == BentleyStatus.eSUCCESS)

    newFile2 = emptyDir + WString ("\\Test9.jpg")
    if (os.path.exists (str (newFile2))) :
        os.remove (str (newFile2))    
    transparency = bytearray ()
    status = MstnImage.extCreateFileFromRGB (str (newFile2), ImageFileFormat.eIMAGEFILE_JPEG, ImageColorMode.eRGB, outSize, out, CompressionType.eCOMPRESSTYPE_DEFAULT, CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, transparency)
    assert (status == BentleyStatus.eSUCCESS)

def test_rotate ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    status, imageMap, imageSize = MstnImage.readFileToRGB (str(newFile), ImageFileFormat.eIMAGEFILE_JPEG, None)
    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.RGBSeparateToRGBInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)

    status, out, outSize = MstnImage.rotate (imageMap, imageSize, ImageFormat.eIMAGEFORMAT_RGB, 90)

    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.RGBToRGBSeparateInPlace (out, outSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)
    newFile2 = emptyDir + WString ("\\Test10.jpg")
    if (os.path.exists (str (newFile2))) :
        os.remove (str (newFile2))    
    transparency = bytearray ()
    status = MstnImage.extCreateFileFromRGB (str (newFile2), ImageFileFormat.eIMAGEFILE_JPEG, ImageColorMode.eRGB, outSize, out, CompressionType.eCOMPRESSTYPE_DEFAULT, CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, transparency)
    assert (status == BentleyStatus.eSUCCESS)

def test_mirror ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    status, imageMap, imageSize = MstnImage.readFileToRGB (str(newFile), ImageFileFormat.eIMAGEFILE_JPEG, None)
    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.RGBSeparateToRGBInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.mirror (imageMap, imageSize, ImageFormat.eIMAGEFORMAT_RGB, True)

    assert (status == BentleyStatus.eSUCCESS)

    status = MstnImage.RGBToRGBSeparateInPlace (imageMap, imageSize, ImageColorMode.eRGB)
    assert (status == BentleyStatus.eSUCCESS)
    newFile2 = emptyDir + WString ("\\Test11.jpg")
    if (os.path.exists (str (newFile2))) :
        os.remove (str (newFile2))    
    transparency = bytearray ()
    status = MstnImage.extCreateFileFromRGB (str (newFile2), ImageFileFormat.eIMAGEFILE_JPEG, ImageColorMode.eRGB, imageSize, imageMap, CompressionType.eCOMPRESSTYPE_DEFAULT, CompressionRatio.eCOMPRESSIONRATIO_DEFAULT, transparency)
    assert (status == BentleyStatus.eSUCCESS)



def test_typeFromFile ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    imgType = MstnImage.typeFromFile (str(newFile))
    assert (imgType == ImageFileFormat.eIMAGEFILE_JPEG)

def test_fileType ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")    

    newFile = emptyDir + WString ("\\Test3.jpg")
    imgType = MstnImage.fileType (ImageFileFormat.eIMAGEFILE_UNKNOWN, str(newFile))
    assert (imgType == ImageFileFormat.eIMAGEFILE_JPEG)



#if __name__ == "__main__":
    #debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
    #print("Waiting for debugger attach")
    #debugpy.wait_for_client()
    #debugpy.breakpoint()
    #test_saveViewToRGB ()
    #test_saveViewToRGBA ()
    #test_saveViewToFileWireFrame ()
    #test_saveViewToFileHiddenLine ()
    #test_saveViewToFileConstant ()
    #test_saveViewToFileSmooth ()
    #test_saveViewToFileVueRayTrace ()
    #test_saveViewToFileVuePathTrace ()
    #test_resizeImage ()
    #test_readImageFile ()
    #test_extCreateFileFromRGB ()
    #test_getExtension ()
    #test_getExportSupport ()
    #test_getImportFormatString ()
    #test_getExportFormatString ()
    #test_typeFromExtension ()
    #test_applyGamma ()
    #test_negate ()
    #test_extractSubImage ()
    #test_rotate ()
    #test_mirror ()
    #test_typeFromFile ()
    #test_fileType ()