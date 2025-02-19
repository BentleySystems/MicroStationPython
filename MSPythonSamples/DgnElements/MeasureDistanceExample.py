from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import math


"""
Retrieve circles and B-spline elements from the active model.
    
:return: A tuple containing lists of circles and B-spline elements.
"""
def getActiveModelGraphicalElements():
    activeModel = ISessionMgr.ActiveDgnModelRef
    dgnModel = activeModel.GetDgnModel()
    graphicalElements = dgnModel.GetGraphicElements()

    circles = []
    bSpline = MSElement()
    
    # Process graphical elements to find circles and the B-spline
    for elementRef in graphicalElements:
        editElementHandle = EditElementHandle(elementRef, dgnModel)
        elementHandle = ElementHandle(elementRef)
        msElement = editElementHandle.GetElement()
        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        # Only process visible graphical elements
        if isGraphics and not isInvisible:
            elementType = elementHandle.GetElementType()
            if elementType == 27:  # B-Spline
                bSpline = editElementHandle
            elif elementType == 15:  # Circle
                circles.append(editElementHandle)

    return circles, bSpline


"""
Measure the distance from each circle to the closest point on the B-spline.
    
:return: A list of tuples containing circle data, closest points, distances, and cloned arcs.
"""
def measureDistancesFromCirclesToBspline():
    circles, bSpline = getActiveModelGraphicalElements()

    circleDistances = []
    
    # bSpline curve primitive
    curve = ICurvePathQuery.ElementToCurveVector(bSpline)
    curvePrimitive = curve[0]
    
    # Process each circle and calculate the distance to the B-spline
    for circle in circles:
        # circle curve primitve
        curve = ICurvePathQuery.ElementToCurveVector(circle)
        arcCurvePrimitive = curve[0]
        
        # Find the circle center
        circleCenter = arcCurvePrimitive.Arc.center
        
        vector0 = arcCurvePrimitive.Arc.vector0
        radius = vector0.Magnitude()

        # Find the closest point on the B-spline
        closestPointBounded = curvePrimitive.ClosestPointBounded(circleCenter)
        closestPoint = closestPointBounded[2]

        # Calculate the distance between circle center and closest point on B-spline
        distance = circleCenter.Distance(closestPoint)
        
        # Store the circle, closest point, distance, and clone data
        circleDistances.append((circle, closestPoint, distance, radius, circleCenter))

    return circleDistances


"""
Calculates the new center coordinates of the circle to be drawn on the opposite side of the B-spline.
:param circleCenter: The original center of the circle (DPoint3d).
:param closestPoint: The closest point on the B-spline (DPoint3d).
:param distance: The distance between the circle center and the closest point (float).
:param clone: A clone of the original circle (MSElement).
:return: New coordinates for the circle to be placed on the opposite side.
"""
def calculateOppositeSideCircleCenter(circleCenter, closestPoint, distance):
    # Calculate the direction vector from the circle center to the closest point
    direction = DPoint3d()
    direction.DifferenceOf(circleCenter, closestPoint)
    direction.Normalize()

    # Calculate the new position for the circle by moving it to the opposite side
    newCenter = DPoint3d(
        circleCenter.x - 2 * direction.x * distance,
        circleCenter.y - 2 * direction.y * distance,
        circleCenter.z - 2 * direction.z * distance
    )

    return newCenter


"""
Creates an ellipse (representing the circle) at the specified position using the radius from the circle's clone.
    
:param basePoint: The center of the new ellipse (DPoint3d).
:param clone: The clone of the original circle (MSElement).
:return: Boolean indicating success or failure.
"""
def createCircleAtPosition(basePoint, radius):
    activeModel = ISessionMgr.ActiveDgnModelRef
    if activeModel is None:
        return False


    # Create an ellipse (representing the circle) at the base point
    ellipse = DEllipse3d.FromCenterRadiusXY(basePoint, radius)

    # Create ellipse element
    eeh = EditElementHandle()
    status = EllipseHandler.CreateEllipseElement(eeh, None, ellipse, activeModel.Is3d(), activeModel)
    
    if BentleyStatus.eSUCCESS != status:
        return False

    # Add the ellipse element to the model
    return BentleyStatus.eSUCCESS == eeh.AddToModel()


"""
Measures distances from circles to the B-spline and draws arcs on the opposite side of the B-spline.
"""
def drawCircleOnOppositeSide():
    
    # Get the circles data and their distance from bspline
    circleDistances = measureDistancesFromCirclesToBspline()

    for circleData in circleDistances:
        circleCenter = calculateOppositeSideCircleCenter(
            circleCenter=circleData[4],
            closestPoint=circleData[1],
            distance=circleData[2],
        )
        radius=circleData[3]
        # Create an arc at the new position
        createCircleAtPosition(circleCenter, radius)



'''
Prerequisite : Run the sample on PythonMeasuringDistanceExample.dgn
'''
#main
if __name__ == "__main__":

    # Execute the function to move circles and draw circle on the opposite side of the B-spline
    drawCircleOnOppositeSide()
