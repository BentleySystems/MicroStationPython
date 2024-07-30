#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import math
from collections import OrderedDict
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnPlatformTest import *
mgr = None        
def Create_schema():
    schema = ECSchema.CreateSchema(WString('ECXAttributesTest'), 1, 0)
    #create a base "Equipment" class
    equipment = schema[1].CreateClass(WString("Equipment"))
    prop = equipment[1].CreatePrimitiveProperty(WString("SerialNumber"), ePRIMITIVETYPE_Integer)
    prop = equipment[1].CreatePrimitiveProperty(WString("Manufacturer"), ePRIMITIVETYPE_String)
    #Create two subclasses of "Equipment"
    gadget = schema[1].CreateClass(WString("Gadget"))
    gadget[1].AddBaseClass (equipment[1])
    prop = gadget[1].CreatePrimitiveProperty(WString("Price"), ePRIMITIVETYPE_Double)
    widget = schema[1].CreateClass(WString("Widget"))
    widget[1].AddBaseClass (equipment[1])
    prop = widget[1].CreatePrimitiveProperty(WString("Description"), ePRIMITIVETYPE_String)
    return schema

def CreateHostElement(eeh, addToModel, ret):
    # segment = DSegment3d()
    segment = DSegment3d(0,0,0, 100,100,0)
    LineHandler.CreateLineElement (eeh, None, segment, ret[0].Is3d(), ret[0])
    if (addToModel):
       eeh.AddToModel()


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_FindECInstances(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global mgr
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile) 
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    schema = Create_schema()
    mgr = DgnECManager.GetManager()
    mgr.ImportSchema (schema[1], srcDgnFile)
    widgetHost = EditElementHandle()
    gadgetHost = EditElementHandle()
    gadgetHost2 = EditElementHandle()
    CreateHostElement (widgetHost, True, ret)
    CreateHostElement (gadgetHost, True, ret)
    CreateHostElement (gadgetHost2, True, ret)
    widgetEnabler = mgr.ObtainInstanceEnablerByName ("ECXAttributesTest", "Widget", srcDgnFile)
    gadgetEnabler = mgr.ObtainInstanceEnablerByName ("ECXAttributesTest", "Gadget", srcDgnFile)
    widgetWip = widgetEnabler.GetSharedWipInstance()
    widgetWip.SetValue ("SerialNumber", ECValue (1))
    widget = widgetEnabler.CreateInstanceOnElement (widgetWip, widgetHost)[1]
    gadgetWip = gadgetEnabler.GetSharedWipInstance()
    gadgetWip.SetValue ("SerialNumber", ECValue (2))
    gadgetEnabler.CreateInstanceOnElement (gadgetWip, gadgetHost)
    gadgetWip.SetValue ("SerialNumber", ECValue (3))
    gadgetEnabler.CreateInstanceOnElement (gadgetWip, gadgetHost2)
    gadgetQuery = ECQuery.CreateQuery ("ECXAttributesTest", "Gadget")
    widgetQuery = ECQuery.CreateQuery ("ECXAttributesTest", "Widget")
    equipmentQuery = ECQuery.CreateQuery ("ECXAttributesTest", "Equipment", True)
    allQuery = ECQuery.CreateQuery (ECQueryProcessFlags.eECQUERY_PROCESS_SearchAllExtrinsic)
    widgetAndGadgetQuery = ECQuery.CreateQuery (ECQueryProcessFlags.eECQUERY_PROCESS_SearchSpecifiedClasses)
    widgetAndGadgetQuery.AddSearchClass ("ECXAttributesTest", "Widget")
    widgetAndGadgetQuery.AddSearchClass ("ECXAttributesTest", "Gadget")
    widgetIdQuery = ECQuery.CreateQuery (ECQueryProcessFlags.eECQUERY_PROCESS_SearchAllClasses)
    widgetId = widget.GetInstanceId()
    where = WhereCriterion.CreateComparison (WhereExpression.CreateECInstanceIdExpression(), WhereCriterion.eEQ, WhereExpression.CreateConstant (ECValue (widgetId)))
    widgetIdQuery.SetWhereCriterion (where)
    serialNumberQuery = ECQuery.CreateQuery ("ECXAttributesTest", "Equipment", True)
    serialNotEqualTo2 = WhereCriterion.CreateComparison (WhereExpression.CreatePropertyExpression (WString("SerialNumber")), WhereCriterion.eNE, WhereExpression.CreateConstant (ECValue (2)))
    serialNumberQuery.SetWhereCriterion (serialNotEqualTo2)
    scopeOption = FindInstancesScopeOption()
    modelScope = FindInstancesScope.CreateScope (ret[0], scopeOption)
    fileScope = FindInstancesScope.CreateScope (srcDgnFile, scopeOption)
    widgetHostScope = FindInstancesScope.CreateScope (widgetHost, scopeOption)
    gadgetHostScope = FindInstancesScope.CreateScope (gadgetHost, scopeOption)
    elements = ElementAgenda()
    elements.Insert (widgetHost.GetElementRef(), widgetHost.GetModelRef())
    elements.Insert (gadgetHost.GetElementRef(), gadgetHost.GetModelRef())
    elementsScope = FindInstancesScope.CreateScope (ret[0], elements, scopeOption)

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, gadgetQuery)[0]) == 2
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, gadgetQuery)[0]) == 2
    assert ECTestHelpers.CountInstances (mgr.FindInstances (widgetHostScope, gadgetQuery)[0]) == 0
    assert ECTestHelpers.CountInstances (mgr.FindInstances (gadgetHostScope, gadgetQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (elementsScope, gadgetQuery)[0]) == 1

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, widgetQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, widgetQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (widgetHostScope, widgetQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (gadgetHostScope, widgetQuery)[0]) == 0
    assert ECTestHelpers.CountInstances (mgr.FindInstances (elementsScope, widgetQuery)[0]) == 1

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, equipmentQuery)[0]) == 3
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, equipmentQuery)[0]) == 3
    assert ECTestHelpers.CountInstances (mgr.FindInstances (widgetHostScope, equipmentQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (gadgetHostScope, equipmentQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (elementsScope, equipmentQuery)[0]) == 2

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, allQuery)[0]) == 3
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, allQuery)[0]) == 3
    assert ECTestHelpers.CountInstances (mgr.FindInstances (widgetHostScope, allQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (gadgetHostScope, allQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (elementsScope, allQuery)[0]) == 2

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, widgetAndGadgetQuery)[0]) == 3
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, widgetAndGadgetQuery)[0]) == 3
    assert ECTestHelpers.CountInstances (mgr.FindInstances (widgetHostScope, widgetAndGadgetQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (gadgetHostScope, widgetAndGadgetQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (elementsScope, widgetAndGadgetQuery)[0]) == 2

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, widgetIdQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, widgetIdQuery)[0]) == 1

    assert ECTestHelpers.CountInstances (mgr.FindInstances (modelScope, serialNumberQuery)[0]) == 2
    assert ECTestHelpers.CountInstances (mgr.FindInstances (fileScope, serialNumberQuery)[0]) == 2
    assert ECTestHelpers.CountInstances (mgr.FindInstances (widgetHostScope, serialNumberQuery)[0]) == 1
    assert ECTestHelpers.CountInstances (mgr.FindInstances (gadgetHostScope, serialNumberQuery)[0]) == 0
    assert ECTestHelpers.CountInstances (mgr.FindInstances (elementsScope, serialNumberQuery)[0]) == 1

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateECInstances(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global mgr
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile) 
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    schema = Create_schema()
    mgr = DgnECManager.GetManager()
    mgr.ImportSchema (schema[1], srcDgnFile)
    enabler = mgr.ObtainInstanceEnablerByName ("ECXAttributesTest", "Gadget", srcDgnFile)
    assert enabler != None
   
    wip = enabler.GetSharedWipInstance()
    wip.SetValue ("SerialNumber", ECValue (12345))
    wip.SetValue ("Manufacturer", ECValue (WString("Gadgets R Us"), False))
    wip.SetValue ("Price", ECValue (2.50))
    eeh = EditElementHandle()
    CreateHostElement (eeh, True, ret)
    createdInstance = enabler.CreateInstanceOnElement (wip, eeh)
    assert createdInstance[0] == BentleyStatus.eSUCCESS
    scheduledInstance = enabler.ScheduleInstanceOnElement (wip, eeh)
    assert scheduledInstance[0] == BentleyStatus.eSUCCESS

    # Verify our DgnECInstances have the property values we specified
    instances = [createdInstance[1], scheduledInstance[1]]                   
    for instance in instances:
        assert (ECTestHelpers.InstanceHasValue (instance, ECValue (12345), "SerialNumber")) == True
        assert (ECTestHelpers.InstanceHasValue (instance, ECValue (WString("Gadgets R Us")), "Manufacturer")) == True
        assert (ECTestHelpers.InstanceHasValue (instance, ECValue (2.50), "Price")) == True






@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Persistence(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    global mgr
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile) 
    ret = srcDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    schema = Create_schema()
    mgr = DgnECManager.GetManager()
    mgr.ImportSchema (schema[1], srcDgnFile)
    eeh = EditElementHandle()
    CreateHostElement (eeh, True, ret)
    enabler = mgr.ObtainInstanceEnablerByName ("ECXAttributesTest", "Widget", srcDgnFile)
    wip = enabler.GetSharedWipInstance()
    wip.SetValue ("Description", ECValue (WString("Initial Value")))

    createdInstance = enabler.CreateInstanceOnElement (wip, eeh)[1]

    assert ECTestHelpers.InstanceHasValue (createdInstance, ECValue (WString("Initial Value")), "Description") == True
    query = ECQuery.CreateQuery ("ECXAttributesTest", "Widget")
    scopeOption = FindInstancesScopeOption()
    modelScope = FindInstancesScope.CreateScope (ret[0], scopeOption)
    persistent = ECTestHelpers.FindInstance (modelScope, query)
    assert persistent != None
    createdInstance.SetValue ("Description", ECValue (WString("Persistent")))
    assert ECTestHelpers.InstanceHasValue (createdInstance, ECValue (WString("Persistent")), "Description") == True
    assert ECTestHelpers.InstanceHasValue (persistent, ECValue (WString("Initial Value")), "Description") == True
    createdInstance.WriteChanges()
    persistent = ECTestHelpers.FindInstance (modelScope, query)
    assert ECTestHelpers.InstanceHasValue (persistent, ECValue (WString("Persistent")), "Description") == True
    createdInstance.SetValue ("Description", ECValue ("Scheduled"))
    elemRef = eeh.GetElementRef()
    createdInstance.ScheduleWriteChanges (eeh)
    eehScope = FindInstancesScope.CreateScope (eeh, scopeOption)
    scheduled = ECTestHelpers.FindInstance (eehScope, query)
    assert scheduled != None
    persistent = ECTestHelpers.FindInstance (modelScope, query)
    assert ECTestHelpers.InstanceHasValue (scheduled, ECValue (WString("Scheduled")), "Description") == True
    assert ECTestHelpers.InstanceHasValue (persistent, ECValue (WString("Persistent")), "Description") == True
    eeh.ReplaceInModel (elemRef)
    persistent = ECTestHelpers.FindInstance (modelScope, query)
    assert ECTestHelpers.InstanceHasValue (persistent, ECValue (WString("Scheduled")), "Description") == True
    persistent.Delete()
    assert ECTestHelpers.FindInstance (modelScope, query) == None
    c = enabler.ScheduleInstanceOnElement (enabler.GetSharedWipInstance(), eeh)
    assert c[0] == BentleyStatus.eSUCCESS
    eehScope = FindInstancesScope.CreateScope (eeh, scopeOption)
    assert ECTestHelpers.FindInstance (eehScope, query) != None
    assert ECTestHelpers.FindInstance (modelScope, query) == None
    eeh.ReplaceInModel (elemRef)
    persistent = ECTestHelpers.FindInstance (modelScope, query)
    assert persistent != None
    assert persistent.ScheduleDelete (eeh) == BentleyStatus.eSUCCESS
    eehScope = FindInstancesScope.CreateScope (eeh, scopeOption)
    assert ECTestHelpers.FindInstance (eehScope, query) == None
    assert ECTestHelpers.FindInstance (modelScope, query) != None
    eeh.ReplaceInModel (elemRef)
    assert ECTestHelpers.FindInstance (modelScope, query) == None

