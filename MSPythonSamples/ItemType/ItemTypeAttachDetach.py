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
def InitItemTypeLib ():
    dgnFile = ISessionMgr.GetActiveDgnFile()
    itemTypeLib = ItemTypeLibrary(g_itemTypeLibName, dgnFile, False)
    sofaItemType = itemTypeLib.AddItemType(g_itemTypeName, False)
    typeProperty = sofaItemType.AddProperty(g_typePropertyName, False)
    typeProperty.SetType(CustomProperty.Type1.eString)
    ecval = ECValue(g_propertyValueName)
    typeProperty.SetDefaultValue(ecval)
    itemTypeLib.Write()
    return True

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
Function to attach item type to element
'''
def AttachItemType ():
    global g_eeh

    print ('BEGIN: Attach Item type to Element \n')

    if True != InitItemTypeLib ():
        return

    if False == CreateLine (ISessionMgr.ActiveDgnModelRef, 0.0, 0.0, 100.0, 0.0):
        return

    dgnFile = ISessionMgr.GetActiveDgnFile()
    itemTypeLib = ItemTypeLibrary.FindByName(g_itemTypeLibName, dgnFile)
    sofaItemType = itemTypeLib.GetItemTypeByName(g_itemTypeName)

    itemHost = CustomItemHost(g_eeh, False)
    dgnecinstance = itemHost.ApplyCustomItem(sofaItemType)
    dgnecinstance.SetValue(g_typePropertyName, ECValue(g_propertyValueName))
    dgnecinstance.WriteChanges()

    print ('END: Attached successfully \n')

'''
Function to detach item type from element
'''
def DetachItemType ():
    global g_eeh

    print ('BEGIN: Detach Item type from Element \n')

    itemHost = CustomItemHost(g_eeh, False)
    dgnecinstance = itemHost.GetCustomItem(g_itemTypeLibName, g_itemTypeName)
    dgnecinstance.Delete();

    print ('END: Detach successfully \n')

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/ItemTypeAttach.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))
