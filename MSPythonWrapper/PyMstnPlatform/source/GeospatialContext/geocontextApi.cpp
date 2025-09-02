/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyMstnPlatform\source\3dModeling\meshapi.cpp $
|
|  $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"

#include <GeospatialContext\GeospatialContextApi.h>

USING_NAMESPACE_BENTLEY_MSTNPLATFORM_GEOSPATIALCONTEXT

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetDefaultConnectionNameForURL = R"doc(Get the default connection name for the given URL

This method generates a default connection name for the given URL. The connection name is a human-readable string that describes the connection.
The connection name is generated based on the server type and URL.
For example, the default connection name for the URL "https://sampleserver6.arcgisonline.com/arcgis/rest/services/Military/FeatureServer" is "Military".

Parameter ``connectionName``:
    The Name of the connection.

Parameter ``url``:
    The URL of the server.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetFeatureSpecifications = R"doc(Get the list of a connection's feature specifications.

Parameter ``featureSpecs``:
    The List of feature specifications for the connection.

Returns:
    None.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_CreateDefaultElementTemplates = R"doc(Create the default element templates with associated item types for features as specified by the import specification.
This method is not normally called by the user, since it is called internally by the Import method to create(if not existing) the default element templates with associated item types for the features as specified by the import specification.
This method is useful if the element template must exist to be modified before the import is performed. For example, change the element template active point type from zero length line to cell before importing.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_Show = R"doc(Show the connection information for debugging.

Parameter ``prefixString``:
    The Prefix string to show before the connection information.

Returns:
    None.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetIURLServer = R"doc(Get the IURLServer interface on the ServerConnection, or NULL if the server connection is not for a URL based server.

Returns:
    IURLServerP.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_IURLServer_GetURL = R"doc(Get the URL of this connection.

Returns:
    The URL for the connection.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_IURLServer_GetUser = R"doc(Get the User Name for the connection.

Returns:
    The User Name for the connection.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_IURLServer_SetUser = R"doc(Set the User Name for the connection.

Parameter ``userName``:
    The User Name for the connection. Default value is empty.

Returns:
    None.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_IURLServer_SetPassword = R"doc(Set the User Password for the connection.

Parameter ``userName``:
    The User Password for the connection. Default value is empty.

Returns:
    None.
)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_GetClassName = R"doc(Get the class name of this feature specification.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_GetDisplayName = R"doc(Get the display name of this feature specification.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_GetElementTemplatePath = R"doc(Get the ElementTemplate path of this feature specification. Note: This only has a value after a connection is established.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_GetItemTypeLibraryName = R"doc(Get the item type library name of this feature specification. Note: This only has a value after a connection is established.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_GetItemTypeName = R"doc(Get the item type name of this feature specification. Note: This only has a value after a connection is established.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_GetIsSelected = R"doc(Get the selected state of this feature specification.

Returns:
bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerFeatureSpecification_SetIsSelected = R"doc(Set the selected state of this feature specification.

Parameter ``isSelected``:
    Is feature specification selected.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetName = R"doc(Get the name of this connection. See also GetDefaultConnectionNameForURL.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetServerType = R"doc(Get the server type of this connection.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetServerTypeName = R"doc(Get the server type name of this connection.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetUniqueID = R"doc(Get the Unique Identifier for the connection.)doc";
static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ServerConnection_GetNeedsUserNameAndPassword = R"doc(Determine if the server for the given URL needs username and password input for connection.
A server may require a username and password for connection. This method checks if the server for the given URL requires a username and password.
If OAuth is used, the server may not require a username and password.

Parameter ``url``:
    The URL of the server.

Returns:
    bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_GetManager = R"doc()doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_GetSavedConnections = R"doc(Get the connections saved in the active model)

Parameter ``connections``:
    The List of saved connections.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_GetActiveConnections = R"doc(Get the active connections)

Parameter ``connections``:
    The List of active connections.

Returns:
    None.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_IsQueriedServerFeatureElement = R"doc(Is this element a server feature element that has been queried from the server.

Parameter ``element``:
    The Element to check.

Returns:
    Bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_GetServerFeatureClassNameFromElement = R"doc(Get the server feature class name from the given element)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ActivateConnection = R"doc(Activate a connection to the server)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_CreateArcGISConnection = R"doc(Create a new connection to an ArcGIS server.
After creating the connection, all features are selected and default element templates with associated item types for the features are created.
See also : #ConnectionManager::CreateArcGISConnectionWithoutDefaultElementTemplates which does not create element templates for all layers in the connection.

Parameter ``[out]``:
    The new Connection to the server.

Parameter ``url``:
    The Server URL of the new connection. Cannot be empty.

Parameter ``connectionName``:
    The Name of the new connection. Cannot be empty. See also GetDefaultConnectionNameForURL.

Parameter ``userName``:
    The User Name for the connection. Default value is empty.  See also ServerConnection::GetNeedsUserNameAndPassword.

Parameter ``password``:
    The User Password for the connection. Default value is empty. See also ServerConnection::GetNeedsUserNameAndPassword.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_CreateArcGISConnectionWithoutDefaultElementTemplates = R"doc(Create a new connection to an ArcGIS server without creating default element templates for each feature.
By default, after creating the connection, all features are selected. The caller may want to select specific features for the connection before creating default element templates.
To create the element templates with associated item types for the selected features, call @See ServerConnection::CreateDefaultElementTemplates.
See also: #ConnectionManager::CreateArcGISConnection which creates element templates for all features in the connection.
See also: #ServerConnection::CreateDefaultElementTemplates which creates element templates for only selected features in the connection.

Parameter ``[out]``:
    The new Connection to the server.

Parameter ``url``:
    The Server URL of the new connection. Cannot be empty.

Parameter ``connectionName``:
    The Name of the new connection. Cannot be empty. See also GetDefaultConnectionNameForURL.

Parameter ``userName``:
    The User Name for the connection. Default value is empty.  See also ServerConnection::GetNeedsUserNameAndPassword.

Parameter ``password``:
    The User Password for the connection. Default value is empty. See also ServerConnection::GetNeedsUserNameAndPassword.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_CreateWFSConnection = R"doc(Create a new connection to a WFS server.
After creating the connection, all features are selected and default element templates with associated item types for the features are created.
See also : #ConnectionManager::CreateWFSConnectionWithoutDefaultElementTemplates which does not create element templates for all layers in the connection.

Parameter ``[out]``:
    The new Connection to the server.

Parameter ``url``:
    The Server URL of the new connection. Cannot be empty.

Parameter ``connectionName``:
    The Name of the new connection. Cannot be empty. See also GetDefaultConnectionNameForURL.

Parameter ``userName``:
    The User Name for the connection. Default value is empty.  See also ServerConnection::GetNeedsUserNameAndPassword.

Parameter ``password``:
    The User Password for the connection. Default value is empty. See also ServerConnection::GetNeedsUserNameAndPassword.

Parameter ``flipCoordinates``:
    The Flip Coordinates value for the connection.
    WFS 1.0.0 servers specify the axis order for geographic coordinates as longitude/latitude (X/Y).
    WFS 1.1.0 and 2.0.0 servers specify the axis order as latitude/longitude (Y/X). This may result in queried features being rotated or flipped.
    To avoid this, enable Flip Coordinates.

Parameter ``preferHttpPost``:
    The Prefer Http post value for the connection. Default method for WFS requests is HTTP Get. Use this property to enforce usage of Http Post. This may help to resolve issues during query.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_CreateWFSConnectionWithoutDefaultElementTemplates = R"doc(Create a new connection to an WFS server without creating default element templates for each feature.
By default, after creating the connection, all features are selected. The caller may want to select specific features for the connection before creating default element templates.
To create the element templates with associated item types for the selected features, call See also: #ServerConnection::CreateDefaultElementTemplates.
See also: #ConnectionManager::CreateWFSConnection which creates element templates for all features in the connection.
See also: #ServerConnection::CreateDefaultElementTemplates which creates element templates for only selected features in the connection.

Parameter ``[out]``:
    The new Connection to the server.

Parameter ``url``:
    The Server URL of the new connection. Cannot be empty.

Parameter ``connectionName``:
    The Name of the new connection. Cannot be empty. See also GetDefaultConnectionNameForURL.

Parameter ``userName``:
    The User Name for the connection. Default value is empty.  See also ServerConnection::GetNeedsUserNameAndPassword.

Parameter ``password``:
    The User Password for the connection. Default value is empty. See also ServerConnection::GetNeedsUserNameAndPassword.

Parameter ``flipCoordinates``:
    The Flip Coordinates value for the connection.
    WFS 1.0.0 servers specify the axis order for geographic coordinates as longitude/latitude (X/Y).
    WFS 1.1.0 and 2.0.0 servers specify the axis order as latitude/longitude (Y/X). This may result in queried features being rotated or flipped.
    To avoid this, enable Flip Coordinates.

Parameter ``preferHttpPost``:
    The Prefer Http post value for the connection. Default method for WFS requests is HTTP Get. Use this property to enforce usage of Http Post. This may help to resolve issues during query.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_QueryConnectionsFeatureInstances = R"doc(Query the feature instances into the active model for a list of connections within a specified area.
Parameter ``mode``:
    The Query area mode.

Parameter ``connections``:
    The List of connections to query.

Parameter ``[out]``:
    The returned Number of features queried.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_QueryConnectionsFeatureInstancesByView = R"doc(Query the feature instances into the active model for a list of connections within a view.
Parameter ``viewIndex``:
    The View index.

Parameter ``connections``:
    The List of connections to query.

Parameter ``[out]``:
    The returned Number of features queried.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_QueryConnectionsFeatureInstancesByNamedBoundary = R"doc(Query the feature instances into the active model for a list of connections within a specified named boundary.
Parameter ``boundaryName``:
    The Named boundary name.
    Named boundary is a user defined boundary that can be used to query features within a specific area.
    Named boundaries can be created using the FenceManager class.

Parameter ``connections``:
    The List of connections to query.

Parameter ``[out]``:
    The returned Number of features queried.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ClearAllFeatureInstances = R"doc(Clear all feature instances from the active model for any connection (active, inactive, or deleted) based on the specified area mode.
    The method returns the number of features cleared.

Parameter ``mode``:
    The Clear area mode.

Parameter ``[out]``:
    The returned Number of features cleared.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ClearAllFeatureInstancesByView = R"doc(Clear all feature instances from the active model for any active, inactive, or deleted connection within a view.
    The method returns the number of features cleared.

Parameter ``viewIndex``:
    The View index.

Parameter ``[out]``:
    The returned Number of features cleared.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ClearAllFeatureInstancesByNamedBoundary = R"doc(Clear all feature instances from the active model for any active, inactive, or deleted connection within a specified named boundary.
    The method returns the number of features cleared.
    Named boundary is a user defined boundary that can be used to clear features within a specific area.
    Named boundaries can be created using the FenceManager class.

Parameter ``boundaryName``:
    The Named boundary name.

Parameter ``[out]``:
    The returned Number of features cleared.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ClearConnectionsFeatureInstances = R"doc(Clear feature instances from the active model for specified active connections.
    This method clears the features from the specified connections based on the specified area mode.
    The method returns the number of features cleared.

Parameter ``mode``:
    The Clear area mode.

Parameter ``connections``:
    The List of connections to clear features from.

Parameter ``[out]``:
    The returned Number of features cleared.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ClearConnectionsFeatureInstancesByView = R"doc(Clear feature instances from the active model within a view for specified active connections.
    This method clears the features from the specified connections within the specified view.
    The method returns the number of features cleared.

Parameter ``viewIndex``:
    The View index.

Parameter ``connections``:
    The List of connections to clear features from.

Parameter ``[out]``:
    The returned Number of features cleared.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_ClearConnectionsFeatureInstancesByNamedBoundary = R"doc(Clear feature instances from the active model within a specified named boundary for specified active connections.
    This method clears the features from the specified connections within the specified named boundary.
    The method returns the number of features cleared.
    Named boundary is a user defined boundary that can be used to clear features within a specific area.
    Named boundaries can be created using the FenceManager class.

Parameter ``boundaryName``:
    The Named boundary name.

Parameter ``connections``:
    The List of connections to clear features from.

Parameter ``[out]``:
    The returned Number of features cleared.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_IsConnectionActivated = R"doc(Is a connection activated in the session.

Parameter ``connection``:
    The Connection to check.

Returns:
    Bool value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_UpdateConnectionFeatureSelections = R"doc(Update an existing connection with modified feature selections.
The connection information is updated in the session and the active model.

Parameter ``connection``:
    The Connection to the server.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_DeleteConnection = R"doc(Delete an existing connection.
The connection information is updated in the session and the active model.

Parameter ``connection``:
    The Connection to the server.

Returns:
    GeospatialContextStatus value.

)doc";

static const char* __doc_Bentley_MstnPlatform_GeospatialContext_ConnectionManager_GetLastError = R"doc(Get the last recorded error message during a ConnectionManager operation.

Parameter ``error``:
    The last Error message.

Returns:
    GeospatialContextStatus value.

)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                      11/2024
+---------------+---------------+---------------+---------------+---------------+------*/
void def_GeospatialContextAPI(py::module_& m)
    {
    //===================================================================================
    // enum GeospatialContextStatus
    py::enum_< GeospatialContextStatus>(m, "GeospatialContextStatus", py::arithmetic())
    .value("eGeospatialContextStatus_Success", GeospatialContextStatus::Success)
    .value("eGeospatialContextStatus_MstnInDwgWorkMode", GeospatialContextStatus::MstnInDwgWorkMode)
    .value("eGeospatialContextStatus_NoCoordSysAttach", GeospatialContextStatus::NoCoordSysAttach)
    .value("eGeospatialContextStatus_NoQueryableFeatures", GeospatialContextStatus::NoQueryableFeatures)
    .value("eGeospatialContextStatus_UserAbort", GeospatialContextStatus::UserAbort)
    .value("eGeospatialContextStatus_NoEraseableFeatures", GeospatialContextStatus::NoEraseableFeatures)
    .value("eGeospatialContextStatus_NoChange", GeospatialContextStatus::NoChange)
    .value("eGeospatialContextStatus_NoExistingConnection", GeospatialContextStatus::NoExistingConnection)
    .value("eGeospatialContextStatus_ConnectionNotActivated", GeospatialContextStatus::ConnectionNotActivated)
    .value("eGeospatialContextStatus_ConnectionNotFound", GeospatialContextStatus::ConnectionNotFound)
    .value("eGeospatialContextStatus_NoActiveModel", GeospatialContextStatus::NoActiveModel)
    .value("eGeospatialContextStatus_Malloc", GeospatialContextStatus::Malloc)
    .value("eGeospatialContextStatus_ConnectionAlreadyActivated", GeospatialContextStatus::ConnectionAlreadyActivated)
    .value("eGeospatialContextStatus_BadServerType", GeospatialContextStatus::BadServerType)
    .value("eGeospatialContextStatus_NoActiveConnections", GeospatialContextStatus::NoActiveConnections)
    .value("eGeospatialContextStatus_BadViewIndex", GeospatialContextStatus::BadViewIndex)
    .value("eGeospatialContextStatus_BadNamedBoundaryName", GeospatialContextStatus::BadNamedBoundaryName)
    .value("eGeospatialContextStatus_QueryFailed", GeospatialContextStatus::QueryFailed)
    .value("eGeospatialContextStatus_ClearFailed", GeospatialContextStatus::ClearFailed)
    .value("eGeospatialContextStatus_NoClearableFeatures", GeospatialContextStatus::NoClearableFeatures)
    .value("eGeospatialContextStatus_EditConnectionFailed", GeospatialContextStatus::EditConnectionFailed)
    .value("eGeospatialContextStatus_DeleteConnectionFailed", GeospatialContextStatus::DeleteConnectionFailed)
    .value("eGeospatialContextStatus_BadConnection", GeospatialContextStatus::BadConnection)
    .value("eGeospatialContextStatus_CreateConnectionFailed", GeospatialContextStatus::CreateConnectionFailed)
    .value("eGeospatialContextStatus_ActivateConnectionFailed", GeospatialContextStatus::ActivateConnectionFailed)
    .value("eGeospatialContextStatus_NoActiveSelectionSet", GeospatialContextStatus::NoActiveSelectionSet)
    .value("eGeospatialContextStatus_NoActiveFence", GeospatialContextStatus::NoActiveFence)
    .value("eGeospatialContextStatus_NoLastError", GeospatialContextStatus::NoLastError)
    .value("eGeospatialContextStatus_NotAFeature", GeospatialContextStatus::NotAFeature)
    .value("eGeospatialContextStatus_ImportFailed", GeospatialContextStatus::ImportFailed)
    .value("eGeospatialContextStatus_BadImportType", GeospatialContextStatus::BadImportType)
    .value("eGeospatialContextStatus_NoImportableFeatures", GeospatialContextStatus::NoImportableFeatures)
    .value("eGeospatialContextStatus_CreateImportSpecificationFailed", GeospatialContextStatus::CreateImportSpecificationFailed)
    .value("eGeospatialContextStatus_CreateExportSpecificationFailed", GeospatialContextStatus::CreateExportSpecificationFailed)
    .value("eGeospatialContextStatus_ExportFailed", GeospatialContextStatus::ExportFailed)
    .value("eGeospatialContextStatus_InvalidFolder", GeospatialContextStatus::InvalidFolder)
    .value("eGeospatialContextStatus_CreateDefaultElementTemplatesFailed", GeospatialContextStatus::CreateDefaultElementTemplatesFailed)
    .export_values();

    //===================================================================================
    // enum QueryFeaturesAreaMode
    py::enum_< QueryFeaturesAreaMode>(m, "QueryFeaturesAreaMode", py::arithmetic())
        .value("eQueryFeaturesAreaMode_All", QueryFeaturesAreaMode::All)
        .value("eQueryFeaturesAreaMode_Fence", QueryFeaturesAreaMode::Fence)
        .export_values();

    //===================================================================================
    // enum ClearFeaturesAreaMode
    py::enum_< ClearFeaturesAreaMode>(m, "ClearFeaturesAreaMode", py::arithmetic())
        .value("eClearFeaturesAreaMode_All", ClearFeaturesAreaMode::All)
        .value("eClearFeaturesAreaMode_Fence", ClearFeaturesAreaMode::Fence)
        .value("eClearFeaturesAreaMode_SelectionSet", ClearFeaturesAreaMode::SelectionSet)
        .export_values();

    //===================================================================================
    // enum ConnectionServerType
    py::enum_< ServerType>(m, "ConnectionServerType", py::arithmetic())
        .value("eConnectionServerType_All", ServerType::Unknown)
        .value("eConnectionServerType_ArcGIS", ServerType::ArcGIS)
        .value("eConnectionServerType_WFS", ServerType::WFS)
        .export_values();

    //===================================================================================
    // struct ServerFeatureSpecification
    py::class_<ServerFeatureSpecification, ServerFeatureSpecificationPtr> c0(m, "ServerFeatureSpecification");
    py::bind_vector< bvector<ServerFeatureSpecificationPtr> >(m, "ServerFeatureSpecificationPtrArray", py::module_local(false));
    
    c0.def("GetClassName", [](ServerFeatureSpecification& self) {return WString(self.GetClassName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, GetClassName));
    c0.def("GetDisplayName", [](ServerFeatureSpecification& self) {return WString(self.GetDisplayName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, GetDisplayName));
    c0.def("GetElementTemplatePath", [](ServerFeatureSpecification& self) {return WString(self.GetElementTemplatePath()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, GetElementTemplatePath));
    c0.def("GetItemTypeLibraryName", [](ServerFeatureSpecification& self) {return WString(self.GetItemTypeLibraryName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, GetItemTypeLibraryName));
    c0.def("GetItemTypeName", [](ServerFeatureSpecification& self) {return WString(self.GetItemTypeName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, GetItemTypeName));

    c0.def_property("IsSelected", &ServerFeatureSpecification::GetIsSelected, &ServerFeatureSpecification::SetIsSelected);
    c0.def("GetIsSelected", &ServerFeatureSpecification::GetIsSelected, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, GetIsSelected));
    c0.def("SetIsSelected", &ServerFeatureSpecification::SetIsSelected, DOC(Bentley, MstnPlatform, GeospatialContext, ServerFeatureSpecification, SetIsSelected));

    //===================================================================================
    // struct IURLServer
    py::class_< IURLServer, std::unique_ptr < IURLServer, py::nodelete>> cUrlServer(m, "IURLServer");

    cUrlServer.def("GetURL", [](IURLServer& self) {return WString(self.GetURL()); }, DOC(Bentley, MstnPlatform, GeospatialContext, IURLServer, GetURL));

    cUrlServer.def("GetUser", [](IURLServer& self) {return WString(self.GetUser()); }, DOC(Bentley, MstnPlatform, GeospatialContext, IURLServer, GetUser));
    cUrlServer.def("SetUser", [](IURLServer& self, WStringCR userName) {self.SetUser(userName); }, "userName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, IURLServer, SetUser));

    cUrlServer.def("SetPassword", [](IURLServer& self, WStringCR password) {self.SetPassword(password); }, "password"_a, DOC(Bentley, MstnPlatform, GeospatialContext, IURLServer, SetPassword));

    //===================================================================================
    // struct ServerConnection : RefCountedBase
    py::class_<ServerConnection, ServerConnectionPtr> c1(m, "ServerConnection", py::multiple_inheritance());
    bind_PointerVector< ServerConnectionPtr >(m, "ServerConnectionPtrArray", py::module_local(false));

    c1.def("GetName", [](ServerConnection& self) {return WString(self.GetName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetName));
    
    c1.def("GetServerType", [](ServerConnection& self) {return self.GetServerType(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetServerType));

    c1.def("GetServerTypeName", [](ServerConnection& self) {return WString(self.GetServerTypeName()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetServerTypeName));

    c1.def("GetUniqueID", [](ServerConnection& self) {return WString(self.GetUniqueID()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetUniqueID));

    c1.def_static("GetDefaultConnectionNameForURL", &ServerConnection::GetDefaultConnectionNameForURL, "connectionName"_a, "url"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetDefaultConnectionNameForURL));

    c1.def_static("GetNeedsUserNameAndPassword", &ServerConnection::GetNeedsUserNameAndPassword, "url"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetNeedsUserNameAndPassword));

    c1.def("GetFeatureSpecifications", ([](ServerConnection& self, bvector<ServerFeatureSpecificationPtr>& featureSpecs)
        {
        self.GetFeatureSpecifications(featureSpecs);
        }), "featureSpecs"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetFeatureSpecifications));

    c1.def("Show", ([](ServerConnection& self, WStringCR prefixString)
        {
            self.Show(prefixString);
        }), "prefixString"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, Show));

    c1.def("GetIURLServer", [](ServerConnection& self) {return self.GetIURLServer(); }, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, GetIURLServer));
    c1.def("CreateDefaultElementTemplates", &ServerConnection::CreateDefaultElementTemplates, DOC(Bentley, MstnPlatform, GeospatialContext, ServerConnection, CreateDefaultElementTemplates));

    //===================================================================================
    // struct ConnectionManager
    py::class_< ConnectionManager, std::unique_ptr < ConnectionManager, py::nodelete>> c2(m, "ConnectionManager");

    c2.def_property_readonly_static("Manager", [](py::object const&) { return std::unique_ptr< ConnectionManager, py::nodelete>(&ConnectionManager::GetManager()); });
    c2.def_static("GetManager", []() { return std::unique_ptr< ConnectionManager, py::nodelete>(&ConnectionManager::GetManager()); }, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, GetManager));
    /*
    c2.def_static("GetSavedConnectionsByModel", ([](bvector<ServerConnectionPtr>& connections, DgnModelP dgnModel)
        {
            ConnectionManager::GetSavedConnections(connections, dgnModel);
        }), "connections"_a, "dgnModel"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, GetSavedConnections));
    */
    c2.def_static("GetSavedConnections", ([](bvector<ServerConnectionPtr>& connections)
        {
            DgnModelP dgnModel = ISessionMgr::GetActiveDgnModelP();
            if (nullptr == dgnModel)
                return;
            ConnectionManager::GetSavedConnections(connections, dgnModel);
        }), "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, GetSavedConnections));

    c2.def("GetActiveConnections", ([](ConnectionManager& self, bvector<ServerConnectionPtr>& connections)
        {
            self.GetActiveConnections(connections);
        }), "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, GetActiveConnections));

    c2.def_static("IsQueriedServerFeatureElement", [](ElementHandleCR eh)
        {
            return ConnectionManager::IsQueriedServerFeatureElement(eh);
        }, "eh"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, IsQueriedServerFeatureElement));

    c2.def_static("GetServerFeatureClassNameFromElement", &ConnectionManager::GetServerFeatureClassNameFromElement, "featureClassName"_a, "element"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, GetServerFeatureClassNameFromElement));

    c2.def("ActivateConnection", &ConnectionManager::ActivateConnection, "connection"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ActivateConnection));

    c2.def("CreateArcGISConnection", [](ConnectionManager& self, WStringCR url, WStringCR connectionName, WStringCR userName, WStringCR password)
        {
            ServerConnectionPtr connection;
            GeospatialContextStatus status = self.CreateArcGISConnection(connection, url, connectionName, userName, password);
            return py::make_tuple(status, connection);
        }, "url"_a, "connectionName"_a, "userName"_a, "password"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, CreateArcGISConnection));

    c2.def("CreateArcGISConnectionWithoutDefaultElementTemplates", [](ConnectionManager& self, WStringCR url, WStringCR connectionName, WStringCR userName, WStringCR password)
        {
            ServerConnectionPtr connection;
            GeospatialContextStatus status = self.CreateArcGISConnectionWithoutDefaultElementTemplates(connection, url, connectionName, userName, password);
            return py::make_tuple(status, connection);
        }, "url"_a, "connectionName"_a, "userName"_a, "password"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, CreateArcGISConnectionWithoutDefaultElementTemplates));

    c2.def("CreateWFSConnection", [](ConnectionManager& self, WStringCR url, WStringCR connectionName, WStringCR userName, WStringCR password, bool flipCoordinates, bool preferHttpPost)
        {
            ServerConnectionPtr connection;
            GeospatialContextStatus status = self.CreateWFSConnection(connection, url, connectionName, userName, password, flipCoordinates, preferHttpPost);
            return py::make_tuple(status, connection);
        }, "url"_a, "connectionName"_a, "userName"_a, "password"_a, "flipCoordinates"_a, "preferHttpPost"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, CreateWFSConnection));

    c2.def("CreateWFSConnectionWithoutDefaultElementTemplates", [](ConnectionManager& self, WStringCR url, WStringCR connectionName, WStringCR userName, WStringCR password, bool flipCoordinates, bool preferHttpPost)
        {
            ServerConnectionPtr connection;
            GeospatialContextStatus status = self.CreateWFSConnectionWithoutDefaultElementTemplates(connection, url, connectionName, userName, password, flipCoordinates, preferHttpPost);
            return py::make_tuple(status, connection);
        }, "url"_a, "connectionName"_a, "userName"_a, "password"_a, "flipCoordinates"_a, "preferHttpPost"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, CreateWFSConnectionWithoutDefaultElementTemplates));

    c2.def("IsConnectionActivated", [](ConnectionManager& self, ServerConnectionPtr connection)
        {
            return self.IsConnectionActivated(connection);
        }, "connection"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, IsConnectionActivated));

    c2.def("UpdateConnectionFeatureSelections", [](ConnectionManager& self, ServerConnectionPtr connection)
        {
            return self.UpdateConnectionFeatureSelections(connection);
        }, "connection"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, UpdateConnectionFeatureSelections));

    c2.def("DeleteConnection", [](ConnectionManager& self, ServerConnectionPtr connection)
        {
            return self.DeleteConnection(connection);
        }, "connection"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, DeleteConnection));

    c2.def("QueryConnectionsFeatureInstances", ([](ConnectionManager& self, QueryFeaturesAreaMode mode, bvector<ServerConnectionPtr>& connections)
        {
            int nQueried = 0;
            GeospatialContextStatus status = self.QueryConnectionsFeatureInstances(mode, connections, nQueried);
            return py::make_tuple(status, nQueried);
        }), "mode"_a, "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, QueryConnectionsFeatureInstances));

    c2.def("QueryConnectionsFeatureInstancesByView", ([](ConnectionManager& self, int viewIndex, bvector<ServerConnectionPtr>& connections)
        {
            int nQueried = 0;
            GeospatialContextStatus status = self.QueryConnectionsFeatureInstancesByView(viewIndex, connections, nQueried);
            return py::make_tuple(status, nQueried);
        }), "viewIndex"_a, "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, QueryConnectionsFeatureInstancesByView));

    c2.def("QueryConnectionsFeatureInstancesByNamedBoundary", ([](ConnectionManager& self, WStringCR boundaryName, bvector<ServerConnectionPtr>& connections)
        {
            int nQueried = 0;
            GeospatialContextStatus status = self.QueryConnectionsFeatureInstancesByNamedBoundary(boundaryName, connections, nQueried);
            return py::make_tuple(status, nQueried);
        }), "boundaryName"_a, "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, QueryConnectionsFeatureInstancesByNamedBoundary));

    c2.def_static("ClearAllFeatureInstances", ([](ClearFeaturesAreaMode mode)
        {
            int nCleared = 0;
            GeospatialContextStatus status = ConnectionManager::ClearAllFeatureInstances(mode, nCleared);
            return py::make_tuple(status, nCleared);
        }), "mode"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ClearAllFeatureInstances));

    c2.def_static("ClearAllFeatureInstancesByView", ([](int viewIndex)
        {
            int nCleared = 0;
            GeospatialContextStatus status = ConnectionManager::ClearAllFeatureInstancesByView(viewIndex, nCleared);
            return py::make_tuple(status, nCleared);
        }), "viewIndex"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ClearAllFeatureInstancesByView));

    c2.def_static("ClearAllFeatureInstancesByNamedBoundary", ([](WStringCR boundaryName)
        {
            int nCleared = 0;
            GeospatialContextStatus status = ConnectionManager::ClearAllFeatureInstancesByNamedBoundary(boundaryName, nCleared);
            return py::make_tuple(status, nCleared);
        }), "boundaryName"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ClearAllFeatureInstancesByNamedBoundary));

    c2.def("ClearConnectionsFeatureInstances", ([](ConnectionManager& self, ClearFeaturesAreaMode mode, bvector<ServerConnectionPtr>& connections)
        {
            int nCleared = 0;
            GeospatialContextStatus status = self.ClearConnectionsFeatureInstances(mode, connections, nCleared);
            return py::make_tuple(status, nCleared);
        }), "mode"_a, "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ClearConnectionsFeatureInstances));

    c2.def("ClearConnectionsFeatureInstancesByView", ([](ConnectionManager& self, int viewIndex, bvector<ServerConnectionPtr>& connections)
        {
            int nCleared = 0;
            GeospatialContextStatus status = self.ClearConnectionsFeatureInstancesByView(viewIndex, connections, nCleared);
            return py::make_tuple(status, nCleared);
        }), "viewIndex"_a, "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ClearConnectionsFeatureInstancesByView));

    c2.def("ClearConnectionsFeatureInstancesByNamedBoundary", ([](ConnectionManager& self, WStringCR boundaryName, bvector<ServerConnectionPtr>& connections)
        {
            int nCleared = 0;
            GeospatialContextStatus status = self.ClearConnectionsFeatureInstancesByNamedBoundary(boundaryName, connections, nCleared);
            return py::make_tuple(status, nCleared);
        }), "boundaryName"_a, "connections"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, ClearConnectionsFeatureInstancesByNamedBoundary));

    c2.def("GetLastError", ([](ConnectionManager& self, WStringR error)
        {
            return self.GetLastError(error);
        }), "error"_a, DOC(Bentley, MstnPlatform, GeospatialContext, ConnectionManager, GetLastError));
    }
