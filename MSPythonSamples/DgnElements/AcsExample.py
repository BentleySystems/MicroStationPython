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


'''Create acs in Microstation'''
def createAcs(basePoint, acsName="MyACS1", acsDesc="My ACS1", scale=1,
              rotation=RotMatrix.FromRowValues(1,0,0,0,1,0,0,0,1)):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False
    
    namedACS = IACSManager.GetManager().GetByName(acsName, ACTIVEMODEL, 0)
    if namedACS is None:
        namedACS = IACSManager.GetManager().CreateACS()
        if namedACS is None:
            return False
        
        namedACS.SetType(ACSType.eRectangular)
        namedACS.SetOrigin(basePoint)
        namedACS.SetRotation(rotation)
        namedACS.SetScale(scale)
        namedACS.SetName(acsName)
        namedACS.SetDescription(acsDesc)

        # save acs to file
        if BentleyStatus.eSUCCESS != namedACS.SaveToFile(ACTIVEMODEL, ACSSaveOptions.eAllowNew):
            return False

    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if viewport is None:
        return False
    
    # set acs active
    if BentleyStatus.eSUCCESS != IACSManager.GetManager().SetActive(namedACS, viewport):
        return False
    
    return True


if __name__ == "__main__":
    if True != createAcs(DPoint3d(500, 0, 0)):
        print("Return false when call createAcs!")