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

# This sample demos how to use GetInput(keyin, data point etc.). (Used: GetInput)
# 1. Set Command and data point as the expected input.
# 2. Wait for the input. (PyCadInputQueue.GetInput will wait for user input.)
# 3. Print the input received by type.

print("Click the active view to input data point:")
msg = PyCadInputQueue.GetInput (CadInputType.eCadInputTypeCommand, CadInputType.eCadInputTypeDataPoint, CadInputType.eCadInputTypeNone, CadInputType.eCadInputTypeNone);

t = msg.GetInputType()

if t == CadInputType.eCadInputTypeDataPoint:
    pt = msg.GetPoint()
    print ("Got data point: ({0}, {1}, {2})".format(pt.x, pt.y, pt.z))
elif t == CadInputType.CadInputTypeCommand:
    print ("Got the Keyin: {0}".format(msg.GetCommandKeyin()))




    
