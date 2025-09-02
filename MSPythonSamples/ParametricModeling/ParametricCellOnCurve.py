from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import math
import ParametricCell
import PSampUtility

"""
This script provides methods to analyze a curve and add parametric cells at the joints of the curve.
"""

def placeParametricCellInModel(cellName, targetModel, newPoint):
    """
    Places a parametric cell in the specified model at a given point.

    :param str cellName: The name of the parametric cell to be placed.
    :param targetModel: The target model where the parametric cell will be placed.
                        This should be an object that provides access to the DGN file and model.
    :type targetModel: ModelRef
    :param newPoint: The point where the parametric cell will be placed. 
                     This should be a 3D point object.
    :type newPoint: Point3d

    :return: An EditElementHandle object representing the placed parametric cell, 
             or None if the operation fails.
    :rtype: EditElementHandle or None

    :raises ValueError: If the parametric cell definition cannot be found or 
                        if the cell creation fails.

    :note: Ensure that the parameter set specified in the function exists in the 
           parametric cell definition. Otherwise, the operation will fail.

    :example:
        >>> cellName = "ExampleCell"
        >>> targetModel = getTargetModel()  # Retrieve the target model reference
        >>> newPoint = Point3d(10, 20, 30)
        >>> placedCell = placeParametricCellInModel(cellName, targetModel, newPoint)
        >>> if placedCell:
        >>>     print("Cell placed successfully.")
        >>> else:
        >>>     print("Failed to place cell.")
    """
    targetFile = targetModel.GetDgnFile()
    cellDefHandler = ParametricCellDefHandler.GetInstance()
    cellDef = cellDefHandler.GetCellDefinition(ElementHandle(cellDefHandler.FindByName(cellName, targetFile)))
    parameterSetName = ""
    status = MsPyParameterStatus(ParameterStatus.eError)
    cellInfo = ParametricCellInfo.Create(status, cellDef, parameterSetName, targetModel.DgnModel)

    if cellInfo is None:
        print("ParametricCellInfo creation failed with parameter set: " + parameterSetName +
              ". Please make sure the parameter set exists.")
        return None

    cellHandler = ParametricCellHandler.GetInstance()
    cellEeh = EditElementHandle()

    if ParameterStatus.eSuccess != cellHandler.CreateCellElement(cellEeh, cellInfo):
        return None

    transform = Transform()
    transform.SetTranslation(newPoint)
    transformInfo = TransformInfo(transform)
    cellHandler.ApplyTransform(cellEeh, transformInfo)
    cellEeh.AddToModel()
    ModelRef.ActivateAndDisplay(targetModel)
    return cellEeh


def getActiveModelGraphicalElements():
    """
    Retrieves the graphical elements from the active DGN model, specifically 
    identifying circles and a line string.

    :returns: A tuple containing:
        - A list of `EditElementHandle` objects representing circles (element type 15).
        - An `EditElementHandle` object representing the line string (element type 4).
    :rtype: tuple[list[EditElementHandle], EditElementHandle]

    The function processes the graphical elements in the active DGN model, 
    filtering out non-graphical and invisible elements. It identifies and 
    separates circles and a single line string based on their element types.

    .. note::
        - Element type 4 corresponds to a line string.
        - Element type 15 corresponds to a circle (or ellipse).
        - Only visible graphical elements are considered.
    """
    activeModel = ISessionMgr.ActiveDgnModelRef
    dgnModel = activeModel.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()

    circles = []
    lineString = MSElement()

    # Process graphical elements to find the circle and the line string
    for elementRef in graphicalElements:
        editElementHandle = EditElementHandle(elementRef, dgnModel)
        elementHandle = ElementHandle(elementRef)
        msElement = editElementHandle.GetElement()
        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        # Only process visible graphical elements
        if isGraphics and not isInvisible:
            elementType = elementHandle.GetElementType()
            if elementType == 4:  # Line string
                lineString = editElementHandle
            elif elementType == 15:  # Circle (Ellipse)
                circles.append(editElementHandle)

    return circles, lineString


def createCircleAtPosition(basePoint, radius):
    """
    Creates a circular element at a specified position in the active DGN model.

    :param basePoint: The center point of the circle, specified as a `DPoint3d` object.
    :type basePoint: DPoint3d
    :param radius: The radius of the circle.
    :type radius: float
    :returns: True if the circle was successfully created and added to the model, False otherwise.
    :rtype: bool
    :raises RuntimeError: If the active DGN model reference is not available.
    
    This function creates an ellipse element (representing a circle in 2D) at the specified 
    base point with the given radius. The element is added to the active DGN model if the 
    creation is successful.
    """
    activeModel = ISessionMgr.ActiveDgnModelRef
    if activeModel is None:
        return False

    # Create an ellipse (representing the arc) at the base point
    ellipse = DEllipse3d.FromCenterRadiusXY(basePoint, radius)

    # Create ellipse element
    eeh = EditElementHandle()
    status = EllipseHandler.CreateEllipseElement(eeh, None, ellipse, activeModel.Is3d(), activeModel)

    if BentleyStatus.eSUCCESS != status:
        return False

    # Add the ellipse element to the model
    return BentleyStatus.eSUCCESS == eeh.AddToModel()


def measureAngle():
    """
    Measures angles between segments of a line string and places parametric cells at the bisector points.

    This function retrieves graphical elements from the active model, calculates the bisector directions
    at each vertex of a line string, and places parametric cells at the calculated bisector points. It also
    ensures that old bisector angle circles are removed before performing the calculations.

    :raises ValueError: If the line string has fewer than 2 segments.

    Steps:
        1. Retrieve circle and line string elements from the active model.
        2. Delete any existing bisector angle circles if more than one circle is found.
        3. Extract vertices from the line string.
        4. Calculate bisector directions for each vertex.
        5. Place parametric cells at the calculated bisector points.

    Notes:
        - The radius for calculations is set to 10,000.
        - The function assumes the presence of at least 3 vertices in the line string.
        - The parametric cell "Barrier01" is placed at each bisector point.

    Dependencies:
        - `getActiveModelGraphicalElements`: Retrieves graphical elements from the active model.
        - `ICurvePathQuery.ElementToCurveVector`: Converts a line string element to a curve vector.
        - `calculateBisector`: Computes the bisector direction in 3D space.
        - `calculateNewPoint`: Calculates a new point along the bisector direction.
        - `placeParametricCellInModel`: Places a parametric cell in the model.

    """
    # Get circle and lineString element
    circles, lineString = getActiveModelGraphicalElements()

    # Delete the old bisector angle circles
    if len(circles) > 1:
        for circle in circles:
            circle.DeleteFromModel()

    radius = 10000

    # Line-string primitive
    curve = ICurvePathQuery.ElementToCurveVector(lineString)
    lineStringPrimitive = curve[0]

    # Total segments count
    segmentsCount = lineStringPrimitive.NumComponent()

    # Ensure there are at least 3 vertices
    if segmentsCount < 2:
        return

    vertices = []

    # Extract vertices from the line string
    for i in range(segmentsCount):
        segment = DSegment3d()
        lineStringPrimitive.TryGetSegmentInLineString(segment, i)
        vertices.append(segment.StartPoint)
        if i == segmentsCount - 1:  # Add the last segment's end point
            vertices.append(segment.EndPoint)

    # Loop through the vertices and calculate angles between segments
    for i in range(1, len(vertices) - 1):
        # Calculate the bisector direction in 3D
        bisectorDirection = calculateBisector(vertices[i - 1], vertices[i], vertices[i + 1])
        newPoint = calculateNewPoint(vertices[i], bisectorDirection, 300)
        placeParametricCellInModel("Barrier01", ISessionMgr.ActiveDgnModelRef, newPoint)


def normalizeVector(v):
    """
    Normalize a 3D vector.

    This function takes a 3D vector as input and returns a normalized version
    of the vector, which has a magnitude of 1.

    :param v: The 3D vector to normalize. It is expected to be an instance of
              `DPoint3d` with attributes `x`, `y`, and `z` representing the
              vector's components.
    :type v: DPoint3d
    :return: A new `DPoint3d` instance representing the normalized vector.
    :rtype: DPoint3d
    :raises ZeroDivisionError: If the input vector has a magnitude of zero.
    """
    length = math.sqrt(v.x ** 2 + v.y ** 2 + v.z ** 2)
    return DPoint3d(v.x / length, v.y / length, v.z / length)


def calculateBisector(prevVertex, currentVertex, nextVertex):
    """
    Calculates the unit vector representing the bisector direction at a vertex 
    formed by three points in 3D space.

    The bisector is computed as the normalized sum of the normalized vectors 
    from the previous vertex to the current vertex and from the next vertex 
    to the current vertex.

    :param prevVertex: The previous vertex as a DPoint3d object.
    :type prevVertex: DPoint3d
    :param currentVertex: The current vertex as a DPoint3d object.
    :type currentVertex: DPoint3d
    :param nextVertex: The next vertex as a DPoint3d object.
    :type nextVertex: DPoint3d
    :return: A normalized DPoint3d object representing the bisector direction.
    :rtype: DPoint3d
    """
    # Vector from prevVertex to currentVertex (segment 1)
    vec1 = DPoint3d(currentVertex.x - prevVertex.x, currentVertex.y - prevVertex.y, currentVertex.z - prevVertex.z)

    # Vector from nextVertex to currentVertex (segment 2)
    vec2 = DPoint3d(currentVertex.x - nextVertex.x, currentVertex.y - nextVertex.y, currentVertex.z - nextVertex.z)

    # Normalize both vectors
    vec1Normalized = normalizeVector(vec1)
    vec2Normalized = normalizeVector(vec2)

    # Calculate the bisector direction by adding the normalized vectors
    bisectorDirection = DPoint3d(vec1Normalized.x + vec2Normalized.x,
                                 vec1Normalized.y + vec2Normalized.y,
                                 vec1Normalized.z + vec2Normalized.z)

    # Normalize the bisector vector to get the unit direction
    bisectorNormalized = normalizeVector(bisectorDirection)

    return bisectorNormalized


def calculateNewPoint(point, bisectorDirection, distance):
    """
    Calculates a new point by moving a given point along a bisector direction 
    by a specified distance.

    :param point: The original point to be moved. Expected to have `x`, `y`, and `z` attributes.
    :type point: DPoint3d
    :param bisectorDirection: The direction vector along which the point will be moved. 
                               Expected to have `x`, `y`, and `z` attributes.
    :type bisectorDirection: DVector3d
    :param distance: The distance to move the point along the bisector direction.
    :type distance: float
    :return: A new point after moving the original point along the bisector direction.
    :rtype: DPoint3d
    """
    newX = point.x - bisectorDirection.x * distance
    newY = point.y - bisectorDirection.y * distance
    newZ = point.z - bisectorDirection.z * distance
    return DPoint3d(newX, newY, newZ)


if __name__ == "__main__":
    # Execute the function to move circles based on angle bisectors
    measureAngle()