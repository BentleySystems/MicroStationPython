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


CELL_MODEL = "CellModel"
PLACEMENT_MODEL = "PlacementModel"
CELL_FILE = "CellModels.dgn"

'''
Save file and return the file path
'''
def saveFile(fileName):
    # Save current active dgn file as given file name to current active dgn file path
    path = BeFileName.GetDirectoryName(repr(ISessionMgr.GetActiveDgnFile().GetFileName()))
    path.AppendA(fileName)
    if (BentleyStatus.eSUCCESS != ISessionMgr.GetActiveDgnFile().DoSaveTo(str(path))):
        return None
    return path

'''
Attach the cell library by given name. 
Name may contain a path specification, if it does not, then MS_CELL and defaultDir (if defined) are searched for the file. 
If this parameter is NULL, then the active library is detached.
'''
def attachCellLib(libName):
    libFileName = BeFileName() # filename name of cell library opened will be return
    if (BentleyStatus.eSUCCESS != Cell.AttachLibrary(libFileName, BeFileName(str(libName)), None, True)):
        return False

    return True

'''
Get cell model from attached cell library
'''
def getCellModelFromAttachedLib(libName, cellName):
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

'''
Function to Create cell definition in design file
'''
def createCellDefInDgn(cellModel, dgnFile):
    # Get DefinitionModelHandler
    definitionModelHandler = cellModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    # Create a cell definition in target file
    return definitionModelHandler.CreateCellDefinition (dgnFile)

'''
Function to define parametric cell from cell model in target model design file, then place the parametric cell in target model
'''
def placeParametricCellInModel(cellName, targetModel):
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

'''
Example to create and place parametric cell
'''
def ExampleCreateAndPlaceParametricCell():
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

'''
Example to create and place parametric cell from dgn
'''
def ExampleCreateAndPlaceParametricCellFromDgn():
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

'''
Example to create and place parametric cell, and then change it's radius
'''
def ExampleChangeRadiusAfterPlacement():
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
    if (1 == index):
        ExampleCreateAndPlaceParametricCell()
    elif(2 == index):
        ExampleCreateAndPlaceParametricCellFromDgn()
    elif(3 == index):
        ExampleChangeRadiusAfterPlacement()

if __name__ == "__main__":
    SmartFeatureUtil.InitSmartFeature()
    RunSamples(3)
