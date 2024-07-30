#--------------------------------------------------------------------------------------+
#
#     $Source: test#Published#CustomAttributeTests.cpp $
#
#  $Copyright: (c) 2019 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------#
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

##---------------------------------------------------------------------------------------
## @bsimethod                                   
##+---------------+---------------+---------------+---------------+---------------+------
def CreateCustomAttributeTestSchema ():
    ret, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    ret, customAttributeClass = schema.CreateClass (WString ("CustomAttribClass"))
    customAttributeClass.SetIsCustomAttributeClass(True)

    ret, customAttributeClass2 = schema.CreateClass (WString ("CustomAttribClass2"))
    customAttributeClass2.SetIsCustomAttributeClass(True)

    ret, customAttributeClass3 = schema.CreateClass (WString ("CustomAttribClass3"))
    customAttributeClass3.SetIsCustomAttributeClass(True)

    ret, customAttributeClass4 = schema.CreateClass (WString ("CustomAttribClass4"))
    customAttributeClass4.SetIsCustomAttributeClass(True)

    ret, baseClass = schema.CreateClass (WString ("BaseClass"))

    ret, baseStringProp = baseClass.CreatePrimitiveProperty (WString ("StringMember"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, ret)

    ret, containerClass = schema.CreateClass (WString ("TestClass"))
    containerClass.AddBaseClass(baseClass)

    ret, classWithProperties = schema.CreateClass (WString ("ClassWithProperties"))
    classWithProperties.AddBaseClass(baseClass)

    ret, stringProp = classWithProperties.CreatePrimitiveProperty (WString ("StringMember"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, ret)
    EXPECT_EQ(baseStringProp, stringProp.GetBaseProperty())

    return schema

##---------------------------------------------------------------------------------------
## @bsimethod                                   
##+---------------+---------------+---------------+---------------+---------------+------
def VerifyCustomAttributeTestSchema (customAttributeSchema):

    EXPECT_TRUE (customAttributeSchema!= None) #<< "Custom attribute schema is null."
    EXPECT_STREQ (WString ("TestSchema.05.05"), customAttributeSchema.GetFullSchemaName ()) #<< "Custom attribute schema full name mismatches."
    
    className = WString ("CustomAttribClass").GetWCharCP ()
    EXPECT_TRUE (customAttributeSchema.GetClass (className) != None) #<< "Class " << className << " not found in custom attribute schema."

    className = WString ("CustomAttribClass2").GetWCharCP ()
    EXPECT_TRUE (customAttributeSchema.GetClass (className) != None) #<< "Class " << className << " not found in custom attribute schema."

    className = WString ("CustomAttribClass3").GetWCharCP ()
    EXPECT_TRUE (customAttributeSchema.GetClass (className) != None) #<< "Class " << className << " not found in custom attribute schema."

    className = WString ("CustomAttribClass4").GetWCharCP ()
    EXPECT_TRUE (customAttributeSchema.GetClass (className) != None) #<< "Class " << className << " not found in custom attribute schema."

    baseClassName = WString ("BaseClass").GetWCharCP ()
    ecClass = customAttributeSchema.GetClass (baseClassName)
    ASSERT_TRUE (ecClass != None) #<< "Class " << baseClassName << " not found in custom attribute schema."

    propertyName = WString ("StringMember")
    EXPECT_TRUE (ecClass.GetProperty (propertyName, False) != None) #<< "Property " << propertyName << " not found in class " << baseClassName
    
    className = WString ("TestClass").GetWCharCP ()
    ecClass = customAttributeSchema.GetClass (className)
    ASSERT_TRUE (ecClass != None) #<< "Class " << className << " not found in custom attribute schema."

    baseClassList = ecClass.GetBaseClasses ()
    EXPECT_EQ (1, baseClassList.__len__ ()) #<< "Class " << className << "is expected to only have one base class"
    EXPECT_STREQ (baseClassName, baseClassList[0].GetName ().GetWCharCP ()) #<< "Unexpected base class of class " << className

    propertyName = WString ("StringMember")
    EXPECT_TRUE (ecClass.GetProperty (propertyName, True) != None) #<< "Inherited property " << propertyName << " not found in class " << className

    className = WString ("ClassWithProperties").GetWCharCP ()
    ecClass = customAttributeSchema.GetClass (className)
    ASSERT_TRUE (ecClass != None) #<< "Class " << className << " not found in custom attribute schema."

    baseClassList2 = ecClass.GetBaseClasses ()
    EXPECT_EQ (1, baseClassList2.__len__ ()) #<< "Class " << className << "is expected to only have one base class"
    EXPECT_STREQ (baseClassName, baseClassList2[0].GetName ().GetWCharCP ()) #<< "Unexpected base class of class " << className

    propertyName = WString ("StringMember")
    EXPECT_TRUE (ecClass.GetProperty (propertyName, False) != None) #<< "Overridden property " << propertyName << " not found in class " << className


##---------------------------------------------------------------------------------------
## @bsimethod                                   
##+---------------+---------------+---------------+---------------+---------------+------
def GetInstanceForClass (className, schema):
    ecClass = schema.GetClass(className.GetWCharCP ())
    enabler = ecClass.GetDefaultStandaloneEnabler()
    instance = enabler.CreateInstance()
    return instance

##---------------------------------------------------------------------------------------
## @bsiclass
##+---------------+---------------+---------------+---------------+---------------+------
class TestCustomAttributeTests :

    #ifdef NDEBUG ## avoid assert eccustomattribute.cpp line 205 stopping build
    #def ExpectFailureWhenSetNonCustomAttributeClass ():
    #schema = CreateCustomAttributeTestSchema()

    #containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
    #ASSERT_TRUE (None != containerClass)

    #instance = GetInstanceForClass (WString ("BaseClass"), schema)
    #EXPECT_EQ(ECOBJECTS_STATUS_NotCustomAttributeClass, containerClass.SetCustomAttribute(instance))
    #endif

    #@pytest.fixture(scope="module")
    def setup_method (self):
        pass

    def teardown_method (self):
        pass

    #@pytest.mark.skip(reason="NEEDS WORK: Fix me")
    def test_CanAddSingleCustomAttribute (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("ClassWithProperties").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)

        p = containerClass.GetProperty (WString ("StringMember"))

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)

        #AttributeError("'MSPyECObjects.ECSchema' object has no attribute 'SetCustomAttribute'")
        #The IECCustomAttributeContainer is not exposed as the base class for ECSchema in MS SDK, so some functions implemented
        #in C++ in it cannot be bound to Python ECSchema class, for example, the method SetCustomAttribute is not bound to Python ECSchema class.
        #So in python code, calling GetCustomAttributeContainer() on ECSchema instance still returns ECSchema instance address, not
        #the address of IECCustomAttributeContainer.Test code related to thid in this file are commented out.
        #EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.GetCustomAttributeContainer().SetCustomAttribute(instance))

        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, p.SetCustomAttribute(instance))

        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))


    def test_CanAddMultipleCustomAttributes (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)

        instance  = GetInstanceForClass (WString ("CustomAttribClass"),  schema)
        instance2 = GetInstanceForClass (WString ("CustomAttribClass2"), schema)
        instance3 = GetInstanceForClass (WString ("CustomAttribClass3"), schema)
        instance4 = GetInstanceForClass (WString ("CustomAttribClass4"), schema)

        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance2))
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance3))
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance4))


    def test_ExpectSuccessWhenAddDuplicateCustomAttribute (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))


    def test_ExpectSuccessWhenAddCustomAttributeToProperty (self):
        schema = CreateCustomAttributeTestSchema()

        classWithProperties = schema.GetClass (WString ("ClassWithProperties").GetWCharCP ())
        ASSERT_TRUE (None != classWithProperties)
        stringProperty = classWithProperties.GetProperty (WString ("StringMember"))
        ASSERT_TRUE (None != stringProperty)

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, stringProperty.SetCustomAttribute (instance))


    def test_ExpectIsDefined (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)
        customAttributeClass = schema.GetClass (WString ("CustomAttribClass").GetWCharCP ())

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_FALSE(containerClass.IsDefined(WString ("TestSchema"), WString ("CustomAttribClass")))
        EXPECT_FALSE(containerClass.IsDefined(customAttributeClass))

        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))
        EXPECT_TRUE(containerClass.IsDefined(WString ("TestSchema"), WString ("CustomAttribClass")))
        EXPECT_TRUE(containerClass.IsDefined(customAttributeClass))


    def test_ExpectIsDefinedOnBaseClass (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)
        customAttributeClass = schema.GetClass (WString ("CustomAttribClass").GetWCharCP ())
        ASSERT_TRUE (None != customAttributeClass)
        baseClass = schema.GetClass (WString ("BaseClass").GetWCharCP ())
        ASSERT_TRUE (None != baseClass)

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_FALSE (containerClass.IsDefined (WString ("TestSchema"), WString ("CustomAttribClass")))
        EXPECT_FALSE (containerClass.IsDefined (customAttributeClass))

        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, baseClass.SetCustomAttribute(instance))
        EXPECT_TRUE (baseClass.IsDefined(WString ("TestSchema"), WString ("CustomAttribClass")))
        EXPECT_TRUE (baseClass.IsDefined(customAttributeClass))
        EXPECT_TRUE (containerClass.IsDefined(WString ("TestSchema"), WString ("CustomAttribClass")))
        EXPECT_TRUE (containerClass.IsDefined(customAttributeClass))


    def test_ExpectCanGetCustomAttribute (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))

        gotInstance = containerClass.GetCustomAttribute (WString ("TestSchema"), WString ("CustomAttribClass"))
        EXPECT_TRUE(gotInstance != None)
        EXPECT_TRUE(instance == gotInstance)

        caClass = schema.GetClass(WString ("CustomAttribClass").GetWCharCP ())
        ASSERT_TRUE (None != caClass)
        gotInstance = containerClass.GetCustomAttribute(caClass)
        EXPECT_TRUE(gotInstance != None)
        EXPECT_TRUE(instance == gotInstance)


    def test_ExpectCanGetAllCustomAttributes (self):
        schema = CreateCustomAttributeTestSchema ()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)

        baseClass = schema.GetClass (WString ("BaseClass").GetWCharCP ())
        ASSERT_TRUE (None != baseClass)

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))

        instance2 = GetInstanceForClass (WString ("CustomAttribClass2"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance2))

        instance3 = GetInstanceForClass (WString ("CustomAttribClass3"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, baseClass.SetCustomAttribute(instance3))

        foundCustomAttrib = False
        foundCustomAttrib2 = False
        foundCustomAttrib3 = False
        iterableFalse = containerClass.GetCustomAttributes (False)
        for testInstance in iterableFalse:
            className = testInstance.GetClass().GetName()
            if (className.CompareTo(WString ("CustomAttribClass")) == 0):
                foundCustomAttrib = True
            elif (className.CompareTo(WString ("CustomAttribClass2")) == 0):
                foundCustomAttrib2 = True
            elif (className.CompareTo(WString ("CustomAttribClass3")) == 0):
                foundCustomAttrib3 = True

        EXPECT_TRUE(foundCustomAttrib)
        EXPECT_TRUE(foundCustomAttrib2)
        EXPECT_FALSE(foundCustomAttrib3)

        foundCustomAttrib = False
        foundCustomAttrib2 = False
        foundCustomAttrib3 = False

        iterableTrue = containerClass.GetCustomAttributes (True)
        for testInstance in iterableTrue:
            if (testInstance.GetClass().GetName().CompareTo(WString ("CustomAttribClass")) == 0):
                foundCustomAttrib = True
            elif (testInstance.GetClass().GetName().CompareTo(WString ("CustomAttribClass2")) == 0):
                foundCustomAttrib2 = True
            elif (testInstance.GetClass().GetName().CompareTo(WString ("CustomAttribClass3")) == 0):
                foundCustomAttrib3 = True

        EXPECT_TRUE(foundCustomAttrib)
        EXPECT_TRUE(foundCustomAttrib2)
        EXPECT_TRUE(foundCustomAttrib3)


    def test_ExpectCanRemoveCustomAttribute (self):
        schema = CreateCustomAttributeTestSchema()

        containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
        ASSERT_TRUE (None != containerClass)

        instance = GetInstanceForClass (WString ("CustomAttribClass"), schema)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))

        gotInstance = containerClass.GetCustomAttribute (WString ("TestSchema"), WString ("CustomAttribClass"))
        EXPECT_TRUE(gotInstance != None)
        EXPECT_TRUE(instance == gotInstance)

        EXPECT_TRUE(containerClass.RemoveCustomAttribute (WString ("TestSchema"), WString ("CustomAttribClass")))
        gotInstance2 = containerClass.GetCustomAttribute (WString ("TestSchema"), WString ("CustomAttribClass"))
        EXPECT_FALSE(gotInstance2 != None)

        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))
        caClass = schema.GetClass (WString ("CustomAttribClass").GetWCharCP ())
        ASSERT_TRUE (None != caClass)
        EXPECT_TRUE(containerClass.RemoveCustomAttribute(caClass))
        gotInstance3 = containerClass.GetCustomAttribute(caClass)
        EXPECT_FALSE(gotInstance3 != None)


#ifdef NDEBUG ## avoid assert eccustomattribute.cpp line 205 stopping build
#TEST_F(CustomAttributeTest, ExpectFailureWithUnreferencedCustomAttribute)

#    schema = CreateCustomAttributeTestSchema()

#    ret, refSchema = ECSchema.CreateSchema (WString ("RefSchema"), 5, 5)

#    ret, refClass = refSchema.CreateClass(WString ("RefClass"))
#    refClass.SetIsCustomAttributeClass(True)

#                   containerClass = schema.GetClass (WString ("TestClass").GetWCharCP ())
#    ASSERT_TRUE (None != containerClass)

#                           instance = GetInstanceForClass (WString ("RefClass"), refSchema)

#    EXPECT_EQ(eECOBJECTS_STATUS_SchemaNotFound, containerClass.SetCustomAttribute(instance))
#    schema.AddReferencedSchema(refSchema)
#    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, containerClass.SetCustomAttribute(instance))

#endif

#ifdef TEST_DEFECT_D_88458 
## This is a nonsensical scenario, so the defect is being deferred.  But the code is
## here if the defect ever gets reopened 
#TEST_F(CustomAttributeTest, ExpectSuccessWhenAddingCircularStructPropertiesToCustomAttributeClass)

#    ECSchemaCachePtr schemaOwner = ECSchemaCache.Create() 
#    ECSchemaP schema    

#    ##ECObjectsStatus structStatus
#                   struct1
#                   struct2
#                   customAttributeClass
#                   testClass

#    ret, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
#    ASSERT_TRUE(schema!=None)

#    ret, struct1 = schema.CreateClass(WString ("Struct1"))
#    ASSERT_TRUE(struct1!=None)
#    ret, struct2 = schema.CreateClass(WString ("Struct2"))
#    ASSERT_TRUE(struct2!=None)
#    struct1.SetIsStruct(True)
#    struct2.SetIsStruct(True)

#    StructP1
#    StructP2

#    struct1.CreateStructProperty(P1, WString ("P1"),struct2)
#    ASSERT_TRUE(P1!=None)
#    struct2.CreateStructProperty(P2,"P2"),struct1)
#    ASSERT_TRUE(P2!=None)

#    StructPropertyOfCustomAttribute

#    ret, customAttributeClass = schema.CreateClass(WString ("MyCustomAttribute"))
#    ASSERT_TRUE(customAttributeClass!=None)
#    customAttributeClass.SetIsCustomAttributeClass(True)


#    customAttributeClass.CreateStructProperty(PropertyOfCustomAttribute, WString ("PropertyOfCustomAttribute"),struct1)
#    ASSERT_TRUE(PropertyOfCustomAttribute!=None)
#    ##If we comment out the class property added to custom attribute. It works fine.
#                           instance = GetInstanceForClass (WString ("MyCustomAttribute"), schema)
#    ASSERT_TRUE(instance.get()!=None)

#    ret, testClass = schema.CreateClass(WString ("TestClass"))
#    ASSERT_TRUE(testClass!=None)

#                   tempClass = schema.GetClass(WString ("TestClass").GetWCharCP ())
#    ASSERT_TRUE(tempClass!=None)
#    ECObjectsStatus status =tempClass.SetCustomAttribute(instance)
#    ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success,status)

#endif

    def test_PresentationMetadataHelper(self):
        ret, schema = ECSchema.CreateSchema (WString ("TestSchema"), 1, 2)
        ret, ecclass = schema.CreateClass (WString ("TestClass"))
        ret, primProp = ecclass.CreatePrimitiveProperty (WString ("PrimitiveProperty"), ePRIMITIVETYPE_String)
        ret, arrayProp = ecclass.CreateArrayProperty (WString ("ArrayProperty"), ePRIMITIVETYPE_String)
        ret, pointProp = ecclass.CreatePrimitiveProperty (WString ("PointProperty"), PrimitiveType.ePRIMITIVETYPE_Point3D)

        readContext = ECSchemaReadContext.CreateContext()

        meta = PresentationMetadataHelper (readContext)

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetHideNullProperties (ecclass))
        EXPECT_TRUE (ecclass.IsDefined (WString ("EditorCustomAttributes"), WString ("DontShowNullProperties")))

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetIgnoreZ (pointProp))
        EXPECT_TRUE (pointProp.IsDefined (WString ("EditorCustomAttributes"), WString ("IgnoreZ")))

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetMembersIndependent (arrayProp))
        EXPECT_TRUE (arrayProp.IsDefined (WString ("EditorCustomAttributes"), WString ("MembersIndependent")))

        v = ECValue ()
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetPriority (primProp, 1234))
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, primProp.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("PropertyPriority")).GetValue (v, WString ("Priority").GetWCharCP ()))
        EXPECT_EQ (1234, v.GetInteger())

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetAlwaysExpand (arrayProp, True))
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, arrayProp.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("AlwaysExpand")).GetValue (v, WString ("ArrayMembers").GetWCharCP ()))
        EXPECT_TRUE (v.GetBoolean())

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetExtendedType (primProp, 1))
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, primProp.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("ExtendType")).GetValue (v, WString ("Standard").GetWCharCP ()))
        EXPECT_EQ (1, v.GetInteger())

        str = WString ("CustomType")
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetExtendedType (primProp, str.GetWCharCP ()))
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, primProp.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("ExtendType")).GetValue (v, WString ("Name").GetWCharCP ()))
        EXPECT_TRUE (str.Equals (v.GetString()))

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetMemberExtendedType (arrayProp, 1))
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, arrayProp.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("MemberExtendedType")).GetValue (v, WString ("Standard").GetWCharCP ()))
        EXPECT_EQ (1, v.GetInteger())

        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.SetMemberExtendedType (arrayProp, str.GetWCharCP ()))
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, arrayProp.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("MemberExtendedType")).GetValue (v, WString ("Name").GetWCharCP ()))
        EXPECT_TRUE (str.Equals (v.GetString()))

        ret, propHide = ecclass.CreatePrimitiveProperty(WString ("HideNoArgument"), ePRIMITIVETYPE_String)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.HideProperty(propHide))
        EXPECT_TRUE(None != propHide.GetCustomAttribute (WString ("EditorCustomAttributes"), WString ("HideProperty")))

        ret, prop3D = ecclass.CreatePrimitiveProperty(WString ("Hide3D"), ePRIMITIVETYPE_String)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.HideProperty(prop3D,False,True))
        EXPECT_TRUE(None != prop3D.GetCustomAttribute(WString ("EditorCustomAttributes"), WString ("HideProperty")))

        ret, prop2D = ecclass.CreatePrimitiveProperty(WString ("Hide2D"), ePRIMITIVETYPE_String)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.HideProperty(prop2D, True, False))
        EXPECT_TRUE(None != prop2D.GetCustomAttribute(WString ("EditorCustomAttributes"), WString ("HideProperty")))

        ret, propAny = ecclass.CreatePrimitiveProperty(WString ("AnyHide"), ePRIMITIVETYPE_String)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, meta.HideProperty(propAny, True, True))
        EXPECT_TRUE(None != propAny.GetCustomAttribute(WString ("EditorCustomAttributes"), WString ("HideProperty")))

        ret, propNo = ecclass.CreatePrimitiveProperty(WString ("NoHide"), ePRIMITIVETYPE_String)
        EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Error, meta.HideProperty(propNo, False, False))
        EXPECT_TRUE(None == propNo.GetCustomAttribute(WString ("EditorCustomAttributes"), WString ("HideProperty")))


##---------------------------------------------------------------------------------------
## @bsimethod                                   
##+---------------+---------------+---------------+---------------+---------------+------
    def test_SerializeSchemaToXmlUtfString (self):
        testClassName = "TestClass"

        caClassName = WString ("CustomAttribClass")
        caStringPropName = WString ("StringProperty")
        expectedSchema = CreateCustomAttributeTestSchema ()
        caClass = expectedSchema.GetClass (WString (caClassName.GetWCharCP ()).GetWCharCP ())
        EXPECT_TRUE (caClass != None) #<< "Test custom attribute class " << caClassName << " not found"
        ret, stringProp = caClass.CreatePrimitiveProperty (caStringPropName, ePRIMITIVETYPE_String)

        expectedCAString = Utf8String ()
        EXPECT_EQ (BentleyStatus.eSUCCESS, BeStringUtilities.WCharToUtf8 (expectedCAString, WString ("����ᳵ").GetWCharCP ()))
        caInstance = GetInstanceForClass (caClassName, expectedSchema)
        expectedUtf8Value = ECValue (expectedCAString)
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, caInstance.SetValue (caStringPropName.GetWCharCP (), expectedUtf8Value)) #<< "Assigning property value to custom attribute instance failed."

        testClass = expectedSchema.GetClass (WString (testClassName).GetWCharCP ())
        EXPECT_TRUE (testClass != None) #<< "Test class " << testClass << " not found"
        EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, testClass.SetCustomAttribute (caInstance)) #<< "Assigning the custom attribute instance to class " << testClassName << " failed."

        ##serializing
        schemaUtfXml = Utf8String ()
        serializeStat = expectedSchema.WriteToXmlString (schemaUtfXml)
        EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, serializeStat) #<< "Serializing the schema to a UTF-8 XML string failed."

        ##deserializing
        schemaContext = ECSchemaReadContext.CreateContext()
        deserializeStat, actualSchema = ECSchema.ReadFromXmlString (schemaUtfXml.__repr__ (), schemaContext)
        EXPECT_EQ (eSCHEMA_READ_STATUS_Success, deserializeStat) #<< "Deserializing the schema from a UTF-8 XML string failed."

        ##base check of actual vs expected schema
        VerifyCustomAttributeTestSchema (actualSchema)
        ##now check CA added in this test
        actualCAClass = actualSchema.GetClass (caClassName.GetWCharCP ())
        EXPECT_TRUE (actualCAClass.GetProperty (caStringPropName) != None) #<< "Property " << caStringPropName << " not found in custom attribute class."
        ##now check CA instance added in this test
        actualTestClass = actualSchema.GetClass (WString (testClassName).GetWCharCP ())

        actualCAInstance = actualTestClass.GetCustomAttribute (actualCAClass)
        ASSERT_TRUE (actualCAInstance!= None) #<< "Test class " << testClassName << " doesn't have the expected custom attribute instance."

        actualUtf8Value = ECValue ()
        ASSERT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, actualCAInstance.GetValue (actualUtf8Value, caStringPropName.GetWCharCP ())) #<< "Property " << caStringPropName << "not found in custom attribute instance on test class."
        EXPECT_TRUE (expectedUtf8Value == actualUtf8Value) #<< "Unexpected string property value of custom attribute instance"
        EXPECT_STREQ (expectedCAString.__repr__ (), actualUtf8Value.GetUtf8CP ()) #<< "Unexpected string value of custom attribute property value"

    #@pytest.mark.skip(reason="NEEDS WORK: Fix me")
    def test_TestCustomAttributesWithSameNameInDifferentSchemas (self):
        ret,schema1 = ECSchema.CreateSchema (WString ("CASchema1"), 5, 5)
        ret, customAttributeClass1 = schema1.CreateClass(WString ("CustomAttribClass"))
        customAttributeClass1.SetIsCustomAttributeClass (True)

        ret, schema2 = ECSchema.CreateSchema (WString ("CASchema2"), 5, 5)
        ret, customAttributeClass2 = schema2.CreateClass (WString ("CustomAttribClass"))
        customAttributeClass2.SetIsCustomAttributeClass (True)
    
        caInstance1 = GetInstanceForClass (WString ("CustomAttribClass"), schema1)
        caInstance2 = GetInstanceForClass (WString ("CustomAttribClass"), schema2)
        
        ret, testSchema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
        testSchema.AddReferencedSchema(schema1)
        testSchema.AddReferencedSchema(schema2)
        schemaCustomAttributeContainer = testSchema.GetCustomAttributeContainer()
        
        #The IECCustomAttributeContainer is not exposed as the base class for ECSchema in MS SDK, so some functions implemented
        #in C++ in it cannot be bound to Python ECSchema class, for example, the method SetCustomAttribute is not bound to Python ECSchema class.
        #So in python code, calling GetCustomAttributeContainer() on ECSchema instance still returns ECSchema instance address, not
        #the address of IECCustomAttributeContainer.Test code related to thid in this file are commented out.
        #EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, schemaCustomAttributeContainer.SetCustomAttribute(caInstance1)) #<< "Assigning the custom attribute instance to class CASchema1.CustomAttribClass failed."
        #EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, schemaCustomAttributeContainer.SetCustomAttribute(caInstance2)) #<< "Assigning the custom attribute instance to class CASchema2.CustomAttribClass failed."

        #EXPECT_TRUE(schemaCustomAttributeContainer.IsDefined(WString ("CASchema1"), WString ("CustomAttribClass"))) #<< "CustomAttribute CATestSchema1.TestClass couldn't be found on TestSchema."
        #EXPECT_TRUE(schemaCustomAttributeContainer.IsDefined(WString ("CASchema2"), WString ("CustomAttribClass"))) # << "CustomAttribute CATestSchema2.TestClass couldn't be found on TestSchema."
        #EXPECT_TRUE(schemaCustomAttributeContainer.IsDefined(WString ("CustomAttribClass"))) # << "CustomAttribute TestClass couldn't be found on TestSchema." ## LEGENCY TEST
        
        #ASSERT_TRUE (schemaCustomAttributeContainer.GetCustomAttribute (WString ("CASchema1"), WString ("CustomAttribClass")) != None)
        #ASSERT_TRUE (schemaCustomAttributeContainer.GetCustomAttribute (WString ("CASchema2"), WString ("CustomAttribClass")) != None)
                
        #EXPECT_TRUE(schemaCustomAttributeContainer.RemoveCustomAttribute(WString ("CASchema2"), WString ("CustomAttribClass")))
        #EXPECT_FALSE(schemaCustomAttributeContainer.IsDefined(WString ("CASchema2"), WString ("CustomAttribClass"))) # << "CustomAttribute CATestSchema2.TestClass was still found although it should have been removed."
        #EXPECT_TRUE(schemaCustomAttributeContainer.IsDefined(WString ("CustomAttribClass")))
        
        #EXPECT_TRUE(schemaCustomAttributeContainer.RemoveCustomAttribute(WString ("CASchema1"), WString ("CustomAttribClass")))
        #EXPECT_FALSE(schemaCustomAttributeContainer.IsDefined(WString ("CASchema1"), WString ("CustomAttribClass"))) # << "CustomAttribute CATestSchema1.TestClass was still found although it should have been removed."
        #EXPECT_FALSE(schemaCustomAttributeContainer.IsDefined(WString ("CustomAttribClass")))

