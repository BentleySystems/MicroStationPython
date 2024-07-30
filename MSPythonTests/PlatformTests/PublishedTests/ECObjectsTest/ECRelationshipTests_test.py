#--------------------------------------------------------------------------------------+
#
#     $Source: test/Published/ECRelationshipTests.cpp $
#
#  $Copyright: (c) 2013 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------/
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

#---------------------------------------------------------------------------------/#
# @bsimethod                                                    JoshSchifter    12/09
#---------------#---------------#---------------#---------------#---------------#------/
def GetTestSchemaXMLString ():
    fmt = WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                    "<ECSchema schemaName=\"RelationshipTesting\" nameSpacePrefix=\"test\" version=\"1.0\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">"
                    "    <ECClass typeName=\"ClassA\" displayLabel=\"Class A\" isDomainClass=\"True\">"
                    "        <ECProperty propertyName=\"p\" typeName=\"int\" />"
                    "    </ECClass>"
                    "    <ECClass typeName=\"ClassB\" displayLabel=\"Class B\" isDomainClass=\"True\">"
                    "        <ECProperty propertyName=\"p\" typeName=\"int\" />"
                    "        <ECProperty propertyName=\"b\" typeName=\"int\" />"
                    "    </ECClass>"
                    "    <ECRelationshipClass typeName=\"ALikesB\" displayLabel=\"A likes B\" strength=\"referencing\">"
                    "        <Source cardinality=\"(1,1)\" roleLabel=\"likes\" polymorphic=\"False\">"
                    "            <Class class=\"ClassA\" />"
                    "        </Source>"
                    "        <Target cardinality=\"(1,1)\" roleLabel=\"is liked by\" polymorphic=\"True\">"
                    "            <Class class=\"ClassB\" />"
                    "        </Target>"
                    "        <ECProperty propertyName=\"p\" typeName=\"int\" />"
                    "        <ECProperty propertyName=\"Name\" typeName=\"string\" />"
                    "        <ECProperty propertyName=\"SourceOrderId\" typeName=\"int\" />"
                    "        <ECProperty propertyName=\"TargetOrderId\" typeName=\"int\" />"
                    "    </ECRelationshipClass>"
                    "</ECSchema>")

    return fmt


#---------------------------------------------------------------------------------/#
# @bsimethod                                    Bill.Steinbock                  04/2012
#---------------#---------------#---------------#---------------#---------------#------/
def CreateTestSchema ():
    schemaXMLString = GetTestSchemaXMLString ()
    schemaContext = ECSchemaReadContext.CreateContext()

    ret, schema = ECSchema.ReadFromXmlString (schemaXMLString.GetWCharCP (), schemaContext)
    EXPECT_EQ (BentleyStatus.eSUCCESS, ret)

    return schema

class TestECRelationshipTests:
    #---------------------------------------------------------------------------------/#
    # @bsimethod                                    Bill.Steinbock                  04/2012
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_SimpleRelationship (self):
        schema = CreateTestSchema()
        ASSERT_TRUE (schema != None)

        sourceClass = schema.GetClass ("ClassA")
        ASSERT_TRUE (None != sourceClass)
        sourceEnabler =  sourceClass.GetDefaultStandaloneEnabler()
        ASSERT_TRUE (sourceEnabler != None)

        targetClass = schema.GetClass ("ClassB")
        ASSERT_TRUE (None != targetClass)
        targetEnabler = targetClass.GetDefaultStandaloneEnabler()
        ASSERT_TRUE (targetEnabler != None)

        p1 = ECValue ()
        p1.SetInteger (123)

        sourceInstance = sourceEnabler.CreateInstance()
        sourceInstance.SetValue("p", p1)
        sourceInstance.SetInstanceId(WString ("source").GetWCharCP ())

        p2 = ECValue ()
        b2 = ECValue ()
        p2.SetInteger (456)
        b2.SetInteger (789)
        targetInstance = targetEnabler.CreateInstance()
        targetInstance.SetValue("p", p2)
        targetInstance.SetValue("b", b2)
        targetInstance.SetInstanceId(WString ("target").GetWCharCP ())

        relClass = schema.GetClass ("ALikesB").GetRelationshipClass ()
        ASSERT_TRUE (None != relClass)

        relationshipEnabler = StandaloneECRelationshipEnabler (relClass)
        ASSERT_TRUE (relationshipEnabler != None)

        relationshipInstance = relationshipEnabler.CreateRelationshipInstance ()
        relationshipInstance.SetSource (sourceInstance)
        relationshipInstance.SetTarget (targetInstance)
        relationshipInstance.SetInstanceId (WString ("source.target").GetWCharCP ())

        readSource = relationshipInstance.GetSource()
        readValue = ECValue ()
        readSource.GetValue (readValue, "p")
        ASSERT_TRUE (readValue == p1)

        readTarget = relationshipInstance.GetTarget()
        readTarget.GetValue (readValue, "p")
        ASSERT_TRUE (readValue == p2)
        readTarget.GetValue (readValue, "b")
        ASSERT_TRUE (readValue == b2)

    #---------------------------------------------------------------------------------/#
    # @bsimethod                                    Bill.Steinbock                  04/2012
    #---------------#---------------#---------------#---------------#---------------#------/
    def test_SetRelationshipProperties (self):
        schema = CreateTestSchema()
        ASSERT_TRUE (schema != None)

        sourceClass = schema.GetClass ("ClassA")
        ASSERT_TRUE (None != sourceClass)
        sourceEnabler =  sourceClass.GetDefaultStandaloneEnabler()
        ASSERT_TRUE (sourceEnabler != None)

        targetClass = schema.GetClass ("ClassB")
        ASSERT_TRUE (None != targetClass)
        targetEnabler =  targetClass.GetDefaultStandaloneEnabler()
        ASSERT_TRUE (targetEnabler != None)

        p1 = ECValue ()
        p1.SetInteger (123)

        sourceInstance = sourceEnabler.CreateInstance()
        sourceInstance.SetValue("p", p1)
        sourceInstance.SetInstanceId(WString ("source").GetWCharCP ())

        p2 = ECValue ()
        b2 = ECValue ()
        p2.SetInteger (456)
        b2.SetInteger (789)
        targetInstance = targetEnabler.CreateInstance()
        targetInstance.SetValue("p", p2)
        targetInstance.SetValue("b", b2)
        targetInstance.SetInstanceId(WString ("target").GetWCharCP ())

        relClass = schema.GetClass ("ALikesB")
        ASSERT_TRUE (None != relClass)

        relationshipEnabler = StandaloneECRelationshipEnabler (relClass)
        ASSERT_TRUE (relationshipEnabler != None)

        relationshipInstance = relationshipEnabler.CreateRelationshipInstance ()
        relationshipInstance.SetSource (sourceInstance)
        relationshipInstance.SetTarget (targetInstance)
        relationshipInstance.SetInstanceId (WString ("source.target").GetWCharCP ())

        rel_p = ECValue ()
        rel_name = ECValue ()
        rel_sourceOrder = ECValue ()
        rel_targetOrder = ECValue ()
        rel_p.SetInteger (777)
        rel_sourceOrder.SetInteger (888)
        rel_targetOrder.SetInteger (999)
        rel_name.SetString ("my_relationship")

        EXPECT_TRUE (BentleyStatus.eSUCCESS == relationshipInstance.SetValue ("p", rel_p))
        EXPECT_TRUE (BentleyStatus.eSUCCESS == relationshipInstance.SetValue ("Name", rel_name))
        EXPECT_TRUE (BentleyStatus.eSUCCESS == relationshipInstance.SetValue ("SourceOrderId", rel_sourceOrder))
        EXPECT_TRUE (BentleyStatus.eSUCCESS == relationshipInstance.SetValue ("TargetOrderId", rel_targetOrder))

        readSource = relationshipInstance.GetSource()
        readValue = ECValue ()
        readSource.GetValue (readValue, "p")
        ASSERT_TRUE (readValue == p1)

        readTarget = relationshipInstance.GetTarget()
        readTarget.GetValue (readValue, "p")
        ASSERT_TRUE (readValue == p2)
        readTarget.GetValue (readValue, "b")
        ASSERT_TRUE (readValue == b2)

        ecInstanceXml = WString ()
        status2 = relationshipInstance.WriteToXmlString (ecInstanceXml, True, True)
        EXPECT_EQ(eINSTANCE_WRITE_STATUS_Success, status2)
