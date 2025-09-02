from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def placeCell():
    
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()    


    celLibraryName = BeFileName(r"C:\ProgramData\Bentley\PowerPlatformPython\Examples\Microstation\data\exampleCells.cel")
    Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryName, defaultDir=r"C:\ProgramData\Bentley\PowerPlatformPython\Examples\Microstation\data", fromKeyin=0)

    cellName = "gas_valve"    
    searchAll = 1 # => 0=no, 1=yes w/o messages, 2=yes w/ messages
    retVal, library = Cell.FindCell(None, cellName, searchAll)
    origin = DPoint3d(0, 0, 0)  # Origin point for cell placement
    scale = DPoint3d(1, 1, 1)  # Scale for cell placement
    rotMatrix = RotMatrix ()
    rotMatrix.InitIdentity()  # Identity rotation matrix
    relativeMode = False  # Relative mode flag for cell placement
    
    if (BentleyStatus.eSUCCESS != retVal):
        print(f"Error finding cell {cellName} in library")
        return
    try:
        result = Cell.PlaceCell(
            origin=origin,  # Origin point of the cell
            scale=scale,  # Scale of the cell
            trueScale=True,  # True scale flag
            rotMatrix=rotMatrix,  # Rotation matrix for orientation
            attributes=0,  # Cell attributes
            ggroup=0,  # Graphic group number
            relativeMode=relativeMode,  # Relative mode flag
            baseLevel=0,  # Level ID for the cell
            sharedFlag=0,  # Shared cell flag
            cellName=cellName,  # Name of the cell
            library=library  # Reference to the DGN file library
        )
    except Exception as e:
        print(f"Error placing cell: {e}")  # Print any error that occurs during cell placement
    

def placeParametricCell():
    
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()    


    celLibraryName = BeFileName(r"C:\ProgramData\Bentley\PowerPlatformPython\Examples\Microstation\data\exampleCells.cel")
    Cell.AttachLibrary(fileName=BeFileName(), inputName=celLibraryName, defaultDir=r"C:\ProgramData\Bentley\PowerPlatformPython\Examples\Microstation\data", fromKeyin=0)

    cellName = "Barrier01"    
    searchAll = 1 # => 0=no, 1=yes w/o messages, 2=yes w/ messages
    retVal, library = Cell.FindCell(None, cellName, searchAll)
    origin = DPoint3d(0, 0, 0)  # Origin point for cell placement
    scale = DPoint3d(1, 1, 1)  # Scale for cell placement
    rotMatrix = RotMatrix ()
    rotMatrix.InitIdentity()  # Identity rotation matrix
    relativeMode = False  # Relative mode flag for cell placement
    
    if (BentleyStatus.eSUCCESS != retVal):
        print(f"Error finding cell {cellName} in library")
        return
    try:
        result = Cell.PlaceCell(
            origin=origin,  # Origin point of the cell
            scale=scale,  # Scale of the cell
            trueScale=True,  # True scale flag
            rotMatrix=rotMatrix,  # Rotation matrix for orientation
            attributes=0,  # Cell attributes
            ggroup=0,  # Graphic group number
            relativeMode=relativeMode,  # Relative mode flag
            baseLevel=0,  # Level ID for the cell
            sharedFlag=0,  # Shared cell flag
            cellName=cellName,  # Name of the cell
            library=library  # Reference to the DGN file library
        )
    except Exception as e:
        print(f"Error placing cell: {e}")  # Print any error that occurs during cell placement
 
    
if __name__ == "__main__":
    placeCell()  # Call the function to place cells along the B-spline curve
    placeParametricCell()
