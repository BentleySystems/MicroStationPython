# $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $

import os

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
This sample demonstrates how to register for DgnEC change events.
'''

class DgnECHelper:
    """
    DgnECHelper is a utility class that provides static methods for interacting with DGN files, models, 
    and creating elements and schemas in a MicroStation environment.
    Methods:
        GetDgnFile():
            Retrieves the active DGN file using the session manager.
        GetDgnModel():
            Retrieves the default model from the active DGN file. Prints an error message if no default model is found.
        CreateLine(x1, y1, z1, x2, y2, z2):
            Creates a line element in the active DGN model using the provided 3D coordinates.
            Prints error messages if the line creation or addition to the model fails.
            Returns:
                EditElementHandle: The handle to the created line element.
        CreateSchema():
            Creates and loads an EC schema into the active DGN file. The schema defines two classes, 
            "Gadget" and "Widget," along with their properties and a relationship class "WidgetHasGadgets."
            Prints an error message if schema creation fails.
            Returns:
                Schema: The loaded schema object if successful, otherwise None.
    """
    @staticmethod
    def GetDgnFile ():
        dgnFile = ISessionMgr.GetActiveDgnFile ()
        return dgnFile
    
    @staticmethod
    def GetDgnModel (): 
        dgnFile = DgnECHelper.GetDgnFile ()
        modelId = dgnFile.GetDefaultModelId ()
        retVal = dgnFile.LoadRootModelById (modelId,True,True)
        if BentleyStatus.eSUCCESS != retVal[1]:
            print ("No Default Model Found")
        return retVal[0]

    @staticmethod
    def  CreateLine (x1, y1, z1, x2, y2, z2):
        model = DgnECHelper.GetDgnModel ()
        segment = DSegment3d(x1, y1, z1, x2, y2, z2)
        eeh = EditElementHandle()
        status = LineHandler.CreateLineElement (eeh, None, segment, model.Is3d (), model)
        if BentleyStatus.eSUCCESS != status:
            print ("Failed to create line")
            return
        status = eeh.AddToModel ()
        if BentleyStatus.eSUCCESS != status:
            print ("Failed to add line to model")

        return eeh
    
    @staticmethod
    def CreateSchema():
        schemaAsXml = """<?xml version="1.0" encoding="UTF-8"?>
<ECSchema schemaName="DGNECPlugin_Test" nameSpacePrefix="DT" version="1.0" description="Test Schema for DGNECPlugin tests" displayLabel="DGNECPlugin Test Schema" xmlns="http://www.bentley.com/schemas/Bentley.ECXML.2.0">
    <ECSchemaReference name="EditorCustomAttributes" version="01.00" prefix="beca" />
    <ECSchemaReference name="Bentley_Standard_CustomAttributes" version="01.00" prefix="bsca" />
    <ECSchemaReference name="Bentley_Standard_Classes" version="01.00" prefix="bsm" />
    <ECClass typeName="Gadget" description="An ECClass representing a Gadget" displayLabel="Gadget" isDomainClass="True">
        <ECProperty propertyName="Tag" typeName="string" description="Tag" />
        <ECProperty propertyName="Inventor" typeName="string" description="GadgetInventor" />
        <ECProperty propertyName="TestProperty1" typeName="string" description="Gadget Test Property1" />
        <ECProperty propertyName="TestProperty2" typeName="string" description="Gadget Test Property2" />
    </ECClass>
    <ECClass typeName="Widget" description="An ECClass representing a Widget" displayLabel="Widget" isDomainClass="True">
        <ECProperty propertyName="Tag" typeName="string" description="Tag" />
        <ECProperty propertyName="Manufacturer" typeName="string" description="WidgetManufacturer" />
        <ECProperty propertyName="Property1" typeName="string" description="Widget Test Property1" />
        <ECProperty propertyName="Property2" typeName="string" description="Widget Test Property2" />
    </ECClass>
    <ECRelationshipClass typeName="WidgetHasGadgets" description="WidgetHasGadgets" isDomainClass="True" strength="referencing" strengthDirection="forward">
        <Source cardinality="(1,1)" roleLabel="has Gadgets" polymorphic="True">
            <Class class="Widget" />
        </Source>
        <Target cardinality="(1,N)" roleLabel="are held by Widget" polymorphic="True">
            <Class class="Gadget" />
        </Target>
    </ECRelationshipClass>
</ECSchema>"""

        retVal, schema = DgnECManager.GetManager().ReadSchemaFromXmlString(schemaAsXml, DgnECHelper.GetDgnFile())
        if BentleyStatus.eSUCCESS != retVal:
            print("Failed to create schema")
            return None

        return schema
    
class BaseChangeProcessor (IDgnECChangeListener):
    """
    BaseChangeProcessor is a class that implements the IDgnECChangeListener interface to handle
    and process changes in DgnEC instances and relationships. It maintains records of added,
    modified, deleted, and existing instances and relationships, and provides methods to clear
    these records and access them via properties.
    Attributes:
        m_addedInstances (DgnInstanceChangeRecords): Records of added instances.
        m_modifiedInstances (DgnInstanceChangeRecords): Records of modified instances.
        m_deletedInstances (DgnInstanceChangeRecords): Records of deleted instances.
        m_existingInstances (DgnInstanceChangeRecords): Records of existing instances.
        m_addedRelations (DgnRelationChangeRecords): Records of added relationships.
        m_modifiedRelations (DgnRelationChangeRecords): Records of modified relationships.
        m_deletedRelations (DgnRelationChangeRecords): Records of deleted relationships.
        m_existingRelations (DgnRelationChangeRecords): Records of existing relationships.
    Methods:
        __init__(priority):
            Initializes the BaseChangeProcessor with a given priority and registers it
            as a DgnEC change listener.
        __del__():
            Destructor that clears all records and unregisters the change listener.
        Clear():
            Clears all instance and relationship change records.
        AddedInstances:
            Property to access the records of added instances.
        ModifiedInstances:
            Property to access the records of modified instances.
        DeletedInstances:
            Property to access the records of deleted instances.
        ExistingInstances:
            Property to access the records of existing instances.
        AddedRelations:
            Property to access the records of added relationships.
        ModifiedRelations:
            Property to access the records of modified relationships.
        DeletedRelations:
            Property to access the records of deleted relationships.
        ExistingRelations:
            Property to access the records of existing relationships.
        RelationshipsChanged(changedRecords, files, transactionType):
            Handles changes in relationships by categorizing them into added, modified,
            deleted, or existing based on their change state.
        DgnECInstancesChanged(changedRecords, files, transactionType):
            Handles changes in instances by categorizing them into added, modified,
            deleted, or existing based on their change state.
        """
    def __init__(self, priority):
        super().__init__(priority)
        self.m_addedInstances = DgnInstanceChangeRecords()
        self.m_modifiedInstances = DgnInstanceChangeRecords()
        self.m_deletedInstances = DgnInstanceChangeRecords()
        self.m_existingInstances = DgnInstanceChangeRecords()
        self.m_addedRelations = DgnRelationChangeRecords()
        self.m_modifiedRelations = DgnRelationChangeRecords()
        self.m_deletedRelations = DgnRelationChangeRecords()
        self.m_existingRelations= DgnRelationChangeRecords()
        DgnECManager.GetManager().RegisterDgnECChangeListener (self)

    def __del__(self):
        self.Clear ()
        DgnECManager.GetManager ().UnregisterDgnECChangeListener (self)

    def Clear (self):
        self.m_addedInstances.clear()
        self.m_modifiedInstances.clear()
        self.m_deletedInstances.clear()
        self.m_existingInstances.clear()
        self.m_addedRelations.clear()
        self.m_modifiedRelations.clear()
        self.m_deletedRelations.clear()
        self.m_existingRelations.clear()
    
    @property
    def AddedInstances(self):
        return self.m_addedInstances
    
    @property
    def ModifiedInstances(self):
        return self.m_modifiedInstances
    
    @property
    def DeletedInstances(self):
        return self.m_deletedInstances
    
    @property
    def ExistingInstances(self):
        return self.m_existingInstances
    
    @property
    def AddedRelations(self):
        return self.m_addedRelations
    
    @property
    def ModifiedRelations(self):
        return self.m_modifiedRelations
    
    @property
    def DeletedRelations(self):
        return self.m_deletedRelations
    
    @property
    def ExistingRelations(self):
        return self.m_existingRelations
    
    def RelationshipsChanged(self, changedRecords, files, transactionType):
        """
        Override method from IDgnECChangeListener to handle relationship changes.
        """
        for nRecord in changedRecords:
            change_state = nRecord.GetChangeState()
            if change_state == DgnECChangeType.eAdded:
                self.m_addedRelations.push_back(nRecord)
            elif change_state == DgnECChangeType.eModified:
                self.m_modifiedRelations.push_back(nRecord)
            elif change_state == DgnECChangeType.eDeleted:
                self.m_deletedRelations.push_back(nRecord)
            else:
                self.m_existingRelations.push_back(nRecord)

    def DgnECInstancesChanged(self, changedRecords, files, transactionType):
        """
        Override method from IDgnECChangeListener to handle instance changes.
        """
        for nRecord in changedRecords:
            change_state = nRecord.GetChangeState()
            if change_state == DgnECChangeType.eAdded:
                self.m_addedInstances.push_back(nRecord)
            elif change_state == DgnECChangeType.eModified:
                self.m_modifiedInstances.push_back(nRecord)
            elif change_state == DgnECChangeType.eDeleted:
                self.m_deletedInstances.push_back(nRecord)
            else:
                self.m_existingInstances.push_back(nRecord)

class ExtrinsicSchemaListener (BaseChangeProcessor):
    class ExtrinsicSchemaListener(BaseChangeProcessor):
        """
        A listener class that extends the BaseChangeProcessor to handle changes
        for a specific schema identified by its full schema name.
        Attributes:
            SCHEMA (str): The full schema name that this listener is configured to accept.
        Methods:
            __init__():
                Initializes the listener with a priority value of 5.
            AcceptChangeFor(ecClass, transactionType):
                Determines whether a change should be accepted based on the schema
                of the provided EC class.
        """
    SCHEMA = "DGNECPlugin_Test.01.00"

    def __init__ (self):
        super ().__init__ (5)

    def AcceptChangeFor (self, ecClass, transactionType):
        accepted = ecClass.GetSchema().FullSchemaName.Equals (self.SCHEMA)
        return accepted
    
class ItemTypeListener (BaseChangeProcessor):
    class ItemTypeListener:
        """
        A listener class that extends the BaseChangeProcessor to handle changes 
        related to Item Types in a DgnEC environment.
        Methods:
            __init__():
                Initializes the ItemTypeListener with a predefined priority level.
            AcceptChangeFor(ecClass, transactionType):
                Determines whether a change should be accepted for a given EC class 
                and transaction type based on whether the schema is an Item Type schema.
        """
    def __init__ (self):
        super ().__init__ (4)
        
    def AcceptChangeFor (self, ecClass, transactionType):
        accepted = ItemTypeLibrary.IsItemTypeSchema (ecClass.GetSchema())
        return accepted
    
def UserSchemaInstancesChangeEvents():
    """
    UserSchemaInstancesChangeEvents()
    This function demonstrates the creation, modification, and deletion of schema instances 
    and relationships using the DgnEC framework. It includes the following steps:
    1. Initializes an extrinsic schema listener to track changes.
    2. Imports a schema named 'DGNECPlugin_Test' and verifies its successful loading.
    3. Creates a 'Widget' instance with specific properties and attaches it to an element.
    4. Creates a 'Gadget' instance with specific properties and attaches it to another element.
    5. Establishes a relationship between the 'Widget' and 'Gadget' instances.
    6. Queries the created 'Gadget' instance, modifies its 'Tag' property, and writes the changes.
    7. Adds another 'Gadget' instance, establishes a relationship with the existing 'Widget', 
        and verifies the added instances and relationships.
    8. Deletes the newly added 'Gadget' instance and verifies the deletion.
    The function also prints the status of each operation and the counts of added, modified, 
    and deleted instances and relationships.
    Returns:
         None
    """
    #initialize listener
    extListener = ExtrinsicSchemaListener()

    #initializations
    schemaName = 'DGNECPlugin_Test'
    WidgetHasGadgets = 'WidgetHasGadgets'
    Gadget = 'Gadget'
    Widget = 'Widget'
    
    # import schema
    extSchema = DgnECHelper.CreateSchema ()
    importStatus = DgnECManager.GetManager().ImportSchema (extSchema, DgnECHelper.GetDgnFile (), True)
    if importStatus == SchemaReadStatus.eSCHEMA_READ_STATUS_Success:
         print("Schema loaded successfully!")
    else:
        print("Failed to load schema!")
        return
    
    extListener.Clear ()
    
    # create widget
    widgetEnabler = DgnECManager.GetManager ().ObtainInstanceEnablerByName (schemaName, Widget, DgnECHelper.GetDgnFile ())
    eh = DgnECHelper.CreateLine (100., 100., 0., 100., 100., 0.0)
    if eh is None:
        return
    
    widgetWipInstance = widgetEnabler.GetSharedWipInstance ()
    widgetWipInstance.SetValue ('Tag', ECValue ('FirstWidget'))
    widgetWipInstance.SetValue ('Manufacturer', ECValue ('ACME Engineering'))
    widgetWipInstance.SetValue ('Property1', ECValue ('test data'))
    widgetWipInstance.SetValue ('Property2', ECValue ('test data'))

    retVal, widgetInstance = widgetEnabler.CreateInstanceOnElement (widgetWipInstance, eh)
    if  DgnECInstanceStatus.eDGNECINSTANCESTATUS_Success == retVal:
        print ("Widget created successfully!")
    else:
        print ("Failed to create Widget!")
        return
      
    # create gadget
    gadgetEnabler = DgnECManager.GetManager ().ObtainInstanceEnablerByName (schemaName, Gadget, DgnECHelper.GetDgnFile ())
    eh = DgnECHelper.CreateLine (200., 200., 0., 200., 0., 200.)
    if eh is None:
        return
    
    gadgetWipInstance = gadgetEnabler.GetSharedWipInstance ()
    gadgetWipInstance.SetValue ('Tag', ECValue ('FirstGadget'))
    gadgetWipInstance.SetValue ('Manufacturer', ECValue ('ACME Engineering'))
    gadgetWipInstance.SetValue ('Property1', ECValue ('test data'))
    gadgetWipInstance.SetValue ('Property2', ECValue ('test data'))
    retVal, gadgetInstance= gadgetEnabler.CreateInstanceOnElement (gadgetWipInstance, eh)
    if DgnECInstanceStatus.eDGNECINSTANCESTATUS_Success == retVal:
        print ("Gadget created successfully!")
    else:
        print ("Failed to create Gadget!")
        return
    
    # create relationship
    relationshipEnabler = DgnECManager.GetManager ().ObtainDgnECRelationshipEnabler (schemaName, WidgetHasGadgets, DgnECHelper.GetDgnFile ())
    retVal, createdRelationship= DgnECManager.GetManager ().CreateRelationship (relationshipEnabler, widgetInstance, gadgetInstance)
    if DgnECInstanceStatus.eDGNECINSTANCESTATUS_Success == retVal:
        print ("RelationshipInstance created successfully!")
    else:
        print ("Failed to create RelationshipInstance!")
        return
    
    print ("Count of Added instance: ", len(extListener.AddedInstances))
    
    #query child and modify it's name
    extListener.Clear ()
    scope = FindInstancesScope.CreateScope (DgnECHelper.GetDgnModel (), FindInstancesScopeOption (DgnECHostType.eElement, True))
    query = ECQuery.CreateQuery (schemaName, Gadget)

    instanceCol, count = DgnECManager.GetManager ().FindInstances (scope, query)
    for foundInstance in instanceCol:
        foundInstance.SetValue ('Tag', ECValue ('ModifiedGadget'))
        foundInstance.WriteChanges ()
        break

    print ("Count of Modified instance: ", len(extListener.ModifiedInstances))
    print ("Count of Modified Relations: ", len(extListener.ModifiedRelations))
    
    extListener.Clear ()
  
    # query Widget
    widgetInstance = None
    gadgetInstance = None
    scope = FindInstancesScope.CreateScope (DgnECHelper.GetDgnModel(), FindInstancesScopeOption (DgnECHostType.eElement, True))
    query = ECQuery.CreateQuery (schemaName, Widget)

    instanceCol, count = DgnECManager.GetManager ().FindInstances (scope, query)
    for foundInstance in instanceCol:
        widgetInstance = foundInstance.GetAsElementInstance ()
        break

    # add one more child and relation
    # create new gadget
    eh = DgnECHelper.CreateLine (300., 300., 0., 300., 300., 0.)
    gadgetWipInstance = gadgetEnabler.GetSharedWipInstance ()
    gadgetWipInstance.SetValue ('Tag', ECValue ('SecondGadget'))
    gadgetWipInstance.SetValue ('Manufacturer', ECValue ('L&T Engineering'))
    gadgetWipInstance.SetValue ('Property1', ECValue ('test data'))
    gadgetWipInstance.SetValue ('Property2', ECValue ('test data'))
    retVal, gadgetInstance = gadgetEnabler.CreateInstanceOnElement (gadgetWipInstance, eh)
    if DgnECInstanceStatus.eDGNECINSTANCESTATUS_Success != retVal:
        print ("Failed to create Gadget!")
        return
    
    # create relationship
    relationshipEnabler = DgnECManager.GetManager ().ObtainDgnECRelationshipEnabler (schemaName, WidgetHasGadgets, DgnECHelper.GetDgnFile ())
    retVal, createdRelationship= DgnECManager.GetManager ().CreateRelationship (relationshipEnabler, widgetInstance, gadgetInstance)
    if DgnECInstanceStatus.eDGNECINSTANCESTATUS_Success != retVal:      
        print ("Failed to create RelationshipInstance!")
        return
    
    print ("Count of Added instance: ", len(extListener.AddedInstances))
    print ("Count of Added Relations: ", len(extListener.AddedRelations))
    
    # delete gadget
    extListener.Clear ()

    # query gadget
    scope = FindInstancesScope.CreateScope (DgnECHelper.GetDgnModel (), FindInstancesScopeOption (DgnECHostType.eElement, True))
    query = ECQuery.CreateQuery (schemaName, Gadget)
    wh = WhereCriterion.CreateComparison (WhereExpression.CreatePropertyExpression(WString('Tag')), WhereCriterion.eEQ, WhereExpression.CreateConstant (ECValue ('SecondGadget')))
    query.SetWhereCriterion (wh)

    instanceCol, count = DgnECManager.GetManager ().FindInstances (scope, query)
    for foundInstance in instanceCol:
        foundInstance.Delete ()
        break

    print ("Count of Deleted instance: ", len(extListener.DeletedInstances))
    DgnECHelper.GetDgnFile().ProcessChanges(DgnSaveReason.eUserInitiated)

def ItemTypeInstancesChangeEvents():
    """
    Demonstrates the creation, modification, and deletion of ItemType instances 
    and the use of a listener to track these changes.
    The function performs the following steps:
    1. Initializes an ItemTypeListener to monitor changes.
    2. Creates an ItemType library named 'TestLibrary' with two ItemTypes ('First' and 'Second'),
       each containing properties 'FirstName' and 'LastName' of type string.
    3. Writes the ItemType library to the DGN file.
    4. Creates a line element and attaches the ItemTypes to it.
    5. Modifies the properties of the attached ItemTypes and writes the changes.
    6. Deletes one of the attached ItemTypes.
    The function also prints the count of added, modified, and deleted instances 
    as tracked by the ItemTypeListener at each stage.
    Note:
    - The function assumes the existence of helper classes and methods such as 
      `ItemTypeLibrary`, `DgnECHelper`, `CustomItemHost`, `ECValue`, and `ItemTypeListener`.
    - The function does not return any value.
    """
    #initialize listener
    IitpListener = ItemTypeListener ()

    #create ItemType library with two ItemType
    itemtypeLib = ItemTypeLibrary('TestLibrary', DgnECHelper.GetDgnFile ())

    itpFirst = itemtypeLib.AddItemType ('First')
    prop = itpFirst.AddProperty ('FirstName')
    prop.SetType (CustomProperty.Type1.eString)
    prop = itpFirst.AddProperty ('LastName')
    prop.SetType (CustomProperty.Type1.eString)

    itpSecond = itemtypeLib.AddItemType ('Second')
    prop = itpSecond.AddProperty ('FirstName')
    prop.SetType (CustomProperty.Type1.eString)
    prop = itpSecond.AddProperty ('LastName')
    prop.SetType (CustomProperty.Type1.eString)

    itemtypeLib.Write()

    print ("item type written...")
    IitpListener.Clear ()

    #create element
    eeh = DgnECHelper.CreateLine (0.0, 0.0, 0.0, 100.0, 100.0, 0.0)
    if eeh is None:
        return

    #attach itemType
    host = CustomItemHost (eeh, False)   
    fItem = host.ApplyCustomItem (itpFirst)
    sItem = host.ApplyCustomItem (itpSecond)

    print ("Count of added instance: ", len(IitpListener.AddedInstances))
    IitpListener.Clear ()

    #modify
    fItem.SetValue ('FirstName', ECValue('AA'))
    fItem.SetValue ('LastName', ECValue ('BB'))
    sItem.SetValue ('FirstName', ECValue ('XX'))
    sItem.SetValue ('LastName', ECValue ('YY'))
    fItem.WriteChanges ()
    sItem.WriteChanges ()

    print ("Count of Modified instance: ", len(IitpListener.ModifiedInstances))
    IitpListener.Clear ()

    #delete
    fItem.Delete ()
    print ("Count of Deleted instance: ", len(IitpListener.DeletedInstances))

if __name__ == "__main__":
    print("Add DgnEC Events listener keyin...")
    keyinXml = os.path.dirname(__file__) + '\\DgnECChangeEvents.commands.xml'
    PythonKeyinManager.GetManager ().LoadCommandTableFromXml (WString (__file__), WString (keyinXml))
    print("DgnEC Events listener Keyin added...")
