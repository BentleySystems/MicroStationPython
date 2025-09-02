# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *

'''
Sample to demonstrate how to use ScanCriteria to find MultiLine elements in the active DGN model.
Prerequisite: Open MSPythonSamples\\data\\FindMultiLinesByScanCriteria.dgn
'''

def MultiLineCallback(ElementRef, scanArgs, sc):
    """
    Callback function invoked for each element found during the scan.
    If the element is of type MultiLine, prints a message with its ID.
    """
    eh = ElementHandle(ElementRef)
    eleType = eh.GetElementType()
    if(eleType == MSElementTypes.eMULTILINE_ELM):
        elementId = ElementRef.GetElementId()
        s = scanArgs.decode("utf-8")
        print(f"{s} Element with ID: {elementId}")
        return BentleyStatus.eSUCCESS

    return BentleyStatus.eERROR

def ScanGraphicalElements():
    """
    Sets up and executes a scan for MultiLine elements in the active DGN model.
    Utilizes ScanCriteria to filter and iterate over graphical elements.
    Prints the IDs of found MultiLine elements.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        print("No active model found.")
        return
    
    print("Scanning for MultiLine elements in the active model...")

    dgnModel = ACTIVEMODEL.GetDgnModel()
    scanArgs = bytearray("Find MultiLine".encode("utf-8"))
    sc = ScanCriteria()

    sc.SetModelRef(dgnModel)
    sc.SetModelSections(DgnModelSections.eGraphicElements)
    sc.SetElemRefCallback (MultiLineCallback, scanArgs)
    sc.AddSingleElementTypeTest (MSElementTypes.eMULTILINE_ELM)
    sc.Scan ()
   
    print("Scan completed.")

"""
This script scans the active DGN model for graphical elements of type MultiLine and prints their element IDs.
"""
if __name__ == "__main__":
    ScanGraphicalElements()