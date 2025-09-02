from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from GeospatialContextUtilities import *

'''
Sample demonstrating how to import a GDB file

1. Ensure that Geographic Coordinate System is set in active model
2. Clear all imported features in the active model
3. Create a DgnFolderMoniker from the file path
4. Import the GDB file
5. Fit active view

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


def ImportGDB(gdbFolderName):
    '''
    Import the GDB for the folder path

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
        spec.SetIsSelected(True)
        print(f"{i+1}. Feature class={featureClassName} DisplayName={featureDisplayName} IsSelected={str(spec.GetIsSelected())}")

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
            
        fullFolderName = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\States.gdb\\"
        print (f"Importing: {fullFolderName}")
        ImportGDB(fullFolderName)

        FitActiveView()

    print("Script end...")
        