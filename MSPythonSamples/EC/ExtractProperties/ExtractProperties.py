'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2025 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
import io
import sys
import json
import tempfile

from MSPyBentley import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''Sample showing how to extract the element properties'''

'''
Class for extracting properties of an element.
'''
class ECPropertyExtractor:
    '''
    Initize the constructor using elementID.
    '''
    def __init__(self, elementID):
        self.elementID = elementID
        self.properties = {}

    '''
    This method is reponsible to get the element handle for elementID.
    Returns an EditElementHandle for the elementID.
    ''' 
    def GetElementHandle(self):
        activeModel = ISessionMgr.ActiveDgnModelRef
        dgnModel = activeModel.GetDgnModel()
        elementHandle = EditElementHandle(self.elementID, dgnModel)
        if not elementHandle.IsValid():
            MessageCenter.ShowInfoMessage(f"Invalid element handle for ID {self.elementID}.", '', False)
            return None
        return elementHandle

    '''
    This method takes the element handle, to create scope and query.
        elementHandle   : MSPyDgnPlatform.EditElementHandle object      Edit Element Handle object
    Returns a python list
    '''
    def GetInstanceCollection(self, elementHandle):
        scope = FindInstancesScope.CreateScope(elementHandle, FindInstancesScopeOption(DgnECHostType.eElement))
        query = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
        instanceCollection = DgnECManager.GetManager().FindInstances(scope, query)
        return instanceCollection

    ''' 
    This method is responsible to export the properties of the element in JSON format.
    '''
    def ProcessJson(self):
        elementHandle = self.GetElementHandle()
        if not elementHandle:
            return
        instanceCollection = self.GetInstanceCollection(elementHandle)
        if not isinstance(instanceCollection[0], DgnECInstanceIterable):
            MessageCenter.ShowInfoMessage(f"Failed to retrieve properties for element ID {self.elementID}.", '', False)
            return
        for ecInstance in instanceCollection[0]:
            enabler = ecInstance.GetEnabler()
            ecClass = enabler.GetClass()
            collection = ECValuesCollection.Create(ecInstance)
            for propertyValue in collection:
                self.ProcessPropertyValue(propertyValue, ecInstance, ecClass, self.properties)
        self.WriteJson()

    ''' 
    This method processes primitive property value and populates the properties dictionary.
    Pass a propertyValue, ecInstance, ecClass and properties as method parameters.
        propertyValue   : MSPyECObjects.ECPropertyValue object          EC Property Value object
        ecInstance      : MSPyECObjects.DgnECInstance object            Dgn EC Instance object
        ecClass         : MSPyECObjects.ECClass object                  Dgn EC Class object
        properties      : Python dictionary                             Container for properties
    
    '''
    def ProcessPropertyValue(self, propertyValue, ecInstance, ecClass, properties):
        accessor = propertyValue.GetValueAccessor()
        accessString = accessor.GetManagedAccessString()
        strAccessString = str(accessString)
        ecProperty = ecClass.GetProperty(str(accessString))
        self.PopulatePrimitive(ecInstance, ecProperty, strAccessString, properties)
        # Loop to handle child values
        if propertyValue.HasChildValues():
            for childPropertyValue in propertyValue.GetChildValues():
                self.ProcessPropertyValue(childPropertyValue, ecInstance, ecClass, properties)

    ''' 
    This method retrieves the property value, type, and name, and populates the properties dictionary with primitive values.
    Pass an ecInstance, ecProperty, accessString and properties as method parameters.
        ecInstance      : MSPyECObjects.DgnECInstance object            Dgn EC Instance object
        ecProperty      : MSPyECObjects.PrimitiveECProperty object      Primitive EC property object
        strAccessString : str                                           Access string for the property
        properties      : Python dictionary                             Container for properties
    '''
    def PopulatePrimitive(self, ecInstance, ecProperty, strAccessString, properties):
        typeAdaptedValue = WString()
        ecPropvalue = ECValue()
        if ecProperty is None:
            return 
        propType = ecProperty.GetTypeName().GetWCharCP()
        propName = str(ecProperty.GetName().GetWCharCP())
        if BentleyStatus.eSUCCESS == ecInstance.GetValueAsString(typeAdaptedValue, strAccessString, False, 0):
            properties[propName] = {
                "value": str(typeAdaptedValue),
                "type": propType
            }
            return
        ecInstance.GetValue(ecPropvalue, strAccessString)
        properties[propName] = {
            "value": str(ecPropvalue.ToString()),
            "type": propType
        }
    
    ''' 
    This method processes array properties and populates the properties dictionary.
    '''
    def WriteJson(self):
        fd, path = tempfile.mkstemp(suffix=".json")
        with io.open(path, 'w', encoding='utf-8') as buff:
            json_string = json.dumps(self.properties, indent=1)
            buff.write(json_string)
        MessageCenter.ShowInfoMessage(str('Json File Path : ' + path), '', False)

def ExractProperties():
    '''
    Extract the properties of the element with the given ID from key-in,
    or from the currently selected element if no ID is provided.
    '''
    elementList = []

    # If elementId is provided as argument
    if len(sys.argv) == 1:
        elementId = int(sys.argv[0]) 
        if elementId <= 0:
            MessageCenter.ShowErrorMessage('Invalid elementID', 'Please enter valid elementID', False )
            return 
        activeModel = ISessionMgr.ActiveDgnModelRef
        dgnModel = activeModel.GetDgnModel()
        elementHandle = EditElementHandle(elementId, dgnModel)
        if elementHandle.IsValid():
            elementList.append(elementHandle)
        else:
            MessageCenter.ShowErrorMessage('Invalid elementID', 'Please enter valid elementID', False )
            return
    else:
        # If no argument provided, use selected element
        nSelectedElements = SelectionSetManager.GetManager().NumSelected()
        if nSelectedElements > 0:
            for elementIndex in range(nSelectedElements):
                elementHandle = ElementHandle()
                SelectionSetManager.GetManager().GetElement(elementIndex, elementHandle)
                if elementHandle.IsValid():
                    elementList.append(elementHandle)
                    break

    if len(elementList) == 0:
        txt = """You can execute key-in as follows 
                pyecextractprop extractprop <Element id> OR
                select any element, then execute pyecextractprop extractprop"""
        MessageCenter.ShowErrorMessage('Invalid arguments for KeyIn', txt, False )
        return

    for elementHandle in elementList:
        extractor = ECPropertyExtractor(elementHandle.GetElementId())
        extractor.ProcessJson()

'''
Main
'''
if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ExtractProperties.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))
