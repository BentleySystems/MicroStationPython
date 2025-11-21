from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def displayActiveACSInfo():
    # Get the active DGN model reference
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Reference to the active DGN model
    if ACTIVEMODEL is None:
        MessageCenter.ShowErrorMessage("Error", "No active DGN model found.", False)
        return

    # Get the active viewport (view)
    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if viewport is None:
        MessageCenter.ShowErrorMessage("Error", "No active viewport found.", False)
        return

    # Get the active ACS for the given viewport
    activeACS = IACSManager.GetManager().GetActive(viewport)
    if activeACS is None:
        MessageCenter.ShowErrorMessage("Error", "No active ACS found.", False)
        return

    # Get the origin and rotation of the active ACS
    origin = DPoint3d()    
    activeACS.GetOrigin(origin)

    rotation = RotMatrix()
    activeACS.GetRotation(rotation)

    # Display the origin and rotation
    MessageCenter.ShowInfoMessage("Active ACS Info", f"Origin: {origin}\nRotation:\n{rotation}", False)

# Call the function to display ACS information
displayActiveACSInfo()