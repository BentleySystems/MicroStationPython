# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import ctypes
import sys

'''
Function to select elements by its item type data
    inPropName  : str      Property Name
    inPropValue : str      Property Value
'''
def selectElementsbyItemType(inPropName, inPropValue):
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

'''
Prerequisite: Open MSPythonSamples\data\SelectExample.dgn with 'ItemType' model 
'''
#main
if __name__ == "__main__":
    #highlight all the elements with type 
    inPropName = "StringProperty"
    inPropValue = "MyStringPropertyValue"
    selectElementsbyItemType(inPropName, inPropValue)