# $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import sys

'''
This script analyzes the active DGN model to identify and categorize different types of cells 
(graphical, point, and parametric) and prints their respective counts.
'''

def GetHostSpecContext(hostType, primaryClassFullName, relatedFullClassName="Bentley_Standard_Classes:AnyClass"):
    """
    Creates and returns a `DgnECHostSpecificationsContext` object based on the provided host type, 
    primary class full name, and optionally a related full class name.
    :param hostType: The type of the host, specified as a `DgnECHostType` enumeration value. 
                     Valid values are `eElement`, `eModel`, `eFile`, and `eDesignLink`.
    :type hostType: DgnECHostType
    :param primaryClassFullName: The fully qualified name of the primary class.
    :type primaryClassFullName: str
    :param relatedFullClassName: The fully qualified name of the related class. Defaults to 
                                 "Bentley_Standard_Classes:AnyClass".
    :type relatedFullClassName: str, optional
    :raises ValueError: If an invalid `hostType` is provided.
    :return: A `DgnECHostSpecificationsContext` object containing the host specifications.
    :rtype: DgnECHostSpecificationsContext
    """
    classname = None
    if hostType == DgnECHostType.eElement:
        classname = "OnSameElement"
    elif hostType == DgnECHostType.eModel:
        classname = "OnSameModel"
    elif hostType == DgnECHostType.eFile:
        classname = "OnSameFile"
    elif hostType == DgnECHostType.eDesignLink:
        classname = "OnSameLinkNode"
    else:
        raise ValueError("Invalid DgnECHostType")

    hostSpec = DgnECHostSpecification()
    hostSpec.GetPrimaryClasses().append(SchemaNameClassNamePair(WString(primaryClassFullName)))
    hostSpec.GetRelationships().append(
        DgnECHostRelationshipSpecification(
        SchemaNameClassNamePair("DgnContentRelationshipSchema", classname),
        SchemaNameClassNamePair(WString(relatedFullClassName))
        )
    )
    hostSpecs = DgnECHostSpecificationArray()
    hostSpecs.append(hostSpec)
    return DgnECHostSpecificationsContext(hostSpecs)

def cellSum():
    """
    Identifies and categorizes cells in the active DGN model into graphical cells, 
    point cells, and parametric cells, and prints their respective counts.
    The function performs the following steps:
    - Retrieves the active DGN model reference.
    - Queries the model for graphical cells, point cells, and parametric cells 
      using specific criteria.
    - Categorizes the elements based on their cell type.
    - Prints the count of each cell type.
    
    :raises Exception: If no active DGN model is selected.
    :return: None
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)

    graphicalCells = []
    pointCells = []
    parametricCells = []
    
    scope = FindInstancesScope.CreateScope(dgnModel, FindInstancesScopeOption())
    spec = GetHostSpecContext(DgnECHostType.eModel, "DgnElementSchema:Element")
    
    # Query for graphical cells.
    graphicalCellsQuery = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
    queryString = 'Element.CellType = 0'
    crit = HostExpressionCriterion(queryString, "Element", spec)
    graphicalCellsQuery.SetWhereCriterion(crit)

    primaryInstances = DgnECManager.GetManager().FindInstances(scope, graphicalCellsQuery)
    graphicalCellsElementIdArray = set()
    for instance in primaryInstances[0]:
        graphicalCellsElementIdArray.add(instance.InstanceHost.ElementHandle.ElementId)
    graphicalElements = dgnModel.GetGraphicElements()
    
    # Query for point cells.
    pointCellsQuery = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
    queryString = 'Element.CellType = 1'
    crit = HostExpressionCriterion(queryString, "Element", spec)
    pointCellsQuery.SetWhereCriterion(crit)

    primaryInstances = DgnECManager.GetManager().FindInstances(scope, pointCellsQuery)
    pointCellsElementIdArray = set()
    for instance in primaryInstances[0]:
        pointCellsElementIdArray.add(instance.InstanceHost.ElementHandle.ElementId)
    graphicalElements = dgnModel.GetGraphicElements()
    
    # Query for parametric cells.
    parametricCellsQuery = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
    parametricCellsQuery.SetPropertyValuePreFilter(ECSubstringPropertyValueFilter("Parametric Cell"))

    primaryInstances = DgnECManager.GetManager().FindInstances(scope, parametricCellsQuery)
    parametricCellsElementIdArray = set()
    for instance in primaryInstances[0]:
        parametricCellsElementIdArray.add(instance.InstanceHost.ElementHandle.ElementId)
    graphicalElements = dgnModel.GetGraphicElements()

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()
        if elementId in parametricCellsElementIdArray:
            parametricCells.append(perElementRef)
        elif elementId in pointCellsElementIdArray:
            pointCells.append(perElementRef)
        elif elementId in graphicalCellsElementIdArray:
            graphicalCells.append(perElementRef)
    
    print(f"Graphical Cells Count: {len(graphicalCells)}")
    print(f"Point Cells Count: {len(pointCells)}")
    print(f"Parametric Cells Count: {len(parametricCells)}")
    return

if __name__ == "__main__":
    cellSum()