# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyDgnView import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Sample to demonstrate how to use ScanCriteria to find elements in a range.
'''

def ElementInLeftViewSection(ElementRef, scanArgs, sc):
    """
    Callback function invoked for each element found during the scan.
    If the element locates in the left section of active view, it prints the element type and ID.
    """
    eh = ElementHandle(ElementRef)
    eleType = eh.GetElementType()
    elementId = ElementRef.GetElementId()
    s = scanArgs.decode("utf-8")
        
    print(f"Type {eleType} of Element with ID {elementId} found In {s}")
    
    return BentleyStatus.eSUCCESS

def GetLeftRangeOfView():
    """
    Retrieves the range of the left section of currently active view.
    
    :return: The left section of the active view as a DRange3d object.
    :rtype: DRange3d
    """
    vSet = IViewManager.GetActiveViewSet()
    if vSet is None:
        print("No active view set found.")
        return None
    
    viewport = vSet.GetSelectedViewport()
    if viewport is None:
        print("No selected viewport found.")
        return None
    
    viewInfo = viewport.GetViewInfo()  

    startPt = viewInfo.GetOrigin() 
    delta =  viewInfo.GetDelta()
    viewRot = viewInfo.GetRotation()

    viewXVec = DVec3d()
    viewRot.GetRow (viewXVec, 0)

    viewYVec = DVec3d()
    viewRot.GetRow (viewYVec, 1) 

    viewZVec = DVec3d()
    viewRot.GetRow (viewZVec, 2)

    endPoint = DPoint3d()
    endPoint.SumOf(startPt,  viewXVec, delta.x/2.0, viewYVec, delta.y, viewZVec, delta.z)

    leftViewRange = ScanRange()

    leftViewRange.xlowlim  = int(startPt.x)
    leftViewRange.ylowlim  = int(startPt.y)
    leftViewRange.zlowlim  = int(startPt.z)

    leftViewRange.xhighlim = int(endPoint.x)
    leftViewRange.yhighlim = int(endPoint.y)
    leftViewRange.zhighlim = int(endPoint.z)
    
    return leftViewRange

def ScanGraphicalElements():
    """
    Sets up and executes a scan for elements in the active DGN model.
    Utilizes ScanCriteria to filter and iterate over graphical elements.
    Prints the IDs and type of found elements.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        print("No active model found.")
        return
    
    leftViewRange = GetLeftRangeOfView()
    if leftViewRange is None:
        return

    print("Scanning for elements locating in the left section of active view in the active model...")

    dgnModel = ACTIVEMODEL.GetDgnModel()
    scanArgs = bytearray("left section of view ".encode("utf-8"))
    sc = ScanCriteria()

    sc.SetModelRef(dgnModel)
    sc.SetModelSections(DgnModelSections.eGraphicElements)
    sc.SetElemRefCallback (ElementInLeftViewSection, scanArgs)
    sc.SetRangeTest (leftViewRange)
    sc.Scan ()
   
    print("Scan completed.")

"""
This script scans the active DGN model for graphical elements in the left section of active view and prints their types and IDs.
"""
if __name__ == "__main__":
    ScanGraphicalElements()