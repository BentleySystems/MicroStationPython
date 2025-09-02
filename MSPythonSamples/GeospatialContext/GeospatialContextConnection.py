from MSPyBentley import *
from MSPyMstnPlatform import *

'''
Example demonstrating how to create or obtain a Geospatial Context connection to an ArcGIS Server
'''

def GetFeatureItemType (conn, target_layer):
    """
    Get the item type library and item type names for the feature in the given target layer in the Server Connection.

    :param conn: The Server Connection to set the selected state of the features. Cannot be None.
    :type conn: ServerConnection
    :param target_layer: The target layer display name to get the item type information of the features.
    :type target_layer: str
    :return: The item type library and item type names.
    :rtype: str, str
    """

    featureSpecs = ServerFeatureSpecificationPtrArray()
    conn.GetFeatureSpecifications (featureSpecs)
    if len(featureSpecs) == 0:
        print("No features available for this connection.")
        return 0

    target_layer_str = str(target_layer).strip()
    for spec in featureSpecs:
        class_name_str = str(spec.GetClassName()).strip()
        display_name_str = str(spec.GetDisplayName()).strip()
        if (display_name_str == target_layer_str) or (class_name_str == target_layer_str):
            return str(spec.GetItemTypeLibraryName()).strip(), str(spec.GetItemTypeName()).strip()

    return  None, None 

def GetFeatureElementTemplatePath (conn, target_layer):
    """
    Get the element template path of the feature in the given target layer in the Server Connection

    :param conn: The Server Connection. Cannot be None.
    :type conn: ServerConnection
    :param target_layer: The target layer display name to get the ElementTemplate path of the features.
    :type target_layer: str
    :return: The element template path.
    :rtype: str
    """

    featureSpecs = ServerFeatureSpecificationPtrArray()
    conn.GetFeatureSpecifications (featureSpecs)
    if len(featureSpecs) == 0:
        print("No features available for this connection.")
        return 0

    target_layer_str = str(target_layer).strip()
    for spec in featureSpecs:
        class_name_str = str(spec.GetClassName()).strip()
        display_name_str = str(spec.GetDisplayName()).strip()
        if (display_name_str == target_layer_str) or (class_name_str == target_layer_str):
            return str(spec.GetElementTemplatePath()).strip()

    return  None 

def SetFeatureSelectedState (conn, target_layers):
    """
    Set the selected state of the features in the given target layers in the Server Connection

    :param conn: The Server Connection to set the selected state of the features. Cannot be None.
    :type conn: ServerConnection
    :param target_layers: The target layer display names to set the selected state of the features.
    :type target_layers: list
    :return: The number of layers set to IsSelected = True.
    :rtype: int
    """

    featureSpecs = ServerFeatureSpecificationPtrArray()
    conn.GetFeatureSpecifications (featureSpecs)
    if len(featureSpecs) == 0:
        print("No features available for this connection.")
        return 0

    target_layers_str = [str(layer).strip() for layer in target_layers]
    layer_found_count = 0
    for spec in featureSpecs:
        class_name_str = str(spec.GetClassName()).strip()
        display_name_str = str(spec.GetDisplayName()).strip()
        if (display_name_str in target_layers_str) or (class_name_str in target_layers_str):
            spec.SetIsSelected(True)
            layer_found_count += 1
        else:
            spec.SetIsSelected(False)
        #print (f"Feature=[{class_name_str},{display_name_str}] IsSelected=", spec.IsSelected)

    return  layer_found_count 

def SetFeatureSelectedStateByLayerClassNames (conn, target_layer_classNames):
    """
    Set the selected state of the features in the given target layers in the Server Connection

    :param conn: The Server Connection to set the selected state of the features. Cannot be None.
    :type conn: ServerConnection
    :param target_layer_classNames: The target layer class names to set the selected state of the features.
    :type target_layer_classNames: list
    :return: The number of layers set to IsSelected = True.
    :rtype: int
    """

    featureSpecs = ServerFeatureSpecificationPtrArray()
    conn.GetFeatureSpecifications (featureSpecs)
    if len(featureSpecs) == 0:
        print("No features available for this connection.")
        return 0

    target_layers_str = [str(layer).strip() for layer in target_layer_classNames]
    layer_found_count = 0
    for spec in featureSpecs:
        class_name_str = str(spec.GetClassName()).strip()
        if (class_name_str in target_layers_str):
            spec.SetIsSelected(True)
            layer_found_count += 1
        else:
            spec.SetIsSelected(False)
        #display_name_str = str(spec.GetDisplayName()).strip()
        #print (f"Feature=[{class_name_str},{display_name_str}] IsSelected=", spec.IsSelected)

    return  layer_found_count 

def SetAllFeatureSelectedState (conn, isSelected):
    """
    Set the selected state of the features in the Server Connection

    :param conn: The Server Connection to set the selected state of the features. Cannot be None.
    :type conn: ServerConnection
    :return: The number of layers whose IsSelected is set to the given value.
    :rtype: int
    """
    featureSpecs = ServerFeatureSpecificationPtrArray()
    conn.GetFeatureSpecifications (featureSpecs)
    if len(featureSpecs) == 0:
        print("No features available for this connection.")
        return 0

    layer_found_count = 0
    for spec in featureSpecs:
        spec.SetIsSelected(isSelected)
        layer_found_count += 1

    return  layer_found_count 

def CreateArcGISConnection (url, newConnectionName="", userName="", password=""):
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
        status, conn = ConnectionManager.GetManager().CreateArcGISConnection (urlW, connectionName, userNameW, passwordW)
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

def CreateArcGISConnectionWithoutDefaultElementTemplates (url, newConnectionName="", userName="", password=""):
    """
    Create a new Geospatial Context connection to the given Esri ArcGIS™ Server URL in the active DGN model without creating default element templates.

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

def CreateWFSConnection (url, newConnectionName="", userName="", password="", flipCoordinates=False, preferHttpPost=False):
    """
    Create a new Geospatial Context connection to the given WFS Server URL in the active DGN model

    :param url: The Server URL of the new connection. Cannot be empty.
    :type url: str
    :param newConnectionName: The name for the new connection. If empty, then a default connection name is used.
    :type url: str   
    :param userName: The user name for the connection. Can be empty.
    :type userName: str
    :param password: The password for the connection. Can be empty.
    :type password: str    
    :param flipCoordinates: The flag to flip the coordinates. Default is False.
    :type flipCoordinates: bool
    :param preferHttpPost: The flag to prefer HTTP POST. Default is False.
    :type preferHttpPost: bool
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
        status, conn = ConnectionManager.GetManager().CreateWFSConnection (urlW, connectionName, userNameW, passwordW, flipCoordinates, preferHttpPost)
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

def GetActiveOrSavedConnection(url):
    """
    Get an active or saved(and activated) Geospatial Context connection to the given Server URL in the active DGN model

    :param url: The Server URL of the new connection. Cannot be empty.
    :type url: str
    :return: The active or saved(and activated) Server Connection.
    :rtype: ServerConnection
    """    

    print(f"URL type: {type(url)}")

    # Check if connection is already active
    print ("GetActiveOrSavedConnection.GetActiveConnection URL=", url)
    conn = GetActiveConnection (url)
    if conn is not None:
        return conn
 
    # Check if connection is saved in the dgn and activate it, otherwise create a new connection
    conn = GetSavedConnection (url)
    if conn is not None:
        print (f"GetActiveOrSavedConnection: Activating SavedConnection URL={url}")
        status = ConnectionManager.GetManager().ActivateConnection (conn)
        if status != eGeospatialContextStatus_Success :
            error = WString()
            ConnectionManager.GetManager().GetLastError (error)
            MessageCenter.ShowInfoMessage (f"Failed to activate saved connection to server. Status={status} Error={error}", "", False)                    
            return None
        else:
            print ("GetActiveOrSavedConnection: SavedConnection Activated")
            #conn.Show(WString("ActivateConnection"))
            return conn

    # Connection not found
    print ("GetActiveOrSavedConnection: Connection not found, URL=", url)
    return None

def GetArcGISConnection(url, newConnectionName="", userName="", password=""):
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

    # Check if connection is already active or saved in DGN
    print ("GetArcGISConnection URL=", url)
    conn = GetActiveOrSavedConnection (url)
    if conn is not None:
        return conn
 
    # Connection not found...create it
    print ("GetArcGISConnection: Connection not found...create it URL=", url)
    print(f"newConnectionName type: {type(newConnectionName)}")    
    return CreateArcGISConnection(url, newConnectionName, userName, password)

def GetWFSConnection (url, newConnectionName="", userName="", password=""):
    """
    Get the active WFS connection in the active DGN model

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

    # Check if connection is already active or saved in DGN
    print ("GetWFSConnection URL=", url)
    conn = GetActiveOrSavedConnection (url)
    if conn is not None:
        return conn
 
    # Connection not found...create it
    print ("GetWFSConnection: Connection not found...create it URL=", url)
    print(f"newConnectionName type: {type(newConnectionName)}")    
    return CreateWFSConnection(url, newConnectionName, userName, password)


if __name__ == "__main__":
    print("Script start...")
    url = "https://ca.dep.state.fl.us/arcgis/rest/services/OpenData/STATEWIDE_LU_2004_2013/MapServer/3"
    userName = ""
    password = ""

    # Create a new connection to the server URL
    conn = GetArcGISConnection(url, None, userName, password)
    if conn is not None:        
        # Set the selected state of the Transportation_Lines layer to True
        layerName = "Statewide Land Use Land Cover Map"
        SetFeatureSelectedState(conn, [layerName])
        conn.Show(WString(f"ArcGIS Connection for {url}"))     

        elementTemplatePath = GetFeatureElementTemplatePath(conn, layerName)
        print (f"[{layerName}] ElementTemplate path is: {elementTemplatePath}")
        itemTypeLibName, itemTypeName = GetFeatureItemType(conn, layerName)
        print (f"[{layerName}] ItemTypeLibraryName={itemTypeLibName} ItemTypeName={itemTypeName}")        
    else:
        print (f"Connection is None for {url}")

    url = "https://mrdata.usgs.gov/wfs/sgmc?request=getcapabilities&service=WFS"
    conn = GetWFSConnection(url, None, userName, password)
    if conn is not None:        
        # Set the selected state of the Transportation_Lines layer to True
        SetFeatureSelectedState(conn, ["Contacts"])
        conn.Show(WString(f"WFS Connection for {url}"))     

        layerName = "Contacts"
        elementTemplatePath = GetFeatureElementTemplatePath(conn, layerName)
        print (f"[{layerName}] ElementTemplate path is: {elementTemplatePath}")        
        itemTypeLibName, itemTypeName = GetFeatureItemType(conn, layerName)
        print (f"[{layerName}] ItemTypeLibraryName={itemTypeLibName} ItemTypeName={itemTypeName}")
    else:
        print (f"Connection is None for {url}")
        
    print("Script end...")
