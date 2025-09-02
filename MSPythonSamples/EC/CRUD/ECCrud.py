# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
import io
import sys

from MSPyBentley import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
from MSPyBentleyGeom import *

'''Sample showing how to perform CRUD (Create, Read, Update, Delete) operations for DgnEC'''

'''
Class for reading and importing schema.
'''
class SchemaHelper:
    '''
    Pass the XML file name of the schema (e.g., schemaExample for schemaExample.xml) as an argument needed for SchemaHelper instance creation.
        fileName    : str       XML file name
    '''
    def __init__(self, fileName):
        self.fileName = fileName
        self.activeModel = ISessionMgr.ActiveDgnModelRef
        if self.activeModel is None:
             MessageCenter.ShowInfoMessage('Failed To Load Active Model','',False)
             return
        self.dgnModel = self.activeModel.GetDgnModel()
        self.dgnFile = self.dgnModel.GetDgnFile()
        self.schemaObj = None

    '''
    This method is reponsible to load schema.
    ''' 
    def LoadSchema(self):
        mgr = DgnECManager.GetManager()
        # Gets the path of XML file and reads it
        self.schemaObj = DgnECManager.ReadSchemaFromXmlFile(mgr, os.path.dirname(os.path.realpath(__file__)) + '\\' + self.fileName, self.dgnFile)
        if self.schemaObj:
            MessageCenter.ShowInfoMessage('Success To Read Schema','',False)
        else:
            MessageCenter.ShowInfoMessage('Fail To Read Schema','',False)
            return
        # Imports the schema after reading it
        # ReadSchemaFromXmlFile returns a tuple such that index 1 is ECSchema object
        status = DgnECManager.ImportSchema(mgr, self.schemaObj[1], self.dgnFile, False, True)
        if status:
            MessageCenter.ShowInfoMessage('Success To Import Schema','',False)
        else:
            MessageCenter.ShowInfoMessage('Fail To Import Schema','',False)


'''
Class for performing EC operations after reading and importing schema.
'''
class DgnECHelper:

    '''
    Pass a SchemaHelper instance as an arguement for DgnECHelper instance creation.
    schemaHelper    : SchemaHelper instance
    '''
    def __init__(self, schemaHelper: SchemaHelper):
        self.schemaHelper = schemaHelper
        self.dgnModel = schemaHelper.dgnModel
        self.dgnFile = schemaHelper.dgnFile

    '''
    This method takes the element handle, associates it with required class and sets the default values.
    Pass an element handle, schema name, class name, property name and property value as method parameters.
        eeh             : MSPyDgnPlatform.EditElementHandle object      Edit Element Handle object
        schemaName      : str                                           Schema Name
        className       : str                                           Class Name
        propertyName    : str                                           Property Name
        propertyValue   : str                                           Property Value
    Returns a DgnECInstance
    '''
    def SetInstance(self, eeh, schemaName, className, propertyName, propertyValue):
        mgr = DgnECManager.GetManager()
        instanceEnabler = mgr.ObtainInstanceEnablerByName(schemaName, className, self.dgnFile)
        if instanceEnabler:
            MessageCenter.ShowInfoMessage('Success To Obtain DgnEC Instance Enabler','',False)
        else:
            MessageCenter.ShowInfoMessage('Fail To Obtain DgnEC Instance Enabler','',False)
            return None
        wipInstance = instanceEnabler.GetSharedWipInstance()
        self.instance = instanceEnabler.CreateInstanceOnElement(wipInstance, eeh)
        # CreateInstanceOnElement returns a tuple with 0th value is the status and 1st value is DgnECInstance
        self.instance[1].SetValue(propertyName, ECValue(propertyValue))
        self.instance[1].WriteChanges()
        return self.instance[1]

    '''
    This method updates the properties of EC instance created
        ecInstance      : MSPyECObjects.IECInstance     EC instance to be updated
        propertyName    : str                           ECProperty propertyName
        value           : Bentley.ECN.ECValue           Updated EC value
    '''
    def UpdateInstance(self, ecInstance, propertyName, value):
        ecInstance.SetValue(propertyName, ECValue(value))
        ecInstance.WriteChanges()

    '''
    This method deletes the properties of EC instance
        ecInstance      : MSPyECObjects.IECInstance     EC instance to be deleted
    '''
    def DeleteInstance(self, ecInstance):
        ecInstance.Delete()

    '''
    This method creates relationship between two EC instances: source instance and target instance, using Relationship class
        schemaName          : str                                       Schema Name
        relationshipClass   : str                                       Relationship Class Name
        source              : MSPyDgnPlatform.DgnElementECInstance      Source EC instance
        target              : MSPyDgnPlatform.DgnElementECInstance      Target EC instance
    '''
    def CreateInstanceRelationship(self, schemaName, relationshipClass , source, target):
        mgr = DgnECManager.GetManager()
        relationship_enabler = mgr.ObtainDgnECRelationshipEnabler(schemaName, relationshipClass, self.dgnFile)
        status = relationship_enabler.CreateRelationship(source, target)
        if BentleyStatus.eSUCCESS != status:
            MessageCenter.ShowInfoMessage('Success To Create Relationship','',False)
        else:
            MessageCenter.ShowInfoMessage('Fail To Create Relationship','',False)

    '''
    This method creates relationship between two EC instances
        schemaName      : str       Schema Name
        className       : str       Class Name
    Returns a MSPyDgnPlatform.DgnECInstanceIterable object
    '''
    def FindIterInstance(self, schemaName, className):
        mgr = DgnECManager.GetManager()
        query = ECQuery.CreateQuery(schemaName, className, False)
        query.SetSelectProperties(True)
        scopeOption = FindInstancesScopeOption((DgnECHostType.eElement))
        fileScope = FindInstancesScope.CreateScope(self.dgnFile, scopeOption)
        instances = mgr.FindInstances(fileScope, query)
        return instances[0]


'''
Functions for performing CRUD operations with SchemaHelper class and DgnECHelper class:
'''

schemaXMLName = "Simple.01.00.ecschema.xml"
schemaName = "Simple"
propertyName = "Manufacturer"
widgetClass = "Widget"
gadgetClass = "Gadget"
relationshipClass = "WidgetHasGadgets"

'''
This function loads ECSchema by providing schema file name.
'''
def LocateAndLoadSchema():
    schemaHelperInstance = SchemaHelper(schemaXMLName)
    schemaHelperInstance.LoadSchema()

'''
This function creates two elements and associates it with respective ECClass and creates relation between two.
'''
def CreateInstancesAndRelations():
    schemaHelperInstance = SchemaHelper(schemaXMLName)
    dgnECHelperInstance = DgnECHelper(schemaHelperInstance)

    # creating line element handle and associating it with schema class: Widget
    widgetElement = CreateLineElement(DPoint3d(0,0,0),DPoint3d(-100,100,0))
    dgnECWidgetInstance = dgnECHelperInstance.SetInstance(widgetElement, schemaName, widgetClass, propertyName, "ACME Engineering")

    # creating line element handle and associating it with schema class: Gadget
    gadgetElement = CreateLineElement(DPoint3d(0,0,0),DPoint3d(0,100,0))
    dgnECGadgetInstance = dgnECHelperInstance.SetInstance(gadgetElement, schemaName, gadgetClass , propertyName, "Sample App Gadget Manufacturer")

    # creating relationship between two instances
    dgnECHelperInstance.CreateInstanceRelationship(schemaName, relationshipClass, dgnECWidgetInstance, dgnECGadgetInstance)
    MessageCenter.ShowInfoMessage('Success To Create Widget Gadget Relationship','',False)

'''
This function finds the instance and reads related information.
'''
def ReadInstancesAndRelations():
    schemaHelperInstance = SchemaHelper(schemaXMLName)
    dgnECHelperInstance = DgnECHelper(schemaHelperInstance)

    # finds instance related to Widget class and then reads related information
    dgnECIterableWidgetInstance = dgnECHelperInstance.FindIterInstance(schemaName, widgetClass)
    if dgnECIterableWidgetInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Find Instances','',False)
    for ecWidgetInst in dgnECIterableWidgetInstance:
        widgetInstanceID = ecWidgetInst.GetInstanceId()
    formatedWidgetMessage= f'Success To Read Widget Instance, with Instance Id:  {widgetInstanceID} '
    if widgetInstanceID is None:
        MessageCenter.ShowInfoMessage('Fail To Read Widget Instance','',False)
    else:
        MessageCenter.ShowInfoMessage(formatedWidgetMessage,'',False)

    # finds instance related to Gadget class and then reads related information
    dgnECIterableGadgetInstance = dgnECHelperInstance.FindIterInstance(schemaName, gadgetClass)
    if dgnECIterableGadgetInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Find Instances','',False)
    for ecGadgetInst in dgnECIterableWidgetInstance:
        gadgetInstanceID = ecGadgetInst.GetInstanceId()
    formatedGadgetMessage = f'Success To Read Gadget Instance, with Instance Id:  {gadgetInstanceID} '
    if gadgetInstanceID is None:
        MessageCenter.ShowInfoMessage('Fail To Read Gadget Instance','',False)
    else:
        MessageCenter.ShowInfoMessage(formatedGadgetMessage,'',False)

    dgnECIterableRelationshipInstance = dgnECHelperInstance.FindIterInstance(schemaName, relationshipClass)
    if dgnECIterableRelationshipInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Read Widget Gadget Relation','',False)
    else:
        MessageCenter.ShowInfoMessage('Success To Read Widget Gadget Relation','',False)

'''
This function finds the instance and updates the property values.
'''
def UpdateInstancesAndRelations():
    schemaHelperInstance = SchemaHelper(schemaXMLName)
    dgnECHelperInstance = DgnECHelper(schemaHelperInstance)

    # finds instance related to Widget class
    dgnECIterableWidgetInstance = dgnECHelperInstance.FindIterInstance(schemaName, widgetClass)
    if dgnECIterableWidgetInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Find Instances','',False)
    # updates the properties of instance related to Widget class
    for ecWidgetInst in dgnECIterableWidgetInstance:
        dgnECHelperInstance.UpdateInstance(ecWidgetInst, propertyName, "ACME Engineering value changed")
    MessageCenter.ShowInfoMessage("Success To Update Widget",'',False)

    # finds instance related to Widget class
    dgnECIterableGadgetInstance = dgnECHelperInstance.FindIterInstance(schemaName, gadgetClass)
    if dgnECIterableGadgetInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Find Instances','',False)
    # updates the properties of instance related to Widget class
    for ecGadgetInst in dgnECIterableGadgetInstance:
        dgnECHelperInstance.UpdateInstance(ecGadgetInst, propertyName, "Sample App Gadget Manufacturer value changed")
    MessageCenter.ShowInfoMessage("Success To Update Widget",'',False)
    MessageCenter.ShowInfoMessage("Success To Update Widget Gadget Relation",'',False)

'''
This function finds the instance and deletes the related instance.
'''
def DeleteInstancesAndRelations():
    schemaHelperInstance = SchemaHelper(schemaXMLName)
    dgnECHelperInstance = DgnECHelper(schemaHelperInstance)

    # finds instance related to Widget class
    dgnECIterableWidgetInstance = dgnECHelperInstance.FindIterInstance(schemaName, widgetClass)
    if dgnECIterableWidgetInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Find Instances','',False)
    # deletes the instance related to Widget class
    for ecWidgetInst in dgnECIterableWidgetInstance:
        dgnECHelperInstance.DeleteInstance(ecWidgetInst)
    MessageCenter.ShowInfoMessage("Success To Delete Widget",'',False)

    # finds instance related to Gadget class
    dgnECIterableGadgetInstance = dgnECHelperInstance.FindIterInstance(schemaName, gadgetClass)
    if dgnECIterableGadgetInstance is None:
        MessageCenter.ShowInfoMessage('Fail To Find Instances','',False)
    # deletes the instance related to Widget class
    for ecGadgetInst in dgnECIterableGadgetInstance:
        dgnECHelperInstance.DeleteInstance(ecGadgetInst)
    MessageCenter.ShowInfoMessage("Success To Delete Widget",'',False)
    MessageCenter.ShowInfoMessage("Success To Delete Widget Gadget Relation",'',False)


'''
Function for creating line element handle example.
'''
def CreateLineElement(point1, point2):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
 
    eeh = EditElementHandle()
    seg = DSegment3d(point1, point2)
    status = LineHandler.CreateLineElement(eeh, None, seg,
                                               ACTIVEMODEL.Is3d(),
                                               ACTIVEMODEL)
    if BentleyStatus.eSUCCESS != status:
            return False
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
            return False
    return eeh


'''
Main
'''
if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ECCrud.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))
