# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *
import PSampUtility
import Constraint2d

'''
Example demonstrating how to create and place parametric cell
'''

CELL_MODEL = "CellModel"
PLACEMENT_MODEL = "PlacementModel"
CELL_FILE = "CellModels.dgn"

def saveFile(fileName):
    """
    Save the current active DGN file with the given file name.

    This function saves the current active DGN file to the specified file name
    within the current active DGN file path.

    :param fileName: The name to save the current active DGN file as.
    :type fileName: str
    
    :return: The path where the file was saved, or None if the save operation failed.
    :rtype: BeFileName or None
    """
    # Save current active dgn file as given file name to current active dgn file path
    path = BeFileName.GetDirectoryName(repr(ISessionMgr.GetActiveDgnFile().GetFileName()))
    path.AppendA(fileName)
    if (BentleyStatus.eSUCCESS != ISessionMgr.GetActiveDgnFile().DoSaveTo(str(path))):
        return None
    return path

def attachCellLib(libName):
    """
    This function attempts to attach a cell library specified by the given name.
    If the attachment is successful, it returns True. Otherwise, it returns False.
    
    :param libName: The name of the cell library to attach.
    :type libName: str
    
    :return: True if the cell library is successfully attached, False otherwise.
    :rtype: bool
    """
    libFileName = BeFileName() # filename name of cell library opened will be return
    if (BentleyStatus.eSUCCESS != Cell.AttachLibrary(libFileName, BeFileName(str(libName)), None, True)):
        return False

    return True

def getCellModelFromAttachedLib(libName, cellName):
    """
    Retrieves a cell model from an attached cell library.
    
    :param str libName: The name of the cell library.
    :param str cellName: The name of the cell to retrieve.
    
    :return: The cell model if found, otherwise None.
    :rtype: object or None
    """
    status, dgnFile = Cell.GetLibraryObject(str(libName), False) # Get cell library object by given name
    if (dgnFile is None):
        return None

    dgnFile.LoadDgnFile()
    dgnFile.FillDictionaryModel()

    # Load cell model by cell name
    cellModel, status = dgnFile.LoadRootModelById(dgnFile.FindModelIdByName(cellName), True, False, True)
    if (cellModel is None):
        return None

    return cellModel

def createCellDefInDgn(cellModel, dgnFile):
    """
    Create a cell definition in the target DGN file.

    :param cellModel: The cell model containing the definition handler.
    :type cellModel: object
    :param dgnFile: The target DGN file where the cell definition will be created.
    :type dgnFile: object
    
    :return: The result of the cell definition creation process.
    :rtype: object
    """
    # Get DefinitionModelHandler
    definitionModelHandler = cellModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    # Create a cell definition in target file
    return definitionModelHandler.CreateCellDefinition (dgnFile)

def placeParametricCellInModel(cellName, targetModel):
    """
    Places a parametric cell in the specified target model.
    
    :param cellName: The name of the parametric cell to be placed.
    :type cellName: str
    :param targetModel: The target model where the parametric cell will be placed.
    :type targetModel: ModelRef

    :return: The EditElementHandle of the placed parametric cell, or None if the placement failed.
    :rtype: EditElementHandle or None
    :raises: ValueError if the ParametricCellInfo creation fails due to a missing parameter set.
    """
    # Get target design file
    targetFile = targetModel.GetDgnFile()

    # Get cell definition from target file
    cellDefHandler = ParametricCellDefHandler.GetInstance()
    cellDef = cellDefHandler.GetCellDefinition(ElementHandle(cellDefHandler.FindByName(cellName, targetFile)))

    # Create ParametricCellInfo to initialize a new parametric cell element
    parameterSetName = "Small"
    status = MsPyParameterStatus(ParameterStatus.eError)
    cellInfo = ParametricCellInfo.Create(status, cellDef, parameterSetName, targetModel)
    if (cellInfo is None):
        print("ParametricCellInfo creation failed with parameter set: " + parameterSetName + "Please make sure the parameter set exist.")
        return None

    cellHandler = ParametricCellHandler.GetInstance()
    cellEeh = EditElementHandle()
    # Create cell element by ParametricCellInfo
    if (ParameterStatus.eSuccess != cellHandler.CreateCellElement (cellEeh, cellInfo)):
        return None

    # Set placement position (50000, 50000, 0)
    transform = Transform()
    transform.SetTranslation(DPoint3d(50000, 50000, 0))
    transformInfo = TransformInfo(transform)
    cellHandler.ApplyTransform(cellEeh, transformInfo)

    # Add cell element to model
    cellEeh.AddToModel()

    # Switch to target model
    ModelRef.ActivateAndDisplay(targetModel)

    return cellEeh

def ExampleCreateAndPlaceParametricCell():
    """
    Creates a parametric cell model, defines it in a target DGN file, and places the parametric cell in the target model.
    This function performs the following steps:
    1. Creates a cell model using `PSampUtility.GetOrCreateModel`.
    2. Creates a parametric solid in the cell model using `Constraint2d.ExampleExtrudeFeatureWithRadiusConstraint`.
    3. Creates a target model in which the parametric cell will be placed using `PSampUtility.GetOrCreateModel`.
    4. Defines the cell in the target DGN file using `createCellDefInDgn`.
    5. Places the parametric cell in the target model using `placeParametricCellInModel`.
    
    :return: The result of `placeParametricCellInModel`, or None if the parametric solid creation fails.
    :rtype: object or None
    """
    # Create cell model
    cellModel = PSampUtility.GetOrCreateModel(CELL_MODEL, True)
    # create parametric solid in cell model
    if(Constraint2d.ExampleExtrudeFeatureWithRadiusConstraint(cellModel) is None):
        return None

    # Create target model and cell definition in target dgn file
    targetModel = PSampUtility.GetOrCreateModel(PLACEMENT_MODEL, True) # Create target model in which the parametric cell will be placed
    createCellDefInDgn(cellModel, targetModel.GetDgnFile()) # Create cell definition in target dgn file

    # Place the parametric cell in target model
    return placeParametricCellInModel(CELL_MODEL, targetModel)


def ExampleCreateAndPlaceParametricCellFromDgn():
    """
    Example function to create and place a parametric cell from a DGN file.
    This function performs the following steps:
    1. Creates a cell model.
    2. Creates a parametric solid in the cell model with a radius constraint.
    3. Saves the file as a cell library.
    4. Attaches the cell library.
    5. Retrieves the cell model from the attached cell library.
    6. Creates a target model and cell definition in the target DGN file.
    7. Places the parametric cell in the target model.
    
    Returns:
        None
    """
    # Create cell model
    cellModel = PSampUtility.GetOrCreateModel(CELL_MODEL, True)
    # create parametric solid in cell model
    if(Constraint2d.ExampleExtrudeFeatureWithRadiusConstraint(cellModel) is None):
        return

    # Save file as the cell library
    path = saveFile(CELL_FILE)
    if (path is None):
        return

    # Attach cell library
    if (not attachCellLib(path)):
        return

    # Get cell model from attached cell library
    cellModelInLib = getCellModelFromAttachedLib(path, CELL_MODEL)
    if (cellModelInLib is None):
        return

    # Create target model and cell definition in target dgn file
    targetModel = PSampUtility.GetOrCreateModel(PLACEMENT_MODEL, True) # Create target model in which the parametric cell will be placed
    createCellDefInDgn(cellModelInLib, targetModel.GetDgnFile()) # Create cell definition in target dgn file

    # Place the parametric cell in target model
    placeParametricCellInModel(CELL_MODEL, targetModel)

def ExampleChangeRadiusAfterPlacement():
    """
    ExampleChangeRadiusAfterPlacement
    This function demonstrates how to change the radius of a placed parametric cell
    after it has been created and placed. It performs the following steps:
    1. Creates and places a parametric cell using the ExampleCreateAndPlaceParametricCell function.
    2. Retrieves an instance of the ParametricCellHandler.
    3. Obtains the cell information for the placed parametric cell.
    4. Sets a new radius value for the parametric cell.
    5. Writes the updated values back to the parametric cell.
    Note:
        The function assumes that the ExampleCreateAndPlaceParametricCell function and the 
        ParametricCellHandler class are defined elsewhere in the codebase.
    
    Raises:
        Any exceptions raised by the underlying functions and methods used within this function.
    """
    # Create and place parametric cell
    cellEeh = ExampleCreateAndPlaceParametricCell()

    # Change radius variable value of the placed parametric cell
    cellHandler = ParametricCellHandler.GetInstance()
    status = MsPyParameterStatus(ParameterStatus.eError)
    cellInfo = cellHandler.GetCellInfo(status, cellEeh)

    ecValue = ECValue()
    ecValue.SetDouble(5.5);
    cellInfo.SetValue("_LOCAL_Radius", ecValue)
    cellInfo.WriteValues()

def RunSamples(index = 1):
    """
    Run sample functions based on the provided index.

    :param index: The index of the sample function to run. 
                  Defaults to 1.
                  - 1: Run ExampleCreateAndPlaceParametricCell
                  - 2: Run ExampleCreateAndPlaceParametricCellFromDgn
                  - 3: Run ExampleChangeRadiusAfterPlacement
    :type index: int
    """
    if (1 == index):
        ExampleCreateAndPlaceParametricCell()
    elif(2 == index):
        ExampleCreateAndPlaceParametricCellFromDgn()
    elif(3 == index):
        ExampleChangeRadiusAfterPlacement()

if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    RunSamples(3)
