from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def setLL84GCS():
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef

    # Check if the active model is valid
    if ACTIVEMODEL is None:
        print("No active DGN model found.")
        return False

    # Check if a GCS is already attached to the model
    dgnGCS = DgnGCS.FromModel(ACTIVEMODEL, True)
    if dgnGCS is not None:
        print("A GCS already exists in the active model.")
        return False

    # Create the LL84 GCS from the library
    newGCS = DgnGCS.CreateGCS("LL84", ACTIVEMODEL)
    if newGCS is None:
        print("Failed to create LL84 GCS.")
        return False

    # Apply the new GCS to the active model
    newGCS.ToModel(ACTIVEMODEL, True, True, True, True)
    print("LL84 GCS applied to the active model.")
    return True

# Run the function to set the LL84 GCS
setLL84GCS()