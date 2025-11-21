from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

import tkinter as tk
from tkinter import simpledialog, messagebox

def get_volume_range():
    """Prompt user for min and max volume (in cubic meters) using tkinter."""
    root = tk.Tk()
    root.withdraw()
    min_vol = simpledialog.askfloat("Volume Range", "Enter minimum volume (m³):", minvalue=0.0)
    if min_vol is None:
        return None, None
    max_vol = simpledialog.askfloat("Volume Range", "Enter maximum volume (m³):", minvalue=min_vol)
    if max_vol is None:
        return None, None
    return min_vol, max_vol

def select_elements_by_volume_range(min_volume, max_volume):
    """
    Selects all 3D solid or surface elements in the active model whose volume is within the specified range.
    Volumes are in cubic meters.
    """
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    modelInfo = dgnModel.GetModelInfo()
    uorPerMeter = modelInfo.UorPerMeter

    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()
    selSetManager.EmptyAll()  # Clear previous selection

    count = 0
    for perElementRef in graphicalElements:
        eeh = EditElementHandle(perElementRef, dgnModel)
        msElement = eeh.GetElement()
        # Only process visible, graphical elements
        if not msElement.ehdr.isGraphics or msElement.hdr.dhdr.props.b.invisible:
            continue

        # Query for EC property 'Volume'
        dgnECManager = DgnECManager.GetManager()
        scopeOption = FindInstancesScopeOption()
        scope = FindInstancesScope.CreateScope(eeh, scopeOption)
        allQuery = ECQuery.CreateQuery(ECQueryProcessFlags.eECQUERY_PROCESS_SearchAllIntrinsic)
        instanceItr = dgnECManager.FindInstances(scope, allQuery)
        found = False
        for instance in instanceItr[0]:
            propValue = ECValue()
            instance.GetValue(propValue, 'Volume', 0)
            if not propValue.IsNull():
                # Convert UOR³ to m³
                volume = propValue.GetDouble() / (uorPerMeter ** 3)
                if min_volume <= volume <= max_volume:
                    selSetManager.AddElement(perElementRef, dgnModel)
                    count += 1
                found = True
                break
        if not found:
            continue

    # Report results
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    messagebox.showinfo("Selection Complete", f"Selected {count} elements with volume in range [{min_volume}, {max_volume}] m³.")

if __name__ == "__main__":
    min_vol, max_vol = get_volume_range()
    if min_vol is not None and max_vol is not None:
        select_elements_by_volume_range(min_vol, max_vol)