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

g_itemTypeLib = None
g_customStructType = None
g_eeh = EditElementHandle()
g_myItemTypeName = str('MyItemType')

'''
Function to create Item type library, item type and custom property type
'''
def CreateLibWithArrayStructAndArrayofStruct ():
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

'''
Function to create a line element
'''
def CreateLine (dgnmodel, x1, y1, x2, y2):
    global g_eeh
    segment = DSegment3d (x1, y1, 0.0, x2, y2, 0.0)
    if BentleyStatus.eSUCCESS != LineHandler.CreateLineElement(g_eeh, None, segment, dgnmodel.Is3d(), dgnmodel):
        g_eeh = None
        return False

    g_eeh.AddToModel()
    return True

'''
* This function reads the entries set on an element and update it.
'''
def ReadAndUpdateProperty ():
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

