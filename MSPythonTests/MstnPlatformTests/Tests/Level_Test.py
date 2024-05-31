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

''' Test the number of levels in the file      '''
def test_GetLevelCount ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret = LevelTable.GetLevelCount (ISessionMgr.ActiveDgnModelRef,LevelCountType.eLEVEL_COUNT_TYPE_ALL)
    assert (BentleyStatus.eSUCCESS == ret[0])
    assert (ret[1]== 7)
    ret = LevelTable.GetLevelCount (ISessionMgr.ActiveDgnModelRef,LevelCountType.eLEVEL_COUNT_TYPE_USED)
    assert (BentleyStatus.eSUCCESS == ret[0])
    assert (ret[1]== 2)
    ret = LevelTable.GetLevelCount (ISessionMgr.ActiveDgnModelRef,LevelCountType.eLEVEL_COUNT_TYPE_UNUSED)
    assert (BentleyStatus.eSUCCESS == ret[0])
    assert (ret[1]== 0)


''' Test a series of methods on a level   '''
def test_OneLevel ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\OneLevel.dgn")
    shutil.copyfile (str (doc[0].GetFileName ()), str (newFile))

    doc = getFileFromDirectory ('OneLevel.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)


    ret = Level.Create (ISessionMgr.ActiveDgnModelRef, "new-level1", 51)

    assert (ret[0] == BentleyStatus.eSUCCESS)
    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    ret1 = Level.Create (ISessionMgr.ActiveDgnModelRef, "new-level1", 52)

    assert (ret1[0] != BentleyStatus.eSUCCESS) # dont allow duplicate names

    if (ret[1] != LEVEL_NULL_ID) :
        ret2 = Level.GetName(ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret2[0] == BentleyStatus.eSUCCESS)
        assert (str (ret2[1]) == "new-level1")

        # Set Description on "new-level1" 
        ret3 = Level.SetDescription(ISessionMgr.ActiveDgnModelRef, ret[1], "This is a test level - new-level1")
        assert (ret3 == BentleyStatus.eSUCCESS)

        ret4 = Level.GetDescription( ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret4[0] == BentleyStatus.eSUCCESS)
        assert (str (ret4[1]) == "This is a test level - new-level1")

        # Set Symbology on "new-level1"
        setColor = 10
        setWeight = 2
        setStyle = 3
        setColorOverride = True
        setStyleOverride = True 
        setWeightOverride = True 
        setElementColor = 15
        setElementWeight = 4
        setElementFillColor = 15
        setElementStyle = 5
        params = LineStyleParams ()
        params.Init ()

        assert (BentleyStatus.eSUCCESS == Level.SetColor (ISessionMgr.ActiveDgnModelRef, ret[1], setColor, setColorOverride))
        assert (BentleyStatus.eSUCCESS == Level.SetStyle (ISessionMgr.ActiveDgnModelRef, ret[1], setStyle, params, setStyleOverride))
        assert (BentleyStatus.eSUCCESS == Level.SetWeight (ISessionMgr.ActiveDgnModelRef, ret[1], setWeight, setWeightOverride))

        assert (BentleyStatus.eSUCCESS == Level.SetElementSymbology (ISessionMgr.ActiveDgnModelRef, ret[1], setElementColor, setElementStyle, params, setElementWeight))

        ret5 = Level.GetSymbology (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret5[0] == BentleyStatus.eSUCCESS)
        assert (ret5[1] == setColor)
        assert (ret5[2] == setColorOverride)
        assert (ret5[3] == setStyle)
        assert (ret5[5] == setStyleOverride)
        assert (ret5[6] == setWeight)
        assert (ret5[7] == setWeightOverride)

        ret6 = Level.GetElementSymbology (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret6[0] == BentleyStatus.eSUCCESS)
        assert (ret6[1] == setElementColor)
        assert (ret6[2] == setElementStyle)
        assert (ret6[4] == setElementWeight)

        assert (BentleyStatus.eSUCCESS == Level.SetElementColor (ISessionMgr.ActiveDgnModelRef, ret[1], setColor))
        ret7 = Level.GetElementColor (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret7[0] == BentleyStatus.eSUCCESS)
        assert (ret7[1] == setColor)

        assert (BentleyStatus.eSUCCESS == Level.SetElementStyle (ISessionMgr.ActiveDgnModelRef, ret[1], setStyle, params))
        ret8 = Level.GetElementStyle (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret8[0] == BentleyStatus.eSUCCESS)
        assert (ret8[1] == setStyle)

        assert (BentleyStatus.eSUCCESS == Level.SetElementWeight (ISessionMgr.ActiveDgnModelRef, ret[1], setWeight))
        ret9 = Level.GetElementWeight (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret9[0] == BentleyStatus.eSUCCESS)
        assert (ret9[1] == setWeight)

        assert (BentleyStatus.eSUCCESS == Level.SetDisplay (ISessionMgr.ActiveDgnModelRef, ret[1], True))
        ret10 = Level.GetDisplay (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret10[0] == BentleyStatus.eSUCCESS)
        assert (ret10[1] == True)

        assert (BentleyStatus.eSUCCESS == Level.SetFrozen (ISessionMgr.ActiveDgnModelRef, ret[1], LevelFrozenType.eLEVEL_FROZEN_TYPE_GLOBAL, True))
        ret11 = Level.GetFrozen (ISessionMgr.ActiveDgnModelRef, ret[1], LevelFrozenType.eLEVEL_FROZEN_TYPE_GLOBAL)
        assert (ret11[0] == BentleyStatus.eSUCCESS)
        assert (ret11[1] == True)

        assert (BentleyStatus.eSUCCESS == Level.SetPlot (ISessionMgr.ActiveDgnModelRef, ret[1], True))
        ret12 = Level.GetPlot (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret12[0] == BentleyStatus.eSUCCESS)
        assert (ret12[1] == True)

        assert (BentleyStatus.eSUCCESS == Level.SetHidden (ISessionMgr.ActiveDgnModelRef, ret[1], True))
        ret13 = Level.GetHidden (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret13[0] == BentleyStatus.eSUCCESS)
        assert (ret13[1] == True)

        assert (BentleyStatus.eSUCCESS == Level.SetDisplayPriority (ISessionMgr.ActiveDgnModelRef, ret[1], 55))
        ret14 = Level.GetDisplayPriority (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret14[0] == BentleyStatus.eSUCCESS)
        assert (ret14[1] == 55)

        assert (BentleyStatus.eSUCCESS == Level.SetTransparency (ISessionMgr.ActiveDgnModelRef, ret[1], 0.5))
        ret15 = Level.GetTransparency (ISessionMgr.ActiveDgnModelRef, ret[1])
        assert (ret15[0] == BentleyStatus.eSUCCESS)
        assert (ret15[1] == 0.5)

        assert (BentleyStatus.eSUCCESS == Level.SetActive ( ret[1]))

    ret16 = Level.Create (ISessionMgr.ActiveDgnModelRef, "new-level2", 31)
    assert (ret16[0] == BentleyStatus.eSUCCESS)
    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    assert (BentleyStatus.eSUCCESS != Level.SetName (ISessionMgr.ActiveDgnModelRef, ret16[1], "new-level1"))

    ret17 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "new-level2")
    assert (ret17[0] == BentleyStatus.eSUCCESS)
    assert (ret17[1] == ret16[1])

    assert (BentleyStatus.eSUCCESS == Level.Delete (ISessionMgr.ActiveDgnModelRef, ret16[1]))
    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    ret18 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "new-level2")
    assert (ret18[0] != BentleyStatus.eSUCCESS)

''' Test copying a level      '''
def test_CopyLevel ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('3dMetricGeneral.dgn', fileDir)

    newFile = emptyDir + WString ("\\CopyLevel.dgn")
    shutil.copyfile (str (doc[0].GetFileName ()), str (newFile))

    doc = getFileFromDirectory ('CopyLevel.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)


    ret = Level.Create (ISessionMgr.ActiveDgnModelRef, "new-level1", 51)
    assert (ret[0] == BentleyStatus.eSUCCESS)

    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    ret1 = LevelTable.GetLevelCount (ISessionMgr.ActiveDgnModelRef, LevelCountType.eLEVEL_COUNT_TYPE_ALL)
    assert (ret1[0] == BentleyStatus.eSUCCESS)

    ret2 = Level.CopyLevel (ISessionMgr.ActiveDgnModelRef, ISessionMgr.ActiveDgnModelRef, ret[1], "new-level3", False)
    assert (ret2[0] == BentleyStatus.eSUCCESS)   
    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    ret3 = LevelTable.GetLevelCount (ISessionMgr.ActiveDgnModelRef, LevelCountType.eLEVEL_COUNT_TYPE_ALL)
    assert (ret3[0] == BentleyStatus.eSUCCESS)

    assert ((ret1[1]+1) == ret3[1])


''' Test selecting all the elements on a level      '''
def test_SelectLevel ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "Elements")

    SelectionSetManager.GetManager().EmptyAll ()
    emptyCount = SelectionSetManager.GetManager().NumSelected ()
    assert (emptyCount == 0)

    ret2 = Level.SelectElement (ISessionMgr.ActiveDgnModelRef, ret1[1])
    assert (ret2[0] == BentleyStatus.eSUCCESS)
    count = SelectionSetManager.GetManager().NumSelected ()
    assert (ret2[1] == count)

''' Test drawing a level in the Microstation Views      '''
def test_DrawLevel ():
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    if (doc[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "Elements")
    assert (ret1[0] == BentleyStatus.eSUCCESS)

    views = [True, False, False, False, False, False, False, False]
    assert (BentleyStatus.eSUCCESS == Level.Draw (views, True, DgnDrawMode.eDRAW_MODE_Normal, ISessionMgr.ActiveDgnModelRef, ret1[1], False, False))


''' Test deleting all the elements on a level    '''
def test_DeleteElement ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    newFile = emptyDir + WString ("\\DeleteElement.dgn")
    shutil.copyfile (str (doc[0].GetFileName ()), str (newFile))

    doc = getFileFromDirectory ('DeleteElement.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "Elements")
    assert (ret1[0] == BentleyStatus.eSUCCESS)
    ret2 = Level.GetElementCount (ISessionMgr.ActiveDgnModelRef, ret1[1])
    assert (ret2[0] == BentleyStatus.eSUCCESS)
    assert (ret2[1] == 1)

    ret3 = Level.DeleteElement (ISessionMgr.ActiveDgnModelRef, ret1[1], False, True)
    assert (ret3[0] == BentleyStatus.eSUCCESS)
    assert (ret3[1] == 1)


''' Test moving elements from one level to another   '''
def test_MoveElementLevel ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    newFile = emptyDir + WString ("\\MoveElementLevel.dgn")
    shutil.copyfile (str (doc[0].GetFileName ()), str (newFile))

    doc = getFileFromDirectory ('MoveElementLevel.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)

    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "Elements")
    assert (ret1[0] == BentleyStatus.eSUCCESS)
    ret2 = Level.GetElementCount (ISessionMgr.ActiveDgnModelRef, ret1[1])
    assert (ret2[0] == BentleyStatus.eSUCCESS)
    assert (ret2[1] == 1)

    ret3 = Level.Create (ISessionMgr.ActiveDgnModelRef, "new-level1", 51)

    assert (ret3[0] == BentleyStatus.eSUCCESS)
    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    ret4 = Level.MoveElementLevel (ret3[1], ISessionMgr.ActiveDgnModelRef, ret1[1], False)
    assert (ret4[0] == BentleyStatus.eSUCCESS)
    assert (ret4[1] == 1)


''' Test copying elements from one level to another   '''
def test_CopyElement ():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")

    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    doc = getFileFromDirectory ('TerrainVolumeWithHoles.dgn', fileDir)

    newFile = emptyDir + WString ("\\CopyElement.dgn")
    shutil.copyfile (str (doc[0].GetFileName ()), str (newFile))

    doc = getFileFromDirectory ('CopyElement.dgn', str (emptyDir))

    modalEvents = MyModalEventHandler ()

    PyEventsHandler.AddModalDialogEventsHandler (modalEvents)

    if (BentleyStatus.eSUCCESS != ISessionMgr.GetManager ().SwitchToNewFile (doc[0],"", GraphicsFileType.eGRAPHICSFILE_WildCard, True, True)):
        assert False   

    PyEventsHandler.RemoveModalDialogEventsHandler (modalEvents)


    ret1 = Level.GetIdFromName (ISessionMgr.ActiveDgnModelRef, 0, "Elements")
    assert (ret1[0] == BentleyStatus.eSUCCESS)
    ret2 = Level.GetElementCount (ISessionMgr.ActiveDgnModelRef, ret1[1])
    assert (ret2[0] == BentleyStatus.eSUCCESS)
    assert (ret2[1] == 1)

    ret3 = Level.Create (ISessionMgr.ActiveDgnModelRef, "new-level1", 51)

    assert (ret3[0] == BentleyStatus.eSUCCESS)
    LevelTable.Rewrite (ISessionMgr.ActiveDgnModelRef)

    ret4 = Level.CopyElement (ISessionMgr.ActiveDgnModelRef, ret3[1], ISessionMgr.ActiveDgnModelRef, ret1[1], False)
    assert (ret4[0] == BentleyStatus.eSUCCESS)
    assert (ret4[1] == 1)



#if __name__ == "__main__":
#    debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
#    print("Waiting for debugger attach")
#    debugpy.wait_for_client()
#    debugpy.breakpoint()
#    test_GetLevelCount ()
#    test_OneLevel ()
#    test_CopyLevel ()
#    test_SelectLevel ()
#    test_DrawLevel ()
#    test_DeleteElement ()
#    test_MoveElementLevel ()
#    test_CopyElement ()