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

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_Create(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    if loadDgnFile == None:
        assert False
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)     
    testName = "TestName"
    
    dimStyle = DimensionStyle(testName, srcDgnFile)
    
    if BentleyStatus.eSUCCESS != dimStyle.Add():
        assert False
        
    preTestStyle = DimensionStyle.GetByName(testName, srcDgnFile)
    
    if preTestStyle == None:
        assert False
    
    if BentleyStatus.eSUCCESS != DimensionStyle.Delete(testName, srcDgnFile):
        assert False
        
    postTestStyle = DimensionStyle.GetByName(testName, srcDgnFile)
    
    if postTestStyle != None:
        assert False
        
        
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateStyle(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
        assert False
    
    testName = "TestName"
    
    preTestStyle = DimensionStyle.GetByName(testName, loadDgnFile)
    
    if preTestStyle != None:
        assert False
        
    dimStyle = DimensionStyle(testName, loadDgnFile)
    
    if BentleyStatus.eSUCCESS != dimStyle.Add():
        assert False
        
    postTestStyle = DimensionStyle.GetByName(testName, loadDgnFile)
    
    if postTestStyle == None:
        assert False
        
        
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CreateStyle_ERROR(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
        assert False
    
    testName = "TestName"
        
    preTestStyle = DimensionStyle.GetByName(testName, loadDgnFile)
    
    if preTestStyle != None:
        assert False
        
    dimStyle = DimensionStyle(testName, loadDgnFile)
    
    if BentleyStatus.eSUCCESS != dimStyle.Add():
        assert False
        
    if BentleyStatus.eERROR != dimStyle.Add():
        assert False
        
        
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_ReplaceInFile(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
        assert False
        
    testName = "TestName"
    
    preTestStyle = DimensionStyle.GetByName(testName, loadDgnFile)
    
    if preTestStyle != None:
        assert False
        
    dimStyle = DimensionStyle(testName, loadDgnFile)
    
    if BentleyStatus.eSUCCESS != dimStyle.Add():
        assert False
        
    postTestStyle = DimensionStyle.GetByName(testName, loadDgnFile)
    
    if postTestStyle == None:
        assert False
        
    assert BentleyStatus.eSUCCESS == postTestStyle.Replace()
    
    assert BentleyStatus.eSUCCESS == postTestStyle.SetName("NewNameForStyle")
    
    assert BentleyStatus.eERROR == postTestStyle.Replace()
    
    assert BentleyStatus.eSUCCESS == postTestStyle.Replace(testName)
    
  
# Error: BeStringUtilities not defined    
# @pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
# def test_Iterator(initDgnPlatformHost, loadDgnFile):
#     if loadDgnFile == None:
#         assert False
        
#     testName = "TestName"
#     numStyles = 10
    
#     for i in range(0, numStyles):
#         name = ""
        
#         # BeStringUtilities.Snwprintf(name, "%ls-%d", testName, i+1)
        
#         dimStyle = DimensionStyle(testName, loadDgnFile)
    
#         if BentleyStatus.eSUCCESS != dimStyle.Add():
#             assert False
            
#     iStyle = 0
#     collection = DimStyleCollection(loadDgnFile)
    
#     for dimStyle in collection:
#         expectedName = ""
        
#         # BeStringUtilities.Snwprintf(expectedName, "%ls-%d", testName, i+1)
        
#         assert expectedName == repr(dimStyle.GetName())
        
#         iStyle = iStyle + 1
        
#     assert iStyle == numStyles
    
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_IteratorEmpty(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
        assert False
        
    collection = DimStyleCollection(loadDgnFile)
    
    for dimStyle in collection:
        assert False
 
 
class FontNumberPair:
    fontANumber = 0
    fontBNumber = 0
        

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_AddBlankNameShouldFail(initDgnPlatformHost, loadDgnFile, createTempDgnFileFromSeed):
    srcDgnFile = createTempDgnFileFromSeed (loadDgnFile)  
    testStyle = DgnTextStyle("AwesomeTextStyle", srcDgnFile)
    dimStyle = DimensionStyle("AwesomeDimStyle", srcDgnFile)
 
    assert (BentleyStatus.eSUCCESS == dimStyle.Add(srcDgnFile))
    assert (BentleyStatus.eSUCCESS == testStyle.Add(srcDgnFile))

    textStyle = DgnTextStyle("", srcDgnFile)
    dimStyle = DimensionStyle("", srcDgnFile)

    assert BentleyStatus.eERROR == dimStyle.Add(srcDgnFile)
    assert BentleyStatus.eERROR == testStyle.Add(srcDgnFile)

 
@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_CopyBetweenFilesFontRemapping(initDgnPlatformHost, loadDgnFile):
    if loadDgnFile == None:
        assert False
        
    dataDir = os.environ['MSPYTESTDATA']
    ret = DgnDocument.CreateFromFileName ('3dMetricGeneral.dgn', dataDir, -101, DgnDocument.FetchMode.eWrite)

    if (ret[1] != DgnFileStatus.eDGNFILE_STATUS_Success):
        assert False

    dgnFile = DgnFile (ret[0], DgnFileOpenMode.eReadWrite)
    dgnFile.LoadDgnFile ()
    dgnFile.FillDictionaryModel ()
    
    if dgnFile == None:
        assert False
        
    fontA = DgnFontManager.FindSystemFont("Courier New", DgnFontFilter.eTrueType)
    fontB = DgnFontManager.FindSystemFont("Times New Roman", DgnFontFilter.eTrueType)
    
    if None == fontA or None == fontB:
        assert False
        
    file1Numbers = FontNumberPair
    
    file1fontA = DgnFontManager.GetDgnFontMap(loadDgnFile).GetFontNumber(fontA, True)
    file1fontB = DgnFontManager.GetDgnFontMap(loadDgnFile).GetFontNumber(fontB, True)
    if BentleyStatus.eSUCCESS != file1fontA[0] or BentleyStatus.eSUCCESS != file1fontB[0]:
        assert False
               
    file2Numbers = FontNumberPair
    
    file2fontB = DgnFontManager.GetDgnFontMap(dgnFile).GetFontNumber(fontB, True)
    file2fontA = DgnFontManager.GetDgnFontMap(dgnFile).GetFontNumber(fontA, True)
    if BentleyStatus.eSUCCESS != file2fontA[0] or BentleyStatus.eSUCCESS != file1fontB[0]:
        assert False
    
    # Validate that the two files use different numbers to refer to the same font
    assert file1fontA[1] != file2fontA[1]
    assert file1fontB[1] != file2fontB[1]
    
    # Now that the font maps are set up, do the actual test
    testNumber = 0
    # Create the style in the context of File 1 using Font A
    testName = "TestName"
    
    dimStyle = DimensionStyle(testName, loadDgnFile)
    print(dimStyle)
    dimStyle.SetFontProp(file1fontA[1], DimStyleProp.eDIMSTYLE_PROP_General_Font_FONT);
    fontPropVal = dimStyle.GetFontProp(DimStyleProp.eDIMSTYLE_PROP_General_Font_FONT)
    
    assert file1fontA[1] == fontPropVal[1]
    
    # Add the style to file 2
    if BentleyStatus.eSUCCESS != dimStyle.Add(dgnFile):
        assert False

    # Verify that the dimStyle object was modified in place
    fontPropVal = dimStyle.GetFontProp(DimStyleProp.eDIMSTYLE_PROP_General_Font_FONT)
    assert file1fontA[1] != fontPropVal[1]
    assert file2fontA[1] == fontPropVal[1]
    
    # Read the style from file 2
    postTestStyle = DimensionStyle.GetByName (testName, dgnFile)
    
    if postTestStyle == None:
        assert False
        
    fontPropVal = postTestStyle.GetFontProp(DimStyleProp.eDIMSTYLE_PROP_General_Font_FONT)
    assert file1fontA[1] != fontPropVal[1]
    assert file2fontA[1] == fontPropVal[1]