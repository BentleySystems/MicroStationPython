from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import math

"""
Retrieve all visible graphical elements from the active model.
    
:return: A tuple containing a circle and a line string element.
"""
def getActiveModelGraphicalElements():
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


"""
Create a circle (ellipse) at the specified position with the given radius.
    
:param basePoint: The center of the new arc (DPoint3d).
:param radius: The radius of circle (double).
:return: Boolean indicating success or failure.
"""
def createCircleAtPosition(basePoint, radius):
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


"""
Measure the angles between segments of a line string and place circles along the bisector.
"""
def measureAngle():
    
    # Get circle and lineString element
    circles, lineString = getActiveModelGraphicalElements()
    
    # Delete the old bisector angle circles
    if len(circles) > 1:
        for i in range(len(circles)):            
            circles[i].DeleteFromModel()

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
        newPoint = calculateNewPoint(vertices[i], bisectorDirection, 30000)
        createCircleAtPosition(newPoint, radius)


"""
Normalize a 3D vector to unit length.
    
:param v: The 3D vector to normalize (DPoint3d).
:return: The normalized vector (DPoint3d).
"""
def normalizeVector(v):
    length = math.sqrt(v.x ** 2 + v.y ** 2 + v.z ** 2)
    return DPoint3d(v.x / length, v.y / length, v.z / length)


"""
Calculate the bisector direction between three points in 3D space.
    
:param prevVertex: Previous vertex point (DPoint3d).
:param currentVertex: Current vertex point (DPoint3d).
:param nextVertex: Next vertex point (DPoint3d).
:return: The direction of the bisector (DPoint3d).
"""
def calculateBisector(prevVertex, currentVertex, nextVertex):
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


"""
Calculate the new point by moving a certain distance along the bisector direction.
    
:param point: The starting point (DPoint3d).
:param bisectorDirection: The direction of the bisector (DPoint3d).
:param distance: The distance to move along the bisector (float).
:return: The new point (DPoint3d).
"""
def calculateNewPoint(point, bisectorDirection, distance):
    newX = point.x - bisectorDirection.x * distance
    newY = point.y - bisectorDirection.y * distance
    newZ = point.z - bisectorDirection.z * distance
    return DPoint3d(newX, newY, newZ)

'''
Prerequisite: Open MSPythonSamples\data\PythonMeasuringAngleExample.dgn 
'''
#main
if __name__ == "__main__":
    # Execute the function to move circles based on angle bisectors
    measureAngle()
