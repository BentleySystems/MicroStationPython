#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import tempfile
import sys
import shutil

sys.dont_write_bytecode = True

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
#
# if you want to test functions in here build the Microstation SDK with the python part then in your environment 
#
# if you use VS code and you want to debug the python tests then add the following to your launch.json
# Note: you will need to change the paths from those below to the location of the MSPyBentley.pyd files in your install
#          {
#            "name": "Python: pytest",
#            "type": "python",
#            "request": "launch",
#            "module": "pytest",
#            "cwd": "c:/src/ADOPython/MSPython/MSPythonTests/PlatformTests/",
#            "env": {
#                "PYTHONPATH": "D:/out/ADOPython/Winx64/Build/MSPython/MSPythonTests/",
#                "MS": "<path to Microstation.exe>" 
#            },
#            "console": "integratedTerminal",
#        }          
# The environment variable : MSPYTESTDATA  needs to be set to the location of ./PlatformTests/data
#
# for debugging tests use pip install pytest-env to allow environment variables to be set in the pytest.ini file so MSPYTESTDATA is found 
#

globalData = {}

@pytest.fixture
def createTempDgnFileWithSeed():
    def _createTempDgnFileWithSeed (tmpfileName, seedDgnFile):
        BeFileName.BeDeleteFile (tmpfileName)
        shutil.copy(str (seedDgnFile.GetFileName ()),tmpfileName)
        doc = DgnDocument.CreateForLocalFile(tmpfileName)
        assert doc != None
        dgnFile = DgnFile (doc, DgnFileOpenMode.eReadWrite)
        dgnFile.LoadDgnFile ()
        dgnFile.LoadRootModelById (seedDgnFile.GetDefaultModelId (), True, False, False)   
        dgnFile.FillDictionaryModel ()
        globalData[fileSpec]=fileSpec        
        return dgnFile
    return _createTempDgnFileWithSeed

def createTempDgnFileFromSeedFile (seedDgnFile):
    emptyDir = WString ()
    ConfigurationManager.GetLocalTempDirectory (emptyDir,"")       
    tempFileName = next(tempfile._get_candidate_names()) + ".dgn"
    fileSpec = str (emptyDir) + str (tempFileName)
    BeFileName.BeDeleteFile (fileSpec)
    shutil.copy(str (seedDgnFile.GetFileName ()),fileSpec)
    ret = DgnDocument.CreateFromFileName (fileSpec, "", -101, DgnDocument.FetchMode.eWrite)
    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False
    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()
    globalData[fileSpec]=fileSpec        
    return dgnFile

@pytest.fixture
def createTempDgnFileFromSeed ():
    def _createTempDgnFileFromSeed (seedDgnFile):
        return createTempDgnFileFromSeedFile (seedDgnFile)

    return _createTempDgnFileFromSeed

@pytest.fixture
def removeTempCreatedFile():
    def _removeTempCreatedFile (testName, tempFile):
        globalData[testName]=tempFile
    return _removeTempCreatedFile

@pytest.fixture (scope='session', autouse=True)
def sessionfinalizer():
    globalData.clear()

    yield

    for tmpFileCreated in globalData.values():
        if(True == BeFileName.DoesPathExist(str(tmpFileCreated))):
            BeFileName.BeDeleteFile (str(tmpFileCreated))

    globalData.clear()

@pytest.fixture
def loadDgnFile (fileName):
    dataDir = os.environ['MSPYTESTDATA']
    ret = DgnDocument.CreateFromFileName (fileName, dataDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()

    return dgnFile

@pytest.fixture
def loadDgnFileReadOnly (fileName):
    dataDir = os.environ['MSPYTESTDATA']
    ret = DgnDocument.CreateFromFileName (fileName, dataDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadOnly)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()
    return dgnFile
       
# This will load ustation.dll and intialize an empty DgnHost object for use with reading DgnFiles
@pytest.fixture
def initDgnPlatformHost ():
    if False == ConfigurationManager.IsVariableDefined ("MS_SYMBRSRC"):
        outDir = os.environ["OutRoot"]
        if outDir != '':
            fontRSCDir = os.path.join (outDir, "Winx64\\Product\\Mstn\\MicroStation\\Default\\Symb\\")
            ConfigurationManager.DefineVariable ("MS_SYMBRSRC", fontRSCDir)

    DgnPlatformFixture_Initialize ()




