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
Function to create variable with given name, value and type in given dgn model
'''
def CreateVariable(name, type, value, dgnModel):
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

'''
Function to remove variable with given name in given dgn model
'''
def RemoveVariable(name, dgnModel):
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

'''
Function to create parameter set with given name and description in given dgn model
'''
def CreateVariation(name, desc, dgnModel):
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

'''
Function to remove variation with given name in given dgn model
'''
def RemoveVariation(name, dgnModel):
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

'''
Function to export variables and variations in dgn model to csv file
'''
def ExportVariables(dgnModel, csvPath):
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

'''
Function to import variables and variations in csv file to dgn model
'''
def ImportVariables(dgnModel, csvPath):
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

'''
Function to set variaible value with given name and value in the given parameter set and given dgn model
'''
def SetVariableValueInParameterSet(setName, varName, varValue, dgnModel):
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

'''
Function to create variable with expression
'''
def CreateVariableWithExpression(name, type, value, expression, dgnModel):
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


'''
Function to create Distance variable "Radius", and create 2 parameter sets "Small" and "Large"
'''
def CreateCircleVariableAndParameterSets(dgnModel):
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

'''
Example to show how to create variable and parameter sets to active model
'''
def ExampleCreateCircleVariableAndParameterSets():
    CreateCircleVariableAndParameterSets(ISessionMgr.GetActiveDgnModel())

'''
Example to show how to create variable with expression to active model
'''
def ExampleCreateVariableWithExpression():
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

'''
Example to show how to remove variable from dgn model
'''
def ExampleRemoveVariable():
    variableName = "Radius"
    dgnModel = ISessionMgr.GetActiveDgnModel()
    RemoveVariable(variableName, dgnModel)

'''
Example to show how to remove variation from dgn model
'''
def ExampleRemoveVariation():
    variationName = "Small"
    dgnModel = ISessionMgr.GetActiveDgnModel()
    RemoveVariation(variationName, dgnModel)

'''
Example to show how to export variables and variations from dgn model into csv file
'''
def ExampleExportVariables():
    dgnModel = ISessionMgr.GetActiveDgnModel()
    path = BeFileName.GetDirectoryName(repr(ISessionMgr.GetActiveDgnFile().GetFileName()))
    path.AppendA("export.csv")
    ExportVariables(dgnModel, str(path))

'''
Example to show how to import variables and variations from csv file into dgn model
'''
def ExampleImportVariables():
    dgnModel = ISessionMgr.GetActiveDgnModel()
    path = BeFileName.GetDirectoryName(repr(ISessionMgr.GetActiveDgnFile().GetFileName()))
    path.AppendA("export.csv")
    ImportVariables(dgnModel, str(path))

def RunSamples(index = 1):
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
