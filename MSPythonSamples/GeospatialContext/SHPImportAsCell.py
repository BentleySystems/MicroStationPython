from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating how to import a SHP file containing point geometry as cell point geometry.

For import into a new DGN file where element template does not exist, the SHP file is imported by default with the line point geometry.
To import the SHP file with cell point geometry, the element template must be created and updated before importing the SHP file.

1. Ensure that Geographic Coordinate System is set in active model
2. Clear all imported features in the active model
3. Create the SHP Import specification for the SHP file
4. If element template does not exist, create it from the SHP Import specification by calling CreateDefaultElementTemplate
    a. Initialize the element template by updating the active point type to cell with cell name and cell fixed size
5. Import the SHP file

'''
    
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

def SetElementTemplateCellFixedSize(elementTemplateInstance, fixedSizeInInches):

    '''
    Set the cell fixed size for the element template instance
    
    :param elementTemplateInstance: Element template instance
    :type elementTemplateInstance: ElementTemplateInstance
    :param fixedSizeInInches: Fixed size in inches
    :type fixedSizeInInches: float

    :return: None
    '''

    index = 0
    actual = 0.0 
    if eETSTATUS_Success != ElementTemplateParamsHelper.GetCellFixedSize (actual, elementTemplateInstance, index):
        ElementTemplateParamsHelper.AddCellFixedSize (elementTemplateInstance, fixedSizeInInches)    
    else:
        ElementTemplateParamsHelper.SetCellFixedSize (elementTemplateInstance, fixedSizeInInches, index)    


def SetElementTemplateActivePointCell(elementTemplateInstance, modelRef, cellName):

    '''
    Set the active point cell for the element template instance
    
    :param elementTemplateInstance: Element template instance
    :type elementTemplateInstance: ElementTemplateInstance
    :param modelRef: Model reference
    :type modelRef: DgnModelRef
    :param cellName: Cell name
    :type cellName: str

    :return: None
    '''

    index = 0
    retVal, actualPointType, actualPointString = ElementTemplateParamsHelper.GetActivePointSpecification (elementTemplateInstance, index)
    if (eETSTATUS_InvalidPropertySpecification == retVal) :
        ElementTemplateParamsHelper.AddActivePointSpecification (elementTemplateInstance, eACTIVEPOINTTYPE_Cell, WString (cellName))
    else:
        ElementTemplateParamsHelper.SetActivePointSpecification (elementTemplateInstance, eACTIVEPOINTTYPE_Cell, WString (cellName), index)

def InitElementTemplate(elementTemplatePath, dgnFile):
    '''
    Initialize the element template for the given path
    
    :param elementTemplatePath: Full path of the element template
    :type elementTemplatePath: str
    :param dgnFile: Dgn file
    :type dgnFile: DgnFile

    :return: None
    '''

    templatePath = WString (elementTemplatePath)

    elementTemplate = ElementTemplateUtils.FindTemplateNodeByPath (templatePath.GetWCharCP(), dgnFile)
    if elementTemplate is None:
        print (f"Failed to Find ElementTemplate for {elementTemplatePath}")
        return
    
    elementTemplateInstance = elementTemplate.GetOrCreateDefaultInstance ()
    if elementTemplateInstance is None:
        print (f"Failed to get ElementTemplateInstance for {elementTemplatePath}")
        return

    cellName = "nodes_point"    
    searchAll = 1 # => 0=no, 1=yes w/o messages, 2=yes w/ messages
    retVal, library = Cell.FindCell(None, cellName, searchAll)
    if (BentleyStatus.eSUCCESS != retVal):
        celLibraryName = 'exampleCells.cel'
        dataDir = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\"
        fullFileName = path.join(dataDir, celLibraryName)    
        celLibraryFullName = BeFileName(fullFileName)
        if (BentleyStatus.eSUCCESS != Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryFullName, defaultDir=dataDir, fromKeyin=0)):
            print(f"Failed to attach cell library for cell: {celLibraryFullName}.")
            return

        retVal, library = Cell.FindCell(None, cellName, searchAll)
        if (BentleyStatus.eSUCCESS != retVal):
            print(f"Failed to find cell library for cell: {cellName}, status={retVal}.")
            return
        
    print(f"Found cell library for cell: {cellName}.")

    # Set the active point type to Cell and set the cell name
    SetElementTemplateActivePointCell(elementTemplateInstance, ISessionMgr.ActiveDgnModelRef, cellName)
    
    # Set the cell fixed size
    SetElementTemplateCellFixedSize(elementTemplateInstance, 0.5)

    result = ElementTemplateUtils.WriteTemplateNode (elementTemplate)
    if (eETSTATUS_Success != result):
        print(f"Failed to write Element Template ByPath: {str(templatePath)}, status={result}.")

    return

def ImportSHPFilePointGeometriesAsCellGeometries(fullFileName, dgnContainingExistingTemplate, elementTemplatePath):
    '''
    Import the SHP file containing point geometries as cell geometries.

    :param fullFileName: Full path of the SHP file containing point geometries
    :type fullFileName: str
    :param dgnContainingExistingTemplate: Dgn file containing the existing template
    :type dgnContainingExistingTemplate: DgnFile
    :param elementTemplatePath: Full path of the element template
    :type elementTemplatePath: str

    :return: None
    '''    

    shpFileMoniker = CreateDocumentMonikerFromFilePath(fullFileName)                                                   
    if shpFileMoniker is None:
        print (f"Failed to create DgnDocumentMoniker for {fullFileName}")
        return    

    flipCoordinates = False

    existingTemplateFullPath = WString(elementTemplatePath)
    existingTemplateFullPath.Trim()

    status, importSpec = ImportManager.GetManager().CreateSHPImportSpecification(shpFileMoniker, dgnContainingExistingTemplate, existingTemplateFullPath, flipCoordinates)
    if importSpec is None:
        print (f"Failed to create SHPImportSpecification for {fullFileName}, status={status}")
        return

    # Check if the element template exists. If not, create it from the SHPImportSpecification before importing the SHP file.
    #  I want to change line point geometry to cell point geometry during the import so I need to create and update the element template here before importing the SHP file.
    foundElementTemplate = ElementTemplateUtils.FindTemplateNodeByPath (existingTemplateFullPath.GetWCharCP(), dgnContainingExistingTemplate)
    if foundElementTemplate is None:
        status = importSpec.CreateDefaultElementTemplate()
        if (eGeospatialContextStatus_Success != status):
            print (f"SHPImportSpecification.CreateDefaultElementTemplate status={status}")
        else:
            # Initialize the element template by updating the cell name and cell fixed size.
            InitElementTemplate(elementTemplatePath, dgnContainingExistingTemplate)   
    else:
        print(f"Existing Element Template found {elementTemplatePath}.")

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

        dgnContainingExistingTemplate = ISessionMgr.ActiveDgnFile
        existingTemplateFullPath = "Geospatial\\mymons"

        # Import the SHP file using the existing element template           
        file = 'mymons.shp'
        dataDir = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\SHP\\"
        fullFileName = path.join(dataDir, file)

        print (f"Importing point geometries as cell geometries: {fullFileName}")
        ImportSHPFilePointGeometriesAsCellGeometries(fullFileName, dgnContainingExistingTemplate, existingTemplateFullPath)

    print("Script end...")
        