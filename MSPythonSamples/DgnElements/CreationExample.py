# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from LineExample import *
from LineStringExample import *
from ArcExample import *
from EllipseExample import *
from RasterAttachmentExample import *
from DgnAttachmentExample import *
from AcsExample import *
from NamedGroupExample import *


if __name__ == "__main__":
    if True != createLine(DPoint3d(0, 0, 0)):
        print("Return false when call createLine!")

    if True != createLineString(DPoint3d(300, 0, 0)):
        print("Return false when call createLineString!")

    if True != createArcOverride1(DPoint3d(600, 0, 0)):
        print("Return false when call createArcOverride1!")

    if True != createArcOverride2(DPoint3d(900, 0, 0)):
        print("Return false when call createArcOverride2!")

    if True != createArcOverride3(DPoint3d(1200, 0, 0)):
        print("Return false when call createArcOverride3!")

    if True != createEllipseOverride1(DPoint3d(1500, 0, 0)):
        print("Return false when call createEllipseOverride1!")

    if True != createEllipseOverride2(DPoint3d(1800, 0, 0)):
        print("Return false when call createEllipseOverride2!")

    if True != createEllipseOverride3(DPoint3d(2100, 0, 0)):
        print("Return false when call createEllipseOverride3!")

    if True != createRasterAttachment():
        print("Return false when call createRasterAttachment!")
        
    if True != createDgnAttachment():
        print("Return false when call createDgnAttachment!")

    if True != createAcs(DPoint3d(500, 0, 0)):
        print("Return false when call createAcs!")

    if True != createNamedGroup(DPoint3d(2400, 0, 0)):
        print("Return false when call createNamedGroup!")
