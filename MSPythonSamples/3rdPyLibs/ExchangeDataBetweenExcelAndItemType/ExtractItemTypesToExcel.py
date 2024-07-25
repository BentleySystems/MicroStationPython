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
Running this sample needs to open ExchangeDataBetweenExcelAndItemType.dgn or other design
file includes title block item.
Command file 'Extract Item Types to Excel.txt' and 'Repopulate Items from Excel.txt' would
be used within Batch Processor.
'Extract Item Types to Excel.txt' would extract title block information to an Excel file.
User can edit the title block information in Excel, then use 'Repopulate Items from Excel.txt'
to re-populate the title block Item Types with the new information. 
'''

'''
/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                              Bentley Systems
+---------------+---------------+---------------+---------------+---------------+------*/
'''
def ExtractItemTypesToExcel(file_path=''):
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

    # Set the file path for the output Excel file
    if file_path:
        file = file_path
    else:
        file = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'TitleBlock.xlsx')

    if os.path.isfile(file):
        df = pd.read_excel(file, dtype=str)
        df = df[df['Design File'] != str(dgnFile.FileName)]
        df = df.reset_index(drop=True)
        cols = df.columns.tolist()
    else:
        # Initialize a list to store column names for the Excel file
        cols = ['Element ID', 'Design File']

        # Initialize a Pandas DataFrame to store data
        df = pd.DataFrame()

    # Iterate through each instance of the 'Title Block' item type found in the DGN file
    for item in DgnECManager.GetManager().FindInstances(scope, query)[0]:
        # Initialize an empty list to store data for this instance
        data = []

        # Get the element ID from the current instance
        data.append(item.GetAsElementInstance().ElementHandle.ElementId)
        data.append(dgnFile.FileName)

        # Iterate through each property of the 'Title Block' item type
        for i in range(size):
            # Get the current property and add its name to the column list if it's not already there
            typeProperty = itemType[i]
            if len(cols) < i + 3:
                cols.append(typeProperty.Name)

            # Get the value of the current property from the instance
            ecVal = ECValue()
            item.GetValue(ecVal, typeProperty.InternalName)

            # Add the property value to the data list as a string
            data.append(ecVal.ToString())

        # If this is the first instance, create an empty DataFrame with the column names
        if df.empty:
            df = pd.DataFrame(columns=cols)

        # Append the data for this instance to the DataFrame
        df.loc[len(df)] = data

    # Open the Excel file in write mode using Pandas
    with pd.ExcelWriter(file) as writer:
        # Write the DataFrame to the Excel file
        df.to_excel(writer, index=False)

        # Get a reference to the workbook and worksheet
        workbook  = writer.book
        worksheet = writer.sheets['Sheet1']

        # Iterate through each column in the worksheet
        for column in worksheet.columns:
            # Initialize an empty list to store cell lengths
            length = []

            # Iterate through each cell in the column
            for cell in column:
                # Set the number format of the cell to display as text
                cell.number_format = '@'
                
                # Calculate the length of the cell's value as a string
                length.append(len(str(cell.value)))

            # Get the maximum length and add 2 to set the column width
            worksheet.column_dimensions[column[0].column_letter].width = max(length) + 2

        # Save the workbook (and therefore the entire Excel file)
        workbook.save(file)

if __name__ == "__main__":  # check if this script is being run directly (not imported as a module)
    ExtractItemTypesToExcel()