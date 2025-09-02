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

''' Utility functions'''

def GetOrCreateModel(modelName, parametricForNewModal):
    """
    Retrieve an existing model by name or create a new one if it does not exist.
    This function attempts to load a model with the specified name from the active DGN file.
    If the model does not exist, it creates a new model with the given name. If the new model
    is created and the `parametricForNewModal` flag is set to True, the model is set to be of
    parametric cell type.
    
    :param modelName: The name of the model to retrieve or create.
    :type modelName: str
    :param parametricForNewModal: Flag indicating whether the new model should be parametric.
    :type parametricForNewModal: bool
    
    :return: The retrieved or newly created model.
    :rtype: Model
    """
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

def CreateNewModel(modelName):
    """
    Create a new model in the active DGN file.
    
    :param modelName: The name of the new model to be created.
    :type modelName: str
    
    :return: The newly created model.
    :rtype: DgnModel
    """
    error = MsPyDgnModelStatus ()
    newModel = ISessionMgr.GetActiveDgnFile().CreateNewModel(error, modelName, DgnModelType.eNormal, True)

    return newModel

def SetCellType(dgnModel, type):
    """
    Sets the cell type of the given DGN model to parametric.

    :param dgnModel: The DGN model whose cell type is to be set.
    :type dgnModel: DgnModel
    :param type: The type of cell to set (currently not used in the function).
    :type type: int
    """
    modelInfo = dgnModel.GetModelInfo()
    modelInfoCopy = ModelInfo.MakeCopy(modelInfo)
    modelInfoCopy.SetCellType(CellLibraryType.eParametric)
    dgnModel.SetModelInfo(modelInfoCopy)

def CreateLineAndAdd2Model(point1, point2, dgnModel, add2Model, color = 0, lineStyle = 0, elementClass = DgnElementClass.ePrimary):
    """
    Create a line element between two points and add it to the model.
    
    :param point1: The starting point of the line.
    :type point1: DPoint3d
    :param point2: The ending point of the line.
    :type point2: DPoint3d
    :param dgnModel: The design model where the line will be created.
    :type dgnModel: DgnModelRefP
    :param add2Model: Flag indicating whether to add the created line to the model.
    :type add2Model: bool
    :param color: The color of the line (default is 0).
    :type color: int, optional
    :param lineStyle: The line style of the line (default is 0).
    :type lineStyle: int, optional
    :param elementClass: The element class of the line (default is DgnElementClass.ePrimary).
    :type elementClass: DgnElementClass, optional
    
    :return: The handle to the created line element, or None if creation failed.
    :rtype: EditElementHandle or None
    """
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

def CreateLineStringAndAdd2Model(points, dgnModel, add2Model):
    """
    Create a LineString element and optionally add it to the model.
    
    :param points: List of points defining the LineString.
    :type points: list
    :param dgnModel: The DGN model to which the LineString belongs.
    :type dgnModel: DgnModel
    :param add2Model: Flag indicating whether to add the LineString to the model.
    :type add2Model: bool
    
    :return: The EditElementHandle of the created LineString element, or None if creation or addition fails.
    :rtype: EditElementHandle or None
    """
    if (dgnModel is None):
        return False

    eeh = EditElementHandle()
    if (BentleyStatus.eSUCCESS != LineStringHandler.CreateLineStringElement(eeh, None, points, dgnModel.Is3d(), dgnModel)):
        return None

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh

def CreateShapeAndAdd2Model(points, dgnModel, add2Model):
    """
    Creates a shape element from the given points and optionally adds it to the specified model.
    
    :param points: A list of points defining the shape.
    :type points: list
    :param dgnModel: The model to which the shape element will be added.
    :type dgnModel: Model
    :param add2Model: Flag indicating whether to add the shape element to the model.
    :type add2Model: bool
    
    :return: The created shape element handle if successful, otherwise None.
    :rtype: EditElementHandle or None
    """
    if (dgnModel is None):
        return False

    eeh = EditElementHandle()
    if (BentleyStatus.eSUCCESS != ShapeHandler.CreateShapeElement(eeh, None, points, dgnModel.Is3d(), dgnModel)):
        return None

    if (add2Model):
        if (BentleyStatus.eSUCCESS != eeh.AddToModel()):
            return None

    return eeh

def CreateArcAndAdd2Model(center, axis1, axis2, start, sweep, dgnModel, add2Model):
    """
    Create an arc element and optionally add it to the model.
    
    :param center: The center point of the arc.
    :type center: Point3d
    :param axis1: The first axis of the ellipse.
    :type axis1: Vector3d
    :param axis2: The second axis of the ellipse.
    :type axis2: Vector3d
    :param start: The start angle of the arc in radians.
    :type start: float
    :param sweep: The sweep angle of the arc in radians.
    :type sweep: float
    :param dgnModel: The design model to which the arc belongs.
    :type dgnModel: DgnModelRef
    :param add2Model: Flag indicating whether to add the arc to the model.
    :type add2Model: bool
    
    :return: The handle to the created arc element, or None if creation failed.
    :rtype: EditElementHandle or None
    """
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

def CreateEllipseAndAdd2Model(center, major, minor, dgnModel, add2Model, color = 0, lineStyle = 0, elementClass = DgnElementClass.ePrimary):
    """
    Create an ellipse element and optionally add it to the model.
    
    :param center: The center point of the ellipse.
    :type center: Point3d
    :param major: The major axis of the ellipse.
    :type major: float
    :param minor: The minor axis of the ellipse.
    :type minor: float
    :param dgnModel: The design model where the ellipse will be created.
    :type dgnModel: DgnModelRefP
    :param add2Model: Flag indicating whether to add the ellipse to the model.
    :type add2Model: bool
    :param color: The color of the ellipse (default is 0).
    :type color: int, optional
    :param lineStyle: The line style of the ellipse (default is 0).
    :type lineStyle: int, optional
    :param elementClass: The element class of the ellipse (default is DgnElementClass.ePrimary).
    :type elementClass: DgnElementClass, optional
    
    :return: The handle to the created ellipse element, or None if creation failed.
    :rtype: EditElementHandle or None
    """
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
