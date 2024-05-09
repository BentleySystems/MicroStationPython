import os
import pytest

import sys

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
    DgnPlatformFixture_Initialize ()




