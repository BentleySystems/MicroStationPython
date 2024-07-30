#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

class InstanceLabelTest:
    s_className = "A"

    def createSchema (self):
        context = ECSchemaReadContext.CreateContext ()
        schemaKey = SchemaKey ("Bentley_Standard_CustomAttributes", 1, 5)
        customAttributesSchema = context.LocateSchema (schemaKey, SchemaMatchType.eSCHEMAMATCHTYPE_Latest)
        self.customAttributeEnabler = customAttributesSchema.GetClass ("InstanceLabelSpecification").GetDefaultStandaloneEnabler()
        surccessOrNot, self.schema = ECSchema.CreateSchema (WString ("TestSchema"), 1, 0)
        self.schema.AddReferencedSchema (customAttributesSchema)

    def createClass (self, className, hasInstanceLabelAttribute, instanceLabelPropertyName):
        wsClassName = WString (className)
        surccessOrNot, ecClass = self.schema.CreateClass (wsClassName)
        wsPropertyName = WString (instanceLabelPropertyName)
        surccessOrNot, prop = ecClass.CreatePrimitiveProperty (wsPropertyName, PrimitiveType.ePRIMITIVETYPE_String)

        if (hasInstanceLabelAttribute):
            labelAttr = self.customAttributeEnabler.CreateInstance()
            if (instanceLabelPropertyName != None):
                v = ECValue ()
                v.SetString (wsPropertyName, False)

            labelAttr.SetValue ("PropertyName", v)
            ecClass.SetCustomAttribute (labelAttr)

        return ecClass


    def testInstanceLabel (self, hasInstanceLabelAttribute, instanceLabelPropertyName, instanceLabelPropertyValue):
        ecClass = self.createClass (self.s_className, hasInstanceLabelAttribute, instanceLabelPropertyName)
        instance = ecClass.GetDefaultStandaloneEnabler().CreateInstance()

        if (None != instanceLabelPropertyValue):
            wsInstanceLabelPropertyValue = WString (instanceLabelPropertyValue)
            v = ECValue (wsInstanceLabelPropertyValue, False)
            instance.SetValue (instanceLabelPropertyName, v)

        displayLabel = WString ()
        assert ECObjectsStatus.eECOBJECTS_STATUS_Success == instance.GetDisplayLabel (displayLabel)

        if (instanceLabelPropertyValue):
            assert True == displayLabel.Equals (instanceLabelPropertyValue)
        else:
            assert True == displayLabel.Equals (ecClass.GetDisplayLabel())

        self.s_className = chr(ord(self.s_className) + 1)

def test_TestLabels ():
    testInstance = InstanceLabelTest ()
    testInstance.createSchema ()

    testInstance.testInstanceLabel (True, 'InstanceLabelProperty', "MyLabel")
    testInstance.testInstanceLabel (False, "DisplayLabel", None)
    testInstance.testInstanceLabel (False, "NAME", "MyName")
    testInstance.testInstanceLabel (True, "NAME", "MyName")
    testInstance.testInstanceLabel (False, "ThisClassHasNoInstanceLabelPropertySoItUsesTheClassLabel", None)