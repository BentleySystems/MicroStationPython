from os import path
from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *

# import debugpy
# debugpy.listen(('0.0.0.0',5678), in_process_debug_adapter=True)
# print("Waiting for debugger attach")
# debugpy.wait_for_client()
# debugpy.breakpoint()
# print('break on this line')

'''
Test attaching a URL link to elements in the active model.
This test bases on  AddURLLink_Test.dgn
'''

def CreateLinksOnElements(modelRef):
    dgnModel = modelRef.GetDgnModel()
    if dgnModel is None:
        print("Failed to get DgnModel from DgnModelRef.")
        return 0

    # Get the graphic elements in the model
    elementRefList = dgnModel.GetGraphicElements()
    if elementRefList is None:
        print("Failed to get graphic elements.")
        return 0
    if elementRefList.IsEmpty():
        print("No graphic elements.")
        return 0

    linkLeaf, status = DgnLinkManager.CreateLink (DGNLINK_TYPEKEY_URLLink)
    if linkLeaf is None:
        print(f"Failed to create new leaf")
        return 0
    
    link = linkLeaf.GetLink()
    link.SetAddress("https://www.blyncsy.com/wp-content/uploads/2024/04/f7677f30-c67d-4d1c-aab7-d65e94f2e9a5_243728751-53.png")

    # Iterate through the elements and add the links
    nLinked = 0
    for elementRef in elementRefList:
        element = EditElementHandle (elementRef, modelRef)
        if element is None:
            continue

    
        # Add link to element -- TODO
        nLinked += 1

    return nLinked

#main
if __name__ == "__main__":
    print("Script start...")

    # Get the active model reference
    modelRef = ISessionMgr.ActiveDgnModelRef

    nLinked = CreateLinksOnElements(modelRef)
    print (f"Linked {nLinked} imported features.")

    print("Script end...")
        