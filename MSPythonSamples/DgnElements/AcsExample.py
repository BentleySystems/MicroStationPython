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
Sample demonstrating how to create acs
'''

def createAcs(basePoint, acsName="MyACS1", acsDesc="My ACS1", scale=1,
              rotation=RotMatrix.FromRowValues(1,0,0,0,1,0,0,0,1)):
    """
    Create an Auxiliary Coordinate System (ACS) in the active DGN model.

    :param basePoint: The base point for the ACS origin.
    :type basePoint: Point3d
    :param acsName: The name of the ACS. Defaults to "MyACS1".
    :type acsName: str, optional
    :param acsDesc: The description of the ACS. Defaults to "My ACS1".
    :type acsDesc: str, optional
    :param scale: The scale of the ACS. Defaults to 1.
    :type scale: float, optional
    :param rotation: The rotation matrix for the ACS. Defaults to identity matrix.
    :type rotation: RotMatrix, optional
    :return: True if the ACS was successfully created and set as active, False otherwise.
    :rtype: bool
    """    
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False  # If no active model, exit
    
    # Find an ACS with the given name in the current model
    namedACS = IACSManager.GetManager().GetByName(acsName, ACTIVEMODEL, 0)
    if namedACS is None:
        # Create a new ACS if one doesn't exist
        namedACS = IACSManager.GetManager().CreateACS()
        if namedACS is None:
            return False
        
        # Set the type of the new ACS to rectangular
        namedACS.SetType(ACSType.eRectangular)
        
        # Set the origin, rotation, and scale of the new ACS
        namedACS.SetOrigin(basePoint)
        namedACS.SetRotation(rotation)
        namedACS.SetScale(scale)
        
        # Set the name and description of the new ACS
        namedACS.SetName(acsName)
        namedACS.SetDescription(acsDesc)

         # Save the ACS to a file
        if BentleyStatus.eSUCCESS != namedACS.SaveToFile(ACTIVEMODEL, ACSSaveOptions.eAllowNew):
            return False

    # Get the active viewport (view) in the current model
    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if viewport is None:
        return False
    
     # Set the ACS as the active ACS for the given viewport
    if BentleyStatus.eSUCCESS != IACSManager.GetManager().SetActive(namedACS, viewport):
        return False
    
    return True  # If all checks out, exit with success


if __name__ == "__main__":
    if True != createAcs(DPoint3d(500, 0, 0)):
        print("Return false when call createAcs!")