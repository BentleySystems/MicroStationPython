from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyMstnPlatform import *
from MSPyDgnView import *
import sys
import os

def unitConvertion():
    """
    Converts a given distance value from one unit to another using the active DGN model's unit definitions.
    The function retrieves the active DGN model and its associated DGN file. It then converts a predefined 
    distance value (100) from a source unit (specified via command-line arguments or defaulting to "METER") 
    to the master unit of the active DGN model. The result is displayed in the Message Center.
    
    :raises ValueError: If the active DGN model or unit definitions cannot be retrieved.
    Command-line Arguments:
        sys.argv[1] (str, optional): The name of the source unit for conversion. Defaults to "METER".
    Messages:
        - Displays an informational message if the DGN model is successfully selected.
        - Displays an error message if no DGN model is selected or if unit definitions cannot be retrieved.
        - Displays the converted value in the Message Center upon successful conversion.
    Dependencies:
        - ISessionMgr.ActiveDgnModelRef: Used to retrieve the active DGN model reference.
        - MessageCenter: Used to display informational and error messages.
        - UnitDefinition.GetStandardUnitByName: Used to retrieve the unit definition by name.
        - dgnModel.ModelInfo.GetMasterUnit: Used to retrieve the master unit of the active DGN model.
    Note:
        Ensure that the active DGN model is properly loaded before calling this function.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    if dgnModel != None:
        MessageCenter.ShowInfoMessage("DGN Model selected successfully.", "", False)
    else:
        MessageCenter.ShowErrorMessage("No DGN Model selected.", "", False)
        return
    dgnFile = dgnModel.GetDgnFile()

    value = 100
    unitNames = ["Meter", "Kilometer", "Centimeter", "Millimeter", "Inch", "Foot", "Yard", "Mile"]

    unitFromValue = " ".join(sys.argv) if len(sys.argv) > 0 else "Meter"
    if unitFromValue not in unitNames:
        MessageCenter.ShowErrorMessage(f"Invalid unit name: {unitFromValue}.", "", False)
        return
    
    unitTo = dgnModel.ModelInfo.GetMasterUnit()
    unitFrom = UnitDefinition.GetStandardUnitByName(unitFromValue)

    if (unitTo is None) or (unitTo.Base == UnitBase.eNone) or (unitFrom is None) or (unitFrom.Base == UnitBase.eNone):
        MessageCenter.ShowErrorMessage("Failed to retrieve unit definitions.", "", False)
        return

    convertedValue = unitTo.ConvertDistanceFrom(value, unitFrom)
    print(f"Converted value: {convertedValue[1]}")

if __name__ == "__main__":
    keyinXml = os.path.dirname(__file__) + '/UnitConversionsSample.commands.xml'
    PythonKeyinManager.GetManager().LoadCommandTableFromXml(WString(__file__), WString(keyinXml))