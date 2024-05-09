#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import sys

if __name__ == '__main__':
    
    fileName = sys.argv[1]

    with open (fileName) as oFile:
        fileInAStringList = oFile.readlines()

    oFile = open(fileName, 'w')
    
    for line in fileInAStringList:
        line = line.replace ('/', '\/')
        oFile.write (line)
    
    oFile.close()
