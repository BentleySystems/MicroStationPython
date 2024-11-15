#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
# Half done
import os
import pytest
import tempfile
import sys
import shutil

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

SEED_FILE_NAME = '2dMetricGeneral.dgn'
TEMP_FILE_NAME = "LevelCache_Test.dgn"
TEMP_FILE2_NAME = "LevelCache_Test2.dgn"

MAX_LINKAGE_STRING_LENGTH = 512

def EndTest():
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")         
    
    BeFileName.BeDeleteFile(str(emptyDir)+TEMP_FILE_NAME)
    BeFileName.BeDeleteFile(str(emptyDir)+TEMP_FILE2_NAME)

def OpenTempFile(dgnFile, mode = DgnFileOpenMode.eReadWrite):
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")         
    
    m_file = OpenFile0(str(emptyDir)+TEMP_FILE_NAME, mode, dgnFile)
    return m_file

def SaveFile(dgnFile):
    assert dgnFile.HasPendingChanges()
    dgnFile.SetFullSaveFlag ()
    assert dgnFile.ProcessChanges(DgnSaveReason.eApplInitiated) == BentleyStatus.eSUCCESS
    return dgnFile

def OpenFile0(seedfilePath, mode, seeddgnfile):
    if seeddgnfile != None:
        return seeddgnfile
    
    seedfile = DgnFile(DgnDocument.CreateForLocalFile(str(seedfilePath)), mode)
    print(seedfilePath)
    assert BentleyStatus.eSUCCESS == seedfile.LoadDgnFile()[0]
    seedfile.FillDictionaryModel()
    return seedfile

def OpenSeedFile(dgnFile):
    dataDir = os.environ['MSPYTESTDATA']
    seedDgnfile = OpenFile0(repr(dataDir+SEED_FILE_NAME), DgnFileOpenMode.eReadOnly, dgnFile)
    return seedDgnfile


def CreateTempFile(dgnFile):
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")       
    tempFileName = next(tempfile._get_candidate_names()) + ".dgn"
    fileSpec = str (emptyDir) + str (tempFileName)
    BeFileName.BeDeleteFile (fileSpec)
    shutil.copy(str (dgnFile.GetFileName ()),fileSpec)
    ret = DgnDocument.CreateFromFileName (fileSpec, "", -101, DgnDocument.FetchMode.eWrite)
    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False
    newFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    newFile.LoadDgnFile ()
    newFile.FillDictionaryModel ()
    return newFile

###############################################################################
# START : ADDED TEST TO ADD PERSISTENT LEVEL
###############################################################################

def AddPersistentLevel(SaveTheChange, m_file, newLevelName):    
    tempFile0 = CreateTempFile(m_file)
    levelCache1 = tempFile0.GetLevelCache()
    
    assert levelCache1.CreateLevel(newLevelName, LEVEL_NULL_CODE, LEVEL_NULL_ID).IsValid()
    
    assert levelCache1.IsDirty()
    
    if(SaveTheChange):
        assert levelCache1.Write() == LevelCacheErrorCode(0)
        tempFile1 = SaveFile(tempFile0)
        
    tempFile2 = OpenTempFile(tempFile0)
    
    levelCache2 = tempFile2.GetLevelCache()
    
    newLevelFound = levelCache2.GetLevelByName(newLevelName)
    assert newLevelFound.IsValid() == SaveTheChange
    assert (not newLevelFound.IsValid()) or newLevelFound == levelCache2.GetLevelByCode(newLevelFound.GetLevelCode())
    
    EndTest()
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddPersistentLevelT(initDgnPlatformHost, loadDgnFile):
    AddPersistentLevel(True, loadDgnFile, "LevelCache_AddPersistentLevel")
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddPersistentLevelF(initDgnPlatformHost, loadDgnFile):
    AddPersistentLevel(True, loadDgnFile, "LevelCache_AddPersistentLevel")
    
###############################################################################
# END : ADDED TEST TO ADD PERSISTENT LEVEL
###############################################################################

def test_D_60051():
    wLevelName2 = WString("Th?s ?s a val?d name")
    LevelUtils.ReplaceInvalidCharacters(wLevelName2, 'i')
    assert True == (repr(wLevelName2) == "This is a valid name")

@pytest.mark.skip(reason="Ping.Chen, error in bb r platformtests")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_SetLineStyle(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    it = iter(dgnFile.GetLineStyleMap())
    nextNum = next(it)
    lsNum = nextNum.GetStyleNumber()
    
    lsDef = dgnFile.GetLineStyleMap().GetLineStyleEntry(lsNum)
    assert lsDef != None
    id = lsDef.GetId(dgnFile.GetDictionaryModel())

    level = EditLevelHandle(dgnFile.GetLevelCache().GetLevelByName ("Default"))
    assert level.SetOverrideLineStyle (lsDef, None, dgnFile)
    assert level.GetOverrideLineStyle ().GetStyle () == lsNum
    assert level.GetOverrideLineStyle ().GetStyleParams() == None

    assert level.SetByLevelLineStyle (lsDef, None, dgnFile)
    assert level.GetByLevelLineStyle ().GetStyle () == lsNum
    assert level.GetByLevelLineStyle ().GetStyleParams() == None
    assert id != INVALID_ELEMENTID
    
   
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_NoModReadOnlyLevel(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    levels = dgnFile.GetLevelCache()
    
    level = EditLevelHandle(levels.GetLevelByName("Default"))
    assert level.IsValid()
    levels.SetLevelReadOnly(level, True)
    assert level.GetReadOnly()
    
    newDesc = "NoModReadOnlyLevel"
    level.SetDescription("NoModReadOnlyLevel")
    assert 0 != (level.GetDescription() == newDesc)

@pytest.mark.skip(reason="Ignore: Find out if it's really true that levels must have names")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_NoNullName(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    levels = dgnFile.GetLevelCache()
    
    level = EditLevelHandle(levels.CreateLevel (None, LEVEL_NULL_CODE, LEVEL_NULL_ID))
    assert levels.Write() == LevelCacheErrorCode(0)
    assert not level.IsValid()
    assert level.GetStatus() == LevelCacheErrorCode.eLevelNameIsNull
    assert None != level.GetName()  # DgnPlatform is broken and this test show it


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetDefaultLevelByCode(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    levelCache = dgnFile.GetLevelCache()
    
    level = levelCache.GetLevelByName("Default")
    assert level.IsValid()   
    
    levelCode = level.GetLevelCode()
    level2 = levelCache.GetLevelByCode(levelCode)
    assert level2.IsValid()
    assert level2.GetLevelCode() == levelCode
    assert level2.GetLevelCode() == level.GetLevelCode()
    assert level2.EqualLevelData(None, level, None)
    assert level2 == level

###############################################################################
# ADDED TEST TO CHECK ONLY DEFAULT LEVEL
###############################################################################

@pytest.mark.parametrize('fileName', [SEED_FILE_NAME])
def test_CheckOnlyDefaultLevel(initDgnPlatformHost, loadDgnFileReadOnly):
    levelCache = loadDgnFileReadOnly.GetLevelCache()
    assert not levelCache.IsDirty()
    assert levelCache.GetLevelCount() == 1
    
    level = levelCache.GetLevel(LEVEL_DEFAULT_LEVEL_ID)
    
    assert level.IsValid()
    assert level.GetLevelId() == LEVEL_DEFAULT_LEVEL_ID
    assert None != level.GetName()
    assert 0 == (repr(level.GetName()) == "Default")
    assert level == levelCache.GetLevelByName("Default")
    assert level == levelCache.GetLevelByCode(level.GetLevelCode())
    levelCacheIter = iter(levelCache)
    assert next(levelCacheIter) == level
    

##########################################################################
# ADDED TEST TO ADD LEVEL BY NAME
##########################################################################
    
def AddLevelByName(newLevelName, m_file):
    m_file = CreateTempFile (m_file)

    
    m_file.SetAbandonChangesFlag()
    
    levelCache = m_file.GetLevelCache()
    
    assert not levelCache.IsDirty()
    assert levelCache.GetLevelCount() == 1
    
    existingLevel = levelCache.GetLevelByName(newLevelName)
    assert not existingLevel.IsValid()
    
    newLevel = levelCache.CreateLevel(newLevelName, LEVEL_NULL_CODE, LEVEL_NULL_ID)
    
    assert newLevel.IsValid()
    assert levelCache.GetLevelCount() == 2
    assert 0 == (newLevel.GetName() == repr(newLevelName))
    # Error: name 'BackDoor' is not defined, BackDoor is not exposed
    # assert LEVEL_DICT_NULL_ID != BackDoor.LevelHandle.GetNameId(newLevel)
    
    newLevelFound = levelCache.GetLevelByName(newLevelName)
    assert newLevelFound.IsValid()
    assert newLevelFound == newLevel
    
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddLevelByName1(initDgnPlatformHost, loadDgnFile):
    m_file = loadDgnFile
    AddLevelByName("L", m_file)
    

@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddLevelByName2(initDgnPlatformHost, loadDgnFile):
    m_file = loadDgnFile
    AddLevelByName("VeryLongVeryLongVeryLongVeryLongVeryLongVeryLongVeryLongVeryLong", m_file)
    
##############################################################################
# ADDED TEST TO CHECK WE CANNOT ADD LEVEL BY INVALIDCODE
##############################################################################
def CannotAddLevelByInvalidCode(m_file):
    m_file = CreateTempFile (m_file)
    
    m_file.SetAbandonChangesFlag()
    
    levelCache = m_file.GetLevelCache()
    
    assert not levelCache.IsDirty()
    assert levelCache.GetLevelCount() == 1
    
    invalidCodes = [0]
    for c in invalidCodes:
        assert not levelCache.CreateLevel(None, c, LEVEL_NULL_ID).IsValid ()
        assert levelCache.GetLevelCount() == 1
        
        
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_CannotAddLevelByInvalidCode(initDgnPlatformHost, loadDgnFile):
    m_file = loadDgnFile
    CannotAddLevelByInvalidCode(m_file)
    
###############################################################################
# ADDED TESTS TO ADD LEVEL BY CODE
###############################################################################
def AddLevelByCode(newLevelCode, m_file):
    tempfile = CreateTempFile (m_file)
    
    tempfile.SetAbandonChangesFlag()
    
    levelCache = tempfile.GetLevelCache()
    
    assert not levelCache.IsDirty()
    assert levelCache.GetLevelCount() == 1
    
    existingLevel = levelCache.GetLevelByCode(newLevelCode)
    assert not existingLevel.IsValid()
    
    levelName = "new" + str(newLevelCode)
    # swprintf (levelName, "new (%d)", newLevelCode)
    
    newLevel = levelCache.CreateLevel(levelName, newLevelCode, LEVEL_NULL_ID)
    assert newLevel.IsValid()
    assert levelCache.GetLevelCount() == 2
    assert newLevelCode == newLevel.GetLevelCode()
    
    newLevelFound = levelCache.GetLevelByCode(newLevelCode)
    assert newLevelFound.IsValid()
    assert newLevelFound == newLevel
    EndTest()
    
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddLevelByCode1(removeTempCreatedFile, initDgnPlatformHost, loadDgnFile):
    AddLevelByCode(1, loadDgnFile)
    dataDir = os.environ['MSPYTESTDATA']
    removeTempCreatedFile('test_AddLevelByCode0', WString(dataDir+TEMP_FILE_NAME))
    removeTempCreatedFile('test_AddLevelByCode1', WString(dataDir+TEMP_FILE2_NAME))
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddLevelByCode100(initDgnPlatformHost, loadDgnFile):
    AddLevelByCode(100, loadDgnFile)
    EndTest()
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddLevelByCode1000(initDgnPlatformHost, loadDgnFile):
    AddLevelByCode(1000, loadDgnFile)
    EndTest()
    
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_AddLevelByCode1000000(initDgnPlatformHost, loadDgnFile):
    AddLevelByCode(1000000, loadDgnFile)
    EndTest()
    
###############################################################################
# ADDED TESTS TO TEST WE CANNOT ADD LEVEL BY INVALID NAME
###############################################################################
@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_CannotAddLevelByInvalidName(initDgnPlatformHost, loadDgnFile):
    m_file = loadDgnFile 

    m_file = CreateTempFile (m_file)
    
    m_file.SetAbandonChangesFlag()
    
    levelCache = m_file.GetLevelCache()
    
    empty = WString.GetWCharCP(WString(""))
    
    invalidchars = WString.GetWCharCP(WString("?"))
    
    tooLong = '1' * ( MAX_LINKAGE_STRING_LENGTH + 2 )
    
    tooLong= tooLong[:len(tooLong)-1] + '0'
    
    assert not levelCache.CreateLevel(empty, LEVEL_NULL_CODE, LEVEL_NULL_ID).IsValid()
    assert not levelCache.CreateLevel(invalidchars, LEVEL_NULL_CODE, LEVEL_NULL_ID).IsValid()
    assert not levelCache.CreateLevel(tooLong, LEVEL_NULL_CODE, LEVEL_NULL_ID).IsValid()
    
###############################################################################
# ADDED TEST TO SET LEVEL DEFINITION PROPERTIES FOR FALSE CONDITION
###############################################################################    
def SetLevelDefinitionProperties(saveTheChanges, m_file, newLevelname):
    newWeight = 2
   
    tempFile = CreateTempFile (m_file)
    levelCache1 = tempFile.GetLevelCache()
    assert levelCache1.CreateLevel(newLevelname, LEVEL_NULL_CODE, LEVEL_NULL_ID).IsValid() 
    assert levelCache1.Write() == LevelCacheErrorCode(0)
    tempFile1 = SaveFile(tempFile)
    
    tempFile2 = OpenTempFile(tempFile1)
    levelCache2 = tempFile2.GetLevelCache()
    
    level = EditLevelHandle(levelCache2.GetLevelByName(newLevelname))
    assert level.IsValid()
    assert not level.IsDirty()
    assert not levelCache2.IsDirty()
    
    originalDefaultWeight = levelCache2.GetLevel(LEVEL_DEFAULT_LEVEL_ID).GetByLevelWeight()
    
    originalWeight = level.GetByLevelWeight()
    level.SetByLevelWeight(newWeight)
    
    assert level.IsDirty()
    assert levelCache2.IsDirty()
    
    if(saveTheChanges):
        assert levelCache2.Write() == LevelCacheErrorCode(0)
        tempFile3 = SaveFile(tempFile2)
        
    tempFile4 = OpenTempFile(tempFile2)
    levelCache3 = tempFile4.GetLevelCache()
    
    newLevelFound = levelCache3.GetLevelByName(newLevelname)
    assert newLevelFound.IsValid()
    
    if saveTheChanges:
        assert newLevelFound.GetByLevelWeight() == newWeight
    else:
        assert newLevelFound.GetByLevelWeight() == originalWeight
        
    assert originalDefaultWeight == levelCache3.GetLevel(LEVEL_DEFAULT_LEVEL_ID).GetByLevelWeight()
    
    EndTest()

@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_SetLevelDefinitionPropertiesT(initDgnPlatformHost, loadDgnFile):
    SetLevelDefinitionProperties(True, loadDgnFile, "LevelCache_AddPersistentLevel0")
    
###############################################################################
# ADDED TEST TO DELETE LEVEL
###############################################################################   
    
def DeleteOtherLevel(saveTheChange, m_file, newLevelname):
    tempDgnFile = CreateTempFile (m_file)
    levelCache1 = tempDgnFile.GetLevelCache()
    
    assert levelCache1.GetLevelCount() == 1
    assert levelCache1.CreateLevel(newLevelname, LEVEL_NULL_CODE, LEVEL_NULL_ID).IsValid()
    assert levelCache1.GetLevelCount() == 2
    
    assert levelCache1.Write() == LevelCacheErrorCode(0)
    tempDgnFile0 = SaveFile(tempDgnFile)
    
    tempDgnFile1 = OpenTempFile(tempDgnFile)
    levelCache2 = tempDgnFile1.GetLevelCache()
    
    assert levelCache2.GetLevelCount() == 2
    
    newLevelFound = levelCache2.GetLevelByName(newLevelname)
    
    assert newLevelFound.IsValid()
    assert levelCache2.GetLevelByName("Default").IsValid()
    
    assert levelCache2.RemoveLevel(None, newLevelFound) == LevelCacheErrorCode(0)
    
    assert not newLevelFound.IsValid()
    assert levelCache2.GetLevelCount() == 1
    assert levelCache2.GetLevelByName("Default").IsValid()
    assert not levelCache2.GetLevelByName(newLevelname).IsValid()
    
    if saveTheChange:
        assert levelCache2.Write() == LevelCacheErrorCode(0)
        tempDgnFile2 = SaveFile(tempDgnFile1)
    
    tempDgnFile3 = OpenTempFile(m_file)
    levelCache3 = tempDgnFile3.GetLevelCache()
    
    if saveTheChange:
        assert levelCache3.GetLevelCount() == 1
    else:
        assert levelCache3.GetLevelCount() == 2
        
    if saveTheChange:
        assert levelCache3.GetLevelByName(newLevelname).IsValid() == False
    else:
        assert levelCache3.GetLevelByName(newLevelname).IsValid() == True
        
    assert levelCache3.GetLevelByName("Default").IsValid()
    EndTest()        

@pytest.mark.parametrize('fileName',['2dMetricGeneral.dgn']) 
def test_DeleteOtherLevelT(initDgnPlatformHost, loadDgnFile):
    DeleteOtherLevel(True, loadDgnFile, "LevelCache_AddPersistentLevel")
    
