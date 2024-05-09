import os
import pytest
import shutil
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import faulthandler

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



def test_GetMasterFile ():
    assert (str (DgnFile.GetMasterFile ().GetFileName ()) == str (ISessionMgr.GetMasterDgnFile ().GetFileName ()))

''' Find ModelId by name  ''' 
def test_FindModelIDByName ():
    faulthandler.disable ()
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

    ret = DgnFile.FindModelIDByName (DgnFile.GetMasterFile (), "Close mesh to volume")

    assert (BentleyStatus.eSUCCESS == ret[0])
    assert (2 == ret[1])

''' Find Element by id  ''' 
def test_FindElemByID ():
    faulthandler.disable ()
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

    elRef = DgnFile.FindElemByID (DgnFile.GetMasterFile (), 130163, False)

    assert (None != elRef)
    assert (130163 == elRef.GetElementId ())


''' Has File Changed  ''' 
def test_HasPendingChanges ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    changes = DgnFile.HasPendingChanges (DgnFile.GetMasterFile ())
    assert (changes == False)

''' Get File Version  ''' 
def test_GetVersion ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret = DgnFile.GetVersion (DgnFile.GetMasterFile ())
    format = DgnFileFormatType.eV8
    major = 8
    minor = 9
    assert (ret[0] == BentleyStatus.eSUCCESS)
    assert (ret[1] == format)
    assert (ret[2] == major)
    assert (ret[3] == minor)


''' IsProtected  ''' 
def test_IsProtected ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret = DgnFile.IsProtected (DgnFile.GetMasterFile ())
    assert (ret == False)

''' Get the number of models in the file  ''' 
def test_GetModelCount ():
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

    count = DgnFile.GetModelCount (DgnFile.GetMasterFile ())

    assert (count == 2)

''' Get the model index for model 1 file  ''' 
def test_GetModelItemById ():
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

    modelIndexItem = DgnFile.GetModelItemById (DgnFile.GetMasterFile (), 2)

    assert (modelIndexItem != None)

    assert (2 == modelIndexItem.GetModelId ())

''' Get the model index for model named  "Close mesh to volume" in the file  ''' 
def test_GetModelItemByName ():
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

    modelIndexItem = DgnFile.GetModelItemByName (DgnFile.GetMasterFile (), "Close mesh to volume")

    assert (modelIndexItem != None)

    assert ("Close mesh to volume" == str (modelIndexItem.GetName ()))


''' Get the modelref list for the models in the file  ''' 
def test_GetModelRefList ():
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

    modelrefList = DgnFile.GetModelRefList (DgnFile.GetMasterFile ())

    for model in modelrefList:
        assert (model.GetDgnFile () == DgnFile.GetMasterFile ())

''' Create a new model in the dgn file  ''' 
def test_CreateModel ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\CreateModel.dgn")
    shutil.copyfile (str (doc.GetFileName ()), str (newFile))

    doc, status = getFileFromDirectory ('CreateModel.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret = DgnFile.CreateModel (DgnFile.GetMasterFile (), None, "New Model", "New Model Test", False, DgnModelType.eNormal, True)

    assert (ret[0] == BentleyStatus.eSUCCESS)
    assert (None != ret[1])
    assert ("New Model" == str(ret[1].GetDgnModel ().GetModelName ()))


''' Check Dgn file has export rights  ''' 
def test_CheckRights ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc, status = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    if (status != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc,"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret = DgnFile.CheckRights (DgnFile.GetMasterFile (), DgnFileRights.eDGNFILE_RIGHT_Edit, MessageDestination.eMESSAGE_DEST_None)

    assert (ret == BentleyStatus.eSUCCESS)

#if __name__ == "__main__":
#    debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
#    print("Waiting for debugger attach")
#    debugpy.wait_for_client()
#    debugpy.breakpoint()
#    test_GetMasterFile ()
#    test_FindModelIDByName ()
#    test_FindElemByID ()
#    test_HasPendingChanges ()
#    test_GetVersion ()
#    test_IsProtected ()
#    test_GetModelCount ()
#    test_GetModelItemById ()
#    test_GetModelItemByName ()
#    test_GetModelRefList ()
#    test_CreateModel ()
#    test_CheckRights ()