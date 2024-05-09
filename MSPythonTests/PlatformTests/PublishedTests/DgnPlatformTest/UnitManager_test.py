import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *


def test_GetStandardUnit(initDgnPlatformHost):
    def1 = UnitDefinition()
    def1 = UnitDefinition.GetStandardUnit(StandardUnit.eMetricMeters)
    assert True == ( 1.0 == def1.GetDenominator() and
                    1.0 == def1.GetNumerator() and
                    UnitBase.eMeter == def1.GetBase() and
                    UnitSystem.eMetric == def1.GetSystem() )


def test_GetStandardUnit_NULL():
    def1 = UnitDefinition()
    def1 = UnitDefinition.GetStandardUnit(StandardUnit(0))
    
    assert True == ( False == def1.IsValid() )


def test_GetStandardUnitByName(initDgnPlatformHost):
    def1 = UnitDefinition()
    
    buffer1 = "meter"
    def1 = UnitDefinition.GetStandardUnitByName (buffer1)
    
    assert True == ( 1.0 == def1.GetDenominator() and
                    1.0 == def1.GetNumerator() and
                    UnitBase.eMeter == def1.GetBase() and
                    UnitSystem.eMetric == def1.GetSystem() )


def test_GetStandardUnitByName_None(initDgnPlatformHost):
    def1 = UnitDefinition()
    
    buffer1 = "none"
    def1 = UnitDefinition.GetStandardUnitByName (buffer1)
    
    assert True == ( False == def1.IsValid() )
    
    
def test_IsStandardUnit():
    def1 = UnitDefinition(UnitBase.eMeter, UnitSystem.eMetric, 100.0, 1.0,"def1")
    
    assert True == (StandardUnit.eMetricCentimeters == def1.IsStandardUnit())


def test_GetStandardLabel(initDgnPlatformHost):
    label = UnitDefinition.GetStandardLabel(StandardUnit.eAngleGrads)
    assert True == ( repr(label) == repr(WString("grad")) )
    
    
def test_GetStandardName(initDgnPlatformHost):
    name = UnitDefinition.GetStandardName(StandardUnit.eNoSystemLightYears, False)
    
    assert True == ( repr(name) == repr(WString("Light Years")) )
    
    
def test_GetStandardName_None(initDgnPlatformHost):
    name = UnitDefinition.GetStandardName(StandardUnit.eCustom, False)
    
    assert True == ( repr(name) == repr(WString("Custom")) )
    

def test_CreateStandardUnitIterator():
    options = UnitIteratorOptions()
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)
    
    unit0 = next(unitEntry)
    
    def1 = unit0.GetUnitDef()
    cmp1 = UnitDefinition.GetStandardUnit(StandardUnit.eMetricFemtometers)
    
    assert ( cmp1.GetDenominator() == def1.GetDenominator() and
             cmp1.GetNumerator() == def1.GetNumerator() and
             cmp1.GetBase() == def1.GetBase() and 
             cmp1.GetSystem() == def1.GetSystem() )

    
def test_ToNext_Ascending():
    options = UnitIteratorOptions()
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)

    firstEntry = next(unitEntry)
    assert True == (StandardUnit.eMetricFemtometers == firstEntry.GetNumber())
    
    secondEntry = next(unitEntry)    
    assert True == (StandardUnit.eMetricPicometers == secondEntry.GetNumber())
    

def test_ToNext_Descending(initDgnPlatformHost):
    options = UnitIteratorOptions()
    options.SetOrderDescending()
    
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)
    
    unit0 = next(unitEntry)
    assert StandardUnit.eUnitlessWhole == unit0.GetNumber()

    unit1 = next(unitEntry)
    assert StandardUnit.eAngleRadians == unit1.GetNumber()


def VerifyExpectedStandardUnits(options, searcharray):
    foundEntries = []
    collection = StandardUnitCollection(options)
    
    for standardUnit in collection:
        foundEntries.append(standardUnit)
           
    result = set(foundEntries).intersection(set(searcharray))
    
    return len(result) == 0
    

def test_SetAllowSingleBase(initDgnPlatformHost):
    options = UnitIteratorOptions()
    options.SetAllowSingleBase(UnitBase.eDegree)
    
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)
    
    unit0 = next(unitEntry)
    assert StandardUnit.eAngleSeconds == unit0.GetNumber()


def test_SetAllowAdditionalBase():
    options = UnitIteratorOptions()
    options.SetAllowSingleBase(UnitBase.eDegree)
    options.SetAllowAdditionalBase(UnitBase(0))
    
    validArray = [ StandardUnit.eUnitlessWhole,
                  StandardUnit.eAngleRadians, 
                  StandardUnit.eAngleDegrees, 
                  StandardUnit.eAngleGrads, 
                  StandardUnit.eAngleMinutes, 
                  StandardUnit.eAngleSeconds ]
    
    print(not VerifyExpectedStandardUnits(options, validArray))
    if (not VerifyExpectedStandardUnits(options, validArray)):
        assert False

def test_SetAllowAdditionalSystem():
    options = UnitIteratorOptions()
    options.SetAllowSingleBase(UnitBase.eMeter)
    options.SetAllowSingleSystem(UnitSystem.eUSSurvey)
    options.SetAllowAdditionalSystem(UnitSystem.eUndefined)
    
    validArray = [ StandardUnit.eEnglishSurveyMiles, 
                   StandardUnit.eEnglishFurlongs, 
                   StandardUnit.eEnglishChains,
                   StandardUnit.eEnglishRods, 
                   StandardUnit.eEnglishFathoms, 
                   StandardUnit.eEnglishSurveyFeet,
                   StandardUnit.eEnglishSurveyInches,
                   StandardUnit.eNoSystemAngstroms,
                   StandardUnit.eNoSystemNauticalMiles,
                   StandardUnit.eNoSystemAstronomicalUnits,
                   StandardUnit.eNoSystemLightYears,
                   StandardUnit.eNoSystemParsecs ]
    
    if not VerifyExpectedStandardUnits(options, validArray):
        assert False
        
        
def test_SetSizeCriteria(initDgnPlatformHost):
    def1 = UnitDefinition.GetStandardUnit(StandardUnit.eMetricNanometers)
    
    options = UnitIteratorOptions()
    options.SetSizeCriteria(def1, UnitIteratorOptions.UnitCompareMethod.eAllowSmallerOrEqual)
    options.SetAllowSingleBase(UnitBase.eMeter)
    options.SetAllowSingleSystem(UnitSystem.eMetric)
    
    validArray = [ StandardUnit.eMetricFemtometers,
                   StandardUnit.eMetricPicometers,
                   StandardUnit.eMetricNanometers ]
    
    if not VerifyExpectedStandardUnits(options, validArray):
        assert False


def test_GetUnitDef():
    options = UnitIteratorOptions()
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)
    
    unit0 = next(unitEntry)
    
    def1 = unit0.GetUnitDef()
    cmp1 = UnitDefinition.GetStandardUnit(StandardUnit.eMetricFemtometers)
    
    assert ( cmp1.GetDenominator() == def1.GetDenominator() and
             cmp1.GetNumerator() == def1.GetNumerator() and
             cmp1.GetBase() == def1.GetBase() and 
             cmp1.GetSystem() == def1.GetSystem() )



def test_GetNumber(initDgnPlatformHost):
    options = UnitIteratorOptions()
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)
    
    unit0 = next(unitEntry)
    assert StandardUnit.eMetricFemtometers == unit0.GetNumber()


def test_GetName(initDgnPlatformHost):
    options = UnitIteratorOptions()
    collection = StandardUnitCollection(options)
    
    unitEntry = iter(collection)
    
    unit0 = next(unitEntry)
    assert repr(unit0.GetName()) == repr(WString('Femtometers'))