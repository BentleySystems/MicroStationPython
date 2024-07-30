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

def test_CompressRscFractions(initDgnPlatformHost):
    arialFont = DgnFontManager.FindSystemFont("Arial",DgnFontFilter.eTrueType)
    assert True == ( None != arialFont )
    
    engineeringFont = DgnFontManager.FindSystemFont("ENGINEERING",DgnFontFilter.eResource)
    assert True == ( None != engineeringFont )
    
    compressedString = WString()
    
    #Arial should always very early return from CompressRscFractions; throw a couple sanity checks at it anyway...
    arialFont.CompressRscFractions(compressedString,None)
    assert 0 == compressedString.__len__()
    
    arialFont.CompressRscFractions(compressedString,"")
    assert 0 == compressedString.__len__()
    
    arialFont.CompressRscFractions(compressedString,"A")
    assert 0 == (compressedString.CompareTo("A"))
    
    arialFont.CompressRscFractions(compressedString,"123")
    assert 0 == (compressedString.CompareTo("123"))
    
    arialFont.CompressRscFractions(compressedString,"1/2")
    assert 0 == (compressedString.CompareTo("1/2"))
    
    arialFont.CompressRscFractions(compressedString,"A1/2B")
    assert 0 == (compressedString.CompareTo("A1/2B"))    
    
    engineeringFont.CompressRscFractions(compressedString,None)
    assert 0 == compressedString.__len__()
    
    engineeringFont.CompressRscFractions(compressedString,"")
    assert 0 == compressedString.__len__()
    
    engineeringFont.CompressRscFractions(compressedString,"A")
    assert 0 == (compressedString.CompareTo("A"))
    
    engineeringFont.CompressRscFractions(compressedString,"ABC")
    assert 0 == (compressedString.CompareTo("ABC"))
    
    engineeringFont.CompressRscFractions(compressedString,"123")
    assert 0 == (compressedString.CompareTo("123"))
    
    engineeringFont.CompressRscFractions(compressedString,"A/B")
    assert 0 == (compressedString.CompareTo("A/B"))
    
    engineeringFont.CompressRscFractions(compressedString,"1/2")
    assert 0 == (compressedString.CompareTo("\xbd"))
    
    engineeringFont.CompressRscFractions(compressedString,"1/16")
    assert 0 == (compressedString.CompareTo(""))
    
    engineeringFont.CompressRscFractions(compressedString,"1/")
    assert 0 == (compressedString.CompareTo("1/"))
    
    engineeringFont.CompressRscFractions(compressedString,"/2")
    assert 0 == (compressedString.CompareTo("/2"))
    
    engineeringFont.CompressRscFractions(compressedString,"1/A")
    assert 0 == (compressedString.CompareTo("1/A"))
    
    engineeringFont.CompressRscFractions(compressedString,"A1/2")
    assert 0 == (compressedString.CompareTo("A\xbd"))
    
    engineeringFont.CompressRscFractions(compressedString,"1/2B")
    assert 0 == (compressedString.CompareTo("\xbd" "B"))
    
    engineeringFont.CompressRscFractions(compressedString,"AB1/2CD")
    assert 0 == (compressedString.CompareTo("AB\xbd" "CD"))
    
    engineeringFont.CompressRscFractions(compressedString,"A1/3B")
    assert 0 == (compressedString.CompareTo("A1/3B"))
    
    engineeringFont.CompressRscFractions(compressedString,"1/2/2010")
    assert 0 == (compressedString.CompareTo("1/2/2010"))
    
    engineeringFont.CompressRscFractions(compressedString,"1-13/64\"")
    assert 0 == (compressedString.CompareTo("1-\""))
    
def test_ExpandRscFractions():
    arialFont = DgnFontManager.FindSystemFont("Arial",DgnFontFilter.eTrueType)
    assert True == ( None != arialFont )
    
    engineeringFont = DgnFontManager.FindSystemFont("ENGINEERING",DgnFontFilter.eResource)
    assert True == ( None != engineeringFont )
    
    expandedString = WString()
    
    #Arial should always very early return from CompressRscFractions; throw a couple sanity checks at it anyway...
    arialFont.CompressRscFractions(expandedString,None)
    assert 0 == expandedString.__len__()
    
    arialFont.CompressRscFractions(expandedString,"")
    assert 0 == expandedString.__len__()
    
    arialFont.CompressRscFractions(expandedString,"A")
    assert 0 == (expandedString.CompareTo("A"))
    
    arialFont.CompressRscFractions(expandedString,"123")
    assert 0 == (expandedString.CompareTo("123"))
    
    arialFont.CompressRscFractions(expandedString,"\x81")
    assert 0 == (expandedString.CompareTo("\x81"))
    
    arialFont.CompressRscFractions(expandedString,"A\x81" "B")
    assert 0 == (expandedString.CompareTo("A\x81" "B"))
    
    engineeringFont.CompressRscFractions(expandedString,None)
    assert 0 == expandedString.__len__()
    
    engineeringFont.CompressRscFractions(expandedString,"")
    assert 0 == expandedString.__len__()
    
    engineeringFont.CompressRscFractions(expandedString,"A")
    assert 0 == (expandedString.CompareTo("A"))
    
    engineeringFont.CompressRscFractions(expandedString,"ABC")
    assert 0 == (expandedString.CompareTo("ABC"))
    
    engineeringFont.CompressRscFractions(expandedString,"\x81")
    assert 0 == (expandedString.CompareTo(""))
    
    engineeringFont.CompressRscFractions(expandedString,"A\x81" "B")
    assert 0 == (expandedString.CompareTo("AB"))
    
    engineeringFont.CompressRscFractions(expandedString,"1-\xA6" "\"")
    assert 0 == (expandedString.CompareTo("1-¦\""))
    
def test_CompressEscapeSequences():
    arialFont = DgnFontManager.FindSystemFont("Arial",DgnFontFilter.eTrueType)
    assert True == ( None != arialFont )
    
    engineeringFont = DgnFontManager.FindSystemFont("ENGINEERING",DgnFontFilter.eResource)
    assert True == ( None != engineeringFont )
    
    compressedString = WString()
    
    #Arial should always very early return from CompressRscFractions; throw a couple sanity checks at it anyway...
    arialFont.CompressRscFractions(compressedString,None)
    assert 0 == compressedString.__len__()
    
    arialFont.CompressRscFractions(compressedString,"")
    assert 0 == compressedString.__len__()
    
    arialFont.CompressRscFractions(compressedString,"A")
    assert 0 == (compressedString.CompareTo("A"))
    
    arialFont.CompressRscFractions(compressedString,"123")
    assert 0 == (compressedString.CompareTo("123"))
    
    arialFont.CompressRscFractions(compressedString,"\x7B")
    assert 0 == (compressedString.CompareTo("{"))
    
    arialFont.CompressRscFractions(compressedString,"A\x42C")
    assert 0 == (compressedString.CompareTo("ABC"))
    
    arialFont.CompressRscFractions(compressedString,"\\")
    assert 0 == (compressedString.CompareTo("\\"))

    arialFont.CompressRscFractions(compressedString,"\\66")
    assert 0 == (compressedString.CompareTo("\\66"))

    arialFont.CompressRscFractions(compressedString,"\\\x42")
    assert 0 == (compressedString.CompareTo("\\B"))

    arialFont.CompressRscFractions(compressedString,"\x41\x42\x43")
    assert 0 == (compressedString.CompareTo("ABC"))
    
    engineeringFont.CompressRscFractions(compressedString,"\\134")
    assert 0 == (compressedString.CompareTo("\\134"))
    
def test_ExpandEscapeSequences():
    arialFont = DgnFontManager.FindSystemFont("Arial",DgnFontFilter.eTrueType)
    assert True == ( None != arialFont )
    
    expandedString = WString()
    
    #Arial should always very early return from CompressRscFractions; throw a couple sanity checks at it anyway...
    arialFont.CompressRscFractions(expandedString,None)
    assert 0 == expandedString.__len__()
    
    arialFont.CompressRscFractions(expandedString,"")
    assert 0 == expandedString.__len__()
    
    arialFont.CompressRscFractions(expandedString,"A")
    assert 0 == (expandedString.CompareTo("A"))
    
    arialFont.CompressRscFractions(expandedString,"123")
    assert 0 == (expandedString.CompareTo("123"))
    
    arialFont.CompressRscFractions(expandedString,"\\")
    assert 0 == (expandedString.CompareTo("\\"))
    
    arialFont.CompressRscFractions(expandedString,"A\\B")
    assert 0 == (expandedString.CompareTo("A\\B"))
    
    arialFont.CompressRscFractions(expandedString,"\\A")
    assert 0 == (expandedString.CompareTo("\\A"))
    
    arialFont.CompressRscFractions(expandedString,"B\\")
    assert 0 == (expandedString.CompareTo("B\\"))
