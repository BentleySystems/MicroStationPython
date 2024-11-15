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

def printGlobals (context : str):
    print (context)
    for k,v in list (globals().items()):
        print(f" key {str(k)} \t {str(v)}")
        
def callbacka ():
    global g_executedTestA
    g_executedTestA = True
    assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]

def callbackb ():
    assert len(sys.argv) == 2
    assert sys.argv[0] == 'cmdArg1'
    assert sys.argv[1] == 'cmdArg2'
    assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]

# cannot test g_executedTestA in main below, as you cant send synchronized keyins to python as python ->c++->python is not allowed so test it in another keyin
def callbackc ():
    global g_executedTestA
    assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
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



g_Str = "KeyInManager_Test"

''' Session Monitor Class  ''' 
class MyGlobalSessionMonitor(SessionMonitor):
    
    def __init__(self, g_Str):
        super(MyGlobalSessionMonitor, self).__init__()
        self.g_Str = g_Str


    ''' Callback called after opening a dgnFile  ''' 
    def _OnMasterFileStart (self, dgnFile):
        global g_Str
        assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
        print(f"KeyInManager_Test::_OnMasterFileStart __mdlDescr__ {globals()["__mdlDescr__"]}")
        assert self.g_Str == g_Str

    ''' Callback called before closing a dgnFile  ''' 
    def _OnMasterFileStop (self, dgnFile, changingFiles):
        global g_Str
        assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
        print(f"KeyInManager_Test::_OnMasterFileStart __mdlDescr__ {globals()["__mdlDescr__"]}")
        assert self.g_Str == g_Str

    ''' Callback called before a modelref is activated  ''' 
    def _OnModelRefPreActivate (self, modelRef):
        pass

    ''' Callback called on activating a model to make it active  ''' 
    def _OnModelRefActivate (self, newModelRef, oldModelRef):
        pass

    ''' Callback called after activating a model to make it active  ''' 
    def _OnModelRefActivated (self, newModelRef, oldModelRef):
        global g_Str
        assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
        print(f"KeyInManager_Test::_OnMasterFileStart __mdlDescr__ {globals()["__mdlDescr__"]}")
        assert self.g_Str == g_Str

    def _OnReleaseWriteLock (self, dgnFileVector):
        pass

    def _OnReleasedWriteLock (self, dgnFileVector):
        pass

    def _OnWriteLocked (self, dgnFile):
        pass

g_sessionMon = MyGlobalSessionMonitor(g_Str)


def globalSessionMonitorAdd ():
    global g_sessionMon
    assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
    ISessionMgr.AddSessionMonitor (g_sessionMon)


def globalSessionMonitorDrop ():
    global g_sessionMon
    assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
    ISessionMgr.DropSessionMonitor (g_sessionMon)


def test_AddKeyinSessionMonitor ():
    globals()["__mdlDescr__"] = 'KEYINMANAGER_TEST.PY' # Pytest must be setting/clearing globals() before the test, this has to be done here with a test which needs to run with a process descriptor
    globalSessionMonitorAdd ()
    
if __name__ == "__main__":
    assert 'KEYINMANAGER_TEST.PY' == globals()["__mdlDescr__"]
    test_KeyinRegisterExecute ()