from MSPyBentley import *
from MSPyECObjects import *
from MSPyBentleyGeom import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

def selectElementsbyType(inputElementType):
    """
    Select elements of a specific type from the active model.

    This function retrieves all graphical elements from the active model and adds 
    elements of the specified type to the selection set.

    :param inputElementType: The type of elements to select.
    :type inputElementType: int
    """
    # Get active model
    ACTIVEMODEL = ISessionMgr.ActiveDgnModelRef
    dgnModel = ACTIVEMODEL.GetDgnModel()
    # Get all graphical elements from the model
    graphicalElements = dgnModel.GetGraphicElements()
    selSetManager = SelectionSetManager.GetManager()

    for perElementRef in graphicalElements:
        elementId = perElementRef.GetElementId()
        eeh = EditElementHandle(perElementRef, dgnModel)
        eh = ElementHandle(perElementRef)

        msElement = MSElement()
        msElement = eeh.GetElement()

        isGraphics = msElement.ehdr.isGraphics
        isInvisible = msElement.hdr.dhdr.props.b.invisible

        if isGraphics and not isInvisible:
            eleType = eh.GetElementType()
            if eleType == inputElementType:
                # It will select and highlight all elements added in the selection set
                selSetManager.AddElement(perElementRef, dgnModel)

    # Get the selected elements from the selection set manager
    agenda = ElementAgenda()
    selSetManager.BuildAgenda(agenda)
    # Print the number of selected elements
    print(f"Selected {agenda.GetCount()} elements")
    # Iterate over the selection set printing the element ids of elements in the selection set
    for i in range(agenda.GetCount()):
        editElementHandle = agenda.GetEntry(i)
        print(f"  Element ID: {editElementHandle.GetElementId()}")

# Example usage: Select all Text Elements (type 17)
selectElementsbyType(MSElementTypes.eTEXT_ELM)