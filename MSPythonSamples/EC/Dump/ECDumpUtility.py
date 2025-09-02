# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
import json
import io
import tempfile
import sys

from MSPyBentley import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''
Sample demonstrating how to dump EC data for selected element
'''

'''
This class has responsibility to serialize property names and values in dictionary
''' 
class ECInstanceSerializer:
    '''
    Initialize class with input instance
    ''' 
    def __init__(self, instance):
        self.m_instance = instance

    def SerializePropValues (dgnECInstance, collection, ecPropNamValDict):
        """
        Serialize property values from a collection into a dictionary.

        :param dgnECInstance: The EC instance containing the property values.
        :type dgnECInstance: ECInstance
        :param collection: The collection of property values to serialize.
        :type collection: list
        :param ecPropNamValDict: The dictionary to store serialized property names and values.
        :type ecPropNamValDict: dict
        """
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

    def SerializeInstance (instance, ecPropNamValDict):
        """
        Serialize an EC instance into a dictionary of property names and values.

        :param instance: The EC instance to serialize.
        :type instance: ECInstance
        :param ecPropNamValDict: The dictionary to store serialized property names and values.
        :type ecPropNamValDict: dict
        :returns: Dictionary of property names and values.
        :rtype: dict
        """
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
    
    def Serialize(self):
        """
        Returns a dictionary of property names and values.

        :returns: Dictionary of property names and values.
        :rtype: dict
        """
        ecPropNamValDict = dict()
        ECInstanceSerializer.SerializeInstance(self.m_instance, ecPropNamValDict)
        return ecPropNamValDict


    

def ProcessElementInstaces(elementHandle):
    """
    Query EC instances on a given element handle and serialize them into a list of dictionaries.

    :param elementHandle: The handle of the element to query EC instances from.
    :type elementHandle: ElementHandle
    :returns: List of dictionaries containing serialized property names and values.
    :rtype: list
    """
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

def WriteJson():
    """
    Write the final property list to a JSON file.

    :returns: None
    """
    fd,path = tempfile.mkstemp(suffix=".json")
    with io.open(path, 'w', encoding='utf-8') as buff:
        json_string = json.dumps(finalPropList, indent=1)
        buff.write(json_string)
    MessageCenter.ShowInfoMessage(str('Json File Path : '+ path), '', False)

# Collect all instance property information in list 
finalPropList = list()

def DumpECData ():
    """
    Dump EC data for a selected element or given elementID.

    If an elementID is provided as a command-line argument, it processes the element with that ID.
    Otherwise, it processes the currently selected element.

    :returns: None
    """
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
