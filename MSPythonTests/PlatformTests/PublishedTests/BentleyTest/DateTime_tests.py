#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest
import math

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *

def test_DateTimeConstructorTests ():
    dateTime = BeDateTime()
    assert (not dateTime.IsValid ()) == True
    expectedKind = BeDateTime.Kind.eLocal
    expectedYear = 2012
    expectedMonth = 10
    expectedDay = 17
    expectedHour = 18
    expectedMinute = 3
    expectedSecond = 18
    expectedHectoNanosecond = 1000000
    dateTime = BeDateTime (expectedKind, expectedYear, expectedMonth, expectedDay, expectedHour, expectedMinute, expectedSecond, expectedHectoNanosecond)
    assert (dateTime.IsValid ()) == True
    assert expectedKind == dateTime.GetInfo ().GetKind ()
    assert BeDateTime.Component.eDateAndTime == dateTime.GetInfo ().GetComponent ()
    assert expectedYear == dateTime.GetYear ()
    assert expectedMonth == dateTime.GetMonth ()
    assert expectedDay == dateTime.GetDay ()
    assert expectedHour == dateTime.GetHour ()
    assert expectedMinute == dateTime.GetMinute ()
    assert expectedSecond == dateTime.GetSecond ()
    assert expectedHectoNanosecond == dateTime.GetHectoNanosecond ()

    expectedKind = BeDateTime.Kind.eLocal
    expectedYear = -3123
    expectedMonth = 10
    expectedDay = 17
    expectedHour = 18
    expectedMinute = 3
    expectedSecond = 18
    expectedHectoNanosecond = 1000000
    dateTime = BeDateTime (expectedKind, expectedYear, expectedMonth, expectedDay, expectedHour, expectedMinute, expectedSecond, expectedHectoNanosecond)
    assert (dateTime.IsValid ()) == True
    assert expectedKind == dateTime.GetInfo ().GetKind ()
    assert BeDateTime.Component.eDateAndTime == dateTime.GetInfo ().GetComponent ()
    assert expectedYear == dateTime.GetYear ()
    assert expectedMonth == dateTime.GetMonth ()
    assert expectedDay == dateTime.GetDay ()
    assert expectedHour == dateTime.GetHour ()
    assert expectedMinute == dateTime.GetMinute ()
    assert expectedSecond == dateTime.GetSecond ()
    assert expectedHectoNanosecond == dateTime.GetHectoNanosecond ()

    dateOnly = BeDateTime(expectedYear, expectedMonth, expectedDay)
    assert (dateOnly.IsValid ()) == True
    assert BeDateTime.Kind.eUnspecified == dateOnly.GetInfo ().GetKind ()
    assert BeDateTime.Component.eDate == dateOnly.GetInfo ().GetComponent ()
    assert expectedYear == dateOnly.GetYear ()
    assert expectedMonth == dateOnly.GetMonth ()
    assert expectedDay == dateOnly.GetDay ()
    assert 0 == dateOnly.GetHour ()
    assert 0 == dateOnly.GetMinute ()
    assert 0 == dateOnly.GetSecond ()
    assert 0 == dateOnly.GetHectoNanosecond ()



def test_DateTimeSpecialMemberTests ():
    d1 = BeDateTime(BeDateTime.Kind.eUtc, 2012, 10, 18, 8, 30, 0, 0)
    assert (d1.IsValid ()) == True
    d2 = BeDateTime()
    d2 = d1
    assert d1 == d2
    d3 = BeDateTime()
    d3 =d1
    assert d1 == d3



def test_DateTimeComparisonTests ():
    dt1 = BeDateTime()
    dt2 = BeDateTime()
    assert (not dt1.IsValid ()) == True
    assert (not dt2.IsValid ()) == True
    assert dt1 == dt2

    utc = BeDateTime(BeDateTime.Kind.eUtc, 2012, 10, 18, 8, 30, 0, 0)
    utc2 = BeDateTime()
    utc2 = utc
    utc3 = BeDateTime()
    utc3 = utc

    local = BeDateTime(BeDateTime.Kind.eLocal, 2012, 10, 18, 8, 30, 0, 0)
    unspec = BeDateTime(BeDateTime.Kind.eUnspecified, 2012, 10, 18, 8, 30, 0, 0)
    dateOnly = BeDateTime(2012, 10, 18)
    dateOnly2 = BeDateTime()
    dateOnly2 = dateOnly
    utcDateOnly = BeDateTime(BeDateTime.Kind.eUtc, 2012, 10, 18, 8, 30, 0, 0)
    unspecifiedDateOnly = BeDateTime(BeDateTime.Kind.eUnspecified, 2012, 10, 18, 8, 30, 0, 0)
    assert utc == utc2
    assert utc == utc3
    assert (utc != utc2) == False
    assert (utc != utc3) == False
    assert dateOnly == dateOnly2
    assert (dateOnly != dateOnly2) == False
    assert (dateOnly == utcDateOnly) == False
    assert (dateOnly == unspecifiedDateOnly) == False
    empty1 = BeDateTime()
    empty2 = BeDateTime()
    assert empty1 == empty2
    assert (empty1 != empty2) == False
    assert (utc == local) == False
    assert (utc != local) == True
    assert (utc == unspec) == False
    assert (utc != unspec) == True
    assert (local == unspec) == False
    assert (local != unspec) == True
    
    # Equals()  and Compare()  are not published to SDK

    # assert (utc.Equals (utc2, True)) == True
    assert int(BeDateTime.Compare (utc, utc2)) == 1
    assert int(BeDateTime.Compare (utc, utc3)) == 1
    # assert (utc.Equals (local, True)) == True



def test_GetMillisecondTests ():
    testDate = BeDateTime(BeDateTime.Kind.eLocal, 2012, 3, 4, 5, 6, 7, 8888000)
    millisecs = testDate.GetMillisecond ()
    assert millisecs == 888

    testDate = BeDateTime(BeDateTime.Kind.eLocal, 2012, 3, 4, 5, 6, 7, 8885000)
    millisecs = testDate.GetMillisecond ()
    assert millisecs == 888

    testDate = BeDateTime(BeDateTime.Kind.eLocal, 2012, 3, 4, 5, 6, 7, 8880000)
    millisecs = testDate.GetMillisecond ()
    assert millisecs == 888



def test_GetCurrentTimeTests ():
    currentTimeLocal = BeDateTime.GetCurrentTime ()
    assert 2 == int(currentTimeLocal.GetInfo ().GetKind ())
    assert 1 == int(currentTimeLocal.GetInfo ().GetComponent ())
    assert int(currentTimeLocal.GetYear ()) >= 2013
    currentTimeUtc = BeDateTime.GetCurrentTimeUtc ()
    assert 1 == int(currentTimeUtc.GetInfo ().GetKind ())
    assert 1 == int(currentTimeUtc.GetInfo ().GetComponent ())
    assert int(currentTimeUtc.GetYear ()) >= 2013


def test_ToUtcAndToLocalTests ():
    localTime = BeDateTime.GetCurrentTime ()
    utc = BeDateTime()
    stat = localTime.ToUtc (utc)
    assert stat == BentleyStatus.eSUCCESS
    assert 1 == int(utc.GetInfo ().GetKind ())
    assert 1 == int(utc.GetInfo ().GetComponent ())
    localTime2 = BeDateTime.GetCurrentTime ()
    stat = localTime2.ToUtc (utc)
    assert stat == BentleyStatus.eSUCCESS
    assert localTime2 == localTime

    res = BeDateTime()
    stat = localTime.ToLocalTime (res)
    assert BentleyStatus.eERROR == stat
    stat = utc.ToUtc (res)
    assert BentleyStatus.eERROR == stat
    unspec = BeDateTime(2012, 10, 10)
    stat = unspec.ToLocalTime (res)
    assert BentleyStatus.eERROR == stat
    stat = unspec.ToUtc (res)
    assert BentleyStatus.eERROR == stat




