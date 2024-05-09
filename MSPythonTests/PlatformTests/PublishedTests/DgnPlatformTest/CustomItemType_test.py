import os
import sys
import pytest
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

def AppendEncodedCharacter(encoded,c):
    buf = [""]*5
    opts = (1<<3) | (1<<2) 
    FormatUInt64 (buf, len(buf), c, opts, 4) #BeStringUtilities is not exposed
    encoded.AppendA ("__x")
    encoded.AppendA (buf) #list is not allowed
    encoded.AppendA ("__")

def IsValidAlphaNumericCharacter(c):
    return (((c >= '0' and c <= '9') or (c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or c == '_'))

def EncodeToValidName(encoded, name):
    encoded.clear()
    if (len(name) == 0):
        return False
    
    encoded.reserve (len(name)) #reserve is not defined
    wasEncoded = False

    startIndex = 0
    if ('0' <= name[0] and '9' >= name[0]):
        
        AppendEncodedCharacter (encoded, name[0])
        startIndex = 1
        wasEncoded = True

    for i in range(startIndex , len(name)):
        if (IsValidAlphaNumericCharacter (name[i]) == False):
            AppendEncodedCharacter (encoded, name[i])
            wasEncoded = True
        else:
            encoded.AppendA (1, name[i]) #only single parameter is allowed , not sure whether we need at that char at 1st position or not.

    return wasEncoded

def CreateLine(model, eeh,  x1,  y1,  x2,  y2):
    
    is3d = model.Is3d ()
    segment = DSegment3d(x1, y1, 0.0, x2, y2, 0.0)
    assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement (eeh, None, segment, is3d, model)
    assert BentleyStatus.eSUCCESS == eeh.AddToModel()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetItemTypeByInternalName(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    itemtypeLib = ItemTypeLibrary ("TestLibrary", srcDgnFile)
    itpFirst = itemtypeLib.AddItemType ("Test Type")
    prop = itpFirst.AddProperty ("FirstName")
    prop.SetType (CustomProperty.Type1.eString)
    assert True == itemtypeLib.Write ()

    enName = WString()
    ECNameValidation.EncodeToValidName(enName, (WString)("Test Type"))
    itp = itemtypeLib.GetItemTypeByInternalName(str(enName))
    assert itp != None
    assert "Test Type" == itp.GetName()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetPropertyByInternalName(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    itemtypeLib = ItemTypeLibrary("TestLibrary", srcDgnFile)
    itpFirst = itemtypeLib.AddItemType("Test Type")
    prop = itpFirst.AddProperty("First Name")
    prop.SetType(CustomProperty.Type1.eString)
    assert True == itemtypeLib.Write ()

    enName = WString()
    ECNameValidation.EncodeToValidName(enName, (WString)("First Name"))
    prop = itpFirst.GetPropertyByInternalName(str(enName))
    assert None != prop
    assert "First Name" == prop.GetName()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetCustomTypeByInternalName(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    itemtypeLib = ItemTypeLibrary("TestLibrary", srcDgnFile)
    customPropType = itemtypeLib.AddCustomType("Test Struct")
    customPropType.AddProperty("First prop")
    itpFirst = itemtypeLib.AddItemType ("Test Type")
    prop = itpFirst.AddProperty ("First Name")
    prop.SetType(customPropType)
    assert True == itemtypeLib.Write ()

    enName = WString()
    ECNameValidation.EncodeToValidName(enName, (WString)("Test Struct"))
    customPropType = itemtypeLib.GetCustomTypeByInternalName(str(enName))
    assert None != customPropType
    assert "Test Struct" == customPropType.GetName()

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DefaultExpression_StringTest(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    itemtypeLib = ItemTypeLibrary ("TestLibrary", srcDgnFile)
    itpFirst = itemtypeLib.AddItemType ("Test Type")
    prop = itpFirst.AddProperty ("prop1")
    prop = itpFirst.AddProperty("prop2")
    prop = itpFirst.AddProperty("prop3")
    prop.SetExpression("this[\"prop1\"] & this[\"prop2\"]","")
    prop.SetIsDefaultValueExpression(True)
    assert False == prop.IsReadOnlyProperty()
    assert True == itemtypeLib.Write()

    eeh = EditElementHandle()
    CreateLine(ret[0],eeh, 10,10, 20, 20)

    itemHost = CustomItemHost (eeh, False)
    instancePtr = itemHost.ApplyCustomItem(itpFirst)
    assert instancePtr != None

    #read expression prop value
    strVal = WString("")
    instancePtr.GetValueAsString(strVal, "prop3", False, 0)
    assert True == WString.IsNullOrEmpty(repr(strVal))

    instancePtr.SetValueAsString("prop1", "A", False, 0)
    instancePtr.SetValueAsString("prop2", "B", False, 0)
    instancePtr.GetValueAsString(strVal, "prop3", False, 0)
    assert  repr(strVal) == "AB"

    instancePtr.SetValueAsString("prop3", "XY", False, 0)
    instancePtr.GetValueAsString(strVal, "prop3", False, 0)
    assert repr(strVal) == "XY"

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_DefaultExpression_Point(initDgnPlatformHost, loadDgnFile, createTempDgnFileWithSeed):
    fileSrc = os.environ['MSPYTEMPDATA']+ os.path.basename(__file__).split('.')[0] + str(sys._getframe().f_lineno)+'.dgn'
    srcDgnFile = createTempDgnFileWithSeed (fileSrc, loadDgnFile)

    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    itemtypeLib = ItemTypeLibrary ("TestLibrary1", srcDgnFile)
    itpFirst = itemtypeLib.AddItemType ("TestType")
    prop = itpFirst.AddProperty ("prop1")
    prop.SetType(CustomProperty.Type1.ePoint)
    prop.SetExpression("this.GetElement().RangeHigh","")
    prop.SetIsDefaultValueExpression(True)
    #propety should be writable
    assert False == prop.IsReadOnlyProperty()
    assert True == itemtypeLib.Write()

    #create element
    eeh = EditElementHandle()
    CreateLine(ret[0],eeh, 10,10, 8000, 800)
 
    #create item
    itemHost = CustomItemHost (eeh, False)
    instancePtr = itemHost.ApplyCustomItem(itpFirst)
    assert instancePtr != None

    #get value
    ptValue = ECValue()
    instancePtr.GetValue(ptValue, "prop1")
    assert True == (ptValue.IsUninitialized() == False and ptValue.IsNull() == False)
    assert True == (ptValue.GetPoint3D().x != 0 and ptValue.GetPoint3D().y != 0)
        
    # #set new value
    ptValue.SetPoint3D(DPoint3d.From(50, 50))
    instancePtr.SetValue("prop1", ptValue)

    # #verify new value
    instancePtr.GetValue(ptValue, "prop1")
    assert False ==ptValue.IsNull() 
    assert True == (ptValue.GetPoint3D().x == 50 and ptValue.GetPoint3D().y == 50)