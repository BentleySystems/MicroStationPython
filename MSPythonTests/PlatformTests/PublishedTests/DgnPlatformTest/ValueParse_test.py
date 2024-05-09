import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

EPSILON = 0.000000001
PI = 3.1415926535897932384626433

DEG_TO_RAD = PI / 180

def RAD(x):
    return x * DEG_TO_RAD

def vp_createAngleValueFromMDS(deg, min1, sec):
    result = deg
    result = result + ( min1 * 1.0 / 60.0 )
    result = result + ( sec * 1.0 / 3600.0 )
    #print(result)
    return result

def vp_createAngleValueFromRadians(rad):
    return rad * 180.0 / PI

def vp_createAngleValueFromGradians(cent):
    return cent * 90.0 / 100.0

def vp_createUnitValue( master, sub, a):
    return master * 1000.0 + sub * 1.0 + a
     

def vp_createParsedPointValue (x,y,z):
    result = DPoint3d ()
    result.Init(x, y, z)
    return result

def vp_doParseAngleTest(mode, testData):
    parser = AngleParser()
    parser.SetAngleMode(mode)
    print(mode)
    val = parser.ToValue(testData[0])
    assert BentleyStatus.eSUCCESS == val[0]
    
    # print(val[1])
    # print(angle)
    # print(testData[0])
    # print(testData[1])
    if AngleMode.eRadians == mode:
        diff = abs(RAD(val[1]) - RAD (testData[1]))
        assert diff <= EPSILON
    else:
        diff = abs(val[1] - testData[1])
        assert diff <= EPSILON
    
def vp_doParseDirectionTest(mode, testData, trueNorth = 0.0):
    parser = DirectionParser()
    parser.GetAngleParser().SetAngleMode(mode)
    
    if( trueNorth != 0.0 ):
        parser.SetTrueNorthValue(trueNorth)
        
    val = parser.ToValue(testData[0])
    if AngleMode.eRadians == mode:
        diff = abs(RAD(val[1]) - RAD(testData[1]))
        assert diff <= EPSILON
    else:
        diff = abs(val[1] - testData[1])
        assert diff <= EPSILON
    
def vp_doParseUnitTest(testData):
    parser = DistanceParser()
    parser.SetMasterUnitLabel("m")
    parser.SetSubUnitLabel("mm")
    parser.SetMasterUnitScale(1000.0)
    parser.SetSubUnitScale(1.0)
    
    val = parser.ToValue(testData[0])
    assert BentleyStatus.eSUCCESS == val[0]
    
    diff = abs(val[1] - testData[1])
    assert diff <= EPSILON

def vp_doParsePointTest(testData):
    parser = PointParser()

    parser.GetDistanceParser().SetMasterUnitLabel   ("m")
    parser.GetDistanceParser().SetSubUnitLabel      ("mm")
    parser.GetDistanceParser().SetMasterUnitScale   (1000.0)
    parser.GetDistanceParser().SetSubUnitScale      (1.0)
    parser.GetDistanceParser().SetScale (testData[4])
    parser.SetIs3d (testData[3])

    ptValue = DPoint3d()
    retVal = parser.ToValue (ptValue, testData[0])

    if (testData[2] == False):
        
        assert 0 != retVal
        return
            
    assert 0 == retVal

    expected = DPoint3d ()
    expected.Init (testData[1].x * testData[4], testData[1].y * testData[4],  testData[1].z)

    if (testData[3]):
        expected.z *= testData[4] 

    assert(ptValue == (expected)) #<< testData.m_inputString;

def vp_doParseValueTest(testData):
    parser = DoubleParser()
    val = parser.ToValue (testData[0])
    assert BentleyStatus.eSUCCESS == val[0]
    diff = abs(val[1]- testData[1])
    assert diff <= EPSILON          

def test_ParseSimple_AngleParser():
    testDataArray = [
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30^", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30^20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20'", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20'10", vp_createAngleValueFromMDS(30, 20, 10)),
        ("30^20'10\"", vp_createAngleValueFromMDS(30, 20, 10)),
        
        ("30^10\"", vp_createAngleValueFromMDS(30, 0, 10)),
        
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30:", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30:20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30:20:", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30:20:10", vp_createAngleValueFromMDS(30, 20, 10)),
        
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30d", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30d20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30d20m", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30d20m10", vp_createAngleValueFromMDS(30, 20, 10)),
        ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eDegMinSec, i)
        
def test_ParseSimple_DirectionParser():
    testDataArray = [
        ("north", vp_createAngleValueFromMDS(90, 0, 0)),
        ("NORTH   ", vp_createAngleValueFromMDS(90, 0, 0)),
        ("  north   ", vp_createAngleValueFromMDS(90, 0, 0)),
        ("south", vp_createAngleValueFromMDS(270, 0, 0)),
        ("sOUth ", vp_createAngleValueFromMDS(270, 0, 0)),
        ("  south   ", vp_createAngleValueFromMDS(270, 0, 0)),
        
        ("East ", vp_createAngleValueFromMDS(0, 0, 0)),
        ("10  east   ", vp_createAngleValueFromMDS(10, 0, 0)),
        
        ("west ", vp_createAngleValueFromMDS(180, 0, 0)),
        ("n 10  west   ", vp_createAngleValueFromMDS(100, 0, 0)),
        
        ("n=23West", vp_createAngleValueFromMDS(113, 0, 0)),
        ("n/23Wes", vp_createAngleValueFromMDS(113, 0, 0)),
        
        ("n=23East", vp_createAngleValueFromMDS(67, 0, 0)),
        ("n/23Ea", vp_createAngleValueFromMDS(67, 0, 0)),
        
        ("north 23W", vp_createAngleValueFromMDS(113, 0, 0)),
        ("north 23^W", vp_createAngleValueFromMDS(113, 0, 0)),
        ("South 3^20e", vp_createAngleValueFromMDS(273, 20, 0)),
        ("South 3^20W", vp_createAngleValueFromMDS(266, 40, 0)),
        
        ("north 23W", vp_createAngleValueFromMDS(113, 0, 0)),
        ("north 23^W", vp_createAngleValueFromMDS(113, 0, 0)),
        ("South 3^20W", vp_createAngleValueFromMDS(266, 40, 0)),
        
        ("north=23W", vp_createAngleValueFromMDS(113, 0, 0)),
        ("north/23W", vp_createAngleValueFromMDS(113, 0, 0)),
        
        ("north=23West", vp_createAngleValueFromMDS(113, 0, 0)),
        ("north/23Wes", vp_createAngleValueFromMDS(113, 0, 0)),
    ]
    
    for i in testDataArray:
        vp_doParseDirectionTest(AngleMode.eDegMinSec, i)        

def test_ParseSimpleTrueNorth():
    testDataArray = [
        ("north", vp_createAngleValueFromMDS(91, 0, 0)),
        ("NORTH   ", vp_createAngleValueFromMDS(91, 0, 0)),
        ("  north   ", vp_createAngleValueFromMDS(91, 0, 0)),
        ("south", vp_createAngleValueFromMDS(271, 0, 0)),
        ("sOUth ", vp_createAngleValueFromMDS(271, 0, 0)),
        ("  south   ", vp_createAngleValueFromMDS(271, 0, 0)),
        
        ("East ", vp_createAngleValueFromMDS(1, 0, 0)),
        ("10  east   ", vp_createAngleValueFromMDS(11, 0, 0)),
        
        ("west ", vp_createAngleValueFromMDS(181, 0, 0)),
        ("n 10  west   ", vp_createAngleValueFromMDS(101, 0, 0)),
        
        ("n=23West", vp_createAngleValueFromMDS(114, 0, 0)),
        ("n/23Wes", vp_createAngleValueFromMDS(114, 0, 0)),
        
        ("n=23East", vp_createAngleValueFromMDS(68, 0, 0)),
        ("n/23Ea", vp_createAngleValueFromMDS(68, 0, 0)),
        
        ("north 23W", vp_createAngleValueFromMDS(114, 0, 0)),
        ("north 23^W", vp_createAngleValueFromMDS(114, 0, 0)),
    ]
    
    for i in testDataArray:
        vp_doParseDirectionTest(AngleMode.eDegMinSec, i, 1.0)   

def test_ParseSimpleAnglesOnly():
    testDataArray = [
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30^20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20'", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20'10", vp_createAngleValueFromMDS(30, 20, 10)),
        ("30^20'10\"", vp_createAngleValueFromMDS(30, 20, 10)),
        
        ("30^10\"", vp_createAngleValueFromMDS(30, 0, 10)),
        
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30:", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30:20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30:20:", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30:20:10", vp_createAngleValueFromMDS(30, 20, 10)),
        
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30d", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30d20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30d20m", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30d20m10", vp_createAngleValueFromMDS(30, 20, 10)),
        ]
    
    for i in testDataArray:
        vp_doParseDirectionTest(AngleMode.eDegMinSec, i)

def test_ParseSimple_Whitespace():
    testDataArray = [
        ("30", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30^", vp_createAngleValueFromMDS(30, 0, 0)),
        ("30^20", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20'", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20'10", vp_createAngleValueFromMDS(30, 20, 10))
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eDegrees, i)
        
def test_ParseDecimalsInvolved():
    testDataArray = [
        ("30.5", vp_createAngleValueFromMDS(30, 30, 0)),
        ("30.5^", vp_createAngleValueFromMDS(30, 30, 0)),
        ("30.5^30", vp_createAngleValueFromMDS(31, 0, 0)),
        ("30^20'", vp_createAngleValueFromMDS(30, 20, 0)),
        ("30^20.5'10", vp_createAngleValueFromMDS(30, 20, 40)),
        ("30.5^20'10.5\"", vp_createAngleValueFromMDS(30, 50, 10.5)),
        
        ("30.5:20:10.5", vp_createAngleValueFromMDS(30, 50, 10.5)),
        ("30.5d20m10.5", vp_createAngleValueFromMDS(30, 50, 10.5)),
        ("0d0m10 1/4", vp_createAngleValueFromMDS(0, 0, 10.25)),
        ("30 1/2d20m10 1/4", vp_createAngleValueFromMDS(30, 50, 10.25))
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eDegMin, i)
        
        
def test_ParseFractions():
    testDataArray = [
        ("1/2^2\"", vp_createAngleValueFromMDS(0, 30, 2)),
        ("10 1/2^2\"", vp_createAngleValueFromMDS(10, 30, 2)),
        ("1/2^2\"", vp_createAngleValueFromMDS(0, 30, 2)),
        ("0^1/2\"", vp_createAngleValueFromMDS(0, 0, 0.5)),
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eDegMin, i)
        
def test_ParseSimple_Radians():
    testDataArray = [
        ("0", vp_createAngleValueFromMDS(0, 0, 0)),
        ("3.1415926535r", vp_createAngleValueFromMDS(180, 0, 0)),
        ("3.1415926535", 180.0),
        ("3.1415926535", vp_createAngleValueFromRadians(3.1415926535)),
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eRadians, i)
        
def test_ParseSimple_Radians_Fractions():
    testDataArray = [
        ("0", vp_createAngleValueFromMDS(0, 0, 0)),
        ("1 1/2", vp_createAngleValueFromRadians(1.5)),
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eRadians, i)
        

def test_ParseSimple_Gradians():
    testDataArray = [
        ("0", vp_createAngleValueFromMDS(0, 0, 0)),
        ("100.0", vp_createAngleValueFromGradians(100.0)),
        ("100.0g", vp_createAngleValueFromGradians(100.0)),
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eCentesimal, i)
        
def test_ParseSimpleWhiteSpaceInBetween():
    testDataArray = [
        #Previously this test expected the whitespace to cause the 20' to be ignored, resulting in a parsed value of 30.0
        #After fixing TFS#94364, the whitespace is ignored and the 20' successfully parsed. This seems like an improvement. So now we expect parsed value of 30.333..
        (" 30^ 20' ", vp_createAngleValueFromMDS(30, 20, 0)),
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eDegMin, i)
        
def test_ParseSimple_DegreeSymbol():
    deg1 = WString("30")
    degSymbol = chr(eSPECIALCHAR_Degree_Unicode)
    deg1 += WString(degSymbol)
    deg1 += WString("20'10\"")
    deg2 = WString("30")
    deg2 += WString(degSymbol)
    deg2 += WString("20'10")
    
    testDataArray = [
        (repr(deg1), vp_createAngleValueFromMDS(30, 20, 10)),
        (repr(deg2), vp_createAngleValueFromMDS(30, 20, 10)),
    ]
    
    for i in testDataArray:
        vp_doParseAngleTest(AngleMode.eDegMin, i)


def test_ParseSimple_DistanceParser():
    testDataArray = [
        ("112", vp_createUnitValue(112, 0, 0),       3),
        ("1..10..0", vp_createUnitValue(1, 10, 0),   8),
        ("1:10:0", vp_createUnitValue(1, 10, 0),     6),
        ("1;10;1", vp_createUnitValue(1, 10, 1),     6),
        ("1m10mm1", vp_createUnitValue(1, 10, 0),    7),
        (" 1m-10mm", vp_createUnitValue(1, 10, 0),   8),
        ("1:-10:0", vp_createUnitValue(-1, -10, 0),  7),
        ("-1:-10:0", vp_createUnitValue(-1, -10, 0), 8),
        ("1'10\"0", vp_createUnitValue(1, 0, 0),     6),
        ("1/10", vp_createUnitValue(0, 100, 0),      5),
    ]
    
    for i in testDataArray:
        vp_doParseUnitTest(i)
    
def test_ParseScientific():
    testDataArray = [
        (" 1.5E0", vp_createUnitValue(1.5, 0, 0),     6),
        ("1.5E", vp_createUnitValue(1.5, 0, 0),      -1),
        ("1.5E1", vp_createUnitValue(15.0, 0, 0),     5),
        ("1.5E-1", vp_createUnitValue(0.15, 0, 0),    6),
        ("-1.5E-1", vp_createUnitValue(-0.15, 0, 0),  7),
    ]
    
    for i in testDataArray:
        vp_doParseUnitTest(i)


def test_ParseSimple_PointParser():
    testDataArray = [
        [ "0m0mm,0m0mm,0m0mm",    vp_createParsedPointValue  (0.0, 0.0, 0.0),     True, True, 1.0], 
        [ "0m0mm,0m0mm,1m0mm",    vp_createParsedPointValue  (0.0, 0.0, 1000.0),  True, True, 1.0], 
        [ "0m0mm,0m0mm,-1m1mm",   vp_createParsedPointValue  (0.0, 0.0, -1001.0), True, True, 1.0], 
        [ " 0m0mm,0m0mm,-1m1mm",  vp_createParsedPointValue  (0.0, 0.0, -1001.0), True, True, 1.0] 
    ]
    for i in range (0,len(testDataArray)):
        vp_doParsePointTest(testDataArray[i])

def test_ParseSimple_ValueParser():
    testDataArray = [
        [ "0",                 0.0],
        [ "0.0",               0.0],
        [ "0.25",              0.25],
        [ "   20343.00   ",    20343.0],          # old behavior would have not parsed this.
        [ "20343.00   ",       20343.0],
        [ "100 1/4",           100.25],
        [ "100.5 1/4",         100.75]
    ]

    for i in range (0,len(testDataArray)):
        vp_doParseValueTest(testDataArray[i])
        
def test_ParseSimple2dLegacy():
    testDataArray = [
        ("0m0mm,0m0mm", vp_createParsedPointValue(0.0, 0.0, 0.0), True, False, 1.0),
        ("0m1mm,1m0mm", vp_createParsedPointValue(1.0, 1000.0, 0.0), True, False, 0.5),
        ("0m1mm,-1m0mm", vp_createParsedPointValue(1.0, -1000.0, 0.0), True, False, 2.0),
    ]
    
    for i in testDataArray:
        vp_doParsePointTest(i)
        
def test_TestCoordSplitting():
    testDataArray = [
        ("1,2,3",       vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True, True, 1.0),
        (" 1, 2, 3",    vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True, True, 1.0),
        (" 1 , 2 , 3 ", vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True, True, 1.0),
        ("  1,  2,  3", vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True, True, 1.0),
        ("\t1,\t2,\t3", vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True, True, 1.0),
        ("1,2",         vp_createParsedPointValue(1000.0, 2000.0, 0), True, True, 1.0),
        ("1,2,",        vp_createParsedPointValue(1000.0, 2000.0, 0), True, True, 1.0),
        (" 1 , 2 , ",   vp_createParsedPointValue(1000.0, 2000.0, 0), True, True, 1.0),
    ]
    
    for i in testDataArray:
        vp_doParsePointTest(i)
        
        
def test_TestUnusualInputs():
    testDataArray = [
        ("a,2,3",        vp_createParsedPointValue(0, 0, 0),                False, True, 1.0),
        ("1,b,3",        vp_createParsedPointValue(0, 0, 0),                False, True, 1.0),
        ("1,2,c",        vp_createParsedPointValue(0, 0, 0),                False, True, 1.0),
        (" a , 2 , 3 ",  vp_createParsedPointValue(0, 0, 0),                False, True, 1.0),
        (" 1 , b , 3 ",  vp_createParsedPointValue(0, 0, 0),                False, True, 1.0),
        (" 1 , 2 , c ",  vp_createParsedPointValue(0, 0, 0),                False, True, 1.0),
        ("1, 2, 3, ABC", vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True,  True, 1.0),
        ("1, 2, 3,    ", vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True,  True, 1.0),
        ("1, 2, 3,",     vp_createParsedPointValue(1000.0, 2000.0, 3000.0), True,  True, 1.0),
    ]
    
    for i in testDataArray:
        vp_doParsePointTest(i)
        
def test_TestUnusualInputs2d():
    testDataArray = [
        ("a,2",       vp_createParsedPointValue(0, 0, 0),                False, False, 1.0),
        ("1,b",       vp_createParsedPointValue(0, 0, 0),                False, False, 1.0),
        (" a , 2 ",   vp_createParsedPointValue(0, 0, 0),                False, False, 1.0),
        (" 1 , b ",   vp_createParsedPointValue(0, 0, 0),                False, False, 1.0),
        ("1, 2, ABC", vp_createParsedPointValue(1000.0, 2000.0, 0.0),    True,  False, 1.0),
        ("1, 2,    ", vp_createParsedPointValue(1000.0, 2000.0, 0.0),    True,  False, 1.0),
        ("1, 2,",     vp_createParsedPointValue(1000.0, 2000.0, 0.0),    True,  False, 1.0),
    ]
    
    for i in testDataArray:
        vp_doParsePointTest(i)