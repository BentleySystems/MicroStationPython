/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnecmanager.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnECManager.h>



static const char * __doc_Bentley_DgnPlatform_DgnECManager_DeleteRelationship =R"doc(Deletes an existing relationship between two DgnElementECInstance.

:param sourceDgnInstance:
    Source DgnElementECInstance.

:param targetDgnInstance:
    Target DgnElementECInstance.

:param relationshipClass:
    The class of the relationship that is to be deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_CreateRelationship =R"doc(Use this method to create a relationship between two
DgnElementECInstance. one or the other must use a DgnModelRef that
represents a DgnAttachment from one model to another. If you got the
instances through



:param relationshipEnabler:
    The relationship enablerA pointer to a WipRelationshipInstance
    that will contain any properties to be set in the relationship
    instance. that represents the attachment from A to B. See docs for
    DgnECManager::CreateInstanceOnElement.

:param createdRelationship:
    Smart pointer to the IDgnECRelationshipInstance that was created

:param relationshipEnabler:
    The relationship enabler

:param wipRelationship:
    Pointer to a WipRelationshipInstance that will contain any
    properties to be set in the relationship instance. This should be
    set to NULL if no properties are to be set. This should be set to
    NULL if no properties are to be set.

:param instanceA:
    DgnElementECInstance to be related to instanceB.

:param instanceB:
    DgnElementECInstance to be related to instanceA.

:param hostModelRef:
    Optional modelRef of element to receive relationship (may be
    different then either source or target host element). For future
    use.

:param hostElementRef:
    Optional element to recieve relationship (may be different then
    either source or target host element). For future use.

Remark:
    s If instanceA and instanceB do not reside in the same DgnModel,
    one or the other must use a DgnModelRef that represents a
    DgnAttachment from one model to another. If you got the instances
    through DgnECManger::FindElementInstances, they should be using
    the correct DgnModelRef. If you created the instances yourself,
    you must pass an optional DgnModelRef parameter when you create
    it. For example, you have two models A and B where A contains a
    reference to B. Model A contains instanceA. You want to create
    instanceB in model B and then create an ECRelationship between
    instanceA and instanceB. The relationship will have to make use of
    the attachment from A to B, so when you create instanceB it must
    use the DgnModelRef that represents the attachment from A to B.
    See DgnECInstanceEnabler::CreateInstanceOnElement.

See also:
    DgnECManager::CreateInstanceOnElement.

Returns (Tuple):
	retVal.

Returns (Tuple):
	createdRelationship , ECN::IECRelationshipInstanceP created. For
    example, you have two models A and B where A contains a reference
    to B. Model A contains instanceA. You want to create instanceB in
    model B and then create an ECRelationship between instanceA and
    instanceB..

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ObtainDgnECRelationshipEnabler =R"doc(Return pointer to the DgnECRelationshipEnabler for the specified
relationship class.

:param schemaName:
    The name of the schema containing the relationship class.

:param className:
    The name of the relationship class.

:param dgnFile:
    The dgnfile that the relationship is to be written to.

:returns:
    Returns pointer to DgnECRelationshipEnabler or NULL if enabler
    cannot be found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_CreateWipRelationshipByName =R"doc(Return a WIP relationship instance that can be used to set
relationship properties like Name and OrderId.

:param schemaName:
    The name of the schema containing the relationship class.

:param className:
    The name of the relationship class.

:param dgnFile:
    The dgnfile that the relationship is to be written to.

:returns:
    Returns a reference counted pointer to an
    StandaloneECRelationshipInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_IsPickListProviderExists =R"doc(Check if PickList provider already exists.

:param name:
    Name of provider

:returns:
    IPickListProviderR)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_GetPickListProviderDisplayLabel =R"doc(Get picklist provider configured for prooperty

:param property:
    ECProperty on which provider is configured.

:returns:
    IPickListProviderR)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_GetPickListProvderNames =R"doc(Get list of names of PickList providers)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ScheduleDeleteDgnECInstance =R"doc(Delete DgnECInstance from persistent ElementRef given the localId of
the instance.

:param element:
    The element that serves as a host to the IECInstance.

:param localId:
    LocalId that specifies the instance, this is typically the
    XAttributeId of the IECInstance

:param ignoreElementOwnership:
    If true, the element will not be deleted even if the instance owns
    the element

:param providerId:
    ProviderId that specifies the provider for the IECInstance

:returns:
    Retuns DELETEDGNECINSTANCE_Success if instance is deleted,
    DELETEDGNECINSTANCE_ProviderDoesNotSupportDelete if provider does
    not support delete.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_DeleteDgnECInstance =R"doc(Delete a DgnECInstance from an element.

:param instanceIdStringP:
    Defines the instance to delete. This must be a fully specified
    InstanceId

:param dependentModel:
    The modelref that is used to evaluate the Persistent Element Path
    stored in the instanceId string.

:param ignoreElementOwnership:
    If true, the host element will not be deleted even if it is owned
    by the deleted instance

:returns:
    Returns DELETEDGNECINSTANCE_Success if instance is successfully
    deleted.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_LocateSchemaInDgnFile =R"doc(Locate a schema in a design file. For normal files, looks only in the
given dgnFile. For packaged i-models, will also look in embedded files

:param schemaInfo:
    The SchemaInfo object that specifies the schema to locate.

:param matchType:
    The SchemaMatchType match type specification.

:param includeDeliveredSchemas:
    If true, and the schema is not persisted in the dgnFile, attempt
    to locate it among schemas delivered with DgnPlatform.

:param includeReferenceAttachments:
    If true, and the schema is not persisted in the dgnFile, attempt
    to locate it among schemas available in reference attachments.

:returns:
    A pointer to the located ECSchema or NULL if the schema cannot be
    found.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_IsSchemaContainedWithinFile =R"doc(Returns whether a schema is contained within the file itself (and not
within referenced attachments)

:param schemaInfo:
    The SchemaInfo object that specifies the schema to look for.

:param matchType:
    The SchemaMatchType match type specification.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_DiscoverSchemasForModel =R"doc(Populate a vector of available schemas for a model and its reference
attachments.

:param schemaInfoVector:
    A vector of SchemInfo

:param dgnModel:
    The root model. This method looks in design file containing the
    root model. If includeReferenceAttachments is true then SchemaInfo
    found in all attached reference files are also added to the infos
    vector.

:param scopeOption:
    Flag that determines how reference file attachments are processed.

:param persistence:
    ECSchemaPersistence criterion (e.g.
    ECSCHEMAPERSISTENCE_Stored|External|All). Including externaly-
    persisted ECSchemas can be significantly slower.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_DiscoverSchemas =R"doc(Populate a vector of available schemas for a design file.

:param infos:
    A vector of SchemInfo. Must be empty, initially

:param dgnFile:
    The design file to search for schemas.

:param persistence:
    ECSchemaPersistence criterion (e.g.
    ECSCHEMAPERSISTENCE_Stored|External|All). Including externally-
    persisted ECSchemas can be significantly slower.

:param hostType:
    Optionally filter schemas according to the host type of the
    provider that supplies them.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_FindRelationshipEntriesOnElement =R"doc(Find all relationships on a particular element. This will return only
the component information about the relationship, and not relationship
instances

:param rootElement:
    The element to search

:param entries:
    The list of relationships)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_FindRelatedInstances =R"doc(Finds instances related to *sourceInstance* that match
*classSpecifier*

:param sourceInstance:
    The instance at one end of the relationship.

:param relationshipClassSpecifier:
    Specifies what relationships to traverse.

:param createContext:
    Context specifying options for loading the related instances, e.g.
    properties to select.

:returns:
    An iterable for iterating over the related instances)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_FindInstanceOnElement =R"doc(Find a single DgnElementECInstance on a particular element. This is a
convenience method.

:param el:
    The element to search

:param ecClass:
    The class of the instance to find

:param polymorphic:
    If polymorphic is true then instances of class 'ecClass', or
    derived from 'ecClass' are returned.

:returns:
    The first instance matching ecClass on el.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_GetInstanceCounts =R"doc(Get a count of the number of instances for each class specified

:param scope:
    The scope to search for instances in

:param requestedClasses:
    A list of SchemaNameClassName pairs. This list will be used to
    determine which classes to get counts for. If the list is empty,
    counts will be returned for all instances in the scope

:param searchFlags:
    If the requestedClasses list is empty, it will use the
    ECQueryProcessFlags to determine which instances to search for

:returns:
    An iterable for iterating over the InstanceCountEntry results.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_FindInstances =R"doc(Find DgnElementECInstances in a DGN file using the supplied scope and
query.

:param scope:
    The scope specifies the set of elements to search for instances

:param query:
    Specifies what instances to return.


Returns  (Tuple, 0):
    An iterable for iterating over the InstanceCountEntry results.

Returns (Tuple, 1):
	count.  will contain the number of instances in the iterable.

Remark:
    s The DgnECManager does not find and " load " all of the ECInstances
    " up front " during the FindElementInstances call but rather it
    incrementally scans the files as the for-each loop iterates over
    the InstancesIterable returned by FindElementInstances. Thus you
    can iterate over thousands of them, while only loading one-at-a-
    time into memory)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ObtainInstanceEnabler =R"doc(Find the ECN::ECEnabler that is handling a given ECN::ECClass in the
given file

:param ecClass:
    The ECN::ECClass for which you want an ECN::ECEnabler

:param file:
    The file in which the ECN::ECEnabler should be valid)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ObtainInstanceEnablerByName =R"doc(Find the ECN::ECEnabler that is handling a given a schema and class
name in the given file

:param schemaName:
    The name of the schema containing the class.

:param className:
    The name of an ECClass defined in the schema specified by
    schemaName.

:param dgnFile:
    The file in which the ECN::ECEnabler should be valid)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_GetProviderById =R"doc(Get a pointer to the IDgnECProvider that read and write IECInstances
to a design file.

:param providerId:
    The Id of the provider. This is typically set to
    DgnECProviderId_ECXAttributes which is the value 0x56FF.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_CreateECInstanceReadContext =R"doc(Get an ECInstanceReadContextPtr suitable for use with
IECInstance::ReadFromXmlString or similar methods that will read
ECInstances that are compatible for persistence in the given dgnFile

:param schema:
    The ECSchema of ECInstances expected to be read.

:param dgnFile:
    The dgnFile into which the ECInstances will be persisted. It will
    be used to find StandaloneInstanceEnablers for the instances)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ReadSchemaFromXmlFile =R"doc(Load an ECSchema managed by the DgnECManager to be used with
ImportSchema or returned by Bentley::ECN::IECSchemaLocater



:param ecSchemaXmlFilename:
    The full file path/name of the ECSchemaXML file to read

:param dgnFile:
    ECSchema reading will look here when locating referenced
    ECSchemas... May be NULL.

:param searchPaths:
    Additional paths to search for referenced ECSchemas. Searched
    after the dgnFile, but before registered ExternalSchemaLocaters

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	schemaHolder. maintains a reference to the ECSchema 

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ReadSchemaFromXmlString =R"doc(Load an ECSchema managed by the DgnECManager to be used with
ImportSchema or returned by Bentley::ECN::IECSchemaLocater

:param schemaAsXml:
    A string holding ECSchemaXML to be parsed

:param dgnFile:
    ECSchema reading will look here when locating referenced
    ECSchemas... May be NULL.

:param searchPaths:
    Additional paths to search for referenced ECSchemas. Searched
    after the dgnFile, but before registered ExternalSchemaLocaters.
    
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	schema. maintains a reference to the ECSchema

)doc";       

static const char * __doc_Bentley_DgnPlatform_DgnECManager_CreateSchema =R"doc(Create an ECSchema managed by the DgnECManager to be used with
ImportSchema or returned by Bentley::ECN::IECSchemaLocater

Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	schemaHolder.

)doc";   

static const char * __doc_Bentley_DgnPlatform_DgnECManager_RemoveECInstancesFromModel =R"doc(Remove ECInstances for the specified DGN model

:param model:
    The model from which to remove instances

:param schemaName:
    The schema of the instances to remove (or NULL for any)

:param className:
    The class of the instances to remove (or NULL for any). Ignored if
    schemaName is not supplied.

:param firstIndex:
    The index of the first instance to remove as counted by those
    instance matching schemaName/className criteria

:param count:
    Including firstIndex, the total number of instances to remove (-1
    for all)

:returns:
    The number of instances removed)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_ReadECInstancesFromModel =R"doc(Remove Read ECInstances for the specified DGN model

:param ecInstances:
    Vector of instances that were read

:param dgnModel:
    The model from which to remove instances

:returns:
    SUCCESS if ecInstance were associated with the specified model)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_AppendECInstancesToModel =R"doc(Append ECInstances to the specified DGN model

:param ecInstances:
    Vector of instances that are to be appended.

:param dgnModel:
    The model which is to receive instances

:returns:
    The number of instances appended

Remark:
    s The caller is responsible for setting a unique InstanceId for
    each of the input instances.

Remark:
    s This method will never replace instances as
    ECXAttributes::AppendInstanceToModelHeaderInCache did in certain
    situations.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_RegisterDgnECChangeListener =R"doc(Register Listener for listening DgnECInstance and relationship changes)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_GetManager =R"doc(Get the singleton DgnECManager)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECManager_FindRelationships =R"doc(Finds relationships defined for sourceInstance according to
relationshipClassSpecifier

:param sourceInstance:
    The instance for which to find relationships.

:param relationshipClassSpecifier:
    Specifies what relationships to traverse.

:param relationshipPropertySpecifier:
    Properties to select for the relationship (optional = NULL).)doc";


/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnECManager(py::module_& m)
    {
    //===================================================================================
    // enum ReferencedModelScopeOption
    py::enum_< ReferencedModelScopeOption>(m, "ReferencedModelScopeOption", py::arithmetic())
        .value("eREFERENCED_MODEL_SCOPE_All", REFERENCED_MODEL_SCOPE_All)
        .value("eREFERENCED_MODEL_SCOPE_DirectOnly", REFERENCED_MODEL_SCOPE_DirectOnly)
        .value("eREFERENCED_MODEL_SCOPE_None", REFERENCED_MODEL_SCOPE_None)
        .export_values();

    //===================================================================================
    // struct DgnECManager :public DgnHost::IHostObject
    py::class_< DgnECManager, DgnHost::IHostObject> c4(m, "DgnECManager");


    c4.def("FindRelationships", &DgnECManager::FindRelationships, "sourceInstance"_a, "relationshipClassSpecifier"_a, "createContext"_a, DOC(Bentley, DgnPlatform, DgnECManager, FindRelationships));
    c4.def("GetSupportedRelationshipInfos", &DgnECManager::GetSupportedRelationshipInfos, "instance"_a, "infos"_a);

    // N.B if the class is not defined with  std::unique_ptr<DgnECManager, py::nodelete>.. the value policy needs to be py::return_value_policy::reference the return type must match

    c4.def_static("GetManager", &DgnECManager::GetManager, py::return_value_policy::reference, DOC(Bentley, DgnPlatform, DgnECManager, GetManager));

    c4.def("RegisterDgnECChangeListener", &DgnECManager::RegisterDgnECChangeListener, "listener"_a, py::keep_alive<1, 2>(), DOC(Bentley, DgnPlatform, DgnECManager, RegisterDgnECChangeListener));    
    c4.def("UnregisterDgnECChangeListener", &DgnECManager::UnregisterDgnECChangeListener, "listener"_a);

    c4.def("AppendECInstancesToModel", &DgnECManager::AppendECInstancesToModel, "ecInstances"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, DgnECManager, AppendECInstancesToModel));
    c4.def("ReadECInstancesFromModel", &DgnECManager::ReadECInstancesFromModel, "ecInstances"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, DgnECManager, ReadECInstancesFromModel));
    
    c4.def("RemoveECInstancesFromModel", 
           py::overload_cast<DgnModelR, WCharCP, WCharCP, Int32, Int32>(&DgnECManager::RemoveECInstancesFromModel), 
           "model"_a, "schemaName"_a, "className"_a, "firstIndex"_a, "count"_a, DOC(Bentley, DgnPlatform, DgnECManager, RemoveECInstancesFromModel));

    c4.def("RemoveECInstancesFromModel",
           py::overload_cast<DgnModelR, bvector<ECN::IECInstancePtr>&>(&DgnECManager::RemoveECInstancesFromModel),
           "model"_a, "instancesToRemove"_a, DOC(Bentley, DgnPlatform, DgnECManager, RemoveECInstancesFromModel));

    c4.def("RemoveECInstancesFromModel", [](DgnECManagerR self, DgnModelR model, py::list& instancesToRemove){
        bvector<ECN::IECInstancePtr> cppInstancesToRemove;
        for (const auto& item : instancesToRemove) {
            cppInstancesToRemove.push_back(item.cast<ECN::IECInstancePtr>());
        }
        return self.RemoveECInstancesFromModel(model, cppInstancesToRemove);
    }, "model"_a, "instancesToRemove"_a, DOC(Bentley, DgnPlatform, DgnECManager, RemoveECInstancesFromModel));
 
    c4.def("ImportSchema",
           py::overload_cast<ECN::ECSchemaR, DgnFileR, bool, bool>(&DgnECManager::ImportSchema),
           "schema"_a, "dgnFile"_a, "isExternalSchema"_a = false, "importReferencedSchemas"_a = true);

    c4.def("UpdateSchema",
           py::overload_cast<ECN::ECSchemaR, DgnFileR, bool>(&DgnECManager::UpdateSchema),
           "schema"_a, "dgnFile"_a, "isExternalSchema"_a = false);
           
    c4.def("CreateSchema", [] (DgnECManager& self, WCharCP schemaName, UInt32 majorVersion, UInt32 minorVersion, DgnFileP file)
           {
           ECN::ECSchemaPtr schemaHolder;
           auto retVal = self.CreateSchema(schemaHolder, schemaName, majorVersion, minorVersion, file);
           return py::make_tuple(retVal, schemaHolder);
           }, "schemaName"_a, "majorVersion"_a, "minorVersion"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnECManager, CreateSchema));

    c4.def("ReadSchemaFromXmlString", [] (DgnECManager& self, WCharCP schemaAsXml, DgnFileP dgnFile, bvector<WString>* searchPaths)
           {
           ECN::ECSchemaPtr schema;
           auto retVal = self.ReadSchemaFromXmlString(schema, schemaAsXml, dgnFile, searchPaths);
           return py::make_tuple(retVal, schema);
           }, "schemaAsXml"_a, "dgnFile"_a, "searchPaths"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECManager, ReadSchemaFromXmlString));

    c4.def("ReadSchemaFromXmlString", [] (DgnECManager& self, WCharCP schemaAsXml, DgnFileP dgnFile, py::list searchPaths)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(searchPaths, cppSearchPaths, bvector<WString>, WString);
           ECN::ECSchemaPtr schema;
           auto retVal = self.ReadSchemaFromXmlString(schema, schemaAsXml, dgnFile, &cppSearchPaths);
           return py::make_tuple(retVal, schema);
           }, "schemaAsXml"_a, "dgnFile"_a, "searchPaths"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECManager, ReadSchemaFromXmlString));

    c4.def("ReadSchemaFromXmlFile", [] (DgnECManager& self, WCharCP ecSchemaXmlFilename, DgnFileP dgnFile, bvector<WString>* searchPaths)
           {
           ECN::ECSchemaPtr schemaHolder;
           auto retVal = self.ReadSchemaFromXmlFile(schemaHolder, ecSchemaXmlFilename, dgnFile, searchPaths);
           return py::make_tuple(retVal, schemaHolder);
           }, "ecSchemaXmlFilename"_a, "dgnFile"_a, "searchPaths"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECManager, ReadSchemaFromXmlFile));

    c4.def("ReadSchemaFromXmlFile", [] (DgnECManager& self, WCharCP ecSchemaXmlFilename, DgnFileP dgnFile, py::list searchPaths)
           {
           CONVERT_PYLIST_TO_NEW_CPPARRAY(searchPaths, cppSearchPaths, bvector<WString>, WString);
           ECN::ECSchemaPtr schemaHolder;
           auto retVal = self.ReadSchemaFromXmlFile(schemaHolder, ecSchemaXmlFilename, dgnFile, &cppSearchPaths);
           return py::make_tuple(retVal, schemaHolder);
           }, "ecSchemaXmlFilename"_a, "dgnFile"_a, "searchPaths"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECManager, ReadSchemaFromXmlFile));

    c4.def("CreateECInstanceReadContext", &DgnECManager::CreateECInstanceReadContext, "schema"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnECManager, CreateECInstanceReadContext));
    c4.def("GetProviderById", &DgnECManager::GetProviderById, "providerId"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECManager, GetProviderById));

    c4.def("ObtainInstanceEnablerByName",
           py::overload_cast<WCharCP, WCharCP, DgnFileR>(&DgnECManager::ObtainInstanceEnablerByName),
           "schemaName"_a, "className"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnECManager, ObtainInstanceEnablerByName));

    c4.def("ObtainInstanceEnabler", &DgnECManager::ObtainInstanceEnabler, "ecClass"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECManager, ObtainInstanceEnabler));
    c4.def("FindInstances", [] (DgnECManagerR self, FindInstancesScopeR scope, ECQueryCR query)
           {
           UInt32 count = 0;
           DgnECInstanceIterable it = self.FindInstances(scope, query, &count);
           return py::make_tuple(it, count);
           }, "scope"_a, "query"_a, DOC(Bentley, DgnPlatform, DgnECManager, FindInstances));

    c4.def_static("GetInstanceCounts", &DgnECManager::GetInstanceCounts, "scope"_a, "requestedClasses"_a, "searchFlags"_a, DOC(Bentley, DgnPlatform, DgnECManager, GetInstanceCounts));
    c4.def("FindInstanceOnElement", &DgnECManager::FindInstanceOnElement, "el"_a, "ecClass"_a, "polymorphic"_a = false, DOC(Bentley, DgnPlatform, DgnECManager, FindInstanceOnElement));
    c4.def("FindRelatedInstances", &DgnECManager::FindRelatedInstances, "sourceInstance"_a, "relationshipClassSpecifier"_a, "createContext"_a, DOC(Bentley, DgnPlatform, DgnECManager, FindRelatedInstances));
    c4.def("FindRelationshipEntriesOnElement", &DgnECManager::FindRelationshipEntriesOnElement, "rootElement"_a, "entries"_a, DOC(Bentley, DgnPlatform, DgnECManager, FindRelationshipEntriesOnElement));
    c4.def("DiscoverSchemas", &DgnECManager::DiscoverSchemas, "infos"_a, "dgnFile"_a, "persistence"_a, "hostType"_a, DOC(Bentley, DgnPlatform, DgnECManager, DiscoverSchemas));
    c4.def("DiscoverSchemasForModel", &DgnECManager::DiscoverSchemasForModel, "schemaInfoVector"_a, "dgnModel"_a, "persistence"_a, "scopeOption"_a = REFERENCED_MODEL_SCOPE_None, DOC(Bentley, DgnPlatform, DgnECManager, DiscoverSchemasForModel));
    c4.def("IsSchemaContainedWithinFile", &DgnECManager::IsSchemaContainedWithinFile, "schemaInfo"_a, "matchType"_a, DOC(Bentley, DgnPlatform, DgnECManager, IsSchemaContainedWithinFile));
    c4.def("LocateSchemaInDgnFile", &DgnECManager::LocateSchemaInDgnFile, "schemaInfo"_a, "matchType"_a, "includeDeliveredSchemas"_a = true, "includeReferenceAttachments"_a = false, DOC(Bentley, DgnPlatform, DgnECManager, LocateSchemaInDgnFile));

    c4.def("DeleteDgnECInstance",
           py::overload_cast<WCharCP, DgnModelRefP, bool>(&DgnECManager::DeleteDgnECInstance, py::const_),
           "instanceId"_a, "dependentModel"_a, "ignoreElementOwnership"_a, DOC(Bentley, DgnPlatform, DgnECManager, DeleteDgnECInstance));

    c4.def("DeleteDgnECInstance",
           py::overload_cast<ElementRefP, UInt32, bool, UInt16>(&DgnECManager::DeleteDgnECInstance, py::const_),
           "elementRef"_a, "localId"_a, "ignoreElementOwnership"_a, "providerId"_a = DgnECProviderId_ECXAttributes, DOC(Bentley, DgnPlatform, DgnECManager, DeleteDgnECInstance));

    c4.def("ScheduleDeleteDgnECInstance", &DgnECManager::ScheduleDeleteDgnECInstance, "element"_a, "localId"_a, "ignoreElementOwnership"_a = false, "providerId"_a = DgnECProviderId_ECXAttributes, DOC(Bentley, DgnPlatform, DgnECManager, ScheduleDeleteDgnECInstance));

    c4.def_property_readonly("PickListProvderNames", &DgnECManager::GetPickListProvderNames);
    c4.def("GetPickListProvderNames", &DgnECManager::GetPickListProvderNames, DOC(Bentley, DgnPlatform, DgnECManager, GetPickListProvderNames));

    c4.def("GetPickListProviderDisplayLabel", &DgnECManager::GetPickListProviderDisplayLabel, "providerName"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECManager, GetPickListProviderDisplayLabel));
    c4.def("IsPickListProviderExists", &DgnECManager::IsPickListProviderExists, "providerName"_a, DOC(Bentley, DgnPlatform, DgnECManager, IsPickListProviderExists));
    c4.def("CreateWipRelationshipByName", &DgnECManager::CreateWipRelationshipByName, "schemaName"_a, "className"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnECManager, CreateWipRelationshipByName));
    c4.def("ObtainDgnECRelationshipEnabler", &DgnECManager::ObtainDgnECRelationshipEnabler, "schemaName"_a, "className"_a, "dgnFile"_a, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECManager, ObtainDgnECRelationshipEnabler));

    c4.def("CreateRelationship", [](DgnECManager const& self, DgnECRelationshipEnablerCR relationshipEnabler, ECN::StandaloneECRelationshipInstanceR wipRelationship,
                                    DgnElementECInstanceCR instanceA, DgnElementECInstanceCR instanceB, DgnModelRefP hostModelRef, ElementRefP hostElementRef)
           {
           IDgnECRelationshipInstancePtr createdRelationship;
           auto retVal = self.CreateRelationship(&createdRelationship, relationshipEnabler, wipRelationship, instanceA, instanceB, hostModelRef, hostElementRef);
           return py::make_tuple(retVal, createdRelationship);
           }, "relationshipEnabler"_a, "wipRelationship"_a, "instanceA"_a, "instanceB"_a, "hostModelRef"_a = nullptr, "hostElementRef"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECManager, CreateRelationship));

    c4.def("CreateRelationship", [] (DgnECManager const& self, DgnECRelationshipEnablerCR relationshipEnabler,
                                     DgnElementECInstanceCR instanceA, DgnElementECInstanceCR instanceB, DgnModelRefP hostModelRef, ElementRefP hostElementRef)
           {
           IDgnECRelationshipInstancePtr createdRelationship;
           auto retVal = self.CreateRelationship(&createdRelationship, relationshipEnabler, instanceA, instanceB, hostModelRef, hostElementRef);
           return py::make_tuple(retVal, createdRelationship);
           }, "relationshipEnabler"_a, "instanceA"_a, "instanceB"_a, "hostModelRef"_a = nullptr, "hostElementRef"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECManager, CreateRelationship));

    c4.def("DeleteRelationship", &DgnECManager::DeleteRelationship, "sourceDgnInstance"_a, "targetDgnInstance"_a, "relationshipClass"_a, DOC(Bentley, DgnPlatform, DgnECManager, DeleteRelationship));

    }