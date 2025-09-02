import os
import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Example showing Esri ArcGIS™ REST servies raster attachment of Pennsylvania Counties layer 

1. Ensure that Geographic Coordinate System is set in active model
2. Send keyin to attach Pennsylvania Counties Esri ArcGIS™ REST servies raster attachment
3. Send keyin to fit active view
'''

def RasterAttachEsriArcGISRESTServiceFileByKeyin(xamisFullPath):
    '''
    Attach raster file for Esri ArcGIS™ REST servies (.xamis) by keyin
    
    :param xamisFullPath: Full path of the raster file
    :type xamisFullPath: str

    :return: None
    :rtype: None
    '''
    
    # Attach raster file by keyin
    openAttachmentOptionsDialog = False
    keyin = "RASTER ATTACH AMIS " + xamisFullPath + " " + str(openAttachmentOptionsDialog)
    PyCadInputQueue.SendKeyin (keyin)
    print(f"Sent keyin to attach raster file: {keyin}.")
    
def FitActiveView():
    '''
    Fit active view

    :return: None
    :rtype: None
    '''
    
    vSet = IViewManager.GetActiveViewSet()  # Get the active view set
    if vSet is None:
        print(f"Failed to get ActiveViewSet.")
        return
    view_number = 1
    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if not viewport is None:
        view_number = viewport.GetViewNumber() # Get the active view index   

    keyin = "FIT VIEW EXTENDED " + str(view_number+1)
    PyCadInputQueue.SendKeyin (keyin)
    print(f"Sent keyin to fit view: {keyin}.")

    
if __name__ == "__main__":
    print("Script start...")

    # Ensure that Geographic Coordinate System is set in active model
    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        newGCS = DgnGCS.CreateGCS("EPSG:3857", ISessionMgr.ActiveDgnModelRef)
        if newGCS is None:
            print("No GCS in the active model.")
        else:
           newGCS.ToModel(ISessionMgr.ActiveDgnModelRef, True, True, True, True)

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if not dgnGCS is None:

        # By keyin, attach Pennsylvania Counties Esri ArcGIS™ REST servies raster attachment
        fullPath = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\PA_state_county.xamis"
        RasterAttachEsriArcGISRESTServiceFileByKeyin(fullPath)

        # Fit active view
        FitActiveView()
       

    print("Script end...") 