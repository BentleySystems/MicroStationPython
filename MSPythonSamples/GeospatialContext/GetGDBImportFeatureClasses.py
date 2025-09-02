from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
from GeospatialContextUtilities import *

'''
Sample demonstrating how to print feature classes in the GDBImportSpecification for a GDB folder
'''

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


def PrintGDBImportFeatureClasses(gdbFolderName):
    '''
    Print feature classes for the GDB folder GDBImportSpecification

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
        print(f"{i+1}. Feature class={featureClassName} DisplayName={featureDisplayName}")

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

        fullFolderName = os.path.dirname(os.path.abspath(__file__)) + "\\..\\data\\FGDB_Building.gdb\\"

        print (f"Printing feature classes for: {fullFolderName}")
        PrintGDBImportFeatureClasses(fullFolderName)

    print("Script end...")
        