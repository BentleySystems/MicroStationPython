import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

# Testing notes.
# To debug a test which needs a fixture make the following changes.
# 1. import the fixture function from the FixtureHelpers.py file i.e.
#       from FixtureHelpers import initDgnPlatformHost
# 2. Define a main which calls the test function with the fixture function i.e.
#   if __name__ == '__main__':
#    test_fixtureInit(initDgnPlatformHost)
# 3. to stop lots of __pycache__ folders being created where the debugger runs from set
#   PYTHONPYCACHEPREFIX=
#   i.e. 
#   PYTHONPYCACHEPREFIX=c:\temp\
#

pytestmark = pytest.mark.debugTest

DEGREE_PLACEHOLDER          = '^'
eSPECIALCHAR_Degree_Unicode  = 0x00b0

class  AngleFormatTestData:
    def __init__ (self, expectedString, inputValue, angleMode, anglePrec, leadingZero, trailingZeros, allowNegative):
        self.expectedString = expectedString
        self.inputValue = inputValue
        self.angleMode = angleMode
        self.anglePrec = anglePrec
        self.leadingZero = leadingZero
        self.trailingZeros = trailingZeros
        self.allowNegative = allowNegative

def replace_str_index(text,index=0,replacement=''):
    return '%s%s%s'%(text[:index],replacement,text[index+1:])

def replaceDegreeChar (str):
    outStr = str
    placeHolderPos = outStr.find (DEGREE_PLACEHOLDER)
    if (placeHolderPos != -1 ):
        return replace_str_index (outStr, placeHolderPos, chr(eSPECIALCHAR_Degree_Unicode))
    return outStr


def do_AngleFormatTest (data):
    formatter = AngleFormatter.Create ()
    formatter.SetAngleMode (data.angleMode)
    formatter.SetAnglePrecision (data.anglePrec)
    formatter.SetLeadingZero    (data.leadingZero)
    formatter.SetTrailingZeros  (data.trailingZeros)
    formatter.SetAllowNegative  (data.allowNegative)

    outputStr = repr (formatter.ToString (data.inputValue))
    expectStr = replaceDegreeChar (data.expectedString)

    assert expectStr == outputStr

testDataArray = [   AngleFormatTestData('35^',          35.123456789, AngleMode.eDegrees, AnglePrecision.eWhole, True, True, True), 
                    AngleFormatTestData('35.1^',        35.123456789, AngleMode.eDegrees, AnglePrecision.eUse1Place, True, True, True),
                    AngleFormatTestData('35.12^',       35.123456789, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True),
                    AngleFormatTestData('35.123^',      35.123456789, AngleMode.eDegrees, AnglePrecision.eUse3Places, True, True, True),
                    AngleFormatTestData('35.1235^',     35.123456789, AngleMode.eDegrees, AnglePrecision.eUse4Places, True, True, True),
                    AngleFormatTestData('35.12346^',    35.123456789, AngleMode.eDegrees, AnglePrecision.eUse5Places, True, True, True),
                    AngleFormatTestData('35.123457^',   35.123456789, AngleMode.eDegrees, AnglePrecision.eUse6Places, True, True, True),
                    AngleFormatTestData('35.1234568^',  35.123456789, AngleMode.eDegrees, AnglePrecision.eUse7Places, True, True, True),
                    AngleFormatTestData('35.12345679^', 35.123456789, AngleMode.eDegrees, AnglePrecision.eUse8Places, True, True, True)
                    ]

def test_FormatDegreeTestPrecision ():
    for entry in testDataArray:
        do_AngleFormatTest (entry)
