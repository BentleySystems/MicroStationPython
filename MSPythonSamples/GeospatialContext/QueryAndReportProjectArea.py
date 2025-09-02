from MSPyECObjects import *
from GeospatialContextConnection import *
from QueryServerConnection import *
from GeospatialContextUtilities import *

'''
Example showing Geospatial Context query and report of roadways affected by a SE 17th Street Causeway Bridge project area in Fort Lauderdale, Florida.

1. Ensure that Geographic Coordinate System is set in active model
2. Create a named boundary from lat/long bounding box around SE 17th Street Causeway Bridge, Fort Lauderdale, Florida
3. Create a fence from the named boundary
4. Connect to Esri ArcGIS™ server URL: https://carto.nationalmap.gov/arcgis/rest/services/transportation/MapServer
5. Query features from the server within the fence from the named boundary
6. Fit the named boundary in the view
7. Get or create a report definition for the Local Roads Map feature layer.
8. Show the report results in a dialog
'''

''' Preview report results. '''
def PreviewReport(reportCategoryName, reportName):
    '''
    Preview report results.

    :param reportCategoryName: The name of the report category.
    :type reportCategoryName: str
    :param reportName: The name of the report.
    :type reportName: str

    '''

    PyCadInputQueue.SendKeyin ("DIALOG REPORTS OPEN " )
    PyCadInputQueue.SendKeyin ("REPORTS DIALOG DESELECTALL " )
    PyCadInputQueue.SendKeyin ("REPORTS DIALOG SELECT " + reportCategoryName)
    PyCadInputQueue.SendKeyin ("REPORTS DIALOG DESELECTALL " )
    PyCadInputQueue.SendKeyin ("REPORTS DIALOG SELECT " + reportCategoryName + "\\" + reportName)
    PyCadInputQueue.SendKeyin ("REPORTS TOGRID" )

''' Get the existing report category with the given name from the active design file. '''    
def GetExistingReportCategory(reportCategoryName):
    '''
    Get the existing report category with the given name from the given design file.

    :param reportCategoryName: The name of the report category.
    :type reportCategoryName: str
    :return: The existing report category.
    :rtype: ReportCategoryNode

    '''

    dgnFile = ISessionMgr.GetActiveDgnFile()
    if not dgnFile:
        print("Failed to get active DGN file.")
        return None    

    reportCat = ReportCategoryNode.FindByName(reportCategoryName, dgnFile)
    if reportCat:
        rCategoryNode= ReportCategoryNode(reportCat)
        return rCategoryNode        

    return None

''' Get the schema for the item type library with the given internal name. '''
def GetItemTypeLibrarySchema(itemTypeLibInternalName):
    """
    Get the schema for the item type library with the given internal name.

    :param itemTypeLibInternalName: The internal name of the item type library.
    :type itemTypeLibInternalName: str
    :return: The schema.
    :rtype: ECSchema
    """

    #list to collect schema names
    schemaList = list()
    #Get dgnEC manager instance
    mgr = DgnECManager.GetManager()
    # Get the current DGN model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()

    #iterate through all reachable models
    for modelRef in dgnModel.GetReachableModelRefs():
        #check for attachment, skip it if attached file is missing
        if modelRef.IsDgnAttachment():
            attachment = modelRef.AsDgnAttachment()
            if attachment.IsMissingFile():
                continue

        #get dgnFile from model
        dgnFile = modelRef.GetDgnFile()

        #discover schemas
        infos = SchemaInfoArray()
        mgr.DiscoverSchemas(infos, dgnFile, ECSchemaPersistence.eECSCHEMAPERSISTENCE_All, DgnECHostType.eAll)        
        infoContainer = SchemaInfoArray()
        for info in infos:
            infoContainer.append(info)
        
        if len(infoContainer) <= 0:
            continue
        
        #iterate container
        for info in infoContainer:
            #locate schema
            ecSchema = mgr.LocateSchemaInDgnFile(info, SchemaMatchType.eSCHEMAMATCHTYPE_Exact)
            if ecSchema is None:
                continue  

            if ecSchema.GetName().Equals(itemTypeLibInternalName) == True:
                print (f"Found schema {ecSchema.GetFullSchemaName()} [{ecSchema.GetName()}]")
                return ecSchema

    return None

''' Create a new report definition with the given name in the given category with selection by fence. The "Local Roads Map" feature layer is used to create the report
 using the layer item type class. '''
def CreateReportDefinitionForFeatureLayer(reportCategoryName, reportName, conn, layerName):
    '''
    Create a new report definition with the given name.

    :param reportCategoryName: The name of the report category.
    :type reportCategoryName: str
    :param reportName: The name of the report definition.
    :type reportName: str
    :param conn: The server connection.
    :type conn: ServerConnection
    :param layerName: The name of the feature layer.
    :type layerName: str
    :return: The new report definition.
    :rtype: ReportDefinition

    '''
    dgnFile = ISessionMgr.GetActiveDgnFile()
    if not dgnFile:
        print("Failed to get active DGN file.")
        return None

    repCat = GetExistingReportCategory(reportCategoryName)
    if repCat is None:
        print(f"Failed to get report category {reportCategoryName}")
        repCat = ReportCategoryNode(reportCategoryName, 1, dgnFile)
        if not repCat:
            print(f"Failed to create report category {reportCategoryName}")
            return None    
    else:
        print(f"Found report category {reportCategoryName}")

    # Create the report based on the feature layer's item type class.
    reportDef = None
    itemTypeLibName, itemTypeName = GetFeatureItemType(conn, layerName)
    if itemTypeLibName and itemTypeName:
        # Find item type library by name in the design file
        itemTypeLib = ItemTypeLibrary.FindByName(itemTypeLibName, dgnFile)
        if itemTypeLib:
            print (f"Found item type library {itemTypeLibName} InternalName:{itemTypeLib.GetInternalName()}")
            # Get the item type from the item type library by its name
            schema = GetItemTypeLibrarySchema(itemTypeLib.GetInternalName())
            if schema:
                itemType = itemTypeLib.GetItemTypeByName(itemTypeName)  
                if itemType:
                    print (f"Found item type {itemTypeName} InternalName:{itemType.GetInternalName()}")
                    itemTypeClass = schema.GetClass(itemType.GetInternalName())
                    if itemTypeClass:
                        reportDef = repCat.GenerateReportFromClass(itemTypeClass, reportName, 1)
                    else:
                        print(f"Failed to get item type class for {itemType.GetInternalName()}")
    
    if not reportDef:
        print("Failed to create report definition based on item type {itemTypeLibName}:{itemTypeName} class.")
        return None

    # Set report by fence
    rDefNode = ReportDefinitionNode (reportDef)
    if not rDefNode is None:
        rDefScope = rDefNode.GetScope()
        rDefScope.InitForActiveModel()
        
        rDefScope.SetSelectionScopeOption (ReportScope.SelectionScopeOption.eByFence)
        rDefScope.SetReferencedModelOption (ReportScope.ReferencedModelOption.eNone)
        rDefScope.SetIncludeItemTypeOption (ReportScope.IncludeItemTypeOption.eIncludeUsedClasses)
        rDefScope.SetIncludeChildElements (False)

        rDefNode.SetScope(rDefScope)

    return reportDef

''' Get the existing report with the given name from the given design file. '''    
def GetExistingReport(reportName):
    '''
    Get the existing report with the given name from the given design file.

    :param dgnFile: The design file.
    :type dgnFile: DgnFile
    :param reportName: The name of the report.
    :type reportName: str
    :return: The existing report definition.
    :rtype: ReportDefinition

    '''

    dgnFile = ISessionMgr.GetActiveDgnFile()
    if not dgnFile:
        print("Failed to get active DGN file.")
        return None    
    print(f"Report collection type: {type(dgnFile)}")

    reportCollection = ReportDefinitionCollection(dgnFile)
    if not reportCollection:
        print("Failed to get report collection.")
        return None

    searchReport = WString(reportName)
    for i in range(0, reportCollection.Count):
        reportDef = reportCollection.GetReportDefinitionAt(i)
        if reportDef and reportDef.DisplayLabel == searchReport:
            return reportDef

    return None

''' Report features in the ProjectArea by fence '''
def ReportProjectArea(conn):
    """
    Report features in the ProjectArea by fence 

    :param conn: The server connection
    :type conn: ServerConnection

    :return: None
    """
    reportCategoryName = "FortLauderdaleBridgeProject"
    reportName = "RoadsAffectedByBridgeProject"
    layerName = "Local Roads Map"

    # Get or create the report definition
    rpt = GetExistingReport(reportName)
    if rpt is None:
        print(f"Failed to get report {reportName}")

        rpt = CreateReportDefinitionForFeatureLayer(reportCategoryName, reportName, conn, layerName)
        if rpt is None:
            print(f"Failed to create report {reportName}")        
            return
    else:
        print(f"Found existing report {reportName}")

    #  Show Report Preview
    PreviewReport(reportCategoryName, reportName)


''' Query features in the ProjectArea by fence from a Geospatial Context server connection into the active DGN model '''
def QueryProjectArea(clearAll):
    """
    Query features in the ProjectArea by fence from a Geospatial Context server connection to URL https://carto.nationalmap.gov/arcgis/rest/services/transportation/MapServer

    :param clearAll: Clear all features for any connection. Otherwise, clear all features for this connection.
    :type clearAll: bool
    :return: The server connection
    """

    url = "https://carto.nationalmap.gov/arcgis/rest/services/transportation/MapServer"
    conn = GetActiveOrSavedConnection(url)
    if conn is None:
        conn = CreateArcGISConnectionWithoutDefaultElementTemplates(url)
        if conn is None:
            print("CreateArcGISConnectionWithoutDefaultElementTemplates Failed to connect to server.")
            return None
        layer_found_count = SetFeatureSelectedState(conn, ["Local Connecting Roads Map", "Local Roads Map"])
        if layer_found_count == 0:
            layer_found_count = SetFeatureSelectedStateByLayerClassNames(conn, ["Local Connecting Roads Map", "Local Roads Map"])
            if layer_found_count == 0:
                print("Failed to SetFeatureSelectedState.")

        # Update and write the connection object so the saved connection has our feature selections on next open of this DGN
        status = ConnectionManager.GetManager().UpdateConnectionFeatureSelections(conn)
        print(f"UpdateConnectionFeatureSelections status = {status}")
        if status not in [GeospatialContextStatus.eGeospatialContextStatus_Success, GeospatialContextStatus.eGeospatialContextStatus_NoChange]:
            print("Failed to update feature selections.")

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

        # Query by fence...
        nQueried = QueryServerConnectionByFence(conn, "Local Connecting Roads Map", "Local Roads Map")    
        
    else:
        print("Connection failed...") 

    return conn

''' Create a named boundary for the project area around SE 17th Street Causeway Bridge in Fort Lauderdale, Florida '''
def CreateProjectArea(boundary_name):
    '''
    Create a named boundary for the project area around SE 17th Street Causeway Bridge in Fort Lauderdale, Florida.

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
        # Approximate Lat/Lon bounding box coordinates for SE 17th Street Causeway Bridge, Fort Lauderdale, Florida
        boundary_coordinates = [
            (26.107, -80.136),  # Northwest corner
            (26.107, -80.103),  # Northeast corner
            (26.093, -80.103),  # Southeast corner
            (26.093, -80.136),  # Southwest corner
            (26.107, -80.136)   # Closing the polygon
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
        boundary_name = "SE17thStreetCausewayBridgeProjectArea"
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

                # Query Local Roads features by fence
                conn = QueryProjectArea(True)
                if conn is None:
                    print("Failed to query features in the ProjectArea.")
                else:
                    # Generate a report of Local Roads in the ProjectArea
                    ReportProjectArea(conn)

    print("Script end...") 