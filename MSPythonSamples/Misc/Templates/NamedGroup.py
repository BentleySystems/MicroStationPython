from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def create_named_group_from_selection(group_name="MyNamedGroup"):
    """
    Creates a named group in the active DGN model and adds all currently selected elements to it.

    :param group_name: The name of the named group to create.
    :type group_name: str

    :returns: True if the named group is successfully created and elements are added, False otherwise.
    :rtype: bool
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    if ACTIVEMODEL is None:
        return False

    namedGroups = NamedGroupCollection(ACTIVEMODEL)
    if namedGroups is None:
        return False

    # Create named group
    flag = NamedGroupFlags()
    ret = NamedGroup.Create(group_name, "", flag, ACTIVEMODEL)
    if BentleyStatus.eSUCCESS != ret[0]:
        return False

    group = ret[1]

    # Get the selected elements
    selSetManager = SelectionSetManager.GetManager()
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)

    # Add each selected element to the named group
    memberFlag = NamedGroupMemberFlags()
    for i in range(agenda.GetCount()):
        editElementHandle = agenda.GetEntry(i)
        if BentleyStatus.eSUCCESS != group.AddMember(editElementHandle.GetElementId(), ACTIVEMODEL, memberFlag):
            return False

    if BentleyStatus.eSUCCESS != group.WriteToFile(True):
        return False

    return True

# Example usage
if create_named_group_from_selection("MyNamedGroup"):
    print("Named group created successfully.")
else:
    print("Failed to create named group.")