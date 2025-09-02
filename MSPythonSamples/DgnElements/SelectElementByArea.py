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
This sample demonstrates how to select elements by area
'''

def selectElementsbyArea(inputArea):
    """
    unction to select elements by its area
    :param inputArea: Area
    :type float: inputArea

    :returns: None
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
        eeh = EditElementHandle(perElementRef, dgnModel)
        eh = ElementHandle(perElementRef)

        msElement = MSElement()
        msElement = eeh.GetElement ()

        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible
        propValue = ECValue()
        if(isGraphics and not(isInvisible) ):
             dgnECManager = DgnECManager.GetManager()
             scopeOption = FindInstancesScopeOption()
             scope = FindInstancesScope.CreateScope(eh, scopeOption)
             allQuery = ECQuery.CreateQuery (ECQueryProcessFlags.eECQUERY_PROCESS_SearchAllIntrinsic)

             instanceItr = dgnECManager.FindInstances(scope, allQuery)
             for instance in instanceItr[0]:
                instance.GetValue(propValue, 'EnclosedArea', 0)
                if (not propValue.IsNull()):
                    #UOR value converted to SQ M , 10000*10000
                    modelInfo = dgnModel.GetModelInfo()
                    scaleFactor = modelInfo.UorPerMeter
                    area = propValue.GetDouble()/(scaleFactor * scaleFactor)
                    print("EnclosedArea:", propValue.GetDouble()/(scaleFactor * scaleFactor))
                    if (inputArea > area):
                        selSetManager.AddElement(perElementRef,dgnModel)
                        print (f"Element ID: {perElementRef.GetElementId ()} Area: {area}")
                    break
                else:
                     break
    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {agenda.GetCount()} elements")

    unique_element_types = set()
    # iterate over the selection set printing the element ids of elements in the selection set
    for i in range(agenda.GetCount()):
        editElementHandle = agenda.GetEntry(i)
        element_type = editElementHandle.ElementType
        unique_element_types.add(element_type)
        elementRange = DRange3d()
        center = DPoint3d ()
        DisplayHandler.Instance.CalcElementRange(editElementHandle, elementRange, None)
        center = elementRange.high - elementRange.low
        print (f"  Element ID: {editElementHandle.GetElementId()}, Range : {elementRange} Center :{center}")
    
    print("Unique Element Types:", list(unique_element_types)) 
#Prerequisite: Open MSPythonSamples\data\SelectExample.dgn with '2D Metric Design' model 
#main
if __name__ == "__main__":
    #highlight all the elements with type 
    #2-D/3-D Line Element (type 3)
    #2-D/3-D Line String Element (type 4)
    #2-D/3-D Ellipse Element (type 15)
    #2-D/3-D Arc Element (type 16)
    inputArea = 200000.0  #consider values in SQ M
    selectElementsbyArea(inputArea)