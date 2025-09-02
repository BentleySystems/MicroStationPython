from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def createSampleElements(dgnModel):
    """
    Creates sample elements and adds them to the given DGN model.

    :param dgnModel: The DGN model to which the elements will be added.
    :type dgnModel: DgnModelRef
    """
    eeh = EditElementHandle()

    # Create a line
    segment = DSegment3d(DPoint3d(0, 0, 0), DPoint3d(10, 10, 0))
    LineHandler.CreateLineElement(eeh, None, segment, dgnModel.Is3d(), dgnModel)
    eeh.AddToModel()

    # Create a line string
    points = DPoint3dArray([DPoint3d(0, 0, 0), DPoint3d(10, 0, 0), DPoint3d(10, 10, 0), DPoint3d(0, 10, 0)])
    LineStringHandler.CreateLineStringElement(eeh, None, points, dgnModel.Is3d(), dgnModel)
    eeh.AddToModel()

    # Create a B-spline curve
    poles = DPoint3dArray([DPoint3d(0, 0, 0), DPoint3d(5, 5, 0), DPoint3d(10, 0, 0)])
    bsplineCurve = MSBsplineCurve.CreateFromPolesAndOrder(poles, None, None, 3, False, True)
    BSplineCurveHandler.CreateBSplineCurveElement(eeh, None, bsplineCurve, dgnModel.Is3d(), dgnModel)
    eeh.AddToModel()

    # Create a shape
    shapePoints = DPoint3dArray([DPoint3d(0, 0, 0), DPoint3d(5, 0, 0), DPoint3d(5, 5, 0), DPoint3d(0, 5, 0)])
    ShapeHandler.CreateShapeElement(eeh, None, shapePoints, dgnModel.Is3d(), dgnModel)
    eeh.AddToModel()

    # Create a complex shape
    ChainHeaderHandler.CreateChainHeaderElement(eeh, None, True, dgnModel.Is3d(), dgnModel)
    line1 = EditElementHandle()
    LineHandler.CreateLineElement(line1, None, DSegment3d(DPoint3d(0, 0, 0), DPoint3d(10, 0, 0)), dgnModel.Is3d(), dgnModel)
    ChainHeaderHandler.AddComponentElement(eeh, line1)
    line2 = EditElementHandle()
    LineHandler.CreateLineElement(line2, None, DSegment3d(DPoint3d(10, 0, 0), DPoint3d(10, 10, 0)), dgnModel.Is3d(), dgnModel)
    ChainHeaderHandler.AddComponentElement(eeh, line2)
    ChainHeaderHandler.AddComponentComplete(eeh)
    eeh.AddToModel()

def generatePointsAlongCurveVector(dgnModel):
    """
    Generates points along the curve vector and prints them out.
    
    :param dgnModel: The DGN model containing the elements.
    :type dgnModel: DgnModelRef
    """

    graphicalElements = dgnModel.GetGraphicElements()
    options = IFacetOptions.CreateForCurves ()
    options.MaxEdgeLength = 100.0
    
    for elementRef in graphicalElements:
        elementHandle = ElementHandle(elementRef)
        print (f"Element Id : {elementHandle.ElementId} Element Type: {elementHandle.ElementType}\n")
        curve = ICurvePathQuery.ElementToCurveVector(elementHandle)
        if (None != curve):
            points = DPoint3dArray ()
            curve.AddStrokePoints(points, options)
            for point in points:
                print (f"Point {point}\n")

def generatePointsAtDistancesAlongCurveVector(dgnModel):
    """
    Generates points along the curve vector and prints them out.
    
    :param dgnModel: The DGN model containing the elements.
    :type dgnModel: DgnModelRef
    """

    graphicalElements = dgnModel.GetGraphicElements()
    
    for elementRef in graphicalElements:
        elementHandle = ElementHandle(elementRef)
        print (f"Element Id : {elementHandle.ElementId} Element Type: {elementHandle.ElementType}\n")
        curve = ICurvePathQuery.ElementToCurveVector(elementHandle)
            
        if (None != curve):
            length = curve.Length()
            distances = DoubleArray()
            delta = length/ 10.0
            for i in range (10):
                distances.append (i*delta)
            points = CurveLocationDetailArray ()
            curve.AddSpacedPoints(distances, points)
            for point in points:
                ray = ValidatedDRay3d()
                ray = point.PointAndUnitTangent ()
                direction = DVec3d ()
                direction = ray.Value().direction
                print (f"Point: {point.point} UnitTangent: {direction}\n")            


def main():    
    activeModel = ISessionMgr.ActiveDgnModelRef
    dgnModel = activeModel.GetDgnModel()

    # Create sample elements
    createSampleElements(dgnModel)

    # Generate points along the curve vector
    generatePointsAlongCurveVector(dgnModel)
    
    # Generate points along the curve vector at distances
    generatePointsAtDistancesAlongCurveVector(dgnModel)


if __name__ == "__main__":
    main()