#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
#import pytest
from MSPyBentley import *
#from MSPyBentleyGeom import *
from MSPyECObjects import *
#from MSPyDgnPlatform import *
#from MSPyDgnView import *
from MSPyMstnPlatform import *

import debugpy

'''  Test active model elements for queried elements ''' 
def test_IsQueriedServerFeatureElement ():
    graphicalElements = ISessionMgr.ActiveDgnModelRef.GetDgnModel ().GetGraphicElements()
    for ref in graphicalElements :
        eh = ElementHandle (ref, ISessionMgr.ActiveDgnModelRef)
        ConnectionManager.IsQueriedServerFeatureElement (eh)

'''  Test get saved connections from the active model ''' 
def test_GetSavedConnections ():
    connections = ServerConnectionPtrArray()
    '''ConnectionManager.GetSavedConnectionsByModel (connections, ISessionMgr.GetActiveDgnModel())'''
    ConnectionManager.GetSavedConnections (connections)
    if connections.__len__() == 0:
        print ("test_GetSavedConnections: NO SavedConnections")
        return

    nConnections = 1
    for conn in connections :
        name = conn.GetName ()
        serverTypeName = WString()
        serverTypeName = conn.GetServerTypeName ()
        print ("test_GetSavedConnections: SavedConnection Name=", name, ", ServerType=", serverTypeName)
        prefix = WString("SavedConn #")
        prefix += WString(str(nConnections))
        prefix += WString(": ")
        nConnections += 1
        conn.Show (prefix)

#    print ("Saved conns count=", connections.GetCount ())

'''  Test get active connections  ''' 
def test_GetActiveConnections ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_GetActiveConnections: Num ActiveConnections=", connections.__len__())
        return

    '''  Test get feature name from queried element ''' 
def test_GetServerFeatureClassNameFromElement ():
    featureName = WString()
    graphicalElements = ISessionMgr.ActiveDgnModelRef.GetDgnModel ().GetGraphicElements()
    for ref in graphicalElements :
        eh = ElementHandle (ref, ISessionMgr.ActiveDgnModelRef)
        ConnectionManager.GetServerFeatureClassNameFromElement (featureName, eh)

'''  Test activate a connection  ''' 
def test_ActivateConnection ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetSavedConnections (connections)
    if connections.__len__() == 0:
        print ("test_ActivateConnection: NO SavedConnections")
        return

    nConnections = 1
    for conn in connections :
        name = conn.GetName ()
        serverTypeName = WString()
        serverTypeName = conn.GetServerTypeName ()
        isActive = ConnectionManager.GetManager().IsConnectionActivated (conn)
        print ("test_ActivateConnection: SavedConnection Name=", name, ", ServerType=", serverTypeName, "isActivated=", isActive)
        status = ConnectionManager.GetManager().ActivateConnection (conn)
        isActive = ConnectionManager.GetManager().IsConnectionActivated (conn)        
        print ("test_ActivateConnection: ActivateConnection status = ", status, "isActivated=", isActive)
        prefix = WString("ActivatedSavedConn #")
        prefix += WString(str(nConnections))
        prefix += WString(": ")
        nConnections += 1
        conn.Show (prefix)

'''  Test Is a connection activated ''' 
def test_IsConnectionActivated ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetSavedConnections (connections)
    if connections.__len__() == 0:
        print ("test_IsConnectionActivated: NO SavedConnections")
        return

    for conn in connections :
        name = conn.GetName ()
        serverTypeName = WString()
        serverTypeName = conn.GetServerTypeName ()
        isActive = ConnectionManager.GetManager().IsConnectionActivated (conn)
        print ("test_IsConnectionActivated: SavedConnection Name=", name, ", ServerType=", serverTypeName, "isActivated=", isActive)               

'''  Test Get connection name from URL ''' 
def test_GetDefaultConnectionNameForURL ():
    url = WString("https://sampleserver6.arcgisonline.com/arcgis/rest/services/Military/FeatureServer")
    connectionName = WString()
    ServerConnection.GetDefaultConnectionNameForURL (connectionName, url)
    print ("ConnectionName = ", connectionName, " for URL ", url)

'''  Test Create an ArcGIS connection ''' 
def test_CreateArcGISConnection ():

    url = WString("https://sampleserver6.arcgisonline.com/arcgis/rest/services/Military/FeatureServer")
    connectionName = WString()
    ServerConnection.GetDefaultConnectionNameForURL (connectionName, url)
    print ("test_CreateArcGISConnection: ConnectionName = ", connectionName)
    userName = WString()
    password = WString()
    status, conn = ConnectionManager.GetManager().CreateArcGISConnection (url, connectionName, userName, password)
    print ("test_CreateArcGISConnection: CreateArcGISConnection status = ", status)
    if status == eGeospatialContextStatus_Success :
        prefix = WString("Created and Activated ArcGIS Connection:")
        conn.Show(prefix)

'''  Test Create a WFS connection ''' 
def test_CreateWFSConnection ():

    url = WString("https://mrdata.usgs.gov/wfs/sgmc?request=getcapabilities&service=WFS")
    connectionName = WString()
    ServerConnection.GetDefaultConnectionNameForURL (connectionName, url)
    print ("test_CreateWFSConnection: ConnectionName = ", connectionName)
    userName = WString()
    password = WString()
    flipCoordinates = False
    preferHttpPost = False
    status, conn =  ConnectionManager.GetManager().CreateWFSConnection (url, connectionName, userName, password, flipCoordinates, preferHttpPost)
    print ("test_CreateWFSConnection: CreateWFSConnection status = ", status)
    if status == eGeospatialContextStatus_Success :
        prefix = WString("Created and Activated WFS Connection:")
        conn.Show(prefix)

'''  Test Update connection feature selections''' 
def test_UpdateConnectionFeatureSelections ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_UpdateConnectionFeatureSelections: NO ActiveConnections")
        return

    for conn in connections :
        featureSpecs = ServerFeatureSpecificationPtrArray()
        conn.GetFeatureSpecifications (featureSpecs)
        for spec in featureSpecs :
            displayName = spec.GetDisplayName ()
            if displayName == WString("Units") or displayName == WString("C2 Military Operations Line") :
                spec.SetIsSelected (True)
            else:
                spec.SetIsSelected (False)

        status = ConnectionManager.GetManager().UpdateConnectionFeatureSelections (conn)
        print ("test_UpdateConnectionFeatureSelections: UpdateConnectionFeatureSelections status = ", status)

'''  Test Delete connection ''' 
def test_DeleteConnection ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_DeleteConnection: NO ActiveConnections")
        return

    for conn in connections :
        name = conn.GetName ()
        status = ConnectionManager.GetManager().DeleteConnection (conn)
        print ("test_DeleteConnection: DeleteConnection status = ", status, " Connection Name=", name)

'''  Test Query Connections Feature Instances ''' 
def test_QueryConnectionsFeatureInstances ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_QueryConnectionsFeatureInstances: NO ActiveConnections")
        return

    print ("test_QueryConnectionsFeatureInstances: nActiveConnections=", connections.__len__())
    queryConnections = ServerConnectionPtrArray()
    for conn in connections :
        serverType = conn.GetServerType();
        if serverType == eConnectionServerType_ArcGIS:
            queryConnections.push_back (conn)
            print("server type=", serverType)
            featureSpecs = ServerFeatureSpecificationPtrArray()
            conn.GetFeatureSpecifications (featureSpecs)
            for spec in featureSpecs :
                displayName = spec.GetDisplayName ()
                if displayName == WString("Units") or displayName == WString("C2 Military Operations Line") :
                    spec.SetIsSelected (True)
                else:
                    spec.SetIsSelected (False)
                print ("Feature=[",displayName, "] IsSelected=", spec.IsSelected)

    status, nQueried = ConnectionManager.GetManager().QueryConnectionsFeatureInstances (eQueryFeaturesAreaMode_All, queryConnections)
    print ("test_QueryConnectionsFeatureInstances: QueryConnectionsFeatureInstances status = ", status, " nQueryConnections=", queryConnections.__len__(), " nQueried=", nQueried)

'''  Test Query Connections Feature InstancesByNamedBoundary ''' 
def test_QueryConnectionsFeatureInstancesByNamedBoundary ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_QueryConnectionsFeatureInstancesByNamedBoundary: NO ActiveConnections")
        return

    print ("test_QueryConnectionsFeatureInstancesByNamedBoundary: nActiveConnections=", connections.__len__())
    queryConnections = ServerConnectionPtrArray()
    for conn in connections :
        serverType = conn.GetServerType();
        if serverType == eConnectionServerType_ArcGIS:
            queryConnections.push_back (conn)
            print("server type=", serverType)
            featureSpecs = ServerFeatureSpecificationPtrArray()
            conn.GetFeatureSpecifications (featureSpecs)
            for spec in featureSpecs :
                displayName = spec.GetDisplayName ()
                if displayName == WString("Units") or displayName == WString("C2 Military Operations Line") :
                    spec.SetIsSelected (True)
                else:
                    spec.SetIsSelected (False)
                print ("Feature=[",displayName, "] IsSelected=", spec.IsSelected)    

    boundaryName = WString("TestBoundary")
    nQueried = 0
    status, nQueried = ConnectionManager.GetManager().QueryConnectionsFeatureInstancesByNamedBoundary (boundaryName, queryConnections)
    print ("test_QueryConnectionsFeatureInstancesByNamedBoundary: QueryConnectionsFeatureInstancesByNamedBoundary status = ", status, " nQueryConnections=", queryConnections.__len__(), " nQueried=", nQueried)

'''  Test Query Connections Feature InstancesByView ''' 
def test_QueryConnectionsFeatureInstancesByView ():
    connections = ServerConnectionPtrArray()
    queryConnections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_QueryConnectionsFeatureInstancesByView: NO ActiveConnections")
        return

    print ("test_QueryConnectionsFeatureInstancesByView: nActiveConnections=", connections.__len__())
    for conn in connections :
        serverType = conn.GetServerType();
        if serverType == eConnectionServerType_ArcGIS:
            queryConnections.push_back (conn)
            print("server type=", serverType)
            featureSpecs = ServerFeatureSpecificationPtrArray()
            conn.GetFeatureSpecifications (featureSpecs)
            for spec in featureSpecs :
                displayName = spec.GetDisplayName ()
                if displayName == WString("Units") or displayName == WString("C2 Military Operations Line") :
                    spec.SetIsSelected (True)
                else:
                    spec.SetIsSelected (False)
                print ("Feature=[",displayName, "] IsSelected=", spec.IsSelected)    
    viewIndex = 0
    status, nQueried = ConnectionManager.GetManager().QueryConnectionsFeatureInstancesByView (viewIndex, queryConnections)
    print ("test_QueryConnectionsFeatureInstancesByView: QueryConnectionsFeatureInstancesByView status = ", status, " nQueryConnections=", queryConnections.__len__(), " nQueried=", nQueried)

'''  Test Clear All Feature Instances ''' 
def test_ClearAllFeatureInstances ():
    status, nCleared = ConnectionManager.ClearAllFeatureInstances (eClearFeaturesAreaMode_All)
    print ("test_ClearAllFeatureInstances: ClearAllFeatureInstances status = ", status, " nCleared=", nCleared)

'''  Test Clear All Feature Instances By View ''' 
def test_ClearAllFeatureInstancesByView ():
    viewIndex = 0
    status, nCleared = ConnectionManager.ClearAllFeatureInstancesByView (viewIndex)
    print ("test_ClearAllFeatureInstancesByView: ClearAllFeatureInstancesByView status = ", status, " nCleared=", nCleared)

'''  Test Clear All Feature InstancesByNamedBoundary ''' 
def test_ClearAllFeatureInstancesByNamedBoundary ():
    boundaryName = WString("TestBoundary")
    nCleared = 0
    status, nCleared = ConnectionManager.ClearAllFeatureInstancesByNamedBoundary (boundaryName)
    print ("test_ClearAllFeatureInstancesByNamedBoundary: ClearAllFeatureInstancesByNamedBoundary status = ", status, " nCleared=", nCleared)

'''  Test Clear Connections Feature Instances ''' 
def test_ClearConnectionsFeatureInstances ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_ClearConnectionsFeatureInstances: NO ActiveConnections")
        return

    status, nCleared = ConnectionManager.GetManager().ClearConnectionsFeatureInstances (eClearFeaturesAreaMode_All, connections)
    print ("test_ClearConnectionsFeatureInstances: ClearConnectionsFeatureInstances status = ", status, " nCleared=", nCleared)

'''  Test Clear Connections Feature Instances By View ''' 
def test_ClearConnectionsFeatureInstancesByView ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_ClearConnectionsFeatureInstancesByView: NO ActiveConnections")
        return

    viewIndex = 0
    status, nCleared = ConnectionManager.GetManager().ClearConnectionsFeatureInstancesByView (viewIndex, connections)
    print ("test_ClearConnectionsFeatureInstancesByView: ClearConnectionsFeatureInstancesByView status = ", status, " nCleared=", nCleared)

'''  Test Clear Connections Feature InstancesByNamedBoundary ''' 
def test_ClearConnectionsFeatureInstancesByNamedBoundary ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_ClearConnectionsFeatureInstancesByNamedBoundary: NO ActiveConnections")
        return

    boundaryName = WString("TestBoundary")
    status, nCleared = ConnectionManager.GetManager().ClearConnectionsFeatureInstancesByNamedBoundary (boundaryName, connections)
    print ("test_ClearConnectionsFeatureInstancesByNamedBoundary: ClearConnectionsFeatureInstancesByNamedBoundary status = ", status, " nCleared=", nCleared)

'''  Test Get Last Error ''' 
def test_GetLastError ():
    error = WString()
    status = ConnectionManager.GetManager().GetLastError (error)
    print ("GetLastError status = ", status)
    print ("Last Error = ", error)

'''  Test Get ServerConnection info ''' 
def test_GetServerConnectionInfo ():
    connections = ServerConnectionPtrArray()
    ConnectionManager.GetManager().GetActiveConnections (connections)
    if connections.__len__() == 0:
        print ("test_GetServerConnectionInfo: NO ActiveConnections")
        return

    for conn in connections :
        name = conn.GetName ()
        print ("test_GetServerConnectionInfo: ActiveConnection Name=", name)
        serverType = conn.GetServerType ()
        uniqueID = conn.GetUniqueID ()
        conn.Show (WString("MyConn"))

        pIURLServerP = conn.GetIURLServer ()
        if pIURLServerP :
            url = pIURLServerP.GetURL ()
            print ("test_GetServerConnectionInfo: ActiveConnection URL=", url)
            user = pIURLServerP.GetUser ()
            pIURLServerP.SetUser (WString("TestUser"))
            pIURLServerP.SetPassword (WString(""))
            
        featureSpecs = ServerFeatureSpecificationPtrArray()
        conn.GetFeatureSpecifications (featureSpecs)
        for spec in featureSpecs :
            className = spec.GetClassName ()
            displayName = spec.GetDisplayName ()
            isSelected1 = spec.IsSelected
            print ("test_GetServerConnectionInfo: Feature DisplayName=", displayName, " IsSelected ", isSelected1)
            isSelected2 = spec.GetIsSelected ()
            spec.SetIsSelected (isSelected2)

'''  Test Get NeedsUserNameAndPassword ''' 
def test_GetNeedsUserNameAndPassword ():
    url = WString("https://sampleserver6.arcgisonline.com/arcgis/rest/services/Military/FeatureServer")
    status = ServerConnection.GetNeedsUserNameAndPassword (url)
    print ("GetNeedsUserNameAndPassword status = ", status)

    
if __name__ == "__main__":
#    debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
#    print("Waiting for debugger attach")
#    debugpy.wait_for_client()
#    debugpy.breakpoint()    

    doSavedConnectionTests = False
    if doSavedConnectionTests == True:
        test_GetSavedConnections ()    
        test_IsConnectionActivated ()        
        test_ActivateConnection ()

    doConnectionTests = False
    if doConnectionTests == True:
        test_GetDefaultConnectionNameForURL()
        test_DeleteConnection ()
        test_CreateArcGISConnection ()
        test_CreateWFSConnection ()
        test_UpdateConnectionFeatureSelections ()        
        test_GetActiveConnections ()          

    doElementRelatedTests = False
    if doElementRelatedTests == True:
        test_IsQueriedServerFeatureElement ()
        test_GetServerFeatureClassNameFromElement ()

    test_QueryConnectionsFeatureInstances ()

    doQueryClearTests = False
    if doQueryClearTests == True:
        test_ClearAllFeatureInstances ()
        test_QueryConnectionsFeatureInstances ()
        test_ClearConnectionsFeatureInstances ()
        test_QueryConnectionsFeatureInstancesByView ()
        test_ClearAllFeatureInstancesByView ()    
        test_QueryConnectionsFeatureInstancesByView ()
        test_ClearConnectionsFeatureInstancesByView ()     
        test_QueryConnectionsFeatureInstancesByNamedBoundary ()        
        test_ClearAllFeatureInstancesByNamedBoundary ()        
        test_ClearConnectionsFeatureInstances ()
        test_ClearConnectionsFeatureInstancesByView ()
        test_ClearConnectionsFeatureInstancesByNamedBoundary ()

    doMiscTests = False
    if doMiscTests == True:
        test_GetLastError ()
        test_GetServerConnectionInfo ()
        test_GetNeedsUserNameAndPassword ()
    print ("GeospatialContext_Test: All tests done")
