/*--------------------------------------------------------------------------------------+
|
|     $Source: MSPython\MSPythonWrapper\PyDgnPlatform\source\dgnecinstance.cpp $
|
|  $Copyright: (c) 2023 Bentley Systems, Incorporated. All rights reserved. $
|
+--------------------------------------------------------------------------------------*/
#include "MSPythonPCH.h"
#include <DgnPlatform/DgnECInstance.h>



static const char * __doc_Bentley_DgnPlatform_DgnECInstanceIterable_IsNull =R"doc(Utility method to check whether the collection is initialized)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceIterable_empty =R"doc(Utility method to check whether the current collection has any
instances)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECRelationshipInstance_GetRelatedInstance =R"doc(Gets the associated instance data)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECRelationshipInstance_GetTargetAssociatedString =R"doc(Gets the source property string

Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	propString.

)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECRelationshipInstance_GetSourceAssociatedString =R"doc(Gets the source property string

Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	propString.

)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECRelationshipInstance_GetTargetOrderId =R"doc(Gets the target order id


Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	targetOrderId.

)doc";

static const char * __doc_Bentley_DgnPlatform_IDgnECRelationshipInstance_GetSourceOrderId =R"doc(Gets the source order id

Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	sourceOrderId.

)doc";
static const char * __doc_Bentley_DgnPlatform_IDgnECRelationshipInstance_Delete =R"doc(Delete the XAttributes that hold the relationship data.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECRelationshipEnabler_SupportsRelationshipProperties =R"doc(Returns true if the enabler supports relationship properties.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECRelationshipEnabler_GetSharedStandaloneWipInstance =R"doc(Get a Shared WIP instance that can be passed CreateRelationship to
specify properties to be set in the relationship instance.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECRelationshipEnabler_CreateRelationship =R"doc(Method to create a relationship between two DgnElementECInstance.

Parameter ``wipRelationship``:
    A reference to a StandaloneInstance that will contain properties
    of the relationship instance.

Parameter ``instanceA``:
    DgnElementECInstance to be related to instanceB.

Parameter ``instanceB``:
    DgnElementECInstance to be related to instanceA.

Parameter ``hostModelRef``:
    Optional modelRef of element to receive relationship (may be
    different then either source or target host element). For future
    use.

Parameter ``hostElementRef``:
    Optional element to receive relationship (may be different then
    either source or target host element). For future use.

Returns (Tuple, 0):
	retVal.

Returns (Tuple,1):
	createdRelationship.



)doc";
static const char * __doc_Bentley_DgnPlatform_DgnElementECInstance_GetLocalId =R"doc(Get LocalId of the instance. For XAttribute-based instances this is an
XAttribute ID.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnElementECInstance_GetElementRef =R"doc(Get ElementRefP of element containing the instance, if the instance is
stored on a persistent element.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnElementECInstance_GetModelRef =R"doc(Get root DgnModelRef from which this instance was obtained. This may
differ from the DgnModel containing the instance's element (see
GetDgnModelP()).)doc";

static const char * __doc_Bentley_DgnPlatform_DgnElementECInstance_GetElementHandle =R"doc(Get the element handle where this DgnElementInstance is stored)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_SetReadOnly =R"doc(Set Instance ReadOnly setting. May be ignored if implementation does
not support setting read-only flag.

Parameter ``isReadOnly``:
    Read-only flag)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_GetAsElementInstance =R"doc(To avoid expensive dynamic casting use this method to see if the
instance is an instance associated with a specific Element as opposed
to a Model or File.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_SetValueAsString =R"doc(Set the value of a property as a string. An IDgnECTypeAdapter is used
to convert string to value.

Parameter ``accessString``:
    The name of the property to set the value of

Parameter ``strVal``:
    If successful, will contain the value of the property

Parameter ``useArrayIndex``:
    Set this to true if retrieving an entry in an array. If this is
    false arrayIndex is ignored;

Parameter ``arrayIndex``:
    The array index, if this is an ArrayProperty

Returns:
    ECOBJECTS_STATUS_Success if successful, otherwise an error code
    indicating the failure)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_GetValueAsString =R"doc(Get the value of a property as a string. An IDgnECTypeAdapter is used
to convert value to string.

Parameter ``strVal``:
    If successful, will contain the value of the property

Parameter ``accessString``:
    The name of the property to set the value of

Parameter ``useArrayIndex``:
    Set this to true if retrieving an entry in an array. If this is
    false arrayIndex is ignored;

Parameter ``arrayIndex``:
    The array index, if this is an ArrayProperty

Returns:
    ECOBJECTS_STATUS_Success if successful, otherwise an error code
    indicating the failure)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_GetDgnECInstanceEnabler =R"doc(Get the enabler used to create the instance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_ScheduleDelete =R"doc(If supported, schedule the delete of the instance from the element.
The instance is removed when the element is written.

Parameter ``element``:
    Element that serves as a host for the instance.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_DeleteAndIgnoreOwnership =R"doc(If supported, delete the instance from the design file but do not
delete any Host Element.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_Delete =R"doc(If supported, delete the instance from the design file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_ScheduleWriteChanges =R"doc(Schedule to write any in-memory modifications when its associated
element is written.

Parameter ``eeh``:
    Element that will host the instance.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_WriteChanges =R"doc(Write any in-memory modifications made to the instance to the design
file.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_GetInstanceHost =R"doc(Returns the object which hosts this ECInstance. The returned
DgnECInstanceHost does not own the host object - it remains valid only
so long as this DgnECInstance does.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstance_GetHostType =R"doc(Get the hosttype in which this instance is persisted.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_IsEnablerValidForDgnFile =R"doc(Returns true if the enabler supports writing instances to DgnFile.

Parameter ``dgnFile``:
    The destination DGN file for the instance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_CreateInstanceAsElement =R"doc(Creates an DgnElementECInstance as a new element. You must call
SupportsCreateInstanceAsElement to determine if it is safe to call
this on a given DgnECInstanceEnabler.


Parameter ``wipInstance``:
    A ECN::StandaloneECInstance that was probably obtained from
    #GetSharedWipInstance It should have been intialized with all of
    the values to allow efficient one-shot creation of the new
    persistent DgnElementECInstance.

Parameter ``modelRef``:
    The modelRef to be used by the returned DgnElementECInstance.
    Typically you should pass *elementRef.GetDgnModelP(). The
    exception is if you will be using the returned
    DgnElementECInstance to create an ECRelationship to another
    DgnElementECInstance that does not reside in the same DgnModel. In
    that case, you must pass the DgnModelRef of the particular
    attachment that will be used by that ECRelationship. See docs for
    DgnECManager::CreateRelationship.

Parameter ``instanceOwnsElement``:
    If true, when the instance is deleted the element will be deleted
    as well.

See also:
    GetSharedWipInstance();
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	dgnecInstance.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_CreateInstanceOnElement =R"doc(Creates an DgnElementECInstance on an persistent element. The instance
will be written to the element immediately. You must call
SupportsCreateInstanceOnElement to determine if it is safe to call
this on a given DgnECInstanceEnabler.

Parameter ``wipInstance``:
    A ECN::StandaloneECInstance that was probably obtained from
    #GetSharedWipInstance. It should have been intialized with all of
    the values

Parameter ``eh``:
    ElementHandle containing the ElementRef and DgnModelRef to be used
    by the returned DgnElementECInstance. The ElementHandle must
    contain a valid ElementRef. Typically the DgnModelRef should come
    from the ElementRef. The exception is if you will be using the
    returned DgnElementECInstance to create an ECRelationship to
    another DgnElementECInstance that does not reside in the same
    DgnModel. In that case, you must pass the DgnModelRef of the
    particular attachment that will be used by that ECRelationship.
    See docs for DgnECManager::CreateRelationship.

Parameter ``instanceOwnsElement``:
    If true, when the instance is deleted the element will be deleted
    as well.

See also:
    GetSharedWipInstance();
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	dgnecInstance.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_ScheduleReplaceInstanceOnElement =R"doc(Schedules the replacement of an existing instance associated with an
element that is identified by the localid. The element is identified
by an EditElementHandle.


Parameter ``wipInstance``:
    A ECN::StandaloneECInstance that was probably a " shared " instance
    with its memory shared with a managed ECDInstance.

Parameter ``modelRef``:
    The modelRef to be used by the returned DgnECInstance. Typically
    you should pass *elementRef.GetDgnModelP(). The exception is if
    you will be using the returned DgnECInstance to create an
    ECRelationship to another DgnECInstance that does not reside in
    the same DgnModel. In that case, you must pass the DgnModelRef of
    the particular attachment that will be used by that
    ECRelationship. See docs for DgnECManager::CreateRelationship.

Parameter ``eh``:
    The element on which to persist the newly-created DgnECInstance

Parameter ``localId``:
    Identifies the existing instance to replace. Typically the
    xattribute id.

Returns (Tuple,0):
	retVal.

Returns (Tuple,1):
	dgnecInstance.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_ScheduleInstanceOnElement =R"doc(Schedules the creation an DgnElementECInstance on an existing element.
The instance will be persisted when the EditElementHandle is written.
You must call SupportsCreateInstanceOnElement to determine if it is
safe to call this on a given DgnECInstanceEnabler.


Parameter ``wipInstance``:
    An ECN::StandaloneECInstance that was probably obtained from
    #GetSharedWipInstance It should have been intialized with all of
    the values

Parameter ``eh``:
    The element on which to schedule the newly-created
    DgnElementECInstance

Parameter ``instanceOwnsElement``:
    If true, when the instance is deleted the element will be deleted
    as well.

See also:
    GetSharedWipInstance();
Returns (Tuple, 0):
	retVal.

Returns (Tuple, 1):
	dgnecInstance.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_GetStandaloneECInstanceEnabler =R"doc(Used to create StandaloneECInstances that use the same enabler as the
" WIP " ECInstances (and are thus may be used with
CreateInstanceOnElement and similar methods))doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_CreateInstanceOnHost =R"doc(Create an instance which is stored on the specified host.

Parameter ``wipInstance``:
    A standalone instance from to get properties of the new instance.

Parameter ``host``:
    The host on which to create the ECInstance

Parameter ``intendedLocalId``:
    If INVALID_XATTR_ID, then use the next available Id, Otherwise use
    the provided ID and error if not available.

Parameter ``createContext``:
    Context with which to create the ECInstance

Parameter ``instanceOwnsHost``:
    (if supported) indicates that if the ECInstance is later deleted,
    the host on which it resides will be deleted as well.
Returns (Tuple, 0):
	retVal.

Returns (Tuple,1):
	dgnecInstance.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_CreateInstanceOnLinkNode =R"doc(Create an instance which is stored on a DgnLinkTreeNode (ex:Folders
and Links in a Link Set or Sheet Index)

Parameter ``wipInstance``:
    A standalone instance from to get properties of the new instance.

Parameter ``linknode``:
    The linknode on which to store

Returns (Tuple, 0):
	retVal.

Returns (Tuple,1):
	dgnecInstance.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_CreateInstanceOnModel =R"doc(Create an instance which is stored on the model or attachment.


Parameter ``wipInstance``:
    A standalone instance from to get properties of the new instance.

Parameter ``model``:
    The dgnmodel on which to store
Returns (Tuple, 0):
	retVal.

Returns (Tuple,1):
	dgnecInstance.

)doc";
static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_CreateInstanceOnFile =R"doc(Create an instance which is stored on the DgnFile.


Parameter ``wipInstance``:
    A template instance from which to get properties of the new
    instance.

Parameter ``dgnfile``:
    The DgnFile on which to store the instance
    
Returns (Tuple, 0):
	retVal.

Returns (Tuple,1):
	dgnecInstance.

)doc";    

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_SupportsCreateInstanceAsElement =R"doc(Return true if the enabler supports creating an instance on a new
element.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_SupportsCreateInstanceOnElement =R"doc(Return true if the enabler supports creating instances on a Dgn
element.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_SupportsCreateInstanceOnHost =R"doc(Check whether this enabler supports creating instances which are
stored on objects of the specified host type)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_GetPrivateWipInstance =R"doc(Gets a private StandaloneECInstance for use with this
DgnECInstanceEnabler's CreateInstance* methods.

Remark:
    s The instance is setup (memory allocated) for efficient usage
    with those methods. The property values in the returned instance
    will all be null. It is private and you control its lifetime, so
    you can have many of them " in play " at once. It is typcially used
    in scenarios when populating struct array values on a shared wip
    instance, before actually creating the primary instance on an
    element. Each such struct element in the array value must exist in
    memory independently and therefore can not use a shared wip
    instance. In cases where you are creating primary ECInstances (not
    struct values) you normally want to use GetSharedWipInstance for
    better performance.

)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceEnabler_GetSharedWipInstance =R"doc(Gets a StandaloneECInstance to be used as a template when creating new
persistent ECInstances with one of this DgnECInstanceEnabler's
CreateInstance* methods. The instance is setup (memory allocated) for
efficient usage with those methods. This technique avoids initially
writing an empty ECInstance and then making subsequent modifications
(avoiding overhead in undo buffer, design history, etc.) The property
values in the returned instance will initially all be null. It is
shared to avoid repeated mallocs and frees when creating many
DgnElementECInstances, forcing you to initialize and create
DgnElementECInstances one-at-a-time. You should never delete/free the
WIP IECInstance. It's values will be cleared the next time it is
requested.


See also:
    GetPrivateWipInstance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateContext_SetSelectedProperties =R"doc(Returns the set of properties which will be selected in the
DgnECInstance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateContext_GetSelectedProperties =R"doc(Returns the set of properties which will be selected in the
DgnECInstance)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_SetCreateReadOnly =R"doc(Sets whether create readonly ECInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_CreateReadOnly =R"doc(Returns whether create readonly ECInstance.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_SetExposesHistorical =R"doc(Sets whether the " historical " properties of an object are returned.
Chiefly used for Design History.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_ExposesHistorical =R"doc(Returns whether the " historical " properties of an object are returned.
Chiefly used for Design History.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_SetExposesHidden =R"doc(Sets whether " hidden " ECInstances are permitted. " Hidden " ECInstances
include those attached to hidden models or elements, or otherwise
explicitly flagged as " hidden ".)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_ExposesHidden =R"doc(Returns whether " hidden " ECInstances are permitted. " Hidden "
ECInstances include those attached to hidden models or elements, or
otherwise explicitly flagged as " hidden ".)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_SetQualifiedPepBasedId =R"doc(Sets whether an element-hosted instance's ID will include a qualified
PersistentElementPath identifier)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_HasQualifiedPepBasedId =R"doc(Returns whether an element-hosted instance's ID will include a
qualified PersistentElementPath identifier)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_SetPathBasedId =R"doc(Sets whether the instance's ID will include a unique identifier for
the containing DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_DgnECInstanceCreateOptions_HasPathBasedId =R"doc(Returns whether the instance's ID will include a unique identifier for
the containing DgnFile.)doc";

static const char * __doc_Bentley_DgnPlatform_SelectedProperties_Duplicate =R"doc(Create a deep copy)doc";

static const char * __doc_Bentley_DgnPlatform_SelectedProperties_AddPropertyNameToSelect =R"doc(Adds a property name to select/populate in the DgnECInstance.
Currently only ECXA Instances support partial instance loading.

Parameter ``accessString``:
    Property name to select)doc";

/*---------------------------------------------------------------------------------**//**
* @bsimethod                                                                       2/2023
+---------------+---------------+---------------+---------------+---------------+------*/
void def_DgnECInstance(py::module_& m)
    {
    //===================================================================================
    // enum DgnECInstanceStatus
    py::enum_< DgnECInstanceStatus>(m, "DgnECInstanceStatus", py::arithmetic())
        .value("eDGNECINSTANCESTATUS_Success", DGNECINSTANCESTATUS_Success)
        .value("eDGNECINSTANCESTATUS_InstanceIsStale", DGNECINSTANCESTATUS_InstanceIsStale)
        .value("eDGNECINSTANCESTATUS_InstanceIsDeletedOrUndone", DGNECINSTANCESTATUS_InstanceIsDeletedOrUndone)
        .value("eDGNECINSTANCESTATUS_InvalidElementRef", DGNECINSTANCESTATUS_InvalidElementRef)
        .value("eDGNECINSTANCESTATUS_InstanceIsAlreadyAsleep", DGNECINSTANCESTATUS_InstanceIsAlreadyAsleep)
        .value("eDGNECINSTANCESTATUS_IncompatibleWipInstance", DGNECINSTANCESTATUS_IncompatibleWipInstance)
        .value("eDGNECINSTANCESTATUS_UnableToAddInstance", DGNECINSTANCESTATUS_UnableToAddInstance)
        .value("eDGNECINSTANCESTATUS_NoInstanceFound", DGNECINSTANCESTATUS_NoInstanceFound)
        .value("eDGNECINSTANCESTATUS_InvalidInstance", DGNECINSTANCESTATUS_InvalidInstance)
        .value("eDGNECINSTANCESTATUS_UnableToUpdateInstance", DGNECINSTANCESTATUS_UnableToUpdateInstance)
        .value("eDGNECINSTANCESTATUS_XAttributeHasBeenRemoved", DGNECINSTANCESTATUS_XAttributeHasBeenRemoved)
        .value("eDGNECINSTANCESTATUS_ClassLayoutNotStored", DGNECINSTANCESTATUS_ClassLayoutNotStored)
        .value("eDGNECINSTANCESTATUS_RelationshipInstanceNotCreated", DGNECINSTANCESTATUS_RelationshipInstanceNotCreated)
        .value("eDGNECINSTANCESTATUS_EnablerNotValidForFile", DGNECINSTANCESTATUS_EnablerNotValidForFile)
        .value("eDGNECINSTANCESTATUS_DuplicateRelationshipFound", DGNECINSTANCESTATUS_DuplicateRelationshipFound)
        .value("eDGNECINSTANCESTATUS_RequiresSingleEndedRelationshipClass", DGNECINSTANCESTATUS_RequiresSingleEndedRelationshipClass)
        .value("eDGNECINSTANCESTATUS_PropertyNotFound", DGNECINSTANCESTATUS_PropertyNotFound)
        .value("eDGNECINSTANCESTATUS_Error", DGNECINSTANCESTATUS_Error)
        .export_values();

    //===================================================================================
    // enum class DgnECHostType
    py::enum_< DgnECHostType>(m, "DgnECHostType")
        .value("eUnknown", DgnECHostType::Unknown)
        .value("eElement", DgnECHostType::Element)
        .value("eModel", DgnECHostType::Model)
        .value("eFile", DgnECHostType::File)
        .value("eDesignLink", DgnECHostType::DesignLink)
        .value("eView", DgnECHostType::View)
        .value("eAttachment", DgnECHostType::Attachment)
        .value("eLevel", DgnECHostType::Level)
        .value("eAll", DgnECHostType::All)
        .export_values();

    //===================================================================================
    // struct DgnECInstanceHost
    py::class_< DgnECInstanceHost> c1(m, "DgnECInstanceHost");

    c1.def(py::init<>());
    c1.def(py::init<ElementHandleCR>(), "eh"_a);
    c1.def(py::init<EditElementHandleR>(), "eeh"_a);
    c1.def(py::init<DgnModelR>(), "model"_a);
    c1.def(py::init<DgnFileR, ModelId>(), "dgnFile"_a, "modelId"_a);
    c1.def(py::init<DgnFileR>(), "dgnFile"_a);
    c1.def(py::init<DgnAttachmentR>(), "attachment"_a);
    c1.def(py::init<DgnModelRefR, LevelId>(), "modelRef"_a, "levelId"_a);
    c1.def(py::init<ViewGroupR, UInt32>(), "viewGroup"_a, "viewIndex"_a);
    c1.def(py::init<DgnLinkTreeNodeR>(), "linkNode"_a);

    c1.def_property_readonly("ElementHandle", &DgnECInstanceHost::GetElementHandle);
    c1.def("GetElementHandle", &DgnECInstanceHost::GetElementHandle, py::return_value_policy::reference_internal);

    c1.def_property_readonly("EditElementHandle", &DgnECInstanceHost::GetEditElementHandle);
    c1.def("GetEditElementHandle", &DgnECInstanceHost::GetEditElementHandle, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("Model", &DgnECInstanceHost::GetModel);
    c1.def("GetModel", &DgnECInstanceHost::GetModel, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("ModelItem", &DgnECInstanceHost::GetModelItem);
    c1.def("GetModelItem", &DgnECInstanceHost::GetModelItem, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("DgnFile", &DgnECInstanceHost::GetDgnFile);
    c1.def("GetDgnFile", &DgnECInstanceHost::GetDgnFile, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("Attachment", &DgnECInstanceHost::GetAttachment);
    c1.def("GetAttachment", &DgnECInstanceHost::GetAttachment, py::return_value_policy::reference_internal);
    
    c1.def_property_readonly("Level", &DgnECInstanceHost::GetLevel);
    c1.def("GetLevel", &DgnECInstanceHost::GetLevel);
    
    c1.def_property_readonly("View", [] (DgnECInstanceHost const& self)
           { 
           UInt32 viewIndex; 
           return self.GetView(viewIndex); 
           }, py::return_value_policy::reference_internal);
        
    c1.def_property_readonly("LinkNode", &DgnECInstanceHost::GetLinkNode);
    c1.def("GetLinkNode", &DgnECInstanceHost::GetLinkNode, py::return_value_policy::reference_internal);
    
    c1.def("IsElement", &DgnECInstanceHost::IsElement);
    c1.def("IsModel", &DgnECInstanceHost::IsModel);
    c1.def("IsDgnFile", &DgnECInstanceHost::IsDgnFile);
    c1.def("IsAttachment", &DgnECInstanceHost::IsAttachment);
    c1.def("IsView", &DgnECInstanceHost::IsView);
    c1.def("IsLevel", &DgnECInstanceHost::IsLevel);
    c1.def("IsDesignLink", &DgnECInstanceHost::IsDesignLink);
    
    c1.def_property_readonly("Type", &DgnECInstanceHost::GetType);
    c1.def("GetType", &DgnECInstanceHost::GetType);
    
    //===================================================================================
    // struct SelectedProperties
    py::class_< SelectedProperties, SelectedPropertiesPtr> c2(m, "SelectedProperties");

    c2.def(py::init(&SelectedProperties::Create), "selectAllProperties"_a = false);

    c2.def("AddPropertyNameToSelect", &SelectedProperties::AddPropertyNameToSelect, "accessString"_a, DOC(Bentley, DgnPlatform, SelectedProperties, AddPropertyNameToSelect));
    c2.def("Duplicate", &SelectedProperties::Duplicate, DOC(Bentley, DgnPlatform, SelectedProperties, Duplicate));
            
    //===================================================================================
    // struct DgnECInstanceCreateOptions
    py::class_< DgnECInstanceCreateOptions> c3(m, "DgnECInstanceCreateOptions");

    c3.def(py::init<bool, bool>(), "pathBasedId"_a = false, "qualifiedPepBasedId"_a = false);

    c3.def("HasPathBasedId", &DgnECInstanceCreateOptions::HasPathBasedId, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, HasPathBasedId));
    c3.def("SetPathBasedId", &DgnECInstanceCreateOptions::SetPathBasedId, "pathBased"_a, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, SetPathBasedId));

    c3.def("HasQualifiedPepBasedId", &DgnECInstanceCreateOptions::HasQualifiedPepBasedId, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, HasQualifiedPepBasedId));
    c3.def("SetQualifiedPepBasedId", &DgnECInstanceCreateOptions::SetQualifiedPepBasedId, "qulified"_a, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, SetQualifiedPepBasedId));

    c3.def("ExposesHidden", &DgnECInstanceCreateOptions::ExposesHidden, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, ExposesHidden));
    c3.def("SetExposesHidden", &DgnECInstanceCreateOptions::SetExposesHidden, "exposes"_a, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, SetExposesHidden));

    c3.def("ExposesHistorical", &DgnECInstanceCreateOptions::ExposesHistorical, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, ExposesHistorical));
    c3.def("SetExposesHistorical", &DgnECInstanceCreateOptions::SetExposesHistorical, "exposes"_a, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, SetExposesHistorical));

    c3.def("CreateReadOnly", &DgnECInstanceCreateOptions::CreateReadOnly, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, CreateReadOnly));
    c3.def("SetCreateReadOnly", &DgnECInstanceCreateOptions::SetCreateReadOnly, "readonly"_a, DOC(Bentley, DgnPlatform, DgnECInstanceCreateOptions, SetCreateReadOnly));

    //===================================================================================
    // struct DgnECInstanceCreateContext
    py::class_< DgnECInstanceCreateContext, DgnECInstanceCreateOptions> c4(m, "DgnECInstanceCreateContext");

    c4.def(py::init<SelectedPropertiesP, DgnECInstanceCreateOptionsCR>(), "selectedProperties"_a = nullptr, "options"_a = DgnECInstanceCreateOptions());
    c4.def(py::init<DgnECInstanceCreateOptionsCR>(), "options"_a = DgnECInstanceCreateOptions());

    c4.def_property("SelectedProperties", py::overload_cast<>(&DgnECInstanceCreateContext::GetSelectedProperties), &DgnECInstanceCreateContext::SetSelectedProperties);
    c4.def("GetSelectedProperties", py::overload_cast<>(&DgnECInstanceCreateContext::GetSelectedProperties), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECInstanceCreateContext, GetSelectedProperties));
    c4.def("SetSelectedProperties", &DgnECInstanceCreateContext::SetSelectedProperties, "selectedProperties"_a, DOC(Bentley, DgnPlatform, DgnECInstanceCreateContext, SetSelectedProperties));

    //===================================================================================
    // struct DgnECInstanceEnabler
    py::class_< DgnECInstanceEnabler, DgnECInstanceEnablerPtr, ECN::ECEnabler> c5(m, "DgnECInstanceEnabler");    

    c5.def_property_readonly("SharedWipInstance", &DgnECInstanceEnabler::GetSharedWipInstance);
    c5.def("GetSharedWipInstance", &DgnECInstanceEnabler::GetSharedWipInstance, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, GetSharedWipInstance));

    c5.def_property_readonly("PrivateWipInstance", &DgnECInstanceEnabler::GetPrivateWipInstance);
    c5.def("GetPrivateWipInstance", &DgnECInstanceEnabler::GetPrivateWipInstance, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, GetPrivateWipInstance));

    c5.def("SupportsCreateInstanceOnHost", &DgnECInstanceEnabler::SupportsCreateInstanceOnHost, "hostType"_a, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, SupportsCreateInstanceOnHost));
    c5.def("SupportsCreateInstanceOnElement", &DgnECInstanceEnabler::SupportsCreateInstanceOnElement, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, SupportsCreateInstanceOnElement));
    c5.def("SupportsCreateInstanceAsElement", &DgnECInstanceEnabler::SupportsCreateInstanceAsElement, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, SupportsCreateInstanceAsElement));

    c5.def("CreateInstanceOnFile", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnFileR dgnfile)
           {
           DgnECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnFile(&dgnecInstance, wipInstance, dgnfile);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnFile));

    c5.def("CreateInstanceOnModel", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnModelR dgnModel)
           {
           DgnECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnModel(&dgnecInstance, wipInstance, dgnModel);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "dgnModel"_a, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnModel));

    c5.def("CreateInstanceOnLinkNode", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnLinkTreeNodeR linkNode)
           {
           DgnECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnLinkNode(&dgnecInstance, wipInstance, linkNode);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "linkNode"_a, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnLinkNode));

    c5.def("CreateInstanceOnHost", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnECInstanceHostCR host, UInt32 intendedLocalId, DgnECInstanceCreateContextCR createContext, bool instanceOwnsHost)
           {
           DgnECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnHost(&dgnecInstance, wipInstance, host, intendedLocalId, createContext, instanceOwnsHost);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "host"_a, "intendedLocalId"_a, "createContext"_a = DgnECInstanceCreateContext(), "instanceOwnsHost"_a = false, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnHost));

    c5.def("CreateInstanceOnHost", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnECInstanceHostCR host, DgnECInstanceCreateContextCR createContext, bool instanceOwnsHost)
           {
           DgnECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnHost(&dgnecInstance, wipInstance, host, createContext, instanceOwnsHost);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "host"_a, "createContext"_a = DgnECInstanceCreateContext(), "instanceOwnsHost"_a = false, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnHost));    


    c5.def_property_readonly("StandaloneECInstanceEnabler", &DgnECInstanceEnabler::GetStandaloneECInstanceEnabler);
    c5.def("GetStandaloneECInstanceEnabler", &DgnECInstanceEnabler::GetStandaloneECInstanceEnabler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, GetStandaloneECInstanceEnabler));

    c5.def("ScheduleInstanceOnElement", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, EditElementHandleR eh, bool instanceOwnsElement)
           {
           DgnElementECInstancePtr dgnecInstance;
           auto retVal = self.ScheduleInstanceOnElement(&dgnecInstance, wipInstance, eh, instanceOwnsElement);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "eh"_a, "instanceOwnsElement"_a = false, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, ScheduleInstanceOnElement));

    c5.def("ScheduleReplaceInstanceOnElement", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnModelRefR modelRef, EditElementHandleR eh, UInt32 localId)
           {
           DgnElementECInstancePtr dgnecInstance;
           auto retVal = self.ScheduleReplaceInstanceOnElement(&dgnecInstance, wipInstance, modelRef, eh, localId);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "modelRef"_a, "eh"_a, "localId"_a, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, ScheduleReplaceInstanceOnElement));

    c5.def("CreateInstanceOnElement", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, EditElementHandleR eh, bool instanceOwnsElement)
           {
           DgnElementECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnElement(&dgnecInstance, wipInstance, eh, instanceOwnsElement);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "eh"_a, "instanceOwnsElement"_a = false, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnElement));

    c5.def("CreateInstanceOnElement", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, EditElementHandleR eh, UInt32 intendedLocalId, bool instanceOwnsElement)
           {
           DgnElementECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceOnElement(&dgnecInstance, wipInstance, eh, intendedLocalId, instanceOwnsElement);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "eh"_a, "intendedLocalId"_a, "instanceOwnsElement"_a = false, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceOnElement));

    c5.def("CreateInstanceAsElement", [] (DgnECInstanceEnabler const& self, ECN::IECInstanceCR wipInstance, DgnModelRefR modelRef, bool instanceOwnsElement)
           {
           DgnElementECInstancePtr dgnecInstance;
           auto retVal = self.CreateInstanceAsElement(&dgnecInstance, wipInstance, modelRef, instanceOwnsElement);
           return py::make_tuple(retVal, dgnecInstance);
           }, "wipInstance"_a, "modelRef"_a, "instanceOwnsElement"_a = false, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, CreateInstanceAsElement));

    c5.def("IsEnablerValidForDgnFile", &DgnECInstanceEnabler::IsEnablerValidForDgnFile, "dgnFile"_a, DOC(Bentley, DgnPlatform, DgnECInstanceEnabler, IsEnablerValidForDgnFile));


    //===================================================================================
    // struct DgnECInstance
    py::class_< DgnECInstance, DgnECInstancePtr, ECN::IECInstance> c7(m, "DgnECInstance");
    py::bind_vector<DgnECInstanceVector>(m, "DgnECInstanceVector", py::module_local(false));

    c7.def_property_readonly("HostType", &DgnECInstance::GetHostType);
    c7.def("GetHostType", &DgnECInstance::GetHostType, DOC(Bentley, DgnPlatform, DgnECInstance, GetHostType));
    
    c7.def_property_readonly("InstanceHost", &DgnECInstance::GetInstanceHost);
    c7.def("GetInstanceHost", &DgnECInstance::GetInstanceHost, DOC(Bentley, DgnPlatform, DgnECInstance, GetInstanceHost));
    
    c7.def_property_readonly("DgnModelRef", &DgnECInstance::GetDgnModelRefP);
    c7.def("GetDgnModelRef", &DgnECInstance::GetDgnModelRefP, py::return_value_policy::reference_internal);
    
    c7.def("WriteChanges", &DgnECInstance::WriteChanges, DOC(Bentley, DgnPlatform, DgnECInstance, WriteChanges));
    c7.def("ScheduleWriteChanges", &DgnECInstance::ScheduleWriteChanges, "eeh"_a, DOC(Bentley, DgnPlatform, DgnECInstance, ScheduleWriteChanges));
    c7.def("Delete", &DgnECInstance::Delete, DOC(Bentley, DgnPlatform, DgnECInstance, Delete));
    c7.def("DeleteAndIgnoreOwnership", &DgnECInstance::DeleteAndIgnoreOwnership, DOC(Bentley, DgnPlatform, DgnECInstance, DeleteAndIgnoreOwnership));
    c7.def("ScheduleDelete", &DgnECInstance::ScheduleDelete, "element"_a, DOC(Bentley, DgnPlatform, DgnECInstance, ScheduleDelete));

    c7.def_property_readonly("DgnECInstanceEnabler", &DgnECInstance::GetDgnECInstanceEnabler);
    c7.def("GetDgnECInstanceEnabler", &DgnECInstance::GetDgnECInstanceEnabler, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECInstance, GetDgnECInstanceEnabler));
    
    c7.def("GetValueAsString",
           py::overload_cast<WStringR, WCharCP, bool, UInt32>(&DgnECInstance::GetValueAsString, py::const_),
           "strVal"_a, "accessString"_a, "useArrayIndex"_a, "arrayIndex"_a, DOC(Bentley, DgnPlatform, DgnECInstance, GetValueAsString));

    c7.def("GetValueAsString",
           py::overload_cast<WStringR, UInt32, bool, UInt32>(&DgnECInstance::GetValueAsString, py::const_),
           "strVal"_a, "propertyIndex"_a, "useArrayIndex"_a, "arrayIndex"_a, DOC(Bentley, DgnPlatform, DgnECInstance, GetValueAsString));

    c7.def("SetValueAsString",
           py::overload_cast<WCharCP, WCharCP, bool, UInt32>(&DgnECInstance::SetValueAsString),
           "accessString"_a, "strVal"_a, "useArrayIndex"_a, "arrayIndex"_a, DOC(Bentley, DgnPlatform, DgnECInstance, SetValueAsString));

    c7.def("SetValueAsString",
           py::overload_cast<UInt32, WCharCP, bool, UInt32>(&DgnECInstance::SetValueAsString),
           "propertyIndex"_a, "strVal"_a, "useArrayIndex"_a, "arrayIndex"_a, DOC(Bentley, DgnPlatform, DgnECInstance, SetValueAsString));

    c7.def("GetAsElementInstance", py::overload_cast<>(&DgnECInstance::GetAsElementInstance), py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECInstance, GetAsElementInstance));
    c7.def("SetReadOnly", &DgnECInstance::SetReadOnly, "isReadonly"_a, DOC(Bentley, DgnPlatform, DgnECInstance, SetReadOnly));
    
    //===================================================================================
    // struct DgnElementECInstance
    py::class_< DgnElementECInstance, DgnElementECInstancePtr, DgnECInstance> c8(m, "DgnElementECInstance");
    py::bind_vector<bvector<DgnElementECInstancePtr>>(m, "DgnElementECInstancePtrArray", py::module_local(false));

    c8.def_property_readonly("ElementHandle", &DgnElementECInstance::GetElementHandle);
    c8.def("GetElementHandle", &DgnElementECInstance::GetElementHandle, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnElementECInstance, GetElementHandle));
    c8.def_property_readonly("ModelRef", &DgnElementECInstance::GetModelRef);
    c8.def("GetModelRef", &DgnElementECInstance::GetModelRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnElementECInstance, GetModelRef));

    c8.def_property_readonly("ElementRef", &DgnElementECInstance::GetElementRef);
    c8.def("GetElementRef", &DgnElementECInstance::GetElementRef, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnElementECInstance, GetElementRef));

    c8.def_property_readonly("LocalId", &DgnElementECInstance::GetLocalId);
    c8.def("GetLocalId", &DgnElementECInstance::GetLocalId, DOC(Bentley, DgnPlatform, DgnElementECInstance, GetLocalId));
    
    //===================================================================================
    // struct DgnECRelationshipEnabler
    py::class_< DgnECRelationshipEnabler, std::unique_ptr<DgnECRelationshipEnabler, py::nodelete>, ECN::IECRelationshipEnabler> c9(m, "DgnECRelationshipEnabler");

    c9.def("CreateRelationship", [] (DgnECRelationshipEnabler const& self, ECN::StandaloneECRelationshipInstanceR wipRelationship,
                                     DgnElementECInstanceCR instanceA, DgnElementECInstanceCR instanceB, DgnModelRefP hostModelRef, ElementRefP hostElementRef)
           {
           IDgnECRelationshipInstancePtr createdRelationship;
           auto retVal = self.CreateRelationship(&createdRelationship, wipRelationship, instanceA, instanceB, hostModelRef, hostElementRef);
           return py::make_tuple(retVal, createdRelationship);
           }, "wipRelationship"_a, "instanceA"_a, "instanceB"_a, "hostModelRef"_a = nullptr, "hostElementRef"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECRelationshipEnabler, CreateRelationship));

    c9.def("CreateRelationship", [] (DgnECRelationshipEnabler const& self, DgnElementECInstanceCR instanceA, DgnElementECInstanceCR instanceB, DgnModelRefP hostModelRef, ElementRefP hostElementRef)
           {
           IDgnECRelationshipInstancePtr createdRelationship;
           auto retVal = self.CreateRelationship(&createdRelationship, instanceA, instanceB, hostModelRef, hostElementRef);
           return py::make_tuple(retVal, createdRelationship);
           }, "instanceA"_a, "instanceB"_a, "hostModelRef"_a = nullptr, "hostElementRef"_a = nullptr, DOC(Bentley, DgnPlatform, DgnECRelationshipEnabler, CreateRelationship));

    c9.def_property_readonly("SharedStandaloneWipInstance", &DgnECRelationshipEnabler::GetSharedStandaloneWipInstance);
    c9.def("GetSharedStandaloneWipInstance", &DgnECRelationshipEnabler::GetSharedStandaloneWipInstance, py::return_value_policy::reference_internal, DOC(Bentley, DgnPlatform, DgnECRelationshipEnabler, GetSharedStandaloneWipInstance));

    c9.def("SupportsRelationshipProperties", &DgnECRelationshipEnabler::SupportsRelationshipProperties, DOC(Bentley, DgnPlatform, DgnECRelationshipEnabler, SupportsRelationshipProperties));
        
    //===================================================================================
    // struct IDgnECRelationshipInstance
    py::class_< IDgnECRelationshipInstance, IDgnECRelationshipInstancePtr, ECN::IECRelationshipInstance> c10(m, "IDgnECRelationshipInstance");
    py::bind_vector<bvector< IDgnECRelationshipInstancePtr>>(m, "IDgnECRelationshipInstancePtrArray", py::module_local(false));

    c10.def("Delete", &IDgnECRelationshipInstance::Delete, DOC(Bentley, DgnPlatform, IDgnECRelationshipInstance, Delete));

    c10.def("GetSourceOrderId", [] (IDgnECRelationshipInstanceCR self)
            {
            Int64 orderId = 0;
            auto retVal = self.GetSourceOrderId(orderId);
            return py::make_tuple(retVal, orderId);
            }, DOC(Bentley, DgnPlatform, IDgnECRelationshipInstance, GetSourceOrderId));

    c10.def("GetTargetOrderId", [] (IDgnECRelationshipInstanceCR self)
            {
            Int64 orderId = 0;
            auto retVal = self.GetTargetOrderId(orderId);
            return py::make_tuple(retVal, orderId);
            }, DOC(Bentley, DgnPlatform, IDgnECRelationshipInstance, GetTargetOrderId));

    c10.def("GetSourceAssociatedString", [] (IDgnECRelationshipInstanceCR self)
            {
            WCharCP propString = nullptr;
            auto retVal = self.GetSourceAssociatedString(propString);
            return py::make_tuple(retVal, propString);
            }, DOC(Bentley, DgnPlatform, IDgnECRelationshipInstance, GetSourceAssociatedString));

    c10.def("GetTargetAssociatedString", [] (IDgnECRelationshipInstanceCR self)
            {
            WCharCP propString = nullptr;
            auto retVal = self.GetTargetAssociatedString(propString);
            return py::make_tuple(retVal, propString);
            }, DOC(Bentley, DgnPlatform, IDgnECRelationshipInstance, GetTargetAssociatedString));

    c10.def("GetRelatedInstance", &IDgnECRelationshipInstance::GetRelatedInstance, "end"_a, "createContext"_a, DOC(Bentley, DgnPlatform, IDgnECRelationshipInstance, GetRelatedInstance));
        
    //===================================================================================
    // struct DgnECInstanceIterable
    py::class_< DgnECInstanceIterable> c11(m, "DgnECInstanceIterable");
    py::bind_vector< bvector<DgnECInstanceIterable> >(m, "DgnECInstanceIterableArray", py::module_local(false));

    c11.def("empty", &DgnECInstanceIterable::empty, DOC(Bentley, DgnPlatform, DgnECInstanceIterable, empty));
    c11.def("IsNull", &DgnECInstanceIterable::IsNull, DOC(Bentley, DgnPlatform, DgnECInstanceIterable, IsNull));
    c11.def("__bool__", [] (DgnECInstanceIterable& self) { return !self.IsNull(); });
    c11.def("__iter__", [] (DgnECInstanceIterable& self) { return py::make_iterator(self.begin(), self.end()); }, py::keep_alive<0, 1>());

    //===================================================================================
    // struct DgnECRelationshipIterable
    py::class_< DgnECRelationshipIterable> c12(m, "DgnECRelationshipIterable");
    py::bind_vector<bvector< DgnECRelationshipIterable>>(m, "DgnECRelationshipIterableArray", py::module_local(false));

    c12.def("empty", &DgnECRelationshipIterable::empty);
    c12.def("__bool__", [] (DgnECRelationshipIterable& self) { return !self.empty(); });
    c12.def("__iter__", [] (DgnECRelationshipIterable& self) { return py::make_iterator(self.begin(), self.begin()); }, py::keep_alive<0, 1>());
    }