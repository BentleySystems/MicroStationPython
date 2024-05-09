# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2022 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import os

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

g_itemTypeLibName = str('Imported Furniture')
g_itemTypeName = str('Sofa')
g_typePropertyName = str('Type')
g_propertyValueName = str('Decorated')
g_propertyValueNewName = str('Newly Decorated')

'''
Function to create item type library, item type and property
'''
def CreateItemTypeLibraryItemTypeAndProperty ():
    print ('BEGIN: Create Item type library: Imported Furniture, Item type: Sofa, property: Type \n')

    dgnFile = ISessionMgr.GetActiveDgnFile()
    itemTypeLib = ItemTypeLibrary(g_itemTypeLibName, dgnFile, False)
    sofaItemType = itemTypeLib.AddItemType(g_itemTypeName, False)
    typeProperty = sofaItemType.AddProperty(g_typePropertyName, False)
    typeProperty.SetType(CustomProperty.Type1.eString)
    ecval = ECValue(g_propertyValueName)
    typeProperty.SetDefaultValue(ecval)
    itemTypeLib.Write()
    
    print ('END: Created Successfully \n')

'''
Function to read the item type property default value
'''
def ReadItemTypePropertyDefaultValue ():
    print ('BEGIN: Read value of Item type property \n')

    dgnFile = ISessionMgr.GetActiveDgnFile()
    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)
    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)
    typeProperty = sofaItemType.GetPropertyByName(g_typePropertyName)
    ecval = ECValue()
    typeProperty.GetDefaultValue(ecval)

    print ('END: Read successfully! ' + 'Value of the property is: ' + ecval.String + '\n')

'''
Function to update the item type property default value
'''
def UpdateTypePropertyDefaultValue ():
    print ('BEGIN: Update value of Item type property \n')

    dgnFile = ISessionMgr.GetActiveDgnFile()
    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)
    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)
    typeProperty = sofaItemType.GetPropertyByName(g_typePropertyName)
    newECVal = ECValue(g_propertyValueNewName)
    typeProperty.SetDefaultValue(newECVal)
    itemTypeLib.Write()

    print ('END: Updated successfully! ' + 'New Value of the property is:' + newECVal.String + '\n')

'''
Function to delete the item type library, item type and property
'''
def DeleteItemTypeLibraryItemAndProperty ():
    print ('BEGIN: Delete property, item type and Item type library \n')

    dgnFile = ISessionMgr.GetActiveDgnFile()
    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)
    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)
    typeProperty = sofaItemType.GetPropertyByName(g_typePropertyName)

    sofaItemType.RemoveProperty(typeProperty.GetId())
    itemTypeLib.RemoveItemType(sofaItemType.GetId())
    itemTypeLib.Delete();

    print ('END: Deleted successfully! \n')

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ItemTypeCRUD.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))    

