from os import *
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating exporting a GDB file by element template, element level, and item type.

1. Ensure that Geographic Coordinate System is set in active model
2. Add data to export.
    a. Clear all imported features in the active model
    b. Create a DgnDocumentMoniker from the file path
    c. Import SHP files to the active model
3. Export the GDB file by element template
4. Export the GDB file by element level
5. Export the GDB file by item type

'''
    
def CreateFolderMonikerFromFilePath (filePath):
    '''
    Create a DgnFolderMoniker from the file path

    :param filePath: Full path of the file
    :type filePath: str

    :return: DgnFolderMoniker for the file
    :rtype: DgnFolderMoniker
    '''    

    try:
        os.makedirs(filePath, exist_ok=True)
    except OSError as e:
        print(f"Error creating directory: {e}")
        return None

    # Check if the file exists
    if not path.exists(filePath):
        print (f"File not found: {filePath}")
        return None

    base_file_name = os.path.basename(os.path.normpath(filePath))
    print (f"Folder Moniker: Base={base_file_name} Full={filePath} ")

    # Create a moniker from the raw data (file name and full path)
    return DgnFolderMoniker.CreateFromRawData (base_file_name, filePath, None, None, True, None)

def PrintGDBExportSpecification(exportSpec):
    '''
    Print the GDB export specification

    :param exportSpec: GDB export specification
    :type exportSpec: GDBExportSpecification

    :return: None
    '''

    print ("==================================================================")
    print ("GDBExportSpecification:")

    assert (exportSpec.GetElementFilterMode() == exportSpec.ElementFilterMode)
    assert (exportSpec.GetUseFenceOverlap() == exportSpec.UseFenceOverlap)
    assert (exportSpec.GetIncludeReferenceFiles() == exportSpec.IncludeReferenceFiles)
    assert (exportSpec.GetPreserveZ() == exportSpec.PreserveZ)
    assert (exportSpec.GetFacetCurves() == exportSpec.FacetCurves)
    assert (exportSpec.GetMaxChordHeight() == exportSpec.MaxChordHeight)
    assert (exportSpec.GetExportTextString() == exportSpec.ExportTextString)

    print (f"ElementFilterMode={exportSpec.GetElementFilterMode()}")
    print (f"FolderMoniker={exportSpec.GetFolderMoniker()}")
    print (f"    {exportSpec.GetFolderMoniker().GetSavedFolderName()}")
    print (f"UseFenceOverlap={exportSpec.GetUseFenceOverlap()}")
    print (f"IncludeReferenceFiles={exportSpec.GetIncludeReferenceFiles()}")
    print (f"PreserveZ={exportSpec.GetPreserveZ()}")
    print (f"FacetCurves={exportSpec.GetFacetCurves()}")
    print (f"MaxChordHeight={exportSpec.GetMaxChordHeight()}")
    print (f"ExportTextString={exportSpec.GetExportTextString()}")

    elementTemplateNames = WStringArray()
    exportSpec.GetElementTemplateNames(elementTemplateNames)
    if len(elementTemplateNames) == 0:
        print("ElementTemplateNames: None")
    else:
        print (f"ElementTemplateNames: Count={len(elementTemplateNames)}")
        for i in range(len(elementTemplateNames)):
            print (f"     {i+1}. {str(elementTemplateNames[i])}")
    
    itemTypes = ItemTypeSpecificationPtrArray()
    exportSpec.GetItemTypeNames(itemTypes)
    if len(itemTypes) == 0:
        print("ItemTypes: None")
    else:
        print (f"ItemTypes: Count={len(itemTypes)}")
        for i, itemType in enumerate(itemTypes):
            lib_name = str(itemType.GetItemTypeLibraryName()).strip()
            item_name = str(itemType.GetItemTypeName()).strip()
            print (f"     {i+1}. {lib_name}:{item_name} {itemType.GetItemTypeDgnFile()}")

    levelNames = LevelSpecificationPtrArray()
    exportSpec.GetLevelNames(levelNames)
    if len(levelNames) == 0:
        print("LevelNames: None")
    else:
        print (f"LevelNames: Count={len(levelNames)}")
        for i, levelName in enumerate(levelNames):
            level_name = str(levelName.GetLevelName()).strip()
            print (f"     {i+1}. {level_name} {levelName.GetDgnFile()}")

    print ("==================================================================")

def ExportGDBByElementTemplate(fullFolderName, existingTemplateFullPathlist):
    '''
    Export GDB to the full folder path by element template path

    :param fullFolderName: Full folder path
    :type fullFolderName: str
    :param existingTemplateFullPathlist: List of Full paths of the element templates
    :type existingTemplateFullPathlist: List[str]
    :return: None
    '''    

    gdbFolderMoniker = CreateFolderMonikerFromFilePath(fullFolderName)                                                   
    if gdbFolderMoniker is None:
        print (f"Failed to create DgnDocumentMoniker for {fullFolderName}")
        return    

    flipCoordinates = False

    dgnContainingExistingTemplate = None

    status, exportSpec = ExportManager.GetManager().CreateGDBExportSpecification(eExportElementFilterMode_ByElementTemplate)
    if exportSpec is None:
        print (f"Failed to create GDBExportSpecification for {fullFolderName}, status={status}")
        return

    exportSpec.SetFolderMoniker(gdbFolderMoniker)
  
    exportSpec.SetUseFenceOverlap(False)
    exportSpec.SetIncludeReferenceFiles(False)
    exportSpec.SetPreserveZ(False)
    exportSpec.SetFacetCurves(False)
    exportSpec.SetMaxChordHeight(0.0)
    exportSpec.SetExportTextString(True)

    for elementTemplatePath in existingTemplateFullPathlist:
        existingTemplateFullPath = WString(elementTemplatePath)
        exportSpec.AddElementTemplateName(existingTemplateFullPath)

    PrintGDBExportSpecification(exportSpec)

    status, nExported = exportSpec.Export()
    print (f"Export to {fullFolderName}, status={status}, nExported={nExported}")


def ExportGDBByLevel(fullFolderName, existingLevelNamelist):
    '''
    Export GDB to the full folder path by element level name

    :param fullFolderName: Full folder path
    :type fullFolderName: str
    :param existingLevelNamelist: List of element level names
    :type existingLevelNamelist: List[str]

    :return: None
    '''    

    gdbFolderMoniker = CreateFolderMonikerFromFilePath(fullFolderName)                                                   
    if gdbFolderMoniker is None:
        print (f"Failed to create DgnDocumentMoniker for {fullFolderName}")
        return    

    flipCoordinates = False

    dgnContainingExistingTemplate = None

    status, exportSpec = ExportManager.GetManager().CreateGDBExportSpecification(eExportElementFilterMode_ByLevel)
    if exportSpec is None:
        print (f"Failed to create GDBExportSpecification for {fullFolderName}, status={status}")
        return
        
    exportSpec.SetFolderMoniker(gdbFolderMoniker)

    exportSpec.SetUseFenceOverlap(False)
    exportSpec.SetIncludeReferenceFiles(False)
    exportSpec.SetPreserveZ(False)
    exportSpec.SetFacetCurves(False)
    exportSpec.SetMaxChordHeight(0.0)
    exportSpec.SetExportTextString(True)

    for levelName in existingLevelNamelist:
        existingLevelName = WString(levelName)
        exportSpec.AddLevelName(ISessionMgr.ActiveDgnFile, existingLevelName)

    PrintGDBExportSpecification(exportSpec)

    status, nExported = exportSpec.Export()
    print (f"Export to {fullFolderName}, status={status}, nExported={nExported}")


def ExportGDBByItemType(fullFolderName, existingItemTypeList):
    '''
    Export GDB to the full folder path by Item Type Library and Item Type Name

    :param fullFolderName: Full folder path
    :type fullFolderName: str
    :param existingItemTypeList: List of Item Type Name
    :type existingItemTypeList: List[str]

    :return: None
    '''    

    gdbFolderMoniker = CreateFolderMonikerFromFilePath(fullFolderName)                                                   
    if gdbFolderMoniker is None:
        print (f"Failed to create DgnDocumentMoniker for {fullFolderName}")
        return    

    flipCoordinates = False

    dgnContainingExistingTemplate = None

    status, exportSpec = ExportManager.GetManager().CreateGDBExportSpecification(eExportElementFilterMode_ByItemType)
    if exportSpec is None:
        print (f"Failed to create GDBExportSpecification for {fullFolderName}, status={status}")
        return

    exportSpec.SetFolderMoniker(gdbFolderMoniker)

    exportSpec.SetUseFenceOverlap(False)
    exportSpec.SetIncludeReferenceFiles(False)
    exportSpec.SetPreserveZ(False)
    exportSpec.SetFacetCurves(False)
    exportSpec.SetMaxChordHeight(0.0)
    exportSpec.SetExportTextString(True)

    for sublist in existingItemTypeList:
        existingItemTypeLibraryName = WString(sublist[0])
        existingItemTypeName = WString(sublist[1])
        exportSpec.AddItemTypeName(ISessionMgr.ActiveDgnFile, existingItemTypeLibraryName, existingItemTypeName)

    PrintGDBExportSpecification(exportSpec)

    status, nExported = exportSpec.Export()
    print (f"Export to {fullFolderName}, status={status}, nExported={nExported}")

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
    print (f"File Moniker: Base={base_file_name} type={type(base_file_name)} Full={filePath} type={type(filePath)} ")

    # Create a moniker from the raw data (file name and full path)
    return DgnDocumentMoniker.CreateFromRawData (base_file_name, filePath, None, None, True, None)

def ImportSHPFile(fullFileName, elementTemplatePath):
    '''
    Import the SHP file for the full file path

    :param fullFileName: Full path of the SHP file
    :type fullFileName: str
    :param elementTemplatePath: Full path of the element template
    :type elementTemplatePath: str

    :return: None
    '''    

    shpFileMoniker = CreateDocumentMonikerFromFilePath(fullFileName)                                                   
    if shpFileMoniker is None:
        print (f"Failed to create DgnDocumentMoniker for {fullFileName}")
        return    

    flipCoordinates = False

    dgnContainingExistingTemplate = None
    existingTemplateFullPath = WString("")  # Pass full path to an existing element template

    status, importSpec = ImportManager.GetManager().CreateSHPImportSpecification(shpFileMoniker, dgnContainingExistingTemplate, existingTemplateFullPath, flipCoordinates)
    if importSpec is None:
        print (f"Failed to create SHPImportSpecification for {fullFileName}, status={status}")
        return
        
    status, nImported = importSpec.Import()
    print (f"Import {fullFileName}, status={status}, nImported={nImported}")

def AddDataToExport():
    '''
    Create data for export.
    Import example SHP files to the active model.

    :return: None
    :rtype: None
    '''
    # Get the active model reference
    modelRef = ISessionMgr.ActiveDgnModelRef
    
    # Clear all imported features in the active model
    nCleared = ClearImportedFeatures(modelRef)
    print (f"Cleared {nCleared} imported features.")    

    # Import a SHP files            
    dataDir = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\SHP\\"

    file = 'mystreets.shp'
    fullFileName = path.join(dataDir, file)
    print (f"Importing: {fullFileName}")
    existingTemplateFullPath = ""
    ImportSHPFile(fullFileName, existingTemplateFullPath)

    file = 'mymons.shp'
    fullFileName = path.join(dataDir, file)
    print (f"Importing: {fullFileName}")
    existingTemplateFullPath = ""
    ImportSHPFile(fullFileName, existingTemplateFullPath)

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

        # Add data to active model for export
        AddDataToExport()

        # Export the GDB file         
        exportBaseFolder = WString ()
        status = ConfigurationManager.GetVariable (exportBaseFolder,"_USTN_OUT")
        if(BentleyStatus.eSUCCESS == status):
            exportBaseFolder.AppendA("GDBExport\\")

            existingTemplateFullPathlist = ["Geospatial\\mystreets", "Geospatial\\mymons"]
            exportFolder = str(exportBaseFolder) + "GDBExportByElementTemplate.gdb\\"
            print (f"Exporting GDB to folder: {exportFolder} by element templates: {existingTemplateFullPathlist}")
            ExportGDBByElementTemplate(exportFolder, existingTemplateFullPathlist)

            existingItemTypeList = [ ["Geospatial", "mystreets"], ["Geospatial", "mymons"]]
            exportFolder = str(exportBaseFolder) + "GDBExportByItemType.gdb\\"
            print (f"Exporting GDB to folder: {exportFolder} by item types: {existingItemTypeList}")
            ExportGDBByItemType(exportFolder, existingItemTypeList)            

            existingLevelNamelist = ["mystreets", "mymons"]
            exportFolder = str(exportBaseFolder) + "GDBExportByLevel.gdb\\"
            print (f"Exporting GDB to folder: {exportFolder} by element levels: {existingLevelNamelist}")
            ExportGDBByLevel(exportFolder, existingLevelNamelist)            
        else:
            print (f"Failed to get _USTN_OUT variable, status={status}")


    print("Script end...")
        