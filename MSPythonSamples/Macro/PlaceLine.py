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

# This sample demos how to invoke the command by keyin. (Used: SendKeyin, SendDataPoint, SendReset)
# 1. Invoke "Place Line" Command.
# 2. Input 2 points.

#PyCadInputQueue.SendKeyin ("Place Line")

# Alternatively:PyCadInputQueue.SendCommand can also be used to invoke the command.
PyCadInputQueue.SendCommand ("Place Line")

startPoint = DPoint3d(16.59365402793434185469, -1.52215075309855607522, 0.00000000000000000000)

point  = startPoint

PyCadInputQueue.SendDataPoint(point, 1)

point = DPoint3d(startPoint.x + 11.0, startPoint.y - 4.0, startPoint.z)
PyCadInputQueue.SendDataPoint(point, 1)

PyCadInputQueue.SendReset()


