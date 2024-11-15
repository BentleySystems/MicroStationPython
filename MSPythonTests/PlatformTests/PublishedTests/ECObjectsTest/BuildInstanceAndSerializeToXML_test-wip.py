#--------------------------------------------------------------------------------------+
#
#     $Source: test/Published/BuildInstanceAndSerializeToXML.cpp $
#
#  $Copyright: (c) 2014 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------#/
import os
import pytest
import pythoncom  #for pythoncom.CoInitialize(0)

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *
import time

#---------------------------------------------------------------------------------##//##
# Specify the ECSchema that contains all the class/struct definitions
# @bsimethod                                                    Ping.Chen   02/2024
#---------------+---------------+---------------+---------------+---------------+------#/
def CreateTestSchema ():
    #time.sleep(45)
    #schemaXML = WString ()
    #test = WString ("Test")
    schemaXML = WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
                    "<ECSchema schemaName=\"TestSchema\" nameSpacePrefix=\"test\" version=\"01.00\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\">"
                    "    <ECClass typeName=\"SampleDataClass\" isStruct=\"True\" isDomainClass=\"True\">"
                    "        <ECProperty propertyName=\"Name\"           typeName=\"string\" />"
                    "        <ECProperty propertyName=\"ID\"             typeName=\"int\" />"
                    "        <ECProperty propertyName=\"StartPoint\"     typeName=\"point3d\" />"
                    "        <ECProperty propertyName=\"EndPoint\"       typeName=\"point3d\" />"
                    "        <ECProperty propertyName=\"XYSize\"         typeName=\"point2d\" />"
                    "        <ECProperty propertyName=\"Length\"         typeName=\"double\"  />"
                    "        <ECArrayProperty propertyName=\"Readings\"  typeName=\"long\" />"
                    "        <ECProperty propertyName=\"Field_Tested\"   typeName=\"boolean\"  />"
                    "    </ECClass>"
                    "</ECSchema>")

    schemaContext = ECSchemaReadContext.CreateContext()
    status, schema = ECSchema.ReadFromXmlString (schemaXML.GetWCharCP (), schemaContext)
    EXPECT_EQ (BentleyStatus.eSUCCESS, status)
    
    return schema

#=========================================================
# Native structure
#=========================================================
class SampleData:
    def __init__(self, id, numReadings):
        self.m_name = "Sample_{0}".format (id)
        self.m_id = id
        self.m_numReadings = numReadings

        if (numReadings > 0):
            self.m_readings = [0] * numReadings
            for i in range (0, numReadings):
                self.m_readings[i] = i*100
        else:
            self.m_readings = None

        self.m_length = id * 3.75

        self.m_startPoint = DPoint3d ()

        self.m_startPoint.x = id * 1.0
        self.m_startPoint.y = id * 1.0
        self.m_startPoint.z = id * 1.0

        self.m_endPoint = DPoint3d ()
        self.m_endPoint.x = id * 1.0 + 100.0
        self.m_endPoint.y = id * 1.0 + 100.0
        self.m_endPoint.z = id * 1.0 + 100.0

        self.m_xySize = DPoint2d ()
        self.m_xySize.x = id * 0.5
        self.m_xySize.y = id * 1.0 + 0.5

        self.m_tested = (0 == id%2)

#=========================================================
# SampleDataInstanceManager - holds schema and enabler that will be
# needed to create standalone instances. 
#=========================================================
class  SampleDataInstanceManager:
    def __init__ (self):    
        # create the test schema (the created schema is added to the schema cache self.m_schemaOwner
        self.m_schema = CreateTestSchema ()

        # get the class that represents the native SampleData stuct and get the enabler that will be used to create instances
        ecClass = self.m_schema.GetClass ("SampleDataClass")
        if (ecClass != None):
            self.m_enabler = ecClass.GetDefaultStandaloneEnabler ()
        else:
            self.m_enabler = None
    

    # Method to populate a standalone instance from a struct
    def CreateInstance (self, data):
        if (self.m_enabler == None):
            return None

        # create an empty instance
        instance = self.m_enabler.CreateInstance()

        # populate the instance
        instance.SetValue("Name",         ECValue (WString (data.m_name).GetWCharCP ()))
        instance.SetValue("ID",           ECValue (data.m_id))
        instance.SetValue("StartPoint",   ECValue (data.m_startPoint))
        instance.SetValue("EndPoint",     ECValue (data.m_endPoint))
        instance.SetValue("XYSize",       ECValue (data.m_xySize))
        instance.SetValue("Length",       ECValue (data.m_length))
        instance.SetValue("Field_Tested", ECValue (data.m_tested, False))

        if (data.m_numReadings > 0):
            # add room for the array members and then set the values for each
            instance.AddArrayElements ("Readings", data.m_numReadings)
            for i in range (0, data.m_numReadings):
                #The type of Readings is long, we need to pass dummy bool value (False) to make pybind calling correct ECValue init function
                instance.SetValue("Readings", ECValue (data.m_readings[i], False), i)

        return instance


class TestBasicTest :
    #----------------------------------------------------------------------------------#//##
    # @bsimethod                                                    Ping.Chen   02/2024
    #---------------+---------------+---------------+---------------+---------------+------#/
    def test_BuildInstanceAndSerializeToXML (self):
        ret = pythoncom.CoInitialize ()
        EXPECT_EQ (None, ret)
        if None != ret:
            return

        instanceManager = SampleDataInstanceManager ()
        ecInstanceXml = WString ()

        for i in range (0, 5):
            sampleData = SampleData (i, (int)(i%2)*3)
            testInstance = instanceManager.CreateInstance (sampleData)
            ASSERT_TRUE (None != testInstance)

            status2 = testInstance.WriteToXmlString (ecInstanceXml, True, False)
            EXPECT_EQ (eINSTANCE_WRITE_STATUS_Success, status2)

        pythoncom.CoUninitialize()