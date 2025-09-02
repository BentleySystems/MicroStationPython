# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import pandas as pd


'''
Samples demonstrating how to repopulate item type data to excel
'''

def RepopulateItemsFromExcel(file_path=''):
    """
    Repopulates item type properties in a DGN file from an Excel file.
    This function reads data from an Excel file and updates the properties of 
    'Title Block' item type instances in the active DGN file. The Excel file 
    should have a column named 'Design File' to filter rows corresponding to 
    the current DGN file and a column named 'Element ID' to match instances.
    
    :param file_path: The path to the Excel file. If not provided, defaults to 
                      'TitleBlock.xlsx' in the same directory as this script.
                      (default: '')
    :type file_path: str
    
    :raises FileNotFoundError: If the specified Excel file does not exist.
    :return: None
    """
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

    if os.path.isfile(file_path):
        file = file_path
    else:
        file = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'TitleBlock.xlsx')

    # Load data from the Excel file using Pandas
    df = pd.read_excel(file, dtype=str)
    df = df[df['Design File'] == str(dgnFile.FileName)]
    if df.empty:
        return

    # Set the 'Element ID' column as the index for easier lookup later
    df.set_index(keys='Element ID', inplace=True)
    df.fillna('', inplace=True)

    # Iterate through each instance of the 'Title Block' item type found in the DGN file
    for item in DgnECManager.GetManager().FindInstances(scope, query)[0]:
        ElementId = str(item.GetAsElementInstance().ElementHandle.ElementId)
        if ElementId not in df.index:
            continue

        # Get the row from the Pandas DataFrame corresponding to this instance
        row = df.loc[ElementId]

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

if __name__ == "__main__":  # check if this script is being run directly (not imported as a module)
    RepopulateItemsFromExcel()