#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
# This will generate the compiler lines to delay-load a set of files.
# The input is from stdin, and consists of a space-seperated list of LIB files that should be delay-loaded.
# Typical usage:
#   AddDelayLoad.py < myAppDelayload.rsp >> linkResponFile.rsp
from __future__ import print_function
import sys, os, re

#-------------------------------------------------------------------------------------------
# main
#-------------------------------------------------------------------------------------------
def main():

    inLines = sys.stdin.readlines ()
    fileList = []
    for line in inLines:
        line = line.strip()
        splits = line.split ()
        for item in splits:
            fileList.append (item)

    if len(fileList) == 0:
        sys.exit (0)    

    dllNameRe = re.compile(r'[a-zA-Z0-9\._-]+\.(dll|DLL|Dll)')
    output = []
    for libFile in fileList:
        # Because we now use a single library name that doesn't match the DLL name, we have to get 
        # the DLL name out of the file.
        foundFile = None
        if os.path.exists (libFile):
            with open (libFile, 'rb') as fileObj:
                byte_data = fileObj.read()
                text = byte_data.decode('utf-8', 'ignore') # ignore decoding errors
                for line in text.split('\n'):
                    match = dllNameRe.search (line)
                    if match:
                        foundFile = match.group(0)
                        break
        
        # Use the DLL name from the library, or the name of the lib as passed in.
        if foundFile:
            fileName = foundFile
        else:
            fileName = os.path.basename (libFile)
        (baseFileName, _) = os.path.splitext (fileName)
        output.append ('-DelayLoad:{0}.dll'.format(baseFileName))

    output.append ("-ignore:4194 -ignore:4199")
    output.append (" DELAYIMP.LIB")
        
    for item in output:
        print(item)

if __name__ == '__main__':
    main ()    
