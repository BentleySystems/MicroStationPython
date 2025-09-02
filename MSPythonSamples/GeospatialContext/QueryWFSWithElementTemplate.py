from GeospatialContextConnection import *
from QueryServerConnection import *
from GeospatialContextUtilities import *

'''
Example showing Geospatial Context query of WFS server. Update element template color for the "Contacts" feature layer.

1. Ensure that Geographic Coordinate System is set in active model
2. Create a named boundary from lat/long bounding box around Fort Lauderdale, Florida
3. Create a fence from the named boundary
4. Fit the view to the named boundary
5. Query features in the ProjectArea by fence
    a. Get the Geospatial Context server connection to URL https://mrdata.usgs.gov/wfs/sgmc?request=getcapabilities&service=WFS
    b. Get the ElementTemplate path for the feature "Contacts". Update the element template if needed.
    c. Clear features before query...
    d. Query by fence...
'''

def GetFeatureLayerElementTemplateInstance (dgnFile, conn, featureName):
    """
    Get the element template for the given feature layer.

    :param dgnFile: The DGN file.
    :type dgnFile: DgnFile
    :param conn: The Geospatial Context server connection.
    :type conn: ServerConnectionPtr
    :param featureName: The name of the feature.
    :type featureName: str
    :return: The element template instance.
    
    """

    # Get the ElementTemplate path for the feature "Contacts". Update the element template if needed.
    elementTemplatePath = GetFeatureElementTemplatePath(conn, featureName)
    if elementTemplatePath is None:
        print(f"Failed to get ElementTemplate for feature \"{featureName}\".")
        return None

    print (f"[{featureName}] ElementTemplate path is: {elementTemplatePath}")            
    templatePath = WString (elementTemplatePath)
    index = 0
    elementTemplate = ElementTemplateUtils.FindTemplateNodeByPath (templatePath.GetWCharCP(), dgnFile)
    if elementTemplate is None:
        print(f"FindTemplateNodeByPath {str(templatePath)} is None.")
        return None

    return elementTemplate.GetDefaultInstance ()

def UpdateFeatureLayerElementTemplate_Color (dgnFile, conn, featureName, color):
    """
    Update the color of the element template.

    :param dgnFile: The DGN file.
    :type dgnFile: DgnFile
    :param conn: The Geospatial Context server connection.
    :type conn: ServerConnectionPtr
    :param featureName: The name of the feature.
    :type featureName: str
    :param color: The color to set the element template.
    :type color: int
    :return: None
    """

    # Get the ElementTemplate path for the feature "Contacts". Update the element template if needed.
    elementTemplateInstance = GetFeatureLayerElementTemplateInstance(dgnFile, conn, featureName)
    if elementTemplateInstance is None:
        print(f"Failed to get ElementTemplate for feature \"{featureName}\".")
        return

    index = 0
    retVal = ElementTemplateParamsHelper.SetElementColor (elementTemplateInstance, color, dgnFile, index)
    if (eETSTATUS_Success == retVal) :
        print (f"SetElementColor success: {color}")
    else:
        print (f"SetElementColor failed: {color}")  

def QueryProjectArea(clearAll):
    """
    Query features in the ProjectArea by fence

    :param clearAll: Clear all features for any connection. Otherwise, clear all features for this connection.
    :type clearAll: bool
    :return: The server connection
    """

    url = "https://mrdata.usgs.gov/wfs/sgmc?request=getcapabilities&service=WFS"
    conn = GetWFSConnection(url)
    if conn is not None:
        #conn.Show(WString("transportation"))
        
        if clearAll == True:
            # Clear all features for any connection...
            ConnectionManager.ClearAllFeatureInstances(eClearFeaturesAreaMode_All)
        else:        
            # Clear all features for this connection...
            SetAllFeatureSelectedState(conn, True)
            clearConnections = ServerConnectionPtrArray()
            clearConnections.push_back (conn)
            status, nCleared = ConnectionManager.GetManager().ClearConnectionsFeatureInstances (eClearFeaturesAreaMode_All, clearConnections)

        # 
        dgnFile = ISessionMgr.GetActiveDgnFile()
        if dgnFile:
            color = 5
            UpdateFeatureLayerElementTemplate_Color(dgnFile, conn, "Contacts", color)

        # Query by fence...
        nQueried = QueryServerConnectionByFence(conn, "Contacts")    
        
    else:
        print("Connection failed...") 

    return conn

def CreateProjectArea(boundary_name):
    '''
    Create a named boundary for Fort Lauderdale, Florida.

    :param boundary_name: The name of the boundary.
    :type boundary_name: str
    :return: True if the named boundary is successfully created, False otherwise.
    :rtype: bool
    '''

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        return False        

    existingBound = NamedBoundary.FindByName(WString(boundary_name), None, ISessionMgr.ActiveDgnModelRef)
    if existingBound is None:
        existingBound = NamedBoundary.FindOrphanByName(WString(boundary_name), ISessionMgr.ActiveDgnModelRef)
    
    boundary_result = True
    if existingBound is None:
    # Approximate Lat/Lon bounding box coordinates for Fort Lauderdale, Florida
        boundary_coordinates = [
            (26.1224, -80.1373),  # Northwest corner
            (26.1224, -80.1045),  # Northeast corner
            (26.0842, -80.1045),  # Southeast corner
            (26.0842, -80.1373),  # Southwest corner
            (26.1224, -80.1373)   # Closing the polygon
        ]
        boundary_result = CreateNamedBoundary(boundary_name, boundary_coordinates)        
    else:
        print(f"Named boundary '{boundary_name}' already exists.")
    return boundary_result

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
        # Create a fence from the ProjectArea named boundary
        boundary_name = "FortLauderdaleBoundary"
        boundary_result = CreateProjectArea (boundary_name)
        if boundary_result == False:
            print(f"Failed to create named boundary {boundary_name}.")
        else:
            if CreateFenceFromNamedBoundary(boundary_name) == False:
                print(f"Failed to create fence from named boundary {boundary_name}.")
            else:
                # Apply a wireframe display style to the active view
                displayStyleName = "Wireframe"
                ApplyDisplayStyleToActiveView(displayStyleName)                

                # Fit the view to the named boundary
                FitViewToNamedBoundary(boundary_name)

                # Query features by fence
                conn = QueryProjectArea(True)
                if conn is None:
                    print(f"Failed to query features in the {boundary_name} named boundary.")

    print("Script end...") 