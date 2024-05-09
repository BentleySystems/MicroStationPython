#--------------------------------------------------------------------------------------+
#
#     $Source: test/Published/SupplementalSchemaTests.cpp $
#
#  $Copyright: (c) 2015 Bentley Systems, Incorporated. All rights reserved. $
#
#--------------------------------------------------------------------------------------*/
import os
import pytest
import pythoncom  #for pythoncom.CoInitialize(0)

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

#The IECCustomAttributeContainer is not exposed as the base class for ECSchema in MS SDK, so some functions implemented
#in C++ in it cannot be bound to Python side, for example, the method SetCustomAttribute is not bound to Python ECSchema class.
#So in python code, calling GetCustomAttributeContainer () on ECSchema instance still returns ECSchema instance adress, not
#the adress of IECCustomAttributeContainer. Tests in this file are based on it, so this file is ignored in pytest.

class TestSchemaHolderTestFixture :
    def CreateSupplementalSchema (self, primarySchemaName, purpose, precedence, primaryMajorVersion,primaryMinorVersion,
                                    supplementalMajorVersion,supplementalMinorVersion):
        supplementalName = WString (primarySchemaName + "_Supplemental_" + purpose)

        retVal, supplementalSchema = ECSchema.CreateSchema (supplementalName, supplementalMajorVersion, supplementalMinorVersion)
        metaData = SupplementalSchemaMetaData (WString (primarySchemaName), primaryMajorVersion, primaryMinorVersion, precedence, WString (purpose), False)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        return supplementalSchema

    #@pytest.fixture(scope="module")
    def setup_method (self):
        if None != pythoncom.CoInitialize():
            return

        schemaContext = ECSchemaReadContext.CreateContext()
        key = SchemaKey ("Bentley_Standard_CustomAttributes", 1, 6)
        self.m_bscaSchema = ECSchema.LocateSchema(key, schemaContext)

    def teardown_method (self):
        #yield
        pythoncom.CoUninitialize()

class TestSupplementalSchemaMetaDataTests (TestSchemaHolderTestFixture):
    #---------------------------------------------------------------------------------**/#*
    # @bsimethod                                    Carole.MacDonald                04/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_CanRetrieveFromSchema (self):
        supplemental = super ().CreateSupplementalSchema("TestSchema", "OverrideWidgets", 200, 1, 0, 4, 2)

        EXPECT_TRUE(supplemental != None)

        tempSchema = supplemental
        tempSchema.GetFullSchemaName ()
        iter = tempSchema.GetCustomAttributeContainer().GetCustomAttributes(True)

        ret, metaData = SupplementalSchemaMetaData.TryGetFromSchema (supplemental)
        EXPECT_TRUE(ret)
        EXPECT_TRUE(None != metaData)

        EXPECT_STREQ("TestSchema", metaData.GetPrimarySchemaName().GetWCharCP ())
        EXPECT_EQ(1, metaData.GetPrimarySchemaMajorVersion())
        EXPECT_EQ(0, metaData.GetPrimarySchemaMinorVersion())
        EXPECT_EQ(200, metaData.GetSupplementalSchemaPrecedence())
        EXPECT_STREQ("OverrideWidgets", metaData.GetSupplementalSchemaPurpose().GetWCharCP ())
        EXPECT_FALSE(metaData.IsUserSpecific())

class TestSupplementalSchemaInfoTests (TestSchemaHolderTestFixture):
    #---------------------------------------------------------------------------------**/#*
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*
    def test_CanSetAndRetrieveInfo (self):
        schemaNamesAndPurposes1 = {}
        schemaNamesAndPurposes1["Schema1.01.00"] = "Units"
        schemaNamesAndPurposes1["Schema2.02.00"] = "Units"
        schemaNamesAndPurposes1["Schema2.01.01"] = "Alpha"
        schemaNamesAndPurposes1["Schema3.01.00"] = "Beta"

        primarySchemaFullName = WString ("PrimarySchema.08.02")

        ret, primarySchema = ECSchema.CreateSchema (WString ("PrimarySchema"), 8, 2)

        supplementalSchema1 = super ().CreateSupplementalSchema("PrimarySchema", "Units", 200, 8, 2, 1, 0)
        supplementalSchema2 = super ().CreateSupplementalSchema("PrimarySchema", "Units", 201, 8, 2, 2, 0)
        supplementalSchema3 = super ().CreateSupplementalSchema("PrimarySchema", "Alpha", 202, 8, 2, 1, 1)
        supplementalSchema4 = super ().CreateSupplementalSchema("PrimarySchema", "Beta", 203, 8, 2, 1, 0)

        supplementalSchemas = ECSchemaPArray ()
        supplementalSchemas.append(supplementalSchema1)
        supplementalSchemas.append(supplementalSchema2)
        supplementalSchemas.append(supplementalSchema3)
        supplementalSchemas.append(supplementalSchema4)

        builder = SupplementedSchemaBuilder ()
        builder.UpdateSchema (primarySchema, supplementalSchemas)

        ret, schema2 = ECSchema.CreateSchema (WString ("PrimarySchema"), 8, 2)
        builder2 = SupplementedSchemaBuilder ()
        builder2.UpdateSchema(schema2, supplementalSchemas)

        schemaInfo1 = primarySchema.GetSupplementalInfo()

        EXPECT_TRUE(schemaInfo1.HasSameSupplementalSchemasForPurpose (schema2, WString ("Units")))

class TestSupplementedSchemaBuilderTests (TestSchemaHolderTestFixture):

    def SetCustomAttribute (self, container, enabler, propertyName1, propertyValue1, propertyName2, propertyValue2):
        customAttribute = enabler.CreateInstance()
        customAttribute.SetValue(propertyName1.GetWCharCP (), ECValue(propertyValue1))
        customAttribute.SetValue(propertyName2.GetWCharCP (), ECValue(propertyValue2))
        container.SetCustomAttribute(customAttribute)


    def CreatePrimarySchema (self):
        retVal, primarySchema = ECSchema.CreateSchema (WString ("TestSchema"), 1, 0)
        ret, fileClass = primarySchema.CreateClass (WString ("File"))
        primarySchema.AddReferencedSchema(self.m_customAttributeSchema)
        primarySchema.AddReferencedSchema(self.m_bscaSchema)
        ret, hiddenProperty = fileClass.CreatePrimitiveProperty (WString ("Hidden"), PrimitiveType.ePRIMITIVETYPE_Boolean)
        ret, creationDateProperty = fileClass.CreatePrimitiveProperty (WString ("CreationDate"), PrimitiveType.ePRIMITIVETYPE_DateTime)
        ret, fileSizeProperty = fileClass.CreatePrimitiveProperty (WString ("FileSize"), PrimitiveType.ePRIMITIVETYPE_Long)

        self.SetCustomAttribute(fileClass, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on File Class"), WString ("Data2"), WString ("Data2 on File Class"))

        self.SetCustomAttribute(hiddenProperty, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on Hidden Property on File Class"), WString ("Data2"), WString ("Data2 on Hidden Property on File Class"))

        self.SetCustomAttribute(hiddenProperty, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Hidden Property on File Class"), WString ("NotImportant"), WString ("Not important on Hidden Property on File Class"))

        ret, folderClass = primarySchema.CreateClass (WString ("Folder"))
        ret, hiddenProperty2 = folderClass.CreatePrimitiveProperty (WString ("Hidden"), PrimitiveType.ePRIMITIVETYPE_Boolean)
        ret, creationDateProperty2 = folderClass.CreatePrimitiveProperty (WString ("CreationDate"), PrimitiveType.ePRIMITIVETYPE_DateTime)
        ret, readOnlyProperty = folderClass.CreatePrimitiveProperty (WString ("ReadOnly"), PrimitiveType.ePRIMITIVETYPE_Boolean)
        self.SetCustomAttribute(folderClass, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on Folder Class"), WString ("Data2"), WString ("Data2 on Folder Class"))
        self.SetCustomAttribute(hiddenProperty2, self.m_uselessInfoCAEnabler,  WString ("NothingImportant"), WString ("Nothing important on Hidden Property on Folder Class"), WString ("NotImportant"), WString ("Not important on Hidden Property on Folder Class"))

        ret, imageClass = primarySchema.CreateClass (WString ("Image"))
        imageClass.AddBaseClass(fileClass)

        ret, bitDepthProperty = imageClass.CreatePrimitiveProperty (WString ("BitDepth"), PrimitiveType.ePRIMITIVETYPE_Integer)
        ret, widthProperty = imageClass.CreatePrimitiveProperty (WString ("Width"), PrimitiveType.ePRIMITIVETYPE_Integer)
        ret, heightProperty = imageClass.CreatePrimitiveProperty (WString ("Height"), PrimitiveType.ePRIMITIVETYPE_Integer)
        self.SetCustomAttribute(imageClass, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on Image Class"), WString ("Data2"), WString ("Data2 on Image Class"))
        self.SetCustomAttribute(widthProperty, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Width Property on Image Class"), WString ("NotImportant"), WString ("Not important on Width Property on Image Class"))

        return primarySchema

    def CreateSupplementalSchema1 (self):
        retVal, supplementalSchema = ECSchema.CreateSchema (WString ("TestSchema_Supplemental_OverrideFiles"), 1, 0)
        metaData = SupplementalSchemaMetaData (WString ("TestSchema"), 1, 0, 200, WString ("OverrideFiles"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        retVal, fileClass = supplementalSchema.CreateClass (WString ("File"))
        ret, hiddenProperty = fileClass.CreatePrimitiveProperty (WString ("Hidden"), PrimitiveType.ePRIMITIVETYPE_Boolean)

        self.SetCustomAttribute(fileClass, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on File Class from SupplementalSchema1"), WString ("Data2"), WString ("Data2 on File Class from SupplementalSchema1"))
        self.SetCustomAttribute(hiddenProperty, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Hidden Property on File Class from SupplementalSchema1"), WString ("NotImportant"), WString ("Not important on Hidden Property on File Class from SupplementalSchema1"))

        return supplementalSchema

    def CreateSupplementalSchema2 (self):
        retVal, supplementalSchema = ECSchema.CreateSchema(WString ("TestSchema_Supplemental_UnderrideFiles_ExtraText"), 1, 0)

        metaData = SupplementalSchemaMetaData (WString ("TestSchema"), 1, 0, 199, WString ("UnderrideFiles"), False)
        supplementalSchema.AddReferencedSchema (self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema (self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute (metaData.CreateCustomAttribute ())

        ret, folderClass = supplementalSchema.CreateClass (WString ("Folder"))
        ret, creationDateProperty = folderClass.CreatePrimitiveProperty (WString ("CreationDate"), PrimitiveType.ePRIMITIVETYPE_DateTime)

        self.SetCustomAttribute(folderClass, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Folder Class from SupplementalSchema2"), WString ("NotImportant"), WString ("Not important on Folder Class from SupplementalSchema2"))
        self.SetCustomAttribute(creationDateProperty, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on CreationDate Property on Folder Class from SupplementalSchema2"), WString ("Data2"), WString ("Data2 on CreationDate Property on Folder Class from SupplementalSchema2"))

        return supplementalSchema

    def CreateSupplementalSchema3 (self):
        retVal, supplementalSchema = ECSchema.CreateSchema (WString ("TestSchema_Supplemental_FileAndImageInfo"), 3, 33)
        metaData = SupplementalSchemaMetaData (WString ("TestSchema"), 1, 0, 200, WString ("FileAndImageInfo"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        ret, fileClass = supplementalSchema.CreateClass (WString ("File"))
        ret, hiddenProperty = fileClass.CreatePrimitiveProperty (WString ("Hidden"), PrimitiveType.ePRIMITIVETYPE_Boolean)
        ret, creationDateProperty = fileClass.CreatePrimitiveProperty (WString ("CreationDate"), PrimitiveType.ePRIMITIVETYPE_DateTime)
        ret, fileSizeProperty = fileClass.CreatePrimitiveProperty (WString ("FileSize"), PrimitiveType.ePRIMITIVETYPE_Long)

        self.SetCustomAttribute(fileClass, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on File Class from Supplemental3"), WString ("NotImportant"), WString ("Not important on File Class from Supplemental3"))

        self.SetCustomAttribute(hiddenProperty, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on Hidden Property on File Class from Supplemental3"), WString ("Data2"), WString ("Data2 on Hidden Property on File Class from Supplemental3"))

        self.SetCustomAttribute(creationDateProperty, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on CreationDate Property on File Class from Supplemental3"), WString ("NotImportant"), WString ("Not important on CreationDate Property on File Class from Supplemental3"))

        self.SetCustomAttribute(fileSizeProperty, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on FileSize Property on File Class from Supplemental3"), WString ("Data2"), WString ("Data2 on FileSize Property on File Class from Supplemental3"))

        ret, imageClass = supplementalSchema.CreateClass (WString ("Image"))
        ret, heightProperty =  imageClass.CreatePrimitiveProperty (WString ("Height"), PrimitiveType.ePRIMITIVETYPE_Integer)
        ret, hiddenProperty2 = imageClass.CreatePrimitiveProperty (WString ("Hidden"), PrimitiveType.ePRIMITIVETYPE_Boolean)
        self.SetCustomAttribute(imageClass, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Image Class from Supplemental3"), WString ("NotImportant"), WString ("Not important on Image Class from Supplemental3"))
        self.SetCustomAttribute(heightProperty, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Height Property on Image Class from Supplemental3"), WString ("NotImportant"), WString ("Not important on Height Property on Image Class from Supplemental3"))
        self.SetCustomAttribute(hiddenProperty2, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Hidden Property on Image Class from Supplemental3"), WString ("NotImportant"), WString ("Not important on Hidden Property on Image Class from Supplemental3"))

        return supplementalSchema


    def CreateSupplementalSchema4 (self):
        retVal, supplementalSchema = ECSchema.CreateSchema (WString ("TestSchema_Supplemental_Conflict"), 6, 66)
        metaData = SupplementalSchemaMetaData (WString ("TestSchema"), 1, 0, 199, WString ("Conflict"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        ret, folderClass = supplementalSchema.CreateClass (WString ("Folder"))
        ret, creationDateProperty = folderClass.CreatePrimitiveProperty (WString ("CreationDate"), PrimitiveType.ePRIMITIVETYPE_DateTime)

        self.SetCustomAttribute(folderClass, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("Nothing important on Folder Class from SupplementalSchema4"), WString ("NotImportant"), WString ("Not important on Folder Class from SupplementalSchema4"))
        self.SetCustomAttribute(creationDateProperty, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("Data1 on CreationDate Property on Folder Class from SupplementalSchema4"), WString ("Data2"), WString ("Data2 on CreationDate Property on Folder Class from SupplementalSchema4"))

        return supplementalSchema

    def BuildSupplementedSchemaForCustomAttributeTests (self):
        ret, customAttributeSchema = ECSchema.CreateSchema(WString ("CustomAttributes"), 1, 0)

        ret, customAttributeA = customAttributeSchema.CreateClass(WString ("CustomAttributeA"))
        customAttributeA.SetIsCustomAttributeClass(True)

        ret, customAttributeB = customAttributeSchema.CreateClass(WString ("CustomAttributeB"))
        customAttributeB.SetIsCustomAttributeClass(True)

        ret, customAttributeC = customAttributeSchema.CreateClass(WString ("CustomAttributeC"))
        customAttributeC.SetIsCustomAttributeClass(True)

        ret, customAttributeD = customAttributeSchema.CreateClass(WString ("CustomAttributeD"))
        customAttributeD.SetIsCustomAttributeClass(True)

        ret, schema = ECSchema.CreateSchema(WString ("testPrimary"), 1, 0)
        schema.AddReferencedSchema(customAttributeSchema, WString ("cas"))

        customAttributeEnablerA = customAttributeA.GetDefaultStandaloneEnabler()
        customAttributeEnablerB = customAttributeB.GetDefaultStandaloneEnabler()
        customAttributeEnablerC = customAttributeC.GetDefaultStandaloneEnabler()
        customAttributeEnablerD = customAttributeD.GetDefaultStandaloneEnabler()

        ret, primaryClassA = schema.CreateClass(WString ("A"))
        primaryClassA.SetCustomAttribute(customAttributeEnablerA.CreateInstance())

        ret, primaryClassB = schema.CreateClass(WString ("B"))
        primaryClassB.SetCustomAttribute(customAttributeEnablerB.CreateInstance())
        primaryClassB.AddBaseClass(primaryClassA)

        ret, supplementalSchema = ECSchema.CreateSchema (WString ("testSupplementa"), 1, 0)
        metaData = SupplementalSchemaMetaData (WString ("testPrimary"), 1, 0, 354, WString ("None"), False)
        supplementalSchema.AddReferencedSchema(customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())
        ret, supplementalClassA = supplementalSchema.CreateClass (WString ("A"))
        supplementalClassA.SetCustomAttribute(customAttributeEnablerC.CreateInstance())
        ret, supplementalClassB = supplementalSchema.CreateClass (WString ("B"))
        supplementalClassB.SetCustomAttribute(customAttributeEnablerD.CreateInstance())

        supplementalSchemas = ECSchemaPArray ()
        supplementalSchemas.append(supplementalSchema)
        builder = SupplementedSchemaBuilder ()
        builder.UpdateSchema (schema, supplementalSchemas)
        classA = schema.GetClass(WString ("A").GetWCharCP ())
        classB = schema.GetClass(WString ("B").GetWCharCP ())

        return classA, classB, schema

    def CreatePrimarySchemaForRelationshipTests (self):
        ret, schema = ECSchema.CreateSchema(WString ("RelationshipTestSchema"), 1, 2)
        ret, targetClass = schema.CreateClass(WString ("TargetClass"))
        ret, sourceClass = schema.CreateClass(WString ("SourceClass"))

        ret, relClass = schema.CreateRelationshipClass(WString ("RelationshipWithCustomAttributes"))
        relClass.GetSource().AddClass(sourceClass)
        relClass.GetTarget().AddClass(targetClass)

        ret, relClass2 = schema.CreateRelationshipClass(WString ("RelClass2"))
        relClass2.GetSource().AddClass(sourceClass)
        relClass2.GetTarget().AddClass(targetClass)

        return schema

    def CreateSupplementalSchema0ForRelationshipTests (self):
        ret, supplementalSchema = ECSchema.CreateSchema(WString ("RTS_Supplementa"), 3, 4)
        metaData = SupplementalSchemaMetaData (WString ("RelationshipTestSchema"), 1, 2, 200, WString ("Test"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        ret, targetClass_Sup = supplementalSchema.CreateClass(WString ("TargetClass"))
        ret, sourceClass_Sup = supplementalSchema.CreateClass(WString ("SourceClass"))

        ret, relClass_Sup = supplementalSchema.CreateRelationshipClass(WString ("RelationshipWithCustomAttributes"))
        relClass_Sup.GetSource().AddClass(sourceClass_Sup)
        relClass_Sup.GetTarget().AddClass(targetClass_Sup)

        relClass_Sup.GetSource().SetCustomAttribute(self.m_systemInfoCAEnabler.CreateInstance())
        relClass_Sup.GetTarget().SetCustomAttribute(self.m_systemInfoCAEnabler.CreateInstance())

        return supplementalSchema

    def CreateSupplementalSchema1ForRelationshipTests (self):
        ret, supplementalSchema = ECSchema.CreateSchema (WString ("RTS_Supplemental2"), 5, 6)
        metaData = SupplementalSchemaMetaData (WString ("RelationshipTestSchema"), 1, 2, 200, WString ("Test"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        ret, targetClass_Sup = supplementalSchema.CreateClass(WString ("TargetClass"))
        ret, sourceClass_Sup = supplementalSchema.CreateClass(WString ("SourceClass"))

        ret, relClass_Sup = supplementalSchema.CreateRelationshipClass(WString ("RelationshipWithCustomAttributes"))
        relClass_Sup.GetSource().AddClass(sourceClass_Sup)
        relClass_Sup.GetTarget().AddClass(targetClass_Sup)

        relClass_Sup.GetSource().SetCustomAttribute(self.m_uselessInfoCAEnabler.CreateInstance())
        relClass_Sup.GetTarget().SetCustomAttribute(self.m_uselessInfoCAEnabler.CreateInstance())

        ret, relClass2_Sup = supplementalSchema.CreateRelationshipClass (WString ("RelClass2"))
        relClass2_Sup.GetSource().AddClass(sourceClass_Sup)
        relClass2_Sup.GetTarget().AddClass(targetClass_Sup)

        relClass2_Sup.GetSource().SetCustomAttribute(self.m_otherInfoCAEnabler.CreateInstance())
        relClass2_Sup.GetTarget().SetCustomAttribute(self.m_otherInfoCAEnabler.CreateInstance())

        return supplementalSchema

    def CreatePrimarySchemaForInheritTests (self):
        ret, primarySchema = ECSchema.CreateSchema(WString ("InheritTestSchema"), 2, 34)
        primarySchema.AddReferencedSchema(self.m_customAttributeSchema)
        # BaseClass1
        # BC1Prop1
        # SystemInfo
        # BC1Prop2
        # BC1Prop3

        ret, baseClass1 = primarySchema.CreateClass(WString ("BaseClass1"))
        ret, bc1Prop1 = baseClass1.CreatePrimitiveProperty(WString ("BC1Prop1"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute(bc1Prop1, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("InheritTestSchema.BaseClass1.BC1Prop1"), WString ("Data2"), WString ("InheritTestSchema.BaseClass1.BC1Prop1"))
        ret, bc1Prop2 = baseClass1.CreatePrimitiveProperty(WString ("BC1Prop2"), ePRIMITIVETYPE_String)
        ret, bc1Prop3 = baseClass1.CreatePrimitiveProperty(WString ("BC1Prop3"), ePRIMITIVETYPE_String)

        # BaseClass2
        # BC2Prop1
        # BC2Prop2
        ret, baseClass2 = primarySchema.CreateClass(WString ("BaseClass2"))
        ret, bc2Prop1 = baseClass2.CreatePrimitiveProperty(WString ("BC2Prop1"), ePRIMITIVETYPE_String)
        ret, bc2Prop2 = baseClass2.CreatePrimitiveProperty(WString ("BC2Prop2"), ePRIMITIVETYPE_String)

        # DerivedClass1
        # BaseClass1
        ret, derivedClass1 = primarySchema.CreateClass(WString ("DerivedClass1"))
        derivedClass1.AddBaseClass(baseClass1)

        # DerivedClass2
        # BaseClass1
        # BC1Prop2
        # UselessInfo
        ret, derivedClass2 = primarySchema.CreateClass(WString ("DerivedClass2"))
        derivedClass2.AddBaseClass (baseClass1)
        ret, bc1Prop2DerivedClass2 = derivedClass2.CreatePrimitiveProperty(WString ("BC1Prop2"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute(bc1Prop2DerivedClass2, self.m_uselessInfoCAEnabler, WString ("NothingImportant"), WString ("InheritTestSchema.DerivedClass2.BC1Prop2"), WString ("NotImportant"), WString ("InheritTestSchema.DerivedClass2.BC1Prop2"))

        # DerivedClass3
        # DerivedClass2
        # BCProp1
        # SystemInfo
        ret, derivedClass3 = primarySchema.CreateClass(WString ("DerivedClass3"))
        ret, derivedClass3.AddBaseClass(derivedClass2)
        #Primitivebc1Prop1DerivedClass3
        #derivedClass3.CreatePrimitiveProperty(bc1Prop1DerivedClass3, "BC1Prop1", ePRIMITIVETYPE_String)
        #SetCustomAttribute(bc1Prop1DerivedClass3, self.m_systemInfoCAEnabler, "Data1", "InheritTestSchema.DerivedClass3.BC1Prop1 - Data1", "Data2", "InheritTestSchema.DerivedClass3.BC1Prop1 - Data2")

        # DerivedClass4
        # BaseClass2
        ret, derivedClass4 = primarySchema.CreateClass(WString ("DerivedClass4"))
        derivedClass4.AddBaseClass(baseClass2)

        return primarySchema

    def CreateLowPrioritySchema1 (self):
        ret, supplementalSchema = ECSchema.CreateSchema(WString ("LowPrioritySchema1"), 4, 3)
        metaData = SupplementalSchemaMetaData (WString ("InheritTest"), 2, 34, 1, WString ("Test"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        # DerivedClass1
        # BC1Prop1
        # SystemInfo
        ret, derivedClass1 = supplementalSchema.CreateClass(WString ("DerivedClass1"))
        ret, bc1Prop1 = derivedClass1.CreatePrimitiveProperty(WString ("BC1Prop1"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute (bc1Prop1, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("LowPrioritySchema1.DerivedClass1.BC1Prop1"), WString ("Data2"), WString ("LowPrioritySchema1.DerivedClass1.BC1Prop1"))

        # DerivedClass2
        # BC1Prop2
        # UselessInfo
        ret, derivedClass2 = supplementalSchema.CreateClass (WString ("DerivedClass2"))
        ret, bc1Prop2 = derivedClass2.CreatePrimitiveProperty(WString ("BC1Prop2"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute (bc1Prop2, self.m_uselessInfoCAEnabler, WString ("Data1"), WString ("LowPrioritySchema1.DerivedClass2.BC1Prop2"), WString ("Data2"), WString ("LowPrioritySchema1.DerivedClass2.BC1Prop2"))

        # DerivedClass4
        # BC2Prop1
        # SystemInfo
        ret, derivedClass4 = supplementalSchema.CreateClass (WString ("DerivedClass4"))
        ret, bc2Prop1DerivedClass4 = derivedClass4.CreatePrimitiveProperty (WString ("BC2Prop1"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute (bc2Prop1DerivedClass4, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("LowPrioritySchema1.DerivedClass4.BC2Prop1"), WString ("Data2"), WString ("LowPrioritySchema1.DerivedClass4.BC2Prop1"))

        return supplementalSchema

    def CreateLowPrioritySchema199 (self):
        ret, supplementalSchema = ECSchema.CreateSchema(WString ("LowPrioritySchema199"), 4, 3)
        metaData = SupplementalSchemaMetaData (WString ("InheritTest"), 2, 34, 199, WString ("Test"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        # DerivedClass1
        # BC1Prop1
        # SystemInfo
        ret, derivedClass1 = supplementalSchema.CreateClass(WString ("DerivedClass1"))
        ret, bc1Prop1 = derivedClass1.CreatePrimitiveProperty(WString ("BC1Prop1"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute(bc1Prop1, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("LowPrioritySchema199.DerivedClass1.BC1Prop1"), WString ("Data2"), WString ("LowPrioritySchema199.DerivedClass1.BC1Prop1"))

        # DerivedClass2
        # BC1Prop2
        # UselessInfo
        ret, derivedClass2 = supplementalSchema.CreateClass(WString ("DerivedClass2"))
        ret, bc1Prop2 = derivedClass2.CreatePrimitiveProperty(WString ("BC1Prop2"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute(bc1Prop2, self.m_uselessInfoCAEnabler, WString ("Data1"), WString ("LowPrioritySchema199.DerivedClass2.BC1Prop2"), WString ("Data2"), WString ("LowPrioritySchema199.DerivedClass2.BC1Prop2"))

        # DerivedClass3
        # BC1Prop1
        # SystemInfo
        ret, derivedClass3 = supplementalSchema.CreateClass(WString ("DerivedClass3"))
        ret, bc1Prop1DerivedClass3 = derivedClass3.CreatePrimitiveProperty(WString ("BC1Prop1"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute (bc1Prop1DerivedClass3, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("LowPrioritySchema199.DerivedClass3.BC1Prop1"), WString ("Data2"), WString ("LowPrioritySchema199.DerivedClass3.BC1Prop1"))

        return supplementalSchema

    def CreateHighPrioritySchema200 (self):

        ret, supplementalSchema = ECSchema.CreateSchema(WString ("HighPrioritySchema200"), 4, 3)
        metaData = SupplementalSchemaMetaData (WString ("InheritTest"), 2, 34, 200, WString ("Test"), False)
        supplementalSchema.AddReferencedSchema(self.m_customAttributeSchema)
        supplementalSchema.AddReferencedSchema(self.m_bscaSchema)
        supplementalSchema.GetCustomAttributeContainer().SetCustomAttribute(metaData.CreateCustomAttribute())

        # BaseClass2
        # BC2Prop1
        ret, baseClass2 = supplementalSchema.CreateClass(WString ("BaseClass2"))
        ret, bc2Prop1 = baseClass2.CreatePrimitiveProperty(WString ("BC2Prop1"), ePRIMITIVETYPE_String)
        self.SetCustomAttribute(bc2Prop1, self.m_systemInfoCAEnabler, WString ("Data1"), WString ("HighPrioritySchema200.BaseClass2,BC2Prop1"), WString ("Data2"), WString ("HighPrioritySchema200.BaseClass2.BC2Prop1"))

        return supplementalSchema

    def ValidatePropertyValuesAreEqual (self, instanceA, instanceB):
        collection  = instanceA.GetClass().GetProperties(True)
        for propertyA in collection:
            valueA = ECValue ()
            instanceA.GetValue (valueA, propertyA.GetName().GetWCharCP ())
            valueB = ECValue ()
            instanceB.GetValue (valueB, propertyA.GetName().GetWCharCP ())
            if (valueA.IsPrimitive()):
                if (False == valueB.IsPrimitive()):
                    #FAIL() << "valueA is a primitive but valueB is not"
                    print ("valueA is a primitive but valueB is not")
                    Fail ()
                else:
                    if (valueA.IsString()):
                        if (valueB.IsString()):
                            EXPECT_STREQ(valueA.GetString(), valueB.GetString())
                        else:
                            print ("Values of different primitive types")
                            FAIL()
                    elif (valueA.IsInteger()):
                        if (valueB.IsInteger()):
                            EXPECT_EQ(valueA.GetInteger(), valueB.GetInteger())
                        else:
                            print ("Values of different primitive types")
                            FAIL()
                    elif (valueA.IsBoolean()):
                        if (valueB.IsBoolean()):
                            EXPECT_EQ(valueA.GetBoolean(), valueB.GetBoolean())
                        else:
                            print ("Values of different primitive types")
                            FAIL()
                    elif (valueA.IsLong()):
                        if (valueB.IsLong()):
                            EXPECT_EQ(valueA.GetLong(), valueB.GetLong())
                        else:
                            print ("Values of different primitive types")
                            FAIL()
            elif (valueA.IsArray() and (False == valueB.IsArray())):
                    print ("valueA is an array but valueB is not")
                    FAIL()
            elif (valueA.IsStruct() and False == valueB.IsStruct()):
                    print ("valueA is a struct but valueB is not")
                    FAIL()

    def CustomAttributesAreEqual (self, customAttributesA, customAttributesB):
        countA = 0
        for attributeA in customAttributesA:
            countA += 1
            className = attributeA.GetClass().GetName()
            customAttributeFound = False

            for attributeB in customAttributesB:
                classB = attributeB.GetClass()
                if 0 == className.CompareTo (classB.GetName()):
                    self.ValidatePropertyValuesAreEqual(attributeA, attributeB)
                    customAttributeFound = True
                    break

            if (False == customAttributeFound):
                return False

        countB = 0
        for attributeB in customAttributesB:
            countB += 1

        EXPECT_EQ (countA, countB)

        return True

    def ValidateAreClassesIdentical (self, classA, classB, compareCustomAttributes):
        EXPECT_TRUE (ECClass.ClassesAreEqualByName(classA, classB))
        #EXPECT_EQ(classA.GetSchema().GetSchemaKey(), classB.GetSchema().GetSchemaKey())

        EXPECT_EQ (classB.GetIsCustomAttributeClass(), classA.GetIsCustomAttributeClass())
        EXPECT_EQ(classB.GetIsDomainClass(), classA.GetIsDomainClass())
        EXPECT_EQ(classB.GetIsStruct(), classA.GetIsStruct())
        if (compareCustomAttributes):
            EXPECT_TRUE(self.CustomAttributesAreEqual(classA.GetCustomAttributes(True), classB.GetCustomAttributes(True)))

        #Assert.IsFalse (TestHelpers.AreIdentical (supplementedClass, originalClass), "The Supplemented and Original classes are identical.")
        #Assert.IsTrue  (TestHelpers.HasSameValues (originalClass.GetPrimaryCustomAttributes (SPECIES_SPECIFIC_CA),
        #    supplementedClass.GetPrimaryCustomAttributes (SPECIES_SPECIFIC_CA)),
        #    "The Supplemented and Original classes have different CustomAttributes even though they were accessed using 'GetPrimaryCustomAttributes'")

    def ValidateSystemInfoCustomAttribute (self, consolidatedContainer, expectedValue1, expectedValue2):
        customAttribute = consolidatedContainer.GetCustomAttribute(WString ("Test_Custom_Attributes"), WString ("SystemInfo"))
        EXPECT_TRUE(customAttribute != None)
        ecValue = ECValue ()
        customAttribute.GetValue(ecValue, WString ("Data1").GetWCharCP ())
        EXPECT_STREQ(expectedValue1.GetWCharCP (), ecValue.GetString())

        customAttribute.GetValue(ecValue, WString ("Data2").GetWCharCP ())
        EXPECT_STREQ(expectedValue2.GetWCharCP (), ecValue.GetString())


    def ValidateUselessInfoCustomAttribute (self, consolidatedContainer, expectedValue1, expectedValue2):
        customAttribute = consolidatedContainer.GetCustomAttribute(WString ("Test_Custom_Attributes"), WString ("UselessInfo"))
        EXPECT_TRUE(customAttribute != None)
        ecValue = ECValue ()
        customAttribute.GetValue(ecValue, WString ("NothingImportant").GetWCharCP ())
        EXPECT_STREQ(expectedValue1.GetWCharCP (), ecValue.GetString())

        customAttribute.GetValue(ecValue, WString ("NotImportant").GetWCharCP ())
        EXPECT_STREQ(expectedValue2.GetWCharCP (), ecValue.GetString())


    def ValidateFolderClass (self, consolidatedClass, originalClass):
        # Make sure it is equal to the original class, but not identical
        self.ValidateAreClassesIdentical(consolidatedClass, originalClass, False)
                
        # Validate class level CAs
        self.ValidateSystemInfoCustomAttribute (consolidatedClass, WString ("Data1 on Folder Class"), WString ("Data2 on Folder Class"))
        self.ValidateUselessInfoCustomAttribute (consolidatedClass, WString ("Nothing important on Folder Class from SupplementalSchema2"), WString ("Not important on Folder Class from SupplementalSchema2"))

        propertyP = consolidatedClass.GetProperty (WString ("Hidden"))
        # Validate custom attributes on Hidden property
        self.ValidateUselessInfoCustomAttribute(propertyP, WString ("Nothing important on Hidden Property on Folder Class"), WString ("Not important on Hidden Property on Folder Class"))

        #Validate custom attributes on CreationDate property
        propertyP = consolidatedClass.GetProperty(WString ("CreationDate"))
        self.ValidateSystemInfoCustomAttribute(propertyP, WString ("Data1 on CreationDate Property on Folder Class from SupplementalSchema2"), WString ("Data2 on CreationDate Property on Folder Class from SupplementalSchema2"))

        # validate custom attributes on ReadOnly property
        propertyP = consolidatedClass.GetProperty(WString ("ReadOnly"))
        attributes = propertyP.GetCustomAttributes(False)
        count = 0
        for attribute in attributes:
            count += 1

        EXPECT_EQ(0, count)


    def ValidateFileClass (self, consolidatedClass, originalClass):
        # Make sure it is equal to the original class, but not identical
        self.ValidateAreClassesIdentical(consolidatedClass, originalClass, False)

        # validate class level CAs
        self.ValidateSystemInfoCustomAttribute(consolidatedClass, WString ("Data1 on File Class from SupplementalSchema1"), WString ("Data2 on File Class from SupplementalSchema1"))
        self.ValidateUselessInfoCustomAttribute(consolidatedClass, WString ("Nothing important on File Class from Supplemental3"), WString ("Not important on File Class from Supplemental3"))
            
        #validate custom attributes on Hidden property
        propertyP = consolidatedClass.GetProperty(WString ("Hidden"))
        self.ValidateUselessInfoCustomAttribute(propertyP, WString ("Nothing important on Hidden Property on File Class from SupplementalSchema1"), WString ("Not important on Hidden Property on File Class from SupplementalSchema1"))
        self.ValidateSystemInfoCustomAttribute(propertyP, WString ("Data1 on Hidden Property on File Class from Supplemental3"), WString ("Data2 on Hidden Property on File Class from Supplemental3"))

        # validate custom attributes on CreationDate property
        propertyP = consolidatedClass.GetProperty(WString ("CreationDate"))
        self.ValidateUselessInfoCustomAttribute(propertyP, WString ("Nothing important on CreationDate Property on File Class from Supplemental3"), WString ("Not important on CreationDate Property on File Class from Supplemental3"))

        # validate custom attributes on FileSize property
        propertyP = consolidatedClass.GetProperty(WString ("FileSize"))
        self.ValidateSystemInfoCustomAttribute(propertyP, WString ("Data1 on FileSize Property on File Class from Supplemental3"), WString ("Data2 on FileSize Property on File Class from Supplemental3"))


    def ValidateImageClass (self, consolidatedClass, originalClass):
        # Make sure it is equal to the original class, but not identical
        self.ValidateAreClassesIdentical(consolidatedClass, originalClass, False)

        # validate class level custom attributes
        self.ValidateSystemInfoCustomAttribute(consolidatedClass, WString ("Data1 on Image Class"), WString ("Data2 on Image Class"))
        self.ValidateUselessInfoCustomAttribute(consolidatedClass, WString ("Nothing important on Image Class from Supplemental3"), WString ("Not important on Image Class from Supplemental3"))

        # validate custom attributes on BitDepth property
        propertyP = consolidatedClass.GetProperty(WString ("BitDepth"))
        attributes = propertyP.GetCustomAttributes(False)
        count = 0
        for attribute in attributes:
            count += 1
        
        EXPECT_EQ(0, count)

        # validate custom attributes on Width property
        propertyP = consolidatedClass.GetProperty(WString ("Width"))
        self.ValidateUselessInfoCustomAttribute(propertyP, WString ("Nothing important on Width Property on Image Class"), WString ("Not important on Width Property on Image Class"))

        #validate custom attributes on height property
        propertyP = consolidatedClass.GetProperty(WString ("Height"))
        self.ValidateUselessInfoCustomAttribute(propertyP, WString ("Nothing important on Height Property on Image Class from Supplemental3"), WString ("Not important on Height Property on Image Class from Supplemental3"))


    def CompareSchemasPostSupplement (self, schemaPostSupplement, schemaPreSupplement):
       # Test that the schemas have the same basic information and class count
       EXPECT_TRUE(schemaPostSupplement.IsSamePrimarySchema(schemaPreSupplement))

       # Test custom attributes at the top level of the schema
       postCustomAttributes = schemaPostSupplement.GetCustomAttributeContainer().GetCustomAttributes(True)
       preCustomAttributes = schemaPreSupplement.GetCustomAttributeContainer().GetCustomAttributes(True)

       EXPECT_TRUE(self.CustomAttributesAreEqual(preCustomAttributes, postCustomAttributes))

       preClassCount = 0
       for preSupplementClass in schemaPreSupplement.GetClasses():
           EXPECT_TRUE(None != preSupplementClass)
           preClassCount += 1
           name = preSupplementClass.GetName()
           postClass = schemaPostSupplement.GetClass(name.GetWCharCP ())
           EXPECT_TRUE(None != postClass)
           self.ValidateAreClassesIdentical(preSupplementClass, postClass, True)
           EXPECT_TRUE(ECClass.ClassesAreEqualByName(preSupplementClass, postClass))
    
       EXPECT_TRUE(0 < preClassCount)

       postClassCount = 0
       for postSupplementClass in schemaPostSupplement.GetClasses():
           EXPECT_TRUE(None != postSupplementClass)
           postClassCount += 1
    
       EXPECT_EQ(preClassCount, postClassCount)


    # Compare the copies and the original schemas to make sure they were not changed by the supplementing process
    def VerifySchemasAreUnchanged (self):
       self.CompareSchemasPostSupplement(self.m_supplementalTestSchema1, self.m_supplementalTestSchema1Copy)
       self.CompareSchemasPostSupplement(self.m_supplementalTestSchema2, self.m_supplementalTestSchema2Copy)
       self.CompareSchemasPostSupplement(self.m_supplementalTestSchema3, self.m_supplementalTestSchema3Copy)
       self.CompareSchemasPostSupplement(self.m_supplementalTestSchema4, self.m_supplementalTestSchema4Copy)


    def CompareSupplementedSchemaAndPrimary (self, consolidatedSchema):
       for consolidatedClass in consolidatedSchema.GetClasses():
           if (consolidatedClass.GetName() == WString ("Folder")):
               self.ValidateFolderClass(consolidatedClass, self.m_primaryTestSchema.GetClass(WString ("Folder").GetWCharCP ()))
           elif (consolidatedClass.GetName() == WString ("File")):
               self.ValidateFileClass(consolidatedClass, self.m_primaryTestSchema.GetClass(WString ("File").GetWCharCP ()))
           elif (consolidatedClass.GetName() ==WString ("Image")):
               self.ValidateImageClass(consolidatedClass, self.m_primaryTestSchema.GetClass(WString ("Image").GetWCharCP ()))
           else:
               FAIL() << "Unexpected class found in consolidated schema"

       EXPECT_TRUE(self.m_primaryTestSchema.IsSamePrimarySchema(consolidatedSchema))
       EXPECT_TRUE(consolidatedSchema.IsSamePrimarySchema(self.m_primaryTestSchema))

       self.VerifySchemasAreUnchanged()

       EXPECT_TRUE(consolidatedSchema.IsSupplemented())

    #@classmethod
    def CreateCustomAttributeSchema (self):
       retVal, self.m_customAttributeSchema = ECSchema.CreateSchema (WString ("Test_Custom_Attributes"), 1, 0)

       ret, customAttributeClass = self.m_customAttributeSchema.CreateClass (WString ("SystemInfo"))
       customAttributeClass.SetIsCustomAttributeClass(True)
       ret, property1 = customAttributeClass.CreatePrimitiveProperty (WString ("Data1"))
       ret, property2 = customAttributeClass.CreatePrimitiveProperty (WString ("Data2"))
       self.m_systemInfoCAEnabler = customAttributeClass.GetDefaultStandaloneEnabler ()

       ret, customAttributeClass2 = self.m_customAttributeSchema.CreateClass (WString ("UselessInfo"))
       customAttributeClass2.SetIsCustomAttributeClass(True)
       ret, property3 = customAttributeClass2.CreatePrimitiveProperty (WString ("NothingImportant"))
       ret, property4 = customAttributeClass2.CreatePrimitiveProperty (WString ("NotImportant"))
       self.m_uselessInfoCAEnabler = customAttributeClass2.GetDefaultStandaloneEnabler()

       ret, customAttributeClass3 = self.m_customAttributeSchema.CreateClass (WString ("OtherInformation"))
       customAttributeClass3.SetIsCustomAttributeClass(True)
       ret, property5 = customAttributeClass3.CreatePrimitiveProperty (WString ("SomeOtherInformation"))
       ret, property6 = customAttributeClass3.CreatePrimitiveProperty (WString ("SomeInformation"))
       self.m_otherInfoCAEnabler = customAttributeClass3.GetDefaultStandaloneEnabler ()

    #@pytest.fixture(scope="module")
    def setup_method (self):
        super ().setup_method ()
        self.CreateCustomAttributeSchema ()
        self.m_primaryTestSchema = self.CreatePrimarySchema ()
        self.m_supplementalTestSchema1 = self.CreateSupplementalSchema1 ()
        self.m_supplementalTestSchema2 = self.CreateSupplementalSchema2 ()
        self.m_supplementalTestSchema3 = self.CreateSupplementalSchema3 ()
        self.m_supplementalTestSchema4 = self.CreateSupplementalSchema4 ()

        #self.m_customAttributeSchema.WriteToXmlFile("d:\\temp\\customAttribute.xm")

        #self.m_primaryTestSchema.WriteToXmlFile("d:\\temp\\supplementalSchemas\\primarySchema.xm")
        #self.m_supplementalTestSchema1.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema1.xm")
        #self.m_supplementalTestSchema2.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema2.xm")
        #self.m_supplementalTestSchema3.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema3.xm")
        #self.m_supplementalTestSchema4.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema4.xm")

        # Create duplicates so we can compare these schemas to the originals post supplementing the primary schema.
        self.m_primaryTestSchemaCopy = self.CreatePrimarySchema ()
        self.m_supplementalTestSchema1Copy = self.CreateSupplementalSchema1 ()
        self.m_supplementalTestSchema2Copy = self.CreateSupplementalSchema2 ()
        self.m_supplementalTestSchema3Copy = self.CreateSupplementalSchema3 ()
        self.m_supplementalTestSchema4Copy = self.CreateSupplementalSchema4 ()

    def teardown_method (self):
        super ().teardown_method ()

    #---------------------------------------------------------------------------------**/#*
    # Test that tries to build a consolidated schema but there are two supplemental schemas that have
    # conflicting custom attributes
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_BuildAConflictingConsolidatedSchema (self):
        supplementalSchemas = ECSchemaPArray ()
        supplementalSchemas.append(self.m_supplementalTestSchema1)
        supplementalSchemas.append(self.m_supplementalTestSchema2)
        supplementalSchemas.append(self.m_supplementalTestSchema3)
        supplementalSchemas.append(self.m_supplementalTestSchema4)

        builder = SupplementedSchemaBuilder ()
        primaryTestSchema = self.CreatePrimarySchema ()
        EXPECT_EQ(eSUPPLEMENTED_SCHEMA_STATUS_SchemaMergeException, builder.UpdateSchema(primaryTestSchema, supplementalSchemas))
        self.VerifySchemasAreUnchanged()


    #---------------------------------------------------------------------------------**/#*
    # Test that builds a consolidated schema that consists of a primary and 3 consolidated schemas.
    # One of the schemas has lower precedence than the primary, two have greater than the primary.
    # The two schemas that are greater have equal precedence
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_BuildANonConflictingConsolidatedSchema (self):
        supplementalSchemas = ECSchemaPArray ()
        supplementalSchemas.append(self.m_supplementalTestSchema1)
        supplementalSchemas.append(self.m_supplementalTestSchema2)
        supplementalSchemas.append(self.m_supplementalTestSchema3)

        builder = SupplementedSchemaBuilder ()
        primaryTestSchema = self.CreatePrimarySchema()
        EXPECT_EQ(eSUPPLEMENTED_SCHEMA_STATUS_Success, builder.UpdateSchema(primaryTestSchema, supplementalSchemas))
        #self.m_supplementalTestSchema1.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema1Post.xm")
        #self.m_supplementalTestSchema2.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema2Post.xm")
        #self.m_supplementalTestSchema3.WriteToXmlFile("d:\\temp\\supplementalSchemas\\supplementalSchema3Post.xm")

        self.CompareSupplementedSchemaAndPrimary(primaryTestSchema)


    def ValidateCustomAttributesOnDerivedClass (self, supplementedClass):
        localCustomAttributes = supplementedClass.GetCustomAttributes(False)
        localCustomAttributesCount = 0
        for attribute in localCustomAttributes:
            localCustomAttributesCount += 1

        EXPECT_EQ(2, localCustomAttributesCount)

        allCustomAttributes = supplementedClass.GetCustomAttributes(True)
        allCustomAttributesCount = 0
        for  attribute in allCustomAttributes:
            allCustomAttributesCount += 1
        
        EXPECT_EQ(4, allCustomAttributesCount)

        localCustomAttributes2 = supplementedClass.GetCustomAttributes(False)
        localCustomAttributesCount = 0
        for  attribute in localCustomAttributes2:
            localCustomAttributesCount += 1
        
        EXPECT_EQ(2, localCustomAttributesCount)


    def ValidatePrimaryCustomAttributesOnDerivedClass (self, supplementedClass):
        localCustomAttributes = supplementedClass.GetPrimaryCustomAttributes(False)

        localCustomAttributesCount = 0
        for attribute in localCustomAttributes:    
            localCustomAttributesCount += 1
        
        EXPECT_EQ(1, localCustomAttributesCount)

        allCustomAttributes = supplementedClass.GetPrimaryCustomAttributes(True)
        allCustomAttributesCount = 0
        for attribute in allCustomAttributes:
            allCustomAttributesCount += 1
        
        EXPECT_EQ(2, allCustomAttributesCount)

        localCustomAttributes2 = supplementedClass.GetPrimaryCustomAttributes(False)
        localCustomAttributesCount = 0
        for attribute in localCustomAttributes2:
            localCustomAttributesCount += 1
        
        EXPECT_EQ(1, localCustomAttributesCount)


    #---------------------------------------------------------------------------------**/#*
    # Test the GetCustomAttributes method on a derived class
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_GetCustomAttributesOnDerivedClass (self):
        classA, classB, schema = self.BuildSupplementedSchemaForCustomAttributeTests()
        self.ValidateCustomAttributesOnDerivedClass(classB)


    #---------------------------------------------------------------------------------**/#*
    # Test the GetPrimaryCustomAttributes method on a derived class
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_GetPrimaryCustomAttributesOnDerivedClass (self):
        classA, classB, schema = self.BuildSupplementedSchemaForCustomAttributeTests()
        self.ValidatePrimaryCustomAttributesOnDerivedClass(classB)


    #---------------------------------------------------------------------------------**/#*
    # Tests supplementing relationship classes
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_SupplementCustomAttributesOnRelationshipClasses (self):
        schema = self.CreatePrimarySchemaForRelationshipTests()

        # Create first supplemental schema
        supplementalSchema0 = self.CreateSupplementalSchema0ForRelationshipTests()

        supplementalSchemas = ECSchemaPArray ()
        supplementalSchemas.append(supplementalSchema0)
        builder = SupplementedSchemaBuilder ()
        EXPECT_EQ(SUPPLEMENTED_SCHEMA_STATUS_Success, builder.UpdateSchema(schema, supplementalSchemas))

        supplementedClass = schema.GetClass(WString ("RelationshipWithCustomAttributes").GetWCharCP ())
        EXPECT_TRUE(None != supplementedClass)
        supplementedRelClass = supplementedClass
        EXPECT_TRUE(None != supplementedRelClass)
        targetCA = supplementedRelClass.GetTarget().GetCustomAttribute(self.m_systemInfoCAEnabler.GetClass())
        EXPECT_TRUE(targetCA != None)
        sourceCA = supplementedRelClass.GetSource().GetCustomAttribute(self.m_systemInfoCAEnabler.GetClass())
        EXPECT_TRUE(sourceCA != None)

        supplementalSchema1 = self.CreateSupplementalSchema1ForRelationshipTests()
        supplementalSchemas.append(supplementalSchema1)

        schema2 = self.CreatePrimarySchemaForRelationshipTests()
        builder2 = SupplementedSchemaBuilder ()
        EXPECT_EQ(eSUPPLEMENTED_SCHEMA_STATUS_Success, builder2.UpdateSchema(schema2, supplementalSchemas))

        supplementedClass = schema2.GetClass(WString ("RelationshipWithCustomAttributes").GetWCharCP ())
        EXPECT_TRUE(None != supplementedClass)
        supplementedRelClass = supplementedClass
        EXPECT_TRUE(None != supplementedRelClass)
        targetCA = supplementedRelClass.GetTarget().GetCustomAttribute(self.m_systemInfoCAEnabler.GetClass())
        EXPECT_TRUE(targetCA != None)
        sourceCA = supplementedRelClass.GetSource().GetCustomAttribute(self.m_systemInfoCAEnabler.GetClass())
        EXPECT_TRUE(sourceCA != None)

        targetCA = supplementedRelClass.GetTarget().GetCustomAttribute(self.m_uselessInfoCAEnabler.GetClass())
        EXPECT_TRUE(targetCA != None)
        sourceCA = supplementedRelClass.GetSource().GetCustomAttribute(self.m_uselessInfoCAEnabler.GetClass())
        EXPECT_TRUE(sourceCA != None)

        supplementedClass = schema2.GetClass(WString ("RelClass2").GetWCharCP ())
        EXPECT_TRUE(None != supplementedClass)
        supplementedRelClass = supplementedClass
        EXPECT_TRUE(None != supplementedRelClass)
        targetCA = supplementedRelClass.GetTarget().GetCustomAttribute(self.m_otherInfoCAEnabler.GetClass())
        EXPECT_TRUE(targetCA != None)
        sourceCA = supplementedRelClass.GetSource().GetCustomAttribute(self.m_otherInfoCAEnabler.GetClass())
        EXPECT_TRUE(sourceCA != None)


    #---------------------------------------------------------------------------------**/#*
    # @bsimethod                                    Carole.MacDonald                05/2012
    #---------------+---------------+---------------+---------------+---------------+------*/
    def test_SupplementingWithInheritance (self):
        inheritPrimarySchema = self.CreatePrimarySchemaForInheritTests()
        lowPrioritySchema1 = self.CreateLowPrioritySchema1()
        lowPrioritySchema199 = self.CreateLowPrioritySchema199()
        highPrioritySchema200 = self.CreateHighPrioritySchema200()

        supplementalSchemas = ECSchemaPArray ()
        supplementalSchemas.append(lowPrioritySchema1)
        supplementalSchemas.append(lowPrioritySchema199)
        supplementalSchemas.append(highPrioritySchema200)

        builder = SupplementedSchemaBuilder ()
        builder.UpdateSchema(inheritPrimarySchema, supplementalSchemas)

        EXPECT_TRUE(inheritPrimarySchema.IsSupplemented())

        # DerivedClass1.BC1Prop1 should have its custom attribute applied by a low precedence supplemental schema
        derivedClass1 = inheritPrimarySchema.GetClass(WString ("DerivedClass1").GetWCharCP ())
        EXPECT_TRUE(None != derivedClass1)
        bc1Prop1DerivedClass1 = derivedClass1.GetProperty(WString ("BC1Prop1"))
        EXPECT_TRUE(None != bc1Prop1DerivedClass1)
        self.ValidateSystemInfoCustomAttribute(bc1Prop1DerivedClass1, WString ("LowPrioritySchema199.DerivedClass1.BC1Prop1"), WString ("LowPrioritySchema199.DerivedClass1.BC1Prop1"))

        # DerivedClass2.BC1Prop2 should have its custom attribute applied by the primary schema
        derivedClass2 = inheritPrimarySchema.GetClass(WString ("DerivedClass2").GetWCharCP ())
        EXPECT_TRUE(None != derivedClass2)
        bc1Prop2DerivedClass2 = derivedClass2.GetProperty(WString ("BC1Prop2"))
        EXPECT_TRUE(None != bc1Prop2DerivedClass2)
        self.ValidateUselessInfoCustomAttribute(bc1Prop2DerivedClass2, WString ("InheritTestSchema.DerivedClass2.BC1Prop2"), WString ("InheritTestSchema.DerivedClass2.BC1Prop2"))

        # DerivedClass3.BC1Prop1 should have its custom attribute applied by a low precedence supplemental schema
        derivedClass3 = inheritPrimarySchema.GetClass(WString ("DerivedClass3").GetWCharCP ())
        EXPECT_TRUE (None != derivedClass3)
        bc1Prop1DerivedClass3 = derivedClass3.GetProperty(WString ("BC1Prop1"))
        EXPECT_TRUE (None != bc1Prop1DerivedClass3)
        self.ValidateSystemInfoCustomAttribute(bc1Prop1DerivedClass3, WString ("LowPrioritySchema199.DerivedClass3.BC1Prop1"), WString ("LowPrioritySchema199.DerivedClass3.BC1Prop1"))

        # DerivedClass4.BC2Prop1 should have its custom attribute applied by a low precedence supplemental schema
        derivedClass4 = inheritPrimarySchema.GetClass(WString ("DerivedClass4").GetWCharCP ())
        EXPECT_TRUE(None != derivedClass4)
        bc2Prop1DerivedClass4 = derivedClass4.GetProperty(WString ("BC2Prop1"))
        EXPECT_TRUE(None != bc2Prop1DerivedClass4)
        self.ValidateSystemInfoCustomAttribute(bc2Prop1DerivedClass4, WString ("LowPrioritySchema1.DerivedClass4.BC2Prop1"), WString ("LowPrioritySchema1.DerivedClass4.BC2Prop1"))

def test_VerifyDeserializedSchemaIsSupplemented ():
   schemaContext = ECSchemaReadContext.CreateContext()

   seedPath = getTestDataPath ("ECSeedData/")
   schemaContext.AddSchemaPath(seedPath.GetWCharCP ())
   key = SchemaKey (WString ("MasterSchema").GetWCharCP (), 1, 0)
   testSchema = schemaContext.LocateSchema(key, eSCHEMAMATCHTYPE_Latest)
   EXPECT_TRUE(testSchema.IsSupplemented())

