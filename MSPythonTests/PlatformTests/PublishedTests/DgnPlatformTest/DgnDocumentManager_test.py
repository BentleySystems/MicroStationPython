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

def test_CompareBinarySameMoniker(initDgnPlatformHost):
    externalizedDocMoniker = WString("<MSDocMoniker><FileName>c:\\frompw\\dms83539\\AT-70879.dgn</FileName><DmsMoniker>pw://Alpo.bentley.com:alpo-alpo/Documents/D{32c486af-2e94-4bb6-ba6c-9ca6da8c2a47}</DmsMoniker><FullPath>c:\\frompw\\dms83539\\AT-70879.dgn</FullPath></MSDocMoniker>").GetWCharCP()
    
    lhsMoniker = DgnDocumentMoniker.Create(externalizedDocMoniker)
    rhsMoniker = DgnDocumentMoniker.Create(externalizedDocMoniker)
    
    cmpresult = lhsMoniker.CompareBinary(rhsMoniker)
    assert 0 == cmpresult

def test_CompareBinarySameMonikerFromDef(initDgnPlatformHost):
    portableName = WString("Building\\Dgn\\Atrium.dgn").GetWCharCP()
    fullPath = WString("").GetWCharCP()
    providerID = WString("0").GetWCharCP()
    searchPath = WString("MS_RFDIR").GetWCharCP()
    fullPathFirst = False
    customXML = WString("<DmsMoniker>pw://Alpo.bentley.com:alpo-alpo/Documents/D{32c486af-2e94-4bb6-ba6c-9ca6da8c2a47}</DmsMoniker>").GetWCharCP()
    lhsMoniker = DgnDocumentMoniker.CreateFromRawData(portableName, fullPath, providerID, searchPath, fullPathFirst, customXML)
    assert True == ( lhsMoniker != 0 )
        
    rhsMoniker = DgnDocumentMoniker.CreateFromRawData(portableName, fullPath, providerID, searchPath, fullPathFirst, customXML)
    assert True == ( rhsMoniker != 0 )
    
    cmpresult = lhsMoniker.CompareBinary(rhsMoniker)
    assert 0 == cmpresult


def test_CompareBinaryDiffMonikerProviderId(initDgnPlatformHost):
    portableName = WString("Building\\Dgn\\Atrium.dgn").GetWCharCP()
    fullPath = WString("").GetWCharCP()
    providerID = WString("0").GetWCharCP()
    searchPath = WString("MS_RFDIR").GetWCharCP()
    fullPathFirst = False
    customXML = WString("<DmsMoniker>pw://Alpo.bentley.com:alpo-alpo/Documents/D{32c486af-2e94-4bb6-ba6c-9ca6da8c2a47}</DmsMoniker>").GetWCharCP()
    lhsMoniker = DgnDocumentMoniker.CreateFromRawData(portableName, fullPath, providerID, searchPath, fullPathFirst, customXML)
    assert True == ( lhsMoniker != 0 )
        
    rhsMoniker = DgnDocumentMoniker.CreateFromRawData(portableName, fullPath, WString("0").GetWCharCP(), searchPath, fullPathFirst, customXML)
    assert True == ( rhsMoniker != 0 )
    
    cmpresult = lhsMoniker.CompareBinary(rhsMoniker)
    assert 0 == cmpresult
    

def RoundTripMonikerProps(portableName, fullPath, providerID, searchPath, customXML, fullPathFirst):
    portableName1 = WString(portableName).GetWCharCP()
    fullPath1 = WString(fullPath).GetWCharCP()
    providerID1 = WString(providerID).GetWCharCP()
    searchPath1 = WString(searchPath).GetWCharCP()
    customXML1 =WString(customXML).GetWCharCP()
    
    lhsMoniker = DgnDocumentMoniker.CreateFromRawData (portableName1, fullPath1, providerID1, searchPath1, fullPathFirst, customXML1)
    assert True == ( lhsMoniker!= 0)
    
    externalizedXML = lhsMoniker.Externalize()
    
    rhsMoniker = DgnDocumentMoniker.Create(repr(externalizedXML), searchPath1, fullPathFirst)
    assert True == ( rhsMoniker!= 0)
    
    cmpresult = lhsMoniker.CompareBinary(rhsMoniker)
    assert 0 == cmpresult


def test_RoundTrip1(initDgnPlatformHost):
        RoundTripMonikerProps("Building\\Dgn\\Atrium.dgn",
                          "",
                          "",
                          "",
                          "",
                          False)


def test_RoundTrip2(initDgnPlatformHost):
    RoundTripMonikerProps("Building\\Dgn\\Atrium.dgn",
                          "d:\\Project1\\MilestoneA\\Building\\Dgn\\Atrium.dgn",
                          "",
                          "",
                          "",
                          False)

def test_RoundTrip3(initDgnPlatformHost):
    RoundTripMonikerProps("Building\\Dgn\\Atrium.dgn",
                          "d:\\Project1\\MilestoneA\\Building\\Dgn\\Atrium.dgn",
                          "1",
                          "",
                          "",
                          False)
    

def test_RoundTrip4(initDgnPlatformHost):
    RoundTripMonikerProps("Building\\Dgn\\Atrium.dgn",
                          "",
                          "1",
                          "",
                          "",
                          False)

  
def test_RoundTrip5(initDgnPlatformHost):
    RoundTripMonikerProps("Building\\Dgn\\Atrium.dgn",
                          "d:\\Project1\\MilestoneA\\Building\\Dgn\\Atrium.dgn",
                          "1",
                          "d:\\Project1\\MilestoneA\\",
                          "",
                          False)
    
def test_RoundTrip6(initDgnPlatformHost):
    RoundTripMonikerProps("Building\\Dgn\\Atrium.dgn",
                          "d:\\Project1\\MilestoneA\\Building\\Dgn\\Atrium.dgn",
                          "1",
                          "d:\\Project1\\MilestoneA\\",
                          "<DmsMoniker>pw://Alpo.bentley.com:alpo-alpo/Documents/D{32c486af-2e94-4bb6-ba6c-9ca6da8c2a47}</DmsMoniker>",
                          False)

def test_RoundTripTFS129680(initDgnPlatformHost):
    RoundTripMonikerProps("PW_WORKDIR:dms00163\\V8_Misc 001.dgn",
                          "",
                          "",
                          "",
                          "<DmsMoniker>pw://SUSIZ8005VIL.bentley.com:pwdb/Documents/D{a6c4202a-a0d4-4f14-8c8d-2aef66b70779}</DmsMoniker>",
                          False)


def test_DeserializeTFS129680(initDgnPlatformHost):
    portableName = WString("PW_WORKDIR:dms00163\\V8_Misc 001.dgn").GetWCharCP()
    fullPath = WString("").GetWCharCP()
    providerID = WString("").GetWCharCP()
    searchPath = WString("").GetWCharCP()
    customXML = WString("<DmsMoniker>pw://SUSIZ8005VIL.bentley.com:pwdb/Documents/D{a6c4202a-a0d4-4f14-8c8d-2aef66b70779}</DmsMoniker>").GetWCharCP()
    fullPathFirst = False
    lhsMoniker = DgnDocumentMoniker.CreateFromRawData(portableName, fullPath, providerID, searchPath, fullPathFirst, customXML)
    assert True == ( lhsMoniker != 0 )
    
    externalizedXML = WString("<MSDocMoniker><FileName>PW_WORKDIR:dms00163\\V8_Misc 001.dgn</FileName><FullPath></FullPath><ProviderId></ProviderId><DmsMoniker>pw://SUSIZ8005VIL.bentley.com:pwdb/Documents/D{a6c4202a-a0d4-4f14-8c8d-2aef66b70779}</DmsMoniker></MSDocMoniker>")
    
    rhsMoniker = DgnDocumentMoniker.Create(repr(externalizedXML), searchPath, fullPathFirst)
    assert True == ( rhsMoniker != 0 )
    
    cmpresult = lhsMoniker.CompareBinary(rhsMoniker)
    assert 0 == cmpresult
    

def test_CreateBaseMonikerList(initDgnPlatformHost):
    list1 = DgnBaseMonikerList()
    assert True == ( list1 != 0 )


def test_CreateDocumentMonikerList(initDgnPlatformHost):
    list1 = DgnDocumentMonikerList()
    assert True == ( list1 != 0 )


def test_CreateFolderMonikerList(initDgnPlatformHost):
    list1 = DgnFolderMonikerList()
    assert True == ( list1 != 0 )