#!/usr/bin/python3
#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import optparse
import re
import subprocess

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
    argParser = optparse.OptionParser("Usage: %prog [options] SdkBaseName")

    (programOptions, args) = argParser.parse_args()
    
    if len(args) != 1:
        argParser.print_help()
        exit(1)
    
    allSdksRaw = runCommand(["xcodebuild", "-showsdks"])

    # http://stackoverflow.com/questions/1714027/version-number-comparison
    def normalizeVersion(v):
        return [int(x) for x in re.sub(r'(\.0+)*$','', v).split(".")]
    
    highestSdkVer = "0.0"
    for sdkMatch in re.finditer(r"\s{0}(\d+(\.\d+)+)".format(args[0]), allSdksRaw):
        sdkVer = sdkMatch.group(1)
        if mycmp(normalizeVersion(sdkVer), normalizeVersion(highestSdkVer)) > 0:
            highestSdkVer = sdkVer

    print (highestSdkVer)

#----------------------------------------------------------------------------------------------------------------------------------------------------
if __name__ == '__main__':
    main()
