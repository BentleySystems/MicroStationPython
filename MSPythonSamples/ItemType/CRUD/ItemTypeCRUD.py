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
def CreateItemTypeLibraryItemTypeAndProperty () :
    # Define a function to create an item type library, item type, and property
    print ('BEGIN: Create Item type library: Imported Furniture, Item type: Sofa, property: Type \n')  # Print a message indicating the start of the function

    dgnFile = ISessionMgr.GetActiveDgnFile()  # Get the active design file
        # Declare a variable dgnFile as the retrieved design file

    itemTypeLib = ItemTypeLibrary(g_itemTypeLibName, dgnFile, False)   # Create an instance of ItemTypeLibrary with the given name and design file
        # Declare a variable itemTypeLib as the created item type library

    sofaItemType = itemTypeLib.AddItemType(g_itemTypeName, False)  # Add an item type to the library
        # Declare a variable sofaItemType as the added item type

    typeProperty = sofaItemType.AddProperty(g_typePropertyName, False)   # Add a property to the item type
        # Declare a variable typeProperty as the added property

    typeProperty.SetType(CustomProperty.Type1.eString)  # Set the type of the property
        # Update the type of the property

    ecval = ECValue(g_propertyValueName)   # Create an instance of ECValue with the given name
        # Declare a variable ecval as the created ECValue instance

    typeProperty.SetDefaultValue(ecval)   # Set the default value of the property
        # Update the default value of the property

    itemTypeLib.Write()  # Write any changes made to the item type library to file
        # Save the updated item type library

    print ('END: Created Successfully \n')  # Print a message indicating that the creation was successful

'''
Function to read the item type property default value
'''
def ReadItemTypePropertyDefaultValue () :
      # Define a function to read the default value of an item type property
    print ('BEGIN: Read value of Item type property \n')  # Print a message indicating the start of the function

    dgnFile = ISessionMgr.GetActiveDgnFile()  # Get the active design file
       # Declare a variable dgnFile as the retrieved design file

    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)  # Find an item type library by name in the design file
       # Declare a variable itemTypeLib as the found item type library

    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)  # Get the item type from the item type library by its name
       # Declare a variable sofaItemType as the retrieved item type

    typeProperty = sofaItemType.GetPropertyByName(g_typePropertyName)  # Get the property of the item type by its name
       # Declare a variable typeProperty as the retrieved property

    ecval = ECValue()  # Create an instance of ECValue
       # Declare a variable ecval as the created ECValue instance

    typeProperty.GetDefaultValue(ecval)  # Get the default value of the property and store it in the ecval instance
       # Read the default value of the property

    print ('END: Read successfully! ' + 'Value of the property is: ' + ecval.String + '\n')  # Print a message indicating that the read operation was successful

'''
Function to update the item type property default value
'''
def UpdateTypePropertyDefaultValue () :
     # Define a function to update the default value of an item type property
    print ('BEGIN: Update value of Item type property \n')  # Print a message indicating the start of the function

    dgnFile = ISessionMgr.GetActiveDgnFile()  # Get the active design file
      # Declare a variable dgnFile as the retrieved design file

    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)  # Find an item type library by name in the design file
      # Declare a variable itemTypeLib as the found item type library

    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)  # Get the item type from the item type library by its name
      # Declare a variable sofaItemType as the retrieved item type

    typeProperty = sofaItemType.GetPropertyByName(g_typePropertyName)  # Get the property of the item type by its name
      # Declare a variable typeProperty as the retrieved property

    newECVal = ECValue(g_propertyValueNewName)  # Create an instance of ECValue with the given new value name
      # Declare a variable newECVal as the created ECValue instance

    typeProperty.SetDefaultValue(newECVal)  # Set the default value of the property to the new value
      # Update the default value of the property

    itemTypeLib.Write()  # Write any changes made to the item type library to file
      # Save the updated item type library

    print ('END: Updated successfully! ' + 'New Value of the property is:' + newECVal.String + '\n')  # Print a message indicating that the update was successful
'''
Function to delete the item type library, item type and property
'''
def DeleteItemTypeLibraryItemAndProperty():
     # Define a function to delete an item type library, its property and the corresponding item
    print ('BEGIN: Delete property, item type and Item type library \n')  # Print a message indicating the start of the function

    dgnFile = ISessionMgr.GetActiveDgnFile()  # Get the active design file
     # Declare a variable dgnFile as the active design file

    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)  # Find an item type library by name in the design file
     # Declare a variable itemTypeLib as the found item type library

    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)  # Get the item type from the item type library by its name
     # Declare a variable sofaItemType as the retrieved item type

    typeProperty = sofaItemType.GetPropertyByName(g_typePropertyName)  # Get the property of the item type by its name
     # Declare a variable typeProperty as the retrieved property

    sofaItemType.RemoveProperty(typeProperty.GetId())  # Remove the property from the item type
     # Remove the property with the given ID from the item type

    itemTypeLib.RemoveItemType(sofaItemType.GetId())  # Remove the item type from the library
     # Remove the item type with the given ID from the library

    itemTypeLib.Delete();  # Delete the item type library
     # Declare a variable as the deleted item type library

    print ('END: Deleted successfully! \n')  # Print a message indicating that the deletion was successful

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ItemTypeCRUD.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))    

