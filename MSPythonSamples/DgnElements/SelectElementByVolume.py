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
This sample demonstrates how to select elements based on their volume.
'''

def selectElementsbyVolume(inputVolume):
    """
    Select elements from the active model based on their volume.

    This function iterates through all graphical elements in the active model,
    calculates their volume, and adds them to the selection set if their volume
    is less than the specified input volume.

    :param inputVolume: The volume threshold for selecting elements. Elements with a volume
                        less than this value will be added to the selection set.
    :type inputVolume: float
    """
    #Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    #Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
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
                instance.GetValue(propValue, 'Volume', 0)
                if (not propValue.IsNull()):                   
                        #UOR value converted to CU M , 10000*10000*10000
                        modelInfo = dgnModel.GetModelInfo()
                        scaleFactor = modelInfo.UorPerMeter
                        volume = propValue.GetDouble()/(scaleFactor * scaleFactor * scaleFactor)
                        print("Volume:", propValue.GetDouble()/(scaleFactor * scaleFactor * scaleFactor))
                        if (inputVolume > volume):
                            selSetManager.AddElement(perElementRef,dgnModel)
                        break
                else:
                     break

    #Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print (f"Selected {len (agenda)} elements")
    # iterate using __iter__ over the selection set printing the element ids of elements in the selection set
    for editElementHandle in agenda:
        print(f"  Element ID: {editElementHandle.GetElementId()}")
        
#Prerequisite: Open MSPythonSamples\\data\\SelectExample.dgn with '3D Data' model
#main
if __name__ == "__main__":
    #highlight all the elements with type 
    #2-D/3-D Line Element (type 3)
    #2-D/3-D Line String Element (type 4)
    #2-D/3-D Ellipse Element (type 15)
    #2-D/3-D Arc Element (type 16)
    inputVolume = 100.0  #consider values in CU M
    selectElementsbyVolume(inputVolume)