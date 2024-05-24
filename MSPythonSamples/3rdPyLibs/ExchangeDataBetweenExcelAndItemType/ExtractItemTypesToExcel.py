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
def ExtractItemTypesToExcel():
    dgnFile = ISessionMgr.ActiveDgnFile

    itemTypeLib = ItemTypeLibrary.FindByName('Title Block', dgnFile)
    itemType = itemTypeLib.GetItemTypeByName('Title Block')
    size = itemType.GetPropertyCount()

    scope = FindInstancesScope.CreateScope (dgnFile, FindInstancesScopeOption (DgnECHostType.eAll, True))
    query = ECQuery.CreateQuery (itemTypeLib.GetInternalName(), itemType.GetInternalName())

    cols = ['Element ID']
    df = pd.DataFrame()
    for item in DgnECManager.GetManager().FindInstances (scope, query)[0]:
        data = []
        data.append(item.GetAsElementInstance().ElementHandle.ElementId)
        for i in range(size):
            typeProperty = itemType[i]
            if len(cols) < i + 2:
                cols.append(typeProperty.Name)
            ecVal = ECValue()
            item.GetValue(ecVal, typeProperty.InternalName)
            data.append(ecVal.ToString())
        if df.empty:
            df = pd.DataFrame(columns=cols)
        df.loc[len(df)] = data

    file = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ItemTypes.xlsx')
    with pd.ExcelWriter(file) as writer:
        df.to_excel(writer, index=False)

        workbook  = writer.book
        worksheet = writer.sheets['Sheet1']
        for column in worksheet.columns:
            length = []
            for cell in column:
                cell.number_format = '@'
                length.append(len(str(cell.value)))
            worksheet.column_dimensions[column[0].column_letter].width = max(length) + 2
        workbook.save(file)

ExtractItemTypesToExcel()