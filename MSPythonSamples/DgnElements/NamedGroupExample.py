# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
This sample demonstrates how to create a named group
'''

def createNamedGroup(basePoint, groupName="MyNamedGroup1", groupDesc="My Named Group1"):
    """
    Creates a named group in the active DGN model and adds a line element to it.

    :param basePoint: The starting point for the line element.
    :type basePoint: DPoint3d
    :param groupName: The name of the named group to create.
    :type groupName: str
    :param groupDesc: The description of the named group to create.
    :type groupDesc: str

    :returns: True if the named group and line element are successfully created and added to the model, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    namedGroups = NamedGroupCollection(ACTIVEMODEL)
    if namedGroups is None:
        return False
    group = namedGroups.FindByName(groupName)
    if group is None:
        # Create namedgroup
        flag = NamedGroupFlags()
        ret = NamedGroup.Create(groupName, groupDesc, flag, ACTIVEMODEL)
        if BentleyStatus.eSUCCESS != ret[0]:
            return False
        group = ret[1]

    xDir = DVec3d(1, 0, 0)
    seg = DSegment3d(basePoint, basePoint + 200 * xDir)
    eeh = EditElementHandle()
    # Create line element
    status = LineHandler.CreateLineElement(eeh, None, seg, 
                                           ACTIVEMODEL.Is3d(), 
                                           ACTIVEMODEL)
    if BentleyStatus.eSUCCESS != status:
        return False

    # Add the line element to model
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        return False

    # Add the line element as a member of the namedgroup
    memberFlag = NamedGroupMemberFlags()
    if BentleyStatus.eSUCCESS != group.AddMember(eeh.GetElementId(), ACTIVEMODEL, memberFlag):
        return False
    
    if BentleyStatus.eSUCCESS != group.WriteToFile(True):
        return False
    
    return True


if __name__ == "__main__":
    if True != createNamedGroup(DPoint3d(0, 0, 0)):
        print("Return false when call createNamedGroup!")