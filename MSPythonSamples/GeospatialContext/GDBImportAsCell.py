from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from GeospatialContextUtilities import *

'''
Sample demonstrating how to import a GDB file containing point geometry as cell point geometry.

For import into a new DGN file where element template does not exist, the GDB file is imported by default with the line point geometry.
To import the GDB file with cell point geometry, the element template must be created and updated before importing the SHP file.

1. Ensure that Geographic Coordinate System is set in active model
2. Clear all imported features in the active model
3. Create the GDB Import specification for the GDB folder
4. Select the feature class to import
5. If element template does not exist, create it from the GDB Import specification by calling CreateDefaultElementTemplates
    a. Initialize the element template by updating the active point type to cell with cell name and cell fixed size
6. Import the GDB file
7. Fit active view

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

def CreateFolderMonikerFromFilePath (filePath):
    '''
    Create a DgnFolderMoniker from the file path

    :param filePath: Full path of the file
    :type filePath: str

    :return: DgnFolderMoniker for the file
    :rtype: DgnFolderMoniker
    '''    

    # Check if the file exists
    if not path.exists(filePath):
        print (f"File not found: {filePath}")
        return None

    base_file_name = os.path.basename(os.path.normpath(filePath))
    print (f"GDB folder Moniker: Base={base_file_name} Full={filePath} ")

    # Create a moniker from the raw data (file name and full path)
    return DgnFolderMoniker.CreateFromRawData (base_file_name, filePath, None, None, True, None)

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

def ImportGDBPointGeometriesAsCellGeometries(gdbFolderName):
    '''
    Import the GDB file containing point geometries as cell geometries.

    :param gdbFolderName: Full path of the GDB folder
    :type gdbFolderName: str

    :return: None
    '''    

    gdbFolderMoniker = CreateFolderMonikerFromFilePath(gdbFolderName)                                                   
    if gdbFolderMoniker is None:
        print (f"Failed to create DgnFolderMonikerPtr for {gdbFolderName}")
        return    

    status, importSpec = ImportManager.GetManager().CreateGDBImportSpecification(gdbFolderMoniker)
    if importSpec is None:
        print (f"Failed to create GDBImportSpecification for {gdbFolderName}, status={status}")
        return

    importFeatureSpecs = ImportFeatureSpecificationPtrArray()
    importSpec.GetImportFeatureSpecifications(importFeatureSpecs)
    if len(importFeatureSpecs) == 0:
        print("No features available for this ImportSpecification.")
        return

    print("Feature classes found in the dataset:")
    for i, spec in enumerate(importFeatureSpecs):
        featureClassName = str(spec.GetClassName()).strip()
        featureDisplayName = str(spec.GetDisplayName()).strip()
        # Select the point feature class to import
        if featureClassName == "mymons":
            spec.SetIsSelected(True)
        else:
            spec.SetIsSelected(False)
        print(f"{i+1}. Feature class={featureClassName} DisplayName={featureDisplayName} IsSelected={str(spec.GetIsSelected())}")

    # Check if the element template exists. If not, create it from the SHPImportSpecification before importing the SHP file.
    #  I want to change line point geometry to cell point geometry during the import so I need to create and update the element template here before importing the SHP file.
    dgnContainingExistingTemplate = ISessionMgr.ActiveDgnFile
    elementTemplatePath = "mytown.gdb\\mymons"
    existingTemplateFullPath = WString(elementTemplatePath)
    foundElementTemplate = ElementTemplateUtils.FindTemplateNodeByPath (existingTemplateFullPath.GetWCharCP(), dgnContainingExistingTemplate)
    if foundElementTemplate is None:
        status = importSpec.CreateDefaultElementTemplates()
        if (eGeospatialContextStatus_Success != status):
            print (f"GDBImportSpecification.CreateDefaultElementTemplates status={status}")
        else:
            # Initialize the element template by updating the cell name and cell fixed size.
            InitElementTemplate(elementTemplatePath, dgnContainingExistingTemplate)   
    else:
        print(f"Existing Element Template found {elementTemplatePath}.")

    status, nImported = importSpec.Import()
    print (f"Import {gdbFolderName}, status={status}, nImported={nImported}")

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
            
        fullFolderName = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\mytown.gdb\\"
        print (f"Importing: {fullFolderName}")
        ImportGDBPointGeometriesAsCellGeometries(fullFolderName)

        FitActiveView()

    print("Script end...")
        