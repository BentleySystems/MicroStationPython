# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''
This sample demonstrates how to add key-in commands and use those commands to add custom property to item type.
'''

g_itemTypeLib = None
g_customStructType = None
g_eeh = EditElementHandle()
g_myItemTypeName = str('MyItemType')


def CreateLibWithArrayStructAndArrayofStruct ():
    """
    Create an Item type library, item type, and custom property type.

    This function performs the following steps:
    
    1. Creates an Item type library.
    2. Adds an item type to the library.
    3. Adds an array property to the item type.
    4. Creates a custom property type named 'Struct' with two properties:
       - Prop1 (String)
       - Prop2 (Integer)
    5. Adds a property with the custom type 'Struct' to the item type.
    6. Adds an array of the custom type 'Struct' to the item type.
    7. Writes the item type library to the active DGN file.

    Globals:
        g_itemTypeLib (ItemTypeLibrary): The global item type library.
        g_customStructType (CustomPropertyType): The global custom property type.
        g_myItemTypeName (str): The global item type name.

    Returns:
        None
    """
    global g_itemTypeLib
    global g_customStructType
    global g_myItemTypeName

    print ('BEGIN: Create Item type library, Item type, custom type property \n')

    dgnFile = ISessionMgr.GetActiveDgnFile()
    g_itemTypeLib = ItemTypeLibrary('ItemTypeLibrary', dgnFile, False)

    if None == g_itemTypeLib:
        return

    myItemType  = g_itemTypeLib.AddItemType(g_myItemTypeName, False)

    #Array property 
    colorProperty = myItemType.AddProperty('Color')
    colorProperty.SetIsArray(True);
    colorProperty.SetType(CustomProperty.Type1.eString)

    # step 1) Create custom property type named 'Struct'
    g_customStructType = g_itemTypeLib.AddCustomType('Struct')
    prop1 = g_customStructType.AddProperty('Prop1')
    prop1.SetType(CustomProperty.Type1.eString)
    prop2 = g_customStructType.AddProperty('Prop2')
    prop2.SetType(CustomProperty.Type1.eInteger)

    # step 2) Add property with custom type of 'Struct'
    structProperty = myItemType.AddProperty('ColorStruct')
    structProperty.SetType(g_customStructType)

    #Array of struct 
    structArrayProperty = myItemType.AddProperty('ColorStructArray')
    structArrayProperty.SetType(g_customStructType)
    structArrayProperty.SetIsArray(True);

    g_itemTypeLib.Write()

    print ('END: Created Successfully \n')


def CreateLine (dgnmodel, x1, y1, x2, y2):
    """
    Create a line element in the specified DGN model.

    :param dgnmodel: The DGN model where the line element will be created.
    :type dgnmodel: DgnModel
    :param x1: The x-coordinate of the start point of the line.
    :type x1: float
    :param y1: The y-coordinate of the start point of the line.
    :type y1: float
    :param x2: The x-coordinate of the end point of the line.
    :type x2: float
    :param y2: The y-coordinate of the end point of the line.
    :type y2: float
    :return: True if the line element was successfully created and added to the model, False otherwise.
    :rtype: bool

    Globals:
        g_eeh (ElementHandle): The global element handle.

    """
    global g_eeh
    segment = DSegment3d (x1, y1, 0.0, x2, y2, 0.0)
    if BentleyStatus.eSUCCESS != LineHandler.CreateLineElement(g_eeh, None, segment, dgnmodel.Is3d(), dgnmodel):
        g_eeh = None
        return False

    g_eeh.AddToModel()
    return True


def ReadAndUpdateProperty ():
    """
    Read the entries set on an element and update it.

    This function performs the following steps:

    1. Checks if the item type library is created.
    2. Creates a line element in the active DGN model.
    3. Attaches a custom item to the element.
    4. Sets values for array properties.
    5. Sets values for struct properties.
    6. Sets values for array of struct properties.
    7. Reads and prints the values from the properties.

    Globals:
        g_itemTypeLib (ItemTypeLibrary): The global item type library.
        g_customStructType (CustomPropertyType): The global custom property type.
        g_myItemTypeName (str): The global item type name.
        g_eeh (ElementHandle): The global element handle.

    Returns:
        None
    """
    global g_itemTypeLib
    global g_customStructType
    global g_myItemTypeName
    global g_eeh

    print ('BEGIN: Read entries set on element\n')

    if None == g_itemTypeLib:
        print ('ERROR: Failed to create item type library \n')
        return

    dgnModel = ISessionMgr.ActiveDgnModelRef
    if False == CreateLine (dgnModel, 0.0, 0.0, 100.0, 0.0):
        print ('ERROR: Failed to create element \n')
        return

    itemHost = CustomItemHost(g_eeh, False)
    myItemType = g_itemTypeLib.GetItemTypeByName(g_myItemTypeName)
    dgnecinstance_0 = itemHost.ApplyCustomItem(myItemType)
    if None == dgnecinstance_0:
        print ('ERROR in attaching item type on element \n')
        return
    dgnecinstance_0.WriteChanges()

    # 1) Set Array Property values
    dgnecinstance_0.AddArrayElements('Color', 2)
    dgnecinstance_0.SetValue('Color', ECValue('Red'), 0)
    dgnecinstance_0.SetValue('Color', ECValue('Green'), 1)

    # 2) Set Struct Property values
    dgnecinstance_0.SetValue('ColorStruct.Prop1', ECValue('StructProp1'))
    dgnecinstance_0.SetValue('ColorStruct.Prop2', ECValue(10))

    # 3) Set Array of Struct Property values
    dgnecinstance_0.AddArrayElements('ColorStructArray', 1)

    structClass = dgnecinstance_0.GetClass().GetSchema().GetClass(g_customStructType.GetInternalName())
    dgnecinstance_1  = structClass.DefaultStandaloneEnabler.CreateInstance()
    dgnecinstance_1.SetValue('Prop1', ECValue('StructArray Prop1'))
    dgnecinstance_1.SetValue('Prop2', ECValue(100))

    newStructValue = ECValue()
    newStructValue.SetStruct(dgnecinstance_1);
    dgnecinstance_0.SetValue('ColorStructArray', newStructValue, 0)

    dgnecinstance_0.WriteChanges()

    print('Read values from Array, Struct, Array of Struct properties \n') 

    propValue = ECValue()
    dgnecinstance_0.GetValue(propValue, 'Color', 0)
    print('Color[0] value :' + propValue.String + '\n')

    dgnecinstance_0.GetValue(propValue, 'Color', 1)
    print('Color[1] value :' + propValue.String + '\n')

    dgnecinstance_0.GetValue(propValue, 'ColorStruct.Prop1')
    print('ColorStruct.Prop1 value :' + propValue.String + '\n')

    dgnecinstance_0.GetValue(propValue, 'ColorStruct.Prop2');
    print ('ColorStruct.Prop2 value :  {0} \n'.format (propValue.GetInteger()))
    
    dgnecinstance_0.GetValue(propValue, 'ColorStructArray', 0)
    structValueInstance_2 = propValue.GetStruct()

    structValueInstance_2.GetValue(propValue, 'Prop1')
    print('ArrayofStruct[0].Prop1 value :'+ propValue.String + '\n')

    structValueInstance_2.GetValue(propValue, 'Prop2')
    print ('ArrayofStruct[0].Prop2 value :  {0} \n'.format (propValue.GetInteger()))

    print ('END: Read Successfully \n')

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ItemTypeCustom.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))    

