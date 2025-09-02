from os import *
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Sample demonstrating importing a SHP file

1. Ensure that Geographic Coordinate System is set in active model
2. Clear all imported features in the active model
3. Create a DgnDocumentMoniker from the file path
4. Import the SHP file
5. Fit active view

'''
def FitActiveView():
    '''
    Fit active view

    :return: None
    :rtype: None
    '''
    
    vSet = IViewManager.GetActiveViewSet()  # Get the active view set
    if vSet is None:
        print(f"Failed to get ActiveViewSet.")
        return
    view_number = 1
    viewport = IViewManager.GetActiveViewSet().GetSelectedViewport()
    if not viewport is None:
        view_number = viewport.GetViewNumber() # Get the active view index   

    keyin = "FIT VIEW EXTENDED " + str(view_number+1)
    PyCadInputQueue.SendKeyin (keyin)
    print(f"Sent keyin to fit view: {keyin}.")
    
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

def ImportExampleSHPFile(clearExistingImportedFeatures = True):
    '''
    Import an example SHP file

    :param clearExistingImportedFeatures: Clear existing imported features
    :type clearExistingImportedFeatures: bool

    :return: None
    :rtype: None
    '''
    if clearExistingImportedFeatures == True:
        # Get the active model reference
        modelRef = ISessionMgr.ActiveDgnModelRef
        
        # Clear all imported features in the active model
        nCleared = ClearImportedFeatures(modelRef)
        print (f"Cleared {nCleared} imported features.")    

    # Import the SHP file            
    file = 'mystreets.shp'
    existingTemplateFullPath = ""
    dataDir = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\SHP\\"
    fullFileName = path.join(dataDir, file)
    print (f"Importing: {fullFileName}")
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

        ImportExampleSHPFile(True)

        # Fit active view
        FitActiveView()

    print("Script end...")
        