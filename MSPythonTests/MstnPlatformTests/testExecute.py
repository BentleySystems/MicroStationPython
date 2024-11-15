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
from MSPyDgnView import *
from MSPyMstnPlatform import *

#
# need to install "python -m pip install pytest-faulthandler" in powerplatformpython\python for this to run
#
#

# function to get folder location
def getRoot(fileLocation):
    origin  = os.getenv ("SrcRoot")
    # origin  = "E:\\MicrostationVenus5\\source\\"
    if not origin:
        return origin
    origin += fileLocation
    return origin




if __name__ == "__main__":
    fileLocation = "MSPython/MSPythonTests/MstnPlatformTests/Tests/"
    fileDir = getRoot(fileLocation)    
    # See https://stackoverflow.com/questions/57523762/pytest-windows-fatal-exception-code-0x8001010d for -p option.
    pytest.main(["-s", "-vv", "-x", fileDir])