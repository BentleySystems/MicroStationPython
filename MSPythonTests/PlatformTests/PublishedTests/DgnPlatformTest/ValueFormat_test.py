#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

MIN_TO_DEG  = (1.0 / 60)
SEC_TO_DEG = (1.0 / 3600)
GRAD_TO_DEG = (90.0 / 100)
RAD_TO_DEG = (180.0 / 3.141592653589793238462643)


def  doFormatDoubleTest (testData): 
    formatter = DoubleFormatter.Create()

    formatter.SetPrecision      (testData[2])
    formatter.SetLeadingZero    (testData[3])
    formatter.SetTrailingZeros  (testData[4])
    formatter.SetInsertThousandsSeparator  (testData[5])
    formatter.SetThousandsSeparator  (testData[7])
    formatter.SetDecimalSeparator  (testData[6])

    outputStr = formatter.ToString (testData[1])
    assert  testData[0] == repr(outputStr)



def test_FormatDecimal_TestPrecision(initDgnPlatformHost):

    testData= [
        # expected         value           precision                  leadingZero, trailingZero, useThousandsSep, decSep, thousandsSep[,
        [ "35",            35.123456789,   PrecisionFormat.eDecimalWhole,   True,        True,         False,           '.',   ','],
        [ "35.1",          35.123456789,   PrecisionFormat.eDecimal1Place,  True,        True,         False,           '.',   ','],
        [ "35.12",         35.123456789,   PrecisionFormat.eDecimal2Places, True,        True,         False,           '.',   ','],
        [ "35.123",        35.123456789,   PrecisionFormat.eDecimal3Places, True,        True,         False,           '.',   ','],
        [ "35.1235",       35.123456789,   PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.12346",      35.123456789,   PrecisionFormat.eDecimal5Places, True,        True,         False,           '.',   ','],
        [ "35.123457",     35.123456789,   PrecisionFormat.eDecimal6Places, True,        True,         False,           '.',   ','],
        [ "35.1234568",    35.123456789,   PrecisionFormat.eDecimal7Places, True,        True,         False,           '.',   ','],
        [ "35.12345679",   35.123456789,   PrecisionFormat.eDecimal8Places, True,        True,         False,           '.',   ',']
    ]

    for i in range (0,len(testData)):
        doFormatDoubleTest(testData[i])

def test_FormatDecimal_TestRounding(initDgnPlatformHost):

    testData= [
        # expected         value           precision                  leadingZero, trailingZero, useThousandsSep, decSep, thousandsSep[,
        [ "35.1234",       35.12340,       PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1234",       35.123445,      PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1234",       35.123449,      PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1234",       35.1234499,     PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1234",       35.12344999,    PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1235",       35.12350000,    PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1235",       35.12350001,    PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "35.1235",       35.12350002,    PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ',']
    ]

    for i in range (0,len(testData)):
        doFormatDoubleTest(testData[i])

def test_FormatDecimal_TestZeros(initDgnPlatformHost):

    testData= [
        # expected         value           precision                  leadingZero, trailingZero, useThousandsSep, decSep, thousandsSep[,
        [ "0.0000",        0.0,            PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "0",             0.0,            PrecisionFormat.eDecimal4Places, True,        False,        False,           '.',   ','],
        [ ".0000",         0.0,            PrecisionFormat.eDecimal4Places, False,       True,         False,           '.',   ','],
        [ "0",             0.0,            PrecisionFormat.eDecimal4Places, False,       False,        False,           '.',   ','],
        [ "100.1000",      100.1,          PrecisionFormat.eDecimal4Places, True,        True,         False,           '.',   ','],
        [ "100.1",         100.1,          PrecisionFormat.eDecimal4Places, True,        False,        False,           '.',   ','],
        [ "100.1000",      100.1,          PrecisionFormat.eDecimal4Places, False,       True,         False,           '.',   ','],
        [ "100.1",         100.1,          PrecisionFormat.eDecimal4Places, False,       False,        False,           '.',   ','],
        ]

    for i in range (0,len(testData)):
        doFormatDoubleTest(testData[i])

def test_FormatDecimal_TestSeparators(initDgnPlatformHost):
    testData= [
        # expected         value           precision                  leadingZero, trailingZero, useThousandsSep, decSep, thousandsSep[,
        [ "10.45",         10.45,          PrecisionFormat.eDecimal2Places, True,        True,         False,           '.',   ','],
        [ "10#45",         10.45,          PrecisionFormat.eDecimal2Places, True,        True,         False,           '#',   ','],
        [ "10.45",         10.45,          PrecisionFormat.eDecimal2Places, True,        True,         True,            '.',   ','],
        [ "10#45",         10.45,          PrecisionFormat.eDecimal2Places, True,        True,         True,            '#',   ','],
        [ "1000#45",       1000.45,        PrecisionFormat.eDecimal2Places, True,        True,         False,           '#',   ','],
        [ "1,000#45",      1000.45,        PrecisionFormat.eDecimal2Places, True,        True,         True,            '#',   ','],
        [ "1000#45",       1000.45,        PrecisionFormat.eDecimal2Places, True,        True,         False,           '#',   '!'],
        [ "1!000#45",      1000.45,        PrecisionFormat.eDecimal2Places, True,        True,         True,            '#',   '!'],
        [ "100",           100,            PrecisionFormat.eDecimal2Places, True,        False,        True,            '.',   ','],
        [ "1,000",         1000,           PrecisionFormat.eDecimal2Places, True,        False,        True,            '.',   ','],
        [ "10,000",        10000,          PrecisionFormat.eDecimal2Places, True,        False,        True,            '.',   ','],
        [ "100,000",       100000,         PrecisionFormat.eDecimal2Places, True,        False,        True,            '.',   ','],
        [ "1,000,000",     1000000,        PrecisionFormat.eDecimal2Places, True,        False,        True,            '.',   ','],
        [ "1x000x000",     1000000,        PrecisionFormat.eDecimal2Places, True,        False,        True,            '.',   'x'],
        ]
    for i in range (0,len(testData)):
        doFormatDoubleTest(testData[i])

def test_FormatFractional_TestPrecision(initDgnPlatformHost):
    testData= [
        # expected         value           precision                  leadingZero, trailingZero, useThousandsSep, decSep, thousandsSep[,
        [ "35",            35,             PrecisionFormat.eFractionalWhole,       True,        True,         False,           '.',   ','],
        [ "35 1/2",        35.5,           PrecisionFormat.eFractionalHalf,        True,        True,         False,           '.',   ','],
        [ "35 3/4",        35.75,          PrecisionFormat.eFractionalQuarter,     True,        True,         False,           '.',   ','],
        [ "35 7/8",        35.875,         PrecisionFormat.eFractionalEighth,      True,        True,         False,           '.',   ','],
        [ "35 15/16",      35.9375,        PrecisionFormat.eFractionalSixteenth,   True,        True,         False,           '.',   ','],
        [ "35 31/32",      35.96875,       PrecisionFormat.eFractional1_Over_32,   True,        True,         False,           '.',   ','],
        [ "35 63/64",      35.984375,      PrecisionFormat.eFractional1_Over_64,   True,        True,         False,           '.',   ','],
        [ "35 127/128",    35.9921875,     PrecisionFormat.eFractional1_Over_128,  True,        True,         False,           '.',   ','],
        [ "35 255/256",    35.99609375,    PrecisionFormat.eFractional1_Over_256,  True,        True,         False,           '.',   ','],
        ]

    for i in range (0,len(testData)):
        doFormatDoubleTest(testData[i])


def test_FormatFractional_TestRounding(initDgnPlatformHost):
    testData= [
        # expected         value           precision                  leadingZero, trailingZero, useThousandsSep, decSep, thousandsSep[,
        [ "35",            35,             PrecisionFormat.eFractionalWhole,       True,        True,         False,           '.',   ','],
        [ "35 1/2",        35.5,           PrecisionFormat.eFractionalHalf,        True,        True,         False,           '.',   ','],
        [ "35 3/4",        35.75,          PrecisionFormat.eFractionalQuarter,     True,        True,         False,           '.',   ','],
        [ "35 7/8",        35.875,         PrecisionFormat.eFractionalEighth,      True,        True,         False,           '.',   ','],
        [ "35 15/16",      35.9375,        PrecisionFormat.eFractionalSixteenth,   True,        True,         False,           '.',   ','],
        [ "35 31/32",      35.96875,       PrecisionFormat.eFractional1_Over_32,   True,        True,         False,           '.',   ','],
        [ "35 63/64",      35.984375,      PrecisionFormat.eFractional1_Over_64,   True,        True,         False,           '.',   ','],
        [ "35 127/128",    35.9921875,     PrecisionFormat.eFractional1_Over_128,  True,        True,         False,           '.',   ','],
        [ "35 255/256",    35.99609375,    PrecisionFormat.eFractional1_Over_256,  True,        True,         False,           '.',   ','],
        ]

    for i in range (0,len(testData)):
        doFormatDoubleTest(testData[i])



def replaceDegreeChar (str):    

    outStr = WString(str)
    placeHolderPos = str.find ('^')
    if (placeHolderPos != -1 ):        
        outStr.ReplaceI ( '^', chr(176))        
    return outStr

def doFormatAngleTest(testData):
    formatter = AngleFormatter.Create()

    formatter.SetAngleMode      (testData[2])
    formatter.SetAnglePrecision (testData[3])
    formatter.SetLeadingZero    (testData[4])
    formatter.SetTrailingZeros  (testData[5])
    formatter.SetAllowNegative  (testData[6])

    outputStr = formatter.ToString (testData[1])
    expectStr = replaceDegreeChar (testData[0])

    assert repr(expectStr) == repr(outputStr)


# def test_FormateDegree_TestNaN():  #not getting proper method for sqrt
#     testDataArray =[
#         [ "N/A",          -1.00, AngleMode.eDegrees, AnglePrecision.eWhole,   True, True, True[,
#          ["N/A",          0, AngleMode.eDegrees, AnglePrecision.eWhole,   True, True, True[
#         [

#     for i in range (0,len(testDataArray)):
#         doFormatAngleTest(testDataArray[i[)

def test_FormatDegree_TestPrecision():

    testDataArray =[
        [ "35^",          35.123456789, AngleMode.eDegrees, AnglePrecision.eWhole,      True, True, True],
        [ "35.1^",        35.123456789, AngleMode.eDegrees, AnglePrecision.eUse1Place,  True, True, True],
        [ "35.12^",       35.123456789, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "35.123^",      35.123456789, AngleMode.eDegrees, AnglePrecision.eUse3Places, True, True, True],
        [ "35.1235^",     35.123456789, AngleMode.eDegrees, AnglePrecision.eUse4Places, True, True, True],
        [ "35.12346^",    35.123456789, AngleMode.eDegrees, AnglePrecision.eUse5Places, True, True, True],
        [ "35.123457^",   35.123456789, AngleMode.eDegrees, AnglePrecision.eUse6Places, True, True, True],
        [ "35.1234568^",  35.123456789, AngleMode.eDegrees, AnglePrecision.eUse7Places, True, True, True],
        [ "35.12345679^", 35.123456789, AngleMode.eDegrees, AnglePrecision.eUse8Places, True, True, True]
        ]

    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatDegree_TestFullCircle():

    testDataArray =[
        [   "0.00^",     0.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [  "30.00^",    30.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [  "60.00^",    60.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [  "90.00^",    90.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "120.00^",   120.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "150.00^",   150.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "180.00^",   180.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "210.00^",   210.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "240.00^",   240.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "270.00^",   270.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "300.00^",   300.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "330.00^",   330.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        [ "360.00^",   360.0, AngleMode.eDegrees, AnglePrecision.eUse2Places, True, True, True],
        ]

    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])


def test_FormatDegMin_TestPrecision():

    testDataArray =[
        [  "35^35'",           35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eWhole,   True, True, True],
        [  "35^35.1'",         35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse1Place, True, True, True],
        [  "35^35.12'",        35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse2Places, True, True, True],
        [  "35^35.123'",       35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse3Places, True, True, True],
        [  "35^35.1235'",      35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse4Places, True, True, True],
        [  "35^35.12346'",     35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse5Places, True, True, True],
        [  "35^35.123457'",    35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse6Places, True, True, True],
        [  "35^35.1234568'",   35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse7Places, True, True, True],
        [  "35^35.12345679'",  35 + 35.123456789 * MIN_TO_DEG, AngleMode.eDegMin, AnglePrecision.eUse8Places, True, True, True],
        ]

    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatDegMinSec_TestPrecision():

    testDataArray =[
        [  "35^00'35\"",           35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eWhole,   True, True, True],
        [  "35^00'35.1\"",         35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse1Place, True, True, True],
        [  "35^00'35.12\"",        35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse2Places, True, True, True],
        [  "35^00'35.123\"",       35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse3Places, True, True, True],
        [  "35^00'35.1235\"",      35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse4Places, True, True, True],
        [  "35^00'35.12346\"",     35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse5Places, True, True, True],
        [  "35^00'35.123457\"",    35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse6Places, True, True, True],
        [  "35^00'35.1234568\"",   35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse7Places, True, True, True],
        [  "35^00'35.12345679\"",  35 + 35.123456789 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse8Places, True, True, True],
        ]

    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatCentesimal_TestPrecision():

    testDataArray =[
        [  "50g",          50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eWhole,   True, True, True],
        [  "50.1g",        50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse1Place, True, True, True],
        [  "50.12g",       50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "50.123g",      50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse3Places, True, True, True],
        [  "50.1235g",     50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse4Places, True, True, True],
        [  "50.12346g",    50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse5Places, True, True, True],
        [  "50.123457g",   50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse6Places, True, True, True],
        [  "50.1234568g",  50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse7Places, True, True, True],
        [  "50.12345679g", 50.123456789 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse8Places, True, True, True],
        ]

    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatCentesimal_TestFullCircle():

    testDataArray = [
        [    "0.00g",     0.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [   "25.00g",    25.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [   "50.00g",    50.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [   "75.00g",    75.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "100.00g",   100.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "125.00g",   125.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "150.00g",   150.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "175.00g",   175.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "200.00g",   200.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "225.00g",   225.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "250.00g",   250.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "275.00g",   275.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "300.00g",   300.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "325.00g",   325.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "350.00g",   350.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "375.00g",   375.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        [  "400.00g",   400.0 * GRAD_TO_DEG, AngleMode.eCentesimal, AnglePrecision.eUse2Places, True, True, True],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatRadians_TestPrecision():

    testDataArray =  [
         [  "2r",          2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eWhole,    True,  True,  True ],
         [  "2.1r",        2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse1Place,  True,  True,  True ],
         [  "2.12r",       2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse2Places,  True,  True,  True ],
         [  "2.123r",      2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse3Places,  True,  True,  True ],
         [  "2.1235r",     2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse4Places,  True,  True,  True ],
         [  "2.12346r",    2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse5Places,  True,  True,  True ],
         [  "2.123457r",   2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse6Places,  True,  True,  True ],
         [  "2.1234568r",  2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse7Places,  True,  True,  True ],
         [  "2.12345679r", 2.123456789 * RAD_TO_DEG, AngleMode.eRadians, AnglePrecision.eUse8Places,  True,  True,  True ],
         ]
    
    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatDegree_TestZeros():
    testDataArray =  [
         [  "0^",         0.0, AngleMode.eDegrees, AnglePrecision.eWhole,    True,   True,   True ],
         [  "0^",         0.0, AngleMode.eDegrees, AnglePrecision.eWhole,    True,   False,  True ],
         [  "0^",         0.0, AngleMode.eDegrees, AnglePrecision.eWhole,    False,  True,   True ],
         [  "0^",         0.0, AngleMode.eDegrees, AnglePrecision.eWhole,    False,  False,  True ],

         [  "0.0^",       0.0, AngleMode.eDegrees, AnglePrecision.eUse1Place,  True,   True,   True ],
         [  "0^",         0.0, AngleMode.eDegrees, AnglePrecision.eUse1Place,  True,   False,  True ],
         [  ".0^",        0.0, AngleMode.eDegrees, AnglePrecision.eUse1Place,  False,  True,   True ],
         [  "0^",         0.0, AngleMode.eDegrees, AnglePrecision.eUse1Place,  False,  False,  True ],
                                                                  
         [  "0.5^",       0.5, AngleMode.eDegrees, AnglePrecision.eUse1Place,  True,   True,   True ],
         [  "0.5^",       0.5, AngleMode.eDegrees, AnglePrecision.eUse1Place,  True,   False,  True ],
         [  ".5^",        0.5, AngleMode.eDegrees, AnglePrecision.eUse1Place,  False,  True,   True ],
         [  ".5^",        0.5, AngleMode.eDegrees, AnglePrecision.eUse1Place,  False,  False,  True ],
                                                                  
         [  "0.5000^",    0.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  True,   True,   True ],
         [  "0.5^",       0.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  True,   False,  True ],
         [  ".5000^",     0.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  False,  True,   True ],
         [  ".5^",        0.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  False,  False,  True ],
                                                                  
         [  "35.5000^",  35.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  True,   True,   True ],
         [  "35.5^",     35.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  True,   False,  True ],
         [  "35.5000^",  35.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  False,  True,   True ],
         [  "35.5^",     35.5, AngleMode.eDegrees, AnglePrecision.eUse4Places,  False,  False,  True ]
         ]                                                        
    
    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatDegMin_TestZeros():
    testDataArray =   [
         [  "00^00'",       0.0, AngleMode.eDegMin, AnglePrecision.eWhole,    True,   True,   True ],
         [  "00^00'",       0.0, AngleMode.eDegMin, AnglePrecision.eWhole,    True,   False,  True ],
         [  "0^0'",         0.0, AngleMode.eDegMin, AnglePrecision.eWhole,    False,  True,   True ],
         [  "0^0'",         0.0, AngleMode.eDegMin, AnglePrecision.eWhole,    False,  False,  True ],
                                                                   
         [  "00^00.0'",     0.0, AngleMode.eDegMin, AnglePrecision.eUse1Place,  True,   True,   True ],
         [  "00^00'",       0.0, AngleMode.eDegMin, AnglePrecision.eUse1Place,  True,   False,  True ],
         [  "0^0.0'",       0.0, AngleMode.eDegMin, AnglePrecision.eUse1Place,  False,  True,   True ],
         [  "0^0'",         0.0, AngleMode.eDegMin, AnglePrecision.eUse1Place,  False,  False,  True ],
                                                                   
         [  "00^30.0'",     0.5, AngleMode.eDegMin, AnglePrecision.eUse1Place,  True,   True,   True ],
         [  "00^30'",       0.5, AngleMode.eDegMin, AnglePrecision.eUse1Place,  True,   False,  True ],
         [  "0^30.0'",      0.5, AngleMode.eDegMin, AnglePrecision.eUse1Place,  False,  True,   True ],
         [  "0^30'",        0.5, AngleMode.eDegMin, AnglePrecision.eUse1Place,  False,  False,  True ],
                                                                   
         [  "00^30.0000'",  0.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  True,   True,   True ],
         [  "00^30'",       0.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  True,   False,  True ],
         [  "0^30.0000'",   0.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  False,  True,   True ],
         [  "0^30'",        0.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  False,  False,  True ],
                                                                   
         [  "35^30.0000'", 35.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  True,   True,   True ],
         [  "35^30'",      35.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  True,   False,  True ],
         [  "35^30.0000'", 35.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  False,  True,   True ],
         [  "35^30'",      35.5, AngleMode.eDegMin, AnglePrecision.eUse4Places,  False,  False,  True ],
         ]                                                         
    
    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def test_FormatDegMinSec_TestZeros():
    testDataArray =  [
         [  "00^00'00\"",      0.0,                  AngleMode.eDegMinSec, AnglePrecision.eWhole,    True,   True,   True ],
         [  "00^00'00\"",      0.0,                  AngleMode.eDegMinSec, AnglePrecision.eWhole,    True,   False,  True ],
         [  "0^0'0\"",         0.0,                  AngleMode.eDegMinSec, AnglePrecision.eWhole,    False,  True,   True ],
         [  "0^0'0\"",         0.0,                  AngleMode.eDegMinSec, AnglePrecision.eWhole,    False,  False,  True ],
                                                               
         [  "00^00'00.0\"",    0.0,                  AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  True,   True,   True ],
         [  "00^00'00\"",      0.0,                  AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  True,   False,  True ],
         [  "0^0'0.0\"",       0.0,                  AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  False,  True,   True ],
         [  "0^0'0\"",         0.0,                  AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  False,  False,  True ],
                                                                                          
         [  "00^00'30.0\"",    30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  True,   True,   True ],
         [  "00^00'30\"",      30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  True,   False,  True ],
         [  "0^0'30.0\"",      30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  False,  True,   True ],
         [  "0^0'30\"",        30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse1Place,  False,  False,  True ],
                                                                                          
         [  "00^00'30.0000\"", 30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  True,   True,   True ],
         [  "00^00'30\"",      30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  True,   False,  True ],
         [  "0^0'30.0000\"",   30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  False,  True,   True ],
         [  "0^0'30\"",        30 * SEC_TO_DEG,      AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  False,  False,  True ],
                                                                                          
         [  "35^00'30.0000\"", 35 + 30 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  True,   True,   True ],
         [  "35^00'30\"",      35 + 30 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  True,   False,  True ],
         [  "35^0'30.0000\"",  35 + 30 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  False,  True,   True ],
         [  "35^0'30\"",       35 + 30 * SEC_TO_DEG, AngleMode.eDegMinSec, AnglePrecision.eUse4Places,  False,  False,  True ],
         ]
    
    for i in range (0,len(testDataArray)):
        doFormatAngleTest(testDataArray[i])

def doFormatDirectionTest (testData):
    
    formatter = DirectionFormatter.Create()

    formatter.SetDirectionMode  (testData[2])
    formatter.SetBaseDirection  (testData[3])
    formatter.SetClockwise      (testData[4])
    formatter.GetAngleFormatter().SetAngleMode      (AngleMode.eDegMinSec)
    formatter.GetAngleFormatter().SetAnglePrecision (AnglePrecision.eWhole)
    formatter.GetAngleFormatter().SetLeadingZero    (True)
    formatter.GetAngleFormatter().SetTrailingZeros  (True)

    outputStr = formatter.ToString (testData[1])
    expectStr = replaceDegreeChar (testData[0])

    assert repr(outputStr) == repr(expectStr)

@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_FormateAzimuth_TestNaN():  #not getting proper method for sqrt
    testDataArray =   [
        [ "N/A", sqrt(-1.00), DirectionMode.eAzimuth, 0.0,   False],
        [ "N/A", None, DirectionMode.eAzimuth, 0.0,   False]
        ]
    for i in range (0,len(testDataArray)):
        doFormatDirectionTest(testDataArray[i])


def test_FormatAzimuth_TestFullCircle1():

    testDataArray =  [
        [  "00^00'00\"",       0.0,   DirectionMode.eAzimuth, 0.0, False],
        [  "30^00'00\"",      30.0,   DirectionMode.eAzimuth, 0.0, False],
        [  "60^00'00\"",      60.0,   DirectionMode.eAzimuth, 0.0, False],
        [  "90^00'00\"",      90.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "120^00'00\"",     120.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "150^00'00\"",     150.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "180^00'00\"",     180.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "210^00'00\"",     210.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "240^00'00\"",     240.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "270^00'00\"",     270.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "300^00'00\"",     300.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "330^00'00\"",     330.0,   DirectionMode.eAzimuth, 0.0, False],
        [ "360^00'00\"",     360.0,   DirectionMode.eAzimuth, 0.0, False],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDirectionTest(testDataArray[i])

def test_FormatAzimuth_TestFullCircle2():

    testDataArray =  [
        [  "90^00'00\"",       0.0,   DirectionMode.eAzimuth, 90.0, True],
        [  "60^00'00\"",      30.0,   DirectionMode.eAzimuth, 90.0, True],
        [  "30^00'00\"",      60.0,   DirectionMode.eAzimuth, 90.0, True],
        [  "00^00'00\"",      90.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "330^00'00\"",     120.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "300^00'00\"",     150.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "270^00'00\"",     180.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "240^00'00\"",     210.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "210^00'00\"",     240.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "180^00'00\"",     270.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "150^00'00\"",     300.0,   DirectionMode.eAzimuth, 90.0, True],
        [ "120^00'00\"",     330.0,   DirectionMode.eAzimuth, 90.0, True],
        [  "90^00'00\"",     360.0,   DirectionMode.eAzimuth, 90.0, True],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDirectionTest(testDataArray[i])

def test_FormatBearing_TestFullCircle1():
    
    testDataArray =  [
        [ "N90^00'00\"E",       0.0,   DirectionMode.eBearing, 0.0, False],
        [ "N60^00'00\"E",      30.0,   DirectionMode.eBearing, 0.0, False],
        [ "N30^00'00\"E",      60.0,   DirectionMode.eBearing, 0.0, False],
        [ "N00^00'00\"E",      90.0,   DirectionMode.eBearing, 0.0, False],
        [ "N30^00'00\"W",     120.0,   DirectionMode.eBearing, 0.0, False],
        [ "N60^00'00\"W",     150.0,   DirectionMode.eBearing, 0.0, False],
        [ "N90^00'00\"W",     180.0,   DirectionMode.eBearing, 0.0, False],
        [ "S60^00'00\"W",     210.0,   DirectionMode.eBearing, 0.0, False],
        [ "S30^00'00\"W",     240.0,   DirectionMode.eBearing, 0.0, False],
        [ "S00^00'00\"E",     270.0,   DirectionMode.eBearing, 0.0, False],
        [ "S30^00'00\"E",     300.0,   DirectionMode.eBearing, 0.0, False],
        [ "S60^00'00\"E",     330.0,   DirectionMode.eBearing, 0.0, False],
        [ "N90^00'00\"E",     360.0,   DirectionMode.eBearing, 0.0, False],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDirectionTest(testDataArray[i])

def test_FormatBearing_TestFullCircle2():
    testDataArray =  [
        [ "N90^00'00\"E",       0.0,   DirectionMode.eBearing, 90.0, True],
        [ "N60^00'00\"E",      30.0,   DirectionMode.eBearing, 90.0, True],
        [ "N30^00'00\"E",      60.0,   DirectionMode.eBearing, 90.0, True],
        [ "N00^00'00\"E",      90.0,   DirectionMode.eBearing, 90.0, True],
        [ "N30^00'00\"W",     120.0,   DirectionMode.eBearing, 90.0, True],
        [ "N60^00'00\"W",     150.0,   DirectionMode.eBearing, 90.0, True],
        [ "N90^00'00\"W",     180.0,   DirectionMode.eBearing, 90.0, True],
        [ "S60^00'00\"W",     210.0,   DirectionMode.eBearing, 90.0, True],
        [ "S30^00'00\"W",     240.0,   DirectionMode.eBearing, 90.0, True],
        [ "S00^00'00\"E",     270.0,   DirectionMode.eBearing, 90.0, True],
        [ "S30^00'00\"E",     300.0,   DirectionMode.eBearing, 90.0, True],
        [ "S60^00'00\"E",     330.0,   DirectionMode.eBearing, 90.0, True],
        [ "N90^00'00\"E",     360.0,   DirectionMode.eBearing, 90.0, True],
        ]
    for i in range (0,len(testDataArray)):
        doFormatDirectionTest(testDataArray[i])


def doFormatDistanceTest (testData): 

    formatter = DistanceFormatter.Create()

    formatter.SetWorkingUnits(testData[13], testData[14])
    formatter.SetStorageUnit(testData[15], testData[16])
    formatter.SetUnitFormat (testData[12])
    formatter.SetPrecision (testData[2])
    formatter.SetUnitLabelFlag (testData[3])
    formatter.SetLeadingZero (testData[4])
    formatter.SetTrailingZeros (testData[5])
    formatter.SetInsertThousandsSeparator (testData[6])
    formatter.SetThousandsSeparator (testData[7])
    formatter.SetDecimalSeparator (testData[8])
    formatter.SetSuppressZeroMasterUnits (testData[9])
    formatter.SetSuppressZeroSubUnits (testData[10])
    formatter.SetScaleFactor (testData[11])
    outputStr = formatter.ToString (testData[0])

    assert testData[1] == repr(outputStr)
    

def test_Format_TestGeneral(initDgnPlatformHost):  
    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray =[
        #uor           value               precision                       unitflag    leadingzero     trailingzero    insertthousands     thousandssep    decimalsep    suppresszeromaster  suppresszerosub   scalefactor format                master        sub         storage         uorperstorage   
        [ 1,            "0.000",           PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0.100",           PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1.000",           PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10.000",          PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1,            "0.100",           PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "100.000",         PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1000.000",        PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10000.000",       PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1,            "0:0.100",         PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100.000",       PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1:0.000",         PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10:0.000",        PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1,            "0:0:1.000",       PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:0.000",     PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1:0:0.000",       PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10:0:0.000",      PrecisionFormat.eDecimal3Places,      False,      True,           True,           False,              ',',            '.',          False,              False,            0.0,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        ]

    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])


def test_Format_TestUnitLabelFlag(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray = [  
        #uor           value                                    precision                   unitflag  leadingzero  trailingzero  insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor  format                master        sub         storage         uorperstorage   
        [ 10000,        "1.000m",   PrecisionFormat.eDecimal3Places,  True,     True,        True,         False,           ',',          '.',        False,              False,           0.0,         DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1000.000mm", PrecisionFormat.eDecimal3Places,  True,     True,        True,         False,           ',',          '.',        False,              False,           0.0,         DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1m 0.000mm",   PrecisionFormat.eDecimal3Places,  True,     True,        True,         False,           ',',          '.',        False,              False,           0.0,         DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1m 0:0.000mm" , PrecisionFormat.eDecimal3Places,  True,     True,        True,         False,           ',',          '.',        False,              False,           0.0,         DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])

def test_Format_TestPrecision(initDgnPlatformHost): 

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray = [
        #uor           value                      precision                   unitflag    leadingzero trailingzero  insertthousands  thousandssep  decimalseparator  suppresszeromaster  suppresszerosub  scalefactor format                master        sub         storage         uorperstorage   
        [ 1,            "0.00",                   PrecisionFormat.eDecimal2Places,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0.10",                   PrecisionFormat.eDecimal2Places,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1.0",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10.0",                   PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10",                     PrecisionFormat.eDecimalWhole,    False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10.0000",                PrecisionFormat.eDecimal4Places,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1000.00000mm",           PrecisionFormat.eDecimal5Places,  True,       True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:0.0",              PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1.0",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10200,        "1.0",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10400,        "1.0",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10499,        "1.0",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10500,        "1.1",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10501,        "1.1",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10600,        "1.1",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10700,        "1.1",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10800,        "1.1",                    PrecisionFormat.eDecimal1Place,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])

def test_Format_TestLeadingTrailingZeros(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray =  [
        #uor           value                      precision                   unitflag    leadingzero trailingzero  insertthousands  thousandssep  decimalseparator  suppresszeromaster  suppresszerosub  scalefactor format                master        sub         storage         uorperstorage   
        [ 1,            "0.00",                   PrecisionFormat.eDecimal2Places,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0.10",                   PrecisionFormat.eDecimal2Places,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1.0",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10.0",                   PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10",                     PrecisionFormat.eDecimalWhole,    False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10.0000",                PrecisionFormat.eDecimal4Places,  False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1000.00000mm",           PrecisionFormat.eDecimal5Places,  True,       True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:0.0",              PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1.0",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10200,        "1.0",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10400,        "1.0",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10499,        "1.0",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10500,        "1.1",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10501,        "1.1",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10600,        "1.1",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10700,        "1.1",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ 10800,        "1.1",                    PrecisionFormat.eDecimal1Place,   False,      True,       True,         False,           ',',          '.',              False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],	
        ]
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])


def test_Format_TestLeadingTrailingZeros(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray =  [
        #uor           value            precision                   unitflag    leadingzero trailingzero    insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor format                master        sub         storage         uorperstorage   
        [ 100000,       "10.0",         PrecisionFormat.eDecimal1Place,  False,      True,       True,           False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 100000,       "10",           PrecisionFormat.eDecimal1Place,  False,      True,       False,          False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:0.000",  PrecisionFormat.eDecimal3Places,  False,      True,       True,           False,           ',',          '.',        False,              False,           0.0,       DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:.000",   PrecisionFormat.eDecimal3Places,  False,      False,      True,           False,           ',',          '.',        False,              False,           0.0,       DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:0",      PrecisionFormat.eDecimal3Places,  False,      True,       False,          False,           ',',          '.',        False,              False,           0.0,       DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "0:100:0",      PrecisionFormat.eDecimal3Places,  False,      False,      False,          False,           ',',          '.',        False,              False,           0.0,       DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        ] 
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])


def test_Format_TestThousandsDecimalSeparator(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray =  [
        #uor           value                                       precision                   unitflag    leadingzero trailingzero  insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor format             master        sub         storage         uorperstorage   
        [ 10000000,     "1000.000m",                     PrecisionFormat.eDecimal3Places,  True,       True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000000,     "1,000.000m",                    PrecisionFormat.eDecimal3Places,  True,       True,       True,         True,            ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000000,     "1`000^000m",                    PrecisionFormat.eDecimal3Places,  True,       True,       True,         True,            '`',          '^',        False,              False,           0.0,        DgnUnitFormat.eMU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1,000.000mm",                   PrecisionFormat.eDecimal3Places,  True,       True,       True,         True,            ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eSU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1`000^000mm",                   PrecisionFormat.eDecimal3Places,  True,       True,       True,         True,            '`',          '^',        False,              False,           0.0,        DgnUnitFormat.eSU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000000,     "1000m 0.000mm",                 PrecisionFormat.eDecimal3Places,  True,       True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMUSU,  masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000000,     "1,000m 0.000mm",                PrecisionFormat.eDecimal3Places,  True,       True,       True,         True,            ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMUSU,  masterUnits,  subUnits,   storageUnits,   10000 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])


def test_Format_TestSuppressZeroMasterSubUnits(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray =  [
        # uor          value                    precision                   unitflag  leadingzero trailingzero    insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor format                master        sub         storage         uorperstorage   
        [ 1000,         ":100.000",             PrecisionFormat.eDecimal3Places,  False,    True,       True,           False,           ',',          '.',        True,               False,           0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         " 100.000mm", PrecisionFormat.eDecimal3Places,  True,     True,       True,           False,           ',',          '.',        True,               False,           0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1:",                   PrecisionFormat.eDecimal3Places,  False,    True,       True,           False,           ',',          '.',        False,              True,            0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 10000,        "1m ",    PrecisionFormat.eDecimal3Places,  True,     True,       True,           False,           ',',          '.',        False,              True,            0.0,        DgnUnitFormat.eMUSU,     masterUnits,  subUnits,   storageUnits,   10000 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])

def test_Format_TestScientific(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray =  [
           #uor           value                                    precision           unitflag  leadingzero trailingzero  insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor       format             master        sub         storage         uorperstorage   
        [ 1000000,      "1.000E+02m" ,                PrecisionFormat.eScientific3Places,  True,     True,       True,         True,            ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000000,      "1.000E+05mm",                PrecisionFormat.eScientific3Places,  True,     True,       True,         True,            ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eSU,    masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000000,      "100m 0.000mm",               PrecisionFormat.eScientific3Places,  True,     True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMUSU,  masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000000,      "100:0.000",                  PrecisionFormat.eDecimal3Places,     False,    True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMUSU,  masterUnits,  subUnits,   storageUnits,   10000 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])

def test_Format_TestFractions(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray = [
        #uor           value                                       precision                      unitflag  leadingzero trailingzero  insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor format            master        sub         storage         uorperstorage   
        [ 10000,        "1",                                       PrecisionFormat.eFractionalWhole,    False,    True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 15000,        "1 1/2",                                   PrecisionFormat.eFractionalHalf,     False,    True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 15000,        "1 1/2",                                   PrecisionFormat.eFractionalQuarter,  False,    True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 17500,        "2",                                       PrecisionFormat.eFractionalHalf,     False,    True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 105555,       "10m 555 1/2mm",                           PrecisionFormat.eFractionalQuarter,  True,     True,       True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMUSU, masterUnits,  subUnits,   storageUnits,   10000 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])

def test_Format_TestScaleFactor(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray = [
        #uor           value                   precision                   unitflag  leadingzero trailingzero  insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor format                master        sub         storage         uorperstorage   
        [ 1000,         "100.000",             PrecisionFormat.eDecimal3Places,  False,    True,       True,         False,           ',',          '.',        False,              False,           1.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "200.000",             PrecisionFormat.eDecimal3Places,  False,    True,       True,         False,           ',',          '.',        False,              False,           2.0,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000,         "50.000",              PrecisionFormat.eDecimal3Places,  False,    True,       True,         False,           ',',          '.',        False,              False,           0.5,        DgnUnitFormat.eSU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 15645554,     "3129.111m",           PrecisionFormat.eDecimal3Places,  True,     True,       True,         False,           ',',          '.',        False,              False,           2,          DgnUnitFormat.eMU,       masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000000,      "50:0:0.000",          PrecisionFormat.eDecimal3Places,  False,    True,       True,         False,           ',',          '.',        False,              False,           0.5,        DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        [ 1000000,      "200:0:0.000",         PrecisionFormat.eDecimal3Places,  False,    True,       True,         False,           ',',          '.',        False,              False,           2,          DgnUnitFormat.eMUSUPU,   masterUnits,  subUnits,   storageUnits,   10000 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatDistanceTest(testDataArray[i])


def doFormatPointTest(testData):

    formatter = PointFormatter.Create()
    formatter.GetDistanceFormatter().SetWorkingUnits(testData[13], testData[14])
    formatter.GetDistanceFormatter().SetStorageUnit(testData[15], testData[16])
    formatter.GetDistanceFormatter().SetUnitFormat (testData[12])
    formatter.GetDistanceFormatter().SetPrecision (testData[2])
    formatter.GetDistanceFormatter().SetUnitLabelFlag (testData[3])
    formatter.GetDistanceFormatter().SetLeadingZero (testData[4])
    formatter.GetDistanceFormatter().SetTrailingZeros (testData[5])
    formatter.GetDistanceFormatter().SetInsertThousandsSeparator (testData[6])
    formatter.GetDistanceFormatter().SetThousandsSeparator (testData[7])
    formatter.GetDistanceFormatter().SetDecimalSeparator (testData[8])
    formatter.GetDistanceFormatter().SetSuppressZeroMasterUnits (testData[9])
    formatter.GetDistanceFormatter().SetSuppressZeroSubUnits (testData[10])
    formatter.GetDistanceFormatter().SetScaleFactor (testData[11])

    formatter.SetIs3d (False)

    outputStr = formatter.ToString (testData[0])

    assert testData[1] == repr(outputStr)

def test_Format_TestGeneral(initDgnPlatformHost):  

    masterUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters)
    subUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters )
    storageUnits = UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 1.0, "")

    testDataArray = [
        #point                       value             precision                   unitflag  leadingzero  trailingzero  insertthousands  thousandssep  decimalsep  suppresszeromaster  suppresszerosub  scalefactor format            masterunits   subunits    storageunis     uorperstorage   
        [ DPoint3d(0,0,0),          "0, 0",          PrecisionFormat.eDecimalWhole,    False,    True,        True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,   masterUnits,  subUnits,   storageUnits,   10000 ],	
        [ DPoint3d(1000,5000,0),    "0.100, 0.500",  PrecisionFormat.eDecimal3Places,  False,    True,        True,         False,           ',',          '.',        False,              False,           0.0,        DgnUnitFormat.eMU,   masterUnits,  subUnits,   storageUnits,   10000 ],	
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatPointTest(testDataArray[i])


def doFormatAreaTest(testData):

    formatter = AreaFormatter.Create()

    formatter.SetPrecision                     (testData[2])
    formatter.SetShowUnitLabel                 (testData[3])
    formatter.SetLeadingZero                   (testData[4])
    formatter.SetTrailingZeros                 (testData[5])
    formatter.SetInsertThousandsSeparator      (testData[6])
    formatter.SetThousandsSeparator            (testData[7])
    formatter.SetDecimalSeparator              (testData[8])
    formatter.SetScaleFactor                   (testData[9])
    formatter.SetMasterUnit                    (testData[10])
    formatter.SetStorageUnit                   (testData[11], testData[12])

    outputStr = formatter.ToString (testData[1])

    assert testData[0] == repr(outputStr)

def test_Format_TestGeneral(initDgnPlatformHost):  

    masterUnits  = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters             )
    storageUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters             )

    testDataArray =  [
        #expected              value             precision                   showLabel leadingzero  trailingzero  insertthousands  thousandssep  decimalsep  scalefactor masterunits   storageunits    uorperstorage
        [ "1",                 100000000.0,              PrecisionFormat.eDecimalWhole,    False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "1m2",               100000000.0,              PrecisionFormat.eDecimalWhole,    True,     True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "1.000",             100000000.0,              PrecisionFormat.eDecimal3Places,  False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "1.000m2",           100000000.0,              PrecisionFormat.eDecimal3Places,  True,     True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "25",                2500000000.0,             PrecisionFormat.eDecimalWhole,    False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "25.000",            2500000000.0,             PrecisionFormat.eDecimal3Places,  False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatAreaTest(testDataArray[i])

def test_Format_TestUnitsAndScales(initDgnPlatformHost):

    meters       = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters             )
    millimeters  = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters        )
    feet         = UnitDefinition.GetStandardUnit (StandardUnit.eEnglishFeet              )
    inches       = UnitDefinition.GetStandardUnit (StandardUnit.eEnglishInches            )

    testDataArray =  [
        #expected          value             precision                   showabel leadingzero  trailingzero  insertthousands  thousandssep  decimalsep  scalefactor masterunits   storageunits    uorperstorage
        #A Cube 2m x 2m = 4m2 = 2000mm * 2000mm = 4E6mm2 = 2E5 uor x 2E5 uor = 4E10 uor2*/
        [ "4000000.0",     40000000000.0,             PrecisionFormat.eDecimal1Place,  False,    True,        True,         False,           ',',          '.',        1.0,        millimeters,  millimeters,    100 ],
        [ "4.0",           40000000000.0,             PrecisionFormat.eDecimal1Place,  False,    True,        True,         False,           ',',          '.',        1.0,        meters,       millimeters,    100 ],
        # A Cube 1ft x 1ft = 1ft2 = 12in * 12in = 144in2 = 1200 uor x 1200 uor = 1.44E6 uor2*/
        [ "144.0",         1440000.0,                 PrecisionFormat.eDecimal1Place,  False,    True,        True,         False,           ',',          '.',        1.0,        inches,       inches,         100 ],
        [ "1.0",           1440000.0,                 PrecisionFormat.eDecimal1Place,  False,    True,        True,         False,           ',',          '.',        1.0,        feet,         inches,         100 ],
        ]

    
    for i in range (0,len(testDataArray)):
        doFormatAreaTest(testDataArray[i])


def doFormatVolumeTest(testData):

    formatter = VolumeFormatter.Create()

    formatter.SetPrecision                     (testData[2])
    formatter.SetShowUnitLabel                 (testData[3])
    formatter.SetLeadingZero                   (testData[4])
    formatter.SetTrailingZeros                 (testData[5])
    formatter.SetInsertThousandsSeparator      (testData[6])
    formatter.SetThousandsSeparator            (testData[7])
    formatter.SetDecimalSeparator              (testData[8])
    formatter.SetScaleFactor                   (testData[9])
    formatter.SetMasterUnit                    (testData[10])
    formatter.SetStorageUnit                   (testData[11], testData[12])

    outputStr = formatter.ToString (testData[1])

    assert testData[0] == repr(outputStr)

def test_Format_TestGeneral(initDgnPlatformHost):  

    masterUnits  = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters             )
    storageUnits = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters             )

    testDataArray =  [
        #expected               value              precision                   showLabel leadingzero  trailingzero  insertthousands  thousandssep  decimalsep  scalefactor masterunits   storageunits    uorperstorage
        [ "1",                  1E12,              PrecisionFormat.eDecimalWhole,    False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "1m3",                1E12,              PrecisionFormat.eDecimalWhole,    True,     True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "1.000",              1E12,              PrecisionFormat.eDecimal3Places,  False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "1.000m3",            1E12,              PrecisionFormat.eDecimal3Places,  True,     True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "25",                 25E12,             PrecisionFormat.eDecimalWhole,    False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        [ "25.000",             25E12,             PrecisionFormat.eDecimal3Places,  False,    True,        True,         False,           ',',          '.',        1.0,        masterUnits,  storageUnits,   10000.0 ],
        ]
    
    for i in range (0,len(testDataArray)):
        doFormatVolumeTest(testDataArray[i])

    def test_Format_TestGeneral(initDgnPlatformHost):  

        meters       = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMeters             )
        millimeters  = UnitDefinition.GetStandardUnit (StandardUnit.eMetricMillimeters        )
        feet         = UnitDefinition.GetStandardUnit (StandardUnit.eEnglishFeet              )
        inches       = UnitDefinition.GetStandardUnit (StandardUnit.eEnglishInches            )

        testDataArray = [
        #expected          value             precision                   showLabel leadingzero  trailingzero  insertthousands  thousandssep  decimalsep  scalefactor masterunits   storageunits    uorperstorage
        # A Cube 20000 uor x 20000 uor x 20000 uor = 8E12 uor3 = 200mm x 200mm x 200mm = 8E6mm3 =  0.2m x 0.2m x 0.2m = 8E-3 m3*/
        [ "8,000,000.0",   8E12,             PrecisionFormat.eDecimal1Place,   False,    True,        True,         True,            ',',          '.',        1.0,        millimeters,  millimeters,    100 ],
        [ "0.008",         8E12,             PrecisionFormat.eDecimal3Places,  False,    True,        True,         True,            ',',          '.',        1.0,        meters,       millimeters,    100 ],
        # Under an ACS with scale 2, the same cube is 100mm x 100mm x 100mm = 1E6mm3 */
        [ "1,000,000.0",   8E12,             PrecisionFormat.eDecimal1Place,   False,    True,        True,         True,            ',',          '.',        2.0,        millimeters,  millimeters,    100 ],
        [ "0.001",         8E12,             PrecisionFormat.eDecimal3Places,  False,    True,        True,         True,            ',',          '.',        2.0,        meters,       millimeters,    100 ],
        # A Cube 1 ft x 1 ft x 1 ft = 12 in x 12 in x 12 in = 1728 in3 = 1200 uor x 1200 uor x 1200 uor = 1728E6 uor3 */
        [ "1,728.0",       1728E6,           PrecisionFormat.eDecimal1Place,   False,    True,        True,         True,            ',',          '.',        1.0,        inches,       inches,         100 ],
        [ "1.0",           1728E6,           PrecisionFormat.eDecimal1Place,   False,    True,        True,         True,            ',',          '.',        1.0,        feet,         inches,         100 ],
        # Under an ACS with scale 2, the same cube is 0.5 ft x 0.5 ft x 0.5 ft = 0.125 ft3 = 6 in x 6 in x 6 in = 216 in3 */
        [ "216.0",         1728E6,           PrecisionFormat.eDecimal1Place,   False,    True,        True,         True,            ',',          '.',        2.0,        inches,       inches,         100 ],
        [ "0.125",         1728E6,           PrecisionFormat.eDecimal3Places,  False,    True,        True,         True,            ',',          '.',        2.0,        feet,         inches,         100 ],
        ]

        for i in range (0,len(testDataArray)):
            doFormatVolumeTest(testDataArray[i])