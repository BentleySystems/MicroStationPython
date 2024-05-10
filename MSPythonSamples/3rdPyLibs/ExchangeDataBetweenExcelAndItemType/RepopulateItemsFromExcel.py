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
    dgnFile = ISessionMgr.ActiveDgnFile
        
    itemTypeLib = ItemTypeLibrary.FindByName('Title Block', dgnFile)
    itemType = itemTypeLib.GetItemTypeByName('Title Block')
    size = itemType.GetPropertyCount()

    scope = FindInstancesScope.CreateScope (dgnFile, FindInstancesScopeOption (DgnECHostType.eAll, True))
    query = ECQuery.CreateQuery (itemTypeLib.GetInternalName(), itemType.GetInternalName())

    file = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'ItemTypes.xlsx')
    df = pd.read_excel(file, dtype=str)
    df.set_index(keys='Element ID', inplace=True)

    for item in DgnECManager.GetManager().FindInstances (scope, query)[0]:
        row = df.loc[str(item.GetAsElementInstance().ElementHandle.ElementId)]
        for i in range(size):
            typeProperty = itemType[i]
            ecVal = ECValue(row[typeProperty.Name])
            item.SetValue(typeProperty.InternalName, ecVal)
        item.WriteChanges()

RepopulateItemsFromExcel()