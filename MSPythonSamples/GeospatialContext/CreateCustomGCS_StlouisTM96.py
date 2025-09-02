from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example adding Geographic Coordinate System (GCS) to the active DGN model by well-known text for StLouisTM96.
'''

def AddGCSByWKTToActiveModel(wellKnownText):
    """
    If no Geographic Coordinate System (GCS) is attached to the active DGN model, then add a GCS to the active DGN model for the given coordinate system well-known text.
    :param wellKnownText: The well-known text of the GCS.
    :type wellKnownText: str
    :return: True if the GCS is found or added to the active model; otherwise, False.
    :rtype: bool
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
    else:
        print("A GCS already exists in the active model.")
        return False

# Define the WKT for StLouisTM96
stlouis_tm96_wkt = "PROJCS[\"StLouisTM96\",GEOGCS[\"GCS_North_American_1983\",DATUM[\"D_North_American_1983\",SPHEROID[\"GRS_1980\",6378137,298.257222101]],PRIMEM[\"Greenwich\",0],UNIT[\"Degree\",0.0174532925199433]],PROJECTION[\"Transverse_Mercator\"],PARAMETER[\"False_Easting\",500000],PARAMETER[\"False_Northing\",0],PARAMETER[\"Central_Meridian\",-90.5],PARAMETER[\"Scale_Factor\",0.9996],PARAMETER[\"Latitude_Of_Origin\",0],UNIT[\"Meter\",1]]"

# Add the new GCS
AddGCSByWKTToActiveModel(stlouis_tm96_wkt)