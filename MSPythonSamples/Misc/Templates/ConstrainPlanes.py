from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def create_distance_constraint_between_shapes():
    # Get the active DGN model reference
    dgnModel = ISessionMgr.GetActiveDgnModelRef()
    if dgnModel is None:
        print("No active DGN model found.")
        return

    # Initialize the selection set manager
    selSetManager = SelectionSetManager.GetManager()

    # Ensure exactly two shapes are selected
    if selSetManager.NumSelected() != 2:
        print("Please select exactly two shapes.")
        return

    # Retrieve the selected shapes
    shape1 = EditElementHandle()
    shape2 = EditElementHandle()
    selSetManager.GetElement(0, shape1)
    selSetManager.GetElement(1, shape2)

    # Convert the shapes to solid bodies
    status1, solid1 = SolidUtil.Convert.ElementToBody(shape1, True, True, False)
    status2, solid2 = SolidUtil.Convert.ElementToBody(shape2, True, True, False)

    if BentleyStatus.eERROR == status1 or BentleyStatus.eERROR == status2:
        print("Error converting shapes to solid bodies.")
        return

    # Get faces from both bodies
    subFaceArray1 = ISubEntityPtrArray()
    numfaces1 = SolidUtil.GetBodyFaces(subFaceArray1, solid1)

    subFaceArray2 = ISubEntityPtrArray()
    numfaces2 = SolidUtil.GetBodyFaces(subFaceArray2, solid2)

    # Create an element agenda for the constraint
    elems = ElementAgenda()
    elems.Insert(shape1.GetElementRef(), shape1.GetModelRef())
    elems.Insert(shape2.GetElementRef(), shape2.GetModelRef())

    # Select the first face from each shape for the distance constraint
    subFaceArray = ISubEntityPtrArray()
    subFaceArray.append(subFaceArray1[0])
    subFaceArray.append(subFaceArray2[0])

    # Add distance constraint between the two faces
    retVal, status = Constraint3dManager.AddConstraint(elems, subFaceArray, Constraint3dType.eDCM3_DISTANCE, 0, 5000, "distanceVar")
    if not retVal:
        print("Distance Constraint failed: " + str(status))
        return

    print("Distance constraint created successfully.")

# Run the function
create_distance_constraint_between_shapes()