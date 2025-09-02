from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example adding Geographic Coordinate System (GCS) to the active DGN model by EPSG code, GCS name, and well-known text.

1. Delete GCS in active model
2. Create a GCS in active model for Fort Lauderdale, Florida by EPSG code 6438
3. Delete GCS in active model
4. Create a GCS in active model for Fort Lauderdale, Florida by name FL83/2011-EF
5. Delete GCS in active model
6. Create a GCS in active model by well-known text (WKT)
'''

def AddGCSByIdToActiveModel(epsgCode):
    """
    Add a Geographic Coordinate System (GCS) to the active DGN model for the given EPSG code if no GCS exists in the model.
    If no Geographic Coordinate System (GCS) is attached to the active DGN model, then add a GCS to the active DGN model for the given EPSG code.
    :param epsgCode: The EPSG code of the GCS.
    :type epsgCode: int
    :return: True if the GCS is found or added to the active model; otherwise, False.
    """
   
    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        base = BaseGCS()
        base.InitFromEPSGCode(epsgCode)
        newGCS = DgnGCS.CreateGCS(base, ISessionMgr.ActiveDgnModelRef)
        if newGCS is None:
            print("New GCS is None.")
            return False
        else:
            newGCS.ToModel(ISessionMgr.ActiveDgnModelRef, True, True, True, True)    
            print(f"Set GCS EPSG:{epsgCode} in the active model.")

    return True
 

def AddGCSByNameToActiveModel(coordinateSystemName):
    """
    Add a Geographic Coordinate System (GCS) to the active DGN model for the given coordinate system name if no GCS exists in the model.
    If no Geographic Coordinate System (GCS) is attached to the active DGN model, then add a GCS to the active DGN model for the given coordinate system name.
    :param coordinateSystemName: The name of the GCS.
    :type coordinateSystemName: str
    :return: True if the GCS is found or added to the active model; otherwise, False.
    """
   
    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        newGCS = DgnGCS.CreateGCS(coordinateSystemName, ISessionMgr.ActiveDgnModelRef)
        if newGCS is None:
            print("New GCS is None.")
            return False
        else:
            newGCS.ToModel(ISessionMgr.ActiveDgnModelRef, True, True, True, True)    
            print(f"Set GCS in the active model by name {coordinateSystemName}.")

    return True

def AddGCSByWKTToActiveModel(wellKnownText):
    """
    Add a Geographic Coordinate System (GCS) to the active DGN model for the given coordinate system well know text if no GCS exists in the model.
    If no Geographic Coordinate System (GCS) is attached to the active DGN model, then add a GCS to the active DGN model for the given coordinate system well know text.
    :param wellKnownText: The well-known text of the GCS.
    :type wellKnownText: str
    :return: True if the GCS is found or added to the active model; otherwise, False.
    """
   
    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        base = BaseGCS()
        base.InitFromWellKnownText(wellKnownText)
        newGCS = DgnGCS.CreateGCS(base, ISessionMgr.ActiveDgnModelRef)
        if newGCS is None:
            print("New GCS is None.")
            return False
        else:
            newGCS.ToModel(ISessionMgr.ActiveDgnModelRef, True, True, True, True)    
            print(f"Set GCS in the active model by WKT {wellKnownText}.")

    return True
# Main
if __name__ == "__main__":
    print("Script start...")

    """Delete the GCS from the active DGN model."""
    DgnGCS.DeleteFromModel(ISessionMgr.ActiveDgnModelRef, True)

    """Attach a Geographic Coordinate System (GCS) to the active DGN model for Fort Lauderdale using EPSG 6438."""
    epsgCode = 6438
    AddGCSByIdToActiveModel(epsgCode)

    """Delete the GCS from the active DGN model."""
    DgnGCS.DeleteFromModel(ISessionMgr.ActiveDgnModelRef, True)

    """Attach a Geographic Coordinate System (GCS) to the active DGN model for Fort Lauderdale using name FL83/2011-EF."""
    gcsName = "FL83/2011-EF"
    AddGCSByNameToActiveModel(gcsName)

    """Delete the GCS from the active DGN model."""
    DgnGCS.DeleteFromModel(ISessionMgr.ActiveDgnModelRef, True)

    gcs_wkt = "GEOGCS[\"WGS 84\",DATUM[\"WGS_1984\",SPHEROID[\"WGS 84\",6378137,298.257223563]],PRIMEM[\"Greenwich\",0],UNIT[\"degree\",0.0174532925199433]]"    
    AddGCSByWKTToActiveModel(gcs_wkt)

    print("Script end...")
