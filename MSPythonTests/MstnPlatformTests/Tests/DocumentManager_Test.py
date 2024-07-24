#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import time
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import pywin.debugger


# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    if not origin:
        return origin
    origin += fileLocation
    return origin


class MyModalEventHandler(IPyModalDialogEvents):

    ''' Callback when a modal Microstation dialog is opened ''' 
    def OnDialogOpened (self, dialogBoxName):
        print (dialogBoxName)
        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK
        
    ''' Callback when a modal Microstation dialog is closed ''' 
    def OnDialogClosed (delf, dialogBoxName, result):
        pass

def test_MSDocumentOpenDialogParams():

    params = PyDocumentOpenDialogParams.Create ()

    params.SetRscFileHandle (33)
    assert 33 == params.GetRscFileHandle()

    params.SetDialogId (44)
    assert 44 == params.GetDialogId ()

    params.SetOpenCreate (FileListAttr.eDEFAULT)   
    assert FileListAttr.eDEFAULT == params.GetOpenCreate ()  

    params.SetSuggestedFileName (WString ('TestFileName.dgn'))
    assert WString ('TestFileName.dgn') == params.GetSuggestedFileName ()

    params.SetDefaultFilter (WString ('*.dgn'))
    assert WString ('*.dgn') == params.GetDefaultFilter ()

    params.SetFilterInfoString (WString ('*.pdf,Portable Document Format Files[*.pdf]'))    
    assert WString ('*.pdf,Portable Document Format Files[*.pdf]') == params.GetFilterInfoString ()

    params.SetDefaultDir(WString ('c:/temp/'))    
    assert WString ('c:/temp/') == params.GetDefaultDir ()

    params.SetDirCfgVar (WString ('MS_REFDIR'))
    assert WString ('MS_REFDIR') == params.GetDirCfgVar()

    params.SetDialogTitle(WString ('My Dialog Title'))
    assert WString ('My Dialog Title') == params.GetDialogTitle ()    

    params.SetDefFileId (DefFileId.eDEFDGNFILE_ID)   
    assert DefFileId.eDEFDGNFILE_ID.value == params.GetDefFileId ()

    params.SetDefRscFileHandle (55)   
    assert 55 == params.GetDefRscFileHandle ()

    params.SetDefSeedFileName (WString ('MySeedFile.dgn'))    
    assert WString ('MySeedFile.dgn') == params.GetDefSeedFileName ()    

    params.SetDefSeedDir(WString ('c:/temp'))
    assert WString ('c:/temp') == params.GetDefSeedDir()    

    params.SetDefSeedFilter(WString ('*.dgnlib')) 
    assert WString ('*.dgnlib') == params.GetDefSeedFilter ()    

    params.SetDefSeedFileId(66) 
    assert 66 == params.GetDefSeedFileId()     

    params.SetRequiredRights(DgnFileRights.eDGNFILE_RIGHT_Any) 
    assert DgnFileRights.eDGNFILE_RIGHT_Any == params.GetRequiredRights ()    

    params.SetFilterStringListId(77) 
    assert 77 == params.GetFilterStringListId ()    

    params.SetFilterRscFileHandle(88) 
    assert 88 == params.GetFilterRscFileHandle  ()   

    params.SetPreIncludeCADFileOpenFilters(False) 
    assert False == params.GetPreIncludeCADFileOpenFilters ()    

    params.SetPostIncludeCADFileOpenFilters(False) 
    assert False == params.GetPostIncludeCADFileOpenFilters()     

    params.SetWorkSetName(WString ('My Workset')) 
    assert WString ('My Workset') == params.GetWorkSetName  ()   

    params.SetWorkSpaceName(WString ('My Workspace')) 
    assert WString ('My Workspace') == params.GetWorkSpaceName()     




def test_OpenDocumentDialog ():
    params = PyDocumentOpenDialogParams.Create ()
    params.SetDefaultFilter (WString ('*.dgn'))
    params.SetSuggestedFileName (WString ('Blank.dgn'))
    params.SetDialogId (DialogIds.eDIALOGID_StdFileOpen)
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)

    params.SetDefaultDir(WString (fileDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    ret = MSDocumentManager.GetManager ().OpenDocumentDialog (params, FileOpenExtAttr.eNONE, DgnDocument.FetchMode.eRead)

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False


def test_CreateNewDocumentDialog ():
    params = PyDocumentOpenDialogParams.Create ()
    params.SetOpenCreate (FileListAttr.eDEFAULT) 
    params.SetDefaultFilter (WString ('*.dgn'))
    params.SetSuggestedFileName (WString ('Temp.dgn'))
    params.SetDialogId (DialogIds.eDIALOGID_StdFileOpen)

    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    params.SetDefaultDir (emptyDir)

    name = WString ('Temp.dgn')
    fullPath = emptyDir + name

    if (os.path.isfile (repr(fullPath))):
        os.remove (repr(fullPath))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    ret = MSDocumentManager.GetManager ().CreateNewDocumentDialog (params, DgnDocument.OverwriteMode.eAlways)

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False



#
# OpenFolderDialog doesnt support dialog events
#
#def test_OpenFolderDialog():
#    params = PyDocumentOpenDialogParams.Create ()
#    params.SetOpenCreate (FileListAttr.DEFAULT) 
#    params.SetDefaultFilter (WString ('*.dgn'))
#    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
#    fileDir = getRoot(fileLocation)
#    params.SetDefaultDir (WString (fileDir))
#    modalEvents = MyModalEventHandler ()
#    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)
#    ret = MSDocumentManager.GetManager ().OpenFolderDialog(params, FileOpenExtAttr.NONE, repr (fileDir),  DgnDocument.FetchMode.Read)
#    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)


#if __name__ == "__main__":
    #test_MSDocumentOpenDialogParams()
    #test_OpenDocumentDialog ()
    #test_CreateNewDocumentDialog ()
    #test_OpenFolderDialog()
      

