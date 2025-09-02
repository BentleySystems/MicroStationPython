from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *

'''
Example showing Geospatial Context query of a project area in Fort Lauderdale, Florida.

1. Create a named boundary from lat/long bounding box around Fort Lauderdale, Florida
2. Connect to Esri ArcGIS™ server URL: https://carto.nationalmap.gov/arcgis/rest/services/transportation/MapServer
3. Query features from the server within the named boundary

'''

def GetActiveConnection (url):
    """
    Get the active connection to the given Server URL in the active DGN model

    :param url: The Server URL of the new connection. Cannot be empty.
    :type url: str
    :return: The active Server Connection.
    :rtype: ServerConnection
    """    

    print(f"URL type: {type(url)}")
    searchURL = url
    print ("GetActiveConnection URL=", searchURL)
    # Check if connection is already active
    active_connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections(active_connections)
    if len(active_connections) > 0:
        for conn in active_connections:
            pIURLServerP = conn.GetIURLServer ()
            if pIURLServerP :
                currentUrl = str(pIURLServerP.GetURL()).strip()
                if currentUrl == searchURL:
                    print ("GetActiveConnection: ActiveConnection URL=", currentUrl)
                    return conn

    return None   

def GetSavedConnection (url):
    """
    Get the saved connection to the given Server URL in the active DGN model

    :param url: The Server URL of the saved connection. Cannot be empty.
    :type url: str
    :return: The saved Server Connection.
    :rtype: ServerConnection
    """    

    print(f"URL type: {type(url)}")
    searchURL = url
    print ("GetSavedConnection URL=", searchURL)

    # Check if connection is saved in the dgn 
    saved_connections = ServerConnectionPtrArray()
    ConnectionManager.GetSavedConnections(saved_connections)

    if len(saved_connections) == 0:
        print ("GetConnection: NO SavedConnections")
        return None

    if len(saved_connections) > 0:
        for sc in saved_connections:
            pIURLServerP = sc.GetIURLServer ()
            if pIURLServerP :
                currentUrl = str(pIURLServerP.GetURL()).strip()
                if currentUrl == searchURL:
                    print ("GetSavedConnection: SavedConnection URL=", currentUrl)
                    return sc

    return None

def CreateArcGISConnection (url, newConnectionName="", userName="", password="", *target_layers):
    """
    Create a new Geospatial Context connection to the given Esri ArcGIS™ Server URL in the active DGN model

    :param url: The Server URL of the new connection. Cannot be empty.
    :type url: str
    :param newConnectionName: The name for the new connection. If empty, then a default connection name is used.
    :type url: str   
    :param userName: The user name for the connection. Can be empty.
    :type userName: str
    :param password: The password for the connection. Can be empty.
    :type password: str    
    :return: The new Server Connection.
    :rtype: ServerConnection
    """    

    print(f"URL type: {type(url)}")
    print(f"newConnectionName type: {type(newConnectionName)}")
    urlW = WString(url)
    userNameW = WString(userName)
    passwordW = WString(password)
    connectionName = WString("")
    if newConnectionName is None or newConnectionName == "":
        ServerConnection.GetDefaultConnectionNameForURL (connectionName, urlW)
    else:
        connectionName = WString(newConnectionName)
    print (f"New connection name={str(connectionName)}")
    try:
        status, conn = ConnectionManager.GetManager().CreateArcGISConnectionWithoutDefaultElementTemplates (urlW, connectionName, userNameW, passwordW)
        if status != eGeospatialContextStatus_Success :
            error = WString()
            ConnectionManager.GetManager().GetLastError (error)
            MessageCenter.ShowInfoMessage(f"Failed to connect to server {url}.  Status={status} Error={error}", "", False)
            return None
        else:
            return conn

    except Exception as e:
        print(f"Exception while creating the connection: {str(e)}")
        return None

    return conn

def GetArcGISConnection(url, newConnectionName="", userName="", password="", *target_layers):
    """
    Get a new or existing Geospatial Context connection to the given Esri ArcGIS™ Server URL in the active DGN model

    :param url: The Server URL of the new connection. Cannot be empty.
    :type url: str
    :param newConnectionName: The name for a new connection. If empty, then a default connection name is used.
    :type url: str      
    :param userName: The user name for the connection. Can be empty.
    :type userName: str
    :param password: The password for the connection. Can be empty.
    :type password: str
    :return: The new or existing Server Connection.
    :rtype: ServerConnection
    """    

    print(f"URL type: {type(url)}")
    print(f"newConnectionName type: {type(newConnectionName)}")    

    # Check if connection is already active
    print ("GetArcGISConnection URL=", url)
    conn = GetActiveConnection (url)
    if conn is not None:
        return conn
 
    # Check if connection is saved in the dgn and activate it, otherwise create a new connection
    conn = GetSavedConnection (url)
    if conn is not None:
        print ("GetArcGISConnection: SavedConnection URL=", url)
        status = ConnectionManager.GetManager().ActivateConnection (conn)
        if status != eGeospatialContextStatus_Success :
            error = WString()
            ConnectionManager.GetManager().GetLastError (error)
            MessageCenter.ShowInfoMessage (f"Failed to activate saved connection to server. Status={status} Error={error}", "", False)                    
            return None
        else:
            print ("GetArcGISConnection: SavedConnection Activated")
            return GetActiveConnection (url)

    # Connection not found...create it
    print ("GetArcGISConnection: Connection not found...create it URL=", url)
    return CreateArcGISConnection(url, newConnectionName, userName, password, target_layers)

def get_arcgis_data_boundary_based(boundary_name="testboundary", *target_layers):
    """
    Query connection features by a named boundary.

    :param boundary_name: The name of the boundary to query. Defaults to "testboundary".
    :type boundary_name: str, optional
    :param target_layers: The target layers to query. Defaults to empty, which means all layers.
    :type target_layers: tuple, optional
    :return: True if the entities for the selected boundary have been imported into the active model, False otherwise.
    :rtype: bool
    """
    print("Starting function get_arcgis_data_boundary_based")
    manager = ConnectionManager.GetManager()
    if not manager:
        print("Failed: Could not get ConnectionManager")
        return False
    print("ConnectionManager retrieved successfully.")
    
    # Configuration
    arcgis_url = "https://carto.nationalmap.gov/arcgis/rest/services/transportation/MapServer"
    arcgis_connection_name = "Transportation_Lines"
    user_name = ""
    password = ""

    print("Attempting to create the connection...")
    try:
        connection = GetArcGISConnection(arcgis_url, arcgis_connection_name, user_name, password, target_layers)
        print(f"Connection created: {connection is not None}")
        if connection is None:
            print("Connection is null after GetArcGISConnection.")
            return False
    except Exception as e:
        print(f"Exception while creating the connection: {str(e)}")
        return False
    
    if not manager.IsConnectionActivated(connection):
        print("Activating the connection...")
        activate_status = manager.ActivateConnection(connection)
        print(f"Activation status: {activate_status}")
        if not manager.IsConnectionActivated(connection):
            print("Failed to activate the connection.")
            return False
    
    feature_specs = ServerFeatureSpecificationPtrArray()
    connection.GetFeatureSpecifications(feature_specs)
    if len(feature_specs) == 0:
        print("No features available for this connection.")
        return False
    print("Layers found in the dataset:")
    for i, spec in enumerate(feature_specs):
        layer_name = str(spec.GetDisplayName()).strip()
        print(f"{i+1}. {layer_name}")
    if not target_layers:
        first_spec = feature_specs
        first_layer_name = str(first_spec.GetDisplayName()).strip()
        target_layers = [first_layer_name]
        print(f"No target layers specified. Using the first layer: {first_layer_name}")
    target_layers_str = [str(layer).strip() for layer in target_layers]
    for spec in feature_specs:
        spec.SetIsSelected(False)
    layer_found_count = 0
    for spec in feature_specs:
        display_name_str = str(spec.GetDisplayName()).strip()
        if display_name_str in target_layers_str:
            spec.SetIsSelected(True)
            layer_found_count += 1
            print(f"Layer {display_name_str} has been selected.")
    if layer_found_count == 0:
        print("No target layers were found.")
        return False
    
    update_status = manager.UpdateConnectionFeatureSelections(connection)
    print(f"UpdateConnectionFeatureSelections status = {update_status}")
    if update_status not in [GeospatialContextStatus.eGeospatialContextStatus_Success, GeospatialContextStatus.eGeospatialContextStatus_NoChange]:
        print("Failed to update feature selections.")
        return False
    
    ConnectionManager.ClearAllFeatureInstances(eClearFeaturesAreaMode_All)
    connections = ServerConnectionPtrArray()
    connections.push_back(connection)
    boundary_name_wstring = WString(boundary_name)
    query_status, nQueried = manager.QueryConnectionsFeatureInstancesByNamedBoundary(boundary_name_wstring, connections)
    print(f"QueryConnectionsFeatureInstancesByNamedBoundary status = {query_status}, nQueried={nQueried}")
    if query_status == GeospatialContextStatus.eGeospatialContextStatus_Success and nQueried > 0:
        print("Entities for the selected boundary have been imported into the active model.")
        return True
    else:
        print("No entities were queried or the query failed.")
        error = WString()
        ConnectionManager.GetManager().GetLastError (error)
        print (f"Failed to query features. Status={query_status} Error={error}")          
        return False

def lat_long_to_master_units(lat, long):
    """
    Convert latitude and longitude to MicroStation master units.

    :param lat: Latitude value.
    :type lat: float
    :param long: Longitude value.
    :type long: float
    :return: Converted coordinates in master units.
    :rtype: tuple (x, y)
    """
    # Create a DPoint3d for the lat/long
    geo_point = GeoPoint()
    geo_point.Init(long, lat, 0)

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("Failed DgnGCS.FromModel.")
        return (0,0)       

    # Transform the geographic point to master units
    dgn_point = DPoint3d()
    status = dgnGCS.UorsFromLatLong(dgn_point, geo_point)
    
    if status != ReprojectStatus.eREPROJECT_Success:
        print("Failed CartesianFromLatLong.")
        return (0,0)

    return (dgn_point.x, dgn_point.y)

def create_named_boundary(boundary_name, boundary_coordinates):
    """
    Create a named boundary in the active DGN model.

    :param boundary_name: The name of the boundary to create.
    :type boundary_name: str
    :param boundary_coordinates: The coordinates of the boundary in lat/long.
    :type boundary_coordinates: list of tuples (lat, long)
    :return: True if the boundary was created successfully, False otherwise.
    :rtype: bool
    """
    points = DPoint3dArray()
    for coord in boundary_coordinates:
        master_units = lat_long_to_master_units(coord[0], coord[1])
        point = DPoint3d(master_units[0], master_units[1], 0)
        points.append(point)

    eeh = EditElementHandle()
    status = ShapeHandler.CreateShapeElement(eeh, None, points, ISessionMgr.ActiveDgnModelRef.Is3d(), ISessionMgr.ActiveDgnModelRef)
    if BentleyStatus.eSUCCESS != status:
        print("Failed to create polygon element.")
        return False
    print("Polygon element created successfully.")

    # Add the polygon to the active model
    if BentleyStatus.eSUCCESS != eeh.AddToModel():
        print("Failed to add polygon element to the active model.")
        return False
    print("Polygon element added to the active model.")

    # Create the named boundary
    boundary = NamedBoundary.Create()
    if not boundary:
        print("Failed to create named boundary.")
        return False
    boundary.SetName(WString(boundary_name))
    boundary.SetGraphicalElement(eeh)
    boundary.SetModelRef(ISessionMgr.ActiveDgnModelRef)
    boundary.Save()
    print(f"Named boundary '{boundary_name}' created successfully.")
    return True

# Main
if __name__ == "__main__":
    print("Script start...")

    # Check if Geographic Coordinate System is set in active model
    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        newGCS = DgnGCS.CreateGCS("EPSG:3857", ISessionMgr.ActiveDgnModelRef)
        if newGCS is None:
            print("No GCS in the active model.")
        else:
           newGCS.ToModel(ISessionMgr.ActiveDgnModelRef, True, True, True, True)

    dgnGCS = DgnGCS.FromModel(ISessionMgr.ActiveDgnModelRef, True)
    if dgnGCS is None:
        print("No GCS in the active model.")
        exit()

    boundary_name = "FortLauderdaleBoundary"

    existingBound = NamedBoundary.FindByName (WString (boundary_name), None, ISessionMgr.ActiveDgnModelRef)
    if existingBound is None:
        existingBound = NamedBoundary.FindOrphanByName (WString (boundary_name), ISessionMgr.ActiveDgnModelRef)

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
        boundary_result = create_named_boundary(boundary_name, boundary_coordinates)        
    else:
        print(f"Named boundary '{boundary_name}' already exists.")
    
    if boundary_result:
        print("Named boundary found or created successfully.")
        query_result = get_arcgis_data_boundary_based(boundary_name, "Local Connecting Roads Map", "Local Roads Map")
        print(f"Final result: {'Success' if query_result else 'Failure'}")
    else:
        print("Failed to find or create named boundary.")    
    print("Script end...")
    