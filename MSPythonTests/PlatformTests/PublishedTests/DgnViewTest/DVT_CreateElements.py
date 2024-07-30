#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

INVALID_MODELID = -2

# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    # origin  = "E:\\MicrostationVenus5\\source\\"
    if not origin:
        return origin
    origin += fileLocation
    return origin

# fetch given file from the directory
def getFileFromDirectory(fileName, fileDir):
    ret = DgnDocument.CreateFromFileName (fileName, fileDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()
    return dgnFile

# prerequisite function to get folder location and dgn file
def setUpTest(fileName):
    fileLocation = "MSPython\\MSPythonTests\\PlatformTests\\data\\"
    fileDir = getRoot(fileLocation)
    dgnFile = getFileFromDirectory(fileName, fileDir)
    assert dgnFile != None
    # viewGroup = setActiveViewGroup(dgnFile)
    # assert viewGroup.IsValid()
    return dgnFile

# Test to create ellipse element
def test_CreateEllipse(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)
    # m_defaultModel = dgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)

    center2 = DPoint3d()
    center2.Init(0,0,0)
    ellipseEeh = EditElementHandle()

    # create ellipse from above created point and add to model
    status = EllipseHandler.CreateEllipseElement(ellipseEeh, None, center2, 5000, 3000, 0, False, m_defaultModel[0])
    if (status != BentleyStatus.eSUCCESS):
        assert False

    ellipseEeh.AddToModel()

# Test to create line element
def test_CreateLine(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    segment = DSegment3d(0.0, 0.0, 0.0, 0.0, 1000.0, 0.0)

    lineEeh = EditElementHandle()

    # create line using above created segement and add to model
    status = LineHandler.CreateLineElement(lineEeh, None, segment, False, m_defaultModel[0])
    if (status != BentleyStatus.eSUCCESS):
        assert False

    lineEeh.AddToModel()

# Test to create arc element
def test_CreateArc(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    center1 = DPoint3d()
    center1.Init(-500,0,0)
    arcEeh = EditElementHandle()

    PI = 3.141592653589793238463

    # create arc using above defined center point and add to model
    status = ArcHandler.CreateArcElement(arcEeh, None, center1, 5000, 5000, 0, 0, -(PI/2), False, m_defaultModel[0])
    if (status != BentleyStatus.eSUCCESS):
        assert False

    arcEeh.AddToModel()

# Test to create curve element
def test_CreateCurve(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    points1 = DPoint3dArray([DPoint3d(0,600,0), DPoint3d(0,200,0), DPoint3d(0,800,0), DPoint3d(800, -900,0), DPoint3d(200, -600,0), DPoint3d(400, -200,0)])
    curveEeh = EditElementHandle()

    # create curve using above defined point array and add to model
    status = CurveHandler.CreateCurveElement (curveEeh, None, points1, False, m_defaultModel[0])
    if (status != BentleyStatus.eSUCCESS):
        assert False

    curveEeh.AddToModel()

# Test to create line string element
def test_CreateLineString(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    points2 = DPoint3dArray([DPoint3d(0,0,0), DPoint3d(0,10000,0), DPoint3d(10000,10000,0), DPoint3d(10000,0,0)])
    lineStringEeh = EditElementHandle()

    # create line string using defined point array and add to model
    status = LineStringHandler.CreateLineStringElement(lineStringEeh, None, points2, False, m_defaultModel[0])
    if(status != BentleyStatus.eSUCCESS):
        assert False

    lineStringEeh.AddToModel()

# Test to create point string element
def test_CreatePointString(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    points3 = DPoint3dArray([DPoint3d(-10000, 0, 0), DPoint3d(-10000, 1000, 0), DPoint3d(-10000, 2000, 0), DPoint3d(-10000, 3000, 0)])
    pointStringEeh = EditElementHandle()
    rotArray = RotMatrixArray()

    # create point string using above defined point array and add to model
    status = PointStringHandler.CreatePointStringElement(pointStringEeh, None, points3, rotArray, False, False, m_defaultModel[0])
    if(status != BentleyStatus.eSUCCESS):
        assert False

    pointStringEeh.AddToModel()

# Test to create shape element
def test_CreateShape(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    points4 = DPoint3dArray([DPoint3d(-1000,1000,0), DPoint3d(-1000,2000,0), DPoint3d(-500,2000,0), DPoint3d(-500,1000,0)])
    shapeEeh = EditElementHandle()

    # create any shape using above defined point array and add to model
    status = ShapeHandler.CreateShapeElement(shapeEeh, None, points4, False, m_defaultModel[0])
    if(status != BentleyStatus.eSUCCESS):
        assert False

    shapeEeh.AddToModel()

# Test to create bsp line curve element
def test_CreateBSPlineCurve(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    order = 4
    numPoints = 4
    pPoints = DPoint3dArray([DPoint3d(-5,-5,0), DPoint3d(0,5,0), DPoint3d(5,-5,0), DPoint3d(10,0,0)])

    # craete msbsplinecurve using point and order and then add to model
    curve = MSBsplineCurve.Create()
    curve.CreateFromPointsAndOrder(pPoints, numPoints, order)

    assert BSplineStatus.eBSPLINE_STATUS_Success == BSplineCurveHandler.IsValidCurve(curve)
    bsplineCurveEeh = EditElementHandle()

    if(BSplineStatus.eBSPLINE_STATUS_Success != BSplineCurveHandler.CreateBSplineCurveElement (bsplineCurveEeh, None, curve, False, m_defaultModel[0])):
        assert False

    bsplineCurveEeh.AddToModel()
    dgnFile.ProcessChanges(DgnSaveReason.eUserInitiated,0)
    assert False == dgnFile.HasPendingChanges()

# Test to create cone element
def test_CreateCone(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    topRadius = 1.8
    bottomRadius= 0.4
    topCenter = DPoint3d()
    topCenter.Init(-1.8, -1.99, 0)
    bottomCenter = DPoint3d()
    bottomCenter.Init(-0.8, 0.4, 0)
    rotation = RotMatrix()
    rotation.InitFromRowValues(0.9, 0, -9.0, -9.0, 0, -0.9, 0, 1, 0)
    coneEeh = EditElementHandle()

    # create cone element using above defined center points, radius and rotation and add to model
    status = ConeHandler.CreateConeElement(coneEeh, None, topRadius, bottomRadius, topCenter, bottomCenter, rotation, True, m_defaultModel[0])
    if(status != BentleyStatus.eSUCCESS):
        assert False

    coneEeh.AddToModel()

    dgnFile.ProcessChanges(DgnSaveReason.eUserInitiated,0)
    assert False == dgnFile.HasPendingChanges()

# Test to create multiline element
def test_CreateMultiline(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    # create multiline profile and set required properties
    m_profile= MultilineProfile()
    m_profile.SetLinestyle(7)
    m_profile.SetUsesLinestyle(True)
    m_profile.SetColor(35)
    m_profile.SetUseColor(True)

    # create second multiline profile and set required properties
    m_profile2= MultilineProfile()
    m_profile2.SetDistance(-1)

    # create third multiline profile and set required properties
    m_profile1= MultilineProfile()
    m_profile1.SetDistance(1)

    #Remove old one with "TempMStyle" as its name, otherwise the following m_style.Add() will be failed
    oldStyle = MultilineStyle.GetByName ("TempMStyle", dgnFile)
    if None != oldStyle:
        oldStyle.Delete ("TempMStyle", dgnFile)

    # create new multiline style and add defined profiles to it
    m_style = MultilineStyle.Create("TempMStyle", dgnFile)
    assert BentleyStatus.eSUCCESS == (m_style.InsertProfile (m_profile, int(1)))
    assert BentleyStatus.eSUCCESS == (m_style.InsertProfile (m_profile2, int(1)))
    assert BentleyStatus.eSUCCESS == (m_style.InsertProfile (m_profile1, int(1)))
    assert BentleyStatus.eSUCCESS == m_style.Add()

    numPoints = 3
    pPoints = DPoint3dArray([DPoint3d(2,5,0), DPoint3d(5,5,0), DPoint3d(5,3,0)])

    normal = DVec3d()
    normal.From(0,0,1)

    multilineEeh = EditElementHandle()

    # create multiline element using above defined multiline style and add to model
    assert BentleyStatus.eSUCCESS ==  MultilineHandler.CreateMultilineElement(multilineEeh , None, m_style, 1, normal, pPoints, False, m_defaultModel[0])
    multilineEeh.AddToModel()

    dgnFile.ProcessChanges(DgnSaveReason.eUserInitiated,0)
    assert False == dgnFile.HasPendingChanges()

# Test to create text element
def test_CreateText(initDgnPlatformHost):
    dgnFile = setUpTest("Blank.dgn")
    assert dgnFile != None
    masterID = dgnFile.FindModelIdByName("Default")
    assert masterID != INVALID_MODELID
    m_defaultModel = dgnFile.LoadRootModelById(masterID, True, True, True)

    # get default fonts and sizes of the texts and create text string properties using these
    font = DgnFontManager.GetDefaultShxFont()
    bigfont = DgnFontManager.GetDefaultShxBigFont()
    fontsize = DPoint2d.From(11.0,11.0)
    prop = TextStringProperties.Create (font, bigfont, fontsize, m_defaultModel[0])

    rotation= RotMatrix()
    rotation.InitFromRowValues(1,0,0,0,1,0,0,0,1)

    lowerLeft = DPoint3d()
    lowerLeft.Init(0, 1000, 0)

    # define text string by providing string and defined point, rotation and properties
    txtString = TextString ("This is String", lowerLeft, rotation, prop)

    # create text style for the given dgnfile
    textStyle = DgnTextStyle("TempTextStyle", dgnFile)

    # create text block with the above defined style and add text as required
    textBlock = TextBlock (textStyle, m_defaultModel[0])
    textBlock.AppendText ("This is a text block string ")

    textEeh = EditElementHandle()

    # ceate text element using above created text block and add to model
    result = TextHandlerBase.CreateElement (textEeh, None, textBlock)
    if(result == eTEXTBLOCK_TO_ELEMENT_RESULT_Success):
        textEeh.AddToModel()
    elif(result == eTEXTBLOCK_TO_ELEMENT_RESULT_Empty):
        assert False
    else:
        assert False

    dgnFile.ProcessChanges(DgnSaveReason.eUserInitiated,0)
    assert False == dgnFile.HasPendingChanges()
