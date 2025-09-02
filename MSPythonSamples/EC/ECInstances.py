# -----------------------------------------------------------------------------
# Script Description:
#
# This script reads and displays the EC (Engineering Content) property values
# attached to the first element in the current MicroStation selection set.
# It queries all EC instances on the selected element, serializes their
# property names and values into a dictionary, and prints them to the console.
# The script uses the MicroStation Python API to access selection sets,
# EC queries, and EC instance serialization.
#
# Usage:
#   - Select an element in the active MicroStation model.
#   - Run this script to print all EC property values attached to that element.
# -----------------------------------------------------------------------------

from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def serialize_ec_instance(instance):
    """
    Serialize an EC instance into a dictionary of property names and values.

    :param instance: The EC instance to serialize.
    :type instance: ECInstance
    :returns: Dictionary of property names and values.
    :rtype: dict
    """
    ecPropNamValDict = {}
    # Create a collection of all property values in the EC instance
    collection = ECValuesCollection.Create(instance)

    # Iterate through each property value in the collection
    for propertyValue in collection:
        accessor = propertyValue.GetValueAccessor()
        accessString = accessor.GetManagedAccessString()
        value = propertyValue.GetValue()
        typeAdaptedValue = WString()

        # Only serialize primitive (non-struct, non-array) properties
        if not value.IsStruct() and not value.IsArray():
            # Try to get the property value as a string
            if BentleyStatus.eSUCCESS == instance.GetValueAsString(typeAdaptedValue, str(accessString), False, 0):
                ecPropNamValDict[str(accessString)] = str(typeAdaptedValue)
            else:
                # Fallback: get the value directly and convert to string
                instance.GetValue(value, str(accessString))
                ecPropNamValDict[str(accessString)] = str(value.ToString())

    return ecPropNamValDict

def read_ec_instances_from_selected_element():
    # Get the selection set manager
    selSetManager = SelectionSetManager.GetManager()
    # Get the number of selected elements in the active model
    numSelected = selSetManager.NumSelected()

    if numSelected == 0:
        print("No element selected.")
        return

    # Prepare an ElementHandle to receive the first selected element
    elementHandle = ElementHandle()
    selSetManager.GetElement(0, elementHandle)

    if not elementHandle.IsValid():
        print("Invalid element handle.")
        return

    # Get the DgnECManager, which manages EC data in the DGN file
    mgr = DgnECManager.GetManager()

    # Create an ECQuery to search all EC classes attached to the element
    query = ECQuery.CreateQuery(eECQUERY_PROCESS_SearchAllClasses)

    # Define the scope for the query: the selected element as an EC host
    elementScope = FindInstancesScope.CreateScope(elementHandle, FindInstancesScopeOption(DgnECHostType.eElement))

    # Execute the query to find all EC instances attached to the element
    instanceCollection = mgr.FindInstances(elementScope, query)

    # Iterate through each EC instance found on the element
    for instance in instanceCollection[0]:
        # Get the EC class of the instance
        ecClass = instance.GetClass()
        className = ecClass.GetName()
        print(f"Class Name: {className}")

        # Serialize the EC instance's properties into a dictionary
        ecPropNamValDict = serialize_ec_instance(instance)

        # Print each property name and value
        for propName, propValue in ecPropNamValDict.items():
            print(f"  {propName}: {propValue}")

# Run the function to display EC properties of the first selected element
read_ec_instances_from_selected_element()