import os
import pytest
import ctypes

import win32com.client  
import pythoncom  

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from util import *

UINT_MAX = 4294967295
NPOS = -1
    
def getTempDataPath (tempFileName):
    return WString (os.path.join (os.environ['TEMP'], tempFileName))

def getTestDataPath (fileName):
    return WString (os.path.join (os.environ['MSPYTESTDATA'], fileName))

def checkPropertyCount (ecClass, nPropertiesWithoutBaseClasses, nPropertiesWithBaseClasses):
    assert (ecClass.GetPropertyCount (False) == nPropertiesWithoutBaseClasses)
    assert (ecClass.GetPropertyCount (True) == nPropertiesWithBaseClasses)


def getPropertyByName (ecClass, name, expectExists = True):
    prop = ecClass.GetProperty (name)
    assert (expectExists == (None != prop))
    utf8 = Utf8String (name)
    prop = ecClass.GetProperty (utf8.__repr__ ())
    assert (expectExists == (None != prop))

    return prop

def verifyWidgetsSchema (schema):
    assert (WString ("Widgets") == schema.GetName ())
    assert (WString ("wid") == schema.GetNamespacePrefix ())
    assert (WString ("Widgets Display Label") == schema.GetDisplayLabel ())
    assert (True == schema.GetIsDisplayLabelDefined ())
    assert (WString ("Widgets Description") == schema.GetDescription ())
    assert (9 == schema.GetVersionMajor ())
    assert (6 == schema.GetVersionMinor ()) 

    pClass = schema.GetClass ("ClassDoesNotExistInSchema")
    assert (None == pClass)

    pClass = schema.GetClass ("ecProject")
    assert (None != pClass)
    assert (WString ("ecProject") == pClass.GetName ())
    assert (WString ("Project") == pClass.GetDisplayLabel ())
    assert (True == pClass.GetIsDisplayLabelDefined ())
    assert (WString ("Project Class") == pClass.GetDescription ())
    assert (False == pClass.GetIsStruct ())
    assert (False == pClass.GetIsCustomAttributeClass ())
    assert (True == pClass.GetIsDomainClass ())
    assert (False == pClass.HasBaseClasses ())

    pProperty = getPropertyByName (pClass, "Name")
    assert (None != pProperty)
    assert (WString ("Name") == pProperty.GetName ())
    assert (True == pProperty.GetIsPrimitive ())
    assert (False == pProperty.GetIsStruct ())
    assert (False == pProperty.GetIsArray ())
    assert (WString ("string") == pProperty.GetTypeName ())
    assert (True == (ePRIMITIVETYPE_String == pProperty.AsPrimitiveProperty ().GetType()))
    assert (True == pProperty.GetIsDisplayLabelDefined ())
    assert (WString ("Project Name") == pProperty.GetDisplayLabel ())
    assert (WString ("") == pProperty.GetDescription())
    assert (pClass == pProperty.GetClass())
    assert (False == pProperty.GetIsReadOnly ())

    pProperty = getPropertyByName (pClass, "PropertyDoesNotExistInClass", False)
    assert (None == pProperty)

    customAttribClass = schema.GetClass ("AccessCustomAttributes")
    assert (None != customAttribClass)
    assert (WString ("AccessCustomAttributes") == customAttribClass.GetName ())
    assert (WString ("AccessCustomAttributes") == customAttribClass.GetDisplayLabel ())
    assert (False == customAttribClass.GetIsDisplayLabelDefined ())
    assert (WString ("") == customAttribClass.GetDescription ())
    assert (False == customAttribClass.GetIsStruct ())
    assert (True == customAttribClass.GetIsCustomAttributeClass ())
    assert (False == customAttribClass.GetIsDomainClass ())
    assert (False == customAttribClass.HasBaseClasses ())

    pClass = schema.GetClass ("Struct1")
    assert (None != pClass)
    assert (WString ("Struct1") == pClass.GetName ())
    assert (WString ("Struct1") == pClass.GetDisplayLabel ())
    assert (False == pClass.GetIsDisplayLabelDefined ())
    assert (WString ("") == pClass.GetDescription ())
    assert (True == pClass.GetIsStruct ())
    assert (False == pClass.GetIsCustomAttributeClass ())
    assert (False == pClass.GetIsDomainClass ())
    assert (False == pClass.HasBaseClasses ())

    pClass = schema.GetClass("Struct2")
    assert (None != pClass)
    assert (WString ("Struct2") == pClass.GetName ())
    assert (WString ("Struct2") == pClass.GetDisplayLabel ())
    assert (False == pClass.GetIsDisplayLabelDefined ())
    assert (WString ("") == pClass.GetDescription ())
    assert (True == pClass.GetIsStruct ())
    assert (False == pClass.GetIsCustomAttributeClass ())
    assert (True == pClass.GetIsDomainClass ())
    assert (False == pClass.HasBaseClasses ())

    pProperty = getPropertyByName (pClass, "NestedArray")
    assert (None != pProperty)
    assert (WString ("NestedArray") == pProperty.GetName ())
    assert (False == pProperty.GetIsPrimitive ())
    assert (False == pProperty.GetIsStruct ())
    assert (True == pProperty.GetIsArray ())
    assert (WString ("Struct1") == pProperty.GetTypeName ())

    arrayProperty = pProperty.AsArrayProperty ()
    assert (ArrayKind.eARRAYKIND_Struct == arrayProperty.GetKind ())
    assert (schema.GetClass ("Struct1") == arrayProperty.GetStructElementType ()) 
    assert (0 == arrayProperty.GetMinOccurs ())
    assert (UINT_MAX == arrayProperty.GetMaxOccurs ())
    assert (False == pProperty.GetIsDisplayLabelDefined ())
    assert (WString ("NestedArray") == pProperty.GetDisplayLabel ())
    assert (WString ("") == pProperty.GetDescription ())
    assert (pClass == pProperty.GetClass())  
    assert (False == pProperty.GetIsReadOnly())

    pClass = schema.GetClass ("TestClass")
    assert (None != pClass)
    assert (True == pClass.HasBaseClasses ())
    pProperty = getPropertyByName (pClass, "EmbeddedStruct")
    assert (None != pProperty)
    assert (WString ("EmbeddedStruct") == pProperty.GetName ())
    assert (False == pProperty.GetIsPrimitive ())
    assert (True == pProperty.GetIsStruct ())
    assert (False == pProperty.GetIsArray ())
    assert (WString ("Struct1") == pProperty.GetTypeName ())

    structProperty = pProperty.AsStructProperty()
    assert (schema.GetClass("Struct1") == (structProperty.GetType ()))
    assert (False == pProperty.GetIsDisplayLabelDefined ())
    assert (WString ("EmbeddedStruct") == pProperty.GetDisplayLabel ())
    assert (WString ("") == pProperty.GetDescription ())
    assert (pClass == pProperty.GetClass ())
    assert (False == pProperty.GetIsReadOnly ())
    
    instance = pClass.GetCustomAttribute (customAttribClass)
    assert (None != instance)

    ecValue = ECValue ()
    assert (BentleyStatus.eSUCCESS == instance.GetValue (ecValue, "AccessLevel"))
    assert (4 == ecValue.GetInteger ())

    assert (BentleyStatus.eSUCCESS == instance.GetValue (ecValue, "Writeable"))
    assert (False == ecValue.GetBoolean())

def validateSchemaNameParsing (fullName, expectFailure, expectName, expectMajor, expectMinor):
    status, shortName, versionMajor, versionMinor = ECSchema.ParseSchemaFullName (fullName)

    if expectFailure :
        assert (ECObjectsStatus.eECOBJECTS_STATUS_Success != status)
        return

    assert (ECObjectsStatus.eECOBJECTS_STATUS_Success == status)

    assert shortName == WString (expectName)
    assert versionMajor == expectMajor
    assert versionMinor == expectMinor

def test_parseFullSchemaName ():
    validateSchemaNameParsing ("TestName.6.8",      False, "TestName", 6, 8)
    validateSchemaNameParsing ("TestName.16.18",    False, "TestName", 16, 18)
    validateSchemaNameParsing ("TestName.126.128",  False, "TestName", 126, 128)
    validateSchemaNameParsing ("TestName.1267.128", True,  None, 0, 0)
    validateSchemaNameParsing ("TestName.1267",     True,  None, 0, 0)
    validateSchemaNameParsing ("TestName",          True,  None, 0, 0)
    validateSchemaNameParsing ("",                  True,  None, 0, 0)
    validateSchemaNameParsing ("12.18",             True,  None, 0, 0)


def test_expectErrorWhenXmlFileDoesNotExist ():
    ECSchema.SetErrorHandling (True, False)
    schemaContext = ECSchemaReadContext.CreateContext ()

    schemaXMLFile = getTestDataPath ("ECSeedData/ThisFileIsntReal.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_FailedToParseXml == status)

def test_expectErrorWhenXmlFileIsMissingNodes ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext ()

    schemaXMLFile = getTestDataPath ("ECSeedData/MissingNodes.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_FailedToParseXml == status)

def test_expectErrorWhenXmlFileIsIllFormed ():
    #show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext ()

    schemaXMLFile = getTestDataPath ("ECSeedData/IllFormedXml.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_FailedToParseXml == status)

def test_expectErrorWhenXmlFileIsMissingECSchemaNode ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext ()

    schemaXMLFile = getTestDataPath ("ECSeedData/MissingECSchemaNode.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_InvalidECSchemaXml == status)    


def test_expectErrorWhenXmlFileIsMissingNamespace ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)
    
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/MissingNamespace.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_InvalidECSchemaXml == status)

def test_expectSuccessWhenCustomAttributeIsMissingNamespace ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/MissingNamespaceOnCustomAttribute.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

def test_expectErrorWhenXmlFileHasUnsupportedNamespace ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/UnsupportedECXmlNamespace.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_InvalidECSchemaXml == status)

def test_ExpectSuccessWithDuplicateNamespacePrefixes ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/DuplicatePrefixes.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

def test_ExpectErrorWhenXmlFileHasMissingSchemaNameAttribute ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/MissingSchemaName.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_InvalidECSchemaXml == status)

def test_ExpectErrorWhenXmlFileHasMissingClassNameAttribute ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/MissingClassName.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_InvalidECSchemaXml == status)

def test_ExpectSuccessWhenXmlFileHasInvalidVersionString ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/InvalidVersionString.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (1 == schema.GetVersionMajor())
    assert (0 == schema.GetVersionMinor())
    assert (eSCHEMA_READ_STATUS_Success == status)

def test_ExpectFailureWhenMissingTypeNameInProperty ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    status, schema = ECSchema.ReadFromXmlString (
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"Widgets\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typename=\"string\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_InvalidECSchemaXml == status)

def test_ExpectUnrecognizedTypeNamesToSurviveRoundtrip ():
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXml = WString ("<?xml version='1.0' encoding='UTF-8'?>"
                         "<ECSchema schemaName='a' version='23.42' nameSpacePrefix='a' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>"
                         "    <ECClass typeName='c'>"
                         "       <ECProperty      propertyName='p' typeName='foobar'  />"
                         "       <ECArrayProperty propertyName='q' typeName='barfood' minOccurs='0' maxOccurs='unbounded'/>"
                         "    </ECClass>"
                         "</ECSchema>")
    status, schema = ECSchema.ReadFromXmlString (schemaXml.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    ecSchemaXml = WString ()
    writeStatus = schema.WriteToXmlString (ecSchemaXml)
    assert (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success == writeStatus)
    assert (True == ecSchemaXml.Contains("typeName=\"foobar\""))
    assert (True == ecSchemaXml.Contains("typeName=\"barfood\""))


def test_ExpectSuccessWithInvalidTypeNameInPrimitiveProperty ():
    schemaContext = ECSchemaReadContext.CreateContext()

    status, schema = ECSchema.ReadFromXmlString (
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"Widgets\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "<ECSchemaReference name=\"EditorCustomAttributes\" version=\"01.00\" prefix=\"beca\" />"
        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typeName=\"strng\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    pClass = schema.GetClass ("ecProject")
    pProperty = getPropertyByName (pClass, "Name")
    assert (True == (ePRIMITIVETYPE_String == pProperty.AsPrimitiveProperty().GetType()))


def test_ExpectSuccessWithEmptyCustomAttribute ():
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/EmptyCustomAttribute.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    ecSchemaXmlString = WString ()
    status2 = schema.WriteToXmlString(ecSchemaXmlString)
    assert (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success == status2)
    assert (NPOS != ecSchemaXmlString.FindI ("<Relationship/>"))

def test_ExpectSuccessWhenDeserializingSchemaWithBaseClassInReferencedFile ():
    schemaContext = ECSchemaReadContext.CreateContext ()
    seedPath = getTestDataPath ("ECSeedData/")
    schemaContext.AddSchemaPath (seedPath.GetWCharCP ())

    schemaXMLFile = getTestDataPath ("ECSeedData/SchemaThatReferences.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    pClass = schema.GetClass ("circle")
    assert (None != pClass)

def test_ExpectSuccessWhenECSchemaContainsOnlyRequiredAttributes ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/OnlyRequiredECSchemaAttributes.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)

    assert (eSCHEMA_READ_STATUS_Success == status)
    assert (WString ("OnlyRequiredECSchemaAttributes") == schema.GetName())
    assert (WString ("") == schema.GetNamespacePrefix())
    assert (WString ("OnlyRequiredECSchemaAttributes") == schema.GetDisplayLabel())
    assert (False == schema.GetIsDisplayLabelDefined())
    assert (WString ("") == schema.GetDescription())
    assert (1 == schema.GetVersionMajor())
    assert (0 == schema.GetVersionMinor())
    
    pClass = schema.GetClass("OnlyRequiredECClassAttributes")
    assert (None != pClass)
    assert (WString ("OnlyRequiredECClassAttributes") == pClass.GetName())
    assert (WString ("OnlyRequiredECClassAttributes") == pClass.GetDisplayLabel())
    assert (False == pClass.GetIsDisplayLabelDefined())
    assert (WString ("") == pClass.GetDescription())
    assert (False == pClass.GetIsStruct())
    assert (False == pClass.GetIsCustomAttributeClass())
    assert (True == pClass.GetIsDomainClass())


def test_ExpectSuccessWhenDeserializingWidgetsECSchema ():
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/Widgets.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    verifyWidgetsSchema (schema)


def test_ExpectSuccessWhenDeserializingECSchemaFromString ():
    schemaContext = ECSchemaReadContext.CreateContext()

    strXml = WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                        "<ECSchema schemaName=\"Widgets\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">\n"
                        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\">\n"
                        "       <ECProperty propertyName=\"Name\" typeName=\"string\" displayLabel=\"Project Name\" />\n"
                        "       <ECProperty propertyName=\"Geometry\" typeName=\"Bentley.Geometry.Common.IGeometry\" displayLabel=\"Geometry\" />\n"
                        "       <ECProperty propertyName=\"LineSegment\" typeName=\"Bentley.Geometry.Common.ILineSegment\" displayLabel=\"Line Segment\" />\n"
                        "    </ECClass>\n"
                        "</ECSchema>")
    status, schema = ECSchema.ReadFromXmlString (strXml.GetWCharCP (), schemaContext)

    assert (eSCHEMA_READ_STATUS_Success == status)
    assert (WString ("Widgets") == schema.GetName())
    assert (WString ("wid") == schema.GetNamespacePrefix())
    assert (WString ("Widgets Display Label") == schema.GetDisplayLabel())
    assert (True == schema.GetIsDisplayLabelDefined())
    assert (WString ("Widgets Description") == schema.GetDescription())
    assert (9 == schema.GetVersionMajor())
    assert (6 == schema.GetVersionMinor())

    pClass = schema.GetClass("ClassDoesNotExistInSchema")
    assert (None == pClass)

    pClass = schema.GetClass("ecProject")
    assert (None != pClass)
    assert (WString ("ecProject") == pClass.GetName())
    assert (WString ("Project") == pClass.GetDisplayLabel())
    assert (True == pClass.GetIsDisplayLabelDefined())
    assert (WString ("Project ECClass") == pClass.GetDescription())
    assert (False == pClass.GetIsStruct())
    assert (False == pClass.GetIsCustomAttributeClass())
    assert (True == pClass.GetIsDomainClass())
    assert (False == pClass.HasBaseClasses())

    pProperty = getPropertyByName (pClass, "Name")
    assert (None != pProperty)
    assert (WString ("Name") == pProperty.GetName())
    assert (True == pProperty.GetIsPrimitive())
    assert (False == pProperty.GetIsStruct())
    assert (False == pProperty.GetIsArray())
    assert (WString ("string") == pProperty.GetTypeName())
    assert (True == (ePRIMITIVETYPE_String == pProperty.AsPrimitiveProperty().GetType()))
    assert (True == pProperty.GetIsDisplayLabelDefined())
    assert (WString ("Project Name") == pProperty.GetDisplayLabel())
    assert (WString ("") == pProperty.GetDescription())
    assert (pClass == pProperty.GetClass())
    assert (False == pProperty.GetIsReadOnly())

    pProperty = pClass.GetProperty ("Geometry")
    assert (None != pProperty)
    assert (WString ("Geometry") == pProperty.GetName())
    assert (True == pProperty.GetIsPrimitive())
    assert (False == pProperty.GetIsStruct())
    assert (False == pProperty.GetIsArray())
    assert (WString ("Bentley.Geometry.Common.IGeometry") == pProperty.GetTypeName())
    assert (True == (ePRIMITIVETYPE_IGeometry == pProperty.AsPrimitiveProperty().GetType()))
    assert (True == pProperty.GetIsDisplayLabelDefined())
    assert (WString ("Geometry") == pProperty.GetDisplayLabel())
    assert (WString ("") == pProperty.GetDescription())
    assert (pClass == pProperty.GetClass())
    assert (False == pProperty.GetIsReadOnly())

    pProperty = pClass.GetProperty ("LineSegment")
    assert (None != pProperty)
    assert (WString ("LineSegment") == pProperty.GetName())
    assert (True == pProperty.GetIsPrimitive())
    assert (False == pProperty.GetIsStruct())
    assert (False == pProperty.GetIsArray())
    assert (WString ("Bentley.Geometry.Common.IGeometry") == pProperty.GetTypeName())
    assert (True == (ePRIMITIVETYPE_IGeometry == pProperty.AsPrimitiveProperty().GetType()))
    assert (True == pProperty.GetIsDisplayLabelDefined())
    assert (WString ("Line Segment") == pProperty.GetDisplayLabel())
    assert (WString ("") == pProperty.GetDescription())
    assert (pClass == pProperty.GetClass())
    assert (False == pProperty.GetIsReadOnly())

    pProperty = getPropertyByName (pClass, "PropertyDoesNotExistInClass", False)
    assert (None == pProperty)


def test_ExpectSuccessWhenRoundtripUsingString ():
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/Widgets.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)

    verifyWidgetsSchema (schema)
    assert (eSCHEMA_READ_STATUS_Success == status)

    ecSchemaXmlString = WString ()
    status2 = schema.WriteToXmlString (ecSchemaXmlString)
    assert (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success == status2)

    schemaContext = ECSchemaReadContext.CreateContext()
    status, deserializedSchema = ECSchema.ReadFromXmlString(ecSchemaXmlString.GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    verifyWidgetsSchema(deserializedSchema)


def test_ExpectDomainClassToBeSetProperly ():
    schemaContext = ECSchemaReadContext.CreateContext()

    status, schema = ECSchema.ReadFromXmlString (
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"Widgets\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\" isCustomAttributeClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typeName=\"string\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "    <ECClass typeName=\"ecWidget\" description=\"Widget ECClass\" displayLabel=\"Widget\" isCustomAttributeClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typeName=\"string\" displayLabel=\"Widget Name\" />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    pClass = schema.GetClass("ecProject")
    assert (True == pClass.GetIsCustomAttributeClass())
    assert (True == pClass.GetIsDomainClass())

    pClass = schema.GetClass("ecWidget")
    assert (True == pClass.GetIsCustomAttributeClass())
    assert (False == pClass.GetIsDomainClass())

def test_ExpectIsFinalToBeSetProperly ():
    # Test that isFinal attribute is serialized/deserialized
    schemaContext = ECSchemaReadContext.CreateContext()

    status, schema = ECSchema.ReadFromXmlString(
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"Widgets\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isFinal=\"True\" isCustomAttributeClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typeName=\"string\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    assert (eSCHEMA_READ_STATUS_Success == status)

    pClass = schema.GetClass("ecProject")
    assert (True == pClass.GetIsFinal())

    ecSchemaXmlString = WString ()
    status3 = schema.WriteToXmlString(ecSchemaXmlString)
    assert (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success == status3)

    status, testSchema = ECSchema.ReadFromXmlString(ecSchemaXmlString.GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    testClass = testSchema.GetClass("ecProject")
    EXPECT_TRUE (testClass.GetIsFinal())


def test_ExpectSuccessWithDuplicateClassesInXml ():
    schemaContext = ECSchemaReadContext.CreateContext()

    status, schema = ECSchema.ReadFromXmlString (
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"Widgets\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "    <ECClass typeName=\"DifferentClass\" isDomainClass=\"True\">"
        "    </ECClass>"
        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typeName=\"string\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "    <ECClass typeName=\"ecProject\" isDomainClass=\"True\">"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)

    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status) 

    # Nothing should have been overwritten
    projectClass = schema.GetClass("ecProject")
    ASSERT_TRUE (None != projectClass)
    EXPECT_STREQ(WString ("Project ECClass"), projectClass.GetDescription())
    EXPECT_STREQ(WString ("Project"), projectClass.GetDisplayLabel())

    pProperty = getPropertyByName (projectClass, "Name")
    ASSERT_TRUE (None != pProperty)
    EXPECT_STREQ (WString ("Name"), pProperty.GetName())
    assert (True == pProperty.GetIsPrimitive())
    assert (False == pProperty.GetIsStruct())
    assert (False == pProperty.GetIsArray())
    EXPECT_STREQ (WString ("string"), pProperty.GetTypeName())

    schemaContext2 = ECSchemaReadContext.CreateContext()

    status, schema2 = ECSchema.ReadFromXmlString (
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"Widgets2\" version=\"09.06\" displayLabel=\"Widgets Display Label\" description=\"Widgets Description\" nameSpacePrefix=\"wid\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\">"
        "       <ECProperty propertyName=\"Name\" typeName=\"string\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "    <ECClass typeName=\"ecProject\" description=\"New Project ECClass\" isDomainClass=\"True\">"
        "       <ECProperty propertyName=\"Author\" typeName=\"string\" displayLabel=\"Project Name\" />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext2)

    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)

    projectClass = schema2.GetClass("ecProject")
    ASSERT_TRUE (None != projectClass)
    EXPECT_STREQ(WString ("New Project ECClass"), projectClass.GetDescription())
    EXPECT_STREQ(WString ("Project"), projectClass.GetDisplayLabel())

    pProperty = getPropertyByName (projectClass, "Name")
    ASSERT_TRUE (None != pProperty)
    EXPECT_STREQ (WString ("Name"), pProperty.GetName())
    assert (True == pProperty.GetIsPrimitive())
    assert (False == pProperty.GetIsStruct())
    assert (False == pProperty.GetIsArray())
    EXPECT_STREQ (WString ("string"), pProperty.GetTypeName())

    pProperty = getPropertyByName (projectClass, "Author")
    ASSERT_TRUE (None != pProperty)
    EXPECT_STREQ (WString ("Author"), pProperty.GetName())
    assert (True == pProperty.GetIsPrimitive())
    assert (False == pProperty.GetIsStruct())
    assert (False == pProperty.GetIsArray())
    EXPECT_STREQ (WString ("string"), pProperty.GetTypeName())


def test_ExpectSuccessWhenSerializingToFile ():
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/Widgets.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    EXPECT_EQ(status, eSCHEMA_READ_STATUS_Success)
    verifyWidgetsSchema(schema)

    status2 = schema.WriteToXmlFile (getTempDataPath ("test.xml").GetWCharCP ())
    EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)

NEEDSWORK_LIBXML = False
# In this test, it uses Windows API CreateStreamOnHGlobal get a IStream. How to get it and how to use it in python code?
# For the corresponding C++ test in schenatests.cpp in \PPBase\ECObjects\test\Published\SchemaTests.cpp, it uses NEEDSWORK_LIBXML
# on it
if NEEDSWORK_LIBXML:
    def test_ExpectSuccessWhenRoundtripUsingStream ():
        schemaContext = ECSchemaReadContext.CreateContext()

        schemaXMLFile = getTestDataPath ("ECSeedData/Widgets.01.00.ecschema.xml")
        status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)

        verifyWidgetsSchema(schema)

        EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)

        pyIStream = pythoncom.CreateStreamOnHGlobal (None, True)

        #Following python code, they need more work
        #status2 = schema.WriteToXmlStream(pyIStream, False)
        #EXPECT_EQ(SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
        
        #LARGE_INTEGER liPos = {0};
        #pyIStream.Seek(0, 0)

        #ECSchemaP deserializedSchema;
        #schemaOwner = ECSchemaCache::Create() # We need a new cache... we don't want to read the ECSchema into the cache that already has a copy of this ECSchema
        #schemaContext = ECSchemaReadContext.CreateContext(schemaOwner)
        #status = ECSchema.ReadFromXmlStream(deserializedSchema, stream, schemaContext)
        #EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status) 

        #verifyWidgetsSchema(deserializedSchema)


def ExpectSuccessWithSerializingBaseClasses ():
    retVal, schema = ECSchema.CreateSchema (WString ("Widget"), 5, 5)
    retVal, schema2 = ECSchema.CreateSchema (WString ("BaseSchema"), 5, 5)
    retVal, schema3 = ECSchema.CreateSchema (WString ("BaseSchema2"), 5, 5)
    
    schema.SetNamespacePrefix (WString ("ecw"))
    schema2.SetNamespacePrefix (WString ("base"))
    schema3.SetNamespacePrefix (WString ("base"))

    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, gadget = schema.CreateClass (WString ("Gadget"))
    retVal, bolt = schema.CreateClass (WString ("Bolt"))
    retVal, baseClass = schema2.CreateClass (WString ("BaseClass"))
    retVal, anotherBase = schema3.CreateClass (WString ("AnotherBase"))
    
    EXPECT_EQ(eECOBJECTS_STATUS_SchemaNotFound, class1.AddBaseClass(baseClass))
    schema.AddReferencedSchema(schema2)
    schema.AddReferencedSchema(schema3)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.AddBaseClass(baseClass))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.AddBaseClass(anotherBase))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, gadget.AddBaseClass(class1))

    status2 = schema.WriteToXmlFile (getTempDataPath ("base.xml").GetWCharCP ())
    EXPECT_EQ(SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
    
    ecSchemaXmlString = WString ()
    status3 = schema.WriteToXmlString(ecSchemaXmlString)
    EXPECT_EQ(SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status3)


def test_AddAndRemoveReferencedSchemas ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)

    retVal, refSchema = ECSchema.CreateSchema (WString ("RefSchema"), 5, 5)

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.AddReferencedSchema(refSchema))

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_NamedItemAlreadyExists, schema.AddReferencedSchema(refSchema))

    refList = schema.GetReferencedSchemas()

    schemaIterator = refList.__getitem__ (refSchema.GetSchemaKey())
    EXPECT_FALSE(schemaIterator == None)

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.RemoveReferencedSchema(refSchema))

    try:
        schemaIterator = None
        schemaIterator = refList.__getitem__ (refSchema.GetSchemaKey())
    except:
        EXPECT_TRUE(schemaIterator == None)

    EXPECT_EQ(eECOBJECTS_STATUS_SchemaNotFound, schema.RemoveReferencedSchema(refSchema))


def test_InvalidReference ():
    # show error messages but do not assert.
    ECSchema.SetErrorHandling (True, False)

    schemaContext = ECSchemaReadContext.CreateContext()
    seedPath = getTestDataPath ("")
    schemaContext.AddSchemaPath (seedPath.GetWCharCP ())

    #The "InvalidReference" schema contains a reference to BaseSchema.01.01.  This schema 
    #does not exist.  1.0 exists, but the minor version numbers are incompatible.
    schemaXMLFile = getTestDataPath ("ECSeedData/InvalidReference.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)

    assert (True == (None == schema))
    EXPECT_EQ (eSCHEMA_READ_STATUS_ReferencedSchemaNotFound, status)


def test_ExpectErrorWhenTryRemoveSchemaInUse ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)

    retVal, refSchema = ECSchema.CreateSchema (WString ("RefSchema"), 5, 5)

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.AddReferencedSchema(refSchema))

    retVal, baseClass = refSchema.CreateClass (WString ("BaseClass"))
    retVal, structClass = refSchema.CreateClass (WString ("StructClass"))
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    structClass.SetIsStruct(True)
    
    class1.AddBaseClass(baseClass)
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_SchemaInUse, schema.RemoveReferencedSchema(refSchema))
    
    class1.RemoveBaseClass(baseClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.RemoveReferencedSchema(refSchema))

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.AddReferencedSchema(refSchema))

    retVal, structProp = class1.CreateStructProperty (WString ("StructMember"))
    retVal, nestedArrayProp = class1.CreateArrayProperty (WString ("NestedArray"))

    retVal,primitiveArrayProp = class1.CreateArrayProperty (WString ("PrimitiveArrayProp"))
    primitiveArrayProp.SetPrimitiveElementType (PrimitiveType.ePRIMITIVETYPE_Long)
    primitiveArrayProp.SetMinOccurs(1)
    primitiveArrayProp.SetMaxOccurs(10)

    structProp.SetType(structClass)
    nestedArrayProp.SetStructElementType(structClass)

    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_SchemaInUse, schema.RemoveReferencedSchema(refSchema))
    class1.RemoveProperty (WString ("StructMember"))
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_SchemaInUse, schema.RemoveReferencedSchema(refSchema))
    class1.RemoveProperty (WString ("NestedArray"))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, schema.RemoveReferencedSchema(refSchema))


def test_ExpectFailureWithCircularReferences ():
    schemaContext = ECSchemaReadContext.CreateContext()
    seedPath = getTestDataPath("")
    schemaContext.AddSchemaPath (seedPath.GetWCharCP ())

    schemaXMLFile = getTestDataPath ("ECSeedData/CircleSchema.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    assert (False == (eSCHEMA_READ_STATUS_Success == status))
    EXPECT_FALSE(None != schema)


def test_ExpectSuccessWithSpecialCaseOpenPlantSchema ():
    schemaContext = ECSchemaReadContext.CreateContext()
    seedPath = getTestDataPath ("")
    schemaContext.AddSchemaPath (seedPath.GetWCharCP ())

    schemaXMLFile = getTestDataPath ("ECSeedData/OpenPlant_Supplemental_Mapping_OPPID.01.01.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)

    refList = schema.GetReferencedSchemas()
    EXPECT_EQ(1, refList.__len__ ())

    refSchemaIte = iter (refList)
    refSchema = next (refSchemaIte)
    value = refList.__getitem__ (refSchema)
    EXPECT_EQ(0, value.GetName().CompareTo("Bentley_Standard_CustomAttributes"))


def test_ExpectSchemaGraphInCorrectOrder ():
    schemaContext = ECSchemaReadContext.CreateContext()
    seedPath = getTestDataPath ("")
    schemaContext.AddSchemaPath(seedPath.GetWCharCP ())

    schemaXMLFile = getTestDataPath ("ECSeedData/Bentley_Plant.06.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)

    schemasToImport = ECSchemaPArray ()
    schema.FindAllSchemasInGraph (schemasToImport, True)

    expectedPrefixes = []
    expectedPrefixes.append ("bsca")
    expectedPrefixes.append ("iipmdbca")
    expectedPrefixes.append ("rdlca")
    expectedPrefixes.append ("beca")
    expectedPrefixes.append ("bsm")
    expectedPrefixes.append ("bjca")
    expectedPrefixes.append ("jclass")
    expectedPrefixes.append ("dmd")
    expectedPrefixes.append ("stepmd")
    expectedPrefixes.append ("bjeca")
    expectedPrefixes.append ("bpca")
    expectedPrefixes.append ("bp")

    EXPECT_EQ(schemasToImport.__len__(), expectedPrefixes.__len__())

    counter = 0
    for testSchema in schemasToImport:
        prefix = testSchema.GetNamespacePrefix ()
        expectedPrefix = expectedPrefixes[counter]
        EXPECT_EQ(0, prefix.CompareTo(expectedPrefix))

        if (0 != prefix.CompareTo(expectedPrefix)):
            print ("Expected " + expectedPrefix + " Actual " + prefix)
        counter += 1

def test_EnsureSchemaContextIntegrity ():
    schemaContext = ECSchemaReadContext.CreateContext()

    status, r1 = ECSchema.ReadFromXmlString (
        WString ("<?xml version='1.0' encoding='UTF-8'?>"
        "<ECSchema schemaName='R1' version='01.00' nameSpacePrefix='r1' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>"
        "    <ECClass typeName='R1C1'>"
        "       <ECProperty propertyName='s1' typeName='string'  />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if eSCHEMA_READ_STATUS_Success != status :
        print ("Failed to read R1 from string")

    status, r2 = ECSchema.ReadFromXmlString (
        WString ("<?xml version='1.0' encoding='UTF-8'?>"
        "<ECSchema schemaName='R2' version='01.00' nameSpacePrefix='r2' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>"
        "    <ECClass typeName='R2C1'>"
        "       <ECProperty propertyName='s2' typeName='string'  />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if eSCHEMA_READ_STATUS_Success != status :
        print ("Failed to read R2 from string")

    status, r3 = ECSchema.ReadFromXmlString (
        WString ("<?xml version='1.0' encoding='UTF-8'?>"
        "<ECSchema schemaName='R3' version='01.00' nameSpacePrefix='r3' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>"
        "    <ECClass typeName='R3C1'>"
        "       <ECProperty propertyName='s3' typeName='string'  />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if eSCHEMA_READ_STATUS_Success != status :
        print ("Failed to read R3 from string")

    status, schemaA = ECSchema.ReadFromXmlString (
        WString ("<?xml version='1.0' encoding='UTF-8'?>"
        "<ECSchema schemaName='SchemaA' version='01.00' nameSpacePrefix='a' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>"
        "<ECSchemaReference name='R1' version='01.00' prefix='r1' />"
        "<ECSchemaReference name='R2' version='01.00' prefix='r2' />"
        "    <ECClass typeName='c'>"
        "       <ECProperty      propertyName='p1' typeName='int'  />"
        "       <ECArrayProperty propertyName='q1' typeName='double' minOccurs='0' maxOccurs='unbounded'/>"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if eSCHEMA_READ_STATUS_Success != status :
        print ("Failed to read SchemaA from string")

    status, schemaB = ECSchema.ReadFromXmlString (
        WString ("<?xml version='1.0' encoding='UTF-8'?>"
        "<ECSchema schemaName='SchemaB' version='01.00' nameSpacePrefix='b' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>"
        "<ECSchemaReference name='R2' version='01.00' prefix='r2' />"
        "<ECSchemaReference name='R3' version='01.00' prefix='r3' />"
        "    <ECClass typeName='c2'>"
        "       <ECProperty      propertyName='p2' typeName='int'  />"
        "    </ECClass>"
        "</ECSchema>").GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if eSCHEMA_READ_STATUS_Success != status :
        print ("Failed to read SchemaB from string")

    status2 = r1.WriteToXmlFile (getTempDataPath ("r1.01.00.ecschema.xml").GetWCharCP ())
    EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
    if SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success != status2 :
        print ("Failed to write r1 to file")

    status2 = r2.WriteToXmlFile (getTempDataPath ("r2.01.00.ecschema.xml").GetWCharCP ())
    EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
    if SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success != status2 :
        print ("Failed to write r2 to file")

    status2 = r3.WriteToXmlFile(getTempDataPath ("r3.01.00.ecschema.xml").GetWCharCP ())
    EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
    if SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success != status2 :
        print ("Failed to write r3 to file")

    status2 = schemaA.WriteToXmlFile(getTempDataPath ("SchemaA.01.00.ecschema.xml").GetWCharCP ())
    EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
    if SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success != status2 :
        print ("Failed to write SchemaA to file")

    status2 = schemaB.WriteToXmlFile(getTempDataPath ("SchemaB.01.00.ecschema.xml").GetWCharCP ())
    EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, status2)
    if SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success != status2 :
        print ("Failed to write SchemaB to file")

    schemaContext2 = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTempDataPath ("SchemaA.01.00.ecschema.xml")
    status, schemaA2 = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext2)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if (eSCHEMA_READ_STATUS_Success != status):
        print ("Failed to read SchemaA from file")

    schemaXMLFile = getTempDataPath ("SchemaB.01.00.ecschema.xml")
    status, schemaB2 = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext2)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)
    if (eSCHEMA_READ_STATUS_Success != status):
        print ("Failed to read SchemaB from file")

    schemaXMLFile = getTempDataPath ("r3.01.00.ecschema.xml")
    status, ref3 = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext2)
    EXPECT_EQ (SchemaReadStatus.eSCHEMA_READ_STATUS_DuplicateSchema, status)
    if (SchemaReadStatus.eSCHEMA_READ_STATUS_DuplicateSchema != status):
        print ("Failed to read r3 from file")

def find_dot (a):  
    for i in range(len(a)):  
        if ord(a[i]) == ord('.'):  
            return i  
    return -1 

def test_ExpectSuccessWhenLocatingStandardSchema ():
    schemaContext = ECSchemaReadContext.CreateContext()

    standardSchemaNames = {}
    standardSchemaNames["Bentley_Standard_CustomAttributes"] = "01.04"
    standardSchemaNames["Bentley_Standard_Classes"] = "01.00"
    standardSchemaNames["Bentley_ECSchemaMap"] = "01.00"
    standardSchemaNames["EditorCustomAttributes"] = "01.00"
    standardSchemaNames["Bentley_Common_Classes"] = "01.00"
    standardSchemaNames["Dimension_Schema"] = "01.00"
    standardSchemaNames["iip_mdb_customAttributes"] = "01.00"
    standardSchemaNames["KindOfQuantity_Schema"] = "01.01"
    standardSchemaNames["rdl_customAttributes"] = "01.00"
    standardSchemaNames["SIUnitSystemDefaults"] = "01.00"
    standardSchemaNames["Unit_Attributes"] = "01.00"
    standardSchemaNames["Units_Schema"] = "01.00"
    standardSchemaNames["USCustomaryUnitSystemDefaults"] = "01.00"

    for key, value in standardSchemaNames.items () :
       schemaKey = SchemaKey (key, 1, 0)
       retVal, schemaKey.versionMajor, schemaKey.versionMinor = ECSchema.ParseVersionString (value)
       EXPECT_TRUE(retVal == ECObjectsStatus.eECOBJECTS_STATUS_Success)

       dotPos = find_dot (value)
       EXPECT_EQ(schemaKey.versionMajor, int(value[:dotPos]))   
       EXPECT_EQ(schemaKey.versionMinor, int(value[(dotPos+1):]))

       schema = ECSchema.LocateSchema(schemaKey, schemaContext)
       EXPECT_TRUE(None != schema)
       EXPECT_TRUE(schema.IsStandardSchema())
       EXPECT_STREQ(WString (value), ECSchema.FormatSchemaVersion(schemaKey.versionMajor, schemaKey.versionMinor))


def test_ExpectFailureWithNonStandardSchema ():
    retVal, testSchema = ECSchema.CreateSchema (WString ("TestSchema"), 1, 2)
    EXPECT_FALSE (testSchema.IsStandardSchema())

def test_DetermineWhetherSchemaCanBeImported ():
    schemaContext = ECSchemaReadContext.CreateContext()
    key = SchemaKey("Bentley_Standard_CustomAttributes", 1, 4)
    
    schema = ECSchema.LocateSchema(key, schemaContext)
    EXPECT_TRUE(None != schema)
    EXPECT_FALSE(schema.ShouldNotBeStored())

    retVal, schema = ECSchema.CreateSchema (WString ("Units_Schema"), 1, 4)
    EXPECT_TRUE(schema.ShouldNotBeStored())


def test_CanFullyCreateASchema ():
    retVal, testSchema = ECSchema.CreateSchema (WString ("TestSchema"), 1, 2)
    testSchema.SetNamespacePrefix (WString ("ts"))
    testSchema.SetDescription (WString ("Schema for testing programmatic construction"))
    testSchema.SetDisplayLabel (WString ("Test Schema"))
    
    EXPECT_TRUE(testSchema.GetIsDisplayLabelDefined())
    EXPECT_EQ(1, testSchema.GetVersionMajor())
    EXPECT_EQ(2, testSchema.GetVersionMinor())
    EXPECT_EQ(testSchema.GetName(), WString ("TestSchema"))
    EXPECT_EQ(testSchema.GetNamespacePrefix(), WString ("ts"))
    EXPECT_EQ(testSchema.GetDescription(), WString ("Schema for testing programmatic construction"))
    EXPECT_EQ(testSchema.GetDisplayLabel(), WString ("Test Schema"))

    retVal, schema2 = ECSchema.CreateSchema (WString ("BaseSchema"), 5, 5)

    testSchema.AddReferencedSchema(schema2)

    retVal, class1 = testSchema.CreateClass (WString ("TestClass"))
    retVal, structClass = testSchema.CreateClass (WString ("StructClass"))
    retVal, baseClass = schema2.CreateClass (WString ("BaseClass"))
    retVal, relatedClass = testSchema.CreateClass (WString ("RelatedClass"))

    class1.SetDescription (WString ("Class for testing purposes"))
    class1.SetDisplayLabel (WString ("Test Class"))

    EXPECT_EQ(class1.GetDescription(), WString ("Class for testing purposes"))
    EXPECT_EQ(class1.GetDisplayLabel(), WString ("Test Class"))
    EXPECT_FALSE(class1.GetIsStruct())
    EXPECT_FALSE(class1.GetIsCustomAttributeClass())
    EXPECT_TRUE(class1.GetIsDomainClass())
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.AddBaseClass(baseClass))
    EXPECT_TRUE(class1.HasBaseClasses())

    structClass.SetIsStruct(True)
    EXPECT_TRUE(structClass.GetIsStruct())
    EXPECT_TRUE(structClass.GetIsDomainClass())

    retVal, stringProp = class1.CreatePrimitiveProperty (WString ("StringMember"))
    retVal, structProp = class1.CreateStructProperty (WString ("StructMember"))
    retVal, nestedArrayProp = class1.CreateArrayProperty (WString ("NestedArray"))
    retVal, primitiveArrayProp = class1.CreateArrayProperty (WString ("PrimitiveArray"))

    structProp.SetType(structClass)
    nestedArrayProp.SetStructElementType(structClass)
    primitiveArrayProp.SetPrimitiveElementType (PrimitiveType.ePRIMITIVETYPE_Long)
    primitiveArrayProp.SetMinOccurs(1)
    primitiveArrayProp.SetMaxOccurs(10)
    
    EXPECT_TRUE(ArrayKind.eARRAYKIND_Struct == nestedArrayProp.GetKind())
    EXPECT_TRUE(ArrayKind.eARRAYKIND_Primitive == primitiveArrayProp.GetKind())
    EXPECT_EQ(0, nestedArrayProp.GetMinOccurs())
    EXPECT_EQ(UINT_MAX, nestedArrayProp.GetMaxOccurs())
    EXPECT_EQ(1, primitiveArrayProp.GetMinOccurs())
#if FIXED_COUNT_ARRAYS_ARE_SUPPORTED
    #EXPECT_EQ(10, primitiveArrayProp.GetMaxOccurs())
#else
    EXPECT_EQ(UINT_MAX, primitiveArrayProp.GetMaxOccurs())
#endif
    EXPECT_TRUE(stringProp.GetIsPrimitive())
    EXPECT_FALSE(stringProp.GetIsStruct())
    EXPECT_FALSE(stringProp.GetIsArray())
    
    EXPECT_FALSE(structProp.GetIsPrimitive())
    EXPECT_TRUE(structProp.GetIsStruct())
    EXPECT_FALSE(structProp.GetIsArray())
    
    EXPECT_FALSE(primitiveArrayProp.GetIsPrimitive())
    EXPECT_FALSE(primitiveArrayProp.GetIsStruct())
    EXPECT_TRUE(primitiveArrayProp.GetIsArray())

    EXPECT_FALSE(stringProp.GetIsReadOnly())

    EXPECT_EQ(stringProp.GetTypeName(), WString ("string"))
    EXPECT_TRUE(ePRIMITIVETYPE_String == stringProp.GetType())
    EXPECT_EQ(structProp.GetType().GetName(), WString ("StructClass"))

    retVal, binaryProperty = class1.CreatePrimitiveProperty (WString ("BinaryProp"))
    retVal, booleanProperty = class1.CreatePrimitiveProperty (WString ("BooleanProp"))
    retVal, dateTimeProperty = class1.CreatePrimitiveProperty (WString ("DateTimeProp"))
    retVal, doubleProperty = class1.CreatePrimitiveProperty (WString ("DoubleProp"))
    retVal, integerProperty = class1.CreatePrimitiveProperty (WString ("IntProp"))
    retVal, longProperty = class1.CreatePrimitiveProperty (WString ("LongProp"))
    retVal, point2DProperty = class1.CreatePrimitiveProperty (WString ("Point2DProp"))
    retVal, point3DProperty = class1.CreatePrimitiveProperty (WString ("Point3DProp"))

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_ParseError, binaryProperty.SetTypeName (WString ("fake")))

    binaryProperty.SetTypeName (WString ("binary"))
    booleanProperty.SetTypeName (WString ("boolean"))
    dateTimeProperty.SetTypeName (WString ("dateTime"))
    doubleProperty.SetTypeName (WString ("double"))
    integerProperty.SetTypeName (WString ("int"))
    longProperty.SetTypeName (WString ("long"))
    point2DProperty.SetTypeName (WString ("point2d"))
    point3DProperty.SetTypeName (WString ("point3d"))
    
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Binary == binaryProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Boolean == booleanProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_DateTime == dateTimeProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Double == doubleProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Integer == integerProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Long == longProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Point2D == point2DProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Point3D == point3DProperty.GetType())

    retVal, binaryProperty = class1.CreatePrimitiveProperty (WString ("BinaryProp2"), PrimitiveType.ePRIMITIVETYPE_Binary)
    retVal, booleanProperty = class1.CreatePrimitiveProperty (WString ("BooleanProp2"), PrimitiveType.ePRIMITIVETYPE_Boolean)
    retVal, dateTimeProperty = class1.CreatePrimitiveProperty (WString ("DateTimeProp2"), PrimitiveType.ePRIMITIVETYPE_DateTime)
    retVal, doubleProperty = class1.CreatePrimitiveProperty (WString ("DoubleProp2"), PrimitiveType.ePRIMITIVETYPE_Double)
    retVal, integerProperty = class1.CreatePrimitiveProperty (WString ("IntProp2"), PrimitiveType.ePRIMITIVETYPE_Integer)
    retVal, longProperty = class1.CreatePrimitiveProperty (WString ("LongProp2"), PrimitiveType.ePRIMITIVETYPE_Long)
    retVal, point2DProperty = class1.CreatePrimitiveProperty (WString ("Point2DProp2"), PrimitiveType.ePRIMITIVETYPE_Point2D)
    retVal, point3DProperty = class1.CreatePrimitiveProperty (WString ("Point3DProp2"), PrimitiveType.ePRIMITIVETYPE_Point3D)

    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Binary == binaryProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Boolean == booleanProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_DateTime == dateTimeProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Double == doubleProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Integer == integerProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Long == longProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Point2D == point2DProperty.GetType())
    EXPECT_TRUE(PrimitiveType.ePRIMITIVETYPE_Point3D == point3DProperty.GetType())

    retVal, structProp = class1.CreateStructProperty (WString ("StructMember2"), structClass)
    retVal, nestedArrayProp = class1.CreateArrayProperty (WString ("NestedArray2"), structClass)
    retVal, primitiveArrayProp = class1.CreateArrayProperty (WString ("PrimitiveArray2"), PrimitiveType.ePRIMITIVETYPE_Integer)
    EXPECT_TRUE(ArrayKind.eARRAYKIND_Struct == nestedArrayProp.GetKind())
    EXPECT_TRUE(ArrayKind.eARRAYKIND_Primitive == primitiveArrayProp.GetKind())
    EXPECT_EQ(structProp.GetType().GetName(), WString ("StructClass"))
    EXPECT_EQ(nestedArrayProp.GetTypeName(), WString ("StructClass"))
    EXPECT_EQ(primitiveArrayProp.GetTypeName(), WString ("int"))

    retVal, relationshipClass = testSchema.CreateRelationshipClass (WString ("RelationshipClass"))
    EXPECT_TRUE(eSTRENGTHTYPE_Referencing == relationshipClass.GetStrength())
    relationshipClass.SetStrength(StrengthType.eSTRENGTHTYPE_Embedding)
    EXPECT_TRUE(StrengthType.eSTRENGTHTYPE_Embedding == relationshipClass.GetStrength())

    EXPECT_TRUE(ECRelatedInstanceDirection.eSTRENGTHDIRECTION_Forward == relationshipClass.GetStrengthDirection())
    relationshipClass.SetStrengthDirection(ECRelatedInstanceDirection.eSTRENGTHDIRECTION_Backward)
    EXPECT_TRUE(ECRelatedInstanceDirection.eSTRENGTHDIRECTION_Backward == relationshipClass.GetStrengthDirection())

    EXPECT_TRUE(relationshipClass.GetTarget().GetIsMultiple())
    EXPECT_TRUE(relationshipClass.GetSource().GetIsMultiple())

    EXPECT_TRUE(relationshipClass.GetSource().GetIsPolymorphic())
    relationshipClass.GetSource().SetIsPolymorphic(False)
    EXPECT_FALSE(relationshipClass.GetSource().GetIsPolymorphic())

    relationshipClass.SetDescription (WString ("Relates the test class to the related class"))
    relationshipClass.SetDisplayLabel (WString ("TestRelationshipClass"))

    EXPECT_EQ(0, relationshipClass.GetSource().GetClasses().__len__()) 
    EXPECT_EQ(0, relationshipClass.GetTarget().GetClasses().__len__())

    relationshipClass.GetSource().AddClass(structClass)
    EXPECT_EQ(1, relationshipClass.GetSource().GetClasses().__len__())
    relationshipClass.GetSource().AddClass(class1)
    EXPECT_EQ(2, relationshipClass.GetSource().GetClasses().__len__())

    relationshipClass.GetTarget().AddClass(relatedClass)
    EXPECT_EQ(1, relationshipClass.GetTarget().GetClasses().__len__())
    relationshipClass.GetTarget().AddClass(relatedClass)
    EXPECT_EQ(1, relationshipClass.GetTarget().GetClasses().__len__())
    relationshipClass.GetTarget().AddClass(structClass)
    EXPECT_EQ(2, relationshipClass.GetTarget().GetClasses().__len__())

    EXPECT_EQ(0, relationshipClass.GetSource().GetCardinality().GetLowerLimit())
    EXPECT_EQ(0, relationshipClass.GetTarget().GetCardinality().GetLowerLimit())
    EXPECT_EQ(1, relationshipClass.GetSource().GetCardinality().GetUpperLimit())
    EXPECT_EQ(1, relationshipClass.GetTarget().GetCardinality().GetUpperLimit())

    relationshipClass.GetSource().SetCardinality(RelationshipCardinality.OneMany())
    EXPECT_EQ(1, relationshipClass.GetSource().GetCardinality().GetLowerLimit())
    EXPECT_TRUE(relationshipClass.GetSource().GetCardinality().IsUpperLimitUnbounded())
    
    card = RelationshipCardinality(2, 5)
    relationshipClass.GetTarget().SetCardinality(card)
    EXPECT_EQ(2, relationshipClass.GetTarget().GetCardinality().GetLowerLimit())
    EXPECT_EQ(5, relationshipClass.GetTarget().GetCardinality().GetUpperLimit())


def test_ExpectSuccessWhenCopyingStructs ():
    schemaContext = ECSchemaReadContext.CreateContext()

    schemaXMLFile = getTestDataPath ("ECSeedData/Widgets.01.00.ecschema.xml")
    status, schema = ECSchema.ReadFromXmlFile (schemaXMLFile.GetWCharCP (), schemaContext)
    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)

    status2, copiedSchema = schema.CopySchema()
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, status2)


def test_ExpectErrorWithCircularBaseClasses ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, baseClass1 = schema.CreateClass (WString ("BaseClass1"))
    retVal, baseClass2 = schema.CreateClass (WString ("BaseClass2"))

    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.AddBaseClass(baseClass1))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, baseClass1.AddBaseClass(baseClass2))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_BaseClassUnacceptable, baseClass2.AddBaseClass(class1))


def test_GetPropertyCount ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 1, 0)

    # Struct class with 2 properties
    retVal, structClass = schema.CreateClass (WString ("StructClass"))
    structClass.SetIsStruct (True)
    retVal, primProp = structClass.CreatePrimitiveProperty (WString ("StructProp1"))
    retVal, primProp = structClass.CreatePrimitiveProperty (WString ("StructProp2"))

    # 1 base class with 3 primitive properties
    retVal, baseClass1 = schema.CreateClass (WString ("BaseClass1"))
    retVal, primProp = baseClass1.CreatePrimitiveProperty (WString ("Base1Prop1"))
    retVal, primProp = baseClass1.CreatePrimitiveProperty (WString ("Base1Prop2"))
    retVal, primProp = baseClass1.CreatePrimitiveProperty (WString ("Base1Prop3"))

    # 1 base class with 1 primitive and 2 struct properties (each struct has 2 properties
    retVal, baseClass2 = schema.CreateClass (WString ("BaseClass2"))
    retVal, primProp = baseClass2.CreatePrimitiveProperty (WString ("Base2Prop1"))
    retVal, structProp = baseClass2.CreateStructProperty (WString ("Base2Prop2"), structClass)
    retVal, structProp = baseClass2.CreateStructProperty (WString ("Base2Prop3"), structClass)

    # Derived class with 1 extra primitive property, 1 extra struct property, derived from 2 base classes
    retVal, derivedClass = schema.CreateClass (WString ("DerivedClass"))
    retVal, structProp = derivedClass.CreateStructProperty (WString ("DerivedProp1"), structClass)
    retVal, primProp = derivedClass.CreatePrimitiveProperty (WString ("DerivedProp2"))
    derivedClass.AddBaseClass (baseClass1)
    derivedClass.AddBaseClass (baseClass2)

    checkPropertyCount (structClass, 2, 2)
    checkPropertyCount (baseClass1, 3, 3)
    checkPropertyCount (baseClass2, 3, 3)
    checkPropertyCount (derivedClass, 2, 8)


def IsClassInList (classList, searchClass):
    for classIterator in classList:
        if classIterator == searchClass:
           return True
        
    return False


def test_AddAndRemoveBaseClass ():
   retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
   retVal, class1 = schema.CreateClass (WString ("TestClass"))
   retVal, baseClass1 = schema.CreateClass (WString ("BaseClass"))

   EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.AddBaseClass(baseClass1))

   assert (True == IsClassInList (class1.GetBaseClasses(), baseClass1))
   assert (True == IsClassInList (baseClass1.GetDerivedClasses(), class1))

   EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.RemoveBaseClass(baseClass1))

   assert (False == IsClassInList (class1.GetBaseClasses(), baseClass1))
   assert (False == IsClassInList (baseClass1.GetDerivedClasses(), class1))

   EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_ClassNotFound, class1.RemoveBaseClass(baseClass1))


def test_AddBaseClassWithProperties ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, baseClass1 = schema.CreateClass (WString ("BaseClass"))
    retVal, baseClass2 = schema.CreateClass (WString ("BaseClass2"))

    retVal, stringProp = class1.CreatePrimitiveProperty (WString ("StringProperty"), ePRIMITIVETYPE_String)
    retVal, baseStringProp = baseClass1.CreatePrimitiveProperty (WString ("StringProperty"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, class1.AddBaseClass(baseClass1))

    retVal, intProp = class1.CreatePrimitiveProperty (WString ("IntProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    retVal, base2NonIntProp = baseClass2.CreatePrimitiveProperty (WString ("IntProperty"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, class1.AddBaseClass(baseClass2))


def test_IsTests ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, baseClass1 = schema.CreateClass (WString ("BaseClass1"))
    retVal, baseClass2 = schema.CreateClass (WString ("BaseClass2"))
    
    EXPECT_FALSE(class1.Is(baseClass1))
    class1.AddBaseClass(baseClass1)
    EXPECT_TRUE(class1.Is(baseClass1))

def test_CanOverrideBaseProperties ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, baseClass1 = schema.CreateClass (WString ("BaseClass1"))
    retVal, structClass = schema.CreateClass (WString ("ClassForStructs"))
    structClass.SetIsStruct(True)
    retVal, structClass2 = schema.CreateClass (WString ("ClassForStructs2"))
    structClass2.SetIsStruct(True)
    class1.AddBaseClass(baseClass1)

    retVal, baseStringProp = baseClass1.CreatePrimitiveProperty (WString ("StringProperty"), ePRIMITIVETYPE_String)
    retVal, baseIntProp = baseClass1.CreatePrimitiveProperty (WString ("IntegerProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    retVal, baseDoubleProp = baseClass1.CreatePrimitiveProperty (WString ("DoubleProperty"), PrimitiveType.ePRIMITIVETYPE_Double)
    retVal, baseStructProp = baseClass1.CreateStructProperty (WString ("StructProperty"), structClass)
    retVal, baseStringArrayProperty = baseClass1.CreateArrayProperty (WString ("StringArrayProperty"), ePRIMITIVETYPE_String)
    retVal, baseStructProperty = baseClass1.CreateArrayProperty (WString ("StructArrayProperty"), structClass)

    #DISABLE_ASSERTS;
    assertDisabler = AssertDisabler ()
    # Primitives overriding primitives
    retVal, longProperty = class1.CreatePrimitiveProperty (WString ("StringProperty"), PrimitiveType.ePRIMITIVETYPE_Long)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)
    EXPECT_EQ(None, longProperty)

    retVal, stringProperty = class1.CreatePrimitiveProperty (WString ("StringProperty"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)
    EXPECT_EQ(baseStringProp, stringProperty.GetBaseProperty())
    class1.RemoveProperty (WString ("StringProperty"))

    # Primitives overriding structs
    #DISABLE_ASSERTS
    with AssertDisabler () as assertDisabler1:
        retVal, longProperty = class1.CreatePrimitiveProperty (WString ("StructProperty"), ePRIMITIVETYPE_Long)
        EXPECT_EQ(eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # Primitives overriding arrays
    retVal, longProperty = class1.CreatePrimitiveProperty (WString ("StringArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Long)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, stringProperty = class1.CreatePrimitiveProperty (WString ("StringArrayProperty"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)
    class1.RemoveProperty (WString ("StringArrayProperty"))

    # Structs overriding primitives
    #DISABLE_ASSERTS
    with AssertDisabler () as assertDisabler2:
        retVal, structProperty = class1.CreateStructProperty (WString ("IntegerProperty"))
        EXPECT_EQ(eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # Structs overriding structs
    # If we don't specify a struct type for the new property, then it should succeed
    retVal, structProperty = class1.CreateStructProperty (WString ("StructProperty"))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)
    class1.RemoveProperty (WString ("StructProperty"))

    retVal, structProperty = class1.CreateStructProperty (WString ("StructProperty"), structClass2)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # Structs overriding arrays
    retVal, structProperty = class1.CreateStructProperty (WString ("StringArrayProperty"))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, structProperty = class1.CreateStructProperty (WString ("StringArrayProperty"), structClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, structProperty = class1.CreateStructProperty (WString ("StructArrayProperty"))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, structProperty = class1.CreateStructProperty (WString ("StructArrayProperty"), structClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, structProperty = class1.CreateStructProperty (WString ("StructArrayProperty"), structClass2)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # Arrays overriding primitives
    retVal, stringArrayProperty = class1.CreateArrayProperty (WString ("IntegerProperty"), PrimitiveType.ePRIMITIVETYPE_Long)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, stringArrayProperty = class1.CreateArrayProperty (WString ("StringProperty"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, stringArrayProperty2 = class1.CreateArrayProperty (WString ("StringProperty"))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # Arrays overriding structs
    retVal, structArrayProperty = class1.CreateArrayProperty (WString("StructProperty"), structClass2)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, structArrayProperty = class1.CreateArrayProperty (WString ("StructProperty"), structClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # the default array type is string if none is passed in
    retVal, structArrayProperty2 = class1.CreateArrayProperty (WString ("StructProperty"))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    # Arrays overriding arrays
    retVal, intArrayProperty = class1.CreateArrayProperty (WString ("StringArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Long)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, retVal)

    retVal, stringArrayProperty = class1.CreateArrayProperty (WString ("StringArrayProperty"), ePRIMITIVETYPE_String)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)
    class1.RemoveProperty (WString ("StringArrayProperty"))

    # StructArrays overriding struct arrays
    retVal, structArrayProperty2 = class1.CreateArrayProperty (WString ("StructArrayProperty"), structClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)


def test_AddAndRemoveBaseProperties ():
    retVal, schema = ECSchema.CreateSchema (WString ("Test"), 1, 1)
    retVal, base = schema.CreateClass (WString ("Base"))

    retVal, basePropA = base.CreatePrimitiveProperty (WString ("A"))
    retVal, derived = schema.CreateClass (WString ("Derived"))
    derived.AddBaseClass (base)

    retVal, derivedPropA = derived.CreatePrimitiveProperty (WString ("A"))
    retVal, derivedPropB = derived.CreatePrimitiveProperty (WString ("B"))

    EXPECT_EQ (basePropA, derivedPropA.GetBaseProperty())
    EXPECT_EQ (None, derivedPropB.GetBaseProperty())

    retVal, basePropB = base.CreatePrimitiveProperty (WString ("B"))
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)
    EXPECT_EQ (basePropB, derivedPropB.GetBaseProperty())

    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, base.RemoveProperty (WString ("A")))
    EXPECT_EQ (None, derivedPropA.GetBaseProperty())


def test_AddAndRemoveInheritedBaseProperties ():
    retVal, schema = ECSchema.CreateSchema (WString ("Test"), 1, 2)
    retVal, base = schema.CreateClass (WString ("Base"))

    retVal, baseA = base.CreatePrimitiveProperty (WString  ("A"))
    retVal, baseB = base.CreatePrimitiveProperty (WString  ("B"))
    
    retVal, intermediate = schema.CreateClass (WString ("Intermediate"))
    intermediate.AddBaseClass (base)

    retVal, intermediateA = intermediate.CreatePrimitiveProperty (WString  ("A"))

    retVal, derived = schema.CreateClass (WString ("Derived"))
    derived.AddBaseClass (intermediate)

    retVal, derivedA = derived.CreatePrimitiveProperty (WString  ("A"))
    retVal, derivedB = derived.CreatePrimitiveProperty (WString  ("B"))

    # Intermediate.A overrides Base.A
    # Derived.A overrides Intermediate.A
    # Derived.B overrides Base.B
    EXPECT_EQ (baseA, intermediateA.GetBaseProperty())
    EXPECT_EQ (intermediateA, derivedA.GetBaseProperty())
    EXPECT_EQ (baseB, derivedB.GetBaseProperty())

    # Remove intermediate A => Derived.A now overrides Base.A
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, intermediate.RemoveProperty (WString ("A")))
    EXPECT_EQ (baseA, derivedA.GetBaseProperty())

    # Add an intermediate B => Derived.B now overrides that instead of Base.A
    retVal, intermediateB = intermediate.CreatePrimitiveProperty (WString ("B"))
    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)
    EXPECT_EQ (intermediateB, derivedB.GetBaseProperty())


def test_AndAddRemoveBaseClassesWithOverridableProperties ():
    retVal, schema = ECSchema.CreateSchema (WString ("Test"), 1, 3)

    retVal, hasA = schema.CreateClass (WString ("HasA"))
    retVal, hasB = schema.CreateClass (WString ("HasB"))

    retVal, baseA = hasA.CreatePrimitiveProperty (WString  ("A"))
    retVal, baseB = hasB.CreatePrimitiveProperty (WString  ("B"))

    retVal, derived = schema.CreateClass (WString ("Derived"))

    retVal, derivedA = derived.CreatePrimitiveProperty (WString  ("A"))
    retVal, derivedB = derived.CreatePrimitiveProperty (WString  ("B"))

    derived.AddBaseClass (hasA)
    derived.AddBaseClass (hasB)

    EXPECT_EQ (baseA, derivedA.GetBaseProperty())
    EXPECT_EQ (baseB, derivedB.GetBaseProperty())

    EXPECT_EQ (ECObjectsStatus.eECOBJECTS_STATUS_Success, derived.RemoveBaseClass (hasB))
    EXPECT_EQ (baseA, derivedA.GetBaseProperty())
    EXPECT_EQ (None, derivedB.GetBaseProperty())


def test_ExpectFailureWhenStructTypeIsNotReferenced ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, schema2 = ECSchema.CreateSchema (WString ("TestSchema2"), 5, 5)
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, structClass = schema2.CreateClass (WString ("ClassForStructs"))
    structClass.SetIsStruct(True)
    retVal, structClass2 = schema.CreateClass (WString ("ClassForStructs2"))
    structClass2.SetIsStruct(True)

    retVal, baseStructProp = class1.CreateStructProperty (WString ("StructProperty"), structClass)
    EXPECT_EQ(eECOBJECTS_STATUS_SchemaNotFound, retVal)

    retVal, structArrayProperty = class1.CreateArrayProperty (WString("StructArrayProperty"), structClass)
    EXPECT_EQ(eECOBJECTS_STATUS_SchemaNotFound, retVal)

    retVal, baseStructProp2 = class1.CreateStructProperty (WString ("StructProperty2"), structClass2)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)

    retVal, structArrayProperty2 = class1.CreateArrayProperty (WString ("StructArrayProperty2"), structClass2)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)
    schema.AddReferencedSchema(schema2)

    retVal, baseStructProp = class1.CreateStructProperty (WString ("StructProperty"), structClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)

    retVal, structArrayProperty = class1.CreateArrayProperty (WString ("StructArrayProperty"), structClass)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, retVal)


def test_ExpectPropertiesInOrder ():
    propertyNames = WStringArray ()
    propertyNames.append (WString ("beta"))
    propertyNames.append (WString ("gamma"))
    propertyNames.append (WString ("delta"))
    propertyNames.append (WString ("alpha"))
  
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, class1 = schema.CreateClass (WString ("TestClass"))
    retVal, property1 = class1.CreatePrimitiveProperty (WString ("beta"))
    retVal, property2 = class1.CreatePrimitiveProperty (WString ("gamma"))
    retVal, property3 = class1.CreatePrimitiveProperty (WString ("delta"))
    retVal, property4 = class1.CreatePrimitiveProperty (WString ("alpha"))    

    i = 0
    iterable = class1.GetProperties (False)
    for prop in iterable:
        EXPECT_EQ (0, prop.GetName().CompareTo (propertyNames[i]))
        i += 1


def test_ExpectProperties ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, ab = schema.CreateClass (WString ("ab"))
    retVal, cd = schema.CreateClass (WString ("cd"))
    retVal, ef = schema.CreateClass (WString ("ef"))

    retVal, a = ab.CreatePrimitiveProperty (WString ("a"))
    retVal, b = ab.CreatePrimitiveProperty (WString ("b"))
              
    retVal, c = cd.CreatePrimitiveProperty (WString ("c"))
    retVal, d = cd.CreatePrimitiveProperty (WString ("d"))
              
    retVal, e = ef.CreatePrimitiveProperty (WString ("e"))
    retVal, f = ef.CreatePrimitiveProperty (WString ("f"))
    
    cd.AddBaseClass(ab)
    ef.AddBaseClass(cd)

    EXPECT_TRUE(None != getPropertyByName (ef, "e"))
    EXPECT_TRUE(None != getPropertyByName (ef, "c"))
    EXPECT_TRUE(None != getPropertyByName (ef, "a"))

def test_ExpectPropertiesFromBaseClass ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, ab = schema.CreateClass (WString ("ab"))
    retVal, cd = schema.CreateClass (WString ("cd"))
    retVal, ef = schema.CreateClass (WString ("ef"))
    retVal, gh = schema.CreateClass (WString ("gh"))
    retVal, ij = schema.CreateClass (WString ("ij"))
    retVal, kl = schema.CreateClass (WString ("kl"))
    retVal, mn = schema.CreateClass (WString ("mn"))

    retVal, a = ab.CreatePrimitiveProperty (WString ("a"))
    retVal, b = ab.CreatePrimitiveProperty (WString ("b"))
    retVal, c = cd.CreatePrimitiveProperty (WString ("c"))
    retVal, d = cd.CreatePrimitiveProperty (WString ("d"))
    retVal, e = ef.CreatePrimitiveProperty (WString ("e"))
    retVal, f = ef.CreatePrimitiveProperty (WString ("f"))
    retVal, g = gh.CreatePrimitiveProperty (WString ("g"))
    retVal, h = gh.CreatePrimitiveProperty (WString ("h"))
    retVal, i = ij.CreatePrimitiveProperty (WString ("i"))
    retVal, j = ij.CreatePrimitiveProperty (WString ("j"))
    retVal, k = kl.CreatePrimitiveProperty (WString ("k"))
    retVal, l = kl.CreatePrimitiveProperty (WString ("l"))
    retVal, m = mn.CreatePrimitiveProperty (WString ("m"))
    retVal, n = mn.CreatePrimitiveProperty (WString ("n"))

    ef.AddBaseClass(ab)
    ef.AddBaseClass(cd)
    kl.AddBaseClass(gh)
    kl.AddBaseClass(ij)
    mn.AddBaseClass(ef)
    mn.AddBaseClass(kl)

    iterable1 = mn.GetProperties (True)
    testVector = []
    for prop in iterable1:
       testVector.append (prop)

    EXPECT_EQ(14, testVector.__len__ ())

    i = 0
    for prop in testVector:
        expectedName = chr(ord('a') + i) + '\0'
        EXPECT_EQ (0, prop.GetName().CompareTo (expectedName))
        if 0 != prop.GetName().CompareTo (expectedName):
            print ("Expected: " + expectedName + "but Actual: " + prop.GetName())
        i += 1
    
    # now we add some duplicate properties to mn which will "override" those from the base classes
    retVal, b2 = mn.CreatePrimitiveProperty (WString ("b"))
    retVal, d2 = mn.CreatePrimitiveProperty (WString ("d"))
    retVal, f2 = mn.CreatePrimitiveProperty (WString ("f"))
    retVal, h2 = mn.CreatePrimitiveProperty (WString ("h"))
    retVal, j2 = mn.CreatePrimitiveProperty (WString ("j"))
    retVal, k2 = mn.CreatePrimitiveProperty (WString ("k"))

    iterable2 = mn.GetProperties (True)
    testVector.clear()
    for prop in iterable2:
       testVector.append (prop)

    EXPECT_EQ(14, testVector.__len__())

    i = 0
    expectedVector = ["a", "c", "e", "g", "i", "l", "m", "n", "b", "d", "f", "h", "j", "k"]
    for prop in testVector:
        EXPECT_EQ (0, prop.GetName().CompareTo (expectedVector[i]))
        if (0 != prop.GetName().CompareTo (expectedVector[i])):
            print ("Expected: " + expectedVector[i] + "but Actual: " + prop.GetName())
        
        i += 1

    retVal, e2 = kl.CreatePrimitiveProperty (WString ("e"))
    retVal, a2 = kl.CreatePrimitiveProperty (WString ("a"))
    retVal, c2 = kl.CreatePrimitiveProperty (WString ("c"))
    retVal, g2 = kl.CreatePrimitiveProperty (WString ("g"))
    retVal, l2 = ef.CreatePrimitiveProperty (WString ("l"))
    retVal, i2 = gh.CreatePrimitiveProperty (WString ("i"))
    retVal, g3 = ij.CreatePrimitiveProperty (WString ("g"))
    retVal, a3 = gh.CreatePrimitiveProperty (WString ("a"))
    retVal, b3 = gh.CreatePrimitiveProperty (WString ("b"))
    retVal, g4 = ab.CreatePrimitiveProperty (WString ("g"))
    retVal, h3 = ab.CreatePrimitiveProperty (WString ("h"))

    iterable3 = mn.GetProperties (True)
    testVector.clear()
    for prop in iterable3:
       testVector.append (prop)
        
    EXPECT_EQ(14, testVector.__len__ ())

    i = 0
    expectedVector = ["a", "g", "c", "e", "l", "i", "m", "n", "b", "d", "f", "h", "j", "k"]
    for prop in testVector:
        if (0 != prop.GetName().CompareTo (expectedVector[i])):
            print ("Expected: " + expectedVector[i] + "but Actual: " + prop.GetName())
        
        i += 1


def test_AddAndRemoveConstraintClasses ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, refSchema = ECSchema.CreateSchema (WString ("RefSchema"), 5, 5)

    retVal, relClass = schema.CreateRelationshipClass (WString ("RElationshipClass"))
    retVal, targetClass = schema.CreateClass (WString ("Target"))
    refretVal, sourceClass = schema.CreateClass (WString ("Source"))
    
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, relClass.GetTarget().AddClass(targetClass))

    #EXPECT_EQ(eECOBJECTS_STATUS_SchemaNotFound, relClass.GetSource().AddClass(sourceClass))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, relClass.GetSource().AddClass(sourceClass))

    schema.AddReferencedSchema(refSchema)
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, relClass.GetSource().AddClass(sourceClass))
    
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, relClass.GetTarget().RemoveClass(targetClass))
    EXPECT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_ClassNotFound, relClass.GetTarget().RemoveClass(targetClass))


def test_ExpectReadOnlyFromBaseClass ():
    retVal, schema = ECSchema.CreateSchema (WString ("TestSchema"), 5, 5)
    retVal, base = schema.CreateClass (WString ("BaseClass"))
    retVal, child = schema.CreateClass (WString ("ChildClass"))

    retVal, readOnlyProp = base.CreatePrimitiveProperty (WString ("readOnlyProp"))
    readOnlyProp.SetIsReadOnly(True)

    ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, child.AddBaseClass(base))

    ecProp = getPropertyByName (child, "readOnlyProp")
    ASSERT_EQ(True, ecProp.GetIsReadOnly())


def checkOverriding (schemaName, majorVersion, allowOverriding):
    retVal, schema = ECSchema.CreateSchema (schemaName, majorVersion, 5)
    retVal, base = schema.CreateClass (WString ("base"))
    retVal, child = schema.CreateClass (WString ("child"))

    retVal, baseIntProp = base.CreatePrimitiveProperty (WString ("IntegerProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    retVal, baseIntArrayProperty = base.CreateArrayProperty (WString ("IntArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    retVal, baseStringArrayProperty = base.CreateArrayProperty (WString ("StringArrayProperty"), ePRIMITIVETYPE_String)
    retVal, baseBoolArrayProperty = base.CreateArrayProperty (WString ("BoolArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Boolean)

    child.AddBaseClass(base)
    # Override an integer property with an array of ints
    status, childIntArrayProperty = child.CreateArrayProperty (WString("IntegerProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    if (allowOverriding):
        ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, status)
        child.RemoveProperty (WString ("IntegerProperty"))
    else:
        ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, status)

    # Override an integer property with an array of strings
    status, childStringArrayProperty = child.CreateArrayProperty (WString("IntegerProperty"), ePRIMITIVETYPE_String)
    ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, status)

    # Override an integer array with an integer
    status, childIntProperty = child.CreatePrimitiveProperty (WString ("IntArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    if (allowOverriding):
        ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_Success, status)
        child.RemoveProperty (WString ("IntArrayProperty"))
    else:
        ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, status)

    # Override an array of strings with an integer
    status, childIntProperty = child.CreatePrimitiveProperty (WString ("StringArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, status)

    # Override an array of boolean with an array of integers
    status, childIntArrayProperty = child.CreateArrayProperty (WString("BoolArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Integer)
    ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, status)

    # Override an array of integers with an array of boolean
    status, childBoolArrayProperty = child.CreateArrayProperty (WString("IntArrayProperty"), PrimitiveType.ePRIMITIVETYPE_Boolean)
    ASSERT_EQ(ECObjectsStatus.eECOBJECTS_STATUS_DataTypeMismatch, status)


def test_TestOverridingArrayPropertyWithNonArray ():
    checkOverriding (WString("TestSchema"), 5, False)
    checkOverriding (WString("jclass"), 1, True)
    checkOverriding (WString("jclass"), 2, True)
    checkOverriding (WString("ECXA_ams"), 1, True)
    checkOverriding (WString("ECXA_ams_user"), 1, True)
    checkOverriding (WString("ams"), 1, True)
    checkOverriding (WString("ams_user"), 1, True)
    checkOverriding (WString("Bentley_JSpace_CustomAttributes"), 2, True)
    checkOverriding (WString("Bentley_Plant"), 6, True)


class ECNameValidationTest :
    class ITester:
        def preprocess (schema):
            pass

        def postprocess (schema):
            pass

    def roundtrip (self, tester):
        retVal, schema = ECSchema.CreateSchema (WString ("MySchema"), 1, 1)
        tester.preprocess (schema)

        schemaXml = WString ()
        EXPECT_EQ (SchemaWriteStatus.eSCHEMA_WRITE_STATUS_Success, schema.WriteToXmlString (schemaXml))

        schema = None
        context = ECSchemaReadContext.CreateContext()
        retVal, schema = ECSchema.ReadFromXmlString (schemaXml.GetWCharCP (), context)
        EXPECT_EQ (eSCHEMA_READ_STATUS_Success, retVal)

        tester.postprocess (schema)

def compareOverriddenLabel (target, label):
    EXPECT_TRUE (True == target.GetIsDisplayLabelDefined())
    EXPECT_TRUE (True == target.GetDisplayLabel().Equals (label))

class DisplayLabelTester (ECNameValidationTest.ITester):
    def __init__ (self, name, encodedName) :
        self.name = name
        self.encodedName = encodedName

    def compare (self, target):
        EXPECT_FALSE (target.GetIsDisplayLabelDefined())
        EXPECT_TRUE (target.GetName() == WString (self.encodedName)), "Name: Expected {} Actual {}".format(self.encodedName, target.GetName())
        EXPECT_TRUE (target.GetDisplayLabel() == WString (self.name)), "Label: Expected {} Actual {}".format(self.name, target.GetDisplayLabel())

    def preprocess (self, schema):
        # This test used to rely on SetName() automatically encoding a non-EC name.
        # We removed that behavior because it diverges from managed EC (which throws an "invalid name" exception instead)
        # So now we must explicitly encode the name first.
        encodedName = WString ()
        EXPECT_NE (ECNameValidation.IsValidName (self.name), ECNameValidation.EncodeToValidName (encodedName,  WString (self.name)))
        schema.SetName (encodedName)
        self.compare (schema)

        retVal, ecclass = schema.CreateClass (encodedName)
        self.compare (ecclass)

        retVal, ecprop = ecclass.CreatePrimitiveProperty (encodedName, ePRIMITIVETYPE_String)
        self.compare (ecprop)


    def postprocess (self, schema):
        ecclass = schema.GetClass (self.encodedName)
        ecprop = getPropertyByName (ecclass, self.encodedName)

        self.compare (schema)
        self.compare (ecclass)
        self.compare (ecprop)

        # Test explicitly setting display labels
        schema.SetDisplayLabel (WString ("NewDisplayLabe"))
        compareOverriddenLabel (schema, "NewDisplayLabe")
        ecclass.SetDisplayLabel (WString ("1!@$"))
        compareOverriddenLabel (ecclass, "1!@$")                # will not be encoded
        ecprop.SetDisplayLabel (WString ("__x003E__"))
        compareOverriddenLabel (ecprop, "__x003E__")            # will not be decoded

        # Test explicitly un-setting display labels
        ecclass.SetDisplayLabel (WString (""))
        self.compare (ecclass)
        ecprop.SetDisplayLabel (WString (""))
        self.compare (ecprop)


def test_DisplayLabels ():
    s_testValues = [
        "NothingSpecial", "NothingSpecial",  
        "Nothing1Special2", "Nothing1Special2",  
        "1_LeadingDigitsDisallowed", "__x0031___LeadingDigitsDisallowed",  
        "Special!", "Special__x0021__",  
        "thing@mail.com", "thing__x0040__mail__x002E__com",  
        "*", "__x002A__",  
        "9&:", "__x0039____x0026____x003A__",  
        "__xNotAChar__", "__xNotAChar__",  
        "__xTTTT__", "__xTTTT__",  
        "__x####__", "__x__x0023____x0023____x0023____x0023____"
        #"", ""   ???
    ]

    nameValidationTest = ECNameValidationTest ()
    for cur in s_testValues[::2]:  # Iterate over every second element in the list.  
        name, encoded = cur, s_testValues[s_testValues.index(cur)+1]

        displayLabelTester = DisplayLabelTester (name, encoded)
        nameValidationTest.roundtrip (displayLabelTester)


def EXPECT_VALIDATION_RESULT (RESULTTOEXPECT, NAMETOTEST):
    expected_result = "eRESULT_" + RESULTTOEXPECT
    return EXPECT_EQ (getattr(ECNameValidation.ValidationResult, expected_result), ECNameValidation.Validate(NAMETOTEST))

def test_Validate ():
    EXPECT_VALIDATION_RESULT("Valid", "ThisIsAValidName")
    EXPECT_VALIDATION_RESULT("Valid", "_123")
    EXPECT_VALIDATION_RESULT("Valid", "___")
    EXPECT_VALIDATION_RESULT("Valid", "A123")

    EXPECT_VALIDATION_RESULT("NullOrEmpty", "")
    EXPECT_VALIDATION_RESULT("NullOrEmpty", None)

    EXPECT_VALIDATION_RESULT("BeginsWithDigit", "1_C")

    EXPECT_VALIDATION_RESULT("IncludesInvalidCharacters", "!ABC")
    EXPECT_VALIDATION_RESULT("IncludesInvalidCharacters", "ABC@")


def test_ExpectErrorWhenBaseClassNotFound ():
    schemaContext = ECSchemaReadContext.CreateContext()
    status, refSchema = ECSchema.ReadFromXmlString (
        WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
        "<ECSchema schemaName=\"ReferencedSchema\" version=\"01.00\" displayLabel=\"Display Label\" description=\"Description\" nameSpacePrefix=\"ref\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">"
        "    <ECClass typeName=\"BaseClass\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\" />"
        "</ECSchema>").GetWCharCP (), schemaContext)

    EXPECT_EQ (eSCHEMA_READ_STATUS_Success, status)

    strSchemaXml = WString ("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                            "<ECSchema schemaName=\"Stuff\" version=\"09.06\" displayLabel=\"Display Label\" description=\"Description\" nameSpacePrefix=\"stuff\" xmlns=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ec=\"http://www.bentley.com/schemas/Bentley.ECXML.2.0\" xmlns:ods=\"Bentley_ODS.01.02\">\n"
                            "<ECSchemaReference name=\"ReferencedSchema\" version=\"01.00\" prefix=\"ref\" />\n"
                            "    <ECClass typeName=\"ecProject\" description=\"Project ECClass\" displayLabel=\"Project\" isDomainClass=\"True\">\n"
                            "       <BaseClass>BaseClassDOESNOTEXIST</BaseClass>\n"
                            "       <BaseClass>ref:BaseClass</BaseClass>\n"
                            "    </ECClass>\n"
                            "</ECSchema>")
    status, schema = ECSchema.ReadFromXmlString (strSchemaXml.GetWCharCP (), schemaContext)

    EXPECT_NE (eSCHEMA_READ_STATUS_Success, status)
    assert (None == schema)
