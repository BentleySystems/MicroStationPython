#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
from __future__ import print_function
import os
import re
import sys

def main ():
    if len (sys.argv) < 4 or len (sys.argv) > 5:
        print("Usage: {0} SearchPattern ReplacePattern InputFileName [OutputFileName]".format (os.path.basename (sys.argv[0])))
        sys.exit (1)

    searchPattern   = sys.argv[1]
    replacePattern  = sys.argv[2]
    inputFileName   = sys.argv[3]

    if len (sys.argv) == 5:
        outputFileName = sys.argv[4]
    else:
        outputFileName = inputFileName

    with open (inputFileName, 'r') as inputFile:
        inputLines = inputFile.readlines()

    with open (outputFileName, 'w') as outputFile:
        for inputLine in inputLines:
            outputFile.write (re.sub (searchPattern, replacePattern, inputLine))

if __name__ == '__main__':
    main()
