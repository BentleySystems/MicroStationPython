# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import math

'''
Run the sample on CreateSections.dgn with No WorkSet.
The sample demonstrates following steps:
Identify an element by type(line string), level and color, 
creating multiple sections at intervals along the line string using specific drawing seed, 
and for each section increment the name by 1.
Interval can be set in the script.
'''

interval = 8.0                  #Master unit

elementType = eLINE_STRING_ELM  #Line string
levelName = "Default"           #Level name
#userColorIndex = np.uint32(-1)  #ByLevel
userColorIndex = 0              #Color index
numName = 1                     #Section serial number
secName = "Section"             #Section name string
drawingSeed = "Section_Metric"  #Drawing seed
points = DPoint3dArray()        #Line string points

'''
Class to handle Create Drawing dialog event
'''
class BmrsecModalEventHandler (IPyModalDialogEvents):
    def OnDialogClosed (self,dialogBoxName,dialogResult):
        return

    def OnDialogOpened (self,dialogBoxName):
        global numName
        if dialogBoxName == "Create Drawing":   #Create Drawing dialog
            #dialog settings
            strCmd = "MDL COMMAND CREATEDRAWING_ASSIGNSAVEDVIEWNAME " + secName + str(numName)
            PyCadInputQueue.SendKeyinToPython (strCmd)
            PyCadInputQueue.SendKeyinToPython ("MDL COMMAND CREATEDRAWING_SET_DISCIPLINE General" )
            PyCadInputQueue.SendKeyinToPython ("MDL COMMAND CREATEDRAWING_SET_PURPOSE Section View" )
            PyCadInputQueue.SendKeyinToPython ("MDL COMMAND DRAWCOMP_VISIBLEEDGES 1" )
            PyCadInputQueue.SendKeyinToPython ("MDL COMMAND CREATEDRAWING_ADDSHEETTOSHEETINDEX_OFF" )
            PyCadInputQueue.SendKeyinToPython ("MDL COMMAND CREATEDRAWING_COINCIDENTSHEET_OFF" )
            PyCadInputQueue.SendKeyinToPython ("MDL COMMAND CREATEDRAWING_OPENMODEL_OFF" )
            numName += 1    #increment section name by 1
            return PyMsdDialogBoxResult.ePyMsdDialogBoxResultOK

        return PyMsdDialogBoxResult.ePyMsdDialogBoxResultNo

'''
Function to create sections at intervals along the line string using specific drawing seed, 
all coordinate values were in master unit
'''
def createSection():
    starts = DPoint3dArray()    #start points for section callout
    ends = DPoint3dArray()  #end points for section callout
    vecs = DPoint3dArray()  #direction and depth points for section callout

    #get all needed points to place section callout
    totalLen = 0.0  #calculated length along line string
    countSec = 0    #calculated section count
    for i in range(len(points) - 1):
        length = points[i+1].Distance(points[i])    #segment length of line string
        oVec = DVec3d.FromStartEndNormalize(points[i], points[i+1]) #segment unit vector
        direc = DVec3d(-oVec.z, 0, oVec.x)  #direction perpendicular to segment vector
        origin = points[i] + oVec * (interval * countSec - totalLen)    #first section start point on the segment

        totalLen += length  #add segment length
        totalCount = math.ceil(totalLen/interval)   #section count till the segment end
        #get needed points to place section on segment
        for j in range(totalCount - countSec):
            start = origin + oVec * interval * j    #section start point
            end = start + oVec  #section end point
            starts.append(start)
            ends.append(end)
            vecs.append(end + direc)

        countSec = totalCount

    handler = BmrsecModalEventHandler ()
    PyEventsHandler.AddModalDialogEventsHandler (handler)   #handle Create Drawing dialog event

    for i in range(countSec):
        #place section callout
        strCmd = "DETAILINGSYMBOL SET DRAWINGSEED " + drawingSeed
        PyCadInputQueue.SendKeyin ("PLACE SECTIONCALLOUT" )
        PyCadInputQueue.SendKeyin (strCmd)  #set drawing seed
        PyCadInputQueue.SendKeyin ("DETAILINGSYMBOL SAVEDVIEW ON" )

        PyCadInputQueue.SendDataPoint (starts[i], 3)    #set start point for section callout
        PyCadInputQueue.SendDataPoint (ends[i], 3)  #set end point for section callout
        PyCadInputQueue.SendDataPoint (vecs[i], 3)  #set direction and depth point for section callout

    PyEventsHandler.RemoveModalDialogEventsHandler (handler)
    PyCommandState.StartDefaultCommand()

'''
Function to iterate levels available on model
    lvlName : str      Level name
    lvlId   : int      Level number
'''
def getLevelName(lvlName, lvlId):
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef #get active model
    levelCache = ACTIVEMODEL.GetDgnFile().GetLevelCache()   #get levels

    for level in levelCache:
        levelName = level.GetName()
        levelId   = level.GetLevelId()
        if lvlName == levelName and lvlId == levelId:
            return True

    return False

'''
Function to select elements by type, level and color
    eleType   : MSElementTypes  Element type
    lvlName   : str             Level name
    userColor : int             Color index value
'''
def selectElementsbyTypeLevelAndColor(eleType, lvlName, userColor):
    global points
    dgnModel = ISessionMgr.ActiveDgnModel   #get active model
    graphicalElements = dgnModel.GetGraphicElements()   #get all graphical elements from the model
    #selSetManager = SelectionSetManager.GetManager()

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()    #get element id
        eeh = EditElementHandle(perElementRef, dgnModel)    #get edit element handle
        eh = ElementHandle(perElementRef)   #get element handle
        if eleType != eh.GetElementType():  #line string
            continue

        msElement = eeh.GetElement ()   #get element
        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        if isGraphics and not isInvisible:
            #Level details
            levelId = msElement.ehdr.level
            bMatch = getLevelName(lvlName, levelId)

            propQuery    = ElementPropertiesGetter(eh)
            color        = propQuery.GetColor()

            if bMatch and userColor == color:
                #selSetManager.AddElement(perElementRef,dgnModel)
                curveQuery_LineString = ICurvePathQuery.ElementToCurveVector (eeh)
                pointsUOR = curveQuery_LineString[0].GetLineString()    #get line string points in uor
                factor = ModelRef.GetUorPerMaster(dgnModel) #get uors per master unit
                points = [DPoint3d.FromScale(point, 1.0/factor) for point in pointsUOR] #convert line string points to master unit

                return True

    return False

if __name__ == "__main__":
    if selectElementsbyTypeLevelAndColor(elementType, levelName, userColorIndex):   #identify a line string by level and color
        createSection() #create sections at intervals along the line string using specific drawing seed