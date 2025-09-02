from MSPyBentley import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from GeospatialContextConnection import *

'''
Example to get layers from datasets using the Geospatial Context API.

1. Ensure that Geographic Coordinate System is set in active model. If not set, then assign "EPSG:3857"
2. Connect to Esri ArcGIS™ server URL: https://ca.dep.state.fl.us/arcgis/rest/services/OpenData/STATEWIDE_LU_2004_2013/MapServer/3
3. Print the layers available in the connection.  The display name of each layer feature specification is printed.
4. Connect to WFS server URL: https://mrdata.usgs.gov/wfs/sgmc?request=getcapabilities&service=WFS
5. Print the layers available in the connection.  The display name of each layer feature specification is printed.
'''

''' Get layers from either an Esri ArcGIS™ or WFS dataset '''
def get_layers(serverType, url, newConnectionName):
    """
     Get layers from an Esri ArcGIS™ dataset using the Geospatial Context API.

        :param serverType: The type of server to connect to.
        :type serverType: int
        :param url: The URL of the Esri ArcGIS™ dataset.
        :type url: str
        :param newConnectionName: The URL of the Esri ArcGIS™ dataset.
        :type newConnectionName: str        
        :return: True if the layers are successfully printed, False otherwise.
        :rtype: bool

    """

    print("Starting function get_layers")

    manager = ConnectionManager.GetManager()
    if not manager:
        print("Failed: Could not get ConnectionManager")
        return False
    print("ConnectionManager retrieved successfully.")

    print("Attempting to get or create the connection...")
    connection = None
    try:
        if serverType == eConnectionServerType_ArcGIS:
            connection = GetArcGISConnection(url, newConnectionName)
        elif serverType == eConnectionServerType_WFS:
            connection = GetWFSConnection(url, newConnectionName)
        print(f"Connection retrieved or created: {connection is not None}")

        if connection is None:
            # If no new connections are created, active connections are checked
            active_connections = ServerConnectionPtrArray()
            manager.GetActiveConnections(active_connections)
            print("Active connections after attempt:")
            for ac in active_connections:
                ac_name = str(ac.GetName()).strip()
                print(f" - {ac_name}")

            desired_name = newConnectionName.strip()
            found_existing = False
            for c in active_connections:
                existing_name = str(c.GetName()).strip()
                print(f"Comparing existing '{existing_name}' to desired '{desired_name}'")
                if existing_name == desired_name:
                    connection = c
                    print("Found existing connection.")
                    found_existing = True
                    break

            if not found_existing:
                print("Connection is null after creation and no existing connection found.")
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

    return True
    

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
        print(f"Active model GCS: {dgnGCS.GetName()}")    

        url = "https://ca.dep.state.fl.us/arcgis/rest/services/OpenData/STATEWIDE_LU_2004_2013/MapServer/3"
        newConnectionName = "Land Use"
        result = get_layers(eConnectionServerType_ArcGIS, url, newConnectionName)
        if result:
            print(f"Layers successfully printed for {url}.")
        else:
            print(f"Failed to print layers for {url}.")

        url = "https://mrdata.usgs.gov/wfs/sgmc?request=getcapabilities&service=WFS"
        newConnectionName = ""
        result = get_layers(eConnectionServerType_WFS, url, newConnectionName)
        if result:
            print(f"Layers successfully printed for {url}.")
        else:
            print(f"Failed to print layers for {url}.")            
    print("Script end...")

