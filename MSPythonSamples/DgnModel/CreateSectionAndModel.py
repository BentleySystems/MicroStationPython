# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Run the sample on CreateSectionAndModel.dgn.
The sample demonstrates the following steps:
Identify an element by type (line string), level, and color,
create a section along the line string.
Create Drawing Model.
'''

elementType = eLINE_STRING_ELM  # Line string
levelName = "Default"           # Level name
userColorIndex = 0              # Color index
numName = 1                     # Section serial number
secName = "Section"             # Section name string
drawingSeed = "Section_Metric"  # Drawing seed
points = DPoint3dArray()        # Line string points

'''
Class to handle Create Drawing dialog event
'''
class BmrsecModalEventHandler(IPyModalDialogEvents):
    def OnDialogClosed(self, dialogBoxName, dialogResult):
        return

    def OnDialogOpened(self, dialogBoxName):
        global numName
        if dialogBoxName == "Create Drawing":   # Create Drawing dialog
            # Dialog settings
            strCmd = "MDL COMMAND CREATEDRAWING_ASSIGNSAVEDVIEWNAME " + secName + str(numName)
            PyCadInputQueue.SendKeyinToPython(strCmd)
            PyCadInputQueue.SendKeyinToPython("MDL COMMAND CREATEDRAWING_SET_DISCIPLINE General")
            PyCadInputQueue.SendKeyinToPython("MDL COMMAND CREATEDRAWING_SET_PURPOSE Section View")
            PyCadInputQueue.SendKeyinToPython("MDL COMMAND DRAWCOMP_VISIBLEEDGES 1")
            PyCadInputQueue.SendKeyinToPython("MDL COMMAND CREATEDRAWING_ADDSHEETTOSHEETINDEX_OFF")
            PyCadInputQueue.SendKeyinToPython("MDL COMMAND CREATEDRAWING_COINCIDENTSHEET_OFF")
            PyCadInputQueue.SendKeyinToPython("MDL COMMAND CREATEDRAWING_OPENMODEL_OFF")
            numName += 1  # Increment section name by 1
            return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK

        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultNo

'''
Function to create a section along the line string using a specific drawing seed.
'''
def createSection():
    starts = DPoint3dArray()    # Start points for section callout
    ends = DPoint3dArray()      # End points for section callout
    vecs = DPoint3dArray()      # Direction and depth points for section callout

    # Ensure there are enough points to calculate a section
    if len(points) < 2:
        print("Not enough points to create a section.")
        return

    # Use the first segment of the line string to calculate the section points
    length = points[1].Distance(points[0])  # Segment length of line string
    oVec = DVec3d.FromStartEndNormalize(points[0], points[1])  # Segment unit vector
    direc = DVec3d(-oVec.z, 0, oVec.x)  # Direction perpendicular to segment vector
    origin = points[0] + oVec  # First section start point on the segment

    # Calculate the section points
    start = origin  # Section start point
    end = start + oVec  # Section end point
    starts.append(start)
    ends.append(end)
    vecs.append(end + direc)

    handler = BmrsecModalEventHandler()
    PyEventsHandler.AddModalDialogEventsHandler(handler)  # Handle Create Drawing dialog event

    # Place the section callout
    strCmd = "DETAILINGSYMBOL SET DRAWINGSEED " + drawingSeed
    PyCadInputQueue.SendKeyin("PLACE SECTIONCALLOUT")
    PyCadInputQueue.SendKeyin(strCmd)  # Set drawing seed
    PyCadInputQueue.SendKeyin("DETAILINGSYMBOL SAVEDVIEW ON")

    PyCadInputQueue.SendDataPoint(starts[0], 3)  # Set start point for section callout
    PyCadInputQueue.SendDataPoint(ends[0], 3)    # Set end point for section callout
    PyCadInputQueue.SendDataPoint(vecs[0], 3)    # Set direction and depth point for section callout

    PyEventsHandler.RemoveModalDialogEventsHandler(handler)
    PyCommandState.StartDefaultCommand()

'''
Function to iterate levels available on model
    lvlName : str      Level name
    lvlId   : int      Level number
'''
def getLevelName(lvlName, lvlId):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef  # Get active model
    levelCache = ACTIVEMODEL.GetDgnFile().GetLevelCache()  # Get levels

    for level in levelCache:
        levelName = level.GetName()
        levelId = level.GetLevelId()
        if lvlName == levelName and lvlId == levelId:
            return True

    return False

'''
Function to select elements by type, level, and color
    eleType   : MSElementTypes  Element type
    lvlName   : str             Level name
    userColor : int             Color index value
'''
def selectElementsbyTypeLevelAndColor(eleType, lvlName, userColor):
    global points
    dgnModel = ISessionMgr.ActiveDgnModel  # Get active model
    graphicalElements = dgnModel.GetGraphicElements()  # Get all graphical elements from the model

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()  # Get element id
        eeh = EditElementHandle(perElementRef, dgnModel)  # Get edit element handle
        eh = ElementHandle(perElementRef)  # Get element handle
        if eleType != eh.GetElementType():  # Line string
            continue

        msElement = eeh.GetElement()  # Get element
        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        if isGraphics and not isInvisible:
            # Level details
            levelId = msElement.ehdr.level
            bMatch = getLevelName(lvlName, levelId)

            propQuery = ElementPropertiesGetter(eh)
            color = propQuery.GetColor()

            if bMatch and userColor == color:
                curveQuery_LineString = ICurvePathQuery.ElementToCurveVector(eeh)
                pointsUOR = curveQuery_LineString[0].GetLineString()  # Get line string points in UOR
                factor = ModelRef.GetUorPerMaster(dgnModel)  # Get UORs per master unit
                points = [DPoint3d.FromScale(point, 1.0 / factor) for point in pointsUOR]  # Convert line string points to master unit

                return True

    return False

if __name__ == "__main__":
    if selectElementsbyTypeLevelAndColor(elementType, levelName, userColorIndex):  # Identify a line string by level and color
        createSection()  # Create a single section along the line string using a specific drawing seed