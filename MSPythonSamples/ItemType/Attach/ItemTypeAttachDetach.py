# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''
This sample demonstrates how to add key-in commands and use those commands to attach or detach item type
'''

g_itemTypeLibName = str('Imported Furniture')
g_itemTypeName = str('Sofa')
g_typePropertyName = str('Type')
g_propertyValueName = str('Modified Sofa')
g_eeh = EditElementHandle()

def InitItemTypeLib () :
    """
    Initialize an item type library, item type, and property.

    This function performs the following steps:
    
    1. Retrieves the active design file using `ISessionMgr.GetActiveDgnFile()`.
    2. Creates an instance of `ItemTypeLibrary` with the global item type library name (`g_itemTypeLibName`), the active design file, and a boolean flag set to `False`.
    3. Adds a new item type to the library using the global item type name (`g_itemTypeName`) and a boolean flag set to `False`.
    4. Adds a property to the newly created item type using the global type property name (`g_typePropertyName`) and a boolean flag set to `False`.
    5. Sets the data type of the property to string using `CustomProperty.Type1.eString`.
    6. Creates an instance of `ECValue` with the global property value name (`g_propertyValueName`).
    7. Sets the default value of the property to the created `ECValue` instance.
    8. Writes any changes made to the library to the file.
    9. Returns `True` to indicate that the initialization was successful.

    :returns: `True` if the initialization was successful.
    :rtype: bool
    """
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

def CreateLine (dgnmodel, x1, y1, x2, y2):
    """
    Create a line element in a design model.

    This function performs the following steps:

    1. Declares the variable `g_eeh` as a global variable.
    2. Creates a 3D segment (`DSegment3d`) with the given coordinates and elevation set to 0.0.
    3. Attempts to create a line element using `LineHandler.CreateLineElement()`.
       - If the creation is unsuccessful, sets `g_eeh` to `None` and returns `False`.
    4. Adds the created line element to the model using `g_eeh.AddToModel()`.
    5. Returns `True` to indicate that the creation was successful.

    :param dgnmodel: The design model where the line element will be created.
    :type dgnmodel: DesignModel
    :param x1: The x-coordinate of the start point of the line.
    :type x1: float
    :param y1: The y-coordinate of the start point of the line.
    :type y1: float
    :param x2: The x-coordinate of the end point of the line.
    :type x2: float
    :param y2: The y-coordinate of the end point of the line.
    :type y2: float
    :returns: `True` if the line element creation was successful, `False` otherwise.
    :rtype: bool
    """
    
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

def AttachItemType():
    """
    Attach an item type to an element.

    This function performs the following steps:

    1. Declares the variable `g_eeh` as a global variable.
    2. Prints a message indicating the start of the function.
    3. Initializes the item type library by calling `InitItemTypeLib()`.
       - If the initialization is unsuccessful, the function returns immediately.
    4. Creates a line element in the active design model by calling `CreateLine()`.
       - If the creation is unsuccessful, the function returns immediately.
    5. Retrieves the active design file using `ISessionMgr.GetActiveDgnFile()`.
    6. Finds the item type library by name in the design file using `ItemTypeLibrary.FindByName()`.
    7. Gets the item type from the item type library by its name using `itemTypeLib.GetItemTypeByName()`.
    8. Creates an instance of `CustomItemHost` with the global element handle (`g_eeh`) and a boolean flag set to `False`.
    9. Applies the custom item to the host using `itemHost.ApplyCustomItem()`.
    10. Sets the property value on the applied instance using `dgnecinstance.SetValue()`.
    11. Writes any changes made to the instance using `dgnecinstance.WriteChanges()`.
    12. Prints a message indicating the end of the function.

    :returns: None
    """
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

def DetachItemType():
    """
    Detach an item type from an element.

    This function performs the following steps:

    1. Declares the variable `g_eeh` as a global variable.
    2. Prints a message indicating the start of the function.
    3. Creates an instance of `CustomItemHost` with the global element handle (`g_eeh`) and a boolean flag set to `False`.
    4. Retrieves a custom item from the item host using the global item type library name (`g_itemTypeLibName`) and the global item type name (`g_itemTypeName`).
    5. Deletes the retrieved custom instance.
    6. Prints a message indicating the end of the function.

    :returns: None
    """
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
