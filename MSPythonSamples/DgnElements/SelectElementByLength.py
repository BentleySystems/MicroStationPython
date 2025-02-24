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
Function to select elements by its length
    inputLength : int      Length
'''
def selectElementsbyLength(inputLength):
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
        eleType = eh.GetElementType()
        if (isGraphics and not(isInvisible) and (eleType == 3 or eleType == 4) ):
            curve = ICurvePathQuery.ElementToCurveVector(eh)
            # Accept elements that are open paths with one or more linear segments (ex. line or linestring).
            if curve==None or (not curve.IsOpenPath()):
                print("Not a Line or LineString")

            primitiveType = curve.HasSingleCurvePrimitive()
            if primitiveType == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_Line or primitiveType == ICurvePrimitive.eCURVE_PRIMITIVE_TYPE_LineString:
                modelInfo = dgnModel.GetModelInfo()
                scaleFactor = modelInfo.UorPerMeter
                lineLength = curve.Length()/scaleFactor
                print("line", lineLength)
                if(inputLength > lineLength):
                    selSetManager.AddElement(perElementRef,dgnModel)         

'''
Prerequisite: Open SelectExample.dgn with '2D Metric Design' 
'''
#main
if __name__ == "__main__":
    #highlight all the elements with type 
    #2-D/3-D Line Element (type 3)
    #2-D/3-D Line String Element (type 4)
    #2-D/3-D Ellipse Element (type 15)
    #2-D/3-D Arc Element (type 16)
    inputLength = 10.0
    selectElementsbyLength(inputLength)