#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import pytest

from MSPyBentley import *


def test_BeFileNameSetName ():
    fileNameUnix        = "/dir1/dir2/temp.txt"
    fileNamePython      = "\\dir1\\dir2\\temp.txt"
    fileNameMixedUp     = "\\dir1/dir2\\temp.txt"

    fromFileNameUnix    = BeFileName(fileNameUnix)
    fromFileNamePython  = BeFileName(fileNamePython)
    fromFileNameMixedUp = BeFileName(fileNameMixedUp)

    fromFileNameUnixE    = BeFileName()
    fromFileNamePythonE  = BeFileName()
    fromFileNameMixedUpE = BeFileName()

    fromFileNameUnixE.SetName    (fileNameUnix)
    fromFileNamePythonE.SetName (fileNamePython)
    fromFileNameMixedUpE.SetName (fileNameMixedUp)

    assert fileNamePython == fromFileNameUnix.GetName ()
    assert fileNamePython == fromFileNamePython.GetName ()
    assert fileNamePython == fromFileNameMixedUp.GetName ()
    assert fileNamePython == fromFileNameUnixE.GetName ()
    assert fileNamePython == fromFileNamePythonE.GetName ()
    assert fileNamePython == fromFileNameMixedUpE.GetName ()


 
def test_BeFileNameParseName1 ():
    fileNameW        = "/dir1/dir2/temp.txt"
    fileName = "\\dir1\\dir2\\temp.txt"

    fromFileName  = BeFileName (fileName)
    fromFileNameW  = BeFileName (fileNameW)
   

    expected = "\\dir1\\dir2\\"
    dirName = WString ()

    assert fromFileName.GetName() == fromFileNameW.GetName ()

    fromFileName.ParseName(None,dirName,None,None)

    assert expected == repr(dirName)

    dirName = WString ("?")
    fromFileNameW.ParseName(None,dirName,None,None)
    
    assert expected == repr(dirName)

def test_BeFileNameParseName2 ():
    fileName        = "/data/temp.txt"
    fromFileName  = BeFileName (fileName)

    driveName = WString ()
    dirName = WString ()
    baseName = WString ()
    extName = WString ()

    expectedDirName = "\\data\\"
    fromFileName.ParseName(driveName,dirName,baseName,extName)
    assert "" == repr(driveName)
    assert expectedDirName == repr(dirName)
    assert "temp" == repr(baseName)
    assert "txt" == repr(extName)

def test_BeFileNameParseName3 ():
    fileName        = "/junk1/junk2/temp.txt"
    fromFileName  = BeFileName (fileName)

    driveName = WString ()
    dirName = WString ()
    baseName = WString ()
    extName = WString ()

    expectedDirName = "\\junk1\\junk2\\"
    fromFileName.ParseName(driveName,dirName,baseName,extName)

    assert "" == repr(driveName)
    assert expectedDirName == repr(dirName)
    assert "temp" == repr(baseName)
    assert "txt" == repr(extName)

def test_BeFileNameParseName4 ():
    fileName        = "/data"
    fromFileName  = BeFileName (fileName)
    WCSDIR_SEPARATOR          = "\\"
    driveName = WString ()
    dirName = WString ()
    baseName = WString ()
    extName = WString ()
    fromFileName.ParseName(driveName,dirName,baseName,extName)

    assert "" == repr(driveName)
    assert WCSDIR_SEPARATOR == repr(dirName)
    assert "data" == repr(baseName)
    assert "" == repr(extName)

def test_BeFileNameParseName5 ():
    fileName        = "/junk1/junk2/"
    fromFileName  = BeFileName (fileName)
    
    driveName = WString ()
    dirName = WString ()
    baseName = WString ()
    extName = WString ()

    expectedDirName = "\\junk1\\junk2\\"
    fromFileName.ParseName(driveName,dirName,baseName,extName)

    assert "" == repr(driveName)
    assert expectedDirName == repr(dirName)
    assert "" == repr(baseName)
    assert "" == repr(extName)

def test_BeFileNameParseName6 ():
    fileNameUnix = "/junk1/junk2/temp.txt"
    fileNameWindows =  "\\junk1\\junk2\\temp.txt"
    fromFileNameUnix  = BeFileName (fileNameUnix)
    fromFileNameWindows  = BeFileName (fileNameWindows)
    
    driveName = WString ()
    dirName = WString ()
    baseName = WString ()
    extName = WString ()

    expectedDirName = "\\junk1\\junk2\\"

    BeFileName.ParseName(fromFileNameUnix, driveName,dirName,baseName,extName)

    assert "" == repr(driveName)
    assert expectedDirName == repr(dirName)
    assert "temp" == repr(baseName)
    assert "txt" == repr(extName)

    driveName.clear ()
    dirName.clear ()
    baseName.clear ()
    extName.clear ()

    BeFileName.ParseName(fromFileNameWindows, driveName,dirName,baseName,extName)

    assert "" == repr(driveName)
    assert expectedDirName == repr(dirName)
    assert "temp" == repr(baseName)
    assert "txt" == repr(extName)

def test_BeFileNameBuildName1 ():
    fileName = BeFileName (None,"/junk1/junk2","junk3","txt")
    expectedFileName = "\\junk1\\junk2\\junk3.txt"

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameBuildName2 ():
    fileName = BeFileName (None,"/junk1/junk2","junk3","txt")
    expectedFileName = "\\junk1\\junk2\\junk3.txt"

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameBuildName3 ():
    fileName = BeFileName (None,"/junk1/junk2/","junk3",".txt")
    expectedFileName = "\\junk1\\junk2\\junk3.txt"

    assert expectedFileName == fileName.GetName ()


def test_BeFileNameBuildName4 ():
    fileName = BeFileName (None,"/junk1/junk2/","junk3.txt",None)
    expectedFileName = "\\junk1\\junk2\\junk3.txt"

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameBuildName5 ():
    fileName = BeFileName (None,"/junk1/junk2/",None,None)
    expectedFileName = "\\junk1\\junk2\\"

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameBuildName6 ():
    fileName = BeFileName (None,"/junk1/junk2",None,None)
    expectedFileName = "\\junk1\\junk2\\"

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameBuildName7 ():
    fileName = BeFileName (None,None,"junk3.txt",None)
    expectedFileName = "junk3.txt"

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameBuildName8 ():
    fileName = BeFileName (None,None,None,None)
    expectedFileName = ""

    assert expectedFileName == fileName.GetName ()

def test_BeFileNameGetDirectoryNameWithDrive ():
    expectedFileName = "C:\\foo\\bar\\"
    assert expectedFileName == repr(BeFileName.GetDirectoryName ("C:\\foo\\bar\\bat.txt"))

def test_BeFileNameGetDirectoryNameNoDriveAbsolute ():
    expectedFileName = "\\foo\\bar\\"
    assert expectedFileName == repr(BeFileName.GetDirectoryName ("/foo/bar/bat.txt"))

def test_BeFileNameGetDirectoryNameNoDriveRelative ():
    expectedFileName = "foo\\bar\\"
    assert expectedFileName == repr(BeFileName.GetDirectoryName ("foo/bar/bat.txt"))

def test_BeFileNameGetExtension ():

    assert "" == repr(BeFileName.GetExtension (None))
    assert "" == repr(BeFileName.GetExtension (""))
    assert "txt" == repr(BeFileName.GetExtension ("/foo/bar/bat.txt"))
    assert "" == repr(BeFileName.GetExtension ("/foo/bar/bat"))
    assert "" == repr(BeFileName.GetExtension ("/foo/bar/bat."))
    assert "xml" == repr(BeFileName.GetExtension ("/foo/bar/foo.partfile.xml"))
    assert "emacs" == repr(BeFileName.GetExtension ("/foo/bar.emacs"))


def test_BeFileNameGetFileName ():
    assert "" == repr(BeFileName.GetFileNameAndExtension (None))
    assert "" == repr(BeFileName.GetFileNameAndExtension (""))
    assert "bat.txt" == repr(BeFileName.GetFileNameAndExtension ("/foo/bar/bat.txt"))
    assert "bat" == repr(BeFileName.GetFileNameAndExtension ("/foo/bar/bat"))
    assert "bat" == repr(BeFileName.GetFileNameAndExtension ("/foo/bar/bat."))
    assert ".emacs" == repr(BeFileName.GetFileNameAndExtension ("/foo/bar/.emacs"))
    assert "foo.partfile.xml" == repr(BeFileName.GetFileNameAndExtension ("/foo.bar/foo.partfile.xml"))

def test_BeFileNameGetFileNameWithoutExtension ():
    assert "" == repr(BeFileName.GetFileNameWithoutExtension (None))
    assert "" == repr(BeFileName.GetFileNameWithoutExtension (""))
    assert "bat" == repr(BeFileName.GetFileNameWithoutExtension ("/foo/bar/bat.txt"))
    assert "bat" == repr(BeFileName.GetFileNameWithoutExtension ("/foo/bar/bat"))
    assert "bat" == repr(BeFileName.GetFileNameWithoutExtension ("/foo/bar/bat."))
    assert "" == repr(BeFileName.GetFileNameWithoutExtension ("/foo/bar/.emacs"))
    assert "foo.partfile" == repr(BeFileName.GetFileNameWithoutExtension ("/foo.bar/foo.partfile.xml"))

def test_BeFileNameDoesPathExist1 ():
    fileName = BeFileName (None,None,"junk3.txt",None)
    assert False == BeFileName.DoesPathExist((fileName.GetName ()))

def test_BeFileNameDoesPathExist2 ():
    fileName = BeFileName (None,None,"c:\\",None)
    assert True == BeFileName.DoesPathExist((fileName.GetName ()))
    assert True == BeFileName.DoesPathExist(repr(fileName))

def test_BeFileNameIsDirectory1 ():
    fileName = BeFileName (None,None,"c:\\",None)
    assert True == BeFileName.IsDirectory(repr(fileName))

def test_BeFileNameIsDirectory2 ():
    fileName = BeFileName ("/junk1/junk2/")
    assert False == BeFileName.IsDirectory(repr(fileName))

# def test_RequiredDataExists (): #MoConfigurationManager is not defined
#     dgnDirName= BeFileName()
#     MoConfigurationManager.GetDirName(dgnDirName,MoConfigurationManager.DIR_DefaultForDgn)
#     assert True == BeFileName.IsDirectory(repr(dgnDirName))


def test_GetFileSize ():
    tmp = BeFileName()
    bfnStatus = BeFileNameStatus(BeFileName.BeGetTempFileName(tmp,BeFileName(),"BeFileNameTests_GetFileSize"))
    assert BeFileNameStatus.eSuccess == bfnStatus

def FindRelativePath (fullPath,basePath,expectedRelativePath):
    relativePath = WString()
    BeFileName.FindRelativePath(relativePath,fullPath,basePath)
    
    assert repr(relativePath) == expectedRelativePath

def test_FindRelativePath1():
    basePath = WString("d:\\comp1\\comp2\\")
    fullPath = WString("c:\\comp1\\comp2\\comp3\\comp4\\file.txt")
    expectedPath = WString("c:\\comp1\\comp2\\comp3\\comp4\\file.txt")

    FindRelativePath(repr(fullPath),repr(basePath),repr(expectedPath))

def test_FindRelativePath2():
    basePath = WString("d:\\comp1\\comp2\\")
    fullPath = WString("d:\\comp1\\comp2\\comp3\\comp4\\file.txt")
    expectedPath = WString("comp3\\comp4\\file.txt")

    FindRelativePath(repr(fullPath),repr(basePath),repr(expectedPath))

def test_FindRelativePath3():
    basePath = WString("d:\\comp1\\comp2\\")
    fullPath = WString("d:\\comp1\\file.txt")
    expectedPath = WString("..\\file.txt")

    FindRelativePath(repr(fullPath),repr(basePath),repr(expectedPath))

def test_FindRelativePath4():
    basePath = WString("d:\\comp1\\comp2\\")
    fullPath = WString("\\comp1\\file.txt")
    expectedPath = WString("\\comp1\\file.txt")

    FindRelativePath(repr(fullPath),repr(basePath),repr(expectedPath))

def test_FindRelativePath5():
    basePath = WString("d:\\")
    fullPath = WString("d:\\comp1\\comp2\\comp3\\comp4\\file.txt")
    expectedPath = WString("comp1\\comp2\\comp3\\comp4\\file.txt")

    FindRelativePath(repr(fullPath),repr(basePath),repr(expectedPath))

def resolveRelativePath1 (relativePath,basePath,expectedFullPath):
    fullPath = WString()
    BeFileName.ResolveRelativePath(fullPath,relativePath,basePath)
    
    assert repr(fullPath) == expectedFullPath

#@pytest.mark.skip(reason="NEEDS WORK: Fix me")
def test_ResolveRelativePath1 (): # failing test case
    basePath = WString("d:\\comp1\\comp2\\")
    relativePath = WString("comp3\\comp4\\file.txt")
    expectedPath = WString("d:\\comp1\\comp2\\comp3\\comp4\\file.txt")

    resolveRelativePath1(repr(relativePath),repr(basePath),repr(expectedPath))



    
