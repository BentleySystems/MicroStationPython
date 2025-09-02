# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import ISessionMgr,PythonKeyinManager

'''
This sample demonstrates how to add key-in commands and use those commands to attach, detach and rotate a dgn attachment
'''

ModelName = 'Default'

def GetDgnAttachmentByAttachedModelName():
    """
    Retrieves a DGN attachment by the attached model name.

    This function iterates through the list of DGN attachments in the active DGN model reference.
    If an attachment with the specified model name is found, it is returned. If no such attachment
    is found, the function returns None.

    :return: The DGN attachment with the specified model name, or None if not found.
    :rtype: DgnAttachment or None
    """
    attachments = ISessionMgr.ActiveDgnModelRef.GetDgnAttachments()
    if None == attachments:
        return None

    for attachment in attachments:
        if ModelName == attachment.GetAttachModelName():
            return attachment

    return None

def Attach():
    """
    Attaches a DGN file as a reference to the active DGN model.

    This function first checks if a DGN attachment with the specified model name already exists.
    If it does, it attempts to detach it. Then, it creates a new DGN attachment from a specified
    file and sets various display and lock properties.

    :return: True if the attachment was successfully created and written to the model, False otherwise.
    :rtype: bool
    """
    if None != GetDgnAttachmentByAttachedModelName():
        if not Detach():
            return False

    file = 'Reference.dgn'
    dataDir = path.join(path.dirname(path.dirname(path.dirname(path.abspath(__file__)))), 'data')

    moniker = DgnDocumentMoniker.CreateFromFileName(path.join(dataDir, file))
    ret = ISessionMgr.ActiveDgnModelRef.CreateDgnAttachment(moniker, ModelName, False)
    if BentleyStatus.eSUCCESS != ret[0]:
        return False

    ret[1].SetIsDisplayed(True) #necessary
    ret[1].SetLocateLock(True)  #necessary
    ret[1].SetSnapLock(True)
    if BentleyStatus.eSUCCESS != ret[1].WriteToModel():
        return False

    return True

def Detach():
    """
    Detaches a DGN file reference from the active DGN model.

    This function retrieves the DGN attachment with the specified model name and attempts to
    delete it from the active DGN model. If the attachment is successfully deleted, the function
    returns True. Otherwise, it returns False.

    :return: True if the attachment was successfully deleted, False otherwise.
    :rtype: bool
    """
    requiredRef = GetDgnAttachmentByAttachedModelName()
    if None == requiredRef:
        return False

    if BentleyStatus.eSUCCESS != ISessionMgr.ActiveDgnModelRef.DeleteDgnAttachment(requiredRef):
        return False

    return True

def Rotate():
    """
    Rotates a DGN file reference in the active DGN model.

    This function retrieves the DGN attachment with the specified model name. If the attachment
    is not already rotated, it rotates the attachment by 90 degrees around the Z-axis.

    :return: True if the rotation was successfully applied and written to the model, False otherwise.
    :rtype: bool
    """    
    requiredRef = GetDgnAttachmentByAttachedModelName()
    if None == requiredRef:
        return False

    axis = DVec3d.From(0, 0, 1)

    #If the reference is not rotated, rotate it by 90 degrees
    if requiredRef.GetRotMatrix().IsIdentity():
        #rotation = RotMatrix.FromVectorAndRotationAngle(axis, PI/2)
        rotation = RotMatrix.FromRotate90(axis)

    requiredRef.SetRotMatrix(rotation)
    if BentleyStatus.eSUCCESS != requiredRef.WriteToModel():
        return False

    return True

if __name__ == '__main__':
    keyinXml = path.dirname(__file__) + '/Reference.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))