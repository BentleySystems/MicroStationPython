#import os
import pytest
import tempfile
import sys
import shutil

sys.dont_write_bytecode = True

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from ctypes import*


@pytest.fixture
def initProcessDescrForTest (testFileName):
    mydll = cdll.LoadLibrary("UstnPython.dll")
    mydll.CreateAndSwitchProcessDescr (testFileName)

       