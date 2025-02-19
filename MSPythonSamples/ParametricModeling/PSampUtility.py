# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''
Get or create model
'''
def GetOrCreateModel(modelName, parametricForNewModal):
    dgnFile = ISessionMgr.GetActiveDgnFile()

    # Load root model with the model name
    model, status = dgnFile.LoadRootModelById(dgnFile.FindModelIdByName(modelName), True, False, True)

    # Create new model with given name if not exist
    if (model is None):
        model = CreateNewModel(modelName)
        # Set cell type for the model
        if (model is not None and parametricForNewModal):
            SetCellType(model, CellLibraryType.eParametric)

    return model

'''
Create new model
'''
def CreateNewModel(modelName):
    error = MsPyDgnModelStatus ()
    newModel = ISessionMgr.GetActiveDgnFile().CreateNewModel(error, modelName, DgnModelType.eNormal, True)

    return newModel

'''
Set cell type
'''
def SetCellType(dgnModel, type):
    modelInfo = dgnModel.GetModelInfo()
    modelInfoCopy = ModelInfo.MakeCopy(modelInfo)
    modelInfoCopy.SetCellType(CellLibraryType.eParametric)
    dgnModel.SetModelInfo(modelInfoCopy)

'''
Function to create line and add it to model
'''
def CreateLineAndAdd2Model(point1, point2, dgnModel, add2Model, color = 0, lineStyle = 0, elementClass = DgnElementClass.ePrimary):
    if (dgnModel is None):
        return None

    # Create line element
    eeh = EditElementHandle()
    if (BentleyStatus.eSUCCESS != LineHandler.CreateLineElement (eeh, None, DSegment3d(point1, point2), dgnModel.Is3d(), dgnModel)):
        return None

    # Set element properties
    propertiesSetter = ElementPropertiesSetter()
    propertiesSetter.SetColor(color)
    propertiesSetter.SetLinestyle(lineStyle, None)
    propertiesSetter.SetElementClass(elementClass)
    propertiesSetter.Apply(eeh)

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh

'''
Function to create line string and add it to model
'''
def CreateLineStringAndAdd2Model(points, dgnModel, add2Model):
    if (dgnModel is None):
        return False

    eeh = EditElementHandle()
    if (BentleyStatus.eSUCCESS != LineStringHandler.CreateLineStringElement(eeh, None, points, dgnModel.Is3d(), dgnModel)):
        return None

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh

'''
Function to create shape and add it to model
'''
def CreateShapeAndAdd2Model(points, dgnModel, add2Model):
    if (dgnModel is None):
        return False

    eeh = EditElementHandle()
    if (BentleyStatus.eSUCCESS != ShapeHandler.CreateShapeElement(eeh, None, points, dgnModel.Is3d(), dgnModel)):
        return None

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh

'''
Function to create arc and add it to model
'''
def CreateArcAndAdd2Model(center, axis1, axis2, start, sweep, dgnModel, add2Model):
    if (dgnModel is None):
        return None

    # Create ellipse element
    eeh = EditElementHandle()
    if (BentleyStatus.eSUCCESS != ArcHandler.CreateArcElement(eeh, None, center, axis1, axis2, 0.0, start, sweep, dgnModel.Is3d(), dgnModel)):
        return None

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh

'''
Function to create ellipse and add it to model
'''
def CreateEllipseAndAdd2Model(center, major, minor, dgnModel, add2Model, color = 0, lineStyle = 0, elementClass = DgnElementClass.ePrimary):
    if dgnModel is None:
        return None

    # Create ellipse element
    eeh = EditElementHandle()
    if(BentleyStatus.eSUCCESS != EllipseHandler.CreateEllipseElement(eeh, None, center, major, minor, 0, dgnModel.Is3d(), dgnModel)):
        return None

    # Set element properties
    propertiesSetter = ElementPropertiesSetter()
    propertiesSetter.SetColor(color)
    propertiesSetter.SetLinestyle(lineStyle, None)
    propertiesSetter.SetElementClass(elementClass)
    propertiesSetter.Apply(eeh)

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh
