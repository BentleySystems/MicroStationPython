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

def test_GetPriority():
    priority = OutputMessagePriority.eFatal
    brief = "This is fatal"
    x= NotifyMessageDetails(priority,brief)

    assert priority == x.GetPriority()

def test_GetOpenAlert_default():
    priority = OutputMessagePriority.eFatal
    openAlert = OutputMessageAlert.eNil
    brief = "This is fatal"
    x= NotifyMessageDetails(priority,brief)
    assert openAlert == x.GetOpenAlert()

def test_GetOpenAlert_setAlert():
    priority = OutputMessagePriority.eFatal
    openAlert = OutputMessageAlert.eDialog
    brief = "This is fatal"
    x= NotifyMessageDetails(priority,brief,None,1, openAlert)
    assert openAlert == x.GetOpenAlert()


def test_GetBriefMsg():
    priority = OutputMessagePriority.eFatal
    openAlert = OutputMessageAlert.eDialog
    brief = "This is fatal"
    x= NotifyMessageDetails(priority,brief,None,1, openAlert)
    assert openAlert == x.GetOpenAlert()


def test_GetMsgAttributes_default():
    priority = OutputMessagePriority.eFatal
    brief = "This is fatal"
    x= NotifyMessageDetails(priority,brief)
    assert 0 == x.GetMsgAttributes()

def test_GetMsgAttributes_setAttr():
    priority = OutputMessagePriority.eFatal
    openAlert = OutputMessageAlert.eNil
    brief = "This is fatal"
    attr = 1
    x= NotifyMessageDetails(priority,brief,None, attr, openAlert)
    assert attr == x.GetMsgAttributes()

def test_GetDetailedMsg():
    priority = OutputMessagePriority.eFatal
    openAlert = OutputMessageAlert.eNil
    brief = "This is fatal"
    detailMsg = "This is a long message"
    attr = 1
    x= NotifyMessageDetails(priority, brief, detailMsg, attr, openAlert)
    assert detailMsg == repr(x.GetDetailedMsg())