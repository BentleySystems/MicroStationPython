#--------------------------------------------------------------------------------------+
#
#     $Source: test/Published/DateTimeInfoCustomAttributeTests.cpp $
#
#  $Copyright: (c) 2014 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------*/
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

from typing import List

#********************** DateTimeInfoTestFixture base classes *************************************
#=======================================================================================
# @bsiclass                                                 Ping.Chen      02/2013
#+===============+===============+===============+===============+===============+======
class DateTimeInfoTestFixture :
    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023
    #+---------------+---------------+---------------+---------------+---------------+------
    def AssertDateTime (expected, actual, ignoreDateTimeInfo):
        #expectedActualStr = WString ()
        expectedActualStr = "Expected: {0} - Actual: {1}".format (expected.ToString (), actual.ToString ())

        if (ignoreDateTimeInfo):
            bCompareRes = BeDateTime.Compare (expected, actual)
            #EXPECT_TRUE (bCompareRes != CompareResult.Error)
            #if (False == bCompareRes):
            #    print ("DateTimes are expected to be equal except for date time info. ") << expectedActualStr.GetWCharCP ()

            #EXPECT_FALSE (expected == actual) 
            ##<< "DateTime metadata is expected to differ. " << expectedActualStr.GetWCharCP ()
        #else:
            #EXPECT_TRUE (expected == actual) ##<< "DateTimes are expected to be equal. " << expectedActualStr.GetWCharCP ()

    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023                               
    #+---------------+---------------+---------------+---------------+---------------+------
    def DeserializeSchema (context, schemaXml):
        EXPECT_FALSE (Utf8String.IsNullOrEmpty (schemaXml.__repr__()))

        context = ECSchemaReadContext.CreateContext ()

        stat, schema = ECSchema.ReadFromXmlString (schemaXml.__repr__(), context)
        EXPECT_EQ (eSCHEMA_READ_STATUS_Success, stat)
        EXPECT_TRUE (None != schema)

        return schema


    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023                               
    #+---------------+---------------+---------------+---------------+---------------+------
    def CreateTestSchema (context):
        testSchemaXml = Utf8String ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
            "<ECSchema schemaName=\"StandardClassesHelperTest\" nameSpacePrefix=\"t\" version=\"01.00\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">"
            "   <ECSchemaReference name=\"Bentley_Standard_CustomAttributes\" version=\"01.05\" prefix=\"bsca\" />"
            "   <ECClass typeName=\"TestClass\" isDomainClass=\"True\">"
            "        <ECProperty propertyName=\"nodatetimeinfo\" typeName=\"dateTime\" />"
            "        <ECProperty propertyName=\"emptydatetimeinfo\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"utc\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeKind>Utc</DateTimeKind>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"unspecified\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeKind>Unspecified</DateTimeKind>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"local\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeKind>Local</DateTimeKind>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"garbagekind\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeKind>Garbage</DateTimeKind>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"dateonly\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeComponent>Date</DateTimeComponent>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"garbagecomponent\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeComponent>Garbage</DateTimeComponent>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECProperty propertyName=\"garbagekindgarbagecomponent\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeKind>Garbage</DateTimeKind>"
            "                   <DateTimeComponent>Garbage</DateTimeComponent>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"                    
            "        <ECArrayProperty propertyName=\"dateTimeArrayProp\" typeName=\"dateTime\" minOccurs=\"0\" maxOccurs=\"unbounded\">"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo xmlns=\"Bentley_Standard_CustomAttributes.01.05\">"
            "                   <DateTimeKind>Utc</DateTimeKind>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECArrayProperty>"                    
            "        <ECProperty propertyName=\"intProp\" typeName=\"int\" />"
            "        <ECArrayProperty propertyName=\"intArrayProp\" typeName=\"int\" minOccurs=\"0\" maxOccurs=\"unbounded\"/>"
            "    </ECClass>"
            "</ECSchema>")

        return DateTimeInfoTestFixture.DeserializeSchema (context, testSchemaXml)


#=======================================================================================
# @bsiclass                                                 Ping.Chen      02/2013
#+===============+===============+===============+===============+===============+======
class StandardCustomAttributeHelperTestFixture (DateTimeInfoTestFixture) :
    class ExpectedResult:
        # def __init__ (self, kind, component) :
        #     self.m_HasDateTimeInfo = True
        #     self.m_hasKind = True
        #     self.m_kind = kind
        #     self.m_hasComponent = True
        #     self.m_component = component

        # def __init__ (self, kind : BeDateTime.Kind) :
        #     self.m_HasDateTimeInfo = True
        #     self.m_hasKind = True
        #     self.m_kind = kind
        #     self.m_hasComponent = False

        # def __init__ (self, component : BeDateTime.Component) :
        #     self.m_HasDateTimeInfo = True
        #     self.m_hasKind = False
        #     self.m_hasComponent = True
        #     self.m_component = component

        # def __init__ (self) :
        #     self.m_HasDateTimeInfo = False
        def __init__(self, kind=None, component=None, **kwargs):  
                if kind is not None and component is not None:
                    self.m_HasDateTimeInfo = True
                    self.m_hasKind = True
                    self.m_kind = kind
                    self.m_hasComponent = True
                    self.m_component = component
                elif kind is not None:  
                    self.m_HasDateTimeInfo = True  
                    self.m_hasKind = True  
                    self.m_kind = kind  
                    self.m_hasComponent = False  
                elif component is not None:  
                    self.m_HasDateTimeInfo = True  
                    self.m_hasKind = False  
                    self.m_hasComponent = True  
                    self.m_component = component  
                else:  
                    self.m_HasDateTimeInfo = False  
                    self.m_hasKind = False  
                    self.m_hasComponent = False

    class ExpectedResultPerProperty:
        def __init__(self, first, second):
            self.first = first
            self.second = second

    ExpectedResults = List[ExpectedResultPerProperty]

    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023                               
    #+---------------+---------------+---------------+---------------+---------------+------
    def Assert (dateTimeProperty, expected):
        actual = DateTimeInfo ()
        found = StandardCustomAttributeHelper.TryGetDateTimeInfo (actual, dateTimeProperty)
        EXPECT_EQ (expected.m_HasDateTimeInfo, found)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023                               
    #+---------------+---------------+---------------+---------------+---------------+------
    def CreateTestSchema (context, expectedResults):
        expectedResults.clear ()

        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("nodatetimeinfo", StandardCustomAttributeHelperTestFixture.ExpectedResult ()))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("emptydatetimeinfo", StandardCustomAttributeHelperTestFixture.ExpectedResult ()))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("utc", StandardCustomAttributeHelperTestFixture.ExpectedResult (kind = BeDateTime.Kind.eUtc)))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("unspecified", StandardCustomAttributeHelperTestFixture.ExpectedResult (kind = BeDateTime.Kind.eUnspecified)))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("local", StandardCustomAttributeHelperTestFixture.ExpectedResult (kind = BeDateTime.Kind.eLocal)))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("garbagekind", StandardCustomAttributeHelperTestFixture.ExpectedResult ()))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("dateonly", StandardCustomAttributeHelperTestFixture.ExpectedResult (component=BeDateTime.Component.eDate)))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("garbagecomponent", StandardCustomAttributeHelperTestFixture.ExpectedResult ()))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("garbagekindgarbagecomponent", StandardCustomAttributeHelperTestFixture.ExpectedResult ()))
        expectedResults.append (StandardCustomAttributeHelperTestFixture.ExpectedResultPerProperty ("dateTimeArrayProp", StandardCustomAttributeHelperTestFixture.ExpectedResult (kind=BeDateTime.Kind.eUtc)))

        return DateTimeInfoTestFixture.CreateTestSchema (context)


    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023                               
    #+---------------+---------------+---------------+---------------+---------------+------
    def CreateTestSchemaNotReferencingBSCA (context):
        testSchemaXml = Utf8String ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
            "<ECSchema schemaName=\"StandardClassesHelperTest\" nameSpacePrefix=\"t\" version=\"01.00\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">"
            "   <ECClass typeName=\"TestClass\" isDomainClass=\"True\">"
            "        <ECProperty propertyName=\"prop1\" typeName=\"dateTime\" />"
            "        <ECProperty propertyName=\"prop2\" typeName=\"int\" />"
            "    </ECClass>"
            "</ECSchema>")

        return DateTimeInfoTestFixture.DeserializeSchema (context, testSchemaXml)

    #---------------------------------------------------------------------------------------
    # @bsimethod                                   Ping.Chen                  12/2023                               
    #+---------------+---------------+---------------+---------------+---------------+------
    def CreateTestSchemaWithCorruptDateTimeInfoCA (context):
        testSchemaXml = Utf8String ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
            "<ECSchema schemaName=\"StandardClassesHelperTest\" nameSpacePrefix=\"t\" version=\"01.00\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">"
            "   <ECClass typeName=\"DateTimeInfo\" isDomainClass=\"False\" isCustomAttributeClass=\"True\" >"
            "        <ECProperty propertyName=\"SomethingUnexpected\" typeName=\"string\" />"
            "   </ECClass>"
            "   <ECClass typeName=\"TestClass\" isDomainClass=\"True\">"
            "        <ECProperty propertyName=\"prop\" typeName=\"dateTime\" >"
            "           <ECCustomAttributes>"
            "               <DateTimeInfo>"
            "                   <SomethingUnexpected>Utc</SomethingUnexpected>"
            "               </DateTimeInfo>"
            "           </ECCustomAttributes>"
            "        </ECProperty>"
            "    </ECClass>"
            "</ECSchema>")

        return DateTimeInfoTestFixture.DeserializeSchema (context, testSchemaXml)


#=======================================================================================
# @bsiclass                                                 Ping.Chen      02/2013
#+===============+===============+===============+===============+===============+======
class ECInstanceGetSetDateTimeTestFixture (DateTimeInfoTestFixture) :
    def AssertSetValue (instance, propertyName, expectedKindIsNull, expectedComponentIsNull, expectedInfo):
        testDateTimes = []
        testDateTimes.append (BeDateTime.GetCurrentTimeUtc ())
        testDateTimes.append (BeDateTime (BeDateTime.Kind.eUnspecified, 2013, 2, 18, 14, 22))
        testDateTimes.append (BeDateTime (2013, 2, 18))

        for testDateTime in testDateTimes:
            value = ECValue ()
            EXPECT_EQ (BentleyStatus.eSUCCESS, value.SetDateTime (testDateTime)) ##<< "Return value of ECValue.SetDateTime"

            actualInfo = testDateTime.GetInfo ()
            isExpectedToSucceed = (expectedKindIsNull or expectedInfo.GetKind () == actualInfo.GetKind ()) and (expectedComponentIsNull or expectedInfo.GetComponent () == actualInfo.GetComponent ())
            if (False == isExpectedToSucceed):
                ##DISABLE_ASSERTS
                stat = instance.SetValue (propertyName, value)
                EXPECT_NE (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) ##<< "IECInstance.SetValue with a mismatching DateTimeKind> Property: " << propertyName #<< " DateTime: " << testDateTime.ToString ().GetWCharCP ()
            else:
                stat = instance.SetValue (propertyName, value)
                EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) ##<< "IECInstance.SetValue with a matching DateTimeKind> Property: " << propertyName #<< " DateTime: " << testDateTime.ToString ().GetWCharCP ()


    def AssertGetValue (instance, propertyName, expectedDateTime, expectedMatch):
        value = ECValue (expectedDateTime)
        ASSERT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, instance.SetValue (propertyName, value)) ##<< "AssertGetValue:Setup> Setting datetime value in ECInstance"

        retVal, expectedTicks = expectedDateTime.ToCommonEraTicks ()

        stat = instance.GetValue (value, propertyName)
        ASSERT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) ##<< "IECInstance.GetValue"

        actualDateTime = value.GetDateTime ()

        actualTicks, actualHasMetadata, actualMetadata = value.GetDateTimeTicksEx ()

        if (expectedMatch):
            if (actualHasMetadata):
                EXPECT_TRUE (expectedDateTime == actualDateTime) ##<< "Instance.GetValue (" << propertyName #<< ") returned mismatching dateTime. Expected: " << expectedDateTime.ToString ().GetWCharCP () #<< ". Actual: " << actualDateTime.ToString ().GetWCharCP ()
            if (actualHasMetadata):
                EXPECT_TRUE (expectedDateTime.GetInfo () == actualMetadata)

            EXPECT_EQ (expectedTicks, actualTicks)
        else:
            EXPECT_FALSE (expectedDateTime == actualDateTime) ##<< "Instance.GetValue (" << propertyName #<< ") returned matching dateTime. Expected: " << expectedDateTime.ToString ().GetWCharCP () #<< ". Actual: " << actualDateTime.ToString ().GetWCharCP ()
            if (actualHasMetadata):
                EXPECT_FALSE (expectedDateTime.GetInfo () == actualMetadata)

            EXPECT_EQ (expectedTicks, actualTicks)


#********************** StandardCustomAttributeHelper Tests *************************************
#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_TryGetDateTimeInfo ():
    expectedResults : StandardCustomAttributeHelperTestFixture.ExpectedResults = []
    context = None
    testSchema = StandardCustomAttributeHelperTestFixture.CreateTestSchema (context, expectedResults)
    
    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    for result in expectedResults:
        prop = testClass.GetProperty (result.first)
        ASSERT_TRUE (prop != None)
        StandardCustomAttributeHelperTestFixture.Assert (prop, result.second)

#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_TryGetDateTimeInfoInSchemaNotReferencingBSCA ():
    context = None
    testSchema = StandardCustomAttributeHelperTestFixture.CreateTestSchemaNotReferencingBSCA (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    prop = testClass.GetProperty ("prop1")
    dti = DateTimeInfo ()
    found = StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, prop)
    EXPECT_FALSE (found) ##<< "No DateTimeInfo CA expected on property that doesn't have the DateTimeInfo CA"


#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_TryGetDateTimeForNonDateTimeProperties ():
    expectedResults : StandardCustomAttributeHelperTestFixture.ExpectedResults = []
    context = None
    testSchema = StandardCustomAttributeHelperTestFixture.CreateTestSchema (context, expectedResults)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    prop = testClass.GetProperty ("intProp")
    ASSERT_TRUE (prop != None)
    #DISABLE_ASSERTS
    assertDisabler = AssertDisabler ()

    dti = DateTimeInfo ()
    found = StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, prop)
    EXPECT_FALSE (found)  #ASSERT_FALSE

    prop = testClass.GetProperty ("intArrayProp")
    ASSERT_TRUE (prop != None)
    found = StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, prop)
    EXPECT_FALSE (found)  #ASSERT_FALSE

#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_TryGetDateTimeInfoWithCorruptCADefinition ():
    context = None
    testSchema = StandardCustomAttributeHelperTestFixture.CreateTestSchemaWithCorruptDateTimeInfoCA (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    #DISABLE_ASSERTS
    prop = testClass.GetProperty ("prop")
    dti = DateTimeInfo ()
    found = StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, prop)
    EXPECT_FALSE (found)


#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_DateTimeInfoToString ():
    expectedResults : StandardCustomAttributeHelperTestFixture.ExpectedResults = []
    context = None
    testSchema = StandardCustomAttributeHelperTestFixture.CreateTestSchema (context, expectedResults)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    dti = DateTimeInfo ()
    str = dti.ToString ()
    EXPECT_TRUE (str.IsEmpty ()) ##<< "DateTimeInfo.ToString () is expected to return an empty string on an empty DateTimeInfo."

    ecproperty = testClass.GetProperty ("nodatetimeinfo")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_TRUE (str.IsEmpty ()) #<< "DateTimeInfo.ToString () is expected to return an empty string for an ECProperty not having the DateTimeInfo custom attribute."

    ecproperty = testClass.GetProperty ("emptydatetimeinfo")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_TRUE (str.IsEmpty ()) #<< "DateTimeInfo.ToString () is expected to return an empty string for an ECProperty having an empty DateTimeInfo custom attribute."

    ecproperty = testClass.GetProperty ("utc")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_STREQ ("Kind: Utc", str.GetWCharCP ()) #<< "DateTimeInfo.ToString ()"

    ecproperty = testClass.GetProperty ("unspecified")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_STREQ ("Kind: Unspecified", str.GetWCharCP ()) #<< "DateTimeInfo.ToString ()"

    ecproperty = testClass.GetProperty ("local")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_STREQ ("Kind: Local", str.GetWCharCP ()) ##<< "DateTimeInfo.ToString ()"

    ecproperty = testClass.GetProperty ("dateonly")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_STREQ ("Component: Date", str.GetWCharCP ()) ##<< "DateTimeInfo.ToString ()"

    ecproperty = testClass.GetProperty ("garbagekind")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_TRUE (str.IsEmpty ()) ##<< "DateTimeInfo.ToString () is expected to return an empty string for an ECProperty having an DateTimeInfo custom attribute with garbage content."

    ecproperty = testClass.GetProperty ("garbagecomponent")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_TRUE (str.IsEmpty ()) ##<< "DateTimeInfo.ToString () is expected to return an empty string for an ECProperty having an DateTimeInfo custom attribute with garbage content."

    ecproperty = testClass.GetProperty ("garbagekindgarbagecomponent")
    dti = DateTimeInfo ()
    StandardCustomAttributeHelper.TryGetDateTimeInfo (dti, ecproperty)
    str = dti.ToString ()
    EXPECT_TRUE (str.IsEmpty ()) ##<< "DateTimeInfo.ToString () is expected to return an empty string for an ECProperty having an DateTimeInfo custom attribute with garbage content."


#********************** ECInstance SetValue / GetValue Tests *************************************
#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_SetDateTime ():
    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "nodatetimeinfo", True, True, BeDateTimeInfo ())
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "emptydatetimeinfo", True, True, BeDateTimeInfo ())
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "utc", False, True, BeDateTimeInfo (BeDateTime.Kind.eUtc, BeDateTime.Component.eDateAndTime))
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "unspecified", False, True, BeDateTimeInfo (BeDateTime.Kind.eUnspecified, BeDateTime.Component.eDateAndTime))
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "dateonly", True, False, BeDateTimeInfo (BeDateTime.Kind.eUnspecified, BeDateTime.Component.eDate))

    #wrong values are treated as if the meta data wasn't specified
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "garbagekind", True, True, BeDateTimeInfo ())
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "garbagecomponent", True, True, BeDateTimeInfo ())
    ECInstanceGetSetDateTimeTestFixture.AssertSetValue (instance, "garbagekindgarbagecomponent", True, True, BeDateTimeInfo ())


#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_SetDateTimeTicks ():
    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    expectedDate = BeDateTime.GetCurrentTimeUtc ()
    retVal, ceTicks = expectedDate.ToCommonEraTicks ()
    ASSERT_EQ (BentleyStatus.eSUCCESS, retVal)

    ticksOnlyValue = ECValue ()
    ticksOnlyValue.SetDateTimeTicks (ceTicks)
    ticksWithUtc = ECValue ()
    ticksWithUtc.SetDateTimeTicks (ceTicks, BeDateTimeInfo (BeDateTime.Kind.eUtc, BeDateTime.Component.eDateAndTime))

    ticksWithDateOnly = ECValue ()
    ticksWithDateOnly.SetDateTimeTicks (ceTicks, BeDateTimeInfo (BeDateTime.Kind.eUnspecified, BeDateTime.Component.eDate))

    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    stat = instance.SetValue ("nodatetimeinfo", ticksOnlyValue)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECProperty without DateTimeInfo - ECValue.SetDateTimeTicks (ticks): Expected to never mismatch with the DateTimeInfo custom attribute."
    
    stat = instance.SetValue ("emptydatetimeinfo", ticksOnlyValue)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> Empty DateTimeInfo - ECValue.SetDateTimeTicks (ticks): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("unspecified", ticksOnlyValue)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECValue.SetDateTimeTicks (ticks): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("dateonly", ticksOnlyValue)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECValue.SetDateTimeTicks (ticks): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("garbagekind", ticksOnlyValue)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECValue.SetDateTimeTicks (ticks): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("garbagekindgarbagecomponent", ticksOnlyValue)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECValue.SetDateTimeTicks (ticks): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("nodatetimeinfo", ticksWithUtc)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECProperty without DateTimeInfo - ECValue.SetDateTimeTicks (ticks, Info): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("nodatetimeinfo", ticksWithDateOnly)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> ECProperty without DateTimeInfo - ECValue.SetDateTimeTicks (ticks, Info): Expected to never mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("utc", ticksWithUtc)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> DateTimeInfo (Utc)  - ECValue.SetDateTimeTicks (ticks, Utc): Expected to match with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("utc", ticksWithDateOnly)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, stat) #<< "IECInstance.SetValue> DateTimeInfo (Utc)  - ECValue.SetDateTimeTicks (ticks, Date): Expected to mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("dateonly", ticksWithUtc)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, stat) #<< "IECInstance.SetValue> DateTimeInfo (Date)  - ECValue.SetDateTimeTicks (ticks, Utc): Expected to mismatch with the DateTimeInfo custom attribute."

    stat = instance.SetValue ("dateonly", ticksWithDateOnly)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat) #<< "IECInstance.SetValue> DateTimeInfo (Date)  - ECValue.SetDateTimeTicks (ticks, Date): Expected to match with the DateTimeInfo custom attribute."


#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_SetDateTimeTicksGetAsDateTime ():
    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)
    propertyName = "nodatetimeinfo"

    #test 1: Original date is UTC
    expectedDate = BeDateTime.GetCurrentTimeUtc ()
    retVal, expectedTicks = expectedDate.ToCommonEraTicks ()
    ASSERT_EQ (BentleyStatus.eSUCCESS, retVal)

    v = ECValue ()
    stat = v.SetDateTimeTicks (expectedTicks)
    EXPECT_EQ (BentleyStatus.eSUCCESS, stat)
    
    actualDate = v.GetDateTime ()
    EXPECT_EQ (BeDateTime.Kind.eUnspecified, actualDate.GetInfo ().GetKind ())
    DateTimeInfoTestFixture.AssertDateTime (expectedDate, actualDate, True)

    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ecstat = instance.SetValue (propertyName, v)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, ecstat)

    actualValue = ECValue ()
    ecstat = instance.GetValue (actualValue, propertyName)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, ecstat)

    actualDate = actualValue.GetDateTime ()
    EXPECT_EQ (BeDateTime.Kind.eUnspecified, actualDate.GetInfo ().GetKind ())
    DateTimeInfoTestFixture.AssertDateTime (expectedDate, actualDate, True)

    #test 2: Original date is Unspecified
    expectedDate = BeDateTime (BeDateTime.Kind.eUnspecified, 2013, 2, 2, 13, 14)
    retVal, expectedTicks = expectedDate.ToCommonEraTicks ()
    ASSERT_EQ (BentleyStatus.eSUCCESS, retVal)

    v.Clear ()
    stat = v.SetDateTimeTicks (expectedTicks)
    EXPECT_EQ (BentleyStatus.eSUCCESS, stat)

    actualDate = v.GetDateTime ()
    EXPECT_EQ (BeDateTime.Kind.eUnspecified, actualDate.GetInfo ().GetKind ())
    DateTimeInfoTestFixture.AssertDateTime (expectedDate, actualDate, False)

    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ecstat = instance.SetValue (propertyName, v)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, ecstat)

    actualValue.Clear ()
    ecstat = instance.GetValue (actualValue, propertyName)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, ecstat)

    actualDate = actualValue.GetDateTime ()
    EXPECT_EQ (BeDateTime.Kind.eUnspecified, actualDate.GetInfo ().GetKind ())
    DateTimeInfoTestFixture.AssertDateTime (expectedDate, actualDate, False)

    #test 3: Original date has component Date
    expectedDate = BeDateTime (2013, 2, 2)
    retVal, expectedTicks = expectedDate.ToCommonEraTicks ()
    ASSERT_EQ (BentleyStatus.eSUCCESS, retVal)

    v.Clear ()
    stat = v.SetDateTimeTicks (expectedTicks)
    EXPECT_EQ (BentleyStatus.eSUCCESS, stat)

    actualDate = v.GetDateTime ()
    EXPECT_EQ (BeDateTime.Kind.eUnspecified, actualDate.GetInfo ().GetKind ())
    DateTimeInfoTestFixture.AssertDateTime (expectedDate, actualDate, True)

    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ecstat = instance.SetValue (propertyName, v)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, ecstat)

    actualValue.Clear ()
    ecstat = instance.GetValue (actualValue, propertyName)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, ecstat)

    actualDate = actualValue.GetDateTime ()
    EXPECT_EQ (BeDateTime.Kind.eUnspecified, actualDate.GetInfo ().GetKind ())
    DateTimeInfoTestFixture.AssertDateTime (expectedDate, actualDate, True)


#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_SetDateTimeWithLocalDateTimeKind ():
    testDateTimes = []
    testDateTimes.append (BeDateTime (BeDateTime.Kind.eUtc, 2013, 2, 18, 14, 22))
    testDateTimes.append (BeDateTime (BeDateTime.Kind.eUnspecified, 2013, 2, 18, 14, 22))
    testDateTimes.append (BeDateTime (BeDateTime.Kind.eLocal, 2013, 2, 18, 14, 22))
    testDateTimes.append (BeDateTime (2013, 2, 18))

    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    localDateTimePropName = "local"

    #DISABLE_ASSERTS
    assertDisabler = AssertDisabler ()

    for testDateTime in testDateTimes:    
        isLocal = testDateTime.GetInfo ().GetKind () == BeDateTime.Kind.eLocal

        value = ECValue ()
        expectedStat = BentleyStatus.eERROR if isLocal else BentleyStatus.eSUCCESS
        EXPECT_EQ (expectedStat, value.SetDateTime (testDateTime)) #<< "Return value of ECValue.SetDateTime ('" << testDateTime.ToString ().GetWCharCP () #<< "')"
 
        retVal, ceTicks = testDateTime.ToCommonEraTicks ()
        EXPECT_EQ (expectedStat, value.SetDateTimeTicks (ceTicks, testDateTime.GetInfo ())) #<< "Return value of ECValue.SetDateTimeTicks () with '" << value.ToString ().GetWCharCP ()

        value = ECValue (testDateTime)
        if False == isLocal:
            EXPECT_FALSE (value.IsNull ()) #<< "ECValue (DateTime) is expected to return an ECValue which is not IsNull if the passed DateTime was not local."
            EXPECT_TRUE (testDateTime == value.GetDateTime ()) #<< "ECValue.GetDateTime () is expected to return a non-empty DateTime if the passed DateTime was not local."
        else:
            EXPECT_TRUE (value.IsNull ()) #<< "ECValue (local DateTime) is expected to return an ECValue which is IsNull."
            EXPECT_TRUE (BeDateTime () == value.GetDateTime ()) #<< "ECValue (local DateTime).GetDateTime () is expected to return an empty DateTime."

        instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
        ASSERT_TRUE (instance != None)

        if False == isLocal:
            EXPECT_NE (ECObjectsStatus.eECOBJECTS_STATUS_Success, instance.SetValue (localDateTimePropName, value)) #<< "IECInstance.SetValue> Property name: " << localDateTimePropName #<< " DateTime: " << testDateTime.ToString ().GetWCharCP ()
        else:
            EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, instance.SetValue (localDateTimePropName, value)) #<< "IECInstance.SetValue> Property name: " << localDateTimePropName #<< " with a local date time is expected to succeed, but the inserted value is null."

#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_GetDateTime ():
    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    expectedDateTime = BeDateTime (BeDateTime.Kind.eUtc, 2013, 2, 18, 14, 28, 34, 1234567)

    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "utc", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "nodatetimeinfo", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "emptydatetimeinfo", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagekind", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagekindgarbagecomponent", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagecomponent", expectedDateTime, False)

    #Unspecified is the default kind, therefore any property that doesn't have a kind CA value (or an invalid value) return
    #a matching date time
    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    expectedDateTime = BeDateTime (BeDateTime.Kind.eUnspecified, 2013, 2, 18, 14, 28, 34, 1234567)

    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "unspecified", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "nodatetimeinfo", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "emptydatetimeinfo", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagekind", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagekindgarbagecomponent", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagecomponent", expectedDateTime, True)

    #DateTime is the default component. Therefore any property that 
    #doesn't have a component CA value (or an invalid value) returns a mismatching date time
    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    expectedDateTime = BeDateTime (2013, 2, 18)

    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "dateonly", expectedDateTime, True)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "nodatetimeinfo", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "emptydatetimeinfo", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagekind", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagekindgarbagecomponent", expectedDateTime, False)
    ECInstanceGetSetDateTimeTestFixture.AssertGetValue (instance, "garbagecomponent", expectedDateTime, False)


#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_DateTimeArrayRoundtrip ():
    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)
    propertyName = "dateTimeArrayProp"
    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    expectedArraySize = 3
    expected = [None] * expectedArraySize

    expected[0] = BeDateTime.GetCurrentTimeUtc ()
    expected[1] = BeDateTime (BeDateTime.Kind.eUtc, 2012, 1, 1, 13, 14)
    expected[2] = BeDateTime (BeDateTime.Kind.eUtc, 2011, 1, 1, 13, 14)

    instance.AddArrayElements (propertyName, expectedArraySize)
    for i in range (expectedArraySize):
        v = ECValue (expected[i])
        stat = instance.SetValue (propertyName, v, i)
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat)

    actualArrayInfoValue = ECValue ()
    stat = instance.GetValue (actualArrayInfoValue, propertyName)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat)
    EXPECT_TRUE (actualArrayInfoValue.IsArray ())

    actualArrayInfo = actualArrayInfoValue.GetArrayInfo ()
    EXPECT_TRUE (PrimitiveType.ePRIMITIVETYPE_DateTime == actualArrayInfo.GetElementPrimitiveType ())
    EXPECT_EQ (expectedArraySize, actualArrayInfo.GetCount ())

    for i in range (expectedArraySize):
        v = ECValue ()
        stat = instance.GetValue (v, propertyName, i)
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat)

        actual = v.GetDateTime ()
        DateTimeInfoTestFixture.AssertDateTime (expected[i], actual, False)

#---------------------------------------------------------------------------------------
# @bsimethod                                   Ping.Chen                  12/2023                               
#+---------------+---------------+---------------+---------------+---------------+------
def test_SetDateTimeArrayWithMismatchingArrayElements ():
    context = None
    testSchema = DateTimeInfoTestFixture.CreateTestSchema (context)

    testClass = testSchema.GetClass ("TestClass")
    ASSERT_TRUE (testClass != None)

    propertyName = "dateTimeArrayProp"
    instance = testClass.GetDefaultStandaloneEnabler ().CreateInstance ()
    ASSERT_TRUE (instance != None)

    expectedArraySize = 3
    expected = [None] * expectedArraySize
    expectedSuccess = [None] * expectedArraySize

    expected[0] = BeDateTime.GetCurrentTimeUtc ()
    expectedSuccess[0] = ECObjectsStatus.eECOBJECTS_STATUS_Success
    expected[1] = BeDateTime (BeDateTime.Kind.eUnspecified, 2012, 1, 1, 13, 14)
    expectedSuccess[1] = ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch
    expected[2] = BeDateTime (2011, 1, 1)
    expectedSuccess[2] = ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch
    
    instance.AddArrayElements (propertyName, expectedArraySize)
    for i in range (expectedArraySize):
        v = ECValue (expected[i])
        stat = instance.SetValue (propertyName, v, i)
        EXPECT_EQ (expectedSuccess[i], stat)

    #retrieving the date time from the one array element that was inserted successfully
    actualArrayInfoValue = ECValue ()
    stat = instance.GetValue (actualArrayInfoValue, propertyName)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat)
    EXPECT_TRUE (actualArrayInfoValue.IsArray ())

    actualArrayInfo = actualArrayInfoValue.GetArrayInfo ()
    EXPECT_TRUE (PrimitiveType.ePRIMITIVETYPE_DateTime == actualArrayInfo.GetElementPrimitiveType ())
    #array was initialized with the full size, although only one element was actually successfully inserted.
    EXPECT_EQ (expectedArraySize, actualArrayInfo.GetCount ())

    for i in range (expectedArraySize):
        v = ECValue ()
        stat = instance.GetValue (v, propertyName, i)
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, stat)

        if (expectedSuccess[i] == ECObjectsStatus.eECOBJECTS_STATUS_Success):
            actual = v.GetDateTime ()
            DateTimeInfoTestFixture.AssertDateTime (expected[i], actual, False)
        else:
            EXPECT_TRUE (v.IsDateTime () and v.IsNull ())