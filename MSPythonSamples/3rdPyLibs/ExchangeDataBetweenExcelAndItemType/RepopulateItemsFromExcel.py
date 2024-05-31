# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import pandas as pd

'''
/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                              Bentley Systems
+---------------+---------------+---------------+---------------+---------------+------*/
'''
def RepopulateItemsFromExcel():

    # Get the active DGN file from the session manager
    dgnFile = ISessionMgr.ActiveDgnFile

    # Find the item type library for 'Title Block' in the current DGN file
    itemTypeLib = ItemTypeLibrary.FindByName('Title Block', dgnFile)

    # Get the 'Title Block' item type from the item type library
    itemType = itemTypeLib.GetItemTypeByName('Title Block')

    # Get the size of the property count for the 'Title Block' item type
    size = itemType.GetPropertyCount()

    # Create a scope to find instances in the DGN file
    scope = FindInstancesScope.CreateScope(dgnFile, FindInstancesScopeOption(DgnECHostType.eAll, True))

    # Create an EC query to find instances of the 'Title Block' item type
    query = ECQuery.CreateQuery(itemTypeLib.GetInternalName(), itemType.GetInternalName())

    # Load data from the Excel file using Pandas
    file = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ItemTypes.xlsx')
    df = pd.read_excel(file, dtype=str)

    # Set the 'Element ID' column as the index for easier lookup later
    df.set_index(keys='Element ID', inplace=True)

    # Iterate through each instance of the 'Title Block' item type found in the DGN file
    for item in DgnECManager.GetManager().FindInstances(scope, query)[0]:

        # Get the row from the Pandas DataFrame corresponding to this instance
        row = df.loc[str(item.GetAsElementInstance().ElementHandle.ElementId)]

        # Iterate through each property of the 'Title Block' item type
        for i in range(size):

            # Get the current property
            typeProperty = itemType[i]

            # Get the value from the Excel file and convert it to an ECValue
            ecVal = ECValue(row[typeProperty.Name])

            # Set the value of the current property for this instance
            item.SetValue(typeProperty.InternalName, ecVal)

        # Write any changes made to the instance back to the DGN file
        item.WriteChanges()