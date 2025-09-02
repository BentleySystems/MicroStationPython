# -*- coding: utf-8 -*-
'''
/*--------------------------------------------------------------------------------------+
| $Copyright: (c) 2024 Bentley Systems, Incorporated. All rights reserved. $
+--------------------------------------------------------------------------------------*/
'''

import math
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

'''
Examples demonstrates how to CRUD variables
'''

def CreateVariable(name, type, value, dgnModel):
    """
    Creates a variable in the given design model.
    
    :param name: The name of the variable to be created.
    :type name: str
    :param type: The type of the variable.
    :type type: str
    :param value: The initial value of the variable.
    :type value: Any
    :param dgnModel: The design model where the variable will be created.
    :type dgnModel: DgnModel
    
    :return: The status of the variable creation process.
    :rtype: ParameterStatus
    :raises: ParameterStatus.eError if the design model or any required handler is None.
             ParameterStatus.eDuplicateName if a variable with the given name already exists.
    """
    if (dgnModel is None):
        return ParameterStatus.eError

    # Get DefinitionModelHandler
    definitionModelHandler = dgnModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    if (definitionModelHandler is None):
        return ParameterStatus.eError

    # Get EditParameterDefinitions
    editParameterDefinitions = definitionModelHandler.GetParameterDefinitions().GetForEdit()
    if (editParameterDefinitions is None):
        return ParameterStatus.eError

    # Check whether a variable with given name has already been defined, if yes, return DuplicateName status
    paramDef = ParameterDefinition()
    if (ParameterStatus.eSuccess == editParameterDefinitions.FindByLabel (paramDef, name)):
        return ParameterStatus.eDuplicateName
    
    # Add variable in model
    return editParameterDefinitions.Add(name, type, value, False)

def RemoveVariable(name, dgnModel):
    """
    Removes a variable with the given name from the specified DGN model.
    
    :param name: The name of the variable to be removed.
    :type name: str
    :param dgnModel: The DGN model from which the variable will be removed.
    :type dgnModel: DgnModel
    
    :return: The status of the operation.
    :rtype: ParameterStatus
    :raises ValueError: If dgnModel is None or if definitionModelHandler is None or if editParameterDefinitions is None.
    """
    if (dgnModel is None):
        return ParameterStatus.eError

    # Get DefinitionModelHandler
    definitionModelHandler = dgnModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    if (definitionModelHandler is None):
        return ParameterStatus.eError

    # Get EditParameterDefinitions
    editParameterDefinitions = definitionModelHandler.GetParameterDefinitions().GetForEdit()
    if (editParameterDefinitions is None):
        return ParameterStatus.eError

    # Check whether a variable with given name is defined, if no, return DuplicateName status
    paramDef = ParameterDefinition()
    status = editParameterDefinitions.FindByLabel(paramDef, name)
    if (ParameterStatus.eSuccess != status):
        return status

    # Remove variable in dgn model
    return editParameterDefinitions.Remove(paramDef.GetAccessString())

def CreateVariation(name, desc, dgnModel):
    """
    Creates a variation with the given name and description in the specified design model.
    
    :param name: The name of the variation to be created.
    :type name: str
    :param desc: The description of the variation to be created.
    :type desc: str
    :param dgnModel: The design model in which the variation is to be created.
    :type dgnModel: DgnModel
    
    :return: The status of the parameter creation process.
    :rtype: ParameterStatus
    
    :raises ValueError: If the dgnModel is None.
    :raises ValueError: If the definitionModelHandler is None.
    :raises ValueError: If the editParameterDefinitions is None.
    :raises ValueError: If a parameter set with the given name already exists.
    """
    if (dgnModel is None):
        return ParameterStatus.eError

    # Get DefinitionModelHandler
    definitionModelHandler = dgnModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    if (definitionModelHandler is None):
        return ParameterStatus.eError

    # Get EditParameterDefinitions
    editParameterDefinitions = definitionModelHandler.GetParameterDefinitions().GetForEdit()
    if (editParameterDefinitions is None):
        return ParameterStatus.eError

    # Check whether a parameter set with given name already exist, if yes, return DuplicateName status
    parameterSets = definitionModelHandler.GetParameterSets()
    parameterSet = parameterSets.FindByName(name)
    if (parameterSet is not None):
        return ParameterStatus.eDuplicateName

    # Create parameter set
    status, parameterSet = definitionModelHandler.CreateParameterSet(name, desc, editParameterDefinitions)
    return status

def RemoveVariation(name, dgnModel):
    """
    Remove a variation from the given design model.
    
    :param name: The name of the parameter set to be removed.
    :type name: str
    :param dgnModel: The design model from which the variation will be removed.
    :type dgnModel: DgnModel
    
    :return: The status of the operation.
    :rtype: ParameterStatus
    
    :raises: None
    """
    if (dgnModel is None):
        return ParameterStatus.eError

    # Get DefinitionModelHandler
    definitionModelHandler = dgnModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    if (definitionModelHandler is None):
        return ParameterStatus.eError

    # Check whether a parameter set with given name exist, if no, return ParameterSetNotFound status
    parameterSets = definitionModelHandler.GetParameterSets()
    parameterSet = parameterSets.FindByName(name)
    if (parameterSet is None):
        return ParameterStatus.eParameterSetNotFound

    # Delete variation in model
    return definitionModelHandler.DeleteParameterSet(parameterSet)

def ExportVariables(dgnModel, csvPath):
    """
    Export variables from a DGN model to a CSV file.
    
    :param dgnModel: The DGN model from which to export variables.
    :type dgnModel: DgnModel
    :param csvPath: The file path where the CSV file will be saved.
    :type csvPath: str
    
    :return: True if the export was successful, False otherwise.
    :rtype: bool
    """
    if (dgnModel is None):
        return False

    # Get ParameterDefinitions
    defs = IParameterDefinitions.GetForModel (dgnModel)
    if (defs is None):
        return False

    # Open csv file for writing
    csvFile, status = BeTextFile.Open(csvPath, TextFileOpenType.eWrite, TextFileOptions.eNone_, TextFileEncoding.eCurrentLocale)
    if (csvFile is None):
        return False

    sections = ParameterCsvSectionPresenceFlags()
    sections.SetAll()
    if (TextFileWriteStatus.eSuccess != defs.WriteToCsv (csvFile, sections)): # Write variables to csv file
        return False

    # Close csv file
    csvFile.Close()
    return True

def ImportVariables(dgnModel, csvPath):
    """
    Imports variables from a CSV file into the given DGN model.
    
    :param dgnModel: The DGN model to which the variables will be imported.
    :type dgnModel: DgnModel
    :param csvPath: The file path of the CSV file containing the variables.
    :type csvPath: str
    
    :return: True if the variables were successfully imported, False otherwise.
    :rtype: bool
    """
    if (dgnModel is None):
        return False

    # Get EditParameterDefinitions
    editDefs = IParameterDefinitions.GetForModel(dgnModel).GetForEdit()
    if (editDefs is None):
        return False

    # Open csv file for reading
    csvFile, status = CsvFile.Open(csvPath)
    if (csvFile is None):
        return False

    mask = ParameterCsvSectionPresenceFlags()
    mask.SetAll();

    context = ParameterCsvReadContext(mask)
    editDefs.ReadFromCsv (csvFile, context) # Read variables from csv file and add to parameter definitions

    return True

def SetVariableValueInParameterSet(setName, varName, varValue, dgnModel):
    """
    Sets the value of a variable in a specified parameter set within a DGN model.
    
    :param setName: The name of the parameter set.
    :type setName: str
    :param varName: The name of the variable.
    :type varName: str
    :param varValue: The value to set for the variable.
    :type varValue: Any
    :param dgnModel: The DGN model object.
    :type dgnModel: DgnModel
    
    :return: True if the variable value was successfully set, False otherwise.
    :rtype: bool
    """
    if (dgnModel is None):
        return ParameterStatus.eError

    # Get DefinitionModelHandler
    definitionModelHandler = dgnModel.GetDgnComponentDefinitionHandler().GetDefinitionModelHandler()
    if (definitionModelHandler is None):
        return ParameterStatus.eError

    # Get EditParameterDefinitions
    editParameterDefinitions = definitionModelHandler.GetParameterDefinitions().GetForEdit()
    if (editParameterDefinitions is None):
        return ParameterStatus.eError

    # Check whether a parameter set with given name exist, if no, return false
    parameterSets = definitionModelHandler.GetParameterSets()
    parameterSet = parameterSets.FindByName(setName)
    if (parameterSet is None):
        return False

    # Check whether a variable with given name exist, if no, return false
    paramDef = ParameterDefinition()
    if (ParameterStatus.eSuccess != editParameterDefinitions.FindByLabel(paramDef, varName)):
        return False

    # Set variable value in the parameter set and write to dgn model
    parameterSet.SetValue(paramDef.GetAccessString(), ECValue(varValue))
    if (ParameterStatus.eSuccess != parameterSet.WriteValues()):
        return False

    return True

def CreateVariableWithExpression(name, type, value, expression, dgnModel):
    """
    Create a variable with an expression in the specified design model.
    
    :param name: The name of the variable to create.
    :type name: str
    :param type: The type of the variable.
    :type type: str
    :param value: The initial value of the variable.
    :type value: any
    :param expression: The expression to associate with the variable.
    :type expression: str
    :param dgnModel: The design model in which to create the variable.
    :type dgnModel: object
    
    :return: True if the variable and expression were successfully created and evaluated, False otherwise.
    :rtype: bool
    """
    if (dgnModel is None):
        return False

    defs = IParameterDefinitions.GetForModel(dgnModel).GetForEdit()

    # Create variables and get parameter definition
    CreateVariable(name, type, value, dgnModel)
    paramDef = ParameterDefinition()
    defs.FindByLabel(paramDef, name) # get the paramDef

    # Add expressions to variables
    exphdlr = defs.GetExpressionHandler()
    context = IParseParameterExpressionContext.Create (defs, type)
    defs.SetExpressionForParameter(paramDef.GetAccessString(), exphdlr.Parse(expression, context).GetParsedExpression()) 

    # Evaluate
    if (ParameterExpressionStatus.eSuccess != defs.EvaluateExpressions(defs)):
        return False

    return True


def CreateCircleVariableAndParameterSets(dgnModel):
    """
    Creates a circle variable and parameter sets in the given design model.
    This function creates a distance variable named "Radius" and two parameter sets named "Small" and "Large".
    It then sets the value of the "Radius" variable for each parameter set.
    :param dgnModel: The design model in which to create the variable and parameter sets.
    :type dgnModel: object
    :Example:
    >>> CreateCircleVariableAndParameterSets(dgnModel)
    The function performs the following steps:
    1. Creates a distance variable named "Radius" with an initial value of 20000.
    2. Creates a parameter set named "Small" with a description "Small circle parameter set".
    3. Creates a parameter set named "Large" with a description "Large circle parameter set".
    4. Sets the value of the "Radius" variable to 1 for the "Small" parameter set.
    5. Sets the value of the "Radius" variable to 5 for the "Large" parameter set.
    """
    variableName = "Radius"
    parameterSetNameSmall = "Small"
    parameterSetDescSmall = "Small circle parameter set"
    parameterSetNameLarge = "Large"
    parameterSetDescLarge = "Large circle parameter set"

    CreateVariable(variableName, ParameterType.eDistance, 20000, dgnModel) # Create Distance variable "Radius" 
    CreateVariation(parameterSetNameSmall, parameterSetDescSmall, dgnModel) # Create parameter set "Small"
    CreateVariation(parameterSetNameLarge, parameterSetDescLarge, dgnModel) # Create parameter set "Large"
    SetVariableValueInParameterSet(parameterSetNameSmall, variableName, 1, dgnModel) # Set "Radius" variable value for "Small" parameter set
    SetVariableValueInParameterSet(parameterSetNameLarge, variableName, 5, dgnModel) # Set "Radius" variable value for "Large" parameter set

def ExampleCreateCircleVariableAndParameterSets():
    """
    Example function to create a circle with variable and parameter sets.

    This function demonstrates how to create a circle using variable and parameter sets
    in the active DGN model. It utilizes the `CreateCircleVariableAndParameterSets` function
    and the `ISessionMgr.GetActiveDgnModel()` method to achieve this.

    Note:
        Ensure that the DGN model is active before calling this function.

    Raises:
        Exception: If there is an issue with creating the circle or accessing the active DGN model.
    """
    CreateCircleVariableAndParameterSets(ISessionMgr.GetActiveDgnModel())

def ExampleCreateVariableWithExpression():
    """
    Demonstrates how to create a variable with an expression in a DGN model.
    This function performs the following steps:
    1. Retrieves the active DGN model.
    2. Creates a distance variable named "SmallRadius" with a value of 20000.0.
    3. Creates another distance variable named "RadiusDouble" with an expression "2 * SmallRadius".
    4. Performs a simple test to verify that the variable "RadiusDouble" evaluates correctly.
    The test involves:
    - Retrieving the parameter definitions for the model.
    - Getting the model information.
    - Comparing the actual value of "RadiusDouble" with the expected value.
    
    :raises AssertionError: If the actual value of "RadiusDouble" does not match the expected value.
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()

    smallRadiusName = "SmallRadius"
    smallRadiusValue = 20000.0
    CreateVariable(smallRadiusName, ParameterType.eDistance, smallRadiusValue, dgnModel) # Create Distance variable "Radius" 

    radiusDoubleName = "RadiusDouble"
    expression = "2 * SmallRadius"
    CreateVariableWithExpression(radiusDoubleName, ParameterType.eDistance, 20000, expression, dgnModel)

    # simple test
    defs = IParameterDefinitions.GetForModel(dgnModel).GetForEdit()
    modelInfo = dgnModel.GetModelInfo()
    actual = ECValue()
    expect = ECValue()
    paramDef = ParameterDefinition()
    defs.FindByLabel(paramDef, radiusDoubleName) # get the paramDef
    defs.GetValue(actual, paramDef.GetAccessString())
    expect.SetDouble(2 * smallRadiusValue/modelInfo.GetUorPerStorage())
    assert (actual == expect)

def ExampleRemoveVariable():
    """
    Removes a specified variable from the active DGN model.

    This function retrieves the active DGN model and removes the variable
    with the name "Radius" from it.

    :raises Exception: If the variable cannot be removed or the model is not found.
    """
    variableName = "Radius"
    dgnModel = ISessionMgr.GetActiveDgnModel()
    RemoveVariable(variableName, dgnModel)

def ExampleRemoveVariation():
    """
    Removes a specified variation from the active DGN model.

    This function removes a variation named "Small" from the currently active
    DGN model using the `RemoveVariation` function.

    :raises SomeException: If the variation cannot be removed or the model is not found.
    """
    variationName = "Small"
    dgnModel = ISessionMgr.GetActiveDgnModel()
    RemoveVariation(variationName, dgnModel)

def ExampleExportVariables():
    """
    Export variables from the active DGN model to a CSV file.

    This function retrieves the active DGN model and constructs a file path
    for the export CSV file. It then calls the ExportVariables function to
    export the variables to the specified CSV file.

    :raises Exception: If there is an error during the export process.
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    path = BeFileName.GetDirectoryName(repr(ISessionMgr.GetActiveDgnFile().GetFileName()))
    path.AppendA("export.csv")
    ExportVariables(dgnModel, str(path))

def ExampleImportVariables():
    """
    Example function to import variables from a CSV file into the active DGN model.

    This function retrieves the active DGN model and constructs the path to the 
    'export.csv' file located in the same directory as the active DGN file. It then 
    calls the ImportVariables function to import the variables from the CSV file 
    into the DGN model.

    :raises Exception: If there is an error in retrieving the active DGN model or file.
    """
    dgnModel = ISessionMgr.GetActiveDgnModel()
    path = BeFileName.GetDirectoryName(repr(ISessionMgr.GetActiveDgnFile().GetFileName()))
    path.AppendA("export.csv")
    ImportVariables(dgnModel, str(path))

def RunSamples(index = 1):
    """
    Run sample functions based on the provided index.

    :param index: An integer representing the sample function to run. 
                  Defaults to 1. The valid values are:
                  1 - Run ExampleCreateCircleVariableAndParameterSets
                  2 - Run ExampleCreateVariableWithExpression
                  3 - Run ExampleExportVariables
                  4 - Run ExampleImportVariables
                  5 - Run ExampleRemoveVariable
                  6 - Run ExampleRemoveVariation
    :type index: int
    """
    if (1 == index):
        ExampleCreateCircleVariableAndParameterSets()
    elif(2 == index):
        ExampleCreateVariableWithExpression()
    elif(3 == index):
        ExampleExportVariables()
    elif(4 == index):
        ExampleImportVariables()
    elif(5 == index):
        ExampleRemoveVariable()
    elif(6 == index):
        ExampleRemoveVariation()

if __name__ == "__main__":
    RunSamples(1)
