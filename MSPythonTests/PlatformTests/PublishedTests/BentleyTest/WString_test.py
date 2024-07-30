#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *
import sys

s_dummy = int()
def test_GetNextToken():
    npos = "18446744073709551615"
    empty = Utf8String()
    m = Utf8String()
    iempty = 0
    iempty = empty.GetNextToken(m, "\n", 0)
    assert str(iempty) == npos
    iempty = empty.GetNextToken(m, "\n", iempty)
    assert str(iempty) == npos

    str1 = Utf8String("first\nsecond\nthird\n")
    i = 0
    t = Utf8String()
    i = str1.GetNextToken(t,"\n",0)
    assert i != npos
    assert repr(t) == "first"
    i = str1.GetNextToken(t,"\n",i)
    assert i != npos
    assert repr(t) == "second"
    i = str1.GetNextToken(t,"\n",i)
    assert i != npos
    assert repr(t) == "third"
    i = str1.GetNextToken(t,"\n",i)
    assert i != npos
    assert Utf8String.IsNullOrEmpty(repr(t))
    i = str1.GetNextToken(t,"\n",i)
    assert i != npos
    assert Utf8String.IsNullOrEmpty(repr(t))

    blanks = Utf8String("\n")
    i = blanks.GetNextToken(t,"\n",0)
    assert i != npos
    assert Utf8String.IsNullOrEmpty(repr(t))
    i = blanks.GetNextToken(t,"\n",i)
    assert i != npos
    assert Utf8String.IsNullOrEmpty(repr(t))


def test_emptyStrings():
    se1 = WString()
    se2 = WString()
    assert repr(se1) == repr(se2)

    sn1 = WString(None)
    print(sn1)
    sn2 = WString(None)
    print(sn2)
    assert repr(sn1) == repr(sn2)

    assert repr(se1) == repr(sn1)

    sl = WString("")
    assert repr(se1) == repr(sl)

    assert WString.IsNullOrEmpty(repr(se1))
    assert WString.IsNullOrEmpty(repr(sn1))
    assert WString.IsNullOrEmpty(repr(sl))

def test_append():
    str1 = WString()
    i = 1
    str2 = str(i)+"0"
    #WString(1,str2)
    str1.AppendA(repr(str2))

def test_CompareTo():
    str = WString("abc 123 def 456")
    str2 = ""
    if s_dummy != 0:
        str2 = "can't happen"
    else:
        str2 = "abc 123 def 456 and more"
    c = str.CompareTo(str2)
    assert c<0

def test_Utf16ToWCharTest1():
    pass

def test_ToLowerEmpty():
    a = WString()
    assert WString.IsNullOrEmpty(repr(a))
    a.ToLower()
    assert WString.IsNullOrEmpty(repr(a))

    o = WString()
    o = a
    assert WString.IsNullOrEmpty(repr(a))
    o.ToLower()
    assert WString.IsNullOrEmpty(repr(a))
    assert WString.IsNullOrEmpty(repr(o))

def test_Mutate():
    a = WString("ABC")
    o = WString()
    o.AssignA(repr(a))
    o.ToLower()
    assert repr(o) == "abc"
    assert repr(a) == "ABC"

def test_ToLowerToUpper():
    str1 = WString("StrIng")
    str1.ToLower()
    assert repr(str1) == "string"
    str1 = WString("StrIng")
    str1.ToUpper()
    assert repr(str1) == "STRING"

def test_BentleyConstructorTest():
    asc = "abc"
    uni = "abc"
    # empty = WString()
    # empty.AssignUtf8("abc")
    # print(empty)
    wa = WString()
    wa.AssignA("abc")
    assert repr(wa) == "abc"
    waUtf8 = WString()
    waUtf8.AssignUtf8("abc")
    assert repr(waUtf8) == "abc"
    wa1 = WString()
    wa1.AssignUtf8(asc)
    assert repr(wa1) == "abc"

    w = WString("abc")
    assert repr(w) == "abc"
    w1 = WString(uni)
    assert repr(w1) == "abc"
    assert repr(w1) == uni
    wcc = WString(str(w1))
    assert repr(wcc) == repr(w1)
    assert repr(wcc) == "abc"

def test_CharToMSWChar():
    str = WString("abc", False)
    #assert repr(str) == "abc" 
    assert repr(str) == repr(WString("abc", False))
    #assert len(str) == 3

    #assert str.GetMaxLocaleCharBytes() == (3+1)*char
    #asc = _alloca(str.GetMaxLocaleCharBytes())
    #str.ConvertToLocaleChars(asc)
    #assert 0 == asc is "abc"
    #assert str == WString(asc,False)

    #str.AppendA("def")
    #assert str == "abcdef"
    #assert len(str) == 6

def test_Operators():
    a = WString("abc")
    z = WString("zyx")

    assert repr(a) != repr(z)
    assert repr(a) < repr(z)
    assert repr(a) <= repr(z)
    assert repr(z) > repr(a)

def test_WStringInContainers():
    v = WStringArray()
    v.append(WString("abc"))
    v.append(WString("def"))
    assert v.__len__() == 2
    assert repr(v[0]) == "abc"
    assert repr(v[1]) == "def"

    wsm = {"def" : 1, "abc" : 2}
    it = wsm["def"]
    assert it != len(wsm)
    assert it == 1
    assert wsm["abc"] == 2

def test_ConstructorTest02():
    s = WString(10,'0')
    assert s.__len__() == 10

def test_ConstructorTest03():
    with_nulls = "This contains \0 a zero byte."
    s1 = WString(with_nulls,28)
    assert s1.__len__() == 28
    s2 = s1
    assert s2.__len__() == 28

def test_ConstructorTest04():
    str01 = WString("portofino")
    str02 = str(str01)
    str02 = WString(str02[::-1])
    assert repr(str02) == "onifotrop"

def test_ConstructorTest99():
    s = WString(6,'f')
    assert repr(s) == "ffffff"



def test_ElementAccess05():
    empty = WString()
    c = empty.substr(0,1)
    assert repr(c) == ''

def test_Operations01():
    empty = WString()
    assert empty.__len__() == 0
    p = empty
#    assert p!=None

def test_WStringOperators():
    a = WString("abc")
    z = WString("zyx")

    assert repr(a) != repr(z)
    assert repr(a) < repr(z)
    assert repr(a) <= repr(z)
    assert repr(z) > repr(a)
    assert repr(z) >= repr(a)








