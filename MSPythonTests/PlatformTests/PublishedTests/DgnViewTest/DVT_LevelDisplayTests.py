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

INVALID_MODELID = -2

# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    # origin  = "E:\\MicrostationVenus5\\source\\"
    if not origin:
        return origin
    origin += fileLocation
    return origin

# fetch given file from the directory
def getFileFromDirectory(fileName, fileDir):
    ret = DgnDocument.CreateFromFileName (fileName, fileDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()
    return dgnFile

# prerequisite function to get folder location and dgn file
def setUpTest(fileName):
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    dgnFile = getFileFromDirectory(fileName, fileDir)
    assert dgnFile != None
    return dgnFile

# Test to create new level
def test_CreateLevel(initDgnPlatformHost):
    m_dgnFile = setUpTest("REFERENCE.dgn")
    assert m_dgnFile != None
    masterID = m_dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = m_dgnFile.LoadRootModelById(masterID, True, True, True)

    levelCache = m_dgnFile.GetLevelCache()

    # create null level
    levelNull = levelCache.CreateLevel ("", 0xffffffff, 0xffffffff)
    if (levelNull.IsValid ()):
        assert False
    else:
        Lcec = levelNull.GetStatus()
        assert Lcec == LevelCacheErrorCode.eLevelNameIsNull

    # create invalid level
    levelInvalid = levelCache.CreateLevel (None, 0xffffffff, 0xffffffff)
    if (levelInvalid.IsValid ()):
        assert False
    else:
        Lcec = levelInvalid.GetStatus()
        assert Lcec == LevelCacheErrorCode.eLevelNameIsNull

    # create a new level with a new name
    level = levelCache.CreateLevel ("newName", LEVEL_NULL_CODE, LEVEL_NULL_ID)
    if not level.IsValid ():
        assert LevelCacheErrorCode.eLevelNameIsDuplicate == level.GetStatus()

    level.SetByLevelWeight (5)
    Lcec =levelCache.Write ()
    assert Lcec == LevelCacheErrorCode.eNone
    statusSave = m_dgnFile.ProcessChanges(DgnSaveReason.eUserInitiated, 0)

# Test to remove existing level and a new level
def test_RemoveLevel(initDgnPlatformHost):
    m_dgnFile = setUpTest("REFERENCE.dgn")
    assert m_dgnFile != None
    masterID = m_dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = m_dgnFile.LoadRootModelById(masterID, True, True, True)

    levelCache = m_dgnFile.GetLevelCache()

    # create a new level and then remove it
    level = levelCache.CreateLevel ("newName1", LEVEL_NULL_CODE, LEVEL_NULL_ID)
    if not level.IsValid ():
        Lcec = level.GetStatus()
        assert False

    Lcec =levelCache.Write ()
    assert Lcec == LevelCacheErrorCode.eNone

    #This is no SetReadOnly method for level cache. There are sub classes from LevelCache, such as PersistentLevelCache.
    #Each of them returns their constant readonly flag by _IsReadOnly in C++ side. 
    #levelCache.SetReadOnly(True)
    Lcec4 = levelCache.RemoveLevel (None, level)
    assert Lcec4 == LevelCacheErrorCode.eNone
    #levelCache.SetReadOnly(False)

    levelCache.SetLevelReadOnly(level, True)
    Lcec5 = levelCache.RemoveLevel (None, level)
    assert Lcec5 == LevelCacheErrorCode.eCannotFindLevel
    levelCache.SetLevelReadOnly(level, False)
    
    #  remove level functionality
    Lcec3 = levelCache.RemoveLevel (None, level)
    assert Lcec3 == LevelCacheErrorCode.eCannotFindLevel

    # code to remove null level
    level_Invalid = levelCache.CreateLevel ("", 0xffffffff, 0xffffffff)
    if not level.IsValid():
        Lcec6 = levelCache.RemoveLevel (None, level)
        assert Lcec6 == LevelCacheErrorCode.eCannotFindLevel

    Lcec2 =levelCache.Write ()
    assert Lcec2 == LevelCacheErrorCode.eNone

    statusSave = m_dgnFile.ProcessChanges(DgnSaveReason.eUserInitiated, 0)

    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID1 = dgnFile.FindModelIdByName("Default")
    assert masterID1 != INVALID_MODELID
    m_defaultModel1 = dgnFile.LoadRootModelById(masterID1, True, True, True)

    levelCache2 = dgnFile.GetLevelCache ()

    # process to remove level from a new file
    level3 = levelCache2.CreateLevel ("newName", LEVEL_NULL_CODE, LEVEL_NULL_ID)
    if not level3.IsValid():
        Lcec = level3.GetStatus()
        assert False

    Ldh = levelCache2.GetLevelByName("Default")
    if Ldh.IsValid():
        Lcec7 = levelCache.RemoveLevel (None, Ldh)
        assert Lcec == LevelCacheErrorCode.eNone
    else:
        assert False

# Test to fetch level details by level name
def test_GetLevelByName(initDgnPlatformHost):
    m_dgnFile = setUpTest("REFERENCE.dgn")
    assert m_dgnFile != None
    masterID = m_dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = m_dgnFile.LoadRootModelById(masterID, True, True, True)

    levelCacheR = m_dgnFile.GetLevelCache()

    # GetLevelByName fetches level details of the passed level name
    Ldh = levelCacheR.GetLevelByName("newName")
    if not Ldh.IsValid():
        assert False

# Test to copy level from one file to another
def test_CopyLevelFromSecondFile(initDgnPlatformHost):
    m_dgnFile = setUpTest("REFERENCE.dgn")
    assert m_dgnFile != None
    masterID = m_dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = m_dgnFile.LoadRootModelById(masterID, True, True, True)

    levelCache = m_dgnFile.GetLevelCache ()

    # level from first file
    Ldh = levelCache.GetLevelByName("newName")
    if not Ldh.IsValid():
        assert False
    
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID1 = dgnFile.FindModelIdByName("Default")
    assert masterID1 != INVALID_MODELID
    m_defaultModel1 = dgnFile.LoadRootModelById(masterID1, True, True, True)

    levelCache2 = dgnFile.GetLevelCache ()

    # copying the fectched level from first file to current file
    Ldeh = levelCache2.CopyLevel(Ldh)

    if not Ldeh.IsValid():
        assert False

# Test to display ellipse (geometrical elements) in the created level
def test_IsDisplayed(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    levelCache2 = dgnFile.GetLevelCache ()

    # create new level
    level3 = levelCache2.CreateLevel ("newName1", LEVEL_NULL_CODE, LEVEL_NULL_ID)
    if not level3.IsValid ():
        Lcec = level3.GetStatus()
        assert False

    levelCache2.Write()

    # create a 3d point
    center2 = DPoint3d()
    center2.Init(0,0,0)
    ellipseEeh = EditElementHandle()

    # create an ellipse element in the created level around the created 3d point and display it
    status = EllipseHandler.CreateEllipseElement(ellipseEeh, None, center2, 5000, 3000, 0, False, m_defaultModel[0])
    if (status != BentleyStatus.eSUCCESS):
        assert False

    eProps = ElementPropertiesSetter()
    eProps.SetLevel(level3.GetLevelId())
    assert True == eProps.Apply(ellipseEeh)

    ellipseEeh.AddToModel()

    level3.SetDisplay(False)
    assert False == level3.GetDisplay()