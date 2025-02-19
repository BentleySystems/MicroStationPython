# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
import json
import debugpy
import io
import tempfile
import sys

from MSPyBentley import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *


'''
This class has responsibility to serialize property names and values in dictionary
''' 
class ECInstanceSerializer:
    '''
    Initialize class with input instance
    ''' 
    def __init__(self, instance):
        self.m_instance = instance

    '''
    Returns dictionary of propertyNames and values
    ''' 
    def SerializePropValues (dgnECInstance, collection, ecPropNamValDict):
        #iterate through propety value collection
        for propertyValue in collection:
            #get accessor
            accessor = propertyValue.GetValueAccessor()
            #get managed access string
            accessString = accessor.GetManagedAccessString ()
            #get value, this is raw value
            value = propertyValue.GetValue()
            typeAdaptedValue = WString ()
            strAccessString = str(accessString)
            #If value is primitive, try getting typeAdapted value, else get value from instance directly
            if value.IsStruct() == False and value.IsArray() == False:
                if BentleyStatus.eSUCCESS == dgnECInstance.GetValueAsString(typeAdaptedValue, strAccessString, False, 0):
                    ecPropNamValDict[str(accessString)] = str(typeAdaptedValue)
                else:
                    dgnECInstance.GetValue(value, strAccessString)
                    ecPropNamValDict[str(accessString)] = str(value.ToString())
            #handle child values
            if (propertyValue.HasChildValues ()):
                ECInstanceSerializer.SerializePropValues (dgnECInstance, propertyValue.GetChildValues(), ecPropNamValDict)

    '''
    Returns dictionary of propertyNames and values
    ''' 
    def SerializeInstance (instance, ecPropNamValDict):
        #ECSchema
        ecPropNamValDict['Instance schema'] = str(instance.GetClass().GetSchema().GetName())
        #ECClass
        ecPropNamValDict['Instance class'] = str(instance.GetClass().GetName())
        #InstanceID
        ecPropNamValDict['Instance ID'] = str(instance.GetInstanceId())
        #get property value collection
        collection = ECValuesCollection.Create (instance)
        #serialize values
        ECInstanceSerializer.SerializePropValues(instance, collection, ecPropNamValDict)
    
    '''
    Returns dictionary of propertyNames and values
    ''' 
    def Serialize(self):
        ecPropNamValDict = dict()
        ECInstanceSerializer.SerializeInstance(self.m_instance, ecPropNamValDict)
        return ecPropNamValDict


    

'''
Function to query EC instances on a given elementHandle
''' 
def ProcessElementInstaces(elementHandle):
    #get DgnEC manager
    mgr = DgnECManager.GetManager()
    #Prepare ECQuery
    query = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
    #prepare scope
    elementScope = FindInstancesScope.CreateScope (elementHandle, FindInstancesScopeOption (DgnECHostType.eElement))
    #execute query
    instanceCollection = mgr.FindInstances (elementScope, query)
    #Iterate through each EC instance
    for inst in instanceCollection[0]:
        #serialize EC Instance
        serializer = ECInstanceSerializer(inst)
        #serialize instance
        ecPropNamValDict = serializer.Serialize()
        #appeng propertis to final list
        finalPropList.append(ecPropNamValDict)

'''
Function to write Json
''' 
def WriteJson():
    fd,path = tempfile.mkstemp(suffix=".json")
    with io.open(path, 'w', encoding='utf-8') as buff:
        json_string = json.dumps(finalPropList, indent=1)
        buff.write(json_string)
    MessageCenter.ShowInfoMessage(str('Json File Path : '+ path), '', False)

# Collect all instance property information in list 
finalPropList = list()
'''
Function to dump EC data for selected element or given elementID
'''
def DumpECData ():
    #list for holding elements
    elementList = list()
    #check if elementId is provided
    if len(sys.argv) == 1:
        #process single element
        elementId = int(sys.argv[0]) 
        if(elementId <= 0):
            MessageCenter.ShowErrorMessage('Invalid elementID', 'Please enter valid elementID', False )
            return 
        # Get the current DGN model
        ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
        # Get the DGN model
        dgnModel = ACTIVEMODEL.GetDgnModel()            
        elementHandle = EditElementHandle(elementId, dgnModel)  # Handle for the selected element
        if elementHandle.IsValid():
            elementList.append(elementHandle)
        else:
            MessageCenter.ShowErrorMessage('Invalid elementID', 'Please enter valid elementID', False )
            return     
    else:
        #process for selected elements, we will consider just one selected element
        nSelectedElements = SelectionSetManager.GetManager().NumSelected()
        if(nSelectedElements > 0):
            for elementIndex in range(nSelectedElements):
                elementHandle = ElementHandle()
                SelectionSetManager.GetManager().GetElement(elementIndex, elementHandle)
                if elementHandle.IsValid():
                    elementList.append(elementHandle)
                    break

    #if element list is empty, return error            
    if len(elementList) == 0:
        txt = """You can execute key-in as follows 
                PYECX DUMP <Element id> OR
                select any element, then execute PYECX DUMP"""
        MessageCenter.ShowErrorMessage('Invalid arguments for KeyIn', txt, False )
        return  

    #process elements in list
    for elementHandle in elementList:
        ProcessElementInstaces(elementHandle)

    #write JSON
    WriteJson()

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ECDumpUtility.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))
