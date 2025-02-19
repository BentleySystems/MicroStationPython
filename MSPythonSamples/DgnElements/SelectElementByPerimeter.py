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
Function to select elements by its perimeter
    inputperimeter : float      perimeter
'''
def selectElementsbyPerimeter(inputPerimeter):
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
                instance.GetValue(propValue, 'Perimeter', 0)
                if (not propValue.IsNull()):                   
                        #UOR value converted to M , 10000
                        modelInfo = dgnModel.GetModelInfo()
                        scaleFactor = modelInfo.UorPerMeter
                        perimeter = propValue.GetDouble()/scaleFactor
                        print("Perimeter:", propValue.GetDouble()/scaleFactor)
                        if (inputPerimeter > perimeter):
                            selSetManager.AddElement(perElementRef,dgnModel)
                        break
                else:
                     break
'''
Prerequisite: Open MSPythonSamples\data\SelectExample.dgn with '2D Metric Design' model 
'''
#main
if __name__ == "__main__":
    #highlight all the elements with type 
    #2-D/3-D Line Element (type 3)
    #2-D/3-D Line String Element (type 4)
    #2-D/3-D Ellipse Element (type 15)
    #2-D/3-D Arc Element (type 16)
    inputPerimeter = 100.0  #consider values in M
    selectElementsbyPerimeter(inputPerimeter)