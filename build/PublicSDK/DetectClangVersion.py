#!/usr/bin/python3
#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import optparse
import re
import subprocess
import platform
import os

#----------------------------------------------------------------------------------------------------------------------------------------------------
def runCommand (command):
    proc = subprocess.Popen (command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    
    allLines = ""
    procStdOutLine = proc.stdout.readline ()
    while procStdOutLine:
        allLines += str(procStdOutLine)
        procStdOutLine = proc.stdout.readline ()
    
    retVal = proc.wait ()
    
    if 0 != retVal:
        print ("ERROR: Command '{0}' failed with error code {1}.".format (command, retVal))
        exit (1)
        
    return allLines

#----------------------------------------------------------------------------------------------------------------------------------------------------
def mycmp(a, b):
    return (a > b) - (a < b) 

#----------------------------------------------------------------------------------------------------------------------------------------------------
def main ():
    argParser = optparse.OptionParser("Usage: %prog [MinimumVersion]")

    (programOptions, args) = argParser.parse_args()
    numArgs = len(args)

    if numArgs > 1:
        argParser.print_help()
        exit(1)

    if 'linux' in platform.platform().lower():
        buildNumberStr = linux_get_version()
    else:
        buildNumberStr = darwin_get_version()

    if 0 == numArgs:
        print (buildNumberStr)
        exit(0)

    # http://stackoverflow.com/questions/1714027/version-number-comparison
    def normalizeVersion(v):
        return [int(x) for x in re.sub(r'(\.0+)*$','', v).split(".")]

    actualVersion = normalizeVersion(buildNumberStr)
    requestedVersion = normalizeVersion(args[0])

    if mycmp(actualVersion, requestedVersion) >= 0:
        print ('YES')
    else:
        print ('NO')

    exit(0)


def darwin_get_version():
    clangVersionString = runCommand(['xcrun', 'clang', '--version'])
    buildNumberMatch = re.search(r'clang-([0-9\-\.]+)\)', clangVersionString)

    try:
        return buildNumberMatch.group(1)
    except:
        print ("Error: Could not detect clang build number")
        exit(1)


def linux_get_version():
    """get the clang version on linux, normalize it to the same version format that apple clang uses"""
    try:
        llvmDir = os.getenv("LLVM_DIR")
    except:
        print ("Error: LLVM_DIR should have been defined in the environment by the build process or user")
        exit(1)
    clangBin = os.path.join(llvmDir, 'bin/clang')
    clangVersionStdout = runCommand([clangBin, '--version'])
    match = re.search(r'version ([0-9\-\.]+)', clangVersionStdout)
    try:
        version = match.group(1)
    except:
        print ("Error: Could not detect clang build number")
        exit(1)
    # we ignore any subversion/tag `-XX` in the clang version since apple's version doesn't seem to have a corresponding part
    versionWithoutTag, _, _ = version.partition('-')
    # apple's clang version that we parse is (Major Minor Patch '.' v '.' v '.' v '.' v)
    # where the v version parts are some apple specific versioning
    # so on linux we will just set them to 0 and expect apple doesn't add actual clang features in those patches
    pseudoAppleClangMajorVersion = versionWithoutTag.replace('.', '')
    pseudoAppleClangVersion = pseudoAppleClangMajorVersion + '.0.0.0.0'
    return pseudoAppleClangVersion


#----------------------------------------------------------------------------------------------------------------------------------------------------
if __name__ == '__main__':
    main()
