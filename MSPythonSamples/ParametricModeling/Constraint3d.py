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
Prerequisite: Open MSPythonSamples\\data\\SolidModeling.dgn to run this sample
'''


'''
Example to create fixed constraint for first cube, then create parallel and distance constraint for 2 faces of 2 cubes
''' 
def ExampleFixedParallelDistance():
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

'''
Example to create perpendicular constraint for 2 faces of 2 cubes
''' 
def ExamplePerpendicular():
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

'''
Example to create coincident constraint for 2 faces of 2 cubes, and set AntiAligned for coincident constraint settings
''' 
def ExampleCoincident():
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

'''
Example to create tangent constraint for 2 faces of one cylinder and one cube
''' 
def ExampleTangent():
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

'''
Example to create concentric constraint for 2 faces of 2 cylinders
''' 
def ExampleConcentric():
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

'''
Function to create coincident constraint for 2 edges of 2 cubes
''' 
def setCoincident():
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

'''
Function to create angle constraint for 2 faces of 2 cubes
''' 
def setAngle():
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

'''
Example to first create coincident constraint for 2 edges of 2 cubes, then create angle constraint for 2 faces of the 2 cubes
''' 
def ExampleAngle():
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
