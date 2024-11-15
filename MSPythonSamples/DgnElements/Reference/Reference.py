# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import ISessionMgr,PythonKeyinManager

ModelName = 'Default'

def GetDgnAttachmentByAttachedModelName():
    attachments = ISessionMgr.ActiveDgnModelRef.GetDgnAttachments()
    if None == attachments:
        return None

    for attachment in attachments:
        if ModelName == attachment.GetAttachModelName():
            return attachment

    return None

def Attach():
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
    requiredRef = GetDgnAttachmentByAttachedModelName()
    if None == requiredRef:
        return False

    if BentleyStatus.eSUCCESS != ISessionMgr.ActiveDgnModelRef.DeleteDgnAttachment(requiredRef):
        return False

    return True

def Rotate():
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