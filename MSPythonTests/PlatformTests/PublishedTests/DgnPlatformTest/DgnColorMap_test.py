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

def _GenerateColors (colors, multiplier):   
    SZ = DgnColorMap.eINDEX_ColorCount
    for i in range(0,SZ):
        
        colors[i].red = (i * multiplier) & 255
        colors[i].green = (i * multiplier) & 255
        colors[i].blue = (i * multiplier) & 255
    
def VerifyColors(colors , colorMap):
    SZ = DgnColorMap.eINDEX_ColorCount 
    colorsTBGR = colorMap.GetTbgrColors ()
    for i in range(0,SZ):
        colorEntry= IntColorDef()
        j=i-1
        if(i==0):
            j = DgnColorMap.eINDEX_Background
        print(j)
        colorEntry.m_int = colorsTBGR[j]
        assert colors[i].red == colorEntry.m_rgb.red
        assert colors[i].green == colorEntry.m_rgb.green
        assert colors[i].blue == colorEntry.m_rgb.blue

def AreTBGRColorMapsEqual(leftTBGR, rightTBGR):
    SZ = DgnColorMap.eINDEX_ColorCount
    for i in range(0,SZ):
        leftEntry = IntColorDef ()
        rightEntry = IntColorDef ()    
            
        leftEntry.m_int = leftTBGR[i]
        rightEntry.m_int = rightTBGR[i]
        
        if (leftEntry.m_rgb.red != rightEntry.m_rgb.red):
            return False
        if (leftEntry.m_rgb.green !=  rightEntry.m_rgb.green):
            return False
        if (leftEntry.m_rgb.blue !=  rightEntry.m_rgb.blue):
            return False
    
    return True

def test_CreateFromRgbColors():
    SZ = DgnColorMap.eINDEX_ColorCount
    colors = [RgbColorDef() for _ in range(int(SZ)) ]
   
    _GenerateColors (colors,1)
    
    colorMap = DgnColorMap.CreateFromRgbColors (colors)
    VerifyColors (colors , colorMap)

    colorMap2 = DgnColorMap.CreateFromTbgrColors (colorMap.GetTbgrColors())
    VerifyColors (colors , colorMap2)
    
def test_CreateFromTbgrColors():
    SZ = DgnColorMap.eINDEX_ColorCount
    colors = [RgbColorDef() for _ in range(int(SZ)) ]
    
    _GenerateColors (colors,1)
    colorMap = DgnColorMap.CreateFromRgbColors (colors)
    VerifyColors (colors , colorMap)

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])
def test_GetForDisplay(initDgnPlatformHost, loadDgnFile):
    ret = loadDgnFile.CreateNewModel ("Test", DgnModelType.eNormal, False)
    colorMap = DgnColorMap.GetForDisplay (ret[0])
    if(colorMap == None):
       assert False
    defaultMap = DgnColorMap.CreateDefaultForFileType (DgnFileFormatType.eV8)

    assert True == AreTBGRColorMapsEqual (defaultMap.GetTbgrColors (), colorMap.GetTbgrColors ())

def test_GetForDisplay_NULL(initDgnPlatformHost):  
    assert None == DgnColorMap.GetForDisplay (None)   

def test_SetForFile_ERROR (initDgnPlatformHost):
    SZ = DgnColorMap.eINDEX_ColorCount
    colors = [RgbColorDef() for _ in range(int(SZ)) ]
    
    _GenerateColors (colors,1)
    # Make sure the colors get set.
    colorMap = DgnColorMap.CreateFromRgbColors (colors)
    assert BentleyStatus.eERROR == colorMap.SetForFile (None, "Doesn't Matter")

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])       
def test_SetForFile (initDgnPlatformHost, loadDgnFile):
    SZ = DgnColorMap.eINDEX_ColorCount
    colors = [RgbColorDef() for _ in range(int(SZ)) ]
    
    _GenerateColors (colors,1)
    # Make sure the colors get set.
    colorMap = DgnColorMap.CreateFromRgbColors (colors)
    nmCache = loadDgnFile.GetDictionaryModel ()
    numberBeforeAdded = nmCache.GetElementCount (DgnModelSections.eAll)
    assert BentleyStatus.eSUCCESS == colorMap.SetForFile (loadDgnFile, "Doesn't Matter")

    fileColor = DgnColorMap.GetForFile (loadDgnFile)
    assert True == AreTBGRColorMapsEqual (fileColor.GetTbgrColors (), colorMap.GetTbgrColors ())
    numberAfterAdded = nmCache.GetElementCount (DgnModelSections.eAll)

    assert numberAfterAdded > numberBeforeAdded

@pytest.mark.parametrize('fileName', ['2dMetricGeneral.dgn'])       
def test_SetForFile_Replace (initDgnPlatformHost, loadDgnFile):
    SZ = DgnColorMap.eINDEX_ColorCount
    colors = [RgbColorDef() for _ in range(int(SZ)) ]
    differentColors = [RgbColorDef()]* int(SZ)
    
    _GenerateColors (colors,1) 
    _GenerateColors (differentColors,2)

    colorMap = DgnColorMap.CreateFromRgbColors (colors)
    differentColorMap = DgnColorMap.CreateFromRgbColors (differentColors)

    nmCache = loadDgnFile.GetDictionaryModel ()
    assert BentleyStatus.eSUCCESS == colorMap.SetForFile (loadDgnFile, "First Color")
    numberBeforeAdded = nmCache.GetElementCount (DgnModelSections.eAll)
    fileColor = DgnColorMap.GetForFile (loadDgnFile)
    assert True == AreTBGRColorMapsEqual (fileColor.GetTbgrColors (), colorMap.GetTbgrColors ())

    assert BentleyStatus.eSUCCESS == differentColorMap.SetForFile (loadDgnFile, "Second Color")
    numberAfterAdded = nmCache.GetElementCount (DgnModelSections.eAll)
    fileColor = DgnColorMap.GetForFile (loadDgnFile)
    assert True == AreTBGRColorMapsEqual (fileColor.GetTbgrColors (), differentColorMap.GetTbgrColors ())

    assert numberAfterAdded == numberBeforeAdded


