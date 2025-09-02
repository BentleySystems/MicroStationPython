from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to import a SHP file and create links on the imported features.

This sample demonstrates the following:
1. Ensure that Geographic Coordinate System is set in active model
2. Clear all imported features in the active model
3. Import a SHP file
4. Create links on the imported features. The sample assumes that the imported features have a property called "img_link" which contains the URL of the image to be linked.
'''

def GetImageURLFromElement(element, imageURLPropertyName="img_link"):
    '''
    Get the image URL from the element

    :param element: Element handle
    :type element: ElementHandle
    :param imageURLPropertyName: Image URL property name
    :type imageURLPropertyName: str

    :return: Image URL
    :rtype: str
    '''
    customItemHost = CustomItemHost(element)
    cItemcount = customItemHost.GetCustomItemsCount()
    if cItemcount < 1:
        return None

    instanceList   = DgnECInstanceVector()
    instanceCount = customItemHost.GetCustomItems (instanceList)
    for instance in instanceList:
        #find the item type of this EC instance
        ecClass = instance.GetEnabler().GetClass()
        properties = ecClass.GetProperties(False)
        propValue = ECValue()
        for primitiveProp in properties:
            accessString = primitiveProp.GetName()
            instance.GetValue(propValue, str(accessString))
            propertyName = str(accessString)
            propertyValue = str(propValue.ToString()).strip()
            if (propertyName == imageURLPropertyName):
                #print(f"property={propertyName} = propertyValue={propertyValue}")
                return propertyValue    

    return None


def CreateURLLink (urlAddress):
    '''
    Create a URL link
    
    :param urlAddress: URL address
    :type urlAddress: str

    :return: Link handle
    :rtype: DgnLinkHandle
    '''

    linkType = DGNLINK_TYPEKEY_URLLink
    link, status = DgnLinkManager.CreateLink (linkType)    
    if link is None:
        print(f"DgnLinkManager.CreateLink failed to create new leaf: {status}")
        return None
    urlLink = link.GetLink()
    urlLink.SetAddress(urlAddress)
    return link

def AttachURLLinkToElement (element, urlAddress):
    '''
    Attach a URL link to the element

    :param element: Element handle
    :type element: ElementHandle
    :param urlAddress: URL address
    :type urlAddress: str

    :return: Bentley status
    :rtype: BentleyStatus
    '''
    createdLink = CreateURLLink (urlAddress)
    if createdLink is None:
        print(f"DgnLinkManager.CreateLink failed to create new leaf: {status}")
        return BentleyStatus.eERROR

    spec = DgnLinkManager.CreateTreeSpec (element.GetElementRef())
    if spec is None:
        print(f"DgnLinkManager.CreateTreeSpec failed")
        return BentleyStatus.eERROR
    elementTree = DgnLinkManager.ReadLinkTree (spec, True)
    if elementTree is None:
        print(f"DgnLinkManager.ReadLinkTree failed")
        return BentleyStatus.eERROR

    root = elementTree.GetRoot ()

    #   Create and add the new node to the linkTree
    nodeToAdd = createdLink.AsDgnLinkTreeLeaf ()
    if elementTree is None:
        print(f"createdLink.AsDgnLinkTreeLeaf failed")
        return BentleyStatus.eERROR

    destLeaf    = nodeToAdd.Copy (elementTree.GetTreeSpec ())
    sourceLink  = nodeToAdd.GetLink ()

    suggestedName = sourceLink.BuildSuggestedName (None, True)
    newName = root.GetUniqueChildName (str(suggestedName))
    destLeaf.SetName (str(newName))

    stat = root.AddChild (destLeaf, 0)
    if stat != DgnLinkAddChildStatus.eSuccess:
        print(f"root.AddChild Failed to add child to link tree: {stat}")
        return stat

    stat = DgnLinkManager.WriteLinkTree (elementTree, element)    
    if stat != BentleyStatus.eSUCCESS:
        print(f"DgnLinkManager.WriteLinkTree failed to write link tree: {stat}")
        return stat

    return BentleyStatus.eSUCCESS

def CreateLinksOnImportedFeatures(modelRef, imageURLPropertyName):
    '''
    Create links on the imported features
    
    :param modelRef: Model reference
    :type modelRef: DgnModelRef
    :param imageURLPropertyName: Image URL property name
    :type imageURLPropertyName: str

    :return: Number of linked elements
    :rtype: int
    '''
    dgnModel = modelRef.GetDgnModel()
    if dgnModel is None:
        print("Failed to get DgnModel from DgnModelRef.")
        return 0

    # Get the graphic elements in the model
    elementRefList = dgnModel.GetGraphicElements()
    if elementRefList is None:
        print("Failed to get graphic elements.")
        return 0
    if elementRefList.IsEmpty():
        print("No graphic elements.")
        return 0

    # Iterate through the elements and delete the imported features
    nLinked = 0
    for elementRef in elementRefList:
        element = EditElementHandle (elementRef, modelRef)
        if element is None:
            continue

        if ImportManager.IsImportedFeatureElement(element):
            imageURL = GetImageURLFromElement(element, imageURLPropertyName)
            if imageURL is None:
                continue

            if AttachURLLinkToElement (element, imageURL) == BentleyStatus.eSUCCESS:
                #print ("Attached Image URL: " + imageURL)
                element.ReplaceInModel(elementRef)
                nLinked += 1

    return nLinked
    
def ClearImportedFeatures(modelRef):
    '''
    Clear all imported features in the active model

    :param modelRef: Model reference
    :type modelRef: DgnModelRef

    :return: Number of deleted elements
    :rtype: int
    '''
    
    dgnModel = modelRef.GetDgnModel()
    if dgnModel is None:
        print("Failed to get DgnModel from DgnModelRef.")
        return 0

    # Get the graphic elements in the model
    elementRefList = dgnModel.GetGraphicElements()
    if elementRefList is None:
        print("Failed to get graphic elements.")
        return 0
    if elementRefList.IsEmpty():
        print("No graphic elements.")
        return 0

    # Iterate through the elements and delete the imported features
    nDeleted = 0
    for elementRef in elementRefList:
        element = EditElementHandle (elementRef, modelRef)
        if element is None:
            continue
        if ImportManager.IsImportedFeatureElement(element):
            #print(f"Deleting imported element ID: {element.GetElementId()}")
            if element.DeleteFromModel() == 0:
                nDeleted += 1
    return nDeleted

def CreateDocumentMonikerFromFilePath (filePath):
    '''
    Create a DgnDocumentMoniker from the file path

    :param filePath: Full path of the file
    :type filePath: str

    :return: DgnDocumentMoniker for the file
    :rtype: DgnDocumentMoniker
    '''    

    # Check if the file exists
    if not path.exists(filePath):
        print (f"File not found: {filePath}")
        return None

    # Get the base name of the selected file (i.e., the file name without directory)
    base_file_name = os.path.basename(filePath)  # get the base name of the selected file (i.e., the file name without directory)
    print (f"SHP file Moniker: Base={base_file_name} type={type(base_file_name)} Full={filePath} type={type(filePath)} ")

    # Create a moniker from the raw data (file name and full path)
    return DgnDocumentMoniker.CreateFromRawData (base_file_name, filePath, None, None, True, None)

def ImportSHPFile(fullFileName):
    '''
    Import the SHP file for the full file path

    :param fullFileName: Full path of the SHP file
    :type fullFileName: str

    :return: None
    '''    

    shpFileMoniker = CreateDocumentMonikerFromFilePath(fullFileName)                                                   
    if shpFileMoniker is None:
        print (f"Failed to create DgnDocumentMoniker for {fullFileName}")
        return    

    flipCoordinates = False

    dgnContainingExistingTemplate = None
    existingTemplateFullPath = WString("")

    status, importSpec = ImportManager.GetManager().CreateSHPImportSpecification(shpFileMoniker, dgnContainingExistingTemplate, existingTemplateFullPath, flipCoordinates)
    if importSpec is None:
        print (f"Failed to create SHPImportSpecification for {fullFileName}, status={status}")
        return
        
    status, nImported = importSpec.Import()
    print (f"Import {fullFileName}, status={status}, nImported={nImported}")

#main
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

        # Get the active model reference
        modelRef = ISessionMgr.ActiveDgnModelRef

        # Clear all imported features in the active model
        nCleared = ClearImportedFeatures(modelRef)
        print (f"Cleared {nCleared} imported features.")

        # Import the SHP file            
        file = 'd_us_fl_bp_1124_Guardrail_Damage_2024_12_17.shp'
        dataDir = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\SHP\\"
        fullFileName = path.join(dataDir, file)
        print (f"Importing: {fullFileName}")
        ImportSHPFile(fullFileName)

        # Link the imported features
        nLinked = CreateLinksOnImportedFeatures(modelRef, imageURLPropertyName="img_link")
        print (f"Linked {nLinked} imported features.")

    print("Script end...")
        