from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def find_and_delete_cells():
    # Get the active DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    modelInfo = dgnModel.GetModelInfo()

    # Convert the element ID to an EditElementHandle
    elementHandle = EditElementHandle(1378, dgnModel)
    if not elementHandle.IsValid():
        print("Invalid element ID.")
        return

    # Convert the element to a curve vector
    curveVector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    if curveVector is None:
        print("Failed to convert element to curve vector.")
        return
        
    searcher = CurveVectorWithDistanceIndex ()
    searcher.SetPath (curveVector)

    # Find all instances of the cell named "Barrier01"
    for element in dgnModel.GetElementsCollection():
        if element.GetElementType() == MSElementTypes.eCELL_HEADER_ELM:
            eh = ElementHandle (element, dgnModel)
            cellOrigin = DPoint3d ()
            cellName = WString ()
            retVal = Cell.Extract (cellOrigin, None, None, None, cellName, eh.GetElement ())
                        
            if str (cellName) == "Barrier01":
                pathLocationDetail = searcher.SearchClosestPointBounded (cellOrigin, True)
                
                # Calculate the minimum distance to the target element
                minDistance = pathLocationDetail.DistanceToPoint(cellOrigin)
                # Convert the distance to the master unit
                minDistanceMasterUnit = minDistance

                # Check if the distance is within 50 units
                if minDistanceMasterUnit < 50:
                    # Delete the cell
                    print (f"Deleting Cell id {eh.GetElementId()}\n")
                    eeh = EditElementHandle (eh, False)
                    eeh.DeleteFromModel()

    # Save the changes to the DGN file
    dgnModel.GetDgnFile().ProcessChanges(DgnSaveReason.eUserInitiated)

if __name__ == "__main__":
    find_and_delete_cells()