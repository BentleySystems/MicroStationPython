import copy
import math
import sys
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

def CreateAttachment(parent, child):
    attachment = None
    childMoniker   = child[0].GetDgnFile().GetDocument().GetMoniker()
    childModelName = child[0].GetModelName()
    attachment = parent[0].CreateDgnAttachment(childMoniker, childModelName, False)
    assert attachment != None
    attachment[1].NestDepth = 99
    attachment[1].WriteToModel()

def AddECInstanceToElement(eeh, enabler):
    value = 0
    wipInstance = enabler.GetSharedWipInstance()
    value += 1
    wipInstance.SetValue("IntegerProp_1", ECValue(value))
    dgnecInstance = DgnElementECInstance
    dgnecInstance = enabler.CreateInstanceOnElement(wipInstance, eeh, False)
    return dgnecInstance;

def CreateLine(model):
    value = 0.0
    is3d = model[0].Is3d();
    segment = DSegment3d(0.0, value, 0.0, value, value, 0.0)
    value += 1000.0
    eeh = EditElementHandle()
    assert BentleyStatus.eSUCCESS == LineHandler.CreateLineElement(eeh, None, segment, is3d, model[0])
    assert BentleyStatus.eSUCCESS == eeh.AddToModel()

    return eeh.GetElementRef();

def GetFile1(ret):
    if ret[0].GetDgnFile() == None:
        return None
    else:
        return ret[0].GetDgnFile()
    
def GetFile2():
    m_file2DataManager = TestDgnManager()
    if m_file2DataManager == None:
        return None
    else:
        return m_file2DataManager.GetLoadedDgnPtr().get()

def GetTestSchemaXml():
    buff = "<?xml version='1.0' encoding='UTF-8'?>" \
                  "<ECSchema schemaName='Test' nameSpacePrefix='test' version='1.0' xmlns='http://www.bentley.com/schemas/Bentley.ECXML.2.0'>" \
                  "    <ECClass typeName='Gadget' isDomainClass='True'>" \
                  "        <ECProperty propertyName='IntegerProp_1' typeName='int' />" \
                  "        <ECProperty propertyName='StringProp_1' typeName='string' />" \
                  "        <ECProperty propertyName='DoubleProp_1' typeName='double' />" \
                  "    </ECClass>" \
                  "</ECSchema>"
    return buff
    
def ImportSchema(dgnFile):
    dgnECManager = DgnECManager.GetManager()
    schema = ECSchema.CreateSchema(WString("Test"), 1, 1)
    schema[1].CreateClass(WString("Gadget"))
    status = dgnECManager.ReadSchemaFromXmlString(GetTestSchemaXml(), dgnFile, WStringArray())
    assert eSCHEMA_READ_STATUS_Success == status[0]

    return schema, dgnFile

def BuildComplexReferenceGraph(ret, loadDgnFile):
    dgnECManager = DgnECManager.GetManager()
    file1 = GetFile1(ret)
    schema, file1 = ImportSchema(file1)
    dgnECManager.ImportSchema(schema[1], file1)
    enabler1 = dgnECManager.ObtainInstanceEnablerByName("Test", "Gadget", file1)
    assert enabler1 != None

    modelA = file1.CreateNewModel("Model_A", DgnModelType.eNormal, False)
    elementA = EditElementHandle(CreateLine(modelA), ret[0])
    AddECInstanceToElement(elementA, enabler1)

    modelB = file1.CreateNewModel("Model_B", DgnModelType.eNormal, False)
    elementB = EditElementHandle(CreateLine(modelB), ret[0])
    AddECInstanceToElement(elementB, enabler1)

    modelC = file1.CreateNewModel("Model_C", DgnModelType.eNormal, False)
    elementC = EditElementHandle(CreateLine(modelC), ret[0])
    AddECInstanceToElement(elementC, enabler1)

    modelD = file1.CreateNewModel("Model_D", DgnModelType.eNormal, False)
    elementD = EditElementHandle(CreateLine(modelD), ret[0])
    AddECInstanceToElement(elementD, enabler1)

    # TestDgnManager in methode GetFile2 is not exposed.
    # file2 = GetFile2()
    # status = ImportSchema(file2)
    # enabler2 = dgnECManager.ObtainInstanceEnablerByName ("Test", "Gadget", file2);
    # assert enabler2 != None

    # modelX = file1.CreateNewModel("Model_X", DgnModelType.eNormal, False)
    # elementX = EditElementHandle(CreateLine(modelX), ret[0])
    # AddECInstanceToElement (elementX, enabler2)

    # modelY = file1.CreateNewModel("Model_Y", DgnModelType.eNormal, False)
    # elementY = EditElementHandle(CreateLine(modelY), ret[0])
    # AddECInstanceToElement (elementY, enabler2)

    # Model_A
    # | Model B
    # | | Model B self ref
    # | | Model D
    # | Model C
    # | | Model D
    # | | Model Y
    # | Model X
    # | | Model Y


    # CreateAttachment(modelX, modelY)
    # file2.ProcessChanges(DgnSaveReason.ApplInitiated)
    CreateAttachment(modelB, modelB)
    CreateAttachment(modelB, modelD)
    CreateAttachment(modelC, modelD)
    # CreateAttachment(modelC, modelY)
    CreateAttachment(modelA, modelB)
    CreateAttachment(modelA, modelC)
    # CreateAttachment(modelA, modelX)
    file1.ProcessChanges(DgnSaveReason.eApplInitiated)
    return modelA, file1

def GetInstanceCount_One(modelToSearch, searchAttachments):
    scopeOption = FindInstancesScopeOption(DgnECHostType.eElement, searchAttachments)
    scope = FindInstancesScope.CreateScope(modelToSearch[0], scopeOption)
    query = ECQuery.CreateQuery("Test", "Gadget")
    count = 0
    for i in DgnECManager.GetManager().FindInstances(scope, query)[0]:
        print(i)
        count += 1
    return count

def GetInstanceCount_Two(modelToSearch, searchAttachments, excludeNestedReferences):
    modelRefOptions = ReachableModelRefOptions()
    if excludeNestedReferences:
        modelRefOptions.ExcludeNestedAttachments()
    options = FindInstancesScopeOption()
    options.SetSearchAttachments(searchAttachments)
    options.SetReachableModelOptions(modelRefOptions)
    scope = FindInstancesScope.CreateScope(modelToSearch[0], options)
    query = ECQuery.CreateQuery("Test", "Gadget")
    count = 0
    instanceCollection = DgnECManager.GetManager().FindInstances(scope, query)
    for i in DgnECManager.GetManager().FindInstances(scope, query)[0]:
        count += 1
    return count

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])  
def test_ComplexReferenceGraph(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    modelA, file1 = BuildComplexReferenceGraph(ret, dgnFile)
    assert 1 == GetInstanceCount_One(modelA, False)
    # Unless the issue in line 100 of TestDgnManager not being fixed.
    # assert 6 == GetInstanceCount_One(modelA, True)
    # assert 6 == GetInstanceCount_Two(modelA, True, False)
    # assert 4 == GetInstanceCount_Two(modelA, True, True)