from MSPyBentley import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from GeospatialContextConnection import *

'''
Sample demonstrating how to query features  from a Geospatial Context server connection
'''

def QueryServerConnectionByView (conn, view_index=0, *target_layers):        
    """
    Query features in the given view from a Geospatial Context server connection to the active DGN model

    :param conn: The Server Connection to query. Cannot be None.
    :type conn: ServerConnection
    :param view_index: The view index to query features in. Defaults to 0.
    :type view_index: int
    :param target_layers: The target layers to query features from.
    :type target_layers: str
    :return: The number of features queried.
    :rtype: int
    """    
    layer_found_count = SetFeatureSelectedState(conn, target_layers)
    if layer_found_count == 0:
        layer_found_count = SetFeatureSelectedStateByLayerClassNames(conn, target_layers)
        if layer_found_count == 0:
            print("Failed to query features from server. No target layers were found.")
            return 0

    queryConnections = ServerConnectionPtrArray()
    queryConnections.push_back (conn)

    status, nQueried = ConnectionManager.GetManager().QueryConnectionsFeatureInstancesByView (view_index, queryConnections)
    if status != eGeospatialContextStatus_Success :
        error = WString()
        ConnectionManager.GetManager().GetLastError (error)
        MessageCenter.ShowInfoMessage (f"Failed to query features from server. Status={status} Error={error}", "", False)     
        return 0
    return nQueried

'''  Query features in the active fence from a Geospatial Context server connection to the active DGN model ''' 
def QueryServerConnectionByFence (conn, *target_layers):        
    """
    Query features in the active fence from a Geospatial Context server connection to the active DGN model

    :param conn: The Server Connection to query. Cannot be None.
    :type conn: ServerConnection
    :param target_layers: The target layers to query features from.
    :type target_layers: str
    :return: The number of features queried.
    :rtype: int
    """        
    if FenceManager.GetManager().IsFenceActive() == False:
        return 0

    layer_found_count = SetFeatureSelectedState(conn, target_layers)
    if layer_found_count == 0:
        layer_found_count = SetFeatureSelectedStateByLayerClassNames(conn, target_layers)
        if layer_found_count == 0:
            print("Failed to query features from server. No target layers were found.")
            return 0

    queryConnections = ServerConnectionPtrArray()
    queryConnections.push_back (conn)

    status, nQueried = ConnectionManager.GetManager().QueryConnectionsFeatureInstances (eQueryFeaturesAreaMode_Fence, queryConnections)
    if status != eGeospatialContextStatus_Success :
        error = WString()
        ConnectionManager.GetManager().GetLastError (error)
        MessageCenter.ShowInfoMessage (f"Failed to query features from server. Status={status} Error={error}", "", False)     
        return 0
    return nQueried

'''  Query features in the named boundary from a Geospatial Context server connection to the active DGN model ''' 
def QueryServerConnectionByNamedBoundary (conn, boundary_name, *target_layers):        
    """
    Query features in the named boundary from a Geospatial Context server connection to the active DGN model

    :param conn: The Server Connection to query. Cannot be None.
    :type conn: ServerConnection
    :param boundary_name: The name of the boundary to query features from.
    :type boundary_name: str
    :param target_layers: The target layers to query features from.
    :type target_layers: str
    :return: The number of features queried.
    :rtype: int
    """        
    layer_found_count = SetFeatureSelectedState(conn, target_layers)
    if layer_found_count == 0:
        layer_found_count = SetFeatureSelectedStateByLayerClassNames(conn, target_layers)
        if layer_found_count == 0:
            print("Failed to query features from server. No target layers were found.")
            return 0

    queryConnections = ServerConnectionPtrArray()
    queryConnections.push_back (conn)

    status, nQueried = ConnectionManager.GetManager().QueryConnectionsFeatureInstancesByNamedBoundary (WString(boundary_name), queryConnections)
    if status != eGeospatialContextStatus_Success :
        error = WString()
        ConnectionManager.GetManager().GetLastError (error)
        MessageCenter.ShowInfoMessage (f"Failed to query features from server. Status={status} Error={error}", "", False)     
        return 0
    return nQueried

def testing_queryByView(conn):
    MessageCenter.ShowInfoMessage(f"Querying server features in view.", "", False)

    # Get the active viewport (view) in the current model
    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if viewport is None:
        view_index = 0
    else:
        view_index = viewport.GetViewNumber() # Get the active view index        
    nQueried = QueryServerConnectionByView(conn, view_index, "Local Connecting Roads Map", "Local Roads Map")    
    MessageCenter.ShowInfoMessage(f"Queried {nQueried} features from server.", "", False)

def testing_queryByFence(conn):
    nQueried = QueryServerConnectionByFence(conn, "Local Connecting Roads Map", "Local Roads Map")    
    MessageCenter.ShowInfoMessage(f"Queried {nQueried} features from server.", "", False)

def testing_queryByNamedBoundary(conn, boundary_name="FortLauderdaleBoundary"):
    nQueried = QueryServerConnectionByNamedBoundary(conn, boundary_name, "Local Connecting Roads Map", "Local Roads Map")    
    MessageCenter.ShowInfoMessage(f"Queried {nQueried} features from server.", "", False)

if __name__ == "__main__":  # check if this script is being run directly (not imported as a module)
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
        print(f"Active model GCS: {dgnGCS.GetName()}")    

        url = "https://carto.nationalmap.gov/arcgis/rest/services/transportation/MapServer"
        userName = ""
        password = ""
        conn = GetArcGISConnection(url, userName, password)
        if conn is not None:

            #testing_queryByView(conn);
            #testing_queryByFence(conn);
            boundary_name="FortLauderdaleBoundary"
            testing_queryByNamedBoundary(conn, boundary_name);

        else:
            print("Conn is None...")

    print("Script end...")