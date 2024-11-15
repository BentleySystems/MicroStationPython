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

endoflist = 0xffffffff
MLINE_BREAKS_ALLLINES = 0xffffffff
CENTER_OFFSET = 0.0
MAX_OFFSET = 10.0
MIN_OFFSET = -20.0
CUSTOM_OFFSET = 17.0

@pytest.mark.parametrize('fileName', ['noStyleSeed.dgn'])
def test_AddNoStyleSeed(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    #if loadDgnFile == None:
    #    dgnFile = loadDgnFile
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    if None == ret[0]:
        dgnFile = None
    else:
        dgnFile = loadDgnFile
        
    assert dgnFile != None
    
    stylename = "TestStyle"
    mlstyle = MultilineStyle.Create(stylename, dgnFile)
    
    styleprof = MultilineProfile()
    
    assert BentleyStatus.eSUCCESS == (mlstyle.InsertProfile(styleprof, endoflist))
    assert BentleyStatus.eSUCCESS == mlstyle.Add()

@pytest.mark.skip(reason="Ping.Chen, error in bb r platformtests")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Add2dMetricGeneral(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    #if loadDgnFile == None:
    #    dgnFile = loadDgnFile
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    if None == ret[0]:
        dgnFile = None
    else:
        dgnFile = loadDgnFile
        
    assert dgnFile != None
    
    stylename = "TestStyle"
    mlstyle = MultilineStyle.Create(stylename, dgnFile)
    
    styleprof = MultilineProfile()
    
    assert BentleyStatus.eSUCCESS == (mlstyle.InsertProfile(styleprof, endoflist))
    assert BentleyStatus.eSUCCESS == mlstyle.Add()
    
@pytest.mark.parametrize('fileName', ['noStyleSeed.dgn'])
def test_DeleteNoStyleSeed(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    #if loadDgnFile == None:
    #    dgnFile = loadDgnFile
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    ret = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    if None == ret[0]:
        dgnFile = None
    else:
        dgnFile = loadDgnFile
        
    assert dgnFile != None
    
    # Try to delete a non-existant style before there is a style table
    assert BentleyStatus.eERROR == MultilineStyle.Delete("BogusStyle", dgnFile)
    
    styleName = "TestStyle"
    mlstyle = MultilineStyle.Create(styleName, dgnFile)
    
    styleprof = MultilineProfile()
    
    assert BentleyStatus.eSUCCESS == (mlstyle.InsertProfile(styleprof, endoflist))
    assert BentleyStatus.eSUCCESS == mlstyle.Add()
    
    #  Try to delete a non-existant style
    assert BentleyStatus.eERROR == MultilineStyle.Delete("BogusStyle", dgnFile)
    
    # Delete the style we created
    assert BentleyStatus.eSUCCESS == MultilineStyle.Delete(styleName, dgnFile)
    
# BeStringUtilities not exposed  
@pytest.mark.skip(reason="NEEDS WORK: Fix Me")
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Iterator(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    if loadDgnFile == None:
        assert False
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    testName = "MlstyleIterator"
    numStyles = 10
    
    for iStyle in range(0, numStyles):
        name = ""
        # BeStringUtilities.Snwprintf (name, "%ls-%d", testName, iStyle+1)
        
        mlinestyle = MultilineStyle.Create(name, dgnFile)
        
        # Must have 1 profile
        styleprof = MultilineProfile()
        assert BentleyStatus.eSUCCESS == mlinestyle.InsertProfile(styleprof, endoflist)
        
        if BentleyStatus.eSUCCESS != mlinestyle.Add():
            assert False
            
    iStyle = 0
    collection = MultilineStyleCollection(dgnFile)
    
    for mlinestyle in collection:
        expectedName = ""
        # BeStringUtilities.Snwprintf (expectedName, "%ls-%d", testName, iStyle+1)
        
        assert expectedName == repr(mlinestyle.GetName())
        
        iStyle = iStyle + 1
    
    assert iStyle == numStyles


@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IteratorEmpty(initDgnPlatformHost, loadDgnFileReadOnly):
    if loadDgnFileReadOnly == None:
        assert False
    
    collection = MultilineStyleCollection(loadDgnFileReadOnly)

    for mlineStyle in dir(collection):
        if not mlineStyle.startswith("__"):
            # We didn't add any styles, so we shouldn't get here
            assert False
    
@pytest.mark.parametrize('fileName', ['noStyleSeed.dgn'])
def test_IteratorEmptyNoStyleSeed(initDgnPlatformHost, loadDgnFileReadOnly):
    if loadDgnFileReadOnly == None:
        assert False
    
    collection = MultilineStyleCollection(loadDgnFileReadOnly)

    for mlineStyle in dir(collection):
        if not mlineStyle.startswith("__"):
            # We didn't add any styles, so we shouldn't get here
            assert False

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])        
def test_OffsetMode(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()
    
    assert None != mlHandler
    
    mlstyle = m_mlineStyle
    
    # Defaults to Work line
    assert MlineOffsetMode.eByWork == mlHandler.GetOffsetMode(mlineElm)
    
    # Set to MAX
    mlHandler.SetOffsetMode(mlineElm, MlineOffsetMode.eByMax)
    assert MlineOffsetMode.eByMax == mlHandler.GetOffsetMode(mlineElm)
    mlHandler.ApplyStyle (mlineElm, mlstyle, 1.0)
    assert (-MAX_OFFSET) == mlHandler.GetProfile(mlineElm, 0).GetDistance()
    
    # Set to MIN
    mlHandler.SetOffsetMode(mlineElm, MlineOffsetMode.eByMin)
    assert MlineOffsetMode.eByMin == mlHandler.GetOffsetMode(mlineElm)
    mlHandler.ApplyStyle (mlineElm, mlstyle, 1.0)
    assert (-MIN_OFFSET) == mlHandler.GetProfile(mlineElm, 0).GetDistance()
    
    # Set to CENTER
    mlHandler.SetOffsetMode(mlineElm, MlineOffsetMode.eByCenter)
    assert MlineOffsetMode.eByCenter == mlHandler.GetOffsetMode(mlineElm)
    mlHandler.ApplyStyle (mlineElm, mlstyle, 1.0)
    assert (-(MAX_OFFSET+MIN_OFFSET)/2) == mlHandler.GetProfile(mlineElm, 0).GetDistance()
    
    # Set to CUSTOM
    mlHandler.SetOffsetMode (mlineElm, MlineOffsetMode.eCustom)
    mlHandler.SetPlacementOffset(mlineElm, CUSTOM_OFFSET)
    assert MlineOffsetMode.eCustom == mlHandler.GetOffsetMode(mlineElm)
    mlHandler.ApplyStyle (mlineElm, mlstyle, 1.0)
    assert CUSTOM_OFFSET == mlHandler.GetPlacementOffset(mlineElm)
    
    mlHandler.ApplyStyle(mlineElm, mlstyle, 1.0)
    assert (-CUSTOM_OFFSET) == mlHandler.GetProfile(mlineElm, 0).GetDistance()
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])     
def test_SetClosed(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()
    
    assert None != mlHandler
    
    # Default created mline is 3 points, not closed
    assert BentleyStatus.eERROR == mlHandler.SetClosed(mlineElm, True)
    assert BentleyStatus.eSUCCESS == mlHandler.SetClosed(mlineElm, False)
    
    # This mline is 4 points and closed (points are equal).
    normal1 = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points1 = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0), DPoint3d(0.0, 0.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(mlineElm, None, m_mlineStyle, 1.0, normal1, points1, False, m_model[0])
    
    assert BentleyStatus.eSUCCESS == mlHandler.SetClosed(mlineElm, True)
    assert BentleyStatus.eSUCCESS == mlHandler.SetClosed(mlineElm, True) #Repeat; goes through shortcut case
    assert BentleyStatus.eSUCCESS == mlHandler.SetClosed(mlineElm, False)
    
    assert 4 == mlHandler.GetPointCount(mlineElm)
    
    pt1 = mlHandler.GetPoint(mlineElm, 0).GetPoint()
    pt2 = mlHandler.GetPoint(mlineElm, 3).GetPoint()
    
    assert pt1.x == pt2.x
    assert pt1.y == pt2.y
    assert pt1.z == pt2.z

def test_CreateBreaks():
    mlbreak1 = MultilineBreak(10.0, eMLBREAK_STD, 5.0, MLINE_BREAKS_ALLLINES)
    assert eMLBREAK_STD == mlbreak1.GetLengthType()
    assert 5.0 == mlbreak1.GetLength()
    assert 10.0 == mlbreak1.GetOffset()
    assert MLINE_BREAKS_ALLLINES == mlbreak1.GetProfileMask()
    
    mlbreak2 = MultilineBreak(11.61, eMLBREAK_BETWEEN_JOINTS, 35.0, 0x3)
    assert eMLBREAK_BETWEEN_JOINTS == mlbreak2.GetLengthType()
    assert 35.0 == mlbreak2.GetLength()
    assert 11.61 == mlbreak2.GetOffset()
    assert 0x3 == mlbreak2.GetProfileMask()
    
def test_ChangeLength():
    mlbreak1 = MultilineBreak(10.0, eMLBREAK_STD, 5.0, MLINE_BREAKS_ALLLINES)
    assert eMLBREAK_STD == mlbreak1.GetLengthType()
    assert 5.0 == mlbreak1.GetLength()
    
    mlbreak1.SetLengthType(eMLBREAK_BETWEEN_JOINTS)
    assert eMLBREAK_BETWEEN_JOINTS == mlbreak1.GetLengthType()
    
    mlbreak1.SetLengthType(eMLBREAK_FROM_JOINT)
    assert eMLBREAK_FROM_JOINT == mlbreak1.GetLengthType()
    
    mlbreak1.SetLengthType(eMLBREAK_TO_JOINT)
    assert eMLBREAK_TO_JOINT == mlbreak1.GetLengthType()
    
    mlbreak1.SetLengthType(eMLBREAK_STD)
    assert eMLBREAK_STD == mlbreak1.GetLengthType()
    
    mlbreak1.SetLength (20.07)
    assert 20.07 == mlbreak1.GetLength()
    
    mlbreak1.SetLengthType (eMLBREAK_BETWEEN_JOINTS);
    mlbreak1.SetLength (10.10)
    assert 10.10 == mlbreak1.GetLength()
    
def test_ChangeOffset():
    mlbreak1 = MultilineBreak(10.0, eMLBREAK_STD, 5.0, MLINE_BREAKS_ALLLINES)
    assert 10.0 == mlbreak1.GetOffset()
    
    mlbreak1.SetOffset(17.23)
    assert 17.23 == mlbreak1.GetOffset()
    
    try:
        mlbreak1.SetOffset(-11.51)
    except:
        assert 17.23 == mlbreak1.GetOffset()
        
def test_ChangeMask():
    mlbreak1 = MultilineBreak(10.0, eMLBREAK_STD, 5.0, MLINE_BREAKS_ALLLINES)
    assert MLINE_BREAKS_ALLLINES == mlbreak1.GetProfileMask()
    assert True == mlbreak1.ProfileIsMasked(0)
    assert True == mlbreak1.ProfileIsMasked(1)
    assert True == mlbreak1.ProfileIsMasked(2)
    assert True == mlbreak1.ProfileIsMasked(3)
    assert True == mlbreak1.ProfileIsMasked(4)
    assert True == mlbreak1.ProfileIsMasked(5)
    assert True == mlbreak1.ProfileIsMasked(6)
    assert True == mlbreak1.ProfileIsMasked(7)
    assert True == mlbreak1.ProfileIsMasked(8)
    assert True == mlbreak1.ProfileIsMasked(9)
    assert True == mlbreak1.ProfileIsMasked(10)
    assert True == mlbreak1.ProfileIsMasked(11)
    assert True == mlbreak1.ProfileIsMasked(12)
    assert True == mlbreak1.ProfileIsMasked(13)
    assert True == mlbreak1.ProfileIsMasked(14)
    assert True == mlbreak1.ProfileIsMasked(15)
    
    mlbreak1.SetProfileMask(0x5)
    assert 0x5 == mlbreak1.GetProfileMask()
    assert True == mlbreak1.ProfileIsMasked(0)
    assert True == mlbreak1.ProfileIsMasked(2)
    assert False == mlbreak1.ProfileIsMasked(1)
    assert False == mlbreak1.ProfileIsMasked(15)
    
    mlbreak1.SetProfileMask(0)
    assert 0 == mlbreak1.GetProfileMask()
    assert False == mlbreak1.ProfileIsMasked(1)
    assert False == mlbreak1.ProfileIsMasked(3)


class CreateMlineBreakData:
    segment = 0
    offset = 0.0
    mtype = MlineBreakLengthType(0)
    length = 0.0
    mask = 0
    
    def __init__(self, segment, offset, mtype, length, mask):
        self.segment = segment
        self.offset = offset
        self.mtype = mtype
        self.length = length
        self.mask = mask

def CreateMlineBreak(data, mlineElm, mHandler):
    mlbreak1 = MultilineBreak(data.offset, data.mtype, data.length, data.mask)
    return mHandler.InsertBreak(mlineElm, mlbreak1, data.segment)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_InsertBreaks(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()
    
    assert None != mlHandler
    
    assert 0 == mlHandler.GetBreakCount(mlineElm)
    
    mlbreak1 = MultilineBreak(10.0, eMLBREAK_STD, 5.0, MLINE_BREAKS_ALLLINES)
    assert BentleyStatus.eSUCCESS == mlHandler.InsertBreak(mlineElm, mlbreak1, 0)
    assert 1 == mlHandler.GetBreakCount(mlineElm)
    
    # Try to insert it past the end of the mline
    mlbreak2 = MultilineBreak(11.61, eMLBREAK_BETWEEN_JOINTS, 35.0, 0x3)
    assert BentleyStatus.eERROR == mlHandler.InsertBreak(mlineElm, mlbreak2, 4)
    assert 1 == mlHandler.GetBreakCount(mlineElm)
    
    # Insert it on the second segment
    assert BentleyStatus.eSUCCESS == mlHandler.InsertBreak(mlineElm, mlbreak2, 1)
    assert 2 == mlHandler.GetBreakCount(mlineElm)
    
    # Put a second break on the first segment
    mlbreak3 = MultilineBreak(4.72, eMLBREAK_STD, 4.4, 0x1)
    assert BentleyStatus.eSUCCESS == mlHandler.InsertBreak(mlineElm, mlbreak3, 0)
    assert 3 == mlHandler.GetBreakCount(mlineElm)
    
    # Putting another break on the second segment shouldn't increase it.
    mlbreak4 = MultilineBreak(5.55, eMLBREAK_STD, 10.0, 0x1)
    assert BentleyStatus.eSUCCESS == mlHandler.InsertBreak(mlineElm, mlbreak4, 1)
    assert 3 == mlHandler.GetBreakCount(mlineElm)
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_GetBreak(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()
    
    # Initialized in the order they will appear on the line
    testData0 = CreateMlineBreakData(0, 4.74, eMLBREAK_FROM_JOINT, 4.4, 0x1)
    testData1 = CreateMlineBreakData(0, 10.0, eMLBREAK_STD, 5.0, MLINE_BREAKS_ALLLINES)
    testData2 = CreateMlineBreakData(1, 11.23, eMLBREAK_TO_JOINT, 35.0, 0x3)
    
    testData = [testData0, testData1, testData2]
    # Don't insert them in the order that they should end up
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[1], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[2], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[0], mlineElm, mlHandler)
    
    # Should have 3 breaks on the mline here - 2 on the first, one on the second.
    tmpPoint = mlHandler.GetPoint(mlineElm, 0)
    assert 2 == tmpPoint.GetNumBreaks()
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 1)
    assert 1 == tmpPoint.GetNumBreaks()
    
    # Roll over the breaks and make sure they are correct
    iTestData = 0
    for iPoint in range(0, mlHandler.GetPointCount(mlineElm)):
        curPoint = mlHandler.GetPoint(mlineElm, iPoint)
        
        for iSegBreak in range(0, curPoint.GetNumBreaks()):
            curBreak = mlHandler.GetBreak(mlineElm, iPoint, iSegBreak)
            
            assert testData[iTestData].mtype == curBreak.GetLengthType()
            assert testData[iTestData].length == curBreak.GetLength()
            assert testData[iTestData].offset == curBreak.GetOffset()
            assert testData[iTestData].mask == curBreak.GetProfileMask()
            iTestData = iTestData + 1
            
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_OverlapBreaks(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()  
    
    # Initialized in the order they will appear on the line
    testData0 = CreateMlineBreakData(0, 4.74, eMLBREAK_FROM_JOINT, 15, MLINE_BREAKS_ALLLINES)
    testData1 = CreateMlineBreakData(0, 10.0, eMLBREAK_STD, 25.0, MLINE_BREAKS_ALLLINES)
    testData = [testData0, testData1]
    
    # The results below are based on which order they are added.  Second one added wins.
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[0], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[1], mlineElm, mlHandler)
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 0)
    assert 1 == tmpPoint.GetNumBreaks()
    
    curBreak = mlHandler.GetBreak(mlineElm, 0, 0)

    assert testData[1].mtype == curBreak.GetLengthType()
    assert testData[1].length == curBreak.GetLength()
    assert testData[1].offset == curBreak.GetOffset()
    assert testData[1].mask == curBreak.GetProfileMask() 
    
    # Retest on second segment, in opposite order
    testData[0].segment = testData[1].segment = 1
    
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[1], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[0], mlineElm, mlHandler)   
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 1)
    assert 1 == tmpPoint.GetNumBreaks()
    
    curBreak = mlHandler.GetBreak(mlineElm, 1, 0)
    
    assert testData[0].mtype == curBreak.GetLengthType()
    assert testData[0].length == curBreak.GetLength()
    assert testData[0].offset == curBreak.GetOffset()
    assert testData[0].mask == curBreak.GetProfileMask() 

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_MultisegmentBreaks(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()
    
    # Initialized in the order they will appear on the line
    testData0 = CreateMlineBreakData(0, 4.74, eMLBREAK_FROM_JOINT, 15, 0x1)
    testData1 = CreateMlineBreakData(0, 10.0, eMLBREAK_STD, 25.0, 0x2)
    testData2 = CreateMlineBreakData(0, 9.90, eMLBREAK_TO_JOINT, 5.0, 0x4)
    
    testData = [testData0, testData1, testData2]
    breakFound = []
    for i in range(0, len(testData)):
        breakFound.append(False)
    
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[0], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[1], mlineElm, mlHandler)  
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[2], mlineElm, mlHandler)  
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 0)
    assert 3 == tmpPoint.GetNumBreaks()
    
    curBreak = mlHandler.GetBreak(mlineElm, 0 , 0)    
    
    # Order of storages need not be determinate, as long as they're all there.
    for iTest in range(0, len(testData)):
        if(testData[iTest].mask == curBreak.GetProfileMask()):
            break
    
    assert iTest != len(testData)
    breakFound[iTest] = True
    
    assert testData[iTest].mtype == curBreak.GetLengthType()
    assert testData[iTest].length == curBreak.GetLength()
    assert testData[iTest].offset == curBreak.GetOffset()
    assert testData[iTest].mask == curBreak.GetProfileMask()
    
    #  Check second break
    curBreak = mlHandler.GetBreak(mlineElm, 0 , 1)
    
    for iTest in range(0, len(testData)):
        if(testData[iTest].mask == curBreak.GetProfileMask()):
            break
    
    assert iTest != len(testData)
    breakFound[iTest] = True
    
    assert testData[iTest].mtype == curBreak.GetLengthType()
    assert testData[iTest].length == curBreak.GetLength()
    assert testData[iTest].offset == curBreak.GetOffset()
    assert testData[iTest].mask == curBreak.GetProfileMask()
    
    #  Check third break
    curBreak = mlHandler.GetBreak(mlineElm, 0 , 2)
    
    for iTest in range(0, len(testData)):
        if(testData[iTest].mask == curBreak.GetProfileMask()):
            break
    
    assert iTest != len(testData)
    breakFound[iTest] = True
    
    assert testData[iTest].mtype == curBreak.GetLengthType()
    assert testData[iTest].length == curBreak.GetLength()
    assert testData[iTest].offset == curBreak.GetOffset()
    assert testData[iTest].mask == curBreak.GetProfileMask()
    
    # Make sure they're all there
    for i in range(0, len(testData)):
        assert True == breakFound[i]
        
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])    
def test_DeleteBreaks(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    mlineElm = EditElementHandle(m_mlineElm, True)
    mlHandler = mlineElm.GetHandler()
    
    # Half on each segment
    testData0 = CreateMlineBreakData(0, 4.74, eMLBREAK_FROM_JOINT, 15, 0x1)
    testData1 = CreateMlineBreakData(0, 10.0, eMLBREAK_STD, 25.0, 0x2)
    testData2 = CreateMlineBreakData(0, 9.90, eMLBREAK_TO_JOINT, 5.0, 0x4)
    testData3 = CreateMlineBreakData(1, 10.10, eMLBREAK_STD, 10.20, MLINE_BREAKS_ALLLINES)
    testData4 = CreateMlineBreakData(1, 30.30, eMLBREAK_STD, 3.3, MLINE_BREAKS_ALLLINES)
    testData5 = CreateMlineBreakData(1, 50.50, eMLBREAK_STD, 5.5, MLINE_BREAKS_ALLLINES)
    
    testData = [testData0, testData1, testData2, testData3, testData4, testData5]
    
    numTestData = len(testData)
    breaksOnFirstSegment = 3
    breaksOnSecondSegment = 3
    
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[2], mlineElm, mlHandler) 
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[1], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[0], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[5], mlineElm, mlHandler) 
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[4], mlineElm, mlHandler)
    assert BentleyStatus.eSUCCESS == CreateMlineBreak(testData[3], mlineElm, mlHandler)
    
    assert numTestData == mlHandler.GetBreakCount(mlineElm)
    
    # Remove 1 break on first segment
    tmpPoint = mlHandler.GetPoint(mlineElm, 0)
    assert breaksOnFirstSegment == tmpPoint.GetNumBreaks()
    
    assert BentleyStatus.eSUCCESS == mlHandler.DeleteBreak(mlineElm, 0, 1)
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 0)
    breaksOnFirstSegment = breaksOnFirstSegment - 1
    assert (breaksOnFirstSegment) == tmpPoint.GetNumBreaks()
    numTestData = numTestData - 1
    assert (numTestData) == mlHandler.GetBreakCount(mlineElm)  
    
    # Remove 2 breaks on second segment
    assert BentleyStatus.eSUCCESS == mlHandler.DeleteBreak(mlineElm, 1, 1)
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 1)
    breaksOnSecondSegment = breaksOnSecondSegment - 1
    assert (breaksOnSecondSegment) == tmpPoint.GetNumBreaks()
    numTestData = numTestData - 1
    assert (numTestData) == mlHandler.GetBreakCount(mlineElm)
    
    assert BentleyStatus.eSUCCESS == mlHandler.DeleteBreak(mlineElm, 1, 1)
    
    tmpPoint = mlHandler.GetPoint(mlineElm, 1)
    breaksOnSecondSegment = breaksOnSecondSegment - 1
    assert (breaksOnSecondSegment) == tmpPoint.GetNumBreaks()
    numTestData = numTestData - 1
    assert (numTestData) == mlHandler.GetBreakCount(mlineElm) 
    
    # These should fail
    assert BentleyStatus.eERROR == mlHandler.DeleteBreak(mlineElm, 0, 2) 
    assert BentleyStatus.eERROR == mlHandler.DeleteBreak(mlineElm, 1, 1)
    

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ChangeSettings(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    firstStyle = m_mlineStyle
    
    # Create a second style so the first style in the file is pristine.  Check later to make sure we didn't break it.
    curStyle = MultilineStyle.Create("StyleToMakeActive", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != curStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != curStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != curStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = curStyle   
        
    assert m_mlineStyle != None
    
    #  Scramble the second style a little
    for iProfile in range(0, 3):
        profile = m_mlineStyle.GetProfile(iProfile)
        profile.SetColor(iProfile)
        profile.SetWeight(iProfile)
        m_mlineStyle.ReplaceProfile(profile, iProfile)
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    
    # Update the settings element
    assert BentleyStatus.eSUCCESS == MultilineStyle.ReplaceSettings(m_mlineStyle, dgnFile)
    
    settingStyle = MultilineStyle.GetSettings(dgnFile)
    assert settingStyle != None
    
    # Make sure settings element matches the style we set it to
    diffMask = settingStyle.Compare(m_mlineStyle)
    assert False == diffMask.AnyBitSet()
    
    # Make sure we did not mess up first style
    firstStyleAtEnd = MultilineStyle.GetByName("TestStyle", dgnFile)
    assert firstStyleAtEnd != None
    
    diffMask= firstStyleAtEnd.Compare(firstStyle)
    assert False == diffMask.AnyBitSet()

  
@pytest.mark.parametrize('fileName', ['noStyleSeed.dgn'])
def test_ChangeSettingsNoStyleSeed(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    dgnFile = createTempDgnFileFromSeed (loadDgnFile)
    m_mlineElm = EditElementHandle()
    m_model = dgnFile.CreateNewModel("Model", DgnModelType.eNormal, False)
    # ret = dgnFile.CreateNewModel("Test", DgnModelType.eNormal, False)
    # m_model = DgnModel.GetModelInfo(ret[0])   
    # Cook up a style to use
    tmpStyle = MultilineStyle.Create("TestStyle", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != tmpStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = tmpStyle   
     
    assert m_mlineStyle != None
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    # Create an element
    normal = DVec3d(DVec3d.From(0.0, 0.0, 1.0))
    points = DPoint3dArray([DPoint3d(0.0, 0.0, 0.0), DPoint3d(0.0, 100.0, 0.0), DPoint3d(100.0, 100.0, 0.0)])
    assert BentleyStatus.eSUCCESS == MultilineHandler.CreateMultilineElement(m_mlineElm, None, m_mlineStyle, 1.0, normal, points, False, m_model[0])
    
    firstStyle = m_mlineStyle
    
    # Create a second style so the first style in the file is pristine.  Check later to make sure we didn't break it.
    curStyle = MultilineStyle.Create("StyleToMakeActive", dgnFile)
        
    styleprof = MultilineProfile()
        
    styleprof.SetDistance(CENTER_OFFSET)
    if BentleyStatus.eSUCCESS != curStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MAX_OFFSET)
    if BentleyStatus.eSUCCESS != curStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
        
    styleprof.SetDistance(MIN_OFFSET)
    if BentleyStatus.eSUCCESS != curStyle.InsertProfile(styleprof, endoflist):
        m_mlineStyle = None
    else:
        m_mlineStyle = curStyle   
        
    assert m_mlineStyle != None
    
    #  Scramble the second style a little
    for iProfile in range(0, 3):
        profile = m_mlineStyle.GetProfile(iProfile)
        profile.SetColor(iProfile)
        profile.SetWeight(iProfile)
        m_mlineStyle.ReplaceProfile(profile, iProfile)
        
    assert BentleyStatus.eSUCCESS == m_mlineStyle.Add()
    
    # Update the settings element
    assert BentleyStatus.eSUCCESS == MultilineStyle.ReplaceSettings(m_mlineStyle, dgnFile)
    
    settingStyle = MultilineStyle.GetSettings(dgnFile)
    assert settingStyle != None
    
    # Make sure settings element matches the style we set it to
    diffMask = settingStyle.Compare(m_mlineStyle)
    assert False == diffMask.AnyBitSet()
    
    # Make sure we did not mess up first style
    firstStyleAtEnd = MultilineStyle.GetByName("TestStyle", dgnFile)
    assert firstStyleAtEnd != None
    
    diffMask= firstStyleAtEnd.Compare(firstStyle)
    assert False == diffMask.AnyBitSet()
    
        
        
    
    
