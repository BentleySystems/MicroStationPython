from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import math

def placeCellsAlongElement(elementId, cellName, cellLibraryPath, interval):
    """
    Places cells along an element at specified intervals.

    :param elementId: The ID of the element along which cells will be placed.
    :type elementId: int
    :param cellName: The name of the cell to be placed.
    :type cellName: str
    :param cellLibraryPath: The path to the cell library.
    :type cellLibraryPath: str
    :param interval: The interval at which cells will be placed.
    :type interval: float
    """
    # Get the active DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    # Convert the element ID to an EditElementHandle
    elementHandle = EditElementHandle(elementId, dgnModel)
    if not elementHandle.IsValid():
        print("Invalid element ID.")
        return

    # Convert the element to a curve vector
    curveVector = ICurvePathQuery.ElementToCurveVector(elementHandle)
    if curveVector is None:
        print("Failed to convert element to curve vector.")
        return

    # Attach the cell library
    celLibraryName = BeFileName(cellLibraryPath)
    Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryName, defaultDir=os.path.dirname(cellLibraryPath), fromKeyin=0)

    # Find the cell in the library
    searchAll = 1  # => 0=no, 1=yes w/o messages, 2=yes w/ messages
    retVal, library = Cell.FindCell(None, cellName, searchAll)
    if BentleyStatus.eSUCCESS != retVal:
        print(f"Error finding cell {cellName} in library")
        return

    # Calculate spaced points along the curve vector
    distances = DoubleArray()
    delta = interval
    length = curveVector.Length()
    numPoints = int(length / delta) + 1
    for i in range(numPoints):
        distances.append(i * delta)

    points = CurveLocationDetailArray()
    curveVector.AddSpacedPoints(distances, points)

    # Place the cell at each spaced point
    for point in points:
        ray = ValidatedDRay3d()
        ray = point.PointAndUnitTangent()
        direction = DVec3d()
        direction = ray.Value().direction

        # Calculate the rotation matrix to align the y-axis of the cell with the unit tangent
        rotMatrix = RotMatrix.From1Vector (direction, 1, False)
        rMatrix2 = RotMatrix ()
        rMatrix2.InitFromPrincipleAxisRotations(rMatrix2, 0.0, math.radians(90), 0.0)
        rotMatrix.InitProduct(rotMatrix,rMatrix2)
        # Place the cell at the calculated location with the specified attributes
        try:
            result = Cell.PlaceCell(
                origin=point.point,  # Origin point of the cell
                scale=DPoint3d(1, 1, 1),  # Scale of the cell
                trueScale=True,  # True scale flag
                rotMatrix=rotMatrix,  # Rotation matrix for orientation
                attributes=0,  # Cell attributes
                ggroup=0,  # Graphic group number
                relativeMode=False,  # Relative mode flag
                baseLevel=0,  # Level ID for the cell
                sharedFlag=0,  # Shared cell flag
                cellName=cellName,  # Name of the cell
                library=library  # Reference to the DGN file library
            )
        except Exception as e:
            print(f"Error placing cell: {e}")

# Example usage
elementId = 1378
cellName = "Barrier01"
cellLibraryPath = r"C:\ProgramData\Bentley\PowerPlatformPython\Examples\Microstation\data\exampleCells.cel"
interval = 20000  # 2 meters interval

placeCellsAlongElement(elementId, cellName, cellLibraryPath, interval)