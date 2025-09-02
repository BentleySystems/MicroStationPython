from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import math

# ------------------------------------------------------------------------------
# Script Description:
#
# This script automates two main tasks in a MicroStation DGN model, both based on
# the user's current selection (the first selected element is used as the reference curve):
#
# 1. find_and_delete_cells_by_selection():
#    - Searches for all cell elements named "Barrier01" in the active model.
#    - For each such cell, if it is within 50 master units of the selected reference element,
#      the cell is deleted from the model.
#
# 2. place_cells_along_selected_element():
#    - Places instances of the "Barrier01" cell at regular intervals (every 2.1 meters)
#      along the curve defined by the selected reference element.
#    - Each cell is oriented to follow the tangent of the curve at its placement point.
#
# Both functions operate on the active DGN model and process changes at the end.
# The script assumes the user has selected a single curve/path element before running.
# ------------------------------------------------------------------------------

def get_first_selected_element_handle(dgnModel):
    """
    Returns an EditElementHandle for the first selected element in the active model.
    If no element is selected, prints an error and returns None.
    """
    selSetManager = SelectionSetManager.GetManager()
    nSelected = selSetManager.NumSelected()
    if nSelected == 0:
        print("No element selected. Please select an element and try again.")
        return None
    elementHandle = EditElementHandle()
    selSetManager.GetElement(0, elementHandle)
    if not elementHandle.IsValid():
        print("Selected element handle is invalid.")
        return None
    return elementHandle

def find_and_delete_cells_by_selection():
    """
    Deletes all cell elements named "Barrier01" within 50 master units of the selected element.
    The selected element must be a curve or path.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    modelInfo = dgnModel.GetModelInfo()

    # Get the selected element as the reference curve
    elementHandle = get_first_selected_element_handle(dgnModel)
    if elementHandle is None:
        return

    # Convert the reference element to a curve vector for distance calculations
    curveVector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    if curveVector is None:
        print("Failed to convert selected element to curve vector.")
        return

    # Create a searcher to find closest points along the curve
    searcher = CurveVectorWithDistanceIndex()
    searcher.SetPath(curveVector)

    # Get UORs per master unit for scaling
    __, uorPerMast = modelInfo.StorageUnit.ConvertDistanceFrom(modelInfo.UorPerStorage, modelInfo.MasterUnit)
    distance_threshold = 50 * uorPerMast  # 50 master units in UORs

    # Iterate through all elements in the model
    for element in dgnModel.GetElementsCollection():
        # Check if the element is a cell header (cell instance)
        if element.GetElementType() == MSElementTypes.eCELL_HEADER_ELM:
            eh = ElementHandle(element, dgnModel)
            cellOrigin = DPoint3d()
            cellName = WString()
            # Extract the cell's origin and name
            retVal = Cell.Extract(cellOrigin, None, None, None, cellName, eh.GetElement())

            if str(cellName) == "Barrier01":
                # Find the closest point on the reference curve to the cell's origin
                pathLocationDetail = searcher.SearchClosestPointBounded(cellOrigin, True)
                minDistance = pathLocationDetail.DistanceToPoint(cellOrigin)
                # If the cell is within the threshold, delete it
                if minDistance < distance_threshold:
                    eeh = EditElementHandle(eh, False)
                    eeh.DeleteFromModel()

    # Commit the changes to the DGN file
    dgnModel.GetDgnFile().ProcessChanges(DgnSaveReason.eUserInitiated)

def place_cells_along_selected_element():
    """
    Places instances of the "Barrier01" cell at regular intervals (every 2.1 meters)
    along the selected curve element. The cell is oriented to follow the tangent of the curve.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    modelInfo = dgnModel.GetModelInfo()

    # Get the selected element as the reference curve
    elementHandle = get_first_selected_element_handle(dgnModel)
    if elementHandle is None:
        return

    # Convert the reference element to a curve vector for placement calculations
    curveVector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    if curveVector is None:
        print("Failed to convert selected element to curve vector.")
        return

    # Attach the cell library containing "Barrier01"
    celLibraryName = BeFileName(r"C:\ProgramData\Bentley\PowerPlatformPython\Examples\Microstation\data\barrier.cel")
    Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryName, defaultDir=r"c:\temp", fromKeyin=0)

    # Find the "Barrier01" cell in the attached library
    searchAll = 1  # 0=no, 1=yes w/o messages, 2=yes w/ messages
    retVal, library = Cell.FindCell(None, "Barrier01", searchAll)
    if BentleyStatus.eSUCCESS != retVal:
        print("Error finding cell Barrier01 in library")
        return

    # Calculate evenly spaced distances along the curve (every 2.1 meters, converted to UORs)
    delta = 2.1 * modelInfo.UorPerMeter  # 2.1 meters in UORs
    length = curveVector.Length()
    numPoints = int(length / delta) + 1
    distances = DoubleArray()
    for i in range(numPoints):
        distances.append(i * delta)

    # Compute the points along the curve at the specified distances
    points = CurveLocationDetailArray()
    curveVector.AddSpacedPoints(distances, points)

    # Place the cell at each computed point along the curve
    for point in points:
        # Get the tangent direction at the point for orientation
        ray = ValidatedDRay3d()
        ray = point.PointAndUnitTangent()
        direction = DVec3d()
        direction = ray.Value().direction

        # Calculate a rotation matrix to align the cell's y-axis with the curve's tangent
        rotMatrix = RotMatrix.From1Vector(direction, 1, False)
        rMatrix2 = RotMatrix()
        rMatrix2.InitFromPrincipleAxisRotations(rMatrix2, 0.0, math.radians(90), 0.0)
        rotMatrix.InitProduct(rotMatrix, rMatrix2)

        # Place the cell at the calculated location with the computed orientation
        try:
            result = Cell.PlaceCell(
                origin=point.point,  # Placement point
                scale=DPoint3d(1, 1, 1),  # Uniform scale
                trueScale=True,  # Use true scale
                rotMatrix=rotMatrix,  # Orientation matrix
                attributes=0,  # Default attributes
                ggroup=0,  # No graphic group
                relativeMode=False,  # Not relative
                baseLevel=0,  # Default level
                sharedFlag=0,  # Not a shared cell
                cellName="Barrier01",  # Cell name
                library=library  # Cell library reference
            )
        except Exception as e:
            print(f"Error placing cell: {e}")

# Execute the functions to perform the operations
find_and_delete_cells_by_selection()
place_cells_along_selected_element()