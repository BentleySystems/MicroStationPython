import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

BentleyStatus.eERROR = 32768

def GenerateMeter_1_10():
    return UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 1.0, 10.0, "UnitDefinitionSeed1")


def GenerateDegree_1_10():
    return UnitDefinition (UnitBase.eDegree, UnitSystem.eEnglish, 1.0, 10.0, "UnitDefinitionSeed2")


def GenerateMeter_10_10():
    return UnitDefinition(UnitBase.eMeter, UnitSystem.eMetric, 10.0, 10.0, "UnitDefinitionSeed3")


def GenerateMeter_1Tenth_10():
    return UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 0.10, 10.0, "UnitDefinitionSeed4");


def GenerateMeter_0_0():
    return UnitDefinition (UnitBase.eMeter, UnitSystem.eMetric, 0.0, 0.0, "UnitDefinitionSeed5");


def test_DefaultConstructor():
    def1 = UnitDefinition()
    assert False == def1.IsValid()


def test_Constructor_UnitInfo():
    ui = UnitInfo()
    label = "seed"
    ui.label = label

    ui.denominator = 10.0
    ui.numerator = 1.0
    ui.flags.reserved = 0
    ui.flags.system = UnitSystem.eMetric
    ui.flags.base = UnitBase.eMeter
    def1 = UnitDefinition(ui)
    
    assert (ui.flags.base == int(def1.GetBase()) and
            ui.flags.system == int(def1.GetSystem()) and
            repr(def1.GetLabel()) == label and
            ui.denominator == def1.GetDenominator() and
            ui.numerator == def1.GetNumerator())


def test_IsEqual_True():
    s1 = GenerateMeter_1_10()
    same = GenerateMeter_1_10()
    assert True == ( same == s1 )


def test_IsEqual_False():
    s2 = GenerateDegree_1_10()
    assert False == ( GenerateMeter_1_10() == s2 )


def test_AreComparable_True():
    s3 = GenerateMeter_10_10()
    assert True == ( GenerateMeter_1_10().AreComparable(s3) )


def test_AreComparable_False():
    s2 = GenerateDegree_1_10()
    assert False == ( GenerateMeter_1_10().AreComparable(s2) )


def test_AreComparable_False2():
    s5 = GenerateMeter_0_0()
    assert False == ( GenerateMeter_1_10().AreComparable(s5) )


def test_IsValid_True():
    s1 = GenerateMeter_1_10()
    s2 = GenerateDegree_1_10()
    s3 = GenerateMeter_10_10()
    
    assert True == ( s1.IsValid() and s2.IsValid() and s3.IsValid() )


def test_IsValid_False():
    assert False == ( GenerateMeter_0_0().IsValid() )


def test_CompareByScale_Error():
    s1 = GenerateMeter_1_10()
    s2 = GenerateDegree_1_10()
    
    assert True == ( BentleyStatus.eERROR == s1.CompareByScale(s2) )


def test_ComapreByScale_Neg1():
    s1 = GenerateMeter_1_10()
    s3 = GenerateMeter_10_10()
    
    assert -1 == ( s1.CompareByScale(s3) )
    

def test_CompareByScale_0():
    s1 = GenerateMeter_1_10()
    s  = GenerateMeter_1_10()
    
    assert 0 == ( s1.CompareByScale(s) )


def test_CompareByScale_1():
    s1 = GenerateMeter_1_10()
    s4 = GenerateMeter_1Tenth_10()
    
    assert 1 == ( s1.CompareByScale(s4) )


def test_GetConversionFactorFrom_ERROR():
    result = 0.0
    s1 = GenerateMeter_1_10()
    s2 = GenerateDegree_1_10()
    
    assert True == ( BentleyStatus.eERROR == s1.GetConversionFactorFrom(s2)[0] )


def test_GetConversionFactorFrom():
    s1 = GenerateMeter_1_10()
    s3 = GenerateMeter_10_10()
    result = s3.GetConversionFactorFrom(s1)

    diff = abs(10.0 - result[1])
    assert diff <= 0.0000001


def test_ConvertDistanceFrom_ERROR():
    result = 0.0
    inp = 0.0
    s1 = GenerateMeter_1_10()
    s2 = GenerateDegree_1_10()
    
    assert True == ( BentleyStatus.eERROR == s1.ConvertDistanceFrom(inp,s2)[0] )

def test_ConvertDistanceFrom():
    s1 = GenerateMeter_1_10()
    s3 = GenerateMeter_10_10()
    
    result = s3.ConvertDistanceFrom(5.0,s1)
    diff = abs(50.0 - result[1])
    assert diff <= 0.0000001

def test_AssignLabel():
    label = "TestLabel"
    def1 = UnitDefinition()
    def1.SetLabel(label)

    assert repr(def1.GetLabel()) == label
