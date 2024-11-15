#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from conftest import *

EPSILON = 0.000000001

def EXPECT_EQ (first, second):
    assert first == second

def ASSERT_EQ (first, second):
    EXPECT_EQ (first, second)

def EXPECT_TRUE (val):
    assert True == val

def EXPECT_STREQ (first, second):
    EXPECT_EQ (first, second)

def EXPECT_STRNE (first, second):
    EXPECT_NE (first, second)

def ASSERT_TRUE (val):
    EXPECT_TRUE (val)

def EXPECT_FALSE (val):
    assert False == val

def ASSERT_FALSE (val):
    EXPECT_FALSE (val)

def EXPECT_NE(first, second):
    assert first != second

def FAIL ():
    assert False

def getTestDataPath (fileName):
    return WString (os.path.join (os.environ['MSPYTESTDATA'], fileName))

def EXPECT_NEAR (expected, actual, absEpsion):
    EXPECT_TRUE (actual == pytest.approx (expected, abs=absEpsion))

class AssertDisabler:
    def setMS_IGNORE_ASSERTS (self, strValue):
        os.environ["MS_IGNORE_ASSERTS"] = strValue

    def __init__ (self):
        self.setMS_IGNORE_ASSERTS ("1")

    def __del__(self):
        self.setMS_IGNORE_ASSERTS ("")

    def __enter__ (self):
        self.setMS_IGNORE_ASSERTS ("1")
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.setMS_IGNORE_ASSERTS ("")