# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import PSampUtility


'''
Function to create parametric solid by extruding a profile
'''
def CreateSmartFeatureElementExtrude(profileEditElementHandle, distance = 50000):
    status, curveVector = SmartFeatureUtil.GetCurveVector (profileEditElementHandle, True)
    if (BentleyStatus.eSUCCESS != status or curveVector is None):
        return None

    # Init extrude settings
    buttonEvent = DgnButtonEvent() # mock the DgnButtonEvent
    buttonEvent.SetPoint(DPoint3d.From(0.0, 0.0, distance))
    buttonEvent.SetViewport(IViewManager.GetActiveViewSet().GetViewport(0))
    hitPoint = DPoint3d()
    hitPoint.Init(0.0, 0.0, 0.0)
    settings = ExtrudeSettings(hitPoint, False, False, None, 1.0, 1.0, 0.0, False, 0, 0.0, buttonEvent, curveVector)

    # Create extrude feature
    featureNode = FeatureCreate.CreateExtrudeFeature(settings)
    if (featureNode is None):
        return None

    # {visible, temporary, profile} - Irrevalent for Smart Feature with single child
    controlFlags = BoolArray()
    controlFlags.append(False)
    controlFlags.append(False)
    controlFlags.append(False)
    childElementToControlFlagsMap = {profileEditElementHandle.GetElementRef(): controlFlags}
    # Create and write smart feature element
    newEditElementHandle = EditElementHandle()
    if (BentleyStatus.eSUCCESS != SmartFeatureElement.CreateAndWriteSmartFeatureElement(newEditElementHandle, profileEditElementHandle, profileEditElementHandle.GetDgnModel(), featureNode, childElementToControlFlagsMap, False)):
        return None

    return newEditElementHandle

'''
Example to show how to create a cylinder by extruding a circle
''' 
def ExampleExtrudeFeature():
    # Create a circle element as the profile
    eeh = PSampUtility.CreateEllipseAndAdd2Model(DPoint3d.From(0.0, 0.0, 0.0), 20000.0, 20000.0, ISessionMgr.GetActiveDgnModel(), True)
    if (eeh is None):
        return False

    # Make parametric solid cylinder by extruding the circle profile
    if(CreateSmartFeatureElementExtrude(eeh) is None):
        return False

    return True


if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    if (not ExampleExtrudeFeature()):
        print("Return false when calling ExampleExtrudeFeature()")
