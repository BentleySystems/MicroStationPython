#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import ctypes

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

N_FINAL_STRING_PROPS_IN_FAKE_CLASS = 48
FIXED_COUNT_ARRAYS_ARE_SUPPORTED = False

s_propertyNames = WStringArray ()

def fill_large_string (s, strSize, copySCount):
    largeString = WString ()
    for i in range (copySCount):
        largeString += s

    curLen = largeString.__len__ ()
    largeString.PadRight (strSize - curLen, '\0')
    return largeString

def VerifyString0 (instance, v, accessString, useIndex, index, value):
    v.Clear()
    if (useIndex):
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString, index))
    else:
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString))

    EXPECT_STREQ (value, v.GetString())

def VerifyString (instance, v, accessString, value):
    return VerifyString0 (instance, v, accessString, False, 0, value)

def SetAndVerifyString (instance, v, accessString, value):
    v.SetString(value)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue (accessString, v))
    VerifyString (instance, v, accessString, value)

def VerifyInteger0 (instance, v, accessString, useIndex, index, value):
    v.Clear()
    if (useIndex):
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString, index))
    else:
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString))
    EXPECT_EQ (value, v.GetInteger())

def VerifyInteger (instance, v, accessString, value):
    return VerifyInteger0 (instance, v, accessString, False, 0, value)

def SetAndVerifyInteger (instance, v, accessString, value):
    v.SetInteger(value)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue (accessString, v))
    VerifyInteger (instance, v, accessString, value)

def VerifyDouble (instance, v, accessString, value):
    v.Clear()
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString))
    EXPECT_EQ (value, v.GetDouble())

def SetAndVerifyDouble (instance, v, accessString, value):
    v.SetDouble(value)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue (accessString, v))
    VerifyDouble (instance, v, accessString, value)

def VerifyLong (instance, v, accessString, value):
    v.Clear()
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString))
    EXPECT_EQ (value, v.GetLong())


def SetAndVerifyLong (instance, v, accessString, value):
    v.SetLong(value)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue (accessString, v))
    VerifyLong (instance, v, accessString, value)

def VerifyArrayInfo (instance, v, accessString, count, isFixedCount):
    v.Clear()
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString))
    EXPECT_EQ (count, v.GetArrayInfo().GetCount())
    EXPECT_EQ (isFixedCount, v.GetArrayInfo().IsFixedCount())

def VerifyOutOfBoundsError (instance, v, accessString, index):
    v.Clear()
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_IndexOutOfRange == instance.GetValue (v, accessString, index))
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_IndexOutOfRange == instance.SetValue (accessString, v, index))

def VerifyStringArray (instance, v, accessString, value, start, count):
    incrementingString = WString (value)

    loopRange = range (start, start + count)
    for i in loopRange:
        incrementingString += WString ("X")
        VerifyString0 (instance, v, accessString, True, i, incrementingString.GetWCharCP ())

def SetAndVerifyStringArray (instance, v, accessString, value, count):
    incrementingString = WString (value)

    loopRange = range (0, count)
    for i in loopRange:
        incrementingString += WString ("X")
        v.SetString(incrementingString.GetWCharCP())
        status = instance.SetValue (accessString, v, i)
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==status)

    VerifyStringArray (instance, v, accessString, value, 0, count)

def VerifyIntegerArray (instance, v, accessString, baseValue, start, count):
    loopRange = range (start, start + count)
    for i in loopRange:
        VerifyInteger0 (instance, v, accessString, True, i, baseValue)
        baseValue += 1

def SetAndVerifyIntegerArray (instance, v, accessString, baseValue, count):
    loopRange = range (0, count)
    for i in loopRange:
        v.SetInteger(baseValue + i)
        status = instance.SetValue (accessString, v, i)
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==status)

    VerifyIntegerArray (instance, v, accessString, baseValue, 0, count)

def VerifyIsNullArrayElements (instance, v, accessString, start, count, isNull):
    loopRange = range (start, start + count)
    for i in loopRange:
        v.Clear()
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, accessString, i))
        EXPECT_TRUE (isNull == v.IsNull())

def GetTestSchemaXMLString (schemaName, versionMajor, versionMinor, className):
    fmt = """<?xml version=\"1.0\" encoding=\"UTF-8\"?>
             <ECSchema schemaName=\"{}\" nameSpacePrefix=\"test\" version=\"{}.{}\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">
                <ECClass typeName=\"EmptyClass\" isDomainClass=\"True\">
                </ECClass>
                <ECClass typeName=\"Manufacturer\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"Name\" typeName=\"string\" />
                    <ECProperty propertyName=\"AccountNo\" typeName=\"int\" />
                </ECClass>
                <ECClass typeName=\"CadData\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"Name\"         typeName=\"string\" />
                    <ECProperty propertyName=\"Count\"        typeName=\"int\" />
                    <ECProperty propertyName=\"StartPoint\"   typeName=\"point3d\" />
                    <ECProperty propertyName=\"EndPoint\"     typeName=\"point3d\" />
                    <ECProperty propertyName=\"Size\"         typeName=\"point2d\" />
                    <ECProperty propertyName=\"Length\"       typeName=\"double\"  />
                    <ECProperty propertyName=\"Install_Date\" typeName=\"dateTime\"  />
                    <ECProperty propertyName=\"Service_Date\" typeName=\"dateTime\"  />
                    <ECProperty propertyName=\"Field_Tested\" typeName=\"boolean\"  />
                </ECClass>
                <ECClass typeName=\"ArrayTest\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECArrayProperty propertyName=\"SomeStrings\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"SomeInts\"    typeName=\"int\" />
                    <ECArrayProperty propertyName=\"SomePoint3ds\"    typeName=\"point3d\" />
                    <ECArrayProperty propertyName=\"SomePoint2ds\"    typeName=\"point2d\" />
                    <ECArrayProperty propertyName=\"SomeDoubles\"     typeName=\"double\"  />
                    <ECArrayProperty propertyName=\"SomeDateTimes\"   typeName=\"dateTime\"  />
                    <ECArrayProperty propertyName=\"SomeBooleans\"    typeName=\"boolean\"  />
                    <ECArrayProperty propertyName=\"SomeLongs\"       typeName=\"long\"  />
                    <ECArrayProperty propertyName=\"SomeBinaries\"    typeName=\"binary\"  />
                    <ECArrayProperty propertyName=\"FixedArrayFixedElement\" typeName=\"int\" minOccurs=\"10\" maxOccurs=\"10\"/>
                    <ECArrayProperty propertyName=\"FixedArrayVariableElement\" typeName=\"string\" minOccurs=\"12\" maxOccurs=\"12\"/> 
                    <ECArrayProperty propertyName=\"ManufacturerArray\" typeName=\"Manufacturer\" />
                </ECClass>
                <ECClass typeName=\"AllPrimitives\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"AString\"          typeName=\"string\" />
                    <ECProperty propertyName=\"AnInt\"            typeName=\"int\" />
                    <ECProperty propertyName=\"APoint3d\"         typeName=\"point3d\" />
                    <ECProperty propertyName=\"APoint2d\"         typeName=\"point2d\" />
                    <ECProperty propertyName=\"ADouble\"          typeName=\"double\"  />
                    <ECProperty propertyName=\"ADateTime\"        typeName=\"dateTime\"  />
                    <ECProperty propertyName=\"ABoolean\"         typeName=\"boolean\"  />
                    <ECProperty propertyName=\"ALong\"            typeName=\"long\"  />
                    <ECProperty propertyName=\"ABinary\"          typeName=\"binary\"  />
                    <ECArrayProperty propertyName=\"SomeStrings\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"SomeInts\"    typeName=\"int\" />
                    <ECArrayProperty propertyName=\"SomePoint3ds\"    typeName=\"point3d\" />
                    <ECArrayProperty propertyName=\"SomePoint2ds\"    typeName=\"point2d\" />
                    <ECArrayProperty propertyName=\"SomeDoubles\"     typeName=\"double\"  />
                    <ECArrayProperty propertyName=\"SomeDateTimes\"   typeName=\"dateTime\"  />
                    <ECArrayProperty propertyName=\"SomeBooleans\"    typeName=\"boolean\"  />
                    <ECArrayProperty propertyName=\"SomeLongs\"       typeName=\"long\"  />
                    <ECArrayProperty propertyName=\"SomeBinaries\"    typeName=\"binary\"  />
                </ECClass>
                <ECClass typeName=\"FixedSizeArrayTester\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECArrayProperty propertyName=\"FixedString1\"  typeName=\"string\"     minOccurs=\"1\"  maxOccurs=\"1\" />
                    <ECArrayProperty propertyName=\"FixedInt1\"     typeName=\"int\"        minOccurs=\"1\"  maxOccurs=\"1\" />
                    <ECArrayProperty propertyName=\"FixedString10\" typeName=\"string\"     minOccurs=\"10\" maxOccurs=\"10\" />
                    <ECArrayProperty propertyName=\"FixedInt10\"    typeName=\"int\"        minOccurs=\"10\" maxOccurs=\"10\" />
                    <ECArrayProperty propertyName=\"Struct1\"       typeName=\"BaseClass0\" minOccurs=\"1\"  maxOccurs=\"1\" />
                    <ECArrayProperty propertyName=\"Struct10\"      typeName=\"BaseClass0\" minOccurs=\"10\" maxOccurs=\"10\" />
                </ECClass>
                <ECClass typeName=\"ClassLayoutPerformanceTest0\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"AString\"  typeName=\"string\" />
                    <ECProperty propertyName=\"AnInt\"    typeName=\"int\" />
                    <ECProperty propertyName=\"ADouble\"  typeName=\"double\"  />
                </ECClass>
                <ECClass typeName=\"ClassLayoutPerformanceTest1\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"AMonkeywrench\"    typeName=\"int\" />
                    <ECProperty propertyName=\"ADouble\"          typeName=\"double\"  />
                    <ECProperty propertyName=\"AString\"          typeName=\"string\" />
                    <ECProperty propertyName=\"AnInt\"            typeName=\"int\" />
                </ECClass>
                <ECClass typeName=\"{}\" isDomainClass=\"True\">
                    <ECArrayProperty propertyName=\"BeginningArray\" typeName=\"string\" />
                    <ECProperty propertyName=\"A\" typeName=\"int\" />
                    <ECProperty propertyName=\"AA\" typeName=\"int\" />
                    <ECProperty propertyName=\"B\" typeName=\"string\" />
                    <ECProperty propertyName=\"C\" typeName=\"long\" />
                    <ECProperty propertyName=\"D\" typeName=\"double\" />
                    <ECProperty propertyName=\"S\" typeName=\"string\" />
                    <ECStructProperty propertyName=\"Manufacturer\" typeName=\"Manufacturer\" />
                    <ECProperty propertyName=\"Property0\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property1\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property2\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property3\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property4\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property5\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property6\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property7\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property8\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property9\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"FixedArrayFixedElement\" typeName=\"int\" minOccurs=\"10\" maxOccurs=\"10\"/>                 
                    <ECProperty propertyName=\"Property10\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property11\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property12\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property13\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property14\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property15\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property16\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property17\" typeName=\"string\" />                  
                    <ECArrayProperty propertyName=\"VariableArrayFixedElement\" typeName=\"int\"/>
                    <ECArrayProperty propertyName=\"FixedArrayVariableElement\" typeName=\"string\" minOccurs=\"12\" maxOccurs=\"12\"/>                   
                    <ECProperty propertyName=\"Property18\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property19\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property20\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property21\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property22\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"ManufacturerArray\" typeName=\"Manufacturer\"/>
                    <ECProperty propertyName=\"Property23\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property24\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property25\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property26\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property27\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"VariableArrayVariableElement\" typeName=\"string\"/>
                    <ECProperty propertyName=\"Property28\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property29\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property30\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property31\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property32\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property33\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property34\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property35\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property36\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property37\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property38\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property39\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property40\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property41\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property42\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property43\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property44\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property45\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property46\" typeName=\"string\" />
                    <ECProperty propertyName=\"Property47\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"EndingArray\" typeName=\"string\" />
                </ECClass>
                <ECClass typeName=\"NestedStructArray\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"NestPropString\" typeName=\"string\" />
                    <ECArrayProperty propertyName=\"ManufacturerArray\" typeName=\"Manufacturer\"  minOccurs=\"0\" maxOccurs=\"unbounded\" />
                </ECClass>
                <ECClass typeName=\"ClassWithStructArray\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECArrayProperty propertyName=\"StructArray\" typeName=\"AllPrimitives\"  minOccurs=\"0\" maxOccurs=\"unbounded\" />
                    <ECStructProperty propertyName=\"StructMember\" typeName=\"AllPrimitives\" />
                    <ECArrayProperty propertyName=\"ComplicatedStructArray\" typeName=\"NestedStructArray\"  minOccurs=\"0\" maxOccurs=\"unbounded\" />
                </ECClass>
                <ECClass typeName=\"ClassWithPolymorphicStructArray\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECArrayProperty propertyName=\"PolymorphicStructArray\" typeName=\"BaseClass0\"  minOccurs=\"0\" maxOccurs=\"unbounded\" />
                </ECClass>
                <ECClass typeName=\"BaseClass0\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"BaseIntProperty\" typeName=\"int\" />
                </ECClass>
                <ECClass typeName=\"DerivedClass0\" isStruct=\"True\" isDomainClass=\"True\">
                    <BaseClass>BaseClass0</BaseClass>
                    <ECProperty propertyName=\"DerivedStringProperty\" typeName=\"string\" />
                </ECClass>
                <ECClass typeName=\"DerivedClass1\" isStruct=\"True\" isDomainClass=\"True\">
                    <BaseClass>BaseClass0</BaseClass>
                    <ECProperty propertyName=\"DerivedDoubleProperty\" typeName=\"double\" />
                </ECClass>
                <ECClass typeName=\"Address\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"HouseNumber\"  typeName=\"string\" />
                    <ECProperty propertyName=\"Street\"       typeName=\"string\" />
                    <ECProperty propertyName=\"Town\"         typeName=\"string\" />
                    <ECProperty propertyName=\"State\"        typeName=\"string\" />
                    <ECProperty propertyName=\"Zip\"          typeName=\"int\" />
                </ECClass>
                <ECClass typeName=\"PhoneNumber\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty propertyName=\"AreaCode\"     typeName=\"int\" />
                    <ECProperty propertyName=\"Number\"       typeName=\"int\" />
                </ECClass>
                <ECClass typeName=\"ContactInfo\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECStructProperty propertyName=\"PhoneNumber\" typeName=\"PhoneNumber\" />
                    <ECStructProperty propertyName=\"Address\"     typeName=\"Address\" />
                    <ECProperty       propertyName=\"Email\"       typeName=\"string\" />
                </ECClass>
                <ECClass typeName=\"Employee\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty       propertyName=\"Name\"       typeName=\"string\" />
                    <ECStructProperty propertyName=\"Home\"       typeName=\"ContactInfo\" />
                    <ECStructProperty propertyName=\"Work\"       typeName=\"ContactInfo\" />
                </ECClass>
                <ECClass typeName=\"EmployeeDirectory\" isDomainClass=\"True\">
                    <ECArrayProperty propertyName=\"Employees\" typeName=\"Employee\"  minOccurs=\"0\" maxOccurs=\"unbounded\" />
                </ECClass>
                <ECClass typeName=\"Car\" isStruct=\"True\" isDomainClass=\"True\">
                    <ECProperty       propertyName=\"Name\"       typeName=\"string\"/>
                    <ECProperty       propertyName=\"Wheels\"     typeName=\"int\"  readOnly=\"True\"/>
                </ECClass>
              <ECClass typeName=\"StructClass\" isStruct=\"True\" isDomainClass=\"False\">
                <ECProperty propertyName=\"StringProperty\" typeName=\"string\" />
                <ECProperty propertyName=\"IntProperty\" typeName=\"int\" />
                <ECArrayProperty propertyName=\"ArrayProperty\" typeName=\"string\" minOccurs=\"1\" maxOccurs=\"1\" />
                </ECClass>
              <ECClass typeName=\"ComplexClass\" isDomainClass=\"True\">
                <ECProperty propertyName=\"IntProperty\" typeName=\"int\" />
                <ECProperty propertyName=\"StringProperty\" typeName=\"string\" />
                <ECProperty propertyName=\"DoubleProperty\" typeName=\"double\" />
                <ECProperty propertyName=\"DateTimeProperty\" typeName=\"dateTime\" />
                <ECProperty propertyName=\"BooleanProperty\" typeName=\"boolean\" />
                <ECArrayProperty propertyName=\"SimpleArrayProperty\" typeName=\"string\" minOccurs=\"1\" maxOccurs=\"1\" />
                <ECArrayProperty propertyName=\"StructArrayProperty\" typeName=\"StructClass\" minOccurs=\"1\" maxOccurs=\"1\" isStruct=\"True\" />
                <ECStructProperty propertyName=\"StructProperty\" typeName=\"StructClass\" /> 
              </ECClass>
            </ECSchema>"""

    #buff = ''.join([fmt.format(schemaName, versionMajor, versionMinor, className)])
    #return buff
    fmt = fmt.format(schemaName, versionMajor, versionMinor, className)
    return fmt

def CreateTestSchema():
    schemaXMLString = WString (GetTestSchemaXMLString ("TestSchema", 0, 0, "TestClass"))
    schemaContext = ECSchemaReadContext.CreateContext()
    retVal, schema = ECSchema.ReadFromXmlString (schemaXMLString.GetWCharCP(), schemaContext)
    EXPECT_EQ (BentleyStatus.eSUCCESS, retVal)
    return schema


def CreateProfilingSchema (nStrings):
    s_propertyNames.clear()

    schemaXml = WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                "<ECSchema schemaName=\"ProfilingSchema\" nameSpacePrefix=\"p\" version=\"1.0\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">"
                "    <ECClass typeName=\"Pidget\" isDomainClass=\"True\">")

    loopRange = range (0, nStrings)
    for i in loopRange:
        propertyName = "StringProperty{}".format(i)
        s_propertyNames.append (WString (propertyName))

        propertyXml =  "        <ECProperty propertyName=\"{}\" typeName=\"string\" />".format(propertyName)
        strPropertyXml = WString (propertyXml)
        schemaXml += strPropertyXml

    schemaXml += WString ("    </ECClass></ECSchema>")

    schemaContext = ECSchemaReadContext.CreateContext()

    retVal, schema = ECSchema.ReadFromXmlString (schemaXml.GetWCharCP(), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, retVal)
    return schema

def ExerciseVariableCountIntArray (instance, v, arrayAccessor, baseValue):
    # test insertion in an empty array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 0, 5))

    VerifyArrayInfo             (instance, v, arrayAccessor, 5, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 5, True)
    SetAndVerifyIntegerArray    (instance, v, arrayAccessor, baseValue, 5)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 5, False)
    VerifyOutOfBoundsError      (instance, v, arrayAccessor, 5)

    # test insertion in the middle of an array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 3, 3))

    VerifyArrayInfo             (instance, v, arrayAccessor, 8, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 3, False)
    VerifyIntegerArray          (instance, v, arrayAccessor, baseValue, 0, 3)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 3, 3, True)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 6, 2, False)
    VerifyIntegerArray          (instance, v, arrayAccessor, baseValue + 3, 6, 2)
    SetAndVerifyIntegerArray    (instance, v, arrayAccessor, baseValue, 8)

    # test insertion at the beginning of an array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 0, 4))

    VerifyArrayInfo             (instance, v, arrayAccessor, 12, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 4, True)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 4, 8, False)
    VerifyIntegerArray          (instance, v, arrayAccessor, baseValue, 4, 8)
    SetAndVerifyIntegerArray    (instance, v, arrayAccessor, baseValue, 12)

    # test insertion at the end of an array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.AddArrayElements (arrayAccessor, 2))

    VerifyArrayInfo             (instance, v, arrayAccessor, 14, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 12, 2, True)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 12, False)
    VerifyIntegerArray          (instance, v, arrayAccessor, baseValue, 0, 12)
    SetAndVerifyIntegerArray    (instance, v, arrayAccessor, baseValue, 14)

def ExerciseVariableCountStringArray (instance, v, arrayAccessor, stringSeed):
    # test insertion in an empty array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 0, 5))
    VerifyArrayInfo             (instance, v, arrayAccessor, 5, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 5, True)
    SetAndVerifyStringArray     (instance, v, arrayAccessor, stringSeed, 5)   
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 5, False)
    VerifyOutOfBoundsError      (instance, v, arrayAccessor, 5)

    # test insertion in the middle of an array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 3, 3))
    VerifyArrayInfo             (instance, v, arrayAccessor, 8, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 3, False)
    VerifyStringArray           (instance, v, arrayAccessor, stringSeed, 0, 3)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 3, 3, True)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 6, 2, False)

    stringSeedXXX = WString (stringSeed)
    stringSeedXXX += WString ("XXX")
    VerifyStringArray           (instance, v, arrayAccessor, stringSeedXXX.GetWCharCP(), 6, 2)
    SetAndVerifyStringArray     (instance, v, arrayAccessor, stringSeed, 8)

    # test insertion at the beginning of an array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 0, 4))

    VerifyArrayInfo             (instance, v, arrayAccessor, 12, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 4, True)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 4, 8, False)
    VerifyStringArray           (instance, v, arrayAccessor, stringSeed, 4, 8)
    SetAndVerifyStringArray     (instance, v, arrayAccessor, stringSeed, 12)

    # test insertion at the end of an array
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.AddArrayElements (arrayAccessor, 2))
    VerifyArrayInfo             (instance, v, arrayAccessor, 14, False)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 12, 2, True)
    VerifyIsNullArrayElements   (instance, v, arrayAccessor, 0, 12, False)
    VerifyStringArray           (instance, v, arrayAccessor, stringSeed, 0, 12)
    SetAndVerifyStringArray     (instance, v, arrayAccessor, stringSeed, 14)

def VerifyVariableCountManufacturerArray (instance, v, arrayAccessor):
    VerifyArrayInfo (instance, v, arrayAccessor, 4, False)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, arrayAccessor))

    VerifyIsNullArrayElements (instance, v, arrayAccessor, 0, 4, False)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, arrayAccessor, 0))
    EXPECT_TRUE (v.IsStruct())
    manufInst = v.GetStruct()
    VerifyString (manufInst, v, "Name", "Nissan")
    VerifyInteger (manufInst, v, "AccountNo", 3475)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, arrayAccessor, 1))
    EXPECT_TRUE (v.IsStruct())
    manufInst = v.GetStruct()
    VerifyString (manufInst, v, "Name", "Ford")
    VerifyInteger (manufInst, v, "AccountNo", 381)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, arrayAccessor, 2))
    EXPECT_TRUE (v.IsStruct())
    manufInst = v.GetStruct()
    VerifyString (manufInst, v, "Name", "Chrysler")
    VerifyInteger (manufInst, v, "AccountNo", 81645)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, arrayAccessor, 3))
    EXPECT_TRUE (v.IsStruct())
    manufInst = v.GetStruct()
    VerifyString (manufInst, v, "Name", "Toyota")
    VerifyInteger (manufInst, v, "AccountNo", 6823)

def ExerciseVariableCountManufacturerArray (instance, manufacturerEnabler, v, arrayAccessor):
    VerifyArrayInfo (instance, v, arrayAccessor, 0, False)

    #create an array of two values
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.AddArrayElements (arrayAccessor, 2))
    VerifyArrayInfo (instance, v, arrayAccessor, 2, False)
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 0, 2, True)
    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Nissan")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 3475)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 0))
    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Kia")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 1791)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 1))
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 0, 2, False)
   
    #insert two elements in the middle of the array   
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.InsertArrayElements (arrayAccessor, 1, 2))
    VerifyArrayInfo (instance, v, arrayAccessor, 4, False)
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 0, 1, False)
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 1, 2, True)
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 3, 1, False)
    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Ford")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 381)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 1)) 
    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Chrysler")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 81645)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 2))
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 0, 4, False)
    
    #ensure we can set a struct array value to NULL        
    v.SetToNull()
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 3))
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 0, 3, False)
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 3, 1, True)
    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Acura")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 6)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 3))
    VerifyIsNullArrayElements (instance, v, arrayAccessor, 3, 1, False)
    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Toyota")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 6823)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue (arrayAccessor, v, 3))
    
    VerifyVariableCountManufacturerArray (instance, v, arrayAccessor)

def ExerciseInstance (instance, valueForFinalStrings):
    v = ECValue ()
    instance.GetValue (v, "D")

    doubleValue = 1.0/3.0
    SetAndVerifyDouble (instance, v, "D", doubleValue)

    SetAndVerifyInteger (instance, v, "A", 97)
    SetAndVerifyInteger (instance, v, "AA", 12)   
    
    SetAndVerifyString (instance, v, "B", "Happy")
    SetAndVerifyString (instance, v, "B", "Very Happy")
    SetAndVerifyString (instance, v, "B", "sad")
    SetAndVerifyString (instance, v, "S", "Lucky")
    SetAndVerifyString (instance, v, "B", "Very Very Happy")
    VerifyString (instance, v, "S", "Lucky")
    SetAndVerifyString (instance, v, "Manufacturer.Name", "Charmed")
    SetAndVerifyString (instance, v, "S", "Lucky Strike")

    s = WString ("S2345678901234567890123456789012")
    largeString = fill_large_string (s, 3000, 20)

    SetAndVerifyString (instance, v, "S", largeString.GetWCharCP ())
    for i in range (0, N_FINAL_STRING_PROPS_IN_FAKE_CLASS):
        propertyName = "Property{}".format (i)
        SetAndVerifyString (instance, v, propertyName, valueForFinalStrings)

    VerifyArrayInfo (instance, v, "BeginningArray", 0, False)
    VerifyArrayInfo (instance, v, "VariableArrayFixedElement", 0, False)
    VerifyArrayInfo (instance, v, "VariableArrayVariableElement", 0, False)
    VerifyArrayInfo (instance, v, "EndingArray", 0, False)
    
    if False != FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
        #We cannot honor min/maxOccurs attributes of ArrayECProperty, so arrays are always unbounded
        VerifyArrayInfo (instance, v, "FixedArrayFixedElement", 10, True)
        VerifyArrayInfo (instance, v, "FixedArrayVariableElement", 12, True)
        VerifyIsNullArrayElements (instance, v, "FixedArrayFixedElement", 0, 10, True)
        SetAndVerifyIntegerArray (instance, v, "FixedArrayFixedElement", 172, 10)
        VerifyIsNullArrayElements (instance, v, "FixedArrayFixedElement", 0, 10, False)
        SetAndVerifyIntegerArray (instance, v, "FixedArrayFixedElement", 283, 10)
        
        VerifyIsNullArrayElements (instance, v, "FixedArrayVariableElement", 0, 12, True)
        SetAndVerifyStringArray (instance, v, "FixedArrayVariableElement", "BaseString", 12)   
        VerifyIsNullArrayElements (instance, v, "FixedArrayVariableElement", 0, 12, False)
        SetAndVerifyStringArray (instance, v, "FixedArrayVariableElement", "LaaaaaaargeString", 10)   
        VerifyStringArray (instance, v, "FixedArrayVariableElement", "BaseStringXXXXXXXXXX", 10, 2)
        SetAndVerifyStringArray (instance, v, "FixedArrayVariableElement", "XString", 12)   
    else:
        #Replace #ifdef'ed out section above
        VerifyArrayInfo (instance, v, "FixedArrayFixedElement", 0, False)
        VerifyArrayInfo (instance, v, "FixedArrayVariableElement", 0, False)
        instance.AddArrayElements ("FixedArrayFixedElement", 10)               #if we supported fixed count arrays, the elements would already have been allocated and this would be unnecessary
        VerifyIsNullArrayElements (instance, v, "FixedArrayFixedElement", 0, 10, True)
        SetAndVerifyIntegerArray (instance, v, "FixedArrayFixedElement", 172, 10)
        VerifyIsNullArrayElements (instance, v, "FixedArrayFixedElement", 0, 10, False)
        SetAndVerifyIntegerArray (instance, v, "FixedArrayFixedElement", 283, 10)

        instance.AddArrayElements ("FixedArrayVariableElement", 12)            #if we supported fixed count arrays, the elements would already have been allocated and this would be unnecessary
        VerifyIsNullArrayElements (instance, v, "FixedArrayVariableElement", 0, 12, True)
        SetAndVerifyStringArray (instance, v, "FixedArrayVariableElement", "BaseString", 12)
        VerifyIsNullArrayElements (instance, v, "FixedArrayVariableElement", 0, 12, False)
        SetAndVerifyStringArray (instance, v, "FixedArrayVariableElement", "LaaaaaaargeString", 10)
        VerifyStringArray (instance, v, "FixedArrayVariableElement", "BaseStringXXXXXXXXXX", 10, 2)
        SetAndVerifyStringArray (instance, v, "FixedArrayVariableElement", "XString", 12)

    ExerciseVariableCountStringArray (instance, v, "BeginningArray", "BAValue")
    ExerciseVariableCountIntArray    (instance, v, "VariableArrayFixedElement", 57)
    ExerciseVariableCountStringArray (instance, v, "VariableArrayVariableElement", "Var+Var")
    ExerciseVariableCountStringArray (instance, v, "EndingArray", "EArray")
    
    manufacturerClass = instance.GetClass().GetSchema().GetClass ("Manufacturer")
    ASSERT_TRUE (None != manufacturerClass)

#ifdef OLD_WAY    
#    manufClassLayout = ClassLayout.BuildFromClass (manufacturerClass, 43, 24)
#    manufEnabler = StandaloneECEnabler.CreateEnabler (manufacturerClass, manufClassLayout, True)
#endif
    manufEnabler =  instance.GetEnabler ().GetEnablerForStructArrayMember (manufacturerClass.GetSchema().GetSchemaKey(), manufacturerClass.GetName().GetWCharCP())
    ExerciseVariableCountManufacturerArray (instance, manufEnabler, v, "ManufacturerArray")
    
    #Make sure that everything still has the final value that we expected
    VerifyString (instance, v, "S", largeString.GetWCharCP ())
    VerifyInteger (instance, v, "A", 97)
    VerifyDouble  (instance, v, "D", doubleValue)
    VerifyInteger (instance, v, "AA", 12)
    VerifyString  (instance, v, "B", "Very Very Happy")
    VerifyString (instance, v, "Manufacturer.Name", "Charmed")
    for i in range (0, N_FINAL_STRING_PROPS_IN_FAKE_CLASS):
        propertyName = "Property{}".format(i)
        VerifyString (instance, v, propertyName, valueForFinalStrings)

    VerifyArrayInfo     (instance, v, "BeginningArray", 14, False)
    VerifyIsNullArrayElements   (instance, v, "BeginningArray", 0, 14, False)
    VerifyStringArray   (instance, v, "BeginningArray", "BAValue", 0, 14)
    VerifyArrayInfo     (instance, v, "VariableArrayVariableElement", 14, False)
    VerifyIsNullArrayElements   (instance, v, "VariableArrayVariableElement", 0, 14, False)
    VerifyStringArray   (instance, v, "VariableArrayVariableElement", "Var+Var", 0, 14)       
    VerifyArrayInfo     (instance, v, "EndingArray", 14, False)
    VerifyIsNullArrayElements   (instance, v, "EndingArray", 0, 14, False)
    VerifyStringArray   (instance, v, "EndingArray", "EArray", 0, 14)        
    VerifyVariableCountManufacturerArray (instance, v, "ManufacturerArray") 
    
    if False != FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
        VerifyArrayInfo     (instance, v, "FixedArrayFixedElement", 10, True)
        VerifyIntegerArray  (instance, v, "FixedArrayFixedElement", 283, 0, 10)     
        VerifyArrayInfo     (instance, v, "FixedArrayVariableElement", 12, True)
        VerifyIsNullArrayElements   (instance, v, "FixedArrayVariableElement", 0, 12, False)
        VerifyStringArray   (instance, v, "FixedArrayVariableElement", "XString", 0, 12)   
        VerifyArrayInfo     (instance, v, "VariableArrayFixedElement", 14, False)
        VerifyIsNullArrayElements   (instance, v, "VariableArrayFixedElement", 0, 14, False)
        VerifyIntegerArray  (instance, v, "VariableArrayFixedElement", 57, 0, 14)           


    instance.ToString("").GetWCharCP()

MUST_PUBLISH_ECInstanceInteropHelper = False
if MUST_PUBLISH_ECInstanceInteropHelper:
    def test_GetValuesUsingInteropHelper ():
        schema = CreateTestSchema()
        ASSERT_TRUE (schema!= None)

        ecClass = schema.GetClass ("TestClass")
        ASSERT_TRUE (None != ecClass)

        classLayout = ClassLayout.BuildFromClass (ecClass, 0, 0)
        enabler = StandaloneECEnabler.CreateEnabler (ecClass, classLayout, True)

        instance = enabler.CreateInstance()

        doubleVal = 0.0
        intVal = 0

        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.SetDoubleValue (instance, "D", 1.0/3.0))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.GetDouble      (instance, doubleVal, "D"))
        EXPECT_TRUE (1.0/3.0 == doubleVal)

        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.AddArrayElements ("FixedArrayFixedElement", 1))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.SetIntegerValue (instance, "FixedArrayFixedElement[0]", 97))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.GetInteger      (instance, intVal, "FixedArrayFixedElement[0]"))
        EXPECT_TRUE (97 == intVal)

        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.SetIntegerValue (instance, "VariableArrayFixedElement[1]", 101))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.GetInteger      (instance, intVal, "VariableArrayFixedElement[1]"))
        EXPECT_TRUE (101 == intVal)

        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.SetIntegerValue (instance, "VariableArrayFixedElement[0]", 100))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.GetInteger      (instance, intVal, "VariableArrayFixedElement[0]"))
        EXPECT_TRUE (100 == intVal)

        testString = WString ("Charmed")
        testString2 = WString ("Charmed2")
        stringValueP = WString ("")

        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.SetStringValue (instance, "ManufacturerArray[1].Name", testString.GetWCharCP()))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.GetString (instance, stringValueP, "ManufacturerArray[1].Name"))
        EXPECT_STREQ (testString.GetWCharCP(), stringValueP)

        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.SetStringValue (instance, "ManufacturerArray[0].Name", testString2.GetWCharCP()))
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == ECInstanceInteropHelper.GetString (instance, stringValueP, "ManufacturerArray[0].Name"))
        EXPECT_STREQ (testString2.GetWCharCP(), stringValueP)


def test_ECValueEqualsMethod ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("AllPrimitives")
    ASSERT_TRUE (None != ecClass)

    enabler = ecClass.GetDefaultStandaloneEnabler()

    v1 = ECValue ()
    v2 = ECValue ()
    EXPECT_TRUE   (v1 == v2)
    v1.SetInteger (3425)
    v2.SetInteger (6548)
    EXPECT_FALSE  (v1 == v2)
    v2.SetInteger (v1.GetInteger())
    EXPECT_TRUE   (v1 == v2)

    v1.SetString  (WString ("Something"))
    v2.SetString  (WString ("Something else"))
    EXPECT_FALSE  (v1 == v2)
    v2.SetString  (v1.GetString())
    EXPECT_TRUE   (v1 == v2)

    #Conflicting types
    v2.SetInteger (3425)
    EXPECT_FALSE  (v1 == v2)

    v1.SetDouble  (1.0)
    v2.SetDouble  (1.0)
    EXPECT_TRUE   (v1 == v2)
    v2.SetDouble  (2.0)
    EXPECT_FALSE  (v1 == v2)

    v1.SetLong    (345)
    v2.SetLong    (345)
    EXPECT_TRUE   (v1 == v2)
    v2.SetLong    (345345)
    EXPECT_FALSE  (v1 == v2)

    v1.SetBoolean (False)
    v2.SetBoolean (False)
    EXPECT_TRUE   (v1 == v2)
    v2.SetBoolean (True)
    EXPECT_FALSE  (v1 == v2)

    timeInput = BeDateTime.GetCurrentTimeUtc ()
    v1.SetDateTime(timeInput)
    v2.SetDateTime(timeInput)
    EXPECT_TRUE   (v1 == v2)

    timeInput2 = BeDateTime (timeInput.GetInfo().GetKind(), timeInput.GetYear()+1, timeInput.GetMonth(), timeInput.GetDay(), timeInput.GetHour(), timeInput.GetMinute(), timeInput.GetSecond(), timeInput.GetHectoNanosecond())
    v2.SetDateTime(timeInput2)
    EXPECT_FALSE  (v1 == v2)

    v1.SetDateTimeTicks(633487865666864601)
    v2.SetDateTimeTicks(633487865666864601)
    EXPECT_TRUE   (v1 == v2)

    v2.SetDateTimeTicks(633487865666866601)
    EXPECT_FALSE  (v1 == v2)

    HOLD_AS_DUPLICATE = True
    binaryValue0 = bytes([0x00, 0x01, 0x02, 0x03])
    binaryValue1 = bytes([0x10, 0x11, 0x12, 0x13])
    EXPECT_EQ (len (binaryValue0), 4)
    EXPECT_EQ (len (binaryValue0), 4)
    v1.SetBinary(binaryValue0)
    v2.SetBinary(binaryValue0)
    EXPECT_TRUE   (v1 == v2)
    v2.SetBinary(binaryValue1)
    EXPECT_FALSE  (v1 == v2)

    point2dInput0 = DPoint2d (1.0, 2.0)
    point2dInput1 = DPoint2d (3.0, 4.0)
    v1.SetPoint2D (point2dInput0)
    v2.SetPoint2D (point2dInput0)
    EXPECT_TRUE   (v1 == v2)
    v2.SetPoint2D (point2dInput1)
    EXPECT_FALSE  (v1 == v2)

    point3dInput0 = DPoint3d (1.0, 2.0, -10.0)
    point3dInput1 = DPoint3d (3.0, 4.0, -123.0)
    v1.SetPoint3D (point3dInput0)
    v2.SetPoint3D (point3dInput0)
    EXPECT_TRUE   (v1 == v2)
    v2.SetPoint3D (point3dInput1)
    EXPECT_FALSE  (v1 == v2)

    testInstance0 = enabler.CreateInstance()
    testInstance1 = enabler.CreateInstance()
    v1.SetStruct  (testInstance0)
    v2.SetStruct  (testInstance0)
    EXPECT_TRUE   (v1 == v2)
    v2.SetStruct  (testInstance1)
    EXPECT_FALSE  (v1 == v2)


def test_GetEnablerPropertyInformation ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("AllPrimitives")
    ASSERT_TRUE (None != ecClass)

    enabler = ecClass.GetDefaultStandaloneEnabler()

    expectedPropertyCount = 19

    # -- Can't test this method via published API -- tested indirectly below
    #UInt32 propertyCount = enabler.GetClassLayout().GetPropertyCount()
    #EXPECT_EQ (expectedPropertyCount, propertyCount)

    expectedProperties = [
        "",
        "AString",
        "AnInt",
        "APoint3d",
        "APoint2d",
        "ADouble",
        "ADateTime",
        "ABoolean",
        "ALong",
        "ABinary",
        "SomeStrings",
        "SomeInts",
        "SomePoint3ds",
        "SomePoint2ds",
        "SomeDoubles",
        "SomeDateTimes",
        "SomeBooleans",
        "SomeLongs",
        "SomeBinaries"]

    for i in range (expectedPropertyCount):
        expectedPropertyName = expectedProperties [i]
        propertyName         = WString ("")
        propertyIndex          = 0

        retVal, propertyIndex = enabler.GetPropertyIndex (expectedPropertyName)
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == retVal)

        retVal, propertyName = enabler.GetAccessString (propertyIndex)
        EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == retVal)

        EXPECT_STREQ (expectedPropertyName, propertyName)


def printfIndent (indentDepth):
    for i in range (indentDepth):
        print ("  ")


def dumpPropertyValues (collection, isArray, indentDepth):
    arrayIndex = 0

    for propertyValue in collection:
        v = propertyValue.GetValue()
        printfIndent (indentDepth)
        accessor = propertyValue.GetValueAccessor()
        accessorDepth = accessor.GetDepth()
        accessString = accessor.GetAccessString (accessorDepth - 1)

        if (isArray):
            s = "Array Member [{0}] {1} (depth={2}) = {3}\n".format (str(arrayIndex), accessString, str(accessorDepth), v.ToString().GetWCharCP ())
            print (s)
            arrayIndex += 1
        else:
            print ("{0} (depth={1})".format (accessString, str(accessorDepth)))
            if (False == v.IsStruct()):
                print (" = {0}".format (v.ToString().GetWCharCP()))

            print ("\n")


        if (propertyValue.HasChildValues ()):
            children = propertyValue.GetChildValues()
            dumpPropertyValues (children, v.IsArray(), indentDepth+1)


def dumpLoadedPropertyValues (collection, isArray, indentDepth, printValues, count):
    arrayIndex = 0

    for propertyValue in collection:
        v = propertyValue.GetValue()
        if (False == v.IsLoaded()):
            continue

        count += 1
        if (printValues):
            printfIndent (indentDepth)
            accessor = propertyValue.GetValueAccessor()
            accessorDepth = accessor.GetDepth()
            accessString = accessor.GetAccessString (accessorDepth- 1)

            if (isArray):
                print ("Array Member [{0}] {1} (depth={2}) = {3}\n".format (str(arrayIndex), accessString, str(accessorDepth), v.ToString().GetWCharCP ()))
            else:
                print ("{0} (depth={1})".format (accessString, str(accessorDepth)))
                if (False == v.IsStruct ()):
                    print (" = {0}".format (v.ToString().GetWCharCP()))

                print ("\n")

        if (propertyValue.HasChildValues ()):
            children = propertyValue.GetChildValues()
            count = dumpLoadedPropertyValues (children, v.IsArray(), indentDepth+1, printValues, count)

    return count


def verifyECValueEnumeration (collection, expectedValues, iValue, isDup):
    try:
        it = iter (collection)
        values = [value for value in it]

        for propertyValue in values:
            foundAccessString    = propertyValue.GetValueAccessor().GetManagedAccessString() 
            expectedAccessString = expectedValues[iValue][0]

            EXPECT_STREQ (expectedAccessString, foundAccessString.GetWCharCP ())

            foundValue    = propertyValue.GetValue()
            expectedValue = expectedValues[iValue][1]

            if (False == isDup or False == foundValue.IsStruct()) :
                bRes = foundValue == expectedValue
                EXPECT_TRUE (foundValue == expectedValue)
            else:
                #If we are enumerating a duplicate, it will have its own struct instances
                #and we expect the struct pointers to be different so we can't call Equals
                EXPECT_TRUE (foundValue.IsNull()   == expectedValue.IsNull())
                EXPECT_TRUE (foundValue.IsStruct() == expectedValue.IsStruct())

            iValue += 1

            if (propertyValue.HasChildValues ()):
                children = propertyValue.GetChildValues()
                iValue = verifyECValueEnumeration (children, expectedValues, iValue, isDup)

        return iValue
    except IndexError:
        return iValue


def test_RecursiveECValueEnumeration_EmptyInstance ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("EmptyClass").GetDefaultStandaloneEnabler ()

    ASSERT_TRUE (enabler!= None)

    #--------------------------------------------------------------------------
    #    Create an empty instance
    #--------------------------------------------------------------------------
    instance = enabler.CreateInstance()

    collection = ECValuesCollection.Create (instance)

    #--------------------------------------------------------------------------
    #    Iterate through its values - shouldn't find any
    #--------------------------------------------------------------------------
    foundValues = 0
    for propertyValue in collection:
        propertyValue.HasChildValues() #Use it to adef warning about unused propertyValue object
        foundValues += 1

    EXPECT_TRUE (0 == foundValues)

    #--------------------------------------------------------------------------
    #    Duplicate the instance and verify the duplicate.
    #--------------------------------------------------------------------------
    standAloneInstance = StandaloneECInstance.Duplicate(instance)

    collection = ECValuesCollection.Create (standAloneInstance)
    foundValues = 0
    for propertyValue in collection:
        propertyValue.HasChildValues() #Use it to adef warning about unused propertyValue object
        foundValues+= 1

    EXPECT_TRUE (0 == foundValues)


def test_RecursiveECValueEnumeration_PrimitiveProperties ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("CadData").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #--------------------------------------------------------------------------
    #    Build the instance
    #--------------------------------------------------------------------------
    instance = enabler.CreateInstance()

    instance.SetValue("Name",         ECValue ("My Name"))
    instance.SetValue("Count",        ECValue (14))
    instance.SetValue("Length",       ECValue (142.5))

    dummy = False
    instance.SetValue("Field_Tested", ECValue (True, dummy))

    #---------------------------------------------------------------------------
    #    Build the vector of expected values.
    #    Note: The order does not match the class it matches the classLayout
    #---------------------------------------------------------------------------
    expectedValues = [("Count", ECValue(14)), ("StartPoint", ECValue ()), ("EndPoint", ECValue ()), ("Size", ECValue ()),
                         ("Length", ECValue (142.5)), ("Install_Date",ECValue ()), ("Service_Date", ECValue ()), ("Field_Tested", ECValue (True, dummy)), ("Name", ECValue ("My Name"))]

    #---------------------------------------------------------------------------
    #    Verify that the values returned from the instance match the expected ones.
    #---------------------------------------------------------------------------
    collection = ECValuesCollection.Create (instance)
    iValue = 0
    
    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, False)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (len (expectedValues) == iValue)

    #---------------------------------------------------------------------------
    #    Duplicate the instance and verify the duplicate.
    #---------------------------------------------------------------------------
    standAloneInstance = StandaloneECInstance.Duplicate(instance)

    collection = ECValuesCollection.Create (standAloneInstance)
    iValue = 0
    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, True)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (len (expectedValues) == iValue)


def test_CopyInstanceProperties ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema != None)

    enabler = schema.GetClass("CadData").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()

    instance.SetValue("Name",         ECValue ("My Name"))
    instance.SetValue("Count",        ECValue (14))
    instance.SetValue("Length",       ECValue (142.5))

    dummy = False
    instance.SetValue("Field_Tested", ECValue (True, dummy))

    #---------------------------------------------------------------------------
    #    Build the vector of expected values.
    #    Note: The order does not match the class it matches the classLayout
    #---------------------------------------------------------------------------
    expectedValues = [("Count", ECValue(14)), ("StartPoint", ECValue ()), ("EndPoint", ECValue ()), ("Size", ECValue ()),
                        ("Length", ECValue (142.5)), ("Install_Date",ECValue ()), ("Service_Date", ECValue ()), ("Field_Tested", ECValue (True, dummy)), ("Name", ECValue ("My Name"))]

    #---------------------------------------------------------------------------
    #    Verify that the values returned from the instance match the expected ones.
    #---------------------------------------------------------------------------
    collection = ECValuesCollection.Create (instance)
    iValue = 0

    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, False)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)

    #---------------------------------------------------------------------------
    #    Duplicate the instance and verify the duplicate.
    #---------------------------------------------------------------------------
    duplicateInstance = enabler.CreateInstance()

    copyStatus = duplicateInstance.CopyValues (instance)
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == copyStatus)

    collection = ECValuesCollection.Create (duplicateInstance)
    iValue = 0
    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, True)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)


def test_MergeInstanceProperties ():

    schema = CreateTestSchema()
    ASSERT_TRUE (schema != None)

    enabler = schema.GetClass("CadData").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the base instance
    #---------------------------------------------------------------------------
    mergeToInstance = enabler.CreateInstance()

    dummy = False

    mergeToInstance.SetValue("Name",         ECValue ("base"))
    mergeToInstance.SetValue("Length",       ECValue (142.5))
    mergeToInstance.SetValue("Field_Tested", ECValue (True, dummy))

    #---------------------------------------------------------------------------
    #    Build the instance with data to merge
    #---------------------------------------------------------------------------
    mergeFromInstance = enabler.CreateInstance()

    tstSize = DPoint2d (10.5, 22.3)

    nullBool = ECValue (PrimitiveType.ePRIMITIVETYPE_Boolean)

    mergeFromInstance.SetValue("Name",         ECValue ("merge"))
    mergeFromInstance.SetValue("Count",        ECValue (14))
    mergeFromInstance.SetValue("Field_Tested", nullBool)
    mergeFromInstance.SetValue ("Size",        ECValue (tstSize))

    mbInstance = mergeToInstance.AsMemoryECInstance ()
    mbInstance.MergePropertiesFromInstance (mergeFromInstance)

    expectedValues = [("Count", ECValue(14)), ("StartPoint", ECValue ()), ("EndPoint", ECValue ()), ("Size", ECValue (tstSize)),
                        ("Length", ECValue (142.5)), ("Install_Date",ECValue ()), ("Service_Date", ECValue ()), ("Field_Tested", nullBool), ("Name", ECValue ("merge"))]

    collection = ECValuesCollection.Create (mergeToInstance)
    dumpPropertyValues (collection, False, 0)

    iValue = 0
    verifyECValueEnumeration (collection, expectedValues, iValue, False)


def test_RecursiveECValueEnumeration_PrimitiveArray ():

    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("AllPrimitives").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()

    instance.SetValue("AString",  ECValue ("Happy String"))
    instance.SetValue("AnInt",    ECValue (6))

    instance.AddArrayElements("SomeStrings", 5)

    instance.SetValue("SomeStrings", ECValue ("ArrayMember 1"), 0)
    instance.SetValue("SomeStrings", ECValue ("ArrayMember 2"), 2)
    instance.SetValue("SomeStrings", ECValue ("ArrayMember 3"), 4)

    #---------------------------------------------------------------------------
    #    Build the vector of expected values.
    #    Note: The order does not match the class it matches the classLayout
    #---------------------------------------------------------------------------
    arrayValue = ECValue ()

    expectedValues = [("AnInt",ECValue (6)), ("APoint3d", ECValue ()), ("APoint2d", ECValue ()), ("ADouble", ECValue ()),
                      ("ADateTime", ECValue ()), ("ABoolean", ECValue ()), ("ALong", ECValue ()),
                      ("AString", ECValue ("Happy String")), ("ABinary", ECValue ())]

    arrayValue.Clear()
    arrayValue.SetPrimitiveArrayInfo (ePRIMITIVETYPE_String, 5, False)
    expectedValues.append (("SomeStrings", arrayValue))
    expectedValues.append (("SomeStrings[0]", ECValue ("ArrayMember 1")))
    expectedValues.append (("SomeStrings[1]", ECValue ()))
    expectedValues.append (("SomeStrings[2]", ECValue ("ArrayMember 2")))
    expectedValues.append (("SomeStrings[3]", ECValue ()))
    expectedValues.append (("SomeStrings[4]", ECValue ("ArrayMember 3")))

    #Must create new one, otherwise it has same address to the previous one. Following code also modified. When releasing expectedValues,
    #the same address will be released again, this causes crash
    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Integer, 0, False)
    expectedValues.append (("SomeInts", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Point3D, 0, False)
    expectedValues.append (("SomePoint3ds", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Point2D, 0, False)
    expectedValues.append (("SomePoint2ds", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Double, 0, False)
    expectedValues.append (("SomeDoubles", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_DateTime, 0, False)
    expectedValues.append (("SomeDateTimes", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Boolean, 0, False)
    expectedValues.append (("SomeBooleans", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Long, 0, False)
    expectedValues.append (("SomeLongs", arrayValue))

    arrayValue = ECValue ()
    arrayValue.SetPrimitiveArrayInfo (PrimitiveType.ePRIMITIVETYPE_Binary, 0, False)
    expectedValues.append (("SomeBinaries", arrayValue))

    #---------------------------------------------------------------------------
    #    Verify that the values returned from the instance match the expected ones.
    #---------------------------------------------------------------------------
    collection = ECValuesCollection.Create (instance)
    iValue = 0

    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, False)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)

    #---------------------------------------------------------------------------
    #    Duplicate the instance and verify the duplicate.
    #---------------------------------------------------------------------------
    standAloneInstance = StandaloneECInstance.Duplicate(instance)

    collection = ECValuesCollection.Create (standAloneInstance)
    iValue = 0
    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, True)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)


def buildAccessString (accessPrefix, propertyString):
    accessString = ""
    if (accessPrefix != None and 0 < len (accessPrefix)):
        accessString += accessPrefix
        accessString += "."

    accessString += propertyString

    return accessString

def setValue (accessPrefix, propertyString, ecValue, instance):
    accessString = buildAccessString (accessPrefix, propertyString)
    instance.SetValue (accessString, ecValue)


def setPartialContactInfo (skipPhoneNumberData, prefix, areaCode, phoneNumber, houseNumber,
                            street, town, state, zip, email, instance):
    if (False == skipPhoneNumberData):
        setValue (prefix, "PhoneNumber.AreaCode",  ECValue (areaCode),     instance)
        setValue (prefix, "PhoneNumber.AreaCode",  ECValue (areaCode),     instance)
        setValue (prefix, "PhoneNumber.Number",    ECValue (phoneNumber),  instance)
        setValue (prefix, "Address.HouseNumber",   ECValue (houseNumber),  instance)

    setValue (prefix, "Address.Street",        ECValue (street),       instance)
    setValue (prefix, "Address.Town",          ECValue (town),         instance)
    setValue (prefix, "Address.State",         ECValue (state),        instance)
    setValue (prefix, "Address.Zip",           ECValue (zip),          instance)
    setValue (prefix, "Email",                 ECValue (email),        instance)


def setContactInfo (prefix, areaCode, phoneNumber, houseNumber, street, town,
                    state, zip, email, instance):
    setValue (prefix, "PhoneNumber.AreaCode",  ECValue (areaCode),     instance)
    setValue (prefix, "PhoneNumber.AreaCode",  ECValue (areaCode),     instance)
    setValue (prefix, "PhoneNumber.Number",    ECValue (phoneNumber),  instance)
    setValue (prefix, "Address.HouseNumber",   ECValue (houseNumber),  instance)
    setValue (prefix, "Address.Street",        ECValue (street),       instance)
    setValue (prefix, "Address.Town",          ECValue (town),         instance)
    setValue (prefix, "Address.State",         ECValue (state),        instance)
    setValue (prefix, "Address.Zip",           ECValue (zip),          instance)
    setValue (prefix, "Email",                 ECValue (email),        instance)


def addValue (accessPrefix, propertyString, ecValue, expectedValues):
    accessString = buildAccessString (accessPrefix, propertyString)
    expectedValues.append ((accessString, ecValue))

    #return expectedValues


def addExpectedContactInfo (prefix, areaCode, phoneNumber,houseNumber, street, town,
                            state, zip, email, expectedValues):
    if (None != prefix and 0 < len (prefix)):
        expectedValues.append ((prefix, ECValue (ValueKind.eVALUEKIND_Struct)))

    addValue (prefix, "PhoneNumber",           ECValue (ValueKind.eVALUEKIND_Struct), expectedValues)
    addValue (prefix, "PhoneNumber.AreaCode",  ECValue (areaCode),         expectedValues)
    addValue (prefix, "PhoneNumber.Number",    ECValue (phoneNumber),      expectedValues)
    addValue (prefix, "Address",               ECValue (ValueKind.eVALUEKIND_Struct), expectedValues)
    addValue (prefix, "Address.Zip",           ECValue (zip),              expectedValues)

    addValue (prefix, "Address.HouseNumber",   ECValue (houseNumber),     expectedValues)
    addValue (prefix, "Address.Street",        ECValue (street),          expectedValues)
    addValue (prefix, "Address.Town",          ECValue (town),            expectedValues)
    addValue (prefix, "Address.State",         ECValue (state),           expectedValues)
    addValue (prefix, "Email",                 ECValue (email),           expectedValues)


def test_RecursiveECValueEnumeration_EmbeddedStructs ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("ContactInfo").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()
    setContactInfo ("", 610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "nobody@nowhere.com", instance)

    #---------------------------------------------------------------------------
    #    Build the vector of expected values.
    #    Note: The order does not match the class it matches the classLayout
    #---------------------------------------------------------------------------
    expectedValues = []
    addExpectedContactInfo ("", 610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "nobody@nowhere.com", expectedValues)

    #---------------------------------------------------------------------------
    #    Verify that the values returned from the instance match the expected ones.
    #---------------------------------------------------------------------------
    collection = ECValuesCollection.Create (instance)
    iValue = 0

    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, False)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)

    #---------------------------------------------------------------------------
    #    Duplicate the instance and verify the duplicate.
    #---------------------------------------------------------------------------
    standAloneInstance = StandaloneECInstance.Duplicate(instance)

    collection = ECValuesCollection.Create (standAloneInstance)
    iValue = 0
    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, True)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)


def test_RecursiveECValueEnumeration_StructArray ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("EmployeeDirectory").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()
    instance.AddArrayElements("Employees", 2)

    arrayMemberEnabler = schema.GetClass("Employee").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    v = ECValue ()
    arrayMemberInstance1 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance1.SetValue("Name", ECValue ("John Smith"))

    setContactInfo ("Home",   610, 7654321, "175",   "Oak Lane",    "Wayne", "PA", 12348, "jsmith@home.com", arrayMemberInstance1)
    setContactInfo ("Work",   610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "jsmith@work.com", arrayMemberInstance1)
    v.SetStruct(arrayMemberInstance1)
    instance.SetValue ("Employees", v, 0)

    arrayMemberInstance2 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance2.SetValue("Name", ECValue ("Jane Doe"))
    setContactInfo ("Home",   555, 1122334, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "prez@gmail.com", arrayMemberInstance2)
    setContactInfo ("Work",   555, 1000000, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "president@whitehouse.gov", arrayMemberInstance2)
    v.SetStruct(arrayMemberInstance2)
    instance.SetValue ("Employees", v, 1)

    #---------------------------------------------------------------------------
    #    Build the vector of expected values.
    #    Note: The order does not match the class it matches the classLayout
    #---------------------------------------------------------------------------

    arrayValue = ECValue ()
    arrayValue.SetStructArrayInfo (2, False)

    expectedValues = []
    expectedValues.append (("Employees", arrayValue))

    structValue = ECValue ()
    structValue.SetStruct (arrayMemberInstance1)
    expectedValues.append (("Employees[0]", structValue))

    addExpectedContactInfo ("Employees[0].Home", 610, 7654321, "175",   "Oak Lane",    "Wayne", "PA", 12348, "jsmith@home.com", expectedValues)
    addExpectedContactInfo ("Employees[0].Work", 610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "jsmith@work.com", expectedValues)

    expectedValues.append (("Employees[0].Name", ECValue ("John Smith")))

    #Must create new one, otherwise it has same address to the previous one. Following code also modifys. And when to release memory of expectedValues,
    #the same address will be released two times, this causes crash
    structValue = ECValue ()
    structValue.SetStruct (arrayMemberInstance2)
    expectedValues.append (("Employees[1]", structValue))

    addExpectedContactInfo ("Employees[1].Home", 555, 1122334, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "prez@gmail.com", expectedValues)
    addExpectedContactInfo ("Employees[1].Work", 555, 1000000, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "president@whitehouse.gov", expectedValues)

    expectedValues.append (("Employees[1].Name", ECValue ("Jane Doe")))

    #---------------------------------------------------------------------------
    #    Verify that the values returned from the instance match the expected ones.
    #---------------------------------------------------------------------------
    collection = ECValuesCollection.Create (instance)
    iValue = 0

    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, False)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)

    #---------------------------------------------------------------------------
    #    Duplicate the instance and verify the duplicate.
    #---------------------------------------------------------------------------
    standAloneInstance = StandaloneECInstance.Duplicate(instance)

    collection = ECValuesCollection.Create (standAloneInstance)
    iValue = 0
    iValue = verifyECValueEnumeration (collection, expectedValues, iValue, True)
    #dumpPropertyValues (collection, False, 0)

    EXPECT_TRUE (expectedValues.__len__() == iValue)

#@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_MergeStrupytestArray ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("EmployeeDirectory").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()
    instance.AddArrayElements("Employees", 2)

    arrayMemberEnabler = schema.GetClass("Employee").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (arrayMemberEnabler!= None)

    v = ECValue ()
    arrayMemberInstance1 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance1.SetValue("Name", ECValue ("John Smith"))

    setContactInfo ("Home",   610, 7654321, "175",   "Oak Lane",    "Wayne", "PA", 12348, "jsmith@home.com", arrayMemberInstance1)
    setPartialContactInfo (True, "Work",   610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "jsmith@work.com", arrayMemberInstance1)
    v.SetStruct(arrayMemberInstance1)
    instance.SetValue ("Employees", v, 0)

    arrayMemberInstance2 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance2.SetValue("Name", ECValue ("Jane Doe"))
    setPartialContactInfo (False, "Home",   555, 1122334, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "prez@gmail.com", arrayMemberInstance2)
    setPartialContactInfo (True, "Work",   555, 1000000, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "president@whitehouse.gov", arrayMemberInstance2)
    v.SetStruct(arrayMemberInstance2)
    instance.SetValue ("Employees", v, 1)

    collection = ECValuesCollection.Create (instance)
    originalCount = 0
    count = 0

    originalCount = dumpLoadedPropertyValues  (collection, False, 0, False, originalCount)

    toInstance = enabler.CreateInstance()

    #The MemoryECInstanceBase is not exposed as the base class for StandaloneECInstance in MS SDK, so some functions implemented in C++ in it
    #cannot be bound to Python side. For tests in this file, AsMemoryECInstance() and MergePropertiesFromInstance () are implemented in
    #MemoryECInstanceBase in C++, in python side they cannot be bound to StandaloneECInstance. When calling these functions on
    #StandaloneECInstance python instance, the instance doesn't have these member functions, the calling causes error.
    #Since we cannot change the MS SDK to expose MemoryECInstanceBase as the base class for StandaloneECInstance, so we commented out code
    #related these two functions. 
    #mbInstance = toInstance.AsMemoryECInstance ()
    #mbInstance.MergePropertiesFromInstance (instance)

    collection = ECValuesCollection.Create (toInstance)

    count = dumpLoadedPropertyValues  (collection, False, 0, False, count)
    #ASSERT_TRUE (count==originalCount)
    #ASSERT_TRUE (count==41)

#@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_MergeStructArrayForModifiedInstance ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("EmployeeDirectory").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    #---------------------------------------------------------------------------
    #    Build the first instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()
    instance.AddArrayElements("Employees", 2)

    arrayMemberEnabler = schema.GetClass("Employee").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    v = ECValue ()
    arrayMemberInstance1 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance1.SetValue("Name", ECValue ("John Smith"))

    setContactInfo ("Home",   610, 7654321, "175",   "Oak Lane",    "Wayne", "PA", 12348, "jsmith@home.com", arrayMemberInstance1)
    setPartialContactInfo (True, "Work",   610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "jsmith@work.com", arrayMemberInstance1)
    v.SetStruct(arrayMemberInstance1)
    instance.SetValue ("Employees", v, 0)

    arrayMemberInstance2 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance2.SetValue("Name", ECValue ("Jane Doe"))
    setPartialContactInfo (False, "Home",   555, 1122334, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "prez@gmail.com", arrayMemberInstance2)
    setPartialContactInfo (True, "Work",   555, 1000000, "1600", "Pennsylvania Ave", "Washington", "DC", 10001, "president@whitehouse.gov", arrayMemberInstance2)
    v.SetStruct(arrayMemberInstance2)
    instance.SetValue ("Employees", v, 1)

    collection = ECValuesCollection.Create (instance)
    originalCount1 = 0
    originalCount2 = 0
    count = 0

    originalCount1 = dumpLoadedPropertyValues  (collection, False, 0, False, originalCount1)

    #Build the second Instance
    toInstance = enabler.CreateInstance()
    toInstance.AddArrayElements("Employees", 2)

    v1 = ECValue ()
    setPartialContactInfo(True, "Work", 610, 1234588, "123-4", "Main Street 2", "Exton", "PA", 12345, "jsmith@work.com", arrayMemberInstance1) 
    v1.SetStruct(arrayMemberInstance1)
    toInstance.SetValue("Employees", v1, 0)

    arrayMemberInstance3 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance3.SetValue("Name", ECValue("Jane Doe"))
    setPartialContactInfo(False, "Home", 555, 1122334, "1600", "Pune", "Maharashtra", "DC", 10001, "prez@gmail.com", arrayMemberInstance3)
    setPartialContactInfo(True, "Work", 555, 1000000, "1600", "Pune", "Maharashtra", "DC", 10001, "president@whitehouse.gov", arrayMemberInstance3)

    v1.SetStruct(arrayMemberInstance3)
    toInstance.SetValue("Employees", v1, 1)

    collection = ECValuesCollection.Create(toInstance)
    originalCount2 = dumpLoadedPropertyValues(collection, False, 0, False, originalCount2)

    #The MemoryECInstanceBase is not exposed as the base class for StandaloneECInstance in MS SDK, so some functions implemented in C++ in it
    #cannot be bound to Python side. For tests in this file, AsMemoryECInstance() and MergePropertiesFromInstance () are implemented in
    #MemoryECInstanceBase in C++, in python side they cannot be bound to StandaloneECInstance. When calling these functions on
    #StandaloneECInstance python instance, the instance doesn't have these member functions, the calling causes error.
    #Since we cannot change the MS SDK to expose MemoryECInstanceBase as the base class for StandaloneECInstance, so we commented out code
    #related these two functions. 
    #mbInstance = toInstance.AsMemoryECInstance ()
    #mbInstance.MergePropertiesFromInstance (instance)

    collection = ECValuesCollection.Create (toInstance)

    count = dumpLoadedPropertyValues  (collection, False, 0, False, count)
    ASSERT_TRUE(originalCount1 == originalCount2)
    ASSERT_TRUE (originalCount2 == count)

#@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_MergeStructArrayForSameInstance ():
    schema = CreateTestSchema()
    ASSERT_TRUE(schema!= None)

    enabler = schema.GetClass("EmployeeDirectory").GetDefaultStandaloneEnabler()
    ASSERT_TRUE(enabler!= None)

    #---------------------------------------------------------------------------
    #Build the first instance
    #---------------------------------------------------------------------------
    instance = enabler.CreateInstance()
    instance.AddArrayElements("Employees", 1)

    arrayMemberEnabler = schema.GetClass("Employee").GetDefaultStandaloneEnabler()
    ASSERT_TRUE(enabler!= None)

    v = ECValue ()
    arrayMemberInstance1 = arrayMemberEnabler.CreateInstance()
    arrayMemberInstance1.SetValue("Name", ECValue("John Smith"))

    setContactInfo("Home", 610, 7654321, "175", "Oak Lane", "Wayne", "PA", 12348, "jsmith@home.com", arrayMemberInstance1)
    setPartialContactInfo(True, "Work", 610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "jsmith@work.com", arrayMemberInstance1)
    v.SetStruct(arrayMemberInstance1)
    instance.SetValue("Employees", v, 0)

    collection = ECValuesCollection.Create(instance)
    originalCount1 = 0
    count = 0

    originalCount1 = dumpLoadedPropertyValues(collection, False, 0, False, originalCount1)

    #Build the second Instance
    toInstance = enabler.CreateInstance()
    toInstance.AddArrayElements("Employees", 1)

    v1 = ECValue ()
    v1.SetStruct(arrayMemberInstance1)
    toInstance.SetValue("Employees", v1, 0)

    originalCount2 = 0
    collection = ECValuesCollection.Create(toInstance)
    originalCount2 = dumpLoadedPropertyValues(collection, False, 0, False, originalCount2)

    #The MemoryECInstanceBase is not exposed as the base class for StandaloneECInstance in MS SDK, so some functions implemented in C++ in it
    #cannot be bound to Python side. For tests in this file, AsMemoryECInstance() and MergePropertiesFromInstance () are implemented in
    #MemoryECInstanceBase in C++, in python side they cannot be bound to StandaloneECInstance. When calling these functions on
    #StandaloneECInstance python instance, the instance doesn't have these member functions, the calling causes error.
    #Since we cannot change the MS SDK to expose MemoryECInstanceBase as the base class for StandaloneECInstance, so we commented out code
    #related these two functions. 
    #mbInstance = toInstance.AsMemoryECInstance()
    #mbInstance.MergePropertiesFromInstance(instance)

    collection = ECValuesCollection.Create(toInstance)

    count = dumpLoadedPropertyValues(collection, False, 0, False, count)
    ASSERT_TRUE(originalCount1 == originalCount2)
    ASSERT_TRUE(originalCount1 == count)

def test_MergeStruct ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    enabler = schema.GetClass("Employee").GetDefaultStandaloneEnabler ()
    ASSERT_TRUE (enabler!= None)

    v = ECValue ()
    employeeInstance = enabler.CreateInstance()
    employeeInstance.SetValue("Name", ECValue ("John Smith"))

    setPartialContactInfo (False, "Home",   610, 7654321, "175",   "Oak Lane",    "Wayne", "PA", 12348, "jsmith@home.com", employeeInstance)
    setPartialContactInfo (True, "Work",   610, 1234567, "123-4", "Main Street", "Exton", "PA", 12345, "jsmith@work.com", employeeInstance)

    originalCount = 0
    count = 0

    collection = ECValuesCollection.Create (employeeInstance)
    originalCount = dumpLoadedPropertyValues  (collection, False, 0, False, originalCount)

    toInstance = enabler.CreateInstance()

    mbInstance = toInstance.AsMemoryECInstance ()
    mbInstance.MergePropertiesFromInstance (employeeInstance)

    collection = ECValuesCollection.Create (toInstance)
    count = dumpLoadedPropertyValues  (collection, False, 0, False, count)
    ASSERT_TRUE (count==originalCount)
    ASSERT_TRUE (count==19)


def test_SimpleMergeTwoInstances ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    primitiveClass = schema.GetClass ("AllPrimitives")
    ASSERT_TRUE (None != primitiveClass)

    enabler = primitiveClass.GetDefaultStandaloneEnabler()
    
    sourceInstance0 = enabler.CreateInstance()
    sourceInstance1 = enabler.CreateInstance()
    targetInstance  = enabler.CreateInstance()

    v = ECValue ()
    v.SetDouble(1.0/3.0)
    sourceInstance0.SetValue("ADouble", v)
    v.SetString("Weaker source instance")
    sourceInstance0.SetValue("AString", v)
    v.SetInteger(234)
    sourceInstance0.SetValue("AnInt", v)
    v.SetInteger(50)
    sourceInstance0.AddArrayElements("SomeInts", 4)
    sourceInstance0.SetValue("SomeInts", v, 0)
    v.SetInteger(60)
    sourceInstance0.SetValue("SomeInts", v, 1)
    v.SetInteger(70)
    sourceInstance0.SetValue("SomeInts", v, 2)
    v.SetInteger(80)
    sourceInstance0.SetValue("SomeInts", v, 3)

    v.SetDouble(10.0/3.0)
    sourceInstance1.SetValue("ADouble", v)
    v.SetLong(2345978)
    sourceInstance1.SetValue("ALong", v)
    v.SetString("Dominant source instance")
    sourceInstance1.SetValue("AString", v)
    v.SetInteger(99999999)
    sourceInstance1.AddArrayElements("SomeInts", 4)
    sourceInstance1.SetValue("SomeInts", v, 1)

    #Merging two instances into a third instance:
    #In this example, values from sourceInstance 1 will take precedence over 
    #values in sourceInstance0 in the even that neither are null.
    #Note that in Options.Create (), the second flag is set to True: in this
    #case, it is wise to include accessors that have null values.
    collection = ECValuesCollection.Create (sourceInstance1)

    for propertyValue in collection:
        ecValue = propertyValue.GetValue()
        localValue = ECValue ()

        if (False == ecValue.IsPrimitive()):
            continue

        accessor = propertyValue.GetValueAccessor()

        #If the value from instance1 is NULL, try to get it from instance0
        if (ecValue.IsNull()):
            sourceInstance0.GetValueUsingAccessor (localValue, accessor)
            ecValue = localValue

        #set the value to target instance
        if(False == ecValue.IsNull()):
            targetInstance.SetValueUsingAccessor (accessor, ecValue)

    valuesCounted = 0
    targetCollection = ECValuesCollection.Create (targetInstance)

    for propertyValue in targetCollection:
        if (False == propertyValue.GetValue().IsPrimitive()):
            continue

        valuesCounted += 1
        #wprintf("%ls: %ls\n", propertyValue.GetValueAccessor().GetManagedAccessString(), propertyValue.GetValue().ToString())


    #Verify that the merge succeeded
    EXPECT_EQ (9, valuesCounted)
    targetInstance.GetValue (v, "AnInt") #Came from sourceInstance0
    EXPECT_EQ (234, v.GetInteger())
    targetInstance.GetValue (v, "ADouble")  #Came from sourceInstance1
    EXPECT_EQ (10.0/3.0, v.GetDouble())


def test_InstantiateStandaloneInstance ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("TestClass")
    ASSERT_TRUE (None != ecClass)

    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    instanceId = instance.GetInstanceId()
    instance.ToString("").GetWCharCP()
    ExerciseInstance (instance, "Test")


def test_InstantiateInstanceWithNoProperties ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("EmptyClass")
    ASSERT_TRUE (None != ecClass)

    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    instanceId = instance.GetInstanceId()

    instance.ToString("").GetWCharCP()


def test_DirectSetStandaloneInstance ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("CadData")
    ASSERT_TRUE (None != ecClass)
    
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()

    inSize = DPoint2d (10.5, 22.3)
    inPoint1 = DPoint3d (10.10, 11.11, 12.12)
    inPoint2 = DPoint3d (200.100, 210.110, 220.120)
    inTimeUtc = BeDateTime.GetCurrentTimeUtc ()
    inCount = 100
    inLength = 432.178
    inTest = True
    inTicks = 634027121070910000
    
    instance.SetValue ("Count",        ECValue (inCount))
    instance.SetValue ("Name",         ECValue ("Test"))
    instance.SetValue ("Length",       ECValue (inLength))
    instance.SetValue ("Field_Tested", ECValue (inTest, False))

    ecValue = ECValue ()
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Field_Tested"))
    EXPECT_TRUE (ecValue.GetBoolean() == inTest)

    instance.SetValue ("Size",         ECValue (inSize))
    instance.SetValue ("StartPoint",   ECValue (inPoint1))
    instance.SetValue ("EndPoint",     ECValue (inPoint2))
    instance.SetValue ("Service_Date", ECValue (inTimeUtc))

    ecValue = ECValue ()
    ecValue.SetDateTimeTicks(inTicks)
    instance.SetValue ("Install_Date", ecValue)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Count"))
    EXPECT_TRUE (ecValue.GetInteger() == inCount)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Name"))
    EXPECT_STREQ (ecValue.GetString(), "Test")
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Length"))
    EXPECT_TRUE (ecValue.GetDouble() == inLength)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Field_Tested"))
    res = ecValue.GetBoolean()
    EXPECT_TRUE (ecValue.GetBoolean() == inTest)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Size"))
    point2d = ecValue.GetPoint2D ()
    EXPECT_TRUE (inSize == point2d)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "StartPoint"))
    point3d = ecValue.GetPoint3D ()
    EXPECT_TRUE (inPoint1 == point3d)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "EndPoint"))
    point3d = ecValue.GetPoint3D ()
    EXPECT_TRUE (inPoint2 == point3d)
    #in absence of the DateTimeInfo custom attribute on Service_Date the retrieved
    #date time will always be of kind Unspecified, i.e. the original kind (here Utc)
    #gets lost
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Service_Date"))
    sysTime = ecValue.GetDateTime ()
    EXPECT_TRUE (inTimeUtc.EqualTo (sysTime, True))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (ecValue, "Install_Date"))
    EXPECT_TRUE (ecValue.GetDateTimeTicks() == inTicks)

    #instance.Compact()... then check values again

def test_GetSetValuesByIndex ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("TestClass")
    ASSERT_TRUE (None != ecClass)
    
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()

    accessString = "Property34"

    #UInt32          intValue = 12345
    stringValue = "Xyz"

    #instance.SetValue  (accessString, ECValue (intValue))
    instance.SetValue  (accessString, ECValue (stringValue))

    value = ECValue ()
    propertyIndex=0

    retVal, propertyIndex = enabler.GetPropertyIndex (accessString)
    EXPECT_TRUE (BentleyStatus.eSUCCESS  == retVal)
    EXPECT_TRUE (BentleyStatus.eSUCCESS  == instance.GetValue (value, propertyIndex))
    #EXPECT_TRUE (intValue == value.GetInteger())
    EXPECT_STREQ (stringValue, value.GetString())

#if defined (TIMING_ACCESS_BYINDEX)
    #   numAccesses = 10000000

    #double      elapsedTime1 = 0.0
    #StopWatch   timer1 ("Time getting values using index", True)

    #for (i = 0 i < numAccesses i+= 1)
    
    #    timer1.Start()
    #    instance.GetValue (value, propertyIndex)
    #    timer1.Stop()

    #    elapsedTime1 += timer1.GetElapsedSeconds()


    #double      elapsedTime2 = 0.0
    #StopWatch   timer2 ("Time getting values using accessString", True)

    #for (i = 0 i < numAccesses i+= 1)
    
    #    timer2.Start()
    #    instance.GetValue (value, accessString)
    #    timer2.Stop()

    #    elapsedTime2 += timer2.GetElapsedSeconds()


    #wprintf ("Time to set %d values by: accessString = %.4f, index = %.4f\n", numAccesses, elapsedTime1, elapsedTime2)
#endif

    #instance.Compact()... then check values again

def failedCases (instance):
    #DISABLE_ASSERTS
    assertDisabler = AssertDisabler ()  #To avoid compile error by bb r MSPythonSamples, comment this temporary

    #if False == FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
        #verify we can not change the size of fixed arrays        
        #ASSERT_EQ (FIXED_COUNT_ARRAYS_ARE_SUPPORTED ? True : False, ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("FixedArrayFixedElement", 0, 1))
        #ASSERT_EQ (FIXED_COUNT_ARRAYS_ARE_SUPPORTED ? True : False, ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("FixedArrayFixedElement", 10, 1))
        #ASSERT_EQ (FIXED_COUNT_ARRAYS_ARE_SUPPORTED ? True : False, ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.AddArrayElements    ("FixedArrayFixedElement", 1))
        #ASSERT_EQ (FIXED_COUNT_ARRAYS_ARE_SUPPORTED ? True : False, ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("FixedArrayVariableElement", 0, 1))
        #ASSERT_EQ (FIXED_COUNT_ARRAYS_ARE_SUPPORTED ? True : False, ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("FixedArrayVariableElement", 12, 1))
        #ASSERT_EQ (FIXED_COUNT_ARRAYS_ARE_SUPPORTED ? True : False, ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.AddArrayElements    ("FixedArrayVariableElement", 1))


    #verify constraints of array insertion are enforced
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("NonExistArray", 0, 1))
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("BeginningArray", 2, 1)) #insert index is invalid    
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.InsertArrayElements ("BeginningArray", 0, 0)) #insert count is invalid    

def test_ExpectErrorsWhenViolatingArrayConstraints ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("TestClass")
    ASSERT_TRUE (None != ecClass)
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()

    failedCases (instance)
    
    v = ECValue ()
    VerifyOutOfBoundsError (instance, v, "BeginningArray", 0)
    VerifyOutOfBoundsError (instance, v, "FixedArrayFixedElement", 10)
    VerifyOutOfBoundsError (instance, v, "VariableArrayFixedElement", 0)
    VerifyOutOfBoundsError (instance, v, "FixedArrayVariableElement", 12)
    VerifyOutOfBoundsError (instance, v, "VariableArrayVariableElement", 0)
    VerifyOutOfBoundsError (instance, v, "EndingArray", 0)             


def test_Values (): #move it!
    i = ECValue (3)
    EXPECT_TRUE (i.IsInteger())
    EXPECT_TRUE (False == i.IsNull())
    EXPECT_EQ (3, i.GetInteger())

    i.SetInteger(4)
    EXPECT_EQ (4, i.GetInteger())
    
    i.SetString("Type changed to string")
    EXPECT_TRUE (i.IsString())
    EXPECT_TRUE (False == i.IsNull())
    EXPECT_STREQ ("Type changed to string", i.GetString())
    
    i.Clear()
    EXPECT_TRUE (i.IsUninitialized())
    EXPECT_TRUE (i.IsNull())
    
    v = ECValue ()
    EXPECT_TRUE (v.IsUninitialized())
    EXPECT_TRUE (v.IsNull())
    
    doubleValue = 1./3.
    v.SetDouble(doubleValue)
    EXPECT_TRUE (v.IsDouble())
    EXPECT_EQ (doubleValue, v.GetDouble())
    
    nullInt = ECValue (PrimitiveType.ePRIMITIVETYPE_Integer)
    EXPECT_TRUE (nullInt.IsNull())
    EXPECT_TRUE (nullInt.IsInteger())

    #For C++ ECValue (::Int64), if we only pass 3 to it, in pybind11 logic, currently it calls ECValue (Int32)
    #for this case. To prevent this implicit convert, for its corresponding binding in pybind11 side, we implement its pybind11
    #binding as ECValue (::Int64, bool), a bool parameter is added to prevent this implicit convert
    long64 = ECValue (3, False)
    EXPECT_TRUE (False == long64.IsNull())
    EXPECT_TRUE (long64.IsLong())  #Ping Chen
    EXPECT_EQ (3, long64.GetLong())

    s = ECValue ("Hello")
    EXPECT_TRUE (s.IsString())
    EXPECT_TRUE (False == s.IsNull())
    EXPECT_STREQ ("Hello", s.GetString())
    ws = s.GetString()
    
    s.SetString("Nice one")
    EXPECT_STREQ ("Nice one", s.GetString())
    
    s.SetString(None)  #different from C++, in C++, it passes a NULL pointer, in python pass None
    EXPECT_TRUE (s.IsNull())
    EXPECT_TRUE (None == s.GetString())
    
    snull = ECValue (None) #different from C++, in C++, it passes a NULL pointer, in python pass None
    EXPECT_TRUE (snull.IsString())
    EXPECT_TRUE (snull.IsNull())
    #wcnull = snull.GetString()
    EXPECT_EQ (None, s.GetString())
    
    #bool
    dummy=False
    boolVal = ECValue (True, dummy)
    EXPECT_TRUE (boolVal.IsBoolean())
    EXPECT_TRUE (boolVal.GetBoolean())

    #DPoint3d
    inPoint3 = DPoint3d (10.0, 100.0, 1000.0)
    pntVal3 = ECValue (inPoint3)
    outPoint3 = pntVal3.GetPoint3D ()
    EXPECT_TRUE (pntVal3.IsPoint3D())
    EXPECT_TRUE (inPoint3 == outPoint3)
    point3Str = pntVal3.ToString()
    EXPECT_TRUE (0 == point3Str.CompareTo ("10,100,1000"))

    #DPoint2d
    inPoint2 = DPoint2d (10.0, 100.0)
    pntVal2 = ECValue (inPoint2)
    EXPECT_TRUE (pntVal2.IsPoint2D())
    outPoint2 = pntVal2.GetPoint2D ()
    EXPECT_TRUE (inPoint2 == outPoint2)
    point2Str = pntVal2.ToString()
    EXPECT_TRUE (0 == point2Str.CompareTo ("10,100"))

    #DateTime
    nowUtc = BeDateTime.GetCurrentTimeUtc ()
    dateValue = ECValue (nowUtc)
    EXPECT_TRUE (dateValue.IsDateTime())
    nowToo = dateValue.GetDateTime ()
    EXPECT_TRUE (nowToo.EqualTo (nowUtc, True))

    fixedDate = ECValue ()
    fixedDate.SetDateTimeTicks (634027121070910000)
    dateStr = fixedDate.ToString()

    bRes = 0 == dateStr.CompareTo ("2010-02-25T16:28:27.091")
    EXPECT_TRUE (bRes)
    if False == bRes:
        print ("Expected date:  {0}\n".format (fixedDate.GetDateTime ().ToString ().GetWCharCP ()))


def test_TestSetGetNull ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("TestClass")
    ASSERT_TRUE (None != ecClass)
        
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    v = ECValue ()
    
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, "D"))
    EXPECT_TRUE (v.IsNull())
    
    doubleValue = 1.0/3.0
    SetAndVerifyDouble (instance, v, "D", doubleValue)
    EXPECT_TRUE (False == v.IsNull())
    
    v.SetToNull()
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("D", v))
    v.SetString("Just making sure that it is not NULL before calling GetValue in the next line.")
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, "D"))
    EXPECT_TRUE (v.IsNull())
        
    SetAndVerifyString (instance, v, "S", "Yo!")

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, "D"))
    EXPECT_TRUE (v.IsNull())
    
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, "S"))
    EXPECT_FALSE (v.IsNull()) 

def test_TestPropertyReadOnly ():
    #"    <ECClass typeName=\"Car\" isStruct=\"True\" isDomainClass=\"True\">"
    #"        <ECProperty       propertyName=\"Name\"       typeName=\"string\"/>"
    #"        <ECProperty       propertyName=\"Wheels\"     typeName=\"int\"  readOnly=\"True\"/>"
    #"    </ECClass>"

    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("Car")
    ASSERT_TRUE (None != ecClass)
        
    enabler = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    
    nameAccessString = "Name"
    wheelsAccessString = "Wheels"
    namePropertyIndex = 9999
    wheelsPropertyIndex = 9998
    retVal, namePropertyIndex = enabler.GetPropertyIndex (nameAccessString)
    EXPECT_TRUE (BentleyStatus.eSUCCESS == retVal)
    retVal, wheelsPropertyIndex = enabler.GetPropertyIndex (wheelsAccessString)
    EXPECT_TRUE (BentleyStatus.eSUCCESS == retVal)

    EXPECT_FALSE (instance.IsPropertyReadOnly (nameAccessString))
    EXPECT_FALSE (instance.IsPropertyReadOnly (namePropertyIndex))

    EXPECT_TRUE  (instance.IsPropertyReadOnly (wheelsAccessString))
    EXPECT_TRUE  (instance.IsPropertyReadOnly (wheelsPropertyIndex))  

    v = ECValue ()
    v.SetInteger(610)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue (wheelsAccessString, v))  #should work since original value is NULL
    v.SetInteger(512)
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_UnableToSetReadOnlyProperty == instance.SetValue (wheelsAccessString, v))  #should fail since read only and value is not NULL

    #make sure we can copy an instance contains read only properties
    copyInstance =  StandaloneECInstance.Duplicate (instance)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, wheelsAccessString))
    EXPECT_TRUE (610 == v.GetInteger())

    #make sure we can deserialize and instance from XML that contains read only properties
    ecInstanceXml = WString ("")
    instance.WriteToXmlString (ecInstanceXml, True, False)

    instanceContext = ECInstanceReadContext.CreateContext (schema, None, None)

    retVal, deserializedInstance = IECInstance.ReadFromXmlString(ecInstanceXml.GetWCharCP(), instanceContext)
    EXPECT_TRUE (InstanceReadStatus.eINSTANCE_READ_STATUS_Success == retVal)
    EXPECT_TRUE (BentleyStatus.eSUCCESS == deserializedInstance.GetValue (v, wheelsAccessString))
    EXPECT_TRUE (610 == v.GetInteger())


def test_TestBinarySetGet ():
    HOLD_AS_DUPLICATE = True
    binaryValue0 = bytes([0x00, 0x01, 0x02, 0x03])
    binaryValue1 = bytes([0x99, 0x88])

    EXPECT_EQ (len(binaryValue0), 4)
    EXPECT_EQ (len(binaryValue1), 2)

    v0In = ECValue ()
    v0Out = ECValue ()
    v1In = ECValue ()
    v1Out = ECValue ()

    v0In.SetBinary(binaryValue0)
    v1In.SetBinary(binaryValue1)

    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("AllPrimitives")
    ASSERT_TRUE (None != ecClass)
        
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("ABinary", v0In))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v0Out, "ABinary"))
    EXPECT_TRUE (v0In == v0Out)

    #now set it to a smaller size
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("ABinary", v1In))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v1Out, "ABinary"))
    EXPECT_TRUE (v1In == v1Out)


def validateArrayCount  (instance, propertyName, expectedCount):
    varray = ECValue ()
    EXPECT_TRUE (BentleyStatus.eSUCCESS == instance.GetValue (varray, propertyName))
    count = varray.GetArrayInfo().GetCount()
    EXPECT_TRUE (count == expectedCount)

    ventry = ECValue ()
    for i in range (count):
        EXPECT_TRUE (BentleyStatus.eSUCCESS == instance.GetValue (ventry, propertyName, i))


def test_TestRemovingArrayEntries ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("ArrayTest")
    ASSERT_TRUE (None != ecClass)
        
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    
    # if False == FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
    #     EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayFixedElement",  ECValue ((int)1), 1))
    #     EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayFixedElement",  ECValue ((int)3), 3))
    #     EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayFixedElement",  ECValue ((int)5), 5))
    #     EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayFixedElement",  ECValue ((int)7), 7))
    #     EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayFixedElement",  ECValue ((int)9), 9))

        #{
        #DISABLE_ASSERTS    
        #EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.RemoveArrayElement("FixedArrayFixedElement", 2))
        #}

        # EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayVariableElement", ECValue ("ArrayMember 1"), 1))
        # EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayVariableElement", ECValue ("ArrayMember 3"), 3))
        # EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayVariableElement", ECValue ("ArrayMember 5"), 5))
        # EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayVariableElement", ECValue ("ArrayMember 7"), 7))
        # EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayVariableElement", ECValue ("ArrayMember 9"), 9))
        # EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("FixedArrayVariableElement", ECValue ("ArrayMember 11"), 11))

        #{
        #DISABLE_ASSERTS    
        #EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success != instance.RemoveArrayElement("FixedArrayVariableElement", 2))
        #}


    instance.AddArrayElements("SomeStrings", 5)

    EXPECT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("SomeStrings",  ECValue ("ArrayMember 0"), 0))
    EXPECT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("SomeStrings",  ECValue ("ArrayMember 1"), 1))
    EXPECT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("SomeStrings",  ECValue ("ArrayMember 2"), 2))
    #leave index 3 null
    EXPECT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("SomeStrings",  ECValue ("ArrayMember 4"), 4))

    validateArrayCount (instance, "SomeStrings", 5) 

    instance.AddArrayElements("SomeInts", 6)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("SomeInts",  ECValue (0), 0))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("SomeInts",  ECValue (1), 1))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("SomeInts",  ECValue (2), 2))
    #leave index 3 null
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("SomeInts",  ECValue (4), 4))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("SomeInts",  ECValue (5), 5))

    validateArrayCount (instance, "SomeInts", 6) 

    #define struct array
    manufacturerEnabler = instance.GetEnabler ().GetEnablerForStructArrayMember (schema.GetSchemaKey(), "Manufacturer") 
    EXPECT_TRUE (manufacturerEnabler!= None)

    v = ECValue ()
    ASSERT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.AddArrayElements ("ManufacturerArray", 4))
    VerifyArrayInfo (instance, v, "ManufacturerArray", 4, False)
    VerifyIsNullArrayElements (instance, v, "ManufacturerArray", 0, 4, True)

    manufInst = manufacturerEnabler.CreateInstance()

    SetAndVerifyString (manufInst, v, "Name", "Nissan")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 3475)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("ManufacturerArray", v, 0))

    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Kia")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 1791)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("ManufacturerArray", v, 1))

    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Honda")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 1592)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("ManufacturerArray", v, 2))

    manufInst = manufacturerEnabler.CreateInstance()
    SetAndVerifyString (manufInst, v, "Name", "Chevy")
    SetAndVerifyInteger (manufInst, v, "AccountNo", 19341)
    v.SetStruct (manufInst)
    ASSERT_TRUE (BentleyStatus.eSUCCESS == instance.SetValue ("ManufacturerArray", v, 3))

    VerifyIsNullArrayElements (instance, v, "ManufacturerArray", 0, 4, False)

    #remove from start of array
    instance.RemoveArrayElement("SomeStrings", 0)
    validateArrayCount (instance, "SomeStrings", 4) 

    #remove from middle of array
    instance.RemoveArrayElement("SomeStrings", 2)
    validateArrayCount (instance, "SomeStrings", 3) 

    #remove from end of array
    instance.RemoveArrayElement("SomeInts", 2)
    validateArrayCount (instance, "SomeInts", 5)

    #remove struct array element
    instance.RemoveArrayElement("ManufacturerArray", 2)
    validateArrayCount (instance, "ManufacturerArray", 3)

def test_IterateCompleClass ():
    schema = CreateTestSchema()
    ASSERT_TRUE (schema!= None)

    ecClass = schema.GetClass ("ComplexClass")
    ASSERT_TRUE (None != ecClass)
        
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()

    dummy = False
    b = ECValue (True, dummy)
    s1 = ECValue ("719372644")
    s2 = ECValue ("asasdasd")
    s3 = ECValue ("1338164264")
    s4 = ECValue ("string val")
    s5 = ECValue ("asdasdas")
    s6 = ECValue ("392010267")
    i1 = ECValue (1683483880)
    i2 = ECValue (1367822242)
    i3 = ECValue (32323)
    d1 = ECValue (0.71266461290077521)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("StringProperty", s4))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("IntProperty", i2))

    structArrayEnabler = schema.GetClass("StructClass").GetDefaultStandaloneEnabler ()
    structInstance = structArrayEnabler.CreateInstance()

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("BooleanProperty", b))
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_PropertyValueMatchesNoChange == instance.ChangeValue ("BooleanProperty", b))
    if False == FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.AddArrayElements ("SimpleArrayProperty", 1))

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("SimpleArrayProperty", s1, 0))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("StructProperty.StringProperty", s2))
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_PropertyValueMatchesNoChange == instance.ChangeValue ("StructProperty.StringProperty", s2))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("StructProperty.IntProperty", i1))
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_PropertyValueMatchesNoChange == instance.ChangeValue ("StructProperty.IntProperty", i1))
    if False == FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.AddArrayElements ("StructProperty.ArrayProperty", 1))

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("StructProperty.ArrayProperty", s3, 0))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("DoubleProperty", d1))
    EXPECT_TRUE (ECObjectsStatus.eECOBJECTS_STATUS_PropertyValueMatchesNoChange == instance.ChangeValue ("DoubleProperty", d1))

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==structInstance.SetValue ("StringProperty", s5))
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==structInstance.SetValue ("IntProperty", i3))
    if False == FIXED_COUNT_ARRAYS_ARE_SUPPORTED:
        EXPECT_TRUE (BentleyStatus.eSUCCESS ==structInstance.AddArrayElements ("ArrayProperty", 1))

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==structInstance.SetValue ("ArrayProperty", s6, 0))

#if FIXED_COUNT_ARRAYS_ARE_SUPPORTED
    #This is a fixed-size struct array so we don't have to insert members
#else
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.AddArrayElements ("StructArrayProperty", 1))
#endif
    structVal = ECValue ()
    structVal.SetStruct (structInstance)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("StructArrayProperty", structVal, 0))

    #ensure we can walk the properties
    collection = ECValuesCollection.Create (instance)
    #dumpPropertyValues (collection, False, 0)

#@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_MergeArrayPropertyWithSmallerArray ():
    retVal, testSchema = ECSchema.CreateSchema(WString ("TestSchema"), 1, 2)
    retVal, class1 = testSchema.CreateClass(WString ("TestClass"))
    retVal, primitiveArrayProp = class1.CreateArrayProperty(WString ("PrimitiveArray"))
    primitiveArrayProp.SetPrimitiveElementType (PrimitiveType.ePRIMITIVETYPE_Long)

    enabler       = class1.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()

    instance.AddArrayElements("PrimitiveArray", 3)
    v = ECValue ()
    v.SetLong(0)
    instance.SetValue("PrimitiveArray", v, 0)

    v.SetLong(1)
    instance.SetValue("PrimitiveArray", v, 1)

    v.SetLong(2)
    instance.SetValue("PrimitiveArray", v, 2)

    secondInstance = enabler.CreateInstance()
    secondInstance.AddArrayElements("PrimitiveArray", 2)
    v.SetLong(3)
    secondInstance.SetValue("PrimitiveArray", v, 0)

    v.SetLong(4)
    secondInstance.SetValue("PrimitiveArray", v, 1)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==secondInstance.GetValue (v, "PrimitiveArray"))
    EXPECT_EQ (2, v.GetArrayInfo().GetCount())

    v.Clear()

    #The MemoryECInstanceBase is not exposed as the base class for StandaloneECInstance in MS SDK, so some functions implemented in C++ in it
    #cannot be bound to Python side. For tests in this file, AsMemoryECInstance() and MergePropertiesFromInstance () are implemented in
    #MemoryECInstanceBase in C++, in python side they cannot be bound to StandaloneECInstance. When calling these functions on
    #StandaloneECInstance python instance, the instance doesn't have these member functions, the calling causes error.
    #Since we cannot change the MS SDK to expose MemoryECInstanceBase as the base class for StandaloneECInstance, so we commented out code
    #related these two functions. 
    #mbInstance = instance.AsMemoryECInstance ()
    #mbInstance.MergePropertiesFromInstance (secondInstance)

    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.GetValue (v, "PrimitiveArray"))

    #TFS#128233
    EXPECT_EQ (3, v.GetArrayInfo().GetCount()) #CGM: This line fails because it merges the array values instead of overwriting

    instance.GetValue(v, "PrimitiveArray", 0)
    EXPECT_EQ(0, v.GetLong())

    instance.GetValue(v, "PrimitiveArray", 1)
    EXPECT_EQ(1, v.GetLong())

def SetStringToSpecifiedNumberOfCharacters (instance, nChars):
    string = WString (nChars + 1, '\0')
    string[0] = '\0'

    for i in range (nChars):
        digit = i % 10
        digitAsString = str (digit)
        string += WString (digitAsString)

    v = ECValue ()(string)
    EXPECT_TRUE (BentleyStatus.eSUCCESS ==instance.SetValue ("S", v))


def SetValuesForProfiling (instance):
    for it in s_propertyNames:
        instance.SetValue (it.GetWCharCP(), ECValue (it.GetWCharCP()))

#@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_ProfileSettingValues ():
    nStrings = 100
    nInstances = 1000

    schema      = CreateProfilingSchema(nStrings)
    ecClass     = schema.GetClass ("Pidget")
    ASSERT_TRUE (None != ecClass)
        
    enabler       = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    
    #UInt32 slack = 0
    #elapsedSeconds = 0.0
    #StopWatch timer ("Time setting of values in a new StandaloneECInstance", True)
    for i in range (nInstances):    
        #timer.Start()
        SetValuesForProfiling (instance)
        #timer.Stop()

        #elapsedSeconds += timer.GetElapsedSeconds()

        #The MemoryECInstanceBase is not exposed as the base class for StandaloneECInstance in MS SDK, so some functions implemented in C++ in it
        #cannot be bound to Python side. For tests in this file, AsMemoryECInstance() and MergePropertiesFromInstance () are implemented in
        #MemoryECInstanceBase in C++, in python side they cannot be bound to StandaloneECInstance. When calling these functions on
        #StandaloneECInstance python instance, the instance doesn't have these member functions, the calling causes error.
        #Since we cannot change the MS SDK to expose MemoryECInstanceBase as the base class for StandaloneECInstance, so we commented out code
        #related these two functions. 
        #instance.AsMemoryECInstance().ClearValues() 

    #wprintf ("  %d StandaloneECInstances with %d string properties initialized in %.4f seconds.\n", nInstances, nStrings, elapsedSeconds)

def test_TestValueAccessor ():
    accessor = ECValueAccessor ()
