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

# Requires pip install pywin32
import pywin.debugger

pywin.debugger.set_trace()

PyCadInputQueue.SendCommand ("Place Line")

startPoint = DPoint3d(16.59365402793434185469, -1.52215075309855607522, 0.00000000000000000000)

point  = startPoint

PyCadInputQueue.SendDataPoint(point, 1)

point = DPoint3d(startPoint.x + 11.0, startPoint.y - 4.0, startPoint.z)
PyCadInputQueue.SendDataPoint(point, 1)

PyCadInputQueue.SendReset()


