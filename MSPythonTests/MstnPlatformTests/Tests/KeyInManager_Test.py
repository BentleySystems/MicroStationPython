#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import time
import sys

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

g_executedTestA = False


def callbacka ():
    global g_executedTestA
    g_executedTestA = True

def callbackb ():
    assert len(sys.argv) == 2
    assert sys.argv[0] == 'cmdArg1'
    assert sys.argv[1] == 'cmdArg2'

# cannot test g_executedTestA in main below, as you cant send synchronized keyins to python as python ->c++->python is not allowed so test it in another keyin
def callbackc ():
    global g_executedTestA
    assert g_executedTestA == True


def test_KeyinRegisterExecute ():
    keyinXml = os.path.dirname(__file__) + '/KeyInTest.commands.xml'
    print (__file__)
    print (str (keyinXml))
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))

    # note the order the keyins are executed is TESTB, TESTA, TESTC
 
    PyCadInputQueue.SendKeyinToPython ("KEYINTEST TESTC")

    PyCadInputQueue.SendKeyinToPython ("KEYINTEST TESTA")

    PyCadInputQueue.SendKeyinToPython ("KEYINTEST TESTB  cmdArg1 cmdArg2")


if __name__ == "__main__":
    test_KeyinRegisterExecute ()