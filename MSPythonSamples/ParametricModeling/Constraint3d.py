# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to create fixed constraint for first cube, then create parallel and distance constraint for 2 faces of 2 cubes
Prerequisite: Open MSPythonSamples\\data\\Constraint3d.dgn to run this sample
'''
 
def ExampleFixedParallelDistance():
    """
    Demonstrates the creation of fixed, parallel, and distance constraints between two 3D solid elements.
    This function performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Validates the first solid element and adds a fixed constraint to it.
    3. Validates the second solid element.
    4. Converts both solid elements to body representations.
    5. Retrieves faces from both body representations.
    6. Adds a parallel constraint between a face from each of the two solid elements.
    7. Adds a distance constraint between the same faces and associates it with a variable "var1" if it exists.
    
    Returns:
        bool: True if all constraints are successfully added, False otherwise.
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return

    solidElement1 = EditElementHandle(1411, dgnModel)
    if False == solidElement1.IsValid():
        return False

    # Add fixed constraint to the first cube
    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    subFaceArray = ISubEntityPtrArray()

    #subFaceArray.append(subFaceArray1[0]) # This line can add fixed constraint to a face of an element
    # Add fixed constraint to the first cube
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eFixed)
    if(not retVal):
        print("Fixed  Constraint failed: " + str(status))
        return False

    solidElement2 = EditElementHandle(1413, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert first cube to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert second cube to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get faces from first body
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    # Get faces from second body
    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    elems.Empty()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray.clear()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[2])

    # Add parallel constraint between 2 faces of the 2 cubes
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_PARALLEL)
    if(not retVal):
        print("Parallel Constraint failed: " + str(status))
        return False

    # Create distance costraint between 2 faces of the 2 cubes and associate it to variable "var1" if the varible exist
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_DISTANCE, 0, 5000, "var1")
    if(not retVal):
        print("Distance Constraint failed: " + str(status))
        return False

    return True

def ExamplePerpendicular():
    """
    Example function to demonstrate adding a perpendicular constraint between two solid elements in a 3D model.
    This function retrieves the active DGN model, converts two specified solid elements to bodies, 
    extracts their faces, and then adds a perpendicular constraint between the first faces of the two bodies.
    Returns:
        bool: True if the perpendicular constraint is successfully added, False otherwise.
    Steps:
        1. Retrieve the active DGN model reference.
        2. Validate the solid elements with IDs 1416 and 1417.
        3. Convert the solid elements to body representations.
        4. Extract faces from the body representations.
        5. Add the perpendicular constraint between the first faces of the two bodies.
    Raises:
        None
    Notes:
        - The function assumes that the solid elements with IDs 1416 and 1417 exist in the active DGN model.
        - The function prints an error message if the perpendicular constraint fails to be added.
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return
    solidElement1 = EditElementHandle(1416, dgnModel)
    if False == solidElement1.IsValid():
        return False

    solidElement2 = EditElementHandle(1417, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert first cube to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert second cube to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get faces from first body
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    # Get faces from second body
    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray = ISubEntityPtrArray()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[0])

    # Add perpendicular constraint between 2 faces of the 2 cubes
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_PERPENDICULAR)
    if(not retVal):
        print("Perpendicular Constraint failed: " + str(status))
        return False

    return True

def ExampleCoincident():
    """
    Demonstrates the creation of a coincident constraint between two 3D solid elements in a DGN model.
    This function performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Validates the first solid element and sets a fixed constraint on it.
    3. Validates the second solid element.
    4. Converts both solid elements to body representations.
    5. Retrieves the faces from both body representations.
    6. Creates an anti-aligned coincident constraint between a face from each of the two bodies.
    
    Returns:
        bool: True if the coincident constraint is successfully created, False otherwise.
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return

    solidElement1 = EditElementHandle(1418, dgnModel)
    if False == solidElement1.IsValid():
        return False

    # Set fixed constraint to the first cube
    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    subFaceArray = ISubEntityPtrArray()
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eFixed)
    if(not retVal):
        print("Fixed  Constraint failed: " + str(status))
        return False

    solidElement2 = EditElementHandle(1419, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert first cube to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert second cube to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get faces from first body
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    # Get faces from second body
    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    elems.Empty()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray.clear()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[1])

    # Create AntiAligned flag for coincident constraint settings
    constraint = Constraint3dBase.Create (Constraint3dType.eDCM3_COINCIDENT)
    constraint.SetSurfaceOrientation(SurfaceOrientation.eAntiAligned)

    # Add coincident constraint between 2 faces of the 2 cubes and set AntiAligned for coincident constraint settings
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_COINCIDENT, constraint.GetFlags())
    if(not retVal):
        print("Coincident Constraint failed: " + str(status))
        return False

    return True

def ExampleTangent():
    """
    Demonstrates how to add a tangent constraint between two 3D solid elements in a DGN model.
    This function performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Initializes two solid elements using their element IDs.
    3. Converts the solid elements to body representations.
    4. Extracts faces from the body representations of the solid elements.
    5. Adds a tangent constraint between the first faces of the two solid elements.
    
    Returns:
        bool: True if the tangent constraint is successfully added, False otherwise.
    Raises:
        None
    Note:
        This function assumes that the element IDs 1420 and 1427 correspond to a cube and a cylinder, respectively.
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return
    solidElement1 = EditElementHandle(1420, dgnModel)
    if False == solidElement1.IsValid():
        return False

    solidElement2 = EditElementHandle(1427, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert the cube to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert sylinder to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get faces from cube body
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    # Get faces from sylinder body
    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray = ISubEntityPtrArray()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[0])

    # Add tangent constraint between 2 faces of the cylinder and cube 
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_TANGENT)
    if(not retVal):
        print("Tangent Constraint failed: " + str(status))
        return False

    return True

def ExampleConcentric():
    """
    Example function to demonstrate adding a concentric constraint between two cylindrical elements.
    This function retrieves the active DGN model, converts two specified solid elements to bodies,
    extracts their faces, and then adds a concentric constraint between the first faces of the two bodies.
    
    Returns:
        bool: True if the concentric constraint is successfully added, False otherwise.
    Notes:
        - The function assumes that the elements with IDs 1433 and 1435 are valid cylindrical elements.
        - The function prints an error message if the concentric constraint fails to be added.
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return
    solidElement1 = EditElementHandle(1433, dgnModel)
    if False == solidElement1.IsValid():
        return False

    solidElement2 = EditElementHandle(1435, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert the first sylinder to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert the second sylinder to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get faces from the first sylinder body
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    # Get faces from the second sylinder body
    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray = ISubEntityPtrArray()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[0])

    # Add concentric constraint between 2 faces of the 2 cylinders
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_CONCENTRIC)
    if(not retVal):
        print("Concentric Constraint failed: " + str(status))
        return False

    return True

def setCoincident():
    """
    Sets a coincident constraint between two solid elements in the active DGN model.
    This function performs the following steps:
    1. Retrieves the active DGN model reference.
    2. Validates the first solid element (ID: 1438).
    3. Adds a fixed constraint to the first solid element.
    4. Validates the second solid element (ID: 1439).
    5. Converts both solid elements to body representations.
    6. Retrieves edges from both solid bodies.
    7. Adds a coincident constraint between the first edges of the two solid bodies.
    
    :returns: True if the coincident constraint is successfully added, False otherwise.
    :rtype: bool
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return

    solidElement1 = EditElementHandle(1438, dgnModel)
    if False == solidElement1.IsValid():
        return False

    # Add fixed costraint to the first cube
    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    subFaceArray = ISubEntityPtrArray()
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eFixed)
    if(not retVal):
        print("Fixed  Constraint failed: " + str(status))
        return False

    solidElement2 = EditElementHandle(1439, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert the first cube to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert the second cube to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get edges from the first cube body
    subFaceArray1 = ISubEntityPtrArray()
    numEdges1 = SolidUtil.GetBodyEdges(subFaceArray1, solid1)

    # Get edges from the second  cube body
    subFaceArray2 = ISubEntityPtrArray()
    numEdges2 = SolidUtil.GetBodyEdges(subFaceArray2, solid2)

    elems.Empty()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray.clear()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[0])

    # Add coincident constraint between 2 edges of the 2 cubes
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_COINCIDENT)
    if(not retVal):
        print("Coincident Constraint failed: " + str(status))
        return False

    return True

def setAngle():
    """
    Sets an angle constraint of 180 degrees between two solid elements in the active DGN model.
    This function retrieves the active DGN model reference and attempts to create two solid elements
    from the given element IDs. It then converts these elements to body representations and retrieves
    their faces. An angle constraint of 180 degrees is added between the first faces of the two solid
    elements.
    
    Returns:
        bool: True if the angle constraint is successfully added, False otherwise.
    Raises:
        None
    Notes:
        - The function assumes that the element IDs 1438 and 1439 correspond to valid solid elements
          in the active DGN model.
        - The angle constraint is set to 180 degrees (π radians).
    """
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if (dgnModel is None):
        return
    solidElement1 = EditElementHandle(1438, dgnModel)
    if False == solidElement1.IsValid():
        return False

    solidElement2 = EditElementHandle(1439, dgnModel)
    if False == solidElement2.IsValid():
        return False

    # Convert the first cube to body
    status1, solid1 = SolidUtil.Convert.ElementToBody(solidElement1, True, True, False)
    if BentleyStatus.eERROR == status1:
        return False

    # Convert the second cube to body
    status2, solid2 = SolidUtil.Convert.ElementToBody(solidElement2, True, True, False)
    if BentleyStatus.eERROR == status2:
        return False

    # Get faces from the first cube body
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    # Get faces from the second cube body
    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    elems = ElementAgenda()
    elems.Insert(solidElement1.GetElementRef(), solidElement1.GetModelRef())
    elems.Insert(solidElement2.GetElementRef(), solidElement2.GetModelRef())

    subFaceArray = ISubEntityPtrArray()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[0])

    # Add angle constraint between 2 faces of the 2 cubes, set angle as 180 degrees
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_ANGLE, 0, 180.0*3.1415926 / 180.0, "")
    if(not retVal):
        print("Angle Constraint failed: " + str(status))
        return False

    return True

def ExampleAngle():
    """
    Creates coincident and angle constraints for two cubes.
    This function first creates a coincident constraint for two edges of the two cubes.
    If the coincident constraint is successfully created, it then creates an angle constraint
    for two faces of the two cubes. If either constraint creation fails, the function returns False.
    
    Returns:
        bool: True if both constraints are successfully created, False otherwise.
    """
    # Create coincident constraint for 2 edges of the 2 cubes
    if (not setCoincident()):
        return False
    # Create angle constraint for 2 faces of the 2 cubes
    if (not setAngle()):
        return False

    return True

if __name__ == "__main__":
    if (not ExampleFixedParallelDistance()):
        print("Run ExampleFixedParallelDistance failed")
    if ( not ExamplePerpendicular()):
        print("Run ExamplePerpendicular failed")
    if (not ExampleCoincident()):
        print("Run ExampleCoincident failed")
    if ( not ExampleTangent()):
        print("Run ExampleTangent failed")
    if (not ExampleConcentric()):
        print("Run ExampleConcentric failed")
    if (not ExampleAngle()):
        print("Run ExampleAngle failed")
