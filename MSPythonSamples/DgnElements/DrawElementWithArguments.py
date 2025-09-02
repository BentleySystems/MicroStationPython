# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
import sys

'''
 Sample demonstrating how to pass arguments to python script. 
 
 In Python, you can use sys.argv to handle command line arguments passed to a Python script.
 argv[0] is the script name, so you can get your own arguments begin from argv[1].
 This sample shows how to draw Line or Circle with different arguments.
 1. Draw Line:
      argument1: Pass "Line" to draw a line
      argument2: x coordinate of line start point
      argument3: y coordinate of line start point
      argument4: z coordinate of line start point
      argument5: x coordinate of line end point
      argument6: y coordinate of line end point
      argument7: z coordinate of line end point
    So you can pass "Line 0 0 0 10 10 10" as the arguments from Python Manager then run it to draw a line from (0, 0, 0) to (10, 10, 10).
 2. Draw Circle:
      argument1: Pass "Circle" to draw a circle
      argument2: x coordinate of circle center point
      argument3: y coordinate of circle center point
      argument4: z coordinate of circle center point
      argument5: radius of circle
    So you can pass "Circle 0 0 0 10" as the arguments from Python Manager then run it to draw a circle at (0, 0, 0) with radius 10.
 3. Pass any other arguments format will be invalid and it will print a message "Arguments error!"
'''

# Draw a line with given start point and end point
def drawLine(startPoint, endPoint):
    """
    Draws a line between two points in the active DGN model.

    :param startPoint: The starting point of the line.
    :type startPoint: Point3d
    :param endPoint: The ending point of the line.
    :type endPoint: Point3d

    :returns: None
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    eeh = EditElementHandle()
    seg = DSegment3d(startPoint, endPoint)
    LineHandler.CreateLineElement(eeh, None, seg, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
    eeh.AddToModel()

# Draw a circle with given center point and radius
def drawCircle(centerPoint, radius):
    """
    Draws a circle in the active DGN model.

    :param centerPoint: The center point of the circle.
    :type centerPoint: Point3d
    :param radius: The radius of the circle.
    :type radius: float

    :returns: None
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    eeh = EditElementHandle()
    ell = DEllipse3d.FromCenterRadiusXY(centerPoint, radius)
    ArcHandler.CreateArcElement(eeh, None, ell, ACTIVEMODEL.Is3d(), ACTIVEMODEL)
    eeh.AddToModel()


if __name__ == "__main__":
    print("Argument list:", sys.argv)
    if len(sys.argv) == 8 and sys.argv[1].lower() == "line":
        startPoint = DPoint3d(int(sys.argv[2]),int(sys.argv[3]),int(sys.argv[4]))
        endPoint = DPoint3d(int(sys.argv[5]),int(sys.argv[6]),int(sys.argv[7]))
        drawLine(startPoint, endPoint)
    elif len(sys.argv) == 6 and sys.argv[1].lower() == "circle":
        centerPoint = DPoint3d(int(sys.argv[2]),int(sys.argv[3]),int(sys.argv[4]))
        radius = int(sys.argv[5])
        drawCircle(centerPoint, radius)
    else:
        print("Arguments error!")
  
