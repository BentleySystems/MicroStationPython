#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
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

def printGlobals (context : str):
    print (context)
    for k,v in list (globals().items()):
        print(f" key {str(k)} \t {str(v)}")


class MyIgnoreAllModalEventHandler(IPyModalDialogEvents):

    ''' Callback when a modal Microstation dialog is opened ''' 
    def OnDialogOpened (self, dialogBoxName):
        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK
        
    ''' Callback when a modal Microstation dialog is closed ''' 
    def OnDialogClosed (self, dialogBoxName, result):
        pass

'''  Test we are in the Master dgn file ''' 
def test_InMasterFile():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef

    if ACTIVEMODEL == None:
        assert False

    inMasterFile = ISessionMgr.GetManager ().InMasterFile (ACTIVEMODEL)

    assert inMasterFile == True

'''  Test the current model is the active model ''' 
def test_IsActiveModel ():
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef

    if ACTIVEMODEL == None:
        assert False
    assert ISessionMgr.GetManager ().IsActiveModel (ACTIVEMODEL)
    

''' We can switch to open a new file ''' 
def test_SwitchToFile ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('Blank.dgn', fileDir)

    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyIgnoreAllModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    dgnFile = ISessionMgr.GetMasterDgnFile ()

    assert repr(doc[0].GetFileName ()) == repr(dgnFile.GetFileName ())

''' Session Monitor Class  ''' 
class MySessionMonitor(SessionMonitor):
    
    def __init__(self, fileName, oldFileName):
        super(MySessionMonitor, self).__init__()
        self.fileName = fileName
        self.oldFileName = oldFileName

    ''' Callback called after opening a dgnFile  ''' 
    def _OnMasterFileStart (self, dgnFile):
        assert 'SESSIONMGR_TEST.PY' == globals()["__mdlDescr__"]
        assert repr(self.fileName) == repr(dgnFile.GetFileName ())

    ''' Callback called before closing a dgnFile  ''' 
    def _OnMasterFileStop (self, dgnFile, changingFiles):
        assert 'SESSIONMGR_TEST.PY' == globals()["__mdlDescr__"]
        assert repr(self.oldFileName) == repr(dgnFile.GetFileName ())

    ''' Callback called before a modelref is activated  ''' 
    def _OnModelRefPreActivate (self, modelRef):
        pass

    ''' Callback called on activating a model to make it active  ''' 
    def _OnModelRefActivate (self, newModelRef, oldModelRef):
        pass

    ''' Callback called after activating a model to make it active  ''' 
    def _OnModelRefActivated (self, newModelRef, oldModelRef):
        assert 'SESSIONMGR_TEST.PY' == globals()["__mdlDescr__"]
        assert False == ISessionMgr.GetManager ().IsDesignFileInitialized ()

    def _OnReleaseWriteLock (self, dgnFileVector):
        pass

    def _OnReleasedWriteLock (self, dgnFileVector):
        pass

    def _OnWriteLocked (self, dgnFile):
        pass


''' Switch Microstation to a new dgn file  ''' 
@pytest.mark.parametrize('testFileName', ['SESSIONMGR_TEST.PY']) #ensure the process/mdl descriptor for the test is initialized and switched into
def test_SessionMonitor (initProcessDescrForTest):
    globals()["__mdlDescr__"] = 'SESSIONMGR_TEST.PY' # Pytest must be setting/clearing globals() before the test, this has to be done here with a test which needs to run with a process descriptor
#    print(f"__mdlDescr__ {globals()["__mdlDescr__"]}")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('Blank.dgn', fileDir)
    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyIgnoreAllModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    mon = MySessionMonitor (doc[0].GetFileName (), ISessionMgr.GetMasterDgnFile ().GetFileName ())

    ISessionMgr.AddSessionMonitor (mon)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False    

    ISessionMgr.DropSessionMonitor (mon)
    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
''' Test the DgnDocument associated with the masterfile  ''' 
def test_GetMaster ():
    assert repr (ISessionMgr.GetManager ().GetMaster().GetFileName ()) == repr(ISessionMgr.GetMasterDgnFile ().GetFileName ())

''' Test the ActiveDgnFile is the MasterFile  ''' 
def test_GetActiveDgnFile ():
    assert repr (ISessionMgr.GetActiveDgnFile().GetFileName ()) == repr(ISessionMgr.GetMasterDgnFile ().GetFileName ())

''' Test the ActiveModelLock methods ''' 
def test_ActiveModelLocked ():
    assert False == ISessionMgr.IsActiveModelLocked ()
    ISessionMgr.SetActiveModelLocked (True)
    assert False != ISessionMgr.IsActiveModelLocked ()
    ISessionMgr.SetActiveModelLocked (False)
    assert False == ISessionMgr.IsActiveModelLocked ()

''' Test FindDesignFile to find a dgn file on disk ''' 
def test_FindDesignFile ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('2dMetricGeneral.dgn', fileDir)    

    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False
    modalEvents = MyIgnoreAllModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)
    ret = ISessionMgr.GetManager().FindDesignFile (repr (doc[0].GetFileName ()), "", GraphicsFileType.eGRAPHICSFILE_WildCard, True)
    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False
    assert repr(doc[0].GetFileName ()) == repr(ret[0].GetFileName ())

''' Class to capture events to a Microstation modal dialog ''' 
class MyModalEventHandler(IPyModalDialogEvents):

    def __init__ (self, dir, fileName):
        super(MyModalEventHandler, self).__init__()
        self.dir = dir
        self.fileName = fileName
    ''' Callback when a modal Microstation dialog is opened ''' 
    def OnDialogOpened (self, dialogBoxName):
        if (dialogBoxName == 'New'):
            dirPathForKeyIn = "MDL COMMAND MGDSHOOK,fileList_setDirectoryCmd " + self.dir
            filePathForKeyIn = "MDL COMMAND MGDSHOOK,fileList_setFileNameCmd " + self.fileName

            PyCadInputQueue.SendKeyin (dirPathForKeyIn)
            PyCadInputQueue.SendKeyin (filePathForKeyIn)
            return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK
        elif (dialogBoxName == 'Open' ):
            filePathForKeyIn = "MDL COMMAND MGDSHOOK,fileList_setFileNameCmd " + self.fileName
            PyCadInputQueue.SendKeyin (filePathForKeyIn)
            return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK

        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultCancel
        
    ''' Callback when a modal Microstation dialog is closed ''' 
    def OnDialogClosed (delf, dialogBoxName, result):
        pass

''' Test Creating a new dgn file ''' 
def test_CreateNewFile ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")
    name = WString ('Temp.dgn')
    fullPath = emptyDir + name

    if (os.path.isfile (repr(fullPath))):
        os.remove (repr(fullPath))

    modalEvents = MyModalEventHandler (repr (emptyDir), repr(name))

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager().CreateNewDgnFile (name, repr (emptyDir), False)):
        PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
        assert False, " test_createNewFile : couldn't Create File"

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

''' Test opening a dgn file, note this doesnt open it into the editor ''' 
def test_OpenFileDialog ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('2dMetricGeneral.dgn', fileDir)    

    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler (repr (fileDir), repr(doc[0].GetFileName ()))

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    ret = ISessionMgr.GetManager().OpenDgnFileDialog ()

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)
        assert False, " test_openFileDialog : couldn't Open File"

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

''' Test getting the list of writable files ''' 
def test_GetWriteableFiles ():
    files = ISessionMgr.GetManager().GetWriteableFiles ()

    assert len(files) == 1

    assert repr(files[0].GetFileName ()) == repr(ISessionMgr.GetMasterDgnFile ().GetFileName ()) 


    
if __name__ == "__main__":
#    debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
#    print("Waiting for debugger attach")
#    debugpy.wait_for_client()
#    debugpy.breakpoint()    
#    test_InMasterFile ()
#    test_IsActiveModel()
#    test_SwitchToFile()
#    print (f"test_SessionMonitor __mdlDescr__ {globals()["__mdlDescr__"]}")
#    test_SessionMonitor()
#    test_GetMaster()
#    test_GetActiveDgnFile()
#    test_ActiveModelLocked()
#    test_FindDesignFile()
#    test_CreateNewFile()
#    test_OpenFileDialog()
#    test_GetWriteableFiles()