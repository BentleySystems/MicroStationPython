# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''Create namedgroup in Microstation'''
def createNamedGroup(basePoint, groupName="MyNamedGroup1", groupDesc="My Named Group1"):
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