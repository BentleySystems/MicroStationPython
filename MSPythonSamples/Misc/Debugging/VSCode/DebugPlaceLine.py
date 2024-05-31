# -*- coding: utf-8 -*-

'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

# Requires pip install debugpy
import debugpy


# 5678 is the default attach port in the VS Code debug configurations. Unless a host and port are specified, host defaults to 127.0.0.1
debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
print("Waiting for debugger attach")
debugpy.wait_for_client()
debugpy.breakpoint()
print('break on this line')

# Alternatively:PyCadInputQueue.SendCommand can also be used to invoke the command.
PyCadInputQueue.SendCommand ("Place Line")

startPoint = DPoint3d(16.59365402793434185469, -1.52215075309855607522, 0.00000000000000000000)

point  = startPoint

PyCadInputQueue.SendDataPoint(point, 1)

point = DPoint3d(startPoint.x + 11.0, startPoint.y - 4.0, startPoint.z)
PyCadInputQueue.SendDataPoint(point, 1)

PyCadInputQueue.SendReset()


