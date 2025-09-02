# $Copyright:(c) 2025 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from MSPyECObjects import *
import sys

"""
This script demonstrates the process of querying and selecting elements from a DGN model using Bentley's MicroStation API.
It includes functions for creating host specifications and executing EC queries based on various criteria.
Users can uncomment specific query examples to filter elements based on properties such as
element description, color, weight, perimeter, volume, and level.

Below are some example queries that can be utilized to filter elements:

    - queryString = 'Element.ElementDescription = "Line String" And Element.TotalLength > 20000000.000 And Element.Color = "4"'

    - queryString = 'Element.Weight < 8'

    - queryString = 'Element.Color = "5" And Element.TotalLength < 20000000.000'

    - queryString = 'Element.Weight > 4 And Element.Weight < 12 And Element.Color = "4"'

    - queryString = 'Element.ElementDescription = "Circle"'

    - queryString = 'Element.Perimeter > 4000000.000 And Element.Weight = 9'

    - queryString = 'Element.ElementDescription = "Circle" And Element.Color = "5"'

    - queryString = 'Element.Color = "5" And Element.Perimeter < 21000000.000'

    - queryString = 'Element.Weight > 4 And Element.Weight < 12 And Element.Color = "4"'

    - queryString = 'Element.Color = "4" And Element.Volume > 40000000000000000000.000'

    - queryString = 'Element.Color = "4"'

    - queryString = 'Element.Level = "Default"'

    - queryString = 'Element.ElementDescription = "Cylinder"'

    - queryString = 'Element.Volume > 40000000000000000000.000 And Element.Weight > 6'

    - queryString = 'Element.Color = "1"'

    - queryString = 'Element.Color = "1" And Element.Volume < 30000000000000000000.000'

    - queryString = 'Element.Weight > 4 And Element.Weight < 12 And Element.Color = "4"'

    - queryString = "Element.Perimeter != null"

    The below query filters elements based on a substring match in the property value.

        - query.SetPropertyValuePreFilter(ECSubstringPropertyValueFilter("Door"))

        - query.SetPropertyValuePreFilter(ECSubstringPropertyValueFilter("Circle"))
"""

def GetHostSpecContext(hostType, primaryClassFullName, relatedFullClassName="Bentley_Standard_Classes:AnyClass"):
    """
    Creates and returns a DgnECHostSpecificationsContext object based on the provided host type, 
    primary class full name, and optionally a related full class name.
    :param hostType: The type of the host, specified as a value from the DgnECHostType enumeration.
                     Valid values include:
                     - DgnECHostType.eElement: Host is an element.
                     - DgnECHostType.eModel: Host is a model.
                     - DgnECHostType.eFile: Host is a file.
                     - DgnECHostType.eDesignLink: Host is a design link.
    :type hostType: DgnECHostType
    :param primaryClassFullName: The fully qualified name of the primary class.
    :type primaryClassFullName: str
    :param relatedFullClassName: The fully qualified name of the related class. Defaults to 
                                 "Bentley_Standard_Classes:AnyClass".
    :type relatedFullClassName: str, optional
    :raises ValueError: If an invalid hostType is provided.
    :return: A context object containing the host specifications.
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

def queryFunction():
    """
    Queries and selects elements in the active DGN model based on specific criteria.
    This function performs the following steps:
    1. Creates a query scope for the active DGN model.
    2. Constructs an ECQuery to search for elements of a specific type (e.g., "Line").
    3. Retrieves instances matching the query and extracts their element IDs.
    4. Iterates through graphical elements in the model and adds matching elements to the selection set.
    5. Prints the IDs of the selected elements.
    :return: None
    """
    dgnModel = ISessionMgr.ActiveDgnModel
    scope = FindInstancesScope.CreateScope(dgnModel, FindInstancesScopeOption())
    query = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)
    spec = GetHostSpecContext(DgnECHostType.eElement, "DgnElementSchema:Element")

    queryString = 'Element.ElementDescription = "Line"'
    crit = HostExpressionCriterion(queryString, "Element", spec)
    query.SetWhereCriterion(crit)

    primaryInstances = DgnECManager.GetManager().FindInstances(scope, query)
    elementIdArray = []
    for instance in primaryInstances[0]:
        elementIdArray.append(instance.InstanceHost.ElementHandle.ElementId)
    
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()
        if elementId in elementIdArray:
            selSetManager.AddElement(perElementRef, dgnModel)

    # Print the selected element IDs
    print("Selected Element IDs:", ", ".join(map(str, elementIdArray)))
    return

#main
if __name__ == "__main__":
    queryFunction()