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
g_propertyValueName = str('Modified Sofa')
g_eeh = EditElementHandle()

'''
Function to create item type library, item type and property
'''
def InitItemTypeLib () :
    # Define a function to initialize an item type library
    dgnFile = ISessionMgr.GetActiveDgnFile()
     # Get the active design file

    itemTypeLib = ItemTypeLibrary(g_itemTypeLibName, dgnFile, False)
     # Create an instance of ItemTypeLibrary with the given lib name and design file

    sofaItemType = itemTypeLib.AddItemType(g_itemTypeName, False)
     # Add a new item type to the library with the given name

    typeProperty = sofaItemType.AddProperty(g_typePropertyName, False)
     # Add a property to the item type with the given name

    typeProperty.SetType(CustomProperty.Type1.eString)
     # Set the data type of the property to string

    ecval = ECValue(g_propertyValueName)
     # Create an instance of ECValue with the given value name

    typeProperty.SetDefaultValue(ecval)
     # Set the default value of the property

    itemTypeLib.Write()
     # Write any changes made to the library to file

    return True
     # Return True to indicate that the initialization was successful

'''
Function to create a line element
'''
def CreateLine (dgnmodel, x1, y1, x2, y2):
     # Define a function that creates a line in a design model
    global g_eeh

     # Declare a variable g_eeh as a global variable

    segment = DSegment3d (x1, y1, 0.0, x2, y2, 0.0)
     # Create a 3D segment with the given coordinates and elevation
    if BentleyStatus.eSUCCESS != LineHandler.CreateLineElement(g_eeh, None, segment, dgnmodel.Is3d(), dgnmodel):
         # Check if the creation of the line element is successful
        g_eeh = None
        return False  # If not, set g_eeh to None and return False

    g_eeh.AddToModel()
     # Add the created line element to the model

    return True
     # Return True to indicate that the creation was successful
'''
Function to attach item type to element
'''
def AttachItemType():
     # Define a function called AttachItemType
    global g_eeh

     # Declare a variable g_eeh as a global variable

    print ('BEGIN: Attach Item type to Element \n')  # Print a message indicating the start of the function

    if True != InitItemTypeLib ():  # Check if the initialization of item type library is successful
        return  # If not, return immediately

    if False == CreateLine (ISessionMgr.ActiveDgnModelRef, 0.0, 0.0, 100.0, 0.0):  # Create a line in the design model
        return  # If creation is unsuccessful, return

    dgnFile = ISessionMgr.GetActiveDgnFile()  # Get the active design file
    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)  # Find an item type library by name in the design file
    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)  # Get the item type from the item type library by its name

    itemHost = CustomItemHost(g_eeh, False)
     # Create an instance of CustomItemHost with the given ee and a boolean value
    dgnecinstance = itemHost.ApplyCustomItem(sofaItemType)
     # Apply the custom item to the host
    dgnecinstance.SetValue(g_typePropertyName, ECValue(g_propertyValueName))  # Set the property value on the applied instance
    dgnecinstance.WriteChanges()  # Write any changes made to the instance

    print ('END: Attached successfully \n')  # Print a message indicating the end of the function

'''
Function to detach item type from element
'''
def DetachItemType():
    # Define a function called DetachItemType
    global g_eeh

    # Declare a variable g_eeh as a global variable

    print ('BEGIN: Detach Item type from Element \n')  # Print a message indicating the start of the function

    itemHost = CustomItemHost(g_eeh, False)
    # Create an instance of CustomItemHost with the given ee and a boolean value
    dgnecinstance = itemHost.GetCustomItem(g_itemTypeLibName, g_itemTypeName)
    # Retrieve a custom item from the item host using the given lib name and type name
    dgnecinstance.Delete();  # Delete the retrieved custom instance

    print ('END: Detach successfully \n')  # Print a message indicating the end of the function
if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ItemTypeAttach.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))
