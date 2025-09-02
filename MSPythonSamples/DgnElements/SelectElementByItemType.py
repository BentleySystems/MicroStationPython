# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import ctypes
import sys

'''
This sample demonstrates how to select elements by item type
'''

def selectElementsbyItemType(inPropName, inPropValue):
    """
    Select elements by item type property.

    This function iterates through all graphical elements in the active model,
    checks their custom item properties, and adds elements to the selection set
    if they match the specified property name and value.

    :param inPropName: The name of the property to match.
    :type inPropName: str
    :param inPropValue: The value of the property to match.
    :type inPropValue: str
    """
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #name =  model.GetModelName()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    #eid 615
    selSetManager = SelectionSetManager.GetManager()

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()
        eh = ElementHandle(perElementRef)

        customItemHost = CustomItemHost(eh)
        #cItemcount = customItemHost.GetCustomItemsCount()
        instanceList   = DgnECInstanceVector()
        instanceCount = customItemHost.GetCustomItems (instanceList)
        for instance in instanceList:
            #find the item type of this EC instance
            ecClass = instance.GetEnabler().GetClass()
            properties = ecClass.GetProperties(False)

            propValue = ECValue()
            #properties = ECValuesCollection.propertyValue(instance)
            for primitiveProp in properties:
                #proptype = primitiveProp.GetType()
                accessString = primitiveProp.GetName()
                instance.GetValue(propValue, str(accessString))
                #print("Val:", accessString + propValue.ToString())
                propertyName = str(accessString)
                propertyValue = str(propValue.ToString())
                if (propertyName == inPropName and propertyValue == inPropValue):
                    selSetManager.AddElement(perElementRef,dgnModel)

    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {agenda.GetCount()} elements")
    # iterate over the selection set printing the element ids of elements in the selection set
    for i in range(agenda.GetCount()):
        editElementHandle = agenda.GetEntry(i)
        print (f"  Element ID: {editElementHandle.GetElementId()}")
    
    
#Prerequisite: Open MSPythonSamples\data\SelectExample.dgn with 'ItemType' model 
#main
if __name__ == "__main__":
    #highlight all the elements with type 
    inPropName = "StringProperty"
    inPropValue = "MyStringPropertyValue"
    selectElementsbyItemType(inPropName, inPropValue)