from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
from math import radians
import os

'''
Example demonstrating how to place Cell
Prerequisite : Run the sample on PlaceCell.dgn
'''

DataDir = os.path.join(os.path.dirname(__file__), "../data")
celLibraryName = BeFileName(os.path.join(DataDir, "CellFromLibrary.cel")) # Path to the cell library
cellName = "ARROW"  # Name of the cell to be placed

"""
Retrieve B-spline elements from the active model and delete other elements that are not B-splines.
    
:return: The first B-spline element found or an empty element.
"""
def getActiveModelGraphicalElements():
    # Retrieve the active model and its graphical elements
    activeModel = ISessionMgr.ActiveDgnModelRef
    dgnModel = activeModel.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()

    # Initialize an empty B-spline element
    bSpline = MSElement()

    # Iterate through each graphical element in the model
    for elementRef in graphicalElements:
        # Create handles to edit or reference elements
        editElementHandle = EditElementHandle(elementRef, dgnModel)
        elementHandle = ElementHandle(elementRef)
        msElement = editElementHandle.GetElement()

        # Check if the element is a visible graphic and not invisible
        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        # If the element is visible, check if it's a B-spline element
        if isGraphics and not isInvisible:
            elementType = elementHandle.GetElementType()
            if elementType == 27:  # Element type 27 corresponds to B-Spline
                bSpline = editElementHandle  # Found the B-spline element
            else:
                editElementHandle.DeleteFromModel()  # Delete non-B-spline elements

    # Return the found B-spline element (or empty if none found)
    return bSpline


"""
Place cells along a B-spline curve at specific intervals.

:return: None
"""
def placeCells():
    global celLibraryName, cellName  # Reference global variables

    # Retrieve the B-spline element from the active model
    bSpline = getActiveModelGraphicalElements()
    if not bSpline:
        print("No B-spline found!")
        return

    # Convert the B-spline element to a curve path for further processing
    curve = ICurvePathQuery.ElementToCurveVector(bSpline)
    curvePrimitive = curve[0]
    
    # Initialize a handle to edit elements and retrieve the DGN file reference
    eeh = EditElementHandle()
    dgnFile = eeh.GetDgnFile()

    # Set the number of cells to place and the distance between them
    count = 5
    setDistance = 200000

    # Specify the location of the cell library to attach
    Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryName, defaultDir=DataDir, fromKeyin=0)

    # Loop through and place cells at different points along the B-spline curve
    for i in range(count):
        # Calculate the location along the curve at the specified distance
        location = CurveLocationDetail()
        result = curvePrimitive.PointAtSignedDistanceFromFraction(
            startFraction=0.1 * i,  # Starting point of the curve for this iteration
            signedDistance=setDistance * i,  # Signed distance from the start point
            allowExtension=True,  # Allow extending the curve if necessary
            location=location
        )

        origin = location.point  # Get the point at the current location along the curve
        
        # Set default scale for the cell to be placed
        scale = DPoint3d(1, 1, 1)  # Default scale of 1 in all axes
       
        # Calculate the rotation matrix to rotate the cell at a specific angle
        rotMatrix = RotMatrix.FromAxisAndRotationAngle(2, radians(30 * i))  # Rotate around Z-axis (2) by 30° increments
        
        # Set additional attributes for the cell placement (such as group number, level, etc.)
        attributes = 0
        ggroup = 0  # Graphic group number
        relativeMode = False  # Whether the position is relative to other elements
        baseLevel = 0  # Level ID (0 if not used)
        sharedFlag = 1  # Set to 1 for shared cell
  
        # Attempt to place the cell at the calculated location with the specified attributes
        try:
            result = Cell.PlaceCell(
                origin=origin,  # Origin point of the cell
                scale=scale,  # Scale of the cell
                trueScale=True,  # True scale flag
                rotMatrix=rotMatrix,  # Rotation matrix for orientation
                attributes=attributes,  # Cell attributes
                ggroup=ggroup,  # Graphic group number
                relativeMode=relativeMode,  # Relative mode flag
                baseLevel=baseLevel,  # Level ID for the cell
                sharedFlag=sharedFlag,  # Shared cell flag
                cellName=cellName,  # Name of the cell
                library=None  # Reference to the DGN file library, or None to search for the cell in the active cell library
            )
        except Exception as e:
            print(f"Error placing cell: {e}")  # Print any error that occurs during cell placement
        

# Main execution point
if __name__ == "__main__":
    placeCells()  # Call the function to place cells along the B-spline curve
